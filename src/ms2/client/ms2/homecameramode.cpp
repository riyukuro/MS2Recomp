// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See homecameramode.h.
// MS2-UNIT: ?\homecameramode.cpp
// MS2-RANGE: 0x140b64c30-0x140b67d70 .text$mn
// MS2-PIN: ??_GCHomeCameraMode@@UEAAPEAXI@Z 0x140b67cd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\homecameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "homecameramode.h"


#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Vector3 g_143a08ce8;   // NiPoint3::UNIT_X
extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z
extern float g_143abb090;                   // remembered camera distance (vfunc_7 / vfunc_24)

class Unk_BuffContainer
{
public:
    bool FUN_141682fe0(int nBuffId);
};

class Unk_LocalPlayer
{
public:
    Unk_BuffContainer* FUN_14166d240();             // +0x6d8
};

// The camera option row held by the game context (+0x154 rotation).
struct Unk_CameraOption
{
    char m_pad_000[0x154];
    float m_154;
    char m_pad_158[0x23c - 0x158];
    float m_23c;
};

// Smart pointer to it (pointer at +8).
class Unk_CameraOptionPtr
{
public:
    ~Unk_CameraOptionPtr() { FUN_140885ab0(); }     // 0x1408850f0 (another obj)
    Unk_CameraOption* FUN_1409657a0() const;        // get
    Unk_CameraOption* FUN_140885340() const;        // operator->
    void FUN_140885ab0();                           // release

    void* m_pad_00;
    Unk_CameraOption* m_p;
};

// The game context (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    float FUN_141bd4120();                          // extra zoom range
    Unk_LocalPlayer* FUN_141bd0cc0();
    Unk_CameraOptionPtr FUN_141bd30a0();            // copy of +0x298
    float FUN_141bcfc50();                          // default zoom
};
Unk_GameContext* FUN_1403ed2d0();

// A float table value of the client configuration (FUN_1401d3200).
struct Unk_ConfigFloat
{
    float FUN_1402bac70();
    char m_pad[0x58];
};
struct Unk_ClientConfig
{
    char m_pad_0000[0x1a80];
    Unk_ConfigFloat m_1a80;
    Unk_ConfigFloat m_1ad8;
    Unk_ConfigFloat m_1b30;
};
Unk_ClientConfig* FUN_1401d3200();

// The scene camera (FUN_1413f9890()->FUN_140af7da0()->FUN_140af7df0()) and its frustum.
struct Unk_Frustum
{
    float m_0, m_4, m_8, m_c, m_10;                 // left, right, top, bottom, near
};
class Unk_NiCamera
{
public:
    Unk_Frustum* FUN_1409a8de0();                   // +0x128
};
class Unk_SceneCamera
{
public:
    Unk_NiCamera* FUN_140af7df0();
};
class Unk_SceneRoot
{
public:
    Unk_SceneCamera* FUN_140af7da0();               // m_48
};
Unk_SceneRoot* FUN_1413f9890();

// The collision world (0x143ab50b8).
class Unk_Collision
{
public:
    static Unk_Collision* FUN_1409f7ca0();
    int FUN_14168a230(Vector3 ptFrom, Vector3& ptHit, Vector3 ptDir, float fLen, int nMask);
};

float FUN_14029d220(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f2310(float f);                       // sin
float FUN_141b6fdb0(float t, int nType);            // easing
bool FUN_14028d470(float a, float b);               // a == b (within epsilon)
extern "C" float (__cdecl* __imp_tanf)(float);      // the exe calls tanf through its import
float FUN_140b02b90(float f);                       // acos with the argument clamped to [-1, 1]

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140b64c30
CHomeCameraMode::CHomeCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev),
      m_78(0),
      m_7c(g_143b01a60),
      m_88(g_143b01a60),
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
      m_100(g_143b01a60),
      m_10c(g_143a08cf8)
{
    m_9c = FUN_1403ed2d0()->FUN_141bd4120();
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
    m_100 = static_cast<Unk_CameraManagerData*>(Unk_CameraManager::FUN_1409478c0())->m_c8;
    m_10c = static_cast<Unk_CameraManagerData*>(Unk_CameraManager::FUN_1409478c0())->m_d4;
    m_4c = FUN_140b02b90(m_100.z);
    if (m_b4 == 0)
    {
        m_50 = Unk_CameraManager::FUN_1409478c0()->FUN_140b67d10();
        m_b0 = 0;
        m_b8 = 0.0f;
    }
    if (n == 0)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (pTarget)
        {
            m_88 = pTarget->vfunc_17();
            m_88.z += vfunc_27();
            vfunc_3(m_88.FUN_14097fd50(FUN_140b66660()));
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
        m_f4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
        m_f8 = FUN_1401d3200()->m_1a80.FUN_1402bac70();
        m_fc = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
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
    setting.m_0 = Unk_CameraManager::FUN_1409478c0()->FUN_140ad4b40();
    setting.m_4 = Unk_CameraManager::FUN_1409478c0()->FUN_140af7f00();
    setting.m_8 = Unk_CameraManager::FUN_1409478c0()->FUN_140af7ea0();
    setting.m_c = Unk_CameraManager::FUN_1409478c0()->FUN_140a17e10();
    setting.m_18 = Unk_CameraManager::FUN_1409478c0()->FUN_140af8290();
    static_cast<Unk_CameraManagerData*>(Unk_CameraManager::FUN_1409478c0())->m_e0 = setting;
}
MS2_REPLACE_METHOD(0x140B651D0, CHomeCameraMode, vfunc_7, 222, 0x3F1915D8);

// @0x140b652c0
// MS2-FUNCTIONAL: the exe moves pTarget through rcx first
void CHomeCameraMode::vfunc_10()
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    Unk_CameraManager::FUN_1409478c0()->FUN_140aeaf40(pTarget, 1);
}
MS2_REPLACE_METHOD(0x140B652C0, CHomeCameraMode, vfunc_10, 59, 0x3AEC2CB0);

// @0x140b65310
void CHomeCameraMode::vfunc_8(double fTime)
{
    int nLoop = 100;
    for (int i = 0; i < nLoop; ++i)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (!pTarget)
            break;
        m_88 = pTarget->vfunc_17();
        m_88.z += vfunc_27();

        Vector3 ptPos = g_143b01a60;
        Vector3 ptRot = g_143b01a60;
        if (m_78 == 0)
        {
            Vector3 ptEye = m_88.FUN_14097fd50(FUN_140b66660());
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
            Vector3 ptTarget = m_88;
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

        Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
        if (ptMove.FUN_140552700(g_143b01a60))
        {
            Vector3 ptInput = ptMove;
            float fRate = 15.0f;
            float fStep = FUN_140a17940((float)fTime, 0.0f, 1.0f / fRate);
            float fMax = FUN_140a0fda0(FUN_140a38cd0(ptInput.x),
                                       FUN_140a0fda0(FUN_140a38cd0(ptInput.y), FUN_140a38cd0(ptInput.z)));
            float fScale = fStep * fMax;
            float fZoom = ptInput.x * fScale;
            float fYaw = ptInput.y * fScale;
            float fPitch = ptInput.z * fScale;
            if (fZoom != 0.0f)
            {
                m_94 += fZoom * 2000.0f;
                m_94 = FUN_140a17940(m_94, -150.0f, 150.0f);
            }
            if (fYaw != 0.0f || fPitch != 0.0f)
            {
                m_68 += fYaw;
                Vector3 ptCenter = m_88;
                ptPos = m_c4.m_pos;
                ptPos.z = ptCenter.z;
                Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
                m_50 = ptDist.FUN_140967ac0();
                m_50 = FUN_140a17940(m_50, m_58, m_54 + m_9c);
                ptPos.x = m_50 * m_100.x + ptCenter.x;
                ptPos.y = m_50 * m_100.y + ptCenter.y;
                ptPos.z = m_50 * m_100.z + ptCenter.z;
                if (m_50 > m_58 && m_54 + m_9c > m_50)
                {
                    m_c4.m_pos = ptPos;
                    ptRot = CCameraMode::FUN_140afdd40(ptCenter, m_c4.m_pos, m_10c);
                    m_c4.m_rot = ptRot;
                    FUN_140b66570();
                }
            }
            Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
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
    Unk_LocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer && pPlayer->FUN_14166d240()->FUN_141682fe0(300008))
        ptMove.x = 1.0f;
    else if (pPlayer && pPlayer->FUN_14166d240()->FUN_141682fe0(300009))
        ptMove.x = -1.0f;
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x140B65E70, CHomeCameraMode, vfunc_9, 208, 0x69A99AEA);

// @0x140b65f50
void CHomeCameraMode::vfunc_33()
{
    Unk_CameraOptionPtr spOption = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spOption.FUN_1409657a0())
    {
        float fRotation = spOption.FUN_140885340()->m_154;
        if (Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0())
        {
            vfunc_31();
            vfunc_16(m_a8);
            vfunc_11(m_a4);
            vfunc_12(fRotation);
        }
        else
        {
            vfunc_16(spOption.FUN_140885340()->m_23c);
            vfunc_11(FUN_1403ed2d0()->FUN_141bcfc50());
            vfunc_12(fRotation);
        }
        vfunc_10();
    }
}
MS2_REPLACE_METHOD(0x140B65F50, CHomeCameraMode, vfunc_33, 334, 0x0FD2BF9A);

// @0x140b660b0
void CHomeCameraMode::vfunc_11(float f)
{
    if (Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0())
        f = m_a4;
    m_setting.m_0 = f;
    m_pOwner->FUN_140947940(f);
}
MS2_REPLACE_METHOD(0x140B660B0, CHomeCameraMode, vfunc_11, 92, 0xC0A00B6B);

// @0x140b66120
void CHomeCameraMode::vfunc_16(float f)
{
    m_54 = Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0() ? m_a8 : f;
    if (-1.0f != m_5c)
        m_98 = FUN_140a17940(m_98, m_58, m_54 + m_9c);
}
MS2_REPLACE_METHOD(0x140B66120, CHomeCameraMode, vfunc_16, 172, 0x273C523C);

// @0x140b661e0
void CHomeCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget && n)
    {
        m_c0 = 0;
        m_50 = m_54;
        if (m_ac && g_143abb090 != 0.0f)
            m_50 = g_143abb090;
        m_9c = FUN_1403ed2d0()->FUN_141bd4120();
        m_88 = pTarget->vfunc_17();
        m_88.z += vfunc_27();
        float fAngle = FUN_140b66b10(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
        m_100.z = FUN_1409f2310(fAngle);
        m_c4.m_pos.x = m_50 * m_100.x + m_88.x;
        m_c4.m_pos.y = m_50 * m_100.y + m_88.y;
        m_c4.m_pos.z = m_50 * m_100.z + m_88.z;
        vfunc_3(m_c4.m_pos);
        Vector3 ptRot = CCameraMode::FUN_140afdd40(m_88, m_c4.m_pos, m_10c);
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
    m_7c = m_c4.m_pos.FUN_140965c40(m_88);
}
MS2_REPLACE_METHOD(0x140B66570, CHomeCameraMode, FUN_140b66570, 232, 0x61C01930);

// @0x140b66660
Vector3 CHomeCameraMode::FUN_140b66660()
{
    return m_7c;
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
    if (m_10c.FUN_140552690(g_143a08ce8))
        m_100.z = 1.0f;
    else if (m_10c.FUN_140552690(g_143a08cf8))
        ptPos.z = ptTarget.z;
    float fPrevDist = m_50;
    Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
    m_50 = ptDir.FUN_140967ac0();
    if (bClamp)
        m_50 = FUN_140a17940(m_50, m_58, m_54 + m_9c);
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
    ptRot = CCameraMode::FUN_140afdd40(ptTarget, m_c4.m_pos, m_10c);
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
// MS2-FUNCTIONAL: fDist/fBlend stack slot order differs
void CHomeCameraMode::vfunc_37(double fTime)
{
    float fDist;
    if (m_c0)
    {
        Unk_HomeNiPoint3 ptDiff = m_c4.m_pos.FUN_140965c40(m_dc.m_pos);
        fDist = ptDiff.FUN_140967ac0();
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
                if (m_b8 < 3.0f)
                {
                    fBlend = FUN_141b6fdb0(m_b8 / 3.0f, 3);
                }
                else
                {
                    fBlend = 1.0f;
                    m_b0 = 0;
                }
            }
        }
        else if (!FUN_14028d470(fDist, 0.0f) && fDist <= 10.0f)
        {
            m_b0 = 1;
            m_b8 = 0.0f;
            fBlend = 0.0f;
        }
        if (!FUN_14028d470(fDist, 0.0f))
        {
            float fStep = FUN_14059d930(m_f4) * (float)fTime;
            if (m_f8 != m_fc)
            {
                float fDelta = FUN_14059d930(m_fc - m_f8);
                if (fStep <= fDelta)
                {
                    if (m_fc <= m_f8)
                        m_fc = m_fc + fStep;
                    else
                        m_fc = m_fc - fStep;
                }
                else
                {
                    m_fc = m_f8;
                }
            }
            fBlend = (float)fTime * fDist * m_fc + fBlend;
            if (fBlend <= 1.0f)
            {
                m_dc.m_pos = m_dc.m_pos.FUN_14097fd50(FUN_1409ab5c0(fBlend, m_c4.m_pos.FUN_140965c40(m_dc.m_pos)));
                if (m_dc.m_rot.FUN_140552700(m_c4.m_rot))
                    m_dc.m_rot = CCameraMode::FUN_140afdec0(fBlend, m_dc.m_rot, m_c4.m_rot);
            }
            else
            {
                m_dc = m_c4;
            }
        }
        else
        {
            m_dc = m_c4;
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
    Unk_SceneCamera* pSceneCamera = FUN_1413f9890()->FUN_140af7da0();
    if (pSceneCamera)
    {
        Unk_NiCamera* pCamera = pSceneCamera->FUN_140af7df0();
        if (pCamera)
        {
            Unk_NiMatrix3 kRot;
            Unk_NiMatrix3 kX;
            Unk_NiMatrix3 kY;
            Unk_NiMatrix3 kZ;
            kX.FUN_142084b30(ptRot.x * -0.0174532924f);
            kY.FUN_142084ba0(ptRot.y * -0.0174532924f);
            kZ.FUN_142084c10(ptRot.z * -0.0174532924f);
            kRot = kX.FUN_140a33480(kY).FUN_140a33480(kZ);
            Vector3 kDir;
            Vector3 kUp;
            Vector3 kRight;
            kRot.FUN_140a01190(0, kDir);
            kRot.FUN_140a01190(1, kUp);
            kRot.FUN_140a01190(2, kRight);
            Unk_Frustum* pFrustum = pCamera->FUN_1409a8de0();
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
                Vector3 ptDir = m_88.FUN_140965c40(aptCorner[i]);
                float fLen = ptDir.FUN_140968990();
                Vector3 ptBack = ptDir.FUN_1409f7960();
                Vector3 ptHit = g_143b01a60;
                if (Unk_Collision::FUN_1409f7ca0()->FUN_14168a230(aptCorner[i], ptHit, ptDir, fLen, 0x209) == 0)
                {
                    if (Unk_Collision::FUN_1409f7ca0()->FUN_14168a230(m_88, ptHit, ptBack, fLen, 0x209))
                        return 1;
                }
                else
                {
                    Vector3 ptHit2 = g_143b01a60;
                    if (Unk_Collision::FUN_1409f7ca0()->FUN_14168a230(ptHit, ptHit2, ptBack, fLen, 0x209))
                        return 1;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140B671A0, CHomeCameraMode, vfunc_38, 2720, 0xC51335A7);

// @0x140b67d10
float Unk_CameraManager::FUN_140b67d10()
{
    if (static_cast<Unk_CameraManagerData*>(this)->m_118.get())
        return static_cast<Unk_CameraManagerData*>(this)->m_118->vfunc_17();
    return 0.0f;
}
MS2_REPLACE_METHOD(0x140B67D10, Unk_CameraManager, FUN_140b67d10, 86, 0x4EECFEFC);

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
