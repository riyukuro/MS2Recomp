// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\radialblurrenderstep.cpp
// MS2-RANGE: 0x1400fc9b0-0x1400fc9e0 .text$di
// MS2-RANGE: 0x1416b9e50-0x1416ba110 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\radialblurrenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "radialblurrenderstep.h"
#include "hook/ms2hook.h"

// @0x1400fc9b0
const NiRTTI RadialBlurRenderStep::ms_RTTI("RadialBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416b9e50
RadialBlurRenderStep::RadialBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("RadialBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416b9ed0
RadialBlurRenderStep::~RadialBlurRenderStep()
{
}

// @0x1416b9f00
bool RadialBlurRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* ok;
    ok = FUN_140c8f690(FUN_1416b4990(this, "RadialBlur", 0, 0, FUN_140c8f680(&m_80), 0, 0, 0, "RadialBlur", FUN_140c8f680(&((void**)b)[2]), FUN_140c8f680(&((void**)b)[1]), 0));
    if (ok == 0) {
        vfunc_16();
        return false;
    }
    return true;
}

// @0x1416ba0e0
const NiRTTI* RadialBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416ba0f0
bool RadialBlurRenderStep::vfunc_14() { return false; }

// @0x1416ba100
bool RadialBlurRenderStep::vfunc_13() { return false; }
MS2_REPLACE_METHOD(0x1416B9F00, RadialBlurRenderStep, vfunc_15, 378, 0xF9A64C48);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x1416ba0e0, RadialBlurRenderStep, GetRTTI, 13, 0x3683DBAE);
MS2_REPLACE_METHOD(0x1416ba0f0, RadialBlurRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416ba100, RadialBlurRenderStep, vfunc_13, 8, 0x41132FCD);

