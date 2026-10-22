// targetcameramode.h - CTargetCameraMode (RTTI .?AVCTargetCameraMode@@): the orbit camera around the camera target
// (base of CRPGCameraMode). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\targetcameramode.cpp` (0x14183a020-0x14183e270). Header name assumed; vfunc_N are vftable slots and the member
// names are invented from their use.
#pragma once

#include "cameramode.h"

// A camera pose: euler angles (degrees) and position. 0x18 bytes; the implicit copy assignment is 0x140a38c40.
struct Unk_CameraPose
{
    // @0x14183e0a0
    Unk_CameraPose() : m_rot(g_143b01a60), m_pos(g_143b01a60) {}

    Vector3 m_rot;              // +0x00
    Vector3 m_pos;              // +0x0c
};
MS2_CHECK_SIZE(Unk_CameraPose, 0x18);

// 0x108 bytes. vftable 0x142f82580, 40 slots.
class CTargetCameraMode : public CCameraMode
{
public:
    CTargetCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);    // 0x14183a020
    virtual ~CTargetCameraMode();                                           // 0x14183a230

    // @0x14183e120
    virtual int vfunc_1() { return 2; }
    // 0x140a4e620 (COMDAT of another obj)
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_3(Vector3 pt);
    virtual void vfunc_4(Vector3 pt);
    virtual void vfunc_6(int n);
    virtual void vfunc_7();
    virtual void vfunc_8(double fTime);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(float f);
    virtual void vfunc_12(float fDegree);
    virtual void vfunc_16(float f);
    virtual void vfunc_21(float f, int n);
    virtual float vfunc_22();
    virtual float vfunc_23();
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    virtual Unk_CameraTargetEntity* vfunc_25();
    virtual Vector3 vfunc_26();
    virtual float vfunc_27();
    virtual void vfunc_29(float f1, float f2, float f3);
    virtual BOOL vfunc_31();
    virtual void vfunc_33();
    // @0x140a38d30
    virtual Vector3 vfunc_35() { return m_78; }
    virtual void vfunc_37();                                                // recompute the eye from the angles
    virtual BOOL vfunc_38(Vector3 ptPos, Vector3 ptRot);    // view frustum blocked?
    virtual void vfunc_39(double fTime);                                    // smooth the pose towards m_d8

    void FUN_14183bfd0(Vector3 ptPos, Vector3 ptRot, Vector3 ptTarget, bool bClamp);
    void FUN_14183c350(int n);
    Vector3 FUN_14183c370();
    void FUN_14183c3b0(float f);
    static bool FUN_14183c3e0(Vector3& ptPos, Vector3& ptRot);
    static Unk_CameraSetting FUN_14183c5b0(Unk_CameraSetting setting);
    void FUN_14183c600(float f);
    float FUN_14183c630();
    float FUN_14183c650();
    void FUN_14183c670(float fDist, BOOL bSmooth);
    void FUN_14183cc50(float f);
    void FUN_14183cc80(int n);
    float FUN_14183ce10(float fMin, float fCur, float fMax, float fDegMin, float fDegMax);
    void FUN_14183d9a0(float& f1, float& f2, float& f3) const;
    void FUN_14183dfe0(const Unk_CameraPose& cur, const Unk_CameraPose& target);
    void FUN_14183e040();

    Vector3 m_78;               // +0x78 target position
    float m_84;                         // +0x84 zoom speed
    int m_88;                           // +0x88
    Vector3 m_8c;               // +0x8c eye offset
    float m_98;                         // +0x98 wanted distance
    float m_9c;
    float m_a0;
    float m_a4;
    float m_a8;
    float m_ac;                         // +0xac (ctor 40)
    float m_b0;
    float m_b4;
    float m_b8;                         // +0xb8 (ctor 1)
    int m_bc;
    Unk_CameraPose m_c0;                // +0xc0 current pose
    Unk_CameraPose m_d8;                // +0xd8 target pose
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    float m_100;
};
MS2_CHECK_SIZE(CTargetCameraMode, 0x108);
MS2_CHECK_OFFSET(CTargetCameraMode, m_78, 0x78);
MS2_CHECK_OFFSET(CTargetCameraMode, m_c0, 0xc0);
MS2_CHECK_OFFSET(CTargetCameraMode, m_100, 0x100);
