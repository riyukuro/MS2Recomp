// The string-id formatter FUN_14028dee0 (commonutil.cpp: looks the id up in the string table and formats its
// "{0}..." text with the arguments) and its variadic wrappers FormatStringId<...>, the exe's names for the
// instances (FormatStringId<CStringW> is 0x14052bd00). Same body as FMT_VARIADIC_W(CStringW, FormatStringId, int),
// but the wrappers call FUN_14028dee0 by its real name instead of an aliased FormatStringId(int, const ArgList&).
// Each argument-type list is one COMDAT in the first unit that uses it.
#pragma once

#include "ms2/fmt/format.h"

CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
#define FSI_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FormatStringId(int arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, FMT_MAKE_REF_wchar_t)}; \
        return FUN_14028dee0(arg1, fmt::ArgList(fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
FSI_WRAP(1)
FSI_WRAP(2)
FSI_WRAP(3)
FSI_WRAP(4)
FSI_WRAP(5)
FSI_WRAP(6)
FSI_WRAP(7)
FSI_WRAP(8)
FSI_WRAP(9)
FSI_WRAP(10)
FSI_WRAP(11)
FSI_WRAP(12)
FSI_WRAP(13)
FSI_WRAP(14)
FSI_WRAP(15)
#undef FSI_WRAP
