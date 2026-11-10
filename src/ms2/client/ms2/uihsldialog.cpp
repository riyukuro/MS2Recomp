// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uihsldialog.h.
// MS2-UNIT: ?\uihsldialog.cpp
// MS2-RANGE: 0x1412c9860-0x1412c9e70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihsldialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uihsldialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"

#include "ms2/client/ms2/ms2.h"   // C3: MS2::GetBackgroundColor / SetBackgroundColor

// ---- out-of-unit callees ----
void* GetMS2();                                                  // the renderer singleton

extern "C" float (__cdecl* __imp_ceilf)(float);                       // the exe calls the IAT slot

// @0x1412c9860
UIHSLDialog::UIHSLDialog()
{
    m_nHue = 0;
    m_nSaturation = 0;
    m_nLightness = 0;
    m_40 = 1;
}

// @0x1412c98e0
UIHSLDialog::~UIHSLDialog()
{
}

// @0x1412c9920
CString UIHSLDialog::GetTypeName()
{
    return "HSLDialog";
}

// @0x1412c9970
void UIHSLDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    NiColorA kRgb = reinterpret_cast<MS2*>(GetMS2())->GetBackgroundColor();
    int nR = (int)__imp_ceilf(kRgb.r * 255.0f);
    int nG = (int)__imp_ceilf(kRgb.g * 255.0f);
    int nB = (int)__imp_ceilf(kRgb.b * 255.0f);
    m_30->Invoke("initData", nR, nG, nB);
}

// @0x1412c9c50
void ApplyBackgroundColor(UIHSLDialog* pDialog)
{
    reinterpret_cast<MS2*>(GetMS2())->SetBackgroundColor(NiColorA((float)pDialog->m_nHue / 255.0f, (float)pDialog->m_nSaturation / 255.0f,
                                                 (float)pDialog->m_nLightness / 255.0f, 1.0f));
}

// @0x1412c9a40
int UIHSLDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeSliderHue", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            m_nHue = data.PopInt();
            ApplyBackgroundColor(this);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderSaturation", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            m_nSaturation = data.PopInt();
            ApplyBackgroundColor(this);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderLightness", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            m_nLightness = data.PopInt();
            ApplyBackgroundColor(this);
        }
        return 1;
    }
    return 0;
}

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h), an unreferenced copy kept in this unit.
#pragma function(memmove)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x1412c9d50
errno_t FUN_1412c9d50(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
