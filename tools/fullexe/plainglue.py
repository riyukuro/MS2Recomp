#!/usr/bin/env python3
"""Glue files of the plain full-exe build (cmake/fullexe/plain.cmake: one link, no Python at build time).
    plainglue.py write DIR [--rsp FILE] [--cache DIR]
    plainglue.py stubs EXE STUBS_TSV OBJ
    plainglue.py compile DIR [--cache DIR] [--tree CHECKOUT]
  write   from a finished build (FULLEXE_DIR, its closed link link3.rsp; run at each merge, like symbols.tsv) -> DIR/:
            objs.txt   the link's objs in command-line order (plan order with the initorder --before moves applied), as
                       paths relative to the obj cache (--cache, default the first FULLEXE_OBJ_CACHES dir): obj/... gb/obj/...
            alias.rsp  the /alternatename lines the link took (alias.rsp + datapair-alias.rsp after aliasaudit.py)
            order.txt  the /ORDER list (order.py)
            stubs.tsv  the shim's data stubs (symbol, kind, exe va, bytes; shim/stubs.tsv): names and VAs, no exe bytes
          Names, paths and order only: no exe bytes. Stops if the link took a shim stub that is not plain data, since
          `stubs` can only extract plain data.
  stubs   one-shot extraction from the user's exe (like tools/extract_resources.py): the data stubs of STUBS_TSV as a
          COFF obj with the layout shim.py writes (the exe's bytes; keep it out of the repository). It stops on a stub
          that holds a pointer slot (a base relocation), which would need the shim's relocation pass.
  compile the cl command of every obj of DIR/objs.txt, as the finished build ran it (tools/progress.py game units with
          their MS2-FLAGS profile or MS2-TOOLSET cl, tools/gbprogress.py engine and library units), checked against the
          flags key that each obj's .deps recorded -> DIR/:
            compile.tsv  obj, tool (cl = 14.16, else the toolset: vc9 vc9c vc11 1414 1415), cwd, source, flag set
            flags.tsv    flag set number, then one field per cl argument (no /Fo, no /showIncludes)
            tree.tsv     the generated include dirs those commands name: build/gb-tree (gbtree.assemble) and the DirectX
                         overlays build/ms2-engine-dxsdk* (progress.engine_flags): L <path> <symlink target> | F <path> <line>
          Paths carry the prefixes ${TP} (MS2_THIRD_PARTY), ${ENGINE} (MS2_ENGINE_DIR), ${GEN} (<checkout>/build) and
          ${ROOT} (the checkout); the plain build substitutes its own. --tree: the checkout the build compiled (its
          tools/ are imported; default this one); run with that build's MS2_THIRD_PARTY / MS2_ENGINE_DIR."""
import os, shutil, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(1, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

TEXT_EXTRA = ("asm", "shim")       # objs of the link outside the cache: built by plain.cmake itself


def unwine(p):
    return p[2:].replace("\\", "/") if p[:2].lower() == "z:" else p


def write(argv):
    from common import OUT  # noqa: E402
    d = argv[0]
    rsp = argv[argv.index("--rsp") + 1] if "--rsp" in argv else os.path.join(OUT, "link3.rsp")
    caches = [c for c in os.environ.get("FULLEXE_OBJ_CACHES", "").split(":") if c]
    cache = argv[argv.index("--cache") + 1] if "--cache" in argv else (caches[0] if caches else None)
    if not cache:
        sys.exit("write: no obj cache (--cache or FULLEXE_OBJ_CACHES)")
    cache = os.path.realpath(cache) + "/"
    outdir = os.path.realpath(os.path.dirname(rsp)) + "/"
    objs, alias, other = [], [], []
    for line in open(rsp, encoding="latin1").read().splitlines():
        s = line.strip()
        if s.startswith('"/alternatename:'):
            alias.append(line)
        elif s.startswith('"') and s.lower().endswith('.obj"'):
            p = os.path.realpath(unwine(s.strip('"')))
            if p.startswith(cache):
                objs.append(p[len(cache):])
            elif p.startswith(outdir) and p[len(outdir):].split("/")[0] in TEXT_EXTRA:
                other.append(p[len(outdir):])
            else:
                sys.exit("write: obj outside the cache and the build: " + p)
    if not objs:
        sys.exit("write: no cache objs in " + rsp)
    stubs = [l.rstrip("\n").split("\t") for l in open(os.path.join(OUT, "shim", "stubs.tsv"), encoding="latin1")
             if l.strip() and l[0] != "#"]
    bad = [r for r in stubs if r[1] != "data"]
    if bad:
        sys.exit("write: %d shim stub(s) are not plain data (first %s): plainglue.py stubs cannot extract them" % (len(bad), bad[0]))
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "objs.txt"), "w", newline="\n") as f:
        f.write("".join(o + "\n" for o in objs))
    with open(os.path.join(d, "alias.rsp"), "w", encoding="latin1", newline="\n") as f:
        f.write("".join(l + "\n" for l in alias))
    shutil.copyfile(os.path.join(OUT, "order.txt"), os.path.join(d, "order.txt"))
    with open(os.path.join(d, "stubs.tsv"), "w", newline="\n") as f:
        f.write("#symbol\tkind\texe_va\tbytes\n" + "".join("\t".join(r) + "\n" for r in stubs))
    print("%s: objs.txt %d objs (+ %s built by plain.cmake), alias.rsp %d lines, order.txt %d functions, stubs.tsv %d data stub(s)"
          % (d, len(objs), ", ".join(other) or "none", len(alias),
             sum(1 for _ in open(os.path.join(d, "order.txt"), encoding="latin1")), len(stubs)))
    return 0


GEN_TREES = ("gb-tree", "ms2-engine-dxsdk", "ms2-engine-dxsdk-preferred")


def compile_list(argv):
    import json
    if "--tree" in argv:
        sys.path.insert(0, os.path.join(os.path.abspath(argv[argv.index("--tree") + 1]), "tools"))
    import progress
    import gbprogress
    import gbtree
    import ms2paths
    d = argv[0]
    cache = os.path.realpath(argv[argv.index("--cache") + 1] if "--cache" in argv else progress.CACHE)
    if progress.ms2pch.enabled():
        sys.exit("compile: MS2_PCH=1 is not supported (the plain build has no PCH step)")
    root, gen = progress.ROOT, os.path.join(progress.ROOT, "build")
    subs = [(ms2paths.THIRD_PARTY, "${TP}"), (ms2paths.ENGINE_DIR, "${ENGINE}"), (gen, "${GEN}"), (root, "${ROOT}")]

    def tok(a):
        for pre, t in subs:
            i = a.find(pre + "/")
            if i < 0 and a.endswith(pre):
                i = a.find(pre)
            if i >= 0:
                return a[:i] + t + a[i + len(pre):]
        return a
    tree, _ = gbtree.assemble()
    gb = {os.path.relpath(gbprogress.obj_path(cache, u), cache): u for u in gbtree.load_units(tree) if u["source"]}
    rows, bad = [], []
    for o in open(os.path.join(d, "objs.txt")).read().split():
        meta = json.load(open(os.path.join(cache, o[:-4] + ".deps")))
        if o.startswith("gb/"):
            u = gb.get(o)
            if u is None:
                sys.exit("compile: no engine unit for " + o)
            if gbprogress._key(u) != meta.get("key"):
                bad.append(o)
            ts = u.get("toolset") or ms2paths.DEFAULT_TOOLSET
            row = [o, "cl" if ts == ms2paths.DEFAULT_TOOLSET else ts, u["cwd"], u["source"], "/nologo", "/c"] + u["args"]
        else:
            src = os.path.join(progress.GAME, o[len("obj/"):-4] + ".cpp")
            u = progress.Unit(src)
            if u.flags_key() != meta.get("flags"):
                bad.append(o)
            if u.toolset:
                row = [o, u.toolset, root, src] + progress.ms2flags.toolset_flags(u.toolset, u.profile)
            else:
                row = [o, "cl", root, src] + progress.ms2flags.apply(progress.GAME_FLAGS, u.profile)
        rows.append([row[0], row[1]] + [tok(a) for a in row[2:]])
    if bad:
        sys.exit("compile: %d obj(s) were built with other flags than these sources give now (first %s): run it on the "
                 "build's own checkout and environment" % (len(bad), bad[0]))
    semi = [r[0] for r in rows if any(";" in a or "\t" in a for a in r)]
    if semi:
        sys.exit("compile: an argument holds ';' or a tab (%s)" % semi[0])
    left = sorted({a for r in rows for a in r[2:] if root in a or "/mnt/" in a or "/home/" in a})
    if left:
        sys.exit("compile: untokenized absolute path %s" % left[0])
    sets = {}
    for r in rows:
        r[4:] = [str(sets.setdefault(tuple(r[4:]), len(sets)))]
    with open(os.path.join(d, "compile.tsv"), "w", newline="\n") as f:
        f.write("#obj\ttool\tcwd\tsource\tflag set\n" + "".join("\t".join(r) + "\n" for r in rows))
    with open(os.path.join(d, "flags.tsv"), "w", newline="\n") as f:
        f.write("".join("%d\t%s\n" % (i, "\t".join(a)) for a, i in sets.items()))
    ents = []
    for t in GEN_TREES:
        top = os.path.join(gen, t)
        for dp, dn, fn in os.walk(top):
            dn.sort()
            for n in sorted(fn + [x for x in dn if os.path.islink(os.path.join(dp, x))]):
                p = os.path.join(dp, n)
                if n == ".stamp" and dp == top:
                    continue
                if os.path.islink(p):
                    ents.append("L\t%s\t%s" % (tok(p), tok(os.readlink(p))))
                else:
                    txt = open(p, encoding="latin1").read()
                    if "\t" in txt or txt.count("\n") != 1 or not txt.endswith("\n"):
                        sys.exit("compile: %s is not a one-line file" % p)
                    ents.append("F\t%s\t%s" % (tok(p), tok(txt[:-1])))
    with open(os.path.join(d, "tree.tsv"), "w", newline="\n") as f:
        f.write("".join(e + "\n" for e in ents))
    tools = {}
    for r in rows:
        k = r[1] + (" engine" if r[0].startswith("gb/") else "")
        tools[k] = tools.get(k, 0) + 1
    print("%s: compile.tsv %d objs (%s), flags.tsv %d flag sets, tree.tsv %d entries"
          % (d, len(rows), ", ".join("%s %d" % kv for kv in sorted(tools.items())), len(sets), len(ents)))
    return 0


def stubs(argv):
    import pefile
    from shim import BASE, Coff, DATA, RDATA, TEXT
    exe, tsv, obj = argv[:3]
    pe = pefile.PE(exe, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_BASERELOC"]])
    relocs = sorted(BASE + e.rva for b in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", []) for e in b.entries if e.type == 10)
    secs = [(BASE + s.VirtualAddress, BASE + s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData), s) for s in pe.sections]
    co = Coff()
    co.section(".text$mn", TEXT)
    rdata = co.section(".rdata", RDATA)
    data = co.section(".data", DATA)
    co.section(".rdata$str", RDATA)
    co.sym("ms2_fullexe_trap")
    for l in open(tsv, encoding="latin1"):
        if not l.strip() or l[0] == "#":
            continue
        name, kind, va, n = l.rstrip("\n").split("\t")[:4]
        va, n = int(va, 16), int(n)
        s = next((s for lo, hi, s in secs if lo <= va < hi), None)
        if kind != "data" or s is None:
            sys.exit("stubs: %s is not exe data (%s at %x)" % (name, kind, va))
        if any(va <= r < va + n for r in relocs):
            sys.exit("stubs: %s holds a pointer slot (base relocation): needs tools/fullexe/shim.py" % name)
        sec = data if s.Characteristics & 0x80000000 else rdata
        sec.align(16)
        off = len(sec.data)
        b = s.get_data()[va - BASE - s.VirtualAddress:][:n]
        sec.data += b + b"\0" * (n - len(b))
        co.sym(name, sec, off)
    co.write(obj)
    print("%s: %d B .data, %d B .rdata" % (obj, len(data.data), len(rdata.data)))
    return 0


if __name__ == "__main__":
    if len(sys.argv) < 3 or sys.argv[1] not in ("write", "stubs", "compile") or (sys.argv[1] == "stubs" and len(sys.argv) < 5):
        sys.exit(__doc__)
    sys.exit({"write": write, "stubs": stubs, "compile": compile_list}[sys.argv[1]](sys.argv[2:]))
