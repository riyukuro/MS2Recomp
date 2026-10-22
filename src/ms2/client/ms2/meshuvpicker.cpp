// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See meshuvpicker.h.
// MS2-UNIT: ?\meshuvpicker.cpp
// MS2-RANGE: 0x14147e6e0-0x141480c70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??A?$CAtlArray@PEAVNiRenderObject@@V?$CElementTraits@PEAVNiRenderObject@@@ATL@@@ATL@@QEAAAEAPEAVNiRenderObject@@_K@Z 0x141480830 ; unique
// MS2-PIN: ??1?$SmartPointer@VNiDynamicEffectState@@@efd@@QEAA@XZ 0x141480240
// MS2-PIN: ??4?$SmartPointer@VNiMaterial@@@efd@@QEAAAEAV01@PEAVNiMaterial@@@Z 0x1414802a0
// MS2-PIN: ??0Unk_UVTexPtr@@QEAA@XZ 0x141480480
// MS2-PIN: ??B?$SmartPointer@VNiRenderTargetGroup@@@efd@@QEBAPEAVNiRenderTargetGroup@@XZ 0x141480470
// MS2-PIN: ??_GCMeshUVPicker@@UEAAPEAXI@Z 0x1414804a0
// MS2-PIN: ?BeginOffScreenFrame@NiRenderer@@QEAA_NXZ 0x141480500
// MS2-PIN: ?BeginUsingRenderTargetGroup@NiRenderer@@QEAA_NPEAVNiRenderTargetGroup@@I@Z 0x141480560
// MS2-PIN: ?Check_FrameState@NiRenderer@@AEBA_NPEBDW4EFrameState@1@@Z 0x141480610
// MS2-PIN: ?Check_RenderTargetGroupActive@NiRenderer@@AEBA_NPEBD_N@Z 0x141480640
// MS2-PIN: ?EndOffScreenFrame@NiRenderer@@QEAA_NXZ 0x1414806a0
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\meshuvpicker.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "meshuvpicker.h"

#include <NiDX9Renderer.h>
#include <NiDX9TextureData.h>
#include <NiColorExtraData.h>
#include <NiFrustum.h>
#include <NiMesh.h>
#include <NiSPWorkflowManager.h>
#include <NiMaterialLibrary.h>
#include <NiDepthStencilBuffer.h>
#include <NiRenderedTexture.h>
#include <NiZBufferProperty.h>
#include <d3dx9math.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees and globals (bound to the exe by their FUN_<va> / DAT_<va> names) ----

NiRenderer* GetNiRenderer();                                    // NiRenderer::GetRenderer
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* p);      // NiObject::DynamicCast
IDirect3DDevice9* FUN_140d89690(NiDX9Renderer* p);              // NiDX9Renderer::GetD3DDevice
unsigned FUN_1411d7c70(NiDX9Renderer* p, bool (*pfnNotify)(bool, void*), void* pvData);   // AddResetNotificationFunc
void* FUN_141d61a80(unsigned uiWidth, unsigned uiHeight, NiRenderer* pRenderer, NiTexture::FormatPrefs* pPrefs,
                    unsigned short usFlags);                    // NiRenderedTexture::Create
NiRenderedTexture* FUN_14127c9b0(Unk_PPSmartA* pSmart);         // the pointer held by the smart pointer
void* FUN_140c8f680(Unk_PPSmartA* pSmart);                      // the same pointer as a truth value
NiMaterial* FUN_141d284a0(const NiFixedString* pName);          // NiMaterialLibrary::CreateMaterial

extern unsigned DAT_1439f7cb4;                                  // picker width (pixels)
extern unsigned DAT_1439f7cb8;                                  // picker height (pixels)
extern NiColorA DAT_143a09680;                                  // render target clear colour
extern NiFixedString DAT_143ae5280;                             // material name (bSecond)
extern NiFixedString DAT_143ae5288;                             // material name (first pass)
extern NiFixedString DAT_143ae50f0;                             // extra data key of the clear colour
extern NiFixedString DAT_143ae5210;                             // material name of the extra meshes

// efd::Point3(x, y, z) shared constructor (0x14097f250), converted to the Unk_NiPoint3 the assign takes.
struct Unk_DummyVec3
{
    Unk_DummyVec3(float x, float y, float z);                   // 0x14097f250
    operator const Unk_NiPoint3&() const { return *reinterpret_cast<const Unk_NiPoint3*>(this); }
    float x, y, z;
};

// Two helpers that sit between the picker functions (their owners are not recovered).
struct Unk_UVPair
{
    Unk_UVPair();                                               // 0x141480bf0
    unsigned m_a;
    unsigned m_b;
};
struct Unk_UVEmpty
{
    CStringA FUN_141480c20();                                   // 0x141480c20
};

// @0x14147e6e0
CMeshUVPicker::CMeshUVPicker()
    : m_10(0), m_14(false), m_18(-1), m_20(NULL), m_28(NULL), m_30(NULL), m_38(NULL), m_40(NULL), m_48(NULL)
{
    for (unsigned i = 0; i < 3; i++)
    {
        m_50[i].Assign(0);
        m_68[i] = NULL;
        m_80[i] = NULL;
    }
}

// @0x14147e840
CMeshUVPicker::~CMeshUVPicker()
{
    FUN_14147fbb0();
}

// @0x14147e900
int CMeshUVPicker::FUN_14147e900()
{
    if (!FUN_14147f570())
        return 0;
    FUN_14147fa80();
    return 1;
}
MS2_REPLACE_METHOD(0x14147E900, CMeshUVPicker, FUN_14147e900, 50, 0xB8E8B77C);

// @0x14147e940
// MS2-FUNCTIONAL: local frame is 8 bytes larger in the exe (texel temporary)
bool CMeshUVPicker::FUN_14147e940(NiRenderObject* pMesh, NiCamera* pCamera, float fX, float fY, float* pU, float* pV,
                                  CAtlArray<NiRenderObject*>* pExtras)
{
    if (!m_14)
        return false;
    FUN_14147ec90(pMesh, pExtras, pCamera, fX, fY, true);
    Unk_UVTexel kTexel;
    FUN_14147fde0(2, &kTexel);
    float fU = kTexel.FUN_14135dd50(0);
    *pU = fU;
    float fV = kTexel.FUN_14135dd50(1);
    *pV = fV;
    if (0.001f < *pU || *pU == 0.001f || 0.001f < *pV || *pV == 0.001f)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14147E940, CMeshUVPicker, FUN_14147e940, 259, 0x6D4483DA);

// @0x14147ea50
// MS2-FUNCTIONAL: local frame layout of the texel temporaries differs
bool CMeshUVPicker::FUN_14147ea50(NiRenderObject* pMesh, NiCamera* pCamera, float fX, float fY, Unk_FcPoint3* pPos0,
                                  Unk_FcPoint3* pPos1, NiPoint2* pUV, unsigned* pIndex,
                                  CAtlArray<NiRenderObject*>* pExtras)
{
    if (!m_14)
        return false;
    FUN_14147ec90(pMesh, pExtras, pCamera, fX, fY, false);
    Unk_UVTexel kTexel;
    FUN_14147fde0(0, &kTexel);
    *pPos0 = Unk_DummyVec3(kTexel.FUN_14135dd50(0), kTexel.FUN_14135dd50(1), kTexel.FUN_14135dd50(2));
    FUN_14147fde0(1, &kTexel);
    *pPos1 = Unk_DummyVec3(kTexel.FUN_14135dd50(0), kTexel.FUN_14135dd50(1), kTexel.FUN_14135dd50(2));
    FUN_14147fde0(2, &kTexel);
    *pUV = NiPoint2(kTexel.FUN_14135dd50(0), kTexel.FUN_14135dd50(1));
    *pIndex = (unsigned)kTexel.FUN_14135dd50(2);
    if (0.001f < pUV->x || pUV->x == 0.001f || 0.001f < pUV->y || pUV->y == 0.001f)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14147EA50, CMeshUVPicker, FUN_14147ea50, 568, 0x8684E60C);

// @0x14147ec90
// MS2-FUNCTIONAL: large Gamebryo render sequence; the inlined smart pointer and NiRenderer glue is laid out differently
void CMeshUVPicker::FUN_14147ec90(NiRenderObject* pMesh, CAtlArray<NiRenderObject*>* pExtras, NiCamera* pCamera,
                                  float fX, float fY, bool bSecond)
{
    if (!m_14)
        return;

    NiMaterial* pUVMaterial = FUN_1414800a0(bSecond);
    NiRenderTargetGroupPtr spTarget = bSecond ? m_40 : m_38;

    NiSPWorkflowManagerPtr spWorkflow = new (efd::MemHint(efd::MemHint::NONE))
        NiSPWorkflowManager(0x40, NiStreamProcessor::MEDIUM, 3);
    NiMesh* pAsMesh = (NiMesh*)FUN_14098d8d0(&NiMesh::ms_RTTI, pMesh);
    if (pAsMesh)
    {
        NiSyncArgs kComplete;
        kComplete.m_uiSubmitPoint = 0x8000;
        kComplete.m_uiCompletePoint = 0x8000;
        pAsMesh->CompleteModifiers(&kComplete);
        for (unsigned i = 0; i < pAsMesh->GetModifierCount(); i++)
        {
            NiMeshModifier* pModifier = pAsMesh->GetModifierAt(i);
            if (pModifier->SupportsSubmitSyncPoint(0x8030))
            {
                NiSyncArgs kSubmit;
                kSubmit.m_uiSubmitPoint = 0x8030;
                kSubmit.m_uiCompletePoint = 0x8040;
                pModifier->SubmitTasks(pAsMesh, &kSubmit, spWorkflow);
            }
        }
    }
    NiUInt32 uiGroup = NiSyncArgs::GetTaskGroupID(0x8030, 0x8040);
    spWorkflow->FlushTaskGroup(uiGroup, uiGroup);

    NiRenderer* pRenderer = GetNiRenderer();
    NiRenderTargetGroup* pBackTarget = pRenderer->GetDefaultRenderTargetGroup();
    NiColorA kSavedColor;
    pRenderer->GetBackgroundColor(kSavedColor);
    NiColorA kClearColor = DAT_143a09680;
    pRenderer->SetBackgroundColor(kClearColor);

    NiFrustum kOrig = pCamera->GetViewFrustum();
    NiFrustum kPick;
    float fPixelW = (kOrig.m_fRight - kOrig.m_fLeft) / (float)pBackTarget->GetWidth(0);
    float fPixelH = (kOrig.m_fTop - kOrig.m_fBottom) / (float)pBackTarget->GetHeight(0);
    kPick.m_fNear = kOrig.m_fNear;
    kPick.m_fFar = kOrig.m_fFar;
    float fHalfW = fPixelW * (float)(DAT_1439f7cb4 / 2);
    float fHalfH = fPixelH * (float)(DAT_1439f7cb8 / 2);
    kPick.m_fLeft = kOrig.m_fLeft + (fPixelW * fX - fHalfW);
    kPick.m_fRight = kPick.m_fLeft + fHalfW * 2.0f;
    kPick.m_fTop = kOrig.m_fTop - (fPixelH * fY - fHalfH);
    kPick.m_fBottom = kPick.m_fTop - fHalfH * 2.0f;
    pCamera->SetViewFrustum(kPick);
    pCamera->Update(0.0f, true);

    pRenderer->BeginOffScreenFrame();
    pRenderer->BeginUsingRenderTargetGroup(spTarget, 7);
    pRenderer->SetCameraData(pCamera);
    pRenderer->SetPropertyState(m_20);
    pRenderer->SetEffectState(NULL);

    if (pExtras)
    {
        for (unsigned i = 0; i < pExtras->GetCount(); i++)
        {
            NiRenderObject* pExtra = (*pExtras)[i];
            const NiMaterial* pExtraMaterial = pExtra->GetActiveMaterial();
            NiColorA kColor = DAT_143a09680;
            FUN_141480710(pExtra, DAT_143ae50f0, kColor);
            NiMaterial* pExtraUV = FUN_141d284a0(&DAT_143ae5210);
            pExtra->ApplyAndSetActiveMaterial(pExtraUV, 0xffffffff);
            for (unsigned j = 0; j < pExtra->GetMaterialCount(); j++)
                pExtra->ClearCachedShaderAndSetNeedsUpdate(j);
            pExtra->RenderImmediate(pRenderer);
            pExtra->SetActiveMaterial(pExtraMaterial);
        }
    }

    const NiMaterial* pOrigMaterial = pMesh->GetActiveMaterial();
    pMesh->ApplyAndSetActiveMaterial(pUVMaterial, 0xffffffff);
    for (unsigned i = 0; i < pMesh->GetMaterialCount(); i++)
        pMesh->ClearCachedShaderAndSetNeedsUpdate(i);

    NiPropertyStatePtr spOrigProps = pMesh->GetPropertyState();
    NiDynamicEffectStatePtr spOrigEffects = pMesh->GetEffectState();
    m_20->SetProperty(spOrigProps->GetTexturing());
    pMesh->SetPropertyState(m_20);
    pMesh->SetEffectState(NULL);
    pMesh->RenderImmediate(pRenderer);
    pMesh->SetPropertyState(spOrigProps);
    pMesh->SetEffectState(spOrigEffects);
    pMesh->SetActiveMaterial(pOrigMaterial);

    pRenderer->EndUsingRenderTargetGroup();
    pRenderer->EndOffScreenFrame();
    pCamera->SetViewFrustum(kOrig);
    pCamera->Update(0.0f, true);
    pRenderer->SetBackgroundColor(kSavedColor);
}
MS2_REPLACE_METHOD(0x14147EC90, CMeshUVPicker, FUN_14147ec90, 2260, 0x30E905BA);

// @0x14147f570
// MS2-FUNCTIONAL: stack cookie and the inlined smart pointer / D3D call sequence are laid out differently
bool CMeshUVPicker::FUN_14147f570()
{
    NiRenderer* pRenderer = GetNiRenderer();
    NiDX9Renderer* pDX9 = (NiDX9Renderer*)FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, pRenderer);
    if (pDX9 == NULL)
        return false;

    m_48 = FUN_140d89690(pDX9);
    m_48->AddRef();
    m_18 = FUN_1411d7c70(pDX9, FUN_14147fd10, this);

    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = (NiTexture::FormatPrefs::PixelLayout)12;
    for (int i = 0; i < 3; i++)
    {
        m_50[i].Assign(FUN_141d61a80(DAT_1439f7cb4, DAT_1439f7cb8, pRenderer, &kPrefs, 0x100));
        if (FUN_140c8f680(&m_50[i]) == 0)
        {
            FUN_14147fbb0();
            return false;
        }
    }

    m_38 = NiRenderTargetGroup::Create(3, pRenderer);
    if (m_38 == NULL)
    {
        FUN_14147fbb0();
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        NiRenderedTexture* pTexture = FUN_14127c9b0(&m_50[i]);
        NiRenderTargetGroup* pGroup = m_38;
        pGroup->AttachBuffer(pTexture->GetBuffer(), i);
    }

    NiDepthStencilBuffer* pDepth = NiDepthStencilBuffer::CreateCompatible(FUN_14127c9b0(&m_50[0])->GetBuffer(), pRenderer);
    if (pDepth == NULL)
    {
        FUN_14147fbb0();
        return false;
    }
    NiRenderTargetGroup* pGroup = m_38;
    pGroup->AttachDepthStencilBuffer(pDepth);

    m_40 = NiRenderTargetGroup::Create(FUN_14127c9b0(&m_50[2])->GetBuffer(), pRenderer, true, true);
    if (m_40 == NULL)
    {
        FUN_14147fbb0();
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        NiDX9TextureData* pData = (NiDX9TextureData*)FUN_14127c9b0(&m_50[i])->GetRendererData();
        m_68[i] = (IDirect3DTexture9*)pData->GetD3DTexture();
        D3DSURFACE_DESC kDesc;
        m_68[i]->GetLevelDesc(0, &kDesc);
        m_10 = kDesc.Format;
        if (m_48->CreateTexture(kDesc.Width, kDesc.Height, 1, 0, kDesc.Format, D3DPOOL_SYSTEMMEM, &m_80[i], NULL) != 0)
        {
            FUN_14147fbb0();
            return false;
        }
    }
    m_14 = true;
    return true;
}
MS2_REPLACE_METHOD(0x14147F570, CMeshUVPicker, FUN_14147f570, 1280, 0xB4DD6A90);

// @0x14147fa80
void CMeshUVPicker::FUN_14147fa80()
{
    m_20 = NiNew NiPropertyState;
    NiZBufferProperty* pZBuffer = NiNew NiZBufferProperty;
    pZBuffer->SetZBufferTest(true);
    pZBuffer->SetZBufferWrite(true);
    m_20->SetProperty(pZBuffer);
}
MS2_REPLACE_METHOD(0x14147FA80, CMeshUVPicker, FUN_14147fa80, 287, 0x53A05DBE);

// @0x14147fbb0
void CMeshUVPicker::FUN_14147fbb0()
{
    NiDX9Renderer* pDX9 = (NiDX9Renderer*)FUN_14098d8d0(&NiDX9Renderer::ms_RTTI, GetNiRenderer());
    if (m_18 != -1)
    {
        pDX9->RemoveResetNotificationFunc((unsigned)m_18);
        m_18 = -1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (m_80[i] != NULL)
            m_80[i]->Release();
        m_68[i] = NULL;
        m_80[i] = NULL;
        m_50[i].Assign(0);
    }
    if (m_48 != NULL)
    {
        m_48->Release();
        m_48 = NULL;
    }
    m_40 = NULL;
    m_38 = NULL;
    m_14 = false;
}
MS2_REPLACE_METHOD(0x14147FBB0, CMeshUVPicker, FUN_14147fbb0, 341, 0xFEA91836);

// @0x14147fd10
bool CMeshUVPicker::FUN_14147fd10(bool bBeforeReset, void* pPicker)
{
    CMeshUVPicker* pThis = (CMeshUVPicker*)pPicker;
    return pThis->FUN_14147fd50(bBeforeReset);
}

// @0x14147fd50
bool CMeshUVPicker::FUN_14147fd50(bool bBeforeReset)
{
    if (!bBeforeReset && m_14)
    {
        for (int i = 0; i < 3; i++)
        {
            NiDX9TextureData* pData = (NiDX9TextureData*)FUN_14127c9b0(&m_50[i])->GetRendererData();
            m_68[i] = (IDirect3DTexture9*)pData->GetD3DTexture();
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x14147FD50, CMeshUVPicker, FUN_14147fd50, 132, 0xF8961D27);

// @0x14147fde0
// MS2-FUNCTIONAL: local variable order of the rect and the null-initialised surface pointer differ
bool CMeshUVPicker::FUN_14147fde0(int nTarget, Unk_ShaderVec4* pTexel)
{
    if (!m_14)
        return false;

    RECT kRect;
    kRect.left = DAT_1439f7cb4 / 2;
    kRect.top = DAT_1439f7cb8 / 2;
    kRect.right = kRect.left + 1;
    kRect.bottom = kRect.top + 1;

    NiDX9TextureData* pData = (NiDX9TextureData*)FUN_14127c9b0(&m_50[nTarget])->GetRendererData();
    m_68[nTarget] = (IDirect3DTexture9*)pData->GetD3DTexture();

    D3DSURFACE_DESC kDesc;
    m_68[nTarget]->GetLevelDesc(0, &kDesc);
    IDirect3DSurface9* pSource;
    m_68[nTarget]->GetSurfaceLevel(0, &pSource);
    IDirect3DSurface9* pDest;
    m_80[nTarget]->GetSurfaceLevel(0, &pDest);
    m_48->GetRenderTargetData(pSource, pDest);
    pSource->Release();
    pDest->Release();

    IDirect3DTexture9* pReadBack = m_80[nTarget];
    D3DLOCKED_RECT kLocked;
    if (pReadBack->LockRect(0, &kLocked, &kRect, D3DLOCK_READONLY) >= 0)
    {
        D3DXFLOAT16* pHalf = (D3DXFLOAT16*)kLocked.pBits;
        float afValue[4];
        D3DXFloat16To32Array(afValue, pHalf, 4);
        pReadBack->UnlockRect(0);
        pTexel->Assign(afValue[0], afValue[1], afValue[2], afValue[3]);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14147FDE0, CMeshUVPicker, FUN_14147fde0, 697, 0x265F1825);

// @0x1414800a0
NiMaterial* CMeshUVPicker::FUN_1414800a0(bool bSecond)
{
    if (bSecond)
    {
        if ((NiMaterial*)m_28 == NULL)
            m_28 = FUN_141d284a0(&DAT_143ae5280);
        return (NiMaterial*)m_28;
    }
    else
    {
        if ((NiMaterial*)m_30 == NULL)
            m_30 = FUN_141d284a0(&DAT_143ae5288);
        return (NiMaterial*)m_30;
    }
}
MS2_REPLACE_METHOD(0x1414800A0, CMeshUVPicker, FUN_1414800a0, 165, 0x7E9A09C7);

// @0x141480710
void CMeshUVPicker::FUN_141480710(NiObjectNET* pObject, const NiFixedString& kKey, const NiColorA& kColor)
{
    NiColorExtraData* pExtra = (NiColorExtraData*)FUN_14098d8d0(&NiColorExtraData::ms_RTTI, pObject->GetExtraData(kKey));
    if (pExtra == NULL)
    {
        pExtra = NiNew NiColorExtraData(kColor);
        pObject->AddExtraData(kKey, pExtra);
    }
    else
    {
        pExtra->SetValue(kColor);
    }
}

// @0x141480bf0
Unk_UVPair::Unk_UVPair()
    : m_a(0xffffff), m_b(1)
{
}

// @0x141480c20
CStringA Unk_UVEmpty::FUN_141480c20()
{
    return CStringA("");
}
