// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StatePlayInstrument / StatePlayInstrumentData: the actor
// state of a player playing an instrument (the ready / solo / ensemble sub states) and the MS2Ptr glue it instantiates.
// See stateplayinstrumentdata.h.
// MS2-UNIT: ?\stateplayinstrumentdata.cpp
// MS2-RANGE: 0x140dde050-0x140de0f70 .text$mn
// MS2-PIN: ?GetURN@AssetID@efd@@QEBAAEBVutf8string@2@XZ 0x140de0ca0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateplayinstrumentdata.cpp"    // assumed
#define NOMINMAX                        // NxPhysics (avatarpc.h)
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>

#include <new>
#include <string.h>
#include <errno.h>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <efd/AssetID.h>
#include <egf/EntityIDFactory.h>
#include <NiNode.h>
#include <NiAVObject.h>

#include "stateplayinstrumentdata.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/instrumentmanager.h"
#include "ms2/client/ms2/effectservice.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The state-sync record (slots 1/2 of StateData): the item id is kept at +0x64.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x64];
    int m_n64;                                               // +0x64
    char m_pad_68[0xb8 - 0x68];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_n64, 0x64);

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

// A player seen with the slots after PCBase's last declared one (123): the held item of the player.
class Unk_PiPC : public PCBase
{
public:
    virtual void vfunc_124();
    virtual void vfunc_125();
    virtual void vfunc_126();
    virtual void vfunc_127(CItem* pItem, int n);             // MS2: slot 127 (0x3f8) puts the item into the hand
    virtual void vfunc_128(CItem* pItem, int n);             // MS2: slot 128 (0x400) takes it out again
};

// The config object with the effect file names of the instrument states (one name per sub state, cheap / expensive
// instrument, plain / ensemble-with-peers).
class Unk_PiStrings
{
public:
    char m_pad_00[0x518];
    CString m_str518;                                        // +0x518 sub state 0x7e
    CString m_str520;                                        // +0x520 sub state 0x7f
    CString m_str528;                                        // +0x528 sub state 0x80
    CString m_str530;                                        // +0x530 sub state 0x81
    CString m_str538;                                        // +0x538 sub state 0x7e (with a guild / group)
    CString m_str540;                                        // +0x540 sub state 0x7f (with a guild / group)
    CString m_str548;                                        // +0x548 sub state 0x81 (with a guild / group)
    CString m_str550;                                        // +0x550 sub state 0x7e (expensive instrument)
    CString m_str558;                                        // +0x558 sub state 0x7f (expensive)
    CString m_str560;                                        // +0x560 sub state 0x80 (expensive)
    CString m_str568;                                        // +0x568 sub state 0x81 (expensive)
    CString m_str570;                                        // +0x570 sub state 0x7e (expensive, with a group)
    CString m_str578;                                        // +0x578 sub state 0x7f (expensive, with a group)
    CString m_str580;                                        // +0x580 sub state 0x81 (expensive, with a group)
    CString m_str588;                                        // +0x588 leave effect of the ready state (cheap)
    CString m_str590;                                        // +0x590 leave effect of the ready state (expensive)
};
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

// The animation service of an entity: plays an animation on an entity id.
class Unk_AnimSvc { public: bool PlayAnimation(const egf::EntityID& entityID, const efd::utf8string& sequenceName, float fBlend, bool bForce); };
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();

// The model loader (singleton): loads a nif by path.
class CNifLoadingService
{
public:
    NiAVObjectPtr Load(CString strPath, bool bFlag, int nClass, int nMyRefs, int nOtherRefs);   // model load
};
class Unk_ResourceMgr* GetNifLoadingService();
CString FUN_140cc2ba0(const CString& strDir, const CString& strFile);   // dir + "/" + file

class Unk_AvModeSvc* GetOptimizer();   // C3: was GetOptimizer

// The tutorial / achievement counter of the played instrument.
class Unk_PiCounter : public CInstrumentManager
{
};
struct Unk_PmFixedItem* GetInstrumentManager();   // C3: was GetInstrumentManager

int GetRandomRange(int nRange, int nBase);                    // random number in [nBase, nBase + nRange)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
// C3: FUN_140a38a50 is egf::Entity::SetPropertyValue<efd::Point3> (0x140a38a50)
void SetCachedBoolProperty(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);             // the scene root of an entity
CString FUN_1409a2360(const char* psz, int n);               // text conversion
CString FUN_141b6ed00(const CString& str);                   // normalised copy of a model name
__int64 GenerateUniqueId();                                     // the current time

// The owner's position slot (vfunc_18) seen as returning the Vector3 placeholder.
class Unk_SpiPos
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Vector3 vfunc_18();
};


// @0x140de0900
// The owner as an AvatarPC (class id 0x6200044), NULL when it is none.
static AvatarPC* GetAvatarPC(GameObject* pObject)
{
    void* pValue = 0;
    if (pObject && pObject->TypeCast(0x6200044, &pValue))
        return (AvatarPC*)pValue;
    else
        return 0;
}

// @0x140de0cb0
// The asset url of an animation; a url that ends in ':' (nothing after the scheme) is not stored.
void FUN_140de0cb0(efd::AssetID* pAsset, const efd::utf8string& strUrn)
{
    unsigned __int64 nLen = strUrn.length();
    if (nLen != 0)
    {
        if (strUrn[nLen - 1] == ':')
            return;
    }
    // m_urn (+0x8) is private; the exe assigns it directly (SetURN inlined).
    *reinterpret_cast<efd::utf8string*>(reinterpret_cast<char*>(pAsset) + 0x8) = strUrn;
}

// ---- StatePlayInstrumentData ----

// @0x140dde050
StatePlayInstrumentData::StatePlayInstrumentData() : m_n28(0)
{
}

// @0x140dde0b0
StatePlayInstrumentData::StatePlayInstrumentData(MS2Ptr<CItemData> spItem, __int64 n) : m_spItem(spItem), m_n28(n)
{
}

// @0x140dde130
void StatePlayInstrumentData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_spItem->GetItemId();
}

// @0x140dde180
void StatePlayInstrumentData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_spItem = FUN_14053f870(p->m_n64);
}

// @0x140dde200
int StatePlayInstrumentData::GetInstrumentId()
{
    if (m_spItem == 0)
        return 0;
    return m_spItem->GetParam1();
}

// ---- StatePlayInstrument ----

// @0x140dde250
StatePlayInstrument::StatePlayInstrument(PCBase* pOwner) : State(pOwner), m_spEffect(0), m_spEntity(0)
{
    m_spEffect = 0;
    m_spInstrument = 0;
    m_vPos = DAT_143b01a60;
    m_bA0 = false;
    m_spEntity = 0;
    m_nB0 = 0;
    m_bB4 = false;
}

// @0x140dde3b0
StatePlayInstrument::~StatePlayInstrument()
{
}

// @0x140dde460
void StatePlayInstrument::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 0x7d;
    m_spInstrumentData.AssignRaw(dynamic_cast<StatePlayInstrumentData*>(pData));
    if (m_spInstrumentData.IsNull())
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    MS2Ptr<CItemData> spItemData = m_spInstrumentData->m_spItem;
    if (spItemData == 0)
        return;
    m_spInstrument = CInstrumentDataTable::GetInstance()->GetInstrument(m_spInstrumentData->GetInstrumentId());
    if (m_spInstrument == 0)
        return;
    if (m_pOwner->vfunc_65() != 0)
        m_pOwner->SetEmotion(0);
    m_nB0 = m_pOwner->vfunc_25();
    m_bB4 = false;
    if (m_spInstrument->m_strAsset.GetLength() > 0)
    {
        if (m_spInstrument->m_strAsset.Find(".kfm", 0) != -1)
        {
            // a kfm: the instrument is an entity of its own
            egf::EntityIDFactory::GetNextID();
            efd::AssetID kAsset;
            CString strName = FUN_141b6ed00(m_spInstrument->m_strAsset);
            CString strUrn = "urn:gamebryo-animation:" + strName;
            FUN_140de0cb0(&kAsset, efd::utf8string((const char*)FUN_1409a2360(strUrn, 0)));
            m_spEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411ce7c0("MS2Actor", kAsset.GetURN(),
                reinterpret_cast<const efd::Point3&>(static_cast<const NiPoint3&>(m_pOwner->vfunc_18())), reinterpret_cast<const efd::Point3&>(static_cast<const NiPoint3&>(m_pOwner->vfunc_20())), 1.0f, 0, 0);
            if ((egf::Entity*)m_spEntity)
            {
                efd::utf8string kAnim((const char*)FUN_1409a2360(m_spInstrument->m_strAnimationReady, 0));
                m_spEntity.operator->()->SetPropertyValue<efd::utf8string>(0x3ff293c8, kAnim);
                AvatarPC* pAvatar = GetAvatarPC(m_pOwner);
                if (pAvatar != 0)
                {
                    bool bHide = false;
                    SetCachedBoolProperty((class Unk_CachedEntity*)m_spEntity.operator->(), 0xa0b6b179, bHide);
                }
                else
                {
                    m_bB4 = true;
                    bool bShow = true;
                    SetCachedBoolProperty((class Unk_CachedEntity*)m_spEntity.operator->(), 0xa0b6b179, bShow);
                    if (m_nB0 != 0 && reinterpret_cast<COptimizer*>(GetOptimizer())->FUN_140ddcc90() == 0)
                    {
                        bool bHide = false;
                        SetCachedBoolProperty((class Unk_CachedEntity*)m_spEntity.operator->(), 0xa0b6b179, bHide);
                    }
                }
            }
        }
        else
        {
            // an effect model: attached under the owner's scene root
            m_spEffect = static_cast<NiNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, static_cast<NiObject*>(((class CNifLoadingService*)GetNifLoadingService())->Load(
                FUN_140cc2ba0("Effect", m_spInstrument->m_strAsset), false, 5, 0, 0).operator NiAVObject*())));
            if ((NiNode*)m_spEffect)
            {
                NiNode* pRoot = static_cast<NiNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, FUN_141b6efc0(m_pOwner->GetEntity())));
                if (pRoot != 0)
                {
                    pRoot->AttachChild(m_spEffect, true);
                    m_spEffect->UpdateEffects();
                    m_spEffect->UpdateProperties();
                    m_spEffect->Update(0.0f, true);
                    if (m_nB0 != 0 && reinterpret_cast<COptimizer*>(GetOptimizer())->FUN_140ddcc90() == 0)
                        m_spEffect->SetAppCulled(1);
                }
            }
        }
    }
    if (spItemData->GetItemPreset() != 0)
    {
        Unk_PiPC* pPC = static_cast<Unk_PiPC*>(FUN_1417b8370());
        if (pPC != 0)
        {
            MS2Ptr<CItem> spNew(new CItem);
            if (spNew->FUN_140523c40(spItemData->GetItemId(), 1, 0))
            {
                spNew->SetObjectId(m_pOwner->GetObjectId());
                spNew->SetItemUid(GenerateUniqueId());
                spNew->SetVariant(5);
                pPC->vfunc_127(spNew.get(), 0);
                m_spItem = spNew;
            }
        }
    }
    if (FUN_1417b8560() != 0)
    {
        ((class Unk_PiCounter*)GetInstrumentManager())->SetInstrument(m_spInstrumentData->GetInstrumentId(), m_spInstrumentData->m_n28);
        m_vPos = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(m_pOwner->vfunc_18()));
    }
    Unk_EffectQuery kQuery;
    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str588;
    kQuery.m_nObject = (FUN_1417b8560() != 0) ? 1 : 3;
    kQuery.SetActor(m_pOwner->GetObjectId());
    TSingleton<CEffectService>::GetInstance()->InsertEffect(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    PlayStateAnimation();
    FUN_140ddfc00();
}

// @0x140ddf110
void StatePlayInstrument::vfunc_5(int n)
{
    State::vfunc_5(n);
    AvatarPC* pAvatar = GetAvatarPC(m_pOwner);
    if (pAvatar != 0)
        pAvatar->FUN_1409f5830();
    m_spInstrument = 0;
    if (m_spEffect)
    {
        NiNode* pParent = static_cast<NiAVObject*>(m_spEffect.operator->())->GetParent();
        if (pParent != 0)
        {
            pParent->DetachChild(m_spEffect);
            m_spEffect = 0;
        }
    }
    if (m_spItem.get())
    {
        Unk_PiPC* pPC = static_cast<Unk_PiPC*>(FUN_1417b8370());
        if (pPC != 0)
            pPC->vfunc_128(m_spItem.get(), 0);
        m_spItem = 0;
    }
    if (m_spEntity)
    {
        if (m_bB4)
        {
            NiNode* pNode = static_cast<NiNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, FUN_141b6efc0(m_spEntity)));
            if (pNode != 0)
            {
                NiNode* pParent = static_cast<NiAVObject*>(pNode)->GetParent();
                if (pParent != 0)
                    pParent->DetachChild(pNode);
            }
        }
        TSingleton<EntityWorldManager>::GetInstance()->DestroyEntity(m_spEntity);
        m_spEntity = 0;
    }
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect68);
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect6c);
    m_nEffect68 = 0;
    m_nEffect6c = 0;
    Unk_EffectQuery kQuery;
    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str590;
    kQuery.m_nObject = (FUN_1417b8560() != 0) ? 1 : 3;
    kQuery.SetActor(m_pOwner->GetObjectId());
    TSingleton<CEffectService>::GetInstance()->InsertEffect(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    if (FUN_1417b8560() != 0)
        ((class Unk_PiCounter*)GetInstrumentManager())->Stop();
}

// @0x140ddf4b0
// MS2-FUNCTIONAL: temporaries differ from the exe
void StatePlayInstrument::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_nB0 != m_pOwner->vfunc_25())
    {
        m_nB0 = m_pOwner->vfunc_25();
        if (!efd::ClassInfo::IsKindOf(m_pOwner ? m_pOwner->GetClassDesc() : 0, 0x6200044))
        {
            if (((NiNode*)m_spEffect ? true : false) && reinterpret_cast<COptimizer*>(GetOptimizer())->FUN_140ddcc90() == 0)
                m_spEffect->SetAppCulled(m_nB0 != 0 ? true : false);
            if (((egf::Entity*)m_spEntity ? true : false) && reinterpret_cast<COptimizer*>(GetOptimizer())->FUN_140ddcc90() == 0)
            {
                bool bShow = m_nB0 != 0 ? false : true;
                SetCachedBoolProperty((class Unk_CachedEntity*)(m_spEntity.operator->()), 0xa0b6b179, bShow);
            }
        }
    }
    if (!m_bB4 && ((egf::Entity*)m_spEntity ? true : false) && m_spEntity.operator->()->IsCreated())
    {
        AvatarPC* pAvatar = GetAvatarPC(m_pOwner);
        if (pAvatar != 0)
        {
            NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
            if (pRoot != 0)
            {
                m_spEntity.operator->()->SetPropertyValue<efd::Point3>(0xfd95ca52, reinterpret_cast<const efd::Point3&>(DAT_143b01a60));
                m_spEntity.operator->()->SetPropertyValue<efd::Point3>(0x68c7c29d, reinterpret_cast<const efd::Point3&>(DAT_143b01a60));
                bool bShow = true;
                SetCachedBoolProperty((class Unk_CachedEntity*)(m_spEntity.operator->()), 0xa0b6b179, bShow);
                NiNode* pNode = static_cast<NiNode*>(NiObject::DynamicCast(&NiNode::ms_RTTI, pRoot));
                pAvatar->AddExternalNode(pNode);
                m_bB4 = true;
            }
        }
    }
    Vector3 kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
    if (FUN_1417b8560() == 0)
        return;
    if (m_pOwner->vfunc_99(0) != 0)
    {
        m_pOwner->vfunc_59(5, 0, 0, 0);
    }
    else if ((reinterpret_cast<Unk_SpiPos*>(m_pOwner)->vfunc_18() - m_vPos).Length() > 50.0f)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x140ddf9e0
void StatePlayInstrument::vfunc_2(int n)
{
    int nOld = m_n10;
    State::vfunc_2(n);
    if (nOld == n)
        return;
    m_bA0 = false;
    FUN_140ddfc00();
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    if (m_spInstrument.IsNull())
        return;
    m_strLastAnim = m_spInstrument->m_strAnimationPlayIdle;   // exe: row +0x50
    if (m_n10 == 0x7e || m_n10 == 0x7f || m_n10 == 0x81)
        FUN_140de0780(m_strLastAnim);
    else
        PlayStateAnimation();
}

// @0x140ddfae0
void StatePlayInstrument::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    PlayStateAnimation();
}

// @0x140ddfb10
int StatePlayInstrument::vfunc_22(MS2Ptr<StateSyncObject> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_nSub)
        return 0;
    return 1;
}

// @0x140ddfbb0
int StatePlayInstrument::GetInstrumentId()
{
    if (m_spInstrumentData.get())
        return m_spInstrumentData->GetInstrumentId();
    return 0;
}

// @0x140ddfc00
// MS2-FUNCTIONAL: the four sub states are written as one table walk
void StatePlayInstrument::FUN_140ddfc00()
{
    if (m_spInstrument.IsNull())
        return;
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect68);
    m_nEffect68 = 0;
    bool bExpensive = m_spInstrument->m_bExpensive;
    if (m_n10 == 0x7d)
    {
    }
    else if (m_n10 == 0x7e)
    {
        Unk_EffectQuery kQuery;
        if (bExpensive)
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str550;
        else
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str518;
        kQuery.m_nObject = FUN_1417b8560() != 0 ? 1 : 3;
        kQuery.SetActor(FUN_1417b8370()->GetObjectId());
        {
            CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FindByAccount(FUN_1417b8370()->FUN_141656a80());
            if (spBuddy.get() != 0 && spBuddy->FUN_1401cc5b0() != 0)
            {
                if (bExpensive)
                    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str570;
                else
                    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str538;
            }
        }
        m_nEffect68 = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    }
    else if (m_n10 == 0x7f)
    {
        Unk_EffectQuery kQuery;
        if (bExpensive)
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str558;
        else
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str520;
        kQuery.m_nObject = FUN_1417b8560() != 0 ? 1 : 3;
        kQuery.SetActor(FUN_1417b8370()->GetObjectId());
        {
            CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FindByAccount(FUN_1417b8370()->FUN_141656a80());
            if (spBuddy.get() != 0 && spBuddy->FUN_1401cc5b0() != 0)
            {
                if (bExpensive)
                    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str578;
                else
                    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str540;
            }
        }
        m_nEffect68 = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    }
    else if (m_n10 == 0x80)
    {
        Unk_EffectQuery kQuery;
        if (bExpensive)
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str560;
        else
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str528;
        kQuery.m_nObject = FUN_1417b8560() != 0 ? 1 : 3;
        kQuery.SetActor(FUN_1417b8370()->GetObjectId());
        m_nEffect68 = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    }
    else if (m_n10 == 0x81)
    {
        Unk_EffectQuery kQuery;
        if (bExpensive)
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str568;
        else
            kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str530;
        kQuery.m_nObject = FUN_1417b8560() != 0 ? 1 : 3;
        kQuery.SetActor(FUN_1417b8370()->GetObjectId());
        {
            CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FindByAccount(FUN_1417b8370()->FUN_141656a80());
            if (spBuddy.get() != 0 && spBuddy->FUN_1401cc5b0() != 0)
            {
                if (bExpensive)
                    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str580;
                else
                    kQuery.m_strName = ((class Unk_PiStrings*)GetCommonResource())->m_str548;
            }
        }
        m_nEffect68 = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    }
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect6c);
    m_nEffect6c = 0;
    CString strEffect;
    if (m_n10 == 0x7d || m_n10 == 0x80)
    {
        if (m_spInstrument->m_strReadyEffect.GetLength() > 0)
            strEffect = m_spInstrument->m_strReadyEffect;
    }
    else if (m_n10 == 0x7f || m_n10 == 0x7e || m_n10 == 0x81)
    {
        if (m_spInstrument->m_strPlayEffect.GetLength() > 0)
            strEffect = m_spInstrument->m_strPlayEffect;
    }
    if (strEffect.GetLength() > 0)
    {
        Unk_EffectQuery kQuery;
        kQuery.m_strName = strEffect;
        kQuery.m_nObject = FUN_1417b8560() != 0 ? 1 : 3;
        kQuery.SetActor(FUN_1417b8370()->GetObjectId());
        m_nEffect6c = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kQuery));
    }
}

// @0x140de0410
void StatePlayInstrument::FUN_140de0410(int nLevel)
{
    if (m_spInstrument.IsNull())
        return;
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    m_bA0 = true;
    if (!(m_n10 == 0x7e || m_n10 == 0x7f || m_n10 == 0x81))
        return;
    PlayLevelAnimation(nLevel);
}

// @0x140de04a0
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::PlayStateAnimation()
{
    if (m_spInstrument.IsNull())
        return;
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    switch (m_n10)
    {
    case 0x7d:
    case 0x80:
        FUN_140de0780(m_spInstrument->m_strAnimationReady);
        break;
    case 0x7e:
    case 0x7f:
    case 0x81:
        if (m_bA0) {
            FUN_140de0780(m_strLastAnim);
        } else {
            int nLevel = GetRandomRange(10, 1);
            PlayLevelAnimation(nLevel);
        }
        break;
    }
}

// @0x140de05a0
void StatePlayInstrument::PlayLevelAnimation(int nLevel)
{
    if (m_spInstrument.IsNull())
        return;
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    CString strAnim = m_spInstrument->m_strAnimationPlayIdle;
    int nPeers = reinterpret_cast<PC*>(pPC)->GetMasteryGrade(2);
    if (nLevel == 0)
    {
        FUN_140de0780(m_spInstrument->m_strAnimationReady);
        return;
    }
    else if (nLevel == 1)
        strAnim = m_spInstrument->m_strAnimationPlayIdle;
    else if (nLevel == 2)
        strAnim = m_spInstrument->m_strAnimationPlayLevel1;
    else if (nLevel == 3 && nPeers >= 2)
        strAnim = m_spInstrument->m_strAnimationPlayLevel2;
    else if (nLevel == 4 && nPeers >= 3)
        strAnim = m_spInstrument->m_strAnimationPlayLevel3;
    else if (nLevel == 5 && nPeers >= 4)
        strAnim = m_spInstrument->m_strAnimationPlayLevel4;
    FUN_140de0780(strAnim);
}

// @0x140de0780
void StatePlayInstrument::FUN_140de0780(const CString& strAnim)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    efd::utf8string kAnim((const char*)FUN_1409a2360(strAnim, 0));
    m_pOwner->PlayAnimation(kAnim, reinterpret_cast<PC*>(pPC)->FUN_14165eb80(), false, false);
    m_strLastAnim = strAnim;
    if (m_spEntity)
        reinterpret_cast<Unk_AnimSvc*>(FUN_141b6f910())->PlayAnimation(reinterpret_cast<const egf::EntityPtr*>(&m_spEntity)->operator->()->GetEntityID(), kAnim, reinterpret_cast<PC*>(pPC)->FUN_14165eb80(), false);
}

// @0x140de0c00
MS2Ptr<StateData> StatePlayInstrument::vfunc_27()
{
    return MS2Ptr<StateData>(new StatePlayInstrumentData());
}

// @0x140de0c80
int StatePlayInstrument::vfunc_1()
{
    return 0x2f;
}

// @0x140de0c90
int StatePlayInstrument::vfunc_19()
{
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
