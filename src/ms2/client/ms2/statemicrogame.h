// statemicrogame.h - StateMicroGameRps (actor state type 0x3c: the rock-paper-scissors event game played against another
// player; sub-states 0x99-0x9d) and StateMicroGameCoupleDance (actor state type 0x45: the couple dance event game; sub-
// states 0xaa-0xb1) with the helpers they instantiate. NOT an original header (names assumed from the unit
// client\ms2\statemicrogame.cpp and the RTTI). Their payloads are StateMicroGameRpsData / StateMicroGameCoupleDanceData
// (statedata.h).
// MS2-UNIT: client\ms2\statemicrogame.cpp
// MS2-RANGE: 0x140b866d0-0x140b8c180 .text$mn
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

class PCBase;
class Unk_StateArg22;
class StateMicroGameRpsData;
class StateMicroGameCoupleDanceData;
class Unk_StateArg29;

// 0x50. The partner is the actor whose id the payload (+0x18) holds.
class StateMicroGameRps : public State
{
public:
    StateMicroGameRps(PCBase* pOwner);                      // 0x140b866d0
    virtual ~StateMicroGameRps();                           // 0  0x140b86730 (??_G 0x140b8bcd0)
    virtual int vfunc_1();                                  // 1  0x140b8be20: 0x3c
    virtual void vfunc_3(double fTime);                     // 3  0x140b86860
    virtual void vfunc_4(StateData* pData);                 // 4  0x140b86770
    virtual void vfunc_5(int n);                            // 5  0x140b86810
    virtual void vfunc_6();                                 // 6  0x140b870a0
    virtual void vfunc_8(double fTime);                     // 8  0x140b86d80
    virtual void vfunc_9(double fTime);                     // 9  0x140b86ea0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140b86ad0
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x140b869c0
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140b8bd90: a new StateMicroGameRpsData
    virtual bool vfunc_28(MS2Ptr<Unk_StateArg22> p);        // 28 0x140b87100

    int FUN_140b871c0();                                    // the played card (-1: none)
    bool FUN_140b87210(MS2Ptr<Unk_StateArg22> p);           // the request carries the same game
    int FUN_140b872c0();                                    // the partner's actor id
    void FUN_140b87310(int nMode, int nCard, int nPick);    // play a card (UI selection)
    bool FUN_140b876a0();                                   // start the game: reset the payload
    void FUN_140b877c0();                                   // show a random chat line of the event
    PCBase* FUN_140b879d0();                                // the partner actor
    void FUN_140b87a40(unsigned int nSeq);                  // play the default motion
    void FUN_140b87ad0();                                   // show both results
    void FUN_140b87cc0();                                   // reset both controllers
    bool FUN_140b87e00();                                   // the result text of the picked card
    void FUN_140b88290(double fTime);                       // leave when the partner left

    MS2Ptr<StateMicroGameRpsData> m_spRps;                  // +0x40
};
MS2_CHECK_SIZE(StateMicroGameRps, 0x50);
MS2_CHECK_OFFSET(StateMicroGameRps, m_spRps, 0x40);

// 0x80.
class StateMicroGameCoupleDance : public State
{
public:
    StateMicroGameCoupleDance(PCBase* pOwner);              // 0x140b88aa0
    virtual ~StateMicroGameCoupleDance();                   // 0  0x140b88b40 (??_G 0x140b8bc90)
    virtual int vfunc_1();                                  // 1  0x140b8be10: 0x45
    virtual void vfunc_3(double fTime);                     // 3  0x140b88c90
    virtual void vfunc_4(StateData* pData);                 // 4  0x140b88bb0
    virtual void vfunc_5(int n);                            // 5  0x140b88c50
    virtual void vfunc_6();                                 // 6  0x140b892f0
    virtual void vfunc_8(double fTime);                     // 8  0x140b89040
    virtual void vfunc_9(double fTime);                     // 9  0x140b89160
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140b88f30
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x140b88e20
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140b8bd10: a new StateMicroGameCoupleDanceData
    virtual bool vfunc_28(MS2Ptr<Unk_StateArg22> p);        // 28 0x140b89350

    bool FUN_140b89410(MS2Ptr<Unk_StateArg22> p);           // the request carries the same dance
    int FUN_140b894c0();                                    // the partner's actor id
    bool FUN_140b89510(const std::vector<int>& aStages);    // start the dance with the event's stage list
    bool FUN_140b89880(int nTime, bool bFlag, int nA, int nB);   // answer a dance request
    PCBase* FUN_140b89dd0();                                // the partner actor
    void FUN_140b89e40(unsigned int nSeq);                  // play the default motion
    void FUN_140b89ed0(double fTime);                       // leave when the partner left
    bool FUN_140b89f90();                                   // the last stage is reached
    void FUN_140b8a060();                                   // advance the dance by the clock
    bool FUN_140b8a290();                                   // stage start
    bool FUN_140b8a5f0();                                   // stage play
    bool FUN_140b8a910();                                   // stage end
    bool FUN_140b8acc0();                                   // dance finish
    void FUN_140b8b020(const std::vector<int>& aStages);    // take over the stage list

    CStringA m_strAnim;                                     // +0x40 the animation of the stage
    MS2Ptr<StateMicroGameCoupleDanceData> m_spDance;        // +0x48
    std::vector<int> m_aStages;                             // +0x58
    int m_nStage;                                           // +0x70
    int m_nDeadline;                                        // +0x74 clock tick of the next advance (0: none)
    int m_nScore;                                           // +0x78
};
MS2_CHECK_SIZE(StateMicroGameCoupleDance, 0x80);
MS2_CHECK_OFFSET(StateMicroGameCoupleDance, m_strAnim, 0x40);
MS2_CHECK_OFFSET(StateMicroGameCoupleDance, m_spDance, 0x48);
MS2_CHECK_OFFSET(StateMicroGameCoupleDance, m_aStages, 0x58);
MS2_CHECK_OFFSET(StateMicroGameCoupleDance, m_nStage, 0x70);
MS2_CHECK_OFFSET(StateMicroGameCoupleDance, m_nScore, 0x78);
