// ugcdesigntable.h - CUGCDesignTable: the UGC design table (Table/UGCDesign.xml). One row (<list>) per item id, with
// the locale it belongs to, its grade, visibility, price type, prices (price / salePrice / marketMinPrice /
// marketMaxPrice), display order, category and sale tag. Loaded once by CGameApp::InitInstance (?\ms2.cpp) and read
// back by the UGC design / UGC shop UI.
// MS2-UNIT: ?\ugcdesigntable.cpp (0x1400bdb40-0x1400bdde0 .text$di, 0x14089e270-0x1408a0190 .text$mn); method and
// member names are inferred from the xml attributes, the asserts and the CAtlMap instantiation.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

class Unk_140165cf0;                    // the tinyxml element wrapper (FUN_140165cf0 = FirstChildElement)

// One <list> row. RTTI CUGCDesignData, 0x58 bytes, base CPtred; vftable 0x142ce5ea8 (1 slot: deleting destructor).
class CUGCDesignData : public CPtred
{
public:
    CUGCDesignData();                       // 0x14089ed40 (no dtor is declared: the exe's ~CUGCDesignData is the
                                            // synthesized one, 0x14089eeb0, and it does not store the vftable)

    // @0x14089e270 reads the row's attributes (0 when the element is null). nDefaultMarketMaxPrice is used when the
    // row has no marketMaxPrice.
    bool Parse(Unk_140165cf0* pElem, __int64 nDefaultMarketMaxPrice);

    int m_nItemID;                          // +0x18 "itemID" (the map key; set by the loader, not by Parse)
    int m_nItemGrade;                       // +0x1c "itemGrade"
    bool m_bVisible;                        // +0x20 "visible"
    int m_nPriceType;                       // +0x24 "priceType" (1 by default)
    __int64 m_nPrice;                       // +0x28 "price"
    __int64 m_nSalePrice;                   // +0x30 "salePrice"
    __int64 m_nMarketMinPrice;              // +0x38 "marketMinPrice"
    __int64 m_nMarketMaxPrice;              // +0x40 "marketMaxPrice"
    int m_nSaleTag;                         // +0x48 "saleTag"
    int m_nCategory;                        // +0x4c "category"
    int m_nDpOrder;                         // +0x50 "dpOrder"

    int FUN_14089e200();                    // the price type of the row (uiugcitemeditdialog.cpp)
};
MS2_CHECK_SIZE(CUGCDesignData, 0x58);
MS2_CHECK_OFFSET(CUGCDesignData, m_nItemGrade, 0x1c);
MS2_CHECK_OFFSET(CUGCDesignData, m_nPrice, 0x28);
MS2_CHECK_OFFSET(CUGCDesignData, m_nMarketMaxPrice, 0x40);
MS2_CHECK_OFFSET(CUGCDesignData, m_nSaleTag, 0x48);
MS2_CHECK_OFFSET(CUGCDesignData, m_nDpOrder, 0x50);

typedef MS2Ptr<CUGCDesignData> CUGCDesignDataPtr;

// The table. RTTI CUGCDesignTable, 0xb0 bytes: TSingleton<CUGCDesignTable> +0 (vftable 0x142ce5e60), CCacheData +8
// (0x142ce5e70), CValidData<CUGCDesignTable> +0x30 (0x142ce5e80), the lock +0x38 and the id -> row map +0x68.
class CUGCDesignTable : public TSingleton<CUGCDesignTable>,
                        public CCacheData,
                        public CValidData<CUGCDesignTable>
{
public:
    CUGCDesignTable();                      // 0x14089e400
    virtual ~CUGCDesignTable();             // 0x14089e590

    bool Load();                                            // 0x14089e950 reloads when the xml changed on disk
    CUGCDesignDataPtr GetData(unsigned int nItemID);        // 0x14089e9f0 the row for an item id (null when missing)
    ATL::CAtlMap<unsigned int, CUGCDesignDataPtr>& GetMap() { return m_map; }   // 0x141b47790 (inline COMDAT, uiugcitemeditdialog.cpp)

    // Both are hooked (MS2_REPLACE_METHOD's thunk derives from this class and calls them), so they stay public.
    bool Reload();                          // 0x14089e630 parses the xml and fills the map
    void Clear();                           // 0x14089e990 drops every row (lock-guarded)

    static bool s_bInit;                    // DAT_143ab22b0 set by the loader (no CheckInit in this unit)

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x38
    ATL::CAtlMap<unsigned int, CUGCDesignDataPtr> m_map;    // +0x68 id -> row
};
MS2_CHECK_SIZE(CUGCDesignTable, 0xb0);
MS2_CHECK_OFFSET(CUGCDesignTable, m_lock, 0x38);
MS2_CHECK_OFFSET(CUGCDesignTable, m_map, 0x68);
