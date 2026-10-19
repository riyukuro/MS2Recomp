// skilldata.h - PLACEHOLDER for SkillData (RTTI .?AVSkillData@@, one skill of the skill table) and SkillLevelData
// (RTTI .?AVSkillLevelData@@, one level of it). NOT an original header; only the members that commonfiles\jobtable.cpp / ?\jobsystem.cpp
// calls are declared (names invented). Both are held by MS2Ptr<T> with the CPtred base at offset 0 (the per-T
// ReleaseImpl 0x140641a30 passes the pointer unadjusted).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class SkillLevelData : public CPtred
{
};

class SkillData : public CPtred
{
public:
    unsigned short FUN_1407e9ac0();                     // the level cap a sub skill follows its parent skill up to
    MS2Ptr<SkillLevelData> FUN_1407e90a0(unsigned short nLevel);  // the data of one level
    unsigned short FUN_1407e9b10();                     // the max level
    bool FUN_1407e9de0();                               // passive skill
    bool FUN_1407e9f30();                               // checked before handing out level 1 of an unowned skill
};
