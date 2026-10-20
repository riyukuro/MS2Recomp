#!/usr/bin/env python3
"""Generate the link-time symbol object for the hook DLL: every not-yet-recovered exe function/global becomes linkable
under its real (mangled) name, so recovered code calls unrecovered code through plain declarations.

    .venv/bin/python tools/ms2symobj.py [-o build/.../ms2sym.obj] [progress/symbols.tsv ...]

Input: progress/symbols.tsv (symbol, va, kind; written by tools/progress.py / bytematch --harvest) and the optional
hand-written progress/symbols-manual.tsv (same format, for names no matched function references yet).
Output: a COFF (bigobj) object with
  func  __ms2fn_<va>: a 14-byte thunk `jmp qword ptr [rip+0]; dq <va>` in its own COMDAT (unreferenced ones are
        dropped by /OPT:REF);
  data  __ms2va_<va>: an absolute symbol whose value is the exe VA minus the DLL base (0x100000000): the linker
        treats absolute symbols as image-relative for REL32 (RIP-relative) fixups, so `mov eax, [g_x]` reaches the
        exe's global (|distance| < 2 GB because the DLL is linked /FIXED at 0x100000000, the exe sits at 0x140000000);
  .drectve /alternatename:<symbol>=__ms2fn_<va> / __ms2va_<va> for every symbol: the alternate is used only when
        nothing else defines <symbol> (no object, no library member), so a recovered definition always wins.
Limits (docs/RECOVERY.md): data may only be referenced RIP-relatively (no `&g_x` in a static initializer = ADDR64;
the linker would store VA - 0x100000000; the post-link step `tools/ms2symobj.py --check <dll>` fails the build), and the exe's statically linked
runtime (CRT, import stubs; 0x142748000-0x1427b6c90) is never mapped: the DLL uses its own CRT/MFC.
"""
import argparse
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DLL_BASE = 0x100000000
RUNTIME_RANGES = [(0x142748000, 0x1427b6c90)]
DEFAULT_INPUTS = [os.path.join(ROOT, "progress", "symbols.tsv"), os.path.join(ROOT, "progress", "symbols-manual.tsv")]

IMAGE_SCN_CNT_CODE = 0x20
IMAGE_SCN_LNK_INFO = 0x200
IMAGE_SCN_LNK_REMOVE = 0x800
IMAGE_SCN_LNK_COMDAT = 0x1000
IMAGE_SCN_ALIGN_1BYTES = 0x100000
IMAGE_SCN_ALIGN_2BYTES = 0x200000
IMAGE_SCN_MEM_EXECUTE = 0x20000000
IMAGE_SCN_MEM_READ = 0x40000000
BIGOBJ_CLASSID = bytes.fromhex("c7a1bad1eebaa94baf20faf66aa4dcb8")


def load(paths):
    """Later tables override earlier ones, but only engine -> anything is a deliberate override (symbols-engine.tsv is
    the FID guess table, lowest priority). The same name at two different VAs anywhere else (within a file, or across
    symbols.tsv / symbols-manual.tsv) is an error; so is the engine table itself having a name twice."""
    syms = {}
    src = {}
    conflicts = []
    multicopy = []
    for p in paths:
        if not os.path.exists(p):
            continue
        is_engine = os.path.basename(p) == "symbols-engine.tsv"
        for n, line in enumerate(open(p), 1):
            if line.startswith("#") or not line.strip():
                continue
            f = line.rstrip("\n").split("\t")
            name, va, kind = f[0], int(f[1], 16), (f[2] if len(f) > 2 else "func")
            if any(a <= va < b for a, b in RUNTIME_RANGES):
                continue
            if name in syms and syms[name][0] != va:
                prev = src[name]
                if not prev[2]:
                    if same_code(syms[name][0], va):
                        # byte-identical exe copies under one name (per-unit COMDAT binding, NOTES "pin1"): calling
                        # either is equivalent; the earlier table's binding stays (deterministic)
                        multicopy.append(name)
                        continue
                    conflicts.append(f"{name}: 0x{syms[name][0]:x} ({prev[0]}:{prev[1]}) vs 0x{va:x} ({os.path.basename(p)}:{n})")
            syms[name] = (va, kind)
            src[name] = (os.path.basename(p), n, is_engine)
    if multicopy:
        print(f"ms2symobj: {len(multicopy)} name(s) listed at byte-identical exe copies; first table's VA kept")
    if conflicts:
        sys.exit("ms2symobj: symbol name bound to different VAs (only symbols-engine.tsv may be overridden):\n  " +
                 "\n  ".join(conflicts))
    return syms


_EXE = []


def same_code(a, b):
    """bytematch.same_code on the exe (loaded lazily: only needed when two tables disagree)."""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import bytematch as bm
    if not _EXE:
        _EXE.append(bm.Exe(bm.EXE))
    return bm.same_code(_EXE[0], a, b)


FUN_RE = re.compile(r"FUN_([0-9a-f]{8,9})(?![0-9a-zA-Z])")


def undefined_externals(objs):
    """Undefined external symbol names of COFF objects (regular and bigobj)."""
    out = set()
    for path in objs:
        d = open(path, "rb").read()
        if d[:4] == b"\0\0\xff\xff":                     # bigobj
            symoff, nsyms = struct.unpack_from("<II", d, 48)
            recsz = 20
        else:
            symoff, nsyms = struct.unpack_from("<II", d, 8)
            recsz = 18
        stroff = symoff + nsyms * recsz
        i = 0
        while i < nsyms:
            o = symoff + i * recsz
            nm = d[o:o + 8]
            value, secnum = struct.unpack_from("<Ii", d, o + 8) if recsz == 20 else struct.unpack_from("<Ih", d, o + 8)
            sclass, naux = d[o + recsz - 2], d[o + recsz - 1]
            if sclass == 2 and secnum == 0 and value == 0:
                if nm[:4] == b"\0\0\0\0":
                    so = stroff + struct.unpack_from("<I", nm, 4)[0]
                    nm = d[so:d.index(b"\0", so)]
                else:
                    nm = nm.rstrip(b"\0")
                out.add(nm.decode("latin1"))
            i += 1 + naux
    return out


def autobind_fun(syms, objs):
    """Undefined externals named ...FUN_<va>... bind to that exe VA when it is a known function start. An explicit
    symbols.tsv / symbols-manual.tsv entry for the same name always wins."""
    starts = set()
    fp = os.path.join(os.environ.get("MS2_MAP_DIR") or os.path.join(ROOT, "work"), "functions.tsv")
    if os.path.exists(fp):
        for line in open(fp):
            starts.add(line.split("\t", 1)[0].strip().lower())
    n = 0
    for name in sorted(undefined_externals(objs)):
        if name in syms:
            continue
        m = FUN_RE.search(name)
        if m and m.group(1) in starts:
            va = int(m.group(1), 16)
            if not any(a <= va < b for a, b in RUNTIME_RANGES):
                syms[name] = (va, "func")
                n += 1
    return n


KEEP_LOCAL_PREFIXES = ("??_", "__imp_", "_TI", "__ImageBase")


def rebind_objects(syms, objs, prev_log=None):
    """Hook-DLL builds only: a data symbol that a recovered unit DEFINES (a TSingleton<T>::s_instance instantiation, an
    s_bInit flag, ms_propertyMap, a DAT_ global ...) and that has an exe VA in the symbol tables would otherwise be a
    DLL-local copy, never the exe's live instance (/alternatename only applies when nothing defines the name). Rewrite
    the object files in place: such a definition becomes an undefined external, so the /alternatename of ms2sym.obj binds
    it to the exe address. vftables / RTTI / import slots (KEEP_LOCAL_PREFIXES) stay local. A COMDAT section whose only
    symbols were rebound loses its COMDAT flag (a leaderless COMDAT is invalid); the bytes are dead weight. Idempotent.
    Returns the list of rebound names (with repeats across objects)."""
    names = {n for n, (va, k) in syms.items() if k != "func" and not n.startswith(KEEP_LOCAL_PREFIXES)}
    out = []
    if prev_log and os.path.exists(prev_log):
        # objects keep their compile mtime (incremental builds), so a rebind done by an earlier run is permanent: if a
        # symbol left the tables the objects must be recompiled, which only a deleted object forces
        gone = set(open(prev_log).read().split()) - names
        if gone:
            for path in objs:
                os.remove(path)
            sys.exit(f"ms2symobj: {len(gone)} previously rebound symbols left the symbol tables (e.g. {sorted(gone)[0]}); "
                    f"deleted the game objects, rerun the build")
    for path in objs:
        d = bytearray(open(path, "rb").read())
        st = os.stat(path)
        if d[:4] == b"\0\0\xff\xff":
            symoff, nsyms = struct.unpack_from("<II", d, 48)
            recsz, secbase, secfmt = 20, 56, "<i"
        else:
            symoff, nsyms = struct.unpack_from("<II", d, 8)
            recsz, secbase, secfmt = 18, 20, "<h"
        stroff = symoff + nsyms * recsz
        secsyms = {}          # section number -> [(symbol record offset, name)] of defined external symbols
        i = 0
        while i < nsyms:
            o = symoff + i * recsz
            nm = bytes(d[o:o + 8])
            secnum = struct.unpack_from(secfmt, d, o + 12)[0]
            sclass, naux = d[o + recsz - 2], d[o + recsz - 1]
            if nm[:4] == b"\0\0\0\0":
                so = stroff + struct.unpack_from("<I", nm, 4)[0]
                nm = bytes(d[so:d.index(b"\0", so)])
            else:
                nm = nm.rstrip(b"\0")
            if sclass == 2 and secnum > 0:
                secsyms.setdefault(secnum, []).append((o, nm.decode("latin1")))
            i += 1 + naux
        changed = False
        for secnum, lst in secsyms.items():
            rebound = [(o, nm) for o, nm in lst if nm in names]
            if not rebound:
                continue
            for o, nm in rebound:
                struct.pack_into("<I", d, o + 8, 0)
                struct.pack_into(secfmt, d, o + 12, 0)
                out.append(nm)
            changed = True
            if len(rebound) == len(lst):
                so = secbase + 40 * (secnum - 1) + 36
                ch = struct.unpack_from("<I", d, so)[0]
                if ch & IMAGE_SCN_LNK_COMDAT:
                    struct.pack_into("<I", d, so, ch & ~IMAGE_SCN_LNK_COMDAT)
        if changed:
            tmp = path + ".rb"
            open(tmp, "wb").write(d)
            os.utime(tmp, ns=(st.st_atime_ns, st.st_mtime_ns))   # keep the compile's mtime: ninja's deps log records it, a newer one marks the object dirty (full rebuild every run)
            os.replace(tmp, path)
    return out


def build(syms):
    vas = {}
    for name, (va, kind) in syms.items():
        vas.setdefault((va, kind), []).append(name)
    funcs = sorted(va for va, k in vas if k == "func")
    datas = sorted(va for va, k in vas if k != "func")
    directives = []
    for (va, kind), names in sorted(vas.items()):
        target = f"__ms2fn_{va:x}" if kind == "func" else f"__ms2va_{va:x}"
        for n in sorted(names):
            directives.append(f"/alternatename:{n}={target}")
    drectve = (" " + " ".join(directives) + " ").encode("latin1")

    # sections: 1 = .drectve, 2.. = one COMDAT .text$ms2 per function thunk
    sections = [(".drectve", IMAGE_SCN_LNK_INFO | IMAGE_SCN_LNK_REMOVE | IMAGE_SCN_ALIGN_1BYTES, drectve)]
    for va in funcs:
        sections.append((".text$ms2", IMAGE_SCN_CNT_CODE | IMAGE_SCN_LNK_COMDAT | IMAGE_SCN_ALIGN_2BYTES |
                         IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ, b"\xff\x25\x00\x00\x00\x00" + struct.pack("<Q", va)))

    strtab = bytearray(4)

    def name_field(n):
        b = n.encode("latin1")
        if len(b) <= 8:
            return b.ljust(8, b"\0")
        off = len(strtab)
        strtab.extend(b + b"\0")
        return struct.pack("<II", 0, off)

    # bigobj symbol records are 20 bytes: name[8] value(4) secnum(4) type(2) sclass(1) naux(1)
    symtab = bytearray()
    nsyms = 0

    def sym(n, value, secnum, typ, sclass, aux=None):
        nonlocal nsyms
        symtab.extend(name_field(n) + struct.pack("<IiHBB", value, secnum, typ, sclass, 1 if aux else 0))
        nsyms += 1
        if aux:
            symtab.extend(aux.ljust(20, b"\0"))
            nsyms += 1

    for i, (sname, chars, data) in enumerate(sections, 1):
        if not chars & IMAGE_SCN_LNK_COMDAT:
            continue
        va = funcs[i - 2]
        # section symbol + aux (length, nrelocs, nlines, checksum, number lo, selection=NODUPLICATES, -, number hi)
        sym(sname, 0, i, 0, 3, struct.pack("<IHHIHBBH", len(data), 0, 0, 0, 0, 1, 0, 0))
        sym(f"__ms2fn_{va:x}", 0, i, 0x20, 2)
    for va in datas:
        rel = va - DLL_BASE
        if not 0 <= rel < 1 << 32:
            sys.exit(f"data VA 0x{va:x} out of the absolute-symbol range")
        sym(f"__ms2va_{va:x}", rel, -1, 0, 2)              # IMAGE_SYM_ABSOLUTE

    sec_names = {}
    for sname, _, _ in sections:
        if len(sname) > 8 and sname not in sec_names:
            sec_names[sname] = f"/{len(strtab)}".encode().ljust(8, b"\0")
            strtab.extend(sname.encode() + b"\0")
    nsec = len(sections)
    hdr_size = 56
    sec_hdr = hdr_size
    raw = sec_hdr + 40 * nsec
    out_sec = bytearray()
    body = bytearray()
    for sname, chars, data in sections:
        if len(sname) <= 8:
            out_sec.extend(sname.encode().ljust(8, b"\0"))
        else:
            out_sec.extend(sec_names[sname])
        out_sec.extend(struct.pack("<IIIIIIHHI", 0, 0, len(data), raw + len(body), 0, 0, 0, 0, chars))
        body.extend(data)
        while len(body) % 4:
            body.append(0)
    symoff = raw + len(body)
    struct.pack_into("<I", strtab, 0, len(strtab))
    header = struct.pack("<HHHHI16sIIIIIII", 0, 0xFFFF, 2, 0x8664, 0, BIGOBJ_CLASSID, 0, 0, 0, 0, nsec, symoff,
                         nsyms)
    assert len(header) == hdr_size
    return header + bytes(out_sec) + bytes(body) + bytes(symtab) + bytes(strtab), len(funcs), len(datas), len(syms)


def check(dll, inputs):
    """Post-link check: ImageBase must be DLL_BASE, and no data section may hold an ADDR64 fixup against a __ms2va_
    symbol (the linker stores the raw absolute value VA - DLL_BASE there, a wild pointer at run time)."""
    import pefile
    pe = pefile.PE(dll, fast_load=True)
    bad = 0
    if pe.OPTIONAL_HEADER.ImageBase != DLL_BASE:
        print(f"{dll}: ImageBase 0x{pe.OPTIONAL_HEADER.ImageBase:x}, expected 0x{DLL_BASE:x} (/BASE /FIXED)")
        bad += 1
    rel = {va - DLL_BASE: name for name, (va, kind) in load(inputs).items() if kind != "func"}
    for sec in pe.sections:
        if sec.Characteristics & IMAGE_SCN_CNT_CODE:
            continue
        data = sec.get_data()
        for off in range(0, len(data) - 7, 8):
            v = struct.unpack_from("<Q", data, off)[0]
            if v in rel:
                print(f"{dll}: {sec.Name.rstrip(bytes(1)).decode()}+0x{off:x} holds 0x{v:x} = address of {rel[v]} "
                      f"taken in static data (ADDR64 against an exe global is unsupported: take it at run time)")
                bad += 1
    if bad:
        sys.exit(1)
    print(f"{dll}: ok (base 0x{DLL_BASE:x}, no static pointers to exe globals)")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("inputs", nargs="*", default=DEFAULT_INPUTS)
    ap.add_argument("-o", "--output", default=os.path.join(ROOT, "build", "ms2sym.obj"))
    ap.add_argument("--objs", nargs="+", metavar="OBJ", help="game objects: undefined FUN_<va> externals are auto-bound")
    ap.add_argument("--rebind", action="store_true", help="with --objs: rebind unit-defined mutable data to the exe (hook DLL)")
    ap.add_argument("--rebind-log", metavar="FILE")
    ap.add_argument("--prune", action="store_true",
                    help="with --objs: emit only the symbols the objects reference (same DLL after /OPT:REF, much smaller "
                         "ms2sym.obj and a faster link; for per-unit checks). A symbol referenced by a non-game object "
                         "would fail to link: then do not prune")
    ap.add_argument("--check", metavar="DLL", help="post-link check of the DLL (base, no ADDR64 to exe globals)")
    a = ap.parse_args()
    if a.check:
        return check(a.check, a.inputs)
    syms = load(a.inputs)
    if a.objs and a.rebind:
        rb = rebind_objects(syms, a.objs, a.rebind_log)
        print(f"rebound {len(rb)} data definitions ({len(set(rb))} distinct symbols) to the exe")
        if a.rebind_log:
            open(a.rebind_log, "w").write("\n".join(sorted(set(rb))) + "\n")
    if a.objs:
        nauto = autobind_fun(syms, a.objs)
        print(f"auto-bound {nauto} FUN_<va> externals")
    if a.objs and a.prune:
        want = undefined_externals(a.objs)
        syms = {n: v for n, v in syms.items() if n in want}
    data, nf, nd, ns = build(syms)
    os.makedirs(os.path.dirname(os.path.abspath(a.output)), exist_ok=True)
    tmp = a.output + ".tmp"
    open(tmp, "wb").write(data)
    os.replace(tmp, a.output)
    print(f"{a.output}: {ns} symbols -> {nf} function thunks, {nd} data addresses")


if __name__ == "__main__":
    main()
