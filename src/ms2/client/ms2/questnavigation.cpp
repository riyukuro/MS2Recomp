// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest navigation: the QuestNavigation trace records and
// CQuestNavigationMap, the TSingleton that builds the all-pairs shortest portal paths between maps
// (CFieldMetaTable's portal targets, Floyd-Warshall over a short matrix) and, per quest condition, the maps holding its
// npc / interact object / liftable targets. TraceQuest picks the nearest such map from the current one.
// The range holds the trace record bodies with their glue and memmove_s copy, then the map's TU (memcpy_s copy last).
// MS2-UNIT: ?\questnavigation.cpp
// MS2-RANGE: 0x140c90340-0x140c99700 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$Unk_QnLog@_J@@YAXPEAVCLogString@@HHPEB_WAEB_J@Z 0x140c935a0 ; unique
// MS2-PIN: ??$Unk_QnLog@_JI@@YAXPEAVCLogString@@HHPEB_WAEB_JAEBI@Z 0x140c93630 ; unique
// MS2-PIN: ??$Unk_QnMerge@H@@YAXV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@AEAV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@Z 0x140c93930 ; unique
// MS2-PIN: ??$Unk_QnMerge@I@@YAXV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@AEAV?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@Z 0x140c939c0 ; unique
// MS2-PIN: ??$Allocate@VTraceContext@QuestNavigation@@@?$MS2Ptr@UUnk_QnAccess@@@@SAPEAVTraceContext@QuestNavigation@@PEAX@Z 0x140c93ac0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VTraceContext@QuestNavigation@@@@QEAA@H@Z 0x140c94000 ; unique
// MS2-PIN: ??0?$MS2Ptr@VTraceContext@QuestNavigation@@@@QEAA@PEAVTraceContext@QuestNavigation@@@Z 0x140c94020 ; unique
// MS2-PIN: ??0?$MS2Ptr@VTraceTarget@CQuestNavigationMap@@@@QEAA@PEAVTraceTarget@CQuestNavigationMap@@@Z 0x140c94070 ; unique
// MS2-PIN: ??C?$MS2Ptr@VTraceContext@QuestNavigation@@@@QEBAPEAVTraceContext@QuestNavigation@@XZ 0x140c94880 ; unique
// MS2-PIN: ??C?$MS2Ptr@VTraceTarget@CQuestNavigationMap@@@@QEBAPEAVTraceTarget@CQuestNavigationMap@@XZ 0x140c94890 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140c956e0 ; unique
// MS2-PIN: ??$Create@VTraceContext@QuestNavigation@@@?$MS2Ptr@UUnk_QnAccess@@@@SAPEAVTraceContext@QuestNavigation@@PEAX@Z 0x140c99470 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlMap@HV?$MS2Ptr@VTraceTarget@CQuestNavigationMap@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VTraceTarget@CQuestNavigationMap@@@@@3@@ATL@@@@6B@ 0x142e14e98 ; RTTI names it TPtr<>
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\questnavigation.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/placeholder/cquestnavigationmap.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class WorldService;
WorldService* FUN_1403ed2d0();                              // WorldService::GetInstance
unsigned FUN_141bd3060(WorldService* pWorld);               // the current map id
int FUN_1412755a0();
int FUN_14074b030(CQuestData* pQuest);                      // the quest id
CQuestManager* FUN_140764020();
int FUN_1406fc7b0(CFieldMetaTable* pTable, unsigned nFrom, unsigned nTo);   // a portal leads from nFrom to nTo

// The game's TPtr has a private allocating reset (`p = New(0)`); a specialization is a friend of every MS2Ptr<T>.
struct Unk_QnAccess;
template <>
class MS2Ptr<Unk_QnAccess>
{
public:
    template <class T> static MS2Ptr<T>& Assign(MS2Ptr<T>& sp, const Unk_BmNewTag&) { Make(sp); return sp; }
    template <class T> static void Make(MS2Ptr<T>& sp) { sp.Release(); sp.m_p = Create<T>(0); }
    template <class T> static T* Create(void*) { return static_cast<T*>(FUN_1401ba820(Allocate<T>(0))); }
    template <class T> static T* Allocate(void*) { return new T; }
};
typedef MS2Ptr<Unk_QnAccess> Unk_QnPtrAccess;

template <class T> MS2BoxPtr<T>::MS2BoxPtr() { m_p = 0; }
template <class T> MS2BoxPtr<T>::MS2BoxPtr(int) { m_p = 0; }
template <class T> MS2BoxPtr<T>::MS2BoxPtr(const Unk_BmNewTag&) { m_p = 0; Make(); }
template <class T> MS2BoxPtr<T>::MS2BoxPtr(const MS2BoxPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> MS2BoxPtr<T>::MS2BoxPtr(MS2BoxPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> MS2BoxPtr<T>::~MS2BoxPtr() { Release(); }
template <class T> MS2BoxPtr<T>& MS2BoxPtr<T>::operator=(const MS2BoxPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> T* MS2BoxPtr<T>::operator->() const { return m_p; }
template <class T> void MS2BoxPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void MS2BoxPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void MS2BoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* MS2BoxPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* MS2BoxPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* MS2BoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void MS2BoxPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> T* MS2BoxPtr<T>::Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
template <class T> void MS2BoxPtr<T>::AddRefImpl(void*) const { Ref(Owner(m_p)); }
template <class T> void MS2BoxPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

namespace QuestNavigation {

// @0x140c90340
TraceContext::TraceContext() : m_18(0)
{
}

// @0x140c903c0
TraceContext::~TraceContext()
{
}

// @0x140c90420
TraceResult::TraceResult()
{
    Clear();
}

// @0x140c904b0
void TraceResult::Clear()
{
    m_1c = 0;
    m_20 = efd::Point3::ZERO;
    m_2c = efd::Point3::ZERO;
    m_38 = L"";
    m_40 = 0;
}

} // namespace QuestNavigation

// @0x140c90720
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// FMT_VARIADIC log wrappers (CLogString::FUN_1406530d0 takes the packed argument list).
template <class A> inline void Unk_QnLog(CLogString* log, int level, int category, const wchar_t* format, const A& a)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a), args));
}
template <class A, class B> inline void Unk_QnLog(CLogString* log, int level, int category, const wchar_t* format,
                                                  const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}

// Adds the ids of a target list to a context's id set (the list by value: the callee releases it).
template <class T> inline void Unk_QnMerge(Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > spIds, std::set<T>& ids)
{
    for (size_t i = 0; i < spIds->GetCount(); i++)
        ids.insert(spIds->GetAt(i));
}
template <> inline void Unk_QnMerge<int>(Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > spIds, std::set<int>& ids)
{
    for (size_t i = 0; i < spIds->GetCount(); i++)
    {
        int nId = spIds->GetAt(i);
        ids.insert(nId);
    }
}

// @0x140c90840
CQuestNavigationMap::CQuestNavigationMap()
{
    m_8 = 0;
}

// @0x140c90920
CQuestNavigationMap::~CQuestNavigationMap()
{
}

// @0x140c909a0
void CQuestNavigationMap::FUN_140c909a0()
{
    BuildMapPaths();
    m_8 = 1;
}

// @0x140c909d0
int CQuestNavigationMap::BuildMapPaths()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x77))
        return 1;
    Unk_FieldIdListMap& portals = TSingleton<CFieldMetaTable>::GetInstance()->FUN_140c955c0();
    short nCount = (short)portals.GetCount() + 1;
    m_10.SetCount(nCount);
    short nIndex = 1;
    for (POSITION pos = portals.GetStartPosition(); pos; portals.GetNext(pos))
    {
        unsigned nMap = portals.GetKeyAt(pos);
        m_30.SetAt(nMap, nIndex);
        m_10[nIndex] = nMap;
        nIndex++;
    }
    ATL::CAtlArray<ATL::CAtlArray<short> > costs;
    ATL::CAtlArray<ATL::CAtlArray<short> > dist;
    costs.SetCount(nCount);
    dist.SetCount(nCount);
    m_78.SetCount(nCount);
    for (short i = 0; i < nCount; i++)
    {
        costs[i].SetCount(nCount);
        dist[i].SetCount(nCount);
        m_78[i].SetCount(nCount);
    }
    for (short i = 0; i < nCount; i++)
    {
        for (short j = 0; j < nCount; j++)
        {
            unsigned nFrom = m_10[i];
            unsigned nTo = m_10[j];
            if (i == j)
                costs[i][j] = 0;
            else if (FUN_1406fc7b0(TSingleton<CFieldMetaTable>::GetInstance(), nFrom, nTo))
            {
                short nCost = 1;
                if (nFrom == 0x3197542 || nTo == 0x3197542)
                    nCost = 3;
                costs[i][j] = nCost;
            }
            else
                costs[i][j] = 0x7fff;
        }
    }
    for (short i = 0; i < nCount; i++)
        for (short j = 0; j < nCount; j++)
            dist[i][j] = costs[i][j];
    for (short k = 0; k < nCount; k++)
        for (short i = 0; i < nCount; i++)
            for (short j = 0; j < nCount; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    m_78[i][j] = k;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
    m_8 = 1;
    return 1;
}

// @0x140c91180
int CQuestNavigationMap::FindMapPath(int nFrom, int nTo, ATL::CAtlArray<unsigned>& path)
{
    short nFromIndex = 0;
    short nToIndex = 0;
    if (nFrom == nTo)
    {
        path.Add(nFrom);
        return 1;
    }
    if (!m_30.Lookup(nFrom, nFromIndex))
        return 0;
    if (!m_30.Lookup(nTo, nToIndex))
        return 0;
    if (m_78[nFromIndex][nToIndex] == 0)
    {
        if (!FUN_1406fc7b0(TSingleton<CFieldMetaTable>::GetInstance(), nFrom, nTo))
            return 0;
    }
    path.Add(nFrom);
    int nDepth = 0;
    CollectMapPath(nFromIndex, nToIndex, path, nDepth);
    path.Add(nTo);
    return 1;
}

// @0x140c912d0
int CQuestNavigationMap::FUN_140c912d0(int nFrom, int nTo)
{
    ATL::CAtlArray<unsigned> path;
    if (FindMapPath(nFrom, nTo, path) && path.GetCount() > 1)
        return path[1];
    return 0;
}

// @0x140c91370
// MS2-FUNCTIONAL: frame 0x88 vs 0x78, the exe spills m_78[a][b] temporaries to extra slots
void CQuestNavigationMap::CollectMapPath(short nFrom, short nTo, ATL::CAtlArray<unsigned>& path, int& nDepth)
{
    if (!m_8)
        return;
    nDepth++;
    if (nDepth > (int)m_30.GetCount())
        return;
    if (m_78[nFrom][nTo] == 0)
        return;
    CollectMapPath(nFrom, m_78[nFrom][nTo], path, nDepth);
    path.Add(m_10[m_78[nFrom][nTo]]);
    CollectMapPath(m_78[nFrom][nTo], nTo, path, nDepth);
}

// @0x140c915a0
int CQuestNavigationMap::NearestMap(const ATL::CAtlArray<unsigned>& maps)
{
    unsigned nCurrent = FUN_141bd3060(FUN_1403ed2d0());
    int nBest = 0x7fffffff;
    int nNearest = 0;
    for (size_t i = 0; i < maps.GetCount(); i++)
    {
        ATL::CAtlArray<unsigned> path;
        if (FindMapPath(nCurrent, maps[i], path))
        {
            if (nBest >= (int)path.GetCount())
            {
                nBest = (int)path.GetCount();
                nNearest = maps[i];
            }
        }
    }
    return nNearest;
}

// @0x140c91690
// MS2-FUNCTIONAL: 3.7KB condition/navigation scan, temporaries and stack slots differ (permuter lane)
int CQuestNavigationMap::InitTraceTable()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x77))
        return 1;
    if (FUN_1412755a0())
        return 1;
    ATL::CAtlArray<MS2Ptr<CQuestData> > quests;
    TSingleton<QuestDataTable>::GetInstance()->FUN_14074cad0(quests, 0xb);
    for (size_t q = 0; q < quests.GetCount(); q++)
    {
        MS2Ptr<CQuestData> spQuest(quests[q]);
        unsigned char bUseNavi = spQuest->m_flag;
        unsigned bHasTag = !spQuest->m_schedule.IsEmpty() ? 1 : 0;
        MS2BoxPtr<TargetTable> spTable(Unk_BmNewTag(0));
        m_98.SetAt(FUN_14074b030(spQuest.operator->()), spTable);
        for (size_t c = 0; c < spQuest->m_conditions.GetCount(); c++)
        {
            MS2Ptr<TraceTarget> spTarget(new TraceTarget);
            Unk_SocketPtr<CQuestData::NavigationData> spNavi = spQuest->FUN_14074b380((int)c);
            if (!spNavi.get())
            {
                MS2Ptr<CConditionCommonData> spCond(spQuest->m_conditions[c]);
                if (ClassifyCondition(spCond->m_nType) == 0)
                {
                    for (size_t i = 0; i < spCond->m_code.m_ids.GetCount(); i++)
                    {
                        ATL::CAtlArray<unsigned> maps;
                        if (!FindConditionMaps(spCond, maps))
                            TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb2a0((unsigned)spCond->m_code.m_ids[i], maps);
                        spTarget->AddMaps(0, (unsigned)spCond->m_code.m_ids[i], maps);
                        if (maps.GetCount() == 0 && bUseNavi && !bHasTag)
                        {
                            unsigned nQuestId = FUN_14074b030(spQuest.operator->());
                            Unk_QnLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                                      L"QuestNavigationMap InitTraceTable Zero Count NpcID:{0} QuestID:{1}",
                                      spCond->m_code.m_ids[i], nQuestId);
                        }
                    }
                }
                else if (ClassifyCondition(spCond->m_nType) == 1)
                {
                    for (size_t i = 0; i < spCond->m_code.m_ids.GetCount(); i++)
                    {
                        ATL::CAtlArray<unsigned> maps;
                        if (!FindConditionMaps(spCond, maps))
                            TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb1e0((int)spCond->m_code.m_ids[i], maps);
                        spTarget->AddMaps(1, (unsigned)spCond->m_code.m_ids[i], maps);
                        if (maps.GetCount() == 0 && bUseNavi && !bHasTag)
                        {
                            unsigned nQuestId = FUN_14074b030(spQuest.operator->());
                            Unk_QnLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                                      L"QuestNavigationMap InitTraceTable Zero Count Interact ObjectID:{0} QuestID:{1}",
                                      spCond->m_code.m_ids[i], nQuestId);
                        }
                    }
                }
                else if (ClassifyCondition(spCond->m_nType) == 2)
                {
                    for (size_t i = 0; i < spCond->m_code.m_ids.GetCount(); i++)
                    {
                        ATL::CAtlArray<unsigned> maps;
                        if (!FindConditionMaps(spCond, maps))
                            TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb120((unsigned)spCond->m_code.m_ids[i], maps);
                        spTarget->AddMaps(2, (unsigned)spCond->m_code.m_ids[i], maps);
                        if (maps.GetCount() == 0 && bUseNavi && !bHasTag)
                            Unk_QnLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                                      L"QuestNavigationMap InitTraceTable Zero Count liftable {0}",
                                      spCond->m_code.m_ids[i]);
                    }
                }
            }
            else
            {
                for (size_t n = 0; n < spNavi->m_targets.GetCount(); n++)
                {
                    Unk_SocketPtr<CQuestData::NavigationTarget> spEntry(spNavi->m_targets[n]);
                    if (spEntry->m_kind == 0)
                    {
                        for (size_t i = 0; i < spEntry->m_ids.GetCount(); i++)
                        {
                            if (spEntry->m_maps.GetCount() == 0)
                            {
                                ATL::CAtlArray<unsigned> maps;
                                TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb2a0(spEntry->m_ids[i], maps);
                                spTarget->AddMaps(0, spEntry->m_ids[i], maps);
                            }
                            else
                                spTarget->AddMaps(0, spEntry->m_ids[i], spEntry->m_maps);
                        }
                    }
                    else if (spEntry->m_kind == 1)
                    {
                        for (size_t i = 0; i < spEntry->m_ids.GetCount(); i++)
                        {
                            if (spEntry->m_maps.GetCount() == 0)
                            {
                                ATL::CAtlArray<unsigned> maps;
                                TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb1e0(spEntry->m_ids[i], maps);
                                spTarget->AddMaps(1, spEntry->m_ids[i], maps);
                            }
                            else
                                spTarget->AddMaps(1, spEntry->m_ids[i], spEntry->m_maps);
                        }
                    }
                    else if (spEntry->m_kind == 2)
                    {
                        for (size_t i = 0; i < spEntry->m_ids.GetCount(); i++)
                        {
                            if (spEntry->m_maps.GetCount() == 0)
                            {
                                ATL::CAtlArray<unsigned> maps;
                                TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb120(spEntry->m_ids[i], maps);
                                spTarget->AddMaps(2, spEntry->m_ids[i], maps);
                            }
                            else
                                spTarget->AddMaps(2, spEntry->m_ids[i], spEntry->m_maps);
                        }
                    }
                }
            }
            if (spTarget->HasTargets())
                spTable->SetAt((int)c, spTarget);
        }
    }
    return 1;
}

// @0x140c92510
int CQuestNavigationMap::FindConditionMaps(MS2Ptr<CConditionCommonData> spCond, ATL::CAtlArray<unsigned>& maps)
{
    int bSupported = 0;
    switch (spCond->m_nType)
    {
    case 0xc:
        bSupported = 1;
        break;
    }
    if (bSupported)
    {
        if (spCond->m_target.m_ids.GetCount() > 0)
        {
            for (size_t i = 0; i < spCond->m_target.m_ids.GetCount(); i++)
                maps.Add((unsigned)spCond->m_target.m_ids[i]);
            return 1;
        }
    }
    return 0;
}

// @0x140c92620
int CQuestNavigationMap::ClassifyCondition(int nType)
{
    switch (nType)
    {
    case 0xc:
    case 0x1a:
    case 0x1b:
        return 0;
    case 0x1d:
    case 0x1e:
        return 1;
    case 0x9c:
        return 2;
    default:
        return 3;
    }
}

// @0x140c92730
// MS2-FUNCTIONAL: completed-quest / context-map temporaries differ (permuter lane)
MS2Ptr<QuestNavigation::TraceContext> CQuestNavigationMap::TraceQuest(int nQuestId)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x77))
        return MS2Ptr<QuestNavigation::TraceContext>(0);
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
    if (spQuest.IsNull())
        return MS2Ptr<QuestNavigation::TraceContext>(0);
    if (!spQuest->IsActive())
        return MS2Ptr<QuestNavigation::TraceContext>(0);
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (spData.IsNull())
        return MS2Ptr<QuestNavigation::TraceContext>(0);
    if (spQuest->IsComplete())
    {
        MS2Ptr<QuestNavigation::TraceContext> spContext(new QuestNavigation::TraceContext);
        spContext->m_20.insert(*reinterpret_cast<unsigned*>(&spData->m_2ec));
        ATL::CAtlArray<unsigned> maps;
        TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb2a0(spData->m_2ec, maps);
        spContext->m_18 = NearestMap(maps);
        return spContext;
    }
    MS2BoxPtr<TargetTable> spTable(0);
    if (!m_98.Lookup(nQuestId, spTable))
        return MS2Ptr<QuestNavigation::TraceContext>(0);
    ATL::CAtlArray<unsigned> maps;
    ATL::CAtlMap<unsigned, MS2Ptr<QuestNavigation::TraceContext> > contexts;
    for (size_t c = 0; c < spData->m_conditions.GetCount(); c++)
    {
        if (!spQuest->IsConditionComplete((int)c))
        {
            MS2Ptr<TraceTarget> spTarget(0);
            if (spTable->Lookup((int)c, spTarget))
            {
                for (size_t nKind = 0; nKind < 3; nKind++)
                {
                    for (POSITION pos = spTarget->m_targets[nKind].GetStartPosition(); pos; spTarget->m_targets[nKind].GetNext(pos))
                    {
                        unsigned nMap = spTarget->m_targets[nKind].GetKeyAt(pos);
                        Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > spIds(spTarget->m_targets[nKind].GetValueAt(pos));
                        MS2Ptr<QuestNavigation::TraceContext> spContext(0);
                        if (!contexts.Lookup(nMap, spContext))
                        {
                            Unk_QnPtrAccess::Assign(spContext, Unk_BmNewTag(0));
                            spContext->m_18 = nMap;
                            maps.Add(nMap);
                            contexts.SetAt(nMap, spContext);
                        }
                        switch (nKind)
                        {
                        case 0:
                            Unk_QnMerge(spIds, spContext->m_20);
                            break;
                        case 1:
                            Unk_QnMerge(spIds, spContext->m_30);
                            break;
                        case 2:
                            Unk_QnMerge(spIds, spContext->m_40);
                            break;
                        }
                    }
                }
            }
        }
    }
    int nNearest = NearestMap(maps);
    MS2Ptr<QuestNavigation::TraceContext> spResult(0);
    contexts.Lookup(nNearest, spResult);
    return spResult;
}

// @0x140c92fc0
// MS2-FUNCTIONAL: temporaries/stack layout differ in the condition loop (permuter lane)
void CQuestNavigationMap::FUN_140c92fc0(Unk_PayloadPtr<CQuest> spQuest, int nMapId, QuestNavigation::TraceContext& context)
{
    if (spQuest.IsNull())
        return;
    if (!spQuest->IsActive())
        return;
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (spData.IsNull())
        return;
    MS2BoxPtr<TargetTable> spTable(0);
    if (!m_98.Lookup(spQuest->FUN_140bfc580(), spTable))
        return;
    for (size_t c = 0; c < spData->m_conditions.GetCount(); c++)
    {
        if (!spQuest->IsConditionComplete((int)c))
        {
            MS2Ptr<TraceTarget> spTarget(0);
            if (spTable->Lookup((int)c, spTarget))
            {
                for (size_t nKind = 0; nKind < 3; nKind++)
                {
                    for (POSITION pos = spTarget->m_targets[nKind].GetStartPosition(); pos; spTarget->m_targets[nKind].GetNext(pos))
                    {
                        int nMap = spTarget->m_targets[nKind].GetKeyAt(pos);
                        Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > spIds(spTarget->m_targets[nKind].GetValueAt(pos));
                        if (nMap != nMapId)
                            continue;
                        switch (nKind)
                        {
                        case 0:
                            Unk_QnMerge(spIds, context.m_20);
                            break;
                        case 1:
                            Unk_QnMerge(spIds, context.m_30);
                            break;
                        case 2:
                            Unk_QnMerge(spIds, context.m_40);
                            break;
                        }
                    }
                }
            }
        }
    }
}

// @0x140c93430
int CQuestNavigationMap::TraceTarget::HasTargets()
{
    for (size_t i = 0; i < 3; i++)
    {
        if (m_targets[i].GetCount() > 0)
            return 1;
    }
    return 0;
}

// @0x140c93490
void CQuestNavigationMap::TraceTarget::AddMaps(int nKind, unsigned nId, ATL::CAtlArray<unsigned>& maps)
{
    for (size_t i = 0; i < maps.GetCount(); i++)
    {
        unsigned nMap = maps[i];
        Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > spIds(0);
        if (!m_targets[nKind].Lookup(nMap, spIds))
        {
            spIds = Unk_BmNewTag(0);
            m_targets[nKind].SetAt(nMap, spIds);
        }
        spIds->Add(nId);
    }
}

// @0x140c995b0
// memcpy_s (the CRT's _VALIDATE_RETURN_ERRCODE form, per-TU static __inline copy).
#pragma function(memset, memcpy)
static __inline errno_t ms2_memcpy_s_copy1(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy1)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy1;
#pragma intrinsic(memset, memcpy)
// Look-alike CAtlMap glue told apart by exe callers (fx24): FindNextNode 0x140c94f60 <- m_targets' GetNext 0x140c95690;
// GetNode 0x140c95a00 <- the TraceContext map's Lookup 0x140c965c0 / SetAt 0x140c98870.
// MS2-PIN: ?FindNextNode@?$CAtlMap@KV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@K@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140c94f60
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VTraceContext@QuestNavigation@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VTraceContext@QuestNavigation@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x140c95a00
