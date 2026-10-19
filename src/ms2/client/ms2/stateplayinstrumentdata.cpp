// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StatePlayInstrument / StatePlayInstrumentData: the actor
// state of a player playing an instrument (the ready / solo / ensemble sub states) and the MS2Ptr glue it instantiates.
// See stateplayinstrumentdata.h.
// MS2-UNIT: ?\stateplayinstrumentdata.cpp
// MS2-RANGE: 0x140dde050-0x140de0f70 .text$mn
// MS2-PIN: ?GetURN@AssetID@efd@@QEBAAEBVutf8string@2@XZ 0x140de0ca0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateplayinstrumentdata.cpp"    // assumed
#define NOMINMAX                        // NxPhysics (avatarpc.h)
#include "ms2/placeholder/ms2stdafx.h"

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
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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

extern Unk_StreamPoint DAT_143b01a60;                       // the zero point
extern NiRTTI DAT_143afa4d8;                                // RTTI NiNode

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
Unk_PiStrings* FUN_1401d31f0();

// The effect manager: plays an effect for a request (returns its id), stops it by id.
class Unk_PiEffectMgr
{
public:
    unsigned FUN_1411a49c0(Unk_EffectQuery* pQuery);
    void FUN_1411a4a00(Unk_EffectQuery* pQuery);
};
Unk_PiEffectMgr* FUN_1403ed280();
void FUN_1411a6060(Unk_PiEffectMgr* pMgr, int nId);

CBuddyManager* FUN_14097a780();

// The animation service of an entity: plays an animation on an entity id.
class Unk_PiAnimSvc { public: };
Unk_PiAnimSvc* FUN_141b6f910();
void FUN_1409a1fc0(Unk_PiAnimSvc* pSvc, const egf::EntityID* pEntityId, const efd::utf8string* pAnim, float fSpeed, int bFlag);
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);

// The model loader (singleton): loads a nif by path.
class Unk_PiResourceMgr
{
public:
    NiAVObjectPtr FUN_141551ea0(CString strPath, bool bA, int nB, int nC, int nD);   // model load
};
Unk_PiResourceMgr* FUN_140a0afd0();
CString FUN_140cc2ba0(const CString& strDir, const CString& strFile);   // dir + "/" + file
void* FUN_1409849b0(void* pHandle);                          // handle -> node pointer
NiNode* FUN_140a0b000(NiAVObject* pObject);                  // GetParent
EntityWorldManager* FUN_1409670f0();

// The UI root of the client: whether the local player is hidden.
class Unk_PiUiRoot
{
public:
    int FUN_140ddcc90();
};
Unk_PiUiRoot* FUN_1409f7c90();

// The tutorial / achievement counter of the played instrument.
class Unk_PiCounter
{
public:
    void FUN_140d07130(int nInstrument, __int64 n);
    void FUN_140d070b0();
};
Unk_PiCounter* FUN_140c8dac0();

int FUN_140768010(int nRange, int nBase);                    // random number in [nBase, nBase + nRange)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned nId);   // efd::ClassInfo::IsKindOf
void FUN_140a0b300(NiAVObject* pNode, char bCulled);         // set app-culled
bool FUN_14212c720(egf::Entity* pEntity);                    // the entity has finished loading
void FUN_140a38a50(egf::Entity* pEntity, unsigned nProp, const Unk_StreamPoint* pValue);   // SetProperty(point)
void FUN_14098c6e0(egf::Entity* pEntity, unsigned nProp, bool* pValue);                    // SetProperty(bool)
void FUN_140ae1240(egf::Entity* pEntity, unsigned nProp, const efd::utf8string* pValue);   // SetProperty(string)
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);             // the scene root of an entity
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);   // dynamic cast through an NiRTTI
float FUN_14165eb80(PCBase* pPC);                            // the animation speed of the player
CString FUN_1409a2360(const char* psz, int n);               // text conversion
CString FUN_141b6ed00(const CString& str);                   // normalised copy of a model name
CString FUN_140298360(const char* pszPrefix, const CString& str);   // prefix + str
__int64 FUN_14028d0e0();                                     // the current time
int FUN_1416627d0(PCBase* pPC, int n);                       // the ensemble size of the player

static inline Unk_StreamPoint PiPoint(const NiPoint3& k) { return *reinterpret_cast<const Unk_StreamPoint*>(&k); }
static inline efd::Point3 PiEfd(const NiPoint3& k) { return efd::Point3(k.x, k.y, k.z); }

// @0x140de0900
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
// The owner as an AvatarPC (class id 0x6200044), NULL when it is none.
static AvatarPC* FUN_140de0900(GameObject* pObject)
{
    AvatarPC* pValue = 0;
    if (pObject == 0 || !pObject->TypeCast(0x6200044, (const void**)&pValue))
        pValue = 0;
    return pValue;
}

// @0x140de0cb0
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
// The asset url of an animation; a url that ends in ':' (nothing after the scheme) is not stored.
void FUN_140de0cb0(efd::AssetID* pAsset, const efd::utf8string& strUrn)
{
    unsigned __int64 nLen = strUrn.length();
    if (nLen != 0)
    {
        if (strUrn[nLen - 1] == ':')
            return;
    }
    pAsset->SetURN(strUrn);
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
    p->m_n64 = m_spItem->FUN_14053c510();
}

// @0x140dde180
void StatePlayInstrumentData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_spItem = FUN_14053f870(p->m_n64);
}

// @0x140dde200
int StatePlayInstrumentData::FUN_140dde200()
{
    if (m_spItem == 0)
        return 0;
    return m_spItem->FUN_14053c650();
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
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
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
    if (spItemData.IsNull())
        return;
    int nInstrument = m_spInstrumentData->FUN_140dde200();
    m_spInstrument = CInstrumentDataTable::GetInstance()->GetInstrument(nInstrument);
    if (m_spInstrument.IsNull())
        return;
    if (m_pOwner->vfunc_65() != 0)
        m_pOwner->FUN_14166ce70(0);
    m_nB0 = m_pOwner->vfunc_25();
    m_bB4 = false;
    if (m_spInstrument->m_strAsset.GetLength() > 0)
    {
        if (m_spInstrument->m_strAsset.Find(".kfm", 0) == -1)
        {
            // an effect model: attached under the owner's scene root
            NiAVObjectPtr spModel = FUN_140a0afd0()->FUN_141551ea0(
                FUN_140cc2ba0(CString("Effect"), m_spInstrument->m_strAsset), false, 5, 0, 0);
            m_spEffect = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, static_cast<NiObject*>(FUN_1409849b0(&spModel))));
            if (m_spEffect != 0)
            {
                NiNode* pRoot = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(m_pOwner->FUN_14123c410())));
                if (pRoot != 0)
                {
                    pRoot->AttachChild(m_spEffect, true);
                    m_spEffect->UpdateEffects();
                    m_spEffect->UpdateProperties();
                    m_spEffect->Update(0.0f, true);
                    if (m_nB0 != 0 && FUN_1409f7c90()->FUN_140ddcc90() == 0)
                        FUN_140a0b300(m_spEffect, 1);
                }
            }
        }
        else
        {
            // a kfm: the instrument is an entity of its own
            egf::EntityIDFactory::GetNextID();
            efd::AssetID kAsset;
            CString strUrn = FUN_140298360("urn:gamebryo-animation:", FUN_141b6ed00(m_spInstrument->m_strAsset));
            FUN_140de0cb0(&kAsset, efd::utf8string((const char*)FUN_1409a2360(strUrn, 0)));
            NiPoint3 kDir = m_pOwner->vfunc_20();
            NiPoint3 kPos = m_pOwner->vfunc_18();
            m_spEntity = FUN_1409670f0()->FUN_1411ce7c0(efd::utf8string(kAsset.GetURN()), efd::utf8string("MS2Actor"),
                PiEfd(kPos), PiEfd(kDir), 1.0f, 0, 0);
            if (m_spEntity != 0)
            {
                efd::utf8string kAnim((const char*)FUN_1409a2360(m_spInstrument->m_strAnimationReady, 0));
                FUN_140ae1240(m_spEntity, 0x3ff293c8, &kAnim);
                if (FUN_140de0900(m_pOwner) == 0)
                {
                    m_bB4 = true;
                    bool bShow = true;
                    FUN_14098c6e0(m_spEntity, 0xa0b6b179, &bShow);
                    if (m_nB0 != 0 && FUN_1409f7c90()->FUN_140ddcc90() == 0)
                    {
                        bool bHide = false;
                        FUN_14098c6e0(m_spEntity, 0xa0b6b179, &bHide);
                    }
                }
                else
                {
                    bool bHide = false;
                    FUN_14098c6e0(m_spEntity, 0xa0b6b179, &bHide);
                }
            }
        }
    }
    if (spItemData->FUN_14053ec50() != 0)
    {
        Unk_PiPC* pPC = static_cast<Unk_PiPC*>(FUN_1417b8370());
        if (pPC != 0)
        {
            MS2Ptr<CItem> spNew(new CItem);
            if (spNew->FUN_140523c40(spItemData->FUN_14053c510(), 1, 0))
            {
                spNew->FUN_140526b30(m_pOwner->FUN_14123c580());
                spNew->FUN_140526a70(FUN_14028d0e0());
                spNew->FUN_14052a130(5);
                pPC->vfunc_127(spNew.get(), 0);
                m_spItem = spNew;
            }
        }
    }
    if (FUN_1417b8560() != 0)
    {
        FUN_140c8dac0()->FUN_140d07130(m_spInstrumentData->FUN_140dde200(), m_spInstrumentData->m_n28);
        m_vPos = PiPoint(m_pOwner->vfunc_18());
    }
    Unk_EffectQuery kQuery;
    kQuery.m_strName = FUN_1401d31f0()->m_str588;
    kQuery.m_nObject = (FUN_1417b8560() == 0) ? 3 : 1;
    kQuery.SetActor(m_pOwner->FUN_14123c580());
    FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    FUN_140de04a0();
    FUN_140ddfc00();
}

// @0x140ddf110
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::vfunc_5(int n)
{
    State::vfunc_5(n);
    AvatarPC* pAvatar = FUN_140de0900(m_pOwner);
    if (pAvatar != 0)
        pAvatar->FUN_1409f5830();
    m_spInstrument = 0;
    if (m_spEffect != 0)
    {
        NiNode* pParent = FUN_140a0b000(m_spEffect);
        if (pParent != 0)
        {
            pParent->DetachChild(m_spEffect);
            m_spEffect = 0;
        }
    }
    if (!m_spItem.IsNull())
    {
        Unk_PiPC* pPC = static_cast<Unk_PiPC*>(FUN_1417b8370());
        if (pPC != 0)
            pPC->vfunc_128(m_spItem.get(), 0);
        m_spItem = 0;
    }
    if (m_spEntity != 0)
    {
        if (m_bB4)
        {
            NiNode* pNode = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(m_spEntity)));
            if (pNode != 0)
            {
                NiNode* pParent = FUN_140a0b000(pNode);
                if (pParent != 0)
                    pParent->DetachChild(pNode);
            }
        }
        FUN_1409670f0()->FUN_1411cf570(m_spEntity);
        m_spEntity = 0;
    }
    FUN_1411a6060(FUN_1403ed280(), m_nEffect68);
    FUN_1411a6060(FUN_1403ed280(), m_nEffect6c);
    m_nEffect68 = 0;
    m_nEffect6c = 0;
    Unk_EffectQuery kQuery;
    kQuery.m_strName = FUN_1401d31f0()->m_str590;
    kQuery.m_nObject = (FUN_1417b8560() == 0) ? 3 : 1;
    kQuery.SetActor(m_pOwner->FUN_14123c580());
    FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    if (FUN_1417b8560() != 0)
        FUN_140c8dac0()->FUN_140d070b0();
}

// @0x140ddf4b0
// MS2-FUNCTIONAL: temporaries differ from the exe
void StatePlayInstrument::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_nB0 != m_pOwner->vfunc_25())
    {
        m_nB0 = m_pOwner->vfunc_25();
        if (!FUN_14087ddc0(m_pOwner ? m_pOwner->GetClassDesc() : 0, 0x6200044))
        {
            if (m_spEffect != 0 && FUN_1409f7c90()->FUN_140ddcc90() == 0)
                FUN_140a0b300(m_spEffect, m_nB0 != 0);
            if (m_spEntity != 0 && FUN_1409f7c90()->FUN_140ddcc90() == 0)
            {
                bool bShow = (m_nB0 == 0);
                FUN_14098c6e0(m_spEntity, 0xa0b6b179, &bShow);
            }
        }
    }
    if (!m_bB4 && m_spEntity != 0 && FUN_14212c720(m_spEntity))
    {
        AvatarPC* pAvatar = FUN_140de0900(m_pOwner);
        if (pAvatar != 0)
        {
            NiAVObject* pRoot = FUN_141b6efc0(m_spEntity);
            if (pRoot != 0)
            {
                FUN_140a38a50(m_spEntity, 0xfd95ca52, &DAT_143b01a60);
                FUN_140a38a50(m_spEntity, 0x68c7c29d, &DAT_143b01a60);
                bool bShow = true;
                FUN_14098c6e0(m_spEntity, 0xa0b6b179, &bShow);
                pAvatar->FUN_1409f5560(static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, pRoot)));
                m_bB4 = true;
            }
        }
    }
    Unk_StreamPoint kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
    if (FUN_1417b8560() != 0)
    {
        if (m_pOwner->vfunc_99(0) == 0)
        {
            Unk_StreamPoint kPos = PiPoint(m_pOwner->vfunc_18());
            if (50.0f < kPos.FUN_140965c40(m_vPos).FUN_140967ac0())
                m_pOwner->vfunc_59(1, 0, 0, 0);
        }
        else
        {
            m_pOwner->vfunc_59(5, 0, 0, 0);
        }
    }
}

// @0x140ddf9e0
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::vfunc_2(int n)
{
    int nOld = m_n10;
    State::vfunc_2(n);
    if (nOld != n)
    {
        m_bA0 = false;
        FUN_140ddfc00();
        if (FUN_1417b8370() != 0 && !m_spInstrument.IsNull())
        {
            m_strLastAnim = m_spInstrument->m_strAnimationReady;
            if (m_n10 == 0x7e || m_n10 == 0x7f || m_n10 == 0x81)
                FUN_140de0780(m_strLastAnim);
            else
                FUN_140de04a0();
        }
    }
}

// @0x140ddfae0
void StatePlayInstrument::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    FUN_140de04a0();
}

// @0x140ddfb10
int StatePlayInstrument::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_nSub)
        return 0;
    return 1;
}

// @0x140ddfbb0
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
int StatePlayInstrument::FUN_140ddfbb0()
{
    if (m_spInstrumentData.get() == 0)
        return 0;
    return m_spInstrumentData->FUN_140dde200();
}

// @0x140ddfc00
// MS2-FUNCTIONAL: the four sub states are written as one table walk
void StatePlayInstrument::FUN_140ddfc00()
{
    if (m_spInstrument.IsNull())
        return;
    FUN_1411a6060(FUN_1403ed280(), m_nEffect68);
    m_nEffect68 = 0;
    bool bExpensive = m_spInstrument->m_bExpensive != 0;
    if (m_n10 != 0x7d)
    {
        Unk_PiStrings* pStr = FUN_1401d31f0();
        const CString* pPlain = 0;
        const CString* pGroup = 0;
        if (m_n10 == 0x7e)
        {
            pPlain = bExpensive ? &pStr->m_str550 : &pStr->m_str518;
            pGroup = bExpensive ? &pStr->m_str570 : &pStr->m_str538;
        }
        else if (m_n10 == 0x7f)
        {
            pPlain = bExpensive ? &pStr->m_str558 : &pStr->m_str520;
            pGroup = bExpensive ? &pStr->m_str578 : &pStr->m_str540;
        }
        else if (m_n10 == 0x80)
        {
            pPlain = bExpensive ? &pStr->m_str560 : &pStr->m_str528;
        }
        else if (m_n10 == 0x81)
        {
            pPlain = bExpensive ? &pStr->m_str568 : &pStr->m_str530;
            pGroup = bExpensive ? &pStr->m_str580 : &pStr->m_str548;
        }
        if (pPlain != 0)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = *pPlain;
            kQuery.m_nObject = (FUN_1417b8560() == 0) ? 3 : 1;
            kQuery.SetActor(FUN_1417b8370()->FUN_14123c580());
            if (pGroup != 0)
            {
                CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880(FUN_1417b8370()->FUN_141656a80());
                if (spBuddy.get() != 0 && spBuddy->FUN_1401cc5b0() != 0)
                    kQuery.m_strName = *pGroup;
            }
            m_nEffect68 = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
        }
    }
    FUN_1411a6060(FUN_1403ed280(), m_nEffect6c);
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
        kQuery.m_nObject = (FUN_1417b8560() == 0) ? 3 : 1;
        kQuery.SetActor(FUN_1417b8370()->FUN_14123c580());
        m_nEffect6c = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
    }
}

// @0x140de0410
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::FUN_140de0410(int nLevel)
{
    if (!m_spInstrument.IsNull() && FUN_1417b8370() != 0)
    {
        m_bA0 = true;
        if (m_n10 == 0x7e || m_n10 == 0x7f || m_n10 == 0x81)
            FUN_140de05a0(nLevel);
    }
}

// @0x140de04a0
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::FUN_140de04a0()
{
    if (m_spInstrument.IsNull())
        return;
    if (FUN_1417b8370() == 0)
        return;
    if (m_n10 == 0x7d || m_n10 == 0x80)
    {
        FUN_140de0780(m_spInstrument->m_strAnimationReady);
    }
    else if (m_n10 == 0x7e || m_n10 == 0x7f || m_n10 == 0x81)
    {
        if (!m_bA0)
            FUN_140de05a0(FUN_140768010(10, 1));
        else
            FUN_140de0780(m_strLastAnim);
    }
}

// @0x140de05a0
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::FUN_140de05a0(int nLevel)
{
    if (m_spInstrument.IsNull())
        return;
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    CString strAnim = m_spInstrument->m_strAnimationPlayIdle;
    int nPeers = FUN_1416627d0(pPC, 2);
    if (nLevel == 0)
    {
        FUN_140de0780(m_spInstrument->m_strAnimationReady);
        return;
    }
    if (nLevel == 1)
        strAnim = m_spInstrument->m_strAnimationPlayIdle;
    else if (nLevel == 2)
        strAnim = m_spInstrument->m_strAnimationPlayLevel1;
    else if (nLevel == 3 && 1 < nPeers)
        strAnim = m_spInstrument->m_strAnimationPlayLevel2;
    else if (nLevel == 4 && 2 < nPeers)
        strAnim = m_spInstrument->m_strAnimationPlayLevel3;
    else if (nLevel == 5 && 3 < nPeers)
        strAnim = m_spInstrument->m_strAnimationPlayLevel4;
    FUN_140de0780(strAnim);
}

// @0x140de0780
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer / string accessors that the source spells inline
void StatePlayInstrument::FUN_140de0780(const CString& strAnim)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    efd::utf8string kAnim((const char*)FUN_1409a2360(strAnim, 0));
    m_pOwner->FUN_14166dd20(kAnim, FUN_14165eb80(pPC), false, false);
    m_strLastAnim = strAnim;
    if (m_spEntity != 0)
        FUN_1409a1fc0(FUN_141b6f910(), FUN_1408b76f0(m_spEntity), &kAnim, FUN_14165eb80(pPC), 0);
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
