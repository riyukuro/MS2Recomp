// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2ShimmerMaterial: the MS2StandardMaterial variant used
// for the shimmer (distortion) pass. It disables fog, forwards the projected position with the vertex UV sets, and
// replaces the pre-light texture stage so that a missing base map yields the neutral (0.5, 0.5, 0.0) offset and the
// dark map is counted but not applied. No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2shimmermaterial.cpp
// MS2-RANGE: 0x142773900-0x1427742c0 .text$mn
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

// keeps the 24-parameter HandlePreLightTextureApplication signature within the @0x tag window
typedef NiMaterialResource Res;

//--------------------------------------------------------------------------------------------------
// @0x142773900
MS2ShimmerMaterial::MS2ShimmerMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2ShimmerMaterial", "MS2StandardMaterial", 7, bAutoCreateCaches)
{
    m_kLibraries.Add(NiStandardMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2MaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_kLibraries.Add(MS2UIMaterialNodeLibrary::CreateMaterialNodeLibrary());
    m_bCharacterLighting = true;
}

//--------------------------------------------------------------------------------------------------
// @0x142773bf0
NiFragmentMaterial::ReturnCode MS2ShimmerMaterial::GenerateShaderDescArray(NiMaterialDescriptor* pkMaterialDescriptor,
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
    }

    return eResult;
}
MS2_REPLACE_METHOD(0x142773BF0, MS2ShimmerMaterial, GenerateShaderDescArray, 278, 0x217FA799);

//--------------------------------------------------------------------------------------------------
// @0x142773d20
bool MS2ShimmerMaterial::HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
    NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
    NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos)
{
    return HandleMS2VertexUVSets(kContext, pkVertDesc, pkWorldPos, pkWorldNormal, pkWorldReflect,
        pkProjectedPos) ? true : false;
}
MS2_REPLACE_METHOD(0x142773D20, MS2ShimmerMaterial, HandleFinalVertexOutputs, 57, 0x2B21A011);

//--------------------------------------------------------------------------------------------------
// @0x142773d60
bool MS2ShimmerMaterial::HandlePreLightTextureApplication(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    Res*& pkWorldPos, Res*& pkWorldNormal, Res*& pkWorldBinormal, Res*& pkWorldTangent, Res*& pkWorldView,
    Res*& pkTangentView, Res*& pkDiffuse, Res*& pkSpecular, Res*& pkSpecPower, Res*& pkGloss, Res*& pkAmbient,
    Res*& pkEmissive, Res*& pkOpacityAccum, Res*& pkAmbientLight, Res*& pkDiffuseLight, Res*& pkSpecularLight,
    Res*& pkDiffuseTex, Res*& pkSpecularTex, unsigned int& uiTexturesApplied, Res** apkUVSets,
    unsigned int uiNumStandardUVs, unsigned int uiNumTexEffectUVs) {
    unsigned int uiApplied = 0;

    if (pkPixDesc->GetPARALLAXMAPCOUNT() == 1)
    {
        unsigned int uiParallaxUV = FindUVSetIndexForTextureEnum(MAP_PARALLAX, pkPixDesc);
        NiMaterialResource* pkParallaxUV = apkUVSets[uiParallaxUV];
        if (!HandleParallaxMap(kContext, pkParallaxUV, pkTangentView))
            return false;
        uiApplied++;
        apkUVSets[uiParallaxUV] = pkParallaxUV;
    }

    bool bNormalMap = pkPixDesc->GetNORMALMAPCOUNT() != 0;
    if (bNormalMap)
    {
        NormalMapType eType = (NormalMapType)pkPixDesc->GetNORMALMAPTYPE();
        if (!HandleNormalMap(kContext, FindUVSetIndexForTextureEnum(MAP_NORMAL, pkPixDesc, apkUVSets), eType,
            pkWorldNormal, pkWorldBinormal, pkWorldTangent))
        {
            return false;
        }
        uiApplied++;
    }

    // the dark map keeps its texture slot but is not applied to the shimmer value
    if (pkPixDesc->GetDARKMAPCOUNT() == 1)
        uiApplied++;

    unsigned int uiEffectUV = 0;
    if (pkPixDesc->GetENVMAPTYPE() != TEXEFFECT_NONE && pkPixDesc->GetNORMALMAPCOUNT() == 0)
        uiEffectUV++;

    unsigned int uiProjLights = pkPixDesc->GetPROJLIGHTMAPCOUNT();
    if (uiProjLights > 0)
    {
        unsigned int uiBit = 1;
        for (unsigned int ui = 0; ui < uiProjLights; ui++)
        {
            bool bPerspective = (pkPixDesc->GetPROJLIGHTMAPTYPES() & uiBit) != 0;
            bool bClipped = (pkPixDesc->GetPROJLIGHTMAPCLIPPED() & uiBit) != 0;
            if (!HandleProjLightMap(kContext, apkUVSets[uiNumStandardUVs + uiEffectUV], ui, bPerspective, bClipped,
                pkWorldPos, pkDiffuseTex, pkSpecularTex))
            {
                return false;
            }
            uiEffectUV++;
            uiBit *= 2;
        }
    }

    if (pkPixDesc->GetBASEMAPCOUNT() == 1)
    {
        bool bAlphaOnly = pkPixDesc->GetBASEMAPALPHAONLY() == 1;
        if (!HandleBaseMap(kContext, FindUVSetIndexForTextureEnum(MAP_BASE, pkPixDesc, apkUVSets), pkDiffuseTex,
            pkOpacityAccum, bAlphaOnly))
        {
            return false;
        }
        uiApplied++;
    }
    else if (pkDiffuseTex == NULL)
    {
        // no base map: neutral shimmer offset
        pkDiffuseTex = kContext.m_spStatics->AddOutputConstant("float3", "(0.5f, 0.5f, 0.0f)");
    }

    if (pkPixDesc->GetDETAILMAPCOUNT() == 1)
    {
        if (!HandleDetailMap(kContext, FindUVSetIndexForTextureEnum(MAP_DETAIL, pkPixDesc, apkUVSets), pkDiffuseTex,
            pkSpecularTex))
        {
            return false;
        }
        uiApplied++;
    }

    unsigned int uiDecals = pkPixDesc->GetDECALMAPCOUNT();
    if (uiDecals > 0)
    {
        for (unsigned int ui = 0; ui < uiDecals; ui++)
        {
            if (!HandleDecalMap(kContext,
                FindUVSetIndexForTextureEnum((TextureMap)(MAP_DECAL00 + ui), pkPixDesc, apkUVSets), ui, pkDiffuseTex,
                pkSpecularTex))
            {
                return false;
            }
            uiApplied++;
        }
    }

    if (!HandleCustomMaps(kContext, pkPixDesc, uiApplied, apkUVSets, uiNumStandardUVs, pkDiffuse, pkSpecular,
        pkSpecPower, pkGloss, pkAmbient, pkEmissive, pkOpacityAccum, pkAmbientLight, pkDiffuseLight, pkSpecularLight,
        pkDiffuseTex, pkSpecularTex))
    {
        return false;
    }

    unsigned int uiProjShadows = pkPixDesc->GetPROJSHADOWMAPCOUNT();
    if (uiProjShadows > 0)
    {
        unsigned int uiBit = 1;
        for (unsigned int ui = 0; ui < uiProjShadows; ui++)
        {
            bool bPerspective = (pkPixDesc->GetPROJSHADOWMAPTYPES() & uiBit) != 0;
            bool bClipped = (pkPixDesc->GetPROJSHADOWMAPCLIPPED() & uiBit) != 0;
            if (!HandleProjShadowMap(kContext, apkUVSets[uiNumStandardUVs + uiEffectUV], ui, bPerspective, bClipped,
                pkWorldPos, pkDiffuseTex, pkSpecularTex))
            {
                return false;
            }
            uiEffectUV++;
            uiBit *= 2;
        }
    }

    if (pkPixDesc->GetGLOSSMAPCOUNT() == 1)
    {
        if (!HandleGlossMap(kContext, FindUVSetIndexForTextureEnum(MAP_GLOSS, pkPixDesc, apkUVSets), pkGloss))
            return false;
        uiApplied++;
    }

    uiTexturesApplied = uiApplied;
    return true;
}
MS2_REPLACE_METHOD(0x142773D60, MS2ShimmerMaterial, HandlePreLightTextureApplication, 1374, 0x4FEAAAFB);

// NiImplementRTTI(MS2ShimmerMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run. The hook
// DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d510-0x14014d530 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d510
const NiRTTI MS2ShimmerMaterial::ms_RTTI("MS2ShimmerMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2ShimmerMaterial@@6B@ 0x1431d40a0
// MS2-PIN: ?GetRTTI@MS2ShimmerMaterial@@UEBAPEBVNiRTTI@@XZ 0x142773d10
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
