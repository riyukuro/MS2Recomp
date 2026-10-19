// posteffectparam.h - CPostEffectParam (CEffectParam + fade settings) and CScreenEffectBase (CPtred-based timed
// full-screen post effect driven by a CPostEffectParam). Owning unit: ?\posteffectparam.cpp (0x140dbcbc0-0x140dbddc0,
// 25 funcs; also CPostEffect 0x38). Header name assumed from the unit path.
//
// HOW TO USE THIS HEADER (for unit workers):
// - Param: `class PostShimmerEffectParam : public CPostEffectParam`; effect: `class PostShimmerEffect : public
//   CScreenEffectBase`. CScreenEffectBase slots 5 and 7 are pure. vfunc_N = slot N of the vftables below.
// - CPostEffectParam's dtor is implicit (only COMDAT 0x140c901a0 is in postshimmerrenderstep; no vptr reset).
// - CScreenEffectBase is driven by its param: duration/fade times are copied in the ctor. States for SetState
//   (0x140dbdb00, non-virtual): 0 off, 1 fade-out, 2 hold, 3 fade-in (inferred from vfunc_2).
#pragma once
#include "ms2/client/ms2/effectparam.h"

// 0x60 bytes. vftable 0x142e37938 (8 slots, ??_G 0x140dbdc00); overrides 1, 6, 7.
class CPostEffectParam : public CEffectParam
{
public:
    explicit CPostEffectParam(int nType);                   // 0x140dbcbc0
    // implicit virtual dtor: COMDAT 0x140c901a0 (postshimmerrenderstep) has no vptr reset, so it is compiler-generated

    virtual void vfunc_1(Unk_140165cf0* pNode);             // 1 0x140dbcc40 + useFade/fade*Duration/holdDuration/interpolators
    virtual CEffectPtr vfunc_6();                           // 6 0x140dbce60 new CPostEffect (0x38)
    virtual bool vfunc_7(Unk_EffectTarget* p);              // 7 0x140dbcf00 base || p->+8 == 3

public:
    bool m_bUseFade;                // +0x48 "useFade"
    float m_fFadeStartDuration;     // +0x4c
    float m_fFadeEndDuration;       // +0x50
    float m_fHoldDuration;          // +0x54
    int m_nFadeStartInterpolator;   // +0x58 1 linear, 2/3 (strings 0x142e37850/54) = 1
    int m_nFadeEndInterpolator;     // +0x5c = 1
};
MS2_CHECK_SIZE(CPostEffectParam, 0x60);
MS2_CHECK_OFFSET(CPostEffectParam, m_bUseFade, 0x48);
MS2_CHECK_OFFSET(CPostEffectParam, m_fHoldDuration, 0x54);
MS2_CHECK_OFFSET(CPostEffectParam, m_nFadeEndInterpolator, 0x5c);

// 0x38 bytes. Runtime post effect created by CPostEffectParam::vfunc_6. vftable 0x142e37980 (13 slots, ??_G
// 0x140dbdba0). vfunc_3 creates the CScreenEffectBase subclass for the param type (4 Monochrome, 5 RadialBlur,
// 0x12 ScreenMasking, 0x13 GaussianBlur, 0x14 PostShimmer) and registers it with the post-process manager under m_nId.
class CPostEffect : public CEffect
{
    NiDeclareRTTI;                                  // 2 GetRTTI 0x140dbdc90; ms_RTTI 0x143ac47d0 ("CPostEffect" : CEffect)
public:
    CPostEffect();                                  // 0x140dbcf50
    virtual ~CPostEffect();                         // 0x140dbcfa0

    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x140dbcfd0
    virtual void vfunc_4();                         // 4  0x140dbd400 base + manager remove(m_nType, m_nId)
    virtual void vfunc_5();                         // 5  0x140dbd440 base + manager (m_nType, m_nId)
    virtual void vfunc_7();                         // 7  0x140dbd480 {}
    virtual int vfunc_12();                         // 12 0x140dbdc80 return m_nType

    static int NextId();                            // 0x140dbd490 ++counter (0x143ac47c8), skipping 0

public:
    int m_nType;                                    // +0x30 param m_nType
    int m_nId;                                      // +0x34 NextId()
};
MS2_CHECK_SIZE(CPostEffect, 0x38);
MS2_CHECK_OFFSET(CPostEffect, m_nType, 0x30);
MS2_CHECK_OFFSET(CPostEffect, m_nId, 0x34);

// 0x50 bytes. vftable 0x142e379f0 (8 slots, ??_G 0x140dbdc40).
class CScreenEffectBase : public CPtred
{
public:
    CScreenEffectBase(int nType, const CPostEffectParam* pParam);   // 0x140dbd4c0
    virtual ~CScreenEffectBase();                                   // 0x140dbd650

    virtual void vfunc_1();                         // 1 0x140dbd680 start (time from 0x14086d260/0x141473280)
    virtual bool vfunc_2();                         // 2 0x140dbd710 update; false when stopped
    virtual void vfunc_3();                         // 3 0x140dbd9c0 request end (fade out)
    virtual void vfunc_4();                         // 4 0x140dbda80 stop: SetState(0, 0), m_bStopped = 1
    virtual int vfunc_5() = 0;                      // 5 pure (PostShimmerEffect: return 0x14 = type id)
    virtual bool vfunc_6(bool b);                   // 6 0x140dbdab0 if (!b) vfunc_7(m_nState, m_fAlpha); true
    virtual void vfunc_7(int nState, float fAlpha) = 0;  // 7 pure (apply)

    // @0x1409a8c30 (compiled into ?\applyeffect.cpp)
    int FUN_1409a8c30() const { return m_nType; }
    void SetState(int nState, float fAlpha);        // 0x140dbdb00

public:
    MS2_LAYOUT_FRIEND;
    int m_nType;                    // +0x18
    float m_fDuration;              // +0x1c param+0x2c (or fadeStart+fadeEnd+hold when fading)
    float m_fFadeStart;             // +0x20 param+0x4c
    float m_fFadeEnd;               // +0x24 param+0x50
    float m_fHold;                  // +0x28 param+0x54
    bool m_bLoop;                   // +0x2c param+0x30
    bool m_bEnding;                 // +0x2d
    bool m_bUseFade;                // +0x2e param+0x48
    bool m_bStopped;                // +0x2f
    bool m_bStarted;                // +0x30
    double m_dStartTime;            // +0x38
    int m_nState;                   // +0x40
    float m_fAlpha;                 // +0x44
    int m_nFadeStartInterp;         // +0x48 = 1
    int m_nFadeEndInterp;           // +0x4c = 1
};
MS2_CHECK_SIZE(CScreenEffectBase, 0x50);
MS2_CHECK_OFFSET(CScreenEffectBase, m_nType, 0x18);
MS2_CHECK_OFFSET(CScreenEffectBase, m_bLoop, 0x2c);
MS2_CHECK_OFFSET(CScreenEffectBase, m_bStarted, 0x30);
MS2_CHECK_OFFSET(CScreenEffectBase, m_dStartTime, 0x38);
MS2_CHECK_OFFSET(CScreenEffectBase, m_nFadeEndInterp, 0x4c);
