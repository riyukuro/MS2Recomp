// consolecameramode.h - CConsoleCameraMode (RTTI .?AVCConsoleCameraMode@@): the gamepad/console orbit camera (mode id
// 14) derived from CTargetCameraMode; base of CFPSCameraMode and CTPSCameraMode. Recovered from MapleStory2.exe
// KMS2_DEV x64 (2022-04-13); the unit is `?\consolecameramode.cpp` (0x14109eb00-0x1410a0e80). Header name assumed;
// vfunc_N are vftable slots and the member names are invented from their use.
#pragma once

#include "targetcameramode.h"

// 0x130 bytes. vftable 0x142ea99f8, 40 slots.
class CConsoleCameraMode : public CTargetCameraMode
{
public:
    CConsoleCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x14109eb00
    virtual ~CConsoleCameraMode();                                      // 0x14109ec00

    // @0x1410a0be0
    virtual int vfunc_1() { return 14; }
    // @0x1410a0bf0
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_6(int n);                                        // 0x14109fc60
    virtual void vfunc_8(double fTime);                                 // 0x14109ee10
    virtual void vfunc_9();                                             // 0x14109ec30
    // @0x1410a0c00
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n) {}
    virtual void vfunc_30();                                            // target the object under the cursor
    virtual BOOL vfunc_31();                                            // reads the Console_* camera settings
    virtual void vfunc_32(float f);                                     // wanted yaw (radians)
    virtual void vfunc_39(double fTime);                                // smooth the pose towards m_d8

    Vector3 FUN_1410a0a00(Vector3 ptPos);               // look-at angles (degrees) from ptPos to m_78

    int m_108;                                                          // +0x108 yaw interpolation running
    float m_10c;                                                        // +0x10c wanted yaw (radians)
    float m_110;                                                        // +0x110 yaw interpolation speed (ctor 100)
    float m_114;                                                        // +0x114 mouse rotation speed (ctor 50)
    Vector3 m_118;                                              // +0x118 target offset (ctor 0, 0, 100)
    float m_124;                                                        // +0x124 min distance (ctor 400)
    float m_128;                                                        // +0x128 max distance (ctor 1100)
};
MS2_CHECK_SIZE(CConsoleCameraMode, 0x130);
MS2_CHECK_OFFSET(CConsoleCameraMode, m_118, 0x118);
