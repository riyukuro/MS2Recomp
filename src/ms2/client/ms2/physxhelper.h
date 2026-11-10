// CPhysXHelper (RTTI name): the game-side wrapper around the PhysX scenes owned by the Gamebryo services (ray casts,
// capsule overlap tests, collision-group assignment of prop actors) and its raycast report. Recovered from the exe;
// the original header is unknown.
#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <afx.h>
#include <NxPhysics.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/clockcriticalsection.h"

namespace egf { class Entity; }
class CPhysXHelper;
class NxControllerManager;
template <class T> class TSingleton;
template <> class TSingleton<CPhysXHelper> {
public:
    TSingleton();                                   // 0x14168ab80
    virtual ~TSingleton() { s_instance = 0; }       // 0x14168acd0 (scalar deleting 0x14168aff0)
    static CPhysXHelper* s_instance;                // 0x143ab50b8
};

// Ray cast request/result block of CPhysXHelper::CastRay (0x64 bytes of data, padded to 0x68). The ctor (0x140ad4440) default-constructs
// the two points; the assignment (0x14168ad40) is the implicit member-wise one.
struct Unk_RayCastInfo {
    Unk_RayCastInfo();              // 0x140ad4440 (inline in another obj)
    Vector3 m_origin;       // +0x00
    Vector3 m_dir;          // +0x0c
    float m_maxDist;                // +0x18
    int m_groups;                   // +0x1c collision groups (0x389 by default)
    void* m_20;                     // +0x20 first ignored entity
    void* m_28;                     // +0x28 second ignored entity
    void* m_hitEntity;              // +0x30 entity owning the hit actor
    void* m_hitActor;               // +0x38 hit NxActor
    void* m_hitShape;               // +0x40 hit NxShape
    float m_hitDist;                // +0x48 distance in game units
    Vector3 m_hitPoint;     // +0x4c
    Vector3 m_hitNormal;    // +0x58
};
MS2_CHECK_SIZE(Unk_RayCastInfo, 0x68);

// Report that keeps the closest hit that is not one of the two ignored entities. 0x58 bytes.
class ClosestHitReport : public NxUserRaycastReport {
public:
    ClosestHitReport(NxActor* pIgnoreA, NxActor* pIgnoreB); // 0x14168abb0
    // implicit virtual dtor: 0x14168acf0 (scalar deleting 0x14168b070)
    virtual bool onHit(const NxRaycastHit& hit);            // 0x14168b3a0
    const NxRaycastHit* GetHit() const;              // the stored hit, or 0 when none was found
    bool FUN_14168b120(NxActor* pA, NxActor* pB);           // same actor, or actors owned by the same entity
    NxActor* m_pIgnoreA;            // +0x08
    NxActor* m_pIgnoreB;            // +0x10
    NxRaycastHit m_hit;             // +0x18 (distance at +0x40, -1 while empty)
};
MS2_CHECK_SIZE(ClosestHitReport, 0x58);

class Unk_PhysXLockOwner;           // owner of the physics lock (DAT_143b05988)
class Unk_PhysXSceneHandle;         // scene found by name in the PhysX prop service
namespace egfPhysX { class EntityActorData; } namespace efd { template <typename T> class SmartPointer; }
class Unk_ActorUser;                // NxActor::userData payload

class CPhysXHelper : public TSingleton<CPhysXHelper> {
public:
    CPhysXHelper();                                                                         // 0x141689180
    virtual ~CPhysXHelper();                                                                // 0x141689240 (scalar deleting 0x14168b030)
    Unk_PhysXSceneHandle* GetScene(int nScene);
    bool CastRay(Unk_RayCastInfo* pInfo, const NxGroupsMask* pMask);                  // closest ray cast
    NxActor* GetPhysicsActor(void* pObj);                                                      // the actor of a game object
    egf::Entity* GetEntityFromActor(NxActor* pActor);
    bool HasPhysicsProps(egf::Entity* pEntity);
    void SetActorUserData(efd::SmartPointer<egfPhysX::EntityActorData> spProp);
    void FUN_141689d00(NxActor* pActor, unsigned short nGroup, const NxGroupsMask* pMask);
    void SetEntityCollisionGroup(egf::Entity* pEntity, unsigned short nGroup, const NxGroupsMask* pMask, int bRefresh);
    NxScene* GetNxScene();
    float FUN_14168a210();
    int RayCastFromPoint(Vector3 ptFrom, Vector3& ptHit, Vector3 ptDir, float fLen, int nMask);
    int RayCastFixedDirection(const Vector3& ptFrom, Vector3& ptHit, Unk_RayCastInfo* pInfo, float fLen,
                      Vector3* pNormal, int nMask);
    int GetGroundDistance(const efd::Point3& ptFrom, float* pDist, float fLen);   // no exe caller copies
    void FUN_14168a540(int);
    void Unlock();
    void CacheScenes();
    void ClearScenes();
    void* GetControllerManager();
    bool CheckCapsuleOverlap(const Vector3* pPoint);
    int FUN_14168a9b0(void* pEntity, Vector3 ptFrom);   // by value: the exe callers pass a copy
    NxControllerManager* m_pControllerMgr;      // +0x08
    Unk_PhysXLockOwner* m_pLock;                // +0x10
    Unk_PhysXSceneHandle* m_apScene[2];         // +0x18 default / item scene
};
MS2_CHECK_SIZE(CPhysXHelper, 0x28);
