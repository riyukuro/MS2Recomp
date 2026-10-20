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
    void FUN_140267220(MS2Ptr<InvokeEffectOption> spOther);    // add another option's count and rate
    void FUN_140267300(float fRate);                        // set the rate
    void FUN_140267330(int nCount);                         // set the count
    float FUN_140267350();                                  // the rate
    int FUN_140267370();                                    // the count

    int m_nA;                                               // +0x18 stat option type
    int m_nB;                                               // +0x1c count
    float m_fC;                                             // +0x20 rate
    int m_pad_24;
};
MS2_CHECK_SIZE(InvokeEffectOption, 0x28);
