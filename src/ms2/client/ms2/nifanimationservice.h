// CNifAnimationService (RTTI name): efd system service (class id 0x06100016) that owns one extra Ni3DRenderView (named
// "NifAnimationInfo") attached to the scene-graph click, and a map entity-id -> NifAnimationInfo of the NIF models whose
// time controllers it keeps running. Member and helper names are invented from their use.
// Owning unit: ?\nifanimationservice.cpp (0x141545470-0x141548790, dir client\ms2).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <efd/ISystemService.h>
#include <Ni3DRenderView.h>
#include <NiNode.h>
#include <NiDynamicEffect.h>
#include <NiTimeController.h>
#include <NiRTTI.h>
#include <NiSmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/timer.h"

class CNifAnimationService;
template <class T> class TSingleton;
template <> class TSingleton<CNifAnimationService>
{
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CNifAnimationService* s_instance;        // 0x143ae1a40
};

// One cached NIF with its running animation: the clone that is shown, the original whose children were detached into
// m_aChildren (re-attached by the dtor) and the play window.
class NifAnimationInfo : public NiRefObject
{
public:
    // @0x141546060
    NifAnimationInfo() : m_spClone(0), m_spOriginal(0)
    {
        m_fStartTime = 0.0f;
        m_fEndTime = 0.0f;
        m_spClone = 0;
        m_spOriginal = 0;
        m_aChildren.RemoveAll();
    }
    // @0x1415461f0 (deleting: 0x1415464e0)
    virtual ~NifAnimationInfo()
    {
        for (size_t i = 0; i < m_aChildren.GetCount(); i++)
        {
            NiAVObject* pkChild = m_aChildren[i];
            if (pkChild)
                m_spOriginal->AttachChild(pkChild, false);
        }
        m_aChildren.RemoveAll();
        m_spClone = 0;
        m_spOriginal = 0;
    }

    // Widens [m_fStartTime, m_fEndTime] by the key times of the time controllers of pkObject and, recursively, of
    // its affected nodes (dynamic effects), children and effects (0x141546810).
    // @0x141546810
    // MS2-FUNCTIONAL: frame size and effect-list call order differ from exe
    void CollectKeyTimes(NiObjectNET* pkObject)
    {
        if (pkObject == 0)
            return;
        for (NiTimeController* pkCtrl = pkObject->GetControllers(); pkCtrl != 0; pkCtrl = pkCtrl->GetNext())
        {
            if (pkCtrl->GetBeginKeyTime() < m_fStartTime)
                m_fStartTime = pkCtrl->GetBeginKeyTime();
            if (m_fEndTime < pkCtrl->GetEndKeyTime())
                m_fEndTime = pkCtrl->GetEndKeyTime();
        }
        if (NiIsKindOf(NiDynamicEffect, pkObject))
        {
            // the exe's Gamebryo keeps the affected nodes in a NiTPointerList<NiNodePtr> (GetHeadPos 0x14098ddb0, IsEmpty
            // 0x141546cb0, GetNext 0x14098de00, NiPointer -> T* 0x140993f00); this SDK's header declares a pointer map
            const NiTPointerList<NiNodePtr>* pkList =
                reinterpret_cast<const NiTPointerList<NiNodePtr>*>(&((NiDynamicEffect*)pkObject)->GetAffectedNodeList());
            NiTListIterator kPos = pkList->GetHeadPos();
            while (pkList != 0 && !pkList->IsEmpty() && kPos != 0)
            {
                NiNode* pkNode = pkList->GetNext(kPos);
                if (pkList != 0)
                    CollectKeyTimes(pkNode);
            }
        }
        if (NiIsKindOf(NiNode, pkObject))
        {
            NiNode* pkNode = (NiNode*)pkObject;
            for (unsigned int i = 0; i < pkNode->GetArrayCount(); i++)
            {
                NiAVObject* pkChild = pkNode->GetAt(i);
                CollectKeyTimes(pkChild);
            }
            const NiDynamicEffectList* pkEffects = &pkNode->GetEffectList();
            NiTListIterator kPos = pkEffects->GetHeadPos();
            while (pkEffects != 0 && !pkEffects->IsEmpty() && kPos != 0)
            {
                NiDynamicEffect* pkEffect = pkEffects->GetNext(kPos);
                if (pkEffect != 0)
                    CollectKeyTimes(pkEffect);
            }
        }
    }

    float m_fStartTime;                             // +0x10 (lowest controller begin key time)
    float m_fEndTime;                               // +0x14 (highest controller end key time)
    Timer m_timer;                                  // +0x18
    NiNodePtr m_spClone;                            // +0x50
    NiNodePtr m_spOriginal;                         // +0x58
    ATL::CAtlArray<NiAVObjectPtr> m_aChildren;      // +0x60
};
MS2_CHECK_SIZE(NifAnimationInfo, 0x80);
MS2_CHECK_OFFSET(NifAnimationInfo, m_timer, 0x18);
MS2_CHECK_OFFSET(NifAnimationInfo, m_spClone, 0x50);
MS2_CHECK_OFFSET(NifAnimationInfo, m_aChildren, 0x60);

class CNifAnimationService : public efd::ISystemService, public TSingleton<CNifAnimationService>
{
    EE_DECLARE_CLASS1(CNifAnimationService, 0x06100016, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CNifAnimationService();                         // 0x141545470
    virtual ~CNifAnimationService();                // 0x141545510, ??_G 0x141546440
    virtual const char* GetDisplayName() const;     // 0x141545580
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x141545920
    virtual efd::AsyncResult OnInit();              // 0x141545950
    virtual efd::AsyncResult OnTick();              // 0x141545b30
    virtual efd::AsyncResult OnShutdown();          // 0x141545ca0

    // Start (nMode 1: restart the controllers of pkNif in place) or register the NIF under nKey (0x1415455a0).
    bool FUN_1415455a0(unsigned __int64 nKey, NiNode* pkNif, int nMode);

    NiPointer<Ni3DRenderView> m_spView;             // +0x28
    ATL::CRBMap<unsigned __int64, NifAnimationInfo*> m_mapInfo;     // +0x30
};
MS2_CHECK_SIZE(CNifAnimationService, 0x60);
MS2_CHECK_OFFSET(CNifAnimationService, m_spView, 0x28);
MS2_CHECK_OFFSET(CNifAnimationService, m_mapInfo, 0x30);
