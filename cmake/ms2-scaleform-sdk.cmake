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
# GFxConfig.h defaults are kept (GFX_AS3_SUPPORT on: Value::DataAux at +0x18, matches the exe).
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

# GFx::Value::ObjectInterface of the exe (4.1.18) has no AS3 ByteArray virtuals: the AS3ValueObjectInterface vftable 0x14317eff8
# has 40 slots (SetElement 13, PushBack 15, RemoveElements 17, GetWorldMatrix 21, GetCxform 26, ToString 35), 4.1.19 declares
# IsByteArray/GetByteArraySize/ReadFromByteArray/WriteToByteArray as slots 18-21, so every Value inline from
# IsDisplayObjectActive on called 4 slots too far (Value::GotoAndPlay(const char*): [+0x130] = CreateObjectValue instead of the
# exe's [+0x110]). <dir>/GFx/GFx_Player.h = the SDK header without those 4 virtuals and Value's AS3 ByteArray inlines (same
# include guard, searched before the SDK; tools/progress.py generates the same file). Rewritten only when the content changes.
function(ms2_scaleform_418_player_h dir)
    file(READ "${MS2_SCALEFORM_SDK}/Src/GFx/GFx_Player.h" h)
    string(REGEX REPLACE "\n[ ]*GFX_VM_ABSTRACT\\([a-z]+ +(IsByteArray|GetByteArraySize|ReadFromByteArray|WriteToByteArray)\\([^\n]*" "" h "${h}")
    string(REGEX REPLACE "\n#ifdef GFX_AS3_SUPPORT\r?\n[ ]*SF_INLINE bool +IsByteArray\\(\\)[^#]*#endif[^\n]*" "" h "${h}")
    if(h MATCHES "ByteArray\\(")
        message(FATAL_ERROR "ms2_scaleform_418_player_h: GFx_Player.h ByteArray declarations not removed")
    endif()
    set(out "${dir}/GFx/GFx_Player.h")
    if(EXISTS "${out}")
        file(READ "${out}" old)
    else()
        set(old "")
    endif()
    if(NOT old STREQUAL h)
        file(WRITE "${out}" "${h}")
    endif()
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
    ms2_scaleform_418_player_h("${CMAKE_BINARY_DIR}/ms2-sf418")
    target_include_directories(${target} PRIVATE "${CMAKE_BINARY_DIR}/ms2-sf418")
    foreach(d ${MS2_SCALEFORM_INCLUDE_DIRS})
        target_include_directories(${target} PRIVATE "${MS2_SCALEFORM_SDK}/${d}")
    endforeach()
    target_compile_definitions(${target} PRIVATE ${MS2_SCALEFORM_DEFINITIONS})
endfunction()
