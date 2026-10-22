// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2StandardMaterial: NiStandardMaterial plus the MS2 material
// node library, the MS2 light nodes (half-lambert character light, lambSkin, hair tangents, rim light), the dye/decal colour
// override of characters, screen-projected environment maps, the glow modifier and the chaos rim (see ms2materials.h).
// No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2standardmaterial.cpp
// MS2-RANGE: 0x14274d700-0x142754a60 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardMaterialNodeLibrary.h>
#include <NiStandardMaterialDescriptor.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiStandardVertexProgramDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceBinding.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiShader.h>
#include <NiShaderDeclaration.h>
#include <NiSemanticAdapterTable.h>
#include <NiCommonSemantics.h>
#include <NiRenderObject.h>
#include <NiTextureEffect.h>
#include <NiShadowManager.h>
#include <NiPSSMShadowClickGenerator.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"
#include "hook/ms2hook.h"

// The vertex/geometry/pixel program versions MS2 registers its materials with.
#define MS2_MATERIAL_PROGRAM_VERSION 0x5d

// "TransformSkinnedPosition60" (the 60-bone skinning fragment of MS2MaterialNodeLibrary); an initialized .data pointer
// of another unit.
extern const char* g_pcTransformSkinnedPosition60;

//--------------------------------------------------------------------------------------------------
// @0x14274d700
MS2StandardMaterial::MS2StandardMaterial(const NiFixedString& kName, const NiFixedString& kTypeName, unsigned int
    uiVersionOffset, bool bAutoCreateCaches) : NiStandardMaterial(kName, NULL, uiVersionOffset +
    MS2_MATERIAL_PROGRAM_VERSION, uiVersionOffset + MS2_MATERIAL_PROGRAM_VERSION, uiVersionOffset +
    MS2_MATERIAL_PROGRAM_VERSION, bAutoCreateCaches)
{
    Init(kTypeName);
}

//--------------------------------------------------------------------------------------------------
// @0x14274d770
MS2StandardMaterial::MS2StandardMaterial(const NiFixedString& kName, bool bAutoCreateCaches) :
    NiStandardMaterial(kName, NULL, MS2_MATERIAL_PROGRAM_VERSION, MS2_MATERIAL_PROGRAM_VERSION,
        MS2_MATERIAL_PROGRAM_VERSION, bAutoCreateCaches)
{
    Init(kName);
}

//--------------------------------------------------------------------------------------------------
// @0x14274d840
bool MS2StandardMaterial::AlphaBlendColors(Context& kContext, NiMaterialResource* pkColor1,
    NiMaterialResource* pkColor2, NiMaterialResource* pkAlpha, NiMaterialResource*& pkResult)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("AlphaBlendColors");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    bool bResult = true;
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor1,
        pkNode->GetInputResourceByVariableName("SrcColor1"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor2,
        pkNode->GetInputResourceByVariableName("SrcColor2"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkAlpha,
        pkNode->GetInputResourceByVariableName("Alpha"));
    if (!bResult)
        return false;

    pkResult = pkNode->GetOutputResourceByVariableName("ColorOut");
    return true;
}
MS2_REPLACE_METHOD(0x14274D840, MS2StandardMaterial, AlphaBlendColors, 379, 0x71B697EE);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: register allocation and block order differ (same calls and bindings)
// @0x14274d9c0
bool MS2StandardMaterial::HandleColorOverride(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource** apkUVSets, NiMaterialResource*& pkDiffuseTexAccum)
{
    NiMaterialResource* pkColor = NULL;
    if (!pkPixDesc->GetCUSTOMMAP00COUNT())
    {
        pkColor = pkDiffuseTexAccum;
    }
    else
    {
        // dye: custom map 00 holds the per-channel weights of the three override colours
        NiMaterialResource* pkControl = NULL;
        NiMaterialResource* pkUV = FindUVSetIndexForTextureEnum(MAP_CUSTOM00, pkPixDesc, apkUVSets);
        if (!pkUV)
            return false;
        if (!InsertTextureSample(kContext, MAP_CUSTOM00, pkUV, pkControl))
            return false;

        NiMaterialResource* pkColor0 = AddOutputAttribute(kContext.m_spUniforms, "OverrideColor0",
            NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
        NiMaterialResource* pkColor1 = AddOutputAttribute(kContext.m_spUniforms, "OverrideColor1",
            NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
        NiMaterialResource* pkColor2 = AddOutputAttribute(kContext.m_spUniforms, "OverrideColor2",
            NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
        if (!ColorOverride(kContext, pkDiffuseTexAccum, pkControl, pkColor0, pkColor1, pkColor2, pkColor))
            return false;
    }

    if (m_eMaterialType == 3 || !pkPixDesc->GetCUSTOMMAP01COUNT())
    {
        pkDiffuseTexAccum = pkColor;
        return true;
    }

    // decal: custom map 01 (own UV transform), custom map 02 recolours it like the dye
    NiMaterialResource* pkDecal = NULL;
    NiMaterialResource* pkDecalColor = NULL;
    NiMaterialResource* pkDecalAlpha = NULL;
    NiMaterialResource* pkDecalSample = NULL;
    NiMaterialResource* pkUV = FindUVSetIndexForTextureEnum(MAP_CUSTOM01, pkPixDesc, apkUVSets);
    if (!pkUV)
        return false;

    NiMaterialResource* pkTransform = AddOutputAttribute(kContext.m_spUniforms, "DecalMapTransform",
        NiShaderAttributeDesc::ATTRIB_TYPE_POINT4);
    NiMaterialResource* pkDecalUV = NULL;
    if (!TransformTexCoord(kContext, pkUV, pkTransform, pkDecalUV))
        return false;
    if (!InsertTextureSample(kContext, MAP_CUSTOM01, pkDecalUV, pkDecalSample))
        return false;
    if (!SplitColorAndOpacity(kContext, pkDecalSample, pkDecalColor, pkDecalAlpha))
        return false;

    if (!pkPixDesc->GetCUSTOMMAP02COUNT())
    {
        pkDecal = pkDecalColor;
    }
    else
    {
        NiMaterialResource* pkControl = NULL;
        if (!InsertTextureSample(kContext, MAP_CUSTOM02, pkDecalUV, pkControl))
            return false;

        NiMaterialResource* pkColor0 = AddOutputAttribute(kContext.m_spUniforms, "DecalOverrideColor0",
            NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
        NiMaterialResource* pkColor1 = AddOutputAttribute(kContext.m_spUniforms, "DecalOverrideColor1",
            NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
        NiMaterialResource* pkColor2 = AddOutputAttribute(kContext.m_spUniforms, "DecalOverrideColor2",
            NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
        if (!DecalColorOverride(kContext, pkDecalColor, pkControl, pkColor0, pkColor1, pkColor2, pkDecal))
            return false;
    }

    return AlphaBlendColors(kContext, pkColor, pkDecal, pkDecalAlpha, pkDiffuseTexAccum);
}
MS2_REPLACE_METHOD(0x14274D9C0, MS2StandardMaterial, HandleColorOverride, 1068, 0xF80811D6);

//--------------------------------------------------------------------------------------------------
// @0x14274ddf0
bool MS2StandardMaterial::ColorOverride(Context& kContext, NiMaterialResource* pkDiffuseTexAccum,
    NiMaterialResource* pkControl, NiMaterialResource* pkColor0, NiMaterialResource* pkColor1,
    NiMaterialResource* pkColor2, NiMaterialResource*& pkResult)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("ColorOverride");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    bool bResult = true;
    bResult &= kContext.m_spConfigurator->AddBinding(pkControl,
        pkNode->GetInputResourceByVariableName("ColorOverrideControl"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkDiffuseTexAccum,
        pkNode->GetInputResourceByVariableName("DiffuseTexAccum"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor0,
        pkNode->GetInputResourceByVariableName("Color0"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor1,
        pkNode->GetInputResourceByVariableName("Color1"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor2,
        pkNode->GetInputResourceByVariableName("Color2"));
    if (!bResult)
        return false;

    pkResult = pkNode->GetOutputResourceByVariableName("DiffuseTexAccumOut");
    return true;
}
MS2_REPLACE_METHOD(0x14274DDF0, MS2StandardMaterial, ColorOverride, 511, 0xB7DC76A2);

//--------------------------------------------------------------------------------------------------
// @0x14274dff0
bool MS2StandardMaterial::DecalColorOverride(Context& kContext, NiMaterialResource* pkDiffuseTexAccum,
    NiMaterialResource* pkControl, NiMaterialResource* pkColor0, NiMaterialResource* pkColor1,
    NiMaterialResource* pkColor2, NiMaterialResource*& pkResult)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("DecalColorOverride");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    bool bResult = true;
    bResult &= kContext.m_spConfigurator->AddBinding(pkControl,
        pkNode->GetInputResourceByVariableName("ColorOverrideControl"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkDiffuseTexAccum,
        pkNode->GetInputResourceByVariableName("DiffuseTexAccum"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor0,
        pkNode->GetInputResourceByVariableName("Color0"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor1,
        pkNode->GetInputResourceByVariableName("Color1"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkColor2,
        pkNode->GetInputResourceByVariableName("Color2"));
    if (!bResult)
        return false;

    pkResult = pkNode->GetOutputResourceByVariableName("DiffuseTexAccumOut");
    return true;
}
MS2_REPLACE_METHOD(0x14274DFF0, MS2StandardMaterial, DecalColorOverride, 511, 0xF072B86D);

//--------------------------------------------------------------------------------------------------
// @0x14274e1f0
bool MS2StandardMaterial::Float4ToFloat3(Context& kContext, NiMaterialResource* pkInput,
    NiMaterialResource*& pkOutput)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("Float4ToFloat3");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    if (!kContext.m_spConfigurator->AddBinding(pkInput, pkNode->GetInputResourceByVariableName("Input")))
        return false;

    pkOutput = pkNode->GetOutputResourceByVariableName("Output");
    return true;
}
MS2_REPLACE_METHOD(0x14274E1F0, MS2StandardMaterial, Float4ToFloat3, 238, 0xB5A91F7A);

//--------------------------------------------------------------------------------------------------
// @0x14274e2e0
bool MS2StandardMaterial::GenerateDescriptor(const NiRenderObject* pkGeometry, const NiPropertyState* pkState,
    const NiDynamicEffectState* pkEffects, NiMaterialDescriptor& kMaterialDesc)
{
    if (!NiStandardMaterial::GenerateDescriptor(pkGeometry, pkState, pkEffects, kMaterialDesc))
        return false;

    // USERDEFINED02: a second vertex colour stream (VertexBrightness)
    if (pkGeometry->ContainsData(NiCommonSemantics::COLOR(), 1))
        kMaterialDesc.m_pkBitArray[3] |= 0x4000000;

    // USERDEFINED00: glow scaled by the GlowModifier attribute
    if (pkGeometry->GetExtraData("GlowModifier"))
    {
        unsigned int* puiBits = kMaterialDesc.m_pkBitArray + 3;
        *puiBits |= 0x1000000;
    }

    return true;
}
MS2_REPLACE_METHOD(0x14274E2E0, MS2StandardMaterial, GenerateDescriptor, 169, 0x2B239A86);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: block layout and register allocation differ (same node graph)
// @0x14274e390
bool MS2StandardMaterial::GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc)
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
    m_pkDetailOpacity = NULL;

    if (!HandlePreLightTextureApplication(kContext, pkPixelDesc, pkPixelWorldPos, pkPixelWorldNorm,
        pkPixelWorldBinormal, pkPixelWorldTangent, pkPixelWorldViewVector, pkPixelTangentViewVector,
        pkMatDiffuse, pkMatSpecular, pkSpecularPower, pkGlossiness, pkMatAmbient, pkMatEmissive, pkOpacityAccum,
        pkLightAmbientAccum, pkLightDiffuseAccum, pkLightSpecularAccum, pkTexDiffuseAccum, pkTexSpecularAccum,
        uiTexturesApplied, apkUVSets, uiNumStandardUVs, uiDynamicEffectCount))
    {
        return false;
    }

    if (pkOpacityAccum || m_pkDetailOpacity)
        MultiplyVector(kContext, pkOpacityAccum, m_pkDetailOpacity, pkOpacityAccum);

    // hair: the tangent comes from a colour map (custom 01) in tangent space
    NiMaterialResource* pkHairTangent = NULL;
    if (m_eMaterialType == 3)
    {
        if (pkPixelDesc->GetBASEMAPCOUNT())
        {
            if (!InsertTextureSample(kContext, MAP_CUSTOM01,
                FindUVSetIndexForTextureEnum(MAP_BASE, pkPixelDesc, apkUVSets), pkHairTangent))
            {
                return false;
            }

            NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("CalculateHairTangentFromColor");
            kContext.m_spConfigurator->AddNode(pkNode);
            kContext.m_spConfigurator->AddBinding(pkHairTangent,
                pkNode->GetInputResourceByVariableName("LocalHairTangentColor"));
            if (pkPixelWorldNorm)
            {
                kContext.m_spConfigurator->AddBinding(pkPixelWorldNorm,
                    pkNode->GetInputResourceByVariableName("WorldNormalIn"));
            }
            if (pkPixelWorldBinormal)
            {
                kContext.m_spConfigurator->AddBinding(pkPixelWorldBinormal,
                    pkNode->GetInputResourceByVariableName("WorldBinormalIn"));
            }
            if (pkPixelWorldTangent)
            {
                kContext.m_spConfigurator->AddBinding(pkPixelWorldTangent,
                    pkNode->GetInputResourceByVariableName("WorldTangentIn"));
            }
            pkHairTangent = pkNode->GetOutputResourceByVariableName("WorldHairTangent");
            if (!pkHairTangent)
                return false;
        }
        else
        {
            NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("CalculateHairTangentFromColor");
            pkHairTangent = pkNode->GetOutputResourceByVariableName("WorldHairTangent");
        }
    }

    unsigned int uiShadowMapForLight = pkPixelDesc->GetSHADOWMAPFORLIGHT();
    unsigned int uiShadowTechnique = pkPixelDesc->GetSHADOWTECHNIQUE();
    NiUInt32 uiPSSMWhichLight = pkPixelDesc->GetPSSMWHICHLIGHT();
    NiUInt32 uiShadowAtlasCells = NiPSSMShadowClickGenerator::DecodeDescriptorMaxSliceCount(
        pkPixelDesc->GetPSSMSLICECOUNT());
    bool bSliceTransitions = pkPixelDesc->GetPSSMSLICETRANSITIONSENABLED() == 1;

    NiMaterialResource* pkLightSpecular = NULL;
    if (!HandleMS2Lighting(kContext, uiShadowAtlasCells, uiPSSMWhichLight, bSliceTransitions, bSpecular,
        uiPointLightCount, uiDirLightCount, uiSpotLightCount, uiShadowMapForLight, uiShadowTechnique,
        pkPixelWorldPos, pkPixelWorldNorm, pkPixelWorldViewVector, pkSpecularPower, pkLightAmbientAccum,
        pkLightDiffuseAccum, pkLightSpecularAccum, pkLightSpecular, pkHairTangent))
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
        uiNumStandardUVs, uiDynamicEffectCount, pkLightSpecular))
    {
        return false;
    }

    if (!HandleColorBoost(kContext, pkPixelDesc, pkDiffuseAccum))
        return false;

    return HandleMS2FinalPixelOutputs(kContext, pkPixelDesc, pkPixelWorldNorm, pkPixelWorldViewVector,
        pkDiffuseAccum, pkSpecularAccum, pkOpacityAccum);
}
MS2_REPLACE_METHOD(0x14274E390, MS2StandardMaterial, GeneratePixelShadeTree, 2225, 0xFAB40BEF);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: exe keeps the base result in edi with a different frame; same behaviour
// @0x14274ec50
NiFragmentMaterial::ReturnCode MS2StandardMaterial::GenerateShaderDescArray(
    NiMaterialDescriptor* pkMaterialDescriptor, RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount,
    unsigned int& uiCountAdded)
{
    ReturnCode eResult = NiStandardMaterial::GenerateShaderDescArray(pkMaterialDescriptor, pkRenderPasses,
        uiMaxCount, uiCountAdded);
    if (eResult != RC_SUCCESS)
        return eResult;

    NiStandardVertexProgramDescriptor* pkVertexDesc =
        (NiStandardVertexProgramDescriptor*)pkRenderPasses[0].m_pkVertexDesc;
    NiStandardPixelProgramDescriptor* pkPixelDesc =
        (NiStandardPixelProgramDescriptor*)pkRenderPasses[0].m_pkPixelDesc;
    pkVertexDesc->m_kIdentifier = "NiStandardVertexProgramDescriptor";
    pkPixelDesc->m_kIdentifier = "NiStandardPixelProgramDescriptor";

    unsigned int* puiMaterialBits = pkMaterialDescriptor->m_pkBitArray;

    // characters with APPLYMODE set get a world view vector in both stages
    if ((unsigned int)(m_eMaterialType - 1) <= 2 && ((puiMaterialBits[0] >> 9) & 1))
    {
        pkVertexDesc->m_pkBitArray[0] |= 0x10;  // OUTPUTWORLDVIEW
        pkPixelDesc->m_pkBitArray[0] |= 0x10;   // WORLDVIEW
    }

    // USERDEFINED02 -> UVSET11TEXOUTPUT: pass the second colour stream through
    if (puiMaterialBits[3] & 0x4000000)
        pkVertexDesc->m_pkBitArray[2] |= 0x80;

    // USERDEFINED00 -> GBNB_RESERVED5 bit 1: glow modifier
    if (puiMaterialBits[3] & 0x1000000)
        pkPixelDesc->m_pkBitArray[4] |= 0x40;

    return eResult;
}
MS2_REPLACE_METHOD(0x14274EC50, MS2StandardMaterial, GenerateShaderDescArray, 370, 0x956EA7EC);

//--------------------------------------------------------------------------------------------------
// @0x14274ee10
int MS2StandardMaterial::GetMaterialType(const NiFixedString& kName)
{
    if (kName == "MS2StandardMaterial")
        return 0;
    if (kName == "MS2CharacterMaterial")
        return 1;
    if (kName == "MS2CharacterSkinMaterial")
        return 2;
    if (kName == "MS2CharacterHairMaterial")
        return 3;
    return 4;
}
MS2_REPLACE(0x14274EE10, MS2StandardMaterial::GetMaterialType, 121, 0x6EE5D8FB);

//--------------------------------------------------------------------------------------------------
// @0x14274eea0
bool MS2StandardMaterial::AddLightObject(Context& kContext, NiShaderConstantMap::ObjectMappings eMapping,
    LightType eType, unsigned int uiObjectIndex, NiMaterialResource* pkShadow, NiMaterialResource*& pkResult)
{
    NiShaderAttributeDesc::ObjectType eObjType;
    const char* pcVariableModifier;
    switch (eType)
    {
        case LIGHT_DIR:
            if (pkShadow)
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SHADOWDIRECTIONALLIGHT;
                pcVariableModifier = "ShadowDir";
            }
            else
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_DIRECTIONALLIGHT;
                pcVariableModifier = "Dir";
            }
            break;
        case LIGHT_POINT:
            if (pkShadow)
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SHADOWPOINTLIGHT;
                pcVariableModifier = "ShadowPoint";
            }
            else
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_POINTLIGHT;
                pcVariableModifier = "Point";
            }
            break;
        case LIGHT_SPOT:
            if (pkShadow)
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SHADOWSPOTLIGHT;
                pcVariableModifier = "ShadowSpot";
            }
            else
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SPOTLIGHT;
                pcVariableModifier = "Spot";
            }
            break;
        default:
            return false;
    }

    pkResult = AddOutputObject(kContext.m_spUniforms, eMapping, eObjType, uiObjectIndex, pcVariableModifier);
    return true;
}
MS2_REPLACE_METHOD(0x14274EEA0, MS2StandardMaterial, AddLightObject, 209, 0x1B47AAD9);

//--------------------------------------------------------------------------------------------------
// @0x14274ef80
bool MS2StandardMaterial::HandleCalculateFog(Context& kContext, NiMaterialResource* pkViewPos, Fog eFogType)
{
    if (eFogType == FOG_NONE)
        return true;

    NiMaterialNode* pkFogNode = GetAttachableNodeFromLibrary("CalculateBiasedFog");
    kContext.m_spConfigurator->AddNode(pkFogNode);

    NiMaterialResource* pkFogOut = kContext.m_spOutputs->AddInputResource("float", "Fog", "", "FogOut");
    kContext.m_spConfigurator->AddBinding(pkFogNode->GetOutputResourceByVariableName("FogOut"), pkFogOut);

    unsigned int uiFogType = 0;
    bool bFogRange = false;
    if (eFogType == FOG_LINEAR)
    {
        uiFogType = 3;
        bFogRange = false;
    }
    else if (eFogType == FOG_SQUARED)
    {
        uiFogType = 3;
        bFogRange = true;
    }

    char acValue[32];
    NiSprintf(acValue, 32, "(%d)", uiFogType);
    kContext.m_spConfigurator->AddBinding(kContext.m_spStatics->AddOutputConstant("int", acValue),
        pkFogNode->GetInputResourceByVariableName("FogType"));

    kContext.m_spConfigurator->AddBinding(
        kContext.m_spStatics->AddOutputConstant("bool", bFogRange ? "(true)" : "(false)"),
        pkFogNode->GetInputResourceByVariableName("FogRange"));

    NiMaterialResource* pkFogDensity = AddOutputPredefined(kContext.m_spUniforms,
        NiShaderConstantMap::SCM_DEF_FOG_DENSITY);
    kContext.m_spConfigurator->AddBinding(pkFogDensity, pkFogNode->GetInputResourceByVariableName("FogDensity"));

    NiMaterialResource* pkFogNearFar = AddOutputPredefined(kContext.m_spUniforms,
        NiShaderConstantMap::SCM_DEF_FOG_NEARFAR);
    kContext.m_spConfigurator->AddBinding(pkFogNearFar, pkFogNode->GetInputResourceByVariableName("FogStartEnd"));

    kContext.m_spConfigurator->AddBinding(pkViewPos, pkFogNode->GetInputResourceByVariableName("ViewPosition"));

    NiMaterialResource* pkFogBias = AddOutputGlobal(kContext.m_spUniforms, "gakFogBias",
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    kContext.m_spConfigurator->AddBinding(pkFogBias, pkFogNode->GetInputResourceByVariableName("FogBias"));

    return true;
}
MS2_REPLACE_METHOD(0x14274EF80, MS2StandardMaterial, HandleCalculateFog, 1085, 0x9B144A5A);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: block layout differs (exe 1010 bytes); same nodes and bindings
// @0x14274f3c0
bool MS2StandardMaterial::HandleChaosRim(Context& kContext, NiMaterialResource*& pkColor,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector)
{
    NiMaterialResource* pkDimmer = AddOutputAttribute(kContext.m_spUniforms, "ChaosDimmer",
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    if (!pkDimmer)
        return false;

    NiMaterialResource* pkDimmed = NULL;
    if (!ScaleVector(kContext, pkColor, pkDimmer, pkDimmed))
        return false;

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("CalcRimIntensity");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    if (!kContext.m_spConfigurator->AddBinding(pkWorldNormal, pkNode->GetInputResourceByVariableName("WorldNrm")))
        return false;
    if (!kContext.m_spConfigurator->AddBinding(pkViewVector,
        pkNode->GetInputResourceByVariableName("WorldViewVector")))
    {
        return false;
    }

    NiMaterialResource* pkRes = AddOutputAttribute(kContext.m_spUniforms, "ChaosFresnelExponent",
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    if (!pkRes || !kContext.m_spConfigurator->AddBinding(pkRes,
        pkNode->GetInputResourceByVariableName("FresnelExponentIn")))
    {
        return false;
    }

    pkRes = AddOutputAttribute(kContext.m_spUniforms, "ChaosFresnelBoost", NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    if (!pkRes || !kContext.m_spConfigurator->AddBinding(pkRes,
        pkNode->GetInputResourceByVariableName("FresnelBoostIn")))
    {
        return false;
    }

    pkRes = AddOutputGlobal(kContext.m_spUniforms, "gakRimLightDirection", NiShaderAttributeDesc::ATTRIB_TYPE_POINT3);
    if (!pkRes || !kContext.m_spConfigurator->AddBinding(pkRes,
        pkNode->GetInputResourceByVariableName("RimLightDirIn")))
    {
        return false;
    }

    NiMaterialResource* pkLightColor = AddOutputAttribute(kContext.m_spUniforms, "ChaosLightColor",
        NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    NiMaterialResource* pkLightRGB = NULL;
    NiMaterialResource* pkLightAlpha = NULL;
    if (!pkLightColor || !SplitColorAndOpacity(kContext, pkLightColor, pkLightRGB, pkLightAlpha))
        return false;

    NiMaterialResource* pkRim = NULL;
    if (!ScaleVector(kContext, pkLightRGB, pkNode->GetOutputResourceByVariableName("RimIntensity"), pkRim))
        return false;

    return AddVector(kContext, pkDimmed, pkRim, pkColor);
}
MS2_REPLACE_METHOD(0x14274F3C0, MS2StandardMaterial, HandleChaosRim, 1010, 0x36EC674C);

//--------------------------------------------------------------------------------------------------
// @0x14274f7c0
bool MS2StandardMaterial::HandleColorBoost(Context& kContext, NiStandardPixelProgramDescriptor*,
    NiMaterialResource*& pkDiffuseAccum)
{
    if ((unsigned int)(m_eMaterialType - 1) <= 2)
    {
        NiMaterialResource* pkBoost = AddOutputAttribute(kContext.m_spUniforms, "ColorBoost",
            NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
        ScaleVector(kContext, pkDiffuseAccum, pkBoost, pkDiffuseAccum);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14274F7C0, MS2StandardMaterial, HandleColorBoost, 167, 0x3C0BC783);

//--------------------------------------------------------------------------------------------------
// @0x14274f870
bool MS2StandardMaterial::HandleCustomMaps(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    unsigned int&, NiMaterialResource** apkUVSets, unsigned int, NiMaterialResource*&, NiMaterialResource*&,
    NiMaterialResource*&, NiMaterialResource*&, NiMaterialResource*&, NiMaterialResource*&, NiMaterialResource*&,
    NiMaterialResource*&, NiMaterialResource*&, NiMaterialResource*&, NiMaterialResource*& pkDiffuseTexAccum,
    NiMaterialResource*&)
{
    if ((unsigned int)(m_eMaterialType - 1) <= 2)
        return HandleColorOverride(kContext, pkPixDesc, apkUVSets, pkDiffuseTexAccum);
    return true;
}
MS2_REPLACE_METHOD(0x14274F870, MS2StandardMaterial, HandleCustomMaps, 44, 0xFDFB5A5B);

//--------------------------------------------------------------------------------------------------
// @0x14274f8a0
bool MS2StandardMaterial::HandleDetailMap(Context& kContext, NiMaterialResource* pkUVSet,
    NiMaterialResource*& pkDiffuseColorRes, NiMaterialResource*&)
{
    // detail colour is applied 2x; its alpha is kept and multiplied into the opacity later
    if (!InsertTexture(kContext, MAP_DETAIL, 0, TEXTURE_RGB_APPLY_MULTIPLY, TEXTURE_SAMPLE_RGB, pkUVSet,
        pkDiffuseColorRes, kContext.m_spStatics->AddOutputConstant("float", "(2.0)"), pkDiffuseColorRes,
        m_pkDetailOpacity))
    {
        return false;
    }
    return InsertTexture(kContext, MAP_DETAIL, 0, TEXTURE_RGB_APPLY_MULTIPLY, TEXTURE_SAMPLE_A, pkUVSet, NULL,
        NULL, m_pkDetailOpacity, m_pkDetailOpacity);
}
MS2_REPLACE_METHOD(0x14274F8A0, MS2StandardMaterial, HandleDetailMap, 289, 0x4D5FA12A);

//--------------------------------------------------------------------------------------------------
// @0x14274f9d0
bool MS2StandardMaterial::HandleEnvMap(Context& kContext, NiStandardMaterial::TexEffectType eTexEffect,
    NiMaterialResource* pkUVResource, NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
    NiMaterialResource* pkBumpOffset, NiMaterialResource* pkGlossiness)
{
    if (eTexEffect != TEXEFFECT_MAX)
    {
        return NiStandardMaterial::HandleEnvMap(kContext, eTexEffect, pkUVResource, pkDiffuseAccum,
            pkSpecularAccum, pkBumpOffset, pkGlossiness);
    }

    // screen-projected environment map
    NiMaterialNode* pkProjNode = GetAttachableNodeFromLibrary("ProjectScreenToTextureCoordinates");
    kContext.m_spConfigurator->AddNode(pkProjNode);
    kContext.m_spConfigurator->AddBinding(pkUVResource, pkProjNode->GetInputResourceByVariableName("TexCoordIn"));
    NiMaterialResource* pkUV = pkProjNode->GetOutputResourceByVariableName("TexCoordOut");

    const NiFixedString& kSamplerName = NiTextureEffect::GetTypeNameFromID(NiTextureEffect::ENVIRONMENT_MAP);

    if (pkBumpOffset)
    {
        NiMaterialNode* pkBumpNode = NULL;
        if (pkUV->GetType() == "float2")
            pkBumpNode = GetAttachableNodeFromLibrary("OffsetUVFloat2");
        else if (pkUV->GetType() == "float3")
            pkBumpNode = GetAttachableNodeFromLibrary("OffsetUVFloat3");
        else if (pkUV->GetType() == "float4")
            pkBumpNode = GetAttachableNodeFromLibrary("OffsetUVFloat4");

        if (!pkBumpNode)
            return false;

        kContext.m_spConfigurator->AddNode(pkBumpNode);
        kContext.m_spConfigurator->AddBinding(pkUV, "TexCoordIn", pkBumpNode);
        kContext.m_spConfigurator->AddBinding(pkBumpOffset, "TexCoordOffset", pkBumpNode);
        pkUV = pkBumpNode->GetOutputResourceByVariableName("TexCoordOut");
    }

    NiMaterialResource* pkSampledColor = NULL;
    NiMaterialResource* pkOpacity = NULL;
    if (!InsertTexture(kContext, kSamplerName, 0, TEXTURE_RGB_APPLY_MULTIPLY, TEXTURE_SAMPLE_RGB, pkUV,
        pkGlossiness, NULL, pkSampledColor, pkOpacity))
    {
        return false;
    }

    if (pkSpecularAccum)
    {
        if (!AddVector(kContext, pkSampledColor, pkSpecularAccum, pkSpecularAccum))
            return false;
    }
    else
    {
        pkSpecularAccum = pkSampledColor;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14274F9D0, MS2StandardMaterial, HandleEnvMap, 812, 0xB6C8D590);

//--------------------------------------------------------------------------------------------------
// @0x14274fd00
bool MS2StandardMaterial::HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
    NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");

    NiMaterialNode* pkRGBNode = GetAttachableNodeFromLibrary("CompositeFinalRGBColor");
    kContext.m_spConfigurator->AddNode(pkRGBNode);
    if (pkDiffuseAccum)
        kContext.m_spConfigurator->AddBinding(pkDiffuseAccum, "DiffuseColor", pkRGBNode);
    if (pkSpecularAccum)
        kContext.m_spConfigurator->AddBinding(pkSpecularAccum, "SpecularColor", pkRGBNode);

    NiMaterialResource* pkColor = pkRGBNode->GetOutputResourceByVariableName("OutputColor");

    if (m_bChaos && !HandleChaosRim(kContext, pkColor, pkWorldNormal, pkViewVector))
        return false;

    if (!HandleApplyFog(kContext, pkPixDesc, pkColor, pkColor))
        return false;

    NiMaterialNode* pkRGBANode = GetAttachableNodeFromLibrary(
        m_bAlphaBoost ? "AlphaBoost" : "CompositeFinalRGBAColor");
    kContext.m_spConfigurator->AddNode(pkRGBANode);
    kContext.m_spConfigurator->AddBinding(pkColor, "FinalColor", pkRGBANode);

    if (pkOpacityAccum)
    {
        HandleAlphaTest(kContext, pkPixDesc, pkOpacityAccum);
        kContext.m_spConfigurator->AddBinding(pkOpacityAccum, "FinalOpacity", pkRGBANode);
    }

    kContext.m_spConfigurator->AddBinding("OutputColor", pkRGBANode, pkPixelOut);
    return true;
}
MS2_REPLACE_METHOD(0x14274FD00, MS2StandardMaterial, HandleMS2FinalPixelOutputs, 774, 0x398B4BC0);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: temporary NiFixedString/binding order differs; same outputs bound
// @0x142750010
bool MS2StandardMaterial::HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
    NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos)
{
    if (!HandleMS2VertexUVSets(kContext, pkVertDesc, pkWorldPos, pkWorldNormal, pkWorldReflect, pkProjectedPos))
        return false;

    if (pkVertDesc->GetHEIGHTFOG() && !HandleCalculateHeightFog(kContext, pkWorldPos))
        return false;

    if (!HandleCalculateFog(kContext, pkViewPos, (Fog)pkVertDesc->GetFOGTYPE()))
        return false;

    // UVSET11TEXOUTPUT (set from USERDEFINED02): multiply the vertex colours by the second colour stream
    if (!pkVertDesc->GetUVSET11TEXOUTPUT())
        return true;

    NiMaterialResource* pkBrightness = kContext.m_spInputs->AddOutputResource("float4", "Color", "",
        "VertexBrightness");
    NiMaterialResource* pkVertIn = kContext.m_spInputs->GetOutputResourceByVariableName("VertexColors");
    NiMaterialResource* pkVertOut = kContext.m_spOutputs->GetInputResourceByVariableName("VertexColors");

    if (!pkVertIn || !pkVertOut)
    {
        if (!pkVertOut)
            pkVertOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "VertexColors");
        return kContext.m_spConfigurator->AddBinding(pkBrightness, pkVertOut);
    }

    for (unsigned int ui = 0; ui < kContext.m_spConfigurator->GetBindingCount(); ui++)
    {
        NiMaterialResourceBinding* pkBinding = kContext.m_spConfigurator->GetBinding(ui);
        if (pkBinding->GetDestinationResource() == pkVertOut)
        {
            kContext.m_spConfigurator->RemoveBinding(pkBinding);
            break;
        }
    }

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("MultiplyFloat4");
    kContext.m_spConfigurator->AddNode(pkNode);
    kContext.m_spConfigurator->AddBinding(pkBrightness, pkNode->GetInputResourceByVariableName("V1"));
    kContext.m_spConfigurator->AddBinding(pkVertIn, pkNode->GetInputResourceByVariableName("V2"));
    kContext.m_spConfigurator->AddBinding(pkNode->GetOutputResourceByVariableName("Output"), pkVertOut);
    return true;
}
MS2_REPLACE_METHOD(0x142750010, MS2StandardMaterial, HandleFinalVertexOutputs, 961, 0xC45FCA5E);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: block layout and register allocation differ (exe 3972 bytes); same light fragment
// @0x1427503e0
bool MS2StandardMaterial::HandleMS2Light(Context& kContext, unsigned int, LightType eType, unsigned int uiLightByType,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkSpecularPower, NiMaterialResource*& pkAmbientAccum, NiMaterialResource*& pkDiffuseAccum,
    NiMaterialResource*& pkSpecularAccum, NiMaterialResource*& pkLightSpecular, bool bSpecular,
    NiMaterialResource* pkShadow, NiMaterialResource* pkHairTangent)
{
    const char* pcLightNode;
    switch (m_eMaterialType)
    {
        case 0:
            pcLightNode = "MS2Light";
            break;
        case 1:
            pcLightNode = "MS2CharacterLight";
            break;
        case 2:
            pcLightNode = "MS2CharacterSkinLight";
            break;
        case 3:
            pcLightNode = "MS2CharacterHairLight";
            break;
        default:
            pcLightNode = "Light";
            break;
    }

    NiMaterialNode* pkLightNode = GetAttachableNodeFromLibrary(pcLightNode);
    kContext.m_spConfigurator->AddNode(pkLightNode);

    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkLightNode->GetInputResourceByVariableName("WorldPos"));
    kContext.m_spConfigurator->AddBinding(pkWorldNorm, pkLightNode->GetInputResourceByVariableName("WorldNrm"));

    if (m_eMaterialType == 3 && pkHairTangent)
    {
        kContext.m_spConfigurator->AddBinding(pkHairTangent,
            pkLightNode->GetInputResourceByVariableName("HairTangent"));
    }
    if (pkAmbientAccum)
    {
        kContext.m_spConfigurator->AddBinding(pkAmbientAccum,
            pkLightNode->GetInputResourceByVariableName("AmbientAccum"));
    }
    if (pkDiffuseAccum)
    {
        kContext.m_spConfigurator->AddBinding(pkDiffuseAccum,
            pkLightNode->GetInputResourceByVariableName("DiffuseAccum"));
    }
    if (pkSpecularAccum && bSpecular)
    {
        kContext.m_spConfigurator->AddBinding(pkSpecularAccum,
            pkLightNode->GetInputResourceByVariableName("SpecularAccum"));
    }

    kContext.m_spConfigurator->AddBinding(
        kContext.m_spStatics->AddOutputConstant("bool", bSpecular ? "(true)" : "(false)"),
        pkLightNode->GetInputResourceByVariableName("SpecularEnable"));

    if (pkShadow)
        kContext.m_spConfigurator->AddBinding(pkShadow, pkLightNode->GetInputResourceByVariableName("Shadow"));

    char acValue[32];
    NiSprintf(acValue, 32, "(%d)", (unsigned int)eType);
    NiMaterialResource* pkLightType = kContext.m_spStatics->AddOutputConstant("int", acValue);
    kContext.m_spConfigurator->AddBinding(pkLightType, pkLightNode->GetInputResourceByVariableName("LightType"));

    NiShaderAttributeDesc::ObjectType eObjType = NiShaderAttributeDesc::OT_EFFECT_GENERALLIGHT;
    const char* pcVariableModifier = NULL;
    switch (eType)
    {
        case LIGHT_DIR:
            if (pkShadow)
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SHADOWDIRECTIONALLIGHT;
                pcVariableModifier = "ShadowDir";
            }
            else
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_DIRECTIONALLIGHT;
                pcVariableModifier = "Dir";
            }
            break;
        case LIGHT_POINT:
            if (pkShadow)
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SHADOWPOINTLIGHT;
                pcVariableModifier = "ShadowPoint";
            }
            else
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_POINTLIGHT;
                pcVariableModifier = "Point";
            }
            break;
        case LIGHT_SPOT:
            if (pkShadow)
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SHADOWSPOTLIGHT;
                pcVariableModifier = "ShadowSpot";
            }
            else
            {
                eObjType = NiShaderAttributeDesc::OT_EFFECT_SPOTLIGHT;
                pcVariableModifier = "Spot";
            }
            break;
        default:
            break;
    }

    NiMaterialResource* pkRes = AddOutputObject(kContext.m_spUniforms, NiShaderConstantMap::SCM_OBJ_AMBIENT,
        eObjType, uiLightByType, pcVariableModifier);
    kContext.m_spConfigurator->AddBinding(pkRes, pkLightNode->GetInputResourceByVariableName("LightAmbient"));

    NiMaterialResource* pkLightDiffuse = AddOutputObject(kContext.m_spUniforms,
        NiShaderConstantMap::SCM_OBJ_DIFFUSE, eObjType, uiLightByType, pcVariableModifier);
    kContext.m_spConfigurator->AddBinding(pkLightDiffuse,
        pkLightNode->GetInputResourceByVariableName("LightDiffuse"));

    pkLightSpecular = AddOutputObject(kContext.m_spUniforms, NiShaderConstantMap::SCM_OBJ_SPECULAR, eObjType,
        uiLightByType, pcVariableModifier);
    kContext.m_spConfigurator->AddBinding(pkLightSpecular,
        pkLightNode->GetInputResourceByVariableName("LightSpecular"));

    NiMaterialResource* pkLightPos = AddOutputObject(kContext.m_spUniforms,
        NiShaderConstantMap::SCM_OBJ_WORLDPOSITION, eObjType, uiLightByType, pcVariableModifier);
    kContext.m_spConfigurator->AddBinding(pkLightPos, pkLightNode->GetInputResourceByVariableName("LightPos"));

    NiMaterialResource* pkAttenuation = NULL;
    if (eType != LIGHT_DIR)
    {
        pkAttenuation = AddOutputObject(kContext.m_spUniforms, NiShaderConstantMap::SCM_OBJ_ATTENUATION,
            eObjType, uiLightByType, pcVariableModifier);
        kContext.m_spConfigurator->AddBinding(pkAttenuation,
            pkLightNode->GetInputResourceByVariableName("LightAttenuation"));
    }

    NiMaterialResource* pkRimLightDir = AddOutputGlobal(kContext.m_spUniforms, "gakRimLightDirection",
        NiShaderAttributeDesc::ATTRIB_TYPE_POINT3);
    NiMaterialResource* pkCharacterLightDir = AddOutputGlobal(kContext.m_spUniforms,
        "gakCharacterLightDirection", NiShaderAttributeDesc::ATTRIB_TYPE_POINT3);

    // characters take the directional light direction from the global character light direction
    NiMaterialResource* pkLightDir = NULL;
    if (eType != LIGHT_POINT)
    {
        pkLightDir = AddOutputObject(kContext.m_spUniforms, NiShaderConstantMap::SCM_OBJ_WORLDDIRECTION, eObjType,
            uiLightByType, pcVariableModifier);
        kContext.m_spConfigurator->AddBinding(
            (eType == LIGHT_DIR && (unsigned int)(m_eMaterialType - 1) <= 2) ? pkCharacterLightDir : pkLightDir,
            pkLightNode->GetInputResourceByVariableName("LightDirection"));
    }

    NiMaterialResource* pkSpotAttenuation = NULL;
    if (eType == LIGHT_SPOT)
    {
        pkSpotAttenuation = AddOutputObject(kContext.m_spUniforms, NiShaderConstantMap::SCM_OBJ_SPOTATTENUATION,
            eObjType, uiLightByType, pcVariableModifier);
        kContext.m_spConfigurator->AddBinding(pkSpotAttenuation,
            pkLightNode->GetInputResourceByVariableName("LightSpotAttenuation"));
    }

    if ((unsigned int)(m_eMaterialType - 1) <= 2)
    {
        kContext.m_spConfigurator->AddBinding(pkViewVector,
            pkLightNode->GetInputResourceByVariableName("WorldViewVector"));
    }

    if (bSpecular && pkSpecularPower)
    {
        kContext.m_spConfigurator->AddBinding(pkSpecularPower,
            pkLightNode->GetInputResourceByVariableName("SpecularPower"));
    }

    pkAmbientAccum = pkLightNode->GetOutputResourceByVariableName("AmbientAccumOut");
    pkDiffuseAccum = pkLightNode->GetOutputResourceByVariableName("DiffuseAccumOut");
    if (bSpecular)
        pkSpecularAccum = pkLightNode->GetOutputResourceByVariableName("SpecularAccumOut");

    // rim light
    if (m_eMaterialType >= 1 && m_eMaterialType <= 3)
    {
        kContext.m_spConfigurator->AddBinding(
            AddOutputAttribute(kContext.m_spUniforms, "FresnelBoost", NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT),
            pkLightNode->GetInputResourceByVariableName("FresnelBoostIn"));
        kContext.m_spConfigurator->AddBinding(
            AddOutputAttribute(kContext.m_spUniforms, "FresnelExponent", NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT),
            pkLightNode->GetInputResourceByVariableName("FresnelExponentIn"));
        kContext.m_spConfigurator->AddBinding(pkRimLightDir,
            pkLightNode->GetInputResourceByVariableName("RimLightDirIn"));
    }

    if (m_eMaterialType != 2)
        return true;

    // skin: subsurface scattering on top of the diffuse light
    NiMaterialNode* pkSkinNode = GetAttachableNodeFromLibrary("LambSkin");
    kContext.m_spConfigurator->AddNode(pkSkinNode);

    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkSkinNode->GetInputResourceByVariableName("WorldPos"));
    kContext.m_spConfigurator->AddBinding(pkWorldNorm, pkSkinNode->GetInputResourceByVariableName("WorldNrm"));
    if (pkDiffuseAccum)
    {
        kContext.m_spConfigurator->AddBinding(pkDiffuseAccum,
            pkSkinNode->GetInputResourceByVariableName("DiffuseAccum"));
    }
    if (pkShadow)
        kContext.m_spConfigurator->AddBinding(pkShadow, pkSkinNode->GetInputResourceByVariableName("Shadow"));
    kContext.m_spConfigurator->AddBinding(pkLightType, pkSkinNode->GetInputResourceByVariableName("LightType"));
    kContext.m_spConfigurator->AddBinding(pkLightDiffuse,
        pkSkinNode->GetInputResourceByVariableName("LightDiffuse"));
    kContext.m_spConfigurator->AddBinding(pkLightPos, pkSkinNode->GetInputResourceByVariableName("LightPos"));

    if (eType == LIGHT_DIR)
    {
        kContext.m_spConfigurator->AddBinding(pkCharacterLightDir,
            pkSkinNode->GetInputResourceByVariableName("LightDirection"));
    }
    else
    {
        kContext.m_spConfigurator->AddBinding(pkAttenuation,
            pkSkinNode->GetInputResourceByVariableName("LightAttenuation"));
        if (eType == LIGHT_SPOT)
        {
            kContext.m_spConfigurator->AddBinding(pkLightDir,
                pkSkinNode->GetInputResourceByVariableName("LightDirection"));
            kContext.m_spConfigurator->AddBinding(pkSpotAttenuation,
                pkSkinNode->GetInputResourceByVariableName("LightSpotAttenuation"));
        }
    }

    kContext.m_spConfigurator->AddBinding(
        AddOutputGlobal(kContext.m_spUniforms, "gakSSSColor", NiShaderAttributeDesc::ATTRIB_TYPE_POINT3),
        pkSkinNode->GetInputResourceByVariableName("SSSColor"));
    kContext.m_spConfigurator->AddBinding(
        AddOutputGlobal(kContext.m_spUniforms, "gkSSSPower", NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT),
        pkSkinNode->GetInputResourceByVariableName("SSSPower"));

    pkDiffuseAccum = pkSkinNode->GetOutputResourceByVariableName("DiffuseAccumOut");
    return true;
}
MS2_REPLACE_METHOD(0x1427503E0, MS2StandardMaterial, HandleMS2Light, 3972, 0x67C3914D);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: register allocation and stack slots differ; same lighting flow
// @0x142751370
bool MS2StandardMaterial::HandleMS2Lighting(Context& kContext, NiUInt32 uiShadowAtlasCells, NiUInt32 uiPSSMWhichLight,
    bool bSliceTransitions, bool bSpecular, unsigned int uiNumPoint, unsigned int uiNumDirectional,
    unsigned int uiNumSpot, unsigned int uiShadowBitfield, unsigned int uiShadowTechnique,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkSpecularPower, NiMaterialResource*& pkAmbientAccum, NiMaterialResource*& pkDiffuseAccum,
    NiMaterialResource*& pkSpecularAccum, NiMaterialResource*& pkLightSpecular, NiMaterialResource* pkHairTangent) {
    unsigned int uiLight = 0;
    NiMaterialResource* pkThisLightSpecular = NULL;

    unsigned int uiLightTypeCount = 0;
    unsigned int uiShadowLightTypeCount = 0;
    for (unsigned int ui = 0; ui < uiNumPoint; ui++)
    {
        NiMaterialResource* pkShadow = NULL;
        unsigned int uiMask = NiTGetBitMask<unsigned int>(uiLight, 1);
        bool bShadow = NiTGetBit<unsigned int>(uiShadowBitfield, uiMask);
        if (bShadow && NiShadowManager::GetShadowManager())
        {
            if (!HandleShadow(kContext, uiShadowAtlasCells, bSliceTransitions, uiLight, LIGHT_POINT,
                uiShadowLightTypeCount, pkWorldPos, pkWorldNorm, uiShadowTechnique, pkShadow))
            {
                return false;
            }
            if (!HandleMS2Light(kContext, uiLight, LIGHT_POINT, uiShadowLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum,
                pkThisLightSpecular, bSpecular, pkShadow, pkHairTangent))
            {
                return false;
            }
            uiShadowLightTypeCount++;
        }
        else
        {
            if (!HandleMS2Light(kContext, uiLight, LIGHT_POINT, uiLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum,
                pkThisLightSpecular, bSpecular, NULL, pkHairTangent))
            {
                return false;
            }
            uiLightTypeCount++;
        }
        uiLight++;
    }

    // the specular colour of the first directional light goes back to the caller (env map tint)
    uiLightTypeCount = uiShadowLightTypeCount = 0;
    for (unsigned int ui = 0; ui < uiNumDirectional; ui++)
    {
        pkThisLightSpecular = NULL;
        NiMaterialResource* pkShadow = NULL;
        unsigned int uiMask = NiTGetBitMask<unsigned int>(uiLight, 1);
        bool bShadow = NiTGetBit<unsigned int>(uiShadowBitfield, uiMask);
        if (bShadow && NiShadowManager::GetShadowManager())
        {
            NiUInt32 uiNumPSSMSplits = 1;
            if (uiPSSMWhichLight == ui + uiNumPoint)
                uiNumPSSMSplits = uiShadowAtlasCells;

            if (!HandleShadow(kContext, uiNumPSSMSplits, bSliceTransitions, uiLight, LIGHT_DIR,
                uiShadowLightTypeCount, pkWorldPos, pkWorldNorm, uiShadowTechnique, pkShadow))
            {
                return false;
            }
            if (!HandleMS2Light(kContext, uiLight, LIGHT_DIR, uiShadowLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum,
                pkThisLightSpecular, bSpecular, pkShadow, pkHairTangent))
            {
                return false;
            }
            uiShadowLightTypeCount++;
        }
        else
        {
            if (!HandleMS2Light(kContext, uiLight, LIGHT_DIR, uiLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum,
                pkThisLightSpecular, bSpecular, NULL, pkHairTangent))
            {
                return false;
            }
            uiLightTypeCount++;
        }
        if (ui == 0)
            pkLightSpecular = pkThisLightSpecular;
        uiLight++;
    }

    uiLightTypeCount = uiShadowLightTypeCount = 0;
    for (unsigned int ui = 0; ui < uiNumSpot; ui++)
    {
        NiMaterialResource* pkShadow = NULL;
        unsigned int uiMask = NiTGetBitMask<unsigned int>(uiLight, 1);
        bool bShadow = NiTGetBit<unsigned int>(uiShadowBitfield, uiMask);
        if (bShadow && NiShadowManager::GetShadowManager())
        {
            if (!HandleShadow(kContext, uiShadowAtlasCells, bSliceTransitions, uiLight, LIGHT_SPOT,
                uiShadowLightTypeCount, pkWorldPos, pkWorldNorm, uiShadowTechnique, pkShadow))
            {
                return false;
            }
            if (!HandleMS2Light(kContext, uiLight, LIGHT_SPOT, uiShadowLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum,
                pkThisLightSpecular, bSpecular, pkShadow, pkHairTangent))
            {
                return false;
            }
            uiShadowLightTypeCount++;
        }
        else
        {
            if (!HandleMS2Light(kContext, uiLight, LIGHT_SPOT, uiLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum,
                pkThisLightSpecular, bSpecular, NULL, pkHairTangent))
            {
                return false;
            }
            uiLightTypeCount++;
        }
        uiLight++;
    }

    return true;
}
MS2_REPLACE_METHOD(0x142751370, MS2StandardMaterial, HandleMS2Lighting, 1830, 0x637A91C6);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: stack slot assignment differs (16 bytes); same lighting flow
// @0x142751aa0
bool MS2StandardMaterial::HandleLighting(Context& kContext, NiUInt32 uiShadowAtlasCells, NiUInt32 uiPSSMWhichLight,
    bool bSliceTransitions, bool bSpecular, unsigned int uiNumPoint, unsigned int uiNumDirectional,
    unsigned int uiNumSpot, unsigned int uiShadowBitfield, unsigned int uiShadowTechnique,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkSpecularPower, NiMaterialResource*& pkAmbientAccum, NiMaterialResource*& pkDiffuseAccum,
    NiMaterialResource*& pkSpecularAccum) {
    unsigned int uiLight = 0;
    NiMaterialResource* pkLightSpecular = NULL;

    unsigned int uiLightTypeCount = 0;
    unsigned int uiShadowLightTypeCount = 0;
    for (unsigned int ui = 0; ui < uiNumPoint; ui++)
    {
        NiMaterialResource* pkShadow = NULL;
        unsigned int uiMask = NiTGetBitMask<unsigned int>(uiLight, 1);
        bool bShadow = NiTGetBit<unsigned int>(uiShadowBitfield, uiMask);
        if (bShadow && NiShadowManager::GetShadowManager())
        {
            if (!HandleShadow(kContext, uiShadowAtlasCells, bSliceTransitions, uiLight, LIGHT_POINT,
                uiShadowLightTypeCount, pkWorldPos, pkWorldNorm, uiShadowTechnique, pkShadow))
            {
                return false;
            }
            if (!HandleMS2Light(kContext, uiLight, LIGHT_POINT, uiShadowLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum, pkLightSpecular,
                bSpecular, pkShadow, NULL))
            {
                return false;
            }
            uiShadowLightTypeCount++;
        }
        else
        {
            if (!HandleMS2Light(kContext, uiLight, LIGHT_POINT, uiLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum, pkLightSpecular,
                bSpecular, NULL, NULL))
            {
                return false;
            }
            uiLightTypeCount++;
        }
        uiLight++;
    }

    uiLightTypeCount = uiShadowLightTypeCount = 0;
    for (unsigned int ui = 0; ui < uiNumDirectional; ui++)
    {
        NiMaterialResource* pkShadow = NULL;
        unsigned int uiMask = NiTGetBitMask<unsigned int>(uiLight, 1);
        bool bShadow = NiTGetBit<unsigned int>(uiShadowBitfield, uiMask);
        if (bShadow && NiShadowManager::GetShadowManager())
        {
            NiUInt32 uiNumPSSMSplits = 1;
            if (uiPSSMWhichLight == ui + uiNumPoint)
                uiNumPSSMSplits = uiShadowAtlasCells;

            if (!HandleShadow(kContext, uiNumPSSMSplits, bSliceTransitions, uiLight, LIGHT_DIR,
                uiShadowLightTypeCount, pkWorldPos, pkWorldNorm, uiShadowTechnique, pkShadow))
            {
                return false;
            }
            if (!HandleMS2Light(kContext, uiLight, LIGHT_DIR, uiShadowLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum, pkLightSpecular,
                bSpecular, pkShadow, NULL))
            {
                return false;
            }
            uiShadowLightTypeCount++;
        }
        else
        {
            if (!HandleMS2Light(kContext, uiLight, LIGHT_DIR, uiLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum, pkLightSpecular,
                bSpecular, NULL, NULL))
            {
                return false;
            }
            uiLightTypeCount++;
        }
        uiLight++;
    }

    uiLightTypeCount = uiShadowLightTypeCount = 0;
    for (unsigned int ui = 0; ui < uiNumSpot; ui++)
    {
        NiMaterialResource* pkShadow = NULL;
        unsigned int uiMask = NiTGetBitMask<unsigned int>(uiLight, 1);
        bool bShadow = NiTGetBit<unsigned int>(uiShadowBitfield, uiMask);
        if (bShadow && NiShadowManager::GetShadowManager())
        {
            if (!HandleShadow(kContext, uiShadowAtlasCells, bSliceTransitions, uiLight, LIGHT_SPOT,
                uiShadowLightTypeCount, pkWorldPos, pkWorldNorm, uiShadowTechnique, pkShadow))
            {
                return false;
            }
            if (!HandleMS2Light(kContext, uiLight, LIGHT_SPOT, uiShadowLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum, pkLightSpecular,
                bSpecular, pkShadow, NULL))
            {
                return false;
            }
            uiShadowLightTypeCount++;
        }
        else
        {
            if (!HandleMS2Light(kContext, uiLight, LIGHT_SPOT, uiLightTypeCount, pkWorldPos, pkWorldNorm,
                pkViewVector, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum, pkSpecularAccum, pkLightSpecular,
                bSpecular, NULL, NULL))
            {
                return false;
            }
            uiLightTypeCount++;
        }
        uiLight++;
    }

    return true;
}
MS2_REPLACE_METHOD(0x142751AA0, MS2StandardMaterial, HandleLighting, 1712, 0xCD2AD750);

//--------------------------------------------------------------------------------------------------
// @0x142752150
bool MS2StandardMaterial::HandleGlowModifier(Context& kContext, NiMaterialResource* pkUVSet,
    NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*&)
{
    NiMaterialResource* pkModifier = AddOutputAttribute(kContext.m_spUniforms, "GlowModifier",
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    if (!pkModifier)
        return false;

    NiMaterialResource* pkOpacity = NULL;
    return InsertTexture(kContext, MAP_GLOW, 0, TEXTURE_RGB_APPLY_ADD, TEXTURE_SAMPLE_RGB, pkUVSet, pkDiffuseAccum,
        pkModifier, pkDiffuseAccum, pkOpacity);
}
MS2_REPLACE_METHOD(0x142752150, MS2StandardMaterial, HandleGlowModifier, 227, 0x88F4FDE4);

//--------------------------------------------------------------------------------------------------
// @0x142752240
bool MS2StandardMaterial::HandlePixelUVSets(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
    NiMaterialResource** ppkUVSets, unsigned int, unsigned int& uiNumStandardUVs,
    unsigned int& uiDynamicEffectCount)
{
    unsigned int uiTexIndex = 0;
    for (unsigned int ui = 0; ui < pkPixelDesc->GetInputUVCount(); ui++)
    {
        ppkUVSets[uiTexIndex] = kContext.m_spInputs->AddOutputResource("float2", "TexCoord", "",
            GenerateUVSetName(uiTexIndex));
        uiTexIndex++;
    }

    uiNumStandardUVs = uiTexIndex;
    uiDynamicEffectCount = pkPixelDesc->GetPROJLIGHTMAPCOUNT() + pkPixelDesc->GetPROJSHADOWMAPCOUNT();

    if (pkPixelDesc->GetENVMAPTYPE() != TEXEFFECT_NONE && pkPixelDesc->GetNORMALMAPCOUNT() == 0)
        uiDynamicEffectCount++;

    // the screen-projected env map needs its UV set even with a normal map
    if (pkPixelDesc->GetENVMAPTYPE() == TEXEFFECT_MAX && pkPixelDesc->GetNORMALMAPCOUNT() != 0)
        uiDynamicEffectCount++;

    for (unsigned int ui = 0; ui < uiDynamicEffectCount; ui++)
    {
        ppkUVSets[uiTexIndex] = kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "",
            GenerateUVSetName(uiTexIndex));
        uiTexIndex++;
    }

    return true;
}
MS2_REPLACE_METHOD(0x142752240, MS2StandardMaterial, HandlePixelUVSets, 642, 0x38F78E68);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: block layout differs (exe 2735 bytes); same transform fragments
// @0x1427524d0
bool MS2StandardMaterial::HandlePositionFragment(Context& kContext, TransformType eTransType,
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
        // characters are skinned with up to 60 bones per partition
        NiMaterialNode* pkProjFrag = GetAttachableNodeFromLibrary(
            m_bCharacterLighting ? g_pcTransformSkinnedPosition60
                                 : "TransformSkinnedPosition");
        unsigned int uiBones = m_bCharacterLighting ? 60 : 30;
        kContext.m_spConfigurator->AddNode(pkProjFrag);

        kContext.m_spInputs->AddOutputResource("float3", "Position", "Local", "Position");
        kContext.m_spInputs->AddOutputResource("float3", "BlendWeight", "Local", "BlendWeights");
        kContext.m_spInputs->AddOutputResource("int4", "BlendIndices", "Local", "BlendIndices");

        NiMaterialResource* pkBoneMatrix = AddOutputPredefined(kContext.m_spUniforms,
            NiShaderConstantMap::SCM_DEF_SKINBONE_MATRIX_3, 3, uiBones);

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
MS2_REPLACE_METHOD(0x1427524D0, MS2StandardMaterial, HandlePositionFragment, 2735, 0x5D9A57BC);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: register allocation and stack slots differ; same texture application
// @0x142752f80
bool MS2StandardMaterial::HandleMS2PostLightTextureApplication(Context& kContext,
    NiStandardPixelProgramDescriptor* pkPixDesc, NiMaterialResource*& pkWorldNormal, NiMaterialResource* pkViewVector,
    NiMaterialResource*&, NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
    NiMaterialResource* pkGlossiness, unsigned int& uiTexturesApplied, NiMaterialResource** apkUVSets,
    unsigned int uiNumStandardUVs, unsigned int, NiMaterialResource* pkLightSpecular)
{
    unsigned int uiApplied = 0;
    NiMaterialResource* pkBumpOffset = NULL;

    if (pkPixDesc->GetBUMPMAPCOUNT())
    {
        if (!HandleBumpMap(kContext, FindUVSetIndexForTextureEnum(MAP_BUMP, pkPixDesc, apkUVSets), pkBumpOffset))
            return false;
        uiApplied++;
    }

    TexEffectType eEnvMap = (TexEffectType)pkPixDesc->GetENVMAPTYPE();
    if (eEnvMap != TEXEFFECT_NONE)
    {
        // with a normal map the env map UVs are generated per pixel from the bumped normal, except for the
        // screen-projected env map, which always uses its interpolated UV set
        NiMaterialResource* pkEnvUV = NULL;
        bool bPerPixelNormal = pkWorldNormal &&
            kContext.m_spConfigurator->GetNodeByName("CalculateNormalFromColor");
        if (bPerPixelNormal && eEnvMap != TEXEFFECT_MAX)
        {
            NiMaterialResource* pkWorldReflect = NULL;
            if ((eEnvMap == TEXEFFECT_SPHERICAL || eEnvMap == TEXEFFECT_SPECULAR_CUBE) &&
                !HandleReflectionVectorFragment(kContext, pkWorldNormal, false, pkViewVector, pkWorldReflect))
            {
                return false;
            }
            if (!HandleMS2TextureEffectUVSetGen(kContext, NULL, pkWorldNormal, pkWorldReflect,
                NiShaderAttributeDesc::OT_EFFECT_ENVIRONMENTMAP, eEnvMap, 0, pkEnvUV, NULL))
            {
                return false;
            }
        }
        else
        {
            pkEnvUV = apkUVSets[uiNumStandardUVs];
        }

        NiMaterialResource* pkEnvSpecular = NULL;
        if (!HandleEnvMap(kContext, eEnvMap, pkEnvUV, pkDiffuseAccum, pkEnvSpecular, pkBumpOffset, pkGlossiness))
            return false;

        // tint the reflection with the first directional light
        if (pkLightSpecular)
        {
            Float4ToFloat3(kContext, pkLightSpecular, pkLightSpecular);
            MultiplyVector(kContext, pkEnvSpecular, pkLightSpecular, pkEnvSpecular);
        }
        AddVector(kContext, pkEnvSpecular, pkSpecularAccum, pkSpecularAccum);
    }

    if (pkPixDesc->GetGLOWMAPCOUNT() && !m_bChaos)
    {
        NiMaterialResource* pkUV = FindUVSetIndexForTextureEnum(MAP_GLOW, pkPixDesc, apkUVSets);
        bool bResult;
        if (pkPixDesc->GetGBNB_RESERVED5() & 2)  // glow modifier (USERDEFINED00)
            bResult = HandleGlowModifier(kContext, pkUV, pkDiffuseAccum, pkSpecularAccum);
        else
            bResult = HandleGlowMap(kContext, pkUV, pkDiffuseAccum, pkSpecularAccum);
        if (!bResult)
            return false;
        uiApplied++;
    }

    uiTexturesApplied += uiApplied;
    return true;
}
MS2_REPLACE_METHOD(0x142752F80, MS2StandardMaterial, HandleMS2PostLightTextureApplication, 756, 0xBEBB5A2E);

//--------------------------------------------------------------------------------------------------
// @0x142753280
bool MS2StandardMaterial::HandleMS2TextureEffectUVSetGen(Context& kContext, NiMaterialResource* pkWorldPos,
    NiMaterialResource* pkWorldNorm, NiMaterialResource* pkWorldReflection,
    NiShaderAttributeDesc::ObjectType eObjType, TexEffectType eEffectType, unsigned int uiOccurance,
    NiMaterialResource*& pkUVResource, NiMaterialResource* pkProjectedPos)
{
    if (eObjType == NiShaderAttributeDesc::OT_EFFECT_ENVIRONMENTMAP && eEffectType == TEXEFFECT_MAX)
    {
        // screen-projected env map: pass the projected position through
        pkUVResource = NULL;
        NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("PassThruViewToTextureCoordinates");
        kContext.m_spConfigurator->AddNode(pkNode);
        kContext.m_spConfigurator->AddBinding(pkProjectedPos, pkNode->GetInputResourceByVariableName("ProjPos"));
        pkUVResource = pkNode->GetOutputResourceByVariableName("TexCoordOut");
        return true;
    }

    return NiStandardMaterial::HandleTextureEffectUVSetGen(kContext, pkWorldPos, pkWorldNorm, pkWorldReflection,
        eObjType, eEffectType, uiOccurance, pkUVResource);
}
MS2_REPLACE_METHOD(0x142753280, MS2StandardMaterial, HandleMS2TextureEffectUVSetGen, 305, 0xAA3F27B2);

//--------------------------------------------------------------------------------------------------
// @0x1427533c0
bool MS2StandardMaterial::HandleMS2TextureEffectUVSets(Context& kContext, NiMaterialResource** apkOutputUVResources,
    size_t, NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkWorldReflection,
    TexEffectType eEnvironmentMapType, unsigned int uiProjectedLightCount, unsigned int uiProjectedLightTypes,
    unsigned int uiProjectedShadowCount, unsigned int uiProjectedShadowTypes, unsigned int& uiNextUVIndex,
    NiMaterialResource* pkProjectedPos)
{
    NiMaterialResource* pkUVResource = NULL;
    if (!HandleMS2TextureEffectUVSetGen(kContext, pkWorldPos, pkWorldNorm, pkWorldReflection,
        NiShaderAttributeDesc::OT_EFFECT_ENVIRONMENTMAP, eEnvironmentMapType, 0, pkUVResource, pkProjectedPos))
    {
        return false;
    }
    if (pkUVResource)
        apkOutputUVResources[uiNextUVIndex++] = pkUVResource;

    unsigned int uiMask = 1;
    for (unsigned int ui = 0; ui < uiProjectedLightCount; ui++)
    {
        bool bPerspective = (uiProjectedLightTypes & uiMask) != 0;
        uiMask *= 2;
        if (!HandleMS2TextureEffectUVSetGen(kContext, pkWorldPos, pkWorldNorm, pkWorldReflection,
            NiShaderAttributeDesc::OT_EFFECT_PROJECTEDLIGHTMAP,
            bPerspective ? TEXEFFECT_WORLD_PERSPECTIVE : TEXEFFECT_WORLD_PARALLEL, ui, pkUVResource,
            pkProjectedPos))
        {
            return false;
        }
        if (pkUVResource)
            apkOutputUVResources[uiNextUVIndex++] = pkUVResource;
    }

    uiMask = 1;
    for (unsigned int ui = 0; ui < uiProjectedShadowCount; ui++)
    {
        bool bPerspective = (uiProjectedShadowTypes & uiMask) != 0;
        uiMask *= 2;
        if (!HandleMS2TextureEffectUVSetGen(kContext, pkWorldPos, pkWorldNorm, pkWorldReflection,
            NiShaderAttributeDesc::OT_EFFECT_PROJECTEDSHADOWMAP,
            bPerspective ? TEXEFFECT_WORLD_PERSPECTIVE : TEXEFFECT_WORLD_PARALLEL, ui, pkUVResource,
            pkProjectedPos))
        {
            return false;
        }
        if (pkUVResource)
            apkOutputUVResources[uiNextUVIndex++] = pkUVResource;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1427533C0, MS2StandardMaterial, HandleMS2TextureEffectUVSets, 550, 0x47E009FF);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: register allocation and EH unwind states differ; same material/lighting nodes
// @0x1427535f0
bool MS2StandardMaterial::HandleVertexLightingAndMaterials(Context& kContext,
    NiStandardVertexProgramDescriptor* pkVertexDesc, NiMaterialResource* pkWorldPos,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldView)
{
    unsigned int uiPointLights = pkVertexDesc->GetPOINTLIGHTCOUNT();
    unsigned int uiDirLights = pkVertexDesc->GetDIRLIGHTCOUNT();
    unsigned int uiSpotLights = pkVertexDesc->GetSPOTLIGHTCOUNT();
    bool bSpecularOn = pkVertexDesc->GetSPECULAR() == 1;
    unsigned int uiNumPerVertexLights = uiPointLights + uiDirLights + uiSpotLights;
    bool bVertexOnlyLights = pkVertexDesc->GetVERTEXLIGHTSONLY() == 1;
    AmbDiffEmissiveEnum eAmbDiffEmissive = (AmbDiffEmissiveEnum)pkVertexDesc->GetAMBDIFFEMISSIVE();
    LightingModeEnum eLightingMode = (LightingModeEnum)pkVertexDesc->GetLIGHTINGMODE();
    ApplyMode eApplyMode = (ApplyMode)pkVertexDesc->GetAPPLYMODE();

    if (eApplyMode == APPLY_REPLACE)
        return true;

    if (uiNumPerVertexLights == 0 && !bVertexOnlyLights)
    {
        // only pixel lights
        bool bVertexColors = pkVertexDesc->GetVERTEXCOLORS() == VC_EXISTS;
        if (bVertexColors && (eAmbDiffEmissive == ADE_EMISSIVE ||
            ((eAmbDiffEmissive == ADE_AMB_DIFF || eAmbDiffEmissive == (AmbDiffEmissiveEnum)3) &&
            eLightingMode == LIGHTING_E_A_D)))
        {
            NiMaterialResource* pkVertIn = kContext.m_spInputs->AddOutputResource("float4", "Color", "",
                "VertexColors");
            NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource(pkVertIn->GetType(),
                pkVertIn->GetSemantic(), pkVertIn->GetLabel(), "VertexColors");
            kContext.m_spConfigurator->AddBinding(pkVertIn, pkVertOut);
        }
        return true;
    }

    NiMaterialResource* pkMatDiffuse = NULL;
    NiMaterialResource* pkMatSpecular = NULL;
    NiMaterialResource* pkSpecularPower = NULL;
    NiMaterialResource* pkMatAmbient = NULL;
    NiMaterialResource* pkMatEmissive = NULL;
    NiMaterialResource* pkOpacityAccum = NULL;

    if (bVertexOnlyLights && !HandleInitialSpecAmbDiffEmissiveColor(kContext, bSpecularOn, eAmbDiffEmissive,
        eLightingMode, pkMatDiffuse, pkMatSpecular, pkSpecularPower, pkMatAmbient, pkMatEmissive, pkOpacityAccum))
    {
        return false;
    }

    NiMaterialResource* pkDiffuseAccum = NULL;
    NiMaterialResource* pkSpecularAccum = NULL;
    NiMaterialResource* pkAmbientAccum = NULL;

    if (eLightingMode == LIGHTING_E_A_D)
    {
        pkAmbientAccum = AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_AMBIENTLIGHT);

        if (pkWorldNormal && !NormalizeVector(kContext, pkWorldNormal))
            return false;
        if (pkWorldView && !NormalizeVector(kContext, pkWorldView))
            return false;

        if (!HandleLighting(kContext, 1, 0, false, bSpecularOn, uiPointLights, uiDirLights, uiSpotLights, 0, 0,
            pkWorldPos, pkWorldNormal, pkWorldView, pkSpecularPower, pkAmbientAccum, pkDiffuseAccum,
            pkSpecularAccum))
        {
            return false;
        }
    }

    if (bVertexOnlyLights)
    {
        NiMaterialResource* pkDiffuseCoeff = NULL;
        NiMaterialResource* pkSpecularCoeff = NULL;
        if (!HandleShadingCoefficients(kContext, pkMatEmissive, pkMatDiffuse, pkMatAmbient, pkMatSpecular,
            pkSpecularAccum, pkDiffuseAccum, pkAmbientAccum, pkDiffuseCoeff, pkSpecularCoeff))
        {
            return false;
        }

        NiMaterialNode* pkDiffuseCombineNode = GetAttachableNodeFromLibrary("CompositeFinalRGBAColor");
        kContext.m_spConfigurator->AddNode(pkDiffuseCombineNode);
        kContext.m_spConfigurator->AddBinding(pkDiffuseCoeff, "FinalColor", pkDiffuseCombineNode);
        if (pkOpacityAccum)
            kContext.m_spConfigurator->AddBinding(pkOpacityAccum, "FinalOpacity", pkDiffuseCombineNode);

        NiMaterialResource* pkDiffuseColorAlpha =
            pkDiffuseCombineNode->GetOutputResourceByVariableName("OutputColor");
        NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource(pkDiffuseColorAlpha->GetType(),
            "TexCoord", pkDiffuseColorAlpha->GetLabel(), "DiffuseAccum");
        kContext.m_spConfigurator->AddBinding(pkDiffuseColorAlpha, pkVertOut);

        if (bSpecularOn)
        {
            NiMaterialResource* pkVertOutRes = kContext.m_spOutputs->AddInputResource(pkSpecularCoeff->GetType(),
                "TexCoord", pkSpecularCoeff->GetLabel(), "SpecularAccum");
            kContext.m_spConfigurator->AddBinding(pkSpecularCoeff, pkVertOutRes);
        }
    }
    else
    {
        // Gouraud terms for the pixel stage; the ambient output keeps the diffuse resource's type and label
        if (pkDiffuseAccum)
        {
            NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource(pkDiffuseAccum->GetType(),
                "TexCoord", pkDiffuseAccum->GetLabel(), "DiffuseAccum");
            kContext.m_spConfigurator->AddBinding(pkDiffuseAccum, pkVertOut);
        }
        if (pkAmbientAccum)
        {
            NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource(pkDiffuseAccum->GetType(),
                "TexCoord", pkDiffuseAccum->GetLabel(), "AmbientAccum");
            kContext.m_spConfigurator->AddBinding(pkAmbientAccum, pkVertOut);
        }
        if (pkSpecularAccum)
        {
            NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource(pkSpecularAccum->GetType(),
                "TexCoord", pkSpecularAccum->GetLabel(), "SpecularAccum");
            kContext.m_spConfigurator->AddBinding(pkSpecularAccum, pkVertOut);
        }
    }

    return true;
}
MS2_REPLACE_METHOD(0x1427535F0, MS2StandardMaterial, HandleVertexLightingAndMaterials, 1995, 0xD8B4C67C);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: register allocation differs; same UV set outputs
// @0x142753dc0
bool MS2StandardMaterial::HandleMS2VertexUVSets(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
    NiMaterialResource* pkProjectedPos)
{
    unsigned int uiNextUVSet = 0;
    NiMaterialResource* apkOutputUVs[STANDARD_PIPE_MAX_UVS_FOR_TEXTURES];
    memset(apkOutputUVs, 0, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES * sizeof(NiMaterialResource*));

    if (!HandleTextureUVSets(kContext, pkVertDesc, apkOutputUVs, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES, uiNextUVSet))
        return false;

    if (!HandleMS2TextureEffectUVSets(kContext, apkOutputUVs, STANDARD_PIPE_MAX_UVS_FOR_TEXTURES, pkWorldPos,
        pkWorldNormal, pkWorldReflect, (TexEffectType)pkVertDesc->GetENVMAPTYPE(),
        pkVertDesc->GetPROJLIGHTMAPCOUNT(), pkVertDesc->GetPROJLIGHTMAPTYPES(),
        pkVertDesc->GetPROJSHADOWMAPCOUNT(), pkVertDesc->GetPROJSHADOWMAPTYPES(), uiNextUVSet, pkProjectedPos))
    {
        return false;
    }

    for (unsigned int ui = 0; ui < uiNextUVSet; ui++)
    {
        NiMaterialResource* pkVertOutTexCoord = kContext.m_spOutputs->AddInputResource(
            apkOutputUVs[ui]->GetType(), "TexCoord", "", GenerateUVSetName(ui));
        kContext.m_spConfigurator->AddBinding(apkOutputUVs[ui], pkVertOutTexCoord);
    }

    return true;
}
MS2_REPLACE_METHOD(0x142753DC0, MS2StandardMaterial, HandleMS2VertexUVSets, 584, 0xD5A1503A);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: instruction scheduling of the material type copy differs (8 bytes)
// @0x142754010
void MS2StandardMaterial::Init(const NiFixedString& kName)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
    AddDefaultFallbacks();

    m_bAlphaBoost = false;
    m_bChaos = false;

    if (kName == "MS2AlphaBoostMaterial")
    {
        m_eMaterialType = GetMaterialType("MS2StandardMaterial");
        m_bAlphaBoost = true;
    }
    else if (kName == "MS2ChaosMaterial")
    {
        m_eMaterialType = 1;
        m_bChaos = true;
    }
    else if (kName == "MS2ChaosSkinMaterial")
    {
        m_eMaterialType = 2;
        m_bChaos = true;
    }
    else if (kName == "MS2ChaosHairMaterial")
    {
        m_eMaterialType = 3;
        m_bChaos = true;
    }
    else
    {
        m_eMaterialType = GetMaterialType(kName);
    }

    m_bCharacterLighting = (unsigned int)(m_eMaterialType - 1) <= 2;
    SetForcePerPixelLighting(m_bCharacterLighting);
}
MS2_REPLACE_METHOD(0x142754010, MS2StandardMaterial, Init, 727, 0xB963B2CE);

//--------------------------------------------------------------------------------------------------
// @0x1427542f0
bool MS2StandardMaterial::IsCharacterMaterial() const
{
    return (unsigned int)(m_eMaterialType - 1) <= 2;
}
MS2_REPLACE_METHOD(0x1427542F0, MS2StandardMaterial, IsCharacterMaterial, 15, 0x5189DCAC);

//--------------------------------------------------------------------------------------------------
// @0x142754300
bool MS2StandardMaterial::InsertTextureSample(Context& kContext, TextureMap eMap, NiMaterialResource* pkUV,
    NiMaterialResource*& pkResult)
{
    NiFixedString kName;
    unsigned int uiOccurance = 0;
    if (!GetTextureNameFromTextureEnum(eMap, kName, uiOccurance))
        return false;

    NiMaterialResource* pkSampler = InsertTextureSampler(kContext, kName, TEXTURE_SAMPLER_2D, uiOccurance);
    if (!pkSampler)
        return false;

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("TextureRGBASample");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    bool bResult = kContext.m_spConfigurator->AddBinding(pkUV, pkNode->GetInputResourceByVariableName("TexCoord"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkSampler,
        pkNode->GetInputResourceByVariableName("Sampler"));
    bResult &= kContext.m_spConfigurator->AddBinding(
        kContext.m_spStatics->AddOutputConstant("bool", "(false)"), "Saturate", pkNode);
    if (!bResult)
        return false;

    pkResult = pkNode->GetOutputResourceByVariableName("ColorOut");
    return true;
}
MS2_REPLACE_METHOD(0x142754300, MS2StandardMaterial, InsertTextureSample, 536, 0x03D641BE);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: block layout differs (exe 1023 bytes); same packing requirements
// @0x142754520
bool MS2StandardMaterial::SetupPackingRequirements(NiShader* pkShader, NiMaterialDescriptor* pkMaterialDescriptor,
    RenderPassDescriptor*, unsigned int)
{
    NiStandardMaterialDescriptor* pkRealMaterialDesc = (NiStandardMaterialDescriptor*)pkMaterialDescriptor;

    unsigned int uiStreamCount = 1;
    if (pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_INSTANCED)
        uiStreamCount++;

    NiShaderDeclarationPtr spShaderDecl = NiShaderDeclaration::Create(15, uiStreamCount);
    if (!spShaderDecl)
        return false;

    unsigned int uiInputUVCount = pkRealMaterialDesc->GetINPUTUVCOUNT();
    unsigned int uiEntryCount = 0;
    unsigned int uiUVOffset = 0;
    if (pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_INSTANCED)
    {
        uiUVOffset = 3;
        if (uiUVOffset + uiInputUVCount > 8)
            return false;
    }

    spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_POSITION0,
        NiShaderDeclaration::SPTYPE_FLOAT3);

    if (pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_SKINNED)
    {
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_BLENDWEIGHT,
            NiShaderDeclaration::SPTYPE_FLOAT3);
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_BLENDINDICES,
            NiShaderDeclaration::SPTYPE_UBYTE4);
    }
    else if (pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_INSTANCED)
    {
        spShaderDecl->SetEntry(0, NiShaderDeclaration::SHADERPARAM_NI_TRANSFORM0,
            NiShaderDeclaration::SPTYPE_FLOAT4, uiStreamCount - 1);
        spShaderDecl->SetEntry(1, NiShaderDeclaration::SHADERPARAM_NI_TRANSFORM1,
            NiShaderDeclaration::SPTYPE_FLOAT4, uiStreamCount - 1);
        spShaderDecl->SetEntry(2, NiShaderDeclaration::SHADERPARAM_NI_TRANSFORM2,
            NiShaderDeclaration::SPTYPE_FLOAT4, uiStreamCount - 1);
    }

    if (pkRealMaterialDesc->GetNORMAL() != NORMAL_NONE)
    {
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_NORMAL,
            NiShaderDeclaration::SPTYPE_FLOAT3);
    }

    if (pkRealMaterialDesc->GetVERTEXCOLORS() == VC_EXISTS)
    {
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_COLOR,
            NiShaderDeclaration::SPTYPE_UBYTECOLOR);
    }

    // USERDEFINED02: second colour stream (VertexBrightness), COLOR semantic index 1
    unsigned int uiSecondColorEntry = 0;
    if (pkRealMaterialDesc->GetUSERDEFINED02())
    {
        uiSecondColorEntry = uiEntryCount;
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_COLOR,
            NiShaderDeclaration::SPTYPE_UBYTECOLOR);
    }

    const unsigned int uiTexCoordEntries = uiEntryCount;
    unsigned int ui = 0;
    for (; ui < 8 && ui < uiInputUVCount; ui++)
    {
        spShaderDecl->SetEntry(uiEntryCount++,
            (NiShaderDeclaration::ShaderParameter)(NiShaderDeclaration::SHADERPARAM_NI_TEXCOORD0 + ui + uiUVOffset),
            NiShaderDeclaration::SPTYPE_FLOAT2);
    }

    if (pkRealMaterialDesc->GetNORMAL() == NORMAL_NBT &&
        (pkRealMaterialDesc->GetNORMALMAPCOUNT() || pkRealMaterialDesc->GetPARALLAXMAPCOUNT()))
    {
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_BINORMAL,
            NiShaderDeclaration::SPTYPE_FLOAT3);
        spShaderDecl->SetEntry(uiEntryCount++, NiShaderDeclaration::SHADERPARAM_NI_TANGENT,
            NiShaderDeclaration::SPTYPE_FLOAT3);
    }

    pkShader->SetSemanticAdapterTableFromShaderDeclaration(spShaderDecl);

    NiSemanticAdapterTable& kTable = pkShader->GetSemanticAdapterTable();

    if (pkRealMaterialDesc->GetUSERDEFINED02())
    {
        kTable.SetGenericSemantic(uiSecondColorEntry, NiCommonSemantics::COLOR(), 1);
        kTable.SetRendererSemantic(uiSecondColorEntry, NiCommonSemantics::COLOR(), 1);
    }

    unsigned int uiTextureCount = pkRealMaterialDesc->GetStandardTextureCount();
    bool abUVSetsUsed[STANDARD_PIPE_MAX_TEXTURE_MAPS];
    memset(abUVSetsUsed, 0, sizeof(abUVSetsUsed));

    unsigned int uiCounter = 0;
    for (ui = 0; ui < uiTextureCount; ui++)
    {
        unsigned int uiUVSet;
        TexGenOutput eTexOutput;
        pkRealMaterialDesc->GetTextureUsage(ui, uiUVSet, eTexOutput);
        if (abUVSetsUsed[uiUVSet] == false)
        {
            uiCounter++;
            abUVSetsUsed[uiUVSet] = true;
        }
    }

    uiCounter = 0;
    for (ui = 0; ui < uiInputUVCount; ui++)
    {
        while (abUVSetsUsed[uiCounter] == false)
            uiCounter++;

        NiFixedString kGenericSemantic = kTable.GetGenericSemanticName(uiTexCoordEntries + ui);
        kTable.SetGenericSemantic(uiTexCoordEntries + ui, kGenericSemantic, (NiUInt8)uiCounter);
        uiCounter++;
    }

    return true;
}
MS2_REPLACE_METHOD(0x142754520, MS2StandardMaterial, SetupPackingRequirements, 1023, 0xDD0AB437);

//--------------------------------------------------------------------------------------------------
// @0x142754920
bool MS2StandardMaterial::TransformTexCoord(Context& kContext, NiMaterialResource* pkUV,
    NiMaterialResource* pkTransform, NiMaterialResource*& pkResult)
{
    if (!pkUV)
        return false;

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("TexCoordTransform2D");
    if (!pkNode)
        return false;
    kContext.m_spConfigurator->AddNode(pkNode);

    bool bResult = kContext.m_spConfigurator->AddBinding(pkUV, pkNode->GetInputResourceByVariableName("TexCoordIn"));
    bResult &= kContext.m_spConfigurator->AddBinding(pkTransform,
        pkNode->GetInputResourceByVariableName("Transform2D"));
    if (!bResult)
        return false;

    pkResult = pkNode->GetOutputResourceByVariableName("TexCoordOut");
    return true;
}
MS2_REPLACE_METHOD(0x142754920, MS2StandardMaterial, TransformTexCoord, 317, 0x8D50917A);

// NiImplementRTTI(MS2StandardMaterial, NiStandardMaterial): the initializer sits in the shared .text$di run. The hook DLL
// binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d1f0-0x14014d210 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d1f0
const NiRTTI MS2StandardMaterial::ms_RTTI("MS2StandardMaterial", &NiStandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2StandardMaterial@@6B@ 0x1431c5b30
// MS2-PIN: ?GetRTTI@MS2StandardMaterial@@UEBAPEBVNiRTTI@@XZ 0x14274ee90
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
