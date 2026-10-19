// applyeffect.h - PLACEHOLDER for ApplyEffect (RTTI .?AVApplyEffect@@, 0x70 bytes). NOT an original header.
// Bases: TSingleton<ApplyEffect> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It applies the screen post effects (fog, soft
// particles, outer glow / material swap render lists) and keeps the active CScreenEffectBase objects by id.
// Owning unit: ?\applyeffect.cpp (0x1409a36c0-0x1409ab110). Member names inferred.
#pragma once

#include <atlcoll.h>
#include <atlstr.h>
#include <map>
#include <efd/SmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"

class CScreenEffectBase;
class MS2OuterGlowMaterialSwapProcessor;
class MS2MaterialSwapProcessor;
class SoftParticlesManager;
class NiRenderListProcessor;
class Unk_AeFieldInfo;

class ApplyEffect : public TSingleton<ApplyEffect>
{
public:
    typedef std::map<int, MS2Ptr<CScreenEffectBase> > EffectMap;
    typedef ATL::CRBMap<CStringA, NiRenderListProcessor*> ClickMap;

    ApplyEffect();                                          // 0x1409a36c0
    virtual ~ApplyEffect();                                 // 0x1409a3810

    void Initialize();                                      // 0x1409a38d0
    void ApplyOuterGlowColor();                             // 0x1409a3ad0
    void FUN_1409a3b60(bool bEnable);                       // enable/disable every effect
    void RestoreClickProcessors();                          // 0x1409a3c20
    void SwapClickProcessor(NiRenderListProcessor* pProcessor);  // 0x1409a3d80
    void FUN_1409a3ee0(int nId, int nType);
    void FUN_1409a3f80(int nId, int nType);
    bool FUN_1409a4020(int nId, CScreenEffectBase* pEffect);
    void FUN_1409a4090();
    void FUN_1409a4150();
    void ResetScreenRatio();                                // 0x1409a4230
    void ApplyFieldFogRange(bool bEnabled);                 // 0x1409a43a0
    void SetFogRange(bool bEnabled, float fNear, float fFar, unsigned int uiColor);   // 0x1409a4450
    void SetFogEffect(bool bEnabled, unsigned int* puiColor, float fNear, float fFar, float fDensity);   // 0x1409a46a0
    void GetFog(float* pfNear, float* pfFar, unsigned int* puiColor);   // 0x1409a4960
    void ApplyFieldFog();                                   // 0x1409a49b0
    void ApplyFieldFogEnabled(bool bEnabled);               // 0x1409a4b00
    bool SetSoftParticlesOption(bool bEnabled, Unk_AeFieldInfo* pField);   // 0x1409a4c60
    void ApplySoftParticleOption();                         // 0x1409a4e30
    void SetOuterGlowEnabled(bool bEnabled);                // 0x1409a4e70
    void ApplyOuterGlowOption();                            // 0x1409a4ed0
    void SetFeatureB(bool bEnabled);                        // 0x1409a4f10
    void SetScreenRatio(float fScale);                      // 0x1409a4f40
    void ApplyFieldRenderInfo();                            // 0x1409a5080
    void SetFeature8(bool bEnabled, bool bUnused);          // 0x1409a5100
    SoftParticlesManager* GetSoftParticles();               // 0x1409a5160
    void SetSoftParticlesEnabled(bool bEnabled);            // 0x1409a5190

private:
    MS2_LAYOUT_FRIEND;
    float m_fFogNear;                                       // +0x08
    float m_fFogFar;                                        // +0x0c
    unsigned int m_uiFogColor;                              // +0x10
    efd::SmartPointer<MS2OuterGlowMaterialSwapProcessor> m_spOuterGlow;       // +0x18
    efd::SmartPointer<MS2MaterialSwapProcessor> m_spMaterialSwap;   // +0x20
    ClickMap m_clicks;                                      // +0x28 processor each click had before the swap
    efd::SmartPointer<SoftParticlesManager> m_spSoftParticles;      // +0x58
    EffectMap m_effects;                                    // +0x60
};
MS2_CHECK_SIZE(ApplyEffect, 0x70);
