// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemExtractionScrollDialog: see uiitemextractionscrolldialog.h.
// MS2-UNIT: ?\uiitemextractionscrolldialog.cpp
// MS2-RANGE: 0x1400d8300-0x1400d84b0 .text$di
// MS2-RANGE: 0x140e497d0-0x140e4c050 .text$mn
// MS2-PIN: ??1UIItemExtractionScrollDialog@@UEAA@XZ 0x140e4b9c0
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
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/item.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
};

// The game context (FUN_1403ed2d0): its FUN_141bd0cc0 returns the local player.
class Unk_ExGameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_ExGameCtx* FUN_1403ed2d0();

// The inventory's bag of items by uid.
class Unk_ExInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nUid); };
extern Unk_ExInventory DAT_143ab2a90;

// The feature switches (FUN_140166410 returns the manager).
class Unk_ExFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_ExFeatures* FUN_140166410();

// A row of the item extraction table: the scroll item (+0x20) and the text argument (+0x18).
class Unk_ExtractionRow : public CPtred
{
public:
    int m_nConsume;                                     // +0x18 (CPtred is 0x18 bytes)
    int m_1c;
    int m_nScrollId;                                    // +0x20
};
class Unk_ExtractionTable { public: MS2Ptr<Unk_ExtractionRow> FUN_140597580(int nItemId); };
Unk_ExtractionTable* FUN_14052d1f0();

// The item data proxy has more slots than the shared header lists; slot 8 reads the item from a packet.
class Unk_ExProxyData : public Unk_UserProxyItemData
{
public:
    virtual void vfunc_7();
    virtual void vfunc_8(CInputStream* pStream);        // 8 (+0x40) read from the packet
};

// The inventory dialog (UI id 0x4e2d).
class UIInventoryDialog : public UIDialog
{
public:
    void FUN_141999f60();
    void FUN_141999e00();
};
UIInventoryDialog* FUN_1405344f0(int nUiId);

// The slot registry (see unit_1400d2c20.cpp / itemlockslot.cpp).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);
UIItemExtractionScrollDialog::SlotBag* FUN_140e4b840(NotifyContext::BindData* p);

UIItemExtractionScrollDialog* FUN_140d27300(int nUiId);     // the open dialog with this UI id
void* FUN_140a50b50(DragSlot* pSlot);                       // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                     // its item uid
int FUN_14053feb0(int nItemId);                             // the rarity of an item id
void FUN_140710590(COutPacket&);                            // send
CStringW FUN_14028b8e0(const CStringW& strKey);             // string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // string table text with one argument
CStringW FUN_140938ae0(CStringW strKey, const int& nArg);          // string table text with one number
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // item name coloured by rank
void FUN_1412751f0(const CStringW& text, int nA, int nB);   // notice
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                // show it

EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIItemExtractionScrollDialog::Slot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIItemExtractionScrollDialog::SlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

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
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        UIItemExtractionScrollDialog* pDlg = FUN_140d27300(0x4f49);
        if (pDlg != 0)
            pDlg->FUN_140e4a920(FUN_141405a10(pItemSlot));
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140e499a0 (ITooltip::vfunc_0)
int UIItemExtractionScrollDialog::Slot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spItem == 0)
        return 0;
    ASTooltip tip(pPlayer, m_nFlags, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()) != 0) {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140e49aa0
int UIItemExtractionScrollDialog::Slot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spItem == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), pPlayer, 0x415) != 0)
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
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
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140e49c50 destroy the registered bag
void FUN_140e49c50(const CString& strName)
{
    UIItemExtractionScrollDialog::SlotBag* pBag = FUN_140e4b840(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
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
    if (nIndex >= 0 && nIndex < (int)m_items.GetCount())
        spItem = m_items.GetAt(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) Slot(strName, nIndex, spItem);
}

// @0x140e49ec0
UIItemExtractionScrollDialog::UIItemExtractionScrollDialog()
    : m_strBag(vfunc_1()), m_nScrollUid(0), m_nTargetUid(0)
{
    FUN_141924170(1);
    m_164 = 1;
}

// @0x140e49f70
CString UIItemExtractionScrollDialog::vfunc_1()
{
    return "ItemExtractionScrollDialog";
}

// @0x140e49fc0
void UIItemExtractionScrollDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140e49c50(m_strBag);
    m_nTargetUid = 0;
}

// @0x140e4a010
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
void UIItemExtractionScrollDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    if (!FUN_140166410()->FUN_14036d570(0x8f))
        return;
    CInPacket* pIn = static_cast<CInPacket*>(pPacket);
    if (pIn->FUN_14070fe80() != 0x107)
        return;
    CInputStream* pStream = static_cast<CInputStream*>(pIn);
    unsigned char nResult = pStream->vfunc_o8_1();
    if (nResult == 0)
    {
        __int64 nUidItem = pStream->vfunc_o8_4();
        __int64 nUidResult = pStream->vfunc_o8_4();
        unsigned nCount = (unsigned short)pStream->vfunc_o8_2();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUidItem);
        if (spItem.IsNull())
            return;
        MS2Ptr<CItem> spResult = DAT_143ab2a90.FUN_140a5d680(nUidResult);
        if (spResult.IsNull())
            return;
        Unk_ExProxyData* pProxy = static_cast<Unk_ExProxyData*>(spResult->FUN_140527870());
        if (pProxy == 0)
            return;
        CItemTransfer* pTransfer = reinterpret_cast<CItemTransfer*>(spResult->FUN_140527930());
        if (pTransfer == 0)
            return;
        pProxy->vfunc_8(pStream);                       // MS2: slot 8
        pTransfer->vfunc_2(*pStream);
        spItem->FUN_140529280(nCount);
        FUN_1412751f0(FUN_1405c2690(CStringW(L"s_itemextraction_success"), spResult->FUN_140527b10()), 1, 0);
    }
    else if (nResult == 1)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemextraction_inventoryfull")), 1, 1);
    }
    else if (nResult == 2)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemextraction_lack_scroll")), 1, 1);
    }
    vfunc_67();
}

// @0x140e4a4b0
bool UIItemExtractionScrollDialog::FUN_140e4a4b0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(0xa0, 0);
        packet.vfunc_o10_4(m_nScrollUid);
        packet.vfunc_o10_4(m_nTargetUid);
        FUN_140710590(packet);
    }
    return true;
}

// @0x140e4a550
void UIItemExtractionScrollDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140e4b340();
}

// @0x140e4a580
// MS2-FUNCTIONAL: AS object temporaries / frame slots not tuned
void UIItemExtractionScrollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e4b340();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        FUN_140e4b640(MS2Ptr<CItem>(0), MS2Ptr<CItem>(0));
        ASArray items(2);
        ASObj objTarget(2);
        objTarget.FUN_1407cba60("binding", m_strBag);
        items.FUN_1422bc050(objTarget.FUN_1422bb870());
        ASObj objScroll(2);
        objScroll.FUN_1407cba60("binding", m_strBag);
        items.FUN_1422bc050(objScroll.FUN_1422bb870());
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
        FUN_140e4b380();
    return 0;
}

// @0x140e4a920
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
void UIItemExtractionScrollDialog::FUN_140e4a920(__int64 nItemUid)
{
    if (vfunc_55() != 0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (spItem.IsNull())
        return;
    if (spItem->FUN_1405292a0() == 0)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemextraction_cannot")), 1, 1);
        return;
    }
    MS2Ptr<Unk_ExtractionRow> spRow = FUN_14052d1f0()->FUN_140597580(spItem->FUN_1405276c0());
    if (!(spRow == 0))
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemextraction_cannot")), 1, 1);
        return;
    }
    MS2Ptr<CItem> spScroll(new CItem);
    int nRarity = FUN_14053feb0(spRow->m_nScrollId);
    if (!spScroll->FUN_140523c40(spRow->m_nScrollId, nRarity, 0))
        return;
    MS2Ptr<Unk_UserProxyItemData> spData(spScroll->FUN_140527840() ? 0 : 0);
    if (spScroll->FUN_140527870() != 0)
        spScroll->FUN_140527870()->vfunc_3(spItem->FUN_140527870());
    spScroll->FUN_14052b370();
    MS2Ptr<CItemTransfer> spTransfer(reinterpret_cast<CItemTransfer*>(spScroll->FUN_140527930()));
    if (spTransfer.get() != 0)
    {
        spTransfer->FUN_140635320(false);
        spTransfer->FUN_140635300();
    }
    m_nTargetUid = nItemUid;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        FUN_140e4b640(spItem, spScroll);
        ASArray items(2);
        ASObj objTarget(2);
        objTarget.FUN_1407cba60("binding", m_strBag);
        objTarget.FUN_1407cbb20("name", FUN_14183e9c0(spItem->FUN_140527b10(), spItem->FUN_140526bd0()));
        objTarget.FUN_1407cbb20("consume", FUN_140938ae0(CStringW(L"s_itemextraction_consume"), spRow->m_nConsume));
        items.FUN_1422bc050(objTarget.FUN_1422bb870());
        ASObj objScroll(2);
        objScroll.FUN_1407cba60("binding", m_strBag);
        objScroll.FUN_1407cbb20("name", FUN_14183e9c0(spScroll->FUN_140527b10(), spScroll->FUN_140526bd0()));
        items.FUN_1422bc050(objScroll.FUN_1422bb870());
        ASObj root(2);
        root.FUN_140c16160("array", ASArray(items));
        pDlg->FUN_140acd1f0("setData", AScript(root));
    }
}

// @0x140e4b2c0
void UIItemExtractionScrollDialog::FUN_140e4b2c0(__int64 nScrollUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nScrollUid);
    if (spItem == 0)
        return;
    m_nScrollUid = nScrollUid;
}

// @0x140e4b340
void UIItemExtractionScrollDialog::FUN_140e4b340()
{
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        pInv->FUN_141999f60();
        pInv->FUN_141999e00();
    }
}

// @0x140e4b380
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
void UIItemExtractionScrollDialog::FUN_140e4b380()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nTargetUid);
    if (spItem.IsNull())
        return;
    MS2Ptr<Unk_ExtractionRow> spRow = FUN_14052d1f0()->FUN_140597580(spItem->FUN_1405276c0());
    if (spRow == 0)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(
        1, FUN_140938ae0(CStringW(L"s_itemextraction_conform"), spRow->m_nConsume), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemExtractionScrollDialog::FUN_140e4a4b0));
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
    FUN_140e49c50(m_strBag);
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
