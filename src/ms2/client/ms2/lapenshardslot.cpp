// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). LapenshardSlot (the lapenshard slots of the lapenshard system
// window and the quick bar).
// MS2-UNIT: ?\lapenshardslot.cpp
// MS2-RANGE: 0x140a6e830-0x140a702f0 .text$mn
// MS2-RANGE: 0x1400c45a0-0x1400c4760 .text$di
// MS2-PIN: ??_7LapenshardSlot@@6BBindData@NotifyContext@@@ 0x142dcb770 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\lapenshardslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "lapenshardslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "hook/ms2hook.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/itemlapensharddata.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#ifdef __clang__
// vfunc_25 passes the address of the temporary CStringW from vfunc_77 (an MSVC extension).
#pragma clang diagnostic ignored "-Waddress-of-temporary"
#endif

// ---- out-of-unit callees ----
class Unk_ItemEquipData : public CItemData { };         // CItem::FUN_140527840's record
class Unk_ItemOwnerRef : public CItemTransfer {};       // CItem::FUN_140527930's record

// The lapenshard system window (unit_140c5d230.h): only the calls the slot makes.
class UILapenshardSystemDialog : public UIDialog
{
public:
    void FUN_140c62490(int nSlot);                      // select a slot, notify 10
    void FUN_140c624d0();                               // notify 11
};
int FUN_140c62520();                                    // the window may be used (not in battle / disabled field)

// The item table (GetLapenshardTable).
class Unk_LsItemTable : public CItemLapenshardTable
{
public:
    int FUN_1405b5810(int nSlot);                       // the kind of a free slot
    int FUN_1405b5890(int nItemId);                     // the kind of an item
};
class Unk_SlotLapenTable* GetLapenshardTable();   // C3: was GetLapenshardTable

// The quick slot manager (FUN_1409331f0; unit-local view of CKeyTable, ckeytable.h).
class CKeyTable
{
public:
    int FUN_140a700b0();                          // the current page
    unsigned char m_pad[0x198];
    int m_nPage;                                        // +0x198
};
class Unk_SoundSink* FUN_1409331f0();   // C3: was FUN_1409331f0

// The equip request of the packet 0xad (ctor 0x140a6ffe0).
struct Unk_LsEquipRequest
{
    int m_nSlot;                                        // +0x00
    __int64 m_nItemUid;                                 // +0x08
    int m_n10;                                          // +0x10
    Unk_LsEquipRequest();                               // 0x140a6ffe0
};

int FUN_14092fac0(int, int, __int64, int);   // C3: was FUN_14092fac0
void PlayItemSoundByUid(__int64 nItemUid);
void FUN_140710590(COutPacket& packet);                 // send
CStringW GetStringCommonByKey(const CStringW& strKey);         // string table text
CStringW GetStringCommon(int nStringId);                  // string table text by id
void FUN_1412751f0(const CStringW& strText, int a, int b);   // a system notice
void FUN_140d73bc0(int nNoticeId, int a, void* pListener, CStringW str);

// Registry of named bags/slots (GFx bind data).

LapenshardSlot* FUN_140a6fea0(NotifyContext::BindData* p);
LapenshardSlot* FUN_140a6fef0(DragSlot* p);
UILapenshardSystemDialog* FUN_140a6ff40(int nId);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(LapenshardSlot);

static CString s_strItemCount = "itemCount";

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70
#include "ms2/commonfiles/itemlapensharddata.h"   // C3: Unk_LapenEquip::Write

// @0x140a6e830
LapenshardSlot::LapenshardSlot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem, int nSlot, int nKind)
    : MS2DragSlot(strName, nIndex), m_spItem(spItem), m_nSlot(nSlot), m_nKind(nKind)
{
}

// @0x140a6e8e0
void CreateLapenshardSlot(const CString& strName, MS2Ptr<CItem> spItem, int nKind)
{
    LapenshardSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) LapenshardSlot(strName, 0, spItem, 0, nKind);
    if (pSlot)
        Unk_NotifyContext::FUN_1422c8f10(strName, pSlot);
}

// @0x140a6e9e0
void RemoveLapenshardSlot(const CString& strName)
{
    LapenshardSlot* pSlot = FUN_140a6fea0(Unk_NotifyContext::FUN_1422c8e90(strName));
    if (pSlot)
        Unk_NotifyContext::FUN_1422c8f70(strName);
}

// @0x140a6ea20
int LapenshardSlot::vfunc_17()
{
    return vfunc_10();
}

// @0x140a6ea50
int LapenshardSlot::vfunc_18(void* p)
{
    MyPC* pPc = (MyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    LapenshardSlot* pFromSlot = FUN_140a6fef0(static_cast<DragSlot*>(p));
    if (pFromSlot == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    if (pFromSlot->GetSlot() != 0)
        return pFromSlot->vfunc_10();
    if (GetSlot() == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    if (FUN_140a6f880() != pFromSlot->FUN_140a6f880())
    {
        FUN_140d73bc0(0xd3, 0, 0, CStringW(L""));
        return static_cast<DragSlot*>(p)->vfunc_10();
    }
    MS2Ptr<CItem> spItem = pFromSlot->vfunc_25();
    if (spItem == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    if (spItem->GetRequiredLevel() > (unsigned short)pPc->vfunc_78())
        return static_cast<DragSlot*>(p)->vfunc_10();
    int nItemId = spItem->FUN_1405276c0();
    int nCurrent = pPc->GetLapenshardItemId((Unk_MyPCLapenSlot)GetSlot());
    if (pPc->HasEquippedLapenshardOfSameGroup(nItemId) != 0)
    {
        int nCurrentGroup = ((class Unk_LsItemTable*)GetLapenshardTable())->GetGroup(nCurrent);
        int nGroup = ((class Unk_LsItemTable*)GetLapenshardTable())->GetGroup(nItemId);
        if (nCurrentGroup == 0 || nCurrentGroup != nGroup || nItemId == nCurrent)
        {
            FUN_1412751f0(GetStringCommonByKey(L"s_msg_shortcutkey_invalid_already_same_lapenshard"), 1, 1);
            return static_cast<DragSlot*>(p)->vfunc_10();
        }
    }
    SendLapenshard(GetSlot(), spItem->GetItemUid());
    PlayItemSoundByUid(spItem->GetItemUid());
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140a6ee30
int LapenshardSlot::vfunc_14()
{
    MyPC* pPc = (MyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem == 0)
        return 0;
    if (GetSlot() == 0)
    {
        int nKind = FUN_140a6f880();
        int nSlot = pPc->FindLapenSlotForItem(nKind);
        if (nSlot == 0)
            return 0;
        int nItemId = spItem->FUN_1405276c0();
        int nCurrent = pPc->GetLapenshardItemId((Unk_MyPCLapenSlot)nSlot);
        if (pPc->HasEquippedLapenshardOfSameGroup(nItemId) != 0)
        {
            int nGroup = ((class Unk_LsItemTable*)GetLapenshardTable())->GetGroup(nItemId);
            int nCurrentGroup = ((class Unk_LsItemTable*)GetLapenshardTable())->GetGroup(nCurrent);
            if (nCurrentGroup == 0 || nCurrentGroup != nGroup || nItemId == nCurrent)
            {
                FUN_1412751f0(GetStringCommonByKey(L"s_msg_shortcutkey_invalid_already_same_lapenshard"), 1, 1);
                return 0;
            }
        }
        SendLapenshard(nSlot, spItem->GetItemUid());
    }
    else
    {
        if (FUN_140a6f880() != 1)
        {
            FUN_1412751f0(GetStringCommonByKey(L"s_msg_shortcutkey_invalid_lapenshard"), 1, 1);
            return 0;
        }
        if (pPc->FUN_14152f860(spItem->FUN_1405276c0()) == 0)
            return 0;
        int nPage = ((class CKeyTable*)FUN_1409331f0())->FUN_140a700b0();
        FUN_14092fac0(spItem->FUN_140527840()->FUN_14053dc20(), 0, 0, nPage);
    }
    PlayItemSoundByUid(spItem->GetItemUid());
    return 1;
}

// @0x140a6f1b0
int LapenshardSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/item"),
            spItem->FUN_140527840()->GetMaterialSoundName(), CString(""), 0, 0, 1.0f, 0);
    if (GetSlot() == 0)
    {
        int nKind = FUN_140a6f880();
        if (nKind == 0)
            return 1;
        UILapenshardSystemDialog* pDialog = FUN_140a6ff40(0x4f6d);
        if (pDialog != 0)
            pDialog->FUN_140c62490(nKind);
    }
    return 1;
}

// @0x140a6f390
int LapenshardSlot::vfunc_21()
{
    DragSlot::vfunc_21();
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/item"),
            spItem->FUN_140527840()->GetMaterialSoundName(), CString(""), 0, 0, 1.0f, 0);
    if (GetSlot() == 0)
    {
        int nKind = FUN_140a6f880();
        if (nKind == 0)
            return 1;
        UILapenshardSystemDialog* pDialog = FUN_140a6ff40(0x4f6d);
        if (pDialog != 0)
            pDialog->FUN_140c624d0();
    }
    return 1;
}

// @0x140a6f570
CStringW LapenshardSlot::vfunc_22()
{
    if (GetSlot() != 0)
    {
        if (FUN_140a6f880() == 1)
            return GetStringCommon(0x75a);
        return CStringW();
    }
    return GetStringCommon(0x751);
}

// @0x140a6f610
MS2Ptr<CItem> LapenshardSlot::vfunc_25()
{
    if (GetSlot() != 0)
    {
        MyPC* pPc = (MyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
        if (pPc == 0)
            return MS2Ptr<CItem>(0);
        int nItemId = pPc->GetLapenshardItemId((Unk_MyPCLapenSlot)GetSlot());
        if (nItemId == 0)
            return MS2Ptr<CItem>(0);
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(nItemId, 0, 0) == 0)
            return MS2Ptr<CItem>(0);
        if (spItem->FUN_140527930()->GetType() == 2)
        {
            __int64 nKey = pPc->FUN_141656a80();
            spItem->BindToCharacter(nKey, pPc->vfunc_77());
        }
        return spItem;
    }
    return m_spItem;
}

// @0x140a6f860
int LapenshardSlot::GetSlot()
{
    return m_nSlot;
}

// @0x140a6f880
int LapenshardSlot::FUN_140a6f880()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        return ((int)((class CItemLapenshardTable*)(((class Unk_LsItemTable*)GetLapenshardTable())))->GetEquipMask(spItem->FUN_1405276c0()));
    return ((int)((class CItemLapenshardTable*)(((class Unk_LsItemTable*)GetLapenshardTable())))->GetEquipPart((enum CItemLapenshardTable::Slot)(GetSlot())));
}

// @0x140a6f940
void LapenshardSlot::SendLapenshard(int nSlot, __int64 nItemUid)
{
    if (FUN_140c62520() == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Lapenshard), 0);
    packet.Encode1(1);
    Unk_LsEquipRequest request;
    request.m_nSlot = nSlot;
    request.m_nItemUid = nItemUid;
    reinterpret_cast<Unk_LapenEquip*>(&request)->Write(&packet);   // C3: 0x1405b5cc0
    FUN_140710590(packet);
}

// @0x140a6f9e0 (ITooltip::vfunc_0)
int LapenshardSlot::vfunc_0(void* p)
{
    MyPC* pPc = (MyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem == 0)
        return 0;
    int nFlags = 0x20;
    int nGrade = spItem->GetRarity();
    if (m_nSlot != 0)
        spItem->FUN_140526bf0(spItem->FUN_140527840()->GetRank());
    int nResult = 0;
    ASTooltip tip(pPc, nFlags, 2);
    if (tip.FUN_1409e0d40(spItem))
    {
        tip.SetEnablePuton(vfunc_22());
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        nResult = 1;
    }
    spItem->FUN_140526bf0(nGrade);
    return nResult;
}

// @0x140a6fc00
int LapenshardSlot::vfunc_8(void* p)
{
    MyPC* pPc = (MyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    unsigned nFlags = 0x49;
    if (GetSlot() == 0)
    {
        nFlags |= 0x24;
        if (m_nKind == 0)
            nFlags |= 0x400;
    }
    else
    {
        if (FUN_140a6f880() != 1)
            nFlags |= 0x400;
        nFlags |= 0x2000;
    }
    ASSlot slot(2);
    if ((spItem.get() != 0 ? true : false) && spItem->IsLapenshard() != 0)
    {
        int nOk = slot.FUN_1409c3860(vfunc_25().get(), pPc, nFlags);
        if (nOk != 0)
        {
            if (GetSlot() == 0)
            {
                slot.SetMemberUInt(s_strItemCount, spItem->GetCount());
                if (spItem->GetCount() == 0)
                    slot.SetDisable(1);
                if (spItem->FUN_14052a290(2))
                    slot.SetItemSeal(1);
                if (spItem->FUN_1405291f0() != 0)
                    slot.SetItemEquip(1);
            }
            else
            {
                slot.SetItemGrade(0);
            }
        }
    }
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x140a6fea0
LapenshardSlot* FUN_140a6fea0(NotifyContext::BindData* p)
{
    LapenshardSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200083, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140a6fef0
LapenshardSlot* FUN_140a6fef0(DragSlot* p)
{
    LapenshardSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200083, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140a6ff40
UILapenshardSystemDialog* FUN_140a6ff40(int nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FindObject((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<UILapenshardSystemDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140a6ffe0
Unk_LsEquipRequest::Unk_LsEquipRequest()
{
    m_nSlot = 0;
    m_nItemUid = 0;
    m_n10 = 0;
}


// @0x140a700b0
int CKeyTable::FUN_140a700b0()
{
    return m_nPage;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f710-0x142c9f7c0 .text$yd
