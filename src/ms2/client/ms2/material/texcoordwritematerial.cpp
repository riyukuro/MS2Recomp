// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TexCoordWriteMaterial: an MS2StandardMaterial variant
// whose pixel shader outputs the base map's texture coordinates as the colour (float2 widened through the
// Float2ToFloat4 fragment). The vertex side keeps only the position transform and the plain texture UV sets; the ctor
// sets the character-lighting flag. No
// __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\texcoordwritematerial.cpp
// MS2-RANGE: 0x14276ca50-0x14276d340 .text$mn
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
// @0x14276ca50
TexCoordWriteMaterial::TexCoordWriteMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("TexCoordWriteMaterial", "MS2StandardMaterial", 1, bAutoCreateCaches)
{
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x14276cb50
bool TexCoordWriteMaterial::ConvertFloat2ToFloat4(Context& kContext, NiMaterialResource* pkInput,
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
MS2_REPLACE_METHOD(0x14276CB50, TexCoordWriteMaterial, ConvertFloat2ToFloat4, 238, 0x5E2A9875);

//--------------------------------------------------------------------------------------------------
// @0x14276cc40
bool TexCoordWriteMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
{
    NiStandardPixelProgramDescriptor* pkPixelDesc = (NiStandardPixelProgramDescriptor*)pkDesc;

    kContext.m_spConfigurator->SetDescription(pkPixelDesc->ToString());

    if (!AddDefaultMaterialNodes(kContext, pkDesc, NiGPUProgram::PROGRAM_PIXEL))
        return false;

    NiMaterialResource* apkUVSets[STANDARD_PIPE_MAX_UVS_FOR_TEXTURES];
    unsigned int uiNumStandardUVs = 0;
    unsigned int uiDynamicEffectCount = 0;

    if (!HandlePixelUVSets(kContext, pkPixelDesc, apkUVSets, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES,
        uiNumStandardUVs, uiDynamicEffectCount))
    {
        return false;
    }

    if (!HandleTexCoordOutput(kContext, pkPixelDesc, apkUVSets))
        return false;

    return true;
}
MS2_REPLACE_METHOD(0x14276CC40, TexCoordWriteMaterial, GeneratePixelShadeTree, 262, 0xB29B5745);

//--------------------------------------------------------------------------------------------------
// @0x14276cd50
bool TexCoordWriteMaterial::GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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
MS2_REPLACE_METHOD(0x14276CD50, TexCoordWriteMaterial, GenerateVertexShadeTree, 454, 0x5CA4FA17);

//--------------------------------------------------------------------------------------------------
// @0x14276cf30
bool TexCoordWriteMaterial::HandleTexCoordOutput(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource** apkUVSets)
{
    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");

    unsigned int uiUVSet = FindUVSetIndexForTextureEnum(MAP_BASE, pkPixDesc);
    if (uiUVSet != UINT_MAX)
    {
        NiMaterialResource* pkTexCoord;
        if (!ConvertFloat2ToFloat4(kContext, apkUVSets[uiUVSet], pkTexCoord))
            return false;
        kContext.m_spConfigurator->AddBinding(pkTexCoord, pkPixelOut);
    }
    else
    {
        NiMaterialResource* pkZero = kContext.m_spStatics->AddOutputConstant("float4", "(0.0, 0.0, 0.0, 0.0)");
        kContext.m_spConfigurator->AddBinding(pkZero, pkPixelOut);
    }

    return true;
}
MS2_REPLACE_METHOD(0x14276CF30, TexCoordWriteMaterial, HandleTexCoordOutput, 402, 0x3466C0B0);

//--------------------------------------------------------------------------------------------------
// @0x14276d0d0
bool TexCoordWriteMaterial::HandleVertexUVSets(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
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
MS2_REPLACE_METHOD(0x14276D0D0, TexCoordWriteMaterial, HandleVertexUVSets, 391, 0x8FE33B71);

//--------------------------------------------------------------------------------------------------
// @0x14276d260
bool TexCoordWriteMaterial::SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
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

    if (!HandleViewProjectionFragment(kContext, bForceViewPos, pkWorldPos, pkProjectedPos, pkViewPos))
        return false;

    if (!pkProjectedPos || !pkOutProjPos)
        return false;

    kContext.m_spConfigurator->AddBinding(pkProjectedPos, pkOutProjPos);
    return true;
}
MS2_REPLACE_METHOD(0x14276D260, TexCoordWriteMaterial, SetupTransformPipeline, 217, 0x2DD25CA5);

// NiImplementRTTI(TexCoordWriteMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run. The
// hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d430-0x14014d450 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d430
const NiRTTI TexCoordWriteMaterial::ms_RTTI("TexCoordWriteMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7TexCoordWriteMaterial@@6B@ 0x1431d20b8
// MS2-PIN: ?GetRTTI@TexCoordWriteMaterial@@UEBAPEBVNiRTTI@@XZ 0x14276cf20
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
