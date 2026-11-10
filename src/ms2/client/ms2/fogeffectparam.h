// fogeffectparam.h - the "Fog" effect (effect XML type 10): blends the scene fog (near/far/color) from the current
// values to the param's over the effect duration. Param (CEffectParam) + runtime effect (CEffect). Owning unit:
// ?\fogeffectparam.cpp (0x1412208a0-0x141221290). Header name assumed from the unit path.
#pragma once
#include "ms2/client/ms2/effectparam.h"

// 0x58 bytes. vftable 0x142ec39d8 (8 slots; overrides 1, 6). Implicit virtual dtor 0x1412211b0, ??_G 0x141221230.
class CFogEffectParam : public CEffectParam
{
public:
    CFogEffectParam();                                          // 0x1412208a0
    virtual void vfunc_1(TiXmlElement* pNode);                 // 1 0x141220910 <fog color="r,g,b" near far>
    virtual CEffectPtr vfunc_6();                               // 6 0x141220aa0 new CFogEffect
public:
    unsigned int m_dwColor;         // +0x48 fog "color" as D3DCOLOR_XRGB (0xffffffff if fewer than 3 components)
    float m_fNear;                  // +0x4c fog "near" = 100
    float m_fFar;                   // +0x50 fog "far" = 10000
};
MS2_CHECK_SIZE(CFogEffectParam, 0x58);
MS2_CHECK_OFFSET(CFogEffectParam, m_dwColor, 0x48);
MS2_CHECK_OFFSET(CFogEffectParam, m_fFar, 0x50);

// 0x48 bytes. vftable 0x142ec3a20 (13 slots). ??_G 0x1412211d0.
class CFogEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141221280; ms_RTTI 0x143ad4098
public:
    CFogEffect();                                               // 0x141220b40
    virtual ~CFogEffect();                                      // 0x141220bb0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141220d90 capture + target
    virtual void vfunc_7();                                     // 7  0x141220ee0 apply the target fog
    virtual bool vfunc_9();                                     // 9  0x141220e90 update while running
    virtual int vfunc_12();                                     // 12 0x141221270 return 10

    // 0x141220be0: standalone create (no caller recovered; the first argument is unused).
    static CFogEffect* CreateFromParam(void* pUnused, const CFogEffectParam* pParam);
    void FUN_141220f50();                                       // 0x141220f50 {}
    void FUN_141220f60(double dNow);                            // 0x141220f60 apply the blend at dNow

public:
    float m_fNearFrom;              // +0x30 fog at start (manager getter 0x1409a4960)
    float m_fFarFrom;               // +0x34
    unsigned int m_dwColorFrom;     // +0x38
    float m_fNear;                  // +0x3c target = param m_fNear (100)
    float m_fFar;                   // +0x40 target = param m_fFar (10000)
    unsigned int m_dwColor;         // +0x44 target = param m_dwColor (0)
};
MS2_CHECK_SIZE(CFogEffect, 0x48);
MS2_CHECK_OFFSET(CFogEffect, m_fNearFrom, 0x30);
MS2_CHECK_OFFSET(CFogEffect, m_dwColor, 0x44);
