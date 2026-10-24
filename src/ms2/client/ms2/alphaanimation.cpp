// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Alpha animation of entity scene graphs (see alphaanimation.h).
// MS2-UNIT: ?\alphaanimation.cpp
// MS2-RANGE: 0x1400bfd30-0x1400bfd47 .text$di
// MS2-RANGE: 0x14098a990-0x14098eb30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1CNode@?$CAtlList@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAA@XZ 0x14098cde0 ; unique
// MS2-PIN: ??1NiAlphaController@@UEAA@XZ 0x14098cdf0 ; prop
// MS2-PIN: ??1NiFloatExtraData@@UEAA@XZ 0x14098ce20 ; prop
// MS2-PIN: ??1NiFloatKey@@QEAA@XZ 0x14098ce70 ; prop
// MS2-PIN: ??1NiIntegerExtraData@@UEAA@XZ 0x14098ce90 ; prop
// MS2-PIN: ??B?$SmartPointer@VUnk_HwService@@@efd@@QEBAPEAVUnk_HwService@@XZ 0x14098d090 ; unique
// MS2-PIN: ??_GNiFloatExtraData@@UEAAPEAXI@Z 0x14098d520 ; prop
// MS2-PIN: ?DetachProperty@NiAVObject@@QEAAXPEAVNiProperty@@@Z 0x14098d760 ; unique
// MS2-PIN: ?IsNull@?$Delegate@$$A6AMM@Z@@QEBA_NXZ 0x14098d900 ; unique
// MS2-PIN: ?GetAlphaBlending@NiAlphaProperty@@QEBA_NXZ 0x14098dab0 ; prop
// MS2-PIN: ?GetAppCulled@NiAVObject@@QEBA_NXZ 0x14098dad0 ; prop
// MS2-PIN: ?GetRTTI@NiAlphaController@@UEBAPEBVNiRTTI@@XZ 0x14098de60 ; unique
// MS2-PIN: ?GetRTTI@NiFloatData@@UEBAPEBVNiRTTI@@XZ 0x14098de70 ; unique
// MS2-PIN: ?GetRTTI@NiFloatExtraData@@UEBAPEBVNiRTTI@@XZ 0x14098de80 ; unique
// MS2-PIN: ?Reset@?$TLinearInterpolator@M@@UEAAXXZ 0x14098dee0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1AlphaTourController@@UEAA@XZ 0x14098cda0
// MS2-PIN: ??1CEntityHider@@UEAA@XZ 0x14098cdc0
// MS2-PIN: ??B?$SmartPointer@VNiFloatData@@@efd@@QEBAPEAVNiFloatData@@XZ 0x14098d0a0
// MS2-PIN: ??C?$SmartPointer@VUnk_HwService@@@efd@@QEBAPEAVUnk_HwService@@XZ 0x14098d0e0
// MS2-PIN: ??0?$SmartPointer@VUnk_HwService@@@efd@@QEAA@PEAVUnk_HwService@@@Z 0x14098c7d0
// MS2-PIN: ??1?$SmartPointer@VUnk_HwService@@@efd@@QEAA@XZ 0x14098cc60
// MS2-PIN: ??1?$SmartPointer@VNiFloatData@@@efd@@QEAA@XZ 0x14098cca0
// MS2-PIN: ??0?$SmartPointer@VNiFloatData@@@efd@@QEAA@PEAVNiFloatData@@@Z 0x14098c820
// MS2-PIN: ?Get@?$TLinearInterpolator@M@@UEAAMM@Z 0x14098ea40
// MS2-PIN: ?SetPhase@NiTimeController@@QEAAXM@Z 0x14098e9e0
// MS2-PIN: ?SetTime@NiAnimationKey@@QEAAXM@Z 0x14098ea00
// MS2-PIN: ?SetValue@NiFloatKey@@QEAAXM@Z 0x14098ea20
// MS2-PIN: ??1NiAnimationKey@@QEAA@XZ 0x14098ce10
// MS2-PIN: ??1NiLinFloatKey@@QEAA@XZ 0x14098cee0
// MS2-PIN: ??_ENiLinFloatKey@@QEAAPEAXI@Z 0x14098d180
// MS2-PIN: ?IsEmpty@?$CAtlList@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEBA_NXZ 0x14098df00
// MS2-FUNCTIONAL: ATL CAtlList node layout of the SDK header differs from the exe
// MS2-PIN: ?RemoveHead@?$CAtlList@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAAPEAVNiAVObject@@XZ 0x14098e5c0
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\alphaanimation.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "alphaanimation.h"
#include <NiAlphaProperty.h>
#include <NiMaterialProperty.h>
#include <NiFloatData.h>
#include <NiFloatInterpolator.h>
#include <NiLinFloatKey.h>
#include <NiFloatExtraData.h>
#include <NiIntegerExtraData.h>
#include <NiNode.h>
#include <NiRTTI.h>
#include <efd/ServiceManager.h>
#include <efd/ISystemService.h>
#include <egf/Entity.h>
#include "entityworldmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ----

// @0x1400bfd30
static egf::EntityID s_nullEntityId(0ull);

// ---- unit-local views of exe objects ----

class Unk_GameClock;
Unk_GameClock* FUN_14086d260();                 // the application (global DAT_143ab1fa8)
double FUN_141473280(Unk_GameClock*);           // current time (ServiceManager::GetTime(0xe001001b))
double FUN_141473260(Unk_GameClock*);           // frame delta

struct Unk_EntityAppFramework                   // the framework
{
    efd::ServiceManagerPtr manager;
};
extern Unk_EntityAppFramework DAT_143b059e8;

// The service 0x0610000c: owns the running CAlphaAnimation objects.
class Unk_AlphaService : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x0610000c;
    void FUN_1411a6ea0(CAlphaAnimation* pAnim);
};

// The per-entity tracker of the hardware instancing service (0x30+ bytes; +0x2a = visible flag).
struct Unk_InstanceTracker
{
    // @0x14098dfe0
    bool FUN_14098dfe0() const { return m_visible; }

    char m_pad_00[0x2a];
    bool m_visible;
};
MS2_CHECK_OFFSET(Unk_InstanceTracker, m_visible, 0x2a);

// The service 0x06100009 (hardware instancing).
class Unk_HwService : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100009;
    Unk_InstanceTracker* FUN_1413d66b0(egf::Entity* pEntity);
    int FUN_1413d6e60(egf::Entity* pEntity, bool bFlag);
};

class Unk_ActorSlots                            // player/actor object reached from the game context (slot 39 = 0x138)
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38();
    virtual void vfunc_39();                    // 0x138
};
void* FUN_1403ed2d0();                          // game context
Unk_ActorSlots* FUN_141bd0fa0(void* pContext, egf::EntityID id);

EntityWorldManager* FUN_1409670f0();
unsigned FUN_1408a2010();                       // property type id of bool
void FUN_1408a20a0(egf::Entity*, unsigned, bool*);      // Entity::GetPropertyValue<bool>

// The property cache of a client entity (egf::Entity subclass: +0xc8 caching enabled, +0xd0 map property id -> entry).
// Same view as bosstargetcamera.cpp.
struct Unk_PropertyCacheEntry
{
    Unk_PropertyCacheEntry(unsigned nId, void* pValue, unsigned nType) : m_id(nId), m_pValue(pValue), m_type(nType) {}

    unsigned m_id;
    void* m_pValue;
    unsigned m_type;
};
MS2_CHECK_SIZE(Unk_PropertyCacheEntry, 0x18);

class Unk_PropertyCacheIter
{
public:
    Unk_PropertyCacheIter();
    bool FUN_140947540(const Unk_PropertyCacheIter& other) const;     // operator==

    void* m_p;
};

class Unk_PropertyCacheMap
{
public:
    Unk_PropertyCacheIter FUN_1409481f0();                          // end()
    Unk_PropertyCacheIter FUN_140948250(const unsigned& nId);       // find
    Unk_PropertyCacheEntry& FUN_140947580(const unsigned& nId);     // operator[]

    void* m_pHead;                                                  // std::map: head node and size
    size_t m_nSize;
};

class Unk_CachedEntity : public egf::Entity
{
public:
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;

    bool m_c8;
    Unk_PropertyCacheMap m_d0;
};
MS2_CHECK_OFFSET(Unk_CachedEntity, m_c8, 0xc8);
MS2_CHECK_OFFSET(Unk_CachedEntity, m_d0, 0xd0);

// Breadth-first queue of scene-graph nodes (0x30 bytes).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);
    ~Unk_NodeQueue();
    NiAVObject* Next(bool bAddChildren);            // pops the head; with bAddChildren the node's children are queued
    void SetRoot(NiAVObject* pkRoot);
    void AddChildren(NiNode* pkNode);

private:
    ATL::CAtlList<NiAVObject*> m_list;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);

extern NiFixedString DAT_143ae50a8;             // extra data keys of the original material/alpha state
extern NiFixedString DAT_143ae50b8;
extern NiFixedString DAT_143ae50c0;

void FUN_14098b3e0(NiAVObject* pkObject, float fAlpha, char bForce);
void FUN_14098c120(NiAVObject* pkObject);
bool FUN_14098c620(NiAVObject* pkObject);
bool FUN_14098c680(NiProperty* pkProperty);
Unk_AlphaService* FUN_14098c540(Unk_EntityAppFramework* pFramework);
Unk_HwService* FUN_14098c5b0(Unk_EntityAppFramework* pFramework);
void FUN_14098c6e0(Unk_CachedEntity* pEntity, unsigned nId, const bool& bValue);

// ---------------------------------------------------------------------------------------------------------------------

// @0x14098a990
bool AlphaTourController::InterpTargetIsCorrectType(NiObjectNET* pkTarget) const
{
    return NiIsKindOf(NiAVObject, pkTarget);
}

// @0x14098a9c0
bool AlphaTourController::UpdateValue(float fTime, float fFloat, unsigned short usIndex)
{
    FUN_14098b3e0((NiAVObject*)m_pkTarget, fFloat, 0);
    return true;
}

// @0x14098aa00
void AlphaTourController::Update(float fTime)
{
    if (GetManagerControlled())
        return;

    if (DontDoUpdate(fTime) && (!m_spInterpolator || !m_spInterpolator->AlwaysUpdate()))
        return;

    if (m_spInterpolator)
    {
        float fValue;
        if (m_spInterpolator->Update(m_fScaledTime, m_pkTarget, fValue))
            FUN_14098b3e0((NiAVObject*)m_pkTarget, fValue, 0);
    }
}

// MS2-FUNCTIONAL: extra temporary for the target property pointer is not reproduced
// @0x14098ab10
void AlphaTourController::GetTargetFloatValue(float& fValue)
{
    fValue = ((NiMaterialProperty*)((NiAVObject*)m_pkTarget)->GetProperty(NiProperty::MATERIAL))->GetAlpha();
}

struct Unk_AlphaKey
{
    float fDelta;
    float fAlpha;
};
MS2_CHECK_SIZE(Unk_AlphaKey, 8);
void FUN_14098ea00(NiFloatKey* pKey, float fTime);

// Starts an alpha animation of pkObject through the (time delta, alpha) keys; idOwner is notified when it ends.
// MS2-FUNCTIONAL: array-new / operator[] shape of the key copy differs
// @0x14098ab60
void FUN_14098ab60(NiAVObject* pkObject, ATL::CAtlArray<Unk_AlphaKey>& keys, const egf::EntityID& idOwner)
{
    if (pkObject == NULL)
        return;
    if (FUN_14098c620(pkObject))
        return;

    unsigned nKeys = (unsigned)keys.GetCount();
    float fTotal = 0.0f;
    for (unsigned i = 0; i < nKeys; i++)
        fTotal = fTotal + keys[i].fDelta;

    float fNow = (float)FUN_141473280(FUN_14086d260());
    CAlphaAnimation* pAnim = EE_NEW CAlphaAnimation(pkObject, fNow + fTotal);
    if (idOwner != s_nullEntityId)
        pAnim->m_idOwner = idOwner;

    NiFloatDataPtr spData = EE_NEW NiFloatData;
    NiLinFloatKey* pKeys = EE_NEW NiLinFloatKey[nKeys];
    float fTime = 0.0f;
    for (unsigned i = 0; i < nKeys; i++)
    {
        fTime = fTime + keys[i].fDelta;
        pKeys[i].SetTime(fTime);
        pKeys[i].SetValue(keys[i].fAlpha);
    }
    spData->SetAnim(pKeys, nKeys, NiAnimationKey::LINKEY);

    AlphaTourController* pCtrl = EE_NEW AlphaTourController;
    NiFloatInterpolator* pInterp = EE_NEW NiFloatInterpolator(spData);
    pCtrl->SetInterpolator(pInterp, 0);
    pCtrl->SetTarget(pkObject);
    pCtrl->ResetTimeExtrema();
    pAnim->m_spController = pCtrl;
    pCtrl->SetAnimType(NiTimeController::APP_INIT);
    pCtrl->Start(-NI_INFINITY);
    pCtrl->SetPhase(0.0f);

    Unk_AlphaService* pService = FUN_14098c540(&DAT_143b059e8);
    if (pService)
        pService->FUN_1411a6ea0(pAnim);
    pkObject->Update(fNow, true);
}

// ---- CAlphaAnimation ----

// @0x14098b110
bool CAlphaAnimation::vfunc_2()
{
    float fNow = (float)FUN_141473280(FUN_14086d260());
    if (fNow > m_fEndTime)
    {

        if (m_idOwner != s_nullEntityId)
        {
            Unk_ActorSlots* pActor = FUN_141bd0fa0(FUN_1403ed2d0(), m_idOwner);
            if (pActor)
                pActor->vfunc_39();
        }
        return false;
    }
    return true;
}

// @0x14098b1d0
CAlphaAnimation::CAlphaAnimation(NiAVObject* pkTarget, float fEndTime)
    : m_fEndTime(fEndTime)
    , m_spTarget(pkTarget)
    , m_spController(0)
    , m_idOwner(s_nullEntityId)
{
}

// @0x14098b270
CAlphaAnimation::~CAlphaAnimation()
{
    if (m_spTarget && FUN_14086d260())
        m_spTarget->Update((float)FUN_141473280(FUN_14086d260()), true);

    if (m_spController)
    {
        if (m_spController->GetRefCount() > 1)
            m_spController->SetTarget(0);
    }

    if (m_spTarget)
        m_spTarget->UpdateProperties();
}

// ---- helpers of the node-tree alpha application ----

// Starts at the root; nodes are visited breadth first.
// @0x14098cb80
Unk_NodeQueue::Unk_NodeQueue(NiAVObject* pkRoot)
{
    SetRoot(pkRoot);
}

// @0x14098cf00
Unk_NodeQueue::~Unk_NodeQueue()
{
}

// @0x14098e7d0
void Unk_NodeQueue::SetRoot(NiAVObject* pkRoot)
{
    m_list.RemoveAll();
    m_list.AddTail(pkRoot);
}

// @0x14098d6d0
void Unk_NodeQueue::AddChildren(NiNode* pkNode)
{
    int nCount = pkNode->GetArrayCount();
    for (int i = 0; i < nCount; i++)
    {
        NiAVObject* pkChild = pkNode->GetAt(i);
        if (pkChild)
            m_list.AddTail(pkChild);
    }
}

// @0x14098e0d0
NiAVObject* Unk_NodeQueue::Next(bool bAddChildren)
{
    if (m_list.IsEmpty())
        return NULL;

    NiAVObject* pkNode = m_list.RemoveHead();
    if (bAddChildren)
    {
        NiNode* pkParent = NiDynamicCast(NiNode, pkNode);
        if (pkParent)
            AddChildren(pkParent);
    }
    return pkNode;
}

// Is the object flagged 0x400 (excluded from the alpha fade)?
// @0x14098dfc0
bool FUN_14098dfc0(NiAVObject* pkObject)
{
    return pkObject->MS2HasAnyFlag(0x400);
}

// Does a controller of the node already drive its alpha?
// @0x14098c620
bool FUN_14098c620(NiAVObject* pkObject)
{
    NiTimeController* pkCtrl = pkObject->GetControllers();
    while (pkCtrl)
    {
        if (NiDynamicCast(NiAlphaController, pkCtrl))
            return true;
        pkCtrl = pkCtrl->GetNext();
    }
    return false;
}

// @0x14098c680
bool FUN_14098c680(NiProperty* pkProperty)
{
    NiTimeController* pkCtrl = pkProperty->GetControllers();
    while (pkCtrl)
    {
        if (NiDynamicCast(NiAlphaController, pkCtrl))
            return true;
        pkCtrl = pkCtrl->GetNext();
    }
    return false;
}

// Makes sure that the node has a material and an alpha property, each remembering the original state.
// MS2-FUNCTIONAL: temporaries differ; same calls and control flow
// @0x14098c120
void FUN_14098c120(NiAVObject* pkObject)
{
    if (pkObject->GetProperty(NiProperty::MATERIAL) == NULL)
    {
        NiMaterialProperty* pkMaterial = NiNew NiMaterialProperty;
        NiFloatExtraData* pkOriginal = NiNew NiFloatExtraData(-1.0f);
        pkMaterial->AddExtraData(DAT_143ae50b8, pkOriginal);
        pkObject->AttachProperty(pkMaterial);
    }

    if (pkObject->GetProperty(NiProperty::ALPHA) == NULL)
    {
        NiAlphaProperty* pkAlpha = NiNew NiAlphaProperty;
        NiIntegerExtraData* pkOriginal = NiNew NiIntegerExtraData(-1);
        pkAlpha->AddExtraData(DAT_143ae50c0, pkOriginal);
        pkObject->AttachProperty(pkAlpha);
    }
}

// @0x14098c360
static void FUN_14098c360(Unk_CachedEntity* pEntity, unsigned nId, const bool& bNew)
{
    if (pEntity->m_c8)
    {
        if (pEntity->m_d0.FUN_140948250(nId).FUN_140947540(pEntity->m_d0.FUN_1409481f0()))
        {
            bool bOld;
            pEntity->GetPropertyValueUnsafe(nId, &bOld, FUN_1408a2010());
            pEntity->m_d0.FUN_140947580(nId) = Unk_PropertyCacheEntry(nId, new bool(bOld), FUN_1408a2010());
        }
    }
}

// @0x14098c6e0
void FUN_14098c6e0(Unk_CachedEntity* pEntity, unsigned nId, const bool& bValue)
{
    FUN_14098c360(pEntity, nId, bValue);
    pEntity->SetPropertyValueUnsafe(nId, (void*)&bValue, FUN_1408a2010());
}

// @0x14098c540
Unk_AlphaService* FUN_14098c540(Unk_EntityAppFramework* pFramework)
{
    return pFramework->manager->GetSystemServiceAs<Unk_AlphaService>();
}

// @0x14098c5b0
Unk_HwService* FUN_14098c5b0(Unk_EntityAppFramework* pFramework)
{
    return pFramework->manager->GetSystemServiceAs<Unk_HwService>();
}

// Applies fAlpha to the material/alpha properties of the object and its descendants (bForce also touches culled nodes).
// MS2-FUNCTIONAL: property walk temporaries differ; same calls and control flow
// @0x14098b3e0
void FUN_14098b3e0(NiAVObject* pkObject, float fAlpha, char bForce)
{
    if (pkObject == NULL)
        return;

    FUN_14098c120(pkObject);
    Unk_NodeQueue kQueue(pkObject);
    for (;;)
    {
        NiAVObject* pkNode = kQueue.Next(true);
        if (pkNode == NULL)
            break;

        if (FUN_14098dfc0(pkNode))
            continue;
        if (!bForce && pkNode->GetAppCulled())
            continue;

        NiMaterialProperty* pkMaterial = (NiMaterialProperty*)pkNode->GetProperty(NiProperty::MATERIAL);
        if (pkMaterial)
        {
            if (FUN_14098c680(pkMaterial))
                continue;

            NiFloatExtraData* pkOriginal = NiDynamicCast(NiFloatExtraData, pkMaterial->GetExtraData(DAT_143ae50b8));
            if (pkOriginal == NULL)
            {
                pkOriginal = NiNew NiFloatExtraData(pkMaterial->GetAlpha());
                pkMaterial->AddExtraData(DAT_143ae50b8, pkOriginal);
            }
            float fOriginal = pkOriginal->GetValue();
            if (fAlpha < 1.0f || 0.0f <= fOriginal)
                pkMaterial->SetAlpha(fOriginal * fAlpha);
            else
                pkNode->DetachProperty(pkMaterial);
        }

        NiAlphaProperty* pkAlphaProp = (NiAlphaProperty*)pkNode->GetProperty(NiProperty::ALPHA);
        if (pkAlphaProp)
        {
            NiIntegerExtraData* pkOriginal = NiDynamicCast(NiIntegerExtraData, pkAlphaProp->GetExtraData(DAT_143ae50c0));
            if (pkOriginal == NULL)
            {
                pkOriginal = NiNew NiIntegerExtraData(pkAlphaProp->GetAlphaBlending());
                pkAlphaProp->AddExtraData(DAT_143ae50c0, pkOriginal);
            }
            if (fAlpha < 1.0f)
            {
                pkAlphaProp->SetAlphaBlending(true);
            }
            else
            {
                pkNode->RemoveExtraData(DAT_143ae50a8);
                int iOriginal = pkOriginal->GetValue();
                if (iOriginal < 0)
                    pkNode->DetachProperty(pkAlphaProp);
                else
                    pkAlphaProp->SetAlphaBlending(iOriginal == 1);
            }
        }
    }
    pkObject->UpdateProperties();
}

// ---- Delegate<float(float)> (the filter of the interpolators) ----

// @0x14098cd00
template <> Delegate<float(float)>::~Delegate()
{
    Reset();
}

// @0x14098d120
template <> float Delegate<float(float)>::operator()(float fValue) const
{
    return m_pImpl->vfunc_2(fValue);
}

// @0x14098e760
template <> void Delegate<float(float)>::Reset()
{
    if (m_pImpl)
    {
        delete m_pImpl;
        m_pImpl = 0;
    }
}

// ---- CEntityShower / CEntityHider ----

// MS2-FUNCTIONAL: initialization temporaries differ; same calls and control flow
// @0x14098b7a0
CEntityShower::CEntityShower(egf::EntityID idEntity, NiAVObject* pkNode, float fFrom, float fTo, float fDuration)
    : m_bWasShown(false), m_fAlpha(1.0f), m_pInterpolator(0)
    , m_fEndTime(0.0f), m_spNode(pkNode), m_idEntity(idEntity)
{
    efd::SmartPointer<egf::Entity> spEntity(FUN_1409670f0()->FUN_1411cf440(idEntity));
    if (spEntity)
    {
        efd::SmartPointer<Unk_HwService> spService(FUN_14098c5b0(&DAT_143b059e8));
        if (spService)
        {
            Unk_InstanceTracker* pTracker = spService->FUN_1413d66b0(spEntity);
            if (pTracker == 0)
            {
                FUN_1408a20a0(spEntity.data(), 0x2a7fd9f4, &m_bWasShown);
            }
            else
            {
                m_bWasShown = pTracker->FUN_14098dfe0();
                FUN_14098c6e0((Unk_CachedEntity*)spEntity.data(), 0x2a7fd9f4, m_bWasShown);
            }
        }
    }

    if (pkNode != 0)
    {
        m_fEndTime = (float)FUN_141473280(FUN_14086d260()) + fDuration;
        m_fAlpha = fFrom;
        m_pInterpolator = new TLinearInterpolator<float>(fDuration, fFrom, fTo);
        m_pInterpolator->Reset();
    }
}

// MS2-FUNCTIONAL: smart-pointer release temporaries differ; same behaviour
// @0x14098ba80
CEntityShower::~CEntityShower()
{
    if (!m_bWasShown)
    {
        efd::SmartPointer<egf::Entity> spEntity(FUN_1409670f0()->FUN_1411cf440(m_idEntity));
        efd::SmartPointer<Unk_HwService> spService(FUN_14098c5b0(&DAT_143b059e8));
        if (spService && spEntity)
        {
            if (spService->FUN_1413d66b0(spEntity))
            {
                bool bFalse = false;
                FUN_14098c6e0((Unk_CachedEntity*)spEntity.data(), 0x2a7fd9f4, bFalse);
            }
        }
    }

    if (m_pInterpolator)
    {
        delete m_pInterpolator;
        m_pInterpolator = 0;
    }
}

// MS2-FUNCTIONAL: temporaries differ; same calls and control flow
// @0x14098bc60
bool CEntityShower::vfunc_2()
{
    float fNow = (float)FUN_141473280(FUN_14086d260());
    if (fNow <= m_fEndTime)
    {
        if (m_pInterpolator)
        {
            m_fAlpha = m_pInterpolator->Get((float)FUN_141473260(FUN_14086d260()));
            FUN_14098b3e0(m_spNode, m_fAlpha, 0);
        }
        return true;
    }

    bool bAlive;
    efd::SmartPointer<egf::Entity> spEntity(FUN_1409670f0()->FUN_1411cf440(m_idEntity));
    if (spEntity)
    {
        efd::SmartPointer<Unk_HwService> spService(FUN_14098c5b0(&DAT_143b059e8));
        if (spService)
        {
            m_fAlpha = m_pInterpolator->Get((float)FUN_141473260(FUN_14086d260()));
            FUN_14098b3e0(m_spNode, m_fAlpha, 0);
            spService->FUN_1413d6e60(spEntity, true);
            if (spService->FUN_1413d66b0(spEntity))
            {
                bool bFalse = false;
                FUN_14098c6e0((Unk_CachedEntity*)spEntity.data(), 0xa0b6b179, bFalse);
            }
        }
    }
    bAlive = false;
    return bAlive;
}

// @0x14098beb0
void CEntityShower::SetAlpha(float fAlpha)
{
    m_fAlpha = fAlpha;
    if (m_pInterpolator)
        m_pInterpolator->SetFrom(fAlpha);
}

// @0x14098bf00
CEntityHider::CEntityHider(egf::EntityID idEntity, NiAVObject* pkNode, float fFrom, float fTo, float fDuration)
    : CEntityShower(idEntity, pkNode, fFrom, fTo, fDuration)
{
}

// MS2-FUNCTIONAL: temporaries differ; same calls and control flow
// @0x14098bf90
bool CEntityHider::vfunc_2()
{
    float fNow = (float)FUN_141473280(FUN_14086d260());
    if (fNow <= m_fEndTime)
    {
        if (m_pInterpolator)
        {
            m_fAlpha = m_pInterpolator->Get((float)FUN_141473260(FUN_14086d260()));
            FUN_14098b3e0(m_spNode, m_fAlpha, 0);
        }
        return true;
    }

    efd::SmartPointer<egf::Entity> spEntity(FUN_1409670f0()->FUN_1411cf440(m_idEntity));
    if (spEntity)
    {
        m_fAlpha = m_pInterpolator->Get((float)FUN_141473260(FUN_14086d260()));
        FUN_14098b3e0(m_spNode, m_fAlpha, 0);
        bool bFalse = false;
        FUN_14098c6e0((Unk_CachedEntity*)spEntity.data(), 0xa0b6b179, bFalse);
    }
    return false;
}

// ---- AlphaTourController ----

// @0x14098c9e0
AlphaTourController::AlphaTourController()
{
}

