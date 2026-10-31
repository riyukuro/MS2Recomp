#!/usr/bin/env python3
"""defined external symbols of every planned obj -> defsyms.tsv (sym, obj): the <OUT>/obj snapshot (link.py
--snapshot), else order.tsv's objs in place, then asm.py's objs"""
import os, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT as R, OUT as F, TREE as T, tagged  # noqa: E402
def defined(path):
    with open(path, "rb") as f:
        h = f.read(56)
        s1, s2 = struct.unpack_from("<HH", h, 0)
        if s1 == 0 and s2 == 0xFFFF:
            symoff, nsym = struct.unpack_from("<II", h, 48); sz, fmt = 20, "<i"
        else:
            symoff, nsym = struct.unpack_from("<II", h, 8); sz, fmt = 18, "<h"
        f.seek(symoff); tab = f.read(nsym * sz)
        strsz, = struct.unpack("<I", f.read(4)); strs = f.read(max(0, strsz - 4))
    i = 0
    while i < nsym:
        o = i * sz
        sec, = struct.unpack_from(fmt, tab, o + 12)
        scl, naux = tab[o + sz - 2], tab[o + sz - 1]
        if sec > 0 and scl == 2:
            if tab[o:o + 4] == b"\0\0\0\0":
                so = struct.unpack_from("<I", tab, o + 4)[0] - 4
                n = strs[so:strs.index(b"\0", so)]
            else:
                n = tab[o:o + 8].rstrip(b"\0")
            yield n.decode("latin1")
        i += 1 + naux
snap = os.path.join(F, "obj")
if os.path.isdir(snap):
    objs = [(p, os.path.join(snap, p)) for p in sorted(os.listdir(snap))]
else:
    objs = [(os.path.relpath(r[3], R), r[3]) for r in (l.rstrip("\n").split("\t") for l in open(os.path.join(F, "order.tsv")))
            if r[0][0] != "#"]
asm = os.path.join(F, "asm")
objs += [("asm/" + p, os.path.join(asm, p)) for p in sorted(os.listdir(asm)) if p.endswith(".obj")] if os.path.isdir(asm) else []
with open(os.path.join(F, "defsyms.tsv"), "w") as out:
    for p, path in objs:
        # dict.fromkeys, not set(): a set iterates in per-run string-hash order, and alias.py takes the first definition
        # at a VA in this order (203 picks moved between two builds of the same objs)
        for s in dict.fromkeys(defined(path)):
            out.write(f"{s}\t{p}\n")
print("done")
