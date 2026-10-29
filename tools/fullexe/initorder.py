#!/usr/bin/env python3
"""Static-initializer order fixes for link.py --before, from crtinit<TAG>.tsv (crtinit.py).
    initorder.py [--manual FILE]
Units with initializers in both the exe and ours are ranked by their first exe .CRT$XCU entry; the longest run already in
exe order (LIS of our obj order) stays, and every other unit is moved just before the first LIS unit the exe runs after
it. --manual rows (same format: `<unit A>\\t<unit B>\\t# why`, for dependencies the first-entry rank gets wrong, e.g. a
unit whose initializers the exe interleaves with another's) are applied first. Writes <OUT>/initorder<TAG>.tsv."""
import argparse, bisect, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import OUT, tagged  # noqa: E402


def lis_keep(ranks):
    """indices of one longest strictly increasing subsequence"""
    tails, tail_i, prev = [], [], [-1] * len(ranks)
    for i, v in enumerate(ranks):
        j = bisect.bisect_left(tails, v)
        if j == len(tails):
            tails.append(v)
            tail_i.append(i)
        else:
            tails[j], tail_i[j] = v, i
        prev[i] = tail_i[j - 1] if j else -1
    out, k = [], tail_i[-1] if tail_i else -1
    while k >= 0:
        out.append(k)
        k = prev[k]
    return set(out)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--manual")
    a = ap.parse_args()
    first_e, ours = {}, []
    for l in open(tagged("crtinit.tsv")):
        p = l.rstrip("\n").split("\t")
        if l[0] == "#" or p[1] != "XC" or p[4] == "?":
            continue
        if p[0] == "exe":
            first_e.setdefault(p[4], int(p[2]))
        elif "ms2_registered_" not in p[5] and p[4] not in ours:
            ours.append(p[4])
    order = [l.split("\t")[2] for l in open(os.path.join(OUT, "order.tsv")) if l[0] != "#"]
    pos = {u: i for i, u in reversed(list(enumerate(order)))}
    shared = sorted((u for u in ours if u in first_e and u in pos), key=lambda u: pos[u])    # our link order
    ranks = [first_e[u] for u in shared]
    keep = lis_keep(ranks)
    lis = sorted((ranks[i], shared[i]) for i in keep)
    rows = []
    if a.manual:
        rows += [l.rstrip("\n") for l in open(a.manual) if l.strip() and l[0] != "#"]
    moved = 0
    for i in sorted(set(range(len(shared))) - keep, key=lambda i: ranks[i]):
        j = bisect.bisect_right(lis, (ranks[i], "￿"))
        if j < len(lis):
            rows.append("%s\t%s\t# exe XC #%d runs before #%d" % (shared[i], lis[j][1], ranks[i], lis[j][0]))
            moved += 1
    path = tagged("initorder.tsv")
    open(path, "w").write("\n".join(rows) + "\n")
    print("%s: %d shared units, LIS %d, %d moved (+%d manual)" % (path, len(shared), len(keep), moved,
                                                                  len(rows) - moved))


if __name__ == "__main__":
    main()
