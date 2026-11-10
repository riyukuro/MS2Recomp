// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemExtractionScrollDialog: see uiitemextractionscrolldialog.h.
// MS2-UNIT: ?\uiitemextractionscrolldialog.cpp
// MS2-RANGE: 0x1400d8300-0x1400d84b0 .text$di
// MS2-RANGE: 0x140e497d0-0x140e4c050 .text$mn
// MS2-PIN: ??1UIItemExtractionScrollDialog@@UEAA@XZ 0x140e4b9c0
// MS2-PIN: ??8?$MS2Ptr@VCExtractionItemInfo@@@@QEBA_NPEAVCExtractionItemInfo@@@Z 0x140e4b9f0
// MS2-PIN: ??_7Slot@UIItemExtractionScrollDialog@@6BBindData@NotifyContext@@@ 0x142e4bef8 ; hand: primary vftable
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemextractionscrolldialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemextractionscrolldialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/item.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemextractiontable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/worldservice.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
};

// The game context (FUN_1403ed2d0): its FUN_141bd0cc0 returns the local player.

// The inventory's bag of items by uid.
extern Unk_Inventory g_143ab2a90;

// The feature switches (FUN_140166410 returns the manager).
class Unk_140166410* FUN_140166410();   // the CFeatureManager instance (0x140166410, the definer's signature)

void* GetItemExtractionTable();   // C3: was GetItemExtractionTable

// The item data proxy has more slots than the shared header lists; slot 8 reads the item from a packet.
class Unk_ExProxyData : public Unk_UserProxyItemData
{
public:
    virtual void vfunc_7();
    virtual void vfunc_8(CInputStream& stream);         // 8 (+0x40) read from the packet
};

// The inventory dialog (UI id 0x4e2d).
class UIInventoryDialog : public UIDialog
{
public:
    void UpdateButtonState();
    void FUN_141999e00();
};
template<class T> T* Unk_BreakDialog(int);   // C3: was FUN_1405344f0

// The slot registry (see unit_1400d2c20.cpp / itemlockslot.cpp).
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70
UIItemExtractionScrollDialog::SlotBag* FUN_140e4b840(NotifyContext::BindData* p);

template <class T> T* GetItemUseDialog(int nId);   // C3: was FUN_140d27300
namespace NotifyContext { class BindData; }
class MS2DragSlot;
MS2DragSlot* AsDragSlot(NotifyContext::BindData* p);   // C3: the real def (displayslot.cpp), TypeCast(0x6200023)
class InvenSlot   // C3: member view for the former free stand-ins
{
public:
    __int64 GetItemUid();
};
int GetItemRank(int nItemId);                             // the rarity of an item id
void FUN_140710590(COutPacket&);                            // send
CStringW GetStringCommonByKey(const CStringW& strKey);             // string table text
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // item name coloured by rank
void ShowSystemNotice(const CStringW& text, int nA, int nB);   // notice
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW text, void* pListener, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                // show it

EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIItemExtractionScrollDialog::Slot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIItemExtractionScrollDialog::SlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers

// @0x140e497d0
UIItemExtractionScrollDialog::Slot::Slot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, nIndex), m_spItem(spItem)
{
    m_nFlags = 0x20;
}

// @0x140e49870
UIItemExtractionScrollDialog::Slot::~Slot()
{
}

// @0x140e498c0
int UIItemExtractionScrollDialog::Slot::vfunc_13()
{
    return 0;
}

// @0x140e498d0
int UIItemExtractionScrollDialog::Slot::vfunc_14()
{
    return vfunc_11();
}

// @0x140e49900
int UIItemExtractionScrollDialog::Slot::vfunc_18(void* p)
{
    void* pPlayer = WorldService::GetInstance()->GetLocalPlayer();
    if (pPlayer == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    void* pItemSlot = AsDragSlot(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        UIItemExtractionScrollDialog* pDlg = GetItemUseDialog<UIItemExtractionScrollDialog>(0x4f49);
        if (pDlg != 0)
            pDlg->FUN_140e4a920(((class InvenSlot*)(void*)(pItemSlot))->GetItemUid());
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140e499a0 (ITooltip::vfunc_0)
int UIItemExtractionScrollDialog::Slot::vfunc_0(void* p)
{
    void* pPlayer = WorldService::GetInstance()->GetLocalPlayer();
    if (pPlayer == 0)
        return 0;
    if (m_spItem == 0)
        return 0;
    ASTooltip tip(pPlayer, m_nFlags, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()) != 0) {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.GetValue();
        return 1;
    }
    return 0;
}

// @0x140e49aa0
int UIItemExtractionScrollDialog::Slot::vfunc_8(void* p)
{
    void* pPlayer = WorldService::GetInstance()->GetLocalPlayer();
    if (pPlayer == 0)
        return 0;
    if (m_spItem == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), pPlayer, 0x415) != 0)
        *static_cast<Scaleform::GFx::Value*>(p) = slot.GetValue();
    return 1;
}

// @0x140e49b80 create the bag of the items and register it under the name
void FUN_140e49b80(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items)
{
    UIItemExtractionScrollDialog::SlotBag* pBag =
        new (efd::MemHint(efd::MemHint::NONE)) UIItemExtractionScrollDialog::SlotBag(strName, items);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10((int)items.GetCount());
        Unk_NotifyContext::RegisterBinding(strName, pBag);
    }
}

// @0x140e49c50 destroy the registered bag
void UnregisterSlotBag(const CString& strName)
{
    UIItemExtractionScrollDialog::SlotBag* pBag = FUN_140e4b840(Unk_NotifyContext::FindBinding(strName));
    if (pBag)
    {
        ((class DragSlotBag*)(class DragSlotBag*)(pBag))->ClearSlots();
        Unk_NotifyContext::UnregisterBinding(strName);
    }
}

// @0x140e49ca0
UIItemExtractionScrollDialog::SlotBag::SlotBag(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items)
    : DragSlotBag(strName)
{
    m_items.Copy(items);
}

// @0x140e49d20
UIItemExtractionScrollDialog::SlotBag::~SlotBag()
{
}

// @0x140e49d60
DragSlot* UIItemExtractionScrollDialog::SlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    MS2Ptr<CItem> spItem(0);
    if (nIndex > -1 && nIndex < (int)m_items.GetCount())
        spItem = m_items.GetAt(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) Slot(strName, nIndex, spItem);
}

// @0x140e49ec0
UIItemExtractionScrollDialog::UIItemExtractionScrollDialog()
    : m_strBag(GetTypeName()), m_nScrollUid(0), m_nTargetUid(0)
{
    SetTweenEnabled(1);
    m_164 = 1;
}

// @0x140e49f70
CString UIItemExtractionScrollDialog::GetTypeName()
{
    return "ItemExtractionScrollDialog";
}

// @0x140e49fc0
void UIItemExtractionScrollDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    UnregisterSlotBag(m_strBag);
    m_nTargetUid = 0;
}

// @0x140e4a010
void UIItemExtractionScrollDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0x8f))
        return;
    if (static_cast<CInPacket*>(pPacket)->GetOpcode() == 0x107)
    {
        int nResult = static_cast<CInPacket*>(pPacket)->ReadUInt8();
        if (nResult == 0)
        {
            __int64 nUidItem = static_cast<CInPacket*>(pPacket)->ReadInt64();
            __int64 nUidResult = static_cast<CInPacket*>(pPacket)->ReadInt64();
            unsigned nCount = (unsigned short)static_cast<CInPacket*>(pPacket)->ReadInt16();
            MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUidItem);
            if (spItem == 0)
                return;
            MS2Ptr<CItem> spResult = g_143ab2a90.FindItemByUid(nUidResult);
            if (spResult == 0)
                return;
            Unk_ExProxyData* pProxy = static_cast<Unk_ExProxyData*>(spResult->GetProxy());
            if (pProxy == 0)
                return;
            CItemTransfer* pTransfer = reinterpret_cast<CItemTransfer*>(spResult->GetTransfer());
            if (pTransfer == 0)
                return;
            pProxy->vfunc_8(*static_cast<CInPacket*>(pPacket));                      // MS2: slot 8
            pTransfer->vfunc_2(*static_cast<CInPacket*>(pPacket));
            spItem->SetExtractionCount(nCount);
            ShowSystemNotice(FUN_14028dfa0<CStringW>(CStringW(L"s_itemextraction_success"), spResult->FUN_140527b10()), 1, 0);
        }
        else if (nResult == 1)
        {
            ShowSystemNotice(GetStringCommonByKey(L"s_itemextraction_inventoryfull"), 1, 1);
        }
        else if (nResult == 2)
        {
            ShowSystemNotice(GetStringCommonByKey(L"s_itemextraction_lack_scroll"), 1, 1);
        }
        vfunc_67();
    }
}

// @0x140e4a4b0
bool UIItemExtractionScrollDialog::SendItemExtractionScroll(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    COutPacket packet(static_cast<int>(SendOp::ItemExtractionScroll), 0);
    packet.WriteInt64(m_nScrollUid);
    packet.WriteInt64(m_nTargetUid);
    FUN_140710590(packet);
    return true;
}

// @0x140e4a550
void UIItemExtractionScrollDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    RefreshInventoryDialog();
}

// @0x140e4a580
void UIItemExtractionScrollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    RefreshInventoryDialog();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        FUN_140e4b640(MS2Ptr<CItem>(0), MS2Ptr<CItem>(0));
        ASArray items(2);
        ASObj objTarget(2);
        objTarget.SetStringMember("binding", m_strBag);
        items.PushValue(objTarget.GetValue());
        ASObj objScroll(2);
        objScroll.SetStringMember("binding", m_strBag);
        items.PushValue(objScroll.GetValue());
        ASObj root(2);
        root.FUN_140c16160("array", ASArray(items));
        pDlg->FUN_140acd1f0("setData", AScript(root));
    }
}

// @0x140e4a8b0
int UIItemExtractionScrollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
        OnOk();
    return 0;
}

// @0x140e4a920
void UIItemExtractionScrollDialog::FUN_140e4a920(__int64 nItemUid)
{
    if (vfunc_55() != 0)
        return;
    MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nItemUid);
    if (spItem == 0)
        return;
    if (spItem->GetExtractionCount() < 1u)
    {
        ShowSystemNotice(GetStringCommonByKey(L"s_itemextraction_cannot"), 1, 1);
        return;
    }
    CExtractionItemInfoPtr spRow = ((CItemExtractionTable*)GetItemExtractionTable())->GetData(spItem->GetItemId());
    if (spRow == 0)
    {
        ShowSystemNotice(GetStringCommonByKey(L"s_itemextraction_cannot"), 1, 1);
        return;
    }
    MS2Ptr<CItem> spScroll(new CItem);
    if (!spScroll->FUN_140523c40(spRow->m_nResultItemId, GetItemRank(spRow->m_nResultItemId), 0))
        return;
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(spScroll->GetData()));
    if (spData == 0)
        return;
    if (spScroll->GetProxy() != 0)
        spScroll->GetProxy()->vfunc_3(spItem->GetProxy());
    spScroll->FUN_14052b370();
    MS2Ptr<CItemTransfer> spTransfer(reinterpret_cast<CItemTransfer*>(spScroll->GetTransfer()));
    if (spTransfer.get() != 0)
    {
        spTransfer->SetSocketTransferFlag(false);
        spTransfer->FUN_140635300();
    }
    m_nTargetUid = nItemUid;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        FUN_140e4b640(spItem, spScroll);
        ASArray items(2);
        ASObj objTarget(2);
        objTarget.SetStringMember("binding", m_strBag);
        ((class AScript&)(objTarget)).SetWStringMember("name", FUN_14183e9c0(spItem->FUN_140527b10(), spItem->GetRarity()));
        ((class AScript&)(objTarget)).SetWStringMember("consume", FUN_14028dfa0<unsigned>(CStringW(L"s_itemextraction_consume"), spRow->m_nScrollCount));
        items.PushValue(objTarget.GetValue());
        ASObj objScroll(2);
        objScroll.SetStringMember("binding", m_strBag);
        ((class AScript&)(objScroll)).SetWStringMember("name", FUN_14183e9c0(spScroll->FUN_140527b10(), spScroll->GetRarity()));
        items.PushValue(objScroll.GetValue());
        ASObj root(2);
        root.FUN_140c16160("array", ASArray(items));
        pDlg->FUN_140acd1f0("setData", AScript(root));
    }
}

// @0x140e4b2c0
void UIItemExtractionScrollDialog::SetScrollUid(__int64 nScrollUid)
{
    MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nScrollUid);
    if (spItem == 0)
        return;
    m_nScrollUid = nScrollUid;
}

// @0x140e4b340
void UIItemExtractionScrollDialog::RefreshInventoryDialog()
{
    UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
    if (pInv != 0)
    {
        pInv->UpdateButtonState();
        pInv->FUN_141999e00();
    }
}

// @0x140e4b380
void UIItemExtractionScrollDialog::OnOk()
{
    MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(m_nTargetUid);
    if (spItem == 0)
        return;
    CExtractionItemInfoPtr spRow = ((CItemExtractionTable*)GetItemExtractionTable())->GetData(spItem->GetItemId());
    if (spRow == 0)
        return;
    MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(
        1, FUN_14028dfa0<unsigned>(CStringW(L"s_itemextraction_conform"), spRow->m_nScrollCount), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemExtractionScrollDialog::SendItemExtractionScroll));
        FUN_140d73c60(spBox);
    }
}

// @0x140e4b640
void UIItemExtractionScrollDialog::FUN_140e4b640(MS2Ptr<CItem> spTarget, MS2Ptr<CItem> spScroll)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    items.SetCount(2, -1);
    items.SetAt(0, spTarget);
    items.SetAt(1, spScroll);
    UnregisterSlotBag(m_strBag);
    FUN_140e49b80(m_strBag, items);
}

// @0x140e4b840
UIItemExtractionScrollDialog::SlotBag* FUN_140e4b840(NotifyContext::BindData* p)
{
    UIItemExtractionScrollDialog::SlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620007b, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca6a00-0x142ca6a90 .text$yd
