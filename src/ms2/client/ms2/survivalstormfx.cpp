// survivalstormfx.cpp - Mushking Royale restore: CStormManager visuals. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: survivalstormfx
// MS2-NO-EXE: 0x140db539a Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

// The storm zone nifs on the effect root and the two minimap storm markers (GMS CStormManager, ctor 0x74b530).
// The zone data and the zone dialog (StormBar) are elsewhere: maplesurvival.cpp (CSurvivalStormManager::OnPacket,
// GMS 0xbe4750) calls the MushkingUI::StormFx_* events below.
//
// GMS layout (for reference): +4 base radius 5000.0f, +0x10 the B01 (shrink) node, +0x14 CAtlMap<u16 id, NiNode*>.
// The GMS minimap dialog kept the storm markers in its own CAtlMap<CStringW, entity> at +0x1d4; the KMS
// UIMinimapDialog has no such map, so this unit keeps it.

#include <map>
#include <math.h>
#include <NiNode.h>
#include <NiTimeController.h>
#include <efd/Point3.h>
#include "ms2/placeholder/asdisplayobject.h"   // ASMovieClip
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/nifeffectparam.h"      // CNifLoadingService::Load
#include "ms2/client/ms2/uiminimapentity.h"     // UIMinimapDialog, UIMinimapEntityStorm, MinimapViewport
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/maplesurvival.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/survivalstormfx.h"

class CEffectService   // member view (effectservice.h: GetLeastLoadedRoot, KMS twin of GMS 0x9c6e90)
{
public:
    class NiNode* GetLeastLoadedRoot();
};
class Unk_ResourceMgr* GetNifLoadingService();   // the CNifLoadingService instance (same view as questnavigator.cpp)

namespace SurvivalStormFx
{
const wchar_t* const kMarkerStorm = L"storm";
const wchar_t* const kMarkerPreview = L"storm_preview";

namespace
{
typedef UIMinimapDialog::EntityPtr EntityPtr;

struct StormFxState
{
    std::map<short, NiNodePtr> nodes;          // GMS +0x14
    NiNodePtr spShrink;                        // GMS +0x10 (Eff_Survival_Storm_B01)
    std::map<CStringW, EntityPtr> markers;     // GMS minimap dialog +0x1d4
    UIMinimapDialog* pMarkerOwner;             // the minimap dialog the markers were created on
    StormFxState() : pMarkerOwner(0) {}
};

// Heap-held and never freed: the NiNode / entity refs must not be released after Gamebryo shut down at exit.
StormFxState& S()
{
    static StormFxState* s = new StormFxState;
    return *s;
}

// GMS 0x74b1f0 / 0x74b220 test the id unsigned: > 2 -> half the base radius and A02, else the base radius and A01.
// (Their A03 branch, "> 4" after "<= 2", can never be taken; kept out the same way.)
bool IsLarge(short id) { return (unsigned short)id > 2; }
float ScaleDivisor(short id) { return IsLarge(id) ? kBaseRadius * 0.5f : kBaseRadius; }
const char* NifPath(short id)
{
    return IsLarge(id) ? "Data/Resource/Model/Effect/BG/Common/Eff_Survival_Storm_A02.nif"
                       : "Data/Resource/Model/Effect/BG/Common/Eff_Survival_Storm_A01.nif";
}

NiNode* EffectRoot()
{
    CEffectService* pSvc = TSingleton<CEffectService>::GetInstance();
    return pSvc ? pSvc->GetLeastLoadedRoot() : 0;
}

// GMS 0xb64ff0 Load(path, 0, 5, 0, 0, 0); KMS CNifLoadingService::Load(path, false, 5, 0, 0) gives a clone.
NiNodePtr LoadNif(const char* szPath)
{
    CNifLoadingService* pSvc = (CNifLoadingService*)GetNifLoadingService();
    if (pSvc == 0)
        return 0;
    NiAVObjectPtr spObj = pSvc->Load(CString(szPath), false, 5, 0, 0);
    return NiDynamicCast(NiNode, (NiAVObject*)spObj);
}

// GMS 0x9c7030 CEffectService::DetachChildFromRoots: here the node's own parent (the root it was attached to).
void Detach(NiNode* pNode)
{
    if (pNode == 0)
        return;
    NiNode* pParent = pNode->GetParent();
    if (pParent)
        NiAVObjectPtr spOld = pParent->DetachChild(pNode);
}

// GMS 0x74b290: translate to pos, scale = |radius / divisor| (rotation kept); the B01 node follows the position.
void Place(short id, NiNode* pNode, int nRadius, const NiPoint3& kPos)
{
    if (pNode)
    {
        pNode->SetTranslate(kPos);
        pNode->SetScale((float)fabs((float)nRadius / ScaleDivisor(id)));
    }
    if (S().spShrink)
        S().spShrink->SetTranslate(kPos);
}

// ---- minimap markers ------------------------------------------------------------------------------------------

UIMinimapDialog* FindMinimap()
{
    CUIService* pUI = TSingleton<CUIService>::GetInstance();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIObject> p = pUI->FindObject((eUIClassID)kMinimapUiId);
    if (p.get() == 0)
        return 0;
    return dynamic_cast<UIMinimapDialog*>((UIObject*)p);
}

// The markers belong to one minimap dialog instance; if it was replaced, forget them (their clips are gone).
UIMinimapDialog* MinimapForMarkers()
{
    UIMinimapDialog* pDlg = FindMinimap();
    StormFxState& s = S();
    if (pDlg != s.pMarkerOwner)
    {
        s.markers.clear();
        s.pMarkerOwner = pDlg;
    }
    return pDlg;
}

// GMS 0xd55600: size the marker clip to the radius in minimap units and move it to the projected position.
// GMS 0xd52d90 projects (x, y, 0) and (x + r*0.1, y + r*0.1, 0); w = h = |p0 - p1|.xy * 14.1, else 100.
void SetMarker(UIMinimapDialog* pDlg, UIMinimapEntity* pEntity, int nRadius, const efd::Point3& kPos)
{
    if (pDlg == 0 || pEntity == 0)
        return;
    int nSize = 100;
    MinimapViewport* pView = pDlg->m_viewport;
    if (pView)
    {
        NiPoint3 a(kPos.x, kPos.y, 0.0f), b(kPos.x + nRadius * 0.1f, kPos.y + nRadius * 0.1f, 0.0f), pa, pb;
        if (pView->WorldToMinimap(a, pa) && pView->WorldToMinimap(b, pb))
        {
            float dx = pa.x - pb.x, dy = pa.y - pb.y;
            nSize = (int)(sqrtf(dx * dx + dy * dy) * 14.1f);
        }
    }
    static_cast<UIMinimapEntityStorm*>(pEntity)->m_id = nRadius;
    pEntity->m_position = kPos;
    ASMovieClip* pClip = static_cast<ASMovieClip*>(pEntity->m_clip);
    if (pClip == 0)
        return;
    pClip->SetWidthInt(nSize);
    pClip->SetHeightInt(nSize);
    if (pView)
        pDlg->ProjectClip(kPos, pEntity->m_clip);
}

// GMS 0xd5e7f0: create the marker once (UIMinimapEntityStorm(radius, pos, name); the name is the swf icon).
void AddMarker(const wchar_t* szName, int nRadius, const efd::Point3& kPos)
{
    UIMinimapDialog* pDlg = MinimapForMarkers();
    if (pDlg == 0)
        return;
    CStringW strName(szName);
    StormFxState& s = S();
    if (s.markers.find(strName) != s.markers.end())
        return;
    EntityPtr spEntity(new UIMinimapEntityStorm(nRadius, kPos, strName));
    if (!pDlg->FUN_141a3e7d0(spEntity))   // CreateEntity (GMS 0xd5c620); false when the movie is not loaded
        return;
    if (ASMovieClip* pClip = static_cast<ASMovieClip*>(spEntity->m_clip))
        pClip->vfunc_4(true);
    SetMarker(pDlg, spEntity, nRadius, kPos);
    s.markers[strName] = spEntity;
}

// GMS 0xd57f90: new radius and position.
void UpdateMarker(const wchar_t* szName, int nRadius, const efd::Point3& kPos)
{
    UIMinimapDialog* pDlg = MinimapForMarkers();
    std::map<CStringW, EntityPtr>::iterator it = S().markers.find(CStringW(szName));
    if (pDlg && it != S().markers.end())
        SetMarker(pDlg, it->second, nRadius, kPos);
}

// GMS 0xd57e60: re-apply the stored radius (m_id) and position.
void RefreshMarker(const wchar_t* szName)
{
    UIMinimapDialog* pDlg = MinimapForMarkers();
    std::map<CStringW, EntityPtr>::iterator it = S().markers.find(CStringW(szName));
    if (pDlg == 0 || it == S().markers.end() || it->second == 0)
        return;
    UIMinimapEntityStorm* pStorm = static_cast<UIMinimapEntityStorm*>((UIMinimapEntity*)it->second);
    efd::Point3 kPos = pStorm->m_position;
    SetMarker(pDlg, pStorm, pStorm->m_id, kPos);
}

// GMS 0xd5e910: RemoveEntity (GMS 0xd5b7b0) and forget the name.
void RemoveMarker(const wchar_t* szName)
{
    UIMinimapDialog* pDlg = MinimapForMarkers();
    std::map<CStringW, EntityPtr>::iterator it = S().markers.find(CStringW(szName));
    if (it == S().markers.end())
        return;
    if (pDlg)
        pDlg->RemoveEntity(it->second);
    S().markers.erase(it);
}

}   // namespace
}   // namespace SurvivalStormFx

using namespace SurvivalStormFx;

// GMS 0x74baa0 (storm mode 0). zone.id = map key and nif choice, zone.radius = storm radius, zone.pos = storm centre,
// zone.previewRadius / zone.preview = preview circle (zone.step is not used by the visuals).
void MushkingUI::StormFx_OnAdd(const SurvivalStormZone& zone)
{
    NiNode* pRoot = EffectRoot();
    if (pRoot == 0)
        return;
    NiNodePtr spNode = LoadNif(NifPath(zone.id));
    if (spNode == 0)
        return;
    spNode->UpdateEffects();   // GMS 0xeb79b0
    std::map<short, NiNodePtr>::iterator it = S().nodes.find(zone.id);
    if (it != S().nodes.end())
        Detach(it->second);   // GMS SetAt overwrote (and leaked) a previous node with this id
    pRoot->AttachChild(spNode, false);
    S().nodes[zone.id] = spNode;
    NiPoint3 kPos(zone.pos[0], zone.pos[1], zone.pos[2]);
    Place(zone.id, spNode, zone.radius, kPos);

    AddMarker(kMarkerStorm, zone.radius, efd::Point3(zone.pos[0], zone.pos[1], zone.pos[2]));
    AddMarker(kMarkerPreview, zone.previewRadius, efd::Point3(zone.preview[0], zone.preview[1], zone.preview[2]));
}

// GMS 0x74b8d0 (storm mode 1). The packet's rounded float is the new radius; maplesurvival.cpp stores it in
// zone.radius.
void MushkingUI::StormFx_OnUpdate(const SurvivalStormZone& zone)
{
    std::map<short, NiNodePtr>::iterator it = S().nodes.find(zone.id);
    if (it != S().nodes.end())
        Place(zone.id, it->second, zone.radius, NiPoint3(zone.pos[0], zone.pos[1], zone.pos[2]));
    UpdateMarker(kMarkerStorm, zone.radius, efd::Point3(zone.pos[0], zone.pos[1], zone.pos[2]));
    RefreshMarker(kMarkerPreview);
}

// GMS 0x74b660 (storm mode 2). The B01 node stays.
void MushkingUI::StormFx_OnRemove(short id)
{
    std::map<short, NiNodePtr>::iterator it = S().nodes.find(id);
    if (it != S().nodes.end())
    {
        Detach(it->second);
        S().nodes.erase(it);
    }
    RemoveMarker(kMarkerStorm);
    RemoveMarker(kMarkerPreview);
}

// GMS 0x74b730 (storm mode 3): B01, every zone node and both markers.
void MushkingUI::StormFx_OnClear()
{
    StormFxState& s = S();
    Detach(s.spShrink);
    s.spShrink = 0;
    for (std::map<short, NiNodePtr>::iterator it = s.nodes.begin(); it != s.nodes.end(); ++it)
        Detach(it->second);
    s.nodes.clear();
    RemoveMarker(kMarkerStorm);
    RemoveMarker(kMarkerPreview);
}

// GMS 0x74b3c0 (storm mode 5): once, when zone 7 exists, put Eff_Survival_Storm_B01 on the effect root. It is
// positioned by the next 0x74b290 (zone update).
void MushkingUI::StormFx_OnShrinkStart()
{
    StormFxState& s = S();
    if (s.spShrink && s.spShrink->GetParent() == 0)
        s.spShrink = 0;   // detached by a field change (CEffectService::DetachAllChildren)
    if (s.spShrink || s.nodes.find(7) == s.nodes.end())
        return;
    NiNode* pRoot = EffectRoot();
    if (pRoot == 0)
        return;
    NiNodePtr spNode = LoadNif("Data/Resource/Model/Effect/BG/Common/Eff_Survival_Storm_B01.nif");
    if (spNode == 0)
        return;
    s.spShrink = spNode;
    NiTimeController::StartAnimations(spNode, 0.0f);   // GMS 0xc721f0(node, 0.0f)
    spNode->UpdateProperties();                         // GMS 0xeb7bd0
    spNode->UpdateEffects();                            // GMS 0xeb79b0
    spNode->Update(0.0f, true);                         // GMS 0xeb76c0 (GMS passes its current time, 0xafe070)
    pRoot->AttachChild(spNode, false);
}

#endif   // MS2_HOOK_DLL
