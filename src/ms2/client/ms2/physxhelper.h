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
    Unk_StreamPoint m_origin;       // +0x00
    Unk_StreamPoint m_dir;          // +0x0c
    float m_maxDist;                // +0x18
    int m_groups;                   // +0x1c collision groups (0x389 by default)
    void* m_20;                     // +0x20 first ignored entity
    void* m_28;                     // +0x28 second ignored entity
    void* m_hitEntity;              // +0x30 entity owning the hit actor
    void* m_hitActor;               // +0x38 hit NxActor
    void* m_hitShape;               // +0x40 hit NxShape
    float m_hitDist;                // +0x48 distance in game units
    Unk_StreamPoint m_hitPoint;     // +0x4c
    Unk_StreamPoint m_hitNormal;    // +0x58
};
MS2_CHECK_SIZE(Unk_RayCastInfo, 0x68);

// Report that keeps the closest hit that is not one of the two ignored entities. 0x58 bytes.
class ClosestHitReport : public NxUserRaycastReport {
public:
    ClosestHitReport(NxActor* pIgnoreA, NxActor* pIgnoreB); // 0x14168abb0
    // implicit virtual dtor: 0x14168acf0 (scalar deleting 0x14168b070)
    virtual bool onHit(const NxRaycastHit& hit);            // 0x14168b3a0
    const NxRaycastHit* FUN_14168b0f0() const;              // the stored hit, or 0 when none was found
    bool FUN_14168b120(NxActor* pA, NxActor* pB);           // same actor, or actors owned by the same entity
    NxActor* m_pIgnoreA;            // +0x08
    NxActor* m_pIgnoreB;            // +0x10
    NxRaycastHit m_hit;             // +0x18 (distance at +0x40, -1 while empty)
};
MS2_CHECK_SIZE(ClosestHitReport, 0x58);

class Unk_PhysXLockOwner;           // owner of the physics lock (DAT_143b05988)
class Unk_PhysXSceneHandle;         // scene found by name in the PhysX prop service
class Unk_PhysPropPtr;
class Unk_ActorUser;                // NxActor::userData payload

class CPhysXHelper : public TSingleton<CPhysXHelper> {
public:
    CPhysXHelper();                                                                         // 0x141689180
    virtual ~CPhysXHelper();                                                                // 0x141689240 (scalar deleting 0x14168b030)
    Unk_PhysXSceneHandle* FUN_1416892a0(int nScene);
    bool CastRay(Unk_RayCastInfo* pInfo, const NxGroupsMask* pMask);                  // closest ray cast
    NxActor* FUN_1416897d0(void* pObj);                                                      // the actor of a game object
    egf::Entity* FUN_141689970(NxActor* pActor);
    bool FUN_141689a10(egf::Entity* pEntity);
    void FUN_141689ac0(Unk_PhysPropPtr pProp);
    void FUN_141689d00(NxActor* pActor, unsigned short nGroup, const NxGroupsMask* pMask);
    void FUN_141689ec0(egf::Entity* pEntity, unsigned short nGroup, const NxGroupsMask* pMask, int bRefresh);
    NxScene* FUN_14168a1c0();
    float FUN_14168a210();
    bool FUN_14168a230(Unk_StreamPoint ptFrom, Unk_StreamPoint& ptHit, Unk_StreamPoint ptDir, float fLen, int nMask);
    int FUN_14168a310(const Unk_StreamPoint& ptFrom, Unk_StreamPoint& ptHit, Unk_RayCastInfo* pInfo, float fLen,
                      Unk_StreamPoint* pNormal, int nMask);
    int FUN_14168a450(Unk_StreamPoint ptFrom, float* pDist, float fLen);
    void FUN_14168a540(int);
    void FUN_14168a570();
    void FUN_14168a5a0();
    void FUN_14168a710();
    void* FUN_14168a750();
    bool FUN_14168a770(const Unk_StreamPoint* pPoint);
    int FUN_14168a9b0(void* pEntity, const Unk_StreamPoint& ptFrom);
    NxControllerManager* m_pControllerMgr;      // +0x08
    Unk_PhysXLockOwner* m_pLock;                // +0x10
    Unk_PhysXSceneHandle* m_apScene[2];         // +0x18 default / item scene
};
MS2_CHECK_SIZE(CPhysXHelper, 0x28);
