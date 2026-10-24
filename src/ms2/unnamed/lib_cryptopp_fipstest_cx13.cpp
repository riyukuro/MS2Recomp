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

// MS2-FUNCTIONAL: delegates the requested property and returns the adapter's bool field; stack temporary initialization is equivalent but may differ in EH metadata.
// @0x1423781c0
bool GetVoidValueCx13Ec2n(void* self, void* name, void* valueType, void* output)
{
    std::uint8_t temporary[56]{};
    FUN_1423739b0(temporary, static_cast<std::uint8_t*>(self) - 0x178,
                  name, valueType, output, 0);
    auto* result = static_cast<std::uint8_t*>(FUN_1423759b0(temporary));
    return result[0x20] != 0;
}

// MS2-FUNCTIONAL: delegates the requested property and returns the adapter's bool field; stack temporary initialization is equivalent but may differ in EH metadata.
// @0x142378240
bool GetVoidValueCx13Ecp(void* self, void* name, void* valueType, void* output)
{
    std::uint8_t temporary[56]{};
    FUN_142373ef0(temporary, static_cast<std::uint8_t*>(self) - 0x170,
                  name, valueType, output, 0);
    auto* result = static_cast<std::uint8_t*>(FUN_142375d80(temporary));
    return result[0x20] != 0;
}
