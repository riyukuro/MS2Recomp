#!/usr/bin/env python3
"""Per-unit compiler flag profiles (`// MS2-FLAGS: <profile>` in a src/ms2 unit; cmake/ms2-unit-profiles.cmake is the
single source of truth, parsed here so tools/progress.py builds the same command line as the DLL build).

    profile_of(text)            -> profile name or None (game code, the default)
    apply(game_flags, profile)  -> the unit's cl flag list: the game flags with the profile's overrides
    key(profile)                -> suffix for the per-unit compile cache key ('' for game code: no rebuilds)

cmake appends the profile's options after the game flags (later options win under cl); here the game options they
override are dropped instead, which gives the same codegen without cl's D9025 'overriding' warnings. The profile is
independent of the MSVC toolset a unit or library may select (ms2paths.find_cl_toolset): both compose.
"""
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CMAKE = os.path.join(ROOT, "cmake", "ms2-unit-profiles.cmake")
DIRECTIVE = re.compile(r"^[ \t]*//[ \t]*MS2-FLAGS:[ \t]*([A-Za-z0-9_]+)", re.M)

# game options a profile option replaces (same cl switch family)
_FAMILY = [(re.compile(r"^/O[dx12]$"), re.compile(r"^/O[dx12]$")),
           (re.compile(r"^/Ob\d$"), re.compile(r"^/Ob\d$")),
           (re.compile(r"^/GR-?$"), re.compile(r"^/GR-?$")),
           (re.compile(r"^/EH"), re.compile(r"^/EH")),
           (re.compile(r"^/fp:"), re.compile(r"^/fp:")),
           (re.compile(r"^/Zp\d*$"), re.compile(r"^/Zp\d*$"))]
_cache = None


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


if __name__ == "__main__":
    import sys
    for p, (o, d) in profiles().items():
        print(p, o, d)
    if len(sys.argv) > 1:
        print(apply(["/Od", "/Ob0", "/Oi", "/EHsc", "/GS", "/GR", "/Gy", "/fp:fast", "/MD"], sys.argv[1]))
