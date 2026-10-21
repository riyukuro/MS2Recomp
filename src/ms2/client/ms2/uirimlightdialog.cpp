// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uirimlightdialog.h.
// MS2-UNIT: client\ms2\uirimlightdialog.cpp
// MS2-RANGE: 0x141709320-0x141709970 .text$mn
// MS2-RANGE: 0x1400ff540-0x1400ff6b0 .text$di
// MS2-RANGE: 0x142cb5eb0-0x142cb5f40 .text$yd
// One of the six objs inside the units.tsv range of client\ms2\scenestategame.cpp (see scenestatebase.cpp).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirimlightdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uirimlightdialog.h"

#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"

// ---- unit-local placeholders ----

// An RGB triple (ctor 0x1405522f0).
struct Unk_Color3
{
    Unk_Color3();
    float r, g, b;
};

// The character rim light / SSS settings (statics; the setters live in another unit, the getters are inline COMDATs
// of this obj).
class Unk_RimLight
{
public:
    static void FUN_14107b2a0(float fYaw, float fPitch);                 // s_fYaw = fYaw, s_fPitch = fPitch
    static void FUN_14107b320(const Unk_Color3& color, float fPower);    // s_sssColor = color, s_fSSSPower = fPower
    // @0x141709920
    static float FUN_141709920() { return s_fPitch; }
    // @0x141709930
    static float FUN_141709930() { return s_fYaw; }
    // @0x141709940
    static const Unk_Color3* FUN_141709940() { return &s_sssColor; }
    // @0x141709950
    static float FUN_141709950() { return s_fSSSPower; }

    static float s_fPitch;              // 0x1439f6fec
    static float s_fYaw;                // 0x143acd4b0
    static Unk_Color3 s_sssColor;       // 0x143acd550
    static float s_fSSSPower;           // 0x1439f6ff0
};

// Shadow parameters set by "onChangeSliderShadow" (four consecutive floats).
extern float g_1439f81f4, g_1439f81f8, g_1439f81fc, g_1439f8200;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141709320
UIRimLightDialog::UIRimLightDialog()
{
    m_40 = 1;
}

// @0x141709370
UIRimLightDialog::~UIRimLightDialog()
{
}

// @0x1417093b0
CString UIRimLightDialog::vfunc_1()
{
    return "RimLightDialog";
}

// @0x141709400
void UIRimLightDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    obj.FUN_1409c4a30("lightYaw", Unk_RimLight::FUN_141709930() + 90.0f);
    obj.FUN_1409c4a30("lightPitch", Unk_RimLight::FUN_141709920());
    obj.FUN_1407cb9c0("shadowMaxHeight", 400);
    obj.FUN_140e06d60("shadowMinScale", 0.5);
    obj.FUN_1407cb9c0("shadowDefaultSize", 100);
    obj.FUN_1407cb9c0("shadowDefaultBias", 3);
    const Unk_Color3* pColor = Unk_RimLight::FUN_141709940();
    obj.FUN_1409c4a30("sssRed", pColor->r);
    obj.FUN_1409c4a30("sssGreen", pColor->g);
    obj.FUN_1409c4a30("sssBlue", pColor->b);
    obj.FUN_1409c4a30("sssPower", Unk_RimLight::FUN_141709950());
    m_30->Invoke("initData", obj.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141709400, UIRimLightDialog, OnLoadComplete, 452, 0x6611AC2D);

// @0x1417095d0
int UIRimLightDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeSliderLightAngle", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1417097a0(data);
        return 1;
    }
    else if (_stricmp("onChangeSliderShadow", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141709800(data);
        return 1;
    }
    else if (_stricmp("onChangeSliderSSS", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141709870(data);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1417095d0, UIRimLightDialog, vfunc_28, 445, 0x2FB16BBD);

// @0x1417097a0
void UIRimLightDialog::FUN_1417097a0(ASData& data)
{
    float fYaw = data.FUN_1422b8c10() - 90.0f;
    float fPitch = data.FUN_1422b8c10();
    Unk_RimLight::FUN_14107b2a0(fYaw, fPitch);
}
MS2_REPLACE_METHOD(0x1417097a0, UIRimLightDialog, FUN_1417097a0, 76, 0x1E22E413);

// @0x141709800
void UIRimLightDialog::FUN_141709800(ASData& data)
{
    g_1439f81f4 = data.FUN_1422b8c10();
    g_1439f81f8 = data.FUN_1422b8c10();
    g_1439f81fc = data.FUN_1422b8c10();
    g_1439f8200 = data.FUN_1422b8c10();
}
MS2_REPLACE_METHOD(0x141709800, UIRimLightDialog, FUN_141709800, 91, 0x28CBBBB8);

// @0x141709870
void UIRimLightDialog::FUN_141709870(ASData& data)
{
    Unk_Color3 color;
    color.r = data.FUN_1422b8c10();
    color.g = data.FUN_1422b8c10();
    color.b = data.FUN_1422b8c10();
    float fPower = data.FUN_1422b8c10();
    Unk_RimLight::FUN_14107b320(color, fPower);
}
MS2_REPLACE_METHOD(0x141709870, UIRimLightDialog, FUN_141709870, 109, 0xE8BFE176);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)

