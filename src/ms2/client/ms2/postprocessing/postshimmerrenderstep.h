// postshimmerrenderstep.h - the "PostShimmer" screen effect: render step (PostShimmerRenderStep, Gamebryo RTTI), effect
// param (effect XML type 0x14) and runtime screen effect. Owning unit: ?\postshimmerrenderstep.cpp
// (0x140c8efe0-0x140c90340). Header name assumed. Shader constants: DAT_143ae5438 (blend, 1 float),
// DAT_143ae5448 (uv move, 1 NiPoint2).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"
#include "ms2/client/ms2/posteffectparam.h"
#include <NiPoint2.h>

// 0xa0 bytes (PostProcessEffect + nothing). vftable 0x142e14490 (23 slots); ??_G 0x140c8f6a0.
class PostShimmerRenderStep : public PostProcessEffect
{
public:
    PostShimmerRenderStep(unsigned __int64 a, unsigned int b);      // 0x140c8efe0
    virtual ~PostShimmerRenderStep();                              // 0x140c8f060
    virtual const NiRTTI* GetRTTI() const;                         // 2  0x140c8f870
    virtual bool vfunc_13();                                       // 13 0x140c8f900 false
    virtual bool vfunc_14();                                       // 14 0x140c8f890 false
    virtual bool vfunc_15(unsigned int a, void* b);                // 15 0x140c8f090 load shimmer.tga, build the click
    virtual void vfunc_16();                                       // 16 0x140c8f5a0 release the texture

    static const NiRTTI ms_RTTI;                                   // 0x143abf730 ("PostShimmerRenderStep")
};
MS2_CHECK_SIZE(PostShimmerRenderStep, 0xa0);

// 0x78 bytes. vftable 0x142e14668 (8 slots; overrides 1). Effect XML type 0x14.
class PostShimmerEffectParam : public CPostEffectParam
{
public:
    PostShimmerEffectParam();                                      // 0x140c8f980
    // implicit virtual dtor 0x140c901f0 (no vptr reset), ??_G 0x140c902a0
    virtual void vfunc_1(TiXmlElement* pNode);                    // 1 0x140c8fa20
public:
    float m_fBlendingMin;           // +0x60 "blendingMin" (percent)
    float m_fBlendingMax;           // +0x64 "blendingMax" = 1
    float m_fMoveX;                 // +0x68 "moveX" (uv scroll speed)
    float m_fMoveY;                 // +0x6c "moveY"
    CString m_strTexture;           // +0x70 "texture" = "shimmer.tga"
};
MS2_CHECK_SIZE(PostShimmerEffectParam, 0x78);
MS2_CHECK_OFFSET(PostShimmerEffectParam, m_fBlendingMin, 0x60);
MS2_CHECK_OFFSET(PostShimmerEffectParam, m_strTexture, 0x70);

// 0x70 bytes. vftable 0x142e146b0 (8 slots: 0 ??_G 0x140c90260, 1, 2, 4, 5, 6, 7 overridden).
class PostShimmerEffect : public CScreenEffectBase
{
public:
    PostShimmerEffect(int nId, const CPostEffectParam* pParam);    // 0x140c8fae0 (pParam is a PostShimmerEffectParam)
    // implicit virtual dtor 0x140c901c0 (no vptr reset), ??_G 0x140c90260
    virtual void vfunc_1();                                        // 1 0x140c8fc40 start: shader on, texture, constants
    virtual bool vfunc_2();                                        // 2 0x140c8fdf0 update: scroll the uv offset
    virtual void vfunc_4();                                        // 4 0x140c8fe90 stop: shader off
    virtual int vfunc_5();                                         // 5 0x140c902e0 return 0x14
    virtual bool vfunc_6(bool b);                                  // 6 0x140c8fed0 reload the texture
    virtual void vfunc_7(int nState, float fAlpha);                // 7 0x140c90040 blend constant
public:
    float m_fBlendMin;              // +0x50 param m_fBlendingMin if > 0
    float m_fBlendMax;              // +0x54 param m_fBlendingMax if < 1
    NiPoint2 m_kMove;               // +0x58 param moveX/moveY
    CString m_strTexture;           // +0x60
    double m_dStart;                // +0x68 m_dStartTime at start
};
MS2_CHECK_SIZE(PostShimmerEffect, 0x70);
MS2_CHECK_OFFSET(PostShimmerEffect, m_kMove, 0x58);
MS2_CHECK_OFFSET(PostShimmerEffect, m_dStart, 0x68);
