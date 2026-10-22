// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See targetcameramode.h.
// MS2-UNIT: ?\targetcameramode.cpp
// MS2-RANGE: 0x14183a020-0x14183e270 .text$mn
// MS2-PIN: memmove_s 0x14183e150
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\targetcameramode.cpp"
// The exe's memmove_s copy is a plain call (no /Oi expansion): the pragma must precede the inline definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "targetcameramode.h"

#include <math.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z
extern float g_143aef240;                   // remembered camera distance (vfunc_7 / vfunc_24)

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

// The camera option row held by the game context (+0x154 rotation, +0x23c distance).
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
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
float FUN_141b6fdb0(float t, int nType);            // easing
bool FUN_14028d470(float a, float b);               // a == b (within epsilon)
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14183a020
CTargetCameraMode::CTargetCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev),
      m_78(g_143b01a60),
      m_84(0.0f),
      m_88(0),
      m_8c(g_143b01a60),
      m_98(0.0f),
      m_9c(0.0f),
      m_a0(0.0f),
      m_a4(0.0f),
      m_a8(0.0f),
      m_ac(40.0f),
      m_b8(1.0f),
      m_bc(0),
      m_f0(0),
      m_f4(0),
      m_f8(0),
      m_fc(0),
      m_100(0.0f)
{
    if (Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0())
        CTargetCameraMode::vfunc_31();
    m_b4 = FUN_1403ed2d0()->FUN_141bd4120();
}

// @0x14183a230
CTargetCameraMode::~CTargetCameraMode()
{
}

// @0x14183a260
void CTargetCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    if (m_f8 == 0)
    {
        m_50 = Unk_CameraManager::FUN_1409478c0()->FUN_140b67d10();
        m_fc = 0;
        m_100 = 0.0f;
    }
    if (n == 0)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (pTarget)
        {
            m_78 = pTarget->vfunc_17();
            m_78.z += vfunc_27();
            vfunc_3(m_78.FUN_14097fd50(FUN_14183c370()));
        }
    }
    if (m_f8)
    {
        m_f0 = 1;
    }
    else
    {
        m_f0 = 0;
        m_d8.m_pos = FUN_1409f2540();
        m_d8.m_rot = FUN_140af8260();
        m_c0 = m_d8;
        m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
        m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
        m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
    }
    m_f8 = 0;
}
MS2_REPLACE_METHOD(0x14183a260, CTargetCameraMode, vfunc_6, 668, 0x81481BA3);

// @0x14183a510
void CTargetCameraMode::vfunc_7()
{
    CCameraMode::vfunc_7();
    if (m_bc)
        g_143aef240 = m_50;
    else
        g_143aef240 = 0.0f;
}
MS2_REPLACE_METHOD(0x14183a510, CTargetCameraMode, vfunc_7, 69, 0x5DAB0202);

// @0x14183a560
void CTargetCameraMode::vfunc_8(double fTime)
{
    Vector3 ptPrevTarget = m_78;
    Vector3 ptPrevPos = m_d8.m_pos;
    const int nMaxLoop = 100;
    int nLoop = 1;
    for (int i = 0; i < nLoop && i < nMaxLoop; ++i)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (!pTarget)
            break;
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
                    vfunc_37();
                }
            }
            Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
        }
        vfunc_39(fTime);
        m_setting.m_c = m_d8.m_pos;
        m_setting.m_18 = m_d8.m_rot;
        if (m_f4)
            ++nLoop;
    }
}
MS2_REPLACE_METHOD(0x14183a560, CTargetCameraMode, vfunc_8, 3332, 0x40364A33);

// @0x14183b270
void CTargetCameraMode::vfunc_9()
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
MS2_REPLACE_METHOD(0x14183b270, CTargetCameraMode, vfunc_9, 758, 0x07F55314);

// @0x14183b570
void CTargetCameraMode::vfunc_10()
{
    m_f0 = 0;
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    Unk_CameraManager::FUN_1409478c0()->FUN_140aeaf40(pTarget, 1);  // MS2-FUNCTIONAL: the exe moves pTarget through rcx first (mov rcx,[rsp+20h]; mov rdx,rcx)
}
MS2_REPLACE_METHOD(0x14183b570, CTargetCameraMode, vfunc_10, 74, 0x9E7A33EE);

// @0x14183b5c0
float CTargetCameraMode::vfunc_22()
{
    return m_6c;
}
MS2_REPLACE_METHOD(0x14183b5c0, CTargetCameraMode, vfunc_22, 16, 0x33EB21D2);

// @0x14183b5e0
float CTargetCameraMode::vfunc_23()
{
    return m_68;
}
MS2_REPLACE_METHOD(0x14183b5e0, CTargetCameraMode, vfunc_23, 16, 0x1BE201AE);

// @0x14183b600
Unk_CameraTargetEntity* CTargetCameraMode::vfunc_25()
{
    return Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
}
MS2_REPLACE_METHOD(0x14183b600, CTargetCameraMode, vfunc_25, 27, 0x0A0B42EA);

// @0x14183b630
void CTargetCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
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
        float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
        float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
        float fZ = m_50 * FUN_1409f2310(m_6c) + m_78.z;
        m_d8.m_pos = Vector3(fX, fY, fZ);
        vfunc_3(Vector3(fX, fY, fZ));
        Vector3 ptRot = CCameraMode::FUN_140afdd40(m_78, m_d8.m_pos, g_143a08cf8);
        vfunc_4(ptRot);
        m_d8.m_rot = ptRot;
        vfunc_37();
        m_fc = 0;
        m_100 = 0.0f;
    }
}
MS2_REPLACE_METHOD(0x14183b630, CTargetCameraMode, vfunc_24, 949, 0x714D6F1E);

// @0x14183b9f0
Vector3 CTargetCameraMode::vfunc_26()
{
    vfunc_24(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60(), 1);
    return m_78.FUN_14097fd50(FUN_14183c370());
}
MS2_REPLACE_METHOD(0x14183b9f0, CTargetCameraMode, vfunc_26, 112, 0x8A79092F);

// @0x14183ba70
void CTargetCameraMode::vfunc_11(float f)
{
    if (Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0())
        f = m_ac;
    m_setting.m_0 = f;
    m_pOwner->FUN_140947940(f);
}
MS2_REPLACE_METHOD(0x14183ba70, CTargetCameraMode, vfunc_11, 92, 0x587F1513);

// @0x14183bae0
void CTargetCameraMode::vfunc_12(float fDegree)
{
    float fOffset = Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0() == 1 ? m_a8 : 0.0f;
    m_48 = (fDegree + fOffset) * 3.14159265f / 180.0f + 3.14159265f;
}
MS2_REPLACE_METHOD(0x14183bae0, CTargetCameraMode, vfunc_12, 126, 0x7DE2A65C);

// @0x14183bb70
void CTargetCameraMode::vfunc_16(float f)
{
    m_54 = Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0() ? m_b0 : f;
    if (-1.0f != m_5c)
        m_98 = FUN_140a17940(m_98, m_58, m_54 + m_b4);
}
MS2_REPLACE_METHOD(0x14183bb70, CTargetCameraMode, vfunc_16, 172, 0x1329D8B0);

// @0x14183bc30
float CTargetCameraMode::vfunc_27()
{
    float fRange = m_54 - m_58;
    float fHeight = m_64;
    if (fRange > 0.0f)
        fHeight = m_64 + (m_60 - m_64) * ((m_50 - m_58) / fRange);
    return fHeight;
}
MS2_REPLACE_METHOD(0x14183bc30, CTargetCameraMode, vfunc_27, 147, 0x3EE26CF8);

// @0x14183bcd0
void CTargetCameraMode::vfunc_3(Vector3 pt)
{
    if (pt.FUN_140552700(m_setting.m_c))
    {
        m_f0 = 0;
        m_setting.m_c = pt;
        m_pOwner->FUN_140a38dc0(pt);
    }
}
MS2_REPLACE_METHOD(0x14183bcd0, CTargetCameraMode, vfunc_3, 128, 0x1B240A92);

// @0x14183bd60
void CTargetCameraMode::vfunc_4(Vector3 pt)
{
    if (pt.FUN_140552700(m_setting.m_18))
    {
        m_f0 = 0;
        m_setting.m_18 = pt;
        m_pOwner->FUN_140a38e00(pt);
    }
}
MS2_REPLACE_METHOD(0x14183bd60, CTargetCameraMode, vfunc_4, 128, 0x028BD464);

// @0x14183bdf0
void CTargetCameraMode::vfunc_21(float f, int n)
{
    float fDist = m_54 + m_b4 - m_58;
    fDist = m_58 + fDist * f;
    FUN_14183c670(fDist, n);
}
MS2_REPLACE_METHOD(0x14183bdf0, CTargetCameraMode, vfunc_21, 120, 0x6EA7BBE0);

// @0x14183be70
void CTargetCameraMode::vfunc_33()
{
    Unk_CameraOptionPtr spOption = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spOption.FUN_1409657a0())
    {
        float fRotation = spOption.FUN_140885340()->m_154;
        if (Unk_CameraManager::FUN_1409478c0()->FUN_140af01d0())
        {
            vfunc_31();
            vfunc_16(m_b0);
            vfunc_11(m_ac);
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
MS2_REPLACE_METHOD(0x14183be70, CTargetCameraMode, vfunc_33, 334, 0x53F7E6FB);

// @0x14183bfd0
void CTargetCameraMode::FUN_14183bfd0(Vector3 ptPos, Vector3 ptRot, Vector3 ptTarget, bool bClamp)
{
    m_6c = FUN_14183ce10(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
    ptPos.z = ptTarget.z;
    float fPrevDist = m_50;
    Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
    m_50 = ptDir.FUN_140967ac0();
    if (bClamp)
        m_50 = FUN_140a17940(m_50, m_58, m_54 + m_b4);
    if (0.0f > m_84 && m_50 > m_54 && fPrevDist < m_54)
    {
        m_50 = m_54;
        m_5c = -1.0f;
        m_84 = 0.0f;
    }
    else if (0.0f < m_84 && fPrevDist > m_54 && m_50 < m_54)
    {
        m_50 = m_54;
        m_5c = -1.0f;
        m_84 = 0.0f;
    }
    if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) <= 5.0f)
    {
        m_50 = m_98;
        m_5c = -1.0f;
        m_84 = 0.0f;
    }
    ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptTarget.x;
    ptPos.y = m_50 * FUN_1409f2310(m_68) + ptTarget.y;
    ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptTarget.z;
    m_d8.m_pos = ptPos;
    ptRot = CCameraMode::FUN_140afdd40(ptTarget, m_d8.m_pos, g_143a08cf8);
    m_d8.m_rot = ptRot;
}
MS2_REPLACE_METHOD(0x14183bfd0, CTargetCameraMode, FUN_14183bfd0, 882, 0x44BF5C37);

// @0x14183c350
void CTargetCameraMode::FUN_14183c350(int n)
{
    m_f0 = n;
}
MS2_REPLACE_METHOD(0x14183c350, CTargetCameraMode, FUN_14183c350, 25, 0x5E107A5F);

// @0x14183c370
Vector3 CTargetCameraMode::FUN_14183c370()
{
    return m_8c;
}
MS2_REPLACE_METHOD(0x14183c370, CTargetCameraMode, FUN_14183c370, 44, 0xE877299E);

// @0x14183c3b0
void CTargetCameraMode::FUN_14183c3b0(float f)
{
    m_84 = f;
}
MS2_REPLACE_METHOD(0x14183c3b0, CTargetCameraMode, FUN_14183c3b0, 31, 0xE932FCE8);

// @0x14183c3e0
bool CTargetCameraMode::FUN_14183c3e0(Vector3& ptPos, Vector3& ptRot)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget)
    {
        float fYaw = Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0()->vfunc_23();
        float fPitch = Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0()->vfunc_22();
        float fDist = Unk_CameraManager::FUN_1409478c0()->FUN_140b67d10();
        Vector3 ptTarget = pTarget->vfunc_17();
        ptTarget.z += Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0()->vfunc_27();
        float fX = fDist * FUN_1409f25a0(fYaw) + ptTarget.x;
        float fY = fDist * FUN_1409f2310(fYaw) + ptTarget.y;
        float fZ = fDist * FUN_1409f2310(fPitch) + ptTarget.z;
        ptPos = Vector3(fX, fY, fZ);
        ptRot = CCameraMode::FUN_140afdd40(ptTarget, ptPos, g_143a08cf8);
        return true;
    }
    return false;
}
MS2_REPLACE(0x14183c3e0, CTargetCameraMode::FUN_14183c3e0, 444, 0x92C52C9E);

// @0x14183c5b0
Unk_CameraSetting CTargetCameraMode::FUN_14183c5b0(Unk_CameraSetting setting)
{
    FUN_14183c3e0(setting.m_c, setting.m_18);
    return setting;
}
MS2_REPLACE(0x14183c5b0, CTargetCameraMode::FUN_14183c5b0, 65, 0x717B8B0C);

// @0x14183c600
void CTargetCameraMode::FUN_14183c600(float f)
{
    m_b4 = f;
}
MS2_REPLACE_METHOD(0x14183c600, CTargetCameraMode, FUN_14183c600, 31, 0xA88FA7F8);

// @0x14183c630
float CTargetCameraMode::FUN_14183c630()
{
    return m_b4;
}
MS2_REPLACE_METHOD(0x14183c630, CTargetCameraMode, FUN_14183c630, 19, 0x209BC484);

// @0x14183c650
float CTargetCameraMode::FUN_14183c650()
{
    return m_5c;
}
MS2_REPLACE_METHOD(0x14183c650, CTargetCameraMode, FUN_14183c650, 16, 0x53C444C2);

// @0x14183c670
void CTargetCameraMode::FUN_14183c670(float fDist, BOOL bSmooth)
{
    m_98 = FUN_140a17940(fDist, m_58, m_54 + m_b4);
    if (m_98 == m_50)
        return;
    if (bSmooth)
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
            m_6c = FUN_14183ce10(m_58, m_50, m_54, m_4c * 180.0f / 3.14159265f, 90.0f);
            ptPos.z = ptCenter.z;
            Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
            m_50 = ptDist.FUN_140967ac0();
            m_50 = FUN_140a17940(m_50, m_58, m_54 + m_b4);
            ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
            ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
            ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptCenter.z;
            if (FUN_14029d220(m_98 - m_50) <= 1.0f)
            {
                m_50 = m_98;
                m_d8.m_pos = ptPos;
                vfunc_3(ptPos);
                ptRot = CCameraMode::FUN_140afdd40(ptCenter, ptPos, g_143a08cf8);
                m_d8.m_rot = ptRot;
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
        m_5c = m_98 / (m_54 + m_b4);
    }
}
MS2_REPLACE_METHOD(0x14183c670, CTargetCameraMode, FUN_14183c670, 1497, 0x14C96233);

// @0x14183cc50
void CTargetCameraMode::FUN_14183cc50(float f)
{
    m_b8 = f;
}
MS2_REPLACE_METHOD(0x14183cc50, CTargetCameraMode, FUN_14183cc50, 31, 0x0DF3526C);

// @0x14183cc80
void CTargetCameraMode::FUN_14183cc80(int n)
{
    m_bc = n;
}
MS2_REPLACE_METHOD(0x14183cc80, CTargetCameraMode, FUN_14183cc80, 25, 0xCEDBA8AB);

// @0x14183cca0
void CTargetCameraMode::vfunc_29(float f1, float f2, float f3)
{
    m_9c = f1;
    m_a0 = f2;
    m_a4 = f3;
}
MS2_REPLACE_METHOD(0x14183cca0, CTargetCameraMode, vfunc_29, 81, 0x51FF0508);

// @0x14183cd00
void CTargetCameraMode::vfunc_37()
{
    float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
    float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
    float fZ = m_50 * FUN_1409f2310(m_6c) + m_78.z;
    m_d8.m_pos = Vector3(fX, fY, fZ);
    m_8c = m_d8.m_pos.FUN_140965c40(m_78);
}
MS2_REPLACE_METHOD(0x14183cd00, CTargetCameraMode, vfunc_37, 263, 0xFA339820);

// @0x14183ce10
float CTargetCameraMode::FUN_14183ce10(float fMin, float fCur, float fMax, float fDegMin, float fDegMax)
{
    float t = fCur - fMin;
    t /= fMax - fMin;
    if (t > 1.0f)
        t = 1.0f;
    float fDegree = (fDegMin - fDegMax) * t;
    fDegree = fDegMax + fDegree;
    return fDegree * 3.14159265f / 180.0f;
}
MS2_REPLACE_METHOD(0x14183ce10, CTargetCameraMode, FUN_14183ce10, 168, 0x8A699848);

// @0x14183cec0
BOOL CTargetCameraMode::vfunc_38(Vector3 ptPos, Vector3 ptRot)
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
            float fTan = tanf(fFov * 3.14159265f / 180.0f);  // MS2-FUNCTIONAL: /Oi makes this a direct call to tanf; the exe calls the import (6-byte call)
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
                Vector3 ptDir = m_78.FUN_140965c40(aptCorner[i]);
                float fLen = ptDir.FUN_140968990();
                if (isinf(fLen))
                    fLen = 1.0f;
                Vector3 ptBack = ptDir.FUN_1409f7960();
                Vector3 ptHit = g_143b01a60;
                if (Unk_Collision::FUN_1409f7ca0()->FUN_14168a230(aptCorner[i], ptHit, ptDir, fLen, 0x209) == 0)
                {
                    if (Unk_Collision::FUN_1409f7ca0()->FUN_14168a230(m_78, ptHit, ptBack, fLen, 0x209))
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
MS2_REPLACE_METHOD(0x14183cec0, CTargetCameraMode, vfunc_38, 2717, 0x0734DB2A);

// @0x14183d970
BOOL CTargetCameraMode::vfunc_31()
{
    if (FUN_140ae8540())
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14183d970, CTargetCameraMode, vfunc_31, 32, 0x8249C6AA);

// @0x14183d9a0
void CTargetCameraMode::FUN_14183d9a0(float& f1, float& f2, float& f3) const
{
    f1 = m_9c;
    f2 = m_a0;
    f3 = m_a4;
}
MS2_REPLACE_METHOD(0x14183d9a0, CTargetCameraMode, FUN_14183d9a0, 87, 0xE5AD0932);

// @0x14183da00
void CTargetCameraMode::vfunc_39(double fTime)
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
            if (t > 1.0f)
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
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
}
MS2_REPLACE_METHOD(0x14183da00, CTargetCameraMode, vfunc_39, 1489, 0xB178627F);

// @0x14183dfe0
void CTargetCameraMode::FUN_14183dfe0(const Unk_CameraPose& cur, const Unk_CameraPose& target)
{
    m_c0 = cur;
    m_d8 = target;
    m_f8 = 1;
}
MS2_REPLACE_METHOD(0x14183dfe0, CTargetCameraMode, FUN_14183dfe0, 87, 0x7B47FECC);

// @0x14183e040
void CTargetCameraMode::FUN_14183e040()
{
    m_f8 = 0;
}
MS2_REPLACE_METHOD(0x14183e040, CTargetCameraMode, FUN_14183e040, 21, 0xA10419EF);

// memmove_s 0x14183e150 closes the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_targetCameraModeMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
