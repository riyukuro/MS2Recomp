// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See targetlookcentercameramode.h.
// MS2-UNIT: ?\targetlookcentercameramode.cpp
// MS2-RANGE: 0x140a4c470-0x140a4e690 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\targetlookcentercameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "targetlookcentercameramode.h"

#include <math.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z
extern float g_143aef240;                   // remembered camera distance (vfunc_24)

// The game context (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    float FUN_141bd4120();                          // extra zoom range
};
Unk_GameContext* FUN_1403ed2d0();

float FUN_14029d220(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
float FUN_141b6fdb0(float t, int nType);            // easing
bool FUN_14028d470(float a, float b);               // a == b (within epsilon)
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)
float FUN_140ae8910(CString key);                   // float value of the camera xml key
unsigned int FUN_140869420();                       // tick count

inline float FUN_140a4e660(float fY, float fX);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140a4c470
CTargetLookCenterCameraMode::CTargetLookCenterCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CTargetCameraMode(pOwner, pPrev),
      m_10c(100.0f),
      m_110(false),
      m_114(),
      m_120(0.0f),
      m_124(0.0f),
      m_12c(false),
      m_12d(false),
      m_130(0),
      m_134(1500),
      m_138(0.03f),
      m_13c(0.0f)
{
    m_114 = Vector3(850.0f, -1150.0f, 1950.0f);
}

// @0x140a4c5e0
CTargetLookCenterCameraMode::~CTargetLookCenterCameraMode()
{
}

// @0x140a4c610
void CTargetLookCenterCameraMode::vfunc_6(int n)
{
    CTargetCameraMode::vfunc_6(n);
}
MS2_REPLACE_METHOD(0x140a4c610, CTargetLookCenterCameraMode, vfunc_6, 32, 0x2A579A95);

// @0x140a4c640
void CTargetLookCenterCameraMode::vfunc_9()
{
    CTargetCameraMode::vfunc_9();
}
MS2_REPLACE_METHOD(0x140a4c640, CTargetLookCenterCameraMode, vfunc_9, 24, 0x68D47921);

// @0x140a4c660
void CTargetLookCenterCameraMode::vfunc_8(double fTime)
{
    Vector3 ptPrevTarget = m_78;
    Vector3 ptPrevPos = m_d8.m_pos;
    const int nMaxLoop = 100;
    int nLoop = 1;
    for (int i = 0; i < nLoop && i < 100; ++i)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (!pTarget)
            return;
        m_78 = pTarget->vfunc_17();
        m_78.z += vfunc_27();

        Vector3 ptPos = g_143b01a60;
        Vector3 ptRot = g_143b01a60;
        if (m_88 == 0)
        {
            Vector3 ptEye = m_78.FUN_14097fd50(FUN_14183c370());
            m_d8.m_pos = ptEye;
        }

        bool bZoom = false;
        if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) > 5.0f)
        {
            bZoom = true;
            if (m_98 < m_50)
                m_84 = 10.0f;
            else if (m_98 > m_50)
                m_84 = -10.0f;
            if (m_50 > m_54)
                m_84 = m_84 * m_b8;
        }
        if (bZoom || FUN_14029d220(m_84) >= 5.0f)
        {
            m_88 = 1;
            if (m_f4 == 0)
                m_84 = m_84 * 0.9f;
            ptPos = m_d8.m_pos;
            Vector3 ptTarget = m_78;
            Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
            ptDir.FUN_140968990();
            ptPos.FUN_140a4e560(ptDir.FUN_14097fc90(m_84));
            float fTargetMove = FUN_140966ea0(ptPrevTarget, m_78);
            float fPosMove = FUN_140966ea0(ptPrevPos, ptPos);
            if (fTargetMove > fPosMove)
                ++nLoop;
            if (m_50 < m_58 || m_54 + m_b4 < m_50)
            {
                if ((0.0f < m_84 && m_54 + m_b4 < m_50) || (0.0f > m_84 && m_50 < m_58))
                    FUN_14183bfd0(ptPos, ptRot, ptTarget, false);
                else
                    FUN_14183bfd0(ptPos, ptRot, ptTarget, true);
            }
            else if (m_50 >= m_58 && m_54 + m_b4 >= m_50)
            {
                FUN_14183bfd0(ptPos, ptRot, ptTarget, true);
            }
            else
            {
                m_d8.m_pos = ptPos;
            }
        }
        else if (m_88)
        {
            m_84 = 0.0f;
            m_88 = 0;
        }
        FUN_140a4d5f0(fTime);

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
                ptPos = m_d8.m_pos;
                ptPos.z = ptCenter.z;
                Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
                m_50 = ptDist.FUN_140967ac0();
                m_50 = FUN_140a17940(m_50, m_58, m_54 + m_b4);
                m_6c -= fPitch;
                if (0.15f >= m_6c)
                    m_6c = 0.15f;
                if (1.57f <= m_6c)
                    m_6c = 1.57f;
                ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
                ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
                ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptCenter.z;
                if (m_50 > m_58 && m_54 + m_b4 > m_50)
                {
                    m_d8.m_pos = ptPos;
                    ptRot = CCameraMode::FUN_140afdd40(ptCenter, m_d8.m_pos, g_143a08cf8);
                    m_d8.m_rot = ptRot;
                    FUN_140a4d5f0(fTime);
                }
            }
            Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
        }
        vfunc_39(fTime);
        if (m_f4)
            ++nLoop;
    }
}
MS2_REPLACE_METHOD(0x140a4c660, CTargetLookCenterCameraMode, vfunc_8, 3258, 0x8AF7F329);

// @0x140a4d320
BOOL CTargetLookCenterCameraMode::vfunc_31()
{
    if (FUN_140ae8540())
    {
        m_10c = FUN_140ae8910("Console_RotationInterpolateSpeed");
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE_METHOD(0x140a4d320, CTargetLookCenterCameraMode, vfunc_31, 88, 0xCC6A26DB);

// @0x140a4d380
void CTargetLookCenterCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget && n)
    {
        m_f0 = 0;
        m_50 = m_54;
        if (m_bc && g_143aef240 != 0.0f)
            m_50 = g_143aef240;
        m_b4 = FUN_1403ed2d0()->FUN_141bd4120();
        m_68 = m_48;
        m_6c = FUN_14183ce10(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
        m_78 = pTarget->vfunc_17();
        m_78.z += vfunc_27();
        FUN_140a4d5f0(0.0);
        vfunc_3(m_d8.m_pos);
        vfunc_4(m_d8.m_rot);
        m_fc = 0;
        m_100 = 0.0f;
    }
}
MS2_REPLACE_METHOD(0x140a4d380, CTargetLookCenterCameraMode, vfunc_24, 615, 0xB948409E);

// @0x140a4d5f0
void CTargetLookCenterCameraMode::FUN_140a4d5f0(double fTime)
{
    Vector3 ptDir = m_78.FUN_140965c40(m_114);
    ptDir.z = 0.0f;
    ptDir.FUN_140968990();
    m_13c = m_68;
    if (m_110)
    {
        if (FUN_140a4e220())
        {
            m_68 = m_128;
        }
        else if (!FUN_140a4e240())
        {
            m_68 = FUN_140a4e660(ptDir.x, ptDir.y);
        }
    }
    FUN_140a4e490(&m_68);
    float fEps = 0.01f;
    if (FUN_140a4e370() && fTime != 0.0 && FUN_14059d930(m_13c - m_68) > 0.01f)
    {
        float fPrev = m_13c;
        float fCur = m_68;
        float fA;
        float fB;
        if (fCur < fPrev)
        {
            fA = (6.2831855f - fPrev) + fCur;
            fB = fPrev - fCur;
        }
        else
        {
            fA = fCur - fPrev;
            fB = (6.2831855f - fCur) + fPrev;
        }
        float fSpeed = 3.0f;
        if (FUN_140a4e3e0())
            m_68 = (float)((double)m_13c + fTime * 3.0);
        else
            m_68 = (float)((double)m_13c - fTime * 3.0);
        FUN_140a4e490(&m_68);
    }
    float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
    float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
    float fZ = m_50 * FUN_1409f2310(m_6c) + m_78.z;
    m_d8.m_pos = Vector3(fX, fY, fZ);
    m_8c = m_d8.m_pos.FUN_140965c40(m_78);
    Vector3 pose = CCameraMode::FUN_140afdd40(m_78, m_d8.m_pos, g_143a08cf8);
    m_d8.m_rot = pose;
}
MS2_REPLACE_METHOD(0x140a4d5f0, CTargetLookCenterCameraMode, FUN_140a4d5f0, 1049, 0xDC61BE42);

// @0x140a4da10
void CTargetLookCenterCameraMode::vfunc_39(double fTime)
{
    if (m_f0)
    {
        Unk_NiPoint3 ptDelta(m_d8.m_pos.FUN_140965c40(m_c0.m_pos));
        float fDist = ptDelta.FUN_140967ac0();
        float fBlend = 0.0f;
        if (m_fc)
        {
            if (fDist >= 10.0f)
            {
                m_fc = 0;
            }
            else
            {
                m_100 = (float)(m_100 + fTime);
                if (3.0f <= m_100)
                {
                    fBlend = 1.0f;
                    m_fc = 0;
                }
                else
                {
                    fBlend = FUN_141b6fdb0(m_100 / 3.0f, 3);
                }
            }
        }
        else if (!FUN_14028d470(fDist, 0.0f) && fDist <= 10.0f)
        {
            m_fc = 1;
            m_100 = 0.0f;
            fBlend = 0.0f;
        }
        if (FUN_14028d470(fDist, 0.0f))
        {
            m_c0 = m_d8;
        }
        else
        {
            float fSpeed = FUN_14059d930(m_a4) * (float)fTime;
            if (m_a0 != m_9c)
            {
                if (FUN_14059d930(m_a0 - m_9c) < fSpeed)
                    m_a0 = m_9c;
                else if (m_a0 > m_9c)
                    m_a0 = m_a0 - fSpeed;
                else
                    m_a0 = m_a0 + fSpeed;
            }
            float t = (float)fTime * fDist * m_a0 + fBlend;
            if (t > 0.5f && !FUN_140a4e370())
            {
                m_c0 = m_d8;
            }
            else
            {
                m_c0.m_pos = m_c0.m_pos.FUN_14097fd50(FUN_1409ab5c0(t, m_d8.m_pos.FUN_140965c40(m_c0.m_pos)));
                if (m_c0.m_rot.FUN_140552700(m_d8.m_rot))
                    m_c0.m_rot = CCameraMode::FUN_140afdec0(t, m_c0.m_rot, m_d8.m_rot);
            }
        }
        m_f4 = vfunc_38(m_c0.m_pos, m_c0.m_rot);
        if (m_f4)
            m_84 = -10.0f;
    }
    else
    {
        m_c0 = m_d8;
        m_f0 = 1;
        m_f4 = 0;
    }
    vfunc_3(m_c0.m_pos);
    vfunc_4(m_c0.m_rot);
}
MS2_REPLACE_METHOD(0x140a4da10, CTargetLookCenterCameraMode, vfunc_39, 1451, 0x30C4D227);

// @0x140a4dfd0
void CTargetLookCenterCameraMode::vfunc_3(Vector3 pt)
{
    if (pt.FUN_140552700(m_setting.m_c))
    {
        m_setting.m_c = pt;
        m_pOwner->FUN_140a38dc0(pt);
    }
}
MS2_REPLACE_METHOD(0x140a4dfd0, CTargetLookCenterCameraMode, vfunc_3, 113, 0x344F33C7);

// @0x140a4e050
void CTargetLookCenterCameraMode::vfunc_4(Vector3 pt)
{
    if (pt.FUN_140552700(m_setting.m_18))
    {
        m_setting.m_18 = pt;
        m_pOwner->FUN_140a38e00(pt);
    }
}
MS2_REPLACE_METHOD(0x140a4e050, CTargetLookCenterCameraMode, vfunc_4, 113, 0xA640E6FF);

// @0x140a4e0d0
void CTargetLookCenterCameraMode::FUN_140a4e0d0(const Vector3& ptCenter)
{
    m_110 = true;
    m_114 = ptCenter;
}
MS2_REPLACE_METHOD(0x140a4e0d0, CTargetLookCenterCameraMode, FUN_140a4e0d0, 55, 0xB1D01578);

// @0x140a4e110
void CTargetLookCenterCameraMode::FUN_140a4e110(float fAngle)
{
    m_128 = fAngle;
    FUN_140a4e3b0();
}
MS2_REPLACE_METHOD(0x140a4e110, CTargetLookCenterCameraMode, FUN_140a4e110, 49, 0x7BF83896);

// @0x140a4e150
void CTargetLookCenterCameraMode::FUN_140a4e150(float f)
{
    m_124 = f;
}
MS2_REPLACE_METHOD(0x140a4e150, CTargetLookCenterCameraMode, FUN_140a4e150, 31, 0xC7953429);

// @0x140a4e180
void CTargetLookCenterCameraMode::FUN_140a4e180(bool b)
{
    if (!m_12c && b == true)
        FUN_140a4e3b0();
    m_12c = b;
}
MS2_REPLACE_METHOD(0x140a4e180, CTargetLookCenterCameraMode, FUN_140a4e180, 70, 0x6F50E6D0);

// @0x140a4e1d0
void CTargetLookCenterCameraMode::FUN_140a4e1d0(float f)
{
    m_120 = f;
}
MS2_REPLACE_METHOD(0x140a4e1d0, CTargetLookCenterCameraMode, FUN_140a4e1d0, 31, 0x623189B5);

// @0x140a4e200
void CTargetLookCenterCameraMode::FUN_140a4e200(bool b)
{
    m_12d = b;
}
MS2_REPLACE_METHOD(0x140a4e200, CTargetLookCenterCameraMode, FUN_140a4e200, 26, 0x9F6E2567);

// @0x140a4e220
bool CTargetLookCenterCameraMode::FUN_140a4e220()
{
    return m_12d;
}
MS2_REPLACE_METHOD(0x140a4e220, CTargetLookCenterCameraMode, FUN_140a4e220, 18, 0xB0F2DC67);

// @0x140a4e240
bool CTargetLookCenterCameraMode::FUN_140a4e240()
{
    Unk_Point2 ptEye(m_78.x, m_78.y);
    Unk_Point2 ptCenter(m_114.x, m_114.y);
    if (m_124 != 0.0f)
    {
        float fDist = ptEye.FUN_140a4e500(ptCenter).FUN_140a4e630();
        if (fDist > m_124 * m_124)
            return false;
    }
    if (!m_12c)
        return true;
    if (m_120 != 0.0f)
    {
        float fDist = ptEye.FUN_140a4e500(ptCenter).FUN_140a4e630();
        if (fDist < m_120 * m_120)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140a4e240, CTargetLookCenterCameraMode, FUN_140a4e240, 286, 0x4F1A9235);

// @0x140a4e370
bool CTargetLookCenterCameraMode::FUN_140a4e370()
{
    unsigned int now = FUN_140869420();
    if (now < m_130 + m_134)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140a4e370, CTargetLookCenterCameraMode, FUN_140a4e370, 57, 0x85A7E535);

// @0x140a4e3b0
void CTargetLookCenterCameraMode::FUN_140a4e3b0()
{
    m_130 = FUN_140869420();
}
MS2_REPLACE_METHOD(0x140a4e3b0, CTargetLookCenterCameraMode, FUN_140a4e3b0, 30, 0x110E1B17);

// @0x140a4e3e0
bool CTargetLookCenterCameraMode::FUN_140a4e3e0()
{
    float fPrev = m_13c;
    float fCur = m_68;
    float fA;
    float fB;
    if (fCur < fPrev)
    {
        fA = (6.2831855f - fPrev) + fCur;
        fB = fPrev - fCur;
    }
    else
    {
        fA = fCur - fPrev;
        fB = (6.2831855f - fCur) + fPrev;
    }
    if (fA < fB)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140a4e3e0, CTargetLookCenterCameraMode, FUN_140a4e3e0, 165, 0xC73F4930);

// @0x140a4e490
void CTargetLookCenterCameraMode::FUN_140a4e490(float* pfAngle)
{
    while (*pfAngle > 6.2831855f)
        *pfAngle = *pfAngle - 6.2831855f;
    while (*pfAngle < 0.0f)
        *pfAngle = *pfAngle + 6.2831855f;
}
MS2_REPLACE_METHOD(0x140a4e490, CTargetLookCenterCameraMode, FUN_140a4e490, 98, 0xCFFC24E1);

// @0x140a4e500
Unk_Point2 Unk_Point2::FUN_140a4e500(const Unk_Point2& pt) const
{
    Unk_Point2 r = *this;
    r.x -= pt.x;
    r.y -= pt.y;
    return r;
}

// @0x140a4e560
Vector3& Vector3::FUN_140a4e560(const Vector3& pt)
{
    x = x + pt.x;
    y = y + pt.y;
    z = z + pt.z;
    return *this;
}

// @0x140a4e630
float Unk_Point2::FUN_140a4e630() const
{
    return x * x + y * y;
}

// @0x140a4e660
// MS2-FUNCTIONAL: exe calls atan2f through an import thunk
inline float FUN_140a4e660(float fY, float fX)
{
    return atan2f(fY, fX);
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140a4e560, Vector3, FUN_140a4e560, 103, 0xF0625B3A);
MS2_REPLACE_METHOD(0x140a4e630, Unk_Point2, FUN_140a4e630, 48, 0xD7D57138);
MS2_REPLACE(0x140a4e660, FUN_140a4e660, 39, 0x14F80A4A);

