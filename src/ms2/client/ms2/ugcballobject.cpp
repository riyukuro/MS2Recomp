// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ugcballobject.h.
// MS2-UNIT: ?\ugcballobject.cpp
// MS2-RANGE: 0x140dece80-0x140def070 .text$mn
// MS2-RANGE: 0x1400d67b0-0x1400d6940 .text$di
// MS2-RANGE: 0x142ca5f10-0x142ca5fa0 .text$yd
// MS2-PIN: ?GetClassDesc@CUGCBallObject@@UEBAPEBVClassInfo@efd@@XZ 0x140deea30
// MS2-PIN: ?TypeCast@CUGCBallObject@@UEBA_NIPEAPEAX@Z 0x140deeba0
// MS2-PIN: ?TypeCast@CUGCBallObject@@UEBA_NIPEAPEBX@Z 0x140deebf0
// MS2-PIN: ??_7CUGCBallObject@@6BIBase@efd@@@ 0x142e3dde0
// MS2-PIN: ??_7CUGCBallObject@@6BCallbackObject@NiActorManager@@@ 0x142e3dfb0
// MS2-PIN: ??_7NxSphereShapeDesc@@6B@ 0x142e3ddc0
// MS2-PIN: ??0Unk_UbVec3@@QEAA@AEBVNiPoint3@@@Z 0x14027dcf0
// MS2-PIN: ??0Unk_UbVec3@@QEAA@AEBVPoint3@efd@@@Z 0x14027dcf0
// C3: the point writer is EncodeVector3 (pointer form) everywhere
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcballobject.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcballobject.h"
#include "worldservice.h"
#include "physxhelper.h"
#include <NiPhysXTypes.h>
#include <efd/MemHint.h>
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- out-of-unit callees ----
class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper
extern __int64 DAT_143ab2828;                                       // my character id
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
void EncodeVector3(COutPacket* pPacket, const Vector3* pPt);    // writes the three floats of a point
struct Unk_UtilFloat3;
void FUN_140710590(COutPacket& packet);                             // send
struct Unk_UbPoint { float x, y, z; };                         // plain three-float point (no ctor)
struct Unk_PayloadPoint { Unk_PayloadPoint(); float values[3]; }; struct Unk_PayloadReader { template<class T> T ReadPoint(); };   // C3: unit_1401f9eb0's packet reader (ReadPoint 0x140204500); was Unk_UbPointReader
NxVec3 Point3ToNxVec3(const efd::Point3& kPt);               // Point3 -> NxVec3 (C3: was const Vector3&)
Vector3 FUN_141b6e150(const Unk_UtilFloat3* pVec);          // NxVec3 -> Point3 (the definer's signature)
struct Unk_UbBoxView                                                // CBoxCollision vtable view: vfunc_3 takes its points by implicit conversion (NiPoint3(const efd::Point3&), 0x14027dcf0)
{
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(NiPoint3 ptPos, NiPoint3 ptDir, float fScale);   // 0x140ada620 place by angles
};

// A temporary point viewed as the efd::Point3 the callee takes by value: cl binds the temporary straight to the
// parameter, as in the exe. clang-cl refuses an rvalue reinterpret_cast, so it goes through a helper there.
#ifdef __clang__
template <class T> static const efd::Point3& Unk_UbPt3(const T& k) { return reinterpret_cast<const efd::Point3&>(k); }
#define MS2_UB_POINT(expr) Unk_UbPt3(expr)
#else
#define MS2_UB_POINT(expr) reinterpret_cast<const efd::Point3&>(expr)
#endif

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CUGCBallObject);

// ---- the unit's header statics ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140dece80
CUGCBallObject::CUGCBallObject()
    : m_nOwner(0)
    , m_pActor(0)
    , m_pMaterial(0)
    , m_vVel(0.0f, 0.0f, 0.0f)
    , m_nLastSend(0)
    , m_fRadius(60.0f)
{
}

// @0x140decf50
CUGCBallObject::~CUGCBallObject()
{
    ReleaseActor();
}

// @0x140decfc0
int CUGCBallObject::Init(__int64 nOwner, int nObjectId, Unk_UbPoint kPt, float fRadius)
{
    m_nOwner = nOwner;
    m_str88 = "MS2VibrateNoPhysX";
    SetModelPath(CString("urn:gamebryo-scenegraph:ugc_fi_prop_ball_A01"));
    SetObjectId(nObjectId);
    vfunc_19(MS2_UB_POINT(Vector3(kPt.x, kPt.y, kPt.z)));
    vfunc_21(NiPoint3::ZERO);
    m_fRadius = fRadius;
    if (m_fRadius < 60.0f)
        m_fRadius = 60.0f;
    if (300.0f < m_fRadius)
        m_fRadius = 300.0f;
    SetScale(m_fRadius / 75.0f);
    Vector3 kBox(m_fRadius * 2.0f, m_fRadius * 2.0f, m_fRadius * 2.0f);
    m_spBox.AssignRaw(new CBoxCollision);
    m_spBox->m_ptBox = kBox;
    m_spBox->m_kColor = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    m_spBox->vfunc_4();
    reinterpret_cast<Unk_UbBoxView*>(m_spBox.operator->())->vfunc_3(MS2_UB_POINT(Vector3(kPt.x, kPt.y, kPt.z)), static_cast<const efd::Point3&>(NiPoint3::ZERO), 1.0f);
    return 1;
}

// @0x140ded420
int CUGCBallObject::FUN_140ded420(Unk_UbTag* pTag, void* pShape)
{
    if (m_pActor == 0)
        return 1;
    GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->GetLocalPlayer());
    if (pPlayer == 0)
        return 1;
    reinterpret_cast<Unk_UbBoxView*>(m_spBox.operator->())->vfunc_3(static_cast<const efd::Point3&>(static_cast<const NiPoint3&>(vfunc_18())), static_cast<const efd::Point3&>(NiPoint3::ZERO), 1.0f);
    if (CBaseCollision::Intersect((class CBaseCollision*)(pShape), (class CBaseCollision*)(m_spBox.get())) == 0)
        return 1;
    efd::Point3 kDir = static_cast<const NiPoint3&>(pPlayer->vfunc_18()) - static_cast<const NiPoint3&>(vfunc_18());
    efd::Point3::UnitizeVector(kDir);
    Vector3 kForce = pTag->m_ptPos;
    kForce.z = kForce.z + 0.75f;
    reinterpret_cast<efd::Point3&>(kForce) *= 1500.0f;
    {
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.Encode1(7);
        packet.Encode1(3);
        packet.Encode4(GetObjectId());
        EncodeVector3(&packet, &kForce);
        EncodeVector3(&packet, reinterpret_cast<const Vector3*>(&kDir));
        FUN_140710590(packet);
    }
    return 1;
}

// @0x140ded6d0
void CUGCBallObject::FUN_140ded6d0()
{
    if (m_pActor == 0)
        return;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pActor->wakeUp(0.39999998f);   // the exe constant is 0x3ecccccc, one ULP below 0.4f
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}

// @0x140ded740
void CUGCBallObject::CreateActor()
{
    if (m_pActor != 0)
        return;
    NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
    if (pScene == 0)
        return;
    NxMaterialDesc kMatDesc;
    kMatDesc.restitution = 1.0f;
    kMatDesc.dynamicFriction = 0.1f;
    m_pMaterial = pScene->createMaterial(kMatDesc);
    NxVec3 kPos;
    NiPhysXTypes::NiPoint3ToNxVec3(vfunc_18(), kPos);
    NxBodyDesc* pBodyDesc = 0;
    NxBodyDesc kBodyDesc;
    kBodyDesc.mass = 1.0f;
    pBodyDesc = &kBodyDesc;
    NxSphereShapeDesc kSphereDesc;
    kSphereDesc.radius = m_fRadius / 100.0f;
    kSphereDesc.materialIndex = m_pMaterial->getMaterialIndex();
    kSphereDesc.groupsMask.bits0 = 0xffffffff;
    kSphereDesc.shapeFlags &= ~(NX_SF_CLOTH_TWOWAY | NX_SF_SOFTBODY_TWOWAY);
    NxActorDesc kActorDesc;
    kActorDesc.body = pBodyDesc;
    kActorDesc.shapes.pushBack(&kSphereDesc);
    kActorDesc.globalPose.t = kPos;
    kActorDesc.globalPose.t = kActorDesc.globalPose.t * 0.01f;
    kActorDesc.globalPose.t.z -= (m_fRadius / 100.0f) * 0.5f;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pActor = pScene->createActor(kActorDesc);
    if (m_pActor != 0)
    {
        m_pActor->setName("UGCBall");
        NxU32 nShapes = m_pActor->getNbShapes();
        NxShape* const* ppShapes = m_pActor->getShapes();
        for (NxU32 i = 0; i < nShapes; i++)
        {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(10);
        }
        m_pActor->userData = GetEntity();
    }
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}

// @0x140dedaf0
void CUGCBallObject::ReleaseActor()
{
    if (((class CPhysXHelper*)GetPhysXHelper()) == 0)
        return;
    NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
    if (pScene == 0)
        return;
    if (m_pActor != 0)
    {
        ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
        pScene->releaseActor(*m_pActor);
        WorldService::GetInstance()->FUN_141bc8e00();
        ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
        m_pActor = 0;
    }
    if (m_pMaterial != 0)
    {
        ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
        pScene->releaseMaterial(*m_pMaterial);
        WorldService::GetInstance()->FUN_141bc8e00();
        ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
        m_pMaterial = 0;
    }
}

// @0x140dedc00
int CUGCBallObject::vfunc_11()
{
    CreateActor();
    return 1;
}

// @0x140dedc30
void CUGCBallObject::vfunc_14()
{
    ReleaseActor();
    GameObject::vfunc_14();
}

// @0x140dedc60
void CUGCBallObject::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    if (m_pActor == 0)
        return;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxVec3 kPos = m_pActor->getGlobalPosition();
    if (m_nOwner == DAT_143ab2828 && m_vVel.magnitudeSquared() > 1.1920929e-07f)
    {
        kPos += m_vVel * 0.9f;
        m_vVel *= 0.9f;
        m_pActor->setGlobalPosition(kPos);
    }
    NxQuat kQuat = m_pActor->getGlobalOrientationQuat();
    NxVec3 kLinVel = m_pActor->getLinearVelocity();
    NxVec3 kAngVel = m_pActor->getAngularVelocity();
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
    efd::Point3 kNiPos;
    efd::Point3 kNiRot;
    NiPhysXTypes::NxVec3ToNiPoint3(kPos * 100.0f, reinterpret_cast<NiPoint3&>(kNiPos));
    FUN_140dee3e0(kQuat, kNiRot);
    vfunc_19(kNiPos);
    vfunc_21(kNiRot);
    SetScale(m_fRadius / 75.0f);
    unsigned int nTick;
    if (m_nOwner == DAT_143ab2828 && (nTick = GetTickCountMs2(), nTick - m_nLastSend > 100))
    {
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.Encode1(7);
        packet.Encode1(2);
        packet.Encode4(GetObjectId());
        EncodeVector3(&packet, reinterpret_cast<const Vector3*>(&kNiPos));
        EncodeVector3(&packet, &static_cast<const Vector3&>(FUN_141b6e150(reinterpret_cast<const Unk_UtilFloat3*>(&kLinVel))));
        EncodeVector3(&packet, &static_cast<const Vector3&>(FUN_141b6e150(reinterpret_cast<const Unk_UtilFloat3*>(&kAngVel))));
        FUN_140710590(packet);
        m_nLastSend = nTick;
    }
}

// @0x140dee050
void CUGCBallObject::FUN_140dee050(CInPacket* pPacket)
{
    __int64 nSender = pPacket->ReadInt64();
    if (m_nOwner == nSender && nSender == DAT_143ab2828)
        return;
    if (m_pActor == 0)
        return;
    NxVec3 kPos = Point3ToNxVec3(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pPacket->FUN_1407140d0()))) / 100.0f;
    NxVec3 kVel = Point3ToNxVec3(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pPacket->FUN_1407140d0())));
    NxVec3 kAngVel = Point3ToNxVec3(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pPacket->FUN_1407140d0())));
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxVec3 kGlobal = m_pActor->getGlobalPosition();
    m_vVel += kGlobal - kPos;
    m_pActor->setLinearVelocity(kVel);
    m_pActor->setAngularVelocity(kAngVel);
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}

// @0x140dee220
void CUGCBallObject::FUN_140dee220(CInPacket* pPacket)
{
    __int64 nId = pPacket->ReadInt64();
    if (nId != DAT_143ab2828)
        return;
    if (m_pActor == 0)
        return;
    Vector3 kForce = pPacket->FUN_1407140d0();
    Vector3 kAt = pPacket->FUN_1407140d0();
    Vector3 kPos = (reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18())) - (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(kAt) * m_fRadius)) / 100.0f));
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pActor->addForceAtPos(Point3ToNxVec3(reinterpret_cast<const efd::Point3&>(kForce)), Point3ToNxVec3(reinterpret_cast<const efd::Point3&>(kPos)), NX_FORCE, true);
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}

// @0x140dee3e0
void CUGCBallObject::FUN_140dee3e0(const NxQuat& kQuat, efd::Point3& kEuler)
{
    NiQuaternion kQ;
    NiPhysXTypes::NxQuatToNiQuaternion(kQuat, kQ);
    NiMatrix3 kRot;
    kQ.ToRotation(kRot);
    kRot.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
    kEuler *= -57.295776f;
}

// @0x140dee4a0
void FUN_140dee4a0(CInPacket& packet)
{
    WorldService* pWorld = WorldService::GetInstance();
    switch (packet.ReadUInt8())
    {
    case 0:
    {
        int nObjectId = packet.ReadInt32();
        __int64 nOwner = packet.ReadInt64();
        Unk_PayloadPoint kPos = reinterpret_cast<Unk_PayloadReader*>(&packet)->ReadPoint<Unk_PayloadPoint>();
        float fRadius = packet.ReadFloat();
        CUGCBallObject* pBall = new (efd::MemHint(efd::MemHint::NONE)) CUGCBallObject;
        if (!pBall->Init(nOwner, nObjectId, reinterpret_cast<Unk_UbPoint&>(kPos), fRadius))
            break;
        if (!pWorld->OnObjectCreated(pBall, 0, 1))
            break;
        break;
    }
    case 2:
    {
        int nObjectId = packet.ReadInt32();
        CUGCBallObject* pBall = FUN_140dee810(reinterpret_cast<GameObject*>(pWorld->FindObjectById(nObjectId)));
        if (!pBall)
            break;
        pBall->FUN_140dee050(&packet);
        break;
    }
    case 3:
    {
        int nObjectId = packet.ReadInt32();
        CUGCBallObject* pBall = FUN_140dee810(reinterpret_cast<GameObject*>(pWorld->FindObjectById(nObjectId)));
        if (!pBall)
            break;
        pBall->FUN_140dee220(&packet);
        break;
    }
    case 1:
    {
        int nObjectId = packet.ReadInt32();
        pWorld->FUN_141bbbcf0(nObjectId, 0);
        break;
    }
    }
}

// @0x140dee810
CUGCBallObject* FUN_140dee810(GameObject* pObj)
{
    void* pValue = 0;
    if (pObj != 0 && pObj->TypeCast(0x6200073, &pValue))
        return static_cast<CUGCBallObject*>(pValue);
    else
        return 0;
}

// @0x140deef50
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
