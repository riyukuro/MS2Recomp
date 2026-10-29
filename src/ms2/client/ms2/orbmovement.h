// orbmovement.h - the effect node movements (RTTI .?AVINodeMovement@@ 0x60 bytes vftable 0x142f45cd8, COrbMovement,
// CBirdMovement). A movement keeps a world transform that trails the target transform an EffectNode follows.
// Code owner: ?\orbmovement.cpp (0x1416252b0-0x1416263e0). NOTE: effectservice.h declares INodeMovement with the same
// size for EffectNode's smart pointer; include only one of the two headers per TU.
#pragma once

#include <NiTransform.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class INodeMovement : public CPtred
{
public:
    INodeMovement();                                            // 0x1416252b0
    INodeMovement(const INodeMovement& kSrc);                   // 0x141625360 (clone)
    virtual ~INodeMovement();                                   // 0x141626240, ??_G 0x1416262f0
    virtual INodeMovement* vfunc_1() const = 0;                 // slot 1: clone
    virtual NiTransform vfunc_2(double dTime, const NiTransform& kTarget) = 0;     // slot 2: step towards the target

    NiTransform FUN_141625430(double dTime, const NiTransform& kTarget);  // first call snaps, then steps
    void FUN_1416263a0(const NiTransform& kTarget);             // snap onto the target
    void FUN_1416256f0(float fT, const NiTransform& kFrom, const NiTransform& kTo, NiTransform& kOut);  // lerp/slerp
    void FUN_1416260f0(float fT, const NiTransform& kFrom, const NiTransform& kTo, NiTransform& kOut);  // slerp the rotation only

    NiTransform m_kTransform;                                   // +0x18 current transform (rotate +0x18, translate +0x3c)
    int m_bInitialized;                                         // +0x4c
    float m_fVelocity;                                          // +0x50
    float m_fMaxLength;                                         // +0x54
    float m_fMinLength;                                         // +0x58
    float m_fRate;                                              // +0x5c
};
MS2_CHECK_SIZE(INodeMovement, 0x60);
MS2_CHECK_OFFSET(INodeMovement, m_kTransform, 0x18);
MS2_CHECK_OFFSET(INodeMovement, m_bInitialized, 0x4c);

class COrbMovement : public INodeMovement
{
public:
    COrbMovement();                                             // 0x1416254a0
    COrbMovement(const COrbMovement& kSrc);                     // 0x1416254e0
    virtual ~COrbMovement();                                    // 0x141625520
    virtual INodeMovement* vfunc_1() const;                     // 0x141625550
    virtual NiTransform vfunc_2(double dTime, const NiTransform& kTarget);     // 0x1416255c0
};
MS2_CHECK_SIZE(COrbMovement, 0x60);

class CBirdMovement : public INodeMovement
{
public:
    CBirdMovement();                                            // 0x141625910
    CBirdMovement(const CBirdMovement& kSrc);                   // 0x141625960
    virtual ~CBirdMovement();                                   // 0x1416259a0
    virtual INodeMovement* vfunc_1() const;                     // 0x1416259d0
    virtual NiTransform vfunc_2(double dTime, const NiTransform& kTarget);     // 0x141625a40
};
MS2_CHECK_SIZE(CBirdMovement, 0x60);
