#!/usr/bin/env python3
"""Pins and look-alikes the gates only mention in a unit's notes -> <OUT>/pinreport.txt, one summary line on stdout.
A MS2-PIN outside the unit's MS2-RANGEs or naming no function of the obj is ignored without any error, and a COMDAT that
is byte-identical to several exe copies is owned by name order: both look like a pairing bug at run time (worldservice_4
RemoveAll pin; RemoveAll<SmartPointer<Entity>> vs <Unk_WsPropRef>). FULLEXE_STRICT_PINS=1: exit 1 on a row that tools/fullexe/pins-allow.tsv does not list (see the end of this file).
Also "look-alike order": a unit's instances of one class template (ATL::CAtlList<A>, <B>, ...) that several member families
(AddTail, NewNode, GetFreeNode, ...) pair to the exe in different orders. COMDATs of a family sit in the exe in sorted
mangled-name order of the ORIGINAL type names, so every family must order the instances alike; a family whose order differs
from its siblings and whose pairs came from name order (how auto-order/auto-leaf/auto-guess) is a rotated pin (AddTail,
GetFreeNode, NewNode of unit_141bf99b8). Listed with each family's instances in exe order.
Reads the results.json of FULLEXE_OBJ_CACHES (default: build/progress-<MS2_AGENT>)."""
import collections, json, os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, OUT  # noqa: E402

caches = [c for c in os.environ.get("FULLEXE_OBJ_CACHES", "").split(":") if c] or \
    [os.path.join(ROOT, "build", "progress-" + os.environ.get("MS2_AGENT", "fullexe"))]
KINDS = (("pin outside MS2-RANGEs", lambda n: "outside the unit's MS2-RANGEs" in n),
         ("pin names no function", lambda n: n.startswith("MS2-PIN") and "no such function" in n),
         ("pin already attributed", lambda n: n.startswith("MS2-PIN") and "already attributed" in n),
         ("ambiguous look-alikes", lambda n: n.startswith("ambiguous")))
rows = {k: [] for k, _ in KINDS}
for c in caches:
    rj = os.path.join(c, "results.json")
    if not os.path.exists(rj):
        continue
    for unit, r in sorted(json.load(open(rj)).items()):
        for n in (r.get("res") or {}).get("notes") or []:
            for k, f in KINDS:
                if f(n):
                    rows[k].append(f"{unit}: {n}")
LOOKALIKE_HOW = ("auto-order", "auto-leaf", "auto-guess")


def split_top(d):
    """(class instance, function name, parameter count) of a demangled member function, None for anything else"""
    dep = 0
    for i, ch in enumerate(d):
        dep += (ch == "<") - (ch == ">")
        if ch == "(" and dep == 0:
            break
    else:
        return None
    head, params = d[:i], d[i + 1:]
    dep, cut, last = 0, 0, -1
    for j, ch in enumerate(head):            # return type | qualified name: the last depth-0 space, then the last depth-0 ::
        dep += (ch == "<") - (ch == ">")
        if dep == 0 and ch == " ":
            cut = j + 1
        if dep == 0 and head.startswith("::", j) and j >= cut:
            last = j
    q = head[cut:]
    if last < cut:
        return None
    cls, fn = q[:last - cut], q[last - cut + 2:]
    dep, n = 0, 1
    for ch in params:
        dep += (ch in "<(") - (ch in ">)")
        n += ch == "," and dep == 0
    return cls, fn, n


_exe = []


def calls(va):
    """the exe function at va contains a call (E8) or an indirect call: a byte-identical copy that differs from its look-alikes
    only in callees. Call-free look-alikes (GetCount, get, ...) are interchangeable and a rotation among them is harmless"""
    if not _exe:
        sys.path.insert(0, os.path.join(ROOT, "tools"))
        import bytematch
        _exe[:] = [bytematch, bytematch.Exe(bytematch.EXE)]
    bm, exe = _exe
    sz = bm._fn_size(exe, va)
    body = exe.read(va, sz) if sz else b""
    return b"\xe8" in body or b"\xff\x15" in body or b"\xff\x25" in body


def lookalike_order(results):
    """[(unit, class template, fn, ...)] per unit: the families whose instance order disagrees"""
    out = []
    for unit, r in sorted(results.items()):
        pairs = (r.get("res") or {}).get("pairs") or {}
        names = [n for n in pairs if n.startswith("?") and "@?$" in n]
        if not any(pairs[n]["how"] in LOOKALIKE_HOW for n in names):
            continue
        dm = subprocess.run(["llvm-undname"], input="\n".join(names) + "\n", capture_output=True, text=True).stdout.split("\n")
        dm = [l for l in dm if l.strip()]
        fam = collections.defaultdict(dict)       # (class base, fn, nparams) -> {class instance: (va, how)}
        for n, d in zip(names, dm[1::2] if len(dm) == 2 * len(names) else dm):
            t = split_top(d)
            if t and "<" in t[0]:
                cls, fn, np_ = t
                fam[(cls.split("<")[0], fn, np_)].setdefault(cls, (pairs[n]["va"], pairs[n]["how"]))
        bybase = collections.defaultdict(list)
        for (base, fn, np_), inst in fam.items():
            if len(inst) > 1 and len({v for v, _ in inst.values()}) == len(inst):
                bybase[base].append((fn, np_, [c for c, _ in sorted(inst.items(), key=lambda x: x[1][0])], inst))
        for base, fams in bybase.items():
            nm = [f for f in fams if any(h in LOOKALIKE_HOW for _, h in f[3].values())]
            ev = [f for f in fams if f not in nm]

            def agree(f, g):
                common = set(f[3]) & set(g[3])
                return len(common) < 2 or [c for c in f[2] if c in common] == [c for c in g[2] if c in common]
            # the evidence families (pins, tags, callers) must agree among themselves, else the group is noise
            if len(ev) < 1 or not all(agree(f, g) for i, f in enumerate(ev) for g in ev[i + 1:]):
                continue
            bad = [f for f in nm if not all(agree(f, g) for g in ev) and any(calls(v) for v, _ in f[3].values())]
            if bad:
                lines = [f"{unit}: {base}: name-order family disagrees with the evidence families"]
                for tag, f in [("evidence", g) for g in ev if any(set(g[3]) & set(b[3]) for b in bad)][:2] + [("NAME-ORDER", g) for g in bad]:
                    fn, np_, order, inst = f
                    pre = os.path.commonprefix(order)
                    suf = os.path.commonprefix([c[::-1] for c in order])[::-1]
                    lab = lambda c: c[len(pre):len(c) - len(suf)][:40] or "-"
                    lines.append(f"    {tag} {fn}/{np_}: " + " < ".join(f"{lab(c)}@{inst[c][0]:x}[{inst[c][1]}]" for c in order))
                out.append("\n".join(lines))
    return out


allres = {}
for c in caches:
    rj = os.path.join(c, "results.json")
    if os.path.exists(rj):
        allres.update(json.load(open(rj)))
rows["look-alike order"] = lookalike_order(allres)
REFRESH = "--refresh" in sys.argv
if not REFRESH:
  with open(os.path.join(OUT, "pinreport.txt"), "w") as f:
    for k, v in rows.items():
        f.write(f"## {k}: {len(v)}\n" + "".join(x + "\n" for x in v))
if not REFRESH: print("pinreport: " + ", ".join(f"{len(v)} {k}" for k, v in rows.items()) + f" -> {os.path.join(OUT, 'pinreport.txt')}")

# FULLEXE_STRICT_PINS=1: an ignored pin or a suspect look-alike order that tools/fullexe/pins-allow.tsv does not list fails the
# build (exit 1). The allow-list is the reviewed baseline: "<kind>\t<first line of the row>"; `--write-allow` regenerates it
# (review the diff: a new row is a pin that no longer does anything or a family the gate pairs by name order).
STRICT = ("pin outside MS2-RANGEs", "pin names no function", "pin already attributed", "look-alike order")
ALLOW = os.path.join(os.path.dirname(os.path.abspath(__file__)), "pins-allow.tsv")
keys = [(k, x.split("\n")[0]) for k in STRICT for x in rows[k]]
if REFRESH:
    # --refresh SRC.cpp...: replace the allow-list rows of these units by the rows the committer's own gate results (cache
    # build/progress-$MS2_AGENT or FULLEXE_OBJ_CACHES) give for them. tools/agent-commit.sh runs this for every committed
    # src/ms2/*.cpp so the pins-allow.tsv change lands in the same commit as the source that causes it. A unit the cache has
    # no result for keeps its rows. Exit 0 = nothing to change, 3 = pins-allow.tsv rewritten (stdout: the diff rows).
    # A src/ms2 .h/.hpp argument stands for the units that include it (tools/header-deps.py), so a header-only commit refreshes
    # the units whose pins it can break (a2507100d / 02b827f96). Only units whose cached obj is newer than the header count (an
    # older result predates the edit; its rows are kept and it is named on stderr); more than PINS_HDR_MAX (default 40) dependents
    # of one header: warned and skipped. --dry-run: print the diff rows and exit 3 without writing pins-allow.tsv.
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    srcs = [a for a in args if not a.endswith((".h", ".hpp"))]
    hdrs = [a for a in args if a.endswith((".h", ".hpp"))]
    results = {}
    for c in caches:
        if os.path.exists(os.path.join(c, "results.json")):
            for u, r in json.load(open(os.path.join(c, "results.json"))).items():
                k = r.get("key") or [0]
                results[u.replace("\\", "/")] = max(results.get(u.replace("\\", "/"), 0), k[0] if isinstance(k[0], (int, float)) else 0)
    hmax = int(os.environ.get("PINS_HDR_MAX", "40"))
    for h in hdrs:
        hp = os.path.abspath(h)
        deps = subprocess.run([sys.executable, "-P", os.path.join(ROOT, "tools", "header-deps.py"), os.path.relpath(hp, ROOT)],
                              cwd=ROOT, capture_output=True, text=True)
        if deps.returncode != 0:
            print(f"pinreport: {h}: header-deps failed, its dependents are not refreshed: {deps.stderr.strip()}", file=sys.stderr)
            continue
        dl = [d for d in deps.stdout.split() if d.startswith("src/ms2/") and d.endswith(".cpp")]
        if len(dl) > hmax:
            print(f"pinreport: {h}: {len(dl)} dependent units (> {hmax}), not refreshed; gate and commit them to refresh their rows", file=sys.stderr)
            continue
        hm = os.path.getmtime(hp) if os.path.exists(hp) else 0
        stale = [d for d in dl if results.get(os.path.relpath(os.path.join(ROOT, d), os.path.join(ROOT, "src", "ms2")).replace(os.sep, "/"), 0) < hm]
        if stale:
            print(f"pinreport: {h}: no gate result newer than the header for {len(stale)} dependent unit(s), their rows are kept: " + " ".join(stale), file=sys.stderr)
        srcs += [os.path.join(ROOT, d) for d in dl if d not in stale]
    units = {os.path.relpath(os.path.abspath(a), os.path.join(ROOT, "src", "ms2")).replace(os.sep, "/") for a in srcs}
    units &= set(results)
    old = [tuple(l.rstrip("\n").split("\t", 1)) for l in open(ALLOW)] if os.path.exists(ALLOW) else []
    cur = [kx for kx in keys if kx[1].split(": ", 1)[0].replace("\\", "/") in units]
    keep = [kx for kx in old if kx[1].split(": ", 1)[0].replace("\\", "/") not in units]
    # A refreshed unit's pin row stays while its MS2-PIN line is still in the source: whether the gate reports it can
    # depend on that run (a filtered run attributes other units differently; the full build links master's objs), and
    # dropping a row the full build still reports fails latest.sh (fea63d3b8 questmanager_2, c972fc284 sfr_cri_02). A
    # row the source no longer pins goes. An extra row only loosens the strict check; a missing one breaks the build.
    srcpins = {}
    def pinned(u):
        if u not in srcpins:
            try:
                txt = open(os.path.join(ROOT, "src", "ms2", u), encoding="latin1").read()
            except OSError:
                txt = ""
            srcpins[u] = set(re.findall(r"MS2-PIN:?[ \t]+([^\s:]+)", txt))
        return srcpins[u]
    held = []
    for kx in old:
        u = kx[1].split(": ", 1)[0].replace("\\", "/")
        m = re.search(r"MS2-PIN ([^\s:]+)", kx[1])
        if u in units and kx not in cur and kx[0].startswith("pin ") and m and m.group(1) in pinned(u):
            held.append(kx)
    if held:
        print(f"pinreport: kept {len(held)} pin row(s) the gate did not report whose MS2-PIN is still in the source",
              file=sys.stderr)
    new = sorted(set(keep + cur + held))
    if new != sorted(set(old)):
        for kx in sorted(set(new) - set(old)): print(f"  + [{kx[0]}] {kx[1][:200]}")
        for kx in sorted(set(old) - set(new)): print(f"  - [{kx[0]}] {kx[1][:200]}")
        if "--dry-run" in sys.argv:
            sys.exit(3)
        with open(ALLOW, "w") as f:
            f.write("".join(f"{k}\t{x}\n" for k, x in new))
        sys.exit(3)
elif "--write-allow" in sys.argv:
    with open(ALLOW, "w") as f:
        f.write("".join(f"{k}\t{x}\n" for k, x in sorted(keys)))
    print(f"pinreport: wrote {len(keys)} rows to {ALLOW}")
elif os.environ.get("FULLEXE_STRICT_PINS"):
    allowed = {tuple(l.rstrip("\n").split("\t", 1)) for l in open(ALLOW)} if os.path.exists(ALLOW) else set()
    new = [kx for kx in keys if kx not in allowed]
    if new:
        print(f"pinreport: {len(new)} pin/look-alike row(s) not in {os.path.basename(ALLOW)} (FULLEXE_STRICT_PINS): the committer of the unit refreshes them (tools/agent-commit.sh does it; or `pinreport.py --refresh src/ms2/<unit>.cpp`, `--write-allow` for all)")
        print("".join(f"  [{k}] {x[:220]}\n" for k, x in new[:30]), end="")
        sys.exit(1)
