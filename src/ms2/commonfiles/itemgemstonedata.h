// itemgemstonedata.h - CItemGemStoneData / CItemGemStoneUpgradeTable (RTTI names): the rows of Table/itemGemstoneUpgrade.xml
// (a gemstone item, its level, the item it upgrades to, the ingredients and the equip parts it fits) and the table that
// loads them. Header name assumed from the unit path; member and helper names are invented from the xml attributes and use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/commonstruct_wa.h"

// One row, 0x60 bytes (CPtred base, the ingredient container is embedded at +0x30).
class CItemGemStoneData : public CPtred
{
public:
    CItemGemStoneData();                    // 0x1405b0b70
    virtual ~CItemGemStoneData();           // 0x1405b0c00 (??_G 0x1405b2700)

    unsigned short m_nSlot;                 // +0x18 "GemLevel"
    int m_nLinked;                          // +0x1c "NextItemID": the id of the row this one upgrades to (0 = none)
    CStringW m_strName;                     // +0x20 "IconId"
    unsigned m_nMask;                       // +0x28 "EquipPart" bit mask (default 7)
    CIngredientContainer m_ingredients;     // +0x30 "IngredientItemID1..4" / "IngredientCount1..4"
};
MS2_CHECK_SIZE(CItemGemStoneData, 0x60);
MS2_CHECK_OFFSET(CItemGemStoneData, m_nSlot, 0x18);
MS2_CHECK_OFFSET(CItemGemStoneData, m_nLinked, 0x1c);
MS2_CHECK_OFFSET(CItemGemStoneData, m_strName, 0x20);
MS2_CHECK_OFFSET(CItemGemStoneData, m_nMask, 0x28);
MS2_CHECK_OFFSET(CItemGemStoneData, m_ingredients, 0x30);

// Bases (RTTI): TSingleton at +0, CCacheData at +0x8, CValidData at +0x30; 0xb0 bytes.
class CItemGemStoneUpgradeTable : public TSingleton<CItemGemStoneUpgradeTable>, public CCacheData,
                                  public CValidData<CItemGemStoneUpgradeTable>
{
public:
    typedef MS2Ptr<CItemGemStoneData> DataPtr;
    typedef ATL::CAtlMap<unsigned, DataPtr> DataMap;

    CItemGemStoneUpgradeTable();                                // 0x1405b0c50
    virtual ~CItemGemStoneUpgradeTable();                       // 0x1405b0d20 (??_G 0x1405b2740)

    int Load();                                                 // 0x1405b0dc0 itemGemstoneUpgrade.xml
    DataPtr FindData(unsigned nId);                        // 0x1405b1a60 find a row (an empty pointer for none)
    int Reload();                                               // 0x1405b1b50 clears the rows and loads again
    static void CheckInit();                                    // 0x1405b27c0
    static void SetInit(bool b);                                // 0x1405b36e0

    static bool s_bInit;                                        // 0x143aafd20
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                // +0x38
    DataMap m_rows;                                             // +0x68 item id -> row
};
MS2_CHECK_SIZE(CItemGemStoneUpgradeTable, 0xb0);
MS2_CHECK_OFFSET(CItemGemStoneUpgradeTable, m_lock, 0x38);
MS2_CHECK_OFFSET(CItemGemStoneUpgradeTable, m_rows, 0x68);
