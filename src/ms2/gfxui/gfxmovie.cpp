// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovie, the base of the game's GFx movie wrappers: it loads
// a SWF (Loader::CreateMovie / MovieDef::CreateInstance), routes the movie's ExternalInterface calls to vfunc_4, advances
// and draws the movie, and holds the stage / mouse cursor / movie clip loader objects of its "initializeClass" call.
// MS2-UNIT: ?\gfxmovie.cpp
// MS2-RANGE: 0x1422bced0-0x1422bf7c0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The class
// is declared in ms2/placeholder/gfxmovie.h. The obj's COMDAT tail holds the Scaleform Ptr<>/Viewport/MemoryParams/
// ActionControl/ExternalInterface inlines, NiGFxExternalInterfaceDelegate<GFxMovie> and the
// Delegate<void(const Params&)> instance bound to FUN_1422be100.
#include "ms2/placeholder/ms2stdafx.h"
#include <NiRenderTargetGroup.h>
#include <ecr/RenderSurface.h>

#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/nigfxexternalinterfacedelegate.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asfunction.h"
#include "ms2/placeholder/asmoviecliploader.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "Render/Renderer2D.h"
#include "hook/ms2hook.h"

extern char DAT_143b059e8;                                      // the entity app framework
void* FUN_14127bf80(void* pFramework);                          // its render service (null if none)
ecr::RenderSurface* FUN_140af7da0(ecr::RenderService* pService);  // the service's default surface
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);   // set a String value

// The GFx UI manager singleton (0x14025e7a0; its class lives in the library's first obj, 0x1422b0060-0x1422b7f20).
class Unk_GFxUIManager
{
public:
    int FUN_1422ae940();                                        // nonzero: advance in one step (no frame catch-up split)
};
Unk_GFxUIManager* FUN_14025e7a0();

// The two Ptr<> arguments of vfunc_9/10 (gfxmovie.h): the Render HAL and the Renderer2D. Only the release functions
// are needed here (GFxMovieBackground's unit spells out more of it).
class Unk_GFxHandleObj
{
public:
    void AddRef();                                              // 0x14257dc30
    void Release();                                             // 0x14257dcb0
};

// @0x1422bced0
GFxMovie::GFxMovie()
    : m_10(0), m_14(1.0f), m_20(0), m_30(0), m_40(0), m_50(0), m_58(0), m_60(0), m_68(0), m_70(0), m_78(0)
{
}

// @0x1422bcfe0
GFxMovie::~GFxMovie()
{
    m_20 = 0;
    m_30 = 0;
    m_40 = 0;
    m_60 = 0;
    m_68 = 0;
    m_70 = 0;
    m_78 = 0;
}

// @0x1422bd0f0
MS2_GFX_MOVIE* GFxMovie::FUN_1422bd0f0()
{
    return m_60;
}

// @0x1422bd120
Scaleform::GFx::Value GFxMovie::FUN_1422bd120(CString strClassName)
{
    return FUN_1422be7f0("flash.utils.getDefinitionByName", strClassName);
}

// MS2-FUNCTIONAL: the exe widens the discarded bool result of Movie::Invoke (movzx eax, al); no source form found yet.
// @0x1422bd1b0
Scaleform::GFx::Value GFxMovie::FUN_1422bd1b0(const char* szMethod)
{
    Scaleform::GFx::Value vResult;
    (int)m_60->Invoke(szMethod, &vResult, (const Scaleform::GFx::Value*)0, 0);
    return vResult;
}

// @0x1422bd250
Scaleform::GFx::Value GFxMovie::FUN_1422bd250(const char* szMethod, ASArgList& args)
{
    Scaleform::GFx::Value vResult;
    if (!m_60->Invoke(szMethod, &vResult, args.FUN_1409b1f70(0), (unsigned)args.FUN_1409b2840()))
        return Scaleform::GFx::Value();
    return vResult;
}

// @0x1422bd350
void GFxMovie::vfunc_3(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
}

// @0x1422bd370
void GFxMovie::vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
}

// @0x1422bd390
void GFxMovie::vfunc_5(bool bHide)
{
    FUN_1422bd0f0()->SetVisible(bHide ? false : true);
}
MS2_REPLACE_METHOD(0x1422BD390, GFxMovie, vfunc_5, 75, 0xFA962DF3);

// @0x1422bd3f0
int GFxMovie::vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags)
{
    m_58 = pLoader;
    if (m_68 = *pLoader->CreateMovie(strPath, nLoadFlags))
    {
        Scaleform::Ptr<Scaleform::GFx::ActionControl> pActionControl =
            *new Scaleform::GFx::ActionControl(Scaleform::GFx::ActionControl::Action_LogAllFilenames);
        Scaleform::GFx::MemoryParams memParams;
        if (m_50 > 0)
            memParams.MaxCollectionRoots = m_50;
        if (m_60 = *m_68->CreateInstance(memParams, false, pActionControl, 0))
        {
            m_60->SetMouseCursorCount(1);
            m_60->SetControllerCount(1);
            m_60->SetBackgroundAlpha(0.0f);
            m_60->SetViewScaleMode(Scaleform::GFx::Movie::SM_NoScale);
            m_60->SetViewAlignment(Scaleform::GFx::Movie::Align_TopLeft);
            m_60->SetExternalInterface(NiGFxExternalInterfaceDelegate<GFxMovie>::Create(this, &GFxMovie::vfunc_4));
            m_60->SetEdgeAAMode(Scaleform::Render::EdgeAA_On);
            void* pService = FUN_14127bf80(&DAT_143b059e8);
            if (pService != 0)
            {
                NiRenderTargetGroup* pTarget = FUN_140af7da0((ecr::RenderService*)pService)->GetRenderTargetGroup();
                if (pTarget != 0)
                    vfunc_7(pTarget->GetWidth(0), pTarget->GetHeight(0));
            }
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422BD3F0, GFxMovie, vfunc_6, 1158, 0xA325B121);

// The viewport is one pixel larger than the window on every side.
// @0x1422bd880
int GFxMovie::vfunc_7(int x, int y)
{
    m_60->SetBackgroundAlpha(0.0f);
    int nWidth = x + 2;
    int nHeight = y + 2;
    Scaleform::GFx::Viewport vp(x, y, -1, -1, nWidth, nHeight, -1, -1, nWidth, nHeight, m_14, 1.0f,
                                Scaleform::Render::Viewport::View_AlphaComposite);
    m_60->SetViewport(vp);
    Scaleform::GFx::Event kEvent(Scaleform::GFx::Event::SceneResize);
    m_60->HandleEvent(kEvent);
    return 1;
}
MS2_REPLACE_METHOD(0x1422BD880, GFxMovie, vfunc_7, 377, 0xEF888BE5);

// Long frames are advanced in two steps: one frame, then the rest with frame catch-up.
// @0x1422bda00
void GFxMovie::vfunc_8(float fTime)
{
    if (!m_60)
        return;
    if (FUN_14025e7a0()->FUN_1422ae940() != 0)
    {
        m_60->Advance(fTime, 0, true);
    }
    else
    {
        float fFrameTime = 1.0f / m_60->GetFrameRate();
        unsigned nFrames = (unsigned)(fTime / fFrameTime);
        if (nFrames >= 2)
        {
            m_60->Advance(fFrameTime, 0, true);
            m_60->Advance(fTime - fFrameTime, nFrames - 1, true);
        }
        else
        {
            m_60->Advance(fTime, 0, true);
        }
    }
}
MS2_REPLACE_METHOD(0x1422BDA00, GFxMovie, vfunc_8, 386, 0x5DFFD53E);

// MS2-FUNCTIONAL: byte-identical except the argument dtors: the exe's two Ptr<> types (HAL, Renderer2D) have different
// release COMDATs (0x14127c550 / 0x14127c5c0); gfxmovie.h spells both Unk_GFxHandleObj (GFxMovieBackground overrides the slot).
// Draw the movie: capture the next frame and display it with the Renderer2D (spRenderer).
// @0x1422bdb90
void GFxMovie::vfunc_9(MS2_GFX_PTR(Unk_GFxHandleObj) spHal, MS2_GFX_PTR(Unk_GFxHandleObj) spRenderer)
{
    Scaleform::GFx::MovieDisplayHandle hDisplay = m_60->GetDisplayHandle();
    if (hDisplay.NextCapture(reinterpret_cast<Scaleform::Render::Renderer2D*>(spRenderer.operator->())->GetContextNotify()))
        reinterpret_cast<Scaleform::Render::Renderer2D*>(spRenderer.operator->())->Display(hDisplay);
}

// MS2-FUNCTIONAL: as vfunc_9 (the two Ptr<> argument types).
// Capture without drawing.
// @0x1422bdc50
void GFxMovie::vfunc_10(MS2_GFX_PTR(Unk_GFxHandleObj) spHal, MS2_GFX_PTR(Unk_GFxHandleObj) spRenderer)
{
    Scaleform::GFx::MovieDisplayHandle hDisplay = m_60->GetDisplayHandle();
    hDisplay.NextCapture(reinterpret_cast<Scaleform::Render::Renderer2D*>(spRenderer.operator->())->GetContextNotify());
    if (reinterpret_cast<Scaleform::Render::Renderer2D*>(spRenderer.operator->())->GetContextNotify())
        reinterpret_cast<Scaleform::Render::Renderer2D*>(spRenderer.operator->())->GetContextNotify()->EndFrameContextNotify();
}

// @0x1422bdd20
void GFxMovie::vfunc_11()
{
    if (m_40.get())
        m_40->FUN_1422d0690();
    m_20 = 0;
    m_30 = 0;
    m_40 = 0;
    m_58 = 0;
    m_60 = 0;
    m_68 = 0;
}
MS2_REPLACE_METHOD(0x1422BDD20, GFxMovie, vfunc_11, 169, 0xA46C1944);

// @0x1422bddd0
void GFxMovie::vfunc_12()
{
}

// @0x1422bdde0
bool GFxMovie::vfunc_13()
{
    return true;
}

// @0x1422bddf0
int GFxMovie::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    return 0;
}

// @0x1422bde10
int GFxMovie::vfunc_15(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    return 0;
}

// @0x1422bde30
float GFxMovie::FUN_1422bde30()
{
    return m_14;
}

// @0x1422bde50
void GFxMovie::FUN_1422bde50(float fScale)
{
    m_14 = fScale;
}

// MS2-FUNCTIONAL: the GFx UI library was built with /fp:precise (m_14 loaded first, ucomiss + jp); the unit build uses /fp:fast.
// @0x1422bde80
int GFxMovie::FUN_1422bde80(float fScale)
{
    int bChanged = m_14 != fScale;
    m_14 = fScale;
    if (bChanged)
    {
        Scaleform::GFx::Viewport vp;
        m_60->GetViewport(&vp);
        vp.Scale = fScale;
        m_60->SetViewport(vp);
    }
    return bChanged;
}
MS2_REPLACE_METHOD(0x1422BDE80, GFxMovie, FUN_1422bde80, 221, 0x8D63D513);

// @0x1422bdf70
int GFxMovie::FUN_1422bdf70()
{
    Scaleform::GFx::Viewport vp;
    m_60->GetViewport(&vp);
    return vp.Width;
}

// @0x1422bdfc0
int GFxMovie::FUN_1422bdfc0()
{
    Scaleform::GFx::Viewport vp;
    m_60->GetViewport(&vp);
    return vp.Height;
}

// @0x1422be010
void GFxMovie::FUN_1422be010(int* pnWidth, int* pnHeight)
{
    Scaleform::GFx::Viewport vp;
    m_60->GetViewport(&vp);
    *pnWidth = vp.Width;
    *pnHeight = vp.Height;
}

// @0x1422be080
void GFxMovie::FUN_1422be080(int bPause)
{
    m_60->SetPause(bPause != 0);
}

// @0x1422be0e0
void GFxMovie::FUN_1422be0e0(void (*pfn)(const Scaleform::GFx::FunctionHandler::Params&))
{
    m_70 = pfn;
}

// @0x1422be100
void GFxMovie::FUN_1422be100(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_70)
        m_70(params);
}

// Bind scaleform.ms2.common.Common.m_getFormatFunction to FUN_1422be100.
// @0x1422be140
void GFxMovie::FUN_1422be140()
{
    Scaleform::GFx::Value vCommon = FUN_1422bd120("scaleform.ms2.common.Common");
    AScript kCommon(vCommon, 2);
    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb(this, &GFxMovie::FUN_1422be100);
    kCommon.FUN_141b46a40("m_getFormatFunction", ASFunction(cb, 0, FUN_1422be400()));
}

// @0x1422be280
void GFxMovie::FUN_1422be280(void (*pfn)(AScript& kCommon, int nMovieId))
{
    m_78 = pfn;
}

// @0x1422be2a0
void GFxMovie::FUN_1422be2a0()
{
    if (m_78)
    {
        Scaleform::GFx::Value vCommon = FUN_1422bd120("scaleform.ms2.common.Common");
        AScript kCommon(vCommon, 2);
        m_78(kCommon, FUN_1422be400());
    }
}

// @0x1422be360
int GFxMovie::FUN_1422be360()
{
    return m_10;
}

// @0x1422be380
void GFxMovie::FUN_1422be380(int n)
{
    m_10 = n;
}

// @0x1422be3a0
int GFxMovie::FUN_1422be3a0(unsigned msg)
{
    if (FUN_1422be400() == 2)
    {
        switch (msg)
        {
        case WM_MOUSEMOVE:
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_LBUTTONDBLCLK:
        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDBLCLK:
        case WM_MOUSEWHEEL:
            return m_10;
        }
    }
    return 0;
}

// @0x1422be400
int GFxMovie::FUN_1422be400()
{
    return m_18;
}

// @0x1422be420
MS2Ptr<ASStage> GFxMovie::FUN_1422be420()
{
    return m_20;
}

// @0x1422be470
MS2Ptr<ASMouseCursor> GFxMovie::FUN_1422be470()
{
    return m_30;
}

// @0x1422be4c0
MS2Ptr<ASMovieClipLoader> GFxMovie::FUN_1422be4c0()
{
    return m_40;
}

// @0x1422be510
void GFxMovie::FUN_1422be510(MS2Ptr<ASStage> spStage)
{
    m_20 = spStage;
}

// @0x1422be560
void GFxMovie::FUN_1422be560(MS2Ptr<ASMouseCursor> spCursor)
{
    m_30 = spCursor;
}

// @0x1422be5b0
void GFxMovie::FUN_1422be5b0(MS2Ptr<ASMovieClipLoader> spLoader)
{
    m_40 = spLoader;
}

// @0x1422be7f0
inline Scaleform::GFx::Value GFxMovie::FUN_1422be7f0(const char* szMethod, CString a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    return FUN_1422bd250(szMethod, args);
}

// @0x1422bf590
void* GFxMovie::vfunc_2()
{
    return (void*)&ms_RTTI;
}

MS2_REPLACE_METHOD(0x1422BE140, GFxMovie, FUN_1422be140, 314, 0xD12302DD);
MS2_REPLACE_METHOD(0x1422BE2A0, GFxMovie, FUN_1422be2a0, 180, 0x7F908042);
MS2_REPLACE_METHOD(0x1422BD250, GFxMovie, FUN_1422bd250, 248, 0x35C7C06A);

// MS2-FUNCTIONAL: SDK MemoryParams ctor (inline): 4.1.19 adds InitialDynamicLimit (+0x4c), which the exe's 4.1.18 lacks.
// MS2-PIN: ??0MemoryParams@GFx@Scaleform@@QEAA@_K@Z 0x1422bec30
