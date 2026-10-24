// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Intrusive list iterator post-increment and advance.
// MS2-UNIT: unit_140448770
// MS2-RANGE: 0x140448770-0x1404487e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void** FUN_1404487c0(void** iterator);

// @0x140448770
void** FUN_140448770(void** iterator, void** out, int /*unused*/)
{
    void* current = *iterator;
    FUN_1404487c0(iterator);
    *out = current;
    return out;
}

// @0x1404487c0
void** FUN_1404487c0(void** iterator)
{
    *iterator = *static_cast<void**>(*iterator);
    return iterator;
}
