// homecameramode.h - CHomeCameraMode (RTTI .?AVCHomeCameraMode@@): the camera of the housing (home) plot, mode id 17.
// A zoom/orbit camera derived straight from CCameraMode (not from CTargetCameraMode, although its update loop is a
// close sibling of it). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\homecameramode.cpp` (0x140b64c30-0x140b67d70). Header name assumed; vfunc_N are vftable slots and the member
// names are invented from their use.
#pragma once

#include "cameramode.h"

// The camera points are NiPoint3 in the exe: efd::Point3 results convert through the out-of-line NiPoint3(const
// efd::Point3&) and are move-assigned; NiPoint3 values are copy-assigned. Vector3 stands for efd::Point3 and
// the base slices implicitly, as in the exe.
struct Unk_HomeNiPoint3 : public Vector3
{
    Unk_HomeNiPoint3(const Vector3& pt);                    // 0x14027dcf0
    Unk_HomeNiPoint3& operator=(Unk_HomeNiPoint3&& pt);             // 0x14097faa0
    Unk_HomeNiPoint3& operator=(const Unk_HomeNiPoint3& pt);        // 0x14097fad0
};
MS2_CHECK_SIZE(Unk_HomeNiPoint3, 12);

// A camera pose: euler angles (degrees) and position; this obj has its own out-of-line ctor and copy assignment.
struct Unk_HomeCameraPose
{
    Unk_HomeCameraPose();                                           // 0x140b67c40
    Unk_HomeCameraPose& operator=(const Unk_HomeCameraPose& o);     // 0x140b67c80

    Vector3 m_rot;
    Vector3 m_pos;
};
MS2_CHECK_SIZE(Unk_HomeCameraPose, 0x18);

// The camera manager's data that the home camera reads (Unk_CameraManager has no members of its own; reached by a
// downcast, the object is the singleton at 0x143ab3700).
class Unk_CameraManagerData : public Unk_CameraManager
{
public:
    char m_pad_00[0xc8];
    Unk_HomeNiPoint3 m_c8;               // +0xc8 zoom axis
    Unk_HomeNiPoint3 m_d4;               // +0xd4 up vector
    Unk_CameraSetting m_e0;             // +0xe0 the setting the engine camera is built from
    char m_pad_108[0x10];
    MS2Ptr<CCameraMode> m_118;          // +0x118 the current camera mode
};

// 0x118 bytes, 39 vftable slots (slots 37 and 38 are new).
class CHomeCameraMode : public CCameraMode
{
public:
    CHomeCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);    // 0x140b64c30
    virtual ~CHomeCameraMode();                                         // 0x140b64e40

    // @0x140b64e70
    virtual int vfunc_1() { return 17; }
    // @0x140b64e90
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_6(int n);
    virtual void vfunc_7();
    virtual void vfunc_8(double fTime);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(float f);
    virtual void vfunc_16(float f);
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    virtual float vfunc_27();
    virtual void vfunc_33();
    virtual void vfunc_37(double fTime);                                // ease the shown pose towards m_c4
    virtual BOOL vfunc_38(Vector3 ptPos, Vector3 ptRot);   // view frustum blocked?

    void FUN_140b66570();                                               // m_c4.m_pos from the zoom, refresh m_7c
    Vector3 FUN_140b66660();                                    // m_7c
    void FUN_140b66730(Vector3 ptPos, Vector3 ptRot, Vector3 ptTarget, bool bClamp);
    float FUN_140b66b10(float fMin, float fCur, float fMax, float fDegMin, float fDegMax);

    int m_78;                           // +0x78 zooming
    Unk_HomeNiPoint3 m_7c;               // +0x7c eye offset from the target
    Unk_HomeNiPoint3 m_88;               // +0x88 target position
    float m_94;                         // +0x94 zoom speed
    float m_98;                         // +0x98 wanted distance
    float m_9c;                         // +0x9c extra zoom range
    float m_a0;                         // +0xa0 (ctor 1)
    float m_a4;                         // +0xa4 (ctor 40)
    float m_a8;                         // +0xa8 (not set by the ctor)
    int m_ac;
    int m_b0;
    int m_b4;
    float m_b8;
    int m_bc;
    int m_c0;
    Unk_HomeCameraPose m_c4;                // +0xc4 wanted pose
    Unk_HomeCameraPose m_dc;                // +0xdc shown pose
    float m_f4;
    float m_f8;
    float m_fc;
    Unk_HomeNiPoint3 m_100;              // +0x100 direction of the zoom axis
    Unk_HomeNiPoint3 m_10c;              // +0x10c up vector
};
MS2_CHECK_SIZE(CHomeCameraMode, 0x118);
MS2_CHECK_OFFSET(CHomeCameraMode, m_c4, 0xc4);
MS2_CHECK_OFFSET(CHomeCameraMode, m_10c, 0x10c);
