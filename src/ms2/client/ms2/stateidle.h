// stateidle.h - StateIdle (type 1) and its siblings StateIdleNPC (1), StateIdlePet (1), StateJumpNpc (6),
// StatePuppetNpc (0x23), StateIdleFittingDoll (1): the standing / idle actor states of a player, npc, pet and fitting
// doll. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\stateidle.cpp`
// (0x1417cd420-0x1417d0be0 .text$mn, dir client\ms2). Header name assumed; names invented from their use.
// All derive State (ms2/placeholder/state.h). StateIdle::m_n10 is the idle sub state:
//   1 stand, 2..5 move/jump variants (animation key = sub state - 2), 6 bore wait, 7 water, 8/9 ride idles, 0xc seated,
//   0x15 emotion idle, 0x4c.. equip-change poses.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/timer.h"
#include "ms2/client/ms2/statemanager.h"   // Unk_140517b00 (8-byte poll timer)

class NiActorManager;
class NiControllerSequence;
class CNpc;

// 0xb8.
class StateIdle : public State
{
public:
    StateIdle(PCBase* pOwner);                              // 0x1417cd420
    virtual ~StateIdle();                                   // 0x1417cd4a0 (??_G 0x1417d08e0)
    virtual int vfunc_1();                                  // 1  0x1417d0a60: 1
    virtual void vfunc_3(double fTime);                     // 3  0x1417cd680 (move in place)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417cd520 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417cd700 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417cd770 (pick the idle animation)
    virtual void vfunc_9(double fTime);                     // 9  0x1417cdbb0 (play the idle animation of the sub state)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417ce460
    virtual int vfunc_14();                                 // 14 0x1417ce600
    virtual int vfunc_15();                                 // 15 0x1417cd740
    virtual int vfunc_16();                                 // 16 0x1417ce630
    virtual void vfunc_21(int n);                           // 21 0x1417ce5b0 (-> bore wait)
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x1417ce680
    virtual void vfunc_29(MS2Ptr<Unk_StateArg29> p);        // 29 0x1417cf4f0

    void FUN_1417ce6f0(unsigned nSeq);                      // stand animation (key 0 / 1 in the water)
    void FUN_1417ce820(unsigned nSeq);                      // move variant animation (key 0x27 + sub state - 2)
    void FUN_1417ce970(unsigned nSeq);                      // rider: animation of key 0x49
    void FUN_1417ce9b0(unsigned nSeq);                      // rider: animation of key 0x49
    void FUN_1417ce9f0(unsigned nSeq);                      // animation of key 0x2e
    void FUN_1417ceab0(unsigned nSeq);                      // bore wait animation (key 0x30, or the ridee's)
    void FUN_1417ceca0(unsigned nSeq);                      // animation of key 0x37
    void FUN_1417ced70(unsigned nSeq);                      // animation of key 0x36
    void FUN_1417cee40(unsigned nSeq);                      // rider: animation of key 0x49
    void FUN_1417cee90(unsigned nSeq);                      // animation of key 0x4a
    void FUN_1417cef60();                                   // idle timers (leave to the stand state, bore sub states)
    void FUN_1417cf210();                                   // stop the idle sound
    void FUN_1417cf260();                                   // start the idle sound
    void FUN_1417cf360();                                   // start the emotion idle sound
    void FUN_1417cf4a0();                                   // stop the emotion idle sound

    Timer m_timerBore;                                      // +0x40 bore wait
    Timer m_timerLeave;                                     // +0x78 leave the sub state
    int m_nSoundIdle;                                       // +0xb0 effect id of the idle sound
    int m_nSoundEmotion;                                    // +0xb4 effect id of the emotion idle sound
};
MS2_CHECK_SIZE(StateIdle, 0xb8);
MS2_CHECK_OFFSET(StateIdle, m_timerBore, 0x40);
MS2_CHECK_OFFSET(StateIdle, m_timerLeave, 0x78);
MS2_CHECK_OFFSET(StateIdle, m_nSoundIdle, 0xb0);

// 0x40.
class StateIdleNPC : public State
{
public:
    StateIdleNPC(PCBase* pOwner);                           // 0x1417cf710
    virtual ~StateIdleNPC();                                // 0x1417cf750 (??_G 0x1417d0960)
    virtual int vfunc_1();                                  // 1  0x1417d0a80: 1
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417cf780

    void FUN_1417cf860(unsigned nSeq);                      // stand animation
};
MS2_CHECK_SIZE(StateIdleNPC, 0x40);

// 0x58.
class StateIdlePet : public State
{
public:
    StateIdlePet(PCBase* pOwner);                           // 0x1417cf970
    virtual ~StateIdlePet();                                // 0x1417cfa00 (??_G 0x1417d09a0)
    virtual int vfunc_1();                                  // 1  0x1417d0a90: 1
    virtual void vfunc_3(double fTime);                     // 3  0x1417cfa80
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417cfa30
    virtual void vfunc_5(int n);                            // 5  0x1417cfaf0
    virtual void vfunc_9(double fTime);                     // 9  0x1417cfb30
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417cfd60

    void FUN_1417cfea0(unsigned nSeq);                      // stand / idle animation and the idle sounds
    void FUN_1417d0140(unsigned nSeq);                      // sub state 2..5 animation, pet voice 0x5c
    void FUN_1417d0210(unsigned nSeq);                      // sub state 0xf animation, pet voice 0x5d
    void FUN_1417d02e0(unsigned nSeq);                      // sub state 0x10 animation, pet voice 0x5e
    void FUN_1417d03b0(unsigned nSeq);                      // sub state 0x11 (revive) animation, pet voice 0x60
    void FUN_1417d0470(unsigned nSeq);                      // sub state 0x13 animation, pet voice 0x61
    void FUN_1417d0540(int nVoice);                         // the pet says nVoice once

    int m_nVoiced;                                          // +0x40 a voice was said in this sub state
    int m_nTired;                                           // +0x44 the first-enter timers were armed
    Unk_140517b00 m_timerVoiceA;                             // +0x48
    Unk_140517b00 m_timerVoiceB;                             // +0x50
};
MS2_CHECK_SIZE(StateIdlePet, 0x58);

// 0x48. Jump of an npc: plays the animation named by the npc's record.
class StateJumpNpc : public State
{
public:
    StateJumpNpc(PCBase* pOwner);                           // 0x1417d05a0
    virtual int vfunc_1();                                  // 1  0x1417d0aa0: 6
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d0620

    CNpc* m_pNpc;                                           // +0x40
};
MS2_CHECK_SIZE(StateJumpNpc, 0x48);

// 0x40.
class StatePuppetNpc : public State
{
public:
    StatePuppetNpc(PCBase* pOwner);                         // 0x1417d06e0
    virtual int vfunc_1();                                  // 1  0x1417d0ab0: 0x23
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417d0720 (back to the idle state)
};
MS2_CHECK_SIZE(StatePuppetNpc, 0x40);

// 0x40.
class StateIdleFittingDoll : public State
{
public:
    StateIdleFittingDoll(PCBase* pOwner);                   // 0x1417d0780
    virtual ~StateIdleFittingDoll();                        // 0x1417d07c0 (??_G 0x1417d0920)
    virtual int vfunc_1();                                  // 1  0x1417d0a70: 1
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d07f0
    virtual void vfunc_5(int n);                            // 5  0x1417d0890 (empty)
};
MS2_CHECK_SIZE(StateIdleFittingDoll, 0x40);
