// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService container COMDAT tail, the
// `_Get_data` .. `_Myend` slice (accessor glue: _Get_first / _Get_second / _Getal / _Isnil / _Kfn / _Key / _Left /
// _Lmost / _Max / _Min / _Myhead / _Mysize ... of the std/efd map, set and vector families). Queue name
// unit_141142d40. Like cubemapinformationservice_tail.cpp (unit_141148d70), _tail2.cpp and _tail3.cpp the range holds
// no original (non-COMDAT) function: it is part of the mangled-name sorted COMDAT tail of
// client\ms2\cubemapinformationservice.cpp (0x1410d5bc0-0x14115b040). The driver is _tail3.cpp's, which
// instantiates every family; tplpin pairs the copies that fall in this slice.
// MS2-UNIT: unit_141142d40
// MS2-RANGE: 0x141142d40-0x141145cb0 .text$mn
// MS2-GUESS-LOOKALIKES
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


void Unk_CMISDriveTail4()
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

// The identity accessor unit_1411267c0's copy ctor calls by address (_Get_first 0x141143890 returns its argument).
class Unk_ContA;

// MS2-FUNCTIONAL: the exe forwards through the folded _Get_first instance
// @0x141145120
void* FUN_141145120(const Unk_ContA& o)
{
    return (void*)&o;
}
