// nigfxoverlayclick.h - NiGFxOverlayClick, GFxRenderer and AtlasRecord of the GFx UI library (?\nigfxoverlayclick.cpp,
// 0x142303440-0x142303963). Names from RTTI; header name, directory and member names assumed. NOT an original header.
#pragma once

#include <NiViewRenderClick.h>
#include <NiRefObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/casyncimageloader.h"
#include "GFxConfig.h"
#include "Render/Render_Types2D.h"

class Ni2DBuffer;
class Unk_GFxUIRenderer2D;                                          // ms2/placeholder/gfxrenderer2d.h

// The render click that draws the GFx UI overlay (0xd8 bytes, vftable 0x14311b658, 8 slots). ms_RTTI (0x143b0dc38,
// parent NiRenderClick) is initialized in unit_14013acc0's .text$di.
class NiGFxOverlayClick : public NiViewRenderClick
{
    NiDeclareRTTI;                                                  // GetRTTI 0x1423035d0
public:
    NiGFxOverlayClick();                                            // 0x142303440
    virtual ~NiGFxOverlayClick();                                   // 0x142303490 (scalar deleting 0x142303570)

    virtual unsigned int GetNumObjectsDrawn() const;                // 0x142303500 (always 1)
    virtual float GetCullTime() const;                              // 0x1423034d0 (always 0)
    virtual float GetRenderTime() const;                            // 0x1423034e0

    void FUN_1423035e0(void* p);                                    // 0x1423035e0 empty, unreferenced

    // protected in NiRenderClick; public here so the hook can bind it
    virtual void PerformRendering(unsigned int uiFrameID);          // 0x142303520: renders the GFx UI, times it

protected:
    float m_fUIRenderTime;                                          // +0xd0
};
MS2_CHECK_SIZE(NiGFxOverlayClick, 0xd8);

// The GFx render callback object (0x10 bytes, vftable 0x14311b6a0, 15 slots): every slot is a no-op stub. Created by
// GFxRenderSingleThread (0x1422f428c).
class GFxRenderer : public NiRefObject
{
public:
    GFxRenderer();                                                  // 0x142303600
    virtual ~GFxRenderer();                                         // 0x142303640 (scalar deleting 0x142303770)

    virtual Unk_GFxUIRenderer2D* vfunc_2();                         // 0x142303670 the Renderer2D
    virtual int vfunc_3();                                          // 0x142303680
    virtual int vfunc_4();                                          // 0x142303690
    virtual void vfunc_5();                                         // 0x1423036a0
    virtual void vfunc_6(void* p);                                  // 0x1423036b0
    virtual int vfunc_7();                                          // 0x1423036d0
    virtual void vfunc_8();                                         // 0x1423036e0
    virtual void vfunc_9(void* p);                                  // 0x1423036f0
    virtual void vfunc_10();                                        // 0x142303710
    virtual void vfunc_11();                                        // 0x142303720
    virtual bool vfunc_12();                                        // 0x142303730 (always true)
    virtual void vfunc_13(void* p);                                 // 0x142303740
    virtual Ni2DBuffer* vfunc_14();                                 // 0x142303760 the render texture's buffer
};
MS2_CHECK_SIZE(GFxRenderer, 0x10);

// An image of a texture atlas and its rect (0x28 bytes, vftable 0x14311b748). Created at 0x1422f7a22.
class AtlasRecord : public NiRefObject
{
public:
    explicit AtlasRecord(Unk_GfxImage* pImage);                     // 0x1423037d0
    // ~AtlasRecord() is implicit (COMDAT 0x142303890, scalar deleting 0x1423038c0)

    Unk_GfxImage* FUN_142303840();                                  // 0x142303840 the image

    Scaleform::Render::Rect<int> m_rect;                            // +0x10
    Unk_GfxRef m_spImage;                                           // +0x20 Scaleform::Ptr<Render::Image>
};
MS2_CHECK_SIZE(AtlasRecord, 0x28);
