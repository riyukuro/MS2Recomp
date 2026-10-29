// Executable-derived adapters for two Crypto++ private-key property queries.
// MS2-UNIT: lib_cryptopp_fipstest_cx13
// MS2-RANGE: 0x1423781c0-0x1423781ff .text$mn
// MS2-RANGE: 0x142378240-0x14237827f .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstdint>

extern void FUN_1423739b0(void* temporary, void* group, void* name,
                           void* valueType, void* output, std::uint64_t flags);
extern void* FUN_1423759b0(void* temporary);
extern void FUN_142373ef0(void* temporary, void* group, void* name,
                           void* valueType, void* output, std::uint64_t flags);
extern void* FUN_142375d80(void* temporary);

namespace {
// GetValueHelperClass-shaped temporary: object, name, type, value pointers, then the found flag at 0x20.
struct Cx13GetValueTemp
{
    Cx13GetValueTemp() {}
    std::uint64_t w0, w1, w2, w3, w4, w5;
};
}

// @0x1423781c0
bool GetVoidValueCx13Ec2n(void* self, void* name, void* valueType, void* output)
{
    Cx13GetValueTemp temporary;
    FUN_1423739b0(&temporary, static_cast<std::uint8_t*>(self) - 0x178,
                  name, valueType, output, 0);
    auto* result = static_cast<std::uint8_t*>(FUN_1423759b0(&temporary));
    return *reinterpret_cast<bool*>(result + 0x20);
}

// @0x142378240
bool GetVoidValueCx13Ecp(void* self, void* name, void* valueType, void* output)
{
    Cx13GetValueTemp temporary;
    FUN_142373ef0(&temporary, static_cast<std::uint8_t*>(self) - 0x170,
                  name, valueType, output, 0);
    auto* result = static_cast<std::uint8_t*>(FUN_142375d80(&temporary));
    return *reinterpret_cast<bool*>(result + 0x20);
}
