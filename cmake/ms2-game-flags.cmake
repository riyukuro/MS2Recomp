# Compiler flags Nexon used for the MapleStory2 game code (ms2code/..., KMS2_DEV x64 2022-04-13), derived by
# byte-matching 52 recovered functions against the exe with cl 19.16 (NOTES.md "Game-code compiler flags
# (byte-matching)", tools/bytematch.py). Only meaningful for real MSVC (cl 19.16); clang-cl never byte-matches.
#
#   /Od /Ob0      no optimization, no inlining (params homed, std::forward/swap/ATL accessors are real calls)
#   /Oi           intrinsics on even at /Od: strlen expanded inline (CreateDirectories 0x1415c31b0)
#   /EHsc         FuncInfo EHFlags=1 (rules out /EHa); no EH state around extern "C" calls (rules out /EHs)
#   /GS           cookies + __report_rangecheckfailure (GetSecond 0x1401d0680, CreateDirectories 0x1415c31b0)
#   /fp:fast      float compares have no parity (NaN) check (equal_to<float> 0x140193370, 0x140783930)
#   /std:c++14    C++14 evaluation order of `a = f()` (swap/forward pattern, 0x1401cd920); c++17 breaks 9 of 52
#   /MD           release DLL CRT/MFC (imports VCRUNTIME140 / MSVCP140 / mfc140.dll), no _DEBUG
#   no NDEBUG     asserts are live (751 game functions call _wassert, e.g. 0x1408e7930)
#   _MBCS         narrow Win32 API (MessageBoxA, CreateFileA), MBCS MFC (mfc140.dll, not mfc140u.dll)
#   _AFXDLL       MFC as a shared DLL (required by afx.h with /MD; CString methods are mfc140.dll imports)
#   also on       /GR /Gy (COMDAT per function) /Zc:wchar_t /Zc:threadSafeInit /Zc:sizedDealloc; no /permissive-
#   absent        /RTC* /JMC /sdl /guard:cf /arch:AVX* /Qspectre /J (each tested: breaks matches); no /GL (no LTCG)
#   charset       /source-charset:utf-8 /execution-charset:.949: our sources are UTF-8 without a BOM, which cl reads as
#                 the build host's ANSI page (1252), turning every Korean L"..." into mojibake; the exe's wide literals
#                 are UTF-16 Hangul and its narrow ones CP949 (Nexon's Korean-locale build). Narrow non-ASCII bytes that
#                 must stay as-is are written as \x escapes (scaleform/as3/sfr_as3_13.cpp key names).
#   untestable    /Zi vs /Z7, /permissive-, /hotpatch: no codegen difference
#
# _ITERATOR_DEBUG_LEVEL is 0, which is the /MD release default (no define needed).

set(MS2_GAME_COMPILE_OPTIONS /Od /Ob0 /Oi /EHsc /GS /GR /Gy /fp:fast /Zc:wchar_t /Zc:threadSafeInit
    /source-charset:utf-8 /execution-charset:.949)
set(MS2_GAME_COMPILE_DEFINITIONS _MBCS _AFXDLL)
set(MS2_GAME_CXX_STANDARD 14)

# Command line for a standalone experiment (tools/bytematch.py workflow):
#   cl /nologo /c /Od /Oi /EHsc /MD /Z7 /fp:fast /D_MBCS /D_AFXDLL /Fofoo.obj /FAsc /Fafoo.cod foo.cpp
# (tools/progress.py uses the same list: keep MS2_GAME_COMPILE_OPTIONS / _DEFINITIONS in sync with GAME_FLAGS there.)
set(MS2_GAME_CL_FLAGS "/Od /Oi /EHsc /MD /Z7 /fp:fast /D_MBCS /D_AFXDLL")

# Apply the game flags to `target` (an OBJECT library of game sources). Under MSVC the caller's directory must not
# add optimization / NDEBUG flags of its own (src/ms2/CMakeLists.txt clears CMAKE_CXX_FLAGS_<CONFIG>).
function(ms2_game_flags target)
    # Both compilers: the game's preprocessor environment (MBCS + MFC DLL); see also src/ms2/CMakeLists.txt, which
    # drops the hook project's WIN32_LEAN_AND_MEAN/NOMINMAX/_CRT_SECURE_NO_WARNINGS and /utf-8 for game code.
    target_compile_definitions(${target} PRIVATE _MBCS _AFXDLL)
    # Only the hook DLL builds define MS2_HOOK_DLL (tools/progress.py does not): game code that must not run its static
    # initializers inside the DLL (self-registering exe-wide registrations) is wrapped in `#ifndef MS2_HOOK_DLL`.
    target_compile_definitions(${target} PRIVATE MS2_HOOK_DLL)
    if(MSVC AND NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target} PRIVATE ${MS2_GAME_COMPILE_OPTIONS})
        target_compile_definitions(${target} PRIVATE ${MS2_GAME_COMPILE_DEFINITIONS})
        set_target_properties(${target} PROPERTIES CXX_STANDARD ${MS2_GAME_CXX_STANDARD})
    endif()
endfunction()
