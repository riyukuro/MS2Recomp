// bosstargetcamera.h - CBossTargetCamera (RTTI .?AVCBossTargetCamera@@): the boss-fight camera (mode id 18), an orbit
// camera derived from CTargetCameraMode that keeps the boss and the player in view (distance follows the boss).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\bosstargetcamera.cpp`
// (0x140a376e0-0x140a38fa0). Header name assumed; vfunc_N are vftable slots and the member names are invented from
// their use.
#pragma once

#include "targetcameramode.h"
#include "ms2/placeholder/mapcameradata.h"

// 0x168 bytes. vftable 0x142dc59b0, 40 slots.
class CBossTargetCamera : public CTargetCameraMode
{
public:
    CBossTargetCamera(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);    // 0x140a376e0
    virtual ~CBossTargetCamera();                                           // 0x140a377a0

    // @0x140a38cf0
    virtual int vfunc_1() { return 18; }
    // @0x140a38d80
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_6(int n);
    virtual void vfunc_8(double fTime);
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    virtual float vfunc_27();
    virtual void vfunc_36(Unk_CameraPreset* pPreset);
    virtual void vfunc_39(double fTime);

    void FUN_140a38550(int nObjectId);                  // 0x140a38550 (inline COMDAT in the exe)
    Vector3 FUN_140a38570();                    // the look-at point (the boss, nudged towards the player)

    int m_108;                          // +0x108 object id of the boss
    CBossTargetCameraData m_data;       // +0x110
};
MS2_CHECK_SIZE(CBossTargetCamera, 0x168);
MS2_CHECK_OFFSET(CBossTargetCamera, m_108, 0x108);
MS2_CHECK_OFFSET(CBossTargetCamera, m_data, 0x110);
