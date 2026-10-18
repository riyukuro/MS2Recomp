#!/usr/bin/env python3
"""Report #include "..." spellings in src/ that resolve only case-insensitively (fine on Windows, broken on Linux), and
backslash separators. Search order mirrors the game flags: the including file's directory, then src/, then src/hook.
Includes that resolve to nothing there (engine / SDK headers) are skipped.

  python tools/check-include-case.py [--fix]      exit 1 when a mismatch is found (and not fixed)
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src")
INC = re.compile(r'^(\s*#\s*include\s*")([^"]+)(")', re.M)
_ls = {}


def listing(d):
    if d not in _ls:
        try:
            _ls[d] = os.listdir(d)
        except OSError:
            _ls[d] = []
    return _ls[d]


def resolve(base, rel):
    """(exact, spelled) for rel under base: spelled is the on-disk spelling when it exists case-insensitively, else None."""
    cur, out, exact = base, [], True
    for part in rel.replace("\\", "/").split("/"):
        if part in ("", "."):
            continue
        if part == "..":
            cur, out = os.path.dirname(cur), out + [".."]
            continue
        names = listing(cur)
        if part in names:
            real = part
        else:
            hit = [n for n in names if n.lower() == part.lower()]
            if not hit:
                return None, None
            real, exact = hit[0], False
        cur, out = os.path.join(cur, real), out + [real]
    return exact, "/".join(out)


def main():
    fix = "--fix" in sys.argv
    bad = 0
    for d, _, files in os.walk(SRC):
        for f in files:
            if not f.endswith((".h", ".cpp", ".hpp", ".inl", ".c")):
                continue
            p = os.path.join(d, f)
            with open(p, "rb") as fh:
                raw = fh.read()
            txt = raw.decode("latin-1")
            changes = []
            for m in INC.finditer(txt):
                name = m.group(2)
                for base in (d, SRC, os.path.join(SRC, "hook")):
                    exact, spelled = resolve(base, name)
                    if spelled is None:
                        continue
                    if exact and "\\" not in name:
                        break
                    bad += 1
                    print("%s:%d: #include \"%s\" -> \"%s\"" % (os.path.relpath(p, ROOT).replace(os.sep, "/"),
                                                              txt.count("\n", 0, m.start()) + 1, name, spelled))
                    changes.append((m.start(2), m.end(2), spelled))
                    break
            if fix and changes:
                for s, e, r in sorted(changes, reverse=True):
                    txt = txt[:s] + r + txt[e:]
                with open(p, "wb") as fh:
                    fh.write(txt.encode("latin-1"))
    print("include case: %s (%d)" % ("OK" if not bad else ("fixed" if fix else "MISMATCH"), bad))
    return 0 if (not bad or fix) else 1


if __name__ == "__main__":
    sys.exit(main())
