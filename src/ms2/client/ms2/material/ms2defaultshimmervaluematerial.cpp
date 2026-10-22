// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2DefaultShimmerValueMaterial: an MS2StandardMaterial
// variant that writes the neutral shimmer (distortion) value. The shade trees are the standard ones without fog and
// without the per-pass extras: the vertex shader only forwards the texture coordinates, and the pixel shader writes
// the constant (0.5, 0.5, 0.0) offset (no distortion) with the material opacity through CompositeFinalRGBAColor. No
// __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2defaultshimmervaluematerial.cpp
// MS2-RANGE: 0x1427728f0-0x142773900 .text$mn
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
#include "ms2/client/ms2/material/ms2materials.h"
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x1427728f0
MS2DefaultShimmerValueMaterial::MS2DefaultShimmerValueMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2DefaultShimmerValueMaterial", "MS2StandardMaterial", 2, bAutoCreateCaches)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2UIMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142772be0
bool MS2DefaultShimmerValueMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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
    bool bSliceTransitions = pkPixelDesc->GetPSSMSLICETRANSITIONSENABLED() == 1;

    if (!HandleLighting(kContext, 0, 0, bSliceTransitions, bSpecular,
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
MS2_REPLACE_METHOD(0x142772BE0, MS2DefaultShimmerValueMaterial, GeneratePixelShadeTree, 1530, 0x44CBFCEF);

//--------------------------------------------------------------------------------------------------
// @0x1427731e0
NiFragmentMaterial::ReturnCode MS2DefaultShimmerValueMaterial::GenerateShaderDescArray(
    NiMaterialDescriptor* pkMaterialDescriptor, RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount,
    unsigned int& uiCountAdded)
{
    ReturnCode eResult = MS2StandardMaterial::GenerateShaderDescArray(pkMaterialDescriptor, pkRenderPasses,
        uiMaxCount, uiCountAdded);
    if (eResult == RC_SUCCESS)
    {
        NiStandardVertexProgramDescriptor* pkVertexDesc =
            (NiStandardVertexProgramDescriptor*)pkRenderPasses[0].m_pkVertexDesc;
        pkVertexDesc->m_kIdentifier = "NiStandardVertexProgramDescriptor";
        NiStandardPixelProgramDescriptor* pkPixelDesc =
            (NiStandardPixelProgramDescriptor*)pkRenderPasses[0].m_pkPixelDesc;
        pkPixelDesc->m_kIdentifier = "NiStandardPixelProgramDescriptor";

        pkVertexDesc->m_pkBitArray[0] &= ~0x600;    // FOGTYPE
        pkPixelDesc->m_pkBitArray[0] &= ~0x800000;  // FOGENABLED
    }

    return eResult;
}
MS2_REPLACE_METHOD(0x1427731E0, MS2DefaultShimmerValueMaterial, GenerateShaderDescArray, 288, 0xD1877463);

//--------------------------------------------------------------------------------------------------
// @0x142773300
bool MS2DefaultShimmerValueMaterial::GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
{
    NiStandardVertexProgramDescriptor* pkVertexDesc = (NiStandardVertexProgramDescriptor*)pkDesc;

    kContext.m_spConfigurator->SetDescription(pkVertexDesc->ToString());

    if (!AddDefaultMaterialNodes(kContext, pkDesc, NiGPUProgram::PROGRAM_VERTEX))
        return false;

    NiMaterialResource* pkVertOutProjPos = kContext.m_spOutputs->AddInputResource("float4", "Position", "World",
        "PosProjected");

    NiMaterialResource* pkWorldPos = NULL;
    NiMaterialResource* pkWorldNormal = NULL;
    NiMaterialResource* pkWorldView = NULL;
    NiMaterialResource* pkViewPos = NULL;
    NiMaterialResource* pkProjectedPos = NULL;

    if (!SetupTransformPipeline(kContext, pkVertOutProjPos, pkVertexDesc, true, false, pkWorldPos, pkViewPos,
        pkProjectedPos, pkWorldNormal, pkWorldView))
    {
        return false;
    }

    if (!HandleVertexLightingAndMaterials(kContext, pkVertexDesc, pkWorldPos, pkWorldNormal, pkWorldView))
        return false;

    return HandleFinalVertexOutputs(kContext, pkVertexDesc, pkWorldPos, pkWorldNormal, NULL, pkViewPos,
        pkProjectedPos) ? true : false;
}
MS2_REPLACE_METHOD(0x142773300, MS2DefaultShimmerValueMaterial, GenerateVertexShadeTree, 521, 0x67E37EC8);

//--------------------------------------------------------------------------------------------------
// @0x142773520
bool MS2DefaultShimmerValueMaterial::HandleMS2FinalPixelOutputs(Context& kContext,
    NiStandardPixelProgramDescriptor* pkPixDesc, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkDiffuseAccum, NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");
    NiMaterialResource* pkNoShimmer = kContext.m_spStatics->AddOutputConstant("float3", "(0.5, 0.5, 0.0)");

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("CompositeFinalRGBAColor");
    kContext.m_spConfigurator->AddNode(pkNode);
    kContext.m_spConfigurator->AddBinding(pkNoShimmer, "FinalColor", pkNode);

    if (pkOpacityAccum)
    {
        HandleAlphaTest(kContext, pkPixDesc, pkOpacityAccum);
        kContext.m_spConfigurator->AddBinding(pkOpacityAccum, "FinalOpacity", pkNode);
    }

    kContext.m_spConfigurator->AddBinding("OutputColor", pkNode, pkPixelOut);
    return true;
}
MS2_REPLACE_METHOD(0x142773520, MS2DefaultShimmerValueMaterial, HandleMS2FinalPixelOutputs, 534, 0x0AE322A2);

//--------------------------------------------------------------------------------------------------
// @0x142773740
bool MS2DefaultShimmerValueMaterial::HandleFinalVertexOutputs(Context& kContext,
    NiStandardVertexProgramDescriptor* pkVertDesc, NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal,
    NiMaterialResource* pkWorldReflect, NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos)
{
    return HandleVertexUVSets(kContext, pkVertDesc, pkWorldPos, pkWorldNormal, pkWorldReflect) ? true : false;
}
MS2_REPLACE_METHOD(0x142773740, MS2DefaultShimmerValueMaterial, HandleFinalVertexOutputs, 44, 0x7E3F03FD);

//--------------------------------------------------------------------------------------------------
// @0x142773770
bool MS2DefaultShimmerValueMaterial::HandleVertexUVSets(Context& kContext,
    NiStandardVertexProgramDescriptor* pkVertDesc, NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal,
    NiMaterialResource* pkWorldReflect)
{
    unsigned int uiNextUVIndex = 0;
    NiMaterialResource* apkOutputUVs[STANDARD_PIPE_MAX_UVS_FOR_TEXTURES];
    memset(apkOutputUVs, 0, sizeof(apkOutputUVs));

    if (!HandleTextureUVSets(kContext, pkVertDesc, apkOutputUVs, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES, uiNextUVIndex))
        return false;

    for (unsigned int ui = 0; ui < uiNextUVIndex; ui++)
    {
        NiMaterialResource* pkVertOutTexCoord = kContext.m_spOutputs->AddInputResource(
            apkOutputUVs[ui]->GetType(), "TexCoord", "", GenerateUVSetName(ui));
        kContext.m_spConfigurator->AddBinding(apkOutputUVs[ui], pkVertOutTexCoord);
    }

    return true;
}
MS2_REPLACE_METHOD(0x142773770, MS2DefaultShimmerValueMaterial, HandleVertexUVSets, 391, 0x8BB666E6);

// NiImplementRTTI(MS2DefaultShimmerValueMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di
// run. The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d4f0-0x14014d510 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d4f0
const NiRTTI MS2DefaultShimmerValueMaterial::ms_RTTI("MS2DefaultShimmerValueMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2DefaultShimmerValueMaterial@@6B@ 0x1431d3ca8
// MS2-PIN: ?GetRTTI@MS2DefaultShimmerValueMaterial@@UEBAPEBVNiRTTI@@XZ 0x142773510
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
