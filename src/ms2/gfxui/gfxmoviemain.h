// gfxmoviemain.h - GFxMovieMain (RTTI .?AVGFxMovieMain@@, 0x98 bytes, base GFxMovieEventHandler): the main GFx UI movie
// (movie id m_18 = 2). It handles the AS events of the main swf ("Main" class members, "Tooltip"/"MouseCursor"
// forwarding to movies 5/6, "VideoPlayer" status, swf "loadInit"/"loadComplete"/"playSound" and the event dispatch
// to the swf entities) and forwards the mouse events to UISwfEntityManager. vftable 0x143117380 (40 slots).
// Recovered with ?\gfxmoviemain.cpp (0x1422ef250-0x1422f0900); header name and directory assumed.
#pragma once

#include "ms2/placeholder/gfxmovie.h"

class GFxMovieMain : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143b0d7c0 (initializer in unit_14013acc0)

    GFxMovieMain();                                                 // 0x1422ef250
    virtual ~GFxMovieMain();                                        //  0 0x1422ef2a0 (scalar deleting 0x1422f0890)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }             //  2 0x1422f08f0 (COMDAT)
    virtual void vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 4 0x1422ef3c0
    virtual void vfunc_5(bool bShow);                               //  5 0x1422effa0 "setVisibleStep" on the loader
    virtual int vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags);   // 6 0x1422ef2d0 load + SetFocus
    virtual void vfunc_8(float fTime);                              //  8 0x1422f0040
    virtual void vfunc_17(void* hwnd);                              // 17 0x1422f0070 + clipboard viewer
    virtual void vfunc_26(void* hwnd, float x, float y);            // 26 0x1422f00b0
    virtual void vfunc_30(void* hwnd, float x, float y, float fDelta);     // 30 0x1422f0120
    virtual void vfunc_31(void* hwnd, float x, float y);            // 31 0x1422f01b0
    virtual void vfunc_32(void* hwnd, float x, float y);            // 32 0x1422f0220
    virtual void vfunc_33(void* hwnd, float x, float y);            // 33 0x1422f0290
    virtual void vfunc_34(void* hwnd, float x, float y);            // 34 0x1422f0300
    virtual void vfunc_35(void* hwnd, float x, float y);            // 35 0x1422f0370
    virtual void vfunc_36(void* hwnd, float x, float y);            // 36 0x1422f03e0

    bool FUN_1422f0450();                                           // 0x1422f0450 m_90: "classMemberSendToClient" received

    bool m_90;                                                      // +0x90 ctor/vfunc_6 false
};
MS2_CHECK_SIZE(GFxMovieMain, 0x98);
MS2_CHECK_OFFSET(GFxMovieMain, m_90, 0x90);
