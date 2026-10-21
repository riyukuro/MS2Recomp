// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ssaorenderstep.cpp
// MS2-RANGE: 0x1400fca40-0x1400fca70 .text$di
// MS2-RANGE: 0x1416ba7f0-0x1416bad00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\ssaorenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ssaorenderstep.h"
#include "hook/ms2hook.h"

// @0x1400fca40
const NiRTTI SSAORenderStep::ms_RTTI("SSAORenderStep", &ReloadablePostProcess::ms_RTTI);

// @0x1416ba7f0
SSAORenderStep::SSAORenderStep(unsigned __int64 a, NiFixedString* name, unsigned int b)
    : ReloadablePostProcess(a, *name, 0, b), m_b8(0), m_c0(0)
{
    NiString buf((size_t)0x100);
    buf.Format("%sRenderStep", (const char*)*name);
    FUN_140c8f950(this, NiFixedString((const char*)buf));
    m_a0 = *name;
}

// @0x1416ba920
SSAORenderStep::~SSAORenderStep()
{
}

// @0x1416ba980
bool SSAORenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    FUN_14169f6d0(&m_c0, &((void**)b)[1]);
    {
        NiFixedString file((const char*)*(CSimpleStringT<char, 1>*)((char*)FUN_1401d31f0() + 0xf8));
        m_b8.Assign(FUN_141d33230(&file, &DAT_1439fc800, 0, 0, true));
    }
    if (m_b8.Get() == 0) {
        vfunc_16();
        return false;
    }
    if (!vfunc_23()) {
        vfunc_16();
        return false;
    }
    return true;
}

// @0x1416baab0
void SSAORenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_b8.Assign(0);
}

// @0x1416baaf0
bool SSAORenderStep::vfunc_23()
{
    void* p;
    {
        NiFixedString click("CalculateOcclusion");
        p = FUN_1409a8d30(this, &click);
    }
    if (p != 0)
        FUN_14169fbf0(this, p);
    p = FUN_140c8f690(FUN_1416b4990(this, "CalculateOcclusion", 0, 0, FUN_140c8f680(&m_80), 0, 3, 0, (const char*)m_a0, FUN_140c8f680(&m_c0), m_b8.Get(), 0));
    if (p == 0)
        return false;
    return true;
}

// @0x1416bacf0
const NiRTTI* SSAORenderStep::GetRTTI() const { return &ms_RTTI; }
MS2_REPLACE_METHOD(0x1416BA980, SSAORenderStep, vfunc_15, 294, 0x9B87AF64);
MS2_REPLACE_METHOD(0x1416BAAB0, SSAORenderStep, vfunc_16, 45, 0x3FCC2CC7);
MS2_REPLACE_METHOD(0x1416BAAF0, SSAORenderStep, vfunc_23, 402, 0xA84A7E34);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x1416bacf0, SSAORenderStep, GetRTTI, 13, 0x027E8B5A);

