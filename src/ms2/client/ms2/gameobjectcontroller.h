// gameobjectcontroller.h - the PhysX capsule character controller of an actor (PCBase +0x150, created by PCBase::vfunc_10).
// Owns the NxCapsuleController (made through CPhysXHelper's NxControllerManager), its hit report, the restitution-1 material
// of the controller's shape, the egfPhysX::EntityActorData tagged on the controller actor, and the fall / jump / lift
// vertical motion of the actor. Recovered from unit_14123f5b0 (0x14123f2d0-0x141241810). The class has no vftable and no
// RTTI: the name GameObjectController is invented after its hit report class (GameObjectControllerHitReport), the header
// name follows it. Units that predate this header use their own views (pcbase.cpp's Unk_PCBaseBody and the FUN_<va>
// free-function externs in the state units); the methods keep the FUN_<va> names those callers use.
#pragma once
#include <afx.h>
#include <NxPhysics.h>
#include "../../../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs/NxCharacter/include/NxCapsuleController.h"
#include "../../../../third_party/physx284/PFiles/NVIDIA Corporation/NVIDIA PhysX SDK/v2.8.4_win/SDKs/NxCharacter/include/NxControllerManager.h"
#include <efd/Point3.h>
#include <egfPhysX/EntityActorData.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "gameobjectcontrollerhitreport.h"

class NiPoint3;
class PCBase;

// 0xf8 bytes (PCBase::vfunc_10 allocates 0xf8).
class GameObjectController
{
public:
    GameObjectController();                                                         // 0x14123f2d0
    ~GameObjectController();                                                        // 0x14123f460

    // Creates the capsule controller at kPos (game units, feet) for an actor fHeight tall with radius fRadius.
    void FUN_14123f5b0(PCBase* pOwner, egf::Entity* pEntity, efd::Point3 kPos, float fHeight, float fRadius);   // raw entity: the exe builds the EntityActorData SmartPointer itself
    void FUN_14123fa70(NxActor* pActor);                                            // give the shape a restitution-1 material
    void FUN_14123fbf0(NxCollisionGroup nGroup);                                    // collision group of every shape
    void FUN_14123fd30(unsigned int nGroups);                                       // the active groups (and groups mask)
    efd::Point3 FUN_14123fd90();                                                    // feet position (game units)
    void FUN_14123fe70(efd::Point3 kPos);                                           // place the feet at kPos
    void FUN_14123ff50();                                                           // NxController::reportSceneChanged
    void FUN_14123ff80(efd::Point3 kDisp, unsigned int nExcludeGroups);             // move by kDisp (game units)
    void FUN_141240520(float fRadius, float fHeight);                               // resize the capsule
    void FUN_141240610(float fHeight, efd::Point3 kVelocity, float fUnused);        // start a jump fHeight high
    void SetKVelocity(efd::Point3 kVelocity);                                      // the horizontal velocity
    void FUN_141240730();                                                           // stop jumping (land)
    int IsJumping();                                                            // jumping
    int FUN_1412407a0();                                                            // still rising
    efd::Point3 FUN_1412407f0(float fDelta, int bMove);                             // vertical step of this frame
    static float FUN_141240c40(bool bDefault);                                      // gravity (scene z, else the default)
    void FUN_141240cb0(float fDuration, float fPeak, float fBase);                  // start a lift (knock-up)
    void FUN_141240d70();                                                           // end the lift
    int IsLift();                                                            // lifting
    int IsLiftFalling();                                                            // the lift is past its peak
    efd::Point3 FUN_141240df0();                                                     // the last hit normal
    NxActor* FUN_141240e70();                                                       // the controller actor
    NxU32 GetCollisionFlags();                                                          // collision flags of the last move
    int FUN_141240ef0();                                                            // falling time (ms)
    GameObjectControllerHitReport* FUN_141240f20();                                 // the hit report
    int FUN_141240f40();                                                            // standing on the ground
    void FUN_141240fa0();                                                           // reset the fall timer
    efd::Point3 GetKVelocity();                                                    // the horizontal velocity
    float FUN_141241000();                                                          // capsule radius (PhysX units)
    void FUN_141241070();                                                           // forget the collision flags
    float FUN_141241090();                                                          // jump apex time (0 unless jumping)
    bool FUN_1412410c0(efd::Point3 kPos, float fOffset);                            // would the capsule overlap at kPos
    int FUN_1412412b0();                                                            // in the air (falling or descending)
    float GetCenterOffset();                                                          // feet-to-centre offset

    NxMaterial* m_pMaterial;                        // +0x00 the shape material (restitution 1)
    NxCapsuleController* m_pController;             // +0x08
    NxControllerManager* m_pManager;                // +0x10 CPhysXHelper::FUN_14168a750
    GameObjectControllerHitReport m_hitReport;      // +0x18
    NxGroupsMask m_groupsMask;                      // +0x50 all four words = m_nGroups
    NxU32 m_nGroups;                                // +0x60 active groups (0x389)
    NxU32 m_nCollisionFlags;                        // +0x64 NXCC_COLLISION_* of the last move
    float m_fCenterOffset;                          // +0x68 -(capsule height / 2 + radius)
    int m_bJumping;                                 // +0x6c
    float m_fJumpSpeed;                             // +0x70 initial vertical speed
    efd::Point3 m_kVelocity;                        // +0x74 horizontal velocity of the jump / fall
    int m_bLift;                                    // +0x80
    float m_fLiftTime;                              // +0x84
    float m_fLiftHeight;                            // +0x88 current lift height
    float m_fLiftDuration;                          // +0x8c
    float m_fLiftPeak;                              // +0x90
    float m_fLiftBase;                              // +0x94
    int m_bLiftFalling;                             // +0x98
    egfPhysX::EntityActorDataPtr m_spActorData;     // +0xa0 NxActor::userData of the controller actor
    Timer m_kFallTimer;                             // +0xa8
    NxU32 m_nIgnoreGroups;                          // +0xe0 groups left out of the next moves (0x10 after a ceiling hit)
    float m_fJumpTime;                              // +0xe4
    float m_fJumpHeight;                            // +0xe8
    float m_fJumpApex;                              // +0xec time of the jump apex (2.0)
    PCBase* m_pOwner;                               // +0xf0
};
MS2_CHECK_OFFSET(GameObjectController, m_hitReport, 0x18);
MS2_CHECK_OFFSET(GameObjectController, m_nGroups, 0x60);
MS2_CHECK_OFFSET(GameObjectController, m_spActorData, 0xa0);
MS2_CHECK_OFFSET(GameObjectController, m_kFallTimer, 0xa8);
MS2_CHECK_OFFSET(GameObjectController, m_pOwner, 0xf0);
MS2_CHECK_SIZE(GameObjectController, 0xf8);
