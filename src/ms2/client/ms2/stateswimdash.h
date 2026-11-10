// stateswimdash.h - StateSwimDash (type 0x1c): the actor state of a player dashing through water (a move skill that
// keeps the swim animation, steers with the movement direction and starts a looping effect). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\stateswimdash.cpp` (0x1417fb5c0-0x1417fc010 .text$mn,
// dir client\ms2). Header name assumed; member names invented from their use.
// Derives StateMoveSkill (statemanager.h): the ctor sets its fallback state to 0x1b (StateSwim) and its m_n44 to 0x1c.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/statemanager.h"

// 0x80.
class StateSwimDash : public StateMoveSkill
{
public:
    StateSwimDash(PCBase* pOwner);                          // 0x1417fb5c0
    virtual ~StateSwimDash();                               // 0x1417fb620 (??_G 0x1417fbfb0)
    virtual int vfunc_1();                                  // 1  0x1417fc000: 0x1c
    virtual void vfunc_3(double fTime);                     // 3  0x1417fb730 (steer in the move direction)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417fb670 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417fb6d0 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417fb910 (leave when the dash ends)
    virtual void vfunc_9(double fTime);                     // 9  0x1417fbb50 (play the dash animation)
    virtual void vfunc_10(float a, float b, float c, float d, int e);   // 10 0x1417fbd70 (owner slot 115 -> speed)
    virtual int vfunc_14();                                 // 14 0x1417fbff0: 0
    virtual int vfunc_36();                                 // 36 0x1417fbe00 (input / skill check)

    void StopEffect();                                   // stop the effect
    void FUN_1417fbec0();                                   // start the effect of the owner's dash animation

    int m_nEffect;                                          // +0x78 effect id (0 = none)
    int m_nPad7c;                                           // +0x7c
};
MS2_CHECK_SIZE(StateSwimDash, 0x80);
MS2_CHECK_OFFSET(StateSwimDash, m_nEffect, 0x78);
