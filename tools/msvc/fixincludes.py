#!/usr/bin/env python3
"""stdin -> stdout filter for cl output: put the "Note: including file:" paths in the on-disk case with '/' separators.

Wine's cl prints some included files (those reached through a differently-cased #include) all-lowercase, and ninja lowercases the
directory part of paths containing a backslash. Either way the deps ninja records name files that do not exist on case-sensitive
Linux, so every object looked out of date and was rebuilt on every run."""
import os, re, sys

_ls = {}


def _list(d):
    r = _ls.get(d)
    if r is None:
        try:
            r = {}
            for n in sorted(os.listdir(d or "/")):   # exact-case names win over lowercase alias symlinks
                k = n.lower()
                if k not in r or (os.path.islink((d or "") + "/" + r[k]) and not os.path.islink((d or "") + "/" + n)):
                    r[k] = n
        except OSError:
            r = {}
        _ls[d] = r
    return r


def fix(path):
    path = path.replace("\\", "/")
    out = ""
    for part in path.split("/")[1:]:
        real = _list(out).get(part.lower(), part)
        out += "/" + real
    return out


pat = re.compile(r"^(Note: including file:\s*)(/.*?)\s*$")
for line in sys.stdin.buffer:
    s = line.decode("latin1")
    m = pat.match(s)
    if m:
        s = m.group(1) + fix(m.group(2)) + "\n"
    sys.stdout.buffer.write(s.encode("latin1"))
    sys.stdout.buffer.flush()
