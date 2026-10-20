// gfxmoviemousecursor.h - GFxMovieMouseCursor (RTTI .?AVGFxMovieMouseCursor@@, 0xa0 bytes, base GFxMovieEventHandler):
// the GFx movie of the mouse cursor layer (movie id m_18 = 6). Its "initializeClass" handler wraps the cursor clip in an
// ASMouseCursor (GFxMovie::m_30) and keeps the first argument's object in m_90; the AS calls "fireCursorEvent" /
// "setText" / "fireCursorMouseEvent" go to the cursor clip, and slots 19/20 switch the cursor mode. vftable 0x143117a50.
// Name and directory of the header are assumed; the code is src/ms2/gfxui/gfxmoviemousecursor.cpp.
#pragma once

#include "ms2/placeholder/gfxmovie.h"

class ASMouseCursor;
class ASUIComponent;

class GFxMovieMouseCursor : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143b0d7e0 (initializer in unit_14013acc0)

    GFxMovieMouseCursor();                                          // 0x1422f2600
    virtual ~GFxMovieMouseCursor();                                 //  0 0x1422f2660 (scalar deleting 0x1422f3040)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }            //  2 0x1422f30a0 (COMDAT)
    virtual void vfunc_3(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   //  3 0x1422f2730
    virtual void vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   //  4 0x1422f2a50
    virtual void vfunc_5(bool b);                                   //  5 0x1422f2e40
    virtual void vfunc_11();                                        // 11 0x1422f26e0 drop m_90, then the base's
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422f2bd0
    virtual void vfunc_19(void* hwnd);                              // 19 0x1422f2e90 cursor mode 1 (the AS clip)
    virtual void vfunc_20(void* hwnd);                              // 20 0x1422f2ee0 cursor mode 2 (the system cursor)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASUIComponent> m_90;                                     // +0x90 "initializeClass" argument 0
};
MS2_CHECK_SIZE(GFxMovieMouseCursor, 0xa0);

// new ASMouseCursor(v, nMovieId) in an MS2Ptr (COMDAT 0x1422f2f30, same shape as gfxmovie.h's FUN_140b62400)
MS2Ptr<ASMouseCursor> FUN_1422f2f30(int nMovieId, const Scaleform::GFx::Value& v);
