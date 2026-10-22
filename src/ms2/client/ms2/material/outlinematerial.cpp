// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). OutlineMaterial: the MS2CharacterMaterial variant drawn in
// the character outline pass. Its transform pipeline projects the position after pushing it out along the world normal
// (the ExtractOutline fragment of MS2MaterialNodeLibrary, scaled by the OutlineWidth attribute) and its pixel shader
// outputs the OutlineColor attribute, fogged and alpha-tested like MS2StandardMaterial. No __FILE__ strings; file name
// guessed from the class name.
// MS2-UNIT: ?\outlinematerial.cpp
// MS2-RANGE: 0x142754a60-0x142755940 .text$mn
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
// @0x142754a60
OutlineMaterial::OutlineMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("OutlineMaterial", "MS2CharacterMaterial", 0xe, bAutoCreateCaches)
{
}

//--------------------------------------------------------------------------------------------------
// @0x142754b60
bool OutlineMaterial::HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
    NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");

    NiMaterialResource* pkColor = AddOutputAttribute(kContext.m_spUniforms, "OutlineColor",
        NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    if (!pkColor)
        return false;
    if (!HandleApplyFog(kContext, pkPixDesc, pkColor, pkColor))
        return false;

    NiMaterialNode* pkRGBANode = GetAttachableNodeFromLibrary("CompositeFinalRGBAColor");
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
MS2_REPLACE_METHOD(0x142754B60, OutlineMaterial, HandleMS2FinalPixelOutputs, 563, 0xC76D5776);

//--------------------------------------------------------------------------------------------------
// @0x142754da0
bool OutlineMaterial::HandleOutlineViewProjection(Context& kContext, bool bForceViewPos,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource*& pkProjectedPos,
    NiMaterialResource*& pkViewPos)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("ExtractOutline");
    if (!pkNode)
        return false;

    kContext.m_spConfigurator->AddNode(pkNode);

    NiMaterialResource* pkView = AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_VIEW, 4);
    kContext.m_spConfigurator->AddBinding(pkView, pkNode->GetInputResourceByVariableName("ViewTransform"));
    NiMaterialResource* pkProj = AddOutputPredefined(kContext.m_spUniforms, NiShaderConstantMap::SCM_DEF_PROJ, 4);
    kContext.m_spConfigurator->AddBinding(pkProj, pkNode->GetInputResourceByVariableName("ProjTransform"));
    kContext.m_spConfigurator->AddBinding(pkWorldPos, pkNode->GetInputResourceByVariableName("WorldPosition"));
    kContext.m_spConfigurator->AddBinding(pkWorldNormal, pkNode->GetInputResourceByVariableName("WorldNormal"));

    NiMaterialResource* pkWidth = AddOutputAttribute(kContext.m_spUniforms, "OutlineWidth",
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    kContext.m_spConfigurator->AddBinding(pkWidth, pkNode->GetInputResourceByVariableName("OutlineWidth"));

    pkViewPos = pkNode->GetOutputResourceByVariableName("ViewPos");
    pkProjectedPos = pkNode->GetOutputResourceByVariableName("ProjPos");
    return true;
}
MS2_REPLACE_METHOD(0x142754DA0, OutlineMaterial, HandleOutlineViewProjection, 662, 0xB904928B);

//--------------------------------------------------------------------------------------------------
// NiStandardMaterial::SetupTransformPipeline with HandleOutlineViewProjection in place of HandleViewProjectionFragment.
// @0x142755040
bool OutlineMaterial::SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
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

    if (!HandleOutlineViewProjection(kContext, bForceViewPos, pkWorldPos, pkWorldNormal, pkProjectedPos, pkViewPos))
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
MS2_REPLACE_METHOD(0x142755040, OutlineMaterial, SetupTransformPipeline, 2298, 0x00469646);

// NiImplementRTTI(OutlineMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run. The hook DLL
// binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d210-0x14014d230 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d210
const NiRTTI OutlineMaterial::ms_RTTI("OutlineMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7OutlineMaterial@@6B@ 0x1431c6458
// MS2-PIN: ?GetRTTI@OutlineMaterial@@UEBAPEBVNiRTTI@@XZ 0x142754b50
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
