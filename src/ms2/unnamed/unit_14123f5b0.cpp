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
#include <NiPoint3.h>
#include <efdPhysX/PhysXTypes.h>
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CPhysXHelper* FUN_1409f7ca0();                          // TSingleton<CPhysXHelper>::GetInstance
float FUN_14028d380(float fValue);                      // PhysX units -> game units (x100), commonutil.cpp
float FUN_14028d3a0(float fValue);                      // game units -> PhysX units (x0.01), commonutil.cpp
float FUN_14029d220(float fValue);                      // fabsf, commonutil.cpp
bool FUN_140a33ff0(const efd::Point3& kPoint);          // all three coordinates finite
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
    FUN_1409f7ca0()->FUN_14168a540(0);
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
    FUN_1409f7ca0()->FUN_14168a570();
}

// @0x14123f5b0
// MS2-FUNCTIONAL: EH state numbering / frame layout of the desc + setName temporaries differ from exe
void GameObjectController::FUN_14123f5b0(PCBase* pOwner, egf::Entity* pEntity, efd::Point3 kPos, float fHeight, float fRadius)
{
    m_pOwner = pOwner;
    m_pManager = static_cast<NxControllerManager*>(FUN_1409f7ca0()->FUN_14168a750());

    NxVec3 kNxPos;
    efdPhysX::PhysXTypes::Point3ToNxVec3(kPos, kNxPos);

    float fCapsuleHeight = fHeight - 2.0f * fRadius;
    if (fCapsuleHeight <= 0.0f)
        fCapsuleHeight = 10.0f;

    NxCapsuleControllerDesc kDesc;
    kDesc.position.x = FUN_14028d3a0(kNxPos.x);
    kDesc.position.y = FUN_14028d3a0(kNxPos.y);
    kDesc.position.z = FUN_14028d3a0(kNxPos.z);
    kDesc.radius = FUN_14028d3a0(fRadius);
    kDesc.height = FUN_14028d3a0(fCapsuleHeight);
    kDesc.skinWidth = 0.01f;
    kDesc.slopeLimit = cosf(0.87266463f);
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

    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pController = static_cast<NxCapsuleController*>(m_pManager->createController(FUN_1409f7ca0()->FUN_14168a1c0(), kDesc));
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
    FUN_1409f7ca0()->FUN_14168a570();
}
MS2_REPLACE_METHOD(0x14123F5B0, GameObjectController, FUN_14123f5b0, 1205, 0x5F88E8D4);

// @0x14123fa70
void GameObjectController::FUN_14123fa70(NxActor* pActor)
{
    FUN_1409f7ca0()->FUN_14168a540(0);
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
    FUN_1409f7ca0()->FUN_14168a570();
}
MS2_REPLACE_METHOD(0x14123FA70, GameObjectController, FUN_14123fa70, 363, 0xF2C614DB);

// @0x14123fbf0
void GameObjectController::FUN_14123fbf0(NxCollisionGroup nGroup)
{
    FUN_1409f7ca0()->FUN_14168a540(0);
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
    FUN_1409f7ca0()->FUN_14168a570();
}
MS2_REPLACE_METHOD(0x14123FBF0, GameObjectController, FUN_14123fbf0, 300, 0xAC5D3404);

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
    FUN_1409f7ca0()->FUN_14168a540(0);
    NxExtendedVec3 kPos = m_pController->getPosition();
    FUN_1409f7ca0()->FUN_14168a570();
    efd::Point3 kResult;
    kResult.x = FUN_14028d380((float)kPos.x);
    kResult.y = FUN_14028d380((float)kPos.y);
    kResult.z = FUN_14028d380((float)kPos.z);
    kResult.z += FUN_141241320();
    return kResult;
}
MS2_REPLACE_METHOD(0x14123FD90, GameObjectController, FUN_14123fd90, 208, 0x55BC2F64);

// @0x14123fe70
void GameObjectController::FUN_14123fe70(efd::Point3 kPos)
{
    NxExtendedVec3 kNxPos;
    kPos.z -= FUN_141241320();
    kNxPos.x = FUN_14028d3a0(kPos.x);
    kNxPos.y = FUN_14028d3a0(kPos.y);
    kNxPos.z = FUN_14028d3a0(kPos.z);
    if (!kNxPos.isFinite())
        return;
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pController->setPosition(kNxPos);
    FUN_1409f7ca0()->FUN_14168a570();
}
MS2_REPLACE_METHOD(0x14123FE70, GameObjectController, FUN_14123fe70, 216, 0xC522256A);

// @0x14123ff50
void GameObjectController::FUN_14123ff50()
{
    m_pController->reportSceneChanged();
}
MS2_REPLACE_METHOD(0x14123FF50, GameObjectController, FUN_14123ff50, 38, 0x4AB3EC28);

// @0x14123ff80
// MS2-FUNCTIONAL: codegen (block layout/EH state numbering differ); NxScene slots are right since src/ms2/physx2846 (checkOverlapCapsule +0x3f0)
void GameObjectController::FUN_14123ff80(efd::Point3 kDisp, unsigned int nExcludeGroups)
{
    if (m_pController != 0)
    {
        if (!FUN_140a33ff0(kDisp))
            kDisp = efd::Point3::ZERO;
        NxU32 nGroups = m_nGroups;
        nGroups &= ~nExcludeGroups;
        nGroups &= ~m_nIgnoreGroups;
        NxVec3 kNxDisp;
        efdPhysX::PhysXTypes::Point3ToNxVec3(kDisp, kNxDisp);
        m_hitReport.ClearHit();

        FUN_1409f7ca0()->FUN_14168a540(0);
        m_pController->move(kNxDisp, nGroups, 0.000001f, m_nCollisionFlags, 1.0f, &m_groupsMask);
        m_pManager->updateControllers();
        FUN_1409f7ca0()->FUN_14168a570();

        if (m_nCollisionFlags == NXCC_COLLISION_UP)
            m_nIgnoreGroups = 0x10;
        if (m_nCollisionFlags == NXCC_COLLISION_DOWN && m_hitReport.GetOtherController() != 0)
            m_nIgnoreGroups = 0x10;

        if ((m_nCollisionFlags & NXCC_COLLISION_DOWN) == 0)
        {
            if (m_kFallTimer.FUN_140868ba0() == 0)
                m_kFallTimer.FUN_1408687c0();
        }
        else
        {
            bool bOnController = false;
            if ((m_nCollisionFlags & NXCC_COLLISION_SIDES) != 0 && m_hitReport.GetOtherController() != 0)
            {
                bOnController = true;
                if (m_hitReport.GetHit() != 0)
                {
                    FUN_141240730();
                    if (m_bLiftFalling != 0)
                        FUN_141240d70();
                }
            }
            if (m_nIgnoreGroups != 0 && m_hitReport.GetOtherController() == 0)
            {
                FUN_1409f7ca0()->FUN_14168a540(0);
                NxExtendedVec3 kPos = m_pController->getPosition();
                float fHeight = m_pController->getHeight();
                float fRadius = m_pController->getRadius();
                NxCapsule kCapsule;
                kCapsule.p0.x = (float)kPos.x;
                kCapsule.p0.y = (float)kPos.y;
                kCapsule.p0.z = (float)kPos.z - fHeight * 0.5f;
                kCapsule.p1.z = (float)kPos.z + fHeight * 0.5f;
                kCapsule.p1.x = kCapsule.p0.x;
                kCapsule.p1.y = kCapsule.p0.y;
                kCapsule.radius = fRadius;
                m_pController->setCollision(false);
                NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
                bool bOverlap = pScene->checkOverlapCapsule(kCapsule, NX_ALL_SHAPES, 0xffffffff, 0);
                m_pController->setCollision(true);
                if (!bOverlap)
                {
                    m_nIgnoreGroups = 0;
                }
                else
                {
                    FUN_141240730();
                    if (m_bLiftFalling != 0)
                        FUN_141240d70();
                }
                FUN_1409f7ca0()->FUN_14168a570();
            }
            if (m_nIgnoreGroups == 0 && !bOnController)
            {
                FUN_141240730();
                if (m_bLiftFalling != 0)
                    FUN_141240d70();
            }
        }
        m_hitReport.ClearOtherController();
    }
}
MS2_REPLACE_METHOD(0x14123FF80, GameObjectController, FUN_14123ff80, 1422, 0xC51BDA45);

// @0x141240520
void GameObjectController::FUN_141240520(float fRadius, float fHeight)
{
    float fCapsuleHeight = fHeight - 2.0f * fRadius;
    if (fCapsuleHeight <= 0.0f)
        fCapsuleHeight = 10.0f;
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pController->setHeight(FUN_14028d3a0(fCapsuleHeight));
    m_pController->setRadius(FUN_14028d3a0(fRadius));
    FUN_1409f7ca0()->FUN_14168a570();
    m_fCenterOffset = -(fCapsuleHeight * 0.5f + fRadius);
}
MS2_REPLACE_METHOD(0x141240520, GameObjectController, FUN_141240520, 232, 0xF9BE8165);

// @0x141240610
void GameObjectController::FUN_141240610(float fHeight, efd::Point3 kVelocity, float fUnused)
{
    if (m_bJumping != 0)
        return;
    m_fJumpSpeed = sqrt(2.0f * (2.0f * fHeight) * -FUN_141240c40(false));
    m_kVelocity = kVelocity;
    m_bJumping = 1;
    m_fJumpTime = 0;
    m_fJumpHeight = 0;
    m_fJumpApex = FUN_14029d220(m_fJumpSpeed / FUN_141240c40(false));
}
MS2_REPLACE_METHOD(0x141240610, GameObjectController, FUN_141240610, 232, 0x77644077);

// @0x141240700
void GameObjectController::FUN_141240700(efd::Point3 kVelocity)
{
    m_kVelocity = kVelocity;
}
MS2_REPLACE_METHOD(0x141240700, GameObjectController, FUN_141240700, 41, 0x589555EC);

// @0x141240730
void GameObjectController::FUN_141240730()
{
    m_bJumping = 0;
    m_kVelocity = efd::Point3::ZERO;
    m_kFallTimer.FUN_1408687f0();
}
MS2_REPLACE_METHOD(0x141240730, GameObjectController, FUN_141240730, 69, 0x772A8ECD);

// @0x141240780
int GameObjectController::FUN_141240780()
{
    return m_bJumping;
}
MS2_REPLACE_METHOD(0x141240780, GameObjectController, FUN_141240780, 14, 0x69D980EB);

// @0x1412407a0
int GameObjectController::FUN_1412407a0()
{
    return m_fJumpTime < m_fJumpApex;
}
MS2_REPLACE_METHOD(0x1412407A0, GameObjectController, FUN_1412407a0, 60, 0x6E54CF7F);

// @0x1412407f0
// MS2-FUNCTIONAL: frame 0xa8 vs 0xb8, lift-path temporaries ordered differently
efd::Point3 GameObjectController::FUN_1412407f0(float fDelta, int bMove)
{
    if (m_bJumping != 0)
    {
        m_fJumpTime += fDelta;
        efd::Point3 kStep = m_kVelocity * fDelta;
        float fPrevHeight = m_fJumpHeight;
        m_fJumpHeight = m_fJumpSpeed * m_fJumpTime + 0.5f * FUN_141240c40(false) * m_fJumpTime * m_fJumpTime;
        kStep.z = m_fJumpHeight - fPrevHeight;
        return kStep;
    }
    if (m_bLift != 0)
    {
        m_fLiftTime += fDelta;
        float fRatio = 1.0f - (m_fLiftDuration - m_fLiftTime) / m_fLiftDuration;
        float fLiftHeight = m_fLiftBase - 4.0f * m_fLiftPeak * fRatio * (fRatio - 1.0f);
        if (m_bLiftFalling == 0 && fLiftHeight < m_fLiftHeight)
        {
            m_bLiftFalling = 1;
            MyPC* pMyPC = efd::DynamicCast<MyPC>(m_pOwner);
            if (pMyPC != 0)
                pMyPC->FUN_141676060(pMyPC->vfunc_18());
        }
        efd::Point3 kStep(0.0f, 0.0f, 0.0f);
        kStep.z = FUN_14028d3a0(fLiftHeight - m_fLiftHeight);
        m_fLiftHeight = fLiftHeight;
        return kStep;
    }
    efd::Point3 kStep = efd::Point3::ZERO;
    if (bMove != 0)
        kStep = m_kVelocity * fDelta;
    kStep.z = FUN_141240c40(false) * ((float)FUN_141240ef0() / 1000.0f) * fDelta
        + 0.5f * FUN_141240c40(false) * fDelta * fDelta;
    return kStep;
}
MS2_REPLACE_METHOD(0x1412407F0, GameObjectController, FUN_1412407f0, 1081, 0x6B9BE4CF);

// @0x141240c40
float GameObjectController::FUN_141240c40(bool bDefault)
{
    if (!bDefault)
    {
        NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
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
void GameObjectController::FUN_141240cb0(float fDuration, float fPeak, float fBase)
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
MS2_REPLACE_METHOD(0x141240CB0, GameObjectController, FUN_141240cb0, 177, 0xBC6079B3);

// @0x141240d70
void GameObjectController::FUN_141240d70()
{
    m_bLift = 0;
    m_kFallTimer.FUN_1408687f0();
}
MS2_REPLACE_METHOD(0x141240D70, GameObjectController, FUN_141240d70, 48, 0xB43DF174);

// @0x141240db0
int GameObjectController::FUN_141240db0()
{
    return m_bLift;
}
MS2_REPLACE_METHOD(0x141240DB0, GameObjectController, FUN_141240db0, 17, 0x0A012C13);

// @0x141240dd0
int GameObjectController::FUN_141240dd0()
{
    return m_bLiftFalling;
}
MS2_REPLACE_METHOD(0x141240DD0, GameObjectController, FUN_141240dd0, 17, 0xA9AE535B);

// @0x141240df0
efd::Point3 GameObjectController::FUN_141240df0()
{
    efd::Point3 kNormal = efd::Point3::ZERO;
    efdPhysX::PhysXTypes::NxVec3ToPoint3(m_hitReport.GetNormal(), kNormal);
    return kNormal;
}
MS2_REPLACE_METHOD(0x141240DF0, GameObjectController, FUN_141240df0, 108, 0x644F6BF6);

// @0x141240e70
NxActor* GameObjectController::FUN_141240e70()
{
    FUN_1409f7ca0()->FUN_14168a540(0);
    NxActor* pActor = m_pController->getActor();
    FUN_1409f7ca0()->FUN_14168a570();
    return pActor;
}
MS2_REPLACE_METHOD(0x141240E70, GameObjectController, FUN_141240e70, 76, 0x80148672);

// @0x141240ed0
NxU32 GameObjectController::FUN_141240ed0()
{
    return m_nCollisionFlags;
}
MS2_REPLACE_METHOD(0x141240ED0, GameObjectController, FUN_141240ed0, 14, 0xB9C4E423);

// @0x141240ef0
int GameObjectController::FUN_141240ef0()
{
    return m_kFallTimer.FUN_140868a70();
}
MS2_REPLACE_METHOD(0x141240EF0, GameObjectController, FUN_141240ef0, 33, 0x55952518);

// @0x141240f20
GameObjectControllerHitReport* GameObjectController::FUN_141240f20()
{
    return &m_hitReport;
}
MS2_REPLACE_METHOD(0x141240F20, GameObjectController, FUN_141240f20, 15, 0x271C8F51);

// @0x141240f40
int GameObjectController::FUN_141240f40()
{
    return (m_nCollisionFlags & NXCC_COLLISION_DOWN) != 0 && FUN_141240780() == 0 && FUN_141240db0() == 0;
}
MS2_REPLACE_METHOD(0x141240F40, GameObjectController, FUN_141240f40, 79, 0xABB10CA2);

// @0x141240fa0
void GameObjectController::FUN_141240fa0()
{
    m_kFallTimer.FUN_1408687f0();
}
MS2_REPLACE_METHOD(0x141240FA0, GameObjectController, FUN_141240fa0, 33, 0x4ADCCA03);

// @0x141240fd0
efd::Point3 GameObjectController::FUN_141240fd0()
{
    return m_kVelocity;
}
MS2_REPLACE_METHOD(0x141240FD0, GameObjectController, FUN_141240fd0, 41, 0x604E0F2C);

// @0x141241000
float GameObjectController::FUN_141241000()
{
    if (m_pController != 0)
    {
        FUN_1409f7ca0()->FUN_14168a540(0);
        float fRadius = m_pController->getRadius();
        FUN_1409f7ca0()->FUN_14168a570();
        return fRadius;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141241000, GameObjectController, FUN_141241000, 95, 0x2E35979C);

// @0x141241070
void GameObjectController::FUN_141241070()
{
    m_nCollisionFlags = 0;
}
MS2_REPLACE_METHOD(0x141241070, GameObjectController, FUN_141241070, 18, 0x595CF247);

// @0x141241090
float GameObjectController::FUN_141241090()
{
    if (m_bJumping != 0)
        return m_fJumpApex;
    return 0;
}
MS2_REPLACE_METHOD(0x141241090, GameObjectController, FUN_141241090, 35, 0xD028E8E5);

// @0x1412410c0
bool GameObjectController::FUN_1412410c0(efd::Point3 kPos, float fOffset)
{
    FUN_1409f7ca0()->FUN_14168a540(0);
    NxVec3 kNxPos;
    kNxPos.x = FUN_14028d3a0(kPos.x);
    kNxPos.y = FUN_14028d3a0(kPos.y);
    kNxPos.z = FUN_14028d3a0(kPos.z + fOffset);
    float fHeight = m_pController->getHeight();
    float fRadius = m_pController->getRadius();
    NxCapsule kCapsule;
    kCapsule.p0.x = kCapsule.p1.x = kNxPos.x;
    kCapsule.p0.y = kCapsule.p1.y = kNxPos.y;
    kCapsule.p0.z = kCapsule.p1.z = kNxPos.z;
    kCapsule.p0.z -= fHeight * 0.5f;
    kCapsule.p1.z += fHeight * 0.5f;
    kCapsule.radius = fRadius;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    bool bOverlap = pScene->checkOverlapCapsule(kCapsule, NX_ALL_SHAPES, 0x389, 0);
    FUN_1409f7ca0()->FUN_14168a570();
    return bOverlap;
}
MS2_REPLACE_METHOD(0x1412410C0, GameObjectController, FUN_1412410c0, 485, 0x0E4FEF0B);

// @0x1412412b0
int GameObjectController::FUN_1412412b0()
{
    if (m_bJumping != 0)
        return (m_kFallTimer.FUN_140868ba0() == 0 || FUN_1412407a0() != 0) ? 0 : 1;
    return m_kFallTimer.FUN_140868ba0();
}
MS2_REPLACE_METHOD(0x1412412B0, GameObjectController, FUN_1412412b0, 105, 0x4B49306D);

// @0x141241320
float GameObjectController::FUN_141241320()
{
    return m_fCenterOffset;
}
MS2_REPLACE_METHOD(0x141241320, GameObjectController, FUN_141241320, 16, 0x1BE201AE);
