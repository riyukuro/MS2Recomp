// radialblureffectparam.h - the "RadialBlur" screen effect (effect XML type 5): param + runtime screen effect.
// Owning unit: ?\radialblureffectparam.cpp (0x1416ec120-0x1416ec580). Header name assumed from the unit path.
// Shader constant DAT_143ae5458 (blur distance, 1 float); post-process step id 9.
#pragma once
#include "ms2/client/ms2/posteffectparam.h"

// 0x68 bytes. Implicit virtual dtor 0x1416ec3b0, ??_G 0x1416ec410.
class RadialBlurEffectParam : public CPostEffectParam
{
public:
    RadialBlurEffectParam();                                       // 0x1416ec120
    virtual void vfunc_1(TiXmlElement* pNode);                    // 1 0x1416ec180
public:
    float m_fDistMin;               // +0x60 "distMin"
    float m_fDistMax;               // +0x64 "distMax" = 1
};
MS2_CHECK_SIZE(RadialBlurEffectParam, 0x68);
MS2_CHECK_OFFSET(RadialBlurEffectParam, m_fDistMin, 0x60);

// 0x58 bytes. Implicit virtual dtor 0x1416ec390, ??_G 0x1416ec3d0.
class RadialBlurEffect : public CScreenEffectBase
{
public:
    RadialBlurEffect(int nId, const CPostEffectParam* pParam);     // 0x1416ec1f0 (pParam: RadialBlurEffectParam, never null)
    virtual void vfunc_1();                                        // 1 0x1416ec280 start: step 9 on
    virtual void vfunc_4();                                        // 4 0x1416ec2c0 stop: step 9 off
    virtual int vfunc_5();                                         // 5 0x1416ec450 return 5
    virtual void vfunc_7(int nState, float fAlpha);                // 7 0x1416ec300 distance constant
public:
    float m_fDistMin;               // +0x50
    float m_fDistMax;               // +0x54
};
MS2_CHECK_SIZE(RadialBlurEffect, 0x58);
MS2_CHECK_OFFSET(RadialBlurEffect, m_fDistMin, 0x50);
