// stanceleveldata.h - StanceLevelData / StanceData / StanceTable (RTTI names): the combo stance rows of Table/stance.xml
// (a stance skill effect that stacks with each hit). Header name assumed; member names are the xml attribute names.
#pragma once
#include <afx.h>
#include <map>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// One <level> row, 0x28 bytes.
class StanceLevelData : public CPtred
{
public:
    StanceLevelData();                                  // 0x1408290b0
    virtual ~StanceLevelData();                         // 0x140829120
    bool Load(Unk_140165cf0* pNode);                     // 0x140829150
    unsigned DamageRate(int nBase);                     // 0x1408291e0 rate per mille of nBase, capped

    unsigned m_nLevel;                                  // +0x18 "level"
    unsigned m_nHitCount;                               // +0x1c "hitCount"
    unsigned m_nMultiplyDamageRate;                     // +0x20 "multiplyDamageRate"
    unsigned m_nMaxAccDamageRate;                       // +0x24 "maxAccDamageRate"
};
MS2_CHECK_SIZE(StanceLevelData, 0x28);

// One <v> row, 0x58 bytes.
class StanceData : public CPtred
{
public:
    StanceData();                                       // 0x140829240
    virtual ~StanceData();                              // 0x1408292d0
    bool Load(Unk_140165cf0* pNode);                     // 0x140829330
    bool HasDamageSkill(unsigned nSkillId);                   // 0x1408294a0
    int StanceAdditionalID();                           // 0x140829510
    int HitCountAdditionalID();                         // 0x140829530
    MS2Ptr<StanceLevelData> LevelData(unsigned nHitCount);   // 0x140829550 last level reached by the hit count

    unsigned m_nStanceAdditionalID;                     // +0x18 "stanceAdditionalID"
    unsigned m_nHitCountAdditionalID;                   // +0x1c "hitCountAdditinoalID" (sic)
    std::set<unsigned> m_damageSkillIDs;                // +0x20 "damageSkillIDs"
    std::set<unsigned> m_finishStanceSkillIDs;          // +0x30 "finishStanceSkillIDs"
    std::vector<MS2Ptr<StanceLevelData> > m_levels;     // +0x40 the <level> children
};
MS2_CHECK_SIZE(StanceData, 0x58);
MS2_CHECK_OFFSET(StanceData, m_damageSkillIDs, 0x20);
MS2_CHECK_OFFSET(StanceData, m_finishStanceSkillIDs, 0x30);
MS2_CHECK_OFFSET(StanceData, m_levels, 0x40);

// RTTI StanceTable, 0x38 bytes: TSingleton at +0.
class StanceTable : public TSingleton<StanceTable>
{
public:
    typedef MS2Ptr<StanceData> DataPtr;

    StanceTable();                                      // 0x140829650
    virtual ~StanceTable();                             // 0x1408296d0
    bool Load();                                         // 0x140829730 Table/stance.xml
    bool HasStance(unsigned nId);                             // 0x140829c80
    bool HasHitCountStance(unsigned nId);                     // 0x140829cf0
    DataPtr Stance(unsigned nId);                            // 0x140829d60
    DataPtr HitCountStance(unsigned nId);                    // 0x140829e20
    bool HasFinishSkill(unsigned nSkillId);                   // 0x140829ee0
    DataPtr FinishSkillStance(unsigned nSkillId);            // 0x140829f50

    std::map<unsigned, DataPtr> m_stances;                   // +0x08 by stanceAdditionalID
    std::map<unsigned, DataPtr> m_hitCountStances;           // +0x18 by hitCountAdditinoalID
    std::map<unsigned, DataPtr> m_finishSkills;              // +0x28 by each finishStanceSkillID
};
MS2_CHECK_SIZE(StanceTable, 0x38);
MS2_CHECK_OFFSET(StanceTable, m_stances, 0x8);
MS2_CHECK_OFFSET(StanceTable, m_hitCountStances, 0x18);
MS2_CHECK_OFFSET(StanceTable, m_finishSkills, 0x28);
