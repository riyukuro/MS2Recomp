#!/usr/bin/env python3
"""Verify the VC9 install (third_party/msvc9, tools/fetch-vc9.sh) against tools/msvc9/manifest.tsv, check_toolchain style.

    python tools/msvc9/check.py            exit 1 on any difference
    python tools/msvc9/check.py --record   rewrite the manifest from this host's install (maintainer only)

Checked: SHA-256 of every file under bin/, an order-independent digest of include/crt and include/api (WDK 7.1
7600.16385), and the cl banner (15.00.30729.207) through tools/msvc9/cl.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import ms2paths  # noqa: E402
from check_toolchain import sha256, tree_digest, banner  # noqa: E402

MANIFEST = os.path.join(ms2paths.ROOT, "tools", "msvc9", "manifest.tsv")
VC9 = os.path.join(ms2paths.THIRD_PARTY, "msvc9")
TREES = ["include/crt", "include/api"]


def measure():
    out = {}
    b = os.path.join(VC9, "bin")
    for d, _, files in os.walk(b):
        for f in files:
            p = os.path.join(d, f)
            out[("file", os.path.relpath(p, VC9).replace("\\", "/"))] = sha256(p)
    for t in TREES:
        p = os.path.join(VC9, t)
        n, dg = tree_digest(p) if os.path.isdir(p) else (0, "MISSING")
        out[("tree", t)] = "%d %s" % (n, dg)
    out[("version", "cl")] = banner(ms2paths.find_cl_toolset("vc9"), dict(os.environ))
    return out


def main(argv):
    got = measure()
    if "--record" in argv:
        with open(MANIFEST, "w") as f:
            f.write("# VC9 toolchain for `// MS2-TOOLSET: vc9` units (tools/msvc9/check.py --record; cl 15.00.30729.207 x64 from the\n"
                    "# WDK 7.1.0 ISO GRMWDK_EN_7600_1.ISO, headers WinDDK 7600.16385 inc/crt + inc/api). Columns: kind, path under\n"
                    "# third_party/msvc9, value. tree rows: '<file count> <sha256 of the sorted lowercase-path+hash list>'.\n")
            for k in sorted(got):
                f.write("\t".join(k) + "\t" + got[k] + "\n")
        print("wrote %s (%d rows)" % (MANIFEST, len(got)))
        return 0
    want = {}
    for line in open(MANIFEST):
        if line.startswith("#") or not line.strip():
            continue
        p = line.rstrip("\n").split("\t")
        want[tuple(p[:-1])] = p[-1]
    bad = ["%s: got %s, want %s" % (" ".join(k), got.get(k, "MISSING"), v) for k, v in sorted(want.items())
           if got.get(k, "MISSING") != v]
    bad += ["%s: not in the manifest" % " ".join(k) for k in sorted(set(got) - set(want))]
    for b in bad:
        print("DIFF " + b)
    print("vc9 toolchain: %s (%d rows, %s)" % ("OK" if not bad else "%d difference(s)" % len(bad), len(want), VC9))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
