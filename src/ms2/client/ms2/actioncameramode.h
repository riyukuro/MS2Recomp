// actioncameramode.h - CActionCameraMode (RTTI .?AVCActionCameraMode@@, mode id 5): the camera mode that plays a
// camera effect nif (CameraMgr::m_effect, "Camera01" node and FOV interpolator) and then returns to the previous view
// (a fly-by back, or the saved setting). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\actioncameramode.cpp` (0x140944f30-0x140948420, dir client\ms2). Header name assumed (the class name); vfunc_N
// are CCameraMode slots, the member names are invented.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/cameramode.h"

// 0x80 bytes, vftable 0x142dad3e0 (37 slots).
class CActionCameraMode : public CCameraMode
{
public:
    CActionCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x140944f30
    virtual ~CActionCameraMode();                                       // 0x140944fb0 (??_G 0x140947820)

    // @0x140947890
    virtual int vfunc_1() { return 5; }
    // @0x140947920
    virtual bool vfunc_2() { return true; }
    virtual void vfunc_6(int n);                                        // 0x140944fe0
    virtual void vfunc_7();                                             // 0x140945030
    virtual void vfunc_8(double fTime);                                 // 0x140945060
    virtual void vfunc_9();                                             // 0x140945450
    virtual Unk_StreamPoint vfunc_26();                                 // 0x140945470 the camera node position
    virtual int vfunc_28();                                             // 0x140945460

    float m_78;                                                         // +0x78 (never set)
    float m_fTime;                                                      // +0x7c time since the mode started
};
MS2_CHECK_SIZE(CActionCameraMode, 0x80);
MS2_CHECK_OFFSET(CActionCameraMode, m_fTime, 0x7c);
