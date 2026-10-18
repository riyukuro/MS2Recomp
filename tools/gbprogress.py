#!/usr/bin/env python3
"""Engine stage of tools/progress.py: compile the Gamebryo TUs of engine/units-gb.json, pair every function of their
objs with an exe VA and byte-match it (tools/bytematch.py), credit engine functions in status.tsv.

    .venv/bin/python tools/gbprogress.py [-j 8] [--cache DIR] [filter...]    # standalone: compile + match, print summary

Pairing (per obj function, funclets skipped): the mangled name through progress/symbols{,-engine,-manual}.tsv, else (or
when that pair does not match) the unique exe function of the same length whose bytes equal the obj's with relocations
masked. Functions with several identical exe copies and no name pair are left alone.
Credit (per exe VA, outside the game unit ranges of work/map/units.tsv and not claimed by a game unit row):
  matched     some obj's function is byte-identical (incl. unwind/EH data);
  functional  paired by name or a unique masked hit, but no obj matches exactly;
  stub        an uncredited function between two credited functions of the same unit (the TU's own range; runs of
              more than STUB_GAP functions are not counted).
Unit names: gb:<Lib>/<TU> (one name for both recipes of a TU; an exact v2525 obj wins the attribution over stock).
Cache: <cache>/gb/obj/<recipe>/... (incremental: obj mtime vs source + /showIncludes deps), <cache>/gb/results.json
(per-obj match results keyed by obj mtime/size).
"""
import argparse
import collections
import contextlib
import io
import json
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from multiprocessing import Pool

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import bytematch as bm  # noqa: E402
import ms2paths  # noqa: E402
import gbtree  # noqa: E402

CL = ms2paths.find_cl()
UNITS_TSV = ms2paths.UNITS_TSV
FUNCS = ms2paths.FUNCTIONS_TSV
GB_BAND = (0x141bf0000, 0x142303c10)        # main Gamebryo band (report only)
GB_TAIL = (0x1427b6c90, 0x1428d6000)        # Gamebryo tail: renderer / shader libs (report only)
STUB_GAP = 48                                # longest run of uncredited functions counted as one TU's stubs
KEY = "gb1"                                  # bump to recompile everything


def _safe(name):
    return re.sub(r"[^A-Za-z0-9_.-]+", "__", name)


def obj_path(cache, u):
    return os.path.join(cache, "gb", "obj", u["recipe"], _safe(u["name"]) + ".obj")


def _key(u):
    return KEY + " " + " ".join(u["args"])


def needs_compile(cache, u):
    o = obj_path(cache, u)
    d = o[:-4] + ".deps"
    if not os.path.exists(o) or not os.path.exists(d):
        return True
    try:
        meta = json.load(open(d))
    except Exception:
        return True
    if meta.get("key") != _key(u):
        return True
    t = os.path.getmtime(o)
    for f in [u["source"]] + meta.get("deps", []):
        if not os.path.exists(f) or os.path.getmtime(f) > t:
            return True
    return False


def _real(p):
    p = ms2paths.host_path(p)
    return os.path.realpath(p) if os.path.exists(p) else None


def compile_unit(args):
    cache, u = args
    o = obj_path(cache, u)
    os.makedirs(os.path.dirname(o), exist_ok=True)
    env = ms2paths.toolchain_env()
    cmd = ms2paths.cl_cmdline([CL, "/nologo", "/c"] + u["args"] + ["/showIncludes", "/Fo" + o, u["source"]])
    t0 = time.time()
    r = subprocess.run(cmd, cwd=u["cwd"], capture_output=True, text=True, env=env, encoding="latin1")
    deps, errs = set(), []
    for line in (r.stdout + r.stderr).splitlines():
        if line.startswith("Note: including file:"):
            f = _real(line.split(":", 2)[2])
            if f and f.startswith(ROOT):       # the repo's engine sources (MSVC / SDK headers do not change)
                deps.add(f)
        elif " error " in line or "fatal error" in line:
            errs.append(line.strip())
    ok = r.returncode == 0 and os.path.exists(o)
    if ok:
        json.dump({"key": _key(u), "deps": sorted(deps)}, open(o[:-4] + ".deps", "w"))
    elif os.path.exists(o):
        os.remove(o)
    return ok, errs[:3], time.time() - t0


# ---------------------------------------------------------------------------------------------------------------
# matching (worker processes)

G = {}


def _init():
    exe = bm.Exe(bm.EXE)
    names = {}
    for f in ("symbols-manual.tsv", "symbols.tsv", "symbols-engine.tsv"):
        p = os.path.join(ROOT, "progress", f)
        if not os.path.exists(p):
            continue
        for ln in open(p):
            c = ln.rstrip("\n").split("\t")
            if ln[0] != "#" and len(c) > 1 and (len(c) < 3 or c[2] == "func"):
                names.setdefault(c[0], int(c[1], 16))
    bm.SYMBOLS.clear()
    bm.SYMBOLS.update(names)      # relocation targets resolve through the same tables
    bylen = collections.defaultdict(list)
    for rva, (end, _) in exe.rf.items():
        bylen[end - rva].append(rva)
    G.update(exe=exe, names=names, bylen=bylen)


def _search(obj, si):
    exe = G["exe"]
    data, fields, unw = obj.function(si)
    keep = bytearray(b"\x01") * len(data)
    for off, ln, *_ in fields:
        for k in range(off, min(off + ln, len(data))):
            keep[k] = 0
    idx = [k for k in range(len(data)) if keep[k]]
    want = bytes(data[k] for k in idx)
    hits = []
    for rva in G["bylen"].get(len(data), []):
        img = exe.img[rva:rva + len(data)]
        if bytes(img[k] for k in idx) == want:
            hits.append(rva + exe.base)
    return hits


def _match(obj, n, va):
    with contextlib.redirect_stdout(io.StringIO()):
        try:
            return bool(bm.match_one(obj, n, va, G["exe"], verbose=False, check_unwind=True, quiet=True))
        except Exception:
            return False


def match_obj(path):
    """[(symbol, va, ok, how)] for the obj's functions that pair with an exe VA"""
    out = []
    try:
        obj = bm.Obj(path)
    except Exception:
        return out
    for si in obj.func_symbols():
        n = obj.syms[si][0]
        if n.startswith(bm.FUNCLET_PREFIXES):
            continue
        va = G["names"].get(n)
        ok = False
        how = "name"
        if va is not None:
            ok = _match(obj, n, va)
        if not ok:
            hits = _search(obj, si)
            if len(hits) == 1 and hits[0] != va:
                ok2 = _match(obj, n, hits[0])
                if ok2 or va is None:
                    va, how, ok = hits[0], "search", ok2
            elif len(hits) == 1:
                how = "name"
        if va is None:
            continue
        out.append((n, va, ok, how))
    return out


def _match_job(path):
    return path, match_obj(path)


# ---------------------------------------------------------------------------------------------------------------

def run(cache, j=8, filters=(), log=print):
    """Compile + match every engine unit (those whose name contains one of `filters`); returns (results, failed)."""
    t0 = time.time()
    cache = os.path.abspath(cache)     # v2525 units compile with the tree as cwd
    tree, _ = gbtree.assemble()
    units = gbtree.load_units(tree)
    if filters:
        units = [u for u in units if any(f in u["name"] or f in u["unit"] for f in filters)]
    units = [u for u in units if u["source"]]
    todo = [u for u in units if needs_compile(cache, u)]
    failed = set()
    if todo:
        log(f"engine: compiling {len(todo)} of {len(units)} Gamebryo TU(s) ...")
        with ThreadPoolExecutor(max_workers=max(1, j)) as ex:
            for u, (ok, errs, dt) in zip(todo, ex.map(compile_unit, [(cache, u) for u in todo])):
                if not ok:
                    failed.add(u["name"])
                    log(f"  FAIL {u['recipe']} {u['name']} ({dt:.1f}s)" + "".join("\n      " + e[:300] for e in errs))
    t1 = time.time()
    rpath = os.path.join(cache, "gb", "results.json")
    res = json.load(open(rpath)) if os.path.exists(rpath) else {}
    jobs = []
    for u in units:
        o = obj_path(cache, u)
        if u["name"] in failed or not os.path.exists(o):
            res.pop(u["recipe"] + ":" + u["name"], None)
            continue
        key = [os.path.getmtime(o), os.path.getsize(o)]
        if os.environ.get("MS2_MERGE_INCR"):      # tools/merge.sh: also keyed by the symbol tables the match read
            import mergekey
            key.append(mergekey.engine_stamp())
        c = res.get(u["recipe"] + ":" + u["name"])
        if not c or c.get("key") != key:
            jobs.append((u, o, key))
    if jobs:
        log(f"engine: matching {len(jobs)} obj(s) ...")
        byobj = {o: (u, key) for u, o, key in jobs}
        with Pool(max(1, j), initializer=_init) as p:
            for o, rows in p.imap_unordered(_match_job, [o for _, o, _ in jobs], chunksize=2):
                u, key = byobj[o]
                res[u["recipe"] + ":" + u["name"]] = {"key": key, "unit": u["unit"], "recipe": u["recipe"],
                                                       "pairs": [list(r) for r in rows]}
    live = {u["recipe"] + ":" + u["name"] for u in gbtree.load_units(tree)}
    res = {k: v for k, v in res.items() if k in live}
    os.makedirs(os.path.dirname(rpath), exist_ok=True)
    json.dump(res, open(rpath + ".tmp", "w"))
    os.replace(rpath + ".tmp", rpath)
    log(f"engine: compile {t1 - t0:.0f}s, match {time.time() - t1:.0f}s, {len(failed)} TU(s) failed")
    return res, failed


def load_results(cache):
    rpath = os.path.join(cache, "gb", "results.json")
    return json.load(open(rpath)) if os.path.exists(rpath) else {}


def credit(res, game_rows):
    """status rows for engine functions: [(va, symbol, unit, state, size)]; game_rows: VAs already claimed by game units"""
    starts, info = [], {}
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if not p[0] or p[0].startswith("#"):
            continue
        va = int(p[0], 16)
        info[va] = (int(p[1]), p[3] if len(p) > 3 else "")
        starts.append(va)
    starts.sort()
    game = []
    for line in open(UNITS_TSV):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 2:
            continue
        game.append((int(p[0], 16), int(p[1], 16)))
    game.sort()
    import bisect
    gs = [a for a, _ in game]

    def in_game(va):
        i = bisect.bisect_right(gs, va) - 1
        return i >= 0 and va < game[i][1]
    best = {}      # va -> (rank, symbol, unit)   rank: 3 exact v2525, 2 exact stock, 1 paired
    for k, c in sorted(res.items()):
        for sym, va, ok, how in c["pairs"]:
            if va not in info or va in game_rows or in_game(va):
                continue
            rank = (3 if c["recipe"] == "v2525" else 2) if ok else 1
            if va not in best or rank > best[va][0]:
                best[va] = (rank, sym, c["unit"])
    rows = {va: (sym, unit, "matched" if r >= 2 else "functional") for va, (r, sym, unit) in best.items()}
    # stubs: uncredited functions between two credited functions of the same unit
    cred = sorted(rows)
    for a, b in zip(cred, cred[1:]):
        if rows[a][1] != rows[b][1]:
            continue
        i = bisect.bisect_right(starts, a)
        gap = []
        while i < len(starts) and starts[i] < b:
            v = starts[i]
            if v in game_rows or in_game(v):
                gap = None
                break
            gap.append(v)
            i += 1
            if len(gap) > STUB_GAP:      # a COMDAT placed elsewhere, not the TU's own range
                gap = None
                break
        for v in gap or ():
            rows[v] = (None, rows[a][1], "stub")
    return [(va, sym if sym else info[va][1], unit, st, info[va][0]) for va, (sym, unit, st) in sorted(rows.items())]


def summary(rows):
    """per-lib lines + totals (engine block of summary.txt)"""
    per = collections.defaultdict(lambda: collections.Counter())
    for va, sym, unit, st, size in rows:
        lib = unit[3:].split("/")[0]
        per[lib][st] += 1
        per[lib][st + "_b"] += size
        per[lib]["n"] += 1
        per[lib]["b"] += size
    out = [f"{'engine lib':<45} {'funcs':>6} {'match':>6} {'func.':>6} {'stub':>5} {'bytes':>8} {'matched':>8}  "
           f"{'exact':>6} {'impl.':>6}"]
    tot = collections.Counter()
    for lib in sorted(per, key=lambda k: -per[k]["matched"]):
        c = per[lib]
        tot.update(c)
        out.append(f"{'gb:' + lib:<45} {c['n']:6} {c['matched']:6} {c['functional']:6} {c['stub']:5} {c['b']:8} "
                   f"{c['matched_b']:8}  {100.0 * c['matched_b'] / max(1, c['b']):5.1f}% "
                   f"{100.0 * (c['matched_b'] + c['functional_b']) / max(1, c['b']):5.1f}%")
    out.append(f"{'engine total (' + str(len(per)) + ' libs)':<45} {tot['n']:6} {tot['matched']:6} {tot['functional']:6} "
               f"{tot['stub']:5} {tot['b']:8} {tot['matched_b']:8}")
    starts = {}
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if p[0] and not p[0].startswith("#"):
            starts[int(p[0], 16)] = int(p[1])
    st = {va: s for va, _, _, s, _ in rows}
    for nm, (lo, hi) in (("Gamebryo band", GB_BAND), ("Gamebryo tail", GB_TAIL)):
        vs = [v for v in starts if lo <= v < hi]
        m = sum(1 for v in vs if st.get(v) == "matched")
        f = sum(1 for v in vs if st.get(v) == "functional")
        b = sum(starts[v] for v in vs)
        bm_ = sum(starts[v] for v in vs if st.get(v) == "matched")
        out.append(f"{nm} 0x{lo:x}-0x{hi:x}: {len(vs)} functions; matched {m} ({100.0 * m / max(1, len(vs)):.2f}%), "
                   f"{100.0 * bm_ / max(1, b):.2f}% of bytes; implemented {m + f} ({100.0 * (m + f) / max(1, len(vs)):.2f}%)")
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("filters", nargs="*")
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--cache", default=os.path.join(ROOT, "build", "progress-" + (os.environ.get("MS2_AGENT") or "report")))
    ap.add_argument("--rows", help="write the status rows here (tsv)")
    a = ap.parse_args()
    res, failed = run(a.cache, a.j, a.filters)
    rows = credit(res, set())
    if a.rows:
        with open(a.rows, "w") as fo:
            fo.write("#va\tname\tunit\tstate\tsize\n")
            for va, nm, un, st, sz in rows:
                fo.write(f"{va:x}\t{nm}\t{un}\t{st}\t{sz}\n")
    print("\n".join(summary(rows)))


if __name__ == "__main__":
    main()
