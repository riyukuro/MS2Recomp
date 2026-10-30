#!/usr/bin/env python3
"""Per-unit compiler flag profiles (`// MS2-FLAGS: <profile>` in a src/ms2 unit; cmake/ms2-unit-profiles.cmake is the
single source of truth, parsed here so tools/progress.py builds the same command line as the DLL build).

    profile_of(text)            -> profile name or None (game code, the default)
    apply(game_flags, profile)  -> the unit's cl flag list: the game flags with the profile's overrides
    key(profile)                -> suffix for the per-unit compile cache key ('' for game code: no rebuilds)
    toolset_of(text)            -> `// MS2-TOOLSET: <toolset>` or None (the project's cl 19.16)
    toolset_flags(ts, profile)  -> the full cl flag list of a unit built by another toolset (vc9: no game flags)
    toolset_key(ts, profile)    -> cache key suffix for it
    unit_override(var, rel)     -> MS2_UNIT_TOOLSET / MS2_UNIT_SOURCE value for a unit ("<stem>=<value>,..." in the env)

cmake appends the profile's options after the game flags (later options win under cl); here the game options they
override are dropped instead, which gives the same codegen without cl's D9025 'overriding' warnings. The profile is
independent of the MSVC toolset a unit or library may select (ms2paths.find_cl_toolset): both compose.
"""
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CMAKE = os.path.join(ROOT, "cmake", "ms2-unit-profiles.cmake")
DIRECTIVE = re.compile(r"^[ \t]*//[ \t]*MS2-FLAGS:[ \t]*([A-Za-z0-9_]+)", re.M)
TOOLSET_DIRECTIVE = re.compile(r"^[ \t]*//[ \t]*MS2-TOOLSET:[ \t]*([A-Za-z0-9_]+)", re.M)

# game options a profile option replaces (same cl switch family)
_FAMILY = [(re.compile(r"^/O[dx12]$"), re.compile(r"^/O[dx12]$")),
           (re.compile(r"^/Ob\d$"), re.compile(r"^/Ob\d$")),
           (re.compile(r"^/GR-?$"), re.compile(r"^/GR-?$")),
           (re.compile(r"^/EH"), re.compile(r"^/EH")),
           (re.compile(r"^/fp:"), re.compile(r"^/fp:")),
           (re.compile(r"^/Zp\d*$"), re.compile(r"^/Zp\d*$"))]
_cache = None
_tcache = None


def profiles():
    """{name: (options, definitions)} from cmake/ms2-unit-profiles.cmake"""
    global _cache
    if _cache is None:
        txt = open(CMAKE).read()
        names = re.search(r"set\(MS2_UNIT_PROFILES ([^)]*)\)", txt).group(1).split()

        def listing(var):
            m = re.search(r"set\(" + var + r"\n(.*?)\n\)", txt, re.S)
            return re.findall(r'"([^"]+)"', m.group(1)) if m else []
        _cache = {n: (listing("MS2_PROFILE_%s_OPTIONS" % n), listing("MS2_PROFILE_%s_DEFINITIONS" % n)) for n in names}
    return _cache


def profile_of(text):
    m = DIRECTIVE.search(text)
    if not m:
        return None
    if m.group(1) not in profiles():
        raise ValueError("unknown MS2-FLAGS profile %r (known: %s)" % (m.group(1), ", ".join(profiles())))
    return m.group(1)


def apply(game_flags, profile):
    if not profile:
        return list(game_flags)
    opts, defs = profiles()[profile]
    out = []
    for f in game_flags:
        if any(g.match(f) and any(p.match(o) for o in opts) for g, p in _FAMILY):
            continue
        out.append(f)
    return out + opts + ["/D" + d for d in defs]


def key(profile):
    if not profile:
        return ""
    opts, defs = profiles()[profile]
    return " profile=%s:%s" % (profile, " ".join(opts + defs))


def toolsets():
    """{name: options} from cmake/ms2-unit-profiles.cmake (MS2_UNIT_TOOLSETS / MS2_TOOLSET_<name>_OPTIONS)"""
    global _tcache
    if _tcache is None:
        txt = open(CMAKE).read()
        names = re.search(r"set\(MS2_UNIT_TOOLSETS ([^)]*)\)", txt).group(1).split()

        def listing(var):
            m = re.search(r"set\(" + var + r"\n(.*?)\n\)", txt, re.S)
            return re.findall(r'"([^"]+)"', m.group(1)) if m else []
        _tcache = {n: listing("MS2_TOOLSET_%s_OPTIONS" % n) for n in names}
    return _tcache


def toolset_of(text):
    m = TOOLSET_DIRECTIVE.search(text)
    if not m:
        return None
    return check_toolset(m.group(1))


def check_toolset(ts):
    if ts not in toolsets():
        raise ValueError("unknown MS2-TOOLSET %r (known: %s)" % (ts, ", ".join(toolsets())))
    return ts


def toolset_flags(ts, profile):
    defs = profiles()[profile][1] if profile else []
    return ["/c"] + toolsets()[ts] + ["/D" + d for d in defs]


def toolset_key(ts, profile):
    return " toolset=%s:%s" % (ts, " ".join(toolset_flags(ts, profile)))


def unit_override(var, rel):
    """value of `var` ("<unit>=<value>,..."; <unit> = the file stem, or the path under src/ms2 without .cpp) for unit
    file `rel` (relative to src/ms2), else None"""
    spec = os.environ.get(var, "").strip()
    if not spec:
        return None
    stem = rel[:-4] if rel.endswith(".cpp") else rel
    for item in spec.split(","):
        k, sep, v = item.partition("=")
        if sep and k.strip() in (stem, stem.rsplit("/", 1)[-1]):
            return v.strip()
    return None


if __name__ == "__main__":
    import sys
    for p, (o, d) in profiles().items():
        print(p, o, d)
    if len(sys.argv) > 1:
        print(apply(["/Od", "/Ob0", "/Oi", "/EHsc", "/GS", "/GR", "/Gy", "/fp:fast", "/MD"], sys.argv[1]))
