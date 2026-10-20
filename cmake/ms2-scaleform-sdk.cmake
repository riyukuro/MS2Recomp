# Scaleform GFx SDK headers (4.1.19, partial copy in work/scaleform; untracked, never copied into src/) for the recovered game
# code. Included by src/ms2/CMakeLists.txt; tools/progress.py parses MS2_SCALEFORM_DEFINITIONS / MS2_SCALEFORM_INCLUDE_DIRS from
# this file (keep the "..." one-per-line format). Opt-in: MS2_SCALEFORM_SDK defaults to work/scaleform/4.1.19/Scaleform when it
# exists; pass -DMS2_SCALEFORM_SDK= (empty) to build with the MS2 placeholders only (src/ms2/placeholder/gfxvalue.h).
# When on, the compiler sees MS2_HAVE_SCALEFORM_SDK=1 and gfxvalue.h includes the real <GFx/GFx_Player.h>.
#
# The exe links Scaleform 4.1.18 (NOTES.md "sf1: Scaleform 4.1.19 SDK"): Kernel / GFx::Value / FunctionHandler layouts match
# 4.1.19 (validated), the Render HAL (D3D9::HAL, Render::HAL) does not, so HAL/Video/Nexon types stay MS2 placeholders.
#   SF_BUILD_SHIPPING     no SF_BUILD_DEBUG (no asserts in Array/Hash), no AMP
#   SF_BUILD_STATICLIB    SF_EXPORT expands to nothing. The exe itself was built without it (it exports Scaleform symbols), but
#                         here declarations must not become dllexport of the hook DLL.
# GFxConfig.h defaults are kept (GFX_AS3_SUPPORT on: Value::DataAux at +0x18, matches the exe), except the 4.1.18 mouse /
# keyboard counts (ms2_scaleform_418_headers).
set(MS2_SCALEFORM_DEFINITIONS
    "SF_BUILD_SHIPPING"
    "SF_BUILD_STATICLIB"
    "MS2_HAVE_SCALEFORM_SDK=1"
)
set(MS2_SCALEFORM_INCLUDE_DIRS
    "Include"
    "Src"
)
get_filename_component(_ms2_sf_default "${CMAKE_CURRENT_LIST_DIR}/../work/scaleform/4.1.19/Scaleform" ABSOLUTE)
if(NOT IS_DIRECTORY "${_ms2_sf_default}")
    set(_ms2_sf_default "")
endif()
set(MS2_SCALEFORM_SDK "${_ms2_sf_default}" CACHE PATH "Scaleform GFx SDK root (dir with Include/ and Src/); empty = placeholders only")

# Scaleform 4.1.18 compatibility headers: tools/sf418_headers.py copies GFx/GFx_Player.h, GFx/GFx_Loader.h and GFxConfig.h
# from the SDK into <dir> with the exe's 4.1.18 differences (Value::ObjectInterface without the AS3 ByteArray virtuals,
# MemoryParams without InitialDynamicLimit, the extra State::StateType entry before State_IMEManager, 4 mice/keyboards;
# see the script). <dir> is searched before the SDK; same include guards. tools/progress.py runs the same script. The
# printed id of the generated text becomes MS2_SF418=<id> in the flags, so objects rebuild when the headers change.
get_filename_component(_ms2_sf418_gen "${CMAKE_CURRENT_LIST_DIR}/../tools/sf418_headers.py" ABSOLUTE)
function(ms2_scaleform_418_headers dir out_id)
    if(NOT MS2_PYTHON)
        find_package(Python3 REQUIRED COMPONENTS Interpreter)
        set(MS2_PYTHON "${Python3_EXECUTABLE}")
    endif()
    set(gen "${_ms2_sf418_gen}")
    execute_process(COMMAND "${MS2_PYTHON}" "${gen}" "${MS2_SCALEFORM_SDK}" "${dir}"
                    OUTPUT_VARIABLE id ERROR_VARIABLE err RESULT_VARIABLE rc OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT rc EQUAL 0 OR NOT id MATCHES "^0x[0-9a-f]+$")
        message(FATAL_ERROR "tools/sf418_headers.py failed (${rc}): ${err}")
    endif()
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${gen}"
                 "${MS2_SCALEFORM_SDK}/Src/GFx/GFx_Player.h" "${MS2_SCALEFORM_SDK}/Src/GFx/GFx_Loader.h"
                 "${MS2_SCALEFORM_SDK}/Include/GFxConfig.h")
    set(${out_id} "${id}" PARENT_SCOPE)
endfunction()

# clang-cl: src/ms2/sdkshim is searched before the SDK (Kernel/SF_SIMD.h shim, see there). cl 19.16 uses the SDK as is.
function(ms2_scaleform_flags target)
    if(NOT MS2_SCALEFORM_SDK OR NOT IS_DIRECTORY "${MS2_SCALEFORM_SDK}")
        return()
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_include_directories(${target} BEFORE PRIVATE "${PROJECT_SOURCE_DIR}/ms2/sdkshim")
        # clang-cl builds as C++17: the SDK uses `register` locals (Render_Containers.h) and similar C++03 idioms.
        target_compile_options(${target} PRIVATE -Wno-register -Wno-deprecated-declarations)
    endif()
    ms2_scaleform_418_headers("${CMAKE_BINARY_DIR}/ms2-sf418" sf418_id)
    target_include_directories(${target} PRIVATE "${CMAKE_BINARY_DIR}/ms2-sf418")
    foreach(d ${MS2_SCALEFORM_INCLUDE_DIRS})
        target_include_directories(${target} PRIVATE "${MS2_SCALEFORM_SDK}/${d}")
    endforeach()
    target_compile_definitions(${target} PRIVATE ${MS2_SCALEFORM_DEFINITIONS} "MS2_SF418=${sf418_id}")
endfunction()
