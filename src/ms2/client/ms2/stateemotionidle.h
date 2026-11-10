// stateemotionidle.h - the emotion / idle-emotion / trigger actor states and their StateData payloads. NOT an
// original header (name assumed from the unit client\ms2\stateemotionidle.cpp). All classes derive State / StateData
// (ms2/placeholder/state.h); slot names follow that header.
//   state type ids (vfunc_1): StateEmotion 0x0b, StateEmotionIdle 0x0f, StateTriggerEmotion 0x35, StateTriggerFollowNpc 0x46
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/timer.h"
#include "ms2/placeholder/statetriggeremotiondata.h"   // StateTriggerEmotionData (0x48), declared for the trigger service

// 0x20. +0x18 emotion id. vftable 0x142f6d... (dtor 0x1417c5210, ??_G 0x1417c5500)
class StateEmotionData : public StateData
{
public:
    StateEmotionData();                                     // 0x1417c3780
    StateEmotionData(long nEmotion);                        // 0x1417c37c0
    ~StateEmotionData() = default;                          // 0x1417c5210
    virtual void vfunc_1(Unk_StateDataArg* p);              // 0x1417c3810
    virtual void vfunc_2(Unk_StateDataArg* p);              // 0x1417c3850

    int m_nEmotion;                                         // +0x18
    int m_pad_1c;
};
MS2_CHECK_SIZE(StateEmotionData, 0x20);

// 0x20. +0x18 emotion id (dtor 0x1417c6af0, ??_G 0x1417c6c60)
class StateEmotionIdleData : public StateData
{
public:
    StateEmotionIdleData();                                 // 0x1417c5ae0
    StateEmotionIdleData(long nEmotion);                    // 0x1417c5b20
    ~StateEmotionIdleData() = default;                      // 0x1417c6af0
    virtual void vfunc_1(Unk_StateDataArg* p);              // 0x1417c5b70
    virtual void vfunc_2(Unk_StateDataArg* p);              // 0x1417c5bb0

    int m_nEmotion;                                         // +0x18
    int m_pad_1c;
};
MS2_CHECK_SIZE(StateEmotionIdleData, 0x20);

// 0x20. +0x18 npc id (dtor 0x1417c51f0, ??_G 0x1417c5480)
class StateDataTriggerFollowNpc : public StateData
{
public:
    StateDataTriggerFollowNpc(long nNpc);                   // 0x1417c49e0
    ~StateDataTriggerFollowNpc() = default;                 // 0x1417c51f0
    virtual void vfunc_1(Unk_StateDataArg* p);              // 0x1417c4a30
    virtual void vfunc_2(Unk_StateDataArg* p);              // 0x1417c4a60

    int m_nNpc;                                             // +0x18
    int m_pad_1c;
};
MS2_CHECK_SIZE(StateDataTriggerFollowNpc, 0x20);

// 0x60. Plays one emotion animation (type 0x0b).
class StateEmotion : public State
{
public:
    StateEmotion(PCBase* pOwner);                           // 0x1417c3890
    virtual ~StateEmotion();                                // 0x1417c3920 (??_G 0x1417c54c0)
    virtual int vfunc_1();                                  // 1  0x1417c5780: 0x0b
    virtual void vfunc_3(double fTime);                     // 3  0x1417c3fe0
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c3990
    virtual void vfunc_5(int n);                            // 5  0x1417c3cb0
    virtual void vfunc_8(double fTime);                     // 8  0x1417c3e00
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417c4150
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);         // 22 0x1417c3d30
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417c5600
    virtual bool vfunc_28(MS2Ptr<StateSyncObject> p);        // 28 0x1417c4270

    int FUN_1417c4320();                                    // emotion id of the data (0 when none)

    MS2Ptr<StateEmotionData> m_spData2;                     // +0x40
    CString m_strAnim;                                      // +0x50 emotion animation name
    CString m_strLoop;                                      // +0x58 follow-up (loop) animation name
};
MS2_CHECK_SIZE(StateEmotion, 0x60);
MS2_CHECK_OFFSET(StateEmotion, m_spData2, 0x40);
MS2_CHECK_OFFSET(StateEmotion, m_strLoop, 0x58);

// 0x88. Plays the emotion list of a trigger (type 0x35).
class StateTriggerEmotion : public State
{
public:
    StateTriggerEmotion(PCBase* pOwner);                    // 0x1417c43e0
    virtual ~StateTriggerEmotion();                         // 0x1417c44b0 (??_G 0x1417c5540)
    virtual int vfunc_1();                                  // 1  0x1417c5790: 0x35
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c4500
    virtual void vfunc_5(int n);                            // 5  0x1417c4770
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417c47d0
    virtual int vfunc_16();                                 // 16 0x1417c47b0: m_nFlag
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417c5680

    ATL::CAtlArray<CStringA> m_aEmotions;                   // +0x40 emotion names
    int m_nIndex;                                           // +0x60 current name
    int m_nFlag;                                            // +0x64
    int m_nMode;                                            // +0x68 0 = list, else hold the first for m_nDuration
    int m_nDuration;                                        // +0x6c ms
    unsigned m_nStart;                                      // +0x70 start time
    int m_pad_74;
    MS2Ptr<StateTriggerEmotionData> m_spData2;              // +0x78
};
MS2_CHECK_SIZE(StateTriggerEmotion, 0x88);
MS2_CHECK_OFFSET(StateTriggerEmotion, m_nIndex, 0x60);
MS2_CHECK_OFFSET(StateTriggerEmotion, m_spData2, 0x78);

// 0x58. Makes the actor follow an npc (type 0x46).
class StateTriggerFollowNpc : public State
{
public:
    StateTriggerFollowNpc(PCBase* pOwner);                  // 0x1417c4a90
    virtual ~StateTriggerFollowNpc();                       // 0x1417c4b00 (??_G 0x1417c55c0)
    virtual int vfunc_1();                                  // 1  0x1417c57a0: 0x46
    virtual void vfunc_3(double fTime);                     // 3  0x1417c4c90
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c4b40
    virtual bool vfunc_25(int n, void* p);                  // 25 0x1417c4fe0
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417c5700

    MS2Ptr<StateDataTriggerFollowNpc> m_spData2;            // +0x40
    short m_nAnim;                                          // +0x50 last animation key
    short m_pad_52;
    int m_pad_54;
};
MS2_CHECK_SIZE(StateTriggerFollowNpc, 0x58);

// 0x98. Idle emotion (type 0x0f): random idle animations 0x6f..0x72.
class StateEmotionIdle : public State
{
public:
    StateEmotionIdle(PCBase* pOwner);                       // 0x1417c5bf0
    virtual ~StateEmotionIdle();                            // 0x1417c5c90 (??_G 0x1417c6c20)
    virtual int vfunc_1();                                  // 1  0x1417c6d20: 0x0f
    virtual void vfunc_3(double fTime);                     // 3  0x1417c6070
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c5d10
    virtual void vfunc_5(int n);                            // 5  0x1417c61a0
    virtual void vfunc_8(double fTime);                     // 8  0x1417c6230
    virtual void vfunc_9(double fTime);                     // 9  0x1417c6810
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417c6940
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);         // 22 0x1417c6990
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417c6ca0

    int FUN_1417c6a30();                                    // emotion id of the data (0 when none)

    CString m_strAnim;                                      // +0x40
    CString m_strNext;                                      // +0x48
    Timer m_timer;                                          // +0x50
    MS2Ptr<StateEmotionIdleData> m_spData2;                 // +0x88
};
MS2_CHECK_SIZE(StateEmotionIdle, 0x98);
MS2_CHECK_OFFSET(StateEmotionIdle, m_timer, 0x50);
MS2_CHECK_OFFSET(StateEmotionIdle, m_spData2, 0x88);
