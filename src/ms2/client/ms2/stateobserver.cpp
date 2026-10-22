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
// MS2-PIN: ?IsNull@?$MS2Ptr@VUnk_StateArg22@@@@QEBA_NXZ 0x140ac5b00 ; unique
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

// ---- unit statics (.text$di): three statics ahead of the shared header statics ----

struct Unk_Handle1401cd100 { Unk_Handle1401cd100(int n); void* m_p; };      // 0x1401cd100
static CString s_strStun0 = "stun";
static Unk_Handle1401cd100 s_hNull0(0);
static Unk_1402a9d70 s_condition0(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The state-sync record (StateSyncObject, Unk_StateArg22 in statemanager.h): +0x70 holds the observed id as text.
class Unk_StateArg22 : public CPtred
{
public:
    char m_pad_18[0x70 - sizeof(CPtred)];
    CStringA m_str70;                                       // +0x70
};
MS2_CHECK_OFFSET(Unk_StateArg22, m_str70, 0x70);
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
    void FUN_140f48dc0(int bVisible);
};
class Unk_FieldRef : public CPtred {};                      // the current map record (only null-tested here)

// The notice the pvp kill log posts (NotifyKillPlayer in scenestategame.cpp): the two names behind the NotifyObject.
struct Unk_ObsKillView
{
    char m_pad_00[0x18];
    CStringW m_strKiller;                                   // +0x18
    CStringW m_strVictim;                                   // +0x20
};
MS2_CHECK_OFFSET(Unk_ObsKillView, m_strVictim, 0x20);

typedef ATL::CAtlMap<unsigned, MS2Ptr<CProxyGameObject> > Unk_ObsProxyMap;

class Unk_ObsWorld
{
public:
    MS2Ptr<CProxyGameObject> FUN_141bc9c60(__int64 nId);                // the proxy of a player by id
    MS2Ptr<CProxyGameObject> FUN_141bc9d60(const CStringW& strName);    // the proxy of a player by name
    MS2Ptr<Unk_FieldRef> FUN_141bd30a0();                               // the current map
    PCBase* FUN_141bd0cc0();                                            // the local player
    PCBase* FUN_141bd1530(__int64 nId);                                 // an actor by id
    Unk_ObsProxyMap* FUN_141bc9fb0();                                   // the proxy table
};
Unk_ObsWorld* FUN_1403ed2d0();

class UIDamageEffect : public UIObject
{
public:
    void FUN_141910660();
    void FUN_141910700();
};
class Unk_ObsUIMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);
    void FUN_141add120(int nUiId, int bShow);
};
Unk_ObsUIMgr* FUN_1403ed2b0();
UIMainPlayerInfo* FUN_140931900(int nUiId);

class Unk_ObsActionKeys { public: void FUN_1409536b0(int bEnable); };
Unk_ObsActionKeys* FUN_140a7b810(MyPC* pPC);                // the actor's action key set
void FUN_141274f50();
class Unk_ObsNotices { public: void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>); void FUN_140da4eb0(CStringW, Delegate<void(NotifyObject*)>); };
Unk_ObsNotices* FUN_140939a10();
class Unk_ObsQuery { public: void FUN_140aecbb0(int a, int b, bool c); };
Unk_ObsQuery* FUN_1409478c0();
CInputKeyHandler* FUN_14025e7c0();
unsigned FUN_140869420();                                   // millisecond clock
void FUN_14152e0c0(void* pPC);
void FUN_140710590(COutPacket& packet);                     // send
bool FUN_14025cd60(const CStringW& a, const CStringW& b);   // equal names

// Both the NiPoint3 the owner hands out and the efd::Point3 it takes are the same three floats as Vector3.
static const Vector3& AsPoint(const NiPoint3& pt)
{
    return reinterpret_cast<const Vector3&>(pt);
}
static efd::Point3 AsEfd(const Vector3& pt)
{
    return efd::Point3(pt.x, pt.y, pt.z);
}

// @0x140ac4f90
// Wraps nIdx into [0, nCount).
static int FUN_140ac4f90(int nCount, int nIdx)
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
static void FUN_140ac4fe0(std::vector<__int64>& ids)
{
    ids.clear();
    Unk_ObsWorld* pWorld = FUN_1403ed2d0();
    if (pWorld != 0)
    {
        Unk_ObsProxyMap* pMap = pWorld->FUN_141bc9fb0();
        POSITION pos = pMap->GetStartPosition();
        while (pos != 0)
        {
            MS2Ptr<CProxyGameObject> spProxy(pMap->GetValueAt(pos));
            if (!spProxy.IsNull())
            {
                if (spProxy->FUN_1416c2040() != 0)
                {
                    if (spProxy->kind == 0)
                    {
                        if (spProxy->m_cc != 0x3f)
                        {
                            __int64 nId = (__int64)spProxy->FUN_1416c22f0();
                            ids.push_back(nId);
                        }
                    }
                }
            }
            pMap->GetNext(pos);
        }
    }
}

// @0x140ac5130
// The observable player nearest to the local player that is not in excluded (0 when there is none).
static unsigned __int64 FUN_140ac5130(std::set<unsigned __int64>& excluded)
{
    Unk_ObsWorld* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return 0;
    MS2Ptr<Unk_FieldRef> spMap = pWorld->FUN_141bd30a0();
    if (spMap.IsNull())
        return 0;
    PCBase* pPlayer = pWorld->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    float fBest = FLT_MAX;
    MS2Ptr<CProxyGameObject> spBest;
    Unk_ObsProxyMap* pMap = pWorld->FUN_141bc9fb0();
    POSITION pos = pMap->GetStartPosition();
    while (pos != 0)
    {
        MS2Ptr<CProxyGameObject> spProxy(pMap->GetValueAt(pos));
        if (!spProxy.IsNull())
        {
            if (spProxy->FUN_1416c2040() != 0)
            {
                if (spProxy->kind == 0)
                {
                    if (spProxy->m_cc != 0x3f)
                    {
                        unsigned __int64 nId = (unsigned __int64)spProxy->FUN_1416c22f0();
                        if (excluded.find(nId) == excluded.end())
                        {
                            float fDist = AsPoint(pPlayer->vfunc_18()).FUN_140965c40(spProxy->FUN_1416c2270()).FUN_140967ac0();
                            if (fDist < fBest)
                            {
                                fBest = fDist;
                                spBest = spProxy;
                            }
                        }
                    }
                }
            }
        }
        pMap->GetNext(pos);
    }
    if (!spBest.IsNull())
        return (unsigned __int64)spBest->FUN_1416c22f0();
    return 0;
}

// @0x140ac55a0
static UIDamageEffect* FUN_140ac55a0(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spRef = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
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
    if (pData != 0)
    {
        MS2Ptr<StateObserverData> spData(dynamic_cast<StateObserverData*>(pData));
        if (!spData.IsNull())
            m_spObserve = spData;
    }
    MS2Ptr<Unk_PCBaseComp_a78> spComp = m_pOwner->vfunc_82();
    if (spComp.get() != 0)
        spComp->FUN_140f48dc0(0);
    m_pOwner->vfunc_23(1);
    m_pOwner->vfunc_31(false);
    FUN_140ac45e0();
}

// @0x140ac3ed0
void StateObserver::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (n != 0x3f)
    {
        m_pOwner->vfunc_23(0);
        m_pOwner->vfunc_31(true);
        FUN_140ac4760();
    }
}

// @0x140ac3f50
void StateObserver::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner != 0)
    {
        if (m_pOwner->FUN_14123c660() == 0)
        {
            m_pOwner->vfunc_23(1);
            m_pOwner->vfunc_31(false);
        }
        FUN_140ac48e0();
        FUN_140ac4c00();
    }
}

// @0x140ac3ff0
void StateObserver::vfunc_8(double fTime)
{
    if (FUN_14025e7c0()->FUN_14116da30(0x39, true, 0))
        FUN_140ac43e0();
}

// @0x140ac4040
int StateObserver::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (!p.IsNull())
    {
        if (FUN_140718350(p->m_str70) == (unsigned __int64)m_spObserve->m_nTarget)
            return 0;
        return 1;
    }
    return 0;
}

// @0x140ac40f0
bool StateObserver::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    return FUN_140ac5ea0() != (__int64)FUN_140718350(p->m_str70);
}

// @0x140ac4170
CStringW StateObserver::FUN_140ac4170()
{
    Unk_ObsWorld* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return CStringW(L"");
    MS2Ptr<CProxyGameObject> spProxy = pWorld->FUN_141bc9c60(m_spObserve->m_nTarget);
    if (!spProxy.IsNull())
        return spProxy->FUN_1416c23b0();
    return CStringW(L"");
}

// @0x140ac4270
void StateObserver::FUN_140ac4270()
{
    std::vector<__int64> ids;
    FUN_140ac4fe0(ids);
    if (!ids.empty())
    {
        int nCount = (int)ids.size();
        int nIdx = FUN_140ac4f90(nCount, (int)(std::find(ids.begin(), ids.end(), m_spObserve->m_nTarget) - ids.begin()) - 1);
        if (nIdx >= 0 && nIdx <= nCount)
            FUN_140ac4c90(ids[nIdx]);
    }
}

// @0x140ac43e0
void StateObserver::FUN_140ac43e0()
{
    std::vector<__int64> ids;
    FUN_140ac4fe0(ids);
    if (!ids.empty())
    {
        int nCount = (int)ids.size();
        int nIdx = FUN_140ac4f90(nCount, (int)(std::find(ids.begin(), ids.end(), m_spObserve->m_nTarget) - ids.begin()) + 1);
        if (nIdx >= 0 && nIdx <= nCount)
            FUN_140ac4c90(ids[nIdx]);
    }
}

// @0x140ac4550
void StateObserver::FUN_140ac4550()
{
    std::set<unsigned __int64> excluded;
    excluded.insert(m_spObserve->m_nTarget);
    unsigned __int64 nId = FUN_140ac5130(excluded);
    if (nId != 0)
        FUN_140ac4c90(nId);
}

// @0x140ac45e0
void StateObserver::FUN_140ac45e0()
{
    if (FUN_1417b8560() != 0)
    {
        MyPC* pPC = FUN_1417b84b0();
        if (pPC != 0)
        {
            FUN_141274f50();
            FUN_140a7b810(pPC)->FUN_1409536b0(0);
            UIDamageEffect* pDamage = FUN_140ac55a0(0x4e3c);
            if (pDamage != 0)
                pDamage->FUN_141910660();
            UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
            if (pInfo != 0)
                pInfo->FUN_1419f1d10(8, false);
            FUN_1403ed2b0()->FUN_141add120(0x4e43, 0);
            FUN_1403ed2b0()->FUN_141add120(0x4e28, 0);
            FUN_140939a10()->FUN_140da4e40(L"NotifyKillPlayer", Delegate<void(NotifyObject*)>(this, &StateObserver::FUN_140ac4dc0));
        }
    }
}

// @0x140ac4760
void StateObserver::FUN_140ac4760()
{
    if (FUN_1417b8560() != 0)
    {
        MyPC* pPC = FUN_1417b84b0();
        if (pPC != 0)
        {
            FUN_140a7b810(pPC)->FUN_1409536b0(1);
            UIDamageEffect* pDamage = FUN_140ac55a0(0x4e3c);
            if (pDamage != 0)
                pDamage->FUN_141910700();
            UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
            if (pInfo != 0)
                pInfo->FUN_1419f1d10(8, true);
            FUN_1403ed2b0()->FUN_141add120(0x4e43, 1);
            FUN_1403ed2b0()->FUN_141add120(0x4e28, 1);
            FUN_140939a10()->FUN_140da4eb0(L"NotifyKillPlayer", Delegate<void(NotifyObject*)>(this, &StateObserver::FUN_140ac4dc0));
        }
    }
}

// @0x140ac48e0
// MS2-FUNCTIONAL: written against the unit-local point views
void StateObserver::FUN_140ac48e0()
{
    if (FUN_1417b8560() != 0)
    {
        Unk_ObsWorld* pWorld = FUN_1403ed2d0();
        if (pWorld != 0)
        {
            Vector3 vTarget;
            MS2Ptr<CProxyGameObject> spProxy = pWorld->FUN_141bc9c60(m_spObserve->m_nTarget);
            if (!spProxy.IsNull())
            {
                if (spProxy->FUN_1416c2040() == 0)
                {
                    FUN_140ac4550();
                }
                else if (spProxy->m_cc == 0x3f)
                {
                    FUN_140ac4550();
                }
                else
                {
                    vTarget = spProxy->FUN_1416c2270();
                    PCBase* pTarget = pWorld->FUN_141bd1530(m_spObserve->m_nTarget);
                    if (pTarget != 0)
                        vTarget = AsPoint(pTarget->vfunc_18());
                    Vector3 vOwner = AsPoint(m_pOwner->vfunc_18());
                    Vector3 vDir = vTarget.FUN_140965c40(vOwner);
                    float fLen = vDir.FUN_140968990();
                    if (fLen <= 1000.0f)
                    {
                        float fStep = (fLen / 60.0f) * 10.0f;
                        Vector3 vNew = vOwner.FUN_14097fd50(vDir.FUN_14097fc90(fStep));
                        m_pOwner->vfunc_19(AsEfd(vNew));
                    }
                    else
                    {
                        m_pOwner->vfunc_19(AsEfd(vTarget));
                    }
                }
            }
        }
    }
}

// @0x140ac4c00
void StateObserver::FUN_140ac4c00()
{
    if (m_nPending != 0)
    {
        PCBase* pObject = FUN_1403ed2d0()->FUN_141bd1530(m_nPending);
        if (pObject != 0)
        {
            int nId = pObject->FUN_14123c580();
            FUN_1409478c0()->FUN_140aecbb0(100, nId, true);
            m_nPending = 0;
        }
    }
}

// @0x140ac4c90
void StateObserver::FUN_140ac4c90(__int64 nTarget)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
    {
        MS2_ASSERT_AT(0x1a9, 0);
    }
    else if (m_spObserve->m_nTarget != nTarget)
    {
        unsigned nNow = FUN_140869420();
        if (nNow - m_nSwitchTick > 299)
        {
            FUN_14152e0c0(pPC);
            COutPacket packet(static_cast<int>(SendOp::SpectateMushtopia), 0);
            packet.WriteUInt8(2);
            packet.WriteInt64(nTarget);
            FUN_140710590(packet);
            m_spObserve->m_nTarget = nTarget;
            m_nSwitchTick = nNow;
        }
    }
}

// @0x140ac4dc0
void StateObserver::FUN_140ac4dc0(NotifyObject* pNotice)
{
    if (pNotice != 0)
    {
        const Unk_ObsKillView* pKill = reinterpret_cast<const Unk_ObsKillView*>(pNotice);
        Unk_ObsWorld* pWorld = FUN_1403ed2d0();
        if (pWorld != 0)
        {
            MS2Ptr<CProxyGameObject> spVictim = pWorld->FUN_141bc9d60(pKill->m_strVictim);
            if (!spVictim.IsNull())
            {
                if ((__int64)spVictim->FUN_1416c22f0() == m_spObserve->m_nTarget)
                {
                    if (FUN_14025cd60(pKill->m_strVictim, pKill->m_strKiller))
                    {
                        FUN_140ac4550();
                    }
                    else
                    {
                        MS2Ptr<Unk_FieldRef> spMap = pWorld->FUN_141bd30a0();
                        if (spMap.IsNull())
                            return;
                        MS2Ptr<CProxyGameObject> spKiller = pWorld->FUN_141bc9d60(pKill->m_strKiller);
                        if (spKiller.get() == 0)
                            FUN_140ac4550();
                        else
                            FUN_140ac4c90((__int64)spKiller->FUN_1416c22f0());
                    }
                }
            }
        }
    }
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
__int64 StateObserver::FUN_140ac5ea0()
{
    return m_spObserve->m_nTarget;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9fe70-0x142c9ff40 .text$yd
