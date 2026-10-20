// freecameramode.h - PLACEHOLDER for three camera modes whose units are not recovered yet: CFreeCameraMode (RTTI
// .?AVCFreeCameraMode@@, vftable 0x142ec3e38, ctor 0x1412221e0), CEditCameraMode (.?AVCEditCameraMode@@, derives from
// CFreeCameraMode, vftable 0x142eb92b0, ctor 0x141198830) and CActionCameraMode (.?AVCActionCameraMode@@, vftable
// 0x142dad3e0, ctor 0x140944f30). NOT an original header. Only the ctors and the sizes are proven (operator new sizes
// in CameraMgr::FUN_140aed750 and the ctor bodies); the overrides are declared so that the classes are concrete. The
// vftables are emitted by their own units, never here (no ctor is defined in a header).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/cameramode.h"

// 0x88 bytes: a point at +0x78 (the ctor sets it to NiPoint3::ZERO).
class CFreeCameraMode : public CCameraMode
{
public:
    CFreeCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x1412221e0
    virtual ~CFreeCameraMode();                                         // 0x141222290
    // @0x141222dd0
    virtual int vfunc_1() { return 1; }
    // @0x141222de0
    virtual bool vfunc_2() { return true; }
    virtual void vfunc_6(int n);                                        // 0x141222d20
    virtual void vfunc_7();                                             // 0x141222d60
    virtual void vfunc_8(double fTime);                                 // 0x1412222c0
    virtual void vfunc_9();                                             // 0x141222b80

    Unk_StreamPoint m_78;                                               // +0x78
    int m_pad_84;
};
MS2_CHECK_SIZE(CFreeCameraMode, 0x88);

// 0x88 bytes: no members of its own.
class CEditCameraMode : public CFreeCameraMode
{
public:
    CEditCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x141198830
    virtual ~CEditCameraMode();                                         // 0x1411988b0
    // @0x141199130
    virtual int vfunc_1() { return 8; }
    // @0x141199140
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_8(double fTime);                                 // 0x1411988e0
    virtual void vfunc_9();                                             // 0x141198f00
};
MS2_CHECK_SIZE(CEditCameraMode, 0x88);

// CActionCameraMode is recovered: ms2/client/ms2/actioncameramode.h.
#include "ms2/client/ms2/actioncameramode.h"
