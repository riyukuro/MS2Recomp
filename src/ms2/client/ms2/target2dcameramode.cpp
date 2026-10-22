// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See target2dcameramode.h.
// MS2-UNIT: ?\target2dcameramode.cpp
// MS2-RANGE: 0x1418379e0-0x14183a020 .text$mn
// The exe's memcpy_s copy is a plain call (no /Oi expansion): the pragma must precede the inline definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\target2dcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "target2dcameramode.h"
#include "homecameramode.h"     // Unk_HomeNiPoint3: the NiPoint3 conversion ctor 0x14027dcf0

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z

// The input state (FUN_14025e7c0).
class Unk_InputState
{
public:
    bool FUN_14116d950(int nKey, bool b, int n);     // key held
    bool FUN_14116d9c0(int nKey, bool b, int n);     // key pressed
};
Unk_InputState* FUN_14025e7c0();

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

// The game context (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    Unk_LocalPlayer* FUN_141bd0cc0();
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

float FUN_14029d220(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1418379e0
CTarget2DCameraMode::CTarget2DCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev),
      m_78(g_143b01a60),
      m_84(0.0f),
      m_88(0),
      m_98(0.0f),
      m_dc(0)
{
}

// @0x141837b00
CTarget2DCameraMode::~CTarget2DCameraMode()
{
}
MS2_REPLACE_DTOR(0x141837B00, CTarget2DCameraMode, 39, 0x967F1291);

// @0x141837b30
void CTarget2DCameraMode::vfunc_8(double fTime)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (!pTarget)
        return;
    {
        m_78 = pTarget->vfunc_18();
        m_78.z += vfunc_27();

        Vector3 ptPos = g_143b01a60;
        Vector3 ptRot = g_143b01a60;
        if (m_88 == 0)
        {
            Vector3 ptEye = m_78.FUN_14097fd50(FUN_141839600());
            m_c0.m_pos = ptEye;
        }

        if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) > 5.0f)
        {
            if (m_98 < m_50)
                m_84 = 10.0f;
            else if (m_98 > m_50)
                m_84 = -10.0f;
        }
        if (m_84 >= 5.0f || m_84 <= -5.0f)
        {
            m_88 = 1;
            if (m_dc == 0)
                m_84 = m_84 * 0.9f;
            ptPos = m_c0.m_pos;
            Vector3 ptTarget = m_78;
            Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
            ptDir.FUN_140968990();
            ptPos = ptPos.FUN_14097fd50(ptDir.FUN_14097fc90(m_84));
            if (m_50 < m_58 || m_50 > m_54)
            {
            }
            else
            {
                if (m_50 >= m_58 && m_50 <= m_54)
                {
                    m_6c = FUN_1418398e0(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
                    ptPos.z = ptTarget.z;
                    Vector3 ptDist = ptTarget.FUN_140965c40(ptPos);
                    m_50 = ptDist.FUN_140967ac0();
                    m_50 = FUN_140a17940(m_50, m_58, m_54);
                    if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) <= 5.0f)
                    {
                        m_50 = m_98;
                        m_5c = -1.0f;
                        m_84 = 0.0f;
                    }
                    ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptTarget.x;
                    ptPos.y = m_50 * FUN_1409f2310(m_68) + ptTarget.y;
                    ptPos.z = ptTarget.z;
                    m_c0.m_pos = ptPos;
                    ptRot = CCameraMode::FUN_140afdd40(ptTarget, m_c0.m_pos, g_143a08cf8);
                    m_c0.m_rot = ptRot;
                }
                else
                {
                    m_c0.m_pos = ptPos;
                }
            }
        }
        else if (m_88)
        {
            m_84 = 0.0f;
            m_88 = 0;
            vfunc_37();
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
                m_84 += fZoom * 2000.0f;
                m_84 = FUN_140a17940(m_84, -150.0f, 150.0f);
            }
            if (fYaw != 0.0f || fPitch != 0.0f)
            {
                m_68 += fYaw;
                Vector3 ptCenter = m_78;
                ptPos = m_c0.m_pos;
                ptPos.z = ptCenter.z;
                Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
                m_50 = ptDist.FUN_140967ac0();
                m_50 = FUN_140a17940(m_50, m_58, m_54);
                m_6c -= fPitch;
                if (0.15f >= m_6c)
                    m_6c = 0.15f;
                if (1.57f <= m_6c)
                    m_6c = 1.57f;
                ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
                ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
                ptPos.z = ptCenter.z;
                if (m_50 > m_58 && m_50 < m_54)
                {
                    m_c0.m_pos = ptPos;
                    ptRot = CCameraMode::FUN_140afdd40(ptCenter, m_c0.m_pos, g_143a08cf8);
                    m_c0.m_rot = ptRot;
                    vfunc_37();
                }
            }
            Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
        }
        FUN_1418399e0(fTime);
        m_setting.m_c = m_c0.m_pos;
        m_setting.m_18 = m_c0.m_rot;
    }
}
MS2_REPLACE_METHOD(0x141837B30, CTarget2DCameraMode, vfunc_8, 2881, 0xDC1B36B3);

// @0x141838680
void CTarget2DCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    if (FUN_14025e7c0()->FUN_14116d950(5, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0))
        ptMove.z = 1.0f;
    else if (FUN_14025e7c0()->FUN_14116d950(6, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0))
        ptMove.z = -1.0f;
    if (FUN_14025e7c0()->FUN_14116d950(7, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0))
        ptMove.y = -1.0f;
    else if (FUN_14025e7c0()->FUN_14116d950(8, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0))
        ptMove.y = 1.0f;
    Unk_LocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer && pPlayer->FUN_14166d240()->FUN_141682fe0(300008))
        ptMove.x = 1.0f;
    else if (pPlayer && pPlayer->FUN_14166d240()->FUN_141682fe0(300009))
        ptMove.x = -1.0f;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x14, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0))
        vfunc_18(m_60 + 5.0f, m_64 + 5.0f);
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x15, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0))
        vfunc_18(m_60 - 5.0f, m_64 - 5.0f);
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x141838680, CTarget2DCameraMode, vfunc_9, 758, 0x61807757);

// @0x141838980
void CTarget2DCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget)
        vfunc_24(pTarget, 1);
    m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
    m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
    m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
}
MS2_REPLACE_METHOD(0x141838980, CTarget2DCameraMode, vfunc_6, 184, 0x5FFD709D);

// @0x141838a40
float CTarget2DCameraMode::vfunc_22()
{
    return m_6c;
}
MS2_REPLACE_METHOD(0x141838A40, CTarget2DCameraMode, vfunc_22, 16, 0x33EB21D2);

// @0x141838a60
float CTarget2DCameraMode::vfunc_23()
{
    return m_68;
}
MS2_REPLACE_METHOD(0x141838A60, CTarget2DCameraMode, vfunc_23, 16, 0x1BE201AE);

// @0x141838a80
Unk_CameraTargetEntity* CTarget2DCameraMode::vfunc_25()
{
    return Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
}
MS2_REPLACE_METHOD(0x141838A80, CTarget2DCameraMode, vfunc_25, 27, 0xA62E4F3A);

// @0x141838ab0
void CTarget2DCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget && n)
    {
        m_d8 = 0;
        m_68 = 3.14159265f;
        m_6c = m_4c;
        m_50 = m_54;
        m_78 = pTarget->vfunc_17();
        m_78.z += vfunc_27();
        float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
        float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
        float fZ = m_78.z;
        m_c0.m_pos = Vector3(fX, fY, fZ);
        vfunc_3(Vector3(fX, fY, fZ));
        Vector3 ptRot = CCameraMode::FUN_140afdd40(m_78, m_c0.m_pos, g_143a08cf8);
        vfunc_4(ptRot);
        m_c0.m_rot = ptRot;
        vfunc_37();
    }
}
MS2_REPLACE_METHOD(0x141838AB0, CTarget2DCameraMode, vfunc_24, 691, 0x2C89D0CB);

// @0x141838d70
Vector3 CTarget2DCameraMode::vfunc_26()
{
    vfunc_24(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60(), 1);
    return m_78.FUN_14097fd50(FUN_141839600());
}
MS2_REPLACE_METHOD(0x141838D70, CTarget2DCameraMode, vfunc_26, 112, 0x085F33EE);

// @0x141838df0
// MS2-FUNCTIONAL: the exe moves pTarget through rcx first (mov rcx,[rsp+20h]; mov rdx,rcx)
void CTarget2DCameraMode::vfunc_10()
{
    m_d8 = 0;
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    Unk_CameraManager::FUN_1409478c0()->FUN_140aeaf40(pTarget, 1);
}
MS2_REPLACE_METHOD(0x141838DF0, CTarget2DCameraMode, vfunc_10, 74, 0x6F58486D);

// @0x141838e40
float CTarget2DCameraMode::vfunc_27()
{
    float fRange = m_54 - m_58;
    float fHeight = m_64;
    if (fRange > 0.0f)
        fHeight = m_64 + (m_60 - m_64) * ((m_50 - m_58) / fRange);
    return fHeight;
}
MS2_REPLACE_METHOD(0x141838E40, CTarget2DCameraMode, vfunc_27, 147, 0xCF35E811);

// @0x141838ee0
void CTarget2DCameraMode::vfunc_3(Vector3 pt)
{
    if (pt.FUN_140552700(m_setting.m_c))
    {
        m_d8 = 0;
        m_setting.m_c = pt;
        m_pOwner->FUN_140a38dc0(pt);
    }
}
MS2_REPLACE_METHOD(0x141838EE0, CTarget2DCameraMode, vfunc_3, 128, 0x198561E9);

// @0x141838f70
void CTarget2DCameraMode::vfunc_4(Vector3 pt)
{
    if (pt.FUN_140552700(m_setting.m_18))
    {
        m_d8 = 0;
        m_setting.m_18 = pt;
        m_pOwner->FUN_140a38e00(pt);
    }
}
MS2_REPLACE_METHOD(0x141838F70, CTarget2DCameraMode, vfunc_4, 128, 0x46FE3B0A);

// @0x141839000
void CTarget2DCameraMode::vfunc_21(float f, int n)
{
    m_98 = m_54 - m_58;
    m_98 = m_58 + m_98 * f;
    m_98 = FUN_140a17940(m_98, m_58, m_54);
    if (m_98 == m_50)
        return;
    if (n)
    {
        bool bDone = false;
        float fStep = m_98 > m_50 ? -10.0f : 10.0f;
        Vector3 ptPos = FUN_1409f2540();
        Vector3 ptRot;
        Vector3 ptCenter = g_143b01a60;
        unsigned int nLoop = 0;
        while (!bDone)
        {
            m_78 = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60()->vfunc_17();
            m_78.z += vfunc_27();
            ptCenter = m_78;
            Vector3 ptDir = ptCenter.FUN_140965c40(ptPos);
            ptDir.FUN_140968990();
            ptPos = ptPos.FUN_14097fd50(ptDir.FUN_14097fc90(fStep));
            m_6c = FUN_1418398e0(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
            ptPos.z = ptCenter.z;
            Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
            m_50 = ptDist.FUN_140967ac0();
            m_50 = FUN_140a17940(m_50, m_58, m_54);
            ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
            ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
            ptPos.z = ptCenter.z;
            if (FUN_14029d220(m_98 - m_50) <= 1.0f)
            {
                m_50 = m_98;
                m_c0.m_pos = ptPos;
                vfunc_3(ptPos);
                ptRot = CCameraMode::FUN_140afdd40(ptCenter, ptPos, g_143a08cf8);
                m_c0.m_rot = ptRot;
                vfunc_4(ptRot);
                m_78 = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60()->vfunc_17();
                m_78.z += vfunc_27();
                vfunc_37();
                break;
            }
            ++nLoop;
            if (nLoop > 1000)
                break;
        }
    }
    else
    {
        m_5c = f;
    }
}
MS2_REPLACE_METHOD(0x141839000, CTarget2DCameraMode, vfunc_21, 1488, 0xD0976145);

// @0x141839600
Vector3 CTarget2DCameraMode::FUN_141839600()
{
    return m_8c;
}
MS2_REPLACE_METHOD(0x141839600, CTarget2DCameraMode, FUN_141839600, 44, 0xE877299E);

// @0x141839640
bool CTarget2DCameraMode::FUN_141839640(Vector3& ptPos, Vector3& ptRot)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget)
    {
        float fYaw = 3.14159265f;
        float fDist = Unk_CameraManager::FUN_1409478c0()->FUN_140b67d10();
        Vector3 ptTarget = pTarget->vfunc_17();
        ptTarget.z += Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0()->vfunc_27();
        float fX = fDist * FUN_1409f25a0(fYaw) + ptTarget.x;
        float fY = fDist * FUN_1409f2310(fYaw) + ptTarget.y;
        float fZ = ptTarget.z;
        ptPos = Vector3(fX, fY, fZ);
        ptRot = CCameraMode::FUN_140afdd40(ptTarget, ptPos, g_143a08cf8);
        return true;
    }
    return false;
}
MS2_REPLACE(0x141839640, CTarget2DCameraMode::FUN_141839640, 342, 0xE95CC76B);

// @0x1418397a0
Unk_CameraSetting CTarget2DCameraMode::FUN_1418397a0(Unk_CameraSetting setting)
{
    FUN_141839640(setting.m_c, setting.m_18);
    return setting;
}
MS2_REPLACE(0x1418397A0, CTarget2DCameraMode::FUN_1418397a0, 65, 0x89070AEE);

// @0x1418397f0
void CTarget2DCameraMode::vfunc_37()
{
    float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
    float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
    float fZ = m_78.z;
    m_c0.m_pos = Vector3(fX, fY, fZ);
    m_8c = m_c0.m_pos.FUN_140965c40(m_78);
}
MS2_REPLACE_METHOD(0x1418397F0, CTarget2DCameraMode, vfunc_37, 231, 0x1834ACDB);

// @0x1418398e0
float CTarget2DCameraMode::FUN_1418398e0(float fMin, float fCur, float fMax, float fDegMin, float fDegMax)
{
    float t = fCur - fMin;
    t /= fMax - fMin;
    float fDegree = (fDegMin - fDegMax) * t;
    fDegree = fDegMax + fDegree;
    return fDegree * 3.14159265f / 180.0f;
}
MS2_REPLACE_METHOD(0x1418398E0, CTarget2DCameraMode, FUN_1418398e0, 141, 0xA7F9A062);

// @0x141839980
void CTarget2DCameraMode::vfunc_29(float f1, float f2, float f3)
{
    m_9c = f1;
    m_a0 = f2;
    m_a4 = f3;
}
MS2_REPLACE_METHOD(0x141839980, CTarget2DCameraMode, vfunc_29, 81, 0x51FF0508);

// @0x1418399e0
void CTarget2DCameraMode::FUN_1418399e0(double fTime)
{
    if (m_d8)
    {
        Unk_HomeNiPoint3 ptDelta = m_c0.m_pos.FUN_140965c40(m_a8.m_pos);
        float fLen = ptDelta.FUN_140967ac0();
        if (fLen <= 1.0f)
        {
            m_a8 = m_c0;
        }
        else
        {
            float fSpeed = FUN_14059d930(m_a4) * (float)fTime;
            if (m_a0 != m_9c)
            {
                if (FUN_14059d930(m_a0 - m_9c) < fSpeed)
                {
                    m_a0 = m_9c;
                }
                else
                {
                    if (m_a0 > m_9c)
                        m_a0 = m_a0 - fSpeed;
                    else
                        m_a0 = m_a0 + fSpeed;
                }
            }
            float fRate = (float)fTime * fLen * m_a0;
            if (fRate > 1.0f)
            {
                m_a8 = m_c0;
            }
            else
            {
                m_a8.m_pos = m_a8.m_pos.FUN_14097fd50(FUN_1409ab5c0(fRate, m_c0.m_pos.FUN_140965c40(m_a8.m_pos)));
                m_a8.m_rot = m_a8.m_rot.FUN_14097fd50(FUN_1409ab5c0(fRate, m_c0.m_rot.FUN_140965c40(m_a8.m_rot)));
            }
        }
    }
    else
    {
        m_a8 = m_c0;
        m_d8 = 1;
        m_dc = 0;
    }
    m_setting.m_c = m_a8.m_pos;
    m_setting.m_18 = m_a8.m_rot;
    m_pOwner->FUN_140a38dc0(m_a8.m_pos);
    m_pOwner->FUN_140a38e00(m_a8.m_rot);
}
MS2_REPLACE_METHOD(0x1418399E0, CTarget2DCameraMode, FUN_1418399e0, 1022, 0xDA368F42);

// @0x141839de0
Unk_Target2DPose::Unk_Target2DPose()
    : m_rot(g_143b01a60),
      m_pos(g_143b01a60)
{
}
MS2_REPLACE_CTOR(0x141839DE0, Unk_Target2DPose, 63, 0x01CFEB53);

// @0x141839e20
Unk_Target2DPose& Unk_Target2DPose::operator=(const Unk_Target2DPose& o)
{
    m_rot = o.m_rot;
    m_pos = o.m_pos;
    return *this;
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, like memmove_s).
// @0x141839ed0
static __inline errno_t ms2_memcpy_s_copy(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
