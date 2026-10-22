// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See consolecameramode.h.
// MS2-UNIT: ?\consolecameramode.cpp
// MS2-RANGE: 0x14109eb00-0x1410a0e80 .text$mn
// MS2-PIN: memcpy_s 0x1410a0c10
// MS2-PIN: memmove_s 0x1410a0d60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\consolecameramode.cpp"
// The exe's memcpy_s / memmove_s copies are plain calls (no /Oi expansion): the pragma must precede the inline
// definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "consolecameramode.h"

#include <math.h>
#include <stdlib.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#pragma intrinsic(abs)

// ---- unit-local placeholders ----

extern const Vector3 g_143a08cf8;   // NiPoint3::UNIT_Z

// The input state (FUN_14025e7c0).
class Unk_InputState
{
public:
    bool FUN_14116d950(int nKey, bool b, int n);                    // key held
    bool FUN_14116daa0(int nButton, bool b, int n);                 // mouse button held
    bool FUN_14116dbf0(int* pnX, int* pnY, int* pnZ, bool b, int n);    // mouse move delta
};
Unk_InputState* FUN_14025e7c0();

class Unk_BuffContainer
{
public:
    bool FUN_141682fe0(int nBuffId);
};

// A field actor (FUN_1409ffd30 casts an object to it).
class Unk_RpgActor : public Unk_CameraTargetEntity
{
public:
    Unk_BuffContainer* FUN_14166d240();             // +0x6d8
};
Unk_RpgActor* FUN_1409ffd30(Unk_CameraTargetEntity* p);

// The game context (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    Unk_CameraTargetEntity* FUN_141bd1050(__int64 nObjectId);
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

// The picked-object list returned by the camera manager's pick (FUN_140af0850).
class Unk_PickEntry
{
public:
    __int64 FUN_140a17cb0();                        // object id
};
class Unk_PickArray
{
public:
    Unk_PickEntry* FUN_140a17d70(unsigned int i);
    unsigned int FUN_140a17ea0();                   // count
};
class Unk_PickList
{
public:
    Unk_PickArray* FUN_140a17e00();
};
class Unk_PickListPtr
{
public:
    ~Unk_PickListPtr() { FUN_140a16120(); }        // 0x140a16120
    void FUN_140a16120();
    Unk_PickList* FUN_140a16c00() const;            // get
    Unk_PickList* FUN_140a16c30() const;            // operator->

    void* m_p;
};
// The cursor (FUN_140aadf80).
class Unk_Cursor
{
public:
    void FUN_141b90e30(float* pfX, float* pfY);
};
Unk_Cursor* FUN_140aadf80();

// The scene graph node of a target entity (FUN_14123c410 -> FUN_141b6efc0 -> FUN_141024c90 = its world rotation).
namespace egf { class Entity; }
class NiAVObject;
egf::Entity* FUN_14123c410(Unk_CameraTargetEntity* p);      // m_80 of the game object
NiAVObject* FUN_141b6efc0(egf::Entity* p);
const Unk_EfdMatrix3* FUN_141024c90(NiAVObject* p);
// efd::operator*(const Point3&, const Matrix3&) (0x1420834e0)
Vector3 FUN_1420834e0(const Vector3& pt, const Unk_EfdMatrix3& m);

// Camera tuning values of the camera xml (FUN_140ae8910 consumes its by-value CString key).
float FUN_140ae8910(CString key);
void FUN_140aec8a0(Unk_CameraManager* pMgr, bool b);

float FUN_14029d220(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
void FUN_140291b70(float* pfDegree);                // wraps an angle to (-180, 180]
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14109eb00
CConsoleCameraMode::CConsoleCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CTargetCameraMode(pOwner, pPrev),
      m_108(0),
      m_110(100.0f),
      m_114(50.0f),
      m_118(0.0f, 0.0f, 100.0f),
      m_124(400.0f),
      m_128(1100.0f)
{
}

// @0x14109ec00
CConsoleCameraMode::~CConsoleCameraMode()
{
}

// @0x14109ec30
void CConsoleCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    Unk_CameraTargetEntity* pTarget = vfunc_25();
    Unk_RpgActor* pActor = FUN_1409ffd30(pTarget);
    if (pActor)
    {
        if (pActor->FUN_14166d240()->FUN_141682fe0(300008))
            ptMove.x = 1.0f;
        else if (pActor->FUN_14166d240()->FUN_141682fe0(300009))
            ptMove.x = -1.0f;
    }
    if (FUN_14025e7c0()->FUN_14116daa0(1, true, 0))
    {
        int nX, nY, nZ;
        if (FUN_14025e7c0()->FUN_14116dbf0(&nX, &nY, &nZ, false, 0))
        {
            if (abs(nY) > abs(nX))
                ptMove.x = (float)nY * -0.05f;
            else
                ptMove.y = (float)nX * 0.1f;
        }
    }
    if (FUN_14025e7c0()->FUN_14116d950(0x33, false, 0))
        ptMove.y = 1.0f;
    else if (FUN_14025e7c0()->FUN_14116d950(0x34, false, 0))
        ptMove.y = -1.0f;
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x14109ec30, CConsoleCameraMode, vfunc_9, 474, 0x7049B776);

// @0x14109ee10
void CConsoleCameraMode::vfunc_8(double fTime)
{
    int nLoop = 100;
    for (int i = 0; i < nLoop; ++i)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (!pTarget)
            break;
        NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410(pTarget));
        if (pNode)
        {
            Unk_EfdMatrix3 kRot = *FUN_141024c90(pNode);
            m_78 = pTarget->vfunc_18().FUN_14097fd50(FUN_1420834e0(m_118, kRot));
        }
        else
        {
            m_78 = pTarget->vfunc_18().FUN_14097fd50(m_118);
        }

        Vector3 ptPos = g_143b01a60;
        Vector3 ptRot = g_143b01a60;
        if (m_88 == 0)
        {
            Vector3 ptEye = m_78.FUN_14097fd50(FUN_14183c370());
            m_d8.m_pos = ptEye;
        }

        if (-1.0f != m_5c && FUN_14029d220(m_98 - m_50) > 5.0f)
        {
            if (m_98 < m_50)
                m_84 = 10.0f;
            else if (m_98 > m_50)
                m_84 = -10.0f;
        }
        if (5.0f <= m_84 || -5.0f >= m_84)
        {
            m_88 = 1;
            if (m_f4 == 0)
                m_84 = m_84 * 0.9f;
            ptPos = m_d8.m_pos;
            Vector3 ptTarget = m_78;
            Vector3 ptDir = ptTarget.FUN_140965c40(ptPos);
            ptDir.FUN_140968990();
            ptPos = ptPos.FUN_14097fd50(ptDir.FUN_14097fc90(m_84));
            ptPos.z = ptTarget.z;
            Vector3 ptDist = ptTarget.FUN_140965c40(ptPos);
            m_50 = ptDist.FUN_140967ac0();
            m_50 = FUN_140a17940(m_50, m_124, m_128);
            m_6c = FUN_14183ce10(m_124, m_50, m_128, m_4c * 180.0f / 3.14159265f, 90.0f);
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
            m_d8.m_rot = FUN_1410a0a00(m_d8.m_pos);
        }
        else if (m_88)
        {
            m_84 = 0.0f;
            m_88 = 0;
            vfunc_37();
        }

        Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
        if (ptMove.FUN_140552700(g_143b01a60) || m_108)
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
                m_84 = FUN_140a17940(m_84, -50.0f, 50.0f);
            }
            if (fYaw != 0.0f)
            {
                float fDegree = m_68 * 180.0f / 3.14159265f + fYaw * m_114;
                FUN_140291b70(&fDegree);
                float fRadian = fDegree * 3.14159265f / 180.0f;
                m_68 = fRadian;
                m_10c = fRadian;
                m_108 = 1;
            }
            if (fPitch != 0.0f || m_108)
            {
                if (m_10c != m_68)
                {
                    float fCur = m_68 * 180.0f / 3.14159265f;
                    float fWant = m_10c * 180.0f / 3.14159265f;
                    float fSpeed = m_110 * fStep;
                    if (fWant > fCur)
                    {
                        if (fWant - fCur > 180.0f)
                            fCur = fCur - fSpeed;
                        else
                            fCur = fCur + fSpeed;
                        if (fCur > fWant)
                            fCur = fWant;
                    }
                    else if (fWant < fCur)
                    {
                        if (fCur - fWant > 180.0f)
                            fCur = fCur + fSpeed;
                        else
                            fCur = fCur - fSpeed;
                        if (fWant > fCur)
                            fCur = fWant;
                    }
                    FUN_140291b70(&fCur);
                    m_68 = fCur * 3.14159265f / 180.0f;
                }
                m_108 = m_68 != m_10c;
                m_6c -= fPitch;
                Vector3 ptCenter = m_78;
                ptPos = m_d8.m_pos;
                ptPos.z = ptCenter.z;
                Vector3 ptDist = ptCenter.FUN_140965c40(ptPos);
                m_50 = ptDist.FUN_140967ac0();
                m_50 = FUN_140a17940(m_50, m_124, m_128);
                ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
                ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
                ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptCenter.z;
                m_d8.m_pos = ptPos;
                m_d8.m_rot = FUN_1410a0a00(ptPos);
                vfunc_37();
            }
            Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
        }
        vfunc_39(fTime);
        m_setting.m_c = m_d8.m_pos;
        m_setting.m_18 = m_d8.m_rot;
        if (m_f4 == 0)
            break;
    }
}
MS2_REPLACE_METHOD(0x14109ee10, CConsoleCameraMode, vfunc_8, 3644, 0x9E753221);

// @0x14109fc60
void CConsoleCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    FUN_140aec8a0(Unk_CameraManager::FUN_1409478c0(), true);
    vfunc_31();
    m_68 = m_48;
    m_10c = m_68;
    m_6c = m_4c;
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget)
    {
        NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410(pTarget));
        Unk_EfdMatrix3 kRot = *FUN_141024c90(pNode);
        m_78 = pTarget->vfunc_18().FUN_14097fd50(FUN_1420834e0(m_118, kRot));
        if (n == 0)
            vfunc_3(m_78.FUN_14097fd50(m_setting.m_c));
    }
    m_50 = (m_128 - m_124) * 0.5f + m_124;
    m_c0.m_pos = m_setting.m_c;
    m_c0.m_rot = m_setting.m_18;
    m_f0 = 0;
    float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
    float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
    float fZ = m_50 * FUN_1409f2310(m_6c) + m_78.z;
    m_d8.m_pos = Vector3(fX, fY, fZ);
    Vector3 ptRot = CCameraMode::FUN_140afdd40(m_78, m_d8.m_pos, g_143a08cf8);
    m_d8.m_rot = ptRot;
    vfunc_37();
    if (n == 0)
    {
        m_c0 = m_d8;
        vfunc_3(Vector3(fX, fY, fZ));
        vfunc_4(ptRot);
    }
    m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
    m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
    m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
    m_108 = 1;
}
MS2_REPLACE_METHOD(0x14109fc60, CConsoleCameraMode, vfunc_6, 1298, 0x3DB4BDAE);

// @0x1410a0180
void CConsoleCameraMode::vfunc_30()
{
    float fX;
    float fY;
    FUN_140aadf80()->FUN_141b90e30(&fX, &fY);
    Unk_PickListPtr pList = Unk_CameraManager::FUN_1409478c0()->FUN_140af0850(fX, fY, true, true, false, NULL);
    if (!pList.FUN_140a16c00())
        return;
    Unk_GameContext* pContext = FUN_1403ed2d0();
    for (unsigned int i = 0; i < pList.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17ea0(); ++i)
    {
        Unk_PickEntry* pEntry = pList.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(i);
        Unk_CameraTargetEntity* pObject = pContext->FUN_141bd1050(pEntry->FUN_140a17cb0());
        Unk_RpgActor* pActor = FUN_1409ffd30(pObject);
        if (pActor)
        {
            Unk_CameraManager::FUN_1409478c0()->FUN_140aeaf40(pActor, 1);
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x1410a0180, CConsoleCameraMode, vfunc_30, 326, 0x2CCF8E9B);

// @0x1410a02d0
BOOL CConsoleCameraMode::vfunc_31()
{
    if (FUN_140ae8540())
    {
        m_110 = FUN_140ae8910(CString("Console_RotationInterpolateSpeed"));
        m_114 = FUN_140ae8910(CString("Console_MouseRotationSpeed"));
        m_124 = FUN_140ae8910(CString("Console_Zoomin"));
        m_128 = FUN_140ae8910(CString("Console_Zoomout"));
        m_118.z = FUN_140ae8910(CString("Console_TargetPositionOffsetZ"));
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1410a02d0, CConsoleCameraMode, vfunc_31, 346, 0x1262FC16);

// @0x1410a0430
void CConsoleCameraMode::vfunc_32(float f)
{
    if (f != m_10c)
    {
        m_10c = f;
        m_108 = 1;
    }
}
MS2_REPLACE_METHOD(0x1410a0430, CConsoleCameraMode, vfunc_32, 66, 0xDAB0BC44);

// @0x1410a0480
void CConsoleCameraMode::vfunc_39(double fTime)
{
    if (m_f0)
    {
        Unk_NiPoint3 ptDelta(m_d8.m_pos.FUN_140965c40(m_c0.m_pos));
        float fDist = ptDelta.FUN_140967ac0();
        if (fDist <= 1.0f)
        {
            m_c0.m_pos = m_d8.m_pos;
            m_c0.m_rot = FUN_1410a0a00(m_c0.m_pos);
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
            float t = (float)fTime * fDist * m_a0;
            if (t > 1.0f)
            {
                m_c0.m_pos = m_d8.m_pos;
                m_c0.m_rot = FUN_1410a0a00(m_c0.m_pos);
            }
            else
            {
                m_c0.m_pos = m_c0.m_pos.FUN_14097fd50(FUN_1409ab5c0(t, m_d8.m_pos.FUN_140965c40(m_c0.m_pos)));
                m_c0.m_rot = CCameraMode::FUN_140afdec0(t, m_c0.m_rot, m_d8.m_rot);
            }
        }
        m_f4 = vfunc_38(m_c0.m_pos, m_c0.m_rot);
        if (m_f4)
            m_84 = -10.0f;
    }
    else
    {
        m_c0.m_pos = m_d8.m_pos;
        m_c0.m_rot = FUN_1410a0a00(m_c0.m_pos);
        m_f0 = 1;
        m_f4 = 0;
    }
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
}
MS2_REPLACE_METHOD(0x1410a0480, CConsoleCameraMode, vfunc_39, 1395, 0x298611D3);

// @0x1410a0a00
Vector3 CConsoleCameraMode::FUN_1410a0a00(Vector3 ptPos)
{
    Vector3 ptTarget = m_78;
    Vector3 kDir = ptTarget.FUN_140965c40(ptPos);
    kDir.FUN_140968990();
    Vector3 kRight = kDir.FUN_140a00e10(g_143a08cf8);
    kRight.FUN_140968990();
    Vector3 kUp = kRight.FUN_140a00e10(kDir);
    Unk_NiMatrix3 kRot(kDir, kUp, kRight);
    float fZ;
    float fY;
    float fX;
    kRot.FUN_142085840(fX, fY, fZ);
    return Vector3(-fX, -fY, -fZ).FUN_14097fc90(180.0f).FUN_140ae9180(3.14159265f);
}
MS2_REPLACE_METHOD(0x1410a0a00, CConsoleCameraMode, FUN_1410a0a00, 416, 0xC0E11021);

// memcpy_s 0x1410a0c10 and memmove_s 0x1410a0d60 close the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_consoleCameraModeMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
__declspec(selectany) extern errno_t(__cdecl* const ms2_consoleCameraModeMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
