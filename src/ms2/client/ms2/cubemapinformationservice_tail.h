// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Shared by the CubeMapInformationService container COMDAT
// tail slices (cubemapinformationservice_tail.cpp = unit_141148d70, cubemapinformationservice_tail2.cpp =
// unit_1410e9350): the record classes held by MS2Ptr, the unit-local value types, the container typedefs of the
// service's member trees and local containers, and the driver templates that instantiate the container operations.
// Not an original header (the exe instantiates these inside client\ms2\cubemapinformationservice.cpp).
#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>
#include <atlstr.h>
#include <efd/StdContainers.h>
#include <efd/utf8string.h>
#include <egf/EntityID.h>
#include <egf/Entity.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cube.h"
#include "ms2/client/ms2/uihousemark.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"

// ---- record classes held by MS2Ptr (RTTI names; only the CPtred base matters here) --------------------------------------
class SalesInfo : public CPtred                         // house sale marker record (0x38, ctor 0x1411232e0)
{
public:
    SalesInfo();
    virtual ~SalesInfo() = default;                     // 0x141125fe0 (no vptr store)
    int m_nA;                                           // +0x18 (not set by the ctor)
    efd::Point3 m_pos;                                  // +0x1c
    CStringW m_str;                                     // +0x28
    void* m_pTail;                                      // +0x30 (not set by the ctor)
};
MS2_CHECK_SIZE(SalesInfo, 0x38);
class SetItemEffectInfo : public CPtred                 // 0x28, ctor 0x1411233c0
{
public:
    SetItemEffectInfo();
    virtual ~SetItemEffectInfo() = default;
    int m_nEffect;                                      // +0x18
    CString m_strName;                                  // +0x20
};
class AutomaticCreateCubeInfo : public CPtred           // ctor 0x141122e70 (0x50)
{
public:
    AutomaticCreateCubeInfo();
    virtual ~AutomaticCreateCubeInfo() = default;       // 0x141125e20 (no vptr store)
    int m_nId;                                          // +0x18
    Unk_Int3 m_cell;                                    // +0x1c
    float m_fAngle;                                     // +0x28
    int m_nFlag;                                        // +0x2c
    Unk_GuildArray m_arr;                               // +0x30
};
MS2_CHECK_SIZE(AutomaticCreateCubeInfo, 0x50);
class SaleStateData : public CPtred                     // sale state of a house (0x28, ctor 0x141123290)
{
public:
    SaleStateData();
    virtual ~SaleStateData() = default;                 // 0x141125fc0 (no vptr store)
    int m_nState;                                       // +0x18
    void* m_p;                                          // +0x20
};
MS2_CHECK_SIZE(SaleStateData, 0x28);
class Unk_CMISUidRecord : public CPtred                 // value of a 64-bit-keyed table (pair 0x18, dtor ICF'd with the 16-byte pointers)
{
public:
    virtual ~Unk_CMISUidRecord();
};
class UICubeUGCHead : public CPtred                     // UGC cube head HUD (0x90, ctor 0x141906490)
{
public:
    virtual ~UICubeUGCHead();
};

// ---- unit-local value types (names invented) -------------------------------------------------------------------------
enum Unk_CMISKindA { Unk_CMISKindA_None };             // key of the 0x14112cb40 comparator family
enum Unk_CMISKindB { Unk_CMISKindB_None };             // key of the 0x14112cb80 comparator family
enum Unk_CMISKindC { Unk_CMISKindC_None };             // element of the std::vector whose allocate sorts after SmartPointer's (exe 0x14114d980)

// mark record of a cube group: poll timer and the mark entities (node value of f288)
struct Unk_CMISMarkRec
{
    Timer m_timer;
    efd::vector<egf::EntityPtr> m_marks;                       // the dtor (0x141125e70) calls ~efd::vector<SmartPointer<Entity>> 0x141125d00
};
MS2_CHECK_SIZE(Unk_CMISMarkRec, 0x50);

// per-cell record with a UTF-8 name (node value of f2b8)
struct Unk_CMISCell
{
    efd::utf8string m_name;
    int m_a, m_b, m_c, m_d, m_e, m_f;
};
MS2_CHECK_SIZE(Unk_CMISCell, 0x38);

// cube timer record (node value of f1f8)
struct Unk_CMISCubeTimer
{
    Unk_CMISCubeTimer();                                        // 0x141123160 (out of line: Timer(), id(), reset, flags, id = none)
    Timer m_timer;
    bool m_bFlagA, m_bFlagB;
    egf::EntityID m_id;
};
MS2_CHECK_SIZE(Unk_CMISCubeTimer, 0x48);

// 8-byte smart pointer to a PhysX prop object (node value of f58; its dtor wraps ~Unk_InteractPropPtr)
class Unk_CMISPropPtr
{
public:
    Unk_CMISPropPtr(int nNull = 0);                             // = Unk_InteractPropPtr(int) 0x140ae1340
    Unk_CMISPropPtr(const Unk_CMISPropPtr&);
    Unk_CMISPropPtr& operator=(const Unk_CMISPropPtr&);
    ~Unk_CMISPropPtr();
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_CMISPropPtr, 8);

// 0x34-byte element of an efd::vector. An efd::MemObject: CustomAllocator<T>::construct's placement new (0x1411503d0)
// calls MemObject::operator new(size_t, void*) (0x140993c70) instead of the inline global one.
struct Unk_CMISElem52 : public efd::MemObject
{
    int m_v[13];
};
MS2_CHECK_SIZE(Unk_CMISElem52, 0x34);

// ---- the containers ----------------------------------------------------------------------------------------------------
typedef efd::map<int, int> Unk_CMISMapIntInt;
typedef efd::map<int, unsigned int> Unk_CMISMapIntUInt;                                    // f338
typedef efd::map<int, Unk_CMISMarkRec> Unk_CMISMapMark;                                    // f288
typedef std::map<int, Unk_Int3> Unk_CMISMapNear;                                           // nearest cell per group
typedef efd::map<int, Unk_CMISCell> Unk_CMISMapCell;                                       // f2b8
typedef efd::map<int, egf::EntityPtr> Unk_CMISMapEntity;                                   // ff8
typedef efd::map<int, MS2Ptr<FittingDollData> > Unk_CMISMapDoll;                           // f118
typedef std::map<int, MS2Ptr<SalesInfo> > Unk_CMISMapSales;                                // f238
typedef efd::map<int, MS2Ptr<SetItemEffectInfo> > Unk_CMISMapSetEffect;                    // f348
typedef efd::map<int, MS2Ptr<Cube> > Unk_CMISMapCube;                                      // f88 f98 fb8
typedef std::map<int, MS2Ptr<UICubeUGCHead> > Unk_CMISMapHead;                             // f228
typedef std::set<int> Unk_CMISStdIntSet;
typedef std::map<unsigned int, Unk_CMISStdIntSet> Unk_CMISMapBucket;                       // set id -> cube keys
typedef std::map<int, Unk_CMISMapBucket> Unk_CMISMapBuckets;                               // f440
typedef std::map<int, MS2Ptr<Cube> > Unk_CMISStdMapCube;
typedef efd::map<int, Unk_CMISStdMapCube> Unk_CMISMapCubeGroups;                           // fc8
typedef efd::set<int> Unk_CMISIntSet;
typedef efd::map<int, Unk_CMISIntSet> Unk_CMISMapColumns;                                  // fd8
typedef efd::vector<egf::EntityPtr> Unk_CMISEntVec;
typedef efd::map<int, Unk_CMISEntVec> Unk_CMISMapEntVec;                                   // f1e8
typedef efd::map<int, egf::EntityID> Unk_CMISMapEntityId;                                  // f108 f2c8 f2e0
typedef efd::map<int, Unk_CMISCubeTimer> Unk_CMISMapCubeTimer;                             // f1f8
typedef efd::map<int, Unk_CMISKindA> Unk_CMISMapKind;                                      // f298
typedef efd::map<unsigned int, int> Unk_CMISMapUIntInt;
typedef efd::map<unsigned long, unsigned long> Unk_CMISMapDword;   // exe find/lower_bound call the pair<const DWORD,DWORD> iterator
typedef efd::map<unsigned __int64, MS2Ptr<Unk_CMISUidRecord> > Unk_CMISMapUid;
typedef efd::map<std::pair<int, int>, MS2Ptr<SaleStateData> > Unk_CMISMapSaleState;       // fe8
typedef efd::map<CStringA, int> Unk_CMISMapName;                                           // f1a0 f358
typedef efd::map<egf::EntityID, __int64> Unk_CMISMapEntityVal;                             // f48
typedef efd::map<egf::EntityID, Unk_CMISPropPtr> Unk_CMISMapProp;                          // f58
typedef efd::map<egf::EntityID, MS2Ptr<Cube> > Unk_CMISMapEntityCube;                      // f78 fa8
typedef efd::map<Unk_CMISKindA, int> Unk_CMISMapKindCount;                                 // f3c8
typedef std::map<Unk_CMISKindA, int> Unk_CMISStdMapKindCount;                              // local counts
typedef efd::map<Unk_CMISKindB, int> Unk_CMISMapKindInt;                                   // f378
typedef efd::map<Unk_CMISKindB, unsigned char> Unk_CMISMapKindByte;                        // f368
typedef efd::set<std::pair<int, int> > Unk_CMISPairSet;
typedef std::set<std::pair<int, int> > Unk_CMISStdPairSet;                                 // exported columns
typedef efd::set<MS2Ptr<AutomaticCreateCubeInfo> > Unk_CMISAutoSet;                        // automatic cubes
typedef std::set<MS2Ptr<CFunctionCubeObject> > Unk_CMISFuncCubeSet;                        // f498
typedef efd::set<egf::EntityID> Unk_CMISEntityIdSet;                                       // f30 f68
typedef efd::vector<int> Unk_CMISIntVec;
typedef std::vector<egf::EntityPtr> Unk_CMISStdEntVec;
typedef efd::vector<egf::EntityID> Unk_CMISEntityIdVec;
typedef efd::vector<Unk_CMISElem52> Unk_CMISElem52Vec;
typedef std::vector<Unk_CMISKindC> Unk_CMISKindVec;

// ---- drivers: the container operations the CU's code instantiates -----------------------------------------------------
template <class M> void Unk_CMISDriveMapOps(M& m, const typename M::key_type& k)
{
    (void)m.begin();
    (void)m.end();
    (void)m.empty();
    (void)m.max_size();
    (void)m.find(k);
    (void)m.lower_bound(k);
    m.erase(m.begin());
    m.erase(m.begin(), m.end());
    m.clear();
}
template <class M> void Unk_CMISDriveMap(M& m, const typename M::key_type& k)
{
    M tmp;
    tmp[k];
    Unk_CMISDriveMapOps(m, k);
}
template <class M> void Unk_CMISDriveMapKey(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveMap(m, k);
    (void)m.equal_range(k);
    m.erase(k);
}
template <class S> void Unk_CMISDriveSet(S& s, const typename S::key_type& k)
{
    S tmp;
    tmp.insert(k);
    (void)s.begin();
    (void)s.end();
    (void)s.empty();
    (void)s.max_size();
    (void)s.find(k);
    (void)s.lower_bound(k);
    s.erase(s.begin());
    s.erase(s.begin(), s.end());
    s.clear();
}
template <class V> void Unk_CMISDriveVector(V& v, const typename V::value_type& x)
{
    V tmp;
    tmp.push_back(x);
    (void)v.begin();
    (void)v.end();
    (void)v.empty();
    (void)v.capacity();
    v.clear();
}
