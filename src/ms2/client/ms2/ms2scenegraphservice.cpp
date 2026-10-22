// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2SceneGraphService: the game's subclass of the engine's
// scene graph service (threaded bucket update of the dynamic scene graphs, lost-device shader purge, crash-log counts)
// and MS2DefaultTexturePalette, the texture palette backed by the NIF loading service.
// MS2-UNIT: client\ms2\ms2scenegraphservice.cpp
// MS2-RANGE: 0x1400f9250-0x1400f94b0 .text$di
// MS2-RANGE: 0x1414f0b90-0x1415033a0 .text$mn
// MS2-RANGE: 0x142cb3100-0x142cb3210 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$SetBitsOnOrOff@G@BitUtils@efd@@YAGGG_N@Z 0x1414f3f40 ; unique
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVMS2SceneGraphService@@P82@EAAXXZ@@UEAAXXZ 0x1414fc0a0 ; unique
// MS2-PIN: ?Clone@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVMS2SceneGraphService@@P82@EAAXXZ@@UEBAPEAV1@XZ 0x1414fcbd0 ; unique
// MS2-PIN: ?GetClassDesc@AssetCacheResponse@efd@@UEBAPEBVClassInfo@2@XZ 0x1414fcec0 ; unique
// MS2-PIN: ?GetClassDesc@SceneGraphCacheResponse@ecr@@UEBAPEBVClassInfo@efd@@XZ 0x1414fced0 ; unique
// MS2-PIN: ?GetClassDesc@SceneGraphService@ecr@@UEBAPEBVClassInfo@efd@@XZ 0x1414fcee0 ; unique
// MS2-PIN: ?TypeCast@AssetCacheResponse@efd@@UEBA_NIPEAPEAX@Z 0x1414fe570 ; unique
// MS2-PIN: ?TypeCast@AssetCacheResponse@efd@@UEBA_NIPEAPEBX@Z 0x1414fe5c0 ; unique
// MS2-PIN: ?TypeCast@SceneGraphCacheResponse@ecr@@UEBA_NIPEAPEAX@Z 0x1414fe610 ; unique
// MS2-PIN: ?TypeCast@SceneGraphCacheResponse@ecr@@UEBA_NIPEAPEBX@Z 0x1414fe660 ; unique
// MS2-PIN: ?TypeCast@SceneGraphService@ecr@@UEBA_NIPEAPEAX@Z 0x1414fe6b0 ; unique
// MS2-PIN: ?TypeCast@SceneGraphService@ecr@@UEBA_NIPEAPEBX@Z 0x1414fe700 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7MS2SceneGraphService@@6BISystemService@efd@@@ 0x142f26588
// MS2-PIN: ??_7MS2SceneGraphService@@6BIPropertyCallback@egf@@@ 0x142f26738
// MS2-PIN: ??_7MS2SceneGraphService@@6B@ 0x142f26750
// MS2-PIN: ??_7ClearCachedShaderFunctor@@6BEntitySceneGraphFunctor@SceneGraphService@ecr@@@ 0x142f26760
// MS2-PIN: ??_7ClearCachedShaderFunctor@@6BHandleSceneGraphFunctor@SceneGraphService@ecr@@@ 0x142f26778
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@PEAVSceneGraphData@SceneGraphService@ecr@@@efd@@V?$_Vector_val@U?$_Simple_types@PEAVSceneGraphData@SceneGraphService@ecr@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1414f3830
// MS2-PIN: ??3MemObject@efd@@SAXPEAX0@Z 0x1414f9ba0
// MS2-PIN: ??0?$CustomAllocator@PEAVSceneGraphData@SceneGraphService@ecr@@@efd@@QEAA@XZ 0x1414fa3b0
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@PEAVSceneGraphData@SceneGraphService@ecr@@V?$CustomAllocator@PEAVSceneGraphData@SceneGraphService@ecr@@@efd@@@std@@@std@@QEAA@XZ 0x1414fa9f0
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@PEAVSceneGraphData@SceneGraphService@ecr@@@std@@@std@@QEAA@XZ 0x1414fab00
// MS2-PIN: ??$_Convert_size@_K@std@@YA_K_K@Z 0x1414fab40
// MS2-PIN: ??0?$vector@PEAVSceneGraphData@SceneGraphService@ecr@@V?$CustomAllocator@PEAVSceneGraphData@SceneGraphService@ecr@@@efd@@@std@@QEAA@XZ 0x1414faba0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2scenegraphservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <NiDX9Renderer.h>
#include <NiMesh.h>
#include <NiBatchedUpdateProcess.h>
#include <efd/LoopedThread.h>
#include <efd/MessageService.h>
#include <efd/ServiceManager.h>
#include <egf/Entity.h>
#include <egf/EntityLoaderMessages.h>
#include <egf/FlatModel.h>
#include <egf/FlatModelManager.h>
#include <egf/egfClassIDs.h>
#include <ecr/RenderService.h>
#include <ecr/SceneGraphCacheResponse.h>
#include "ms2scenegraphservice.h"
#include "ms2animationservice.h"
#include "animationcallbackmanager.h"
#include "multisceneupdater.h"
#include "ms2/commonfiles/crashmanager.h"
#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

using efd::UInt32;
using efd::utf8string;
using efd::vector;
using efd::Bool;
using namespace egf;
using namespace ecr;

extern int DAT_143ae2b30;                               // 1: threaded scene graph update (worker threads)

// The NIF loading service's texture cache (CNifLoadingService, nifeffectparam.h; FUN_140a0afd0 returns it).
class Unk_SgNifLoader
{
public:
    NiTexturePtr FUN_141553eb0(CString strPath, NiTexture* pkSelf);    // cached texture by path
    void FUN_1415540f0(CString strPath, NiTexture* pkTex);              // cache a texture under a path
};
Unk_SgNifLoader* FUN_140a0afd0();

// The client options (FUN_1411b1db0 returns them): the scene graph worker thread count.
class Unk_SgOptions
{
public:
    UInt32 FUN_14070f0a0();
};
Unk_SgOptions* FUN_1411b1db0();


// The world objects (WorldService::m_118, an ATL::CRBMap<unsigned, Unk_WsV118> in worldservice.h) and the rider seat
// update run between the buckets.
class Unk_SgRidee { public: void FUN_1417074c0(); };                   // Ridee: seat the rider
class Unk_SgRider { public: Unk_SgRidee* FUN_1416764a0(); };           // PCBase: the ridee this actor rides
struct Unk_SgWorldObjectRef;                                            // map value: intrusive pointer to the object
Unk_SgRider* FUN_140aac420(Unk_SgWorldObjectRef* pRef);
class Unk_SgWorldObjects;
POSITION FUN_140c20a10(Unk_SgWorldObjects* pMap);                       // GetHeadPosition
Unk_SgWorldObjectRef* FUN_140c20a80(Unk_SgWorldObjects* pMap, POSITION pos);   // GetValueAt
void FUN_140c20a30(Unk_SgWorldObjects* pMap, POSITION* pPos);           // GetNext
class Unk_SgWorld { public: Unk_SgWorldObjects* FUN_141bd36b0(); };
Unk_SgWorld* FUN_1403ed2d0();

CCrashManager* FUN_140a44830();
MS2AnimationService* FUN_1413f9b10();
unsigned FUN_140d868f0(egf::FlatModelManager* pFlatModels);     // the loaded flat model count

// ---- static initializers (.text$di, in this order) ----
#ifndef MS2_HOOK_DLL
// @0x1400f9250
EE_HANDLER(MS2SceneGraphService, MS2_HandleCacheResponse, ecr::SceneGraphCacheResponse);   // 0x143ae0c68
#endif
// @0x1400f92b0
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f9370
static CString s_strSkill = "skill";
// @0x1400f93a0
static CString s_strStun = "stun";
// @0x1400f9400
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);    // 0x143ae0c90
// @0x1400f9450
static CString s_strSkill2 = "skill";                                   // 0x143ae0ce8
// @0x1400f9480
static CString s_strStun2 = "stun";                                     // 0x143ae0ce0

MS2SceneGraphService* TSingleton<MS2SceneGraphService>::s_instance = 0;

// Purges the renderer data of every NiAVObject of the scene graphs it is run over (ClearAllCachedShaders).
class ClearCachedShaderFunctor : public SceneGraphService::EntitySceneGraphFunctor,
    public SceneGraphService::HandleSceneGraphFunctor
{
public:
    // @0x1414fad40
    ClearCachedShaderFunctor(NiRenderer* pkRenderer) : m_pkRenderer(pkRenderer) {}
    // @0x1414fb2a0
    virtual ~ClearCachedShaderFunctor() { m_pkRenderer = NULL; }

    // @0x1414fc1e0
    virtual Bool operator()(const egf::Entity* pEntity, const efd::vector<NiObjectPtr>& objects)
    {
        efd::vector<NiObjectPtr>::const_iterator it;
        for (it = objects.begin(); it != objects.end(); it++)
        {
            NiAVObjectPtr spAVObject = NiDynamicCast(NiAVObject, *it);
            if (!spAVObject)
                continue;
            spAVObject->PurgeRendererData(m_pkRenderer);
        }
        return false;
    }

    // @0x1414fc0d0
    virtual Bool operator()(const SceneGraphService::SceneGraphHandle handle, const efd::vector<NiObjectPtr>& objects)
    {
        efd::vector<NiObjectPtr>::const_iterator it;
        for (it = objects.begin(); it != objects.end(); it++)
        {
            NiAVObjectPtr spAVObject = NiDynamicCast(NiAVObject, *it);
            if (!spAVObject)
                continue;
            spAVObject->PurgeRendererData(m_pkRenderer);
        }
        return false;
    }

    NiRenderer* m_pkRenderer;
};
MS2_CHECK_SIZE(ClearCachedShaderFunctor, 0x18);

// ---- MS2DefaultTexturePalette ----

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414f0b90
MS2DefaultTexturePalette::MS2DefaultTexturePalette()
{
}
#endif

// @0x1414f0bd0
MS2DefaultTexturePalette::~MS2DefaultTexturePalette()
{
}

// @0x1414f0c00
NiTexture* MS2DefaultTexturePalette::GetTexture(const char* pcPath, NiTexture* pkSelf) const
{
    return FUN_140a0afd0()->FUN_141553eb0(CString(pcPath), pkSelf);
}
MS2_REPLACE_METHOD(0x1414F0C00, MS2DefaultTexturePalette, GetTexture, 154, 0xA8167CF8);

// @0x1414f0ca0
void MS2DefaultTexturePalette::SetTexture(const char* pcPath, NiTexture* pkTex)
{
    FUN_140a0afd0()->FUN_1415540f0(CString(pcPath), pkTex);
}
MS2_REPLACE_METHOD(0x1414F0CA0, MS2DefaultTexturePalette, SetTexture, 98, 0x7EC1F0B7);

// ---- MS2SceneGraphService ----

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414f0d10
MS2SceneGraphService::MS2SceneGraphService(NiSPWorkflowManager* pWorkflowManager, NiTexturePalette* pTexturePalette,
    const efd::Bool toolMode)
    : SceneGraphService(pWorkflowManager, pTexturePalette, toolMode)
    , m_bPauseUpdate(false)
    , m_bucketOverrides(17, 0.75f, 0.25f, 2.25f, 10)
    , m_uiThreadCount(0)
{
}
#endif

// @0x1414f0e40
MS2SceneGraphService::~MS2SceneGraphService()
{
}

// @0x1414f0f00
void MS2SceneGraphService::SetPauseUpdate(bool bPauseUpdate)
{
    m_bPauseUpdate = bPauseUpdate;
}
MS2_REPLACE_METHOD(0x1414F0F00, MS2SceneGraphService, SetPauseUpdate, 26, 0xBCD448CC);

// @0x1414f0f20
efd::AsyncResult MS2SceneGraphService::OnInit()
{
    efd::AsyncResult result = SceneGraphService::OnInit();
    NiDX9Renderer* pkRenderer = static_cast<NiDX9Renderer*>(m_spRenderService->GetRenderer());
    if (pkRenderer)
    {
        pkRenderer->AddResetNotificationFunc(FUN_1414f3690, this);
        pkRenderer->AddLostDeviceNotificationFunc(FUN_1414f36b0, this);
    }
    FUN_140a44830()->FUN_1401ce3d0(TFunctor<void, EmptyParam>(this, &MS2SceneGraphService::FUN_1414f3700));
    if (DAT_143ae2b30 != 0)
    {
        m_uiThreadCount = FUN_1411b1db0()->FUN_14070f0a0();
        MultiSceneUpdater::GetInstance()->Create(m_uiThreadCount);
        MultiSceneUpdater::s_pfnCallback = reinterpret_cast<SceneUpdateCallback>(FUN_1414f1d00);
        MultiSceneUpdater::s_pCallbackContext = this;
    }
    return result;
}

// @0x1414f1090
efd::AsyncResult MS2SceneGraphService::OnTick()
{
    if (!m_bPauseUpdate)
        UpdateDynamicEntities();
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x1414F1090, MS2SceneGraphService, OnTick, 62, 0x30D40CAC);

// @0x1414f10e0
efd::AsyncResult MS2SceneGraphService::OnShutdown()
{
    if (DAT_143ae2b30 != 0)
    {
        MultiSceneUpdater::s_pCallbackContext = 0;
        MultiSceneUpdater::s_pfnCallback = 0;
        m_alwaysUpdated.clear();
        for (int i = 0; i < kBucketCount; i++)
            m_buckets[i].clear();
    }
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer)
    {
        pkRenderer->RemoveResetNotificationFunc(FUN_1414f3690);
        pkRenderer->RemoveLostDeviceNotificationFunc(FUN_1414f36b0);
    }
    if (DAT_143ae2b30 != 0)
        AnimationCallbackManager::GetInstance()->FUN_14099c030();
    return SceneGraphService::OnShutdown();
}
MS2_REPLACE_METHOD(0x1414F10E0, MS2SceneGraphService, OnShutdown, 222, 0xFEF72BD6);

// @0x1414f11d0
void MS2SceneGraphService::FUN_1414f11d0(egf::Entity* pEntity)
{
    SceneGraphData* pData = GetEntityData(pEntity);
    if (pData)
    {
        if (!pData->IsWaitingOnAsset())
        {
            pData->SetIsDynamic(true);
            AddToUpdate(pData);
        }
    }
}
MS2_REPLACE_METHOD(0x1414F11D0, MS2SceneGraphService, FUN_1414f11d0, 100, 0x3F182875);

// @0x1414f1240
void MS2SceneGraphService::FUN_1414f1240(egf::Entity* pEntity)
{
    SceneGraphData* pData = GetEntityData(pEntity);
    if (pData)
        RemoveFromUpdate(pData);
}
MS2_REPLACE_METHOD(0x1414F1240, MS2SceneGraphService, FUN_1414f1240, 71, 0x4A9093B5);

// @0x1414f1290
void MS2SceneGraphService::OnAssetLoadFailure(AssetDataPtr spAssetData)
{
    SceneGraphService::OnAssetLoadFailure(spAssetData);
}

// @0x1414f12f0
void MS2SceneGraphService::UpdateDynamicEntities(bool advanceUpdateTime, bool performUpdate, bool performUpdateOnce)
{
    float currTime = 0.0f;
    if (advanceUpdateTime)
    {
        currTime = (float)m_pServiceManager->GetTime(efd::kCLASSID_GameTimeClock);
        m_pUpdateProcess->SetTime(currTime);
        m_pBatchedUpdateProcess->SetTime(currTime);
    }

    if (performUpdate)
    {
        if (DAT_143ae2b30 != 0)
        {
            AnimationCallbackManager::GetInstance()->SetQueueMode(1);
            MultiSceneUpdater::s_fTime = currTime;
            FUN_1414f1f50(1);
            FUN_1414f1f50(0);
            FUN_1414f1f50(4);
            FUN_1414f1f50(5);
            Unk_SgWorldObjects* pObjects = FUN_1403ed2d0()->FUN_141bd36b0();
            for (POSITION pos = FUN_140c20a10(pObjects); pos != NULL; FUN_140c20a30(pObjects, &pos))
            {
                Unk_SgRider* pRider = FUN_140aac420(FUN_140c20a80(pObjects, pos));
                if (pRider != NULL)
                {
                    Unk_SgRidee* pRidee = pRider->FUN_1416764a0();
                    if (pRidee != NULL)
                        pRidee->FUN_1417074c0();
                }
            }
            FUN_1414f1f50(2);
            AnimationCallbackManager::GetInstance()->SetQueueMode(0);
            AnimationCallbackManager::GetInstance()->FUN_14099bd80();
            FUN_1414f1f50(3);
            m_pBatchedUpdateProcess->Flush();
        }
        else
        {
            efd::UInt32 numToUpdate = static_cast<efd::UInt32>(m_toUpdate.size());
            for (efd::UInt32 ui = 0; ui < numToUpdate; ++ui)
            {
                SceneGraphData* pData = m_toUpdate[ui];
                NiAVObject* pSceneGraph = pData->GetSceneGraph();
                if (pSceneGraph)
                    pSceneGraph->Update(*m_pBatchedUpdateProcess);

                UInt32 count = pData->m_placeableFeedback.size();
                for (UInt32 uj = 0; uj < count; ++uj)
                {
                    PlaceableFeedback(pData->m_placeableFeedback[uj]);
                }
            }
            m_pBatchedUpdateProcess->Flush();
        }
    }

    if (performUpdateOnce)
    {
        efd::UInt32 numToUpdate = static_cast<efd::UInt32>(m_toUpdateOnce.size());
        for (efd::UInt32 ui = 0; ui < numToUpdate; ++ui)
        {
            SceneGraphData* pData = m_toUpdateOnce[ui];
            NiAVObject* pSceneGraph = pData->GetSceneGraph();
            if (pSceneGraph)
            {
                pSceneGraph->Update(*m_pUpdateProcess);
                NiMesh::CompleteSceneModifiers(pSceneGraph);
            }

            UInt32 count = pData->m_placeableFeedback.size();
            for (UInt32 uj = 0; uj < count; ++uj)
            {
                PlaceableFeedback(pData->m_placeableFeedback[uj]);
            }
        }
    }

    OnSceneGraphsUpdated();

    m_toUpdateOnce.clear();
}
MS2_REPLACE_METHOD(0x1414F12F0, MS2SceneGraphService, UpdateDynamicEntities, 1119, 0xED39919E);

// @0x1414f1760
bool MS2SceneGraphService::RemoveUnusedCacheAssetData(efd::utf8string physicalID)
{
    AssetData* pAssetData = FindAssetData(physicalID);
    if (pAssetData)
    {
        pAssetData->m_isCached = false;
        if (!pAssetData->InUse() && pAssetData->m_cacheHandle && pAssetData->m_state == AssetData::ADS_Ready)
        {
            if (m_spSceneGraphCache->UnCacheSceneGraph(pAssetData->m_cacheHandle))
            {
                m_spSceneGraphCache->RemoveFilePaths(pAssetData->m_physicalID);
                m_assetsByPhysicalID.erase(pAssetData->m_physicalID);
                pAssetData->m_state = AssetData::ADS_Unloaded;
                return true;
            }
        }
        pAssetData->m_isCached = true;
    }
    return false;
}

// @0x1414f18f0
void MS2SceneGraphService::ClearAllCachedShaders()
{
    if (m_spRenderService == NULL || m_spRenderService->GetRenderer() == NULL)
        return;
    ClearCachedShaderFunctor functor(m_spRenderService->GetRenderer());
    ForEachEntitySceneGraph(functor);
    ForEachHandleSceneGraph(functor);
}

// @0x1414f19b0
void MS2SceneGraphService::AddToUpdate(SceneGraphData* pData)
{
    if (DAT_143ae2b30 != 0 && pData->m_ms2UpdateBucketIndex == SceneGraphData::kInvalidUpdateIndex)
    {
        int iBucket = pData->m_ms2UpdateBucket;
        NiAVObject* pkSceneGraph = pData->GetSceneGraph();
        std::set<NiAVObject*, LessAV>::iterator it = m_alwaysUpdated.find(pkSceneGraph);
        if (it != m_alwaysUpdated.end())
        {
            pData->m_ms2UpdateBucket = 1;
            iBucket = 1;
        }
        else if (!pData->IsAssetExternal())
        {
            if (pData->m_pEntity->GetModel()->ContainsModel(0xd3b04f05))
            {
                pData->m_ms2UpdateBucket = 5;
                iBucket = 5;
            }
            else if (pData->m_pEntity->GetModel()->ContainsModel(0xe2595a6e) ||
                pData->m_pEntity->GetModel()->ContainsModel(0x88c00694) ||
                pData->m_pEntity->GetModel()->ContainsModel(0x61abfc9b) ||
                pData->m_pEntity->GetModel()->ContainsModel(0x72f49865))
            {
                pData->m_ms2UpdateBucket = 4;
                iBucket = 4;
            }
            if (m_bucketOverrides.Lookup(pData->m_pEntity->GetEntityIDValue(), iBucket))
            {
                pData->m_ms2UpdateBucket = iBucket;
                m_bucketOverrides.RemoveKey(pData->m_pEntity->GetEntityIDValue());
            }
        }
        pData->m_ms2UpdateBucketIndex = static_cast<efd::UInt32>(m_buckets[iBucket].size());
        m_buckets[iBucket].push_back(pData);
    }
    SceneGraphService::AddToUpdate(pData);
}
MS2_REPLACE_METHOD(0x1414F19B0, MS2SceneGraphService, AddToUpdate, 593, 0xA04481E7);

// @0x1414f1c10
void MS2SceneGraphService::RemoveFromUpdate(SceneGraphData* pData)
{
    if (DAT_143ae2b30 != 0 && pData->m_ms2UpdateBucketIndex != SceneGraphData::kInvalidUpdateIndex)
    {
        SceneGraphData* pBackData = m_buckets[pData->m_ms2UpdateBucket].back();
        pBackData->m_ms2UpdateBucketIndex = pData->m_ms2UpdateBucketIndex;
        m_buckets[pData->m_ms2UpdateBucket][pBackData->m_ms2UpdateBucketIndex] = pBackData;
        m_buckets[pData->m_ms2UpdateBucket].pop_back();
        pData->m_ms2UpdateBucketIndex = SceneGraphData::kInvalidUpdateIndex;
    }
    SceneGraphService::RemoveFromUpdate(pData);
}
MS2_REPLACE_METHOD(0x1414F1C10, MS2SceneGraphService, RemoveFromUpdate, 219, 0x7CDE8B0F);

// @0x1414f1d00
void MS2SceneGraphService::FUN_1414f1d00(MS2SceneGraphService* pService, int iBucket, efd::UInt32 uiBegin,
    efd::UInt32 uiEnd, NiUpdateProcess* pkProcess)
{
    if (pService)
    {
        efd::vector<SceneGraphData*>& bucket = pService->m_buckets[iBucket];
        if (!bucket.empty())
        {
            for (efd::UInt32 ui = uiBegin; ui < uiEnd; ++ui)
            {
                SceneGraphData* pData = bucket[ui];
                NiAVObject* pSceneGraph = pData->GetSceneGraph();
                if (pSceneGraph)
                    pSceneGraph->Update(*pkProcess);

                UInt32 count = pData->m_placeableFeedback.size();
                for (UInt32 uj = 0; uj < count; ++uj)
                {
                    pService->PlaceableFeedback(pData->m_placeableFeedback[uj]);
                }
            }
        }
    }
}
MS2_REPLACE(0x1414F1D00, MS2SceneGraphService::FUN_1414f1d00, 297, 0xB30B4D87);

// @0x1414f1e30
void MS2SceneGraphService::FUN_1414f1e30(NiAVObject* pkSceneGraph)
{
    m_alwaysUpdated.insert(pkSceneGraph);
}
MS2_REPLACE_METHOD(0x1414F1E30, MS2SceneGraphService, FUN_1414f1e30, 48, 0xA04A05A5);

// @0x1414f1e70
void MS2SceneGraphService::FUN_1414f1e70(const egf::EntityID& entityID, int iBucket)
{
    m_bucketOverrides[entityID.GetValue()] = iBucket;
}
MS2_REPLACE_METHOD(0x1414F1E70, MS2SceneGraphService, FUN_1414f1e70, 60, 0x7F714462);

// @0x1414f1ec0
void MS2SceneGraphService::FUN_1414f1ec0()
{
    m_bucketOverrides.RemoveAll();
}
MS2_REPLACE_METHOD(0x1414F1EC0, MS2SceneGraphService, FUN_1414f1ec0, 33, 0xF5AD8023);

// @0x1414f1ef0
void MS2SceneGraphService::FUN_1414f1ef0(const egf::EntityID& entityID)
{
    if (!m_bucketOverrides.IsEmpty())
        m_bucketOverrides.RemoveKey(entityID.GetValue());
}
MS2_REPLACE_METHOD(0x1414F1EF0, MS2SceneGraphService, FUN_1414f1ef0, 75, 0x3467E42F);

// @0x1414f1f50
void MS2SceneGraphService::FUN_1414f1f50(int iBucket)
{
    efd::UInt32 uiThreads = m_uiThreadCount;
    efd::UInt32 uiTotal = static_cast<efd::UInt32>(m_buckets[iBucket].size());
    efd::UInt32 uiPerThread = uiTotal / uiThreads;
    if (uiPerThread != 0)
    {
        efd::UInt32 uiJob = 0;
        for (efd::UInt32 ui = 0; ui < uiThreads - 1; ++ui)
        {
            MultiSceneUpdater::GetInstance()->m_pProcs[uiJob].m_nFirst = ui * uiPerThread;
            MultiSceneUpdater::GetInstance()->m_pProcs[uiJob].m_nCount = (ui + 1) * uiPerThread;
            MultiSceneUpdater::GetInstance()->m_pProcs[uiJob].m_eOrder = iBucket;
            MultiSceneUpdater::GetInstance()->m_ppThreads[uiJob]->DoLoop();
            ++uiJob;
        }
        MultiSceneUpdater::GetInstance()->m_pProcs[uiJob].m_nFirst = (uiThreads - 1) * uiPerThread;
        MultiSceneUpdater::GetInstance()->m_pProcs[uiJob].m_nCount = uiTotal;
        MultiSceneUpdater::GetInstance()->m_pProcs[uiJob].m_eOrder = iBucket;
        MultiSceneUpdater::GetInstance()->m_ppThreads[uiJob]->DoLoop();
        ++uiJob;
        for (efd::UInt32 ui = 0; ui < uiJob; ++ui)
            MultiSceneUpdater::GetInstance()->m_ppThreads[ui]->WaitForLoopCompletion();
    }
    else
    {
        efd::UInt32 numToUpdate = static_cast<efd::UInt32>(m_buckets[iBucket].size());
        for (efd::UInt32 ui = 0; ui < numToUpdate; ++ui)
        {
            SceneGraphData* pData = m_buckets[iBucket][ui];
            NiAVObject* pSceneGraph = pData->GetSceneGraph();
            if (pSceneGraph)
                pSceneGraph->Update(*m_pBatchedUpdateProcess);

            UInt32 count = pData->m_placeableFeedback.size();
            for (UInt32 uj = 0; uj < count; ++uj)
            {
                PlaceableFeedback(pData->m_placeableFeedback[uj]);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1414F1F50, MS2SceneGraphService, FUN_1414f1f50, 757, 0x9B665AC9);

// @0x1414f2250
void MS2SceneGraphService::MS2_MarkPreloadsAsFound(AssetData* pAssetData)
{
    while (pAssetData->m_preloads.size() > 0)
    {
        EntityPreloadDataPtr spPreloadData = pAssetData->m_preloads.back();

        ++(spPreloadData->m_assetsFound);

        if (spPreloadData->m_assetsNeeded == spPreloadData->m_assetsFound &&
            spPreloadData->m_responseCategory.IsValid())
        {
            EntityPreloadResponse* pPreloadResponse = EE_NEW EntityPreloadResponse;
            pPreloadResponse->m_pEntity = spPreloadData->m_pEntityData->m_pEntity;
            m_pMessageService->SendLocal(pPreloadResponse, spPreloadData->m_responseCategory);
        }

        pAssetData->m_preloads.pop_back();
    }
}
MS2_REPLACE_METHOD(0x1414F2250, MS2SceneGraphService, MS2_MarkPreloadsAsFound, 465, 0x47110224);

// @0x1414f2430
SceneGraphService::AssetData* MS2SceneGraphService::MS2_SetAssetDataFromCache(AssetDataPtr spAssetData,
    SceneGraphCache::SceneGraphCacheHandle cacheHandle, bool usagePending)
{
    // Clear any load data on the asset data
    spAssetData->m_spLoadData = 0;

    // Get the physical ID that we are setting from.
    const utf8string& physicalID = m_spSceneGraphCache->GetPhysicalID(cacheHandle);

    if (spAssetData->m_state == AssetData::ADS_Reloading)
    {
        // Clear the scene graphs from all entities, attachments and handles
        efd::UInt32 numEntities = static_cast<efd::UInt32>(spAssetData->m_entities.size());
        for (efd::UInt32 ui = 0; ui < numEntities; ++ui)
        {
            SceneGraphData* pEntityData = spAssetData->m_entities[ui];
            UnsetSceneGraph(pEntityData);
        }
        efd::UInt32 numHandles = static_cast<efd::UInt32>(spAssetData->m_handles.size());
        for (efd::UInt32 ui = 0; ui < numHandles; ++ui)
        {
            SceneGraphData* pHandleData = spAssetData->m_handles[ui];
            UnsetSceneGraph(pHandleData);
        }
        efd::UInt32 numAttach = static_cast<efd::UInt32>(spAssetData->m_attachments.size());
        for (efd::UInt32 ui = 0; ui < numAttach; ++ui)
        {
            AttachedSceneGraphData* pAttachData = spAssetData->m_attachments[ui];
            UnsetAttachedSceneGraph(pAttachData);
        }
    }
    else
    {
        // Add it to the set of known identifier->physical IDs and remove it from pending loads.
        m_pendingAssetLoads.erase(spAssetData->m_identifier);
        m_requestIDToPhysicalID[spAssetData->m_identifier] = physicalID;
        spAssetData->m_identifier.clear();

        // We might already have the NIF for this request under a different request: merge into the existing one.
        AssetData* pExistingData = FindAssetData(physicalID);
        if (pExistingData && pExistingData != spAssetData)
        {
            MergeAssetData(pExistingData, spAssetData);
            return pExistingData;
        }

        // Set up data we now have from the cache handle.
        spAssetData->m_physicalID = physicalID;
        spAssetData->m_cacheHandle = cacheHandle;
        m_assetsByPhysicalID[physicalID] = spAssetData;
    }

    // We have new data and are ready for use.
    spAssetData->m_state = AssetData::ADS_Ready;

    // Set the scene graphs on all entities, attachments and handles
    efd::UInt32 numEntities = static_cast<efd::UInt32>(spAssetData->m_entities.size());
    for (efd::UInt32 ui = 0; ui < numEntities; ++ui)
    {
        SceneGraphData* pEntityData = spAssetData->m_entities[ui];
        SetSceneGraph(spAssetData, pEntityData);
    }
    efd::UInt32 numHandles = static_cast<efd::UInt32>(spAssetData->m_handles.size());
    for (efd::UInt32 ui = 0; ui < numHandles; ++ui)
    {
        SceneGraphData* pHandleData = spAssetData->m_handles[ui];
        SetSceneGraph(spAssetData, pHandleData);
    }
    efd::UInt32 numAttach = static_cast<efd::UInt32>(spAssetData->m_attachments.size());
    for (efd::UInt32 ui = 0; ui < numAttach; ++ui)
    {
        AttachedSceneGraphData* pAttachData = spAssetData->m_attachments[ui];
        SetAttachedSceneGraph(spAssetData, pAttachData);
    }

    // Mark all the preloads for this asset as completed.
    MS2_MarkPreloadsAsFound(spAssetData);

    // In theory this asset data is used, but remove it if it isn't and it isn't expected to be.
    if (!usagePending)
        RemoveUnusedAssetData(spAssetData);

    return spAssetData;
}

// @0x1414f2aa0
void MS2SceneGraphService::MS2_HandleCacheResponse(const ecr::SceneGraphCacheResponse* pResponse,
    efd::Category targetChannel)
{
    if (targetChannel == m_assetRefreshCategory)
    {
        ProcessSceneGraphCacheReload(pResponse);
        return;
    }

    SceneGraphCacheRequestDataPtr spCRData =
        (SceneGraphCacheRequestData*)pResponse->GetRequestData();

    if (pResponse->GetHandleCount() == 0)
    {
        EE_LOG_AT(efd::kGamebryoGeneral0,
            efd::ILogger::kERR1,
            ("%s: Found no assets when looking for identifier '%s'. "
            "Reloads or other change notifications for this identifier will be ignored and "
            "existing assets using this identifer will have their scene graphs removed. ",
            __FUNCTION__,
            pResponse->GetIdentifier().c_str()),
            MS2_THIS_FILE, 0x19c);

        if (spCRData->m_pAssetData)
        {
            OnAssetLoadFailure(spCRData->m_pAssetData);
        }

        m_pendingAssetLoads.erase(pResponse->GetIdentifier());

        // Some operations still need to send responses, so don't always exit.
        if (spCRData->m_action != SGCRA_CacheSceneGraph)
        {
            return;
        }
    }

    if (spCRData->m_action == SGCRA_AssetLoadRequest)
    {
        if (pResponse->GetHandleCount() > 1)
        {
            EE_LOG_AT(efd::kGamebryoGeneral0,
                efd::ILogger::kERR1,
                ("%s: Found %d assets when looking for tag '%s'. "
                "Ignoring all but the first.",
                __FUNCTION__,
                pResponse->GetHandleCount(),
                pResponse->GetIdentifier().c_str()),
                MS2_THIS_FILE, 0x1bc);
        }

        spCRData->m_pAssetData =
            MS2_SetAssetDataFromCache(spCRData->m_pAssetData, pResponse->GetHandle(0), false);
    }
    else if (spCRData->m_action == SGCRA_CacheSceneGraph)
    {
        SceneGraphCacheResponse* pNewResponse = EE_NEW SceneGraphCacheResponse(
            pResponse->GetIdentifier(),
            spCRData->m_responseCategory,
            spCRData->m_pRequestData,
            pResponse->GetResult(),
            pResponse->GetType());

        if (pResponse->GetHandleCount() == 1)
        {
            m_requestIDToPhysicalID[pResponse->GetIdentifier()] =
                m_spSceneGraphCache->GetPhysicalID(pResponse->GetHandle(0));
        }

        vector<SceneGraphCache::SceneGraphCacheHandle> handles;
        for (UInt32 ui = 0; ui < pResponse->GetHandleCount(); ++ui)
        {
            handles.push_back(pResponse->GetHandle(ui));
            pNewResponse->AddHandle(pResponse->GetHandle(ui));
        }
        CacheHandles(handles);

        if (spCRData->m_responseCategory.IsValid())
        {
            // Forward the message to the given response category
            m_pMessageService->SendLocal(pNewResponse, spCRData->m_responseCategory);
        }
        else
        {
            EE_DELETE pNewResponse;
        }
    }
    return;
}

// @0x1414f32c0
void MS2SceneGraphService::OnSceneGraphAdded(egf::Entity* pEntity, NiAVObject* pSceneGraph)
{
    SceneGraphService::OnSceneGraphAdded(pEntity, pSceneGraph);
}
MS2_REPLACE_METHOD(0x1414F32C0, MS2SceneGraphService, OnSceneGraphAdded, 44, 0x13218C46);

// @0x1414f3300
void MS2SceneGraphService::OnSceneGraphRemoved(egf::Entity* pEntity, NiAVObject* pSceneGraph)
{
    SceneGraphService::OnSceneGraphRemoved(pEntity, pSceneGraph);
}
MS2_REPLACE_METHOD(0x1414F3300, MS2SceneGraphService, OnSceneGraphRemoved, 44, 0x84454759);

// @0x1414f3340
void MS2SceneGraphService::RemoveSceneGraph(egf::Entity* pEntity, efd::Bool forceRemoval)
{
    if (!pEntity)
        return;

    SceneGraphDataPtr spEntityData = GetEntityData(pEntity);
    if (!spEntityData)
        return;

    if (spEntityData->IsAssetExternal())
    {
        if (!forceRemoval)
            return;

        // RemoveEntityFromAssetData would normally call UnsetSceneGraph, but we have no
        // asset data so we won't do anything. Do it explicitly here.
        UnsetSceneGraph(spEntityData);
    }

    // Remove all attachment info before removing the scene graph itself.
    RemoveAllAttachmentData(spEntityData);

    // Remove it from the AssetData (render list, update list, removed message).
    RemoveEntityFromAssetData(spEntityData);

    // Remove from the map of entities to data
    m_entityData.erase(pEntity);
}
MS2_REPLACE_METHOD(0x1414F3340, MS2SceneGraphService, RemoveSceneGraph, 272, 0xE3027A42);

// @0x1414f3460
void MS2SceneGraphService::EntityEnterWorld(SceneGraphData* pSceneGraphData)
{
    if (pSceneGraphData->IsInWorld())
        return;

    NiAVObject* pAVObject = pSceneGraphData->GetSceneGraph();
    if (pAVObject)
    {
        if (pSceneGraphData->IsRenderable() && m_spRenderService)
        {
            // Tell the renderer, if rendered
            m_spRenderService->AddRenderedEntity(
                pSceneGraphData->m_pEntity,
                pAVObject);
            pSceneGraphData->SetIsRendered(true);
        }
        else
        {
            pSceneGraphData->SetIsRendered(false);
        }

        if (pSceneGraphData->IsDynamic())
        {
            AddToUpdate(pSceneGraphData);
        }
        else
        {
            AddToUpdateOnce(pSceneGraphData);
        }
    }

    pSceneGraphData->SetIsInWorld(true);
}
MS2_REPLACE_METHOD(0x1414F3460, MS2SceneGraphService, EntityEnterWorld, 279, 0x725EEEC9);

// @0x1414f3580
void MS2SceneGraphService::EntityExitWorld(SceneGraphData* pSceneGraphData)
{
    if (!pSceneGraphData->IsInWorld())
        return;

    // Take the entity out of the rendered world
    if (pSceneGraphData->IsRendered())
    {
        m_spRenderService->RemoveRenderedEntity(
            pSceneGraphData->m_pEntity,
            pSceneGraphData->GetSceneGraph());
        pSceneGraphData->SetIsRendered(false);
    }

    NiAVObject* pAVObject = pSceneGraphData->GetSceneGraph();
    if (pAVObject)
    {
        RemoveFromUpdate(pSceneGraphData);
        RemoveFromUpdateOnce(pSceneGraphData);
    }

    pSceneGraphData->SetIsInWorld(false);
}
MS2_REPLACE_METHOD(0x1414F3580, MS2SceneGraphService, EntityExitWorld, 217, 0x79C9BE43);

// @0x1414f3660
efd::UInt32 MS2SceneGraphService::FUN_1414f3660()
{
    return m_spSceneGraphCache->GetIdentifierCount();
}
MS2_REPLACE_METHOD(0x1414F3660, MS2SceneGraphService, FUN_1414f3660, 41, 0x4EB5A467);

// @0x1414f3690
bool MS2SceneGraphService::FUN_1414f3690(bool bBeforeReset, void* pvData)
{
    return true;
}
MS2_REPLACE(0x1414F3690, MS2SceneGraphService::FUN_1414f3690, 12, 0x64ABE79E);

// @0x1414f36b0
bool MS2SceneGraphService::FUN_1414f36b0(void* pvData)
{
    MS2SceneGraphService* pService = static_cast<MS2SceneGraphService*>(pvData);
    if (pService)
    {
        FUN_140a44830()->FUN_1401ce2f0("\n *Lost device - ClearAllCachedShaders()");
        pService->ClearAllCachedShaders();
    }
    return true;
}
MS2_REPLACE(0x1414F36B0, MS2SceneGraphService::FUN_1414f36b0, 64, 0xDE91E682);

// @0x1414f3700
// MS2-FUNCTIONAL: the exe passes the MS2AnimationService counts as 32-bit temps (its getters return a 32-bit count; the
// shared ms2animationservice.h declares size_t), so the three count arguments compile with a different temp width.
void MS2SceneGraphService::FUN_1414f3700()
{
    FUN_140a44830()->FUN_1401ce2b0("\n--- SceneGraphService Log---");
    FUN_140a44830()->FUN_1401ce2f0("SceneGraphCached count: %d", FUN_1414f3660());
    egf::FlatModelManager* pFlatModels;
    MS2AnimationService* pAnimation;
    pFlatModels =
        EE_DYNAMIC_CAST(egf::FlatModelManager, m_pServiceManager->GetSystemServiceAs<egf::FlatModelManager>());
    if (pFlatModels)
        FUN_140a44830()->FUN_1401ce2f0("FlatModel count: %d", FUN_140d868f0(pFlatModels));
    pAnimation = FUN_1413f9b10();
    if (pAnimation)
    {
        FUN_140a44830()->FUN_1401ce2f0("Asset count: %d", (efd::UInt32)pAnimation->GetAssetCount());
        FUN_140a44830()->FUN_1401ce2f0("Actor count: %d", (efd::UInt32)pAnimation->GetActorCount());
        FUN_140a44830()->FUN_1401ce2f0("KFMCached count: %d", (efd::UInt32)pAnimation->GetKFMCacheCount());
    }
}
MS2_REPLACE_METHOD(0x1414F3700, MS2SceneGraphService, FUN_1414f3700, 292, 0xF2EAAB3D);
// MS2-PIN: ??_GClearCachedShaderFunctor@@UEAAPEAXI@Z 0x1414fc560 ; scalar deleting dtor (no symbols.tsv row)
// MS2-PIN: ??_GNiTexturePalette@@UEAAPEAXI@Z 0x1414fc6c0 ; NiTexturePalette scalar deleting dtor COMDAT copy kept by this TU
