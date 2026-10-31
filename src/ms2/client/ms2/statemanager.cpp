// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CStateManager (per-actor state machine), the actor states
// StateNone / StatePush / StateRegen / StateRide / StateRope / StateMoveSkill and CStateService (efd scene-state
// service). See statemanager.h.
// MS2-UNIT: client\ms2\statemanager.cpp
// MS2-PIN: ??_7CStateService@@6B?$TSingleton@VCStateService@@@@@ 0x142f72250
// MS2-PIN: ??_7CStateService@@6BISystemService@efd@@@ 0x142f72260
// MS2-RANGE: 0x1417da7a0-0x1417e4730 .text$mn
// MS2-RANGE: 0x140103470-0x140103f20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x140103590 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUnk_StateArg22@@@@QEBAPEAVUnk_StateArg22@@XZ 0x1417dd2d0 ; unique
// MS2-PIN: ?erase@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@@2@0@Z 0x1417dedd0 ; unique
// MS2-PIN: ?erase@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@@2@@Z 0x1417deeb0 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$MS2Ptr@VUnk_StateArg22@@@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_List_node@V?$MS2Ptr@VUnk_StateArg22@@@@PEAX@std@@@2@@Z 0x1417def20 ; unique
// MS2-PIN: ?pop_front@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEAAXXZ 0x1417def50 ; unique
// MS2-PIN: ?push_back@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEAAX$$QEAV?$MS2Ptr@VUnk_StateArg22@@@@@Z 0x1417def90 ; unique
// MS2-PIN: ?rbegin@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@@std@@@2@XZ 0x1417defe0 ; prop
// MS2-PIN: ?rend@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@@std@@@2@XZ 0x1417df020 ; unique
// MS2-PIN: ?size@?$list@V?$MS2Ptr@VUnk_StateArg22@@@@V?$allocator@V?$MS2Ptr@VUnk_StateArg22@@@@@std@@@std@@QEBA_KXZ 0x1417df060 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUnk_SMSkillData@@@@QEAA@XZ 0x1417df770 ; unique
// MS2-PIN: ??4?$MS2Ptr@VUnk_StateArg22@@@@QEAAAEAV0@H@Z 0x1417df790 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUnk_SMSkillData@@@@QEAAAEAV1@PEAVUnk_SMSkillData@@@Z 0x1417df7c0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUnk_SMSkillData@@@@QEBA_NPEAVUnk_SMSkillData@@@Z 0x1417df830 ; unique
// MS2-PIN: ??_GStateMoveSkill@@UEAAPEAXI@Z 0x1417df870 ; unique
// MS2-PIN: ??_GStateNone@@UEAAPEAXI@Z 0x1417dfb10 ; prop
// MS2-PIN: ??_GStatePush@@UEAAPEAXI@Z 0x1417dfc20 ; prop
// MS2-PIN: ??_GStateRegen@@UEAAPEAXI@Z 0x1417e0550 ; unique
// MS2-PIN: ??_GStateRide@@UEAAPEAXI@Z 0x1417e0ce0 ; prop
// MS2-PIN: ??_GStateRope@@UEAAPEAXI@Z 0x1417e2410 ; unique
// MS2-PIN: ??$AddDependency@UUnk_SMDepPlatform@@@IDependencyRegistrar@efd@@QEAA_NI@Z 0x1417e3240 ; unique
// MS2-PIN: ??0?$CRBTree@IV?$SmartPointer@VCSceneStateBase@@@efd@@UUnk_SMSceneTraits@@V?$CElementTraits@V?$SmartPointer@VCSceneStateBase@@@efd@@@ATL@@@ATL@@IEAA@_K@Z 0x1417e32a0 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@IV?$SmartPointer@VCSceneStateBase@@@efd@@UUnk_SMSceneTraits@@V?$CElementTraits@V?$SmartPointer@VCSceneStateBase@@@efd@@@ATL@@@ATL@@IEAA@XZ 0x1417e3500 ; unique
// MS2-PIN: ?Find@?$CRBTree@IV?$SmartPointer@VCSceneStateBase@@@efd@@UUnk_SMSceneTraits@@V?$CElementTraits@V?$SmartPointer@VCSceneStateBase@@@efd@@@ATL@@@ATL@@IEBAPEAVCNode@12@I@Z 0x1417e3820 ; unique
// MS2-PIN: ?TypeCast@CStateService@@UEBA_NIPEAPEAX@Z 0x1417e4610 ; unique
// MS2-PIN: ?TypeCast@CStateService@@UEBA_NIPEAPEBX@Z 0x1417e4660 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statemanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <NiPlane.h>
#include <cfloat>

#include "statemanager.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/scenestatelogo.h"
#include "ms2/client/ms2/scenestatemodeselect.h"
#include "ms2/client/ms2/scenestatelogin.h"
#include "ms2/client/ms2/scenestatemulti.h"
#include "ms2/client/ms2/scenestateloading.h"
#include "ms2/client/ms2/scenestatemove.h"
#include "ms2/client/ms2/scenestaterelocateworld.h"
#include "ms2/placeholder/scenestategame.h"
#include <new>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/randomeffectparam.h"
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/statemanager_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
#include "ms2/ms2recover.h"
#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/cpet.h"
#include "ms2/unnamed/unit_140ad1860.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/reconnectionmanagercli.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/uiservice.h"

// The unit includes the statics six more times (without the pointer object), then the class-info and skill/stun.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_3(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_4(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill5 = "skill";
static CString s_strStun5 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_5(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames6[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill6 = "skill";
static CString s_strStun6 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_6(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill7 = "skill";
static CString s_strStun7 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_7(17, 0.75f, 0.25f, 2.25f, 10);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CStateService);

static CString s_strSkill8 = "skill";
static CString s_strStun8 = "stun";

// ---- unit-local placeholders ----

extern int DAT_143ab0248;
extern int DAT_143ab2914;

// The game-context singleton (FUN_14025e7c0 returns DAT_143aacd00): feature / permission queries.
CInputKeyHandler* FUN_14025e7c0();

// CMouseController (DAT_143ab3850) and the entity world manager (DAT_143ab3910).
class Unk_SMEntityMgr { public: egf::Entity* FUN_1411cf440(const egf::EntityID& id); };
Unk_SMEntityMgr* FUN_1409670f0();

// A zone marker (BoxCollision): position at +0x148, the entity at +0x28.
class Unk_SMMarker : public CPtred
{
public:
    efd::Point3 FUN_140adf8e0();
    egf::EntityPtr FUN_140adf980();
};
// The world service: marker lookup by entity / by name.
class Unk_SMWorld : public WorldService
{
public:
    MS2Ptr<Unk_SMMarker> FUN_141bc4f10(egf::Entity* pEntity);
    MS2Ptr<Unk_SMMarker> FUN_141bc4e70(CStringA strName);
};

class Unk_SMField690 { public: char m_pad[0x18]; efd::Point3 m_pos18; };

// Actor casts (efd TypeCast with a class id) and PCBase helpers.
PCBase* FUN_140974230(PCBase* p);           // as PC (0x6200003)
PCBase* FUN_141468360(PCBase* p);           // as Ridee (0x6200045)
PCBase* FUN_140ddc910(PCBase* p);           // 0x6200064
PCBase* FUN_140ac06f0(PCBase* p);           // 0x6200081
int FUN_14166c930(PCBase* p);               // current state id of the actor
void FUN_14166d8b0(PCBase* p, float f);
void FUN_1410a77e0(PCBase* p, float f);
void FUN_141678160(PCBase* p, efd::Point3 kPos);
void FUN_1416781a0(PCBase* p, int n);
void FUN_141671990(PCBase* p, float f);
void FUN_141678290(PCBase* p, egf::EntityID kId, efd::Point3 kPos);
egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);             // the entity's id (+0x40)
egf::Entity* FUN_1408a9280(const egf::EntityPtr& sp);           // folded copy of SmartPointer<Entity>::operator Entity*
void FUN_141678300(PCBase* p, int n);
Unk_SMField690* FUN_141675eb0(PCBase* p);
void* FUN_14166d220(PCBase* p);             // +0x150
void* FUN_141240f20(void* p);               // +0x18
class Unk_SMHitReport
{
public:
    egf::EntityID FUN_140cfaf70();   // id of the entity stood on
};
float FUN_14029d220(float f);               // fabs
void* FUN_140cea080();                      // a global accessor whose result the exe drops
float FUN_14028d280(unsigned n);            // milliseconds -> seconds

// The helper component of vfunc_103 (a skill record holder): +0x30 table row.
class Unk_SMRow { public: char m_pad[0xad]; unsigned char m_bAd; };
class Unk_SMTable { public: Unk_SMRow* FUN_14063ed50(); };
class Unk_PCBaseComp_b18 : public CPtred
{
public:
    int FUN_141759960();
    char m_pad_18[0x18];
    Unk_SMTable m_table30;
};

// efd::ClassInfo layout (m_Classes is protected; the exe reads m_Classes[0].m_ID inline)
struct Unk_SMClassDef { efd::ClassID m_ID; const char* m_Name; const efd::ClassInfo* m_ClassInfo; efd::UInt32 m_Offset; };
struct Unk_SMClassInfoView { efd::UInt32 m_ClassCount; Unk_SMClassDef m_Classes[32]; };

// @0x1417ddbf0
bool FUN_1417ddbf0(const efd::ClassInfo* pInfo, int nId)
{
    if (pInfo == 0)
        return false;
    if (reinterpret_cast<const Unk_SMClassInfoView*>(pInfo)->m_Classes[0].m_ID == (efd::ClassID)nId)
        return true;
    return false;
}

// @0x1417dcb20
PCBase* FUN_1417dcb20(PCBase* p)
{
    PCBase* pOut = 0;
    if (p != 0 && p->TypeCast(0x6200050, (void**)&pOut))
        return pOut;
    else
        return 0;
}

// ---- CStateManager ----

// @0x1417da7a0
CStateManager::CStateManager(PCBase* pOwner)
    : m_nPrev(0), m_nCur(0), m_pOwner(pOwner), m_states(17, 0.75f, 0.25f, 2.25f, 10), m_pos(efd::Point3::ZERO)
{
    m_states.SetAt(0, new StateNone(m_pOwner));
    m_pState = FUN_1417db1e0(0);
    m_pState->vfunc_4(0);
}

// @0x1417da950
CStateManager::~CStateManager()
{
    for (POSITION pos = m_states.GetStartPosition(); pos != 0; m_states.GetNext(pos))
    {
        State* pState = m_states.GetValueAt(pos);
        if (pState != 0)
        {
            delete pState;
            pState = 0;
        }
    }
    m_states.RemoveAll();
}

// @0x1417daa70
void CStateManager::FUN_1417daa70()
{
    m_requests.clear();
}

// @0x1417daaa0
void CStateManager::FUN_1417daaa0(double fTime)
{
    float fDelta = (float)fTime;
    {
        MS2Ptr<Unk_StateArg22> spReq = FUN_1417dc230(&fDelta);
        if (spReq.get() != 0)
            FUN_1417db550(spReq.get());
    }
    m_pState->vfunc_3((double)fDelta);
    m_pState->vfunc_9((double)fDelta);
    bool bCheck = true;
    if (DAT_143ab0248 == 2)
        bCheck = DAT_143ab2914 >= 0x33;
    if (bCheck)
    {
        CInputKeyHandler* pCtx = FUN_14025e7c0();
        if (FUN_1417ddbf0(m_pOwner != 0 ? m_pOwner->GetClassDesc() : 0, 0x6200004) && pCtx != 0 && pCtx->FUN_14116d9c0(0x23, true, 0)
            && pCtx->FUN_14116d950(0x1d, true, 0))
        {
            Unk_SMStateSlots* pSlots = (Unk_SMStateSlots*)FUN_1417db1e0(2);
            if (pSlots != 0)
                pSlots->vfunc_36(pSlots->vfunc_37() == 0);
        }
    }
    if (m_pState->vfunc_20() != 0)
    {
        if (FUN_1417ddbf0(m_pOwner != 0 ? m_pOwner->GetClassDesc() : 0, 0x6200004))
        {
            if (m_pOwner->vfunc_18() != m_pos)
            {
                int bFound = 0;
                egf::EntityID kId = static_cast<Unk_SMHitReport*>(FUN_141240f20(FUN_14166d220(m_pOwner)))->FUN_140cfaf70();
                egf::Entity* pEntity = FUN_1409670f0()->FUN_1411cf440(kId);
                if (pEntity != 0)
                {
                    MS2Ptr<Unk_SMMarker> spMarker = reinterpret_cast<Unk_SMWorld*>(WorldService::GetInstance())->FUN_141bc4f10(pEntity);
                    if (spMarker.get() != 0)
                    {
                        if (m_pOwner->FUN_14123c360() == efd::Point3::ZERO)
                            bFound = 1;
                    }
                }
                if (!bFound)
                    FUN_1417dafa0(1, 0, 0, 0);
            }
        }
    }
}

// @0x1417daeb0
void CStateManager::FUN_1417daeb0(int state, State* pState)
{
    MS2_ASSERT_MSG_AT(0x45, L"state == pState->GetState()", state == pState->vfunc_1());
    State* pOld = 0;
    m_states.Lookup(state, pOld);
    m_states.SetAt(state, pState);
    if (pOld != 0)
    {
        if (pOld != 0)   // the exe's safe-delete idiom re-tests and clears the pointer
        {
            delete pOld;
            pOld = 0;
        }
    }
}

// @0x1417dafa0
void CStateManager::FUN_1417dafa0(int nState, StateData* pData, int nSub, int bForce)
{
    if (m_pOwner->FUN_14123bea0() == 0)
        return;
    if (m_states.Lookup(nState) == 0)
        return;
    if (nState == m_nCur && bForce == 0 && m_pState->vfunc_25(nSub, pData))
        return;
    if (nState == 0x10)
        FUN_1417dc110();
    m_pState->vfunc_5(nState);
    m_states.Lookup(nState, m_pState);
    if (m_pState == 0)
        m_pState = FUN_1417db1e0(0);
    m_nPrev = m_nCur;
    if (nSub != 0)
        m_pState->vfunc_2(nSub);
    if (FUN_1417ddbf0(m_pOwner != 0 ? m_pOwner->GetClassDesc() : 0, 0x6200004))
        TSingleton<CMouseController>::GetInstance()->FUN_140ad1f30(m_nCur, nState);
    m_nCur = nState;
    m_pState->vfunc_4(pData);
    if (m_pState->vfunc_20() != 0)
        m_pos = m_pOwner->vfunc_18();
}

// @0x1417db1c0
State* CStateManager::GetState()
{
    return m_pState;
}

// @0x1417db1e0
State* CStateManager::FUN_1417db1e0(int nId)
{
    State* pState = 0;
    m_states.Lookup(nId, pState);
    return pState;
}

// @0x1417db230
void CStateManager::FUN_1417db230(int nValue)
{
    m_pState->vfunc_2(nValue);
}

// @0x1417db270
int CStateManager::GetCur()
{
    return m_nCur;
}

// @0x1417db290
int CStateManager::FUN_1417db290()
{
    return m_pState->FUN_1417b7e40();
}

// @0x1417db2c0
int CStateManager::GetPrev()
{
    return m_nPrev;
}

// @0x1417db2e0
void CStateManager::FUN_1417db2e0(Unk_StateArg22* pReq)
{
    if (m_pOwner->FUN_14123bea0() == 0)
        return;
    {
        MS2Ptr<Unk_StateArg22> spNew(pReq);
        m_requests.push_back(static_cast<MS2Ptr<Unk_StateArg22>&&>(spNew));
    }
    // MS2: the queue is walked newest first (reverse iterators); the oldest requests past 100 ms are dropped
    float fSum = pReq->m_fTime;
    std::list<MS2Ptr<Unk_StateArg22> >::reverse_iterator it = m_requests.rbegin();
    for (; it != m_requests.rend(); it++)
    {
        MS2Ptr<Unk_StateArg22> spReq = *it;
        if (spReq->m_fTime != 0.0f)
        {
            fSum = spReq->m_fTime;
            it++;
            break;
        }
    }
    for (; it != m_requests.rend(); it++)
    {
        MS2Ptr<Unk_StateArg22> spReq = *it;
        fSum = fSum + spReq->m_fTime;
        FUN_140cea080();
        if (fSum > FUN_14028d280(100))
            break;
    }
    m_requests.erase(m_requests.begin(), it.base());
}

// @0x1417db550
// MS2-FUNCTIONAL: GameObject::vfunc_22 takes Point3 by value in the exe (shared header gameobject.h; see shared-header-leftovers)
void CStateManager::FUN_1417db550(Unk_StateArg22* pReq)
{
    if (pReq == 0)
        return;
    PCBase* pActor = FUN_140974230(m_pOwner);
    if (pActor != 0)
    {
        pActor->vfunc_22(pReq->m_vel3c);
        FUN_141678160(pActor, pReq->m_pos48);
        FUN_1416781a0(pActor, pReq->m_n54);
        FUN_141671990(pActor, 1.0f);
        int bApply = 0;
        if (FUN_14166c930(pActor) != 0x10 && pReq->m_nState != 0x10 && pReq->m_nState != 4)
        {
            bApply = 1;
        }
        else if (FUN_14166c930(pActor) == 0x10)
        {
            MS2Ptr<Unk_PCBaseComp_b18> spComp = pActor->vfunc_103();
            if (spComp.get() != 0)
            {
                if (pReq->m_n64 != 0)
                {
                    if (spComp->FUN_141759960() != pReq->m_n64)
                        bApply = 1;
                }
                if (pReq->m_nState != 0x10)
                {
                    if (spComp->m_table30.FUN_14063ed50()->m_bAd != 0)
                        bApply = 1;
                }
            }
        }
        if (bApply)
            FUN_1417dc4c0(pReq);
    }
    else if ((pActor = FUN_1417dcb20(m_pOwner)) != 0)
    {
        pActor->vfunc_22(pReq->m_vel3c);
        pActor->vfunc_19(pReq->m_pos20);
        pActor->vfunc_21(pReq->m_dir2c);
        FUN_14166d8b0(pActor, pReq->m_f58);
        FUN_1410a77e0(pActor, pReq->m_fA4);
        pActor->vfunc_59(pReq->m_nState, 0, pReq->m_nSub, 0);
    }
    else if ((pActor = FUN_141468360(m_pOwner)) != 0)
    {
        FUN_1417dbd00(pActor, pReq);
        pActor->vfunc_22(pReq->m_vel3c);
        pActor->vfunc_21(pReq->m_dir2c);
        FUN_14166d8b0(pActor, pReq->m_f58);
        if (FUN_14166c930(pActor) != 0x10 && pReq->m_nState != 0x10)
        {
            int nForce = 0;
            if (GetCur() == pReq->m_nState)
            {
                if (m_pState->vfunc_28(MS2Ptr<Unk_StateArg22>(pReq)))
                    nForce = 1;
            }
            MS2Ptr<StateData> spData = FUN_1417dc9a0(pReq->m_nState);
            if (spData.get() != 0)
                spData->vfunc_2(reinterpret_cast<Unk_StateDataArg*>(pReq));   // MS2: StateData slot 2 reads the same record
            pActor->vfunc_59(pReq->m_nState, spData.get(), pReq->m_nSub, nForce);
        }
    }
    else if ((pActor = FUN_140ddc910(m_pOwner)) != 0)
    {
        pActor->vfunc_22(pReq->m_vel3c);
        pActor->vfunc_19(pReq->m_pos20);
        pActor->vfunc_21(pReq->m_dir2c);
        FUN_14166d8b0(pActor, pReq->m_f58);
        FUN_1410a77e0(pActor, pReq->m_fA4);
        pActor->vfunc_59(pReq->m_nState, 0, pReq->m_nSub, 0);
    }
    else if ((pActor = FUN_140ac06f0(m_pOwner)) != 0)
    {
        FUN_1417dbd00(pActor, pReq);
        pActor->vfunc_22(pReq->m_vel3c);
        pActor->vfunc_21(pReq->m_dir2c);
        FUN_14166d8b0(pActor, pReq->m_f58);
        pActor->vfunc_59(pReq->m_nState, 0, pReq->m_nSub, 0);
    }
}

// @0x1417dbd00
void CStateManager::FUN_1417dbd00(PCBase* pActor, Unk_StateArg22* pReq)
{
    bool bSnap = true;
    efd::Point3 kDelta = pActor->vfunc_18() - pReq->m_pos20;
    float fDz = kDelta.z;
    kDelta.z = 0.0f;
    float fDist = kDelta.Length();
    if ((pReq->m_nState == 2 || pReq->m_nState == 0x1b || pReq->m_nState == 0x1c || pReq->m_nState == 0x1e
            || pReq->m_nState == 5 || pReq->m_nState == 3 || pReq->m_nState == 1 || pReq->m_nState == 0xd
            || pReq->m_nState == 0x41 || pReq->m_nState == 0x46) && fDist < 100.0f)
        bSnap = false;
    float fLimit = 200.0f;
    if (pReq->m_nState == 0x1e)
        fLimit = 400.0f;
    if (FUN_14029d220(fDz) > fLimit)
        bSnap = true;
    if (pReq->m_nState == 0x1e && FUN_14166c930(pActor) != 0x1e)
        bSnap = true;
    if (bSnap)
        pActor->vfunc_19(pReq->m_pos20);
}

// @0x1417dbef0
void CStateManager::FUN_1417dbef0(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    m_pState->AnimActivated(pkManager, eSequenceID, pkSeq, fEventTime);
}

// @0x1417dbf50
void CStateManager::FUN_1417dbf50(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    m_pState->TextKeyEvent(pkManager, eSequenceID, kTextKey, pkMatchObject, pkSeq, fEventTime);
}

// @0x1417dbfc0
void CStateManager::FUN_1417dbfc0(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    m_pState->EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
}

// @0x1417dc020
void CStateManager::FUN_1417dc020(int n)
{
    if (m_pState != 0)
        m_pState->vfunc_31(n);
}

// @0x1417dc070
int CStateManager::FUN_1417dc070(int nState)
{
    switch (nState)
    {
    case 0xe:
    case 0x20:
    case 0x2b:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x45:
        return 0;
    default:
        return 1;
    }
}

// @0x1417dc110
void CStateManager::FUN_1417dc110()
{
    for (std::list<MS2Ptr<Unk_StateArg22> >::iterator it = m_requests.begin(); it != m_requests.end(); it++)
    {
        MS2Ptr<Unk_StateArg22> spReq = *it;
        FUN_1417db550(spReq.get());
        m_pState->vfunc_3((double)spReq->m_fTime);
        m_pState->vfunc_9((double)spReq->m_fTime);
    }
    m_requests.clear();
}

// @0x1417dc230
MS2Ptr<Unk_StateArg22> CStateManager::FUN_1417dc230(float* pDelta)
{
    if (m_requests.empty())
        return MS2Ptr<Unk_StateArg22>(0);
    MS2Ptr<Unk_StateArg22> spReq = *m_requests.begin();
    if (spReq->m_fTime >= *pDelta)
    {
        spReq->m_fTime -= *pDelta;
        if (spReq->m_nA8 != 0)
        {
            return MS2Ptr<Unk_StateArg22>(0);
        }
        else
        {
            spReq->m_nA8 = 1;
            return spReq;
        }
    }
    else
    {
        if (m_requests.size() == 1)
        {
            spReq->m_fTime = 0.0f;
            if (spReq->m_nA8 != 0)
            {
                return MS2Ptr<Unk_StateArg22>(0);
            }
            else
            {
                spReq->m_nA8 = 1;
                return spReq;
            }
        }
        else
        {
            m_requests.pop_front();
            spReq = *m_requests.begin();
            return spReq;
        }
    }
}

// @0x1417dc4c0
void CStateManager::FUN_1417dc4c0(Unk_StateArg22* pReq)
{
    PCBase* pActor = FUN_140974230(m_pOwner);
    bool bPushed = FUN_141675eb0(pActor)->m_pos18 != efd::Point3::ZERO;
    if (!bPushed)
    {
        if (FUN_1417dc070(GetCur()) == 1)
        {
            FUN_1417dbd00(pActor, pReq);
            pActor->vfunc_21(pReq->m_dir2c);
            FUN_14166d8b0(pActor, pReq->m_f58);
        }
    }
    if (!pReq->m_str88.IsEmpty())
    {
        MS2Ptr<Unk_SMMarker> spMarker = reinterpret_cast<Unk_SMWorld*>(WorldService::GetInstance())->FUN_141bc4e70(pReq->m_str88);
        if (spMarker.get() != 0)
        {
            pActor->vfunc_19(spMarker->FUN_140adf8e0() + pReq->m_pos78);
            egf::Entity* pEntity = spMarker->FUN_140adf980();
            if (pEntity != 0)
                FUN_141678290(pActor, *FUN_1408b76f0(FUN_1408a9280(spMarker->FUN_140adf980())), spMarker->FUN_140adf8e0());
        }
    }
    if (pReq->m_nA0 != 0x7fffffff)
        FUN_141678300(pActor, pReq->m_nA0);
    if (!m_pState->vfunc_32())
        return;
    if (pReq->m_nState == 0xd || pReq->m_nState == 0x12)
        return;
    int nForce = 0;
    if (GetCur() == pReq->m_nState)
    {
        if (m_pState->vfunc_28(MS2Ptr<Unk_StateArg22>(pReq)))
            nForce = 1;
    }
    MS2Ptr<StateData> spData = FUN_1417dc9a0(pReq->m_nState);
    if (spData.get() != 0)
        spData->vfunc_2(reinterpret_cast<Unk_StateDataArg*>(pReq));
    pActor->vfunc_59(pReq->m_nState, spData.get(), pReq->m_nSub, nForce);
}

// @0x1417dc9a0
MS2Ptr<StateData> CStateManager::FUN_1417dc9a0(int nState)
{
    State* pState = FUN_1417db1e0(nState);
    if (pState != 0)
    {
        MS2Ptr<StateData> spData = pState->vfunc_27();
        if (spData.get() != 0)
            return spData;
    }
    return MS2Ptr<StateData>(0);
}

// ---- StateMoveSkill ----

class Unk_SMBlk180 { public: int m_pad[2]; float m_n8; };   // +8 move speed (exe movss xmm1, [rax+8])
Unk_SMBlk180* FUN_141671920(PCBase* p);
void FUN_141671960(PCBase* p, float fSpeed);   // PCBase::FUN_141671960
long long FUN_141670a00(PCBase* p, int n);
class Unk_SMSkills : public CSkillSystem { };
Unk_SMSkills* FUN_141523bc0(MyPC* p);
CKeyTable* FUN_1409331f0();
class Unk_SMSession { public: char m_pad; };
int FUN_141adbb00(Unk_SMSession* p);
class Unk_SMSkillTable { public: MS2Ptr<Unk_SMSkillRec> FUN_1407ee2f0(int nSkill, short nLevel); };

// @0x1417df080
StateMoveSkill::StateMoveSkill(PCBase* pOwner) : State(pOwner), m_n44(0), m_nFallbackState(0), m_nFallbackSub(0)
{
    m_nMode = 0;
}

// @0x1417df130
StateMoveSkill::~StateMoveSkill()
{
}

// @0x1417df180
void StateMoveSkill::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (!vfunc_38(pData))
        FUN_1417df370();
    m_tick.FUN_140268840();
}

// @0x1417df1f0
void StateMoveSkill::vfunc_5(int n)
{
    State::vfunc_5(n);
    Unk_SMBlk180* pBlk = FUN_141671920(m_pOwner);
    FUN_141671960(m_pOwner, pBlk->m_n8);
    m_tick.FUN_140268840();
    m_spData = 0;
    m_spRec = 0;
}

// @0x1417df280
void StateMoveSkill::vfunc_7(int n)
{
    m_pOwner->vfunc_59(n, 0, 0, 0);
}

// @0x1417df2d0
void StateMoveSkill::vfunc_8(double fTime)
{
    if (FUN_1417b8560() == 0)
        return;
    if (m_nMode == 0)
    {
        if (vfunc_36() == 0)
        {
            FUN_1417df370();
            return;
        }
    }
    else if (m_nMode == 1)
    {
        if (vfunc_37() == 0)
        {
            FUN_1417df370();
            return;
        }
    }
    State::vfunc_8(fTime);
}

// @0x1417df370
void StateMoveSkill::FUN_1417df370()
{
    m_pOwner->vfunc_59(m_nFallbackState, 0, m_nFallbackSub, 0);
}

// @0x1417df3c0
int StateMoveSkill::GetMode()
{
    return m_nMode;
}

// @0x1417df3e0
int StateMoveSkill::FUN_1417df3e0()
{
    if (m_spData.get() != 0)
        return m_spData->m_nSkill;
    return 0;
}

// @0x1417df430
long long StateMoveSkill::FUN_1417df430()
{
    if (m_spRec == 0)
        return 0;
    return (long long)m_spRec->m_n1c;
}

// @0x1417df480
int StateMoveSkill::vfunc_36()
{
    if (m_spData.get() != 0)
        return FUN_1409331f0()->FUN_14142c0c0(m_spData->m_nSkill);
    return 0;
}

// @0x1417df4e0
int StateMoveSkill::vfunc_37()
{
    if (m_spData.get() != 0)
    {
        if (FUN_141adbb00(reinterpret_cast<Unk_SMSession*>(TSingleton<CUIService>::GetInstance())) == 0)
            return FUN_1409331f0()->FUN_14142c300(m_spData->m_nSkill) == 0;
    }
    return 1;
}

// The dynamic_cast view: the exe casts to StateSkillData (RTTI names are compared, so casting to Unk_SMSkillData always
// gave NULL).
class StateSkillData : public StateData {};
// @0x1417df570
bool StateMoveSkill::vfunc_38(StateData* pData)
{
    m_spData.AssignRaw(reinterpret_cast<Unk_SMSkillData*>(dynamic_cast<StateSkillData*>(pData)));
    if (m_spData == 0)
        return false;
    m_spRec = reinterpret_cast<Unk_SMSkillTable*>(TSingleton<SkillDataTableCli>::GetInstance())->FUN_1407ee2f0(m_spData->m_nSkill, m_spData->m_nLevel);
    if (m_spRec == 0)
        return false;
    return true;
}

// @0x1417df6a0
bool StateMoveSkill::FUN_1417df6a0()
{
    if (FUN_1417b8560() == 0)
        return true;
    if (m_tick.FUN_140268870(1000))
    {
        if (FUN_141670a00(m_pOwner, 10) < FUN_1417df430())
        {
            FUN_1417df370();
            return false;
        }
    }
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        if (!FUN_141523bc0(pPC)->FUN_141765b80(FUN_1417df3e0()))
        {
            FUN_1417df370();
            return false;
        }
    }
    return true;
}

// ---- StateNone ----

PCBase* FUN_1417dfaa0(PCBase* p);           // as 0x620004f (defined below)
void FUN_14166ca20(PCBase* p, int n);
void FUN_14166ca80(PCBase* p, int n);
CPet* FUN_1409ffc60(PCBase* p);

// @0x1417df8b0
StateNone::StateNone(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417df900
void StateNone::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    bool bPC = FUN_1417b8370() != 0;
    bool b4f = FUN_1417dfaa0(m_pOwner) != 0;
    if (!bPC || b4f)
        FUN_14166ca20(m_pOwner, 4);
}

// @0x1417df9b0
void StateNone::vfunc_5(int n)
{
    State::vfunc_5(n);
    bool bPC = FUN_1417b8370() != 0;
    bool b4f = FUN_1417dfaa0(m_pOwner) != 0;
    if (!bPC || b4f)
    {
        int nValue = 0;
        CPet* pHost = reinterpret_cast<CPet*>(FUN_1417b83a0());
        if (pHost != 0)
            nValue = pHost->FUN_140b10150();
        FUN_14166ca80(m_pOwner, 4);
    }
}

// @0x1417dfa80
bool StateNone::vfunc_25(int n, void* p)
{
    return false;
}

// @0x1417dfaa0
PCBase* FUN_1417dfaa0(PCBase* p)
{
    PCBase* pOut = 0;
    if (p != 0 && p->TypeCast(0x620004f, (void**)&pOut))
        return pOut;
    else
        return 0;
}

// @0x1417dfb50
int StateNone::vfunc_1()
{
    return 0;
}

// ---- StatePush ----

void FUN_14166dda0(PCBase* p, int n);

// @0x1417dfb60
StatePush::StatePush(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417dfbb0
StatePush::~StatePush()
{
}

// @0x1417dfbe0
void StatePush::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    FUN_14166dda0(m_pOwner, 0x29);
}

// @0x1417dfc60
int StatePush::vfunc_1()
{
    return 0x15;
}

// ---- StateRegen ----

extern long long DAT_143ab2820;

class Unk_AnimName { public: alignas(8) char m_pad[0x20]; };   // efd::utf8string stand-in, 0x20 bytes (ctor 0x1409989e0, dtor 0x1408a8900)
void FUN_1409989e0(Unk_AnimName* p, const char* psz);
void FUN_1408a8900(Unk_AnimName* p);
// The same string as a real temporary (ctor 0x1409989e0, dtor 0x1408a8900).
class Unk_SMAnimStr
{
public:
    Unk_SMAnimStr(const char* psz);
    ~Unk_SMAnimStr();
    alignas(8) char m_pad[0x20];
};
bool FUN_141b6fa90(const egf::EntityID& kKey, const Unk_SMAnimStr& kName);
void FUN_14166dd20(PCBase* p, Unk_AnimName* pName, float fSpeed, bool bA, bool bB);
void FUN_14166dd20(PCBase* p, const Unk_SMAnimStr& kName, float fSpeed, bool bA, bool bB);
bool FUN_14166de90(PCBase* p, int nAnim, unsigned nSeq);

// NPC table row data (the regen / spawn flags).
class Unk_SMNpcData : public CPtred
{
public:
    int FUN_14067dbc0();
    int FUN_1417e0590();
    char m_pad_18[0x10];
    long long m_n28;                    // +0x28
    char m_pad_30[0x18];
    int m_n48;                          // +0x48
};
class Unk_SMNpcTpl : public CPtred
{
public:
    char m_pad_18[0x538];
    CStringA m_str550;                  // +0x550 effect name
};
// An NPC actor (class id 0x6200028).
class Unk_SMNpc : public PCBase
{
public:
    MS2Ptr<Unk_SMNpcData> FUN_141093800();
    MS2Ptr<Unk_SMNpcTpl> FUN_141093270();
    void FUN_1410943b0(int n);
};
Unk_SMNpc* FUN_14096e110(PCBase* p);
struct Unk_VibEffectReq;
class Unk_SMEffectSvc { public: int FUN_1411a4a00(const Unk_VibEffectReq& kReq); };
// Effect request layout shared with entityvibrator.cpp.
struct Unk_VibEffectReq
{
    Unk_VibEffectReq();
    ~Unk_VibEffectReq();
    CString m_name;                                                 // +0x00
    int m_type;                                                     // +0x08
    int m_pad_0c;
    void* m_pad_10;
    void* m_pXform;                                                 // +0x18 rotation 3x3, translation, scale (0x34)
    void* m_pad_20[10];
};
MS2_CHECK_SIZE(Unk_VibEffectReq, 0x70);
// NiPoint3(const efd::Point3&) 0x14027dcf0; the owner's position comes back as an efd::Point3.
struct Unk_SMNiPt3 : public NiPoint3
{
    Unk_SMNiPt3(const NiPoint3& kPt);
};

// @0x1417dfc70
StateRegen::StateRegen(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
    m_nStarted = 0;
    m_nVariantB = 0;
    m_nSpecial = 0;
    m_nSkip = 0;
}

// @0x1417dfd10
StateRegen::~StateRegen()
{
}

// @0x1417dfd50
void StateRegen::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_pOwner->FUN_14123cb20(false);
    if (!FUN_141b6fa90(m_pOwner->FUN_14123c460(), "Regen_A"))
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        FUN_14166ca20(m_pOwner, 9);
        Unk_Random kRandom(m_pOwner->FUN_14123c580());
        int nDelay = kRandom.FUN_1407684c0() % 300 + 100;
        m_timer.FUN_140868750(nDelay);
    }
    Unk_SMNpc* pNpc = reinterpret_cast<Unk_SMNpc*>(FUN_1417b8480());
    if (pNpc != 0)
    {
        if (pNpc->FUN_141093800().get())
        {
            if (pNpc->FUN_141093800()->FUN_14067dbc0())
                m_nSkip = 1;
            if (pNpc->FUN_141093800()->FUN_1417e0590() == 0)
            {
                if (DAT_143ab2820 == pNpc->FUN_141093800()->m_n28)
                    m_nSpecial = 1;
                if (FUN_141b6fa90(m_pOwner->FUN_14123c460(), "Regen_B"))
                    m_nVariantB = 1;
            }
        }
    }
}

// @0x1417e0120
void StateRegen::vfunc_5(int n)
{
    State::vfunc_5(n);
    FUN_14166ca80(m_pOwner, 9);
    CPet* pHost = reinterpret_cast<CPet*>(FUN_1417b83a0());
    if (pHost != 0)
    {
        int nValue = pHost->FUN_140b10150();
        if (nValue != 0)
        {
            m_pOwner->vfunc_23(nValue);
            m_pOwner->FUN_14123cb20(nValue == 0);
        }
    }
}

// @0x1417e01d0
void StateRegen::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_timer.FUN_140868ba0())
        return;
    if (m_nStarted == 0)
    {
        Unk_SMNpc* pNpc = reinterpret_cast<Unk_SMNpc*>(FUN_1417b8480());
        if (pNpc != 0)
        {
            {
                Unk_SMAnimStr kName(m_nVariantB != 0 ? "Regen_B" : "Regen_A");
                FUN_14166dd20(m_pOwner, kName, 1.0f, true, false);
            }
            FUN_14166ca80(m_pOwner, 9);
            NiTransform kXform;
            kXform.m_Rotate.MakeIdentity();
            kXform.m_fScale = 1.0f;
            Unk_SMNiPt3 kPos(m_pOwner->vfunc_18());
            kXform.m_Translate = kPos;
            Unk_VibEffectReq req;
            req.m_name = pNpc->FUN_141093270()->m_str550;
            req.m_type = 0;
            req.m_pXform = &kXform;
            reinterpret_cast<Unk_SMEffectSvc*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a4a00(req);
            if (m_nSkip == 0)
            {
                if (m_nVariantB != 0)
                {
                    if (m_nSpecial != 0)
                        pNpc->FUN_1410943b0(6);
                    else
                        pNpc->FUN_1410943b0(3);
                }
                else
                {
                    pNpc->FUN_1410943b0(2);
                }
            }
        }
        else
        {
            {
                Unk_SMAnimStr kName("Regen_A");
                FUN_14166dd20(m_pOwner, kName, 1.0f, true, false);
            }
            FUN_14166ca80(m_pOwner, 9);
        }
        m_nStarted = 1;
    }
}

// @0x1417e04e0
void StateRegen::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 0x2c, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417e0590
int Unk_SMNpcData::FUN_1417e0590()
{
    return m_n48;
}

// @0x1417e05a0
int StateRegen::vfunc_1()
{
    return 0x17;
}

// ---- StateRide ----

// A rider's ride-animation row: the animation name per riding pose.
class Unk_SMRideAnim : public CPtred
{
public:
    char m_pad_18[0x10];
    CStringA m_str28;
    CStringA m_str30;
    CStringA m_str38;
    CStringA m_str40;
    CStringA m_str48;
    CStringA m_str50;
    CStringA m_str58;
};
class Unk_SMRideA : public CPtred
{
public:
    MS2Ptr<Unk_SMRideAnim> FUN_140784970();
};
// The rider of the owner (FUN_1416764a0).
class Unk_SMRider : public PCBase
{
public:
    MS2Ptr<Unk_SMRideA> FUN_141707750();
};
Unk_SMRider* FUN_1416764a0(PCBase* p);
void FUN_141705ac0(Unk_SMRider* p, double fTime);
int FUN_14166cc80(PCBase* p);
int FUN_141676b70(PCBase* p);
float FUN_1416713c0(PCBase* p);
void FUN_141657c80(PCBase* p, bool b);
void FUN_14165f170(PCBase* p);
void FUN_14166f8f0(PCBase* p, int n, int b);

// @0x1417e05b0
StateRide::StateRide(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417e0600
StateRide::~StateRide()
{
}

// @0x1417e0630
void StateRide::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    PCBase* pPC = FUN_140974230(m_pOwner);
    if (pPC != 0)
        FUN_141657c80(pPC, false);
    MyPC* pMy = FUN_1417b84b0();
    if (pMy != 0)
        FUN_14165f170(pMy);
    m_pOwner->FUN_14123cb20(false);
    FUN_14166f8f0(m_pOwner, 0, 0);
}

// @0x1417e06d0
void StateRide::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_14123cb20(true);
}

// @0x1417e0710
void StateRide::vfunc_8(double fTime)
{
    Unk_SMRider* pRider = FUN_1416764a0(m_pOwner);
    if (pRider == 0)
        return;
    if (m_pOwner->vfunc_63() == 0)
        return;
    FUN_141705ac0(pRider, fTime);
}

// @0x1417e0780
void StateRide::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    Unk_SMRider* pRider = FUN_1416764a0(m_pOwner);
    if (pRider == 0)
        return;
    MS2Ptr<Unk_SMRideA> spRide = pRider->FUN_141707750();
    if (spRide == 0)
        return;
    MS2Ptr<Unk_SMRideAnim> spAnim = spRide->FUN_140784970();
    if (spAnim == 0)
        return;
    if (FUN_14166c930(pRider) == 2 || FUN_14166c930(pRider) == 0x1b)
    {
        if (FUN_14166cc80(pRider) == 0x17 || FUN_14166cc80(pRider) == 0x85)
        {
            Unk_SMAnimStr kName(spAnim->m_str50);
            FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
        }
        else
        {
            Unk_SMAnimStr kName(spAnim->m_str38);
            FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
        }
    }
    else if (FUN_14166c930(pRider) == 6)
    {
        if (FUN_14166cc80(pRider) == 0x27)
        {
            Unk_SMAnimStr kName(spAnim->m_str58);
            FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
        }
        else
        {
            Unk_SMAnimStr kName(spAnim->m_str40);
            FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
        }
    }
    else if (FUN_14166c930(pRider) == 4)
    {
        Unk_SMAnimStr kName(spAnim->m_str30);
        FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
    }
    else if (FUN_14166c930(pRider) == 1)
    {
        if (FUN_14166cc80(pRider) == 0xc || FUN_14166cc80(pRider) == 0x87)
        {
            Unk_SMAnimStr kName(spAnim->m_str48);
            FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
        }
        else
        {
            Unk_SMAnimStr kName(spAnim->m_str30);
            FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
        }
    }
    else if (FUN_141676b70(pRider))
    {
        Unk_SMAnimStr kName(spAnim->m_str48);
        FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
    }
    else
    {
        Unk_SMAnimStr kName(spAnim->m_str28);
        FUN_14166dd20(m_pOwner, kName, FUN_1416713c0(pRider), false, false);
    }
}

// @0x1417e0d20
int StateRide::vfunc_1()
{
    return 0x21;
}

// ---- StateRope ----

// The key / buff state of the owner (the input query object of the PC).
class Unk_SMKeys
{
public:
    bool FUN_141682fe0(int nKey);               // held
    bool FUN_141683100(int nKey);               // pressed this frame
    efd::Point3 FUN_141683290();                // pointer direction
};
struct Unk_SMExtent { float m_fWidth; float m_fHeight; };
Unk_SMKeys* FUN_14166d240(PCBase* p);
Unk_SMExtent* FUN_141671390(PCBase* p, Unk_SMExtent* pOut);
bool FUN_1412410c0(void* pCollider, const efd::Point3* pPos, float fHalfHeight);
bool FUN_140552700(const efd::Point3& kA, const efd::Point3& kB);    // efd::Point3::operator!=
bool FUN_1416749c0(PCBase* p);
void FUN_141240730(void* p);
void* FUN_14165f100(PCBase* p);
void FUN_14166e0a0(PCBase* p);
egf::Entity* FUN_141659af0(PCBase* p, int n);
egf::Entity* FUN_141659b80(PCBase* p, int n, unsigned nProp, float fRange);
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProp, const efd::Point3* pValue);
void FUN_1408a20a0(egf::Entity* pEntity, unsigned nProp, bool* pOut);
void FUN_141658fc0(PCBase* p, egf::EntityID kId);      // PC::FUN_141658fc0(const EntityID&); callers pass a copy
bool FUN_140998dc0(const NiFixedString& kKey, const char* psz);
void* FUN_1409f7ca0();
int FUN_14168a450(void* pSvc, const NiPoint3* pPos, float* pGround, float fZ);
float FUN_1409f25a0(float f);
float FUN_1409f2310(float f);
bool FUN_14028d470(float a, float b);
float FUN_140a00ef0(const NiPlane* plane, const NiPoint3& pt);   // NiPlane distance

// @0x1417e0d30
StateRope::StateRope(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
    m_f60 = 0.0f;
    m_fAngle = 0.0f;
    m_pRope = 0;
    m_pos54 = efd::Point3::ZERO;
    m_pos48 = efd::Point3::ZERO;
}

// @0x1417e0e50
StateRope::~StateRope()
{
}

// @0x1417e0ed0
void StateRope::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    FUN_141240730(FUN_14166d220(m_pOwner));
    m_n10 = 0x38;
    m_timerA0.FUN_1408687f0();
    m_timerD8.FUN_1408687f0();
    m_time110.FUN_140868750(100);
    m_timer68.FUN_140868750((int)(200.0f / FUN_1416713c0(m_pOwner)));
    m_pos48 = m_pOwner->vfunc_18();
    m_pos54 = efd::Point3::ZERO;
    m_pRope = 0;
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
        m_pRope = FUN_141659af0(pPC, 3);
    MyPC* pMy = FUN_1417b84b0();
    if (pMy != 0 && FUN_14165f100(pMy) != 0)
        FUN_14165f170(pMy);
    if (m_pRope != 0)
    {
        NiPoint3 kPos = m_pOwner->vfunc_18();
        efd::Point3 kZero = efd::Point3::ZERO;
        FUN_1409618c0(m_pRope, 0xfd95ca52, &m_pos54);
        FUN_1409618c0(m_pRope, 0x68c7c29d, &kZero);
        NiPoint3 kOrigin(static_cast<const efd::Point3&>(m_pOwner->vfunc_18()));
        NiPoint3 kFacing(m_pOwner->FUN_14123cc20());
        NiPlane kPlane(kFacing, kOrigin);
        if (FUN_140a00ef0(&kPlane, m_pos54) >= 0.0f)
        {
            m_fAngle = GameObject::FUN_14123ce70(m_pOwner->FUN_14123cc20());
        }
        else
        {
            efd::Point3 kDiff = m_pos54 - kPos;
            m_fAngle = GameObject::FUN_14123ce70(kDiff);
            m_pOwner->vfunc_21(efd::Point3(0.0f, 0.0f, GameObject::FUN_14123cd50(kDiff)));
        }
    }
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    m_pOwner->FUN_14123cb20(false);
}

// @0x1417e1330
void StateRope::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_14123cb20(true);
    if (m_pRope != 0 && FUN_1417b8370() != 0)
    {
        FUN_141658fc0(FUN_1417b8370(), *FUN_1408b76f0(m_pRope));
    }
    FUN_14166d8b0(m_pOwner, m_pOwner->vfunc_20().z);
}

// @0x1417e1400
void StateRope::vfunc_3(double fTime)
{
    if (m_pRope == 0)
        return;
    efd::Point3 kInput = m_pOwner->FUN_14123c360();
    NiPoint3 kPos = m_pOwner->vfunc_18();
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    if (m_n10 == 0x38)
    {
        efd::Point3 kTop;
        kTop.x = 20.0f * FUN_1409f25a0(m_fAngle) + m_pos54.x;
        kTop.y = 20.0f * FUN_1409f2310(m_fAngle) + m_pos54.y;
        kTop.z = m_pos54.z + 50.0f;
        efd::Point3 kDelta = kTop - m_pos48;
        kDelta *= m_timer68.FUN_140868940();
        efd::Point3 kTarget = m_pos48 + kDelta;
        Unk_SMExtent kExtent;
        FUN_141671390(m_pOwner, &kExtent);
        if (!FUN_1412410c0(FUN_14166d220(m_pOwner), &kTarget, kExtent.m_fHeight * 0.5f))
            m_pOwner->vfunc_19(kTarget);
        m_pOwner->vfunc_21(efd::Point3(0.0f, 0.0f, -((m_fAngle * 180.0f) / 3.1415927f)));
        if (m_timer68.FUN_140868c00() != 0)
        {
            m_timer68.FUN_1408687f0();
            m_n10 = 0x33;
        }
    }
    else
    {
        if (kInput.y > 0.0f)
        {
            if (m_n10 == 0x36 || m_n10 == 0x33)
                m_n10 = 0x34;
        }
        else if (kInput.y < 0.0f)
        {
            m_n10 = 0x35;
        }
        if (kInput.x < 0.0f)
        {
            m_fAngle = m_fAngle + 2.0f * (float)fTime;
            if (FUN_14028d470(kInput.y, 0.0f))
            {
                m_n10 = 0x37;
                m_timerA0.FUN_1408687f0();
            }
        }
        else if (kInput.x > 0.0f)
        {
            m_fAngle = m_fAngle - 2.0f * (float)fTime;
            if (FUN_14028d470(kInput.y, 0.0f))
            {
                m_n10 = 0x37;
                m_timerA0.FUN_1408687f0();
            }
        }
        if (m_n10 == 0x36 && !FUN_1416749c0(m_pOwner) && m_timerA0.FUN_140868ba0() == 0)
            m_n10 = 0x33;
    }
    FUN_1417e20d0(FUN_1417e1e60(), kInput.x);
}

// @0x1417e18d0
void StateRope::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    Unk_SMKeys* pKeys = FUN_14166d240(m_pOwner);
    efd::Point3 kInput = efd::Point3::ZERO;
    if (m_time110.FUN_140868c00() != 0)
    {
        if (pKeys->FUN_141682fe0(0x30d41))
            kInput.y = 1.0f;
        else if (pKeys->FUN_141682fe0(0x30d42))
            kInput.y = -1.0f;
    }
    if (pKeys->FUN_141683100(0x30d43) || pKeys->FUN_141683100(0x30d44))
        m_timerD8.FUN_140868750(500);
    if (m_timerD8.FUN_140868c00() != 0)
    {
        if (pKeys->FUN_141682fe0(0x30d43))
            kInput.x = -1.0f;
        else if (pKeys->FUN_141682fe0(0x30d44))
            kInput.x = 1.0f;
    }
    m_pOwner->vfunc_22(kInput);
    if (pKeys->FUN_141683100(0x493e1))
    {
        m_pOwner->vfunc_22(pKeys->FUN_141683290());
        if (!pKeys->FUN_141682fe0(0x30d43) && !pKeys->FUN_141682fe0(0x30d44) && pKeys->FUN_141682fe0(0x30d41))
            m_pOwner->vfunc_22(efd::Point3::ZERO);
        m_pOwner->vfunc_59(6, 0, 0, 0);
    }
}

// @0x1417e1ba0
void StateRope::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    switch (m_n10)
    {
    case 0x33: FUN_14166dda0(m_pOwner, 0x24); break;
    case 0x34: FUN_14166dda0(m_pOwner, 0x22); break;
    case 0x35: FUN_14166dda0(m_pOwner, 0x23); break;
    case 0x37: FUN_14166dda0(m_pOwner, 0x25); break;
    case 0x38: FUN_14166dda0(m_pOwner, 0x26); break;
    }
}

// @0x1417e1c70
void StateRope::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID, const NiFixedString& kTextKey,
    const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 0x22, eSequenceID) || FUN_14166de90(m_pOwner, 0x23, eSequenceID))
    {
        if (FUN_140998dc0(kTextKey, "begin"))
            FUN_1417e23c0();
    }
}

// @0x1417e1d00
void StateRope::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (FUN_14166de90(m_pOwner, 0x22, eSequenceID))
    {
        m_n10 = 0x36;
        FUN_14166e0a0(m_pOwner);
    }
    else if (FUN_14166de90(m_pOwner, 0x23, eSequenceID))
    {
        m_n10 = 0x36;
        FUN_14166e0a0(m_pOwner);
    }
    else if (FUN_14166de90(m_pOwner, 0x25, eSequenceID) || FUN_14166de90(m_pOwner, 0x26, eSequenceID))
    {
        m_n10 = 0x33;
    }
}

// @0x1417e1df0
void StateRope::FUN_1417e1df0(egf::Entity* pRope)
{
    if (pRope == 0)
        return;
    if (m_pRope != 0 && m_pRope != pRope)
    {
        m_pRope = pRope;
        FUN_1409618c0(m_pRope, 0xfd95ca52, &m_pos54);
    }
}

// @0x1417e1e60
float StateRope::FUN_1417e1e60()
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return 0.0f;
    float fStep = 0.0f;
    NiPoint3 kPos = pPC->vfunc_18();
    bool bOnRope = false;
    if (m_pRope != 0)
        FUN_1408a20a0(m_pRope, 0x4df0c0de, &bOnRope);
    if (!bOnRope)
    {
        float fGround = 0.0f;
        if (FUN_14168a450(FUN_1409f7ca0(), &kPos, &fGround, 0.0f) != 0 && fGround != FLT_MAX)
            m_n10 = 0x39;
    }
    else if (m_n10 == 0x34)
    {
        fStep = 150.0f * m_timerA0.FUN_140868b20();
        egf::Entity* pNext = FUN_141659b80(pPC, 1, 0xc13e30c8, 150.0f);
        if (pNext == 0)
        {
            if (kPos.z + fStep > m_pos54.z + 50.0f)
            {
                m_n10 = 0x33;
                m_timerA0.FUN_1408687f0();
            }
        }
        else
        {
            FUN_1417e1df0(pNext);
        }
    }
    else if (m_n10 == 0x35)
    {
        fStep = 150.0f * m_timerA0.FUN_140868b20();
        egf::Entity* pNext = FUN_141659b80(pPC, 2, 0xc13e30c8, 90.0f);
        if (pNext == 0)
        {
            if (kPos.z - fStep < m_pos54.z)
            {
                pPC->vfunc_59(5, 0, 0, 0);
                return 0.0f;
            }
        }
        else
        {
            FUN_1417e1df0(pNext);
        }
    }
    return fStep;
}

// @0x1417e20d0
void StateRope::FUN_1417e20d0(float fDz, float fAngle)
{
    NiPoint3 kTarget = m_pOwner->vfunc_18();
    if (m_n10 == 0x34 || m_n10 == 0x35)
    {
        if (fDz != 0.0f)
        {
            if (m_n10 == 0x34)
                kTarget.z = kTarget.z + fDz;
            else if (m_n10 == 0x35)
                kTarget.z = kTarget.z - fDz;
        }
    }
    else if (m_n10 == 0x39)
    {
        kTarget.z = kTarget.z - fDz;
        m_pOwner->vfunc_59(5, 0, 0, 0);
    }
    if (fAngle != 0.0f)
    {
        kTarget.x = 20.0f * FUN_1409f25a0(m_fAngle) + m_pos54.x;
        kTarget.y = 20.0f * FUN_1409f2310(m_fAngle) + m_pos54.y;
        m_pOwner->vfunc_21(efd::Point3(0.0f, 0.0f, -((m_fAngle * 180.0f) / 3.1415927f)));
    }
    if (FUN_140552700(m_pOwner->vfunc_18(), kTarget))
    {
        Unk_SMExtent kExtent;
        FUN_141671390(m_pOwner, &kExtent);
        if (!FUN_1412410c0(FUN_14166d220(m_pOwner), &kTarget, kExtent.m_fHeight * 0.5f))
            m_pOwner->vfunc_19(static_cast<efd::Point3&>(kTarget));
    }
}

// @0x1417e23c0
void StateRope::FUN_1417e23c0()
{
    m_timerA0.FUN_140868750((int)(400.0f / FUN_1416713c0(m_pOwner)));
}

// @0x1417e2450
int StateRope::vfunc_1()
{
    return 9;
}

// ---- CStateService ----

// The services the exe reaches through its global accessors.
struct Unk_SMDepPlatform : efd::ISystemService { static const efd::ClassID CLASS_ID = 0x0700001a; };
struct Unk_SMDepWorld : efd::ISystemService { static const efd::ClassID CLASS_ID = 0x06100002; };
struct Unk_SMDepSix : efd::ISystemService { static const efd::ClassID CLASS_ID = 0x06100006; };
struct Unk_SMInputHandle { void* m_p0; void* m_pTarget; ~Unk_SMInputHandle(); };   // dtor 0x140b62a60 (release)
class Unk_SMInputSvc { public: Unk_SMInputHandle FUN_1422b02f0(int nSlot); };
Unk_SMInputSvc* FUN_14025e7a0();
CFeatureManager* FUN_140166410();
CReconnectionManagerCli* FUN_140e800e0();
void FUN_14151f460(int n);
class Unk_SMSceneHook { public: void FUN_1422b9ef0(int nScene); };
Unk_SMSceneHook* FUN_1408e57f0();
void* FUN_14086d260();
float FUN_141473230(void* pApp);

// The service singleton: s_instance is set by the TSingleton constructor.
CStateService* TSingleton<CStateService>::s_instance = 0;
inline TSingleton<CStateService>::TSingleton() { s_instance = static_cast<CStateService*>(this); }

// @0x1417e3620
static bool FUN_1417e3620(const Unk_SMInputHandle& h)
{
    return h.m_pTarget == 0;
}

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1417e2460
CStateService::CStateService() : m_mapScenes(10), m_spCurrent(0)
{
    m_spCurrent = 0;
}
#endif

// @0x1417e2510
CStateService::~CStateService()
{
}

// @0x1417e2580
const char* CStateService::GetDisplayName() const
{
    return "StateService";
}

// @0x1417e25a0
int CStateService::FUN_1417e25a0(int nScene)
{
    if (FUN_1417e2610() == nScene)
        return 0;
    FUN_14151f460(1);
    if (FUN_140e800e0() != 0)
        FUN_140e800e0()->FUN_140aad970();
    int nRet = FUN_1417e2830(nScene);
    return nRet;
}

// @0x1417e2610
int CStateService::FUN_1417e2610()
{
    if (m_spCurrent == 0)
        return 0;
    return m_spCurrent->GetClassID();
}

// @0x1417e2670
int CStateService::FUN_1417e2670()
{
    if (m_spCurrent == 0)
        return 0;
    return m_spCurrent->vfunc_15();
}

// @0x1417e26d0
efd::SmartPointer<CSceneStateBase> CStateService::GetCurrent()
{
    return m_spCurrent;
}

// @0x1417e2720
efd::SmartPointer<CSceneStateBase> CStateService::FUN_1417e2720(unsigned nScene)
{
    efd::SmartPointer<CSceneStateBase> spScene(0);
    if (!m_mapScenes.Lookup(nScene, spScene))
        return efd::SmartPointer<CSceneStateBase>(0);
    return spScene;
}

// @0x1417e27d0
void CStateService::FUN_1417e27d0(CInPacket* pPacket)
{
    if (m_spCurrent == 0)
        return;
    m_spCurrent->OnPacket(*pPacket);
}

// @0x1417e2830
int CStateService::FUN_1417e2830(int nScene)
{
    if (nScene == 0)
    {
        if (m_spCurrent)
        {
            m_spCurrent->OnLeave(0);
            m_spCurrent = 0;
        }
        return 1;
    }
    if (FUN_1417e2610() == nScene)
        return 0;
    efd::SmartPointer<CSceneStateBase> spNext(0);
    if (!m_mapScenes.Lookup(nScene, spNext))
        return 0;
    if (m_spCurrent)
        m_spCurrent->OnLeave(spNext->GetClassID());
    int nPrev = 0;
    if (m_spCurrent)
        nPrev = m_spCurrent->GetClassID();
    m_spCurrent = spNext;
    m_spCurrent->OnEnter(nPrev);
    FUN_1408e57f0()->FUN_1422b9ef0(nScene);
    return 1;
}

// @0x1417e2a60
efd::SyncResult CStateService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    pRegistrar->AddDependency<Unk_SMDepPlatform>(1);
    pRegistrar->AddDependency<Unk_SMDepWorld>(1);
    pRegistrar->AddDependency<Unk_SMDepSix>(1);
    efd::SmartPointer<CSceneStateBase> spScene(0);
    spScene = EE_NEW CSceneStateLogo;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    if (FUN_140166410()->FUN_14036d570(0xd8))
    {
        spScene = EE_NEW CSceneStateModeSelect;
        m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    }
    spScene = EE_NEW CSceneStateLogin;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    spScene = EE_NEW CSceneStateMulti;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    spScene = EE_NEW CSceneStateGame;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    spScene = EE_NEW CSceneStateLoading;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    spScene = EE_NEW CSceneStateMove;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    spScene = EE_NEW CSceneStateRelocateWorld;
    m_mapScenes.SetAt(spScene->GetClassID(), spScene);
    return efd::SyncResult_Success;
}

// @0x1417e30c0
efd::AsyncResult CStateService::OnInit()
{
    if (reinterpret_cast<Unk_SMWorld*>(WorldService::GetInstance())->FUN_141bcfb70() == 0)
        return efd::AsyncResult_Pending;
    bool bNone = FUN_1417e3620(FUN_14025e7a0()->FUN_1422b02f0(2));
    if (bNone)
        return efd::AsyncResult_Pending;
    FUN_1417e25a0(0x620000b);
    return efd::AsyncResult_Complete;
}

// @0x1417e3160
efd::AsyncResult CStateService::OnTick()
{
    if (m_spCurrent)
    {
        efd::SmartPointer<CSceneStateBase> spScene = m_spCurrent;
        double fTime = (double)FUN_141473230(FUN_14086d260());
        spScene->OnUpdate(fTime);
    }
    return efd::AsyncResult_Pending;
}

// @0x1417e3200
efd::AsyncResult CStateService::OnShutdown()
{
    FUN_1417e25a0(0);
    m_mapScenes.RemoveAll();
    return efd::AsyncResult_Complete;
}

// @0x1417e46b0
MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb79b0-0x142cb7de0 .text$yd
