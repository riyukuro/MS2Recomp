// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: a block of efd::Point3 / Point2 geometry
// helpers (parabola solve, ray cast with a ground probe, circle / sphere / ray intersections, disc sampling) that sits
// between mapmetamanager.cpp and the CMesh code at 0x14147af80.
// MS2-UNIT: unit_14147a2a0
// MS2-RANGE: 0x14147a2a0-0x14147af80 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_14147a2a0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <math.h>
// The statically linked CRT math calls go through the exe's IAT.
extern "C" float (__cdecl* __imp_cosf)(float);
extern "C" float (__cdecl* __imp_sinf)(float);
extern "C" float (__cdecl* __imp_tanf)(float);
#define cosf(x) __imp_cosf(x)
#define sinf(x) __imp_sinf(x)
#define tanf(x) __imp_tanf(x)
#include "ms2/client/ms2/physxhelper.h"
#include "hook/ms2hook.h"

// ---- exe callees ----
Unk_StreamPoint FUN_141192780(Unk_StreamPoint kFrom, Unk_StreamPoint kTo, bool bFlag);  // direction of the pair (flag 1)
float FUN_141403f20(Unk_StreamPoint kA, Unk_StreamPoint kB);                // horizontal distance (z cleared on the copies)
float FUN_140968970(float fValue);                                          // sqrtf wrapper
CPhysXHelper* FUN_1409f7ca0();
Unk_StreamPoint* FUN_14097faa0(Unk_StreamPoint* pDst, const Unk_NiPoint3* pSrc);    // NiPoint3 assignment
Unk_StreamPoint* FUN_14097fad0(Unk_StreamPoint* pDst, const Unk_NiPoint3* pSrc);    // NiPoint3 assignment
extern float FUN_1407680d0(void* pRandom);                                  // random float in [0, 1)
void FUN_140e69330(float fAngle, float* pSin, float* pCos);                 // sin and cos of the angle
extern Unk_StreamPoint DAT_143a08cf8;                                       // the up axis

// A 2D point and its NiPoint2 / efd::Point2 helpers.
struct Unk_Pt2 { float x, y; };
struct Unk_Pt2Pair { float x, y; };
struct Unk_Pt2Sub { Unk_Pt2 FUN_140a4e500(const Unk_Pt2& kRhs) const; }; // efd::Point2::operator-
struct Unk_Pt2Add { Unk_Pt2 FUN_141412ca0(const Unk_Pt2& kRhs) const; }; // efd::Point2::operator+
Unk_Pt2 FUN_140c90220(float fScalar, const Unk_Pt2& kPt);                   // efd::operator*(float, Point2)
void FUN_140db9c80(Unk_Pt2* pOut, const Unk_Pt2& kPt);                      // NiPoint2(const efd::Point2&)

// Launch parameters of a parabolic throw from a start to an end point at a given pitch angle (0x38 bytes).
struct Unk_Parabola
{
    float m_fTime;              // +0x00
    float m_fSpeed;             // +0x04
    float m_fGravity;           // +0x08
    Unk_StreamPoint m_ptEnd;    // +0x0c
    Unk_StreamPoint m_ptDir;    // +0x18
    Unk_StreamPoint m_ptStart;  // +0x24
    float m_fCos;               // +0x30
    float m_fSin;               // +0x34
    void FUN_14147a2a0(const Unk_StreamPoint& ptStart, const Unk_StreamPoint& ptEnd, float fAngle, float fGravity);
};
MS2_CHECK_SIZE(Unk_Parabola, 0x38);

float FUN_14147af60(float fAngle);
float FUN_14147aed0(const Unk_Pt2* pA, const Unk_Pt2* pB);
Unk_StreamPoint FUN_14147af10(Unk_StreamPoint kVec);

// @0x14147a2a0
// MS2-FUNCTIONAL: float temp slots and the *2.0f constant load differ
void Unk_Parabola::FUN_14147a2a0(const Unk_StreamPoint& ptStart, const Unk_StreamPoint& ptEnd, float fAngle, float fGravity)
{
    m_ptStart = ptStart;
    m_ptEnd = ptEnd;
    m_ptDir = FUN_141192780(ptStart, ptEnd, true);
    m_fGravity = fGravity;
    m_fCos = cosf(fAngle);
    m_fSin = sinf(fAngle);
    float fRise = ptEnd.z - ptStart.z;
    float fValue;
    float fRange = FUN_140966ea0(ptEnd, ptStart);
    float fTan = FUN_14147af60(fAngle);
    fValue = (fGravity * (fTan * fTan + 1.0f)) / ((fRange * fTan - fRise) * 2.0f);
    if (0.0f <= fValue)
    {
        fValue = FUN_140968970(fValue);
        m_fSpeed = fRange * fValue;
        m_fTime = fRange / (m_fCos * m_fSpeed);
    }
    else
    {
        m_fSpeed = 0.0f;
        m_fTime = 0.0f;
    }
}

// @0x14147a500
// MS2-FUNCTIONAL: call-temp spill layout of the Point3 chain differs
// Casts from the start towards the end (horizontal distance), moving the start along or stopping at the hit; with bProbe
// it then drops a ray along -up and writes the hit point lifted by 5 units.
int FUN_14147a500(Unk_StreamPoint* pOut, const Unk_StreamPoint* pStart, const Unk_StreamPoint* pEnd, char bProbe, float fProbeLen, const NxGroupsMask* pMask)
{
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = *pStart;
    Unk_NiPoint3 kDelta(pEnd->FUN_140965c40(*pStart));
    kInfo.m_dir = FUN_14147af10(reinterpret_cast<const Unk_StreamPoint&>(kDelta));
    kInfo.m_groups = 0x389;
    float fDist = FUN_141403f20(*pStart, *pEnd);
    if (!FUN_1409f7ca0()->FUN_1416892f0(&kInfo, pMask))
    {
        kInfo.m_origin = pStart->FUN_14097fd50(kInfo.m_dir.FUN_14097fc90(fDist));
    }
    else
    {
        Unk_StreamPoint kFrom = *pStart;
        float fHit = FUN_140966ea0(kFrom, kInfo.m_hitPoint);
        if (fDist <= fHit)
        {
            kInfo.m_origin = pStart->FUN_14097fd50(kInfo.m_dir.FUN_14097fc90(fDist));
        }
        else
        {
            if (bProbe == 0)
            {
                Unk_NiPoint3 kPoint(kInfo.m_hitPoint);
                FUN_14097faa0(pOut, &kPoint);
                return 1;
            }
            kInfo.m_origin = kInfo.m_hitPoint.FUN_140965c40(kInfo.m_dir.FUN_14097fc90(30.0f));
        }
    }
    if (bProbe != 0)
    {
        kInfo.m_dir = DAT_143a08cf8.FUN_1409f7960();
        kInfo.m_maxDist = fProbeLen;
        if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, pMask))
        {
            Unk_NiPoint3 kPoint(kInfo.m_hitPoint);
            kPoint.z = kPoint.z + 5.0f;
            FUN_14097fad0(pOut, &kPoint);
            return 1;
        }
    }
    return 0;
}

// @0x14147a850
// MS2-FUNCTIONAL: Point2 temp layout differs
// Circle (centre kCenter, radius fRadius) against the line kOrigin + t * kDir; writes both crossing points.
bool FUN_14147a850(const Unk_Pt2& kOrigin, const Unk_Pt2& kDir, const Unk_Pt2& kCenter, float fRadius, Unk_Pt2* pHit0, Unk_Pt2* pHit1)
{
    Unk_Pt2 kLocal;
    FUN_140db9c80(&kLocal, reinterpret_cast<const Unk_Pt2Sub*>(&kOrigin)->FUN_140a4e500(kCenter));
    float fA = FUN_14147aed0(&kDir, &kDir);
    float fB = FUN_14147aed0(&kLocal, &kDir);
    float fC = FUN_14147aed0(&kLocal, &kLocal);
    float fDisc = fB * fB - fA * (fC - fRadius * fRadius);
    if (0.0f <= fDisc)
    {
        float fRoot = FUN_140968970(fDisc);
        float fT0 = (-fB - fRoot) * (1.0f / fA);
        float fT1 = (-fB + fRoot) * (1.0f / fA);
        Unk_Pt2 kHit;
        FUN_140db9c80(&kHit, reinterpret_cast<const Unk_Pt2Add*>(&kOrigin)->FUN_141412ca0(FUN_140c90220(fT0, kDir)));
        *pHit0 = kHit;
        FUN_140db9c80(&kHit, reinterpret_cast<const Unk_Pt2Add*>(&kOrigin)->FUN_141412ca0(FUN_140c90220(fT1, kDir)));
        *pHit1 = kHit;
    }
    return 0.0f <= fDisc;
}

// @0x14147aa60
// MS2-FUNCTIONAL: Point3 temp layout and the NiPoint3 conversion copies differ
// Ray against a sphere; writes the first hit point (or the closest point on the sphere when the ray misses) to pHit.
char FUN_14147aa60(const Unk_StreamPoint& kOrigin, const Unk_StreamPoint& kDir, const Unk_StreamPoint& kCenter, float fRadius, Unk_StreamPoint* pHit)
{
    Unk_StreamPoint kUnit = kDir;
    kUnit.FUN_140968990();
    Unk_NiPoint3 kToCenter(kCenter.FUN_140965c40(kOrigin));
    const Unk_StreamPoint& kToC = reinterpret_cast<const Unk_StreamPoint&>(kToCenter);
    float fProj = kToC.FUN_140a00f20(kUnit);
    float fSqr = kToC.FUN_140a00f20(kToC);
    float fRR = fRadius * fRadius;
    if (0.0f <= fProj || fSqr <= fRR)
    {
        float fPerp = fSqr - fProj * fProj;
        char bHit;
        if (fPerp <= fRR)
        {
            float fHalf = FUN_140968970(fRR - fPerp);
            if (fSqr <= fRR)
                fProj = fProj + fHalf;
            else
                fProj = fProj - fHalf;
            Unk_NiPoint3 kPoint(kOrigin.FUN_14097fd50(FUN_1409ab5c0(fProj, kUnit)));
            FUN_14097faa0(pHit, &kPoint);
            bHit = 1;
        }
        else
        {
            bHit = 0;
            Unk_NiPoint3 kNear(kOrigin.FUN_14097fd50(FUN_1409ab5c0(fProj, kUnit)));
            Unk_NiPoint3 kNormal(kCenter.FUN_140965c40(reinterpret_cast<const Unk_StreamPoint&>(kNear)));
            reinterpret_cast<Unk_StreamPoint&>(kNormal).FUN_140968990();
            float fDepth = FUN_140968970(fPerp);
            Unk_NiPoint3 kPoint(reinterpret_cast<const Unk_StreamPoint&>(kNear).FUN_14097fd50(
                reinterpret_cast<const Unk_StreamPoint&>(kNormal).FUN_14097fc90(fDepth - fRadius)));
            FUN_14097faa0(pHit, &kPoint);
        }
        return bHit;
    }
    return 0;
}

// @0x14147ad10
// MS2-FUNCTIONAL: conversion temp layout differs
// True when the ray (unit direction kDir) from kOrigin passes within fRadius of kCenter.
bool FUN_14147ad10(const Unk_StreamPoint& kOrigin, const Unk_StreamPoint& kDir, const Unk_StreamPoint& kCenter, float fRadius)
{
    Unk_StreamPoint kUnit = kDir;
    kUnit.FUN_140968990();
    Unk_NiPoint3 kToCenter(kCenter.FUN_140965c40(kOrigin));
    const Unk_StreamPoint& kToC = reinterpret_cast<const Unk_StreamPoint&>(kToCenter);
    float fProj = kToC.FUN_140a00f20(kUnit);
    float fSqr = kToC.FUN_140a00f20(kToC);
    if (0.0f <= fProj || fSqr <= fRadius * fRadius)
        return fSqr - fProj * fProj <= fRadius * fRadius;
    return false;
}

// @0x14147ae30
// MS2-FUNCTIONAL: float temp spills differ
// A random point of the disc of radius fRadius (uniform by area): angle from one draw, radius from the root of the next.
void FUN_14147ae30(void* pUnused0, void* pUnused1, float fRadius, float* pX, float* pY, void* pRandom)
{
    float fAngle = FUN_1407680d0(pRandom);
    float fRoot = FUN_140968970(FUN_1407680d0(pRandom));
    FUN_140e69330(fAngle * 6.2831855f, pY, pX);
    *pX = *pX * fRadius * fRoot;
    *pY = *pY * fRadius * fRoot;
}

// @0x14147aed0
float FUN_14147aed0(const Unk_Pt2* pA, const Unk_Pt2* pB)
{
    return pA->x * pB->x + pA->y * pB->y;
}

// @0x14147af10
// The vector with z cleared, normalised.
Unk_StreamPoint FUN_14147af10(Unk_StreamPoint kVec)
{
    kVec.z = 0.0f;
    kVec.FUN_140968990();
    return kVec;
}

// @0x14147af60
float FUN_14147af60(float fAngle)
{
    return tanf(fAngle);
}
