// stateladder.h - StateLadder (type 8): the actor state of a player climbing a ladder / rope entity. m_n10 is the
// climb phase (0x2a idle on the ladder, 0x2b climbing up, 0x2c climbing down, 0x2d getting on at the bottom, 0x2e done,
// 0x2f / 0x30 / 0x31 getting off at the top / sliding off, 0x32 falling off); the position is interpolated between
// recorded points by Unk_LadderStep timers. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\stateladder.cpp` (0x1417d79e0-0x1417d9c70 .text$mn, dir client\ms2). Header name assumed; names invented from use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/timer.h"
#include <efd/Point3.h>

namespace egf { class Entity; }

// A timed move between three points (0x60): a timer plus the start, middle and end of the move (inline members of the
// original header; the ctor / dtor / helpers come out of this unit).
struct Unk_LadderStep
{
    Unk_LadderStep();                                       // 0x1417d9b50
    ~Unk_LadderStep();                                      // 0x1417d9bd0 (Timer::~Timer)
    void FUN_1417d79e0(efd::Point3 kA, efd::Point3 kB, efd::Point3 kC);   // reset and set the points
    void FUN_1417d7a60();                                   // reset and clear the points
    void FUN_1417d7ad0(unsigned int ms);                    // arm
    float FUN_1417d7b00();                                  // elapsed ratio

    Timer m_timer;                                          // +0x00
    efd::Point3 m_a;                                        // +0x38
    efd::Point3 m_b;                                        // +0x44
    efd::Point3 m_c;                                        // +0x50
};
MS2_CHECK_SIZE(Unk_LadderStep, 0x60);
MS2_CHECK_OFFSET(Unk_LadderStep, m_a, 0x38);

// 0x278.
class StateLadder : public State
{
public:
    StateLadder(PCBase* pOwner);                            // 0x1417d7b30
    virtual ~StateLadder();                                 // 0  0x1417d7c30 (??_G 0x1417d9bf0)
    virtual int vfunc_1();                                  // 1  0x1417d9c30: 8
    virtual void vfunc_3(double fTime);                     // 3  0x1417d8370
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d7ce0 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417d82a0 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417d8490
    virtual void vfunc_9(double fTime);                     // 9  0x1417d86d0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);     // 12 0x1417d8840
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417d8980
    virtual int vfunc_18();                                 // 18 0x1417d9c40: 0
    virtual void vfunc_34();                                // 34 0x1417d9c50

    egf::Entity* FUN_1417d8b20(int nSide, unsigned int nKey);   // the ladder entity found next to the actor
    float FUN_1417d8c00();                                  // phase update; returns the climb distance of this frame
    void FUN_1417d9240(float fDist);                        // move the actor
    float FUN_1417d9880(egf::Entity* pLadder);              // height to hang at
    efd::Point3 FUN_1417d99e0();                            // the top of the ladder above the actor (zero when none)

    egf::Entity* m_pLadder;             // +0x40
    bool m_bUpFlip;                     // +0x48
    bool m_bDownFlip;                   // +0x49
    Timer m_timerUp;                    // +0x50
    Timer m_timerDown;                  // +0x88
    Timer m_timerPos;                   // +0xc0
    Unk_LadderStep m_step0;             // +0xf8
    Unk_LadderStep m_step1;             // +0x158
    Unk_LadderStep m_step2;             // +0x1b8
    Unk_LadderStep m_step3;             // +0x218
};
MS2_CHECK_SIZE(StateLadder, 0x278);
MS2_CHECK_OFFSET(StateLadder, m_pLadder, 0x40);
MS2_CHECK_OFFSET(StateLadder, m_timerUp, 0x50);
MS2_CHECK_OFFSET(StateLadder, m_step0, 0xf8);
MS2_CHECK_OFFSET(StateLadder, m_step3, 0x218);
