// statetalk.h - StateTalk (actor state type 0x16, 0x48: the player's side of an npc dialogue) and StateTalkNpc
// (type 0x16, 0x40: the npc's own side). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\statetalk.cpp` (0x1417fc010-0x1417fcf30 .text$mn, dir client\ms2). Header name assumed; member names invented
// from their use. The state drives the owner's animation through the talk manager (reason 0x2d/0x2e/0x2f) and, for
// each finished talk phase, spawns the npc dialogue effect of the client config (+0x290 / +0x298).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

class PCBase;
class StateData;
class NiActorManager;
class NiControllerSequence;

// 0x48: State + the phase the talk is in (m_n10, mirrored into m_n40 so the update only reacts to a change) and the
// spawned effect handle (m_n44). The phase values: 0x47 wait for the npc to be talkable, 0x48 npc is talking,
// 0x49 nothing to talk to, 0x4a/0x4b the two dialogue effects were requested.
class StateTalk : public State
{
public:
    StateTalk(PCBase* pOwner);                          // @0x1417fc010
    virtual ~StateTalk();                               // @0x1417fc070 (??_G 0x1417fcd70)
    virtual int vfunc_1();                              // 1  @0x1417fcdf0: 0x16
    virtual void vfunc_3(double fTime);                 // 3  @0x1417fc4e0: push the owner to the zero point
    virtual void vfunc_4(StateData* pData);             // 4  @0x1417fc0a0 (enter)
    virtual void vfunc_5(int n);                        // 5  @0x1417fc460 (leave)
    virtual void vfunc_6();                             // 6  @0x1417fc960 (stop the talk)
    virtual void vfunc_8(double fTime);                 // 8  @0x1417fc9a0 (empty)
    virtual void vfunc_9(double fTime);                 // 9  @0x1417fc560 (update: play the phase anim / effect)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime); // 13 @0x1417fc9c0 (the talk anim finished)
    int FUN_1417fca20();                                // @0x1417fca20: the phase is neither 0x47 nor 0x49
    void FUN_1417fca60(int n);                          // @0x1417fca60: select a dialogue branch (not a slot)
    int m_n40;                                          // +0x40 the phase the last update saw
    int m_n44;                                          // +0x44 the spawned dialogue effect (0: none)
};
MS2_CHECK_SIZE(StateTalk, 0x48);
MS2_CHECK_OFFSET(StateTalk, m_n40, 0x40);
MS2_CHECK_OFFSET(StateTalk, m_n44, 0x44);

// 0x40: State + nothing (the npc only mirrors the talk manager into m_n10).
class StateTalkNpc : public State
{
public:
    StateTalkNpc(PCBase* pOwner);                       // @0x1417fcac0
    virtual ~StateTalkNpc();                            // @0x1417fcb00 (??_G 0x1417fcdb0)
    virtual int vfunc_1();                              // 1  @0x1417fce00: 0x16
    virtual void vfunc_3(double fTime);                 // 3  @0x1417fccf0: push the owner to the zero point
    virtual void vfunc_4(StateData* pData);             // 4  @0x1417fcb30 (enter: play the talking/idle anim)
};
MS2_CHECK_SIZE(StateTalkNpc, 0x40);
