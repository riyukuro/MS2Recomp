// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See toolcameramode.h.
// MS2-UNIT: ?\toolcameramode.cpp
// MS2-RANGE: 0x141852c30-0x141853bc0 .text$mn
// MS2-PIN: ??_GCToolCameraMode@@UEAAPEAXI@Z 0x141853b60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Matrix3.h>   // C3: efd::Matrix3::FromEulerAnglesXYZ

#include "toolcameramode.h"

#include <NiAVObject.h>
#include <NiBound.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/fielddatacli.h"   // MS2Ptr<CFieldDataCli> (the camera option row)
#include "ms2/client/ms2/camera.h"

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The camera option row held by the game context (+0x154 rotation).
struct Unk_CameraOption
{
    char m_pad_000[0x154];
    float m_154;
};

class FieldProperty;

// The world service (FUN_1403ed2d0).
class Unk_GameContext : public WorldService
{
public:
};

// The game clock (TSingleton<CMainSystem>::GetInstance).

namespace egf { class Entity; }
class GameObject { public: egf::Entity* FUN_14123c410(); };   // C3: unit-local view
NiAVObject* FUN_141b6efc0(egf::Entity* p);
bool FUN_14028d470(float a, float b);                       // nearly equal

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141852c30
CToolCameraMode::CToolCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev),
      m_84(0),
      m_88(0),
      m_90(0)
{
}

// @0x141852cf0
CToolCameraMode::~CToolCameraMode()
{
}

// @0x141852d20
void CToolCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    if (m_84 == 0)
    {
        Unk_CameraTargetEntity* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60();
        if (pTarget)
        {
            m_84 = 1;
            float fRotation = reinterpret_cast<Unk_CameraOption*>(WorldService::GetInstance()->FUN_141bd30a0().operator->())->m_154;
            Vector3 ptRot(90.0f, fRotation, -60.0f);
            vfunc_4(ptRot);
            vfunc_24(pTarget, 1);
        }
    }
    m_90 = ((class Unk_GameContext*)WorldService::GetInstance())->FindFieldProperty(0xb) != 0;
}
MS2_REPLACE_METHOD(0x141852d20, CToolCameraMode, vfunc_6, 370, 0x51A5235E);

// @0x141852ea0
void CToolCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    m_8c = n;
    if (!p)
        return;
    m_88 = 1;
    Vector3 ptRot = FUN_140af8260();
    if (((class Unk_GameContext*)WorldService::GetInstance())->FUN_141bd3cd0() && ((class Unk_GameContext*)WorldService::GetInstance())->FUN_141bd3d10())
        ptRot.z = 0.0f;
    else
        ptRot.z = -45.0f;
    vfunc_4(ptRot);
    ptRot = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptRot) * 3.14159274f)).FUN_140ae9180(180.0f);
    Vector3 ptPos = p->vfunc_18();
    vfunc_3(ptPos);
    Unk_EfdMatrix3 kRot;
    reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(ptRot.x, ptRot.y, ptRot.z);
    Vector3 ptAxis;
    reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(0, reinterpret_cast<efd::Point3&>(ptAxis));
    ptAxis.FUN_140968990();
    float fDist = 200.0f;
    float fHeight = 0.0f;
    if (n == 0)
        fDist = 600.0f;
    ptPos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptPos) + reinterpret_cast<const efd::Point3&>(ptAxis) * (-fDist)));
    vfunc_3(ptPos);
    NiAVObject* pNode = FUN_141b6efc0(reinterpret_cast<GameObject*>(p)->FUN_14123c410());
    if (!pNode)
        return;
    pNode->Update((float)TSingleton<CMainSystem>::GetInstance()->FUN_141473280(), true);
    pNode->UpdateWorldBound();
    const NiBound& kBound = ((class NiAVObject*)(class NiAVObject*)(pNode))->GetWorldBound();
    fDist = ((class NiBound*)&(kBound))->GetRadius();
    fHeight = (((class NiBound*)&(kBound))->GetCenter().z - ptPos.z < 0.0f) ? 0.0f : ((class NiBound*)&(kBound))->GetCenter().z - ptPos.z;
    if (n != 0)
    {
        ptPos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>((reinterpret_cast<const efd::Point3&>(ptPos) + reinterpret_cast<const efd::Point3&>(ptAxis) * (-fDist)) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, fHeight)))));
        vfunc_3(ptPos);
    }
    m_88 = 0;
}
MS2_REPLACE_METHOD(0x141852ea0, CToolCameraMode, vfunc_24, 1078, 0xF25AE606);

// @0x1418532e0
void CToolCameraMode::vfunc_8(double fTime)
{
    if (m_88)
    {
        vfunc_24(TSingleton<CameraMgr>::GetInstance()->FUN_140a38d60(), m_8c);
    }
    Vector3 ptMove = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d00();
    unsigned int bShift = ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x2a, false, 0);
    unsigned int bLeft = ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(0, false, 0);
    unsigned int bRight = ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, false, 0);
    if (bLeft != 0 && bRight != 0)
    {
        efd::Point3 ptPos = FUN_1409f2540();
        ptPos.z = ptPos.z - ptMove.z * 2.0f;
        vfunc_3(reinterpret_cast<Vector3&>(ptPos));
    }
    else if (bShift == 0 && bRight != 0)
    {
        if (!((class Unk_GameContext*)WorldService::GetInstance())->FUN_141bd3cd0() || ((class Unk_GameContext*)WorldService::GetInstance())->FUN_141bd3d10() == 1)
        {
            if (reinterpret_cast<const efd::Point3&>(ptMove) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
            {
                Vector3 ptRot = FUN_140af8260();
                ptRot.y = ptRot.y - ptMove.y / 512.0f * 90.0f;
                ptRot.z = ptRot.z - ptMove.z / 512.0f * 90.0f;
                vfunc_4(ptRot);
            }
        }
    }
    if (reinterpret_cast<const efd::Point3&>(m_78) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        Vector3 ptRot = FUN_140af8260();
        ptRot = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptRot) * 3.14159274f)).FUN_140ae9180(180.0f);
        Unk_EfdMatrix3 kRot;
        reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(ptRot.x, ptRot.y, ptRot.z);
        Vector3 ptRight;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(0, reinterpret_cast<efd::Point3&>(ptRight));
        ptRight.FUN_140968990();
        Vector3 ptForward;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(2, reinterpret_cast<efd::Point3&>(ptForward));
        ptForward.FUN_140968990();
        efd::Point3 ptPos = FUN_1409f2540();
        reinterpret_cast<Vector3&>(ptPos) = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(reinterpret_cast<Vector3&>(ptPos)) + (reinterpret_cast<const efd::Point3&>(ptRight) * m_78.x + reinterpret_cast<const efd::Point3&>(ptForward) * m_78.y) * 1000.0f * ((float)fTime)));
        vfunc_3(reinterpret_cast<Vector3&>(ptPos));
    }
}
MS2_REPLACE_METHOD(0x1418532e0, CToolCameraMode, vfunc_8, 1177, 0xB27624DC);

// @0x141853780
void CToolCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_78 = g_143b01a60;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x11, false, 0))
    {
        if (FUN_140af8140())
        {
            if (0.01f < m_70)
                m_70 = m_70 - 0.01f;
            else
                m_70 = 0.01f;
        }
        else
        {
            m_78.x = 1.0f;
        }
    }
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1f, false, 0))
    {
        if (FUN_140af8140())
            m_70 = m_70 + 0.01f;
        else
            m_78.x = -1.0f;
    }
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1e, false, 0))
        m_78.y = 1.0f;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x20, false, 0))
        m_78.y = -1.0f;
    int nX;
    int nY;
    int nWheel;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dbf0(&nX, &nY, &nWheel, false, 0))
    {
        ptMove.y = (float)nX;
        ptMove.z = (float)nY;
        if (FUN_14028d470(m_78.x, 0.0f))
        {
            if (nWheel > 0)
                m_78.x = 15.0f;
            else if (nWheel < 0)
                m_78.x = -15.0f;
        }
    }
    TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(ptMove);
    if (FUN_140af8140())
        TSingleton<CameraMgr>::GetInstance()->FUN_140af0170(m_70, true);
}
MS2_REPLACE_METHOD(0x141853780, CToolCameraMode, vfunc_9, 687, 0x270105CE);

// @0x141853a40
void CToolCameraMode::vfunc_3(Vector3 pt)
{
    if (m_90)
    {
        efd::Point3 ptCur = FUN_1409f2540();
        Vector3 ptOut;
        if (!((class Unk_GameContext*)WorldService::GetInstance())->FUN_141bd36f0(pt, &ptOut))
        {
            if (!FUN_14028d470(ptOut.x, 0.0f))
                pt.x = ptCur.x;
            if (!FUN_14028d470(ptOut.y, 0.0f))
                pt.y = ptCur.y;
            if (!FUN_14028d470(ptOut.z, 0.0f))
                pt.z = ptCur.z;
        }
    }
    CCameraMode::vfunc_3(pt);
}
MS2_REPLACE_METHOD(0x141853a40, CToolCameraMode, vfunc_3, 282, 0xDAD5715B);
