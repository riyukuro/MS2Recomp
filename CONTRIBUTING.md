# Contributing

The work here is recovering the MapleStory2 client function by function. A unit is one original compilation unit,
written as `src/ms2/<path>.cpp`, and it is done when the gates below pass. Batches of units are handed out as GitHub
issues labelled `unit-batch`.

## What you need to supply

None of this is in the repository.

| What | Where it goes |
|---|---|
| The KMS2_DEV x64 `MapleStory2.exe` | `Game Versions/KMS2_DEV/x64/MapleStory2.exe`, or set `MS2_EXE`. Run `tools/check-exe.sh`: it must print `OK` (SHA-256 check) |
| MSVC 14.16 (VS2017 15.9, cl 19.16.27054), MFC/ATL MBCS, Windows 10 SDK 10.0.19041 | `third_party/msvc/`, installed with [msvc-wine](https://github.com/mstorsjo/msvc-wine) (`vsdownload.py --manifest` for 15.9, then `install.sh`). `tools/msvc/*` wrap it under Wine |
| Gamebryo 3.2.0.661 source with the engine patches (coming separately) | `engine/gamebryo/` |
| DirectX SDK June 2010, PhysX 2.8.4 | `third_party/dxsdk/`, `third_party/physx284/` |
| Scaleform GFx 4.1.x SDK headers (the game uses 4.1.18; 4.1.19 headers also work) | `work/scaleform/4.1.19/Scaleform`, or set `MS2_SCALEFORM_SDK`. Optional: without it the placeholder types are used |
| Exe-derived maps: `functions.tsv`, `units.tsv`, `rtti_classes.tsv`, `rtti_vftables.tsv` | `work/map/` and `work/classes/`. The two RTTI files are regenerated from the exe by `tools/regen-map.sh rtti`. `functions.tsv` and `units.tsv` come from the maintainer (they are derived from a curated Ghidra project; `tools/regen-map.sh ghidra` gives an approximation) |

Everything is looked up relative to the checkout. To keep a file elsewhere, set the matching variable instead:
`MS2_EXE`, `MS2_MAP_DIR`, `MS2_CLASSES_DIR`, `MS2_THIRD_PARTY`, `MS2_ENGINE_DIR`, `MS2_WINEPREFIX`,
`MS2_SCALEFORM_SDK` (see `tools/ms2paths.py`).

Host: Linux with Wine, CMake 3.20+, Ninja, clang-cl and LLVM tools (`llvm-undname`, `llvm-nm`) on PATH, Python 3 with
`pip install -r requirements.txt`. Put a virtualenv at `.venv/` (the scripts use `.venv/bin/python`).

## Claiming a batch

1. Open an issue labelled `unit-batch` and comment that you take it. Do not start units from a batch someone else holds.
2. Tick nothing yourself; the maintainer ticks a unit when its PR has been applied.
3. If you cannot finish a unit, say which one and why (for example "needs a shared type X") in the issue.

## Working on a unit

A unit's source starts with a header block:

```
// MS2-UNIT: <unit name from the issue>
// MS2-RANGE: 0x14190eac0-0x141910480 .text$mn
// MS2-RANGE: 0x140111d60-0x140111ef1 .text$di
```

Use the ranges from the issue. Every function in them is compiled by the same toolchain and compared byte by byte to
the exe. Write typed, behaviour-equivalent C++ (no Ghidra names such as `param_1` or `plVar1`, no raw offset
arithmetic where a member would do). Where exact bytes will not come out, mark the function
`// MS2-FUNCTIONAL: <reason>` after at most two attempts.

Set `export MS2_AGENT=<yourname>` first in every shell that runs the tools. It selects a private cache under
`build/progress-<yourname>/`, so the tools never write the shared `progress/` files.

## The gates

Iterate with:

    python tools/progress.py --agent <yourname> --force --functional --check <unit-substring>

It must print `CHECK OK`. Before you open a PR, run once:

    tools/unit-check.sh --functional <unit-substring>

It must print `functional gate: OK` and `DLL link: OK`. The functional gate means:

- every function in the unit's ranges is either byte-identical (`matched`) or implemented in source (`functional`), no
  `stub`;
- every vftable of the unit's classes is paired with the exe and matches slot by slot;
- the unit raises no symbol conflict with the committed tables;
- both hook DLLs (cl 19.16 and clang-cl) link.

Template glue (STL/ATL instantiations) is paired with `tools/tplpin.py <unit-substring>`.

## Pull requests

- One PR per unit or per batch, changing `src/` only.
- Do not edit `progress/`, `assets/` or anything under `tools/`, `cmake/`. If you need a new symbol-table row, list it in
  the PR description.
- PRs are not merged on GitHub: the mirror is regenerated from the maintainer's repository. The maintainer applies the
  PR locally after re-running the gates and credits you in the commit.
- State in the PR which units it covers and the output of both gates (exact/functional counts).
- Do not add anything derived from the exe other than the recovered source: no disassembly dumps, no byte listings,
  no decompiler output.
