#!/usr/bin/env python3
"""Apply engine-patches/ to a stock Gamebryo tree (see tools/engine-patches.py for the format).

usage: apply_engine_patches.py <patches-dir> <gamebryo-tree>
Verifies every stock hash first, applies in memory, verifies every result hash,
and only then writes.  Refuses (exit 1, nothing written) on any mismatch.
"""
import hashlib, json, re, sys
from pathlib import Path


def sha(b):
    return hashlib.sha256(b).hexdigest()


def apply(script, data):
    lines = [] if data is None else data.split(b"\n")
    cmds, sl, i = [], script.split(b"\n"), 0
    if sl and sl[-1] == b"":
        sl.pop()
    while i < len(sl):
        c = sl[i].decode("ascii")
        i += 1
        m = re.fullmatch(r'(\d+)@(\d+)s ("(?:[^"\\]|\\.)*") ("(?:[^"\\]|\\.)*")', c)
        if m:
            cmds.append(("s", int(m[1]), int(m[2]), json.loads(m[3]).encode("latin-1"), json.loads(m[4]).encode("latin-1")))
            continue
        m = re.fullmatch(r"(\d+)(?:,(\d+))?([acd])", c)
        if not m:
            raise ValueError(f"bad command {c!r}")
        s, e, k = int(m[1]), int(m[2] or m[1]), m[3]
        text = []
        if k in "ac":
            while sl[i] != b".":
                text.append(sl[i][1:] if sl[i].startswith(b"..") else sl[i])
                i += 1
            i += 1
        cmds.append((k, s, e, text))
    for c in cmds:   # scripts are in descending order; stock line numbers stay valid
        if c[0] == "s":
            _, ln, col, so, sn = c
            L = lines[ln - 1]
            if L[col:col + len(so)] != so:
                raise ValueError(f"line {ln} col {col}: token mismatch")
            lines[ln - 1] = L[:col] + sn + L[col + len(so):]
        elif c[0] == "a":
            lines[c[1]:c[1]] = c[3]
        elif c[0] == "c":
            lines[c[1] - 1:c[2]] = c[3]
        else:
            del lines[c[1] - 1:c[2]]
    return b"\n".join(lines)


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    pd, tree = Path(sys.argv[1]), Path(sys.argv[2])
    rows = [l.split("\t") for l in (pd / "manifest.tsv").read_text(encoding="ascii").splitlines()[1:]]
    results, bad = {}, []
    for path, ssha, rsha, kind in rows:
        if kind == "withheld":
            print(f"skip (withheld, supply separately): {path}")
            continue
        tgt = tree / path
        try:
            if kind == "modified":
                data = tgt.read_bytes()
                if sha(data) != ssha:
                    bad.append(f"{path}: stock hash mismatch")
                    continue
            else:
                if tgt.exists():
                    bad.append(f"{path}: added file already exists")
                    continue
                data = None
            out = apply((pd / (path + ".ed")).read_bytes(), data)
        except Exception as ex:
            bad.append(f"{path}: {ex}")
            continue
        results[path] = (out, rsha)
    if not bad:
        for p, (out, rsha) in results.items():
            if sha(out) != rsha:
                bad.append(f"{p}: result hash mismatch")
    if bad:
        print("REFUSING, nothing written:\n  " + "\n  ".join(bad))
        sys.exit(1)
    for p, (out, _) in results.items():
        (tree / p).parent.mkdir(parents=True, exist_ok=True)
        (tree / p).write_bytes(out)
    print(f"applied {len(results)} files, all result hashes verified")


if __name__ == "__main__":
    main()
