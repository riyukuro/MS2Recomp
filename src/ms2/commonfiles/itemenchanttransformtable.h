// itemenchanttransformtable.h - CEnchantTransformData / CItemEnchantTransformTable (RTTI names): the item enchant transform
// table read from Table/ItemEnchantTransform.xml (<transform inputRank inputLimitLevel inputEnchantLevel inputSlot
// inputItemId needMeso output1Id/Rank/Count output2Id/Rank/Count/>). Header name assumed. Member names are invented
// from use.
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

class CItem;

// The xml "inputRank" value, printed by its number in the row key.
enum EnchantTransformRank
{
    ENCHANT_TRANSFORM_RANK_0 = 0,
};

// One <transform> row. RTTI CEnchantTransformData, 0x80 bytes, base CPtred, vftable 0x142d60988 (the deleting destructor).
class CEnchantTransformData : public CPtred
{
public:
    CEnchantTransformData();                                // 0x140591330
    virtual ~CEnchantTransformData();                       // 0x1405913b0 (??_G 0x140593130)

    __int64 m_nNeedMeso;                                    // +0x18 "needMeso"
    ATL::CAtlArray<unsigned int> m_arrOutputId;             // +0x20 "output1Id" / "output2Id"
    ATL::CAtlArray<unsigned int> m_arrOutputRank;           // +0x40 "output1Rank" / "output2Rank"
    ATL::CAtlArray<unsigned int> m_arrOutputCount;          // +0x60 "output1Count" / "output2Count"
};
MS2_CHECK_SIZE(CEnchantTransformData, 0x80);
MS2_CHECK_OFFSET(CEnchantTransformData, m_nNeedMeso, 0x18);
MS2_CHECK_OFFSET(CEnchantTransformData, m_arrOutputId, 0x20);
MS2_CHECK_OFFSET(CEnchantTransformData, m_arrOutputRank, 0x40);
MS2_CHECK_OFFSET(CEnchantTransformData, m_arrOutputCount, 0x60);

typedef MS2Ptr<CEnchantTransformData> CEnchantTransformDataPtr;

// The table. RTTI CItemEnchantTransformTable, 0xe0 bytes: TSingleton +0, CValidData +8, the lock +0x10, the cache record of
// the xml +0x40, the row key -> row map +0x50 and the item id -> lowest input enchant level map +0x98.
class CItemEnchantTransformTable : public TSingleton<CItemEnchantTransformTable>,
                                   public CValidData<CItemEnchantTransformTable>
{
public:
    CItemEnchantTransformTable();                           // 0x140591410
    virtual ~CItemEnchantTransformTable();                  // 0x140591510 (??_G 0x140593170)

    int FUN_1405915b0();                                    // loads the xml (CValidData init)
    int LoadItemEnchantTransform();                                    // parses the xml into the maps
    static int FUN_140592110(MS2Ptr<CItem> spItem);        // the item can be transformed
    CEnchantTransformDataPtr FUN_140592330(const CString& strKey);   // the row of a key (reloads when the xml changed)
    CEnchantTransformDataPtr FUN_140592430(int nItemId, EnchantTransformRank eRank, int nLimitLevel, int nEnchantLevel, int nSlot);
    CEnchantTransformDataPtr FUN_1405924d0(MS2Ptr<CItem> spItem);   // the row of an item
    unsigned int FUN_140592620(unsigned int nItemId);       // the lowest input enchant level of an item id
    static CString FUN_140592090(int nItemId, EnchantTransformRank eRank, int nLimitLevel, int nEnchantLevel, int nSlot);   // row key
    static void CheckInit();                                // 0x1405931f0
    static void SetInit(bool b);                            // 0x1405940e0
    static bool s_bInit;                                    // DAT_143aafb58

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x10
    MS2Ptr<CCacheData> m_spCache;                           // +0x40
    ATL::CAtlMap<CString, CEnchantTransformDataPtr, ATL::CStringElementTraits<CString> > m_map;   // +0x50 key -> row
    ATL::CAtlMap<unsigned int, unsigned int> m_mapLimit;    // +0x98 item id -> lowest input enchant level
};
MS2_CHECK_SIZE(CItemEnchantTransformTable, 0xe0);
MS2_CHECK_OFFSET(CItemEnchantTransformTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CItemEnchantTransformTable, m_spCache, 0x40);
MS2_CHECK_OFFSET(CItemEnchantTransformTable, m_map, 0x50);
MS2_CHECK_OFFSET(CItemEnchantTransformTable, m_mapLimit, 0x98);
