// unit_1416c4de0.h - CPVPCameraMode (RTTI .?AVCPVPCameraMode@@): the PVP duel camera (mode id 13) derived from
// CTargetCameraMode; it frames the local player and the opponent. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is unit_1416c4de0 (0x1416c4de0-0x1416c6210). Header name assumed; vfunc_N are vftable slots
// and the member names are invented from their use.
#pragma once

#include "ms2/client/ms2/targetcameramode.h"

// 0x130 bytes. 40 vftable slots.
class CPVPCameraMode : public CTargetCameraMode
{
public:
    CPVPCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x1416c4de0
    virtual ~CPVPCameraMode();                                      // 0x1416c4ee0

    // @0x1416c60d0
    virtual int vfunc_1() { return 13; }
    // @0x1416c60e0
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_6(int n);
    virtual void vfunc_8(double fTime);
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    virtual float vfunc_27();
    virtual BOOL vfunc_31();                                        // reads the PVP_* camera settings
    virtual void vfunc_39(double fTime);                            // smooth the pose towards m_d8

    void FUN_1416c5b00(int nTargetId);                              // select the opponent
    Vector3 FUN_1416c5d30();                                // framing centre (midpoint with the opponent)

    int m_108;                                                      // +0x108 opponent object id
    Unk_CameraTargetEntity* m_110;                                  // +0x110 opponent (null without one)
    float m_118;                                                    // +0x118 interpolation delay (ctor 0.02)
    float m_11c;                                                    // +0x11c distance offset (ctor 500)
    float m_120;                                                    // +0x120 detach distance (ctor 800)
    float m_124;                                                    // +0x124 zoom out (ctor 2000)
    float m_128;                                                    // +0x128 view offset z (ctor 200)
};
MS2_CHECK_SIZE(CPVPCameraMode, 0x130);
MS2_CHECK_OFFSET(CPVPCameraMode, m_110, 0x110);
