// adventureleveltablehelper.h - CAdventureLevelTableHelper / CAdventureLevelTable / CAdventureLevelMissionData (RTTI names).
// Header name assumed. Member and helper names are invented from use. The maps at +0x10 / +0x20 are never filled
// by any recovered function (their loaders are stubs returning true), so their element types are placeholders.
#pragma once
#include <afx.h>
#include <map>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

// One adventure-level mission row. 0x28 bytes (CPtred 0x18 + three fields).
class CAdventureLevelMissionData : public CPtred
{
public:
    CAdventureLevelMissionData();               // 0x140195660
    virtual ~CAdventureLevelMissionData() = default;    // 0x140195700 (implicit: the exe stores no vptr)

    int m_nId;                                  // +0x18 (name invented)
    bool m_b1c;                                 // +0x1c
    void* m_p20;                                // +0x20
};
MS2_CHECK_SIZE(CAdventureLevelMissionData, 0x28);
MS2_CHECK_OFFSET(CAdventureLevelMissionData, m_p20, 0x20);

// AdventureLevelReward.xml row (the value of the map at +0x48, keyed by level).
struct CAdventureLevelReward
{
    int m_nType;                                // 0 none, 1 "item", 2 "statPoint"
    int m_nId;
    int m_nRank;
    int m_nValue;
};
MS2_CHECK_SIZE(CAdventureLevelReward, 0x10);

// AdventureLevelAbility.xml row (the value of the map at +0x70, keyed by additionalEffectId). 0x1c bytes.
struct CAdventureLevelAbility
{
    unsigned m_nEffectId;                       // +0x00
    int m_nId;                                  // +0x04 "id"; 0 means no ability
    unsigned m_nRequireLevel;                   // +0x08
    int m_nInterval;                            // +0x0c level step per extra count
    int m_nMaxCount;                            // +0x10 (read as a ushort)
    float m_fStartValue;                        // +0x14
    float m_fAddValue;                          // +0x18

    unsigned short GetCount(unsigned nLevel) const;         // 0x140195910
    int GetLevelOfCount(unsigned nLevel) const;             // 0x1401959d0
    float GetPercent(unsigned nLevel) const;                // 0x140195a20
};
MS2_CHECK_SIZE(CAdventureLevelAbility, 0x1c);

// AdventureLevelMission.xml row (the value of the map at +0x80, keyed by missionId). 0x14 bytes.
struct CAdventureLevelMission
{
    int m_nCount;                               // missionCount
    int m_nOne;                                 // always 1
    unsigned m_nItemId;
    int m_nItemRank;
    int m_nItemCount;
};
MS2_CHECK_SIZE(CAdventureLevelMission, 0x14);

// Singleton wrapper over the table; +8 caches a pointer to the current level row.
class CAdventureLevelTableHelper : public TSingleton<CAdventureLevelTableHelper>
{
public:
    CAdventureLevelTableHelper();               // 0x140195470
    virtual ~CAdventureLevelTableHelper();      // 0x1401954b0

    void FindCurrent();                         // 0x1401954e0
    bool IsReached(unsigned nLevel);            // 0x1401955f0
    CAdventureLevelAbility* GetCurrent();       // 0x140195640

    CAdventureLevelAbility* m_pCurrent;         // +0x08
};
MS2_CHECK_SIZE(CAdventureLevelTableHelper, 0x10);
MS2_CHECK_OFFSET(CAdventureLevelTableHelper, m_pCurrent, 0x08);

// Stand-in element types of the two unused containers below. The exe's nodes are 0x30 bytes (set of a 16-byte key,
// map<unsigned, 8-byte value>); the real types are unrecovered and never constructed with data.
struct Unk_ALValue { unsigned long long m_v; };

class CAdventureLevelTable : public TSingleton<CAdventureLevelTable>, public CValidData<CAdventureLevelTable>
{
public:
    CAdventureLevelTable();                     // 0x140195b80
    virtual ~CAdventureLevelTable();            // 0x140195c60

    bool LoadAll();                              // 0x140195d30
    bool LoadUnused1();                          // 0x1401961b0
    bool LoadUnused2();                          // 0x1401961a0
    bool LoadReward();                           // 0x1401961c0
    bool LoadAbility();                          // 0x140196550
    bool LoadMission();                          // 0x1401968b0
    void* FindUnused1(unsigned nKey, unsigned nSub);    // 0x140195dd0 (always null; the +0x10 set is never filled)
    void* FindUnused2(unsigned nKey);           // 0x140195e00 (always null)
    const CAdventureLevelReward* GetReward(unsigned nLevel);        // 0x140195e30
    const CAdventureLevelAbility* GetAbility(unsigned nEffectId);   // 0x140195ed0
    const CAdventureLevelMission* GetMission(unsigned nMissionId);  // 0x140196090
    std::vector<unsigned>& GetLevels();         // 0x140195eb0
    std::vector<unsigned>& GetAbilityIds();     // 0x140195f50
    int CountUnclaimedRewards(unsigned nLevel, const std::set<unsigned>& setClaimed);    // 0x140195f70
    void CollectMissionIds(std::vector<unsigned>& aOut) const;         // 0x140196110

    std::map<unsigned long long, unsigned long long> m_map10;             // +0x10 placeholder, never filled (a 16-byte map: _Tidy takes the iterator conversion)
    std::map<unsigned, Unk_ALValue> m_map20;    // +0x20 placeholder, never filled
    std::vector<unsigned> m_vecLevels;          // +0x30 reward levels in file order
    std::map<unsigned, CAdventureLevelReward> m_mapReward;      // +0x48
    std::vector<unsigned> m_vecAbilityIds;      // +0x58 sorted by required level
    std::map<unsigned, CAdventureLevelAbility> m_mapAbility;    // +0x70
    std::map<unsigned, CAdventureLevelMission> m_mapMission;    // +0x80
};
MS2_CHECK_SIZE(CAdventureLevelTable, 0x90);
MS2_CHECK_OFFSET(CAdventureLevelTable, m_mapMission, 0x80);
