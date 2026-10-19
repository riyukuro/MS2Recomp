// rewardcontentstable.h - RewardContentsTable (RTTI) and its rows: RewardContents (Table/RewardContent.xml),
// RewardContentsItemTable / RewardContentsItemGroup / RewardContentsItem (Table/RewardContentItemTable.xml) and the meso
// tables (RewardContentMesoTable.xml, RewardContentMesoStaticTable.xml). A reward id gives meso, exp, adventure exp and
// item rewards for a level. Header name assumed (the unit is commonfiles\rewardcontentstable.cpp); member names are
// inferred from the xml attributes. The rewardcontentstable.h placeholder forwards here.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/dclevelrange.h"

// One item row of a reward group, 0x38 bytes: an ItemEntity with a probability.
class RewardContentsItem : public ItemEntity
{
public:
    RewardContentsItem();                           // 0x1407703a0
    virtual ~RewardContentsItem() = default;                // 0x140778260
    virtual void vfunc_2(void* pNode);              // 0x1407703f0 reads the item and "prob"
    int m_nProb;                                    // +0x30 "prob" (0 = always)
};
MS2_CHECK_SIZE(RewardContentsItem, 0x38);
MS2_CHECK_OFFSET(RewardContentsItem, m_nProb, 0x30);

// One <v> group of an item table, 0x38 bytes: items for a level range.
class RewardContentsItemGroup : public CPtred
{
public:
    RewardContentsItemGroup();                      // 0x140770440
    virtual ~RewardContentsItemGroup() = default;           // 0x140778280
    bool Load(void* pNode);                         // 0x1407704a0 "minLevel" / "maxLevel" and the <item> rows
    bool GetItems(unsigned short nLevel, std::vector<ItemEntity>& rItems);   // 0x140770650
    Unk_DcLevelRange m_levelRange;                  // +0x18 "minLevel" / "maxLevel"
    std::vector<MS2Ptr<RewardContentsItem> > m_items;   // +0x20
};
MS2_CHECK_SIZE(RewardContentsItemGroup, 0x38);
MS2_CHECK_OFFSET(RewardContentsItemGroup, m_items, 0x20);

// One <table> of RewardContentItemTable.xml, 0x38 bytes.
class RewardContentsItemTable : public CPtred
{
public:
    RewardContentsItemTable();                      // 0x1407707c0
    virtual ~RewardContentsItemTable() = default;           // 0x1407782b0
    bool Load(void* pNode);                         // 0x140770810
    void GetItems(unsigned short nLevel, std::vector<ItemEntity>& rItems);   // 0x140770970 first group that fits
    unsigned m_nItemTableId;                             // +0x18 "itemTableID"
    std::vector<MS2Ptr<RewardContentsItemGroup> > m_groups;   // +0x20
};
MS2_CHECK_SIZE(RewardContentsItemTable, 0x38);
MS2_CHECK_OFFSET(RewardContentsItemTable, m_groups, 0x20);

// One <v> of RewardContent.xml, 0x40 bytes.
class RewardContents : public CPtred
{
public:
    RewardContents();                               // 0x140770a50
    virtual ~RewardContents() = default;                    // 0x140778240
    bool Load(void* pNode);                         // 0x140770af0
    unsigned m_nRewardId;                                // +0x18 "rewardID"
    unsigned m_nMesoTableId;                             // +0x1c "mesoTableID"
    double m_dMesoFactor;                           // +0x20 "mesoFactor"
    unsigned m_nExpTableId;                              // +0x28 "expTableID"
    double m_dExpFactor;                            // +0x30 "expFactor"
    unsigned m_nItemTableId;                             // +0x38 "itemTableID"
    unsigned m_nAdventureExpTableId;                     // +0x3c "adventureExpTableID"
};
MS2_CHECK_SIZE(RewardContents, 0x40);
MS2_CHECK_OFFSET(RewardContents, m_nAdventureExpTableId, 0x3c);

// RTTI RewardContentsTable, 0x38 bytes.
class RewardContentsTable : public TSingleton<RewardContentsTable>
{
public:
    struct Result
    {
        Result();                                   // 0x140770c00
        __int64 m_nMeso;                            // +0x00
        __int64 m_nExp;                             // +0x08
        __int64 m_nAdventureExp;                    // +0x10
        std::vector<ItemEntity> m_items;            // +0x18
    };
    RewardContentsTable();                          // 0x140770c50
    virtual ~RewardContentsTable();                 // 0x140770cd0
    bool Load();                                    // 0x140770d30 meso tables, item tables, contents
    bool GetReward(unsigned nRewardId, unsigned short nLevel, Result& rResult);   // 0x140770e40
    bool ReadMesoTable(const CStringA& strFile);    // 0x140771030
    bool ReadItemTable();                           // 0x1407713d0
    bool ReadContents();                            // 0x140771730
    __int64 GetMeso(unsigned nTableId, double dFactor, unsigned short nLevel);    // 0x1407719b0
    void GetItems(unsigned nTableId, unsigned short nLevel, std::vector<ItemEntity>& rItems);   // 0x140771ad0

    std::map<unsigned, std::vector<__int64> > m_mesoTables;                  // +0x08 meso table id -> meso by level
    std::map<unsigned, MS2Ptr<RewardContentsItemTable> > m_itemTables;       // +0x18
    std::map<unsigned, MS2Ptr<RewardContents> > m_rewards;                   // +0x28
};
MS2_CHECK_SIZE(RewardContentsTable::Result, 0x30);
MS2_CHECK_SIZE(RewardContentsTable, 0x38);
MS2_CHECK_OFFSET(RewardContentsTable, m_mesoTables, 0x08);
MS2_CHECK_OFFSET(RewardContentsTable, m_itemTables, 0x18);
MS2_CHECK_OFFSET(RewardContentsTable, m_rewards, 0x28);
