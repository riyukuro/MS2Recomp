// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Avatar item helpers (the file after unit_141420f10's):
// the uid of the item equipped in an avatar slot, the equipped-item handle of a slot, the "can these two worn items be
// combined" test, and the "item has any of the five costume flags" test.
// MS2-UNIT: unit_1414210f0
// MS2-RANGE: 0x1414210f0-0x141421740 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\avatarcustomize.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/pcinfo.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/fittingdollpc.h"

class AvatarPC;
class Unk_AvPlayers;

class Unk_AvPlayers { public: AvatarPC* FUN_141bd0cc0(); };
Unk_AvPlayers* FUN_1403ed2d0();
MS2Ptr<CEquipItem> FUN_1414211a0(int nSlot, AvatarPC* pAvatar);
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);    // pop the system message nTable

// @0x1414210f0
__int64 FUN_1414210f0(int nSlot, AvatarPC* pAvatar)
{
    {
        MS2Ptr<CEquipItem> spEquip = FUN_1414211a0(nSlot, pAvatar);
        if (spEquip.get())
            return spEquip->FUN_1411dc7a0()->FUN_140526a50();
    }
    return 0;
}

// @0x1414211a0
MS2Ptr<CEquipItem> FUN_1414211a0(int nSlot, AvatarPC* pAvatar)
{
    if (pAvatar == 0)
    {
        pAvatar = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pAvatar == 0)
            return MS2Ptr<CEquipItem>(0);
    }
    return reinterpret_cast<PC*>(pAvatar)->FUN_141655e10(nSlot);
}

// @0x141421230
// MS2-FUNCTIONAL: first-pass source; the exe's per-exit release order / temp frame not byte-compared.
int FUN_141421230(MS2Ptr<CItem> spFirst, MS2Ptr<CItem> spSecond, MS2Ptr<PCInfo> spPc)
{
    if (!(spFirst == 0))
    {
        CItemData* pData = reinterpret_cast<CItemData*>(spFirst->FUN_140527840());
        if (!pData->FUN_14053d510())
            return 0;
        MS2Ptr<CItem> spHead = spPc->FUN_140dba790(static_cast<Unk_InventoryEquipSlot>(4));
        MS2Ptr<CItem> spBody = spPc->FUN_140dba790(static_cast<Unk_InventoryEquipSlot>(5));
        if (spHead.get() == 0 || spBody.get() == 0)
        {
            if (!(spHead == 0) || !(spBody == 0))
            {
                FUN_140d73bc0(0xd5, 0, 0, CStringW(L""));
                return 0;
            }
            if (!(spSecond == 0))
            {
                CItemData* pOther = reinterpret_cast<CItemData*>(spSecond->FUN_140527840());
                if (!pOther->FUN_14053d510())
                    return 0;
            }
        }
        else
        {
            CItemData* pHeadData = reinterpret_cast<CItemData*>(spHead->FUN_140527840());
            if (!pHeadData->FUN_14053d510())
                return 0;
            CItemData* pBodyData = reinterpret_cast<CItemData*>(spBody->FUN_140527840());
            if (!pBodyData->FUN_14053d510())
                return 0;
            if (!(spSecond == 0))
            {
                CItemData* pOther = reinterpret_cast<CItemData*>(spSecond->FUN_140527840());
                if (!pOther->FUN_14053d510())
                    return 0;
            }
        }
        return 1;
    }
    return 0;
}

// @0x141421690
int FUN_141421690(CItem* pItem)
{
    if (pItem != 0 && pItem->FUN_140527840() != 0)
    {
        CItemData* pData = reinterpret_cast<CItemData*>(pItem->FUN_140527840());
        return pData->FUN_14053cf00() || pData->FUN_14053d0c0() || pData->FUN_14053cfd0() || pData->FUN_14053d020()
            || pData->FUN_14053cf40();
    }
    return 0;
}
