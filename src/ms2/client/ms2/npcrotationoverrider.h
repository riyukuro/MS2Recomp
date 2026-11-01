// npcrotationoverrider.h - CNPCRotationOverrider (RTTI .?AVCNPCRotationOverrider@@, base NiRefObject, 0x20 bytes): turns
// an NPC to a new yaw over a fixed time with a sine ease-in-out. Header name assumed; member names invented from use.
// vftable 0x142f43728 (deleting dtor 0x14160c670, NiRefObject::DeleteThis).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"

class CNPCRotationOverrider : public NiRefObject
{
public:
    CNPCRotationOverrider();                        // 0x14160c280
    virtual ~CNPCRotationOverrider();               // 0x14160c2f0

    bool AdvanceRotation(float* pfAngle, float fDelta);   // advance by fDelta; the yaw (0..360) in *pfAngle; false once finished
    float GetEasedAngle();                          // the eased yaw at the elapsed time

    float m_fFrom;                      // +0x10 the yaw the turn starts at
    float m_fTo;                        // +0x14 the yaw it ends at
    float m_fDuration;                  // +0x18 seconds
    float m_fElapsed;                   // +0x1c seconds
};
MS2_CHECK_SIZE(CNPCRotationOverrider, 0x20);
MS2_CHECK_OFFSET(CNPCRotationOverrider, m_fFrom, 0x10);
MS2_CHECK_OFFSET(CNPCRotationOverrider, m_fElapsed, 0x1c);
