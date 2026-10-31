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

class AvatarPC;

// 16-byte smart pointer handles (item pointer / equipped-item handle).
class Unk_CustomizeHandle
{
public:
    ~Unk_CustomizeHandle();                                       // 0x1405a85f0
    void* FUN_1405a8e70() const;                                  // get
    void* FUN_1405a8ed0() const;                                  // get
private:
    void* m_pad;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_CustomizeHandle, 0x10);
class Unk_CustomizeCopy
{
public:
    ~Unk_CustomizeCopy();                                         // 0x1401bfde0
    CItem* FUN_1401c0180();                                       // 0x1401c0180 operator->
private:
    void* m_pad;
    void* m_p;
};

// Unrecovered callees.
// the item's data record smart pointer
class Unk_CustomizeItemPtr
{
public:
    Unk_CustomizeItemPtr(void* pData);                            // 0x1401bf970
    ~Unk_CustomizeItemPtr();                                      // 0x1401b50d0
    bool FUN_1402ffd90() const;                                   // 0x1402ffd90 is it null
    void* FUN_140203c60() const;                                  // 0x140203c60 get
private:
    void* m_pad;
    void* m_p;
};
// The avatar's equip-slot getters return a handle by value (rcx = avatar, rdx = result, r8d = slot).
struct Unk_CzAvatarView
{
    Unk_CustomizeHandle FUN_141655e10(int nSlot);
    Unk_CustomizeHandle FUN_141655c90(int nSlot);
    Unk_CustomizeHandle FUN_141655cf0(int nSlot);
};
// The equipped item returns a copy of its item pointer by value.
struct Unk_CzEquipView { Unk_CustomizeCopy FUN_1411dc7a0(); };
bool FUN_1409edd90(void* pHandle, int n);                         // 0x1409edd90
void* FUN_1411dc7f0(void* pEquip);                                // 0x1411dc7f0
CFeatureManager* FUN_140166410();

int FUN_141420b30(CItemData* pData, AvatarPC* pAvatar);

// @0x141420a70
int FUN_141420a70(CItem* pItem, AvatarPC* pAvatar)
{
    if (pItem == 0 || pAvatar == 0)
        return 0;
    Unk_CustomizeItemPtr sp(pItem->FUN_140527840());
    if (sp.FUN_1402ffd90())
        return 0;
    int nId = FUN_141420b30((CItemData*)sp.FUN_140203c60(), pAvatar);
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
        if (pData->FUN_14053cf90())
        {
            Unk_CustomizeHandle a4 = reinterpret_cast<Unk_CzAvatarView*>(pAvatar)->FUN_141655c90(4);
            Unk_CustomizeHandle a5 = reinterpret_cast<Unk_CzAvatarView*>(pAvatar)->FUN_141655c90(5);
            if ((bool)a5.FUN_1405a8e70() && (bool)a4.FUN_1405a8e70())
            {
                Unk_CustomizeHandle b4 = reinterpret_cast<Unk_CzAvatarView*>(pAvatar)->FUN_141655cf0(4);
                Unk_CustomizeHandle b5 = reinterpret_cast<Unk_CzAvatarView*>(pAvatar)->FUN_141655cf0(5);
                if (FUN_1409edd90(&b5, 0))
                    nResult = 5;
                else if (FUN_1409edd90(&b4, 0))
                    nResult = 4;
                else
                    nResult = 5;
            }
            else if (a5.FUN_1405a8e70())
            {
                nResult = 5;
            }
            else if (a4.FUN_1405a8e70())
            {
                nResult = 4;
            }
        }
        else
        {
            Unk_CustomizeHandle h4 = reinterpret_cast<Unk_CzAvatarView*>(pAvatar)->FUN_141655e10(4);
            Unk_CustomizeHandle h5 = reinterpret_cast<Unk_CzAvatarView*>(pAvatar)->FUN_141655e10(5);
            if (h5.FUN_1405a8e70())
            {
                if (reinterpret_cast<CItemData*>(FUN_1411dc7f0(h5.FUN_1405a8ed0()))->FUN_14053d460())
                {
                    nResult = 5;
                }
                else if (h4.FUN_1405a8e70())
                {
                    nResult = 5;
                    if (FUN_140166410()->FUN_14036d570(0xda))
                    {
                        if (reinterpret_cast<Unk_CzEquipView*>(h5.FUN_1405a8ed0())->FUN_1411dc7a0().FUN_1401c0180()->FUN_140529070()
                            > reinterpret_cast<Unk_CzEquipView*>(h4.FUN_1405a8ed0())->FUN_1411dc7a0().FUN_1401c0180()->FUN_140529070())
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
