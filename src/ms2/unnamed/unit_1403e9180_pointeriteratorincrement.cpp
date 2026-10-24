// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pointer iterator over 0x10-byte elements: advance, post- and pre-increment.
// MS2-UNIT: unit_1403e9180
// MS2-RANGE: 0x1403e9180-0x1403e9210 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void** FUN_1403e9180(void** iterator);
void** FUN_1403e91f0(void** iterator);

// @0x1403e9180
void** FUN_1403e9180(void** iterator)
{
    *iterator = static_cast<char*>(*iterator) + 0x10;
    return iterator;
}

// @0x1403e91a0
void** FUN_1403e91a0(void** iterator, void** out, int /*unused*/)
{
    void* current = *iterator;
    FUN_1403e91f0(iterator);
    *out = current;
    return out;
}

// @0x1403e91f0
void** FUN_1403e91f0(void** iterator)
{
    FUN_1403e9180(iterator);
    return iterator;
}
