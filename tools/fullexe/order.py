#!/usr/bin/env python3
"""/ORDER file from functions.tsv: every function symbol some linked obj defines, at its exe VA (symbols*.tsv), in
exe VA order -> order.txt (link with /ORDER:@order.txt). Only COMDAT functions (/Gy) can be ordered."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import SYMBOL_TABLES, ROOT as R, OUT as F, TREE as T, tagged  # noqa: E402
import ms2paths  # noqa: E402
fva = set()
for l in open(ms2paths.FUNCTIONS_TSV):
    p = l.split("\t")
    if p[0] and p[0][0] != "#":
        try: fva.add(int(p[0], 16))
        except ValueError: pass
defs = {l.split("\t")[0] for l in open(f"{F}/defsyms.tsv", encoding="latin1")}
va = {}
for fn in SYMBOL_TABLES:
    for l in open(f"{T}/progress/{fn}", encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if l[0] != "#" and len(p) > 1 and p[0] in defs and p[0] not in va:
            try: v = int(p[1], 16)
            except ValueError: continue
            if v in fva: va[p[0]] = v
rows = sorted(va.items(), key=lambda x: (x[1], x[0]))
with open(f"{F}/order.txt", "w", encoding="latin1") as o:
    for s, v in rows: o.write(s + "\n")
print(len(rows), "ordered function symbols of", len(fva), "exe functions;", len({v for _, v in rows}), "distinct VAs")
