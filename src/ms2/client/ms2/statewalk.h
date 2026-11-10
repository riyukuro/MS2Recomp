// statewalk.h - StateWalk (type 2) and StateWalkNPC (type 2): the actor states of a walking / running player and of a
// walking npc. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statewalk.cpp`
// (0x1417ff730-0x141801030 .text$mn, dir client\ms2). Header name assumed; names invented from their use.
// State::m_n10 is the gait: 0x17 swim-walk (ridee speed), 0x18 walk, 0x19 run, 0x1a sprint.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

// 0x58.
class StateWalk : public State
{
public:
    StateWalk(PCBase* pOwner);                              // 0x1417ff730
    virtual ~StateWalk();                                   // 0x1417ff7d0 (??_G 0x141800f70)
    virtual int vfunc_1();                                  // 1  0x141800ff0: 2
    virtual void vfunc_3(double fTime);                     // 3  0x1417ffba0 (steer in the move direction)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417ff800 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417ffb40 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417fff20 (pick the gait, leave on events)
    virtual void vfunc_9(double fTime);                     // 9  0x141800580 (play the walk / run animation)
    virtual void vfunc_10(float a, float b, float c, float d, int e);   // 10 0x141800ac0 (owner slot 115 -> speed)
    virtual int vfunc_15();                                 // 15 0x141800a90
    virtual int vfunc_19();                                 // 19 0x141801010: 0
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);         // 22 0x141800b60: 1
    virtual void vfunc_34();                                // 34 0x141801020: m_n28 = 1
    virtual void vfunc_36(int n);                           // 36 0x141800b90: m_n4c = n
    virtual int vfunc_37();                                 // 37 0x141800bb0: m_n4c

    float m_fSpeed1;                                        // +0x40 the owner's slot 96 value at the last animation change
    float m_fSpeed2;                                        // +0x44 the owner's slot 97 value at the last animation change
    int m_n48;                                              // +0x48 0 = the animation is the run-in (slot 115 out value)
    int m_n4c;                                              // +0x4c 1 = forced sprint (set by slot 36)
    int m_n50;                                              // +0x50 the gait changed
};
MS2_CHECK_SIZE(StateWalk, 0x58);
MS2_CHECK_OFFSET(StateWalk, m_fSpeed1, 0x40);
MS2_CHECK_OFFSET(StateWalk, m_n50, 0x50);

// 0x50.
class StateWalkNPC : public State
{
public:
    StateWalkNPC(PCBase* pOwner);                           // 0x141800bd0
    virtual ~StateWalkNPC();                                // 0x141800c20 (??_G 0x141800fb0)
    virtual int vfunc_1();                                  // 1  0x141801000: 2
    virtual void vfunc_4(StateData* pData);                 // 4  0x141800c50
    virtual void vfunc_9(double fTime);                     // 9  0x141800cb0
    virtual void vfunc_10(float a, float b, float c, float d, int e);   // 10 0x141800ed0

    float m_fSpeed1;                                        // +0x40
    float m_fSpeed2;                                        // +0x44
    int m_n48;                                              // +0x48
};
MS2_CHECK_SIZE(StateWalkNPC, 0x50);
MS2_CHECK_OFFSET(StateWalkNPC, m_n48, 0x48);
