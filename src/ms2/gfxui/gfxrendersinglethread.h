// gfxrendersinglethread.h - GFxRenderSingleThread (RTTI .?AVGFxRenderSingleThread@@ : GFxRenderer : NiRefObject, 0x80
// bytes, vftable 0x1431181b8, 15 slots), the single-threaded Scaleform renderer of the GFx UI library: it owns the D3D9 HAL
// and the Renderer2D, saves/restores the device state around the UI frame with a state block and draws the UI from a
// "ScaleformStep" render step of the main render frame. Created by GFxManager (0x1422b1750). Header name, directory and
// member names assumed ("m_renderHAL" and "CreateRenderTexture()" come from the reset error strings). NOT an original header.
#pragma once

#include <d3d9.h>
#include <NiRenderedTexture.h>
#include <NiDefaultClickRenderStep.h>

#include "Kernel/SF_RefCount.h"

#include "ms2/ms2layout.h"
#include "ms2/gfxui/nigfxoverlayclick.h"
#include "ms2/placeholder/gfxrenderer2d.h"

class NiRenderer;
class NiRenderClick;

class GFxRenderSingleThread : public GFxRenderer
{
public:
    explicit GFxRenderSingleThread(NiRenderer* pRenderer);          // 0x1422f4270
    virtual ~GFxRenderSingleThread();                               // 0x1422f4360 (scalar deleting 0x1422f57e0)

    virtual Unk_GFxUIRenderer2D* vfunc_2();                         //  2 0x1422f4470 the Renderer2D
    virtual int vfunc_3();                                          //  3 0x1422f44a0 init: HAL, Renderer2D, glyph cache, state block, render step
    virtual int vfunc_4();                                          //  4 0x1422f4740 begin frame (captures the device state)
    virtual void vfunc_5();                                         //  5 0x1422f47d0 end frame (restores the device state)
    virtual void vfunc_6(void* pMovie);                             //  6 0x1422f4860 hands the HAL and the Renderer2D to a movie
    virtual int vfunc_7();                                          //  7 0x1422f4920 tick count of the frame
    virtual void vfunc_8();                                         //  8 0x1422f4960 frame advanced
    virtual void vfunc_9(void* pMovie);                             //  9 0x1422f4980 advances a movie by the elapsed time (max 1s)
    virtual void vfunc_10();                                        // 10 0x1422f4a10 shutdown
    virtual void vfunc_11();                                        // 11 0x1422f4a70 device lost
    virtual bool vfunc_12();                                        // 12 0x1422f4af0 device reset (throws 0xd on failure)
    virtual void vfunc_13(void* p);                                 // 13 0x1422f4c40 (empty)
    virtual Ni2DBuffer* vfunc_14();                                 // 14 0x1422f4c60 the render texture's buffer

    int FUN_1422f4cc0();                                            // 0x1422f4cc0 builds the "ScaleformStep" render step
    int FUN_1422f4f00();                                            // 0x1422f4f00 removes it
    int FUN_1422f4fd0();                                            // 0x1422f4fd0 CreateRenderTexture(): back buffer sized texture
    // 0x1422f50d0 pre-processing callback of the "ScaleformRC" click (pData = the renderer): copies the current back
    // buffer into the render texture
    static bool FUN_1422f50d0(NiRenderClick* pClick, void* pData);

private:
    MS2_LAYOUT_FRIEND;
    DWORD m_dwTick;                                                 // +0x10 GetTickCount of the current frame
    int m_14;
    DWORD m_dwLastTick;                                             // +0x18 tick of the last advanced frame
    NiRenderer* m_pRenderer;                                        // +0x20
    Scaleform::Ptr<Unk_GFxUIHal> m_renderHAL;                       // +0x28
    Scaleform::Ptr<Unk_GFxUIRenderer2D> m_spRenderer2D;             // +0x30
    Scaleform::Ptr<IDirect3DStateBlock9> m_spStateBlock;            // +0x38 D3DSBT_ALL
    NiRenderedTexturePtr m_spRenderTexture;                         // +0x40
    NiDefaultClickRenderStepPtr m_spRenderStep;                     // +0x48 "ScaleformStep"
    void* m_50;                                                     // +0x50 always 0
    char m_pad_58[0x80 - 0x58];                                     // never touched by the class's code
};
MS2_CHECK_SIZE(GFxRenderSingleThread, 0x80);
MS2_CHECK_OFFSET(GFxRenderSingleThread, m_renderHAL, 0x28);
MS2_CHECK_OFFSET(GFxRenderSingleThread, m_spRenderStep, 0x48);
