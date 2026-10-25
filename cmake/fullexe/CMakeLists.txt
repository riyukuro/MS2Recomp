# Full-exe build: drives tools/fullexe/*.py in order, in place (no reimplementation). Each stage is a custom command with a
# stamp file; stages that depend on sources re-run only when their inputs changed (the compile stage keeps its own per-TU
# cache, so only changed units recompile). The link reads the objs where the cache keeps them (link<TAG>.rsp), no copy.
cmake_minimum_required(VERSION 3.20)
project(ms2_fullexe NONE)

set(MS2_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." CACHE PATH "repository root")
get_filename_component(MS2_ROOT "${MS2_ROOT}" ABSOLUTE)
set(MS2_PYTHON "${MS2_ROOT}/.venv/bin/python" CACHE FILEPATH "python3 with the tools/ requirements")
set(MS2_JOBS 8 CACHE STRING "parallel compiles in the compile stage")
set(MS2_MSVC_ROOT "" CACHE PATH "MSVC 14.16 + Windows SDK tree (msvc-wine layout); empty = third_party/msvc")
foreach(v GAMEBRYO DXSDK PHYSX CEF PATHENGINE SCALEFORM)
  set(MS2_${v}_ROOT "" CACHE PATH "BYO ${v} root (see BUILDING.md); empty = the in-tree default")
endforeach()

# in-tree defaults, so a checkout that already has the SDKs in place needs no variables
if(NOT MS2_GAMEBRYO_ROOT)
  set(MS2_GAMEBRYO_ROOT "${MS2_ROOT}/engine")
endif()
if(NOT MS2_DXSDK_ROOT)
  set(MS2_DXSDK_ROOT "${MS2_ROOT}/third_party/dxsdk/DXSDK")
endif()
if(NOT MS2_PHYSX_ROOT)
  set(MS2_PHYSX_ROOT "${MS2_ROOT}/third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win")
endif()
if(NOT MS2_CEF_ROOT)
  file(GLOB _cef "${MS2_ROOT}/third_party/src/cef_binary_*")
  list(GET _cef 0 MS2_CEF_ROOT)
endif()
if(NOT MS2_PATHENGINE_ROOT)
  set(MS2_PATHENGINE_ROOT "${MS2_ROOT}/third_party/src/pathengine-sigmaco")
endif()

set(MANIFEST "${MS2_ROOT}/cmake/sdk-manifest.txt")
include("${CMAKE_CURRENT_LIST_DIR}/check-sdk.cmake")

set(OUT "${CMAKE_BINARY_DIR}/out")
set(CACHE_TAG fullexe)
set(GB_OVERLAY "${MS2_ROOT}/build/progress-${CACHE_TAG}/gb")
set(WINSDK_VERSION "10.0.19041.0" CACHE STRING "Windows SDK version of the MSVC tree")
if(MS2_MSVC_ROOT)
  set(_tp "${MS2_MSVC_ROOT}")
else()
  set(_tp "${MS2_ROOT}/third_party")
endif()
set(SDK_UM "${_tp}/msvc/Windows Kits/10/Lib/${WINSDK_VERSION}/um/x64")
set(SDK_LIB_ARGS "")
foreach(l kernel32 user32 ws2_32 shlwapi oleaut32 shell32 dsound)
  list(APPEND SDK_LIB_ARGS --sdk-lib "${SDK_UM}/${l}.lib")
endforeach()

# environment every tools/fullexe script reads (tools/ms2paths.py, tools/fullexe/common.py)
set(ENVV FULLEXE_DIR=${OUT} FULLEXE_TREE=${MS2_ROOT} FULLEXE_FRESH=all FULLEXE_GB_OVERLAY=${GB_OVERLAY}
    FULLEXE_OBJ_CACHES=${MS2_ROOT}/build/progress-${CACHE_TAG}
    MS2_THIRD_PARTY=${_tp} MS2_ENGINE_DIR=${MS2_GAMEBRYO_ROOT} MS2_AGENT=${CACHE_TAG})
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
# 1. compile: the gates' incremental per-TU cache (game, Scaleform, engine); only changed units rebuild
stage(compile "" COMMAND ${PY} "${MS2_ROOT}/tools/progress.py" --agent ${CACHE_TAG} -j ${MS2_JOBS})
# 2. plan the obj order, import libs (from the exe's IAT), asm objs
stage(plan "" COMMAND ${PY} "${FE}/plan.py")
stage(implibs "" COMMAND ${PY} "${FE}/implibs.py")
stage(asm "" COMMAND ${PY} "${FE}/asm.py")
# 3. open link (/force:unresolved) -> the unresolved set and every obj's defined externals
stage(link0 "" COMMAND ${PY} "${FE}/link.py")
stage(defsyms "" COMMAND ${PY} "${FE}/defsyms.py")
stage(analyze0 "" COMMAND ${PY} "${FE}/analyze.py")
# 4. glue: alias pairs (alias.rsp, abithunks.tsv) and /ORDER list
stage(alias "" COMMAND ${PY} "${FE}/alias.py")
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
