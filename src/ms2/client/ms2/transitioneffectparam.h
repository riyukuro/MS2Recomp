// transitioneffectparam.h - keyframed "transition" effects: TransitionData (one keyframe, NiRefObject),
// TransitionEffectParam (CEffectParam + keyframe list) and TransitionEffect (CEffect that walks the keyframes and
// hands each (from, to, t) to the pure slot 13). Base of the light effects (CLightEffectParam/CLightEffect with
// LightEffectTransitionData, ?\lighteffectparam.cpp) and of the chaos-light layer data (?\chaoslighttransitiondata.cpp).
// Owning unit: ?\transitioneffectparam.cpp (0x14185f1d0-0x14185ff70). Header name assumed from the unit path.
//
// HOW TO USE: derive the keyframe from TransitionData, the param from TransitionEffectParam (pass the effect type
// to the ctor, fill m_arrData in vfunc_1), the effect from TransitionEffect and implement vfunc_13.
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/effectparam.h"

// 0x20 bytes. vftable 0x142ea3300 (2 slots: ??_G 0x1410477f0, DeleteThis). ctor 0x141047100, implicit dtor
// 0x1410473f0 (both emitted in ?\chaoslighttransitiondata.cpp).
class TransitionData : public NiRefObject
{
public:
    TransitionData();
public:
    int m_nInterpolation;           // +0x10 0 linear, 1/2 eases (0x140cd8c20 / 0x1410af700), 3 sine
    float m_fDuration;              // +0x14
    float m_fStartTime;             // +0x18 offset from the effect start
};
MS2_CHECK_SIZE(TransitionData, 0x20);
MS2_CHECK_OFFSET(TransitionData, m_nInterpolation, 0x10);
typedef NiPointer<TransitionData> TransitionDataPtr;
typedef ATL::CAtlArray<TransitionDataPtr> TransitionDataArray;   // 0x20 bytes; Copy/SetCount/[] COMDATs in this unit

// 0x70 bytes. vftable 0x142f881b0 (8 slots, overrides none: an abstract-by-convention base). Implicit dtor
// 0x141043a00 (emitted in ?\uichaoslightdialog.cpp), ??_G 0x14185fbf0.
class TransitionEffectParam : public CEffectParam
{
public:
    explicit TransitionEffectParam(int nType);                  // 0x14185f1d0
    TransitionEffectParam& operator=(const TransitionEffectParam& o);   // 0x14185f230 (keyframes only)
public:
    int m_nLoopIndex;               // +0x48 keyframe the effect loops back to after the last (-1: no loop)
    TransitionDataArray m_arrData;  // +0x50
};
MS2_CHECK_SIZE(TransitionEffectParam, 0x70);
MS2_CHECK_OFFSET(TransitionEffectParam, m_nLoopIndex, 0x48);
MS2_CHECK_OFFSET(TransitionEffectParam, m_arrData, 0x50);

// 0x58 bytes. vftable 0x142f881f8 (13 slots; 12 and 13 pure). ??_G 0x14185fb90.
class TransitionEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x14185fdd0; ms_RTTI 0x143af00f8
public:
    TransitionEffect();                                         // 0x14185f290
    virtual ~TransitionEffect();                                // 0x14185f2e0 (calls vfunc_7 first)
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x14185f390 copy keyframes
    virtual bool vfunc_9();                                     // 9 0x14185f410 interpolate the current keyframe
    virtual void vfunc_13(TransitionData* pFrom, TransitionData* pTo, float fT) = 0;   // 13 apply

    void CopyKeyframes(const TransitionEffectParam* pParam);    // 0x14185f340 copy keyframes (same as vfunc_3)
    void AddKeyframe(TransitionData* pData);                  // 0x14185f670 append a keyframe
    bool FUN_14185f6f0(double dNow, unsigned int* pnIndex, float* pfT);   // 0x14185f6f0 keyframe + t at dNow
public:
    TransitionDataArray m_arrData;  // +0x30
    int m_nLoopIndex;               // +0x50
};
MS2_CHECK_SIZE(TransitionEffect, 0x58);
MS2_CHECK_OFFSET(TransitionEffect, m_arrData, 0x30);
MS2_CHECK_OFFSET(TransitionEffect, m_nLoopIndex, 0x50);
