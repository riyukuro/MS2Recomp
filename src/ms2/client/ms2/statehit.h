// statehit.h - StateHit (type 0xd): the actor state of a player that was hit; plays the hit animation named by the
// StateHitData record (a fly-away "Jump_FlyDamg_A" or the "Damg_C" hit) and ends when the animation has run out.
// StateHitNPC is the same state for an NPC, which instead lifts the model along a parabola while it is being hit.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statehit.cpp` (0x1417ca270-0x1417cb9c0
// .text$mn, dir client\ms2). Header name assumed; member names invented from use.
#pragma once

#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/commonfiles/timer.h"

class NiActorManager;
class NiControllerSequence;

// 0xd0.
class StateHit : public State
{
public:
    StateHit(PCBase* pOwner);                               // 0x1417ca270
    virtual ~StateHit();                                    // 0  0x1417ca300 (??_G 0x1417cb8d0)
    virtual int vfunc_1();                                  // 1  0x1417cb960: 0xd
    virtual void vfunc_3(double fTime);                     // 3  0x1417ca8a0
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417ca370 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417caa10 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417cad10
    virtual void vfunc_9(double fTime);                     // 9  0x1417caa80
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417caaf0
    virtual int vfunc_15();                                 // 15 0x1417cb950: 1
    virtual bool vfunc_32();                                // 32 0x1417cb980
    virtual void vfunc_33(bool b);                          // 33 0x1417cb9a0
    virtual bool vfunc_36();                                // 36 0x1417cb120: the hit timer ran out

    bool FUN_1417cb160();                                   // the hit is still running
    void FUN_1417cb1d0();                                   // clear the hit record
    bool FUN_1417cb2a0();                                   // the hit has a duration
    int FUN_1417cb2f0();                                    // m_nBc

    Timer m_timer;                      // +0x40
    efd::utf8string m_strAnim;          // +0x78 the hit animation
    float m_fEndTime;                   // +0x98 the clock time the hit state ends
    float m_f9c;                        // +0x9c
    float m_fA0;                        // +0xa0 the clock time the hit lasts until
    float m_fA4;                        // +0xa4 the duration
    float m_fA8;                        // +0xa8
    float m_fAc;                        // +0xac the actor's height when the hit began
    float m_fB0;                        // +0xb0 the fly-away height
    int m_nB4;                          // +0xb4
    int m_nB8;                          // +0xb8
    int m_nBc;                          // +0xbc
    CString m_strC0;                    // +0xc0 the animation name the record asks for
    bool m_bC8;                         // +0xc8 the state has ended
};
MS2_CHECK_SIZE(StateHit, 0xd0);
MS2_CHECK_OFFSET(StateHit, m_timer, 0x40);
MS2_CHECK_OFFSET(StateHit, m_strAnim, 0x78);
MS2_CHECK_OFFSET(StateHit, m_fEndTime, 0x98);
MS2_CHECK_OFFSET(StateHit, m_strC0, 0xc0);
MS2_CHECK_OFFSET(StateHit, m_bC8, 0xc8);

// 0x60.
class StateHitNPC : public State
{
public:
    StateHitNPC(PCBase* pOwner);                            // 0x1417cb310
    virtual ~StateHitNPC();                                 // 0  0x1417cb370 (??_G 0x1417cb910)
    virtual int vfunc_1();                                  // 1  0x1417cb970: 0xd
    virtual void vfunc_3(double fTime);                     // 3  0x1417cb4c0
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417cb3a0 (enter)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417cb5d0

    void FUN_1417cb730();                                   // clear the hit record
    void FUN_1417cb7b0();                                   // lift the model along the parabola

    int m_n40;                          // +0x40
    float m_f44;                        // +0x44
    float m_fEndTime;                   // +0x48
    float m_f4c;                        // +0x4c
    float m_f50;                        // +0x50
    float m_f54;                        // +0x54
    float m_f58;                        // +0x58
    int m_n5c;                          // +0x5c
};
MS2_CHECK_SIZE(StateHitNPC, 0x60);
