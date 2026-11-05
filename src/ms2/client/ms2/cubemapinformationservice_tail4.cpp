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
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@XZ 0x141144e10
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@XZ 0x141144de0
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

// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEBAAEBV?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@XZ 0x141145120 ; unit_1411267c0's copy assignment calls the const _Getal of its entity vector
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVCube@@V?$CustomAllocator@PEAVCube@@@efd@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@PEAVCube@@@std@@@2@XZ 0x141142f90 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@PEAVCube@@V?$CustomAllocator@PEAVCube@@@efd@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEAVCube@@@std@@@2@XZ 0x141142fb0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@VNiTransform@@V?$CustomAllocator@VNiTransform@@@efd@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@VNiTransform@@@std@@@2@XZ 0x141143010 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@VNiTransform@@V?$CustomAllocator@VNiTransform@@@efd@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@VNiTransform@@@std@@@2@XZ 0x141143030 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@std@@@2@XZ 0x1411444b0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// m49: identical one-line accessors, the call-site guess pairs them with other maps' copies; pinned by merge 50.
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1411452e0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x141145420
// Pinned by their exe callers: max_size of map<int,MS2Ptr<Cube>> 0x141159ff0 calls 0x141144690 and of map<Unk_CMISKindA,int>
// 0x14115a210 calls 0x141144cf0; the map<Unk_CMISKindB,int> _Buynode/_Erase/_Freeheadnode/erase call 0x141144d20 and the
// map<Unk_CMISKindB,unsigned char> ones call 0x141144d80; _Compare of map<int,MS2Ptr<Cube>> 0x141134910 calls 0x141145440.
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@XZ 0x141144690
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$allocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@2@XZ 0x141144cf0
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@$0A@@std@@@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@PEAX@std@@@efd@@XZ 0x141144d20
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@PEAX@std@@@efd@@XZ 0x141144d80
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x141145440
// Their callees: the map<Unk_CMISKindA,int> const _Getal 0x141144cf0 calls _Get_second 0x141143e20 and _Get_first 0x1411439b0;
// the set<pair<int,int>> const _Getal 0x141144f30 calls _Get_first 0x1411439d0.
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@W4Unk_CMISKindA@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@2@$00@2@XZ 0x141143e20
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@2@XZ 0x1411439b0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@2@XZ 0x1411439d0
// The map<int,MS2Ptr<SalesInfo>> const _Getal 0x141144510 calls _Get_second 0x141143ac0 and _Get_first 0x1411435b0.
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@$00@2@XZ 0x141143ac0
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@std@@@2@XZ 0x1411435b0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@$00@2@XZ 0x141143d90 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@VEntityID@egf@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@$00@2@XZ 0x141143da0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@2@XZ 0x1411440d0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@2@XZ 0x1411440e0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@4@$0A@@std@@@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141144ba0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@4@$0A@@std@@@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@PEAX@std@@@efd@@XZ 0x141144bd0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@4@$0A@@std@@@std@@QEAAAEAU?$less@VEntityID@egf@@@2@XZ 0x1411457a0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@VEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@4@$0A@@std@@@std@@QEBAAEBU?$less@VEntityID@egf@@@2@XZ 0x1411457c0 ; ua12: kept on its exe copy after the Unk_CMISPropPtr retype
