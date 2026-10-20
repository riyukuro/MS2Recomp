// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPortrait: the player head portrait view. See uiportrait.h.
// MS2-UNIT: ?\uiportrait.cpp
// MS2-RANGE: 0x141a90500-0x141a911b0 .text$mn
// MS2-PIN: ??_7UIPortrait@@6BIRenderServiceDelegate@ecr@@@ 0x142fd5740
// MS2-PIN: ??_GUIPortrait@@UEAAPEAXI@Z 0x141a91150
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiportrait.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiportrait.h"
#include "gameobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiActorManager.h>
#include <NiColor.h>
#include <NiAmbientLight.h>
#include <NiDirectionalLight.h>
#include <NiFrustum.h>
#include <NiTransform.h>

// ---- out-of-unit callees (bound to the exe by name) ----
// The world manager (singleton FUN_1403ed2d0).
class Unk_PortraitWorld
{
public:
    GameObject* FUN_141bd3620();                                // 0x141bd3620 the local player (NULL outside a field)
};
Unk_PortraitWorld* FUN_1403ed2d0();

class Unk_PortraitClock;
Unk_PortraitClock* FUN_14086d260();                             // the game clock
double FUN_141473280(Unk_PortraitClock* pClock);                // the current time
void FUN_14107b010();                                           // refreshes the sun direction constants
void FUN_14107b050(const NiPoint3& kDirection);                 // sets the sun direction constants
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                // the entity's scene graph
void FUN_141568d80(NiAVObject* pNode);
class Unk_PortraitEffectMgr;
Unk_PortraitEffectMgr* FUN_1409a8b20();
void FUN_1416aac60(Unk_PortraitEffectMgr* pMgr, NiNode* pNode);
extern efd::Point3 DAT_143a08cf8;                               // (0, 0, 1)

static float GetCurrentTime();                                  // 0x141a90fe0 (name invented)
static NiPoint3 GetHeadPosition(NiAVObject* pRoot);             // 0x141a91000 (name invented)

// @0x141a90500
UIPortrait::~UIPortrait()
{
}

// @0x141a90540
UIRenderView* FUN_141a90540(int nWidth, int nHeight, GameObject* pObject, float fLightDimmer)
{
    return EE_NEW UIPortrait(nWidth, nHeight, pObject, fLightDimmer);
}

// @0x141a905f0
// MS2-FUNCTIONAL: the NiPoint3 temporaries sit 4 bytes higher in the frame than in the exe
void UIPortrait::vfunc_2()
{
    if (m_spCamera)
    {
        GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd3620();
        if (pPlayer)
        {
            NiPoint3 kTarget = GetHeadPosition(FUN_141b6efc0(pPlayer->FUN_14123c410())) + NiPoint3(0.0f, 0.0f, 25.0f);
            NiPoint3 kPosition = kTarget + pPlayer->FUN_14123cc20() * 130.0f;
            m_spCamera->SetTranslate(kPosition);
            m_spCamera->Update(GetCurrentTime(), true);
            m_spCamera->LookAtWorldPoint(kTarget, DAT_143a08cf8);
            m_spCamera->Update(GetCurrentTime(), true);
            FUN_14107b050(m_spCamera->GetWorldDirection());
        }
    }
}
MS2_REPLACE_METHOD(0x141A905F0, UIPortrait, vfunc_2, 483, 0xECD7ABD9);

// @0x141a907e0
void UIPortrait::vfunc_3()
{
    FUN_14107b010();
}
MS2_REPLACE_METHOD(0x141A907E0, UIPortrait, vfunc_3, 19, 0x3D92B46E);

// @0x141a90800
void UIPortrait::vfunc_11(ATL::CAtlArray<efd::SmartPointer<NiActorManager> >& arrActors)
{
    if (!m_spClick)
        return;
    m_spClick->vfunc_14();
    if (arrActors.GetCount() < 1)
        return;
    m_spEffectRoot->DetachEffect(m_spDirLight);
    m_spEffectRoot->DetachEffect(m_spAmbientLight);
    m_spEffectRoot->AttachEffect(m_spDirLight);
    m_spEffectRoot->AttachEffect(m_spAmbientLight);
    m_spEffectRoot->UpdateEffects();
    m_spClick->vfunc_12(m_spEffectRoot);
    for (unsigned int i = 0; i < arrActors.GetCount(); ++i)
    {
        efd::SmartPointer<NiActorManager> spActor = arrActors[i];
        if (spActor)
        {
            NiNode* pNode = NiDynamicCast(NiNode, spActor->GetNIFRoot());
            if (pNode != 0)
            {
                pNode->DetachEffect(m_spDirLight);
                pNode->DetachEffect(m_spAmbientLight);
                pNode->AttachEffect(m_spDirLight);
                pNode->AttachEffect(m_spAmbientLight);
                pNode->UpdateEffects();
                m_spClick->vfunc_12(pNode);
                FUN_141568d80(pNode);
                FUN_1416aac60(FUN_1409a8b20(), pNode);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141A90800, UIPortrait, vfunc_11, 856, 0x80244AE0);

// @0x141a90b60
UIPortrait::UIPortrait(unsigned int uiWidth, unsigned int uiHeight, GameObject* pObject, float fLightDimmer)
    : UIRenderView(uiWidth, uiHeight, pObject, fLightDimmer)
{
}

// @0x141a90bd0
int UIPortrait::vfunc_14()
{
    m_spDirLight = EE_NEW NiDirectionalLight();
    m_spDirLight->SetDimmer(m_fLightDimmer);
    m_spDirLight->SetAmbientColor(NiColor(0.0f, 0.0f, 0.0f));
    m_spDirLight->SetDiffuseColor(NiColor(1.0f, 1.0f, 1.0f));
    m_spDirLight->SetSpecularColor(NiColor(1.0f, 1.0f, 1.0f));
    m_spAmbientLight = EE_NEW NiAmbientLight();
    m_spAmbientLight->SetDimmer(m_fLightDimmer);
    m_spAmbientLight->SetAmbientColor(NiColor(1.0f, 1.0f, 1.0f));
    m_spAmbientLight->SetDiffuseColor(NiColor(0.0f, 0.0f, 0.0f));
    m_spAmbientLight->SetSpecularColor(NiColor(0.0f, 0.0f, 0.0f));
    return 1;
}
MS2_REPLACE_METHOD(0x141A90BD0, UIPortrait, vfunc_14, 758, 0xCFDCFF6B);

// @0x141a90ed0
int UIPortrait::vfunc_15()
{
    m_spCamera = EE_NEW NiCamera();
    m_spCamera->SetViewFrustum(NiFrustum(-0.312384f, 0.312384f, 0.36397f, -0.36397f, 10.0f, 100000.0f, false));
    return 1;
}
MS2_REPLACE_METHOD(0x141A90ED0, UIPortrait, vfunc_15, 261, 0xDD71E32D);

// @0x141a90fe0
static float GetCurrentTime()
{
    return (float)FUN_141473280(FUN_14086d260());
}

// @0x141a91000
static NiPoint3 GetHeadPosition(NiAVObject* pRoot)
{
    if (pRoot != 0)
    {
        NiAVObject* pHead = pRoot->GetObjectByName("Bip01 Head");
        if (pHead != 0)
        {
            NiTransform kTransform = pHead->GetLocalTransform();
            if (pHead->GetParent() != 0)
            {
                kTransform = pHead->GetParent()->GetWorldTransform() * kTransform;
                return kTransform.m_Translate;
            }
        }
    }
    return NiPoint3(0.0f, 0.0f, 0.0f);
}
