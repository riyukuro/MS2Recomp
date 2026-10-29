"""paths of the full-exe link prototype (tools/fullexe): no machine paths, everything from the repo root or env.
  FULLEXE_DIR   work dir (obj snapshot, rsp files, link outputs, reports); default work/fullexe
  FULLEXE_TREE  merge tree whose objs/progress tables are linked; default work/merge-wt
  FULLEXE_TAG   suffix of one link's outputs: link<TAG>.log, fullexe<TAG>.exe/.map, unresolved<TAG>.txt ... (default "")
  FULLEXE_HERMETIC=1: only explicit build/ dirs and committed inputs (see _hermetic); stops with the offending path
  FULLEXE_GB_OVERLAY  ':'-separated gate output dirs (an agent's build/progress-<agent>/gb) whose objs replace the tree's
                gb objs of the same recipe/name and join the closure candidates, with their results.json pairs: an
                engine fix gated in a lane worktree links before its merge (default none)"""
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ms2paths  # noqa: E402

OUT = os.path.abspath(os.environ.get("FULLEXE_DIR") or os.path.join(ROOT, "work", "fullexe"))
TREE = os.path.abspath(os.environ.get("FULLEXE_TREE") or os.path.join(ROOT, "work", "merge-wt"))
TAG = os.environ.get("FULLEXE_TAG", "")
EXE = ms2paths.EXE
SYMBOL_TABLES = ("symbols.tsv", "symbols-manual.tsv", "symbols-engine.tsv", "symbols-engine-manual.tsv")
GB_OVERLAY = [os.path.abspath(d) for d in os.environ.get("FULLEXE_GB_OVERLAY", "").split(":") if d]


def status_tsv():
    """the tree's committed progress/status.tsv, else the one this build's compile stage wrote (first FULLEXE_OBJ_CACHES
    dir): the published mirror does not ship progress/status.tsv"""
    f = os.path.join(TREE, "progress", "status.tsv")
    caches = [c for c in os.environ.get("FULLEXE_OBJ_CACHES", "").split(":") if c]
    if not os.path.exists(f) and caches and os.path.exists(os.path.join(caches[0], "status.tsv")):
        return os.path.join(caches[0], "status.tsv")
    return f


def _hermetic():
    """FULLEXE_HERMETIC=1 (cmake/fullexe sets it; default unset: nothing checked): the build may read only committed inputs
    and an explicit output dir. Stops with the offending path instead of silently using work/ or an uncommitted file
    (FULLEXE_ALLOW_DIRTY=1 keeps the dirty-input check from stopping it)."""
    import subprocess
    work = os.path.join(ROOT, "work") + os.sep
    for var, val in (("FULLEXE_DIR", OUT), ("FULLEXE_TREE", TREE)):
        if not os.environ.get(var):
            sys.exit(f"FULLEXE_HERMETIC: {var} is not set (the default is under work/, which is not a committed input); "
                     f"set it to a build/ dir")
        if (val + os.sep).startswith(work):
            sys.exit(f"FULLEXE_HERMETIC: {var}={val} is under work/ (not committed)")
    if not os.environ.get("FULLEXE_OBJ_CACHES"):
        # plan.py and alias.py otherwise read every agent's build/progress*/results.json and obj: not the build's own tree
        sys.exit("FULLEXE_HERMETIC: FULLEXE_OBJ_CACHES is not set (plan.py/alias.py would read every build/progress*); "
                 "set it to this build's progress cache dir")
    for d in GB_OVERLAY + [c for c in os.environ.get("FULLEXE_OBJ_CACHES", "").split(":") if c]:
        if (os.path.abspath(d) + os.sep).startswith(work):
            sys.exit(f"FULLEXE_HERMETIC: cache {d} is under work/ (not committed)")
    # the engine tree the engine objs compile from must be what engine-patches/ produces: a checkout whose SDK copy was
    # patched before a later patch commit built an exe with the old KFM stream label (empty model names, no login)
    import hashlib
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import gbtree
    stale = []
    for l in open(os.path.join(TREE, "engine-patches", "manifest.tsv"), encoding="latin1"):
        p = l.rstrip("\n").split("\t")
        if len(p) < 4 or p[0] == "path" or p[3] == "sdk":
            continue
        f = os.path.join(gbtree.ENGINE, p[0])
        if not os.path.exists(f) or hashlib.sha256(open(f, "rb").read()).hexdigest() != p[2]:
            stale.append(p[0])
    if stale:
        sys.exit(f"FULLEXE_HERMETIC: {len(stale)} file(s) of {gbtree.ENGINE} differ from engine-patches/manifest.tsv "
                 f"(re-apply: tools/apply-engine-patches.sh engine-patches <stock tree>):\n  " + "\n  ".join(stale[:15]))
    # ... and every other file of it must be the stock file: stock + patches reproduces the tracked tree exactly (the
    # maintainer checkout only: a BYO engine dir, MS2_ENGINE_DIR, is not tracked, and the mirror has no engine-tree-check.py)
    check = os.path.join(ROOT, "tools", "engine-tree-check.py")
    if os.path.isdir(gbtree.PRISTINE) and os.path.exists(check) and gbtree.ENGINE == os.path.join(ROOT, "engine", "gamebryo"):
        import subprocess
        r = subprocess.run([sys.executable, "-I", check, gbtree.PRISTINE],
                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        if r.returncode:
            sys.exit("FULLEXE_HERMETIC: engine/gamebryo is not stock + engine-patches:\n" + r.stdout)
    if os.environ.get("FULLEXE_ALLOW_DIRTY"):
        return
    # modified tracked files of every input; untracked ones only where a file is read without git's say-so (src/ms2 is
    # filtered by git ls-files in plan.py, so a stray file there is ignored)
    inputs = ["engine-patches", "data/engine/units-gb.json", "data/engine/units-lib-*.json", "progress", "tools/fullexe/*.py",
              "tools/fullexe/*.tsv", "src/ms2", "cmake/fullexe"]
    dirty = []
    for extra, paths in (("--untracked-files=no", inputs), ("--untracked-files=all", ["engine-patches", "progress"])):
        r = subprocess.run(["git", "-C", TREE, "status", "--porcelain", extra, "--"] + paths, capture_output=True, text=True)
        dirty += [l for l in r.stdout.splitlines() if l.strip() and l not in dirty]
    if dirty:
        sys.exit("FULLEXE_HERMETIC: uncommitted build inputs (commit them or set FULLEXE_ALLOW_DIRTY=1):\n  "
                 + "\n  ".join(dirty[:15]) + (f"\n  ... {len(dirty) - 15} more" if len(dirty) > 15 else ""))


if os.environ.get("FULLEXE_HERMETIC"):
    _hermetic()
os.makedirs(OUT, exist_ok=True)


def copy_new(src, dst, copy=None):
    """copy src over dst without writing through a symlink at dst (a snapshot obj may link into another lane's dir)"""
    import shutil
    if os.path.lexists(dst):
        os.unlink(dst)
    (copy or shutil.copy)(src, dst)


def tagged(name):
    """<OUT>/<name> with TAG inserted before the extension for per-link outputs"""
    b, e = os.path.splitext(name)
    return os.path.join(OUT, b + TAG + e)


def wine(path):
    """z:\\ form of a host path (MSVC under wine)"""
    return "z:" + os.path.abspath(path).replace("/", "\\")


def coff_externals(path):
    """(defined, undefined) external symbol names of a COFF obj (bigobj too); commons and weak externals count as
    neither"""
    defs, undefs = set(), set()
    with open(path, "rb") as f:
        h = f.read(56)
        s1, s2 = struct.unpack_from("<HH", h, 0)
        if s1 == 0 and s2 == 0xFFFF:
            symoff, nsym = struct.unpack_from("<II", h, 48); sz, fmt = 20, "<i"
        else:
            symoff, nsym = struct.unpack_from("<II", h, 8); sz, fmt = 18, "<h"
        f.seek(symoff); tab = f.read(nsym * sz)
        strsz, = struct.unpack("<I", f.read(4) or b"\4\0\0\0"); strs = f.read(max(0, strsz - 4))
    i = 0
    while i < nsym:
        o = i * sz
        value, = struct.unpack_from("<I", tab, o + 8)
        sec, = struct.unpack_from(fmt, tab, o + 12)
        scl, naux = tab[o + sz - 2], tab[o + sz - 1]
        if scl == 2 and (sec != 0 or value == 0):
            if tab[o:o + 4] == b"\0\0\0\0":
                so = struct.unpack_from("<I", tab, o + 4)[0] - 4
                n = strs[so:strs.index(b"\0", so)]
            else:
                n = tab[o:o + 8].rstrip(b"\0")
            (defs if sec != 0 else undefs).add(n.decode("latin1"))
        i += 1 + naux
    return defs, undefs


def udt_return_abi(names):
    """{name: "member" | "free"} for the mangled functions in names that return a class/struct/union by value (llvm-undname):
    a non-static member takes the hidden return pointer in rdx (this in rcx), a free or static function in rcx, so a
    free declaration of a member (`CString FUN_<va>(void* pThis)`) bound to the member's definition swaps the two"""
    import subprocess
    names = list(names)
    if not names:
        return {}
    out = subprocess.run(["llvm-undname"], input="\n".join(names) + "\n", capture_output=True, text=True,
                         errors="replace").stdout.split("\n")
    res = {}
    want = set(names)
    for n, d in zip(out, out[1:]):                       # llvm-undname echoes each input line, then its demangling
        if n not in want:
            continue
        m = re.match(r"(?:(public|private|protected): )?(?:(virtual|static) )?(?:class|struct|union) (.*?) __\w+ ", d)
        if not m or m.group(3).rstrip().endswith(("*", "&")):
            continue
        res[n] = "member" if m.group(1) and m.group(2) != "static" else "free"
    return res


def cri_any_shift(pairs):
    """the (unresolved, definition) pairs whose definition is a free function returning cri_any (the CRI vendor shim's
    any-scalar type: its constructors make MSVC return it through a hidden pointer in rcx) while the declaration is a
    free function returning a scalar in rax with at most 3 arguments: shim.py's shift adapter slides the arguments one
    register right, passes a stack slot as the return pointer and loads rax from it"""
    import subprocess
    names = sorted({x for p in pairs for x in p})
    if not names:
        return set()
    out = subprocess.run(["llvm-undname"], input="\n".join(names) + "\n", capture_output=True, text=True,
                         errors="replace").stdout.split("\n")
    want, dem = set(names), {}
    for n, d in zip(out, out[1:]):
        if n in want:
            dem[n] = d

    def nargs(d):
        """top-level parameter count of a demangled free function (None: not one)"""
        if not d.endswith(")") or d.startswith(("public:", "private:", "protected:")):
            return None
        depth, i = 0, len(d) - 1
        while i >= 0:
            depth += {")": 1, ">": 1, "(": -1, "<": -1}.get(d[i], 0)
            if depth == 0:
                break
            i -= 1
        args = d[i + 1:-1]
        if args in ("", "void"):
            return 0
        depth, n = 0, 1
        for ch in args:
            depth += {"(": 1, "<": 1, ")": -1, ">": -1}.get(ch, 0)
            n += ch == "," and depth == 0
        return n

    res = set()
    for s, d in pairs:
        ds, dd = dem.get(s, ""), dem.get(d, "")
        if not dd.startswith("struct cri_any __cdecl ") or nargs(dd) is None:
            continue
        k = nargs(ds)
        if k is None or k > 3 or re.match(r"(?:class|struct|union) ", ds) and not ds.split(" __")[0].endswith("*"):
            continue
        res.add((s, d))
    return res
