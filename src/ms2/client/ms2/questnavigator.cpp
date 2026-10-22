// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuestNavigator: the quest guide beam. It keeps the quest
// the player selected for navigation (m_18, a QuestNavigation::TraceResult), traces it every frame to the nearest
// target on the current map (an npc, an interact object, a liftable, or the portal towards the target's map), places
// the "Eff_Quest_Navigation" effect node at the player and tells the minimap / HUD the distance text. m_70 holds the
// maps, npcs and objects the tracked quests lead to (rebuilt when a quest changes).
// MS2-UNIT: ?\questnavigator.cpp
// MS2-PIN: ??_7CQuestNavigator@@6B?$TSingleton@VCQuestNavigator@@@@@ 0x142e152e0
// MS2-RANGE: 0x1400cf480-0x1400cf5f0 .text$di
// MS2-RANGE: 0x140c99700-0x140c9ba20 .text$mn
// MS2-FUNCTIONAL: written from the decompile; the Delegate / MS2Ptr template glue is not pinned
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\questnavigator.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <float.h>
#include <atlcoll.h>
#include <NiNode.h>
#include <NiTransform.h>

#include "ms2/placeholder/cquestnavigator.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"

class NotifyObject;
// The minimap dialog (UI type 0x4e29) lives in another unit; only the cast target is needed.
class UIMinimapDialog : public UIDialog
{
};

// ---- unit-local views of the exe objects and unrecovered callees ----

// The tracked quest id lives in the player settings block at +0x160 (field +0x30).
struct Unk_QnTracking { char m_pad_00[0x30]; int m_30; };
class Unk_QnState
{
public:
    Unk_QnTracking* FUN_140c9b8b0() { return &m_160; }              // 0x140c9b8b0
    void FUN_141243540();                                           // save the settings
    char m_pad_00[0x160];
    Unk_QnTracking m_160;
};
Unk_QnState* FUN_1409a8b10();

class Unk_QnFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_QnFeatures* FUN_140166410();

class Unk_QnNotices
{
public:
    void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> cb);   // register
    void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> cb);   // unregister
};
Unk_QnNotices* FUN_140939a10();

UIQuestEventDispatcher* FUN_140bfc4b0();
WorldService* FUN_1403ed2d0();
CQuestManager* FUN_140764020();
void* FUN_1403ed280();
NiNode* FUN_1411a6b10(void* p);                                     // the scene root
void* FUN_1408e57f0();
int FUN_1422b9e00(void* p);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_14062b4f0(CStringW strKey, const int& n);              // localized text with one number
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
CQuestNavigationMap* FUN_140c9b8e0();
int FUN_140408410(const ATL::CAtlArray<unsigned>& aValues, const unsigned& nValue);    // index of nValue or -1
UIMinimapDialog* FUN_140c9b540(int nId);

// the minimap dialog (UI type 0x4e29) and the UI manager
class Unk_QnUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_QnUIMgr* FUN_1403ed2b0();
void FUN_141a3ada0(UIMinimapDialog* pDialog);                       // refresh the minimap's quest marker

// engine helpers (non-inlined in the exe)
Unk_StreamPoint FUN_140a0b080(const Unk_StreamPoint& a, const Unk_StreamPoint& b, const Unk_StreamPoint& c);
void FUN_140b86230(const Unk_StreamPoint* pTarget, NiTransform* pXf);
float FUN_140966f00(Unk_StreamPoint a, Unk_StreamPoint b);
extern Unk_StreamPoint DAT_143b01a60;                               // the zero point
extern Unk_StreamPoint DAT_143a08cf8;                               // the up axis
extern const NiRTTI DAT_143afa4d8;                                  // NiNode::ms_RTTI
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);   // NiDynamicCast

// the loaded effect model (a smart pointer, dtor 0x1405a85c0) and the model loader
struct Unk_QnModelRef { void* m_p; ~Unk_QnModelRef(); };
class Unk_QnModelLoader { public: Unk_QnModelRef FUN_141551ea0(CString strPath, int a, int b, int c, int d); };
Unk_QnModelLoader* FUN_140a0afd0();
NiObject* FUN_1409849b0(const Unk_QnModelRef& ref);

// riding data (rows of the ride table)
struct Unk_QnRideRow { char m_pad_00[0x6c]; int m_6c; };
class Unk_QnRideRef
{
public:
    Unk_QnRideRef(int nRideId);                                     // 0x1407844b0
    ~Unk_QnRideRef();                                               // 0x140788ed0
    bool FUN_140c9b760() const { return m_p == 0; }                 // 0x140c9b760
    void* FUN_1407895d0();                                          // the table
    void* m_0;
    void* m_p;
};
class Unk_QnRideEntry { public: ~Unk_QnRideEntry(); Unk_QnRideRow* FUN_1407895c0(); void* m_0; void* m_p; };   // dtor 0x140788ea0
Unk_QnRideEntry FUN_140784970(void* pTable);

// ---- dynamic initializers (.text$di) ----

#ifndef MS2_HOOK_DLL
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142ca3a50();                                               // the exe's atexit destructor of the marker
struct Unk_QnMarker {};
#endif

// @0x1400cf480
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400cf540
static CString s_skill("skill");

// @0x1400cf570
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400cf5a0
static char s_marker[0x48];
static Unk_QnMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142ca3a50), Unk_QnMarker());
#endif

// ---- CQuestNavigator ----

// @0x140c99700
CQuestNavigator::CQuestNavigator()
{
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyCompleteMyPC"), Delegate<void(NotifyObject*)>(this, &CQuestNavigator::OnCompleteMyPC));
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyCreateMyPC"), Delegate<void(NotifyObject*)>(this, &CQuestNavigator::OnCreateMyPC));
    FUN_140bfc4b0()->FUN_141aa87c0(this);
}

// @0x140c99990
CQuestNavigator::~CQuestNavigator()
{
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyCompleteMyPC"), Delegate<void(NotifyObject*)>(this, &CQuestNavigator::OnCompleteMyPC));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyCreateMyPC"), Delegate<void(NotifyObject*)>(this, &CQuestNavigator::OnCreateMyPC));
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// A quest was removed / completed: the navigation target is dropped when it was this quest.
// @0x140c99be0
void CQuestNavigator::vfunc_o178_6(void* pQuest)
{
    CQuest* quest = (CQuest*)pQuest;
    if (IsSelected(quest->FUN_140bfc580()) && quest->GetTrackingState() == 0)
        SelectQuest(0);
}

// A quest was accepted / changed: select it for navigation when it asks for it.
// @0x140c99c40
void CQuestNavigator::vfunc_o178_1(void* pQuest)
{
    m_68 = 1;
    if (IsSelected(0))
    {
        if (((CQuest*)pQuest)->GetTrackingState() != 0)
        {
            MS2Ptr<CQuestData> spData = ((CQuest*)pQuest)->GetData();
            if (spData.IsNull())
                return;
            if (spData->m_flag != 0)
                SelectQuest(((CQuest*)pQuest)->FUN_140bfc580());
        }
    }
}

// @0x140c99d20
void CQuestNavigator::vfunc_o178_2(void* pQuest)
{
    CQuest* quest = (CQuest*)pQuest;
    m_68 = 1;
    if (IsSelected(quest->FUN_140bfc580()))
        SelectQuest(0);
}

// @0x140c99d80
void CQuestNavigator::vfunc_o178_3(void* pQuest)
{
    m_68 = 1;
}

// @0x140c99da0
void CQuestNavigator::vfunc_o178_5(void* pQuest)
{
    CQuest* quest = (CQuest*)pQuest;
    m_68 = 1;
    if (IsSelected(quest->FUN_140bfc580()))
        SelectQuest(0);
}

// @0x140c99e00
void CQuestNavigator::vfunc_o178_7(int nQuestId, int a2)
{
    m_68 = 1;
}

// Detach the beam from its parent and drop it.
// @0x140c99e30
void CQuestNavigator::FUN_140c99e30()
{
    if ((NiNode*)m_10 != 0)
    {
        NiNode* pParent = m_10->GetParent();
        if (pParent != 0)
        {
            NiAVObjectPtr spDetached = pParent->DetachChild(m_10);
        }
        m_10 = 0;
    }
}

// Per frame: re-trace the selected quest and move the beam to the player.
// @0x140c99ee0
void CQuestNavigator::FUN_140c99ee0()
{
    PCBase* pPC = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        if (m_10 != 0)
        {
            m_18.Clear();
            int nFailed = FUN_140c9a4c0(&m_18);
            unsigned char bShow = FUN_140c9af60();
            if (nFailed != 0)
                bShow = 0;
            unsigned bVisible = (m_10->GetAppCulled() == 0);
            if (bShow != bVisible)
            {
                bool bCull = bShow == 0;
                m_10->SetAppCulled(bCull);
            }
            if (bShow != 0)
            {
                NiTransform xf;
                xf.MakeIdentity();
                xf.m_Translate = NiPoint3(pPC->vfunc_18());
                FUN_140b86230(reinterpret_cast<Unk_StreamPoint*>(&m_18.m_2c), &xf);
                m_10->SetLocalTransform(xf);
            }
        }
        if (m_68 != 0)
        {
            m_68 = 0;
            FUN_140c9ac80();
        }
    }
}

// "NotifyCreateMyPC": the local player appeared; restore the tracked quest from the settings.
// @0x140c9a0e0
void CQuestNavigator::OnCreateMyPC(NotifyObject* pNotify)
{
    m_18.Clear();
    m_18.m_18 = 0;
    int nQuestId = FUN_1409a8b10()->FUN_140c9b8b0()->m_30;
    Unk_PayloadPtr<CQuest> spQuest = static_cast<CQuestManagerCommon*>(FUN_140764020())->vfunc_o10_3(nQuestId);
    if (!spQuest.IsNull())
    {
        if (spQuest->GetTrackingState() != 0)
            m_18.m_18 = nQuestId;
    }
}

// "NotifyCompleteMyPC": the local player finished loading; create the beam effect.
// @0x140c9a1c0
void CQuestNavigator::OnCompleteMyPC(NotifyObject* pNotify)
{
    if (FUN_140166410()->FUN_14036d570(0x77))
    {
        if (m_10 == 0)
        {
            Unk_QnModelRef ref = FUN_140a0afd0()->FUN_141551ea0(CString("./Data/Resource/Model/Effect/ETC/Eff_Quest_Navigation.nif"), 0, 5, 0, 0);
            m_10 = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, FUN_1409849b0(ref));
            if ((NiNode*)m_10 != 0)
            {
                NiNode* pScene = FUN_1411a6b10(FUN_1403ed280());
                if (pScene != 0)
                {
                    pScene->AttachChild(m_10, true);
                    m_10->SetAppCulled(true);
                    m_10->UpdateEffects();
                    m_10->UpdateProperties();
                    m_10->Update(0.0f, true);
                }
            }
        }
        FUN_140c9ac80();
        UIMinimapDialog* pMinimap = FUN_140c9b540(0x4e29);
        if (pMinimap != 0)
            FUN_141a3ada0(pMinimap);
    }
}

// @0x140c9a420
void CQuestNavigator::SelectQuest(int nQuestId)
{
    m_18.Clear();
    m_18.m_18 = nQuestId;
    if (FUN_1409a8b10()->FUN_140c9b8b0()->m_30 != nQuestId)
    {
        FUN_1409a8b10()->FUN_140c9b8b0()->m_30 = nQuestId;
        FUN_1409a8b10()->FUN_141243540();
    }
}

// @0x140c9a490
int CQuestNavigator::IsSelected(int nQuestId)
{
    if (m_18.m_18 == nQuestId)
        return 1;
    return 0;
}

// Trace the quest of pResult to its nearest target. Returns 0 when a target was found (pResult filled), 1 when the
// quest cannot be navigated, 2 while the map paths are still being built.
// @0x140c9a4c0
int CQuestNavigator::FUN_140c9a4c0(QuestNavigation::TraceResult* pResult)
{
    if (!FUN_140166410()->FUN_14036d570(0x77))
        return 1;
    CQuestNavigationMap* pMap = FUN_140c9b8e0();
    if (pMap->FUN_140c9b8d0() == 0)
    {
        pResult->m_38 = GetStringCommonByKey(CStringW(L"s_quest_navigation_initializing"));
        return 2;
    }
    MS2Ptr<CQuestData> spData = FUN_14074bc40(pResult->m_18);
    if (spData.IsNull())
        return 1;
    if (spData->m_flag == 0)
        return 1;
    MS2Ptr<QuestNavigation::TraceContext> spContext = pMap->TraceQuest(pResult->m_18);
    if (spContext == 0)
        return 1;
    int nFailed = 1;
    int nTargetMap = spContext->m_18;
    int nCurrentMap = FUN_1403ed2d0()->FUN_141bd3060();
    if (nTargetMap == nCurrentMap)
    {
        float fBest = FLT_MAX;
        float fDist = FLT_MAX;
        Unk_StreamPoint pos = DAT_143b01a60;
        if (FUN_1403ed2d0()->FUN_141bd49d0(spContext->m_20, &pos, &fDist) != 0 && (nFailed = 0, fDist < fBest))
        {
            fBest = fDist;
            if (static_cast<CQuestManagerCommon*>(FUN_140764020())->FUN_1407456d0(pResult->m_18) == 0)
                pResult->m_1c = 1;
            else
                pResult->m_1c = 2;
            reinterpret_cast<Unk_StreamPoint&>(pResult->m_20) = pos;
        }
        if (FUN_1403ed2d0()->FUN_141bd4ed0(spContext->m_30, &pos, &fDist) != 0 && (nFailed = 0, fDist < fBest))
        {
            fBest = fDist;
            pResult->m_1c = 3;
            reinterpret_cast<Unk_StreamPoint&>(pResult->m_20) = pos;
        }
        if (FUN_1403ed2d0()->FUN_141bd51a0(spContext->m_40, &pos, &fDist) != 0 && (nFailed = 0, fDist < fBest))
        {
            fBest = fDist;
            pResult->m_1c = 5;
            reinterpret_cast<Unk_StreamPoint&>(pResult->m_20) = pos;
        }
    }
    else
    {
        ATL::CAtlArray<unsigned> aPath;
        if (pMap->FindMapPath(nCurrentMap, nTargetMap, aPath) != 0)
        {
            bool bFound = false;
            ATL::CAtlArray<MS2Ptr<CPortal> > aPortals;
            FUN_1403ed2d0()->FUN_141bc2a70(6, &aPortals);
            for (size_t i = 0; i < aPortals.GetCount(); i++)
            {
                MS2Ptr<CPortal> spPortal = aPortals[i];
                if (spPortal->FUN_14169d160())
                {
                    unsigned nPortalMap = spPortal->FUN_14169d280();
                    if (FUN_140408410(aPath, nPortalMap) != -1)
                    {
                        pResult->m_1c = 4;
                        reinterpret_cast<Unk_StreamPoint&>(pResult->m_20) = spPortal->FUN_14169d2f0();
                        nFailed = 0;
                        bFound = true;
                        break;
                    }
                }
            }
            if (!bFound)
            {
                int nNextMap = pMap->FUN_140c912d0(nCurrentMap, nTargetMap);
                if (nNextMap != 0)
                {
                    MS2Ptr<CPortal> spNext = FUN_1403ed2d0()->FUN_141bc2880(nNextMap);
                    if (spNext.get() != 0)
                    {
                        if (spNext->FUN_14169d160() == 1)
                        {
                            pResult->m_1c = 4;
                            reinterpret_cast<Unk_StreamPoint&>(pResult->m_20) = spNext->FUN_14169d2f0();
                            nFailed = 0;
                        }
                    }
                }
            }
        }
    }
    if (nFailed == 0)
    {
        Unk_StreamPoint posTarget = reinterpret_cast<Unk_StreamPoint&>(pResult->m_20);
        reinterpret_cast<Unk_StreamPoint&>(pResult->m_2c) = FUN_140c9b0a0(posTarget);
        Unk_StreamPoint posText = reinterpret_cast<Unk_StreamPoint&>(pResult->m_20);
        pResult->m_38 = FUN_140c9b150(posText);
        pResult->m_40 = spContext;
    }
    return nFailed;
}

// @0x140c9ac60
QuestNavigation::TraceResult* CQuestNavigator::Result()
{
    return &m_18;
}

// Rebuild m_70 from the tracked quests of the current map.
// @0x140c9ac80
void CQuestNavigator::FUN_140c9ac80()
{
    m_70.m_20.clear();
    m_70.m_30.clear();
    m_70.m_40.clear();
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    ATL::CAtlArray<Unk_PayloadPtr<CQuest> > aQuests;
    FUN_140764020()->FUN_1416cb8b0(aQuests, 1, 0xb, -1);
    for (size_t i = 0; i < aQuests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = aQuests[i];
        FUN_140c9b8e0()->FUN_140c92fc0(spQuest, nMapId, m_70);
    }
}

// @0x140c9adf0
QuestNavigation::TraceContext* CQuestNavigator::Context()
{
    return &m_70;
}

// @0x140c9ae10
int CQuestNavigator::HasMap(int nMapId)
{
    if (m_70.m_20.find(nMapId) != m_70.m_20.end())
        return 1;
    return 0;
}

// @0x140c9ae80
int CQuestNavigator::HasNpc(int nNpcId)
{
    if (m_70.m_30.find(nNpcId) != m_70.m_30.end())
        return 1;
    return 0;
}

// @0x140c9aef0
int CQuestNavigator::HasInteractObject(int nObjectId)
{
    if (m_70.m_40.find(nObjectId) != m_70.m_40.end())
        return 1;
    return 0;
}

// The beam shows only in the field state, and not while the player is hidden or rides something without a beam.
// @0x140c9af60
bool CQuestNavigator::FUN_140c9af60()
{
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d)
    {
        PCBase* pPC = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC == 0)
            return false;
        if (pPC->FUN_1416764d0() == 0)
            return pPC->FUN_14123c660() == 0;
        Unk_QnRideRef ride(pPC->FUN_141676410());
        if (ride.FUN_140c9b760())
            return false;
        Unk_QnRideEntry entry = FUN_140784970(ride.FUN_1407895d0());
        int nValue = entry.FUN_1407895c0()->m_6c;
        return nValue != 0;
    }
    return false;
}

// The end point of the beam: from the player towards pos.
// @0x140c9b0a0
Unk_StreamPoint CQuestNavigator::FUN_140c9b0a0(const Unk_StreamPoint& pos)
{
    PCBase* pPC = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return DAT_143b01a60;
    const auto& ptPC = pPC->vfunc_18();
    Unk_StreamPoint posPC = reinterpret_cast<const Unk_StreamPoint&>(ptPC);
    return FUN_140a0b080(posPC, pos, DAT_143a08cf8);
}

// The distance text from the player to pos.
// @0x140c9b150
CStringW CQuestNavigator::FUN_140c9b150(const Unk_StreamPoint& pos)
{
    PCBase* pPC = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return CStringW(L"");
    CStringW strText;
    Unk_StreamPoint posTo = pos;
    const auto& ptPC = pPC->vfunc_18();
    Unk_StreamPoint posPC = reinterpret_cast<const Unk_StreamPoint&>(ptPC);
    int nDist = (int)FUN_140966f00(posPC, posTo);
    if (nDist <= 100000)
    {
        if (nDist < 100000 && 99 < nDist)
        {
            int nMeters = nDist / 100;
            strText = FUN_14062b4f0(CStringW(L"s_quest_navigation_distance_m"), nMeters);
        }
        else
        {
            strText = GetStringCommonByKey(CStringW(L"s_quest_navigation_dest"));
        }
    }
    else
    {
        int nKm = nDist / 100000;
        strText = FUN_14062b4f0(CStringW(L"s_quest_navigation_distance_km"), nKm);
    }
    return strText;
}

// The minimap dialog (UI type 0x4e29).
// @0x140c9b540
UIMinimapDialog* FUN_140c9b540(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIMinimapDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140c9b8e0
CQuestNavigationMap* FUN_140c9b8e0()
{
    return TSingleton<CQuestNavigationMap>::GetInstance();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca39e0-0x142ca3a70 .text$yd
