// gfxmoviepostdisplay.h - GFxMoviePostDisplay (RTTI .?AVGFxMoviePostDisplay@@, 0x90 bytes, base GFxMovieEventHandler):
// the GFx movie drawn after the scene (movie id m_18 = 3); a copy of GFxMovieHeadUpDisplay. It adds no members; it handles the AS callbacks
// ("initializeClass", the swf "loadInit"/"loadComplete"/"playSound" notifications and the event dispatch to the swf
// entities) and the mouse messages. vftable 0x143117e90. Name and directory of the header are assumed.
#pragma once

#include "ms2/placeholder/gfxmovie.h"

class GFxMoviePostDisplay : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143b0d800 (initializer in unit_14013acc0)

    GFxMoviePostDisplay();                                        // 0x1422f3990
    virtual ~GFxMoviePostDisplay();                               //  0 0x1422f39d0 (scalar deleting 0x1422f4200)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }            //  2 0x1422f4260 (COMDAT)
    virtual void vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 4 0x1422f3a00
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422f4080 mouse
};
MS2_CHECK_SIZE(GFxMoviePostDisplay, 0x90);
