// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Avatar customize id helpers: the
// customize id of an item data record, the same starting from a CItem (through its data record), and
// the item id of the item equipped in one avatar slot.
// MS2-UNIT: unit_141420f10
// MS2-RANGE: 0x141420f10-0x1414210f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\avatarcustomize.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/fittingdollpc.h"

class AvatarPC;

// Unrecovered callees (0x141420b30 is defined in unit_141420a70).
int FUN_141420b30(CItemData* pData, AvatarPC* pAvatar);           // 0x141420b30 the customize id of a data record
MS2Ptr<CEquipItem> FUN_1414211a0(int nSlot, AvatarPC* pAvatar);   // 0x1414211a0 the equipped item of a slot

// @0x141420f10
int FUN_141420f10(CItemData* pData, AvatarPC* pAvatar)
{
    if (pData == 0)
        return 0;
    if (pData->FUN_14053d2b0())
    {
        return 8;
    }
    else
    {
        if (pAvatar != 0)
        {
            int nCustomizeId = FUN_141420b30(pData, pAvatar);
            if (nCustomizeId != 0)
                return nCustomizeId;
        }
    }
    return pData->FUN_14053eba0()->FUN_14054b400();
}

// @0x141420f90
int FUN_141420f90(CItem* pItem, AvatarPC* pAvatar)
{
    if (pItem == 0)
        return 0;
    CItemData* pData = reinterpret_cast<CItemData*>(pItem->FUN_140527840());
    if (pData == 0)
        return 0;
    if (pData->FUN_14053d510())
    {
        if (pItem->FUN_140526c30())
            return pItem->FUN_140526c30();
        int nCustomizeId = FUN_141420b30(pData, pAvatar);
        if (nCustomizeId != 0)
        {
            pItem->FUN_140526c10(nCustomizeId);
            return nCustomizeId;
        }
    }
    return FUN_141420f10(pData, pAvatar);
}

// @0x141421040
int FUN_141421040(int nSlot, AvatarPC* pAvatar)
{
    {
        MS2Ptr<CEquipItem> spEquip = FUN_1414211a0(nSlot, pAvatar);
        if (spEquip.get())
            return spEquip->GetItem()->FUN_1405276c0();
    }
    return 0;
}
