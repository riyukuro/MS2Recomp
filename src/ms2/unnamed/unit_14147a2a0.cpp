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
#include <efd/Point3.h>
#include <NiPoint3.h>     // C3: NiPoint3 assignment (was FUN_14097faa0/FUN_14097fad0)
#include <NiPoint2.h>     // C3: the circle crossing points
#include <efd/EEMath.h>   // C3: efd::Sqrt was FUN_140968970
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
Vector3 FUN_141192780(Vector3 kFrom, Vector3 kTo, bool bFlag);  // direction of the pair (flag 1)
float FUN_141403f20(NiPoint3 kA, NiPoint3 kB);                // horizontal distance (z cleared on the copies)
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0
float FUN_1407680d0(class Unk_Random*);   // C3: was FUN_1407680d0
void FUN_140e69330(float fAngle, float* pSin, float* pCos);                 // sin and cos of the angle
#define DAT_143a08cf8 (*(Vector3*)&efd::Point3::UNIT_Z)          // C3: was extern Vector3 DAT_143a08cf8

// A 2D point and its NiPoint2 / efd::Point2 helpers.
struct Unk_Pt2 { float x, y; };
#define AsPoint2(pt) reinterpret_cast<const efd::Point2&>(pt)

// Launch parameters of a parabolic throw from a start to an end point at a given pitch angle (0x38 bytes).
struct Unk_Parabola
{
    float m_fTime;              // +0x00
    float m_fSpeed;             // +0x04
    float m_fGravity;           // +0x08
    Vector3 m_ptEnd;    // +0x0c
    Vector3 m_ptDir;    // +0x18
    Vector3 m_ptStart;  // +0x24
    float m_fCos;               // +0x30
    float m_fSin;               // +0x34
    void FUN_14147a2a0(const Vector3& ptStart, const Vector3& ptEnd, float fAngle, float fGravity);
};
MS2_CHECK_SIZE(Unk_Parabola, 0x38);

float FUN_14147af60(float fAngle);
float FUN_14147aed0(const Unk_Pt2* pA, const Unk_Pt2* pB);
Vector3 FUN_14147af10(Unk_NiPoint3 kVec);

// @0x14147a2a0
void Unk_Parabola::FUN_14147a2a0(const Vector3& ptStart, const Vector3& ptEnd, float fAngle, float fGravity)
{
    m_ptStart = ptStart;
    m_ptEnd = ptEnd;
    m_ptDir = FUN_141192780(ptStart, ptEnd, true);
    m_fGravity = fGravity;
    m_fCos = cosf(fAngle);
    m_fSin = sinf(fAngle);
    float fRange = FUN_140966ea0(ptEnd, ptStart);
    float fRise = ptEnd.z - ptStart.z;
    float fTan = FUN_14147af60(fAngle);
    float fValue = fGravity * (fTan * fTan + 1.0f) / (2.0f * (fRange * fTan - fRise));
    if (fValue < 0.0f)
    {
        m_fSpeed = 0.0f;
        m_fTime = 0.0f;
    }
    else
    {
        m_fSpeed = fRange * efd::Sqrt(fValue);
        m_fTime = fRange / (m_fCos * m_fSpeed);
    }
}

// @0x14147a500
// Casts from the start towards the end (horizontal distance), moving the start along or stopping at the hit; with bProbe
// it then drops a ray along -up and writes the hit point lifted by 5 units.
bool FUN_14147a500(Vector3* pOut, Vector3 kStart, Vector3 kEnd, bool bProbe, float fProbeLen, const NxGroupsMask* pMask)
{
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = kStart;
    kInfo.m_dir = FUN_14147af10(kEnd.FUN_140965c40(kStart));
    kInfo.m_groups = 0x389;
    float fDist = FUN_141403f20(reinterpret_cast<NiPoint3&>(kStart), reinterpret_cast<NiPoint3&>(kEnd));
    if (((class CPhysXHelper*)FUN_1409f7ca0())->CastRay(&kInfo, pMask))
    {
        float fHit = FUN_140966ea0(Vector3(kStart), kInfo.m_hitPoint);
        if (fHit < fDist)
        {
            if (!bProbe)
            {
                Unk_NiPoint3 kPoint(kInfo.m_hitPoint);
                *reinterpret_cast<NiPoint3*>(pOut) = static_cast<NiPoint3&&>(*const_cast<NiPoint3*>(reinterpret_cast<const NiPoint3*>(&static_cast<const Unk_NiPoint3&>(kPoint))));
                return true;
            }
            kInfo.m_origin = kInfo.m_hitPoint.FUN_140965c40(kInfo.m_dir.FUN_14097fc90(30.0f));
        }
        else
        {
            kInfo.m_origin = kStart.FUN_14097fd50(kInfo.m_dir.FUN_14097fc90(fDist));
        }
    }
    else
    {
        kInfo.m_origin = kStart.FUN_14097fd50(kInfo.m_dir.FUN_14097fc90(fDist));
    }
    if (bProbe)
    {
        kInfo.m_dir = DAT_143a08cf8.FUN_1409f7960();
        kInfo.m_maxDist = fProbeLen;
        if (((class CPhysXHelper*)FUN_1409f7ca0())->CastRay(&kInfo, pMask))
        {
            Unk_NiPoint3 kPoint(kInfo.m_hitPoint);
            kPoint.z = kPoint.z + 5.0f;
            *reinterpret_cast<NiPoint3*>(pOut) = *reinterpret_cast<const NiPoint3*>(&kPoint);
            return true;
        }
    }
    return false;
}

// @0x14147a850
// Circle (centre kCenter, radius fRadius) against the line kOrigin + t * kDir; writes both crossing points.
bool FUN_14147a850(const Unk_Pt2& kOrigin, const Unk_Pt2& kDir, const Unk_Pt2& kCenter, float fRadius, Unk_Pt2* pHit0, Unk_Pt2* pHit1)
{
    NiPoint2 kLocal(AsPoint2(kOrigin) - AsPoint2(kCenter));
    float fA = FUN_14147aed0(&kDir, &kDir);
    float fB = FUN_14147aed0(reinterpret_cast<const Unk_Pt2*>(&kLocal), &kDir);
    float fC = FUN_14147aed0(reinterpret_cast<const Unk_Pt2*>(&kLocal), reinterpret_cast<const Unk_Pt2*>(&kLocal)) - fRadius * fRadius;
    float fDisc = fB * fB - fA * fC;
    if (fDisc < 0.0f)
        return false;
    float fRoot = efd::Sqrt(fDisc);
    float fInvA = 1.0f / fA;
    float afT[2];
    afT[0] = (-fB - fRoot) * fInvA;
    afT[1] = (-fB + fRoot) * fInvA;
    NiPoint2 kHit0(AsPoint2(kOrigin) + afT[0] * AsPoint2(kDir));
    *pHit0 = reinterpret_cast<const Unk_Pt2&>(kHit0);
    NiPoint2 kHit1(AsPoint2(kOrigin) + afT[1] * AsPoint2(kDir));
    *pHit1 = reinterpret_cast<const Unk_Pt2&>(kHit1);
    return true;
}

// @0x14147aa60
// Ray against a sphere; writes the first hit point (or the closest point on the sphere when the ray misses) to pHit.
char FUN_14147aa60(const Vector3& kOrigin, const Vector3& kDir, const Vector3& kCenter, float fRadius, Vector3* pHit)
{
    char bHit = 0;
    Vector3 kUnit = kDir;
    kUnit.FUN_140968990();
    Unk_NiPoint3 kToCenter(kCenter.FUN_140965c40(kOrigin));
    float fProj = reinterpret_cast<const efd::Point3&>(kToCenter).Dot(reinterpret_cast<const efd::Point3&>(kUnit));
    float fProjSqr = fProj * fProj;
    float fSqr = reinterpret_cast<const efd::Point3&>(kToCenter).Dot(reinterpret_cast<const efd::Point3&>(kToCenter));
    float fRR = fRadius * fRadius;
    if (fProj < 0.0f && fSqr > fRR)
        return 0;
    float fPerp = fSqr - fProjSqr;
    if (fPerp > fRR)
    {
        bHit = 0;
        Unk_NiPoint3 kNear(kOrigin.FUN_14097fd50(FUN_1409ab5c0(fProj, kUnit)));
        Unk_NiPoint3 kNormal(kCenter.FUN_140965c40(reinterpret_cast<const Vector3&>(kNear)));
        reinterpret_cast<Vector3&>(kNormal).FUN_140968990();
        *reinterpret_cast<NiPoint3*>(pHit) = static_cast<NiPoint3&&>(*const_cast<NiPoint3*>(reinterpret_cast<const NiPoint3*>(&static_cast<const Unk_NiPoint3&>(reinterpret_cast<const Vector3&>(kNear).FUN_14097fd50(
            reinterpret_cast<const Vector3&>(kNormal).FUN_14097fc90(efd::Sqrt(fPerp) - fRadius))))));
    }
    else
    {
        float fHalf = efd::Sqrt(fRR - fPerp);
        float fT = 0.0f;
        if (fSqr > fRR)
            fT = fProj - fHalf;
        else
            fT = fProj + fHalf;
        *reinterpret_cast<NiPoint3*>(pHit) = static_cast<NiPoint3&&>(*const_cast<NiPoint3*>(reinterpret_cast<const NiPoint3*>(&static_cast<const Unk_NiPoint3&>(kOrigin.FUN_14097fd50(FUN_1409ab5c0(fT, kUnit))))));
        bHit = 1;
    }
    return bHit;
}

// @0x14147ad10
// True when the ray (unit direction kDir) from kOrigin passes within fRadius of kCenter.
bool FUN_14147ad10(const Vector3& kOrigin, const Vector3& kDir, const Vector3& kCenter, float fRadius)
{
    Vector3 kUnit = kDir;
    kUnit.FUN_140968990();
    Unk_NiPoint3 kToCenter(kCenter.FUN_140965c40(kOrigin));
    float fProj = reinterpret_cast<const efd::Point3&>(kToCenter).Dot(reinterpret_cast<const efd::Point3&>(kUnit));
    float fProjSqr = fProj * fProj;
    float fSqr = reinterpret_cast<const efd::Point3&>(kToCenter).Dot(reinterpret_cast<const efd::Point3&>(kToCenter));
    float fRadiusSqr = fRadius * fRadius;
    if (fProj < 0.0f && fSqr > fRadiusSqr)
        return false;
    float fDistSqr = fSqr - fProjSqr;
    return fDistSqr <= fRadiusSqr;
}

// @0x14147ae30
// A random point of the disc of radius fRadius (uniform by area): angle from one draw, radius from the root of the next.
void FUN_14147ae30(float fUnused0, float fUnused1, float fRadius, float* pX, float* pY, void* pRandom)
{
    float fAngle = FUN_1407680d0((class Unk_Random*)(pRandom)) * 6.2831855f;
    float fDist = fRadius * efd::Sqrt(FUN_1407680d0((class Unk_Random*)(pRandom)));
    FUN_140e69330(fAngle, pY, pX);
    *pX = *pX * fDist;
    *pY = *pY * fDist;
}

// @0x14147aed0
float FUN_14147aed0(const Unk_Pt2* pA, const Unk_Pt2* pB)
{
    return pA->x * pB->x + pA->y * pB->y;
}

// @0x14147af10
// The vector with z cleared, normalised.
Vector3 FUN_14147af10(Unk_NiPoint3 kVec)
{
    kVec.z = 0.0f;
    reinterpret_cast<Vector3&>(kVec).FUN_140968990();
    return reinterpret_cast<Vector3&>(kVec);
}

// @0x14147af60
float FUN_14147af60(float fAngle)
{
    return tanf(fAngle);
}
