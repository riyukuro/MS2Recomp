// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2DepthMaterial: an MS2StandardMaterial variant that
// writes depth. The vertex shader passes the projected position through a texture coordinate
// (PositionPassThrough); the pixel shader runs it through the PositionToDepth node (with the final opacity for alpha
// test) and writes the result as Color0. Normal and environment maps are dropped. No __FILE__ strings; file name
// guessed from the class name.
// MS2-UNIT: ?\ms2depthmaterial.cpp
// MS2-RANGE: 0x142771d50-0x1427726c0 .text$mn
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
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x142771d50
MS2DepthMaterial::MS2DepthMaterial(const NiFixedString& kName, bool bAutoCreateCaches, unsigned int uiVersionOffset) :
    MS2StandardMaterial(kName, "MS2StandardMaterial", uiVersionOffset, bAutoCreateCaches)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142771e90
MS2DepthMaterial::MS2DepthMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2DepthMaterial", "MS2StandardMaterial", 0xe, bAutoCreateCaches)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142772030
NiFragmentMaterial::ReturnCode MS2DepthMaterial::GenerateShaderDescArray(NiMaterialDescriptor* pkMaterialDescriptor,
    RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount, unsigned int& uiCountAdded)
{
    ReturnCode eResult = MS2StandardMaterial::GenerateShaderDescArray(pkMaterialDescriptor, pkRenderPasses,
        uiMaxCount, uiCountAdded);
    if (eResult != RC_SUCCESS)
        return eResult;

    NiStandardVertexProgramDescriptor* pkVertexDesc =
        (NiStandardVertexProgramDescriptor*)pkRenderPasses[0].m_pkVertexDesc;
    NiStandardPixelProgramDescriptor* pkPixelDesc =
        (NiStandardPixelProgramDescriptor*)pkRenderPasses[0].m_pkPixelDesc;
    pkRenderPasses[0].m_bAlphaOverride = true;

    pkVertexDesc->m_pkBitArray[0] |= 0x8;                                       // OUTPUTWORLDNBT
    pkVertexDesc->m_pkBitArray[0] = (pkVertexDesc->m_pkBitArray[0] & ~0x80) | 0x40;    // NORMAL = 1
    pkPixelDesc->m_pkBitArray[0] |= 0x4;                                        // WORLDNORMAL
    pkPixelDesc->m_pkBitArray[0] &= ~0x8;                                       // WORLDNBT
    pkVertexDesc->m_pkBitArray[0] &= ~0x3800;                                   // ENVMAPTYPE
    pkPixelDesc->m_pkBitArray[0] &= ~0x7000000;                                 // ENVMAPTYPE

    return eResult;
}
MS2_REPLACE_METHOD(0x142772030, MS2DepthMaterial, GenerateShaderDescArray, 103, 0x25C43D4A);

//--------------------------------------------------------------------------------------------------
// @0x1427720b0
bool MS2DepthMaterial::HandleEnvMap(Context& kContext, NiStandardMaterial::TexEffectType eTexEffect,
    NiMaterialResource* pkUVResource, NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
    NiMaterialResource* pkBumpOffset, NiMaterialResource* pkGlossiness)
{
    return true;
}
MS2_REPLACE_METHOD(0x1427720B0, MS2DepthMaterial, HandleEnvMap, 3, 0xBB96D90B);

//--------------------------------------------------------------------------------------------------
// @0x1427720c0
bool MS2DepthMaterial::HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
    NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum)
{
    if (pkOpacityAccum)
        HandleAlphaTest(kContext, pkPixDesc, pkOpacityAccum);

    NiMaterialNode* pkPixelIn = kContext.m_spConfigurator->GetNodeByName("PixelIn");
    NiMaterialResource* pkPosProjected = pkPixelIn->AddOutputResource("float4", "TexCoord", "World",
        "WorldPosProjected");

    NiMaterialNode* pkNode = AttachDepthNode("PositionToDepth", kContext, pkOpacityAccum, pkPosProjected);

    NiMaterialNode* pkPixelOut = kContext.m_spConfigurator->GetNodeByName("PixelOut");
    NiMaterialResource* pkColor = pkPixelOut->AddInputResource("float4", "Color", "", "Color0");
    kContext.m_spConfigurator->AddBinding(pkNode->GetOutputResourceByVariableName("Output"), pkColor);
    return true;
}
MS2_REPLACE_METHOD(0x1427720C0, MS2DepthMaterial, HandleMS2FinalPixelOutputs, 652, 0x0F1262D4);

//--------------------------------------------------------------------------------------------------
// @0x142772350
bool MS2DepthMaterial::HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
    NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos)
{
    if (!MS2StandardMaterial::HandleFinalVertexOutputs(kContext, pkVertDesc, pkWorldPos, pkWorldNormal,
        pkWorldReflect, pkViewPos, pkProjectedPos))
    {
        return false;
    }

    NiMaterialResource* pkPassThrough = kContext.m_spOutputs->AddInputResource("float4", "TexCoord", "World",
        "PosProjectedPassThrough");

    NiMaterialNode* pkNode = GetAttachableNodeFromLibrary("PositionPassThrough");
    kContext.m_spConfigurator->AddNode(pkNode);
    kContext.m_spConfigurator->AddBinding(pkProjectedPos, pkNode->GetInputResourceByVariableName("Input"));
    kContext.m_spConfigurator->AddBinding(pkNode->GetOutputResourceByVariableName("Output"), pkPassThrough);
    return true;
}
MS2_REPLACE_METHOD(0x142772350, MS2DepthMaterial, HandleFinalVertexOutputs, 486, 0x323F2806);

//--------------------------------------------------------------------------------------------------
// @0x142772540
bool MS2DepthMaterial::HandleNormalMap(Context& kContext, NiMaterialResource* pkUVSet, NormalMapType eType,
    NiMaterialResource*& pkWorldNormal, NiMaterialResource* pkWorldBinormal, NiMaterialResource* pkWorldTangent)
{
    return true;
}
MS2_REPLACE_METHOD(0x142772540, MS2DepthMaterial, HandleNormalMap, 3, 0xBB96D90B);

//--------------------------------------------------------------------------------------------------
// @0x142772550
bool MS2DepthMaterial::HandlePixelInputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
    NiMaterialResource*& pkPixelWorldPos, NiMaterialResource*& pkPixelWorldNorm,
    NiMaterialResource*& pkPixelWorldBinormal, NiMaterialResource*& pkPixelWorldTangent,
    NiMaterialResource*& pkPixelWorldViewVector, NiMaterialResource*& pkPixelTangentViewVector)
{
    return NiStandardMaterial::HandlePixelInputs(kContext, pkPixelDesc, pkPixelWorldPos, pkPixelWorldNorm,
        pkPixelWorldBinormal, pkPixelWorldTangent, pkPixelWorldViewVector, pkPixelTangentViewVector) ? true : false;
}
MS2_REPLACE_METHOD(0x142772550, MS2DepthMaterial, HandlePixelInputs, 84, 0xB3A474A4);

//--------------------------------------------------------------------------------------------------
// @0x1427725b0
bool MS2DepthMaterial::HandleViewProjectionFragment(Context& kContext, bool bForceViewPos,
    NiMaterialResource* pkVertWorldPos, NiMaterialResource*& pkVertOutProjectedPos,
    NiMaterialResource*& pkVertOutViewPos)
{
    return NiStandardMaterial::HandleViewProjectionFragment(kContext, bForceViewPos, pkVertWorldPos,
        pkVertOutProjectedPos, pkVertOutViewPos) ? true : false;
}
MS2_REPLACE_METHOD(0x1427725B0, MS2DepthMaterial, HandleViewProjectionFragment, 39, 0xAA90E7BE);

//--------------------------------------------------------------------------------------------------
// @0x1427725e0
NiMaterialNodePtr MS2DepthMaterial::AttachDepthNode(const NiFixedString& kNodeName, Context& kContext,
    NiMaterialResource* pkOpacity, NiMaterialResource* pkInput)
{
    NiMaterialNodePtr spNode = GetAttachableNodeFromLibrary(kNodeName);
    kContext.m_spConfigurator->AddNode(spNode);
    kContext.m_spConfigurator->AddBinding(pkInput, spNode->GetInputResourceByVariableName("Input"));
    if (pkOpacity)
        kContext.m_spConfigurator->AddBinding(pkOpacity, spNode->GetInputResourceByVariableName("FinalOpacity"));
    return spNode;
}
MS2_REPLACE_METHOD(0x1427725E0, MS2DepthMaterial, AttachDepthNode, 219, 0x4EC9FE30);

// NiImplementRTTI(MS2DepthMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d4b0-0x14014d4d0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d4b0
const NiRTTI MS2DepthMaterial::ms_RTTI("MS2DepthMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2DepthMaterial@@6B@ 0x1431d3448
// MS2-PIN: ?GetRTTI@MS2DepthMaterial@@UEBAPEBVNiRTTI@@XZ 0x1427720a0
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
