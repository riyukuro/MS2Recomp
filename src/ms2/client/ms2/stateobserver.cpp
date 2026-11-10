// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateObserver, the spectator actor state that follows
// another player (cycling through the observable players with the keyboard, switching away when the observed
// player dies), and its StateObserverData payload, with the container / MS2Ptr / Delegate glue over its members.
// See stateobserver.h.
// MS2-UNIT: client\ms2\stateobserver.cpp
// MS2-RANGE: 0x140ac3b40-0x140ac6400 .text$mn
// MS2-RANGE: 0x1400c5a10-0x1400c5c20 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400c5a10 ; probe
// MS2-PIN: ??__Es_condition0@@YAXXZ 0x1400c5a60 ; probe
// MS2-PIN: ??__Es_strStun0@@YAXXZ 0x1400c5b70 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400c5ba0 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400c5bd0 ; probe
// MS2-PIN: ?IsNull@?$MS2Ptr@VCProxyGameObject@@@@QEBA_NXZ 0x140ac5aa0 ; unique
// MS2-PIN: ?IsNull@?$MS2Ptr@VStateSyncObject@@@@QEBA_NXZ 0x140ac5b00 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140ac5d00 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEBAIXZ 0x140ac5dc0 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140ac5dd0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140ac5e20 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCProxyGameObject@@@@PEAU__POSITION@@@Z 0x140ac5ed0 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@IV?$MS2Ptr@VCProxyGameObject@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCProxyGameObject@@@@@3@@ATL@@QEBA_NXZ 0x140ac5f40 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@2@AEB_K@Z 0x140ac6200 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@_KU?$less@_K@std@@V?$allocator@_K@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_K@std@@@std@@@2@AEB_K@Z 0x140ac63a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateobserver.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <float.h>
#include <atlcoll.h>
#include <algorithm>
#include <set>
#include <vector>

#include "stateobserver.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/actionkeyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/client/ms2/fielddatacli.h"

// ---- unit statics (.text$di): three statics ahead of the shared header statics ----

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static CString s_strStun0 = "stun";
static egf::EntityID s_hNull0(0);   // @0x1400c5a40
static Unk_1402a9d70 s_condition0(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The state-sync record (StateSyncObject in statemanager.h): +0x70 holds the observed id as text.
class StateSyncObject : public CPtred
{
public:
    char m_pad_18[0x70 - sizeof(CPtred)];
    CStringA m_str70;                                       // +0x70
};
MS2_CHECK_OFFSET(StateSyncObject, m_str70, 0x70);
class Unk_StateDataArg
{
public:
    char m_pad_00[0x70];
    CStringA m_str70;                                       // +0x70
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

unsigned __int64 FUN_140718350(const CString& strId);       // id text -> id
CString FUN_140719530(unsigned __int64 nId);                // id -> id text

// The nameplate component PCBase slot 82 hands out (itemgem.cpp spells the same class).
class Unk_PCBaseComp_a78 : public CPtred
{
public:
};

// The notice the pvp kill log posts (NotifyKillPlayer in scenestategame.cpp): the two names behind the NotifyObject.
struct Unk_ObsKillView
{
    char m_pad_00[0x18];
    CStringW m_strKiller;                                   // +0x18
    CStringW m_strVictim;                                   // +0x20
};
MS2_CHECK_OFFSET(Unk_ObsKillView, m_strVictim, 0x20);

typedef ATL::CAtlMap<unsigned, MS2Ptr<CProxyGameObject> > Unk_ObsProxyMap;

class Unk_ObsWorld : public WorldService
{
public:
    // FUN_141bc9d60 (the proxy of a player by name): WorldService's own member
};

class UIDamageEffect : public UIObject
{
public:
    void FUN_141910660();
    void FUN_141910700();
};
UIMainPlayerInfo* FindMainPlayerInfo(int nUiId);

struct Unk_MiActionState* Unk_PlayerActionState(struct Unk_MiPlayer* pPlayer);   // the actor's action key set (mouseinteract.cpp)
void FUN_141274f50();
class Unk_SingletonObj;
Unk_SingletonObj*FUN_140939a10();
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
class MyPC   // C3: member view for the former free stand-ins
{
public:
    void FUN_14152e0c0();
};
void FUN_140710590(COutPacket& packet);                     // send
// The NiPoint3 the owner hands out and the efd::Point3 it takes are the same three floats as Vector3 (read through reinterpret_cast).

// @0x140ac4f90
// Wraps nIdx into [0, nCount).
static int WrapIndex(int nCount, int nIdx)
{
    if (nCount == 0)
        return -1;
    nIdx = nIdx % nCount;
    if (nIdx < 0)
        nIdx = nCount + nIdx;
    return nIdx;
}

// @0x140ac4fe0
// Collects the ids of the observable players: valid proxies of kind 0 that are not observers (type 0x3f).
static void CollectObservableIds(std::vector<__int64>& ids)
{
    ids.clear();
    Unk_ObsWorld* pWorld = reinterpret_cast<Unk_ObsWorld*>(WorldService::GetInstance());
    if (pWorld == 0)
        return;
    Unk_ObsProxyMap* pMap = reinterpret_cast<Unk_ObsProxyMap*>(reinterpret_cast<WorldService*>(pWorld)->FUN_141bc9fb0());
    for (POSITION pos = pMap->GetStartPosition(); pos != 0; pMap->GetNext(pos))
    {
        MS2Ptr<CProxyGameObject> spProxy(pMap->GetValueAt(pos));
        if (spProxy.IsNull())
            continue;
        if (spProxy->IsOtherPlayer() == 0)
            continue;
        if (spProxy->kind != 0)
            continue;
        if (spProxy->m_cc == 0x3f)
            continue;
        __int64 nId = (__int64)spProxy->GetCharacterId();
        ids.push_back(nId);
    }
}

// @0x140ac5130
// The observable player nearest to the local player that is not in excluded (0 when there is none).
static unsigned __int64 FindNearestObservableId(std::set<unsigned __int64>& excluded)
{
    Unk_ObsWorld* pWorld = reinterpret_cast<Unk_ObsWorld*>(WorldService::GetInstance());
    if (pWorld == 0)
        return 0;
    MS2Ptr<CFieldDataCli> spMap = reinterpret_cast<WorldService*>(pWorld)->FUN_141bd30a0();
    if (spMap.IsNull())
        return 0;
    PCBase* pPlayer = reinterpret_cast<PCBase*>(reinterpret_cast<WorldService*>(pWorld)->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    float fBest = FLT_MAX;
    MS2Ptr<CProxyGameObject> spBest;
    Unk_ObsProxyMap* pMap = reinterpret_cast<Unk_ObsProxyMap*>(reinterpret_cast<WorldService*>(pWorld)->FUN_141bc9fb0());
    for (POSITION pos = pMap->GetStartPosition(); pos != 0; pMap->GetNext(pos))
    {
        MS2Ptr<CProxyGameObject> spProxy(pMap->GetValueAt(pos));
        if (spProxy.IsNull())
            continue;
        if (spProxy->IsOtherPlayer() == 0)
            continue;
        if (spProxy->kind != 0)
            continue;
        if (spProxy->m_cc == 0x3f)
            continue;
        unsigned __int64 nId = (unsigned __int64)spProxy->GetCharacterId();
        bool bExcluded = excluded.find(nId) != excluded.end();
        if (bExcluded)
            continue;
        float fDist = (reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPlayer->vfunc_18())) - spProxy->GetPosition()).Length();
        if (fDist < fBest)
        {
            fBest = fDist;
            spBest = spProxy;
        }
    }
    if (spBest.IsNull())
        return 0;
    return (unsigned __int64)spBest->GetCharacterId();
}

// @0x140ac55a0
UIDamageEffect* GetDamageEffect(int nUiId)
{
    if (reinterpret_cast<CUIService*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spRef = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spRef.get() != 0)
            return dynamic_cast<UIDamageEffect*>((UIObject*)spRef);
    }
    return 0;
}

// ---- StateObserverData ----------------------------------------------------------------------------------------------

// @0x140ac3b40
StateObserverData::StateObserverData(__int64 nTarget)
{
    m_nTarget = nTarget;
}

// @0x140ac5640
static CString FUN_140ac5640(unsigned __int64 nId)
{
    return FUN_140719530(nId);
}

// @0x140ac3b90
void StateObserverData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = FUN_140ac5640(m_nTarget);
}

// @0x140ac3c10
void StateObserverData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nTarget = FUN_140718350(p->m_str70);
}

// ---- StateObserver --------------------------------------------------------------------------------------------------

// @0x140ac3c60
StateObserver::StateObserver(PCBase* pOwner) : State(pOwner), m_spObserve(new StateObserverData(0))
{
    m_nSwitchTick = 0;
    m_n14 = 0;
}

// @0x140ac3d20
StateObserver::~StateObserver()
{
}

// @0x140ac3d60
void StateObserver::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spObserve->m_nTarget = 0;
    m_nPending = 0;
    do
    {
        if (pData == 0)
            break;
        MS2Ptr<StateObserverData> spData(dynamic_cast<StateObserverData*>(pData));
        if (spData.IsNull())
            break;
        m_spObserve = spData;
    } while (0);
    {
        MS2Ptr<Unk_PCBaseComp_a78> spComp = m_pOwner->vfunc_82();
        if (spComp.get() != 0)
            reinterpret_cast<MS2Ptr<UIHudEntity::Entity>&>(spComp)->FUN_140f48dc0(0);
    }
    m_pOwner->vfunc_23(1);
    m_pOwner->vfunc_31(false);
    FUN_140ac45e0();
}

// @0x140ac3ed0
void StateObserver::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (n == 0x3f)
        return;
    m_pOwner->vfunc_23(0);
    m_pOwner->vfunc_31(true);
    FUN_140ac4760();
}

// @0x140ac3f50
void StateObserver::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner == 0)
        return;
    if (m_pOwner->FUN_14123c660() == 0)
    {
        m_pOwner->vfunc_23(1);
        m_pOwner->vfunc_31(false);
    }
    FUN_140ac48e0();
    FUN_140ac4c00();
}

// @0x140ac3ff0
void StateObserver::vfunc_8(double fTime)
{
    if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyReleased(0x39, true, 0))
        ObserveNext();
}

// @0x140ac4040
int StateObserver::vfunc_22(MS2Ptr<StateSyncObject> p)
{
    if (p.IsNull())
        return 0;
    unsigned __int64 nTargetId = FUN_140718350(p->m_str70);
    if (nTargetId == m_spObserve->m_nTarget)
        return 0;
    return 1;
}

// @0x140ac40f0
bool StateObserver::vfunc_28(MS2Ptr<StateSyncObject> p)
{
    unsigned __int64 nTargetId = FUN_140718350(p->m_str70);
    return GetObservedTargetId() != (__int64)nTargetId;
}

// @0x140ac4170
CStringW StateObserver::GetTargetName()
{
    Unk_ObsWorld* pWorld = reinterpret_cast<Unk_ObsWorld*>(WorldService::GetInstance());
    if (pWorld == 0)
        return CStringW(L"");
    MS2Ptr<CProxyGameObject> spProxy = reinterpret_cast<WorldService*>(pWorld)->FindProxyObjectByOwner((void*)m_spObserve->m_nTarget);
    if (spProxy.IsNull())
        return CStringW(L"");
    return spProxy->GetName();
}

// @0x140ac4270
void StateObserver::ObservePrevious()
{
    std::vector<__int64> ids;
    CollectObservableIds(ids);
    if (ids.empty())
        return;
    int nCount = (int)ids.size();
    int nPos = (int)(std::find(ids.begin(), ids.end(), m_spObserve->m_nTarget) - ids.begin());
    int nIdx = WrapIndex(nCount, nPos - 1);
    if ((nIdx >= 0 && nIdx <= nCount) == 0)
        return;
    FUN_140ac4c90(ids[nIdx]);
}

// @0x140ac43e0
void StateObserver::ObserveNext()
{
    std::vector<__int64> ids;
    CollectObservableIds(ids);
    if (ids.empty())
        return;
    int nCount = (int)ids.size();
    int nPos = (int)(std::find(ids.begin(), ids.end(), m_spObserve->m_nTarget) - ids.begin());
    int nIdx = WrapIndex(nCount, nPos + 1);
    if ((nIdx >= 0 && nIdx <= nCount) == 0)
        return;
    FUN_140ac4c90(ids[nIdx]);
}

// @0x140ac4550
void StateObserver::ObserveOther()
{
    std::set<unsigned __int64> excluded;
    excluded.insert(reinterpret_cast<const unsigned __int64&>(m_spObserve->m_nTarget));
    unsigned __int64 nId = FindNearestObservableId(excluded);
    if (nId == 0)
        return;
    FUN_140ac4c90(nId);
}

// @0x140ac45e0
void StateObserver::FUN_140ac45e0()
{
    if (FUN_1417b8560() == 0)
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    FUN_141274f50();
    reinterpret_cast<Unk_ActionKeyManager*>(Unk_PlayerActionState(reinterpret_cast<Unk_MiPlayer*>(pPC)))->SetEnabled(0);
    UIDamageEffect* pDamage = GetDamageEffect(0x4e3c);
    if (pDamage != 0)
        pDamage->FUN_141910660();
    UIMainPlayerInfo* pInfo = FindMainPlayerInfo(0x4e5f);
    if (pInfo != 0)
        pInfo->SetHideReason(8, false);
    reinterpret_cast<CUIService*>(TSingleton<CUIService>::GetInstance())->FUN_141add120((eUIClassID)0x4e43, 0);
    reinterpret_cast<CUIService*>(TSingleton<CUIService>::GetInstance())->FUN_141add120((eUIClassID)0x4e28, 0);
    reinterpret_cast<NotifySystem *>(FUN_140939a10())->RegisterNotify(L"NotifyKillPlayer", Delegate<void(NotifyObject*)>(this, &StateObserver::FUN_140ac4dc0));
}

// @0x140ac4760
void StateObserver::FUN_140ac4760()
{
    if (FUN_1417b8560() == 0)
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    reinterpret_cast<Unk_ActionKeyManager*>(Unk_PlayerActionState(reinterpret_cast<Unk_MiPlayer*>(pPC)))->SetEnabled(1);
    UIDamageEffect* pDamage = GetDamageEffect(0x4e3c);
    if (pDamage != 0)
        pDamage->FUN_141910700();
    UIMainPlayerInfo* pInfo = FindMainPlayerInfo(0x4e5f);
    if (pInfo != 0)
        pInfo->SetHideReason(8, true);
    reinterpret_cast<CUIService*>(TSingleton<CUIService>::GetInstance())->FUN_141add120((eUIClassID)0x4e43, 1);
    reinterpret_cast<CUIService*>(TSingleton<CUIService>::GetInstance())->FUN_141add120((eUIClassID)0x4e28, 1);
    reinterpret_cast<NotifySystem *>(FUN_140939a10())->UnregisterNotify(L"NotifyKillPlayer", Delegate<void(NotifyObject*)>(this, &StateObserver::FUN_140ac4dc0));
}

// @0x140ac48e0
void StateObserver::FUN_140ac48e0()
{
    if (FUN_1417b8560() == 0)
        return;
    Unk_ObsWorld* pWorld = reinterpret_cast<Unk_ObsWorld*>(WorldService::GetInstance());
    if (pWorld == 0)
        return;
    Vector3 vTarget;
    MS2Ptr<CProxyGameObject> spProxy = reinterpret_cast<WorldService*>(pWorld)->FindProxyObjectByOwner((void*)m_spObserve->m_nTarget);
    if (spProxy.IsNull())
    {
        ObserveOther();
        return;
    }
    if (spProxy->IsOtherPlayer() == 0)
    {
        ObserveOther();
        return;
    }
    if (spProxy->m_cc == 0x3f)
    {
        ObserveOther();
        return;
    }
    vTarget = spProxy->GetPosition();
    do
    {
        PCBase* pTarget = reinterpret_cast<PCBase*>(reinterpret_cast<WorldService*>(pWorld)->FUN_141bd1530(m_spObserve->m_nTarget));
        if (pTarget == 0)
            break;
        vTarget = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18()));
    } while (0);
    const NiPoint3& kOwner = m_pOwner->vfunc_18();
    Vector3 vDir = (vTarget - reinterpret_cast<const Vector3&>(kOwner));
    float fLen = vDir.Unitize();
    if (fLen > 1000.0f)
    {
        m_pOwner->vfunc_19(reinterpret_cast<const efd::Point3&>(vTarget));
        return;
    }
    const float kFrame = 60.0f;
    const float kSpeed = 10.0f;
    float fStep = (fLen / kFrame) * kSpeed;
    efd::Point3 vNew = kOwner + reinterpret_cast<const efd::Point3&>(vDir) * fStep;
    m_pOwner->vfunc_19(reinterpret_cast<const efd::Point3&>(vNew));
}

// @0x140ac4c00
void StateObserver::FUN_140ac4c00()
{
    if (m_nPending == 0)
        return;
    PCBase* pObject = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPending));
    if (pObject == 0)
        return;
    const int nCameraId = 100;
    TSingleton<CameraMgr>::GetInstance()->FUN_140aecbb0(nCameraId, pObject->GetObjectId(), true);
    m_nPending = 0;
}

// @0x140ac4c90
void StateObserver::FUN_140ac4c90(__int64 nTarget)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
    {
        MS2_ASSERT_AT(0x1a9, 0);
        return;
    }
    if (m_spObserve->m_nTarget == nTarget)
        return;
    unsigned nNow = GetTickCountMs2();
    if (nNow - m_nSwitchTick < 300)
        return;
    ((class MyPC*)(void*)(pPC))->FUN_14152e0c0();
    COutPacket packet(static_cast<int>(SendOp::SpectateMushtopia), 0);
    packet.WriteUInt8(2);
    packet.WriteInt64(nTarget);
    FUN_140710590(packet);
    m_spObserve->m_nTarget = nTarget;
    m_nSwitchTick = nNow;
}

// @0x140ac4dc0
void StateObserver::FUN_140ac4dc0(NotifyObject* pNotice)
{
    const Unk_ObsKillView* pKill = reinterpret_cast<const Unk_ObsKillView*>(pNotice);
    if (pKill == 0)
        return;
    const CStringW& strKiller = pKill->m_strKiller;
    const CStringW& strVictim = pKill->m_strVictim;
    Unk_ObsWorld* pWorld = reinterpret_cast<Unk_ObsWorld*>(WorldService::GetInstance());
    if (pWorld == 0)
        return;
    MS2Ptr<CProxyGameObject> spVictim = pWorld->FindProxyObjectByName(strVictim);
    if (spVictim.IsNull())
        return;
    if ((__int64)spVictim->GetCharacterId() != m_spObserve->m_nTarget)
        return;
    if (strVictim == strKiller)
    {
        ObserveOther();
        return;
    }
    MS2Ptr<CFieldDataCli> spMap = reinterpret_cast<WorldService*>(pWorld)->FUN_141bd30a0();
    if (spMap.IsNull())
        return;
    MS2Ptr<CProxyGameObject> spKiller = pWorld->FindProxyObjectByName(strKiller);
    if (spKiller.get() != 0)
        FUN_140ac4c90((__int64)spKiller->GetCharacterId());
    else
        ObserveOther();
}

// @0x140ac5c80
MS2Ptr<StateData> StateObserver::vfunc_27()
{
    return MS2Ptr<StateData>(new StateObserverData(0));
}

// @0x140ac5e90
int StateObserver::vfunc_1()
{
    return 0x3f;
}

// @0x140ac5ea0
__int64 StateObserver::GetObservedTargetId()
{
    return m_spObserve->m_nTarget;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9fe70-0x142c9ff40 .text$yd
