#!/usr/bin/env python3
"""Per-unit done check for one agent (docs/RECOVERY.md sections 10 and 12). Safe to run while other agents run theirs.
Python implementation of tools/unit-check.sh for native Windows (no bash needed); on Linux unit-check.sh calls it too.

    set MS2_AGENT=<name>
    python tools/unit_check.py [--functional] [--no-clang] [--no-dll] [-v] <unit-substr> [<unit-substr> ...]

1. tools/progress.py --agent <name> --check: compiles the unit with the game flags into build/progress-<name>/, pairs and
   byte-matches it; fails unless every function in its MS2-RANGEs is matched and every vftable is OK.
2. Link check: builds build/hook-msvc-<name>/ (cl 19.16) and build/hook-clang-<name>/ (clang-cl) with ONLY this unit's .cpp
   (+ its difftest, if any) as game code, linked against build/progress-<name>/symbols.tsv. The post-link
   `ms2symobj.py --check` must print ok.
--functional: the functional gate: no stub function in the unit's ranges, every vftable paired and byte-matching, no symbol
   conflict from the unit, both DLL links OK. Without it the exact gate applies (every function byte-identical).
Exit 0 = the unit meets done criteria 1-3.
"""
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402
import heavy_lock  # noqa: E402

R = ms2paths.ROOT
NT = ms2paths.is_nt()


def say(*a, **k):
    print(*a, **k)
    sys.stdout.flush()


def run(cmd, env=None, log=None):
    """run cmd with inherited stdio (or its output into `log`), `nice`d on POSIX; returns the exit code"""
    if not NT:
        cmd = ["nice"] + cmd
    sys.stdout.flush()
    sys.stderr.flush()
    try:
        if log:
            with open(log, "a") as lf:
                return subprocess.call(cmd, env=env, stdout=lf, stderr=subprocess.STDOUT)
        return subprocess.call(cmd, env=env)
    except OSError as ex:
        say("unit-check: cannot run %s: %s" % (cmd[0], ex))
        return 127


def find_units(subs):
    """src/ms2 sources with an MS2-UNIT line whose path or unit name contains one of the substrings (same rule as progress.py)"""
    top = os.path.join(R, "src", "ms2")
    hits = []
    for d, _, files in os.walk(top):
        for f in files:
            if not f.endswith(".cpp"):
                continue
            p = os.path.join(d, f)
            with open(p, encoding="latin-1") as fh:
                txt = fh.read()
            m = re.search(r"MS2-UNIT: *([^ \r\n]*)", txt)
            if m:
                rel = os.path.relpath(p, top).replace(os.sep, "/")
                hits.append((rel, m.group(1)))
    hits.sort()
    return [rel for rel, u in hits if any(s in rel + "|" + u for s in subs)]


def has_external_thunk(obj):
    try:
        r = subprocess.run(["llvm-nm", "-g", "--defined-only", obj], capture_output=True, text=True)
    except OSError:
        return False
    return "ms2_thunk_" in r.stdout


def main(argv):
    clang, dll, verbose, func, units = True, True, [], [], []
    for a in argv:
        if a == "--no-clang":
            clang = False
        elif a == "--no-dll":
            dll = False
        elif a == "-v":
            verbose = ["-v"]
        elif a == "--functional":
            func = ["--functional"]
        elif a in ("-h", "--help"):
            say(__doc__)
            return 0
        else:
            units.append(a)
    py = ms2paths.python_exe()
    if os.environ.get("MS2_PCH") == "1":
        print("unit-check: WARNING MS2_PCH=1 drops header-defined COMDATs (ATL module ctor/dtor): do not use it for the done gate",
              file=sys.stderr)
    agent = os.environ.get("MS2_AGENT", "")
    if not agent:
        print("unit-check: set MS2_AGENT=<your agent name>", file=sys.stderr)
        return 2
    if not units:
        print("usage: MS2_AGENT=<name> %s <unit-substr>..." % sys.argv[0], file=sys.stderr)
        return 2
    srcs = find_units(units)
    if not srcs:
        print("unit-check: no src/ms2 unit matches: %s" % " ".join(units), file=sys.stderr)
        return 2
    say("unit-check [%s]: %s" % (agent, " ".join(srcs)))

    # 1. compile + bytematch (one cl at a time per agent keeps the CPU moderate)
    say("== progress.py --agent %s --check" % agent)
    env = ms2paths.toolchain_env()
    if NT:
        env["PYTHONUTF8"] = "1"
    pst = run([py, os.path.join(R, "tools", "progress.py"), "--agent", agent, "--check", "-j1"] + func + verbose + units, env=env)
    if not dll:
        return pst

    # 2. link check in the agent's own build dirs
    filt = ";".join("src/ms2/%s;hook/difftest/%s_difftest" % (f, os.path.basename(f)[:-4]) for f in srcs)
    syms = os.path.join(R, "build", "progress-%s" % agent, "symbols.tsv")
    if not os.path.isfile(syms):
        import shutil
        shutil.copyfile(os.path.join(R, "progress", "symbols.tsv"), syms)

    def build(d, toolchain, msvc):
        cenv = dict(env)
        venv = os.path.join(R, ".venv", "Scripts" if NT else "bin")
        cenv["PATH"] = venv + os.pathsep + cenv.get("PATH", os.environ.get("PATH", ""))
        ninja = [os.path.join(R, "tools", "ninja-msvc.sh")] if (msvc and not NT) else ["ninja"]
        cache = os.path.join(d, "CMakeCache.txt")
        ctxt = ""
        if os.path.isfile(cache):
            with open(cache) as cf:
                ctxt = cf.read()
        if (not os.path.isfile(os.path.join(d, "build.ninja")) or "\nMS2_GAME_FILTER:STRING=%s\n" % filt not in "\n" + ctxt
                or "\nMS2_SYMOBJ_PRUNE:BOOL=ON" not in "\n" + ctxt):
            cm = ["cmake", "-G", "Ninja", "-S", os.path.join(R, "src"), "-B", d, "-DCMAKE_TOOLCHAIN_FILE=" + toolchain,
                  "-DMS2_GAME_FILTER=" + filt, "-DMS2_SYMBOL_TSV=" + syms, "-DMS2_SYMOBJ_PRUNE=ON"]
            if NT:
                cm.append("-DMS2_WINSDK_INCLUDE=" + ms2paths.winsdk_include(env))
            log = d + ".configure.log"
            sys.stdout.flush()
            with open(log, "w") as lf:
                r = subprocess.call(cm, env=cenv, stdout=lf, stderr=subprocess.STDOUT)
            if r:
                with open(log) as lf:
                    say(lf.read(), end="")
                return False
        if run(ninja + ["-C", d, "-j2"], env=cenv) == 0:
            return True
        # a pruned ms2sym.obj only binds what the unit's objects reference; a failing link is re-run with the full table so that
        # references from library members (CRT/MFC) resolve exactly like the shared build before the check is called failed
        say("== link failed with the pruned symbol table: retrying with the full one")
        log = d + ".configure.log"
        with open(log, "a") as lf:
            ok = subprocess.call(["cmake", "-DMS2_SYMOBJ_PRUNE=OFF", d], env=cenv, stdout=lf, stderr=subprocess.STDOUT) == 0
        return ok and run(ninja + ["-C", d, "-j2"], env=cenv) == 0

    with heavy_lock.heavy():    # the DLL links (wine link.exe, clang-cl) are the other memory-heavy step
        return link_checks(agent, srcs, clang, func, pst, env, build)


def link_checks(agent, srcs, clang, func, pst, env, build):
    dst = 0
    say("== build/hook-msvc-%s (cl 19.16)" % agent)
    os.makedirs(os.path.join(R, "build"), exist_ok=True)
    tc = "toolchain-msvc1416-native.cmake" if NT else "toolchain-msvc1416-wine.cmake"
    if not build(os.path.join(R, "build", "hook-msvc-%s" % agent), os.path.join(R, "cmake", tc), True):
        dst = 1
    # hook thunks must have internal linkage: an external ms2_thunk_* COMDAT folds across units (merge 9e11067)
    for f in srcs:
        o = os.path.join(R, "build", "hook-msvc-%s" % agent, "ms2", "CMakeFiles", "ms2game.dir", f + ".obj")
        if os.path.isfile(o) and has_external_thunk(o):
            say("hook thunk with external linkage in %s (cross-unit COMDAT folding)" % f)
            dst = 1
    if clang:
        say("== build/hook-clang-%s (clang-cl)" % agent)
        if not build(os.path.join(R, "build", "hook-clang-%s" % agent), os.path.join(R, "cmake", "toolchain-clangcl-x64.cmake"), False):
            dst = 1

    say()
    if func:
        say("functional gate: OK (progress.py --functional --check passed)" if pst == 0 else
            "functional gate: NOT DONE (see above; -v for diffs)")
    else:
        say("bytematch: OK" if pst == 0 else "bytematch: NOT DONE (see above; -v for diffs)")
    say("DLL link: OK" if dst == 0 else "DLL link: FAILED")
    return 0 if pst == 0 and dst == 0 else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
