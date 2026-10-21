// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRenderView: the offscreen 3D view of the UI. See uirenderview.h.
// MS2-UNIT: ?\uirenderview.cpp
// MS2-RANGE: 0x141ab6f50-0x141ab8920 .text$mn
// MS2-PIN: ??_7UIRenderView@@6BIRenderServiceDelegate@ecr@@@ 0x142fdaf10
// MS2-PIN: ??8?$SmartPointer@VRenderedTextureRenderClick@@@efd@@QEBA_NPEAVRenderedTextureRenderClick@@@Z 0x141ab83c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirenderview.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uirenderview.h"
#include "uimodelview.h"
#include "gameobject.h"
#include "ms2renderlistprocessor.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <d3dx9tex.h>
#include <NiRenderedTexture.h>
#include <NiRenderTargetGroup.h>
#include <NiDX92DBufferData.h>
#include <NiShaderFactory.h>
#include <ecr/RenderService.h>
#include <ecr/SceneGraphService.h>

// ---- out-of-unit callees (bound to the exe by name) ----
ecr::SceneGraphService* FUN_1413f98b0();                        // the scene graph service
ecr::RenderService* FUN_1413fb7a0();                            // the render service
void* FUN_140980440(NiRenderedTexture* pTexture);               // the texture's buffer data
void* FUN_140980360(void* pData);                               // the D3D texture of a buffer data
void FUN_14272b7f0(void* pImage, void* pD3DTexture);            // sets the D3D texture of a swf image
NiDX92DBufferData* FUN_1414dbd20(void* pRTTI, Ni2DBuffer::RendererData* pData);   // NiDynamicCast (NULL safe)
extern char DAT_143d6eed8;                                      // NiDX92DBufferData::ms_RTTI
extern NiFixedString DAT_143ae52f8;                             // the global shader constant name
void FUN_141568d80(NiNode* pRoot);                              // prepares the effect root
void FUN_141d18b90(NiNode* pRoot, const NiFixedString& kName);  // sets the node name
bool FUN_141ab8060(NiRenderClick* pClick, void* pView);
bool FUN_141ab80b0(NiRenderClick* pClick, void* pView);
bool FUN_141ab80f0(NiFixedString* pName, void* pData, int nCount);

class Unk_UISwfEntity_25
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void* vfunc_24(void* pArg);                         // 24 0xc0 the swf image of the argument
};

// @0x141ab6f50
UIRenderView::~UIRenderView()
{
    m_spCamera = 0;
    if (m_spDirLight)
    {
        m_spDirLight->DetachAllAffectedNodes();
        m_spDirLight = 0;
    }
    if (m_spAmbientLight)
    {
        m_spAmbientLight->DetachAllAffectedNodes();
        m_spAmbientLight = 0;
    }
    if (m_spClick)
    {
        m_spClick->vfunc_14();
        m_spClick->SetProcessor(0, 0);
        m_spClick->SetPreProcessingCallbackFunc(0, 0);
        m_spClick->SetPostProcessingCallbackFunc(0, 0);
        m_spClick->vfunc_11();
        m_spClick = 0;
    }
    ecr::SceneGraphService* pSceneGraph = FUN_1413f98b0();
    if (pSceneGraph != 0 && m_uiSceneHandle != 0)
        pSceneGraph->RemoveSceneGraph(m_uiSceneHandle);
    m_spEffectRoot = 0;
    FUN_1413fb7a0()->RemoveDelegate(this);
}

// @0x141ab7200
int FUN_141ab7200(UIRenderView* pView, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg)
{
    if (spTarget.get() == 0)
        return 0;
    if (pArg == 0)
        return 0;
    if (pView->vfunc_14() == 0)
        return 0;
    if (pView->vfunc_15() == 0)
        return 0;
    if (pView->vfunc_16() == 0)
        return 0;
    NiRenderedTexture* pTexture = pView->FUN_141ab73f0();
    if (pTexture != 0)
    {
        void* pData = FUN_140980440(pTexture);
        if (pData != 0)
        {
            void* pImage = spTarget->vfunc_24(pArg);
            if (pImage != 0)
            {
                FUN_14272b7f0(pImage, FUN_140980360(pData));
                return 1;
            }
        }
    }
    return 0;
}

// @0x141ab73f0
NiRenderedTexture* UIRenderView::FUN_141ab73f0()
{
    if (m_spClick)
        return m_spClick->FUN_1416f9ab0();
    return 0;
}

// @0x141ab7440
NiRenderTargetGroup* UIRenderView::FUN_141ab7440()
{
    if (m_spClick)
        return m_spClick->GetRenderTargetGroup();
    return 0;
}

// @0x141ab7490
void UIRenderView::vfunc_2()
{
}

// @0x141ab74a0
void UIRenderView::vfunc_3()
{
    m_nDirty = 1;
}

// @0x141ab74c0
void UIRenderView::vfunc_4()
{
    if (m_spClick)
        m_spClick->vfunc_14();
}

// @0x141ab7510
void UIRenderView::vfunc_5(float)
{
}

// @0x141ab7530
void UIRenderView::vfunc_6(float)
{
}

// @0x141ab7550
void UIRenderView::vfunc_7(float, float, float)
{
}

// @0x141ab7570
void UIRenderView::vfunc_8(float)
{
}

// @0x141ab7590
void UIRenderView::vfunc_9(float)
{
}

// @0x141ab75b0
void UIRenderView::vfunc_10(int nObjectId)
{
    if (m_nObjectId != nObjectId)
        m_nDirty = 0;
    m_nObjectId = nObjectId;
}

// @0x141ab75f0
void UIRenderView::vfunc_12(const ATL::CAtlArray<NiNode*>&, NiNodePtr)
{
}

// @0x141ab7620
void UIRenderView::vfunc_11(ATL::CAtlArray<efd::SmartPointer<NiActorManager> >&)
{
}

// @0x141ab7640
int UIRenderView::vfunc_13(const Unk_ModelViewCamera&)
{
    return 1;
}

// @0x141ab7660
int UIRenderView::FUN_141ab7660()
{
    return m_nDirty;
}

// @0x141ab7680
NiNode* UIRenderView::FUN_141ab7680()
{
    return m_spEffectRoot;
}

// @0x141ab76b0
bool UIRenderView::FUN_141ab76b0(const efd::Point3& kWorld, Unk_ScreenPoint* pScreen)
{
    if (m_spCamera == 0 || m_spClick == 0)
        return false;
    NiPoint3 kPoint(kWorld);
    if (!m_spCamera->WorldPtToScreenPt(kPoint, pScreen->x, pScreen->y, 1e-05f))
        return false;
    m_spClick->GetViewport().GetWidth();
    m_spClick->GetViewport().GetHeight();
    pScreen->x = pScreen->x * (float)m_spClick->GetWidth();
    pScreen->y = (1.0f - pScreen->y) * (float)m_spClick->GetHeight();
    return true;
}

// @0x141ab7870
// MS2-FUNCTIONAL: D3DX save path; the exe keeps an HRESULT local and a different unwind layout
bool UIRenderView::FUN_141ab7870(CStringW strPath, int nFormat)
{
    if (m_uiWidth == 0 || m_uiHeight == 0)
        return false;
    NiRenderTargetGroup* pGroup = FUN_141ab7440();
    if (pGroup != 0)
    {
        Ni2DBuffer* pBuffer = pGroup->GetBuffer(0);
        if (pBuffer != 0)
        {
            NiDX92DBufferData* pData = FUN_1414dbd20(&DAT_143d6eed8, pBuffer->GetRendererData());
            if (pData != 0)
            {
                RECT kRect = { 0, 0, (LONG)m_uiWidth, (LONG)m_uiHeight };
                HRESULT hr = D3DXSaveSurfaceToFileW(strPath, (D3DXIMAGE_FILEFORMAT)nFormat, pData->GetSurface(), 0, &kRect);
                if (hr >= 0)
                    return true;
            }
        }
    }
    return false;
}

// @0x141ab7a20
UIRenderView::UIRenderView(unsigned int uiWidth, unsigned int uiHeight, GameObject* pObject, float fLightDimmer)
    : m_spCamera(0), m_uiWidth(uiWidth), m_uiHeight(uiHeight), m_fLightDimmer(fLightDimmer), m_spAmbientLight(0),
      m_spDirLight(0), m_spClick(0), m_nDirty(0), m_spEffectRoot(0), m_uiSceneHandle(0)
{
    m_nObjectId = pObject->FUN_14123c580();
    FUN_1413fb7a0()->AddDelegate(this);
}

// @0x141ab7b80
void UIRenderView::FUN_141ab7b80(int nValue)
{
    FUN_141ab80f0(&DAT_143ae52f8, &nValue, 1);
}

// @0x141ab7bb0
int UIRenderView::vfunc_14()
{
    return 0;
}

// @0x141ab7bc0
int UIRenderView::vfunc_15()
{
    return 0;
}

// @0x141ab7bd0
// MS2-FUNCTIONAL: the exe zero-fills the processor before its ctor and re-fetches the click through operator-> per call
int UIRenderView::vfunc_16()
{
    m_spClick = EE_NEW RenderedTextureRenderClick();
    {
        NiFixedString kClickName("UIRenderViewClick");
        m_spClick->SetName(kClickName);
    }
    m_spClick->vfunc_8(m_uiWidth, m_uiHeight);
    m_spClick->vfunc_9();
    m_spClick->SetPreProcessingCallbackFunc(FUN_141ab8060, this);
    m_spClick->SetPostProcessingCallbackFunc(FUN_141ab80b0, this);
    m_spClick->SetProcessor(EE_NEW MS2RenderViewRenderListProcessor(), 0);
    m_spEffectRoot = EE_NEW NiNode(0x80);
    {
        NiFixedString kRootName("UI Effect Root");
        m_spEffectRoot->SetName(kRootName);
    }
    m_spClick->vfunc_12(m_spEffectRoot);
    FUN_141568d80(m_spEffectRoot);
    ecr::SceneGraphService* pSceneGraph = FUN_1413f98b0();
    if (pSceneGraph != 0)
    {
        efd::vector<NiObjectPtr> kObjects;
        kObjects.push_back(NiObjectPtr(m_spEffectRoot));
        m_uiSceneHandle = pSceneGraph->AddSceneGraph(kObjects, true, true);
    }
    return 1;
}

// @0x141ab7fd0
void UIRenderView::OnSurfacePreDraw(ecr::RenderService*, ecr::RenderSurface* pSurface)
{
    if (m_spClick)
        m_spClick->FUN_1416f99d0(m_spCamera);
}

// @0x141ab8040
void UIRenderView::OnSurfacePostDraw(ecr::RenderService*, ecr::RenderSurface*)
{
}

// @0x141ab8060
bool FUN_141ab8060(NiRenderClick*, void* pView)
{
    UIRenderView* pRenderView = (UIRenderView*)pView;
    if (!pRenderView)
        return false;
    pRenderView->vfunc_2();
    return true;
}

// @0x141ab80b0
bool FUN_141ab80b0(NiRenderClick*, void* pView)
{
    UIRenderView* pRenderView = (UIRenderView*)pView;
    if (!pRenderView)
        return false;
    pRenderView->vfunc_3();
    return true;
}

// @0x141ab80f0
bool FUN_141ab80f0(NiFixedString* pName, void* pData, int nCount)
{
    bool bResult = NiShaderFactory::UpdateGlobalShaderConstant(*pName, nCount * sizeof(float), pData);
    return bResult;
}

// @0x141ab82e0 ecr::IRenderServiceDelegate::IRenderServiceDelegate is an implicit COMDAT.

// @0x141ab8300
MS2RenderViewRenderListProcessor::MS2RenderViewRenderListProcessor()
{
}

// @0x141ab83a0
// MS2-FUNCTIONAL: the exe's dtor omits the vfptr store
MS2RenderViewRenderListProcessor::~MS2RenderViewRenderListProcessor()
{
}

// the UCRT memmove_s this TU emits
// @0x141ab8800
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x141ab73f0, UIRenderView, FUN_141ab73f0, 65, 0x8C69B794);
MS2_REPLACE_METHOD(0x141ab7440, UIRenderView, FUN_141ab7440, 65, 0xA3788857);
MS2_REPLACE_METHOD(0x141ab7490, UIRenderView, vfunc_2, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x141ab74a0, UIRenderView, vfunc_3, 18, 0xA1EAFB60);
MS2_REPLACE_METHOD(0x141ab74c0, UIRenderView, vfunc_4, 74, 0x13076876);
MS2_REPLACE_METHOD(0x141ab7510, UIRenderView, vfunc_5, 12, 0x90591540);
MS2_REPLACE_METHOD(0x141ab7530, UIRenderView, vfunc_6, 12, 0x90591540);
MS2_REPLACE_METHOD(0x141ab7550, UIRenderView, vfunc_7, 24, 0x905D2B1C);
MS2_REPLACE_METHOD(0x141ab7570, UIRenderView, vfunc_8, 12, 0x90591540);
MS2_REPLACE_METHOD(0x141ab7590, UIRenderView, vfunc_9, 12, 0x90591540);
MS2_REPLACE_METHOD(0x141ab75b0, UIRenderView, vfunc_10, 48, 0xDCFD6EC6);
MS2_REPLACE_METHOD(0x141ab7620, UIRenderView, vfunc_11, 11, 0x02239C70);
MS2_REPLACE_METHOD(0x141ab7640, UIRenderView, vfunc_13, 16, 0x32804D89);
MS2_REPLACE_METHOD(0x141ab7660, UIRenderView, FUN_141ab7660, 14, 0x921EE467);
MS2_REPLACE_METHOD(0x141ab7680, UIRenderView, FUN_141ab7680, 31, 0x52CE6B8B);
MS2_REPLACE_METHOD(0x141ab76b0, UIRenderView, FUN_141ab76b0, 430, 0xC0327C64);
MS2_REPLACE_METHOD(0x141ab7b80, UIRenderView, FUN_141ab7b80, 41, 0x1026C096);
MS2_REPLACE_METHOD(0x141ab7bb0, UIRenderView, vfunc_14, 8, 0x7F371472);
MS2_REPLACE_METHOD(0x141ab7bc0, UIRenderView, vfunc_15, 8, 0x7F371472);
MS2_REPLACE_METHOD_VIA(0x141ab7fd0, UIRenderView, ecr::IRenderServiceDelegate, OnSurfacePreDraw, 98, 0xF165BFF6);
MS2_REPLACE_METHOD_VIA(0x141ab8040, UIRenderView, ecr::IRenderServiceDelegate, OnSurfacePostDraw, 16, 0xB7F2802D);
MS2_REPLACE(0x141ab8060, FUN_141ab8060, 59, 0x50C1D92E);
MS2_REPLACE(0x141ab80b0, FUN_141ab80b0, 59, 0xC09813C6);
MS2_REPLACE(0x141ab80f0, FUN_141ab80f0, 63, 0x42CBE35F);

