// toolsmoothcameramode.h - CToolSmoothCameraMode (RTTI .?AVCToolSmoothCameraMode@@): the editor free camera with
// smoothed keyboard/mouse motion (mode id 7), derived from CConsoleCameraMode. WASD/QE move, right-button drag
// rotates, wheel zooms; the target pose is eased towards through a velocity (m_130 move, m_13c rotate, m_148 vertical).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\toolsmoothcameramode.cpp`
// (0x141856e00-0x1418589b0). Header name assumed; vfunc_N are vftable slots and the member names are invented.
#pragma once

#include "consolecameramode.h"

// 0x168 bytes. vftable 0x142f868a8, 40 slots.
class CToolSmoothCameraMode : public CConsoleCameraMode
{
public:
    CToolSmoothCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x141856e00
    virtual ~CToolSmoothCameraMode();                                   // 0x141856f30

    // @0x1418588b0
    virtual int vfunc_1() { return 7; }
    // @0x141858970
    virtual bool vfunc_2() { return true; }
    virtual void vfunc_6(int n);                                        // 0x141857ce0
    virtual void vfunc_8(double fTime);                                 // 0x141857480
    virtual void vfunc_9();                                             // 0x141856f60
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);            // 0x1418585d0 frame the target
    virtual void vfunc_30();                                            // 0x141858480 target the object under the cursor
    virtual BOOL vfunc_31();                                            // 0x141858790 reads the ToolSmooth_* settings
    virtual void vfunc_39(double fTime);                                // 0x141857e80 smooth the pose towards m_d8

    Vector3 m_130;                                              // +0x130 move velocity (x: right, y: forward)
    Vector3 m_13c;                                              // +0x13c rotate velocity
    Vector3 m_148;                                              // +0x148 vertical velocity (z)
    float m_154;                                                        // +0x154 key move speed (ctor 50)
    float m_158;                                                        // +0x158 key rotation speed (ctor 360)
    float m_15c;                                                        // +0x15c mouse rotation speed (ctor 5)
    float m_160;                                                        // +0x160 speed multiplier (ctor 1)
};
MS2_CHECK_SIZE(CToolSmoothCameraMode, 0x168);
MS2_CHECK_OFFSET(CToolSmoothCameraMode, m_130, 0x130);
MS2_CHECK_OFFSET(CToolSmoothCameraMode, m_160, 0x160);
