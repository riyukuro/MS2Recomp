// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameObjectController: the PhysX capsule character controller
// of an actor (see ms2/client/ms2/gameobjectcontroller.h) and the NxCharacter header inlines it instantiates
// (NxCapsuleControllerDesc / NxControllerDesc, NxExtendedVec3, NxCapsule). Source file name unknown.
// MS2-UNIT: unit_14123f5b0
// MS2-RANGE: 0x14123f2d0-0x141241810 .text$mn
#define NOMINMAX
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/gameobjectcontroller.h"
#include <math.h>
extern "C" float (__cdecl* __imp_cosf)(float);                      // the exe calls the CRT import
#include <NiPoint3.h>
#include <efdPhysX/PhysXTypes.h>
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper
float ToPercent(float fValue);                      // PhysX units -> game units (x100), commonutil.cpp
float FromPercent(float fValue);                      // game units -> PhysX units (x0.01), commonutil.cpp
float FUN_14029d220(float fValue);                      // fabsf, commonutil.cpp
bool Unk_IsFinite(const efd::Point3& kPoint);           // all three coordinates finite
CString FUN_140390ea0(const wchar_t* pszText, int nCodePage);   // wide -> multibyte, filebuffer_1.cpp

// Gravity used while no PhysX scene exists (game units / s^2).
static float s_fDefaultGravity = -34.602074f;

// @0x14123f2d0
GameObjectController::GameObjectController()
    : m_pMaterial(0)
    , m_pController(0)
    , m_pManager(0)
    , m_nGroups(0x389)
    , m_nCollisionFlags(0)
    , m_bJumping(0)
    , m_fJumpSpeed(0)
    , m_kVelocity(efd::Point3::ZERO)
    , m_bLift(0)
    , m_fLiftTime(0)
    , m_fLiftHeight(0)
    , m_fLiftDuration(0)
    , m_fLiftPeak(0)
    , m_fLiftBase(0)
    , m_bLiftFalling(0)
    , m_spActorData(0)
    , m_nIgnoreGroups(0)
    , m_fJumpApex(2.0f)
    , m_pOwner(0)
{
}

// @0x14123f460
GameObjectController::~GameObjectController()
{
    if (m_pController == 0)
        return;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxActor* pActor = m_pController->getActor();
    if (pActor != 0)
    {
        if (m_pMaterial != 0)
        {
            pActor->getScene().releaseMaterial(*m_pMaterial);
            m_pMaterial = 0;
        }
        pActor->userData = 0;
        m_spActorData = 0;
    }
    m_pManager->releaseController(*m_pController);
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}

// @0x14123f5b0
// MS2-FUNCTIONAL: EH state numbering / frame layout of the desc + setName temporaries differ from exe
void GameObjectController::FUN_14123f5b0(PCBase* pOwner, egf::Entity* pEntity, efd::Point3 kPos, float fHeight, float fRadius)
{
    m_pOwner = pOwner;
    m_pManager = static_cast<NxControllerManager*>(((class CPhysXHelper*)GetPhysXHelper())->GetControllerManager());

    NxVec3 kNxPos;
    efdPhysX::PhysXTypes::Point3ToNxVec3(kPos, kNxPos);

    float fCapsuleHeight = fHeight - 2.0f * fRadius;
    if (fCapsuleHeight <= 0.0f)
        fCapsuleHeight = 10.0f;

    NxCapsuleControllerDesc kDesc;
    kDesc.position.x = FromPercent(kNxPos.x);
    kDesc.position.y = FromPercent(kNxPos.y);
    kDesc.position.z = FromPercent(kNxPos.z);
    kDesc.radius = FromPercent(fRadius);
    kDesc.height = FromPercent(fCapsuleHeight);
    kDesc.skinWidth = 0.01f;
    kDesc.slopeLimit = __imp_cosf(0.87266463f);
    kDesc.stepOffset = 0.3f;
    kDesc.upDirection = NX_Z;
    kDesc.climbingMode = CLIMB_EASY;
    kDesc.callback = &m_hitReport;
    m_hitReport.SetField28(pOwner);

    m_fCenterOffset = -(fCapsuleHeight * 0.5f + fRadius);
    m_groupsMask.bits0 = m_nGroups;
    m_groupsMask.bits1 = m_nGroups;
    m_groupsMask.bits2 = m_nGroups;
    m_groupsMask.bits3 = m_nGroups;

    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pController = static_cast<NxCapsuleController*>(m_pManager->createController(((class CPhysXHelper*)GetPhysXHelper())->GetNxScene(), kDesc));
    if (m_pController != 0)
    {
        m_pController->setInteraction(NXIF_INTERACTION_USE_FILTER);
        m_spActorData = EE_NEW egfPhysX::EntityActorData(pEntity);
        NxActor* pActor = m_pController->getActor();
        if (pActor != 0)
            pActor->userData = m_spActorData;
        pActor->setName(FUN_140390ea0(pOwner->vfunc_77(), 0));
        FUN_14123fa70(pActor);
    }
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}
MS2_REPLACE_METHOD(0x14123F5B0, GameObjectController, FUN_14123f5b0, 1205, 0x5F88E8D4);

// @0x14123fa70
void GameObjectController::FUN_14123fa70(NxActor* pActor)
{
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxShape* pShape = pActor->getShapes()[0];
    NxScene& kScene = pActor->getScene();
    NxMaterial* pMaterial = kScene.getMaterialFromIndex(pShape->getMaterial());
    NxMaterialDesc kDesc;
    pMaterial->saveToDesc(kDesc);
    kDesc.restitution = 1.0f;
    if (m_pMaterial != 0)
        kScene.releaseMaterial(*m_pMaterial);
    m_pMaterial = kScene.createMaterial(kDesc);
    pShape->setMaterial(m_pMaterial->getMaterialIndex());
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}
MS2_REPLACE_METHOD(0x14123FA70, GameObjectController, FUN_14123fa70, 363, 0xF2C614DB);

// @0x14123fbf0
void GameObjectController::SetCollisionGroup(NxCollisionGroup nGroup)
{
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxActor* pActor = m_pController->getActor();
    if (pActor != 0)
    {
        NxU32 nShapes = pActor->getNbShapes();
        NxShape* const* ppShapes = pActor->getShapes();
        for (unsigned int i = 0; i < nShapes; i++)
        {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(nGroup);
            NxGroupsMask kMask;
            kMask.bits0 = kMask.bits1 = kMask.bits2 = kMask.bits3 = m_nGroups;
            pShape->setGroupsMask(kMask);
        }
    }
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}
MS2_REPLACE_METHOD(0x14123FBF0, GameObjectController, SetCollisionGroup, 300, 0xAC5D3404);

// @0x14123fd30
void GameObjectController::FUN_14123fd30(unsigned int nGroups)
{
    m_nGroups = nGroups;
    m_groupsMask.bits0 = m_groupsMask.bits1 = m_groupsMask.bits2 = m_groupsMask.bits3 = m_nGroups;
}
MS2_REPLACE_METHOD(0x14123FD30, GameObjectController, FUN_14123fd30, 86, 0x541B5E13);

// @0x14123fd90
efd::Point3 GameObjectController::FUN_14123fd90()
{
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxExtendedVec3 kPos = m_pController->getPosition();
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
    efd::Point3 kResult;
    kResult.x = ToPercent((float)kPos.x);
    kResult.y = ToPercent((float)kPos.y);
    kResult.z = ToPercent((float)kPos.z);
    kResult.z += GetCenterOffset();
    return kResult;
}
MS2_REPLACE_METHOD(0x14123FD90, GameObjectController, FUN_14123fd90, 208, 0x55BC2F64);

// @0x14123fe70
void GameObjectController::FUN_14123fe70(efd::Point3 kPos)
{
    NxExtendedVec3 kNxPos;
    kPos.z -= GetCenterOffset();
    kNxPos.x = FromPercent(kPos.x);
    kNxPos.y = FromPercent(kPos.y);
    kNxPos.z = FromPercent(kPos.z);
    if (!kNxPos.isFinite())
        return;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pController->setPosition(kNxPos);
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}
MS2_REPLACE_METHOD(0x14123FE70, GameObjectController, FUN_14123fe70, 216, 0xC522256A);

// @0x14123ff50
void GameObjectController::ReportSceneChanged()
{
    m_pController->reportSceneChanged();
}
MS2_REPLACE_METHOD(0x14123FF50, GameObjectController, ReportSceneChanged, 38, 0x4AB3EC28);

// @0x14123ff80
// MS2-FUNCTIONAL: codegen (block layout/EH state numbering differ); NxScene slots are right since src/ms2/physx2846 (checkOverlapCapsule +0x3f0)
void GameObjectController::Move(efd::Point3 kDisp, unsigned int nExcludeGroups)
{
    if (m_pController != 0)
    {
        if (!Unk_IsFinite(kDisp))
            kDisp = efd::Point3::ZERO;
        NxU32 nGroups = m_nGroups;
        nGroups &= ~nExcludeGroups;
        nGroups &= ~m_nIgnoreGroups;
        NxVec3 kNxDisp;
        efdPhysX::PhysXTypes::Point3ToNxVec3(kDisp, kNxDisp);
        m_hitReport.ClearHit();

        ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
        m_pController->move(kNxDisp, nGroups, 0.000001f, m_nCollisionFlags, 1.0f, &m_groupsMask);
        m_pManager->updateControllers();
        ((class CPhysXHelper*)GetPhysXHelper())->Unlock();

        if (m_nCollisionFlags == NXCC_COLLISION_UP)
            m_nIgnoreGroups = 0x10;
        if (m_nCollisionFlags == NXCC_COLLISION_DOWN && m_hitReport.GetOtherController() != 0)
            m_nIgnoreGroups = 0x10;

        if ((m_nCollisionFlags & NXCC_COLLISION_DOWN) != 0)
        {
            int bOnController = 0;
            if ((m_nCollisionFlags & NXCC_COLLISION_SIDES) != 0 && m_hitReport.GetOtherController() != 0)
            {
                bOnController = 1;
                if (m_hitReport.GetHit() != 0)
                {
                    StopJump();
                    if (m_bLiftFalling != 0)
                        FUN_141240d70();
                }
            }
            if (m_nIgnoreGroups != 0 && m_hitReport.GetOtherController() == 0)
            {
                ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
                NxExtendedVec3 kPos = m_pController->getPosition();
                float fHeight = m_pController->getHeight();
                float fRadius = m_pController->getRadius();
                NxCapsule kCapsule;
                kCapsule.p0.x = kCapsule.p1.x = (float)kPos.x;
                kCapsule.p0.y = kCapsule.p1.y = (float)kPos.y;
                kCapsule.p0.z = kCapsule.p1.z = (float)kPos.z;
                kCapsule.p0.z -= fHeight * 0.5f;
                kCapsule.p1.z += fHeight * 0.5f;
                kCapsule.radius = fRadius;
                m_pController->setCollision(false);
                NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
                bool bOverlap = pScene->checkOverlapCapsule(kCapsule, NX_ALL_SHAPES, 0xffffffff, 0);
                m_pController->setCollision(true);
                if (bOverlap)
                {
                    StopJump();
                    if (m_bLiftFalling != 0)
                        FUN_141240d70();
                }
                else
                {
                    m_nIgnoreGroups = 0;
                }
                ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
            }
            if (m_nIgnoreGroups == 0 && bOnController == 0)
            {
                StopJump();
                if (m_bLiftFalling != 0)
                    FUN_141240d70();
            }
        }
        else
        {
            if (m_kFallTimer.IsRunning() == 0)
                m_kFallTimer.FUN_1408687c0();
        }
        m_hitReport.ClearOtherController();
    }
}
MS2_REPLACE_METHOD(0x14123FF80, GameObjectController, Move, 1422, 0xC51BDA45);

// @0x141240520
void GameObjectController::SetCapsuleSize(float fRadius, float fHeight)
{
    float fCapsuleHeight = fHeight - 2.0f * fRadius;
    if (fCapsuleHeight <= 0.0f)
        fCapsuleHeight = 10.0f;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pController->setHeight(FromPercent(fCapsuleHeight));
    m_pController->setRadius(FromPercent(fRadius));
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
    m_fCenterOffset = -(fCapsuleHeight * 0.5f + fRadius);
}
MS2_REPLACE_METHOD(0x141240520, GameObjectController, SetCapsuleSize, 232, 0xF9BE8165);

// @0x141240610
void GameObjectController::StartJump(float fHeight, efd::Point3 kVelocity, float fUnused)
{
    if (m_bJumping != 0)
        return;
    m_fJumpSpeed = sqrt(2.0f * (2.0f * fHeight) * -GetGravity(false));
    m_kVelocity = kVelocity;
    m_bJumping = 1;
    m_fJumpTime = 0;
    m_fJumpHeight = 0;
    m_fJumpApex = FUN_14029d220(m_fJumpSpeed / GetGravity(false));
}
MS2_REPLACE_METHOD(0x141240610, GameObjectController, StartJump, 232, 0x77644077);

// @0x141240700
void GameObjectController::SetKVelocity(efd::Point3 kVelocity)
{
    m_kVelocity = kVelocity;
}
MS2_REPLACE_METHOD(0x141240700, GameObjectController, SetKVelocity, 41, 0x589555EC);

// @0x141240730
void GameObjectController::StopJump()
{
    m_bJumping = 0;
    m_kVelocity = efd::Point3::ZERO;
    m_kFallTimer.Reset();
}
MS2_REPLACE_METHOD(0x141240730, GameObjectController, StopJump, 69, 0x772A8ECD);

// @0x141240780
int GameObjectController::IsJumping()
{
    return m_bJumping;
}
MS2_REPLACE_METHOD(0x141240780, GameObjectController, IsJumping, 14, 0x69D980EB);

// @0x1412407a0
int GameObjectController::FUN_1412407a0()
{
    return m_fJumpTime < m_fJumpApex;
}
MS2_REPLACE_METHOD(0x1412407A0, GameObjectController, FUN_1412407a0, 60, 0x6E54CF7F);

// @0x1412407f0
efd::Point3 GameObjectController::FUN_1412407f0(float fDelta, int bMove)
{
    if (m_bJumping != 0)
    {
        m_fJumpTime += fDelta;
        efd::Point3 kStep = m_kVelocity * fDelta;
        float fPrevHeight = m_fJumpHeight;
        m_fJumpHeight = m_fJumpSpeed * m_fJumpTime + 0.5f * GetGravity(false) * m_fJumpTime * m_fJumpTime;
        kStep.z = m_fJumpHeight - fPrevHeight;
        return kStep;
    }
    else if (m_bLift != 0)
    {
        m_fLiftTime += fDelta;
        float fLiftHeight = m_fLiftBase;
        float fRatio = 1.0f - (m_fLiftDuration - m_fLiftTime) / m_fLiftDuration;
        fLiftHeight -= 4.0f * m_fLiftPeak * fRatio * (fRatio - 1.0f);
        if (m_bLiftFalling == 0 && fLiftHeight < m_fLiftHeight)
        {
            m_bLiftFalling = 1;
            MyPC* pMyPC = efd::DynamicCast<MyPC>(m_pOwner);
            if (pMyPC != 0)
                pMyPC->FUN_141676060(pMyPC->vfunc_18());
        }
        efd::Point3 kStep(0.0f, 0.0f, 0.0f);
        kStep.z = FromPercent(fLiftHeight - m_fLiftHeight);
        m_fLiftHeight = fLiftHeight;
        return kStep;
    } else {
        efd::Point3 kStep = efd::Point3::ZERO;
        if (bMove != 0) kStep = m_kVelocity * fDelta;
        float fFallSpeed = GetGravity(false) * ((float)GetFallTime() / 1000.0f);
        float fFall = fFallSpeed * fDelta;
        kStep.z = fFall + 0.5f * GetGravity(false) * fDelta * fDelta;
        return kStep; }
}
MS2_REPLACE_METHOD(0x1412407F0, GameObjectController, FUN_1412407f0, 1081, 0x6B9BE4CF);

// @0x141240c40
float GameObjectController::GetGravity(bool bDefault)
{
    if (!bDefault)
    {
        NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
        if (pScene != 0)
        {
            NxVec3 kGravity;
            pScene->getGravity(kGravity);
            return kGravity.z;
        }
    }
    return s_fDefaultGravity;
}

// @0x141240cb0
void GameObjectController::StartLift(float fDuration, float fPeak, float fBase)
{
    if (m_bLift != 0)
        return;
    m_bLift = 1;
    m_bJumping = 0;
    m_fLiftTime = 0;
    m_fLiftHeight = fBase;
    m_fLiftDuration = fDuration;
    m_fLiftPeak = fPeak;
    m_fLiftBase = fBase;
    m_bLiftFalling = 0;
}
MS2_REPLACE_METHOD(0x141240CB0, GameObjectController, StartLift, 177, 0xBC6079B3);

// @0x141240d70
void GameObjectController::FUN_141240d70()
{
    m_bLift = 0;
    m_kFallTimer.Reset();
}
MS2_REPLACE_METHOD(0x141240D70, GameObjectController, FUN_141240d70, 48, 0xB43DF174);

// @0x141240db0
int GameObjectController::IsLift()
{
    return m_bLift;
}
MS2_REPLACE_METHOD(0x141240DB0, GameObjectController, IsLift, 17, 0x0A012C13);

// @0x141240dd0
int GameObjectController::IsLiftFalling()
{
    return m_bLiftFalling;
}
MS2_REPLACE_METHOD(0x141240DD0, GameObjectController, IsLiftFalling, 17, 0xA9AE535B);

// @0x141240df0
efd::Point3 GameObjectController::GetHitNormal()
{
    efd::Point3 kNormal = efd::Point3::ZERO;
    efdPhysX::PhysXTypes::NxVec3ToPoint3(m_hitReport.GetNormal(), kNormal);
    return kNormal;
}
MS2_REPLACE_METHOD(0x141240DF0, GameObjectController, GetHitNormal, 108, 0x644F6BF6);

// @0x141240e70
NxActor* GameObjectController::GetActor()
{
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxActor* pActor = m_pController->getActor();
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
    return pActor;
}
MS2_REPLACE_METHOD(0x141240E70, GameObjectController, GetActor, 76, 0x80148672);

// @0x141240ed0
NxU32 GameObjectController::GetCollisionFlags()
{
    return m_nCollisionFlags;
}
MS2_REPLACE_METHOD(0x141240ED0, GameObjectController, GetCollisionFlags, 14, 0xB9C4E423);

// @0x141240ef0
int GameObjectController::GetFallTime()
{
    return m_kFallTimer.FUN_140868a70();
}
MS2_REPLACE_METHOD(0x141240EF0, GameObjectController, GetFallTime, 33, 0x55952518);

// @0x141240f20
GameObjectControllerHitReport* GameObjectController::GetHitReport()
{
    return &m_hitReport;
}
MS2_REPLACE_METHOD(0x141240F20, GameObjectController, GetHitReport, 15, 0x271C8F51);

// @0x141240f40
int GameObjectController::FUN_141240f40()
{
    return (m_nCollisionFlags & NXCC_COLLISION_DOWN) != 0 && IsJumping() == 0 && IsLift() == 0;
}
MS2_REPLACE_METHOD(0x141240F40, GameObjectController, FUN_141240f40, 79, 0xABB10CA2);

// @0x141240fa0
void GameObjectController::ResetFallTimer()
{
    m_kFallTimer.Reset();
}
MS2_REPLACE_METHOD(0x141240FA0, GameObjectController, ResetFallTimer, 33, 0x4ADCCA03);

// @0x141240fd0
efd::Point3 GameObjectController::GetKVelocity()
{
    return m_kVelocity;
}
MS2_REPLACE_METHOD(0x141240FD0, GameObjectController, GetKVelocity, 41, 0x604E0F2C);

// @0x141241000
float GameObjectController::FUN_141241000()
{
    if (m_pController != 0)
    {
        ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
        float fRadius = m_pController->getRadius();
        ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
        return fRadius;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141241000, GameObjectController, FUN_141241000, 95, 0x2E35979C);

// @0x141241070
void GameObjectController::ClearCollisionFlags()
{
    m_nCollisionFlags = 0;
}
MS2_REPLACE_METHOD(0x141241070, GameObjectController, ClearCollisionFlags, 18, 0x595CF247);

// @0x141241090
float GameObjectController::GetJumpApexTime()
{
    if (m_bJumping != 0)
        return m_fJumpApex;
    return 0;
}
MS2_REPLACE_METHOD(0x141241090, GameObjectController, GetJumpApexTime, 35, 0xD028E8E5);

// @0x1412410c0
bool GameObjectController::IsCapsuleOverlapping(const efd::Point3& kPos, float fOffset)
{
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    NxVec3 kNxPos;
    kNxPos.x = FromPercent(kPos.x);
    kNxPos.y = FromPercent(kPos.y);
    kNxPos.z = FromPercent(kPos.z + fOffset);
    float fHeight = m_pController->getHeight();
    float fRadius = m_pController->getRadius();
    NxCapsule kCapsule;
    kCapsule.p0.x = kCapsule.p1.x = kNxPos.x;
    kCapsule.p0.y = kCapsule.p1.y = kNxPos.y;
    kCapsule.p0.z = kCapsule.p1.z = kNxPos.z;
    kCapsule.p0.z -= fHeight * 0.5f;
    kCapsule.p1.z += fHeight * 0.5f;
    kCapsule.radius = fRadius;
    NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
    bool bOverlap = pScene->checkOverlapCapsule(kCapsule, NX_ALL_SHAPES, 0x389, 0);
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
    return bOverlap;
}
MS2_REPLACE_METHOD(0x1412410C0, GameObjectController, IsCapsuleOverlapping, 485, 0x0E4FEF0B);

// @0x1412412b0
int GameObjectController::FUN_1412412b0()
{
    if (m_bJumping != 0)
        return (m_kFallTimer.IsRunning() == 0 || FUN_1412407a0() != 0) ? 0 : 1;
    return m_kFallTimer.IsRunning();
}
MS2_REPLACE_METHOD(0x1412412B0, GameObjectController, FUN_1412412b0, 105, 0x4B49306D);

// @0x141241320
float GameObjectController::GetCenterOffset()
{
    return m_fCenterOffset;
}
MS2_REPLACE_METHOD(0x141241320, GameObjectController, GetCenterOffset, 16, 0x1BE201AE);
