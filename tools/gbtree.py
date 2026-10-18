#!/usr/bin/env python3
"""Gamebryo engine units for tools/progress.py (engine mode): the v2525 recipe tree and the per-TU compile commands.

    python3 tools/gbtree.py [--tree DIR]          # (re)assemble the tree, print a summary
    python3 tools/gbtree.py --check               # also check that every unit's source resolves

engine/units-gb.json lists every engine TU twice-over at most, one entry per recipe:
  recipe "v2525": the per-TU flags/defines/forced includes/include order of the v2525 snapshot (work/ext/v2525,
                  units.json; -Zi -> -Z7). Its include dirs and sources are relative to an assembled tree with the
                  snapshot's layout (gamebryo/include/<Module>/..., gamebryo/overlay/<group>/...);
  recipe "stock": the build/gamebryo-msvc (engine/gamebryo/CMakeLists.txt) command of the same or an extra TU (Lua,
                  TinyXML, ecrInput, ...): /O2 /GR /EHsc, no forced includes.
progress.py compiles both and credits each exe function to whichever obj matches it best (the union).

The tree (build/gb-tree/, symlinks only, rebuilt when its inputs change) reproduces the snapshot exactly:
  - the files the snapshot patched or added (per-group variants, x64 shims) -> engine/gamebryo-v2525/{include,overlay}/,
    verbatim copies of the snapshot (their Nexon members use other names than our engine/gamebryo `// MS2:` edits, so
    the two header sets are not mixed);
  - unchanged SDK files (engine/gamebryo-v2525/SDK_FILES.tsv) -> the pristine SDK in third_party/gamebryo (fallback
    engine/gamebryo); $(D3DX) files -> third_party/dxsdk;
  - stock/: the generated include dirs of engine/gamebryo/CMakeLists.txt (DXSDK overlay, XInput, PCH forwarders).
Path variables in units-gb.json: $(TREE) the tree, $(ROOT) the repo, $(SDK) an SDK file (stock recipe: engine/gamebryo
first; v2525 recipe: the pristine SDK first), $(PHYSX) the PhysX 2.8.4 SDKs dir, $(D3DX) the DirectX SDK include dir.
"""
import argparse
import hashlib
import json
import os
import shutil
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ms2paths  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ENGINE = os.path.join(ROOT, "engine", "gamebryo")
V2525 = os.path.join(ROOT, "engine", "gamebryo-v2525")
UNITS_JSON = os.path.join(ROOT, "engine", "units-gb.json")
PRISTINE = os.path.join(ROOT, "third_party", "gamebryo", "APPDIR", "Source")
VC90 = os.path.join(ROOT, "third_party", "gamebryo", "APPDIR", "Build", "GameFramework", "Win32", "VC90")
D3DX = os.path.join(ROOT, "third_party", "dxsdk", "DXSDK", "Include")
PHYSX = os.path.join(ROOT, "third_party", "physx284", "PFiles", "NVIDIA Corporation", "NVIDIA PhysX SDK", "v2.8.4_win",
                     "SDKs")
TREE = os.path.join(ROOT, "build", "gb-tree")
WINSDK = ms2paths.winsdk_include()
# the generated include dirs of engine/gamebryo/CMakeLists.txt, rebuilt in the tree under stock/ for the stock recipe
PCH_FORWARD = ("Foundation/efd/efdPCH.h", "Foundation/efdLogService/efdLogServicePCH.h",
               "Foundation/efdNetwork/efdNetworkPCH.h", "Foundation/efdPhysX/efdPhysXPCH.h", "GameFramework/ecr/ecrPCH.h",
               "GameFramework/ecrInput/ecrInputPCH.h", "GameFramework/ecrPhysX/ecrPhysXPCH.h", "GameFramework/egf/egfPCH.h",
               "GameFramework/egfLua/egfLuaPCH.h", "GameFramework/egfPhysX/egfPhysXPCH.h",
               "GameFramework/egmAnimation/egmAnimationPCH.h", "GameFramework/egmVisualizers/egmVisualizersPCH.h",
               "GameFramework/egmVisualTracker/egmVisualTrackerPCH.h")

_idx = {}


def _index(top):
    if top not in _idx:
        m = {}
        for d, _, fs in os.walk(top):
            for f in fs:
                p = os.path.join(d, f)
                m[os.path.relpath(p, top).lower()] = p
        _idx[top] = m
    return _idx[top]


_byname = {}


def sdk_file(rel, pristine=False):
    """An SDK path relative to Engine/Source (any case) -> engine/gamebryo copy if we have it, else the pristine file
    (pristine=True: the pristine file first, as the v2525 snapshot copied it).
    Paths the snapshot got wrong (EngineLibs/ for ShaderLibs/UtilityLibs, Generated/ SWIG wrappers that ship in the
    SDK's Build/.../VC90/<lib>/Release/) fall back to the same file name with the most path components in common."""
    rel = rel.replace("\\", "/").lower()
    tops = (PRISTINE, ENGINE) if pristine else (ENGINE, PRISTINE)
    hit = _index(tops[0]).get(rel) or _index(tops[1]).get(rel)
    if hit:
        return hit
    if not _byname:
        for rank, top in enumerate((ENGINE, PRISTINE, VC90)):
            for k, v in _index(top).items():
                _byname.setdefault(os.path.basename(k), []).append((rank, k, v))
    want = set(rel.split("/")[:-1])
    cands = _byname.get(os.path.basename(rel), [])
    if not cands:
        return None
    order = (1, 0, 2) if pristine else (0, 1, 2)
    return max(cands, key=lambda c: (len(want & set(c[1].split("/")[:-1])), -order[c[0]], "/release/" in c[1]))[2]


def origin(o):
    if o.startswith("$(GB_SDK)/"):
        rest = o[len("$(GB_SDK)/"):]
        if rest.lower().startswith("engine/source/"):
            rest = rest[len("engine/source/"):]
        return sdk_file(rest, pristine=True)
    if o.startswith("$(D3DX)/"):
        return _index(D3DX).get(o[len("$(D3DX)/"):].lower())
    return None


def tree_map():
    """{tree-relative path: real file}"""
    m = {}
    for ln in open(os.path.join(V2525, "SDK_FILES.tsv")):
        if ln.startswith("#") or not ln.strip():
            continue
        dst, o = ln.rstrip("\n").split("\t")
        src = origin(o)
        if src:
            m[dst] = src
    # stock recipe (CMakeLists.txt): DXSDK headers the Windows SDK does not shadow, under their own and lower-case name
    # (dxsdk-overlay-include); XInput.h from the DXSDK even though it is shadowed (dxsdk-preferred-include)
    winsdk = {f.lower() for sub in ("um", "shared") for f in os.listdir(os.path.join(WINSDK, sub))}
    for f in os.listdir(D3DX):
        if f.lower() not in winsdk:
            for n in {f, f.lower()}:
                m["stock/dxsdk-overlay-include/" + n] = os.path.join(D3DX, f)
    for n in ("XInput.h", "xinput.h"):
        m["stock/dxsdk-preferred-include/" + n] = os.path.join(D3DX, "XInput.h")
    # NiSettingsDialog.cpp includes its resource header from its own dir (not part of the snapshot)
    m["gamebryo/overlay/gb-physx/NiSettingsDialog/NiSettingsDialogResource.hrc"] = os.path.join(
        PRISTINE, "CoreRuntime", "UtilityLibs", "NiSettingsDialog", "NiSettingsDialogResource.hrc")
    for sub in ("include", "overlay"):
        for d, _, fs in os.walk(os.path.join(V2525, sub)):
            for f in fs:
                p = os.path.join(d, f)
                m["gamebryo/" + os.path.relpath(p, V2525)] = p
    return m


def assemble(tree=TREE, verbose=False):
    """Symlink farm in `tree`; cheap when nothing changed (stamp = hash of the map)."""
    m = tree_map()
    key = hashlib.sha1(json.dumps([sorted(m.items()), PCH_FORWARD]).encode()).hexdigest()
    stamp = os.path.join(tree, ".stamp")
    if os.path.exists(stamp) and open(stamp).read() == key:
        return tree, m
    if os.path.isdir(tree):
        shutil.rmtree(tree)
    for rel, src in m.items():
        dst = os.path.join(tree, rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        if not os.path.lexists(dst):
            ms2paths.link_or_copy(src, dst)
    os.makedirs(os.path.join(tree, "include"), exist_ok=True)     # the snapshot's game include dir (unused by engine TUs)
    for h in PCH_FORWARD:     # gb_pch_forwarder(): the libs' PCH headers, which are not on their include path
        d = os.path.join(tree, "stock", "pch-forward", os.path.basename(os.path.dirname(h)))
        os.makedirs(d, exist_ok=True)
        open(os.path.join(d, os.path.basename(h)), "w").write(f'#include "{os.path.join(ENGINE, h)}"\n')
    open(stamp, "w").write(key)
    if verbose:
        print(f"assembled {tree}: {len(m)} files")
    return tree, m


def lib_of(path):
    """engine/gamebryo/<Area>/<Lib>/... (or the pristine SDK) -> Lib; 3rdParty/<Lib>/..."""
    real = os.path.realpath(path)
    for top in (ENGINE, PRISTINE):
        if real.startswith(top + "/"):
            parts = os.path.relpath(real, top).split("/")
            if parts[0] in ("CoreRuntime",) and len(parts) > 2:
                return parts[2]
            return parts[1] if len(parts) > 1 else parts[0]
    return None


def expand(s, tree=TREE):
    return (s.replace("$(TREE)", tree).replace("$(ROOT)", ROOT).replace("$(PHYSX)", PHYSX).replace("$(D3DX)", D3DX))


def load_units(tree=TREE):
    """[{name, recipe, unit, source, cmd}] with every path resolved; source None when it does not exist."""
    out = []
    doc = json.load(open(UNITS_JSON))
    for u in doc["units"]:
        u = dict(u, flags=doc["flags"][u["flags"]], include_dirs=doc["include_dirs"][u["include_dirs"]])
        src = u["source"]
        if src.startswith("$(SDK)/"):
            src = sdk_file(src[len("$(SDK)/"):], pristine=u["recipe"] == "v2525")
        else:
            src = expand(src, tree)
            if not os.path.isabs(src):
                src = os.path.join(tree, src)
            if not os.path.exists(src):
                src = None
        cwd = tree if u["recipe"] == "v2525" else ROOT
        inc = []
        for d in u["include_dirs"]:
            d = expand(d, tree)
            inc.append("/I" + (d if os.path.isabs(d) else os.path.join(cwd, d)))
        flags = []
        for f in u["flags"]:
            f = expand(f, tree)
            if f.startswith("-FI") and "/" in f[3:] and not os.path.isabs(f[3:]) and os.path.exists(os.path.join(tree, f[3:])):
                f = "-FI" + os.path.join(tree, f[3:])
            flags.append(f)
        out.append(dict(name=u["name"], recipe=u["recipe"], unit=u["unit"], source=src, cwd=cwd,
                        args=flags + ["-D" + d for d in u["defines"]] + inc))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--tree", default=TREE)
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args()
    tree, m = assemble(a.tree, verbose=True)
    if a.check:
        us = load_units(tree)
        miss = [u for u in us if not u["source"]]
        print(f"{len(us)} units, {len(miss)} without source")
        for u in miss:
            print("  no source:", u["recipe"], u["name"])
        sys.exit(1 if miss else 0)


if __name__ == "__main__":
    main()
