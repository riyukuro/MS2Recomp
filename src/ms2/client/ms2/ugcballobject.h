// ugcballobject.h - CUGCBallObject (efd RTTI "CUGCBallObject", class id 0x06200073): the kickable ball of the UGC map
// ("ugc_fi_prop_ball_A01"). A GameObject whose position is driven by a PhysX sphere actor on the owner's client; the
// owner streams position / velocity to the other clients (packet type 0x90, sub-type 2), a kick is sent as a force
// (sub-type 3). Owning unit: ?\ugcballobject.cpp (0x140dece80-0x140def070). Header name assumed; member names invented.
// Size 0x180 (operator delete size in the scalar deleting dtor). vftable 0x142e3dde0 (57 slots), CallbackObject
// vftable 0x142e3dfb0. efd: TypeCast 0x140deebf0/0x140deeba0, GetClassDesc 0x140deea30, ??_G 0x140dee990, ClassInfo
// 0x143ac4f40 (setup 0x140deeb40, registration 0x1400d67b0).
#pragma once
#include <NxPhysics.h>
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/functioncubeobject.h"    // CBoxCollision
#include "ms2/placeholder/nipoint3.h"

class CInPacket;
class WorldService;

// The tag (trigger) object the ball is tested against: only its position is read.
struct Unk_UbTag
{
    MS2_LAYOUT_FRIEND;
    void* m_pad_00[12];
    Vector3 m_ptPos;                                // +0x60
};
MS2_CHECK_OFFSET(Unk_UbTag, m_ptPos, 0x60);

class CUGCBallObject : public GameObject
{
    EE_DECLARE_CLASS1(CUGCBallObject, 0x06200073, GameObject);

public:
    CUGCBallObject();                                       // 0x140dece80
    virtual ~CUGCBallObject();                              // 0x140decf50

    virtual int vfunc_11();                                 // 11 0x140dedc00 creates the physics actor
    virtual void vfunc_14();                                // 14 0x140dedc30 releases the physics actor
    virtual void vfunc_53(float f);                         // 53 0x140dedc60 per-frame update / send

    int FUN_140decfc0(__int64 nOwner, int nObjectId, const Vector3* pPos, float fRadius);   // 0x140decfc0
    int FUN_140ded420(Unk_UbTag* pTag, void* pShape);       // 0x140ded420 kick the player standing in the range
    void FUN_140ded6d0();                                   // 0x140ded6d0 wake the actor up
    void FUN_140ded740();                                   // 0x140ded740 create the material and the sphere actor
    void FUN_140dedaf0();                                   // 0x140dedaf0 release the actor and the material
    void FUN_140dee050(CInPacket* pPacket);                 // 0x140dee050 received state of the owner's ball
    void FUN_140dee220(CInPacket* pPacket);                 // 0x140dee220 received kick
    void FUN_140dee3e0(const NxQuat& kQuat, efd::Point3& kEuler);   // 0x140dee3e0 quaternion -> euler angles (degrees)

public:
    MS2_LAYOUT_FRIEND;
    __int64 m_nOwner;                                       // +0x140 character id of the client that simulates the ball
    NxActor* m_pActor;                                      // +0x148
    NxMaterial* m_pMaterial;                                // +0x150
    NxVec3 m_vVel;                                          // +0x158 smoothed correction velocity
    MS2Ptr<CBoxCollision> m_spBox;                          // +0x168 debug box
    unsigned int m_nLastSend;                               // +0x178 tick of the last state packet
    float m_fRadius;                                        // +0x17c 60..300
};
MS2_CHECK_SIZE(CUGCBallObject, 0x180);
MS2_CHECK_OFFSET(CUGCBallObject, m_nOwner, 0x140);
MS2_CHECK_OFFSET(CUGCBallObject, m_vVel, 0x158);
MS2_CHECK_OFFSET(CUGCBallObject, m_spBox, 0x168);
MS2_CHECK_OFFSET(CUGCBallObject, m_fRadius, 0x17c);

void FUN_140dee4a0(CInPacket& packet);                       // 0x140dee4a0 packet 0x90 handler
CUGCBallObject* FUN_140dee810(GameObject* pObj);            // 0x140dee810 cast to CUGCBallObject
