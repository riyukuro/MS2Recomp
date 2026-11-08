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
- CMake 3.20 or newer, Ninja, Python 3 with the packages of `tools/` (the default is `.venv/bin/python`; override with
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
| `MS2_GAMEBRYO_ROOT` | the directory that holds `gamebryo/`: Gamebryo LightSpeed 3.2.0.661 after `tools/apply-engine-patches.sh engine-patches <dir>/gamebryo`, and `fmt-ms2/`: `format.cc` and `format.h` of upstream cppformat (fmt) commit 5ca3d00e2 (BSD 2-clause) after `tools/apply-engine-patches.sh fmt-patches <dir>/fmt-ms2`, and `gamebryo-v2525/`, made from the pristine Source by `engine-patches-v2525/` (configure does this; see "Engine trees" below) (default `engine/`) |
| `MS2_DXSDK_ROOT` | DirectX SDK June 2010; must be `dxsdk/DXSDK` under the `MS2_MSVC_ROOT` directory (see below) |
| `MS2_PHYSX_ROOT` | PhysX 2.8.4 SDK; must be `physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win` under `MS2_MSVC_ROOT` |
| `MS2_CEF_ROOT` | CEF 3.3396 binary distribution (`cef_binary_3.3396.1786.gd3e36d0_windows64_minimal`); must be under `src/` of `MS2_MSVC_ROOT` |
| `MS2_PATHENGINE_ROOT` | PathEngine evaluation sources; must be `src/pathengine-sigmaco` under `MS2_MSVC_ROOT` (game sources include them as `<pathengine-sigmaco/...>`, see below) |
| `MS2_MSVC_ROOT` | a directory in the `third_party/` layout that the tools read (`MS2_THIRD_PARTY`): `msvc/` (MSVC 14.16 + Windows SDK, msvc-wine), `gamebryo/APPDIR/Source` (the stock Gamebryo 3.2.0.661 Source, unpatched), `dxsdk/`, `physx284/`, and under `src/` the statically linked library sources `cryptopp562`, `jpeg-6b`, `libpng-1.6.17`, `lua-5.1.4`, `expat-2.0.1`, `zlib-1.2.3`, `pcre-8.21`, `pathengine-sigmaco` and the CEF distribution, plus `fmod44464/` and `razer/` (headers); default `third_party/` |

The library sources are the upstream releases, unmodified, and none of them is redistributed here. `pcre-8.21` is upstream PCRE 8.21 (BSD) prepared the way its `NON-UNIX-USE` describes for a build without `configure`: `cp pcre.h.generic pcre.h` and `cp pcre_chartables.c.dist pcre_chartables.c`; the build settings are `-D` defines in `data/engine/units-lib-pcre.json`, so no `config.h` is needed.

Example: `cmake --preset fullexe -DMS2_GAMEBRYO_ROOT=<dir> -DMS2_MSVC_ROOT=<dir>`.

### Engine trees

The build uses two trees made from one stock Gamebryo 3.2.0.661 tree, and the order matters:

1. `gamebryo-v2525/` is made from the pristine `APPDIR/Source` with `engine-patches-v2525/`:
   `tools/apply-engine-patches.sh engine-patches-v2525 <third_party>/gamebryo/APPDIR/Source <engine dir>/gamebryo-v2525`
   (Windows: `python tools\apply_engine_patches.py ...` with the same arguments). It writes only to the third argument.
   Configure runs this step itself (`cmake/v2525.cmake`) when `gamebryo-v2525/` is missing and Python is found, and stops
   if `engine-patches-v2525/` changed since (delete `gamebryo-v2525/` and configure again).
2. `engine-patches/` is applied to a separate copy of `APPDIR/Source`, `<engine dir>/gamebryo/`.

The SDK copy under `<third_party>/gamebryo/` must stay unpatched: the build also compiles about 4,000 of its files as
they are, and step 1 checks every stock hash and refuses on a patched tree. Never apply `engine-patches/` to it in place.

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

The plain link below has no `rsrc` stage: it links the `.res` named by `MS2_RESOURCES_RES`. Left empty, rc compiles
the stand-in `cmake/fullexe-plain/standin/standin.rc` to `<build>/standin.res` and the link takes that. The stand-in is
written for this repo and holds nothing of the exe's: its own icon 2000 (`standin.ico`, drawn by `mkicon.py` there),
manifest 1 (Common Controls 6, asInvoker, DPI aware), and plain English dialogs with the control IDs the client binds:
3000 (out of memory: buttons 8 and 10, SysLink 1034, text 1035), 3001 (error: button 11, text 1036), 148 and 150 (a
WebBrowser control, 1236 and 1237), plus a VERSIONINFO reading "MS2Recomp stand-in". It lacks the exe's dev dialogs,
menus, bitmaps and strings, its dialogs look different, and the exe's `.rsrc` does not byte-match the original. For the
original resources, pass the `.res` built from your exe (the commands above).

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
(`MS2_PLAIN_OBJ_ROOT`); `-DMS2_PLAIN_COMPILE=ON` compiles them instead (see Compile list below). The one remaining data
stub, `g_physXItem`, lies in the exe's `.bss`. Its obj is zero fill only (no exe bytes), so it is committed as
`data/fullexe/plain/stubs.obj`, the default of `MS2_PLAIN_STUBS_OBJ`. `plainglue.py stubs <exe> data/fullexe/plain/stubs.tsv <obj>`
writes it from the exe and reports whether it holds exe bytes:

```
cmake -S cmake/fullexe-plain -B build/fullexe-plain -G Ninja -DMS2_PLAIN_OBJ_ROOT=build/progress-<tag> \
      [-DMS2_RESOURCES_RES=<res>] && cmake --build build/fullexe-plain
```

The result is `build/fullexe-plain/out/MapleStory2.exe`, a copy of `fullexe-plain.exe`. The `/ORDER` list (`order.txt`,
32 MB) goes into the glue as `order.tar.xz` (1.7 MB, `plainglue.py pack <dir>`). The plain build unpacks it into
`<build>/glue/` at configure time, and `MS2_PLAIN_ORDER` turns on when either file exists. Without it, the linker lays
functions out in its own order. With `-DMS2_PLAIN_NAME=fullexe3`, a build's glue (`plainglue.py write <dir>` on a
finished `cmake/fullexe` build, `-DMS2_PLAIN_GLUE=<dir>`) and its objs, the result is byte-identical to `link2`'s
`fullexe3.exe` except for the link timestamp. The exe's export directory records the output name, so the default name
shifts some `.rdata` bytes.

#### Refreshing the glue (maintainers only)

This needs an exe-reading `cmake/fullexe` build. `glue-refresh.sh`, `latest.sh`, the `work/` dirs and
`publish-github.sh` named here are maintainer files and are not in the published repo. After each applied merge, once
that commit's fullexe-latest build has linked and passed, run these against that build, with `FULLEXE_DIR` and
`--cache` pointing at it:

1. `tools/fullexe/plainglue.py write data/fullexe/plain`
2. `plainglue.py compile data/fullexe/plain` (in that build's checkout and environment)
3. `plainglue.py pack data/fullexe/plain`

Then delete `order.txt` and commit `objs.txt`, `alias.rsp`, `stubs.tsv`, `order.tar.xz`, `compile.tsv`, `flags.tsv` and
`tree.tsv` together. Rerun `plainglue.py stubs` and commit `stubs.obj` only when `stubs.tsv` changes and the tool still
reports zero fill. The glue names that build's objs, so a checkout other than that commit links only by luck: a
renamed, added or removed unit breaks the link (LNK1120).

`tools/fullexe/glue-refresh.sh [--commit]` runs those steps in one command, from the latest published
`fullexe-latest` build. It takes `work/fx29/fx/fullexe-latest.glue`, which `latest.sh` publishes only on a smoke
PASS. If that dir holds no glue for the published commit (a `latest.sh --loop` started before 10-30 keeps none), the
script runs step 1 itself on the build's `out` dir, after checking that `out/fullexe3.exe` is the published exe. It
writes a `commit` file naming the build's commit. Run it while up1's worktree is still at that commit; the script stops
once the worktree has moved on. It also stops when `stubs.tsv` changed. It does not open the original exe.

Each published merge carries fresh glue: after `work/merge/<rev8>/apply.sh` and before `tools/publish-github.sh`, run
`MS2_AGENT=<name> tools/fullexe/glue-refresh.sh --commit`. It commits the glue for the newest smoke-passed
`fullexe-latest` build, which can be older than the merge. The published tip must be that build's own sources, so
`glue-refresh.sh --side <branch> [--overlay <path>]...` makes a side commit: parent the build's commit, tree that commit
with the refreshed glue (plus any `--overlay` path, such as this file, as master has it). `PUBLISH_REV=<branch>
tools/publish-github.sh` then publishes that commit instead of master. When the script stops because up1's worktree
has moved past the published build, refresh after the next smoke PASS. When it stops because `stubs.tsv` changed, run
`plainglue.py stubs` against an exe first (above).

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
`/showIncludes`). The link uses `/debug:none`, so those sections do not reach the exe. The checkout path does reach
the exe, though: about 17.7k `__FILE__` strings (asserts, `MS2Ptr` and engine logging) hold the source path as spelled
on the compiler command line, and the anonymous-namespace names (`?A0x<hash>`) hash it, which also moves `/ORDER`
matches. A build from another path gave an exe 37,888 bytes larger. Byte identity needs the same checkout path, with
`MS2_MSVC_ROOT` and `MS2_PLAIN_ENGINE` spelled as in the reference build, and the exe's own `.res` (the stand-in
changes `.rsrc`). For this project's reference builds that is
the checkout `z:/home/riyu/Documents/MS2_decomp/work/up1/wt` (as the exe's `__FILE__` strings spell it), with its
`third_party` and `engine` under it.

A full `-DMS2_PLAIN_COMPILE=ON` build on Linux (the 10-31 glue: 3637 steps, about 85 minutes at `-j16`) of a
clean worktree with that build's glue
and `-DMS2_PLAIN_NAME=fullexe3` gave an exe identical to `link2`'s `fullexe3.exe` except for 4 bytes, the link
timestamps in the COFF header and the debug directory. The objs are not byte-identical files. That would need the same `/Fo`
dir, the same `${GEN}` dir and `/showIncludes`.

A second full build (the 11-03 glue, the same checkout path, no exe anywhere: the committed `stubs.obj` default, `order.txt`
unpacked from `order.tar.xz`, a supplied `.res`) gave the same symbol set and section list as the reference
`fullexe3.exe` but was 512 bytes larger (`.text$mn` +0xd0, `.xdata` -0x20). Of its 3390 objs that could be compared
(283 reference objs had been rebuilt since), 3329 were identical outside the debug and `.chks64` sections. The 61 that
differed were all engine objs (`ecrD3D11Renderer`, `NiMain` textures, `NiMesh`, `AttachNifData`, `LuaWrap`,
`ActorModel`, `egmAnimationBindings`). The reference cache had built them on 10-27, before 153 `engine-patches` files
changed; the fresh build applied the patches at that commit. So the size difference comes from a stale reference cache,
not from reading the exe. Relinking the reference objs with the committed `stubs.obj` and the unpacked order list gave
the reference exe except for the 4 timestamp bytes.

On Windows with Visual Studio (tested on Windows 10 with VS 2022 Community from the VS GUI's Open Folder, step 5
below: on 11-03 it built all 3731 steps of that day's later glue with every `MS2_CL_<tool>` on the 14.16 fallback, and the
exe logged in on a local server and entered a field):

- Install VS 2022 (Community is enough) with the "Desktop development with C++" workload and these individual
  components: MSVC v141 VS 2017 C++ x64/x86 build tools (14.16), C++ ATL for v141, C++ MFC for v141, C++ CMake tools
  for Windows (CMake and Ninja come with VS; no Python or Wine is needed to build), and the Windows 10 SDK (10.0.19041).
- Use a developer prompt for the 14.16 toolset: `"C:\Program Files\Microsoft Visual
  Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" -vcvars_ver=14.16`. A plain VS 2022 prompt gives cl 14.4x,
  which is not the build's compiler. Check with `cl` (it prints 19.16).
- `cmake/fullexe-plain/CMakePresets.json` has a `windows-noexe` preset (Ninja, `MS2_PLAIN_COMPILE=ON`, build dir
  `<checkout>\build\fullexe-plain`, the stand-in resources). The checkout, SDK and engine paths
  default to the repo root, `<checkout>\third_party` and `<checkout>\engine`.
- `MS2_CL_1414`, `MS2_CL_1415`, `MS2_CL_vc9`, `MS2_CL_vc9c`, `MS2_CL_vc9v` and `MS2_CL_vc11` may name those compilers'
  `cl.exe` (or a `.cmd` wrapper that sets that compiler's own `INCLUDE`/`LIB`). Each one left unset gives a CMake
  warning and the 14.16 `cl` builds those rows instead; the exe then works but is not byte-identical. CMake adds the
  `/I<checkout>\src` (and for `vc9v` the `/FI tools\msvc9v\compat.h`) that the Linux wrappers add, and builds the
  fallback `vc*` rows `/MD /Zp8`. `/MD`: their flag sets name no CRT, and cl 19.16's default `/MT` would pull
  `libcpmt.lib` into the link (LNK2038/LNK2005). `/Zp8` (the cl rows' layout option): at the default `/Zp16` cl 19.16
  rounds a derived class past a base with an `align(16)` member where VC9 fills the base's tail padding, so
  `sfr_video_02` would stop at its `ShapeDataFloatMP size` static_assert (0xa0, the exe's 0x90). With both, every
  `vc*` row compiles under the fallback with its static_asserts intact, and an all-fallback build links and runs.
- Command lines reach 9.6 KB, over cmd.exe's limit, so on Windows each flag set goes into a response file
  (`<build>/out/cl/<id>.rsp`).
- `tree.tsv` symlinks need Developer Mode or an elevated prompt; without it CMake copies the target instead.
- Flag-set arguments containing `$(` (unexpanded `$(GB_SDK)` include dirs that name no dir) are dropped, since Ninja and
  MSBuild would both read them as variables.
- Code-page warnings (C4819, C4828: the sources hold cp949 text) are harmless.

Steps for a Windows-only user with no exe (run on a Windows 10 VM, see above):

1. Clone the repo and fetch the Scaleform submodule (`src/ms2/scaleform` is a submodule; a few hundred
   `compile.tsv` rows compile from it): `git clone <url> <checkout>`, then `git submodule update --init` in
   `<checkout>`. Build the tip as cloned: its sources are the ones the committed glue was made from.
   `data/fullexe/plain/commit` only records the maintainer's build id. For a byte-identical exe, clone to the
   reference checkout path (see "What matches"; a `subst Z:` drive works).
2. Put the SDK tree at `<checkout>\third_party` (or a junction to it), with the stock Gamebryo Source unpatched at
   `third_party\gamebryo\APPDIR\Source`, and the engine tree at `<checkout>\engine`. Order (see "Engine trees"): first
   `gamebryo-v2525` from the pristine Source with `engine-patches-v2525` (configure does it when Python is on PATH), then
   `engine-patches` into a separate copy of `APPDIR\Source` at `engine\gamebryo`, with `python tools\apply_engine_patches.py`.
3. `src\ms2\cef\include` is a git symlink. Without symlink support git checks it out as a small text file, and the CEF
   units then fail to find their headers. Replace it with a junction: in `src\ms2\cef`, `del include` then
   `mklink /J include ..\..\..\third_party\src\cef_binary_3.3396.1786.gd3e36d0_windows64_minimal\include`.
4. Resources: nothing to do, the build compiles the stand-in (see Resources). Only for the exe's own resources, pass
   `-DMS2_RESOURCES_RES=<path to .res>` with a `.res` built from an exe (`tools/extract_resources.py --compile`).
5. In the 14.16 developer prompt (above):
   ```
   cmake -S <checkout>\cmake\fullexe-plain -B <build> -G Ninja -DMS2_PLAIN_COMPILE=ON
         -DMS2_ROOT=<checkout> -DMS2_PLAIN_CHECKOUT=<checkout> -DMS2_MSVC_ROOT=<checkout>/third_party
         -DMS2_PLAIN_ENGINE=<checkout>/engine
   cmake --build <build>
   ```
   (or, with the default layout, `cmake --preset windows-noexe` then `cmake --build --preset windows-noexe` from
   `cmake\fullexe-plain`). Use forward slashes in the `-D` paths. `MS2_PLAIN_STUBS_OBJ` and the order list default
   to the committed `stubs.obj` and `order.tar.xz`. The exe is `<build>\out\fullexe-plain.exe`.

   Or in the VS GUI, with no developer prompt: File > Open > Folder, pick `<checkout>\cmake\fullexe-plain`. VS
   selects the `windows-noexe` preset and configures with the 14.16 `cl` and its own Ninja (the default layout from
   steps 2 to 4 is needed, since the preset passes no `-D` paths). Then Build > Build All. The exe is
   `<checkout>\build\fullexe-plain\out\fullexe-plain.exe`.

   On a Windows 10 install without recent updates, VS 2022 may fail to start ("Could not start Visual Studio",
   `ControllerConnectionException`). Its .NET runtime stops with "Your Windows doesn't fully support CET". Install
   the Windows updates, or turn off the shadow-stack mitigation for the ServiceHub exes in an elevated PowerShell:
   `gci "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\ServiceHub" -r -fi *.exe |
   % { Set-ProcessMitigation -Name $_.Name -Disable UserShadowStack }`.

### Without the original exe

`cmake/fullexe` cannot run without the exe: `rtti_scan`, `progress` (byte matching), `pinreport`, `implibs --lib`,
`datapair`, `shim`, `rsrc` and `crtinit` all open it, and `alias` then finds no pairs. The plain build with
`-DMS2_PLAIN_COMPILE=ON` reads no exe: the obj commands come from `compile.tsv`/`flags.tsv`/`tree.tsv`, the data stub
from `stubs.obj`, the `/ORDER` list from `order.tar.xz` and the resources from the stand-in (or `MS2_RESOURCES_RES`).
The glue is committed in `data/fullexe/plain` (`tools/fullexe/glue-refresh.sh` refreshes them). A user without the exe still
needs:

- the published tip as cloned, with its submodule (step 1 above); the glue names that tip's objs, so sources from any
  other commit fail to compile or link;
- every SDK root above, the 14.16 toolset, and the old compilers for `vc9`, `vc9c`, `vc9v`, `vc11`, `1414`, `1415` (or the
  14.16 fallback, not byte-identical);
- `third_party/` at the checkout's top level when the SDKs live elsewhere: some sources reach SDK headers through
  relative symlinks (`src/ms2/cef/include` -> `../../../third_party/src/cef_binary_...`), so a link or junction to
  `MS2_MSVC_ROOT` is needed;
- nothing for the resources: the stand-in builds in (only the exe's own `.res` gives the original resources and a
  byte-identical `.rsrc`);
- for a byte-identical exe, the reference build's checkout path (see "What matches" above). Any other path builds a
  working exe that differs in its `__FILE__` strings and layout.

Still exe-bound: the default `cmake/fullexe` build (the stages above), and every glue refresh, which runs from an
exe-reading build's objs and map. A user without the exe can only build the published tip, whose glue names its own
sources.
