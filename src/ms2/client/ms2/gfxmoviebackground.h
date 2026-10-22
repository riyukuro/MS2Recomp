// gfxmoviebackground.h - GFxMovieBackground (RTTI .?AVGFxMovieBackground@@, 0xe8 bytes, base GFxMovieEventHandler): the Scaleform
// movie that paints a full-screen background (a "BG" swf/png/dds) into a render texture and shows it through a
// NiScreenFillingRenderView appended to the "SceneGraphClick" of the default click render step. It also owns the optional
// minimap viewport that projects the player position onto the background ("updatePos").
#pragma once

#include <efd/SmartPointer.h>
#include <NiRenderedTexture.h>
#include <NiScreenFillingRenderView.h>
#include <NiRTTI.h>

#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/ascript.h"

class MinimapViewport;                  // ?\minimapviewport.cpp, 0x90 bytes, base NiRefObject (ctor 0x1414856d0)

// The render target the movie draws into: a COM-style object (AddRef at vtable +8, Release at +0x10) created by the GFx
// renderer HAL (vtable +0x218 of FUN_1422cf060()).
class Unk_BgTarget
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();             // AddRef
    virtual void vfunc_2();             // Release
};

// Scaleform-style intrusive pointer to a COM-style object (the exe keeps one extra reference and drops it by hand).
template <class T>
class Unk_BgComPtr
{
public:
    Unk_BgComPtr();
    Unk_BgComPtr(T* p);                 // 0x14127c1a0
    ~Unk_BgComPtr();                    // 0x14127c580
    Unk_BgComPtr& operator=(T* p);      // 0x14127c6b0
    operator T*() const;                // 0x14127c920
    T* operator->() const;              // 0x14127c970
private:
    T* m_p;
};

// The overlay object at +0xd0 (never created by this unit); slot 2 destroys it.
class Unk_BgOverlay
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

class GFxMovieBackground : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;                                            // 0x1400ebd60

    GFxMovieBackground(const CString& strBg, unsigned nCameraFlag, unsigned nPosFlag);   // 0x141279710
    virtual ~GFxMovieBackground();                                          //  0 0x141279840 (scalar deleting 0x14127c9d0)
    virtual void* vfunc_2();                                                //  2 0x14127cc60 returns &ms_RTTI
    virtual void vfunc_4(void* pUnused, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   // 4 0x141279a70 AS callbacks
    virtual void vfunc_5(bool b);                                           //  5 0x141279de0 (empty)
    virtual int vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags);   // 6 0x141279df0 load + build the render chain
    virtual int vfunc_7(int x, int y);                                      //  7 0x141279f90 viewport + mouse move
    virtual void vfunc_8(float fTime);                                      //  8 0x14127a070 advance, push "updatePos"
    virtual void vfunc_9(MS2_GFX_PTR(Unk_GFxHandleObj) spObj, MS2_GFX_PTR(Unk_GFxHandleObj) spHandle);   // 9 0x14127a3a0
    virtual void vfunc_11();                                                // 11 0x14127a580
    virtual void vfunc_12();                                                // 12 0x14127a6c0
    virtual bool vfunc_13();                                                // 13 0x14127a7e0
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x14127a8a0 the WM_ switch
    virtual void vfunc_16();                                                // 16 0x14127afd0 onResize
    virtual void vfunc_39(int a, int b, int c, bool d, bool e);             // 39 0x14127b040 char event

    MS2Ptr<AScript> GetScript();                                        // 0x14127aaf0 copy of the AS object
    int IsLoaded();                                                    // 0x14127ab40 loaded
    bool FUN_14127ab60(CString strLabel);                                   // 0x14127ab60 bgGotoAndPlay
    bool FUN_14127ac70(CString strLabel);                                   // 0x14127ac70 bgGotoAndStop
    bool FUN_14127ad80();                                                   // 0x14127ad80 bgPlay
    bool FUN_14127ae10();                                                   // 0x14127ae10 bgStop
    void FUN_14127aea0(int bShow);                                          // 0x14127aea0 showBackgroundColor
    void FUN_14127af40(unsigned long nColor);                               // 0x14127af40 setBackgroundColor

    int AppendScene();                                                   // AppendScene
    int FUN_14127b290();                                                   // RemoveScene
    int CreateRenderView();                                                   // CreateRenderView
    int CreateRenderTarget();                                                   // CreateRenderTarget
    int CreateRenderTexture();                                                   // CreateRenderTexture
    int SetBaseTexture(NiRenderedTexture* pTexture);                        // SetBaseTexture
    CString FUN_14127be10();                                                // the background name handed to "loadBG"

public:
    unsigned m_nCameraFlag;                                                 // +0x90 push "setCameraDistance"
    unsigned m_nPosFlag;                                                    // +0x94 push "updatePos"
    unsigned m_n98;                                                         // +0x98 minimap viewport id
    unsigned m_pad_9c;
    CString m_strBg;                                                        // +0xa0 background file name
    int m_bLoaded;                                                          // +0xa8 "loadComplete" received
    int m_pad_ac;
    efd::SmartPointer<MinimapViewport> m_spViewport;                        // +0xb0
    MS2Ptr<AScript> m_spScript;                                             // +0xb8 the AS object of the background clip
    efd::SmartPointer<NiRenderedTexture> m_spRenderTexture;                 // +0xc8
    Unk_BgOverlay* m_pOverlay;                                              // +0xd0
    efd::SmartPointer<NiScreenFillingRenderView> m_spRenderView;            // +0xd8
    Unk_BgComPtr<Unk_BgTarget> m_spRenderTarget;                            // +0xe0
};
MS2_CHECK_SIZE(GFxMovieBackground, 0xe8);
MS2_CHECK_OFFSET(GFxMovieBackground, m_strBg, 0xa0);
MS2_CHECK_OFFSET(GFxMovieBackground, m_spRenderTexture, 0xc8);
MS2_CHECK_OFFSET(GFxMovieBackground, m_spRenderTarget, 0xe0);
