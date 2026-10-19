// statejump.h - StateJump (type 6): the actor state of a player jumping (Jump / JumpSpecial / Jump2 / JumpSpecial2 /
// JumpRandom, plus the hide-and-seek jump): plays the jump animation, steers in the air with the recorded launch
// direction and lands (on the ground, on a ridee or onto a sit / lie / climb object). Recovered from MapleStory2.exe
// KMS2_DEV x64 (2022-04-13); the unit is `?\statejump.cpp` (0x1417d5160-0x1417d6c00 .text$mn + the .text$di init
// 0x140102ff0, dir client\ms2). Header name assumed; member names invented from their use.
// Derives State (ms2/placeholder/state.h); the payload is StateJumpData (statedata.h).
#pragma once
#include <egf/Entity.h>
#include <efd/Point3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/unnamed/unit_140b0e5f0.h"

class StateJumpData;

// 0xa0. State sub ids in m_n10: 0x21 Jump, 0x22 JumpSpecial, 0x23 Jump2, 0x24 JumpSpecial2, 0x25 JumpRandom (resolved on
// enter), 0x26 (leave), 0x27 (landing / on ground).
class StateJump : public State
{
public:
    StateJump(PCBase* pOwner);                              // 0x1417d5160
    virtual ~StateJump();                                   // 0x1417d52e0 (??_G 0x1417d6a80)
    virtual int vfunc_1();                                  // 1  0x1417d6ad0: 6
    virtual void vfunc_3(double fTime);                     // 3  0x1417d58d0 (air control)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d5320 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417d5700 (leave)
    virtual void vfunc_6();                                 // 6  0x1417d57b0
    virtual void vfunc_8(double fTime);                     // 8  0x1417d5c70 (landing on a ridee / object / climb)
    virtual void vfunc_9(double fTime);                     // 9  0x1417d6000 (animation selection)
    virtual int vfunc_15();                                 // 15 0x1417d6ac0: 1
    virtual int vfunc_19();                                 // 19 0x1417d6ae0: 0
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x1417d64c0
    virtual bool vfunc_28(MS2Ptr<Unk_StateArg22> p);        // 28 0x1417d6560

    bool FUN_1417d65d0();                                   // the jump has lasted long enough (timer + m_n80 < clock)
    int FUN_1417d6620();                                    // the object to sit / lie on (+0x58) is taken or the ride ended

    efd::Point3 m_vDir;                                     // +0x40 the launch direction (world)
    int m_nOnGround;                                        // +0x4c launched from the ground
    float m_fSpeed;                                         // +0x50 the move speed to restore on leave
    int m_n54;                                              // +0x54 the direction has not been taken yet
    egf::Entity* m_pSeat;                                   // +0x58 the nearby object to sit / lie on
    float m_f60;                                            // +0x60
    efd::Point3 m_v64;                                      // +0x64
    int m_aSub[4];                                          // +0x70 Jump, Jump2, JumpSpecial, JumpSpecial2 sub ids
    int m_n80;                                              // +0x80 the minimum flight time (ms)
    Unk_CoupleTick m_tick;                                  // +0x84 the jump start tick
    MS2Ptr<StateJumpData> m_spJump;                         // +0x90
};
MS2_CHECK_SIZE(StateJump, 0xa0);
MS2_CHECK_OFFSET(StateJump, m_vDir, 0x40);
MS2_CHECK_OFFSET(StateJump, m_pSeat, 0x58);
MS2_CHECK_OFFSET(StateJump, m_aSub, 0x70);
MS2_CHECK_OFFSET(StateJump, m_tick, 0x84);
MS2_CHECK_OFFSET(StateJump, m_spJump, 0x90);
