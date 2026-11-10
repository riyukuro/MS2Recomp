// csmartrecommendshoptable.h - PLACEHOLDER for CSmartRecommendShopTable (RTTI .?AVCSmartRecommendShopTable@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<CSmartRecommendShopTable> at +0x0, CValidData<CSmartRecommendShopTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It loads Table\smartRecommendShop.xml (<recommend ...>
// rows) into a CRecommendTableCache and answers by-code lookups. The members/methods are recovered in unit_140815690.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"

// One <recommend> row (RTTI .?AVCRecommendItem@@, 0x60 bytes): the shop offer shown by the smart recommend dialog.
class CRecommendItem : public CPtred
{
public:
    CRecommendItem();                                       // 0x1408163a0
    virtual ~CRecommendItem() = default;                    //  0 0x1408165d0 (??_G 0x140816770)
    unsigned int m_nCode;                                   // +0x18 "code"
    unsigned int m_nItemId;                                 // +0x1c "itemID"
    int m_nItemRank;                                        // +0x20 "itemRank"
    int m_nItemCount;                                       // +0x24 "itemCount"
    CStringW m_strItemDescription;                          // +0x28 "itemDescription"
    CStringW m_strStoreDescription;                         // +0x30 "storeDescription"
    CStringW m_strBuyButtonText;                            // +0x38 "buyButtonText"
    int m_nNpcImageType;                                    // +0x40 "npcImageType"
    __int64 m_nRequireMoney;                                // +0x48 "requireMoney"
    unsigned int m_nRequireItemId;                          // +0x50 "requireItemID"
    int m_nRequireItemRank;                                 // +0x54 "requireItemRank"
    int m_nRequireItemCount;                                // +0x58 "requireItemCount"
};
MS2_CHECK_SIZE(CRecommendItem, 0x60);
MS2_CHECK_OFFSET(CRecommendItem, m_nCode, 0x18);
MS2_CHECK_OFFSET(CRecommendItem, m_strBuyButtonText, 0x38);
MS2_CHECK_OFFSET(CRecommendItem, m_nRequireItemCount, 0x58);

// The loaded rows (RTTI .?AVCRecommendTableCache@@, 0xa0 bytes): a cache record (file path / write time) with the
// code -> row map. Named by that RTTI (was the placeholder Unk_SmartRecommendShops).
class CRecommendTableCache : public CCacheData
{
public:
    CRecommendTableCache();                              // 0x140816470
    virtual ~CRecommendTableCache() = default;           //  0 0x140816620 (??_G 0x1408167b0)
    ATL::CAtlMap<unsigned int, MS2Ptr<CRecommendItem> > m_items;    // +0x28
    CLockCriticalSection m_lock;                            // +0x70
};
MS2_CHECK_SIZE(CRecommendTableCache, 0xa0);

class CSmartRecommendShopTable : public TSingleton<CSmartRecommendShopTable>,
                                 public CValidData<CSmartRecommendShopTable>
{
public:
    // @0x1414960d0
    CSmartRecommendShopTable() { Load(); }
    // @0x141497570
    virtual ~CSmartRecommendShopTable() {}
    int Load();                                    // loads the table (unit_140815690); 1 when loaded
    int FUN_1408157e0(CString strPath);                     // always 1
    void ClearItems();                                   // forget all rows
    MS2Ptr<CRecommendItem> FUN_140815890(int nCode);        // the row of a code (reloads when the file changed)
    void FUN_140815a10(MS2Ptr<CRecommendItem> spItem);      // add a row
    int FUN_140815ac0(CString strPath);                     // parse the xml into the map
    static void CheckInit();                                // 0x1408167f0
    static void SetInit(bool b);                            // 0x1408176c0
    static bool s_bInit;                                    // 0x143ab1a31
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CRecommendTableCache> m_spData;               // +0x10
    int m_bLoaded;                                          // +0x20
    int m_pad_24;
};
MS2_CHECK_SIZE(CSmartRecommendShopTable, 0x28);
