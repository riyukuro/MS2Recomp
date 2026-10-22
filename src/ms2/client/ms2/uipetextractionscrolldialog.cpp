// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The pet extraction scroll window ("PetExtractionScrollDialog");
// see uipetextractionscrolldialog.h. One of the five TUs of the queue unit ?\uiotherpetsystemdialog.cpp. The body is the
// item extraction window's (uiitemextractionscrolldialog.cpp) with the pet skin gem as the result.
// MS2-UNIT: ?\uiotherpetsystemdialog.cpp
// MS2-RANGE: 0x140e70aa0-0x140e733a0 .text$mn
// MS2-RANGE: 0x1400d9b80-0x1400d9d30 .text$di
// MS2-PIN: ??_7Slot@UIPetExtractionScrollDialog@@6BBindData@NotifyContext@@@ 0x142e53c28 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipetextractionscrolldialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uipetextractionscrolldialog.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/commonfiles/itemsocketsystemutil.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
};

class Unk_ItemEquipData : public CItemData {};              // CItem::FUN_140527840's record (as commonfiles\item.cpp)

// The game context (FUN_1403ed2d0): its FUN_141bd0cc0 returns the local player.
class Unk_PxGameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_PxGameCtx* FUN_1403ed2d0();

extern Unk_Inventory DAT_143ab2a90;

// The feature switches (FUN_140166410 returns the manager).
class Unk_PxFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_PxFeatures* FUN_140166410();

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
UIPetExtractionScrollDialog::SlotBag* FUN_140e72d40(NotifyContext::BindData* p);

UIPetExtractionScrollDialog* FUN_140d27760(int nUiId);      // the open dialog with this UI id
void* FUN_140a50b50(DragSlot* pSlot);                       // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                     // its item uid
int FUN_14053feb0(int nItemId);                             // the rarity of an item id
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);          // the item data of an item id
CPetDataTable* FUN_14052d210();                             // TSingleton<CPetDataTable>::GetInstance
CItemSocketTable* FUN_14052d200();                          // TSingleton<CItemSocketTable>::GetInstance
CStringW FUN_140298ea0(CStringW strKey);                    // string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // string table text with one argument
CStringW FUN_14183e9c0(CStringW strName, int nRank);        // item name coloured by rank
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);    // "{0}" formatter
void FUN_1412751f0(const CStringW& text, int nA, int nB);   // notice
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                // show it

EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIPetExtractionScrollDialog::Slot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIPetExtractionScrollDialog::SlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x140e70aa0
UIPetExtractionScrollDialog::Slot::Slot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, nIndex), m_spItem(spItem)
{
    m_nFlags = 0x20;
}

// @0x140e70b40
UIPetExtractionScrollDialog::Slot::~Slot()
{
}

// @0x140e70b90
int UIPetExtractionScrollDialog::Slot::vfunc_13()
{
    return 0;
}

// @0x140e70ba0
int UIPetExtractionScrollDialog::Slot::vfunc_14()
{
    return vfunc_11();
}

// @0x140e70bd0
int UIPetExtractionScrollDialog::Slot::vfunc_18(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        UIPetExtractionScrollDialog* pDlg = FUN_140d27760(0x4f4a);
        if (pDlg != 0)
            pDlg->FUN_140e71d40(FUN_141405a10(pItemSlot));
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140e70c70 (ITooltip::vfunc_0)
int UIPetExtractionScrollDialog::Slot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spItem == 0)
        return 0;
    ASTooltip tip(pPlayer, m_nFlags, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()) != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140e70d70
int UIPetExtractionScrollDialog::Slot::vfunc_8(void* p)
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

// @0x140e70e50 create the bag of the items and register it under the name
void FUN_140e70e50(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items)
{
    UIPetExtractionScrollDialog::SlotBag* pBag =
        new (efd::MemHint(efd::MemHint::NONE)) UIPetExtractionScrollDialog::SlotBag(strName, items);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10((int)items.GetCount());
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140e70f20 destroy the registered bag
void FUN_140e70f20(const CString& strName)
{
    UIPetExtractionScrollDialog::SlotBag* pBag = FUN_140e72d40(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140e70f70
UIPetExtractionScrollDialog::SlotBag::SlotBag(const CString& strName, const ATL::CAtlArray<MS2Ptr<CItem> >& items)
    : DragSlotBag(strName)
{
    m_items.Copy(items);
}

// @0x140e70ff0
UIPetExtractionScrollDialog::SlotBag::~SlotBag()
{
}

// @0x140e71030
DragSlot* UIPetExtractionScrollDialog::SlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    MS2Ptr<CItem> spItem(0);
    if (nIndex > -1 && nIndex < (int)m_items.GetCount())
        spItem = m_items.GetAt(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) Slot(strName, nIndex, spItem);
}

// @0x140e71190
UIPetExtractionScrollDialog::UIPetExtractionScrollDialog()
    : m_strBag(vfunc_1()), m_nScrollUid(0), m_nTargetUid(0)
{
    FUN_141924170(1);
    m_164 = 1;
}

// @0x140e71240
CString UIPetExtractionScrollDialog::vfunc_1()
{
    return "PetExtractionScrollDialog";
}

// @0x140e71290
void UIPetExtractionScrollDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140e70f20(m_strBag);
    m_nTargetUid = 0;
}

// @0x140e712e0
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
void UIPetExtractionScrollDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    if (!FUN_140166410()->FUN_14036d570(0x6c))
        return;
    CInPacket* pIn = static_cast<CInPacket*>(pPacket);
    if (pIn->FUN_14070fe80() != 0x108)
        return;
    CInputStream* pStream = static_cast<CInputStream*>(pIn);
    unsigned nResult = pStream->vfunc_o8_1();
    if (nResult == 0)
    {
        __int64 nUidPet = pStream->vfunc_o8_4();
        __int64 nUidResult = pStream->vfunc_o8_4();
        MS2Ptr<CItem> spPet = DAT_143ab2a90.FUN_140a5d680(nUidPet);
        if (spPet.IsNull())
            return;
        MS2Ptr<CItem> spResult = DAT_143ab2a90.FUN_140a5d680(nUidResult);
        if (spResult.IsNull())
            return;
        CItemGem* pGem = spResult->FUN_140527900();
        if (pGem == 0)
            return;
        MS2Ptr<CGemBase> spGem = pGem->FUN_140d41400();
        if (spGem.get() == 0)
            return;
        if (spGem->vfunc_1() != 0xb)
            return;
        CGemBase* pSkin = spGem.get();
        if (pSkin == 0)
            return;
        pSkin->vfunc_3(*pStream);
        FUN_1412751f0(FUN_1405c2690(CStringW(L"s_petextraction_success"), spResult->FUN_140527b10()), 1, 0);
    }
    else if (nResult == 2)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_petextraction_inventoryfull")), 1, 0);
    }
    else if (nResult == 3)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_petextraction_invalid")), 1, 0);
    }
    else
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_petextraction_invalid")), 1, 0);
    }
    vfunc_67();
}

// @0x140e71880
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
bool UIPetExtractionScrollDialog::FUN_140e71880(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        MS2Ptr<CItem> spScroll = DAT_143ab2a90.FUN_140a5d680(m_nScrollUid);
        if (!spScroll.IsNull())
            DAT_143ab2a90.FUN_140a63880(spScroll.get(), FUN_1406c6bd0(L"{0}", m_nTargetUid));
    }
    return true;
}

// @0x140e71970
void UIPetExtractionScrollDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140e728e0();
}

// @0x140e719a0
// MS2-FUNCTIONAL: AS object temporaries / frame slots not tuned
void UIPetExtractionScrollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e728e0();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        FUN_140e72b40(MS2Ptr<CItem>(0), MS2Ptr<CItem>(0));
        ASArray items(2);
        ASObj objTarget(2);
        objTarget.FUN_1407cba60("binding", m_strBag);
        items.FUN_1422bc050(objTarget.FUN_1422bb870());
        ASObj objResult(2);
        objResult.FUN_1407cba60("binding", m_strBag);
        items.FUN_1422bc050(objResult.FUN_1422bb870());
        ASObj root(2);
        root.FUN_140c16160("array", ASArray(items));
        pDlg->FUN_140acd1f0("setData", AScript(root));
    }
}

// @0x140e71cd0
int UIPetExtractionScrollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
        OnOk();
    return 0;
}

// @0x140e71d40
// MS2-FUNCTIONAL: written from the decompile; temporaries / frame slots not tuned
void UIPetExtractionScrollDialog::FUN_140e71d40(__int64 nItemUid)
{
    if (vfunc_55() != 0)
        return;
    MS2Ptr<CItem> spPet = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (spPet == 0)
        return;
    if (spPet->FUN_140525640() == 0)                    // not a pet
        return;
    int nPetId = spPet->FUN_140527840()->FUN_14053dc60();
    MS2Ptr<CPetData> spPetData = FUN_14052d210()->Find(nPetId);
    if (spPetData.get() == 0)
        return;
    if (!spPetData->m_bEnablePetExtraction)
        return;
    unsigned nGemItemId = *Client::Constants::GetInstance()->gemPetSkinBaseItemID.Get();
    MS2Ptr<CItemData> spGemData = FUN_14053f870(nGemItemId);
    if (spGemData.get() == 0)
        return;
    MS2Ptr<CItem> spResult(new CItem);
    int nRarity = FUN_14053feb0(nGemItemId);
    if (!spResult->FUN_140523c40(nGemItemId, nRarity, 0))
        return;
    MS2Ptr<CItemData> spData(spResult->FUN_140527840());
    if (spData.get() == 0)
        return;
    if (spResult->FUN_140525a30() == 0)                 // not a gem
        return;
    CItemGem* pGem = spResult->FUN_140527900();
    if (pGem == 0)
        return;
    pGem->FUN_1405a7020(spData->FUN_14053e900(), spData->FUN_14053c650());
    MS2Ptr<CGemBase> spGem = pGem->FUN_140d41400();
    if (spGem.get() == 0)
        return;
    if (spGem->vfunc_1() != 0xb)                        // the pet skin gem
        return;
    CGemPetSkin* pSkin = static_cast<CGemPetSkin*>(spGem.get());
    if (pSkin == 0)
        return;
    pSkin->m_nPetId = nPetId;
    MS2Ptr<CItemData> spSocketData(spResult->FUN_140527840());
    int nRank = spResult->FUN_140526bd0();
    unsigned nSockets = FUN_14052d200()->FUN_14062d4b0(spData->property.socketDataId, nRank, spSocketData);
    CItemSocket* pSocket = spResult->FUN_1405279c0();
    if (pSocket != 0)
        pSocket->FUN_140620840(nSockets, 0);
    m_nTargetUid = nItemUid;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        FUN_140e72b40(spPet, spResult);
        ASArray items(2);
        ASObj objTarget(2);
        objTarget.FUN_1407cba60("binding", m_strBag);
        objTarget.FUN_1407cbb20("name", FUN_14183e9c0(spPet->FUN_140527b10(), spPet->FUN_140526bd0()));
        items.FUN_1422bc050(objTarget.FUN_1422bb870());
        ASObj objResult(2);
        objResult.FUN_1407cba60("binding", m_strBag);
        objResult.FUN_1407cbb20("name", FUN_14183e9c0(spResult->FUN_140527b10(), spResult->FUN_140526bd0()));
        items.FUN_1422bc050(objResult.FUN_1422bb870());
        ASObj root(2);
        root.FUN_140c16160("array", ASArray(items));
        pDlg->FUN_140acd1f0("setData", AScript(root));
    }
}

// @0x140e72860
void UIPetExtractionScrollDialog::FUN_140e72860(__int64 nScrollUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nScrollUid);
    if (spItem == 0)
        return;
    m_nScrollUid = nScrollUid;
}

// @0x140e728e0
void UIPetExtractionScrollDialog::FUN_140e728e0()
{
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        pInv->FUN_141999f60();
        pInv->FUN_141999e00();
    }
}

// @0x140e72920
void UIPetExtractionScrollDialog::OnOk()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nTargetUid);
    if (spItem == 0)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(
        1, FUN_140298ea0(CStringW(L"s_petextraction_conform")), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIPetExtractionScrollDialog::FUN_140e71880));
        FUN_140d73c60(spBox);
    }
}

// @0x140e72b40
void UIPetExtractionScrollDialog::FUN_140e72b40(MS2Ptr<CItem> spTarget, MS2Ptr<CItem> spResult)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    items.SetCount(2, -1);
    items.SetAt(0, spTarget);
    items.SetAt(1, spResult);
    FUN_140e70f20(m_strBag);
    FUN_140e70e50(m_strBag, items);
}

// @0x140e72d40
UIPetExtractionScrollDialog::SlotBag* FUN_140e72d40(NotifyContext::BindData* p)
{
    UIPetExtractionScrollDialog::SlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620007b, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca73c0-0x142ca7450 .text$yd
