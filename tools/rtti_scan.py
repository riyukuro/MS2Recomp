#!/usr/bin/env python3
"""MSVC x64 RTTI parser for the MS2 dump (offline, straight from the PE).

Walks every Complete Object Locator (COL) referenced from a vftable[-1] slot:
  COL  : sig(=1) offset cdOffset pTypeDescriptor pClassDescriptor pSelf   (image-relative)
  TD   : pVFTable(8) spare(8) name ".?AV...@@"
  CHD  : sig attributes numBaseClasses pBaseClassArray
  BCD  : pTypeDescriptor numContainedBases mdisp pdisp vdisp attributes pClassDescriptor

Outputs (work/classes/):
  rtti_classes.tsv : td  mangled  demangled  chd_attr  nbases  bases
                     bases = ';'-joined "name|mdisp|pdisp|vdisp|ncontained|attr" (index 0 = the class itself)
  rtti_vftables.tsv: vftable  col  class(demangled)  offset  cdOffset  nslots  slot targets (comma, hex)
Usage: tools/rtti_scan.py [exe] [outdir]
"""
import os
import struct
import subprocess
import sys
from bisect import bisect_left

import pefile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402
EXE = ms2paths.EXE
OUT = ms2paths.CLASSES_DIR


class Image:
    def __init__(self, path):
        pe = pefile.PE(path, fast_load=True)
        self.base = pe.OPTIONAL_HEADER.ImageBase
        self.size = pe.OPTIONAL_HEADER.SizeOfImage
        self.mem = bytearray(self.size)
        self.exec_ranges = []
        self.sections = []
        for s in pe.sections:
            raw = s.get_data()[: s.Misc_VirtualSize]
            self.mem[s.VirtualAddress : s.VirtualAddress + len(raw)] = raw
            name = s.Name.rstrip(b"\0").decode()
            self.sections.append((name, s.VirtualAddress, s.Misc_VirtualSize, s.Characteristics))
            if s.Characteristics & 0x20000000:
                self.exec_ranges.append((s.VirtualAddress, s.VirtualAddress + s.Misc_VirtualSize))

    def u32(self, rva):
        return struct.unpack_from("<I", self.mem, rva)[0]

    def i32(self, rva):
        return struct.unpack_from("<i", self.mem, rva)[0]

    def u64(self, rva):
        return struct.unpack_from("<Q", self.mem, rva)[0]

    def cstr(self, rva):
        e = self.mem.index(b"\0", rva)
        return self.mem[rva:e].decode("latin-1")

    def string_at(self, va, minlen=4):
        """NUL-terminated printable ASCII or UTF-16LE string at va, else None."""
        r = va - self.base
        if not (0 <= r < self.size):
            return None
        m = self.mem
        e = r
        while e < self.size and e - r < 4096 and (32 <= m[e] < 127 or m[e] in (9, 10, 13)):
            e += 1
        if e < self.size and m[e] == 0 and e - r >= minlen:
            return m[r:e].decode("latin-1")
        e = r
        while e + 1 < self.size and e - r < 8192 and m[e + 1] == 0 and (32 <= m[e] < 127 or m[e] in (9, 10, 13)):
            e += 2
        if e + 1 < self.size and m[e] == 0 and m[e + 1] == 0 and (e - r) // 2 >= minlen:
            return m[r:e].decode("utf-16le")
        return None

    def is_exec_va(self, va):
        r = va - self.base
        return any(a <= r < b for a, b in self.exec_ranges)

    def section(self, name):
        for n, va, sz, ch in self.sections:
            if n == name:
                return va, sz
        raise KeyError(name)


def demangle_types(mangled):
    """'.?AVFoo@Bar@@' -> 'Bar::Foo' via llvm-undname on the vftable symbol."""
    syms = ["??_7" + m[4:] + "6B@" for m in mangled]
    p = subprocess.run(["llvm-undname"], input="\n".join(syms) + "\n", capture_output=True, text=True)
    res = {}
    blocks = [b for b in p.stdout.split("\n\n")]
    lines = []
    for b in blocks:
        ls = [x for x in b.split("\n") if x != ""]
        if len(ls) >= 2:
            lines.append((ls[0], ls[1]))
        elif len(ls) == 1:
            lines.append((ls[0], None))
    by_sym = {a: b for a, b in lines}
    for m, s in zip(mangled, syms):
        d = by_sym.get(s)
        if d and d.startswith("const ") and d.endswith("::`vftable'"):
            res[m] = d[len("const ") : -len("::`vftable'")]
        else:
            # fallback: simple reversed components
            body = m[4:].rstrip("@")
            res[m] = "::".join(reversed([x for x in body.split("@") if x]))
    return res


def main():
    img = Image(EXE)
    global OUT
    os.makedirs(OUT, exist_ok=True)
    rd_va, rd_sz = img.section(".rdata")
    # 1. find COLs: sig==1, pSelf == own rva, TD name starts with .?A
    cols = {}
    mem = img.mem
    for rva in range(rd_va, rd_va + rd_sz - 24, 4):
        if mem[rva] != 1 or mem[rva + 1 : rva + 4] != b"\0\0\0":
            continue
        sig, off, cdoff, ptd, pchd, pself = struct.unpack_from("<IIIIII", mem, rva)
        if pself != rva or not (0 < ptd < img.size) or not (0 < pchd < img.size):
            continue
        if mem[ptd + 16 : ptd + 20] not in (b".?AV", b".?AU"):
            continue
        cols[rva] = (off, cdoff, ptd, pchd)
    print(f"COLs: {len(cols)}", file=sys.stderr)

    # 2. vftables: qword in .rdata pointing to a COL; vftable = that slot + 8
    col_vas = {img.base + r: r for r in cols}
    meta = []  # (vftable rva, col rva)
    for rva in range(rd_va, rd_va + rd_sz - 8, 8):
        q = struct.unpack_from("<Q", mem, rva)[0]
        if q in col_vas:
            meta.append((rva + 8, col_vas[q]))
    meta_set = sorted(r - 8 for r, _ in meta)
    print(f"vftables: {len(meta)}", file=sys.stderr)

    # 3. classes from TDs/CHDs
    tds = {}
    chds = {}

    def read_chd(chd):
        if chd in chds:
            return chds[chd]
        sig, attr, nb, pbca = struct.unpack_from("<IIII", mem, chd)
        bases = []
        for i in range(nb):
            bcd = img.u32(pbca + 4 * i)
            ptd, ncont, mdisp, pdisp, vdisp, battr = struct.unpack_from("<IIiiiI", mem, bcd)
            bases.append((ptd, mdisp, pdisp, vdisp, ncont, battr))
            tds.setdefault(ptd, img.cstr(ptd + 16))
        chds[chd] = (attr, bases)
        return chds[chd]

    for col, (off, cdoff, ptd, pchd) in cols.items():
        tds.setdefault(ptd, img.cstr(ptd + 16))
        read_chd(pchd)
    # Every TD whose class has its own COL: map td -> chd (from COLs)
    td_chd = {}
    for col, (off, cdoff, ptd, pchd) in cols.items():
        td_chd.setdefault(ptd, pchd)
    names = demangle_types(sorted(set(tds.values())))

    with open(os.path.join(OUT, "rtti_classes.tsv"), "w") as f:
        f.write("#td\tmangled\tname\tchd_attr\tnbases\tbases(name|mdisp|pdisp|vdisp|ncontained|attr)\n")
        for td in sorted(tds):
            m = tds[td]
            chd = td_chd.get(td)
            if chd is None:
                f.write(f"{img.base + td:x}\t{m}\t{names[m]}\t\t0\t\n")
                continue
            attr, bases = chds[chd]
            bs = ";".join(f"{names[tds[b[0]]]}|{b[1]}|{b[2]}|{b[3]}|{b[4]}|{b[5]}" for b in bases)
            f.write(f"{img.base + td:x}\t{m}\t{names[m]}\t{attr}\t{len(bases)}\t{bs}\n")

    # slots
    with open(os.path.join(OUT, "rtti_vftables.tsv"), "w") as f:
        f.write("#vftable\tcol\tclass\toffset\tcdOffset\tnslots\tslots\n")
        for vt, col in sorted(meta):
            off, cdoff, ptd, pchd = cols[col]
            # stop at the next vftable's meta pointer or at a non-code pointer
            nxt = bisect_left(meta_set, vt)
            limit = meta_set[nxt] if nxt < len(meta_set) else vt + 8 * 4096
            slots = []
            r = vt
            while r < limit:
                q = img.u64(r)
                if not img.is_exec_va(q):
                    break
                slots.append(q)
                r += 8
            f.write(f"{img.base + vt:x}\t{img.base + col:x}\t{names[tds[ptd]]}\t{off}\t{cdoff}\t{len(slots)}\t"
                    + ",".join(f"{s:x}" for s in slots) + "\n")


if __name__ == "__main__":
    if len(sys.argv) > 1:
        EXE = sys.argv[1]
    if len(sys.argv) > 2:
        OUT = sys.argv[2]
    main()
