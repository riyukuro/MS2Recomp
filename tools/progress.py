#!/usr/bin/env python3
"""Recovery progress: compile every recovered unit with the game flags, pair its functions with exe VAs, byte-match.

    .venv/bin/python tools/progress.py                 # incremental: only units whose obj/deps changed are re-matched
    .venv/bin/python tools/progress.py --force         # everything
    .venv/bin/python tools/progress.py md5checksum     # only units whose path contains this (others keep cached rows)
    .venv/bin/python tools/progress.py -v uicutscene   # print the bytematch report of every non-matching function

A unit is a src/ms2/**/*.cpp with a header block (docs/RECOVERY.md):
    // MS2-UNIT: client\\ms2\\uicutscenemovie.cpp          original CU (path below ms2code\\)
    // MS2-RANGE: 0x14190eac0-0x141910480 .text$mn         exe address ranges owned by the unit (any number;
    // MS2-RANGE: 0x140111d60-0x140111f00 .text$di         .text$mn, the dynamic initializers, the atexit thunks)
and `// @0x<va>` tags on the line(s) directly above function definitions (in the .cpp or in headers for inline
member functions). Pairing obj symbol -> exe VA:
  1. tag: the function's first line (CodeView line table of the /Z7 obj) has a tag at most 6 lines above it;
  2. auto: a function symbol without tag whose bytes (relocations masked) equal exactly one exe function of the same
     length inside the unit's ranges (COMDATs: STL/ATL instantiations, dynamic initializers, atexit thunks);
  3. vftables ??_7Class@@6B...@ are paired through RTTI (work/classes/rtti_*.tsv) and checked slot by slot.
Every paired function is byte-matched (tools/bytematch.py, incl. unwind/EH data and the symbol map).

Outputs (committed):
  progress/status.tsv    va, name, unit, state, size   for every exe function inside a unit range;
                         state = matched | functional (paired, compiles, not byte-identical) | stub (not recovered)
  progress/symbols.tsv   symbol -> VA map harvested from matched functions/vftables (bytematch --symbols/--harvest,
                         tools/ms2symobj.py for the hook DLL link)
  progress/summary.txt   per unit and overall: functions and bytes matched
Cache: build/progress/ (objs, /showIncludes deps, per-unit results keyed by obj mtime).

Engine stage (tools/gbprogress.py): the Gamebryo TUs of engine/units-gb.json are compiled into <cache>/gb/ (same
incremental rules) and paired by symbol name / unique masked bytes; every engine-band function they byte-match (or pair)
becomes a status.tsv row with unit gb:<Lib>/<TU> (state matched | functional, plus stub gap-fills), summarised at the
end of summary.txt. Engine functions never enter the hook DLL. Runs with every full pass; `--engine` forces it when
unit filters are given, `--no-engine` reuses the cached engine results.

Parallel agents (docs/RECOVERY.md section 12): `--agent NAME` or MS2_AGENT=NAME selects a private cache
build/progress-NAME/ and REPORT MODE: progress/* is never written. status.tsv / summary.txt go to the agent dir, and
build/progress-NAME/symbols.tsv = committed progress/symbols.tsv + the harvest of the units in the agent's cache (the
symbol table of the agent's hook build, tools/unit-check.sh). `--report` gives report mode without an agent name
(cache build/progress-report/). Only the merge step (no agent, no --report) writes progress/*.
"""
import argparse
import bisect
import contextlib
import hashlib
import io
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import bytematch as bm  # noqa: E402
import ms2paths  # noqa: E402
import gbprogress  # noqa: E402
import ms2flags  # noqa: E402  (`// MS2-FLAGS: <profile>` per-unit flags, cmake/ms2-unit-profiles.cmake)
import sf_sdk_guard  # noqa: E402  (MS2-FLAGS: scaleform units must not include SDK headers)
import mergekey  # noqa: E402

SRC = os.path.join(ROOT, "src")
GAME = os.path.join(SRC, "ms2")
OUT = os.path.join(ROOT, "progress")
CACHE = os.path.join(ROOT, "build", "progress")
CL = ms2paths.find_cl()
FUNCS = ms2paths.FUNCTIONS_TSV
UNITS = ms2paths.UNITS_TSV
RTTI_CLASSES = ms2paths.RTTI_CLASSES
RTTI_VFTABLES = ms2paths.RTTI_VFTABLES

# cmake/ms2-game-flags.cmake (MS2_GAME_COMPILE_OPTIONS + _DEFINITIONS + C++14) + /MD /Z7 + the ms2game include dirs.
GAME_FLAGS = ["/nologo", "/c", "/Od", "/Ob0", "/Oi", "/EHsc", "/GS", "/GR", "/Gy", "/fp:fast", "/Zc:wchar_t",
              "/Zc:threadSafeInit", "/std:c++14", "/MD", "/Z7", "/W3", "/D_MBCS", "/D_AFXDLL",
              "/I" + SRC, "/I" + os.path.join(SRC, "hook")]


def engine_flags():
    """Gamebryo include dirs + defines for the game code, parsed from cmake/ms2-engine-flags.cmake (one source of truth with
    src/ms2/CMakeLists.txt), plus the DirectX SDK overlay (symlinks to the June 2010 headers the Windows SDK lacks; the
    same rule as that cmake file, kept in build/ms2-engine-dxsdk*)."""
    txt = open(os.path.join(ROOT, "cmake", "ms2-engine-flags.cmake")).read()

    def listing(name):
        out = re.findall(r'"([^"]+)"', re.search(r"set\(" + name + r"\n(.*?)\n\)", txt, re.S).group(1))
        if os.environ.get("MS2_PHYSX") == "283":   # fall back to the PhysX 2.8.3 headers (cmake: -DMS2_PHYSX_VERSION=283)
            out = [d.replace("physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/",
                             "physx283/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.3/") for d in out]
        return out
    eng = os.path.join(ms2paths.ENGINE_DIR, "gamebryo")
    over = os.path.join(ROOT, "build", "ms2-engine-dxsdk")
    pref = over + "-preferred"
    dx = os.path.join(ms2paths.THIRD_PARTY, "dxsdk", "DXSDK", "Include")
    wk = ms2paths.winsdk_include()
    if not os.path.isdir(over):
        os.makedirs(over, exist_ok=True)
        os.makedirs(pref, exist_ok=True)
        shadow = {f.lower() for sub in ("um", "shared") for f in os.listdir(os.path.join(wk, sub))}
        for h in os.listdir(dx):
            if h.lower() not in shadow:
                for n in {h, h.lower()}:
                    if not os.path.lexists(os.path.join(over, n)):
                        ms2paths.link_or_copy(os.path.join(dx, h), os.path.join(over, n))
        for n in ("XInput.h", "xinput.h"):
            if not os.path.lexists(os.path.join(pref, n)):
                ms2paths.link_or_copy(os.path.join(dx, "XInput.h"), os.path.join(pref, n))
    return (["/I" + pref] + ["/I" + os.path.join(eng, d) for d in listing("MS2_ENGINE_INCLUDE_DIRS")] + ["/I" + over]
            + ["/D" + d for d in listing("MS2_ENGINE_DEFINITIONS")])


GAME_FLAGS += engine_flags()


def scaleform_flags():
    """Scaleform SDK includes/defines (cmake/ms2-scaleform-sdk.cmake: same default path, same lists). Off when the SDK dir is
    absent or MS2_SCALEFORM_SDK is set empty in the environment; then gfxvalue.h uses its placeholders."""
    sdk = os.environ.get("MS2_SCALEFORM_SDK", ms2paths.SCALEFORM_SDK)
    if not sdk or not os.path.isdir(sdk):
        return []
    txt = open(os.path.join(ROOT, "cmake", "ms2-scaleform-sdk.cmake")).read()

    def listing(name):
        return re.findall(r'"([^"]+)"', re.search(r"set\(" + name + r"\n(.*?)\n\)", txt, re.S).group(1))
    # Scaleform 4.1.18 compatibility headers (GFx_Player.h, GFx_Loader.h, GFxConfig.h) generated from the SDK by
    # tools/sf418_headers.py, searched before the SDK; cmake runs the same script. /DMS2_SF418=<id of the generated
    # text> makes FLAGS_KEY (and cmake's flags) change with them, since SDK headers are not in the deps lists.
    sf418 = os.path.join(ROOT, "build", "ms2-sf418")
    import sf418_headers
    sf418_id = sf418_headers.generate(sdk, sf418)
    return (["/I" + sf418] + ["/I" + os.path.join(sdk, d) for d in listing("MS2_SCALEFORM_INCLUDE_DIRS")]
            + ["/D" + d for d in listing("MS2_SCALEFORM_DEFINITIONS")] + ["/DMS2_SF418=" + sf418_id])


GAME_FLAGS += scaleform_flags()
FLAGS_KEY = " ".join(GAME_FLAGS) + " v3"
import ms2pch  # noqa: E402  (opt-in MS2_PCH=1)
if ms2pch.enabled():
    FLAGS_KEY += " pch1"
TAG_RE = re.compile(r"//\s*@0x([0-9a-fA-F]+)\b")
TAG_WINDOW = 6


# ----------------------------------------------------------------------------------------------------------------
# units

class Unit:
    def __init__(self, path):
        self.path = path
        self.rel = os.path.relpath(path, GAME).replace("\\", "/")
        self.name = None
        self.ranges = []
        self.guess = bool(os.environ.get("MS2_GUESS_LOOKALIKES"))   # `// MS2-GUESS-LOOKALIKES`: pair leftover identical groups (functional)
        self.pins = {}       # `// MS2-PIN: <mangled> 0x<va>`: obj symbol -> exe VA (must lie in a MS2-RANGE)
        self.profile = None  # `// MS2-FLAGS: <profile>`: per-unit flag profile (ms2flags; None = game flags)
        for line in open(path, encoding="latin1"):
            if "MS2-" not in line:                    # every directive below contains it (find_units reads ~470 files)
                continue
            m = re.match(r"\s*//\s*MS2-PIN:\s*(\S+)\s+0x([0-9a-fA-F]+)", line)
            if m:
                self.pins[m.group(1)] = int(m.group(2), 16)
            if re.match(r"\s*//\s*MS2-GUESS-LOOKALIKES\b", line):
                self.guess = True
            m = re.match(r"\s*//\s*MS2-UNIT:\s*(\S+)", line)
            if m:
                self.name = m.group(1)
            if self.profile is None and re.match(r"\s*//\s*MS2-FLAGS:", line):
                self.profile = ms2flags.profile_of(line)
            m = re.match(r"\s*//\s*MS2-RANGE:\s*0x([0-9a-fA-F]+)\s*-\s*0x([0-9a-fA-F]+)", line)
            if m:
                self.ranges.append((int(m.group(1), 16), int(m.group(2), 16)))
        self.obj = os.path.join(CACHE, "obj", self.rel[:-4] + ".obj")
        self.deps = self.obj[:-4] + ".deps"

    def in_range(self, va):
        return any(a <= va < b for a, b in self.ranges)


# ----------------------------------------------------------------------------------------------------------------
# source lint (functional gate; docs/RECOVERY.md "Functional tier: source lint")

def _strip_code(text):
    """Blank comments and string/char literals (keeping line structure) so rules only see code."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i)); i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", text[i:j])); i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            out.append(c + " " * (j - i - 2) + c if j - i >= 2 else c); i = j
        else:
            out.append(c); i += 1
    return "".join(out)


def lint_unit(u):
    """Return [(file, line, rule, text)] for the unit's .cpp and its same-stem / quoted-include unit-local .h files."""
    files = [u.path]
    d = os.path.dirname(u.path)
    stem = os.path.splitext(os.path.basename(u.path))[0]
    for m in re.finditer(r'^\s*#\s*include\s+"([^"/]+\.h)"', open(u.path, encoding="latin1").read(), re.M):
        q = os.path.join(d, m.group(1))
        if os.path.exists(q) and os.path.splitext(m.group(1))[0].split("_")[0] == stem.split("_")[0]:
            files.append(q)
    hits = []
    for f in dict.fromkeys(files):
        raw = open(f, encoding="latin1").read()
        code = _strip_code(raw)
        rl, cl = raw.split("\n"), code.split("\n")
        rel = os.path.relpath(f, ROOT)
        for i, line in enumerate(cl, 1):
            if re.search(r"\bundefined[1248]?\b", line):
                hits.append((rel, i, "ghidra-type", rl[i - 1].strip()))
            if not re.search(r"\bMS2_[A-Z_]+\s*\(", line):
                for m in re.finditer(r"\b0[xX]([0-9a-fA-F]{9})(?:[uUlL]{0,3})\b", line):
                    if 0x140000000 <= int(m.group(1), 16) < 0x144000000:
                        hits.append((rel, i, "exe-address-literal", rl[i - 1].strip()))
                        break
            if re.search(r"\b(?:param_\d+|[a-z]{1,3}Var\d+|local_[0-9a-f]+|in_stack_[0-9a-f]+|extraout_\w+|unaff_\w+)\b", line):
                hits.append((rel, i, "ghidra-name", rl[i - 1].strip()))
            # `*(i64*)(node + 0x18)`, `(i64)(p) + (o)` (incl. Q8-style macros): use typed members
            if re.search(r"\(\s*\w+\s*\*+\s*\)\s*\(\s*\w+\s*\+\s*0[xX][0-9a-fA-F]+\s*\)", line) or re.search(
                    r"\(\s*(?:i64|u64|__int64|INT_PTR|UINT_PTR|LONG_PTR|ULONG_PTR|intptr_t|uintptr_t|long\s+long)\s*\)\s*\(?\s*\w+\s*\)?\s*\+\s*\(?\s*(?:0[xX][0-9a-fA-F]+|\d+|\w+)\s*\)?\s*\)", line):
                hits.append((rel, i, "raw-ptr-offset", rl[i - 1].strip()))
            if re.search(r"\b\w+\s*\(\s*\.\.\.\s*\)", line) and not re.search(r"\b(?:if|while|for|switch|sizeof|defined|catch)\s*\(\s*\.\.\.", line):
                hits.append((rel, i, "variadic-callee", rl[i - 1].strip()))
            # `(char*)this + 0x20`: use the class's own members
            if re.search(r"\(\s*(?:const\s+)?(?:char|unsigned\s+char|BYTE|uint8_t|uintptr_t)\s*\*\s*\)\s*this\s*\+", line):
                hits.append((rel, i, "raw-this-offset", rl[i - 1].strip()))
            # `*(char**)p + 0x88` / `+ slot * 8`: call through a declared virtual (real engine headers, placeholder slots)
            if re.search(r"\*\s*\(\s*char\s*\*\*\s*\)\s*\(?\s*\w+\s*\)?\s*\)?\s*\+", line):
                hits.append((rel, i, "raw-vtable-call", rl[i - 1].strip()))
        # registration statics: self-registering Gamebryo objects must be #ifdef MS2_STANDALONE (hook-DLL copies
        # would register into the exe's shared registries)
        stack = []  # per open #if: is the CURRENT branch compiled only in a non-hook-DLL (standalone / progress.py) build
        for i, line in enumerate(cl, 1):
            m = re.match(r"\s*#\s*(if|ifdef|ifndef|else|elif|endif)\b\s*(.*)", line)
            if m:
                d, arg = m.group(1), m.group(2).strip()
                if d in ("if", "ifdef", "ifndef"):
                    neg = d == "ifndef" or (d == "if" and arg.startswith("!"))
                    if "MS2_HOOK_DLL" in arg:
                        stack.append((neg, neg))        # (current branch guarded, true-branch guarded)
                    elif "MS2_STANDALONE" in arg:
                        stack.append((not neg, not neg))
                    else:
                        stack.append((False, None))
                elif d == "else" and stack:
                    g, tg = stack[-1]
                    stack[-1] = (False if tg is None else not tg, tg)
                elif d == "endif" and stack:
                    stack.pop()
                continue
            if not any(g for g, _ in stack) and re.match(r"\s*(?:EE_HANDLER\w*|RegisterLoader\w*)\s*\(", line):
                hits.append((rel, i, "registration-static", rl[i - 1].strip()))
        # forwarder: inside the function tagged `// @0xX`, a use of FUN_X beyond the definition's own name
        tags = [(i, m.group(1)) for i, l in enumerate(rl) if (m := re.match(r"\s*//\s*@0x([0-9a-fA-F]+)\s*$", l))]
        for k, (i, va) in enumerate(tags):
            end = tags[k + 1][0] if k + 1 < len(tags) else len(cl)
            seg = "\n".join(l for l in cl[i + 1:end] if not re.search(r"\bMS2_[A-Z_]+\s*\(", l))
            pat = r"\bFUN_0*%s\b" % va.lower().lstrip("0")
            head, _, body = seg.partition("{")
            if body and not re.search(pat, head, re.I) and re.search(pat + r"\s*\(", body, re.I):
                hits.append((rel, i + 1, "forwarder", f"function @0x{va} calls FUN_{va}"))
    return hits


def find_units(filters):
    out = []
    for d, _, files in os.walk(GAME):
        for f in sorted(files):
            if f.endswith(".cpp"):
                u = Unit(os.path.join(d, f))
                if not u.name:
                    continue
                if filters and not any(x in u.rel or x in u.name for x in filters):
                    continue
                out.append(u)
    return sorted(out, key=lambda u: u.rel)


def winpath(p):
    return p


_case = {}


def unixpath(p):
    """Wine cl reports paths as z:\\... and (in CodeView) lowercased: map back to the real file under ROOT."""
    p = ms2paths.host_path(p)
    if os.path.exists(p):
        return p
    if not _case:
        for top in (SRC, ms2paths.ENGINE_DIR):
            for d, _, files in os.walk(top):
                for f in files:
                    q = os.path.join(d, f)
                    _case[q.lower()] = q
    return _case.get(p.lower(), p)


def needs_compile(u):
    if not os.path.exists(u.obj) or not os.path.exists(u.deps):
        return True
    try:
        meta = json.load(open(u.deps))
    except Exception:
        return True
    if meta.get("flags") != FLAGS_KEY + ms2flags.key(u.profile):
        return True
    t = os.path.getmtime(u.obj)
    for f in [u.path] + meta.get("deps", []):
        if not os.path.exists(f) or os.path.getmtime(f) > t:
            return True
    return False


def compile_unit(u):
    os.makedirs(os.path.dirname(u.obj), exist_ok=True)
    env = ms2paths.toolchain_env()
    flags = ms2flags.apply(GAME_FLAGS, u.profile)
    pch = ms2pch.args(GAME_FLAGS, open(u.path, encoding="latin1").read(), CL, env) if not u.profile else []
    cmd = ms2paths.cl_cmdline([CL] + flags + pch + ["/showIncludes", "/Fo" + u.obj, u.path])
    t0 = time.time()
    r = subprocess.run(cmd, capture_output=True, text=True, env=env, encoding="latin1")
    deps, msgs, included = [], [], []
    for line in (r.stdout + r.stderr).splitlines():
        if line.startswith("Note: including file:"):
            f = unixpath(line.split(":", 2)[2])
            included.append(f)
            if ms2paths.under(f, SRC) or ms2paths.under(f, ms2paths.ENGINE_DIR):
                deps.append(f)
        elif line.strip() and line.strip() != os.path.basename(u.path) and "_WIN32_WINNT not defined" not in line:
            msgs.append(line)
    ok = r.returncode == 0 and os.path.exists(u.obj)
    if ok and u.profile == "scaleform":
        # the recovered Scaleform builds without the SDK (tools/sf_sdk_guard.py, docs/RECOVERY.md section 2)
        bad = ["%s: opens SDK header %s" % (u.rel, f) for f in sf_sdk_guard.sdk_includes(included)]
        for f in [u.path] + [d for d in deps if ms2paths.under(d, sf_sdk_guard.SF_SRC)]:
            bad += ["%s:%d: SDK include %s" % (os.path.relpath(f, ROOT), n, name) for n, name in sf_sdk_guard.scan_file(f)]
        if bad:
            msgs += ["sf_sdk_guard: " + b for b in sorted(set(bad))]
            ok = False
    if ok and pch:
        deps.append(os.path.join(SRC, ms2pch.HDR))
    if ok:
        json.dump({"flags": FLAGS_KEY + ms2flags.key(u.profile), "deps": sorted(set(deps))}, open(u.deps, "w"))
    elif os.path.exists(u.obj):
        os.remove(u.obj)
    return ok, msgs, time.time() - t0


# ----------------------------------------------------------------------------------------------------------------
# CodeView line tables (C13: .debug$S subsections 0xf2 lines, 0xf4 file checksums, 0xf3 strings)

def cv_first_lines(obj):
    """{function symbol name: (source path, first line)}"""
    strings, checks, pending = {}, {}, []
    for sn, s in enumerate(obj.sections, 1):
        if s["name"] != ".debug$S":
            continue
        d = s["data"]
        if len(d) < 4 or struct.unpack_from("<I", d, 0)[0] != 4:
            continue
        rel = {va: si for va, si, ty in s["relocs"]}
        o = 4
        while o + 8 <= len(d):
            typ, ln = struct.unpack_from("<II", d, o)
            body = o + 8
            if typ == 0xF3:
                strings[sn] = d[body:body + ln]
            elif typ == 0xF4:
                checks[sn] = d[body:body + ln]
            elif typ == 0xF2 and ln >= 12:
                si = rel.get(body)
                fb = body + 12
                if si is not None and fb + 12 <= body + ln:
                    fileid, nlines, _ = struct.unpack_from("<III", d, fb)
                    if nlines:
                        off, val = struct.unpack_from("<II", d, fb + 12)
                        pending.append((obj.syms[si][0], fileid, val & 0xFFFFFF))
            o = body + ln
            o = (o + 3) & ~3
    if not checks or not strings:
        return {}
    ck = next(iter(checks.values()))
    st = next(iter(strings.values()))
    out = {}
    for name, fileid, line in pending:
        if fileid + 4 > len(ck):
            continue
        so = struct.unpack_from("<I", ck, fileid)[0]
        e = st.index(b"\0", so)
        out.setdefault(name, (unixpath(st[so:e].decode("latin1")), line))
    return out


_tag_cache = {}


def tags_of(path):
    if path not in _tag_cache:
        tags = {}
        try:
            for i, line in enumerate(open(path, encoding="latin1"), 1):
                m = TAG_RE.search(line)
                if m:
                    tags[i] = int(m.group(1), 16)
        except OSError:
            pass
        _tag_cache[path] = tags
    return _tag_cache[path]


def tag_for(path, line):
    tags = tags_of(path)
    for k in range(line, max(0, line - TAG_WINDOW) - 1, -1):
        if k in tags:
            return tags[k]
    return None


# ----------------------------------------------------------------------------------------------------------------
# exe-side tables

def load_functions():
    starts, info = [], {}
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if not p[0] or p[0].startswith("#"):
            continue
        va = int(p[0], 16)
        info[va] = (int(p[1]), p[3] if len(p) > 3 else "")
        starts.append(va)
    starts.sort()
    return starts, info


TD2NAME = {}     # RTTI TypeDescriptor name (.?AV...@@) -> class name used by bases/vft


def load_vftables():
    bases = {}       # class -> {base: mdisp}
    TD2NAME.clear()
    for line in open(RTTI_CLASSES):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 6:
            continue
        TD2NAME[p[1]] = p[2]
        bases[p[2]] = {}
        for b in p[5].split(";"):
            q = b.split("|")
            if len(q) >= 2:
                bases[p[2]].setdefault(q[0], int(q[1]))
    vft = {}         # (class, offset) -> va
    for line in open(RTTI_VFTABLES):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 4:
            continue
        vft[(p[2], int(p[3]))] = int(p[0], 16)
    return bases, vft


def _vft_class(sym):
    m = re.match(r"^\?\?_7(.+?)@@6B(.*)@$", sym)
    if not m:
        return None, None
    cls = m.group(1)
    for kind in "VU":       # template instances / unit-local names: the mangled TypeDescriptor name is exact
        td = TD2NAME.get(".?A" + kind + cls + "@@")
        if td:
            return td, m.group(2)
    if "@" in cls:          # nested / namespaced: Ghidra/RTTI names use '::' in reverse order
        cls = "::".join(reversed(cls.split("@")))
    return cls, m.group(2)


def vftable_va(sym, bases, vft, siblings=()):
    """exe vftable of an obj vftable symbol. `??_7C@@6BBase@@@` names the subobject table of base `Base` (its offset
    comes from the RTTI base list). MSVC names the one remaining table of a multiple-inheritance class `??_7C@@6B@`: it
    is paired with the exe table (same class, RTTI CompleteObjectLocator offset) that no sibling symbol of the same
    class claims. `siblings` = all ??_7 symbols of the obj."""
    cls, rest = _vft_class(sym)
    if cls is None:
        return None
    if rest == "":
        claimed = set()
        for s2 in siblings:
            c2, r2 = _vft_class(s2)
            if c2 == cls and r2:
                o2 = bases.get(cls, {}).get(r2.rstrip("@").split("@")[0])
                if o2 is not None:
                    claimed.add(o2)
        free = sorted(o for (c, o) in vft if c == cls and o not in claimed)
        if not free:
            return None
        off = 0 if 0 in free else free[0]
        if len(free) > 1 and 0 not in free:
            return None         # ambiguous: more than one unclaimed exe table
    else:
        base = rest.rstrip("@").split("@")[0]
        off = bases.get(cls, {}).get(base)
        if off is None:
            return None
    return vft.get((cls, off))


# ----------------------------------------------------------------------------------------------------------------

def quiet_match(obj, sym, va, exe, verbose):
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        ok = bm.match_one(obj, sym, va, exe, verbose=verbose, check_unwind=True, quiet=not verbose)
    return ok, buf.getvalue()


def demangle_all(names):
    if not names:
        return {}
    try:
        out = ms2paths.undname("\n".join(names) + "\n").splitlines()
        res, i = {}, 0
        # llvm-undname echoes "<mangled>\n<demangled>\n\n" per input line
        for n in names:
            while i < len(out) and out[i].strip() != n:
                i += 1
            if i + 1 < len(out):
                res[n] = out[i + 1].strip()
            i += 2
        return res
    except Exception:
        return {}


def short_name(dem):
    """'public: void __cdecl A::B(int)' -> 'A::B'"""
    s = re.sub(r"^(public|protected|private): ", "", dem)
    s = re.sub(r"^(static |virtual )", "", s)
    s = re.sub(r"\(.*$", "", s)
    s = s.split(" __cdecl ")[-1].split(" __ptr64")[0]
    return s.strip()


INITS = ("??__E", "??__F")    # dynamic initializers and their atexit thunks
GENERATED = ("??_G", "??_E", "??__E", "??__F", "??__J", "??_H", "??_I", "??_L", "??_M",
             "?__empty_global_delete@")    # the last: compiler-emitted at end of file, carries the last line


def process_unit(u, exe, starts, finfo, bases, vft, verbose):
    obj = bm.Obj(u.obj)
    lines = cv_first_lines(obj)
    syms = [si for si in obj.func_symbols() if not obj.syms[si][0].startswith(bm.FUNCLET_PREFIXES)]
    res = {"pairs": {}, "vft": {}, "notes": [], "harvest": {}}
    known = bm.LOCAL_KNOWN
    known.clear()
    how = {}

    def trial(name, va):
        snap, nconf = dict(bm.HARVEST), len(bm.CONFLICTS)
        bm.STRICT_SYMBOLS = True
        try:
            buf = io.StringIO()
            with contextlib.redirect_stdout(buf):
                ok = bm.match_one(obj, name, va, exe, verbose=False, check_unwind=True, quiet=True)
        finally:
            bm.STRICT_SYMBOLS = False
        bm.HARVEST.clear()
        bm.HARVEST.update(snap)
        del bm.CONFLICTS[nconf:]
        return ok

    def refs(name, va):
        """{obj symbol: exe va} referenced by `name` paired with `va` (empty unless it matches)."""
        snap, nconf = dict(bm.HARVEST), len(bm.CONFLICTS)
        bm.STRICT_SYMBOLS = True
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                bm.match_one(obj, name, va, exe, verbose=False, check_unwind=False, quiet=True)
        finally:
            bm.STRICT_SYMBOLS = False
        out = dict(bm.LAST_TARGETS)
        bm.HARVEST.clear()
        bm.HARVEST.update(snap)
        del bm.CONFLICTS[nconf:]
        return out

    # 1. tags (authoritative). Compiler-generated functions (??_G, ??__E ...) inherit the line of the declaration they
    # belong to, so a tag claimed by several symbols goes to the non-generated one, else to the one that matches.
    by_tag = {}
    for si in syms:
        name = obj.syms[si][0]
        fl = lines.get(name)
        va = tag_for(*fl) if fl else None
        if va is not None:
            by_tag.setdefault(va, []).append(name)
    for va, names in sorted(by_tag.items()):
        if not u.in_range(va):
            continue            # a header tag (shared template) of another unit's copy: attributed by pin/auto here
        if len(names) > 1:
            names = [n for n in names if not n.startswith(GENERATED)] or names
        if len(names) > 1:      # MS2_REPLACE* thunks sit right after short functions, inside their tag window
            names = [n for n in names if "@ms2_thunk_" not in n] or names
        if len(names) > 1:
            names = [n for n in names if trial(n, va)] or names
        if len(names) != 1:
            res["notes"].append(f"tag 0x{va:x} claimed by {len(names)} functions: " + ", ".join(names[:4]))
            continue
        known[names[0]] = va
        how[names[0]] = "tag"
    # 1b. MS2-PIN directives (compiler-generated functions and ambiguous COMDATs that cannot carry a tag). A pin only
    # decides attribution: the address must lie in one of the unit's ranges, must be free, and the pair is
    # byte-matched like any other (a wrong pin shows as `functional`, it never counts as matched).
    names_here = {obj.syms[si][0] for si in syms}
    for name, va in sorted(u.pins.items()):
        if name.startswith("??_7"):
            continue            # vftable pins: step 4
        if name not in names_here:
            res["notes"].append(f"MS2-PIN {name}: no such function in the obj")
        elif not u.in_range(va):
            res["notes"].append(f"MS2-PIN {name} 0x{va:x}: outside the unit's MS2-RANGEs, ignored")
        elif name in known or va in known.values():
            res["notes"].append(f"MS2-PIN {name} 0x{va:x}: already attributed (tag), ignored")
        else:
            known[name] = va
            how[name] = "pin"
    # 2. auto: untagged functions (COMDATs, initializers) whose masked bytes equal exe functions in the unit ranges.
    used = set(known.values())
    cands = {}
    for lo, hi in u.ranges:
        i = bisect.bisect_left(starts, lo)
        while i < len(starts) and starts[i] < hi:
            va = starts[i]
            rva = va - exe.base
            size = exe.rf[rva][0] - rva if rva in exe.rf else finfo[va][0]
            cands.setdefault(size, []).append(va)
            i += 1
    hits = {}
    for si in syms:
        name = obj.syms[si][0]
        if name in known:
            continue
        data, fields, _ = obj.function(si)
        mask = bytearray(len(data))
        for off, ln, *_ in fields:
            mask[off:off + ln] = b"\1" * len(mask[off:off + ln])
        keep = [k for k in range(len(data)) if not mask[k]]
        want = bytes(data[k] for k in keep)
        h = [va for va in cands.get(len(data), []) if va not in used and
             bytes(exe.img[va - exe.base + k] for k in keep) == want]
        if h:
            hits[name] = h
    hits0 = {n: list(h) for n, h in hits.items()}
    # resolve: a candidate must be consistent with the pairs known so far (call targets, unwind, EH); iterate
    # because each accepted pair constrains the others. Several obj functions can fit one exe function (tiny
    # look-alikes: a 24-byte dtor vs. _Allocate, an initializer of the unit's static vs. of a selectany ATL global):
    # prefer the unit's own code (score), then the COMDAT tail order (the linker emits the selectany functions an obj
    # contributes sorted by mangled name, after its own functions).
    si_of = {obj.syms[si][0]: si for si in syms}

    def score(name):
        si = si_of[name]
        if obj.own(si):
            return 2
        _, fields, _ = obj.function(si)
        for f in fields:
            t = f[5]
            tn, tv, tsec, _, tcl = obj.syms[t]
            if tsec > 0 and not obj.is_code(t) and not tn.startswith(("$", "??_C@", "__real@", "__xmm@", "??_R")) \
                    and (obj.own(t) or tcl == 3 and not obj.sec(tsec)["chars"] & 0x1000):
                return 1
        return 0

    _rcache = {}

    def range_of(va):
        if va not in _rcache:
            _rcache[va] = next((r for r in u.ranges if r[0] <= va < r[1]), None)
        return _rcache[va]

    _own_n = {n: obj.own(si) for n, si in si_of.items()}

    def order_ok(name, va):
        if _own_n[name] or name.startswith(INITS):
            return True
        r = range_of(va)
        lo = hi = None
        for n2, v2 in known.items():
            if n2 == name or n2 not in _own_n or _own_n[n2]:
                continue
            if range_of(v2) != r:
                continue
            if v2 < va and (lo is None or v2 > lo[1]):
                lo = (n2, v2)
            if v2 > va and (hi is None or v2 < hi[1]):
                hi = (n2, v2)
        return (lo is None or lo[0] < name) and (hi is None or name < hi[0])

    def order_key(name):
        # initializers/atexit thunks (static symbols, COMDATs under /Gy) follow definition order = obj section order;
        # selectany COMDATs are emitted sorted by mangled name
        return (1, si_of[name], "") if name.startswith(INITS) else (0, 0, name)

    # references from tagged functions decide look-alikes as well (a function-local static's atexit thunk is named
    # only by the `lea rcx, ??__F...` inside the function that owns the static)
    # (to a fixpoint: a function decided by reference names its own callees in turn, e.g. an STL operator-> and the
    # 11-byte _Const_cast it calls)
    expanded = set()
    while True:
        todo = [(n, v) for n, v in sorted(known.items(), key=lambda kv: kv[1]) if n not in expanded]
        if not todo:
            break
        for name, va in todo:
            expanded.add(name)
            for n2, v2 in refs(name, va).items():
                if n2 in hits and n2 not in known and v2 not in used and v2 in hits[n2] and trial(n2, v2):
                    known[n2] = v2
                    how[n2] = "auto-ref"
                    used.add(v2)
    hits = {n: h for n, h in hits.items() if n not in known}

    ok_hits = {}
    while hits:
        good = {}
        for name in sorted(hits):
            g = [va for va in hits[name] if va not in used and order_ok(name, va) and trial(name, va)]
            if g:
                good[name] = g
        claims = {}
        for name, g in good.items():
            for va in g:
                claims.setdefault(va, []).append(name)
        accepted = []
        for name, g in good.items():
            if len(g) != 1:
                continue
            cl = claims[g[0]]
            if len(cl) > 1:
                top = max(score(n) for n in cl)
                cl = [n for n in cl if score(n) == top]
            if cl == [name]:
                accepted.append((name, g[0]))
        ok_hits = good
        if not accepted:
            break
        for name, va in accepted:
            if va in used:
                continue
            known[name] = va
            how[name] = "auto"
            used.add(va)
        # references from accepted functions to look-alike candidates decide those (an initializer's
        # `lea rcx, ??__F<static>` names its atexit thunk; a ctor names its vftable's functions)
        for name, va in accepted:
            for n2, v2 in refs(name, va).items():
                if n2 in hits and n2 not in known and v2 not in used and v2 in hits[n2] and trial(n2, v2):
                    known[n2] = v2
                    how[n2] = "auto-ref"
                    used.add(v2)
        hits = {n: h for n, h in hits.items() if n not in known and n in good}
    # late multicopy pass: what the exact trials could not pair may call a byte-identical COMDAT copy of a callee that
    # the unit paired elsewhere (std::less<int>::operator() in the unit's TU and in the global table): accept the
    # unambiguous pairs under that leniency only now, so it cannot blur the look-alike groups decided above
    if hits and not os.environ.get("MS2_NO_MULTICOPY"):
        bm.LENIENT_TRIAL = True
        try:
            while True:
                lg = {}
                for name in sorted(hits):
                    g = [va for va in hits0[name] if va not in used and order_ok(name, va) and trial(name, va)]
                    if g:
                        lg[name] = g
                cl = {}
                for name, g in lg.items():
                    for va in g:
                        cl.setdefault(va, []).append(name)
                acc = [(n, g[0]) for n, g in lg.items() if len(g) == 1 and cl[g[0]] == [n]]
                if not acc:
                    break
                for name, va in acc:
                    known[name] = va
                    how[name] = "auto-multicopy"
                    used.add(va)
                hits = {n: h for n, h in hits.items() if n not in known}
        finally:
            bm.LENIENT_TRIAL = False
    # identical functions left over (same bytes, unknown callees): COMDAT tail order = sorted by mangled name
    groups = {}
    for name in hits:
        groups.setdefault(tuple(va for va in ok_hits.get(name, []) if va not in used), []).append(name)
    for vas, names in groups.items():
        if vas and len(vas) == len(names):
            for name, va in zip(sorted(names, key=order_key), sorted(vas)):
                known[name] = va
                how[name] = "auto-order"
                used.add(va)
        elif vas:
            res["notes"].append(f"ambiguous: {len(names)} look-alike functions for {len(vas)} exe candidates: "
                                + ", ".join(names[:3]))
    # references from every pair accepted so far name their callees (to a fixpoint): look-alikes that a caller
    # already pins must not be handed out by the arbitrary leaf/fold assignments below
    implied = {}                # obj name -> exe VAs its paired callers call (the COMDAT may live in another unit)
    if not os.environ.get("MS2_NO_ICF_FOLD"):
        expanded2 = set()
        while True:
            todo = [(n, v) for n, v in sorted(known.items(), key=lambda kv: kv[1]) if n not in expanded2]
            if not todo:
                break
            for name, va in todo:
                expanded2.add(name)
                for n2, v2 in refs(name, va).items():
                    implied.setdefault(n2, set()).add(v2)
                    if n2 in hits0 and n2 not in known and v2 not in used and v2 in hits0[n2] and trial(n2, v2):
                        known[n2] = v2
                        how[n2] = "auto-ref"
                        used.add(v2)
    # relocation-free look-alikes that the order test rejected everywhere (tiny `mov rax, rcx; ret` stubs: there is
    # no information to order them): equal bytes mean equal behaviour, so any pairing is exact and harmless.
    if not os.environ.get("MS2_NO_ICF_FOLD"):
        leaf = {}
        for name in sorted(hits0):
            if name in known or obj.function(si_of[name])[1]:
                continue
            cv = tuple(va for va in hits0[name] if va not in used and va in implied.get(name, (va,)) and trial(name, va))
            if cv:
                leaf.setdefault(cv, []).append(name)
        for cv, names in leaf.items():
            free = [va for va in cv if va not in used]
            for name, va in zip(sorted(names, key=order_key), sorted(free)):
                known[name] = va
                how[name] = "auto-leaf"
                used.add(va)
    # ICF folding (/OPT:ICF): the linker keeps ONE body for several byte-identical COMDATs of the unit (look-alike
    # std::forward<T>, _Allocate/dtor stubs ...), so the exe has fewer functions than the obj has names and the
    # group cannot be paired one-to-one. A name whose only byte/unwind/reference-compatible candidate is an exe
    # function that nobody claims is paired with it AFTER the normal pairs are matched (never part of `known`, so no
    # caller's check changes): the folded body is not a stub, and every name of the group is bound to it.
    folds = {}
    if not os.environ.get("MS2_NO_ICF_FOLD"):
        taken = set(known.values())
        for name in sorted(hits0):
            if name in known:
                continue
            cv = [va for va in hits0[name] if va not in taken and va in implied.get(name, (va,)) and trial(name, va)]
            if len(cv) == 1:
                folds[name] = cv[0]
        # names folded onto one body must call the same functions: two different targets (memcpy vs memmove, a vector
        # vs a list _Tidy: same bytes up to the relocation) cannot be one exe function. On a conflict keep only the
        # names whose targets the pairs/symbol maps confirm (to a fixpoint: dropping a name unconfirms its callers).
        tg = {n: refs(n, va) for n, va in folds.items()}
        while True:
            def where(t):
                return known.get(t) or folds.get(t) or bm.HARVEST.get(t) or bm.SYMBOLS.get(t)
            drop = set()
            byva_f = {}
            for n, va in folds.items():
                byva_f.setdefault(va, []).append(n)
            for va, ns in byva_f.items():
                seen_t = {}
                for n in ns:
                    for t, v in tg[n].items():
                        seen_t.setdefault(v, set()).add(t)
                if all(len(x) == 1 for x in seen_t.values()):
                    continue
                for n in ns:
                    if not all(where(t) == v for t, v in tg[n].items()):
                        drop.add(n)
            if not drop:
                break
            for n in drop:
                del folds[n]
    # 2b'. own-copy pass: a function whose only candidates were rejected because the committed table binds its name (or a
    # callee's) to ANOTHER unit's byte-identical copy (bytematch.same_code) is paired with its own copy: a merge that
    # re-binds a shared MS2Ptr/CAtlArray/STL COMDAT name to another unit's copy must not turn the unit's gated function
    # into a stub. Only names nothing above paired (no fold), unique candidate and unique claimant, so look-alike groups
    # decided by the table's hints (and auto-order) are unchanged. MS2_NO_OWN_COPY=1: off.
    if not os.environ.get("MS2_NO_OWN_COPY"):
        bm.LENIENT_TRIAL = bm.OWN_COPY_TRIAL = True
        try:
            # callers first: a paired function's call target names the copy (to a fixpoint)
            if any(n not in known and n not in folds for n in hits0):
                expanded3 = set()
                while True:
                    todo = [(n, v) for n, v in sorted(known.items(), key=lambda kv: kv[1]) if n not in expanded3]
                    if not todo:
                        break
                    taken = set(known.values()) | set(folds.values())
                    for name, va in todo:
                        expanded3.add(name)
                        for n2, v2 in refs(name, va).items():
                            if n2 in hits0 and n2 not in known and n2 not in folds and v2 not in taken \
                                    and v2 in hits0[n2] and trial(n2, v2):
                                known[n2] = v2
                                how[n2] = "auto-owncopy"
                                used.add(v2)
                                taken.add(v2)
            while True:
                taken = set(known.values()) | set(folds.values())
                og = {}
                for name in sorted(hits0):
                    if name in known or name in folds:
                        continue
                    g = [va for va in hits0[name] if va not in taken and order_ok(name, va) and trial(name, va)]
                    if g:
                        og[name] = g
                ocl = {}
                for name, g in og.items():
                    for va in g:
                        ocl.setdefault(va, []).append(name)
                acc = [(n, g[0]) for n, g in og.items() if len(g) == 1 and ocl[g[0]] == [n]]
                if not acc:
                    break
                for name, va in acc:
                    known[name] = va
                    how[name] = "auto-owncopy"
                    used.add(va)
        finally:
            bm.LENIENT_TRIAL = bm.OWN_COPY_TRIAL = False
    # 2c. look-alike GUESS (opt-in: `// MS2-GUESS-LOOKALIKES` in the unit, or MS2_GUESS_LOOKALIKES=1): byte-identical
    # groups that nothing above could pair (no reloc evidence, M != N, or callee symbols the global table disagrees
    # about). The bytes AND unwind data are identical and every relocation target is consistent (a pair known from
    # the unit, a name of the same group set, or an outside symbol the table does not contradict), so the exe body
    # does what the source says; only WHICH name owns WHICH copy is arbitrary. Such a pair is FUNCTIONAL, never
    # exact (ok=False, how=auto-guess), is not part of `known` (no caller's check changes) and harvests nothing.
    guessed = {}
    if u.guess:
        taken_g = set(known.values())
        pool = {n: [v for v in h if v not in taken_g] for n, h in hits0.items() if n not in known and n not in folds}
        pool = {n: h for n, h in pool.items() if h}
        saved = (dict(bm.SYMBOLS), dict(bm.HARVEST))
        # pairs that were themselves chosen by name order carry no evidence about their callers: set them aside
        # (a tag or pin on an identical look-alike is no better): all pairs are checked below with same_code instead
        weak = {t: known.pop(t) for t in list(known) if how.get(t) in ("auto-order", "auto-leaf", "auto", "auto-ref", "tag", "pin")}
        bm.SYMBOLS.clear()
        bm.HARVEST.clear()
        snap_conf = len(bm.CONFLICTS)
        tg_g = {}
        try:
            for n, h in pool.items():
                for v in h:
                    bm.STRICT_SYMBOLS = False
                    buf_g = io.StringIO()
                    with contextlib.redirect_stdout(buf_g):
                        ok_g = bm.match_one(obj, n, v, exe, verbose=False, check_unwind=True, quiet=True)
                    if ok_g:
                        tg_g[(n, v)] = dict(bm.LAST_TARGETS)
        finally:
            bm.SYMBOLS.update(saved[0])
            bm.HARVEST.clear()
            bm.HARVEST.update(saved[1])
            del bm.CONFLICTS[snap_conf:]
            del bm.MULTICOPY[:]
            known.update(weak)
        outside = saved[0]
        cands_g = {}
        while True:
            cands_g = {n: [v for v in h if (n, v) in tg_g] for n, h in pool.items()}
            changed = False
            for n in list(cands_g):
                keep = []
                for v in cands_g[n]:
                    good = True
                    for t, tv in tg_g[(n, v)].items():
                        if t in weak:
                            good = good and (weak[t] == tv or bm.same_code(exe, weak[t], tv))
                        elif t in pool:
                            good = good and any(x == tv or bm.same_code(exe, x, tv) for x in cands_g.get(t, pool[t]))
                        else:
                            w = outside.get(t) or bm.HARVEST.get(t)
                            good = good and (w is None or w == tv or bm.same_code(exe, w, tv))
                    if good:
                        keep.append(v)
                if len(keep) != len(pool[n]) and keep != cands_g[n]:
                    changed = True
                cands_g[n] = keep
            if not changed:
                break
            pool = {n: cands_g[n] for n in cands_g if cands_g[n]}
            tg_g = {k: t for k, t in tg_g.items() if k[0] in pool and k[1] in pool[k[0]]}
        groups_g = {}
        for n, h in cands_g.items():
            if h:
                pref = [v for v in h if v in implied.get(n, ())] or h
                groups_g.setdefault(tuple(sorted(pref)), []).append(n)
        for vas, names in groups_g.items():
            names = sorted(names, key=order_key)
            for i, n in enumerate(names):
                if i < len(vas) or len(names) > len(vas):
                    guessed[n] = vas[i % len(vas)]
    # 3. match everything paired (harvests the symbol map)
    funclets = {}
    # the symbol map is harvested from FULLY matched functions only (bytes + unwind/EH): a function that differs
    # anywhere contributes no mapping
    del bm.SYMBOL_MISMATCH[:]
    del bm.MULTICOPY[:]
    for name, va in sorted(known.items(), key=lambda kv: kv[1]):
        bm.FUNCLET_PAIRS.clear()
        snap = dict(bm.HARVEST)
        ok, text = quiet_match(obj, name, va, exe, verbose)
        if not ok:
            bm.HARVEST.clear()
            bm.HARVEST.update(snap)
        res["pairs"][name] = {"va": va, "how": how[name], "ok": ok, "report": "" if ok else text}
        if ok:
            funclets.update(bm.FUNCLET_PAIRS)
    for name, va in sorted(folds.items(), key=lambda kv: kv[1]):
        snap = dict(bm.HARVEST)
        ok, text = quiet_match(obj, name, va, exe, verbose)
        if not ok:
            bm.HARVEST.clear()
            bm.HARVEST.update(snap)
        if ok:                  # a fold that does not match is no evidence: the function stays a stub
            res["pairs"][name] = {"va": va, "how": "auto-fold", "ok": ok, "report": ""}
    for name, va in sorted(guessed.items(), key=lambda kv: kv[1]):
        if name not in res["pairs"]:
            res["pairs"][name] = {"va": va, "how": "auto-guess", "ok": False,
                                  "report": f"look-alike guess: byte-identical to 0x{va:x}, owner of the copy chosen by name order"}
    # unwind funclets of matched functions (?dtor$N@...: not in the unit ranges, not counted) are matched only to
    # harvest their callees: a destructor reached only on the exception path is otherwise missing from the symbol map
    for name, va in sorted(funclets.items(), key=lambda kv: kv[1]):
        snap = dict(bm.HARVEST)
        ok, _ = quiet_match(obj, name, va, exe, False)
        if not ok:
            bm.HARVEST.clear()
            bm.HARVEST.update(snap)
            res["notes"].append(f"funclet {name} @0x{va:x} does not match")
    # 4. vftables (paired via RTTI, every slot checked against the pairs and the symbol map)
    vnames = [n for (n, _, sec, _, sc) in obj.syms.values() if sec > 0 and n.startswith("??_7") and sc == 2]
    for si, (name, value, secnum, typ, sclass) in obj.syms.items():
        if secnum > 0 and name.startswith("??_7") and sclass == 2:
            va = vftable_va(name, bases, vft, vnames)
            pin = u.pins.get(name)
            if pin is not None:
                if va is not None and va != pin:
                    res["notes"].append(f"MS2-PIN {name} 0x{pin:x}: RTTI pairing says 0x{va:x}, pin wins")
                if pin in set(vft.values()):
                    va = pin
                elif exe_is_code_ptr(exe, pin):
                    # vftable of a class compiled without RTTI (/GR- library: Scaleform, CRI): no COL, so it is not in
                    # the RTTI table; accepted when slot 0 points into .text, still compared slot by slot below
                    va = pin
                    res["notes"].append(f"MS2-PIN {name} 0x{pin:x}: non-RTTI vftable, compared slot by slot")
                else:
                    res["notes"].append(f"MS2-PIN {name} 0x{pin:x}: not an RTTI vftable of the exe, ignored")
            if va is None:
                # an unpaired vftable counts against the unit (it is never silently skipped)
                res["vft"][name] = {"va": None, "ok": False,
                                    "report": f"UNPAIRED vftable {name}: no exe vftable via RTTI "
                                              f"(add `// MS2-PIN: {name} 0x<va>` if the class is unit-local)"}
                res["notes"].append(f"{name}: no exe vftable found via RTTI (counts as unpaired)")
                continue
            snap = dict(bm.HARVEST)
            ok, text = quiet_match(obj, name, va, exe, verbose)
            if not ok:
                bm.HARVEST.clear()
                bm.HARVEST.update(snap)
            res["vft"][name] = {"va": va, "ok": ok, "report": "" if ok else text}
    res["harvest"] = dict(bm.HARVEST)
    res["symmismatch"] = sorted({f"{n} is 0x{w:x} in the symbol table, exe uses 0x{v:x}" for n, w, v in bm.SYMBOL_MISMATCH})
    # byte-identical exe copies under one name (bytematch.same_code): the unit's own binding is accepted, info only
    res["multicopy"] = sorted({(n, w, v) for n, w, v in bm.MULTICOPY})
    known.clear()
    return res


def exe_is_code_ptr(exe, va):
    """True if the qword at exe address va points into the exe's .text section (slot 0 of a vftable)."""
    q = exe.read(va, 8)
    if len(q) != 8:
        return False
    target = struct.unpack("<Q", q)[0] - exe.base
    return any(sec.Name.rstrip(b"\0") == b".text" and sec.VirtualAddress <= target < sec.VirtualAddress + sec.Misc_VirtualSize
               for sec in exe.pe.sections)


LOOKALIKE_HOW = ("auto-order", "auto-leaf", "auto-guess")


def unit_score(u, res, starts):
    """(stubs, -exact, -vftables ok) of a process_unit result over the unit's ranges: lower is better."""
    byva = {}
    for p in res["pairs"].values():
        byva[p["va"]] = byva.get(p["va"], False) or p["ok"]
    stubs = exact = 0
    for lo, hi in u.ranges:
        i = bisect.bisect_left(starts, lo)
        while i < len(starts) and starts[i] < hi:
            if starts[i] not in byva:
                stubs += 1
            elif byva[starts[i]]:
                exact += 1
            i += 1
    return (stubs, -exact, -sum(1 for v in res["vft"].values() if v["ok"]))


def needs_gate_pass(u, res, starts):
    """Could the committed table's hints change this unit's pairing? (stubs, failed pairs, look-alike choices)"""
    if unit_score(u, res, starts)[0]:
        return True
    if any(p["how"] in LOOKALIKE_HOW for p in res["pairs"].values()):
        return True
    return any(n.startswith("ambiguous") for n in res["notes"])


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("filters", nargs="*", help="only units whose path/name contains one of these")
    ap.add_argument("--force", action="store_true", help="recompile and re-match everything")
    ap.add_argument("-j", type=int, default=4, help="parallel compiles (default 4)")
    ap.add_argument("-v", "--verbose", action="store_true", help="print bytematch reports of non-matching functions")
    ap.add_argument("--agent", default=os.environ.get("MS2_AGENT") or None,
                    help="private cache build/progress-AGENT/, report mode (default: $MS2_AGENT)")
    ap.add_argument("--report", action="store_true", help="report mode: never write progress/* (implied by --agent)")
    ap.add_argument("--simulate-merge", action="store_true",
                    help="report mode with the merge step's symbol semantics (table rebuilt from symbols-manual.tsv + "
                         "the harvest of the selected units): shows the CONFLICT lines a merge would print, writes only "
                         "build/progress-AGENT/")
    ap.add_argument("--functional", action="store_true",
                    help="with --check: the functional gate instead of the exact one (no stub functions, all vftables "
                         "paired and matching, no symbol conflict from the unit; functional functions are accepted)")
    ap.add_argument("--engine", action="store_true",
                    help="run the Gamebryo engine stage (tools/gbprogress.py) even when unit filters are given")
    ap.add_argument("--no-engine", action="store_true",
                    help="skip compiling/matching the engine TUs (their cached rows are still written)")
    ap.add_argument("--check", action="store_true",
                    help="exit 1 unless every selected unit compiles and is 100%% matched with all vftables OK")
    a = ap.parse_args()

    global CACHE, OUT
    if a.simulate_merge and not a.agent:
        a.report = True
    if a.agent and not re.fullmatch(r"[A-Za-z0-9_.-]+", a.agent):
        sys.exit(f"bad agent name {a.agent!r}")
    if a.filters and not (a.agent or a.report):
        # a filtered merge rebuilds progress/symbols.tsv from the selected units' harvest only (2026-10-17: a worker's
        # `progress.py -v <unit>` without MS2_AGENT cut it from 73478 to 2655 rows); merges always run on all units
        sys.exit("refusing a filtered merge (it would truncate progress/symbols.tsv): "
                 "set MS2_AGENT=<name> in the same command or pass --agent/--report")
    if a.agent or a.report:
        CACHE = os.path.join(ROOT, "build", "progress-" + (a.agent or "report"))
        OUT = CACHE
    symbols_out = os.path.join(OUT, "symbols.tsv")

    t0 = time.time()
    os.makedirs(CACHE, exist_ok=True)
    os.makedirs(OUT, exist_ok=True)
    all_units = find_units([])
    units = [u for u in all_units if not a.filters or any(x in u.rel or x in u.name for x in a.filters)]
    cache_path = os.path.join(CACHE, "results.json")
    cache = json.load(open(cache_path)) if os.path.exists(cache_path) else {}

    # compile
    import heavy_lock
    a.j = heavy_lock.clamp_jobs(a.j)
    todo = [u for u in units if a.force or needs_compile(u)]
    failed = set()
    if todo:
        print(f"compiling {len(todo)} unit(s) with cl 19.16 ...", flush=True)
        with ThreadPoolExecutor(max_workers=max(1, a.j)) as ex:
            for u, (ok, msgs, dt) in zip(todo, ex.map(compile_unit, todo)):
                print(f"  {'ok  ' if ok else 'FAIL'} {u.rel} ({dt:.1f}s)")
                for m in msgs:
                    print("      " + m)
                if not ok:
                    failed.add(u.rel)

    exe = bm.Exe(bm.EXE)
    starts, finfo = load_functions()
    bases, vft = load_vftables()
    merge_mode = not (a.agent or a.report) or a.simulate_merge
    manual_tsv = os.path.join(ROOT, "progress", "symbols-manual.tsv")
    # merge mode: the table is rebuilt from scratch (hand-written symbols-manual.tsv + the harvest of fully matched
    # units); stale entries of the previous table never win. Report mode checks against the committed table.
    bm.load_symbols(manual_tsv if merge_mode else bm.SYMBOLS_TSV)

    for u in units:
        if u.rel in failed or not os.path.exists(u.obj):
            cache[u.rel] = {"key": None, "failed": True, "res": None}
            continue
        key = [os.path.getmtime(u.obj), os.path.getsize(u.obj), u.ranges, "multicopy5" + ("g" if u.guess else "") + ("f9" if not os.environ.get("MS2_NO_ICF_FOLD") else "") + ("m" if merge_mode else "") + ("x" if os.environ.get("MS2_NO_MULTICOPY") else "")]
        if os.environ.get("MS2_MERGE_INCR"):      # tools/merge.sh: persistent tree, match results also keyed by their inputs
            key.append(mergekey.game_stamp())
            key.append(mergekey.rows_stamp(u.obj, manual_tsv))
        c = cache.get(u.rel)
        if not a.force and c and c.get("key") == json.loads(json.dumps(key)) and not a.verbose:
            continue
        bm.HARVEST.clear()
        print(f"matching {u.rel} ...", flush=True)
        nconf0 = len(bm.CONFLICTS)
        res = process_unit(u, exe, starts, finfo, bases, vft, a.verbose)
        # in-unit conflicts (one mangled name paired to two non-identical exe functions inside this unit) are kept in
        # the unit's cache entry so that they survive cached runs and carry the unit name; the global stage reports them
        res["conflicts"] = [list(c) for c in bm.CONFLICTS[nconf0:]]
        del bm.CONFLICTS[nconf0:]
        cache[u.rel] = {"key": key, "failed": False, "res": res}
        if a.verbose:
            for n, p in res["pairs"].items():
                if not p["ok"]:
                    print(p["report"])
            for n, p in res["vft"].items():
                if not p["ok"]:
                    print(p["report"])
    # gate-faithful pass (merge mode): the pass above pairs every unit with only symbols-manual.tsv as the symbol table,
    # but the unit's own gate (report mode) paired it against the committed progress/symbols.tsv, whose rows for other
    # units' byte-identical COMDAT copies (MS2Ptr<T>/Delegate/ReleaseImpl/STL glue ...) rule those look-alike
    # candidates out. Without them several look-alikes compete for the unit's copy -> "ambiguous" -> stub (merge 17:
    # 47 gated functions in 20 units). Units with stubs, failed pairs or look-alike pairing are matched again exactly
    # like their gate (table = committed symbols.tsv) and that result is kept unless it is worse (more stubs, fewer
    # exact, fewer vftables). The output table is still rebuilt from the harvests only. MS2_NO_GATE_PASS=1: old behaviour.
    if merge_mode and os.path.exists(bm.SYMBOLS_TSV) and not os.environ.get("MS2_NO_GATE_PASS"):
        gate_todo = []
        for u in units:
            c = cache.get(u.rel)
            if not c or not c.get("res"):
                continue
            stamp = mergekey.rows_stamp(u.obj, bm.SYMBOLS_TSV)    # only the committed rows this unit can read
            if c.get("key2") == [c["key"], stamp]:
                continue
            c.pop("res2", None)
            c.pop("key2", None)
            if needs_gate_pass(u, c["res"], starts):
                gate_todo.append(u)
            else:
                c["key2"] = [c["key"], stamp]
        if gate_todo:
            print(f"gate pass: re-matching {len(gate_todo)} unit(s) against the committed symbols.tsv ...", flush=True)
            bm.load_symbols(bm.SYMBOLS_TSV)
            kept = 0
            for u in gate_todo:
                c = cache[u.rel]
                bm.HARVEST.clear()
                nconf0 = len(bm.CONFLICTS)
                res2 = process_unit(u, exe, starts, finfo, bases, vft, False)
                res2["conflicts"] = [list(x) for x in bm.CONFLICTS[nconf0:]]
                del bm.CONFLICTS[nconf0:]
                s1, s2 = unit_score(u, c["res"], starts), unit_score(u, res2, starts)
                if s2 <= s1:
                    c["res2"] = res2
                    kept += 1
                    if s2 < s1:
                        print(f"gate pass: {u.rel}: stubs {s1[0]} -> {s2[0]}, exact {-s1[1]} -> {-s2[1]}")
                c["key2"] = [c["key"], mergekey.rows_stamp(u.obj, bm.SYMBOLS_TSV)]
            bm.load_symbols(manual_tsv)
            print(f"gate pass: {kept} of {len(gate_todo)} unit(s) keep their gate pairing", flush=True)
    # drop cache entries of units that no longer exist
    live = {u.rel for u in all_units}
    cache = {k: v for k, v in cache.items() if k in live}
    json.dump(cache, open(cache_path, "w"))
    if merge_mode and not os.environ.get("MS2_NO_GATE_PASS"):
        cache = {k: (dict(v, res=v["res2"]) if v.get("res2") else v) for k, v in cache.items()}

    # symbols: union of all units' harvests. One mangled name has one exe address: when units disagree, the mapping of
    # the units that fully match wins (then the most units), and every unit that harvested another address is
    # reported (CONFLICT, both units and VAs) and fails --check. Nothing is overwritten silently.
    def fully_ok(c):
        r = c["res"]
        return all(p["ok"] for p in r["pairs"].values()) and all(v["ok"] for v in r["vft"].values())

    done_rels = set()
    try:
        _done = {l.split("\t")[0] for l in open(os.path.join(OUT, "queue.tsv"))
                 if l.strip() and not l.startswith("#") and l.split("\t")[4] in ("done", "done-functional")}
        done_rels = {u.rel for u in all_units if u.name in _done}
    except (OSError, IndexError):
        pass
    seen = {}                       # name -> {va: [unit rel, ...]}
    # a filtered run keeps the cached rows of the units it did not select; a unit whose source/header changed since its obj
    # was built has a stale harvest (its old obj may bind a name that the current source no longer references), so it
    # contributes nothing to the symbol table until it is rebuilt
    selected = {u.rel for u in units}
    stale_units = {u.rel for u in all_units if u.rel not in selected and needs_compile(u)}
    if stale_units and merge_mode:
        print(f"warning: {len(stale_units)} unit(s) not selected and out of date (source/header newer than obj); their "
              f"cached harvest is ignored (rerun without a filter to include them): "
              + ", ".join(sorted(stale_units)[:8]) + (" ..." if len(stale_units) > 8 else ""))
    STALE = []                      # (name, win, va, units): conflicts whose losing side is only blocked/todo/claimed units
    for rel, c in sorted(cache.items()):
        for n, x, y in (c.get("res") or {}).get("conflicts", []):
            if rel in done_rels:
                bm.CONFLICTS.append((f"{n} [inside {rel}: 0x{x:x} and 0x{y:x}]", x, y))
            else:
                STALE.append((n, x, y, [rel]))
    # a unit that is not done yet (WIP commit, often before tools/tplpin.py --apply) harvests nothing for the names it
    # paired only by look-alike order (auto-order/auto-leaf: no caller evidence): such rows are arbitrary and later
    # fail the unit's own report-mode --check with rotated conflicts (w465)
    queue_done = set()
    try:
        _qd = {l.split("\t")[0] for l in open(os.path.join(ROOT, "progress", "queue.tsv"))
               if l.strip() and not l.startswith("#") and l.split("\t")[4] in ("done", "done-functional")}
        queue_done = {u.rel for u in all_units if u.name in _qd}
    except (OSError, IndexError):
        pass
    for rel, c in sorted(cache.items()):
        if c.get("res") and not (merge_mode and rel in stale_units):
            weak = set() if rel in queue_done or not merge_mode else \
                {n for n, p in c["res"]["pairs"].items() if p["how"] in ("auto-order", "auto-leaf")}
            for n, va in c["res"]["harvest"].items():
                if n not in weak:
                    seen.setdefault(n, {}).setdefault(va, []).append(rel)
    bm.HARVEST.clear()
    inconsistent = {}               # unit rel -> [description]
    for n, by_va in seen.items():
        if len(by_va) == 1:
            bm.HARVEST[n] = next(iter(by_va))
            continue
        def rank(va):
            us = by_va[va]
            # units that are done in the queue win over blocked/in-progress ones (their pins may be stale)
            return (sum(1 for r in us if r in done_rels), sum(1 for r in us if fully_ok(cache[r])), len(us), -va)
        # the global binding (symbols.tsv -> hook DLL link) of a name with several VAs: deterministic rank. When the
        # copies are byte-identical (bytematch.same_code) every unit keeps its own binding for scoring and the DLL may
        # call any copy: info-level MULTICOPY, not a conflict.
        win = max(by_va, key=rank)
        bm.HARVEST[n] = win
        for va, us in by_va.items():
            if va != win and bm.same_code(exe, win, va):
                bm.MULTICOPY.append((n, win, va))
            elif va != win and not any(r in done_rels for r in us):
                # only blocked/todo/claimed units (stale or work-in-progress pins) disagree with the done units: the
                # done binding stands and the disagreement is listed as info (re-check when those units are finished)
                STALE.append((n, win, va, us))
            elif va != win:
                bm.CONFLICTS.append((f"{n} [0x{win:x} from {', '.join(by_va[win])}; 0x{va:x} from {', '.join(us)}]",
                                     win, va))
                for r in us:
                    inconsistent.setdefault(r, []).append(f"{n[:80]} is 0x{va:x} here, 0x{win:x} in "
                                                          + ", ".join(by_va[win]))
    if merge_mode:
        if os.path.exists(manual_tsv):
            for line in open(manual_tsv):
                if line.startswith("#") or not line.strip():
                    continue
                q = line.rstrip("\n").split("\t")
                va = int(q[1], 16)
                if bm.HARVEST.get(q[0], va) != va and bm.same_code(exe, bm.HARVEST[q[0]], va):
                    bm.MULTICOPY.append((q[0], bm.HARVEST[q[0]], va))
                elif bm.HARVEST.get(q[0], va) != va:
                    # symbols-manual.tsv is hand-verified: it wins over the harvest, the disagreement is only warned about
                    print(f"warning: {q[0]}: symbols-manual.tsv says 0x{va:x}, harvest of "
                          f"{', '.join(seen.get(q[0], {}).get(bm.HARVEST[q[0]], ['?']))} says 0x{bm.HARVEST[q[0]]:x}; "
                          f"manual wins (fix the unit that references the wrong symbol)")
                    bm.HARVEST[q[0]] = va
                else:
                    bm.HARVEST.setdefault(q[0], va)
    elif symbols_out != bm.SYMBOLS_TSV:
        # report mode: the committed table plus this cache's harvest (rebuilt every run, nothing stale survives)
        os.makedirs(OUT, exist_ok=True)
        shutil.copyfile(bm.SYMBOLS_TSV, symbols_out + ".tmp")
        os.replace(symbols_out + ".tmp", symbols_out)
    added = bm.write_harvest(symbols_out, exe, fresh=merge_mode)

    # status rows
    unit_by_rel = {u.rel: u for u in all_units}
    rows = []
    summary = []
    tot = dict(n=0, m=0, f=0, b=0, bm=0, bf=0)
    names_to_demangle = []
    for rel, c in cache.items():
        if c.get("res"):
            names_to_demangle += list(c["res"]["pairs"].keys())
    dem = demangle_all(sorted(set(names_to_demangle)))
    for rel in sorted(cache):
        u = unit_by_rel[rel]
        c = cache[rel]
        byva = {}
        if c.get("res"):
            for n, p in c["res"]["pairs"].items():
                if p["va"] not in byva or p["ok"] and not byva[p["va"]][1]:     # several names on one ICF-folded VA: exact wins
                    byva[p["va"]] = (n, p["ok"])
        n = m = f = b = bmt = bft = 0
        for lo, hi in u.ranges:
            i = bisect.bisect_left(starts, lo)
            while i < len(starts) and starts[i] < hi:
                va = starts[i]
                size, gname = finfo[va]
                if va in byva:
                    sym, ok = byva[va]
                    state = "matched" if ok else "functional"
                    nm = short_name(dem.get(sym, sym))
                else:
                    state, nm = "stub", gname
                rows.append((va, nm, u.name, state, size))
                n += 1
                b += size
                if state == "matched":
                    m += 1
                    bmt += size
                elif state == "functional":
                    f += 1
                    bft += size
                i += 1
        vt = c["res"]["vft"] if c.get("res") else {}
        vok = sum(1 for v in vt.values() if v["ok"])
        summary.append((u.name, n, m, f, b, bmt, len(vt), vok, c.get("failed"), bft))
        for k, v in zip("nmfb", (n, m, f, b)):
            tot[k] += v
        tot["bm"] += bmt
        tot["bf"] += bft
    # engine stage: Gamebryo TUs of engine/units-gb.json (tools/gbprogress.py; own cache, no MS2-UNIT/queue rows, no
    # symbols harvested). Its rows only cover VAs outside the game units; game rows and totals are unaffected.
    eng_rows = []
    if not os.path.exists(gbprogress.gbtree.UNITS_JSON) and not a.filters and not a.no_engine:
        # merge 12 ran from a snapshot older than engine/units-gb.json and silently wrote a game-only status.tsv
        sys.exit(f"progress.py: {gbprogress.gbtree.UNITS_JSON} missing: refusing to write a status.tsv without engine rows "
                 "(snapshot older than the engine stage? pass --no-engine to skip deliberately)")
    if os.path.exists(gbprogress.gbtree.UNITS_JSON):
        if (a.engine or not a.filters) and not a.no_engine:
            eng_res, _ = gbprogress.run(CACHE, max(1, a.j), log=lambda m: print(m, flush=True))
        else:
            eng_res = gbprogress.load_results(CACHE)
        eng_rows = gbprogress.credit(eng_res, {r[0] for r in rows})
        edem = demangle_all(sorted({r[1] for r in eng_rows if r[3] != "stub"}))
        rows += [(va, short_name(edem.get(sym, sym)) if st != "stub" else sym, un, st, sz)
                 for va, sym, un, st, sz in eng_rows]
    rows.sort()
    with open(os.path.join(OUT, "status.tsv"), "w") as fo:
        fo.write("#va\tname\tunit\tstate\tsize\n")
        for va, nm, un, st, sz in rows:
            fo.write(f"{va:x}\t{nm}\t{un}\t{st}\t{sz}\n")

    # overall game-code denominator: functions inside work/map/units.tsv ranges (minus the rows a library lane owns)
    game_n = game_b = 0
    lib_owned = gbprogress.owned_game_units()
    for line in open(UNITS):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 6 or int(p[0], 16) in lib_owned:
            continue
        lo, hi = int(p[0], 16), int(p[1], 16)
        i = bisect.bisect_left(starts, lo)
        while i < len(starts) and starts[i] < hi:
            game_n += 1
            game_b += finfo[starts[i]][0]
            i += 1
    out = []
    out.append(f"# tools/progress.py  {time.strftime('%Y-%m-%d %H:%M')}")
    out.append(f"{'unit':<45} {'funcs':>6} {'match':>6} {'func.':>6} {'stub':>5} {'bytes':>8} {'matched':>8}  "
               f"{'exact':>6} {'impl.':>6}  vftables")
    for name, n, m, f, b, bmt, nv, vok, fail, bft in summary:
        pct = 100.0 * bmt / b if b else 0
        ipct = 100.0 * (bmt + bft) / b if b else 0
        out.append(f"{name:<45} {n:6} {m:6} {f:6} {n - m - f:5} {b:8} {bmt:8}  {pct:5.1f}% {ipct:5.1f}%  {vok}/{nv}"
                   + ("  COMPILE FAILED" if fail else ""))
    out.append(f"{'total (' + str(len(summary)) + ' units)':<45} {tot['n']:6} {tot['m']:6} {tot['f']:6} "
               f"{tot['n'] - tot['m'] - tot['f']:5} {tot['b']:8} {tot['bm']:8}")
    out.append(f"game code (work/map/units.tsv): {game_n} functions, {game_b} bytes; matched "
               f"{tot['m']} ({100.0 * tot['m'] / game_n:.3f}%) functions, {100.0 * tot['bm'] / game_b:.3f}% of bytes; "
               f"implemented (matched + functional) {tot['m'] + tot['f']} ({100.0 * (tot['m'] + tot['f']) / game_n:.3f}%) "
               f"functions, {100.0 * (tot['bm'] + tot['bf']) / game_b:.3f}% of bytes")
    if eng_rows:
        out += gbprogress.summary(eng_rows)
    text = "\n".join(out) + "\n"
    open(os.path.join(OUT, "summary.txt"), "w").write(text)
    print(text, end="")
    for rel in sorted(cache):
        r = cache[rel].get("res")
        if r:
            for nline in r["notes"]:
                print(f"note {rel}: {nline}")
    for n, x, y in bm.CONFLICTS:
        print(f"CONFLICT symbol {n}: 0x{x:x} vs 0x{y:x}")
    if STALE:
        with open(os.path.join(OUT, "stale-conflicts.tsv"), "w") as fo:
            fo.write("#symbol\tbound va\tother va\tnot-done units that use the other va\n")
            for n, x, y, us in sorted(STALE):
                fo.write(f"{n}\t{x:x}\t{y:x}\t{','.join(us)}\n")
        print(f"stale: {len(STALE)} symbol disagreements involve only blocked/todo/claimed units (info; "
              f"{os.path.relpath(OUT, ROOT)}/stale-conflicts.tsv)")
    mc = sorted(set(bm.MULTICOPY) | {tuple(t) for c in cache.values() if c.get("res")
                                     for t in c["res"].get("multicopy", [])})
    with open(os.path.join(OUT, "multicopy.tsv"), "w") as fo:
        fo.write("#symbol\tbound va (symbols.tsv)\tother byte-identical copy\n")
        for n, x, y in mc:
            fo.write(f"{n}\t{x:x}\t{y:x}\n")
    if mc:
        print(f"multicopy: {len(mc)} name/VA pairs bound to byte-identical exe copies (info; "
              f"{os.path.relpath(OUT, ROOT)}/multicopy.tsv)")
    bad = []
    ok_msg = None
    # who claims the VAs named in a "symbol conflict" line: committed status.tsv (matched/functional rows) plus this run
    va_owner = {}
    try:
        for line in open(os.path.join(ROOT, "progress", "status.tsv")):
            f = line.rstrip("\n").split("\t")
            if len(f) >= 4 and f[3] in ("matched", "functional"):
                va_owner[int(f[0], 16)] = f[2]
    except (OSError, ValueError):
        pass
    for rel, c in cache.items():
        for p_ in ((c.get("res") or {}).get("pairs") or {}).values():
            if p_.get("ok"):
                va_owner[p_["va"]] = rel

    def annotate(d):
        def one(m):
            va = int(m.group(1), 16)
            return m.group(0) + (f" [claimed by {va_owner[va]}]" if va in va_owner else "")
        return re.sub(r"0x([0-9a-f]+)(?= in the symbol table|$)", one, d)

    if a.check:
        ifc_cache = {}
        sel = {u.name for u in units}
        by_rel = {u.name: u.rel for u in all_units}
        for name, n, m, f, b, bmt, nv, vok, fail, bft in summary:
            if name not in sel:
                continue
            rel = by_rel.get(name)
            res = cache.get(rel, {}).get("res") or {}
            if a.functional:
                stubs = n - m - f
                if fail or n == 0 or stubs or vok != nv:
                    bad.append(f"{name}: " + ("COMPILE FAILED" if fail else
                                              f"{m + f}/{n} functions implemented ({stubs} stub), vftables {vok}/{nv}"))
                for d in res.get("symmismatch", []):
                    bad.append(f"{name}: symbol conflict: {annotate(d)}")
                if not os.environ.get("MS2_NO_LINT"):
                    lu = next((x for x in all_units if x.name == name), None)
                    lh = lint_unit(lu) if lu else []
                    for lf, ln, lr, lt in lh[:12]:
                        bad.append(f"{name}: lint: {lr} at {lf}:{ln}: {lt[:100]}")
                    if len(lh) > 12:
                        bad.append(f"{name}: lint: ... {len(lh) - 12} more")
                # exact interface (tools/interface_check.py, fx12): non-exact functions other units depend on need a
                # byte match or an `// MS2-FUNCTIONAL: <reason>`; a hard gate only for units not yet done
                if res and not fail:
                    import interface_check as ifc
                    if "states" not in ifc_cache:
                        ifc_cache["states"] = ifc.done_units()
                    qs = ifc.queue_state(name, ifc_cache["states"])
                    try:
                        rows = [r for r in ifc.check_unit(rel, name, res, os.path.join(CACHE, "obj", rel[:-4] + ".obj"),
                                                          ifc_cache, exe) if r["violation"]]
                    except Exception as ex:
                        rows = []
                        print(f"interface check skipped for {name}: {ex.__class__.__name__}: {ex}")
                    soft = os.environ.get("MS2_INTERFACE_WARN") or qs in ("done", "done-functional")
                    for r in rows:
                        line = f"{name}: interface: " + ifc.fmt_row(r)
                        if soft:
                            print("INTERFACE WARNING " + line)
                        else:
                            bad.append(line)
                ok_msg = (f"functional: OK (matched {m}/{n}, {f} functional, {bmt} of {b} bytes = "
                          f"{100.0 * bmt / b if b else 0:.1f}% exact, {100.0 * (bmt + bft) / b if b else 0:.1f}% implemented)")
            elif fail or n == 0 or m != n or vok != nv:
                bad.append(f"{name}: " + ("COMPILE FAILED" if fail else
                                          f"{m}/{n} functions matched ({f} functional, {n - m - f} stub), "
                                          f"vftables {vok}/{nv}"))
        for name in sorted(sel):
            for d in inconsistent.get(by_rel.get(name), []):
                bad.append(f"{name}: inconsistent symbol mapping: {d}")
        if not units:
            bad.append("no unit matches " + " ".join(a.filters))
    where = os.path.relpath(OUT, ROOT)
    print(f"{where}/symbols.tsv: {added} new; {where}/status.tsv, summary.txt written; {time.time() - t0:.1f}s")
    if a.check:
        for line in bad:
            print("CHECK FAILED " + line)
        if bad or (bm.CONFLICTS and not a.functional):
            sys.exit(1)
        if ok_msg:
            print(ok_msg)
        print("CHECK OK: " + ", ".join(u.name for u in units))


if __name__ == "__main__":
    import heavy_lock
    with heavy_lock.heavy():     # machine-wide memory limit (tools/heavy_lock.py); a no-op under merge.sh / unit_check
        main()
