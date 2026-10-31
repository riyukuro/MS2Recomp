#!/usr/bin/env python3
"""Static-initializer order: the exe's .CRT$XC* / .CRT$XI* pointer tables vs fullexe<TAG>.exe's (map __xc_a..__xc_z).
Each entry is attributed to a unit: exe entries by status.tsv row at the VA, else the data/map/units.tsv range holding
it; ours by the map's Lib:Object of the initializer (-> order.tsv unit). Hook registrations (`ms2_registered_*`, the
MS2_REPLACE statics that call the shim's no-op hook::Register) are counted apart. Writes crtinit<TAG>.tsv (side, index,
va, unit, symbol) and prints the comparison.
    crtinit.py [--exe-table FILE] [--write-exe-table FILE]
  --exe-table        the exe's XC/XI initializer VAs from FILE (data/fullexe/crtinit-exe.tsv) instead of the exe
  --write-exe-table  write them from the exe to FILE and exit"""
import bisect, collections, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT as R, OUT as F, TREE as T, EXE, tagged, status_tsv  # noqa: E402
import pefile  # noqa: E402


def lis_len(seq):
    tails = []
    for v in seq:
        i = bisect.bisect_left(tails, v)
        tails[i:i + 1] = [v]
    return len(tails)


def qwords(pe, va, n):
    b = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, 8 * n)
    return list(struct.unpack("<%dQ" % n, b))


def exe_tables(pe):
    """[(name, [ptr...])] for XC and XI: walk back from __xl_a (TLS AddressOfCallBacks - 8) over code pointers"""
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_TLS"]])
    xl_a = pe.DIRECTORY_ENTRY_TLS.struct.AddressOfCallBacks - 8
    text = [s for s in pe.sections if s.Characteristics & 0x20000000]
    lo = pe.OPTIONAL_HEADER.ImageBase + min(s.VirtualAddress for s in text)
    hi = pe.OPTIONAL_HEADER.ImageBase + max(s.VirtualAddress + s.Misc_VirtualSize for s in text)
    cur, vals = xl_a, []
    while True:
        cur -= 8
        v = qwords(pe, cur, 1)[0]
        if v and not lo <= v < hi:
            break
        vals.append(v)
    vals.reverse()                       # [xc_a=0, ..., xc_z=0, xi_a=0, ..., xi_z=0]; leading zeros before xc_a dropped
    while len(vals) > 1 and vals[0] == 0 and vals[1] == 0:
        vals.pop(0)
    z = [i for i, v in enumerate(vals) if v == 0]
    return [("XC", [v for v in vals[z[0]:z[-3] + 1] if v]), ("XI", [v for v in vals[z[-2]:] if v])]


def arg(name):
    return sys.argv[sys.argv.index(name) + 1] if name in sys.argv else None


def main():
    if arg("--exe-table"):
        ex = {"XC": [], "XI": []}
        for l in open(arg("--exe-table")):
            if l.strip() and l[0] != "#":
                t, i, va = l.split()[:3]
                assert int(i) == len(ex[t]), l
                ex[t].append(int(va, 16))
    else:
        ex = dict(exe_tables(pefile.PE(EXE, fast_load=True)))
    if arg("--write-exe-table"):
        with open(arg("--write-exe-table"), "w", newline="\n") as f:
            f.write("# table\tindex\tva: the exe's .CRT$XC*/.CRT$XI* initializer pointers in table order (between __xc_a/"
                    "__xc_z, __xi_a/__xi_z;\n# tools/fullexe/crtinit.py --write-exe-table)\n")
            for t in ("XC", "XI"):
                for i, v in enumerate(ex[t]):
                    f.write("%s\t%d\t%x\n" % (t, i, v))
        return
    # exe VA -> unit
    st = {}
    for l in open(status_tsv(), encoding="utf-8", errors="replace"):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 2:
            st[int(p[0], 16)] = (p[2], p[1])
    ur = []
    for l in open(os.path.join(T, "data", "map", "units.tsv")):
        p = l.split("\t")
        if l[0] != "#" and len(p) > 2:
            ur.append((int(p[0], 16), int(p[1], 16), p[2]))
    ur.sort()
    starts = [u[0] for u in ur]

    def exe_unit(va):
        if va in st:
            return st[va][0], st[va][1]
        i = bisect.bisect_right(starts, va) - 1
        if i >= 0 and va < ur[i][1]:
            return ur[i][2], ""
        return "?", ""

    # ours: map symbols + objs
    mp = open(tagged("fullexe.map"), encoding="latin1").read().splitlines()
    sym_at, xc = {}, {}
    pat = re.compile(r"^ [0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{16})\s+(?:f i |f   |    )?\s*(\S+)$")
    for l in mp:
        m = pat.match(l)
        if m:
            name, va, obj = m.group(1), int(m.group(2), 16), m.group(3)
            if name in ("__xc_a", "__xc_z", "__xi_a", "__xi_z"):
                xc[name] = va
            sym_at.setdefault(va, (name, obj))
    obj2unit = {}
    for l in open(os.path.join(F, "order.tsv")):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 3:
            obj2unit.setdefault(os.path.basename(p[3]), p[2])
    fx = pefile.PE(tagged("fullexe.exe"), fast_load=True)
    ours = {}
    for t, a, z in (("XC", "__xc_a", "__xc_z"), ("XI", "__xi_a", "__xi_z")):
        ours[t] = [v for v in qwords(fx, xc[a], (xc[z] - xc[a]) // 8 + 1) if v]

    def our_unit(va):
        name, obj = sym_at.get(va, ("?", "?"))
        obj = re.sub(r"^\d{5}_", "", obj.split(":")[-1])
        return obj2unit.get(obj, obj), name

    rows = []
    with open(tagged("crtinit.tsv"), "w") as out:
        out.write("#side\ttable\tindex\tva\tunit\tsymbol\n")
        seqs = {}
        for side, tabs, fn in (("exe", ex, exe_unit), ("ours", ours, our_unit)):
            for t in ("XC", "XI"):
                seq = []
                for i, v in enumerate(tabs[t]):
                    u, s = fn(v)
                    out.write(f"{side}\t{t}\t{i}\t{v:x}\t{u}\t{s}\n")
                    seq.append((u, s))
                seqs[side, t] = seq
    for t in ("XC", "XI"):
        e, o = seqs["exe", t], seqs["ours", t]
        reg = sum(1 for u, s in o if "ms2_registered_" in s)
        o2 = [(u, s) for u, s in o if "ms2_registered_" not in s]
        print(f"{t}: exe {len(e)} entries, ours {len(o)} ({reg} hook registrations, {len(o2)} other)")
        eu = [u for u, _ in e]
        first_e = {}
        for i, u in enumerate(eu):
            first_e.setdefault(u, i)
        ou = []
        for u, _ in o2:
            if not ou or ou[-1] != u:
                ou.append(u)
        seen, ranks = set(), []
        for u in ou:
            if u in first_e and u not in seen:
                seen.add(u)
                ranks.append(first_e[u])
        ue, uo = set(eu), set(u for u, _ in o2)
        print(f"  units with initializers: exe {len(ue)}, ours {len(uo)}, both {len(ue & uo)}; exe-only {len(ue - uo)}"
              f" ({sum(1 for u in eu if u not in uo)} entries), ours-only {len(uo - ue)}")
        if ranks:
            print(f"  order of the shared units: LIS {lis_len(ranks)}/{len(ranks)} = {100.0 * lis_len(ranks) / len(ranks):.1f}%")
        miss = collections.Counter(u for u in eu if u not in uo)
        print("  exe-only units by entries:", ", ".join(f"{u} {n}" for u, n in miss.most_common(12)))


if __name__ == "__main__":
    main()
