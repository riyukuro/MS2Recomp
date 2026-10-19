// seasondatatable.h - CSeasonDataTable and its row types (RTTI names): the ranking seasons read from
// Table/SeasonData_<type>.xml, Table/SeasonReward_mapleSurvival.xml and the season name table. Header name assumed;
// member names are invented from use (layouts proven against the ctors/dtors and the loaders).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"

// The ranking categories (key of every table map); 9 = none.
enum SeasonRankType : int {};

// One season of one category, 0x70 bytes.
class CSeasonData : public CPtred
{
public:
    CSeasonData();                                      // 0x140790bd0
    virtual ~CSeasonData();                             // 0x140790cf0
    int GetGrade(int nValue);                           // 0x140790d50 grade (0..6) of a ranking value

    SeasonRankType m_type;                              // +0x18
    int m_nSeasonID;                                    // +0x1c "id"
    CStringW m_strDisplayName;                          // +0x20 from the name table
    CStringW m_strSeasonName;                           // +0x28 "seasonName"
    CMsTime m_start;                                    // +0x30 "eventStart"
    CMsTime m_end;                                      // +0x40 "eventEnd"
    int m_grades[7];                                    // +0x50 "grade1".."grade7"
};
MS2_CHECK_SIZE(CSeasonData, 0x70);

// The season of a category that is running now, 0x30 bytes.
class CSeasonDataCurrent : public CPtred
{
public:
    CSeasonDataCurrent();                               // 0x140790da0
    virtual ~CSeasonDataCurrent();                      // 0x140790e10

    MS2Ptr<CSeasonData> m_spData;                       // +0x18
    POSITION m_position;                                // +0x28 position of m_spData in the season list
};
MS2_CHECK_SIZE(CSeasonDataCurrent, 0x30);

// One <SeasonReward> row, 0xa8 bytes.
class CSeasonRewardData : public CPtred
{
public:
    CSeasonRewardData();                                // 0x140790e80
    virtual ~CSeasonRewardData();                       // 0x140791000

    int m_nRewardID;                                    // +0x18 "rewardID"
    int m_nRankType;                                    // +0x1c "rankType"
    int m_nRewardType;                                  // +0x20 "rewardType"
    int m_nValue;                                       // +0x24 "value"
    CMsTime m_startDate;                                // +0x28 "startdate"
    CStringW m_strMailSender;                           // +0x38 "systemMailSender"
    CStringW m_strMailSubject;                          // +0x40 "systemMailSubject"
    CStringW m_strMailContent;                          // +0x48 "systemMailContent"
    __int64 m_nRewardMeso;                              // +0x50 "rewardMeso"
    unsigned m_nItemID[5];                              // +0x58 "rewardItemID1.."
    int m_nItemRank[5];                                 // +0x6c
    int m_nItemCount[5];                                // +0x80
    int m_nItemDuration[5];                             // +0x94
};
MS2_CHECK_SIZE(CSeasonRewardData, 0xa8);

// The rewards of one rewardID, 0x60 bytes.
class CSeasonReward : public CPtred
{
public:
    CSeasonReward();                                    // 0x140791070
    virtual ~CSeasonReward();                           // 0x140791100
    void Initialize(int nID, int nType, const CMsTime& rTime);   // 0x140791150
    int GetID();                                        // 0x1407911a0
    CMsTime GetTime();                                  // 0x1407911c0
    void Add(MS2Ptr<CSeasonRewardData> spData);         // 0x140791200
    int CalcKey(int nCategory, int nValue);             // 0x140791380
    void GetData(ATL::CAtlList<MS2Ptr<CSeasonRewardData> >& rOut);   // 0x1407913f0

    int m_nID;                                          // +0x18
    int m_nType;                                        // +0x1c
    CMsTime m_time;                                     // +0x20
    ATL::CRBMap<int, MS2Ptr<CSeasonRewardData> > m_data;   // +0x30 key = category * 1000000 + value
};
MS2_CHECK_SIZE(CSeasonReward, 0x60);

// Display names of the seasons by contents id, 0x48 bytes.
class CSeasonContentsName : public CPtred
{
public:
    typedef ATL::CRBMap<int, CStringW> Names;
    CSeasonContentsName();                              // 0x1407914b0
    virtual ~CSeasonContentsName();                     // 0x140791500
    void Add(int nContents, int nSeason, CStringW strName);   // 0x140791550
    CStringW Find(int nContents, int nSeason);          // 0x140791620

    ATL::CRBMap<int, TPtrValue<Names> > m_data;         // +0x18 contents id -> (season -> name)
};
MS2_CHECK_SIZE(CSeasonContentsName, 0x48);

// RTTI CSeasonDataTable, 0x148 bytes.
class CSeasonDataTable : public TSingleton<CSeasonDataTable>
{
public:
    typedef ATL::CRBMap<int, MS2Ptr<CSeasonData> > Seasons;
    typedef ATL::CRBMap<int, MS2Ptr<CSeasonReward> > Rewards;

    CSeasonDataTable();                                 // 0x140791740
    virtual ~CSeasonDataTable();                        // 0x140791a10
    void Tick();                                        // 0x140791ac0 refreshes every category once a minute
    void Callback1();                                   // 0x140791c10
    void Callback2();                                   // 0x140791c20
    bool Load();                                        // 0x140791c30
    MS2Ptr<CSeasonData> GetCurrent(SeasonRankType type);   // 0x140791e40
    int GetCurrentID(SeasonRankType type);              // 0x140791f50
    MS2Ptr<CSeasonData> Find(SeasonRankType type, int nSeason);   // 0x140791fd0
    void GetUpcoming(SeasonRankType type, ATL::CAtlArray<MS2Ptr<CSeasonData> >& rOut);   // 0x1407920d0
    void GetRecent(SeasonRankType type, ATL::CAtlArray<MS2Ptr<CSeasonData> >& rOut);   // 0x140792250
    SeasonRankType GetType(CStringA strName);           // 0x140792380
    CStringW GetDisplayName(MS2Ptr<CSeasonData> spData);   // 0x140792460
    CStringW GetContentsName(MS2Ptr<CSeasonData> spData, int nContents);   // 0x1407925e0
    int ReadData(SeasonRankType type, CStringA strPath);   // 0x1407927d0
    void Refresh(SeasonRankType type, int nMode);       // 0x140792b90
    bool ReadNames();                                   // 0x1407931f0
    MS2Ptr<CSeasonDataCurrent> GetCurrentRecord(SeasonRankType type);   // 0x140793690
    POSITION GetRecentPosition(SeasonRankType type);    // 0x140793750
    void Log(CStringA strText);                         // 0x1407938a0
    void SetCurrent(SeasonRankType type, MS2Ptr<CSeasonDataCurrent> spCurrent);   // 0x1407938d0
    int ReadRewards();                                  // 0x140793990
    MS2Ptr<CSeasonReward> GetReward(SeasonRankType type);   // 0x140794310

    ATL::CRBMap<SeasonRankType, TPtrValue<Seasons> > m_seasons;   // +0x08 per category: season id -> season
    std::map<SeasonRankType, CStringA> m_typeNames;     // +0x38 category -> xml name
    CLockCriticalSection m_lock;                        // +0x48
    ATL::CRBMap<SeasonRankType, MS2Ptr<CSeasonDataCurrent> > m_currents;   // +0x78
    ATL::CRBMap<SeasonRankType, POSITION> m_positions;  // +0xa8 last position per category
    __int64 m_nLastUpdate;                              // +0xd8
    ATL::CRBMap<SeasonRankType, MS2Ptr<CSeasonContentsName> > m_names;   // +0xe0
    int m_bInitialized;                                 // +0x110
    ATL::CRBMap<SeasonRankType, TPtrValue<Rewards> > m_rewards;   // +0x118
};
MS2_CHECK_SIZE(CSeasonDataTable, 0x148);
MS2_CHECK_OFFSET(CSeasonDataTable, m_typeNames, 0x38);
MS2_CHECK_OFFSET(CSeasonDataTable, m_lock, 0x48);
MS2_CHECK_OFFSET(CSeasonDataTable, m_currents, 0x78);
MS2_CHECK_OFFSET(CSeasonDataTable, m_nLastUpdate, 0xd8);
MS2_CHECK_OFFSET(CSeasonDataTable, m_bInitialized, 0x110);
MS2_CHECK_OFFSET(CSeasonDataTable, m_rewards, 0x118);
