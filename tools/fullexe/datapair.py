#!/usr/bin/env python3
"""data VA pairs: for every linked obj function the gates pair with an exe VA and whose code bytes match there (relocation
fields masked, .pdata length equal), each REL32 field's exe displacement names the exe VA of the symbol the obj field
targets. A data symbol the obj defines (directly, or at its offset in a section a field targets through the section
symbol) gets the VA every such field agrees on -> datapairs<TAG>.tsv:
    va  symbol  obj  external(1/0)  nrefs(referencing functions)  size(obj, '~' = upper bound)  exe_section
Symbols two fields resolve differently are dropped (`conflicts` in the summary). datapair-alias<TAG>.rsp: an
/alternatename for each unresolved name whose VA (symbol row, or DAT_/PTR_ VA in its name) a pair gives, when the pair
is external, has nrefs >= 2 or an exact size equal to the exe-side size (the gap to the next exe VA a symbol row or
data pair names: an upper bound), the sections agree (read-only obj data <->
exe .rdata) and no exact obj size exceeds the exe-side bound. Also copied to datapair-alias.rsp, which link.py --alias
appends after alias.rsp. datapair-static<TAG>.tsv: unresolved names a pair gives
only an internal (static) definition (no alias can target one: the owning TU must give it external linkage)."""
import collections, glob, json, os, re, shutil, struct, sys
from multiprocessing import Pool
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import SYMBOL_TABLES, ROOT as R, OUT as F, TREE as T, tagged  # noqa: E402
sys.path.insert(0, os.path.join(R, "tools"))
import bytematch as bm  # noqa: E402

REL32 = bm.REL_REL32
G = {}


def exe_section(va):
    for s in G["secs"]:
        if s[1] <= va < s[2]:
            return s[0]
    return "?"


def _init(paired=None):
    G["paired"] = paired
    exe = G["exe"] = bm.Exe(bm.EXE)
    G["secs"] = [(s.Name.rstrip(b"\0").decode("latin1"), exe.base + s.VirtualAddress,
                  exe.base + s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData)) for s in exe.pe.sections]


def code_matches(obj, si, va):
    """code bytes equal outside relocation fields and the exe .pdata length (when the VA has one) equal: then every
    REL32 field's exe displacement is the same target the obj field names"""
    exe = G["exe"]
    data, fields, _ = obj.function(si)
    rva = va - exe.base
    if rva in exe.rf and exe.chain_end(rva) - rva != len(data):
        return None
    x = exe.read(va, len(data))
    if len(x) != len(data):
        return None
    mask = bytearray(len(data))
    for off, ln, *_ in fields:
        mask[off:off + ln] = b"\1" * min(ln, len(data) - off)
    if any(not mask[k] and data[k] != x[k] for k in range(len(data))):
        return None
    out = []
    for off, ln, sname, ty, inner, tsi in fields:
        if REL32 <= ty <= REL32 + 5 and off + 4 <= len(data) and tsi is not None:
            disp = struct.unpack_from("<i", x, off)[0]
            add = struct.unpack_from("<i", data, off)[0]
            out.append((tsi, va + off + 4 + (ty - REL32) + disp - add))
    return out


def job(arg):
    path, names = arg, G["paired"]
    try:
        obj = bm.Obj(path)
    except Exception:
        return path, [], 0, 0
    seen = collections.defaultdict(lambda: collections.defaultdict(set))   # symidx -> target -> {referencing fns}
    nmatch = 0
    for si in obj.func_symbols():
        n = obj.syms[si][0]
        va = names.get(n)
        if va is None:
            continue
        try:
            t = code_matches(obj, si, va)
        except Exception:
            t = None
        if t is None:
            continue
        nmatch += 1
        for tsi, tgt in t:
            seen[tsi][tgt].add(n)
    # data sections' symbols, by section
    bysec = collections.defaultdict(list)
    for idx, (name, value, secnum, typ, sclass) in obj.syms.items():
        if secnum > 0 and sclass in (2, 3) and not obj.sec(secnum)["chars"] & 0x20:
            bysec[secnum].append((value, idx))
    out = []
    conflicts = 0
    for secnum, lst in bysec.items():
        s = obj.sec(secnum)
        if s["chars"] & 0x02000000 or s["name"].startswith((".debug", ".pdata", ".xdata", ".drectve", ".CRT")):
            continue           # discardable / unwind / CRT init tables
        lst.sort()
        secsym = next((i for v, i in lst if v == 0 and obj.syms[i][4] == 3 and obj.syms[i][0] == s["name"]), None)
        base = seen.get(secsym, {}) if secsym is not None else {}
        ro = not s["chars"] & 0x80000000
        named = [(v, i) for v, i in lst if not (obj.syms[i][4] == 3 and v == 0 and obj.syms[i][0] == s["name"])]
        for k, (v, i) in enumerate(named):
            name, sclass = obj.syms[i][0], obj.syms[i][4]
            if name.startswith(("$", ".", "??_C@", "__real@", "__xmm@", "__mask@")):
                continue
            nxt = next((v2 for v2, _ in named[k + 1:] if v2 > v), None)
            exact = nxt is None and v == 0 and "comdat" in s
            size = ("%d" if exact else "~%d") % ((nxt if nxt is not None else s["size"]) - v)
            cand = collections.defaultdict(set)
            for tgt, fns in seen.get(i, {}).items():
                cand[tgt] |= fns
            for tgt, fns in base.items():
                cand[tgt + v] |= {f + "@sec" for f in fns}
            if not cand:
                continue
            if len(cand) > 1:
                conflicts += 1
                continue
            tgt, fns = next(iter(cand.items()))
            out.append((tgt, name, int(sclass == 2), len({f.replace("@sec", "") for f in fns}), size, ro))
    return path, out, nmatch, conflicts


def main():
    sym2va = {}
    for fn in SYMBOL_TABLES:
        for l in open(f"{T}/progress/{fn}", encoding="latin1"):
            p = l.rstrip("\n").split("\t")
            if l[0] != "#" and len(p) > 1:
                try: sym2va.setdefault(p[0], int(p[1], 16))
                except ValueError: pass
    paired = {}
    for rj in glob.glob(f"{T}/build/progress*/results.json"):
        for unit, r in json.load(open(rj)).items():
            for sym, pr in ((r.get("res") or {}).get("pairs") or {}).items():
                if pr.get("ok") and pr.get("va"): paired.setdefault(sym, pr["va"])
    if os.path.exists(f"{F}/gbpairs.tsv"):
        for l in open(f"{F}/gbpairs.tsv", encoding="latin1"):
            sym, va = l.rstrip("\n").split("\t"); paired.setdefault(sym, int(va, 16))
    for s, va in sym2va.items():
        paired.setdefault(s, va)
    objs = collections.OrderedDict()
    for l in open(f"{F}/defsyms.tsv", encoding="latin1"):
        o = l.rstrip("\n").split("\t")[1]
        if o not in objs:
            for d in (os.path.join(F, "obj"), F, R):
                if os.path.exists(os.path.join(d, o)):
                    objs[o] = os.path.join(d, o); break
    jobs = list(objs.values())
    rel = {p: o for o, p in objs.items()}
    pairs, nm, nc = [], 0, 0
    with Pool(int(os.environ.get("JOBS", "8")), initializer=_init, initargs=(paired,)) as pool:
        for path, out, nmatch, conflicts in pool.imap_unordered(job, jobs, chunksize=4):
            nm += nmatch; nc += conflicts
            pairs += [(tgt, n, rel[path], ext, nr, sz, ro) for tgt, n, ext, nr, sz, ro in out]
    _init()
    with open(tagged("datapairs.tsv"), "w") as f:
        f.write("#va\tsymbol\tobj\texternal\tnrefs\tsize\texe_section\n")
        for tgt, n, o, ext, nr, sz, ro in sorted(pairs):
            f.write(f"{tgt:x}\t{n}\t{o}\t{ext}\t{nr}\t{sz}\t{exe_section(tgt)}\n")
    # exe-side size bound: the gap to the next exe VA any symbol row or data pair names (outside-units.tsv's sizes
    # are the placeholder's declared type, e.g. 8 for a type_info DAT_ that is ??_R0H@8's 19 bytes)
    import bisect
    known = sorted(set(sym2va.values()) | {p[0] for p in pairs})
    def gap(va):
        i = bisect.bisect_right(known, va)
        return known[i] - va if i < len(known) else None
    defs = set(l.split("\t")[0] for l in open(f"{F}/defsyms.tsv", encoding="latin1"))
    byva, statics = collections.defaultdict(list), collections.defaultdict(list)
    for tgt, n, o, ext, nr, sz, ro in pairs:
        if ext and n in defs:
            byva[tgt].append((n, nr, sz, ro))
        elif not ext:
            statics[tgt].append((n, o, nr, sz))
    PH = re.compile(r"(?:DAT|PTR)_(14[0-9a-f]{7})")
    why, n = collections.Counter(), 0
    st = open(tagged("datapair-static.tsv"), "w")
    st.write("#va\tunresolved\tstatic definition\tobj\tnrefs\tsize\n")
    with open(tagged("datapair-alias.rsp"), "w") as out:
        for l in open(tagged("unresolved.txt"), encoding="latin1"):
            s = l.rstrip("\n").split("\t")[0]
            va = sym2va.get(s)
            if va is None:
                m = PH.search(s); va = int(m.group(1), 16) if m else None
            if va is None or s in defs:
                continue
            if va not in byva:
                for d, o, nr, sz in statics.get(va, [])[:1]:
                    st.write(f"{va:x}\t{s}\t{d}\t{o}\t{nr}\t{sz}\n"); why["static definition only"] += 1
                continue
            want = gap(va)
            ok = []
            for d, nr, sz, ro in byva[va]:
                exact = not sz.startswith("~"); dsz = int(sz.lstrip("~"))
                # the exe-side size is the distance to the next known exe symbol (an upper bound): only an exact obj
                # size larger than it contradicts the pair
                if want is not None and exact and dsz > want:
                    why["size differs"] += 1; continue
                if ro != (exe_section(va) == ".rdata"):
                    why["section differs"] += 1; continue
                if nr >= 2 or (exact and want is not None and 0 <= want - dsz < 16):   # size up to alignment padding
                    ok.append(d)
                else:
                    why["one referencing function, no exact size"] += 1
            ok = sorted(set(ok))
            if len(ok) > 1:
                why["several definitions"] += 1
            if ok and ok[0] != s:
                out.write(f'"/alternatename:{s}={ok[0]}"\n'); n += 1
    st.close()
    # the untagged copy link.py --alias appends after alias.rsp (like alias.rsp / abithunks.tsv, the pipeline's current set)
    if tagged("datapair-alias.rsp") != os.path.join(F, "datapair-alias.rsp"):
        shutil.copy(tagged("datapair-alias.rsp"), os.path.join(F, "datapair-alias.rsp"))
    print(f"{nm} matched functions; {len(pairs)} data pairs ({sum(1 for p in pairs if p[3])} external), {nc} conflicting "
          f"symbols dropped; {n} aliases -> {tagged('datapair-alias.rsp')}")
    for k, v in why.most_common():
        print(f"  {v:6}  {k}")


if __name__ == "__main__":
    main()
