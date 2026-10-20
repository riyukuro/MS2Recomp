// gfxmoviedamage.h - GFxMovieDamage (RTTI .?AVGFxMovieDamage@@, 0x138 bytes, base GFxMovieEventHandler): the GFx movie of
// the damage numbers (movie id m_18 = 1). It owns the UIDamageText HUD (ui id 0x4e32) and the damage-number fonts: one
// UIDamageFont swf per font id, loaded on demand (m_90) or queued for a later load (m_d8, one per frame in vfunc_8).
// Fonts unused for 60 s are unloaded by FUN_140b61ce0. vftable 0x142ddf890, ctor 0x140b60ff0, dtor 0x140b610f0
// (scalar deleting 0x140b62e40). The names of the non-virtual members are not known.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxmovie.h"

class UIDamageFont;
class UIDamageText;

class GFxMovieDamage : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143abb060 ("GFxMovieDamage", parent GFxMovieEventHandler)

    GFxMovieDamage();                                               // 0x140b60ff0
    virtual ~GFxMovieDamage();                                      //  0 0x140b610f0 (scalar deleting 0x140b62e40)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }            //  2 0x140b634b0 (COMDAT)
    virtual void vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 4 0x140b61200
    virtual void vfunc_8(float fTime);                              //  8 0x140b617f0 advance; load one queued font
    virtual void vfunc_11();                                        // 11 0x140b61190 release the fonts and the HUD
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x140b617d0 returns 0

    bool FUN_140b61900(const CString& strFont);                     // load a font now (or refresh its time stamp)
    bool FUN_140b61b80(const CString& strFont);                     // queue a font unless loaded or queued
    void FUN_140b61ce0();                                           // GC the movie; unload the fonts unused for 60 s
    bool FUN_140b62010(const CString& strFont);                     // refresh a loaded font, else queue it
    bool FUN_140b621a0();                                           // reload the fonts saved by FUN_140b622b0
    void FUN_140b62270();                                           // in scene 0x620000c close the HUD (ui 0x4e32)
    void FUN_140b622b0();                                           // save the ids of the loaded fonts (s_arr)

    typedef ATL::CAtlMap<unsigned, MS2Ptr<UIDamageFont> > FontMap;
    FontMap m_90;                                                   // +0x90 the loaded fonts by font id
    FontMap m_d8;                                                   // +0xd8 the queued fonts
    CString m_120;                                                  // +0x120 the name of a movie that is not a font (never set here)
    MS2Ptr<UIDamageText> m_128;                                     // +0x128 the damage-number HUD
};
MS2_CHECK_SIZE(GFxMovieDamage, 0x138);
MS2_CHECK_OFFSET(GFxMovieDamage, m_d8, 0xd8);
MS2_CHECK_OFFSET(GFxMovieDamage, m_128, 0x128);
