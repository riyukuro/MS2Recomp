// HardwareInstancingService (RTTI name): efd system service (class id 0x06100009) that draws the static instanced
// entities of the current map (FlatModel property 0x23f9860e) through shared hardware-instanced meshes. Per map it
// groups the entities by asset into EntityInstancing objects (one NiMeshHWInstance node per asset and grid cell),
// keeps the DynamicInstancing objects created on request (FUN_1413d49f0) and the "nearby" entities whose
// property 0xe68ebfdf learns which instancing covers them. It is also an egf::IPropertyCallback (property changes of
// instanced entities queue them for a refresh on the next tick) and an IWorldServiceCallback (slot 3 drops the map).
// Member and helper names are invented from their use.
// Owning unit: ?\hardwareinstancingservice.cpp (0x1413d3000-0x1413e8a20, .text$di 0x1400f4b40-0x1400f4ea0; dir client\ms2).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>
#include <efd/Point3.h>
#include <efd/StdContainers.h>
#include <efd/utf8string.h>
#include <egf/IPropertyCallback.h>
#include <egf/EntityID.h>
#include <egf/Entity.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/meshinstancing.h"

namespace efd { class Category; }
namespace egf { class EntityChangeMessage; }
namespace ecr { class SceneGraphAddedMessage; }
class EntityInstancing;
class NiTransform;

// An entity near which instancings are tested (FlatModel 0x2c4767f5): its position and pick radius.
struct Unk_HwiNearby
{
    Unk_HwiNearby() {}                                              // 0x1413e8a40
    egf::Entity* m_pEntity;                                         // +0
    float m_fRadius;                                                // +8 property 0x4871503b
    efd::Point3 m_kPos;                                             // +0xc property 0xfd95ca52
};
MS2_CHECK_SIZE(Unk_HwiNearby, 0x18);

// A DynamicInstancing request whose entity had no scene graph yet (resolved by the SceneGraphAddedMessage handler).
struct Unk_HwiPending
{
    egf::EntityID m_id;                                             // +0
    NiTransform* m_pTransform;                                      // +8 EE_ALLOC'd by the requester, EE_FREE'd here
    int m_nArg10;                                                   // +0x10
    int m_nArg14;                                                   // +0x14
};
MS2_CHECK_SIZE(Unk_HwiPending, 0x18);

// An instanced entity and the EntityInstancing it was put in (FUN_1413d5710's work list).
struct Unk_HwiCreated
{
    Unk_HwiCreated(egf::Entity* pEntity, EntityInstancing* pInstancing)    // 0x1413e8a70
        : m_pEntity(pEntity), m_pInstancing(pInstancing) {}
    egf::Entity* m_pEntity;                                         // +0
    EntityInstancing* m_pInstancing;                                // +8
};
MS2_CHECK_SIZE(Unk_HwiCreated, 0x10);

// The instancing state of one map.
struct Unk_HwiMapData
{
    Unk_HwiMapData() : m_bLoaded(false), m_nCellSize(0), m_nVisited(0) {}  // 0x1413e8850

    bool m_bLoaded;                                                 // +0
    int m_nCellSize;                                                // +4
    size_t m_nVisited;                                              // +8 entries of m_mapExcluded marked visited
    std::list<Unk_HwiNearby> m_listNearby;                          // +0x10
    std::map<egf::EntityID, int> m_mapExcluded;                     // +0x20 entities kept out of the instancing
    std::list<MeshInstancing*> m_listInstancings;                   // +0x30 owned
    std::map<efd::UInt64, MeshInstancing*> m_mapByValue;            // +0x40 entity id value -> instancing
    std::map<egf::EntityID, MeshInstancing*> m_mapDynamic;          // +0x50 entity id -> DynamicInstancing
};
MS2_CHECK_SIZE(Unk_HwiMapData, 0x60);

// A property write saved while an entity's property cache is on (id, a heap copy of the old value, its class id).
// Same view as bosstargetcamera.cpp (its ctor 0x140947490) and scenestategame.cpp.
struct Unk_PropertyCacheEntry
{
    Unk_PropertyCacheEntry() : m_id(0), m_pValue(NULL), m_type(0) {}       // 0x1409474d0
    Unk_PropertyCacheEntry(unsigned nId, void* pValue, unsigned nType) : m_id(nId), m_pValue(pValue), m_type(nType) {}

    unsigned m_id;
    void* m_pValue;
    unsigned m_type;
};
MS2_CHECK_SIZE(Unk_PropertyCacheEntry, 0x18);

// A client entity with a property cache (egf::Entity subclass: +0xc8 caching on, +0xd0 the plain writes, +0xe0 the
// keyed writes; scenestategame.cpp's Unk_SSGCachedEntity writes them back). MS2's keyed SetPropertyValue<T> first
// saves the property's old value into the cache, then sets it. Names invented.
class Unk_HwiCachedEntity : public egf::Entity
{
public:
    template<typename T>
    void CacheKeyedPropertyValue(egf::PropertyID propID, const efd::utf8string& key, const T& data);
    template<typename T>
    egf::PropertyResult SetPropertyValue(egf::PropertyID propID, const efd::utf8string& key, const T& data);

    bool m_bCaching;                                                        // +0xc8
    efd::map<unsigned, Unk_PropertyCacheEntry> m_mapCache;                  // +0xd0
    efd::map<unsigned, efd::map<efd::utf8string, Unk_PropertyCacheEntry> > m_mapKeyedCache;   // +0xe0
};
MS2_CHECK_OFFSET(Unk_HwiCachedEntity, m_bCaching, 0xc8);
MS2_CHECK_OFFSET(Unk_HwiCachedEntity, m_mapCache, 0xd0);
MS2_CHECK_OFFSET(Unk_HwiCachedEntity, m_mapKeyedCache, 0xe0);

class HardwareInstancingService : public efd::ISystemService, public egf::IPropertyCallback, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(HardwareInstancingService, 0x06100009, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    HardwareInstancingService();                                    // 0x1413d42a0
    virtual ~HardwareInstancingService();                           // 0x1413d43d0
    virtual const char* GetDisplayName() const;                     // 0x1413d4470
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1413d4490
    virtual efd::AsyncResult OnInit();                              // 0x1413d4520
    virtual efd::AsyncResult OnTick();                              // 0x1413d45a0
    virtual efd::AsyncResult OnShutdown();                          // 0x1413d45d0
    virtual void OnPropertyUpdate(const efd::ClassID& callerID, egf::Entity* pEntity,
        const egf::PropertyID& propertyID, const egf::IProperty* pProperty, const efd::UInt32 tags);   // 0x1413d4680
    // IWorldServiceCallback (the exe's bodies work on the adjusted this)
    virtual void vfunc_0(int nMap);                                 // 0x1413d7960 map entered
    virtual void vfunc_1(int nMap);                                 // 0x1413d7cf0
    virtual void vfunc_3(int nMap);                                 // 0x1413d7990 map left
    virtual void vfunc_4(int nMap);                                 // 0x1413d7d00

    void FUN_1413d47b0();                                           // tick: refresh the queued entities
    egf::EntityID FUN_1413d49f0(const efd::utf8string& strName, efd::AssetID& rAsset, bool bInstanced,
        NiTransform* pTransform, int nArg10, int nArg14);           // create an entity drawn by a DynamicInstancing
    MeshInstancing* FUN_1413d4b40(egf::Entity* pEntity, int nCellZ, unsigned nCapacity);
    int FUN_1413d4fe0(EntityInstancing* pInstancing, egf::Entity* pEntity);
    void FUN_1413d5220(egf::EntityID id);                           // drop the instancing of an entity
    void FUN_1413d5660();
    void FUN_1413d5710();                                           // build the instancings of the current map
    void SetEnabled(bool bEnabled);
    int FUN_1413d6650();
    MeshInstancing* FUN_1413d66b0(egf::Entity* pEntity);
    MeshInstancing* FUN_1413d6770(const Unk_MeshInstancingConfig& rConfig);
    NiNode* FUN_1413d6840(egf::Entity* pEntity);
    int FUN_1413d6890(egf::Entity* pEntity);                       // is the entity excluded
    bool FUN_1413d68d0(egf::Entity* pEntity);
    bool FUN_1413d6920();
    void FUN_1413d69b0(const egf::EntityID& id);
    void FUN_1413d6ab0(bool bShow);
    static bool FUN_1413d6b60(egf::Entity* pEntity);                       // can the entity be instanced
    static bool FUN_1413d6c70(egf::Entity* pEntity);                       // has a mesh with a hardware skin modifier
    void FUN_1413d6db0();
    int FUN_1413d6e60(egf::Entity* pEntity, bool bFlag);
    int FUN_1413d6f40(egf::Entity* pEntity);
    int FUN_1413d6fc0(egf::Entity* pEntity);
    void FUN_1413d7040(bool bVisible);
    Unk_InstanceIdList FUN_1413d7160(egf::Entity* pEntity);         // the nearby entities the entity's bound reaches
    bool FUN_1413d7360();
    void FUN_1413d73a0(unsigned nMap);                              // unload a map
    void FUN_1413d7570(const ecr::SceneGraphAddedMessage* pMsg, efd::Category targetChannel);
    void FUN_1413d7710(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);   // 8254 removed
    void FUN_1413d7800(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel);   // 8196 updated
    void FUN_1413d78e0(egf::Entity* pEntity);
    void FUN_1413d7d10(const egf::EntityID& id);                    // exclude an entity
    int FUN_1413d7d90(const egf::EntityID& id);
    int FUN_1413d7e30();
    void FUN_1413d7e70(int nCellSize);
    unsigned FUN_1413d7eb0();
    MeshInstancing* FUN_1413d7ef0(int nIndex, bool bOnly);
    MeshInstancing* FUN_1413d80f0(egf::Entity* pEntity);
    void FUN_1413d83f0(egf::Entity* pEntity);
    bool IsEnabled();
    bool FUN_1413d84e0(egf::Entity* pEntity, NiTransform* pTransform, int nArg10, int nArg14);

    bool m_bEnabled;                                                // +0x34
    bool m_bReady;                                                  // +0x35
    bool m_bVisible;                                                // +0x36
    unsigned m_nMap;                                                // +0x38
    ATL::CAtlMap<efd::UInt64, efd::SmartPointer<egf::Entity> > m_mapQueued;     // +0x40
    std::map<unsigned, Unk_HwiMapData> m_maps;                      // +0x88 keyed by map id (less<unsigned> in the exe)
    int m_nNextId;                                                  // +0x98
    std::list<Unk_HwiPending> m_listPending;                        // +0xa0
};
MS2_CHECK_SIZE(HardwareInstancingService, 0xb0);
MS2_CHECK_OFFSET(HardwareInstancingService, m_bEnabled, 0x34);
MS2_CHECK_OFFSET(HardwareInstancingService, m_mapQueued, 0x40);
MS2_CHECK_OFFSET(HardwareInstancingService, m_maps, 0x88);
MS2_CHECK_OFFSET(HardwareInstancingService, m_listPending, 0xa0);
