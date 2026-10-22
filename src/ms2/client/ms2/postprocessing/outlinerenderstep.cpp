// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\outlinerenderstep.cpp
// MS2-RANGE: 0x1400fad00-0x1400fad30 .text$di
// MS2-RANGE: 0x1416263e0-0x141626c30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\outlinerenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "outlinerenderstep.h"
#include "hook/ms2hook.h"
#include <string.h>
#include <errno.h>
#pragma function(memset, memcpy)

// @0x1400fad00
const NiRTTI OutlineRenderStep::ms_RTTI("OutlineRenderStep", &ReloadablePostProcess::ms_RTTI);

// @0x1416263e0
// MS2-FUNCTIONAL: exe passes the NiFixedString temporary straight to the base ctor (no copy temp); we get an extra temp
OutlineRenderStep::OutlineRenderStep(unsigned __int64 a, unsigned int b)
    : ReloadablePostProcess(a, NiFixedString("OutlineTechnique"), 0, b), m_b8(0), m_c0(0)
{
    NiFixedString name("OutlineRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416264b0
bool OutlineRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, b))
        return false;
    NiRenderer* p = GetNiRenderer();
    NiRenderTargetGroup* q = p->GetDefaultRenderTargetGroup();
    unsigned int w = q->GetWidth(0);
    unsigned int h = q->GetHeight(0);
    Unk_PPFmt fmt;
    fmt.v = a;
    m_b8.Assign(FUN_141d61a80(w, h, p, &fmt, 0x100));
    if (FUN_140c8f680(&m_b8) == 0) {
        vfunc_16();
        return false;
    }
    m_c0.Assign(FUN_141d61a80(w, h, p, &fmt, 0x100));
    if (FUN_140c8f680(&m_c0) == 0) {
        vfunc_16();
        return false;
    }
    if (!vfunc_23()) {
        vfunc_16();
        return false;
    }
    return true;
}

// @0x141626650
bool OutlineRenderStep::vfunc_23()
{
    void* p;
    FUN_141626ac0(this);
    p = FUN_140c8f690(FUN_1416b4990(this, "OuterBlur_H", 0, 0, FUN_140c8f680(&((void**)m_98)[10]), 0, 0, FUN_140c8f680(&m_b8), "OuterGaussianBlur_H", 0, 0, 0));
    if (p == 0)
        return false;
    p = FUN_140c8f690(FUN_1416b4990(this, "OuterBlur_V", 0, 0, FUN_140c8f680(&m_b8), 0, 0, FUN_140c8f680(&m_c0), "OuterGaussianBlur_V", 0, 0, 0));
    if (p == 0)
        return false;
    p = FUN_140c8f690(FUN_1416b4990(this, "OutlineClick", 0, 0, FUN_140c8f680(&m_80), 0, 3, 0, "OutlineTechnique", FUN_140c8f680(&((void**)m_98)[10]), FUN_140c8f680(&m_c0), 0));
    if (p == 0)
        return false;
    return true;
}

// @0x141626970
void OutlineRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_b8.Assign(0);
    m_c0.Assign(0);
}

// @0x1416269c0
// MS2-FUNCTIONAL: see ReloadablePostProcess::~ReloadablePostProcess (vptr store not in exe)
OutlineRenderStep::~OutlineRenderStep()
{
}

// @0x141626a00
// MS2-FUNCTIONAL: the exe omits the vptr store in this dtor and in ~OutlineRenderStep (cause unknown); ours stores it.
ReloadablePostProcess::~ReloadablePostProcess()
{
}

// @0x141626a90
const NiRTTI* OutlineRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x141626aa0
bool ReloadablePostProcess::vfunc_14() { return false; }

// @0x141626ab0
bool ReloadablePostProcess::vfunc_13() { return false; }

// @0x141626ac0
void FUN_141626ac0(void* p)
{
    FUN_141475e60((char*)p + 0x50);
}

#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
// @0x141626ae0 (UCRT header-inline memcpy_s emitted as an ordinary function)
errno_t FUN_141626ae0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}

MS2_REPLACE_METHOD(0x1416264B0, OutlineRenderStep, vfunc_15, 409, 0x9E9695B6);
MS2_REPLACE_METHOD(0x141626650, OutlineRenderStep, vfunc_23, 787, 0x00EA1A97);
MS2_REPLACE_METHOD(0x141626970, OutlineRenderStep, vfunc_16, 66, 0x5D0A5722);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x141626a90, OutlineRenderStep, GetRTTI, 13, 0xE04CAFAB);
MS2_REPLACE_METHOD(0x141626aa0, ReloadablePostProcess, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x141626ab0, ReloadablePostProcess, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE(0x141626ac0, FUN_141626ac0, 31, 0xC6A21E5A);

