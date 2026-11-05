// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x14111fdf0-
// 0x141121cf0 (queue unit_14111fdf0): the public map::try_emplace / operator[] wrappers of the service's member trees,
// swap/make_pair/sort helpers and the CAtlArray<void*> ctors. Same driver family as cubemapinformationservice_tail2.cpp;
// the container types are shared in cubemapinformationservice_tail.h. Not an original file.
// MS2-UNIT: unit_14111fdf0
// MS2-RANGE: 0x14111fdf0-0x141121cf0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEAA@XZ 0x1411200d0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <NiTransform.h>
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

struct Unk_CMISPawn;
// The ordering FUN_1410bb610 sorts its entity list with: by distance from the pawn (ctor 0x141123230, operator()
// 0x14112cbc0, outside this slice).
class GameObject; struct Unk_DkNearer   // C3: was Unk_CMISByDistance (operator() 0x14112cbc0, unit_14112ab60)
{
    Unk_DkNearer(GameObject* pPlayer) { m_pPlayer = pPlayer; }                 // 0x141123230
    bool operator()(egf::EntityPtr kA, egf::EntityPtr kB) const;
    GameObject* m_pPlayer;
};

typedef std::map<unsigned int, int> Unk_CMISStdMapUIntInt;
typedef std::map<unsigned int, MS2SvrPtr<CUGCMapSetItemInfo> > Unk_CMISMapSetItem;
typedef efd::vector<NiTransform> Unk_CMISXformVec2;
typedef std::vector<Cube*> Unk_CMISCubePtrVec;
// This slice's set-bucket operator[] chain is a second exe copy of the map<id, set<int>> glue that
// entityworldmanager.cpp owns at 0x1411d50c0; a linker keeps one COMDAT per name, so the key here is spelled
// unsigned long (byte-identical code, distinct name).
typedef std::map<unsigned long, Unk_CMISStdIntSet> Unk_CMISMapBucketUL;

// operator[] with a temporary key: the exe's try_emplace(key_type&&) copies
template <class M> void Unk_CMISDriveIndexRv8(M& m)
{
    M tmp;
    tmp[typename M::key_type()];
    (void)m;
}
// the map ops without the const-key operator[] (the exe only indexes these with a temporary)
template <class M> void Unk_CMISDriveMapRv8(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveIndexRv8(m);
    Unk_CMISDriveMapOps(m, k);
}

void Unk_CMISDriveTail8()
{
    int nKey = 0;
    unsigned int uKey = 0;
    unsigned __int64 ullKey = 0;
    egf::EntityID id;
    { Unk_CMISMapIntUInt m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapMark m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapNear m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCell m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapEntity m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapDoll m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapSales m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapSetEffect m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapHead m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapBuckets m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapCubeGroups m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISStdMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapColumns m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntVec m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntityId m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapKind m; Unk_CMISDriveMapRv8(m, nKey); }
    { Unk_CMISMapUIntInt m; Unk_CMISDriveMapRv8(m, uKey); }
    { Unk_CMISStdMapUIntInt m; Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapSetItem m; Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapDword m; unsigned long dwKey = uKey, dwVal; (void)m.find(dwKey, dwVal); (void)m.end(); (void)m.lower_bound(dwKey); }
    { Unk_CMISMapUid m; Unk_CMISDriveMapOps(m, ullKey); (void)m.equal_range(ullKey); m.erase(ullKey); }
    { Unk_CMISMapBucketUL m; Unk_CMISDriveMap(m, static_cast<unsigned long>(uKey)); }
    { Unk_CMISMapSaleState m; std::pair<int, int> k(0, 0); Unk_CMISDriveMapRv8(m, k); (void)m.equal_range(k); m.erase(k); m[k]; }
    { Unk_CMISMapName m; Unk_CMISDriveMapKey(m, CStringA()); }
    { Unk_CMISMapEntityVal m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapProp m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapEntityCube m; Unk_CMISDriveMap(m, id); }
    { Unk_CMISMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISStdMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISMapKindInt m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapKindByte m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv8(m); }
    { Unk_CMISMapIntInt m; Unk_CMISDriveMapOps(m, nKey); }
    { Unk_CubeOwners m; }                                                                       // ugcmapdata's owner table
    { std::_Tree_val<std::_Tree_simple_types<std::pair<const __int64, Unk_PayloadPtr<CubeOwner> > > > t; (void)t; } // mt7: actionkeyobject's owner-id table (its _Compressed_pair ctor 0x1410d7340 calls 0x141121af0)
    { Unk_CMISIntSet s; Unk_CMISDriveSet(s, nKey); { int n = nKey; s.insert(std::move(n)); } (void)s.equal_range(nKey); s.erase(nKey); (void)s.key_comp(); }
    { Unk_CMISPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISAutoSet s; MS2Ptr<AutomaticCreateCubeInfo> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISFuncCubeSet s; MS2Ptr<CFunctionCubeObject> p; Unk_CMISDriveSet(s, p); s.emplace(p); }
    { Unk_CMISEntityIdSet s; Unk_CMISDriveSet(s, id); }
    { Unk_CMISIntVec v; Unk_CMISDriveVector(v, nKey); Unk_CMISIntVec w; v = w; }
    { Unk_CMISStdEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); std::sort(v.begin(), v.end(), Unk_DkNearer(0)); }
    { Unk_CMISEntityIdVec v; Unk_CMISDriveVector(v, id); Unk_CMISEntityIdVec w; v = w; }
    { Unk_CMISEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); Unk_CMISEntVec w; v = w; }
    { Unk_CMISElem52Vec v; Unk_CMISDriveVector(v, Unk_CMISElem52()); Unk_CMISElem52Vec w; v = w; }
    { Unk_CMISKindVec v; Unk_CMISDriveVector(v, Unk_CMISKindC_None); Unk_CMISKindVec w; v = w; }
    { Unk_CMISStdIntSet s; { int n = nKey; s.insert(std::move(n)); } }
    { Unk_CMISPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; s.insert(std::pair<int, int>(0, 0)); }
    { std::vector<int> v; v.push_back(nKey); { int n = nKey; v.push_back(std::move(n)); } }
    { Unk_CMISMapBucket a, b; a = b; }
    { Unk_CMISXformVec2 v; NiTransform x; v.push_back(x); v.push_back(NiTransform()); Unk_CMISXformVec2 w; v = w; }
    { Unk_CMISCubePtrVec v; Cube* p = 0; v.push_back(p); v.push_back(static_cast<Cube*>(0)); Unk_CMISCubePtrVec w; v = w; }
    { MS2Ptr<UIHouseMarkEntity> p; }
    { efd::utf8string s; (void)s.find_last_of("/", 0); }
    { std::string s; s.append("x"); }
    { int a = nKey, b = nKey; std::pair<int, int> pr = std::make_pair(a, b); (void)pr; }
    { ATL::CAtlArray<Unk_CMISElem388*> a; ATL::CAtlArray<Unk_CMISElem3a8*> b; ATL::CAtlArray<Unk_CMISElem458*> c; }
}
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@1@@Z 0x141120090 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@1@@Z 0x1411202d0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@1@@Z 0x141120930 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@1@@Z 0x141120f90 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBKV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@1@@Z 0x1411211d0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@1@@Z 0x141121350 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$map@HIU?$less@H@std@@@efd@@QEAA@XZ 0x141120490 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$map@HUUnk_CMISCell@@U?$less@H@std@@@efd@@QEAA@XZ 0x1411205b0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$map@HUUnk_CMISCubeTimer@@U?$less@H@std@@@efd@@QEAA@XZ 0x141120670 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$map@HUUnk_CMISMarkRec@@U?$less@H@std@@@efd@@QEAA@XZ 0x141120750 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@1@@Z 0x141120b30 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@1@@Z 0x141120b70 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@1@@Z 0x141120bb0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@1@@Z 0x141120510 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@1@@Z 0x141120c30 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@QEAA@XZ 0x141121a30 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
