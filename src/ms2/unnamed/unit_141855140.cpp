// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Derived effect dummy data and copy routine.
// MS2-UNIT: unit_141855140
// MS2-RANGE: 0x141855140-0x141855200 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "../client/ms2/effectdummy.h"

class Unk_EffectDummyRecord
{
public:
    Unk_EffectDummyRecord(const Unk_EffectDummyRecord& other);
    long long AssignRecord(const Unk_EffectDummyRecord& other);
    CEffectDummy m_effect;
    CString m_recordName;
    int m_recordValue;
};

// @0x1418551a0
long long Unk_EffectDummyRecord::AssignRecord(const Unk_EffectDummyRecord& other)
{
    m_effect.operator=(other.m_effect);
    m_recordName = other.m_effect.GetParentNode();
    m_recordValue = other.m_recordValue;
    return reinterpret_cast<long long>(this);
}

// @0x141855140 copy ctor: default-constructs the members, then AssignRecord(other) (exe: rcx = this, rdx = other)
Unk_EffectDummyRecord::Unk_EffectDummyRecord(const Unk_EffectDummyRecord& other)
    : m_effect(), m_recordName()
{
    AssignRecord(other);
}
