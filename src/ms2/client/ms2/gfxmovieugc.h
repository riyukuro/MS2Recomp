// gfxmovieugc.h - GFxMovieUgc (RTTI .?AVGFxMovieUgc@@, 0xc0 bytes, base GFxMovieEventHandler): a Scaleform movie drawn into
// a render texture that becomes the base (decal-cleared) texture of a scene object (UGC pictures on items/blocks). The
// render chain is the one of GFxMovieBackground (gfxmoviebackground.h) without the logging and the screen view:
// CreateRenderTexture (FUN_14127dd70, a square texture of the UGC texture size), CreateRenderTarget (FUN_14127dc60, the
// GFx HAL target over the texture's D3D surface) and SetBaseTexture (FUN_14127de50). vftable 0x142ecf758 (42 slots,
// 40/41 new: SetFocus/KillFocus), ctor 0x14127d290, dtor 0x14127d360 (scalar deleting 0x14127e000).
#pragma once

#include <efd/SmartPointer.h>
#include <NiAVObject.h>
#include <NiRenderedTexture.h>

#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/client/ms2/gfxmoviebackground.h"     // Unk_BgComPtr<Unk_BgTarget> (the GFx HAL render target)

class GFxMovieUgc : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143ad6338 ("GFxMovieUgc", parent GFxMovieEventHandler)

    GFxMovieUgc(NiAVObject* pObject, CString strName);              // 0x14127d290 (the CString by value)
    virtual ~GFxMovieUgc();                                         //  0 0x14127d360 (scalar deleting 0x14127e000)
    virtual void* vfunc_2();                                        //  2 0x14127e060 returns &ms_RTTI
    virtual void vfunc_4(void* pUnused, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 4 0x14127d4b0 (empty)
    virtual int vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags);   // 6 0x14127d4d0 load + build the render chain
    virtual int vfunc_7(int x, int y);                              //  7 0x14127d640 viewport + mouse move
    virtual void vfunc_9(MS2_GFX_PTR(Unk_GFxHandleObj) spObj, MS2_GFX_PTR(Unk_GFxHandleObj) spHandle);   // 9 0x14127d720 render into the target
    virtual void vfunc_11();                                        // 11 0x14127d900 release everything
    virtual void vfunc_12();                                        // 12 0x14127d9d0 device lost: clear the texture, drop the target
    virtual bool vfunc_13();                                        // 13 0x14127da50 device reset: rebuild the chain
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x14127dbc0 (base)
    virtual void vfunc_39(int a, int b, int c, bool d, bool e);     // 39 0x14127dc10 (base)
    virtual void vfunc_40();                                        // 40 0x14127dad0 SetFocusEvent
    virtual void vfunc_41();                                        // 41 0x14127db60 KillFocus event

    int FUN_14127dc60();                                            // CreateRenderTarget
    int FUN_14127dd70();                                            // CreateRenderTexture
    int FUN_14127de50(NiRenderedTexture* pTexture);                 // SetBaseTexture (of m_spObject)

public:
    CString m_strName;                                              // +0x90
    efd::SmartPointer<NiAVObject> m_spObject;                       // +0x98 the object that shows the movie
    MS2Ptr<ASUIComponent> m_spComponent;                            // +0xa0 (only reset here)
    efd::SmartPointer<NiRenderedTexture> m_spRenderTexture;         // +0xb0
    Unk_BgComPtr<Unk_BgTarget> m_spRenderTarget;                    // +0xb8
};
MS2_CHECK_SIZE(GFxMovieUgc, 0xc0);
MS2_CHECK_OFFSET(GFxMovieUgc, m_spObject, 0x98);
MS2_CHECK_OFFSET(GFxMovieUgc, m_spRenderTexture, 0xb0);
MS2_CHECK_OFFSET(GFxMovieUgc, m_spRenderTarget, 0xb8);
