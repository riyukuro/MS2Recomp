// statemanager.h - CStateManager (the per-actor state machine, PCBase +0x140), the actor states it creates itself
// (StateNone, StatePush, StateRegen, StateRide, StateRope, StateMoveSkill) and CStateService (efd system service,
// class id 0x06100007, "StateService"), which owns the client's scene states (CSceneStateBase subclasses).
// Names are invented from their use; header name assumed from the unit client\ms2\statemanager.cpp
// (0x1417da7a0-0x1417e47d0 .text$mn, 0x140103470-0x140103f20 .text$di).
//   state ids used here: 0 none, 1 idle, 2 (slot 36/37 owner), 4 push, 0xd, 0x10, 0x12, 0x1b, 0x1c, 0x1e, 0x41, 0x46 ...
//   state type ids (vfunc_1): StateNone 0x00, StateRegen 0x09, StatePush 0x29 (see the cpp)
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <efd/ISystemService.h>
#include <efd/Point3.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/timer.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/partybits.h"
#include "ms2/client/ms2/scenestatebase.h"

class PCBase;
class StateData;
class CInPacket;
class COutPacket;
class COutputStream;

// A queued state request (the record PCBase/the network feed the state machine): CPtred-derived, held in MS2Ptr<>.
// RTTI StateSyncObject (defined in ?\statesyncobject.cpp, subclasses in commonfiles/statesyncobject.h). The exe object
// is 0xb8: its last field (void* +0xb0, not set by the ctor) is left out here because ?\state.cpp's local subclasses pad it.
// Fields proven from CStateManager::FUN_1417db550 (applies one request to the actor) and the packet coders.
class Unk_StateArg22 : public CPtred
{
public:
    explicit Unk_StateArg22(int nState);        // 0x140835210
    virtual ~Unk_StateArg22();                  // 0x1408353e0
    virtual void vfunc_1(COutputStream& kOut);  // write
    virtual void vfunc_2(CInPacket& kIn);       // read
    void FUN_1408356c0(COutPacket& packet);     // write the request
    void FUN_1408356f0(CInPacket& packet);      // read the request (scenestategame 0x1417127b0)
    void FUN_140835720(COutputStream& kOut);
    void FUN_140836250(COutputStream& kOut);    // packs the direction flags, then writes
    void FUN_140836540(CInPacket& kIn);
    void FUN_1408365a0(COutputStream& kOut);
    void FUN_1408365d0(CInPacket& kIn);         // reads, then unpacks the direction flags

    int m_nState;                       // +0x18 state id
    int m_nSub;                         // +0x1c sub state id
    efd::Point3 m_pos20;                // +0x20 position
    efd::Point3 m_dir2c;                // +0x2c direction
    unsigned char m_nDirFlags;          // +0x38 m_vel3c x/y packed as -1/0/1 (bits 0-1, 2-3), 0x80 = sent as floats
    efd::Point3 m_vel3c;                // +0x3c velocity (actor slot 22)
    efd::Point3 m_pos48;                // +0x48
    int m_n54;                          // +0x54
    float m_f58;                        // +0x58 (PCBase +0x934)
    float m_fTime;                      // +0x5c remaining time of the request
    Unk_PartyBits m_optional;           // +0x60 which of the optional fields below are sent
    int m_n64;                          // +0x64 (bit 0)
    int m_n68;                          // +0x68 (bit 1)
    unsigned short m_n6c;               // +0x6c (bit 2)
    CStringA m_str70;                   // +0x70 (bit 3)
    efd::Point3 m_pos78;                // +0x78 (bit 4)
    CStringA m_str88;                   // +0x88 object name (bit 4)
    int m_n90;                          // +0x90 (bit 5)
    CStringA m_str98;                   // +0x98 (bit 5)
    int m_nA0;                          // +0xa0 (0x7fffffff = unset)
    float m_fA4;                        // +0xa4
    int m_nA8;                          // +0xa8 already-fired flag
    int m_nAC;                          // +0xac server tick (Ridee::FUN_141706650)
};
MS2_CHECK_SIZE(Unk_StateArg22, 0xb0);
MS2_CHECK_OFFSET(Unk_StateArg22, m_optional, 0x60);
MS2_CHECK_OFFSET(Unk_StateArg22, m_str70, 0x70);
MS2_CHECK_OFFSET(Unk_StateArg22, m_str98, 0x98);
MS2_CHECK_OFFSET(Unk_StateArg22, m_nState, 0x18);
MS2_CHECK_OFFSET(Unk_StateArg22, m_pos20, 0x20);
MS2_CHECK_OFFSET(Unk_StateArg22, m_vel3c, 0x3c);
MS2_CHECK_OFFSET(Unk_StateArg22, m_fTime, 0x5c);
MS2_CHECK_OFFSET(Unk_StateArg22, m_pos78, 0x78);
MS2_CHECK_OFFSET(Unk_StateArg22, m_str88, 0x88);
MS2_CHECK_OFFSET(Unk_StateArg22, m_nA8, 0xa8);
MS2_CHECK_OFFSET(Unk_StateArg22, m_fA4, 0xa4);

// The owner state whose slots 36/37 CStateManager::FUN_1417daaa0 drives (state id 2).
class Unk_SMStateSlots : public State
{
public:
    virtual void vfunc_36(int n);       // 36 +0x120
    virtual int vfunc_37();             // 37 +0x128
};

// 0x98. vftable: the scalar deleting destructor only.
// ATL::CElementTraits<int> with its Hash / CompareElements spelled out: the exe keeps its own copies of the two (the
// state map's functions are not shared with the other CAtlMap<int, ...> instantiations).
struct Unk_SMKeyTraits : public ATL::CDefaultElementTraits<int>
{
    static ULONG Hash(const int& element) throw() { return (ULONG(ULONG_PTR(element))); }
    static bool CompareElements(const int& element1, const int& element2) { return ((element1 == element2) != 0); }
};

// CRBMap<unsigned> traits with the ordering function spelled out locally (the exe's copy at 0x140212de0 is not the one
// the other CRBMap<unsigned, ...> units share).
struct Unk_SMSceneTraits : public ATL::CElementTraits<unsigned>
{
    static int CompareElementsOrdered(const unsigned& a, const unsigned& b) { return (a < b) ? -1 : ((a > b) ? 1 : 0); }
};

class CStateManager : public CPtred
{
public:
    CStateManager(PCBase* pOwner);                                  // 0x1417da7a0
    virtual ~CStateManager();                                       // 0x1417da950 (??_G 0x1417dd510)

    void FUN_1417daa70();                                           // drop every queued request
    void FUN_1417daaa0(double fTime);                               // per-frame update
    void FUN_1417daeb0(int nId, State* pState);                     // AddState (asserts nId == pState->vfunc_1())
    void FUN_1417dafa0(int nState, StateData* pData, int nSub, int bForce);   // change state
    State* FUN_1417db1c0();                                         // current state
    State* FUN_1417db1e0(int nId);                                  // state by id, or NULL
    void FUN_1417db230(int nValue);                                 // current state slot 2
    int FUN_1417db270();                                            // current state id
    int FUN_1417db290();                                            // current state's m_n10
    int FUN_1417db2c0();                                            // previous state id
    void FUN_1417db2e0(Unk_StateArg22* pReq);                       // queue a request
    void FUN_1417db550(Unk_StateArg22* pReq);                       // apply a request to the actor
    void FUN_1417dbd00(PCBase* pActor, Unk_StateArg22* pReq);       // snap the actor to the request position
    void FUN_1417dbef0(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
        float fEventTime);                                          // forward to the current state, slot 11
    void FUN_1417dbf50(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
        const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime);   // slot 12
    void FUN_1417dbfc0(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
        float fEventTime);                                          // slot 13
    void FUN_1417dc020(int n);                                      // slot 31
    bool FUN_1417dc070(int nState);                                 // the state allows a position correction
    void FUN_1417dc110();                                           // flush the request queue
    MS2Ptr<Unk_StateArg22> FUN_1417dc230(float* pDelta);            // next due request
    void FUN_1417dc4c0(Unk_StateArg22* pReq);                       // apply a request's non-state parts
    MS2Ptr<StateData> FUN_1417dc9a0(int nState);                    // the state's pending data

    int m_nPrev;                                                    // +0x18 previous state id
    int m_nCur;                                                     // +0x1c current state id
    State* m_pState;                                                // +0x20 current state
    PCBase* m_pOwner;                                               // +0x28
    ATL::CAtlMap<int, State*, Unk_SMKeyTraits> m_states;                             // +0x30 id -> state
    std::list<MS2Ptr<Unk_StateArg22> > m_requests;                  // +0x78 queued requests
    efd::Point3 m_pos;                                              // +0x88 last synced position
    int m_pad_94;
};
MS2_CHECK_SIZE(CStateManager, 0x98);
MS2_CHECK_OFFSET(CStateManager, m_nPrev, 0x18);
MS2_CHECK_OFFSET(CStateManager, m_pState, 0x20);
MS2_CHECK_OFFSET(CStateManager, m_pOwner, 0x28);
MS2_CHECK_OFFSET(CStateManager, m_states, 0x30);
MS2_CHECK_OFFSET(CStateManager, m_requests, 0x78);
MS2_CHECK_OFFSET(CStateManager, m_pos, 0x88);

// ---- the actor states ----

// 8-byte millisecond poll timer (ctor 0x140517b00, arm 0x140268840, "interval elapsed" test 0x140268870 re-arms).
class Unk_140517b00
{
public:
    Unk_140517b00();
    void FUN_140268840();
    int FUN_140268870(int nInterval);
    unsigned m_nInterval;
    unsigned m_nLastTick;
};
// StateSkillData stand-in (id +0x18, level +0x1c). The exe's class is StateSkillData (RTTI .?AVStateSkillData@@).
class Unk_SMSkillData : public StateData
{
public:
    int m_nSkill;                                                   // +0x18
    short m_nLevel;                                                 // +0x1c
    short m_pad_1e;
};
// skill table row (int at +0x1c)
class Unk_SMSkillRec : public CPtred
{
public:
    char m_pad_18[4];
    int m_n1c;
};

// 0x78. Plays a move skill (abstract: vfunc_1 is _purecall in its vftable 0x142f716b0).
class StateMoveSkill : public State
{
public:
    StateMoveSkill(PCBase* pOwner);                                 // 0x1417df080
    virtual ~StateMoveSkill();                                      // 0x1417df130
    virtual void vfunc_4(StateData* pData);                         // 4  0x1417df180
    virtual void vfunc_5(int n);                                    // 5  0x1417df1f0
    virtual void vfunc_7(int n);                                    // 7  0x1417df280
    virtual int vfunc_15();                                         // 15 0x1417bef20 (ICF-folded body in another unit; symbols-manual)
    virtual MS2Ptr<StateData> vfunc_27();                           // 27 0x1417beea0 (ICF-folded body in another unit; symbols-manual)
    virtual void vfunc_8(double fTime);                             // 8  0x1417df2d0
    virtual int vfunc_36();                                         // 36 0x1417df480
    virtual int vfunc_37();                                         // 37 0x1417df4e0
    virtual bool vfunc_38(StateData* pData);                        // 38 0x1417df570

    void FUN_1417df370();                                           // go to the fallback state
    int FUN_1417df3c0();                                            // m_nMode
    int FUN_1417df3e0();                                            // skill id of the data (0 if none)
    long long FUN_1417df430();                                      // skill cooldown (0 if none)
    bool FUN_1417df6a0();                                           // keep-playing check

    int m_nMode;                                                    // +0x40 0 = slot 36 check, 1 = slot 37 check
    int m_n44;
    int m_nFallbackState;                                           // +0x48
    int m_nFallbackSub;                                             // +0x4c
    Unk_140517b00 m_tick;                                           // +0x50
    MS2Ptr<Unk_SMSkillData> m_spData;                               // +0x58
    MS2Ptr<Unk_SMSkillRec> m_spRec;                                 // +0x68
};
MS2_CHECK_SIZE(StateMoveSkill, 0x78);
MS2_CHECK_SIZE(Unk_140517b00, 8);
MS2_CHECK_OFFSET(StateMoveSkill, m_nMode, 0x40);
MS2_CHECK_OFFSET(StateMoveSkill, m_tick, 0x50);
MS2_CHECK_OFFSET(StateMoveSkill, m_spData, 0x58);
MS2_CHECK_OFFSET(StateMoveSkill, m_spRec, 0x68);

// 0x40. The idle placeholder state (id 0): sets the actor's base animation.
class StateNone : public State
{
public:
    StateNone(PCBase* pOwner);                                      // 0x1417df8b0
    virtual ~StateNone();                                           // 0x1417dfaf0
    virtual int vfunc_1();                                          // 1  0x1417dfb50
    virtual void vfunc_4(StateData* pData);                         // 4  0x1417df900
    virtual void vfunc_5(int n);                                    // 5  0x1417df9b0
    virtual bool vfunc_25(int n, void* p);                          // 25 0x1417dfa80
};
MS2_CHECK_SIZE(StateNone, 0x40);

// 0x40. Push state: plays the push animation.
class StatePush : public State
{
public:
    StatePush(PCBase* pOwner);                                      // 0x1417dfb60
    virtual ~StatePush();                                           // 0x1417dfbb0
    virtual int vfunc_1();                                          // 1  0x1417dfc60
    virtual void vfunc_4(StateData* pData);                         // 4  0x1417dfbe0
};
MS2_CHECK_SIZE(StatePush, 0x40);

// 0x88. Regen (respawn) state.
class StateRegen : public State
{
public:
    StateRegen(PCBase* pOwner);                                     // 0x1417dfc70
    virtual ~StateRegen();                                          // 0x1417dfd10
    virtual int vfunc_1();                                          // 1  0x1417e05a0
    virtual void vfunc_4(StateData* pData);                         // 4  0x1417dfd50
    virtual void vfunc_5(int n);                                    // 5  0x1417e0120
    virtual void vfunc_9(double fTime);                             // 9  0x1417e01d0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);             // 13 0x1417e04e0

    Timer m_timer;                                                  // +0x40 delay before the first animation
    int m_nStarted;                                                 // +0x78
    int m_nVariantB;                                                // +0x7c "Regen_B" is used
    int m_nSpecial;                                                 // +0x80
    int m_nSkip;                                                    // +0x84
};
MS2_CHECK_SIZE(StateRegen, 0x88);

// 0x40. Riding state.
class StateRide : public State
{
public:
    StateRide(PCBase* pOwner);                                      // 0x1417e05b0
    virtual ~StateRide();                                           // 0x1417e0600
    virtual int vfunc_1();                                          // 1  0x1417e0d20
    virtual void vfunc_4(StateData* pData);                         // 4  0x1417e0630
    virtual void vfunc_5(int n);                                    // 5  0x1417e06d0
    virtual void vfunc_8(double fTime);                             // 8  0x1417e0710
    virtual void vfunc_9(double fTime);                             // 9  0x1417e0780
};
MS2_CHECK_SIZE(StateRide, 0x40);

// 0x150. Rope climbing; m_nPhase is the State m_n10 (0x33 idle .. 0x39 fall).
class StateRope : public State
{
public:
    StateRope(PCBase* pOwner);                                      // 0x1417e0d30
    virtual ~StateRope();                                           // 0x1417e0e50
    virtual int vfunc_1();                                          // 1  0x1417e2450
    virtual void vfunc_3(double fTime);                             // 3  0x1417e1400
    virtual void vfunc_4(StateData* pData);                         // 4  0x1417e0ed0
    virtual void vfunc_5(int n);                                    // 5  0x1417e1330
    virtual void vfunc_8(double fTime);                             // 8  0x1417e18d0
    virtual void vfunc_9(double fTime);                             // 9  0x1417e1ba0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);             // 12 0x1417e1c70
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);             // 13 0x1417e1d00

    void FUN_1417e1df0(egf::Entity* pRope);                         // switch the rope entity
    float FUN_1417e1e60();                                          // climb step + ground / rope probes
    void FUN_1417e20d0(float fDz, float fAngle);                    // move the actor along the rope
    void FUN_1417e23c0();                                           // arm the grab timer

    egf::Entity* m_pRope;                                           // +0x40 rope entity
    efd::Point3 m_pos48;                                            // +0x48 start position
    efd::Point3 m_pos54;                                            // +0x54 rope top
    int m_n60;
    Timer m_timer68;                                                // +0x68 grab delay
    Timer m_timerA0;                                                // +0xa0 climb
    Timer m_timerD8;                                                // +0xd8 horizontal input
    Timer m_time110;                                                // +0x110 vertical input
    float m_fAngle;                                                 // +0x148 facing angle
    int m_pad_14c;
};
MS2_CHECK_SIZE(StateRope, 0x150);

// ---- CStateService ----

class CStateService;
template <class T> class TSingleton;
template <> class TSingleton<CStateService>
{
public:
    TSingleton();                                   // 0x1417e33a0 (inline, in the cpp)
    virtual ~TSingleton() { s_instance = 0; }       // 0x1417e34c0
    static CStateService* s_instance;               // 0x143ab89e8
    static CStateService* GetInstance() { return s_instance; }  // 0x140aa6d30 (first emitted by unit_140a93d00)
};

// 0x60, class id 0x06100007. TSingleton at +0, ISystemService at +8.
class CStateService : public TSingleton<CStateService>, public efd::ISystemService
{
    EE_DECLARE_CLASS1(CStateService, 0x06100007, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CStateService();                                // 0x1417e2460
    virtual ~CStateService();                       // 0x1417e2510
    virtual const char* GetDisplayName() const;     // 0x1417e2580
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1417e2a60
    virtual efd::AsyncResult OnInit();              // 0x1417e30c0
    virtual efd::AsyncResult OnTick();              // 0x1417e3160
    virtual efd::AsyncResult OnShutdown();          // 0x1417e3200

    int FUN_1417e25a0(int nScene);                  // switch to a scene state (0 = none)
    int FUN_1417e2610();                            // current scene id
    int FUN_1417e2670();                            // current scene slot 15
    efd::SmartPointer<CSceneStateBase> FUN_1417e26d0();       // copy of the current scene
    efd::SmartPointer<CSceneStateBase> FUN_1417e2720(unsigned nScene);   // scene by id
    void FUN_1417e27d0(CInPacket* pPacket);         // forward a packet to the current scene
    int FUN_1417e2830(int nScene);                  // the switch itself

    ATL::CRBMap<unsigned, efd::SmartPointer<CSceneStateBase>, Unk_SMSceneTraits> m_mapScenes;   // +0x28 scene id -> scene state
    efd::SmartPointer<CSceneStateBase> m_spCurrent; // +0x58
};
MS2_CHECK_SIZE(CStateService, 0x60);
MS2_CHECK_OFFSET(CStateService, m_mapScenes, 0x28);
MS2_CHECK_OFFSET(CStateService, m_spCurrent, 0x58);
