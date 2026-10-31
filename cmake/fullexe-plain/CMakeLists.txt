# Plain full-exe link: no Python at build time. One closed link of the compiled objs with committed glue files, the same
# command line link2 (cmake/fullexe, tools/fullexe/link.py --alias --order --shim --before) builds:
#   MS2_PLAIN_GLUE/objs.txt    the objs in link order (plan order + the initorder --before moves), relative to MS2_PLAIN_OBJ_ROOT
#   MS2_PLAIN_GLUE/alias.rsp   the /alternatename lines (alias.rsp + datapair-alias.rsp as link2 took them)
#   MS2_PLAIN_GLUE/order.txt   the /ORDER list
#   data/fullexe/imports.tsv   the import names: one .def per DLL here at configure time, lib /def at build time
# tools/fullexe/plainglue.py write <dir> regenerates the glue from a finished cmake/fullexe build (names, paths and order
# only); plainglue.py stubs <exe> <dir>/stubs.tsv <obj> extracts the one data stub (g_physXItem, the exe's bytes) once,
# like tools/extract_resources.py does the resources. Built here: the import libs, CryptoPP's MASM objs, hookglue.lib
# and shim_runtime.obj.
# Not covered yet: the compile. MS2_PLAIN_OBJ_ROOT is the obj cache a cmake/fullexe build (build/progress-<tag>) or
# the gates left.
#   cmake -S cmake/fullexe-plain -B build/fullexe-plain -G Ninja -DMS2_PLAIN_GLUE=<dir> -DMS2_PLAIN_OBJ_ROOT=<cache>
#         -DMS2_PLAIN_STUBS_OBJ=<obj> -DMS2_RESOURCES_RES=<res>
#   cmake --build build/fullexe-plain          -> build/fullexe-plain/out/<MS2_PLAIN_NAME>.exe (+ .map)
cmake_minimum_required(VERSION 3.20)
project(ms2_fullexe_plain NONE)

set(MS2_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." CACHE PATH "repository root")
get_filename_component(MS2_ROOT "${MS2_ROOT}" ABSOLUTE)
set(MS2_PLAIN_GLUE "" CACHE PATH "dir with objs.txt, alias.rsp, order.txt (tools/fullexe/plainglue.py write)")
set(MS2_PLAIN_OBJ_ROOT "" CACHE PATH "obj cache objs.txt is relative to (build/progress-<tag>)")
set(MS2_PLAIN_STUBS_OBJ "" CACHE FILEPATH "data-stub obj (tools/fullexe/plainglue.py stubs)")
set(MS2_RESOURCES_RES "" CACHE FILEPATH "the .res (tools/extract_resources.py --compile)")
set(MS2_PLAIN_IMPORTS "${MS2_ROOT}/data/fullexe/imports.tsv" CACHE FILEPATH "import names (dll, symbol)")
option(MS2_PLAIN_ORDER "link with the /ORDER list (the exe's function layout; off = the linker's own order)" ON)
option(MS2_PLAIN_LEGACY_STDIO "link legacy_stdio_definitions.lib (link.py adds it when MS2-TOOLSET objs are linked)" ON)
set(MS2_PLAIN_NAME fullexe-plain CACHE STRING "output name: <name>.exe/.map (the exe's export directory records it; fullexe3 = link2's)")
set(MS2_PLAIN_LAUNCHER "" CACHE STRING "command the link runs under (e.g. a lock wrapper); empty = none")
set(MS2_MSVC_ROOT "" CACHE PATH "third_party/-layout dir: msvc/ (MSVC 14.16 + Windows SDK, msvc-wine), dxsdk/, src/cryptopp562; empty = third_party")
set(WINSDK_VERSION "10.0.19041.0" CACHE STRING "Windows SDK version of the MSVC tree")
set(MSVC_TOOLSET "14.16.27023" CACHE STRING "MSVC toolset dir of the MSVC tree")
foreach(v MS2_PLAIN_GLUE MS2_PLAIN_OBJ_ROOT MS2_PLAIN_STUBS_OBJ MS2_RESOURCES_RES)
  if(NOT ${v} OR NOT EXISTS "${${v}}")
    message(FATAL_ERROR "${v}=${${v}}: missing (see the header of ${CMAKE_CURRENT_LIST_FILE})")
  endif()
endforeach()
if(MS2_MSVC_ROOT)
  set(_tp "${MS2_MSVC_ROOT}")
else()
  set(_tp "${MS2_ROOT}/third_party")
endif()

set(OUT "${CMAKE_BINARY_DIR}/out")
file(MAKE_DIRECTORY "${OUT}/implib" "${OUT}/asm/glue" "${OUT}/shim")

# tools: msvc-wine's wrappers under wine (paths in z:\ form, the prefix tools/ms2paths.py uses), or the Developer
# Command Prompt's on Windows
if(CMAKE_HOST_WIN32)
  set(TOOL_ENV "")
  foreach(t cl link lib ml64)
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
  foreach(t cl link lib ml64)
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
set(SDK_UM "${_tp}/msvc/Windows Kits/10/Lib/${WINSDK_VERSION}/um/x64")
set(LIBS "")
foreach(l kernel32 user32 ws2_32 shlwapi oleaut32 shell32 dsound dinput8)
  list(APPEND LIBS "${SDK_UM}/${l}.lib")
endforeach()
list(APPEND LIBS "${_tp}/dxsdk/DXSDK/Lib/x64/dxguid.lib")
if(MS2_PLAIN_LEGACY_STDIO)
  list(APPEND LIBS "${_tp}/msvc/VC/Tools/MSVC/${MSVC_TOOLSET}/lib/x64/legacy_stdio_definitions.lib")
endif()
tp(_exe "${OUT}/${MS2_PLAIN_NAME}.exe")
tp(_map "${OUT}/${MS2_PLAIN_NAME}.map")
set(RSP "/nologo /machine:x64 /subsystem:windows,6.0 /base:0x140000000 /dynamicbase:no /entry:ms2_fullexe_entry /manifest:no\n")
string(APPEND RSP "/opt:ref /opt:icf /debug:none /nodefaultlib:D3DX9.lib /nodefaultlib:D3DX10.lib /nodefaultlib:D3DX11.lib "
                  "/nodefaultlib:D3DCompiler.lib /nodefaultlib:NiDX9Renderer.lib\n")
string(APPEND RSP "/out:\"${_exe}\" /map:\"${_map}\"\n")
set(OBJS "")
file(STRINGS "${MS2_PLAIN_GLUE}/objs.txt" _rel)
foreach(o IN LISTS _rel)
  list(APPEND OBJS "${MS2_PLAIN_OBJ_ROOT}/${o}")
endforeach()
foreach(f IN LISTS IMPLIBS LIBS OBJS)
  tp(_f "${f}")
  string(APPEND RSP "\"${_f}\"\n")
endforeach()
foreach(f "${OUT}/asm/hookglue.lib" ${ASMOBJS} "${OUT}/shim/shim_runtime.obj" "${MS2_PLAIN_STUBS_OBJ}" "${MS2_RESOURCES_RES}")
  tp(_f "${f}")
  string(APPEND RSP "\"${_f}\"\n")
endforeach()
file(READ "${MS2_PLAIN_GLUE}/alias.rsp" _a)
string(APPEND RSP "${_a}")
if(MS2_PLAIN_ORDER)
  tp(_f "${MS2_PLAIN_GLUE}/order.txt")
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
                           "${MS2_PLAIN_STUBS_OBJ}" "${MS2_RESOURCES_RES}" "${MS2_PLAIN_GLUE}/order.txt" ${OBJS}
                   WORKING_DIRECTORY "${OUT}" USES_TERMINAL VERBATIM)
add_custom_target(fullexe-plain ALL DEPENDS "${OUT}/${MS2_PLAIN_NAME}.exe")
