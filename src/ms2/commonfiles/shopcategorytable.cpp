// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CShopCategoryTable and its tab rows TabInfo / SortTabInfo: the shop tab trees
// (Table/shopCategory.xml, Table/meratMarketCategory.xml), plus the template glue of their containers (CAtlMap of the boxed tab
// list, CAtlList of the tab pointer) and the header statics (the three market sort name arrays).
// MS2-UNIT: ?\shopcategorytable.cpp
// MS2-RANGE: 0x1400bc9c0-0x1400bcc10 .text$di
// MS2-RANGE: 0x1407c9f40-0x1407cde30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$TPtrValue@V?$CAtlList@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@V?$CElementTraits@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlList@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@V?$CElementTraits@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1407ccbd0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CShopCategoryTable@@6B?$TSingleton@VCShopCategoryTable@@@@@ 0x142d8e750
// MS2-PIN: ??_7CShopCategoryTable@@6B?$CValidData@VCShopCategoryTable@@@@@ 0x142d8e760
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@V?$CElementTraits@V?$MS2Ptr@UTabInfo@CShopCategoryTable@@@@@ATL@@@ATL@@@@6B@ 0x142d8e780
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\shopcategorytable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "shopcategorytable.h"
#include <typeinfo>
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Header statics: the market sort name arrays, one copy per including unit.
#ifndef MS2_HOOK_DLL
static CString s_sortNames7a[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_sortNames7b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// Out-of-unit callees.
class Unk_140166410 { public: bool FUN_14036d4b0(const CStringW& strFeature); };   // the content switches
Unk_140166410* FUN_140166410();
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
CString FUN_14016a5c0(const char* psz, int nCodePage);                   // narrows a string (the RTTI name in CheckInit)
CStringTable* GetStringTable();                                           // the string table singleton
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault);   // wide string attribute with default
bool FUN_14028f710(Unk_140165cf0* pElem);                                // the element is enabled for this build
Unk_140165cf0* FUN_14028f8d0(Unk_140165cf0* pElem);                      // the next sibling root
bool FUN_140184310(const CString& str, const char* psz);                 // string equals
bool FUN_1406a5040(int nTabId);                                          // the tab opens on its best page

// The AS object a tab is written into: AScript, which holds the GFx value at +0x20.
struct Unk_AsOut : public CPtred
{
    int m_nMovieId;
    Scaleform::GFx::Value m_value;
};
MS2_CHECK_OFFSET(Unk_AsOut, m_value, 0x20);

bool CShopCategoryTable::s_bInit;

// ---- AS object writers (header-inline helpers)

void FUN_1407cb9c0(Unk_AsOut* pOut, const char* pszName, int nValue)
{
    ASData data;
    data.FUN_1422b7f70(nValue);
    pOut->m_value.SetMember(pszName, data.FUN_1422b9260());
}

void FUN_1407cba60(Unk_AsOut* pOut, const char* pszName, CString strValue)
{
    ASData data;
    data.FUN_1422b82b0(strValue);
    pOut->m_value.SetMember(pszName, data.FUN_1422b9260());
}

void FUN_1407cbb20(Unk_AsOut* pOut, const char* pszName, CStringW strValue)
{
    ASData data;
    data.FUN_1422b8310(strValue);
    pOut->m_value.SetMember(pszName, data.FUN_1422b9260());
}

void FUN_1407cbbe0(Unk_AsOut* pOut, const char* pszName, bool bValue)
{
    ASData data;
    data.FUN_1422b7fd0(bValue);
    pOut->m_value.SetMember(pszName, data.FUN_1422b9260());
}

// ---- TabInfo

// @0x1407c9f40
CShopCategoryTable::TabInfo::TabInfo(int nKind)
    : m_nKind(nKind), m_nName(0), m_nPriority(0), m_nStatic(0), m_nId(-1), m_subTabs(10), m_bAlwaysOpen(false)
{
}

// @0x1407ca000
CShopCategoryTable::TabInfo::~TabInfo()
{
    m_subTabs.RemoveAll();
}

// @0x1407ca080
bool CShopCategoryTable::TabInfo::Load(Unk_140165cf0* pElem, MS2Ptr<TabInfo> spParent)
{
    if (pElem == 0)
        return false;
    unsigned nName = 0;
    FUN_140873220(pElem, "name", nName);
    if (nName == 0)
        return false;
    m_nName = nName;
    CStringW strFeature = FUN_1401bf530(pElem, "feature", CStringW(L""));
    if (!FUN_140166410()->FUN_14036d4b0(strFeature))
        return false;
    m_strSymbol = FUN_14015f710(pElem, "symbol", CString(""));
    if (m_strSymbol.Find("/", 0) >= 0)
        m_strSymbol = "";
    m_strCategory = FUN_14015f710(pElem, "category", CString(""));
    FUN_1408731e0(pElem, "priority", m_nPriority);
    FUN_1408731e0(pElem, "static", m_nStatic);
    FUN_1408731e0(pElem, "id", m_nId);
    FUN_1408730a0(pElem, "alwaysOpen", m_bAlwaysOpen);
    return true;
}

// @0x1407ca3a0
void CShopCategoryTable::TabInfo::Write(Unk_AsOut* pOut)
{
    if (m_nId != -1)
        FUN_1407cb9c0(pOut, "id", m_nId);
    FUN_1407cba60(pOut, "symbol", m_strSymbol);
    FUN_1407cb9c0(pOut, "priority", m_nPriority);
    FUN_1407cbb20(pOut, "name", GetName());
    bool bBestPage = m_nStatic == 1 && FUN_1406a5040(m_nId);
    if (bBestPage)
        FUN_1407cbbe0(pOut, "bestPage", true);
    FUN_1407cbbe0(pOut, "alwaysOpen", m_bAlwaysOpen);
}

// @0x1407ca4e0
CStringW CShopCategoryTable::TabInfo::GetName()
{
    return GetStringTable()->FUN_141811980(13, m_nName);
}

// ---- SortTabInfo

// @0x1407ca540
CShopCategoryTable::SortTabInfo::SortTabInfo()
    : TabInfo(1), m_bSortGender(false), m_bSortJob(false)
{
}

// @0x1407ca590
bool CShopCategoryTable::SortTabInfo::Load(Unk_140165cf0* pElem, MS2Ptr<TabInfo> spParent)
{
    if (TabInfo::Load(pElem, MS2Ptr<TabInfo>(0)))
    {
        FUN_1408730a0(pElem, "sortGender", m_bSortGender);
        FUN_1408730a0(pElem, "sortJob", m_bSortJob);
        if (spParent.get() != 0)
        {
            MS2Ptr<SortTabInfo> spSortParent(dynamic_cast<SortTabInfo*>(spParent.operator TabInfo*()));
            if (spSortParent.get() != 0)
            {
                m_bSortGender = m_bSortGender && spSortParent->m_bSortGender;
                m_bSortJob = m_bSortJob && spSortParent->m_bSortJob;
            }
        }
        return true;
    }
    return false;
}

// @0x1407ca770
void CShopCategoryTable::SortTabInfo::Write(Unk_AsOut* pOut)
{
    TabInfo::Write(pOut);
}

// ---- CShopCategoryTable

// @0x1407ca7a0
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs (operator-> results and by-value temps); no source form found
CShopCategoryTable::CShopCategoryTable()
    : m_tabs(17, 0.75f, 0.25f, 2.25f, 10)
{
    MS2Ptr<CCacheData> spShop(new CCacheData);
    spShop->FUN_1401d1160(FUN_14071a5b0(CString("Table"), CString("shopCategory.xml")));
    m_caches.Add(spShop);
    MS2Ptr<CCacheData> spMerat(new CCacheData);
    spMerat->FUN_1401d1160(FUN_14071a5b0(CString("Table"), CString("meratMarketCategory.xml")));
    m_caches.Add(spMerat);
    Load();
}

// @0x1407caad0
CShopCategoryTable::~CShopCategoryTable()
{
    Clear();
}

// @0x1407cab80
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs (operator-> results and by-value temps); no source form found
void CShopCategoryTable::Load()
{
    for (size_t i = 0; i < m_caches.GetCount(); i++)
    {
        MS2Ptr<CCacheData> spCache = m_caches[i];
        if (spCache == 0)
            continue;
        TiXmlDocument doc;
        const char* pszPath = *spCache->FUN_1401d1140();
        if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) != 0)
        {
            Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
            if (pRoot == 0)
                continue;
            LoadCategories(pRoot);
            Unk_140165cf0* pNext = FUN_14028f8d0(pRoot);
            if (pNext != 0)
                LoadCategories(pNext);
        }
    }
    SetInit(true);
}

// @0x1407cad10
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs (operator-> results and by-value temps); no source form found
void CShopCategoryTable::LoadCategories(Unk_140165cf0* pRoot)
{
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pCategory = pRoot->FUN_140165cf0("category"); pCategory != 0; pCategory = pCategory->FUN_140168650("category"))
    {
        unsigned nId = 0;
        FUN_140873220(pCategory, "id", nId);
        if (nId <= 0)
            continue;
        if (!FUN_14028f710(pCategory))
            continue;
        CString strTabType;
        FUN_1408733e0(pCategory, "tabType", strTabType);
        int nTabType = FUN_140184310(strTabType, "sort") != 0;
        TabListPtr spList(Unk_GrNewTag(0));
        if (spList.get() != 0)
        {
            LoadTabs(nTabType, pCategory, m_tabs, spList.get(), TabPtr(0));
            m_tabs.SetAt(nId, spList);
        }
    }
}

// @0x1407caee0
CShopCategoryTable::TabPtr CShopCategoryTable::NewTab(int nTabType)
{
    TabPtr spTab(0);
    if (nTabType == 0)
        spTab.AssignRaw(new TabInfo(0));
    else if (nTabType == 1)
        spTab.AssignRaw(new SortTabInfo);
    return spTab;
}

// @0x1407cb000
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs (operator-> results and by-value temps); no source form found
void CShopCategoryTable::LoadTabs(int nTabType, Unk_140165cf0* pParent, TabMap& rMap, TabList* pList, TabPtr spParent)
{
    for (Unk_140165cf0* pElem = pParent->FUN_140165cf0("tab"); pElem != 0; pElem = pElem->FUN_140168650("tab"))
    {
        if (!FUN_14028f710(pElem))
            continue;
        int nName = 0;
        FUN_1408731e0(pElem, "name", nName);
        if (nName > 0)
        {
            TabPtr spTab = NewTab(nTabType);
            if (spTab == 0)
                continue;
            spTab->Load(pElem, spParent);
            LoadTabs(nTabType, pElem, rMap, &spTab->m_subTabs, spTab);
            if (spParent.get() != 0 && !spTab->m_strCategory.IsEmpty())
            {
                const char* pszSep = spParent->m_strCategory.IsEmpty() ? "" : ",";
                CString strAdd(pszSep);
                strAdd += spTab->m_strCategory;
                spParent->m_strCategory.Append(strAdd);
            }
            pList->AddTail(spTab);
        }
        else
        {
            int nCopyId = 0;
            FUN_1408731e0(pElem, "copyid", nCopyId);
            TabListPtr spCopy(0);
            if (rMap.Lookup(nCopyId, spCopy))
            {
                TabList* pCopy = spCopy.get();
                if (pCopy != 0)
                    pList->AddTailList(pCopy);
            }
        }
    }
}

// @0x1407cb360
void CShopCategoryTable::Clear()
{
    m_tabs.RemoveAll();
}

// @0x1407cb390
bool CShopCategoryTable::Reload(bool bForce)
{
    for (size_t i = 0; i < m_caches.GetCount(); i++)
    {
        MS2Ptr<CCacheData> spCache = m_caches[i];
        if (spCache == 0)
            continue;
        if (bForce || FUN_1401d1320(spCache.operator->()))
        {
            Clear();
            Load();
            return true;
        }
    }
    return false;
}

// @0x1407cb490
CShopCategoryTable::TabListPtr CShopCategoryTable::GetTabs(int nCategory)
{
    CheckInit();
    TabListPtr spList(0);
    m_tabs.Lookup(nCategory, spList);
    return spList;
}

// @0x1407cb520
CShopCategoryTable::TabPtr CShopCategoryTable::FindTab(int nCategory, int nTabId)
{
    CheckInit();
    TabListPtr spList = GetTabs(nCategory);
    if (spList == 0 || spList->IsEmpty())
        return TabPtr(0);
    for (POSITION pos = spList->GetHeadPosition(); pos != 0; spList->GetNext(pos))
    {
        TabPtr spTab = spList->GetAt(pos);
        if (spTab == 0)
            continue;
        TabPtr spFound = FindSubTab(spTab, nTabId);
        if (spFound.get() != 0)
            return spFound;
    }
    return TabPtr(0);
}

// @0x1407cb740
CShopCategoryTable::TabPtr CShopCategoryTable::FindSubTab(TabPtr spTab, int nTabId)
{
    if (spTab == 0)
        return TabPtr(0);
    if (spTab->GetId() == nTabId)
        return spTab;
    TabList* pSubs = &spTab->m_subTabs;
    if (pSubs->IsEmpty())
        return TabPtr(0);
    for (POSITION pos = pSubs->GetHeadPosition(); pos != 0; pSubs->GetNext(pos))
    {
        TabPtr spSub = pSubs->GetAt(pos);
        if (spSub == 0)
            continue;
        TabPtr spFound = FindSubTab(spSub, nTabId);
        if (spFound.get() != 0)
            return spFound;
    }
    return TabPtr(0);
}

// @0x1407cc720
void CShopCategoryTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CShopCategoryTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9bf60-0x142c9bff0 .text$yd
