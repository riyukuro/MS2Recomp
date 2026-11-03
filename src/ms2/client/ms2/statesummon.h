// statesummon.h - the summon / go-home / recall family of the client state manager: StateSummon, StateGoToHome and
// StateRecall (each State + ICastingEventListener: a casting bar is shown while the cast runs and OnCastingFinished
// flips m_n48), plus the four pet helper states StateSummonIdle, StateSummonRevive, StateSummonExpire,
// StateSummonItemPick and StateSummonPortal. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\statesummon.cpp` (0x1417f7550-0x1417fa370 .text$mn, 0x140104390-0x140104530 .text$di, dir client\ms2). Header
// name assumed; member names invented from their use.
//
// StateGoToHome and StateSummonIdle have no vfunc_1 override: their vftable slot 1 is _purecall, so both classes stay
// abstract (the exe still emits their ctors, which is why the definitions are out of line below).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"                  // State / StateData
#include "ms2/placeholder/icastingeventlistener.h"  // the casting-bar listener StateSummon/GoToHome/Recall implement
#include "ms2/placeholder/timer.h"                  // Timer (StateSummonRevive)
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/statedata.h"               // StateSummonData / StateRecallData
#include "ms2/placeholder/intervaltimer.h"

class NiActorManager;
class NiControllerSequence;

// 0x60. The ridee/pet summon cast. m_n10 ends up 0x82 (a pet item) or 0x83 (a ridee item) according to the item the
// summon data points at; the casting bar runs for SummonRideeDuration.
class StateSummon : public State, public ICastingEventListener
{
public:
    StateSummon(PCBase* pOwner);                                                        // 0x1417f7550
    ~StateSummon();                                                                     // 0x1417f75e0
    int vfunc_1();                                                                      // 0x1417fa100: 0x26
    void vfunc_3(double fTime);                                                         // 0x1417f7a70
    void vfunc_4(StateData* pData);                                                     // 0x1417f7630
    void vfunc_5(int n);                                                                // 0x1417f7af0
    void vfunc_6();                                                                     // 0x1417f8190
    void vfunc_8(double fTime);                                                         // 0x1417f7b60
    void vfunc_9(double fTime);                                                         // 0x1417f8060
    int vfunc_20();                                                                     // 0x1417fa0e0: 1
    void OnCastingFinished();                                                           // 0x1417f81e0

    int m_n48;                                                                          // +0x48 the cast-finished flag
    MS2Ptr<StateSummonData> m_spData;                                                   // +0x50 the summon data
};
MS2_CHECK_SIZE(StateSummon, 0x60);

// 0x50. The "return home" cast (the PC_ReturnHouse command).
class StateGoToHome : public State, public ICastingEventListener
{
public:
    StateGoToHome(PCBase* pOwner);                                                      // 0x1417f8200
    ~StateGoToHome();                                                                   // 0x1417f8270
    void vfunc_4(StateData* pData);                                                     // 0x1417f82b0
    void vfunc_5(int n);                                                                // 0x1417f84c0
    void vfunc_6();                                                                     // 0x1417f8550
    void vfunc_8(double fTime);                                                         // 0x1417f8520
    int vfunc_20();                                                                     // 0x1417fa0c0: 1
    void OnCastingFinished();                                                           // 0x1417f85a0

    int m_n48;                                                                          // +0x48 the cast-finished flag
};
MS2_CHECK_SIZE(StateGoToHome, 0x50);

// 0x60. The recall cast; m_n10 is 0x83 for the ridee variant.
class StateRecall : public State, public ICastingEventListener
{
public:
    StateRecall(PCBase* pOwner);                                                        // 0x1417f85c0
    ~StateRecall();                                                                     // 0x1417f8650
    int vfunc_1();                                                                      // 0x1417fa0f0: 0x2c
    void vfunc_4(StateData* pData);                                                     // 0x1417f86a0
    void vfunc_5(int n);                                                                // 0x1417f88b0
    void vfunc_6();                                                                     // 0x1417f8b60
    void vfunc_8(double fTime);                                                         // 0x1417f8920
    int vfunc_20();                                                                     // 0x1417fa0d0: 1
    void OnCastingFinished();                                                           // 0x1417f8bb0

    int m_n48;                                                                          // +0x48 the cast-finished flag
    MS2Ptr<StateRecallData> m_spData;                                                   // +0x50 the recall data
};
MS2_CHECK_SIZE(StateRecall, 0x60);

// 0x58. The pet's idle state: two poll timers (the idle motion and the skill motion).
class StateSummonIdle : public State
{
public:
    StateSummonIdle(PCBase* pOwner);                                                    // 0x1417f8bd0
    ~StateSummonIdle();                                                                 // 0x1417f8c60
    void vfunc_3(double fTime);                                                         // 0x1417f8ce0
    void vfunc_4(StateData* pData);                                                     // 0x1417f8c90
    void vfunc_5(int n);                                                                // 0x1417f8d50
    void vfunc_9(double fTime);                                                         // 0x1417f8d90
    void EndOfSequence(NiActorManager* pkManager, unsigned int nSequenceID, NiControllerSequence* pkSeq,
                       float fEventTime);                                               // 0x1417f8fc0

    int m_n40;                                                                          // +0x40 playing a pet motion (0 = free)
    int m_n44;                                                                          // +0x44 the idle timer is armed
    Unk_IntervalTimer m_t48;                                                            // +0x48 idle motion timer
    Unk_IntervalTimer m_t50;                                                            // +0x50 skill motion timer
};
MS2_CHECK_SIZE(StateSummonIdle, 0x58);

// 0x80. The pet revive state: it polls the (dead) pet and sends the revive request every m_n40 ms.
// The destructor is implicit (0x1417f9d70 stores no vftable, it just runs Timer::~Timer and State::~State).
class StateSummonRevive : public State
{
public:
    StateSummonRevive(PCBase* pOwner);                                                  // 0x1417f9500
    int vfunc_1();                                                                      // 0x1417fa140: 0x30
    void vfunc_3(double fTime);                                                         // 0x1417f95c0
    void vfunc_4(StateData* pData);                                                     // 0x1417f9570
    void vfunc_5(int n);                                                                // 0x1417f96c0
    void vfunc_9(double fTime);                                                         // 0x1417f9700

    int m_n40;                                                                          // +0x40 poll interval (3000 ms)
    Timer m_timer;                                                                      // +0x48
};
MS2_CHECK_SIZE(StateSummonRevive, 0x80);

// 0x48. The pet expire state: plays the expire motion once the poll timer elapses (implicit destructor).
class StateSummonExpire : public State
{
public:
    StateSummonExpire(PCBase* pOwner);                                                  // 0x1417f9860
    int vfunc_1();                                                                      // 0x1417fa110: 0x31
    void vfunc_3(double fTime);                                                         // 0x1417f9900
    void vfunc_4(StateData* pData);                                                     // 0x1417f98c0
    void vfunc_5(int n);                                                                // 0x1417f99c0

    Unk_IntervalTimer m_t40;                                                            // +0x40
};
MS2_CHECK_SIZE(StateSummonExpire, 0x48);

// 0x40. The pet item-pick state: asks the field object the pet stands on to pick up the item (implicit destructor).
class StateSummonItemPick : public State
{
public:
    StateSummonItemPick(PCBase* pOwner);                                                // 0x1417f99f0
    int vfunc_1();                                                                      // 0x1417fa120: 0x32
    void vfunc_3(double fTime);                                                         // 0x1417f9a60
    void vfunc_4(StateData* pData);                                                     // 0x1417f9a30
    void vfunc_5(int n);                                                                // 0x1417f9b20
};
MS2_CHECK_SIZE(StateSummonItemPick, 0x40);

// 0x40. The portal state: just plays the idle animation (implicit destructor).
class StateSummonPortal : public State
{
public:
    StateSummonPortal(PCBase* pOwner);                                                  // 0x1417f9b50
    int vfunc_1();                                                                      // 0x1417fa130: 0x38
    void vfunc_4(StateData* pData);                                                     // 0x1417f9b90
};
MS2_CHECK_SIZE(StateSummonPortal, 0x40);
