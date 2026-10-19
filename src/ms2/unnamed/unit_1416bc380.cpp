// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The render name tables: the material registry
// (std::map<std::string, NiMaterialPtr> filled from the MS2 material name keys), the global shader-constant names, the
// per-part dummy node names ("<part>NN", "Hold_PointNN") and the header statics this TU picks up (part names, UGC sort
// names, CAtlMap<unsigned, CString>). The name keys are shared NiFixedString globals: the ones this TU constructs are
// defined here, the rest are constructed by other TUs and referenced as DAT_ externs. All function names are invented.
// MS2-UNIT: unit_1416bc380
// MS2-RANGE: 0x1400fd610-0x1400fd830 .text$di
// MS2-RANGE: 0x1400fda40-0x1400fda80 .text$di
// MS2-RANGE: 0x1400fe1a0-0x1400fe440 .text$di
// MS2-RANGE: 0x1416bc380-0x1416c1cc0 .text$mn
// MS2-RANGE: 0x142cb4f00-0x142cb5080 .text$yd
// MS2-RANGE: 0x142cb51e0-0x142cb5210 .text$yd
// MS2-RANGE: 0x142cb56d0-0x142cb57b0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <map>
#include <string>
#include <utility>
#include <NiFixedString.h>
#include <NiMaterial.h>
#include "ms2/ms2recover.h"

// Name keys constructed by other TUs.
extern NiFixedString DAT_143ae51e0; // "NiStandardMaterial"
extern NiFixedString DAT_143ae51e8; // "MS2StandardMaterial"
extern NiFixedString DAT_143ae51f8; // "MS2CharacterMaterial"
extern NiFixedString DAT_143ae5200; // "MS2CharacterSkinMaterial"
extern NiFixedString DAT_143ae5208; // "MS2CharacterHairMaterial"
extern NiFixedString DAT_143ae5210; // "MS2ForceColorMaterial"
extern NiFixedString DAT_143ae5218; // "MS2TextureDensityMaterial"
extern NiFixedString DAT_143ae5220; // "MS2DepthMaterial"
extern NiFixedString DAT_143ae5228; // "MS2CharacterDepthMaterial"
extern NiFixedString DAT_143ae5230; // "MS2AlphaBoostMaterial"
extern NiFixedString DAT_143ae5238; // "MS2BlendLightMaterial"
extern NiFixedString DAT_143ae5240; // "MS2ChaosMaterial"
extern NiFixedString DAT_143ae5248; // "MS2ChaosSkinMaterial"
extern NiFixedString DAT_143ae5250; // "MS2ChaosHairMaterial"
extern NiFixedString DAT_143ae5258; // "SoftParticlesMaterial"
extern NiFixedString DAT_143ae5260; // "MS2MotionBlurMaterial"
extern NiFixedString DAT_143ae5268; // "MS2OuterGlowCharacterMaterial"
extern NiFixedString DAT_143ae5270; // "MS2CharacterMonochromeMaterial"
extern NiFixedString DAT_143ae5278; // "MS2DecorationMaterial"
extern NiFixedString DAT_143ae5280; // "TexCoordWriteMaterial"
extern NiFixedString DAT_143ae5288; // "MRTShaderPickerMaterial"
extern NiFixedString DAT_143ae5290; // "MS2DirectionalShadowWriteMaterial"
extern NiFixedString DAT_143ae5298; // "MS2PointShadowWriteMaterial"
extern NiFixedString DAT_143ae52a0; // "MS2SpotShadowWriteMaterial"
extern NiFixedString DAT_143ae52a8; // "OutlineMaterial"
extern NiFixedString DAT_143ae52b0; // "MS2DefaultShimmerValueMaterial"
extern NiFixedString DAT_143ae52b8; // "MS2ShimmerMaterial"
extern NiFixedString DAT_143ae52c0; // "MS2IceMaterial"
extern NiFixedString DAT_143ae52c8; // "MS2FireMaterial"
extern NiFixedString DAT_143ae52d0; // "MS2PoisonMaterial"
extern NiFixedString DAT_143ae52d8; // "MS2DarkMaterial"
extern NiFixedString DAT_143ae52e0; // "MS2UIMaterial"
extern NiFixedString DAT_143ae52f8; // "gbHeightFogEnable"
extern NiFixedString DAT_143ae5300; // "gkHeightFogColor"
extern NiFixedString DAT_143ae5308; // "gfHeightFogUpperZ"
extern NiFixedString DAT_143ae5310; // "gfHeightFogLowerZ"
extern NiFixedString DAT_143ae5318; // "gfHeightFogPercent"
extern NiFixedString DAT_143ae5320; // "gakFadeInOutRenderStepPercent"
extern NiFixedString DAT_143ae5328; // "g_vTexelSize"
extern NiFixedString DAT_143ae5340; // "gakScreenMaskingRenderStepBlend"
extern NiFixedString DAT_143ae5348; // "gkOuterColor"
extern NiFixedString DAT_143ae5350; // "gakMonochromeLevel"
extern NiFixedString DAT_143ae5358; // "gfBrightPassThreshold"
extern NiFixedString DAT_143ae5360; // "gfBrightPassOffset"
extern NiFixedString DAT_143ae5368; // "gfMiddleGray"
extern NiFixedString DAT_143ae5370; // "gfBloomScale"
extern NiFixedString DAT_143ae5378; // "gfGlowScale"
extern NiFixedString DAT_143ae5380; // "gakFogBias"
extern NiFixedString DAT_143ae5388; // "gakRimLightDirection"
extern NiFixedString DAT_143ae5390; // "gakCharacterLightDirection"
extern NiFixedString DAT_143ae5398; // "gakSSSColor"
extern NiFixedString DAT_143ae53a8; // "gfStrength"
extern NiFixedString DAT_143ae53b0; // "gfRange"
extern NiFixedString DAT_143ae53b8; // "gfNearZ"
extern NiFixedString DAT_143ae53c0; // "gfEnableShimmerRender"
extern NiFixedString DAT_143ae53c8; // "g_kOutlineColors"
extern NiFixedString DAT_143ae53d0; // "g_vColorPerspectiveRange"
extern NiFixedString DAT_143ae53e0; // "gakNormalSampleOffsets"
extern NiFixedString DAT_143ae53e8; // "gakSampleOffsets"
extern NiFixedString DAT_143ae53f0; // "gakSampleWeights"
extern NiFixedString DAT_143ae53f8; // "mViewProjectionLast"
extern NiFixedString DAT_143ae5400; // "gfElapsedTime"
extern NiFixedString DAT_143ae5408; // "gfNearToFarDistance"
extern NiFixedString DAT_143ae5410; // "gfEdgeSmoothDepthWeight"
extern NiFixedString DAT_143ae5418; // "gfEdgeSmoothNormalWeight"
extern NiFixedString DAT_143ae5420; // "gfAdaptationScale"
extern NiFixedString DAT_143ae5440; // "g_fShimmerBrightness"
extern NiFixedString DAT_143ae5450; // "PixelBlurConst"
extern NiFixedString DAT_143ae5458; // "sampleDist"
extern NiFixedString DAT_143ae5460; // "gfGaussianValueX"
extern NiFixedString DAT_143ae5468; // "gfGaussianValueY"

// ---- statics of this TU, in definition order (.text$di) ----

// @0x1400fd610
static NiFixedString s_k_gkShadowAdjust;
// @0x1400fd640
static NiFixedString s_k_gkSSSPower;
// @0x1400fd670
static NiFixedString s_k_MS2GlowMaterial;
// @0x1400fd6a0
static NiFixedString s_k_GlowModifier;
// @0x1400fd6d0
static NiFixedString s_akPartDummyNames[9][30];         // "<part>NN" (s_partNames x 30)
// @0x1400fd710
static NiFixedString s_k_gvSSAOParams;
// @0x1400fd740
static NiFixedString s_k_g_afBlurOffsetU;
// @0x1400fd770
static NiFixedString s_k_g_afBlurOffsetV;
// @0x1400fd7a0
static NiFixedString s_k_g_fPerturbationMultiplier;
// @0x1400fd7d0
static NiFixedString s_k_g_fPostPerturbationMultiplier;
// @0x1400fd800
static NiFixedString s_k_g_fPostShimmerMove;

// @0x1400fda40
static NiFixedString s_akHoldPointNames[50];            // "Hold_PointNN"

// @0x1400fe1a0
static std::map<std::string, NiMaterialPtr> s_kMaterials;

// Header statics.
// @0x1400fe1d0
static CString s_partNames[] = {"Head", "Body", "Back", "RHand", "LHand", "RFoot", "LFoot", "Tail", "Hold_Point"};
// @0x1400fe2b0
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400fe370
static CString s_strSkill("skill");
// @0x1400fe3a0
static CString s_strStun("stun");

// Stand-in for the unrecovered class constructed by 0x1401cd100 (one pointer, null).
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
// @0x1400fe3d0
static Unk_1401cd100 s_pointer(NULL);
// @0x1400fe3f0
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

// ---- functions ----

// Empties the material registry and the material name keys.
// @0x1416bc380
void ResetMaterialNames()
{
    s_kMaterials.clear();
    DAT_143ae51e0 = NiFixedString();
    DAT_143ae51e8 = NiFixedString();
    DAT_143ae51f8 = NiFixedString();
    DAT_143ae5200 = NiFixedString();
    DAT_143ae5208 = NiFixedString();
    DAT_143ae5210 = NiFixedString();
    DAT_143ae5218 = NiFixedString();
    DAT_143ae5220 = NiFixedString();
    DAT_143ae5228 = NiFixedString();
    DAT_143ae5230 = NiFixedString();
    DAT_143ae5238 = NiFixedString();
    DAT_143ae5240 = NiFixedString();
    DAT_143ae5248 = NiFixedString();
    DAT_143ae5250 = NiFixedString();
    DAT_143ae5258 = NiFixedString();
    s_k_MS2GlowMaterial = NiFixedString();
    DAT_143ae52e0 = NiFixedString();
    DAT_143ae5260 = NiFixedString();
    DAT_143ae5268 = NiFixedString();
    DAT_143ae5270 = NiFixedString();
    DAT_143ae5278 = NiFixedString();
    DAT_143ae5280 = NiFixedString();
    DAT_143ae5288 = NiFixedString();
    DAT_143ae5290 = NiFixedString();
    DAT_143ae5298 = NiFixedString();
    DAT_143ae52a0 = NiFixedString();
    DAT_143ae52a8 = NiFixedString();
    DAT_143ae52b0 = NiFixedString();
    DAT_143ae52b8 = NiFixedString();
    DAT_143ae52c0 = NiFixedString();
    DAT_143ae52c8 = NiFixedString();
    DAT_143ae52d0 = NiFixedString();
    DAT_143ae52d8 = NiFixedString();
}

#define MS2_REGISTER_MATERIAL(kName) \
    pkMaterial = NiMaterial::GetMaterial(kName); \
    if (pkMaterial != NULL && bRegister) \
        s_kMaterials.insert(std::make_pair(std::string((const char*)kName), pkMaterial));

// Looks every material name up in the material library and records the found ones.
// @0x1416bcc90
void RegisterMaterials(bool bRegister)
{
    NiMaterial* pkMaterial = NULL;
    MS2_REGISTER_MATERIAL(DAT_143ae51e0);
    MS2_REGISTER_MATERIAL(DAT_143ae51e8);
    MS2_REGISTER_MATERIAL(DAT_143ae51f8);
    MS2_REGISTER_MATERIAL(DAT_143ae5200);
    MS2_REGISTER_MATERIAL(DAT_143ae5208);
    MS2_REGISTER_MATERIAL(DAT_143ae5210);
    MS2_REGISTER_MATERIAL(DAT_143ae5218);
    MS2_REGISTER_MATERIAL(DAT_143ae5220);
    MS2_REGISTER_MATERIAL(DAT_143ae5228);
    MS2_REGISTER_MATERIAL(DAT_143ae5230);
    MS2_REGISTER_MATERIAL(DAT_143ae5238);
    MS2_REGISTER_MATERIAL(DAT_143ae5240);
    MS2_REGISTER_MATERIAL(DAT_143ae5248);
    MS2_REGISTER_MATERIAL(DAT_143ae5250);
    MS2_REGISTER_MATERIAL(DAT_143ae5258);
    MS2_REGISTER_MATERIAL(s_k_MS2GlowMaterial);
    MS2_REGISTER_MATERIAL(DAT_143ae52e0);
    MS2_REGISTER_MATERIAL(DAT_143ae5260);
    MS2_REGISTER_MATERIAL(DAT_143ae5268);
    MS2_REGISTER_MATERIAL(DAT_143ae5270);
    MS2_REGISTER_MATERIAL(DAT_143ae5278);
    MS2_REGISTER_MATERIAL(DAT_143ae5280);
    MS2_REGISTER_MATERIAL(DAT_143ae5288);
    MS2_REGISTER_MATERIAL(DAT_143ae5290);
    MS2_REGISTER_MATERIAL(DAT_143ae5298);
    MS2_REGISTER_MATERIAL(DAT_143ae52a0);
    MS2_REGISTER_MATERIAL(DAT_143ae52a8);
    MS2_REGISTER_MATERIAL(DAT_143ae52b0);
    MS2_REGISTER_MATERIAL(DAT_143ae52b8);
    MS2_REGISTER_MATERIAL(DAT_143ae52c0);
    MS2_REGISTER_MATERIAL(DAT_143ae52c8);
    MS2_REGISTER_MATERIAL(DAT_143ae52d0);
    MS2_REGISTER_MATERIAL(DAT_143ae52d8);
}

#undef MS2_REGISTER_MATERIAL

// @0x1416be6d0
void InitShaderConstantNames()
{
    DAT_143ae52f8 = "gbHeightFogEnable";
    DAT_143ae5300 = "gkHeightFogColor";
    DAT_143ae5308 = "gfHeightFogUpperZ";
    DAT_143ae5310 = "gfHeightFogLowerZ";
    DAT_143ae5318 = "gfHeightFogPercent";
    DAT_143ae5320 = "gakFadeInOutRenderStepPercent";
    DAT_143ae5328 = "g_vTexelSize";
    s_k_g_afBlurOffsetU = "g_afBlurOffsetU";
    s_k_g_afBlurOffsetV = "g_afBlurOffsetV";
    DAT_143ae5340 = "gakScreenMaskingRenderStepBlend";
    DAT_143ae5348 = "gkOuterColor";
    DAT_143ae5350 = "gakMonochromeLevel";
    DAT_143ae5358 = "gfBrightPassThreshold";
    DAT_143ae5360 = "gfBrightPassOffset";
    DAT_143ae5368 = "gfMiddleGray";
    DAT_143ae5370 = "gfBloomScale";
    DAT_143ae5378 = "gfGlowScale";
    DAT_143ae5380 = "gakFogBias";
    DAT_143ae5388 = "gakRimLightDirection";
    DAT_143ae5390 = "gakCharacterLightDirection";
    DAT_143ae5398 = "gakSSSColor";
    s_k_gkSSSPower = "gkSSSPower";
    DAT_143ae53a8 = "gfStrength";
    DAT_143ae53b0 = "gfRange";
    DAT_143ae53b8 = "gfNearZ";
    DAT_143ae53c0 = "gfEnableShimmerRender";
    DAT_143ae53c8 = "g_kOutlineColors";
    DAT_143ae53d0 = "g_vColorPerspectiveRange";
    s_k_gkShadowAdjust = "gkShadowAdjust";
    DAT_143ae53e0 = "gakNormalSampleOffsets";
    DAT_143ae53e8 = "gakSampleOffsets";
    DAT_143ae53f0 = "gakSampleWeights";
    DAT_143ae53f8 = "mViewProjectionLast";
    DAT_143ae5400 = "gfElapsedTime";
    DAT_143ae5408 = "gfNearToFarDistance";
    DAT_143ae5410 = "gfEdgeSmoothDepthWeight";
    DAT_143ae5418 = "gfEdgeSmoothNormalWeight";
    DAT_143ae5420 = "gfAdaptationScale";
    s_k_gvSSAOParams = "gvSSAOParams";
    s_k_g_fPerturbationMultiplier = "g_fPerturbationMultiplier";
    s_k_g_fPostPerturbationMultiplier = "g_fPostPerturbationMultiplier";
    s_k_g_fPostShimmerMove = "g_fPostShimmerMove";
    DAT_143ae5440 = "g_fShimmerBrightness";
    DAT_143ae5450 = "PixelBlurConst";
    DAT_143ae5458 = "sampleDist";
    DAT_143ae5460 = "gfGaussianValueX";
    DAT_143ae5468 = "gfGaussianValueY";
}

// @0x1416bea60
void ResetShaderConstantNames()
{
    DAT_143ae52f8 = NiFixedString();
    DAT_143ae5300 = NiFixedString();
    DAT_143ae5308 = NiFixedString();
    DAT_143ae5310 = NiFixedString();
    DAT_143ae5318 = NiFixedString();
    DAT_143ae5320 = NiFixedString();
    DAT_143ae5328 = NiFixedString();
    s_k_g_afBlurOffsetU = NiFixedString();
    s_k_g_afBlurOffsetV = NiFixedString();
    DAT_143ae5340 = NiFixedString();
    DAT_143ae5348 = NiFixedString();
    DAT_143ae5350 = NiFixedString();
    DAT_143ae5358 = NiFixedString();
    DAT_143ae5360 = NiFixedString();
    DAT_143ae5368 = NiFixedString();
    DAT_143ae5370 = NiFixedString();
    DAT_143ae5378 = NiFixedString();
    DAT_143ae5380 = NiFixedString();
    DAT_143ae5388 = NiFixedString();
    DAT_143ae5390 = NiFixedString();
    DAT_143ae5398 = NiFixedString();
    s_k_gkSSSPower = NiFixedString();
    DAT_143ae53a8 = NiFixedString();
    DAT_143ae53b0 = NiFixedString();
    DAT_143ae53b8 = NiFixedString();
    DAT_143ae53c0 = NiFixedString();
    DAT_143ae53c8 = NiFixedString();
    DAT_143ae53d0 = NiFixedString();
    s_k_gkShadowAdjust = NiFixedString();
    DAT_143ae53e0 = NiFixedString();
    DAT_143ae53e8 = NiFixedString();
    DAT_143ae53f0 = NiFixedString();
    DAT_143ae53f8 = NiFixedString();
    DAT_143ae5400 = NiFixedString();
    DAT_143ae5408 = NiFixedString();
    DAT_143ae5410 = NiFixedString();
    DAT_143ae5418 = NiFixedString();
    DAT_143ae5420 = NiFixedString();
    s_k_gvSSAOParams = NiFixedString();
    s_k_g_fPerturbationMultiplier = NiFixedString();
    s_k_g_fPostPerturbationMultiplier = NiFixedString();
    s_k_g_fPostShimmerMove = NiFixedString();
    DAT_143ae5440 = NiFixedString();
    DAT_143ae5450 = NiFixedString();
    DAT_143ae5458 = NiFixedString();
    DAT_143ae5460 = NiFixedString();
    DAT_143ae5468 = NiFixedString();
}

// @0x1416bf750
void InitDummyNames()
{
    for (unsigned int i = 0; i < 9; i++)
    {
        for (unsigned int j = 0; j < 30; j++)
        {
            CString strName;
            strName.Format("%s%02d", (const char*)s_partNames[i], j);
            s_akPartDummyNames[i][j] = (const char*)strName;
        }
    }
    for (unsigned int i = 0; i < 50; i++)
    {
        CString strName;
        strName.Format("Hold_Point%02d", i);
        s_akHoldPointNames[i] = (const char*)strName;
    }
}

// @0x1416bf8a0
void ResetDummyNames()
{
    for (unsigned int i = 0; i < 9; i++)
    {
        for (unsigned int j = 0; j < 30; j++)
            s_akPartDummyNames[i][j] = NiFixedString();
    }
    for (unsigned int i = 0; i < 50; i++)
        s_akHoldPointNames[i] = NiFixedString();
}
