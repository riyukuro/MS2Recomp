// screenmaskingeffectparam.h - the "ScreenMasking" screen effect (effect XML type 0x12): a full-screen mask texture
// (Image/ScreenMask/<texture>) blended in by the ScreenMaskingRenderStep (post-process step id 8; texture swap
// FUN_1416ba640 in ?\screenmaskingrenderstep.cpp). Owning unit: ?\screenmaskingeffectparam.cpp
// (0x140dca0b0-0x140dca750). Header name assumed. Shader constant DAT_143ae5340 (blend, 1 float).
#pragma once
#include "ms2/client/ms2/posteffectparam.h"

// 0x70 bytes. Implicit virtual dtor 0x140dca690, ??_G 0x140dca700.
class ScreenMaskingEffectParam : public CPostEffectParam
{
public:
    ScreenMaskingEffectParam();                                    // 0x140dca0b0
    virtual void vfunc_1(TiXmlElement* pNode);                    // 1 0x140dca130
public:
    float m_fBlendingMin;           // +0x60 "blendingMin"
    float m_fBlendingMax;           // +0x64 "blendingMax" = 1
    CString m_strTexture;           // +0x68 "texture" = "title_make_ch.tga"
};
MS2_CHECK_SIZE(ScreenMaskingEffectParam, 0x70);
MS2_CHECK_OFFSET(ScreenMaskingEffectParam, m_strTexture, 0x68);

// 0x60 bytes. Implicit virtual dtor 0x140dca660, ??_G 0x140dca6c0.
class ScreenMaskingEffect : public CScreenEffectBase
{
public:
    ScreenMaskingEffect(int nId, const CPostEffectParam* pParam);  // 0x140dca1b0 (pParam is a ScreenMaskingEffectParam)
    virtual void vfunc_1();                                        // 1 0x140dca2a0 start: step 8 on, load the mask
    virtual void vfunc_4();                                        // 4 0x140dca410 stop: step 8 off, blend 0
    virtual int vfunc_5();                                         // 5 0x140dca740 return 0x12
    virtual bool vfunc_6(bool b);                                  // 6 0x140dca470 reload the mask
    virtual void vfunc_7(int nState, float fAlpha);                // 7 0x140dca5d0 blend constant
public:
    float m_fBlendMin;              // +0x50 param m_fBlendingMin if > 0
    float m_fBlendMax;              // +0x54 param m_fBlendingMax if < 1
    CString m_strTexture;           // +0x58
};
MS2_CHECK_SIZE(ScreenMaskingEffect, 0x60);
MS2_CHECK_OFFSET(ScreenMaskingEffect, m_strTexture, 0x58);
