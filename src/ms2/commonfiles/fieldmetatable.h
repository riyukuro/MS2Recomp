// fieldmetatable.h - CFieldMetaTable (RTTI name): the Table/FieldMetaData.xml index (which fields an npc/pet/liftable/
// interact object appears in, field portals, taxi stations, spawn-npc guarantees), plus CFieldFeatureChecker and
// CSpawnNpcGuaranteeInfo which share its unit. Header and member names are inferred from use.
//
// Layout: TSingleton<CFieldMetaTable> (vftable only, 8 bytes), CValidData<CFieldMetaTable> at +8, then the
// containers from +0x10; 0x3b0 bytes (operator new size at 0x14149a090).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/mstime.h"

// The wrapper the exe allocates around a value that is shared through a smart pointer: a CPtred base followed by the
// value (TPtredDummy<T>, size 0x18 + sizeof(T)). The smart pointer below points at the value, not at the wrapper.
#include "ms2/placeholder/tptreddummy.h"

struct Unk_FieldNewTag
{
    explicit Unk_FieldNewTag(int);                          // 0x1401b7b90 (returns its this, no code)
};

CPtred* FUN_1401ba820(CPtred* p);                           // marks a freshly allocated box (sets the count to 1)

// 16-byte intrusive smart pointer of a boxed value (field 0 unused, field 1 the value). Same shape as the plain
// MS2Ptr<T> but the CPtred header sits 0x18 bytes before the pointee. Members are defined out of the class (below) so
// that they stay out-of-line COMDATs like the exe's.
template <class T>
class Unk_FieldPtr
{
public:
    Unk_FieldPtr();                                         // m_p = NULL (0x140443920 for T = Unk_FieldIdList)
    Unk_FieldPtr(int);                                      // m_p = NULL (0x140443900)
    Unk_FieldPtr(const Unk_FieldNewTag&);                   // fresh box (0x1404438d0)
    Unk_FieldPtr(const Unk_FieldPtr& o);                    // copy + AddRef (0x1406feb00)
    Unk_FieldPtr(Unk_FieldPtr& o);                          // steal from a non-const lvalue (0x1406fead0)
    ~Unk_FieldPtr();                                        // 0x140446410
    Unk_FieldPtr& operator=(const Unk_FieldPtr& o);
    Unk_FieldPtr& operator=(const Unk_FieldNewTag&);        // 0x1406ffb10
    T* get() const;                                         // 0x140448220
    T* operator->() const;                                  // same bytes as get() (0x1402a5ca0 for the Dict box)
    bool operator!() const;                                 // m_p == NULL (0x1402a5b10 for the Dict box)
    bool operator==(T* p) const;

private:
    void AddRef() const;                                    // 0x14045b2f0
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

template <class T> Unk_FieldPtr<T>::Unk_FieldPtr() { m_p = 0; }
template <class T> Unk_FieldPtr<T>::Unk_FieldPtr(int) { m_p = 0; }
template <class T> Unk_FieldPtr<T>::Unk_FieldPtr(const Unk_FieldNewTag&) { m_p = 0; Make(); }
template <class T> Unk_FieldPtr<T>::Unk_FieldPtr(const Unk_FieldPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_FieldPtr<T>::Unk_FieldPtr(Unk_FieldPtr& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_FieldPtr<T>::~Unk_FieldPtr() { Release(); }
template <class T> Unk_FieldPtr<T>& Unk_FieldPtr<T>::operator=(const Unk_FieldPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_FieldPtr<T>& Unk_FieldPtr<T>::operator=(const Unk_FieldNewTag&) { Make(); return *this; }
template <class T> T* Unk_FieldPtr<T>::get() const { return m_p; }
template <class T> T* Unk_FieldPtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_FieldPtr<T>::operator!() const { return m_p == 0 ? 1 : 0; }
template <class T> bool Unk_FieldPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_FieldPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_FieldPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_FieldPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* Unk_FieldPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* Unk_FieldPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* Unk_FieldPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void Unk_FieldPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> T* Unk_FieldPtr<T>::Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
template <class T> void Unk_FieldPtr<T>::AddRefImpl(void*) const { Ref(Owner(m_p)); }
template <class T> void Unk_FieldPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

typedef ATL::CAtlList<unsigned int> Unk_FieldIdList;
typedef Unk_FieldPtr<Unk_FieldIdList> Unk_FieldIdListPtr;
typedef ATL::CAtlMap<unsigned int, Unk_FieldIdListPtr> Unk_FieldIdListMap;

// An absolute [start, end] server-time window (16 bytes); helpers live elsewhere in the exe.
struct Unk_FieldTimeSpan
{
    Unk_FieldTimeSpan();                                    // 0x1402a54a0
    // 0x1404437b0 (gameeventvalue.cpp: the dungeon open period map value)
    Unk_FieldTimeSpan(__int64 nStart, __int64 nEnd) : m_nStart(nStart), m_nEnd(nEnd) {}
    void Set(__int64 nStart, __int64 nEnd);                 // 0x1402a6bd0
    bool Contains(__int64 nTime) const;                     // 0x1402a6f60
    __int64 m_nStart;
    __int64 m_nEnd;
};
MS2_CHECK_SIZE(Unk_FieldTimeSpan, 0x10);

// <taxiStation field= IsHomePrivilege=/>
struct Unk_FieldTaxi
{
    unsigned int m_nField;
    unsigned int m_nHomePrivilege;
};
MS2_CHECK_SIZE(Unk_FieldTaxi, 0x8);

// Feature-name gate for fields. Base is a bare CPtred (the exe's CPtred ctor 0x140159740), CValidData at +0x18.
class CFieldFeatureChecker : public CPtred, public CValidData<CFieldFeatureChecker>
{
public:
    CFieldFeatureChecker();                                 // 0x1406f96f0

    // The field's configured feature name (looked up by field id in the global name table) is enabled.
    static int IsEnabled(int nFieldId);                    // 0x1406f9820
    static void BuildNameTable();                           // 0x1406f9750
    static void CheckInit();                                // 0x1406ffb80
    static void SetInit(bool b);                            // 0x140703180

    static bool s_bInit;                                    // 0x143ab09bc
};
MS2_CHECK_SIZE(CFieldFeatureChecker, 0x20);

// One <fieldPortal> spawn guarantee row (0x30 bytes, vftable 0x142d7f1xx).
class CSpawnNpcGuaranteeInfo : public CPtred
{
public:
    CSpawnNpcGuaranteeInfo();                               // 0x1406ff040

    int m_nFieldId;                                         // +0x18
    int m_nNpcId;                                           // +0x1c
    CMsTime m_time;                                         // +0x20
};
MS2_CHECK_SIZE(CSpawnNpcGuaranteeInfo, 0x30);
MS2_CHECK_OFFSET(CSpawnNpcGuaranteeInfo, m_time, 0x20);

class CFieldMetaTable : public TSingleton<CFieldMetaTable>, public CValidData<CFieldMetaTable>
{
public:
    typedef std::pair<unsigned int, unsigned int> NpcFieldKey;

    CFieldMetaTable();                                      // 0x1406f9890
    virtual ~CFieldMetaTable();                             // 0x1406f9c20

    static void CheckInit();                                // 0x1406ffc30
    static void SetInit(bool b);                            // 0x140703190
    static bool s_bInit;                                    // 0x143ab0a10

    void FUN_1406fb060(unsigned int nId, ATL::CAtlArray<unsigned int>& out);        // pet fields
    void FUN_1406fb120(unsigned int nId, ATL::CAtlArray<unsigned int>& out);        // liftable fields
    void FUN_1406fb1e0(int nId, ATL::CAtlArray<unsigned int>& out);                 // interact object fields
    void FUN_1406fb2a0(unsigned int nId, ATL::CAtlArray<unsigned int>& out);
    void FUN_1406fb3a0(unsigned int nId, Unk_FieldIdList& out);
    void FUN_1406fb520(unsigned int nId, Unk_FieldIdList& out);
    void FUN_1406fb610(unsigned int nFieldId, Unk_FieldIdList& out);
    int FUN_1406fb700(unsigned int nId, unsigned int* pOut);
    void FUN_1406fb810(unsigned int nFieldId, Unk_FieldIdList& out);
    void FUN_1406fb900(unsigned int nFieldId, unsigned int nGroupId, Unk_FieldIdList& out);
    int FUN_1406fba40(unsigned int nId, int nField);
    bool FUN_1406fbb50(unsigned int nNpc, unsigned int nField);
    int FUN_1406fbc10(unsigned int nField);
    unsigned int FUN_1406fbc50(unsigned int nField);
    Unk_FieldIdListPtr FUN_1406fbca0(unsigned int nField);
    void FUN_1406fbdf0(Unk_FieldIdListPtr pFrom, Unk_FieldIdListPtr pTo);
    int FUN_1406fc110(unsigned int nKey, unsigned int* pValue);
    int FUN_1406fc160(unsigned int nKey, Unk_FieldIdListPtr& pList);
    void FUN_1406fc1b0(std::set<unsigned int>& seen, unsigned int nField);
    void FUN_1406fc2f0(unsigned int nField, Unk_FieldIdList& out);
    Unk_FieldIdListPtr FUN_1406fc3c0(unsigned int nField);
    Unk_FieldIdListMap& FUN_1406fc450();
    Unk_FieldIdListMap& FUN_140c955c0() { return m_portalTargets; }   // inline (COMDAT 0x140c955c0, questnavigation.cpp)
    Unk_FieldIdListMap& FUN_141b69360() { return m_fieldNpcs; }       // inline (COMDAT 0x141b69360, uiworldmapdialog.cpp)
    void FUN_1406fc480(int nFieldId, int nNpcId, const CMsTime& t);
    void FUN_1406fc590(int nFieldId);
    int FUN_1406fc620(int nNpcId, CMsTime& out);
    int FUN_1406fc6d0(int nNpcId, ATL::CAtlArray<CMsTime>& out);
    bool FUN_1406fc7b0(unsigned int nField, unsigned int nId);
    int FUN_1406fc870(unsigned nFieldId);
    bool FUN_1406fc8a0(CString str, __int64* pTime);
    void LoadFieldMetaData();                                   // Load

private:
    MS2_LAYOUT_FRIEND;
    Unk_FieldIdListMap m_npcFields;                         // +0x10 npc id -> field ids
    Unk_FieldIdListMap m_fieldNpcs;                         // +0x58 field id -> npc ids
    ATL::CAtlMap<unsigned int, Unk_FieldTaxi> m_taxi;       // +0xa0
    Unk_FieldIdListMap m_portalTargets;                     // +0xe8
    Unk_FieldIdListMap m_portalTargets2;                    // +0x130
    Unk_FieldIdListMap m_portalType8;                       // +0x178
    Unk_FieldIdListMap m_indoorPortals;                     // +0x1c0
    Unk_FieldIdListMap m_indoorClosure;                     // +0x208
    ATL::CAtlMap<unsigned int, unsigned int> m_reverse;     // +0x250
    ATL::CRBMap<int, MS2Ptr<CSpawnNpcGuaranteeInfo> > m_guarantee;   // +0x298
    ATL::CAtlMap<int, Unk_FieldIdListPtr> m_interact;       // +0x2c8 interact object id (signed) -> field ids
    Unk_FieldIdListMap m_pet;                               // +0x310
    Unk_FieldIdListMap m_liftable;                          // +0x358
    std::map<NpcFieldKey, Unk_FieldTimeSpan> m_activeTimes; // +0x3a0
};
MS2_CHECK_SIZE(CFieldMetaTable, 0x3b0);
