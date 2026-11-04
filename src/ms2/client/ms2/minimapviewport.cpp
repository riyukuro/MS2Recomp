// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See minimapviewport.h. The exe's copies of the
// efd::Point3 / efd::Matrix3 helpers this unit calls are shared COMDATs owned by other objs, so they are declared as
// free functions here (a member's thiscall is the same calling convention as a first reference parameter) and the
// hook DLL binds them to the exe.
// MS2-UNIT: ?\minimapviewport.cpp
// MS2-RANGE: 0x1414856d0-0x141486df0 .text$mn
// MS2-PIN: ??_GMinimapViewport@@UEAAPEAXI@Z 0x141486cd0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Matrix3.h>   // C3: efd::Matrix3::FromEulerAnglesXYZ

#include "minimapviewport.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include <efd/EEMath.h>   // C3: efd::Max was FUN_140a0fda0

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------
// The world service (0x1403ed2d0); the client field data it hands out (0x141bd30a0).
class Unk_MvWorld : public WorldService
{
public:
};

// efd::Matrix3 helpers (all out of line in the exe).
float FUN_140a38cd0(float fValue);                               // efd::Abs
void FUN_1409f72e0(Unk_MvMatrix3& kMatrix);                      // efd::Matrix3::Matrix3()

static const float k_fPi = 3.1415927f;   // the exe multiplies by pi, then divides by 180

// ---- MinimapViewport ----------------------------------------------------------------------------------------------------
// @0x1414856d0
MinimapViewport::MinimapViewport()
    : m_kFrustum(false)
    , m_rcImage(0.0f, 0.0f, 0.0f, 0.0f)
    , m_rcScreen(0.0f, 0.0f, 0.0f, 0.0f)
{
    ResetScale();
}

// @0x141485770
unsigned MinimapViewport::InitFromFieldMinimap(int nScale)
{
    ResetScale();
    MS2Ptr<CFieldDataCli> spField = reinterpret_cast<Unk_MvWorld*>(WorldService::GetInstance())->FUN_141bd30a0();
    if (spField ? true : false)
    {
        if (spField->m_spMinimap ? true : false)
        {
            MS2Ptr<CMinimap> spMinimap = spField->m_spMinimap;
            m_kFrustum = spMinimap->m_frustum;
            m_rcImage = spMinimap->m_rcImage;
            m_rcScreen = spMinimap->m_rcScreen;

            NiPoint3 kAxisY(0.0f, 0.0f, 0.0f);
            NiPoint3 kAxisZ(0.0f, 0.0f, 0.0f);
            NiPoint3 kAxisX(0.0f, 0.0f, 0.0f);
            Unk_MvRot3 kRot = reinterpret_cast<const Unk_MvRot3&>(spMinimap->m_vecCamRot);
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
void MinimapViewport::FUN_141485a50(const NiPoint3& kCamPos, const NiPoint3& kAxisX, const NiPoint3& kAxisY,
                                    const NiPoint3& kAxisZ)
{
    float fDotX = -kAxisX.Dot(kCamPos);
    float fDotZ = -kAxisZ.Dot(kCamPos);
    float fDotY = -kAxisY.Dot(kCamPos);

    float fSumLR = m_kFrustum.r + m_kFrustum.l;
    float fSumTB = m_kFrustum.t + m_kFrustum.b;
    float fInvLR = 1.0f / (m_kFrustum.r - m_kFrustum.l);
    float fInvTB = 1.0f / (m_kFrustum.t - m_kFrustum.b);
    float fInvNF = 1.0f / (m_kFrustum.f - m_kFrustum.n);

    if (m_kFrustum.ortho)
    {
        float fX = 2.0f * fInvLR;
        float fXT = fSumLR * fInvLR;
        float fZ = 2.0f * fInvTB;
        float fZT = fSumTB * fInvTB;
        float fNF = fInvNF;
        float fNT = -m_kFrustum.n * fNF;
        m_afMatrix[0][0] = fX * kAxisX.x;
        m_afMatrix[0][1] = fX * kAxisX.y;
        m_afMatrix[0][2] = fX * kAxisX.z;
        m_afMatrix[0][3] = fX * fDotX + fXT;
        m_afMatrix[1][0] = fZ * kAxisZ.x;
        m_afMatrix[1][1] = fZ * kAxisZ.y;
        m_afMatrix[1][2] = fZ * kAxisZ.z;
        m_afMatrix[1][3] = fZ * fDotZ + fZT;
        m_afMatrix[2][0] = fNF * kAxisY.x;
        m_afMatrix[2][1] = fNF * kAxisY.y;
        m_afMatrix[2][2] = fNF * kAxisY.z;
        m_afMatrix[2][3] = fNF * fDotY + fNT;
        m_afMatrix[3][0] = 0.0f;
        m_afMatrix[3][1] = 0.0f;
        m_afMatrix[3][2] = 0.0f;
        m_afMatrix[3][3] = 1.0f;
    }
    else
    {
        float fX = 2.0f * fInvLR;
        float fXV = -fSumLR * fInvLR;
        float fZ = 2.0f * fInvTB;
        float fZV = -fSumTB * fInvTB;
        float fNF = m_kFrustum.f * fInvNF;
        float fNT = -m_kFrustum.n * fNF;
        m_afMatrix[0][0] = fX * kAxisX.x + fXV * kAxisY.x;
        m_afMatrix[0][1] = fX * kAxisX.y + fXV * kAxisY.y;
        m_afMatrix[0][2] = fX * kAxisX.z + fXV * kAxisY.z;
        m_afMatrix[0][3] = fX * fDotX + fXV * fDotY;
        m_afMatrix[1][0] = fZ * kAxisZ.x + fZV * kAxisY.x;
        m_afMatrix[1][1] = fZ * kAxisZ.y + fZV * kAxisY.y;
        m_afMatrix[1][2] = fZ * kAxisZ.z + fZV * kAxisY.z;
        m_afMatrix[1][3] = fZ * fDotZ + fZV * fDotY;
        m_afMatrix[2][0] = fNF * kAxisY.x;
        m_afMatrix[2][1] = fNF * kAxisY.y;
        m_afMatrix[2][2] = fNF * kAxisY.z;
        m_afMatrix[2][3] = fNF * fDotY + fNT;
        m_afMatrix[3][0] = kAxisY.x;
        m_afMatrix[3][1] = kAxisY.y;
        m_afMatrix[3][2] = kAxisY.z;
        m_afMatrix[3][3] = fDotY;
    }
}

// @0x1414863e0
void MinimapViewport::ResetScale()
{
    m_fScale = 1.0f;
}

// @0x141486410
bool MinimapViewport::FUN_141486410(const NiPoint3& kPos, NiPoint3& kOut)
{
    return FUN_141486450(kPos, kOut, m_fScale);
}

// @0x141486450
bool MinimapViewport::FUN_141486450(const NiPoint3& kPos, NiPoint3& kOut, float fScale)
{
    NiPoint3 kPt;
    if (FUN_141486550(kPos, kPt.x, *(&kPt.x + 1), *(&kPt.x + 2)))
    {
        kOut.z = kPt.z;
        kOut.x = (kPt.x * FUN_141486d90(m_rcScreen) - m_rcImage.l) * fScale;
        kOut.y = ((1.0f - kPt.y) * FUN_141486d30(m_rcScreen) - m_rcImage.t) * fScale;
        return true;
    }
    return false;
}

// @0x141486550
bool MinimapViewport::FUN_141486550(const NiPoint3& kPos, float& fX, float& fY, float& fZ)
{
    float fEps = efd::Max<float>(1e-05f, 0.0f);
    Unk_Rect4 kRect(0.0f, 1.0f, 1.0f, 0.0f);

    float fW = kPos.x * m_afMatrix[3][0] + kPos.y * m_afMatrix[3][1] + kPos.z * m_afMatrix[3][2] + m_afMatrix[3][3];
    if (fW > fEps)
    {
        float fInvW = 1.0f / fW;
        fX = kPos.x * m_afMatrix[0][0] + kPos.y * m_afMatrix[0][1] + kPos.z * m_afMatrix[0][2] + m_afMatrix[0][3];
        fY = kPos.x * m_afMatrix[1][0] + kPos.y * m_afMatrix[1][1] + kPos.z * m_afMatrix[1][2] + m_afMatrix[1][3];
        fX = fX * fInvW;
        fY = fY * fInvW;
        fX *= (kRect.r - kRect.l) * 0.5f;
        fY *= (kRect.t - kRect.b) * 0.5f;
        fX = fX + (kRect.r + kRect.l) * 0.5f;
        fY = fY + (kRect.t + kRect.b) * 0.5f;
        fZ = kPos.x * m_afMatrix[2][0] + kPos.y * m_afMatrix[2][1] + kPos.z * m_afMatrix[2][2] + m_afMatrix[2][3];
        fZ = fZ * fInvW;
        if (fX >= kRect.l && fX <= kRect.r && fY >= kRect.b && fY <= kRect.t)
            return true;
    }
    else
    {
        fX = FLT_MAX;
        fY = FLT_MAX;
        fZ = FLT_MAX;
    }
    return false;
}

// @0x141486a20
void MinimapViewport::FUN_141486a20(Unk_MvRot3 kRot, NiPoint3& kAxisX, NiPoint3& kAxisY, NiPoint3& kAxisZ)
{
    if (FUN_140a38cd0(kRot.z) < 1e-05f)
    {
        Unk_MvMatrix3 kMatrix;
        FUN_1409f72e0(kMatrix);
        reinterpret_cast<efd::Matrix3*>(&kMatrix)->FromEulerAnglesXYZ(-kRot.x * k_fPi / 180.0f, -kRot.y * k_fPi / 180.0f, kRot.z * k_fPi / 180.0f);
        reinterpret_cast<const efd::Matrix3*>(&kMatrix)->GetCol(0, kAxisY);
        reinterpret_cast<const efd::Matrix3*>(&kMatrix)->GetCol(1, kAxisZ);
        reinterpret_cast<const efd::Matrix3*>(&kMatrix)->GetCol(2, kAxisX);
        ((struct Vector3*)&(kAxisY))->FUN_140968990();
        ((struct Vector3*)&(kAxisZ))->FUN_140968990();
        ((struct Vector3*)&(kAxisX))->FUN_140968990();
    }
    else
    {
        Unk_MvMatrix3 kMatrix;
        FUN_1409f72e0(kMatrix);
        reinterpret_cast<efd::Matrix3*>(&kMatrix)->FromEulerAnglesXYZ(kRot.x * k_fPi / 180.0f, kRot.y * k_fPi / 180.0f, kRot.z * k_fPi / 180.0f);
        reinterpret_cast<const efd::Matrix3*>(&kMatrix)->GetCol(0, kAxisY);
        reinterpret_cast<const efd::Matrix3*>(&kMatrix)->GetCol(1, kAxisZ);
        reinterpret_cast<const efd::Matrix3*>(&kMatrix)->GetCol(2, kAxisX);
        reinterpret_cast<efd::Point3&>(kAxisZ) = -reinterpret_cast<const efd::Point3&>(kAxisZ);
        reinterpret_cast<efd::Point3&>(kAxisX) = -reinterpret_cast<const efd::Point3&>(kAxisX);
        ((struct Vector3*)&(kAxisY))->FUN_140968990();
        ((struct Vector3*)&(kAxisZ))->FUN_140968990();
        ((struct Vector3*)&(kAxisX))->FUN_140968990();
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
