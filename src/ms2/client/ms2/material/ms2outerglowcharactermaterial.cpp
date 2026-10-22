// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2OuterGlowCharacterMaterial: the outer glow pass
// drawn around characters ("MS2OuterGlowCharacterMaterial", typed as MS2CharacterMaterial). The vertices are projected
// through the library's ProjectPositionWorldToViewToProj_Outer fragment (fed the world normal) and the pixels output
// the flat gkOuterColor global in place of the lit diffuse colour; the pixel tree is MS2StandardMaterial's without the
// detail opacity, hair tangent, MS2 lighting and colour boost steps. No __FILE__ strings; file name guessed from the
// class name.
// MS2-UNIT: ?\ms2outerglowcharactermaterial.cpp
// MS2-RANGE: 0x14276fc70-0x142771d50 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardMaterialNodeLibrary.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiStandardVertexProgramDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include <NiPSSMShadowClickGenerator.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"
#include "hook/ms2hook.h"

// "TransformSkinnedPosition60" (the 60-bone skinning fragment of MS2MaterialNodeLibrary); this TU's copy of the
// header-static pointer, .data 0x143a4a678
static const char* g_pcTransformSkinnedPosition60 = "TransformSkinnedPosition60";

//--------------------------------------------------------------------------------------------------
// @0x14276fc70
MS2OuterGlowCharacterMaterial::MS2OuterGlowCharacterMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2OuterGlowCharacterMaterial", "MS2CharacterMaterial", 6, bAutoCreateCaches)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2UIMaterialNodeLibrary::CreateMaterialNodeLibrary());
    SetForcePerPixelLighting(true);
}

//--------------------------------------------------------------------------------------------------
// @0x14276ff60
bool MS2OuterGlowCharacterMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
{
    NiStandardPixelProgramDescriptor* pkPixelDesc = (NiStandardPixelProgramDescriptor*)pkDesc;

    kContext.m_spConfigurator->SetDescription(pkPixelDesc->ToString());

    if (!AddDefaultMaterialNodes(kContext, pkDesc, NiGPUProgram::PROGRAM_PIXEL))
        return false;

    kContext.m_spInputs->AddOutputResource("float4", "Position", "World", "PosProjected");

    NiMaterialResource* pkPixelWorldPos = NULL;
    NiMaterialResource* pkPixelWorldNorm = NULL;
    NiMaterialResource* pkPixelWorldBinormal = NULL;
    NiMaterialResource* pkPixelWorldTangent = NULL;
    NiMaterialResource* pkPixelWorldViewVector = NULL;
    NiMaterialResource* pkPixelTangentViewVector = NULL;

    if (!HandlePixelInputs(kContext, pkPixelDesc, pkPixelWorldPos, pkPixelWorldNorm, pkPixelWorldBinormal,
        pkPixelWorldTangent, pkPixelWorldViewVector, pkPixelTangentViewVector))
    {
        return false;
    }

    unsigned int uiPointLightCount = pkPixelDesc->GetPOINTLIGHTCOUNT();
    unsigned int uiDirLightCount = pkPixelDesc->GetDIRLIGHTCOUNT();
    unsigned int uiSpotLightCount = pkPixelDesc->GetSPOTLIGHTCOUNT();
    bool bSpecular = pkPixelDesc->GetSPECULAR() ? true : false;

    NiMaterialResource* pkMatDiffuse = NULL;
    NiMaterialResource* pkMatSpecular = NULL;
    NiMaterialResource* pkSpecularPower = NULL;
    NiMaterialResource* pkGlossiness = NULL;
    NiMaterialResource* pkMatAmbient = NULL;
    NiMaterialResource* pkMatEmissive = NULL;
    NiMaterialResource* pkTexDiffuseAccum = NULL;
    NiMaterialResource* pkTexSpecularAccum = NULL;
    NiMaterialResource* pkDiffuseAccum = NULL;
    NiMaterialResource* pkSpecularAccum = NULL;
    NiMaterialResource* pkOpacityAccum = NULL;
    NiMaterialResource* pkLightDiffuseAccum = NULL;
    NiMaterialResource* pkLightSpecularAccum = NULL;
    NiMaterialResource* pkLightAmbientAccum = NULL;
    LightingModeEnum eLightingMode = LIGHTING_E_A_D;

    if (!HandlePixelMaterialInitialValues(kContext, pkPixelDesc,
        uiPointLightCount + uiDirLightCount + uiSpotLightCount, bSpecular, eLightingMode, pkMatDiffuse,
        pkMatSpecular, pkSpecularPower, pkGlossiness, pkMatAmbient, pkMatEmissive, pkTexDiffuseAccum,
        pkTexSpecularAccum, pkDiffuseAccum, pkSpecularAccum, pkOpacityAccum, pkLightDiffuseAccum,
        pkLightSpecularAccum, pkLightAmbientAccum))
    {
        return false;
    }

    NiMaterialResource* apkUVSets[STANDARD_PIPE_MAX_UVS_FOR_TEXTURES];
    unsigned int uiNumStandardUVs = 0;
    unsigned int uiDynamicEffectCount = 0;

    if (!HandlePixelUVSets(kContext, pkPixelDesc, apkUVSets, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES,
        uiNumStandardUVs, uiDynamicEffectCount))
    {
        return false;
    }

    unsigned int uiTexturesApplied = 0;

    if (!HandlePreLightTextureApplication(kContext, pkPixelDesc, pkPixelWorldPos, pkPixelWorldNorm,
        pkPixelWorldBinormal, pkPixelWorldTangent, pkPixelWorldViewVector, pkPixelTangentViewVector,
        pkMatDiffuse, pkMatSpecular, pkSpecularPower, pkGlossiness, pkMatAmbient, pkMatEmissive, pkOpacityAccum,
        pkLightAmbientAccum, pkLightDiffuseAccum, pkLightSpecularAccum, pkTexDiffuseAccum, pkTexSpecularAccum,
        uiTexturesApplied, apkUVSets, uiNumStandardUVs, uiDynamicEffectCount))
    {
        return false;
    }

    unsigned int uiShadowMapForLight = pkPixelDesc->GetSHADOWMAPFORLIGHT();
    unsigned int uiShadowTechnique = pkPixelDesc->GetSHADOWTECHNIQUE();
    NiUInt32 uiPSSMWhichLight = pkPixelDesc->GetPSSMWHICHLIGHT();
    NiUInt32 uiShadowAtlasCells = NiPSSMShadowClickGenerator::DecodeDescriptorMaxSliceCount(
        pkPixelDesc->GetPSSMSLICECOUNT());
    bool bSliceTransitions = pkPixelDesc->GetPSSMSLICETRANSITIONSENABLED() == 1;

    if (!HandleLighting(kContext, uiShadowAtlasCells, uiPSSMWhichLight, bSliceTransitions, bSpecular,
        uiPointLightCount, uiDirLightCount, uiSpotLightCount, uiShadowMapForLight, uiShadowTechnique,
        pkPixelWorldPos, pkPixelWorldNorm, pkPixelWorldViewVector, pkSpecularPower, pkLightAmbientAccum,
        pkLightDiffuseAccum, pkLightSpecularAccum))
    {
        return false;
    }

    if (!HandleColorAccumulation(kContext, pkPixelDesc, pkMatEmissive, pkMatDiffuse, pkMatAmbient, pkMatSpecular,
        pkLightSpecularAccum, pkLightDiffuseAccum, pkLightAmbientAccum, pkGlossiness, pkTexDiffuseAccum,
        pkTexSpecularAccum, eLightingMode, pkSpecularAccum, pkDiffuseAccum))
    {
        return false;
    }

    if (!HandleMS2PostLightTextureApplication(kContext, pkPixelDesc, pkPixelWorldNorm, pkPixelWorldViewVector,
        pkOpacityAccum, pkDiffuseAccum, pkSpecularAccum, pkGlossiness, uiTexturesApplied, apkUVSets,
        uiNumStandardUVs, uiDynamicEffectCount, NULL))
    {
        return false;
    }

    return HandleMS2FinalPixelOutputs(kContext, pkPixelDesc, pkPixelWorldNorm, pkPixelWorldViewVector,
        pkDiffuseAccum, pkSpecularAccum, pkOpacityAccum) ? true : false;
}
MS2_REPLACE_METHOD(0x14276FF60, MS2OuterGlowCharacterMaterial, GeneratePixelShadeTree, 1555, 0xA852492F);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: exe keeps the base result in edi with a different frame; same behaviour
// @0x142770580
NiFragmentMaterial::ReturnCode MS2OuterGlowCharacterMaterial::GenerateShaderDescArray(
    NiMaterialDescriptor* pkMaterialDescriptor, RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount,
    unsigned int& uiCountAdded)
{
    ReturnCode eResult = MS2StandardMaterial::GenerateShaderDescArray(pkMaterialDescriptor, pkRenderPasses,
        uiMaxCount, uiCountAdded);
    if (eResult != RC_SUCCESS)
        return eResult;

    NiStandardVertexProgramDescriptor* pkVertexDesc =
        (NiStandardVertexProgramDescriptor*)pkRenderPasses[0].m_pkVertexDesc;
    NiStandardPixelProgramDescriptor* pkPixelDesc =
        (NiStandardPixelProgramDescriptor*)pkRenderPasses[0].m_pkPixelDesc;
    pkVertexDesc->m_kIdentifier = "NiStandardVertexProgramDescriptor";
    pkPixelDesc->m_kIdentifier = "NiStandardPixelProgramDescriptor";

    // APPLYMODE set: a world view vector in both stages
    if (pkMaterialDescriptor->m_pkBitArray[0] & 0x200)
    {
        pkVertexDesc->m_pkBitArray[0] |= 0x10;  // OUTPUTWORLDVIEW
        pkPixelDesc->m_pkBitArray[0] |= 0x10;   // WORLDVIEW
    }

    return eResult;
}
MS2_REPLACE_METHOD(0x142770580, MS2OuterGlowCharacterMaterial, GenerateShaderDescArray, 297, 0xAA247A75);

//--------------------------------------------------------------------------------------------------
// @0x1427706c0
bool MS2OuterGlowCharacterMaterial::HandleMS2FinalPixelOutputs(Context& kContext,
    NiStandardPixelProgramDescriptor* pkPixDesc, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkDiffuseAccum, NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialResource* pkOuterColor = AddOutputGlobal(kContext.m_spUniforms, "gkOuterColor",
        NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    return NiStandardMaterial::HandleFinalPixelOutputs(kContext, pkPixDesc, pkOuterColor, pkSpecularAccum,
        pkOpacityAccum) ? true : false;
}
MS2_REPLACE_METHOD(0x1427706C0, MS2OuterGlowCharacterMaterial, HandleMS2FinalPixelOutputs, 175, 0x57CA06AA);

//--------------------------------------------------------------------------------------------------
// @0x142770770
bool MS2OuterGlowCharacterMaterial::HandlePositionFragment(Context& kContext, TransformType eTransType,
    NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix)
{
    pkVertWorldPos = NULL;
    pkWorldMatrix = NULL;

    if (eTransType == TRANSFORM_DEFAULT)
    {
        NiMaterialNode* pkProjFrag = GetAttachableNodeFromLibrary("TransformPosition");
        kContext.m_spConfigurator->AddNode(pkProjFrag);

        kContext.m_spInputs->AddOutputResource("float3", "Position", "Local", "Position");

        pkWorldMatrix = AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_WORLD, 4);

        kContext.m_spConfigurator->AddBinding("Position", kContext.m_spInputs, "Position", pkProjFrag);
        kContext.m_spConfigurator->AddBinding(pkWorldMatrix, "World", pkProjFrag);

        pkVertWorldPos = pkProjFrag->GetOutputResourceByVariableName("WorldPos");
        return true;
    }

    if (eTransType == TRANSFORM_SKINNED)
    {
        NiMaterialNode* pkProjFrag = GetAttachableNodeFromLibrary(g_pcTransformSkinnedPosition60);
        kContext.m_spConfigurator->AddNode(pkProjFrag);

        kContext.m_spInputs->AddOutputResource("float3", "Position", "Local", "Position");
        kContext.m_spInputs->AddOutputResource("float3", "BlendWeight", "Local", "BlendWeights");
        kContext.m_spInputs->AddOutputResource("int4", "BlendIndices", "Local", "BlendIndices");

        NiMaterialResource* pkBoneMatrix = AddOutputPredefined(kContext.m_spUniforms,
            NiShaderConstantMap::SCM_DEF_SKINBONE_MATRIX_3, 3, 60);

        kContext.m_spConfigurator->AddBinding("Position", kContext.m_spInputs, "Position", pkProjFrag);
        kContext.m_spConfigurator->AddBinding("BlendWeights", kContext.m_spInputs, "BlendWeights", pkProjFrag);
        kContext.m_spConfigurator->AddBinding("BlendIndices", kContext.m_spInputs, "BlendIndices", pkProjFrag);
        kContext.m_spConfigurator->AddBinding(pkBoneMatrix, "Bones", pkProjFrag);

        pkVertWorldPos = pkProjFrag->GetOutputResourceByVariableName("WorldPos");
        pkWorldMatrix = pkProjFrag->GetOutputResourceByVariableName("SkinBoneTransform");
        return true;
    }

    if (eTransType == TRANSFORM_INSTANCED)
    {
        NiMaterialNode* pkInstTransFrag = GetAttachableNodeFromLibrary("ConstructInstanceTransform");
        kContext.m_spConfigurator->AddNode(pkInstTransFrag);

        kContext.m_spInputs->AddOutputResource("float3", "Position", "Local", "Position");
        kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "World", "Position1");
        kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "World", "Position2");
        kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "World", "Position3");

        kContext.m_spConfigurator->AddBinding("Position1", kContext.m_spInputs, "Position1", pkInstTransFrag);
        kContext.m_spConfigurator->AddBinding("Position2", kContext.m_spInputs, "Position2", pkInstTransFrag);
        kContext.m_spConfigurator->AddBinding("Position3", kContext.m_spInputs, "Position3", pkInstTransFrag);

        pkWorldMatrix = pkInstTransFrag->GetOutputResourceByVariableName("InstanceWorld");

        NiMaterialNode* pkProjFrag = GetAttachableNodeFromLibrary("TransformPosition");
        kContext.m_spConfigurator->AddNode(pkProjFrag);

        kContext.m_spConfigurator->AddBinding("Position", kContext.m_spInputs, "Position", pkProjFrag);
        kContext.m_spConfigurator->AddBinding(pkWorldMatrix, "World", pkProjFrag);

        pkVertWorldPos = pkProjFrag->GetOutputResourceByVariableName("WorldPos");
        return true;
    }

    return false;
}
MS2_REPLACE_METHOD(0x142770770, MS2OuterGlowCharacterMaterial, HandlePositionFragment, 2709, 0x889DD2F0);

//--------------------------------------------------------------------------------------------------
// @0x142771210
bool MS2OuterGlowCharacterMaterial::HandleOuterViewProjection(Context& kContext, bool bForceViewPos,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource*& pkProjectedPos,
    NiMaterialResource*& pkViewPos)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("ProjectPositionWorldToViewToProj_Outer");
    if (!pkNode)
        return false;

    kContext.m_spConfigurator->AddNode(pkNode);

    NiMaterialResource* pkView = AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_VIEW, 4);
    kContext.m_spConfigurator->AddBinding(pkView, pkNode->GetInputResourceByVariableName("ViewTransform"));
    NiMaterialResource* pkProj = AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_PROJ, 4);
    kContext.m_spConfigurator->AddBinding(pkProj, pkNode->GetInputResourceByVariableName("ProjTransform"));
    kContext.m_spConfigurator->AddBinding(pkWorldNormal, pkNode->GetInputResourceByVariableName("WorldNormal"));
    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkNode->GetInputResourceByVariableName("WorldPosition"));

    pkViewPos = pkNode->GetOutputResourceByVariableName("ViewPos");
    pkProjectedPos = pkNode->GetOutputResourceByVariableName("ProjPos");
    return true;
}
MS2_REPLACE_METHOD(0x142771210, MS2OuterGlowCharacterMaterial, HandleOuterViewProjection, 576, 0x338B2242);

//--------------------------------------------------------------------------------------------------
// NiStandardMaterial::SetupTransformPipeline with HandleOuterViewProjection in place of HandleViewProjectionFragment.
// @0x142771450
bool MS2OuterGlowCharacterMaterial::SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
    NiStandardVertexProgramDescriptor* pkVertexDesc, bool bForceWorldView, bool bForceViewPos,
    NiMaterialResource*& pkWorldPos, NiMaterialResource*& pkViewPos, NiMaterialResource*& pkProjectedPos,
    NiMaterialResource*& pkWorldNormal, NiMaterialResource*& pkWorldView) {
    pkWorldPos = NULL;
    pkWorldNormal = NULL;
    pkWorldView = NULL;

    NiMaterialResource* pkWorldMatrix = NULL;
    if (!HandlePositionFragment(kContext, (TransformType)pkVertexDesc->GetTRANSFORM(), pkWorldPos, pkWorldMatrix))
        return false;

    NiMaterialResource* pkWorldBinormal = NULL;
    NiMaterialResource* pkWorldTangent = NULL;
    NormalType eNormalType = (NormalType)pkVertexDesc->GetNORMAL();
    if (!HandleNormalFragment(kContext, eNormalType, pkWorldMatrix, pkWorldNormal, pkWorldBinormal, pkWorldTangent))
        return false;

    if (!HandlePostWorldTransform(kContext, pkVertexDesc, pkWorldPos, pkWorldNormal))
        return false;

    if (!HandleOuterViewProjection(kContext, bForceViewPos, pkWorldPos, pkWorldNormal, pkProjectedPos, pkViewPos))
        return false;

    if (!pkProjectedPos || !pkOutProjPos)
        return false;

    kContext.m_spConfigurator->AddBinding(pkProjectedPos, pkOutProjPos);

    if (pkVertexDesc->GetOUTPUTWORLDPOS() == 1)
    {
        NiMaterialResource* pkTexCoord = kContext.m_spOutputs->AddInputResource("float4", "TexCoord", "", "WorldPos");
        kContext.m_spOutputs->AddOutputResource("float4", "TexCoord", "", "WorldPos");
        kContext.m_spConfigurator->AddBinding(pkWorldPos, pkTexCoord);
    }

    if (pkVertexDesc->GetOUTPUTWORLDNBT() == 1)
    {
        if (eNormalType != NORMAL_NONE)
        {
            NiMaterialResource* pkTexCoord = kContext.m_spOutputs->AddInputResource("float3", "TexCoord", "",
                "WorldNormal");
            kContext.m_spOutputs->AddOutputResource("float3", "TexCoord", "", "WorldNormal");
            kContext.m_spConfigurator->AddBinding(pkWorldNormal, pkTexCoord);
        }

        if (eNormalType == NORMAL_NBT)
        {
            NiMaterialResource* pkTexCoord = kContext.m_spOutputs->AddInputResource("float3", "TexCoord", "",
                "WorldBinormal");
            kContext.m_spOutputs->AddOutputResource("float3", "TexCoord", "", "WorldBinormal");
            kContext.m_spConfigurator->AddBinding(pkWorldBinormal, pkTexCoord);

            pkTexCoord = kContext.m_spOutputs->AddInputResource("float3", "TexCoord", "", "WorldTangent");
            kContext.m_spOutputs->AddOutputResource("float3", "TexCoord", "", "WorldTangent");
            kContext.m_spConfigurator->AddBinding(pkWorldTangent, pkTexCoord);
        }
    }

    bool bOutputWorldView = pkVertexDesc->GetOUTPUTWORLDVIEW() == 1;
    bool bOutputTangentView = pkVertexDesc->GetOUTPUTTANGENTVIEW() == 1;
    if (bOutputWorldView || bOutputTangentView || bForceWorldView)
    {
        NiMaterialResource* pkTangentView = NULL;
        if (!HandleViewVectorFragment(kContext, pkWorldPos, pkWorldNormal, pkWorldBinormal, pkWorldTangent,
                bOutputTangentView, pkWorldView, pkTangentView))
            return false;

        if (bOutputWorldView)
        {
            NiMaterialResource* pkOut = kContext.m_spOutputs->AddInputResource("float3", "TexCoord", "WorldView",
                "WorldView");
            kContext.m_spConfigurator->AddBinding(pkWorldView, pkOut);
        }

        if (bOutputTangentView)
        {
            NiMaterialResource* pkOut = kContext.m_spOutputs->AddInputResource("float3", "TexCoord",
                "TangentSpaceView", "TangentSpaceView");
            kContext.m_spConfigurator->AddBinding(pkTangentView, pkOut);
        }
    }

    return true;
}
MS2_REPLACE_METHOD(0x142771450, MS2OuterGlowCharacterMaterial, SetupTransformPipeline, 2298, 0xBCE57F41);

// NiImplementRTTI(MS2OuterGlowCharacterMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d490-0x14014d4b0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d490
const NiRTTI MS2OuterGlowCharacterMaterial::ms_RTTI("MS2OuterGlowCharacterMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2OuterGlowCharacterMaterial@@6B@ 0x1431d2fa8
// MS2-PIN: ?GetRTTI@MS2OuterGlowCharacterMaterial@@UEBAPEBVNiRTTI@@XZ 0x1427706b0
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
