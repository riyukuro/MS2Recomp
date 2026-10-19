// The string-key formatter FUN_14028dfa0 (commonutil.cpp: looks the key up in the string table and formats its
// "{0}..." text with the arguments) and its variadic wrappers. The wrappers take the key by value, as the exe's
// instances do (the callee destroys it). Each argument-type list is one COMDAT in the first unit that uses it.
// Same shape as item.cpp's local copy (0x14052b9d0 matches); shared here by w127 for itemsocketsystemutil.cpp.
#pragma once

#include "ms2/fmt/format.h"

CStringW FUN_14028dfa0(const CStringW&, const fmt::ArgList&);
namespace fmt { namespace internal {
struct Unk_WcFormatter { typedef wchar_t Char; };
template <typename T> inline ULongLong wc_make_type(const T& arg) { return MakeValue<Unk_WcFormatter>::type(arg); }
struct Unk_WcArgType {
    ULongLong type;
    Unk_WcArgType() : type(0) {}
    template <typename T> Unk_WcArgType(const T& arg) : type(wc_make_type(arg)) {}
};
inline ULongLong wc_make_type(Unk_WcArgType t0 = Unk_WcArgType(), Unk_WcArgType t1 = Unk_WcArgType(), Unk_WcArgType t2 = Unk_WcArgType(),
                              Unk_WcArgType t3 = Unk_WcArgType(), Unk_WcArgType t4 = Unk_WcArgType(), Unk_WcArgType t5 = Unk_WcArgType(),
                              Unk_WcArgType t6 = Unk_WcArgType(), Unk_WcArgType t7 = Unk_WcArgType(), Unk_WcArgType t8 = Unk_WcArgType(),
                              Unk_WcArgType t9 = Unk_WcArgType(), Unk_WcArgType t10 = Unk_WcArgType(), Unk_WcArgType t11 = Unk_WcArgType(),
                              Unk_WcArgType t12 = Unk_WcArgType(), Unk_WcArgType t13 = Unk_WcArgType(), Unk_WcArgType t14 = Unk_WcArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
#define WC_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
WC_WRAP(1)
WC_WRAP(2)
WC_WRAP(3)
WC_WRAP(4)
WC_WRAP(5)
WC_WRAP(6)
