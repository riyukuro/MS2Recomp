// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The shop helper TU (the exe's ?\shopbannerinfo.cpp guess was
// rejected; CU name unknown): ShopBannerInfo / MeratMarketShopBannerInfo / ShopBanner, the shop tab list builders
// (ShopTabInfo / NpcShopTabInfo over CShopCategoryTable tabs), the item tooltip compared with the equipped item, the
// shop open / item message box helpers and the currency helpers of the beauty shops. Types: shoptabinfo.h.
// MS2-UNIT: unit_141347b10
// MS2-RANGE: 0x1400f0590-0x1400f0980 .text$di
// MS2-RANGE: 0x141347b10-0x14134c9d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VNpcShopTabInfo@@@@QEAA@PEAVNpcShopTabInfo@@@Z 0x14134a7a0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VShopTabInfo@@@@QEAA@PEAVShopTabInfo@@@Z 0x14134a7d0 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VNpcShopTabInfo@@@@QEAAAEAV1@PEAVNpcShopTabInfo@@@Z 0x14134ac30 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VCNpcShopProductBase@@@@QEBAPEAVCNpcShopProductBase@@XZ 0x14134ada0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCNpcShopProductBase@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14134ae30 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCNpcShopProductBase@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14134ae50 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VShopTabInfo@@@@V?$CElementTraits@V?$MS2Ptr@VShopTabInfo@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VShopTabInfo@@@@@Z 0x14134b0c0 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCNpcShopProductBase@@@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopProductBase@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCNpcShopProductBase@@@@@Z 0x14134b170 ; prop
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@V?$CElementTraits@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@PEAU__POSITION@@@Z 0x14134b3c0 ; unique
// MS2-PIN: ?vfunc_1@NpcShopTabInfo@@UEAAXXZ 0x14134c020 ; unique
// MS2-PIN: ?vfunc_1@ShopTabInfo@@UEAAXXZ 0x14134c030 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VNpcShopTabInfo@@@@AEBAXXZ 0x14134c300 ; prop
// MS2-PIN: ?Reference@?$MS2Ptr@VCNpcShopProductBase@@@@CAXPEAVCNpcShopProductBase@@@Z 0x14134c380 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VNpcShopTabInfo@@@@AEBAXPEAX@Z 0x14134c3a0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCNpcShopProductBase@@@@AEBAXPEAX@Z 0x14134c3d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$MS2Ptr@VNpcShopTabInfo@@@@QEAA@XZ 0x14134ab50 ; manual: calls Release 0x14134c4e0 -> ReleaseImpl<NpcShopTabInfo> 0x14134c560
// MS2-PIN: ?Release@?$MS2Ptr@VNpcShopTabInfo@@@@AEAAXXZ 0x14134c4e0 ; manual
// MS2-PIN: ?Release@?$MS2Ptr@VCNpcShopProductBase@@@@AEAAXXZ 0x14134c520 ; manual: called by ~MS2Ptr<CNpcShopProductBase> 0x14134ab80
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCNpcShopProductBase@@@@AEAAXPEAX@Z 0x14134c5b0 ; manual
// MS2-PIN: ??A?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@_K@Z 0x14134b380 ; manual: the product categories in FUN_1413487e0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/shoptabinfo.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"
#include "ms2/client/ms2/npcshopproductbase.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemexchangescrolltable.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Unk_ClickDelegate;

class Unk_140acd6e0 : public ASDisplayObject                    // the button wrapper
{
public:
    void FUN_1422ce240(const Unk_ClickDelegate& cb, void* pUser);   // click callback
};

class Unk_SbWorld { public: void* FUN_141bd0cc0(); };           // the local player (a MyPC)
class Unk_SbShopDialog : public UIDialog { public: int FUN_141afb740(); };   // UIShopDialog: its current tab

CString FUN_14016a600(const wchar_t* psz, int n);                // wide -> narrow
CString FUN_14102a0b0(int nType, const CString& strName, const CString& strUrl, CString strKey);   // banner image path
void FUN_1418fe1c0(const CString& strUrl);                       // open a url
CShopCategoryTable* FUN_1406aa4b0();
CShopEventManager* FUN_1403ed2a0();
Unk_SbWorld* FUN_1403ed2d0();
CUIService* FUN_1403ed2b0();
CItemExchangeScrollTable* FUN_140f56960();
CFeatureManager* FUN_140166410();
CNetworkService* FUN_140714f90();
Unk_SbShopDialog* FUN_140534780(int nUIType);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);
CStringW FUN_14028de60(int nId);                                 // string table lookup
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table lookup by key
CStringW FUN_14062b4f0(CStringW strKey, const int& n);          // formatted string table text
void FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                  // show a message box
Delegate<bool(int, const CMsgBoxData&)> FUN_140b76b10(bool (*pfn)(int, const CMsgBoxData&));
CStringW FUN_1418fec90(int nCurrency, __int64 nAmount, int nArg);
CStringW FUN_1418fee40(int nCurrency, __int64 nAmount, const CString& strArg, bool bAlt);
bool FUN_1418ff1f0(int nCurrency, __int64 nAmount, int nItemId);
__int64 FUN_1418ff5a0(int nCurrency, __int64 nAmount, int nItemId);
void FUN_1418ff710(int nCurrency, __int64 nAmount, int nItemId, int nOpt);
int FUN_1403baee0(int value);
void FUN_140657820();                                            // 'invalid call' of an empty Delegate

// ---- header statics (.text$di) ----
static CString s_strSortTypeNames1[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CString s_strBuildOpenShop = "System_BuildOpenShop";      // DAT_143ad82b0
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Delegate<void(AScript&)>::operator() (0x14134af00, exe RTTI .?AUDelegateImplBase@?$Delegate@$$A6AXAEAVAScript@@@Z@@): null check, then slot 2.
template <>
void Delegate<void(AScript&)>::operator()(AScript& a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// ---- ShopBannerInfo ----

// @0x141347b10
ShopBannerInfo::ShopBannerInfo()
{
    m_nType = 0;
    m_nKind = 0;
}

// @0x141347bb0
ShopBannerInfo::~ShopBannerInfo()
{
}

// @0x141347c30
void ShopBannerInfo::FUN_141347c30(const Unk_AdBannerPtr& spBanner, int nType, CStringA strKey)
{
    CString strUrl = FUN_14016a600(spBanner.FUN_14016e5a0()->m_str40, 0);
    m_nKind = 0;
    m_strName = (const wchar_t*)spBanner.FUN_14016e5a0()->m_strTypeName;
    m_strName2 = (const wchar_t*)spBanner.FUN_14016e5a0()->m_str30;
    m_strName3 = (const wchar_t*)spBanner.FUN_14016e5a0()->m_str38;
    m_nType = nType;
    CString strImg = FUN_14102a0b0(nType, m_strName, strUrl, strKey);
    if (strImg.GetLength() > 0)
        m_strImgPath = strImg;
    m_nKind = FUN_141349e30(m_strName2);
}
MS2_REPLACE_METHOD(0x141347c30, ShopBannerInfo, FUN_141347c30, 408, 0x4A79F065);

// @0x141347dd0
void ShopBannerInfo::vfunc_1(AScript* pObj)
{
    static_cast<ASObj*>(pObj)->FUN_1407cba60("imgpath", m_strImgPath);
    static_cast<ASObj*>(pObj)->FUN_1407cba60("name", m_strName);
}
MS2_REPLACE_METHOD(0x141347dd0, ShopBannerInfo, vfunc_1, 139, 0x3E389F5C);

// @0x141347e70
MeratMarketShopBannerInfo::MeratMarketShopBannerInfo()
    : m_nProduct(-1)
{
}

// ---- ShopBanner ----

// @0x141347ed0
void ShopBanner::FUN_141347ed0(MS2Ptr<ShopBannerInfo> spInfo)
{
    if (spInfo == 0)
        return;
    m_banners.SetAt(spInfo->m_strName, spInfo);
}
MS2_REPLACE_METHOD(0x141347ed0, ShopBanner, FUN_141347ed0, 115, 0xDF5BF32C);

// @0x141347f50
MS2Ptr<ShopBannerInfo> ShopBanner::FUN_141347f50(const Unk_AdBannerPtr& spBanner, int nType)
{
    MS2Ptr<ShopBannerInfo> spInfo(new ShopBannerInfo);
    if (spInfo.get())
    {
        spInfo->FUN_141347c30(spBanner, nType, CString(""));
        m_banners.SetAt(spInfo->m_strName, spInfo);
    }
    return spInfo;
}
MS2_REPLACE_METHOD(0x141347f50, ShopBanner, FUN_141347f50, 324, 0x8C051611);

// @0x1413480a0
MS2Ptr<ShopBannerInfo> ShopBanner::FUN_1413480a0(const CString& strName)
{
    MS2Ptr<ShopBannerInfo> spInfo(0);
    if (m_banners.Lookup(strName, spInfo))
        return spInfo;
    return MS2Ptr<ShopBannerInfo>(0);
}
MS2_REPLACE_METHOD(0x1413480a0, ShopBanner, FUN_1413480a0, 175, 0x0287A2A3);

// @0x141348160
void ShopBanner::FUN_141348160(const CString& strUrl)
{
    FUN_1418fe1c0(strUrl);
}
MS2_REPLACE_METHOD(0x141348160, ShopBanner, FUN_141348160, 29, 0x6C2B4716);

// @0x141348190
void ShopBanner::FUN_141348190(ASArray& arr)
{
    if (m_banners.IsEmpty())
        return;
    for (POSITION pos = m_banners.GetHeadPosition(); pos != NULL; m_banners.GetNext(pos))
    {
        MS2Ptr<ShopBannerInfo> spInfo = m_banners.GetValueAt(pos);
        if (spInfo.get())
        {
            ASObj obj(2);
            spInfo->vfunc_1(&obj);
            arr.FUN_1422bc050(obj.FUN_1422bb890());
        }
    }
}
MS2_REPLACE_METHOD(0x141348190, ShopBanner, FUN_141348190, 322, 0x553CA18E);

// ---- tab lists ----

// @0x1413482e0
int FUN_1413482e0(const Unk_ShopTabArray& arr, MS2Ptr<CShopCategoryTable::TabInfo> spTab)
{
    if (!arr.IsEmpty())
    {
        size_t nCount = arr.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            if (arr[i]->m_spTab == spTab.get())
                return (int)i;
        }
    }
    return -1;
}
MS2_REPLACE(0x1413482e0, FUN_1413482e0, 213, 0x5B7DB259);

// @0x1413483c0
// MS2-FUNCTIONAL: string search loop; frame / EH temp layout differs from the exe
// Is strCategory one of the comma separated entries of strList (case-insensitive)?
int FUN_1413483c0(const CString& strCategory, const CString& strList)
{
    int nPos = strList.Find(strCategory, 0);
    int nLen = strList.GetLength();
    for (; nPos > -1 && nPos < nLen; nPos = strList.Find(strCategory, nPos))
    {
        int nPrev = nPos - 1 < 0 ? 0 : nPos - 1;
        if (nPrev == 0 || strList.GetAt(nPrev) == ',')
        {
            CString strToken = strList.Tokenize(",", nPos);
            if (_stricmp(strCategory, strToken) == 0)
                return 1;
        }
        strList.Tokenize(",", nPos);
    }
    return 0;
}

// @0x141348530
// MS2-FUNCTIONAL: tab list loop; temp spill order differs
void FUN_141348530(int nShop, Unk_ShopTabArray& arr)
{
    arr.RemoveAll();
    CShopCategoryTable::TabListPtr spTabs = FUN_1406aa4b0()->GetTabs(nShop);
    if (spTabs.get() && !spTabs->IsEmpty())
        FUN_1413487e0(arr, *spTabs, MS2Ptr<CNpcShopProductBase>(0), 0);
}

// @0x141348610
// MS2-FUNCTIONAL: map iteration; iterator temp layout differs
void FUN_141348610(int nShop, Unk_ShopTabArray& arr, std::map<int, MS2Ptr<CNpcShopProductBase> >& products)
{
    arr.RemoveAll();
    CShopCategoryTable::TabListPtr spTabs = FUN_1406aa4b0()->GetTabs(nShop);
    if (spTabs.get() && !spTabs->IsEmpty())
    {
        if (!products.empty())
        {
            for (std::map<int, MS2Ptr<CNpcShopProductBase> >::iterator it = products.begin(); it != products.end(); ++it)
            {
                MS2Ptr<CNpcShopProductBase> spProduct = it->second;
                FUN_1413487e0(arr, *spTabs, spProduct, 0);
            }
        }
        else
        {
            FUN_1413487e0(arr, *spTabs, MS2Ptr<CNpcShopProductBase>(0), 0);
        }
    }
}

// @0x1413487e0
// MS2-FUNCTIONAL: recursive tab tree builder; temp layout / EH states differ
// Adds the tabs of the list (and, recursively, their sub tabs) that list the product (or are static) to arr.
void FUN_1413487e0(Unk_ShopTabArray& arr, CShopCategoryTable::TabList& list, MS2Ptr<CNpcShopProductBase> spProduct,
                   int nDepth)
{
    if (list.IsEmpty())
        return;
    for (POSITION pos = list.GetHeadPosition(); pos != NULL; list.GetNext(pos))
    {
        MS2Ptr<CShopCategoryTable::TabInfo> spTab = list.GetAt(pos);
        if (spTab == 0)
            continue;
        bool bMatch;
        if (spProduct.get() == 0 || !spTab->m_strCategory.IsEmpty() || spTab->m_subTabs.IsEmpty())
            bMatch = false;
        else
            bMatch = true;
        if (spProduct.get() != 0 && !bMatch)
        {
            CAtlArray<CString>* pCategories = spProduct->FUN_140db5f00();
            bMatch = false;
            for (size_t i = 0; i < pCategories->GetCount(); i++)
            {
                bMatch = bMatch || FUN_1413483c0((*pCategories)[i], spTab->m_strCategory) != 0;
                if (bMatch)
                    break;
            }
        }
        int bAdd = bMatch || spTab->m_nStatic != 0 ? 1 : 0;
        if (bAdd)
        {
            MS2Ptr<NpcShopTabInfo> spInfo(0);
            int nIndex = FUN_1413482e0(arr, spTab);
            if (nIndex < 0)
            {
                spInfo.AssignRaw(new NpcShopTabInfo(spTab));
                arr.Add(MS2Ptr<ShopTabInfo>(spInfo.get()));
            }
            else
            {
                spInfo.AssignRaw(dynamic_cast<NpcShopTabInfo*>((ShopTabInfo*)arr[nIndex]));
            }
            spInfo->m_nDepth = nDepth;
            if (bMatch)
                spInfo->m_products.Add(spProduct);
            if (!spTab->m_subTabs.IsEmpty())
                FUN_1413487e0(arr, spTab->m_subTabs, spProduct, nDepth + 1);
        }
    }
}

// @0x141348cf0
void FUN_141348cf0(const Unk_ShopTabArray& arr, MS2Ptr<AScript> spRoot, int nSale, Delegate<void(AScript&)>* pfnEach)
{
    ASArray arrTabs(2);
    int nMaxDepth = 0;
    FUN_141348dd0(arr, arrTabs, &nMaxDepth, nSale, pfnEach);
    if (spRoot.get())
        spRoot->FUN_140e813f0("buildCategoryList", arrTabs, nMaxDepth);
}
MS2_REPLACE(0x141348cf0, FUN_141348cf0, 211, 0xEC8D684F);

// @0x141348dd0
// MS2-FUNCTIONAL: tab writer loop; temp layout differs
void FUN_141348dd0(const Unk_ShopTabArray& arr, ASArray& out, int* pMaxDepth, int nSale, Delegate<void(AScript&)>* pfnEach)
{
    *pMaxDepth = 0;
    if (arr.IsEmpty())
        return;
    size_t nCount = arr.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<ShopTabInfo> spInfo = arr[i];
        if (spInfo == 0)
            continue;
        MS2Ptr<CShopCategoryTable::TabInfo> spTab = spInfo->m_spTab;
        if (spTab == 0)
            continue;
        ASObj obj(2);
        spTab->Write(reinterpret_cast<Unk_AsOut*>(&obj));
        int nDepth = spInfo->m_nDepth;
        obj.FUN_1407cb9c0("depth", nDepth);
        if (nDepth < *pMaxDepth)
            nDepth = *pMaxDepth;
        *pMaxDepth = nDepth;
        obj.FUN_140e846b0("tabindex", i);
        int nId = spTab->GetId();
        if (nSale != 0 && FUN_1403ed2a0()->FUN_1407ce690(nId, nSale))
            obj.FUN_1407cbbe0("saleTag", true);
        obj.FUN_1407cb9c0("space", 1);
        if (pfnEach != 0 && !pfnEach->IsNull())
            (*pfnEach)(obj);
        out.FUN_1422bc050(obj.FUN_1422bb870());
    }
}

// ---- item tooltips ----

// @0x1413490b0
void FUN_1413490b0(MS2Ptr<CItem> spItem, Scaleform::GFx::Value* pOut, bool bCaption, int nLhsFlags, int nRhsFlags)
{
    if (spItem.IsNull() || spItem->FUN_140527840() == 0)
        return;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    ASTooltip tipLhs(pPlayer, nLhsFlags, 2);
    ASTooltip tipRhs(pPlayer, nRhsFlags, 2);
    FUN_141349210(spItem, pOut, bCaption, &tipLhs, &tipRhs);
}
MS2_REPLACE(0x1413490b0, FUN_1413490b0, 332, 0xD664891F);

// @0x141349210
// MS2-FUNCTIONAL: comparison tooltip; EH state numbering / temp ordering differs from the exe
void FUN_141349210(MS2Ptr<CItem> spItem, Scaleform::GFx::Value* pOut, bool bCaption, ASTooltip* pLhs, ASTooltip* pRhs)
{
    if (spItem.IsNull())
        return;
    if (spItem->FUN_140527840() == 0)
        return;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CItem> spEquipped(0);
    bool bAlt = spItem->FUN_1405258b0() != 0;
    MS2Ptr<CEquipItem> spEquip(0);
    if (!reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053d510())
        spEquip = static_cast<PC*>(pPlayer)->FUN_1416561a0()->FUN_1411e1780(spItem->FUN_140527a20(), bAlt);
    else if (FUN_1403ed2b0()->FUN_141adcb40() == 0)
        spEquip = static_cast<PC*>(pPlayer)->FUN_1416561a0()->FUN_1411e1780(5, bAlt);
    else
        spEquip = static_cast<PC*>(pPlayer)->FUN_1416561a0()->FUN_1411e1780(4, bAlt);
    if (spEquip.get())
        spEquipped = spEquip->GetItem();
    if (!FUN_1403b3c40(reinterpret_cast<CItemData*>(spItem->FUN_140527840())->function.name, L"ItemExchangeScroll"))
    {
        ASTooltip tip(pPlayer, pLhs->FUN_1409c6560(), 2);
        if (pRhs->FUN_1409c6560() == 0)
            pRhs->FUN_1409c6580(pLhs->FUN_1409c6560());
        if (tip.FUN_1409e15a0(spEquipped.get(), spItem.get(), pLhs, pRhs))
        {
            if (bCaption)
            {
                CStringW strEmpty(L"");
                tip.FUN_1409c6a20(strEmpty, FUN_14028de60(0x758));
            }
            *pOut = tip.FUN_1422bb870();
        }
    }
    else
    {
        MS2Ptr<CExchangeItemInfo> spInfo = FUN_140f56960()->GetData(spItem->FUN_1405276c0());
        if (spInfo.get())
        {
            MS2Ptr<CItem> spResult(new CItem);
            if (spResult.get())
            {
                spResult->FUN_14052b130(spInfo->m_exchange.m_nId, spInfo->m_exchange.m_nRank, 0);
                if (pLhs->FUN_1409e13f0(spResult.get(), spItem.get(), 0x800, 0x80))
                {
                    {
                        CStringW strEmpty1(L"");
                        CStringW strEmpty2(L"");
                        pLhs->FUN_1409c6640(strEmpty2, strEmpty1);
                    }
                    {
                        CStringW strEmpty(L"");
                        CStringW strKey(L"s_word_compose_result");
                        pLhs->FUN_1409c7060(FUN_14028b8e0(strKey), strEmpty);
                    }
                    if (bCaption)
                    {
                        CStringW strEmpty(L"");
                        pLhs->FUN_1409c6a20(strEmpty, FUN_14028de60(0x758));
                    }
                    *pOut = pLhs->FUN_1422bb870();
                }
            }
        }
    }
}

// ---- shop open / message boxes ----

// @0x1413499b0
// MS2-FUNCTIONAL: frame size: the exe keeps one fewer temp slot (2 attempts)
int FUN_1413499b0(int nTab)
{
    if (FUN_1403ed2b0()->FUN_141adc7f0((eUIClassID)0x4e3b) == 0)
        return 0;
    Unk_SbShopDialog* pDlg = FUN_140534780(0x4e3b);
    if (pDlg != 0)
    {
        int bOpen = 1;
        if (pDlg->vfunc_55() == 0)
        {
            if (pDlg->FUN_141afb740() == nTab)
            {
                bOpen = 0;
            }
            else
            {
                FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4e3b);
                FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4e2d);
            }
        }
        if (bOpen)
        {
            FUN_140714f90()->FUN_141538c40(nTab, 1);
            FUN_141276180(s_strBuildOpenShop, CString(""));
        }
        else
        {
            FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4e3b);
            FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4e2d);
        }
        return bOpen;
    }
    return 0;
}

// @0x141349ae0
void FUN_141349ae0(MS2Ptr<CItem> spItem, int nStringId, const CString& strUrl)
{
    if (spItem == 0)
        return;
    FUN_141349ba0(spItem, FUN_14028de60(nStringId), strUrl);
}
MS2_REPLACE(0x141349ae0, FUN_141349ae0, 181, 0x7FFCBB10);

// @0x141349e10
static bool FUN_141349e10(int nResult, const CMsgBoxData& box)
{
    return true;
}
MS2_REPLACE(0x141349e10, FUN_141349e10, 12, 0x4A4C3EC5);

// @0x141349ba0
void FUN_141349ba0(MS2Ptr<CItem> spItem, CStringW strText, const CString& strUrl)
{
    if (spItem == 0)
        return;
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(0x11));
    spBox->SetMsg(strText);
    spBox->FUN_141a027c0(FUN_140b76b10(FUN_141349e10));
    if (!strUrl.IsEmpty())
        spBox->SetSound(strUrl);
    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
    FUN_140d73c60(spBox);
}
MS2_REPLACE(0x141349ba0, FUN_141349ba0, 616, 0xA11CBD25);

// @0x141349e30
int FUN_141349e30(const CString& strKind)
{
    int nKind = 0;
    if (strKind.CompareNoCase("link") == 0)
        nKind = 1;
    else if (strKind.CompareNoCase("product") == 0)
        nKind = 2;
    else if (strKind.CompareNoCase("changeTab") == 0)
        nKind = 3;
    else if (strKind.CompareNoCase("searchByStr") == 0)
        nKind = 4;
    else if (strKind.CompareNoCase("searchBySN") == 0)
        nKind = 5;
    return nKind;
}
MS2_REPLACE(0x141349e30, FUN_141349e30, 184, 0xBCF869E9);

// ---- currency helpers ----

// @0x141349ef0
__int64 FUN_141349ef0(int nKind, int nItemId, unsigned int nAmount)
{
    int nCurrency = FUN_14134a170(nKind);
    return FUN_1418ff5a0(nCurrency, nAmount, nItemId);
}
MS2_REPLACE(0x141349ef0, FUN_141349ef0, 55, 0xB69B65E2);

// @0x141349f30
void FUN_141349f30(CStringW& strOut, int nKind, int nArg, unsigned int nAmount, const CString& strCurrency)
{
    int nCurrency = FUN_14134a170(nKind);
    if (!strCurrency.IsEmpty())
        strOut = FUN_1418fee40(nCurrency, nAmount, strCurrency, false);
    else
        strOut = FUN_1418fec90(nCurrency, nAmount, nArg);
}
MS2_REPLACE(0x141349f30, FUN_141349f30, 237, 0xD66D1824);

// @0x14134a030
bool FUN_14134a030(int nKind, int nItemId, unsigned int nAmount)
{
    int nCurrency = FUN_14134a170(nKind);
    return FUN_1418ff1f0(nCurrency, nAmount, nItemId);
}
MS2_REPLACE(0x14134a030, FUN_14134a030, 55, 0xDBE12B4E);

// @0x14134a070
CStringW FUN_14134a070(int nKind, int nArg, unsigned int nAmount)
{
    CStringW strText;
    {
        CString strNone("");
        FUN_141349f30(strText, nKind, nArg, nAmount, strNone);
    }
    return strText;
}
MS2_REPLACE(0x14134a070, FUN_14134a070, 165, 0x55430BE5);

// @0x14134a120
void FUN_14134a120(int nKind, int nItemId, unsigned int nAmount)
{
    int nCurrency = FUN_14134a170(nKind);
    FUN_1418ff710(nCurrency, nAmount, nItemId, 1);
}
MS2_REPLACE(0x14134a120, FUN_14134a120, 61, 0xEEEAD390);

// @0x14134a170
int FUN_14134a170(int nKind)
{
    return FUN_1403baee0(nKind);
}
MS2_REPLACE(0x14134a170, FUN_14134a170, 22, 0xFF2C17B2);

// @0x14134a190
__int64 FUN_14134a190(Unk_BSFee* pFee)
{
    return FUN_141349ef0(pFee->FUN_1406dc510(), pFee->FUN_1406dc4d0(), 0);
}
MS2_REPLACE(0x14134a190, FUN_14134a190, 54, 0xA554498C);

// @0x14134a1d0
bool FUN_14134a1d0(Unk_BSFee* pFee, const unsigned int* pPrice)
{
    return FUN_14134a030(pFee->FUN_1406dc510(), pFee->FUN_1406dc4d0(), *pPrice);
}
MS2_REPLACE(0x14134a1d0, FUN_14134a1d0, 64, 0xD9B549FA);

// @0x14134a220
CStringW FUN_14134a220(Unk_BSFee* pFee, const unsigned int* pPrice)
{
    CStringW strText;
    FUN_141349f30(strText, pFee->FUN_1406dc510(), pFee->FUN_1406dc4d0(), *pPrice, pFee->FUN_1406dc4b0());
    return strText;
}
MS2_REPLACE(0x14134a220, FUN_14134a220, 172, 0x6ECB716B);

// @0x14134a2e0
void FUN_14134a2e0(Unk_BSFee* pFee)
{
    FUN_14134a120(pFee->FUN_1406dc510(), pFee->FUN_1406dc4d0(), 0);
}
MS2_REPLACE(0x14134a2e0, FUN_14134a2e0, 54, 0x2D3D1D1C);

// @0x14134a320
// The sale tag of a product: the tag kind and, for a discount (4), the "n% off" text.
void FUN_14134a320(ASObj& obj, const int& nTag, const __int64& nSalePrice, const __int64& nPrice)
{
    obj.FUN_140fbd930("saleTag", nTag);
    bool bSale = nPrice > nSalePrice;
    if (nTag == 4 && nPrice > 0 && bSale)
    {
        int nPercent = (int)((nPrice - nSalePrice) * 100 / nPrice);
        if (nPercent > 0)
        {
            CStringW strText = FUN_14062b4f0(CStringW(L"s_common_saletag_sale"), nPercent);
            obj.FUN_1407cbb20("saleTagText", strText);
        }
    }
}
MS2_REPLACE(0x14134a320, FUN_14134a320, 343, 0x7ADD3300);

// @0x14134a5a0
static void FUN_14134a5a0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    const CString& strUrl = TSingleton<Client::Constants>::GetInstance()->ShopProbInfoUrl.Read();
    if (strUrl.IsEmpty() == true)
        return;
    FUN_1418fe1c0(strUrl);
}
MS2_REPLACE(0x14134a5a0, FUN_14134a5a0, 112, 0x127C11A5);

// @0x14134a480
// Binds the probability info button (KR builds only) and opens ShopProbInfoUrl on click.
void FUN_14134a480(AScript& root, const CString& strName, MS2Ptr<Unk_140acd6e0>* pButton)
{
    if (!FUN_140166410()->FUN_14036e4c0())
        return;
    if (*pButton == 0)
        *pButton = root.FUN_140acce30<Unk_140acd6e0>(strName);
    if (*pButton == 0)
        return;
    (*pButton)->vfunc_4(true);
    (*pButton)->FUN_1422ce240(Unk_ClickDelegate(FUN_14134a5a0), 0);
}
MS2_REPLACE(0x14134a480, FUN_14134a480, 282, 0x814F7A18);

// ---- ShopTabInfo / NpcShopTabInfo ----

// @0x14134aa00
NpcShopTabInfo::NpcShopTabInfo(MS2Ptr<CShopCategoryTable::TabInfo> spTab)
    : ShopTabInfo(spTab)
{
}

// @0x14134aa80
ShopTabInfo::ShopTabInfo(MS2Ptr<CShopCategoryTable::TabInfo> spTab)
    : m_spTab(spTab)
{
    m_nDepth = 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb0660-0x142cb07f0 .text$yd
