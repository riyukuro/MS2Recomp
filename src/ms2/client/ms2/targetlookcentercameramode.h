// targetlookcentercameramode.h - CTargetLookCenterCameraMode (RTTI .?AVCTargetLookCenterCameraMode@@): the console
// (gamepad) orbit camera that looks at a centre point (mode id 0x13), derived from CTargetCameraMode. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\targetlookcentercameramode.cpp` (0x140a4c470-0x140a4e690).
// Header name assumed; vfunc_N are vftable slots and the member names are invented from their use.
#pragma once

#include "targetcameramode.h"

// A 2D point (x, y of a Point3 are read into it by FUN_140a0a600); returned by value through a hidden pointer.
struct Unk_Point2
{
    Unk_Point2(float fX, float fY);                         // 0x140a0a600 (inline, another obj)
    Unk_Point2 FUN_140a4e500(const Unk_Point2& pt) const;   // operator-
    float FUN_140a4e630() const;                            // squared length
    Unk_Point2 FUN_140affce0(float f) const;                // operator*(float)
    float FUN_140affe70() const;                            // length
    float FUN_140affeb0();                                  // Unitize (returns the old length)

    float x, y;
};
MS2_CHECK_SIZE(Unk_Point2, 8);

// 0x140 bytes. vftable 0x142dc7748, 40 slots.
class CTargetLookCenterCameraMode : public CTargetCameraMode
{
public:
    CTargetLookCenterCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x140a4c470
    virtual ~CTargetLookCenterCameraMode();                                         // 0x140a4c5e0

    // @0x140a4e620
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_3(Vector3 pt);
    virtual void vfunc_4(Vector3 pt);
    virtual void vfunc_6(int n);
    virtual void vfunc_8(double fTime);
    virtual void vfunc_9();
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    virtual BOOL vfunc_31();
    virtual void vfunc_39(double fTime);
    // @0x140a4e610
    virtual int vfunc_1() { return 0x13; }

    void FUN_140a4d5f0(double fTime);               // recompute the yaw and the eye from the centre point
    void FUN_140a4e0d0(const Vector3& ptCenter);    // set the look-at centre
    void FUN_140a4e110(float fAngle);               // fixed yaw
    void FUN_140a4e150(float f);                    // outer radius
    void FUN_140a4e180(bool b);                     // inner-radius check on/off
    void FUN_140a4e1d0(float f);                    // inner radius
    void FUN_140a4e200(bool b);                     // use the fixed yaw
    bool FUN_140a4e220();
    bool FUN_140a4e240();                           // inside the allowed ring?
    bool FUN_140a4e370();                           // the yaw lock expired?
    void FUN_140a4e3b0();                           // restart the yaw lock timer
    bool FUN_140a4e3e0();                           // shortest turn is clockwise?
    void FUN_140a4e490(float* pfAngle);             // wrap an angle into (0, 2pi]

    int m_108;                          // +0x108 (not written)
    float m_10c;                        // +0x10c rotation interpolate speed (ctor 100)
    bool m_110;                         // +0x110 a centre is set
    Vector3 m_114;              // +0x114 centre
    float m_120;                        // +0x120 inner radius
    float m_124;                        // +0x124 outer radius
    float m_128;                        // +0x128 fixed yaw
    bool m_12c;                         // +0x12c
    bool m_12d;                         // +0x12d use the fixed yaw
    unsigned int m_130;                 // +0x130 yaw lock start tick
    unsigned int m_134;                 // +0x134 yaw lock duration (ctor 1500)
    float m_138;                        // +0x138 (ctor 0.03)
    float m_13c;                        // +0x13c previous yaw
};
MS2_CHECK_SIZE(CTargetLookCenterCameraMode, 0x140);
MS2_CHECK_OFFSET(CTargetLookCenterCameraMode, m_10c, 0x10c);
MS2_CHECK_OFFSET(CTargetLookCenterCameraMode, m_114, 0x114);
MS2_CHECK_OFFSET(CTargetLookCenterCameraMode, m_13c, 0x13c);
