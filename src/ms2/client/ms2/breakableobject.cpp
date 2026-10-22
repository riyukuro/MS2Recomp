// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBreakableObject: a breakable / moving field object (see
// ms2/placeholder/cbreakableobject.h). It binds a map prop entity, reads its properties (box size, move path and
// timing, animation and effect names, tomb stone data), keeps a box collision and a kinematic PhysX box actor in sync
// with the entity, plays the state animations and effects the server's state changes ask for and moves the object
// along its back-and-forth path every frame.
// The tail of the unit (0x140ae0f60-0x140ae2d20) is the PhysX descriptor / efd / ATL inline COMDATs it instantiates
// (NxActorDesc, NxBodyDesc, NxBoxShapeDesc, NxArray<NxShapeDesc*>, Entity::GetPropertyValue<T>, CAtlArray<NiPoint2>).
// File name assumed (no __FILE__ string).
// MS2-UNIT: ?\breakableobject.cpp
// MS2-RANGE: 0x140add560-0x140ae2d20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$max@H@std@@YAAEBHAEBH0@Z 0x140ae1290 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCBoxCollision@@@@QEAA@PEAVCBoxCollision@@@Z 0x140ae1380 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCBoxCollision@@@@QEAAAEAV1@PEAVCBoxCollision@@@Z 0x140ae1850 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <NxPhysics.h>
#include <NiPoint2.h>
#include <NiNode.h>
#include <efd/ParseHelper.h>
#include <efdPhysX/PhysXTypes.h>
#include <egf/EntityManager.h>
#include <egmAnimation/AnimationService.h>
#include "ms2/placeholder/cbreakableobject.h"
#include "ms2/placeholder/cboxcollision.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cgraphicoptiontable.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/propertycache.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/ms2entitymanagerservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

namespace ecr { class SceneGraphService; }

// ---- exe data ----
extern int DAT_143ae2b30;                   // 1: actor-manager callbacks are routed through the callback manager
extern int DAT_1439f8208;                   // shadow quality (graphic option)
extern int DAT_143ae2960;                   // shadow quality (forced)

// ---- exe functions outside this unit ----
CPhysXHelper* FUN_1409f7ca0();                                      // TSingleton<CPhysXHelper>::GetInstance
CEffectService* FUN_1403ed280();                                    // TSingleton<CEffectService>::GetInstance
CMainSystem* FUN_14086d260();                                       // TSingleton<CMainSystem>::GetInstance
efd::ServiceManager* FUN_1413f9850();                               // the framework's service manager
ecr::SceneGraphService* GetSceneGraphService();                            // the scene graph service
void FUN_1414f11d0(ecr::SceneGraphService* pService, egf::Entity* pEntity);    // attach the entity's scene graph
void FUN_1414f1240(ecr::SceneGraphService* pService, egf::Entity* pEntity);    // detach it
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // the entity's scene root
void FUN_14098b3e0(NiAVObject* pRoot, float fAlpha, bool bRecurse); // set the model alpha
void FUN_141567330(NiAVObject* pRoot, bool bOn);                    // the model's shadow on / off
void FUN_1414737d0(egf::Entity* pEntity);                           // destroy a client-side entity
void FUN_140997ab0(egf::EntityPtr spEntity, NiActorManager::CallbackObject* pCb);   // register the actor callback
CString FUN_140188f50(const char* pszText, unsigned int nCodePage); // UTF-8 -> CString
void FUN_1401d3700(CString& str);                                   // normalise an object name
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& aOut, const char* pszDelim);   // split
int FUN_14028d260(float fSeconds);                                  // seconds -> milliseconds
float FUN_14028d280(unsigned int nTicks);                           // milliseconds -> seconds
void FUN_14098ab60(NiAVObject* pRoot, ATL::CAtlArray<NiPoint2>& aKeys, egf::EntityID idOwner);   // alpha animation

// AnimationService (egmAnimation) as the MS2 code calls it: play a sequence by name.
class Unk_BoAnimService
{
public:
    bool FUN_1409a1fc0(const egf::EntityID& id, const efd::utf8string& strSeq, float fBlend, bool bLoop);
};
Unk_BoAnimService* FUN_141b6f910();
// CEffectService as this unit calls it: the entity id by value (effectservice.h declares it const&; same callee bytes)
class Unk_BoEffectService
{
public:
    void FUN_1411a6f00(egf::EntityID id);                           // drop the kept object of an entity
};
bool FUN_140a33ff0(const efd::Point3& pt);                          // all three coordinates are finite

// ---- inline helpers (COMDATs this obj instantiated first) ----
// The entity manager service.
// @0x140ae11e0
inline egf::EntityManager* FUN_140ae11e0()
{
    return FUN_1413f9850()->GetSystemServiceAs<egf::EntityManager>();
}

// The effective shadow quality.
// @0x140ae1c10
inline int FUN_140ae1c10()
{
    return std::max(DAT_1439f8208, DAT_143ae2960);
}

// Fades the model's alpha from fFrom to fTo: hold fDelay seconds, then fDuration seconds; idOwner is told at the end.
// @0x140ae1e80
inline void FUN_140ae1e80(NiAVObject* pRoot, float fFrom, float fTo, float fDelay, float fDuration, egf::EntityID idOwner)
{
    if (pRoot == 0)
        return;
    ATL::CAtlArray<NiPoint2> aKeys;
    aKeys.Add(NiPoint2(fDelay, fFrom));
    aKeys.Add(NiPoint2(fDuration, fTo));
    FUN_14098ab60(pRoot, aKeys, idOwner);
}

// @0x140add560
CBreakableObject::CBreakableObject()
    : m_spEntity(0), m_nState(2), m_bHittable(false), m_nHitSound(0), m_bShadow(false), m_bC1(false),
      m_bPhysics(false), m_nTombId(0), m_spActorData(0)
{
    m_pActor = 0;
    m_bTombStone = 0;
    m_n184 = 0;
    m_bActorDirty = 0;
    m_ptPos = efd::Point3::ZERO;
    m_ptSize = efd::Point3::ZERO;
    m_ptRot = efd::Point3::ZERO;
    m_ptRotBase = efd::Point3::ZERO;
    m_ptPosBase = efd::Point3::ZERO;
    m_bHasAnim = 0;
    m_ptMoveDir = efd::Point3::ZERO;
    m_fMoveDelay = 0.0f;
    m_fSpeed = 0.0f;
    m_fMoveTime = 0.0f;
    m_afWait[0] = 0.0f;
    m_afWait[1] = 0.0f;
    m_nMoveMode = 0;
    m_fTimeScale = 0.0f;
    m_ptVelocity = efd::Point3::ZERO;
    m_nGroup = 0;
    m_n1dc = 0;
    m_nPhaseStart = 0;
    m_nPhase = 0;
    m_nSyncA = 1;
    m_nSyncB = 0;
    m_nSyncC = 0;
    m_bTombEffects = false;
    m_bDetached = true;
    m_kDetachTimer.FUN_1408687f0();
    m_kStateTimer.FUN_1408687f0();
}

// @0x140adda30
CBreakableObject::~CBreakableObject()
{
    if (m_spEntity)
    {
        egmAnimation::AnimationService* pService = g_143b059e8.GetSystemServiceAs<egmAnimation::AnimationService>();
        if (pService)
        {
            NiActorManager* pMgr = pService->GetActorManager(m_spEntity->GetEntityID());
            if (pMgr)
            {
                if (DAT_143ae2b30 != 0)
                {
                    AnimationCallbackManager::GetInstance()->FUN_14099bb80(pMgr, 0);
                }
                else
                {
                    pMgr->SetCallbackObject(0);
                    pMgr->ClearAllRegisteredCallbacks();
                }
            }
        }
        NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
        if (pRoot)
            FUN_14098b3e0(pRoot, 1.0f, false);
    }
    FUN_140ae0720();
    if (IsTombStone() != 0)
    {
        if (m_spEntity)
            FUN_1414737d0(m_spEntity);
    }
    m_spEntity = 0;
    FUN_140ae0b90();
    m_spActorData = 0;
    if (!m_aEffects.IsEmpty())
    {
        size_t nCount = m_aEffects.GetCount();
        for (size_t i = 0; i < nCount; i++)
            FUN_1403ed280()->FUN_1411a6060(m_aEffects[i]);
    }
    m_aEffects.RemoveAll();
}

// @0x140adde00
void CBreakableObject::SetName(CString strName)
{
    m_strName = strName;
}
MS2_REPLACE_METHOD(0x140adde00, CBreakableObject, SetName, 0, 0);

// @0x140adde50
CString CBreakableObject::GetName()
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x140adde50, CBreakableObject, GetName, 0, 0);

// @0x140addea0
int CBreakableObject::FUN_140addea0()
{
    if (!m_bHittable)
        return 0;
    if (IsTombStone() == 0 && m_kHitTimer.FUN_140868ba0() != 0)
        return 0;
    return m_nState == 2;
}
MS2_REPLACE_METHOD(0x140addea0, CBreakableObject, FUN_140addea0, 0, 0);

// MS2-FUNCTIONAL: the exe tests m_spBox through MS2Ptr::get (0x140a006f0) and builds both point temps up front; same calls
// @0x140addf10
MS2Ptr<CBoxCollision> CBreakableObject::FUN_140addf10()
{
    if (m_spBox.get())
        m_spBox->vfunc_3(Vector3(m_ptPos), Vector3(m_ptRot), 1.0f);
    return m_spBox;
}

// MS2-FUNCTIONAL: the exe's point copy sits 8 bytes higher in the frame (one more 8-byte temp); same calls
// @0x140ade030
void CBreakableObject::FUN_140ade030(int nHitter, int nKind)
{
    Common::Constants::Value<float>* pVolume = (nKind == 1 || nKind == 2)
        ? &static_cast<Client::Constants*>(FUN_1401d3200())->VolumeMyPcToBreakableObject
        : &static_cast<Client::Constants*>(FUN_1401d3200())->VolumePcToBreakableObject;
    float fVolume = pVolume->Read();
    efd::Point3 kPos = m_ptPos;
    FUN_1403ed280()->FUN_1411a5580(nHitter, m_nHitSound, nKind, static_cast<const NiPoint3&>(kPos), fVolume);
    m_kHitTimer.FUN_140868750(1000);
}

// @0x140ade120
int CBreakableObject::vfunc_1(egf::Entity* pEntity, int nState)
{
    m_spEntity = pEntity;
    m_spActorData = EE_NEW egfPhysX::EntityActorData(pEntity);
    FUN_140997ab0(pEntity, static_cast<CGlobalKeyTextCallback*>(this));
    FUN_140adf9d0(pEntity);
    efd::utf8string strId;
    efd::ParseHelper<efd::ID128>::ToString(pEntity->GetDataFileID(), strId);
    if (IsTombStone() != 0)
    {
        m_spEntity->GetPropertyValue(0x85b708e6, m_nTombId);
        m_strName.Format("%d", m_nTombId);
        if (!m_strIdleEffect.IsEmpty())
            FUN_140ae0a90(m_strIdleEffect);
    }
    else
    {
        m_strName = FUN_140188f50(strId.c_str(), 0);
        FUN_1401d3700(m_strName);
    }
    FUN_140ade420(nState, 0);
    return 1;
}

// Plays a random animation of the list on the entity.
// @0x140ade420
void CBreakableObject::FUN_140ade420(int nState, unsigned int nDelay)
{
    m_nState = nState;
    m_kStateTimer.FUN_1408687f0();
    if (nDelay > 0)
        m_kStateTimer.FUN_140868750(nDelay);
    if (m_spEntity == 0)
        return;
    if (m_nState == 5)
    {
        if (m_fSpeed == 0.0f && m_strIdleEffect.IsEmpty())
        {
            FUN_140ae0e40();
            FUN_140ae0ec0(5000);
        }
        FUN_140ae07d0(1);
        FUN_140ae0a90(m_strRegenEffect);
        if (m_bHasAnim != 0 && !m_aRegenAnims.IsEmpty())
        {
            int nIndex = rand() % m_aRegenAnims.GetCount();
            efd::utf8string strAnim(m_aRegenAnims[nIndex]);
            FUN_141b6f910()->FUN_1409a1fc0(m_spEntity->GetEntityID(), strAnim, 1.0f, true);
        }
    }
    else if (m_nState == 2)
    {
        if (m_fSpeed == 0.0f && m_strIdleEffect.IsEmpty())
        {
            FUN_140ae0e40();
            FUN_140ae0ec0(5000);
        }
        MakeNxBoxController();
        if (m_bHasAnim != 0)
            FUN_141b6f910()->FUN_1409a1fc0(m_spEntity->GetEntityID(), m_strIdleAnim, 1.0f, true);
        FUN_140ae07d0(1);
    }
    if (m_nState == 6)
    {
        FUN_140ae0e40();
        MakeNxBoxController();
        FUN_140ae0a90(m_strDamageEffect);
        if (m_bHasAnim != 0 && !m_aDamageAnims.IsEmpty())
        {
            int nIndex = rand() % m_aDamageAnims.GetCount();
            efd::utf8string strAnim(m_aDamageAnims[nIndex]);
            FUN_141b6f910()->FUN_1409a1fc0(m_spEntity->GetEntityID(), strAnim, 1.0f, true);
        }
        FUN_140ae07d0(1);
    }
    else if (m_nState == 3)
    {
        FUN_140ae0e40();
        FUN_140ae0720();
        FUN_140ae0a90(m_strDeadEffect);
        if (m_bHasAnim != 0 && !m_aReviveAnims.IsEmpty())
        {
            int nIndex = rand() % m_aReviveAnims.GetCount();
            efd::utf8string strAnim(m_aReviveAnims[nIndex]);
            FUN_141b6f910()->FUN_1409a1fc0(m_spEntity->GetEntityID(), strAnim, 1.0f, false);
        }
        FUN_140ae07d0(1);
    }
    else if (m_nState == 4)
    {
        FUN_140ae0e40();
        FUN_140ae0720();
        FUN_140ae07d0(0);
    }
}
MS2_REPLACE_METHOD(0x140ade420, CBreakableObject, FUN_140ade420, 0, 0);

// @0x140adea80
int CBreakableObject::GetState()
{
    return m_nState;
}
MS2_REPLACE_METHOD(0x140adea80, CBreakableObject, GetState, 0, 0);

// @0x140adeaa0
void CBreakableObject::FUN_140adeaa0(int nSyncA, int nSyncB, int nSyncC)
{
    m_nSyncA = nSyncA;
    m_nSyncB = nSyncB;
    m_nSyncC = nSyncC;
}
MS2_REPLACE_METHOD(0x140adeaa0, CBreakableObject, FUN_140adeaa0, 0, 0);

// The moving object runs a cycle: wait, go (m_fMoveTime), wait, come back; the position is the base plus the move
// direction times the speed times the time on the way. A synced object derives its cycle time from the server tick.
// MS2-FUNCTIONAL: per-frame movement update: same calls and math, different temp / branch layout
// @0x140adeaf0
void CBreakableObject::FUN_140adeaf0(int nNow)
{
    m_ptVelocity = efd::Point3::ZERO;
    if (static_cast<MS2EntityManagerService*>(FUN_140ae11e0())->FUN_1414b54f0(m_spEntity))
        FUN_140adf9d0(m_spEntity);
    if (m_kDetachTimer.FUN_140868c00())
    {
        m_kDetachTimer.FUN_1408687f0();
        FUN_140ae0ec0(0);
    }
    if (m_kStateTimer.FUN_140868c00())
    {
        m_kStateTimer.FUN_1408687f0();
        FUN_140adf6e0();
    }
    if (0.0f < m_fMoveTime && m_fSpeed != 0.0f && (m_nState == 2 || m_nState == 5 || m_nState == 6))
    {
        if (m_nPhase == 0)
        {
            m_nPhaseTime = FUN_14086d260()->FUN_141473410(nNow);
            m_nPhaseStart = nNow;
        }
        int nElapsed = m_nPhaseTime + (nNow - m_nPhaseStart);
        unsigned int nTime = nElapsed + FUN_14028d260(m_fMoveDelay) + m_nSyncB;
        unsigned int nWait0 = FUN_14028d260(m_afWait[0]);
        unsigned int nGo = nWait0 + FUN_14028d260(m_fMoveTime);
        unsigned int nWait1 = nGo + FUN_14028d260(m_afWait[1]);
        unsigned int nBack = nWait1 + FUN_14028d260(m_fMoveTime);
        unsigned int nCycle = nBack;
        if (m_nMoveMode == 1)
            nCycle = nWait1;
        unsigned int nPos = nTime % nCycle;
        if (m_nSyncA == 0 && m_nSyncC < nTime)
            nPos = m_nSyncC % nCycle;
        if (nWait0 < nPos)
        {
            if (nWait0 < nPos && nPos <= nGo)
            {
                nPos = nPos - nWait0;
                FUN_140adf830(m_ptRotBase);
                if (m_nPhase != 2)
                    FUN_140ae06a0(2, nNow);
            }
            else if (nGo < nPos && nPos <= nWait1)
            {
                nPos = FUN_14028d260(m_fMoveTime);
                if (m_nMoveMode == 2)
                    FUN_140adf830(m_ptRotBase + efd::Point3(0.0f, 0.0f, 180.0f));
                if (m_nPhase != 3)
                    FUN_140ae06a0(3, nNow);
            }
            else
            {
                nPos = nCycle - nPos;
                if (m_nMoveMode == 2)
                    FUN_140adf830(m_ptRotBase + efd::Point3(0.0f, 0.0f, 180.0f));
                if (m_nPhase != 3)
                    FUN_140ae06a0(4, nNow);
            }
        }
        else
        {
            nPos = 0;
            FUN_140adf830(m_ptRotBase);
            if (m_nPhase != 1)
                FUN_140ae06a0(1, nNow);
        }
        efd::Point3 ptOld = GetPtPos();
        float fTime = FUN_14028d280(nPos);
        FUN_140adf770(m_ptPosBase + m_ptMoveDir * m_fSpeed * fTime);
        m_ptVelocity = GetPtPos() - ptOld;
        m_ptVelocity.Unitize();
    }
    if (m_kFadeTimer.FUN_140868c00())
    {
        m_kFadeTimer.FUN_1408687f0();
        bool bFade = false;
        m_spEntity->SetPropertyValue(0xa0b6b179, bFade);
    }
    if (m_pActor != 0 && m_bActorDirty != 0)
    {
        NxVec3 kPos(m_ptPos.x, m_ptPos.y, m_ptPos.z);
        kPos = kPos * 0.01f;
        kPos.z = kPos.z + m_ptSize.z * 0.01f * 0.5f;
        FUN_1409f7ca0()->FUN_14168a540(0);
        m_pActor->setGlobalPosition(kPos);
        FUN_1409f7ca0()->FUN_14168a570();
        m_bActorDirty = 0;
    }
}

// @0x140adf310
bool CBreakableObject::FUN_140adf310()
{
    return m_bC1;
}
MS2_REPLACE_METHOD(0x140adf310, CBreakableObject, FUN_140adf310, 0, 0);

// @0x140adf330
int CBreakableObject::IsTombStone()
{
    return m_bTombStone;
}
MS2_REPLACE_METHOD(0x140adf330, CBreakableObject, IsTombStone, 0, 0);

// @0x140adf350
int CBreakableObject::FUN_140adf350()
{
    return m_n184;
}
MS2_REPLACE_METHOD(0x140adf350, CBreakableObject, FUN_140adf350, 0, 0);

// A tomb stone: the model ids decide the variant, the gem data gives the four effects.
// MS2-FUNCTIONAL: tomb stone bind: same calls, the exe's CString temp and ContainsModel order differ
// @0x140adf370
void CBreakableObject::FUN_140adf370(egf::Entity* pEntity, int nArg, MS2Ptr<CGemTombStone> spTomb)
{
    m_spEntity = pEntity;
    FUN_140ae0b90();
    bool bDark = false;
    const egf::FlatModel* pModel = pEntity->GetModel();
    if (pModel == 0)
        return;
    if (pModel->ContainsModel(0xee380f26))
    {
        m_bTombStone = 1;
    }
    else if (pModel->ContainsModel(0x88a73561))
    {
        m_bTombStone = 1;
        bDark = true;
    }
    m_aRegenAnims.RemoveAll();
    m_aDamageAnims.RemoveAll();
    m_aReviveAnims.RemoveAll();
    if (spTomb.get() == 0)
    {
        m_bTombEffects = false;
        FUN_140ae0c20(pEntity);
    }
    else
    {
        m_strIdleAnim = "Idle_A";
        m_aRegenAnims.Add(CString("Regen_A"));
        m_aDamageAnims.Add(CString("Damg_A"));
        m_aReviveAnims.Add(CString("Revive_A"));
        MS2Ptr<CGemTombStoneData> spData = spTomb->FUN_1405a53c0();
        if (spData.get())
        {
            CGemTombStoneData::TModelAttr& kAttr = bDark ? spData->m_attrB : spData->m_attrA;
            m_strIdleEffect = kAttr.m_strIdleEffect;
            m_strRegenEffect = kAttr.m_strRegenEffect;
            m_strDamageEffect = kAttr.m_strDmgEffect;
            m_strReviveEffect = kAttr.m_strReviveEffect;
            m_strDeadEffect = m_strReviveEffect;
        }
        m_bTombEffects = true;
    }
}

// @0x140adf6e0
void CBreakableObject::FUN_140adf6e0()
{
    m_kStateTimer.FUN_1408687f0();
    if (IsTombStone() != 0)
    {
        switch (m_nState)
        {
        case 6:
            FUN_140ade420(2, 0);
            break;
        case 5:
            FUN_140ade420(2, 0);
            break;
        case 3:
            m_n184 = 1;
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x140adf6e0, CBreakableObject, FUN_140adf6e0, 0, 0);

// @0x140adf770
void CBreakableObject::FUN_140adf770(efd::Point3 ptPos)
{
    if ((egf::Entity*)m_spEntity != 0 && m_ptPos != ptPos)
    {
        if (!FUN_140a33ff0(ptPos))
            return;
        m_ptPos = ptPos;
        m_spEntity->SetPropertyValue(0xfd95ca52, m_ptPos);
        m_bActorDirty = 1;
    }
}

// @0x140adf830
void CBreakableObject::FUN_140adf830(efd::Point3 ptRot)
{
    if ((egf::Entity*)m_spEntity != 0 && m_ptRot != ptRot)
    {
        if (!FUN_140a33ff0(ptRot))
            return;
        m_ptRot = ptRot;
        m_spEntity->SetPropertyValue(0x68c7c29d, m_ptRot);
    }
}

// @0x140adf8e0
efd::Point3 CBreakableObject::GetPtPos()
{
    return m_ptPos;
}
MS2_REPLACE_METHOD(0x140adf8e0, CBreakableObject, GetPtPos, 0, 0);

// @0x140adf920
void CBreakableObject::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    CGlobalKeyTextCallback::EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
    FUN_140adf6e0();
}

// @0x140adf980
egf::EntityPtr CBreakableObject::GetEntity()
{
    return m_spEntity;
}

// MS2-FUNCTIONAL: property read + box build: same calls, Vector3 temp order differs
// @0x140adf9d0
void CBreakableObject::FUN_140adf9d0(egf::Entity* pEntity)
{
    pEntity->GetPropertyValue(0x2683e9ec, m_bHittable);
    pEntity->GetPropertyValue(0x9dc22aea, m_ptSize);
    pEntity->GetPropertyValue(0xada5c5d2, m_nGroup);
    if (m_ptSize == efd::Point3::ZERO)
        m_bHittable = false;
    if (IsTombStone() == 0)
        pEntity->GetPropertyValue(0x3ff293c8, m_strIdleAnim);
    pEntity->GetPropertyValue(0xd89e9b12, m_bShadow);
    pEntity->GetPropertyValue(0x54adb2fd, m_bC1);
    pEntity->GetPropertyValue(0xd3ba88ae, m_bPhysics);
    pEntity->GetPropertyValue(0x0c10618b, m_ptMoveDir);
    pEntity->GetPropertyValue(0x1994cfe8, m_fMoveDelay);
    float fDistance = 0.0f;
    pEntity->GetPropertyValue(0x83d0f1ba, fDistance);
    pEntity->GetPropertyValue(0xf6068266, m_fMoveTime);
    pEntity->GetPropertyValue(0x000bd4a6, m_afWait[0]);
    pEntity->GetPropertyValue(0x000bd4bc, m_afWait[1]);
    m_ptMoveDir.Unitize();
    if (0.0f < m_fMoveTime)
        m_fSpeed = fDistance / m_fMoveTime;
    CString str;
    efd::utf8string strRevive;
    pEntity->GetPropertyValue(0xc9385319, strRevive);
    str = strRevive.c_str();
    m_aReviveAnims.RemoveAll();
    FUN_14015f050(str, m_aReviveAnims, ",");
    if (IsTombStone() == 0 || !m_bTombEffects)
    {
        efd::utf8string strEffect;
        pEntity->GetPropertyValue(0xf509dc4a, strEffect);
        if (!strEffect.empty())
            m_strDeadEffect = strEffect.c_str();
    }
    pEntity->GetPropertyValue(0xfd95ca52, m_ptPos);
    pEntity->GetPropertyValue(0x68c7c29d, m_ptRot);
    pEntity->GetPropertyValue(0x76ba4184, m_nMoveMode);
    m_ptRotBase = m_ptRot;
    m_ptPosBase = m_ptPos;
    Vector3 kSize(m_ptSize.x, m_ptSize.y * 0.5f, m_ptSize.z);
    Vector3 kOffset(0.0f, m_ptSize.y * 0.5f, 0.0f);
    m_spBox.AssignRaw(new CBoxCollision);
    m_spBox->m_ptBox = kSize;
    m_spBox->m_ptSize = kOffset;
    m_spBox->m_kColor = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    m_spBox->vfunc_4();
    m_spBox->vfunc_3(Vector3(m_ptPos), Vector3(m_ptRot), 1.0f);
    pEntity->GetPropertyValue(0xa34897b1, m_spBox->m_b54);
    pEntity->GetPropertyValue(0x8843d885, m_nHitSound);
    m_bHasAnim = pEntity->GetModel()->ContainsModel(0x48ccc02d);
}

// @0x140ae0150
efd::Point3 CBreakableObject::GetPtVelocity()
{
    return m_ptVelocity;
}
MS2_REPLACE_METHOD(0x140ae0150, CBreakableObject, GetPtVelocity, 0, 0);

// @0x140ae0190
void CBreakableObject::FUN_140ae0190()
{
    if ((double)m_fTimeScale == FUN_14086d260()->FUN_141473280())
        return;
    m_fTimeScale = (float)FUN_14086d260()->FUN_141473280();
    FUN_140ae0720();
    MakeNxBoxController();
}
MS2_REPLACE_METHOD(0x140ae0190, CBreakableObject, FUN_140ae0190, 0, 0);

// @0x140ae0210
void CBreakableObject::MakeNxBoxController()
{
    if (!m_bPhysics)
        return;
    if (m_pActor != 0)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (pScene == 0)
        return;
    {
        {
            NxVec3 kPos;
            efdPhysX::PhysXTypes::Point3ToNxVec3(m_ptPos, kPos);
            NxBodyDesc* pBodyDesc = 0;
            NxBodyDesc kBodyDesc;
            if (0.0f < m_fMoveTime && m_fSpeed != 0.0f)
            {
                kBodyDesc.flags |= NX_BF_KINEMATIC;
                kBodyDesc.mass = 1.0f;
                kBodyDesc.massSpaceInertia.set(1.0f, 1.0f, 1.0f);
                pBodyDesc = &kBodyDesc;
            }
            NxBoxShapeDesc kBoxDesc;
            kBoxDesc.dimensions.set(m_ptSize.x, m_ptSize.y, m_ptSize.z);
            kBoxDesc.dimensions = kBoxDesc.dimensions * 0.01f * 0.5f;
            kBoxDesc.groupsMask.bits0 = 0xffffffff;
            kBoxDesc.shapeFlags &= ~(NX_SF_CLOTH_TWOWAY | NX_SF_SOFTBODY_TWOWAY);
            NxActorDesc kActorDesc;
            kActorDesc.body = pBodyDesc;
            kActorDesc.shapes.pushBack(&kBoxDesc);
            efd::Point3 kPoint = m_ptPos;
            kActorDesc.globalPose.t = NxVec3(kPoint.x, kPoint.y, kPoint.z);
            kActorDesc.globalPose.t = kActorDesc.globalPose.t * 0.01f;
            kActorDesc.globalPose.t.z += kBoxDesc.dimensions.z;
            kActorDesc.globalPose.M.rotZ(m_ptRot.z * 3.1415927f / 180.0f);
            FUN_1409f7ca0()->FUN_14168a540(0);
            m_pActor = pScene->createActor(kActorDesc);
            if (m_pActor != 0)
            {
                m_pActor->setName("CBreakableObject::MakeNxBoxController");
                NxU32 nShapes = m_pActor->getNbShapes();
                NxShape* const* ppShapes = m_pActor->getShapes();
                for (NxU32 i = 0; i < nShapes; i++)
                {
                    NxShape* pShape = ppShapes[i];
                    pShape->setGroup(m_nGroup);
                }
                m_pActor->userData = m_spActorData;
            }
            FUN_1409f7ca0()->FUN_14168a570();
        }
    }
}

// @0x140ae0660
efd::Point3 CBreakableObject::GetPtSize()
{
    return m_ptSize;
}
MS2_REPLACE_METHOD(0x140ae0660, CBreakableObject, GetPtSize, 0, 0);

// @0x140ae06a0
void CBreakableObject::FUN_140ae06a0(int nPhase, int nNow)
{
    m_nPhaseTime = FUN_14086d260()->FUN_141473410(nNow);
    m_nPhaseStart = nNow;
    m_nPhase = nPhase;
}
MS2_REPLACE_METHOD(0x140ae06a0, CBreakableObject, FUN_140ae06a0, 0, 0);

// @0x140ae0700
bool CBreakableObject::FUN_140ae0700()
{
    if (m_nSyncA != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140ae0700, CBreakableObject, FUN_140ae0700, 0, 0);

// @0x140ae0720
void CBreakableObject::FUN_140ae0720()
{
    if (!m_bPhysics)
        return;
    if (m_pActor != 0)
    {
        NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
        if (pScene != 0)
        {
            FUN_1409f7ca0()->FUN_14168a540(0);
            pScene->releaseActor(*m_pActor);
            WorldService::GetInstance()->FUN_141bc8e00();
            FUN_1409f7ca0()->FUN_14168a570();
            m_pActor = 0;
        }
    }
}

// @0x140ae07d0
void CBreakableObject::FUN_140ae07d0(int bShow)
{
    if (bShow != 0)
    {
        bool bFade = true;
        m_spEntity->SetPropertyValue(0xa0b6b179, bFade);
        m_kFadeTimer.FUN_1408687f0();
        reinterpret_cast<Unk_BoEffectService*>(FUN_1403ed280())->FUN_1411a6f00(m_spEntity->GetEntityID());
        NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
        if (pRoot != 0)
            FUN_14098b3e0(pRoot, 1.0f, false);
    }
    else
    {
        NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
        if (pRoot != 0)
            FUN_140ae1e80(pRoot, 1.0f, 0.0f, 0.0f, FUN_14028d280(500), m_spEntity->GetEntityID());
        m_kFadeTimer.FUN_140868750(500);
    }
    FUN_140ae0990(bShow);
}

// MS2-FUNCTIONAL: the exe materialises the shadow compare as an int temp (jl, 1/0) before narrowing to bool; same calls
// @0x140ae0990
void CBreakableObject::FUN_140ae0990(int bShow)
{
    if (bShow != 0)
    {
        NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
        if (pRoot != 0 && m_bShadow && (IsTombStone() == 0 || m_nState != 5))
        {
            int nQuality = FUN_140ae1c10();
            FUN_141567330(pRoot, nQuality >= TSingleton<CGraphicOptionTable>::GetInstance()->GetShadowOption(5) ? true : false);
        }
    }
    else
    {
        NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
        if (pRoot != 0)
            FUN_141567330(pRoot, false);
    }
}

// @0x140ae0a90
void CBreakableObject::FUN_140ae0a90(const CString& strEffect)
{
    if (strEffect.IsEmpty() || m_spEntity == 0)
        return;
    Unk_EffectTarget kTarget;
    kTarget.m_strName = strEffect;
    kTarget.m_nKind = 1;
    kTarget.m_spObject = NiDynamicCast(NiNode, FUN_141b6efc0(m_spEntity));
    unsigned int nId = FUN_1403ed280()->FUN_1411a49c0(kTarget);
    if (nId != 0)
        m_aEffects.Add(nId);
}

// @0x140ae0b90
void CBreakableObject::FUN_140ae0b90()
{
    m_strIdleEffect = "";
    m_strRegenEffect = "";
    m_strDamageEffect = "";
    m_strReviveEffect = "";
    m_bTombEffects = false;
}
MS2_REPLACE_METHOD(0x140ae0b90, CBreakableObject, FUN_140ae0b90, 0, 0);

// @0x140ae0c20
void CBreakableObject::FUN_140ae0c20(egf::Entity* pEntity)
{
    CString str;
    efd::utf8string strRegen;
    pEntity->GetPropertyValue(0x2ec0ee97, strRegen);
    str = strRegen.c_str();
    FUN_14015f050(str, m_aRegenAnims, ",");
    efd::utf8string strDamage;
    pEntity->GetPropertyValue(0x487e2afd, strDamage);
    str = strDamage.c_str();
    FUN_14015f050(str, m_aDamageAnims, ",");
    pEntity->GetPropertyValue(0x3ff293c8, m_strIdleAnim);
    if (!m_aRegenAnims.IsEmpty())
    {
        int nIndex = rand() % m_aRegenAnims.GetCount();
        efd::utf8string strAnim(m_aRegenAnims[nIndex]);
        static_cast<Unk_CachedEntity*>(pEntity)->SetPropertyValue(0x3ff293c8, strAnim);
    }
}

// @0x140ae0e40
void CBreakableObject::FUN_140ae0e40()
{
    if (m_bDetached)
        return;
    if (m_spEntity == 0)
        return;
    FUN_1414f11d0(GetSceneGraphService(), m_spEntity);
    m_bDetached = true;
}

// @0x140ae0ec0
void CBreakableObject::FUN_140ae0ec0(int nDelay)
{
    if (!m_bDetached)
        return;
    if (m_spEntity == 0)
        return;
    if (nDelay != 0)
    {
        m_kDetachTimer.FUN_140868750(nDelay);
    }
    else
    {
        FUN_1414f1240(GetSceneGraphService(), m_spEntity);
        m_bDetached = false;
    }
}

// ---- CGlobalKeyTextCallback: inline ctor / dtor (first instantiated here) ----
// @0x140ae13d0
CGlobalKeyTextCallback::CGlobalKeyTextCallback()
{
}

// MS2-FUNCTIONAL: the exe dtor (inline in the original header) has no vftable store; the declared out-of-line body adds one
// @0x140ae16e0
CGlobalKeyTextCallback::~CGlobalKeyTextCallback()
{
}

// ---- UCRT memmove_s (static inline per TU; RelocateElements of CAtlArray<NiPoint2>) ----
// @0x140ae2c00
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// fx25: the 15-byte MS2Ptr<T>::get look-alike pair; FUN_140adf370 calls 0x140ae1930 on its MS2Ptr<CGemTombStone> param
// MS2-PIN: ?get@?$MS2Ptr@VCGemTombStone@@@@QEBAPEAVCGemTombStone@@XZ 0x140ae1930
