// invokeeffectoption.h - PLACEHOLDER for InvokeEffectOption (RTTI, 0x28 bytes): one stat option an invoke effect adds
// (type, count, rate). Defined by unit_140266860.cpp (ctor 0x140266f10); the members used by additionalcli.cpp are
// declared here. NOT an original header.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class InvokeEffectOption : public CPtred
{
public:
    InvokeEffectOption();                                   // 0x140266f10
    bool HasWork(); bool HasCount(); bool HasAmount();      // 0x140267090 / 0x1402670e0 / 0x140267120 (unit_140267090)
    void Assign(MS2Ptr<InvokeEffectOption> spOther);        // 0x140267160 copy another option's count and rate
    void Accumulate(MS2Ptr<InvokeEffectOption> spOther);    // 0x140267220 add another option's count and rate
    void SetAmount(float fRate); void SetCount(int nCount); // 0x140267300 / 0x140267330
    float GetAmount(); int GetCount();                      // 0x140267350 the rate / 0x140267370 the count

    int m_nA;                                               // +0x18 stat option type
    int m_nB;                                               // +0x1c count
    float m_fC;                                             // +0x20 rate
    int m_pad_24;
};
MS2_CHECK_SIZE(InvokeEffectOption, 0x28);
