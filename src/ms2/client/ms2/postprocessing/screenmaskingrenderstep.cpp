// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\screenmaskingrenderstep.cpp
// MS2-RANGE: 0x1400fc9e0-0x1400fca40 .text$di
// MS2-RANGE: 0x1416ba110-0x1416ba7f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\screenmaskingrenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "screenmaskingrenderstep.h"
#include "ms2/placeholder/nitexturingproperty.h"
#include <NiScreenFillingRenderView.h>
#include "hook/ms2hook.h"

// Unrecovered callees (real types unknown).
struct Unk_SMApp { CString FUN_1414736e0(); };   // path provider singleton (resource root)
Unk_SMApp* FUN_14086d260();
CString FUN_14016a5c0(const char* psz, int n);
struct Unk_SMMgr { Unk_PPSmartC FUN_141552f90(CString name, int flags); };   // texture/resource manager
Unk_SMMgr* FUN_140a0afd0();
void* FUN_140c8f880(void* p);
void* FUN_140c8f7f0(void* p);
void* FUN_140c8f670(void* p);
NiScreenFillingRenderView* FUN_140c8f7b0(void* tbl, void* key);
void* FUN_141d14f90(void* node, int type);
void* FUN_1409a8b20();
void* FUN_1416a3a90(void* p, int n);
extern char DAT_143afbbc0;
bool FUN_1416ba600(void* a, void* b);
bool FUN_1416ba620(void* a, void* b);

// @0x143ae5058 (no initializer; zero-initialised)
static NiTexturingProperty* s_pkScreenMaskProp;

// @0x1400fc9e0
static Unk_PPSmartC s_screenMaskTexture(0);

// @0x1400fca10
const NiRTTI ScreenMaskingRenderStep::ms_RTTI("ScreenMaskingRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416ba110
ScreenMaskingRenderStep::ScreenMaskingRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("ScreenMaskingRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416ba190
ScreenMaskingRenderStep::~ScreenMaskingRenderStep()
{
}

// @0x1416ba1c0
bool ScreenMaskingRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0) || m_70 == 0)
        return false;
    CString path;
    path.Format("%s/Image/ScreenMask/title_make_ch.tga", (const char*)FUN_14086d260()->FUN_1414736e0());
    s_screenMaskTexture = FUN_140a0afd0()->FUN_141552f90(CString((const char*)FUN_14016a5c0((const char*)path, 0)), 5);
    void* res = 0;
    res = FUN_140c8f690(FUN_1416b4990(this, "ScreenMasking", (void*)FUN_1416ba620, this, FUN_140c8f680(&m_80), 0, 0, 0, "ScreenMasking", s_screenMaskTexture.Get(), 0, 0));
    if (res == 0) {
        vfunc_16();
        return false;
    }
    NiScreenFillingRenderView* obj = FUN_140c8f7b0(&DAT_143afbbc0, FUN_140c8f670(FUN_140c8f7f0(FUN_140c8f880(res))));
    s_pkScreenMaskProp = (NiTexturingProperty*)FUN_141d14f90(&obj->GetScreenFillingQuad(), 8);
    NiTexturingProperty::ShaderMap* sm = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty::ShaderMap((NiTexture*)s_screenMaskTexture.Get(), 0, (NiTexturingProperty::ClampMode)0, (NiTexturingProperty::FilterMode)0, 0);
    s_pkScreenMaskProp->SetShaderMap(0, sm);
    return true;
}

// @0x1416ba5d0
void ScreenMaskingRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    s_screenMaskTexture.Assign(0);
}

// @0x1416ba600
bool FUN_1416ba600(void* a, void* b) { return true; }

// @0x1416ba620
bool FUN_1416ba620(void* a, void* b) { return true; }

void FUN_1416ba640(Unk_PPSmartC tex);
#ifndef MS2_HOOK_DLL
// @0x1416ba640
void FUN_1416ba640(Unk_PPSmartC tex)
{
    if (s_pkScreenMaskProp != 0) {
        void* r = FUN_1416a3a90(FUN_1409a8b20(), 8);
        if (r != 0) {
            s_screenMaskTexture = tex;
            NiTexturingProperty::ShaderMap* sm = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty::ShaderMap((NiTexture*)s_screenMaskTexture.Get(), 0, (NiTexturingProperty::ClampMode)0, (NiTexturingProperty::FilterMode)0, 0);
            s_pkScreenMaskProp->SetShaderMap(0, sm);
        }
    }
}
#endif

// @0x1416ba750
void ScreenMaskingRenderStep::vfunc_22() {}

// @0x1416ba7c0
const NiRTTI* ScreenMaskingRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416ba7d0
bool ScreenMaskingRenderStep::vfunc_14() { return false; }

// @0x1416ba7e0
bool ScreenMaskingRenderStep::vfunc_13() { return false; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb4740-0x142cb4760 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x1416ba600, FUN_1416ba600, 13, 0xC078F4D1);
MS2_REPLACE(0x1416ba620, FUN_1416ba620, 13, 0xC078F4D1);
MS2_REPLACE_METHOD(0x1416ba750, ScreenMaskingRenderStep, vfunc_22, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x1416ba7c0, ScreenMaskingRenderStep, GetRTTI, 13, 0x9687C7E9);
MS2_REPLACE_METHOD(0x1416ba7d0, ScreenMaskingRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416ba7e0, ScreenMaskingRenderStep, vfunc_13, 8, 0x41132FCD);

