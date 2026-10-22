// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). FittingDollSlot, the item slot of the fitting doll window
// (second of the three objects of the fittingdollslot.cpp range).
// MS2-UNIT: client\ms2\fittingdollslot.cpp#2
// MS2-RANGE: 0x14121d110-0x14121e670 .text$mn
// MS2-RANGE: 0x1400e9420-0x1400e9600 .text$di
// MS2-RANGE: 0x142cad8f0-0x142cad9a0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7FittingDollSlot@@6BBindData@NotifyContext@@@ 0x142ec3330 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fittingdollslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fittingdollslot.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
class Unk_ItemEquipData : public CItemData { };         // CItem::FUN_140527840's record
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----

// The world service singleton (FUN_1403ed2d0).
class Unk_FdWorld
{
public:
    PCBase* FUN_141bd0cc0();                                // the local player
    PC* FUN_141bd1290(int nId);                             // the actor with the object id
    PC* FUN_141bd1530(__int64 nEntityId);                   // the actor of an entity id
};
Unk_FdWorld* FUN_1403ed2d0();

// The sound service (FUN_1403ed280).
class Unk_FdSound
{
public:
    unsigned FUN_1411a5110(CString strCategory, CString strName, CString strExtra, int nKind, void* pXform, float fVolume,
        int nOwner);                                        // play a sound event
};
Unk_FdSound* FUN_1403ed280();

// A cube of the cube service (only its grid position is used here).
class Unk_FdCube
{
public:
    char m_pad_000[0x50];
    int m_n50;                                              // +0x50
    int m_n54;                                              // +0x54
};
MS2_CHECK_OFFSET(Unk_FdCube, m_n54, 0x54);

// The cube service (efd service 0x06100017): the cube of an entity and the owner of a cube column.
class Unk_FdCubeSvc
{
public:
    Unk_FdCube* FUN_1410b8c90(const egf::EntityID& kId);
    __int64 FUN_1410c8030(int x, int y);                    // the owner of the cube column
};
struct Unk_FdFramework { void* m_pad; };
extern Unk_FdFramework DAT_143b059e8;
Unk_FdCubeSvc* FUN_1401cd040(Unk_FdFramework* pFramework);

// The feature switches (FUN_140166410).
class Unk_FdFeatures
{
public:
    bool FUN_14036d570(int nFeature);                       // the feature is switched on
};
Unk_FdFeatures* FUN_140166410();

FittingDollPC* FUN_140884db0(PCBase* pObject);               // the object as a fitting doll (class 0x6200046) or 0
__int64 FUN_141656ad0(PCBase* pPlayer);                     // the account of the player
void* FUN_140a50b50(DragSlot* pSlot);                       // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                     // its item uid
void FUN_141405a60(void* pItemSlot, CItem* pItem, int nSlot);   // put the item into the slot
int FUN_141275a10(CItem* pItem);                            // the item's lock kind
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);                   // item link / popup for the item
CStringW GetStringCommon(int nStringId);                      // a string table text
CString FUN_1405451e0(int nType);                           // the name of an equip slot type
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);   // string table text with one argument
void FUN_140d73bc0(int nStringId, int nType, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);
void FUN_140710590(COutPacket& packet);                     // send the packet
void FUN_14121b840(int nResult);                            // the notice of a doll item result (fittingdollslot#1)

extern Unk_Inventory DAT_143ab2a90;

EE_IMPLEMENT_CONCRETE_CLASS_INFO(FittingDollSlot);

static CStringW s_strDestroyDollItem = L"destroy_doll_item";

// Header-defined statics (the second copy of the shared item header's statics).
#define MS2_STATICS_A_BEFORE_CONDITION <egf/EntityID.h>
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

// @0x14121d110
FittingDollSlot::FittingDollSlot(const CString& strName, int nIndex, int nPcId, unsigned __int64 nDollId, Unk_InventoryEquipSlot nSlot)
    : MS2DragSlot(strName, nIndex)
{
    m_nPcId = nPcId;
    m_nDollId = nDollId;
    m_nSlot = nSlot;
    SetEnabled(true);
}

// @0x14121d1c0
int FittingDollSlot::vfunc_13()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14121d1c0, FittingDollSlot, vfunc_13, 8, 0x7F371472);

// @0x14121d1d0
int FittingDollSlot::vfunc_14()
{
    return FUN_14121ddc0();
}
MS2_REPLACE_METHOD(0x14121d1d0, FittingDollSlot, vfunc_14, 24, 0x34369C48);

// @0x14121d1f0
int FittingDollSlot::vfunc_15()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_140d2cfc0(spItem);
    return DragSlot::vfunc_15();
}
MS2_REPLACE_METHOD(0x14121d1f0, FittingDollSlot, vfunc_15, 131, 0x2FF59A43);

// @0x14121d280
int FittingDollSlot::vfunc_18(void* p)
{
    DragSlot* pDrag = static_cast<DragSlot*>(p);
    void* pItemSlot = FUN_140a50b50(pDrag);
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem.get() != 0)
            FUN_141405a60(pItemSlot, spItem.get(), m_nSlot);
    }
    return pDrag->vfunc_10();
}

// @0x14121d330
int FittingDollSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x14121d330, FittingDollSlot, vfunc_20, 360, 0x8C0A70F5);

// @0x14121d4a0
int FittingDollSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x14121d4a0, FittingDollSlot, vfunc_21, 360, 0x889F2550);

// @0x14121d610 (ITooltip::vfunc_0)
int FittingDollSlot::vfunc_0(void* p)
{
    PC* pPlayer = FUN_14121dd90();
    if (pPlayer == 0)
        return 0;
    CItem* pItem = vfunc_25().get();
    if (pItem == 0)
        return 0;
    int nFlags = 0x100;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == pPlayer)
        nFlags = 0x200;
    ASTooltip tip(pPlayer, nFlags, 2);
    if (tip.FUN_1409e0d40(pItem) == 0)
        return 0;
    tip.FUN_1409c69b0(GetStringCommon(0x75c));
    if (IsEnabled() == true)
        tip.FUN_1409db7b0(MS2Ptr<CItem>(pItem));
    *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return 1;
}

// @0x14121d810
int FittingDollSlot::vfunc_8(void* p)
{
    PC* pPlayer = FUN_14121dd90();
    if (pPlayer == 0)
        return 0;
    FittingDollPC* pDoll = FUN_14121dd50();
    if (pDoll == 0)
        return 0;
    PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal == 0)
        return 0;
    CItem* pItem = vfunc_25().get();
    if (pItem == 0)
        return 0;
    Unk_FdCubeSvc* pSvc = FUN_1401cd040(&DAT_143b059e8);
    egf::EntityID kId;
    Unk_FdCube* pCube = pSvc->FUN_1410b8c90(pDoll->FUN_14123c460(kId));
    if (pCube == 0)
        return 0;
    __int64 nOwner = pSvc->FUN_1410c8030(pCube->m_n50, pCube->m_n54);
    __int64 nLocalOwner = FUN_141656ad0(pLocal);
    ASSlot slot(2);
    if (slot.FUN_1409c41f0(pItem, pPlayer, m_nSlot, 0x49) == 0)
        return 0;
    if (nOwner == nLocalOwner)
    {
        int nLock = FUN_141275a10(vfunc_25().get());
        if (nLock == 1)
            slot.FUN_1409c1e80(1);
        else if (nLock == 2)
            slot.FUN_1409c2710(1);
        else if (nLock == 3)
            slot.FUN_1409c1ec0(1);
    }
    if (m_nSlot == 4)
    {
        if (pItem->FUN_140527840()->FUN_14053d460() != false)
        {
            slot.FUN_1409c2090(1);
            goto LAB_gray_done;
        }
    }
    if (m_nSlot == 9)
    {
        if (pItem->FUN_140527840()->FUN_14053d2b0() != false)
            slot.FUN_1409c2090(1);
    }
LAB_gray_done:
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x14121db80
MS2Ptr<CItem> FittingDollSlot::vfunc_25()
{
    FittingDollPC* pDoll = FUN_14121dd50();
    if (pDoll == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CEquipItem> spEquip = pDoll->FUN_141655e80(m_nSlot, pDoll->FUN_14121c710() != 0);
    if (spEquip == 0)
        return MS2Ptr<CItem>(0);
    return ((CEquipItem*)spEquip)->GetItem();
}

// @0x14121dc90
void FittingDollSlot::vfunc_9()
{
    if (FUN_1409b0350(&m_value18) == 0)
    {
        ASObj obj(m_value18, 2);
        if (obj.FUN_1422ba9a0() == 0)
            obj.FUN_1407cba60("m_strSlotType", FUN_1405451e0(m_nSlot));
    }
}
MS2_REPLACE_METHOD(0x14121dc90, FittingDollSlot, vfunc_9, 177, 0x60A25617);

// @0x14121dd50
FittingDollPC* FittingDollSlot::FUN_14121dd50()
{
    return FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(m_nDollId));
}
MS2_REPLACE_METHOD(0x14121dd50, FittingDollSlot, FUN_14121dd50, 47, 0x50AAF435);

// @0x14121dd90
PC* FittingDollSlot::FUN_14121dd90()
{
    return FUN_1403ed2d0()->FUN_141bd1290(m_nPcId);
}
MS2_REPLACE_METHOD(0x14121dd90, FittingDollSlot, FUN_14121dd90, 38, 0xA1936EAD);

// @0x14121ddc0
// Destroy the doll item of the slot: a confirm box when the item has a reason to keep (or the packet at once).
int FittingDollSlot::FUN_14121ddc0()
{
    PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal == 0)
        return 0;
    FittingDollPC* pDoll = FUN_14121dd50();
    if (pDoll == 0)
        return 0;
    Unk_FdCubeSvc* pSvc = FUN_1401cd040(&DAT_143b059e8);
    Unk_FdCube* pCube = pSvc->FUN_1410b8c90(pDoll->FUN_14123c460());
    if (pCube == 0)
        return 0;
    __int64 nOwner = pSvc->FUN_1410c8030(pCube->m_n50, pCube->m_n54);
    if (nOwner != FUN_141656ad0(pLocal))
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (!spItem)
        return 0;
    if (FUN_140166410()->FUN_14036d570(0xd4))
    {
        CStringW strName;
        int nReason;
        if (DAT_143ab2a90.FUN_140a66200(spItem.get(), &nReason, strName) == 0)
        {
            CStringW strText;
            if (nReason == 2)
                FUN_140d73bc0(0xdc, 0, 0, CStringW(L""));
            else if (nReason == 3)
                FUN_140d73bc0(0xfc, 0, 0, CStringW(L""));
            else if (nReason == 4)
                strText = FUN_14052bd00(0xdb, strName);
            else if (nReason == 5)
                strText = FUN_14052bd00(0xde, strName);
            else
                MS2_ASSERT_AT(0xfe, 0);
            if (!strText.IsEmpty())
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strText, 0, s_strDestroyDollItem);
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a01600(((CItem*)spItem)->FUN_140526a50());
                    spBox->FUN_141a01ee0(spItem, ((CItem*)spItem)->FUN_140527b10(), 1, ((CItem*)spItem)->FUN_140526c50(), -1, -1, 1);
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a026f0(1);
                    spBox->FUN_141a024e0(GetStringCommon(0x9d1), 0);
                    FUN_140d73c60(spBox);
                }
            }
            return 0;
        }
    }
    int nResult = pDoll->FUN_14121c9d0(spItem.get());
    if (nResult == 0)
    {
        COutPacket packet(0x42, 0);
        packet.vfunc_o10_1(7);
        packet.vfunc_o10_4(m_nDollId);
        packet.vfunc_o10_1((char)m_nSlot);
        FUN_140710590(packet);
    }
    else
    {
        FUN_14121b840(nResult);
    }
    return nResult == 0;
}
