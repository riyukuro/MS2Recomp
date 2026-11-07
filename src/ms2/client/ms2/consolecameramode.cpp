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
#include <efd/Matrix3.h>   // C3: efd::Matrix3

#include "consolecameramode.h"

#include <math.h>
#include <stdlib.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
#include <NiPoint3.h>
#include <NiPick.h>
#include <ecr/PickService.h>
#include "ms2/client/ms2/pcbase.h"  // C3: PCBase (efd::DynamicCast<PCBase, GameObject>)
class CameraMgr;
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };   // C3: 0x1409478c0, as camera.h declares it

#pragma intrinsic(abs)

// ---- unit-local placeholders ----

#define g_143a08cf8 (*(const Vector3*)&efd::Point3::UNIT_Z)   // NiPoint3::UNIT_Z

// The input state (FUN_14025e7c0).
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

class Unk_BuffContainer;
// C3: the movement controller (Unk_PCMove, unit_141682f80) behind FUN_14166d240
class Unk_PCMove
{
public:
    bool FUN_141682fe0(int nKey);
};

// A field actor (efd::DynamicCast<PCBase, GameObject> casts an object to it).
class Unk_RpgActor : public Unk_CameraTargetEntity
{
public:
};

class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
    class Unk_WsC_GameObj* FUN_141bd1050(void* mesh);   // C3: was Unk_GameContext::FUN_141bd1050
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
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

class Unk_PickEntry;
// The cursor (FUN_140aadf80).
class CWindowService   // C3: member view (real class not in this TU)
{
public:
    int GetCursorClientPos(float* pfX, float* pfY);
};
void* FUN_140aadf80();   // C3: was FUN_140aadf80

// The scene graph node of a target entity (FUN_14123c410 -> FUN_141b6efc0 -> FUN_141024c90 = its world rotation).
namespace egf { class Entity; }
class NiAVObject;
NiAVObject* FUN_141b6efc0(egf::Entity* p);
// efd::operator*(const Point3&, const Matrix3&) (0x1420834e0)
// C3 #9: efd::operator*(const Point3&, const Matrix3&) (0x1420834e0) is called directly.

// Camera tuning values of the camera xml (FUN_140ae8910 consumes its by-value CString key).
float FUN_140ae8910(CString key);
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    Vector3 FUN_140a38d00();   // C3: was Unk_CameraManager
    void FUN_140a38d90(Vector3 pt);   // C3: was Unk_CameraManager
    efd::SmartPointer<ecr::PickService::PickRecord> FUN_140af0850(float fX, float fY, bool bFrontOnly, bool bAppCulled, bool bClosestOnly,
        NiAVObject* pRoot);                                         // pick the scene under a window point
    void FUN_140aec8a0(bool);
    void FUN_140aeaf40(Unk_CameraTargetEntity* pTarget, int n);   // set the camera target
    class Unk_CameraTargetEntity* FUN_140a38d60();   // C3: bosstargetcamera.cpp
};

float FUN_14029d220(float f);                       // fabs
float FUN_140a38cd0(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
void FUN_140291b70(float* pfDegree);                // wraps an angle to (-180, 180]
int LoadTestCamerValue();                                // reloads the camera xml (returns 0 on failure)

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
    Unk_RpgActor* pActor = reinterpret_cast<Unk_RpgActor*>(efd::DynamicCast<PCBase, GameObject>(reinterpret_cast<GameObject*>(pTarget)));
    if (pActor)
    {
        if (reinterpret_cast<Unk_PCMove*>(reinterpret_cast<PCBase*>(pActor)->FUN_14166d240())->FUN_141682fe0(300008))
            ptMove.x = 1.0f;
        else if (reinterpret_cast<Unk_PCMove*>(reinterpret_cast<PCBase*>(pActor)->FUN_14166d240())->FUN_141682fe0(300009))
            ptMove.x = -1.0f;
    }
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, true, 0))
    {
        int nX, nY, nZ;
        if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dbf0(&nX, &nY, &nZ, false, 0))
        {
            if (abs(nY) > abs(nX))
                ptMove.x = (float)nY * -0.05f;
            else
                ptMove.y = (float)nX * 0.1f;
        }
    }
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x33, false, 0))
        ptMove.y = 1.0f;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x34, false, 0))
        ptMove.y = -1.0f;
    TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x14109ec30, CConsoleCameraMode, vfunc_9, 474, 0x7049B776);

// @0x14109ee10
void CConsoleCameraMode::vfunc_8(double fTime)
{
    int nLoop = 100;
    for (int i = 0; i < nLoop; ++i)
    {
        Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
        if (!pTarget)
            break;
        NiAVObject* pNode = FUN_141b6efc0(reinterpret_cast<GameObject*>(pTarget)->FUN_14123c410());
        if (pNode)
        {
            Unk_EfdMatrix3 kRot = *((struct Unk_EfdMatrix3 const*)&((class NiAVObject*)(pNode))->GetWorldRotate());
            m_78 = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pTarget->vfunc_18())) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_118) * reinterpret_cast<const efd::Matrix3&>(kRot)))))));
        }
        else
        {
            m_78 = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pTarget->vfunc_18())) + reinterpret_cast<const efd::Point3&>(m_118)));
        }

        Vector3 ptPos = g_143b01a60;
        Vector3 ptRot = g_143b01a60;
        if (m_88 == 0)
        {
            efd::Point3 ptEye = reinterpret_cast<const efd::Point3&>(m_78) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(FUN_14183c370()));
            m_d8.m_pos = reinterpret_cast<Vector3&>(ptEye);
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
            Vector3 ptDir = (ptTarget - ptPos);
            ptDir.Unitize();
            ptPos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptPos) + reinterpret_cast<const efd::Point3&>(ptDir) * m_84));
            ptPos.z = ptTarget.z;
            Vector3 ptDist = (ptTarget - ptPos);
            m_50 = ptDist.Length();
            m_50 = efd::Clamp(m_50, m_124, m_128);
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

        Vector3 ptMove = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d00();
        if (reinterpret_cast<const efd::Point3&>(ptMove) != reinterpret_cast<const efd::Point3&>(g_143b01a60) || m_108)
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
                m_84 += fZoom * 2000.0f;
                m_84 = efd::Clamp(m_84, -50.0f, 50.0f);
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
                Vector3 ptDist = (ptCenter - ptPos);
                m_50 = ptDist.Length();
                m_50 = efd::Clamp(m_50, m_124, m_128);
                ptPos.x = m_50 * FUN_1409f25a0(m_68) + ptCenter.x;
                ptPos.y = m_50 * FUN_1409f2310(m_68) + ptCenter.y;
                ptPos.z = m_50 * FUN_1409f2310(m_6c) + ptCenter.z;
                m_d8.m_pos = ptPos;
                m_d8.m_rot = FUN_1410a0a00(ptPos);
                vfunc_37();
            }
            TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(g_143b01a60);
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
    TSingleton<CameraMgr>::GetInstance()->FUN_140aec8a0(true);
    vfunc_31();
    m_68 = m_48;
    m_10c = m_68;
    m_6c = m_4c;
    Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
    if (pTarget)
    {
        NiAVObject* pNode = FUN_141b6efc0(reinterpret_cast<GameObject*>(pTarget)->FUN_14123c410());
        Unk_EfdMatrix3 kRot = *((struct Unk_EfdMatrix3 const*)&((class NiAVObject*)(pNode))->GetWorldRotate());
        m_78 = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pTarget->vfunc_18())) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_118) * reinterpret_cast<const efd::Matrix3&>(kRot)))))));
        if (n == 0)
            vfunc_3(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_78) + reinterpret_cast<const efd::Point3&>(m_setting.m_c))));
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
    m_9c = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_ClientConfig*)GetClientConstants())->m_1a80)->Read();
    m_a0 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_ClientConfig*)GetClientConstants())->m_1ad8)->Read();
    m_a4 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_ClientConfig*)GetClientConstants())->m_1b30)->Read();
    m_108 = 1;
}
MS2_REPLACE_METHOD(0x14109fc60, CConsoleCameraMode, vfunc_6, 1298, 0x3DB4BDAE);

// @0x1410a0180
void CConsoleCameraMode::vfunc_30()
{
    float fX;
    float fY;
    ((CWindowService*)FUN_140aadf80())->GetCursorClientPos(&fX, &fY);
    efd::SmartPointer<ecr::PickService::PickRecord> pList = TSingleton<CameraMgr>::GetInstance()->FUN_140af0850(fX, fY, true, true, false, NULL);
    if (!(ecr::PickService::PickRecord*)pList)
        return;
    WorldService* pContext = WorldService::GetInstance();
    for (unsigned int i = 0; i < pList->GetPickResult()->GetSize(); ++i)
    {
        Unk_PickEntry* pEntry = reinterpret_cast<Unk_PickEntry*>(pList->GetPickResult()->GetAt(i));
        Unk_CameraTargetEntity* pObject = reinterpret_cast<Unk_CameraTargetEntity*>(pContext->FUN_141bd1050(reinterpret_cast<NiPick::Record*>(pEntry)->GetAVObject()));
        Unk_RpgActor* pActor = reinterpret_cast<Unk_RpgActor*>(efd::DynamicCast<PCBase, GameObject>(reinterpret_cast<GameObject*>(pObject)));
        if (pActor)
        {
            TSingleton<CameraMgr>::GetInstance()->FUN_140aeaf40(pActor, 1);
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x1410a0180, CConsoleCameraMode, vfunc_30, 326, 0x2CCF8E9B);

// @0x1410a02d0
BOOL CConsoleCameraMode::vfunc_31()
{
    if (LoadTestCamerValue())
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
        NiPoint3 ptDelta(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((m_d8.m_pos - m_c0.m_pos))));
        float fDist = ptDelta.Length();
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
                m_c0.m_pos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_c0.m_pos) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((t * (m_d8.m_pos - m_c0.m_pos))))));
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
    Vector3 kDir = (ptTarget - ptPos);
    kDir.Unitize();
    efd::Point3 kRight = reinterpret_cast<const efd::Point3&>(kDir).Cross(reinterpret_cast<const efd::Point3&>(g_143a08cf8));
    kRight.Unitize();
    efd::Point3 kUp = reinterpret_cast<const efd::Point3&>(kRight).Cross(reinterpret_cast<const efd::Point3&>(kDir));
    NiMatrix3 kRot((const efd::Point3&)kDir, (const efd::Point3&)kUp, (const efd::Point3&)kRight);
    float fZ;
    float fY;
    float fX;
    reinterpret_cast<const efd::Matrix3*>(&kRot)->ToEulerAnglesXYZ(fX, fY, fZ);
    return (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-fX, -fY, -fZ))) * 180.0f)) / 3.14159265f);
}
MS2_REPLACE_METHOD(0x1410a0a00, CConsoleCameraMode, FUN_1410a0a00, 416, 0xC0E11021);

// memcpy_s 0x1410a0c10 and memmove_s 0x1410a0d60 close the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_consoleCameraModeMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
__declspec(selectany) extern errno_t(__cdecl* const ms2_consoleCameraModeMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
