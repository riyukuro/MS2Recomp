// vibrateeffectparam.h - the "Vibrate" effect (effect XML type 0xc): shakes the camera (and the gamepad) for the
// effect's duration. Param (CEffectParam) + runtime effect (CEffect). Owning unit: ?\vibrateeffectparam.cpp
// (0x141b72630-0x141b72f60). Header name assumed from the unit path. Member names are invented from their use.
#pragma once
#include "ms2/client/ms2/effectparam.h"

// 0x58 bytes. vftable (8 slots; overrides 1, 2, 6, 7). Implicit virtual dtor 0x141b72e80, ??_G 0x141b72f00.
class CVibrateEffectParam : public CEffectParam
{
public:
    CVibrateEffectParam();                                      // 0x141b72630
    virtual void vfunc_1(TiXmlElement* pNode);                 // 1 0x141b72690 freq / amp / damping / dampingTime
    virtual bool vfunc_2();                                     // 2 0x141b72730 validate: dampingTime must not exceed duration
    virtual CEffectPtr vfunc_6();                               // 6 0x141b727b0 new CVibrateEffect
    virtual bool vfunc_7(Unk_EffectTarget* p);                  // 7 0x141b72850 also skip for target kind 3
public:
    MS2_LAYOUT_FRIEND;
    float m_fFreq;                  // +0x48 "freq"
    float m_fAmp;                   // +0x4c "amp"
    float m_fDamping;               // +0x50 "damping" = 1
    float m_fDampingTime;           // +0x54 "dampingTime" = 0
};
MS2_CHECK_SIZE(CVibrateEffectParam, 0x58);
MS2_CHECK_OFFSET(CVibrateEffectParam, m_fFreq, 0x48);
MS2_CHECK_OFFSET(CVibrateEffectParam, m_fDamping, 0x50);
MS2_CHECK_OFFSET(CVibrateEffectParam, m_fDampingTime, 0x54);

// 0x30 bytes (CEffect, no members). Implicit virtual dtor 0x141b728e0 (explicit here), ??_G 0x141b72ea0.
// ms_RTTI 0x143af7710 (GetRTTI 0x141b72f50).
class CVibrateEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI
public:
    CVibrateEffect();                                           // 0x141b728a0
    virtual ~CVibrateEffect();                                  // 0x141b728e0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141b72bd0 start the camera shake
    virtual void vfunc_7();                                     // 7  0x141b72e70 {}
    virtual bool vfunc_9();                                     // 9  0x141b72e00 still running
    virtual int vfunc_12();                                     // 12 0x141b72f40 return 0xc
};
MS2_CHECK_SIZE(CVibrateEffect, 0x30);

// Owner of the effect creation helper at 0x141b72910 (this is unused; class unrecovered).
class Unk_VibrateEffectFactory
{
public:
    CVibrateEffect* CreateVibrateEffect(const CVibrateEffectParam* pParam);   // create + start the shake directly (no NiPointer)
};
