// carcadedatatable.h - PLACEHOLDER for CArcadeDataTable (RTTI .?AVCArcadeDataTable@@, 0xe8 bytes). NOT an original header.
// Bases: TSingleton<CArcadeDataTable> at +0x0, CValidData<CArcadeDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates and loads (Load, 0x1401a2e40). The loaders, getters and
// the row classes are ?\arcademaindata.cpp (0x1401a2e40-0x1401adea0); member and method names are invented from use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include <atlcoll.h>
#include <utility>
#include <vector>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"

// One <arcadeGame> row of Table/arcadeGame.xml (RTTI CArcadeMainData, 0x30 bytes).
class CArcadeMainData : public CPtred
{
public:
    CArcadeMainData();                  // 0x1401a8b20
    // ~CArcadeMainData is implicit (0x1401a8f10): the exe dtor stores no vptr.

    int m_nId;                          // +0x18 "id"
    int m_nSortingOrder;                // +0x1c "sortingOrder"
    CStringW m_strArcadeBanner;         // +0x20 "arcadeBanner"
    unsigned m_nTargetField;            // +0x28 "targetField"
    bool m_bIsEventArcade;              // +0x2c "isEventArcade"
};
MS2_CHECK_SIZE(CArcadeMainData, 0x30);
MS2_CHECK_OFFSET(CArcadeMainData, m_nTargetField, 0x28);

// One <reward> row of Table/Server/arcadeReward.xml (RTTI CArcadeRewardData, 0x30 bytes).
class CArcadeRewardData : public CPtred
{
public:
    CArcadeRewardData();                // 0x1401a8b90
    // ~CArcadeRewardData is implicit (0x1401a8f40): the exe dtor stores no vptr.

    int m_nArcadeId;                    // +0x18 the <arcadeGame> "arcadeId"
    int m_nRound;                       // +0x1c "round"
    float m_fExpRate;                   // +0x20 "expRate"
    __int64 m_nMeso;                    // +0x28 "meso"
};
MS2_CHECK_SIZE(CArcadeRewardData, 0x30);
MS2_CHECK_OFFSET(CArcadeRewardData, m_nMeso, 0x28);

// One <rank> row of Table/arcadeGameRecord.xml: the score and the display name of the record holder npc. A plain
// std::pair (its ctor 0x1401a3d20, operator= 0x1401a3d50/0x1401a3db0, operator< 0x1401a3e00 and operator> 0x1401a3e70
// are this unit's COMDATs); the records are sorted with std::greater.
typedef std::pair<int, CStringW> Unk_ArcadeRecord;
MS2_CHECK_SIZE(Unk_ArcadeRecord, 0x10);

class CArcadeDataTable : public TSingleton<CArcadeDataTable>, public CValidData<CArcadeDataTable>
{
public:
    typedef MS2SvrPtr<CArcadeMainData> MainPtr;
    typedef MS2SvrPtr<CArcadeRewardData> RewardPtr;
    typedef ATL::CDefaultElementTraits<int> KeyTraits;    // the exe passes the key by const& (not CPrimitiveElementTraits)
    typedef ATL::CAtlMap<int, MainPtr, KeyTraits> MainMap;
    typedef ATL::CAtlMap<int, std::vector<Unk_ArcadeRecord>, KeyTraits> RecordMap;
    typedef ATL::CAtlMap<int, std::vector<RewardPtr>, KeyTraits> RewardMap;
    enum { MAX_ROUND = 51 };

    // @0x141495e10
    CArcadeDataTable() {}
    // @0x1414973c0
    virtual ~CArcadeDataTable() {}

    bool Load();                                                    // 0x1401a2e40
    bool LoadMain();                                                // 0x1401a2e90
    bool LoadReward();                                              // 0x1401a31a0 (server table; no client caller)
    bool LoadRecord();                                              // 0x1401a35d0
    MainPtr GetMainData(int nId);                                   // 0x1401a3940
    void GetMainDataList(std::vector<MainPtr>& out);                // 0x1401a3a00 (sorted)
    void GetRecords(int nId, std::vector<Unk_ArcadeRecord>& out) const; // 0x1401a3ae0
    RewardPtr GetReward(int nId, int nRound) const;                 // 0x1401a3b40

    static void CheckInit();            // 0x1401a9600
    static void SetInit(bool b);        // 0x1401abe90
    static bool s_bInit;                // 0x143aac2a0

private:
    MS2_LAYOUT_FRIEND;
    MainMap m_mapMain;                  // +0x10
    RecordMap m_mapRecord;              // +0x58
    RewardMap m_mapReward;              // +0xa0 (MAX_ROUND slots per arcade)
};
MS2_CHECK_SIZE(CArcadeDataTable, 0xe8);
