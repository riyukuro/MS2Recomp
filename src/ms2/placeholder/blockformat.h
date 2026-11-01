// BlockFormat<...>, the exe's name for a second set of variadic wrappers over the string-id formatter
// FUN_14028dee0 (BlockFormat<int> is 0x1408116a0). Same body as FMT_VARIADIC_W(CStringW, BlockFormat, int),
// but the wrappers call FUN_14028dee0 by its real name instead of an aliased BlockFormat(int, const ArgList&).
#pragma once

#include "ms2/fmt/format.h"

CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
#define BF_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW BlockFormat(int arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, FMT_MAKE_REF_wchar_t)}; \
        return FUN_14028dee0(arg1, fmt::ArgList(fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
BF_WRAP(1)
BF_WRAP(2)
BF_WRAP(3)
BF_WRAP(4)
BF_WRAP(5)
BF_WRAP(6)
BF_WRAP(7)
BF_WRAP(8)
BF_WRAP(9)
BF_WRAP(10)
BF_WRAP(11)
BF_WRAP(12)
BF_WRAP(13)
BF_WRAP(14)
BF_WRAP(15)
#undef BF_WRAP
