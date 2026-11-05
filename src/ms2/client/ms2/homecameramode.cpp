// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See homecameramode.h.
// MS2-UNIT: ?\homecameramode.cpp
// MS2-RANGE: 0x140b64c30-0x140b67d70 .text$mn
// MS2-PIN: ??_GCHomeCameraMode@@UEAAPEAXI@Z 0x140b67cd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\homecameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Matrix3.h>   // C3: efd::Matrix3 rotation builders

#include "homecameramode.h"


#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include <ecr/RenderService.h>   // C3: GetActiveRenderSurface / GetCamera
#include <ecr/RenderSurface.h>
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940

// ---- unit-local placeholders ----

#define g_143a08ce8 (*(const Vector3*)&efd::Point3::UNIT_Y) // C3: was extern const Vector3 g_143a08ce8 (0, 1, 0)
#define g_143a08cf8 (*(const Vector3*)&efd::Point3::UNIT_Z)   // NiPoint3::UNIT_Z
extern float g_143abb090;                   // remembered camera distance (vfunc_7 / vfunc_24)

class Unk_BuffContainer;
// C3: the movement controller (Unk_PCMove, unit_141682f80) behind FUN_14166d240
class Unk_PCMove
{
public:
    bool FUN_141682fe0(int nKey);
};

class PCBase { public: void * FUN_14166d240(void); }; class Unk_LocalPlayer : public PCBase {
public:

};

// The camera option row held by the game context (+0x154 rotation).
struct Unk_CameraOption
{
    char m_pad_000[0x154];
    float m_154;
    char m_pad_158[0x23c - 0x158];
    float m_23c;
};

// A view of the world service.
class Unk_GameContext : public WorldService
{
};

// A float table value of the client configuration (FUN_1401d3200).
struct Unk_ConfigFloat
{
    char m_pad[0x58];
};
MS2_CHECK_SIZE(Unk_ConfigFloat, 0x58);
struct Unk_ClientConfig
{
    char m_pad_0000[0x1a80];
    Unk_ConfigFloat m_1a80;
    Unk_ConfigFloat m_1ad8;
    Unk_ConfigFloat m_1b30;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// The scene camera (FUN_1413f9890()->GetActiveRenderSurface()->GetCamera()) and its frustum.
struct Unk_HomeFrustum
{
    float m_0, m_4, m_8, m_c, m_10;                 // left, right, top, bottom, near
};
class Unk_NiCamera
{
public:
};
ecr::RenderService* FUN_1413f9890();   // C3: the render service (was Unk_SceneRoot*)

class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: the physics service getter (real return type)
// The collision world (0x143ab50b8).
class CPhysXHelper
{
public:
    int RayCastFromPoint(Vector3 ptFrom, Vector3& ptHit, Vector3 ptDir, float fLen, int nMask);
};

float FUN_14029d220(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_1409f2310(float f);                       // sin
float FUN_141b6fdb0(float t, int nType);            // easing
bool FUN_14028d470(float a, float b);               // a == b (within epsilon)
extern "C" float (__cdecl* __imp_tanf)(float);      // the exe calls tanf through its import
class CCapRotationController   // C3: member view for the former free stand-ins
{
public:
    static float SafeAcos(float);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140b64c30
CHomeCameraMode::CHomeCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev),
      m_78(0),
      m_7c(reinterpret_cast<const efd::Point3&>(g_143b01a60)),
      m_88(reinterpret_cast<const efd::Point3&>(g_143b01a60)),
      m_94(0.0f),
      m_98(0.0f),
      m_9c(0.0f),
      m_a0(1.0f),
      m_a4(40.0f),
      m_ac(0),
      m_b0(0),
      m_b4(0),
      m_b8(0.0f),
      m_bc(0),
      m_c0(0),
      m_f4(0.0f),
      m_f8(0.0f),
      m_fc(0.0f),
      m_100(reinterpret_cast<const efd::Point3&>(g_143b01a60)),
      m_10c(reinterpret_cast<const efd::Point3&>(g_143a08cf8))
{
    m_9c = static_cast<Unk_GameContext*>(WorldService::GetInstance())->FUN_141bd4120();
}

// @0x140b64e40
CHomeCameraMode::~CHomeCameraMode()
{
}
MS2_REPLACE_DTOR(0x140B64E40, CHomeCameraMode, 39, 0xE439C4F8);

// @0x140b64ea0
void CHomeCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    m_100 = reinterpret_cast<Unk_CameraManagerData*>(TSingleton<CameraMgr>::GetInstance())->m_c8;
    m_10c = reinterpret_cast<Unk_CameraManagerData*>(TSingleton<CameraMgr>::GetInstance())->m_d4;
    m_4c = CCapRotationController::SafeAcos(m_100.z);
    if (m_b4 == 0)
    {
        m_50 = TSingleton<CameraMgr>::GetInstance()->FUN_140b67d10();
        m_b0 = 0;
        m_b8 = 0.0f;
    }
    if (n == 0)
    {
        Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
        if (pTarget)
        {
            m_88 = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pTarget->vfunc_17()));
            m_88.z += vfunc_27();
            vfunc_3(reinterpret_cast<Vector3&>(m_88).FUN_14097fd50(FUN_140b66660()));
        }
    }
    if (m_b4)
    {
        m_c0 = 1;
    }
    else
    {
        m_c0 = 0;
        m_c4.m_pos = FUN_1409f2540();
        m_c4.m_rot = FUN_140af8260();
        m_dc = m_c4;
        m_f4 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_ClientConfig*)FUN_1401d3200())->m_1b30)->Read();
        m_f8 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_ClientConfig*)FUN_1401d3200())->m_1a80)->Read();
        m_fc = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_ClientConfig*)FUN_1401d3200())->m_1ad8)->Read();
    }
    m_b4 = 0;
    FUN_140b66570();
}
MS2_REPLACE_METHOD(0x140B64EA0, CHomeCameraMode, vfunc_6, 809, 0x062EA86D);

// @0x140b651d0
void CHomeCameraMode::vfunc_7()
{
    CCameraMode::vfunc_7();
    if (m_ac)
        g_143abb090 = m_50;
    else
        g_143abb090 = 0.0f;
    Unk_CameraSetting setting;
    setting.m_0 = TSingleton<CameraMgr>::GetInstance()->FUN_140ad4b40();
    setting.m_4 = TSingleton<CameraMgr>::GetInstance()->FUN_140af7f00();
    setting.m_8 = TSingleton<CameraMgr>::GetInstance()->FUN_140af7ea0();
    setting.m_c = TSingleton<CameraMgr>::GetInstance()->FUN_140a17e10();
    setting.m_18 = TSingleton<CameraMgr>::GetInstance()->FUN_140af8290();
    reinterpret_cast<Unk_CameraManagerData*>(TSingleton<CameraMgr>::GetInstance())->m_e0 = setting;
}
MS2_REPLACE_METHOD(0x140B651D0, CHomeCameraMode, vfunc_7, 222, 0x3F1915D8);

// @0x140b652c0
void CHomeCameraMode::vfunc_10()
{
    TSingleton<CameraMgr>::GetInstance()->FUN_140aeaf40(TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60(), 1);
}
MS2_REPLACE_METHOD(0x140B652C0, CHomeCameraMode, vfunc_10, 59, 0x3AEC2CB0);

// @0x140b65310
void CHomeCameraMode::vfunc_8(double fTime)
{
    int nLoop = 100;
    for (int i = 0; i < nLoop; ++i)
    {
        Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
        if (!pTarget)
            break;
        m_88 = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pTarget->vfunc_17()));
        m_88.z += vfunc_27();

        Vector3 ptPos = g_143b01a60;
        Vector3 ptRot = g_143b01a60;
        if (m_78 == 0)
        {
            Vector3 ptEye = reinterpret_cast<Vector3&>(m_88).FUN_14097fd50(FUN_140b66660());
            m_c4.m_pos = ptEye;
        }

        bool bZoom = false;
        if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) > 5.0f)
        {
            bZoom = true;
            if (m_98 < m_50)
                m_94 = 10.0f;
            else if (m_98 > m_50)
                m_94 = -10.0f;
            if (m_50 > m_54)
                m_94 = m_94 * m_a0;
        }
        if (bZoom || FUN_14029d220(m_94) >= 5.0f)
        {
            m_78 = 1;
            if (m_bc == 0)
                m_94 = m_94 * 0.9f;
            ptPos = m_c4.m_pos;
            Vector3 ptTarget = reinterpret_cast<Vector3&>(m_88);
            Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
            ptDir.FUN_140968990();
            ptPos.FUN_140a4e560(ptDir.FUN_14097fc90(m_94));
            if (m_50 < m_58 || m_54 + m_9c < m_50)
            {
                if ((0.0f < m_94 && m_54 + m_9c < m_50) || (0.0f > m_94 && m_50 < m_58))
                    FUN_140b66730(ptPos, ptRot, ptTarget, false);
                else
                    FUN_140b66730(ptPos, ptRot, ptTarget, true);
            }
            else if (m_50 >= m_58 && m_54 + m_9c >= m_50)
            {
                FUN_140b66730(ptPos, ptRot, ptTarget, true);
            }
            else
            {
                m_c4.m_pos = ptPos;
            }
        }
        else if (m_78)
        {
            m_94 = 0.0f;
            m_78 = 0;
            FUN_140b66570();
        }

        Vector3 ptMove = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d00();
        if (reinterpret_cast<const efd::Point3&>(ptMove) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
        {
            Vector3 ptInput = ptMove;
            float fRate = 15.0f;
            float fStep = efd::Clamp((float)fTime, 0.0f, 1.0f / fRate);
            float fMax = efd::Max<float>(FUN_140a38cd0(ptInput.x),
                                       efd::Max<float>(FUN_140a38cd0(ptInput.y), FUN_140a38cd0(ptInput.z)));
            float fScale = fStep * fMax;
            float fZoom = ptInput.x * fScale;
            float fYaw = ptInput.y * fScale;
            float fPitch = ptInput.z * fScale;
            if (fZoom != 0.0f)
            {
                m_94 += fZoom * 2000.0f;
                m_94 = efd::Clamp(m_94, -150.0f, 150.0f);
            }
            if (fYaw != 0.0f || fPitch != 0.0f)
            {
                m_68 += fYaw;
                Vector3 ptCenter = reinterpret_cast<Vector3&>(m_88);
                ptPos = m_c4.m_pos;
                ptPos.z = ptCenter.z;
                Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
                m_50 = ptDist.FUN_140967ac0();
                m_50 = efd::Clamp(m_50, m_58, m_54 + m_9c);
                ptPos.x = m_50 * m_100.x + ptCenter.x;
                ptPos.y = m_50 * m_100.y + ptCenter.y;
                ptPos.z = m_50 * m_100.z + ptCenter.z;
                if (m_50 > m_58 && m_54 + m_9c > m_50)
                {
                    m_c4.m_pos = ptPos;
                    ptRot = CCameraMode::FUN_140afdd40(ptCenter, m_c4.m_pos, reinterpret_cast<Vector3&>(m_10c));
                    m_c4.m_rot = ptRot;
                    FUN_140b66570();
                }
            }
            TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(g_143b01a60);
        }
        vfunc_37(fTime);
        m_setting.m_c = m_c4.m_pos;
        m_setting.m_18 = m_c4.m_rot;
        if (m_bc == 0)
            return;
    }
}
MS2_REPLACE_METHOD(0x140B65310, CHomeCameraMode, vfunc_8, 2901, 0xFFFC5422);

// @0x140b65e70
void CHomeCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    Unk_LocalPlayer* pPlayer = static_cast<Unk_LocalPlayer*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer && reinterpret_cast<Unk_PCMove*>(pPlayer->FUN_14166d240())->FUN_141682fe0(300008))
        ptMove.x = 1.0f;
    else if (pPlayer && reinterpret_cast<Unk_PCMove*>(pPlayer->FUN_14166d240())->FUN_141682fe0(300009))
        ptMove.x = -1.0f;
    TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x140B65E70, CHomeCameraMode, vfunc_9, 208, 0x69A99AEA);

// @0x140b65f50
void CHomeCameraMode::vfunc_33()
{
    MS2Ptr<CFieldDataCli> spOption = WorldService::GetInstance()->FUN_141bd30a0();
    if (reinterpret_cast<Unk_CameraOption*>(spOption.get()))
    {
        float fRotation = reinterpret_cast<Unk_CameraOption*>(spOption.operator->())->m_154;
        if (TSingleton<CameraMgr>::GetInstance()->FUN_140af01d0())
        {
            vfunc_31();
            vfunc_16(m_a8);
            vfunc_11(m_a4);
            vfunc_12(fRotation);
        }
        else
        {
            vfunc_16(reinterpret_cast<Unk_CameraOption*>(spOption.operator->())->m_23c);
            vfunc_11(static_cast<Unk_GameContext*>(WorldService::GetInstance())->FUN_141bcfc50());
            vfunc_12(fRotation);
        }
        vfunc_10();
    }
}
MS2_REPLACE_METHOD(0x140B65F50, CHomeCameraMode, vfunc_33, 334, 0x0FD2BF9A);

// @0x140b660b0
void CHomeCameraMode::vfunc_11(float f)
{
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140af01d0())
        f = m_a4;
    m_setting.m_0 = f;
    m_pOwner->FUN_140947940(f);
}
MS2_REPLACE_METHOD(0x140B660B0, CHomeCameraMode, vfunc_11, 92, 0xC0A00B6B);

// @0x140b66120
void CHomeCameraMode::vfunc_16(float f)
{
    m_54 = TSingleton<CameraMgr>::GetInstance()->FUN_140af01d0() ? m_a8 : f;
    if (-1.0f != m_5c)
        m_98 = efd::Clamp(m_98, m_58, m_54 + m_9c);
}
MS2_REPLACE_METHOD(0x140B66120, CHomeCameraMode, vfunc_16, 172, 0x273C523C);

// @0x140b661e0
void CHomeCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
    if (pTarget && n)
    {
        m_c0 = 0;
        m_50 = m_54;
        if (m_ac && g_143abb090 != 0.0f)
            m_50 = g_143abb090;
        m_9c = static_cast<Unk_GameContext*>(WorldService::GetInstance())->FUN_141bd4120();
        m_88 = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pTarget->vfunc_17()));
        m_88.z += vfunc_27();
        float fAngle = FUN_140b66b10(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
        m_100.z = FUN_1409f2310(fAngle);
        m_c4.m_pos.x = m_50 * m_100.x + m_88.x;
        m_c4.m_pos.y = m_50 * m_100.y + m_88.y;
        m_c4.m_pos.z = m_50 * m_100.z + m_88.z;
        vfunc_3(m_c4.m_pos);
        Vector3 ptRot = CCameraMode::FUN_140afdd40(reinterpret_cast<Vector3&>(m_88), m_c4.m_pos, reinterpret_cast<Vector3&>(m_10c));
        vfunc_4(ptRot);
        m_c4.m_rot = ptRot;
        FUN_140b66570();
        m_b0 = 0;
        m_b8 = 0.0f;
    }
}
MS2_REPLACE_METHOD(0x140B661E0, CHomeCameraMode, vfunc_24, 898, 0x61962024);

// @0x140b66570
void CHomeCameraMode::FUN_140b66570()
{
    m_c4.m_pos.x = m_50 * m_100.x + m_88.x;
    m_c4.m_pos.y = m_50 * m_100.y + m_88.y;
    m_c4.m_pos.z = m_50 * m_100.z + m_88.z;
    m_7c = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(m_c4.m_pos.FUN_140965c40(reinterpret_cast<Vector3&>(m_88))));
}
MS2_REPLACE_METHOD(0x140B66570, CHomeCameraMode, FUN_140b66570, 232, 0x61C01930);

// @0x140b66660
Vector3 CHomeCameraMode::FUN_140b66660()
{
    return reinterpret_cast<Vector3&>(m_7c);
}
MS2_REPLACE_METHOD(0x140B66660, CHomeCameraMode, FUN_140b66660, 41, 0x359C3214);

// @0x140b66690
float CHomeCameraMode::vfunc_27()
{
    float fRange = m_54 - m_58;
    float fHeight = m_64;
    if (fRange > 0.0f)
        fHeight = m_64 + (m_60 - m_64) * ((m_50 - m_58) / fRange);
    return fHeight;
}
MS2_REPLACE_METHOD(0x140B66690, CHomeCameraMode, vfunc_27, 147, 0xB6BA5502);

// @0x140b66730
void CHomeCameraMode::FUN_140b66730(Vector3 ptPos, Vector3 ptRot, Vector3 ptTarget, bool bClamp)
{
    float fAngle = FUN_140b66b10(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
    m_100.z = FUN_1409f2310(fAngle);
    if (reinterpret_cast<const efd::Point3&>(m_10c) == efd::Point3::UNIT_Y)
        m_100.z = 1.0f;
    else if (reinterpret_cast<const efd::Point3&>(m_10c) == efd::Point3::UNIT_Z)
        ptPos.z = ptTarget.z;
    float fPrevDist = m_50;
    Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
    m_50 = ptDir.FUN_140967ac0();
    if (bClamp)
        m_50 = efd::Clamp(m_50, m_58, m_54 + m_9c);
    if (0.0f > m_94 && m_50 > m_54 && fPrevDist < m_54)
    {
        m_50 = m_54;
        m_5c = -1.0f;
        m_94 = 0.0f;
    }
    else if (0.0f < m_94 && fPrevDist > m_54 && m_50 < m_54)
    {
        m_50 = m_54;
        m_5c = -1.0f;
        m_94 = 0.0f;
    }
    if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) <= 5.0f)
    {
        m_50 = m_98;
        m_5c = -1.0f;
        m_94 = 0.0f;
    }
    ptPos.x = m_50 * m_100.x + ptTarget.x;
    ptPos.y = m_50 * m_100.y + ptTarget.y;
    ptPos.z = m_50 * m_100.z + ptTarget.z;
    m_c4.m_pos = ptPos;
    ptRot = CCameraMode::FUN_140afdd40(ptTarget, m_c4.m_pos, reinterpret_cast<Vector3&>(m_10c));
    m_c4.m_rot = ptRot;
}
MS2_REPLACE_METHOD(0x140B66730, CHomeCameraMode, FUN_140b66730, 972, 0x6CC486F2);

// @0x140b66b10
float CHomeCameraMode::FUN_140b66b10(float fMin, float fCur, float fMax, float fDegMin, float fDegMax)
{
    float t = fCur - fMin;
    t /= fMax - fMin;
    if (t > 1.0f)
        t = 1.0f;
    float fDegree = (fDegMin - fDegMax) * t;
    fDegree = fDegMax + fDegree;
    return fDegree * 3.14159265f / 180.0f;
}
MS2_REPLACE_METHOD(0x140B66B10, CHomeCameraMode, FUN_140b66b10, 168, 0x89B97448);

// @0x140b66bc0
void CHomeCameraMode::vfunc_37(double fTime)
{
    float fDist;
    if (m_c0)
    {
        NiPoint3 ptDiff = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(m_c4.m_pos.FUN_140965c40(m_dc.m_pos)));
        fDist = reinterpret_cast<Vector3&>(ptDiff).FUN_140967ac0();
        float fBlend = 0.0f;
        if (m_b0)
        {
            if (fDist >= 10.0f)
            {
                m_b0 = 0;
            }
            else
            {
                m_b8 = (float)((double)m_b8 + fTime);
                if (!(m_b8 < 3.0f))
                {
                    fBlend = 1.0f;
                    m_b0 = 0;
                }
                else
                {
                    fBlend = FUN_141b6fdb0(m_b8 / 3.0f, 3);
                }
            }
        }
        else if (!FUN_14028d470(fDist, 0.0f) && !(fDist > 10.0f))
        {
            m_b0 = 1;
            m_b8 = 0.0f;
            fBlend = 0.0f;
        }
        if (FUN_14028d470(fDist, 0.0f))
        {
            m_dc = m_c4;
        }
        else
        {
            float fStep = FUN_14059d930(m_f4) * (float)fTime;
            if (m_fc != m_f8)
            {
                if (FUN_14059d930(m_fc - m_f8) < fStep)
                    m_fc = m_f8;
                else if (!(m_fc <= m_f8))
                    m_fc = m_fc - fStep;
                else
                    m_fc = m_fc + fStep;
            }
            float fT = (float)fTime * fDist * m_fc + fBlend;
            if (fT > 1.0f)
            {
                m_dc = m_c4;
            }
            else
            {
                m_dc.m_pos = m_dc.m_pos.FUN_14097fd50(FUN_1409ab5c0(fT, m_c4.m_pos.FUN_140965c40(m_dc.m_pos)));
                if (reinterpret_cast<const efd::Point3&>(m_dc.m_rot) != reinterpret_cast<const efd::Point3&>(m_c4.m_rot))
                    m_dc.m_rot = CCameraMode::FUN_140afdec0(fT, m_dc.m_rot, m_c4.m_rot);
            }
        }
        m_bc = vfunc_38(m_dc.m_pos, m_dc.m_rot);
        if (m_bc)
            m_94 = -10.0f;
    }
    else
    {
        m_dc = m_c4;
        m_c0 = 1;
        m_bc = 0;
    }
    m_setting.m_c = m_dc.m_pos;
    m_setting.m_18 = m_dc.m_rot;
    m_pOwner->FUN_140a38dc0(m_dc.m_pos);
    m_pOwner->FUN_140a38e00(m_dc.m_rot);
}
MS2_REPLACE_METHOD(0x140B66BC0, CHomeCameraMode, vfunc_37, 1489, 0x509869EC);

// @0x140b671a0
BOOL CHomeCameraMode::vfunc_38(Vector3 ptPos, Vector3 ptRot)
{
    ecr::RenderSurface* pSceneCamera = FUN_1413f9890()->GetActiveRenderSurface();
    if (pSceneCamera)
    {
        Unk_NiCamera* pCamera = (Unk_NiCamera*)pSceneCamera->GetCamera();
        if (pCamera)
        {
            Unk_NiMatrix3 kRot;
            Unk_NiMatrix3 kX;
            Unk_NiMatrix3 kY;
            Unk_NiMatrix3 kZ;
            reinterpret_cast<efd::Matrix3&>(kX).MakeXRotation(ptRot.x * -0.0174532924f);
            reinterpret_cast<efd::Matrix3&>(kY).MakeYRotation(ptRot.y * -0.0174532924f);
            reinterpret_cast<efd::Matrix3&>(kZ).MakeZRotation(ptRot.z * -0.0174532924f);
            kRot = reinterpret_cast<const Unk_EfdMatrix3&>(static_cast<const efd::Matrix3&>(reinterpret_cast<const efd::Matrix3&>(kX) * reinterpret_cast<const efd::Matrix3&>(kY) * reinterpret_cast<const efd::Matrix3&>(kZ)));
            Vector3 kDir;
            Vector3 kUp;
            Vector3 kRight;
            reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(0, reinterpret_cast<efd::Point3&>(kDir));
            reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(1, reinterpret_cast<efd::Point3&>(kUp));
            reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(2, reinterpret_cast<efd::Point3&>(kRight));
            Unk_HomeFrustum* pFrustum = (Unk_HomeFrustum*)&reinterpret_cast<NiCamera*>(pCamera)->GetViewFrustum();
            float fNear = pFrustum->m_10;
            float fFov = FUN_140ad4b30();
            float fAspect = (pFrustum->m_4 - pFrustum->m_0) / (pFrustum->m_8 - pFrustum->m_c);
            float fTan = __imp_tanf(fFov * 3.14159265f / 180.0f);
            float fTanAspect = fTan * fAspect;
            Vector3 aptCorner[9];
            aptCorner[0] = ptPos.FUN_14097fd50(kDir.FUN_14097fc90(fNear))
                               .FUN_140965c40(FUN_1409ab5c0(fNear, kRight).FUN_14097fc90(fTanAspect))
                               .FUN_14097fd50(kUp.FUN_14097fc90(fTan).FUN_14097fc90(fNear));
            aptCorner[1] = ptPos.FUN_14097fd50(kDir.FUN_14097fc90(fNear))
                               .FUN_14097fd50(FUN_1409ab5c0(fNear, kRight).FUN_14097fc90(fTanAspect))
                               .FUN_14097fd50(kUp.FUN_14097fc90(fTan).FUN_14097fc90(fNear));
            aptCorner[2] = ptPos.FUN_14097fd50(kDir.FUN_14097fc90(fNear))
                               .FUN_140965c40(FUN_1409ab5c0(fNear, kRight).FUN_14097fc90(fTanAspect))
                               .FUN_140965c40(kUp.FUN_14097fc90(fTan).FUN_14097fc90(fNear));
            aptCorner[3] = ptPos.FUN_14097fd50(kDir.FUN_14097fc90(fNear))
                               .FUN_14097fd50(FUN_1409ab5c0(fNear, kRight).FUN_14097fc90(fTanAspect))
                               .FUN_140965c40(kUp.FUN_14097fc90(fTan).FUN_14097fc90(fNear));
            aptCorner[4] = aptCorner[0].FUN_14097fd50(aptCorner[3]).FUN_14097fc90(0.5f);
            aptCorner[5] = aptCorner[0].FUN_14097fd50(aptCorner[1]).FUN_14097fc90(0.5f);
            aptCorner[6] = aptCorner[0].FUN_14097fd50(aptCorner[2]).FUN_14097fc90(0.5f);
            aptCorner[7] = aptCorner[1].FUN_14097fd50(aptCorner[3]).FUN_14097fc90(0.5f);
            aptCorner[8] = aptCorner[2].FUN_14097fd50(aptCorner[3]).FUN_14097fc90(0.5f);
            for (int i = 0; i < 9; ++i)
            {
                Vector3 ptDir = reinterpret_cast<Vector3&>(m_88).FUN_140965c40(aptCorner[i]);
                float fLen = ptDir.FUN_140968990();
                Vector3 ptBack = ptDir.FUN_1409f7960();
                Vector3 ptHit = g_143b01a60;
                if (((CPhysXHelper*)FUN_1409f7ca0())->RayCastFromPoint(aptCorner[i], ptHit, ptDir, fLen, 0x209) == 0)
                {
                    if (((CPhysXHelper*)FUN_1409f7ca0())->RayCastFromPoint(static_cast<Vector3>(reinterpret_cast<Vector3&>(m_88)), ptHit, ptBack, fLen, 0x209))
                        return 1;
                }
                else
                {
                    Vector3 ptHit2 = g_143b01a60;
                    if (((CPhysXHelper*)FUN_1409f7ca0())->RayCastFromPoint(ptHit, ptHit2, ptBack, fLen, 0x209))
                        return 1;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140B671A0, CHomeCameraMode, vfunc_38, 2720, 0xC51335A7);

// @0x140b67d10
float CameraMgr::FUN_140b67d10()   // C3: was Unk_CameraManager::FUN_140b67d10
{
    if (reinterpret_cast<Unk_CameraManagerData*>(this)->m_118.get())
        return reinterpret_cast<Unk_CameraManagerData*>(this)->m_118->vfunc_17();
    return 0.0f;
}
MS2_REPLACE_METHOD(0x140B67D10, CameraMgr, FUN_140b67d10, 86, 0x4EECFEFC);

// @0x140b67c40
Unk_HomeCameraPose::Unk_HomeCameraPose()
    : m_rot(g_143b01a60),
      m_pos(g_143b01a60)
{
}
MS2_REPLACE_CTOR(0x140B67C40, Unk_HomeCameraPose, 63, 0xA4FDA0AC);

// @0x140b67c80
Unk_HomeCameraPose& Unk_HomeCameraPose::operator=(const Unk_HomeCameraPose& o)
{
    m_rot = o.m_rot;
    m_pos = o.m_pos;
    return *this;
}
