// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Intrusive list iterator post-increment, pre-increment and advance.
// MS2-UNIT: unit_1404487e0
// MS2-RANGE: 0x1404487e0-0x140448870 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void** FUN_140448830(void** iterator);
void** FUN_140448850(void** iterator);
void** FUN_1404487c0(void** iterator);

// @0x1404487e0
void** FUN_1404487e0(void** iterator, void** out, int /*unused*/)
{
    void* current = *iterator;
    FUN_140448830(iterator);
    *out = current;
    return out;
}

// @0x140448830
void** FUN_140448830(void** iterator)
{
    FUN_1404487c0(iterator);
    return iterator;
}

// @0x140448850
void** FUN_140448850(void** iterator)
{
    *iterator = *static_cast<void**>(*iterator);
    return iterator;
}
