// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemExchangeScrollDialog: the item exchange scroll window.
// See uiitemexchangescrolldialog.h. Member and local names are invented from the use.
// MS2-UNIT: ?\uiitemexchangescrolldialog.cpp
// MS2-RANGE: 0x140f50d60-0x140f56ab0 .text$mn
// MS2-RANGE: 0x1400dff60-0x1400e0020 .text$di
// MS2-PIN: ??1ExchangeRequest@CCItemExchangeScrollPacket@@UEAA@XZ 0x140f56690
// MS2-PIN: ??1ForceFillIngredient@CCItemExchangeScrollPacket@@UEAA@XZ 0x140f566b0
// MS2-PIN: ??_GExchangeRequest@CCItemExchangeScrollPacket@@UEAAPEAXI@Z 0x140f568a0
// MS2-PIN: ??_GForceFillIngredient@CCItemExchangeScrollPacket@@UEAAPEAXI@Z 0x140f568e0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_SVRPTR_ASSIGN_INT
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemexchangescrolldialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemexchangescrolldialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ccitemexchangescrollpacket.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/inventoryitemkey.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/commonfiles/item.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"   // C3: TSingleton<> needs the class
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422cdfb0

// ---- unit-local views of exe objects ----

// A button of the movie.
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
//
//
//

// The AS function object calling back into C++ (ctor 0x1422c8430, dtor 0x1422c85b0).
class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser, int nMovieId);   // C3: the definition takes __int64 (gfxui/asfunction.cpp)
    ~ASFunction();
private:
    void* m_40;
};

// The inventory (global 0x143ab2a90); its count queries take an Unk_InventoryItemKey (id, +8 kind 1 = by item id).
class Unk_Inventory { public: class MS2Ptr<class CItem> FindItemByUid(__int64); int GetItemCountByTag(int nTypeId, int n); int GetItemCountByFilter(const int* filter); };   // C3: GetItemCountByFilter = inventory.h's signature
class Unk_IesInventory : public Unk_Inventory {};
class Unk_Inventory;
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90); read through Unk_IesInventory
extern __int64 DAT_143ab2898;                           // the player's mesos
extern int DAT_143ab2914;                               // the build level (> 0x31: debug commands)


class CGameEventValueExchangeScrollSale   // C3: member view for the former free stand-ins
{
public:
    int Get(unsigned long);
};

// Dialog child lookups.
class Unk_IesEntity : public UIDialog
{
public:
};

// The debug key state (singleton).
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The status listener registry.

// The string table (item names).

// AS views.
class Unk_IesChild : public ASMovieClip
{
};
struct Unk_IesParams                                                      // Scaleform FunctionHandler::Params
{
    void* m_pad_00[4];
    Scaleform::GFx::Value* m_pArgs;                                       // +0x20
    unsigned m_nArgs;                                                     // +0x28
};

// Helpers of other units.
void SetChildHtmlText(const Scaleform::GFx::Value& v, CString strName, CStringW strText);   // set the text of a child field
void DestroyItemInfoSlot(const CString& strKey);                          // release the item bound to the key
void FUN_141415560(const CString& strKey, ItemInfoSlot::CreateParam* pParam);      // bind an item slot
void FUN_140b6c7a0(const CString& strName, __int64 nTarget, MS2Ptr<CItem> spItem);  // create the drag slot
void FUN_140b6c890(const CString& strName);                         // drop the drag slot
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // the item data of an id
int GetItemRank(int);   // C3: was GetItemRank
int Clamp(int a, int b, int nMax);                          // clamp
CStringW FUN_1409404f0(__int64 nMeso);                              // meso text
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text
void ShowSystemNotice(const CStringW& strText, int a, int b);          // show a notice
void FUN_140710590(COutPacket& packet);                             // send
void FUN_140202470(unsigned char* pRecord, COutputStream& out);     // encode an ExchangeRequest
void FUN_140202580(unsigned char* pRecord, COutputStream& out);     // encode a ForceFillIngredient
int FUN_1422db730();

using ATL::CAtlArray;

// @0x1400dff60
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140f50d60
UIItemExchangeScrollDialog::UIItemExchangeScrollDialog()
{
    SetTweenEnabled(1);
    m_uidScroll = 0;
    m_uidTarget = 0;
}

// @0x140f50eb0
CString UIItemExchangeScrollDialog::GetTypeName()
{
    return "ItemExchangeScrollDialog";
}

// @0x140f50f00
int UIItemExchangeScrollDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140f50f30
void UIItemExchangeScrollDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f50f50
void UIItemExchangeScrollDialog::vfunc_72()
{
    vfunc_55();
}

// @0x140f50f80
void UIItemExchangeScrollDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (unsigned i = 0; i < m_infoKeys.GetCount(); i++)
        DestroyItemInfoSlot(m_infoKeys[i]);
    m_infoKeys.RemoveAll();
    for (unsigned i = 0; i < m_dragKeys.GetCount(); i++)
        FUN_140b6c890(m_dragKeys[i]);
    m_dragKeys.RemoveAll();
    m_uidScroll = 0;
    m_uidTarget = 0;
    m_spScroll = 0;
    m_spOk = 0;
    m_spExchange = 0;
    m_spIngredients = 0;
    m_spDebugAdd10 = 0;
    m_spDebugAddMax = 0;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x140f51150
void UIItemExchangeScrollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_spOk = GetChild<ASButton>("m_ok");
    FUN_140f53a70();
    FUN_140f52880();
    m_spScroll = GetChild<ASMovieClip>("m_scroll");
    BindDebugButtons();
}

// @0x140f51280
int UIItemExchangeScrollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
            SendItemExchangeScrollMode1(&data);
        return 1;
    }
    return 0;
}

// @0x140f51350
void UIItemExchangeScrollDialog::vfunc_15()
{
}

// @0x140f51360
void UIItemExchangeScrollDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (((CInPacket*)p)->GetOpcode() == 0x102)
    {
        int nKind = ((CInPacket*)p)->ReadUInt8();
        if (nKind == 0)
            FUN_140f52ca0((CInPacket*)p);
        else if (nKind == 2)
        {
            int nResult = (unsigned short)((CInPacket*)p)->ReadInt16();
            bool bOk = FUN_140f55670(&nResult);
            if (!bOk)
                vfunc_67();
        }
        else if (nKind == 3)
            UpdateIngredientCounts((CInPacket*)p);
    }
}

// @0x140f51460
void UIItemExchangeScrollDialog::vfunc_oa0_11(void* p)
{
    FUN_140f56180();
}

// @0x140f51490
void UIItemExchangeScrollDialog::SetScrollItem(CItem* pScroll)
{
    m_uidScroll = pScroll->GetItemUid();
}

// @0x140f514c0
void UIItemExchangeScrollDialog::FUN_140f514c0(const Unk_ExchangeItemRef* pRef, CString strKey, ASObj& obj, unsigned char nFlags, int nMul,
                                               MS2Ptr<CItem> spCur)
{
    if ((nFlags & 1) && pRef->m_nCount == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(pRef->m_nId, pRef->m_nRank, 0) == 0)
        return;
    if (nFlags & 0x10)
        spItem->SetCountClamped(0);
    else
    {
        int nCount = pRef->m_nCount * nMul;
        spItem->SetCountClamped(nCount);
    }
    ASObj slot(2);
    ItemInfoSlot::CreateParam param;
    param.m_spItem = spItem;
    param.m_nIconType = 0x415;
    if (nFlags & 2)
        param.m_nFlags = 0x800;
    CStringW strText;
    if (nFlags & 1)
    {
        Unk_InventoryItemKey key;
        key.m_id = pRef->m_nId;
        key.m_extra = 1;
        int nHave = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&key.m_id);
        int nBase = pRef->m_nCount;
        int nNeed = nMul * nBase;
        CStringW strCount;
        if (nHave >= nNeed)
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
        else
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
        strText = strCount;
        slot.SetIntMember("itemRequireCount", nBase);
        slot.SetIntMember("itemCurrentCount", nHave);
    }
    else
    {
        int nBase = pRef->m_nCount;
        int nCount = nMul * nBase;
        param.m_strCount = Unk_SocketFormat("{0}", nCount);
        strText = spItem->FUN_140528160();
        if (spCur.get() != 0)
        {
            spItem->SetEnchantLevel(spCur->GetEnchantLevel(), 0);
            if (spItem->GetStatus() != 0
                && reinterpret_cast<CItemStatus*>(spItem->GetStatus())->GetEnchant() != 0
                && spCur->FUN_140527030() != 0)
                reinterpret_cast<CItemStatus*>(spItem->GetStatus())->GetEnchant()->FUN_14058c870();
            reinterpret_cast<CItemStatus*>(spItem->GetStatus())->CopyGroup4From(
                MS2Ptr<CItemStatus>(reinterpret_cast<CItemStatus*>(spCur->GetStatus())));
        }
    }
    CString strBind;
    if (nFlags & 8)
    {
        strBind.Format("%s_drag_%d", (const char*)GetTypeName(), m_dragKeys.GetCount());
        FUN_140b6c7a0(strBind, m_uidScroll, MS2Ptr<CItem>(spCur));
        ((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_dragKeys))->Add(strBind);
    }
    else
    {
        strBind.Format("%s_info_%d", (const char*)GetTypeName(), m_infoKeys.GetCount());
        FUN_141415560(strBind, &param);
        ((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_infoKeys))->Add(strBind);
    }
    if (nFlags & 4)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(pRef->m_nId);
        if (spData.get() != 0)
            slot.SetWStringMember("level", FUN_14028dfa0(CStringW(L"s_itemslot_exchange_level"),
                                                      *reinterpret_cast<const unsigned*>(reinterpret_cast<char*>(spData.operator->()) + 0x138)));
    }
    slot.SetStringMember("binding", CString(strBind));
    slot.SetWStringMember("name", CStringW(strText));
    obj.FUN_1409eb270(strKey, slot);
}

// @0x140f51e90
void UIItemExchangeScrollDialog::WriteIngredientSlot(CIngredientInfo* pIng, CString strKey, ASObj& obj, unsigned char nFlags, int nMul)
{
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(pIng->GetItemId(), GetItemRank(pIng->GetItemId()), 0) == 0)
        return;
    ItemInfoSlot::CreateParam param;
    param.m_spItem = spItem;
    param.m_nIconType = 0x415;
    if (nFlags & 2)
        param.m_nFlags = 0x800;
    ASObj slot(2);
    CStringW strText;
    if (nFlags & 1)
    {
        int nHave = 0;
        if (pIng->m_b != 0)
            nHave = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByTag(pIng->m_b, 0);
        else
        {
            Unk_InventoryItemKey key;
            key.m_id = pIng->GetItemId();
            key.m_extra = 1;
            nHave = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&key.m_id);
        }
        int nBase = pIng->m_c;
        int nNeed = nMul * nBase;
        CStringW strCount;
        if (nHave >= nNeed)
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
        else
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
        strText = strCount;
        param.m_nIconType = 0x405;
        slot.SetIntMember("itemRequireCount", nBase);
        slot.SetIntMember("itemCurrentCount", nHave);
    }
    else
    {
        int nBase = pIng->m_c;
        int nCount = nBase * nMul;
        param.m_strCount = Unk_SocketFormat("{0}", nCount);
        strText = spItem->FUN_140528160();
        spItem->SetCountClamped(nCount);
    }
    CString strBind;
    strBind.Format("%s_info_%d", (const char*)GetTypeName(), m_infoKeys.GetCount());
    FUN_141415560(strBind, &param);
    ((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)&static_cast<class ATL::CAtlArray<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>, class ATL::CElementTraits<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>>>>&>(m_infoKeys))->Add(strBind);
    slot.SetStringMember("binding", CString(strBind));
    slot.SetWStringMember("name", CStringW(strText));
    obj.FUN_1409eb270(strKey, slot);
}

// @0x140f524d0
bool UIItemExchangeScrollDialog::CanExchange(unsigned nCount)
{
    int nError = GetExchangeErrorCode(nCount);
    return nError == 0;
}

// @0x140f52520
unsigned UIItemExchangeScrollDialog::GetExchangeErrorCode(unsigned nCount)
{
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    if (spInfo == 0)
        return 1;
    unsigned nError = CheckExchangeRequirements(spInfo->GetMeso(), &spInfo->m_receipe, &spInfo->m_require, nCount);
    return nError;
}

// @0x140f52610
unsigned UIItemExchangeScrollDialog::CheckExchangeRequirements(__int64 nMeso, const Unk_ExchangeItemRef* pRecipe, CIngredientContainer* pRequire, unsigned nCount)
{
    if (nMeso > 0 && DAT_143ab2898 < nMeso * nCount)
        return 3;
    Unk_InventoryItemKey key;
    key.m_id = pRecipe->m_nId;
    key.m_extra = 1;
    int nNeed = pRecipe->m_nCount * nCount;
    if (reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&key.m_id) < nNeed)
        return 1;
    for (unsigned __int64 i = 0; i < pRequire->FUN_14026bf10(); i++)
    {
        Unk_IngRef ref = pRequire->FUN_14026be50(i);
        if (ref == 0)
            continue;
        int nNeedIng = ref->m_c * nCount;
        if (ref->m_b != 0)
        {
            if (reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByTag(ref->m_b, 0) < nNeedIng)
                return 4;
        }
        else
        {
            Unk_InventoryItemKey ingKey;
            ingKey.m_id = ref->GetItemId();
            ingKey.m_extra = 1;
            if (reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&ingKey.m_id) < nNeedIng)
                return 4;
        }
    }
    return 0;
}

// @0x140f52810
CItem* UIItemExchangeScrollDialog::GetScrollItem()
{
    return reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).FindItemByUid(m_uidScroll).get();
}

// @0x140f52880
void UIItemExchangeScrollDialog::FUN_140f52880()
{
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    if (spInfo == 0)
        return;
    ASObj obj(2);
    int bEnable = 0;
    CStringW strTitle;
    int nCount = 1;
    switch (spInfo->m_eType)
    {
    case 1:
        FUN_140f53bb0(obj, spInfo.get());
        bEnable = CanExchange(nCount);
        strTitle = L"$s_item_exchange_title";
        break;
    case 2:
        FUN_140f54120(obj, spInfo.get());
        bEnable = 0;
        strTitle = L"$s_item_exchange_upgrade_title";
        break;
    case 3:
        FUN_140f544d0(obj, spInfo.get());
        bEnable = CanExchange(nCount);
        strTitle = L"$s_item_exchange_trading_title";
        break;
    }
    unsigned nItemId = spInfo->m_nId;
    unsigned nSale = ((class CGameEventValueExchangeScrollSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetExchangeScrollSale()))->Get(nItemId);
    CStringW strSale;
    if (nSale != 0)
    {
        float fRate = (float)nSale / 100.0f;
        strSale = FUN_14028dfa0<float>(CStringW(L"s_itemslot_exchange_money_sale_desc"), fRate);
    }
    obj.SetWStringMember("event", CStringW(strSale));
    m_30->Invoke("setData", obj);
    if (m_spOk.get() != 0)
        m_spOk->SetEnabled(bEnable);
    if (MS2Ptr<ASTextField> spTitle = ((Unk_IesEntity*)this)->GetChild<ASTextField>("m_title"))
        spTitle->SetTextW(strTitle);
}

// @0x140f52c80
void UIItemExchangeScrollDialog::FUN_140f52c80()
{
    FUN_140f52880();
}

// @0x140f52ca0
void UIItemExchangeScrollDialog::FUN_140f52ca0(CInPacket* pPacket)
{
    __int64 uidScroll = pPacket->ReadInt64();
    __int64 uidTarget = pPacket->ReadInt64();
    m_spIngredients = 0;
    m_spIngredients = new CIngredientContainer();
    if (m_spIngredients == 0)
        return;
    CIngredientContainer* pContainer = m_spIngredients.operator CIngredientContainer*();
    ((class CIngredientContainer*)(class CIngredientContainer*)(pContainer))->Read(*(class CInPacket*)(pPacket));
    MS2Ptr<CItem> spScroll = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).FindItemByUid(uidScroll);
    if (!spScroll)
        return;
    MS2Ptr<CItem> spTarget = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).FindItemByUid(uidTarget);
    if (!spTarget)
        return;
    if (m_spExchange == 0)
        return;
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    int nCount = 1;
    ASObj obj(2);
    obj.FUN_1409c0dc0("type", "upgrade");
    obj.SetIntMember("isReady", 0);
    obj.SetWStringMember("price", FUN_1409404f0(spInfo->GetTotalMeso(nCount)));
    FUN_140f514c0(&spInfo->m_requireEquip, CString("recipe"), obj, 0xc, nCount, MS2Ptr<CItem>(spTarget));
    FUN_140f514c0(&spInfo->m_exchange, CString("exchange"), obj, 6, nCount, MS2Ptr<CItem>(spTarget));
    for (unsigned __int64 i = 0; i < pContainer->FUN_14026bee0(); i++)
        WriteIngredientSlot(pContainer->FUN_14026bdc0(i).get(), Unk_SocketFormat("require{0}", i + 1), obj, 1, 1);
    m_30->Invoke("setData", obj);
    if (m_spOk.get() != 0)
        m_spOk->SetEnabled(CanExchange(nCount));
    m_uidTarget = uidTarget;
    BindDebugButtons();
}

// @0x140f53300
void UIItemExchangeScrollDialog::UpdateIngredientCounts(CInPacket* pPacket)
{
    if (m_30 == 0)
        return;
    if (m_spExchange == 0)
        return;
    MS2Ptr<ASMovieClip> spScroll(m_spScroll);
    if (spScroll == 0)
        return;
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    CIngredientContainer* pRequire = 0;
    if (spInfo->m_eType == 2)
        pRequire = m_spIngredients.get();
    else
        pRequire = &spInfo->m_require;
    if (pRequire == 0)
        return;
    int nMake = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spScroll->Invoke("getMakeCount")))->GetInt();
    for (unsigned __int64 i = 0; i < pRequire->FUN_14026bee0(); i++)
    {
        MS2Ptr<ASMovieClip> spReq = spScroll->FUN_1409b4560(Unk_SocketFormat("m_require{0}", i + 1));
        // the exe null-tests spScroll here, not spReq
        if (spScroll == 0)
            continue;
        CIngredientInfo* pIng = pRequire->FUN_14026bdc0(i).get();
        if (pIng == 0)
            continue;
        int nHave = 0;
        if (pIng->m_b != 0)
            nHave = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByTag(pIng->m_b, 0);
        else
        {
            Unk_InventoryItemKey key;
            key.m_id = pIng->GetItemId();
            key.m_extra = 1;
            nHave = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&key.m_id);
        }
        int nBase = pIng->m_c;
        int nNeed = nMake * nBase;
        CStringW strCount;
        if (nHave >= nNeed)
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
        else
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
        SetChildHtmlText(spReq->GetValue(), CString("m_name"), CStringW(strCount));
        ASObj data(spReq->GetMember("data"), 2);
        if (!data.IsUndefinedOrNull())
        {
            data.SetIntMember("itemRequireCount", nBase);
            data.SetIntMember("itemCurrentCount", nHave);
            data.SetWStringMember("name", CStringW(strCount));
        }
    }
    FUN_140f56180();
}

// @0x140f53950
void UIItemExchangeScrollDialog::SendItemExchangeScrollMode1(ASData* pData)
{
    int nCount = pData->PopInt();
    if (nCount == 0)
    {
        int nCode = 7;
        FUN_140f55670(&nCode);
        return;
    }
    int nError = GetExchangeErrorCode(nCount);
    if (nError != 0)
    {
        FUN_140f55670(&nError);
        return;
    }
    CCItemExchangeScrollPacket::ExchangeRequest req;
    req.m_uidScroll = m_uidScroll;
    req.m_uidTarget = m_uidTarget;
    req.m_nMakeCount = nCount;
    COutPacket packet(static_cast<int>(SendOp::ItemExchangeScroll), 0);
    packet.WriteUInt8(1);
    FUN_140202470(reinterpret_cast<unsigned char*>(&req), packet);
    FUN_140710590(packet);
}

// @0x140f53a70
void UIItemExchangeScrollDialog::FUN_140f53a70()
{
    m_spExchange = 0;
    CItem* pScroll = GetScrollItem();
    if (pScroll == 0)
        return;
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(pScroll->GetData()));
    if (spData == 0)
        return;
    if (spData->function.name != L"ItemExchangeScroll")
        return;
    unsigned nId = spData->function.parameter.FUN_1408d1f60(0, 0);
    m_spExchange = CItemExchangeScrollTable::GetInstance()->GetData(nId);
}

// @0x140f53bb0
void UIItemExchangeScrollDialog::FUN_140f53bb0(ASObj& obj, CExchangeItemInfo* pInfo)
{
    if (pInfo == 0)
        return;
    int nMax = GetMaxMakeCount();
    nMax = nMax > 1 ? nMax : 1;
    int nMin = 1;
    int nDefault = Clamp(1, nMin, nMax);
    if (pInfo->GetTotalMeso(1) == 0)
        nDefault = nMax;
    obj.FUN_1409c0dc0("type", "exchange");
    FUN_140f514c0(&pInfo->m_receipe, CString("recipe"), obj, 0x11, nDefault, MS2Ptr<CItem>(0));
    FUN_140f514c0(&pInfo->m_exchange, CString("exchange"), obj, 2, nDefault, MS2Ptr<CItem>(0));
    for (unsigned __int64 i = 0; i < pInfo->m_require.FUN_14026bee0(); i++)
        WriteIngredientSlot(pInfo->m_require.FUN_14026bdc0(i).get(), Unk_SocketFormat("require{0}", i + 1), obj, 1, nDefault);
    obj.SetWStringMember("price", FUN_1409404f0(pInfo->GetTotalMeso(nDefault)));
    obj.SetIntMember("itemMaxCount", nMax);
    obj.SetIntMember("itemMinCount", nMin);
    obj.SetIntMember("itemDefaultCount", nDefault);
    ASFunction fn(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f54a20), 0,
                  FUN_1422db730());
    obj.FUN_1409adbe0("updateCountFunction", Scaleform::GFx::Value(fn.GetValue()));
    bool bInput = false;
    MS2Ptr<CItemData> spData = FUN_14053f870(pInfo->m_exchange.m_nId);
    if ((bool)spData.get() && (unsigned)spData->GetSlotMax() > 1)
        bInput = true;
    obj.SetBoolMember("enableInputCount", bInput);
}

// @0x140f54120
void UIItemExchangeScrollDialog::FUN_140f54120(ASObj& obj, CExchangeItemInfo* pInfo)
{
    if (pInfo == 0)
        return;
    int nCount = 1;
    obj.FUN_1409c0dc0("type", "upgrade");
    obj.SetIntMember("isReady", 1);
    obj.SetWStringMember("price", FUN_1409404f0(pInfo->GetTotalMeso(nCount)));
    FUN_140f514c0(&pInfo->m_requireEquip, CString("recipe"), obj, 0xc, nCount, MS2Ptr<CItem>(0));
    FUN_140f514c0(&pInfo->m_exchange, CString("exchange"), obj, 6, nCount, MS2Ptr<CItem>(0));
    CStringW strNotify = FUN_14028dfa0<CStringW>(CStringW(L"s_itemslot_exchange_upgrade_notify"),
                                       TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, pInfo->m_requireEquip.m_nId));
    ((class CReservedWordTable*)(void*)(((void*)TSingleton<CReservedWordTable>::GetInstance())))->ReplaceObjectAndValueWords(strNotify);
    obj.SetWStringMember("warning", FUN_14028dfa0(CStringW(L"s_itemslot_exchange_upgrade_warning"), pInfo->m_nMaxGrade));
    obj.SetWStringMember("notify", CStringW(strNotify));
}

// @0x140f544d0
void UIItemExchangeScrollDialog::FUN_140f544d0(ASObj& obj, CExchangeItemInfo* pInfo)
{
    if (pInfo == 0)
        return;
    int nMax = GetMaxMakeCount();
    nMax = nMax > 1 ? nMax : 1;
    int nMin = 1;
    int nDefault = Clamp(1, nMin, nMax);
    obj.FUN_1409c0dc0("type", "trading");
    FUN_140f514c0(&pInfo->m_receipe, CString("recipe"), obj, 0x11, nDefault, MS2Ptr<CItem>(0));
    FUN_140f514c0(&pInfo->m_exchange, CString("exchange"), obj, 2, nDefault, MS2Ptr<CItem>(0));
    for (unsigned __int64 i = 0; i < pInfo->m_require.FUN_14026bee0(); i++)
        WriteIngredientSlot(pInfo->m_require.FUN_14026bdc0(i).get(), Unk_SocketFormat("require{0}", i + 1), obj, 1, nDefault);
    obj.SetWStringMember("price", FUN_1409404f0(pInfo->GetTotalMeso(nDefault)));
    obj.SetIntMember("itemMaxCount", nMax);
    obj.SetIntMember("itemMinCount", nMin);
    obj.SetIntMember("itemDefaultCount", nDefault);
    ASFunction fn(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f54a20), 0,
                  FUN_1422db730());
    obj.FUN_1409adbe0("updateCountFunction", Scaleform::GFx::Value(fn.GetValue()));
    bool bInput = false;
    MS2Ptr<CItemData> spData = FUN_14053f870(pInfo->m_exchange.m_nId);
    if ((bool)spData.get() && (unsigned)spData->GetSlotMax() > 1)
        bInput = true;
    obj.SetBoolMember("enableInputCount", bInput);
}

// @0x140f54a20
void UIItemExchangeScrollDialog::FUN_140f54a20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (reinterpret_cast<const Unk_IesParams&>(params).m_nArgs < 3)
        return;
    if (m_spExchange == 0)
        return;
    AScript argMake(reinterpret_cast<const Unk_IesParams&>(params).m_pArgs[0], 2);
    if (argMake.IsUndefinedOrNull())
        return;
    ASArray argList(reinterpret_cast<const Unk_IesParams&>(params).m_pArgs[1], 2);
    if (argList.IsUndefinedOrNull())
        return;
    AScript argSlot(reinterpret_cast<const Unk_IesParams&>(params).m_pArgs[2], 2);
    if (argSlot.IsUndefinedOrNull())
        return;
    int nMake = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(argMake.GetValue()))->GetInt();
    int nLen = argList.GetLength();
    bool bEnough = true;
    for (int i = 0; i < nLen; i++)
    {
        ASObj item(argList.GetElement(i), 2);
        if (item.IsUndefinedOrNull())
            continue;
        ASObj data(item.GetMember("data"), 2);
        if (data.IsUndefinedOrNull())
            continue;
        int nBase = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(data.GetMember("itemRequireCount")))->GetInt();
        int nHave = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(data.GetMember("itemCurrentCount")))->GetInt();
        int nNeed = nBase * nMake;
        CStringW strCount;
        if (nHave >= nNeed)
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
        else
        {
            bEnough = false;
            strCount = FUN_14028dfa0<int, int>(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
        }
        SetChildHtmlText(item.GetValue(), CString("m_name"), CStringW(strCount));
    }
    MS2Ptr<ASMovieClip> spSlot = argSlot.FUN_1409b4560("slot");
    if (spSlot.get() != 0)
    {
        static_cast<Unk_IesChild*>(spSlot.operator->())->Invoke("updateItemCount", m_spExchange->m_exchange.m_nCount * nMake);
    }
    if (m_spOk.get() != 0)
    {
        __int64 nMeso = m_spExchange->GetTotalMeso(nMake);
        bool bPay = DAT_143ab2898 >= nMeso;
        m_spOk->SetEnabled(bPay && bEnough);
        m_spOk->FUN_1422cdfb0(FUN_1409404f0(nMeso));
    }
}

// @0x140f55190
unsigned UIItemExchangeScrollDialog::GetMakeCount()
{
    if (m_spScroll == 0)
        return 0;
    return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_spScroll->Invoke("getMakeCount")))->GetInt();
}

// @0x140f55220
int UIItemExchangeScrollDialog::GetMaxMakeCount()
{
    CItem* pScroll = GetScrollItem();
    if (pScroll == 0)
        return 0;
    if (m_spExchange == 0)
        return 0;
    int nMax = 0;
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    const Unk_ExchangeItemRef* pRecipe = &spInfo->m_receipe;
    Unk_InventoryItemKey key;
    key.m_id = pRecipe->m_nId;
    key.m_extra = 1;
    int nHave = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&key.m_id);
    int nNeed = pRecipe->m_nCount;
    int nCraft = nNeed > 0 ? nHave / nNeed : 0;
    nMax = nCraft;
    unsigned __int64 nRequire = spInfo->m_require.FUN_14026bee0();
    if (nRequire > 0)
    {
        int nMin = nMax;
        for (unsigned __int64 i = 0; i < nRequire; i++)
        {
            Unk_IngRef ref = spInfo->m_require.FUN_14026bdc0(i);
            if (ref == 0)
                continue;
            int nHaveIng = 0;
            if (ref->m_b != 0)
                nHaveIng = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByTag(ref->m_b, 0);
            else
            {
                Unk_InventoryItemKey ingKey;
                ingKey.m_id = ref->GetItemId();
                ingKey.m_extra = 1;
                nHaveIng = reinterpret_cast<Unk_IesInventory&>(g_143ab2a90).GetItemCountByFilter(&ingKey.m_id);
            }
            int nNeedIng = ref->m_c;
            nMin = nNeedIng > 0 ? nHaveIng / nNeedIng : 0;
            nMax = nMax < nMin ? nMax : nMin;
        }
    }
    __int64 nPrice = m_spExchange->GetMeso();
    __int64 nTotal = nPrice * nMax;
    if (nPrice > 0 && DAT_143ab2898 < nTotal)
        nMax = (int)((__int64)nMax < DAT_143ab2898 / nPrice ? (__int64)nMax : DAT_143ab2898 / nPrice);
    int nStack = 0;
    int nUnit = spInfo->m_exchange.m_nCount;
    MS2Ptr<CItemData> spData = FUN_14053f870(spInfo->m_exchange.m_nId);
    if (spData.get() != 0)
    {
        if (nUnit > 1)
            nStack = spData->GetSlotMax() / (unsigned)nUnit;
        else
            nStack = spData->GetSlotMax();
    }
    nMax = nStack < nMax ? nStack : nMax;
    return nMax;
}

// @0x140f55670
bool UIItemExchangeScrollDialog::FUN_140f55670(const int* pCode)
{
    if (*pCode == 0)
    {
        {
            CStringW strKey(L"s_itemslot_exchange_ok");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        return false;
    }
    switch (*pCode)
    {
    case 1:
        {
            CStringW strKey(L"s_itemslot_exchange_scroll_invalid");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 2:
        {
            CStringW strKey(L"s_itemslot_exchange_upgrade_invalid");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 6:
        {
            CStringW strKey(L"s_itemslot_exchange_lockstate_item");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 3:
        {
            CStringW strKey(L"s_itemslot_exchange_money_invalid");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 4:
        {
            CStringW strKey(L"s_itemslot_exchange_count_invalid");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 5:
        {
            CStringW strKey(L"s_itemslot_exchange_grade_invalid");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 8:
        {
            CStringW strKey(L"s_itemslot_exchange_unknown");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    case 7:
        {
            CStringW strKey(L"s_itemslot_exchange_count_check");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
        break;
    default:
        {
            CStringW strKey(L"s_itemslot_exchange_unknown");
            ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
        }
    }
    return true;
}

// @0x140f55b90
void UIItemExchangeScrollDialog::FUN_140f55b90(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (DAT_143ab2914 < 0x32)
        return;
    {
        CCItemExchangeScrollPacket::ForceFillIngredient fill;
        fill.m_uidScroll = m_uidScroll;
        fill.m_uidTarget = m_uidTarget;
        fill.m_nCount = 0;
        COutPacket packet(static_cast<int>(SendOp::ItemExchangeScroll), 0);
        packet.WriteUInt8(3);
        FUN_140202580(reinterpret_cast<unsigned char*>(&fill), packet);
        FUN_140710590(packet);
    }
}

// @0x140f55c50
void UIItemExchangeScrollDialog::FUN_140f55c50(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (DAT_143ab2914 < 0x32)
        return;
    {
        CCItemExchangeScrollPacket::ForceFillIngredient fill;
        fill.m_uidScroll = m_uidScroll;
        fill.m_uidTarget = m_uidTarget;
        fill.m_nCount = 10;
        COutPacket packet(static_cast<int>(SendOp::ItemExchangeScroll), 0);
        packet.WriteUInt8(3);
        FUN_140202580(reinterpret_cast<unsigned char*>(&fill), packet);
        FUN_140710590(packet);
    }
}

// @0x140f55d10
void UIItemExchangeScrollDialog::BindDebugButtons()
{
    bool bDebug = ((class CInputKeyHandler*)FUN_14025e7c0())->IsDebugMode();
    if (!bDebug)
        return;
    if (m_spExchange == 0)
        return;
    if (m_spExchange->m_eType == 2)
    {
        if (m_spIngredients == 0 || m_spIngredients->IsEmpty())
            return;
    }
    else if (m_spExchange->m_require.IsEmpty())
        return;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    MS2Ptr<ASMovieClip> spScroll(m_spScroll);
    if (spScroll.get() != 0)
    {
        m_spDebugAddMax = spScroll->FUN_140acce30<ASButton>("m_debugAddMax");
        if (m_spDebugAddMax.get() != 0)
        {
            m_spDebugAddMax->vfunc_4(bDebug);
            m_spDebugAddMax->AddClickHandler(
                Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f55b90), 0);
        }
        m_spDebugAdd10 = spScroll->FUN_140acce30<ASButton>("m_debugAdd10");
        if (m_spDebugAdd10.get() != 0)
        {
            m_spDebugAdd10->vfunc_4(bDebug);
            m_spDebugAdd10->AddClickHandler(
                Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f55c50), 0);
        }
    }
}

// @0x140f56180
void UIItemExchangeScrollDialog::FUN_140f56180()
{
    if (m_30 == 0 || m_spScroll == 0)
        return;
    int nMax = GetMaxMakeCount();
    nMax = nMax > 1 ? nMax : 1;
    ASObj obj(2);
    obj.SetIntMember("itemMaxCount", nMax);
    m_spScroll->Invoke("updateData", obj.GetValue());
    if (m_spOk.get() != 0)
    {
        unsigned nMake = GetMakeCount();
        m_spOk->SetEnabled(CanExchange(nMake));
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9ac0-0x142ca9af0 .text$yd
