// state.h - State (RTTI .?AVState@@, vftable 0x142f6c218, 36 slots, 0x40 bytes) and StateData (RTTI .?AVStateData@@,
// CPtred-derived, vftable 3 slots, 0x18 bytes): the base of every actor state (StateIdle, StateSkill,
// StateSkillMagicControl, StateAutoInteraction, StateBanner ... ~75 classes) run by CStateManager (PCBase +0x140).
// NOT an original header (sb2). Owning unit ?\state.cpp (path unknown; ctor 0x1417b7d30, dtor 0x1417b7dc0, slot
// bodies 0x1417b7e20..0x1417b9430, deleting dtor 0x1417ba930). Unrecovered: every out-of-line member below is a
// symbols-manual row (the base implementation VA from the State vftable is given per slot).
//
// HOW TO USE (unit workers): `class X : public State { ... };` with ctor `X(PCBase* pOwner) : State(pOwner)`.
// Virtual names are vfunc_N = slot N (names unknown); to override, copy the exact declaration. Slot 1 is pure.
// Slots 32/33 are header inlines: their only COMDATs (0x140ac07a0/0x140ac07b0) are in the first unit that
// instantiates them (unit_140ac02e0, StateSkillMagicControl), so keep them inline.
//
// Evidence (exe KMS2_DEV x64):
// - Layout from the ctor 0x1417b7d30 / dtor 0x1417b7dc0: +0x08 owner (ctor arg; vcalls up to slot 108 = PCBase,
//   e.g. 0x1417b7e80 calls owner slot 95 float, 0x1417b7fb0 slots 104/102), +0x10 int (slot 2 setter, getter
//   0x1417b7e40), +0x14 int = 1 (slot 14 getter), +0x18 std::list<unsigned> (ctor/dtor COMDATs 0x140a3d2e0/0x140a3d3d0
//   from chatemoticoncli; iterator deref 0x140a3d6f0 = node+0x10 -> list node; 0x1417b9310 walks it and removes each
//   id), +0x28 int = 0, +0x30 MS2Ptr<StateData> (default ctor 0x1417ba320, AssignRaw 0x14167ec90, =0 0x14167ec60,
//   get 0x14167f020). Size 0x40: StateNurturing/StateTreeWatering put ICastingEventListener at +0x40.
// - Slot types from the base bodies' register homing and from every override's homing / stack-arg reads
//   (work/sb2/slotsig.py, stackargs.py): see the per-slot comments.
#pragma once
#include <list>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>

class PCBase;
class MyPC;
class NiActorManager;
class NiFixedString;
class NiTextKeyMatch;
class NiControllerSequence;
class Unk_StateDataArg;   // StateData slots 1/2 / State slot 26 argument (StateObserverData writes a CStringA at +0x70)
class StateSyncObject;     // MS2Ptr<T> by value in slots 22/28 (dtor 0x140837140, ReleaseImpl 0x1408374b0)
class Unk_StateArg29;     // MS2Ptr<T> by value in slots 29/30 (dtor 0x1401bfde0, ICF-folded generic MS2Ptr dtor)

// 0x18. vftable: deleting dtor 0x1417c1e00 (dtor 0x1417c0b00), 0x1417c0b30, 0x1417c0b50 (both empty, one pointer
// arg). Derived: StateAutoInteractionData, StateBannerData (0x20), StateObserverData, ...
class StateData : public CPtred
{
public:
    StateData();                                 // 0x1417c0ac0 (w38)
    virtual ~StateData();                        // 0x1417c0b00
    virtual void vfunc_1(Unk_StateDataArg* p);   // 1 0x1417c0b30 (called from State slot 26)
    virtual void vfunc_2(Unk_StateDataArg* p);   // 2 0x1417c0b50
};
MS2_CHECK_SIZE(StateData, 0x18);

class State
{
public:
    State(PCBase* pOwner);                                  // 0x1417b7d30
    virtual ~State();                                       // 0  0x1417b7dc0 (??_G 0x1417ba930)
    virtual int vfunc_1() = 0;                              // 1  _purecall; state type id (SkillMagicControl: 0x41)
    virtual void vfunc_2(int n);                            // 2  0x1417b7e20: m_n10 = n
    virtual void vfunc_3(double fTime);                     // 3  0x1417b7e60 (empty; update tick)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417b7e80 (enter: m_spData.AssignRaw(pData);
                                                            //    overrides dynamic_cast<XxxData*>(pData))
    virtual void vfunc_5(int n);                            // 5  0x1417b7f50 (leave: m_spData = 0)
    virtual void vfunc_6();                                 // 6  0x1417b7f90
    virtual void vfunc_7(int n);                            // 7  0x1417b7fa0
    virtual void vfunc_8(double fTime);                     // 8  0x1417b7fb0
    virtual void vfunc_9(double fTime);                     // 9  0x1417b8070
    virtual void vfunc_10(float a, float b, float c, float d, int e);  // 10 0x1417b8090 (owner FUN_141670d80(d))
    // 11..13: the actor's NiActorManager callbacks forwarded to the state (same arg shapes as PCBase's;
    // StateSkill 0x1417e7660 reads pkSeq at arg 5, others read fEventTime at arg 6 with movss).
    virtual void AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);    // 11 0x1417b80d0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);    // 12 0x1417b80f0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);    // 13 0x1417b8110
    virtual int vfunc_14();                                 // 14 0x1417b8130: return m_n14
    virtual int vfunc_15();                                 // 15 0x1417b8150: 0 (SkillMagicControl: 1)
    virtual int vfunc_16();                                 // 16 0x1417b8160: 0
    virtual int vfunc_17();                                 // 17 0x1417b8170: 1
    virtual int vfunc_18();                                 // 18 0x1417b8190: 1
    virtual int vfunc_19();                                 // 19 0x1417b81b0: 1
    virtual int vfunc_20();                                 // 20 0x1417b81d0: 0 (StateTaxiCall etc.: 1)
    virtual void vfunc_21(int n);                           // 21 0x1417b81e0
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);         // 22 0x1417b81f0: 0 (by value: callee destroys)
    virtual void vfunc_23();                                // 23 0x1417b8220
    virtual void vfunc_24();                                // 24 0x1417b8230
    virtual bool vfunc_25(int n, void* p);                  // 25 0x1417b8240: if (n) vfunc_2(n); return true
    virtual void vfunc_26(Unk_StateDataArg* p);             // 26 0x1417b8280: if (StateData* d = vfunc_35())
                                                            //    d->vfunc_1(p) (ICF-shared with a CRichEditDoc COMDAT)
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417b82d0: null (MS2Ptr(int) 0x14167e100);
                                                            //    StateBanner 0x140b7f610: new StateBannerData
    virtual bool vfunc_28(MS2Ptr<StateSyncObject> p);        // 28 0x1417b8310: false
    virtual void vfunc_29(MS2Ptr<Unk_StateArg29> p);        // 29 0x1417b93b0
    virtual void vfunc_30(MS2Ptr<Unk_StateArg29> p);        // 30 0x1417b93e0
    virtual void vfunc_31(int n);                           // 31 0x1417b9410
    // @0x140ac07a0
    virtual bool vfunc_32() { return true; }                // 32 (inline, see above)
    // @0x140ac07b0
    virtual void vfunc_33(bool b) {}                        // 33 (inline, see above)
    virtual void vfunc_34();                                // 34 0x1417b9420
    virtual StateData* vfunc_35();                          // 35 0x1417b9430: m_spData.get()

    int FUN_1417b7e40();                                    // return m_n10
    void FUN_1417b9310();                                   // remove every id in m_ids, then clear it (dtor, slots 4/5)
    // w38 (stateemotionidle): non-virtual helpers, bodies unrecovered
    MyPC* FUN_1417b84b0();                                  // owner as MyPC (a Ridee's rider), via the class-id casts
    PCBase* FUN_1417b8370();                                // owner as PC (class id 0x6200003)
    void FUN_1417b92a0();                                   // FUN_1417b9310 + register the state's ids with the manager
    bool FUN_1417b9460();                                   // play the idle motion (owner slot 104/102)
    // w77 (state.cpp)
    int FUN_1417b8340();                                    // owner slot 108
    PCBase* FUN_1417b83a0();                                // owner as npc (FUN_1409ffc60)
    PCBase* FUN_1417b83d0();                                // the npc's pet / summon owner
    PCBase* FUN_1417b8480();                                // owner's mount (FUN_14096e110)
    int FUN_1417b8560();                                    // FUN_1417b84b0() != 0

    PCBase* m_pOwner;                  // +0x08
    int m_n10;                         // +0x10
    int m_n14;                         // +0x14 (ctor: 1)
    std::list<unsigned> m_ids;         // +0x18
    int m_n28;                         // +0x28
    MS2Ptr<StateData> m_spData;        // +0x30
};
MS2_CHECK_SIZE(State, 0x40);
MS2_CHECK_OFFSET(State, m_pOwner, 0x08);
MS2_CHECK_OFFSET(State, m_n10, 0x10);
MS2_CHECK_OFFSET(State, m_n14, 0x14);
MS2_CHECK_OFFSET(State, m_ids, 0x18);
MS2_CHECK_OFFSET(State, m_n28, 0x28);
MS2_CHECK_OFFSET(State, m_spData, 0x30);
