// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxRenderSingleThread, the single-threaded Scaleform renderer
// of the GFx UI library (D3D9 HAL + Renderer2D, device state block, the "ScaleformStep" render step).
// MS2-UNIT: ?\gfxrendersinglethread.cpp
// MS2-RANGE: 0x1422f4270-0x1422f5910 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The obj's
// COMDAT tail is the Scaleform Ptr<> glue of the HAL, the Renderer2D and the state block, Render::GlyphCacheParams,
// Render::(D3D9::)HALInitParams, the SF_MEMORY_REDEFINE_NEW operators, NiDX9Renderer::GetPresentParams and
// GFxManager::FUN_1422f58f0.
#include "ms2/placeholder/ms2stdafx.h"
#include <string.h>

#include <NiDX9Renderer.h>
#include <NiDX92DBufferData.h>
#include <NiRenderFrame.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>

#include "Render/D3D9/D3D9_HAL.h"

#include "gfxrendersinglethread.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/ecrcameraservice.h"

#include "hook/ms2hook.h"

// vfunc_3 calls memcpy (the build would expand it inline as an intrinsic)
#pragma function(memcpy)

// GFx UI render helpers (gfxrenderhelpers.h; inline COMDATs of ?\asmousecursor.cpp). That header's manager getter
// conflicts with gfxmanager.h, so the two helpers are declared here.
NiDX9Renderer* FUN_1422cf0a0();
LPDIRECT3DDEVICE9 FUN_1422cf0d0();

ecr::RenderService* FUN_14127bf80(Unk_AppFramework* pFramework);   // the render service of the framework
ecr::RenderSurface* FUN_140af7da0(ecr::RenderService* pService);    // its main surface
void FUN_141aee8d0(NiRenderFrame* pFrame, NiRenderStep* pStep);     // NiRenderFrame::AppendRenderStep (uiservice.cpp copy)

// GFxMovie as vfunc_6 sees it: slot 9 takes the HAL and the Renderer2D by value (gfxmovie.h types both parameters with
// the Ptr<Unk_GFxHandleObj> stand-in; the copies made here are this obj's Ptr<HAL>/Ptr<Renderer2D> COMDATs).
class Unk_GrstMovie
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(float fTime);
    virtual void vfunc_9(Scaleform::Ptr<Unk_GFxUIHal> spHAL, Scaleform::Ptr<Unk_GFxUIRenderer2D> spRenderer2D);
};

// @0x1422f4270
GFxRenderSingleThread::GFxRenderSingleThread(NiRenderer* pRenderer)
    : m_dwTick(0), m_14(0), m_dwLastTick(0), m_pRenderer(pRenderer), m_renderHAL(0), m_spRenderer2D(0),
      m_spStateBlock(0), m_spRenderTexture(0), m_spRenderStep(0)
{
    m_50 = 0;
}

// @0x1422f4360
GFxRenderSingleThread::~GFxRenderSingleThread()
{
    m_pRenderer = 0;
    m_renderHAL = 0;
    m_spRenderer2D = 0;
    m_spStateBlock = 0;
    m_spRenderTexture = 0;
    m_spRenderStep = 0;
    m_50 = 0;
}

// @0x1422f4470
Unk_GFxUIRenderer2D* GFxRenderSingleThread::vfunc_2()
{
    return m_spRenderer2D;
}
MS2_REPLACE_METHOD(0x1422F4470, GFxRenderSingleThread, vfunc_2, 31, 0xFB0F0BA5);

// @0x1422f44a0
int GFxRenderSingleThread::vfunc_3()
{
    D3DPRESENT_PARAMETERS kPresentParams;
    memcpy(&kPresentParams, FUN_1422cf0a0()->GetPresentParams(), sizeof(kPresentParams));

    m_renderHAL = *new Unk_GFxUIHal(0);
    m_spRenderer2D = *new Unk_GFxUIRenderer2D(m_renderHAL.GetPtr());

    Scaleform::Render::GlyphCacheParams kGlyphParams;
    kGlyphParams.NumTextures = 32;
    m_spRenderer2D->FUN_142582280()->SetParams(kGlyphParams);

    if (FAILED(FUN_1422cf0d0()->CreateStateBlock(D3DSBT_ALL, &m_spStateBlock.GetRawRef())))
        return 0;
    if (!m_renderHAL->InitHAL(Scaleform::Render::D3D9::HALInitParams(FUN_1422cf0d0(), kPresentParams, 1)))
        return 0;
    if (!FUN_1422f4cc0())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422F44A0, GFxRenderSingleThread, vfunc_3, 658, 0x6361EA31);

// @0x1422f4740
int GFxRenderSingleThread::vfunc_4()
{
    if (!m_spRenderer2D)
        return 0;
    if (!m_spStateBlock)
        return 0;
    m_spStateBlock->Capture();
    return m_spRenderer2D->FUN_142582210();
}
MS2_REPLACE_METHOD(0x1422F4740, GFxRenderSingleThread, vfunc_4, 132, 0xECA44D9F);

// @0x1422f47d0
void GFxRenderSingleThread::vfunc_5()
{
    if (!m_spRenderer2D)
        return;
    if (!m_spStateBlock)
        return;
    m_spRenderer2D->FUN_142582250();
    m_spStateBlock->Apply();
}
MS2_REPLACE_METHOD(0x1422F47D0, GFxRenderSingleThread, vfunc_5, 125, 0x54B3E73C);

// @0x1422f4860
void GFxRenderSingleThread::vfunc_6(void* pMovie)
{
    if (!pMovie)
        return;
    if (!m_spRenderer2D)
        return;
    static_cast<Unk_GrstMovie*>(pMovie)->vfunc_9(m_renderHAL, m_spRenderer2D);
}
MS2_REPLACE_METHOD(0x1422F4860, GFxRenderSingleThread, vfunc_6, 175, 0x9819F91E);

// @0x1422f4920
int GFxRenderSingleThread::vfunc_7()
{
    m_dwTick = GetTickCount();
    if (m_dwLastTick == 0)
        m_dwLastTick = GetTickCount();
    return 1;
}
MS2_REPLACE_METHOD(0x1422F4920, GFxRenderSingleThread, vfunc_7, 58, 0xEA03248E);

// @0x1422f4960
void GFxRenderSingleThread::vfunc_8()
{
    m_dwLastTick = m_dwTick;
}
MS2_REPLACE_METHOD(0x1422F4960, GFxRenderSingleThread, vfunc_8, 22, 0x29CF2808);

// @0x1422f4980
void GFxRenderSingleThread::vfunc_9(void* pMovie)
{
    if (!pMovie)
        return;
    float fScale = 1.0f;
    float fTime = efd::Min((m_dwTick - m_dwLastTick) / 1000.0f, 1.0f);
    static_cast<GFxMovie*>(pMovie)->vfunc_8(fTime * fScale);
}
MS2_REPLACE_METHOD(0x1422F4980, GFxRenderSingleThread, vfunc_9, 126, 0x5BD5AF48);

// @0x1422f4a10
void GFxRenderSingleThread::vfunc_10()
{
    FUN_1422f4f00();
    if (m_renderHAL)
        m_renderHAL->ShutdownHAL();
}
MS2_REPLACE_METHOD(0x1422F4A10, GFxRenderSingleThread, vfunc_10, 87, 0x3FF95D7C);

// @0x1422f4a70
void GFxRenderSingleThread::vfunc_11()
{
    if (m_spStateBlock)
        m_spStateBlock = 0;
    m_renderHAL->PrepareForReset();
    FUN_14025e7a0()->FUN_1422f58f0(0);
}
MS2_REPLACE_METHOD(0x1422F4A70, GFxRenderSingleThread, vfunc_11, 111, 0xD05EBE8E);

// @0x1422f4af0
bool GFxRenderSingleThread::vfunc_12()
{
    if (m_renderHAL)
    {
        if (FAILED(FUN_1422cf0d0()->CreateStateBlock(D3DSBT_ALL, &m_spStateBlock.GetRawRef())))
            return false;
        if (!m_renderHAL->RestoreAfterReset())
        {
            FUN_14025e7a0()->FUN_1422f58f0(0);
            FUN_14025e7a0()->FUN_1422b08f0("*** GFX :: !m_renderHAL->RestoreAfterReset()");
            throw 0xd;
        }
    }
    if (!FUN_1422f4fd0())
    {
        FUN_14025e7a0()->FUN_1422f58f0(0);
        FUN_14025e7a0()->FUN_1422b08f0("*** GFX :: !CreateRenderTexture()");
        throw 0xd;
    }
    FUN_14025e7a0()->FUN_1422f58f0(1);
    return true;
}
MS2_REPLACE_METHOD(0x1422F4AF0, GFxRenderSingleThread, vfunc_12, 317, 0xFED07058);

// @0x1422f4c40
void GFxRenderSingleThread::vfunc_13(void* p)
{
}
MS2_REPLACE_METHOD(0x1422F4C40, GFxRenderSingleThread, vfunc_13, 11, 0x02239C70);

// @0x1422f4c60
Ni2DBuffer* GFxRenderSingleThread::vfunc_14()
{
    if (m_spRenderTexture)
        return m_spRenderTexture->GetBuffer();
    return 0;
}
MS2_REPLACE_METHOD(0x1422F4C60, GFxRenderSingleThread, vfunc_14, 81, 0x43325BF2);

// @0x1422f4cc0
int GFxRenderSingleThread::FUN_1422f4cc0()
{
    FUN_1422f4f00();
    ecr::RenderService* pService = FUN_14127bf80(&g_143b059e8);
    if (pService)
    {
        NiRenderFrame* pFrame = FUN_140af7da0(pService)->GetRenderFrame();
        if (pFrame)
        {
            m_spRenderStep = NiNew NiDefaultClickRenderStep();
            m_spRenderStep->SetName("ScaleformStep");
            FUN_1422f4fd0();
            NiGFxOverlayClick* pClick = NiNew NiGFxOverlayClick;
            if (pClick)
            {
                pClick->SetName("ScaleformRC");
                pClick->SetPreProcessingCallbackFunc(FUN_1422f50d0, this);
                m_spRenderStep->AppendRenderClick(pClick);
            }
            FUN_141aee8d0(pFrame, m_spRenderStep);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422F4CC0, GFxRenderSingleThread, FUN_1422f4cc0, 565, 0x0148222D);

// @0x1422f4f00
int GFxRenderSingleThread::FUN_1422f4f00()
{
    if (!m_spRenderStep)
        return 0;
    ecr::RenderService* pService = FUN_14127bf80(&g_143b059e8);
    if (pService)
    {
        NiRenderFrame* pFrame = FUN_140af7da0(pService)->GetRenderFrame();
        if (pFrame)
        {
            pFrame->RemoveRenderStep(m_spRenderStep);
            m_spRenderStep->RemoveAllRenderClicks();
            m_spRenderStep = 0;
            m_spRenderTexture = 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1422F4F00, GFxRenderSingleThread, FUN_1422f4f00, 197, 0x6A5C51E6);

// @0x1422f4fd0
int GFxRenderSingleThread::FUN_1422f4fd0()
{
    ecr::RenderService* pService = FUN_14127bf80(&g_143b059e8);
    if (pService)
    {
        NiRenderTargetGroup* pTarget = FUN_140af7da0(pService)->GetRenderTargetGroup();
        if (pTarget)
        {
            NiTexture::FormatPrefs kPrefs;
            kPrefs.m_eAlphaFmt = NiTexture::FormatPrefs::ALPHA_DEFAULT;
            m_spRenderTexture = NiRenderedTexture::Create(pTarget->GetWidth(0), pTarget->GetHeight(0),
                NiRenderer::GetRenderer(), kPrefs, Ni2DBuffer::MULTISAMPLE_NONE);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422F4FD0, GFxRenderSingleThread, FUN_1422f4fd0, 236, 0xFA4BBAFB);

// @0x1422f50d0
bool GFxRenderSingleThread::FUN_1422f50d0(NiRenderClick* pClick, void* pData)
{
    GFxRenderer* pRenderer = static_cast<GFxRenderer*>(pData);
    if (!pRenderer)
        return false;
    NiDX9Renderer* pDX9Renderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (!pDX9Renderer)
        return false;
    Ni2DBuffer* pBuffer = pRenderer->vfunc_14();
    if (!pBuffer)
        return true;
    NiRenderTargetGroup* pTarget = NiRenderer::GetRenderer()->GetDefaultRenderTargetGroup();
    if (!pTarget)
        return true;
    if (!pTarget->GetBuffer(0)->FastCopy(pBuffer))
        return true;
    return true;
}
MS2_REPLACE(0x1422F50D0, GFxRenderSingleThread::FUN_1422f50d0, 240, 0x59B3C7D8);
