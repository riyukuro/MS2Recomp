// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See toolsmoothcameramode.h.
// MS2-UNIT: ?\toolsmoothcameramode.cpp
// MS2-RANGE: 0x14010e180-0x14010e4a0 .text$di
// MS2-RANGE: 0x141856e00-0x1418589b0 .text$mn
// MS2-PIN: ??__Es_pointer1@@YAXXZ 0x14010e1e0 ; <ecr/PickService.h> brings the look-alike egf::kENTITY_INVALID/kEVT_INVALID initializers
// MS2-PIN: ??__Es_pointer2@@YAXXZ 0x14010e370
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolsmoothcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>

#include "toolsmoothcameramode.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/fielddatacli.h"   // MS2Ptr<CFieldDataCli> (the camera option row)
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
#include <efd/Matrix3.h>   // C3: efd::Matrix3::FromEulerAnglesXYZ
#include <NiPoint3.h>
#include <NiPick.h>
#include <ecr/PickService.h>
#include "ms2/client/ms2/pcbase.h"  // C3: PCBase (efd::DynamicCast<PCBase, GameObject>)

// The shared eight-byte null-handle wrapper; constructor forwards to its pointer setter.
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
// MS2_CHECK_SIZE(Unk_BuddyHandle, 8);
static CString s_skill1("skill");
static CString s_stun1("stun");
static egf::EntityID s_pointer1(0);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames1[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_skill2("skill");
static CString s_stun2("stun");
static egf::EntityID s_pointer2(0);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames2[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The camera option row held by the game context (+0x154 rotation).
struct Unk_CameraOption
{
    char m_pad_000[0x154];
    float m_154;
};

// A field actor (efd::DynamicCast<PCBase, GameObject> casts an object to it).
class Unk_RpgActor : public Unk_CameraTargetEntity
{
};

// The game context (FUN_1403ed2d0).
class CameraMgr   // C3: member view (real class not in this TU)
{
public:
    Vector3 FUN_140a38d00();   // C3: was Unk_CameraManager::FUN_140a38d00
    void FUN_140a38d90(Vector3 pt);   // C3: was Unk_CameraManager::FUN_140a38d90
    efd::SmartPointer<ecr::PickService::PickRecord> FUN_140af0850(float fX, float fY, bool bFrontOnly, bool bAppCulled, bool bClosestOnly,
        NiAVObject* pRoot);                                         // pick the scene under a window point
    void FUN_140aeaf40(Unk_CameraTargetEntity* pTarget, int n);   // set the camera target
    class Unk_CameraTargetEntity* FUN_140a38d60();   // C3: bosstargetcamera.cpp
};
class Unk_GameContext
{
public:
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
    MS2Ptr<class CFieldDataCli> FUN_141bd30a0();   // the field data (copy of +0x298)
    class Unk_WsC_GameObj* FUN_141bd1050(void* mesh);   // C3: was Unk_GameContext::FUN_141bd1050
};

class Unk_PickEntry;
// The cursor (FUN_140aadf80).
class CWindowService { public: int GetCursorClientPos(float *, float *); }; class Unk_Cursor : public CWindowService {
public:

};
void* FUN_140aadf80();   // C3: was FUN_140aadf80

// Camera tuning values of the camera xml (FUN_140ae8910 consumes its by-value CString key).
float FUN_140ae8910(CString key);
int LoadTestCamerValue();                                // reloads the camera xml (returns 0 on failure)

float FUN_14059d930(float f);                       // fabs
bool FUN_14028d470(float a, float b);               // nearly equal
void FUN_1412751f0(const CStringW& str, int a, int b);     // chat/debug log line
#include "ms2/ms2format.h"
template <class T> class TSingleton;
class CameraMgr;
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };   // C3: 0x1409478c0, as camera.h declares it

extern int DAT_143ab0248;
extern int DAT_143ab2914;

// efd::Matrix3::GetCol (0x1418588c0, this obj's COMDAT)
// @0x1418588c0
void FUN_1418588c0(const Unk_EfdMatrix3* pMatrix, unsigned int uiCol, float* pOut)
{
    pOut[0] = pMatrix->m_afEntry[0][uiCol];
    pOut[1] = pMatrix->m_afEntry[1][uiCol];
    pOut[2] = pMatrix->m_afEntry[2][uiCol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141856e00
CToolSmoothCameraMode::CToolSmoothCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CConsoleCameraMode(pOwner, pPrev),
      m_130(),
      m_13c(g_143b01a60),
      m_148(g_143b01a60),
      m_154(50.0f),
      m_158(360.0f),
      m_15c(5.0f),
      m_160(1.0f)
{
}

// @0x141856f30
CToolSmoothCameraMode::~CToolSmoothCameraMode()
{
}

// @0x141856f60
void CToolSmoothCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_148 = m_13c = m_130 = g_143b01a60;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x11, false, 0))
        m_130.x = m_154 * m_160;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1f, false, 0))
        m_130.x = -m_154 * m_160;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1e, false, 0))
        m_130.y = m_154 * m_160;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x20, false, 0))
        m_130.y = -m_154 * m_160;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x10, false, 0))
        ptMove.y = m_158 * m_160;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x12, false, 0))
        ptMove.y = -m_158 * m_160;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x39, false, 0))
        m_148.z = m_154 * m_160 * 10.0f;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x2e, false, 0))
        m_148.z = -m_154 * m_160 * 10.0f;
    unsigned int bLeft = ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(0, false, 0);
    unsigned int bRight = ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, false, 0);
    int nX;
    int nY;
    int nWheel;
    unsigned int bMoved = ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dbf0(&nX, &nY, &nWheel, false, 0);
    if (bMoved != 0)
    {
        if (bRight != 0)
        {
            if (bLeft != 0)
            {
                m_148.z = m_148.z - (float)nY * 100.0f;
            }
            else
            {
                m_13c.x = (float)nX * m_15c * m_160;
                m_13c.y = (float)nY * m_15c * m_160;
                m_50 = efd::Clamp(m_50 + (float)nWheel, m_58, m_54);
            }
        }
        else if (FUN_14028d470(m_130.x, 0.0f))
        {
            if (nWheel > 0)
                m_130.x = 300.0f;
            else if (nWheel < 0)
                m_130.x = -300.0f;
        }
    }
    TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x141856F60, CToolSmoothCameraMode, vfunc_9, 1292, 0xF2E237FE);

// @0x141857480
void CToolSmoothCameraMode::vfunc_8(double fTime)
{
    bool bEnabled = true;
    if (DAT_143ab0248 == 2)
        bEnabled = DAT_143ab2914 >= 0x34;
    if (bEnabled)
    {
        if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1d, true, 0) || ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x6b, true, 0))
        {
            float fOld = m_160;
            if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x52, true, 0) || ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0xb, true, 0))
                m_160 = 1.0f;
            else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x4e, true, 0) || ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0xd, true, 0))
                m_160 = m_160 + 0.05f;
            else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x4a, true, 0) || ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0xc, true, 0))
                m_160 = m_160 - 0.05f;
            float fMax = 3.0f;
            m_160 = (std::min)(m_160, fMax);
            float fMin = 0.05f;
            m_160 = (std::max)(m_160, fMin);
            if (fOld != m_160)
                FUN_1412751f0(StringFormat<float>(L"move accelerate rate:{0}", m_160), 1, 1);
        }
    }
    Vector3 ptMove = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d00();
    float fRate = 15.0f;
    float fStep = efd::Clamp((float)fTime, 0.0f, 1.0f / fRate);
    float fScale = fStep;
    if (reinterpret_cast<const efd::Point3&>(m_148) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        m_148 = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_148) * fScale));
        m_c0.m_pos = m_d8.m_pos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_d8.m_pos) + reinterpret_cast<const efd::Point3&>(m_148)));
    }
    if (reinterpret_cast<const efd::Point3&>(m_13c) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        m_13c = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_13c) * fScale));
        Vector3 ptRot = FUN_140af8260();
        ptRot.y = ptRot.y - m_13c.x;
        ptRot.z = ptRot.z - m_13c.y;
        m_d8.m_rot = ptRot;
    }
    if (reinterpret_cast<const efd::Point3&>(ptMove) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        ptMove = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptMove) * fScale));
        Vector3 ptRot = m_c0.m_rot;
        ptRot.y = ptRot.y - ptMove.y;
        ptRot.z = ptRot.z - ptMove.z;
        m_d8.m_rot = ptRot;
    }
    if (reinterpret_cast<const efd::Point3&>(m_130) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        m_130 = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_130) * fScale));
        Vector3 ptAngle = m_c0.m_rot;
        ptAngle = (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptAngle) * 3.14159274f)) / 180.0f);
        Unk_EfdMatrix3 kRot;
        reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(ptAngle.x, ptAngle.y, ptAngle.z);
        Vector3 ptRight;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(0, reinterpret_cast<efd::Point3&>(ptRight));
        ptRight.Unitize();
        Vector3 ptForward;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(2, reinterpret_cast<efd::Point3&>(ptForward));
        ptForward.Unitize();
        Vector3 ptPos = m_d8.m_pos;
        ptPos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptPos) + (reinterpret_cast<const efd::Point3&>(ptRight) * m_130.x + reinterpret_cast<const efd::Point3&>(ptForward) * m_130.y) * 1000.0f * ((float)fTime)));
        m_d8.m_pos = ptPos;
    }
    vfunc_39(fTime);
    m_setting.m_c = m_d8.m_pos;
    m_setting.m_18 = m_d8.m_rot;
}

// @0x141857ce0
void CToolSmoothCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    vfunc_31();
    m_68 = m_48;
    m_6c = m_4c;
    CConsoleCameraMode::vfunc_6(n);
    Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
    if (pTarget)
    {
        float fRotation = reinterpret_cast<Unk_CameraOption*>(WorldService::GetInstance()->FUN_141bd30a0().operator->())->m_154;
        Vector3 ptRot(90.0f, fRotation, -60.0f);
        vfunc_4(ptRot);
        vfunc_24(pTarget, 1);
    }
    m_130 = g_143b01a60;
}
MS2_REPLACE_METHOD(0x141857CE0, CToolSmoothCameraMode, vfunc_6, 398, 0x0E152FB4);

// @0x141857e80
void CToolSmoothCameraMode::vfunc_39(double fTime)
{
    if (m_f0 != 0)
    {
        NiPoint3 ptDelta(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((m_d8.m_pos - m_c0.m_pos))));
        float fDist = ptDelta.Length();
        if (fDist <= 1.0f)
        {
            m_c0.m_pos = m_d8.m_pos;
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
                m_c0.m_pos = m_d8.m_pos;
            else
                m_c0.m_pos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_c0.m_pos) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((t * (m_d8.m_pos - m_c0.m_pos))))));
        }
        Unk_NiMatrix3 kCur;
        Unk_NiPoint3 ptCur((reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_c0.m_rot) * 3.14159274f)) / 180.0f));
        Unk_NiPoint3 ptWant((reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_d8.m_rot) * 3.14159274f)) / 180.0f));
        reinterpret_cast<efd::Matrix3*>(&kCur)->FromEulerAnglesXYZ(ptCur.x, ptCur.y, ptCur.z);
        Unk_NiMatrix3 kWant;
        reinterpret_cast<efd::Matrix3*>(&kWant)->FromEulerAnglesXYZ(ptWant.x, ptWant.y, ptWant.z);
        NiPoint3 ptColCur;
        NiPoint3 ptColWant;
        FUN_1418588c0(&kCur, 0, &ptColCur.x);
        FUN_1418588c0(&kWant, 0, &ptColWant.x);
        ptColCur.Unitize();
        ptColWant.Unitize();
        float fDot = ptColCur.Dot(ptColWant);
        float fBlend = FUN_14059d930(fDot) * (float)fTime * 8.0f;
        if (fBlend >= 1.0f)
            m_c0.m_rot = m_d8.m_rot;
        else
            m_c0.m_rot = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_c0.m_rot) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((fBlend * (m_d8.m_rot - m_c0.m_rot))))));
    }
    else
    {
        m_c0.m_pos = m_d8.m_pos;
        m_c0.m_rot = m_c0.m_rot;
        m_f0 = 1;
    }
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
}
MS2_REPLACE_METHOD(0x141857E80, CToolSmoothCameraMode, vfunc_39, 1524, 0x2FD06C6A);

// @0x141858480
void CToolSmoothCameraMode::vfunc_30()
{
    float fX;
    float fY;
    ((class Unk_Cursor*)FUN_140aadf80())->GetCursorClientPos(&fX, &fY);
    efd::SmartPointer<ecr::PickService::PickRecord> pList = TSingleton<CameraMgr>::GetInstance()->FUN_140af0850(fX, fY, true, true, false, NULL);
    if (!(ecr::PickService::PickRecord*)pList)
        return;
    Unk_GameContext* pContext = ((class Unk_GameContext*)WorldService::GetInstance());
    for (unsigned int i = 0; i < pList->GetPickResult()->GetSize(); ++i)
    {
        Unk_PickEntry* pEntry = reinterpret_cast<Unk_PickEntry*>(pList->GetPickResult()->GetAt(i));
        Unk_CameraTargetEntity* pObject = reinterpret_cast<Unk_CameraTargetEntity*>(reinterpret_cast<WorldService*>(pContext)->FUN_141bd1050(reinterpret_cast<NiPick::Record*>(pEntry)->GetAVObject()));
        Unk_RpgActor* pActor = reinterpret_cast<Unk_RpgActor*>(efd::DynamicCast<PCBase, GameObject>(reinterpret_cast<GameObject*>(pObject)));
        if (pActor)
        {
            TSingleton<CameraMgr>::GetInstance()->FUN_140aeaf40(pActor, 1);
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x141858480, CToolSmoothCameraMode, vfunc_30, 326, 0x992A3EE3);

// @0x1418585d0
void CToolSmoothCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    CConsoleCameraMode::vfunc_24(p, n);
    if (p)
    {
        m_50 = (m_c0.m_pos - p->vfunc_18()).Length();
        m_78 = p->vfunc_18();
        m_78.z = m_78.z + vfunc_27();
        Vector3 ptRot = FUN_1410a0a00(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(FUN_1409f2540())));
        vfunc_4(ptRot);
        m_d8.m_rot = ptRot;
        m_c0.m_rot = ptRot;
    }
}
MS2_REPLACE_METHOD(0x1418585D0, CToolSmoothCameraMode, vfunc_24, 434, 0x00620478);

// @0x141858790
BOOL CToolSmoothCameraMode::vfunc_31()
{
    if (LoadTestCamerValue())
    {
        m_154 = FUN_140ae8910(CString("ToolSmooth_KeyMoveSpeed"));
        m_158 = FUN_140ae8910(CString("ToolSmooth_KeyRotationSpeed"));
        m_15c = FUN_140ae8910(CString("ToolSmooth_MouseRotationSpeed"));
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141858790, CToolSmoothCameraMode, vfunc_31, 213, 0x5FEEEF7C);

// @0x141858980
CRuntimeClass* FUN_141858980()
{
    return CDialog::GetThisClass();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbbe70-0x142cbbf90 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x1418588c0, FUN_1418588c0, 162, 0x1E8F04A1);
MS2_REPLACE_METHOD(0x141857480, CToolSmoothCameraMode, vfunc_8, 2134, 0x211EFDDB);
MS2_REPLACE(0x141858980, FUN_141858980, 14, 0xFC327C3B);

