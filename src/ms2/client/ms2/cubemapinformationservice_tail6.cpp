// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x14111e450-
// 0x14111eb90 (queue unit_14111e450): message handler ctors (EntityChange wrapper / SceneGraphAdded), MS2Ptr and
// Unk_PayloadPtr ctors of the service's record maps, TSingleton ctor. Same driver as cubemapinformationservice_tail5.cpp;
// tplpin pairs the copies that fall in this slice. Not an original file.
// MS2-UNIT: unit_14111e450
// MS2-RANGE: 0x14111e450-0x14111eb90 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include <efd/MessageService.h>
#include <egf/EntityChangeMessage.h>
#include <ecr/CoreRuntimeMessages.h>
#include <NiTransform.h>
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

// ecr::SceneGraphService::kInvalidHandle is referenced by the SceneGraphAddedMessage factory method the
// handler anchor below instantiates; the engine ships the declaration, the definition is selectany. Gamebryo's
// SceneGraphService.cpp defines it in the full-exe link, so only the hook DLL needs this copy.
#ifdef MS2_HOOK_DLL
__declspec(selectany) const ecr::SceneGraphService::SceneGraphHandle ecr::SceneGraphService::kInvalidHandle = 0;
#endif

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


// the service's message handlers (static objects in the exe's .text$di; constructed here only to instantiate the templates)
void Unk_CMISHandlerAnchor()
{
    efd::MessageWrapperSubclassHandler<CubeMapInformationService, egf::EntityChangeMessage, egf::EntityChangeMessage, 8253>
        h1(&CubeMapInformationService::FUN_1410cef70);
    efd::MessageHandlerImpl<CubeMapInformationService, ecr::SceneGraphAddedMessage>
        h2(reinterpret_cast<void (CubeMapInformationService::*)(const ecr::SceneGraphAddedMessage*, efd::Category)>(
            &CubeMapInformationService::FUN_1410cf130));
}

void Unk_CMISDriveTail6()
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

// -----------------------------------------------------------------------------------------------------------
// The 16 out-of-line members of this slice that the driver's copies do not pair, written as plain functions
// with an explicit @VA tag each (the exe emits one copy per type; naming the tags removes the look-alike
// ambiguity the generic MS2Ptr/Unk_PayloadPtr/TSingleton instantiations suffer from).
// -----------------------------------------------------------------------------------------------------------

void FUN_1411225a0(void* pThis);      // 0x1411225a0: async queue ctor
void FUN_140ae79e0(void* pThis);      // 0x140ae79e0: async queue aux ctor
void FUN_14112fe10(void* pThis);      // MS2Ptr<AutomaticCreateCubeInfo> link
void FUN_14112faf0(void* pThis);      // MS2Ptr<CFunctionCubeObject> link
void FUN_14112fb20(void* pThis);      // MS2Ptr<Unk_CMISUidRecord> link
void FUN_140dd7940(void* pThis);      // MS2Ptr<SaleStateData> link
void FUN_140ba1c80(void* pThis);      // MS2Ptr<SetItemEffectInfo> link
void FUN_14112fb50(void* pThis);      // MS2Ptr<Unk_CMISHouseRef> link
void FUN_14112fb80(void* pThis);      // MS2Ptr<Unk_CMISBlueprintPtr>/<Unk_CMISDesignPtr> link
void FUN_140fac7c0(void* pThis);
void FUN_140fac7f0(void* pThis);
void FUN_14112fbb0(void* pThis);
extern char DAT_142eb3950;            // TSingleton<CubeMapInformationService> vtable
extern void* DAT_143ab3908;           // TSingleton<CubeMapInformationService>::ms_pInstance

// @0x14111e640
void* FUN_14111e640(void* pThis)
{
    FUN_1411225a0(pThis);
    FUN_140ae79e0((char*)pThis + 0x10);
    return pThis;
}

// @0x14111e6e0
void* FUN_14111e6e0(void* pThis, void* pUnused)
{
    *(void**)((char*)pThis + 8) = 0;
    FUN_14112fe10(pThis);
    return pThis;
}

// @0x14111e770
void* FUN_14111e770(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_14112faf0(pThis);
    return pThis;
}

// @0x14111e800
void* FUN_14111e800(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_14112fb20(pThis);
    return pThis;
}

// @0x14111e850
void* FUN_14111e850(void* pThis, void* pOther)
{
    *(void**)((char*)pThis + 8) = *(void**)((char*)pOther + 8);
    FUN_140dd7940(pThis);
    return pThis;
}

// @0x14111e890
void* FUN_14111e890(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_140dd7940(pThis);
    return pThis;
}

// @0x14111e900
void* FUN_14111e900(void* pThis, void* pOther)
{
    *(void**)((char*)pThis + 8) = *(void**)((char*)pOther + 8);
    FUN_140ba1c80(pThis);
    return pThis;
}

// @0x14111e960
void* FUN_14111e960(void* pThis, void* pOther)
{
    *(void**)((char*)pThis + 8) = *(void**)((char*)pOther + 8);
    FUN_14112fb50(pThis);
    return pThis;
}

// @0x14111e9a0
void* FUN_14111e9a0(void* pThis, int nUnused)
{
    *(void**)((char*)pThis + 8) = 0;
    return pThis;
}

// @0x14111e9c0
void* FUN_14111e9c0(void* pThis, void* pOther)
{
    *(void**)((char*)pThis + 8) = *(void**)((char*)pOther + 8);
    FUN_14112fb80(pThis);
    return pThis;
}

// @0x14111ea00
void* FUN_14111ea00(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_14112fb80(pThis);
    return pThis;
}

// @0x14111ea50
void* FUN_14111ea50(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_140fac7c0(pThis);
    return pThis;
}

// @0x14111eaa0
void* FUN_14111eaa0(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_140fac7f0(pThis);
    return pThis;
}

// @0x14111eaf0
void* FUN_14111eaf0(void* pThis, void* pRaw)
{
    *(void**)((char*)pThis + 8) = pRaw;
    FUN_14112fbb0(pThis);
    return pThis;
}

// @0x14111eb20
void* FUN_14111eb20(void* pThis)
{
    *(void**)((char*)pThis + 8) = 0;
    return pThis;
}

// @0x14111eb40
void* FUN_14111eb40(void* pThis)
{
    *(void**)pThis = (void*)&DAT_142eb3950;
    if (pThis != 0)
        DAT_143ab3908 = (char*)pThis - 0x18;
    else
        DAT_143ab3908 = 0;
    return pThis;
}
