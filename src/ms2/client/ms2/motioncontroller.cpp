// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See motioncontroller.h.
// MS2-UNIT: ?\motioncontroller.cpp
// MS2-RANGE: 0x1400f8050-0x1400f82a0 .text$di
// MS2-RANGE: 0x142cb29c0-0x142cb2a45 .text$yd
// MS2-RANGE: 0x141487ed0-0x141489aa0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\motioncontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include <efd/Matrix3.h>   // C3: efd::Matrix3::FromEulerAnglesXYZ, MakeZRotation

#include "motioncontroller.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef unsigned __int64 u64;

// ---- out-of-unit callees ----
// The actor's physics body (FUN_14166d220) and what the movement checks ask of it.
class Unk_MotionBody;
class GameObjectController   // C3: member view for the former free stand-ins
{
public:
    int IsJumping();
    int IsLift();
};
// The motion record and the actor's skill state.
class CSkillRecord   // C3: member view for the former free stand-ins
{
public:
    class SkillMotionData* GetMotionData();
    float FUN_141759b60(double);
    float FUN_141759d20(double, float);
};
class CEquipment   // C3: member view for the former free stand-ins
{
public:
    float FUN_1411e0f50(float);
};
bool FUN_14028d470(float a, float b);                               // nearly equal
__int64 FUN_14028d260(float f);                                     // float -> fixed
int FUN_1416725c0(PCBase* p, Vector3 kDir, float fSpeed, float fMax, float fZero);  // move is blocked
float FUN_141b71550(Vector3 kStart, Vector3 kCtrl, Vector3 kEnd);   // bezier length
Vector3 FUN_141b71390(Vector3 kStart, Vector3 kCtrl, Vector3 kEnd, float t);   // bezier point
class CLogString* GetLogString();   // C3: was FUN_140166440
int FUN_141489940(PCBase* p);
void FUN_1414894f0(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat,
                   const float* pA, const float* pB, const float* pC, const float* pD);

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
#define DAT_143a08cd8 (*(Vector3*)&efd::Point3::UNIT_X)        // C3: was extern Vector3 DAT_143a08cd8 (reference axis)
#define DAT_143a08cf8 (*(Vector3*)&efd::Point3::UNIT_Z)        // C3: was extern Vector3 DAT_143a08cf8 (up axis)

// @0x141489940
int FUN_141489940(PCBase* p)
{
    return p->m_unk_c00;
}

// ---- static initializers (.text$di) ----
#ifndef MS2_HOOK_DLL
// @0x1400f8050 CArcMotionController, 0x1400f8080 CBlinkMotionController, 0x1400f80b0 CLinearMotionController,
// 0x1400f80e0 CMotionController, 0x1400f8100 CMoveMotionController
const NiRTTI CArcMotionController::ms_RTTI("CArcMotionController", &CMotionController::ms_RTTI);
const NiRTTI CBlinkMotionController::ms_RTTI("CBlinkMotionController", &CMotionController::ms_RTTI);
const NiRTTI CLinearMotionController::ms_RTTI("CLinearMotionController", &CMotionController::ms_RTTI);
const NiRTTI CMotionController::ms_RTTI("CMotionController", 0);
const NiRTTI CMoveMotionController::ms_RTTI("CMoveMotionController", &CMotionController::ms_RTTI);
// @0x1400f8130..0x1400f8250: the sort names, "skill", "stun" and the condition table
#endif
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_1416561a0

// @0x141487ed0
CMotionController::CMotionController()
    : m_kMove(DAT_143b01a60), m_kDir(DAT_143b01a60), m_fSpeed(0), m_nPad34(0), m_nPad38(0), m_pData(0), m_pTarget(0), m_nType(0)
{
}

// @0x141487f90
CMotionController::~CMotionController()
{
}

// @0x141487fc0
int CMotionController::vfunc_2(Unk_MotionData* pData, PCBase* pTarget)
{
    m_kDir = DAT_143b01a60;
    m_fSpeed = 0;
    m_pData = pData;
    m_pTarget = pTarget;
    return 1;
}

// @0x141488030
Vector3 CMotionController::vfunc_3()
{
    return m_kMove;
}

// @0x141488060
int CMotionController::vfunc_4()
{
    return m_nPad38;
}

// Speed and move direction for this tick: the direction is the motion's base direction tilted by the skill's angle.
// @0x141488080
bool CMotionController::vfunc_5(double fTime)
{
    m_fSpeed = ((class CSkillRecord*)(struct Unk_MotionData*)(m_pData))->FUN_141759b60(fTime);
    if (((class PCBase*)(class PCBase*)(m_pTarget))->IsDashModel() != 0)
    {
        PCBase* pPc = efd::DynamicCast<PC, PCBase>(m_pTarget);
        if (pPc != 0)
            m_fSpeed = ((class CEquipment*)(void*)(reinterpret_cast<void*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())))->FUN_1411e0f50(m_fSpeed);
    }
    Vector3 kDir;
    float fTiltSpeed = 0;
    float fTiltAngle = 0;
    Unk_MotionTilt* pTilt = ((struct Unk_MotionTilt*)((class CSkillRecord*)(struct Unk_MotionData*)(m_pData))->GetMotionData());
    if (pTilt != 0)
    {
        fTiltSpeed = pTilt->m_fSpeed;
        fTiltAngle = pTilt->m_fAngle;
    }
    if (FUN_14028d470(fTiltSpeed, 0) && FUN_14028d470(m_pData->m_fSpeedScale, 0))
    {
        kDir = m_pData->m_kStart;
    }
    else
    {
        Vector3 kBase;
        PCBase* pPc = efd::DynamicCast<PC, PCBase>(m_pTarget);
        if (pPc != 0 && FUN_141489940(pPc) == 10)
        {
            Vector3 kEuler = m_pData->m_kDir.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
            Vector3 kAxis = DAT_143a08cd8;
            Unk_EfdMatrix3 mxEuler;
            reinterpret_cast<efd::Matrix3*>(&mxEuler)->FromEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
            kAxis = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(*reinterpret_cast<efd::Matrix3*>(&mxEuler) * reinterpret_cast<const efd::Point3&>(kAxis)));
            kBase = kAxis;
        }
        else
        {
            kBase = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(GameObject::RotationToDirection(reinterpret_cast<const NiPoint3&>(m_pData->m_kDir))));
        }
        Unk_EfdMatrix3 mxTilt;
        reinterpret_cast<efd::Matrix3*>(&mxTilt)->MakeZRotation((fTiltAngle * 3.1415927f) / 180.0f);
        kDir = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(*reinterpret_cast<efd::Matrix3*>(&mxTilt) * reinterpret_cast<const efd::Point3&>(kBase)));
        float fRad = (fTiltAngle * 3.1415927f) / 180.0f;
        if (0.0f < fRad)
        {
            Vector3 kAxis = kDir.FUN_140a00e10(DAT_143a08cf8);
            kAxis.FUN_140968990();
            mxTilt.FUN_14107cc40(-fRad, kAxis);
            kDir = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(*reinterpret_cast<efd::Matrix3*>(&mxTilt) * reinterpret_cast<const efd::Point3&>(kDir)));
        }
    }
    m_kDir = kDir;
    m_kDir.FUN_140968990();
    return false;
}

// @0x141488470
int CMotionController::vfunc_6()
{
    return m_nType;
}

// @0x141488490
CArcMotionController::CArcMotionController()
{
    m_nType = 1;
}

// Arms the arc: the destination is a fixed distance along the tilted base direction, the bezier control point sits on
// the line start-destination.
// @0x141488520
int CArcMotionController::vfunc_2(Unk_MotionData* pData, PCBase* pTarget)
{
    CMotionController::vfunc_2(pData, pTarget);
    m_dElapsed = 0;
    m_dDuration = m_pData->m_fDuration;
    m_dDuration = 0.4f;
    m_kStartPos = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18()));
    Vector3 kRot;
    Vector3 kBase;
    PCBase* pPc = efd::DynamicCast<PC, PCBase>(pTarget);
    if (pPc != 0 && FUN_141489940(pPc) == 10)
    {
        Vector3 kEuler = m_pData->m_kDir.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
        Vector3 kAxis = DAT_143a08cd8.FUN_1409f7960();
        Unk_EfdMatrix3 mxEuler;
        reinterpret_cast<efd::Matrix3*>(&mxEuler)->FromEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
        kAxis = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(*reinterpret_cast<efd::Matrix3*>(&mxEuler) * reinterpret_cast<const efd::Point3&>(kAxis)));
        kBase = kAxis;
    }
    else
    {
        kBase = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(GameObject::RotationToDirection(reinterpret_cast<const NiPoint3&>(m_pData->m_kDir))));
    }
    float fSpeed = 0;
    float fAngle = 0;
    float fCtrlHeight = 100.0f;
    float fCtrlWeight = 0.5f;
    Unk_MotionTilt* pTilt = ((struct Unk_MotionTilt*)((class CSkillRecord*)(struct Unk_MotionData*)(m_pData))->GetMotionData());
    if (pTilt != 0)
    {
        fSpeed = pTilt->m_fSpeed;
        fAngle = pTilt->m_fAngle;
    }
    Unk_EfdMatrix3 mxTilt;
    reinterpret_cast<efd::Matrix3*>(&mxTilt)->MakeZRotation((fAngle * 3.1415927f) / 180.0f);
    kRot = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(*reinterpret_cast<efd::Matrix3*>(&mxTilt) * reinterpret_cast<const efd::Point3&>(kBase)));
    float fRad = (fAngle * 3.1415927f) / 180.0f;
    if (0.0f < fRad)
    {
        Vector3 kAxis = kRot.FUN_140a00e10(DAT_143a08cf8);
        kAxis.FUN_140968990();
        mxTilt.FUN_14107cc40(-fRad, kAxis);
        kRot = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(*reinterpret_cast<efd::Matrix3*>(&mxTilt) * reinterpret_cast<const efd::Point3&>(kRot)));
    }
    m_kDir = kRot;
    if (!FUN_14028d470(m_pData->m_fSpeedScale, 0))
        fSpeed = m_pData->m_fSpeedScale;
    m_kEndPos = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18())).FUN_14097fd50(m_kDir.FUN_14097fc90(fSpeed));
    m_fCtrlHeight = fCtrlHeight;
    m_fCtrlWeight = fCtrlWeight;
    m_kCtrlPos = m_kStartPos.FUN_14097fc90(m_fCtrlWeight).FUN_14097fd50(m_kEndPos.FUN_14097fc90(1.0f - m_fCtrlWeight));
    m_kCtrlPos.z = m_kCtrlPos.z + m_fCtrlHeight;
    m_kMove = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18()));
    m_fSpeedLimit = FUN_141b71550(m_kStartPos, m_kCtrlPos, m_kEndPos);
    return 1;
}

// @0x141488b40
Vector3 CArcMotionController::vfunc_3()
{
    return m_kHeading.FUN_140ae9180(100.0f);
}

// @0x141488b80
int CArcMotionController::vfunc_4()
{
    return m_nPad38;
}

// @0x141488ba0
bool CArcMotionController::vfunc_5(double fTime)
{
    CMotionController::vfunc_5(fTime);
    m_dElapsed += fTime;
    Vector3 kUnused;
    m_fSpeed = ((class CSkillRecord*)(struct Unk_MotionData*)(m_pData))->FUN_141759d20(fTime, m_fSpeedLimit);
    float fT = (float)m_dElapsed / (float)m_dDuration;
    if (fT < 0.0f)
        fT = 0.0f;
    if (1.0f < fT)
        fT = 1.0f;
    Vector3 kPos = FUN_141b71390(m_kStartPos, m_kCtrlPos, m_kEndPos, fT);
    FUN_1414894f0(((void*)GetLogString()), 0xc, 0x13, L"{0} {1} {2} {3}", &fT, &kPos.x, &kPos.y, &kPos.z);
    m_kDir = kPos.FUN_140965c40(m_kMove);
    m_kHeading = m_kDir;
    m_kDir.FUN_140968990();
    m_kMove = kPos;
    return true;
}

// @0x141488df0
int CLinearMotionController::vfunc_2(Unk_MotionData* pData, PCBase* pTarget)
{
    CMotionController::vfunc_2(pData, pTarget);
    return 1;
}

// @0x141488e30
Vector3 CLinearMotionController::vfunc_3()
{
    return m_kMove;
}

// @0x141488e60
int CLinearMotionController::vfunc_4()
{
    return m_nPad38;
}

// Moves along the fixed direction unless the actor is blocked or the step is refused.
// @0x141488e80
bool CLinearMotionController::vfunc_5(double fTime)
{
    CMotionController::vfunc_5(fTime);
    m_kMove = DAT_143b01a60;
    int nProbe = 100;
    if (0.0f < m_pData->m_fDistance)
    {
        nProbe = nProbe + (int)FUN_14028d260(m_pData->m_fDistance);
    }
    int bBlocked = (m_pTarget->vfunc_99(nProbe) != 0 || ((class GameObjectController*)(class Unk_MotionBody*)(((class Unk_MotionBody*)((class PCBase*)(class PCBase*)(m_pTarget))->GetPhysicsBody())))->IsJumping() != 0
        || ((class GameObjectController*)(class Unk_MotionBody*)(((class Unk_MotionBody*)((class PCBase*)(class PCBase*)(m_pTarget))->GetPhysicsBody())))->IsLift() != 0) ? 1 : 0;
    if (bBlocked)
        return false;
    if (FUN_14028d470(m_fSpeed, 0))
    {
        m_kMove = DAT_143b01a60;
        return false;
    }
    if (reinterpret_cast<const efd::Point3&>(m_kDir) == reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
    {
        m_kMove = DAT_143b01a60;
        return false;
    }
    if (FUN_1416725c0(m_pTarget, m_kDir, m_fSpeed * 100.0f, 750.0f, 0.0f) == 0)
    {
        m_kMove = m_kDir.FUN_14097fc90(m_fSpeed);
    }
    else
    {
        m_pData->m_fPad7c = 0;
        m_pData->m_fDuration = 0;
        m_pData->m_fDistance = 0;
    }
    return true;
}

// @0x141489100
int CBlinkMotionController::vfunc_2(Unk_MotionData* pData, PCBase* pTarget)
{
    CMotionController::vfunc_2(pData, pTarget);
    return 1;
}

// @0x141489140
Vector3 CBlinkMotionController::vfunc_3()
{
    return m_kMove;
}

// @0x141489170
int CBlinkMotionController::vfunc_4()
{
    return m_nPad38;
}

// @0x141489190
bool CBlinkMotionController::vfunc_5(double fTime)
{
    return CMotionController::vfunc_5(fTime);
}

// @0x1414891c0
int CMoveMotionController::vfunc_2(Unk_MotionData* pData, PCBase* pTarget)
{
    CMotionController::vfunc_2(pData, pTarget);
    return 1;
}

// @0x141489200
Vector3 CMoveMotionController::vfunc_3()
{
    return m_kMove;
}

// @0x141489230
int CMoveMotionController::vfunc_4()
{
    return m_nPad38;
}

// Moves the actor along its input direction unless it is blocked or the step is refused.
// @0x141489250
bool CMoveMotionController::vfunc_5(double fTime)
{
    if (m_pTarget == 0)
        return false;
    CMotionController::vfunc_5(fTime);
    m_kMove = DAT_143b01a60;
    bool bBlocked = (m_pTarget->vfunc_99(0) != 0 || ((class GameObjectController*)(class Unk_MotionBody*)(((class Unk_MotionBody*)((class PCBase*)(class PCBase*)(m_pTarget))->GetPhysicsBody())))->IsJumping() != 0
        || ((class GameObjectController*)(class Unk_MotionBody*)(((class Unk_MotionBody*)((class PCBase*)(class PCBase*)(m_pTarget))->GetPhysicsBody())))->IsLift() != 0) ? true : false;
    if (bBlocked)
        return false;
    if (FUN_14028d470(m_fSpeed, 0))
    {
        m_kMove = DAT_143b01a60;
        return false;
    }
    m_kDir = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(m_pTarget->CalcMoveDirectionNoYaw(m_pTarget->FUN_14123c360())));
    if (reinterpret_cast<const efd::Point3&>(m_kDir) == reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
    {
        m_kMove = DAT_143b01a60;
        return false;
    }
    if (FUN_1416725c0(m_pTarget, m_kDir, m_fSpeed * 100.0f, 750.0f, 0.0f) == 0)
    {
        m_kMove = m_kDir.FUN_14097fc90(m_fSpeed);
    }
    else
    {
        m_pData->m_fPad7c = 0;
        m_pData->m_fDuration = 0;
        m_pData->m_fDistance = 0;
    }
    return true;
}

// ---- debug log of four floats (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0) ----
// @0x1414894f0
void FUN_1414894f0(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat,
                   const float* pA, const float* pB, const float* pC, const float* pD)
{
    const fmt::internal::ArgArray<4>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pA),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pB),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pC),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(*pD)};
    ((CLogString*)pLog)->FUN_1406530d0(nLevel, nCategory, pszFormat, fmt::ArgList(fmt::internal::make_type(*pA, *pB, *pC, *pD), args));
}

// @0x141489960
const NiRTTI* CArcMotionController::vfunc_1()
{
    return &ms_RTTI;
}

// @0x141489970
const NiRTTI* CMotionController::vfunc_1()
{
    return &ms_RTTI;
}

// The UCRT's `static __inline memmove_s`, kept by this TU (unreferenced).
// @0x141489980
MS2_EMIT_CRT_MEMMOVE_S();
