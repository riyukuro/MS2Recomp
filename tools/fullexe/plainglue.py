#!/usr/bin/env python3
"""Glue files of the plain full-exe build (cmake/fullexe/plain.cmake: one link, no Python at build time).
    plainglue.py write DIR [--rsp FILE] [--cache DIR]
    plainglue.py stubs EXE STUBS_TSV OBJ
    plainglue.py pack DIR
    plainglue.py compile DIR [--cache DIR] [--tree CHECKOUT]
    plainglue.py tables DIR --cache DIR
    plainglue.py facts DIR [--link FILE] [--crtinit FILE] [--tree CHECKOUT]
    plainglue.py derive DIR [--base GLUE] [--committed-tables] [--standalone]
  write   from a finished build (FULLEXE_DIR, its closed link link3.rsp; run at each merge, like symbols.tsv) -> DIR/:
            objs.txt   the link's objs in command-line order (plan order with the initorder --before moves applied), as
                       paths relative to the obj cache (--cache, default the first FULLEXE_OBJ_CACHES dir): obj/... gb/obj/...
            alias.rsp  the /alternatename lines the link took (alias.rsp + datapair-alias.rsp after aliasaudit.py)
            order.txt  the /ORDER list (order.py)
            stubs.tsv  the shim's data stubs (symbol, kind, exe va, bytes; shim/stubs.tsv): names and VAs, no exe bytes
            link.tsv, before.tsv  as `tables` writes them
          Names, paths and order only: no exe bytes. Stops if the link took a shim stub that is not plain data, since
          `stubs` can only extract plain data.
  stubs   one-shot extraction from the user's exe (like tools/extract_resources.py): the data stubs of STUBS_TSV as a
          COFF obj with the layout shim.py writes. It stops on a stub that holds a pointer slot (a base relocation),
          which would need the shim's relocation pass. An obj of zero fill only (a stub in the exe's .bss) holds no
          exe bytes and is committed as data/fullexe/plain/stubs.obj, cmake/fullexe-plain's default; one that holds exe
          bytes stays out of the repository. An empty STUBS_TSV (no stub: every global has a definition) writes no obj
          and removes a stale OBJ; cmake/fullexe-plain then links none.
  pack    DIR/order.txt -> DIR/order.tar.xz (about 1.7 MB; no timestamps or owners, so the same list packs to the same
          bytes): the committed form of order.txt, which cmake/fullexe-plain unpacks into its build dir at configure.
          --standalone: packed without the ms2::hook::detail helper names (as derive --standalone); DIR/order.txt
          is left as it is. glue-refresh.sh passes it.
  compile the cl command of every obj of DIR/objs.txt, as the finished build ran it (tools/progress.py game units with
          their MS2-FLAGS profile or MS2-TOOLSET cl, tools/gbprogress.py engine and library units), checked against the
          flags key that each obj's .deps recorded -> DIR/:
            compile.tsv  obj, tool (cl = 14.16, else the toolset: vc9 vc9c vc11 1414 1415), cwd, source, flag set
            flags.tsv    flag set number, then one field per cl argument (no /Fo, no /showIncludes)
            tree.tsv     the generated include dirs those commands name: build/gb-tree (gbtree.assemble) and the DirectX
                         overlays build/ms2-engine-dxsdk* (progress.engine_flags): L <path> <symlink target> | F <path> <line>
          Paths carry the prefixes ${TP} (MS2_THIRD_PARTY), ${ENGINE} (MS2_ENGINE_DIR), ${GEN} (<checkout>/build) and
          ${ROOT} (the checkout); the plain build substitutes its own. --tree: the checkout the build compiled (its
          tools/ are imported; default this one); run with that build's MS2_THIRD_PARTY / MS2_ENGINE_DIR.
  tables  a finished build's link plan (FULLEXE_DIR) -> DIR/ (facts reads link.tsv; derive reads both only where it cannot
          make them: no status.tsv, as on the published mirror, or --committed-tables):
            link.tsv    plan.py's order.tsv (va, kind, unit, obj relative to the cache --cache): the engine, library and
                        closure objs (gate results and COFF closure) and each game unit's VA, before the --before moves
            before.tsv  initorder.py's --before rules (initorder2.tsv: the exe's static-init order, from its XC table)
  facts   the few link-plan facts derive cannot compute from the repository, from a finished build's link.tsv (--link,
          default DIR/link.tsv; `tables` writes it) and its crtinit2.tsv (--crtinit, default FULLEXE_DIR's) -> DIR/linkfacts.tsv:
            pick     the engine twins (two units-gb.json entries for one unit) linked from the entry that is not the
                     first recipe:name (plan.py takes the one with the most gate pairs, from the gate results)
            va       engine and library units with no progress/status.tsv row, at their gate pairs' lowest exe VA
            closure  the objs with no exe VA that the link pulls in for a symbol nothing else defines (COFF closure over
                     the built objs), in link order
            noinit   units the exe's .CRT$XC table names whose objs register no static initializer (initorder.py's ranking
                     leaves them out; that needs the linked map)
          Then checks that derive's rules give the table's engine, library and closure rows back (exit 3 when not).
          glue-refresh.sh runs it at each refresh; the other link-plan inputs are tracked files derive reads itself.
          --tree: the checkout the build compiled (its tools/ and status.tsv are read; default this one).
  derive  the glue of this checkout from the repository alone (cmake/fullexe-plain MS2_PLAIN_DERIVE runs it at
          configure; no exe, no obj cache, no earlier build) -> DIR/: link.tsv, before.tsv, objs.txt, compile.tsv,
          flags.tsv, tree.tsv, order.txt, alias.rsp, stubs.tsv, stubs.obj. Game units are this checkout's tracked
          src/ms2 sources (MS2-UNIT; NO-EXE place, else the lowest progress/status.tsv VA, else MS2-RANGE; plan.py's
          rules), engine and library units are units-gb.json's (and units-lib-*.json's), sorted as plan.py does, the
          closure objs last: that plan is link.tsv. before.tsv: initorder.py's moves, then applied to give objs.txt.
          order.txt is order.py's list without the defsyms filter (a name no obj defines is LNK4037: the build passes
          /ignore:4037); stubs.obj is stubs.tsv's stubs as zero fill (the exe's .bss), not written (a stale one is
          removed) when stubs.tsv lists no stub.
          --base: the dir with link.tsv, before.tsv, alias.rsp, stubs.tsv (default data/fullexe/plain).
          --standalone: order.txt without the ms2::hook::detail helper names (cmake/fullexe-plain passes it with
          MS2_PLAIN_STANDALONE, where the game units hold no hook code).
          Engine and library units: one entry per unit (the facts' pick, else the first recipe:name) at the unit's lowest
          status.tsv VA, else its facts VA, else left out; the facts' closure objs last. before.tsv: initorder.py's ranking
          of the exe's .CRT$XC entries (data/fullexe/crtinit-exe.tsv, attributed as crtinit.py does: status.tsv row at
          the VA, else the data/map/units.tsv range) over the plan's units less the facts' noinit ones. Needs
          --base's linkfacts.tsv and progress/status.tsv; without either (the published mirror ships no status.tsv), or
          with --committed-tables, --base's link.tsv and before.tsv are read instead (engine units units-gb.json no
          longer has are left out; game units with no status.tsv row take link.tsv's VA)."""
import collections, os, shutil, sys
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
    tables(d, OUT, cache)
    print("%s: objs.txt %d objs (+ %s built by plain.cmake), alias.rsp %d lines, order.txt %d functions, stubs.tsv %d data stub(s)"
          % (d, len(objs), ", ".join(other) or "none", len(alias),
             sum(1 for _ in open(os.path.join(d, "order.txt"), encoding="latin1")), len(stubs)))
    return 0


def tables(d, out, cache):
    """link.tsv (plan.py's order.tsv, objs relative to cache) and before.tsv (initorder.py's rules) of the build in out:
    the exe facts plainglue.py derive takes from the repository"""
    plan = []
    for l in open(os.path.join(out, "order.tsv"), encoding="latin1"):
        if l[0] == "#" or not l.strip():
            continue
        va, kind, unit, o = l.rstrip("\n").split("\t")
        o = os.path.realpath(o)
        if not o.startswith(cache):
            sys.exit("write: order.tsv obj outside the cache: " + o)
        plan.append("\t".join((va, kind, unit, o[len(cache):])))
    with open(os.path.join(d, "link.tsv"), "w", encoding="latin1", newline="\n") as f:
        f.write("#va\tkind\tunit\tobj (plan.py's order.tsv, before the --before moves; obj relative to the cache)\n"
                + "".join(r + "\n" for r in plan))
    with open(os.path.join(d, "before.tsv"), "w", encoding="latin1", newline="\n") as f:
        f.write("# initorder.py's --before rules of that link (unit A moves just before unit B; tools/fullexe/link.py)\n"
                + open(os.path.join(out, "initorder2.tsv"), encoding="latin1").read())
    return 0


def tables_cmd(argv):
    from common import OUT  # noqa: E402
    d = argv[0]
    cache = os.path.realpath(argv[argv.index("--cache") + 1]) + "/"
    os.makedirs(d, exist_ok=True)
    tables(d, OUT, cache)
    print("%s: link.tsv %d objs, before.tsv %d rules" % (d, sum(1 for l in open(os.path.join(d, "link.tsv")) if l[0] != "#"),
                                                       sum(1 for l in open(os.path.join(d, "before.tsv")) if l.strip() and l[0] != "#")))
    return 0


def pack(argv):
    import io, lzma, tarfile
    d = argv[0]
    data = open(os.path.join(d, "order.txt"), "rb").read()
    if "--standalone" in argv:
        # as derive --standalone: the archive is the no-exe build's list, where no obj defines the hook helpers
        ns = HOOK_NS.encode()
        data = b"".join(l for l in data.splitlines(True) if ns not in l)
    ti = tarfile.TarInfo("order.txt")
    ti.size, ti.mode = len(data), 0o644
    buf = io.BytesIO()
    with tarfile.open(fileobj=buf, mode="w", format=tarfile.USTAR_FORMAT) as t:
        t.addfile(ti, io.BytesIO(data))
    with open(os.path.join(d, "order.tar.xz"), "wb") as f:
        f.write(lzma.compress(buf.getvalue(), preset=9))
    print("%s: %d B (order.txt %d B)" % (os.path.join(d, "order.tar.xz"), os.path.getsize(os.path.join(d, "order.tar.xz")), len(data)))
    return 0


GEN_TREES = ("gb-tree", "ms2-engine-dxsdk", "ms2-engine-dxsdk-preferred")


def compile_list(argv):
    if "--tree" in argv:
        sys.path.insert(0, os.path.join(os.path.abspath(argv[argv.index("--tree") + 1]), "tools"))
    import progress
    d = argv[0]
    cache = os.path.realpath(argv[argv.index("--cache") + 1] if "--cache" in argv else progress.CACHE)
    return compile_tables(d, open(os.path.join(d, "objs.txt")).read().split(), cache)


def compile_tables(d, objs, cache=None):
    """compile.tsv, flags.tsv, tree.tsv of objs (cache-relative obj paths) in d; cache: check each obj's .deps flags key
    (the objs of a finished build), None: no check (derive: the commands this checkout gives)"""
    import json
    import progress
    import gbprogress
    import gbtree
    import ms2paths
    if progress.ms2pch.enabled():
        sys.exit("compile: MS2_PCH=1 is not supported (the plain build has no PCH step)")
    root, gen = progress.ROOT, os.path.join(progress.ROOT, "build")
    subs = [(ms2paths.THIRD_PARTY, "${TP}"), (ms2paths.ENGINE_DIR, "${ENGINE}"), (gen, "${GEN}"), (root, "${ROOT}")]

    def tok(a):
        for pre, t in subs:
            i = a.find(pre + "/")
            if i < 0 and os.sep != "/":         # Windows: os.path.join gives a backslash
                i = a.find(pre + os.sep)
            if i < 0 and a.endswith(pre):
                i = a.find(pre)
            if i >= 0:
                return a[:i] + t + a[i + len(pre):]
        return a
    tree, _ = gbtree.assemble()
    gb = {os.path.relpath(gbprogress.obj_path("/c", u), "/c").replace(os.sep, "/"): u for u in gbtree.load_units(tree) if u["source"]}
    rows, bad = [], []
    for o in objs:
        meta = json.load(open(os.path.join(cache, o[:-4] + ".deps"))) if cache else None
        if o.startswith("gb/"):
            u = gb.get(o)
            if u is None:
                sys.exit("compile: no engine unit for " + o)
            if meta is not None and gbprogress._key(u) != meta.get("key"):
                bad.append(o)
            ts = u.get("toolset") or ms2paths.DEFAULT_TOOLSET
            row = [o, "cl" if ts == ms2paths.DEFAULT_TOOLSET else ts, u["cwd"], u["source"], "/nologo", "/c"] + u["args"]
        else:
            src = os.path.join(progress.GAME, o[len("obj/"):-4] + ".cpp")
            u = progress.Unit(src)
            if meta is not None and u.flags_key() != meta.get("flags"):
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
                    t = os.readlink(p)
                    if tok(t) == t and os.path.isabs(t):     # made under another spelling of the same dir (a symlink)
                        dr = os.path.realpath(os.path.dirname(t))
                        for pre, _ in subs:
                            if (dr + "/").startswith(os.path.realpath(pre) + "/"):
                                t = os.path.join(pre, os.path.relpath(dr, os.path.realpath(pre)), os.path.basename(t))
                                break
                    ents.append("L\t%s\t%s" % (tok(p), tok(t)))
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


NM_ZONE = (0x14156a020, 0x14160a7f0)     # plan.py: the Nexon Messenger units stay out (nm_stubs.cpp stands in)
NOVA = 0xFFFFFFFFFF


def before(items, unit, rules):
    """link.py's --before: each rule (A, B) moves A's objs just before B's first obj"""
    for x, y, *_ in rules:
        rest = [r for r in items if unit(r) != x]
        i = next((i for i, r in enumerate(rest) if unit(r) == y), None)
        if i is not None:
            items = rest[:i] + [r for r in items if unit(r) == x] + rest[i:]
    return items


FACTS = "linkfacts.tsv"
FACTS_HEAD = ("# the link-plan facts plainglue.py derive cannot compute from the repository (plainglue.py facts writes them from\n"
              "# a finished cmake/fullexe build at each glue refresh; derive reads them):\n"
              "#   pick     <unit>  <recipe:name>   an engine twin (two units-gb.json entries, one unit) linked from the entry\n"
              "#                                    that is not the default (the first recipe:name): the gate's pair counts chose it\n"
              "#   va       <unit>  <hex va>        an engine or library unit with no progress/status.tsv row, placed at its gate\n"
              "#                                    pairs' lowest exe VA (shared COMDATs that status.tsv credits to another unit)\n"
              "#   closure  <unit>  <kind>  <obj>   an obj with no exe VA that the link pulls in for a symbol nothing else defines\n"
              "#                                    (COFF symbol closure over the built objs), in link order\n"
              "#   noinit   <unit>                  a unit that the exe's .CRT$XC table names but whose objs register no static\n"
              "#                                    initializer of their own (initorder.py leaves it out of the ranking)\n")


def read_facts(path):
    f = {"pick": {}, "va": {}, "closure": [], "noinit": set()}
    for l in open(path, encoding="latin1"):
        if not l.strip() or l[0] == "#":
            continue
        q = l.rstrip("\n").split("\t")
        if q[0] == "pick":
            f["pick"][q[1].lower()] = q[2]
        elif q[0] == "va":
            f["va"][q[1]] = int(q[2], 16)
        elif q[0] == "closure":
            f["closure"].append((q[2], q[1], q[3]))
        elif q[0] == "noinit":
            f["noinit"].add(q[1])
        else:
            sys.exit("%s: unknown row %r" % (path, l))
    return f


def status_rows(root):
    """progress/status.tsv as unit -> [(va, state)] and va -> unit, or None (the published mirror does not ship it)"""
    st = os.path.join(root, "progress", "status.tsv")
    if not os.path.exists(st):
        return None, None
    rows, at = collections.defaultdict(list), {}
    for l in open(st, encoding="latin1"):
        if l[0] != "#":
            q = l.rstrip("\n").split("\t")
            if len(q) > 3:
                rows[q[2]].append((int(q[0], 16), q[3]))
                at[int(q[0], 16)] = q[2]
    return rows, at


def status_low(rows, u):
    """plan.py's low(): the lowest non-stub status.tsv VA of the unit, else its lowest stub VA"""
    v = [va for va, s in rows.get(u, ()) if s != "stub"] or [va for va, s in rows.get(u, ())]
    return min(v) if v else None


def gb_entries(units):
    """units-gb.json entries with a source, grouped as plan.py groups the gate results: unit (lower case) ->
    {recipe:name: (entry, obj relative to the cache)}"""
    import gbprogress
    grp = collections.defaultdict(dict)
    for u in units:
        if u["source"]:
            grp[u["unit"].lower()][u["recipe"] + ":" + u["name"]] = (u, os.path.relpath(gbprogress.obj_path("/c", u), "/c").replace(os.sep, "/"))
    return grp


def engine_plan(grp, rows, facts):
    """plan.py's engine and library rows from units-gb.json, status.tsv and the facts: one entry per unit (the facts'
    pick, else the first recipe:name; plan.py takes the one with the most gate pairs), at the unit's lowest status.tsv
    VA, else its facts VA; a unit with neither is left out unless the facts list it as a closure obj"""
    units_lc = {u.lower(): u for u in rows if u.startswith("gb:")}
    plan, placed = [], set()
    for ul, c in sorted(grp.items()):
        k = facts["pick"].get(ul)
        e, o = c[k if k in c else min(c)]
        u = units_lc.get(ul, e["unit"])
        va = status_low(rows, u)
        if va is None:
            va = facts["va"].get(u)
        if va is not None:
            plan.append((va, "lib" if e["recipe"].startswith("lib-") else "engine", u, o))
            placed.add(o)
    objs = {o for c in grp.values() for _, o in c.values()}
    closure = [(NOVA, kind, u, o) for kind, u, o in facts["closure"] if o in objs and o not in placed]
    return plan, closure


def init_rules(root, at, order, noinit):
    """initorder.py's --before rules without a link: the exe's .CRT$XC entries (data/fullexe/crtinit-exe.tsv) by unit as
    crtinit.py attributes them (status.tsv row at the VA, else the data/map/units.tsv range), ranked by each unit's first
    entry; our side is every unit of the plan the exe table names, less the facts' noinit units"""
    import bisect
    from initorder import before_rules
    xc = []
    for l in open(os.path.join(root, "data", "fullexe", "crtinit-exe.tsv")):
        if l.strip() and l[0] != "#":
            t, i, va = l.split()[:3]
            if t == "XC":
                assert int(i) == len(xc), l
                xc.append(int(va, 16))
    ur = sorted((int(p[0], 16), int(p[1], 16), p[2]) for p in (l.split("\t") for l in open(os.path.join(root, "data", "map", "units.tsv")))
                if p[0] and p[0][0] != "#" and len(p) > 2)
    starts = [u[0] for u in ur]
    first_e = {}
    for i, va in enumerate(xc):
        u = at.get(va)
        if u is None:
            j = bisect.bisect_right(starts, va) - 1
            u = ur[j][2] if j >= 0 and va < ur[j][1] else "?"
        if u != "?":
            first_e.setdefault(u, i)
    pos = {}
    for i, u in enumerate(order):
        pos.setdefault(u, i)
    shared = sorted((u for u in first_e if u in pos and u not in noinit), key=lambda u: pos[u])
    return before_rules(shared, first_e)[0]


def write_tables(d, plan, rules):
    """link.tsv and before.tsv as `tables` writes them from a build"""
    with open(os.path.join(d, "link.tsv"), "w", encoding="latin1", newline="\n") as f:
        f.write("#va\tkind\tunit\tobj (plan.py's order.tsv, before the --before moves; obj relative to the cache)\n"
                + "".join("%x\t%s\t%s\t%s\n" % r for r in plan))
    with open(os.path.join(d, "before.tsv"), "w", encoding="latin1", newline="\n") as f:
        f.write("# initorder.py's --before rules of that link (unit A moves just before unit B; tools/fullexe/link.py)\n"
                + "\n".join(rules) + "\n")


def facts(argv):
    """DIR/link.tsv (a build's plan, `tables`) + its crtinit tsv -> DIR/linkfacts.tsv: what derive cannot
    compute; then checks that derive's rules give that build's engine, library and closure rows back"""
    if "--tree" in argv:
        sys.path.insert(0, os.path.join(os.path.abspath(argv[argv.index("--tree") + 1]), "tools"))
    import progress
    import gbtree
    d = argv[0]
    link = argv[argv.index("--link") + 1] if "--link" in argv else os.path.join(d, "link.tsv")
    if "--crtinit" in argv:
        crt = argv[argv.index("--crtinit") + 1]
    else:
        from common import OUT
        crt = os.path.join(OUT, "crtinit2.tsv")
    root = progress.ROOT
    rows, at = status_rows(root)
    if rows is None:
        sys.exit("facts: no progress/status.tsv in " + root)
    table = [l.rstrip("\n").split("\t") for l in open(link, encoding="latin1") if l.strip() and l[0] != "#"]
    tree, _ = gbtree.assemble()
    grp = gb_entries(gbtree.load_units(tree))
    byobj = {o: (ul, k) for ul, c in grp.items() for k, (_, o) in c.items()}
    out, bad = [], 0
    for va, kind, u, o in table:
        if kind in ("game", "scaleform"):
            continue
        if kind.endswith("-closure"):
            out.append("closure\t%s\t%s\t%s" % (u, kind, o))
            continue
        if o not in byobj:
            sys.exit("facts: %s (%s) is no units-gb.json entry with a source" % (o, u))
        ul, k = byobj[o]
        if k != min(grp[ul]):
            out.append("pick\t%s\t%s" % (u, k))
        lv = status_low(rows, u)
        if lv is None:
            out.append("va\t%s\t%s" % (u, va))
        elif lv != int(va, 16):
            bad += 1
            print("facts: %s at %s, status.tsv's lowest VA %x" % (u, va, lv), file=sys.stderr)
    # noinit: units of the plan in the exe's XC table with no XC entry of ours (crtinit.py's attribution of both sides)
    exe_u, ours = set(), set()
    for l in open(crt, encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if l[0] == "#" or p[1] != "XC" or p[4] == "?":
            continue
        if p[0] == "exe":
            exe_u.add(p[4])
        elif "ms2_registered_" not in p[5]:
            ours.add(p[4])
    inplan = {r[2] for r in table}
    out += ["noinit\t%s" % u for u in sorted(exe_u & inplan - ours)]
    order = {"pick": 0, "va": 1, "closure": 2, "noinit": 3}
    out.sort(key=lambda r: (order[r.split("\t")[0]], r) if not r.startswith("closure") else (2, ""))
    with open(os.path.join(d, FACTS), "w", encoding="latin1", newline="\n") as f:
        f.write(FACTS_HEAD + "".join(r + "\n" for r in out))
    # check: the engine, library and closure rows derive --tables makes from these facts
    fx = read_facts(os.path.join(d, FACTS))
    plan, closure = engine_plan(grp, rows, fx)
    got = sorted(plan) + closure
    want = [(int(va, 16), kind, u, o) for va, kind, u, o in table if kind not in ("game", "scaleform")]
    want = sorted(r for r in want if not r[1].endswith("-closure")) + [r for r in want if r[1].endswith("-closure")]
    diff = [r for r in got if r not in want] + [r for r in want if r not in got]
    print("%s: %s; derived engine/library/closure rows %s the table's (%d rows)%s" % (
        os.path.join(d, FACTS), ", ".join("%s %d" % kv for kv in sorted(collections.Counter(r.split("\t")[0] for r in out).items())),
        "equal" if got == want else "DIFFER from", len(want), ", %d row(s) off status.tsv's VA" % bad if bad else ""))
    for r in diff[:20]:
        print("  %s %x %s %s %s" % ("derived" if r in got else "table  ", *r), file=sys.stderr)
    return 0 if got == want and not bad else 3


HOOK_NS = "@detail@hook@ms2@@"     # mangled scope of src/hook/ms2hook.h's helper templates


def derive(argv):
    """the glue of this checkout from the repository alone -> DIR (see the module doc)"""
    import re, subprocess
    import progress
    import gbprogress
    import gbtree
    import ms2paths
    from common import SYMBOL_TABLES
    d = argv[0]
    base = os.path.abspath(argv[argv.index("--base") + 1]) if "--base" in argv else os.path.join(progress.ROOT, "data", "fullexe", "plain")
    root = progress.ROOT
    rows, at = status_rows(root)
    # link.tsv and before.tsv made here from status.tsv, units-gb.json, crtinit-exe.tsv, data/map/units.tsv and the facts
    # list; without status.tsv (the published mirror does not ship it) or the facts, the committed ones are read
    made = "--committed-tables" not in argv and rows is not None and os.path.exists(os.path.join(base, FACTS))
    if not made and "--committed-tables" not in argv:
        print("derive: no %s: reading %s's link.tsv and before.tsv" % ("progress/status.tsv" if rows is None else FACTS, base),
              file=sys.stderr)
    if made:
        fx = read_facts(os.path.join(base, FACTS))
        table, rules, tvas = [], None, {}
    else:
        # the committed plan of the last refresh: engine and library objs (gate results) and the closure, game VAs as fallback
        table = [l.rstrip("\n").split("\t") for l in open(os.path.join(base, "link.tsv"), encoding="latin1") if l.strip() and l[0] != "#"]
        rules = [p for l in open(os.path.join(base, "before.tsv"), encoding="latin1")
                 if len(p := l.split("#")[0].rstrip().split("\t")) >= 2]
        tvas = {u: int(va, 16) for va, kind, u, o in table if kind in ("game", "scaleform")}
    rows = rows or {}       # not on the published mirror: the table's VA, then MS2-RANGE

    def low(u):
        v = status_low(rows, u)
        return v if v is not None else tvas.get(u)
    try:
        r = subprocess.run(["git", "-C", root, "ls-files", "-z", "--recurse-submodules", "--", "src/ms2"], capture_output=True, text=True)
    except OSError:     # no git on PATH (a source tarball on Windows): walk the tree below
        r = None
    if r is not None and r.returncode == 0:
        srcs = sorted(os.path.relpath(f, "src/ms2").replace(os.sep, "/") for f in r.stdout.split("\0") if f.endswith(".cpp"))
    else:           # a source tarball: every .cpp
        srcs = sorted(os.path.relpath(os.path.join(dp, f), progress.GAME).replace(os.sep, "/")
                      for dp, _, fs in os.walk(progress.GAME) for f in fs if f.endswith(".cpp"))
    plan, skipped = [], collections.Counter()
    for rel in srcs:
        name, rng, place = None, [], None
        for line in open(os.path.join(progress.GAME, rel), encoding="latin1"):
            if "MS2-" not in line:
                continue
            m = re.match(r"\s*//\s*MS2-UNIT:\s*(\S+)", line)
            if m:
                name = m.group(1)
            m = re.match(r"\s*//\s*MS2-RANGE:\s*0x([0-9a-fA-F]+)", line)
            if m:
                rng.append(int(m.group(1), 16))
            m = re.match(r"\s*//\s*MS2-NO-EXE:\s*0x([0-9a-fA-F]+)", line)
            if m:
                place = int(m.group(1), 16)
        if not name:
            continue
        va = place if place is not None else low(name)
        if va is None and rng:
            va = min(rng)
        if place is None and va is not None and NM_ZONE[0] <= va < NM_ZONE[1]:
            skipped["NM zone"] += 1
            continue
        if va is None:
            skipped["game no address"] += 1
            continue
        plan.append((va, "scaleform" if rel.startswith("scaleform/") else "game", name, "obj/" + rel[:-4] + ".obj"))
    tree, _ = gbtree.assemble()
    units = gbtree.load_units(tree)
    gb = {os.path.relpath(gbprogress.obj_path("/c", u), "/c").replace(os.sep, "/") for u in units if u["source"]}
    closure = []
    if made:
        eng, closure = engine_plan(gb_entries(units), rows, fx)
        plan += eng
    for va, kind, u, o in table:
        if kind in ("game", "scaleform"):
            continue
        if o not in gb:
            skipped["engine unit gone"] += 1
            print("derive: %s (%s) is no engine unit of this checkout: left out" % (o, u), file=sys.stderr)
            continue
        (closure if kind.endswith("-closure") else plan).append((int(va, 16), kind, u, o))
    plan.sort()
    plan += closure
    os.makedirs(d, exist_ok=True)
    if made:
        rules = init_rules(root, at, [u for _, _, u, _ in plan], fx["noinit"])
        write_tables(d, plan, rules)
        rules = [p for r in rules if len(p := r.split("#")[0].rstrip().split("\t")) >= 2]
    plan = before(plan, lambda x: x[2], rules)
    objs = [o for _, _, _, o in plan]
    if len(set(objs)) != len(objs):
        sys.exit("derive: an obj twice in the plan")
    with open(os.path.join(d, "objs.txt"), "w", newline="\n") as f:
        f.write("".join(o + "\n" for o in objs))
    shutil.copyfile(os.path.join(base, "alias.rsp"), os.path.join(d, "alias.rsp"))
    shutil.copyfile(os.path.join(base, "stubs.tsv"), os.path.join(d, "stubs.tsv"))
    zero_stubs(os.path.join(base, "stubs.tsv"), os.path.join(d, "stubs.obj"))   # none: no stubs.obj
    # order.txt: order.py without its defsyms filter (that needs the objs): a name no obj defines is LNK4037 only.
    # --standalone (the game units compile with /DMS2_STANDALONE): the ms2::hook::detail helpers of the registrations
    # (FnToVoid, ArgPass::Get) are left out; no obj defines them there, and the symbol tables list them because a gate
    # obj's copy has the bytes of an exe function
    nohook = "--standalone" in argv
    fva = set()
    for l in open(ms2paths.FUNCTIONS_TSV):
        q = l.split("\t")
        if q[0] and q[0][0] != "#":
            try:
                fva.add(int(q[0], 16))
            except ValueError:
                pass
    va = {}
    for fn in SYMBOL_TABLES:
        for l in open(os.path.join(root, "progress", fn), encoding="latin1"):
            q = l.rstrip("\n").split("\t")
            if l[0] != "#" and len(q) > 1 and q[0] not in va and not (nohook and HOOK_NS in q[0]):
                try:
                    v = int(q[1], 16)
                except ValueError:
                    continue
                if v in fva:
                    va[q[0]] = v
    with open(os.path.join(d, "order.txt"), "w", encoding="latin1", newline="\n") as f:
        f.write("".join(n + "\n" for n, _ in sorted(va.items(), key=lambda x: (x[1], x[0]))))
    print("%s: objs.txt %d objs (%s), order.txt %d functions%s; %s" % (
        d, len(objs), ", ".join("%s %d" % kv for kv in sorted(collections.Counter(k for _, k, _, _ in plan).items())),
        len(va), ", link.tsv and before.tsv (%d rules) made from %s" % (len(rules), FACTS) if made else "", dict(skipped)))
    return compile_tables(d, objs)


def stub_rows(tsv):
    """stubs.tsv's stub rows (symbol, kind, exe va, bytes, ...), comments and blank lines left out"""
    return [l.rstrip("\n").split("\t") for l in open(tsv, encoding="latin1") if l.strip() and l[0] != "#"]


def no_stub_obj(tsv, obj):
    """True when stubs.tsv lists no stub: then there is no stub obj to write (a stale one is removed)"""
    if stub_rows(tsv):
        return False
    if os.path.exists(obj):
        os.remove(obj)
    return True


def zero_stubs(tsv, obj):
    """stubs.tsv -> the data-stub obj with the layout shim.py writes, zero fill (the stubs lie in the exe's .bss;
    plainglue.py stubs checks that against the exe at each refresh). No stub: no obj."""
    if no_stub_obj(tsv, obj):
        return
    from shim import Coff, DATA, RDATA, TEXT
    co = Coff()
    co.section(".text$mn", TEXT)
    co.section(".rdata", RDATA)
    data = co.section(".data", DATA)
    co.section(".rdata$str", RDATA)
    co.sym("ms2_fullexe_trap")
    for l in open(tsv, encoding="latin1"):
        if not l.strip() or l[0] == "#":
            continue
        name, kind, va, n = l.rstrip("\n").split("\t")[:4]
        if kind != "data":
            sys.exit("stubs: %s is not plain data" % name)
        data.align(16)
        off = len(data.data)
        data.data += b"\0" * int(n)
        co.sym(name, data, off)
    co.write(obj)


def stubs(argv):
    exe, tsv, obj = argv[:3]
    if no_stub_obj(tsv, obj):
        print("%s: no stub, no obj (cmake/fullexe-plain links none)" % tsv)
        return 0
    import pefile
    from shim import BASE, Coff, DATA, RDATA, TEXT
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
    held = []
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
        if b.strip(b"\0"):
            held.append(name)
    co.write(obj)
    print("%s: %d B .data, %d B .rdata, %s" % (obj, len(data.data), len(rdata.data),
                                             "exe bytes in " + " ".join(held) if held else "zero fill only (no exe bytes)"))
    return 0


if __name__ == "__main__":
    cmds = {"write": write, "stubs": stubs, "pack": pack, "compile": compile_list, "derive": derive, "tables": tables_cmd,
            "facts": facts}
    if len(sys.argv) < 3 or sys.argv[1] not in cmds or (sys.argv[1] == "stubs" and len(sys.argv) < 5):
        sys.exit(__doc__)
    sys.exit(cmds[sys.argv[1]](sys.argv[2:]))
