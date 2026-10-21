# MS2Recomp

A work-in-progress recompilation of the MapleStory2 client (KMS2 dev build, x64, April 2022).

Functions recovered from the original executable are rewritten as C++ in `src/ms2/`, one file per original
compilation unit. They are built into a proxy `dinput8.dll`. When it is placed next to the original
`MapleStory2.exe`, it uses Microsoft Detours to redirect the original functions to the recompiled ones, so every
recovered function runs inside the real game. Many functions are already a byte-for-byte match of the original,
compiled with the same compiler (MSVC 14.16).

This repository contains only the recompiled code and what is needed to build it. It does not include the game, the
Gamebryo engine source or any other SDK. You need your own copies of those.

## Progress

![Progress: each block is a group of functions in the original exe, coloured by recompilation status](assets/progress.png)

Each block stands for a group of functions in the original executable, grouped by subsystem. **Matched** functions
compile to the same bytes as the original. **Equivalent** ones behave the same but differ in code generation.
**Awaiting match** and **In flight** are written or in progress but not yet merged. The image is regenerated on each
publish.

Merged totals by area (functions in the original executable; regenerated on each publish together with the image):

<!-- progress:start -->
| Area | Functions | Matched | Equivalent | Done |
|---|---:|---:|---:|---:|
| Game · ms2 | 179,369 | 168,470 (93.9%) | 10,653 (5.9%) | 99.9% |
| Runtime & middleware | 22,418 | 3,421 (15.3%) | 101 (0.5%) | 15.7% |
| Gamebryo engine | 16,620 | 14,816 (89.1%) | 137 (0.8%) | 90.0% |
| Game framework · egf | 11,596 | 11,346 (97.8%) | 137 (1.2%) | 99.0% |
| Libraries | 11,528 | 6,447 (55.9%) | 24 (0.2%) | 56.1% |
| Foundation | 11,189 | 10,430 (93.2%) | 437 (3.9%) | 97.1% |
| Imports | 782 | 8 (1.0%) | 1 (0.1%) | 1.2% |
| **Total** | **253,502** | 214,938 (84.8%) | 11,490 (4.5%) | 89.3% |
<!-- progress:end -->

## Layout

| Path | Contents |
|---|---|
| `src/ms2/` | recovered game code; `client/ms2/` and `commonfiles/` follow the original source paths, `unnamed/` and `guess/` hold units whose file name is unknown or guessed, and `placeholder/` holds partially recovered class layouts |
| `src/hook/` | the hook DLL runtime (`ms2hook.h` macros, differential tests, vendored Detours) |
| `cmake/` | toolchains (clang-cl, or real cl 19.16 under Wine or natively on Windows) and the game and engine compiler flags |
| `tools/msvc/` | wrappers that run MSVC 14.16 under Wine (Linux only; on Windows the real `cl.exe` is used directly) |
| `tools/ms2paths.py` | where the tools find the exe, maps and toolchain; the Linux/Wine and native Windows differences live here |
| `.gitattributes` | turns line-ending conversion off (`* -text`): patches, maps and sources must check out byte-exact |
| `tools/ms2symobj.py` | turns the symbol tables into the object that binds unrecovered names to their addresses in the exe |
| `progress/symbols*.tsv` | symbol name → address tables for the original exe, used by the DLL link |
| `engine-patches/` | our Gamebryo changes as SDK-free edit scripts against stock LightSpeed 3.2.0.661 (`tools/apply-engine-patches.sh`) |
| `data/map/` | function and unit tables for the original exe (names, address ranges, unit grouping) used by the gate tools |
| `tools/progress.py`, `tools/unit-check.sh`, ... | the byte-match and functional gates; see `CONTRIBUTING.md` |

## Requirements

- Either **Linux** with CMake 3.20+, Ninja, Python 3 and Wine, or **native Windows 10/11** with CMake 3.20+, Ninja, Python 3.10+
  and Git (no WSL, no Wine)
- MSVC 14.16 (VS2017 15.9, cl 19.16.27054) with MFC/ATL (MBCS) and the Windows 10 SDK 10.0.19041. Linux: installed with
  [msvc-wine](https://github.com/mstorsjo/msvc-wine) into `third_party/msvc/`. Windows: the Visual Studio 2017 Build Tools
  (v141 toolset); component IDs and setup in [`CONTRIBUTING.md`](CONTRIBUTING.md#windows-native-no-wsl-no-wine).
  `tools/check_toolchain.py` verifies either install against our hashes
- clang-cl and the LLVM tools (`llvm-nm`, `llvm-undname`), for the faster non-matching build and the gates
- Stock Gamebryo LightSpeed 3.2.0.661 source (not included), patched with `engine-patches/` into `engine/gamebryo/`
- DirectX SDK (June 2010) in `third_party/dxsdk/` and the NVIDIA PhysX SDK 2.8.4 in `third_party/physx284/`
- Optional: the Scaleform GFx 4.1 SDK. Without it, the build uses the placeholder types in `src/ms2/placeholder/`.
- The unpacked KMS2_DEV x64 `MapleStory2.exe` (TimeDateStamp `0x62568c46`) to run the DLL against

## Build

```sh
# clang-cl
cmake -G Ninja -S src -B build/hook-clang -DCMAKE_TOOLCHAIN_FILE=$PWD/cmake/toolchain-clangcl-x64.cmake
ninja -C build/hook-clang

# MSVC 14.16 under Wine (byte-matching flags)
cmake -G Ninja -S src -B build/hook-msvc -DCMAKE_TOOLCHAIN_FILE=$PWD/cmake/toolchain-msvc1416-wine.cmake
tools/ninja-msvc.sh -C build/hook-msvc
```

On native Windows, run the same commands from a shell that has the VS 2017 environment (`python tools\ms2paths.py shell`,
or prefix a command with `python tools\ms2paths.py run`), with the native toolchain in place of the Wine one:

```bat
cmake -G Ninja -S src -B build\hook-clang -DCMAKE_TOOLCHAIN_FILE=%CD%\cmake\toolchain-clangcl-x64.cmake
ninja -C build\hook-clang

rem MSVC 14.16 (byte-matching flags): the real cl.exe
cmake -G Ninja -S src -B build\hook-msvc -DCMAKE_TOOLCHAIN_FILE=%CD%\cmake\toolchain-msvc1416-native.cmake
ninja -C build\hook-msvc
```

The per-unit gate does these builds for you (`python tools\unit_check.py`). Both builds produce `dinput8.dll`. `-DMS2HOOK_WITH_GAME=OFF` builds the bare proxy with no hooks.

## Running

Copy `dinput8.dll` next to `MapleStory2.exe` and start the game (on Windows nothing else is needed; under Wine, set the DLL override `dinput8=n,b`).
The DLL writes `ms2hook.log` beside the exe, listing every hook as INSTALLED or REFUSED. Each hook checks a hash of
the original function's bytes, and the DLL refuses all hooks if the exe is not the expected build.

Environment switches: `MS2HOOK_DISABLE='*'` (or a list of names and addresses) turns hooks off,
`MS2HOOK_DIFFTEST=0` skips the differential tests, and `MS2HOOK_COUNT=0` turns off call counting.

## Contributing

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for the setup, the gates a unit has to pass, and how to claim a batch of units
from the issues.

## Legal

This project is not affiliated with Nexon. MapleStory2 is a trademark of Nexon. The repository contains no game
assets, executables or engine source.
