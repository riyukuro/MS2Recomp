// uirenderview.h - UIRenderView (RTTI .?AVUIRenderView@@): the offscreen 3D view that the UI draws into a swf image
// (NiRefObject + ecr::IRenderServiceDelegate, 0x60 bytes). It owns a camera, two lights, a RenderedTextureRenderClick
// that renders the effect root into a texture, and the scene graph handle of that root. UIModelView (uimodelview.h) is
// its only subclass. Unit `?\uirenderview.cpp` (.text$mn 0x141ab6f50-0x141ab8920); every member name except the RTTI
// class names is invented from its use.
//
// Virtual slots (primary vftable 0x142f26cb8-ish: see the unit; the secondary ecr::IRenderServiceDelegate vftable follows):
//   0 dtor  1 DeleteThis  2 pre-draw tick  3 post-draw tick (marks the texture dirty)  4 refresh  5..9 camera controls
//   (no-ops here, UIModelView overrides them)  10 set the object id  11 (no-op)  12 show nodes  13 set the camera
//   14 create lights  15 create camera  16 create the render click
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/tptr.h"

#include <atlcoll.h>
#include <NiCamera.h>
#include <NiLight.h>
#include <NiAmbientLight.h>
#include <NiDirectionalLight.h>
#include <NiNode.h>
#include <ecr/IRenderServiceDelegate.h>
#include <efd/SmartPointer.h>

#include "ms2/client/ms2/renderedtexturerenderclick.h"

class GameObject;
class NiActorManager;
class NiRenderedTexture;
class NiRenderTargetGroup;
class Unk_UISwfEntity_25;
class Unk_ModelViewCamera;
struct Unk_ScreenPoint { float x, y; };   // a point in the texture (pixels)

class UIRenderView : public NiRefObject, public ecr::IRenderServiceDelegate
{
public:
    UIRenderView(unsigned int uiWidth, unsigned int uiHeight, GameObject* pObject, float fLightDimmer);   // 0x141ab7a20
    virtual ~UIRenderView();                                // 0x141ab6f50 (scalar deleting 0x141ab84f0)

    virtual void vfunc_2();                                 // 2 0x141ab7490 before the click draws
    virtual void vfunc_3();                                 // 3 0x141ab74a0 after the click drew: the texture is dirty
    virtual void vfunc_4();                                 // 4 0x141ab74c0 refresh the click
    virtual void vfunc_5(float fStep);                      // 5 0x141ab7510 zoom in
    virtual void vfunc_6(float fStep);                      // 6 0x141ab7530 zoom out
    virtual void vfunc_7(float fX, float fY, float fZ);     // 7 0x141ab7550 rotate the camera
    virtual void vfunc_8(float fDist);                      // 8 0x141ab7570 set the near limit
    virtual void vfunc_9(float fDist);                      // 9 0x141ab7590 set the far limit
    virtual void vfunc_10(int nObjectId);                   // 10 0x141ab75b0
    virtual void vfunc_11(ATL::CAtlArray<efd::SmartPointer<NiActorManager> >& arrActors);   // 11 0x141ab7620 show actors (UIPortrait)
    virtual void vfunc_12(const ATL::CAtlArray<NiNode*>& arrNodes, NiNodePtr spRoot);   // 12 0x141ab75f0
    virtual int vfunc_13(const Unk_ModelViewCamera& kCamera);   // 13 0x141ab7640
    virtual int vfunc_14();                                 // 14 0x141ab7bb0 create the lights
    virtual int vfunc_15();                                 // 15 0x141ab7bc0 create the camera
    virtual int vfunc_16();                                 // 16 0x141ab7bd0 create the render click

    // ecr::IRenderServiceDelegate
    virtual void OnSurfacePreDraw(ecr::RenderService* pService, ecr::RenderSurface* pSurface);    // 0x141ab7fd0
    virtual void OnSurfacePostDraw(ecr::RenderService* pService, ecr::RenderSurface* pSurface);   // 0x141ab8040

    NiRenderedTexture* FUN_141ab73f0();                     // the click's rendered texture (NULL without a click)
    NiRenderTargetGroup* FUN_141ab7440();                   // the click's render target group (NULL without a click)
    int GetDirty();                                    // m_nDirty
    NiNode* GetEffectRoot();                                // the effect root
    bool FUN_141ab76b0(const efd::Point3& kWorld, Unk_ScreenPoint* pScreen);   // world point -> pixels in the texture
    bool FUN_141ab7870(CStringW strPath, int nFormat);       // saves the texture to a file
    void FUN_141ab7b80(int nValue);                         // updates the global shader constant

protected:
    efd::SmartPointer<NiCamera> m_spCamera;                 // +0x18
    unsigned int m_uiWidth;                                 // +0x20
    unsigned int m_uiHeight;                                // +0x24
    float m_fLightDimmer;                                   // +0x28
    int m_nObjectId;                                        // +0x2c id of the GameObject shown (0 = none)
    efd::SmartPointer<NiAmbientLight> m_spAmbientLight;     // +0x30
    efd::SmartPointer<NiDirectionalLight> m_spDirLight;     // +0x38
    efd::SmartPointer<RenderedTextureRenderClick> m_spClick;   // +0x40
    int m_nDirty;                                           // +0x48
    NiNodePtr m_spEffectRoot;                               // +0x50 "UI Effect Root"
    unsigned int m_uiSceneHandle;                           // +0x58 ecr::SceneGraphService handle of the effect root
};
MS2_CHECK_SIZE(UIRenderView, 0x60);
