// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). FittingDollSlot, the item slot of the fitting doll window
// (second of the three objects of the fittingdollslot.cpp range).
// MS2-UNIT: client\ms2\fittingdollslot.cpp#2
// MS2-RANGE: 0x14121d110-0x14121e670 .text$mn
// MS2-RANGE: 0x1400e9420-0x1400e9600 .text$di
// MS2-RANGE: 0x142cad8f0-0x142cad9a0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7FittingDollSlot@@6BBindData@NotifyContext@@@ 0x142ec3330 ; hand: primary vftable
// MS2-PIN: ??__E?ms_ClassInfo@FittingDollSlot@@2VClassInfo@efd@@B@@YAXXZ 0x1400e9420 ; initpin: a header's look-alike initializer must not make these ambiguous
// MS2-PIN: ??__Es_strDestroyDollItem@@YAXXZ 0x1400e9440
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1400e9470
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e9530
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e9560
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400e9590
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400e95b0
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
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
class Unk_ItemEquipData : public CItemData { };         // CItem::FUN_140527840's record
#include <efd/MemHint.h>
#include <egf/ScriptContext.h>   // C3: egf::g_bapiContext
#include <efd/MemObject.h>

// ---- out-of-unit callees ----

// The world service singleton (FUN_1403ed2d0).
class Unk_FdWorld
{
public:
    PCBase* FUN_141bd0cc0();                                // the local player
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    class Unk_WsC_GameObj* FUN_141bd1290(int id);   // C3: the real member (0x141bd1290, an object by id)
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    class Unk_WsC_GameObj* FUN_141bd1530(__int64 id);   // C3: the real member (0x141bd1530, the actor of an entity id)
    static class WorldService* GetInstance();
};

// The effect service (TSingleton<CEffectService>, as effectservice.h declares it): plays the item sound.
class NiTransform;
class CEffectService;
template <> class TSingleton<CEffectService>
{
public:
    static CEffectService* GetInstance() { return s_instance; }     // 0x1403ed280 (COMDAT of another unit)
    static CEffectService* s_instance;              // 0x143aaee08
};
class CEffectService
{
public:
    unsigned FUN_1411a5110(CString strCategory, CString strName, CString strExtra, int nKind, NiTransform* pXform,
        float fVolume, int nOwner);                             // play a sound event
};

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
class Unk_FdCubeSvc : public CubeMapInformationService
{
public:
    // C3: FUN_1410b8c90 is CubeMapInformationService's own (returns Cube*)
};
class CubeMapInformationService* FUN_1401cd040(struct Unk_EntityAppFramework*);   // C3: was FUN_1401cd040

// The feature switches (FUN_140166410).
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

class MyPC* FUN_140884db0(class Unk_QueryObj*);   // C3: was FUN_140884db0
namespace NotifyContext { class BindData; }
class MS2DragSlot;
MS2DragSlot* FUN_140a50b50(NotifyContext::BindData* p);   // C3: the real def (displayslot.cpp), TypeCast(0x6200023)
class InvenSlot   // C3: member view for the former free stand-ins
{
public:
    __int64 GetItemUid();
public:
    int FUN_141405a60(class CItem*, int);   // C3: was free FUN_141405a60
};
int FUN_141275a10(CItem* pItem);                            // the item's lock kind
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);                   // item link / popup for the item
CStringW GetStringCommon(int nStringId);                      // a string table text
CString FUN_1405451e0(int nType);                           // the name of an equip slot type
template <class A> CStringW FormatStringId(int nId, const A& a);
void FUN_140d73bc0(int nStringId, int nType, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140710590(COutPacket& packet);                     // send the packet
void FUN_14121b840(int nResult);                            // the notice of a doll item result (fittingdollslot#1)

extern Unk_Inventory g_143ab2a90;

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
    void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(((class InvenSlot*)(void*)(pItemSlot))->GetItemUid());
        if (spItem.get() != 0)
            ((class InvenSlot*)(void*)(pItemSlot))->FUN_141405a60(spItem.get(), m_nSlot);
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x14121d330
int FittingDollSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->GetMaterialSoundName(), CString(""), 0, 0, 1.0f, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x14121d330, FittingDollSlot, vfunc_20, 360, 0x8C0A70F5);

// @0x14121d4a0
int FittingDollSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/item"),
            ((CItem*)spItem)->FUN_140527840()->GetMaterialSoundName(), CString(""), 0, 0, 1.0f, 0);
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
    if (((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()) == pPlayer)
        nFlags = 0x200;
    ASTooltip tip(pPlayer, nFlags, 2);
    if (tip.FUN_1409e0d40(pItem) != 0)
    {
        tip.SetEnablePuton(GetStringCommon(0x75c));
        if (IsEnabled() == true)
            tip.FUN_1409db7b0(MS2Ptr<CItem>(pItem));
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
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
    PCBase* pLocal = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pLocal == 0)
        return 0;
    CItem* pItem = vfunc_25().get();
    if (pItem == 0)
        return 0;
    Unk_FdCubeSvc* pSvc = ((class Unk_FdCubeSvc*)FUN_1401cd040((struct Unk_EntityAppFramework*)(&egf::g_bapiContext)));
    Unk_FdCube* pCube = reinterpret_cast<Unk_FdCube*>(pSvc->FUN_1410b8c90(pDoll->FUN_14123c460()));
    if (pCube == 0)
        return 0;
    int bOwner = pSvc->GetOwnerId(pCube->m_n50, pCube->m_n54) == ((class PC*)(class PCBase*)(pLocal))->FUN_141656ad0();
    ASSlot slot(2);
    if (slot.FUN_1409c41f0(pItem, pPlayer, m_nSlot, 0x49))
    {
        if (bOwner)
        {
            int nLock = FUN_141275a10(vfunc_25().get());
            if (nLock == 1)
                slot.SetItemLock(1);
            else if (nLock == 2)
                slot.SetDisable(1);
            else if (nLock == 3)
                slot.SetItemConditionLock(1);
        }
        if (m_nSlot == 4 && pItem->FUN_140527840()->FUN_14053d460() != false)
            slot.SetGrayColor(1);
        else if (m_nSlot == 9 && pItem->FUN_140527840()->FUN_14053d2b0() != false)
            slot.SetGrayColor(1);
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x14121db80
MS2Ptr<CItem> FittingDollSlot::vfunc_25()
{
    FittingDollPC* pDoll = FUN_14121dd50();
    if (pDoll == 0)
        return MS2Ptr<CItem>(0);
    int nKind = 0;
    if (pDoll->FUN_14121c710() != 0)
        nKind = 1;
    MS2Ptr<CEquipItem> spEquip = pDoll->GetEquipBySlotKind(m_nSlot, nKind);
    if (spEquip == 0)
        return MS2Ptr<CItem>(0);
    return ((CEquipItem*)spEquip)->GetItem();
}

// @0x14121dc90
void FittingDollSlot::vfunc_9()
{
    if (((Scaleform::GFx::Value*)(void*)(&m_value18))->IsNull() == 0)
    {
        ASObj obj(m_value18, 2);
        if (obj.IsUndefinedOrNull() == 0)
            obj.FUN_1407cba60("m_strSlotType", FUN_1405451e0(m_nSlot));
    }
}
MS2_REPLACE_METHOD(0x14121dc90, FittingDollSlot, vfunc_9, 177, 0x60A25617);

// @0x14121dd50
FittingDollPC* FittingDollSlot::FUN_14121dd50()
{
    return ((class FittingDollPC*)FUN_140884db0((class Unk_QueryObj*)(reinterpret_cast<PC*>(WorldService::GetInstance()->FUN_141bd1530(m_nDollId)))));
}
MS2_REPLACE_METHOD(0x14121dd50, FittingDollSlot, FUN_14121dd50, 47, 0x50AAF435);

// @0x14121dd90
PC* FittingDollSlot::FUN_14121dd90()
{
    return reinterpret_cast<PC*>(WorldService::GetInstance()->FUN_141bd1290(m_nPcId));
}
MS2_REPLACE_METHOD(0x14121dd90, FittingDollSlot, FUN_14121dd90, 38, 0xA1936EAD);

// @0x14121ddc0
// Destroy the doll item of the slot: a confirm box when the item has a reason to keep (or the packet at once).
int FittingDollSlot::FUN_14121ddc0()
{
    PCBase* pLocal = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pLocal == 0)
        return 0;
    FittingDollPC* pDoll = FUN_14121dd50();
    if (pDoll == 0)
        return 0;
    Unk_FdCubeSvc* pSvc = ((class Unk_FdCubeSvc*)FUN_1401cd040((struct Unk_EntityAppFramework*)(&egf::g_bapiContext)));
    Unk_FdCube* pCube = reinterpret_cast<Unk_FdCube*>(pSvc->FUN_1410b8c90(pDoll->FUN_14123c460()));
    if (pCube == 0)
        return 0;
    if (pSvc->GetOwnerId(pCube->m_n50, pCube->m_n54) != ((class PC*)(class PCBase*)(pLocal))->FUN_141656ad0())
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (!spItem)
        return 0;
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xd4))
    {
        CStringW strName;
        int nReason;
        if (g_143ab2a90.FUN_140a66200(spItem.get(), &nReason, strName) == 0)
        {
            CStringW strText;
            switch (nReason)
            {
            case 3:
                FUN_140d73bc0(0xfc, 0, 0, CStringW(L""));
                break;
            case 2:
                FUN_140d73bc0(0xdc, 0, 0, CStringW(L""));
                break;
            case 4:
                strText = FormatStringId<CStringW>(0xdb, strName);
                break;
            case 5:
                strText = FormatStringId<CStringW>(0xde, strName);
                break;
            default:
                MS2_ASSERT_AT(0xfe, 0);
                break;
            }
            if (!strText.IsEmpty())
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strText, 0, s_strDestroyDollItem);
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a01600(((CItem*)spItem)->GetItemUid());
                    spBox->FUN_141a01ee0(spItem, ((CItem*)spItem)->FUN_140527b10(), 1, ((CItem*)spItem)->GetCount(), -1, -1, 1);
                    spBox->FUN_141a01800(1);
                    spBox->SetCheckboxMust(1);
                    spBox->SetCheckbox0(GetStringCommon(0x9d1), 0);
                    FUN_140d73c60(spBox);
                }
            }
            return 0;
        }
    }
    int nResult = pDoll->FUN_14121c9d0(spItem.get());
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::FittingDoll), 0);
        packet.WriteUInt8(7);
        packet.WriteInt64(m_nDollId);
        packet.WriteUInt8((char)m_nSlot);
        FUN_140710590(packet);
    }
    else
    {
        FUN_14121b840(nResult);
    }
    return nResult == 0;
}
