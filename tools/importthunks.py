#!/usr/bin/env python3
"""Import thunks: the 6-byte `jmp qword ptr [__imp_X]` stubs the linker emits for every import that some object calls
without __declspec(dllimport) (a plain `call X` resolved against the import library's short import member). No source
defines them; a link of the objects that call X against X's import library produces exactly this thunk.

    .venv/bin/python tools/importthunks.py [--cache build/progress] [-v]      # report only (prints the summary)

progress.py's imports stage (after the engine stage) turns them into status.tsv rows, unit `imp:<dll>` (lower case):
  matched  the exe function is a real linker thunk: 6 bytes FF 25 <rel32> (functions.tsv size 6), its rel32 lands on an
           IAT slot of the exe's import directory whose DLL is the one functions.tsv names (`<DLL>::<name>`), no other
           thunk jumps through that slot, the slot's import resolves to a symbol (by name, or by ordinal through the
           import library: bytematch.ORDINAL_LIBS), AND some compiled object of the merged tree (game unit objs of the
           cache + objs of the live engine units under <cache>/gb/obj) references that symbol as an undefined external without the
           __imp_ prefix (it calls X the way the original did, so the full link emits this thunk), or references a
           weak alias msvcrt.lib resolves to it (`_setjmp` -> `__intrinsic_setjmp`: crt_aliases), or a static member of
           the CRT/MFC/ATL libs the link pulls in references it that way (static_lib_refs: __scrt_common_main_seh in
           msvcrt.lib's exe_winmain.obj calls _initterm, mfcs140.lib's appmodul.obj calls AfxWinMain ...)
  stub     a verified thunk no object references that way yet (its callers are not recovered, or ours call through
           __imp_X: dllimport declarations, which need no thunk)
Functions named `<DLL>::<name>` that are not such thunks (compiled tail-call wrappers: 48 FF 25 / E9 jumps, 16-aligned)
are left to the units/engine TUs that own them; VAs already claimed by a game or engine row are never touched.
Undefined-external lists are cached per object (path, mtime, size) in <cache>/imports.json, with the object's definitions
of the static lib members' symbols (a symbol the objects define pulls no lib member for it).
MS2_IMP_STATIC_LIBS=0 leaves the static lib members out (only the objects' own references count).
"""
import collections
import json
import os
import struct
import sys
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ms2paths  # noqa: E402

FUNCS = ms2paths.FUNCTIONS_TSV
# import libraries that name the exe's by-ordinal imports for the thunk credit only (in bytematch.ORDINAL_LIBS they would name
# them for every tool, and fullexe/implibs.py would then import them by name): DSOUND.DLL #11 = DirectSoundCreate8
THUNK_ORDINAL_LIBS = [os.path.join(os.path.dirname(os.path.dirname(ms2paths.winsdk_include())), "Lib",
                                   os.path.basename(ms2paths.winsdk_include()), "um", "x64", "dsound.lib")]


# the static (non-import) members of these libs are linked like objects: mfcs140.lib's appmodul.obj (WinMain ->
# AfxWinMain), msvcrt.lib's CRT startup (exe_winmain.obj ...), vcruntime/msvcprt's static parts, atls.lib. Search order =
# afx.h's (mfc140.lib, mfcs140.lib, then msvcrt.lib); the link's entry point seeds the search. The imports of
# STATIC_IMPORTS_FIRST come before them: mfc140.lib exports operator new/delete, so the exe calls MFC140's (thunks
# 0x14274863a ...) and msvcrt.lib's new_scalar.obj/delete_scalar.obj are not linked.
STATIC_IMPORTS_FIRST = [os.path.join("atlmfc", "lib", "x64", "mfc140.lib")]
STATIC_LIBS = [os.path.join("atlmfc", "lib", "x64", "mfcs140.lib"), os.path.join("lib", "x64", "msvcrt.lib"),
               os.path.join("lib", "x64", "vcruntime.lib"), os.path.join("lib", "x64", "msvcprt.lib"),
               os.path.join("atlmfc", "lib", "x64", "atls.lib")]
STATIC_ENTRY = "WinMainCRTStartup"
STATIC_ON = os.environ.get("MS2_IMP_STATIC_LIBS", "1") != "0"


def coff_externals(read, size=None):
    """(undefined, defined) external symbol names of a COFF object; read(offset, n) -> bytes. Short import members and
    anonymous objects other than bigobj give None."""
    h = read(0, 56)
    s1, s2 = struct.unpack_from("<HH", h, 0)
    if s1 == 0 and s2 == 0xFFFF:
        if struct.unpack_from("<H", h, 4)[0] < 2:           # short import member (version 0)
            return None
        symoff, nsym = struct.unpack_from("<II", h, 48)     # ANON_OBJECT_HEADER_BIGOBJ
        sz, secfmt = 20, "<i"
    else:
        symoff, nsym = struct.unpack_from("<II", h, 8)
        sz, secfmt = 18, "<h"
    tab = read(symoff, nsym * sz)
    strsz, = struct.unpack("<I", read(symoff + nsym * sz, 4) or b"\0\0\0\0")
    strs = read(symoff + nsym * sz + 4, max(0, strsz - 4))
    und, dfn, i = set(), set(), 0
    while i < nsym:
        o = i * sz
        val, = struct.unpack_from("<I", tab, o + 8)
        sec, = struct.unpack_from(secfmt, tab, o + 12)
        scl, naux = tab[o + sz - 2], tab[o + sz - 1]
        if scl == 2 and (sec != 0 or val == 0):             # IMAGE_SYM_CLASS_EXTERNAL: defined, or undefined (not common)
            if tab[o:o + 4] == b"\0\0\0\0":
                so, = struct.unpack_from("<I", tab, o + 4)
                so -= 4                                     # string table offsets count its 4-byte size field
                n = strs[so:strs.index(b"\0", so)]
            else:
                n = tab[o:o + 8].rstrip(b"\0")
            (und if sec == 0 else dfn).add(n.decode("latin1"))
        i += 1 + naux
    return und, dfn


def file_externals(path):
    """(undefined, defined) externals of a COFF object file (reads only the header, symbol and string tables)"""
    with open(path, "rb") as f:
        def read(off, n):
            f.seek(off)
            return f.read(n)
        return coff_externals(read)


def undefined_externals(path):
    """names of the undefined external symbols of a COFF object (reads only the symbol and string tables)"""
    return file_externals(path)[0]


def import_lib_symbols(path):
    """the symbols an import library's short import members define (X and __imp_X)"""
    out = set()
    try:
        d = open(path, "rb").read()
    except OSError:
        return out
    o = 8
    while o + 60 <= len(d):
        size = int(d[o + 48:o + 58].split()[0])
        m = d[o + 60:o + 60 + size]
        o += 60 + size + (size & 1)
        if len(m) >= 20 and m[:4] == b"\0\0\xff\xff" and struct.unpack_from("<H", m, 4)[0] == 0:
            sym = m[20:].split(b"\0")[0].decode("latin1")
            out |= {sym, "__imp_" + sym}
    return out


def static_members():
    """[(member name, undefined, defined)] of the static members of STATIC_LIBS, in search order, after one pseudo
    member per STATIC_IMPORTS_FIRST lib that defines its imports (and references nothing); [] when the toolchain is
    absent"""
    out = []
    for rel in STATIC_IMPORTS_FIRST:
        syms = import_lib_symbols(os.path.join(ms2paths.msvc_tools_dir(), rel))
        if syms:
            out.append((os.path.basename(rel) + ":<imports>", set(), syms))
    for rel in STATIC_LIBS:
        try:
            d = open(os.path.join(ms2paths.msvc_tools_dir(), rel), "rb").read()
        except OSError:
            continue
        o, longnames = 8, b""
        while o + 60 <= len(d):
            hdr, size = d[o:o + 16], int(d[o + 48:o + 58].split()[0])
            m = d[o + 60:o + 60 + size]
            o += 60 + size + (size & 1)
            if hdr.startswith(b"// "):
                longnames = m
                continue
            if hdr.startswith(b"/ ") or len(m) < 56:
                continue                                    # linker members
            if hdr[:1] == b"/" and hdr[1:2].isdigit():
                k = int(hdr[1:].split()[0])
                name = longnames[k:].split(b"\0")[0]
            else:
                name = hdr.split(b"/")[0]
            if struct.unpack_from("<H", m, 0)[0] not in (0, 0x8664):
                continue
            r = coff_externals(lambda off, n, m=m: m[off:off + n])
            if r:
                out.append((os.path.basename(rel) + ":" + name.decode("latin1").replace("\\", "/").split("/")[-1],) + r)
    return out if len(out) > len(STATIC_IMPORTS_FIRST) else []


def static_lib_refs(members, undefined, defined, entry=STATIC_ENTRY):
    """{symbol: number of pulled members referencing it undefined}: the static lib members a link of objects with these
    undefined/defined externals pulls in (a member for each still-undefined symbol, the first in search order that defines
    it, until nothing more resolves), starting from the entry point"""
    first = {}
    for k, (_, und, dfn) in enumerate(members):
        for n in dfn:
            first.setdefault(n, k)
    have, need, pulled = set(defined), [n for n in set(undefined) | {entry} if n not in defined], set()
    while need:
        n = need.pop()
        k = first.get(n)
        if k is None or k in pulled or n in have:
            continue
        pulled.add(k)
        have |= members[k][2]
        need += [u for u in members[k][1] if u not in have]
    refs = collections.Counter()
    for k in pulled:
        refs.update(members[k][1])
    return refs, sorted(members[k][0] for k in pulled)


def referenced(objs, cache_path=None, static=None, pulled=None):
    """{symbol: number of objects that reference it undefined}, plus the references of the static lib members the
    objects pull in (static_lib_refs; static=False or MS2_IMP_STATIC_LIBS=0: without them; pulled: a list that gets the
    pulled member names); per-object lists cached by (mtime, size)"""
    if static is None:
        static = STATIC_ON
    members = static_members() if static else []
    lib_defs = set().union(*[m[2] for m in members]) if members else set()
    key = "%08x" % (zlib.crc32("\n".join(sorted(lib_defs)).encode("latin1")) & 0xffffffff)
    old = {}
    if cache_path and os.path.exists(cache_path):
        try:
            old = json.load(open(cache_path))
        except ValueError:
            old = {}
    new, refs, defs = {}, collections.Counter(), set()
    for p in objs:
        try:
            st = os.stat(p)
        except OSError:
            continue
        stamp = [st.st_mtime_ns, st.st_size]
        e = old.get(p)
        if not e or e[0] != stamp or (members and (len(e) < 4 or e[3] != key)):
            try:
                und, dfn = file_externals(p)
            except (OSError, struct.error, ValueError, TypeError):
                continue
            # entry: stamp, undefined externals, definitions of static lib member symbols, the lib symbol set's key
            e = [stamp, sorted(und), sorted(dfn & lib_defs), key] if members else [stamp, sorted(und)]
        new[p] = e
        refs.update(e[1])
        if members:
            defs.update(e[2])
    if cache_path:
        tmp = cache_path + ".tmp"
        json.dump(new, open(tmp, "w"))
        os.replace(tmp, cache_path)
    if members:
        lib_refs, names = static_lib_refs(members, refs, defs)
        refs.update(lib_refs)
        if pulled is not None:
            pulled += names
    return refs


def engine_objs(cache):
    """the objs of the live engine units (data/engine/units-gb.json) in <cache>/gb/obj (stale objs of dropped units are skipped)"""
    import gbprogress
    if not os.path.exists(gbprogress.gbtree.UNITS_JSON):
        return []
    tree, _ = gbprogress.gbtree.assemble()
    return [gbprogress.obj_path(cache, u) for u in gbprogress.gbtree.load_units(tree) if u["source"]]


def cache_objs(cache, game_objs=()):
    """the objects a progress cache links: the given game unit objs + the live engine objs, those that exist"""
    return sorted({p for p in list(game_objs) + engine_objs(cache) if os.path.exists(p)})


def thunks(exe):
    """(verified, rejected): verified = [(va, size, name, dll, symbol or None)], rejected = [(va, name, reason)] for
    every functions.tsv entry named <DLL>::<name>; exe = bytematch.Exe"""
    rows = []
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if len(p) > 3 and p[0] and not p[0].startswith("#") and ".DLL::" in p[3].upper():
            rows.append((int(p[0], 16), int(p[1]), p[3]))
    cand, rejected = [], []
    slots = collections.Counter()
    for va, size, name in rows:
        b = exe.read(va, 6)
        if size != 6 or b[:2] != b"\xff\x25":
            rejected.append((va, name, "not a 6-byte FF 25 thunk (%s, size %d)" % (b.hex(), size)))
            continue
        slot = va + 6 + struct.unpack_from("<i", b, 2)[0]
        if slot not in exe.iat:
            rejected.append((va, name, "jump target 0x%x is not an IAT slot" % slot))
            continue
        dll = exe.iat[slot].split("!")[0]
        if dll.upper() != name.split("::")[0].upper():
            rejected.append((va, name, "IAT slot 0x%x imports %s" % (slot, exe.iat[slot])))
            continue
        sym = exe.imp.get(slot)
        if sym and "?" not in sym and not name.split("::", 1)[1].startswith("Ordinal_") and \
                name.split("::", 1)[1] != sym:
            rejected.append((va, name, "IAT slot 0x%x imports %s" % (slot, exe.iat[slot])))
            continue
        slots[slot] += 1
        cand.append((va, size, name, dll, sym, slot))
    verified = []
    for va, size, name, dll, sym, slot in cand:
        if slots[slot] > 1:
            rejected.append((va, name, "IAT slot 0x%x has %d thunks" % (slot, slots[slot])))
        else:
            verified.append((va, size, name, dll, sym))
    return verified, rejected


def crt_aliases():
    """{target: [alias, ...]} from the weak externals of the CRT import library (msvcrt.lib, the /DEFAULTLIB every obj
    names): an obj calling `_setjmp` links to msvcrt.lib's weak `_setjmp` -> `__intrinsic_setjmp`, so the exe's
    __intrinsic_setjmp thunk is what that call produces. {} when the toolchain is absent."""
    try:
        d = open(os.path.join(ms2paths.msvc_tools_dir(), "lib", "x64", "msvcrt.lib"), "rb").read()
    except OSError:
        return {}
    out, o = collections.defaultdict(list), 8
    while o + 60 <= len(d):
        size = int(d[o + 48:o + 58].split()[0])
        m = d[o + 60:o + 60 + size]
        o += 60 + size + (size & 1)
        if len(m) < 20 or struct.unpack_from("<H", m, 0)[0] not in (0, 0x8664) or m[2:4] == b"\xff\xff":
            continue                                        # alias objs have machine 0; 0000 FFFF: short import
        symoff, nsym = struct.unpack_from("<II", m, 8)
        strs = symoff + 18 * nsym
        if strs > len(m):
            continue

        def name(i):
            raw = m[symoff + 18 * i:symoff + 18 * i + 8]
            if raw[:4] == b"\0\0\0\0":
                so = strs + struct.unpack_from("<I", raw, 4)[0]
                return m[so:m.index(b"\0", so)].decode("latin1")
            return raw.rstrip(b"\0").decode("latin1")
        i = 0
        while i < nsym:
            e = symoff + 18 * i
            scl, naux = m[e + 16], m[e + 17]
            if scl == 105 and naux:                         # IMAGE_SYM_CLASS_WEAK_EXTERNAL: aux TagIndex = target
                out[name(struct.unpack_from("<I", m, e + 18)[0])].append(name(i))
            i += 1 + naux
    return dict(out)


def credit(exe, refs, claimed):
    """status rows [(va, name, unit, state, size)] for the verified thunks whose VA no game/engine row claims"""
    verified, _ = thunks(exe)
    alias = crt_aliases()
    import bytematch as bm
    ords = {}
    for lib in THUNK_ORDINAL_LIBS:
        if os.path.exists(lib):
            ords.update(bm.import_lib_ordinals(lib))
    out = []
    for va, size, name, dll, sym in verified:
        if va in claimed:
            continue
        if not sym and name.split("::", 1)[1].startswith("Ordinal_"):
            sym = ords.get((dll.lower(), int(name.split("::", 1)[1][8:])))
        state = "matched" if sym and any(refs.get(s) for s in [sym] + alias.get(sym, [])) else "stub"
        out.append((va, name, "imp:" + dll.lower(), state, size))
    return out


def summary(rows):
    """per-DLL lines + totals (imports block of summary.txt)"""
    per = collections.defaultdict(collections.Counter)
    for va, name, unit, st, size in rows:
        c = per[unit]
        c[st] += 1
        c[st + "_b"] += size
        c["n"] += 1
        c["b"] += size
    out = [f"{'import thunks (dll)':<45} {'funcs':>6} {'match':>6} {'func.':>6} {'stub':>5} {'bytes':>8} {'matched':>8}"]
    tot = collections.Counter()
    for u in sorted(per, key=lambda k: (-per[k]["n"], k)):
        c = per[u]
        tot.update(c)
        out.append(f"{u:<45} {c['n']:6} {c['matched']:6} {c['functional']:6} {c['stub']:5} {c['b']:8} {c['matched_b']:8}")
    out.append(f"{'imports total (' + str(len(per)) + ' dlls)':<45} {tot['n']:6} {tot['matched']:6} {tot['functional']:6} "
               f"{tot['stub']:5} {tot['b']:8} {tot['matched_b']:8}")
    return out


def main():
    import argparse
    import bytematch as bm
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--cache", default=os.path.join(ROOT, "build", "progress"),
                    help="progress cache whose objs count as references (default build/progress)")
    ap.add_argument("-v", "--verbose", action="store_true", help="list rejected entries and unreferenced thunks")
    ap.add_argument("--no-static", action="store_true", default=not STATIC_ON,
                    help="count only the objects' references (default with MS2_IMP_STATIC_LIBS=0)")
    ap.add_argument("--compare", action="store_true", help="list the thunks whose state the static lib members change")
    a = ap.parse_args()
    exe = bm.Exe(bm.EXE)
    objs = []
    for r, _, fs in os.walk(os.path.join(a.cache, "obj")):
        objs += [os.path.join(r, f) for f in fs if f.endswith(".obj")]
    pulled = []
    refs = referenced(cache_objs(a.cache, objs), static=not a.no_static, pulled=pulled)
    rows = credit(exe, refs, set())
    print("\n".join(summary(rows)))
    if a.compare:
        base = {va: st for va, _, _, st, _ in credit(exe, referenced(cache_objs(a.cache, objs), static=False), set())}
        print(f"static lib members pulled: {len(pulled)}")
        for va, name, unit, st, size in rows:
            if st != base.get(va):
                print(f"{base.get(va)} -> {st} {va:x} {name}")
    if a.verbose:
        for n in pulled:
            print(f"pulled {n}")
        _, rej = thunks(exe)
        for va, name, why in sorted(rej):
            print(f"rejected {va:x} {name}: {why}")
        for va, name, unit, st, size in rows:
            if st == "stub":
                print(f"stub {va:x} {name}")


if __name__ == "__main__":
    main()
