// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Effect dummy record equality and copy.
// MS2-UNIT: unit_141855200
// MS2-RANGE: 0x141855200-0x141855360 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "../client/ms2/effectdummy.h"

struct Unk_EffectDummyRecord
{
    CEffectDummy m_effect;
    CString m_recordName;
    int m_recordValue;
};

bool FUN_141855250(const Unk_EffectDummyRecord&, const Unk_EffectDummyRecord&);
extern bool FUN_1401c0090(const CString&, const CString&);

// @0x141855200
bool FUN_141855200(const Unk_EffectDummyRecord& a, const Unk_EffectDummyRecord& b)
{
    return !FUN_141855250(a, b);
}

// @0x141855250
bool FUN_141855250(const Unk_EffectDummyRecord& a, const Unk_EffectDummyRecord& b)
{
    return a.m_effect.operator==(b.m_effect) & FUN_1401c0090(a.m_recordName, b.m_recordName) &
           (a.m_recordValue == b.m_recordValue);
}

// @0x1418552e0
void FUN_1418552e0(Unk_EffectDummyRecord& a, const Unk_EffectDummyRecord& b)
{
    a.m_effect.operator=(reinterpret_cast<const CEffectDummy&>(b));
    a.m_recordName = reinterpret_cast<const CEffectDummy&>(b).GetParentNode();
}

// @0x141855330
CRuntimeClass* FUN_141855330()
{
    return CDialog::GetThisClass();
}
