#!/usr/bin/env python3
"""Engine stage of tools/progress.py: compile the Gamebryo TUs of engine/units-gb.json, pair every function of their
objs with an exe VA and byte-match it (tools/bytematch.py), credit engine functions in status.tsv.

    .venv/bin/python tools/gbprogress.py [-j 8] [--cache DIR] [filter...]    # standalone: compile + match, print summary

Pairing (per obj function, funclets skipped): the mangled name through progress/symbols{,-engine,-manual}.tsv, else (or
when that pair does not match) the unique exe function of the same length whose bytes equal the obj's with relocations
masked. Functions with several identical exe copies and no name pair are then paired (2026-10-20, gb5) through an
exact caller's relocation target or a referenced vftable's slot of the same name (kept only if exact), else
(assign_copies, over all objs) one to one with the free copies nearest the obj's own functions (kept only if exact).
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
import hashlib
import io
import json
import os
import re
import struct
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
MATCH_KEY = "callee9"                        # bump to re-match every obj (pairing logic changed)
COPY_ROUNDS = 4                              # assign_copies: offers of an unpaired copy to the next claimant
NO_CALLEE = bool(os.environ.get("MS2_GB_NO_CALLEE"))     # old pairing (no callee pass), for before/after comparisons
if NO_CALLEE:
    MATCH_KEY = "nocallee"


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
    names, dnames = {}, {}
    for f in ("symbols-manual.tsv", "symbols.tsv", "symbols-engine.tsv"):
        p = os.path.join(ROOT, "progress", f)
        if not os.path.exists(p):
            continue
        for ln in open(p):
            c = ln.rstrip("\n").split("\t")
            if ln[0] != "#" and len(c) > 1 and (len(c) < 3 or c[2] == "func"):
                names.setdefault(c[0], int(c[1], 16))
            elif ln[0] != "#" and len(c) > 2 and c[0].startswith("??_7"):
                dnames.setdefault(c[0], int(c[1], 16))
    bm.SYMBOLS.clear()
    bm.SYMBOLS.update(names)      # relocation targets resolve through the same tables
    bylen = collections.defaultdict(list)
    for rva, (end, _) in exe.rf.items():
        bylen[end - rva].append(rva)
    game = []
    for line in open(UNITS_TSV):
        p = line.rstrip("\n").split("\t")
        if not p[0].startswith("#") and len(p) > 1:
            game.append((int(p[0], 16), int(p[1], 16)))
    game.sort()
    G.update(exe=exe, names=names, dnames=dnames, bylen=bylen, game=game, game_lo=[a for a, _ in game])


def _in_game(va):
    import bisect
    i = bisect.bisect_right(G["game_lo"], va) - 1
    return i >= 0 and va < G["game"][i][1]


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
    """([(symbol, va, ok, how)] for the obj's functions that pair with an exe VA, [[symbol, [exe copies]]] of the
    unpaired functions whose bytes several exe functions have, exe VAs of the obj's exact non-template functions)"""
    out = []
    try:
        obj = bm.Obj(path)
    except Exception:
        return out, [], []
    callees, pending = {}, []    # name -> exe VA called/referenced by this obj's exact functions; unpaired functions
    copies = {}                  # unpaired name -> the exe functions whose bytes equal it (relocations masked), if several
    weak = {}                    # name -> its non-exact table-name pair, kept if nothing better turns up
    for si in obj.func_symbols():
        n = obj.syms[si][0]
        if n.startswith(bm.FUNCLET_PREFIXES):
            continue
        va = G["names"].get(n)
        ok = False
        how = "name"
        hits = ()
        if va is not None:
            ok = _match(obj, n, va)
            if ok:
                callees.update(bm.LAST_TARGETS)
        if not ok:
            hits = _search(obj, si)
            if len(hits) > 1:
                eng = tuple(h for h in hits if not _in_game(h))      # game-unit copies are never engine credit
                if eng:
                    copies[n] = eng
            if len(hits) == 1 and hits[0] != va:
                ok2 = _match(obj, n, hits[0])
                if ok2:
                    callees.update(bm.LAST_TARGETS)
                if ok2 or va is None:
                    va, how, ok = hits[0], "search", ok2
            elif len(hits) == 1:
                how = "name"
        if va is None:
            pending.append(n)
            continue
        if not ok and n in copies:       # its table name points at another (game) copy: may still pair below
            weak[n] = (n, va, ok, how)
            pending.append(n)
            continue
        out.append((n, va, ok, how))
    # callee pass: a function with no table name and several byte-identical exe copies (template instantiations for
    # types of the same size, e.g. map<utf8string,__int64> / map<utf8string,unsigned __int64>) is paired with the exe
    # function an exact caller of this obj references under its name, if it then matches exactly; repeated until no
    # new exact match appears
    # vftable pass: a vftable referenced by an exact function (or named in the tables) pairs its slots' functions
    # (destructors, virtuals nobody calls directly) with the exe vftable's slots
    exe = G["exe"]
    vfts = {obj.syms[i][0]: i for i in obj.syms if obj.syms[i][0].startswith("??_7") and obj.syms[i][2] > 0}
    tried = set()
    while (pending or vfts) and not NO_CALLEE:
        grew = False
        for n in list(vfts):
            va = callees.get(n) or G["dnames"].get(n)
            if va is not None:
                for tn, tgt in _vft_slots(obj, vfts.pop(n), va):
                    callees.setdefault(tn, tgt)
                grew = True
        nxt = []
        for n in pending:
            va = callees.get(n)
            if va is None or va - exe.base not in exe.rf or (n, va) in tried:
                nxt.append(n)
                continue
            tried.add((n, va))
            if _match(obj, n, va):          # exact only: the caller itself may be a byte-identical look-alike of
                callees.update(bm.LAST_TARGETS)     # another type, so its reloc targets are only a hint
                out.append((n, va, True, "callee"))
            else:                           # a wrong hint: still unpaired (a copy candidate below)
                nxt.append(n)
        if len(nxt) == len(pending) and not grew:
            break
        pending = nxt
    # the remaining unpaired functions with several byte-identical exe copies are paired by assign_copies (all objs)
    out += [weak[n] for n in pending if n in weak]
    cands = [[n, list(copies[n])] for n in pending if n in copies]
    own = sorted({va for n, va, ok, _ in out if ok and obj.sec(obj.syms[obj.by_name[n]][2]).get("comdat", (0,))[0] != 2})
    return out, cands, own


def _vft_slots(obj, si, va):
    """[(slot symbol, exe target)] of the obj's vftable si placed at exe va (nothing if its unrelocated bytes differ)"""
    exe = G["exe"]
    _, value, secnum = obj.syms[si][:3]
    sec = obj.sec(secnum)
    nxt = [v for (_, v, sn, _, _) in obj.syms.values() if sn == secnum and v > value]
    end = min(nxt) if nxt else sec["size"]
    data = sec["data"][value:end]
    try:
        xb = exe.read(va, len(data))
    except Exception:
        return []
    if len(xb) < len(data):
        return []
    mask = bytearray(len(data))
    out = []
    for r, rsi, ty in sec["relocs"]:
        if not value <= r < end:
            continue
        off = r - value
        for k in range(off, min(off + bm.RELOC_LEN.get(ty, 4), len(data))):
            mask[k] = 1
        if ty == bm.REL_ADDR64 and off + 8 <= len(data):
            out.append((obj.syms[rsi][0], struct.unpack_from("<Q", xb, off)[0] - struct.unpack_from("<q", data, off)[0]))
    if any(not mask[k] and data[k] != xb[k] for k in range(len(data))):
        return []
    return out


def _match_job(path):
    return path, match_obj(path)


def _greedy(todo, xok, match=None):
    """one-to-one pairing of each group's names with its copies, first exact copy wins: [(name, va)]. xok caches
    match results ("name@va" -> bool); without `match` an uncached trial returns None (a worker must run it)"""
    out = []
    for ns, copies in todo:
        used = set()
        for n in ns:
            for v in copies:
                if v in used:
                    continue
                t = f"{n}@{v:x}"
                if t not in xok:
                    if match is None:
                        return None
                    xok[t] = match(n, v)
                if xok[t]:
                    used.add(v)
                    out.append((n, v))
                    break
    return out


def _verify_job(job):
    path, todo, xok = job
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, xok
    _greedy(todo, xok, lambda n, v: _match(obj, n, v))
    return path, xok


def assign_copies(res, cgroups, paths, j, log=print):
    """Pair the objs' unpaired functions that have several byte-identical exe copies (template instantiations of
    same-size types, e.g. map<utf8string,int> / map<utf8string,unsigned int>, kept apart by the linker): every copy no
    obj pairs exactly goes to the claiming obj whose own (non-COMDAT-any) exact functions lie nearest (the TU whose
    instantiation the linker placed there), then each obj pairs its functions one to one with its copies (greedy: the
    first copy that matches exactly; a callee named in the tables tells same-byte copies apart). Writes
    res[key]["xpairs"] (match results cached per obj result in res[key]["xok"])."""
    claimed = {va for c in res.values() for _, va, ok, _ in c["pairs"] if ok}
    groups = collections.defaultdict(list)
    for k, c in res.items():
        for n, gid in c.get("cands", ()):
            if gid in cgroups:
                groups[(k, tuple(cgroups[gid]))].append(n)

    def dist(k, v):
        own = res[k].get("own") or ()
        if own:
            return min(abs(v - a) for a in own)
        ex = [va for _, va, ok, _ in res[k]["pairs"] if ok]
        return (min(abs(v - a) for a in ex) if ex else 1 << 40) + (1 << 32)
    xpairs = collections.defaultdict(list)
    refused = set()       # (va, key): the obj had the copy and none of its names matched it exactly
    for _ in range(COPY_ROUNDS):    # a copy its nearest obj cannot pair goes to the next nearest claimant
        done = {(k, n) for k in xpairs for n, _ in xpairs[k]}
        owner = {}
        for (k, hits), ns in groups.items():
            for v in hits:
                if v in claimed or (v, k) in refused:
                    continue
                d = dist(k, v)
                if v not in owner or (d, k) < owner[v]:
                    owner[v] = (d, k)
        todo = collections.defaultdict(list)
        for (k, hits), ns in groups.items():
            mine = sorted(v for v in hits if v in owner and owner[v][1] == k)
            left = [n for n in ns if (k, n) not in done]
            if mine and left:
                todo[k].append((left, mine))
        if not todo:
            break
        jobs = [(paths[k], prs, res[k].get("xok", {}), k) for k, prs in todo.items()
                if k in paths and _greedy(prs, res[k].get("xok", {})) is None]
        if jobs:
            log(f"engine: pairing byte-identical copies in {len(jobs)} obj(s) ...")
            byp = {p: k for p, _, _, k in jobs}
            with Pool(max(1, j), initializer=_init) as p:
                for path, xok in p.imap_unordered(_verify_job, [(p_, t, x) for p_, t, x, _ in jobs]):
                    res[byp[path]]["xok"] = xok
        grew, r0 = False, len(refused)
        for k, prs in todo.items():
            got = _greedy(prs, res[k].get("xok", {})) or ()
            xpairs[k] += got
            claimed |= {v for _, v in got}
            grew |= bool(got)
            refused |= {(v, k) for _, mine in prs for v in mine if v not in claimed}
        if not grew and len(refused) == r0:
            break
    for k, c in res.items():
        c["xpairs"] = [[n, v, True, "copy"] for n, v in xpairs.get(k, ())]


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
    gpath = os.path.join(cache, "gb", "copygroups.json")      # copy group id -> exe VAs (see assign_copies)
    groups = json.load(open(gpath)) if os.path.exists(gpath) else {}
    jobs = []
    for u in units:
        o = obj_path(cache, u)
        if u["name"] in failed or not os.path.exists(o):
            res.pop(u["recipe"] + ":" + u["name"], None)
            continue
        key = [os.path.getmtime(o), os.path.getsize(o), MATCH_KEY]
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
            for o, (rows, cands, own) in p.imap_unordered(_match_job, [o for _, o, _ in jobs], chunksize=2):
                u, key = byobj[o]
                gc = []
                for n, hits in cands:                  # copy groups are shared by many objs: stored once
                    gid = hashlib.sha1(" ".join("%x" % h for h in hits).encode()).hexdigest()[:16]
                    groups.setdefault(gid, hits)
                    gc.append([n, gid])
                res[u["recipe"] + ":" + u["name"]] = {"key": key, "unit": u["unit"], "recipe": u["recipe"],
                                                       "pairs": [list(r) for r in rows], "cands": gc, "own": own}
    live = {u["recipe"] + ":" + u["name"] for u in gbtree.load_units(tree)}
    res = {k: v for k, v in res.items() if k in live}
    if not NO_CALLEE:
        t2 = time.time()
        allu = gbtree.load_units(tree)
        assign_copies(res, groups, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, j, log)
        used = {g for c in res.values() for _, g in c.get("cands", ())}
        groups = {g: h for g, h in groups.items() if g in used}
        json.dump(groups, open(gpath + ".tmp", "w"))
        os.replace(gpath + ".tmp", gpath)
        log(f"engine: copy pairs {sum(len(c['xpairs']) for c in res.values())} ({time.time() - t2:.0f}s)")
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
    named = set()  # (unit, va) paired through a name table
    for k, c in sorted(res.items()):
        better = {x[0] for x in c.get("xpairs", ())}
        for sym, va, ok, how in c["pairs"] + c.get("xpairs", []):
            if not ok and sym in better:      # a non-exact table-name pair superseded by an exact copy pair
                continue
            if how == "name":
                named.add((c["unit"], va))
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
    _drop_foreign_stubs(rows, starts, named)
    return [(va, sym if sym else info[va][1], unit, st, info[va][0]) for va, (sym, unit, st) in sorted(rows.items())]


FOREIGN_FAR = 0x40000


def _drop_foreign_stubs(rows, starts, named):
    """A TU's code is contiguous: a unit's credited functions linked by stub runs form components. A minor component
    (fewer credited functions than the unit's largest) far from the largest one and without a name-table pair is a
    run of byte-identical copies in another library or TU (a second Lua build, template COMDATs a game TU placed),
    so the functions between them are not this unit's stubs."""
    pos = {v: i for i, v in enumerate(starts)}
    cred = {}
    for va, (sym, unit, st) in rows.items():
        if st != "stub":
            cred.setdefault(unit, []).append(va)
    for unit, cv in cred.items():
        cv.sort()
        comps = [[cv[0]]]
        for a, b in zip(cv, cv[1:]):
            between = starts[pos[a] + 1:pos[b]] if a in pos and b in pos else [None]
            if between and all(v in rows and rows[v][1] == unit and rows[v][2] == "stub" for v in between):
                comps[-1] += between + [b]
            elif not between:
                comps[-1].append(b)
            else:
                comps.append([b])
        if len(comps) < 2:
            continue
        size = [sum(1 for v in c if rows[v][2] != "stub") for c in comps]
        big = max(size)
        lo = min(c[0] for c, n in zip(comps, size) if n == big)
        hi = max(c[-1] for c, n in zip(comps, size) if n == big)
        for c, n in zip(comps, size):
            if n == big or (c[0] < hi + FOREIGN_FAR and c[-1] > lo - FOREIGN_FAR):
                continue
            if any((unit, v) in named for v in c):
                continue
            for v in c:
                if rows[v][2] == "stub":
                    del rows[v]


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
