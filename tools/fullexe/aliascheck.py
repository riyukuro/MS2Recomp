#!/usr/bin/env python3
"""Check the picks of an alias rsp against fresh evidence (no stale gate caches):
    aliascheck.py [--rsp FILE] [--tsv OUT] [--all]   (default: <OUT>/alias<TAG>.rsp; FULLEXE_DIR/FULLEXE_TAG as alias.py)
alias.py takes, for an unresolved FUN_<va>, the first definition some build/progress*/results.json pairs with <va>. Every
agent's cache is read, and one whose gate ran before a pin moved still pairs the old symbol with the VA: a code-different
template instance wins (FUN_141c18890 -> Unk_WsTargetF7's RemoveKey instead of m_1a8's RemoveKey<Unk_WsObjectEntry>:
its node dtor released the entity id as a CPtred, HUD portrait AV). Fresh evidence for "<def> is the code at <va>":
  pin       an `MS2-PIN: <def> 0x<va>` line in the current sources
  manual    alias-manual.tsv (it replaces every other claim on its VA)
  symbol    a progress/ symbol-table row
  name      the VA in the definition's own FUN_<va> name
  current   a results.json pairing whose entry describes the current obj (alias.py's FULLEXE_ALIAS_CURRENT rule)
A line is
  mismatch  its target has no fresh claim on the VA, another definition has one (the cache outvoted the sources)
  manual    alias-manual.tsv names another definition for the VA
  cacheonly nothing fresh claims the VA (only stale caches pair it; unverifiable here, not an error)
  callee    its body matches the exe bytes, but a call/reference in it resolves to an exe VA freshly claimed by other
            definitions only (same bytes, another template instance)
  ok        the target has a fresh claim, or its body matches the exe bytes at the VA with agreeing callees
A target that is a byte-identical exe copy's definition (bytematch.same_code of the two VAs) counts as a fresh claim.
Output: one TSV row per non-ok line (kind, unresolved, target, va, fresh claimants with their evidence); exit 1 when
there are mismatch/manual/callee rows. alias.py runs check() on its own picks, replaces such a pick with a freshly claimed
definition at the VA (FULLEXE_ALIAS_STRICT=0: report only) and writes aliascheck<TAG>.tsv."""
import argparse, collections, glob, json, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(1, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from common import SYMBOL_TABLES, ROOT as R, OUT as F, TREE as T, tagged  # noqa: E402

LINE = re.compile(r'/alternatename:([^=]+)=([^"\s]+)', re.I)
PH = re.compile(r"(?:FUN|LAB|DAT|PTR)_(14[0-9a-f]{7})")
PIN = re.compile(r"MS2-PIN: (\S+) 0x([0-9a-fA-F]+)")


def tables():
    fresh = os.environ.get("FULLEXE_FRESH") and os.path.realpath(R) != os.path.realpath(T)
    return [R, T] if fresh else [T]


def obj_path(o):
    """defsyms.tsv's obj column: a <OUT>/obj snapshot name, asm/<obj>, or a path relative to the repo root"""
    up = [os.path.dirname(F), os.path.dirname(os.path.dirname(F)), os.path.dirname(os.path.dirname(os.path.dirname(F)))]
    for d in [os.path.join(F, "obj"), F, R, T] + up:      # a cmake out dir: <tree>/build/fullexe/out, paths from <tree>
        if os.path.exists(os.path.join(d, o)): return os.path.join(d, o)


def name_va(s):
    m = PH.search(s)
    return int(m.group(1), 16) if m else None


def fresh_claims(current_pairs=None):
    """{va: {definition: set(evidence)}} from the sources, symbol tables, alias-manual.tsv and (given) current pairings"""
    claims = collections.defaultdict(lambda: collections.defaultdict(set))
    for d in tables():
        for fn in sorted(glob.glob(f"{d}/src/**/*.cpp", recursive=True) + glob.glob(f"{d}/src/**/*.h", recursive=True)):
            try:
                txt = open(fn, encoding="latin1").read()
            except OSError:
                continue
            if "MS2-PIN: " not in txt:
                continue
            for m in PIN.finditer(txt):
                claims[int(m.group(2), 16)][m.group(1)].add("pin")
        for t in SYMBOL_TABLES:
            fn = f"{d}/progress/{t}"
            if not os.path.exists(fn):
                continue
            for l in open(fn, encoding="latin1"):
                p = l.rstrip("\n").split("\t")
                if l[0] != "#" and len(p) > 1:
                    try: claims[int(p[1], 16)][p[0]].add("symbol")
                    except ValueError: pass
    manual = {}
    for l in open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "alias-manual.tsv"), encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 1:
            manual[int(p[0], 16)] = p[1]
            claims[int(p[0], 16)][p[1]].add("manual")
    for sym, vas in (current_pairs or {}).items():
        for va in vas:
            claims[va][sym].add("current")
    return claims, manual


def current_pairs():
    """the pairings of the results.json entries that describe the current obj (alias.py's `cur`, built by its preamble)"""
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "alias.py")
    src = open(path, encoding="utf-8").read()
    head = src[:src.index("if os.path.exists(f\"{F}/gbpairs.tsv\")")]
    g = {"__file__": path, "__name__": "_alias_cur"}
    exec(compile(head, path, "exec"), g)
    return g["cur"]


_bm = {}
def bytes_evidence(obj, d, va, claims, def_obj=None, depth=6, _seen=None):
    """(match, [callee conflicts]): <d>'s body in <obj> against the exe at <va> (relocation fields masked), then every
    callee/data reference whose exe target another (non-placeholder) definition freshly claims while the callee has no
    claim there: its own body must match the exe at that target too, recursively. A template instance of another type
    has the same bytes and differs only in what it calls, levels down (RemoveKey<F7> and RemoveKey<Unk_WsObjectEntry>
    match 0x141c18890, so do their RemoveAt; the node dtors ~MS2Ptr vs ~SmartPointer do not). ICF folds (BasicStringRef
    and ArgList ctors share 0x1401db760) pass: the callee's body is the exe's."""
    import contextlib, io
    import bytematch as bm
    if "exe" not in _bm:
        _bm["exe"] = bm.Exe(bm.EXE)
        _bm["objs"], _bm["memo"] = {}, {}
    key = (d, va)
    if key in _bm["memo"]:
        return _bm["memo"][key]
    _seen = _seen or set()
    if key in _seen:
        return True, []                     # a cycle (recursion): judged by the levels above
    _seen.add(key)
    try:
        o = _bm["objs"].get(obj) or _bm["objs"].setdefault(obj, bm.Obj(obj))
        with contextlib.redirect_stdout(io.StringIO()):
            ok = bm.match_one(o, d, va, _bm["exe"], False, False, quiet=True)
        tg = dict(bm.LAST_TARGETS)
    except Exception:
        ok, tg = False, {}
    bad = []
    if ok:
        for sname, t in sorted(tg.items()):
            # placeholder names (FUN_/DAT_<va>, Sd_ images) claiming their own VA declare the same thing, not a rival
            rivals = sorted(k for k in claims.get(t, ()) if not PH.search(k) and not k.startswith("?Sd_"))
            if not rivals or sname in claims.get(t, ()) or name_va(sname) == t or sname.startswith("__imp_"):
                continue
            sub = (def_obj or {}).get(sname)
            if sub and depth > 0:
                sok, sbad = bytes_evidence(sub, sname, t, claims, def_obj, depth - 1, _seen)
                if sok and not sbad:
                    continue
                why = "; ".join(sbad) if sbad else "its body differs"
            else:
                why = "depth" if sub else "no obj"
            bad.append(f"{sname} -> 0x{t:x} claimed by {', '.join(rivals)} ({why})")
    _seen.discard(key)
    _bm["memo"][key] = (ok, bad)
    return ok, bad


_same = {}
def same_code(a, b):
    if (a, b) not in _same:
        import bytematch as bm
        if "exe" not in _same:
            _same["exe"] = bm.Exe(bm.EXE)
        try: _same[(a, b)] = bool(bm.same_code(_same["exe"], a, b))
        except Exception: _same[(a, b)] = False
    return _same[(a, b)]


def check(lines, sym2va, claims, manual, defined=None, def_obj=None):
    """[(kind, unresolved, target, va, {claimant: evidence})] for the non-ok alias lines. With def_obj (definition ->
    obj path) a target without a fresh claim is compared with the exe bytes: a match whose callees all agree with the
    fresh claims is ok ("folded": the exe linker folded identical bodies, ICF), one whose callees disagree is a
    mismatch even when nothing else claims the VA"""
    def_vas = collections.defaultdict(set)              # a definition's fresh VAs (for the byte-identical copy rule)
    for va, ds in claims.items():
        for d in ds:
            def_vas[d].add(va)
    out = []
    for l in lines:
        m = LINE.search(l)
        if not m:
            continue
        s, d = m.group(1), m.group(2)
        va = sym2va.get(s, name_va(s))
        if va is None:
            continue
        cl = {k: v for k, v in claims.get(va, {}).items() if defined is None or k in defined or "manual" in v}
        if va in manual and manual[va] != d:
            out.append(("manual", s, d, va, cl))
            continue
        if d in cl or name_va(d) == va:
            continue
        if any(v != va and same_code(v, va) for v in def_vas.get(d, ())):
            continue
        others = {k: v for k, v in cl.items() if k != s}
        if def_obj and def_obj.get(d):
            ok, bad = bytes_evidence(def_obj[d], d, va, claims, def_obj)
            if ok and not bad:
                continue
            if bad:
                out.append(("callee", s, d, va, {**others, **{b: {"callee"} for b in bad}}))
                continue
        out.append(("mismatch" if others else "cacheonly", s, d, va, others))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rsp", default=None)
    ap.add_argument("--tsv", default=None)
    ap.add_argument("--all", action="store_true", help="also list cacheonly rows")
    a = ap.parse_args()
    rsp = a.rsp or tagged("alias.rsp")
    sym2va = {}
    for d in tables():
        for t in SYMBOL_TABLES:
            fn = f"{d}/progress/{t}"
            if os.path.exists(fn):
                for l in open(fn, encoding="latin1"):
                    p = l.rstrip("\n").split("\t")
                    if l[0] != "#" and len(p) > 1:
                        try: sym2va.setdefault(p[0], int(p[1], 16))
                        except ValueError: pass
    claims, manual = fresh_claims(current_pairs())
    defined, def_obj = None, {}
    if os.path.exists(os.path.join(F, "defsyms.tsv")):
        defined = set()
        for l in open(os.path.join(F, "defsyms.tsv"), encoding="latin1"):
            p = l.rstrip("\n").split("\t")
            defined.add(p[0])
            if len(p) > 1 and p[0] not in def_obj:
                def_obj[p[0]] = obj_path(p[1])
    rows = check(open(rsp, encoding="latin1").read().splitlines(), sym2va, claims, manual, defined, def_obj)
    n = collections.Counter(r[0] for r in rows)
    tsv = open(a.tsv, "w") if a.tsv else sys.stdout
    for kind, s, d, va, cl in sorted(rows, key=lambda r: (r[0], r[3])):
        if kind == "cacheonly" and not a.all:
            continue
        tsv.write(f"{kind}\t{va:x}\t{s}\t{d}\t" + "; ".join(f"{k} [{','.join(sorted(v))}]" for k, v in sorted(cl.items())) + "\n")
    print(f"aliascheck {rsp}: {sum(1 for l in open(rsp, encoding='latin1') if LINE.search(l))} lines; "
          + ", ".join(f"{k} {v}" for k, v in sorted(n.items())) or "all ok", file=sys.stderr)
    sys.exit(1 if n["mismatch"] or n["manual"] or n["callee"] else 0)


if __name__ == "__main__":
    main()
