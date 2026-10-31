# Building the full executable

One command builds `fullexe<N>.exe` from this checkout plus SDKs you supply yourself. No SDK, object file or generated
import library is ever part of the repository.

```
cmake --preset fullexe && cmake --build build/fullexe
```

The result is `build/fullexe/out/MapleStory2.exe`, a copy of `fullexe3.exe` next to it (link log and map there too). Rebuilding after an edit recompiles only
the changed translation units; the link reads every object where the compile cache keeps it (a response file), so no
copy of the objects is made.

## Prerequisites

- Linux with Wine, or Windows with the VS2017 v141 toolset; the MSVC 14.16 cl/link and the Windows SDK 10.0.19041
  (`tools/toolchain-manifest.tsv` pins them, `tools/check_toolchain.py --quick` verifies them).
- For the units that declare `// MS2-TOOLSET:`, the old compilers the exe's prebuilt libraries were built with. Each
  goes into a gitignored `third_party/` dir and is checked against its manifest (`--check`).
  - vc9: cl 15.00.30729 for the CRI Movie decoder (`tools/fetch-vc9.sh`, from the WDK 7.1 ISO).
  - vc11: cl 17.00.61030 for the Scaleform Video add-on (`tools/fetch-vs2012.sh`, from Microsoft's VS2012.4.iso and
    VS2012_WDX_ENU.iso; `--download` fetches both). It installs the VS2012 Update 4 compiler and VC headers and the
    Windows SDK 8.0 headers.
- CMake 3.25 or newer, Ninja, Python 3 with the packages of `tools/` (the default is `.venv/bin/python`; override with
  `-DMS2_PYTHON=...`), LLVM binutils (`llvm-nm`, `llvm-undname`).
- The original x64 `MapleStory2.exe` (KMS2_DEV build): `-DMS2_EXE=<file>` or the `MS2_EXE` environment variable, else `Game Versions/KMS2_DEV/x64/MapleStory2.exe` in the checkout (verified by `tools/check_exe.py`).
- One free heavy slot (`tools/heavy_lock.py`): the link and the compile stage take it. The slots are files in `work/locks/`;
  a second checkout on the same machine shares them with `MS2_LOCK_DIR=<first checkout>/work/locks`.
- About 60 GB of free disk and 16 GB of RAM for a clean build.

## Your SDKs

Each root is a CMake cache variable. Left empty, it defaults to the in-tree location that `CONTRIBUTING.md` describes.
At configure time every root is checked against `cmake/sdk-manifest.txt`, which lists file names and SHA-256 values only;
a missing or different file stops the configure with the variable name.

| Variable | Contents |
| --- | --- |
| `MS2_GAMEBRYO_ROOT` | the directory that holds `gamebryo/`: Gamebryo LightSpeed 3.2.0.661 after `tools/apply-engine-patches.sh engine-patches <dir>/gamebryo`, and `fmt-ms2/`: `format.cc` and `format.h` of upstream cppformat (fmt) commit 5ca3d00e2 (BSD 2-clause) after `tools/apply-engine-patches.sh fmt-patches <dir>/fmt-ms2` (default `engine/`) |
| `MS2_DXSDK_ROOT` | DirectX SDK June 2010; must be `dxsdk/DXSDK` under the `MS2_MSVC_ROOT` directory (see below) |
| `MS2_PHYSX_ROOT` | PhysX 2.8.4 SDK; must be `physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win` under `MS2_MSVC_ROOT` |
| `MS2_CEF_ROOT` | CEF 3.3396 binary distribution (`cef_binary_3.3396.1786.gd3e36d0_windows64_minimal`); must be under `src/` of `MS2_MSVC_ROOT` |
| `MS2_PATHENGINE_ROOT` | PathEngine evaluation sources; must be `src/pathengine-sigmaco` under `MS2_MSVC_ROOT` (game sources include them as `<pathengine-sigmaco/...>`, see below) |
| `MS2_MSVC_ROOT` | a directory in the `third_party/` layout that the tools read (`MS2_THIRD_PARTY`): `msvc/` (MSVC 14.16 + Windows SDK, msvc-wine), `dxsdk/`, `physx284/`, and under `src/` the statically linked library sources `cryptopp562`, `jpeg-6b`, `libpng-1.6.17`, `lua-5.1.4`, `expat-2.0.1`, `zlib-1.2.3`, `pcre-8.21`, `pathengine-sigmaco` and the CEF distribution, plus `fmod44464/` and `razer/` (headers); default `third_party/` |

The library sources are the upstream releases, unmodified, and none of them is redistributed here. `pcre-8.21` is upstream PCRE 8.21 (BSD) prepared the way its `NON-UNIX-USE` describes for a build without `configure`: `cp pcre.h.generic pcre.h` and `cp pcre_chartables.c.dist pcre_chartables.c`; the build settings are `-D` defines in `data/engine/units-lib-pcre.json`, so no `config.h` is needed.

Example: `cmake --preset fullexe -DMS2_GAMEBRYO_ROOT=<dir> -DMS2_MSVC_ROOT=<dir>`.

Game sources name these SDKs by include path only (`<cryptopp562/...>`, `<pathengine-sigmaco/...>`, `<zlib-1.2.3/...>`,
`<fmod44464/...>`, `<razer/...>`; the include roots are `MS2_THIRD_PARTY_INCLUDE_DIRS` in `cmake/ms2-engine-flags.cmake`),
so the roots may live anywhere.

## Stages

Each is a CMake target that runs the matching `tools/fullexe` script unchanged, in this order: `compile` (incremental
per-unit cache), `plan`, `implibs`, `asm`, `link0` (open link), `defsyms`, `analyze0`, `alias` and `order` (generated
glue), `link1`, `analyze1`, `shim` and `rsrc` (generated stubs, ABI adapters, resources), `crtinit`, `initorder`, and
`link2` (the closed link). `cmake --build build/fullexe --target <stage>` runs the chain up to that stage.

## Resources

By default the `rsrc` stage builds `shim/exe.res` straight from your exe's `.rsrc` tree (`tools/fullexe/rsrc.py`).
`tools/extract_resources.py` turns the same resources into an ordinary resource script for a plain Visual Studio build:

```
python tools/extract_resources.py [MapleStory2.exe]     # -> resources/MapleStory2.rc + one file per resource
python tools/extract_resources.py --compile             # rc.exe (14.16 toolchain) -> resources/MapleStory2.res
```

It checks the exe first (the `tools/check_exe.py` hash and TimeDateStamp 0x62568C46). Icons become real `.ico` files
(`2000 ICON "...ico"`) and bitmaps real `.bmp` files. Dialogs (DIALOGEX), menus and VERSIONINFO are decompiled to `.rc`
text. String tables, HTML, DLGINIT, AFX_DIALOG_LAYOUT and the manifest (`1 24`) are raw includes. Every entry keeps its
LANGUAGE. Compiled with rc.exe, the result has the same entries (type, name, language, data bytes) as `rsrc.py`'s
exe.res: `python tools/extract_resources.py --compare a.res b.res` checks this. To link that .res instead of reading the
exe, pass `-DMS2_RESOURCES_RES=<path>/MapleStory2.res`.

`resources/` holds Nexon's data. It is gitignored, and the publish script refuses any resource file.

## Committed lists instead of exe reads

These options are off by default. Each one replaces an exe read with a committed list of names or addresses (no exe
bytes), and gives the same stage output:

- `-DMS2_IMPORTS_FROM_LIST=ON`: the `implibs` stage builds the import libs from `data/fullexe/imports.tsv` (the exe's
  import names, the shipped `libcef.dll` export names and the extra imports), so it needs neither the exe nor
  `libcef.dll`. `tools/fullexe/implibs.py --write-imports <file>` regenerates the list.
- `-DMS2_CRTINIT_FROM_LIST=ON`: the `crtinit` stage reads the exe's static-initializer table (the `.CRT$XC*`/`.CRT$XI*`
  pointers, in order) from `data/fullexe/crtinit-exe.tsv`; `initorder` then gives the same `--before` list.
  `tools/fullexe/crtinit.py --write-exe-table <file>` regenerates it.

## How much glue is left

`tools/fullexe/gluecount.py` appends a dated row to `progress/glue-metrics.tsv` (alias pairs, ABI adapters, trap
stubs, duplicate symbols, unresolved symbols before the shim, `/FORCE` flags, boot patch files, signature clashes).

## Plain link (prototype)

`cmake/fullexe-plain/` links the exe once and runs no Python at build time. It writes the import-lib `.def` files from
`data/fullexe/imports.tsv`, assembles the CryptoPP MASM objs and compiles `shim_runtime.cpp` itself. Everything else
comes from the glue files in `data/fullexe/plain/`: `objs.txt` (the obj list in link order), `alias.rsp` (the
`/alternatename` lines) and `stubs.tsv` (the data stubs, names and addresses only). They are generated from the newest
`cmake/fullexe` build that linked and passed. By default the objs come from that kind of build's compile cache
(`MS2_PLAIN_OBJ_ROOT`); `-DMS2_PLAIN_COMPILE=ON` compiles them instead (see Compile list below). The one remaining data stub is extracted once from your exe
with `plainglue.py stubs <exe> data/fullexe/plain/stubs.tsv <obj>`:

```
cmake -S cmake/fullexe-plain -B build/fullexe-plain -G Ninja -DMS2_PLAIN_OBJ_ROOT=build/progress-<tag> \
      -DMS2_PLAIN_STUBS_OBJ=<obj> -DMS2_RESOURCES_RES=<res> && cmake --build build/fullexe-plain
```

The result is `build/fullexe-plain/out/MapleStory2.exe`, a copy of `fullexe-plain.exe`. The `/ORDER` list (`order.txt`,
32 MB) is not committed, so by default the linker lays functions out in its own order. To get the exe's layout, run
`tools/fullexe/plainglue.py write <dir>` on a finished `cmake/fullexe` build and pass `-DMS2_PLAIN_GLUE=<dir>`
(`MS2_PLAIN_ORDER` turns on when `<dir>/order.txt` exists). With `-DMS2_PLAIN_NAME=fullexe3`, that build's glue and its
objs, the result is byte-identical to `link2`'s `fullexe3.exe` except for the link timestamp. The exe's export directory
records the output name, so the default name shifts some `.rdata` bytes.

Refreshing the glue (maintainers): after each applied merge, once that commit's fullexe-latest build has linked and
passed, run `tools/fullexe/plainglue.py write data/fullexe/plain` with `FULLEXE_DIR` and `--cache` pointing at that
build. Delete the `order.txt` it writes, then commit `objs.txt`, `alias.rsp` and `stubs.tsv` together.

### Compile list

`tools/fullexe/plainglue.py compile <dir> --cache <obj cache>` writes the cl command of every obj in `<dir>/objs.txt`,
as the finished build ran it, and checks each one against the flags key its `.deps` recorded:

- `compile.tsv`: obj, tool, working dir, source, flag set. The tool is `cl` (14.16) or the unit's `MS2-TOOLSET`
  (`vc9`, `vc9c`, `vc11`, `1414`, `1415`). Game units carry their `MS2-FLAGS` profile; engine and library units their
  `data/engine` flags.
- `flags.tsv`: one row per distinct flag set (no `/Fo`, no `/showIncludes`).
- `tree.tsv`: the generated include dirs those commands name (`build/gb-tree` and the DirectX overlays), as symlinks or
  one-line files.

Paths are written as `${TP}`, `${ENGINE}`, `${GEN}` and `${ROOT}`. With `-DMS2_PLAIN_COMPILE=ON` the plain build
fills them from `MS2_MSVC_ROOT`, `MS2_PLAIN_ENGINE`, `MS2_PLAIN_GEN` and `MS2_PLAIN_CHECKOUT`, recreates `tree.tsv`
under `MS2_PLAIN_GEN`, and makes one custom command per obj into `<build>/cache`. Header dependencies are not tracked
(no depfile); a header edit needs a clean rebuild. MS2_PCH=1 builds are not supported.

What matches: compiled from the same checkout and SDKs, every obj's code, data, relocations and symbols are identical
to the compile cache's (checked on 83 objs: 50 game, 10 vc9, 3 vc11, 10 engine, 10 Scaleform). Only the `/Z7` debug
sections differ, and only in recorded paths: the obj's own `/Fo` path, the `${GEN}` dir and the command line (no
`/showIncludes`). The link uses `/debug:none`, so those sections do not reach the exe. The checkout path itself does
not leak into code or data in the sample.

A full `-DMS2_PLAIN_COMPILE=ON` build (3637 steps, about 85 minutes at `-j16`) of a clean worktree with that build's glue
and `-DMS2_PLAIN_NAME=fullexe3` gave an exe identical to `link2`'s `fullexe3.exe` except for 4 bytes, the link
timestamps in the COFF header and the debug directory. The objs are not byte-identical files. That would need the same `/Fo`
dir, the same `${GEN}` dir and `/showIncludes`.

On Windows with Visual Studio:

- VS opens `cmake/fullexe-plain` directly (Open Folder, or a `CMakePresets.json` entry with the cache variables above);
  the Ninja generator is the tested one.
- The 14.16 `cl` comes from the developer environment. Set `MS2_CL_1414` / `MS2_CL_1415` to those toolsets' `cl.exe`,
  or the 14.16 compiler builds those units too (not byte-identical).
- `vc9`, `vc9c` and `vc11` need `MS2_CL_<tool>` set to a `.cmd` wrapper that sets that compiler's own `INCLUDE`/`LIB`
  and runs its `cl.exe`; the commands otherwise inherit the 14.16 environment. The `tools/msvc9/cl`-style wrappers the
  Linux build uses are bash scripts with their own Wine prefix and are the only Wine-specific part.
- Command lines reach 9.6 KB, over cmd.exe's limit, so on Windows each flag set goes into a response file
  (`<build>/out/cl/<id>.rsp`). This path is untested.
- `tree.tsv` symlinks need Developer Mode or an elevated prompt; without it CMake copies the target instead.
- Flag-set arguments containing `$(` (unexpanded `$(GB_SDK)` include dirs that name no dir) are dropped, since Ninja and
  MSBuild would both read them as variables.
