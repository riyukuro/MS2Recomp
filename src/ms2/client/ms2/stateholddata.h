// stateholddata.h - StateHold (actor state type 0x20: holding another player's / a mount's hand): the owner follows
// the held actor's seat node, plays the seat animation of the mount's model and falls back to a state when the
// holder is gone. Its payload StateHoldData is in statedata.h.
// MS2-UNIT: ?\stateholddata.cpp
// MS2-RANGE: 0x1417cb9c0-0x1417cd420 .text$mn
#pragma once

#include <afx.h>
#include <efd/Point3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statemanager.h"

class PCBase;

// 0xa8. The held actor is the one whose id is in the payload (StateHoldData::m_nTargetId).
class StateHold : public StateMoveSkill
{
public:
    StateHold(PCBase* pOwner);                         // @0x1417cbba0
    virtual ~StateHold();                              // @0x1417cbc70
    virtual int vfunc_1();                             // 1  @0x1417cd410: 0x20
    virtual void vfunc_3(double fTime);                // 3  @0x1417cbfa0
    virtual void vfunc_4(StateData* pData);            // 4  @0x1417cbcb0
    virtual void vfunc_5(int n);                       // 5  @0x1417cbe70
    virtual void vfunc_8(double fTime);                // 8  @0x1417cc440
    virtual void vfunc_9(double fTime);                // 9  @0x1417cc5a0
    virtual int vfunc_15();                            // 15 @0x1417cccf0
    virtual int vfunc_16();                            // 16 @0x1417ccd20
    virtual MS2Ptr<StateData> vfunc_27();              // 27 @0x1417cd390: a new StateHoldData
    virtual int vfunc_36();                            // 36 @0x1417cd120
    virtual int vfunc_37();                            // 37 @0x1417cd1b0: 1

    void FUN_1417ccca0(int nState, int nSub);          // @0x1417ccca0: owner slot 59 (switch state)
    void FUN_1417ccd50();                              // @0x1417ccd50: remember whether the holder rides, aim the camera
    void FUN_1417cce10();                              // @0x1417cce10: cast the hold skill at the holder
    int FUN_1417cd060();                               // @0x1417cd060: the holder rides a mount
    int FUN_1417cd0d0();                               // @0x1417cd0d0: the held actor's id, 0 without a payload

    MS2Ptr<StateHoldData> m_spHold;                    // +0x78
    efd::Point3 m_kPos;                                // +0x88 (the owner's position before the hold)
    efd::Point3 m_kDir;                                // +0x94 (the owner's direction before the hold)
    bool m_bRiding;                                    // +0xa0
};
MS2_CHECK_SIZE(StateHold, 0xa8);
MS2_CHECK_OFFSET(StateHold, m_spHold, 0x78);
MS2_CHECK_OFFSET(StateHold, m_kPos, 0x88);
MS2_CHECK_OFFSET(StateHold, m_kDir, 0x94);
MS2_CHECK_OFFSET(StateHold, m_bRiding, 0xa0);
