// statereact.h - StateReact (actor state types 0x9e / 0x9f: reacting to another actor - the player plays an animation
// at a target and, for 0x9f, shows the casting bar while the target stays in reach) and its payload StateReactData.
// NOT an original header (names assumed from the unit client\ms2\statereact.cpp and the RTTI). The ICastingEventListener
// at +0x40 is the casting bar's callback.
// MS2-UNIT: client\ms2\statereact.cpp
// MS2-RANGE: 0x140b8d3e0-0x140b8e760 .text$mn
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

class PCBase;
class Unk_ReactRef;     // counted reference to an actor looked up by name (8 bytes)

// 0x30. The target actor's name and the animation to play.
#ifndef MS2_STATEREACTDATA_DEFINED   // also defined by another header (w539: both may be included)
#define MS2_STATEREACTDATA_DEFINED
class StateReactData : public StateData
{
public:
    StateReactData(int nId, CString strTarget, CString strAnim);   // 0x140b8d3e0
    virtual ~StateReactData();                              // 0  0x140b8d480 (??_G 0x140b8e520)
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1  0x140b8d4e0
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2  0x140b8d540

    int m_nId;                                              // +0x18
    CString m_strTarget;                                    // +0x20
    CString m_strAnim;                                      // +0x28
};
MS2_CHECK_SIZE(StateReactData, 0x30);
MS2_CHECK_OFFSET(StateReactData, m_nId, 0x18);
MS2_CHECK_OFFSET(StateReactData, m_strTarget, 0x20);
MS2_CHECK_OFFSET(StateReactData, m_strAnim, 0x28);
#endif

// 0x60.
class StateReact : public State, public ICastingEventListener
{
public:
    StateReact(PCBase* pOwner);                             // 0x140b8d5a0
    virtual ~StateReact();                                  // 0  0x140b8d630 (??_G 0x140b8e4e0)
    virtual int vfunc_1();                                  // 1  0x140b8e630: 0x3d
    virtual void vfunc_3(double fTime);                     // 3  0x140b8d900
    virtual void vfunc_4(StateData* pData);                 // 4  0x140b8d680
    virtual void vfunc_5(int n);                            // 5  0x140b8d9c0
    virtual void vfunc_6();                                 // 6  0x140b8dde0
    virtual void vfunc_8(double fTime);                     // 8  0x140b8da40
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140b8de30
    virtual bool vfunc_25(int n, void* p);                  // 25 0x140b8deb0: false
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140b8e560: a new StateReactData
    virtual void OnCastingFinished();                       // listener 0  0x140b8dfb0: m_n48 = 1

    void FUN_140b8ded0();                                   // leave when the target actor is gone
    void FUN_140b8dfd0(Unk_ReactRef kRef);                  // by-value reference: the callee destroys it
    bool FUN_140b8e030();                                   // start the reaction animation

    int m_n48;                                              // +0x48 casting finished
    MS2Ptr<StateReactData> m_spData;                        // +0x50
};
MS2_CHECK_SIZE(StateReact, 0x60);
MS2_CHECK_OFFSET(StateReact, m_n48, 0x48);
MS2_CHECK_OFFSET(StateReact, m_spData, 0x50);
