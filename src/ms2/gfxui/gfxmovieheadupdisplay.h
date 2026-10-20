// gfxmovieheadupdisplay.h - GFxMovieHeadUpDisplay (RTTI .?AVGFxMovieHeadUpDisplay@@, 0x90 bytes, base GFxMovieEventHandler):
// the GFx movie of the head-up display layer (movie id m_18 = 0). It adds no members; it handles the AS callbacks
// ("initializeClass", the swf "loadInit"/"loadComplete"/"playSound" notifications and the event dispatch to the swf
// entities) and the mouse messages. vftable 0x143117c70. Name and directory of the header are assumed.
#pragma once

#include "ms2/placeholder/gfxmovie.h"

class GFxMovieHeadUpDisplay : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143b0d7f0 (initializer in unit_14013acc0)

    GFxMovieHeadUpDisplay();                                        // 0x1422f30b0
    virtual ~GFxMovieHeadUpDisplay();                               //  0 0x1422f30f0 (scalar deleting 0x1422f3920)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }            //  2 0x1422f3980 (COMDAT)
    virtual void vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 4 0x1422f3120
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422f37a0 mouse
};
MS2_CHECK_SIZE(GFxMovieHeadUpDisplay, 0x90);
