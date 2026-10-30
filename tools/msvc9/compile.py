#!/usr/bin/env python3
"""cmake custom-command compile of a `// MS2-TOOLSET:` unit (cmake/ms2-unit-profiles.cmake ms2_unit_toolsets):

    compile.py <depfile> <cl> <cl args...>

Runs <cl> <args> /showIncludes and writes the included files as a Makefile-style depfile for ninja (DEPFILE), so the
obj rebuilds when a header changes (ninja's msvc deps mode is for the target's own compiler only). Other output passes through.
"""
import subprocess
import sys


def main(argv):
    dep, cl, args = argv[0], argv[1], argv[2:]
    obj = next((a[3:] for a in args if a.startswith(("/Fo", "-Fo"))), None)
    r = subprocess.run([cl] + args + ["/showIncludes"], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    deps = []
    for line in r.stdout.decode("latin1").splitlines():
        if line.startswith("Note: including file:"):
            deps.append(line.split(":", 2)[2].strip())
        elif line.strip():
            print(line, flush=True)
    if r.returncode == 0 and obj:
        def esc(p):
            return p.replace("\\", "/").replace(" ", "\\ ").replace("#", "\\#").replace("$", "$$")
        with open(dep, "w") as f:
            f.write(esc(obj) + ": " + " \\\n  ".join(esc(d) for d in dict.fromkeys(deps)) + "\n")
    return r.returncode


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
