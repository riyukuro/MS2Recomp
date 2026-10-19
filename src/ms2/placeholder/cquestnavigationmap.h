// cquestnavigationmap.h - PLACEHOLDER for CQuestNavigationMap (RTTI .?AVCQuestNavigationMap@@, 0xe0 bytes) and the
// QuestNavigation trace records (RTTI .?AVTraceContext@QuestNavigation@@ / .?AVTraceResult@QuestNavigation@@, 0x50 each).
// NOT an original header. Bodies in client/ms2/questnavigation.cpp (?\questnavigation.cpp).
// Bases: TSingleton<CQuestNavigationMap> at +0x0. CGameApp::InitInstance (?\ms2.cpp) creates it.
#pragma once

#include <set>
#include <atlcoll.h>
#include <efd/Point3.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/commonfiles/blackmarketitemoption.h"

class CConditionCommonData;
class CQuest;
template <class T> class Unk_PayloadPtr;

namespace QuestNavigation {

// The maps and the npc / interact object / liftable ids a traced quest leads to on one map.
class TraceContext : public CPtred
{
public:
    TraceContext();                                         // 0x140c90340
    virtual ~TraceContext();                                // 0x140c903c0
    int m_18;                                               // +0x18 map id
    std::set<unsigned> m_20;                                // +0x20 npc ids
    std::set<int> m_30;                                     // +0x30 interact object ids
    std::set<unsigned> m_40;                                // +0x40 liftable ids
};
MS2_CHECK_SIZE(TraceContext, 0x50);

class TraceResult : public CPtred
{
public:
    TraceResult();                                          // 0x140c90420
    void Clear();                                           // 0x140c904b0
    int m_18;                                               // +0x18 quest id (not reset by Clear)
    int m_1c;                                               // +0x1c
    efd::Point3 m_20;                                       // +0x20
    efd::Point3 m_2c;                                       // +0x2c
    CStringW m_38;                                          // +0x38
    MS2Ptr<TraceContext> m_40;                              // +0x40
};
MS2_CHECK_SIZE(TraceResult, 0x50);

} // namespace QuestNavigation

// TPtr<T> to a boxed value (TPtredDummy<T>), the same smart pointer as Unk_BmBoxPtr; a separate name so that the
// m_98 map's COMDATs sort like the exe's (bodies in questnavigation.cpp).
template <class T>
class MS2BoxPtr
{
public:
    MS2BoxPtr();
    MS2BoxPtr(int);
    MS2BoxPtr(const Unk_BmNewTag&);
    MS2BoxPtr(const MS2BoxPtr& o);
    MS2BoxPtr(MS2BoxPtr&& o);
    ~MS2BoxPtr();
    MS2BoxPtr& operator=(const MS2BoxPtr& o);
    T* operator->() const;

private:
    void AddRef() const;
    void Make();
    void Release();
    static TPtredDummy<T>* Allocate(void*);
    static T* Value(TPtredDummy<T>* p);
    static TPtredDummy<T>* Owner(T* p);
    static void Ref(CPtred* p);
    static T* Create(void*);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    void* m_00;
    T* m_p;
};

class CQuestNavigationMap : public TSingleton<CQuestNavigationMap>
{
public:
    // The maps (key) holding a quest condition's targets, per kind (0 npc, 1 interact object, 2 liftable).
    class TraceTarget : public CPtred
    {
    public:
        TraceTarget() {}                                    // 0x140c94340 (inline)
        int HasTargets();                                   // 0x140c93430
        void AddMaps(int nKind, unsigned nId, ATL::CAtlArray<unsigned>& maps);  // 0x140c93490
        ATL::CAtlMap<unsigned, Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > > m_targets[3];   // +0x18 map -> ids
    };
    typedef ATL::CAtlMap<int, MS2Ptr<TraceTarget> > TargetTable;    // condition index -> targets

    CQuestNavigationMap();                                  // 0x140c90840
    virtual ~CQuestNavigationMap();                         // 0x140c90920
    void FUN_140c909a0();                                   // BuildMapPaths, then m_8 = 1
    int FUN_140c9b8d0() const { return m_8; }               // 0x140c9b8d0 paths built (inline COMDAT, questnavigator.cpp)
    int BuildMapPaths();                                    // 0x140c909d0 all-pairs shortest portal paths
    int FindMapPath(int nFrom, int nTo, ATL::CAtlArray<unsigned>& path);    // 0x140c91180
    int FUN_140c912d0(int nFrom, int nTo);                  // the next map on the path (0 = none)
    void CollectMapPath(short nFrom, short nTo, ATL::CAtlArray<unsigned>& path, int& nDepth);   // 0x140c91370
    int NearestMap(const ATL::CAtlArray<unsigned>& maps);   // 0x140c915a0
    int InitTraceTable();                                   // 0x140c91690
    int FindConditionMaps(MS2Ptr<CConditionCommonData> spCond, ATL::CAtlArray<unsigned>& maps);   // 0x140c92510
    int ClassifyCondition(int nType);                       // 0x140c92620 (0 npc, 1 interact, 2 liftable, 3 none)
    MS2Ptr<QuestNavigation::TraceContext> TraceQuest(int nQuestId);         // 0x140c92730
    // Adds the targets of the quest's open conditions on map nMapId to the context.
    void FUN_140c92fc0(Unk_PayloadPtr<CQuest> spQuest, int nMapId, QuestNavigation::TraceContext& context);

private:
    MS2_LAYOUT_FRIEND;
    int m_8;                                                // +0x08 paths built
    ATL::CAtlArray<unsigned> m_10;                          // +0x10 index -> map id
    ATL::CAtlMap<unsigned, short> m_30;                     // +0x30 map id -> index
    ATL::CAtlArray<ATL::CAtlArray<short> > m_78;            // +0x78 [from][to] -> intermediate index
    ATL::CAtlMap<unsigned, MS2BoxPtr<TargetTable> > m_98;   // +0x98 quest id -> condition targets
};
MS2_CHECK_OFFSET(CQuestNavigationMap, m_10, 0x10);
MS2_CHECK_OFFSET(CQuestNavigationMap, m_30, 0x30);
MS2_CHECK_OFFSET(CQuestNavigationMap, m_78, 0x78);
MS2_CHECK_OFFSET(CQuestNavigationMap, m_98, 0x98);
MS2_CHECK_SIZE(CQuestNavigationMap, 0xe0);
