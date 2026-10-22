// target2dcameramode.h - CTarget2DCameraMode (RTTI .?AVCTarget2DCameraMode@@): the side-view camera (mode id 11). An
// older sibling of CTargetCameraMode: it orbits the camera target on a fixed yaw (pi), derives straight from
// CCameraMode and smooths the shown pose towards the wanted one itself. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\target2dcameramode.cpp` (0x1418379e0-0x14183a020). Header name assumed; vfunc_N are
// vftable slots and the member names are invented from their use.
#pragma once

#include "cameramode.h"

// A camera pose: euler angles (degrees) and position; this obj has its own out-of-line ctor and copy assignment.
struct Unk_Target2DPose
{
    Unk_Target2DPose();                                             // 0x141839de0
    Unk_Target2DPose& operator=(const Unk_Target2DPose& o);         // 0x141839e20

    Vector3 m_rot;
    Vector3 m_pos;
};
MS2_CHECK_SIZE(Unk_Target2DPose, 0x18);

// 0xe0 bytes. vftable 0x142f82360.
class CTarget2DCameraMode : public CCameraMode
{
public:
    CTarget2DCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x1418379e0
    virtual ~CTarget2DCameraMode();                                 // 0x141837b00

    // @0x141839eb0
    virtual int vfunc_1() { return 11; }
    // @0x141839ec0
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_3(Vector3 pt);
    virtual void vfunc_4(Vector3 pt);
    virtual void vfunc_6(int n);
    virtual void vfunc_8(double fTime);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_21(float f, int n);
    virtual float vfunc_22();
    virtual float vfunc_23();
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    virtual Unk_CameraTargetEntity* vfunc_25();
    virtual Vector3 vfunc_26();
    virtual float vfunc_27();
    virtual void vfunc_29(float f1, float f2, float f3);
    virtual void vfunc_37();                                        // recompute the wanted eye from the angles

    Vector3 FUN_141839600();                                // m_8c
    static bool FUN_141839640(Vector3& ptPos, Vector3& ptRot);
    static Unk_CameraSetting FUN_1418397a0(Unk_CameraSetting setting);
    float FUN_1418398e0(float fMin, float fCur, float fMax, float fDegMin, float fDegMax);
    void FUN_1418399e0(double fTime);                               // ease the shown pose towards the wanted one

    Vector3 m_78;               // +0x78 target position
    float m_84;                         // +0x84 zoom speed
    int m_88;                           // +0x88 zooming
    Vector3 m_8c;               // +0x8c eye offset
    float m_98;                         // +0x98 wanted distance
    float m_9c;                         // +0x9c pose follow speed (from the config)
    float m_a0;                         // +0xa0 current follow speed
    float m_a4;                         // +0xa4 follow acceleration
    Unk_Target2DPose m_a8;              // +0xa8 shown pose
    Unk_Target2DPose m_c0;              // +0xc0 wanted pose
    int m_d8;                           // +0xd8 shown pose valid
    int m_dc;
};
MS2_CHECK_SIZE(CTarget2DCameraMode, 0xe0);
MS2_CHECK_OFFSET(CTarget2DCameraMode, m_a8, 0xa8);
MS2_CHECK_OFFSET(CTarget2DCameraMode, m_c0, 0xc0);
MS2_CHECK_OFFSET(CTarget2DCameraMode, m_dc, 0xdc);
