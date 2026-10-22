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
CPhysXHelper* FUN_1409f7ca0();                                      // TSingleton<CPhysXHelper>::GetInstance
extern __int64 DAT_143ab2828;                                       // my character id
unsigned int FUN_140869420();                                       // tick count (ms)
void FUN_14020af60(COutPacket* pPacket, const Unk_StreamPoint* pPt);    // writes the three floats of a point
void FUN_140710590(COutPacket& packet);                             // send
Unk_StreamPoint FUN_140204500(CInPacket* pPacket);                  // reads a point (three floats)
NxVec3 FUN_141b6e0e0(const Unk_StreamPoint& kPt);                   // Point3 -> NxVec3
Unk_StreamPoint FUN_141b6e150(const NxVec3& kVec);                  // NxVec3 -> Point3
char FUN_1409ff0d0(void* pShape, CBoxCollision* pBox);              // does the box touch the shape

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
    FUN_140dedaf0();
}

// @0x140decfc0
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
int CUGCBallObject::FUN_140decfc0(__int64 nOwner, int nObjectId, const Unk_StreamPoint* pPos, float fRadius)
{
    m_nOwner = nOwner;
    m_str88 = "MS2VibrateNoPhysX";
    FUN_14123bb80(CString("urn:gamebryo-scenegraph:ugc_fi_prop_ball_A01"));
    FUN_14123c5a0(nObjectId);
    efd::Point3 kPos(pPos->x, pPos->y, pPos->z);
    vfunc_19(kPos);
    vfunc_21(NiPoint3::ZERO);
    m_fRadius = fRadius;
    if (m_fRadius < 60.0f)
        m_fRadius = 60.0f;
    if (300.0f < m_fRadius)
        m_fRadius = 300.0f;
    FUN_14123c280(m_fRadius / 75.0f);
    Unk_StreamPoint kBox(m_fRadius * 2.0f, m_fRadius * 2.0f, m_fRadius * 2.0f);
    m_spBox.AssignRaw(new CBoxCollision);
    m_spBox->m_ptBox = kBox;
    m_spBox->m_kColor = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    m_spBox->vfunc_4();
    CBoxCollision* pBox = m_spBox.operator->();
    Unk_NiPoint3 kZero(reinterpret_cast<const Unk_StreamPoint&>(NiPoint3::ZERO));
    Unk_NiPoint3 kAt(Unk_StreamPoint(pPos->x, pPos->y, pPos->z));
    pBox->vfunc_3(reinterpret_cast<Unk_StreamPoint&>(kAt), reinterpret_cast<Unk_StreamPoint&>(kZero), 1.0f);
    return 1;
}

// @0x140ded420
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
int CUGCBallObject::FUN_140ded420(Unk_UbTag* pTag, void* pShape)
{
    if (m_pActor != 0)
    {
        WorldService* pWorld = WorldService::GetInstance();
        GameObject* pPlayer = static_cast<GameObject*>(pWorld->FUN_141bd0cc0());
        if (pPlayer != 0)
        {
            CBoxCollision* pBox = m_spBox.operator->();
            Unk_NiPoint3 kZero(reinterpret_cast<const Unk_StreamPoint&>(NiPoint3::ZERO));
            Unk_NiPoint3 kAt(reinterpret_cast<const Unk_StreamPoint&>(static_cast<const NiPoint3&>(vfunc_18())));
            pBox->vfunc_3(reinterpret_cast<Unk_StreamPoint&>(kAt), reinterpret_cast<Unk_StreamPoint&>(kZero), 1.0f);
            if (FUN_1409ff0d0(pShape, m_spBox.get()) != 0)
            {
                NiPoint3 kDir = static_cast<const NiPoint3&>(pPlayer->vfunc_18()) - static_cast<const NiPoint3&>(vfunc_18());
                efd::Point3::UnitizeVector(kDir);
                Unk_StreamPoint kForce = pTag->m_ptPos;
                kForce.z = kForce.z + 0.75f;
                kForce.FUN_140ad0c10(1500.0f);
                COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
                packet.Encode1(7);
                packet.Encode1(3);
                packet.Encode4(FUN_14123c580());
                FUN_14020af60(&packet, &kForce);
                FUN_14020af60(&packet, reinterpret_cast<const Unk_StreamPoint*>(&kDir));
                FUN_140710590(packet);
            }
        }
    }
    return 1;
}

// @0x140ded6d0
void CUGCBallObject::FUN_140ded6d0()
{
    if (m_pActor == 0)
        return;
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pActor->wakeUp(0.4f);
    FUN_1409f7ca0()->FUN_14168a570();
}

// @0x140ded740
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
void CUGCBallObject::FUN_140ded740()
{
    if (m_pActor == 0)
    {
        NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
        if (pScene != 0)
        {
            NxMaterialDesc kMatDesc;
            kMatDesc.restitution = 1.0f;
            kMatDesc.dynamicFriction = 0.1f;
            m_pMaterial = pScene->createMaterial(kMatDesc);
            NxVec3 kPos;
            NiPhysXTypes::NiPoint3ToNxVec3(vfunc_18(), kPos);
            NxBodyDesc kBodyDesc;
            kBodyDesc.mass = 1.0f;
            NxSphereShapeDesc kSphereDesc;
            kSphereDesc.radius = m_fRadius / 100.0f;
            kSphereDesc.materialIndex = m_pMaterial->getMaterialIndex();
            kSphereDesc.groupsMask.bits0 = 0xffffffff;
            kSphereDesc.shapeFlags &= ~(NX_SF_CLOTH_TWOWAY | NX_SF_SOFTBODY_TWOWAY);
            NxActorDesc kActorDesc;
            kActorDesc.body = &kBodyDesc;
            kActorDesc.shapes.pushBack(&kSphereDesc);
            kActorDesc.globalPose.t = kPos;
            kActorDesc.globalPose.t = kActorDesc.globalPose.t * 0.01f;
            kActorDesc.globalPose.t.z -= (m_fRadius / 100.0f) * 0.5f;
            FUN_1409f7ca0()->FUN_14168a540(0);
            m_pActor = pScene->createActor(kActorDesc);
            if (m_pActor != 0)
            {
                m_pActor->setName("UGCBall");
                NxU32 nShapes = m_pActor->getNbShapes();
                NxShape* const* ppShapes = m_pActor->getShapes();
                for (NxU32 i = 0; i < nShapes; i++)
                    ppShapes[i]->setGroup(10);
                m_pActor->userData = FUN_14123c410();
            }
            FUN_1409f7ca0()->FUN_14168a570();
        }
    }
}

// @0x140dedaf0
void CUGCBallObject::FUN_140dedaf0()
{
    if (FUN_1409f7ca0() == 0)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (pScene == 0)
        return;
    if (m_pActor != 0)
    {
        FUN_1409f7ca0()->FUN_14168a540(0);
        pScene->releaseActor(*m_pActor);
        WorldService::GetInstance()->FUN_141bc8e00();
        FUN_1409f7ca0()->FUN_14168a570();
        m_pActor = 0;
    }
    if (m_pMaterial != 0)
    {
        FUN_1409f7ca0()->FUN_14168a540(0);
        pScene->releaseMaterial(*m_pMaterial);
        WorldService::GetInstance()->FUN_141bc8e00();
        FUN_1409f7ca0()->FUN_14168a570();
        m_pMaterial = 0;
    }
}

// @0x140dedc00
int CUGCBallObject::vfunc_11()
{
    FUN_140ded740();
    return 1;
}

// @0x140dedc30
void CUGCBallObject::vfunc_14()
{
    FUN_140dedaf0();
    GameObject::vfunc_14();
}

// @0x140dedc60
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
void CUGCBallObject::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    if (m_pActor != 0)
    {
        FUN_1409f7ca0()->FUN_14168a540(0);
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
        FUN_1409f7ca0()->FUN_14168a570();
        efd::Point3 kNiPos;
        efd::Point3 kNiRot;
        NiPhysXTypes::NxVec3ToNiPoint3(kPos * 100.0f, reinterpret_cast<NiPoint3&>(kNiPos));
        FUN_140dee3e0(kQuat, kNiRot);
        vfunc_19(kNiPos);
        vfunc_21(kNiRot);
        FUN_14123c280(m_fRadius / 75.0f);
        unsigned int nTick;
        if (m_nOwner == DAT_143ab2828 && (nTick = FUN_140869420(), nTick - m_nLastSend > 100))
        {
            COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
            packet.Encode1(7);
            packet.Encode1(2);
            packet.Encode4(FUN_14123c580());
            FUN_14020af60(&packet, reinterpret_cast<const Unk_StreamPoint*>(&kNiPos));
            Unk_StreamPoint kLin = FUN_141b6e150(kLinVel);
            FUN_14020af60(&packet, &kLin);
            Unk_StreamPoint kAng = FUN_141b6e150(kAngVel);
            FUN_14020af60(&packet, &kAng);
            FUN_140710590(packet);
            m_nLastSend = nTick;
        }
    }
}

// @0x140dee050
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
void CUGCBallObject::FUN_140dee050(CInPacket* pPacket)
{
    __int64 nSender = static_cast<CInputStream*>(pPacket)->vfunc_o8_4();
    if ((m_nOwner != nSender || nSender != DAT_143ab2828) && m_pActor != 0)
    {
        NxVec3 kPos = FUN_141b6e0e0(pPacket->FUN_1407140d0()) / 100.0f;
        NxVec3 kVel = FUN_141b6e0e0(pPacket->FUN_1407140d0());
        NxVec3 kAngVel = FUN_141b6e0e0(pPacket->FUN_1407140d0());
        FUN_1409f7ca0()->FUN_14168a540(0);
        m_vVel += m_pActor->getGlobalPosition() - kPos;
        m_pActor->setLinearVelocity(kVel);
        m_pActor->setAngularVelocity(kAngVel);
        FUN_1409f7ca0()->FUN_14168a570();
    }
}

// @0x140dee220
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
void CUGCBallObject::FUN_140dee220(CInPacket* pPacket)
{
    if (static_cast<CInputStream*>(pPacket)->vfunc_o8_4() == DAT_143ab2828 && m_pActor != 0)
    {
        Unk_StreamPoint kForce = pPacket->FUN_1407140d0();
        Unk_StreamPoint kAt = pPacket->FUN_1407140d0();
        Unk_StreamPoint kScaled = kAt.FUN_14097fc90(m_fRadius);
        Unk_StreamPoint kScaled2 = kScaled.FUN_140ae9180(100.0f);
        Unk_StreamPoint kPos = reinterpret_cast<const Unk_StreamPoint&>(static_cast<const NiPoint3&>(vfunc_18())).FUN_140965c40(kScaled2);
        FUN_1409f7ca0()->FUN_14168a540(0);
        m_pActor->addForceAtPos(FUN_141b6e0e0(kForce), FUN_141b6e0e0(kPos), NX_FORCE, true);
        FUN_1409f7ca0()->FUN_14168a570();
    }
}

// @0x140dee3e0
void CUGCBallObject::FUN_140dee3e0(const NxQuat& kQuat, efd::Point3& kEuler)
{
    NiQuaternion kQ;
    NiPhysXTypes::NxQuatToNiQuaternion(kQuat, kQ);
    NiMatrix3 kRot;
    kQ.ToRotation(kRot);
    kRot.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
    kEuler *= -57.29578f;
}

// @0x140dee4a0
// MS2-FUNCTIONAL: frame layout/temps differ from exe (reloc-order and stack offsets); behaviour-equivalent
void FUN_140dee4a0(CInPacket& packet)
{
    WorldService* pWorld = WorldService::GetInstance();
    CInputStream* pStream = &packet;
    char cMode = pStream->vfunc_o8_1();
    if (cMode == 0)
    {
        int nObjectId = pStream->vfunc_o8_3();
        __int64 nOwner = pStream->vfunc_o8_4();
        Unk_StreamPoint kPos = FUN_140204500(&packet);
        float fRadius = pStream->vfunc_o8_5();
        CUGCBallObject* pBall = new (efd::MemHint(efd::MemHint::NONE)) CUGCBallObject;
        if (pBall->FUN_140decfc0(nOwner, nObjectId, &kPos, fRadius) != 0)
            pWorld->FUN_141bbb1e0(pBall, 0, 1);
    }
    else if (cMode == 1)
    {
        int nObjectId = pStream->vfunc_o8_3();
        pWorld->FUN_141bbbcf0(nObjectId, 0);
    }
    else if (cMode == 2)
    {
        int nObjectId = pStream->vfunc_o8_3();
        CUGCBallObject* pBall = FUN_140dee810(reinterpret_cast<GameObject*>(pWorld->FUN_141bd1180(nObjectId)));
        if (pBall != 0)
            pBall->FUN_140dee050(&packet);
    }
    else if (cMode == 3)
    {
        int nObjectId = pStream->vfunc_o8_3();
        CUGCBallObject* pBall = FUN_140dee810(reinterpret_cast<GameObject*>(pWorld->FUN_141bd1180(nObjectId)));
        if (pBall != 0)
            pBall->FUN_140dee220(&packet);
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
