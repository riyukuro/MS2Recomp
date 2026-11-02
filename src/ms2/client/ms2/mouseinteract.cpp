// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\mouseinteract.cpp
// MS2-RANGE: 0x140a78f70-0x140a7bb20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mouseinteract.cpp"
#define MS2_PTR_MOVE_CONVERT
#include "ms2/placeholder/ms2stdafx.h"
#include "mouseinteract.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "uiobject.h"
#include "pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#pragma pop_macro("max")
#pragma pop_macro("min")

// ---- RTTI-only action classes (the picker compares the player's current action against the picked object) ----
class ActionKeyObject { public: virtual ~ActionKeyObject(); };
class TalkAction : public ActionKeyObject { public: char m_pad[0x10]; int m_nNpcId; };                  // +0x18
class HoldAction : public ActionKeyObject { public: char m_pad[0x18]; int m_nNpcId; };                  // +0x20
struct PortalAction : public ActionKeyObject { char m_pad[0x10]; int FUN_140956110(); };   // a struct (.?AUPortalAction@@): as a class the cast never matched
class InteractAction : public ActionKeyObject { public: char m_pad[0x10]; CStringA m_strObjectId; };    // +0x18
class PullObjectWeaponAction : public ActionKeyObject { public: char m_pad[0x10]; MS2Ptr<Cube> m_hit; };    // +0x18
class UITalkCinematic : public UIObject {public:
    int GetLoaded();   // C3: was free FUN_141b1bfc0
};

// ---- exe callees ----
struct Unk_MiPlayer;
struct Unk_MiActionState;
CStringW GetStringCommon(int nStringId);
CStringW GetStringCommonByKey(const CStringW& str);
       // npc name (member: this=rcx, hidden return=rdx)
void FUN_140194470(Unk_Vec3* pDst, const Unk_Vec3* pSrc);
bool FUN_14147ad10(struct Vector3 const&, struct Vector3 const&, struct Vector3 const&, float);   // C3: was FUN_14147ad10
bool FUN_14028d470(float a, float b);
#define DAT_143b01a60 (*(char*)&efd::Point3::ZERO)          // C3: was extern char DAT_143b01a60

struct Unk_NpcTree;
class Unk_MiWorld
{
public:
    Unk_MiPlayer* FUN_141bd0cc0();                          // the local player
    MS2Ptr<CPortal> FUN_141bc2800(unsigned nId);

};
Unk_MiActionState* Unk_PlayerActionState(Unk_MiPlayer* pPlayer);
class Unk_ActionKeyManager   // C3: member view for the former free stand-ins
{
public:
    void ActivateCurrentAction();
    class ActionKeyObject* GetCurrentAction();
    int GetCur();
};
class MyPC   // C3: member view for the former free stand-ins
{
public:
    int FUN_141527160(int);
};
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
class CGuideManager   // C3: member view for the former free stand-ins
{
public:
    int IsRestricted(int);
};
void* FUN_140967100();
class UITalkManager   // C3: member view for the former free stand-ins
{
public:
    int IsTalkIntervalElapsed();
    void SendNpcTalkMode0();
};
int FUN_140855d10(int);   // C3: was FUN_140855d10



// ---- npc list iteration (a red-black tree of smart pointers, root at +0, nil node at +0x28) ----
// CAtlRBTree CNode: key +0, value (PCBaseRef) +8, color +0x10, left +0x18, right +0x20, parent +0x28 (exe 0x140a7b980
// reads [p+0x18], 0x140a7b9f0 [p+0x20]/[p+0x28])
struct Unk_NpcNode { char m_pad_00[0x18]; Unk_NpcNode* m_pLeft; Unk_NpcNode* m_pRight; Unk_NpcNode* m_pParent; };
struct PCBaseRef
{
    PCBase* m_p;
    // @0x140a7b390
    PCBaseRef(const PCBaseRef& r) : m_p(r.m_p) { if (m_p) m_p->IncRefCount(); }
    // @0x140a7b530
    ~PCBaseRef() { if (m_p) m_p->DecRefCount(); }
    // @0x140a7b650
    operator PCBase*() const { return m_p; }
    // @0x140a7b660
    PCBase* operator->() const { return m_p; }
};
void AtlThrow(long hr);
struct Unk_NpcTree
{
    Unk_NpcNode* m_pRoot;
    char m_pad_08[0x20];
    Unk_NpcNode* m_pNil;
    Unk_NpcNode* Begin();
    Unk_NpcNode* GetNext(Unk_NpcNode*& pos);
    PCBaseRef* GetAt(Unk_NpcNode* pos);
    bool IsNil(Unk_NpcNode* p);
    Unk_NpcNode* Minimum(Unk_NpcNode* p);
    Unk_NpcNode* Successor(Unk_NpcNode* p);
};
// @0x140a7b840
Unk_NpcNode* Unk_NpcTree::Begin()
{
    return Minimum(m_pRoot);
}
// @0x140a7b860
Unk_NpcNode* Unk_NpcTree::GetNext(Unk_NpcNode*& pos)
{
    Unk_NpcNode* pCur = pos;
    pos = Successor(pCur);
    return pCur;
}
// @0x140a7b8e0
PCBaseRef* Unk_NpcTree::GetAt(Unk_NpcNode* pos)
{
    do                                                      // ATLENSURE(pos != NULL)
    {
        int nCond = !!(pos != 0);
        do {} while (0);
        if (!nCond)
            AtlThrow(0x80004005L);
    } while (0);
    return reinterpret_cast<PCBaseRef*>(reinterpret_cast<char*>(pos) + 8);
}
// @0x140a7b940
bool Unk_NpcTree::IsNil(Unk_NpcNode* p)
{
    return p == m_pNil;
}
// @0x140a7b980
Unk_NpcNode* Unk_NpcTree::Minimum(Unk_NpcNode* p)
{
    if (p == 0 || IsNil(p))
        return 0;
    Unk_NpcNode* pCur = p;
    while (!IsNil(pCur->m_pLeft))
        pCur = pCur->m_pLeft;
    return pCur;
}
// @0x140a7b9f0
Unk_NpcNode* Unk_NpcTree::Successor(Unk_NpcNode* p)
{
    Unk_NpcNode* pNext;
    if (p == 0)
        return 0;
    if (!IsNil(p->m_pRight))
        return Minimum(p->m_pRight);
    pNext = p->m_pParent;
    Unk_NpcNode* pChild = p;
    while (!IsNil(pNext) && pChild == pNext->m_pRight) {
        pChild = pNext;
        pNext = pNext->m_pParent;
    }
    if (IsNil(pNext))
        pNext = 0;
    return pNext;
}



typedef ATL::CAtlList<efd::SmartPointer<egf::Entity> > Unk_PCEntList;
struct Unk_WsC_TagPtr                                     // smart pointer to the model list, pc.cpp's view
{
    void* m_pVt;
    Unk_PCEntList* m_p;
    ~Unk_WsC_TagPtr();                                    // 0x1409f20e0
    Unk_PCEntList* operator->() const;                      // 0x1409f2190
};

class Unk_Service6100017* FUN_1401cd040(struct Unk_EntityAppFramework*);   // C3: was FUN_1401cd040
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(char*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8



struct Unk_MiPlayer { char m_pad[0x1338]; char m_actionState[8]; };
// @0x140a7b810
Unk_MiActionState* Unk_PlayerActionState(Unk_MiPlayer* pPlayer)
{
    return reinterpret_cast<Unk_MiActionState*>(pPlayer->m_actionState);
}

// @0x140a78f70
CMouseInteract::CMouseInteract()
{
}
// @0x140a78fb0
CMouseInteract::~CMouseInteract()
{
}
// @0x140a78fe0
int CMouseInteract::vfunc_1(Unk_MouseRay* pRay)
{
    return false;
}
// @0x140a79000
int CMouseInteract::vfunc_2(Unk_MouseRay* pRay)
{
    return false;
}
// @0x140a79020
int CMouseInteract::vfunc_3()
{
    return false;
}
// @0x140a79030
int CMouseInteract::vfunc_4()
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    ((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->ActivateCurrentAction();
    return 1;
}
// @0x140a79080
void CMouseInteract::vfunc_5()
{
}
// @0x140a7b8a0
int CMouseInteract::vfunc_6()
{
    return 0;
}

// ---- npc ----
// @0x140a79090
int CMouseInteractNpc::vfunc_1(Unk_MouseRay* pRay)
{
    PCBase* pNpc = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pNpc != 0) {
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(pNpc->vfunc_18())));
        if (pNpc->vfunc_117() != 0) {
            pRay->strCursor = FUN_14028dfa0(CStringW(L"s_mouse_interact_hold"), reinterpret_cast<CNpc*>(pNpc)->FUN_141093310());
        } else {
            CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xe, ((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0());
            if (strName.GetLength() == 0)
                strName = GetStringCommon(0x62d);
            pRay->strCursor = FUN_14028dfa0(CStringW(L"s_mouse_interact_talk"), strName, reinterpret_cast<CNpc*>(pNpc)->FUN_141093310());
        }
        return true;
    }
    return false;
}
// @0x140a79340
int CMouseInteractNpc::vfunc_2(Unk_MouseRay* pRay)
{
    PCBase* pNpc = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pNpc != 0) {
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(pNpc->vfunc_18())));
        if (pNpc->vfunc_117() != 0)
            m_nAction = 6;
        else
            m_nAction = 0x14;
        m_nNpcId = ((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0();
        return true;
    }
    return false;
}
// @0x140a79400
int CMouseInteractNpc::vfunc_3()
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    if (((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCur() != m_nAction)
        return false;
    if (m_nAction == 0x14) {
        TalkAction* pAct = dynamic_cast<TalkAction*>(((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCurrentAction());
        if (pAct == 0)
            return false;
        return pAct->m_nNpcId == m_nNpcId;
    } else if (m_nAction == 6) {
        HoldAction* pAct = dynamic_cast<HoldAction*>(((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCurrentAction());
        if (pAct == 0)
            return false;
        return pAct->m_nNpcId == m_nNpcId;
    }
    return false;
}
// @0x140a79550
void CMouseInteractNpc::vfunc_5()
{
    m_nAction = 0x1e;
    m_nNpcId = 0;
}
// @0x140a79580
PCBase* CMouseInteractNpc::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    int bTalk = 1;
    int bHold = 1;
    if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsRestricted(2) != 0)
        bTalk = 0;
    if (((class UITalkManager*)(void*)(FUN_140967100()))->IsTalkIntervalElapsed() == 0)
        bTalk = 0;
    if (((class PCBase*)(struct Unk_MiPlayer*)(pPlayer))->FUN_14166c930() == 0x20)
        bHold = 0;
    Unk_NpcTree* pTree = reinterpret_cast<Unk_NpcTree*>(WorldService::GetInstance()->FUN_141bd36d0());
    for (Unk_NpcNode* pos = pTree->Begin(); pos != 0; pTree->GetNext(pos)) {
        PCBaseRef ref(*pTree->GetAt(pos));
        if (((class GameObject*)(class PCBase*)(ref.operator->()))->FUN_14123c660() != 0)
            continue;
        if (ref->vfunc_116() == 0)
            continue;
        MS2Ptr<CNpcData> spRec(((class CNpc*)(class PCBase*)(ref.operator->()))->GetNpcData());
        if (!spRec)
            continue;
        int bPick = 0;
        if (((class CNpc*)(class PCBase*)(ref.operator->()))->GetNpcData()->GetKind() != 0 && bTalk != 0)
            bPick = 1;
        if (FUN_140855d10(((class CNpc*)(class PCBase*)(ref.operator->()))->FUN_141092fa0()) != 0 && bTalk != 0)
            bPick = 1;
        if (((class CNpc*)(class PCBase*)(ref.operator->()))->FUN_141093c60() != 4 && bTalk != 0)
            bPick = 1;
        if (ref->vfunc_117() != 0 && bHold != 0)
            bPick = 1;
        if (bPick == 0)
            continue;
        float fSize = *(float*)(reinterpret_cast<char*>(spRec.operator->()) + 0x2dc);
        Unk_NiPoint3 vCenter(reinterpret_cast<const Vector3&>((const NiPoint3&)ref->vfunc_18()));
        vCenter.z += fSize * 0.5;
        if (FUN_14147ad10(*(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pOrigin)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pEnd)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(vCenter), (float)(fSize * 0.5)))
            return ref;
    }
    return 0;
}

// ---- portal ----
// @0x140a79a00
int CMouseInteractPortal::vfunc_1(Unk_MouseRay* pRay)
{
    MS2Ptr<CPortal> hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.IsNull())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&(const Vector3&)hit->FUN_14169d2f0()));
    if (hit->FUN_14169d280() == 0)
        pRay->strCursor = hit->FUN_14169c3b0();
    else
        pRay->strCursor = FUN_14028dfa0(CStringW(L"s_mouse_interact_portal"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, hit->FUN_14169d280()));
    return true;
}
// @0x140a79c00
int CMouseInteractPortal::vfunc_2(Unk_MouseRay* pRay)
{
    MS2Ptr<CPortal> hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.IsNull())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&(const Vector3&)hit->FUN_14169d2f0()));
    m_nPortalId = hit->FUN_14169d280();
    return true;
}
// @0x140a79cd0
int CMouseInteractPortal::vfunc_3()
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    if (((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCur() != 0x13)
        return false;
    PortalAction* pAct = dynamic_cast<PortalAction*>(((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCurrentAction());
    if (pAct == 0)
        return false;
    return pAct->FUN_140956110() == m_nPortalId;
}
// @0x140a79d90
void CMouseInteractPortal::vfunc_5()
{
    m_nPortalId = 0;
}
// @0x140a79db0
MS2Ptr<CPortal> CMouseInteractPortal::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    std::vector<int> aIds;
    WorldService::GetInstance()->FUN_141bc2980(&aIds);
    for (size_t i = 0; i < aIds.size(); i++) {
        const int& nId = aIds[i];
        MS2Ptr<CPortal> hit = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bc2800(nId);
        if (hit == (CPortal*)0)
            continue;
        efd::SmartPointer<egf::Entity> comp(TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(hit->m_idEntity));
        if (comp.data() == 0)
            continue;
        bool bFlag = false;
        comp->GetPropertyValue(0x14969c28, bFlag);
        if (!bFlag)
            continue;
        int nState;
        comp->GetPropertyValue<int>(0x1b8b1161, nState);
        if (nState == 1)
            continue;
        Unk_NiPoint3 vCenter(hit->FUN_14169d2f0());
        vCenter.z += hit->m_pos44.z * 0.5;
        float fRadius = hit->m_pos44.z * 0.5;
        if (FUN_14147ad10(*(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pOrigin)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pEnd)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(vCenter), fRadius))
            return hit;
    }
    return 0;
}

// ---- object ----
// @0x140a7a0c0
int CMouseInteractObject::vfunc_1(Unk_MouseRay* pRay)
{
    MS2Ptr<CInteractObject> hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.IsNull())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&(const Vector3&)hit->GetPos()));
    pRay->strCursor = FUN_14028dfa0(CStringW(L"s_mouse_interact_object"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xb, hit->GetRowId()));
    return true;
}
// @0x140a7a250
int CMouseInteractObject::vfunc_2(Unk_MouseRay* pRay)
{
    MS2Ptr<CInteractObject> hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.IsNull())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&(const Vector3&)hit->GetPos()));
    switch (hit->vfunc_5()) {
    case 8:
        m_nAction = 0x18;
        break;
    case 6:
        m_nAction = 4;
        break;
    default:
        m_nAction = 0x12;
        break;
    }
    m_strObjectId = hit->GetName();
    return true;
}
// @0x140a7a3d0
int CMouseInteractObject::vfunc_3()
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    if (((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCur() != m_nAction)
        return false;
    if (((class MyPC*)(struct Unk_MiPlayer*)(pPlayer))->FUN_141527160(0x19) == 0)
        return false;
    InteractAction* pAct = dynamic_cast<InteractAction*>(((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCurrentAction());
    if (pAct == 0)
        return false;
    return pAct->m_strObjectId == m_strObjectId;
}
// @0x140a7a4a0
void CMouseInteractObject::vfunc_5()
{
    m_nAction = 0x1e;
    m_strObjectId.Empty();
}
// @0x140a7a4e0
MS2Ptr<CInteractObject> CMouseInteractObject::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    ATL::CAtlArray<MS2Ptr<CInteractObject> > aObjs;
    WorldService::GetInstance()->FUN_141bc5f10(&aObjs);
    for (size_t i = 0; i < aObjs.GetCount(); i++) {
        MS2Ptr<CInteractObject> hit = aObjs[i];
        if (hit->vfunc_4() == 0)
            continue;
        MS2Ptr<CInteractObjectData> comp = hit->GetRow();
        if (comp.IsNull())
            continue;
        float fSize = *(float*)(reinterpret_cast<char*>(comp.operator->()) + 0x90);
        if (FUN_14028d470(fSize, 0.0f))
            continue;
        Unk_NiPoint3 vCenter(hit->GetPos());
        vCenter.z += fSize * 0.5;
        float fRadius = fSize * 0.5;
        if (FUN_14147ad10(*(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pOrigin)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pEnd)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(vCenter), fRadius))
            return hit;
    }
    return 0;
}

// ---- dynamic model (taxi / ugc banner) ----
// @0x140a7a780
int CMouseInteractDynamicModel::vfunc_1(Unk_MouseRay* pRay)
{
    if (!vfunc_2(pRay))
        return 0;
    pRay->strCursor = GetStringCommonByKey(m_strCursor);
    return 1;
}
// @0x140a7a810
int CMouseInteractDynamicModel::vfunc_2(Unk_MouseRay* pRay)
{
    void* pModel = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pModel == 0)
        return 0;
    reinterpret_cast<egf::Entity*>(pModel)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(pRay->vPick));
    return 1;
}
// @0x140a7a880
int CMouseInteractDynamicModel::vfunc_3()
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    if (((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCur() != m_nAction)
        return false;
    return true;
}
// @0x140a7a8e0
void* CMouseInteractDynamicModel::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_WsC_TagPtr it = WorldService::GetInstance()->FUN_141bd0420(m_dwModelKey);
    for (POSITION pos = it->GetHeadPosition(); pos != 0; it->GetNext(pos)) {
        efd::SmartPointer<egf::Entity> ref = it->GetAt(pos);
        NiPoint3 vPos = *reinterpret_cast<NiPoint3*>(&DAT_143b01a60);
        ref->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)*(reinterpret_cast<Unk_Vec3*>(&vPos)));
        float fSize = m_fPickSize;
        Unk_NiPoint3 vCenter(reinterpret_cast<const Vector3&>(vPos));
        vCenter.z += fSize * 0.5;
        float fRadius = fSize * 0.5;
        if (FUN_14147ad10(*(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pOrigin)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pEnd)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(vCenter), fRadius))
            return ref.data();
    }
    return 0;
}
// @0x140a7b4b0
CMouseInteractDynamicModel::CMouseInteractDynamicModel()
{
}
// @0x140a7b8b0
int CMouseInteractDynamicModel::vfunc_6()
{
    return 0;
}
// @0x140a7aad0
CMouseInteractTaxi::CMouseInteractTaxi()
{
    m_dwModelKey = 0x85359406;
    m_fPickSize = 150.0f;
    m_nAction = 8;
    m_strCursor = L"s_mouse_interact_taxi";
}
// @0x140a7b8c0
int CMouseInteractTaxi::vfunc_6()
{
    return 4;
}
// @0x140a7ab50
CMouseInteractUgcBanner::CMouseInteractUgcBanner()
{
    m_dwModelKey = 0xc7f9dd65;
    m_fPickSize = 225.0f;
    m_nAction = 0x10;
    m_strCursor = L"s_mouse_interact_ugcbanner";
}
// @0x140a7b8d0
int CMouseInteractUgcBanner::vfunc_6()
{
    return 5;
}

// ---- talk cancel ----
class Unk_MiUiMgr { public: };
// @0x140a7b2b0
UITalkCinematic* FUN_140a7b2b0(int nId)
{
    if (reinterpret_cast<Unk_MiUiMgr*>(TSingleton<CUIService>::GetInstance())) {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<UITalkCinematic*>((UIObject*)p);
    }
    return 0;
}
struct Unk_TalkUi { char m_pad[8]; };
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int GetSubSceneId();
};
// @0x140a7abd0
int CMouseInteractTalkCancel::vfunc_1(Unk_MouseRay* pRay)
{
    if (!vfunc_2(pRay))
        return 0;
    pRay->strCursor = GetStringCommonByKey(L"s_mouse_interact_talk_end");
    return 1;
}
// @0x140a7ac80
int CMouseInteractTalkCancel::vfunc_2(Unk_MouseRay* pRay)
{
    if (((class GFxSceneService*)(struct Unk_TalkUi*)(((Unk_TalkUi*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() != 0x6200031)
        return false;
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi == 0)
        return false;
    if (((class UITalkCinematic*)(class UITalkCinematic*)(pUi))->GetLoaded() == 0)
        return false;
    PCBase* pPlayer = reinterpret_cast<PCBase*>(((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    if (pPlayer == 0)
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(pPlayer->vfunc_18())));
    return true;
}
// @0x140a7ad30
int CMouseInteractTalkCancel::vfunc_3()
{
    return true;
}
// @0x140a7ad50
int CMouseInteractTalkCancel::vfunc_4()
{
    ((class UITalkManager*)(void*)(FUN_140967100()))->SendNpcTalkMode0();
    return true;
}

// ---- weapon object ----
// @0x140a7ad80
int CMouseInteractWeaponObject::vfunc_1(Unk_MouseRay* pRay)
{
    MS2Ptr<Cube> hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.get()) {
        pRay->strCursor = GetStringCommon(0x63c);
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&(const Vector3&)hit->FUN_1408b5370()));
        return true;
    }
    return false;
}
// @0x140a7ae80
int CMouseInteractWeaponObject::vfunc_2(Unk_MouseRay* pRay)
{
    MS2Ptr<Cube> hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.get()) {
        m_qwObjectId = hit->field18;
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&(const Vector3&)hit->FUN_1408b5370()));
        return true;
    }
    return false;
}
// @0x140a7af50
int CMouseInteractWeaponObject::vfunc_3()
{
    Unk_MiPlayer* pPlayer = ((Unk_MiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    if (((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCur() != 0xd)
        return false;
    PullObjectWeaponAction* pAct = dynamic_cast<PullObjectWeaponAction*>(((class Unk_ActionKeyManager*)(struct Unk_MiActionState*)(Unk_PlayerActionState(pPlayer)))->GetCurrentAction());
    if (pAct == 0)
        return false;
    if (!pAct->m_hit)
        return false;
    return pAct->m_hit->field18 == m_qwObjectId;
}
// @0x140a7b040
MS2Ptr<Cube> CMouseInteractWeaponObject::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    ATL::CAtlArray<MS2Ptr<Cube> > aWeapons;
    CubeMapInformationService* pMgr = ((class CubeMapInformationService*)FUN_1401cd040((struct Unk_EntityAppFramework*)(&DAT_143b059e8)));
    pMgr->FUN_1410d59c0(&aWeapons);
    for (size_t i = 0; i < aWeapons.GetCount(); i++) {
        MS2Ptr<Cube> hit = aWeapons[i];
        bool bFlag = false;
        hit->entity->GetPropertyValue(0xa0b6b179, bFlag);
        if (!bFlag)
            continue;
        if (hit->field48 != 0)
            continue;
        if (hit->field50 != 0)
            continue;
        Vector3 vPos = hit->FUN_1408b5370();
        float fSize = 150.0f;
        Unk_NiPoint3 vCenter(reinterpret_cast<const Vector3&>(vPos));
        vCenter.z += fSize * 0.5;
        float fRadius = fSize * 0.5;
        if (FUN_14147ad10(*(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pOrigin)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<const Vector3&>(*pEnd)), *(struct Vector3 const*)&static_cast<struct Unk_NiPoint3 const&>(vCenter), fRadius))
            return hit;
    }
    return 0;
}


MS2_EMIT_CRT_MEMMOVE_S();

// The out-of-line ctor of the cursor ray (gap2: ps1 had split it off; the v2525 TU map starts this TU at 0x140a78f00).
// In the exe the three vectors are efd::Point3 (default ctor 0x1402bd040) and the pick slot starts at Point3::ZERO;
// Unk_MouseRay (mouseinteract.h) is the trivial view its users still aggregate-initialise (unit_140ad1860), so the
// ctor is written on a same-layout view here.
// MS2-RANGE: 0x140a78f00-0x140a78f70 .text$mn
#include <efd/Point3.h>
#include <egf/Entity.h>  // C3: egf::Entity::GetPropertyValue<bool>
struct Unk_MouseRayInit
{
    Unk_MouseRayInit();
    efd::Point3 vOrigin;        // +0x00
    efd::Point3 vEnd;           // +0x0c
    efd::Point3 vPick;          // +0x18
    int m_pad_24;
    CStringW strCursor;         // +0x28
};
MS2_CHECK_SIZE(Unk_MouseRayInit, sizeof(Unk_MouseRay));

// @0x140a78f00
Unk_MouseRayInit::Unk_MouseRayInit()
    : vPick(efd::Point3::ZERO)
{
}

// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCInteractObject@@@@AEBAXPEAX@Z 0x140a7baf0
// MS2-PIN: ??0?$MS2Ptr@VCube@@@@QEAA@$$QEAV0@@Z 0x140a7b480
// MS2-PIN: ??_G?$MS2Ptr@VCube@@@@QEAAPEAXI@Z 0x140a7b670
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VCube@@@@V?$CElementTraits@V?$MS2Ptr@VCube@@@@@ATL@@@ATL@@QEAA@XZ 0x140a7b350
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCube@@@@V?$CElementTraits@V?$MS2Ptr@VCube@@@@@ATL@@@ATL@@QEAA@XZ 0x140a7b4f0
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCube@@@@V?$CElementTraits@V?$MS2Ptr@VCube@@@@@ATL@@@ATL@@QEBA_KXZ 0x140a7b830
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCube@@@@V?$CElementTraits@V?$MS2Ptr@VCube@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCube@@@@_K@Z 0x140a7b610
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCube@@@@V?$CElementTraits@V?$MS2Ptr@VCube@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCube@@@@_K@Z 0x140a7b7b0
