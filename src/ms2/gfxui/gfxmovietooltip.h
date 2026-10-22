// gfxmovietooltip.h - GFxMovieTooltip (RTTI .?AVGFxMovieTooltip@@, 0xd0 bytes, base GFxMovieEventHandler): the GFx movie
// of the tooltip layer (movie id m_18 = 5). The other movies' "createTooltip" / "destroyTooltip" AS calls arrive through
// vfunc_3 with values of the calling movie; the two data objects are deep-copied into this movie (GFxObjectAdapter /
// GFxArrayAdapter, Scaleform value visitors) and forwarded to the TooltipManager clip (m_90), and the open tooltip ids are
// kept in m_a0. vftable 0x143117780. Name and directory of the header are assumed; the code is
// src/ms2/gfxui/gfxmovietooltip.cpp.
#pragma once

#include <atlcoll.h>

#include "ms2/placeholder/gfxmovie.h"

class ASUIComponent;

class GFxMovieTooltip : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143b0d7d0 (initializer in unit_14013acc0)

    GFxMovieTooltip();                                              // 0x1422f0900
    virtual ~GFxMovieTooltip();                                     //  0 0x1422f0980 (scalar deleting 0x1422f2260)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }            //  2 0x1422f2420 (COMDAT)
    virtual void vfunc_3(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   //  3 0x1422f0a90
    virtual void vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   //  4 0x1422f0d00
    virtual void vfunc_11();                                        // 11 0x1422f0a30 drop m_90 and the ids, then the base's
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422f0ea0 mouse

    int FUN_1422f1020();                                            // destroy every open tooltip; 0 if none was open
    // "createTooltip"(id, a, b): remember the id, call the TooltipManager clip
    void CreateTooltip(const Scaleform::GFx::Value& vId, const Scaleform::GFx::Value& vA, const Scaleform::GFx::Value& vB);
    void DestroyTooltip(const Scaleform::GFx::Value& vId);           // "destroyTooltip"(id)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASUIComponent> m_90;                                     // +0x90 "initializeClass" argument 0 (the TooltipManager clip)
    ATL::CAtlList<Scaleform::GFx::Value> m_a0;                      // +0xa0 ids of the open tooltips (block size 10)
};
MS2_CHECK_SIZE(GFxMovieTooltip, 0xd0);

// Deep copy of an AS object into a fresh object of another movie (Value::VisitMembers visitor). Strings are re-created
// in the target movie; nested objects and arrays recurse. RTTI .?AVGFxObjectAdapter@@, vftable 0x1431178c8.
class GFxObjectAdapter : public Scaleform::GFx::Value::ObjectVisitor
{
public:
    // 0x1422f1de0 (inline; the movie pointer is taken by value: the callee releases it)
    GFxObjectAdapter(Scaleform::Ptr<Scaleform::GFx::Movie> pMovie)
        : m_pMovie(pMovie)
    {
        if (m_pMovie)
            m_pMovie->CreateObject(&m_value);
    }
    virtual void Visit(const char* name, const Scaleform::GFx::Value& val);   // 2 0x1422f13b0

    Scaleform::GFx::Value m_value;                                  // +0x08 the copy
    Scaleform::Ptr<Scaleform::GFx::Movie> m_pMovie;                 // +0x28 the target movie
};
MS2_CHECK_SIZE(GFxObjectAdapter, 0x30);

// The same for an AS array (Value::VisitElements visitor). RTTI .?AVGFxArrayAdapter@@, vftable 0x1431178e8.
class GFxArrayAdapter : public Scaleform::GFx::Value::ArrayVisitor
{
public:
    // 0x1422f1d20 (inline)
    GFxArrayAdapter(Scaleform::Ptr<Scaleform::GFx::Movie> pMovie)
        : m_pMovie(pMovie)
    {
        if (m_pMovie)
            m_pMovie->CreateArray(&m_value);
    }
    virtual void Visit(unsigned idx, const Scaleform::GFx::Value& val);   // 1 0x1422f1760

    Scaleform::GFx::Value m_value;                                  // +0x08 the copy
    Scaleform::Ptr<Scaleform::GFx::Movie> m_pMovie;                 // +0x28 the target movie
};
MS2_CHECK_SIZE(GFxArrayAdapter, 0x30);
