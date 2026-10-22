// CMotionController (RTTI name) and its four subclasses: the movement helpers of a skill's displacement ("motion")
// phase. A controller is armed with the skill's motion record and the moved actor (vfunc_2), then ticked (vfunc_5); it
// leaves the per-tick displacement in m_kMove (vfunc_3) and the motion kind in m_nType (vfunc_6). Member names are invented
// from their use. Only CMotionController and CArcMotionController have their ctor in the owning unit; the Linear / Blink /
// Move ctors, vftables and deleting dtors live in client\ms2\stateskill (0x1417f58e0..), they are declared here only.
// Owning unit: ?\motioncontroller.cpp (0x141487ed0-0x141489aa0, dir client\ms2).
#pragma once
#include <afx.h>
#include <NiRTTI.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

class PCBase;

// The skill's motion record (the actor-side state the controller reads: base direction, speed and duration).
struct Unk_MotionData
{
    char m_pad_00[0x5c];
    Vector3 m_kStart;           // +0x5c
    Vector3 m_kDir;             // +0x68 base direction (euler degrees for type 10 actors)
    float m_fSpeedScale;                // +0x74
    float m_fDuration;                  // +0x78
    float m_fPad7c;                     // +0x7c
    float m_fDistance;                  // +0x80
};
MS2_CHECK_OFFSET(Unk_MotionData, m_kStart, 0x5c);
MS2_CHECK_OFFSET(Unk_MotionData, m_kDir, 0x68);
MS2_CHECK_OFFSET(Unk_MotionData, m_fSpeedScale, 0x74);
MS2_CHECK_OFFSET(Unk_MotionData, m_fDistance, 0x80);

// Tilt record the motion data points at (FUN_141759830).
struct Unk_MotionTilt
{
    char m_pad_00[0xb4];
    float m_fAngle;                     // +0xb4 degrees
    float m_fSpeed;                     // +0xb8
};
MS2_CHECK_OFFSET(Unk_MotionTilt, m_fAngle, 0xb4);
MS2_CHECK_OFFSET(Unk_MotionTilt, m_fSpeed, 0xb8);

class CMotionController : public CPtred
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143adffa8

    CMotionController();                                        // 0x141487ed0
    virtual ~CMotionController();                               // 0x141487f90 (??_G 0x141489900)
    virtual const NiRTTI* vfunc_1();                            // 0x141489970
    virtual int vfunc_2(Unk_MotionData* pData, PCBase* pTarget);    // 0x141487fc0 arm
    virtual Vector3 vfunc_3();                          // 0x141488030 current displacement
    virtual int vfunc_4();                                      // 0x141488060
    virtual bool vfunc_5(double fTime);                         // 0x141488080 tick
    virtual int vfunc_6();                                      // 0x141488470 motion kind

    Vector3 m_kMove;                                    // +0x18
    Vector3 m_kDir;                                     // +0x24
    float m_fSpeed;                                             // +0x30
    int m_nPad34;                                               // +0x34
    int m_nPad38;                                               // +0x38
    int m_nPad3c;
    Unk_MotionData* m_pData;                                    // +0x40
    PCBase* m_pTarget;                                          // +0x48
    int m_nType;                                                // +0x50
    int m_nPad54;
};
MS2_CHECK_SIZE(CMotionController, 0x58);
MS2_CHECK_OFFSET(CMotionController, m_kMove, 0x18);
MS2_CHECK_OFFSET(CMotionController, m_kDir, 0x24);
MS2_CHECK_OFFSET(CMotionController, m_pData, 0x40);
MS2_CHECK_OFFSET(CMotionController, m_nType, 0x50);

// Arc: the actor is carried along a bezier from its position to the point in front of it.
class CArcMotionController : public CMotionController
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143adffc8

    CArcMotionController();                                     // 0x141488490
    virtual ~CArcMotionController();                            // 0x1414898a0 (??_G 0x1414898c0)
    virtual const NiRTTI* vfunc_1();                            // 0x141489960
    virtual int vfunc_2(Unk_MotionData* pData, PCBase* pTarget);    // 0x141488520
    virtual Vector3 vfunc_3();                          // 0x141488b40
    virtual int vfunc_4();                                      // 0x141488b80
    virtual bool vfunc_5(double fTime);                         // 0x141488ba0

    Vector3 m_kHeading;                                 // +0x58 last step direction
    Vector3 m_kStartPos;                                // +0x64 actor position when armed
    Vector3 m_kEndPos;                                  // +0x70 destination
    int m_nPad7c;
    double m_dDuration;                                         // +0x80
    double m_dElapsed;                                          // +0x88
    Vector3 m_kCtrlPos;                                 // +0x90 bezier control point
    float m_fCtrlWeight;                                        // +0x9c
    float m_fCtrlHeight;                                        // +0xa0 added to the control point's z
    float m_fSpeedLimit;                                        // +0xa4 bezier length
};
MS2_CHECK_SIZE(CArcMotionController, 0xa8);
MS2_CHECK_OFFSET(CArcMotionController, m_kHeading, 0x58);
MS2_CHECK_OFFSET(CArcMotionController, m_dDuration, 0x80);
MS2_CHECK_OFFSET(CArcMotionController, m_kCtrlPos, 0x90);
MS2_CHECK_OFFSET(CArcMotionController, m_fSpeedLimit, 0xa4);

// Linear / Blink are 0x60 bytes (StateSkill::vfunc_4 new(0x60), ??_G delete 0x60; +0x58 is never touched by the
// recovered code), Move is 0x58 (no new members). The ctors are in client\ms2\stateskill.
class CLinearMotionController : public CMotionController
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143adffb8

    CLinearMotionController();                                  // 0x1417f58e0
    // ~CLinearMotionController() is implicit (0x1417f5b00 in stateskill.obj: no vptr store).
    virtual const NiRTTI* vfunc_1();                            // 0x1417f5ee0
    virtual int vfunc_2(Unk_MotionData* pData, PCBase* pTarget);    // 0x141488df0
    virtual Vector3 vfunc_3();                          // 0x141488e30
    virtual int vfunc_4();                                      // 0x141488e60
    virtual bool vfunc_5(double fTime);                         // 0x141488e80
    char m_pad58[8];                                            // +0x58
};
MS2_CHECK_SIZE(CLinearMotionController, 0x60);

class CBlinkMotionController : public CMotionController
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143adffd8

    CBlinkMotionController();
    // ~CBlinkMotionController() is implicit (0x1417f5a90 in stateskill.obj: no vptr store).
    virtual const NiRTTI* vfunc_1();                            // 0x1417f5ed0
    virtual int vfunc_2(Unk_MotionData* pData, PCBase* pTarget);    // 0x141489100
    virtual Vector3 vfunc_3();                          // 0x141489140
    virtual int vfunc_4();                                      // 0x141489170
    virtual bool vfunc_5(double fTime);                         // 0x141489190
    char m_pad58[8];                                            // +0x58
};
MS2_CHECK_SIZE(CBlinkMotionController, 0x60);

class CMoveMotionController : public CMotionController
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143adffe8

    CMoveMotionController();                                    // 0x1417f5910
    // ~CMoveMotionController() is implicit (0x1417f5b20 in stateskill.obj: no vptr store).
    virtual const NiRTTI* vfunc_1();                            // 0x1417f5ef0
    virtual int vfunc_2(Unk_MotionData* pData, PCBase* pTarget);    // 0x1414891c0
    virtual Vector3 vfunc_3();                          // 0x141489200
    virtual int vfunc_4();                                      // 0x141489230
    virtual bool vfunc_5(double fTime);                         // 0x141489250
};
MS2_CHECK_SIZE(CMoveMotionController, 0x58);
