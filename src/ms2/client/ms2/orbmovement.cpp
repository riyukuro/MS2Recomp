// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Effect node movements: INodeMovement base, COrbMovement
// (eases the node onto the target by the distance) and CBirdMovement (turns the node towards its flight direction).
// MS2-UNIT: ?\orbmovement.cpp
// MS2-RANGE: 0x1416252b0-0x1416263e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\orbmovement.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "orbmovement.h"
#include <efd/Quaternion.h>
#include <NiMath.h>
#include <NiQuaternion.h>
#include "ms2/ms2recover.h"

float FUN_14059d930(float f);                                   // fabsf

// @0x1416252b0
INodeMovement::INodeMovement() : CPtred()
{
    m_bInitialized = 0;
    m_fVelocity = 300.0f;
    m_fMaxLength = 500.0f;
    m_fMinLength = 1.0f;
    m_fRate = 0.0003f;
}

// @0x141625360
INodeMovement::INodeMovement(const INodeMovement& kSrc) : CPtred()
{
    m_fMaxLength = kSrc.m_fMaxLength;
    m_fMinLength = kSrc.m_fMinLength;
    m_fRate = kSrc.m_fRate;
    m_kTransform = kSrc.m_kTransform;
    m_fVelocity = kSrc.m_fVelocity;
    m_bInitialized = 0;
}

// @0x141625430
NiTransform INodeMovement::FUN_141625430(double dTime, const NiTransform& kTarget)
{
    if (m_bInitialized == 0)
    {
        FUN_1416263a0(kTarget);
        m_bInitialized = 1;
    }
    return vfunc_2(dTime, kTarget);
}

// @0x1416254a0
COrbMovement::COrbMovement()
{
}

// @0x1416254e0
COrbMovement::COrbMovement(const COrbMovement& kSrc) : INodeMovement(kSrc)
{
}

// @0x141625520
COrbMovement::~COrbMovement()
{
}

// @0x141625550
INodeMovement* COrbMovement::vfunc_1() const
{
    return new COrbMovement(*this);
}

// @0x1416255c0
NiTransform COrbMovement::vfunc_2(double dTime, const NiTransform& kTarget)
{
    NiPoint3 kDelta = kTarget.m_Translate - m_kTransform.m_Translate;
    float fLength = kDelta.Length();
    if (m_fMaxLength <= fLength || fLength <= m_fMinLength)
        FUN_1416263a0(kTarget);
    else
    {
        float fDelta = (float)dTime;
        FUN_1416256f0(fLength * m_fRate * fDelta, m_kTransform, kTarget, m_kTransform);
    }
    return m_kTransform;
}

// @0x1416256f0
void INodeMovement::FUN_1416256f0(float fT, const NiTransform& kFrom, const NiTransform& kTo, NiTransform& kOut)
{
    if (fT <= 0.0f)
    {
        kOut = kFrom;
    }
    else if (fT >= 1.0f)
    {
        kOut = kTo;
    }
    else
    {
        kOut.m_fScale = kFrom.m_fScale + fT * (kTo.m_fScale - kFrom.m_fScale);
        kOut.m_Translate = kFrom.m_Translate + fT * (kTo.m_Translate - kFrom.m_Translate);
        NiQuaternion kQ0;
        kQ0.FromRotation(kFrom.m_Rotate);
        NiQuaternion kQ1;
        kQ1.FromRotation(kTo.m_Rotate);
        if (efd::Quaternion::Dot(kQ0, kQ1) < 0.0f)
            kQ1 = -kQ1;
        NiQuaternion kQ = efd::Quaternion::Slerp(fT, kQ0, kQ1);
        kQ.ToRotation(kOut.m_Rotate);
    }
}

// @0x141625910
CBirdMovement::CBirdMovement()
{
    m_fMaxLength = 300.0f;
}

// @0x141625960
CBirdMovement::CBirdMovement(const CBirdMovement& kSrc) : INodeMovement(kSrc)
{
}

// @0x1416259a0
CBirdMovement::~CBirdMovement()
{
}

// @0x1416259d0
INodeMovement* CBirdMovement::vfunc_1() const
{
    return new CBirdMovement(*this);
}

// @0x141625a40
NiTransform CBirdMovement::vfunc_2(double dTime, const NiTransform& kTarget)
{
    if (m_bInitialized != 0)
    {
        float fTurn = 0.33f;
        float fSlope = 0.8f;
        efd::Point3 kDir = kTarget.m_Translate - m_kTransform.m_Translate;
        efd::Point3 kUp = -(kTarget.m_Translate - m_kTransform.m_Translate);
        kUp.z = kUp.z * 0.3f;
        kUp.Unitize();
        if (FUN_14059d930(kUp.x) < 0.001f)
            kUp.x = 0.0f;
        if (FUN_14059d930(kUp.y) < 0.001f)
            kUp.y = 0.0f;
        if (FUN_14059d930(kUp.z) < 0.001f)
            kUp.z = 0.0f;
        if (0.999f < FUN_14059d930(kUp.x))
        {
            if (kUp.x > 0.0f)
                kUp.x = 1.0f;
            else
                kUp.x = -1.0f;
        }
        if (0.999f < FUN_14059d930(kUp.y))
        {
            if (kUp.y > 0.0f)
                kUp.y = 1.0f;
            else
                kUp.y = -1.0f;
        }
        if (0.999f < FUN_14059d930(kUp.z))
        {
            if (kUp.z > 0.0f)
                kUp.z = 1.0f;
            else
                kUp.z = -1.0f;
        }
        float fDist = kDir.Unitize();
        float fOver;
        if (fDist - m_fMaxLength > 0.0f)
            fOver = fDist - m_fMaxLength;
        else
            fOver = 0.0f;
        float fExcess = fOver;
        float fRatio = fExcess / m_fMaxLength;
        float fSpeed = m_fVelocity + m_fVelocity * fRatio * m_fRate;
        float fTime = fDist / fSpeed;
        if ((double)fTime <= dTime)
        {
            m_kTransform.m_Translate = kTarget.m_Translate;
            FUN_1416260f0(fTurn, m_kTransform, kTarget, m_kTransform);
            return m_kTransform;
        }
        if (kUp == efd::Point3::ZERO)
        {
            kTarget.m_Rotate.GetCol(1, kUp);
            kUp = -kUp;
            kUp.Unitize();
        }
        efd::Point3 kSide = efd::Point3::ZERO;
        efd::Matrix3 kTilt;
        kTilt.MakeIdentity();
        if (kUp == efd::Point3::UNIT_Z)
        {
            kTarget.m_Rotate.GetCol(0, kSide);
            kTilt.MakeXRotation(1.5707964f * fSlope);
        }
        else if (kUp == -efd::Point3::UNIT_Z)
        {
            kTarget.m_Rotate.GetCol(0, kSide);
            kTilt.MakeXRotation(1.5707964f * -fSlope);
        }
        else
        {
            kSide = kUp.UnitCross(efd::Point3::UNIT_Z);
        }
        efd::Point3 kFront = kSide.UnitCross(kUp);
        efd::Matrix3 kBasis;
        kBasis.SetCol(0, kSide);
        kBasis.SetCol(1, kUp);
        kBasis.SetCol(2, kFront);
        NiTransform kGoal;
        kGoal.m_Rotate = kBasis * kTilt;
        FUN_1416260f0(fTurn, m_kTransform, kGoal, m_kTransform);
        m_kTransform.m_Translate = m_kTransform.m_Translate + kDir * fSpeed * (float)dTime;
    }
    else
    {
        FUN_1416263a0(kTarget);
        m_bInitialized = 1;
    }
    return m_kTransform;
}

// @0x1416260f0
void INodeMovement::FUN_1416260f0(float fT, const NiTransform& kFrom, const NiTransform& kTo, NiTransform& kOut)
{
    if (fT <= 0.0f)
    {
        kOut = kFrom;
    }
    else if (fT >= 1.0f)
    {
        kOut = kTo;
    }
    else
    {
        NiQuaternion kQ0;
        kQ0.FromRotation(kFrom.m_Rotate);
        NiQuaternion kQ1;
        kQ1.FromRotation(kTo.m_Rotate);
        if (efd::Quaternion::Dot(kQ0, kQ1) < 0.0f)
            kQ1 = -kQ1;
        NiQuaternion kQ = efd::Quaternion::Slerp(fT, kQ0, kQ1);
        kQ.ToRotation(kOut.m_Rotate);
    }
}

// @0x141626240
INodeMovement::~INodeMovement()
{
}

// @0x1416263a0
void INodeMovement::FUN_1416263a0(const NiTransform& kTarget)
{
    m_bInitialized = 1;
    m_kTransform = kTarget;
}
