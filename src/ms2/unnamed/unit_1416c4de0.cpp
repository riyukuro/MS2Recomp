// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See unit_1416c4de0.h.
// MS2-UNIT: unit_1416c4de0
// MS2-RANGE: 0x1416c4de0-0x1416c6210 .text$mn
// MS2-PIN: memmove_s 0x1416c60f0
#define MS2_THIS_FILE ""
// The exe's memmove_s copy is a plain call (no /Oi expansion): the pragma must precede the inline definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "unit_1416c4de0.h"

#include <math.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z

// The game context (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    Unk_CameraTargetEntity* FUN_141bd1180(int nObjectId);
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

// Camera tuning values of the camera xml (FUN_140ae8910 consumes its by-value CString key).
float FUN_140ae8910(CString key);
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)

float FUN_14059d930(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
float FUN_141b6fdb0(float t, int nType);            // easing
bool FUN_14028d470(float a, float b);               // a == b (within epsilon)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1416c4de0
CPVPCameraMode::CPVPCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CTargetCameraMode(pOwner, pPrev),
      m_108(0),
      m_110(NULL),
      m_118(0.02f),
      m_11c(500.0f),
      m_120(800.0f),
      m_124(2000.0f),
      m_128(200.0f)
{
}

// @0x1416c4ee0
CPVPCameraMode::~CPVPCameraMode()
{
}

// @0x1416c4f10
void CPVPCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    m_6c = 1.30899694f;
    m_68 = 3.14159265f;
    vfunc_31();
    m_f0 = 0;
    Vector3 ptPos = m_d8.m_pos;
    Vector3 ptRot = g_143b01a60;
    Vector3 ptCenter = FUN_1416c5d30();
    m_50 = m_124;
    ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
    ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
    ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptCenter.z;
    m_d8.m_pos = ptPos;
    ptRot = CCameraMode::FUN_140afdd40(ptCenter, ptPos, g_143a08cf8);
    m_d8.m_rot = ptRot;
    m_c0 = m_d8;
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
    m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
    m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
    m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
}
MS2_REPLACE_METHOD(0x1416c4f10, CPVPCameraMode, vfunc_6, 793, 0x057BE7BB);

// @0x1416c5230
void CPVPCameraMode::vfunc_8(double fTime)
{
    Vector3 ptPos = m_d8.m_pos;
    Vector3 ptRot = g_143b01a60;
    Vector3 ptCenter = FUN_1416c5d30();
    Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    if (ptMove.FUN_140552700(g_143b01a60))
    {
        Vector3 ptInput = ptMove;
        float fRate = 15.0f;
        float fStep = FUN_140a17940((float)fTime, 0.0f, 1.0f / fRate);
        float fMax = FUN_140a0fda0(FUN_140a38cd0(ptInput.x),
                                   FUN_140a0fda0(FUN_140a38cd0(ptInput.y), FUN_140a38cd0(ptInput.z)));
        float fScale = fStep * fMax;
        m_50 = m_50 + ptInput.y * fScale;
        if (m_50 > m_120)
            m_50 = m_124;
    }
    ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
    ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
    ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptCenter.z;
    m_d8.m_pos = ptPos;
    ptRot = CCameraMode::FUN_140afdd40(ptCenter, ptPos, g_143a08cf8);
    m_d8.m_rot = ptRot;
    vfunc_39(fTime);
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
}
MS2_REPLACE_METHOD(0x1416c5230, CPVPCameraMode, vfunc_8, 772, 0x4DA24B45);

// @0x1416c5540
void CPVPCameraMode::vfunc_39(double fTime)
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
            float t = (float)fTime * fDist * m_118 + fBlend;
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
MS2_REPLACE_METHOD(0x1416c5540, CPVPCameraMode, vfunc_39, 1330, 0x2AEDBD94);

// @0x1416c5a80
void CPVPCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget && n)
        vfunc_6(0);
}
MS2_REPLACE_METHOD(0x1416c5a80, CPVPCameraMode, vfunc_24, 75, 0xC3A34032);

// @0x1416c5ae0
float CPVPCameraMode::vfunc_27()
{
    return m_128;
}
MS2_REPLACE_METHOD(0x1416c5ae0, CPVPCameraMode, vfunc_27, 19, 0x6FC60411);

// @0x1416c5b00
void CPVPCameraMode::FUN_1416c5b00(int nTargetId)
{
    m_108 = nTargetId;
}
MS2_REPLACE_METHOD(0x1416c5b00, CPVPCameraMode, FUN_1416c5b00, 25, 0x7D8CAC3E);

// @0x1416c5b20
BOOL CPVPCameraMode::vfunc_31()
{
    if (FUN_140ae8540())
    {
        m_118 = FUN_140ae8910(CString("PVP_InterpolateDelay"));
        m_6c = FUN_140ae8910(CString("PVP_VertDeg")) * 3.1415927f / 180.0f;
        m_68 = FUN_140ae8910(CString("PVP_HorzDeg")) * 3.1415927f / 180.0f;
        m_11c = FUN_140ae8910(CString("PVP_DistanceOffset"));
        m_120 = FUN_140ae8910(CString("PVP_DetachDistance"));
        m_124 = FUN_140ae8910(CString("PVP_Zoomout"));
        m_128 = FUN_140ae8910(CString("PVP_ViewOffsetZ"));
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416c5b20, CPVPCameraMode, vfunc_31, 514, 0x392A4514);

// @0x1416c5d30
Vector3 CPVPCameraMode::FUN_1416c5d30()
{
    Vector3 ptCenter(0.0f, 0.0f, 0.0f);
    Vector3 ptOther(0.0f, 0.0f, 0.0f);
    Unk_CameraTargetEntity* pSelf = vfunc_25();
    if (pSelf)
    {
        ptOther = ptCenter = pSelf->vfunc_18().FUN_14097fd50(Vector3(0.0f, 0.0f, m_128));
        m_50 = m_124;
    }
    m_110 = FUN_1403ed2d0()->FUN_141bd1180(m_108);
    if (m_110 != NULL)
    {
        float fDist = 0.0f;
        if (m_110 != NULL)
        {
            ptOther = m_110->vfunc_18().FUN_14097fd50(Vector3(0.0f, 0.0f, m_128));
            fDist = ptOther.FUN_140965c40(ptCenter).FUN_140967ac0() + m_11c;
            if (fDist > m_120)
            {
                m_110 = NULL;
                fDist = m_124;
                return ptCenter;
            }
        }
        else
        {
            fDist = m_124;
        }
        m_50 = fDist;
    }
    else
    {
        return ptCenter;
    }
    Vector3 kDir = ptOther.FUN_140965c40(ptCenter);
    float fLen = kDir.FUN_140968990();
    return ptCenter.FUN_14097fd50(kDir.FUN_14097fc90(fLen * 0.5f));
}
MS2_REPLACE_METHOD(0x1416c5d30, CPVPCameraMode, FUN_1416c5d30, 849, 0x6A577FD4);

// memmove_s 0x1416c60f0 closes the unit's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_pvpCameraModeMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
