// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game's subclass of ecr::LightService.
// MS2-UNIT: ?\ms2lightservice.cpp
// MS2-RANGE: 0x1414bfc40-0x1414cf920 .text$mn
// MS2-RANGE: 0x1400f8d70-0x1400f8ee0 .text$di
// MS2-PIN: ??_7MS2LightService@@6BISystemService@efd@@@ 0x142f213b0
// MS2-PIN: ??_7MS2LightService@@6BIRenderServiceDelegate@ecr@@@ 0x142f21488
// MS2-PIN: ??_7MS2LightService@@6BIPropertyCallback@egf@@@ 0x142f214e0
// MS2-PIN: ??_7MS2LightService@@6BIWorldServiceCallback@@@ 0x142f214f8
// MS2-PIN: ??_7MS2LightService@@6B?$TSingleton@VMS2LightService@@@@@ 0x142f21540
// MS2-PIN: ??_7AddAffectedObjectFunctor@@6BEntitySceneGraphFunctor@SceneGraphService@ecr@@@ 0x142f215d0
// MS2-PIN: ??_7AddAffectedObjectFunctor@@6BHandleSceneGraphFunctor@SceneGraphService@ecr@@@ 0x142f215e8
// MS2-PIN: ??1?$MessageSubclassHandler@VMS2LightService@@VEntityChangeMessage@egf@@V23@@efd@@UEAA@XZ 0x1414c7a60
// MS2-PIN: ??1?$MessageWrapperSubclassHandler@VMS2LightService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAA@XZ 0x1414c7a80
// MS2-PIN: ??1?$MessageWrapperSubclassHandler@VMS2LightService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAA@XZ 0x1414c7aa0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_List_node@VEntityID@egf@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@VEntityID@egf@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1414c12d0 ; unique
// MS2-PIN: ??$construct@PEAU?$_List_node@VEntityID@egf@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@VEntityID@egf@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@VEntityID@egf@@PEAX@std@@@1@QEAPEAU?$_List_node@VEntityID@egf@@PEAX@1@AEAPEAU31@@Z 0x1414c61a0 ; unique
// MS2-PIN: ??0BaseObjectData@LightService@ecr@@QEAA@XZ 0x1414c7960 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageHandlerImpl@VMS2LightService@@VEntityChangeMessage@egf@@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1414c98e0 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageSubclassHandler@VMS2LightService@@VEntityChangeMessage@egf@@V23@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1414c9920 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageWrapperSubclassHandler@VMS2LightService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1414c9980 ; unique
// MS2-PIN: ?TypeCast@LightService@ecr@@UEBA_NIPEAPEBX@Z 0x1414c9c60 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$SmartPointer@VEntity@egf@@@efd@@MU?$less@V?$SmartPointer@VEntity@egf@@@efd@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@M@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$SmartPointer@VEntity@egf@@@efd@@M@std@@PEAX@2@@Z 0x1414cb9a0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@PEAVLightData@LightService@ecr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@PEAVLightData@LightService@ecr@@@std@@@efd@@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@PEAVLightData@LightService@ecr@@@std@@PEAX@2@@Z 0x1414cb9d0 ; prop
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2lightservice.h"
#include "hook/ms2hook.h"
#include <list>
#include <efd/MessageHandlerBase.h>
#include <egf/EntityManager.h>
#include <egf/FlatModel.h>
#include <egf/StandardModelLibraryFlatModelIDs.h>
#include <egf/StandardModelLibraryPropertyIDs.h>
#include <ecr/SceneGraphService.h>
#include <NiNode.h>
#include <NiTPointerMap.h>
#include <NiLight.h>
#include <NiShadowManager.h>
#include <NiShadowGenerator.h>
#include <NiPSSMShadowClickGenerator.h>
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/coptimizer.h"

using namespace egf;

// ---- out-of-unit callees ----
WorldService* FUN_1403ed2d0();                                          // the world service (global)
egf::EntityManager* FUN_1409670f0();                                    // the world's entity manager
egf::Entity* FUN_1411cf440(egf::EntityManager* mgr, const egf::EntityID* id);   // entity lookup by id
void FUN_1413eb6d0(egf::IPropertyCallback* pCallback);                  // registers a light property callback
COptimizer* FUN_1409f7c90();                                            // the optimizer (singleton)
int FUN_140ae1c10();                                                    // the current graphics quality level
class Unk_QualityTable;
Unk_QualityTable* FUN_140ae1c00();                                      // the per feature quality table
int FUN_141376880(Unk_QualityTable* pTable, int nFeature);              // the level a feature needs (5: light shadows)

// The effect service; told about every light the batch creates.
class Unk_LightEffectService
{
public:
    void FUN_1411a74a0(egf::EntityID entityID, egf::Entity* pEntity);
};
Unk_LightEffectService* FUN_1403ed280();

// The graphics options: whether the "dim lights" option is on, and the post processing step that applies it.
class Unk_LightVideoOptions
{
public:
    bool FUN_14125e0b0();
};
class Unk_LightOptions
{
public:
    Unk_LightVideoOptions* FUN_1409a8ac0();
};
Unk_LightOptions* FUN_1409a8b10();
class Unk_LightRenderStep
{
public:
    bool FUN_1409a8f00();
};
class Unk_LightPostProcess
{
public:
    Unk_LightRenderStep* FUN_1416a3a90(int nStep);
};
Unk_LightPostProcess* FUN_1409a8b20();

// ---- static initializers (.text$di, in this order) ----
// Light entities added while a world loads (SetLightAddedCallback(QueueLight)); CreateQueuedLights empties it.
// @0x1400f8d70
static std::list<egf::EntityID> s_queuedLights;
#ifndef MS2_HOOK_DLL
// @0x1400f8da0
EE_HANDLER_WRAP(MS2LightService, HandleEntityEnterWorld, egf::EntityChangeMessage, efd::kMSGID_OwnedEntityEnterWorld);
// @0x1400f8e00
EE_HANDLER_WRAP(MS2LightService, HandleEntityExitWorld, egf::EntityChangeMessage, efd::kMSGID_OwnedEntityExitWorld);
#endif
// @0x1400f8e60
static CString s_strSkill = "skill";
// @0x1400f8e90
static CString s_strStun = "stun";
// @0x1400f8ec0
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };     // ctor 0x1401cd100
static Unk_1401cd100 s_pointer(NULL);

// ---------------------------------------------------------------------------------------------------------------
// AddAffectedObjectFunctor: the engine's (LightService.cpp) functor, compiled again into this unit.
// ---------------------------------------------------------------------------------------------------------------
class AddAffectedObjectFunctor :
    public ecr::SceneGraphService::EntitySceneGraphFunctor,
    public ecr::SceneGraphService::HandleSceneGraphFunctor
{
public:
    // @0x1414c78c0
    AddAffectedObjectFunctor(NiLightPtr spLight)
    {
        m_spLight = spLight;
    }

    // @0x1414c7eb0
    ~AddAffectedObjectFunctor()
    {
        m_spLight = 0;
    }

    // @0x1414c8d70
    efd::Bool operator()(const egf::Entity* pEntity, const efd::vector<NiObjectPtr>& objects)
    {
        EE_UNUSED_ARG(pEntity);
        EE_ASSERT(objects.size() > 0);

        NiNode* pNode = NiDynamicCast(NiNode, objects[0]);
        if (pNode)
        {
            if (pNode->AttachEffect(m_spLight))
                pNode->UpdateEffects();
        }

        return false;
    }

    // @0x1414c8cf0
    efd::Bool operator()(const ecr::SceneGraphService::SceneGraphHandle handle,
        const efd::vector<NiObjectPtr>& objects)
    {
        EE_UNUSED_ARG(handle);
        EE_ASSERT(objects.size() > 0);

        NiNode* pNode = NiDynamicCast(NiNode, objects[0]);
        if (pNode)
        {
            if (pNode->AttachEffect(m_spLight))
                pNode->UpdateEffects();
        }

        return false;
    }

    NiLightPtr m_spLight;
};

// @0x1414c6fb0
inline TSingleton<MS2LightService>::TSingleton() { s_instance = static_cast<MS2LightService*>(this); }

// ---------------------------------------------------------------------------------------------------------------
// MS2LightService
// ---------------------------------------------------------------------------------------------------------------

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414bfc40
MS2LightService::MS2LightService()
    : ecr::LightService(true), m_bSortedRelight(false)
{
}
#endif

// @0x1414bfd40
MS2LightService::~MS2LightService()
{
}

// @0x1414bfe10
efd::SyncResult MS2LightService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    efd::SyncResult result = ecr::LightService::OnPreInit(pDependencyRegistrar);
    if (result == efd::SyncResult_Success)
        FUN_1413eb6d0(static_cast<egf::IPropertyCallback*>(this));
    return result;
}
MS2_REPLACE_METHOD(0x1414BFE10, MS2LightService, OnPreInit, 94, 0x4C922F5B);

// @0x1414bfe80
efd::AsyncResult MS2LightService::OnInit()
{
    FUN_1403ed2d0()->FUN_141bbae40(static_cast<IWorldServiceCallback*>(this));
    return ecr::LightService::OnInit();
}
MS2_REPLACE_METHOD(0x1414BFE80, MS2LightService, OnInit, 77, 0x9166F0A9);

// @0x1414bfee0
efd::AsyncResult MS2LightService::OnTick()
{
    if (m_changedLightList.empty() && m_changedNodeList.empty())
        return efd::AsyncResult_Pending;

    if (m_bSortedRelight)
    {
        m_sortAxis = efd::Point3::ZERO;
        RelightScene(false);
    }
    else if (m_enableAutomaticRelighting)
    {
        RelightScene(true);
    }
    m_bSortedRelight = false;
    m_changedLightList.clear();
    m_changedNodeList.clear();
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x1414BFEE0, MS2LightService, OnTick, 233, 0xE3B714E2);

#ifndef MS2_HOOK_DLL
// @0x1414bffd0
void MS2LightService::QueueLight(const egf::EntityID& entityID)
{
    s_queuedLights.push_back(entityID);
}
#endif

// @0x1414c0000
void MS2LightService::OnPropertyUpdate(const efd::ClassID& callerID, egf::Entity* pEntity, const egf::PropertyID& propertyID,
    const egf::IProperty* pProperty, const efd::UInt32 tags)
{
    if (pEntity == 0)
        return;
    if (propertyID == kPropertyID_StandardModelLibrary_Position || propertyID == kPropertyID_StandardModelLibrary_Rotation)
    {
        egf::EntityID entityID = pEntity->GetEntityID();
        efd::map<egf::EntityID, LightData*>::iterator it = m_entityLightMap.find(entityID);
        if (it != m_entityLightMap.end())
            LightEntityChanged(it->second, pEntity);
    }
}
MS2_REPLACE_METHOD_VIA(0x1414C0000, MS2LightService, egf::IPropertyCallback, OnPropertyUpdate, 227, 0x3922D2B1);

// @0x1414c00f0
void MS2LightService::vfunc_0(int nMap)
{
    m_enableAutomaticRelighting = false;
    SetLightAddedCallback(QueueLight);
}

// MS2: the exe's NiDynamicEffect keeps its affected nodes in a NiTPointerMap<NiNode*, NiNode*> (key == value; the
// GetFirstPos/GetNext/RemoveAll COMDATs 0x1414c9250/0x1414c92b0/0x1414c9a20 are NiTMapBase's), the SDK header has a
// NiTPointerList at the same offset. View the member through the exe's type.
typedef NiTPointerMap<NiNode*, NiNode*> AffectedNodeMap;

// @0x1414c0120
void MS2LightService::vfunc_3(int nMap)
{
    m_lightIntensity.clear();
    m_lightShadow.clear();

    for (efd::map<egf::EntityID, LightData*>::iterator it = m_entityLightMap.begin(); it != m_entityLightMap.end(); ++it)
    {
        NiLight* pLight = it->second->m_spLight;
        NiShadowGenerator* pShadowGenerator = pLight->GetShadowGenerator();

        NiPSSMShadowClickGenerator* pPSSMClickGenerator = NiDynamicCast(NiPSSMShadowClickGenerator,
            NiShadowManager::GetActiveShadowClickGenerator());
        if (pPSSMClickGenerator && pShadowGenerator)
        {
            if (pPSSMClickGenerator->GetActiveGenerator() == pShadowGenerator)
                pPSSMClickGenerator->SetActiveGenerator(NULL);

            NiPSSMConfiguration* pConfiguration = pPSSMClickGenerator->GetConfiguration(pShadowGenerator);
            pConfiguration->SetRebuildFrustums(true);
        }

        AffectedNodeMap& affectedNodeMap = (AffectedNodeMap&)pLight->GetAffectedNodeList();
        NiTMapIterator kIter = affectedNodeMap.GetFirstPos();
        while (kIter)
        {
            NiNode* pNode = NULL;
            affectedNodeMap.GetNext(kIter, pNode, pNode);
            if (pNode)
            {
                pNode->DetachEffect(pLight);
                pNode->UpdateEffects();
            }
        }
        affectedNodeMap.RemoveAll();

        pLight->DetachAllAffectedNodes();
        pLight->DetachAllUnaffectedNodes();
        if (pShadowGenerator)
        {
            pShadowGenerator->DetachAllUnaffectedCasterNodes();
            pShadowGenerator->DetachAllUnaffectedReceiverNodes();
            NiShadowManager::DeleteShadowGenerator(pShadowGenerator);
        }
        pLight->AssignShadowGenerator(NULL);
    }
    m_entityLightMap.clear();

    for (efd::vector<LightData*>::iterator itLight = m_lightList.begin(); itLight != m_lightList.end(); itLight++)
    {
        EE_DELETE(*itLight);
    }
    m_lightList.clear();
    m_changedLightList.clear();
}
MS2_REPLACE_METHOD_VIA(0x1414C0120, MS2LightService, IWorldServiceCallback, vfunc_3, 722, 0xFEE50E8E);

// @0x1414c0400
void MS2LightService::vfunc_1(int nMap)
{
    CreateQueuedLights();
    RequestSortedRelight();
}

// @0x1414c0440
void MS2LightService::vfunc_5(int nMap)
{
}

// @0x1414c0450
void MS2LightService::UpdateRelightingMode()
{
    const efd::UInt32 kMaxPointLights = 3;
    const efd::UInt32 kMaxSpotLights = 2;
    const efd::UInt32 kMaxDirectionalLights = 3;
    efd::UInt32 nPointLights = 0;
    efd::UInt32 nSpotLights = 0;
    efd::UInt32 nDirectionalLights = 0;

    for (efd::map<egf::EntityID, LightData*>::iterator it = m_entityLightMap.begin(); it != m_entityLightMap.end(); ++it)
    {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), &it->first);
        if (!pEntity)
            continue;
        const egf::FlatModel* pModel = pEntity->GetModel();
        if (pModel->ContainsModel(kFlatModelID_StandardModelLibrary_PointLight))
            nPointLights++;
        else if (pModel->ContainsModel(kFlatModelID_StandardModelLibrary_SpotLight))
            nSpotLights++;
        else if (pModel->ContainsModel(kFlatModelID_StandardModelLibrary_DirectionalLight))
            nDirectionalLights++;
    }

    m_enableAutomaticRelighting = !(nPointLights <= kMaxPointLights && nSpotLights <= kMaxSpotLights
        && nDirectionalLights <= kMaxDirectionalLights);
}
MS2_REPLACE_METHOD(0x1414C0450, MS2LightService, UpdateRelightingMode, 377, 0x64A06890);

// @0x1414c05d0
void MS2LightService::UpdateLightShadows()
{
    for (efd::map<egf::EntityID, LightData*>::iterator it = m_entityLightMap.begin(); it != m_entityLightMap.end(); ++it)
    {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), &it->first);
        UpdateLightShadow(pEntity);
    }
}
MS2_REPLACE_METHOD(0x1414C05D0, MS2LightService, UpdateLightShadows, 148, 0x161BBE56);

// @0x1414c0670
void MS2LightService::UpdateLightShadow(egf::Entity* pEntity)
{
    if (!pEntity->GetModel()->ContainsModel(kFlatModelID_StandardModelLibrary_Light))
        return;
    if (!pEntity->GetModel()->ContainsModel(kFlatModelID_StandardModelLibrary_ShadowGenerator))
        return;

    int nNeeded = FUN_141376880(FUN_140ae1c00(), 5);
    bool bShadows = FUN_140ae1c10() >= nNeeded;
    std::map<egf::EntityID, bool>::iterator it = m_lightShadow.find(pEntity->GetEntityID());
    bool bKnown = it != m_lightShadow.end();
    if (bShadows)
    {
        // Shadows are on again: restore the light's own value.
        if (bKnown)
            pEntity->SetPropertyValue(kPropertyID_StandardModelLibrary_CastShadows, it->second);
    }
    else
    {
        if (!bKnown)
        {
            bool bCastShadows = false;
            if (pEntity->GetPropertyValue(kPropertyID_StandardModelLibrary_CastShadows, bCastShadows) == PropertyResult_OK)
                m_lightShadow.insert(std::make_pair(pEntity->GetEntityID(), bCastShadows));
        }
        bool bOff = false;
        pEntity->SetPropertyValue(kPropertyID_StandardModelLibrary_CastShadows, bOff);
    }
}
MS2_REPLACE_METHOD(0x1414C0670, MS2LightService, UpdateLightShadow, 393, 0x8A98B89F);

// @0x1414c0800
void MS2LightService::RequestSortedRelight()
{
    m_bSortedRelight = true;
}
MS2_REPLACE_METHOD(0x1414C0800, MS2LightService, RequestSortedRelight, 18, 0x4F8EDC2C);

// @0x1414c0820
void MS2LightService::ScaleLightIntensity(float fScale)
{
    for (efd::map<egf::EntityPtr, float>::iterator it = m_lightIntensity.begin(); it != m_lightIntensity.end(); ++it)
    {
        egf::Entity* pEntity = it->first;
        float fDimmer = it->second * fScale;
        pEntity->SetPropertyValue(kPropertyID_StandardModelLibrary_Dimmer, fDimmer);
    }
}
MS2_REPLACE_METHOD(0x1414C0820, MS2LightService, ScaleLightIntensity, 172, 0x9519E38D);

// @0x1414c08e0
void MS2LightService::HandleEntityEnterWorld(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMessage->GetEntity();
    const egf::FlatModel* pModel = pEntity->GetModel();
    if (!pModel->ContainsModel(kFlatModelID_StandardModelLibrary_Light))
        return;

    float fDimmer = 0.0f;
    if (pEntity->GetPropertyValue(kPropertyID_StandardModelLibrary_Dimmer, fDimmer) != PropertyResult_OK)
        return;

    efd::map<egf::EntityPtr, float>::const_iterator it = m_lightIntensity.find(pEntity);
    if (it == m_lightIntensity.end())
        m_lightIntensity.insert(std::make_pair(pEntity, fDimmer));
    else
        fDimmer = it->second;

    Unk_LightVideoOptions* pVideo = FUN_1409a8b10()->FUN_1409a8ac0();
    bool bDimmed = pVideo->FUN_14125e0b0();
    Unk_LightRenderStep* pStep = FUN_1409a8b20()->FUN_1416a3a90(3);
    if (pStep)
        bDimmed = bDimmed & pStep->FUN_1409a8f00();
    else
        bDimmed = false;
    if (!bDimmed)
    {
        float fBright = fDimmer * 1.1f;
        pEntity->SetPropertyValue(kPropertyID_StandardModelLibrary_Dimmer, fBright);
    }
}
MS2_REPLACE_METHOD(0x1414C08E0, MS2LightService, HandleEntityEnterWorld, 517, 0x0DB379F2);

// @0x1414c0af0
void MS2LightService::HandleEntityExitWorld(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel)
{
    if (!m_lightIntensity.empty())
    {
        egf::Entity* pEntity = pMessage->GetEntity();
        const egf::FlatModel* pModel = pEntity->GetModel();
        if (!pModel->ContainsModel(kFlatModelID_StandardModelLibrary_Light))
            return;
        m_lightIntensity.erase(pEntity);
    }
}
MS2_REPLACE_METHOD(0x1414C0AF0, MS2LightService, HandleEntityExitWorld, 185, 0xBF4B724F);

// @0x1414c0bb0
void MS2LightService::RemoveRenderedEntity(egf::Entity* pEntity, NiAVObject* pAVObject)
{
    if (!FUN_1409f7c90()->IsModelCullingOn())
        return;
    NiNode* pNode = NiDynamicCast(NiNode, pAVObject);
    if (!pNode || !pEntity)
        return;

    // Detach entity from every light.
    for (efd::map<egf::EntityID, LightData*>::iterator iter = m_entityLightMap.begin();
        iter != m_entityLightMap.end(); ++iter)
    {
        iter->second->m_spLight->DetachAffectedNode(pNode);
        iter->second->m_spLight->UpdateEffects();
    }

    const NiTPointerList<NiShadowGeneratorPtr>& shadowGenerators = NiShadowManager::GetShadowGenerators();
    NiTListIterator kIter = shadowGenerators.GetHeadPos();
    while (kIter)
    {
        NiShadowGeneratorPtr spGenerator = shadowGenerators.GetNext(kIter);
        if (spGenerator)
        {
            spGenerator->DetachUnaffectedCasterNode(pNode);
            spGenerator->DetachUnaffectedReceiverNode(pNode);
        }
    }

    pNode->UpdateEffects();

    RemoveReceiverData(pEntity->GetEntityID());
}
MS2_REPLACE_METHOD(0x1414C0BB0, MS2LightService, RemoveRenderedEntity, 421, 0x7C9D8B1A);

#ifndef MS2_HOOK_DLL
// @0x1414c0d60
bool MS2LightService::CreateQueuedLights()
{
    for (std::list<egf::EntityID>::iterator itQueued = s_queuedLights.begin(); itQueued != s_queuedLights.end(); ++itQueued)
    {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), &*itQueued);
        if (!pEntity)
            continue;

        const egf::EntityID& entityID = pEntity->GetEntityID();
        const egf::FlatModel* pModel = pEntity->GetModel();
        NiLight* pLight = CreateLight(pModel);
        UpdateLightProperties(pLight, pEntity);

        // Add to light list (position, radius, id).
        NiPoint3 center = pLight->GetTranslate();

        efd::Float32 range = 100.0f;
        pEntity->GetPropertyValue(kPropertyID_StandardModelLibrary_Range, range);

        LightData* pLightData = EE_NEW LightData();
        if (pLightData)
        {
            // Store light's EntityID, range, and center.
            pLightData->m_entityID = entityID;
            pLightData->m_radius = range;
            pLightData->m_position = center;
            pLightData->m_spLight = pLight;

            m_lightList.push_back(pLightData);
            m_entityLightMap[entityID] = pLightData;
            m_changedLightList.push_back(pLightData);

            // Populate the LightData's priority override map.
            efd::list<efd::utf8string> keyList;
            if (pEntity->GetPropertyKeys(kPropertyID_StandardModelLibrary_AlwaysAffectedByLight,
                keyList) == PropertyResult_OK)
            {
                for (efd::list<efd::utf8string>::iterator iter = keyList.begin();
                    iter != keyList.end();  ++iter)
                {
                    egf::EntityID kAffectedEntityID;
                    pEntity->GetPropertyValue(
                        kPropertyID_StandardModelLibrary_AlwaysAffectedByLight, *iter,
                        kAffectedEntityID);
                    pLightData->m_entityPriorityOverride[kAffectedEntityID] = 100.0f;
                }
            }

            if (pEntity->GetPropertyKeys(kPropertyID_StandardModelLibrary_NeverAffectedByLight,
                keyList) == PropertyResult_OK)
            {
                for (efd::list<efd::utf8string>::iterator iter = keyList.begin();
                    iter != keyList.end(); ++iter)
                {
                    egf::EntityID kAffectedEntityID;
                    pEntity->GetPropertyValue(
                        kPropertyID_StandardModelLibrary_NeverAffectedByLight, *iter,
                        kAffectedEntityID);
                    pLightData->m_entityPriorityOverride[kAffectedEntityID] = 0;
                }
            }
        }

        if (!m_enableAutomaticRelighting)
        {
            // Add all nodes to the light's effect.
            AddAffectedObjectFunctor kFunctor(pLight);
            m_spSceneGraphService->ForEachEntitySceneGraph(kFunctor);
        }

        FUN_1403ed280()->FUN_1411a74a0(entityID, pEntity);
        UpdateShadowCaster(pLight, pEntity);
    }
    s_queuedLights.clear();
    SetLightAddedCallback(0);
    UpdateRelightingMode();
    UpdateLightShadows();
    return true;
}
#endif
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2f10-0x142cb2fb0 .text$yd

// The last function of this TU (gap2: ps1 had split it off; the v2525 TU map ends this TU at 0x1414cf980): a flag
// setter on the post-processing pass objects DepthOfFieldManager toggles (passes 1 and 2 of the list it gets through
// 0x1414cfbe0). Only the flag byte at +0x20 is known.
// MS2-RANGE: 0x1414cf920-0x1414cf940 .text$mn
class Unk_LsPassFlag
{
public:
    void FUN_1414cf920(bool bOn);
private:
    char m_pad_00[0x20];
    bool m_bOn;                                         // +0x20
};

// @0x1414cf920
void Unk_LsPassFlag::FUN_1414cf920(bool bOn)
{
    m_bOn = bOn;
}
MS2_REPLACE_METHOD(0x1414CF920, Unk_LsPassFlag, FUN_1414cf920, 23, 0x698F012D);
