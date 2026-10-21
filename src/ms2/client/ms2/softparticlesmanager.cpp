// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SoftParticlesManager: the second 3D view (a "SoftParticleClick"
// render click) that redraws the soft-particle scene nodes and binds the post-processing MRT target to their texturing
// property. The class ctor/scalar-deleting-dtor live in ?\applyeffect.cpp; this unit has the non-deleting dtor and the
// helpers the effects and WorldService call.
// MS2-UNIT: ?\softparticlesmanager.cpp
// MS2-RANGE: 0x141773630-0x141774240 .text$mn
// MS2-PIN: ??4?$SmartPointer@VNiMaterial@@@efd@@QEAAAEAV01@PEAVNiMaterial@@@Z 0x141774170
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\softparticlesmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/softparticlesmanager.h"
#include <new>
#include <NiObject.h>
#include <NiFixedString.h>
#include <NiRenderedTexture.h>
#include <NiMaterialLibrary.h>
#include <NiDefaultClickRenderStep.h>
#include <NiMesh.h>
#include <NiTexturingProperty.h>
#include <ecr/RenderSurface.h>
#include <ecr/SceneGraphService.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"
#include "ms2/ms2recover.h"

// Options block read by the scene-graph message callbacks (FUN_1409a8b10()->FUN_1409a8ac0()).
class Unk_PPGraphicsOptions { public: bool FUN_1416b1d40(); };     // 0x1416b1d40, byte +0x1b
class Unk_PPOptions { public: Unk_PPGraphicsOptions* FUN_1409a8ac0(); };
Unk_PPOptions* FUN_1409a8b10();

// The second scene view as the post-processing service sees it: only the click getter.
class Unk_PPSecondView
{
public:
    NiViewRenderClick* FUN_141774010();         // 0x141774010
    char m_pad_00[0x10];
    NiViewRenderClickPtr m_spClick;             // +0x10
    Ni3DRenderViewPtr m_spView;                 // +0x18
    NiMaterialPtr m_spMaterial;                 // +0x20
};

// Depth-first walker over a scene graph (0x38 bytes; see nifeffectparam.cpp).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);          // 0x14098cb80
    ~Unk_SceneWalker();                         // 0x14098cf00
    NiAVObject* Next(bool bDescend);            // 0x14098e0d0
private:
    void* m_pad[7];
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

void* FUN_140876480(void* pOut, int nCat);      // category hint
void* FUN_14208a860(size_t cb, int nCat);       // the engine allocator
const NiMaterial* FUN_140a17cd0(NiMesh* pMesh); // the mesh's active material
bool FUN_140a17fd0(NiObject* pObject, const NiRTTI* pRTTI);   // NiObject::IsKindOf
Ni3DRenderView* FUN_1413f9a70();                // the main 3D view
ecr::RenderSurface* FUN_1413f98d0();            // the render surface
ecr::SceneGraphService* FUN_1413f98b0();        // the scene-graph service
bool FUN_1417741e0(const NiRTTI* pRTTI, const void* pObject);

extern const NiRTTI DAT_143d691b8;              // material kind the soft-particle nodes are filtered by
extern NiFixedString DAT_143ae5258;             // name of the material created for the view
PostProcessingService* FUN_1409a8b20();         // the post-processing service singleton

void FUN_141773a90(void* pRegistry, void* pNode);
void FUN_141773cc0(void* pRegistry, void* pNode);
void FUN_1417740c0(void* viewSystem, bool bCulled);
bool FUN_141774040(NiRenderClick* pkClick, void* pvData);
bool FUN_141774080(NiRenderClick* pkClick, void* pvData);

// Creates the click and the mirrored view and hooks them into the render surface.
// @0x141773630
void FUN_141773630(void* viewSystem)
{
    NiViewRenderClick* pkClick = new (efd::MemHint(efd::MemHint::NONE)) NiViewRenderClick();

    ((SoftParticlesManager*)viewSystem)->m_spClick = pkClick;
    ((SoftParticlesManager*)viewSystem)->m_spClick->SetName(NiFixedString("SoftParticleClick"));
    ((SoftParticlesManager*)viewSystem)->m_spClick->SetClearAllBuffers(false);

    NiDefaultClickRenderStep* pkStep =
        NiDynamicCast(NiDefaultClickRenderStep, FUN_1413f98d0()->GetRenderStep());
    pkStep->AppendRenderClick(((SoftParticlesManager*)viewSystem)->m_spClick);

    Ni3DRenderView* pkMainView = FUN_1413f9a70();
    Ni3DRenderView* pkView = new (efd::MemHint(efd::MemHint::NONE)) Ni3DRenderView(pkMainView->GetCamera(), pkMainView->GetCullingProcess(),
                                                  pkMainView->GetAlwaysUseCameraViewport());

    ((SoftParticlesManager*)viewSystem)->m_spView = pkView;
    ((SoftParticlesManager*)viewSystem)->m_spClick->AppendRenderView(((SoftParticlesManager*)viewSystem)->m_spView);
    ((SoftParticlesManager*)viewSystem)->m_spClick->SetPreProcessingCallbackFunc(FUN_141774040, viewSystem);
    ((SoftParticlesManager*)viewSystem)->m_spClick->SetPostProcessingCallbackFunc(FUN_141774080, viewSystem);
    ((SoftParticlesManager*)viewSystem)->m_spMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae5258);
}

// Turns the click off/on; turning it on registers every scene of the main view as a soft-particle scene.
// @0x141773940
void FUN_141773940(void* viewSystem, bool bEnable)
{
    SoftParticlesManager* pThis = (SoftParticlesManager*)viewSystem;

    pThis->m_spClick->SetActive(bEnable);
    FUN_1409a8b20()->FUN_1416aa6a0((Unk_PPTexture)1, bEnable);

    if (bEnable)
    {
        pThis->m_spView->RemoveAllScenes();

        Ni3DRenderView* pkMainView = FUN_1413f9a70();
        NiTPointerList<NiAVObjectPtr>& kScenes = pkMainView->GetScenes();
        NiTListIterator kPos = kScenes.GetHeadPos();
        while (kPos != 0)
        {
            const NiAVObjectPtr& spScene = kScenes.GetNext(kPos);
            NiAVObject* pkScene = spScene;
            FUN_141773a90(pThis, pkScene);
        }
    }
    else
    {
        NiTPointerList<NiAVObjectPtr>& kScenes = pThis->m_spView->GetScenes();
        NiTListIterator kPos = kScenes.GetHeadPos();
        while (kPos != 0)
        {
            const NiAVObjectPtr& spScene = kScenes.GetNext(kPos);
            NiAVObject* pkScene = spScene;
            pkScene->SetAppCulled(false);
        }
        pThis->m_spView->RemoveAllScenes();
    }
}

// Registers one scene of the main view in the soft-particle view.
// @0x141773a90
void FUN_141773a90(void* pRegistry, void* pNode)
{
    SoftParticlesManager* pThis = (SoftParticlesManager*)pRegistry;

    Unk_SceneWalker kWalker((NiObject*)pNode);
    NiAVObject* pkNext;
    while ((pkNext = kWalker.Next(true)) != 0)
    {
        NiRenderObject* pkObject = NiDynamicCast(NiRenderObject, pkNext);
        if (pkObject == 0)
            continue;

        const NiMaterial* pkMaterial = FUN_140a17cd0((NiMesh*)pkObject);
        if (!FUN_1417741e0(&DAT_143d691b8, pkMaterial))
            continue;

        pkObject->SetAppCulled(true);
        pThis->m_spView->AppendScene(pkObject);

        NiTexturingProperty* pkTexturing = (NiTexturingProperty*)pkObject->GetProperty(NiProperty::TEXTURING);
        if (pkTexturing == 0)
        {
            NiTexturingProperty* pkNew = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty();
            pkTexturing = pkNew;
            pkObject->AttachProperty(pkTexturing);
        }

        NiRenderedTexture* pkTexture = FUN_1409a8b20()->FUN_1416a23f0(1);
        NiTexturingProperty::ShaderMap* pkMap = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty::ShaderMap(pkTexture, 0);
        pkTexturing->SetShaderMap(0, pkMap);
        pkObject->UpdateProperties();
    }
}

// Unregisters one scene from the soft-particle view.
// @0x141773cc0
void FUN_141773cc0(void* pRegistry, void* pNode)
{
    SoftParticlesManager* pThis = (SoftParticlesManager*)pRegistry;

    Unk_SceneWalker kWalker((NiObject*)pNode);
    NiAVObject* pkNext;
    while ((pkNext = kWalker.Next(true)) != 0)
    {
        NiRenderObject* pkObject = NiDynamicCast(NiRenderObject, pkNext);
        if (pkObject == 0)
            continue;

        const NiMaterial* pkMaterial = FUN_140a17cd0((NiMesh*)pkObject);
        if (!FUN_1417741e0(&DAT_143d691b8, pkMaterial))
            continue;

        pkObject->SetAppCulled(false);
        pThis->m_spView->RemoveScene(pkObject);
    }
}

// SceneGraphAddedMessage callback: register the entity's scene graph when soft particles are enabled.
// @0x141773d90
void FUN_141773d90(void* svc, const ecr::SceneGraphAddedMessage* pMsg, efd::Category cat)
{
    if (!FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b1d40())
        return;

    ecr::SceneGraphService* pkService = FUN_1413f98b0();
    NiAVObject* pkScene = pkService->GetSceneGraphFromEntity(pMsg->GetEntity());
    FUN_141773a90(svc, pkScene);
}

// SceneGraphRemovedMessage callback: unregister the entity's scene graph.
// @0x141773e30
void FUN_141773e30(void* svc, const ecr::SceneGraphRemovedMessage* pMsg, efd::Category cat)
{
    if (!FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b1d40())
        return;

    ecr::SceneGraphService* pkService = FUN_1413f98b0();
    NiAVObject* pkScene = pkService->GetSceneGraphFromEntity(pMsg->GetEntity());
    FUN_141773cc0(svc, pkScene);
}

// Points every texturing property of the soft-particle view at the post-processing MRT target.
// @0x141773ed0
void FUN_141773ed0(Unk_PPSecondView* pkSoftParticles)
{
    NiRenderedTexture* pkTexture = FUN_1409a8b20()->FUN_1416a23f0(1);

    NiTPointerList<NiAVObjectPtr>& kScenes = pkSoftParticles->m_spView->GetScenes();
    NiTListIterator kPos = kScenes.GetHeadPos();
    while (kPos != 0)
    {
        const NiAVObjectPtr& spScene = kScenes.GetNext(kPos);
        NiAVObject* pkScene = spScene;

        Unk_SceneWalker kWalker(pkScene);
        NiAVObject* pkNext;
        while ((pkNext = kWalker.Next(true)) != 0)
        {
            NiRenderObject* pkObject = NiDynamicCast(NiRenderObject, pkNext);
            if (pkObject == 0)
                continue;

            NiTexturingProperty* pkTexturing = (NiTexturingProperty*)pkObject->GetProperty(NiProperty::TEXTURING);
            if (pkTexturing != 0 && pkTexturing->GetShaderMapCount() > 0)
                pkTexturing->GetShaderMap(0)->SetTexture(pkTexture);
            pkObject->UpdateProperties();
        }
    }
}

// @0x141774010
NiViewRenderClick* Unk_PPSecondView::FUN_141774010()
{
    return m_spClick;
}

// Pre-processing callback of the "SoftParticleClick": show the scenes.
// @0x141774040
bool FUN_141774040(NiRenderClick* pkClick, void* pvData)
{
    SoftParticlesManager* pThis = (SoftParticlesManager*)pvData;
    FUN_1417740c0(pThis, false);
    return true;
}

// Post-processing callback of the "SoftParticleClick": hide the scenes again.
// @0x141774080
bool FUN_141774080(NiRenderClick* pkClick, void* pvData)
{
    SoftParticlesManager* pThis = (SoftParticlesManager*)pvData;
    FUN_1417740c0(pThis, true);
    return true;
}

// @0x1417740c0
void FUN_1417740c0(void* viewSystem, bool bCulled)
{
    SoftParticlesManager* pThis = (SoftParticlesManager*)viewSystem;

    NiTPointerList<NiAVObjectPtr>& kScenes = pThis->m_spView->GetScenes();
    NiTListIterator kPos = kScenes.GetHeadPos();
    while (kPos != 0)
    {
        const NiAVObjectPtr& spScene = kScenes.GetNext(kPos);
        NiAVObject* pkScene = spScene;
        pkScene->SetAppCulled(bCulled);
    }
}

// @0x1417738e0
SoftParticlesManager::~SoftParticlesManager()
{
}

// @0x1417741e0
bool FUN_1417741e0(const NiRTTI* pRTTI, const void* pObject)
{
    if (pObject == 0)
        return false;
    return FUN_140a17fd0((NiObject*)pObject, pRTTI);
}

// @0x141774210
CRuntimeClass* FUN_141774210()
{
    return CDialog::GetThisClass();
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE(0x141773940, FUN_141773940, 321, 0x4C2A5D6B);
MS2_REPLACE(0x141773cc0, FUN_141773cc0, 198, 0xFB373809);
MS2_REPLACE(0x141773ed0, FUN_141773ed0, 310, 0xBBA392D9);
MS2_REPLACE_METHOD(0x141774010, Unk_PPSecondView, FUN_141774010, 31, 0x7FC3E510);
MS2_REPLACE(0x141774040, FUN_141774040, 43, 0x9063ABCD);
MS2_REPLACE(0x141774080, FUN_141774080, 43, 0x71E5F04D);
MS2_REPLACE(0x1417740c0, FUN_1417740c0, 116, 0xD1935A30);
MS2_REPLACE(0x1417741e0, FUN_1417741e0, 46, 0x9F3A7873);
MS2_REPLACE(0x141774210, FUN_141774210, 14, 0x778E3120);

