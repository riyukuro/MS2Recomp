// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2TextureDensityMaterial: an MS2StandardMaterial
// variant for the texture density debug view. The pixel shader applies the pre-light textures and writes the
// diffuse texture color straight out through the DiffuseOnly node, without lighting. No __FILE__ strings; file name
// guessed from the class name.
// MS2-UNIT: ?\ms2texturedensitymaterial.cpp
// MS2-RANGE: 0x1427766b0-0x142776e50 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x1427766b0
MS2TextureDensityMaterial::MS2TextureDensityMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2TextureDensityMaterial", "MS2StandardMaterial", 3, bAutoCreateCaches)
{
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142776850
bool MS2TextureDensityMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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

    unsigned int uiLightCount = pkPixelDesc->GetPOINTLIGHTCOUNT() + pkPixelDesc->GetDIRLIGHTCOUNT() +
        pkPixelDesc->GetSPOTLIGHTCOUNT();
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
        uiLightCount, bSpecular, eLightingMode, pkMatDiffuse,
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

    return HandleMS2FinalPixelOutputs(kContext, pkPixelDesc, pkPixelWorldNorm, pkPixelWorldViewVector,
        pkDiffuseAccum, pkSpecularAccum, pkOpacityAccum) ? true : false;
}
MS2_REPLACE_METHOD(0x142776850, MS2TextureDensityMaterial, GeneratePixelShadeTree, 1076, 0xBBE9B519);

//--------------------------------------------------------------------------------------------------
// @0x142776ca0
bool MS2TextureDensityMaterial::HandleMS2FinalPixelOutputs(Context& kContext,
    NiStandardPixelProgramDescriptor* pkPixDesc, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkDiffuseAccum, NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("DiffuseOnly");
    kContext.m_spConfigurator->AddNode(pkNode);

    if (pkDiffuseAccum)
        kContext.m_spConfigurator->AddBinding(pkDiffuseAccum, "DiffuseColor", pkNode);

    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");
    kContext.m_spConfigurator->AddBinding(pkNode->GetOutputResourceByVariableName("Output"), pkPixelOut);
    return true;
}
MS2_REPLACE_METHOD(0x142776CA0, MS2TextureDensityMaterial, HandleMS2FinalPixelOutputs, 431, 0x6586C238);

// NiImplementRTTI(MS2TextureDensityMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d590-0x14014d5b0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d590
const NiRTTI MS2TextureDensityMaterial::ms_RTTI("MS2TextureDensityMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2TextureDensityMaterial@@6B@ 0x1431d5100
// MS2-PIN: ?GetRTTI@MS2TextureDensityMaterial@@UEBAPEBVNiRTTI@@XZ 0x142776c90
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
