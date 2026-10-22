// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See effectobject.h.
// MS2-UNIT: ?\effectobject.cpp
// MS2-RANGE: 0x140a53740-0x140a54160 .text$mn
// MS2-RANGE: 0x1400c3eb0-0x1400c4040 .text$di
// MS2-RANGE: 0x142c9f460-0x142c9f4f0 .text$yd
// MS2-PIN: ?GetClassDesc@CEffectObject@@UEBAPEBVClassInfo@efd@@XZ 0x140a53f70
// MS2-PIN: ?TypeCast@CEffectObject@@UEBA_NIPEAPEAX@Z 0x140a54010
// MS2-PIN: ?TypeCast@CEffectObject@@UEBA_NIPEAPEBX@Z 0x140a54060
// MS2-PIN: ??_7CEffectObject@@6BIBase@efd@@@ 0x142dc86f0
// MS2-PIN: ??_7CEffectObject@@6BCallbackObject@NiActorManager@@@ 0x142dc88c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "effectobject.h"
#include "animationmanager.h"
#include "pcbase.h"
#include <NiActorManager.h>
#include <NiControllerSequence.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- out-of-unit callees (names of the Unk_ types are invented) ----

class WorldService;
WorldService* FUN_1403ed2d0();                                      // TSingleton<WorldService>::GetInstance
GameObject* FUN_141bd1180(WorldService* pWorld, int nId);           // game object by id
PCBase* FUN_141bd1290(WorldService* pWorld, int nId);               // actor by id
void FUN_141663b70(PCBase* pActor, int nEffectId);                  // PCBase: add to its effect list (+0x1210)
void FUN_141663bb0(PCBase* pActor, int nEffectId);                  // PCBase: remove from its effect list
int FUN_14166c930(PCBase* pActor);                                  // actor kind (0x10 = player character)

// Target of a state (MS2Ptr, the pointer is a CPtred); its +0x30 member holds a descriptor with a kind at +0x88.
struct Unk_EffDesc
{
    int m_pad_00[34];
    int m_nKind;                                                    // +0x88
};
struct Unk_EffDescHolder
{
    void* m_p;
};
class Unk_EffTarget : public CPtred
{
public:
    MS2_LAYOUT_FRIEND;
    void* m_pad_18[3];
    Unk_EffDescHolder m_f30;                                        // +0x30
};
// The state machine's current state.
class Unk_EffState
{
public:
    MS2Ptr<Unk_EffTarget> FUN_1417ed6f0();                          // the state's target
    float FUN_1417e9380();                                          // the state's animation speed
};
Unk_EffState* FUN_1417db1c0(CStateManager* pMgr);                   // current state
Unk_EffDesc* FUN_14063ed50(Unk_EffDescHolder* pHolder);                          // descriptor of a holder
// MS2Ptr<Unk_EffTarget> members instantiated by earlier objs.
template <> Unk_EffTarget* MS2Ptr<Unk_EffTarget>::get() const;       // 0x140975ba0
template <> MS2Ptr<Unk_EffTarget>::~MS2Ptr();                        // 0x140975740

// MS2Ptr<CStateManager> members instantiated by cubespawnobject.cpp.
template <> MS2Ptr<CStateManager>::operator CStateManager*() const;  // 0x140a4ff20
template <> MS2Ptr<CStateManager>::~MS2Ptr();                        // 0x140a4fcd0

CString FUN_141b6ed00(const CString& str);                          // normalised copy of a model name
CString FUN_140298360(const char* pszPrefix, const CString& str);   // prefix + str

NiActorManager* FUN_140999440(void* pCache, const Unk_GoModelKey& kKey);   // cached actor manager (NULL if none)
void* FUN_141b6f910();                                              // the model cache singleton
const char* FUN_142087e50(const NiFixedString& kName);              // NiFixedString::operator const char*
void FUN_1409a20a0(NiActorManager* pMgr, unsigned int uiSeqId, float fSpeed, bool bFlag);   // start the sequence
void* FUN_14086d260();                                              // the game clock
double FUN_141473280(void* pClock);                                 // seconds
float FUN_141b6fe90(NiControllerSequence* pSeq, const NiFixedString& kKey, float fDefault);   // text key time
void FUN_1409a1f60(NiControllerSequence* pSeq, float fTime);        // seek the sequence

// The exe's NiActorManager has a virtual Update(float) at slot 4 that the SDK header lacks (slots 0-3 not proven).
// MS2: slot 4
struct Unk_ActorManagerVt
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void Update(float fTime);
};

// NiControllerSequence members read through protected access.
struct Unk_SeqAccess : public NiControllerSequence
{
    // @0x140a53f80
    static float FUN_140a53f80(NiControllerSequence* p) { return static_cast<Unk_SeqAccess*>(p)->m_fFrequency; }
    // @0x140a53fa0
    static float FUN_140a53fa0(NiControllerSequence* p) { return static_cast<Unk_SeqAccess*>(p)->m_fOffset; }
};

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CEffectObject);

// ---- the unit's header statics ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140a53740
CEffectObject::CEffectObject()
    : m_nOwnerId(0)
{
}

// @0x140a537a0
CEffectObject::~CEffectObject()
{
    PCBase* pOwner = FUN_141bd1290(FUN_1403ed2d0(), m_nOwnerId);
    if (pOwner)
        FUN_141663bb0(pOwner, FUN_14123c580());
}

// @0x140a53830
static unsigned int FUN_140a53830()
{
    for (unsigned int nId = 0x4bf; nId < 0x8a7; nId++)
    {
        if (FUN_141bd1180(FUN_1403ed2d0(), nId) == 0)
            return nId;
    }
    return 0x4bf;
}

// @0x140a53880
int CEffectObject::FUN_140a53880(int nOwnerId, CString strModel, float fScale)
{
    m_nOwnerId = nOwnerId;
    m_str88 = "GameObject";
    SetScaleAC(fScale);
    FUN_14123bb80(FUN_140298360("urn:gamebryo-animation:", FUN_141b6ed00(strModel)));
    FUN_14123c5a0(FUN_140a53830());
    PCBase* pOwner = FUN_141bd1290(FUN_1403ed2d0(), m_nOwnerId);
    if (pOwner)
        FUN_141663b70(pOwner, FUN_14123c580());
    return 1;
}
MS2_REPLACE_METHOD(0x140a53880, CEffectObject, FUN_140a53880, 322, 0x61463D26);

// @0x140a539d0
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (no source form found); everything else matches
void CEffectObject::FUN_140a539d0(const NiFixedString& kSeqName, float fSpeed, const NiFixedString& kTextKey)
{
    Unk_GoModelKey kKey;
    NiActorManager* pMgr = FUN_140999440(FUN_141b6f910(), FUN_14123c460(kKey));
    if (pMgr != NULL)
    {
        unsigned int uiSeqId = pMgr->FindSequenceID(FUN_142087e50(kSeqName));
        if (uiSeqId == NiActorManager::INVALID_SEQUENCE_ID)
            return;
        {
            FUN_1409a20a0(pMgr, uiSeqId, fSpeed, true);
            reinterpret_cast<Unk_ActorManagerVt*>(pMgr)->Update((float)FUN_141473280(FUN_14086d260()));
            NiControllerSequence* pSeq = pMgr->GetActiveSequence(uiSeqId, true, true);
            if (pSeq != NULL)
            {
                float fKeyTime = FUN_141b6fe90(pSeq, kTextKey, 1.0f);
                float fOffset = Unk_SeqAccess::FUN_140a53fa0(pSeq);
                float fTarget = fOffset + fKeyTime * (1.0f / Unk_SeqAccess::FUN_140a53f80(pSeq));
                FUN_1409a1f60(pSeq, fTarget);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a539d0, CEffectObject, FUN_140a539d0, 342, 0x3E7C4CC0);

// @0x140a53b30
void CEffectObject::FUN_140a53b30(efd::Point3 kDir)
{
    GameObject::vfunc_21(kDir);
}
MS2_REPLACE_METHOD(0x140a53b30, CEffectObject, FUN_140a53b30, 58, 0xC5BD7AF6);

// @0x140a53b70
void CEffectObject::vfunc_21(efd::Point3 kDir)
{
    if (vfunc_20() != kDir)
    {
        PCBase* pOwner = FUN_141bd1290(FUN_1403ed2d0(), m_nOwnerId);
        if (pOwner && FUN_14166c930(pOwner) == 0x10)
        {
            Unk_EffState* pState = FUN_1417db1c0(pOwner->FUN_141678750());
            if (pState)
            {
                Unk_EffTarget* pTarget = pState->FUN_1417ed6f0().get();
                if (pTarget && FUN_14063ed50(&pTarget->m_f30)->m_nKind == 2)
                    return;
            }
        }
    }
    GameObject::vfunc_21(kDir);
}
MS2_REPLACE_METHOD(0x140a53b70, CEffectObject, vfunc_21, 370, 0xD8112247);

// @0x140a53cf0
void CEffectObject::vfunc_12()
{
    GameObject::vfunc_12();
    FUN_14123c280(m_fScaleA4);
}
MS2_REPLACE_METHOD(0x140a53cf0, CEffectObject, vfunc_12, 47, 0xE746E346);

// @0x140a53d30
void CEffectObject::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    if (m_nOwnerId != 0)
    {
        PCBase* pOwner = FUN_141bd1290(FUN_1403ed2d0(), m_nOwnerId);
        if (pOwner)
        {
            float fScale = 1.0f;
            if (FUN_14166c930(pOwner) == 0x10)
            {
                Unk_EffState* pState = FUN_1417db1c0(pOwner->FUN_141678750());
                if (pState)
                    fScale = pState->FUN_1417e9380();
            }
            GetAnimMgr()->FUN_14099e050(pOwner->GetAnimMgr()->FUN_140a53f90(), fScale, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x140a53d30, CEffectObject, vfunc_53, 393, 0x2F2D04F2);
