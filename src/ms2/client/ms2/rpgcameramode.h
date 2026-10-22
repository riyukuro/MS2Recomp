// rpgcameramode.h - CRPGCameraMode (RTTI .?AVCRPGCameraMode@@): the default third-person camera (mode id 12), an orbit
// camera derived from CTargetCameraMode that takes mouse/keyboard input. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the obj lies inside the units.tsv range of client\ms2\scenestategame.cpp (0x141709970-0x14170b530).
// Header name assumed; vfunc_N are vftable slots.
#pragma once

#include "targetcameramode.h"

// 0x108 bytes (no members of its own). vftable 0x142f5c0d8, 40 slots.
class CRPGCameraMode : public CTargetCameraMode
{
public:
    CRPGCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x141709970
    virtual ~CRPGCameraMode();                                          // 0x1417099f0

    // @0x14170b500
    virtual int vfunc_1() { return 12; }
    // @0x14170b510
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_6(int n);
    virtual void vfunc_8(double fTime);
    virtual void vfunc_9();
    // @0x14170b520
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n) {}
    virtual void vfunc_30();                                            // target the nearest picked actor
    virtual BOOL vfunc_31();
    virtual void vfunc_39(double fTime);

    Vector3 FUN_14170b320(Vector3 ptPos);              // look-at angles (degrees) from ptPos to m_78
};
MS2_CHECK_SIZE(CRPGCameraMode, 0x108);
