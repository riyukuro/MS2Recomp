// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x141159a60-
// 0x14115b040 (queue unit_141159a60): the public map::try_emplace / operator[] wrappers of the service's member trees,
// swap/make_pair/sort helpers and the CAtlArray<void*> ctors. Same driver family as cubemapinformationservice_tail2.cpp;
// the container types are shared in cubemapinformationservice_tail.h. Not an original file.
// MS2-UNIT: unit_141159a60
// MS2-RANGE: 0x141159a60-0x14115b040 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <NiTransform.h>
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

// la1: the column map efd::map<long, MS2Ptr<Cube>> (operator[] 0x141128350, erase(where) 0x141156050); its copies in this
// unit's range are pinned at the end.
void Unk_CMISDriveColumnMapTail9()
{
    efd::map<long, MS2Ptr<Cube> > m;
    const long k = 0;
    m[k];
    m.erase(m.begin());
}

struct Unk_CMISPawn;
// The ordering FUN_1410bb610 sorts its entity list with: by distance from the pawn (ctor 0x141123230, operator()
// 0x14112cbc0, outside this slice).
struct Unk_CMISByDistance
{
    Unk_CMISByDistance(Unk_CMISPawn* pPawn) { m_pPawn = pPawn; }
    bool operator()(egf::EntityPtr a, egf::EntityPtr b) const;
    Unk_CMISPawn* m_pPawn;
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
template <class M> void Unk_CMISDriveIndexRv9(M& m)
{
    M tmp;
    tmp[typename M::key_type()];
    (void)m;
}
// the map ops without the const-key operator[] (the exe only indexes these with a temporary)
template <class M> void Unk_CMISDriveMapRv9(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveIndexRv9(m);
    Unk_CMISDriveMapOps(m, k);
}

void Unk_CMISDriveTail9()
{
    int nKey = 0;
    unsigned int uKey = 0;
    unsigned __int64 ullKey = 0;
    egf::EntityID id;
    { Unk_CMISMapIntUInt m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapMark m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapNear m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCell m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapEntity m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapDoll m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapSales m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapSetEffect m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapHead m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapBuckets m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapCubeGroups m; Unk_CMISDriveMap(m, nKey); Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISStdMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapColumns m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntVec m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntityId m; Unk_CMISDriveMapKey(m, nKey); Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapKind m; Unk_CMISDriveMapRv9(m, nKey); }
    { Unk_CMISMapUIntInt m; Unk_CMISDriveMapRv9(m, uKey); }
    { Unk_CMISStdMapUIntInt m; Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapSetItem m; Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapDword m; unsigned long dwKey = uKey, dwVal; (void)m.find(dwKey, dwVal); (void)m.end(); (void)m.lower_bound(dwKey); }
    { Unk_CMISMapUid m; Unk_CMISDriveMapOps(m, ullKey); (void)m.equal_range(ullKey); m.erase(ullKey); }
    { Unk_CMISMapBucketUL m; Unk_CMISDriveMap(m, static_cast<unsigned long>(uKey)); }
    { Unk_CMISMapSaleState m; std::pair<int, int> k(0, 0); Unk_CMISDriveMapRv9(m, k); (void)m.equal_range(k); m.erase(k); m[k]; }
    { Unk_CMISMapName m; Unk_CMISDriveMapKey(m, CStringA()); }
    { Unk_CMISMapEntityVal m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapProp m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapEntityCube m; Unk_CMISDriveMap(m, id); }
    { Unk_CMISMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISStdMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISMapKindInt m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapKindByte m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); Unk_CMISDriveIndexRv9(m); }
    { Unk_CMISMapIntInt m; Unk_CMISDriveMapOps(m, nKey); }
    { Unk_CubeOwners m; }                                                                       // ugcmapdata's owner table
    { Unk_CMISIntSet s; Unk_CMISDriveSet(s, nKey); { int n = nKey; s.insert(std::move(n)); } (void)s.equal_range(nKey); s.erase(nKey); (void)s.key_comp(); }
    { Unk_CMISPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISAutoSet s; MS2Ptr<AutomaticCreateCubeInfo> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISFuncCubeSet s; MS2Ptr<CFunctionCubeObject> p; Unk_CMISDriveSet(s, p); s.emplace(p); }
    { Unk_CMISEntityIdSet s; Unk_CMISDriveSet(s, id); }
    { Unk_CMISIntVec v; Unk_CMISDriveVector(v, nKey); Unk_CMISIntVec w; v = w; }
    { Unk_CMISStdEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); std::sort(v.begin(), v.end(), Unk_CMISByDistance(0)); }
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
    { efd::utf8string s; (void)s.find_last_of("/", 0); efd::utf8string t = s.substr(0, 1); (void)t; }
    { std::string s; s.append("x"); }
    { int a = nKey, b = nKey; std::pair<int, int> pr = std::make_pair(a, b); (void)pr; }
    { ATL::CAtlArray<Unk_CMISElem388*> a; ATL::CAtlArray<Unk_CMISElem3a8*> b; ATL::CAtlArray<Unk_CMISElem458*> c; }
}

// Full-exe entry points under the FUN_ spellings that unit_141127a90's iterator helpers call: each is a
// _Compressed_pair / _Get_unwrapped accessor that forwards to the addressof / _Kfn identity instance ICF folded it
// onto (callee VAs below).
typedef struct std::pair<int const, struct Unk_CMISMarkRec> Unk_Ao1173c0; template<> Unk_Ao1173c0* std::addressof<Unk_Ao1173c0>(Unk_Ao1173c0&) noexcept;
typedef struct std::pair<int const, struct Unk_Int3> Unk_Ao1173d0; template<> Unk_Ao1173d0* std::addressof<Unk_Ao1173d0>(Unk_Ao1173d0&) noexcept;
typedef struct std::_Tree_node<struct std::pair<int const, class MS2Ptr<class FittingDollData>>, void *> * Unk_Ao1173e0; template<> Unk_Ao1173e0* std::addressof<Unk_Ao1173e0>(Unk_Ao1173e0&) noexcept;
typedef struct std::pair<int const, class efd::SmartPointer<class egf::Entity>> Unk_Ao1173f0; template<> Unk_Ao1173f0* std::addressof<Unk_Ao1173f0>(Unk_Ao1173f0&) noexcept;
typedef struct std::pair<int const, class MS2Ptr<class FittingDollData>> Unk_Ao117400; template<> Unk_Ao117400* std::addressof<Unk_Ao117400>(Unk_Ao117400&) noexcept;
typedef struct std::pair<int const, class MS2Ptr<class Cube>> Unk_Ao117410; template<> Unk_Ao117410* std::addressof<Unk_Ao117410>(Unk_Ao117410&) noexcept;
typedef struct std::_Tree_node<struct std::pair<int const, class efd::SmartPointer<class egf::Entity>>, void *> * Unk_Ao117420; template<> Unk_Ao117420* std::addressof<Unk_Ao117420>(Unk_Ao117420&) noexcept;
typedef struct std::_Tree_node<struct std::pair<int const, class Unk_PayloadPtr<class CubeOwner>>, void *> * Unk_Ao117430; template<> Unk_Ao117430* std::addressof<Unk_Ao117430>(Unk_Ao117430&) noexcept;
typedef struct std::pair<int const, class MS2Ptr<class UICubeUGCHead>> Unk_Ao117440; template<> Unk_Ao117440* std::addressof<Unk_Ao117440>(Unk_Ao117440&) noexcept;
typedef struct std::_Tree_node<struct std::pair<int const, class std::map<int, class Unk_PayloadPtr<class CubeOwner>, struct std::less<int>, class std::allocator<struct std::pair<int const, class Unk_PayloadPtr<class CubeOwner>>>>>, void *> * Unk_Ao117450; template<> Unk_Ao117450* std::addressof<Unk_Ao117450>(Unk_Ao117450&) noexcept;
typedef struct std::pair<int const, class std::map<int, class MS2Ptr<class Cube>, struct std::less<int>, class std::allocator<struct std::pair<int const, class MS2Ptr<class Cube>>>>> Unk_Ao117460; template<> Unk_Ao117460* std::addressof<Unk_Ao117460>(Unk_Ao117460&) noexcept;
typedef struct std::pair<int const, class efd::set<int, struct std::less<int>>> Unk_Ao117470; template<> Unk_Ao117470* std::addressof<Unk_Ao117470>(Unk_Ao117470&) noexcept;
typedef struct std::pair<int const, class efd::vector<class efd::SmartPointer<class egf::Entity>>> Unk_Ao117480; template<> Unk_Ao117480* std::addressof<Unk_Ao117480>(Unk_Ao117480&) noexcept;
typedef struct std::pair<int const, class egf::EntityID> Unk_Ao117490; template<> Unk_Ao117490* std::addressof<Unk_Ao117490>(Unk_Ao117490&) noexcept;
typedef struct std::pair<int const, struct Unk_CMISCubeTimer> Unk_Ao1174a0; template<> Unk_Ao1174a0* std::addressof<Unk_Ao1174a0>(Unk_Ao1174a0&) noexcept;
typedef struct std::_Tree_node<struct std::pair<unsigned int const, int>, void *> * Unk_Ao1174b0; template<> Unk_Ao1174b0* std::addressof<Unk_Ao1174b0>(Unk_Ao1174b0&) noexcept;
typedef struct std::_Tree_node<struct std::pair<unsigned int const, class MS2SvrPtr<class CUGCMapSetItemInfo>>, void *> * Unk_Ao1174c0; template<> Unk_Ao1174c0* std::addressof<Unk_Ao1174c0>(Unk_Ao1174c0&) noexcept;
typedef struct std::_Tree_node<struct std::pair<unsigned int const, class std::set<int, struct std::less<int>, class std::allocator<int>>>, void *> * Unk_Ao1174d0; template<> Unk_Ao1174d0* std::addressof<Unk_Ao1174d0>(Unk_Ao1174d0&) noexcept;
typedef struct std::_Tree_node<struct std::pair<unsigned long const, unsigned long>, void *> * Unk_Ao1174e0; template<> Unk_Ao1174e0* std::addressof<Unk_Ao1174e0>(Unk_Ao1174e0&) noexcept;
typedef struct std::pair<class egf::EntityID const, class Unk_CMISPropPtr> Unk_Ao1174f0; template<> Unk_Ao1174f0* std::addressof<Unk_Ao1174f0>(Unk_Ao1174f0&) noexcept;
typedef struct std::pair<class egf::EntityID const, class MS2Ptr<class Cube>> Unk_Ao117500; template<> Unk_Ao117500* std::addressof<Unk_Ao117500>(Unk_Ao117500&) noexcept;
typedef struct std::_Tree_node<struct std::pair<class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> const, int>, void *> * Unk_Ao117510; template<> Unk_Ao117510* std::addressof<Unk_Ao117510>(Unk_Ao117510&) noexcept;
typedef struct std::pair<enum Unk_CMISKindB const, int> Unk_Ao8b6530; template<> Unk_Ao8b6530* std::addressof<Unk_Ao8b6530>(Unk_Ao8b6530&) noexcept;
typedef struct std::pair<enum Unk_CMISKindB const, unsigned char> Unk_Ao8b6540; template<> Unk_Ao8b6540* std::addressof<Unk_Ao8b6540>(Unk_Ao8b6540&) noexcept;
typedef std::pair<const egf::EntityID, MS2Ptr<Cube> > Unk_KfnPair; typedef std::_Tmap_traits<egf::EntityID, MS2Ptr<Cube>, std::less<egf::EntityID>, efd::CustomAllocator<Unk_KfnPair>, 0> Unk_KfnTraits;

// @0x14115a580
char* FUN_14115a580(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1173c0*>(p))); }

// @0x14115a5a0
char* FUN_14115a5a0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1173d0*>(p))); }

// @0x14115a5c0
char* FUN_14115a5c0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1173e0*>(p))); }

// @0x14115a5e0
char* FUN_14115a5e0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1173f0*>(p))); }

// @0x14115a600
char* FUN_14115a600(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117400*>(p))); }

// @0x14115a620
char* FUN_14115a620(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117410*>(p))); }

// @0x14115a640
char* FUN_14115a640(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117420*>(p))); }

// @0x14115a660
char* FUN_14115a660(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117430*>(p))); }

// @0x14115a680
char* FUN_14115a680(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117440*>(p))); }

// @0x14115a6a0
char* FUN_14115a6a0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117450*>(p))); }

// @0x14115a6c0
char* FUN_14115a6c0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117460*>(p))); }

// @0x14115a6e0
char* FUN_14115a6e0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117470*>(p))); }

// @0x14115a700
char* FUN_14115a700(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117480*>(p))); }

// @0x14115a720
char* FUN_14115a720(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117490*>(p))); }

// @0x14115a740
char* FUN_14115a740(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1174a0*>(p))); }

// @0x14115a760
char* FUN_14115a760(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1174b0*>(p))); }

// @0x14115a780
char* FUN_14115a780(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1174c0*>(p))); }

// @0x14115a7a0
char* FUN_14115a7a0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1174d0*>(p))); }

// @0x14115a7c0
char* FUN_14115a7c0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1174e0*>(p))); }

// @0x14115a7e0
char* FUN_14115a7e0(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao1174f0*>(p))); }

// @0x14115a800
char* FUN_14115a800(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117500*>(p))); }

// @0x14115a820
char* FUN_14115a820(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao117510*>(p))); }

// @0x14115a840
char* FUN_14115a840(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao8b6530*>(p))); }

// @0x14115a860
char* FUN_14115a860(char* p) { return reinterpret_cast<char*>(std::addressof(*reinterpret_cast<Unk_Ao8b6540*>(p))); }

// @0x14115a880
char* FUN_14115a880(char* p) { return reinterpret_cast<char*>(const_cast<egf::EntityID*>(&Unk_KfnTraits::_Kfn(*reinterpret_cast<Unk_KfnPair*>(p)))); }

// The list append worldservice_1 calls: std::vector<EntityPtr>::emplace_back (folded with
// vector<Cube*>::push_back). The exe calls the std::allocator instance 0x14111ada0, not the CustomAllocator 0x14111ad30.
// @0x14115a960
void FUN_14115a960(void* list, void* elem)
{
    static_cast<std::vector<egf::EntityPtr>*>(list)->emplace_back(*static_cast<const egf::EntityPtr*>(elem));
}

// The container wrappers cubemapinformationservice_3 calls by address. Its stand-in types are opaque here; each is the
// container the callee instantiates (the exe passes the pointers straight through).
struct Unk_CMISKeySet;
struct Unk_CMISCubeByKey;
struct Unk_CMISCubePtrSet;
struct Unk_CMISEntSet;
struct Unk_CMISEntityRef;
struct Unk_CMISXformVec;
template <unsigned __int64 N> struct Unk_CMISTree;

// @0x14115a8a0
void FUN_14115a8a0(Unk_CMISKeySet* pVec, Unk_CMISCubeByKey* pVal)
{
    reinterpret_cast<Unk_CMISIntVec*>(pVec)->emplace_back(*reinterpret_cast<const int*>(pVal));
}

// @0x14115a900
void FUN_14115a900(Unk_CMISCubePtrSet* pVec, Cube** ppCube)
{
    reinterpret_cast<Unk_CMISCubePtrVec*>(pVec)->emplace_back(*ppCube);
}

// @0x14115a930
void FUN_14115a930(void* list, egf::EntityPtr* pEnt)
{
    static_cast<Unk_CMISEntVec*>(list)->emplace_back(*pEnt);
}

// @0x14115a990
void FUN_14115a990(Unk_CMISEntSet* pVec, const Unk_CMISEntityRef* pId)
{
    reinterpret_cast<Unk_CMISEntityIdVec*>(pVec)->emplace_back(*reinterpret_cast<const egf::EntityID*>(pId));
}

// @0x14115a9c0
void FUN_14115a9c0(Unk_CMISXformVec* pVec, const NiTransform* pXform)
{
    reinterpret_cast<Unk_CMISXformVec2*>(pVec)->emplace_back(*pXform);
}

// size() through _Get_data 0x141142ec0 (set<MS2Ptr<CFunctionCubeObject>>; _Mysize sits after _Myhead)
class CFunctionCubeObject;
typedef std::_Tree_comp_alloc<std::_Tset_traits<MS2Ptr<CFunctionCubeObject>, std::less<MS2Ptr<CFunctionCubeObject> >, std::allocator<MS2Ptr<CFunctionCubeObject> >, 0> > Unk_FcSetBase;
// @0x14115adf0
__int64 FUN_14115adf0(Unk_CMISTree<284>* pSet)
{
    return reinterpret_cast<Unk_FcSetBase*>(pSet)->_Get_data()._Mysize;
}
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBJV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@@std@@SA_KAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBJV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@@Z 0x141159e10 ; la1: the efd::map<long,MS2Ptr<Cube>> (column map, operator[] 0x141128350) chain
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@JV?$MS2Ptr@VCube@@@@U?$less@J@std@@V?$CustomAllocator@U?$pair@$$CBJV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115a270 ; la1: the efd::map<long,MS2Ptr<Cube>> (column map, operator[] 0x141128350) chain
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141159f70 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x141159f90 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x141159fd0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x141159ff0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115a190 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115a1f0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@HU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115a230 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindB@@EU?$less@W4Unk_CMISKindB@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115a250 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115a2d0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?push_back@?$vector@VNiTransform@@V?$CustomAllocator@VNiTransform@@@efd@@@std@@QEAAX$$QEAVNiTransform@@@Z 0x14115a9f0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115aa90 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@U?$less@_K@std@@V?$CustomAllocator@U?$pair@$$CB_KV?$MS2Ptr@VUnk_CMISUidRecord@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x14115aab0 ; sfk: byte-identical COMDAT fold (was the look-alike guess)
