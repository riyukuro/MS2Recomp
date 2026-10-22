// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\worldfadeoutrenderstep.cpp
// MS2-RANGE: 0x1400fca70-0x1400fcad0 .text$di
// MS2-RANGE: 0x1416bad00-0x1416bc380 .text$mn
// MS2-RANGE: 0x1400fcc80-0x1400fcce0 .text$di
// MS2-RANGE: 0x1400fcf80-0x1400fd100 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\worldfadeoutrenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldfadeoutrenderstep.h"
#include <NiRenderer.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderedTexture.h>
#include "hook/ms2hook.h"

// Unrecovered callees (real types unknown).
unsigned char FUN_1412642d0(void* step);
NiRenderedTexture* FUN_1416a23f0(unsigned __int64 p, int n);   // the step's input texture n
void FUN_1416a0fb0(unsigned __int64 p, int n);
// MS2: unit-local interface; only slot 17 is proven (the class behind FUN_1416a3ec0 is unrecovered). Never instantiated.
struct Unk_WFTarget
{
    virtual ~Unk_WFTarget();
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual __int64 vfunc_17();                 // slot 17 (+0x88): non-zero when the target is usable
};
Unk_WFTarget* FUN_1416a3ec0(unsigned __int64 p);
char* FUN_1409a8b20();
void* FUN_140af8310(char* p);
void* FUN_1411d15b0(void* p);
NiRenderer* GetNiRenderer();   // NiRenderer::GetRenderer()
NiRenderer* FUN_1414fd170(void* p);
void FUN_1409a5770(void* obj, float* value, int n);
extern char DAT_143ae5320;
extern int DAT_1439f823c;
struct Unk_WFApp { void FUN_141473020(int a); };
Unk_WFApp* FUN_14086d260();
struct Unk_WFRect {
    Unk_WFRect(int a, int b, int c, int d);     // 0x140a5a400
    int a, b, c, d;
};
bool FUN_1416bafb0(void* a, void* step);

// @0x143ae5088 / @0x143ae508c (zero-initialised)
static float s_fade;
static unsigned long s_fadeStartTick;

// @0x1400fca70
#ifdef __clang__
// MS2: clang folds this to a constant initializer holding the address of an exe global (ADDR64 in .rdata), which the
// DLL post-link check rejects; a base-pointer getter reading a mutable zero forces dynamic initialization (MSVC build unaffected).
static volatile unsigned __int64 s_wfZero;
static const NiRTTI* wfBaseRTTI() { return (const NiRTTI*)((unsigned __int64)&NiDefaultClickRenderStep::ms_RTTI + s_wfZero); }
const NiRTTI WorldFadeOutRenderStep::ms_RTTI("WorldFadeOutRenderStep", wfBaseRTTI());
#else
const NiRTTI WorldFadeOutRenderStep::ms_RTTI("WorldFadeOutRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
#endif


// Header-defined property and material names; each is a real NiFixedString.
extern NiFixedString DAT_143ae50a8;
extern NiFixedString DAT_143ae50a0;
extern NiFixedString DAT_143ae50b0;
extern NiFixedString DAT_143ae50b8;
extern NiFixedString DAT_143ae50c0;
extern NiFixedString DAT_143ae50c8;
extern NiFixedString DAT_143ae50d0;
extern NiFixedString DAT_143ae50d8;
extern NiFixedString DAT_143ae50e0;
extern NiFixedString DAT_143ae50e8;
extern NiFixedString DAT_143ae50f0;
extern NiFixedString DAT_143ae50f8;
extern NiFixedString DAT_143ae5100;
extern NiFixedString DAT_143ae5108;
extern NiFixedString DAT_143ae5110;
extern NiFixedString DAT_143ae5118;
extern NiFixedString DAT_143ae5120;
extern NiFixedString DAT_143ae5128;
extern NiFixedString DAT_143ae5130;
extern NiFixedString DAT_143ae5138;
extern NiFixedString DAT_143ae5140;
extern NiFixedString DAT_143ae5148;
extern NiFixedString DAT_143ae5150;
extern NiFixedString DAT_143ae5158;
extern NiFixedString DAT_143ae5160;
extern NiFixedString DAT_143ae5168;
extern NiFixedString DAT_143ae5170;
extern NiFixedString DAT_143ae5178;
extern NiFixedString DAT_143ae5180;
extern NiFixedString DAT_143ae5188;
extern NiFixedString DAT_143ae5190;
extern NiFixedString DAT_143ae5198;
extern NiFixedString DAT_143ae51a0;
extern NiFixedString DAT_143ae51a8;
extern NiFixedString DAT_143ae51b0;
extern NiFixedString DAT_143ae51b8;
extern NiFixedString DAT_143ae51c0;
extern NiFixedString DAT_143ae51c8;
extern NiFixedString DAT_143ae51d0;
extern NiFixedString DAT_143ae51d8;
extern NiFixedString DAT_143ae51e0;
extern NiFixedString DAT_143ae51e8;
extern NiFixedString DAT_143ae51f8;
extern NiFixedString DAT_143ae5200;
extern NiFixedString DAT_143ae5208;
extern NiFixedString DAT_143ae5210;
extern NiFixedString DAT_143ae5218;
extern NiFixedString DAT_143ae5220;
extern NiFixedString DAT_143ae5228;
extern NiFixedString DAT_143ae5230;
extern NiFixedString DAT_143ae5238;
extern NiFixedString DAT_143ae5240;
extern NiFixedString DAT_143ae5248;
extern NiFixedString DAT_143ae5250;
extern NiFixedString DAT_143ae5258;
extern NiFixedString DAT_143ae51f0;
extern NiFixedString DAT_143ae52e0;
extern NiFixedString DAT_143ae5260;
extern NiFixedString DAT_143ae5268;
extern NiFixedString DAT_143ae5270;
extern NiFixedString DAT_143ae5278;
extern NiFixedString DAT_143ae5280;
extern NiFixedString DAT_143ae5288;
extern NiFixedString DAT_143ae5290;
extern NiFixedString DAT_143ae5298;
extern NiFixedString DAT_143ae52a0;
extern NiFixedString DAT_143ae52a8;
extern NiFixedString DAT_143ae52b0;
extern NiFixedString DAT_143ae52b8;
extern NiFixedString DAT_143ae52c0;
extern NiFixedString DAT_143ae52c8;
extern NiFixedString DAT_143ae52d0;
extern NiFixedString DAT_143ae52d8;

// @0x1400fcaa0
NiFixedString DAT_143ae5238;
// @0x1400fcc80
NiFixedString DAT_143ae5208;
// @0x1400fccb0
NiFixedString DAT_143ae51f8;
// @0x1400fcf80
NiFixedString DAT_143ae51a0;
// @0x1400fcfb0
NiFixedString DAT_143ae51d8;
// @0x1400fcfe0
NiFixedString DAT_143ae52c8;
// @0x1400fd010
NiFixedString DAT_143ae51d0;
// @0x1400fd040
NiFixedString DAT_143ae50f0;
// @0x1400fd070
NiFixedString DAT_143ae5210;
// @0x1400fd0a0
NiFixedString DAT_143ae5148;
// @0x1400fd0d0
NiFixedString DAT_143ae5150;

// @0x1416bad00
WorldFadeOutRenderStep::WorldFadeOutRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b), m_a0(0)
{
    NiFixedString name("WorldFadeOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416bada0
WorldFadeOutRenderStep::~WorldFadeOutRenderStep()
{
    NiFixedString name("FadeOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416bae20
bool WorldFadeOutRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* p;
    p = FUN_140c8f690(FUN_1416b4990(this, "FadeOut", (void*)FUN_1416bafb0, this, FUN_1416a23f0(m_70, 5), 0, 0, 0, "FadeInOut", FUN_140c8f680(&((void**)b)[2]), FUN_140c8f680(&((void**)b)[1]), 0));
    if (p == 0) {
        vfunc_16();
        return false;
    }
    return true;
}

MS2_REPLACE_METHOD(0x1416BAE20, WorldFadeOutRenderStep, vfunc_15, 388, 0xF523D75F);

#ifndef MS2_HOOK_DLL
// @0x1416bafb0
bool FUN_1416bafb0(void* a, void* step)
{
    void* s = step;
    s_fade = 1.0f - ((float)GetTickCount() - (float)s_fadeStartTick) / (float)DAT_1439f823c;
    if (s_fade <= 0.0f) {
        if (FUN_1412642d0(s) == 1) {
            FUN_1416a0fb0(((PostProcessEffect*)s)->m_70, 0xf);
            s_fade = 0.0f;
            FUN_14086d260()->FUN_141473020(0);
        }
    }
    s_fade = s_fade * s_fade;
    FUN_1409a5770(&DAT_143ae5320, &s_fade, 1);
    return true;
}
#endif

// @0x1416bb0a0
// MS2-FUNCTIONAL: stack-slot layout of temps differs (frame 0x98 matches, slot order does not)
void WorldFadeOutRenderStep::vfunc_19()
{
    if (FUN_1412642d0(this) == 1) {
        Unk_WFTarget* a = FUN_1416a3ec0(m_70);
        if (a->vfunc_17() != 0) {
            void* h = FUN_1411d15b0(FUN_140af8310(FUN_1409a8b20() + 8));
            NiRenderer* p = GetNiRenderer();
            NiRenderTargetGroup* q = p->GetDefaultRenderTargetGroup();
            int w = q->GetWidth(0);
            int ht = q->GetHeight(0);
            Unk_WFRect rect(0, w, 0, ht);
            NiRenderedTexture* pp = FUN_1416a23f0(m_70, 5);
            NiRenderer* rn = FUN_1414fd170(h);
            Ni2DBuffer* r = rn->GetDefaultRenderTargetGroup()->GetBuffer(0);
            Ni2DBuffer* arg = pp->GetBuffer();
            r->Copy(arg, reinterpret_cast<const NiRect<unsigned int>*>(&rect), reinterpret_cast<const NiRect<unsigned int>*>(&rect), (Ni2DBuffer::CopyFilterPreference)0);
            s_fadeStartTick = GetTickCount();
        }
    }
}

// @0x1416bb2b0
const NiRTTI* WorldFadeOutRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416bb2c0
bool WorldFadeOutRenderStep::vfunc_14() { return false; }

// @0x1416bb2d0
bool WorldFadeOutRenderStep::vfunc_13() { return false; }

// Name-table routines operate on mutable exe statics, so are not hooked.
// @0x1416bb2e0
void FUN_1416bb2e0()
{
    DAT_143ae50a8 = "CI";
    DAT_143ae50a0 = "AO";
    DAT_143ae50b0 = "IA";
    DAT_143ae50b8 = "IM";
    DAT_143ae50c0 = "IA";
    DAT_143ae50c8 = "OverrideColor0";
    DAT_143ae50d0 = "OverrideColor1";
    DAT_143ae50d8 = "OverrideColor2";
    DAT_143ae50e0 = "POutlineColor";
    DAT_143ae50e8 = "noOutline";
    DAT_143ae50f0 = "ForceForcedColor";
    DAT_143ae50f8 = "DecalMapTransform";
    DAT_143ae5100 = "DecalOverrideColor0";
    DAT_143ae5108 = "DecalOverrideColor1";
    DAT_143ae5110 = "DecalOverrideColor2";
    DAT_143ae5118 = "Highlight";
    DAT_143ae5120 = "OutlineWidth";
    DAT_143ae5128 = "OutlineColor";
    DAT_143ae5130 = "SuperModeOrginColorRate";
    DAT_143ae5138 = "SuperModeWhiteColorRate";
    DAT_143ae5140 = "ColorBoost";
    DAT_143ae5148 = "FresnelBoost";
    DAT_143ae5150 = "FresnelExponent";
    DAT_143ae5158 = "ChaosFresnelBoost";
    DAT_143ae5160 = "ChaosFresnelExponent";
    DAT_143ae5168 = "ChaosDimmer";
    DAT_143ae5170 = "ChaosLightColor";
    DAT_143ae5178 = "GlowModifier";
    DAT_143ae5180 = "SoftDepth";
    DAT_143ae5188 = "Order";
    DAT_143ae5190 = "HasMS2MapProperties";
    DAT_143ae5198 = "Name";
    DAT_143ae51a0 = "ExNearbox";
    DAT_143ae51a8 = "CastShadow";
    DAT_143ae51b0 = "NoDOF";
    DAT_143ae51b8 = "UserPropBuffer";
    DAT_143ae51c0 = "RenderView";
    DAT_143ae51c8 = "_SFN";
    DAT_143ae51d0 = "FluidMeshFlag";
    DAT_143ae51d8 = "FA";
}

// @0x1416bb5f0
void FUN_1416bb5f0()
{
    DAT_143ae50a0 = NiFixedString();
    DAT_143ae50a8 = NiFixedString();
    DAT_143ae50b0 = NiFixedString();
    DAT_143ae50b8 = NiFixedString();
    DAT_143ae50c0 = NiFixedString();
    DAT_143ae50c8 = NiFixedString();
    DAT_143ae50d0 = NiFixedString();
    DAT_143ae50d8 = NiFixedString();
    DAT_143ae50e0 = NiFixedString();
    DAT_143ae50e8 = NiFixedString();
    DAT_143ae50f0 = NiFixedString();
    DAT_143ae50f8 = NiFixedString();
    DAT_143ae5100 = NiFixedString();
    DAT_143ae5108 = NiFixedString();
    DAT_143ae5110 = NiFixedString();
    DAT_143ae5118 = NiFixedString();
    DAT_143ae5120 = NiFixedString();
    DAT_143ae5128 = NiFixedString();
    DAT_143ae5130 = NiFixedString();
    DAT_143ae5138 = NiFixedString();
    DAT_143ae5140 = NiFixedString();
    DAT_143ae5148 = NiFixedString();
    DAT_143ae5150 = NiFixedString();
    DAT_143ae5158 = NiFixedString();
    DAT_143ae5160 = NiFixedString();
    DAT_143ae5168 = NiFixedString();
    DAT_143ae5170 = NiFixedString();
    DAT_143ae5178 = NiFixedString();
    DAT_143ae5180 = NiFixedString();
    DAT_143ae5188 = NiFixedString();
    DAT_143ae5190 = NiFixedString();
    DAT_143ae5198 = NiFixedString();
    DAT_143ae51a0 = NiFixedString();
    DAT_143ae51a8 = NiFixedString();
    DAT_143ae51b0 = NiFixedString();
    DAT_143ae51b8 = NiFixedString();
    DAT_143ae51c0 = NiFixedString();
    DAT_143ae51c8 = NiFixedString();
    DAT_143ae51d0 = NiFixedString();
    DAT_143ae51d8 = NiFixedString();
}

// @0x1416bc0f0
void FUN_1416bc0f0()
{
    DAT_143ae51e0 = "NiStandardMaterial";
    DAT_143ae51e8 = "MS2StandardMaterial";
    DAT_143ae51f8 = "MS2CharacterMaterial";
    DAT_143ae5200 = "MS2CharacterSkinMaterial";
    DAT_143ae5208 = "MS2CharacterHairMaterial";
    DAT_143ae5210 = "MS2ForceColorMaterial";
    DAT_143ae5218 = "MS2TextureDensityMaterial";
    DAT_143ae5220 = "MS2DepthMaterial";
    DAT_143ae5228 = "MS2CharacterDepthMaterial";
    DAT_143ae5230 = "MS2AlphaBoostMaterial";
    DAT_143ae5238 = "MS2BlendLightMaterial";
    DAT_143ae5240 = "MS2ChaosMaterial";
    DAT_143ae5248 = "MS2ChaosSkinMaterial";
    DAT_143ae5250 = "MS2ChaosHairMaterial";
    DAT_143ae5258 = "SoftParticlesMaterial";
    DAT_143ae51f0 = "MS2GlowMaterial";
    DAT_143ae52e0 = "MS2UIMaterial";
    DAT_143ae5260 = "MS2MotionBlurMaterial";
    DAT_143ae5268 = "MS2OuterGlowCharacterMaterial";
    DAT_143ae5270 = "MS2CharacterMonochromeMaterial";
    DAT_143ae5278 = "MS2DecorationMaterial";
    DAT_143ae5280 = "TexCoordWriteMaterial";
    DAT_143ae5288 = "MRTShaderPickerMaterial";
    DAT_143ae5290 = "MS2DirectionalShadowWriteMaterial";
    DAT_143ae5298 = "MS2PointShadowWriteMaterial";
    DAT_143ae52a0 = "MS2SpotShadowWriteMaterial";
    DAT_143ae52a8 = "OutlineMaterial";
    DAT_143ae52b0 = "MS2DefaultShimmerValueMaterial";
    DAT_143ae52b8 = "MS2ShimmerMaterial";
    DAT_143ae52c0 = "MS2IceMaterial";
    DAT_143ae52c8 = "MS2FireMaterial";
    DAT_143ae52d0 = "MS2PoisonMaterial";
    DAT_143ae52d8 = "MS2DarkMaterial";
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb4760-0x142cb4780 .text$yd
// MS2-RANGE: 0x142cb48a0-0x142cb48e0 .text$yd
// MS2-RANGE: 0x142cb4aa0-0x142cb4ba0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x1416bb2b0, WorldFadeOutRenderStep, GetRTTI, 13, 0x6B2BF7C8);
MS2_REPLACE_METHOD(0x1416bb2c0, WorldFadeOutRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416bb2d0, WorldFadeOutRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE(0x1416bb5f0, FUN_1416bb5f0, 2795, 0xCB9A0617);
MS2_REPLACE(0x1416bc0f0, FUN_1416bc0f0, 636, 0x77CB25AB);

