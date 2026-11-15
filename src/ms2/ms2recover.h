// ms2recover.h - helpers for byte-matching recovered game code. NOT an original Nexon header.
// Conventions: docs/RECOVERY.md. Must stay C++14 and compile under cl 19.16 and clang-cl.
//
//   MS2_THIS_FILE        every recovered .cpp defines it (before including anything) as the original __FILE__ string,
//                        e.g. #define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\md5checksum.cpp"
//   MS2_ASSERT_AT(line, expr)
//                        assert() with the original line number: same code as <assert.h>'s assert (no NDEBUG in the
//                        game build), but file/line are the original ones, so the source keeps its own line numbers
//                        (and line tables stay usable by tools/progress.py). Use the line from the decompiled
//                        _wassert call (3rd argument).
//   MS2_LINE(line)       an original __LINE__ value used outside assert (logging/exception macros).
//   MS2_CHECK_SIZE(T, n) / MS2_CHECK_OFFSET(T, member, off)
//                        layout pins (ms2layout.h, which headers include directly).
//   MS2_EMIT_CRT_MEMMOVE_S()
//                        ~45% of the original objs contain an unreferenced copy of the CRT's static-inline memmove_s
//                        (271 bytes, sorted last in the obj's COMDAT tail). Its referrer was a discarded COMDAT whose
//                        source is unknown (not reproducible from afx/atl/std headers alone). This forces the same copy
//                        through ATL::Checked::memmove_s, which the original also used. Put it once at file scope.
#pragma once

#include <assert.h>
#include <stddef.h>

#include "ms2/ms2layout.h"

#ifndef MS2_THIS_FILE
#error "define MS2_THIS_FILE (the original __FILE__ string) before including ms2recover.h"
#endif

// <assert.h> only declares _wassert without NDEBUG (the clang-cl RelWithDebInfo build defines it); the game asserts always.
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#if defined(MS2_RETAIL) && !defined(MS2_HOOK_DLL)
// MS2-RESTORE: the retail build (MS2_RETAIL, README.md "Retail build") drops the asserts as NDEBUG drops assert():
// the expression is not evaluated. No MS2_ASSERT_AT expression has a side effect (each one only reads or compares).
#define MS2_ASSERT_AT(line, expression) ((void)0)
#else
#define MS2_ASSERT_AT(line, expression)                                                                   \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))
#endif

#define MS2_LINE(line) (line)


// MS2_FOR_EACH(decl, range)
//   MSVC's non-standard `for each (decl in range)`: the exe shape is a range reference, end() then begin() into
//   temps copied to the iterator locals (a C++11 range-for calls begin() first). clang-cl has no `for each`, so the
//   hook build uses the equivalent range-for.
#ifdef __clang__
#define MS2_FOR_EACH(decl, range) for (decl : range)
#else
#define MS2_FOR_EACH(decl, range) for each (decl in range)
#endif

#define MS2_EMIT_CRT_MEMMOVE_S()                                                                          \
    __declspec(selectany) extern void(__cdecl* const ms2_pfnCheckedMemmoveS)(void*, size_t, const void*, size_t) = \
        &ATL::Checked::memmove_s

// MS2_EMIT_CRT_MEMMOVE_S_COPY(n)
//   One more internal-linkage copy of the CRT memmove_s (a unit range that spans two original TUs holds two of them: the
//   UCRT's `static __inline memmove_s` is per TU, never folded). Put `// @0x<va>` directly above the invocation, with
//   MS2_EMIT_CRT_MEMMOVE_S() once for the first TU's copy; n only makes the name unique (use 2, 3...).
#include <errno.h>
#include <string.h>
#define MS2_EMIT_CRT_MEMMOVE_S_COPY(n)                                                                       \
    static __inline errno_t ms2_memmove_s_copy##n(void* const d, size_t const dsz, void const* const s, size_t const ssz) \
    { if (ssz == 0) { return 0; }                                                                            \
      { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }     \
      { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }     \
      { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }    \
      memmove(d, s, ssz); return 0; }                                                                        \
    __declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemmoveSCopy##n)(void*, size_t, const void*, size_t) = \
        &ms2_memmove_s_copy##n
