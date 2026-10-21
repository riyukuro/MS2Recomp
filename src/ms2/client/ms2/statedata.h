// statedata.h - the StateData payloads of the actor states and the climb / crawl / dash states, all from the unit
// ?\state.cpp (0x1417b73c0-0x1417c24a0). NOT an original header (name assumed). State / StateData themselves are in
// ms2/placeholder/state.h, StateMoveSkill in statemanager.h.
//
// Payloads travel through the state-sync record (Unk_StateDataArg, ms2/placeholder/state.h): slot 1 writes the
// payload into the record, slot 2 reads it back. Layouts from the ctors; vftables from RTTI.
#pragma once
#include <afx.h>
#include <efd/Point3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/timer.h"
#include "ms2/client/ms2/statemanager.h"     // StateMoveSkill, Unk_140517b00

// ---- StateData payloads ----

// 0x30. Spawn position and the spawn effect name.
class StateSpawnData : public StateData
{
public:
    StateSpawnData();                                           // 0x1417c0b70
    virtual ~StateSpawnData();                                  // 0x1417c0bf0

    efd::Point3 m_pos;                                          // +0x18
    CString m_str;                                              // +0x28
};
MS2_CHECK_SIZE(StateSpawnData, 0x30);

// 0x40. Jump-to target, gravity (-9.8) and speed scale.
class StateJumpToData : public StateData
{
public:
    StateJumpToData();                                          // 0x1417c0c30
    virtual ~StateJumpToData();                                 // 0x1417c0cf0

    efd::Point3 m_pos;                                          // +0x18
    float m_f24;                                                // +0x24
    float m_fGravity;                                           // +0x28 -9.8
    bool m_b2c;                                                 // +0x2c
    float m_fScale;                                             // +0x30 1.0
    int m_n34;                                                  // +0x34
    float m_f38;                                                // +0x38 yaw (z rotation)
};
MS2_CHECK_SIZE(StateJumpToData, 0x40);

// 0x28. Jump velocity.
class StateJumpData : public StateData
{
public:
    StateJumpData();                                            // 0x1417c0d20
    virtual ~StateJumpData();                                   // 0x1417c0d90

    efd::Point3 m_pos;                                          // +0x18
};
MS2_CHECK_SIZE(StateJumpData, 0x28);

// 0x20. Landing animation name.
class StateLandData : public StateData
{
public:
    StateLandData();                                            // 0x1417c0dc0
    virtual ~StateLandData();                                   // 0x1417c0e30

    CString m_str;                                              // +0x18
};
MS2_CHECK_SIZE(StateLandData, 0x20);

// 0x28.
class StateTurnData : public StateData
{
public:
    StateTurnData();                                            // 0x1417c0e70
    virtual ~StateTurnData();                                   // 0x1417c0ee0

    float m_f18;                                                // +0x18 (the ctor stores 0.0f)
    float m_f1c;                                                // +0x1c
    float m_f20;                                                // +0x20
    float m_f24;                                                // +0x24 1.0
};
MS2_CHECK_SIZE(StateTurnData, 0x28);

// 0x20. The npc being talked to.
class StateInteractNpcData : public StateData
{
public:
    StateInteractNpcData();                                     // 0x1417c0f10
    virtual ~StateInteractNpcData() = default;                  // 0x1417c1c20 (implicit)

    int m_nNpc;                                                 // +0x18
};
MS2_CHECK_SIZE(StateInteractNpcData, 0x20);

// 0x40.
class StateHitData : public StateData
{
public:
    StateHitData();                                             // 0x1417c0f50
    virtual ~StateHitData() = default;                          // 0x1417c1bc0 (implicit)

    float m_f18;                                                // +0x18 1.0 the hit animation speed
    float m_f1c;                                                // +0x1c
    float m_f20;                                                // +0x20 (not set by the ctor)
    float m_f24;                                                // +0x24
    float m_f28;                                                // +0x28
    int m_n2c;                                                  // +0x2c
    int m_n30;                                                  // +0x30
    CString m_str;                                              // +0x38
};
MS2_CHECK_SIZE(StateHitData, 0x40);

// 0x20. Skill id / level (record +0x64 / +0x6c).
class StateSkillData : public StateData
{
public:
    StateSkillData();                                           // 0x1417c0ff0
    virtual ~StateSkillData() = default;                        // 0x1417c1cc0 (implicit)
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x1417c1040
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417c1090

    int m_nSkill;                                               // +0x18
    short m_nLevel;                                             // +0x1c
};
MS2_CHECK_SIZE(StateSkillData, 0x20);

// 0x28. Glide: the skill plus record +0x68.
class StateGlideData : public StateSkillData
{
public:
    StateGlideData();                                           // 0x1417c10e0
    virtual ~StateGlideData() = default;                        // 0x1417c1ba0 (implicit)
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x1417c1120
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417c1160

    int m_n20;                                                  // +0x20
};
MS2_CHECK_SIZE(StateGlideData, 0x28);

// 0x28.
class StateSummonData : public StateData
{
public:
    StateSummonData();                                          // 0x1417c11a0
    StateSummonData(void* pSummon, bool b);                     // 0x1417c11f0
    virtual ~StateSummonData() = default;                       // 0x1417c1d00 (implicit)

    bool m_b18;                                                 // +0x18
    void* m_pSummon;                                            // +0x20
};
MS2_CHECK_SIZE(StateSummonData, 0x28);

// 0x20.
class StateStunData : public StateData
{
public:
    StateStunData(long n);                                      // 0x1417c1250
    virtual ~StateStunData() = default;                         // 0x1417c1ce0 (implicit)

    long m_n18;                                                 // +0x18
};
MS2_CHECK_SIZE(StateStunData, 0x20);

// 0x20.
class StateDeadNPCData : public StateData
{
public:
    StateDeadNPCData(bool b);                                   // 0x1417c12a0
    virtual ~StateDeadNPCData() = default;                      // 0x1417c1b60 (implicit)

    bool m_b18;                                                 // +0x18
};
MS2_CHECK_SIZE(StateDeadNPCData, 0x20);

// 0x20.
class StateRecallData : public StateData
{
public:
    StateRecallData();                                          // 0x1417c12f0
    StateRecallData(void* p);                                   // 0x1417c1330
    virtual ~StateRecallData() = default;                       // 0x1417c1ca0 (implicit)

    void* m_p18;                                                // +0x18
};
MS2_CHECK_SIZE(StateRecallData, 0x20);

// 0x28. Fall start point.
class StateFallData : public StateData
{
public:
    StateFallData(const efd::Point3& kPos);                     // 0x1417c1380
    virtual ~StateFallData() = default;                         // 0x1417c1b80 (implicit)

    efd::Point3 m_pos;                                          // +0x18
};
MS2_CHECK_SIZE(StateFallData, 0x28);

// 0x28. Housing craft: the item name, and two ids (slot 2 parses +0x24 from the record string).
class StateHomemadeData : public StateData
{
public:
    StateHomemadeData(int nA, CString str, int nB);             // 0x1417c13d0
    virtual ~StateHomemadeData() = default;                     // 0x1417c1bf0 (implicit)
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417c1460

    CString m_str;                                              // +0x18
    int m_n20;                                                  // +0x20
    int m_n24;                                                  // +0x24
};
MS2_CHECK_SIZE(StateHomemadeData, 0x28);

// 0x28.
class StateAutoInteractionData : public StateData
{
public:
    StateAutoInteractionData(int a, int b, int c);              // 0x1417c14b0
    virtual ~StateAutoInteractionData() = default;              // 0x1417c1b40 (implicit)

    int m_n18;                                                  // +0x18
    int m_n1c;                                                  // +0x1c
    int m_n20;                                                  // +0x20
};
MS2_CHECK_SIZE(StateAutoInteractionData, 0x28);

// 0x30. Rock-paper-scissors micro game (record +0xb8/+0xbc/+0xc0/+0xc8).
class StateMicroGameRpsData : public StateData
{
public:
    StateMicroGameRpsData(int n);                               // 0x1417c1520
    virtual ~StateMicroGameRpsData() = default;                 // 0x1417c1c70 (implicit)
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x1417c1590
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417c1620

    bool FUN_1417c16b0(MS2Ptr<Unk_StateArg22> p);               // the request carries the same game state

    int m_n18;                                                  // +0x18
    int m_n1c;                                                  // +0x1c -1
    int m_n20;                                                  // +0x20 -1
    CStringW m_str;                                             // +0x28
};
MS2_CHECK_SIZE(StateMicroGameRpsData, 0x30);

// 0x28. Couple dance micro game (record +0xb8/+0xbc/+0xc0).
class StateMicroGameCoupleDanceData : public StateData
{
public:
    StateMicroGameCoupleDanceData(int n);                       // 0x1417c1830
    virtual ~StateMicroGameCoupleDanceData() = default;         // 0x1417c1c40 (implicit)
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x1417c1890
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417c1910

    bool FUN_1417c1990(MS2Ptr<Unk_StateArg22> p);               // the request carries the same dance

    int m_n18;                                                  // +0x18
    bool m_b1c;                                                 // +0x1c
    CString m_str;                                              // +0x20
};
MS2_CHECK_SIZE(StateMicroGameCoupleDanceData, 0x28);

// ---- states ----

// 0xf8. Wall climbing (state type 0x1d); m_n10 is the climb phase 0x56 (hang) .. 0x62 (top).
class StateClimb : public StateMoveSkill
{
public:
    StateClimb(PCBase* pOwner);                                 // 0x1417bc020
    virtual ~StateClimb();                                      // 0x1417bc110
    virtual int vfunc_1();                                      // 1  0x1417bef30
    virtual void vfunc_3(double fTime);                         // 3  0x1417bc390
    virtual void vfunc_4(StateData* pData);                     // 4  0x1417bc180
    virtual void vfunc_5(int n);                                // 5  0x1417bc340
    virtual void vfunc_8(double fTime);                         // 8  0x1417bc470
    virtual void vfunc_9(double fTime);                         // 9  0x1417bc6e0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);        // 12 0x1417bc8a0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);        // 13 0x1417bc9b0
    virtual int vfunc_18();                                     // 18 0x1417bc170
    virtual int vfunc_36();                                     // 36 0x1417bee30

    static int FUN_1417bc010();                                  // ray cast collision groups
    int FUN_1417bcc80();                                        // a climbable wall is ahead (and high enough)
    int FUN_1417bcf20();                                        // the wall is still in front
    int FUN_1417bd030(int bLeft);                               // the wall continues sideways
    int FUN_1417bd310(efd::Point3 kPos);                        // re-attach to the wall at kPos
    int FUN_1417bd420(void* pWall);                             // the wall edges are far enough
    int FUN_1417bd6c0();                                        // the top / bottom is walkable ground
    bool FUN_1417bda60();                                       // phase checks (top, ground, fall off)
    int FUN_1417bdee0();                                        // pick the phase from the input
    int FUN_1417be120(double fTime);                            // move by the phase
    int FUN_1417be590(double fTime);                            // up
    int FUN_1417be680(double fTime);                            // down
    int FUN_1417be760(double fTime);                            // left
    int FUN_1417be880(double fTime);                            // right
    int FUN_1417be990(double fTime);                            // analog stick move
    void FUN_1417beb40();                                       // climb over the top

    Timer m_timerHit;                                           // +0x78
    Timer m_timerHang;                                          // +0xb0
    bool m_bAltUp;                                              // +0xe8 alternate up/down animation
    bool m_bAltSide;                                            // +0xe9 alternate side animation
    float m_fSpeedV;                                            // +0xec
    float m_fSpeedH;                                            // +0xf0
    float m_fF4;                                                // +0xf4 1.0
};
MS2_CHECK_SIZE(StateClimb, 0xf8);
MS2_CHECK_OFFSET(StateClimb, m_timerHit, 0x78);
MS2_CHECK_OFFSET(StateClimb, m_bAltUp, 0xe8);
MS2_CHECK_OFFSET(StateClimb, m_fF4, 0xf4);

// 0x48. Crawling (state type 3); m_n10 0x1b idle / 0x1c moving.
class StateCrawl : public State
{
public:
    StateCrawl(PCBase* pOwner);                                 // 0x1417bef40
    virtual ~StateCrawl();                                      // 0x1417bef90
    virtual int vfunc_1();                                      // 1  0x1417bf8c0
    virtual void vfunc_3(double fTime);                         // 3  0x1417bf080
    virtual void vfunc_4(StateData* pData);                     // 4  0x1417befc0
    virtual void vfunc_5(int n);                                // 5  0x1417bf020
    virtual void vfunc_8(double fTime);                         // 8  0x1417bf2a0
    virtual void vfunc_9(double fTime);                         // 9  0x1417bf3f0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);        // 12 0x1417bf760
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);             // 22 0x1417bf7f0

    bool m_bCrawling;                                           // +0x40 between "begin_crawling" and "end_crawling"
};
MS2_CHECK_SIZE(StateCrawl, 0x48);

// 0xa0. Dash (state type 0x14); m_n10 0x1d start, 0x1e run, 0x1f stop, 0x20 run (after the start animation).
class StateDash : public State
{
public:
    StateDash(PCBase* pOwner);                                  // 0x1417bf8d0
    virtual ~StateDash();                                       // 0x1417bf9b0
    virtual int vfunc_1();                                      // 1  0x1417c0a30
    virtual void vfunc_3(double fTime);                         // 3  0x1417bfbd0
    virtual void vfunc_4(StateData* pData);                     // 4  0x1417bf9f0
    virtual void vfunc_5(int n);                                // 5  0x1417bfb70
    virtual void vfunc_6();                                     // 6  0x1417c0470
    virtual void vfunc_8(double fTime);                         // 8  0x1417c02e0
    virtual void vfunc_9(double fTime);                         // 9  0x1417c0180
    virtual void AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);        // 11 0x1417c0320
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);        // 13 0x1417c0400

    int FUN_1417c0510();                                        // ran into a ladder / rope entity

    float m_fDist;                                              // +0x40 distance run so far
    efd::Point3 m_posLast;                                      // +0x44
    efd::Point3 m_dir;                                          // +0x50
    Timer m_timerStop;                                          // +0x60
    Unk_140517b00 m_tick;                                       // +0x98
};
MS2_CHECK_SIZE(StateDash, 0xa0);
MS2_CHECK_OFFSET(StateDash, m_timerStop, 0x60);
MS2_CHECK_OFFSET(StateDash, m_tick, 0x98);

// 0x38. The interact object being used (built by InteractAction::vfunc_2; the state itself is in another unit).
class StateInteractData : public StateData
{
public:
    StateInteractData();                                        // 0x1417d0be0
    virtual ~StateInteractData();                               // 0x1417d0c50 (??_G 0x1417d4800)
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x1417d0cb0
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417d0d10

    int m_nObjectId;                                            // +0x18
    int m_pad_1c;
    CString m_strObjectId;                                      // +0x20
    CString m_strAnim;                                          // +0x28 the reaction animation
    int m_nFlag;                                                // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(StateInteractData, 0x38);

// 0x30. The hold target (built by HoldAction::vfunc_2; the state itself is in another unit).
class StateHoldData : public StateSkillData
{
public:
    StateHoldData();                                            // 0x1417cb9c0 (skill 20000031 level 1)
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x1417cba30
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x1417cbaf0
    MS2Ptr<class SkillData> FUN_1417cbb50();                    // the skill table row of m_nSkill

    int m_nTargetId;                                            // +0x20
    int m_pad_24;
    CString m_strTargetName;                                    // +0x28
};
MS2_CHECK_SIZE(StateHoldData, 0x30);

// 0x30. The reactor being used (built by ReactorAction::vfunc_2; the state itself is in another unit).
#ifndef MS2_STATEREACTDATA_DEFINED   // also defined by another header (w539: both may be included)
#define MS2_STATEREACTDATA_DEFINED
class StateReactData : public StateData
{
public:
    StateReactData(int nReactorId, CString strName, CString strAnim);   // 0x140b8d3e0

    int m_nReactorId;                                           // +0x18
    int m_pad_1c;
    CString m_strName;                                          // +0x20
    CString m_strAnim;                                          // +0x28
};
MS2_CHECK_SIZE(StateReactData, 0x30);
#endif

// 0x20. The tree watering state (built by TreeWateringAction::vfunc_2; the state itself is in another unit).
#ifndef MS2_STATETREEWATERINGDATA_DEFINED   // also defined by another header (w539: both may be included)
#define MS2_STATETREEWATERINGDATA_DEFINED
class StateTreeWateringData : public StateData
{
public:
    StateTreeWateringData(CString strName);                     // 0x140ad5280 (the callee destroys the argument)

    CString m_strName;                                          // +0x18
};
MS2_CHECK_SIZE(StateTreeWateringData, 0x20);
#endif
