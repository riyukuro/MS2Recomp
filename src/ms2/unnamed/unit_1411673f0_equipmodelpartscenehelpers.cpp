// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Model-part scene helpers of the item customize / equip model code:
// scene node lookup by name through a CEquipModel part (its root, then the loaded mesh set), the NiMesh lookup used by the
// hair customizer, interpolator controller update by node name, the part highlight toggle, and the CAtlArray<MS2Ptr<Unk_PickTarget> >
// glue they instantiate. File and function names are invented (no __FILE__ string in the range).
// MS2-UNIT: unit_1411673f0
// MS2-RANGE: 0x1411673f0-0x141168140 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <set>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiStringExtraData.h>
#include <NiInterpController.h>
#include <NiRenderObject.h>
#include <efd/ServiceManager.h>
#include <egmAnimation/AnimationService.h>
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/client/ms2/itempickinghelper.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (names invented) --------------------------------------------------------------------------
// The local player (a world actor) and the world that owns it.
struct Unk_EmPlayer : public GameObject
{
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);                // the item equipped in a slot
};
struct Unk_EmWorld { Unk_EmPlayer* FUN_141bd0cc0(); };          // the local player
Unk_EmWorld* FUN_1403ed2d0();

// The app framework: +8 holds the service manager and the frame clock.
struct Unk_EmApp
{
    void* m_pad_00;
    efd::SmartPointer<Unk_ServiceManager> m_spServiceManager;   // +0x08
    double FUN_141473280();                                     // the application time
};
Unk_EmApp* FUN_14086d260();

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class). Next(bDescend) yields the next NiAVObject.
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

extern NiFixedString DAT_143ae51b8;     // name of the extra data that tags a node
extern NiFixedString DAT_143ae50e8;     // substring of that tag that excludes the node from the highlight

void FUN_1411dcc80(CEquipItem* pItem, CAtlArray<MS2Ptr<Unk_PickTarget> >& aParts);   // the item's model parts
int FUN_1405451c0(const CString* pName);                        // equip slot of a part name
void FUN_1414d37a0(NiRenderObject* pObject, int n);             // highlight on
void FUN_1414d3930(NiRenderObject* pObject);                    // highlight off

// @0x1411673f0
// The scene node of the part named pName: from the model root first, then from each loaded mesh of the part.
NiAVObject* Unk_PickTarget::FUN_1411673f0(const CString* pName) const
{
    NiAVObject* pFound = 0;
    if (FUN_141200ab0()->m_n20 == 0) {
        NiAVObject* pRoot = (NiAVObject*)reinterpret_cast<CEquipModel*>(const_cast<Unk_PickTarget*>(this))->vfunc_14();
        if (pRoot != 0) {
            pFound = pRoot->GetObjectByName((const char*)*pName);
            if (pFound == 0) {
                std::set<NiAVObjectPtr>* kPSet = &FUN_141201c90(); std::set<NiAVObjectPtr>& kSet = *kPSet;
                std::set<NiAVObjectPtr>::const_iterator itEnd = kSet.end();
                std::set<NiAVObjectPtr>::const_iterator it = kSet.begin();
                for (; it != itEnd; ++it) {
                    NiAVObjectPtr spNode(*it);
                    pFound = spNode->GetObjectByName((const char*)*pName);
                    if (pFound != 0)
                        break;
                }
                if (pFound == 0)
                    pFound = pRoot;
            }
        }
    } else {
        std::set<NiAVObjectPtr>* kPSet = &FUN_141201c90(); std::set<NiAVObjectPtr>& kSet = *kPSet;
        std::set<NiAVObjectPtr>::const_iterator itEnd = kSet.end();
        std::set<NiAVObjectPtr>::const_iterator it = kSet.begin();
        for (; it != itEnd; ++it) {
            NiAVObjectPtr spNode(*it);
            pFound = spNode->GetObjectByName((const char*)*pName);
            if (pFound != 0)
                break;
        }
    }
    return pFound;
}

// @0x1411676d0
// The mesh of the part named pPartName; failing that, the first "Editable " / "HR" mesh below the node of that name.
NiAVObject* Unk_PickTarget::FUN_1411676d0(const CString* pPartName) const
{
    NiAVObject* pNode = FUN_1411673f0(pPartName);
    NiMesh* pMesh = NiDynamicCast(NiMesh, pNode);
    if (pMesh != 0)
        return pMesh;
    NiNode* pParent = NiDynamicCast(NiNode, pNode);
    if (pParent != 0) {
        for (unsigned i = 0; i < pParent->GetChildCount(); i++) {
            if (pParent->GetAt(i) == 0)
                continue;
            if (pParent->GetAt(i)->GetName().Contains("Editable ")) {
                pMesh = NiDynamicCast(NiMesh, pParent->GetAt(i));
                if (pMesh != 0)
                    break;
            }
            if (pParent->GetAt(i)->GetName().Contains("HR")) {
                pMesh = NiDynamicCast(NiMesh, pParent->GetAt(i));
                if (pMesh != 0)
                    break;
            }
        }
    }
    return pMesh;
}

// @0x141167840
// Sets the value of every interpolator of the first interpolator controller of the node named strName, then updates it.
void FUN_141167840(NiAVObject* pRoot, const CString& strName, float fValue)
{
    if (pRoot == 0)
        return;
    NiAVObject* pObject = pRoot->GetObjectByName(NiFixedString((const char*)strName));
    if (pObject == 0)
        return;
    NiTimeController* pController = pObject->GetControllers();
    while (pController != 0) {
        NiInterpController* pInterp = NiDynamicCast(NiInterpController, pController);
        if (pInterp != 0) {
            int nCount = pInterp->GetInterpolatorCount();
            for (unsigned short us = 0; us < nCount; us++) {
                float fTime = (float)FUN_14086d260()->FUN_141473280();
                pInterp->UpdateValue(fTime, fValue, us);
                pInterp->Update(fTime);
            }
            return;
        }
        pController = pController->GetNext();
    }
}

// @0x1411679d0
// MS2-FUNCTIONAL: same instructions, but the frame is 0x10 larger and the loop locals sit in other slots (the exe keeps the node set in an unnamed temp)
// Highlights (fMode != 0) or un-highlights the meshes of the part; pNode narrows the highlight to one mesh.
void Unk_PickTarget::FUN_1411679d0(float fScale, float fMode, NiAVObject* pNode)
{
    if (this == 0)
        return;
    Unk_EmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CAtlArray<NiAVObject*> aRoots;
    if (FUN_141200ab0()->m_n20 == 0) {
        NiAVObject* pRoot = (NiAVObject*)reinterpret_cast<CEquipModel*>(this)->vfunc_14();
        aRoots.Add(pRoot);
    }
    std::set<NiAVObjectPtr>* kPSet = &FUN_141201c90(); std::set<NiAVObjectPtr>& kSet = *kPSet;
    std::set<NiAVObjectPtr>::const_iterator itEnd = kSet.end();
    std::set<NiAVObjectPtr>::const_iterator it = kSet.begin();
    for (; it != itEnd; ++it) {
        NiAVObjectPtr spNode(*it);
        NiAVObject* pRaw = spNode;
        aRoots.Add(pRaw);
    }
    if (aRoots.GetCount() == 0)
        return;
    for (unsigned i = 0; i < aRoots.GetCount(); i++) {
        NiAVObject* pRoot = aRoots[i];
        if (pRoot == 0)
            return;
        Unk_SceneWalker kWalker(pRoot);
        NiAVObject* pCur;
        while ((pCur = kWalker.Next(true)) != 0) {
            NiStringExtraData* pTag = NiDynamicCast(NiStringExtraData, pCur->GetExtraData(DAT_143ae51b8));
            if (pTag != 0 && pTag->GetValue().ContainsNoCase((const char*)DAT_143ae50e8))
                continue;
            NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pCur);
            if (pRender != 0) {
                if ((pNode != 0 && pNode != pRender) || fMode == 0.0f)
                    FUN_1414d3930(pRender);
                else
                    FUN_1414d37a0(pRender, 0);
            }
        }
        pRoot->UpdateProperties();
    }
}

// @0x141167cf0
// The mesh named strName of the local player's equipment slot of that name (from the equip item's parts, else the actor's model).
NiAVObject* FUN_141167cf0(const CString& strName)
{
    Unk_EmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    {
        MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655e10(FUN_1405451c0(&strName));
        if (spItem.get() != 0) {
            CAtlArray<MS2Ptr<Unk_PickTarget> > aParts;
            FUN_1411dcc80(spItem.operator->(), aParts);
            for (unsigned i = 0; i < aParts.GetCount(); i++) {
                MS2Ptr<Unk_PickTarget>& spPart = aParts[i];
                NiAVObject* pMesh = spPart.get()->FUN_1411676d0(&strName);
                if (pMesh != 0)
                    return pMesh;
                pMesh = spPart.get()->FUN_1411676d0(&spPart->FUN_141200ab0()->m_str08);
                if (pMesh != 0)
                    return pMesh;
            }
        } else {
            Unk_ServiceManager* pServices = FUN_14086d260()->m_spServiceManager;
            egmAnimation::AnimationService* pAnimation = pServices->GetSystemServiceAs<egmAnimation::AnimationService>();
            NiActorManager* pActor = pAnimation->GetActorManager(pPlayer->FUN_14123c460());
            if (pActor == 0)
                return 0;
            return NiDynamicCast(NiMesh, pActor->GetNIFRoot()->GetObjectByName((const char*)strName));
        }
    }
    return 0;
}
