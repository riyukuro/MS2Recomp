// cubemapinformationservice_3.h - CubeMapInformationService (RTTI) and FittingDollData. The service is an efd system
// service (TSingleton at +0x18, atomic refcount at +0x20) that owns the cube/UGC map state of the client: cube
// owners and houses, the cube/function-cube/NPC containers, the PhysX bodies generated for the cube floors and the
// per-tick housekeeping timers. Owning unit: client\ms2\cubemapinformationservice.cpp#3 (0x1410b68a0-0x1410d5bc0).
// sizeof 0x4a8 (operator new size at the creation site in scenestategame/ms2.c).
//
// Most members are std::map/std::set-like trees (0x10 bytes) whose key/value types are not recovered: each family is
// a unit-local stand-in Unk_CMISTree<ctor VA of the family>. The tree glue lives in the 0x14111xxxx / 0x14112xxxx
// template zones owned by other units, so the stand-ins only carry the ctor/dtor the exe calls.
#pragma once
#include <atlcoll.h>
#include <atlstr.h>
#include <efd/ISystemService.h>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/timer.h"
#include "ms2/commonfiles/ugcbuildvalidator.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/cubespawnobject.h"
namespace egf { class Entity; class EntityChangeMessage; }

// RTTI name; layout from 1410b68a0, storage size 0x70.
class FittingDollData : public CPtred {
public:
    FittingDollData();
    virtual ~FittingDollData();
    int kind;
    unsigned __int64 instanceId;
    int field28;
    efd::Point3 position;
    efd::Point3 rotation;
    int field44,field48;
    ATL::CAtlArray<MS2Ptr<CItem>> items;
};
MS2_CHECK_SIZE(FittingDollData,0x70);
MS2_CHECK_OFFSET(FittingDollData,instanceId,0x20);
MS2_CHECK_OFFSET(FittingDollData,position,0x2c);
MS2_CHECK_OFFSET(FittingDollData,rotation,0x38);
MS2_CHECK_OFFSET(FittingDollData,items,0x50);

struct Unk_CMISPt2; struct Unk_CMISPt3;
class CubeMapInformationService;
template <class T> class TSingleton;
template <> class TSingleton<CubeMapInformationService>
{
public:
    TSingleton();                                   // 0x1410b69e0 (inline in the ctor)
    virtual ~TSingleton() { s_instance = 0; }       // 0x14112d060
    static CubeMapInformationService* s_instance;
};

// Tree-shaped container (head pointer + count, 0x10 bytes) of one unrecovered key/value family. N is the VA of the
// exe's default-constructor wrapper of the family (its dtor wrapper is the 0x141125xxx twin).
template <unsigned __int64 N> struct Unk_CMISTree
{
    Unk_CMISTree();
    ~Unk_CMISTree();
    void* head;
    unsigned __int64 count;
};

// Three-flag record (+0x418), ctor 0x140b68e60 (same bytes as scenestategame's Unk_SSGHouseRule).
struct Unk_CMISFlags3
{
    Unk_CMISFlags3();
    bool a, b, c;
};

// Null handle (ctor 0x1401cd100) of the header statics: the file-static none id DAT_143acf820.
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
// Entity id handle copied from the none id (copy ctor 0x1408b6b20).
struct Unk_CMISEntityRef
{
    Unk_CMISEntityRef(const Unk_CMISEntityRef&);                 // 0x1408b6b20
    bool FUN_140965410(const Unk_1401cd100& none) const;     // operator==
    void* m_p;
};

struct Unk_CMISObj208; struct Unk_CMISObj480;

struct Unk_CMISElem388;
struct Unk_CMISHandle388; struct Unk_CMISHandle3a8;
struct Unk_CMISElem3a8;
struct Unk_CMISElem458;
class CubeMapInformationService : public efd::ISystemService, public TSingleton<CubeMapInformationService>
{
    EE_DECLARE_CLASS1(CubeMapInformationService, 0x06100017, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CubeMapInformationService();                    // 0x1410b69e0
    virtual ~CubeMapInformationService();           // 0x1410b7240
    virtual const char* GetDisplayName() const;     // 0x1410b7680
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1410ce800
    virtual efd::AsyncResult OnInit();              // 0x1410ce850
    virtual efd::AsyncResult OnTick();              // 0x1410ce8a0
    virtual efd::AsyncResult OnShutdown();          // 0x1410cef40

    int FUN_1410b76a0();
    void FUN_1410b76d0();
    Unk_StreamPoint FUN_1410b7a20(Unk_StreamPoint pt, Unk_StreamPoint* pOut);
    Unk_StreamPoint FUN_1410b7ad0(PCBase* pActor, float fDist, Unk_StreamPoint* pOut, int bSnap);
    Unk_StreamPoint FUN_1410b7ba0(Unk_StreamPoint ptFrom, Unk_StreamPoint ptTo, float fDist, Unk_StreamPoint* pOut, int bSnap);
    bool FUN_1410b7d50();
    bool FUN_1410b7da0(Unk_StreamPoint pt);
    bool FUN_1410b7e80(Unk_StreamPoint pt);
    bool FUN_1410b7ed0(int nKey);
    bool FUN_1410b7f90(Unk_Int3 cell);
    Unk_CMISTree<287>* FUN_1410b7fe0(int nKey);
    Cube* FUN_1410b80d0(MS2Ptr<Cube> spCube, int nZ);
    bool FUN_1410b82c0(MS2Ptr<Cube> spCube);
    bool FUN_1410b8420(MS2Ptr<Cube> spCube, int nZ);
    void FUN_1410b85f0(Unk_Int3* pMin, Unk_Int3* pMax);
    Cube* FUN_1410b8790(Unk_Int3 pt);
    Cube* FUN_1410b8980(Unk_Int3 pt);
    Cube* FUN_1410b8a60(Unk_Int3 pt);
    Cube* FUN_1410b8ab0(Unk_StreamPoint pt);
    Cube* FUN_1410b8b00(int nKey);
    Cube* FUN_1410b8be0(const Unk_CMISEntityRef& ref);
    Cube* FUN_1410b8c90(const Unk_CMISEntityRef& ref);
    Cube* FUN_1410b8d90(Cube* pBase, int nOffset, int nField44);
    Cube* FUN_1410b8e60(egf::Entity* pEntity);
    Cube* FUN_1410b8f30(Unk_StreamPoint ptFrom, Unk_StreamPoint* pHit, float fRange);
    Unk_StreamPoint FUN_1410b9150(Unk_StreamPoint ptIn);
    bool FUN_1410b9330(void* pArg, Unk_StreamPoint pt, float fStep, Unk_StreamPoint* pOutPos, Unk_StreamPoint* pOutRot, int* pnResult, void** ppHit);
    int FUN_1410d1320(void* pArg, Unk_StreamPoint pt, float fStep, Unk_StreamPoint* pOut);
    int FUN_1410d1820(void* pArg, int nDir, Unk_StreamPoint pt, Unk_StreamPoint ptCur, void** ppFound);
    int FUN_1410d2130(void* pFound, int nDir, float fRadius, Unk_StreamPoint* pOutPos, Unk_StreamPoint* pOutRot);
    Cube* FUN_1410b9850(int nItemId);
    int FUN_1410b9950(int nCategory);
    int FUN_1410b9a50();
    int FUN_1410b9b20(int nItemId);
    int FUN_1410b9d80(__int64 nId);
    Unk_CMISTree<277>* FUN_1410b9e70();
    int FUN_1410b9c20(int nItemId, __int64 nOwnerId);
    float FUN_1410ba440(int nDir);
    int FUN_1410ba4a0(Unk_StreamPoint ptDir);
    Unk_Int3 FUN_1410bab50(Unk_Int3 pt, int nDir);
    Unk_Int3 FUN_1410bac00(Unk_StreamPoint ptDir);
    int FUN_1410bb950(Unk_Int3 pt);
    void FUN_1410bba60(int nKey);
    int FUN_1410bbab0(int nKey);
    void FUN_1410bbc00(int nKey, int nUnused);
    void FUN_1410bbcd0(int nKey, int nFlag);
    void FUN_1410bc1c0();
    void FUN_1410bc320();
    Cube* FUN_1410b9080(Cube* pBase, int nOffset);
    int FUN_1410d2f40(int nKey);
    bool FUN_1410c68e0();
    void FUN_1410d0310();
    void FUN_1410bf250(const CString* pKey);
    void FUN_1410bf320(const CString* pKey);
    int FUN_1410bf3e0(const CString* pKey);
    unsigned char FUN_1410c3e00(int nKey);
    void FUN_1410c3e40(int nKey, unsigned char v);
    int FUN_1410c3e80(int nKey);
    void FUN_1410c3f10(int nKey, int v);
    void FUN_1410c3f50(int n);
    int FUN_1410c3fa0();
    void GenerateFloorPhysX();
    void FUN_1410c2fe0(void*);
    bool FUN_1410cb900();
    Unk_CMISTree<260>* FUN_1410ce7e0();
    void FUN_1410cf130(void*, void* p);
    Unk_CMISTree<268>* FUN_1410d3360();
    Unk_CMISTree<269>* FUN_1410d3380();
    ATL::CAtlArray<Unk_CMISElem388*>* FUN_1410d4660();
    ATL::CAtlArray<Unk_CMISElem3a8*>* FUN_1410d4920();
    bool FUN_1410d5530();
    void FUN_1410d5700(unsigned __int64 v);
    unsigned __int64 FUN_1410d5730();
    void FUN_1410d5750(unsigned __int64 v);
    unsigned __int64 FUN_1410d5780();
    void FUN_1410d5ab0();
    void FUN_1410d5ae0(int v);
    int FUN_1410d5b00();
    void FUN_1410cb8b0(bool b);
    bool FUN_1410cb920(int n);
    int FUN_1410d2ee0();
    int FUN_1410d2f10();
    void FUN_1410d54f0(bool b);
    int FUN_1410d5550(int nKey);
    void FUN_1410d55d0(int a, int b);
    bool FUN_1410d5640();
    bool FUN_1410d56a0();
    void FUN_1410d57a0(unsigned __int64 key);
    void FUN_1410d5830(unsigned __int64 key);
    bool FUN_1410d58c0(unsigned __int64 key);
    void FUN_1410d5930(Unk_CMISTree<286>* pOut);
    void* FUN_1410c5420(Unk_CMISEntityRef key);
    int FUN_1410cb420(const Unk_CMISEntityRef* pRef);
    int FUN_1410d2730(const Unk_Int3* pPt);
    int FUN_1410d4340(Unk_CubePoint* pOut);
    void FUN_1410c4d80(const Unk_StreamPoint& pt, float fDist);
    bool FUN_1410c2840(Unk_StreamPoint pt, float fDist);
    bool FUN_1410d2340(const Unk_CMISPt2* a, const Unk_CMISPt2* b, float fLimX, float fLimY);
    void FUN_1410caa60(const CString* pKey, int v);
    void FUN_1410c51d0(int nA, int nB, CStringW strName);
    __int64 FUN_1410c8030(int nA, int nB);
    void FUN_1410c4240(int nGroup, int nBlock, const CStringW& strName, __int64 nUnused, __int64 nOwnerId);
    void FUN_1410c44b0(int nGroup, int nBlock, int bFlag);
    void FUN_1410ccc00(int nGroup, int nA, int nB);
    void FUN_1410cd440();
    void FUN_1410c3670();
    void FUN_1410c9710();
    void FUN_1410ca170();
    void FUN_1410cc160(int nKind);
    int FUN_1410c8670(int nGroup, int* pnFlag);
    CStringW FUN_1410c7ce0(int nA, int nB);
    void FUN_1410ce020(MS2Ptr<Cube> spCube);
    void FUN_1410ce1e0(int nNotify, const int* pCount);
    void FUN_1410cef70(const egf::EntityChangeMessage* pMsg, efd::Category cat);
    void FUN_1410cf160(egf::Entity* pEntity);
    void FUN_1410cf5c0(egf::Entity* pEntity);
    int FUN_1410cdd80(Unk_StreamPoint* pFrom, Unk_StreamPoint* pTo, float fDist, Unk_Int3* pOffset);
    int FUN_1410ca900(int nGroup);
    int FUN_1410c88b0(PCBase* pActor);
    int FUN_1410c81c0(int nGroup, int* pnWidth, int* pnHeight, int* pnDepth);
    void FUN_1410c7a50(int nA, int nB, int nState, __int64 nValue);
    int FUN_1410c6980(class Cube* pCube, int nKind, class Unk_CMISItemRef rItem, __int64 nOwner, int nMode);
    int FUN_1410cba80(int nDir, int nField50, Unk_Int3* pCell, Unk_CMISPt3* pPos);
    void FUN_1410ce3f0(Unk_CubeOwnerPtr spOwner);
    void FUN_1410ce4b0(Unk_CubeOwnerPtr spOwner);
    void FUN_1410c5280(int nKey);
    void FUN_1410c5340(Unk_CMISEntityRef ref);
    void FUN_1410c6070();
    void FUN_1410c6820(int nIdx);
    void GenerateAreaPhysX(int n);                  // 0x1410c6100
    int FUN_1410c6b90(unsigned nMask, int* pOutGroup, int nMode, Unk_CMISEntityRef* pOutEnt);
    bool FUN_1410d27c0(__int64 nOwner, int nMode, int* pCount, int* pLimit);
    void FUN_1410cbb40(struct Unk_CMISXformVec* pOut, int nMode, int nGroup, Unk_StreamPoint ptPlayer, Unk_Int3 cell, bool bRot, int nMs);
    Unk_StreamPoint FUN_1410c54a0(Unk_EntRef spEnt);
    void FUN_1410ce560();
    bool FUN_1410c1910(const Unk_Int3& pt, int bDefer);
    bool FUN_1410c06b0(MS2Ptr<Cube> spCube);
    int FUN_1410d3450(CString strName);
    bool FUN_1410c2610(Unk_Int3 pt);
    void FUN_1410c2a90(int nGroup);
    void FUN_1410c3fc0(PCBase* pActor, float* pOutLo, float* pOutHi);
    int FUN_1410d2da0(int nKey, Unk_Int3 pt);
    int FUN_1410d23f0(int nGroup, int nBlock);
    bool FUN_1410d2130(Cube* pCube, int nDir, float fSize, float* pOutXY, Unk_StreamPoint* pOutPt);
    int FUN_1410d2590(Unk_Int3 pt, int nGroup, int nBlock);
    void FUN_1410d4450(__int64 nId, int nIdx, CStringA strName, __int64 nValue);
    void FUN_1410d4710(__int64 nId, int nIdx, CStringA strName, __int64 nValue);
    unsigned __int64 FUN_1410d4fa0();
    unsigned __int64 FUN_1410d50c0();
    void FUN_1410d5190(unsigned __int64* pCubes, unsigned __int64* pOthers);
    void FUN_1410d5350();
    bool FUN_1410c8470(int nA, int nB, int* pState, __int64* pValue);
    bool FUN_1410c80d0(int nGroup);
    int FUN_1410c8580(int nGroup);
    Unk_CubeOwnerMap* FUN_1410c78b0(int nGroup);
    bool FUN_1410c3cd0(int nKey);
    void FUN_1410c2ce0(egf::Entity* pEntity);
    bool FUN_1410be0c0(Unk_Int3 pt, int nGroup, int nFloor, struct Unk_CMISCell56* pVal);
    int FUN_1410ce310();
    int FUN_1410d33a0(int nKey, Unk_StreamPoint* pOut);
    CStringW FUN_1410c7f60(int nA, int nB);
    void FUN_1410d5b20(__int64 nId);
    int FUN_1410c3000();
    void FUN_1410c3020(int v);
    int FUN_1410c3100();
    void FUN_1410c3120(int v);
    int FUN_1410c3140();
    void FUN_1410c3160(int v);
    __int64 FUN_1410c3180();
    void FUN_1410c31a0(__int64 v);
    CStringW FUN_1410c31d0();
    void FUN_1410c3220(const CStringW& s);
    CStringW FUN_1410c3260();
    void FUN_1410c32b0(const CStringW& s);
    int FUN_1410c32f0();
    void FUN_1410c3310(int v);
    int FUN_1410c33f0();
    void FUN_1410c3410(int v);
    int FUN_1410c3430();
    void FUN_1410c3450(int v);
    int FUN_1410c3470();
    void FUN_1410c3490(int v);
    int FUN_1410c34b0();
    void FUN_1410c34d0(int v);
    Unk_CMISFlags3 FUN_1410c34f0();
    void FUN_1410c3530(Unk_CMISFlags3 v);
    void FUN_1410c3560(bool v);
    void FUN_1410c3580(bool v);
    void FUN_1410c35a0(bool v);
    bool FUN_1410c35c0();
    void FUN_1410bb170(struct Unk_CMISPawn* pPawn, int nDx, int nDy, int nDz, struct Unk_CMISNearMap* pMap);
    void FUN_1410c8e40();
    void FUN_1410d0e30(egf::Entity* pEntity, MS2Ptr<Cube> spCube);
    Cube* FUN_1410badf0(int nGroup, struct Unk_CMISPawn* pPawn);
    void FUN_1410c9db0();
    void FUN_1410cb4c0(struct Unk_CMISBlock rec);
    void FUN_1410c8a90();
    bool FUN_1410d2fb0(__int64 nOwnerId, int nCategory, int* pnCount);
    unsigned __int64 FUN_1410d4940();
    int FUN_1410c7110(int* pCell);
    bool FUN_1410c7500(CString* pOut);
    void FUN_1410c93c0();
    void FUN_1410d0000(void* pCtx, MS2Ptr<Cube> spCube);
    void FUN_1410bb610(unsigned nMask, struct Unk_CMISPawn* pPawn, float fDist, struct Unk_CMISRefList* pOut);
    void FUN_1410caf20(Cube* pCube, int nTime);
    void FUN_1410bbf20(int nGroup, const egf::EntityID& id);
    void FUN_1410bf470();
    void FUN_1410ce600(int nItemId, Unk_Int3 pt, int nZ);
    Unk_CMISEntityRef FUN_1410cb1b0();
    void FUN_1410bf610(struct Unk_CMISCubeList* pPlaced, struct Unk_CMISSetRef rSet, struct Unk_CMISCubeList* pOthers);
    void FUN_1410c4850(__int64 nOwner, Unk_Int3 pt, class CubeItemInfo* pInfo, float fRot, int nField50, int nField54,
        unsigned char bField4c, int nUnused, int nFieldD8, Unk_PayloadPtr<class NoticeCubeInfo> spNotice);
    void FUN_1410c4b50(Unk_Int3 pt, bool bKeep);
    void FUN_1410c4e20(__int64 nOwner, Unk_Int3 pt, class CubeItemInfo* pInfo, float fRot, unsigned char bField4c, int nUnused, int nFieldD8);
    bool FUN_1410bca70(__int64 nOwner, Unk_Int3 pt, float fRot, int nField50, int nField54, __int64 nUnused, int nFieldD8);
    void FUN_1410bec60(MS2Ptr<Cube> spCube);
    void FUN_1410d4cb0(int nItemId, bool bFlag);
    bool FUN_1410bd080(__int64 nOwner, Unk_Int3 pt, float fRot, class CubeItemInfo* pInfo, const efd::utf8string& strName,
        int nField50, int nField54, unsigned char bField4c, __int64 nUnused, int nFieldD8, Unk_PayloadPtr<class NoticeCubeInfo> spNotice);
    egf::EntityPtr FUN_1410bc3d0(struct Unk_CMISBlock rec);
    egf::EntityPtr FUN_1410bc7f0(Unk_StreamPoint ptPos, Unk_StreamPoint ptRot, unsigned nIdx, int nItemId);
    bool FUN_1410c3600(int v);
    void FUN_1410c3630(int v);
    int FUN_1410c3650();

    void FUN_1410cab10(Cube* pCube);
    int FUN_1410ba5f0(Unk_Int3 pt, Unk_StreamPoint ptRef);
    void FUN_1410be6e0(MS2Ptr<Cube> spCube);
    int FUN_1410b9e90(__int64 nOwnerId, struct Unk_CMISCubePtrSet* pOut);
    MS2Ptr<Cube> FUN_1410c1330(Unk_StreamPoint ptWorld, float fUnused, class CubeItemInfo* pInfo, int nKind, egf::EntityPtr spEnt, bool bUnused, int nField50);

    // w138
    int FUN_1410b77e0(int nItemId, struct Unk_CMISStr* pOut);
    int FUN_1410cb980(int nItemId);
    void GeneratePhysX(Unk_EntRef spEnt, Unk_StreamPoint pt);
    void FUN_1410c5570(Unk_EntRef spEnt);
    void FUN_1410c3330(CStringW* pOut);
    void FUN_1410c79a0(int nA, int nB);
    void* FUN_1410c7c20(int nA, int nB);
    int FUN_1410cdf60(Unk_Int3* pA, Unk_Int3* pB);
    void FUN_1410c92e0(int nId);
    void FUN_1410cb380(Unk_Int3 pt, const Unk_CMISEntityRef& ref);
    void FUN_1410d4680(ATL::CAtlArray<Unk_CMISHandle3a8>* pSrc);
    void FUN_1410d43c0(ATL::CAtlArray<Unk_CMISHandle388>* pSrc);
    void FUN_1410d59c0(ATL::CAtlArray<MS2Ptr<Cube>>* pOut);

    __int64 f28;                                    // not touched by the ctor
    Unk_CMISTree<256> f30;
    void* f40 = 0;
    Unk_CMISTree<257> f48;
    Unk_CMISTree<258> f58;
    Unk_CMISTree<256> f68;
    Unk_CMISTree<259> f78;
    Unk_CMISTree<260> f88;
    Unk_CMISTree<260> f98;
    Unk_CMISTree<259> fa8;
    Unk_CMISTree<260> fb8;
    Unk_CMISTree<261> fc8;
    Unk_CMISTree<262> fd8;
    Unk_CMISTree<263> fe8;
    Unk_CMISTree<264> ff8;
    Unk_CMISTree<265> f108;
    Unk_CMISTree<266> f118;
    Unk_CMISTree<267> f128;
    Unk_CMISTree<268> f138;
    Unk_CMISTree<269> f148;
    Unk_EntRef f158;
    bool f160;                                      // cleared by FUN_1410b76d0
    Timer t168;
    Unk_CMISTree<270> f1a0;
    int f1b0 = 0, f1b4 = 0, f1b8 = 0;
    __int64 f1c0 = 0;
    CStringW s1c8;
    CStringW s1d0;
    int f1d8 = 0, f1dc = 0, f1e0 = 1;
    Unk_CMISTree<271> f1e8;
    Unk_CMISTree<272> f1f8;
    Unk_PayloadPtr<Unk_CMISObj208> f208;
    Unk_UGCMapPtr f218;
    Unk_CMISTree<273> f228;
    Unk_CMISTree<274> f238;
    bool f248 = false;
    int f24c = 0;
    Timer t250;
    Unk_CMISTree<275> f288;
    Unk_CMISTree<276> f298;
    Unk_CMISTree<277> f2a8;
    Unk_CMISTree<278> f2b8;
    Unk_CMISTree<265> f2c8;
    Unk_CMISEntityRef f2d8;
    Unk_CMISTree<265> f2e0;
    int f2f0 = 0, f2f4 = 0, f2f8 = 0, f2fc = 0;
    Unk_CubePoint p300;
    Unk_CubePoint p30c;
    void* f318[3];
    int f330 = 0;
    Unk_CMISTree<285> f338;
    Unk_CMISTree<279> f348;
    Unk_CMISTree<270> f358;
    Unk_CMISTree<280> f368;
    Unk_CMISTree<281> f378;
    ATL::CAtlArray<Unk_CMISElem388*> a388;
    ATL::CAtlArray<Unk_CMISElem3a8*> a3a8;
    Unk_CMISTree<282> f3c8;
    int f3d8 = 0x12;
    bool f3dc = false;
    Timer t3e0;
    Unk_CMISFlags3 f418;
    unsigned __int64 f420, f428;
    Unk_CMISTree<286> f430;
    Unk_CMISTree<283> f440;
    int f450 = 1;
    ATL::CAtlArray<Unk_CMISElem458*> a458;
    __int64 f478 = 0;
    Unk_PayloadPtr<Unk_CMISObj480> f480;
    int f490 = 0, f494 = 0;
    Unk_CMISTree<284> f498;
};
MS2_CHECK_OFFSET(CubeMapInformationService,f30,0x30);
MS2_CHECK_OFFSET(CubeMapInformationService,f40,0x40);
MS2_CHECK_OFFSET(CubeMapInformationService,f48,0x48);
MS2_CHECK_OFFSET(CubeMapInformationService,f58,0x58);
MS2_CHECK_OFFSET(CubeMapInformationService,f68,0x68);
MS2_CHECK_OFFSET(CubeMapInformationService,f78,0x78);
MS2_CHECK_OFFSET(CubeMapInformationService,f88,0x88);
MS2_CHECK_OFFSET(CubeMapInformationService,f98,0x98);
MS2_CHECK_OFFSET(CubeMapInformationService,fa8,0xa8);
MS2_CHECK_OFFSET(CubeMapInformationService,fb8,0xb8);
MS2_CHECK_OFFSET(CubeMapInformationService,fc8,0xc8);
MS2_CHECK_OFFSET(CubeMapInformationService,fd8,0xd8);
MS2_CHECK_OFFSET(CubeMapInformationService,fe8,0xe8);
MS2_CHECK_OFFSET(CubeMapInformationService,ff8,0xf8);
MS2_CHECK_OFFSET(CubeMapInformationService,f108,0x108);
MS2_CHECK_OFFSET(CubeMapInformationService,f118,0x118);
MS2_CHECK_OFFSET(CubeMapInformationService,f128,0x128);
MS2_CHECK_OFFSET(CubeMapInformationService,f138,0x138);
MS2_CHECK_OFFSET(CubeMapInformationService,f148,0x148);
MS2_CHECK_OFFSET(CubeMapInformationService,f158,0x158);
MS2_CHECK_OFFSET(CubeMapInformationService,f160,0x160);
MS2_CHECK_OFFSET(CubeMapInformationService,t168,0x168);
MS2_CHECK_OFFSET(CubeMapInformationService,f1a0,0x1a0);
MS2_CHECK_OFFSET(CubeMapInformationService,f1b0,0x1b0);
MS2_CHECK_OFFSET(CubeMapInformationService,f1c0,0x1c0);
MS2_CHECK_OFFSET(CubeMapInformationService,s1c8,0x1c8);
MS2_CHECK_OFFSET(CubeMapInformationService,s1d0,0x1d0);
MS2_CHECK_OFFSET(CubeMapInformationService,f1d8,0x1d8);
MS2_CHECK_OFFSET(CubeMapInformationService,f1e8,0x1e8);
MS2_CHECK_OFFSET(CubeMapInformationService,f1f8,0x1f8);
MS2_CHECK_OFFSET(CubeMapInformationService,f208,0x208);
MS2_CHECK_OFFSET(CubeMapInformationService,f218,0x218);
MS2_CHECK_OFFSET(CubeMapInformationService,f228,0x228);
MS2_CHECK_OFFSET(CubeMapInformationService,f238,0x238);
MS2_CHECK_OFFSET(CubeMapInformationService,f248,0x248);
MS2_CHECK_OFFSET(CubeMapInformationService,f24c,0x24c);
MS2_CHECK_OFFSET(CubeMapInformationService,t250,0x250);
MS2_CHECK_OFFSET(CubeMapInformationService,f288,0x288);
MS2_CHECK_OFFSET(CubeMapInformationService,f298,0x298);
MS2_CHECK_OFFSET(CubeMapInformationService,f2a8,0x2a8);
MS2_CHECK_OFFSET(CubeMapInformationService,f2b8,0x2b8);
MS2_CHECK_OFFSET(CubeMapInformationService,f2c8,0x2c8);
MS2_CHECK_OFFSET(CubeMapInformationService,f2d8,0x2d8);
MS2_CHECK_OFFSET(CubeMapInformationService,f2e0,0x2e0);
MS2_CHECK_OFFSET(CubeMapInformationService,f2f0,0x2f0);
MS2_CHECK_OFFSET(CubeMapInformationService,p300,0x300);
MS2_CHECK_OFFSET(CubeMapInformationService,p30c,0x30c);
MS2_CHECK_OFFSET(CubeMapInformationService,f318,0x318);
MS2_CHECK_OFFSET(CubeMapInformationService,f330,0x330);
MS2_CHECK_OFFSET(CubeMapInformationService,f338,0x338);
MS2_CHECK_OFFSET(CubeMapInformationService,f348,0x348);
MS2_CHECK_OFFSET(CubeMapInformationService,f358,0x358);
MS2_CHECK_OFFSET(CubeMapInformationService,f368,0x368);
MS2_CHECK_OFFSET(CubeMapInformationService,f378,0x378);
MS2_CHECK_OFFSET(CubeMapInformationService,a388,0x388);
MS2_CHECK_OFFSET(CubeMapInformationService,a3a8,0x3a8);
MS2_CHECK_OFFSET(CubeMapInformationService,f3c8,0x3c8);
MS2_CHECK_OFFSET(CubeMapInformationService,f3d8,0x3d8);
MS2_CHECK_OFFSET(CubeMapInformationService,f3dc,0x3dc);
MS2_CHECK_OFFSET(CubeMapInformationService,t3e0,0x3e0);
MS2_CHECK_OFFSET(CubeMapInformationService,f418,0x418);
MS2_CHECK_OFFSET(CubeMapInformationService,f420,0x420);
MS2_CHECK_OFFSET(CubeMapInformationService,f430,0x430);
MS2_CHECK_OFFSET(CubeMapInformationService,f440,0x440);
MS2_CHECK_OFFSET(CubeMapInformationService,f450,0x450);
MS2_CHECK_OFFSET(CubeMapInformationService,a458,0x458);
MS2_CHECK_OFFSET(CubeMapInformationService,f478,0x478);
MS2_CHECK_OFFSET(CubeMapInformationService,f480,0x480);
MS2_CHECK_OFFSET(CubeMapInformationService,f490,0x490);
MS2_CHECK_OFFSET(CubeMapInformationService,f498,0x498);
MS2_CHECK_SIZE(CubeMapInformationService,0x4a8);
