// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pet summon state check, its message key and an item-type
// based slot value lookup (names invented).
// MS2-UNIT: unit_14072f7f0
// MS2-RANGE: 0x14072f7f0-0x14072fd10 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ascript.h"

// Unit-local view of the per-slot value table (ints at +0x00..+0x24).
struct Unk_SlotValueTable {
    int m_0;
    int m_4;
    int m_8;
    int m_c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
};

MS2Ptr<CItemData> FUN_14053f870(int nItemId);
bool FUN_14053f8c0(unsigned nItemId);
bool FUN_14053f900(unsigned nItemId);
bool FUN_14053f940(unsigned nItemId);
int FUN_14053f990_1(int nId);
int FUN_14072f890(int nState);

// @0x14072f7f0
int FUN_14072f7f0(int nState)
{
    if (FUN_14072f890(nState) == 0) return 0;
    return 1;
}

// @0x14072f890
int FUN_14072f890(int nState)
{
    if (nState == 3) return 0;
    if (nState == 6) return 0;
    if (nState == 7) return 0;
    if (nState == 9) return 0;
    if (nState == 0x1d) return 0;
    if (nState == 0x1e) return 0;
    if (nState == 5) return 0;
    if (nState == 0x1f) return 0;
    if (nState == 0x1b) return 0;
    if (nState == 0x1c) return 0;
    if (nState == 8) return 0;
    if (nState == 0x2f) return 0;
    if (nState == 0x2d) return 0;
    if (nState == 0x12) return 0;
    if (nState == 0x2b) return 0;
    if (nState == 0x20) return 0;
    if (nState == 0x10) return 0;
    return 1;
}

// @0x14072f970
int FUN_14072f970(int nState)
{
    if (FUN_14072f890(nState) == 0) return 0;
    return 1;
}

// @0x14072f9a0
CStringW FUN_14072f9a0(int nState)
{
    if (nState == 0x2f) return CStringW(L"s_pet_cant_summon_state_play_instrument");
    if (nState == 0x2d) return CStringW(L"s_pet_cant_summon_state_fishing");
    if (nState == 0x10) return CStringW(L"s_pet_cant_summon_state_skill");
    return CStringW(L"");
}

// @0x14072fa70
int FUN_14072fa70(Unk_SlotValueTable* pTable, int nItemId, int nLevel)
{
    if (FUN_14053f900(nItemId)) return 1;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0) return 0;
    switch (spItem->FUN_14053c5c0()) {
    case 0xb:
        return pTable->m_1c;
    case 0xd:
    case 0xe:
        return pTable->m_18;
    case 4:
        if (FUN_14053f8c0(nItemId)) return pTable->m_0;
        if (FUN_14053f940(nItemId)) return pTable->m_4;
        if (FUN_14053f990_1(nItemId)) return pTable->m_c;
        return pTable->m_8;
    case 1:
        if (pTable->m_24 > nLevel) return 0;
        return pTable->m_10;
    case 2:
        return pTable->m_14;
    }
    return pTable->m_8;
}

// @0x14072fd00
int FUN_14072fd00(int nUnused)
{
    return 1;
}
