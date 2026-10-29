#!/usr/bin/env python3
"""Emit fmt-patches/: our edits to cppformat (fmt) as ed-style scripts, upstream commit 5ca3d00e2 -> engine/fmt-ms2.

Same script and manifest format as engine-patches/ (tools/engine-patches.py), so tools/apply-engine-patches.sh applies it:
the BYO user copies upstream fmt 5ca3d00e2 (format.cc, format.h; BSD 2-clause, its licence notice stays in both files)
to <MS2_ENGINE_DIR>/fmt-ms2 and runs `tools/apply-engine-patches.sh fmt-patches <that dir>`. engine/fmt-ms2 itself is
not published.

usage: fmt-patches.py [--upstream DIR] [--out DIR]   (default upstream: third_party/src/fmt-git-5ca3d00e2)
"""
import argparse, importlib.util, os, sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
FILES = ("format.cc", "format.h")
_spec = importlib.util.spec_from_file_location("engine_patches", ROOT / "tools" / "engine-patches.py")
EP = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(EP)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--upstream", default=os.path.join(ms2paths.THIRD_PARTY, "src", "fmt-git-5ca3d00e2"))
    ap.add_argument("--fork", default=os.path.join(ms2paths.ENGINE_DIR, "fmt-ms2"))
    ap.add_argument("--out", default=str(ROOT / "fmt-patches"))
    a = ap.parse_args()
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    pol = EP.load_policy(Path("/nonexistent"))
    man, stats = [], []
    for f in FILES:
        old, new = (Path(a.upstream) / f).read_bytes(), (Path(a.fork) / f).read_bytes()
        (out / (f + ".ed")).write_bytes(EP.diff_script(f, old, new, pol, stats))
        man.append((f, EP.sha(old), EP.sha(new), "modified"))
    # fmt's licence notice (the comment block heading upstream format.h), shipped with the patches derived from it
    h = (Path(a.upstream) / "format.h").read_text()
    (out / "LICENSE.fmt").write_text(h[h.index("/*") + 2:h.index("*/")].strip("\n") + "\n")
    with open(out / "manifest.tsv", "w") as fh:
        fh.write("path\tstock_sha256\tresult_sha256\tkind\tsource\n")
        for m in man:
            fh.write("\t".join(m) + "\n")
    print(f"fmt-patches: {len(man)} files -> {out}")


if __name__ == "__main__":
    main()
