// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). List iterator advance to the second link (offset 8).
// MS2-UNIT: unit_1404495e0
// MS2-RANGE: 0x1404495e0-0x140449650 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

struct Unk_ListLink
{
    void* m_pFirst;
    void* m_pSecond;
};

void** FUN_1404495e0(void** iterator);

// @0x1404495e0
void** FUN_1404495e0(void** iterator)
{
    void* next = static_cast<Unk_ListLink*>(*iterator)->m_pSecond;
    *iterator = next;
    return iterator;
}

// @0x140449610
void** FUN_140449610(void** iterator)
{
    FUN_1404495e0(iterator);
    return iterator;
}

// @0x140449630
void** FUN_140449630(void** iterator)
{
    *iterator = static_cast<Unk_ListLink*>(*iterator)->m_pSecond;
    return iterator;
}
