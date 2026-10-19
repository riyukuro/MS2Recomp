// skillbegincondition.h - <beginCondition> of a skill (SkillBeginCondition) and its <caster> / <target> buff blocks.
// Members are defined by ?\skilloverlapcompare.cpp (0x1407e6170-0x1407e6900); split out of skilloverlapcompare.h so that
// SkillActionAdditional (skillactionadditional.h) can embed one.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/xmlattr.h"

// <caster> / <target> of a beginCondition.
struct SkillHasBuffCondition
{
    SkillHasBuffCondition();                                // 0x1407e6170
    bool operator!=(const SkillHasBuffCondition& o);        // 0x1407e61c0
    int Load(Unk_140165cf0* pElem);                         // 0x1407e6250
    int Save(void* pElem);                                  // 0x1407e6300
    BOOL HasContent();                                      // 0x1407e6400

    unsigned m_nHasBuffID;                                  // +0x00
    unsigned m_nHasBuffCount;                               // +0x04
    bool m_bHasBuffOwner;                                   // +0x08
    unsigned m_nHasNotBuffID;                               // +0x0c
    bool m_bHasNotBuffOwner;                                // +0x10
};
MS2_CHECK_SIZE(SkillHasBuffCondition, 0x14);

// <beginCondition>.
struct SkillBeginCondition
{
    SkillBeginCondition();                                  // 0x1407e6440
    bool operator!=(const SkillBeginCondition& o);          // 0x1407e64b0
    bool IsDefault();                                       // 0x1407e6580
    int Load(Unk_140165cf0* pElem);                         // 0x1407e6610
    int Save(void* pParent);                                // 0x1407e6740

    float m_fProbability;                                   // +0x00
    int m_nUseTargetCountFactor;                            // +0x04
    int m_nAllowBattleRidingState;                          // +0x08
    int m_nOnlyBattleRidingState;                           // +0x0c
    SkillHasBuffCondition m_caster;                         // +0x10
    SkillHasBuffCondition m_target;                         // +0x24
};
MS2_CHECK_SIZE(SkillBeginCondition, 0x38);

