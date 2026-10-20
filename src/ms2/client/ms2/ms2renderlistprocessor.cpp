// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game's shader-sort render-list processor: the engine
// NiShaderSortProcessor bucket logic plus swapped post-processing materials, outlined objects, alpha shell groups and
// depth-sorted alpha objects. Also the render-view and after-image variants.
// MS2-UNIT: ?\ms2renderlistprocessor.cpp
// MS2-RANGE: 0x1400f8ee0-0x1400f9250 .text$di
// MS2-RANGE: 0x1414dbf30-0x1414ea3d0 .text$mn
// MS2-RANGE: 0x142cb30c0-0x142cb3100 .text$yd
// MS2-PIN: ??__Es_pointer3@@YAXXZ 0x1400f9170
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <algorithm>
#include <atlstr.h>
#include "ms2renderlistprocessor.h"
#include "ms2afterimagerenderlistprocessor.h"
#include "ms2/client/ms2/ms2materialswapprocessor.h"
#include "ms2/client/ms2/ms2outerglowmaterialswapprocessor.h"
#include "ms2/client/ms2/ms2outlinepreprocessor.h"
#include "ms2/client/ms2/ms2overdrawprocessor.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/skillcollisionmanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/decoeditservice.h"
#include "hook/ms2hook.h"
#include <NiRenderer.h>
#include <NiRenderObject.h>
#include <NiMesh.h>
#include <NiNode.h>
#include <NiVisibleArray.h>
#include <NiMaterialInstance.h>
#include <NiMaterialLibrary.h>
#include <NiFloatExtraData.h>
#include <NiIntegerExtraData.h>
#include <NiColorExtraData.h>
#include <NiBooleanExtraData.h>
#include <NiStencilProperty.h>
#include <NiAlphaProperty.h>
#include <NiZBufferProperty.h>
#include <NiPropertyState.h>
#include <NiShader.h>
#include <NiFrustum.h>
#include <NiRect.h>
#include <NiPSMeshParticleSystem.h>
#include <NiDX9Renderer.h>
#include <efd/MemHint.h>

// ---- out-of-unit callees ----
// The post-processing service: the materials of the post-process modes and the mode of every scene root.
class Unk_RLPPostProcessSvc
{
public:
    void FUN_1416aa330();                                   // creates the post-process mode materials
    char m_pad0[0x30];
    NiMaterialPtr m_aspMaterial[7];                         // +0x30
    std::map<NiNodePtr, int> m_kRootModes;                  // +0x68
};
Unk_RLPPostProcessSvc* FUN_1409a8b20();
// A material-table entry (see ms2materialswapprocessor.cpp); only its state word (+0x540) is read here. Its exe
// accessor (0x1427542f0) lies in the statically linked runtime range that the hook DLL does not map, so it is inline.
struct Unk_MaterialTable;                                   // DAT_143d69198 (MS2StandardMaterial RTTI)
struct Unk_MaterialEntry
{
    char m_pad[0x540];
    unsigned m_nState;
    bool IsActive() const { return m_nState - 1 <= 2; }
};
extern Unk_MaterialTable DAT_143d69198;
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);   // table lookup, NULL-safe
int FUN_140ef4dd0(Unk_MaterialEntry* pEntry);               // colour-shift mode refresh
extern const NiRTTI DAT_143d691a8;                          // OutlineMaterial::ms_RTTI
extern const NiRTTI DAT_143ad1588;                          // EffectNode::ms_RTTI
extern int DAT_143ae2b34;
extern NiFixedString DAT_143ae5120;                         // outline width (float extra data)
extern NiFixedString DAT_143ae5128;                         // outline colour (colour extra data)
extern NiFixedString DAT_143ae5130;                         // colour-shift float extra data
extern NiFixedString DAT_143ae5138;                         // colour-shift float extra data
extern NiFixedString DAT_143ae5188;                         // render group (float extra data)
extern NiFixedString DAT_143ae50a0;                         // alpha sort mode (integer extra data)
extern NiFixedString DAT_143ae50a8;                         // alpha shell group (integer extra data)
extern NiFixedString DAT_143ae50b0;                         // alpha shell member flag (boolean extra data)
extern NiFixedString DAT_143ae51d0;                         // alpha depth-bias tag
extern NiFixedString DAT_143ae52a8;                         // outline material name
NiNode* FUN_141d15010(NiAVObject* pkObject);                // topmost ancestor of the object
NiNode* FUN_140a0b000(NiAVObject* pkObject);                // parent of the object
float FUN_141b71c50();                                      // depth bias of tagged alpha objects
bool FUN_141568c20(NiRenderObject* pkObject);
bool FUN_141568c90(NiRenderObject* pkObject);
int FUN_141568e90(NiRenderObject* pkObject);                // outline allowed
int FUN_1415690c0(NiRenderObject* pkObject);                // alpha depth bias tag
bool FUN_14098dfc0(NiAVObject* pkObject);
void FUN_1410479a0(NiObjectNET* pkObject, const NiFixedString& kName, const NiColor& kColor);   // set colour extra data
CSkillCollisionManager* FUN_141469a90();
WorldService* FUN_1403ed2d0();
DecoEditService* FUN_1411987a0();

// ---- file-scope statics (.text$di) -------------------------------------------------------------------------------------
// This range also holds the initializers of the neighbouring processor TUs (their RTTI objects and the header statics every
// one of them carries: the condition table, the skill/stun labels, a condition map, a null handle).
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

#ifndef MS2_HOOK_DLL   // the exe's own RTTI objects are the registered ones
// @0x1400f8ee0
const NiRTTI MS2MaterialSwapProcessor::ms_RTTI("MS2MaterialSwapProcessor", &MS2RenderListProcessor::ms_RTTI);
// @0x1400f8f10
static NiRTTI s_rttiOuterGlow("MS2OuterGlowMaterialSwapProcessor", &MS2RenderListProcessor::ms_RTTI);
// @0x1400f8f40
const NiRTTI MS2OutlinePreProcessor::ms_RTTI("MS2OutlinePreProcessor", &MS2RenderListProcessor::ms_RTTI);
#endif
static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1("skill");
static CString s_strStun1("stun");
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
#ifndef MS2_HOOK_DLL
// @0x1400f90e0
const NiRTTI MS2OverdrawProcessor::ms_RTTI("MS2OverdrawProcessor", &MS2RenderListProcessor::ms_RTTI);
#endif
static CString s_strSkill2("skill");
static CString s_strStun2("stun");
static Unk_1401cd100 s_pointer3(NULL);
// @0x1400f9190
static CString s_skill("skill");
// @0x1400f91c0
static CString s_stun("stun");
static CString s_strSkill4("skill");
static CString s_strStun4("stun");

// @0x1414dbf30
MS2RenderListProcessor::MS2RenderListProcessor()
    : m_spMaterial(0)
{
    FUN_1409a8b20()->FUN_1416aa330();
    m_spMaterial = 0;
    m_ppkSortedAlpha = 0;
    m_pkAlphaObjects = 0;
    m_uiAllocatedAlpha = 0;
    m_bOutlineColor = true;
    SetSortByClosestPoint(true);
}

// @0x1414dc020
MS2RenderListProcessor::~MS2RenderListProcessor()
{
    m_spMaterial = 0;
    NiFree(m_ppkSortedAlpha);
    NiDelete[] m_pkAlphaObjects;
}

// MS2-FUNCTIONAL: bytes identical; only the NiPoint3 default-ctor call differs from the symbol map (exe calls 0x1405522f0,
// the real NiPoint3() that chains to Point3(); progress/symbols.tsv maps ??0NiPoint3@@QEAA@XZ to 0x1402bd040 = Point3()).
// @0x1414dc0d0
void MS2RenderListProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (!pkInput)
        return;

    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiDX9Renderer* pkDX9Renderer = NiDynamicCast(NiDX9Renderer, pkRenderer);
    if (pkDX9Renderer && pkDX9Renderer->IsDeviceLost())
        return;

    m_kExtraAlphaObjects.clear();

    NiPoint3 kWorldLoc, kWorldDir, kWorldUp, kWorldRight;
    NiFrustum kFrustum;
    NiRect<float> kViewport;
    pkRenderer->GetCameraData(kWorldLoc, kWorldDir, kWorldUp, kWorldRight, kFrustum, kViewport);

    const unsigned int uiInputCount = pkInput->GetCount();
    if (m_uiAllocatedAlpha < uiInputCount)
    {
        NiFree(m_ppkSortedAlpha);
        m_ppkSortedAlpha = NiAlloc(AlphaComponent*, uiInputCount);
        NiDelete[] m_pkAlphaObjects;
        m_pkAlphaObjects = NiNew AlphaObject[uiInputCount];
        m_uiAllocatedAlpha = uiInputCount;
    }

    ClearBuckets();
    ClearNodePool();
    ClearPerEffectBucketPool();
    m_kNoSortVisibleArray.RemoveAll();

    MS2SavedMaterialMap kSaved(37);
    NiVisibleArray kOutline;
    MS2AlphaShellMap kShells;
    unsigned int uiDepthIndex = 0;
    float fBias = FUN_141b71c50();
    for (unsigned int ui = 0; ui < uiInputCount; ui++)
    {
        NiRenderObject& kMesh = pkInput->GetAt(ui);
        NiPSMeshParticleSystem* pkParticles = NiDynamicCast(NiPSMeshParticleSystem, &kMesh);
        if (pkParticles)
            continue;
        if (FUN_141568c20(&kMesh))
            continue;
        if (FUN_141568c90(&kMesh))
            continue;

        ApplyEffectMaterial(&kMesh, kSaved);
        if (!pkRenderer->PrecacheShader(&kMesh))
            continue;

        if (IsTransparent(kMesh))
        {
            NiIntegerExtraData* pkShellGroup = NiDynamicCast(NiIntegerExtraData, kMesh.GetExtraData(DAT_143ae50a8));
            if (!pkShellGroup)
            {
                if (kMesh.GetSortObject())
                {
                    float fDepth = ComputeDepth(kMesh, kWorldDir);
                    NiIntegerExtraData* pkSortMode = NiDynamicCast(NiIntegerExtraData, kMesh.GetExtraData(DAT_143ae50a0));
                    if (pkSortMode)
                    {
                        fDepth = (kWorldLoc - kMesh.GetWorldBound().GetCenter()).Length();
                        bool bSorted = false;
                        int iMode = pkSortMode->GetValue();
                        switch (iMode)
                        {
                        case 0:
                            bSorted = true;
                            break;
                        case 1:
                            fDepth += 1000.0f;
                            break;
                        }
                        AlphaObject kObject;
                        kObject.Set(&kMesh, fDepth);
                        m_kExtraAlphaObjects.push_back(kObject);
                        if (!bSorted)
                            continue;
                    }

                    int bBias = 0;
                    if (DAT_143ae2b34)
                        bBias = FUN_1415690c0(&kMesh);
                    else
                        bBias = kMesh.GetExtraData(DAT_143ae51d0) != 0;
                    if (bBias)
                        fDepth += fBias;
                    m_pkAlphaObjects[uiDepthIndex++].Set(&kMesh, fDepth);
                    continue;
                }
            }
            else
            {
                int iGroup = pkShellGroup->GetValue();
                bool bExists = kShells.find(iGroup) != kShells.end();
                AlphaShellComposite& kShell = kShells[iGroup];
                if (!bExists)
                    kShell.Clear();
                NiBooleanExtraData* pkMember = NiDynamicCast(NiBooleanExtraData, kMesh.GetExtraData(DAT_143ae50b0));
                if (pkMember && pkMember->GetValue())
                    kShell.AddObject(&kMesh);
                else
                    kShell.AddShell(&kMesh);
                continue;
            }
        }

        if (!kMesh.GetSortObject())
        {
            m_kNoSortVisibleArray.Add(kMesh);
            continue;
        }

        int bOutline = 1;
        if (DAT_143ae2b34)
            bOutline = FUN_141568e90(&kMesh);
        if (bOutline)
        {
            NiFloatExtraData* pkWidth = NiDynamicCast(NiFloatExtraData, kMesh.GetExtraData(DAT_143ae5120));
            if (pkWidth && pkWidth->GetValue() > 0.0f)
            {
                kOutline.Add(kMesh);
                continue;
            }
        }

        NiMaterialInstance* pkSrcMatInst = (NiMaterialInstance*)kMesh.GetActiveMaterialInstance();

        NiUInt32 uiKeyID;
        for (uiKeyID = 0; uiKeyID < m_uiActiveBuckets; uiKeyID++)
        {
            RenderObjectBucket& kBucket = *m_kMeshBuckets.GetAt(uiKeyID);

            if (!kBucket.m_pkMatInstanceKey)
                continue;

            NiMaterialInstance* pkCmpMatInst = kBucket.m_pkMatInstanceKey;
            const NiRenderObject* pkFirst = kBucket.m_pkRenderObjectList->m_pkRenderObject;

            if (pkSrcMatInst->ShaderEquals(pkCmpMatInst) &&
               ((!pkFirst->GetEffectState()) == (!kMesh.GetEffectState())))
            {
                break;
            }
        }

        RenderObjectNode* pkNode = GetFreeRONode();
        pkNode->m_pkRenderObject = &kMesh;

        if (uiKeyID == m_uiActiveBuckets)
        {
            pkNode->m_pkNext = NULL;

            PerEffectBucket* pkSubBucket = GetFreePerEffectBucket();
            pkSubBucket->m_pkHead = pkNode;
            pkSubBucket->m_pkTail = pkNode;

            RenderObjectBucket* pkBucket = GetFreeBucket();
            pkBucket->m_pkMatInstanceKey = pkSrcMatInst;
            pkBucket->m_pkRenderObjectList = pkNode;
            pkBucket->m_pkEffectStateMap->SetAt(kMesh.GetEffectState(), pkSubBucket);
        }
        else
        {
            RenderObjectBucket& kBucket = *m_kMeshBuckets.GetAt(uiKeyID);

            PerEffectBucket* pkSubBucket = NULL;
            kBucket.m_pkEffectStateMap->GetAt(kMesh.GetEffectState(), pkSubBucket);

            if (pkSubBucket != NULL)
            {
                RenderObjectNode* pkOldTail = pkSubBucket->m_pkTail;
                pkNode->m_pkNext = pkOldTail->m_pkNext;
                pkOldTail->m_pkNext = pkNode;
                pkSubBucket->m_pkTail = pkNode;
            }
            else
            {
                pkSubBucket = GetFreePerEffectBucket();
                pkSubBucket->m_pkHead = pkNode;
                pkSubBucket->m_pkTail = pkNode;
                kBucket.m_pkEffectStateMap->SetAt(kMesh.GetEffectState(), pkSubBucket);

                pkNode->m_pkNext = kBucket.m_pkRenderObjectList;
                kBucket.m_pkRenderObjectList = pkNode;
            }
        }
    }

    for (NiUInt32 uiBucketID = 0; uiBucketID < m_uiActiveBuckets; uiBucketID++)
    {
        RenderObjectBucket& kBucket = *m_kMeshBuckets.GetAt(uiBucketID);

        NiRenderObject* pkMesh = kBucket.m_pkRenderObjectList->m_pkRenderObject;
        const NiMaterialInstance* pkMatInst = pkMesh->GetActiveMaterialInstance();
        if (!pkMatInst)
            continue;

        m_kTempVisibleArray.RemoveAll();
        RenderObjectNode* pkRONode = kBucket.m_pkRenderObjectList;
        while (pkRONode)
        {
            m_kTempVisibleArray.Add(*pkRONode->m_pkRenderObject);
            pkRONode = pkRONode->m_pkNext;
        }

        NiShader* pkShader = pkMatInst->GetCachedShader();
        if (pkShader)
            pkShader->RenderMeshes(&m_kTempVisibleArray);
    }

    RenderNoSortList(pkRenderer);
    RenderOutlines(kOutline, pkRenderer);
    RenderAlphaList(uiDepthIndex, kShells, kWorldDir);
    if (FUN_141469a90())
        FUN_141469a90()->Tick();
    FUN_1403ed2d0()->FUN_141bc12b0();
    FUN_1411987a0()->ApplyBrush();
    m_kNoSortVisibleArray.RemoveAll();
    RestoreMaterials(kSaved);
}
MS2_REPLACE_METHOD(0x1414DC0D0, MS2RenderListProcessor, PreRenderProcessList, 3423, 0x32C81A0B);

// MS2-FUNCTIONAL: code identical; the GetValueColor3 return temp sits at rsp+0x88 (exe +0x84), frame 0xa8 vs 0x98.
// @0x1414dce40
void MS2RenderListProcessor::RenderOutlines(NiVisibleArray& kList, NiRenderer* pkRenderer)
{
    const unsigned int uiCount = kList.GetCount();
    for (unsigned int ui = 0; ui < uiCount; ui++)
    {
        NiRenderObject* pkObject = &kList.GetAt(ui);
        NiColor kSavedColor(NiColor::BLACK);
        if (!m_bOutlineColor)
        {
            NiColorExtraData* pkColor = NiDynamicCast(NiColorExtraData, pkObject->GetExtraData(DAT_143ae5128));
            if (pkColor)
                kSavedColor = pkColor->GetValueColor3();
            NiColor kBlack(NiColor::BLACK);
            FUN_1410479a0(pkObject, DAT_143ae5128, kBlack);
        }

        NiMaterial* pkOriginal = pkObject->GetActiveMaterialInstance()->GetMaterial();
        NiMaterial* pkOutline = 0;
        for (unsigned int uj = 0; uj < pkObject->GetMaterialCount(); uj++)
        {
            pkOutline = NiMaterial::DynamicCast(&DAT_143d691a8, pkObject->GetMaterialInstance(uj)->GetMaterial());
            if (pkOutline)
                break;
        }
        if (!pkOutline)
        {
            NiMaterial* pkCreated = NiMaterialLibrary::CreateMaterial(DAT_143ae52a8);
            pkOutline = NiMaterial::DynamicCast(&DAT_143d691a8, pkCreated);
        }

        NiStencilProperty* pkStencil = pkObject->GetPropertyState()->GetStencil();
        NiStencilProperty::DrawMode eDrawMode = pkStencil->GetDrawMode();
        pkStencil->SetDrawMode(NiStencilProperty::DRAW_CW);
        pkObject->ApplyAndSetActiveMaterial(pkOutline);
        NiMaterialInstance* pkInstance = (NiMaterialInstance*)pkObject->GetActiveMaterialInstance();
        pkInstance->ClearCachedShader();
        pkObject->SetMaterialNeedsUpdate(true);
        pkObject->RenderImmediate(pkRenderer);

        pkStencil->SetDrawMode(eDrawMode);
        pkObject->ApplyAndSetActiveMaterial(pkOriginal);
        pkInstance = (NiMaterialInstance*)pkObject->GetActiveMaterialInstance();
        pkInstance->ClearCachedShader();
        pkObject->SetMaterialNeedsUpdate(true);
        pkObject->RenderImmediate(pkRenderer);

        if (!m_bOutlineColor)
            FUN_1410479a0(pkObject, DAT_143ae5128, kSavedColor);
    }
}
MS2_REPLACE_METHOD(0x1414DCE40, MS2RenderListProcessor, RenderOutlines, 714, 0x8DE59773);

// @0x1414dd110
void MS2RenderListProcessor::RenderGroups(const NiVisibleArray* pkInput)
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    const unsigned int uiCount = pkInput->GetCount();
    MS2RenderGroupMap kGroups;
    for (unsigned int ui = 0; ui < uiCount; ui++)
    {
        NiRenderObject& kObject = pkInput->GetAt(ui);
        NiFloatExtraData* pkGroup = NiDynamicCast(NiFloatExtraData, kObject.GetExtraData(DAT_143ae5188));
        if (pkGroup)
        {
            float fGroup = pkGroup->GetValue();
            efd::vector<NiRenderObject*>* pkList = kGroups[fGroup];
            if (!pkList)
            {
                pkList = new efd::vector<NiRenderObject*>;
                kGroups[fGroup] = pkList;
            }
            pkList->push_back(&kObject);
        }
    }

    MS2RenderGroupMap::iterator it = kGroups.begin();
    MS2RenderGroupMap::iterator itEnd = kGroups.end();
    for (; it != itEnd; ++it)
    {
        efd::vector<NiRenderObject*>* pkList = it->second;
        if (pkList)
        {
            size_t uiSize = pkList->size();
            for (size_t uj = 0; uj < uiSize; uj++)
            {
                NiRenderObject* pkObject = (*pkList)[uj];
                NiPropertyState* pkState = pkObject->GetPropertyState();
                NiZBufferProperty* pkZBuffer = pkState->GetZBuffer();
                NiAlphaProperty* pkAlpha = pkState->GetAlpha();
                if (pkZBuffer && pkAlpha)
                {
                    pkAlpha->SetSrcBlendMode(NiAlphaProperty::ALPHA_ZERO);
                    pkAlpha->SetDestBlendMode(NiAlphaProperty::ALPHA_ONE);
                    pkZBuffer->SetTestFunction(NiZBufferProperty::TEST_LESSEQUAL);
                    pkObject->RenderImmediate(pkRenderer);
                }
            }
            for (size_t uj = 0; uj < uiSize; uj++)
            {
                NiRenderObject* pkObject = (*pkList)[uj];
                NiPropertyState* pkState = pkObject->GetPropertyState();
                NiZBufferProperty* pkZBuffer = pkState->GetZBuffer();
                NiAlphaProperty* pkAlpha = pkState->GetAlpha();
                if (pkZBuffer && pkAlpha)
                {
                    pkAlpha->SetSrcBlendMode(NiAlphaProperty::ALPHA_SRCALPHA);
                    pkAlpha->SetDestBlendMode(NiAlphaProperty::ALPHA_INVSRCALPHA);
                    pkZBuffer->SetTestFunction(NiZBufferProperty::TEST_LESSEQUAL);
                    pkObject->RenderImmediate(pkRenderer);
                }
            }
            pkList->clear();
            delete pkList;
        }
    }
    kGroups.clear();
}
MS2_REPLACE_METHOD(0x1414DD110, MS2RenderListProcessor, RenderGroups, 1101, 0x3C36AA58);

// @0x1414dd570
void MS2RenderListProcessor::ApplyEffectMaterial(NiRenderObject* pkObject, MS2SavedMaterialMap& kSaved)
{
    Unk_MaterialEntry* pkEntry = FUN_140a17af0(&DAT_143d69198, pkObject->GetActiveMaterial());
    if (!pkEntry)
        return;
    if (!pkEntry->IsActive())
        return;

    std::map<NiNodePtr, int>::const_iterator it = FUN_1409a8b20()->m_kRootModes.find(FUN_141d15010(pkObject));
    if (it == FUN_1409a8b20()->m_kRootModes.end())
        return;

    int iMode = it->second;
    if (iMode >= 0 && iMode < 7)
    {
        if (iMode == 4)
        {
            if (!NiDynamicCast(NiFloatExtraData, pkObject->GetExtraData(DAT_143ae5130)))
                pkObject->AddExtraData(DAT_143ae5130, NiNew NiFloatExtraData(0.3f));
            if (!NiDynamicCast(NiFloatExtraData, pkObject->GetExtraData(DAT_143ae5138)))
                pkObject->AddExtraData(DAT_143ae5138, NiNew NiFloatExtraData(0.7f));
            if (FUN_140ef4dd0(pkEntry) == 2)
                iMode = 5;
        }
        else
        {
            SaveMaterial(kSaved, pkObject);
            pkObject->ApplyAndSetActiveMaterial(FUN_1409a8b20()->m_aspMaterial[iMode]);
        }
    }
}
MS2_REPLACE_METHOD(0x1414DD570, MS2RenderListProcessor, ApplyEffectMaterial, 702, 0x4CB4BA61);

// @0x1414dd840
void MS2RenderListProcessor::RestoreMaterials(MS2SavedMaterialMap& kSaved)
{
    if (FUN_1409a8b20()->m_kRootModes.size() == 0)
        return;

    NiTMapIterator pos = kSaved.GetFirstPos();
    while (pos != 0)
    {
        NiRenderObject* pkObject;
        const NiMaterial* pkMaterial;
        kSaved.GetNext(pos, pkObject, pkMaterial);
        pkObject->SetActiveMaterial(pkMaterial);
    }
    kSaved.RemoveAll();
}
MS2_REPLACE_METHOD(0x1414DD840, MS2RenderListProcessor, RestoreMaterials, 118, 0x39F9D86F);

// @0x1414dd8c0
void MS2RenderListProcessor::SaveMaterial(MS2SavedMaterialMap& kSaved, NiRenderObject* pkObject)
{
    const NiMaterial* pkMaterial;
    if (!kSaved.GetAt(pkObject, pkMaterial))
    {
        pkMaterial = pkObject->GetActiveMaterial();
        kSaved.SetAt(pkObject, pkMaterial);
    }
}
MS2_REPLACE_METHOD(0x1414DD8C0, MS2RenderListProcessor, SaveMaterial, 86, 0xB9F46BDA);

// @0x1414dd920
void MS2RenderListProcessor::CompleteModifiers(NiAVObject* pkObject)
{
    NiSyncArgs kArgs;
    kArgs.m_uiSubmitPoint = NiSyncArgs::SYNC_ANY;
    kArgs.m_uiCompletePoint = NiSyncArgs::SYNC_RENDER;
    NiMesh* pkMesh = NiDynamicCast(NiMesh, pkObject);
    if (pkMesh)
    {
        pkMesh->CompleteModifiers(&kArgs);
    }
    else
    {
        NiPSMeshParticleSystem* pkSystem = NiDynamicCast(NiPSMeshParticleSystem, pkObject);
        if (pkSystem)
            pkSystem->CompleteModifiers(&kArgs);
    }
}
MS2_REPLACE_METHOD(0x1414DD920, MS2RenderListProcessor, CompleteModifiers, 131, 0xC77B5E7D);

// @0x1414dd9b0
void MS2RenderListProcessor::DisableOutlineColor()
{
    m_bOutlineColor = false;
}
MS2_REPLACE_METHOD(0x1414DD9B0, MS2RenderListProcessor, DisableOutlineColor, 18, 0xFEF2AEF2);

// @0x1414dd9d0
float MS2RenderListProcessor::ComputeDepth(const NiRenderObject& kGeometry, const NiPoint3& kDir)
{
    NiBound kBound = kGeometry.GetWorldBound();
    float fDepth = kBound.GetCenter() * kDir;
    if (m_bSortByClosestPoint)
        fDepth -= kBound.GetRadius();
    return fDepth;
}
MS2_REPLACE_METHOD(0x1414DD9D0, MS2RenderListProcessor, ComputeDepth, 133, 0x5A0424E2);

// @0x1414dda60
void MS2RenderListProcessor::RenderNoSortList(NiRenderer* pkRenderer)
{
    const unsigned int uiCount = m_kNoSortVisibleArray.GetCount();
    for (unsigned int ui = 0; ui < uiCount; ui++)
    {
        NiRenderObject& kObject = m_kNoSortVisibleArray.GetAt(ui);
        NiRenderObject* pkObject = &kObject;
        pkObject->RenderImmediate(pkRenderer);
    }
}
MS2_REPLACE_METHOD(0x1414DDA60, MS2RenderListProcessor, RenderNoSortList, 132, 0x1F8D19E3);

// Sort predicate of the alpha components: the most opaque (deepest) first.
static bool CompareAlpha(AlphaComponent* pkA, AlphaComponent* pkB);

// Extra alpha objects sort by their alpha value (std::less over the list).
inline bool operator<(const AlphaObject& kA, const AlphaObject& kB)
{
    return kA.m_fAlpha < kB.m_fAlpha;
}

// @0x1414ddaf0
void MS2RenderListProcessor::RenderAlphaList(unsigned int uiCount, MS2AlphaShellMap& kShells, NiPoint3 kDir)
{
    unsigned int ui = 0;
    while (ui < uiCount)
    {
        m_ppkSortedAlpha[ui] = &m_pkAlphaObjects[ui];
        ui++;
    }
    for (MS2AlphaShellMap::iterator it = kShells.begin(); it != kShells.end(); ++it)
    {
        it->second.Update(&kDir);
        m_ppkSortedAlpha[ui] = &it->second;
        ui++;
    }
    std::sort(m_ppkSortedAlpha, m_ppkSortedAlpha + ui, CompareAlpha);
    m_kExtraAlphaObjects.sort();
    for (std::list<AlphaObject>::reverse_iterator it = m_kExtraAlphaObjects.rbegin(); it != m_kExtraAlphaObjects.rend(); ++it)
        it->vfunc_0();
    for (unsigned int uj = 0; uj < ui; uj++)
        m_ppkSortedAlpha[uj]->vfunc_0();
}
MS2_REPLACE_METHOD(0x1414DDAF0, MS2RenderListProcessor, RenderAlphaList, 488, 0xB09BD833);

// MS2-FUNCTIONAL: bytes identical; only the NiPoint3 default-ctor call differs from the symbol map (exe calls 0x1405522f0,
// the real NiPoint3() that chains to Point3(); progress/symbols.tsv maps ??0NiPoint3@@QEAA@XZ to 0x1402bd040 = Point3()).
// @0x1414ddce0
void MS2RenderViewRenderListProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (!pkInput)
        return;

    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiDX9Renderer* pkDX9Renderer = NiDynamicCast(NiDX9Renderer, pkRenderer);
    if (pkDX9Renderer && pkDX9Renderer->IsDeviceLost())
        return;

    m_kExtraAlphaObjects.clear();

    NiPoint3 kWorldLoc, kWorldDir, kWorldUp, kWorldRight;
    NiFrustum kFrustum;
    NiRect<float> kViewport;
    pkRenderer->GetCameraData(kWorldLoc, kWorldDir, kWorldUp, kWorldRight, kFrustum, kViewport);

    float fBias = FUN_141b71c50();
    const unsigned int uiInputCount = pkInput->GetCount();
    if (m_uiAllocatedAlpha < uiInputCount)
    {
        NiFree(m_ppkSortedAlpha);
        m_ppkSortedAlpha = NiAlloc(AlphaComponent*, uiInputCount);
        NiDelete[] m_pkAlphaObjects;
        m_pkAlphaObjects = NiNew AlphaObject[uiInputCount];
        m_uiAllocatedAlpha = uiInputCount;
    }

    ClearBuckets();
    ClearNodePool();
    ClearPerEffectBucketPool();
    m_kNoSortVisibleArray.RemoveAll();

    MS2SavedMaterialMap kSaved(37);
    NiVisibleArray kOutline;
    MS2AlphaShellMap kShells;
    unsigned int uiDepthIndex = 0;
    for (unsigned int ui = 0; ui < uiInputCount; ui++)
    {
        NiRenderObject& kMesh = pkInput->GetAt(ui);
        NiPSMeshParticleSystem* pkParticles = NiDynamicCast(NiPSMeshParticleSystem, &kMesh);
        if (pkParticles)
            continue;
        if (FUN_141568c20(&kMesh))
            continue;

        ApplyEffectMaterial(&kMesh, kSaved);
        if (!pkRenderer->PrecacheShader(&kMesh))
            continue;

        if (IsTransparent(kMesh))
        {
            NiIntegerExtraData* pkShellGroup = NiDynamicCast(NiIntegerExtraData, kMesh.GetExtraData(DAT_143ae50a8));
            if (!pkShellGroup)
            {
                if (kMesh.GetSortObject())
                {
                    float fDepth = ComputeDepth(kMesh, kWorldDir);
                    NiIntegerExtraData* pkSortMode = NiDynamicCast(NiIntegerExtraData, kMesh.GetExtraData(DAT_143ae50a0));
                    if (pkSortMode)
                    {
                        fDepth = (kWorldLoc - kMesh.GetWorldBound().GetCenter()).Length();
                        bool bSorted = false;
                        int iMode = pkSortMode->GetValue();
                        switch (iMode)
                        {
                        case 0:
                            bSorted = true;
                            break;
                        case 1:
                            fDepth += 1000.0f;
                            break;
                        }
                        AlphaObject kObject;
                        kObject.Set(&kMesh, fDepth);
                        m_kExtraAlphaObjects.push_back(kObject);
                        if (!bSorted)
                            continue;
                    }

                    int bBias = 0;
                    if (DAT_143ae2b34)
                        bBias = FUN_1415690c0(&kMesh);
                    else
                        bBias = kMesh.GetExtraData(DAT_143ae51d0) != 0;
                    if (bBias)
                        fDepth += fBias;
                    m_pkAlphaObjects[uiDepthIndex++].Set(&kMesh, fDepth);
                    continue;
                }
            }
            else
            {
                int iGroup = pkShellGroup->GetValue();
                bool bExists = kShells.find(iGroup) != kShells.end();
                AlphaShellComposite& kShell = kShells[iGroup];
                if (!bExists)
                    kShell.Clear();
                NiBooleanExtraData* pkMember = NiDynamicCast(NiBooleanExtraData, kMesh.GetExtraData(DAT_143ae50b0));
                if (pkMember && pkMember->GetValue())
                    kShell.AddObject(&kMesh);
                else
                    kShell.AddShell(&kMesh);
                continue;
            }
        }

        if (!kMesh.GetSortObject())
        {
            m_kNoSortVisibleArray.Add(kMesh);
            continue;
        }

        int bOutline = 1;
        if (DAT_143ae2b34)
            bOutline = FUN_141568e90(&kMesh);
        if (bOutline)
        {
            NiFloatExtraData* pkWidth = NiDynamicCast(NiFloatExtraData, kMesh.GetExtraData(DAT_143ae5120));
            if (pkWidth && pkWidth->GetValue() > 0.0f)
            {
                kOutline.Add(kMesh);
                continue;
            }
        }

        NiMaterialInstance* pkSrcMatInst = (NiMaterialInstance*)kMesh.GetActiveMaterialInstance();

        NiUInt32 uiKeyID;
        for (uiKeyID = 0; uiKeyID < m_uiActiveBuckets; uiKeyID++)
        {
            RenderObjectBucket& kBucket = *m_kMeshBuckets.GetAt(uiKeyID);

            if (!kBucket.m_pkMatInstanceKey)
                continue;

            NiMaterialInstance* pkCmpMatInst = kBucket.m_pkMatInstanceKey;
            const NiRenderObject* pkFirst = kBucket.m_pkRenderObjectList->m_pkRenderObject;

            if (pkSrcMatInst->ShaderEquals(pkCmpMatInst) &&
               ((!pkFirst->GetEffectState()) == (!kMesh.GetEffectState())))
            {
                break;
            }
        }

        RenderObjectNode* pkNode = GetFreeRONode();
        pkNode->m_pkRenderObject = &kMesh;

        if (uiKeyID == m_uiActiveBuckets)
        {
            pkNode->m_pkNext = NULL;

            PerEffectBucket* pkSubBucket = GetFreePerEffectBucket();
            pkSubBucket->m_pkHead = pkNode;
            pkSubBucket->m_pkTail = pkNode;

            RenderObjectBucket* pkBucket = GetFreeBucket();
            pkBucket->m_pkMatInstanceKey = pkSrcMatInst;
            pkBucket->m_pkRenderObjectList = pkNode;
            pkBucket->m_pkEffectStateMap->SetAt(kMesh.GetEffectState(), pkSubBucket);
        }
        else
        {
            RenderObjectBucket& kBucket = *m_kMeshBuckets.GetAt(uiKeyID);

            PerEffectBucket* pkSubBucket = NULL;
            kBucket.m_pkEffectStateMap->GetAt(kMesh.GetEffectState(), pkSubBucket);

            if (pkSubBucket != NULL)
            {
                RenderObjectNode* pkOldTail = pkSubBucket->m_pkTail;
                pkNode->m_pkNext = pkOldTail->m_pkNext;
                pkOldTail->m_pkNext = pkNode;
                pkSubBucket->m_pkTail = pkNode;
            }
            else
            {
                pkSubBucket = GetFreePerEffectBucket();
                pkSubBucket->m_pkHead = pkNode;
                pkSubBucket->m_pkTail = pkNode;
                kBucket.m_pkEffectStateMap->SetAt(kMesh.GetEffectState(), pkSubBucket);

                pkNode->m_pkNext = kBucket.m_pkRenderObjectList;
                kBucket.m_pkRenderObjectList = pkNode;
            }
        }
    }

    for (NiUInt32 uiBucketID = 0; uiBucketID < m_uiActiveBuckets; uiBucketID++)
    {
        RenderObjectBucket& kBucket = *m_kMeshBuckets.GetAt(uiBucketID);

        NiRenderObject* pkMesh = kBucket.m_pkRenderObjectList->m_pkRenderObject;
        const NiMaterialInstance* pkMatInst = pkMesh->GetActiveMaterialInstance();
        if (!pkMatInst)
            continue;

        m_kTempVisibleArray.RemoveAll();
        RenderObjectNode* pkRONode = kBucket.m_pkRenderObjectList;
        while (pkRONode)
        {
            m_kTempVisibleArray.Add(*pkRONode->m_pkRenderObject);
            pkRONode = pkRONode->m_pkNext;
        }

        NiShader* pkShader = pkMatInst->GetCachedShader();
        if (pkShader)
            pkShader->RenderMeshes(&m_kTempVisibleArray);
    }

    const unsigned int uiNoSortCount = m_kNoSortVisibleArray.GetCount();
    for (unsigned int ui = 0; ui < uiNoSortCount; ui++)
    {
        NiRenderObject& kObject = m_kNoSortVisibleArray.GetAt(ui);
        NiRenderObject* pkObject = &kObject;
        pkObject->RenderImmediate(pkRenderer);
    }

    RenderOutlines(kOutline, pkRenderer);

    unsigned int uiSorted = 0;
    while (uiSorted < uiDepthIndex)
    {
        m_ppkSortedAlpha[uiSorted] = &m_pkAlphaObjects[uiSorted];
        uiSorted++;
    }
    for (MS2AlphaShellMap::iterator it = kShells.begin(); it != kShells.end(); ++it)
    {
        it->second.Update(&kWorldDir);
        m_ppkSortedAlpha[uiSorted] = &it->second;
        uiSorted++;
    }
    std::sort(m_ppkSortedAlpha, m_ppkSortedAlpha + uiSorted, CompareAlpha);
    m_kExtraAlphaObjects.sort();
    for (std::list<AlphaObject>::reverse_iterator it = m_kExtraAlphaObjects.rbegin(); it != m_kExtraAlphaObjects.rend(); ++it)
        it->vfunc_0();
    for (unsigned int uj = 0; uj < uiSorted; uj++)
        m_ppkSortedAlpha[uj]->vfunc_0();

    m_kNoSortVisibleArray.RemoveAll();
    RestoreMaterials(kSaved);
}
MS2_REPLACE_METHOD(0x1414DDCE0, MS2RenderViewRenderListProcessor, PreRenderProcessList, 3997, 0xB84D67D1);

// @0x1414dec90
MS2AfterImageRenderListProcessor::MS2AfterImageRenderListProcessor()
{
}

// Whether the object or one of its ancestors is an effect node.
static bool IsUnderEffectNode(NiAVObject* pkObject);

// @0x1414decd0
void MS2AfterImageRenderListProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (!pkInput)
        return;

    NiVisibleArray kList;
    for (size_t ui = 0; ui < pkInput->GetCount(); ui++)
    {
        NiRenderObject* pkObject = &pkInput->GetAt((unsigned int)ui);
        if (FUN_14098dfc0(pkObject))
            continue;
        if (!IsUnderEffectNode(pkObject))
            kList.Add(*pkObject);
    }
    MS2RenderListProcessor::PreRenderProcessList(&kList, kOutput, pvExtraData);
}
MS2_REPLACE_METHOD(0x1414DECD0, MS2AfterImageRenderListProcessor, PreRenderProcessList, 213, 0xDA950315);

// @0x1414dedb0
static bool IsUnderEffectNode(NiAVObject* pkObject)
{
    while (pkObject)
    {
        if (NiObject::IsKindOf(&DAT_143ad1588, pkObject))
            return true;
        pkObject = FUN_140a0b000(pkObject);
    }
    return false;
}
MS2_REPLACE(0x1414DEDB0, IsUnderEffectNode, 69, 0x5A60BE20);

// @0x1414dee00
static bool CompareAlpha(AlphaComponent* pkA, AlphaComponent* pkB)
{
    return pkA->GetAlpha() > pkB->GetAlpha();
}
MS2_REPLACE(0x1414DEE00, CompareAlpha, 79, 0x89149BAE);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2fb0-0x142cb30c0 .text$yd
