// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService container COMDAT tail, the
// `_Myend` neighbourhood slice between _tail4.cpp and _tail.cpp (accessor glue of
// the std/efd map, set and vector families). Queue name
// unit_141145cb0. Like cubemapinformationservice_tail.cpp (unit_141148d70), _tail2/3/4.cpp the range holds
// no original (non-COMDAT) function: it is part of the mangled-name sorted COMDAT tail of
// client\ms2\cubemapinformationservice.cpp (0x1410d5bc0-0x14115b040). The driver is _tail3.cpp's, which
// instantiates every family; tplpin pairs the copies that fall in this slice.
// MS2-UNIT: unit_141145cb0
// MS2-RANGE: 0x141145cb0-0x141148d70 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@efd@@@std@@SA_KAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@efd@@U?$integral_constant@_N$00@2@@Z 0x1411487c0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include <NiTransform.h>
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

typedef std::map<unsigned int, MS2SvrPtr<CUGCMapSetItemInfo> > Unk_CMISMapSetItem;
typedef efd::vector<NiTransform> Unk_CMISXformVec2;
typedef efd::vector<Cube*> Unk_CMISCubePtrVec;
// actionkeyobject.cpp's owner-id table: the CU constructs one first (_Construct/_Buyheadnode sit in this slice, the rest
// of the family in actionkeyobject's range)
typedef std::map<__int64, Unk_PayloadPtr<CubeOwner> > Unk_CMISOwnerById;

// operator[] with a temporary key: the exe's try_emplace(key_type&&) copies
template <class M> void Unk_CMISDriveIndexRv3(M& m)
{
    M tmp;
    tmp[typename M::key_type()];
    (void)m;
}
// the map ops without the const-key operator[] (the exe only indexes these with a temporary)
template <class M> void Unk_CMISDriveMapRv3(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveIndexRv3(m);
    Unk_CMISDriveMapOps(m, k);
}


// unit_14112ab60's stand-in key of its 23rd map family (its iterator-- 0x14112bff0 calls this slice's _Max 0x141148330)
template <int N> struct Unk_DkKey { int v[N + 1]; bool operator<(const Unk_DkKey& o) const { return v[0] < o.v[0]; } };

// mt7: the tree helpers of two families this slice holds the only copy of: the long-key cube map's _Lrotate
// (0x141147c80, called by 0x1410ef500 / 0x14113f850) and the Unk_DkKey<23> map's _Max (0x141148330)
void Unk_CMISDriveTreeHelpersTail5()
{
    std::_Tree_val<std::_Tree_simple_types<std::pair<const long, MS2Ptr<Cube> > > > t;
    t._Lrotate(t._Myhead);
    (void)std::_Tree_val<std::_Tree_simple_types<std::pair<const Unk_DkKey<23>, int> > >::_Max(nullptr);
}


void Unk_CMISDriveTail5()
{
    int nKey = 0;
    unsigned int uKey = 0;
    unsigned __int64 ullKey = 0;
    egf::EntityID id;
    { Unk_CMISMapIntUInt m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapMark m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapNear m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCell m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapEntity m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapDoll m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapSales m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapSetEffect m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapHead m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapBuckets m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapCubeGroups m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISStdMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapColumns m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntVec m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntityId m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapKind m; Unk_CMISDriveMapRv3(m, nKey); }
    { Unk_CMISMapUIntInt m; Unk_CMISDriveMapRv3(m, uKey); }
    { Unk_CMISMapSetItem m; Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapDword m; unsigned long dwKey = uKey, dwVal; (void)m.find(dwKey, dwVal); (void)m.end(); (void)m.lower_bound(dwKey); }
    { Unk_CMISMapUid m; Unk_CMISDriveMapOps(m, ullKey); (void)m.equal_range(ullKey); m.erase(ullKey); }
    { Unk_CMISMapBucket m; Unk_CMISDriveMap(m, uKey); }
    { Unk_CMISMapSaleState m; std::pair<int, int> k(0, 0); Unk_CMISDriveMapRv3(m, k); (void)m.equal_range(k); m.erase(k); }
    { Unk_CMISMapName m; Unk_CMISDriveMapKey(m, CStringA()); }
    { Unk_CMISMapEntityVal m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapProp m; Unk_CMISDriveMapOps(m, id); }                                           // no operator[]: Unk_CMISPropPtr has no default ctor in the exe
    { Unk_CMISMapEntityCube m; Unk_CMISDriveMap(m, id); }
    { Unk_CMISMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISStdMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISMapKindInt m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapKindByte m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv3(m); }
    { Unk_CMISMapIntInt m; Unk_CMISDriveMapOps(m, nKey); }
    { Unk_CubeOwners m; }                                                                       // ugcmapdata's owner table
    { Unk_CMISIntSet s; Unk_CMISDriveSet(s, nKey); { int n = nKey; s.insert(std::move(n)); } (void)s.equal_range(nKey); s.erase(nKey); (void)s.key_comp(); }
    { Unk_CMISPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISAutoSet s; MS2Ptr<AutomaticCreateCubeInfo> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISFuncCubeSet s; MS2Ptr<CFunctionCubeObject> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISEntityIdSet s; Unk_CMISDriveSet(s, id); }
    { Unk_CMISIntVec v; Unk_CMISDriveVector(v, nKey); }
    { Unk_CMISStdEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); }
    { Unk_CMISEntityIdVec v; Unk_CMISDriveVector(v, id); Unk_CMISEntityIdVec w; v = w; }
    { Unk_CMISEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); Unk_CMISEntVec w; v = w; }
    { Unk_CMISElem52Vec v; Unk_CMISDriveVector(v, Unk_CMISElem52()); }
    { Unk_CMISKindVec v; Unk_CMISDriveVector(v, Unk_CMISKindC_None); }
    { Unk_CMISStdIntSet s; { int n = nKey; s.insert(std::move(n)); } }
    { Unk_CMISPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { std::vector<int> v; v.push_back(nKey); { int n = nKey; v.push_back(std::move(n)); } }
    { Unk_CMISMapBucket a, b; a = b; }
    { Unk_CMISXformVec2 v; NiTransform x; v.push_back(x); v.push_back(NiTransform()); }
    { Unk_CMISCubePtrVec v; Cube* p = 0; v.push_back(p); v.push_back(static_cast<Cube*>(0)); }
    // copy assignments (the exe's _Copy_alloc / _Buynode0 of these families)
    { Unk_CMISMapUid a, b; a = b; }
    { Unk_CMISIntSet a, b; a = b; }
    { Unk_CMISStdIntSet a, b; a = b; }
    { Unk_CMISFuncCubeSet a, b; a = b; }
    { Unk_CMISOwnerById m; }
    { MS2Ptr<UIHouseMarkEntity> p; }
    { efd::utf8string s; (void)s.find_last_of("/", 0); }
    { std::string s; s.append("x"); }
}
