// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2GlowMaterial: an MS2StandardMaterial variant for the
// glow pass. The pixel shader skips lighting: it samples the base map for opacity only, takes the glow map alpha
// (multiplied by the detail map alpha when the object has one) as the output color and writes no specular. Fog is
// disabled. No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2glowmaterial.cpp
// MS2-RANGE: 0x142775ba0-0x1427766b0 .text$mn
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
// @0x142775ba0
MS2GlowMaterial::MS2GlowMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2GlowMaterial", "MS2StandardMaterial", 5, bAutoCreateCaches)
{
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142775ca0
bool MS2GlowMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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

    if (pkPixelDesc->GetBASEMAPCOUNT())
    {
        bool bOpacityOnly = pkPixelDesc->GetBASEMAPALPHAONLY() ? true : false;
        if (!HandleBaseMap(kContext, FindUVSetIndexForTextureEnum(MAP_BASE, pkPixelDesc, apkUVSets), pkDiffuseAccum,
            pkOpacityAccum, bOpacityOnly))
        {
            return false;
        }
    }

    HandleGlowColor(kContext, pkPixelDesc, apkUVSets, pkDiffuseAccum, pkSpecularAccum);

    return HandleMS2FinalPixelOutputs(kContext, pkPixelDesc, pkPixelWorldNorm, pkPixelWorldViewVector,
        pkDiffuseAccum, pkSpecularAccum, pkOpacityAccum) ? true : false;
}
MS2_REPLACE_METHOD(0x142775CA0, MS2GlowMaterial, GeneratePixelShadeTree, 965, 0xAB9E2BC4);

//--------------------------------------------------------------------------------------------------
// @0x142776070
NiFragmentMaterial::ReturnCode MS2GlowMaterial::GenerateShaderDescArray(NiMaterialDescriptor* pkMaterialDescriptor,
    RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount, unsigned int& uiCountAdded)
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

        pkPixelDesc->m_pkBitArray[0] &= ~0x800000;  // FOGENABLED
        pkPixelDesc->m_pkBitArray[3] |= 0x400000;   // BASEMAPALPHAONLY
    }

    return eResult;
}
MS2_REPLACE_METHOD(0x142776070, MS2GlowMaterial, GenerateShaderDescArray, 289, 0x20D415C3);

//--------------------------------------------------------------------------------------------------
// @0x1427761b0
bool MS2GlowMaterial::HandleGlowColor(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
    NiMaterialResource** apkUVSets, NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum)
{
    pkSpecularAccum = kContext.m_spStatics->AddOutputConstant("float3", "(0.0, 0.0, 0.0)");

    if (pkPixelDesc->GetGLOWMAPCOUNT())
    {
        if (pkPixelDesc->GetDETAILMAPCOUNT())
        {
            NiMaterialResource* pkDetailAlpha = kContext.m_spStatics->AddOutputConstant("float", "(0.0)");
            NiMaterialResource* pkDetailUV = FindUVSetIndexForTextureEnum(MAP_DETAIL, pkPixelDesc, apkUVSets);
            if (!InsertTexture(kContext, MAP_DETAIL, 0, TEXTURE_RGB_APPLY_NOOP, TEXTURE_SAMPLE_A, pkDetailUV, NULL,
                NULL, pkDiffuseAccum, pkDetailAlpha))
            {
                return false;
            }

            NiMaterialResource* pkGlowAlpha = kContext.m_spStatics->AddOutputConstant("float", "(0.0)");
            NiMaterialResource* pkGlowUV = FindUVSetIndexForTextureEnum(MAP_GLOW, pkPixelDesc, apkUVSets);
            if (!InsertTexture(kContext, MAP_GLOW, 0, TEXTURE_RGB_APPLY_NOOP, TEXTURE_SAMPLE_A, pkGlowUV, NULL, NULL,
                pkDiffuseAccum, pkGlowAlpha))
            {
                return false;
            }

            NiMaterialNode* pkMultiply = GetAttachableNodeFromLibrary("MultiplyFloat");
            kContext.m_spConfigurator->AddNode(pkMultiply);
            kContext.m_spConfigurator->AddBinding(pkDetailAlpha, pkMultiply->GetInputResourceByVariableName("V1"));
            kContext.m_spConfigurator->AddBinding(pkGlowAlpha, pkMultiply->GetInputResourceByVariableName("V2"));

            NiMaterialNode* pkToFloat3 = GetAttachableNodeFromLibrary("FloatToFloat3");
            kContext.m_spConfigurator->AddNode(pkToFloat3);
            kContext.m_spConfigurator->AddBinding(pkMultiply->GetOutputResourceByVariableName("Output"),
                pkToFloat3->GetInputResourceByVariableName("Input"));
            pkDiffuseAccum = pkToFloat3->GetOutputResourceByVariableName("Output");
        }
        else
        {
            NiMaterialResource* pkGlowAlpha = kContext.m_spStatics->AddOutputConstant("float", "(0.0)");
            NiMaterialResource* pkUV = FindUVSetIndexForTextureEnum(MAP_GLOW, pkPixelDesc, apkUVSets);
            if (!InsertTexture(kContext, MAP_GLOW, 0, TEXTURE_RGB_APPLY_NOOP, TEXTURE_SAMPLE_A, pkUV, NULL, NULL,
                pkDiffuseAccum, pkGlowAlpha))
            {
                return false;
            }

            NiMaterialNode* pkToFloat3 = GetAttachableNodeFromLibrary("FloatToFloat3");
            kContext.m_spConfigurator->AddNode(pkToFloat3);
            kContext.m_spConfigurator->AddBinding(pkGlowAlpha, pkToFloat3->GetInputResourceByVariableName("Input"));
            pkDiffuseAccum = pkToFloat3->GetOutputResourceByVariableName("Output");
        }
    }
    else
    {
        pkDiffuseAccum = kContext.m_spStatics->AddOutputConstant("float3", "(0.0, 0.0, 0.0)");
    }

    return true;
}
MS2_REPLACE_METHOD(0x1427761B0, MS2GlowMaterial, HandleGlowColor, 1274, 0xD394B7A1);

// NiImplementRTTI(MS2GlowMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run. The hook
// DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d570-0x14014d590 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d570
const NiRTTI MS2GlowMaterial::ms_RTTI("MS2GlowMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2GlowMaterial@@6B@ 0x1431d4cf0
// MS2-PIN: ?GetRTTI@MS2GlowMaterial@@UEBAPEBVNiRTTI@@XZ 0x1427761a0
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
