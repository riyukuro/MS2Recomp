// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2MotionBlurMaterial: an MS2StandardMaterial variant
// that writes a per-pixel screen velocity for the motion blur pass. The vertex shader runs PositionToVelocity on the
// world position against this frame's and the previous frame's view-projection (mViewProjectionLast global) and
// passes the result through a texture coordinate; the pixel shader writes it out as Color0 via Float2ToFloat4.
// Lighting is reduced to the vertex colours / a white diffuse term. No __FILE__ strings; file name guessed from the
// class name.
// MS2-UNIT: ?\ms2motionblurmaterial.cpp
// MS2-RANGE: 0x14276e620-0x14276fc70 .text$mn
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

// "TransformSkinnedPosition60" (the 60-bone skinning fragment of MS2MaterialNodeLibrary); this TU's copy of the
// header-static pointer, .data 0x143a4a670
static const char* g_pcTransformSkinnedPosition60 = "TransformSkinnedPosition60";

//--------------------------------------------------------------------------------------------------
// @0x14276e620
MS2MotionBlurMaterial::MS2MotionBlurMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2MotionBlurMaterial", "MS2StandardMaterial", 3, bAutoCreateCaches)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2UIMaterialNodeLibrary::CreateMaterialNodeLibrary());
}

//--------------------------------------------------------------------------------------------------
// @0x14276e950
bool MS2MotionBlurMaterial::HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
    NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialResource* pkVelocity = kContext.m_spInputs->AddOutputResource("float2", "TexCoord", "World",
        "VelocityUV");
    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("Float2ToFloat4");
    kContext.m_spConfigurator->AddNode(pkNode);
    kContext.m_spConfigurator->AddBinding(pkVelocity, pkNode->GetInputResourceByVariableName("Input"));
    kContext.m_spConfigurator->AddBinding(pkNode->GetOutputResourceByVariableName("Output"), pkPixelOut);
    return true;
}
MS2_REPLACE_METHOD(0x14276E950, MS2MotionBlurMaterial, HandleMS2FinalPixelOutputs, 557, 0xE2CEBC6D);

//--------------------------------------------------------------------------------------------------
// @0x14276eb80
bool MS2MotionBlurMaterial::HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
    NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos)
{
    if (!NiStandardMaterial::HandleFinalVertexOutputs(kContext, pkVertDesc, pkWorldPos, pkWorldNormal,
        pkWorldReflect, pkViewPos, pkProjectedPos))
    {
        return false;
    }

    NiMaterialResource* pkViewProj = AddOutputPredefined(kContext.m_spUniforms,
        NiShaderConstantMap::SCM_DEF_VIEWPROJ, 4);
    NiMaterialResource* pkViewProjLast = AddOutputGlobal(kContext.m_spUniforms, "mViewProjectionLast",
        NiShaderAttributeDesc::ATTRIB_TYPE_MATRIX4);
    NiMaterialResource* pkVelocity = kContext.m_spOutputs->AddInputResource("float2", "TexCoord", "whatIsIt",
        "VelocityUV");

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("PositionToVelocity");
    kContext.m_spConfigurator->AddNode(pkNode);
    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkNode->GetInputResourceByVariableName("vWorldPos"));
    kContext.m_spConfigurator->AddBinding(pkViewProj, pkNode->GetInputResourceByVariableName("mViewProjection"));
    kContext.m_spConfigurator->AddBinding(pkViewProjLast,
        pkNode->GetInputResourceByVariableName("mViewProjectionLast"));
    kContext.m_spConfigurator->AddBinding(pkNode->GetOutputResourceByVariableName("velocity"), pkVelocity);
    return true;
}
MS2_REPLACE_METHOD(0x14276EB80, MS2MotionBlurMaterial, HandleFinalVertexOutputs, 686, 0x7801F5F4);

//--------------------------------------------------------------------------------------------------
// @0x14276ee30
bool MS2MotionBlurMaterial::HandlePositionFragment(Context& kContext, TransformType eTransType,
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
MS2_REPLACE_METHOD(0x14276EE30, MS2MotionBlurMaterial, HandlePositionFragment, 2709, 0x97889706);

//--------------------------------------------------------------------------------------------------
// @0x14276f8d0
bool MS2MotionBlurMaterial::HandleVertexLightingAndMaterials(Context& kContext,
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

    if (uiNumPerVertexLights != 0 || bVertexOnlyLights)
    {
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

        // the ambient light is registered but no lighting is computed
        if (eLightingMode == LIGHTING_E_A_D)
            AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_AMBIENTLIGHT);

        if (bVertexOnlyLights)
        {
            NiMaterialResource* pkWhite = kContext.m_spStatics->AddOutputConstant("float4", "(1.0, 1.0, 1.0, 1.0)");
            NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource("float4", "TexCoord", "",
                "DiffuseAccum");
            kContext.m_spConfigurator->AddBinding(pkWhite, pkVertOut);
        }

        return true;
    }

    // only pixel lights
    bool bVertexColors = pkVertexDesc->GetVERTEXCOLORS() == VC_EXISTS;
    if (bVertexColors && (eAmbDiffEmissive == ADE_EMISSIVE ||
        (eAmbDiffEmissive == ADE_AMB_DIFF && eLightingMode == LIGHTING_E_A_D)))
    {
        NiMaterialResource* pkVertIn = kContext.m_spInputs->AddOutputResource("float4", "Color", "",
            "VertexColors");
        NiMaterialResource* pkVertOut = kContext.m_spOutputs->AddInputResource(pkVertIn->GetType(),
            pkVertIn->GetSemantic(), pkVertIn->GetLabel(), "VertexColors");
        kContext.m_spConfigurator->AddBinding(pkVertIn, pkVertOut);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14276F8D0, MS2MotionBlurMaterial, HandleVertexLightingAndMaterials, 923, 0xC4F11908);

// NiImplementRTTI(MS2MotionBlurMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d470-0x14014d490 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d470
const NiRTTI MS2MotionBlurMaterial::ms_RTTI("MS2MotionBlurMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2MotionBlurMaterial@@6B@ 0x1431d2aa0
// MS2-PIN: ?GetRTTI@MS2MotionBlurMaterial@@UEBAPEBVNiRTTI@@XZ 0x14276e940
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
