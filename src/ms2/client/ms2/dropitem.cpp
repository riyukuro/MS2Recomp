// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See dropitem.h.
// MS2-UNIT: client\ms2\dropitem.cpp
// MS2-RANGE: 0x14118c730-0x141192960 .text$mn
// MS2-RANGE: 0x1400e7300-0x1400e74f0 .text$di
// MS2-PIN: ?GetClassDesc@CDropItem@@UEBAPEBVClassInfo@efd@@XZ 0x141192770
// MS2-PIN: ?TypeCast@CDropItem@@UEBA_NIPEAPEAX@Z 0x1411928c0
// MS2-PIN: ?TypeCast@CDropItem@@UEBA_NIPEAPEBX@Z 0x141192910
// MS2-PIN: ??_7CDropItem@@6BIBase@efd@@@ 0x142eb89c8
// MS2-PIN: ??0CDropItem@@QEAA@HH@Z 0x14118c730
// MS2-PIN: ??_7CDropItem@@6BCallbackObject@NiActorManager@@@ 0x142eb8b98
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dropitem.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dropitem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <io.h>
#include <math.h>
#include <NxPhysics.h>
#include <NiTransform.h>
#include <NiTexturingProperty.h>
#include <NiMesh.h>                         // C3: NiMesh::ms_RTTI
#include <egmAnimation/AnimationService.h>  // C3: AnimationService::GetActorManager
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/commonfiles/blockchecker.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/client/ms2/arccontroller.h"
#include "ms2/client/ms2/uidamagetext.h"
#include "ms2/placeholder/cgraphicoptiontable.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/placeholder/cguidemanager.h"

// ---- unit-local views of exe objects and unrecovered callees ----

extern "C" float (__cdecl* __imp_sinf)(float);                      // the exe calls the CRT import

class Unk_WsC_GameObj : public GameObject
{
public:
    virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61();
    virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66();
    virtual void vfunc_67(Vector3* pForward, Vector3* pSide);   // 0x218
};

// The actor's ground shadow (unit_14160fb10 holds its methods; only the members this unit reads are named).
class CObjectShadow : public NiRefObject
{
public:
    CObjectShadow(void* pOwner, int nLodHi, int nLodLo, float fSize, float fAlpha);   // 0x14160fc90 (the owner GameObject)
    bool FUN_14109a720();                                           // 0x14109a720
    bool FUN_141192820();                                           // 0x141192820 the dirty flag
    bool FUN_141192830();                                           // 0x141192830 the enabled flag
private:
    char m_pad_10[0x30 - sizeof(NiRefObject)];
public:
    bool m_bEnabled;                                                // +0x30
    bool m_bFlag31;                                                 // +0x31
    bool m_bFlag32;                                                 // +0x32
    bool m_bDirty;                                                  // +0x33
private:
    char m_pad_34[0x58 - 0x34];
};
MS2_CHECK_SIZE(CObjectShadow, 0x58);
void FUN_14160fe10(CObjectShadow* self, bool v);   // unit_14160fb10
void FUN_14160fe50(CObjectShadow* self, bool v);
void FUN_1416105c0(CObjectShadow* self);

// The shadow quality settings (?\gameoption.cpp keeps the full view).

// The sound / effect service (TSingleton<CEffectService>::GetInstance), see effectservice.h.

// The notice and guide managers.
class Unk_DropGuideMgr : public CGuideManager
{
};
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
void FUN_141275260(int nSound, int a, int b);
int FUN_141276180(const CString& strKey, const CString& strArg);   // system notice
void FUN_1412751b0(const CStringW& strText, int nSeconds);          // center notice

// The ui dialogs a pickup notifies.
template <class T> T* Unk_DmgFindUI(int nId);
#include "ms2/client/ms2/uirewardnotify.h"
class UIRewardNotify* FUN_140938cd0(int);   // C3: was FUN_140938cd0
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                           // the scene root of an entity
void FUN_141851f90(void* pRoot, float fWeight);
void FUN_141852050(void* pRoot, unsigned int uValue);
class CMainSystem   // C3: member view for the former free stand-ins
{
public:
    double FUN_141473280();
};
void FUN_141545250(egf::EntityID kId, int b);
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
bool FUN_14053f8c0(unsigned nItemId);                               // the item id is meso
bool FUN_14053f900(unsigned nItemId);                               // the item id is a special item
void FUN_1401d3700(CString& str);
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0

// More unit-local views of exe objects (the drop source, the model attachment, the item data, the prop of a tree).
// (the prop of a tree is WorldService's CInteractObject, interactobject.h)
class Unk_GoAttachment { public: char m_pad[0xb4]; NxBox m_box; };     // +0xb4 the placement box
                      // the item kind
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();
class Unk_AvSeqCtl   // C3: member view for the former free stand-ins
{
public:
    void FUN_1409fae00(bool);
};
class MyPC; class PCBase;
template <> MyPC* efd::DynamicCast<MyPC, PCBase>(PCBase* Source);
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
// C3: the string getter 0x140298f80 is Common::Constants::Value<CString>::Get() (clientconstants.h)
class Unk_InventoryStateManager* FUN_140a6a830();   // C3: was FUN_140a6a830
extern Unk_Inventory g_143ab2a90;
int FUN_140768010(int, int);   // C3: was FUN_140768010
float FUN_140966f00(Vector3 kA, Vector3 kB);        // the horizontal distance
void FUN_14160feb0(CObjectShadow* pShadow, int nActive, const void* pPos, const void* pDir, float fTime, bool bForce);   // C3: the real free signature (unit_14160fb10)
float FUN_140966f00(Vector3 kA, efd::Point3 kB);    // the same, the second point sliced from an NiPoint3
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0
bool FUN_14147a500(Vector3* pOut, Vector3 kStart, Vector3 kEnd, bool bProbe, float fProbeLen, const NxGroupsMask* pMask);
#define DAT_143a08ce8 (*(Vector3*)&efd::Point3::UNIT_Y) // C3: was extern Vector3 DAT_143a08ce8; NiPoint3::UNIT_Y
#define DAT_143a08cf8 (*(Vector3*)&efd::Point3::UNIT_Z) // C3: was extern Vector3 DAT_143a08cf8; NiPoint3::UNIT_Z
extern Vector3 DAT_143a08d08;                               // NiPoint3::ALL_ONES

extern const efd::Matrix3 DAT_143a09600;                // efd::Matrix3::IDENTITY

// ---- the unit's timer, class info and header statics (the .text$di order) ----
static Timer s_kPickTimer;                                          // @0x1400e7300
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CDropItem);                        // @0x1400e7330
#include "ms2/placeholder/header_statics_a.h"                       // @0x1400e7350..0x1400e7470
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int nActor);                                      // 0x140a53190
    void* m_storage[14];
};
static CString s_strWarningBag("system_notice_error_warningBag");   // @0x1400e74c0

// ---- helpers ----


// The horizontal direction kTo - kFrom (z cleared on the copies), unit length when bUnitize.
// @0x141192780
Vector3 FUN_141192780(Vector3 kFrom, Vector3 kTo, bool bUnitize)
{
    kFrom.z = 0.0f;
    kTo.z = 0.0f;
    if (bUnitize)
    {
        Vector3 kDir = kTo.FUN_140965c40(kFrom);
        kDir.FUN_140968990();
        return kDir;
    }
    else
        return kTo.FUN_140965c40(kFrom);
}

// @0x141192820
bool CObjectShadow::FUN_141192820() { return m_bDirty; }

// @0x141192830
bool CObjectShadow::FUN_141192830() { return m_bEnabled; }

// ---- CDropItem ----

// @0x14118c730
CDropItem::CDropItem(int nType, int nRarity)
    : GameObject()
    , m_nAmount(0)
    , m_fElapsed(0.0f)
    , m_n64Meso(0)
    , m_owners(10)
    , m_n188(0)
    , m_nOwnerObjId(0)
    , m_nNpcType(0)
    , m_nEffectIdA(0)
    , m_nEffectIdB(0)
    , m_nState(6)
    , m_nOwnerType(nType)
    , m_nDropKind(nRarity)
    , m_nTick(0)
    , m_pfnState(0)
    , m_n278(0)
    , m_n28c(0)
    , m_nFadeTime(0)
    , m_n298(0)
{
    m_unk_b0 = 1;
    m_str88 = "";
    s_kPickTimer.FUN_140868750(10);
    m_f218 = Client::Constants::GetInstance()->DropItemTargetZPos.Read();
    m_f21c = Client::Constants::GetInstance()->DropItemMaxLength.Read();
    m_f220 = Client::Constants::GetInstance()->DropMoneyMaxLength.Read();
    m_f224 = Client::Constants::GetInstance()->DropItemPickUpVel.Read();
    m_f228 = Client::Constants::GetInstance()->DropItemPickUpGravity.Read();
    m_f22c = Client::Constants::GetInstance()->DropItemPickUpCompleteRotateTime.Read();
    m_f230 = Client::Constants::GetInstance()->DropItemPickUpCompleteRotateVel.Read();
    m_f27c = m_f21c;
    reinterpret_cast<NiPoint3&>(m_posOrigin) = vfunc_18();    // NiPoint3 move-assign (0x140194470) of the returned temp
    m_n294 = 0;
}

// @0x14118cac0
CDropItem::~CDropItem()
{
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffectIdA);
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffectIdB);
}

// Builds the item and the model of the drop; false when the item or its effect row does not exist.
// @0x14118cb90
int CDropItem::FUN_14118cb90(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId)
{
    m_nOwnerObjId = nOwnerObjId;
    m_nAmount = nAmount;
    if (!IsPickupAllowedForLocalPlayer())
        return 0;
    m_spItem.AssignRaw(new CItem());
    if (!m_spItem->FUN_140523c40(nItemId, nRarity, 0))
        return 0;
    Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FUN_141bd1320(m_nOwnerObjId);
    if (pOwner)
        m_nNpcType = static_cast<CNpc*>(static_cast<GameObject*>(pOwner))->GetNpcData()->GetId();
    m_str88 = "DropItemNIF";
    FUN_14123c5a0(nObjectId);
    if (FUN_14053f8c0(nItemId))
    {
        m_n64Meso = nAmount;
        m_spEffect = CItemDataTable::GetInstance()->GetItemDropEffect(0x55d4a81, nAmount);
        if (m_spEffect == 0)
            return 0;
        FUN_14123bb80(StringFormat<CString>("urn:gamebryo-scenegraph:{0}", m_spEffect->assetName));
    }
    else if (FUN_14053f900(nItemId))
    {
        int nEffectId = nItemId;     // computed but never used by the exe
        if (nItemId == 0x55d4a93)
            nEffectId = 0x55d4a89;
        m_spEffect = CItemDataTable::GetInstance()->GetItemDropEffect(nItemId, nAmount);
        if (m_spEffect == 0)
        {
            MS2_ASSERT_AT(0xb1, 0);
            return 0;
        }
        FUN_14123bb80(StringFormat<CString>("urn:gamebryo-scenegraph:{0}", m_spEffect->assetName));
        if (nItemId == 0x55d4a89 || nItemId == 0x55d4a8a)
            LoadSpepBallConstants();
    }
    else if (FUN_14118ffb0())
    {
        m_spEffect = CItemDataTable::GetInstance()->GetDropEffect(2);
        if (m_spEffect == 0)
            return 0;
        CString strNif = CItemDataTable::GetInstance()->GetGradePetNif((ItemGradeKey)nRarity);
        FUN_14123bb80(StringFormat<CString>("urn:gamebryo-scenegraph:{0}", strNif));
    }
    else
    {
        m_spEffect = CItemDataTable::GetInstance()->GetDropEffect(1);
        if (m_spEffect == 0)
            return 0;
        CString strNif = CItemDataTable::GetInstance()->GetGradeNif((ItemGradeKey)nRarity);
        FUN_14123bb80(StringFormat<CString>("urn:gamebryo-scenegraph:{0}", strNif));
    }
    return 1;
}

// @0x14118d1c0
int CDropItem::FUN_14118d1c0(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId, const ATL::CAtlList<__int64>& kOwners)
{
    m_owners.AddTailList(&kOwners);
    return FUN_14118cb90(nObjectId, nItemId, nAmount, nRarity, nOwnerObjId);
}

// @0x14118d230
int CDropItem::InitWithOwners(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId, __int64 nOwner)
{
    if (nOwner)
        m_owners.AddTail(nOwner);
    return FUN_14118cb90(nObjectId, nItemId, nAmount, nRarity, nOwnerObjId);
}

// @0x14118d2a0
int CDropItem::vfunc_10()
{
    if (!GameObject::vfunc_10())
        return 0;
    if (!IsMeso())
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
        if (pRoot)
            FUN_14118d720(pRoot);
    }
    if (FUN_14118ffb0())
    {
        bool bValue = false;
        FUN_14098c6e0((class Unk_CachedEntity*)(FUN_14123c410()), 0x2a7fd9f4, bValue);
        FUN_141851f90(FUN_141b6efc0(FUN_14123c410()), 0.0f);
        FUN_141b6efc0(FUN_14123c410())->Update((float)((class CMainSystem*)(void*)(((void*)TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
        FUN_141852050(FUN_141b6efc0(FUN_14123c410()), 0);
        FUN_141545250(FUN_14123c460(), 1);
    }
    return 1;
}

// @0x14118d3e0
int CDropItem::vfunc_11()
{
    GameObject::vfunc_11();
    return 1;
}

// @0x14118d410
void CDropItem::vfunc_12()
{
    GameObject::vfunc_12();
}

// @0x14118d430
void CDropItem::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    vfunc_21(efd::Point3(0.0f, 0.0f, 0.0f));
    if (m_spEffect.get())
        SetScaleAC(m_spEffect->scale);
}

// @0x14118d4e0
void CDropItem::vfunc_32(bool bForce)
{
    if (m_spShadow)
    {
        FUN_14160fe50(m_spShadow.operator->(), FUN_140f4a450() < 200000.0f);
        FUN_1416105c0(m_spShadow.operator->());
        bool bMoved = m_spShadow->FUN_14109a720();
        bool bDirty = m_spShadow->FUN_141192820();
        if (bMoved || bForce || bDirty)
        {
            Unk_RayCastInfo kInfo;
            Vector3 kNormal(0.0f, 0.0f, 1.0f);
            Vector3 kHit(0.0f, 0.0f, 0.0f);
            int nHit = 0;
            if (bMoved)
            {
                if (m_spShadow->FUN_141192830())
                {
                    nHit = ((class CPhysXHelper*)FUN_1409f7ca0())->RayCastFixedDirection(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18())), kHit, &kInfo, 0.0f, &kNormal, 0);
                }
            }
            FUN_14160feb0(m_spShadow.operator->(), nHit, &kHit, &kNormal, kInfo.m_hitDist, bForce);
        }
    }
}

// @0x14118d700
void CDropItem::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
}

// Puts the icon of the dropped item on the "Item_Icon:0" mesh of the model.
// @0x14118d720
void CDropItem::FUN_14118d720(NiAVObject* pRoot)
{
    if (NiAVObject* pIcon = pRoot->GetObjectByName("Item_Icon:0"))
    {
        if (NiObject::IsExactKindOf(&NiMesh::ms_RTTI, (class NiObject const*)(pIcon)))
        {
            NiTexturingProperty* pTexturing = static_cast<NiTexturingProperty*>(NiObject::DynamicCast(&NiTexturingProperty::ms_RTTI, (class NiObject const*)(pIcon->GetProperty(8))));
            if (pTexturing)
            {
                NiTexturingProperty::Map* pMap = ((class NiTexturingProperty*)(pTexturing))->GetBaseMap();
                if (pMap)
                {
                    CString strPath = m_spItem->FUN_140528590();
                    if (m_spItem->HasCubeTextureMesh())
                    {
                        if (m_spItem->FUN_140525f60())
                        {
                            if (_access(strPath, 0) != 0)
                                strPath = reinterpret_cast<CItemData*>(m_spItem->FUN_140527840())->GetIconPath();
                        }
                    }
                    FUN_1401d3700(strPath);
                    if (!strPath.IsEmpty())
                    {
                        ((NiTexturingProperty::Map*)(void*)(pMap))->SetTexture(((class CNifLoadingService*)FUN_140a0afd0())->GetTexture(CString(strPath), 5));
                    }
                }
            }
        }
    }
}

// Enters a state of the drop: 1 flies out of the source, 0 waits, 2 / 3 / 4 fly to the owner and vanish, 5 grows back.
// @0x14118d9a0
void CDropItem::FUN_14118d9a0(int nState)
{
    if (m_nState == nState)
        return;
    if (m_spEffect == 0)
        return;
    m_fElapsed = 0.0f;
    m_fSpawnTime = 0.0f;
    m_nState = nState;
    if (nState == 1)
    {
        float fDropHeight = 0.0f;
        float fDropSpeed = 100.0f;
        float fDropBase = 50.0f;
        unsigned nDropRange = 100;
        if (WorldService::GetInstance()->FUN_141bd3060() == 0x4c4b404 || WorldService::GetInstance()->FUN_141bd3060() == 0x4c4b407)
        {
            fDropHeight = Client::Constants::GetInstance()->moneyTreeDropHeight.Read();
            fDropBase = Client::Constants::GetInstance()->moneyTreeDropBase.Read();
            nDropRange = Client::Constants::GetInstance()->moneyTreeDropRandom.Read();
        }
        if (m_nNpcType != 0)
        {
            MS2Ptr<CNpcData> spNpc = FUN_1406cd330(m_nNpcType);
            fDropHeight = spNpc->m_drop.m_fDropHeight;
            if (spNpc->m_drop.m_fDropDistanceBase != 0.0f)
                fDropBase = spNpc->m_drop.m_fDropDistanceBase;
            if (spNpc->m_drop.m_nDropDistanceRandom != 0)
                nDropRange = spNpc->m_drop.m_nDropDistanceRandom;
            fDropSpeed = spNpc->m_drop.m_fFireVelocity;
        }
        else if (m_nDropKind == 0x21)
        {
            // (the point is vfunc_18's result, copied once into the by-value argument)
            CInteractObject* pProp = WorldService::GetInstance()->FUN_141bc6090(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(vfunc_18())), 0);
            bool bProp = pProp && (pProp->GetRow().get() ? true : false);
            if (bProp)
            {
                if (pProp->GetRow()->m_drop.m_nDropHeight != 0)
                    fDropHeight = (float)pProp->GetRow()->m_drop.m_nDropHeight;
                if (pProp->GetRow()->m_drop.m_nDropDistance != 0)
                    fDropBase = (float)pProp->GetRow()->m_drop.m_nDropDistance;
            }
        }
        NiPoint3 kSelf = vfunc_18();
        m_posOrigin = reinterpret_cast<Vector3&>(kSelf).FUN_140965c40(Vector3(0.0f, 0.0f, 70.0f));
        kSelf.z += fDropHeight;
        if (FUN_14118ffb0())
        {
            reinterpret_cast<Vector3&>(kSelf) = m_posOrigin;
            if (m_n298 != 0)
            {
                NoticeMessage kTarget;   // C3: was Unk_EffectTarget
                ((Unk_EffectTarget&)(kTarget)).m_strName = *Client::Constants::GetInstance()->PetTrapDropItemEffect.Get();
                ((Unk_EffectTarget&)(kTarget)).m_nKind = 0;
                kTarget.SetActor(FUN_14123c580());
                TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(((Unk_EffectTarget&)(kTarget)));
                m_nFadeTime = GetTickCountMs2() + *Client::Constants::GetInstance()->PetTrapDropVisibleDelay.Get();
                vfunc_23(1);
            }
        }
        if (m_nFadeTime == 0 && (CObjectShadow*)m_spShadow != 0)
        {
            FUN_14160fe10(m_spShadow.operator->(), true);
            vfunc_32(true);
        }
        vfunc_19(reinterpret_cast<efd::Point3&>(kSelf));
        NiPoint3 kBase = static_cast<const efd::Point3&>(vfunc_18());
        kBase.z += 85.0f;
        Unk_Random kRand(FUN_14123c580(), FUN_14123c580() + 0x7fff, FUN_14123c580() * 0x7fff);
        NiPoint3 kTargetPos;
        Unk_WsC_GameObj* pSource = WorldService::GetInstance()->FUN_141bd1290(m_nOwnerObjId);
        Unk_WsC_GameObj* pNpcObj = WorldService::GetInstance()->FUN_141bd1320(m_nOwnerObjId);
        if (m_n28c != 0)
        {
            kTargetPos = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18())))) + reinterpret_cast<const efd::Point3&>(DAT_143a08d08)))));
        }
        else if (pSource && IsMeso())
        {
            Vector3 kForward, kSide;
            pSource->vfunc_67(&kForward, &kSide);
            kForward.z = 0.0f;
            kTargetPos = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kBase).FUN_140965c40(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(kForward) * 50.0f)))));
        }
        else if (pNpcObj && FUN_14118ff60())
        {
            Unk_WsC_GameObj* pOwnerPc = WorldService::GetInstance()->FUN_141bd1530(GetFirstOwner());
            Unk_GoAttachment* pAttach = pNpcObj->vfunc_26();
            if (pAttach && (static_cast<CNpc*>(static_cast<GameObject*>(pNpcObj))->GetNpcData()->m_collision.m_strShape == "box") && pOwnerPc)
            {
                Unk_GoAttachment* pBoxOwner = pAttach;
                NxVec3 kCenter = pBoxOwner->m_box.GetCenter();
                kBase = NiPoint3(kCenter.x, kCenter.y, kCenter.z);
                vfunc_19(kBase);
                float fDistance = fDropBase + (float)(kRand.FUN_1407684c0() % nDropRange);
                m_f27c = FUN_140966f00(m_posOrigin, reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(NiPoint3(kTargetPos))));
#ifdef __clang__
                NiPoint3 kOwnerPos = pOwnerPc->vfunc_18();
                const Vector3& kDirRaw = FUN_141192780(reinterpret_cast<Vector3&>(kBase), reinterpret_cast<Vector3&>(kOwnerPos), true);
                NiPoint3 kDir = reinterpret_cast<const efd::Point3&>(kDirRaw);
#else
                NiPoint3 kDir = reinterpret_cast<const efd::Point3&>(FUN_141192780(Vector3(reinterpret_cast<Vector3&>(kBase)), reinterpret_cast<Vector3&>(pOwnerPc->vfunc_18()), true));
#endif
                if (reinterpret_cast<const efd::Point3&>(kDir) == reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
                {
                    kDir.y = ((float)(kRand.FUN_1407684c0() % 0x168) * 3.1415927f) / 180.0f + 1.0f;
                    reinterpret_cast<Vector3&>(kDir).FUN_140968990();
                }
                kTargetPos = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kBase))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kDir))) * fDistance))));
            }
        }
        else
        {
            NiMatrix3 kRot;
            kRot.MakeZRotation(((float)(kRand.FUN_1407684c0() % 0x168) * 3.1415927f) / 180.0f);
            NiPoint3 kDir = efd::Point3::UNIT_Y * kRot;
            float fDistance = fDropBase + (float)(kRand.FUN_1407684c0() % nDropRange);
            kTargetPos = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kBase))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kDir))) * fDistance))));
            m_f27c = FUN_140966f00(m_posOrigin, reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(NiPoint3(kTargetPos))));
        }
        NxGroupsMask kMask;
        kMask.bits0 = 0xffffffff;
        kMask.bits1 = kMask.bits2 = kMask.bits3 = 0;
        NiPoint3 kHit;
        int nGravityJitter = kRand.FUN_1407684c0() % 0x19;
        float fGravity = -15.0f - (float)nGravityJitter;
        float fProbe = fDropHeight + 85.0f + 100.0f;
        if (FUN_14147a500(&reinterpret_cast<Vector3&>(kHit), reinterpret_cast<Vector3&>(kBase), reinterpret_cast<Vector3&>(kTargetPos), true, fProbe, &kMask))
        {
            kHit.z += m_spEffect->unknown1c;
#ifdef __clang__
            NiPoint3 kStartPos = vfunc_18();
            m_arc.FUN_141479ed0(reinterpret_cast<Vector3&>(kStartPos), reinterpret_cast<Vector3&>(kHit), fDropSpeed, fGravity);
#else
            m_arc.FUN_141479ed0(reinterpret_cast<Vector3&>(vfunc_18()), Vector3(reinterpret_cast<Vector3&>(kHit)), fDropSpeed, fGravity);
#endif
        }
        else
        {
            Unk_RayCastInfo kInfo;
            kInfo.m_origin = reinterpret_cast<Vector3&>(kBase);
            reinterpret_cast<efd::Point3&>(kInfo.m_dir) = -reinterpret_cast<const efd::Point3&>(DAT_143a08cf8);
            kInfo.m_maxDist = 0.0f;
            kInfo.m_groups = 0x389;
            if (((class CPhysXHelper*)FUN_1409f7ca0())->CastRay(&kInfo, &kMask))
            {
                kHit = reinterpret_cast<const efd::Point3&>(kInfo.m_hitPoint);
                kHit.z += m_spEffect->unknown1c;
                m_arc.m_origin = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18()));
                m_arc.m_direction = DAT_143b01a60;
                m_arc.m_target = reinterpret_cast<Vector3&>(kHit);
                m_arc.m_gravity = -9.8f;
                m_arc.m_flightScale = 5.0f;
                m_arc.m_angle.x = 0.0f;
                m_arc.m_angle.y = 0.0f;
                m_arc.m_speed = fDropSpeed;
            }
            else
            {
                int nFound = 0;
                float aSideX[4] = { 1.0f, -1.0f, -1.0f, 1.0f };
                float aSideY[4] = { 1.0f, 1.0f, -1.0f, -1.0f };
                for (size_t i = 0; i < 4; ++i)
                {
                    Vector3 kSide;
                    kSide.x = aSideX[i];
                    kSide.y = aSideY[i];
                    kSide.FUN_140968990();
                    NxGroupsMask kMaskSide;
                    kMaskSide.bits0 = 0xffffffff;
                    kMaskSide.bits1 = kMaskSide.bits2 = kMaskSide.bits3 = 0;
                    Unk_RayCastInfo kInfoSide;
                    kInfoSide.m_origin = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18())))) + reinterpret_cast<const efd::Point3&>(kSide) * 150.0f * 0.5f));
                    reinterpret_cast<efd::Point3&>(kInfoSide.m_dir) = -reinterpret_cast<const efd::Point3&>(DAT_143a08cf8);
                    kInfoSide.m_maxDist = 0.0f;
                    kInfoSide.m_groups = 0x389;
                    if (((class CPhysXHelper*)FUN_1409f7ca0())->CastRay(&kInfoSide, &kMaskSide))
                    {
                        kHit = reinterpret_cast<const efd::Point3&>(kInfoSide.m_hitPoint);
                        kHit.z += m_spEffect->unknown1c;
#ifdef __clang__
                        NiPoint3 kStartPos = vfunc_18();
                        m_arc.FUN_141479ed0(reinterpret_cast<Vector3&>(kStartPos), reinterpret_cast<Vector3&>(kHit), fDropSpeed, fGravity);
#else
                        m_arc.FUN_141479ed0(reinterpret_cast<Vector3&>(vfunc_18()), Vector3(reinterpret_cast<Vector3&>(kHit)), fDropSpeed, fGravity);
#endif
                        nFound = 1;
                        break;
                    }
                }
                if (nFound == 0)
                {
                    m_arc.m_origin = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18()));
                    m_arc.m_direction = DAT_143b01a60;
                    m_arc.m_target = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18()));
                    m_arc.m_gravity = -9.8f;
                    m_arc.m_flightScale = 0.0f;
                    m_arc.m_angle.x = 0.0f;
                    m_arc.m_angle.y = 0.0f;
                    m_arc.m_speed = fDropSpeed;
                    m_pfnState = &CDropItem::FUN_141191a10;
                    m_nState = 0;
                    return;
                }
            }
        }
        if (250.0f < m_arc.m_target.z - m_posOrigin.z)
        {
            m_arc.m_target = m_posOrigin;
            m_arc.m_target.z += 85.0f;
        }
        if (m_spItem.get())
        {
            NiTransform kXform;
            kXform.m_fScale = 1.0f;
            kXform.m_Translate = static_cast<const efd::Point3&>(vfunc_18());
            kXform.m_Rotate = DAT_143a09600;
            int nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nOwnerObjId);
            CString strSound = m_spEffect->dropSoundID;
            if (!strSound.IsEmpty())
                TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), nKind, &kXform, 1.0f, 0);
        }
        m_pfnState = &CDropItem::FUN_141191780;
    }
    else if (nState == 2)
    {
        if (m_nEffectIdA != 0)
            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffectIdA);
        if (m_nEffectIdB != 0)
            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffectIdB);
        Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FindObjectById(m_n278);
        if (!pOwner)
            pOwner = WorldService::GetInstance()->FindObjectById(m_n188);
        if (pOwner)
        {
            m_posGround = static_cast<const efd::Point3&>(pOwner->vfunc_18());
            NiPoint3 kGoal = static_cast<const efd::Point3&>(pOwner->vfunc_18());
            kGoal.z += m_f218;
            unsigned nHalf = (unsigned)(__int64)m_f224;
            nHalf >>= 1;
            m_f224 = (float)(FUN_140768010(nHalf, 0) + nHalf);
            Vector3 kGoalCopy(reinterpret_cast<Vector3&>(kGoal));
#ifdef __clang__
            NiPoint3 kStart = vfunc_18();
            m_arc.FUN_141479ed0(reinterpret_cast<Vector3&>(kStart), kGoalCopy, m_f224, m_f228);
#else
            m_arc.FUN_141479ed0(reinterpret_cast<Vector3&>(vfunc_18()), kGoalCopy, m_f224, m_f228);
#endif
        }
        m_pfnState = &CDropItem::FUN_141191d10;
    }
    else if (nState == 3)
    {
        m_arc.m_origin = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18()));
        if (FUN_141b6f910()->GetActorManager(FUN_14123c460()))
            ((class NiActorManager*)(FUN_141b6f910()->GetActorManager(FUN_14123c460())))->SetPaused(true);
        if (IsMeso())
        {
            Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FindObjectById(m_n188);
            if (efd::ClassInfo::IsKindOf(pOwner ? pOwner->GetClassDesc() : 0, 0x6200004))
            {
                UIDamageText* pDlg = Unk_DmgFindUI<UIDamageText>(0x4e32);
                if (pDlg)
                    pDlg->FUN_141912a80(pOwner, (int)m_n64Meso, 1);
            }
        }
        else if (reinterpret_cast<CItemData*>(m_spItem->FUN_140527840())->GetType() == 3)
        {
            Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FindObjectById(m_n188);
            if (efd::ClassInfo::IsKindOf(pOwner ? pOwner->GetClassDesc() : 0, 0x6200004))
            {
                UIDamageText* pDlg = Unk_DmgFindUI<UIDamageText>(0x4e32);
                if (pDlg)
                    pDlg->FUN_141913060(pOwner, m_spItem->GetCount(), m_spItem->FUN_140528590());
            }
        }
        m_pfnState = &CDropItem::UpdatePickUpHoverState;
    }
    else if (nState == 4)
    {
        m_pfnState = &CDropItem::FUN_141192200;
    }
    else if (nState == 0)
    {
        m_n188 = 0;
        m_pfnState = &CDropItem::FUN_141191a10;
        NiTransform kXform;
        kXform.m_fScale = 1.0f;
        kXform.m_Translate = static_cast<const efd::Point3&>(vfunc_18());
        kXform.m_Rotate = DAT_143a09600;
        NoticeMessage kTarget;   // C3: was Unk_EffectTarget
        ((Unk_EffectTarget&)(kTarget)).m_strName = CItemDataTable::GetInstance()->GetGradeEffect((ItemGradeKey)m_spItem->GetRarity());
        ((Unk_EffectTarget&)(kTarget)).m_nKind = 0;
        ((Unk_EffectTarget&)(kTarget)).m_pXform = &kXform;
        m_nEffectIdA = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTarget)));
        if (m_spEffect->beEffect.GetLength() != 0)
        {
            NoticeMessage kTargetB;   // C3: was Unk_EffectTarget
            ((Unk_EffectTarget&)(kTargetB)).m_strName = m_spEffect->beEffect;
            ((Unk_EffectTarget&)(kTargetB)).m_nKind = 0;
            ((Unk_EffectTarget&)(kTargetB)).m_pXform = &kXform;
            m_nEffectIdB = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(((Unk_EffectTarget&)(kTargetB)));
        }
    }
    else if (nState == 5)
    {
        m_fGrow = 0.0f;
        m_posGrow = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18()));
        m_pfnState = &CDropItem::FUN_1411923a0;
    }
    if (!IsPickupAllowedForLocalPlayer())
    {
        static float s_fAlpha = Client::Constants::GetInstance()->DefaultDropItemAlpha.Read();
        vfunc_42(s_fAlpha, false);
    }
}

// @0x14118fe60
void CDropItem::FUN_14118fe60(int nValue) { m_n28c = nValue; }

// @0x14118fe80
void CDropItem::FUN_14118fe80(int nValue) { m_n298 = nValue; }

// @0x14118fea0
int CDropItem::IsMeso() { return 0 < m_n64Meso; }

// @0x14118fee0
int CDropItem::FUN_14118fee0() { return m_spItem->FUN_140525920(); }

// @0x14118ff10
int CDropItem::FUN_14118ff10() { return m_spItem->FUN_1405276c0() == 0x55d4a8a; }

// @0x14118ff60
int CDropItem::FUN_14118ff60() { return m_spItem->FUN_1405276c0() == 0x55d4a83; }

// @0x14118ffb0
int CDropItem::FUN_14118ffb0()
{
    return (m_spItem.get() ? true : false) && m_spItem->IsPetItem();
}

// @0x141190030
int CDropItem::IsOwnedByLocalPlayer()
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer)
    {
        unsigned __int64 nUid = static_cast<PCBase*>(pPlayer)->FUN_141656a80();
        return IsOwner(nUid);
    }
    return 0;
}

// @0x141190080
int CDropItem::IsOwner(unsigned __int64 nUid)
{
    if (m_owners.Find(nUid, 0))
        return 1;
    return 0;
}

// @0x1411900d0
int CDropItem::FUN_1411900d0()
{
    return m_n188 != 0 && m_nState != 0;
}

// Whether the player at kPos may pick the drop up (in range, off the pickup throttle, owner rules).
// @0x141190120
int CDropItem::FUN_141190120(Vector3 kPos, int nA, int nB)
{
    if (!s_kPickTimer.FUN_140868c00() && nA)
        return 0;
    if (FUN_1411900d0() && nA)
        return 0;
    if (m_nState && nA)
        return 0;
    if (!HasPickupDelayElapsed())
        return 0;
    if (GetTickCountMs2() < m_nFadeTime)
        return 0;
    if (((class Unk_DropGuideMgr*)FUN_1409331e0())->IsRestricted(7))
        return 0;
    Vector3 kPlayer(reinterpret_cast<const efd::Point3&>(kPos));
#ifdef __clang__
    NiPoint3 kSelf = vfunc_18();
    float fDistance = kPlayer.FUN_140965c40(reinterpret_cast<Vector3&>(kSelf)).FUN_140967ac0();
#else
    float fDistance = kPlayer.FUN_140965c40(reinterpret_cast<Vector3&>(vfunc_18())).FUN_140967ac0();
#endif
    kPlayer.z += m_f218;
    if (fDistance > (m_f27c > m_f21c ? m_f27c : m_f21c))
        return 0;
    if (!nB)
    {
        int bAllowed = 0;
        if (m_nOwnerType == 2)
            bAllowed = 1;
        else if (m_nOwnerType == 0 || m_nOwnerType == 1)
        {
            if (IsOwnedByLocalPlayer() == 1)
                bAllowed = 1;
        }
        if (!bAllowed)
            return 0;
    }
    return 1;
}

// @0x141190320
int CDropItem::FUN_141190320(GameObject* pActor, int nA, int nB)
{
    return FUN_1411903c0(pActor, m_f21c, nA, nB);
}

// @0x141190370
int CDropItem::FUN_141190370(GameObject* pActor, int nA, int nB)
{
    return FUN_1411903c0(pActor, m_f220, nA, nB);
}

// @0x1411903c0
int CDropItem::FUN_1411903c0(GameObject* pActor, float fRange, int nA, int nB)
{
    if (!pActor)
        return 0;
    if (!s_kPickTimer.FUN_140868c00() && nA)
        return 0;
    if (FUN_1411900d0() && nA)
        return 0;
    if (m_nState && nA)
        return 0;
    if (!HasPickupDelayElapsed())
        return 0;
    if (GetTickCountMs2() < m_nFadeTime)
        return 0;
    if (((class Unk_DropGuideMgr*)FUN_1409331e0())->IsRestricted(7))
        return 0;
#ifdef __clang__
    NiPoint3 kActor = pActor->vfunc_18();
    Vector3 kPlayer(reinterpret_cast<const efd::Point3&>(kActor));
    NiPoint3 kSelf = vfunc_18();
    float fDistance = kPlayer.FUN_140965c40(reinterpret_cast<Vector3&>(kSelf)).FUN_140967ac0();
#else
    Vector3 kPlayer(reinterpret_cast<const efd::Point3&>(pActor->vfunc_18()));
    float fDistance = kPlayer.FUN_140965c40(reinterpret_cast<Vector3&>(vfunc_18())).FUN_140967ac0();
#endif
    kPlayer.z += m_f218;
    if (fDistance > fRange)
        return 0;
    if (!nB)
    {
        int bAllowed = 0;
        if (m_nOwnerType == 2)
            bAllowed = 1;
        else if (m_nOwnerType == 0 || m_nOwnerType == 1)
        {
            if (IsOwnedByLocalPlayer() == 1)
                bAllowed = 1;
        }
        if (!bAllowed)
            return 0;
    }
    return 1;
}

// @0x1411905a0
int CDropItem::IsPickupAllowedForLocalPlayer()
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    int bAllowed = 0;
    if (m_nOwnerType == 2)
        bAllowed = 1;
    else if (m_nOwnerType == 0 || m_nOwnerType == 1)
    {
        if (IsOwnedByLocalPlayer() == 1)
            bAllowed = 1;
    }
    if (bAllowed == 0)
        return 0;
    return 1;
}

// @0x141190640
int CDropItem::FUN_141190640(bool bForce)
{
    int bInBag = g_143ab2a90.FUN_140a615d0(0);
    if (bInBag == 0 && FUN_1411906a0() == 0 && bForce == 0)
        return 0;
    return 1;
}

// @0x1411906a0
int CDropItem::FUN_1411906a0()
{
    if (!m_spItem->IsStackable())
        return 0;
    {
        ATL::CAtlList<MS2Ptr<CItem> > kHave(10);
        g_143ab2a90.FUN_140a5e8d0(m_spItem->FUN_1405276c0(), kHave, 1);
        for (POSITION pos = kHave.GetHeadPosition(); pos; kHave.GetNext(pos))
        {
            MS2Ptr<CItem> spHave = kHave.GetAt(pos);
            if (spHave.get())
            {
                if (spHave->GetSlotMax() >= (unsigned)(spHave->GetCount() + m_spItem->GetCount()))
                    return 1;
            }
        }
    }
    return 0;
}

// @0x141190830
void CDropItem::SendRequestItemPickup(int nPickerId)
{
    FUN_141192840(1);
    FUN_141191030();
    COutPacket kPacket(static_cast<int>(SendOp::RequestItemPickup), 0);
    kPacket.Encode4(FUN_14123c580());
    kPacket.COutPacket::WriteBool(nPickerId != 0);
    if (nPickerId != 0)
        kPacket.Encode4(nPickerId);
    FUN_140710590(kPacket);
}

// Asks the server to pick the drop up, with the inventory and block checks first.
// @0x141190900
void CDropItem::FUN_141190900(int nPickerId)
{
    if (FUN_1411900d0())
        return;
    if (m_spItem->FUN_140525980() || FUN_14053f900(m_spItem->FUN_1405276c0()))
    {
        SendRequestItemPickup(nPickerId);
        return;
    }
    {
        BlockPtr spBlock = ((class CBlockManager*)FUN_140a6a830())->FindBlockedAction(0x13);
        if (spBlock.get())
        {
            static Unk_IntervalTimer s_kNoticeTick;
            if (s_kNoticeTick.Check(5000) == 1)
            {
                CStringW strNotice = FUN_1401ca400(spBlock, 0x20);
                FUN_1412751b0(strNotice, 0x14);
            }
            FUN_1411911a0();
            return;
        }
    }
    if (g_143ab2a90.FUN_140a61430(g_143ab2a90.FUN_140a617f0(m_spItem)))
    {
        SendRequestItemPickup(nPickerId);
        return;
    }
    if (!FUN_1411906a0())
    {
        FUN_141275260(0x43, 1, 1);
        FUN_141276180(s_strWarningBag, "");
        FUN_1411911a0();
    }
    SendRequestItemPickup(nPickerId);
}

// The drop was picked up by the actor nPickerId: sound, pickup notices, then the fly-to-owner state.

// @0x141190b70
void CDropItem::FUN_141190b70(int nPickerId)
{
    GameObject* pPicker = reinterpret_cast<GameObject*>(efd::DynamicCast<MyPC, PCBase>(reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1200(nPickerId))));
    if (pPicker)
    {
        if (m_spItem.get() ? true : false)
        {
            if (m_spEffect.get() ? true : false)
            {
                NiTransform kXform;
                kXform.m_fScale = 1.0f;
                kXform.m_Translate = static_cast<const efd::Point3&>(pPicker->vfunc_18());
                kXform.m_Rotate = DAT_143a09600;
                CString strSound = m_spEffect->getSoundID;
                if (!strSound.IsEmpty())
                    TSingleton<CEffectService>::GetInstance()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), 1, &kXform, 1.0f, 0);
                if (m_spItem->GetRarity() >= 1)
                {
                    if (m_spItem->FUN_1405258f0() == 0)
                    {
                        if (m_spItem->FUN_140525950() == 0 && FUN_14118fee0() == 0)
                        {
                            UIRewardNotify* pBag = ((class UIRewardNotify*)FUN_140938cd0(0x4e5d));
                            if (pBag)
                                pBag->FUN_141abfa10(m_spItem);
                        }
                    }
                }
            }
        }
        if (m_spItem->FUN_140528980())
            ((class Unk_DropGuideMgr*)FUN_1409331e0())->AddTrigger((CGuideManager::TriggerType)0xc, m_spItem->FUN_1405276c0(), 0);
    }
    if (m_nState == 6)
    {
        vfunc_23(0);
        if (m_spShadow)
        {
            FUN_14160fe10(m_spShadow.operator->(), true);
            vfunc_32(true);
        }
    }
    if (m_nState == 0)
    {
        m_n188 = nPickerId;
        s_kPickTimer.FUN_140868750(0x96);
        FUN_14118d9a0(2);
    }
}

// @0x141191030
void CDropItem::FUN_141191030() { m_nTick = GetTickCountMs2(); }

// @0x141191060
bool CDropItem::HasPickupDelayElapsed()
{
    unsigned int nNow = GetTickCountMs2();
    if (m_nTick + 1000 > nNow)
        return false;
    return true;
}

// @0x1411910a0
int CDropItem::GetOwnerObjId() { return m_nOwnerObjId; }

// @0x1411910c0
int CDropItem::GetDropKind() { return m_nDropKind; }

// @0x1411910e0
unsigned __int64 CDropItem::GetFirstOwner()
{
    if (!m_owners.GetCount())
        return 0;
    POSITION pPos = m_owners.GetHeadPosition();
    unsigned __int64 nUid = m_owners.GetAt(pPos);
    return nUid;
}

// @0x141191150
int CDropItem::FUN_141191150()
{
    return m_nState == 1 || m_nState == 6;
}

// @0x1411911a0
void CDropItem::FUN_1411911a0() { FUN_14118d9a0(5); }

// @0x1411911d0
void CDropItem::vfunc_47(bool b) { m_bUnk138 = false; }

// @0x1411911f0
void CDropItem::FUN_1411911f0()
{
    if (!IsMeso())
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
        if (pRoot)
            FUN_14118d720(pRoot);
    }
}

// The pet-ball (SPEP) drops use their own settings.
// @0x141191240
void CDropItem::LoadSpepBallConstants()
{
    m_f218 = Client::Constants::GetInstance()->DropSPEPBallTargetZPos.Read();
    m_f21c = Client::Constants::GetInstance()->DropSPEPBallMaxLength.Read();
    m_f224 = Client::Constants::GetInstance()->DropSPEPBallPickUpVel.Read();
    m_f228 = Client::Constants::GetInstance()->DropSPEPBallPickUpGravity.Read();
    m_f22c = Client::Constants::GetInstance()->DropSPEPBallPickUpCompleteRotateTime.Read();
    m_f230 = Client::Constants::GetInstance()->DropSPEPBallPickUpCompleteRotateVel.Read();
    m_f27c = m_f21c;
}

// @0x141191330
void CDropItem::FUN_141191330(int nValue) { m_n278 = nValue; }

// @0x141191350
void CDropItem::vfunc_49()
{
    float fScale = 100.0f;
    float fBias = 5.0f;
    if (m_spItem.get())
    {
        fScale = m_spEffect->shadowScale;
        fBias = m_spEffect->shadowBias;
    }
    CGraphicOptionTable* pCfg = TSingleton<CGraphicOptionTable>::GetInstance();
    int nLodHi = pCfg->GetShadowOption(4);
    int nLodLo = pCfg->GetShadowOptionOffset(4);
    m_spShadow = NiNew CObjectShadow((void*)static_cast<GameObject*>(this), nLodHi, nLodLo, fScale, fBias);
    FUN_14160fe10(m_spShadow.operator->(), false);
}

// @0x1411914d0
void CDropItem::vfunc_53(float fTime)
{
    GameObject::vfunc_53(fTime);
    if (m_nFadeTime != 0 && m_nFadeTime < GetTickCountMs2())
    {
        vfunc_23(0);
        if (m_spShadow)
        {
            FUN_14160fe10(m_spShadow.operator->(), true);
            vfunc_32(true);
        }
    }
    if (m_nDropKind == 0xc80 && !FUN_14118ffb0() && m_n298 != 0)
    {
        if (m_nFadeTime == 0)
        {
            m_nFadeTime = GetTickCountMs2() + *Client::Constants::GetInstance()->PetTrapDropVisibleDelay.Get();
            vfunc_23(1);
            return;
        }
        else if (m_nFadeTime > GetTickCountMs2())
            return;
    }
    if (m_nState == 6)
    {
        vfunc_23(0);
        FUN_14118d9a0(1);
    }
    Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FindObjectById(m_n188);
    if (FUN_1411900d0() && !pOwner)
        WorldService::GetInstance()->FUN_141bbb7f0(this, 0);
    else if (m_pfnState)
    {
        GameObject* pTarget = WorldService::GetInstance()->FindObjectById(m_n278);
        if (!pTarget)
            pTarget = pOwner;
        m_fSpawnTime += fTime;
        (this->*m_pfnState)(fTime, pTarget);
    }
}

// State 1: flies out of the source along the arc.
// @0x141191780
void CDropItem::FUN_141191780(double fTime, GameObject* pTarget)
{
    bool bArrived = m_fElapsed > m_arc.m_flightScale;
    if (bArrived)
    {
        FUN_14118d9a0(0);
        vfunc_19(reinterpret_cast<efd::Point3&>(m_arc.m_target));
    }
    else
    {
        m_fElapsed += (float)fTime * 10.0f;
        Vector3 kOffset = FUN_1409ab5c0(m_arc.m_speed * m_arc.m_angle.x * m_fElapsed, m_arc.m_direction);
        kOffset.z = 0.5f * m_arc.m_gravity * m_fElapsed * m_fElapsed + m_arc.m_speed * m_arc.m_angle.y * m_fElapsed;
        efd::Point3 kPos = reinterpret_cast<const efd::Point3&>(m_arc.m_origin) + reinterpret_cast<const efd::Point3&>(kOffset);
        vfunc_19(reinterpret_cast<efd::Point3&>(reinterpret_cast<Vector3&>(kPos)));
        if (m_spItem.get())
            FUN_1411925e0(m_spEffect->dropAni, m_spEffect->dropAniSpeed);
    }
}

// State 0: waits on the ground and bobs.
// @0x141191a10
void CDropItem::FUN_141191a10(double fTime, GameObject* pTarget)
{
    if (m_spItem.get() ? true : false)
    {
        if (m_spItem->FUN_140527840())
        {
            m_fElapsed += (float)fTime;
            if (0.0f < m_spEffect->bouncePeriod)
            {
                if (m_fElapsed > m_spEffect->bouncePeriod)
                    m_fElapsed = 0.0f;
                float fPhase = m_fElapsed * 3.1415927f * 2.0f;
                float fSin = -1.0f * __imp_sinf(fPhase / m_spEffect->bouncePeriod) * 0.5f;
                float fZ = m_spEffect->bounceHeight * fSin;
#ifdef __clang__
                efd::Point3 kPos = reinterpret_cast<const efd::Point3&>(m_arc.m_target) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, fZ)));
                vfunc_19(reinterpret_cast<efd::Point3&>(reinterpret_cast<Vector3&>(kPos)));
#else
                vfunc_19(reinterpret_cast<const efd::Point3&>(m_arc.m_target) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, fZ))));
#endif
            }
            m_f27c = FUN_140966f00(m_posOrigin, reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18()))) + 10.0f;
        }
    }
    if (m_spItem.get())
        FUN_1411925e0(m_spEffect->beAni, m_spEffect->beAniSpeed);
}

// State 2: flies to the owner who picked it up.
// @0x141191d10
void CDropItem::FUN_141191d10(double fTime, GameObject* pTarget)
{
    Vector3 kGoal(pTarget->vfunc_18());
    kGoal.z += m_f218;
    bool bArrived = m_fElapsed > m_arc.m_flightScale;
    if (bArrived)
        FUN_14118d9a0(3);
    else
    {
        m_fElapsed += (float)fTime * 10.0f;
#ifdef __clang__
        NiPoint3 kNow = pTarget->vfunc_18();
        Vector3 kDir = FUN_141192780(Vector3(m_arc.m_origin), reinterpret_cast<Vector3&>(kNow), true);
#else
        Vector3 kDir(reinterpret_cast<const efd::Point3&>(FUN_141192780(m_arc.m_origin, reinterpret_cast<Vector3&>(pTarget->vfunc_18()), true)));
#endif
        Vector3 kOffset = FUN_1409ab5c0(m_arc.m_speed * m_arc.m_angle.x * m_fElapsed, m_arc.m_direction);
        kOffset.z = 0.5f * m_arc.m_gravity * m_fElapsed * m_fElapsed + m_arc.m_speed * m_arc.m_angle.y * m_fElapsed;
#ifdef __clang__
        NiPoint3 kPull = pTarget->vfunc_18();
        kOffset.FUN_140a4e560(reinterpret_cast<Vector3&>(kPull).FUN_140965c40(reinterpret_cast<Vector3&>(m_posGround)));
        efd::Point3 kPos = reinterpret_cast<const efd::Point3&>(m_arc.m_origin) + reinterpret_cast<const efd::Point3&>(kOffset);
        vfunc_19(reinterpret_cast<efd::Point3&>(reinterpret_cast<Vector3&>(kPos)));
#else
        Vector3 kDrift(reinterpret_cast<const efd::Point3&>(reinterpret_cast<Vector3&>(pTarget->vfunc_18()).FUN_140965c40(reinterpret_cast<Vector3&>(m_posGround))));
        kOffset.FUN_140a4e560(kDrift);
        vfunc_19(reinterpret_cast<const efd::Point3&>(m_arc.m_origin) + reinterpret_cast<const efd::Point3&>(kOffset));
#endif
        if (m_spItem.get())
            FUN_1411925e0(m_spEffect->getAni, m_spEffect->getAniSpeed);
    }
}

// State 3: hovers over the owner for the rotate time.
// @0x1411920b0
void CDropItem::UpdatePickUpHoverState(double fTime, GameObject* pTarget)
{
    m_fElapsed += (float)fTime;
    if (m_fElapsed > m_f22c)
        FUN_14118d9a0(4);
    else
    {
        NiPoint3 kPos = pTarget->vfunc_18();
        kPos.z += m_f218;
        vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
        FUN_1411925e0(efd::Point3(0.0f, 0.0f, 1.0f), m_f230);
    }
}

// State 4: sinks away, then the drop is destroyed.
// @0x141192200
void CDropItem::FUN_141192200(double fTime, GameObject* pTarget)
{
    Vector3 kDelta = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18())).FUN_140965c40(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(vfunc_18())));
    if (kDelta.FUN_140967ac0() < 100.0f || kDelta.FUN_140967ac0() > 300.0f)
    {
        WorldService::GetInstance()->FUN_141bbb7f0(this, 0);
    }
    else
    {
        Vector3 kPos(reinterpret_cast<const efd::Point3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18())));
        kPos.z = vfunc_18().z;
        kPos.z = kPos.z - (float)fTime * 1000.0f;
        Vector3 kTmp = kPos;
        vfunc_19(reinterpret_cast<efd::Point3&>(kTmp));
    }
}

// State 5: grows back in after a failed pickup.
// @0x1411923a0
void CDropItem::FUN_1411923a0(double fTime, GameObject* pTarget)
{
    m_fGrow = m_fGrow + fTime;
    static float s_fFailTime = Client::Constants::GetInstance()->DropItemPickFailTime.Read();
    static float s_fFailHeight = Client::Constants::GetInstance()->DropItemPickFailHeight.Read();
    float fRatio = m_fGrow / s_fFailTime;
    if (fRatio >= 1.0f)
    {
        m_fGrow = 0.0f;
        m_nState = 0;
        m_pfnState = &CDropItem::FUN_141191a10;
    }
    else
    {
        float fPhase = 3.1415927f * fRatio;
        float fZ = __imp_sinf(fPhase) * s_fFailHeight;
#ifdef __clang__
        efd::Point3 kPos = reinterpret_cast<const efd::Point3&>(m_posGrow) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, fZ)));
        vfunc_19(reinterpret_cast<efd::Point3&>(reinterpret_cast<Vector3&>(kPos)));
#else
        vfunc_19(reinterpret_cast<const efd::Point3&>(m_posGrow) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, fZ))));
#endif
    }
}

// Spins the model by fDegrees around kAxis.
// @0x1411925e0
void CDropItem::FUN_1411925e0(efd::Point3 kAxis, float fDegrees)
{
    if (FUN_14118ffb0())
        return;
    efd::Point3 kRot = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kAxis))) * fDegrees * 360.0f * m_fSpawnTime;
    vfunc_21(reinterpret_cast<efd::Point3&>(reinterpret_cast<Vector3&>(kRot)));
}

// @0x141192840
void CDropItem::FUN_141192840(int nValue) { m_n294 = nValue; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caca70-0x142cacb40 .text$yd
