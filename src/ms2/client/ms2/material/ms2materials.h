// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2's NiFragmentMaterial classes (built with /GR-, so the
// class names come from the material name strings MS2MaterialLibrary::CreateMaterial dispatches on). Almost all derive
// from MS2StandardMaterial, which adds MS2MaterialNodeLibrary to the standard library and a set of new virtual Handle*
// steps; the shadow-write materials derive from the stock Gamebryo shadow-write materials instead.
#pragma once

#include <NiStandardMaterial.h>
#include <NiDirectionalShadowWriteMaterial.h>
#include <NiPointShadowWriteMaterial.h>
#include <NiSpotShadowWriteMaterial.h>
#include <NiShaderConstantMap.h>

//--------------------------------------------------------------------------------------------------
// Vtable 0x1431c5b30 (sizeof 0x550). Overrides the descriptor/packing steps and a dozen standard Handle* steps, then adds
// 18 new virtuals (+0x308..+0x390) for the MS2 lighting model (half-lambert/skin/hair lights, rim light), the colour
// override (dye) and decal maps of characters, screen-projected env maps, colour boost and the chaos rim.
class MS2StandardMaterial : public NiStandardMaterial
{
    NiDeclareRTTI;

public:
    MS2StandardMaterial(const NiFixedString& kName, bool bAutoCreateCaches);

    // "MS2StandardMaterial" 0, "MS2CharacterMaterial" 1, "MS2CharacterSkinMaterial" 2, "MS2CharacterHairMaterial" 3,
    // anything else 4.
    static int GetMaterialType(const NiFixedString& kName);
    bool IsCharacterMaterial() const;

    virtual bool SetupPackingRequirements(NiShader* pkShader, NiMaterialDescriptor* pkMaterialDescriptor,
        RenderPassDescriptor* pkRenderPasses, unsigned int uiCount);
    virtual bool GenerateDescriptor(const NiRenderObject* pkGeometry, const NiPropertyState* pkState,
        const NiDynamicEffectState* pkEffects, NiMaterialDescriptor& kMaterialDesc);
    virtual bool GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual ReturnCode GenerateShaderDescArray(NiMaterialDescriptor* pkMaterialDescriptor,
        RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount, unsigned int& uiCountAdded);

protected:
    MS2StandardMaterial(const NiFixedString& kName, const NiFixedString& kTypeName, unsigned int uiVersionOffset,
        bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
public:

    void Init(const NiFixedString& kName);

    virtual bool HandlePositionFragment(Context& kContext, TransformType eTransType,
        NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix);
    virtual bool HandleCalculateFog(Context& kContext, NiMaterialResource* pkViewPos, Fog eFogType);
    virtual bool HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
        NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos);
    virtual bool HandleVertexLightingAndMaterials(Context& kContext, NiStandardVertexProgramDescriptor* pkVertexDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldView);
    virtual bool HandlePixelUVSets(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
        NiMaterialResource** ppkUVSets, unsigned int uiMaxUVIndex, unsigned int& uiNumStandardUVs,
        unsigned int& uiDynamicEffectCount);
    virtual bool HandleDetailMap(Context& kContext, NiMaterialResource* pkUVSet,
        NiMaterialResource*& pkDiffuseColorRes, NiMaterialResource*& pkSpecularTexAccum);
    virtual bool HandleCustomMaps(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        unsigned int& uiWhichTexture, NiMaterialResource** apkUVSets, unsigned int uiNumStandardUVs,
        NiMaterialResource*& pkMatDiffuseColor, NiMaterialResource*& pkMatSpecularColor,
        NiMaterialResource*& pkMatSpecularPower, NiMaterialResource*& pkMatGlossiness,
        NiMaterialResource*& pkMatAmbientColor, NiMaterialResource*& pkMatEmissiveColor,
        NiMaterialResource*& pkOpacityAccum, NiMaterialResource*& pkAmbientLightAccum,
        NiMaterialResource*& pkDiffuseLightAccum, NiMaterialResource*& pkSpecularLightAccum,
        NiMaterialResource*& pkDiffuseTexAccum, NiMaterialResource*& pkSpecularTexAccum);
    virtual bool HandleEnvMap(Context& kContext, NiStandardMaterial::TexEffectType eTexEffect,
        NiMaterialResource* pkUVResource, NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
        NiMaterialResource* pkBumpOffset, NiMaterialResource* pkGlossiness);
    virtual bool HandleLighting(Context& kContext, NiUInt32 uiShadowAtlasCells, NiUInt32 uiPSSMWhichLight,
        bool bSliceTransitions, bool bSpecular, unsigned int uiNumPoint, unsigned int uiNumDirectional,
        unsigned int uiNumSpot, unsigned int uiShadowBitfield, unsigned int uiShadowTechnique,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkViewVector,
        NiMaterialResource* pkSpecularPower, NiMaterialResource*& pkAmbientAccum,
        NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum);

    // ---- new virtuals ----
    // +0x308 HandleLighting with the MS2 lights; also returns the first directional light's specular colour and
    // feeds the hair tangent to the hair light.
    virtual bool HandleMS2Lighting(Context& kContext, NiUInt32 uiShadowAtlasCells, NiUInt32 uiPSSMWhichLight,
        bool bSliceTransitions, bool bSpecular, unsigned int uiNumPoint, unsigned int uiNumDirectional,
        unsigned int uiNumSpot, unsigned int uiShadowBitfield, unsigned int uiShadowTechnique,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkViewVector,
        NiMaterialResource* pkSpecularPower, NiMaterialResource*& pkAmbientAccum,
        NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
        NiMaterialResource*& pkLightSpecular, NiMaterialResource* pkHairTangent);
    // +0x310 the light object uniform (shadowed or plain dir/point/spot) of one light
    virtual bool AddLightObject(Context& kContext, NiShaderConstantMap::ObjectMappings eMapping, LightType eType,
        unsigned int uiObjectIndex, NiMaterialResource* pkShadow, NiMaterialResource*& pkResult);
    // +0x318
    virtual bool Float4ToFloat3(Context& kContext, NiMaterialResource* pkInput, NiMaterialResource*& pkOutput);
    // +0x320 HandleLight with the MS2/character light nodes
    virtual bool HandleMS2Light(Context& kContext, unsigned int uiLight, LightType eType, unsigned int uiLightByType,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm, NiMaterialResource* pkViewVector,
        NiMaterialResource* pkSpecularPower, NiMaterialResource*& pkAmbientAccum,
        NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
        NiMaterialResource*& pkLightSpecular, bool bSpecular, NiMaterialResource* pkShadow,
        NiMaterialResource* pkHairTangent);
    // +0x328 dye colours (custom map 00 as control) and the decal map (custom 01, custom 02 as its control)
    virtual bool HandleColorOverride(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource** apkUVSets, NiMaterialResource*& pkDiffuseTexAccum);
    // +0x330 / +0x338
    virtual bool ColorOverride(Context& kContext, NiMaterialResource* pkDiffuseTexAccum,
        NiMaterialResource* pkControl, NiMaterialResource* pkColor0, NiMaterialResource* pkColor1,
        NiMaterialResource* pkColor2, NiMaterialResource*& pkResult);
    virtual bool DecalColorOverride(Context& kContext, NiMaterialResource* pkDiffuseTexAccum,
        NiMaterialResource* pkControl, NiMaterialResource* pkColor0, NiMaterialResource* pkColor1,
        NiMaterialResource* pkColor2, NiMaterialResource*& pkResult);
    // +0x340 a plain RGBA sample of a standard map
    virtual bool InsertTextureSample(Context& kContext, TextureMap eMap, NiMaterialResource* pkUV,
        NiMaterialResource*& pkResult);
    // +0x348
    virtual bool TransformTexCoord(Context& kContext, NiMaterialResource* pkUV, NiMaterialResource* pkTransform,
        NiMaterialResource*& pkResult);
    // +0x350
    virtual bool AlphaBlendColors(Context& kContext, NiMaterialResource* pkColor1, NiMaterialResource* pkColor2,
        NiMaterialResource* pkAlpha, NiMaterialResource*& pkResult);
    // +0x358 scales the diffuse colour of characters by the ColorBoost attribute
    virtual bool HandleColorBoost(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource*& pkDiffuseAccum);
    // +0x360 HandleVertexUVSets plus the projected position for screen-projected env maps
    virtual bool HandleMS2VertexUVSets(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
        NiMaterialResource* pkProjectedPos);
    // +0x368 / +0x370
    virtual bool HandleMS2TextureEffectUVSets(Context& kContext, NiMaterialResource** apkOutputUVResources,
        size_t stOutputUVMax, NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNorm,
        NiMaterialResource* pkWorldReflection, TexEffectType eEnvironmentMapType,
        unsigned int uiProjectedLightCount, unsigned int uiProjectedLightTypes,
        unsigned int uiProjectedShadowCount, unsigned int uiProjectedShadowTypes, unsigned int& uiNextUVIndex,
        NiMaterialResource* pkProjectedPos);
    virtual bool HandleMS2TextureEffectUVSetGen(Context& kContext, NiMaterialResource* pkWorldPos,
        NiMaterialResource* pkWorldNorm, NiMaterialResource* pkWorldReflection,
        NiShaderAttributeDesc::ObjectType eObjType, TexEffectType eEffectType, unsigned int uiOccurance,
        NiMaterialResource*& pkUVResource, NiMaterialResource* pkProjectedPos);
    // +0x378 bump, env and glow maps after lighting
    virtual bool HandleMS2PostLightTextureApplication(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource*& pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource*& pkOpacityAccum,
        NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum,
        NiMaterialResource* pkGlossiness, unsigned int& uiTexturesApplied, NiMaterialResource** apkUVSets,
        unsigned int uiNumStandardUVs, unsigned int uiNumTexEffectUVs, NiMaterialResource* pkLightSpecular);
    // +0x380 the glow map added on top, scaled by the GlowModifier attribute
    virtual bool HandleGlowModifier(Context& kContext, NiMaterialResource* pkUVSet,
        NiMaterialResource*& pkDiffuseAccum, NiMaterialResource*& pkSpecularAccum);
    // +0x388
    virtual bool HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
        NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum);
    // +0x390
    virtual bool HandleChaosRim(Context& kContext, NiMaterialResource*& pkColor, NiMaterialResource* pkWorldNormal,
        NiMaterialResource* pkViewVector);

    int m_eMaterialType;                    // +0x540 GetMaterialType
    bool m_bCharacterLighting;              // +0x544 character, skin or hair
    bool m_bAlphaBoost;                     // +0x545 MS2AlphaBoostMaterial
    bool m_bChaos;                          // +0x546 MS2Chaos*Material
    NiMaterialResource* m_pkDetailOpacity;  // +0x548 detail map alpha, multiplied into the opacity
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
// Vtable 0x1431c68e0 (sizeof 0x540, no new members): soft particles faded against the scene depth.
class SoftParticlesMaterial : public NiStandardMaterial
{
public:
    SoftParticlesMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool HandleViewProjectionFragment(Context& kContext, bool bForceViewPos,
        NiMaterialResource* pkVertWorldPos, NiMaterialResource*& pkVertOutProjectedPos,
        NiMaterialResource*& pkVertOutViewPos);
    virtual bool HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
        NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos);
    virtual bool HandlePreLightTextureApplication(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
        NiMaterialResource*& pkWorldPos, NiMaterialResource*& pkWorldNormal, NiMaterialResource*& pkWorldBinormal,
        NiMaterialResource*& pkWorldTangent, NiMaterialResource*& pkWorldViewVector,
        NiMaterialResource*& pkTangentViewVector, NiMaterialResource*& pkMatDiffuseColor,
        NiMaterialResource*& pkMatSpecularColor, NiMaterialResource*& pkMatSpecularPower,
        NiMaterialResource*& pkMatGlossiness, NiMaterialResource*& pkMatAmbientColor,
        NiMaterialResource*& pkMatEmissiveColor, NiMaterialResource*& pkOpacityAccum,
        NiMaterialResource*& pkAmbientLightAccum, NiMaterialResource*& pkDiffuseLightAccum,
        NiMaterialResource*& pkSpecularLightAccum, NiMaterialResource*& pkDiffuseTexAccum,
        NiMaterialResource*& pkSpecularTexAccum, unsigned int& uiTexturesApplied, NiMaterialResource** apkUVSets,
        unsigned int uiNumStandardUVs, unsigned int uiNumTexEffectUVs);
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
