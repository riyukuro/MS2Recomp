// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Avatar customize id helpers (the first half of
// unit_141420f10's file): the customize id of a CItem on an avatar, and the one of a data record (which
// of the two equipped slots 4/5 the item belongs to).
// MS2-UNIT: unit_141420a70
// MS2-RANGE: 0x141420a70-0x141420f10 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\avatarcustomize.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/equipitem.h"

class AvatarPC;

class Unk_140166410;
Unk_140166410* FUN_140166410();

int FUN_141420b30(CItemData* pData, AvatarPC* pAvatar);

// @0x141420a70
int FUN_141420a70(CItem* pItem, AvatarPC* pAvatar)
{
    if (pItem == 0 || pAvatar == 0)
        return 0;
    MS2Ptr<CItemData> sp(reinterpret_cast<CItemData*>(pItem->FUN_140527840()));
    if (sp.IsNull())
        return 0;
    int nId = FUN_141420b30(sp, pAvatar);
    if (nId == 0)
        nId = pItem->FUN_140526c30();
    return nId;
}

// @0x141420b30
int FUN_141420b30(CItemData* pData, AvatarPC* pAvatar)
{
    if (pData == 0 || pAvatar == 0)
        return 0;
    if (pData->FUN_14053d2f0() == 0)
        return 0;
    int nResult = 0;
    if (pData->FUN_14053d460())
    {
        nResult = 5;
    }
    else if (pData->FUN_14053d510())
    {
        if (pData->HasSkinType())
        {
            MS2Ptr<CEquipItem> a4 = reinterpret_cast<PC*>(pAvatar)->FUN_141655c90(4);
            MS2Ptr<CEquipItem> a5 = reinterpret_cast<PC*>(pAvatar)->FUN_141655c90(5);
            if ((bool)(CEquipItem*)a5 && (bool)(CEquipItem*)a4)
            {
                MS2Ptr<CEquipItem> b4 = reinterpret_cast<PC*>(pAvatar)->FUN_141655cf0(4);
                MS2Ptr<CEquipItem> b5 = reinterpret_cast<PC*>(pAvatar)->FUN_141655cf0(5);
                if (b5 == 0)
                    nResult = 5;
                else if (b4 == 0)
                    nResult = 4;
                else
                    nResult = 5;
            }
            else if ((CEquipItem*)a5)
            {
                nResult = 5;
            }
            else if ((CEquipItem*)a4)
            {
                nResult = 4;
            }
        }
        else
        {
            MS2Ptr<CEquipItem> h4 = reinterpret_cast<PC*>(pAvatar)->FUN_141655e10(4);
            MS2Ptr<CEquipItem> h5 = reinterpret_cast<PC*>(pAvatar)->FUN_141655e10(5);
            if ((CEquipItem*)h5)
            {
                if (reinterpret_cast<CItemData*>(((void*)h5->FUN_1411dc7f0()))->FUN_14053d460())
                {
                    nResult = 5;
                }
                else if ((CEquipItem*)h4)
                {
                    nResult = 5;
                    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xda))
                    {
                        if (h5->GetItem()->FUN_140529070()
                            > h4->GetItem()->FUN_140529070())
                            nResult = 4;
                    }
                }
                else
                {
                    nResult = 4;
                }
            }
            else
            {
                nResult = 5;
            }
        }
    }
    return nResult;
}
