// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2GlassMaterial: MS2StandardMaterial with the final
// pixel output reworked so the opacity runs through the CalculateDiffuseOnlyAlpha node (alpha from the lit diffuse
// and specular colour) before the alpha test. No chaos rim or alpha boost. No __FILE__ strings; file name guessed
// from the class name.
// MS2-UNIT: ?\ms2glassmaterial.cpp
// MS2-RANGE: 0x1427742c0-0x142774820 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x1427742c0
MS2GlassMaterial::MS2GlassMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2GlassMaterial", "MS2StandardMaterial", 4, bAutoCreateCaches)
{
}

//--------------------------------------------------------------------------------------------------
// @0x1427743c0
bool MS2GlassMaterial::HandleDiffuseOnlyAlpha(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkDiffuseAccum, NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum,
    NiMaterialResource*& pkOpacityOut)
{
    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("CalculateDiffuseOnlyAlpha");
    kContext.m_spConfigurator->AddNode(pkNode);
    if (pkDiffuseAccum)
        kContext.m_spConfigurator->AddBinding(pkDiffuseAccum, "DiffuseColor", pkNode);
    if (pkSpecularAccum)
        kContext.m_spConfigurator->AddBinding(pkSpecularAccum, "SpecularColor", pkNode);
    if (pkOpacityAccum)
        kContext.m_spConfigurator->AddBinding(pkOpacityAccum, "OpacityIn", pkNode);

    pkOpacityOut = pkNode->GetOutputResourceByVariableName("OpacityOut");
    return true;
}
MS2_REPLACE_METHOD(0x1427743C0, MS2GlassMaterial, HandleDiffuseOnlyAlpha, 329, 0x421440C0);

//--------------------------------------------------------------------------------------------------
// @0x142774510
bool MS2GlassMaterial::HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
    NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    NiMaterialResource* pkPixelOut = kContext.m_spOutputs->AddInputResource("float4", "Color", "", "Color0");

    NiMaterialResource* pkColor = NULL;
    NiMaterialNode* pkRGBNode = GetAttachableNodeFromLibrary("CompositeFinalRGBColor");
    kContext.m_spConfigurator->AddNode(pkRGBNode);
    if (pkDiffuseAccum)
        kContext.m_spConfigurator->AddBinding(pkDiffuseAccum, "DiffuseColor", pkRGBNode);
    if (pkSpecularAccum)
        kContext.m_spConfigurator->AddBinding(pkSpecularAccum, "SpecularColor", pkRGBNode);

    pkColor = pkRGBNode->GetOutputResourceByVariableName("OutputColor");

    if (!HandleApplyFog(kContext, pkPixDesc, pkColor, pkColor))
        return false;

    NiMaterialNode* pkRGBANode = GetAttachableNodeFromLibrary("CompositeFinalRGBAColor");
    kContext.m_spConfigurator->AddNode(pkRGBANode);
    kContext.m_spConfigurator->AddBinding(pkColor, "FinalColor", pkRGBANode);

    if (pkOpacityAccum)
    {
        NiMaterialResource* pkOpacity = NULL;
        if (!HandleDiffuseOnlyAlpha(kContext, pkPixDesc, pkDiffuseAccum, pkSpecularAccum, pkOpacityAccum, pkOpacity))
            return false;
        HandleAlphaTest(kContext, pkPixDesc, pkOpacity);
        kContext.m_spConfigurator->AddBinding(pkOpacity, "FinalOpacity", pkRGBANode);
    }

    kContext.m_spConfigurator->AddBinding("OutputColor", pkRGBANode, pkPixelOut);
    return true;
}
MS2_REPLACE_METHOD(0x142774510, MS2GlassMaterial, HandleMS2FinalPixelOutputs, 769, 0x446F5D55);

// NiImplementRTTI(MS2GlassMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run. The hook
// DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d530-0x14014d550 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d530
const NiRTTI MS2GlassMaterial::ms_RTTI("MS2GlassMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2GlassMaterial@@6B@ 0x1431d44c8
// MS2-PIN: ?GetRTTI@MS2GlassMaterial@@UEBAPEBVNiRTTI@@XZ 0x1427743b0
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
