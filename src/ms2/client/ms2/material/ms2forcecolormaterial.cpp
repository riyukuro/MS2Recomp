// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2ForceColorMaterial: an MS2StandardMaterial that
// keeps the standard shade tree for alpha testing but writes a single uniform color ("ForceForcedColor") to the
// pixel output. No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2forcecolormaterial.cpp
// MS2-RANGE: 0x142776e50-0x142777100 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResource.h>
#include <NiShaderAttributeDesc.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x142776e50
MS2ForceColorMaterial::MS2ForceColorMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2ForceColorMaterial", "MS2StandardMaterial", 5, bAutoCreateCaches)
{
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142776f60
bool MS2ForceColorMaterial::HandleMS2FinalPixelOutputs(Context& kContext,
    NiStandardPixelProgramDescriptor* pkPixDesc, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector,
    NiMaterialResource* pkDiffuseAccum, NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    if (pkOpacityAccum)
        HandleAlphaTest(kContext, pkPixDesc, pkOpacityAccum);

    NiMaterialNode* pkPixelOut = kContext.m_spConfigurator->GetNodeByName("PixelOut");
    kContext.m_spConfigurator->AddBinding(
        AddOutputAttribute(kContext.m_spUniforms, "ForceForcedColor", NiShaderAttributeDesc::ATTRIB_TYPE_COLOR),
        pkPixelOut->AddInputResource("float4", "Color", "", "Color0"));
    return true;
}
MS2_REPLACE_METHOD(0x142776F60, MS2ForceColorMaterial, HandleMS2FinalPixelOutputs, 406, 0x5630D0EF);

// NiImplementRTTI(MS2ForceColorMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d5b0-0x14014d5d0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d5b0
const NiRTTI MS2ForceColorMaterial::ms_RTTI("MS2ForceColorMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2ForceColorMaterial@@6B@ 0x1431d54e8
// MS2-PIN: ?GetRTTI@MS2ForceColorMaterial@@UEBAPEBVNiRTTI@@XZ 0x142776f50
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
