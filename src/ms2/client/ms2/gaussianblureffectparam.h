// gaussianblureffectparam.h - the "GaussianBlur" screen effect (effect XML type 0x13): param + runtime screen effect.
// Owning unit: ?\gaussianblureffectparam.cpp (0x140cfd2a0-0x140cfd6f0). Header name assumed from the unit path.
// Shader constants DAT_143ae5460 / DAT_143ae5468 (x / y blur offset, 1 float each); post-process step id 0xb.
#pragma once
#include "ms2/client/ms2/posteffectparam.h"

// 0x68 bytes. Implicit virtual dtor 0x140cfd640, ??_G 0x140cfd6a0.
class GaussianBlurEffectParam : public CPostEffectParam
{
public:
    GaussianBlurEffectParam();                                     // 0x140cfd2a0
    virtual void vfunc_1(TiXmlElement* pNode);                    // 1 0x140cfd300
public:
    float m_fOffsetMin;             // +0x60 "offsetMin"
    float m_fOffsetMax;             // +0x64 "offsetMax" = 1
};
MS2_CHECK_SIZE(GaussianBlurEffectParam, 0x68);
MS2_CHECK_OFFSET(GaussianBlurEffectParam, m_fOffsetMin, 0x60);

// 0x58 bytes. Implicit virtual dtor 0x140cfd620, ??_G 0x140cfd660.
class GaussianBlurEffect : public CScreenEffectBase
{
public:
    GaussianBlurEffect(int nId, const CPostEffectParam* pParam);   // 0x140cfd370 (pParam is a GaussianBlurEffectParam)
    virtual void vfunc_1();                                        // 1 0x140cfd410 start: step 0xb on
    virtual void vfunc_4();                                        // 4 0x140cfd450 stop: step 0xb off
    virtual int vfunc_5();                                         // 5 0x140cfd6e0 return 0x13
    virtual void vfunc_7(int nState, float fAlpha);                // 7 0x140cfd490 aspect-corrected blur offsets
public:
    float m_fOffsetMin;             // +0x50
    float m_fOffsetMax;             // +0x54 = 1
};
MS2_CHECK_SIZE(GaussianBlurEffect, 0x58);
MS2_CHECK_OFFSET(GaussianBlurEffect, m_fOffsetMin, 0x50);
