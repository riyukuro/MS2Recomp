// RenderedTextureRenderClick: NiViewRenderClick subclass that renders a view into an offscreen texture (0xf8 bytes).
// The engine base (NiViewRenderClick, 0xd0 bytes) comes from the real Gamebryo headers. The three smart-pointer members are
// kept opaque (their NiPointer helpers are separate out-of-line functions in the exe, called through FUN_ externs).
#pragma once
#include "ms2/ms2layout.h"
#include <NiViewRenderClick.h>

class RenderedTextureRenderClick : public NiViewRenderClick {
public:
    RenderedTextureRenderClick();                       // 0x1416f8f50
    virtual ~RenderedTextureRenderClick();              // 0x1416f9070 (+ sdd 0x1416fa1a0)
    virtual void vfunc_8(unsigned w, unsigned h);       // 0x1416f9130  create view + culling process
    virtual void vfunc_9();                             // 0x1416f9400
    virtual void vfunc_10();                            // 0x1416f94c0
    virtual void vfunc_11();                            // 0x1416f9580
    virtual void vfunc_12(void* a);                     // 0x1416f96d0
    virtual void vfunc_13(void* a);                     // 0x1416f9730
    virtual void vfunc_14();                            // 0x1416f9790
    virtual void vfunc_15(char bFree);                  // 0x1416f9890
    virtual void vfunc_16();                            // 0x1416f99b0
protected:
    virtual void PerformRendering(unsigned int uiFrameID);  // 0x1416f9d40
public:
    unsigned m_uiWidth;     // +0xd0
    unsigned m_uiHeight;    // +0xd4
    void* m_spView;         // +0xd8  NiPointer<Ni3DRenderView>
    void* m_spTexture;      // +0xe0  NiPointer<NiRenderedTexture>
    void* m_spTarget;       // +0xe8  NiPointer<NiRenderTargetGroup>
    int m_iEventId;         // +0xf0

    class NiRenderedTexture* FUN_1416f9ab0();           // 0x1416f9ab0 the rendered texture (member of ?\uirenderview.cpp's callers)
    void FUN_1416f99d0(class NiCamera* pCamera);        // 0x1416f99d0 sets the camera of the view
    unsigned GetWidth() const { return m_uiWidth; }     // 0x141ab8580 (COMDAT of ?\uirenderview.cpp)
    unsigned GetHeight() const { return m_uiHeight; }   // 0x141ab8550
};
MS2_CHECK_SIZE(RenderedTextureRenderClick, 0xf8);
