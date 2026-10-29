#!/usr/bin/env python3
"""Drop the /alternatename lines of an alias rsp that no longer fit the objs being linked:
    aliasaudit.py [--rsp FILE] [--out FILE]   (default: <OUT>/alias.rsp, a report only; --out writes the kept lines)
  gone      the target is not defined by any planned obj (defsyms.tsv) nor named by alias-manual.tsv: renamed, re-typed
            (another mangling) or removed since the line was made
  wrong-va  the name's exe VAs (symbol rows, the FUN_/DAT_ VA in its name, gate pairings) and the target's do not meet
            (and are not byte-identical copies of each other)
  stale     the target has no known VA, but another planned definition is paired with the name's VA
alias.py builds every line from the current tables and objs, so its own output passes; what this catches is lines
carried over from an older run (a merged alias base). link.py --alias runs audit() on alias.rsp before every link and
writes the dropped lines to aliasdrop<TAG>.tsv: a stale line would link the old definition without any error (boot 12s:
GetShadowManager; 12v: FUN_14261e310 bound to a void-returning old copy). Rebuild the aliases each TAG from a no-alias
prelink (link.py --snapshot, analyze.py, alias.py) rather than merging older rsp files."""
import argparse, collections, glob, json, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import SYMBOL_TABLES, ROOT as R, OUT as F, TREE as T, tagged  # noqa: E402

LINE = re.compile(r'/alternatename:([^=]+)=([^"\s]+)', re.I)
PH = re.compile(r"(?:FUN|LAB|DAT|PTR)_(14[0-9a-f]{7})")


def tables():
    """the same sources as alias.py: master's tables first under FULLEXE_FRESH"""
    fresh = os.environ.get("FULLEXE_FRESH") and os.path.realpath(R) != os.path.realpath(T)
    return [R, T] if fresh else [T]


def load():
    sym2va = collections.defaultdict(set)
    for d in tables():
        for t in SYMBOL_TABLES:
            fn = f"{d}/progress/{t}"
            if not os.path.exists(fn):
                continue
            for l in open(fn, encoding="latin1"):
                p = l.rstrip("\n").split("\t")
                if l[0] != "#" and len(p) > 1:
                    try: sym2va[p[0]].add(int(p[1], 16))
                    except ValueError: pass
    for d in tables():
        for rj in (sorted(os.path.join(os.path.abspath(c), "results.json") for c in os.environ["FULLEXE_OBJ_CACHES"].split(":") if c)
                   if os.environ.get("FULLEXE_OBJ_CACHES") else sorted(glob.glob(f"{d}/build/progress*/results.json"))):
            if not os.path.exists(rj):
                continue
            try: res = json.load(open(rj))
            except (OSError, ValueError): continue
            for r in res.values():
                for s, pr in ((r.get("res") or {}).get("pairs") or {}).items():
                    if pr.get("va"): sym2va[s].add(pr["va"])
    gp = os.path.join(F, "gbpairs.tsv")
    if os.path.exists(gp):
        for l in open(gp, encoding="latin1"):
            p = l.rstrip("\n").split("\t")
            if len(p) > 1: sym2va[p[0]].add(int(p[1], 16))
    defs = []
    for l in open(os.path.join(F, "defsyms.tsv"), encoding="latin1"):
        defs.append(l.split("\t", 1)[0].rstrip("\n"))
    manual = set()
    for l in open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "alias-manual.tsv"), encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 1: manual.add(p[1])
    return sym2va, defs, manual


_bm = []


def folded(kx, ky):
    """some VA of the name and some VA of the target are byte-identical exe copies (bytematch.same_code): alias.py pairs a
    FUN_<va> with the definition of an identical copy when the gate paired the definition with another one"""
    if not _bm:
        sys.path.insert(0, os.path.join(R, "tools"))
        import bytematch
        _bm[:] = [bytematch, bytematch.Exe(bytematch.EXE)]
    bm, exe = _bm
    return any(bm.same_code(exe, a, b) for a in kx for b in ky)


def audit(lines):
    """-> (kept lines, [(reason, name, target, detail)])"""
    sym2va, defs, manual = load()
    defined = set(defs)

    def known(s):
        k = set(sym2va.get(s, ()))
        m = PH.search(s)
        if m: k.add(int(m.group(1), 16))
        return k
    va2def = collections.defaultdict(list)
    for s in dict.fromkeys(defs):
        for v in known(s):
            va2def[v].append(s)
    kept, dropped = [], []
    for l in lines:
        m = LINE.search(l)
        if not m:
            kept.append(l)
            continue
        x, y = m.groups()
        kx, ky = known(x), known(y)
        hx = ",".join("%x" % v for v in sorted(kx))
        if y not in defined and y not in manual:
            dropped.append(("gone", x, y, hx))
        elif y not in manual and kx and ky and not (kx & ky) and not folded(kx, ky):
            dropped.append(("wrong-va", x, y, hx + " vs " + ",".join("%x" % v for v in sorted(ky))))
        elif y not in manual and kx and not ky and (better := [d for v in kx for d in va2def.get(v, ()) if d != y]):
            dropped.append(("stale", x, y, hx + " defined by " + better[0]))
        else:
            kept.append(l)
    return kept, dropped


def write_report(dropped, path):
    with open(path, "w") as f:
        f.write("#reason\tname\ttarget\tdetail\n")
        for r in dropped:
            f.write("\t".join(r) + "\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rsp", default=os.path.join(F, "alias.rsp"))
    ap.add_argument("--out")
    a = ap.parse_args()
    kept, dropped = audit(open(a.rsp, encoding="latin1").read().splitlines())
    write_report(dropped, tagged("aliasdrop.tsv"))
    for r in dropped:
        print("\t".join(r))
    c = collections.Counter(r[0] for r in dropped)
    print("%d kept, %d dropped (%s) -> %s" % (sum(1 for l in kept if LINE.search(l)), len(dropped),
          ", ".join("%s %d" % kv for kv in sorted(c.items())) or "none", tagged("aliasdrop.tsv")), file=sys.stderr)
    if a.out:
        open(a.out, "w", encoding="latin1").write("".join(l + "\n" for l in kept))


if __name__ == "__main__":
    main()
