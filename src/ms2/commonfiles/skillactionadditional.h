// skillactionadditional.h - SkillActionAdditional (RTTI .?AVSkillActionAdditional@@, 0x70 bytes): one
// <actionAdditional> record of a skill attack. Declared by ?\skillattackdata.cpp (the owner unit, 0x1408011f0, defines
// the members).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/skillbegincondition.h"

class SkillActionAdditional : public CPtred
{
public:
    SkillActionAdditional();                                // 0x140802090
    bool operator!=(const SkillActionAdditional& o);        // 0x140802120
    int Load(Unk_140165cf0* pElem);                         // 0x140802210

    unsigned m_nAdditionalID;                               // +0x18 "additionalID"
    unsigned short m_nLevel;                                // +0x1c "level"
    unsigned m_nLinkSkillID;                                // +0x20
    unsigned m_nOverlapCount;                               // +0x24
    int m_nSkillTarget;                                     // +0x28
    int m_nSkillOwner;                                      // +0x2c
    int m_nDependOnDamageCount;                             // +0x30
    SkillBeginCondition m_beginCondition;                   // +0x34
};
MS2_CHECK_SIZE(SkillActionAdditional, 0x70);
