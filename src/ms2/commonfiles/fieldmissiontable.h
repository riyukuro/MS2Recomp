// fieldmissiontable.h - CFieldMissionTable / CFieldMissionReward (RTTI names): the field mission rewards read from
// Table/fieldMission.xml (<round mission type value subJobLevel/> rows under <ms2>). Header name assumed from the unit
// path; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"

class TiXmlElement;    // xml element (declared where the loader is)

// Skill point kind of a reward ("subJobLevel": 1 / 2). Name and type invented: the map GetSkillPoints fills has its own
// copy of the std::map glue (try_emplace 0x14037e600, gameevent's map<int,int> is 0x1403e13d0) and of less<K>::operator()
// (0x14037ee20, a signed jge; less<int> is 0x1401f1b70), so K is a distinct signed 32-bit type, not int.
enum Unk_SubJobLevel { Unk_SubJobLevel_1 = 1, Unk_SubJobLevel_2 = 2 };

// One reward (0x58 bytes, CPtred base, deleting dtor only). m_nType: 1 item, 2 stat point, 3 skill point.
class CFieldMissionReward : public CPtred
{
public:
    CFieldMissionReward();              // 0x14037e900
    virtual ~CFieldMissionReward();     // 0x14037eab0

    int m_nType;                        // +0x18 "type"
    int m_nValue;                       // +0x1c "value" (types 2, 3)
    ItemEntity m_item;                  // +0x20 the item (type 1)
    Unk_SubJobLevel m_nSubJob;          // +0x50 skill point kind (1 / 2) from "subJobLevel"
};
MS2_CHECK_SIZE(CFieldMissionReward, 0x58);
MS2_CHECK_OFFSET(CFieldMissionReward, m_item, 0x20);
MS2_CHECK_OFFSET(CFieldMissionReward, m_nSubJob, 0x50);

// RTTI CFieldMissionTable, 0x38 bytes (+ TSingleton). The rewards are keyed by the "mission" round number.
class CFieldMissionTable : public TSingleton<CFieldMissionTable>
{
public:
    typedef MS2Ptr<CFieldMissionReward> RewardPtr;
    typedef ATL::CRBMap<int, RewardPtr> RewardMap;

    CFieldMissionTable();               // 0x14037bf80
    virtual ~CFieldMissionTable();      // 0x14037bfd0

    int Load();                                                 // 0x14037c010
    RewardPtr GetReward(int nRound);                            // 0x14037c3d0
    int GetPrevRound(int nRound);                               // 0x14037c450 the round before nRound (0 if none)
    int GetNextRound(int nRound);                               // 0x14037c510 the round after nRound (0 if none)
    int GetMaxRound();                                          // 0x14037c610
    void GetSkillPoints(int nRound, std::map<Unk_SubJobLevel, int>& rOut);  // 0x14037c6a0 skill points of the rounds <= nRound per kind
    int GetStatPoints(int nRound);                              // 0x14037c7c0 stat points of the rounds <= nRound

private:
    MS2_LAYOUT_FRIEND;
    RewardMap m_rewards;                // +0x08
};
MS2_CHECK_SIZE(CFieldMissionTable, 0x38);
MS2_CHECK_OFFSET(CFieldMissionTable, m_rewards, 8);
