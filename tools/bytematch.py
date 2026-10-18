#!/usr/bin/env python3
"""Byte-match recompiled functions against the original KMS2_DEV x64 MapleStory2.exe.

    .venv/bin/python tools/bytematch.py OBJ_OR_COD  SYMBOL VA  [SYMBOL VA ...]  [-v] [--no-unwind]
    .venv/bin/python tools/bytematch.py a.obj  Encrypt@CXORCrypter 0x1401cd490  Decrypt@CXORCrypter 0x1401cd530
    .venv/bin/python tools/bytematch.py a.obj  --list            # function symbols in the obj

SYMBOL: an exact (mangled) symbol name, or a substring of exactly one function symbol's mangled name
("Encrypt@CXORCrypter" matches "?Encrypt@CXORCrypter@@UEAAXPEAEIPEAX@Z").

.obj (COFF, also /bigobj), the reliable mode:
  * function bytes = the symbol's bytes, length from the obj's .pdata entry (else up to the next symbol/section end);
  * every relocated field (REL32[_1.._5], ADDR64, ADDR32NB, SECREL, SECTION) is masked on both sides. REL32 fields
    are *resolved* on the exe side and must be consistent: one obj symbol -> one exe address (a second, different
    target is a mismatch). The resolved targets are printed with -v (handy for naming callees/globals).
    ADDR32NB fields that point into the function itself (switch jump tables, which /Od places after the code inside
    the function's .pdata range) are checked exactly: the exe entry must be the function RVA + the same offset;
  * unwind data is compared too: UNWIND_INFO header + unwind codes exactly, the exception handler by role
    (handler symbol name in the obj, e.g. __CxxFrameHandler3 / __GSHandlerCheck / __GSHandlerCheck_EH), GS data
    exactly, and for C++ EH the FuncInfo (magic, maxState, try blocks, EH flags incl. FI_EHS_FLAG = /EHs, unwind
    help offset), the unwind-map states, the try-block map and the IP-to-state map (as offsets inside the function;
    funclet entries compared by count only). Funclets themselves (?dtor$N@... / ?catch$N@...) are separate symbols:
    match them with their own SYMBOL VA pair (their VAs are in the exe's unwind map / IP map, printed with -v).
.cod (/FAsc listing): bytes from the listing; masking is heuristic (call/jmp rel32 leaving the function,
  RIP-relative displacements, and zero imm64/imm32 fields that a listing shows for unresolved fixups); no unwind check.

Exit status: 0 if every pair matches, 1 otherwise.  On mismatch a side-by-side disassembly (obj | exe) is printed,
aligned with difflib, with '!' on differing lines; masked bytes show as '..'.
"""
import argparse
import bisect
import difflib
import os
import re
import struct
import subprocess
import sys

import capstone
import pefile
from capstone import x86

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402
EXE = ms2paths.EXE
FUNCS = ms2paths.FUNCTIONS_TSV
# import libraries that resolve the exe's by-ordinal imports (mfc140.dll exports everything by ordinal)
ORDINAL_LIBS = [os.path.join(ms2paths.msvc_tools_dir(), "atlmfc", "lib", "x64", "mfc140.lib")]


def import_lib_ordinals(path):
    """{(dll lower, ordinal): symbol} from the short import members of an import library (by-ordinal entries)."""
    out = {}
    data = open(path, "rb").read()
    o = 8
    while o + 60 <= len(data):
        size = int(data[o + 48:o + 58].decode().strip())
        m = data[o + 60:o + 60 + size]
        if len(m) >= 20 and m[:4] == b"\0\0\xff\xff":
            hint, flags = struct.unpack_from("<HH", m, 16)
            sym, dll = m[20:].split(b"\0")[:2]
            if (flags >> 2) & 7 == 0:                      # IMPORT_OBJECT_ORDINAL
                out[(dll.decode().lower(), hint)] = sym.decode("latin1")
        o += 60 + size + (size & 1)
    return out

# IMAGE_REL_AMD64_*
REL_ADDR64, REL_ADDR32, REL_ADDR32NB, REL_REL32 = 1, 2, 3, 4
REL_SECTION, REL_SECREL = 10, 11
RELOC_LEN = {1: 8, 2: 4, 3: 4, 4: 4, 5: 4, 6: 4, 7: 4, 8: 4, 9: 4, 10: 2, 11: 4, 12: 1, 13: 4, 14: 8, 15: 4, 16: 4}
FUNCLET_PREFIXES = ("?dtor$", "?catch$", "?filt$", "?fin$")
UNW_FLAG_EHANDLER, UNW_FLAG_UHANDLER, UNW_FLAG_CHAININFO = 1, 2, 4

MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
MD.detail = True


# ----------------------------------------------------------------------------------------------------------------
# COFF object reader

class Obj:
    def __init__(self, path):
        self.path = path
        d = self.d = open(path, "rb").read()
        sig1, sig2 = struct.unpack_from("<HH", d, 0)
        if sig1 == 0 and sig2 == 0xFFFF:                       # ANON_OBJECT_HEADER_BIGOBJ
            nsec, = struct.unpack_from("<I", d, 44)
            symoff, nsym = struct.unpack_from("<II", d, 48)
            sechdr, symsz, secnum_fmt = 56, 20, "<i"
        else:
            nsec, = struct.unpack_from("<H", d, 2)
            symoff, nsym = struct.unpack_from("<II", d, 8)
            opt, = struct.unpack_from("<H", d, 16)
            sechdr, symsz, secnum_fmt = 20 + opt, 18, "<h"
        strtab = symoff + nsym * symsz
        self.sections = []
        for i in range(nsec):
            o = sechdr + 40 * i
            name = d[o:o + 8].rstrip(b"\0").decode("latin1")
            if name.startswith("/"):
                name = self._str(strtab, int(name[1:]))
            size, ptr, prel, _, nrel = struct.unpack_from("<IIIIH", d, o + 16)
            chars, = struct.unpack_from("<I", d, o + 36)
            relocs = []
            if chars & 0x01000000 and nrel == 0xFFFF:          # IMAGE_SCN_LNK_NRELOC_OVFL
                nrel, = struct.unpack_from("<I", d, prel)
                prel += 10
                nrel -= 1
            for r in range(nrel):
                relocs.append(struct.unpack_from("<IIH", d, prel + 10 * r))
            data = d[ptr:ptr + size] if ptr else bytes(size)
            self.sections.append(dict(name=name, data=data, relocs=sorted(relocs), chars=chars, size=size))
        self.syms = {}                                         # index -> (name, value, secnum(1-based), type, sclass)
        i = 0
        while i < nsym:
            o = symoff + i * symsz
            raw = d[o:o + 8]
            if raw[:4] == b"\0\0\0\0":
                name = self._str(strtab, struct.unpack_from("<I", raw, 4)[0])
            else:
                name = raw.rstrip(b"\0").decode("latin1")
            value, = struct.unpack_from("<I", d, o + 8)
            secnum, = struct.unpack_from(secnum_fmt, d, o + 12)
            typ, sclass, naux = struct.unpack_from("<HBB", d, o + symsz - 4)
            self.syms[i] = (name, value, secnum, typ, sclass)
            if sclass == 3 and naux and value == 0 and 0 < secnum <= nsec and name == self.sections[secnum - 1]["name"]:
                ao = o + symsz                                 # section definition aux: COMDAT selection
                num, sel = struct.unpack_from("<HB", d, ao + 12)
                if secnum_fmt == "<i":
                    num |= struct.unpack_from("<H", d, ao + 16)[0] << 16
                self.sections[secnum - 1]["comdat"] = (sel, num)
            i += 1 + naux
        self.by_name = {}
        for idx, s in self.syms.items():
            self.by_name.setdefault(s[0], idx)
        self._pdata = None

    def _str(self, strtab, off):
        e = self.d.index(b"\0", strtab + off)
        return self.d[strtab + off:e].decode("latin1")

    def sec(self, secnum):
        return self.sections[secnum - 1]

    def reloc_at(self, secnum, off):
        """(type, symidx) of the reloc at section offset off, or None."""
        for va, si, ty in self.sec(secnum)["relocs"]:
            if va == off:
                return ty, si
        return None

    def pdata(self):
        """[(func_secnum, func_off, end_off, unwind_secnum, unwind_off)] from every .pdata section."""
        if self._pdata is None:
            out = []
            for sn, s in enumerate(self.sections, 1):
                if s["name"] != ".pdata":
                    continue
                rel = {va: si for va, si, ty in s["relocs"]}
                for o in range(0, s["size"] - 11, 12):
                    b, e, u = struct.unpack_from("<III", s["data"], o)
                    if o not in rel or o + 8 not in rel:
                        continue
                    fs = self.syms[rel[o]]
                    us = self.syms[rel[o + 8]]
                    out.append((fs[2], fs[1] + b, fs[1] + e, us[2], us[1] + u))
            self._pdata = out
        return self._pdata

    def func_symbols(self):
        out = []
        for idx, (name, value, secnum, typ, sclass) in self.syms.items():
            if secnum <= 0 or sclass not in (2, 3, 6):
                continue
            s = self.sec(secnum)
            if not s["chars"] & 0x20:                          # IMAGE_SCN_CNT_CODE
                continue
            if name.startswith("$") or name.startswith(".") or (sclass == 3 and value == 0 and name == s["name"]):
                continue
            if typ != 0x20 and sclass != 6 and not name.startswith("?"):
                continue
            out.append(idx)
        return out

    def find(self, pat):
        if pat in self.by_name and self.syms[self.by_name[pat]][2] > 0:
            return self.by_name[pat]
        hits = [i for i in self.func_symbols() if pat in self.syms[i][0]]
        if len(hits) > 1 and not pat.startswith(FUNCLET_PREFIXES):
            hits = [i for i in hits if not self.syms[i][0].startswith(FUNCLET_PREFIXES)] or hits
        if len(hits) == 1:
            return hits[0]
        if not hits:
            sys.exit(f"{pat}: no function symbol in {self.path} (try --list)")
        exact = [i for i in hits if self.syms[i][0] == pat]
        if len(exact) == 1:
            return exact[0]
        sys.exit(f"{pat}: ambiguous in {self.path}: " + ", ".join(self.syms[i][0] for i in hits[:10]))

    def find_any(self, pat):
        if pat in self.by_name and self.syms[self.by_name[pat]][2] > 0:
            return self.by_name[pat]
        return self.find(pat)

    def function(self, symidx):
        """(bytes, [(off, len, symname, rtype, target)], unwind_loc or None).

        target = in-function offset for ADDR32NB fields that point into the function itself (jump tables:
        the exe must hold function RVA + that offset), else None."""
        try:
            cache = self._fcache
        except AttributeError:
            cache = self._fcache = {}
        hit = cache.get(symidx)
        if hit is not None:
            return hit
        name, value, secnum, _, _ = self.syms[symidx]
        sec = self.sec(secnum)
        end = None
        unwind = None
        pidx = self.__dict__.get("_pidx")
        if pidx is None:
            pidx = self._pidx = {}
            for fs, fo, fe, us, uo in self.pdata():
                pidx.setdefault((fs, fo), (fe, (us, uo)))
        if (secnum, value) in pidx:
            end, unwind = pidx[(secnum, value)]
        if end is None:                                        # leaf without pdata: up to the next symbol
            nxt = [v for (n, v, s, t, c) in self.syms.values() if s == secnum and v > value and not n.startswith("$")]
            end = min(nxt) if nxt else sec["size"]
        data = sec["data"][value:end]
        fields = []
        for va, si, ty in sec["relocs"]:
            if value <= va < end:
                ln = RELOC_LEN.get(ty, 4)
                tname, tval, tsec = self.syms[si][0], self.syms[si][1], self.syms[si][2]
                inner = None
                if ty == REL_ADDR32NB and tsec == secnum:
                    add = struct.unpack_from("<I", sec["data"], va)[0]
                    if value <= tval + add < end:
                        inner = tval + add - value
                fields.append((va - value, ln, tname, ty, inner, si))
        cache[symidx] = (data, fields, unwind)
        return cache[symidx]

    def is_code(self, symidx):
        sn = self.syms[symidx][2]
        return sn > 0 and bool(self.sec(sn)["chars"] & 0x20)

    def own(self, symidx):
        """Not a discardable duplicate: plain section or COMDAT NODUPLICATES (the unit's own functions), as opposed
        to selectany/largest COMDATs (inline/template functions, kept once exe-wide in whichever unit came first)."""
        try:
            oc = self._owncache
        except AttributeError:
            oc = self._owncache = {}
        r = oc.get(symidx)
        if r is None:
            r = oc[symidx] = self._own(symidx)
        return r

    def _own(self, symidx):
        sec = self.sec(self.syms[symidx][2])
        if not sec["chars"] & 0x1000:                          # IMAGE_SCN_LNK_COMDAT
            return True
        sel, num = sec.get("comdat", (0, 0))
        for _ in range(8):
            if sel != 5 or not num:                            # ASSOCIATIVE: selection of the parent section
                break
            sel, num = self.sections[num - 1].get("comdat", (0, 0))
        return sel == 1

    def is_external(self, symidx):
        return self.syms[symidx][4] == 2

    def defined(self, symidx):
        return self.syms[symidx][2] > 0


# ----------------------------------------------------------------------------------------------------------------
# .cod listing reader (heuristic)

def cod_function(path, pat):
    text = open(path, encoding="latin1").read()
    procs = re.findall(r"^(\S+)\s+PROC\b.*?$(.*?)^\1\s+ENDP", text, re.M | re.S)
    hits = [(n, body) for n, body in procs if n == pat] or [(n, body) for n, body in procs if pat in n]
    if len(hits) != 1:
        sys.exit(f"{pat}: {len(hits)} matching PROCs in {path}: " + ", ".join(n for n, _ in hits[:10]))
    name, body = hits[0]
    out = bytearray()
    for line in body.splitlines():
        m = re.match(r"^\s+([0-9a-f]{5,8})\t((?:[0-9a-f]{2} ?)+)", line)
        if m:
            off = int(m.group(1), 16)
            bs = bytes.fromhex(m.group(2).replace(" ", ""))
            if off != len(out):
                if off > len(out):
                    out += b"\0" * (off - len(out))
                else:
                    continue
            out += bs
        else:
            m = re.match(r"^\s+((?:[0-9a-f]{2} ){1,8})\s*$", line)   # continuation line of a long instruction
            if m and out:
                out += bytes.fromhex(m.group(1).replace(" ", ""))
    return name, bytes(out)


def heuristic_fields(data):
    fields = []
    for i in MD.disasm(data, 0):
        rel_base = i.size
        for op in i.operands:
            if op.type == x86.X86_OP_MEM and op.mem.base == x86.X86_REG_RIP:
                doff = i.disp_offset
                fields.append((i.address + doff, 4, "<rip>", REL_REL32, None, None))
            elif op.type == x86.X86_OP_IMM and i.mnemonic in ("call", "jmp") and i.imm_size == 4:
                if not (0 <= op.imm < len(data)):
                    fields.append((i.address + i.imm_offset, 4, "<rel32>", REL_REL32, None, None))
    return fields


# ----------------------------------------------------------------------------------------------------------------
# Exe

class Exe:
    def __init__(self, path):
        self.pe = pefile.PE(path, fast_load=True)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.img = self.pe.get_memory_mapped_image()
        d = self.pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        self.rf = {}
        raw = self.img[d.VirtualAddress:d.VirtualAddress + d.Size]
        for o in range(0, len(raw) - 11, 12):
            b, e, u = struct.unpack_from("<III", raw, o)
            self.rf[b] = (e, u)
        self.names = {}
        self.starts = []
        if os.path.exists(FUNCS):
            for line in open(FUNCS):
                p = line.rstrip("\n").split("\t")
                va = int(p[0], 16)
                self.names[va] = p[3] if len(p) > 3 else ""
                self.starts.append(va)
            self.starts.sort()
        self.iat = {}
        self.pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
        ords = {}
        for lib in ORDINAL_LIBS:
            if os.path.exists(lib):
                ords.update(import_lib_ordinals(lib))
        self.imp = {}                                       # IAT slot va -> imported symbol name
        for e in getattr(self.pe, "DIRECTORY_ENTRY_IMPORT", []):
            for imp in e.imports:
                if imp.name:
                    sym = imp.name.decode()
                else:
                    sym = ords.get((e.dll.decode().lower(), imp.ordinal))
                if sym:
                    self.imp[imp.address] = sym
                    self.iat[imp.address] = e.dll.decode() + "!" + sym
                else:
                    self.iat[imp.address] = f"{e.dll.decode()}!#{imp.ordinal}"

    def read(self, va, n):
        o = va - self.base
        return bytes(self.img[o:o + n])

    def name(self, va):
        if va in self.iat:
            return "[" + self.iat[va] + "]"
        n = self.names.get(va)
        if n:
            return n
        i = bisect.bisect_right(self.starts, va) - 1
        if i >= 0 and self.starts[i] != va:
            return f"{self.names.get(self.starts[i], '?')}+0x{va - self.starts[i]:x}"
        return ""


# ----------------------------------------------------------------------------------------------------------------
# Unwind / EH

def parse_unwind(buf, off):
    b0, prolog, ncodes, fr = struct.unpack_from("<BBBB", buf, off)
    codes = buf[off + 4:off + 4 + 2 * ncodes]
    after = off + 4 + 2 * ((ncodes + 1) & ~1)
    return dict(ver=b0 & 7, flags=b0 >> 3, prolog=prolog, ncodes=ncodes, frame=fr, codes=codes, after=after)


def demangle(n):
    try:
        return subprocess.run(["llvm-undname", n], capture_output=True, text=True).stdout.strip().splitlines()[-1].strip()
    except Exception:
        return n


class Report:
    def __init__(self):
        self.lines, self.ok = [], True

    def bad(self, msg):
        self.ok = False
        self.lines.append("  MISMATCH " + msg)

    def info(self, msg):
        self.lines.append("  " + msg)


def compare_unwind(obj, unw, exe, va, fstart_obj, fsec_obj, rep, verbose):
    rva = va - exe.base
    if rva not in exe.rf:
        if unw is None:
            return
        rep.bad("obj has .pdata/unwind, exe has no RUNTIME_FUNCTION at this VA")
        return
    if unw is None:
        rep.bad("exe has a RUNTIME_FUNCTION, obj function has no .pdata")
        return
    eend, eu = exe.rf[rva]
    us, uo = unw
    osec = obj.sec(us)
    ou = parse_unwind(osec["data"], uo)
    xu = parse_unwind(exe.img, eu)
    for k in ("ver", "flags", "prolog", "ncodes", "frame", "codes"):
        if ou[k] != xu[k]:
            rep.bad(f"UNWIND_INFO.{k}: obj {ou[k]!r} exe {xu[k]!r}")
    if ou["flags"] & UNW_FLAG_CHAININFO:
        rep.info("chained unwind info (not compared further)")
        return
    if not ou["flags"] & (UNW_FLAG_EHANDLER | UNW_FLAG_UHANDLER):
        if verbose:
            rep.info(f"unwind ok: prolog {ou['prolog']}, {ou['ncodes']} codes, no handler")
        return
    r = obj.reloc_at(us, ou["after"])
    hname = obj.syms[r[1]][0] if r else "?"
    xh = struct.unpack_from("<I", exe.img, xu["after"])[0] + exe.base
    xhn = exe.name(xh)
    if verbose:
        rep.info(f"handler: obj {hname}  exe 0x{xh:x} {xhn}")
    hshort = hname.lstrip("_")
    if hshort not in xhn.replace("::", "_") and hshort.split("_")[0] not in xhn:
        rep.info(f"note: handler names differ (obj {hname}, exe {xhn}); check manually")
    lo, lx = ou["after"] + 4, xu["after"] + 4
    if "GSHandlerCheck" in hname and "_EH" not in hname:
        go, gx = struct.unpack_from("<I", osec["data"], lo)[0], struct.unpack_from("<I", exe.img, lx)[0]
        if go != gx:
            rep.bad(f"GS handler data: obj 0x{go:x} exe 0x{gx:x}")
        return
    if "FrameHandler3" in hname or "GSHandlerCheck_EH" in hname:
        r = obj.reloc_at(us, lo)
        fi_sym = obj.syms[r[1]]
        fi_sec, fi_off = fi_sym[2], fi_sym[1] + struct.unpack_from("<I", osec["data"], lo)[0]
        xfi = struct.unpack_from("<I", exe.img, lx)[0]
        try:
            compare_funcinfo(obj, fi_sec, fi_off, exe, xfi, fstart_obj, fsec_obj, va, eend, rep, verbose)
        except struct.error:
            rep.bad("obj function has EH FuncInfo, exe function has none")
            return
        if "GSHandlerCheck_EH" in hname:
            go, gx = struct.unpack_from("<I", osec["data"], lo + 4)[0], struct.unpack_from("<I", exe.img, lx + 4)[0]
            if go != gx:
                rep.bad(f"GS handler data: obj 0x{go:x} exe 0x{gx:x}")
        return
    rep.info(f"handler {hname}: language-specific data not compared")


def obj_rva_target(obj, secnum, off):
    """(symname, symsec, symvalue+addend) for an ADDR32NB field."""
    r = obj.reloc_at(secnum, off)
    if not r:
        return None
    s = obj.syms[r[1]]
    add = struct.unpack_from("<I", obj.sec(secnum)["data"], off)[0]
    return s[0], s[2], s[1] + add


def compare_funcinfo(obj, fs, fo, exe, xfi, fstart, fsec, va, eend, rep, verbose):
    od = obj.sec(fs)["data"]
    o = struct.unpack_from("<IiIIIIIiII", od, fo)
    x = struct.unpack_from("<IiIIIIIiII", exe.img, xfi)
    names = ("magic", "maxState", "dispUnwindMap", "nTryBlocks", "dispTryBlockMap", "nIPMapEntries",
             "dispIPToStateMap", "dispUnwindHelp", "dispESTypeList", "EHFlags")
    for i in (0, 1, 3, 5, 7, 9):
        if o[i] != x[i]:
            rep.bad(f"FuncInfo.{names[i]}: obj {o[i]:#x} exe {x[i]:#x}")
    if verbose:
        rep.info(f"FuncInfo: magic {x[0]:#x} maxState {x[1]} tries {x[3]} ip2state {x[5]} unwindHelp {x[7]:#x} "
                 f"EHFlags {x[9]:#x}{' (/EHs: FI_EHS_FLAG)' if x[9] & 1 else ''}")
    # unwind map: (toState, action)
    if o[1] == x[1] and o[1] > 0:
        t = obj_rva_target(obj, fs, fo + 8)
        if t:
            us, uo = t[1], t[2]
            for k in range(o[1]):
                ot = struct.unpack_from("<i", obj.sec(us)["data"], uo + 8 * k)[0]
                xt, xa = struct.unpack_from("<iI", exe.img, x[2] + 8 * k)
                if ot != xt:
                    rep.bad(f"unwind map[{k}].toState: obj {ot} exe {xt}")
                act = obj_rva_target(obj, us, uo + 8 * k + 4)
                if act and xa:
                    FUNCLET_PAIRS[act[0]] = xa + exe.base
                if verbose:
                    rep.info(f"  unwind[{k}] toState {xt} action exe 0x{xa + exe.base:x}  obj {act[0] if act else '-'}")
    # try blocks: tryLow, tryHigh, catchHigh, nCatches, (handlerArray)
    if o[3] == x[3] and o[3] > 0:
        t = obj_rva_target(obj, fs, fo + 16)
        if t:
            for k in range(o[3]):
                ob = struct.unpack_from("<iiii", obj.sec(t[1])["data"], t[2] + 20 * k)
                xb = struct.unpack_from("<iiii", exe.img, x[4] + 20 * k)
                if ob != xb:
                    rep.bad(f"try block[{k}] (low,high,catchHigh,nCatches): obj {ob} exe {xb}")
    # ip2state: (ip RVA, state)
    if o[5] == x[5] and o[5] > 0:
        t = obj_rva_target(obj, fs, fo + 24)
        if t:
            for k in range(o[5]):
                ent = obj_rva_target(obj, t[1], t[2] + 8 * k)
                ost = struct.unpack_from("<i", obj.sec(t[1])["data"], t[2] + 8 * k + 4)[0]
                xip, xst = struct.unpack_from("<Ii", exe.img, x[6] + 8 * k)
                xin = va - exe.base <= xip < eend
                oin = ent is not None and ent[1] == fsec and fstart <= ent[2]
                if ost != xst:
                    rep.bad(f"ip2state[{k}].state: obj {ost} exe {xst}")
                if xin and oin and ent[2] - fstart != xip - (va - exe.base):
                    rep.bad(f"ip2state[{k}].ip: obj +0x{ent[2] - fstart:x} exe +0x{xip - (va - exe.base):x}")
                elif xin != oin:
                    rep.bad(f"ip2state[{k}]: in-function mismatch (obj {oin}, exe {xin})")
                elif verbose and not xin:
                    rep.info(f"  ip2state[{k}] funclet exe 0x{xip + exe.base:x} {exe.name(xip + exe.base)}  "
                             f"obj {ent[0] if ent else '-'}+0x{(ent[2] if ent else 0):x}")


# ----------------------------------------------------------------------------------------------------------------
# Byte comparison + side-by-side

def masked_hex(data, mask):
    return " ".join(".." if mask[i] else f"{data[i]:02x}" for i in range(len(data)))


def insns(data, base, mask):
    out = []
    for i in MD.disasm(data, base):
        o = i.address - base
        m = mask[o:o + i.size]
        txt = f"{i.mnemonic} {i.op_str}".strip()
        key = (bytes(b if not m[k] else 0 for k, b in enumerate(i.bytes)), )
        out.append((o, masked_hex(i.bytes, m), txt, key))
    return out


def side_by_side(obytes, omask, xbytes, xmask, va):
    a = insns(obytes, 0, omask)
    b = insns(xbytes, va, xmask)
    sm = difflib.SequenceMatcher(a=[t[3] for t in a], b=[t[3] for t in b], autojunk=False)
    rows = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        n = max(i2 - i1, j2 - j1)
        for k in range(n):
            l = a[i1 + k] if i1 + k < i2 else None
            r = b[j1 + k] if j1 + k < j2 else None
            mark = " " if tag == "equal" else "!"
            ls = f"{l[0]:5x}  {l[1][:29]:<29} {l[2][:34]:<34}" if l else " " * 71
            rs = f"{va + r[0]:x}  {r[1][:29]:<29} {r[2][:40]}" if r else ""
            rows.append(f"  {mark} {ls} | {rs}")
    return rows


# ----------------------------------------------------------------------------------------------------------------
# Symbol map (progress/symbols.tsv): mangled external symbol -> exe VA, harvested from matched functions/vtables.
# Used (a) to check that a call/reference goes to the right exe address (not just a consistent one) and (b) by
# tools/ms2symobj.py to resolve references from recovered code to not-yet-recovered exe code/data in the hook DLL.

SYMBOLS_TSV = os.environ.get("MS2_SYMBOLS_TSV") or os.path.join(ROOT, "progress", "symbols.tsv")   # override: what-if table (work/cf7)
SYMBOLS = {}          # name -> va
HARVEST = {}          # name -> va (this run)
CONFLICTS = []
SYMBOL_MISMATCH = []  # (name, table va, exe va): a code-identical function disagrees with the symbol table
FUNCLET_PAIRS = {}  # unwind-map action funclet symbol (?dtor$N@...) -> exe VA, from every compared FuncInfo
LAST_TARGETS = {}  # every symbol -> exe target of the last match_one call (statics included; empty on mismatch)
LOCAL_KNOWN = {}   # name -> va pairs of the current unit (statics included), checked like SYMBOLS
# Statically linked runtime (CRT startup/helpers, import stubs) at the end of .text: never mapped - the hook DLL
# links its own CRT/MFC. Gamebryo resumes at 0x1427b6c90 (NOTES "Binary map").
RUNTIME_RANGES = [(0x142748000, 0x1427b6c90)]
NO_HARVEST_PREFIXES = ("__imp_", "??_C@", "__real@", "__xmm@", "__mask@", "__ymm@", "$", ".", "??_R", "__security_",
                       "_tls_", "__GSHandler", "__CxxFrameHandler", "_CxxThrowException", "__chkstk", "_fltused",
                       "_RTC_", "__std_", "_Init_thread_", "_Thrd_", "__acrt_", "__vcrt_", "__report_")


MULTICOPY = []     # (name, table va, exe va): one name, several byte-identical exe copies (info only, not a conflict)
LENIENT_TRIAL = False    # tools/progress.py late pass: strict pairing trials accept same-code copies of a known callee
STRICT_SYMBOLS = False  # tools/progress.py pairing trials: only the unit's own pairs override the table (the table's
                        # other copy stays a hint against look-alike candidates)
CUR_EXE = None     # the Exe of the current match_one call (note_symbol needs it for same_code)
_SAME_MEMO = {}
_MD2 = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
_MD2.detail = True


def _fn_size(exe, va):
    rva = va - exe.base
    if rva in exe.rf:
        return exe.rf[rva][0] - rva
    i = bisect.bisect_left(exe.starts, va)
    if i < len(exe.starts) and exe.starts[i] == va and i + 1 < len(exe.starts):
        n = exe.starts[i + 1] - va          # leaf without .pdata: up to the next function, minus int3 padding
        d = exe.read(va, n)
        while n > 1 and d[n - 1] == 0xCC:
            n -= 1
        return n
    return None


def same_code(exe, a, b, depth=32):
    """Per-unit COMDAT binding (NOTES "per-unit COMDAT binding (pin1)"): are the exe functions at a and b byte-identical
    copies? Same length, same instructions; branch/call/RIP-relative operands must reach the same offset inside the
    function, the same absolute address, or (recursively) identical functions. Conservative: anything else is False."""
    if a == b:
        return True
    if exe is None or os.environ.get("MS2_NO_MULTICOPY"):     # MS2_NO_MULTICOPY=1: old one-name-one-VA behaviour
        return False
    # Nested STL vector construction/destruction chains can exceed eight calls (e.g.
    # vector<pair<int, int>>::push_back). Keep a bounded traversal, but do not reject
    # equivalent copies solely because their allocator glue is deeply nested.
    key = (min(a, b), max(a, b))
    if key in _SAME_MEMO:
        return _SAME_MEMO[key]
    if depth <= 0:
        return False
    na, nb = _fn_size(exe, a), _fn_size(exe, b)
    if na and nb and na != nb and (_thin_forwarder(exe, a, na, b, depth) or _thin_forwarder(exe, b, nb, a, depth)
                                  or _ptr_release_variant(exe, a, na, b, nb)):
        _SAME_MEMO[key] = True      # NiPoint3() -> Point3(), NiPoint3::operator= -> Point3::operator=: same effect
        return True
    if not na or na != nb or na > 0x4000:
        _SAME_MEMO[key] = False
        return False
    _SAME_MEMO[key] = True          # coinductive: a cycle back to this pair counts as equal
    ok = _same_code(exe, a, b, na, depth)
    _SAME_MEMO[key] = ok
    return ok



def _ptr_release_variant(exe, a, na, b, nb):
    """Recognize the two verified MS2Ptr::ReleaseImpl forms, not arbitrary frame differences.

    One TU saves m_p in a local; another reloads m_p before each call. ReleasePtred
    and AddRefPtred only change the pointed-to CPtred count, so they cannot change
    the owning MS2Ptr's m_p. The branch, pointer offset, and all three operations
    must agree. In particular, arbitrary calls and writes are never normalized.
    """
    if not (na <= 0x60 and nb <= 0x60):
        return False
    release = SYMBOLS.get("?ReleasePtred@CPtred@@SAHPEAV1@@Z")
    addref = SYMBOLS.get("?AddRefPtred@CPtred@@SAXPEAV1@@Z")
    delete = SYMBOLS.get("?DeletePtred@CPtred@@SAXPEAV1@@Z")
    if None in (release, addref, delete):
        return False

    def decode(va, n):
        ins = list(_MD2.disasm(exe.read(va, n), va))
        if sum(i.size for i in ins) != n or len(ins) < 2:
            return None, []
        code, calls = [], []
        for i in ins:
            if i.mnemonic == "call" and i.operands[0].type == x86.X86_OP_IMM:
                code.append("call")
                calls.append(i.operands[0].imm)
            elif i.mnemonic == "jne" and i.operands[0].type == x86.X86_OP_IMM and i.operands[0].imm == ins[-2].address:
                code.append("jne exit")
            else:
                code.append((i.mnemonic + " " + i.op_str).strip())
        return code, calls

    prefix = ["mov qword ptr [rsp + 0x10], rdx", "mov qword ptr [rsp + 8], rcx"]
    cached = prefix + [
        "sub rsp, 0x38", "mov rax, qword ptr [rsp + 0x40]",
        "mov rax, qword ptr [rax + 8]", "mov qword ptr [rsp + 0x20], rax",
        "mov rcx, qword ptr [rsp + 0x20]", "call", "test eax, eax", "jne exit",
        "mov rcx, qword ptr [rsp + 0x20]", "call",
        "mov rcx, qword ptr [rsp + 0x20]", "call", "add rsp, 0x38", "ret"]
    load = ["mov rax, qword ptr [rsp + 0x30]", "mov rcx, qword ptr [rax + 8]"]
    reloaded = prefix + ["sub rsp, 0x28"] + load + ["call", "test eax, eax", "jne exit"] + load + ["call"] + load + ["call", "add rsp, 0x28", "ret"]
    ca, calls_a = decode(a, na)
    cb, calls_b = decode(b, nb)
    if not ((ca == cached and cb == reloaded) or (cb == cached and ca == reloaded)):
        return False
    reference = ["mov qword ptr [rsp + 8], rcx", "sub rsp, 0x28",
                 "mov rcx, qword ptr [rsp + 0x30]", "call", "add rsp, 0x28", "ret"]
    for calls in (calls_a, calls_b):
        if len(calls) != 3 or calls[0] != release or calls[2] != delete:
            return False
        n = _fn_size(exe, calls[1])
        if not n or n > 0x30:
            return False
        rc, targets = decode(calls[1], n)
        if rc != reference or targets != [addref]:
            return False
    return True


def _thin_forwarder(exe, a, n, b, depth):
    """Is the function at a a /Od thin wrapper (only mov/sub rsp/add rsp/ret plus one direct call, no branches) whose
    single callee is b (or a byte-identical copy of b)? Derived-class ctor/assign forwarding to the base one."""
    if n > 0x60:
        return False
    calls = []
    for ins in _MD2.disasm(exe.read(a, n), a):
        if ins.mnemonic == "call":
            if not ins.operands or ins.operands[0].type != x86.X86_OP_IMM:
                return False
            calls.append(ins.operands[0].imm)
        elif ins.mnemonic not in ("mov", "ret", "sub", "add"):
            return False
        elif ins.mnemonic in ("sub", "add") and "rsp" not in ins.op_str:
            return False
        elif ins.mnemonic == "mov" and "rip" in ins.op_str:
            return False
    return len(calls) == 1 and (calls[0] == b or same_code(exe, calls[0], b, depth - 1))


def _same_code(exe, a, b, n, depth):
    ia = list(_MD2.disasm(exe.read(a, n), a))
    ib = list(_MD2.disasm(exe.read(b, n), b))
    if len(ia) != len(ib) or sum(x.size for x in ia) != n:
        return False
    for x, y in zip(ia, ib):
        if x.size != y.size or x.id != y.id:
            return False
        bx, by = bytearray(x.bytes), bytearray(y.bytes)
        tx, ty = [], []
        for ins, buf, tg, lo in ((x, bx, tx, a), (y, by, ty, b)):
            branch = ins.group(capstone.CS_GRP_JUMP) or ins.group(capstone.CS_GRP_CALL)
            for op in ins.operands:
                if op.type == x86.X86_OP_IMM and branch and ins.imm_size:
                    tg.append(op.imm)
                    buf[ins.imm_offset:ins.imm_offset + ins.imm_size] = bytes(ins.imm_size)
                elif op.type == x86.X86_OP_MEM and op.mem.base == x86.X86_REG_RIP and ins.disp_size:
                    tg.append(ins.address + ins.size + op.mem.disp)
                    buf[ins.disp_offset:ins.disp_offset + ins.disp_size] = bytes(ins.disp_size)
        if bx != by or len(tx) != len(ty):
            return False
        for p, q in zip(tx, ty):
            if p == q:
                continue
            if a <= p < a + n and b <= q < b + n:
                if p - a != q - b:
                    return False
                continue
            if not same_code(exe, p, q, depth - 1):
                return False
    return True


def load_symbols(path=SYMBOLS_TSV):
    SYMBOLS.clear()
    if path and os.path.exists(path):
        for line in open(path):
            if line.startswith("#") or not line.strip():
                continue
            p = line.rstrip("\n").split("\t")
            SYMBOLS[p[0]] = int(p[1], 16)


def harvestable(name, va):
    if name.startswith(NO_HARVEST_PREFIXES) or name in ("memset", "memcpy", "memmove", "memcmp", "strlen", "atexit"):
        return False
    # guiddef.h's operator==/!= get C linkage when an SDK header includes it inside extern "C": cl names them "==" /
    # "!=", which /alternatename:<name>=<target> (tools/ms2symobj.py) cannot express. The inline COMDAT is defined by
    # every user anyway.
    if "=" in name:
        return False
    return not any(a <= va < b for a, b in RUNTIME_RANGES)


def note_symbol(name, va, rep):
    """Check name -> va against the symbol map; remember it for --harvest."""
    if not harvestable(name, va):
        return
    want = SYMBOLS.get(name)
    if want is not None and want != va and (not STRICT_SYMBOLS or LOCAL_KNOWN.get(name) == va) \
            and same_code(CUR_EXE, want, va):
        # one name, several byte-identical exe copies (template COMDATs per TU, or stand-in types that fold several
        # real instantiations into one mangled name): the unit's own binding wins for its own references
        MULTICOPY.append((name, want, va))
    elif want is not None and want != va:
        SYMBOL_MISMATCH.append((name, want, va))
        rep.bad(f"symbol {name} is 0x{want:x} in {os.path.relpath(SYMBOLS_TSV, ROOT)}, exe uses 0x{va:x} "
                f"(wrong callee/global?)")
        return
    prev = HARVEST.get(name)
    if prev is not None and prev != va:
        if same_code(CUR_EXE, prev, va):
            MULTICOPY.append((name, prev, va))      # first binding of this run stays
        else:
            CONFLICTS.append((name, prev, va))
        return
    HARVEST[name] = va


def write_harvest(path, exe, fresh=False):
    """Merge HARVEST into the symbol TSV (sym, va, kind). Existing entries win; conflicts are reported.
    fresh=True ignores the existing file (the table is rebuilt from the harvest alone)."""
    cur = {}
    if os.path.exists(path) and not fresh:
        for line in open(path):
            if line.startswith("#") or not line.strip():
                continue
            p = line.rstrip("\n").split("\t")
            cur[p[0]] = (int(p[1], 16), p[2] if len(p) > 2 else "")
    text_lo = exe.base + exe.pe.sections[0].VirtualAddress
    text_hi = text_lo + exe.pe.sections[0].Misc_VirtualSize
    added = 0
    for n, va in HARVEST.items():
        if n in cur:
            if cur[n][0] != va:
                if same_code(exe, cur[n][0], va):
                    MULTICOPY.append((n, cur[n][0], va))     # the existing entry stays the DLL's binding
                else:
                    CONFLICTS.append((n, cur[n][0], va))
            continue
        cur[n] = (va, "func" if text_lo <= va < text_hi else "data")
        added += 1
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "w") as f:
        f.write("#symbol\tva\tkind\n")
        for n, (va, k) in sorted(cur.items(), key=lambda kv: (kv[1][0], kv[0])):
            f.write(f"{n}\t{va:x}\t{k}\n")
    return added


def match_data(obj, si, va, exe, verbose, quiet=False):
    """Data symbol (vftable, constant table): unrelocated bytes equal, ADDR64 slots resolved against the exe."""
    global CUR_EXE
    CUR_EXE = exe
    rep = Report()
    name, value, secnum = obj.syms[si][0], obj.syms[si][1], obj.syms[si][2]
    sec = obj.sec(secnum)
    nxt = [v for (n, v, sn, t, c) in obj.syms.values() if sn == secnum and v > value]
    end = min(nxt) if nxt else sec["size"]
    data = sec["data"][value:end]
    xb = exe.read(va, len(data))
    mask = bytearray(len(data))
    nslot = 0
    for rva_, rsi, ty in sec["relocs"]:
        if not value <= rva_ < end:
            continue
        off = rva_ - value
        ln = RELOC_LEN.get(ty, 4)
        for k in range(off, min(off + ln, len(data))):
            mask[k] = 1
        if ty == REL_ADDR64 and off + 8 <= len(data):
            tgt = struct.unpack_from("<Q", xb, off)[0] - struct.unpack_from("<q", data, off)[0]
            tname = obj.syms[rsi][0]
            nslot += 1
            if verbose:
                rep.info(f"[+0x{off:x}] {tname} -> 0x{tgt:x} {exe.name(tgt)}")
            want = LOCAL_KNOWN.get(tname)
            if want is not None and want != tgt:
                rep.bad(f"[+0x{off:x}] {tname} is paired with 0x{want:x}, exe slot holds 0x{tgt:x}")
            elif obj.is_external(rsi) or obj.defined(rsi):
                note_symbol(tname, tgt, rep)
    ndiff = sum(1 for k in range(len(data)) if not mask[k] and data[k] != xb[k])
    if ndiff:
        rep.bad(f"{ndiff} unrelocated byte(s) differ")
    status = "MATCH" if rep.ok else "DIFF"
    print(f"{status:5} {name}  @0x{va:x}  (data, {len(data)} bytes, {nslot} pointer slots)")
    for l in rep.lines:
        print(l)
    if rep.ok and obj.is_external(si):
        note_symbol(name, va, rep)
    return rep.ok


def match_one(obj_or_cod, sym, va, exe, verbose, check_unwind, quiet=False):
    global CUR_EXE
    CUR_EXE = exe
    if isinstance(obj_or_cod, Obj):
        si = obj_or_cod.find_any(sym)
        if not obj_or_cod.is_code(si):
            return match_data(obj_or_cod, si, va, exe, verbose, quiet)
    rep = Report()
    if isinstance(obj_or_cod, Obj):
        obj = obj_or_cod
        si = obj.find(sym)
        name, value, secnum = obj.syms[si][0], obj.syms[si][1], obj.syms[si][2]
        data, fields, unw = obj.function(si)
    else:
        name, data = cod_function(obj_or_cod, sym)
        fields, unw, obj, value, secnum = heuristic_fields(data), None, None, 0, 0
    title = f"{name}  @0x{va:x}"
    exe_len = None
    rva = va - exe.base
    if rva in exe.rf:
        exe_len = exe.rf[rva][0] - rva
    xbytes = exe.read(va, max(len(data), exe_len or 0))
    if exe_len is not None and exe_len != len(data):
        rep.bad(f"length: obj {len(data)} exe {exe_len} (.pdata)")
    n = len(data)
    omask = bytearray(n)
    xmask = bytearray(len(xbytes))
    targets = {}
    tsyms = {}
    for off, ln, sname, ty, inner, tsi in fields:
        if inner is not None and off + 4 <= len(xbytes):       # jump-table entry: must point at the same offset
            xv = struct.unpack_from("<I", xbytes, off)[0]
            if xv != rva + inner:
                rep.bad(f"jump table entry at +0x{off:x}: obj -> +0x{inner:x}, exe -> 0x{xv + exe.base:x}")
        for k in range(off, min(off + ln, n)):
            omask[k] = 1
            if k < len(xmask):
                xmask[k] = 1
        if obj is not None and REL_REL32 <= ty <= REL_REL32 + 5 and off + 4 <= len(xbytes):
            disp = struct.unpack_from("<i", xbytes, off)[0]
            # REL32_k: the field is followed by k more bytes of the instruction (imm) before the next instruction
            tgt = va + off + 4 + (ty - REL_REL32) + disp
            # the obj stores the addend in the field; RIP-relative refs to sym+addend resolve to target+addend
            add = struct.unpack_from("<i", data, off)[0]
            tgt -= add
            prev = targets.get(sname)
            if prev is not None and prev != tgt:
                rep.bad(f"symbol {sname} resolves to two different exe targets 0x{prev:x} / 0x{tgt:x}")
            targets[sname] = tgt
            tsyms[sname] = tsi
    ndiff = sum(1 for k in range(min(n, len(xbytes))) if not omask[k] and data[k] != xbytes[k])
    if ndiff:
        rep.bad(f"{ndiff} unmasked byte(s) differ")
    for sname, tgt in targets.items():                      # imports: __imp_X must be the exe's IAT slot for X
        if sname.startswith("__imp_") and tgt in exe.imp and exe.imp[tgt] != sname[6:]:
            rep.bad(f"{sname} is the import {exe.imp[tgt]} in the exe")
    for sname, tgt in targets.items():                      # pairs known by the caller (tools/progress.py)
        want = LOCAL_KNOWN.get(sname)
        if want is not None and want != tgt:
            # the unit pairs the name with one exe copy but this function calls another, byte-identical COMDAT copy
            # (e.g. std::less<int>::operator() exists in the global table and again in the unit's own TU): same code
            # (not in pairing trials unless tools/progress.py's late multicopy pass asks: identical look-alikes of other
            # types call the same bytes through a same-code copy, and only exact trials tell them apart)
            if (not STRICT_SYMBOLS or LENIENT_TRIAL) and same_code(CUR_EXE, want, tgt):
                MULTICOPY.append((sname, want, tgt))
                targets[sname] = want       # the unit's own binding is what harvest/refs see, not the other copy
                continue
            rep.bad(f"{sname} is paired with 0x{want:x}, exe calls/uses 0x{tgt:x}")
    LAST_TARGETS.clear()
    if obj is not None and rep.ok:                             # targets are only meaningful if the code matches
        LAST_TARGETS.update(targets)
        for sname, tgt in targets.items():
            tsi = tsyms.get(sname)
            if tsi is not None and obj.is_external(tsi):
                note_symbol(sname, tgt, rep)
        if rep.ok and obj.is_external(obj.find_any(sym)):
            note_symbol(name, va, rep)
    if obj is not None and check_unwind:
        compare_unwind(obj, unw, exe, va, value, secnum, rep, verbose)
    status = "MATCH" if rep.ok else "DIFF"
    print(f"{status:5} {title}  ({n} bytes, {sum(omask)} masked in {len(fields)} reloc fields)")
    for l in rep.lines:
        print(l)
    if verbose and targets:
        for s, t in sorted(targets.items(), key=lambda kv: kv[1]):
            print(f"    {s:<60} -> 0x{t:x} {exe.name(t)}")
    if not rep.ok and not quiet:
        L = max(n, exe_len or 0)
        xb = exe.read(va, L)
        xm = bytearray(L)
        om = bytearray(omask)
        for k in range(min(L, n)):
            xm[k] = omask[k]
        for row in side_by_side(data, om, xb, xm, va):
            print(row)
    return rep.ok


def search(obj, pats, exe, full=False):
    bylen = {}
    for rva, (end, _) in exe.rf.items():
        bylen.setdefault(end - rva, []).append(rva)
    syms = [obj.find(p) for p in pats] if pats else obj.func_symbols()
    for si in syms:
        name = obj.syms[si][0]
        data, fields, unw = obj.function(si)
        mask = bytearray(len(data))
        for off, ln, *_ in fields:
            for k in range(off, min(off + ln, len(data))):
                mask[k] = 1
        keep = [k for k in range(len(data)) if not mask[k]]
        want = bytes(data[k] for k in keep)
        hits = []
        for rva in bylen.get(len(data), []):
            x = exe.img[rva:rva + len(data)]
            if bytes(x[k] for k in keep) == want:
                hits.append(rva + exe.base)
        hits.sort()
        hs = " ".join(f"0x{h:x}" for h in (hits if full else hits[:8])) + (f" ... (+{len(hits) - 8})" if len(hits) > 8 and not full else "")
        print(f"{len(hits):5} hits  {len(data):5}B  {name}  {hs}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file", help=".obj or .cod")
    ap.add_argument("pairs", nargs="*", help="SYMBOL VA [SYMBOL VA ...]")
    ap.add_argument("-v", "--verbose", action="store_true")
    ap.add_argument("--no-unwind", action="store_true")
    ap.add_argument("--list", action="store_true", help="list function symbols of the obj")
    ap.add_argument("--map", help="file with 'SYMBOL VA' lines (# comments) instead of / in addition to pairs")
    ap.add_argument("--search", action="store_true",
                    help="for every function symbol of the obj (or the given SYMBOLs), list exe functions (by .pdata) "
                         "with the same length and identical bytes outside the reloc fields")
    ap.add_argument("-q", "--quiet", action="store_true", help="status lines only (no side-by-side)")
    ap.add_argument("--exe", default=EXE)
    ap.add_argument("--symbols", default=SYMBOLS_TSV,
                    help="symbol map to check references against (default progress/symbols.tsv; '' = none)")
    ap.add_argument("--harvest", nargs="?", const=SYMBOLS_TSV, default=None,
                    help="merge symbol->VA pairs of matched functions/vtables into this TSV (default progress/symbols.tsv)")
    a = ap.parse_args()
    load_symbols(a.symbols)
    src = Obj(a.file) if not a.file.lower().endswith(".cod") else a.file
    if a.list:
        if not isinstance(src, Obj):
            sys.exit("--list needs an .obj")
        for i in src.func_symbols():
            n, v, s, t, c = src.syms[i]
            d, f, u = src.function(i)
            print(f"{len(d):6}  {src.sec(s)['name']:<10} {n}  ({demangle(n)})")
        return
    if a.search:
        if not isinstance(src, Obj):
            sys.exit("--search needs an .obj")
        exe = Exe(a.exe)
        search(src, a.pairs, exe, a.verbose)
        return
    pairs = list(a.pairs)
    if a.map:
        for line in open(a.map):
            line = line.split("#", 1)[0].split()
            if len(line) >= 2:
                pairs += line[:2]
    if len(pairs) % 2 or not pairs:
        sys.exit("need SYMBOL VA pairs")
    exe = Exe(a.exe)
    nok = 0
    for k in range(0, len(pairs), 2):
        nok += match_one(src, pairs[k], int(pairs[k + 1], 16), exe, a.verbose, not a.no_unwind, a.quiet)
    if len(pairs) > 2:
        print(f"{nok}/{len(pairs) // 2} matched")
    if a.harvest:
        added = write_harvest(a.harvest, exe)
        print(f"harvest: {added} new symbol(s) -> {a.harvest}")
    for n, x, y in CONFLICTS:
        print(f"CONFLICT {n}: 0x{x:x} vs 0x{y:x}")
    sys.exit(0 if nok == len(pairs) // 2 else 1)


if __name__ == "__main__":
    main()
