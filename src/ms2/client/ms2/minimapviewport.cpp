// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See minimapviewport.h. The exe's copies of the
// efd::Point3 / efd::Matrix3 helpers this unit calls are shared COMDATs owned by other objs, so they are declared as
// free functions here (a member's thiscall is the same calling convention as a first reference parameter) and the
// hook DLL binds them to the exe.
// MS2-UNIT: ?\minimapviewport.cpp
// MS2-FUNCTIONAL: MinimapViewport::FUN_141486450 (Project) differs only in the /Od argument setup of the FUN_141486550
// call (the exe materializes &kPt.y into rcx and moves it to r9); every other instruction matches.
// MS2-RANGE: 0x1414856d0-0x141486df0 .text$mn
// MS2-PIN: ??_GMinimapViewport@@UEAAPEAXI@Z 0x141486cd0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "minimapviewport.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------
// The world service (0x1403ed2d0); the client field data it hands out (0x141bd30a0).
class Unk_MvWorld
{
public:
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();
};
Unk_MvWorld* FUN_1403ed2d0();

// efd::Point3 and efd::Matrix3 helpers (all out of line in the exe).
float FUN_140a00f20(const Unk_GVec3& kA, const Unk_GVec3& kB);   // efd::Point3::Dot
float FUN_140968990(Unk_GVec3& kVec);                            // efd::Point3::Unitize (returns the old length)
float FUN_140a38cd0(float fValue);                               // efd::Abs
float FUN_140a0fda0(float fA, float fB);                         // the larger of the two floats
void FUN_1409f72e0(Unk_MvMatrix3& kMatrix);                      // efd::Matrix3::Matrix3()

static const float k_fPiOver180 = 3.1415927f / 180.0f;

// ---- MinimapViewport ----------------------------------------------------------------------------------------------------
// @0x1414856d0
MinimapViewport::MinimapViewport()
    : m_kFrustum(false)
    , m_rcImage(0.0f, 0.0f, 0.0f, 0.0f)
    , m_rcScreen(0.0f, 0.0f, 0.0f, 0.0f)
{
    FUN_1414863e0();
}

// MS2-FUNCTIONAL: exe copies m_vecCamRot twice with rep movsb (local + by-value arg: a trivially copyable point,
//   NiPoint3/efd::Point3) while Unk_GVec3 (fielddatacli.h) declares a copy ctor 0x14027dcf0 -> 2 extra calls and a
//   different local slot order; needs the camera-vector type recovery in fielddatacli.h
// @0x141485770
unsigned MinimapViewport::FUN_141485770(int nScale)
{
    FUN_1414863e0();
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField ? true : false)
    {
        if (spField->m_spMinimap ? true : false)
        {
            MS2Ptr<CMinimap> spMinimap = spField->m_spMinimap;
            m_kFrustum = spMinimap->m_frustum;
            m_rcImage = spMinimap->m_rcImage;
            m_rcScreen = spMinimap->m_rcScreen;

            Unk_GVec3 kAxisX(0.0f, 0.0f, 0.0f);
            Unk_GVec3 kAxisY(0.0f, 0.0f, 0.0f);
            Unk_GVec3 kAxisZ(0.0f, 0.0f, 0.0f);
            Unk_GVec3 kRot = spMinimap->m_vecCamRot;
            FUN_141486a20(kRot, kAxisX, kAxisY, kAxisZ);
            FUN_141485a50(spMinimap->m_vecCamPos, kAxisX, kAxisY, kAxisZ);

            if (FUN_141486d90(spMinimap->m_rcImage) <= 0.0f)
                return 0;
            if (nScale > 0)
                m_fScale = (float)nScale / FUN_141486d90(spMinimap->m_rcImage);
                return 1;
        }
    }
    return 0;
}

// @0x141485a50
void MinimapViewport::FUN_141485a50(const Unk_GVec3& kCamPos, const Unk_GVec3& kAxisX, const Unk_GVec3& kAxisY,
                                    const Unk_GVec3& kAxisZ)
{
    float fDotX = FUN_140a00f20(kAxisX, kCamPos);
    float fDotZ = FUN_140a00f20(kAxisZ, kCamPos);
    float fDotY = -FUN_140a00f20(kAxisY, kCamPos);

    float fSumLR = m_kFrustum.r + m_kFrustum.l;
    float fSumTB = m_kFrustum.t + m_kFrustum.b;
    float fInvLR = 1.0f / (m_kFrustum.r - m_kFrustum.l);
    float fInvTB = 1.0f / (m_kFrustum.t - m_kFrustum.b);
    float fInvNF = 1.0f / (m_kFrustum.f - m_kFrustum.n);

    if (m_kFrustum.ortho)
    {
        float fX = fInvLR * 2.0f;
        float fZ = fInvTB * 2.0f;
        m_afMatrix[0][0] = fX * kAxisX.x;
        m_afMatrix[0][1] = fX * kAxisX.y;
        m_afMatrix[0][2] = fX * kAxisX.z;
        m_afMatrix[0][3] = fX * -fDotX + fSumLR * fInvLR;
        m_afMatrix[1][0] = fZ * kAxisZ.x;
        m_afMatrix[1][1] = fZ * kAxisZ.y;
        m_afMatrix[1][2] = fZ * kAxisZ.z;
        m_afMatrix[1][3] = fZ * -fDotZ + fSumTB * fInvTB;
        m_afMatrix[2][0] = fInvNF * kAxisY.x;
        m_afMatrix[2][1] = fInvNF * kAxisY.y;
        m_afMatrix[2][2] = fInvNF * kAxisY.z;
        m_afMatrix[2][3] = fInvNF * fDotY + -m_kFrustum.n * fInvNF;
        m_afMatrix[3][0] = 0.0f;
        m_afMatrix[3][1] = 0.0f;
        m_afMatrix[3][2] = 0.0f;
        m_afMatrix[3][3] = 1.0f;
    }
    else
    {
        float fX = fInvLR * 2.0f;
        float fXV = -fSumLR * fInvLR;
        float fZ = fInvTB * 2.0f;
        float fZV = -fSumTB * fInvTB;
        float fNF = m_kFrustum.n * fInvNF;
        m_afMatrix[0][0] = fX * kAxisX.x + fXV * kAxisY.x;
        m_afMatrix[0][1] = fX * kAxisX.y + fXV * kAxisY.y;
        m_afMatrix[0][2] = fX * kAxisX.z + fXV * kAxisY.z;
        m_afMatrix[0][3] = fX * -fDotX + fXV * fDotY;
        m_afMatrix[1][0] = fZ * kAxisZ.x + fZV * kAxisY.x;
        m_afMatrix[1][1] = fZ * kAxisZ.y + fZV * kAxisY.y;
        m_afMatrix[1][2] = fZ * kAxisZ.z + fZV * kAxisY.z;
        m_afMatrix[1][3] = fZ * -fDotZ + fZV * fDotY;
        m_afMatrix[2][0] = fNF * kAxisY.x;
        m_afMatrix[2][1] = fNF * kAxisY.y;
        m_afMatrix[2][2] = fNF * kAxisY.z;
        m_afMatrix[2][3] = fNF * fDotY + -m_kFrustum.n * fNF;
        m_afMatrix[3][0] = kAxisY.x;
        m_afMatrix[3][1] = kAxisY.y;
        m_afMatrix[3][2] = kAxisY.z;
        m_afMatrix[3][3] = fDotY;
    }
}

// @0x1414863e0
void MinimapViewport::FUN_1414863e0()
{
    m_fScale = 1.0f;
}

// @0x141486410
void MinimapViewport::FUN_141486410(const Unk_GVec3& kPos, Unk_GVec3& kOut)
{
    FUN_141486450(kPos, kOut, m_fScale);
}

// @0x141486450
bool MinimapViewport::FUN_141486450(const Unk_GVec3& kPos, Unk_GVec3& kOut, float fScale)
{
    Unk_GVec3 kPt;
    if (FUN_141486550(kPos, kPt.x, kPt.y, kPt.z))
    {
        kOut.z = kPt.z;
        kOut.x = (kPt.x * FUN_141486d90(m_rcScreen) - m_rcImage.l) * fScale;
        kOut.y = ((1.0f - kPt.y) * FUN_141486d30(m_rcScreen) - m_rcImage.t) * fScale;
        return true;
    }
    return false;
}

// @0x141486550
bool MinimapViewport::FUN_141486550(const Unk_GVec3& kPos, float& fX, float& fY, float& fZ)
{
    float fEps = FUN_140a0fda0(1e-05f, 0.0f);
    Unk_Rect4 kRect(0.0f, 1.0f, 1.0f, 0.0f);

    float fW = kPos.x * m_afMatrix[3][0] + kPos.y * m_afMatrix[3][1] + kPos.z * m_afMatrix[3][2] + m_afMatrix[3][3];
    if (fW <= fEps)
    {
        fX = FLT_MAX;
        fY = FLT_MAX;
        fZ = FLT_MAX;
        return false;
    }

    float fInvW = 1.0f / fW;
    fX = kPos.x * m_afMatrix[0][0] + kPos.y * m_afMatrix[0][1] + kPos.z * m_afMatrix[0][2] + m_afMatrix[0][3];
    fY = kPos.x * m_afMatrix[1][0] + kPos.y * m_afMatrix[1][1] + kPos.z * m_afMatrix[1][2] + m_afMatrix[1][3];
    fX = fX * fInvW;
    fY = fY * fInvW;
    fX = fX * (kRect.r - kRect.l) * 0.5f;
    fY = fY * (kRect.t - kRect.b) * 0.5f;
    fX = fX + (kRect.r + kRect.l) * 0.5f;
    fY = fY + (kRect.t + kRect.b) * 0.5f;
    fZ = (kPos.x * m_afMatrix[2][0] + kPos.y * m_afMatrix[2][1] + kPos.z * m_afMatrix[2][2] + m_afMatrix[2][3]) * fInvW;
    if (fX >= kRect.l && fX <= kRect.r && fY >= kRect.b && fY <= kRect.t)
        return true;
    return false;
}

// @0x141486a20
void MinimapViewport::FUN_141486a20(Unk_GVec3 kRot, Unk_GVec3& kAxisX, Unk_GVec3& kAxisY, Unk_GVec3& kAxisZ)
{
    Unk_MvMatrix3 kMatrix;
    if (FUN_140a38cd0(kRot.z) >= 1e-05f)
    {
        FUN_1409f72e0(kMatrix);
        kMatrix.FUN_142083d40(kRot.x * k_fPiOver180, kRot.y * k_fPiOver180, kRot.z * k_fPiOver180);
        kMatrix.FUN_140a01190(0, kAxisY);
        kMatrix.FUN_140a01190(1, kAxisZ);
        kMatrix.FUN_140a01190(2, kAxisX);
        // kAxisZ = -kAxisZ; kAxisX = -kAxisX; (efd::Point3::operator- hands its result back through the hidden pointer
        // in rdx, so it is a member call; the view adds no data)
        ((Unk_MvPoint3&)kAxisZ).FUN_140194470(((Unk_MvPoint3&)kAxisZ).FUN_1409f7960());
        ((Unk_MvPoint3&)kAxisX).FUN_140194470(((Unk_MvPoint3&)kAxisX).FUN_1409f7960());
        FUN_140968990(kAxisY);
        FUN_140968990(kAxisZ);
        FUN_140968990(kAxisX);
    }
    else
    {
        FUN_1409f72e0(kMatrix);
        kMatrix.FUN_142083d40(-kRot.x * k_fPiOver180, -kRot.y * k_fPiOver180, kRot.z * k_fPiOver180);
        kMatrix.FUN_140a01190(0, kAxisY);
        kMatrix.FUN_140a01190(1, kAxisZ);
        kMatrix.FUN_140a01190(2, kAxisX);
        FUN_140968990(kAxisY);
        FUN_140968990(kAxisZ);
        FUN_140968990(kAxisX);
    }
}

// @0x141486d30
float FUN_141486d30(const Unk_Rect4& rc)
{
    return rc.t > rc.b ? (rc.t - rc.b) : (rc.b - rc.t);
}

// @0x141486d90
float FUN_141486d90(const Unk_Rect4& rc)
{
    return rc.r > rc.l ? (rc.r - rc.l) : (rc.l - rc.r);
}
