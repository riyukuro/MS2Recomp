// monochromeeffectparam.h - the "Monochrome" screen effect (effect XML type 4): param + runtime screen effect.
// Owning unit: ?\monochromeeffectparam.cpp (0x1414876d0-0x141487a20). Header name assumed from the unit path.
// Shader constant DAT_143ae5350 (saturation, 1 float); post-process step id 7.
#pragma once
#include "ms2/client/ms2/posteffectparam.h"

// 0x68 bytes. Implicit virtual dtor 0x141487970, ??_G 0x1414879d0.
class MonochromeEffectParam : public CPostEffectParam
{
public:
    MonochromeEffectParam();                                       // 0x1414876d0
    virtual void vfunc_1(TiXmlElement* pNode);                    // 1 0x141487730
public:
    float m_fSaturationMin;         // +0x60 "saturationMin"
    float m_fSaturationMax;         // +0x64 "saturationMax" = 1
};
MS2_CHECK_SIZE(MonochromeEffectParam, 0x68);
MS2_CHECK_OFFSET(MonochromeEffectParam, m_fSaturationMin, 0x60);

// 0x58 bytes. Implicit virtual dtor 0x141487950, ??_G 0x141487990.
class MonochromeEffect : public CScreenEffectBase
{
public:
    MonochromeEffect(int nId, const CPostEffectParam* pParam);     // 0x1414877a0 (pParam is a MonochromeEffectParam)
    virtual void vfunc_1();                                        // 1 0x141487840 start: step 7 on
    virtual void vfunc_4();                                        // 4 0x141487880 stop: step 7 off
    virtual int vfunc_5();                                         // 5 0x141487a10 return 4
    virtual void vfunc_7(int nState, float fAlpha);                // 7 0x1414878c0 saturation constant
public:
    float m_fSaturationMin;         // +0x50
    float m_fSaturationMax;         // +0x54 = 1
};
MS2_CHECK_SIZE(MonochromeEffect, 0x58);
MS2_CHECK_OFFSET(MonochromeEffect, m_fSaturationMin, 0x50);
