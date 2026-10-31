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
3. Fullexe precheck (tools/fullexe/precheck.py): relinks the last published latest build (inputs kept by
   tools/fullexe/latest-sidecar.sh) with the unit's fresh cl 19.16 obj and fails on a new LNK2005 or a new trap stub, which
   the DLL link cannot see. Runs for units whose source or headers differ from that build's commit (or under an
   MS2_UNIT_SOURCE scratch copy); MS2_FULLEXE_PRECHECK=0 turns it off, =1 runs it for every unit. Skipped (not failed)
   when no baseline inputs exist.
4. ADDR64 check (tools/addr64check.py): the unit's cl 19.16 hook objects may not hold a static pointer (an ADDR64 in a
   data section) to a global that the merge's symbol tables bind to the exe; the merge's `ms2symobj.py --check` rejects
   the DLL for it, but the gate's DLL drops such data under /OPT:REF when nothing in the unit calls its function
   (sfr_gfx_07h, merge 45). It also scans the published build's game objects for the symbols-manual rows added or
   rebound since that build (sfr_render_06e after 4418b8cd5). MS2_ADDR64_CHECK=0 turns it off.
--functional: the functional gate: no stub function in the unit's ranges, every vftable paired and byte-matching, no symbol
   conflict from the unit, both DLL links OK. Without it the exact gate applies (every function byte-identical).
Exit 0 = the unit meets done criteria 1-4.
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
    # one heavy slot for the whole gate (progress.py and the DLL links): taken twice, every gate queued again between the
    # steps behind the other agents' runs (2026-10-31, the last 16 gates with the precheck: median wall 444 s = progress.py
    # 84 + precheck 16 + 289 from the slot release to the end, of which the two ninja builds took ~40 s: ~250 s queueing).
    # progress.py and precheck.py see MS2_HEAVY_HELD and do not re-acquire.
    with heavy_lock.heavy():
        return gate(agent, srcs, units, py, clang, dll, func, verbose)


def gate(agent, srcs, units, py, clang, dll, func, verbose):
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
        # experiment overrides of `// MS2-TOOLSET:` (cmake/ms2-unit-profiles.cmake); a cache without the entry has them empty
        over = [(v, cenv.get(v, "").strip()) for v in ("MS2_UNIT_TOOLSET", "MS2_UNIT_SOURCE")]
        stale = [v for v, val in over if ("\n%s:STRING=%s\n" % (v, val) not in "\n" + ctxt + "\n"
                                         and (val or "\n%s:STRING=" % v in "\n" + ctxt))]
        if (not os.path.isfile(os.path.join(d, "build.ninja")) or "\nMS2_GAME_FILTER:STRING=%s\n" % filt not in "\n" + ctxt
                or "\nMS2_SYMOBJ_PRUNE:BOOL=ON" not in "\n" + ctxt or stale):
            cm = ["cmake", "-G", "Ninja", "-S", os.path.join(R, "src"), "-B", d, "-DCMAKE_TOOLCHAIN_FILE=" + toolchain,
                  "-DMS2_GAME_FILTER=" + filt, "-DMS2_SYMBOL_TSV=" + syms, "-DMS2_SYMOBJ_PRUNE=ON"]
            cm += ["-D%s=%s" % (v, val) for v, val in over if val or v in stale]
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

    ast = addr64_check(agent, srcs, env)
    fst = fullexe_precheck(agent, srcs, env)

    say()
    if func:
        say("functional gate: OK (progress.py --functional --check passed)" if pst == 0 else
            "functional gate: NOT DONE (see above; -v for diffs)")
    else:
        say("bytematch: OK" if pst == 0 else "bytematch: NOT DONE (see above; -v for diffs)")
    say("DLL link: OK" if dst == 0 else "DLL link: FAILED")
    if ast is not None:
        say("ADDR64 check: OK" if ast == 0 else "ADDR64 check: FAILED (static pointers to exe globals above)")
    if fst is not None:
        say("fullexe precheck: OK" if fst == 0 else "fullexe precheck: FAILED (new LNK2005 / trap stubs above)")
    return 0 if pst == 0 and dst == 0 and not ast and not fst else 1


def addr64_check(agent, srcs, env):
    """tools/addr64check.py on the unit's cl 19.16 hook objects and the symbols-manual rows new since the published
    build (None = not run)"""
    if os.environ.get("MS2_ADDR64_CHECK", "") == "0":
        return None
    import glob
    d = os.path.join(R, "build", "hook-msvc-%s" % agent, "ms2")
    objs = []
    for f in srcs:
        objs += [o for o in [os.path.join(d, "CMakeFiles", "ms2game.dir", f + ".obj")] if os.path.isfile(o)]
        objs += sorted(glob.glob(os.path.join(d, "toolset-*", f[:-4] + ".obj")))    # MS2-TOOLSET units
    tables = [os.path.join(R, "progress", "symbols-engine.tsv"), os.path.join(R, "progress", "symbols.tsv"),
              os.path.join(R, "build", "progress-%s" % agent, "symbols.tsv"),
              os.path.join(R, "progress", "symbols-manual.tsv")]
    cmd = [ms2paths.python_exe(), os.path.join(R, "tools", "addr64check.py")]
    for t in tables:
        cmd += ["--table", t]
    snap = os.path.join(R, "work", "fx29", "fx", "latest-inputs", "current")
    if os.path.exists(os.path.join(snap, "commit")):
        cmd += ["--manual-since", snap] + ["--skip=" + f[:-4] for f in srcs]
    say("== ADDR64 check: %d object(s)%s" % (len(objs), " + symbols-manual rows new since the published build"
                                              if "--manual-since" in cmd else ""))
    return run(cmd + objs, env=env)


def fullexe_precheck(agent, srcs, env):
    """tools/fullexe/precheck.py for the units that differ from the baseline build (None = not run)"""
    mode = os.environ.get("MS2_FULLEXE_PRECHECK", "")
    snap = os.path.join(R, "work", "fx29", "fx", "latest-inputs", "current")
    if mode == "0" or NT:
        return None
    if not os.path.exists(os.path.join(snap, "commit")):
        say("== fullexe precheck: skipped, no baseline inputs (%s)" % snap)
        return None
    base = open(os.path.join(snap, "commit")).read().strip()
    cache = os.path.join(R, "build", "progress-%s" % agent)
    scratch = os.environ.get("MS2_UNIT_SOURCE", "").strip()
    run_for = []
    for f in srcs:
        obj = os.path.join(cache, "obj", f[:-4] + ".obj")
        stem = os.path.basename(f)[:-4]
        paths = [os.path.join("src", "ms2", f)]
        try:
            import json
            with open(obj[:-4] + ".deps") as df:
                paths += [os.path.relpath(d, R) for d in json.load(df).get("deps", [])
                          if os.path.abspath(d).startswith(R + os.sep)]
        except (OSError, ValueError):
            pass
        changed = subprocess.call(["git", "-C", R, "diff", "--quiet", base, "--"] + paths,
                                  stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL) != 0
        if mode == "1" or changed or ("%s=" % stem) in scratch:
            run_for.append(f)
    if not run_for:
        say("== fullexe precheck: skipped, no unit differs from the baseline %s" % base[:12])
        return None
    say("== fullexe precheck vs %s: %s" % (base[:12], " ".join(run_for)))
    return run([ms2paths.python_exe(), os.path.join(R, "tools", "fullexe", "precheck.py"), "--cache", cache] + run_for, env=env)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
