// weddingtable.h - PLACEHOLDER for WeddingTable (RTTI .?AVWeddingTable@@, 0x60 bytes) and its row classes
// WeddingRewardData (0x30), WeddingExpData (0x28), WeddingMaintenanceData (0x28) and WeddingSkillData (0x68). NOT an
// original header. Bases: TSingleton<WeddingTable> at +0x0, CValidData<WeddingTable> at +0x8. A TSingleton that
// CGameApp::InitInstance (?\ms2.cpp) creates. Defined in ?\weddingrewarditem.cpp (0x1409063b0-0x140920690); layouts and
// names follow the v2525 reference decomp (include/ms2/commonfiles/WeddingTable.h), member names are the XML keys.
#pragma once

#include <list>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/timeutil.h"               // Unk_DayTime, CMsTime
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/weddingpackage.h"

// weddingReward.xml <v type rewardExp rewardLimit>: the wedding experience an action grants.
class WeddingRewardData : public CPtred
{
public:
    WeddingRewardData();                                    // 0x1409071e0
    virtual ~WeddingRewardData();                           // 0x140907240
    bool Read(Unk_140165cf0* pNode);                        // 0x140907270

    int m_nType;                                            // +0x18 "type"
    __int64 m_nRewardExp;                                   // +0x20 "rewardExp"
    int m_nRewardLimit;                                     // +0x28 "rewardLimit" (1: once a day, 2: once a month)
};
MS2_CHECK_SIZE(WeddingRewardData, 0x30);

// weddingExp.xml <v grade value>: the experience a grade needs.
class WeddingExpData : public CPtred
{
public:
    WeddingExpData();                                       // 0x140907310
    virtual ~WeddingExpData();                              // 0x140907360
    bool Read(Unk_140165cf0* pNode);                        // 0x140907390

    int m_nGrade;                                           // +0x18 "grade"
    __int64 m_nValue;                                       // +0x20 "value"
};
MS2_CHECK_SIZE(WeddingExpData, 0x28);

// weddingMaintenance.xml <mainternance world dayOfWeek time_range="hh:mm:ss-hh:mm:ss">: a weekly closed window.
class WeddingMaintenanceData : public CPtred
{
public:
    WeddingMaintenanceData();                               // 0x1409073f0
    virtual ~WeddingMaintenanceData();                      // 0x140907470
    bool Read(Unk_140165cf0* pNode);                        // 0x1409074a0
    bool IsMaintenance(int nWorld, const CMsTime& time);    // 0x1409077a0

    int m_nWorld;                                           // +0x18 "world" (0: every world)
    unsigned int m_nDayOfWeek;                              // +0x1c "dayOfWeek"
    Unk_DayTime m_startTime;                                // +0x20
    Unk_DayTime m_endTime;                                  // +0x24
};
MS2_CHECK_SIZE(WeddingMaintenanceData, 0x28);

// weddingSkill.xml <v id type requireGrade ...>: a couple skill unlocked by the wedding grade.
class WeddingSkillData : public CPtred
{
public:
    WeddingSkillData();                                     // 0x1409078d0
    virtual ~WeddingSkillData();                            // 0x140907980
    bool Read(Unk_140165cf0* pNode);                        // 0x1409079c0
    unsigned short GetLevel(int nGrade);                    // 0x140907ad0
    float GetValue(int nGrade);                             // 0x140907b50 (percent)

    int m_nId;                                              // +0x18 "id"
    int m_nType;                                            // +0x1c "type" (0 passive, 1 item)
    int m_nRequireGrade;                                    // +0x20 "requireGrade"
    int m_nMaxCount;                                        // +0x24 "maxCount"
    unsigned int m_nAdditionalEffectId;                     // +0x28 "additionalEffectID"
    float m_fStartValue;                                    // +0x2c "startValue"
    float m_fAddValue;                                      // +0x30 "addValue"
    ItemEntity m_item;                                      // +0x38
};
MS2_CHECK_OFFSET(WeddingSkillData, m_item, 0x38);
MS2_CHECK_SIZE(WeddingSkillData, 0x68);

class WeddingTable : public TSingleton<WeddingTable>, public CValidData<WeddingTable>
{
public:
    WeddingTable();                                         // 0x140907bd0
    virtual ~WeddingTable();                                // 0x140907c90
    bool Load();                                            // 0x140907d40
    bool LoadPackage();                                     // 0x140907dc0
    bool LoadReward();                                      // 0x1409080a0
    bool LoadExp();                                         // 0x140908380
    bool LoadMaintenance();                                 // 0x140908660
    bool LoadSkill();                                       // 0x1409088e0
    MS2Ptr<WeddingPackage> FUN_140908b80(int nPackageId);   // the package of an id (null: none)
    MS2Ptr<WeddingPackage> FindPackageByPlanner(int nPlanner);              // 0x140908c50
    unsigned int FUN_140908d50(int nPackageId, int nHallId, bool bNight);   // the hall's field id (night variant)
    __int64 FUN_140908e60(int nType, __int64 nLastTime);    // the reward exp of a type (0 inside its limit period)
    int GetGrade(__int64 nExp);                             // 0x140908f90
    __int64 GetExpValue(int nGrade);                        // 0x140909070
    int GetMaxGrade();                                      // 0x1409090f0
    int FUN_140909130(int nPackageId, int nHallId);         // the grade of a hall
    __int64 FUN_140909220(int nPackageId, int nHallId);     // the price of a hall
    bool GetUpgradeItems(int nFromPackageId, int nFromHallId, int nToPackageId, int nToHallId,
                         std::vector<ItemEntity>& items);   // 0x140909310
    bool FUN_140909870(int nWorld, const CMsTime& time);    // in a maintenance window
    MS2Ptr<WeddingSkillData> FindSkill(int nId);            // 0x140909910
    void GetSkillsByGrade(int nGrade, std::vector<MS2Ptr<WeddingSkillData> >& skills);   // 0x1409099d0
    std::map<int, MS2Ptr<WeddingSkillData> >& GetSkills();  // 0x140909a80

    std::map<int, MS2Ptr<WeddingPackage> > m_packages;              // +0x10 weddingPackage.xml
    std::map<int, MS2Ptr<WeddingRewardData> > m_rewards;            // +0x20 weddingReward.xml
    std::map<int, MS2Ptr<WeddingExpData> > m_exps;                  // +0x30 weddingExp.xml
    std::list<MS2Ptr<WeddingMaintenanceData> > m_maintenance;       // +0x40 weddingMaintenance.xml
    std::map<int, MS2Ptr<WeddingSkillData> > m_skills;              // +0x50 weddingSkill.xml
};
MS2_CHECK_OFFSET(WeddingTable, m_packages, 0x10);
MS2_CHECK_OFFSET(WeddingTable, m_maintenance, 0x40);
MS2_CHECK_SIZE(WeddingTable, 0x60);
