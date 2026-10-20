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
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/commonfiles/item.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// A button of the movie.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(unsigned int bEnabled);          // enable / disable
    void FUN_1422cdfb0(const CStringW& strLabel);       // set the label
    void FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, size_t n);   // click handler
};

// The AS function object calling back into C++ (ctor 0x1422c8430, dtor 0x1422c85b0).
class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int nUser, int nMovieId);
    ~ASFunction();
private:
    void* m_40;
};

// The inventory (global 0x143ab2a90) and the key of its count queries (id, kind 1 = by item id).
struct Unk_IesCountKey
{
    unsigned m_nId;
    unsigned m_pad_04;
    unsigned m_nKind;
    unsigned m_pad_0c;
};
void FUN_140bb5a30(Unk_IesCountKey* pKey);              // zero it
class Unk_IesInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nUid);
    int FUN_140a5eda0(Unk_IesCountKey* pKey);           // how many items match
    int FUN_140a5f780(int nTypeId, int n);              // how many items of the type
};
extern Unk_IesInventory DAT_143ab2a90;
extern __int64 DAT_143ab2898;                           // the player's mesos
extern int DAT_143ab2914;                               // the build level (> 0x31: debug commands)


CGameEventValueManager* FUN_140302b00();                            // TSingleton<CGameEventValueManager>::GetInstance
unsigned FUN_140428cb0(Unk_GameEventLockedValue<0x78>* pSale, unsigned long nItemId);   // the sale rate (percent) of the scroll item

// Dialog child lookups.
class Unk_IesEntity : public UIDialog
{
public:
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);
};

// The debug key state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d720(); };
Unk_14025e7c0* FUN_14025e7c0();

// The status listener registry.
class Unk_IesStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);           // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);           // unregister
};
Unk_IesStatusMgr* FUN_140aa6d40();

// The string table (item names).
class Unk_IesStrTable { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_IesStrTable* FUN_1401a9d70();

// AS views.
class Unk_IesChild : public ASMovieClip
{
public:
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int n);     // call a method with one int
};
class Unk_IesArray : public ASArray
{
public:
    Scaleform::GFx::Value FUN_1422bc6b0(int nIndex);                      // element
};
struct Unk_IesParams                                                      // Scaleform FunctionHandler::Params
{
    void* m_pad_00[4];
    Scaleform::GFx::Value* m_pArgs;                                       // +0x20
    unsigned m_nArgs;                                                     // +0x28
};

// Helpers of other units.
int FUN_1409c1750(const Scaleform::GFx::Value& v);                  // the value as int
void FUN_140cff1b0(Scaleform::GFx::Value& v, CString strName, CStringW strText);   // set the text of a child field
void FUN_141415600(const CString& strKey);                          // release the item bound to the key
void FUN_141415560(const CString& strKey, ItemInfoSlot::CreateParam* pParam);      // bind an item slot
void FUN_140165270(ATL::CAtlArray<CString>& arr, const CString& str);              // append
void FUN_140b6c7a0(const CString& strName, __int64 nTarget, MS2Ptr<CItem> spItem);  // create the drag slot
void FUN_140b6c890(const CString& strName);                         // drop the drag slot
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // the item data of an id
int FUN_14053feb0(unsigned nItemId);                                // the default rank of an item
int FUN_140ad0d60(int a, int b, int nMax);                          // clamp
CStringW FUN_1409e8970(CStringW strKey, const int& nHave, const int& nNeed);   // "have/need" text
CStringW FUN_14042cb90(CStringW strKey, const float& v);
CStringW FUN_140938ae0(CStringW strKey, const int* pValue);
CStringW FUN_14062b4f0(CStringW strKey, const int* pValue);
CStringW FUN_1409404f0(__int64 nMeso);                              // meso text
CStringW FUN_14028b8e0(const CStringW& strKey);                     // string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
void FUN_1412751f0(const CStringW& strText, int a, int b);          // show a notice
void FUN_1416fb300(void* pFilter, CStringW& strText);               // filter a script text
void* FUN_1403b4750();                                              // the script text filter
void FUN_140710590(COutPacket& packet);                             // send
void FUN_140202470(unsigned char* pRecord, COutputStream& out);     // encode an ExchangeRequest
void FUN_140202580(unsigned char* pRecord, COutputStream& out);     // encode a ForceFillIngredient
void FUN_14026c0b0(CIngredientContainer* pContainer, CInPacket* pPacket);   // decode the ingredients
bool FUN_140534e50(MS2Ptr<CItem>* pItem);                           // the item is expired / unusable
int FUN_1422db730();

using ATL::CAtlArray;

// @0x1400dff60
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140f50d60
UIItemExchangeScrollDialog::UIItemExchangeScrollDialog()
{
    FUN_141924170(1);
    m_uidScroll = 0;
    m_uidTarget = 0;
}

// @0x140f50eb0
CString UIItemExchangeScrollDialog::vfunc_1()
{
    return "ItemExchangeScrollDialog";
}

// @0x140f50f00
// MS2-FUNCTIONAL: not byte-matched yet
int UIItemExchangeScrollDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() != 0)
        return 1;
    else
        return 0;
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
        FUN_141415600(m_infoKeys[i]);
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
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x140f51150
void UIItemExchangeScrollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_spOk = GetChild<Unk_140acd6e0>("m_ok");
    FUN_140f53a70();
    FUN_140f52880();
    m_spScroll = GetChild<ASMovieClip>("m_scroll");
    FUN_140f55d10();
}

// @0x140f51280
int UIItemExchangeScrollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140f53950(&data);
        return 1;
    }
    return 0;
}

// @0x140f51350
void UIItemExchangeScrollDialog::vfunc_15()
{
}

// @0x140f51360
// MS2-FUNCTIONAL: not byte-matched yet
void UIItemExchangeScrollDialog::vfunc_79(void* p)
{
    CInPacket* pkt = (CInPacket*)p;
    UIDialog::vfunc_79(p);
    if (pkt->FUN_14070fe80() == 0x102)
    {
        unsigned char kind = pkt->vfunc_o8_1();
        if (kind == 0)
            FUN_140f52ca0(pkt);
        else if (kind == 2)
        {
            unsigned nCode = (unsigned short)pkt->vfunc_o8_2();
            int nResult = (int)nCode;
            if (!FUN_140f55670(&nResult))
                vfunc_67();
        }
        else if (kind == 3)
            FUN_140f53300(pkt);
    }
}

// @0x140f51460
void UIItemExchangeScrollDialog::vfunc_oa0_11(void* p)
{
    FUN_140f56180();
}

// @0x140f51490
void UIItemExchangeScrollDialog::FUN_140f51490(CItem* pScroll)
{
    m_uidScroll = pScroll->FUN_140526a50();
}

// @0x140f514c0
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f514c0(const Unk_ExchangeItemRef* pRef, CString strKey, ASObj& obj, unsigned char nFlags, int nMul,
                                               MS2Ptr<CItem> spCur)
{
    if (!(nFlags & 1) || pRef->m_nCount != 0)
    {
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(pRef->m_nId, pRef->m_nRank, 0) != 0)
        {
            if (!(nFlags & 0x10))
            {
                int nCount = pRef->m_nCount * nMul;
                spItem->FUN_140526c70(nCount);
            }
            else
                spItem->FUN_140526c70(0);
            ASObj slot(2);
            ItemInfoSlot::CreateParam param;
            param.m_spItem = spItem;
            param.m_nIconType = 0x415;
            if (nFlags & 2)
                param.m_nFlags = 0x800;
            CStringW strText;
            if (!(nFlags & 1))
            {
                int nBase = pRef->m_nCount;
                int nCount = nMul * nBase;
                param.m_strCount = StringFormat("{0}", nCount);
                strText = spItem->FUN_140528160();
                if (spCur.get() != 0)
                {
                    int nLevel = spCur->FUN_140526fc0();
                    spItem->FUN_140526e60(nLevel, 0);
                    if (spItem->FUN_1405278a0() != 0)
                    {
                        CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0());
                        if (pStatus->FUN_140630d60() != 0)
                        {
                            if (spCur->FUN_140527030() != 0)
                                reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->FUN_140630d60()->FUN_14058c870();
                        }
                    }
                    CItemStatus* pSrc = reinterpret_cast<CItemStatus*>(spCur->FUN_1405278a0());
                    reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->FUN_1406308a0(MS2Ptr<CItemStatus>(pSrc));
                }
            }
            else
            {
                Unk_IesCountKey key;
                FUN_140bb5a30(&key);
                key.m_nId = pRef->m_nId;
                key.m_nKind = 1;
                int nHave = DAT_143ab2a90.FUN_140a5eda0(&key);
                int nBase = pRef->m_nCount;
                int nNeed = nMul * nBase;
                CStringW strCount;
                if (nHave < nNeed)
                    strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
                else
                    strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
                strText = strCount;
                slot.FUN_1407cb9c0("itemRequireCount", nBase);
                slot.FUN_1407cb9c0("itemCurrentCount", nHave);
            }
            CString strBind;
            if (!(nFlags & 8))
            {
                unsigned __int64 n = m_infoKeys.GetCount();
                strBind.Format("%s_info_%d", (const char*)vfunc_1(), n);
                FUN_141415560(strBind, &param);
                FUN_140165270(m_infoKeys, strBind);
            }
            else
            {
                unsigned __int64 n = m_dragKeys.GetCount();
                strBind.Format("%s_drag_%d", (const char*)vfunc_1(), n);
                FUN_140b6c7a0(strBind, m_uidScroll, MS2Ptr<CItem>(spCur));
                FUN_140165270(m_dragKeys, strBind);
            }
            if (nFlags & 4)
            {
                MS2Ptr<CItemData> spData = FUN_14053f870(pRef->m_nId);
                if (spData.get() != 0)
                {
                    const int* pLevel = reinterpret_cast<const int*>(reinterpret_cast<char*>(spData.get()) + 0x138);
                    slot.FUN_1407cbb20("level", FUN_140938ae0(CStringW(L"s_itemslot_exchange_level"), pLevel));
                }
            }
            slot.FUN_1407cba60("binding", CString(strBind));
            slot.FUN_1407cbb20("name", CStringW(strText));
            obj.FUN_1409eb270(strKey, slot);
        }
    }
}

// @0x140f51e90
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f51e90(CIngredientInfo* pIng, CString strKey, ASObj& obj, unsigned char nFlags, int nMul)
{
    MS2Ptr<CItem> spItem(new CItem());
    int nRank = FUN_14053feb0(pIng->FUN_14026b500());
    if (spItem->FUN_14052b130(pIng->FUN_14026b500(), nRank, 0) != 0)
    {
        ItemInfoSlot::CreateParam param;
        param.m_spItem = spItem;
        param.m_nIconType = 0x415;
        if (nFlags & 2)
            param.m_nFlags = 0x800;
        ASObj slot(2);
        CStringW strText;
        if (!(nFlags & 1))
        {
            int nBase = pIng->m_c;
            int nCount = nBase * nMul;
            param.m_strCount = StringFormat("{0}", nCount);
            strText = spItem->FUN_140528160();
            spItem->FUN_140526c70(nCount);
        }
        else
        {
            int nHave = 0;
            if (pIng->m_b == 0)
            {
                Unk_IesCountKey key;
                FUN_140bb5a30(&key);
                key.m_nId = pIng->FUN_14026b500();
                key.m_nKind = 1;
                nHave = DAT_143ab2a90.FUN_140a5eda0(&key);
            }
            else
                nHave = DAT_143ab2a90.FUN_140a5f780(pIng->m_b, 0);
            int nBase = pIng->m_c;
            int nNeed = nMul * nBase;
            CStringW strCount;
            if (nHave < nNeed)
                strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
            else
                strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
            strText = strCount;
            param.m_nIconType = 0x405;
            slot.FUN_1407cb9c0("itemRequireCount", nBase);
            slot.FUN_1407cb9c0("itemCurrentCount", nHave);
        }
        CString strBind;
        unsigned __int64 n = m_infoKeys.GetCount();
        strBind.Format("%s_info_%d", (const char*)vfunc_1(), n);
        FUN_141415560(strBind, &param);
        FUN_140165270(m_infoKeys, strBind);
        slot.FUN_1407cba60("binding", CString(strBind));
        slot.FUN_1407cbb20("name", CStringW(strText));
        obj.FUN_1409eb270(strKey, slot);
    }
}

// @0x140f524d0
bool UIItemExchangeScrollDialog::FUN_140f524d0(unsigned nCount)
{
    int nError = FUN_140f52520(nCount);
    return nError == 0;
}

// @0x140f52520
// MS2-FUNCTIONAL: operator-> temporaries differ
unsigned UIItemExchangeScrollDialog::FUN_140f52520(unsigned nCount)
{
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    if (spInfo == 0)
        return 1;
    CExchangeItemInfo* pRequire = spInfo.operator->();
    CExchangeItemInfo* pRecipe = spInfo.operator->();
    __int64 nMeso = spInfo->GetMeso();
    return FUN_140f52610(nMeso, &pRecipe->m_receipe, &pRequire->m_require, nCount);
}

// @0x140f52610
// MS2-FUNCTIONAL: not byte-matched yet
unsigned UIItemExchangeScrollDialog::FUN_140f52610(__int64 nMeso, const Unk_ExchangeItemRef* pRecipe, CIngredientContainer* pRequire, unsigned nCount)
{
    if (nMeso < 1 || (__int64)(nMeso * (unsigned __int64)nCount) <= DAT_143ab2898)
    {
        Unk_IesCountKey key;
        FUN_140bb5a30(&key);
        key.m_nId = pRecipe->m_nId;
        key.m_nKind = 1;
        int nNeed = pRecipe->m_nCount * nCount;
        if (DAT_143ab2a90.FUN_140a5eda0(&key) < nNeed)
            return 1;
        for (unsigned __int64 i = 0; i < pRequire->FUN_14026bf10(); i++)
        {
            Unk_IngRef ref = pRequire->FUN_14026be50(i);
            if (!(ref == 0))
            {
                int nNeedIng = ref->m_c * nCount;
                if (ref->m_b == 0)
                {
                    Unk_IesCountKey ingKey;
                    FUN_140bb5a30(&ingKey);
                    ingKey.m_nId = ref->FUN_14026b500();
                    ingKey.m_nKind = 1;
                    if (DAT_143ab2a90.FUN_140a5eda0(&ingKey) < nNeedIng)
                        return 4;
                }
                else
                {
                    if (DAT_143ab2a90.FUN_140a5f780(ref->m_b, 0) < nNeedIng)
                        return 4;
                }
            }
        }
        return 0;
    }
    return 3;
}

// @0x140f52810
CItem* UIItemExchangeScrollDialog::FUN_140f52810()
{
    return DAT_143ab2a90.FUN_140a5d680(m_uidScroll).get();
}

// @0x140f52880
// MS2-FUNCTIONAL: not byte-matched yet
void UIItemExchangeScrollDialog::FUN_140f52880()
{
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    if (spInfo == 0)
        return;
    ASObj obj(2);
    bool bEnable = false;
    CStringW strTitle;
    int nType = spInfo->m_eType;
    if (nType == 1)
    {
        FUN_140f53bb0(obj, spInfo.get());
        bEnable = FUN_140f524d0(1);
        strTitle = L"$s_item_exchange_title";
    }
    else if (nType == 2)
    {
        FUN_140f54120(obj, spInfo.get());
        bEnable = false;
        strTitle = L"$s_item_exchange_upgrade_title";
    }
    else if (nType == 3)
    {
        FUN_140f544d0(obj, spInfo.get());
        bEnable = FUN_140f524d0(1);
        strTitle = L"$s_item_exchange_trading_title";
    }
    unsigned nItemId = spInfo->m_nId;
    unsigned nSale = FUN_140428cb0(FUN_140302b00()->GetExchangeScrollSale(), nItemId);
    CStringW strSale;
    if (nSale != 0)
    {
        float fRate = (float)nSale / 100.0f;
        strSale = FUN_14042cb90(CStringW(L"s_itemslot_exchange_money_sale_desc"), fRate);
    }
    obj.FUN_1407cbb20("event", CStringW(strSale));
    m_30->Invoke("setData", obj);
    if (m_spOk.get() != 0)
        m_spOk->FUN_1422c1fe0(bEnable);
    MS2Ptr<ASTextField> spTitle = ((Unk_IesEntity*)this)->FUN_140bb4cf0(CString("m_title"));
    if (spTitle.get() != 0)
        spTitle->FUN_1422c4cd0(strTitle);
}

// @0x140f52c80
void UIItemExchangeScrollDialog::FUN_140f52c80()
{
    FUN_140f52880();
}

// @0x140f52ca0
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f52ca0(CInPacket* pPacket)
{
    __int64 uidScroll = pPacket->vfunc_o8_4();
    __int64 uidTarget = pPacket->vfunc_o8_4();
    m_spIngredients = 0;
    m_spIngredients = new CIngredientContainer();
    if (!(m_spIngredients == 0))
    {
        CIngredientContainer* pContainer = m_spIngredients.operator CIngredientContainer*();
        FUN_14026c0b0(pContainer, pPacket);
        MS2Ptr<CItem> spScroll = DAT_143ab2a90.FUN_140a5d680(uidScroll);
        if (!FUN_140534e50(&spScroll))
        {
            MS2Ptr<CItem> spTarget = DAT_143ab2a90.FUN_140a5d680(uidTarget);
            if (!FUN_140534e50(&spTarget))
            {
                if (!(m_spExchange == 0))
                {
                    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
                    ASObj obj(2);
                    obj.FUN_1409c0dc0("type", "upgrade");
                    obj.FUN_1407cb9c0("isReady", 0);
                    obj.FUN_1407cbb20("price", FUN_1409404f0(spInfo->GetTotalMeso(1)));
                    FUN_140f514c0(&spInfo->m_requireEquip, CString("recipe"), obj, 0xc, 1, MS2Ptr<CItem>(spTarget));
                    FUN_140f514c0(&spInfo->m_exchange, CString("exchange"), obj, 6, 1, MS2Ptr<CItem>(spTarget));
                    for (unsigned __int64 i = 0; i < pContainer->FUN_14026bee0(); i++)
                    {
                        CString strKey = StringFormat("require{0}", i + 1);
                        Unk_IngRef ref = pContainer->FUN_14026bdc0(i);
                        FUN_140f51e90(ref.FUN_14027f250(), strKey, obj, 1, 1);
                    }
                    m_30->Invoke("setData", obj);
                    if (m_spOk.get() != 0)
                    {
                        bool bEnable = FUN_140f524d0(1);
                        m_spOk->FUN_1422c1fe0(bEnable);
                    }
                    m_uidTarget = uidTarget;
                    FUN_140f55d10();
                }
            }
        }
    }
}

// @0x140f53300
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f53300(CInPacket* pPacket)
{
    if (!(m_30 == 0) && !(m_spExchange == 0))
    {
        MS2Ptr<ASMovieClip> spScroll(m_spScroll);
        if (!(spScroll == 0))
        {
            MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
            CIngredientContainer* pRequire = 0;
            if (spInfo->m_eType == 2)
                pRequire = m_spIngredients.get();
            else
                pRequire = &spInfo->m_require;
            if (pRequire != 0)
            {
                int nMake = FUN_1409c1750(spScroll->Invoke("getMakeCount"));
                for (unsigned __int64 i = 0; i < pRequire->FUN_14026bee0(); i++)
                {
                    CString strName = StringFormat("m_require{0}", i + 1);
                    MS2Ptr<ASMovieClip> spReq = spScroll->FUN_1409b4560(strName);
                    if (!(spReq == 0))
                    {
                        Unk_IngRef ref = pRequire->FUN_14026bdc0(i);
                        CIngredientInfo* pIng = ref.FUN_14027f250();
                        if (pIng != 0)
                        {
                            int nHave = 0;
                            if (pIng->m_b == 0)
                            {
                                Unk_IesCountKey key;
                                FUN_140bb5a30(&key);
                                key.m_nId = pIng->FUN_14026b500();
                                key.m_nKind = 1;
                                nHave = DAT_143ab2a90.FUN_140a5eda0(&key);
                            }
                            else
                                nHave = DAT_143ab2a90.FUN_140a5f780(pIng->m_b, 0);
                            int nBase = pIng->m_c;
                            int nNeed = nMake * nBase;
                            CStringW strCount;
                            if (nHave < nNeed)
                                strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
                            else
                                strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
                            FUN_140cff1b0(spReq->FUN_1422bb870(), CString("m_name"), CStringW(strCount));
                            Scaleform::GFx::Value vData = spReq->FUN_1422baa20("data");
                            ASObj data(vData, 2);
                            if (!data.FUN_1422ba9a0())
                            {
                                data.FUN_1407cb9c0("itemRequireCount", nBase);
                                data.FUN_1407cb9c0("itemCurrentCount", nHave);
                                data.FUN_1407cbb20("name", CStringW(strCount));
                            }
                        }
                    }
                }
                FUN_140f56180();
            }
        }
    }
}

// @0x140f53950
// MS2-FUNCTIONAL: not byte-matched yet
void UIItemExchangeScrollDialog::FUN_140f53950(ASData* pData)
{
    int nCount = pData->FUN_1422b8a10();
    if (nCount == 0)
    {
        int nCode = 7;
        FUN_140f55670(&nCode);
    }
    else
    {
        int nError = FUN_140f52520(nCount);
        if (nError == 0)
        {
            CCItemExchangeScrollPacket::ExchangeRequest req;
            req.m_uidScroll = m_uidScroll;
            req.m_uidTarget = m_uidTarget;
            req.m_nMakeCount = nCount;
            COutPacket packet(0x9b, 0);
            packet.vfunc_o10_1(1);
            FUN_140202470(reinterpret_cast<unsigned char*>(&req), packet);
            FUN_140710590(packet);
        }
        else
            FUN_140f55670(&nError);
    }
}

// @0x140f53a70
// MS2-FUNCTIONAL: not byte-matched yet
void UIItemExchangeScrollDialog::FUN_140f53a70()
{
    m_spExchange = 0;
    CItem* pScroll = FUN_140f52810();
    if (pScroll != 0)
    {
        MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(pScroll->FUN_140527840()));
        if (!(spData == 0))
        {
            if (!(spData->function.name != L"ItemExchangeScroll"))
            {
                unsigned nId = spData->function.parameter.FUN_1408d1f60(0, 0);
                m_spExchange = CItemExchangeScrollTable::GetInstance()->GetData(nId);
            }
        }
    }
}

// @0x140f53bb0
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f53bb0(ASObj& obj, CExchangeItemInfo* pInfo)
{
    if (pInfo != 0)
    {
        int nMax = FUN_140f55220();
        if (nMax < 2)
            nMax = 1;
        int nDefault = FUN_140ad0d60(1, 1, nMax);
        if (pInfo->GetTotalMeso(1) == 0)
            nDefault = nMax;
        obj.FUN_1409c0dc0("type", "exchange");
        FUN_140f514c0(&pInfo->m_receipe, CString("recipe"), obj, 0x11, nDefault, MS2Ptr<CItem>(0));
        FUN_140f514c0(&pInfo->m_exchange, CString("exchange"), obj, 2, nDefault, MS2Ptr<CItem>(0));
        for (unsigned __int64 i = 0; i < pInfo->m_require.FUN_14026bee0(); i++)
        {
            CString strKey = StringFormat("require{0}", i + 1);
            Unk_IngRef ref = pInfo->m_require.FUN_14026bdc0(i);
            FUN_140f51e90(ref.FUN_14027f250(), strKey, obj, 1, nDefault);
        }
        obj.FUN_1407cbb20("price", FUN_1409404f0(pInfo->GetTotalMeso(nDefault)));
        obj.FUN_1407cb9c0("itemMaxCount", nMax);
        obj.FUN_1407cb9c0("itemMinCount", 1);
        obj.FUN_1407cb9c0("itemDefaultCount", nDefault);
        ASFunction fn(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f54a20), 0,
                      FUN_1422db730());
        obj.FUN_1409adbe0("updateCountFunction", Scaleform::GFx::Value(fn.FUN_1422bb870()));
        bool bInput = false;
        MS2Ptr<CItemData> spData = FUN_14053f870(pInfo->m_exchange.m_nId);
        if (spData.get() != 0)
        {
            if (1 < spData->FUN_14053de60())
                bInput = true;
        }
        obj.FUN_1407cbbe0("enableInputCount", bInput);
    }
}

// @0x140f54120
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f54120(ASObj& obj, CExchangeItemInfo* pInfo)
{
    if (pInfo != 0)
    {
        obj.FUN_1409c0dc0("type", "upgrade");
        obj.FUN_1407cb9c0("isReady", 1);
        obj.FUN_1407cbb20("price", FUN_1409404f0(pInfo->GetTotalMeso(1)));
        FUN_140f514c0(&pInfo->m_requireEquip, CString("recipe"), obj, 0xc, 1, MS2Ptr<CItem>(0));
        FUN_140f514c0(&pInfo->m_exchange, CString("exchange"), obj, 6, 1, MS2Ptr<CItem>(0));
        CStringW strNotify = FUN_1405c2690(CStringW(L"s_itemslot_exchange_upgrade_notify"),
                                           FUN_1401a9d70()->FUN_141811980(1, pInfo->m_requireEquip.m_nId));
        FUN_1416fb300(FUN_1403b4750(), strNotify);
        obj.FUN_1407cbb20("warning", FUN_14062b4f0(CStringW(L"s_itemslot_exchange_upgrade_warning"), &pInfo->m_nMaxGrade));
        obj.FUN_1407cbb20("notify", CStringW(strNotify));
    }
}

// @0x140f544d0
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f544d0(ASObj& obj, CExchangeItemInfo* pInfo)
{
    if (pInfo != 0)
    {
        int nMax = FUN_140f55220();
        if (nMax < 2)
            nMax = 1;
        int nDefault = FUN_140ad0d60(1, 1, nMax);
        obj.FUN_1409c0dc0("type", "trading");
        FUN_140f514c0(&pInfo->m_receipe, CString("recipe"), obj, 0x11, nDefault, MS2Ptr<CItem>(0));
        FUN_140f514c0(&pInfo->m_exchange, CString("exchange"), obj, 2, nDefault, MS2Ptr<CItem>(0));
        for (unsigned __int64 i = 0; i < pInfo->m_require.FUN_14026bee0(); i++)
        {
            CString strKey = StringFormat("require{0}", i + 1);
            Unk_IngRef ref = pInfo->m_require.FUN_14026bdc0(i);
            FUN_140f51e90(ref.FUN_14027f250(), strKey, obj, 1, nDefault);
        }
        obj.FUN_1407cbb20("price", FUN_1409404f0(pInfo->GetTotalMeso(nDefault)));
        obj.FUN_1407cb9c0("itemMaxCount", nMax);
        obj.FUN_1407cb9c0("itemMinCount", 1);
        obj.FUN_1407cb9c0("itemDefaultCount", nDefault);
        ASFunction fn(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f54a20), 0,
                      FUN_1422db730());
        obj.FUN_1409adbe0("updateCountFunction", Scaleform::GFx::Value(fn.FUN_1422bb870()));
        bool bInput = false;
        MS2Ptr<CItemData> spData = FUN_14053f870(pInfo->m_exchange.m_nId);
        if (spData.get() != 0)
        {
            if (1 < spData->FUN_14053de60())
                bInput = true;
        }
        obj.FUN_1407cbbe0("enableInputCount", bInput);
    }
}

// @0x140f54a20
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f54a20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    const Unk_IesParams* pParams = reinterpret_cast<const Unk_IesParams*>(&params);
    if (2 < pParams->m_nArgs && !(m_spExchange == 0))
    {
        AScript argMake(pParams->m_pArgs[0], 2);
        if (!argMake.FUN_1422ba9a0())
        {
            ASArray argList(pParams->m_pArgs[1], 2);
            if (!argList.FUN_1422ba9a0())
            {
                AScript argSlot(pParams->m_pArgs[2], 2);
                if (!argSlot.FUN_1422ba9a0())
                {
                    int nMake = FUN_1409c1750(argMake.FUN_1422bb870());
                    int nLen = argList.FUN_1422bc5d0();
                    bool bEnough = true;
                    for (int i = 0; i < nLen; i++)
                    {
                        Scaleform::GFx::Value vItem = reinterpret_cast<Unk_IesArray&>(argList).FUN_1422bc6b0(i);
                        ASObj item(vItem, 2);
                        if (!item.FUN_1422ba9a0())
                        {
                            Scaleform::GFx::Value vData = item.FUN_1422baa20("data");
                            ASObj data(vData, 2);
                            if (!data.FUN_1422ba9a0())
                            {
                                int nBase = FUN_1409c1750(data.FUN_1422baa20("itemRequireCount"));
                                int nHave = FUN_1409c1750(data.FUN_1422baa20("itemCurrentCount"));
                                int nNeed = nBase * nMake;
                                CStringW strCount;
                                if (nHave < nNeed)
                                {
                                    bEnough = false;
                                    strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_disable"), nHave, nNeed);
                                }
                                else
                                    strCount = FUN_1409e8970(CStringW(L"s_itemslot_exchange_count_enable"), nHave, nNeed);
                                FUN_140cff1b0(item.FUN_1422bb870(), CString("m_name"), CStringW(strCount));
                            }
                        }
                    }
                    MS2Ptr<ASMovieClip> spSlot = argSlot.FUN_1409b4560(CString("slot"));
                    if (spSlot.get() != 0)
                    {
                        int nUnitCount = m_spExchange->m_exchange.m_nCount * nMake;
                        reinterpret_cast<Unk_IesChild*>(spSlot.get())->FUN_1409ba030("updateItemCount", nUnitCount);
                    }
                    if (m_spOk.get() != 0)
                    {
                        __int64 nMeso = m_spExchange->GetTotalMeso(nMake);
                        bool bPay = nMeso <= DAT_143ab2898;
                        unsigned nEnable = (bPay && bEnough) ? 1 : 0;
                        m_spOk->FUN_1422c1fe0(nEnable);
                        m_spOk->FUN_1422cdfb0(FUN_1409404f0(nMeso));
                    }
                }
            }
        }
    }
}

// @0x140f55190
unsigned UIItemExchangeScrollDialog::FUN_140f55190()
{
    if (m_spScroll == 0)
        return 0;
    return FUN_1409c1750(m_spScroll->Invoke("getMakeCount"));
}

// @0x140f55220
// MS2-FUNCTIONAL: temporaries / frame not tuned
int UIItemExchangeScrollDialog::FUN_140f55220()
{
    CItem* pScroll = FUN_140f52810();
    if (pScroll == 0)
        return 0;
    if (m_spExchange == 0)
        return 0;
    MS2Ptr<CExchangeItemInfo> spInfo(m_spExchange);
    const Unk_ExchangeItemRef* pRecipe = &spInfo->m_receipe;
    Unk_IesCountKey key;
    FUN_140bb5a30(&key);
    key.m_nId = pRecipe->m_nId;
    key.m_nKind = 1;
    int nMax = DAT_143ab2a90.FUN_140a5eda0(&key);
    if (pRecipe->m_nCount < 1)
        nMax = 0;
    else
        nMax = nMax / pRecipe->m_nCount;
    unsigned __int64 nRequire = spInfo->m_require.FUN_14026bee0();
    if (nRequire != 0)
    {
        int nMin = nMax;
        for (unsigned __int64 i = 0; nMax = nMin, i < nRequire; i++)
        {
            Unk_IngRef ref = spInfo->m_require.FUN_14026bdc0(i);
            if (!(ref == 0))
            {
                int nHave = 0;
                if (ref->m_b == 0)
                {
                    Unk_IesCountKey ingKey;
                    FUN_140bb5a30(&ingKey);
                    ingKey.m_nId = ref->FUN_14026b500();
                    ingKey.m_nKind = 1;
                    nHave = DAT_143ab2a90.FUN_140a5eda0(&ingKey);
                }
                else
                    nHave = DAT_143ab2a90.FUN_140a5f780(ref->m_b, 0);
                if (ref->m_c < 1)
                    nHave = 0;
                else
                    nHave = nHave / ref->m_c;
                if (nHave <= nMin)
                    nMin = nHave;
            }
        }
    }
    __int64 nPrice = spInfo->GetMeso();
    __int64 nTotal = nPrice * nMax;
    int nResult = nMax;
    if (0 < nPrice && DAT_143ab2898 < nTotal)
    {
        __int64 nA = (__int64)nMax;
        __int64 nB = DAT_143ab2898 / nPrice;
        __int64 nLimit = nA < nB ? nA : nB;
        nResult = (int)nLimit;
    }
    int nStack = 0;
    unsigned nUnit = spInfo->m_exchange.m_nCount;
    MS2Ptr<CItemData> spData = FUN_14053f870(spInfo->m_exchange.m_nId);
    if (spData.get() != 0)
    {
        if ((int)nUnit < 2)
            nStack = spData->FUN_14053de60();
        else
            nStack = (int)(((unsigned __int64)spData->FUN_14053de60() & 0xffffffff) / (unsigned __int64)nUnit);
    }
    if (nStack < nResult)
        nResult = nStack;
    return nResult;
}

// @0x140f55670
// MS2-FUNCTIONAL: not byte-matched yet
bool UIItemExchangeScrollDialog::FUN_140f55670(const int* pCode)
{
    if (*pCode == 0)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_ok")), 1, 1);
        return false;
    }
    switch (*pCode)
    {
    case 1:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_scroll_invalid")), 1, 1);
        break;
    case 2:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_upgrade_invalid")), 1, 1);
        break;
    case 3:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_money_invalid")), 1, 1);
        break;
    case 4:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_count_invalid")), 1, 1);
        break;
    case 5:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_grade_invalid")), 1, 1);
        break;
    case 6:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_lockstate_item")), 1, 1);
        break;
    case 7:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_count_check")), 1, 1);
        break;
    case 8:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_unknown")), 1, 1);
        break;
    default:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemslot_exchange_unknown")), 1, 1);
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
        COutPacket packet(0x9b, 0);
        packet.vfunc_o10_1(3);
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
        COutPacket packet(0x9b, 0);
        packet.vfunc_o10_1(3);
        FUN_140202580(reinterpret_cast<unsigned char*>(&fill), packet);
        FUN_140710590(packet);
    }
}

// @0x140f55d10
// MS2-FUNCTIONAL: temporaries / frame not tuned
void UIItemExchangeScrollDialog::FUN_140f55d10()
{
    bool bDebug = FUN_14025e7c0()->FUN_14116d720();
    if (bDebug && !(m_spExchange == 0))
    {
        CIngredientContainer* pRequire = 0;
        if (m_spExchange->m_eType == 2)
        {
            if (!(m_spIngredients == 0))
                return;
            pRequire = m_spIngredients.get();
        }
        else
            pRequire = &m_spExchange->m_require;
        if (pRequire->FUN_14026bf40() == 0)
        {
            FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
            MS2Ptr<ASMovieClip> spScroll(m_spScroll);
            if (spScroll.get() != 0)
            {
                m_spDebugAddMax = spScroll->FUN_140acce30<Unk_140acd6e0>("m_debugAddMax");
                if (m_spDebugAddMax.get() != 0)
                {
                    m_spDebugAddMax->vfunc_4(bDebug);
                    m_spDebugAddMax->FUN_1422ce240(
                        Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f55b90), 0);
                }
                m_spDebugAdd10 = spScroll->FUN_140acce30<Unk_140acd6e0>("m_debugAdd10");
                if (m_spDebugAdd10.get() != 0)
                {
                    m_spDebugAdd10->vfunc_4(bDebug);
                    m_spDebugAdd10->FUN_1422ce240(
                        Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemExchangeScrollDialog::FUN_140f55c50), 0);
                }
            }
        }
    }
}

// @0x140f56180
// MS2-FUNCTIONAL: not byte-matched yet
void UIItemExchangeScrollDialog::FUN_140f56180()
{
    if (!(m_30 == 0) && !(m_spScroll == 0))
    {
        int nMax = FUN_140f55220();
        if (nMax < 2)
            nMax = 1;
        ASObj obj(2);
        obj.FUN_1407cb9c0("itemMaxCount", nMax);
        m_spScroll->Invoke("updateData", obj.FUN_1422bb870());
        if (m_spOk.get() != 0)
        {
            unsigned nMake = FUN_140f55190();
            bool bEnable = FUN_140f524d0(nMake);
            m_spOk->FUN_1422c1fe0(bEnable);
        }
    }
}

// @0x140f566d0
// MS2-FUNCTIONAL: not byte-matched yet
UIItemExchangeScrollDialog::~UIItemExchangeScrollDialog()
{
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9ac0-0x142ca9af0 .text$yd
