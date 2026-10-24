// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A small gauge record (a count at +0x1c, a float amount at
// +0x20, a tag at +0x18) with its "has anything" tests and assign/accumulate from a shared reference. The class name is
// invented (no RTTI or __FILE__ string in the range); Ghidra's "SchedulerBase::HasWorkPending" label is a false match.
// MS2-UNIT: unit_140267090
// MS2-RANGE: 0x140267090-0x140267390 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// A 16 byte reference handle: the pointed-to record is at +8 (see commonstruct_2.cpp).
struct Unk_GaugeRef
{
    void* m_unknown; void* m_p;
    ~Unk_GaugeRef();                                            // 0x14027e0f0
};

class Unk_Gauge
{
public:
    bool HasWork();                                             // 0x140267090
    bool HasCount();                                            // 0x1402670e0
    bool HasAmount();                                           // 0x140267120
    void Assign(Unk_GaugeRef other);                          // 0x140267160
    void Accumulate(Unk_GaugeRef other);                      // 0x140267220
    void SetAmount(float fAmount);                              // 0x140267300
    void SetCount(int nCount);                                  // 0x140267330
    float GetAmount();                                          // 0x140267350
    int GetCount();                                             // 0x140267370

    char m_pad_00[0x18];
    int m_n18;
    int m_nCount;                                               // +0x1c
    float m_fAmount;                                            // +0x20
};

float FUN_14028aaf0();                                          // 0x14028aaf0 returns 0x34000000 (2^-23)
bool FUN_14027ec30(Unk_GaugeRef* pRef);
void FUN_14027e0f0(void* pRef) noexcept;
Unk_GaugeRef::~Unk_GaugeRef() { FUN_14027e0f0(this); }
Unk_Gauge* FUN_14027f330(Unk_GaugeRef* pRef);

// @0x140267090
bool Unk_Gauge::HasWork()
{
    return HasCount() || HasAmount();
}
MS2_REPLACE_METHOD(0x140267090, Unk_Gauge, HasWork, 71, 0x89A2B316);

// @0x1402670e0
bool Unk_Gauge::HasCount()
{
    return 0 < m_nCount;
}
MS2_REPLACE_METHOD(0x1402670E0, Unk_Gauge, HasCount, 45, 0xBA8CAF98);

// @0x140267120
bool Unk_Gauge::HasAmount()
{
    return FUN_14028aaf0() < m_fAmount;
}
MS2_REPLACE_METHOD(0x140267120, Unk_Gauge, HasAmount, 53, 0x635252AB);

// @0x140267160
void Unk_Gauge::Assign(Unk_GaugeRef other)
{
    if (FUN_14027ec30(&other))
        return;
    if (FUN_14027f330(&other)->HasAmount() || FUN_14027f330(&other)->HasCount())
    {
        m_fAmount = FUN_14027f330(&other)->m_fAmount;
        m_nCount = FUN_14027f330(&other)->m_nCount;
        m_n18 = FUN_14027f330(&other)->m_n18;
    }
}
MS2_REPLACE_METHOD(0x140267160, Unk_Gauge, Assign, 184, 0xB500B85F);

// @0x140267220
void Unk_Gauge::Accumulate(Unk_GaugeRef other)
{
    if (FUN_14027ec30(&other))
        return;
    if (FUN_14027f330(&other)->HasAmount() || FUN_14027f330(&other)->HasCount())
    {
        m_fAmount = m_fAmount + FUN_14027f330(&other)->m_fAmount;
        m_nCount = m_nCount + FUN_14027f330(&other)->m_nCount;
        m_n18 = FUN_14027f330(&other)->m_n18;
    }
}
MS2_REPLACE_METHOD(0x140267220, Unk_Gauge, Accumulate, 207, 0x3B7F02B5);

// @0x140267300
void Unk_Gauge::SetAmount(float fAmount)
{
    m_fAmount = fAmount;
}
MS2_REPLACE_METHOD(0x140267300, Unk_Gauge, SetAmount, 28, 0x586C5DDA);

// @0x140267330
void Unk_Gauge::SetCount(int nCount)
{
    m_nCount = nCount;
}
MS2_REPLACE_METHOD(0x140267330, Unk_Gauge, SetCount, 22, 0x6E748507);

// @0x140267350
float Unk_Gauge::GetAmount()
{
    return m_fAmount;
}
MS2_REPLACE_METHOD(0x140267350, Unk_Gauge, GetAmount, 16, 0x4C93A5B6);

// @0x140267370
int Unk_Gauge::GetCount()
{
    return m_nCount;
}
MS2_REPLACE_METHOD(0x140267370, Unk_Gauge, GetCount, 14, 0x8AEE455B);
