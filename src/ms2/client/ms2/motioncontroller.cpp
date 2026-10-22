// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See motioncontroller.h.
// MS2-UNIT: ?\motioncontroller.cpp
// MS2-RANGE: 0x1400f8050-0x1400f82a0 .text$di
// MS2-RANGE: 0x142cb29c0-0x142cb2a45 .text$yd
// MS2-RANGE: 0x141487ed0-0x141489aa0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\motioncontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "motioncontroller.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef unsigned __int64 u64;

// ---- out-of-unit callees ----
// The actor's physics body (FUN_14166d220) and what the movement checks ask of it.
class Unk_MotionBody;
Unk_MotionBody* FUN_14166d220(PCBase* p);
int FUN_141240780(Unk_MotionBody* p);                               // body is blocked (a)
int FUN_141240db0(Unk_MotionBody* p);                               // body is blocked (b)
// The motion record and the actor's skill state.
float FUN_141759b60(Unk_MotionData* pData, double fTime);           // speed for this tick
Unk_MotionTilt* FUN_141759830(Unk_MotionData* pData);
float FUN_141759d20(Unk_MotionData* pData, double fTime, float fLimit);
int FUN_1416719c0(PCBase* p);
PCBase* FUN_140974230(PCBase* p);                                   // owning pc of the target
void* FUN_1416561a0(PCBase* p);                                     // skill component
float FUN_1411e0f50(void* pSkill, float fSpeed);                    // speed after skill bonuses
bool FUN_14028d470(float a, float b);                               // nearly equal
int FUN_14028d260(float f);                                         // float -> fixed
Vector3 FUN_14123cc80(Vector3 kDir);                // facing direction -> move direction
Vector3* FUN_14123c360(PCBase* p, Vector3* pOut);   // input move direction (member: this=rcx, hidden return=rdx)
Vector3* FUN_141674b60(PCBase* p, Vector3* pOut, Vector3* pDir);   // move direction on the ground (by-value dir = pointer to a copy)
int FUN_1416725c0(PCBase* p, Vector3 kDir, float fSpeed, float fMax, float fZero);  // move is blocked
float FUN_141b71550(Vector3 kStart, Vector3 kCtrl, Vector3 kEnd);   // bezier length
Vector3 FUN_141b71390(Vector3 kStart, Vector3 kCtrl, Vector3 kEnd, float t);   // bezier point
void* FUN_140166440();                                              // the logger
int FUN_141489940(PCBase* p);
void FUN_1414894f0(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat,
                   const float* pA, const float* pB, const float* pC, const float* pD);

extern Vector3 DAT_143b01a60;       // zero point
extern Vector3 DAT_143a08cd8;       // reference axis of the type 10 base direction
extern Vector3 DAT_143a08cf8;       // up axis

// @0x141489940
int FUN_141489940(PCBase* p)
{
    return p->m_unk_c00;
}

// Views a NiPoint3 returned by PCBase::vfunc_18 as the unit's point type (same 12 byte layout).
static const Vector3& AsPoint(const NiPoint3& kPt)
{
    return reinterpret_cast<const Vector3&>(kPt);
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
// MS2-FUNCTIONAL: float/matrix temporaries and the goto-merged tail of the exe are laid out differently.
bool CMotionController::vfunc_5(double fTime)
{
    m_fSpeed = FUN_141759b60(m_pData, fTime);
    if (FUN_1416719c0(m_pTarget) != 0)
    {
        PCBase* pPc = FUN_140974230(m_pTarget);
        if (pPc != 0)
            m_fSpeed = FUN_1411e0f50(FUN_1416561a0(pPc), m_fSpeed);
    }
    Vector3 kDir;
    float fTiltSpeed = 0;
    float fTiltAngle = 0;
    Unk_MotionTilt* pTilt = FUN_141759830(m_pData);
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
        PCBase* pPc = FUN_140974230(m_pTarget);
        if (pPc != 0 && FUN_141489940(pPc) == 10)
        {
            Vector3 kEuler = m_pData->m_kDir.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
            Vector3 kAxis = DAT_143a08cd8;
            Unk_EfdMatrix3 mxEuler;
            mxEuler.FUN_142083d40(kEuler.x, kEuler.y, kEuler.z);
            kAxis = mxEuler.FUN_140a00720(kAxis);
            kBase = kAxis;
        }
        else
        {
            Vector3 kFacing = m_pData->m_kDir;
            kBase = FUN_14123cc80(kFacing);
        }
        Unk_EfdMatrix3 mxTilt;
        mxTilt.FUN_142084c10((fTiltAngle * 3.1415927f) / 180.0f);
        kDir = mxTilt.FUN_140a00720(kBase);
        float fRad = (fTiltAngle * 3.1415927f) / 180.0f;
        if (0.0f < fRad)
        {
            Vector3 kAxis = kDir.FUN_140a00e10(DAT_143a08cf8);
            kAxis.FUN_140968990();
            mxTilt.FUN_14107cc40(-fRad, kAxis);
            kDir = mxTilt.FUN_140a00720(kDir);
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
// MS2-FUNCTIONAL: float/matrix temporaries and the goto-merged tail of the exe are laid out differently.
int CArcMotionController::vfunc_2(Unk_MotionData* pData, PCBase* pTarget)
{
    CMotionController::vfunc_2(pData, pTarget);
    m_dElapsed = 0;
    m_dDuration = m_pData->m_fDuration;
    m_dDuration = 0.4f;
    m_kStartPos = AsPoint(pTarget->vfunc_18());
    Vector3 kRot;
    Vector3 kBase;
    PCBase* pPc = FUN_140974230(pTarget);
    if (pPc != 0 && FUN_141489940(pPc) == 10)
    {
        Vector3 kEuler = m_pData->m_kDir.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
        Vector3 kAxis = DAT_143a08cd8.FUN_1409f7960();
        Unk_EfdMatrix3 mxEuler;
        mxEuler.FUN_142083d40(kEuler.x, kEuler.y, kEuler.z);
        kAxis = mxEuler.FUN_140a00720(kAxis);
        kBase = kAxis;
    }
    else
    {
        Vector3 kFacing = m_pData->m_kDir;
        kBase = FUN_14123cc80(kFacing);
    }
    float fSpeed = 0;
    float fAngle = 0;
    float fCtrlHeight = 100.0f;
    float fCtrlWeight = 0.5f;
    Unk_MotionTilt* pTilt = FUN_141759830(m_pData);
    if (pTilt != 0)
    {
        fSpeed = pTilt->m_fSpeed;
        fAngle = pTilt->m_fAngle;
    }
    Unk_EfdMatrix3 mxTilt;
    mxTilt.FUN_142084c10((fAngle * 3.1415927f) / 180.0f);
    kRot = mxTilt.FUN_140a00720(kBase);
    float fRad = (fAngle * 3.1415927f) / 180.0f;
    if (0.0f < fRad)
    {
        Vector3 kAxis = kRot.FUN_140a00e10(DAT_143a08cf8);
        kAxis.FUN_140968990();
        mxTilt.FUN_14107cc40(-fRad, kAxis);
        kRot = mxTilt.FUN_140a00720(kRot);
    }
    m_kDir = kRot;
    if (!FUN_14028d470(m_pData->m_fSpeedScale, 0))
        fSpeed = m_pData->m_fSpeedScale;
    Vector3 kStep = m_kDir.FUN_14097fc90(fSpeed);
    m_kEndPos = AsPoint(pTarget->vfunc_18()).FUN_14097fd50(kStep);
    m_fCtrlHeight = fCtrlHeight;
    m_fCtrlWeight = fCtrlWeight;
    Vector3 kEndPart = m_kEndPos.FUN_14097fc90(1.0f - m_fCtrlWeight);
    m_kCtrlPos = m_kStartPos.FUN_14097fc90(m_fCtrlWeight).FUN_14097fd50(kEndPart);
    m_kCtrlPos.z = m_kCtrlPos.z + m_fCtrlHeight;
    m_kMove = AsPoint(pTarget->vfunc_18());
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
    m_fSpeed = FUN_141759d20(m_pData, fTime, m_fSpeedLimit);
    float fT = (float)m_dElapsed / (float)m_dDuration;
    if (fT < 0.0f)
        fT = 0.0f;
    if (1.0f < fT)
        fT = 1.0f;
    Vector3 kPos = FUN_141b71390(m_kStartPos, m_kCtrlPos, m_kEndPos, fT);
    FUN_1414894f0(FUN_140166440(), 0xc, 0x13, L"{0} {1} {2} {3}", &fT, &kPos.x, &kPos.y, &kPos.z);
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
// MS2-FUNCTIONAL: the blocked-flag temporaries and by-value point copy are laid out differently.
bool CLinearMotionController::vfunc_5(double fTime)
{
    CMotionController::vfunc_5(fTime);
    m_kMove = DAT_143b01a60;
    int nProbe = 100;
    if (0.0f < m_pData->m_fDistance)
    {
        nProbe = FUN_14028d260(m_pData->m_fDistance);
        nProbe = nProbe + 100;
    }
    int bBlocked;
    if (m_pTarget->vfunc_99(nProbe) == 0 && FUN_141240780(FUN_14166d220(m_pTarget)) == 0
        && FUN_141240db0(FUN_14166d220(m_pTarget)) == 0)
        bBlocked = 0;
    else
        bBlocked = 1;
    if (bBlocked)
        return false;
    if (FUN_14028d470(m_fSpeed, 0))
    {
        m_kMove = DAT_143b01a60;
        return false;
    }
    if (m_kDir.FUN_140552690(DAT_143b01a60))
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
// MS2-FUNCTIONAL: the blocked-flag temporaries and by-value point copies are laid out differently.
bool CMoveMotionController::vfunc_5(double fTime)
{
    if (m_pTarget == 0)
        return false;
    CMotionController::vfunc_5(fTime);
    m_kMove = DAT_143b01a60;
    int bBlocked;
    if (m_pTarget->vfunc_99(0) == 0 && FUN_141240780(FUN_14166d220(m_pTarget)) == 0
        && FUN_141240db0(FUN_14166d220(m_pTarget)) == 0)
        bBlocked = 0;
    else
        bBlocked = 1;
    if (bBlocked)
        return false;
    if (FUN_14028d470(m_fSpeed, 0))
    {
        m_kMove = DAT_143b01a60;
        return false;
    }
    Vector3 kInput, kGround;
    m_kDir = *FUN_141674b60(m_pTarget, &kGround, FUN_14123c360(m_pTarget, &kInput));
    if (m_kDir.FUN_140552690(DAT_143b01a60))
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

// ---- debug log of four floats (a template instantiation of the logger's argument packing) ----
struct Unk_LogArg
{
    int m_a[4];
};
MS2_CHECK_SIZE(Unk_LogArg, 0x10);
Unk_LogArg FUN_14027c920(float fValue);                             // formats one float
u64* FUN_140163e80(u64* pSlot);                                     // empty argument slot
u64* FUN_140274c80(u64* pSlot, const float* pValue);                // slot bound to a value
u64 FUN_14016d660(u64 a, u64 b, u64 c, u64 d);                      // joins four slots
u64 FUN_140163e50(void* pOut, u64 kJoined, Unk_LogArg* pFirst);
void FUN_1406530d0(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, u64 kArgs);

// @0x1414894f0
// MS2-FUNCTIONAL: template instantiation glue; the argument packing temporaries are laid out differently.
void FUN_1414894f0(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat,
                   const float* pA, const float* pB, const float* pC, const float* pD)
{
    Unk_LogArg kArg0 = FUN_14027c920(*pA);
    Unk_LogArg kArg1 = FUN_14027c920(*pB);
    Unk_LogArg kArg2 = FUN_14027c920(*pC);
    Unk_LogArg kArg3 = FUN_14027c920(*pD);
    u64 aSlot[4];
    u64 aInit[11];
    u64* pInit0 = FUN_140163e80(&aInit[0]);
    u64* pInit1 = FUN_140163e80(&aInit[1]);
    u64* pInit2 = FUN_140163e80(&aInit[2]);
    u64* pInit3 = FUN_140163e80(&aInit[3]);
    u64* pInit4 = FUN_140163e80(&aInit[4]);
    u64* pInit5 = FUN_140163e80(&aInit[5]);
    u64* pInit6 = FUN_140163e80(&aInit[6]);
    u64* pInit7 = FUN_140163e80(&aInit[7]);
    u64* pInit8 = FUN_140163e80(&aInit[8]);
    u64* pInit9 = FUN_140163e80(&aInit[9]);
    u64* pInit10 = FUN_140163e80(&aInit[10]);
    u64* pBoundD = FUN_140274c80(&aSlot[3], pD);
    u64* pBoundC = FUN_140274c80(&aSlot[2], pC);
    u64* pBoundB = FUN_140274c80(&aSlot[1], pB);
    u64* pBoundA = FUN_140274c80(&aSlot[0], pA);
    u64 q0 = *pInit0;
    u64 q1 = *pInit1;
    u64 q2 = *pInit2;
    u64 q3 = *pInit3;
    u64 q4 = *pInit4;
    u64 q5 = *pInit5;
    u64 q6 = *pInit6;
    u64 q7 = *pInit7;
    u64 q8 = *pInit8;
    u64 q9 = *pInit9;
    u64 q10 = *pInit10;
    u64 kJoined = FUN_14016d660(*pBoundA, *pBoundB, *pBoundC, *pBoundD);
    char aOut[24];
    u64 kArgs = FUN_140163e50(aOut, kJoined, &kArg0);
    FUN_1406530d0(pLog, nLevel, nCategory, pszFormat, kArgs);
}

// @0x1414898a0
CArcMotionController::~CArcMotionController()
{
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
