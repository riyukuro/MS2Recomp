// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2FragmentShader: NiDX9FragmentShader with the game's own
// Do_RenderMeshes / PrepareTextureStage and pipeline overrides (stock NiD3DShader behaviour).
// MS2-UNIT: ?\ms2fragmentshader.cpp
// MS2-RANGE: 0x1400d3aa0-0x1400d3ac3 .text$di
// MS2-RANGE: 0x140d878b0-0x140d8a570 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2fragmentshader.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2fragmentshader.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiDX9Renderer.h>
#include <NiDX9RenderState.h>
#include <NiDX9MeshMaterialBinding.h>
#include <NiDX9DataStream.h>
#include <NiMesh.h>
#include <NiInstancingUtilities.h>
#include <NiShadowGenerator.h>
#include <NiShadowMap.h>
#include <NiTextureEffect.h>

#ifdef __clang__
static volatile unsigned __int64 s_msZero;
static const NiRTTI* msBaseRTTI() { return (const NiRTTI*)((unsigned __int64)&NiDX9FragmentShader::ms_RTTI + s_msZero); }
const NiRTTI MS2FragmentShader::ms_RTTI("MS2FragmentShader", msBaseRTTI());
#else
// @0x1400d3aa0
const NiRTTI MS2FragmentShader::ms_RTTI("MS2FragmentShader", &NiDX9FragmentShader::ms_RTTI);
#endif

// @0x140d878b0
MS2FragmentShader::MS2FragmentShader(NiMaterialDescriptor* pkDesc)
    : NiDX9FragmentShader(pkDesc)
{
}

// @0x140d878f0
MS2FragmentShader::~MS2FragmentShader()
{
}

// The game's draw-statistics counters live in the renderer's Nexon-appended tail (+0x1074 / +0x1078); the code writes them directly.
struct Unk_RendererDrawStats : public NiDX9Renderer
{
    // @0x140d8a110
    static void AddPrimitiveCount(NiDX9Renderer* pkRenderer, int iCount)
    {
        ((Unk_RendererDrawStats*)pkRenderer)->m_uiMS2Unknown_1078 += iCount;
    }
    // @0x140d8a140
    static void AddVertexCount(NiDX9Renderer* pkRenderer, int iCount)
    {
        ((Unk_RendererDrawStats*)pkRenderer)->m_uiMS2Unknown_1074 += iCount;
    }
};

// Hook registration can only name public members; re-expose the two protected overrides.
struct MS2FragmentShaderHookAccess : public MS2FragmentShader
{
    void Do_RenderMeshesHook(NiVisibleArray* pkVisibleArray) { MS2FragmentShader::Do_RenderMeshes(pkVisibleArray); }
    void PrepareTextureStageHook(NiD3DTextureStage* pkStage, const NiRenderCallContext& kRCC)
    {
        MS2FragmentShader::PrepareTextureStage(pkStage, kRCC);
    }
};

// @0x140d87920
void MS2FragmentShader::Do_RenderMeshes(NiVisibleArray* pkVisibleArray)
{
    if (pkVisibleArray->GetCount() == 0)
        return;

    NiDX9Renderer* pkRenderer = NiDX9Renderer::GetRenderer();
    NiDX9RenderState* pkRenderState = pkRenderer->GetRenderState();
    LPDIRECT3DDEVICE9 pkD3DDevice9 = pkRenderer->GetD3DDevice();

    unsigned int uiMetricDPCalls = 0;

    unsigned int uiRet;
    NiRenderCallContext kRCC;
    kRCC.m_uiPass = 0;
    kRCC.m_uiActivePhases = NiRenderer::PHASE_PER_SHADER | NiRenderer::PHASE_PER_LIGHTSTATE | NiRenderer::PHASE_PER_MESH;

    bool bStatesCommitted = false;
    const NiDynamicEffectState* pkPreviousEffectState = NULL;

    for (NiUInt32 uiRenderObjectIndex = 0; uiRenderObjectIndex < pkVisibleArray->GetCount(); uiRenderObjectIndex++)
    {
        NiMesh* pkMesh = NiVerifyStaticCast(NiMesh, &pkVisibleArray->GetAt(uiRenderObjectIndex));

        if (bStatesCommitted && pkPreviousEffectState != pkMesh->GetEffectState())
            kRCC.m_uiActivePhases |= NiRenderer::PHASE_PER_LIGHTSTATE;

        NiSyncArgs kSyncArgs;
        kSyncArgs.m_uiSubmitPoint = NiSyncArgs::SYNC_ANY;
        kSyncArgs.m_uiCompletePoint = NiSyncArgs::SYNC_RENDER;
        pkMesh->CompleteModifiers(&kSyncArgs);

        NiTimeController::OnPreDisplayIterate(pkMesh->GetControllers());

        pkRenderer->SetPropertyState(pkMesh->GetPropertyState());
        pkRenderer->SetEffectState(pkMesh->GetEffectState());

        const NiMaterialInstance* pkMatInst = pkMesh->GetActiveMaterialInstance();
        NiDX9MeshMaterialBindingPtr spVertexDeclaration;
        if (!pkMatInst)
        {
            pkRenderer->GetShaderAndVertexDecl(pkMesh, spVertexDeclaration);
            if (spVertexDeclaration == NULL)
            {
                continue;
            }
        }
        else
        {
            spVertexDeclaration = (NiDX9MeshMaterialBinding*)pkMatInst->GetVertexDeclarationCache();
        }

        NiTransform kWorld = pkMesh->GetWorldTransform();
        NiBound kWorldBound = pkMesh->GetWorldBound();

        kRCC.m_pkMesh = pkMesh;
        kRCC.m_pkMeshMaterialBinding = ((NiVertexDeclarationCache*)(spVertexDeclaration.data()));
        kRCC.m_pkWorldBound = &kWorldBound;
        kRCC.m_pkEffects = pkRenderer->GetEffectState();
        kRCC.m_pkState = pkRenderer->GetPropertyState();
        kRCC.m_pkWorld = &kWorld;
        kRCC.m_uiPass = 0;

        uiRet = PreProcessPipeline(kRCC);
        if (uiRet != 0)
        {
            continue;
        }

        uiRet = UpdatePipeline(kRCC);

        D3DPRIMITIVETYPE eGeomType;
        if (!pkRenderer->GetDX9PrimitiveFromNiMeshPrimitiveType(pkMesh->GetPrimitiveType(), eGeomType))
        {
            continue;
        }

        if (spVertexDeclaration->m_kStreamsToSet.GetSize() == 0)
        {
            NiDX9Renderer::Warning(
                "NiD3DShader::RenderMeshes> "
                "No vertex streams found to render with on"
                "'%s' object, pointer: %x, skipping render.",
                (const char*)pkMesh->GetName(),
                pkMesh);
            continue;
        }

        bool bIndexed = spVertexDeclaration->m_pkIndexStreamRef != NULL;

        const NiDataStreamRef* pkStreamRef = NULL;
        if (bIndexed)
        {
            pkStreamRef = spVertexDeclaration->m_pkIndexStreamRef;
        }
        else
        {
            pkStreamRef = pkMesh->GetStreamRefAt(spVertexDeclaration->m_kStreamsToSet.GetAt(0));
        }

        pkD3DDevice9->SetVertexDeclaration(spVertexDeclaration->GetD3DDeclaration());

        NiUInt32 uiSubmeshCount = 0;
        if (pkMesh->GetInstanced())
            uiSubmeshCount = NiInstancingUtilities::GetVisibleSubmeshCount(pkMesh);
        else
            uiSubmeshCount = pkMesh->GetSubmeshCount();

        unsigned int uiRemainingPasses = FirstPass();
        unsigned int uiTotalPasses = uiRemainingPasses;
        while (uiRemainingPasses != 0)
        {
            uiRet = SetupRenderingPass(kRCC);
            uiRet = SetupTransformations(kRCC);

            for (NiUInt32 uiSubmesh = 0; uiSubmesh < uiSubmeshCount; ++uiSubmesh)
            {
                kRCC.m_uiSubmesh = uiSubmesh;

                NiDataStream::Region kRegion = pkStreamRef->GetRegionForSubmesh(uiSubmesh);
                unsigned int uiElementCount = pkStreamRef->GetCount(uiSubmesh);
                unsigned int uiPrimitiveCount = pkMesh->GetPrimitiveCountFromElementCount(uiElementCount);

                int iInstancedPrimitiveCount = 0;
                if (pkMesh->GetInstanced())
                    iInstancedPrimitiveCount = uiPrimitiveCount * NiInstancingUtilities::GetVisibleInstanceCount(pkMesh);

                if (uiPrimitiveCount == 0)
                {
                    continue;
                }
                SetupShaderPrograms(kRCC);

                pkRenderState->CommitShaderConstants();

                bStatesCommitted = true;

                PreRenderSubmesh(kRCC);

                NiUInt32 uiNumVertices;
                if (bIndexed)
                {
                    uiNumVertices = pkMesh->GetVertexCount(uiSubmesh);
                    Unk_RendererDrawStats::AddVertexCount(pkRenderer, uiNumVertices);
                    Unk_RendererDrawStats::AddPrimitiveCount(pkRenderer, iInstancedPrimitiveCount != 0 ? iInstancedPrimitiveCount : uiPrimitiveCount);

                    pkD3DDevice9->DrawIndexedPrimitive(eGeomType, 0, 0, uiNumVertices, kRegion.GetStartIndex(), uiPrimitiveCount);
                }
                else
                {
                    uiNumVertices = kRegion.GetRange();
                    Unk_RendererDrawStats::AddVertexCount(pkRenderer, uiNumVertices);
                    Unk_RendererDrawStats::AddPrimitiveCount(pkRenderer, iInstancedPrimitiveCount != 0 ? iInstancedPrimitiveCount : uiPrimitiveCount);

                    pkD3DDevice9->DrawPrimitive(eGeomType, 0, uiPrimitiveCount);
                }

                uiMetricDPCalls++;

                PostRenderSubmesh(kRCC);
            }

            uiRet = PostRender(kRCC);

            uiRemainingPasses = NextPass();
            kRCC.m_uiPass++;
        }

        PostProcessPipeline(kRCC);

        if (bStatesCommitted)
        {
            if (uiTotalPasses > 1)
                kRCC.m_uiActivePhases = NiRenderer::PHASE_PER_MESH | NiRenderer::PHASE_PER_LIGHTSTATE;
            else
                kRCC.m_uiActivePhases = NiRenderer::PHASE_PER_MESH;
        }
        pkPreviousEffectState = kRCC.m_pkEffects;
    }
}
MS2_REPLACE_METHOD(0x140D87920, MS2FragmentShaderHookAccess, Do_RenderMeshesHook, 2136, 0xA1D30F26);

// @0x140d88180
unsigned int MS2FragmentShader::FirstPass()
{
    m_uiCurrentPass = 0;
    m_spCurrentPass = m_kPasses.GetAt(m_uiCurrentPass);

    return m_uiPassCount;
}
MS2_REPLACE_METHOD(0x140D88180, MS2FragmentShader, FirstPass, 90, 0xD40AF3DF);

// @0x140d881e0
unsigned int MS2FragmentShader::NextPass()
{
    if (m_spCurrentPass != NULL)
        m_spCurrentPass->PostProcessRenderingPass(m_uiCurrentPass);

    m_uiCurrentPass++;
    if (m_uiCurrentPass == m_uiPassCount)
        return 0;

    m_spCurrentPass = m_kPasses.GetAt(m_uiCurrentPass);

    return (m_uiPassCount - m_uiCurrentPass);
}
MS2_REPLACE_METHOD(0x140D881E0, MS2FragmentShader, NextPass, 219, 0x4D858197);

// @0x140d882d0
unsigned int MS2FragmentShader::SetupRenderingPass(const NiRenderCallContext& kRCC)
{
    unsigned int uiRet = 0;

    uiRet = m_spCurrentPass->SetupRenderingPass(kRCC);

    return uiRet;
}
MS2_REPLACE_METHOD(0x140D882D0, MS2FragmentShader, SetupRenderingPass, 80, 0x4A80EF45);

// @0x140d88330
unsigned int MS2FragmentShader::SetupTransformations(const NiRenderCallContext& kRCC)
{
    if (m_uiCurrentPass == 0)
    {
        m_pkD3DRenderState->SetBoneCount(0);
        m_pkD3DRenderer->SetModelTransform(*kRCC.m_pkWorld);
    }

    return 0;
}
MS2_REPLACE_METHOD(0x140D88330, MS2FragmentShader, SetupTransformations, 77, 0xD47CC31A);

// @0x140d88390
unsigned int MS2FragmentShader::SetupShaderPrograms(const NiRenderCallContext& kRCC)
{
    unsigned int uiRet = 0;

    ResetSCMExtraData(kRCC.m_pkMesh);

    uiRet = m_spCurrentPass->SetupShaderPrograms(kRCC);

    NiD3DError eErr = NISHADERERR_OK;

    if (m_spPixelConstantMap && m_spCurrentPass->GetPixelShader())
    {
        eErr = m_spPixelConstantMap->SetShaderConstants(kRCC, m_spCurrentPass->GetPixelShader(), true);
    }

    if (m_spVertexConstantMap && m_spCurrentPass->GetVertexShader())
    {
        eErr = m_spVertexConstantMap->SetShaderConstants(kRCC, m_spCurrentPass->GetVertexShader(), true);
    }

    return uiRet;
}
MS2_REPLACE_METHOD(0x140D88390, MS2FragmentShader, SetupShaderPrograms, 444, 0xB234E446);

// @0x140d88560
unsigned int MS2FragmentShader::PreProcessPipeline(const NiRenderCallContext& kRCC)
{
    if (!m_bInitialized)
    {
        return 0xFFFFFFFF;
    }

    if (m_bUsesNiRenderState)
    {
        m_pkD3DRenderState->UpdateRenderState(kRCC.m_pkState);
    }

    if (m_bUsesNiLightState)
    {
        if (m_pkD3DRenderer->GetLightManager())
        {
            m_pkD3DRenderer->GetLightManager()->SetState(
                kRCC.m_pkEffects, kRCC.m_pkState->GetTexturing(), kRCC.m_pkState->GetVertexColor());
        }
    }

    if (m_pkRenderStateGroup != NULL)
    {
        m_pkRenderStateGroup->SetRenderStates();
    }

    return 0;
}
MS2_REPLACE_METHOD(0x140D88560, MS2FragmentShader, PreProcessPipeline, 235, 0x2B0D51E9);

// @0x140d88660
unsigned int MS2FragmentShader::UpdatePipeline(const NiRenderCallContext& kRCC)
{
    for (unsigned int uiPass = 0; uiPass < m_kPasses.GetSize(); uiPass++)
    {
        NiD3DPass* pkCurPass = m_kPasses.GetAt(uiPass);
        if (!pkCurPass)
        {
            continue;
        }
        for (unsigned int uiStage = 0; uiStage < pkCurPass->GetStageCount(); uiStage++)
        {
            NiD3DTextureStage* pkCurStage = pkCurPass->GetStage(uiStage);
            if (!pkCurStage)
            {
                continue;
            }
            PrepareTextureStage(pkCurStage, kRCC);
        }
    }

    return NiD3DShader::UpdatePipeline(kRCC);
}
MS2_REPLACE_METHOD(0x140D88660, MS2FragmentShader, UpdatePipeline, 230, 0x0DD34B4F);

// @0x140d88750
void MS2FragmentShader::PrepareTextureStage(
    NiD3DTextureStage* pkStage,
    const NiRenderCallContext& kRCC)
{
    const NiDynamicEffectState* pkEffects = kRCC.m_pkEffects;
    NiRenderObject* pkMesh = kRCC.m_pkMesh;

    NiTexture* pkTexture = NULL;
    NiTexturingProperty::ClampMode eClampMode =
        NiTexturingProperty::CLAMP_S_CLAMP_T;
    NiTexturingProperty::FilterMode eFilterMode =
        NiTexturingProperty::FILTER_NEAREST;
    unsigned short usMaxAnisotropy = 1;

    unsigned int uiTextureFlags = pkStage->GetTextureFlags();
    unsigned short usObjTextureFlags = pkStage->GetObjTextureFlags();

    if (usObjTextureFlags == NiD3DTextureStage::TSOTF_IGNORE)
    {
        if (uiTextureFlags != NiD3DTextureStage::TSTF_IGNORE)
        {
            const NiTexturingProperty* pkTexProp =
                kRCC.m_pkState->GetTexturing();
            const NiTexturingProperty::Map* pkMap = NULL;
            EE_ASSERT(pkTexProp);
            if ((uiTextureFlags & NiD3DTextureStage::TSTF_MAP_MASK) == 0)
            {
                switch (uiTextureFlags & NiD3DTextureStage::TSTF_NDL_TYPEMASK)
                {
                case NiD3DTextureStage::TSTF_NONE:
                    break;
                case NiD3DTextureStage::TSTF_NDL_BASE:
                    pkMap = pkTexProp->GetBaseMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_DARK:
                    pkMap = pkTexProp->GetDarkMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_DETAIL:
                    pkMap = pkTexProp->GetDetailMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_GLOSS:
                    pkMap = pkTexProp->GetGlossMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_GLOW:
                    pkMap = pkTexProp->GetGlowMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_BUMP:
                    pkMap = pkTexProp->GetBumpMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_NORMAL:
                    pkMap = pkTexProp->GetNormalMap();
                    break;
                case NiD3DTextureStage::TSTF_NDL_PARALLAX:
                    pkMap = pkTexProp->GetParallaxMap();
                    break;

                }
            }
            else if ((uiTextureFlags & NiD3DTextureStage::TSTF_MAP_MASK) ==
                NiD3DTextureStage::TSTF_MAP_DECAL)
            {
                unsigned int uiIndex = uiTextureFlags &
                    NiD3DTextureStage::TSTF_INDEX_MASK;
                if (uiIndex < pkTexProp->GetDecalArrayCount())
                {
                    pkMap = pkTexProp->GetDecalMap(uiIndex);
                }
            }
            else if ((uiTextureFlags & NiD3DTextureStage::TSTF_MAP_MASK) ==
                NiD3DTextureStage::TSTF_MAP_SHADER)
            {
                unsigned int uiIndex = uiTextureFlags &
                    NiD3DTextureStage::TSTF_INDEX_MASK;
                if (uiIndex < pkTexProp->GetShaderArrayCount())
                {
                    pkMap = pkTexProp->GetShaderMap(uiIndex);
                }
            }

            if (pkMap)
            {
                pkTexture = pkMap->GetTexture();
                eClampMode = pkMap->GetClampMode();
                eFilterMode = pkMap->GetFilterMode();
                usMaxAnisotropy = pkMap->GetMaxAnisotropy();
                // What else is needed?

                // If we are to use the index from the map, set that now
                // as well
                if ((uiTextureFlags & NiD3DTextureStage::TSTF_MAP_USE_MASK) ==
                    NiD3DTextureStage::TSTF_MAP_USE_INDEX)
                {
                    unsigned int uiTexCoordIndex = pkMap->GetTextureIndex();

                    // We need to take the transformation info into account
                    uiTexCoordIndex |= pkStage->GetTexCoordIndex() &
                        ~NiD3DTextureStage::TSTF_INDEX_MASK;

                    pkStage->SetStageState(D3DTSS_TEXCOORDINDEX,
                        uiTexCoordIndex, pkStage->GetSaveTexCoordIndex());
                }
            }
        }
    }
    else if (pkEffects)
    {
        NiTextureEffect* pkTextureEffect = NULL;
        unsigned short usObjectIndex = static_cast<unsigned short>(
            usObjTextureFlags & NiD3DTextureStage::TSOTF_INDEX_MASK);
        switch ((usObjTextureFlags & NiD3DTextureStage::TSOTF_TYPE_MASK) >>
            NiD3DTextureStage::TSOTF_TYPE_SHIFT)
        {
        case NiShaderAttributeDesc::OT_EFFECT_DIRSHADOWMAP:
            {
                NiLight* pkLight  = (NiLight*)
                    NiShaderConstantMap::GetDynamicEffectForObject(
                    pkEffects,
                    NiShaderAttributeDesc::OT_EFFECT_SHADOWDIRECTIONALLIGHT,
                    usObjectIndex);
                EE_ASSERT(pkLight);

                NiShadowGenerator* pkGenerator =
                    pkLight->GetShadowGenerator();
                EE_ASSERT(pkGenerator);

                NiShadowMap* pkShadowMap =
                    pkGenerator->RetrieveShadowMap(
                    NiShadowGenerator::AUTO_DETERMINE_SM_INDEX,
                    pkMesh);
                EE_ASSERT(pkShadowMap);

                pkTexture = pkShadowMap->GetTexture();
                eClampMode = (NiTexturingProperty::ClampMode)
                    pkShadowMap->GetClampMode();
                eFilterMode = (NiTexturingProperty::FilterMode)
                    pkShadowMap->GetFilterMode();
                usMaxAnisotropy = pkShadowMap->GetMaxAnisotropy();
                break;
            }
        case NiShaderAttributeDesc::OT_EFFECT_POINTSHADOWMAP:
            {
                NiLight* pkLight  = (NiLight*)
                    NiShaderConstantMap::GetDynamicEffectForObject(
                    pkEffects,
                    NiShaderAttributeDesc::OT_EFFECT_SHADOWPOINTLIGHT,
                    usObjectIndex);
                EE_ASSERT(pkLight);

                NiShadowGenerator* pkGenerator =
                    pkLight->GetShadowGenerator();
                EE_ASSERT(pkGenerator);

                NiShadowMap* pkShadowMap =
                    pkGenerator->RetrieveShadowMap(
                    NiShadowGenerator::AUTO_DETERMINE_SM_INDEX,
                    pkMesh);
                EE_ASSERT(pkShadowMap);

                pkTexture = pkShadowMap->GetTexture();
                eClampMode = (NiTexturingProperty::ClampMode)
                    pkShadowMap->GetClampMode();
                eFilterMode = (NiTexturingProperty::FilterMode)
                    pkShadowMap->GetFilterMode();
                usMaxAnisotropy = pkShadowMap->GetMaxAnisotropy();
                break;
            }
        case NiShaderAttributeDesc::OT_EFFECT_SPOTSHADOWMAP:
            {
                NiLight* pkLight  = (NiLight*)
                    NiShaderConstantMap::GetDynamicEffectForObject(
                    pkEffects,
                    NiShaderAttributeDesc::OT_EFFECT_SHADOWSPOTLIGHT,
                    usObjectIndex);
                EE_ASSERT(pkLight);

                NiShadowGenerator* pkGenerator =
                    pkLight->GetShadowGenerator();
                EE_ASSERT(pkGenerator);

                NiShadowMap* pkShadowMap =
                    pkGenerator->RetrieveShadowMap(
                    NiShadowGenerator::AUTO_DETERMINE_SM_INDEX,
                    pkMesh);
                EE_ASSERT(pkShadowMap);

                pkTexture = pkShadowMap->GetTexture();
                eClampMode = (NiTexturingProperty::ClampMode)
                    pkShadowMap->GetClampMode();
                eFilterMode = (NiTexturingProperty::FilterMode)
                    pkShadowMap->GetFilterMode();
                usMaxAnisotropy = pkShadowMap->GetMaxAnisotropy();
                break;
            }
            case NiShaderAttributeDesc::OT_EFFECT_ENVIRONMENTMAP:
                pkTextureEffect = pkEffects->GetEnvironmentMap();
                if (pkTextureEffect && !pkTextureEffect->GetSwitch())
                    pkTextureEffect = NULL;
                break;
            case NiShaderAttributeDesc::OT_EFFECT_PROJECTEDSHADOWMAP:
            {
                unsigned short usIndex = 0;
                NiDynEffectStateIter kIter =
                    pkEffects->GetProjShadowHeadPos();
                while (kIter)
                {
                    NiTextureEffect* pkProjShadow =
                        pkEffects->GetNextProjShadow(kIter);
                    if (pkProjShadow && pkProjShadow->GetSwitch() == true)
                    {
                        if (usIndex++ == usObjectIndex)
                        {
                            pkTextureEffect = pkProjShadow;
                            break;
                        }
                    }
                }
                break;
            }
            case NiShaderAttributeDesc::OT_EFFECT_PROJECTEDLIGHTMAP:
            {
                unsigned short usIndex = 0;
                NiDynEffectStateIter kIter =
                    pkEffects->GetProjLightHeadPos();
                while (kIter)
                {
                    NiTextureEffect* pkProjLight =
                        pkEffects->GetNextProjLight(kIter);
                    if (pkProjLight && pkProjLight->GetSwitch() == true)
                    {
                        if (usIndex++ == usObjectIndex)
                        {
                            pkTextureEffect = pkProjLight;
                            break;
                        }
                    }
                }
                break;
            }
            case NiShaderAttributeDesc::OT_EFFECT_FOGMAP:
                pkTextureEffect = pkEffects->GetFogMap();
                if (pkTextureEffect && !pkTextureEffect->GetSwitch())
                    pkTextureEffect = NULL;
                break;
            case NiShaderAttributeDesc::OT_EFFECT_PSSMSLICENOISEMASK:
            {
                NiLight* pkLight = (NiLight*)
                    NiShaderConstantMap::GetDynamicEffectForObject(
                    pkEffects,
                    NiShaderAttributeDesc::OT_EFFECT_SHADOWDIRECTIONALLIGHT,
                    usObjectIndex);
                EE_ASSERT(pkLight);

                NiShadowGenerator* pkGenerator = 
                    pkLight->GetShadowGenerator();
                EE_ASSERT(pkGenerator);

                NiTexturingProperty::Map* pkShadowNoiseMap = 
                    pkGenerator->RetrieveTextureMap(
                    NiShadowGenerator::AUTO_DETERMINE_TM_INDEX, 
                    NiStandardMaterial::MAP_SHADOWMAP_NOISE_GREYSCALE,
                    pkMesh);
                EE_ASSERT(pkShadowNoiseMap);
                
                if (pkShadowNoiseMap)
                {
                    pkTexture = pkShadowNoiseMap->GetTexture();
                    eClampMode = (NiTexturingProperty::ClampMode)
                        pkShadowNoiseMap->GetClampMode();
                    eFilterMode = (NiTexturingProperty::FilterMode)
                        pkShadowNoiseMap->GetFilterMode();
                }
                break;
            }
            default:
                // This assertion is hit when the object type is not one
                // that has a texture.
                EE_ASSERT(false);
                break;
        }

        if (pkTextureEffect)
        {
            pkTexture = pkTextureEffect->GetEffectTexture();
            eClampMode = pkTextureEffect->GetTextureClamp();
            eFilterMode = pkTextureEffect->GetTextureFilter();
            usMaxAnisotropy = pkTextureEffect->GetMaxAnisotropy();

            // If UseMapIndex is specified, grab and set the tex coord gen
            // mode and
            if ((uiTextureFlags & NiD3DTextureStage::TSTF_MAP_USE_MASK) ==
                NiD3DTextureStage::TSTF_MAP_USE_INDEX)
            {
                PackDynamicEffect(pkTextureEffect, pkStage,
                    pkStage->GetSaveTexCoordIndex(), m_pkD3DRenderer);
            }
        }
    }

    // Even if the texture is NULL, we need to set that here to prevent a
    // stale texture from getting used by accident.
    pkStage->SetTexture(pkTexture);
    pkStage->SetClampMode(eClampMode);
    pkStage->SetFilterMode(eFilterMode);
    pkStage->SetMaxAnisotropy(usMaxAnisotropy);
}
MS2_REPLACE_METHOD(0x140D88750, MS2FragmentShaderHookAccess, PrepareTextureStageHook, 2169, 0xFDCA82C4);

//--------------------------------------------------------------------------------------------------
// The engine's NiDX9FragmentShader.cpp defines this (0x1427e2d20) in the full-exe link; only the hook DLL, which links
// no engine objs, needs this copy.
#ifdef MS2_HOOK_DLL
const NiShader::NiShaderInstanceDescriptor*
    NiDX9FragmentShader::GetShaderInstanceDesc() const
{
    return &m_kDescriptor;
}
#endif

//--------------------------------------------------------------------------------------------------
