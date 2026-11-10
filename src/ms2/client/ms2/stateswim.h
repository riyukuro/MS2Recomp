// stateswim.h - StateSwim (type 0x1b): the actor state of a player swimming (m_n10 is the swim kind: 0x84 normal,
// 0x85 riding a ridee; starts a looping effect). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\stateswim.cpp` (0x1417fb040-0x1417fb5c0 .text$mn, dir client\ms2). Header name assumed; names invented from use.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

class Ridee;

// 0x48.
class StateSwim : public State
{
public:
    StateSwim(PCBase* pOwner);                              // 0x1417fa370
    virtual ~StateSwim();                                   // 0x1417fa3d0 (??_G 0x1417fb530)
    virtual int vfunc_1();                                  // 1  0x1417fb580: 0x1b
    virtual void vfunc_3(double fTime);                     // 3  0x1417fa660 (steer in the move direction)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417fa420 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417fa600 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417fa950 (leave when out of the water)
    virtual void vfunc_9(double fTime);                     // 9  0x1417fac90 (play the swim animation)
    virtual void vfunc_10(float a, float b, float c, float d, int e);   // 10 0x1417fafb0 (owner slot 115 -> speed)
    virtual int vfunc_14();                                 // 14 0x1417fb570: 0
    virtual int vfunc_19();                                 // 19 0x1417fb590: 0
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);         // 22 0x1417fb040 (a new request may replace this state)
    virtual void vfunc_29(MS2Ptr<Unk_StateArg29> p);        // 29 0x1417fb160 (a swim gem was put on)
    virtual void vfunc_34();                                // 34 0x1417fb5a0: m_n28 = 1

    int FUN_1417fb370();                                    // the ridee's swim kind (0 without a ridee)
    void FUN_1417fb400();                                   // stop the effect
    void FUN_1417fb440();                                   // start the effect of the owner's swim animation

    int m_nEffect;                                          // +0x40 effect id (0 = none)
    int m_nMode;                                            // +0x44 last picked mode (service value)
};
MS2_CHECK_SIZE(StateSwim, 0x48);
MS2_CHECK_OFFSET(StateSwim, m_nEffect, 0x40);
