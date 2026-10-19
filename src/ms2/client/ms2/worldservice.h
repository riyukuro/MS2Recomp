// worldservice.h - WorldService (RTTI .?AVWorldService@@), the game's field/world system service: loads the xblock world
// (urn:emergent-world:<name>), owns the field's entity/actor/prop bookkeeping and forwards field events to the scene
// state through IWorldServiceCallback. Shared header of the four sub-units ?\worldservice.cpp#1..#4 (owner: w3o2).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); NOT an original header (the exe has no __FILE__ for it).
//
// Proven facts (all from the exe):
// - bases (RTTI CHD of vftable 0x142ffeb98): efd::ISystemService +0x00, TSingleton<WorldService> +0x18,
//   IMessageListener +0x20. sizeof = 0xaf0 (the TSingleton thunk 0x141bf99b8 adjusts by -0x18 into the deleting dtor,
//   Ghidra prints it as this[-1].field_0xad8).
// - EE_DECLARE_CLASS1(WorldService, 0x06100002, efd::ISystemService) (class id in the ClassInfo setup 0x141c1cac0),
//   ClassInfo static 0x143af8360 (initializer 0x140120240), TSingleton<WorldService>::s_instance 0x143aaee10.
// - vftable 0x142ffeb98 (16 slots, same shape as CNetworkService):
//     0 DeleteThis 0x141bfb5b0, 1 IncRefCount 0x141c03190, 2 DecRefCount 0x141bfb570, 3 TypeCast 0x141bffe20,
//     4/5 TypeCast 0x141c1eab0/0x141c1ea60, 6 GetClassDesc 0x141bfe670, 7 GetClassID 0x1409f2f80 (efd, shared),
//     8 scalar deleting dtor 0x141bfaad0, 9 OnServiceRegistered 0x14209cf70 (efd), 10 OnPreInit() 0x14209cf50 (efd),
//     11 OnPreInit(IDependencyRegistrar*) 0x141bcb2a0, 12 OnInit 0x141bcb370, 13 OnTick 0x141bcb830,
//     14 OnShutdown 0x141bcd5a0, 15 GetDisplayName 0x141bbae20.
//   vftable 0x142ffec20 (TSingleton part): { 0x141bf99b8 = thunk to the deleting dtor }.
//   vftable 0x142ffec30 (IMessageListener part): { 0x141bc8230 = OnMessage }.
//   Slots 0-6 and the deleting dtor lie past 0x141bf7060: the CU's COMDAT tail runs on to about 0x141c30000 (beyond
//   units.tsv's ?\worldservice.cpp range); see NOTES.md "w3o2".
// - Member offsets and constructors: ctor 0x141bb9720, dtor 0x141bba870 (member dtors in reverse order). Each member
//   below lists its ctor / dtor COMDAT. Offsets/sizes are checked below (MS2_CHECK_SIZE/OFFSET); container kinds, key
//   types and element sizes are proven from node sizes and traits COMDATs; pointee types (Unk_WsP8/P16/PodN) and the
//   remaining "TYPE?" members are not. A #2-#4 worker who proves one may replace that member's type here (same size;
//   say so in the commit), but never an offset, a size or the virtual slot list.
// - For #2-#4: write methods as `WorldService::FUN_<va>` members (declare them in the methods block below; undefined
//   FUN_<va> members/functions auto-bind to the exe at DLL link). Until a container's element type is proven, touch it
//   only through the exe's COMDATs by VA (`FUN_141bffee0(&m_350)` etc., declared as free functions taking void*),
//   never through the C++ container API on an Unk_Ws* stand-in -- except m_048 (std::set<void*>, exact).
//   Handlers take (const Msg*, efd::Category targetChannel) with the Category by value (callee destroys it).
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <afx.h>
#include <atlcoll.h>
#include <atlcomcli.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <efd/ISystemService.h>
#include <efd/Category.h>
#include <efd/SmartPointer.h>
#include <egf/EntityManager.h>
#include <egf/Scheduler.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"                // MS2Ptr<T> (16-byte game smart pointer)
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/nipoint3.h"           // Unk_StreamPoint (NiPoint3 / efd::Point3)

class WorldService;
template <class T> class TSingleton;
template <> class TSingleton<WorldService>
{
public:
    TSingleton();                                       // 0x141bf1a00 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }           // 0x141bf56f0
    static WorldService* GetInstance() { return s_instance; }   // 0x1403ed2d0 (COMDAT of gameevent.cpp)
    static WorldService* s_instance;                    // 0x143aaee10
};

namespace efd { class ServiceManager; class MessageService; class AssetLoadResponse; }
namespace egf { class FlatModelFactoryResponse; class EntityLoadResult; class EntityChangeMessage; class Entity; }
class NiNode;
namespace ecrPhysX { class PhysXPropMessage; }
namespace egmAnimation { class ActorAddedMessage; class ActorRemovedMessage; }
namespace ecr { class SceneGraphAddedMessage; class SceneGraphRemovedMessage; }
#include "animationcallbackmanager.h"   // CGlobalKeyTextCallback
class GameObject;                                       // gameobject.h (forward decl for the worldservice_mem_*.inc members)
class Unk_WsE_FieldObject;                               // worldservice_mem_E.inc (FUN_141bc1720 parameter; defined in the E part)
// Polymorphic helper owned by pointer (deleted in OnShutdown through the vtable slot 1 = scalar deleting dtor; slot 0 unknown).
class Unk_WsDeletable { public: virtual void Unk_Slot0(); virtual ~Unk_WsDeletable(); };
class TextureLayerManager;                              // NiObject subclass (0x20 bytes, ctor 0x141bf48f0 COMDAT)
class ChaosLightEffectLayerManager;                     // 0x28 bytes
class CWireframeManager;                                // 0x48 bytes

// Gamebryo NiPointer<T> stand-in (8 bytes). The real NiPointer is in CoreRuntime (not on the game include path); the
// per-T COMDATs (e.g. ctor 0x141bf1020, dtor 0x141bf54e0, operator= 0x141bf6ad0 for m_340) all have this shape.
void FUN_140980460(void* obj);                          // NiRefObject::IncRefCount
void FUN_1405a93d0(void* obj);                          // NiRefObject::DecRefCount
template <class T> class Unk_WsNiPtr
{
public:
    Unk_WsNiPtr(T* p = 0) : m_p(p) { if (m_p) FUN_140980460(m_p); }
    ~Unk_WsNiPtr() { if (m_p) FUN_1405a93d0(m_p); }
    Unk_WsNiPtr& operator=(T* p)
    {
        if (m_p != p) { if (m_p) FUN_1405a93d0(m_p); m_p = p; if (m_p) FUN_140980460(m_p); }
        return *this;
    }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    operator T*() const { return m_p; }
    T* m_p;
};

// boost::optional<T>-like (8 bytes for float: bool at +0, value at +4; the get() COMDAT 0x1410a71d0 asserts at line 0x55).
template <class T> struct Unk_WsOptional
{
    Unk_WsOptional() : m_init(false) {}                 // 0x141bf0e70
    void reset() { m_init = false; }                    // 0x141c2ed00
    Unk_WsOptional& operator=(const T& v) { m_value = v; m_init = true; return *this; }   // 0x141bf68b0
    bool operator!() const { return !m_init; }          // 0x1417f6020
    T& get() { return m_value; }                        // 0x1410a71d0 (asserts m_init)
    bool m_init;
    T m_value;
};

// Container element stand-ins. Container KINDS, key types and element SIZES are proven from the COMDATs (node sizes,
// hash/compare traits; w3o2 + helper, 2026-10-15), so the node layouts match the exe; the pointee types T are not:
//   Unk_WsP8  = an 8-byte intrusive pointer (efd::SmartPointer<T> / NiPointer<T>, Release via vtable slot 2),
//   Unk_WsP16 = a 16-byte game pointer (MS2Ptr<T> / std::shared_ptr<T>-like; the m_208 one is made from a new-tag),
//   Unk_WsPodN = N bytes of unknown value. Their dtors do nothing (a functional ctor/dtor leaks references).
// Replace one with the real type when proven (same size only).
struct Unk_WsElem { void* p; };
struct Unk_WsP8 { void* p; };
struct Unk_WsP16 { void* p0; void* p1; };
struct Unk_WsPod8 { unsigned char raw[8]; };
struct Unk_WsPod16 { unsigned char raw[16]; };
struct Unk_WsPod24 { unsigned char raw[24]; };
struct Unk_WsPod32 { unsigned char raw[32]; };
// Per-member value stand-ins: every container member of the exe instantiates its own template family (distinct ctor/dtor
// COMDATs per member, see the VAs in the member comments), so each gets its own type of the proven size. Replace one
// with the real class when proven (same size only).
struct Unk_WsV058 { void* p; };
struct Unk_WsV0b8 { void* p; };
struct Unk_WsV0e8 { void* p; };
struct Unk_WsV118 { GameObject* p; };                     // an 8-byte intrusive pointer to the world object (player/npc/monster/pet; slot 2 = Release)
struct Unk_WsV148 { void* p; };
struct Unk_WsV1a8 { void* m_obj; unsigned __int64 m_id; };      // proven by OnTick (G): {GameObject*, entity id}
struct Unk_WsV1d8                                      // proven by FUN_141bbfe30 (helper A): a tracked scene-graph entity
{
    void* m_sceneNode;                                  // +0x00
    int m_state;                                        // +0x08
    int m_pad_0c;
    unsigned __int64 m_entityId;                        // +0x10
    int m_group;                                        // +0x18 (key of m_1e8)
    int m_pad_1c;
};
struct Unk_WsV1f8 { unsigned char raw[16]; };
struct Unk_WsV208 { void* p0; void* p1; };
struct Unk_WsV2e8 { void* p; };
struct Unk_WsV2f8 { void* p0; void* p1; };
struct Unk_WsV350 { void* p0; void* p1; };
struct Unk_WsV3a0 { void* p0; void* p1; };
struct Unk_WsV420 { void* p0; void* p1; };
struct Unk_WsV468 { void* p0; void* p1; };
struct Unk_WsV4b0 { void* p0; void* p1; };
struct Unk_WsV4e0 { void* p0; void* p1; };
struct Unk_WsV510 { void* p0; void* p1; };
struct Unk_WsV540 { void* p0; void* p1; };
struct Unk_WsV570 { void* p0; void* p1; };
struct Unk_WsV5a0 { void* p; };
struct Unk_WsV5e8 { void* p; };
struct Unk_WsV678 { void* p0; void* p1; };
struct Unk_WsV6a8 { void* p0; void* p1; };
struct Unk_WsV6d8 { void* p; };                                  // an egf::Entity* (OnTick, G)
struct Unk_WsV708 { void* p0; void* p1; };
struct Unk_WsV738 { void* p; };
struct Unk_WsV780 { void* p0; void* p1; };
struct Unk_WsV7c8 { void* p; };
struct Unk_WsV848 { void* p0; void* p1; };
struct Unk_WsV930 { void* p0; void* p1; };
struct Unk_WsV980 { void* p; };                                  // intrusive pointer to a ticking task (OnTick, G)
struct Unk_WsV990 { void* p; };                                  // intrusive pointer to a ticking task (OnTick, G)
struct Unk_WsV9a0 { void* p0; void* p1; };                      // p1 = an actor-like object (OnTick, G)
class Unk_WsK_Rank : public CPtred {};                          // rank record shown by the interact display image (refcounted)
template <> void MS2Ptr<Unk_WsK_Rank>::ReleaseImpl(void*);   // explicit specialization lives in unit_141bb15d0
// queued (name, text) / (name, rank) entries: the exe's vector elements are plain std::pair instantiations
struct Unk_WsVa00 : std::pair<CStringA, CStringW> {};
struct Unk_WsVa18 : std::pair<CStringA, MS2Ptr<Unk_WsK_Rank> > {};
struct Unk_WsVab0 { __int64 m_expireTick; };
struct Unk_WsVac0 { void* p; };
struct Unk_WsVad0 { void* p0; void* p1; };
// Target of the MS2Ptr members (some CPtred subclass; TYPE? per member).
class Unk_WsPtred : public CPtred {};
class Unk_WsPtred298 : public CPtred       // one class per MS2Ptr member (distinct ctor/dtor COMDATs in the exe)
{
public:                                        // the local player (fields as accessed by WorldService; helper C)
    unsigned char m_pad18[0x5c - 0x18];
    int m_5c;                                  // 0: the map needs the housing service's check before a guild-house move (CGuildManager::FUN_1413ba4b0)
    unsigned char m_pad60[0x1c8 - 0x60];
    int m_1c8;                                 // passed to a manager setter by FUN_141bcda90
    unsigned char m_pad1cc[0x1e4 - 0x1cc];
    int m_1e4;                                 // ditto
    unsigned char m_pad1e8[0x1f0 - 0x1e8];
    char m_1f0;
    unsigned char m_pad1f1[3];
    float m_1f4;                               // base value of a speed/range scale (FUN_141bcfc50)
    unsigned char m_pad1f8[0x23c - 0x1f8];
    float m_23c;                               // camera distance (exe 0x141bbbdde movss xmm1)
    unsigned char m_pad240[0x24c - 0x240];
    char m_24c;                                // flag tested at the end of FUN_141bcda90
    unsigned char m_pad24d[0x254 - 0x24d];
    int m_254;                                 // passed to FUN_1416105a0
    int m_258;
};
class Unk_WsPtreda80 : public CPtred {};
class Unk_WsPtredaa0 : public CPtred {};

class WorldService : public efd::ISystemService, public TSingleton<WorldService>, public IMessageListener
{
    EE_DECLARE_CLASS1(WorldService, 0x06100002, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
    MS2_LAYOUT_FRIEND;
public:
    WorldService();                                     // 0x141bb9720
    virtual ~WorldService();                            // 0x141bba870
    const char* GetDisplayName() const override;        // 0x141bbae20
    efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar) override;   // 0x141bcb2a0
    efd::AsyncResult OnInit() override;                 // 0x141bcb370
    efd::AsyncResult OnTick() override;                 // 0x141bcb830
    efd::AsyncResult OnShutdown() override;             // 0x141bcd5a0
    int OnMessage(UISwfEntity* pSender, UIMsg* pMsg) override;   // 0x141bc8230 (IMessageListener, this = +0x20)

    static WorldService* GetInstance() { return TSingleton<WorldService>::s_instance; }

    // ---- non-virtual methods (Ghidra names; rename freely when proven, the hook binds by VA) ----
    void FUN_141bbae40(void* p);                        // m_048.insert(p)
    void FUN_141bbae80(void* p);                        // m_048.erase(p) if present
    int FUN_141bc32b0();                                // return m_398
    void FUN_141bc1640();                               // m_148 COMDAT 0x141bfe6b0
    void FUN_141bc1670();                               // m_118 COMDAT 0x141bfe6c0
    void FUN_141bc16a0();                               // m_348 COMDAT 0x141bf7c40
    void FUN_141bc6f60(int a804, int a800, int a808);
    void FUN_141bc70f0();                               // empty
    void FUN_141bc72f0();
    void FUN_141bc73e0(bool b);                         // m_91c = b; FUN_141bc72f0()
    bool FUN_141bc7420();                               // return m_91c
    void FUN_141bc7910();                               // empty
    int FUN_141bc9a80();                                // return m_928
    void* FUN_141bc9fb0();                              // return &m_930
    void FUN_141bca220();                               // m_2bc = 1
    void FUN_141bcad60(void* p, int n);                 // m_2c8 = p, m_2d0 = n
    int FUN_141bcaf60();                                // return m_2d0
    void* FUN_141bcaf80();                              // return m_2c8
    void FUN_141bbbd70();                               // FUN_1409a49b0(FUN_1409a8b00())
    void FUN_141bbbda0();
    void FUN_141bbbe00();
    void FUN_141bbc4e0();
    void FUN_141bd3c00(bool b);                         // (unrecovered, #1)
    void FUN_141bd5ea0(void* pActor);                   // (unrecovered, #1)
    // message handlers (EE_HANDLER statics in the .di, see worldservice_1.cpp); Category by value (callee destroys)
    void FUN_141bbd640(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);        // EE_HANDLER_WRAP id 8253
    void FUN_141bbf2f0(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);        // EE_HANDLER_WRAP id 8254
    void FUN_141bbfa50(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);        // EE_HANDLER_WRAP id 8196
    void FUN_141bbfb50(const egmAnimation::ActorAddedMessage* pMsg, efd::Category targetChannel);
    void FUN_141bbfe30(const ecr::SceneGraphAddedMessage* pMsg, efd::Category targetChannel);
    void FUN_141bc0290(const ecr::SceneGraphRemovedMessage* pMsg, efd::Category targetChannel);
    void FUN_141bc0530(const ecrPhysX::PhysXPropMessage* pMsg, efd::Category targetChannel);      // EE_HANDLER_WRAP id 12299
    void FUN_141bc0a70(const egf::EntityLoadResult* pMsg, efd::Category targetChannel);
    void FUN_141bbf9f0(const efd::AssetLoadResponse* pMsg, efd::Category targetChannel);
    void FUN_141bbfde0(const egmAnimation::ActorRemovedMessage* pMsg, efd::Category targetChannel);
    void FUN_141bc0f50(const efd::AssetLoadResponse* pMsg, efd::Category targetChannel);
    efd::SmartPointer<egf::EntityManager> FUN_141bc16d0();   // copy of m_268
    int FUN_141bc2b30();                                // sum of m_350 values' +0x188
    void FUN_141bc7440();
    void* FUN_141bc8070();                              // FUN_141bd3620()->vfunc(0x4a0) or 0
    void* FUN_141bd3620();                              // (unrecovered, #1)
    void FUN_141bc8fe0(unsigned __int64 key);           // m_468.RemoveKey
    void FUN_141bc9fd0(int key);                        // m_9d0.SetAt(key, 0)
    void FUN_141bca010();                               // re-arm the 0xa5 timer (m_a70/m_a74/m_a78)
    void FUN_141bca090();                               // timer expired -> send 0xa5(1)
    void FUN_141bca110(bool b);                         // send COutPacket 0xa5 { u8 b }
    void FUN_141bca170(int interval);                   // m_a70 = interval
    void FUN_141bca1e0();                               // m_2b8 = 1 ...
    void FUN_141bca240();
    void* FUN_141bd0cc0();                              // the local player: m_2d8's pointee, a MyPC (cast with static_cast<PC*>; fittingdollpc.h has PC with slots to 146)
    void FUN_141bcf9f0();                               // (unrecovered, #1)
    void FUN_141bcfad0();                               // (unrecovered, #1)
    void FUN_141bca390(unsigned key);                   // m_1a8.RemoveKey
    void FUN_141bca630();
    void FUN_141bc58d0(void* pOut);                     // copy m_510's pointers into *pOut
    void FUN_141bc5980(void* pOut);                     // copy m_540's pointers into *pOut
    void FUN_141bc5f10(void* pOut);                     // copy m_678's pointers into *pOut
    void FUN_141bc6a20(int n);                          // each m_678 value: vfunc 3(n), FUN_141bc6af0
    void FUN_141bc6af0(Unk_WsP16& sp);                  // (unrecovered, #1)
    void FUN_141bca6d0(void* pMsg);                     // dispatch on pMsg+8 vfunc 1 (0/1/2)
    void FUN_141bca770(void* pMsg);                     // (unrecovered, #1)
    void FUN_141bca8c0(void* pMsg);                     // (unrecovered, #1)
    void FUN_141bca9b0(void* pMsg);                     // (unrecovered, #1)
    int FUN_141bcfbd0();                                // m_state == 4 && m_2b4 != 0
    // per-part member declaration files (ws4 workers; folded into this header when the unit is finished)
    // ---- helper A (0x141bbaf00 .. 0x141bc3fff) ----
    int FUN_141bbaf00(GameObject* obj, const unsigned __int64& id, bool bNewlyAdded);   // register a created object's entity
    int FUN_141bbb1e0(GameObject* obj, int bFullInit, unsigned cameraArg);   // OnObjectCreated: register in the object maps
    void FUN_141bbb7f0(GameObject* obj, int bImmediate);                         // OnObjectDestroyed: unregister from the object maps
    void FUN_141bbbc60(const unsigned __int64& id, int bImmediate);              // destroy the object registered under entity id
    void FUN_141bbbcf0(unsigned objId, int bImmediate);                          // destroy the object registered under object id
    int FUN_141bbbe40(int mapId, int arg2, int arg3);                            // start loading map mapId
    int FUN_141bbc1d0(const char* urn, int arg2);                                // begin loading the xblock urn
    void FUN_141bbd490(egf::Entity* entity, void* sceneNode);                           // track a shadow-casting entity in m_2e8
    Unk_StreamPoint FUN_141bc0ff0(GameObject* obj, void* classIds, int skipId);        // unit push-away direction from nearby objects of the given class ids
    void FUN_141bc12b0();                                                              // take extra refs on the parts of every object of the active class filter
    void FUN_141bc2730();                                                              // clear the field-object registry (m_350) and destroy the entities in m_838
    Unk_WsP16* FUN_141bc2800(Unk_WsP16* out, int id);                                  // m_350.Lookup(field object id) -> *out (null when absent)
    Unk_WsP16* FUN_141bc2880(Unk_WsP16* out, int mapType);                             // first m_350 field object with this map type
    void FUN_141bc2980(void* outIds);                                                  // append every field object id to the CAtlArray<int>
    void FUN_141bc2a70(int type, void* outRefs);                                       // collect the field objects of this type into the CAtlArray of refs
    void FUN_141bc24e0(int id);                                                        // unregister field object id (entity lists, m_838, m_350, proxy)
    int FUN_141bc2bc0();                                                               // number of m_930 objects with a target
    int FUN_141bc2f40();                                                               // any field object of type 6?
    void FUN_141bc3000(int id, int enabled);                                           // set the field object's enabled property
    void FUN_141bc30a0(int id, int visible);                                           // set the field object's visible property
    void FUN_141bc3140(int id, int visible, int enabled, int hidden);                  // set the field object's visible / enabled / hidden properties
    void FUN_141bc31d0(int id, Unk_StreamPoint pos, Unk_StreamPoint scale);            // set the field object's position / scale
    bool FUN_141bc32d0(void* obj);                                                     // register obj (id at +0x40) in m_3a0; true if it was new
    void* FUN_141bc3360(int id);                                                       // m_3a0 lookup, or null
    void FUN_141bc33d0(int id);                                                        // unregister id from m_3a0 after removing its effects / sounds
    void FUN_141bc3470(const Unk_WsP16& value, const Unk_WsP16& key);                  // m_3f0.SetAt(key, value) when key is registrable (callee releases both)
    void FUN_141bc2c90(Unk_StreamPoint pt, void* outRefs);                             // field objects containing pt appended to the ref array, sorted nearest first
    // ws4 part B member declarations (0x141bc4000..0x141bcb2ff)
    void FUN_141bc49c0(); // 0x141bc49c0
    void FUN_141bc4b10(MS2Ptr<class Unk_WsB_Marker> marker); // 0x141bc4b10
    void FUN_141bc4bf0(CString name); // 0x141bc4bf0
    MS2Ptr<class Unk_WsB_Marker> FUN_141bc4ca0(const Unk_StreamPoint& pos, float maxDist, int type); // 0x141bc4ca0
    MS2Ptr<class Unk_WsB_Marker> FUN_141bc4e70(CString name); // 0x141bc4e70
    MS2Ptr<class Unk_WsB_Marker> FUN_141bc4f10(egf::Entity* entity); // 0x141bc4f10
    void FUN_141bc4fc0(float dt); // 0x141bc4fc0
    void FUN_141bc51d0(float dt); // 0x141bc51d0
    void FUN_141bc5420(class Unk_WsB_Packet* pkt); // 0x141bc5420
    void FUN_141bc5830(CString name); // 0x141bc5830
    MS2Ptr<class Unk_WsB_Lift> FUN_141bc5a20(CString name); // 0x141bc5a20
    void FUN_141bc5ab0(efd::SmartPointer<class Unk_WsB_RefObj> obj); // 0x141bc5ab0
    void FUN_141bc5b30(efd::SmartPointer<class Unk_WsB_RefObj> obj); // 0x141bc5b30
    efd::SmartPointer<class Unk_WsB_RefObj> FUN_141bc5bb0(unsigned __int64 key); // 0x141bc5bb0
    void FUN_141bc5c40(MS2Ptr<class Unk_WsB_Prop> prop); // 0x141bc5c40
    void FUN_141bc5d60(const CString& name); // 0x141bc5d60
    void FUN_141bc5e20(int category); // 0x141bc5e20
    void FUN_141bc5fb0(void* out, int category); // 0x141bc5fb0
    MS2Ptr<class Unk_WsB_Prop> FUN_141bc6090(const Unk_StreamPoint& pos, int skipDisabled); // 0x141bc6090
    MS2Ptr<class Unk_WsB_Prop> FUN_141bc62b0(const Unk_StreamPoint& pos, int category, int skipDisabled); // 0x141bc62b0
    MS2Ptr<class Unk_WsB_Prop> FUN_141bc6510(const Unk_StreamPoint& pos, int kind); // 0x141bc6510
    MS2Ptr<class Unk_WsB_Prop> FUN_141bc66b0(const CString& name); // 0x141bc66b0
    void FUN_141bc6760(const CString& name, int arg3, int category, int arg5); // 0x141bc6760
    void FUN_141bc6860(const CString& name, int arg3, int category); // 0x141bc6860
    void FUN_141bc6930(int kind, int arg); // 0x141bc6930
    efd::SmartPointer<class Unk_WsB_Spawn> FUN_141bc6c60(const Unk_StreamPoint& pos, int skipUnusable); // 0x141bc6c60
    efd::SmartPointer<class Unk_WsB_Spawn> FUN_141bc6eb0(const CString& name); // 0x141bc6eb0
    bool FUN_141bc6fb0(int* a, int* b, int* c, int* flag) const; // 0x141bc6fb0
    class FieldProperty* FUN_141bcab60(unsigned type); // 0x141bcab60
    bool FUN_141bc7920(std::set<void*>& visible); // 0x141bc7920
    bool FUN_141bc7aa0(int id, std::set<unsigned __int64>& out); // 0x141bc7aa0
    bool FUN_141bc7b20(const unsigned __int64& key); // 0x141bc7b20 (merge3: is `key` present in m_1d8; was mis-recovered as erase(iterator))
    void FUN_141bc7b80(int force); // 0x141bc7b80
    void FUN_141bc7d40(const unsigned __int64& key); // 0x141bc7d40
    void FUN_141bc7ec0(const unsigned __int64& key); // 0x141bc7ec0
    void FUN_141bc7f10(const unsigned __int64& key); // 0x141bc7f10
    void FUN_141bc7fe0(const unsigned __int64& key); // 0x141bc7fe0
    int FUN_141bc80c0(int channel); // 0x141bc80c0
    void FUN_141bc8e00(); // 0x141bc8e00
    void FUN_141bc8ef0(const unsigned __int64& key, MS2Ptr<class Unk_WsB_Vibrator> vibrator); // 0x141bc8ef0
    MS2Ptr<class Unk_WsB_Vibrator> FUN_141bc8f60(const unsigned __int64& key); // 0x141bc8f60
    // Height-index caller proves an ID value in r8; retained alias pending owner signature audit.
    MS2Ptr<class Unk_WsB_Vibrator> FUN_141bc8f60_value(unsigned __int64 key);
    void FUN_141bc9020(CString name, class Unk_WsB_ShakeRef shake, CString shakeName, bool flag); // 0x141bc9020
    void FUN_141bc92e0(CString name); // 0x141bc92e0
    void FUN_141bc9480(CString name); // 0x141bc9480
    void FUN_141bc9560(CString name, CString model, char mode); // 0x141bc9560
    bool FUN_141bc9830(int* id, CString& name, float maxDist); // 0x141bc9830
    void FUN_141bc9aa0(MS2Ptr<class Unk_WsB_Notice> notice); // 0x141bc9aa0
    void FUN_141bc9b30(unsigned id); // 0x141bc9b30
    MS2Ptr<class Unk_WsB_Notice> FUN_141bc9be0(unsigned id); // 0x141bc9be0
    MS2Ptr<class Unk_WsB_Notice> FUN_141bc9c60(void* owner); // 0x141bc9c60
    MS2Ptr<class Unk_WsB_Notice> FUN_141bc9d60(const CStringW& text); // 0x141bc9d60
    MS2Ptr<class Unk_WsB_Notice> FUN_141bc9e70(int kind); // 0x141bc9e70
    int FUN_141bca2e0(); // 0x141bca2e0
    int FUN_141bca3c0(float z); // 0x141bca3c0
    int FUN_141bca4f0(float* z); // 0x141bca4f0
    void FUN_141bcaa80(); // 0x141bcaa80
    void FUN_141bcabf0(); // 0x141bcabf0
    int FUN_141bcada0(__int64 id); // 0x141bcada0
    int FUN_141bcafa0(egf::Entity* entity); // 0x141bcafa0
    bool FUN_141bcb0a0(); // 0x141bcb0a0
    bool FUN_141bcb150(); // 0x141bcb150
    bool FUN_141bcb1a0(); // 0x141bcb1a0
    bool FUN_141bcb210(); // 0x141bcb210
    bool FUN_141bc8420(class Unk_WsB_Actor* actor, float dt, int* lifted, Unk_StreamPoint* velocity); // 0x141bc8420
    void FUN_141bc7100(class Unk_WsB_SceneObj* root); // 0x141bc7100
    void FUN_141bc7490(egf::Entity* entity, NiNode* root); // 0x141bc7490
    // ---- helper C (0x141bcb300-0x141bd2fff) ----
    void FUN_141bcd960();                               // 0xa5 timer helper: walk m_9d0 (requests), retire done ones
    void FUN_141bcf800(CString name);                   // callbacks vfunc_2(m_284, name)
    void FUN_141bcf8d0();                               // m_2b0 = 1; callbacks vfunc_4(m_288); retry m_258
    void FUN_141bcf9c0();                               // FUN_141bc5e20(this, 6)
    int FUN_141bcfb70();                                // service running && m_040 == 0
    int FUN_141bcfc10();                                // m_prevState == 4 && m_state == 6
    float FUN_141bcfc50();                              // scale from the local player
    int FUN_141bcfd10();                                // return m_state
    egf::Entity* FUN_141bcfd30(unsigned key, const Unk_StreamPoint& pos, float maxDist, int nearest, int flat);
    int FUN_141bcfff0(int id, struct Unk_WsC_NpcAnim* out);
    egf::Entity* FUN_141bd0220(const Unk_StreamPoint& pos, float maxDist);
    struct Unk_WsC_TagPtr FUN_141bd0420(unsigned key);
    egf::Entity* FUN_141bd04d0(unsigned key);
    egf::Entity* FUN_141bd0560(unsigned key, unsigned prop, float x, float y);
    egf::Entity* FUN_141bd08f0(unsigned key, unsigned prop, float x, float y, __int64 filter);
    void FUN_141bd0cf0(void* pPlayer);                  // m_2d8 = pPlayer
    CStringW FUN_141bd0d30();                           // m_2d8's name or ""
    int FUN_141bd0dd0(Unk_StreamPoint* pos, Unk_StreamPoint* dir);
    class Unk_WsC_GameObj* FUN_141bd0f50(class Unk_WsC_GameObj* p);
    class Unk_WsC_GameObj* FUN_141bd0fa0(const egf::EntityID& id);   // the game object of an entity
    class Unk_WsC_GameObj* FUN_141bd0fe0(unsigned __int64 key);
    class Unk_WsC_GameObj* FUN_141bd1050(void* mesh);
    class Unk_WsC_GameObj* FUN_141bd1180(int id);
    class Unk_WsC_GameObj* FUN_141bd1200(int id);
    class Unk_WsC_GameObj* FUN_141bd1290(int id);
    class Unk_WsC_GameObj* FUN_141bd1320(int id);
    class Unk_WsC_GameObj* FUN_141bd13a0(int id);
    class Unk_WsC_GameObj* FUN_141bd1420(CStringW name);
    class Unk_WsC_GameObj* FUN_141bd1530(__int64 id);
    class Unk_WsC_GameObj* FUN_141bd1640(__int64 id);
    void FUN_141bd1750(ATL::CAtlList<efd::SmartPointer<class Unk_WsC_GameObj> >* out);
    CStringW FUN_141bd1830(int id);
    __int64 FUN_141bd1980(int id);
    void FUN_141bd19d0(int id);
    int FUN_141bd1a10(class Unk_WsC_GameObj* obj);
    class Unk_WsC_GameObj* FUN_141bd1a50(class Unk_WsC_GameObj* self);
    class Unk_WsC_GameObj* FUN_141bd1d10(int a, int b);
    void FUN_141bd1ed0(std::list<class Unk_WsC_GameObj*>* outA, std::list<class Unk_WsC_GameObj*>* outB, int skipOwned, int a, int b);
    void FUN_141bd2030(std::list<class Unk_WsC_GameObj*>* out);
    class Unk_WsC_GameObj* FUN_141bd2170(int type, float range, int useFront, int addBonus);
    class Unk_WsC_GameObj* FUN_141bd2690(const Unk_StreamPoint& pos, float maxDist, float up, float down, int needHp, int includeDead);
    class Unk_WsC_GameObj* FUN_141bd28d0(const Unk_StreamPoint& pos, float maxDist, float up, float down, int needHp, class Unk_WsC_GameObj* exclude, int includeDead);
    class Unk_WsC_GameObj* FUN_141bd2bf0(const Unk_StreamPoint& pos, int id);   // pos unused (exe caller 0x14176b489)
    efd::SmartPointer<egf::Entity> FUN_141bd2cd0(CString name);
    void FUN_141bd2db0(ATL::CAtlList<efd::SmartPointer<class Unk_WsC_GameObj> >* out, int (*filter)(class Unk_WsC_GameObj*));
    void FUN_141bd2ea0(void* ctx, ATL::CAtlList<efd::SmartPointer<class Unk_WsC_GameObj> >* out, int a, int b, int (*filter)(void*, class Unk_WsC_GameObj*, int, int));
    void FUN_141bd2fa0();
    CString FUN_141bd2ff0();
    void FUN_141bcda90();                                           // field-load: scan tagged entities into the object maps, then notify services
    // ---- helper D (0x141bd3000-0x141bdbfff) ----
    int FUN_141bd3040();                                // return m_28c
    int FUN_141bd3060();                                // return m_284
    CStringW* FUN_141bd3080();                          // &m_290
    MS2Ptr<Unk_WsPtred298> FUN_141bd30a0();             // copy of m_298
    void FUN_141bd30f0(char b);                         // set shadow flag on every m_2e8 entity's scene graph + hw instancing
    Unk_WsP16* FUN_141bd3210(Unk_WsP16* out, Unk_StreamPoint pt);   // field object containing pt, else the nearest (m_2f8)
    Unk_WsP16* FUN_141bd3430(Unk_WsP16* out, unsigned __int64 key); // m_2f8 lookup
    TextureLayerManager* FUN_141bd3650();               // return m_spTextureLayerManager
    ChaosLightEffectLayerManager* FUN_141bd3680();      // return m_spChaosLightEffectLayerManager
    ATL::CRBMap<unsigned, Unk_WsV118>* FUN_141bd36b0(); // &m_118
    ATL::CRBMap<unsigned, Unk_WsV148>* FUN_141bd36d0(); // &m_148
    bool FUN_141bd36f0(Unk_StreamPoint pt, Unk_StreamPoint* pOut);   // offset of pt outside the world bounds into *pOut; true if inside
    Unk_StreamPoint FUN_141bd37e0();                    // m_boundsMin
    Unk_StreamPoint FUN_141bd3820();                    // m_boundsMax
    void FUN_141bd3860();                               // m_978 = 1
    void FUN_141bd3880();                               // each m_350 value: FUN_14169d0e0
    void FUN_141bd3920();                               // each m_540 / m_570 value: FUN_1414483e0
    void FUN_141bd3a40();                               // each m_510 value: FUN_141447de0
    void FUN_141bd3ae0();                               // each m_148 / m_930 value
    void FUN_141bd3cb0(bool b);                         // m_914 = b
    bool FUN_141bd3cd0();                               // return m_914
    void FUN_141bd3cf0(bool b);                         // m_915 = b
    bool FUN_141bd3d10();                               // return m_915
    int FUN_141bd3d50();                                // return m_918
    void FUN_141bd3d70(const Unk_StreamPoint& a, const Unk_StreamPoint& b);   // m_8d8 = a, m_8e4 = b
    Unk_StreamPoint FUN_141bd3dc0();                    // return m_8d8
    int FUN_141bd3e00();                                // player camera has the default 1100/45/30 values
    void FUN_141bd3ec0(int id, char b);                 // each m_148 object with this id: set its flag
    unsigned FUN_141bd3fe0(int id);                     // key of the m_148 entry whose object has this id
    float FUN_141bd4120();                              // player height offset + constant
    void FUN_141bd41d0();                               // each m_118 object: FUN_1411e6e70(sub-object)
    void FUN_141bd4260();                               // each m_118 object: FUN_1411ea320(sub-object)
    void FUN_141bd42f0(void* pMsg);                     // effect message: read effects into m_848 and apply
    void FUN_141bd4490(void* pMsg);                     // effect message: add one effect
    void FUN_141bd4670(void* pMsg);                     // effect message: remove one effect
    int FUN_141bd4700(const std::set<unsigned __int64>& ids, Unk_StreamPoint* pOutPos, float* pOutDist);   // nearest m_118 actor in ids
    int FUN_141bd49d0(const std::set<unsigned>& ids, Unk_StreamPoint* pOutPos, float* pOutDist);           // nearest m_148/m_930 object in ids
    int FUN_141bd4ed0(const std::set<int>& ids, Unk_StreamPoint* pOutPos, float* pOutDist);                // nearest m_678 object in ids
    int FUN_141bd51a0(const std::set<unsigned>& ids, Unk_StreamPoint* pOutPos, float* pOutDist);           // nearest m_510 object in ids
    void FUN_141bd5460();                               // each m_208 value: FUN_141b948b0(list) (RemoveAll)
    void FUN_141bd5500(unsigned modelId, Unk_WsP8* pEntity);   // drop the entity from m_208[modelId]'s list; destroys *pEntity
    void FUN_141bd5650();                               // player->m_250 notification (1)
    void FUN_141bd5ff0();                               // deliver pending notifications (m_2b0/m_2ac) to the m_048 listeners
    void FUN_141bd6170(int n1, int n2);                 // process n1 entities of m_088 and n2 of m_098
    void FUN_141bd6240(void* entity);                   // visibility/range decision for one entity
    void FUN_141bd6520();                               // rebuild m_088 from the flat model 0xe4fc9d5d entities
    void FUN_141bd6690();                               // retune m_0b4 and drain the backlog
    void FUN_141bd6810(char flag);                      // update the sight-range war fog and every npc's visibility
    void FUN_141bd6c40(void* npc, Unk_StreamPoint* center, class FieldPropertySightRange* range, float sight, char flag);   // fade one npc by distance
    bool FUN_141bd7230(Unk_StreamPoint* pt);            // player is outside the sight range of pt
    void FUN_141bd7350(bool enable);                    // set m_a98 and refresh the sight range
    void FUN_141bd7390();                               // refresh zone-based fading of the player and the m_118 objects
    void FUN_141bd7bf0();                               // request the preload of the resource id DAT_143ab2870
    void FUN_141bd7c60(int resourceId);                 // remember a loaded resource id
    void FUN_141bd7d10();                               // notify the m_048 listeners (slot 7)
    CString FUN_141bd8370(int loadResult);              // name of an egf load result (elr_*)
    void FUN_141bd8660(int v);                          // m_8f4 = v
    void FUN_141bd8680(int v);                          // m_8f8 = v
    int FUN_141bd86a0();                                // m_8f4
    int FUN_141bd86c0();                                // m_8f8
    Unk_WsP8* FUN_141bd86e0(Unk_WsP8* out, unsigned __int64 id);   // m_980 lookup
    Unk_WsP8* FUN_141bd87a0(Unk_WsP8* out, unsigned __int64 id);   // m_990 lookup
    bool FUN_141bd8860(void* pNpc);                     // move a pending npc from m_990 to m_980
    bool FUN_141bd8ae0(void* pNpc);                     // move a pending npc from m_980 to m_990
    bool FUN_141bd8e30(unsigned __int64 entityId, char show, float fFade);   // fade an entity in or out over fFade seconds
    void FUN_141bd92c0(float scale, float scale2, float duration, int mode);   // start the time-scale change
    void FUN_141bd9380();                               // end the time-scale change
    void FUN_141bd9410(Unk_WsP16* pObj);                 // show a debug tooltip over an interactive object
    void FUN_141bd97a0(unsigned __int64 id);            // remove the debug tooltip of id
    int FUN_141bd9870();                                // per-class table value of the local player
    int FUN_141bd98d0();                                // m_2c0
    int FUN_141bd98f0();                                // class index of the local player
    void FUN_141bd9950(const CString& s);               // m_a60 = s
    void FUN_141bd9990(const CString& s);               // m_a68 = s
    int FUN_141bd99d0(int id);                          // count the m_678 kind-6 objects linked to record id
    Unk_WsOptional<float>* FUN_141bd9c00();             // &m_a90
    void FUN_141bd9c20(struct Unk_WsD_Msg* msg);        // dispatch on the message kind
    void FUN_141bd9ca0(struct Unk_WsD_Msg* msg);        // kind 0: list of (id, flag)
    void FUN_141bd9da0(struct Unk_WsD_Msg* msg);        // kind 1: single (id, flag)
    void FUN_141bd9e60(float a, float b, float c, int skipId);   // notify the objects of m_118 / m_148
    void FUN_141bda050(float alpha, int skipId);        // fade every m_118 / m_148 object except skipId
    void FUN_141bda290(const std::vector<unsigned>* ids);   // strip effects from the entities of m_ac0[ids] and hide them
    void FUN_141bda460();                               // m_ac0.clear()
    void FUN_141bda490(unsigned key, void* pOutList);   // copy the m_208[key] list into *pOutList
    void FUN_141bda580();                               // rebuild m_708 from the ugc banner objects
    Unk_WsP16* FUN_141bda6d0(Unk_WsP16* out, unsigned key);   // m_708 lookup
    void FUN_141bda780();                               // expire the timed entries of m_ab0
    void FUN_141bda9c0(int v);                          // m_890 operation
    void FUN_141bda9f0();                               // m_890 operation
    void FUN_141bdaa20();                               // m_890 operation
    Unk_WsP8* FUN_141bdaa50(Unk_WsP8* out, Unk_WsP8* arg);   // m_890 operation (arg released)
    void FUN_141bdaae0();                               // show the node viewer dialog
    void FUN_141bdabb0();                               // show the research and development dialog
    void FUN_141bdac80(CStringA text);                  // append a line to that dialog
    void FUN_141bdad00(int kind, struct Unk_WsD_Msg* msg);   // forward kind 0x17 / 0x18 / 0x19 messages to m_aa0
    void FUN_141bdb5a0(int v);                          // m_ae0 = v
    int FUN_141bdb5c0();                                // m_ae0
    int FUN_141bdb5e0();                                // local player allowed check
    int FUN_141bdb660(int id);                          // quest manager check
    void FUN_141bdb690();                               // empty
    void FUN_141bdb6a0();                               // hide the m_ad0 tooltips
    void FUN_141bdb7a0();                               // show the m_ad0 tooltips
    void FUN_141bdb030(CStringA name, CStringW text);   // queue a (name, text) entry in m_a00
    void FUN_141bd7dd0();                               // per-frame callback registered by OnInit (helper D owns the body)
    int FUN_141bc1720(MS2Ptr<Unk_WsE_FieldObject> obj);     // register a field object (returns 0/1); defined in worldservice_1.cpp
    void FUN_141bc3560();                               // periodic tag-range enter pass (m_3f0/m_420/m_468/m_4b0/m_5e8/m_738/m_118)

    int FUN_141bbc580(int resetFlag, int mapId);        // state change into state 6 (field teardown); returns 0 when done, 1 if nothing to do

    // ---- non-virtual members, exe order (names invented unless noted). Append; do not reorder. ----

public:
    efd::Category m_category;                           // +0x030 own globally unique category (OnInit)
    efd::Category m_038;                                // +0x038
    int m_040;                                          // +0x040
    std::set<void*> m_048;                              // +0x048 ctor 0x141bf32d0 / dtor 0x141bf5ed0 TYPE?
    ATL::CAtlList<Unk_WsV058> m_058;                      // +0x058 0x141bef200 / 0x141bf4960
    std::list<Unk_WsElem> m_088;                        // +0x088 0x141bf2fa0 / 0x141bf5c60 TYPE?
    std::list<Unk_WsElem> m_098;                        // +0x098 same type as m_088
    Unk_StreamPoint m_0a8;                              // +0x0a8 copy of DAT_143b01a60 (a point constant)
    float m_0b4;                                        // +0x0b4 3000.0f
    ATL::CRBMap<unsigned __int64, Unk_WsV0b8> m_0b8;      // +0x0b8 0x141beff50 / 0x141bf4d50
    ATL::CRBMap<unsigned, Unk_WsV0e8> m_0e8;              // +0x0e8 0x141befd10 / 0x141bf4bd0
    ATL::CRBMap<unsigned, Unk_WsV118> m_118;              // +0x118 0x141befd40 / 0x141bf4bf0
    ATL::CRBMap<unsigned, Unk_WsV148> m_148;              // +0x148 0x141befce0 / 0x141bf4bb0
    ATL::CAtlList<Unk_WsP8> m_178;                      // +0x178 0x140963ae0 / 0x1409647c0 (shared)
    ATL::CRBMap<unsigned, Unk_WsV1a8> m_1a8;           // +0x1a8 0x141befcb0 / 0x141bf4b90
    std::map<unsigned __int64, Unk_WsV1d8> m_1d8;      // +0x1d8 0x141bf30e0 / 0x141bf5d50
    std::map<int, std::set<unsigned __int64> > m_1e8;   // +0x1e8 0x141bf2ff0 / 0x141bf5cb0
    std::map<int, Unk_WsV1f8> m_1f8;                   // +0x1f8 0x141bf2fc0 / 0x141bf5c90
    ATL::CAtlMap<unsigned, Unk_WsV208> m_208;            // +0x208 0x141bef530 / 0x141bf4a10
    CString m_250;                                      // +0x250
    CString m_258;                                      // +0x258
    int m_state;                                        // +0x260 = 7
    int m_prevState;                                    // +0x264 = 7
    efd::SmartPointer<egf::EntityManager> m_268;        // +0x268 GetSystemServiceAs<EntityManager> (OnInit, 0x07001000)
    efd::SmartPointer<efd::MessageService> m_spMessageService;   // +0x270
    egf::Scheduler* m_278;                              // +0x278 GetSystemServiceAs<Scheduler> (OnInit, 0x07001002), not ref-counted
    bool m_280;                                         // +0x280
    int m_284;                                          // +0x284
    int m_288;                                          // +0x288
    int m_28c;                                          // +0x28c = 1
    CStringW m_290;                                     // +0x290
    MS2Ptr<Unk_WsPtred298> m_298;                           // +0x298 0x141bf14b0(0) / 0x1408850f0 TYPE?
    int m_2a8;                                          // +0x2a8 = 1
    int m_2ac;                                          // +0x2ac
    int m_2b0;                                          // +0x2b0
    int m_2b4;                                          // +0x2b4
    int m_2b8;                                          // +0x2b8
    int m_2bc;                                          // +0x2bc
    int m_2c0;                                          // +0x2c0
    void* m_2c8;                                        // +0x2c8
    int m_2d0;                                          // +0x2d0
    efd::SmartPointer<efd::ISystemService> m_2d8;       // +0x2d8 dtor 0x140dc13f0 TYPE?
    bool m_2e0;                                         // +0x2e0
    std::map<unsigned __int64, Unk_WsV2e8> m_2e8;         // +0x2e8 0x141bf30b0 / 0x141bf5d30
    ATL::CAtlMap<unsigned __int64, Unk_WsV2f8> m_2f8;    // +0x2f8 0x141befad0 / 0x141bf4b30
    Unk_WsNiPtr<CWireframeManager> m_340;               // +0x340 0x141bf1020 / 0x141bf54e0 (OnInit: new CWireframeManager)
    Unk_WsNiPtr<Unk_WsElem> m_348;                      // +0x348 0x141bf0f90 / 0x141bf5470 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsV350> m_350;            // +0x350 0x141bef260 / 0x141bf4980
    int m_398;                                          // +0x398
    ATL::CAtlMap<unsigned, Unk_WsV3a0> m_3a0;            // +0x3a0 0x141bef710 / 0x141bf4a70
    CGlobalKeyTextCallback m_3e8;                       // +0x3e8
    ATL::CRBMap<Unk_WsP16, Unk_WsP16> m_3f0;            // +0x3f0 0x141234580 / 0x141234d30 (shared)
    ATL::CAtlMap<unsigned __int64, Unk_WsV420> m_420;    // +0x420 0x141bef9e0 / 0x141bf4b00
    ATL::CAtlMap<unsigned __int64, Unk_WsV468> m_468;    // +0x468 0x141befbc0 / 0x141bf4b60
    ATL::CRBMap<CString, Unk_WsV4b0> m_4b0;              // +0x4b0 0x141befe60 / 0x141bf4cb0
    ATL::CRBMap<unsigned __int64, Unk_WsV4e0> m_4e0;     // +0x4e0 0x141befdd0 / 0x141bf4c50
    ATL::CRBMap<CString, Unk_WsV510> m_510;              // +0x510 0x141befec0 / 0x141bf4cf0
    ATL::CRBMap<int, Unk_WsV540> m_540;                  // +0x540 0x141beff80 / 0x141bf4d70
    ATL::CRBMap<int, Unk_WsV570> m_570;                  // +0x570 0x141beffb0 / 0x141bf4d90
    ATL::CAtlMap<unsigned __int64, Unk_WsV5a0> m_5a0;     // +0x5a0 0x141bef8f0 / 0x141bf4ad0
    ATL::CRBMap<CString, Unk_WsV5e8> m_5e8;               // +0x5e8 0x141befe30 / 0x141bf4c90
    ATL::CRBMap<CString, Unk_WsV5e8> m_618;               // +0x618 same type as m_5e8
    ATL::CRBMap<unsigned __int64, Unk_WsPod8> m_648;    // +0x648 0x140cb6ab0 / 0x140cb6cd0 (shared)
    ATL::CRBMap<CString, Unk_WsV678> m_678;              // +0x678 0x141befe90 / 0x141bf4cd0
    ATL::CRBMap<unsigned __int64, Unk_WsV6a8> m_6a8;     // +0x6a8 0x141befef0 / 0x141bf4d10
    ATL::CRBMap<unsigned __int64, Unk_WsV6d8> m_6d8;    // +0x6d8 0x141befda0 / 0x141bf4c30
    ATL::CRBMap<unsigned, Unk_WsV708> m_708;             // +0x708 0x141befd70 / 0x141bf4c10
    ATL::CAtlMap<unsigned, Unk_WsV738> m_738;             // +0x738 0x141bef350 / 0x141bf49b0
    ATL::CAtlMap<unsigned, Unk_WsV780> m_780;            // +0x780 0x141bef800 / 0x141bf4aa0
    ATL::CRBMap<CString, Unk_WsV7c8> m_7c8;               // +0x7c8 0x141befe00 / 0x141bf4c70
    __int64 m_7f8;                                      // +0x7f8 never touched by the CU (padding or unused)
    int m_800;                                          // +0x800
    int m_804;                                          // +0x804
    int m_808;                                          // +0x808
    Unk_WsNiPtr<TextureLayerManager> m_spTextureLayerManager;               // +0x810 0x141bf1130 / 0x141bf5540
    Unk_WsNiPtr<ChaosLightEffectLayerManager> m_spChaosLightEffectLayerManager;   // +0x818 0x141bf1060 / 0x141bf5510
    Unk_StreamPoint m_boundsMin;                           // +0x820 (FLT_MAX x3)
    Unk_StreamPoint m_boundsMax;                           // +0x82c (-FLT_MAX x3)
    std::set<unsigned __int64> m_838;                   // +0x838 0x140a15e30 / 0x140a16650 (shared)
    ATL::CAtlMap<unsigned, Unk_WsV848> m_848;            // +0x848 0x141bef440 / 0x141bf49e0
    ATL::CRBMap<unsigned, Unk_WsPod8> m_890;            // +0x890 with m_8c0: one 0x38-byte CRBTree-derived class (ctor 0x1416c3150 = base(10) + [+0x30]=0, dtor 0x1416c3190, other obj) TYPE?
    int m_8c0;                                          // +0x8c0 (part of the m_890 class)
    Unk_WsDeletable* m_8c8;                             // +0x8c8 owned, deleted in OnShutdown
    Unk_WsDeletable* m_8d0;                             // +0x8d0 owned, deleted in OnShutdown
    Unk_StreamPoint m_8d8;                                 // +0x8d8 (0,0,0)
    Unk_StreamPoint m_8e4;                                 // +0x8e4 (0,0,0)
    bool m_8f0;                                         // +0x8f0 = true
    int m_8f4;                                          // +0x8f4
    int m_8f8;                                          // +0x8f8
    std::map<unsigned __int64, Unk_WsPod8> m_900;       // +0x900 0x1413e86d0 / 0x1413e91c0 (shared)
    int m_910;                                          // +0x910
    bool m_914;                                         // +0x914
    bool m_915;                                         // +0x915
    int m_918;                                          // +0x918
    bool m_91c;                                         // +0x91c = true
    CString m_920;                                      // +0x920
    int m_928;                                          // +0x928
    ATL::CAtlMap<unsigned, Unk_WsV930> m_930;            // +0x930 0x141bef620 / 0x141bf4a40
    int m_978;                                          // +0x978
    int m_97c;                                          // +0x97c
    std::map<unsigned __int64, Unk_WsV980> m_980;       // +0x980 0x141bf3080 / 0x141bf5d10
    std::map<unsigned __int64, Unk_WsV990> m_990;       // +0x990 0x141bf3050 / 0x141bf5cf0
    std::vector<Unk_WsV9a0> m_9a0;                     // +0x9a0 0x141bf3390 / 0x141bf5f80
    int m_9b8;                                          // +0x9b8
    int m_9bc;                                          // +0x9bc
    float m_9c0;                                        // +0x9c0 = 1.0f
    float m_9c4;                                        // +0x9c4 = 1.0f
    int m_9c8;                                          // +0x9c8
    ATL::CRBMap<int, int> m_9d0;                        // +0x9d0 0x141beff20 / 0x141bf4d30
    std::vector<Unk_WsVa00> m_a00;                     // +0xa00 0x141bf3330 / 0x141bf5f20
    std::vector<Unk_WsVa18> m_a18;                     // +0xa18 0x141bf3360 / 0x141bf5f50
    CLockCriticalSection m_lock;                        // +0xa30
    CString m_a60;                                      // +0xa60 = ""
    CString m_a68;                                      // +0xa68
    int m_a70;                                          // +0xa70 interval (ms) for the 0xa5 packet toggle
    int m_a74;                                          // +0xa74 next tick
    bool m_a78;                                         // +0xa78
    MS2Ptr<Unk_WsPtreda80> m_a80;                           // +0xa80 0x141bf1750 / 0x141bf5600 TYPE?
    Unk_WsOptional<float> m_a90;                        // +0xa90 ctor 0x141bf0e70, reset 0x141c2ed00, set 0x141bf68b0
    bool m_a98;                                         // +0xa98
    MS2Ptr<Unk_WsPtredaa0> m_aa0;                           // +0xaa0 0x141bf1650(0) / 0x141bf55d0 TYPE?
    std::map<unsigned __int64, Unk_WsVab0> m_ab0;       // +0xab0 0x141bf3110 / 0x141bf5d70
    std::map<unsigned, Unk_WsVac0> m_ac0;                 // +0xac0 0x141bf3020 / 0x141bf5cd0
    std::map<unsigned __int64, Unk_WsVad0> m_ad0;        // +0xad0 0x141bf3140 / 0x141bf5d90
    int m_ae0;                                          // +0xae0
    int m_ae4;                                          // +0xae4
    int m_ae8;                                          // +0xae8
    int m_aec;                                          // +0xaec
};
MS2_CHECK_SIZE(WorldService, 0xaf0);
MS2_CHECK_OFFSET(WorldService, m_category, 0x30);   // +0x28 = efd::AtomicRefCount (EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT, ctor 0x140ae79e0)
MS2_CHECK_OFFSET(WorldService, m_048, 0x48);
MS2_CHECK_OFFSET(WorldService, m_208, 0x208);
MS2_CHECK_OFFSET(WorldService, m_298, 0x298);
MS2_CHECK_OFFSET(WorldService, m_3e8, 0x3e8);
MS2_CHECK_OFFSET(WorldService, m_7c8, 0x7c8);
MS2_CHECK_OFFSET(WorldService, m_800, 0x800);
MS2_CHECK_OFFSET(WorldService, m_890, 0x890);
MS2_CHECK_OFFSET(WorldService, m_900, 0x900);
MS2_CHECK_OFFSET(WorldService, m_930, 0x930);
MS2_CHECK_OFFSET(WorldService, m_9a0, 0x9a0);
MS2_CHECK_OFFSET(WorldService, m_lock, 0xa30);
MS2_CHECK_OFFSET(WorldService, m_a80, 0xa80);
MS2_CHECK_OFFSET(WorldService, m_ad0, 0xad0);

inline TSingleton<WorldService>::TSingleton() { s_instance = static_cast<WorldService*>(this); }
