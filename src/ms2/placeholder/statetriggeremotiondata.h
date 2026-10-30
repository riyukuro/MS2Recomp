// statetriggeremotiondata.h - PLACEHOLDER for StateTriggerEmotionData (RTTI .?AVStateTriggerEmotionData@@, vftable
// 0x142f6d9d8, 0x48 bytes, CPtred-derived): the emotion list a trigger hands to the player's emotion-idle state.
// Owning unit is client\ms2\stateemotionidle.cpp (ctor 0x1417c4370, dtor 0x1417c5230, ??_G 0x1417c5580), not recovered
// yet; this declares only what the trigger service needs. Field names are invented. NOT an original header.
#pragma once

#include <atlstr.h>
#include <atlcoll.h>
#include "ms2/placeholder/state.h"

class StateTriggerEmotionData : public StateData
{
public:
    StateTriggerEmotionData();              // 0x1417c4370
    // ~StateTriggerEmotionData() implicit: 0x1417c5230 (slot 0) stores no vftable

    ATL::CAtlArray<CStringA> m_aEmotions;   // +0x18 emotion names
    int m_nMode;                            // +0x38 0 = from a list, 1 = single
    int m_nFlag;                            // +0x3c
    int m_nValue;                           // +0x40
    bool m_bLoop;                           // +0x44 play the first animation looped
    char m_pad_45[3];
};
MS2_CHECK_SIZE(StateTriggerEmotionData, 0x48);
MS2_CHECK_OFFSET(StateTriggerEmotionData, m_aEmotions, 0x18);
MS2_CHECK_OFFSET(StateTriggerEmotionData, m_nMode, 0x38);
