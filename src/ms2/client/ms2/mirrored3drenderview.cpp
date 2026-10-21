// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mirrored 3D render view (planar reflection camera).
// MS2-UNIT: ?\mirrored3drenderview.cpp
// MS2-RANGE: 0x141486df0-0x1414876d0 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include "mirrored3drenderview.h"
#include <NiDX9Renderer.h>
#include <NiDX9RenderState.h>
#include <d3dx9math.h>

// ---- out-of-unit callees (bound to the exe by name) ----
void* FUN_140994450();                              // NiRenderer::GetRenderer()
void* FUN_14098d8d0(void* rtti, void* obj);         // NiDynamicCast helper (null-checked IsKindOf)
void FUN_140d9dab0(NiDX9RenderState* pkState, bool bEnable);
NiPoint3* FUN_140194470(NiPoint3* pkDst, const NiPoint3* pkSrc);   // NiPoint3 copy (a different COMDAT than NiPoint3::operator=)
extern char DAT_143d6eb58;                          // MS2Renderer::ms_RTTI

// MS2Renderer carries the render-state matrices as inherited NiDX9Renderer members; the game code writes them directly.
struct Unk_RendererMatrices : public NiDX9Renderer {
    // @0x141487670
    static void SetD3DView(NiDX9Renderer* pkRenderer, const D3DXMATRIX& kMat)
    {
        ((Unk_RendererMatrices*)pkRenderer)->m_kD3DView = kMat;
    }
    // @0x1414876a0
    static void SetInvView(NiDX9Renderer* pkRenderer, const D3DXMATRIX& kMat)
    {
        ((Unk_RendererMatrices*)pkRenderer)->m_kInvView = kMat;
    }
};

// @0x141486df0
CMirrored3DRenderView::CMirrored3DRenderView(NiCamera* pkCamera, NiCullingProcess* pkCullingProcess, bool bAlwaysUseCameraViewport)
    : Ni3DRenderView(pkCamera, pkCullingProcess, bAlwaysUseCameraViewport)
{
}

// @0x141486e70
void CMirrored3DRenderView::SetCameraData(const NiRect<float>& kViewport)
{
    Ni3DRenderView::SetCameraData(kViewport);

    NiDX9Renderer* pkRenderer = (NiDX9Renderer*)FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pkRenderer != NULL)
    {
        D3DXMATRIX kView(pkRenderer->GetD3DView());
        D3DXMATRIX kToOrigin;
        D3DXMATRIX kFromOrigin;
        D3DXMATRIX kReflect;
        D3DXMatrixTranslation(&kToOrigin, m_kPlanePoint.x, m_kPlanePoint.y, -m_kPlanePoint.z);
        D3DXMatrixTranslation(&kFromOrigin, m_kPlanePoint.x, m_kPlanePoint.y, m_kPlanePoint.z);
        D3DXMatrixIdentity(&kReflect);
        kReflect._33 = -1.0f;

        D3DXMATRIX kMirrorView = kToOrigin * kReflect * kFromOrigin * kView;
        D3DXMATRIX kInvMirror;
        D3DXMatrixInverse(&kInvMirror, NULL, &kMirrorView);

        LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
        pkDevice->SetTransform(D3DTS_VIEW, &kMirrorView);
        Unk_RendererMatrices::SetD3DView(pkRenderer, kMirrorView);
        Unk_RendererMatrices::SetInvView(pkRenderer, kInvMirror);

        D3DXPLANE kPlane;
        D3DXVECTOR3 kPoint(m_kPlanePoint.x, m_kPlanePoint.y, m_kPlanePoint.z);
        D3DXVECTOR3 kNormal(0.0f, 0.0f, 1.0f);
        D3DXPlaneFromPointNormal(&kPlane, &kPoint, &kNormal);
        D3DXPlaneNormalize(&kPlane, &kPlane);

        D3DXMATRIX kProj(pkRenderer->GetD3DProj());
        D3DXMATRIX kInvTranspose;
        D3DXMATRIX kViewProj;
        D3DXMatrixMultiply(&kViewProj, &kMirrorView, &kProj);
        D3DXMatrixInverse(&kInvTranspose, NULL, &kViewProj);
        D3DXMatrixTranspose(&kInvTranspose, &kInvTranspose);
        D3DXPLANE kClip;
        D3DXPlaneTransform(&kClip, &kPlane, &kInvTranspose);
        pkDevice->SetClipPlane(0, kClip);

        NiDX9RenderState* pkState = NiDX9Renderer::GetRenderer()->GetRenderState();
        FUN_140d9dab0(pkState, true);
        pkState->SetRenderState(D3DRS_CLIPPLANEENABLE, 1);
    }
}

// @0x141487200
void CMirrored3DRenderView::SetMirrorPoints(const NiPoint3& kPoint, const NiPoint3& kNormal)
{
    FUN_140194470(&m_kPlanePoint, &kPoint);
    FUN_140194470(&m_kPlaneNormal, &kNormal);
}

// @0x1414872a0
// MS2-FUNCTIONAL: the exe destructor omits the vptr store that the compiler emits
CMirrored3DRenderView::~CMirrored3DRenderView()
{
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE_METHOD(0x141486e70, CMirrored3DRenderView, SetCameraData, 893, 0xEDD2FDC1);
MS2_REPLACE_METHOD(0x141487200, CMirrored3DRenderView, SetMirrorPoints, 68, 0x3F507DF3);

