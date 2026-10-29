# Full-exe build: drives tools/fullexe/*.py in order, in place (no reimplementation). Each stage is a custom command with a
# stamp file; stages that depend on sources re-run only when their inputs changed (the compile stage keeps its own per-TU
# cache, so only changed units recompile). The link reads the objs where the cache keeps them (link<TAG>.rsp), no copy.
cmake_minimum_required(VERSION 3.20)
project(ms2_fullexe NONE)

set(MS2_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." CACHE PATH "repository root")
get_filename_component(MS2_ROOT "${MS2_ROOT}" ABSOLUTE)
set(MS2_PYTHON "${MS2_ROOT}/.venv/bin/python" CACHE FILEPATH "python3 with the tools/ requirements")
set(MS2_JOBS 8 CACHE STRING "parallel compiles in the compile stage")
# the original exe (tools/check_exe.py verifies it); empty = $ENV{MS2_EXE}, else the in-tree path CONTRIBUTING.md names
set(MS2_EXE "" CACHE FILEPATH "the original KMS2_DEV x64 MapleStory2.exe")
if(NOT MS2_EXE)
  if(DEFINED ENV{MS2_EXE})
    set(MS2_EXE "$ENV{MS2_EXE}")
  else()
    set(MS2_EXE "${MS2_ROOT}/Game Versions/KMS2_DEV/x64/MapleStory2.exe")
  endif()
endif()
set(MS2_MSVC_ROOT "" CACHE PATH "third_party/-layout dir: msvc/ (MSVC 14.16 + Windows SDK, msvc-wine), dxsdk/, physx284/, src/<library>; empty = third_party")
foreach(v GAMEBRYO DXSDK PHYSX CEF PATHENGINE)
  set(MS2_${v}_ROOT "" CACHE PATH "BYO ${v} root (see BUILDING.md); empty = the in-tree default")
endforeach()

# the tools read the MSVC tree, DXSDK, PhysX and the library sources from one third_party/-layout dir (MS2_THIRD_PARTY,
# tools/ms2paths.py): msvc/, dxsdk/DXSDK, physx284/..., src/<library>
if(MS2_MSVC_ROOT)
  set(_tp "${MS2_MSVC_ROOT}")
else()
  set(_tp "${MS2_ROOT}/third_party")
endif()
# in-tree defaults, so a checkout that already has the SDKs in place needs no variables
if(NOT MS2_GAMEBRYO_ROOT)
  set(MS2_GAMEBRYO_ROOT "${MS2_ROOT}/engine")
endif()
set(_tp_DXSDK "${_tp}/dxsdk/DXSDK")
set(_tp_PHYSX "${_tp}/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win")
file(GLOB _tp_CEF "${_tp}/src/cef_binary_*")
list(APPEND _tp_CEF "${_tp}/src/cef_binary_3.3396.1786.gd3e36d0_windows64_minimal")
list(GET _tp_CEF 0 _tp_CEF)
# a root set elsewhere would pass the hash check below but not be the one the tools compile and link with
foreach(v DXSDK PHYSX CEF)
  if(NOT MS2_${v}_ROOT)
    set(MS2_${v}_ROOT "${_tp_${v}}")
  endif()
  get_filename_component(_a "${MS2_${v}_ROOT}" REALPATH)
  get_filename_component(_b "${_tp_${v}}" REALPATH)
  if(NOT _a STREQUAL _b)
    message(FATAL_ERROR "MS2_${v}_ROOT=${MS2_${v}_ROOT}: the tools read it from ${_tp_${v}} (the third_party/ layout of "
                        "MS2_MSVC_ROOT); put or link it there (see BUILDING.md)")
  endif()
endforeach()
if(NOT MS2_PATHENGINE_ROOT)
  set(MS2_PATHENGINE_ROOT "${MS2_ROOT}/third_party/src/pathengine-sigmaco")
endif()

set(MANIFEST "${MS2_ROOT}/cmake/sdk-manifest.txt")
include("${CMAKE_CURRENT_LIST_DIR}/check-sdk.cmake")

set(OUT "${CMAKE_BINARY_DIR}/out")
set(MS2_CACHE_TAG fullexe CACHE STRING "progress cache tag: objs and gb overlay live in build/progress-<tag> (a private tag keeps a build off other agents' caches)")
set(CACHE_TAG "${MS2_CACHE_TAG}")
set(MS2_ENGINE_CACHE_TAG "" CACHE STRING "read the engine objs from build/progress-<tag>/gb instead of the build's own cache (bisecting; pair with MS2_ENGINE_REFRESH=0, the cache is not written)")
set(MS2_ENGINE_REFRESH 1 CACHE STRING "FULLEXE_ENGINE_REFRESH: 1 rebuild stale engine objs, check list them, 0/empty take the cache as is")
set(MS2_ALIAS_CURRENT 1 CACHE STRING "FULLEXE_ALIAS_CURRENT: 1 drop alias.py cache entries that do not describe the current obj, 0 keep them all")
set(MS2_STRICT_COMPILE 1 CACHE STRING "FULLEXE_STRICT_COMPILE: 1 fail when a unit the compile stage ran has no obj and tools/fullexe/compile-allow.tsv does not list it, empty = report only")
set(MS2_STRICT_PINS 1 CACHE STRING "FULLEXE_STRICT_PINS: 1 fail on an ignored pin / suspect look-alike order missing from tools/fullexe/pins-allow.tsv, empty = report only")
set(_er "${MS2_ENGINE_REFRESH}")
if(_er STREQUAL "0")
  set(_er "")
endif()
set(_ac "${MS2_ALIAS_CURRENT}")
if(_ac STREQUAL "0" OR _ac STREQUAL "OFF")
  set(_ac "")
endif()
if(MS2_ENGINE_CACHE_TAG)
  set(GB_OVERLAY "${MS2_ROOT}/build/progress-${MS2_ENGINE_CACHE_TAG}/gb")
else()
  set(GB_OVERLAY "${MS2_ROOT}/build/progress-${CACHE_TAG}/gb")
endif()
set(WINSDK_VERSION "10.0.19041.0" CACHE STRING "Windows SDK version of the MSVC tree")
set(SDK_UM "${_tp}/msvc/Windows Kits/10/Lib/${WINSDK_VERSION}/um/x64")
set(SDK_LIB_ARGS "")
foreach(l kernel32 user32 ws2_32 shlwapi oleaut32 shell32 dsound)
  list(APPEND SDK_LIB_ARGS --sdk-lib "${SDK_UM}/${l}.lib")
endforeach()

# environment every tools/fullexe script reads (tools/ms2paths.py, tools/fullexe/common.py)
set(ENVV FULLEXE_DIR=${OUT} FULLEXE_TREE=${MS2_ROOT} FULLEXE_FRESH=all FULLEXE_GB_OVERLAY=${GB_OVERLAY}
    FULLEXE_OBJ_CACHES=${MS2_ROOT}/build/progress-${CACHE_TAG}
    FULLEXE_HERMETIC=1 FULLEXE_ENGINE_REFRESH=${_er} FULLEXE_ALIAS_CURRENT=${_ac}
    MS2_EXE=${MS2_EXE} MS2_CLASSES_DIR=${OUT}/classes MS2_THIRD_PARTY=${_tp} MS2_ENGINE_DIR=${MS2_GAMEBRYO_ROOT} MS2_AGENT=${CACHE_TAG})
file(MAKE_DIRECTORY "${OUT}")

set(_prev "")
# stage(name TAG tag-or-empty COMMAND ...): a target that runs after the previous stage
function(stage name tag)
  cmake_parse_arguments(S "" "" "COMMAND" ${ARGN})
  add_custom_target(${name} COMMAND ${CMAKE_COMMAND} -E env ${ENVV} FULLEXE_TAG=${tag} ${S_COMMAND}
                    WORKING_DIRECTORY "${MS2_ROOT}" USES_TERMINAL VERBATIM)
  if(_prev)
    add_dependencies(${name} ${_prev})
  endif()
  set(_prev ${name} PARENT_SCOPE)
endfunction()

set(PY ${MS2_PYTHON} -P)
set(FE "${MS2_ROOT}/tools/fullexe")
# 0. RTTI tables (rtti_classes.tsv, rtti_vftables.tsv) the vftable pairing reads: derived from the exe, so generated here
#    instead of living in the untracked work/classes (byte-identical to the maintainer's)
stage(rtti "" COMMAND ${PY} "${MS2_ROOT}/tools/rtti_scan.py" "${MS2_EXE}" "${OUT}/classes")
# 1. compile: the gates' incremental per-TU cache (game, Scaleform, engine); only changed units rebuild
stage(compile "" COMMAND ${PY} "${MS2_ROOT}/tools/progress.py" --agent ${CACHE_TAG} -j ${MS2_JOBS})
# a unit that failed to compile drops out of the link and its functions become trap stubs: summary in out/compilecheck.txt.
# Strict: a unit not in tools/fullexe/compile-allow.tsv fails the build
stage(compilecheck "" COMMAND ${CMAKE_COMMAND} -E env FULLEXE_STRICT_COMPILE=${MS2_STRICT_COMPILE} ${PY} "${FE}/compilecheck.py")
# ignored pins / look-alike COMDATs the gates only note: summary in out/pinreport.txt. Strict: a row that is not in the reviewed
# baseline tools/fullexe/pins-allow.tsv fails the build (python3 tools/fullexe/pinreport.py --write-allow regenerates it)
stage(pinreport "" COMMAND ${CMAKE_COMMAND} -E env FULLEXE_STRICT_PINS=${MS2_STRICT_PINS} ${PY} "${FE}/pinreport.py")
# 2. plan the obj order, import libs (from the exe's IAT), asm objs
stage(plan "" COMMAND ${PY} "${FE}/plan.py")
stage(implibs "" COMMAND ${PY} "${FE}/implibs.py" --lib)
stage(asm "" COMMAND ${PY} "${FE}/asm.py")
# 3. open link (/force:unresolved) -> the unresolved set and every obj's defined externals
stage(link0 "" COMMAND ${PY} "${FE}/link.py")
stage(defsyms "" COMMAND ${PY} "${FE}/defsyms.py")
stage(analyze0 "" COMMAND ${PY} "${FE}/analyze.py")
# 4. glue: alias pairs (alias.rsp, abithunks.tsv) and /ORDER list
stage(alias "" COMMAND ${PY} "${FE}/alias.py")
# data aliases alias.py cannot pair (engine/CryptoPP/Cef vftables, singleton statics): link.py --alias appends datapair-alias.rsp
stage(datapair "" COMMAND ${PY} "${FE}/datapair.py")
stage(order "" COMMAND ${PY} "${FE}/order.py")
# 5. alias + order link (still open), then the shim: trap stubs, ABI adapters, resources
stage(link1 2 COMMAND ${PY} "${FE}/link.py" --alias --order)
stage(analyze1 2 COMMAND ${PY} "${FE}/analyze.py")
stage(shim 2 COMMAND ${PY} "${FE}/shim.py" ${SDK_LIB_ARGS})
stage(rsrc 2 COMMAND ${PY} "${FE}/rsrc.py")
# 6. static-initializer order
stage(crtinit 2 COMMAND ${PY} "${FE}/crtinit.py")
stage(initorder 2 COMMAND ${PY} "${FE}/initorder.py")
# 7. closed link: no /force:unresolved; objs taken in place through the response file
stage(link2 3 COMMAND ${PY} "${FE}/link.py" --alias --order --shim --before "${OUT}/initorder2.tsv")

add_custom_target(fullexe ALL DEPENDS link2)
