// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CustomizedTextureGeneratorMaterial: the MS2CharacterMaterial
// variant used to bake customized character textures. Its vertex tree only transforms the position and emits the
// MS2 UV sets; its pixel tree runs the pre-light texture stage and hands the texture accumulators straight to the MS2
// final outputs, skipping lighting. No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\customizedtexturegeneratormaterial.cpp
// MS2-RANGE: 0x14276c420-0x14276ca50 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiStandardVertexProgramDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x14276c420
CustomizedTextureGeneratorMaterial::CustomizedTextureGeneratorMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("CustomizedTextureGeneratorMaterial", "MS2CharacterMaterial", 4, bAutoCreateCaches)
{
}

//--------------------------------------------------------------------------------------------------
// @0x14276c510
bool CustomizedTextureGeneratorMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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

    NiMaterialResource* pkMatDiffuse = NULL;
    NiMaterialResource* pkMatSpecular = NULL;
    NiMaterialResource* pkSpecularPower = NULL;
    NiMaterialResource* pkGlossiness = NULL;
    NiMaterialResource* pkMatAmbient = NULL;
    NiMaterialResource* pkMatEmissive = NULL;
    NiMaterialResource* pkTexDiffuseAccum = NULL;
    NiMaterialResource* pkTexSpecularAccum = NULL;
    NiMaterialResource* pkOpacityAccum = NULL;
    NiMaterialResource* pkLightDiffuseAccum = NULL;
    NiMaterialResource* pkLightSpecularAccum = NULL;
    NiMaterialResource* pkLightAmbientAccum = NULL;

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

    if (!HandleMS2FinalPixelOutputs(kContext, pkPixelDesc, pkPixelWorldNorm, pkPixelWorldViewVector,
        pkTexDiffuseAccum, pkTexSpecularAccum, pkOpacityAccum))
    {
        return false;
    }

    return true;
}
MS2_REPLACE_METHOD(0x14276C510, CustomizedTextureGeneratorMaterial, GeneratePixelShadeTree, 844, 0xC2279B23);

//--------------------------------------------------------------------------------------------------
// @0x14276c860
bool CustomizedTextureGeneratorMaterial::GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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

    if (!SetupTransformPipeline(kContext, pkVertOutProjPos, pkVertexDesc, false, false, pkWorldPos, pkViewPos,
        pkProjectedPos, pkWorldNormal, pkWorldView))
    {
        return false;
    }

    if (!HandleMS2VertexUVSets(kContext, pkVertexDesc, pkWorldPos, pkWorldNormal, NULL, pkProjectedPos))
        return false;

    return true;
}
MS2_REPLACE_METHOD(0x14276C860, CustomizedTextureGeneratorMaterial, GenerateVertexShadeTree, 463, 0x5229F208);

// NiImplementRTTI(CustomizedTextureGeneratorMaterial, MS2StandardMaterial): the initializer sits in the shared
// .text$di run. The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d410-0x14014d430 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d410
const NiRTTI CustomizedTextureGeneratorMaterial::ms_RTTI("CustomizedTextureGeneratorMaterial",
    &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7CustomizedTextureGeneratorMaterial@@6B@ 0x1431d1c30
// MS2-PIN: ?GetRTTI@CustomizedTextureGeneratorMaterial@@UEBAPEBVNiRTTI@@XZ 0x14276ca30
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
