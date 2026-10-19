// skillactionskill.h - SkillActionSkill (RTTI .?AVSkillActionSkill@@, 0xb0 bytes): one <actionSkill> record of a skill
// attack. Declared by ?\skillattackdata.cpp (the owner unit, 0x1408011f0, defines the members).
#pragma once
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/xmlattr.h"

class SkillActionSkill : public CPtred
{
public:
    SkillActionSkill();                                     // 0x1408018d0
    bool operator!=(const SkillActionSkill& o);             // 0x140801a10
    int Load(Unk_140165cf0* pElem);                         // 0x140801c40
    int Save(void* pParent, CString strName);               // 0x140802050

    ATL::CAtlArray<unsigned short> m_arrLevel;              // +0x18 "level"
    ATL::CAtlArray<int> m_arrSkillID;                       // +0x38 "skillID"
    ATL::CAtlArray<int> m_arrLinkSkillID;                   // +0x58 "linkSkillID"
    unsigned m_nOverlapCount;                               // +0x78
    unsigned m_nDelay;                                           // +0x7c
    unsigned m_nInterval;                                        // +0x80
    unsigned m_nRemoveDelay;                                     // +0x84
    int m_nImmediateActive;                                 // +0x88
    int m_nFireCount;                                       // +0x8c
    int m_nNonTargetActive;                                 // +0x90
    int m_nUseDirection;                                    // +0x94
    int m_nOnlySensingActive;                               // +0x98
    int m_nActiveByIntervalTick;                            // +0x9c
    int m_nDependOnCasterState;                             // +0xa0
    int m_nIndependent;                                     // +0xa4
    int m_nChain;                                           // +0xa8
    float m_fChainDistance;                                 // +0xac
};
MS2_CHECK_SIZE(SkillActionSkill, 0xb0);
