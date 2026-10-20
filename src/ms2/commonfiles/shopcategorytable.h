// shopcategorytable.h - CShopCategoryTable (RTTI name, 0xa0 bytes) and its tab rows TabInfo / SortTabInfo: the tab trees of the
// shops, read from Table/shopCategory.xml and Table/meratMarketCategory.xml (<ms2><category id tabType><tab name feature symbol
// category priority static id alwaysOpen sortGender sortJob copyid/>). Header name assumed from the unit path; member names are
// invented from use.
// Bases: TSingleton<CShopCategoryTable> at +0, CValidData<CShopCategoryTable> at +8, CCacheData at +0x10.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // xml element (declared where the loader is)
struct Unk_AsOut;       // the AS object a tab is written into (AScript layout)

class CShopCategoryTable : public TSingleton<CShopCategoryTable>, public CValidData<CShopCategoryTable>, public CCacheData
{
public:
    // One shop tab (RTTI struct CShopCategoryTable::TabInfo, 3 slots: dtor, Load, Write), 0x78 bytes.
    struct TabInfo : public CPtred
    {
        typedef ATL::CAtlList<MS2Ptr<TabInfo> > SubTabs;

        TabInfo(int nKind);                                                 // 0x1407c9f40
        virtual ~TabInfo();                                                 // 0x1407ca000
        virtual bool Load(Unk_140165cf0* pElem, MS2Ptr<TabInfo> spParent);   // 0x1407ca080 one <tab>
        virtual void Write(Unk_AsOut* pOut);                                // 0x1407ca3a0 the tab as an AS object
        CStringW GetName();                                                 // 0x1407ca4e0 the tab caption
        int GetId() const { return m_nId; }                                 // 0x1407ccb40

        int m_nKind;                        // +0x18 0 plain, 1 sort tab
        int m_nName;                        // +0x1c "name" (string table id)
        CString m_strSymbol;                // +0x20 "symbol"
        int m_nPriority;                    // +0x28 "priority"
        CString m_strCategory;              // +0x30 "category" comma separated item categories
        int m_nStatic;                      // +0x38 "static"
        int m_nId;                          // +0x3c "id"
        SubTabs m_subTabs;                  // +0x40
        bool m_bAlwaysOpen;                 // +0x70 "alwaysOpen"
    };

    // A tab that can be limited by gender / job (RTTI struct CShopCategoryTable::SortTabInfo), 0x80 bytes.
    struct SortTabInfo : public TabInfo
    {
        SortTabInfo();                                                      // 0x1407ca540
        virtual bool Load(Unk_140165cf0* pElem, MS2Ptr<TabInfo> spParent);   // 0x1407ca590
        virtual void Write(Unk_AsOut* pOut);                                // 0x1407ca770

        bool m_bSortGender;                 // +0x78 "sortGender"
        bool m_bSortJob;                    // +0x79 "sortJob"
    };

    typedef MS2Ptr<TabInfo> TabPtr;
    typedef TabInfo::SubTabs TabList;
    typedef TPtrValue<TabList> TabListPtr;
    typedef ATL::CAtlMap<int, TabListPtr> TabMap;

    CShopCategoryTable();                                                   // 0x1407ca7a0
    // @0x1406a9940 (inline COMDAT of meratmarketbasketinfo.cpp)
    static CShopCategoryTable* CreateInstance() { return s_instance ? GetInstance() : new CShopCategoryTable; }
    virtual ~CShopCategoryTable();                                          // 0x1407caad0

    void Load();                                                            // 0x1407cab80 every file in m_caches
    void LoadCategories(Unk_140165cf0* pRoot);                              // 0x1407cad10 the <category> list
    TabPtr NewTab(int nTabType);                                            // 0x1407caee0
    void LoadTabs(int nTabType, Unk_140165cf0* pParent, TabMap& rMap, TabList* pList, TabPtr spParent);   // 0x1407cb000
    void Clear();                                                           // 0x1407cb360
    bool Reload(bool bForce);                                               // 0x1407cb390 reload when a file changed
    TabListPtr GetTabs(int nCategory);                                      // 0x1407cb490
    TabPtr FindTab(int nCategory, int nTabId);                              // 0x1407cb520
    TabPtr FindSubTab(TabPtr spTab, int nTabId);                            // 0x1407cb740 recursive

    static void CheckInit();                                                // 0x1407cc720
    static void SetInit(bool bInit) { s_bInit = bInit; }                    // 0x1407cda50
    static bool s_bInit;                                                    // DAT_143ab0fe8

private:
    MS2_LAYOUT_FRIEND;
    TabMap m_tabs;                          // +0x38 category id -> its tabs
    ATL::CAtlArray<MS2Ptr<CCacheData> > m_caches;   // +0x80 the xml files
};
MS2_CHECK_SIZE(CShopCategoryTable::TabInfo, 0x78);
MS2_CHECK_SIZE(CShopCategoryTable::SortTabInfo, 0x80);
MS2_CHECK_SIZE(CShopCategoryTable, 0xa0);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_strSymbol, 0x20);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_strCategory, 0x30);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_nId, 0x3c);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_subTabs, 0x40);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_bAlwaysOpen, 0x70);
MS2_CHECK_OFFSET(CShopCategoryTable, m_tabs, 0x38);
MS2_CHECK_OFFSET(CShopCategoryTable, m_caches, 0x80);
