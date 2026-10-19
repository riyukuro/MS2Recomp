// itemenchantlimittable.h - CItemEnchantLimitTable / CItemEnchantLimitTable::EnchantLimit (RTTI names): the enchant limits per
// item slot read from Table/enchantLimitTable.xml (<ms2><limit slot minLv maxLv maxGrade/>). Header name assumed. Member names
// are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cvaliddata.h"

class CItem;
class CItemData;

// The limit of one equipment slot: the item level band that may be enchanted and the highest enchant grade.
// RTTI CItemEnchantLimitTable::EnchantLimit, 0x20 bytes, base CPtred.
class CItemEnchantLimitTable : public TSingleton<CItemEnchantLimitTable>,
                               public CValidData<CItemEnchantLimitTable>
{
public:
    class EnchantLimit : public CPtred
    {
    public:
        EnchantLimit();                         // 0x14058ee60
        // implicit dtor 0x14058f060 (no vptr store)

        unsigned short m_nMinLv;                // +0x18 "minLv"
        unsigned short m_nMaxLv;                // +0x1a "maxLv"
        int m_nMaxGrade;                        // +0x1c "maxGrade"
    };

    CItemEnchantLimitTable();                   // 0x14058db50
    virtual ~CItemEnchantLimitTable();          // 0x14058dbf0

    int Load();                                 // 0x14058dc50 parses the xml into the map
    int FUN_14058df90(CItem* pItem);            // the item may start an enchant (level band, grade, not excluded)
    int FUN_14058e230(CItem* pItem);            // the same without the enchant grade test
    unsigned FUN_14058e3a0(CItem* pItem);       // the item is at the limit grade
    bool FUN_14058e4a0(CItemData* pData);       // the item data has a limit row
    int FUN_14058e500(unsigned nItemId, int nGrade);   // the item id may be enchanted to a grade

    static void CheckInit();                    // 0x14058f330
    static void SetInit(bool b);                // 0x1405902a0

    static bool s_bInit;                        // DAT_143aafb48

private:
    MS2_LAYOUT_FRIEND;
    struct KeyTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };
    ATL::CAtlMap<int, MS2Ptr<EnchantLimit>, KeyTraits> m_map;   // +0x10 slot -> limit
};
