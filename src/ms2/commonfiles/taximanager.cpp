// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTaxiManager: the fare between two taxi stations, found by
// a breadth first search over the stations' portal links and cached per station pair, plus the std::map / std::queue
// glue it instantiates.
// MS2-UNIT: ?\taximanager.cpp
// MS2-RANGE: 0x14085f650-0x1408665a0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAU?$pair@II@std@@AEAH$0A@@?$pair@U?$pair@II@std@@H@std@@QEAA@AEAU?$pair@II@1@AEAH@Z 0x14085fdf0 ; unique
// MS2-PIN: ??$?0U?$pair@II@std@@H$0A@@?$pair@$$CBU?$pair@II@std@@H@std@@QEAA@$$QEAU?$pair@U?$pair@II@std@@H@1@@Z 0x14085ffd0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@1@@Z 0x1408600e0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@II@std@@H@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@II@std@@HU?$less@U?$pair@II@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@II@std@@H@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@II@std@@H@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@II@std@@H@1@@Z 0x140860100 ; unique
// MS2-PIN: ??$_Kfn@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@?$_Tmap_traits@IV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@3@$0A@@std@@SAAEBIAEBU?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@1@@Z 0x1408613a0 ; unique
// MS2-PIN: ??$_Kfn@$$CBU?$pair@II@std@@H@?$_Tmap_traits@U?$pair@II@std@@HU?$less@U?$pair@II@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@II@std@@H@std@@@2@$0A@@std@@SAAEBU?$pair@II@1@AEBU?$pair@$$CBU?$pair@II@std@@H@1@@Z 0x1408613b0 ; unique
// MS2-PIN: ??$forward@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@YA$$QEAV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@AEAV1@@Z 0x140861ba0 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140861bb0 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@H@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x140861bc0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x140864240 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140864250 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@II@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@II@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@H@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@II@std@@@2@XZ 0x140864260 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@II@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@II@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@II@std@@@2@XZ 0x140864270 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@PEAX@std@@@2@XZ 0x140864280 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@2@$00@std@@QEAAAEAV?$_Deque_val@U?$_Deque_simple_types@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@2@XZ 0x140864360 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@2@$00@std@@QEBAAEBV?$_Deque_val@U?$_Deque_simple_types@V?$Unk_TaxiPtr@V_CTaxiPathInfo@@@@@std@@@2@XZ 0x140864370 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1_CTaxiPathInfo@@UEAA@XZ 0x140862570
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\taximanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <deque>
#include <map>
#include <new>
#include <queue>
#include <utility>

#include "ms2/placeholder/ctaximanager.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "hook/ms2hook.h"

// 16-byte intrusive smart pointer of a CPtred-derived T (field 0 unused, field 1 the pointer); has a move ctor.
template <class T>
class Unk_TaxiPtr
{
public:
    Unk_TaxiPtr();
    Unk_TaxiPtr(int);                                       // m_p = NULL
    Unk_TaxiPtr(T* p);                                      // m_p = p; AddRef
    Unk_TaxiPtr(const Unk_TaxiPtr& o);                      // copy + AddRef
    Unk_TaxiPtr(Unk_TaxiPtr&& o);                           // steal
    ~Unk_TaxiPtr();
    T* operator->() const;

private:
    void AddRef() const;
    void Release();
    static void Ref(CPtred* p);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    void* m_00;
    T* m_p;
};

template <class T> Unk_TaxiPtr<T>::Unk_TaxiPtr() { m_p = 0; }
template <class T> Unk_TaxiPtr<T>::Unk_TaxiPtr(int) { m_p = 0; }
template <class T> Unk_TaxiPtr<T>::Unk_TaxiPtr(T* p) { m_p = p; AddRef(); }
template <class T> Unk_TaxiPtr<T>::Unk_TaxiPtr(const Unk_TaxiPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_TaxiPtr<T>::Unk_TaxiPtr(Unk_TaxiPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_TaxiPtr<T>::~Unk_TaxiPtr() { Release(); }
template <class T> T* Unk_TaxiPtr<T>::operator->() const { return m_p; }
template <class T> void Unk_TaxiPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_TaxiPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> void Unk_TaxiPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_TaxiPtr<T>::AddRefImpl(void*) const { Ref(m_p); }
template <class T> void Unk_TaxiPtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); }
}

// One station of the search (0x38, RTTI _CTaxiPathInfo).
class _CTaxiPathInfo : public CPtred
{
public:
    _CTaxiPathInfo(int nStation, int nHops);                // 0x1408622a0

    int m_nStation;                                         // +0x18
    Unk_TaxiPtr<_CTaxiPathInfo> m_spPrev;                   // +0x20
    int m_nHops;                                            // +0x30
};
MS2_CHECK_SIZE(_CTaxiPathInfo, 0x38);

// The fare table (singleton of 0x1401c0db0).
struct Unk_TaxiFare
{
    int FUN_1406764e0(int nHops, short sOption);
    int FUN_1406766a0(short sOption);
};
Unk_TaxiFare* FUN_1401c0db0();
CFieldMetaTable* FUN_140700390();

typedef Unk_TaxiPtr<_CTaxiPathInfo> Unk_TaxiNodePtr;
typedef std::pair<unsigned int, unsigned int> Unk_TaxiKey;

_CTaxiPathInfo::_CTaxiPathInfo(int nStation, int nHops) : m_nStation(nStation), m_spPrev(0), m_nHops(nHops) {}

// @0x14085f650
CTaxiManager::CTaxiManager() {}

// @0x14085f6a0
CTaxiManager::~CTaxiManager() {}

// @0x14085f6e0
bool CTaxiManager::FUN_14085f6e0(unsigned int nField)
{
    return FUN_140700390()->FUN_1406fbc10(nField) == 1;
}
MS2_REPLACE_METHOD(0x14085f6e0, CTaxiManager, FUN_14085f6e0, 63, 0xE2BA897A);

// @0x14085f730
bool CTaxiManager::FUN_14085f730(unsigned int nField)
{
    return FUN_140700390()->FUN_1406fbc50(nField) == 1;
}
MS2_REPLACE_METHOD(0x14085f730, CTaxiManager, FUN_14085f730, 63, 0x613ACC7A);

// @0x14085fcb0
static Unk_TaxiKey FUN_14085fcb0(unsigned int nA, unsigned int nB)
{
    if (nA > nB)
        return std::make_pair(nB, nA);
    return std::make_pair(nA, nB);
}
MS2_REPLACE(0x14085fcb0, FUN_14085fcb0, 85, 0xD0072D33);

// @0x14085f780
long long CTaxiManager::FUN_14085f780(int nFrom, int nTo, short sOption)
{
    if (nFrom == nTo)
        return 0;
    Unk_TaxiKey kKey = FUN_14085fcb0(nFrom, nTo);
    std::map<Unk_TaxiKey, int>::const_iterator itCached = m_mapRouteLength.find(kKey);
    if (itCached != m_mapRouteLength.end())
        return FUN_1401c0db0()->FUN_1406764e0(itCached->second, sOption);

    int nBest = -1;
    std::queue<Unk_TaxiNodePtr> aOpen;
    std::map<unsigned int, Unk_TaxiNodePtr> mapSeen;
    aOpen.push(new _CTaxiPathInfo(nFrom, 0));
    while (aOpen.size() > 0)
    {
        Unk_TaxiNodePtr spCur = aOpen.front();
        aOpen.pop();
        int nHops = spCur->m_nHops + 1;
        if (nHops >= nBest && nBest >= 0)
            continue;
        Unk_FieldIdListPtr spLinks = FUN_140700390()->FUN_1406fbca0(spCur->m_nStation);
        if (spLinks == 0)
            continue;
        POSITION pos = spLinks->GetHeadPosition();
        while (pos != 0)
        {
            unsigned int nNext = spLinks->GetNext(pos);
            if (nNext == 0 || spCur->m_nStation == nNext)
                continue;
            if (nNext == nTo && (nBest > nHops || nBest == -1))
            {
                nBest = nHops;
                continue;
            }
            std::map<unsigned int, Unk_TaxiNodePtr>::iterator itSeen = mapSeen.find(nNext);
            if (itSeen == mapSeen.end())
            {
                _CTaxiPathInfo* pNew = new _CTaxiPathInfo(nNext, nHops);
                aOpen.push(pNew);
                mapSeen.insert(std::make_pair(nNext, pNew));
            }
            else if (itSeen->second->m_nHops > nHops)
            {
                itSeen->second->m_nHops = nHops;
                aOpen.push(itSeen->second);
            }
        }
    }
    m_mapRouteLength.insert(std::make_pair(kKey, nBest));
    return FUN_1401c0db0()->FUN_1406764e0(nBest, sOption);
}
MS2_REPLACE_METHOD(0x14085f780, CTaxiManager, FUN_14085f780, 1268, 0x27ADECB6);

// @0x14085fc80
long long CTaxiManager::FUN_14085fc80(short sOption)
{
    return FUN_1401c0db0()->FUN_1406766a0(sOption);
}
MS2_REPLACE_METHOD(0x14085fc80, CTaxiManager, FUN_14085fc80, 39, 0x03353DB4);
