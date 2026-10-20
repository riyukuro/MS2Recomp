// ms2scenegraphservice.h - MS2SceneGraphService (RTTI .?AVMS2SceneGraphService@@): the game's subclass of the engine's
// ecr::SceneGraphService (0x240 bytes, no ClassInfo of its own). With the threaded update option (DAT_143ae2b30) it
// sorts the dynamic scene graphs into six update buckets (+0x160) that are updated by the scene graph worker threads; it
// also clears the cached shaders on a lost device and dumps the cache counts into the crash log.
// MS2DefaultTexturePalette, the texture palette handed to the service, routes texture lookups to the NIF loading service.
// Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `client\ms2\ms2scenegraphservice.cpp` (0x1414f0b90-0x1415033a0).
#pragma once

#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <ecr/SceneGraphService.h>
#include <NiTexturePalette.h>

class NiUpdateProcess;

// ---- the palette that looks textures up in the NIF loading service (0x10 bytes, vftable 0x142f26550) ----
class MS2DefaultTexturePalette : public NiTexturePalette
{
public:
    MS2DefaultTexturePalette();                                             // 0x1414f0b90
    ~MS2DefaultTexturePalette();                                            // 0x1414f0bd0, ??_G 0x1414fc600
    virtual NiTexture* GetTexture(const char* pcPath, NiTexture* pkSelf) const;   // 0x1414f0c00
    virtual void SetTexture(const char* pcPath, NiTexture* pkTex);          // 0x1414f0ca0
};
MS2_CHECK_SIZE(MS2DefaultTexturePalette, 0x10);

// ---- TSingleton<MS2SceneGraphService> (own vftable at +0x140; ctor 0x1414fa5f0, dtor 0x1414fb020, ??_G 0x1414fc400) ----
// Unlike the generic TSingleton (commonfiles/os.h) this one keeps the derived pointer: the ctor stores
// static_cast<MS2SceneGraphService*>(this) (this - 0x140).
class MS2SceneGraphService;
template <> class TSingleton<MS2SceneGraphService>
{
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static MS2SceneGraphService* s_instance;                                // 0x143ab9508
};

class MS2SceneGraphService : public ecr::SceneGraphService, public TSingleton<MS2SceneGraphService>
{
public:
    // Number of dynamic-update buckets (updated in the order 1, 0, 4, 5, riders, 2, animation callbacks, 3).
    enum { kBucketCount = 6 };

    MS2SceneGraphService(NiSPWorkflowManager* pWorkflowManager, NiTexturePalette* pTexturePalette,
        const efd::Bool toolMode);                                          // 0x1414f0d10
    virtual ~MS2SceneGraphService();                                        // 0x1414f0e40, ??_G 0x1414fc660

    void FUN_1414f0f00(bool bPauseUpdate);                                  // 0x1414f0f00 OnTick skips the update while set
    virtual efd::AsyncResult OnInit();                                      // 0x1414f0f20
    virtual efd::AsyncResult OnTick();                                      // 0x1414f1090
    virtual efd::AsyncResult OnShutdown();                                  // 0x1414f10e0
    void FUN_1414f11d0(egf::Entity* pEntity);                               // 0x1414f11d0 make the entity's scene graph dynamic
    void FUN_1414f1240(egf::Entity* pEntity);                               // 0x1414f1240 drop it from the dynamic update
    virtual void OnAssetLoadFailure(AssetDataPtr spAssetData);              // 0x1414f1290
    virtual void UpdateDynamicEntities(bool advanceUpdateTime = true, bool performUpdate = true,
        bool performUpdateOnce = true);                                     // 0x1414f12f0
    bool RemoveUnusedCacheAssetData(efd::utf8string physicalID);            // 0x1414f1760 (FUN_1414f1760)
    void ClearAllCachedShaders();                                           // 0x1414f18f0 (FUN_1414f18f0)
    virtual void AddToUpdate(SceneGraphData* pData);                        // 0x1414f19b0
    virtual void RemoveFromUpdate(SceneGraphData* pData);                   // 0x1414f1c10
    static void FUN_1414f1d00(MS2SceneGraphService* pService, int iBucket, efd::UInt32 uiBegin, efd::UInt32 uiEnd,
        NiUpdateProcess* pkProcess);                                        // 0x1414f1d00 MultiSceneUpdater callback
    void FUN_1414f1e30(NiAVObject* pkSceneGraph);                           // 0x1414f1e30 always update in bucket 1
    void FUN_1414f1e70(const egf::EntityID& entityID, int iBucket);         // 0x1414f1e70 bucket override by entity
    void FUN_1414f1ec0();                                                   // 0x1414f1ec0 drop all bucket overrides
    void FUN_1414f1ef0(const egf::EntityID& entityID);                      // 0x1414f1ef0 drop one bucket override
    void FUN_1414f1f50(int iBucket);                                        // 0x1414f1f50 update one bucket
    void MS2_MarkPreloadsAsFound(AssetData* pAssetData);                    // 0x1414f2250
    AssetData* MS2_SetAssetDataFromCache(AssetDataPtr spAssetData, ecr::SceneGraphCache::SceneGraphCacheHandle cacheHandle,
        bool usagePending);                                                 // 0x1414f2430
    void MS2_HandleCacheResponse(const ecr::SceneGraphCacheResponse* pResponse,
        efd::Category targetChannel);                                       // 0x1414f2aa0
    virtual void OnSceneGraphAdded(egf::Entity* pEntity, NiAVObject* pSceneGraph);     // 0x1414f32c0
    virtual void OnSceneGraphRemoved(egf::Entity* pEntity, NiAVObject* pSceneGraph);   // 0x1414f3300
    virtual void RemoveSceneGraph(egf::Entity* pEntity, efd::Bool forceRemoval = false);  // 0x1414f3340
    virtual void EntityEnterWorld(SceneGraphData* pSceneGraphData);         // 0x1414f3460
    virtual void EntityExitWorld(SceneGraphData* pSceneGraphData);          // 0x1414f3580
    efd::UInt32 FUN_1414f3660();                                            // 0x1414f3660 cached scene graph count
    static bool FUN_1414f3690(bool bBeforeReset, void* pvData);             // 0x1414f3690 device reset notification
    static bool FUN_1414f36b0(void* pvData);                                // 0x1414f36b0 lost device notification
    void FUN_1414f3700();                                                   // 0x1414f3700 crash-log dump

public:
    MS2_LAYOUT_FRIEND;
    bool m_bPauseUpdate;                                                    // +0x148
    struct LessAV { bool operator()(NiAVObject* const& a, NiAVObject* const& b) const { return a < b; } };   // = std::less<NiAVObject*>; the exe calls the copy at 0x14106a330
    std::set<NiAVObject*, LessAV> m_alwaysUpdated;                           // +0x150 scene graphs forced into bucket 1 (std::allocator)
    efd::vector<SceneGraphData*> m_buckets[kBucketCount];                   // +0x160
    ATL::CAtlMap<efd::UInt64, int> m_bucketOverrides;                       // +0x1f0 entity id -> bucket
    efd::UInt32 m_uiThreadCount;                                            // +0x238
};
MS2_CHECK_SIZE(MS2SceneGraphService, 0x240);
MS2_CHECK_OFFSET(MS2SceneGraphService, m_bPauseUpdate, 0x148);
MS2_CHECK_OFFSET(MS2SceneGraphService, m_alwaysUpdated, 0x150);
MS2_CHECK_OFFSET(MS2SceneGraphService, m_buckets, 0x160);
MS2_CHECK_OFFSET(MS2SceneGraphService, m_bucketOverrides, 0x1f0);
MS2_CHECK_OFFSET(MS2SceneGraphService, m_uiThreadCount, 0x238);

// @0x1414fa5f0
inline TSingleton<MS2SceneGraphService>::TSingleton() { s_instance = static_cast<MS2SceneGraphService*>(this); }
