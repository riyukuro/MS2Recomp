// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The couple-emotion actor state: StateCoupleEmotionData (the
// state's payload, mirrored into / out of the state-sync record), CoupleEmotionAnimInfo (the loaded animation set of one
// running emotion) and StateCoupleEmotion (state type 0x3a). Also the request entry point the emotion UI calls, its
// placement / failure helpers and this unit's MS2Ptr / vector<CString> instantiation copies. See statecoupleemotion.h.
// MS2-UNIT: client\ms2\statecoupleemotion.cpp
// MS2-RANGE: 0x1400c90a0-0x1400c9240 .text$di
// MS2-RANGE: 0x140b7fa70-0x140b866d0 .text$mn
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VStateSyncObjectCoupleEmotion@@@@AEAAXPEAX@Z 0x140b86680 ; merge-bind
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statecoupleemotion.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uimessageboxdata.h"

#include <new>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <efd/utf8string.h>
#include <NiNode.h>
#include <NiTransform.h>
#include <NiMatrix3.h>
#include <NiFixedString.h>
#include <NiTimeController.h>
#include <NiMultiTargetTransformController.h>
#include <NiTransformController.h>
#include <NiPathInterpolator.h>

#include "ms2/placeholder/statecoupleemotion.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/commonfiles/statesyncobject.h"
#include "ms2/placeholder/ccoupleemotiontable.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/unnamed/unit_140b0e5f0.h"            // Unk_CoupleVec (out-of-line NiPoint3 copy 0x14027dcf0)

// The unit's own header static, ahead of the shared header statics.
static CStringW s_strCoupleEmotion(L"coupleEmotion");                             // @0x1400c90a0

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/cmainsystem.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// StateData slots 1 / 2 argument: the state-sync record.
class Unk_StateDataArg : public Unk_StateArg22 { };

// Node names of the two actors in the couple nif and the centre node ("B", "A", "Eff_center").
extern const char* PTR_DAT_1439f4da0;
extern const char* PTR_DAT_1439f4da8;
extern const char* PTR_s_Eff_center_1439f4db0;

// The scene-graph loader (nifs by path) and the NiRTTI-checked dynamic cast.
class CNifLoadingService
{
public:
    NiAVObjectPtr Load(CString strPath, bool bFlag, int nClass, int nMyRefs, int nOtherRefs);   // 0x141551ea0 load a nif
};
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0

// Depth-first walk over a scene graph (0x30-byte iterator).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);                                     // 0x14098cb80
    ~Unk_NodeQueue();                                                      // 0x14098cf00
    NiAVObject* Next(bool bDescend);                                       // 0x14098e0d0 next object (0 at the end)
    void* m_p[6];
};

// Time and client services.
unsigned long GetTickCountMs2();   // C3: was FUN_140869420

// The emotion table (0x1401958b0) and its rows.
class Unk_EmoRow : public CPtred
{
public:
    char m_pad_18[0x18];
    int m_n30;                                                             // +0x30 the actor's height offset
};

// World service lookups.

// The effect service (0x1403ed280): plays / stops effects.

// PCBase / MyPC non-virtual helpers (free-function form: `this` is the first argument).

#include "ms2/placeholder/nipoint3.h"   // C3: Vector3, the CPhysXHelper argument type
// The physics service: ray casts.
class CPhysXHelper
{
public:
    int FUN_14168a450(const efd::Point3& ptFrom, float* pDist, float fLen);                            // closest hit distance
    bool FUN_14168a770(const Vector3* pPoint);                                                    // the point is blocked
    int FUN_14168a230(efd::Point3 ptFrom, efd::Point3& ptHit, efd::Point3 ptDir, float fLen, int nMask);   // line is blocked (RayCastFromPoint; Vector3 by value drops the Point3 copies)
    int RayCastFixedDirection(const Vector3& ptFrom, Vector3& ptHit, struct Unk_RayCastInfo* pInfo, float fLen, Vector3* pNormal, int nA);
};
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0

// The actor's pet-buff position buffer (see statesummon.cpp).
#include "ms2/placeholder/nipoint3.h"   // C3: Vector3, the return type of Unk_PCMove::FUN_141683290
class Unk_PCMove { public: Vector3 FUN_141683290(); };   // C3: view of the real class (unit_141682f80)
class Unk_CeBuffMgr { public: };
Unk_CeBuffMgr* FUN_14166d240(PCBase* p);                                   // 0x14166d240

// Entity registry / game objects.
int FUN_140b7f6a0(void* pRegistry, const egf::EntityID& kEntity);
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();                           // 0x141b6f910 (util.cpp); the call casts to Unk_CeRegistry

// UI helpers.
template <class A> CStringW FormatStringId(int nId, const A& a);
void FUN_1412751f0(const CStringW& text, int nA, int nB);                  // 0x1412751f0 notice
void FUN_141275260(int nStringId, int nA, int nB);                         // 0x141275260 notice by string id

// The game's constants table, the slot holding the maximum distance of a couple emotion (+0x37e0).
class Unk_CeConstSlot { public: char m_pad0[1]; };
class Unk_CeConsts { public: char m_pad0[0x37e0]; Unk_CeConstSlot m_maxDist; };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// Opaque scene-graph and math helpers of the placement search (free-function form).
void FUN_140a0b2a0(NiAVObject* pObject);                                   // 0x140a0b2a0 detach from the parent
void FUN_140a0b1f0(const NiMatrix3&, efd::Point3&);   // C3: rotation to euler angles (degrees, negated)
float FUN_140967ac0(const NiPoint3& kVec);                                 // 0x140967ac0 length
int FUN_1408a01e0(CStringA s);                                      // 0x1408a01e0 string -> id
MS2Ptr<CMsgBoxData> FUN_14151f820();                                      // 0x14151f820 the message box currently shown

// The ray cast record FUN_14168a310 fills (0x68; physxhelper.h needs NOMINMAX, so it is redeclared as in state.cpp).
struct Unk_RayCastInfo
{
    Unk_RayCastInfo();                                  // 0x140ad4440
    efd::Point3 m_origin;                               // +0x00
    efd::Point3 m_dir;                                  // +0x0c
    float m_maxDist;                                    // +0x18
    int m_groups;                                       // +0x1c
    void* m_20;
    void* m_28;
    void* m_hitEntity;                                  // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                    // +0x48
    efd::Point3 m_hitPoint;                             // +0x4c
    efd::Point3 m_hitNormal;                            // +0x58
};
MS2_CHECK_SIZE(Unk_RayCastInfo, 0x68);
NiTransform* FUN_140a33de0(const NiTransform& kA, NiTransform* pOut, const NiTransform& kB);   // 0x140a33de0 compose
void FUN_140a35bd0(efd::Matrix3* pDest, const NiTransform* pSrc);          // 0x140a35bd0 store the rotation part
void FUN_140b850d0(void* pLogger, int nLevel, int nId, const wchar_t* pszFmt, const char* const* ppszArg0,
    const CStringA& strArg1);                                              // 0x140b850d0 log with two {n} argumentsCStringA FUN_140a52ef0();                                                  // 0x140a52ef0 empty effect-param block ctor
template <class T> void Unk_ShopLog(class CLogString*, int, int, const wchar_t*, const T&);   // 0x140353fc0 log
class CLogString* GetLogString();   // C3: was FUN_140166440

// ---- local helpers declared early ---------------------------------------------------------------------------------------
bool FUN_140b83fa0(const NiPoint3& kA, const NiPoint3& kB);         // 0x140b83fa0
bool FUN_140b83f60(int nState);                                     // 0x140b83f60
bool FUN_140b83ec0();                                               // 0x140b83ec0
bool FUN_140b84dc0(const NiPoint3& kPoint);                         // 0x140b84dc0 the point is placeable
void FUN_140b86230(const efd::Point3& kEuler, NiMatrix3& kOut);  // 0x140b86230

// ---- StateCoupleEmotionData -------------------------------------------------------------------------------------------

// @0x140b7fa70
StateCoupleEmotionData::StateCoupleEmotionData()
    : m_nEmotion(0), m_nPartnerId(0), m_nRequesterId(0), m_nAni(0)
{
}

// Mirrors the payload into the couple-emotion part of the sync record.
// @0x140b7fb00
void StateCoupleEmotionData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    StateSyncObjectCoupleEmotion* pSync = dynamic_cast<StateSyncObjectCoupleEmotion*>(p);
    if (pSync == 0)
        return;
    pSync->m_n64 = m_nEmotion;
    pSync->m_nBC = m_nPartnerId;
    pSync->m_nB8 = m_nRequesterId;
    pSync->m_nC0 = (unsigned char)m_nAni;
    pSync->m_posD0 = m_posStart;
    pSync->m_posC4 = m_posEnd;
}

// The reverse of vfunc_1.
// @0x140b7fbe0
void StateCoupleEmotionData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    StateSyncObjectCoupleEmotion* pSync = dynamic_cast<StateSyncObjectCoupleEmotion*>(p);
    if (pSync == 0)
        return;
    m_nEmotion = pSync->m_n64;
    m_nPartnerId = pSync->m_nBC;
    m_nRequesterId = pSync->m_nB8;
    m_nAni = pSync->m_nC0;
    m_posStart = pSync->m_posD0;
    m_posEnd = pSync->m_posC4;
}

// ---- CoupleEmotionAnimInfo --------------------------------------------------------------------------------------------

// Which of the two actors plays the first animation set: the requester when the genders differ or when asked to swap.
// @0x140b85080
static bool FUN_140b85080(int nGender1, int nGender2, bool bSwap)
{
    if (nGender1 == nGender2)
        return bSwap;
    return nGender1 != 0;
}

// Picks the table row of nEmotion, copies its teleport effect and the animation set of the gender pairing.
// @0x140b7fcc0
bool CoupleEmotionAnimInfo::Init(int nEmotion, int nGender1, int nGender2, bool bSwap)
{
    MS2Ptr<CCoupleEmotionData> spData = TSingleton<CCoupleEmotionTable>::GetInstance()->GetData(nEmotion);
    if (!spData)
    {
        MS2_ASSERT_AT(0x4e, "pData" && 0);
        return false;
    }
    MS2Ptr<CCoupleEmotionData::AnimationData> spAni = spData->GetAni(nGender1, nGender2);
    if (!spAni)
    {
        MS2_ASSERT_AT(0x51, "pAniData" && 0);
        return false;
    }
    m_strTeleportEffect = spData->m_strTeleportEffect;
    m_bLoop = spAni->m_bLoop;
    m_nifPaths = spAni->m_nifPaths;
    if (FUN_140b85080(nGender1, nGender2, bSwap) == true)
    {
        m_strOwnerNode = PTR_DAT_1439f4da0;
        m_strPeerNode = PTR_DAT_1439f4da8;
        m_aniNames = spAni->m_requestAnis;
    }
    else
    {
        m_strOwnerNode = PTR_DAT_1439f4da8;
        m_strPeerNode = PTR_DAT_1439f4da0;
        m_aniNames = spAni->m_targetAnis;
    }
    return true;
}

// Loads the nif of animation nAni, finds the owner / peer / centre nodes in it and the controller that drives them.
// MS2-FUNCTIONAL: the controller walk uses the SDK's NiTimeController accessors where the exe calls two vtable slots of
// the multi-target controller.
// @0x140b7ff20
bool CoupleEmotionAnimInfo::Load(int nAni)
{
    if (nAni < 0 || nAni >= (int)m_nifPaths.size())
    {
        MS2_ASSERT_AT(0x6b, 0);
        return false;
    }
    CString strPath;
    strPath.Format("Data/Resource/Model/Path/%s", (const char*)m_nifPaths[nAni]);
    m_spNifRoot = ((class CNifLoadingService*)FUN_140a0afd0())->Load(strPath, 0, 5, 0, 0);
    if (!m_spNifRoot)
    {
        MS2_ASSERT_AT(0x72, "m_spNifRoot" && 0);
        return false;
    }
    m_spOwnerNode = (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, m_spNifRoot->GetObjectByName((const char*)m_strOwnerNode));
    if ((NiNode*)m_spOwnerNode == 0)
    {
        MS2_ASSERT_AT(0x75, "m_spOwnerNode" && 0);
        return false;
    }
    m_spPeerNode = (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, m_spNifRoot->GetObjectByName((const char*)m_strPeerNode));
    if ((NiNode*)m_spPeerNode == 0)
    {
        MS2_ASSERT_AT(0x78, "m_spPeerNode" && 0);
        return false;
    }
    m_spCenterNode = (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, m_spNifRoot->GetObjectByName(PTR_s_Eff_center_1439f4db0));
    if (m_spCenterNode == 0)
        m_spCenterNode = m_spOwnerNode;
    if ((NiNode*)m_spCenterNode == 0)
    {
        MS2_ASSERT_AT(0x7e, "m_spCenterNode" && 0);
        return false;
    }
    m_fStartTime = 0.0f;
    m_fDuration = 0.0f;
    Unk_NodeQueue walk((NiAVObject*)m_spNifRoot);
    while (NiAVObject* pObject = walk.Next(true))
    {
        NiTimeController* pCtrl = pObject->GetControllers();
        while (pCtrl != 0 && (int)pCtrl->GetAnimType() == 1)
        {
            pCtrl->SetAnimType((NiTimeController::AnimType)0);
            pCtrl = pCtrl->GetNext();
        }
    }
    for (NiTimeController* pCtrl = m_spOwnerNode->GetControllers(); pCtrl != 0;
         pCtrl = pCtrl->GetNext())
    {
        if (pCtrl->GetEndKeyTime() > m_fDuration)
            m_fDuration = pCtrl->GetEndKeyTime();
        // the path interpolator of the first transform controller that has one (later ones overwrite it)
        NiTransformController* pXf = (NiTransformController*)NiObject::DynamicCast(&NiTransformController::ms_RTTI, pCtrl);
        if (pXf == 0)
            continue;
        for (int i = 0; i < pXf->GetInterpolatorCount(); ++i)
        {
            m_spTarget = (NiObjectNET*)NiObject::DynamicCast(&NiPathInterpolator::ms_RTTI, pXf->GetInterpolator((unsigned short)i));
            if (m_spTarget != 0)
                break;
        }
    }
    SetStartTime((float)reinterpret_cast<CMainSystem*>(((void*)TSingleton<CMainSystem>::GetInstance()))->FUN_141473280());
    UpdateNif();
    return true;
}

// Advances the loaded nif to "now".
// @0x140b80630
void CoupleEmotionAnimInfo::UpdateNif()
{
    double dTime = reinterpret_cast<CMainSystem*>(((void*)TSingleton<CMainSystem>::GetInstance()))->FUN_141473280() - m_fStartTime;
    ((NiAVObject*)m_spNifRoot)->Update((float)dTime, true);
}

// The partner's animation name of animation nAni ("" when out of range).
// @0x140b806a0
CString CoupleEmotionAnimInfo::GetAniName(int nAni)
{
    if (nAni < 0)
        return "";
    if (nAni >= (int)m_aniNames.size())
        return "";
    return m_aniNames[nAni];
}

// @0x140b861f0
int CoupleEmotionAnimInfo::GetLastAni()
{
    return (int)m_aniNames.size() - 1;
}

// @0x140b86350
void CoupleEmotionAnimInfo::SetStartTime(float f)
{
    m_fStartTime = f;
}

// @0x140b85a20
CoupleEmotionAnimInfo::CoupleEmotionAnimInfo()
    : m_spNifRoot(0), m_spOwnerNode(0), m_spPeerNode(0), m_spCenterNode(0), m_spTarget(0)
{
}

// 0x140b85be0 ~CoupleEmotionAnimInfo is implicit (the exe dtor has no vftable reset); pinned at the end



// @0x140b85910
Unk_TargetPtr::Unk_TargetPtr(NiObjectNET* p)
    : m_p(p)
{
    if (m_p != 0)
        FUN_140980460(m_p);
}

// @0x140b85b20
Unk_TargetPtr::~Unk_TargetPtr()
{
    if (m_p != 0)
        FUN_1405a93d0(m_p);
}

// @0x140b85cd0
Unk_TargetPtr& Unk_TargetPtr::operator=(NiObjectNET* p)
{
    if (m_p != p)
    {
        if (m_p != 0)
            FUN_1405a93d0(m_p);
        m_p = p;
        if (m_p != 0)
            FUN_140980460(m_p);
    }
    return *this;
}

// @0x140b85fc0
bool Unk_TargetPtr::operator!=(NiObjectNET* p) const
{
    return m_p != p;
}

// ---- StateCoupleEmotion -----------------------------------------------------------------------------------------------

// @0x140b80760
StateCoupleEmotion::StateCoupleEmotion(PCBase* pOwner)
    : State(pOwner), m_spLoopEffectNode(0), m_effects(10)
{
    m_n10 = 0;
    m_n6c = 0;
}

// @0x140b80820
StateCoupleEmotion::~StateCoupleEmotion()
{
}

// Enter: creates the animation set, resolves the partner, reads the emotion row and starts the first animation (when the
// state is entered already running).
// @0x140b808a0
void StateCoupleEmotion::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0 && ((void*)(reinterpret_cast<PC*>((PCBase*)pMyPC)->FUN_14165f100())) != 0)
        reinterpret_cast<PC*>((PCBase*)pMyPC)->SendRequestCube();
    m_spAnimInfo.AssignRaw(new CoupleEmotionAnimInfo);
    m_spCoupleData.AssignRaw(dynamic_cast<StateCoupleEmotionData*>(pData));
    if (m_spCoupleData == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_posSaved = m_pOwner->vfunc_20();
    PCBase* pOwnerPC = FUN_1417b8370();
    PCBase* pPartner = GetPartner();
    if (pOwnerPC == 0 || pPartner == 0)
        return;
    StateCoupleEmotionData* pCouple = m_spCoupleData.get();
    MS2Ptr<SkillData> spRow = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(pCouple->m_nEmotion);
    if (spRow == 0)
        return;
    if (reinterpret_cast<SkillData*>(spRow.operator->())->GetMainType() != 0xf)
        return;
    m_pOwner->FUN_141670330((float)reinterpret_cast<Unk_EmoRow*>(spRow.operator->())->m_n30);
    bool bRequester = IsRequester();
    if (!m_spAnimInfo->Init(reinterpret_cast<SkillData*>(spRow.operator->())->GetParam1(), reinterpret_cast<PC*>(pOwnerPC)->FUN_141658e60(), reinterpret_cast<PC*>(pPartner)->FUN_141658e60(), bRequester))
        return;
    if (!m_spAnimInfo->Load(m_spCoupleData->m_nAni))
        return;
    m_spLoopEffectNode = NiNew NiNode(0);
    TSingleton<CEffectService>::GetInstance()->GetLeastLoadedRoot()->AttachChild((NiAVObject*)(NiNode*)m_spLoopEffectNode, false);
    if (FUN_1417b7e40() == 0x96)
        PlayFirstAni();
}

// Leave: stops every running effect, restores the saved rotation and drops the loop node.
// @0x140b80d10
void StateCoupleEmotion::vfunc_5(int n)
{
    State::vfunc_5(n);
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0xf7, "pOwnerPC" && 0);
        return;
    }
    m_n10 = 0;
    ATL::CAtlList<CStringA> listNames(10);
    for (POSITION pos = m_effects.GetHeadPosition(); pos != 0; m_effects.GetNext(pos))
    {
        const CStringA& strName = m_effects.GetKeyAt(pos);
        listNames.AddTail(strName);
    }
    for (POSITION pos = listNames.GetHeadPosition(); pos != 0;)
    {
        const CStringA& strName = listNames.GetNext(pos);
        RemoveEffect(strName);
    }
    do
    {
        if (n != 0x3a)
            break;
        pOwnerPC->SetRotationAndTargetYaw(m_posSaved);
    } while (0);
    FUN_140a0b2a0((NiAVObject*)(NiNode*)m_spLoopEffectNode);
    m_spLoopEffectNode = (NiNode*)0;
    m_pOwner->FUN_141670330(0.0f);
}

// Per tick: follows the partner (ends the state when it is gone or too far away) and keeps the two states in step.
// @0x140b80f00
void StateCoupleEmotion::vfunc_3(double fTime)
{
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0x118, "pOwnerPC" && 0);
        return;
    }
    PCBase* pPartner = GetPartner();
    if (pPartner == 0)
    {
        Stop(0);
        return;
    }
    switch (FUN_1417b7e40())
    {
    case 0x93:
        if (!FUN_140b83fa0(pOwnerPC->vfunc_18(), pPartner->vfunc_18()))
        {
            Stop(1);
            break;
        }
        break;
    case 0x96:
        if (pPartner->GetCurStateId() != 0x3a)
            Stop(0);
        else if (pPartner->FUN_14166cc80() < 0x95)
            Stop(0);
        break;
    }
    switch (FUN_1417b7e40())
    {
    case 0x95:
        if (pPartner->FUN_14166cc80() == 0x96)
            pOwnerPC->FUN_14166cc40(0x96);
        else
        {
            if (pPartner->FUN_14166cc80() != 0x95)
                break;
            pOwnerPC->FUN_14166cc40(0x96);
        }
        break;
    }
    State::vfunc_3(fTime);
}

// Follows the partner: while the state is entering (0x93) the actor must stay in range, then the animations are kept
// in step with the partner's.
// @0x140b810d0
void StateCoupleEmotion::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int nActorId = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460());
    switch (FUN_1417b7e40())
    {
    case 0x93:
    {
        int nKey = 0;
        if (m_pOwner->vfunc_65())
            nKey = 1;
        if (!m_pOwner->FUN_14166de90(nKey, nActorId))
        {
            m_pOwner->PlayAnimationById(nKey);
            m_pOwner->FUN_14166f8f0(0, 1);
        }
        break;
    }
    }
    SyncWithPartner(fTime);
}

// Drops the actor onto the ground below it, aligns it with the nif's owner node and plays the teleport effect.
// @0x140b811d0
void StateCoupleEmotion::vfunc_24()
{
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0x1ce, "pOwnerPC" && 0);
        return;
    }
    NiPoint3 kPos(static_cast<const efd::Point3&>(pOwnerPC->vfunc_18()));
    do
    {
        float fDist = 0.0f;
        if (((class CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a450(kPos, &fDist, 50.0f) != 0)
        {
            kPos.z = kPos.z - (fDist - 1.0f);
            break;
        }
        int nPartner = GetPartnerId();
        PCBase* pPeer = (PCBase*)WorldService::GetInstance()->FUN_141bd1290(nPartner);
        if (pPeer == 0)
            break;
        kPos.z = pPeer->vfunc_18().z;
    } while (0);
    pOwnerPC->vfunc_19(kPos);
    do
    {
        NiPoint3 kRot;
        if (m_spAnimInfo == 0)
            break;
        if (m_spAnimInfo->m_spOwnerNode == 0)
            break;
        NiAVObjectPtr spParent(m_spAnimInfo->m_spOwnerNode->GetParent());
        if (spParent == 0)
            break;
        NiTransform kXform = spParent->GetWorldTransform()
            * m_spAnimInfo->m_spOwnerNode->GetLocalTransform();
        FUN_140a0b1f0(reinterpret_cast<const NiMatrix3&>(kXform), reinterpret_cast<efd::Point3&>(kRot));
        kRot = m_spCoupleData->m_posEnd + kRot;
        pOwnerPC->SetRotationAndTargetYaw(kRot);
    } while (0);
    do
    {
        if (m_spAnimInfo.IsNull())
        {
            MS2_ASSERT_AT(0x1f7, "m_pAnimInfo" && 0);
            return;
        }
        if (m_spAnimInfo->m_strTeleportEffect.IsEmpty())
            break;
        NiTransform kXf;
        kXf.MakeIdentity();
        kXf.m_Translate = kPos;
        Unk_EffectTarget kTarget;
        kTarget.m_strName = m_spAnimInfo->m_strTeleportEffect;
        kTarget.m_nKind = 0;
        kTarget.m_pXform = &kXf;
        TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(kTarget);
    } while (0);
}

// @0x140b81650
void StateCoupleEmotion::vfunc_6()
{
    Stop(0);
}

// A finished animation moves on to the next one, or ends the state after the last.
// @0x140b81670
void StateCoupleEmotion::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    State::EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0x212, "pOwnerPC" && 0);
        return;
    }
    CString strCur = GetCurAniName();
    if (strCur != pOwnerPC->FUN_14166dc50())
        return;
    if (m_spAnimInfo.IsNull())
    {
        MS2_ASSERT_AT(0x218, "m_pAnimInfo" && 0);
        return;
    }
    if (!PlayNextAni())
    {
        m_posSaved = pOwnerPC->vfunc_20();
        Stop(0);
    }
}

// Follows the owner's ridden mount position; ends the state when the actor can no longer stay.
// @0x140b81830
void StateCoupleEmotion::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (FUN_1417b8560() == 0)
        return;
    Unk_CeBuffMgr* pMgr = static_cast<Unk_CeBuffMgr*>(m_pOwner->FUN_14166d240());
    m_pOwner->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Unk_PCMove*>(pMgr)->FUN_141683290())));
    if (m_pOwner->FUN_1416749c0())
    {
        Stop(0);
        m_pOwner->vfunc_59(2, 0, 0, 0);
    }
    else
    {
        FUN_1417b9460();
    }
}

// Entering the playing phase (0x96) starts the first animation.
// @0x140b81950
void StateCoupleEmotion::vfunc_2(int n)
{
    int nOld = FUN_1417b7e40();
    State::vfunc_2(n);
    if (nOld == n)
        return;
    if (m_spCoupleData == NULL)
        return;
    m_n6c = GetTickCountMs2();
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0x244, "pOwnerPC" && 0);
        return;
    }
    switch (n)
    {
    case 0x96:
        PlayFirstAni();
        break;
    }
}

// The nif's text keys "loopstart_effect_<name>" / "loopend_effect_<name>" / "loopreset_effect_<name>" start / stop /
// restart the named effect (requester only).
// @0x140b81a30
void StateCoupleEmotion::TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
    const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq, float fEventTime)
{
    if (!IsRequester())
        return;
    CString strKey((const char*)kTextKey);
    CString strStart("loopstart_effect_");
    if (strKey.Find(strStart, 0) == 0)
    {
        CString strName = strKey.Right(strKey.GetLength() - strStart.GetLength());
        AddEffect(strName);
        return;
    }
    CString strEnd("loopend_effect_");
    if (strKey.Find(strEnd, 0) == 0)
    {
        CString strName = strKey.Right(strKey.GetLength() - strEnd.GetLength());
        RemoveEffect(strName);
        return;
    }
    CString strReset("loopreset_effect_");
    if (strKey.Find(strReset, 0) == 0)
    {
        CString strName = strKey.Right(strKey.GetLength() - strReset.GetLength());
        RemoveEffect(strName);
        AddEffect(strName);
        return;
    }
}

// Is a state request for this state a repeat of what is running? 1 = no, the state should be re-entered.
// @0x140b81da0
int StateCoupleEmotion::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (!p)
    {
        MS2_ASSERT_AT(0x2c9, "pSyncObject" && 0);
        return 0;
    }
    if (m_n10 != p->m_nSub)
        return 1;
    MS2Ptr<StateSyncObjectCoupleEmotion> spSync(dynamic_cast<StateSyncObjectCoupleEmotion*>((Unk_StateArg22*)p));
    if (spSync == 0)
        return 0;
    switch (m_n10)
    {
    case 0x96:
        if ((unsigned)GetAniIndex() != spSync->m_nC0)
            return 1;
        break;
    }
    return 0;
}

// @0x140b81f70
bool StateCoupleEmotion::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    return FUN_1417b7e40() != p->m_nSub;
}

// @0x140b81fe0
int StateCoupleEmotion::GetEmotionId()
{
    if (m_spCoupleData.get() != 0)
        return m_spCoupleData->m_nEmotion;
    return 0;
}

// @0x140b82030
int StateCoupleEmotion::GetPartnerId()
{
    if (m_spCoupleData.get() != 0)
        return m_spCoupleData->m_nPartnerId;
    return 0;
}

// @0x140b82080
int StateCoupleEmotion::GetRequesterId()
{
    if (m_spCoupleData.get() != 0)
        return m_spCoupleData->m_nRequesterId;
    return 0;
}

// @0x140b820d0
void StateCoupleEmotion::SetStartPos(const efd::Point3& pos)
{
    if (m_spCoupleData == 0)
        return;
    m_spCoupleData->m_posStart = pos;
}

// @0x140b82130
void StateCoupleEmotion::SetEndPos(const efd::Point3& pos)
{
    if (m_spCoupleData == 0)
        return;
    m_spCoupleData->m_posEnd = pos;
}

// @0x140b82190
bool StateCoupleEmotion::IsRequester()
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
    {
        MS2_ASSERT_AT(0x276, "pPC" && 0);
        return false;
    }
    return reinterpret_cast<GameObject*>(pPC)->FUN_14123c580() == GetRequesterId();
}

// ---- placement / partner / animation control ---------------------------------------------------------------------------

// Finds the spot for the pair: the owner node is moved onto the peer node by rotating the placement through
// 360 one-degree steps until neither end is blocked.
// @0x140b82230
bool StateCoupleEmotion::FindPlacement(efd::Point3& posA, efd::Point3& posB, float* pfYaw)
{
    if (m_spCoupleData == 0)
        return false;
    if (m_spAnimInfo.IsNull())
    {
        MS2_ASSERT_AT(0x280, "m_pAnimInfo" && 0);
        return false;
    }
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0x283, "pOwnerPC" && 0);
        return false;
    }
    WorldService* pWorldService = WorldService::GetInstance();
    if (pWorldService == 0)
    {
        MS2_ASSERT_AT(0x286, "pWorldService" && 0);
        return false;
    }
    PCBase* pPeerPC = (PCBase*)pWorldService->FUN_141bd1290(m_spCoupleData->m_nPartnerId);
    if (pPeerPC == 0)
    {
        MS2_ASSERT_AT(0x289, "pPeerPC" && 0);
        return false;
    }
    NiNodePtr spPeerNode(m_spAnimInfo->m_spPeerNode);
    if ((NiNode*)spPeerNode == 0)
    {
        MS2_ASSERT_AT(0x28c, "spPeerNode" && 0);
        return false;
    }
    NiNodePtr spOwnerNode(m_spAnimInfo->m_spOwnerNode);
    if ((NiNode*)spOwnerNode == 0)
    {
        MS2_ASSERT_AT(0x28f, "spOwnerNode" && 0);
        return false;
    }
    NiAVObjectPtr spParentNode(spOwnerNode->GetParent());
    if (!spParentNode)
    {
        MS2_ASSERT_AT(0x292, "spParentNode" && 0);
        return false;
    }
    NiPoint3 kRot(static_cast<const efd::Point3&>(pOwnerPC->vfunc_20()));   // the owner's angles; each step turns z by one degree
    for (int nStep = 0; nStep < 360; ++nStep, kRot.z += 1.0f)
    {
        NiTransform kOwnerXf = spOwnerNode->GetWorldTransform();
        NiTransform kParentXf = spParentNode->GetWorldTransform();
        NiTransform kPeerXf = spPeerNode->GetWorldTransform();
        reinterpret_cast<Vector3*>(&kParentXf.m_Translate)->FUN_140ae9200(*reinterpret_cast<const Vector3*>(static_cast<const NiPoint3*>(&kOwnerXf.m_Translate)));
        reinterpret_cast<Vector3*>(&kPeerXf.m_Translate)->FUN_140ae9200(*reinterpret_cast<const Vector3*>(static_cast<const NiPoint3*>(&kOwnerXf.m_Translate)));
        reinterpret_cast<Vector3*>(&kOwnerXf.m_Translate)->FUN_140ae9200(*reinterpret_cast<const Vector3*>(static_cast<const NiPoint3*>(&kOwnerXf.m_Translate)));
        NiMatrix3 matRot;
        FUN_140b86230(kRot, matRot);
        kOwnerXf.m_Rotate = matRot;
        kParentXf = kOwnerXf * kParentXf;
        kPeerXf = kOwnerXf * kPeerXf;
        NiPoint3 ptPeer(m_spCoupleData->m_posStart + kPeerXf.m_Translate);
        NiPoint3 ptOwner(m_spCoupleData->m_posStart + kOwnerXf.m_Translate);
        if (!FUN_140b84dc0(ptPeer))
            continue;
        if (!FUN_140b84dc0(ptOwner))
            continue;
        efd::Point3 kHit;
        NiPoint3 kDir(ptPeer - ptOwner);
        float fLen = ((struct Vector3*)&static_cast<class NiPoint3 const&>(kDir))->FUN_140968990();
        if (((class CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a230(ptOwner, kHit, kDir, fLen, 0) != 0)
            continue;
        NiPoint3 kAngles;
        if (kParentXf.m_Rotate.ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z))
            kAngles *= -57.2957763671875f;   // 0xc2652ee0
        *pfYaw = kAngles.z;
        posA = ptPeer;
        posB = m_spCoupleData->m_posStart + kParentXf.m_Translate;
        return true;
    }
    return false;
}

// @0x140b82a00
PCBase* StateCoupleEmotion::GetPartner()
{
    if (m_spCoupleData == 0)
        return 0;
    WorldService* pWorldService = WorldService::GetInstance();
    if (pWorldService == 0)
    {
        MS2_ASSERT_AT(0x32d, "pWorldService" && 0);
        return 0;
    }
    return (PCBase*)pWorldService->FUN_141bd1290(m_spCoupleData->m_nPartnerId);
}

// Leaves the state: tells the server (packet 0xa3) and optionally shows the "partner left" notice.
// @0x140b82aa0
void StateCoupleEmotion::Stop(int bNotify)
{
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC == 0)
        return;
    pMyPC->vfunc_59(1, 0, 0, 0);
    PCBase* pPeer = GetPartner();
    if (pPeer == 0)
        return;
    COutPacket kPacket(static_cast<int>(SendOp::BuddyEmote), 0);
    kPacket.Encode1(6);
    kPacket.Encode4(m_spCoupleData.get()->m_nEmotion);
    kPacket.Encode8(pPeer->FUN_141656a80());
    FUN_140710590(kPacket);
    switch (bNotify)
    {
    case 1:
        FUN_1412751f0(FormatStringId<CStringW>(0xcee, pPeer->vfunc_77()), 1, 1);
        break;
    }
}

// Keeps this state in step with the partner's: same animation, the loop effect node follows the nif's centre node.
// MS2-FUNCTIONAL: transform arithmetic written from the call sequence.
// @0x140b82c40
void StateCoupleEmotion::SyncWithPartner(double fTime)
{
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
        return;
    PCBase* pPeer = GetPartner();
    if (pPeer == 0)
        return;
    if (pPeer->GetCurStateId() != 0x3a)
        return;
    if (pPeer->FUN_14166cc80() != FUN_1417b7e40())
        return;
    if (m_spCoupleData == 0)
        return;
    StateCoupleEmotion* pPeerState = (StateCoupleEmotion*)pPeer->FUN_14166ccb0();
    if (pPeerState == 0)
    {
        MS2_ASSERT_AT(0x180, "pPeerState" && 0);
        return;
    }
    int nAction = FUN_1417b7e40();
    if (nAction != 0x96)
        return;
    if (m_spAnimInfo.IsNull())
    {
        MS2_ASSERT_AT(0x186, "m_pAnimInfo" && 0);
        return;
    }
    if ((NiNode*)m_spAnimInfo->m_spOwnerNode == 0)
    {
        MS2_ASSERT_AT(0x187, "m_pAnimInfo->m_spOwnerNode" && 0);
        return;
    }
    NiAVObjectPtr spParentNode(m_spAnimInfo->m_spOwnerNode->GetParent());
    if (!spParentNode)
    {
        MS2_ASSERT_AT(0x18a, "spParentNode" && 0);
        return;
    }
    if ((NiNode*)m_spAnimInfo->m_spCenterNode == 0)
    {
        MS2_ASSERT_AT(0x18b, "m_pAnimInfo->m_spCenterNode" && 0);
        return;
    }
    if ((NiNode*)m_spLoopEffectNode == 0)
    {
        MS2_ASSERT_AT(0x18c, "m_loopEffectNode" && 0);
        return;
    }
    if (GetAniIndex() != pPeerState->GetAniIndex())
        return;
    m_spAnimInfo->UpdateNif();
    NiTransform kParentXf = spParentNode->GetWorldTransform();
    FUN_140b86230(m_spCoupleData->m_posEnd, kParentXf.m_Rotate);
    NiTransform kOwnerXf = kParentXf * m_spAnimInfo->m_spOwnerNode->GetLocalTransform();
    NiPoint3 kPos(m_spCoupleData->m_posStart + kOwnerXf.m_Translate);
    pOwnerPC->vfunc_19(kPos);
    NiPoint3 kAngles;
    if (kOwnerXf.m_Rotate.ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z))
    {
        kAngles *= -57.2957763671875f;   // 0xc2652ee0
        pOwnerPC->vfunc_21(kAngles);
    }
    NiTransform kCenterXf = kParentXf * m_spAnimInfo->m_spCenterNode->GetLocalTransform();
    static_cast<efd::Point3&>(kCenterXf.m_Translate) += m_spCoupleData->m_posStart;
    m_spLoopEffectNode->SetWorldTranslate(kCenterXf.m_Translate);
    m_spLoopEffectNode->SetWorldRotate(*reinterpret_cast<const NiMatrix3*>(static_cast<const NiTransform*>(&kCenterXf)));
    m_spLoopEffectNode->SetLocalFromWorldTransform(kCenterXf);
}

// @0x140b83260
CStringA StateCoupleEmotion::GetCurAniName()
{
    if (m_spAnimInfo == 0 || m_spCoupleData == 0)
        return CStringA("");
    int nAni = m_spCoupleData->m_nAni;
    if (nAni < 0 || nAni > m_spAnimInfo->GetLastAni())
    {
        Unk_ShopLog<int>(GetLogString(), 2, 99, L"StateCoupleEmotion::GetCurStateAniName Out of Range:{0}", nAni);
        return CStringA("");
    }
    return m_spAnimInfo->GetAniName(nAni);
}

// @0x140b833a0
int StateCoupleEmotion::GetAniIndex()
{
    if (m_spCoupleData == 0)
        return -1;
    return m_spCoupleData->m_nAni;
}

// Euler angles in degrees (X, Y, Z) to a rotation matrix; the engine's rotation sense is the opposite one.
// @0x140b86230
void FUN_140b86230(const efd::Point3& kEuler, NiMatrix3& kOut)
{
    NiMatrix3 matX, matY, matZ;
    matX.MakeXRotation(kEuler.x * -0.017453292f);
    matY.MakeYRotation(kEuler.y * -0.017453292f);
    matZ.MakeZRotation(kEuler.z * -0.017453292f);
    NiMatrix3 matOut = matX * matY * matZ;
    kOut = matOut;
}

// Starts the effect named strName on the loop node (once); the actor that asked owns the effect.
// MS2-FUNCTIONAL: node / transform set-up written from the call sequence.
// @0x140b833f0
bool StateCoupleEmotion::AddEffect(CStringA strName)
{
    if (m_pOwner == 0)
    {
        MS2_ASSERT_AT(0x363, "m_pPCBase" && 0);
        return false;
    }
    if (m_effects.Lookup(strName) != 0)
        return true;
    if (m_spAnimInfo.IsNull())
    {
        MS2_ASSERT_AT(0x368, "m_pAnimInfo" && 0);
        return false;
    }
    if ((NiNode*)m_spLoopEffectNode == 0)
    {
        MS2_ASSERT_AT(0x369, "m_loopEffectNode" && 0);
        return false;
    }
    if (!m_spAnimInfo->m_spNifRoot)
    {
        MS2_ASSERT_AT(0x36a, "m_pAnimInfo->m_spNifRoot" && 0);
        return false;
    }
    if ((NiNode*)m_spAnimInfo->m_spCenterNode == 0)
    {
        MS2_ASSERT_AT(0x36b, "m_pAnimInfo->m_spCenterNode" && 0);
        return false;
    }
    CStringA strNodeName((const char*)m_spAnimInfo->m_spCenterNode->GetName());
    if (strNodeName != PTR_s_Eff_center_1439f4db0)
    {
        FUN_140b850d0(((void*)GetLogString()), 2, 0x13, L"[coupleEmotion] failed to find \"{0}\" node. currentNodeName: {1}",
            &PTR_s_Eff_center_1439f4db0, strNodeName);
    }
    NiPoint3 kEuler(m_spCoupleData->m_posEnd);
    NiTransform kRootXf = m_spAnimInfo->m_spNifRoot->GetWorldTransform();
    kRootXf.m_Rotate.FromEulerAnglesXYZ((-kEuler.x * 3.1415927f) / 180.0f, (-kEuler.y * 3.1415927f) / 180.0f,
        (-kEuler.z * 3.1415927f) / 180.0f);
    NiTransform kCenterXf = kRootXf * m_spAnimInfo->m_spCenterNode->GetLocalTransform();
    static_cast<efd::Point3&>(kCenterXf.m_Translate) += m_spCoupleData->m_posStart;
    m_spLoopEffectNode->SetWorldTranslate(kCenterXf.m_Translate);
    m_spLoopEffectNode->SetWorldRotate(*reinterpret_cast<const NiMatrix3*>(static_cast<const NiTransform*>(&kCenterXf)));
    m_spLoopEffectNode->SetLocalFromWorldTransform(kCenterXf);
    MyPC* pMyPC = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMyPC == 0)
    {
        MS2_ASSERT_AT(0x37f, "pMyPC" && 0);
        return false;
    }
    bool bMine = (reinterpret_cast<GameObject*>(pMyPC)->FUN_14123c580() == reinterpret_cast<GameObject*>(m_pOwner)->FUN_14123c580() || reinterpret_cast<GameObject*>(pMyPC)->FUN_14123c580() == GetPartnerId()) ? true : false;
    Unk_EffectTarget kTarget;
    kTarget.m_strName = strName;
    kTarget.m_nKind = 0;
    kTarget.m_spObject = (NiAVObject*)(NiNode*)m_spLoopEffectNode;
    reinterpret_cast<NoticeMessage&>(kTarget).SetActor(bMine ? reinterpret_cast<GameObject*>(pMyPC)->FUN_14123c580() : reinterpret_cast<GameObject*>(m_pOwner)->FUN_14123c580());
    unsigned nHandle = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(kTarget);
    m_effects.SetAt(strName, nHandle);
    return true;
}

// @0x140b83a90
bool StateCoupleEmotion::RemoveEffect(CStringA strName)
{
    if (m_pOwner == 0)
    {
        MS2_ASSERT_AT(0x391, "m_pPCBase" && 0);
        return false;
    }
    int nHandle = 0;
    if (!m_effects.Lookup(strName, nHandle))
        return true;
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nHandle);
    m_effects.RemoveKey(strName);
    return true;
}

// @0x140b83b80
bool StateCoupleEmotion::PlayFirstAni()
{
    if (m_spCoupleData.IsNull())
    {
        MS2_ASSERT_AT(0x334, "m_stateData" && 0);
        return false;
    }
    if (!PlayAni(m_spCoupleData->m_nAni))
    {
        Stop(0);
        return false;
    }
    return true;
}

// Moves on to the next animation of the row (looping rows wrap round).
// @0x140b83c20
bool StateCoupleEmotion::PlayNextAni()
{
    int nCur = m_spCoupleData->m_nAni;
    int nLast = m_spAnimInfo->GetLastAni();
    if (!m_spAnimInfo->m_bLoop && m_spCoupleData->m_nAni >= nLast)
        return false;
    int nNext = nCur + 1;
    int nAni = (std::min)(nNext, nLast);
    if (!PlayAni(nAni))
        return false;
    return true;
}

// Plays animation nAni on the owner and restarts the nif clock.
// @0x140b83ce0
bool StateCoupleEmotion::PlayAni(int nAni)
{
    if (m_spCoupleData == 0 || m_spAnimInfo == 0)
        return false;
    PCBase* pOwnerPC = FUN_1417b8370();
    if (pOwnerPC == 0)
    {
        MS2_ASSERT_AT(0x355, "pOwnerPC" && 0);
        return false;
    }
    m_spCoupleData->m_nAni = nAni;
    CStringA strName = m_spAnimInfo->GetAniName(nAni);
    m_spAnimInfo->Load(nAni);
    m_spAnimInfo->SetStartTime((float)reinterpret_cast<CMainSystem*>(((void*)TSingleton<CMainSystem>::GetInstance()))->FUN_141473280());
    pOwnerPC->PlayAnimation((const char*)strName, 1.0f, true, false);
    return true;
}

// ---- free helpers -----------------------------------------------------------------------------------------------------

// No message box is shown, or the shown box is not the couple-emotion request.
// @0x140b83ec0
bool FUN_140b83ec0()
{
    MS2Ptr<CMsgBoxData> spBox = FUN_14151f820();
    if (spBox == NULL)
        return true;
    if (spBox->GetExtra() == s_strCoupleEmotion)
        return false;
    return true;
}

// Is the actor in a state that may start a couple emotion?
// @0x140b83f60
bool FUN_140b83f60(int nState)
{
    switch (nState)
    {
    case 1:
    case 2:
    case 4:
    case 6:
    case 7:
        return true;
    }
    return false;
}

// The two actors are within the table's maximum distance of each other.
// @0x140b83fa0
bool FUN_140b83fa0(const NiPoint3& kA, const NiPoint3& kB)
{
    float fMax = (float)*reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CeConsts*)FUN_1401d3200())->m_maxDist)->Get();
    float fLen = (kA - kB).Length();
    if (fLen > fMax)
        return false;
    return true;
}

// Shows the "couldn't start the couple emotion" notice matching the failure reason nWhy.
// @0x140b84010
void FUN_140b84010(int nWhy)
{
    CStringW strPartner(L"");
    do
    {
        MyPC* pMyPC = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pMyPC == 0)
        {
            MS2_ASSERT_AT(0x3cf, "pMyPC" && 0);
            break;
        }
        if (pMyPC->GetCurStateId() != 0x3a)
            break;
        StateCoupleEmotion* pState = (StateCoupleEmotion*)pMyPC->FUN_14166ccb0();
        if (pState == 0)
        {
            MS2_ASSERT_AT(0x3d5, "pState" && 0);
            break;
        }
        PCBase* pPeer = (PCBase*)WorldService::GetInstance()->FUN_141bd1290(pState->GetPartnerId());
        if (pPeer == 0)
            break;
        strPartner = pPeer->vfunc_77();
    } while (0);
    switch (nWhy)
    {
    case 0:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf2, strPartner), 1, 1);
        break;
    case 4:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf3, strPartner), 1, 1);
        break;
    case 1:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf4, strPartner), 1, 1);
        break;
    case 2:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf5, strPartner), 1, 1);
        break;
    case 6:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf8, strPartner), 1, 1);
        break;
    case 7:
        FUN_1412751f0(FormatStringId<CStringW>(0xcea, strPartner), 1, 1);
        break;
    case 8:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf9, strPartner), 1, 1);
        break;
    case 5:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf7, strPartner), 1, 1);
        break;
    case 3:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf6, strPartner), 1, 1);
        break;
    case 9:
        FUN_1412751f0(FormatStringId<CStringW>(0xcf0, strPartner), 1, 1);
        break;
    default:
        FUN_1412751f0(FormatStringId<CStringW>(0xce7, strPartner), 1, 1);
        break;
    }
}

// Is the point a legal spot to stand: ground below, not blocked, and no solid / forbidden object on it?
// @0x140b84dc0
bool FUN_140b84dc0(const NiPoint3& kPoint)
{
    // the exe raises the caller's point itself (both callers go on using the raised point)
    const_cast<NiPoint3&>(kPoint).z += 5.0f;
    float fDist = 0.0f;
    if (((class CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a450((const efd::Point3&)kPoint, &fDist, 10.0f) == 0)
        return false;
    if (((class CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a770((const Vector3*)&kPoint))
        return false;
    Unk_CoupleVec kDown(reinterpret_cast<const Vector3&>(efd::Point3::ZERO));
    Unk_RayCastInfo kHit;           // 0x68: FUN_14168a310 fills it up to the hit normal (+0x64)
    if (((class CPhysXHelper*)FUN_1409f7ca0())->RayCastFixedDirection((const Vector3&)kPoint, (Vector3&)kDown, &kHit, 0.0f, 0, 0) == 0)
        return false;
    if (kHit.m_hitEntity == 0)
        return false;
    efd::utf8string strTag("None");
    ((egf::Entity*)kHit.m_hitEntity)->GetPropertyValue<efd::utf8string>(0x15014205, strTag);
    int nTag = FUN_1408a01e0((const char*)((efd::utf8string*)&static_cast<class efd::utf8string const&>(strTag))->c_str());
    if (nTag == 0x40)
        return false;
    if (((egf::Entity*)kHit.m_hitEntity)->GetModel()->ContainsModel(0xd3b04f05))
        return false;
    if (((egf::Entity*)kHit.m_hitEntity)->GetModel()->ContainsModel(0x032767dd))
        return false;
    if (((egf::Entity*)kHit.m_hitEntity)->GetModel()->ContainsModel(0x72f49865))
        return false;
    if (WorldService::GetInstance()->FUN_141bcafa0((egf::Entity*)kHit.m_hitEntity))
        return false;
    return true;
}

// Logs pszFmt with the two arguments ({0}, {1}).
// @0x140b850d0
void FUN_140b850d0(void* pLogger, int nLevel, int nId, const wchar_t* pszFmt, const char* const* ppszArg0,
    const CStringA& strArg1)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue< fmt::BasicFormatter<wchar_t> >(*ppszArg0),
                                                   fmt::internal::MakeValue< fmt::BasicFormatter<wchar_t> >(strArg1)};
    reinterpret_cast<CLogString*>(pLogger)->FUN_1406530d0(nLevel, nId, pszFmt, fmt::ArgList(fmt::internal::make_type(*ppszArg0, strArg1), args));
}

// The couple-emotion request (the UI's "ask <target> to do emotion <emotionId>"). Checks the situation, then sends
// the request packet 0xa3 sub 3 with the chosen start / end positions.
// MS2-FUNCTIONAL: written from the call sequence.
// @0x140b845a0
bool RequestCoupleEmotion(__int64 nTargetId, int nEmotionId)
{
    WorldService* pWorldService = WorldService::GetInstance();
    if (pWorldService == 0)
    {
        MS2_ASSERT_AT(0x409, "pWorldService" && 0);
        return false;
    }
    MyPC* pMyPC = static_cast<MyPC*>(pWorldService->FUN_141bd0cc0());
    if (pMyPC == 0)
    {
        MS2_ASSERT_AT(0x40c, "pMyPC" && 0);
        return false;
    }
    PCBase* pTarget = (PCBase*)pWorldService->FUN_141bd1530(nTargetId);
    if (pTarget == 0)
    {
        FUN_141275260(0xcf1, 1, 1);
        return false;
    }
    if (!FUN_140b83fa0(pMyPC->vfunc_18(), pTarget->vfunc_18()))
    {
        COutPacket kPacket(static_cast<int>(SendOp::BuddyEmote), 0);
        kPacket.Encode1(2);
        kPacket.Encode8(nTargetId);
        kPacket.Encode1(8);
        FUN_140710590(kPacket);
        FUN_1412751f0(FormatStringId<CStringW>(0xcee, pTarget->vfunc_77()), 1, 1);
        return false;
    }
    if (pMyPC->FUN_141675ed0() != 0)
    {
        COutPacket kPacket(static_cast<int>(SendOp::BuddyEmote), 0);
        kPacket.Encode1(2);
        kPacket.Encode8(nTargetId);
        kPacket.Encode1(5);
        FUN_140710590(kPacket);
        FUN_141275260(0xcfa, 1, 1);
        return false;
    }
    if (!FUN_140b83f60(pMyPC->GetCurStateId()))
    {
        COutPacket kPacket(static_cast<int>(SendOp::BuddyEmote), 0);
        kPacket.Encode1(2);
        kPacket.Encode8(nTargetId);
        kPacket.Encode1(5);
        FUN_140710590(kPacket);
        FUN_141275260(0xcfa, 1, 1);
        return false;
    }
    MS2Ptr<StateCoupleEmotionData> spData(new StateCoupleEmotionData);
    spData->m_nEmotion = nEmotionId;
    spData->m_nPartnerId = reinterpret_cast<GameObject*>(pTarget)->FUN_14123c580();
    spData->m_nRequesterId = reinterpret_cast<GameObject*>(pTarget)->FUN_14123c580();
    spData->m_posStart = pMyPC->vfunc_18();
    spData->m_posEnd = pMyPC->vfunc_20();
    pMyPC->vfunc_59(0x3a, spData.get(), 0x94, 1);
    if (pMyPC->GetCurStateId() != 0x3a)
    {
        MS2_ASSERT_AT(0x443, "pMyPC->GetState() == gosCoupleEmotion" && 0);
        return false;
    }
    StateCoupleEmotion* pState = (StateCoupleEmotion*)pMyPC->FUN_14166ccb0();
    if (pState == 0)
    {
        MS2_ASSERT_AT(0x445, "pState" && 0);
        return false;
    }
    efd::Point3 posA, posB;
    float fYaw;
    if (!pState->FindPlacement(posA, posB, &fYaw))
    {
        COutPacket kPacket(static_cast<int>(SendOp::BuddyEmote), 0);
        kPacket.Encode1(2);
        kPacket.Encode8(nTargetId);
        kPacket.Encode1(7);
        FUN_140710590(kPacket);
        FUN_1412751f0(FormatStringId<CStringW>(0xcea, pMyPC->vfunc_77()), 1, 1);
        pMyPC->vfunc_59(1, 0, 0, 0);
        return false;
    }
    COutPacket kPacket(static_cast<int>(SendOp::BuddyEmote), 0);
    kPacket.Encode1(3);
    kPacket.Encode4(nEmotionId);
    kPacket.Encode8(nTargetId);
    kPacket.WriteVector3(reinterpret_cast<const Vector3&>(posA));
    kPacket.WriteVector3(reinterpret_cast<const Vector3&>(posB));
    kPacket.WriteFloat(fYaw);
    FUN_140710590(kPacket);
    return true;
}

// ---- remaining overrides ----------------------------------------------------------------------------------------------

// @0x140b86100
MS2Ptr<StateData> StateCoupleEmotion::vfunc_27()
{
    return MS2Ptr<StateData>(new StateCoupleEmotionData);
}

// @0x140b86220
int StateCoupleEmotion::vfunc_1()
{
    return 0x3a;
}

// The null comparisons of the three smart pointers this unit owns.
template bool MS2Ptr<CoupleEmotionAnimInfo>::operator==(CoupleEmotionAnimInfo*) const;               // @0x140b85f00
template bool MS2Ptr<StateCoupleEmotionData>::operator==(StateCoupleEmotionData*) const;             // @0x140b85f40
template bool MS2Ptr<StateSyncObjectCoupleEmotion>::operator==(StateSyncObjectCoupleEmotion*) const; // @0x140b85f80
// MS2-PIN: ??1CoupleEmotionAnimInfo@@UEAA@XZ 0x140b85be0 ; implicit virtual dtor (no vftable reset, like the exe)
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1160-0x142ca1210 .text$yd
// Full-executable aliases for existing couple-emotion helpers.
// MS2-PIN: ?RequestCoupleEmotion@@YA_N_JH@Z 0x140b845a0
// MS2-PIN: ?FUN_140b845a0@@YAX_JI@Z 0x140b845a0
// MS2-PIN: ?FUN_140b84dc0@@YA_NAEBVNiPoint3@@Z 0x140b84dc0
// MS2-PIN: ?FUN_140b86230@@YAXAEBVPoint3@efd@@AEAVNiMatrix3@@Z 0x140b86230
// MS2-PIN: ?FUN_140b86230@@YAXAEBUVector3@@AEAUUnk_NiMatrix3@@@Z 0x140b86230
// MS2-PIN: ?FUN_140b86230@@YAXAEBVNiPoint3@@AEAVNiMatrix3@@Z 0x140b86230
// MS2-PIN: ?FUN_140b86230@@YAXPEBUVector3@@PEAVNiTransform@@@Z 0x140b86230
