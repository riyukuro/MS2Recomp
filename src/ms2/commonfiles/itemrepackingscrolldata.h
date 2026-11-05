// itemrepackingscrolldata.h - CItemRePackingScrollData / CItemRePackingScrollTable (RTTI names): the item re-packing
// scroll table read from Table/itemRePackingScroll.xml (<rePackingScroll id minLv maxLv slot rank petType .../>).
// Header name assumed. Member names are invented from use.
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

class TiXmlElement;                    // the tinyxml element wrapper
class CItem;

// One <rePackingScroll> row. RTTI CItemRePackingScrollData, 0x68 bytes, base CPtred, only the deleting destructor is
// virtual.
class CItemRePackingScrollData : public CPtred
{
public:
    CItemRePackingScrollData();             // 0x14061ce90
    virtual ~CItemRePackingScrollData();    // 0x14061cf20

    int m_nId;                              // +0x18 "id"
    int m_nPet;                             // +0x1c 1 when petType == 1 (the scroll repacks pets)
    unsigned short m_nMinLv;                // +0x20 "minLv"
    unsigned short m_nMaxLv;                // +0x22 "maxLv"
    ATL::CAtlArray<unsigned int> m_arrSlot; // +0x28 "slot"
    ATL::CAtlArray<unsigned int> m_arrRank; // +0x48 "rank"
};
MS2_CHECK_SIZE(CItemRePackingScrollData, 0x68);
MS2_CHECK_OFFSET(CItemRePackingScrollData, m_arrSlot, 0x28);
MS2_CHECK_OFFSET(CItemRePackingScrollData, m_arrRank, 0x48);

typedef MS2Ptr<CItemRePackingScrollData> CItemRePackingScrollDataPtr;

// The table. RTTI CItemRePackingScrollTable, 0xb0 bytes: TSingleton +0, CCacheData +8, CValidData +0x30, the lock +0x38
// and the id -> row map +0x68. Created by CGameApp::InitInstance (?\ms2.cpp).
class CItemRePackingScrollTable : public TSingleton<CItemRePackingScrollTable>,
                                  public CCacheData,
                                  public CValidData<CItemRePackingScrollTable>
{
public:
    CItemRePackingScrollTable();            // 0x14061cfa0
    virtual ~CItemRePackingScrollTable();   // 0x14061d070

    int Load();                             // 0x14061d130 parses the xml into the map (always 1)
    int Reload();                           // 0x14061d530
    CItemRePackingScrollDataPtr GetData(int nId);               // 0x14061d5b0 the row for an id (null when missing)
    // 0x14061d670: why an item can't be re-packed with the scroll row (0 = fine; the values are error codes)
    static int Check(MS2Ptr<CItem> pItem, CItemRePackingScrollDataPtr pData);

    static void CheckInit();                // 0x14061e350
    static void SetInit(bool b);            // 0x14061f220

    static bool s_bInit;                    // DAT_143aaff60

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                        // +0x38
    ATL::CAtlMap<int, CItemRePackingScrollDataPtr> m_map;               // +0x68 id -> row
};
MS2_CHECK_SIZE(CItemRePackingScrollTable, 0xb0);
MS2_CHECK_OFFSET(CItemRePackingScrollTable, m_lock, 0x38);
MS2_CHECK_OFFSET(CItemRePackingScrollTable, m_map, 0x68);
