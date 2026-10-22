// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2MaterialLibrary: publishes a NiShaderDesc per MS2 material
// for the tools and creates/caches the materials by name (see ms2materiallibrary.h). No __FILE__ strings; file name
// guessed from the class name.
// MS2-UNIT: ?\ms2materiallibrary.cpp
// MS2-RANGE: 0x142767180-0x142769ed0 .text$mn
// MS2-FLAGS: gamebryo
// the exe inlines NiFixedString::operator=(const char*) here (NiTFixedStringMap<NiMaterialPtr>::DeleteItem)
#define EE_MS2_NIFS_ASSIGN_FORCE
#include "ms2/placeholder/ms2stdafx.h"

#include <NiShaderDesc.h>
#include <NiShaderAttributeDesc.h>
#include <NiString.h>
#include <efd/StringUtilities.h>
#include "ms2/client/ms2/material/ms2materiallibrary.h"
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

MS2MaterialLibrary* MS2MaterialLibrary::ms_pkThis = NULL;
unsigned int MS2MaterialLibrary::ms_uiCurrentDesc = 0;

//--------------------------------------------------------------------------------------------------
// @0x142767180
MS2MaterialLibrary::MS2MaterialLibrary() :
    NiMaterialLibrary("MS2MaterialLibrary")
{
    memset(m_apkDescs, 0, sizeof(m_apkDescs));

    NiColor kRed(1.0f, 0.0f, 0.0f);
    NiColor kGreen(0.0f, 1.0f, 0.0f);
    NiColor kBlue(0.0f, 0.0f, 1.0f);
    NiShaderAttributeDesc* pkAttrib;

    CreateCharacterDesc(m_apkDescs[0]);
    m_apkDescs[0]->SetName("MS2CharacterMaterial");
    m_apkDescs[0]->SetDescription("Material that includes rim light and uses half-lambert equation in diffuse factor.");

    CreateCharacterDesc(m_apkDescs[1]);
    m_apkDescs[1]->SetName("MS2CharacterSkinMaterial");
    m_apkDescs[1]->SetDescription("Material that includes rim light and lambSkin in diffuse factor.");

    m_apkDescs[2] = NiNew NiShaderDesc();
    m_apkDescs[2]->SetName("MS2StandardMaterial");
    m_apkDescs[2]->SetConfigurableMaterial(false);
    m_apkDescs[2]->SetDescription("Material that adds the capability of additive dark maps, instead of the default "
        "standard material behavior.");
    m_apkDescs[2]->SetBonesPerPartition(30);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("MapAttribute");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_STRING);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_String("");
    m_apkDescs[2]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ColorBoost");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(true);
    pkAttrib->SetValue_Float(1.0f);
    m_apkDescs[2]->AddAttribute(pkAttrib);

    m_apkDescs[3] = NiNew NiShaderDesc();
    m_apkDescs[3]->SetName("MS2DirectionalShadowWriteMaterial");
    m_apkDescs[3]->SetConfigurableMaterial(false);

    m_apkDescs[4] = NiNew NiShaderDesc();
    m_apkDescs[4]->SetName("MS2PointShadowWriteMaterial");
    m_apkDescs[4]->SetConfigurableMaterial(false);

    m_apkDescs[5] = NiNew NiShaderDesc();
    m_apkDescs[5]->SetName("MS2SpotShadowWriteMaterial");
    m_apkDescs[5]->SetConfigurableMaterial(false);

    m_apkDescs[6] = NiNew NiShaderDesc();
    m_apkDescs[6]->SetName("CustomizedTextureGeneratorMaterial");
    m_apkDescs[6]->SetConfigurableMaterial(false);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OverrideColor0");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kRed);
    m_apkDescs[6]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OverrideColor1");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kGreen);
    m_apkDescs[6]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OverrideColor2");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kBlue);
    m_apkDescs[6]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("DecalOverrideColor0");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kRed);
    m_apkDescs[6]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("DecalOverrideColor1");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kGreen);
    m_apkDescs[6]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("DecalOverrideColor2");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kBlue);
    m_apkDescs[6]->AddAttribute(pkAttrib);

    m_apkDescs[7] = NiNew NiShaderDesc();
    m_apkDescs[7]->SetName("TexCoordWriteMaterial");
    m_apkDescs[7]->SetConfigurableMaterial(false);

    m_apkDescs[8] = NiNew NiShaderDesc();
    m_apkDescs[8]->SetName("OutlineMaterial");
    m_apkDescs[8]->SetConfigurableMaterial(true);
    m_apkDescs[8]->SetDescription("Outline Material");

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OutlineWidth");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(0.0f);
    m_apkDescs[8]->AddAttribute(pkAttrib);

    m_apkDescs[9] = NiNew NiShaderDesc();
    m_apkDescs[9]->SetName("MRTShaderPickerMaterial");
    m_apkDescs[9]->SetConfigurableMaterial(false);

    m_apkDescs[10] = NiNew NiShaderDesc();
    m_apkDescs[10]->SetName("MS2MotionBlurMaterial");
    m_apkDescs[10]->SetConfigurableMaterial(false);

    m_apkDescs[11] = NiNew NiShaderDesc();
    m_apkDescs[11]->SetName("MS2RadialBlurMaterial");
    m_apkDescs[11]->SetConfigurableMaterial(false);

    m_apkDescs[12] = NiNew NiShaderDesc();
    m_apkDescs[12]->SetName("MS2OuterGlowCharacterMaterial");
    m_apkDescs[12]->SetConfigurableMaterial(false);

    m_apkDescs[13] = NiNew NiShaderDesc();
    m_apkDescs[13]->SetName("MS2DepthMaterial");
    m_apkDescs[13]->SetConfigurableMaterial(false);
    m_apkDescs[13]->SetBonesPerPartition(60);

    m_apkDescs[14] = NiNew NiShaderDesc();
    m_apkDescs[14]->SetName("MS2DefaultShimmerValueMaterial");
    m_apkDescs[14]->SetConfigurableMaterial(false);

    m_apkDescs[15] = NiNew NiShaderDesc();
    m_apkDescs[15]->SetName("MS2ShimmerMaterial");
    m_apkDescs[15]->SetConfigurableMaterial(false);

    m_apkDescs[16] = NiNew NiShaderDesc();
    m_apkDescs[16]->SetName("MS2GlassMaterial");
    m_apkDescs[16]->SetConfigurableMaterial(false);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("FresnelBoost");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(5.0f);
    m_apkDescs[16]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("FresnelExponent");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(4.0f);
    m_apkDescs[16]->AddAttribute(pkAttrib);

    m_apkDescs[17] = NiNew NiShaderDesc();
    m_apkDescs[17]->SetName("MS2DecorationMaterial");
    m_apkDescs[17]->SetConfigurableMaterial(false);
    m_apkDescs[17]->SetBonesPerPartition(60);

    m_apkDescs[18] = NiNew NiShaderDesc();
    m_apkDescs[18]->SetName("MS2GlowMaterial");
    m_apkDescs[18]->SetConfigurableMaterial(false);
    m_apkDescs[18]->SetBonesPerPartition(60);

    m_apkDescs[19] = NiNew NiShaderDesc();
    m_apkDescs[19]->SetName("MS2CharacterDepthMaterial");
    m_apkDescs[19]->SetConfigurableMaterial(false);
    m_apkDescs[19]->SetBonesPerPartition(60);

    m_apkDescs[20] = NiNew NiShaderDesc();
    m_apkDescs[20]->SetName("MS2TextureDensityMaterial");
    m_apkDescs[20]->SetConfigurableMaterial(false);
    m_apkDescs[20]->SetBonesPerPartition(60);

    m_apkDescs[21] = NiNew NiShaderDesc();
    m_apkDescs[21]->SetName("MS2AlphaBoostMaterial");
    m_apkDescs[21]->SetConfigurableMaterial(false);

    CreateCharacterDesc(m_apkDescs[22]);
    m_apkDescs[22]->SetName("MS2CharacterHairMaterial");
    m_apkDescs[22]->SetDescription("Material that includes rim light and uses half-lambert equation in diffuse factor. "
        "Anisotropic lighting for hair rendering is added.");

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("HairTangentMap");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Texture(1, NULL);
    m_apkDescs[22]->AddAttribute(pkAttrib);

    m_apkDescs[23] = NiNew NiShaderDesc();
    m_apkDescs[23]->SetName("MS2BlendLightMaterial");
    m_apkDescs[23]->SetConfigurableMaterial(true);
    m_apkDescs[23]->SetBonesPerPartition(30);
    m_apkDescs[23]->SetDescription("Material that includes a light map and three blend maps.");

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("LightMap");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Texture(0, "DefaultLightMap.tga");
    m_apkDescs[23]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("MapAttribute");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_STRING);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_String("");
    m_apkDescs[23]->AddAttribute(pkAttrib);

    for (int i = 1; i <= 3; i++)
    {
        pkAttrib = NiNew NiShaderAttributeDesc();
        NiString kName;
        kName.Format("BlendMap%d", i);
        pkAttrib->SetName(kName);
        pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
        pkAttrib->SetHidden(false);
        pkAttrib->SetValue_Texture(i, NULL);
        m_apkDescs[23]->AddAttribute(pkAttrib);
    }

    AddStandardTextureAttributes(m_apkDescs[23]);

    CreateCharacterDesc(m_apkDescs[24]);
    m_apkDescs[24]->SetName("MS2ChaosMaterial");
    m_apkDescs[24]->SetConfigurableMaterial(false);
    m_apkDescs[24]->SetDescription("MS2ChaosMaterial dims original texture colors and then adds emission of rim light.");

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ChaosFresnelBoost");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(26.09f);
    m_apkDescs[24]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ChaosFresnelExponent");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(5.36f);
    m_apkDescs[24]->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ChaosDimmer");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(0.1f);
    m_apkDescs[24]->AddAttribute(pkAttrib);

    NiColor kChaosLightColor(0.95f, 0.57f, 0.22f);
    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ChaosLightColor");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kChaosLightColor);
    m_apkDescs[24]->AddAttribute(pkAttrib);

    m_apkDescs[25] = NiNew NiShaderDesc();
    m_apkDescs[25]->SetName("MS2ChaosSkinMaterial");
    m_apkDescs[25]->SetConfigurableMaterial(false);

    m_apkDescs[26] = NiNew NiShaderDesc();
    m_apkDescs[26]->SetName("MS2ChaosHairMaterial");
    m_apkDescs[26]->SetConfigurableMaterial(false);

    m_apkDescs[27] = NiNew NiShaderDesc();
    m_apkDescs[27]->SetName("SoftParticlesMaterial");
    m_apkDescs[27]->SetConfigurableMaterial(false);
    m_apkDescs[27]->SetDescription("Material for soft particles.");

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("SoftDepth");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(400.0f);
    m_apkDescs[27]->AddAttribute(pkAttrib);

    m_apkDescs[28] = NiNew NiShaderDesc();
    m_apkDescs[28]->SetName("MS2ForceColorMaterial");
    m_apkDescs[28]->SetConfigurableMaterial(false);

    m_apkDescs[29] = NiNew NiShaderDesc();
    m_apkDescs[29]->SetName("MS2UIMaterial");
    m_apkDescs[29]->SetConfigurableMaterial(false);
}

//--------------------------------------------------------------------------------------------------
// @0x142768670
MS2MaterialLibrary::~MS2MaterialLibrary()
{
    for (unsigned int i = 0; i < MATERIAL_COUNT; i++)
        NiDelete m_apkDescs[i];
}

//--------------------------------------------------------------------------------------------------
// @0x142768910
void MS2MaterialLibrary::AddTextureAttribute(NiShaderDesc* pkDesc, const char* pcName, const char* pcDefault,
    unsigned int uiIndex)
{
    NiShaderAttributeDesc* pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName(pcName);
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
    pkAttrib->SetHidden(true);
    pkAttrib->SetValue_Texture(uiIndex, pcDefault);
    pkDesc->AddAttribute(pkAttrib);
}
MS2_REPLACE(0x142768910, MS2MaterialLibrary::AddTextureAttribute, 178, 0xE96E9EA1);

//--------------------------------------------------------------------------------------------------
// @0x1427689d0
void MS2MaterialLibrary::AddStandardTextureAttributes(NiShaderDesc* pkDesc)
{
    AddTextureAttribute(pkDesc, "BaseMap", "base", 0);
    AddTextureAttribute(pkDesc, "DarkMap", "dark", 0);
    AddTextureAttribute(pkDesc, "DetailMap", "detail", 0);
    AddTextureAttribute(pkDesc, "GlossMap", "gloss", 0);
    AddTextureAttribute(pkDesc, "GlowMap", "glow", 0);
    AddTextureAttribute(pkDesc, "BumpMap", "bump", 0);
    AddTextureAttribute(pkDesc, "NormalMap", "normal", 0);
    AddTextureAttribute(pkDesc, "ParallaxMap", "parallax", 0);

    for (unsigned int i = 0; i < 3; i++)
    {
        char acName[32];
        efd::Sprintf(acName, 32, "DecalMap%d", i);
        AddTextureAttribute(pkDesc, acName, "decal", i);
    }
}
MS2_REPLACE(0x1427689D0, MS2MaterialLibrary::AddStandardTextureAttributes, 1174, 0xFB4A8A0C);

//--------------------------------------------------------------------------------------------------
// @0x142768e70
MS2MaterialLibrary* MS2MaterialLibrary::Create()
{
    if (!ms_pkThis)
        ms_pkThis = NiNew MS2MaterialLibrary();
    return ms_pkThis;
}

//--------------------------------------------------------------------------------------------------
// @0x142768ed0
void MS2MaterialLibrary::CreateCharacterDesc(NiShaderDesc*& pkDesc)
{
    NiColor kRed(1.0f, 0.0f, 0.0f);
    NiColor kGreen(0.0f, 1.0f, 0.0f);
    NiColor kBlue(0.0f, 0.0f, 1.0f);

    pkDesc = NiNew NiShaderDesc();
    pkDesc->SetConfigurableMaterial(true);
    pkDesc->SetBonesPerPartition(60);

    NiShaderAttributeDesc* pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("FresnelBoost");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(5.0f);
    pkDesc->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("FresnelExponent");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Float(4.0f);
    pkDesc->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ColorOverrideMap");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Texture(0, NULL);
    pkDesc->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OverrideColor0");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kRed);
    pkDesc->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OverrideColor1");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kGreen);
    pkDesc->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("OverrideColor2");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
    pkAttrib->SetHidden(false);
    pkAttrib->SetValue_Color(kBlue);
    pkDesc->AddAttribute(pkAttrib);

    pkAttrib = NiNew NiShaderAttributeDesc();
    pkAttrib->SetName("ColorBoost");
    pkAttrib->SetType(NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
    pkAttrib->SetHidden(true);
    pkAttrib->SetValue_Float(1.0f);
    pkDesc->AddAttribute(pkAttrib);
}
MS2_REPLACE(0x142768ED0, MS2MaterialLibrary::CreateCharacterDesc, 950, 0xEAAF9075);

//--------------------------------------------------------------------------------------------------
// @0x142769360
NiShaderDesc* MS2MaterialLibrary::GetFirstMaterialDesc()
{
    ms_uiCurrentDesc = 0;
    return ms_pkThis->m_apkDescs[0];
}

//--------------------------------------------------------------------------------------------------
// @0x142769380
NiMaterial* MS2MaterialLibrary::CreateMaterial(const NiFixedString& kName)
{
    if (kName == "MS2DirectionalShadowWriteMaterial")
        return NiNew MS2DirectionalShadowWriteMaterial(true);
    else if (kName == "MS2PointShadowWriteMaterial")
        return NiNew MS2PointShadowWriteMaterial(true);
    else if (kName == "MS2SpotShadowWriteMaterial")
        return NiNew MS2SpotShadowWriteMaterial(true);
    else if (kName == "CustomizedTextureGeneratorMaterial")
        return NiNew CustomizedTextureGeneratorMaterial(true);
    else if (kName == "TexCoordWriteMaterial")
        return NiNew TexCoordWriteMaterial(true);
    else if (kName == "OutlineMaterial")
        return NiNew OutlineMaterial(true);
    else if (kName == "MRTShaderPickerMaterial")
        return NiNew MRTShaderPickerMaterial(true);
    else if (kName == "MS2MotionBlurMaterial")
        return NiNew MS2MotionBlurMaterial(true);
    else if (kName == "MS2OuterGlowCharacterMaterial")
        return NiNew MS2OuterGlowCharacterMaterial(true);
    else if (kName == "MS2DepthMaterial")
        return NiNew MS2DepthMaterial(true);
    else if (kName == "MS2CharacterDepthMaterial")
        return NiNew MS2CharacterDepthMaterial(true);
    else if (kName == "MS2DefaultShimmerValueMaterial")
        return NiNew MS2DefaultShimmerValueMaterial(true);
    else if (kName == "MS2ShimmerMaterial")
        return NiNew MS2ShimmerMaterial(true);
    else if (kName == "MS2GlassMaterial")
        return NiNew MS2GlassMaterial(true);
    else if (kName == "MS2DecorationMaterial")
        return NiNew MS2DecorationMaterial(true);
    else if (kName == "MS2GlowMaterial")
        return NiNew MS2GlowMaterial(true);
    else if (kName == "MS2TextureDensityMaterial")
        return NiNew MS2TextureDensityMaterial(true);
    else if (kName == "MS2ForceColorMaterial")
        return NiNew MS2ForceColorMaterial(true);
    else if (kName == "SoftParticlesMaterial")
        return NiNew SoftParticlesMaterial(true);
    else if (kName == "MS2UIMaterial")
        return NiNew MS2UIMaterial(true);

    const char* apcStandardNames[] =
    {
        "MS2StandardMaterial",
        "MS2CharacterMaterial",
        "MS2CharacterSkinMaterial",
        "MS2CharacterHairMaterial",
        "MS2AlphaBoostMaterial",
        "MS2ChaosMaterial",
        "MS2ChaosSkinMaterial",
        "MS2ChaosHairMaterial",
    };
    for (unsigned int i = 0; i < 8; i++)
    {
        if (kName == apcStandardNames[i])
            return NiNew MS2StandardMaterial(kName, true);
    }

    return NULL;
}
MS2_REPLACE_METHOD(0x142769380, MS2MaterialLibrary, CreateMaterial, 1686, 0x398B2601);

//--------------------------------------------------------------------------------------------------
// @0x142769a20
NiMaterial* MS2MaterialLibrary::GetMaterial(const NiFixedString& kName)
{
    NiMaterialPtr spMaterial;
    m_kMaterials.GetAt(kName, spMaterial);
    if (spMaterial)
        return spMaterial;

    spMaterial = CreateMaterial(kName);
    m_kMaterials.SetAt(kName, spMaterial);
    return spMaterial;
}
MS2_REPLACE_METHOD(0x142769A20, MS2MaterialLibrary, GetMaterial, 567, 0x018596CA);

//--------------------------------------------------------------------------------------------------
// @0x142769c60
unsigned int MS2MaterialLibrary::GetMaterialCount() const
{
    return MATERIAL_COUNT;
}
MS2_REPLACE_METHOD(0x142769C60, MS2MaterialLibrary, GetMaterialCount, 6, 0xC00D3B9E);

//--------------------------------------------------------------------------------------------------
// @0x142769c70
const char* MS2MaterialLibrary::GetMaterialName(unsigned int ui)
{
    return m_apkDescs[ui]->GetName();
}
MS2_REPLACE_METHOD(0x142769C70, MS2MaterialLibrary, GetMaterialName, 14, 0xFB092BBF);

//--------------------------------------------------------------------------------------------------
// @0x142769c80
NiShaderDesc* MS2MaterialLibrary::GetNextMaterialDesc()
{
    ms_uiCurrentDesc++;
    if (ms_uiCurrentDesc == MATERIAL_COUNT)
        return NULL;
    return ms_pkThis->m_apkDescs[ms_uiCurrentDesc];
}

//--------------------------------------------------------------------------------------------------
// @0x142769e40
// MS2MaterialSDM::Init calls this entry point to create the MS2MaterialLibrary singleton.
void MS2MaterialLibrary::InitFromSDM()
{
    Create();
}

//--------------------------------------------------------------------------------------------------
// @0x142769ea0
void MS2MaterialLibrary::_SDMShutdown()
{
    NiDelete ms_pkThis;
    ms_pkThis = NULL;
}

// MS2-PIN: ??_7?$NiTFixedStringMapBase@V?$DFALL@V?$SmartPointer@VNiMaterial@@@efd@@@@V?$SmartPointer@VNiMaterial@@@efd@@@@6B@ 0x1431d0c08
// MS2-PIN: ??_7?$NiTFixedStringMap@V?$SmartPointer@VNiMaterial@@@efd@@@@6B@ 0x1431d0c20
// MS2-PIN: ??_7MS2MaterialLibrary@@6B@ 0x1431d0c38
// MS2-PIN: ?DeleteItem@?$NiTFixedStringMap@V?$SmartPointer@VNiMaterial@@@efd@@@@UEAAXPEAV?$NiTMapItem@VNiFixedString@@V?$SmartPointer@VNiMaterial@@@efd@@@@@Z 0x142769290
