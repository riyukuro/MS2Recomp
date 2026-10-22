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

struct Unk_HslColor { float r, g, b, a; Unk_HslColor() {} };
struct Unk_HslRgb { float r, g, b; Unk_HslRgb() {} };

// ---- out-of-unit callees ----
void* FUN_140aae430();                                                  // the renderer singleton

void FUN_14148a050(void* pRenderer, Unk_HslRgb* pRgb);                      // reads the current colour (3 floats)
float FUN_140bf4fd0(float f);                                           // ceilf
void* FUN_14097f1d0(void* out, float r, float g, float b, float a);     // builds a colour
void FUN_141489ff0(void* pRenderer, Unk_HslColor kColor);               // sets the colour

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

// MS2-FUNCTIONAL: float-to-int conversion and local colour temporaries are laid out differently (39 bytes longer)
// @0x1412c9970
void UIHSLDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_HslRgb kRgb;
    FUN_14148a050(FUN_140aae430(), &kRgb);
    float fR = FUN_140bf4fd0(kRgb.r * 255.0f);
    float fG = FUN_140bf4fd0(kRgb.g * 255.0f);
    float fB = FUN_140bf4fd0(kRgb.b * 255.0f);
    m_30->Invoke("initData", (int)fR, (int)fG, (int)fB);
}

// MS2-FUNCTIONAL: the exe copies the returned colour with a byte loop, we use a struct copy
// @0x1412c9c50
void FUN_1412c9c50(UIHSLDialog* pDialog)
{
    Unk_HslColor kBuf;
    Unk_HslColor kColor = *(Unk_HslColor*)FUN_14097f1d0(&kBuf, (float)pDialog->m_nHue / 255.0f, (float)pDialog->m_nSaturation / 255.0f,
                                                        (float)pDialog->m_nLightness / 255.0f, 1.0f);
    FUN_141489ff0(FUN_140aae430(), kColor);
}

// @0x1412c9a40
int UIHSLDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeSliderHue", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_nHue = data.FUN_1422b8a10();
            FUN_1412c9c50(this);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderSaturation", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_nSaturation = data.FUN_1422b8a10();
            FUN_1412c9c50(this);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderLightness", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_nLightness = data.FUN_1422b8a10();
            FUN_1412c9c50(this);
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
