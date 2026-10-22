// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2CharacterDepthMaterial: MS2DepthMaterial for
// characters. The depth node is PositionToDepthForCharacter, which also takes the near plane (gfNearZ global). No
// __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2characterdepthmaterial.cpp
// MS2-RANGE: 0x1427726c0-0x1427728f0 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x1427726c0
MS2CharacterDepthMaterial::MS2CharacterDepthMaterial(bool bAutoCreateCaches) :
    MS2DepthMaterial("MS2CharacterDepthMaterial", bAutoCreateCaches, 1)
{
}

//--------------------------------------------------------------------------------------------------
// @0x1427727a0
NiMaterialNodePtr MS2CharacterDepthMaterial::AttachDepthNode(const NiFixedString& kNodeName, Context& kContext,
    NiMaterialResource* pkOpacity, NiMaterialResource* pkInput)
{
    NiMaterialNodePtr spNode = MS2DepthMaterial::AttachDepthNode("PositionToDepthForCharacter", kContext, pkOpacity,
        pkInput);

    NiMaterialResourcePtr spNearZ = AddOutputGlobal(kContext.m_spUniforms, "gfNearZ",
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    kContext.m_spConfigurator->AddBinding(spNearZ, spNode->GetInputResourceByVariableName("GfNearZ"));
    return spNode;
}
MS2_REPLACE_METHOD(0x1427727A0, MS2CharacterDepthMaterial, AttachDepthNode, 331, 0x6AA74532);

// NiImplementRTTI(MS2CharacterDepthMaterial, MS2DepthMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d4d0-0x14014d4f0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d4d0
const NiRTTI MS2CharacterDepthMaterial::ms_RTTI("MS2CharacterDepthMaterial", &MS2DepthMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2CharacterDepthMaterial@@6B@ 0x1431d3838
// MS2-PIN: ?GetRTTI@MS2CharacterDepthMaterial@@UEBAPEBVNiRTTI@@XZ 0x142772790
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
