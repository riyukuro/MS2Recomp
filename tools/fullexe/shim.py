#!/usr/bin/env python3
"""Full-exe shim: definitions for every external no linked obj defines, so the link closes without /FORCE:UNRESOLVED.
    shim.py [--unresolved FILE] [--sdk-lib LIB ...]
  --unresolved   symbol list (first column; default unresolved<TAG>.txt of the previous /FORCE link, see analyze.py)
  --sdk-lib      import/static libs linked after the generated import libs: symbols they define get no stub (default:
                 link.py's SDK_LIBS, which link.py --shim adds; a stub for e.g. __imp_CreateThread would win over them)
Writes <OUT>/shim/: stubs.obj (a COFF object written here, no compiler), shim_runtime.obj (tools/fullexe/
shim_runtime.cpp: g_imageDelta = 0, no-op hook::Register, the trap logger, boot milestones) and stubs.tsv.

  functions  a 32-byte stub: lea rcx,"<symbol>"; mov rdx,<exe va or 0>; mov r8,[rsp]; jmp ms2_fullexe_trap (logs the
             symbol, VA and caller to fullexe-trap.log next to the exe, then terminates)
  data       the exe's bytes at the symbol's VA (symbols tables or the DAT_/PTR_ name), sized up to the next known
             symbol (8 B .. 64 KB): constant tables come out right. Pointer slots (the exe's base relocations) are
             relocated to the obj symbol defined at the target VA, to another stub, to a trap stub for code VAs, or
             to a copy of the pointed-to exe data (strings, nested tables; 4 MB budget); else 0. No VA: 256 zero bytes.
  vftables   the exe's slot count, each slot -> its target as above (defined function, or a trap naming the vftable)
  __imp_X    a pointer to a trap stub for X
  abithunks  --thunks (default <OUT>/abithunks.tsv, written by alias.py): `xchg rdx,rcx; jmp <definition>` for a
             free declaration of a member function returning a class by value (or the reverse): the hidden return
             pointer and `this` trade registers; a "shift" line (scalar declaration of a cri_any-returning definition,
             at most 3 arguments): the arguments move one register right, rcx = a stack slot, rax = the slot after the call
The generated obj holds exe bytes: it stays in work/ (never committed)."""
import argparse, bisect, collections, os, re, struct, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import SYMBOL_TABLES, ROOT, OUT, TREE, EXE, tagged, wine  # noqa: E402
import ms2paths  # noqa: E402
import pefile  # noqa: E402

BASE = 0x140000000
DATA_CAP, ANON_BUDGET, NOVA_SIZE = 0x10000, 4 << 20, 256
VA_NAME = re.compile(r"(?:^|[?_])(?:FUN|DAT|PTR|LAB|UINT|UNK|BYTE|WORD|DWORD|QWORD|INT|FLOAT|DOUBLE|ULONG|LONG|"
                     r"USHORT|SHORT|CHAR|BOOL|GUID|IID|STRUCT|ARRAY|s|u|switchD|caseD)_(1[0-9a-f]{8})\b", re.I)
CC = re.compile(r"(?<!\()\b__(?:cdecl|thiscall|stdcall|fastcall|vectorcall|clrcall)\b")
NOVA_DATA = re.compile(r"^(?:IID_|GUID_|CLSID_|c_df|GFx_Compile|luaP_op)")


# ---------------------------------------------------------------- COFF writer
class Section:
    def __init__(self, name, flags):
        self.name, self.flags, self.data, self.relocs = name, flags, bytearray(), []   # relocs: (off, symidx, type)

    def align(self, a, fill=b"\0"):
        while len(self.data) % a:
            self.data += fill


class Coff:
    def __init__(self):
        self.secs, self.syms, self.index = [], [], {}       # syms: [name, value, secno(1-based or 0), type, class]

    def section(self, name, flags):
        s = Section(name, flags)
        self.secs.append(s)
        self.syms.append([name, 0, len(self.secs), 0, 3])   # section symbol (static)
        s.symidx = len(self.syms) - 1
        return s

    def sym(self, name, sec=None, value=0, func=False):
        """define (sec given) or reference an external; returns the symbol index"""
        if name in self.index:
            i = self.index[name]
            if sec is not None:
                self.syms[i][1:3] = [value, self.secs.index(sec) + 1]
            return i
        self.syms.append([name, value, (self.secs.index(sec) + 1) if sec is not None else 0, 0x20 if func else 0, 2])
        self.index[name] = len(self.syms) - 1
        return self.index[name]

    def write(self, path):
        strtab = bytearray()
        symtab = bytearray()

        def name8(n):
            b = n.encode("latin1")
            if len(b) <= 8:
                return b.ljust(8, b"\0")
            off = 4 + len(strtab)
            strtab.extend(b + b"\0")
            return struct.pack("<II", 0, off)

        # split sections whose relocation count exceeds 0xFFFF is avoided by NRELOC_OVFL
        hdr_size = 20 + 40 * len(self.secs)
        raw, pos = [], hdr_size
        for s in self.secs:
            s.align(4)
            rel = bytearray()
            relocs = s.relocs
            ovfl = len(relocs) >= 0xFFFF
            if ovfl:
                rel += struct.pack("<IIH", len(relocs) + 1, 0, 0)
            for off, si, t in relocs:
                rel += struct.pack("<IIH", off, si, t)
            raw.append((s, pos, pos + len(s.data), rel, ovfl))
            pos += len(s.data) + len(rel)
        symoff = pos
        for name, value, sec, typ, cls in self.syms:
            symtab += name8(name) + struct.pack("<IhHBB", value, sec, typ, cls, 0)
        out = bytearray(struct.pack("<HHIIIHH", 0x8664, len(self.secs), 0, symoff, len(self.syms), 0, 0))
        for s, dpos, rpos, rel, ovfl in raw:
            flags = s.flags | (0x01000000 if ovfl else 0)
            nrel = 0xFFFF if ovfl else len(s.relocs)
            out += name8(s.name) + struct.pack("<IIIIIIHHI", 0, 0, len(s.data), dpos, rpos if rel else 0, 0, nrel, 0, flags)
        for s, dpos, rpos, rel, ovfl in raw:
            out += s.data + rel
        out += symtab + struct.pack("<I", 4 + len(strtab)) + strtab
        open(path, "wb").write(out)


REL_ADDR64, REL_REL32 = 1, 4
TEXT = 0x60000020 | 0x00500000      # code, execute/read, align 16
RDATA = 0x40000040 | 0x00500000     # initialized data, read, align 16
DATA = 0xC0000040 | 0x00500000      # initialized data, read/write, align 16


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--unresolved", default=tagged("unresolved.txt"))
    ap.add_argument("--sdk-lib", action="append", default=[])
    ap.add_argument("--thunks", default=os.path.join(OUT, "abithunks.tsv"))
    a = ap.parse_args()
    sd = os.path.join(OUT, "shim")
    os.makedirs(sd, exist_ok=True)

    want = []
    for l in open(a.unresolved, encoding="latin1"):
        s = l.rstrip("\n").split("\t")[0]
        if s and s[0] != "#":
            want.append(s)
    provided = set()
    if not a.sdk_lib:
        from link import SDK_LIBS, SDK_UM
        a.sdk_lib = [os.path.join(SDK_UM, l + ".lib") for l in SDK_LIBS]
    for lib in a.sdk_lib:
        t = subprocess.run(["llvm-nm", "--defined-only", "--no-sort", "-j", lib], capture_output=True, text=True,
                           errors="replace").stdout
        provided.update(x.strip() for x in t.splitlines() if x.strip() and not x.endswith(":"))
    runtime = {"?g_imageDelta@ms2@@3_KA", "?Register@hook@ms2@@YA_NPEAUReplacement@12@@Z"}
    thunks = {}
    if os.path.exists(a.thunks):
        for l in open(a.thunks, encoding="latin1"):
            p = l.rstrip("\n").split("\t")
            if len(p) > 1 and p[0][0] != "#":
                thunks[p[0]] = (p[1], p[2] if len(p) > 2 else "swap")
    want = sorted(set(w for w in want if w not in provided and w not in runtime and w not in thunks))

    # exe VAs of symbols; VAs our objs define (for pointer slots)
    sym2va = {}
    for fn in SYMBOL_TABLES:
        for l in open(os.path.join(TREE, "progress", fn), encoding="latin1"):
            p = l.rstrip("\n").split("\t")
            if l[0] != "#" and len(p) > 1:
                try:
                    sym2va.setdefault(p[0], int(p[1], 16))
                except ValueError:
                    pass
    defined = set(l.split("\t", 1)[0] for l in open(os.path.join(OUT, "defsyms.tsv"), encoding="latin1"))
    va2def = {}
    for s in defined:
        va = sym2va.get(s)
        if va is None:
            m = VA_NAME.search(s)
            va = int(m.group(1), 16) if m else None
        if va is not None and (va not in va2def or len(s) < len(va2def[va])):
            va2def[va] = s
    fstart = set()
    for l in open(ms2paths.FUNCTIONS_TSV):
        p = l.split("\t")
        if p[0] and p[0][0] != "#":
            try:
                fstart.add(int(p[0], 16))
            except ValueError:
                pass

    pe = pefile.PE(EXE, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_BASERELOC"]])
    secs = [(BASE + s.VirtualAddress, BASE + s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData), s)
            for s in pe.sections]
    relocs = set()
    for blk in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", []):
        for e in blk.entries:
            if e.type == 10:                                   # IMAGE_REL_BASED_DIR64
                relocs.add(BASE + e.rva)
    rel_sorted = sorted(relocs)

    def sec_of(va):
        for lo, hi, s in secs:
            if lo <= va < hi:
                return s
        return None

    def is_exec(va):
        s = sec_of(va)
        return bool(s and s.Characteristics & 0x20000000)

    def exe_bytes(va, n):
        s = sec_of(va)
        off = va - BASE - s.VirtualAddress
        d = s.get_data()[off:off + n]                            # past the raw data: zero fill (bss)
        return d + b"\0" * (n - len(d))

    # demangle the mangled names once
    mangled = [w for w in want if w.startswith("?") or w.startswith("__imp_?")]
    dem = {}
    if mangled:
        t = subprocess.run(["llvm-undname"], input="\n".join(m.replace("__imp_", "", 1) for m in mangled) + "\n",
                           capture_output=True, text=True, errors="replace").stdout.split("\n")
        i = 0
        while i + 1 < len(t):
            if t[i]:
                dem[t[i]] = t[i + 1]
                i += 3
            else:
                i += 1

    def va_of(s):
        if s in sym2va:
            return sym2va[s]
        m = VA_NAME.search(s)
        return int(m.group(1), 16) if m else None

    def kind_of(s, va):
        if s.startswith("__imp_"):
            return "imp"
        if s.startswith("??_7"):
            return "vftable"
        if s.startswith("?"):
            if s.startswith("??_R") or s.startswith("??_C@"):
                return "data"
            d = dem.get(s, "")
            if CC.search(d):
                return "code"
            if d and d != s:
                return "data"
            return "code" if (va is None or is_exec(va)) else "data"
        if re.match(r"(?:FUN|LAB|thunk_FUN|caseD|switchD)_", s):
            return "code"
        if va is not None:
            return "code" if va in fstart or (is_exec(va) and not re.match(r"[A-Z]+_", s)) else "data"
        return "data" if NOVA_DATA.match(s) else "code"

    # all known VAs bound data sizes
    known = sorted(set(sym2va.values()) | fstart | set(va2def) | {v for v in (va_of(w) for w in want) if v})

    def size_at(va):
        i = bisect.bisect_right(known, va)
        nxt = known[i] if i < len(known) else va + 8
        s = sec_of(va)
        end = BASE + s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData) if s else va + 8
        return max(8, min(nxt, end, va + DATA_CAP) - va)

    co = Coff()
    text = co.section(".text$mn", TEXT)
    rdata = co.section(".rdata", RDATA)
    data = co.section(".data", DATA)
    strs = co.section(".rdata$str", RDATA)
    trap = co.sym("ms2_fullexe_trap")
    str_off = {}

    def cstr(s):
        if s not in str_off:
            str_off[s] = len(strs.data)
            strs.data += s.encode("latin1", "replace") + b"\0"
        return str_off[s]

    def code_stub(label, va, public=None):
        """32-byte trap stub; returns its offset in .text"""
        text.align(16, b"\xcc")
        off = len(text.data)
        so = cstr(label)
        text.data += b"\x48\x8d\x0d" + struct.pack("<i", so)               # lea rcx,[rip+str]   (REL32, addend = so)
        text.relocs.append((off + 3, strs.symidx, REL_REL32))
        text.data += b"\x48\xba" + struct.pack("<Q", va or 0)              # mov rdx, va
        text.data += b"\x4c\x8b\x04\x24"                                   # mov r8,[rsp]
        text.data += b"\xe9\0\0\0\0"                                       # jmp ms2_fullexe_trap
        text.relocs.append((off + 22, trap, REL_REL32))
        text.align(16, b"\xcc")
        if public:
            co.sym(public, text, off, func=True)
        return off

    rows = []
    stub_va = {}                                   # exe va -> symbol name of a stub defined here (data and code)
    kinds = {}
    for s in want:
        va = va_of(s)
        kinds[s] = (kind_of(s, va), va)
        if va is not None:
            stub_va.setdefault(va, s)

    # code stubs first: data pointer slots may target them
    code_at = {}                                   # exe va -> .text offset of a trap stub for it
    for s in want:
        k, va = kinds[s]
        if k == "code":
            off = code_stub(s, va, s)
            if va is not None:
                code_at.setdefault(va, off)
            rows.append((s, k, va, 32))

    for s, (d, kind) in sorted(thunks.items()):
        text.align(16, b"\xcc")
        off = len(text.data)
        if kind == "shift":
            text.data += (b"\x48\x83\xec\x38"                              # sub rsp,0x38
                          b"\x4d\x89\xc1\x49\x89\xd0\x48\x89\xca"              # mov r9,r8; mov r8,rdx; mov rdx,rcx
                          b"\x48\x8d\x4c\x24\x28"                          # lea rcx,[rsp+0x28]
                          b"\xe8\0\0\0\0"                                  # call <definition>
                          b"\x48\x8b\x44\x24\x28"                          # mov rax,[rsp+0x28]
                          b"\x48\x83\xc4\x38\xc3")                         # add rsp,0x38; ret
            text.relocs.append((off + 19, co.sym(d), REL_REL32))
        else:
            text.data += b"\x48\x87\xca\xe9\0\0\0\0"                     # xchg rdx,rcx; jmp <definition>
            text.relocs.append((off + 4, co.sym(d), REL_REL32))
        co.sym(s, text, off, func=True)
        rows.append((s, "abithunk", None, 8))

    anon = {}                                      # exe va -> (section, offset) of a copied anonymous blob
    budget = [ANON_BUDGET]
    pending = []                                   # (section, offset of slot, target va)
    unresolved_ptrs = collections.Counter()

    def place_blob(sec, va, n):
        sec.align(16)
        off = len(sec.data)
        sec.data += exe_bytes(va, n)
        i = bisect.bisect_left(rel_sorted, va)
        while i < len(rel_sorted) and rel_sorted[i] < va + n:
            r = rel_sorted[i]
            if r + 8 <= va + n:
                tgt = struct.unpack_from("<Q", sec.data, off + r - va)[0]
                struct.pack_into("<Q", sec.data, off + r - va, 0)
                pending.append((sec, off + r - va, tgt))
            i += 1
        return off

    def blob_section(va):
        s = sec_of(va)
        return data if s is not None and s.Characteristics & 0x80000000 else rdata

    data_at = {}                                   # exe va -> (section, offset) of a data stub defined here
    for s in want:
        k, va = kinds[s]
        if k == "data":
            if va is not None and sec_of(va) is not None:
                if va in data_at:
                    sec, off = data_at[va]
                else:
                    n = size_at(va)
                    sec = blob_section(va)
                    off = place_blob(sec, va, n)
                    data_at[va] = (sec, off)
                co.sym(s, sec, off)
                rows.append((s, k, va, size_at(va)))
            else:
                data.align(16)
                co.sym(s, data, len(data.data))
                data.data += b"\0" * NOVA_SIZE
                rows.append((s, k, va, NOVA_SIZE))
        elif k == "vftable":
            n = 0
            if va is not None and sec_of(va) is not None:
                while n < 2048:
                    v = struct.unpack("<Q", exe_bytes(va + 8 * n, 8))[0]
                    if not (BASE <= v < BASE + 0x10000000 and is_exec(v)) or (n and va + 8 * n in stub_va):
                        break
                    n += 1
            if va is not None and va in data_at:
                sec, off = data_at[va]
            else:
                n = n or 64
                sec = rdata
                sec.align(16)
                off = len(sec.data)
                sec.data += b"\0" * (8 * n)
                for j in range(n):
                    tgt = struct.unpack("<Q", exe_bytes(va + 8 * j, 8))[0] if va is not None and sec_of(va) else None
                    pending.append((sec, off + 8 * j, tgt if tgt else ("vftable " + s, j)))
                if va is not None:
                    data_at[va] = (sec, off)
            co.sym(s, sec, off)
            rows.append((s, k, va, 8 * n))
        elif k == "imp":
            rdata.align(8)
            off = len(rdata.data)
            rdata.data += b"\0" * 8
            pending.append((rdata, off, ("import " + s[6:], 0)))
            co.sym(s, rdata, off)
            rows.append((s, k, None, 8))

    # pointer slots
    while pending:
        sec, slot, tgt = pending.pop()
        if isinstance(tgt, tuple):                                        # synthetic trap (vftable slot / import)
            label = tgt[0] + (" slot %d" % tgt[1] if tgt[0].startswith("vftable") else "")
            toff = code_stub(label, 0)
            sec.relocs.append((slot, text.symidx, REL_ADDR64))
            struct.pack_into("<Q", sec.data, slot, toff)
            continue
        if tgt in va2def:
            sec.relocs.append((slot, co.sym(va2def[tgt]), REL_ADDR64))
        elif tgt in data_at:
            dsec, doff = data_at[tgt]
            sec.relocs.append((slot, dsec.symidx, REL_ADDR64))
            struct.pack_into("<Q", sec.data, slot, doff)
        elif tgt in code_at or (sec_of(tgt) is not None and is_exec(tgt)):
            if tgt not in code_at:
                code_at[tgt] = code_stub("code pointer 0x%x" % tgt, tgt)
            sec.relocs.append((slot, text.symidx, REL_ADDR64))
            struct.pack_into("<Q", sec.data, slot, code_at[tgt])
        elif sec_of(tgt) is not None and budget[0] > 0:
            # inside a blob we already copied?
            hit = None
            for (bva, (bsec, boff)) in ((v, data_at[v]) for v in [known[max(0, bisect.bisect_right(known, tgt) - 1)]]
                                         if v in data_at):
                if bva <= tgt < bva + size_at(bva):
                    hit = (bsec, boff + tgt - bva)
            if hit is None:
                start = tgt
                n = size_at(start)
                budget[0] -= n
                bsec = blob_section(start)
                boff = place_blob(bsec, start, n)
                data_at[start] = (bsec, boff)
                hit = (bsec, boff)
            sec.relocs.append((slot, hit[0].symidx, REL_ADDR64))
            struct.pack_into("<Q", sec.data, slot, hit[1])
        else:
            unresolved_ptrs[sec_of(tgt).Name.rstrip(b"\0").decode() if sec_of(tgt) else "outside"] += 1

    co.write(os.path.join(sd, "stubs.obj"))
    with open(os.path.join(sd, "stubs.tsv"), "w") as f:
        f.write("#symbol\tkind\texe_va\tbytes\n")
        for s, k, va, n in rows:
            f.write("%s\t%s\t%s\t%d\n" % (s, k, "%x" % va if va is not None else "", n))
    c = collections.Counter(k for _, k, _, _ in rows)
    print("stubs: %d symbols (%s); %d provided by the SDK libs; .text %d B, .rdata %d B, .data %d B; "
          "copied exe data budget used %d B; pointer slots left 0: %s" % (
              len(rows), ", ".join("%s %d" % kv for kv in c.most_common()), len(provided & set(
                  l.rstrip("\n").split("\t")[0] for l in open(a.unresolved, encoding="latin1"))),
              len(text.data), len(rdata.data), len(data.data), ANON_BUDGET - budget[0], dict(unresolved_ptrs)))

    # the runtime obj
    src = os.path.join(ROOT, "tools", "fullexe", "shim_runtime.cpp")
    obj = os.path.join(sd, "shim_runtime.obj")
    env = ms2paths.toolchain_env()
    r = subprocess.run([ms2paths.find_cl(env), "/nologo", "/c", "/O2", "/MD", "/EHsc", "/W3", "/D_AFXDLL",
                        wine(src) if not ms2paths.is_nt() else src, "/Fo" + (wine(obj) if not ms2paths.is_nt() else obj)],
                       env=env, capture_output=True, text=True, errors="replace")
    if r.returncode:
        sys.exit("shim_runtime.cpp: cl failed\n" + r.stdout + r.stderr)
    print("shim_runtime.obj built")


if __name__ == "__main__":
    main()
