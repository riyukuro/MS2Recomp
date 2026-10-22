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
// Vtable 0x1431c6458 (sizeof 0x550, no new members): the character outline pass ("OutlineMaterial", typed as
// MS2CharacterMaterial, version offset 0xe). The vertices are pushed out along the world normal by the OutlineWidth
// attribute in view space (ExtractOutline) and the pixels output the flat OutlineColor attribute.
class OutlineMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;

public:
    OutlineMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
        NiStandardVertexProgramDescriptor* pkVertexDesc, bool bForceWorldView, bool bForceViewPos,
        NiMaterialResource*& pkWorldPos, NiMaterialResource*& pkViewPos, NiMaterialResource*& pkProjectedPos,
        NiMaterialResource*& pkWorldNormal, NiMaterialResource*& pkWorldView);
    virtual bool HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
        NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum);

    // ---- new virtual ----
    // +0x398 HandleViewProjectionFragment with the position extruded along the world normal (ExtractOutline);
    // bForceViewPos is unused, the view position is always produced
    virtual bool HandleOutlineViewProjection(Context& kContext, bool bForceViewPos, NiMaterialResource* pkWorldPos,
        NiMaterialResource* pkWorldNormal, NiMaterialResource*& pkProjectedPos, NiMaterialResource*& pkViewPos);
};

//--------------------------------------------------------------------------------------------------
// Vtable 0x1431d1200 (sizeof 0x548, no new members): the stock shadow writer plus MS2MaterialNodeLibrary, skinning
// with the 60-bone fragment.
class MS2DirectionalShadowWriteMaterial : public NiDirectionalShadowWriteMaterial
{
    NiDeclareRTTI;

public:
    MS2DirectionalShadowWriteMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hook can bind it
    virtual bool HandlePositionFragment(Context& kContext, TransformType eTransType,
        NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix);
};

// Vtable 0x1431d1558 (sizeof 0x548, no new members): the stock shadow writer plus MS2MaterialNodeLibrary, skinning
// with the 60-bone fragment.
class MS2PointShadowWriteMaterial : public NiPointShadowWriteMaterial
{
    NiDeclareRTTI;

public:
    MS2PointShadowWriteMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hook can bind it
    virtual bool HandlePositionFragment(Context& kContext, TransformType eTransType,
        NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix);
};

// Vtable 0x1431d18b0 (sizeof 0x548, no new members): the stock shadow writer plus MS2MaterialNodeLibrary, skinning
// with the 60-bone fragment.
class MS2SpotShadowWriteMaterial : public NiSpotShadowWriteMaterial
{
    NiDeclareRTTI;

public:
    MS2SpotShadowWriteMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hook can bind it
    virtual bool HandlePositionFragment(Context& kContext, TransformType eTransType,
        NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix);
};

//--------------------------------------------------------------------------------------------------
// Vtable 0x1431c68e0 (sizeof 0x540, no new members): soft particles faded against the scene depth.
class SoftParticlesMaterial : public NiStandardMaterial
{
    NiDeclareRTTI;

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
// Vtable 0x1431d1c30: an MS2CharacterMaterial variant (version offset 4) whose shade trees keep only the transform,
// the UV sets and the pre-light texture stage; no lighting.
class CustomizedTextureGeneratorMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;
public:
    CustomizedTextureGeneratorMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual bool GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
};

//--------------------------------------------------------------------------------------------------
// Vtable 0x1431d20b8: writes the base map's UV set out as the pixel colour (UV debug / bake pass), version offset 1 of
// MS2StandardMaterial. The transform pipeline only produces the world and projected positions.
class TexCoordWriteMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;
public:
    TexCoordWriteMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual bool GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual bool SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
        NiStandardVertexProgramDescriptor* pkVertexDesc, bool bForceWorldView, bool bForceViewPos,
        NiMaterialResource*& pkWorldPos, NiMaterialResource*& pkViewPos, NiMaterialResource*& pkProjectedPos,
        NiMaterialResource*& pkWorldNormal, NiMaterialResource*& pkWorldView);
    virtual bool HandleVertexUVSets(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect);

    // ---- new virtuals ----
    // +0x398 the pixel output: the base map's UV set widened to float4, or zero when there is no base map
    virtual bool HandleTexCoordOutput(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource** apkUVSets);
    // +0x3a0 binds pkInput through a Float2ToFloat4 node
    virtual bool ConvertFloat2ToFloat4(Context& kContext, NiMaterialResource* pkInput,
        NiMaterialResource*& pkOutput);
};

//--------------------------------------------------------------------------------------------------
class MRTShaderPickerMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;
public:
    MRTShaderPickerMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool GenerateVertexShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual bool GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual bool SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
        NiStandardVertexProgramDescriptor* pkVertexDesc, bool bForceWorldView, bool bForceViewPos,
        NiMaterialResource*& pkWorldPos, NiMaterialResource*& pkViewPos, NiMaterialResource*& pkProjectedPos,
        NiMaterialResource*& pkWorldNormal, NiMaterialResource*& pkWorldView);
    virtual bool HandleVertexUVSets(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect);
    virtual bool HandlePixelInputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
        NiMaterialResource*& pkPixelWorldPos, NiMaterialResource*& pkPixelWorldNorm,
        NiMaterialResource*& pkPixelWorldBinormal, NiMaterialResource*& pkPixelWorldTangent,
        NiMaterialResource*& pkPixelWorldViewVector, NiMaterialResource*& pkPixelTangentViewVector);

    // ---- new virtuals ----
    // +0x398 the three MRT colour outputs: world position, world normal and the base-map UV colour
    virtual bool HandleMRTOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource** apkUVSets);
    // +0x3a0 binds pkInput through a UVColorToFloat4 node sampling custom map 00
    virtual bool ConvertUVColorToFloat4(Context& kContext, NiMaterialResource* pkInput,
        NiMaterialResource*& pkOutput);
    // +0x3a8 binds pkInput through a Float2ToFloat4 node
    virtual bool ConvertFloat2ToFloat4(Context& kContext, NiMaterialResource* pkInput,
        NiMaterialResource*& pkOutput);
    // +0x3b0 binds pkInput through a Float3ToFloat4 node
    virtual bool ConvertFloat3ToFloat4(Context& kContext, NiMaterialResource* pkInput,
        NiMaterialResource*& pkOutput);
};

//--------------------------------------------------------------------------------------------------
class MS2MotionBlurMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;
public:
    MS2MotionBlurMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool HandlePositionFragment(Context& kContext, TransformType eTransType,
        NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix);
    virtual bool HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
        NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos);
    virtual bool HandleVertexLightingAndMaterials(Context& kContext, NiStandardVertexProgramDescriptor* pkVertexDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldView);
    virtual bool HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
        NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum);
};

//--------------------------------------------------------------------------------------------------
// Vtable 0x1431d2fa8 (sizeof 0x550, no new members): the outer glow drawn around characters
// ("MS2OuterGlowCharacterMaterial", typed as MS2CharacterMaterial, version 6, per-pixel lighting forced). The
// position runs through ProjectPositionWorldToViewToProj_Outer and the pixels output the gkOuterColor global.
class MS2OuterGlowCharacterMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;

public:
    MS2OuterGlowCharacterMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    virtual bool GeneratePixelShadeTree(Context& kContext, NiGPUProgramDescriptor* pkDesc);
    virtual ReturnCode GenerateShaderDescArray(NiMaterialDescriptor* pkMaterialDescriptor,
        RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount, unsigned int& uiCountAdded);
    virtual bool HandlePositionFragment(Context& kContext, TransformType eTransType,
        NiMaterialResource*& pkVertWorldPos, NiMaterialResource*& pkWorldMatrix);
    virtual bool SetupTransformPipeline(Context& kContext, NiMaterialResource* pkOutProjPos,
        NiStandardVertexProgramDescriptor* pkVertexDesc, bool bForceWorldView, bool bForceViewPos,
        NiMaterialResource*& pkWorldPos, NiMaterialResource*& pkViewPos, NiMaterialResource*& pkProjectedPos,
        NiMaterialResource*& pkWorldNormal, NiMaterialResource*& pkWorldView);
    virtual bool HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
        NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum);

    // ---- new virtual ----
    // +0x398 HandleViewProjectionFragment through ProjectPositionWorldToViewToProj_Outer (fed the world normal);
    // bForceViewPos is unused, the view position is always produced
    virtual bool HandleOuterViewProjection(Context& kContext, bool bForceViewPos, NiMaterialResource* pkWorldPos,
        NiMaterialResource* pkWorldNormal, NiMaterialResource*& pkProjectedPos, NiMaterialResource*& pkViewPos);
};

//--------------------------------------------------------------------------------------------------
class MS2DepthMaterial : public MS2StandardMaterial
{
    NiDeclareRTTI;

public:
    MS2DepthMaterial(bool bAutoCreateCaches);

protected:
    MS2DepthMaterial(const NiFixedString& kName, bool bAutoCreateCaches, unsigned int uiVersionOffset);

    // protected in the original; public here so the hooks can bind them
public:
    virtual ReturnCode GenerateShaderDescArray(NiMaterialDescriptor* pkMaterialDescriptor,
        RenderPassDescriptor* pkRenderPasses, unsigned int uiMaxCount, unsigned int& uiCountAdded);
    virtual bool HandleViewProjectionFragment(Context& kContext, bool bForceViewPos,
        NiMaterialResource* pkVertWorldPos, NiMaterialResource*& pkVertOutProjectedPos,
        NiMaterialResource*& pkVertOutViewPos);
    virtual bool HandleFinalVertexOutputs(Context& kContext, NiStandardVertexProgramDescriptor* pkVertDesc,
        NiMaterialResource* pkWorldPos, NiMaterialResource* pkWorldNormal, NiMaterialResource* pkWorldReflect,
        NiMaterialResource* pkViewPos, NiMaterialResource* pkProjectedPos);
    virtual bool HandlePixelInputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixelDesc,
        NiMaterialResource*& pkPixelWorldPos, NiMaterialResource*& pkPixelWorldNorm,
        NiMaterialResource*& pkPixelWorldBinormal, NiMaterialResource*& pkPixelWorldTangent,
        NiMaterialResource*& pkPixelWorldViewVector, NiMaterialResource*& pkPixelTangentViewVector);
    virtual bool HandleNormalMap(Context& kContext, NiMaterialResource* pkUVSet, NormalMapType eType,
        NiMaterialResource*& pkWorldNormal, NiMaterialResource* pkWorldBinormal,
        NiMaterialResource* pkWorldTangent);
    virtual bool HandleEnvMap(Context& kContext, NiStandardMaterial::TexEffectType eTexEffect,
        NiMaterialResource* pkUVResource, NiMaterialResource*& pkDiffuseAccum,
        NiMaterialResource*& pkSpecularAccum, NiMaterialResource* pkBumpOffset,
        NiMaterialResource* pkGlossiness);
    virtual bool HandleMS2FinalPixelOutputs(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
        NiMaterialResource* pkWorldNormal, NiMaterialResource* pkViewVector, NiMaterialResource* pkDiffuseAccum,
        NiMaterialResource* pkSpecularAccum, NiMaterialResource* pkOpacityAccum);

    // ---- new virtual ----
    // +0x398 adds the named depth node, feeding it the projected position ("Input") and, when there is one, the
    // final opacity ("FinalOpacity")
    virtual NiMaterialNodePtr AttachDepthNode(const NiFixedString& kNodeName, Context& kContext,
        NiMaterialResource* pkOpacity, NiMaterialResource* pkInput);
};

//--------------------------------------------------------------------------------------------------
#define MS2_DECLARE_STANDARD_MATERIAL(classname)                                                    \
    class classname : public MS2StandardMaterial                                                    \
    {                                                                                               \
    public:                                                                                         \
        classname(bool bAutoCreateCaches);                                                          \
    }

MS2_DECLARE_STANDARD_MATERIAL(MS2DefaultShimmerValueMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2ShimmerMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2GlassMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2DecorationMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2GlowMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2TextureDensityMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2ForceColorMaterial);
MS2_DECLARE_STANDARD_MATERIAL(MS2UIMaterial);

//--------------------------------------------------------------------------------------------------
class MS2CharacterDepthMaterial : public MS2DepthMaterial
{
    NiDeclareRTTI;

public:
    MS2CharacterDepthMaterial(bool bAutoCreateCaches);

    // protected in the original; public here so the hooks can bind them
    // "PositionToDepthForCharacter" plus the gfNearZ global
    virtual NiMaterialNodePtr AttachDepthNode(const NiFixedString& kNodeName, Context& kContext,
        NiMaterialResource* pkOpacity, NiMaterialResource* pkInput);
};
