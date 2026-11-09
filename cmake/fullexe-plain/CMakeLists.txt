# Plain full-exe link: no Python at build time. One closed link of the compiled objs with committed glue files, the same
# command line link2 (cmake/fullexe, tools/fullexe/link.py --alias --order --shim --before) builds:
#   MS2_PLAIN_GLUE/objs.txt    the objs in link order (plan order + the initorder --before moves), relative to MS2_PLAIN_OBJ_ROOT
#   MS2_PLAIN_GLUE/alias.rsp   the /alternatename lines (alias.rsp + datapair-alias.rsp as link2 took them)
#   MS2_PLAIN_GLUE/order.txt   the /ORDER list (optional: MS2_PLAIN_ORDER defaults to off without it); without order.txt,
#                              MS2_PLAIN_GLUE/order.tar.xz (plainglue.py pack, its committed form) unpacks into the build dir
#   MS2_PLAIN_GLUE/stubs.tsv   the data stubs the shim took (names and VAs), input of plainglue.py stubs
# MS2_PLAIN_GLUE defaults to data/fullexe/plain, the committed glue of the newest passing fullexe-latest build.
#   data/fullexe/imports.tsv   the import names: one .def per DLL here at configure time, lib /def at build time
# tools/fullexe/plainglue.py write <dir> regenerates the glue from a finished cmake/fullexe build (names, paths and order
# only); plainglue.py stubs <exe> <dir>/stubs.tsv <obj> extracts the one data stub (g_physXItem) once, like
# tools/extract_resources.py does the resources. g_physXItem lies in the exe's .bss, so the obj is zero fill and is
# committed as MS2_PLAIN_GLUE/stubs.obj, the default of MS2_PLAIN_STUBS_OBJ. Built here: the import libs, CryptoPP's MASM objs, hookglue.lib
# and shim_runtime.obj.
# The objs: by default MS2_PLAIN_OBJ_ROOT, the obj cache a cmake/fullexe build (build/progress-<tag>) or the gates left.
# -DMS2_PLAIN_COMPILE=ON compiles them here instead, one cl command per obj from MS2_PLAIN_GLUE/compile.tsv, flags.tsv
# and tree.tsv (plainglue.py compile; MS2_PLAIN_CHECKOUT, MS2_PLAIN_ENGINE, MS2_MSVC_ROOT and MS2_PLAIN_GEN fill in
# their path tokens). Code, data, relocations and symbols come out the same as the cache's; only the /Z7 debug info
# differs (it records the obj path and command line), and the link drops it.
#   cmake -S cmake/fullexe-plain -B build/fullexe-plain -G Ninja [-DMS2_PLAIN_GLUE=<dir>] -DMS2_PLAIN_OBJ_ROOT=<cache>
#         [-DMS2_PLAIN_STUBS_OBJ=<obj>] [-DMS2_RESOURCES_RES=<res>]
# Without MS2_RESOURCES_RES, rc compiles standin/standin.rc (our own icon, manifest and the dialogs the client loads, no
# original resource) to <build>/standin.res and the link takes that: the exe runs, but its .rsrc is not the original's.
#   cmake --build build/fullexe-plain          -> build/fullexe-plain/out/<MS2_PLAIN_NAME>.exe (+ .map), copied to MapleStory2.exe
cmake_minimum_required(VERSION 3.20)
project(ms2_fullexe_plain NONE)

set(MS2_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." CACHE PATH "repository root")
get_filename_component(MS2_ROOT "${MS2_ROOT}" ABSOLUTE)
set(MS2_PLAIN_OBJ_ROOT "" CACHE PATH "obj cache objs.txt is relative to (build/progress-<tag>)")
set(MS2_PLAIN_STUBS_OBJ "" CACHE FILEPATH "data-stub obj (tools/fullexe/plainglue.py stubs); empty = MS2_PLAIN_GLUE/stubs.obj")
set(MS2_RESOURCES_RES "" CACHE FILEPATH "the .res (tools/extract_resources.py --compile); empty = standin/standin.rc's")
set(MS2_PLAIN_IMPORTS "${MS2_ROOT}/data/fullexe/imports.tsv" CACHE FILEPATH "import names (dll, symbol)")
set(MS2_PLAIN_GLUE "${MS2_ROOT}/data/fullexe/plain" CACHE PATH "dir with objs.txt, alias.rsp, stubs.tsv [, stubs.obj, order.txt or order.tar.xz] (tools/fullexe/plainglue.py write)")
# MS2_PLAIN_DERIVE: the glue of this checkout, made at configure by tools/fullexe/plainglue.py derive from the repository
# alone (no exe, no exe-reading build): objs.txt from the tracked game sources (MS2-UNIT, their status.tsv VAs) plus
# MS2_PLAIN_GLUE/link.tsv's engine, library and closure objs, ordered and moved by MS2_PLAIN_GLUE/before.tsv; compile.tsv,
# flags.tsv, tree.tsv from tools/progress.py and tools/gbtree.py; order.txt from the symbol tables and data/map;
# stubs.obj from stubs.tsv. AUTO: when MS2_PLAIN_COMPILE is on and the glue has link.tsv (falls back to the committed
# glue, with a warning, when the derive step fails). Needs the venv's Python (MS2_PLAIN_PYTHON). cmake re-runs it when
# the tables change or a src/ms2 .cpp is added, removed or renamed.
set(MS2_PLAIN_DERIVE AUTO CACHE STRING "make the glue from this checkout at configure (plainglue.py derive): AUTO, ON, OFF")
set_property(CACHE MS2_PLAIN_DERIVE PROPERTY STRINGS AUTO ON OFF)
option(MS2_PLAIN_COMPILE "compile the objs here from MS2_PLAIN_GLUE/compile.tsv, flags.tsv, tree.tsv (plainglue.py compile) instead of reading MS2_PLAIN_OBJ_ROOT" OFF)
set(MS2_PLAIN_CHECKOUT "${MS2_ROOT}" CACHE PATH "MS2_PLAIN_COMPILE: the checkout whose sources compile.tsv names (\${ROOT})")
set(MS2_PLAIN_ENGINE "${MS2_ROOT}/engine" CACHE PATH "MS2_PLAIN_COMPILE: the dir holding gamebryo/ and fmt-ms2/ (\${ENGINE}, MS2_GAMEBRYO_ROOT)")
set(MS2_MSVC_ROOT "" CACHE PATH "third_party/-layout dir: msvc/ (MSVC 14.16 + Windows SDK, msvc-wine), dxsdk/, src/cryptopp562; empty = third_party")
if(CMAKE_HOST_WIN32)
  set(_venv "${MS2_ROOT}/.venv/Scripts/python.exe")
else()
  set(_venv "${MS2_ROOT}/.venv/bin/python")
endif()
if(NOT EXISTS "${_venv}")
  find_package(Python3 COMPONENTS Interpreter QUIET)
  set(_venv "${Python3_EXECUTABLE}")
endif()
set(MS2_PLAIN_PYTHON "${_venv}" CACHE FILEPATH "MS2_PLAIN_DERIVE: Python with requirements.txt (default <root>/.venv)")
set(_derive OFF)
if(MS2_PLAIN_DERIVE STREQUAL "ON" OR (MS2_PLAIN_DERIVE STREQUAL "AUTO" AND MS2_PLAIN_COMPILE AND EXISTS "${MS2_PLAIN_GLUE}/link.tsv"))
  set(_derive ON)
endif()
set(MS2_PLAIN_DERIVED OFF)
if(_derive)
  set(_dg "${CMAKE_BINARY_DIR}/glue-derived")
  set(_denv "")
  if(MS2_MSVC_ROOT)
    list(APPEND _denv "MS2_THIRD_PARTY=${MS2_MSVC_ROOT}")
  endif()
  list(APPEND _denv "MS2_ENGINE_DIR=${MS2_PLAIN_ENGINE}")
  execute_process(COMMAND ${CMAKE_COMMAND} -E env ${_denv} "${MS2_PLAIN_PYTHON}" -P
                          "${MS2_PLAIN_CHECKOUT}/tools/fullexe/plainglue.py" derive "${_dg}" --base "${MS2_PLAIN_GLUE}"
                  WORKING_DIRECTORY "${MS2_PLAIN_CHECKOUT}" RESULT_VARIABLE _rc OUTPUT_VARIABLE _out ERROR_VARIABLE _err)
  if(_rc EQUAL 0)
    message(STATUS "plainglue.py derive: ${_out}")
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
                 "${MS2_PLAIN_GLUE}/link.tsv" "${MS2_PLAIN_GLUE}/before.tsv" "${MS2_PLAIN_GLUE}/alias.rsp" "${MS2_PLAIN_GLUE}/stubs.tsv"
                 "${MS2_PLAIN_CHECKOUT}/progress/symbols.tsv" "${MS2_PLAIN_CHECKOUT}/progress/symbols-manual.tsv"
                 "${MS2_PLAIN_CHECKOUT}/data/map/functions.tsv" "${MS2_PLAIN_CHECKOUT}/data/engine/units-gb.json")
    if(EXISTS "${MS2_PLAIN_CHECKOUT}/progress/status.tsv")
      set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${MS2_PLAIN_CHECKOUT}/progress/status.tsv")
    endif()
    # a game source added, removed or renamed re-runs configure (and so derive) at the next build; an edit to an
    # existing source's MS2-UNIT/MS2-RANGE line does not (re-configure by hand)
    file(GLOB_RECURSE _ms2_srcs CONFIGURE_DEPENDS LIST_DIRECTORIES false "${MS2_PLAIN_CHECKOUT}/src/ms2/*.cpp")
    set(MS2_PLAIN_GLUE "${_dg}")      # a normal variable: shadows the cache entry from here on
    set(MS2_PLAIN_DERIVED ON)
  elseif(MS2_PLAIN_DERIVE STREQUAL "ON")
    message(FATAL_ERROR "plainglue.py derive failed (${_rc}):\n${_out}${_err}")
  else()
    message(WARNING "plainglue.py derive failed (${_rc}), linking the committed glue ${MS2_PLAIN_GLUE}:\n${_out}${_err}")
  endif()
endif()
if(EXISTS "${MS2_PLAIN_GLUE}/order.txt")
  set(_orderfile "${MS2_PLAIN_GLUE}/order.txt")
elseif(EXISTS "${MS2_PLAIN_GLUE}/order.tar.xz")
  # order.txt is 32 MB: committed as order.tar.xz, unpacked here at configure
  set(_orderfile "${CMAKE_BINARY_DIR}/glue/order.txt")
  if(NOT EXISTS "${_orderfile}" OR "${MS2_PLAIN_GLUE}/order.tar.xz" IS_NEWER_THAN "${_orderfile}")
    file(ARCHIVE_EXTRACT INPUT "${MS2_PLAIN_GLUE}/order.tar.xz" DESTINATION "${CMAKE_BINARY_DIR}/glue" PATTERNS order.txt)
    file(TOUCH "${_orderfile}")
  endif()
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${MS2_PLAIN_GLUE}/order.tar.xz")
else()
  set(_orderfile "")
endif()
if(_orderfile)
  set(_order ON)
else()
  set(_order OFF)     # plainglue.py write makes order.txt from a cmake/fullexe build
endif()
option(MS2_PLAIN_ORDER "link with MS2_PLAIN_GLUE/order.txt, the exe's function layout (off = the linker's own order)" ${_order})
option(MS2_PLAIN_LEGACY_STDIO "link legacy_stdio_definitions.lib (link.py adds it when MS2-TOOLSET objs are linked)" ON)
set(MS2_PLAIN_NAME fullexe-plain CACHE STRING "output name: <name>.exe/.map (the exe's export directory records it; fullexe3 = link2's)")
set(MS2_PLAIN_LAUNCHER "" CACHE STRING "command the link runs under (e.g. a lock wrapper); empty = none")
set(WINSDK_VERSION "10.0.19041.0" CACHE STRING "Windows SDK version of the MSVC tree")
set(MSVC_TOOLSET "14.16.27023" CACHE STRING "MSVC toolset dir of the MSVC tree")
set(MS2_PLAIN_GEN "${CMAKE_BINARY_DIR}/gen" CACHE PATH "MS2_PLAIN_COMPILE: where tree.tsv's generated include trees go (\${GEN}; the exporting build's is <checkout>/build)")
if(MS2_PLAIN_COMPILE)
  set(MS2_PLAIN_OBJ_ROOT "${CMAKE_BINARY_DIR}/cache")
  file(MAKE_DIRECTORY "${MS2_PLAIN_OBJ_ROOT}")
endif()
if(NOT MS2_PLAIN_STUBS_OBJ AND EXISTS "${MS2_PLAIN_GLUE}/stubs.obj")
  set(MS2_PLAIN_STUBS_OBJ "${MS2_PLAIN_GLUE}/stubs.obj")   # zero fill only: committed, no exe bytes
endif()
foreach(v MS2_PLAIN_OBJ_ROOT MS2_PLAIN_STUBS_OBJ MS2_RESOURCES_RES)
  if("${v}" STREQUAL "MS2_RESOURCES_RES" AND NOT MS2_RESOURCES_RES)
    continue()      # the stand-in below
  endif()
  if(NOT ${v} OR NOT EXISTS "${${v}}")
    message(FATAL_ERROR "${v}=${${v}}: missing (see the header of ${CMAKE_CURRENT_LIST_FILE})")
  endif()
endforeach()
foreach(f objs.txt alias.rsp)
  if(NOT EXISTS "${MS2_PLAIN_GLUE}/${f}")
    message(FATAL_ERROR "MS2_PLAIN_GLUE=${MS2_PLAIN_GLUE}: no ${f}")
  endif()
endforeach()
if(MS2_PLAIN_ORDER AND NOT _orderfile)
  message(FATAL_ERROR "MS2_PLAIN_ORDER=ON: no ${MS2_PLAIN_GLUE}/order.txt or order.tar.xz (tools/fullexe/plainglue.py write, pack)")
endif()
if(MS2_MSVC_ROOT)
  set(_tp "${MS2_MSVC_ROOT}")
else()
  set(_tp "${MS2_ROOT}/third_party")
endif()
if(MS2_PLAIN_COMPILE)   # engine/gamebryo-v2525 from the pristine Source + engine-patches-v2525/ (made here when missing)
  find_package(Python3 COMPONENTS Interpreter QUIET)
  set(V2525_DIR "${MS2_PLAIN_ENGINE}/gamebryo-v2525")
  set(V2525_SDK "${_tp}/gamebryo/APPDIR/Source")
  set(V2525_PY "${Python3_EXECUTABLE}")
  include("${MS2_ROOT}/cmake/v2525.cmake")
endif()

set(OUT "${CMAKE_BINARY_DIR}/out")
file(MAKE_DIRECTORY "${OUT}/implib" "${OUT}/asm/glue" "${OUT}/shim")

# tools: msvc-wine's wrappers under wine (paths in z:\ form, the prefix tools/ms2paths.py uses), or the Developer
# Command Prompt's on Windows
if(CMAKE_HOST_WIN32)
  set(TOOL_ENV "")
  foreach(t cl link lib ml64 rc)
    find_program(MS2_${t} ${t} REQUIRED)
  endforeach()
else()
  if(DEFINED ENV{MS2_WINEPREFIX})
    set(_wp "$ENV{MS2_WINEPREFIX}")
  elseif(DEFINED ENV{MS2_MSVC_WINEPREFIX})
    set(_wp "$ENV{MS2_MSVC_WINEPREFIX}")
  else()
    set(_wp "${MS2_ROOT}/work/wineprefix-msvc")
  endif()
  set(TOOL_ENV ${CMAKE_COMMAND} -E env WINEPREFIX=${_wp} WINEDEBUG=-all)
  foreach(t cl link lib ml64 rc)
    set(MS2_${t} "${_tp}/msvc/bin/x64/${t}")
  endforeach()
endif()
function(tp out path)       # the tools' form of a host path
  get_filename_component(path "${path}" ABSOLUTE)
  if(CMAKE_HOST_WIN32)
    file(TO_NATIVE_PATH "${path}" path)
  else()
    string(REPLACE "/" "\\" path "z:${path}")
  endif()
  set(${out} "${path}" PARENT_SCOPE)
endfunction()

# resources: the given .res, or the stand-in's
if(NOT MS2_RESOURCES_RES)
  set(_sd "${CMAKE_CURRENT_LIST_DIR}/standin")
  set(MS2_RESOURCES_RES "${CMAKE_BINARY_DIR}/standin.res")
  tp(_o "${MS2_RESOURCES_RES}")
  tp(_i "${_sd}/standin.rc")
  add_custom_command(OUTPUT "${MS2_RESOURCES_RES}"
                     COMMAND ${TOOL_ENV} "${MS2_rc}" /nologo "/fo${_o}" "${_i}"
                     DEPENDS "${_sd}/standin.rc" "${_sd}/standin.ico" WORKING_DIRECTORY "${_sd}" VERBATIM)
endif()

# import libs: one .def per DLL (implibs.py's format; imports.tsv is in its order), lib /def at build time
file(STRINGS "${MS2_PLAIN_IMPORTS}" _rows REGEX "^[^#]")
set(_dll "")
set(IMPLIBS "")
macro(flush_def)
  if(_dll)
    string(REGEX REPLACE "\\.[^.]*$" "" _base "${_dll}")
    file(WRITE "${OUT}/implib/${_base}.def.new" "${_def}")
    configure_file("${OUT}/implib/${_base}.def.new" "${OUT}/implib/${_base}.def" COPYONLY)
    tp(_d "${OUT}/implib/${_base}.def")
    tp(_l "${OUT}/implib/${_base}.lib")
    add_custom_command(OUTPUT "${OUT}/implib/${_base}.lib"
                       COMMAND ${TOOL_ENV} "${MS2_lib}" /nologo /machine:x64 "/def:${_d}" "/out:${_l}"
                       DEPENDS "${OUT}/implib/${_base}.def" VERBATIM)
    list(APPEND IMPLIBS "${OUT}/implib/${_base}.lib")
  endif()
endmacro()
foreach(r IN LISTS _rows)
  string(REPLACE "\t" ";" r "${r}")
  list(GET r 0 d)
  list(GET r 1 s)
  if(NOT d STREQUAL _dll)
    flush_def()
    set(_dll "${d}")
    set(_def "LIBRARY \"${d}\"\nEXPORTS\n")
  endif()
  if(s MATCHES "^@([0-9]+)$")
    string(APPEND _def "  ord${CMAKE_MATCH_1} ${s} NONAME\n")
  elseif(s MATCHES "@@[23]")
    string(APPEND _def "  ${s} DATA\n")
  else()
    string(APPEND _def "  ${s}\n")
  endif()
endforeach()
flush_def()
list(SORT IMPLIBS)

# CryptoPP's x64 MASM objs (tools/fullexe/asm.py): x64masm.asm without Sosemanuk_OperateKeystream and the EXTERNDEF
# only it uses (the exe has no sosemanuk.cpp)
set(CRYPTOPP "${_tp}/src/cryptopp562")
set(ASM_INC "${MS2_ROOT}/tools/fullexe/asm")
file(READ "${CRYPTOPP}/x64dll.asm" _a)
file(WRITE "${OUT}/asm/x64dll.asm.new" "${_a}")
file(READ "${CRYPTOPP}/x64masm.asm" _a)
string(REGEX REPLACE "(^|\n)EXTERNDEF s_sosemanukMulTables:FAR\n" "\\1" _a "${_a}")
string(FIND "${_a}" "\nSosemanuk_OperateKeystream PROC" _p0)
string(FIND "${_a}" "\nSosemanuk_OperateKeystream ENDP" _p1)
if(_p0 LESS 0 OR _p1 LESS _p0)
  message(FATAL_ERROR "${CRYPTOPP}/x64masm.asm: no Sosemanuk_OperateKeystream PROC/ENDP")
endif()
string(SUBSTRING "${_a}" ${_p1} -1 _tail)
string(FIND "${_tail}" "\n" _e)                      # the ENDP line's own end: _tail starts at the newline before it
string(SUBSTRING "${_tail}" 1 -1 _tail)
string(FIND "${_tail}" "\n" _e)
string(SUBSTRING "${_tail}" ${_e} -1 _tail)
string(SUBSTRING "${_a}" 0 ${_p0} _a)
file(WRITE "${OUT}/asm/x64masm.asm.new" "${_a}${_tail}")
set(ASMOBJS "")
foreach(u x64dll x64masm)
  configure_file("${OUT}/asm/${u}.asm.new" "${OUT}/asm/${u}.asm" COPYONLY)
  tp(_i "${ASM_INC}")
  tp(_o "${OUT}/asm/${u}.obj")
  tp(_s "${OUT}/asm/${u}.asm")
  add_custom_command(OUTPUT "${OUT}/asm/${u}.obj" COMMAND ${TOOL_ENV} "${MS2_ml64}" /nologo /c /I "${_i}" "/Fo${_o}" "${_s}"
                     DEPENDS "${OUT}/asm/${u}.asm" "${ASM_INC}/ksamd64.inc" VERBATIM)
  list(APPEND ASMOBJS "${OUT}/asm/${u}.obj")
endforeach()
tp(_o "${OUT}/asm/glue/hookglue.obj")
tp(_s "${ASM_INC}/hookglue.asm")
tp(_l "${OUT}/asm/hookglue.lib")
add_custom_command(OUTPUT "${OUT}/asm/hookglue.lib"
                   COMMAND ${TOOL_ENV} "${MS2_ml64}" /nologo /c "/Fo${_o}" "${_s}"
                   COMMAND ${TOOL_ENV} "${MS2_lib}" /nologo /machine:x64 "/out:${_l}" "${_o}"
                   DEPENDS "${ASM_INC}/hookglue.asm" VERBATIM)

# shim_runtime.obj: entry point, trap logger, no-op hook::Register (tools/fullexe/shim.py's cl line)
set(RT_SRC "${MS2_ROOT}/tools/fullexe/shim_runtime.cpp")
tp(_s "${RT_SRC}")
tp(_o "${OUT}/shim/shim_runtime.obj")
add_custom_command(OUTPUT "${OUT}/shim/shim_runtime.obj"
                   COMMAND ${TOOL_ENV} "${MS2_cl}" /nologo /c /O2 /MD /EHsc /W3 /D_AFXDLL "${_s}" "/Fo${_o}"
                   DEPENDS "${RT_SRC}" VERBATIM)

# the response file, in link.py's order: header, import libs, SDK libs, objs, asm, shim, res, aliases, /ORDER
# (on Windows the SDK and VC libs are bare names, found through the Developer Command Prompt's LIB)
set(SDK_UM "${_tp}/msvc/Windows Kits/10/Lib/${WINSDK_VERSION}/um/x64")
set(LIBS "")
set(SYSLIBS "")
foreach(l kernel32 user32 ws2_32 shlwapi oleaut32 shell32 dsound dinput8)
  if(CMAKE_HOST_WIN32)
    list(APPEND SYSLIBS "${l}.lib")
  else()
    list(APPEND LIBS "${SDK_UM}/${l}.lib")
  endif()
endforeach()
list(APPEND LIBS "${_tp}/dxsdk/DXSDK/Lib/x64/dxguid.lib")
if(MS2_PLAIN_LEGACY_STDIO)
  if(CMAKE_HOST_WIN32)
    list(APPEND SYSLIBS "legacy_stdio_definitions.lib")
  else()
    list(APPEND LIBS "${_tp}/msvc/VC/Tools/MSVC/${MSVC_TOOLSET}/lib/x64/legacy_stdio_definitions.lib")
  endif()
endif()
tp(_exe "${OUT}/${MS2_PLAIN_NAME}.exe")
tp(_map "${OUT}/${MS2_PLAIN_NAME}.map")
set(RSP "/nologo /machine:x64 /subsystem:windows,6.0 /base:0x140000000 /dynamicbase:no /entry:ms2_fullexe_entry /manifest:no\n")
string(APPEND RSP "/opt:ref /opt:icf /debug:none /nodefaultlib:D3DX9.lib /nodefaultlib:D3DX10.lib /nodefaultlib:D3DX11.lib "
                  "/nodefaultlib:D3DCompiler.lib /nodefaultlib:NiDX9Renderer.lib\n")
string(APPEND RSP "/out:\"${_exe}\" /map:\"${_map}\"\n")
if(MS2_PLAIN_DERIVED)
  string(APPEND RSP "/ignore:4037\n")   # derived order.txt is not filtered to the defined names (that needs the objs)
endif()
# MS2_PLAIN_COMPILE: one cl command per obj, as progress.py / gbprogress.py ran it (compile.tsv: obj, tool, cwd, source,
# flag set; flags.tsv: id, args). Paths are tokens: ${TP} the third_party layout, ${ENGINE} the engine dir, ${GEN} the
# generated include trees (tree.tsv: L = symlink, F = one-line forwarding header), ${ROOT} the checkout. Sources keep
# their absolute paths, so /Z7 debug info and __FILE__ name this checkout; the exe has no debug info (/debug:none).
# No header dependencies: an edited header needs a clean rebuild (or the progress.py cache).
if(MS2_PLAIN_COMPILE)
  foreach(f compile.tsv flags.tsv tree.tsv)
    if(NOT EXISTS "${MS2_PLAIN_GLUE}/${f}")
      message(FATAL_ERROR "MS2_PLAIN_COMPILE=ON: no ${MS2_PLAIN_GLUE}/${f} (tools/fullexe/plainglue.py compile)")
    endif()
  endforeach()
  macro(untok var)
    string(REPLACE "\${TP}" "${_tp}" ${var} "${${var}}")
    string(REPLACE "\${ENGINE}" "${MS2_PLAIN_ENGINE}" ${var} "${${var}}")
    string(REPLACE "\${GEN}" "${MS2_PLAIN_GEN}" ${var} "${${var}}")
    string(REPLACE "\${ROOT}" "${MS2_PLAIN_CHECKOUT}" ${var} "${${var}}")
  endmacro()
  file(STRINGS "${MS2_PLAIN_GLUE}/tree.tsv" _rows)
  foreach(r IN LISTS _rows)
    untok(r)
    string(REPLACE "\t" ";" r "${r}")
    list(GET r 0 k)
    list(GET r 1 p)
    list(GET r 2 t)
    get_filename_component(_d "${p}" DIRECTORY)
    file(MAKE_DIRECTORY "${_d}")
    if(k STREQUAL "L")
      if(NOT IS_SYMLINK "${p}")
        file(CREATE_LINK "${t}" "${p}" SYMBOLIC COPY_ON_ERROR)
      endif()
    else()
      file(WRITE "${p}.new" "${t}\n")
      configure_file("${p}.new" "${p}" COPYONLY)
    endif()
  endforeach()
  # the compilers: 14.16 (MS2_cl), the 14.14/14.15 toolsets for some engine libs, the MS2-TOOLSET wrappers (vc9, vc9c, vc9v,
  # vc11: bash scripts with their own Wine prefix and headers; on Windows, MS2_CL_<tool> names a cl of that version)
  set(MS2_CL_cl "${MS2_cl}")
  foreach(t 1414:msvc147 1415:msvc148 vc9:msvc9 vc9c:msvc9c vc9v:msvc9v vc11:msvc11)
    string(REPLACE ":" ";" t "${t}")
    list(GET t 0 n)
    list(GET t 1 dir)
    if(CMAKE_HOST_WIN32)
      set(MS2_CL_${n} "$ENV{MS2_CL_${n}}" CACHE FILEPATH "cl for the ${n} rows of compile.tsv")
      if(NOT MS2_CL_${n})   # none of that version: the 14.16 cl builds those rows too (same flags; other codegen)
        message(WARNING "MS2_CL_${n} not set: the ${n} rows of compile.tsv build with ${MS2_cl}")
        set(MS2_CL_${n} "${MS2_cl}")
      endif()
      # the args the Linux wrappers add (tools/msvc9v/cl, tools/msvc11/cl put src/ on the include path)
      if(n STREQUAL "vc9v")
        tp(_src "${MS2_PLAIN_CHECKOUT}/src")
        tp(_fi "${MS2_PLAIN_CHECKOUT}/tools/msvc9v/compat.h")
        set(_cl_args_${n} "/I${_src}" "/FI${_fi}")
      elseif(n STREQUAL "vc11")
        tp(_src "${MS2_PLAIN_CHECKOUT}/src")
        set(_cl_args_${n} "/I${_src}")
      endif()
      # the vc9/vc11 flag sets name no CRT, so cl 19.16 standing in for them defaults to /MT: its yvals.h then tags the
      # objs RuntimeLibrary=MT_StaticRelease and pulls libcpmt.lib, which clash with the /MD objs at the link (LNK2038,
      # LNK2005). The old cl's headers did neither, so build those rows /MD like the rest (CRT calls go through __imp_).
      # /Zp8 too (the cl rows' MS2_LAYOUT_OPTIONS): at the default /Zp16, cl 19.16 rounds a derived class past a base
      # with an align(16) member, where VC9 fills the base's tail padding (ShapeDataFloatMP: 0xa0 vs the exe's 0x90)
      if(MS2_CL_${n} STREQUAL MS2_cl AND n MATCHES "^vc")
        list(APPEND _cl_args_${n} "/MD" "/Zp8")
      endif()
    elseif(n MATCHES "^vc")
      set(MS2_CL_${n} "${MS2_PLAIN_CHECKOUT}/tools/${dir}/cl")
    else()
      set(MS2_CL_${n} "${_tp}/${dir}/bin/x64/cl")
    endif()
  endforeach()
  file(STRINGS "${MS2_PLAIN_GLUE}/flags.tsv" _rows)
  foreach(r IN LISTS _rows)
    untok(r)
    string(REPLACE "\t" ";" r "${r}")
    list(POP_FRONT r id)
    # an unexpanded vcxproj macro ($(GB_SDK) in some engine /I dirs) names no dir, and the Ninja generator cannot pass
    # "$(" through; dropping it changes only the command line /Z7 records
    list(FILTER r EXCLUDE REGEX "\\$\\(")
    if(CMAKE_HOST_WIN32)    # a flag set runs to 6 KB of include dirs: past cmd.exe's 8191 once the paths are long
      string(REPLACE ";" "\"\n\"" _rsp "\"${r}\"")
      file(WRITE "${OUT}/cl/${id}.rsp.new" "${_rsp}\n")
      configure_file("${OUT}/cl/${id}.rsp.new" "${OUT}/cl/${id}.rsp" COPYONLY)
      set(_flags_${id} "@${OUT}/cl/${id}.rsp")
    else()
      set(_flags_${id} "${r}")
    endif()
  endforeach()
  file(STRINGS "${MS2_PLAIN_GLUE}/compile.tsv" _rows REGEX "^[^#]")
  foreach(r IN LISTS _rows)
    untok(r)
    string(REPLACE "\t" ";" r "${r}")
    list(GET r 0 o)
    list(GET r 1 tool)
    list(GET r 2 cwd)
    list(GET r 3 src)
    list(GET r 4 id)
    if(NOT MS2_CL_${tool})
      message(FATAL_ERROR "compile.tsv: ${o}: no compiler for ${tool} (set MS2_CL_${tool})")
    endif()
    get_filename_component(_d "${MS2_PLAIN_OBJ_ROOT}/${o}" DIRECTORY)
    file(MAKE_DIRECTORY "${_d}")
    add_custom_command(OUTPUT "${MS2_PLAIN_OBJ_ROOT}/${o}"
                       COMMAND ${TOOL_ENV} "${MS2_CL_${tool}}" ${_cl_args_${tool}} ${_flags_${id}} "/Fo${MS2_PLAIN_OBJ_ROOT}/${o}" "${src}"
                       DEPENDS "${src}" WORKING_DIRECTORY "${cwd}" VERBATIM)
  endforeach()
endif()

set(OBJS "")
file(STRINGS "${MS2_PLAIN_GLUE}/objs.txt" _rel)
foreach(o IN LISTS _rel)
  list(APPEND OBJS "${MS2_PLAIN_OBJ_ROOT}/${o}")
endforeach()
foreach(f IN LISTS IMPLIBS)
  tp(_f "${f}")
  string(APPEND RSP "\"${_f}\"\n")
endforeach()
foreach(f IN LISTS SYSLIBS)
  string(APPEND RSP "${f}\n")
endforeach()
foreach(f IN LISTS LIBS OBJS)
  tp(_f "${f}")
  string(APPEND RSP "\"${_f}\"\n")
endforeach()
foreach(f "${OUT}/asm/hookglue.lib" ${ASMOBJS} "${OUT}/shim/shim_runtime.obj" "${MS2_PLAIN_STUBS_OBJ}" "${MS2_RESOURCES_RES}")
  tp(_f "${f}")
  string(APPEND RSP "\"${_f}\"\n")
endforeach()
file(READ "${MS2_PLAIN_GLUE}/alias.rsp" _a)
string(APPEND RSP "${_a}")
set(_orderdep "")
if(MS2_PLAIN_ORDER)
  set(_orderdep "${_orderfile}")
  tp(_f "${_orderfile}")
  string(APPEND RSP "\"/order:@${_f}\"\n")
endif()
file(WRITE "${OUT}/link.rsp.new" "${RSP}")
configure_file("${OUT}/link.rsp.new" "${OUT}/link.rsp" COPYONLY)
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${MS2_PLAIN_GLUE}/objs.txt" "${MS2_PLAIN_GLUE}/alias.rsp"
             "${MS2_PLAIN_IMPORTS}" "${CRYPTOPP}/x64dll.asm" "${CRYPTOPP}/x64masm.asm")

tp(_r "${OUT}/link.rsp")
add_custom_command(OUTPUT "${OUT}/${MS2_PLAIN_NAME}.exe" "${OUT}/${MS2_PLAIN_NAME}.map"
                   COMMAND ${MS2_PLAIN_LAUNCHER} ${TOOL_ENV} "${MS2_link}" "@${_r}"
                   DEPENDS "${OUT}/link.rsp" ${IMPLIBS} ${ASMOBJS} "${OUT}/asm/hookglue.lib" "${OUT}/shim/shim_runtime.obj"
                           "${MS2_PLAIN_STUBS_OBJ}" "${MS2_RESOURCES_RES}" ${_orderdep} ${OBJS}
                   WORKING_DIRECTORY "${OUT}" USES_TERMINAL VERBATIM)
# the game's file name: a plain copy, the bytes stay those of <MS2_PLAIN_NAME>.exe
add_custom_command(OUTPUT "${OUT}/MapleStory2.exe"
                   COMMAND ${CMAKE_COMMAND} -E copy "${OUT}/${MS2_PLAIN_NAME}.exe" "${OUT}/MapleStory2.exe"
                   DEPENDS "${OUT}/${MS2_PLAIN_NAME}.exe" VERBATIM)
add_custom_target(fullexe-plain ALL DEPENDS "${OUT}/MapleStory2.exe")
