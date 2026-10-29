// afterimageitem.h - the after-image trail effect at run time: CAfterImageEffect (the effect object, built from a
// CAfterImageEffectParam) spawns AfterImageItem snapshots (a billboard quad textured with a copy of the owner's render
// target that fades out), and CAfterImageEffectManager (singleton) owns the offscreen render click that fills the
// snapshot texture. Owning unit: ?\afterimageitem.cpp (0x14097c1f0-0x140987430). Names assumed from the RTTI / effect XML
// type; member names are invented from use.
#pragma once
#include "ms2/ms2layout.h"
#include <afx.h>
#include <list>
#include <vector>
#include <NiSmartPointer.h>
#include <NiPoint3.h>
#include <NiColor.h>
#include <NiBillboardNode.h>
#include <NiMeshScreenElements.h>
#include <NiDynamicTexture.h>
#include <NiRenderClick.h>
#include <set>
#include <NiTexture.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/afterimageeffectparam.h"
#include "ms2/client/ms2/renderedtexturerenderclick.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"

// Screen rectangle (left, right, top, bottom); the same struct as in fielddatacli.h.
struct Unk_Rect4 { Unk_Rect4(float l, float r, float t, float b); float l, r, t, b; };   // ctor 0x14097eac0

class AfterImageItem;
typedef MS2Ptr<AfterImageItem> AfterImageItemPtr;
typedef efd::SmartPointer<NiBillboardNode> NiBillboardNodePtr;
typedef efd::SmartPointer<RenderedTextureRenderClick> RenderedTextureClickPtr;
typedef efd::SmartPointer<NiMeshScreenElements> NiMeshScreenElementsPtr;

// One snapshot of the trail (0x68 bytes). vftable 0x142ee..., dtor 0x14097f600, ??_G 0x14097fe80.
class AfterImageItem : public CPtred
{
public:
    AfterImageItem();                                               // 0x14097c1f0
    virtual ~AfterImageItem() = default;                            // 0x14097f600 (no vptr store), ??_G 0x14097fe80
    // Take the snapshot: build the quad (a billboard facing the camera at kPos, fSize wide) textured with spTexture
    // and tinted with the param's colour; nLife is the lifetime in ms.
    void Init(Unk_AfterImageRef kParam, NiDynamicTexturePtr spTexture, const NiPoint3& kPos, float fSize,
              unsigned nLife);                                      // 0x14097c2d0
    void Release();                                                 // 0x14097c6d0 detach the node from the scene
    void UpdateColor();                                             // 0x14097c7a0 fade the colour with the age
    bool IsExpired() const;                                         // 0x14097c890
    NiDynamicTexturePtr GetTexture() const;                        // 0x14097c8e0
    // The quad: a fSize x fSize screen element (centred on the pivot), textured, with the alpha / z-buffer /
    // vertex-colour properties of the additive or the alpha-blended mode.
    static NiMeshScreenElementsPtr CreateQuad(NiTexturePtr spTexture, float fSize, NiTexturePtr spMask,
                                              const NiColorA& kColor, bool bLighten);   // 0x14097c930
public:
    MS2_LAYOUT_FRIEND;
    Unk_AfterImageRef m_kParam;                                     // +0x18
    NiDynamicTexturePtr m_spTexture;                               // +0x28
    NiBillboardNodePtr m_spNode;                                    // +0x30
    NiMeshScreenElementsPtr m_spMesh;                               // +0x38
    efd::Point3 m_kOffset;                                          // +0x40
    float m_fSize;                                                  // +0x4c
    Unk_AfterImageColor m_kColor;                                   // +0x50 the param's colour
    unsigned m_nBirth;                                              // +0x60 tick count of the snapshot
    unsigned m_nLife;                                               // +0x64 lifetime in ms
};
MS2_CHECK_SIZE(AfterImageItem, 0x68);
MS2_CHECK_OFFSET(AfterImageItem, m_kParam, 0x18);
MS2_CHECK_OFFSET(AfterImageItem, m_spMesh, 0x38);
MS2_CHECK_OFFSET(AfterImageItem, m_kColor, 0x50);
MS2_CHECK_OFFSET(AfterImageItem, m_nLife, 0x64);

// 0x98 bytes; the runtime effect. vftable 0x142ee..., dtor 0x14097d100, ??_G 0x14097fec0. RTTI "CAfterImageEffect".
class CAfterImageEffect : public CEffect
{
    NiDeclareRTTI;                                                  // 2 GetRTTI 0x140980390
public:
    CAfterImageEffect(Unk_AfterImageRef kRef);                      // 0x14097d000
    virtual ~CAfterImageEffect();                                   // 0x14097d100
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x14097d160
    virtual void vfunc_4();                                         // 4 0x14097d3b0 register with the manager
    virtual void vfunc_7();                                         // 7 0x14097d430 unregister
    virtual int vfunc_8(void* p);                                   // 8 0x14097d4d0 return 1
    virtual bool vfunc_9();                                         // 9 0x14097d1e0 per-update
    virtual void vfunc_10(bool b);                                  // 10 0x14097d4c0 {}
    virtual int vfunc_12();                                         // 12 0x140980370 effect type 0x16

    void Capture(RenderedTextureClickPtr spClick);   // 0x14097d4f0 snapshot the render target
    NiAVObjectPtr GetTarget() const;                                // 0x14097df60
    bool IsTimeUp() const;                                          // 0x14097d8b0
    bool ShouldCapture();                                           // 0x14097d960
    void StartCapture();                                            // 0x14097db30 note the owner pose, project the bound
public:
    MS2_LAYOUT_FRIEND;
    Unk_AfterImageRef m_kParam;                                     // +0x30
    int m_nTarget;                                                  // +0x40 the owner's id
    NiAVObjectPtr m_spTarget;                                       // +0x48 the owner's scene node
    std::vector<AfterImageItemPtr> m_vecItems;                      // +0x50 live snapshots
    unsigned m_nLastCapture;                                        // +0x68 tick count of the last snapshot
    int m_unk_6c;                                                   // +0x6c
    Unk_Rect4 m_rcScreen;                                           // +0x70 screen rect of the owner
    NiPoint3 m_kPos;                                                // +0x80 owner position at the last capture
    float m_fRadius;                                                // +0x8c bound radius
    bool m_bPending;                                                // +0x90 a capture is wanted
};
MS2_CHECK_SIZE(CAfterImageEffect, 0x98);
MS2_CHECK_OFFSET(CAfterImageEffect, m_kParam, 0x30);
MS2_CHECK_OFFSET(CAfterImageEffect, m_vecItems, 0x50);
MS2_CHECK_OFFSET(CAfterImageEffect, m_rcScreen, 0x70);
MS2_CHECK_OFFSET(CAfterImageEffect, m_bPending, 0x90);

// The afterimage render list processor (the ctor is recovered with ?\ms2renderlistprocessor.cpp).
class MS2AfterImageRenderListProcessor : public MS2RenderListProcessor
{
public:
    MS2AfterImageRenderListProcessor();                             // 0x1414dec90
};

class CAfterImageEffectManager;
template <class T> class TSingleton;
template <> class TSingleton<CAfterImageEffectManager>
{
public:
    TSingleton();                                                   // 0x140984130
    virtual ~TSingleton();                                          // 0x140984480, ??_G 0x140984f90
    static CAfterImageEffectManager* GetInstance();                 // 0x140980380
    static CAfterImageEffectManager* CreateInstance();              // 0x140980250 the instance, created on first use
    static void DestroyInstance();                                  // 0x1409802d0
    static CAfterImageEffectManager* s_instance;                    // 0x143ab3b58
};

// 0x38 bytes. vftable 0x142ee..., dtor 0x140981d50, ??_G 0x140984fd0. Owns the offscreen click that renders the owners of
// the live effects, one per frame (the click's pre/post callbacks pick the next effect and hand it the finished frame).
class CAfterImageEffectManager : public TSingleton<CAfterImageEffectManager>
{
public:
    CAfterImageEffectManager();                                     // 0x140981cc0
    virtual ~CAfterImageEffectManager();                            // 0x140981d50
    void CreateClick();                                             // 0x140981e30
    void AddEffect(CEffectPtr spEffect);                            // 0x140982030
    void RemoveEffect(CEffectPtr spEffect);                         // 0x140982080
    bool IsIdle() const;                                            // 0x1409820d0 no effect is registered
    void Process(CEffectPtr spEffect);                              // 0x140982100 hand the finished frame to the effect
    void RenderNext();                                              // 0x140982390 begin the capture of the selected effect
    bool SelectNext();                                              // 0x1409821b0 pick the next effect due a snapshot
    NiDynamicTexturePtr GetTexture();                               // 0x140982460 a pooled or new 256x256 texture
    void ReleaseTexture(NiDynamicTexturePtr spTexture);             // 0x140982580 (invented name) return a texture to the pool
public:
    MS2_LAYOUT_FRIEND;
    RenderedTextureClickPtr m_spClick;                              // +0x08
    std::set<NiDynamicTexturePtr> m_setTextures;                    // +0x10 free textures
    std::set<CEffectPtr> m_setEffects;                              // +0x20 registered effects
    CEffectPtr m_spCurrent;                                         // +0x30 the effect being captured
};
MS2_CHECK_SIZE(CAfterImageEffectManager, 0x38);
MS2_CHECK_OFFSET(CAfterImageEffectManager, m_setTextures, 0x10);
MS2_CHECK_OFFSET(CAfterImageEffectManager, m_spCurrent, 0x30);
