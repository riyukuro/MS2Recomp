// individualarenadata.h - IndividualArenaData / CIndividualArenaDataTable (RTTI names): the individual-arena (PvP) table
// read from Table/IndividualArena.xml (<individualArena arenaType arenaName arenaDetail bannerPath fieldID playerCount
// rewardItemId1 reward1Winner reward1Loser rewardItemId2 reward2Winner reward2Loser/>). Header name assumed; member
// names come from the xml attributes.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One row. RTTI IndividualArenaData, 0x50 bytes, base CPtred; vftable 1 slot (dtor; deleting dtor 0x14051b180).
class IndividualArenaData : public CPtred
{
public:
    IndividualArenaData();              // 0x14051a170
    virtual ~IndividualArenaData();     // 0x14051a220

    int m_nArenaType;                   // +0x18 "arenaType"
    int m_nNameId;                      // +0x1c "arenaName" (string id)
    int m_nDetailId;                    // +0x20 "arenaDetail" (string id)
    int m_24;                           // +0x24 (never written)
    CString m_strBannerPath;            // +0x28 "bannerPath"
    unsigned int m_nFieldID;            // +0x30 "fieldID"
    int m_nPlayerCount;                 // +0x34 "playerCount"
    unsigned int m_nRewardItemId1;      // +0x38 "rewardItemId1"
    int m_nReward1Winner;               // +0x3c
    int m_nReward1Loser;                // +0x40
    unsigned int m_nRewardItemId2;      // +0x44 "rewardItemId2"
    int m_nReward2Winner;               // +0x48
    int m_nReward2Loser;                // +0x4c
};
MS2_CHECK_SIZE(IndividualArenaData, 0x50);
MS2_CHECK_OFFSET(IndividualArenaData, m_strBannerPath, 0x28);
MS2_CHECK_OFFSET(IndividualArenaData, m_nReward2Loser, 0x4c);

class CIndividualArenaDataTable : public TSingleton<CIndividualArenaDataTable>, public CValidData<CIndividualArenaDataTable>
{
public:
    typedef MS2SvrPtr<IndividualArenaData> DataPtr;
    typedef ATL::CAtlMap<int, DataPtr> Map;

    CIndividualArenaDataTable();                // 0x14051a260
    virtual ~CIndividualArenaDataTable();       // 0x14051a300

    bool Load();                                // 0x14051a360 (name invented)
    DataPtr GetData(int nArenaType);            // 0x14051a980 (name invented)

    static void CheckInit();                    // 0x14051b1c0
    static void SetInit(bool b);                // 0x14051c4f0

    static bool s_bInit;                        // 0x143aaf0a0

private:
    MS2_LAYOUT_FRIEND;
    Map m_map;                                  // +0x10
};
MS2_CHECK_SIZE(CIndividualArenaDataTable, 0x58);
MS2_CHECK_OFFSET(CIndividualArenaDataTable, m_map, 0x10);
