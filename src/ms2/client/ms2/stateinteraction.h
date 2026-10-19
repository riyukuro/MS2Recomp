// stateinteraction.h - the player states of using a world object: StateInteraction (type 0x19, an interact object such as a
// gathering node or notice board), StateInteractionNpc (type 0x1a, talking to an npc) and StateAutoInteraction (type 0x39, the
// auto mining / gathering / breeding / farming progress). All three show the casting bar (the ICastingEventListener at +0x40
// is its callback). NOT an original header (name assumed from the unit client\ms2\stateinteractdata.cpp). Derive State
// (ms2/placeholder/state.h); the data classes StateInteractData / StateInteractNpcData / StateAutoInteractionData are in
// statedata.h.
#pragma once
#include <vector>

#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

class CInteractObject;
class CInteractObjectData;
class StateInteractData;
class StateInteractNpcData;
class StateAutoInteractionData;
struct Unk_CastInfo;     // casting bar request (0x38)

// 0x78. m_n10: 0x8a using, 0x8b / 0x8c reaction animation, 0x8d walk back. m_nEffect is the handle of the reaction effect.
class StateInteraction : public State, public ICastingEventListener
{
public:
    StateInteraction(PCBase* pOwner);                       // 0x1417d0d70
    virtual ~StateInteraction();                            // 0x1417d0e10 (??_G 0x1417d4840)
    virtual int vfunc_1();                                  // 1  0x1417d4980: 0x19
    virtual void vfunc_3(double fTime);                     // 3  0x1417d1700
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d0e70
    virtual void vfunc_5(int n);                            // 5  0x1417d1780
    virtual void vfunc_6();                                 // 6  0x1417d1db0
    virtual void vfunc_8(double fTime);                     // 8  0x1417d18c0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417d1e00
    virtual bool vfunc_25(int n, void* p);                  // 25 0x1417d1eb0: false
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417d48c0: an empty StateInteractData
    virtual void OnCastingFinished();                       // listener 0  0x1417d2210: m_n48 = 1

    void FUN_1417d1ed0();                                   // send the objects in reach (kind 0xb)
    void FUN_1417d2070();                                   // send the objects the player may use (kind 0xc)
    void FUN_1417d2230(CInteractObject* pObject);           // the use has finished
    void FUN_1417d22f0(MS2Ptr<CInteractObjectData> spRow); // create the reaction effect
    void FUN_1417d25e0(MS2Ptr<CInteractObjectData> spRow); // play the start animation
    int FUN_1417d2880();                                    // the object can still be used

    int m_n48;                                              // +0x48 casting finished
    int m_nEffect;                                          // +0x4c reaction effect handle
    MS2Ptr<StateInteractData> m_spInteract;                 // +0x50
    std::vector<MS2Ptr<CInteractObject> > m_aObjects;       // +0x60 usable objects in reach
};
MS2_CHECK_SIZE(StateInteraction, 0x78);
MS2_CHECK_OFFSET(StateInteraction, m_n48, 0x48);
MS2_CHECK_OFFSET(StateInteraction, m_nEffect, 0x4c);
MS2_CHECK_OFFSET(StateInteraction, m_spInteract, 0x50);
MS2_CHECK_OFFSET(StateInteraction, m_aObjects, 0x60);

// 0x60. Talking to an npc.
class StateInteractionNpc : public State, public ICastingEventListener
{
public:
    StateInteractionNpc(PCBase* pOwner);                    // 0x1417d2a50
    virtual ~StateInteractionNpc();                         // 0x1417d2ae0 (??_G 0x1417d4880)
    virtual int vfunc_1();                                  // 1  0x1417d4990: 0x1a
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d2b30
    virtual void vfunc_5(int n);                            // 5  0x1417d2e70
    virtual void vfunc_6();                                 // 6  0x1417d30d0
    virtual void vfunc_8(double fTime);                     // 8  0x1417d2ed0
    virtual void OnCastingFinished();                       // listener 0  0x1417d3120: m_n48 = 1

    int m_n48;                                              // +0x48 casting finished
    MS2Ptr<StateInteractNpcData> m_spNpc;                   // +0x50
};
MS2_CHECK_SIZE(StateInteractionNpc, 0x60);
MS2_CHECK_OFFSET(StateInteractionNpc, m_n48, 0x48);
MS2_CHECK_OFFSET(StateInteractionNpc, m_spNpc, 0x50);

// 0x60. The mastery auto action (mining / gathering / breeding / farming) with its progress bar.
class StateAutoInteraction : public State, public ICastingEventListener
{
public:
    StateAutoInteraction(PCBase* pOwner);                   // 0x1417d3140
    virtual ~StateAutoInteraction();                        // 0x1417d31d0 (??_G 0x1417d47c0)
    virtual int vfunc_1();                                  // 1  0x1417d4970: 0x39
    virtual void vfunc_3(double fTime);                     // 3  0x1417d3440
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d3220
    virtual void vfunc_5(int n);                            // 5  0x1417d33e0
    virtual void vfunc_8(double fTime);                     // 8  0x1417d35b0
    virtual void OnCastingFinished();                       // listener 0  0x1417d3690: m_n48 = 1

    efd::utf8string FUN_1417d36b0();                        // "Object_React_C"
    void FUN_1417d3700(Unk_CastInfo* pInfo);                // fill the casting bar request

    int m_n48;                                              // +0x48 casting finished
    MS2Ptr<StateAutoInteractionData> m_spAuto;              // +0x50
};
MS2_CHECK_SIZE(StateAutoInteraction, 0x60);
MS2_CHECK_OFFSET(StateAutoInteraction, m_n48, 0x48);
MS2_CHECK_OFFSET(StateAutoInteraction, m_spAuto, 0x50);
