// animationcallbackmanager.h - AnimationCallbackManager (RTTI name), the bridge between Gamebryo's NiActorManager
// callbacks and the game objects that listen to them, plus the per-owner text-key table (Unk_AnimTable, owned by
// CAnimationManager at +0x20) and the global text-key listener CGlobalKeyTextCallback. Header name assumed; method
// names are invented from use (FUN_<va> where the role is unclear).
// Owning unit: client\ms2\animationcallbackmanager.cpp (0x140996b20-0x14099db10).
//
// Exe facts:
// - AnimationCallbackManager: TSingleton<AnimationCallbackManager> (own vftable 0x142e..., s_instance 0x143ab3be0) at +0,
//   CAtlMap<NiActorManager*, AniCallbackBridge*> at +8 (0x48 bytes), the "queue events" mode flag at +0x50 (0x58 bytes).
//   With the flag clear, SetCallback installs the owner directly on the NiActorManager; with it set, an AniCallbackBridge
//   is installed that queues the events (a CAtlList of Unk_BridgeEvent) and AnimationCallbackManager::FUN_14099bd80
//   replays them later.
// - NiActorManager of the exe is the engine header with the MS2 edits (pending sequence data map at +0x100, m_kCallbacks at
//   +0x120, see ms2actormanager.h).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiActorManager.h>
#include <NiFixedString.h>
#include <NiSequenceData.h>
#include <NiTextKeyExtraData.h>
#include <NiTPointerMap.h>
#include <NiTArray.h>
#include <egf/EntityID.h>
#include <egf/Entity.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class GameObject;
class AnimationCallbackManager;
class AniCallbackBridge;

// ---- TSingleton<AnimationCallbackManager> (own vftable; ctor 0x14099c240, dtor 0x14099c4f0, ??_G 0x14099c5e0) ----
template <class T> class TSingleton;
template <> class TSingleton<AnimationCallbackManager>
{
public:
    TSingleton();                                                       // 0x14099c240 (inline, animationcallbackmanager.cpp)
    virtual ~TSingleton() { s_instance = 0; }                           // 0x14099c4f0
    static AnimationCallbackManager* s_instance;                        // 0x143ab3be0
    // @0x1409995c0
    static AnimationCallbackManager* GetInstance() { return s_instance; }
};

// ---- one text-key group of an animation: the free texts the sequence's keys registered ----
// RTTI CAnimationCallbackItem, 0x40 bytes, CPtred (0x18) + CAtlArray<CString> at +0x18 + the height at +0x38.
class CAnimationCallbackItem : public CPtred
{
public:
    // @0x140998900
    CAnimationCallbackItem() : m_fHeight(0.0f) {}
    // @0x140998b00 (??_G 0x1409990f0)
    virtual ~CAnimationCallbackItem() {}

    ATL::CAtlArray<CString> m_texts;                                    // +0x18 key texts to register as TEXT_KEY_EVENT
    float m_fHeight;                                                    // +0x38 "HeightFromGround_<f>" (0 = unset)
    int m_pad_3c;
};
MS2_CHECK_SIZE(CAnimationCallbackItem, 0x40);
MS2_CHECK_OFFSET(CAnimationCallbackItem, m_texts, 0x18);
MS2_CHECK_OFFSET(CAnimationCallbackItem, m_fHeight, 0x38);

// ---- MS2 view of NiActorManager: a sequence lookup that also drains the pending sequence data map (+0x100) ----
// The exe's NiActorManager is the engine header with the MS2 edits (ms2actormanager.h pins the layout); callers cast the
// manager to this class to reach the MS2 lookup, which has no SDK equivalent (NiActorManager::GetSequenceData reads
// m_kSeqDataMap only).
class Unk_CbActorMgr : public NiActorManager
{
public:
    // Sequence data of eSequenceID; on first use it is moved from the pending map into the controller manager and
    // m_kSeqDataMap. 0 if the id is unknown.
    NiSequenceData* FUN_140999740(SequenceID eSequenceID);              // 0x140999740
};

// ---- a queued NiActorManager::CallbackObject event (0x30) ----
struct Unk_BridgeEvent
{
    // @0x14099c310
    Unk_BridgeEvent(int eKind, NiActorManager* pManager, NiActorManager::SequenceID eSequenceID,
                    const NiFixedString& kTextKey, const NiTextKeyMatch* pMatch, NiControllerSequence* pSeq,
                    float fEventTime)
        : m_pManager(pManager), m_eSequenceID(eSequenceID), m_kTextKey(kTextKey), m_pMatch(pMatch), m_pSequence(pSeq),
          m_fEventTime(fEventTime), m_eKind(eKind) {}
    // @0x14099c270
    Unk_BridgeEvent(const Unk_BridgeEvent& o)
        : m_pManager(o.m_pManager), m_eSequenceID(o.m_eSequenceID), m_kTextKey(o.m_kTextKey), m_pMatch(o.m_pMatch),
          m_pSequence(o.m_pSequence), m_fEventTime(o.m_fEventTime), m_eKind(o.m_eKind) {}

    NiActorManager* m_pManager;                                         // +0x00
    NiActorManager::SequenceID m_eSequenceID;                           // +0x08
    NiFixedString m_kTextKey;                                           // +0x10
    const NiTextKeyMatch* m_pMatch;                                     // +0x18
    NiControllerSequence* m_pSequence;                                  // +0x20
    float m_fEventTime;                                                 // +0x28
    int m_eKind;                                                        // +0x2c NiActorManager::EventType
};
MS2_CHECK_SIZE(Unk_BridgeEvent, 0x30);

// ---- queues the events of one NiActorManager and forwards them to the real listener later ----
// RTTI AniCallbackBridge, 0x40 bytes, NiActorManager::CallbackObject at +0 (vftable 0x142e..., 6 slots).
class AniCallbackBridge : public NiActorManager::CallbackObject
{
public:
    AniCallbackBridge(NiActorManager::CallbackObject* pTarget);         // 0x14099b290
    virtual ~AniCallbackBridge();                                       // 0x14099b2f0, ??_G 0x14099c620

    virtual void AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x14099b390
    virtual void AnimDeactivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x14099b4d0
    virtual void AnimCompleted(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x14099b620
    virtual void TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x14099b770
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x14099b8b0

    void FUN_14099b330(NiActorManager::CallbackObject* pObj);           // 0x14099b330 retarget (drops the queue)

public:
    MS2_LAYOUT_FRIEND;
    NiActorManager::CallbackObject* m_pTarget;                          // +0x08
    ATL::CAtlList<Unk_BridgeEvent> m_queue;                             // +0x10 (block size 10)
};
MS2_CHECK_SIZE(AniCallbackBridge, 0x40);
MS2_CHECK_OFFSET(AniCallbackBridge, m_pTarget, 0x08);
MS2_CHECK_OFFSET(AniCallbackBridge, m_queue, 0x10);

// ---- the singleton ----
class AnimationCallbackManager : public TSingleton<AnimationCallbackManager>
{
public:
    typedef ATL::CAtlMap<NiActorManager*, AniCallbackBridge*> BridgeMap;

    AnimationCallbackManager();                                         // 0x14099ba00
    virtual ~AnimationCallbackManager();                                // 0x14099ba80, ??_G 0x14099c660

    // Installs pCb as the listener of pMgr (through a queueing bridge when m_nQueue is set); pCb == 0 removes it.
    void FUN_14099bb80(NiActorManager* pMgr, NiActorManager::CallbackObject* pCb);   // 0x14099bb80
    void FUN_14099bd80();                                               // 0x14099bd80 replay every queued event
    void FUN_14099c030();                                               // 0x14099c030 delete all bridges
    // @0x14099d0d0
    int GetQueueMode() { return m_nQueue; }
    // @0x1414fe550 (COMDAT emitted in ms2scenegraphservice.cpp)
    void SetQueueMode(int nQueue) { m_nQueue = nQueue; }

public:
    MS2_LAYOUT_FRIEND;
    BridgeMap m_bridges;                                                // +0x08
    int m_nQueue;                                                       // +0x50
};
MS2_CHECK_SIZE(AnimationCallbackManager, 0x58);
MS2_CHECK_OFFSET(AnimationCallbackManager, m_bridges, 0x08);
MS2_CHECK_OFFSET(AnimationCallbackManager, m_nQueue, 0x50);

// ---- per-owner text-key table (CAnimationManager +0x20) ----
struct Unk_AnimTable
{
    typedef MS2Ptr<CAnimationCallbackItem> ItemPtr;
    typedef ATL::CAtlMap<CString, ItemPtr, ATL::CStringElementTraits<CString> > ItemMap;

    Unk_AnimTable();                                                    // 0x140996b20
    ~Unk_AnimTable();                                                   // 0x140996b80

    // Binds the owner's actor manager (all callbacks go to the owner) and registers its text keys.
    bool FUN_140996bc0(GameObject* pObj);                               // 0x140996bc0
    // Same for the single sequence named strName.
    bool FUN_140997070(GameObject* pObj, CString strName);              // 0x140997070
    // Unbinds the owner.
    void FUN_1409975a0(GameObject* pObj);                               // 0x1409975a0
    // Height-from-ground of the sequence (0 if none).
    float FUN_140997650(CString strName);                               // 0x140997650
    bool FUN_140997710(CString strName);                                // 0x140997710 make sure the item exists
    bool FUN_1409977f0(CString strName, CString strText);              // 0x1409977f0 add a text to the item
    bool FUN_140997990(ItemPtr spItem, CString strText);                // 0x140997990

    ItemMap m_items;                                                    // +0x00
    NiActorManager* m_pActor;                                           // +0x48 the bound actor manager
};
MS2_CHECK_SIZE(Unk_AnimTable, 0x50);
MS2_CHECK_OFFSET(Unk_AnimTable, m_pActor, 0x48);

// ---- the global text-key listener (embedded in WorldService at +0x3e8) ----
// Handles "bgEffect_<name>" text keys of any actor: plays the background effect. 8 bytes (vftable only); ctor/dtor are
// in worldservice.
class CGlobalKeyTextCallback : public NiActorManager::CallbackObject
{
public:
    CGlobalKeyTextCallback();

    virtual void AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x140997f20
    virtual void AnimDeactivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x140997f40
    virtual void AnimCompleted(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x140997f60
    virtual void TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x140997f80
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                 // 0x140998180

    // Registers the entity's actor with this listener (callee releases pEntity).
    void FUN_140997ec0(egf::EntityPtr pEntity);                         // 0x140997ec0
};
MS2_CHECK_SIZE(CGlobalKeyTextCallback, 0x08);
