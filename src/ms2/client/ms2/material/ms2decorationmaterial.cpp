// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2DecorationMaterial: a character material for
// instanced, skinned decorations. Skinned geometry also carries an instance transform (three float4 rows on the
// second stream), so the position fragment builds the instance matrix first and feeds it to the skinning node, and
// the vertex declaration puts the instance rows in front of the skinning inputs. No __FILE__ strings; file name
// guessed from the class name.
// MS2-UNIT: ?\ms2decorationmaterial.cpp
// MS2-RANGE: 0x142774820-0x142775ba0 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardMaterialDescriptor.h>
#include <NiMaterialConfigurator.h>
#include <NiMaterialNode.h>
#include <NiMaterialResourceProducerNode.h>
#include <NiMaterialResource.h>
#include <NiShader.h>
#include <NiShaderDeclaration.h>
#include <NiSemanticAdapterTable.h>
#include <NiCommonSemantics.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x142774820
MS2DecorationMaterial::MS2DecorationMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2DecorationMaterial", "MS2CharacterMaterial", 1, bAutoCreateCaches)
{
}

//--------------------------------------------------------------------------------------------------
// @0x142774920
bool MS2DecorationMaterial::HandlePositionFragment(Context& kContext, TransformType eTransType,
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
    else if (eTransType == TRANSFORM_SKINNED)
    {
        // skinned decorations are instanced too: build the instance matrix, then skin with it
        NiMaterialNode* pkInstTransFrag = GetAttachableNodeFromLibrary("ConstructInstanceTransform");
        kContext.m_spConfigurator->AddNode(pkInstTransFrag);

        kContext.m_spInputs->AddOutputResource("float3", "Position", "Local", "Position");
        kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "World", "Position1");
        kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "World", "Position2");
        kContext.m_spInputs->AddOutputResource("float4", "TexCoord", "World", "Position3");

        kContext.m_spConfigurator->AddBinding("Position1", kContext.m_spInputs, "Position1", pkInstTransFrag);
        kContext.m_spConfigurator->AddBinding("Position2", kContext.m_spInputs, "Position2", pkInstTransFrag);
        kContext.m_spConfigurator->AddBinding("Position3", kContext.m_spInputs, "Position3", pkInstTransFrag);

        NiMaterialResource* pkInstanceWorld = pkInstTransFrag->GetOutputResourceByVariableName("InstanceWorld");

        // characters are skinned with up to 60 bones per partition
        unsigned int uiBones = m_bCharacterLighting ? 60 : 30;
        NiMaterialNode* pkProjFrag = GetAttachableNodeFromLibrary(
            m_bCharacterLighting ? "TransformInstanceSkinnedPosition60" : "TransformSkinnedPosition");
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
        kContext.m_spConfigurator->AddBinding(pkInstanceWorld, "InstanceMatrix", pkProjFrag);

        pkVertWorldPos = pkProjFrag->GetOutputResourceByVariableName("WorldPos");
        pkWorldMatrix = pkProjFrag->GetOutputResourceByVariableName("SkinBoneTransform");
        return true;
    }
    else if (eTransType == TRANSFORM_INSTANCED)
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
MS2_REPLACE_METHOD(0x142774920, MS2DecorationMaterial, HandlePositionFragment, 3742, 0x98AC10AA);

//--------------------------------------------------------------------------------------------------
// MS2-FUNCTIONAL: loop counters get swapped registers (exe 991 bytes); same vertex declaration
// @0x1427757c0
bool MS2DecorationMaterial::SetupPackingRequirements(NiShader* pkShader, NiMaterialDescriptor* pkMaterialDescriptor,
    RenderPassDescriptor*, unsigned int)
{
    NiStandardMaterialDescriptor* pkRealMaterialDesc = (NiStandardMaterialDescriptor*)pkMaterialDescriptor;

    // skinned decorations carry the instance rows on a second stream as well
    unsigned int uiStreamCount = 1;
    if (pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_SKINNED ||
        pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_INSTANCED)
    {
        uiStreamCount++;
    }

    NiShaderDeclarationPtr spShaderDecl = NiShaderDeclaration::Create(15, uiStreamCount);
    if (!spShaderDecl)
        return false;

    unsigned int uiInputUVCount = pkRealMaterialDesc->GetINPUTUVCOUNT();
    unsigned int uiEntryCount = 0;
    unsigned int uiUVOffset = 0;
    TransformType eTransform = (TransformType)pkRealMaterialDesc->GetTRANSFORM();
    if (eTransform == TRANSFORM_SKINNED || eTransform == TRANSFORM_INSTANCED)
    {
        uiUVOffset = 3;
        if (uiUVOffset + uiInputUVCount > 8)
            return false;
    }

    if (eTransform == TRANSFORM_SKINNED)
    {
        spShaderDecl->SetEntry(0, NiShaderDeclaration::SHADERPARAM_NI_TRANSFORM0,
            NiShaderDeclaration::SPTYPE_FLOAT4, uiStreamCount - 1);
        spShaderDecl->SetEntry(1, NiShaderDeclaration::SHADERPARAM_NI_TRANSFORM1,
            NiShaderDeclaration::SPTYPE_FLOAT4, uiStreamCount - 1);
        spShaderDecl->SetEntry(2, NiShaderDeclaration::SHADERPARAM_NI_TRANSFORM2,
            NiShaderDeclaration::SPTYPE_FLOAT4, uiStreamCount - 1);
        spShaderDecl->SetEntry(0, NiShaderDeclaration::SHADERPARAM_NI_POSITION0,
            NiShaderDeclaration::SPTYPE_FLOAT3);
        spShaderDecl->SetEntry(1, NiShaderDeclaration::SHADERPARAM_NI_BLENDWEIGHT,
            NiShaderDeclaration::SPTYPE_FLOAT3);
        spShaderDecl->SetEntry(2, NiShaderDeclaration::SHADERPARAM_NI_BLENDINDICES,
            NiShaderDeclaration::SPTYPE_UBYTE4);
        uiEntryCount = 3;
    }
    if (pkRealMaterialDesc->GetTRANSFORM() == TRANSFORM_INSTANCED)
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
MS2_REPLACE_METHOD(0x1427757C0, MS2DecorationMaterial, SetupPackingRequirements, 991, 0x7D2977AA);

// NiImplementRTTI(MS2DecorationMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run. The
// hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d550-0x14014d570 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d550
const NiRTTI MS2DecorationMaterial::ms_RTTI("MS2DecorationMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2DecorationMaterial@@6B@ 0x1431d48e0
// MS2-PIN: ?GetRTTI@MS2DecorationMaterial@@UEBAPEBVNiRTTI@@XZ 0x142774910
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
