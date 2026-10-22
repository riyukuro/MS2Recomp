// postprocessingservice.h - the render steps compiled into client\ms2\postprocessing\postprocessingservice.cpp (RTTI names),
// recovered header. The PostProcessEffect / ReloadablePostProcess bases are in ms2/placeholder/postprocesseffect.h; their
// member functions live in this unit too.
// Several steps register their RTTI with NiDefaultClickRenderStep (0x143afa7a8) or AntiAlias/DoF with NiRenderStep (0x143afaa00) as parent,
// as the original NiImplementRTTI lines did.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"
#include <NiTPointerList.h>
#include <NiTList.h>
#include <efd/ISystemService.h>
#include <efd/StdContainers.h>
#include <efd/Category.h>
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/client/ms2/afterimageeffectparam.h"

class Ni2DBuffer;
class NiRenderClick;
class NiTexturingProperty;
class NiMaterial;
class NiViewRenderClick;
class NiDefaultClickRenderStep;
class NiRenderTargetGroup;
class NiTextureEffect;
class NiRenderListProcessor;
class NiNode;
class PostProcessSetting;
class CPlaneReflectionSetting;
class MS2TextureDensityProcessor;
class CDepthOfFieldManager;
class NiRenderStep;
class NiTexture;
class NiAVObject;
class NiPixelFormat;
struct IDirect3DSurface9;
typedef IDirect3DSurface9* LPDIRECT3DSURFACE9;
namespace egf { class IBuiltinModel; class EntityChangeMessage; }
namespace ecr { class SceneGraphAddedMessage; class SceneGraphRemovedMessage; }

// ---- PostProcessingService (0x218, class id 0x06100005) ----
// TSingleton at +0, ISystemService at +8, IWorldServiceCallback at +0x20. Owns the render clicks / targets the steps
// draw with and the step map (step index -> effect). Passed to the steps as PostProcessEffect::m_70.
class PostProcessingService;
template <class T> class TSingleton;
template <> class TSingleton<PostProcessingService>
{
public:
    TSingleton();                                   // 0x1416ae4f0 (inline, in the cpp)
    virtual ~TSingleton() { s_instance = 0; }       // 0x1416aedf0
    static PostProcessingService* s_instance;       // 0x143ab3da0
};

// A pre-process render-click slot (m_aspClicks index); SetPreprocessRCActiveRef logs it as "texture={0}" through fmt's
// enum (custom argument) path.
enum Unk_PPTexture {};

class PostProcessingService : public TSingleton<PostProcessingService>, public efd::ISystemService,
    public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(PostProcessingService, 0x06100005, efd::IBase);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    PostProcessingService();                        // 0x1416a3020
    virtual ~PostProcessingService();               // 0x1416a3380
    virtual const char* GetDisplayName() const;     // 0x1416a35a0
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1416a4800
    virtual efd::AsyncResult OnInit();              // 0x1416a4860
    virtual efd::AsyncResult OnTick();              // 0x1416a5f20
    virtual efd::AsyncResult OnShutdown();          // 0x1416a6100

    // IWorldServiceCallback
    virtual void vfunc_0(int) {}                    // 0x1416b1d70
    virtual void vfunc_1(int) {}                    // 0x1416b1d80
    virtual void vfunc_2(int, CString) {}           // 0x1416b1d90
    virtual void vfunc_3(int);                      // 0x1416aad30 world unloaded: drop the mirrored view
    virtual void vfunc_4(int) {}                    // 0x1416b1dc0

    bool FUN_1416a35c0(bool bEnable);               // toggle the extra MRT targets (1..6)
    bool FUN_1416a36f0(bool bEnable);               // toggle the 16-bit float target format
    bool FUN_1416a3760();
    bool FUN_1416a3780();
    bool FUN_1416a37a0(int nStep, bool bRelink);    // toggle a step's active flag; returns the new state
    bool FUN_1416a3920(int nStep, bool bActive);    // set a step's active flag (toggles + relinks when it differs)
    bool FUN_1416a3a00(int nStep);                  // is the step active
    PostProcessEffect* FUN_1416a3a90(int nStep);
    static egf::IBuiltinModel* FUN_1416a3b10();     // "PostProcessSetting" builtin model factory
    void FUN_1416a3bb0();                           // create the off-screen target m_spTarget190
    LPDIRECT3DSURFACE9 FUN_1416a3cd0(const NiPixelFormat* pkFormat, unsigned int uiWidth, unsigned int uiHeight);
    PostProcessEffect* FUN_1416a3ec0();             // first active step
    efd::SmartPointer<NiRenderTargetGroup> FUN_1416a3fb0();
    static bool FUN_1416a4000(NiRenderStep* pkStep, void* pvData);                    // re-point the mirrored view at the main camera
    static bool FUN_1416a40c0(NiRenderStep* pkStep, void* pvData);                    // disable user clip planes
    void FUN_1416a4110(const ecr::SceneGraphAddedMessage* pMessage, efd::Category targetChannel);
    void FUN_1416a4240(const ecr::SceneGraphRemovedMessage* pMessage, efd::Category targetChannel);
    void FUN_1416a4350(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel);   // 8196
    void FUN_1416a43e0(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel);   // 8253
    void FUN_1416a44d0(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel);   // 8254
    void FUN_1416a4570(bool bEnable);               // texture-density debug view on/off
    bool FUN_1416a4620();                           // is the texture-density view on
    void FUN_1416a4660(int nMode);
    int FUN_1416a46a0();
    void FUN_1416a46d0();                           // toggle the outline click
    bool FUN_1416a4790();                           // is the outline click active
    void FUN_1416aa450(int nClick, bool bActive);
    bool FUN_1416a66d0();                           // can the device do MRT
    bool FUN_1416a69a0();                           // can the device do float targets
    void FUN_1416a6d90(int nStep, efd::SmartPointer<PostProcessEffect> spStep);   // insert a step
    void FUN_1416a7570();                           // build the pre-process render step
    void FUN_1416a6fc0();                           // debug hot-key: Ctrl+S toggles the post-process debug view
    void FUN_1416aade0(NiRenderTargetGroup* pkTarget);  // release the D3D references of the target's colour buffer
    void FUN_1416aae50();                           // flush the queued click events
    void FUN_1416aa240();                           // rebuild the shimmer target over m_aspTextures[7]
    void FUN_1416aa330();                           // create the seven post-process materials
    bool FUN_1416aa850(int nClick);                 // is click nClick active
    bool FUN_1416aa8b0(NiRenderStep* pkStep);       // is the step one of the fade steps
    void FUN_1416aac60(NiAVObject* pkScene);        // remove a scene from the mirrored view
    CDepthOfFieldManager* FUN_1416aad00();          // m_spDoF
    void FUN_1416aa6a0(Unk_PPTexture eClick, bool bActive);   // SetPreprocessRCActiveRef: reference-counted SetActive of a pre-process click
    void FUN_1416aa950();                           // attach the reflection texture effect to the reflective nodes
    void FUN_1416ab960();                           // remove the steps from the active render frame
    static bool FUN_1416ac0b0(NiRenderClick* pkClick, void* pvData);   // save the background colour, clear to grey
    static bool FUN_1416ac150(NiRenderClick* pkClick, void* pvData);   // save the background colour, clear to pvData
    static bool FUN_1416ac1e0(NiRenderClick* pkClick, void* pvData);   // restore the background colour
    static bool FUN_1416ac240(NiRenderClick* pkClick, void* pvData);   // flip the motion-blur frame target
    static bool FUN_1416ac2e0(NiRenderClick* pkClick, void* pvData);   // remember the view-projection matrix
    static void FUN_1416ac3b0(NiRenderTargetGroup* pkTarget);   // point the main scene clicks at a render target
    static egf::IBuiltinModel* FUN_1416aa1a0();     // "PlaneReflectionSetting" builtin model factory
    static bool FUN_1416abce0(bool bBeforeReset, void* pvData);   // device reset callback
    bool FUN_1416abd20(bool bBeforeReset);
    void FUN_1416a0fb0(int nEvent);                 // queue an event (13 = fade-in finished)
    NiRenderedTexture* FUN_1416a23f0(int nIndex);   // m_aspTextures[nIndex]
    void FUN_1416a7050();                           // create the MRT targets
    static void FUN_1416ac440(unsigned int uiWidth, unsigned int uiHeight);   // texel size + 9-tap blur offsets shader constants
    efd::SmartPointer<NiViewRenderClick> FUN_1416a8140();
    efd::SmartPointer<NiViewRenderClick> FUN_1416a8600();
    efd::SmartPointer<NiViewRenderClick> FUN_1416a8e50();
    efd::SmartPointer<NiViewRenderClick> FUN_1416a92e0();
    efd::SmartPointer<NiViewRenderClick> FUN_1416a97b0();
    efd::SmartPointer<NiViewRenderClick> FUN_1416a9a90();
    efd::SmartPointer<NiViewRenderClick> FUN_1416a9e20();
    void LinkEffects();                           // link the active effects into the post-process render step
    bool FUN_1416ac060(PostProcessEffect* pkEffect);   // (re)create the effect's output over the shared textures
    void FUN_1416abb30(NiTexture* pkTexture);       // copy the m_spTarget190 colour buffer into a texture
    static bool FUN_1416abac0(NiRenderStep* pkStep, void* pvData);   // post-processing callback: copy into the step's texture

    efd::SmartPointer<NiMaterial> m_aspMaterials[7];            // +0x30
    efd::map<NiNodePtr, int> m_kMap68;                          // +0x68 (only constructed / destroyed)
    efd::map<NiNodePtr, int> m_kMap78;                          // +0x78
    int m_iFrame;                                               // +0x88 (motion blur ping-pong frame)
    int m_aiRefCount[11];                                       // +0x8c
    efd::SmartPointer<NiViewRenderClick> m_aspClicks[11];       // +0xb8 (3 = mirrored, 7 = shimmer, 9 = outline)
    efd::SmartPointer<NiRenderedTexture> m_aspTextures[11];     // +0x110 (3/4: motion blur history)
    efd::SmartPointer<NiDefaultClickRenderStep> m_spMirroredStep;   // +0x168
    efd::SmartPointer<NiRenderTargetGroup> m_spTarget170;       // +0x170
    efd::SmartPointer<NiRenderTargetGroup> m_spTarget178;       // +0x178
    efd::SmartPointer<NiRenderTargetGroup> m_aspFrameTargets[2];    // +0x180 (indexed by m_iFrame)
    efd::SmartPointer<NiRenderTargetGroup> m_spTarget190;       // +0x190
    NiTList<int> m_kEvents;                                     // +0x198
    efd::SmartPointer<PostProcessSetting> m_spSetting;          // +0x1b8
    bool m_bMRT;                                                // +0x1c0
    bool m_bHDR;                                                // +0x1c1
    bool m_b1c2;                                                // +0x1c2 extra MRT targets
    bool m_b1c3;                                                // +0x1c3 float target format
    int m_nFormat;                                              // +0x1c4 (2, or 0xd with m_b1c3)
    efd::map<int, efd::SmartPointer<PostProcessEffect> > m_kSteps;  // +0x1c8
    Unk_AfterImageColor m_kBackground;                          // +0x1d8
    efd::SmartPointer<CPlaneReflectionSetting> m_spReflection;  // +0x1e8
    efd::SmartPointer<NiTextureEffect> m_spTextureEffect;       // +0x1f0
    efd::SmartPointer<NiRenderListProcessor> m_spProcessor;     // +0x1f8
    efd::SmartPointer<MS2TextureDensityProcessor> m_spDensity;  // +0x200
    efd::SmartPointer<CDepthOfFieldManager> m_spDoF;            // +0x208
    bool m_b210;                                                // +0x210 mirrored view active
};
MS2_CHECK_SIZE(PostProcessingService, 0x218);
MS2_CHECK_OFFSET(PostProcessingService, m_aspMaterials, 0x30);
MS2_CHECK_OFFSET(PostProcessingService, m_iFrame, 0x88);
MS2_CHECK_OFFSET(PostProcessingService, m_aspClicks, 0xb8);
MS2_CHECK_OFFSET(PostProcessingService, m_aspTextures, 0x110);
MS2_CHECK_OFFSET(PostProcessingService, m_kEvents, 0x198);
MS2_CHECK_OFFSET(PostProcessingService, m_bMRT, 0x1c0);
MS2_CHECK_OFFSET(PostProcessingService, m_kSteps, 0x1c8);
MS2_CHECK_OFFSET(PostProcessingService, m_kBackground, 0x1d8);
MS2_CHECK_OFFSET(PostProcessingService, m_b210, 0x210);
typedef PostProcessingService Unk_PPOwner;

// The service's shared targets passed to vfunc_15 as `b`: +8 the scene colour texture, +0x10 the depth texture.
struct Unk_PPTargets
{
    void* m_0;
    efd::SmartPointer<NiRenderedTexture> m_8;
    efd::SmartPointer<NiRenderedTexture> m_10;
};

class AntiAliasRenderStep : public PostProcessEffect {
public:
    AntiAliasRenderStep(unsigned __int64 a, unsigned int b);    // 0x14169d920
    virtual ~AntiAliasRenderStep();                             // 0x14169d9a0
    virtual const NiRTTI* GetRTTI() const;                      // 0x14169de50
    virtual bool vfunc_13();                                    // 0x14169de80
    virtual bool vfunc_14();                                    // 0x14169de70
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169d9d0
    static bool FUN_14169dbb0(NiRenderClick* pkClick, void* pvData);   // pre-render callback: texel offsets of the buffer

    static const NiRTTI ms_RTTI;                                // 0x143ae4558
};
MS2_CHECK_SIZE(AntiAliasRenderStep, 0xa0);

class BloomRenderStep : public PostProcessEffect {
public:
    BloomRenderStep(unsigned __int64 a, unsigned int b);        // 0x14169de90
    virtual ~BloomRenderStep();                                 // 0x14169df70
    virtual const NiRTTI* GetRTTI() const;                      // 0x14169f340
    virtual bool vfunc_13();                                    // 0x14169f360
    virtual bool vfunc_14();                                    // 0x14169f350
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169e000
    virtual void vfunc_16();                                    // 0x14169e9b0
    virtual void vfunc_21();                                    // 0x14169ea40

    static const NiRTTI ms_RTTI;                                // 0x143ae4568

    unsigned int m_a0;      // tick count when the targets were created
    efd::SmartPointer<NiRenderedTexture> m_a8;
    efd::SmartPointer<NiRenderedTexture> m_b0;
    efd::SmartPointer<NiRenderedTexture> m_b8[2];
};
MS2_CHECK_OFFSET(BloomRenderStep, m_b8, 0xb8);

class ColorPerspectiveRenderStep : public ReloadablePostProcess {
public:
    ColorPerspectiveRenderStep(unsigned __int64 a, unsigned int b);    // 0x14169f3a0
    // ~ColorPerspectiveRenderStep() implicit                   // 0x14169f6a0
    virtual const NiRTTI* GetRTTI() const;                      // 0x14169f850
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169f460
    virtual bool vfunc_23();                                    // 0x14169f500

    static const NiRTTI ms_RTTI;                                // 0x143ae4578

    efd::SmartPointer<NiRenderedTexture> m_b8;
};
MS2_CHECK_OFFSET(ColorPerspectiveRenderStep, m_b8, 0xb8);

class DepthOfFieldRenderStep : public PostProcessEffect {
public:
    DepthOfFieldRenderStep(unsigned __int64 a, unsigned int b); // 0x14169fd30
    virtual ~DepthOfFieldRenderStep();                          // 0x14169fe10
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a0a00
    virtual bool vfunc_13();                                    // 0x1416a0a20
    virtual bool vfunc_14();                                    // 0x1416a0a10
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169fe90
    virtual void vfunc_16();                                    // 0x1416a0930

    static const NiRTTI ms_RTTI;                                // 0x143ae4588

    efd::SmartPointer<NiRenderedTexture> m_a0;
    efd::SmartPointer<NiRenderedTexture> m_a8;
    efd::SmartPointer<NiRenderedTexture> m_b0;
    efd::SmartPointer<NiRenderedTexture> m_b8;
};
MS2_CHECK_OFFSET(DepthOfFieldRenderStep, m_b8, 0xb8);

class FadeInOutRenderStep : public PostProcessEffect {
public:
    FadeInOutRenderStep(unsigned __int64 a, unsigned int b);    // 0x1416a0a30
    virtual ~FadeInOutRenderStep();                             // 0x1416a0ab0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a0fe0
    virtual bool vfunc_13();                                    // 0x1416a1000
    virtual bool vfunc_14();                                    // 0x1416a0ff0
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a0b20
    static bool FUN_1416a0cd0(NiRenderClick* pkClick, void* pvData);   // pre-render callback: advance the fade, set the constant

    static const NiRTTI ms_RTTI;                                // 0x143ae45a8
    static float ms_fAlpha;                                     // 0x143ae4598
    static unsigned int ms_uiStartTime;                         // 0x143ae459c
    static int ms_iState;                                       // 0x143ae45a0 (0 fading in, 1 fading out, 2 idle)
    static int ms_iFadeOutTime;                                 // 0x143ae45b8 (initialised from DAT_1439f823c)
    static int ms_iFadeInTime;                                  // 0x143ae45bc (initialised from DAT_1439f8240)
};

class FadeInRenderStep : public PostProcessEffect {
public:
    FadeInRenderStep(unsigned __int64 a, unsigned int b);       // 0x1416a1010
    virtual ~FadeInRenderStep();                                // 0x1416a1090
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1380
    virtual bool vfunc_13();                                    // 0x1416a13a0
    virtual bool vfunc_14();                                    // 0x1416a1390
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a10c0
    static bool FUN_1416a1260(NiRenderClick* pkClick, void* pvData);   // pre-render callback: advance the fade-in

    static const NiRTTI ms_RTTI;                                // 0x143ae45c8
    static float ms_fAlpha;                                     // 0x143ae45c0
    static unsigned int ms_uiStartTime;                         // 0x143ae45c4
};

class GaussianBlurRenderStep : public PostProcessEffect {
public:
    GaussianBlurRenderStep(unsigned __int64 a, unsigned int b); // 0x1416a13b0
    virtual ~GaussianBlurRenderStep();                          // 0x1416a1450
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1960
    virtual bool vfunc_13();                                    // 0x1416a1980
    virtual bool vfunc_14();                                    // 0x1416a1970
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1490
    virtual void vfunc_16();                                    // 0x1416a1870
    virtual void vfunc_22();                                    // 0x1416a18b0

    static const NiRTTI ms_RTTI;                                // 0x143ae45d8

    efd::SmartPointer<NiRenderedTexture> m_a0;
};
MS2_CHECK_OFFSET(GaussianBlurRenderStep, m_a0, 0xa0);

class HeatShimmerRenderStep : public PostProcessEffect {
public:
    HeatShimmerRenderStep(unsigned __int64 a, unsigned int b);  // 0x1416a1990
    virtual ~HeatShimmerRenderStep();                           // 0x1416a1a10
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1c20
    virtual bool vfunc_13();                                    // 0x1416a1c40
    virtual bool vfunc_14();                                    // 0x1416a1c30
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1a40

    static const NiRTTI ms_RTTI;                                // 0x143ae45e8
};

class MonochromeRenderStep : public PostProcessEffect {
public:
    MonochromeRenderStep(unsigned __int64 a, unsigned int b);   // 0x1416a1c50
    virtual ~MonochromeRenderStep();                            // 0x1416a1cd0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1f00
    virtual bool vfunc_13();                                    // 0x1416a1f20
    virtual bool vfunc_14();                                    // 0x1416a1f10
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1d20

    static const NiRTTI ms_RTTI;                                // 0x143ae45f8
};

class MotionBlurRenderStep : public PostProcessEffect {
public:
    MotionBlurRenderStep(unsigned __int64 a, unsigned int b);   // 0x1416a1f30
    virtual ~MotionBlurRenderStep();                            // 0x1416a1fb0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a23e0
    virtual bool vfunc_13();                                    // 0x1416a2430
    virtual bool vfunc_14();                                    // 0x1416a2420
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1fe0
    static bool FUN_1416a21c0(NiRenderClick* pkClick, void* pvData);   // pre-render callback: bind the history textures

    static const NiRTTI ms_RTTI;                                // 0x143ae4610
    static NiTexturingProperty* ms_pkTexProp;                   // 0x143ae4608 (the screen quad's texturing property)
};

class OuterBlurRenderStep : public PostProcessEffect {
public:
    OuterBlurRenderStep(unsigned __int64 a, unsigned int b);    // 0x1416a2440
    virtual ~OuterBlurRenderStep();                             // 0x1416a24c0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a2560
    virtual bool vfunc_13();                                    // 0x1416a2580
    virtual bool vfunc_14();                                    // 0x1416a2570

    static const NiRTTI ms_RTTI;                                // 0x143ae4620
};

class OverdrawRenderStep : public ReloadablePostProcess {
public:
    OverdrawRenderStep(unsigned __int64 a, unsigned int b);     // 0x1416a2590
    // ~OverdrawRenderStep() implicit                           // 0x1416a27f0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a2870
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a2640
    virtual bool vfunc_23();                                    // 0x1416a2690

    static const NiRTTI ms_RTTI;                                // 0x143ae4630
};
