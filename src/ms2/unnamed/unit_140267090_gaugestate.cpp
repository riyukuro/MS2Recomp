// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A small gauge record (a count at +0x1c, a float amount at
// +0x20, a tag at +0x18) with its "has anything" tests and assign/accumulate from a shared reference. The class is
// InvokeEffectOption (its ctor 0x140266f10 is in unit_140266860; no __FILE__ string in the range); Ghidra's "SchedulerBase::HasWorkPending" label is a false match.
// MS2-UNIT: unit_140267090
// MS2-RANGE: 0x140267090-0x140267390 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <limits>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include "ms2/placeholder/invokeeffectoption.h"
// The record is InvokeEffectOption (0x28 bytes: count at +0x1c, rate at +0x20, type at +0x18). The by-value argument is
// MS2Ptr<InvokeEffectOption>: its dtor 0x14027e0f0 and operator-> 0x14027f330 are that pointer's COMDATs.
struct Unk_Ref16;                              // the pointer view of the definer (commonstruct_2.cpp)
bool FUN_14027ec30(Unk_Ref16* t);


























// @0x140267090
bool InvokeEffectOption::HasWork()
{
    return HasCount() || HasAmount();
}
MS2_REPLACE_METHOD(0x140267090, InvokeEffectOption, HasWork, 71, 0x89A2B316);

// @0x1402670e0
bool InvokeEffectOption::HasCount()
{
    return 0 < m_nB;
}
MS2_REPLACE_METHOD(0x1402670E0, InvokeEffectOption, HasCount, 45, 0xBA8CAF98);

// @0x140267120
bool InvokeEffectOption::HasAmount()
{
    return std::numeric_limits<float>::epsilon() < m_fC;
}
MS2_REPLACE_METHOD(0x140267120, InvokeEffectOption, HasAmount, 53, 0x635252AB);

// @0x140267160
void InvokeEffectOption::Assign(MS2Ptr<InvokeEffectOption> other)
{
    if (FUN_14027ec30(reinterpret_cast<Unk_Ref16*>(&other)))
        return;
    if (other->HasAmount() || other->HasCount())
    {
        m_fC = other->m_fC;
        m_nB = other->m_nB;
        m_nA = other->m_nA;
    }
}
MS2_REPLACE_METHOD(0x140267160, InvokeEffectOption, Assign, 184, 0xB500B85F);

// @0x140267220
void InvokeEffectOption::Accumulate(MS2Ptr<InvokeEffectOption> other)
{
    if (FUN_14027ec30(reinterpret_cast<Unk_Ref16*>(&other)))
        return;
    if (other->HasAmount() || other->HasCount())
    {
        m_fC = m_fC + other->m_fC;
        m_nB = m_nB + other->m_nB;
        m_nA = other->m_nA;
    }
}
MS2_REPLACE_METHOD(0x140267220, InvokeEffectOption, Accumulate, 207, 0x3B7F02B5);

// @0x140267300
void InvokeEffectOption::SetAmount(float fAmount)
{
    m_fC = fAmount;
}
MS2_REPLACE_METHOD(0x140267300, InvokeEffectOption, SetAmount, 28, 0x586C5DDA);

// @0x140267330
void InvokeEffectOption::SetCount(int nCount)
{
    m_nB = nCount;
}
MS2_REPLACE_METHOD(0x140267330, InvokeEffectOption, SetCount, 22, 0x6E748507);

// @0x140267350
float InvokeEffectOption::GetAmount()
{
    return m_fC;
}
MS2_REPLACE_METHOD(0x140267350, InvokeEffectOption, GetAmount, 16, 0x4C93A5B6);

// @0x140267370
int InvokeEffectOption::GetCount()
{
    return m_nB;
}
MS2_REPLACE_METHOD(0x140267370, InvokeEffectOption, GetCount, 14, 0x8AEE455B);
