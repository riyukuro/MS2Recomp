// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UILightDialog (debug dialog, UI type 0x4ead, "LightDialog") with
// the fog switch, fog colour and fog depth sliders, plus this TU's copies of the UCRT memcpy_s / memmove_s.
// File name guessed (uilightdialog.cpp); the unit is unnamed in the exe.
// MS2-UNIT: unit_141448b90
// MS2-RANGE: 0x141448b90-0x1414494d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UILightDialog@@UEAAHXZ 0x141449250 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_141448b90.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <ecr/SceneGraphService.h>
#include <NiNode.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
struct Unk_Colc { float x, y, z; Unk_Colc(float x, float y, float z); };    // ctor 0x140a56db0

// The scene fog block (global at 0x143afa7f0).
struct Unk_FogState
{
    void FUN_1409a9b90(bool bEnable);               // 0x1409a9b90
    void FUN_1409a9bc0(const Unk_Colc& color);      // 0x1409a9bc0
    void FUN_1409a9b40(float fValue);               // 0x1409a9b40
};
Unk_FogState* FUN_1409a8a80();                      // the global fog block

// The renderer's state block (MS2Renderer +0xba8).
struct Unk_RenderState { void FUN_1409a9bf0(float fMaxFog); };
struct Unk_FogRenderer { Unk_RenderState* FUN_1409a8d60(); };               // 0x1409a8d60 returns the +0xba8 block

// The main 3D view -> camera -> view frustum (near/far at +0x10/+0x14).
struct Unk_ViewFrustum { char m_pad_00[0x10]; float m_fNear; float m_fFar; };
struct Unk_FogCamera { Unk_ViewFrustum* FUN_1409a8de0(); };                // 0x1409a8de0 returns this + 0x128
struct Unk_FogView { Unk_FogCamera* FUN_1409a8a60(); };                    // 0x1409a8a60 returns the camera at +0x38
Unk_FogView* FUN_1413f9a70();
void* FUN_140994450();                                                      // the current NiRenderer
void* FUN_14098d8d0(const void* pRtti, void* pObject);                      // dynamic cast through an NiRTTI (NULL-safe)
extern char DAT_143d6eb58;                                                  // MS2Renderer's RTTI
extern char DAT_143b059e8;                                                  // the entity app framework
ecr::SceneGraphService* FUN_1409a5700(void* pFramework);                    // the scene graph service

// The engine's light-service functor that re-evaluates which lights affect each scene graph (Gamebryo LightService.cpp, ctor
// 0x1409a79c0, dtor 0x1409a7d30; the engine copy is not linked into the hook DLL).
class UpdateAffectsFunctor
    : public ecr::SceneGraphService::EntitySceneGraphFunctor
    , public ecr::SceneGraphService::HandleSceneGraphFunctor
{
public:
    UpdateAffectsFunctor();
    ~UpdateAffectsFunctor();
    efd::Bool operator()(const egf::Entity* pEntity, const efd::vector<NiObjectPtr>& objects);
    efd::Bool operator()(const ecr::SceneGraphService::SceneGraphHandle handle, const efd::vector<NiObjectPtr>& objects);
};

// The UCRT's header-inline memcpy_s / memmove_s of this TU (0x141449260 / 0x1414493b0), kept alive through ATL::Checked.
// @0x141449260
#pragma function(memset, memcpy)
static __inline errno_t ms2_uld_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnUldMemcpyS)(void*, size_t, const void*, size_t) = &ms2_uld_memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();

// UILightDialog: RTTI .?AVUILightDialog@@, vftables 0x142ea.... (primary) and +0x18 (IMessageListener). No members of its own.
class UILightDialog : public UIDialog
{
public:
    UILightDialog();                                                                // 0x141448b90
    virtual ~UILightDialog();                                                       //  0 0x141448be0
    virtual CString GetTypeName();                                                      //  1 0x141448c20
    virtual void OnLoadComplete();                                                  // 22 0x141448c90
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                    // 28 0x141448ce0
    virtual int vfunc_48() { return 0x4ead; }                                       // 48 (COMDAT 0x141449250)
    virtual void vfunc_67();                                                        // 67 0x141448c70

    void FUN_141448ec0(ASData* pData);                                              // fog colour (r, g, b in 0..255)
    void FUN_141448fd0(ASData* pData);                                              // fog depth (two sliders)
    void FUN_141449190(bool bEnable);                                               // fog on/off
};

// @0x141448b90
UILightDialog::UILightDialog()
{
    m_40 = 1;
}

// @0x141448be0
UILightDialog::~UILightDialog()
{
}

// @0x141448c20
CString UILightDialog::GetTypeName()
{
    return "LightDialog";
}

// @0x141448c70
void UILightDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141448c90
void UILightDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_30->Invoke("initData");
}

// @0x141448ce0
int UILightDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeFogEnable", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bEnable = data.FUN_1422b8a90();
            FUN_141449190(bEnable);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderColor", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141448ec0(&data);
        return 1;
    }
    else if (_stricmp("onChangeSliderDepth", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141448fd0(&data);
        return 1;
    }
    return 0;
}

// @0x141448ec0
void UILightDialog::FUN_141448ec0(ASData* pData)
{
    float fR = pData->FUN_1422b8c10();
    float fG = pData->FUN_1422b8c10();
    float fB = pData->FUN_1422b8c10();
    Unk_FogState* pFog = FUN_1409a8a80();
    pFog->FUN_1409a9bc0(Unk_Colc(fR / 255.0f, fG / 255.0f, fB / 255.0f));
    ecr::SceneGraphService* pService = FUN_1409a5700(&DAT_143b059e8);
    if (pService != 0) {
        UpdateAffectsFunctor functor;
        pService->ForEachEntitySceneGraph(functor);
    }
}

// @0x141448fd0
void UILightDialog::FUN_141448fd0(ASData* pData)
{
    float fSlider1 = pData->FUN_1422b8c10();
    float fSlider2 = pData->FUN_1422b8c10();
    float fFogValue = 1.0f;
    float fDensity = 1.0f;
    float fNear = 0.0f;
    float fFar = 0.0f;
    Unk_FogView* pView = FUN_1413f9a70();
    Unk_ViewFrustum* pFrustum = pView->FUN_1409a8a60()->FUN_1409a8de0();
    fNear = pFrustum->m_fNear;
    fFar = pFrustum->m_fFar;
    fFogValue = (fFar - fSlider1) / (fFar - fNear);
    float fRange = (fFar - fNear) * fFogValue;
    fDensity = fRange / (fRange + (fSlider2 - fFar));
    Unk_FogRenderer* pRenderer = (Unk_FogRenderer*)FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    pRenderer->FUN_1409a8d60()->FUN_1409a9bf0(fDensity);
    Unk_FogState* pFog = FUN_1409a8a80();
    pFog->FUN_1409a9b40(fFogValue);
    ecr::SceneGraphService* pService = FUN_1409a5700(&DAT_143b059e8);
    if (pService != 0) {
        UpdateAffectsFunctor functor;
        pService->ForEachEntitySceneGraph(functor);
    }
}

// @0x141449190
void UILightDialog::FUN_141449190(bool bEnable)
{
    Unk_FogState* pFog = FUN_1409a8a80();
    pFog->FUN_1409a9b90(bEnable);
    ecr::SceneGraphService* pService = FUN_1409a5700(&DAT_143b059e8);
    if (pService != 0) {
        UpdateAffectsFunctor functor;
        pService->ForEachEntitySceneGraph(functor);
    }
}
