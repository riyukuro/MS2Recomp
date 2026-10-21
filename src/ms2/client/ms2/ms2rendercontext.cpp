// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2RenderContext: ecr::RenderContext plus the back-buffer recode capture.
// MS2-UNIT: ?\ms2rendercontext.cpp
// MS2-RANGE: 0x1414dab70-0x1414dbf30 .text$mn
// MS2-PIN: ??_GMS2RenderContext@@UEAAPEAXI@Z 0x1414dbb80
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2rendercontext.h"
#include "hook/ms2hook.h"
#include <time.h>
#include <string.h>
#include <NiDX9Renderer.h>
#include <NiDX92DBufferData.h>
#include <NiViewRenderClick.h>
#include <Ni3DRenderView.h>
#include <NiShadowManager.h>
#include <d3dx9tex.h>

// ---- out-of-unit callees (bound to the exe by name) ----
class Unk_RendererWrap;
class Unk_RenderTarget
{
public:
    unsigned int FUN_1409a8ab0();   // width
    unsigned int FUN_1409a8aa0();   // height
};
class Unk_RendererWrap
{
public:
    Unk_RenderTarget* FUN_1409a8ac0();
};
Unk_RendererWrap* FUN_1409a8b10();
class Unk_RenderLog;
Unk_RenderLog* FUN_140166440();
void FUN_1401859c0(Unk_RenderLog* pLog, int nCategory, int nLevel, const wchar_t* pszMessage);
Ni2DBuffer* FUN_14184e5d0(int nTarget);                  // back buffer of the default render target group
NiDX9Renderer* FUN_140d89bc0();                          // the DX9 renderer, or 0 when the renderer is not a DX9 one
extern NiRenderer* FUN_140994450();                      // NiRenderer::GetRenderer()

// @0x1414dabb0
MS2RenderContext::MS2RenderContext(ecr::RenderService* pRenderService, Ni3DRenderView* pRenderView)
    : ecr::RenderContext(pRenderService, pRenderView)
{
    m_bRecode = 0;
    m_pCopySurface = 0;
    m_pFrameMemory = 0;
    m_pInfoMemory = 0;
    m_nSerial = 0;
}

// @0x1414dac50
MS2RenderContext::~MS2RenderContext()
{
    ReleaseRecodeSurface();
}

// @0x1414daca0
void MS2RenderContext::Draw(efd::Float32 currentTime)
{
    if (m_validate && !m_invalid) {
        return;
    }
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (!pkRenderer->BeginFrame()) {
        return;
    }
    m_invalid = false;

    efd::UInt32 count = (efd::UInt32)m_renderSurfaces.size();
    for (efd::UInt32 ui = 0; ui < count; ++ui) {
        ecr::RenderSurface* pSurface = m_renderSurfaces[ui];
        if (pSurface->GetCamera() == NULL) {
            continue;
        }
        pSurface->GetCamera()->Update(currentTime);

        NiRenderStep* pRenderStep = pSurface->GetRenderStep();
        NiDefaultClickRenderStep* pClickRenderStep = (NiDefaultClickRenderStep*)pRenderStep;
        const NiTPointerList<NiRenderClickPtr>& kRenderClicks = pClickRenderStep->GetRenderClickList();

        NiCamera* pCamera = pSurface->GetCamera();
        const NiRect<float>& kViewport = pCamera->GetViewPort();
        NiShadowManager::SetSceneCamera(pCamera);

        NiTListIterator kClickIter = kRenderClicks.GetHeadPos();
        while (kClickIter) {
            const NiRenderClickPtr& kClick = kRenderClicks.GetNext(kClickIter);
            kClick->SetViewport(kViewport);

            NiViewRenderClickPtr kViewClick = NiDynamicCast(NiViewRenderClick, kClick);
            if (kViewClick != NULL) {
                const NiTPointerList<NiRenderViewPtr>& kRenderViews = kViewClick->GetRenderViews();
                NiTListIterator kViewIter = kRenderViews.GetHeadPos();
                while (kViewIter) {
                    Ni3DRenderViewPtr kView = NiDynamicCast(Ni3DRenderView, kRenderViews.GetNext(kViewIter));
                    if (kView)
                        kView->SetCamera(pCamera);
                }
            }
        }

        RaisePreDrawEvent(pSurface);
        pSurface->Draw(currentTime);
        RaisePostDrawEvent(pSurface);
    }
    pkRenderer->EndFrame();
    CaptureRecodeFrame();
    pkRenderer->DisplayFrame();
}
MS2_REPLACE_METHOD(0x1414DACA0, MS2RenderContext, Draw, 747, 0x3E082227);

// @0x1414dafa0
int MS2RenderContext::CreateRecodeSurface()
{
    if (m_pInfoMemory != 0) {
        delete m_pInfoMemory;
    }
    m_pInfoMemory = new Unk_SharedMemory("MS2SurfaceInfo", 0x444);
    if (!m_pInfoMemory->IsValid()) {
        if (FUN_140166440() != 0) {
            FUN_1401859c0(FUN_140166440(), 0xb, 0x15, L"MS2RenderContext::CreateRecodeSurface CSharedMemory false");
        }
        return 0;
    }
    Unk_RecodeSurfaceInfo* pInfo = (Unk_RecodeSurfaceInfo*)m_pInfoMemory->m_pView;
    pInfo->m_nWidth = FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8ab0();
    pInfo->m_nHeight = FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8aa0();
    pInfo->m_nFrameSize = pInfo->m_nWidth * pInfo->m_nHeight * 4;
    pInfo->m_nOutWidth = 0x500;
    pInfo->m_nOutHeight = 0x2d0;
    pInfo->m_bFrameReady[0] = 0;
    pInfo->m_bFrameReady[1] = 0;
    memset(pInfo->m_szText, 0, sizeof(pInfo->m_szText));
    pInfo->m_bTextValid = 0;

    time_t tNow = time(0);
    tm* pLocal = localtime(&tNow);
    tm kTime;
    memset(&kTime, 0, sizeof(tm));
    if (pLocal != 0) {
        memcpy(&kTime, pLocal, sizeof(tm));
    }
    ++m_nSerial;
    CString kName;
    kName.Format("%02d_%02d%02d%02d_%d", kTime.tm_mday, kTime.tm_hour, kTime.tm_min, kTime.tm_sec, m_nSerial);
    memset(pInfo->m_szFrameName, 0, sizeof(pInfo->m_szFrameName));
    memcpy(pInfo->m_szFrameName, (const char*)kName, kName.GetLength());

    NiDX9Renderer* pDX9 = NiDX9Renderer::GetRenderer();
    if (pDX9 != 0) {
        IDirect3DDevice9* pDevice = pDX9->GetD3DDevice();
        if (pDevice != 0) {
            int nWidth = pInfo->m_nWidth;
            int nHeight = pInfo->m_nHeight;
            if (m_pCopySurface != 0) {
                m_pCopySurface->Release();
                m_pCopySurface = 0;
            }
            if (pDevice->CreateOffscreenPlainSurface(nWidth, nHeight, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &m_pCopySurface, 0) != 0) {
                if (FUN_140166440() != 0) {
                    FUN_1401859c0(FUN_140166440(), 0xb, 0x15, L"MS2RenderContext::CreateRecodeSurface copySurface false");
                }
                return 0;
            }
            if (m_pFrameMemory != 0) {
                delete m_pFrameMemory;
            }
            m_pFrameMemory = new Unk_SharedMemory(pInfo->m_szFrameName, pInfo->m_nFrameSize << 1);
            if (!m_pFrameMemory->IsValid()) {
                if (FUN_140166440() != 0) {
                    FUN_1401859c0(FUN_140166440(), 0xb, 0x15, L"MS2RenderContext::CreateRecodeSurface CSharedMemory false 2");
                }
                return 0;
            }
            pInfo->m_bActive = 1;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1414DAFA0, MS2RenderContext, CreateRecodeSurface, 1552, 0xAAA72561);

// @0x1414db5c0
void MS2RenderContext::ReleaseRecodeSurface()
{
    if (m_pInfoMemory != 0) {
        Unk_RecodeSurfaceInfo* pInfo = (Unk_RecodeSurfaceInfo*)m_pInfoMemory->m_pView;
        pInfo->m_bActive = 0;
        pInfo->m_bTextValid = 0;
        delete m_pInfoMemory;
        m_pInfoMemory = 0;
    }
    m_bRecode = 0;
    if (m_pCopySurface != 0) {
        m_pCopySurface->Release();
        m_pCopySurface = 0;
    }
    if (m_pFrameMemory != 0) {
        delete m_pFrameMemory;
        m_pFrameMemory = 0;
    }
}
MS2_REPLACE_METHOD(0x1414DB5C0, MS2RenderContext, ReleaseRecodeSurface, 326, 0x7711F0BB);

// @0x1414db710
void MS2RenderContext::EnableRecode()
{
    m_bRecode = 1;
}
MS2_REPLACE_METHOD(0x1414DB710, MS2RenderContext, EnableRecode, 18, 0xF20B0D10);

// @0x1414db730
void MS2RenderContext::SetRecodeText(CString text)
{
    if (m_pInfoMemory != 0) {
        if (!text.IsEmpty()) {
            Unk_RecodeSurfaceInfo* pInfo = (Unk_RecodeSurfaceInfo*)m_pInfoMemory->m_pView;
            memcpy(pInfo->m_szText, (const char*)text, text.GetLength());
            pInfo->m_bTextValid = 1;
            m_bRecode = 1;
        }
    }
}

// @0x1414db7e0
bool MS2RenderContext::IsRecodeFrameFree(int index)
{
    if (m_pInfoMemory != 0) {
        Unk_RecodeSurfaceInfo* pInfo = (Unk_RecodeSurfaceInfo*)m_pInfoMemory->m_pView;
        return pInfo->m_bFrameReady[index] == 0;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1414DB7E0, MS2RenderContext, IsRecodeFrameFree, 95, 0x3F89C615);

// @0x1414db850
void MS2RenderContext::MarkRecodeFrameReady(int index)
{
    if (m_pInfoMemory != 0) {
        Unk_RecodeSurfaceInfo* pInfo = (Unk_RecodeSurfaceInfo*)m_pInfoMemory->m_pView;
        pInfo->m_bFrameReady[index] = 1;
    }
}
MS2_REPLACE_METHOD(0x1414DB850, MS2RenderContext, MarkRecodeFrameReady, 70, 0x29C18C64);

// @0x1414db8a0
void MS2RenderContext::CaptureRecodeFrame()
{
    if (m_pCopySurface == 0) {
        return;
    }
    if (m_bRecode == 0) {
        return;
    }
    Unk_RecodeSurfaceInfo* pInfo = (Unk_RecodeSurfaceInfo*)m_pInfoMemory->m_pView;
    int index = 0;
    bool bFree = IsRecodeFrameFree(index);
    if (!bFree) {
        index = 1;
        bFree = IsRecodeFrameFree(index);
    }
    if (m_bRecode == 0) {
        return;
    }
    Ni2DBuffer* pBuffer = FUN_14184e5d0(0);
    if (pBuffer == 0) {
        return;
    }
    NiDX92DBufferData* pData = NiDynamicCast(NiDX92DBufferData, static_cast<NiDX92DBufferData*>(pBuffer->GetRendererData()));
    if (pData == 0) {
        return;
    }
    D3DXLoadSurfaceFromSurface(m_pCopySurface, 0, 0, pData->GetSurface(), 0, 0, D3DX_FILTER_NONE, 0);
    D3DLOCKED_RECT kRect;
    HRESULT hr = m_pCopySurface->LockRect(&kRect, 0, D3DLOCK_READONLY);
    if (hr < 0) {
        return;
    }
    unsigned char* pDst = (unsigned char*)m_pFrameMemory->m_pView + (int)(index * pInfo->m_nFrameSize);
    memcpy(pDst, kRect.pBits, pInfo->m_nFrameSize);
    m_pCopySurface->UnlockRect();
    MarkRecodeFrameReady(index);
}
MS2_REPLACE_METHOD(0x1414DB8A0, MS2RenderContext, CaptureRecodeFrame, 501, 0xADFD84AF);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)

