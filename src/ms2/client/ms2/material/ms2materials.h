// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2's NiFragmentMaterial classes (built with /GR-, so the
// class names come from the material name strings MS2MaterialLibrary::CreateMaterial dispatches on). Almost all derive
// from MS2StandardMaterial, which adds MS2MaterialNodeLibrary to the standard library and a set of new virtual Handle*
// steps; the shadow-write materials derive from the stock Gamebryo shadow-write materials instead.
#pragma once

#include <NiStandardMaterial.h>
#include <NiDirectionalShadowWriteMaterial.h>
#include <NiPointShadowWriteMaterial.h>
#include <NiSpotShadowWriteMaterial.h>

//--------------------------------------------------------------------------------------------------
class MS2StandardMaterial : public NiStandardMaterial
{
public:
    MS2StandardMaterial(const NiFixedString& kName, bool bAutoCreateCaches);

protected:
    MS2StandardMaterial(const NiFixedString& kName, const NiFixedString& kTypeName, unsigned int uiVersionOffset,
        bool bAutoCreateCaches);

    int m_eMaterialType;            // +0x540 0 standard, 1 character, 2 skin, 3 hair, 4 other
    bool m_bCharacterLighting;      // +0x544
    bool m_bAlphaBoost;             // +0x545
    bool m_bChaos;                  // +0x546
    void* m_pvUnk548;               // +0x548
};

//--------------------------------------------------------------------------------------------------
class MS2DirectionalShadowWriteMaterial : public NiDirectionalShadowWriteMaterial
{
public:
    MS2DirectionalShadowWriteMaterial(bool bAutoCreateCaches);
};

class MS2PointShadowWriteMaterial : public NiPointShadowWriteMaterial
{
public:
    MS2PointShadowWriteMaterial(bool bAutoCreateCaches);
};

class MS2SpotShadowWriteMaterial : public NiSpotShadowWriteMaterial
{
public:
    MS2SpotShadowWriteMaterial(bool bAutoCreateCaches);
};

//--------------------------------------------------------------------------------------------------
class SoftParticlesMaterial : public NiStandardMaterial
{
public:
    SoftParticlesMaterial(bool bAutoCreateCaches);
};

//--------------------------------------------------------------------------------------------------
#define MS2_DECLARE_STANDARD_MATERIAL(classname)                                                    \
    class classname : public MS2StandardMaterial                                                    \
    {                                                                                               \
    public:                                                                                         \
        classname(bool bAutoCreateCaches);                                                          \
    }

MS2_DECLARE_STANDARD_MATERIAL(CustomizedTextureGeneratorMaterial);
MS2_DECLARE_STANDARD_MATERIAL(TexCoordWriteMaterial);
MS2_DECLARE_STANDARD_MATERIAL(OutlineMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MRTShaderPickerMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2MotionBlurMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2OuterGlowCharacterMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2DepthMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2DefaultShimmerValueMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2ShimmerMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2GlassMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2DecorationMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2GlowMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2TextureDensityMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2ForceColorMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2UIMaterial);

class MS2CharacterDepthMaterial : public MS2DepthMaterial
{
public:
    MS2CharacterDepthMaterial(bool bAutoCreateCaches);
};
