// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2DirectionalShadowWriteMaterial: the stock directional
// shadow write material with MS2MaterialNodeLibrary appended, so skinned geometry is transformed by the 60-bone
// TransformSkinnedPosition60 fragment (MS2 characters use up to 60 bones per partition) instead of the stock 30-bone
// one. Its own TU: the exe keeps a separate .data copy of the header-static fragment name pointer (0x143a4a658) per
// shadow writer. No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2directionalshadowwritematerial.cpp
// MS2-RANGE: 0x142769ed0-0x14276ab40 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiDirectionalShadowWriteMaterial.h>
#include <DirectionalShadowWriteMaterialNodeLibrary/NiDirectionalShadowWriteMaterialNodeLibrary.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "ms2/client/ms2/material/ms2materialnodelibrary.h"
#include "hook/ms2hook.h"

// "TransformSkinnedPosition60" (the 60-bone skinning fragment of MS2MaterialNodeLibrary); this TU's copy of the
// header-static pointer, .data 0x143a4a658
static const char* g_pcTransformSkinnedPosition60 = "TransformSkinnedPosition60";

//--------------------------------------------------------------------------------------------------
// @0x142769ed0
MS2DirectionalShadowWriteMaterial::MS2DirectionalShadowWriteMaterial(bool bAutoCreateCaches) :
    NiDirectionalShadowWriteMaterial("MS2DirectionalShadowWriteMaterial",
        NiDirectionalShadowWriteMaterialNodeLibrary::CreateMaterialNodeLibrary(), bAutoCreateCaches)
{
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
}

//--------------------------------------------------------------------------------------------------
// @0x14276a0a0
bool MS2DirectionalShadowWriteMaterial::HandlePositionFragment(Context& kContext, TransformType eTransType,
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
MS2_REPLACE_METHOD(0x14276A0A0, MS2DirectionalShadowWriteMaterial, HandlePositionFragment, 2709, 0xFE9E6D3A);

// NiImplementRTTI(MS2DirectionalShadowWriteMaterial, NiDirectionalShadowWriteMaterial): the initializer sits in the
// shared .text$di run. The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d3b0-0x14014d3d0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d3b0
const NiRTTI MS2DirectionalShadowWriteMaterial::ms_RTTI("MS2DirectionalShadowWriteMaterial",
    &NiDirectionalShadowWriteMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2DirectionalShadowWriteMaterial@@6B@ 0x1431d1200
// MS2-PIN: ?GetRTTI@MS2DirectionalShadowWriteMaterial@@UEBAPEBVNiRTTI@@XZ 0x14276a090
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
