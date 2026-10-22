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
VA windows (engine/unit-windows.tsv, 2026-10-20 lb2): a unit-name prefix pairs only inside (include) or outside
(exclude) VA ranges (pairing, not just credit: name, search and callee pairs), for a library the exe links twice
(Gamebryo's LNUM Lua gb:Lua/ and the stock Lua 5.1.4 gb:Lua2/, mostly byte-identical); part of the match cache key.
Cache: <cache>/gb/obj/<recipe>/... (incremental: obj mtime vs source + /showIncludes deps), <cache>/gb/results.json
(per-obj match results keyed by obj mtime/size).
"""
import argparse
import bisect
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
MATCH_KEY = "callee-dup"                        # bump to re-match every obj (pairing logic changed)
if bm.CHAIN:
    MATCH_KEY += "-chain"
LEAF_SMALL, LEAF_NEAR = 16, 0x10000             # assign_copies: small leaf copies only this near the obj's own functions
STATIC_NEAR = 0x10000                           # match_obj: a COMDAT caller's static callee only this near the obj's own code
COPY_ROUNDS = 8                              # assign_copies: offers of an unpaired copy to the next claimant
LIB_RECIPE = "/obj/lib-"                         # obj path part of the library units' recipes (lib-cef, ...)
NO_CALLEE = bool(os.environ.get("MS2_GB_NO_CALLEE"))     # old pairing (no callee pass), for before/after comparisons
if NO_CALLEE:
    MATCH_KEY = "nocallee"


def _safe(name):
    return re.sub(r"[^A-Za-z0-9_.-]+", "__", name)


def obj_path(cache, u):
    return os.path.join(cache, "gb", "obj", u["recipe"], _safe(u["name"]) + ".obj")


def _key(u):
    ts = u.get("toolset", ms2paths.DEFAULT_TOOLSET)       # default toolset keeps the old key (no rebuild)
    return KEY + (" toolset=" + ts if ts != ms2paths.DEFAULT_TOOLSET else "") + " " + " ".join(u["args"])


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
    cl = ms2paths.find_cl_toolset(u.get("toolset"))
    cmd = ms2paths.cl_cmdline([cl, "/nologo", "/c"] + u["args"] + ["/showIncludes", "/Fo" + o, u["source"]])
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


WINDOWS_TSV = os.path.join(ROOT, "engine", "unit-windows.tsv")


def load_windows():
    """[(unit prefix, include|exclude, lo, hi)] from engine/unit-windows.tsv"""
    out = []
    if os.path.exists(WINDOWS_TSV):
        for ln in open(WINDOWS_TSV):
            c = ln.split("#")[0].split()
            if len(c) >= 4:
                out.append((c[0], c[1], int(c[2], 16), int(c[3], 16)))
    return out


def unit_window(unit, windows):
    """(include ranges or None, exclude ranges) of a unit name"""
    rg = lambda kind: [(lo, hi) for p, k, lo, hi in windows if k == kind and unit.startswith(p)]
    return (rg("include") or None, rg("exclude"))


def _allowed(va):
    inc, exc = G.get("win") or (None, [])
    return va is None or ((inc is None or any(lo <= va < hi for lo, hi in inc)) and
                          not any(lo <= va < hi for lo, hi in exc))


def _is_text(va):
    exe = G["exe"]
    return any(sec.Name.rstrip(b"\0") == b".text" and sec.VirtualAddress <= va - exe.base < sec.VirtualAddress
               + sec.Misc_VirtualSize for sec in exe.pe.sections)


def _init():
    exe = bm.Exe(bm.EXE)
    names, dnames = {}, {}
    for f in ("symbols-manual.tsv", "symbols.tsv", "symbols-engine.tsv", "symbols-engine-manual.tsv"):
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
        if bm.CHAIN and rva in exe._chained:
            continue
        bylen[exe.chain_end(rva) - rva].append(rva)
    # leaf functions (no stack frame, no calls) have no .pdata entry: their length comes from the function map
    leaf = set()
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if p[0] and not p[0].startswith("#"):
            rva = int(p[0], 16) - exe.base
            if rva not in exe.rf and int(p[1]) > 0:
                bylen[int(p[1])].append(rva)
                leaf.add(rva)
    game = game_ranges()
    G.update(exe=exe, names=names, dnames=dnames, bylen=bylen, leaf=leaf, game=game, game_lo=[a for a, _ in game],
             named_vas=set(names.values()))


def owned_game_units():
    """start VAs of the work/map/units.tsv rows owned by a library doc (see game_ranges)"""
    return {int(v, 16) for d in gbtree.lib_docs() for v in d.get("owned_game_units", ())}


def game_ranges():
    """sorted [(lo, hi)] of the game units (work/map/units.tsv), minus the rows a library doc owns: "owned_game_units"
    in engine/units-lib-*.json lists unit-map rows (start VA, hex) whose range is a vendored library compiled by the
    engine stage (fmt 0.12.0, 2026-10-20 tc1: the game map's source-less ?\\fmt.cpp row)."""
    owned = owned_game_units()
    game = []
    for line in open(UNITS_TSV):
        p = line.rstrip("\n").split("\t")
        if not p[0].startswith("#") and len(p) > 1 and int(p[0], 16) not in owned:
            game.append((int(p[0], 16), int(p[1], 16)))
    game.sort()
    return game


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
    leaf = G["leaf"]
    for rva in G["bylen"].get(len(data), []):
        if (rva in leaf) != (unw is None):      # a leaf (no .pdata) only pairs with a leaf, and vice versa
            continue
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


def _comdat_any(obj, n):
    return obj.sec(obj.syms[obj.by_name[n]][2]).get("comdat", (0,))[0] == 2


def _hints(obj, n, shints):
    """the exe targets of the last match of n; the static callees of a COMDAT-any caller go to shints instead: the
    linker may have kept another TU's copy of the caller, which calls that TU's statics (LuaTraits<T>::ToLuaObject ->
    _SWIG_Lua_AddMetatable), so they count only near the obj's own code (_static_hints)"""
    t = dict(bm.LAST_TARGETS)
    if not _comdat_any(obj, n):
        return t
    for k in [k for k in t if k in obj.by_name and obj.syms[obj.by_name[k]][4] == 3]:
        shints.setdefault(k, t.pop(k))
    return t


def _static_hints(obj, out, shints, callees):
    """shints whose exe VA lies within STATIC_NEAR of the obj's own (non-COMDAT-any) exact functions (if it has none:
    any of its exact functions) -> callees"""
    own = sorted(va for n, va, ok, _ in out if ok and not _comdat_any(obj, n)) or sorted(va for _, va, ok, _ in out if ok)
    if not own:
        return
    for k, v in shints.items():
        if k not in callees:
            i = bisect.bisect_left(own, v)
            if min(abs(v - own[j]) for j in (i - 1, i) if 0 <= j < len(own)) <= STATIC_NEAR:
                callees[k] = v


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
    shints = {}                  # static name -> exe VA called by an exact COMDAT-any function (see _hints)
    for si in obj.func_symbols():
        n = obj.syms[si][0]
        if n.startswith(bm.FUNCLET_PREFIXES):
            continue
        va = G["names"].get(n)
        if not _allowed(va):
            va = None
        ok = False
        how = "name"
        hits = ()
        if va is not None:
            ok = _match(obj, n, va)
            if ok:
                callees.update(_hints(obj, n, shints))
        if not ok:
            hits = [h for h in _search(obj, si) if _allowed(h)]
            if len(hits) > 1:
                eng = tuple(h for h in hits if not _in_game(h))      # game-unit copies are never engine credit
                if eng:
                    copies[n] = eng
            if len(hits) == 1 and hits[0] != va:
                ok2 = _match(obj, n, hits[0])
                if ok2:
                    callees.update(_hints(obj, n, shints))
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
        _static_hints(obj, out, shints, callees)
        for n in list(vfts):
            va = callees.get(n) or G["dnames"].get(n)
            if va is not None and (_allowed(va) or not _is_text(va)):   # windows are code ranges, vftables are .rdata
                for tn, tgt in _vft_slots(obj, vfts.pop(n), va):
                    callees.setdefault(tn, tgt)
                grew = True
        nxt = []
        for n in pending:
            va = callees.get(n)
            if va is None or not _allowed(va) or (va - exe.base not in exe.rf and va - exe.base not in G["leaf"]) \
                    or (n, va) in tried:
                nxt.append(n)
                continue
            tried.add((n, va))
            if _match(obj, n, va):          # exact only: the caller itself may be a byte-identical look-alike of
                if n in copies and (va in G["named_vas"] or va in {v for _, v, ok, _ in out if ok}):
                    weak[n] = (n, va, True, "callee")   # another type, so its reloc targets are only a hint: a VA
                    nxt.append(n)       # the tables or another name of this obj hold leaves a name with several
                    continue            # copies to assign_copies
                callees.update(_hints(obj, n, shints))
                out.append((n, va, True, "callee"))
            else:                           # a wrong hint: still unpaired (a copy candidate below)
                nxt.append(n)
        if len(nxt) == len(pending) and not grew:
            break
        pending = nxt
    # library objs (engine/units-lib-*.json, compiled from the vendor's own sources inside an include window): a hint
    # that stays non-exact (the vendor built them with another MSVC: EH states, inlining) still names the function at
    # that VA, so it pairs as functional rather than leaving the function a stub
    if LIB_RECIPE in path and not NO_CALLEE:
        used = {va for _, va, _, _ in out}
        for n in [n for n in pending if n not in copies and n not in weak]:
            va = callees.get(n)
            if va is not None and va not in used and _allowed(va) and G["win"] and G["win"][0] \
                    and (va - exe.base in exe.rf or va - exe.base in G["leaf"]):
                out.append((n, va, False, "hint"))
                used.add(va)
                pending.remove(n)
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


def _match_job(job):
    path, win = job
    G["win"] = win
    return path, match_obj(path)


def _greedy(todo, xok, match=None):
    """one-to-one pairing of each group's names with its exact copies (maximum matching): [(name, va)]. xok caches
    match results ("name@va" -> bool); without `match` an uncached trial returns None (a worker must run it)"""
    out = []
    for ns, copies in todo:
        for n in ns:
            for v in copies:
                t = f"{n}@{v:x}"
                if t not in xok:
                    if match is None:
                        return None
                    xok[t] = match(n, v)
        # maximum matching (augmenting paths, names and copies in the given order): a name whose callees are not in
        # the tables matches every copy, and first-fit let it take the one copy a callee-pinned name could use
        adj = {n: [v for v in copies if xok[f"{n}@{v:x}"]] for n in ns}
        mate = {}

        def augment(n, seen):
            for v in adj[n]:
                if v not in seen:
                    seen.add(v)
                    if v not in mate or augment(mate[v], seen):
                        mate[v] = n
                        return True
            return False
        for n in ns:
            augment(n, set())
        got = {n: v for v, n in mate.items()}
        out += [(n, got[n]) for n in ns if n in got]
    return out


def _verify_job(job):
    path, todo, xok = job
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, xok
    _greedy(todo, xok, lambda n, v: _match(obj, n, v))
    return path, xok


def _code_match(obj, n, va):
    """code bytes match (relocations resolved consistently) whatever the unwind/EH data: its targets are reliable"""
    with contextlib.redirect_stdout(io.StringIO()):
        try:
            return bool(bm.match_one(obj, n, va, G["exe"], verbose=False, check_unwind=False, quiet=True))
        except Exception:
            return False


def _libhint_job(job):
    """library obj: the exe targets (vftables -> their slots, direct callees) of its functions whose code matches
    (exact pairs, the copy pairs assign_copies found, then the hints themselves, to a fixpoint; plus `ext`, the other
    library objs' hints) name its functions that stay unpaired: (path, [(name, va)] credited functional, {name: va}
    every target found)"""
    path, pairs, win, ext = job
    G["win"] = win
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, [], {}
    exe = G["exe"]
    funcs = [obj.syms[si][0] for si in obj.func_symbols() if not obj.syms[si][0].startswith(bm.FUNCLET_PREFIXES)]
    paired = {n for n, _, _ in pairs}
    callees = {}
    todo = [(n, va) for n, va, _ in pairs]
    vfts = {obj.syms[i][0]: i for i in obj.syms if obj.syms[i][0].startswith("??_7") and obj.syms[i][2] > 0}
    out = []
    used = {va for _, va, _ in pairs}
    while True:
        for n, va in todo:
            if _code_match(obj, n, va):
                for k, v in bm.LAST_TARGETS.items():
                    callees.setdefault(k, v)
        for k, v in ext.items():
            callees.setdefault(k, v)
        for vn in list(vfts):
            va = callees.get(vn)
            if va is not None and not _is_text(va):
                for tn, tgt in _vft_slots(obj, vfts.pop(vn), va):
                    callees.setdefault(tn, tgt)
        todo = []
        for n in funcs:
            va = callees.get(n)
            if n in paired or va is None or va in used or not _allowed(va):
                continue
            if va - exe.base in exe.rf or va - exe.base in G["leaf"]:
                out.append((n, va))
                todo.append((n, va))
                paired.add(n)
                used.add(va)
        if not todo:
            break
    return path, out, {k: v for k, v in callees.items() if _allowed(v) or not _is_text(v)}


def lib_hints(res, paths, windows, j, log=print):
    """res[key]["hpairs"] of the library units (recipe lib-*): see _libhint_job (two rounds: the second one seeded
    with every obj's targets); a VA some obj pairs exactly or another hint already names is skipped"""
    keys = [k for k, c in res.items() if c["recipe"].startswith("lib-") and k in paths]
    jobs, byp = [], {}
    for k in keys:
        c = res[k]
        win = unit_window(c["unit"], windows)
        if not win[0]:
            continue
        jobs.append((paths[k], [(n, va, ok) for n, va, ok, _ in c["pairs"] + c.get("xpairs", [])], win))
        byp[paths[k]] = k
    if not jobs:
        return
    taken = {va for c in res.values() for _, va, ok, _ in c["pairs"] + c.get("xpairs", []) if ok}
    got, ext = {}, {}
    with Pool(max(1, j), initializer=_init) as p:
        for rnd in range(2):
            for path, hp, tg in p.imap_unordered(_libhint_job, [jb + (ext if rnd else {},) for jb in jobs]):
                got[byp[path]] = hp
                if not rnd:
                    for k, v in tg.items():
                        ext.setdefault(k, v)
    n = 0
    for k in sorted(got):
        res[k]["hpairs"] = []
        for nm, va in got[k]:
            if va not in taken:
                taken.add(va)
                res[k]["hpairs"].append([nm, va, False, "libhint"])
                n += 1
    log(f"engine: library hint pairs {n}")


def _small_leaf():
    """exe VAs of the leaf functions (no .pdata) shorter than LEAF_SMALL bytes"""
    exe = bm.Exe(bm.EXE)
    out = set()
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if p[0] and not p[0].startswith("#") and int(p[1]) < LEAF_SMALL and int(p[0], 16) - exe.base not in exe.rf:
            out.add(int(p[0], 16))
    return out


def assign_copies(res, cgroups, paths, j, log=print):
    """Pair the objs' unpaired functions that have several byte-identical exe copies (template instantiations of
    same-size types, e.g. map<utf8string,int> / map<utf8string,unsigned int>, kept apart by the linker): every copy no
    obj pairs exactly goes to the claiming obj whose own (non-COMDAT-any) exact functions lie nearest (the TU whose
    instantiation the linker placed there), then each obj pairs its functions one to one with its copies (greedy: the
    first copy that matches exactly; a callee named in the tables tells same-byte copies apart). Writes
    res[key]["xpairs"] (match results cached per obj result in res[key]["xok"])."""
    claimed = {va for c in res.values() for _, va, ok, _ in c["pairs"] if ok}
    small_leaf = _small_leaf()
    groups = collections.defaultdict(list)
    for k, c in res.items():
        for n, gid in c.get("cands", ()):
            if gid in cgroups:
                groups[(k, tuple(cgroups[gid]))].append(n)

    def dist(k, v):
        # an exact copy pair of an earlier round anchors the obj too (an obj whose only own code was a copy, e.g. a
        # NiPSys* modifier's CreateObject, then pulls its ??_G / ctor copies next to it)
        own = list(res[k].get("own") or ()) + [a for _, a in xpairs.get(k, ())]
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
                if v in small_leaf and d > LEAF_NEAR:     # a few-byte leaf body (ret, return a constant) says
                    continue                              # nothing about its TU: only near the obj's own code
                if v not in owner or (d, k) < owner[v]:
                    owner[v] = (d, k)
        todo = collections.defaultdict(list)
        for (k, hits), ns in groups.items():
            mine = sorted((v for v in hits if v in owner and owner[v][1] == k), key=lambda v: (owner[v][0], v))  # nearest first
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

# ---------------------------------------------------------------------------------------------------------------
# block pass (2026-10-22 gb12): a TU's dynamic initializers (.text$di) and atexit destructors (.text$yd) are one
# section per function; the linker lays an obj's sections of one name out contiguously, in the obj's section order, at
# the section alignment. Header statics (NiXKeyregisterloaderreturn, efd kCAT_* FixedStrings, NiFloodgateSDM) give
# every includer the same byte-identical functions (hundreds of copies), which assign_copies cannot place (its
# distance is to the obj's .text code, far away). Here each obj's whole block is placed: an exe base where every
# function's masked bytes match; relocations into the obj's own (non-COMDAT) data sections that agree on one base per
# section are counted as a score (the exe TU's data layout may differ a little), used only to rank placements.
BLOCK_SECS = (".text$di", ".text$yd")
BLOCK_KEY = "blk7"


def _block_layout(obj, secname):
    """[(symbol, offset, data, fields, leaf, alignment)] of the obj's functions in sections named secname, in link
    order"""
    secs = [(i + 1, s) for i, s in enumerate(obj.sections) if s["name"] == secname and s["chars"] & 0x20]
    fsyms = {}
    for si in obj.func_symbols():
        n, v, sn = obj.syms[si][0], obj.syms[si][1], obj.syms[si][2]
        if not n.startswith(bm.FUNCLET_PREFIXES):
            fsyms.setdefault(sn, []).append((v, si))
    out, off = [], 0
    for sn, s in secs:
        al = 1 << (((s["chars"] >> 20) & 0xF) - 1) if (s["chars"] >> 20) & 0xF else 16
        off = (off + al - 1) & -al
        for v, si in sorted(fsyms.get(sn, ())):
            data, fields, unw = obj.function(si)
            out.append((obj.syms[si][0], off + v, bytes(data), fields, unw is None, al))
        off += s["size"]
    return out


def _block_cands(obj, lay):
    """[(base, score, bad, shifts)] where the block lay fits the exe; score = own-data relocations agreeing on a base
    per section, bad = functions (at most 1/8) whose bytes differ, shifts = [[index, delta]] of the functions placed
    off their obj offset (after a function whose exe size differs)"""
    exe = G["exe"]
    if not lay:
        return []
    pats = []
    for n, off, data, fields, leaf, al in lay:
        m = bytearray(b"\xff") * len(data)
        loc = []
        for f in fields:
            for k in range(f[0], min(f[0] + f[1], len(data))):
                m[k] = 0
            tsi = f[5]
            if tsi is not None and bm.REL_REL32 <= f[3] <= bm.REL_REL32 + 5:
                t = obj.syms[tsi]
                if t[2] > 0 and not obj.sec(t[2])["chars"] & 0x20 and obj.sec(t[2]).get("comdat", (0,))[0] == 0:
                    loc.append((f[0], f[3] - bm.REL_REL32, struct.unpack_from("<i", data, f[0])[0] + 0, t[2], t[1]))
        mi = int.from_bytes(bytes(m), "little")
        pats.append((len(data), mi, int.from_bytes(data, "little") & mi, loc, al))
    # seed: the non-leaf function with the fewest (but some) masked hits
    best = None
    for i, (n, off, data, fields, leaf, al) in enumerate(lay):
        if leaf:
            continue
        hits = _search(obj, obj.by_name[n])
        if hits and (best is None or len(hits) < len(best[1])):
            best = (i, hits)
        if 0 < len(hits) <= 2:
            break
    if best is None:
        return []
    starts = G.get("starts")
    if starts is None:
        starts = G["starts"] = sorted(exe.rf)

    def fits(i, va):
        """None: the exe function at va is ours; else the size of the (different) exe function there, or -1"""
        ln, mi, want, loc, al = pats[i]
        rva = va - exe.base
        if not _allowed(va) or _in_game(va):
            return -1
        if (rva not in exe.rf or exe.chain_end(rva) - rva == ln) and \
                int.from_bytes(bytes(exe.img[rva:rva + ln]), "little") & mi == want:
            return None
        # a function the exe builds differently (MS2 change, other inlining): tolerated where the exe has a
        # function of its own (with unwind data, so its size is known)
        return exe.chain_end(rva) - rva if rva in exe.rf else -1
    # no tolerance: blocks are mostly identical header thunks, so a block with one differing function fits at many
    # wrong places (tried 1/8 in gb12: NiBezPosKey's thunks landed on NiAlphaController's block)
    out, lim = [], 0
    for h in best[1]:
        si = best[0]
        pos, bad = {si: h}, 0
        # walk forward: each function follows the previous one's exe size at its own section alignment
        for i in range(si, len(pats)):
            if i > si:
                pos[i] = (end + pats[i][4] - 1) & -pats[i][4]
            r = fits(i, pos[i])
            if r == -1:
                bad = len(pats)
                break
            if r is not None:
                bad += 1
            end = pos[i] + (pats[i][0] if r is None else r)
            if bad > lim:
                break
        # walk back: the previous function ends right below (our size if it matches there, else the exe function
        # that starts before)
        for i in range(si - 1, -1, -1):
            if bad > lim:
                break
            nxt = pos[i + 1]
            a = pats[i][4]
            guess = (nxt - pats[i][0]) & -a
            if fits(i, guess) is None and ((guess + pats[i][0] + pats[i + 1][4] - 1) & -pats[i + 1][4]) == nxt:
                pos[i] = guess
                continue
            j = bisect.bisect_left(starts, nxt - exe.base) - 1
            if j < 0:
                bad = len(pats)
                break
            pos[i] = starts[j] + exe.base
            r = fits(i, pos[i])
            if r is None or r == -1 or ((pos[i] + r + pats[i + 1][4] - 1) & -pats[i + 1][4]) != nxt:
                bad = len(pats)
                break
            bad += 1
        if bad > lim:
            continue
        bases = collections.defaultdict(collections.Counter)
        for i, va in pos.items():
            rva = va - exe.base
            if fits(i, va) is None:
                for fo, extra, add, sn, sv in pats[i][3]:
                    disp = struct.unpack_from("<i", exe.img, rva + fo)[0]
                    bases[sn][va + fo + 4 + extra + disp - add - sv] += 1
        base = pos[0] - lay[0][1]
        shifts = [[i, va - base - lay[i][1]] for i, va in sorted(pos.items()) if va != base + lay[i][1]]
        # score: relocations into the obj's own data that agree with one base per section (the exe TU's data layout
        # may differ a little, so this only ranks placements)
        out.append((base, sum(c.most_common(1)[0][1] for c in bases.values()), bad, shifts))
    return out


def _block_job(job):
    path, win = job
    G["win"] = win
    out = {}
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, out
    for sec in BLOCK_SECS:
        lay = _block_layout(obj, sec)
        if lay:
            out[sec] = {"lay": [[n, off, len(d)] for n, off, d, _, _, _ in lay],
                        "cands": [list(c) for c in _block_cands(obj, lay)]}
    return path, out


def assign_blocks(res, paths, windows, j, log=print):
    """place every obj's .text$di / .text$yd block (see BLOCK_SECS); writes res[key]["bpairs"]"""
    jobs = []
    for k, c in res.items():
        if c.get("blk", {}).get("key") != c["key"] + [BLOCK_KEY] and k in paths:
            jobs.append((paths[k], unit_window(c["unit"], windows), k))
    if jobs:
        log(f"engine: block layouts of {len(jobs)} obj(s) ...")
        byp = {p: k for p, _, k in jobs}
        with Pool(max(1, j), initializer=_init) as p:
            for path, out in p.imap_unordered(_block_job, [(p_, w) for p_, w, _ in jobs], chunksize=4):
                res[byp[path]]["blk"] = {"key": res[byp[path]]["key"] + [BLOCK_KEY], "secs": out}
    # exe VAs paired exactly by a name / unique search / callee hint / copy: another TU's function, never inside a
    # block. A copy pair of a block function is not: assign_copies places those by distance to the obj's .text and
    # never checks the data they initialise, so the block placement decides them (see the end).
    blkfn = {k: {n for s in c.get("blk", {}).get("secs", {}).values() for n, _, _ in s["lay"]} for k, c in res.items()}
    fixed, ex = {}, {}
    for k, c in res.items():
        for n, va, ok, how in c["pairs"] + c.get("hpairs", []) + [x for x in c.get("xpairs", []) if x[0] not in blkfn[k]]:
            if ok:
                fixed.setdefault(va, set()).add((k, n))
                ex[(k, n)] = va
    taken = []          # sorted [(lo, hi, unit)] of placed blocks
    bp = collections.defaultdict(list)
    for sec in BLOCK_SECS:
        todo = []
        for k, c in res.items():
            s = c.get("blk", {}).get("secs", {}).get(sec)
            if not s or not s["cands"]:
                continue
            lay = s["lay"]
            # the obj's own exact pairs inside the block are anchors: a placement must keep every one of them
            anchors = [(i, ex[(k, n)]) for i, (n, off, _) in enumerate(lay) if (k, n) in ex]
            good = []
            for b, score, bad, shifts in s["cands"]:
                sh = dict(shifts)
                pos = [b + off + sh.get(i, 0) for i, (n, off, _) in enumerate(lay)]
                if any(pos[i] != va for i, va in anchors):
                    continue
                if any(v in fixed and (k, n) not in fixed[v] for (n, _, _), v in zip(lay, pos)):
                    continue
                good.append(((bad, -score), pos))
            if good:
                best = min(good)[0]
                todo.append((k, lay, sorted(g[1] for g in good if g[0] == best)))
        # fewest (best-ranked) placements first, larger blocks first; a placement never overlaps an earlier one, but
        # the stock and v2525 objs of one unit share theirs
        todo.sort(key=lambda t: (len(t[2]), -(t[1][-1][1] + t[1][-1][2]), t[0]))
        for k, lay, good in todo:
            u = res[k]["unit"]
            for pos in good:
                lo, hi = pos[0], pos[-1] + lay[-1][2]
                i = bisect.bisect_right(taken, (lo, 1 << 62)) - 1
                if i >= 0 and taken[i][:3] == (lo, hi, u):
                    pass
                elif (i >= 0 and taken[i][1] > lo) or (i + 1 < len(taken) and taken[i + 1][0] < hi):
                    continue
                else:
                    bisect.insort(taken, (lo, hi, u))
                bp[k] += [(n, v) for (n, _, _), v in zip(lay, pos)]
                break
    # verify exactly (unwind included); a placed function that differs stays a functional pair
    vjobs = [(paths[k], [([n], [v]) for n, v in prs], res[k].get("bok", {})) for k, prs in bp.items()]
    vjobs = [jb for jb in vjobs if _greedy(jb[1], jb[2]) is None]
    if vjobs:
        byp = {paths[k]: k for k in bp}
        with Pool(max(1, j), initializer=_init) as p:
            for path, xok in p.imap_unordered(_verify_job, vjobs):
                res[byp[path]]["bok"] = xok
    n_ok = 0
    for k, c in res.items():
        xok = c.get("bok", {})
        c["bpairs"] = [[n, v, bool(xok.get(f"{n}@{v:x}")), "block"] for n, v in bp.get(k, ())]
        n_ok += sum(1 for p in c["bpairs"] if p[2])
    # an exact block pair supersedes copy pairs of the same function or exe VA
    bva = {p[1] for c in res.values() for p in c["bpairs"] if p[2]}
    for k, c in res.items():
        bn = {p[0] for p in c["bpairs"] if p[2]}
        if "xpairs" in c:
            c["xpairs"] = [x for x in c["xpairs"] if x[0] not in bn and x[1] not in bva]
    log(f"engine: block pairs {sum(len(v) for v in bp.values())} ({n_ok} exact) in {len(bp)} obj(s)")


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
    windows = load_windows()
    for u in units:
        o = obj_path(cache, u)
        if u["name"] in failed or not os.path.exists(o):
            res.pop(u["recipe"] + ":" + u["name"], None)
            continue
        key = [os.path.getmtime(o), os.path.getsize(o), MATCH_KEY]
        if LIB_RECIPE in o:
            key.append("lib-hint2")
        win = unit_window(u["unit"], windows)
        if win != (None, []):
            key.append(json.dumps(win))
        if os.environ.get("MS2_MERGE_INCR"):      # tools/merge.sh: also keyed by the symbol tables the match read
            import mergekey
            key.append(mergekey.engine_stamp())
        c = res.get(u["recipe"] + ":" + u["name"])
        if not c or c.get("key") != key:
            jobs.append((u, o, key, win))
    if jobs:
        log(f"engine: matching {len(jobs)} obj(s) ...")
        byobj = {o: (u, key) for u, o, key, _ in jobs}
        with Pool(max(1, j), initializer=_init) as p:
            for o, (rows, cands, own) in p.imap_unordered(_match_job, [(o, w) for _, o, _, w in jobs], chunksize=2):
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
        lib_hints(res, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, windows, j, log)
        assign_blocks(res, {u["recipe"] + ":" + u["name"]: obj_path(cache, u) for u in allu}, windows, j, log)
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
    game = game_ranges()
    import bisect
    gs = [a for a, _ in game]

    def in_game(va):
        i = bisect.bisect_right(gs, va) - 1
        return i >= 0 and va < game[i][1]
    best = {}      # va -> (rank, symbol, unit)   rank: 3 exact v2525, 2 exact stock, 1 paired
    named = set()  # (unit, va) paired through a name table
    # a stock TU and its v2525 twin are one TU whose unit names differ in case (SchedulerLua / schedulerlua): credit
    # them under the stock name, else a stub gap between their functions is never filled
    canon = {}
    for c in sorted(res.values(), key=lambda c: c["recipe"] != "stock"):
        canon.setdefault(c["unit"].lower(), c["unit"])
    for k, c in sorted(res.items()):
        c = dict(c, unit=canon[c["unit"].lower()])
        better = {x[0] for x in c.get("xpairs", []) + c.get("bpairs", []) if x[2]}
        for sym, va, ok, how in c["pairs"] + c.get("xpairs", []) + c.get("hpairs", []) + c.get("bpairs", []):
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
    # stubs: uncredited functions between two credited functions of the same unit. A credited function shorter than
    # LEAF_SMALL (ret, return a constant, an empty virtual: the linker folds such bodies across TUs) is no evidence of
    # where its TU lies: it neither bounds nor interrupts a run
    cred = sorted(v for v in rows if info[v][0] >= LEAF_SMALL)
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
            i += 1
            if v in rows:
                continue
            gap.append(v)
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
            # a name-table pair only anchors the run when it is exact: a functional one is a game /Od copy of an
            # inline the engine TU emitted optimised (NiPlane::SetConstant 0x141c1bb10 for NiHalfSpaceBV)
            if any((unit, v) in named and rows[v][2] == "matched" for v in c):
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
    import heavy_lock
    a.j = heavy_lock.clamp_jobs(a.j)
    with heavy_lock.heavy():     # no-op when a parent (progress.py, merge) already holds a slot
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
