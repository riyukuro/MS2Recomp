// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieUgc: a movie rendered onto a scene object. See gfxmovieugc.h.
// MS2-UNIT: client\ms2\gfxmovieugc.cpp
// MS2-RANGE: 0x1400ebf20-0x1400ebf50 .text$di
// MS2-RANGE: 0x14127d290-0x14127e190 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "gfxmovieugc.h"
#include <NiTexturingProperty.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderer.h>
#include <NiDX9TextureData.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/gfxrenderhandle.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- file statics (.text$di) ----
#ifndef MS2_HOOK_DLL
const NiRTTI GFxMovieUgc::ms_RTTI("GFxMovieUgc", &GFxMovieEventHandler::ms_RTTI);       // @0x1400ebf20
#else
const NiRTTI GFxMovieUgc::ms_RTTI("GFxMovieUgc", &GFxMovieEventHandler::ms_RTTI);
#endif

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
extern char DAT_143b059e8;                                                  // efd::SmartPointer<efd::ServiceManager> cell
extern int DAT_1439f7358;                                                   // edge length of the UGC render texture
ecr::RenderService* FUN_14127bf80(char* pCell);                             // the render service (gfxmoviebackground.cpp)

// ---- GFxMovieUgc ----
// @0x14127d290
GFxMovieUgc::GFxMovieUgc(NiAVObject* pObject, CString strName)
    : m_strName(strName), m_spObject(pObject), m_spComponent(0), m_spRenderTexture(0), m_spRenderTarget(0)
{
}
// MS2-FUNCTIONAL: smart-pointer release sequence differs
// @0x14127d360
GFxMovieUgc::~GFxMovieUgc()
{
    if (m_spRenderTarget != 0)
    {
        m_spRenderTarget->vfunc_2();
        m_spRenderTarget = 0;
    }
    if (m_spObject != 0)
        m_spObject = 0;
    m_spRenderTexture = 0;
    m_spComponent = 0;
}
// @0x14127e060
void* GFxMovieUgc::vfunc_2() { return (void*)&ms_RTTI; }
// @0x14127d4b0
void GFxMovieUgc::vfunc_4(void* pUnused, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
}
// MS2-FUNCTIONAL: by-value CString/loader argument temps differ
// @0x14127d4d0
int GFxMovieUgc::vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags)
{
    if (GFxMovie::vfunc_6(pLoader, strPath, nLoadFlags) == 0)
        return 0;
    m_60->SetBackgroundAlpha(1.0f);
    if (FUN_14127dd70() == 0)
        return 0;
    if (FUN_14127dc60() == 0)
        return 0;
    if (FUN_14127de50(m_spRenderTexture) == 0)
        return 0;
    return 1;
}
// MS2-FUNCTIONAL: GFx event temp layout differs
// @0x14127d640
int GFxMovieUgc::vfunc_7(int x, int y)
{
    m_60->SetBackgroundAlpha(1.0f);
    m_60->SetViewport(x, y, 0, 0, x, y, 1);
    Scaleform::GFx::Event kEvent(Scaleform::GFx::Event::MouseMove);
    m_60->HandleEvent(kEvent);
    return 1;
}
// MS2-FUNCTIONAL: by-value Ptr arguments and display handle temps differ
// @0x14127d720
void GFxMovieUgc::vfunc_9(MS2_GFX_PTR(Unk_GFxHandleObj) spObj, MS2_GFX_PTR(Unk_GFxHandleObj) spHandle)
{
    if (m_spRenderTarget == 0)
        return;
    Unk_BgComPtr<Unk_BgTarget> spTarget(spObj->vfunc_14());
    if (spTarget != 0)
    {
        spObj->vfunc_17(m_spRenderTarget, 1);
        Unk_BgDispHandle kHandle(reinterpret_cast<const Unk_BgDispHandle&>(m_60->GetDisplayHandle()));
        if (kHandle.FUN_1425805a0(spHandle->FUN_142582270()))
            spHandle->Assign(kHandle);
        spObj->vfunc_17(spTarget, 1);
    }
}
// MS2-FUNCTIONAL: smart-pointer release sequence differs
// @0x14127d900
void GFxMovieUgc::vfunc_11()
{
    if (m_spRenderTarget != 0)
    {
        m_spRenderTarget->vfunc_2();
        m_spRenderTarget = 0;
    }
    if (m_spObject != 0)
        m_spObject = 0;
    m_spRenderTexture = 0;
    m_spComponent = 0;
    GFxMovieEventHandler::vfunc_11();
}
// @0x14127d9d0
void GFxMovieUgc::vfunc_12()
{
    GFxMovie::vfunc_12();
    FUN_14127de50(0);
    if (m_spRenderTarget != 0)
    {
        m_spRenderTarget->vfunc_2();
        m_spRenderTarget = 0;
    }
}
// @0x14127da50
bool GFxMovieUgc::vfunc_13()
{
    if (!GFxMovie::vfunc_13())
        return false;
    if (FUN_14127dd70() == 0)
        return false;
    if (FUN_14127dc60() == 0)
        return false;
    if (FUN_14127de50(m_spRenderTexture) == 0)
        return false;
    return true;
}
// @0x14127dad0
void GFxMovieUgc::vfunc_40()
{
    m_60->HandleEvent(Scaleform::GFx::SetFocusEvent(UpdateModifiers(false)));
}
// @0x14127db60
void GFxMovieUgc::vfunc_41()
{
    Scaleform::GFx::Event kEvent(Scaleform::GFx::Event::KillFocus);
    m_60->HandleEvent(kEvent);
}
// @0x14127dbc0
int GFxMovieUgc::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    return GFxMovieEventHandler::vfunc_14(hwnd, msg, wParam, lParam);
}
// @0x14127dc10
void GFxMovieUgc::vfunc_39(int a, int b, int c, bool d, bool e)
{
    GFxMovieEventHandler::vfunc_39(a, b, c, d, e);
}
// MS2-FUNCTIONAL: COM surface temporaries differ
// @0x14127dc60
int GFxMovieUgc::FUN_14127dc60()
{
    if (m_spRenderTexture != 0)
    {
        NiDX9TextureData* pData = (NiDX9TextureData*)m_spRenderTexture->GetRendererData();
        if (pData != 0)
        {
            IDirect3DTexture9* pTexture = (IDirect3DTexture9*)pData->GetD3DTexture();
            if (pTexture != 0)
            {
                IDirect3DSurface9* pSurface = 0;
                pTexture->GetSurfaceLevel(0, &pSurface);
                m_spRenderTarget = FUN_1422cf060()->vfunc_67(pSurface, 0);
                if (pSurface != 0)
                    pSurface->Release();
                if (m_spRenderTarget != 0)
                    return 1;
            }
        }
    }
    return 0;
}
// MS2-FUNCTIONAL: FormatPrefs/render texture temporaries differ
// @0x14127dd70
int GFxMovieUgc::FUN_14127dd70()
{
    ecr::RenderService* pRender;
    if (m_spObject != 0 && (pRender = FUN_14127bf80(&DAT_143b059e8)) != 0)
    {
        if (pRender->GetActiveRenderSurface()->GetRenderTargetGroup() != 0)
        {
            NiTexture::FormatPrefs kPrefs;
            kPrefs.m_eAlphaFmt = NiTexture::FormatPrefs::ALPHA_DEFAULT;
            m_spRenderTexture = NiRenderedTexture::Create(DAT_1439f7358, DAT_1439f7358, NiRenderer::GetRenderer(), kPrefs, Ni2DBuffer::MULTISAMPLE_NONE);
            if (m_spRenderTexture != 0)
                return 1;
        }
    }
    return 0;
}
// MS2-FUNCTIONAL: Map allocation temporaries differ
// @0x14127de50
int GFxMovieUgc::FUN_14127de50(NiRenderedTexture* pTexture)
{
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, m_spObject->GetProperty(NiProperty::TEXTURING));
    if (pTexturing == 0)
        return 0;
    pTexturing->SetBaseTexture(pTexture);
    pTexturing->SetDecalMap(0, NiNew NiTexturingProperty::Map());
    if (m_spObject != 0)
        m_spObject->UpdateProperties();
    return 1;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x14127d4d0, GFxMovieUgc, vfunc_6, 362, 0x50C96535);
MS2_REPLACE_METHOD(0x14127d640, GFxMovieUgc, vfunc_7, 213, 0x922DEEED);
MS2_REPLACE_METHOD(0x14127d720, GFxMovieUgc, vfunc_9, 472, 0x2493A5A8);
MS2_REPLACE_METHOD(0x14127d900, GFxMovieUgc, vfunc_11, 196, 0x0006AAEF);
MS2_REPLACE_METHOD(0x14127d9d0, GFxMovieUgc, vfunc_12, 121, 0x88E213A9);
MS2_REPLACE_METHOD(0x14127da50, GFxMovieUgc, vfunc_13, 113, 0xAED5E240);
MS2_REPLACE_METHOD(0x14127dad0, GFxMovieUgc, vfunc_40, 127, 0x6E1649F0);
MS2_REPLACE_METHOD(0x14127db60, GFxMovieUgc, vfunc_41, 75, 0x5B8E2E00);
MS2_REPLACE_METHOD(0x14127dc60, GFxMovieUgc, FUN_14127dc60, 265, 0x666C97BE);
MS2_REPLACE_METHOD(0x14127dd70, GFxMovieUgc, FUN_14127dd70, 213, 0x180E575F);
MS2_REPLACE_METHOD(0x14127de50, GFxMovieUgc, FUN_14127de50, 267, 0xE814C7D2);
