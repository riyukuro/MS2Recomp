// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MRTShaderPickerMaterial: an MS2StandardMaterial variant
// that writes three render targets for picking: the world position, the normalized world normal and the base map's
// UV set run through the UVColorToFloat4 fragment (sampling custom map 00). The vertex side passes the world position
// and normal through as texture coordinates; the ctor sets the character-lighting flag. No __FILE__ strings; file
// name guessed from the class name.
// MS2-UNIT: ?\mrtshaderpickermaterial.cpp
// MS2-RANGE: 0x14276d340-0x14276e620 .text$mn
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
// @0x14276d340
MRTShaderPickerMaterial::MRTShaderPickerMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MRTShaderPickerMaterial", "MS2StandardMaterial", 6, bAutoCreateCaches)
{
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x14276d440
bool MRTShaderPickerMaterial::ConvertFloat2ToFloat4(Context& kContext, NiMaterialResource* pkInput,
    NiMaterialResource*& pkOutput)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("Float2ToFloat4");
    if (!pkNode)
        return false;

    kContext.m_spConfigurator->AddNode(pkNode);
    if (!kContext.m_spConfigurator->AddBinding(pkInput, pkNode->GetInputResourceByVariableName("Input")))
        return false;

    pkOutput = pkNode->GetOutputResourceByVariableName("Output");
    return true;
}
MS2_REPLACE_METHOD(0x14276D440, MRTShaderPickerMaterial, ConvertFloat2ToFloat4, 238, 0x0AF14C7B);

//--------------------------------------------------------------------------------------------------
// @0x14276d530
bool MRTShaderPickerMaterial::ConvertFloat3ToFloat4(Context& kContext, NiMaterialResource* pkInput,
    NiMaterialResource*& pkOutput)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("Float3ToFloat4");
    if (!pkNode)
        return false;

    kContext.m_spConfigurator->AddNode(pkNode);
    if (!kContext.m_spConfigurator->AddBinding(pkInput, pkNode->GetInputResourceByVariableName("Input")))
        return false;

    pkOutput = pkNode->GetOutputResourceByVariableName("Output");
    return true;
}
MS2_REPLACE_METHOD(0x14276D530, MRTShaderPickerMaterial, ConvertFloat3ToFloat4, 238, 0x42C816DE);

//--------------------------------------------------------------------------------------------------
// @0x14276d620
bool MRTShaderPickerMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
{
    NiStandardPixelProgramDescriptor* pkPixelDesc = (NiStandardPixelProgramDescriptor*)pkDesc;

    kContext.m_spConfigurator->SetDescription(pkPixelDesc->ToString());

    if (!AddDefaultMaterialNodes(kContext, pkDesc, NiGPUProgram::PROGRAM_PIXEL))
        return false;

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

    NiMaterialResource* apkUVSets[STANDARD_PIPE_MAX_UVS_FOR_TEXTURES];
    unsigned int uiNumStandardUVs = 0;
    unsigned int uiDynamicEffectCount = 0;

    if (!HandlePixelUVSets(kContext, pkPixelDesc, apkUVSets, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES,
        uiNumStandardUVs, uiDynamicEffectCount))
    {
        return false;
    }

    if (!HandleMRTOutputs(kContext, pkPixelDesc, apkUVSets))
        return false;

    return true;
}
MS2_REPLACE_METHOD(0x14276D620, MRTShaderPickerMaterial, GeneratePixelShadeTree, 397, 0xF9FCE351);

//--------------------------------------------------------------------------------------------------
// @0x14276d7b0
bool MRTShaderPickerMaterial::GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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

    if (!HandleVertexUVSets(kContext, pkVertexDesc, pkWorldPos, pkWorldNormal, NULL))
        return false;

    return true;
}
MS2_REPLACE_METHOD(0x14276D7B0, MRTShaderPickerMaterial, GenerateVertexShadeTree, 454, 0xC66E569B);

//--------------------------------------------------------------------------------------------------
// @0x14276d990
bool MRTShaderPickerMaterial::HandleMRTOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource** apkUVSets)
{
    NiMaterialResource* pkWorldPos = kContext.m_spInputs->GetOutputResourceByVariableName("WorldPos");
    NiMaterialResource* pkOutPosition = kContext.m_spOutputs->AddInputResource("float4", "Color", "",
        "OutPosition");
    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkOutPosition);

    NiMaterialResource* pkWorldNormal = kContext.m_spInputs->GetOutputResourceByVariableName("WorldNormal");
    if (!NormalizeVector(kContext, pkWorldNormal))
        return false;
    if (!ConvertFloat3ToFloat4(kContext, pkWorldNormal, pkWorldNormal))
        return false;

    NiMaterialResource* pkOutNormal = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "OutNormal");
    kContext.m_spConfigurator->AddBinding(pkWorldNormal, pkOutNormal);

    NiMaterialResource* pkOutTexCoord = kContext.m_spOutputs->AddInputResource("float4", "Color", "",
        "OutBaseTexCoord");

    unsigned int uiUVSet = FindUVSetIndexForTextureEnum(MAP_BASE, pkPixDesc);
    if (uiUVSet != UINT_MAX)
    {
        NiMaterialResource* pkUVColor;
        if (!ConvertUVColorToFloat4(kContext, apkUVSets[uiUVSet], pkUVColor))
            return false;
        kContext.m_spConfigurator->AddBinding(pkUVColor, pkOutTexCoord);
    }
    else
    {
        NiMaterialResource* pkZero = kContext.m_spStatics->AddOutputConstant("float4", "(0.0, 0.0, 0.0, 0.0)");
        kContext.m_spConfigurator->AddBinding(pkZero, pkOutTexCoord);
    }

    return true;
}
MS2_REPLACE_METHOD(0x14276D990, MRTShaderPickerMaterial, HandleMRTOutputs, 888, 0xAE7EAD17);

//--------------------------------------------------------------------------------------------------
// @0x14276dd10
bool MRTShaderPickerMaterial::HandlePixelInputs(Context& kContext, NiStandardPixelProgramDescriptor*,
    NiMaterialResource*& pkPixelWorldPos, NiMaterialResource*& pkPixelWorldNorm, NiMaterialResource*&,
    NiMaterialResource*&, NiMaterialResource*&, NiMaterialResource*&)
{
    pkPixelWorldPos = kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "", "WorldPos");
    pkPixelWorldNorm = kContext.m_spInputs->AddOutputResource("float3", "TexCoord", "", "WorldNormal");
    if (!NormalizeVector(kContext, pkPixelWorldNorm))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14276DD10, MRTShaderPickerMaterial, HandlePixelInputs, 398, 0xF2CCDEE2);

//--------------------------------------------------------------------------------------------------
// @0x14276dea0
bool MRTShaderPickerMaterial::HandleVertexUVSets(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
    NiMaterialResource*, NiMaterialResource*, NiMaterialResource*)
{
    unsigned int uiNextUVSet = 0;
    NiMaterialResource* apkOutputUVs[STANDARD_PIPE_MAX_UVS_FOR_TEXTURES];
    memset(apkOutputUVs, 0, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES * sizeof(NiMaterialResource*));

    if (!HandleTextureUVSets(kContext, pkVertDesc, apkOutputUVs, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES, uiNextUVSet))
        return false;

    for (unsigned int ui = 0; ui < uiNextUVSet; ui++)
    {
        NiMaterialResource* pkVertOutTexCoord = kContext.m_spOutputs->AddInputResource(
            apkOutputUVs[ui]->GetType(), "TexCoord", "", GenerateUVSetName(ui));
        kContext.m_spConfigurator->AddBinding(apkOutputUVs[ui], pkVertOutTexCoord);
    }

    return true;
}
MS2_REPLACE_METHOD(0x14276DEA0, MRTShaderPickerMaterial, HandleVertexUVSets, 391, 0xA54D2D66);

//--------------------------------------------------------------------------------------------------
// @0x14276e030
bool MRTShaderPickerMaterial::SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
    NiStandardVertexProgramDescriptor* pkVertexDesc, bool, bool bForceViewPos, NiMaterialResource*& pkWorldPos,
    NiMaterialResource*& pkViewPos, NiMaterialResource*& pkProjectedPos, NiMaterialResource*& pkWorldNormal,
    NiMaterialResource*& pkWorldView)
{
    pkWorldPos = NULL;
    pkWorldNormal = NULL;
    pkWorldView = NULL;

    NiMaterialResource* pkWorldMatrix = NULL;

    if (!HandlePositionFragment(kContext, (TransformType)pkVertexDesc->GetTRANSFORM(), pkWorldPos, pkWorldMatrix))
        return false;

    NiMaterialResource* pkWorldBinormal = NULL;
    NiMaterialResource* pkWorldTangent = NULL;
    NormalType eNormType = (NormalType)pkVertexDesc->GetNORMAL();

    if (!HandleNormalFragment(kContext, eNormType, pkWorldMatrix, pkWorldNormal, pkWorldBinormal, pkWorldTangent))
        return false;

    if (!HandlePostWorldTransform(kContext, pkVertexDesc, pkWorldPos, pkWorldNormal))
        return false;

    if (!HandleViewProjectionFragment(kContext, bForceViewPos, pkWorldPos, pkProjectedPos, pkViewPos))
        return false;

    if (!pkProjectedPos || !pkOutProjPos)
        return false;

    kContext.m_spConfigurator->AddBinding(pkProjectedPos, pkOutProjPos);

    // world position and normal go to the pixel shader as texture coordinates
    NiMaterialResource* pkVertOutWorldPos = kContext.m_spOutputs->AddInputResource("float4", "TexCoord", "",
        "WorldPos");
    kContext.m_spOutputs->AddOutputResource("float4", "TexCoord", "", "WorldPos");
    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkVertOutWorldPos);

    if (eNormType != NORMAL_NONE)
    {
        NiMaterialResource* pkVertOutWorldNormal = kContext.m_spOutputs->AddInputResource("float3", "TexCoord", "",
            "WorldNormal");
        kContext.m_spOutputs->AddOutputResource("float3", "TexCoord", "", "WorldNormal");
        kContext.m_spConfigurator->AddBinding(pkWorldNormal, pkVertOutWorldNormal);
    }

    return true;
}
MS2_REPLACE_METHOD(0x14276E030, MRTShaderPickerMaterial, SetupTransformPipeline, 1082, 0x5AF2CA6A);

//--------------------------------------------------------------------------------------------------
// @0x14276e470
bool MRTShaderPickerMaterial::ConvertUVColorToFloat4(Context& kContext, NiMaterialResource* pkInput,
    NiMaterialResource*& pkOutput)
{
    NiFixedString kSamplerName;
    unsigned int uiOccurance = 0;
    if (!GetTextureNameFromTextureEnum(MAP_CUSTOM00, kSamplerName, uiOccurance))
        return false;

    NiMaterialResource* pkSampler = InsertTextureSampler(kContext, kSamplerName, TEXTURE_SAMPLER_2D, uiOccurance);
    if (!pkSampler)
        return false;

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("UVColorToFloat4");
    if (!pkNode)
        return false;

    kContext.m_spConfigurator->AddNode(pkNode);
    bool bSuccess = kContext.m_spConfigurator->AddBinding(pkInput, pkNode->GetInputResourceByVariableName("Input"));
    bSuccess &= kContext.m_spConfigurator->AddBinding(pkSampler,
        pkNode->GetInputResourceByVariableName("ControlSampler"));
    if (!bSuccess)
        return false;

    pkOutput = pkNode->GetOutputResourceByVariableName("Output");
    return true;
}
MS2_REPLACE_METHOD(0x14276E470, MRTShaderPickerMaterial, ConvertUVColorToFloat4, 419, 0x586A74FB);

// NiImplementRTTI(MRTShaderPickerMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d450-0x14014d470 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d450
const NiRTTI MRTShaderPickerMaterial::ms_RTTI("MRTShaderPickerMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MRTShaderPickerMaterial@@6B@ 0x1431d25f0
// MS2-PIN: ?GetRTTI@MRTShaderPickerMaterial@@UEBAPEBVNiRTTI@@XZ 0x14276d980
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
