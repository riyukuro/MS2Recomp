// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See physxhelper.h.
// MS2-UNIT: client\ms2\physxhelper.cpp
// MS2-RANGE: 0x1400fb920-0x1400fbab0 .text$di
// MS2-RANGE: 0x141689180-0x14168b4a0 .text$mn
// MS2-PIN: ??1NxRay@@QEAA@XZ 0x14168ad10
// MS2-PIN: ??4NxRaycastHit@@QEAAAEAU0@AEBU0@@Z 0x14168ae50
// MS2-PIN: ??8?$SmartPointer@VEntity@egf@@@efd@@QEBA_NAEBV01@@Z 0x14168af30
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\physxhelper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <math.h>
#include <float.h>
// NxMath::sqrt calls ::sqrtf through the exe's IAT (0x14168b480).
#define sqrtf(x) __imp_sqrtf(x)
extern "C" float (__cdecl* __imp_sqrtf)(float);

#include "physxhelper.h"
#include <efd/ILogger.h>
#include <efd/LoggerMacros.h>
#include <efd/ServiceManager.h>
#include <egf/Entity.h>
#include <ecrPhysX/PropService.h>
#include <NiPhysXProp.h>
#include <NiPhysXPropDesc.h>
#include <NiPhysXActorDesc.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"


// Header statics, in the original initialization order. These are private
// constants and a condition table, with no registration into exe registries.
#include "ms2/placeholder/unk_1402a9d70.h"
class Unk_1401cd100 {
public:
    Unk_1401cd100(void*);
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_1401cd100, 8);

// @0x1400fb920
static CString s_physSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400fb9e0
static CString s_physSkill("skill");
// @0x1400fba10
static CString s_physStun("stun");
// @0x1400fba40
static Unk_1401cd100 s_physNone(NULL);
// @0x1400fba60
static Unk_1402a9d70 s_physCondition(17, 0.75f, 0.25f, 2.25f, 10);

namespace egfPhysX { class SceneService; }

// ---- unit-local views of exe types ----

// The application service (class id 0x06100001); only its NxUserAllocator is read.
class Unk_PhysXApp : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100001;
};
class Unk_PhysGameObj;
class Unk_PhysRpgActor;
class Unk_PhysBody;
// The world service (class id 0x06100002).
class Unk_PhysWorldSvc : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100002;
    Unk_PhysGameObj* FUN_141bd0f50(void* pObj);
};
// The application object; the service manager handle sits at +8.
struct Unk_PhysAppHost { char m_pad[8]; char m_manager[1]; };
// The user data payload of a prop actor.
class Unk_PhysPropObj
{
public:
    efd::SmartPointer<egf::Entity> FUN_14163b4e0();         // the owning entity
};
// The lock holder of CPhysXHelper::m_pLock; the lock itself sits at +0xf8.
class Unk_PhysXLockOwner
{
public:
    void FUN_14168b240();                                   // unlock
    void FUN_14168b270();                                   // lock
    char m_pad[0xf8];
    char m_lock[8];
};
// Smart pointer to a prop object (the same shape as worldservice_1's Unk_WsA_PropPtr).
class Unk_PhysPropPtr
{
public:
    ~Unk_PhysPropPtr();                                     // 0x140ae16b0
    Unk_PhysPropObj* FUN_140ae1920() const;                 // the object
    Unk_PhysPropObj* FUN_14168afe0() const;                 // the object (this unit's copy)
private:
    Unk_PhysPropObj* m_p;
};
Unk_PhysXApp* FUN_14168ab00(efd::ServiceManager* pServices);
Unk_PhysWorldSvc* FUN_14168ab40(efd::ServiceManager* pServices);
void FUN_140d86210(char* pLock);
void FUN_140d852c0(char* pLock);
// NxVec3 <-> game point conversions (member-style calls with the result in the hidden return slot).
struct Unk_PhysVecView
{
    Unk_StreamPoint FUN_140deea90() const;                  // NxVec3 to game point
    float x, y, z;
};

Unk_PhysAppHost* FUN_14086d260();
efd::ServiceManager* FUN_140af8310(char* pManager);
NxUserAllocator* FUN_141489fd0(Unk_PhysXApp* pApp);
Unk_PhysXLockOwner* FUN_1414a5890();
egfPhysX::SceneService* FUN_1411d14f0(efd::ServiceManager* pServices);
NxScene* FUN_141503cc0(egfPhysX::SceneService* pService, int nScene);
ecrPhysX::PropService* FUN_14120a240(efd::ServiceManager* pServices);
Unk_PhysXSceneHandle* FUN_141293c40(ecrPhysX::PropService* pService, const efd::utf8string& kName);
efd::utf8string FUN_1414d7990(const efd::utf8string& kName);
CPhysXHelper* FUN_1409f7ca0();
Unk_PhysRpgActor* FUN_1409ffd30(Unk_PhysGameObj* p);
Unk_PhysBody* FUN_14166d220(Unk_PhysRpgActor* pActor);
NxActor* FUN_141240e70(Unk_PhysBody* p);
int FUN_1409a8f90(const float* pf);
bool FUN_14028d470(float f, float g);
float FUN_14028d3a0(float f);
float FUN_140a38cd0(float f);
void FUN_1408a20a0(egf::Entity*, unsigned, bool*);
extern char DAT_143b059e8;
efd::ISystemService* FUN_1401cd040(char*);
NxActor* FUN_1410c5420(efd::ISystemService*, egf::EntityID);
void* FUN_1403ed2d0();
void FUN_141bc8e00(void*);
extern int DAT_143ae2b30;
extern const Unk_StreamPoint g_143b01a60;
extern const Unk_StreamPoint g_143a08cf8;
struct Unk_PointView
{
    NxVec3 FUN_140ae1df0() const;                           // game point to NxVec3 (this = the point, result in the hidden slot)
};

// The PhysX character kit entry points are DLL imports of the exe (IAT slots 0x142ccec98 / 0x142ccec90).
extern "C" __declspec(dllimport) NxControllerManager* NxCreateControllerManager(NxUserAllocator*);
extern "C" __declspec(dllimport) void NxReleaseControllerManager(NxControllerManager*);

CPhysXHelper* TSingleton<CPhysXHelper>::s_instance = 0;

#define PHYSX_FILE MS2_THIS_FILE

// Unk_RayCastInfo::Unk_RayCastInfo (0x140ad4440) is defined by unit_140ad1860.cpp (MS2-RANGE owner).
// @0x141689180
CPhysXHelper::CPhysXHelper()
{
    efd::ServiceManager* pServices = FUN_140af8310(FUN_14086d260()->m_manager);
    Unk_PhysXApp* pApp = FUN_14168ab00(pServices);
    m_pControllerMgr = NxCreateControllerManager(FUN_141489fd0(pApp));
    m_pLock = FUN_1414a5890();
    for (int i = 0; i < 2; i++)
        m_apScene[i] = 0;
}
// @0x141689240
CPhysXHelper::~CPhysXHelper()
{
    NxReleaseControllerManager(m_pControllerMgr);
    m_pControllerMgr = 0;
    m_pLock = 0;
}
// @0x1416892a0
Unk_PhysXSceneHandle* CPhysXHelper::FUN_1416892a0(int nScene)
{
    if (m_apScene[nScene] == 0)
        FUN_14168a5a0();
    return m_apScene[nScene];
}
// @0x1416892f0
// MS2-FUNCTIONAL: call-order/spill shape differs from exe
bool CPhysXHelper::FUN_1416892f0(Unk_RayCastInfo* pInfo, const NxGroupsMask* pMask)
{
    NxScene* pScene = FUN_14168a1c0();
    if (pScene == 0)
        return false;
    NxRay ray;
    if (FUN_1409a8f90(&pInfo->m_maxDist) == 0)
    {
        EE_LOG_AT(0x12, 1, ("CPhysXHelper::CastRay::m_maxDist"), PHYSX_FILE, 0x32);
        throw 13;
    }
    float fMaxDist = pInfo->m_maxDist;
    float fScale = FUN_14168a210();
    if (FUN_14028d470(fMaxDist, 0) == 0)
        fMaxDist = fMaxDist * (1.0f / fScale);
    else
        fMaxDist = FLT_MAX;
    ray.orig = reinterpret_cast<const Unk_PointView&>(pInfo->m_origin).FUN_140ae1df0();
    ray.dir = reinterpret_cast<const Unk_PointView&>(pInfo->m_dir).FUN_140ae1df0();
    ray.orig *= 1.0f / fScale;
    ray.dir.normalize();
    if (ray.dir == NxVec3(0, 0, 0))
        return false;
    NxActor* pIgnoreA = 0;
    NxActor* pIgnoreB = 0;
    FUN_1409f7ca0()->FUN_14168a540(0);
    if (pInfo->m_20 != 0)
        pIgnoreA = FUN_1416897d0(pInfo->m_20);
    if (pInfo->m_28 != 0)
        pIgnoreB = FUN_1416897d0(pInfo->m_28);
    ClosestHitReport report(pIgnoreA, pIgnoreB);
    pScene->raycastAllShapes(ray, report, NX_ALL_SHAPES, pInfo->m_groups, fMaxDist, 0x52, pMask);
    const NxRaycastHit* pHit = report.FUN_14168b0f0();
    if (pHit != 0)
    {
        NxActor* pActor = &pHit->shape->getActor();
        pInfo->m_hitEntity = FUN_141689970(pActor);
        pInfo->m_hitActor = pActor;
        pInfo->m_hitShape = pHit->shape;
        pInfo->m_hitDist = pHit->distance * fScale;
        NxVec3 vPoint = pHit->worldImpact * fScale;
        pInfo->m_hitPoint = reinterpret_cast<const Unk_PhysVecView&>(vPoint).FUN_140deea90();
        pInfo->m_hitNormal = reinterpret_cast<const Unk_PhysVecView&>(pHit->worldNormal).FUN_140deea90();
    }
    FUN_1409f7ca0()->FUN_14168a570();
    return pHit != 0;
}
#ifndef MS2_HOOK_DLL
// @0x1416897d0
// MS2-FUNCTIONAL: static lock EH shape differs from exe
NxActor* CPhysXHelper::FUN_1416897d0(void* pObj)
{
    NxActor* pActor = 0;
    if (DAT_143ae2b30 == 0)
    {
        Unk_PhysWorldSvc* pWorld = FUN_14168ab40(FUN_140af8310(FUN_14086d260()->m_manager));
        Unk_PhysRpgActor* pRpg = FUN_1409ffd30(pWorld->FUN_141bd0f50(pObj));
        if (pRpg != 0)
            pActor = FUN_141240e70(FUN_14166d220(pRpg));
    }
    else
    {
        static CLockCriticalSection s_lock;     // 0x143ae3968
        Unk_PhysWorldSvc* pWorld = FUN_14168ab40(FUN_140af8310(FUN_14086d260()->m_manager));
        if (Unk_LockGuard guard = s_lock)
        {
        }
        else
        {
            Unk_PhysRpgActor* pRpg = FUN_1409ffd30(pWorld->FUN_141bd0f50(pObj));
            if (pRpg != 0)
                pActor = FUN_141240e70(FUN_14166d220(pRpg));
        }
    }
    return pActor;
}
#endif
// @0x141689970
// MS2-FUNCTIONAL: EH unwind shape differs from exe
egf::Entity* CPhysXHelper::FUN_141689970(NxActor* pActor)
{
    if (pActor == 0)
        return 0;
    else if (pActor->userData == 0)
        return 0;
    else
    {
        Unk_PhysPropObj* pObj = static_cast<Unk_PhysPropObj*>(pActor->userData);
        if (pObj == 0)
            return 0;
        return pObj->FUN_14163b4e0().data();
    }
}
// @0x141689a10
// MS2-FUNCTIONAL: EH unwind shape differs from exe
bool CPhysXHelper::FUN_141689a10(egf::Entity* pEntity)
{
    if (pEntity == 0)
        return false;
    bool bCube = false;
    FUN_1408a20a0(pEntity, 0x38141815, &bCube);
    if (bCube)
        return true;
    ecrPhysX::PropService* pProps = FUN_14120a240(FUN_140af8310(FUN_14086d260()->m_manager));
    if (pProps == 0)
        return false;
    return pProps->GetNumProps(pEntity->GetEntityID()) != 0;
}
// @0x141689ac0
// MS2-FUNCTIONAL: temporary lifetime shape differs from exe
void CPhysXHelper::FUN_141689ac0(Unk_PhysPropPtr pProp)
{
    ecrPhysX::PropService* pProps = FUN_14120a240(FUN_140af8310(FUN_14086d260()->m_manager));
    if (pProps != 0)
    {
        unsigned uiProps = pProps->GetNumProps(pProp.FUN_14168afe0()->FUN_14163b4e0()->GetEntityID());
        for (unsigned i = 0; i < uiProps; i++)
        {
            NiPhysXProp* pPhysXProp = pProps->GetPropAt(pProp.FUN_14168afe0()->FUN_14163b4e0()->GetEntityID(), i);
            if (pPhysXProp != 0)
            {
                NiPhysXPropDesc* pSnapshot = pPhysXProp->GetSnapshot();
                if (pSnapshot != 0)
                {
                    unsigned uiActors = pSnapshot->GetActorCount();
                    if (uiActors != 0)
                    {
                        for (unsigned a = 0; a < uiActors; a++)
                        {
                            NiPhysXActorDesc* pDesc = pSnapshot->GetActorAt(a);
                            if (pDesc != 0)
                            {
                                NxActor* pActor = pDesc->GetActor();
                                if (pActor != 0)
                                    pActor->userData = pProp.FUN_140ae1920();
                            }
                        }
                    }
                }
            }
        }
    }
}
// @0x141689d00
// MS2-FUNCTIONAL: codegen shape differs from exe
void CPhysXHelper::FUN_141689d00(NxActor* pActor, unsigned short nGroup, const NxGroupsMask* pMask)
{
    if (pActor != 0)
    {
        pActor->setGroup(nGroup);
        unsigned uiShapes = pActor->getNbShapes();
        NxShape* const* ppShapes = pActor->getShapes();
        for (unsigned i = 0; i < uiShapes; i++)
        {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(nGroup);
            NxGroupsMask kMask;
            if (nGroup == 0 || nGroup == 7 || nGroup == 8 || nGroup == 9 || nGroup == 10)
            {
                if (pMask == 0)
                    kMask.bits0 = 0xffffffff;
                else
                    kMask = *pMask;
            }
            else if (nGroup == 1)
            {
                if (pMask == 0)
                    kMask.bits0 = 4;
                else
                    kMask = *pMask;
            }
            pShape->setGroupsMask(kMask);
        }
    }
}
// @0x141689ec0
// MS2-FUNCTIONAL: codegen shape differs from exe
void CPhysXHelper::FUN_141689ec0(egf::Entity* pEntity, unsigned short nGroup, const NxGroupsMask* pMask, int bRefresh)
{
    if (pEntity == 0)
        return;
    bool bCube = false;
    FUN_1408a20a0(pEntity, 0x38141815, &bCube);
    if (!bCube)
    {
        ecrPhysX::PropService* pProps = FUN_14120a240(FUN_140af8310(FUN_14086d260()->m_manager));
        if (pProps != 0)
        {
            unsigned uiProps = pProps->GetNumProps(pEntity->GetEntityID());
            for (unsigned i = 0; i < uiProps; i++)
            {
                NiPhysXProp* pPhysXProp = pProps->GetPropAt(pEntity->GetEntityID(), i);
                if (pPhysXProp != 0)
                {
                    NiPhysXPropDesc* pSnapshot = pPhysXProp->GetSnapshot();
                    if (pSnapshot != 0)
                    {
                        unsigned uiActors = pSnapshot->GetActorCount();
                        if (uiActors != 0)
                        {
                            FUN_14168a540(0);
                            for (unsigned a = 0; a < uiActors; a++)
                            {
                                NiPhysXActorDesc* pDesc = pSnapshot->GetActorAt(a);
                                if (pDesc != 0)
                                {
                                    NxActor* pActor = pDesc->GetActor();
                                    if (pActor != 0)
                                        FUN_141689d00(pActor, nGroup, pMask);
                                }
                            }
                            FUN_14168a570();
                        }
                    }
                }
            }
        }
    }
    else
    {
        efd::SmartPointer<efd::ISystemService> spService(FUN_1401cd040(&DAT_143b059e8));
        NxActor* pActor = FUN_1410c5420(spService, pEntity->GetEntityID());
        if (pActor != 0)
        {
            FUN_14168a540(0);
            FUN_141689d00(pActor, nGroup, pMask);
            FUN_14168a570();
        }
    }
    if (bRefresh != 0)
        FUN_141bc8e00(FUN_1403ed2d0());
}
// @0x14168a1c0
NxScene* CPhysXHelper::FUN_14168a1c0()
{
    efd::ServiceManager* pServices = FUN_140af8310(FUN_14086d260()->m_manager);
    egfPhysX::SceneService* pScenes = FUN_1411d14f0(pServices);
    return FUN_141503cc0(pScenes, 0);
}
// @0x14168a210
float CPhysXHelper::FUN_14168a210()
{
    return 100.0f;
}
// @0x14168a230
// MS2-FUNCTIONAL: minor codegen shape differs from exe
bool CPhysXHelper::FUN_14168a230(Unk_StreamPoint ptFrom, Unk_StreamPoint& ptHit, Unk_StreamPoint ptDir, float fLen, int nMask)
{
    int nDefaultGroups = 0x389;
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = ptFrom;
    kInfo.m_dir = ptDir;
    kInfo.m_maxDist = fLen;
    kInfo.m_groups = nMask != 0 ? nMask : nDefaultGroups;
    kInfo.m_20 = 0;
    kInfo.m_28 = 0;
    bool bHit = FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0);
    if (bHit)
        ptHit = kInfo.m_hitPoint;
    return bHit;
}
// @0x14168a310
int CPhysXHelper::FUN_14168a310(const Unk_StreamPoint& ptFrom, Unk_StreamPoint& ptHit, Unk_RayCastInfo* pInfo, float fLen,
                                Unk_StreamPoint* pNormal, int nMask)
{
    int nDefaultGroups = 0x389;
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = ptFrom;
    kInfo.m_dir = g_143a08cf8.FUN_1409f7960();
    kInfo.m_maxDist = fLen;
    kInfo.m_dir.FUN_140968990();
    kInfo.m_groups = nMask != 0 ? nMask : nDefaultGroups;
    kInfo.m_20 = 0;
    kInfo.m_28 = 0;
    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0))
    {
        if (pInfo != 0)
            *pInfo = kInfo;
        ptHit = kInfo.m_hitPoint;
        if (pNormal != 0)
            *pNormal = kInfo.m_hitNormal;
        return 1;
    }
    return 0;
}
// @0x14168a450
int CPhysXHelper::FUN_14168a450(Unk_StreamPoint ptFrom, float* pDist, float fLen)
{
    Unk_RayCastInfo kInfo;
    kInfo.m_origin = ptFrom;
    kInfo.m_dir = g_143a08cf8.FUN_1409f7960();
    kInfo.m_maxDist = fLen;
    kInfo.m_dir.FUN_140968990();
    kInfo.m_groups = 0x389;
    kInfo.m_20 = 0;
    kInfo.m_28 = 0;
    if (FUN_1409f7ca0()->FUN_1416892f0(&kInfo, 0) && pDist != 0)
    {
        *pDist = FUN_140a38cd0(kInfo.m_hitPoint.z - ptFrom.z);
        return 1;
    }
    return 0;
}
// @0x14168a540
void CPhysXHelper::FUN_14168a540(int)
{
    m_pLock->FUN_14168b270();
}
// @0x14168a570
void CPhysXHelper::FUN_14168a570()
{
    m_pLock->FUN_14168b240();
}
// @0x14168a5a0
void CPhysXHelper::FUN_14168a5a0()
{
    efd::ServiceManager* pServices = FUN_140af8310(FUN_14086d260()->m_manager);
    ecrPhysX::PropService* pProps = FUN_14120a240(pServices);
    if (pProps != 0)
    {
        efd::utf8string kName("PhysXDefaultSceneName");
        kName = FUN_1414d7990(kName);
        m_apScene[0] = FUN_141293c40(pProps, kName);
        kName = "PhysXItemSceneName";
        kName = FUN_1414d7990(kName);
        m_apScene[1] = FUN_141293c40(pProps, kName);
    }
}
// @0x14168a710
void CPhysXHelper::FUN_14168a710()
{
    for (unsigned i = 0; i < 2; i++)
        m_apScene[i] = 0;
}
// @0x14168a750
void* CPhysXHelper::FUN_14168a750()
{
    return m_pControllerMgr;
}
// @0x14168a770
// MS2-FUNCTIONAL: codegen shape differs from exe
bool CPhysXHelper::FUN_14168a770(const Unk_StreamPoint* pPoint)
{
    if (FUN_14168a1c0() == 0)
    {
        MS2_ASSERT_AT(499, 0);
        return false;
    }
    float fFootOffset = 52.5f;
    float fHeight = FUN_14028d3a0(55.0f);
    float fRadius = FUN_14028d3a0(25.0f);
    FUN_1409f7ca0()->FUN_14168a540(0);
    NxVec3 vCenter;
    vCenter.x = FUN_14028d3a0(pPoint->x);
    vCenter.y = FUN_14028d3a0(pPoint->y);
    vCenter.z = FUN_14028d3a0(pPoint->z + fFootOffset);
    NxCapsule kCapsule;
    kCapsule.p0.x = vCenter.x;
    kCapsule.p1.x = vCenter.x;
    kCapsule.p0.y = vCenter.y;
    kCapsule.p1.y = vCenter.y;
    kCapsule.p0.z = vCenter.z - fHeight * 0.5f;
    kCapsule.p1.z = vCenter.z + fHeight * 0.5f;
    kCapsule.radius = fRadius;
    bool bOverlap = FUN_14168a1c0()->checkOverlapCapsule(kCapsule, NX_ALL_SHAPES, 0x289, 0);
    FUN_1409f7ca0()->FUN_14168a570();
    return bOverlap;
}
// @0x14168a9b0
// MS2-FUNCTIONAL: codegen shape differs from exe
int CPhysXHelper::FUN_14168a9b0(void* pEntity, const Unk_StreamPoint& ptFrom)
{
    Unk_RayCastInfo kInfo;
    Unk_StreamPoint ptHit = g_143b01a60;
    return FUN_1409f7ca0()->FUN_14168a310(ptFrom, ptHit, &kInfo, 0, 0, 0) != 0 && kInfo.m_hitEntity == pEntity;
}
// @0x14168aa60
Unk_PhysXApp* FUN_14168aa60(efd::ISystemService* pService)
{
    void* pValue = 0;
    if (pService != 0 && pService->TypeCast(Unk_PhysXApp::CLASS_ID, &pValue))
        return (Unk_PhysXApp*)pValue;
    else
        return 0;
}
// @0x14168aab0
Unk_PhysWorldSvc* FUN_14168aab0(efd::ISystemService* pService)
{
    void* pValue = 0;
    if (pService != 0 && pService->TypeCast(Unk_PhysWorldSvc::CLASS_ID, &pValue))
        return (Unk_PhysWorldSvc*)pValue;
    else
        return 0;
}
// @0x14168ab00
Unk_PhysXApp* FUN_14168ab00(efd::ServiceManager* pServices)
{
    efd::ISystemService* pService = pServices->GetSystemService(Unk_PhysXApp::CLASS_ID);
    Unk_PhysXApp* pApp = FUN_14168aa60(pService);
    return pApp;
}
// @0x14168ab40
Unk_PhysWorldSvc* FUN_14168ab40(efd::ServiceManager* pServices)
{
    efd::ISystemService* pService = pServices->GetSystemService(Unk_PhysWorldSvc::CLASS_ID);
    Unk_PhysWorldSvc* pWorld = FUN_14168aab0(pService);
    return pWorld;
}
// @0x14168ab80
inline TSingleton<CPhysXHelper>::TSingleton() { s_instance = static_cast<CPhysXHelper*>(this); }
// @0x14168abb0
ClosestHitReport::ClosestHitReport(NxActor* pIgnoreA, NxActor* pIgnoreB)
{
    m_pIgnoreA = pIgnoreA;
    m_pIgnoreB = pIgnoreB;
    m_hit.distance = -1.0f;
}
// @0x14168afe0
Unk_PhysPropObj* Unk_PhysPropPtr::FUN_14168afe0() const { return m_p; }
// @0x14168b0f0
const NxRaycastHit* ClosestHitReport::FUN_14168b0f0() const
{
    if (m_hit.distance < 0.0f)
        return 0;
    return &m_hit;
}
// @0x14168b120
// MS2-FUNCTIONAL: SmartPointer temporary shape differs from exe
bool ClosestHitReport::FUN_14168b120(NxActor* pA, NxActor* pB)
{
    if (pA == 0 || pB == 0)
        return false;
    if (pA == pB)
        return true;
    if (pA->userData != 0 && pB->userData != 0)
    {
        efd::SmartPointer<egf::Entity> spB = static_cast<Unk_PhysPropObj*>(pB->userData)->FUN_14163b4e0();
        efd::SmartPointer<egf::Entity> spA = static_cast<Unk_PhysPropObj*>(pA->userData)->FUN_14163b4e0();
        if (spA == spB)
            return true;
    }
    return false;
}
// @0x14168b240
void Unk_PhysXLockOwner::FUN_14168b240() { FUN_140d86210(m_lock); }
// @0x14168b270
void Unk_PhysXLockOwner::FUN_14168b270() { FUN_140d852c0(m_lock); }
// @0x14168b3a0
// MS2-FUNCTIONAL: codegen shape differs from exe
bool ClosestHitReport::onHit(const NxRaycastHit& kHit)
{
    if (kHit.shape != 0 && (m_hit.distance < 0.0f || kHit.distance < m_hit.distance))
    {
        NxActor* pActor = &kHit.shape->getActor();
        if (pActor != 0 && !FUN_14168b120(pActor, m_pIgnoreA) && !FUN_14168b120(pActor, m_pIgnoreB))
            m_hit = kHit;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416892A0, CPhysXHelper, FUN_1416892a0, 61, 0x19AF2D89);
MS2_REPLACE_METHOD(0x14168A1C0, CPhysXHelper, FUN_14168a1c0, 63, 0x5C1A7CCA);
MS2_REPLACE_METHOD(0x14168A210, CPhysXHelper, FUN_14168a210, 14, 0xE4E8D95F);
MS2_REPLACE_METHOD(0x14168A310, CPhysXHelper, FUN_14168a310, 302, 0x52623978);
MS2_REPLACE_METHOD(0x14168A450, CPhysXHelper, FUN_14168a450, 232, 0x8C3C8D12);
MS2_REPLACE_METHOD(0x14168A540, CPhysXHelper, FUN_14168a540, 32, 0xEC94BD02);
MS2_REPLACE_METHOD(0x14168A570, CPhysXHelper, FUN_14168a570, 28, 0xC37B47B6);
MS2_REPLACE_METHOD(0x14168A5A0, CPhysXHelper, FUN_14168a5a0, 349, 0x880CE577);
MS2_REPLACE_METHOD(0x14168A710, CPhysXHelper, FUN_14168a710, 56, 0xB4C7EA23);
MS2_REPLACE_METHOD(0x14168A750, CPhysXHelper, FUN_14168a750, 15, 0x5B8A7339);
MS2_REPLACE_METHOD(0x14168B0F0, ClosestHitReport, FUN_14168b0f0, 33, 0xE0D29AB9);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb4170-0x142cb4220 .text$yd
