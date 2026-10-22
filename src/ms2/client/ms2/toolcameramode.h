// toolcameramode.h - CToolCameraMode (RTTI .?AVCToolCameraMode@@): the free "tool" camera (mode id 6) used by the map
// editor / debug fly mode: WASD move, right-button drag rotates, wheel adjusts the speed. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\toolcameramode.cpp` (0x141852c30-0x141853bc0). Header
// name assumed; vfunc_N are vftable slots and the member names are invented from their use.
#pragma once

#include "cameramode.h"

// 0x98 bytes. vftable 0x142f84c68 (slots 3, 6, 8, 9 and 24 overridden).
class CToolCameraMode : public CCameraMode
{
public:
    CToolCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x141852c30
    virtual ~CToolCameraMode();                                         // 0x141852cf0

    // @0x141853ba0
    virtual int vfunc_1() { return 6; }
    // @0x141853bb0
    virtual bool vfunc_2() { return true; }
    virtual void vfunc_3(Vector3 pt);                           // 0x141853a40 keeps the eye inside the world
    virtual void vfunc_6(int n);                                        // 0x141852d20
    virtual void vfunc_8(double fTime);                                 // 0x1418532e0
    virtual void vfunc_9();                                             // 0x141853780
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);            // 0x141852ea0 frame the target

    Vector3 m_78;                                               // +0x78 move input (x: right, y: forward)
    int m_84;                                                           // +0x84 initial target framed
    int m_88;                                                           // +0x88 re-frame pending
    int m_8c;                                                           // +0x8c vfunc_24's n
    int m_90;                                                           // +0x90 world has field property 0xb
};
MS2_CHECK_SIZE(CToolCameraMode, 0x98);
MS2_CHECK_OFFSET(CToolCameraMode, m_78, 0x78);
