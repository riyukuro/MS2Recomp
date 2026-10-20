// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuestNavigation and its NavigationEntity markers: see uiquestnavigation.h.
// MS2-UNIT: ?\uiquestnavigation.cpp
// MS2-RANGE: 0x140e785c0-0x140e7dc10 .text$mn
// MS2-RANGE: 0x1400da2b0-0x1400da440 .text$di
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x1400da3d0 ; manual: look-alike of the egf::k*_INVALID statics (pcbase.h)
// The exe's 12-byte point copies are plain rep movsb (no /Oi expansion); the pragma must precede the inline copies.
#pragma function(memcpy, memset)
#define NOMINMAX                        // NxPhysics (interactobject.h)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquestnavigation.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiquestnavigation.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The statics of the unit's .text$di (the name tables of the shop tabs, the pointer handle and the shared id map).
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

using namespace QuestNavigation;

// ---- out-of-unit callees (names describe uses) ----
class MyPC : public PCBase {};                                  // the local player (only its actor view is used)
class Unk_SSGNpc : public PCBase
{
public:
    int FUN_141092fa0();                                        // the npc id
};
class CLiftableObject : public CPtred
{
public:
    CStringA FUN_1414472a0();                                   // the liftable's name
    int FUN_141447cc0();                                        // its id
    int FUN_141447ae0();                                        // nonzero: already carried
    Unk_StreamPoint FUN_141447c80();                            // its position
};
class Unk_SSGNamedObj : public CLiftableObject {};
class Unk_SSGWorld
{
public:
    int FUN_141bd3060();                                        // current channel's map id
    MS2Ptr<CPortal> FUN_141bc2800(int nId);                     // a field object by id
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);   // find one by name
    Unk_SSGNpc* FUN_141bd1320(int nId);
    MS2Ptr<Unk_SSGNamedObj> FUN_141bc5a20(CString strName);     // a named field object
    MyPC* FUN_141bd0cc0();                                      // the local player actor
};
Unk_SSGWorld* FUN_1403ed2d0();
class Unk_QgNavi
{
public:
    TraceResult* FUN_140c9ac60();                               // the current trace
    TraceContext* FUN_140c9adf0();                              // the current trace context
    int FUN_140c9af60();                                        // nonzero: the player's arrow is shown
};
extern Unk_QgNavi* DAT_143abf7e8;                              // the quest navigator
Unk_QgNavi* FUN_140e7c990() { return DAT_143abf7e8; }           // 0x140e7c990
class Unk_QgCamera { public: bool FUN_140af0700(const Unk_StreamPoint& ptWorld, Unk_StreamPoint& rptScreen); };
Unk_QgCamera* FUN_1409478c0();
class Unk_QgUIScale;
Unk_QgUIScale* FUN_14025e7a0();
float FUN_1422afec0(Unk_QgUIScale* pScale, int nMovie);
int FUN_141277f40();
float FUN_1412762d0(const Unk_StreamPoint& pt);                 // the screen y offset of a world point
class Unk_AuCfgValue
{
public:
    const float& FUN_140298f40();
    char m_pad[0x58];
};
struct Unk_AuConfig
{
    char m_pad[0x5e0];
    Unk_AuCfgValue m_5e0;               // +0x5e0 the marker's screen y offset
};
Unk_AuConfig* FUN_1401d3200();
const Unk_StreamPoint& FUN_140947900(void* pNode);
bool FUN_1409b0390(Scaleform::GFx::Value* pValue);              // the value is undefined
NotifySystem* FUN_140939a10();
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
extern Unk_StreamPoint DAT_143b01a60;                           // the zero point

// Out-of-unit instantiations the exe calls rather than inlines.
template<> TraceContext* MS2Ptr<TraceContext>::operator->() const;
template<> bool MS2Ptr<TraceContext>::operator==(TraceContext* p) const;
template<> CString Unk_SocketFormat<unsigned>(const char* format, const unsigned& v0);
template<> CString Unk_SocketFormat<int>(const char* format, const int& v0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NavigationEntity

// @0x140e785c0
NavigationEntity::NavigationEntity()
{
    m_18 = 0;
    m_20 = 0;
    m_1c = 100.0f;
}

// @0x140e78640
NavigationEntity::~NavigationEntity()
{
    m_20 = 0;
}

// @0x140e786a0
int NavigationEntity::vfunc_3(AScript* pParent)
{
    if (!pParent)
        return 0;
    ASObj obj(FUN_141277f40());
    obj.FUN_1407cba60("id", vfunc_1());
    Scaleform::GFx::Value v = pParent->Invoke("create", vfunc_2(), obj);
    if (FUN_1409b0390(&v))
        return 0;
    ASGameEntity* pEntity = new ASGameEntity(v, FUN_141277f40());
    if (pEntity)
        m_20.AssignRaw(pEntity);
    return 1;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e78870
void NavigationEntity::vfunc_4(const TraceResult* pResult)
{
    if (!(m_20 == 0) && m_18 != 0)
    {
        Unk_StreamPoint pt;
        if (!FUN_1409478c0()->FUN_140af0700(vfunc_7(), pt))
        {
            m_20->vfunc_3(0);
        }
        else
        {
            pt.FUN_140ad0c10(FUN_1422afec0(FUN_14025e7a0(), FUN_141277f40()));
            pt.y += vfunc_8();
            m_20->FUN_1422c00f0(pt.x, pt.y);
            m_20->vfunc_3(1);
        }
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e789d0
int NavigationEntity::vfunc_5(const TraceResult* pResult)
{
    return 0;
}

// @0x140e789f0
int NavigationEntity::vfunc_6(const TraceContext* pContext)
{
    return 0;
}

// @0x140e78a10
Unk_StreamPoint NavigationEntity::vfunc_7()
{
    return DAT_143b01a60;
}

// @0x140e78a40
float NavigationEntity::vfunc_8()
{
    return FUN_1412762d0(vfunc_7());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PcHudNavigationEntity

// @0x140e78a80
PcHudNavigationEntity::PcHudNavigationEntity()
{
}

// @0x140e78ac0
PcHudNavigationEntity::~PcHudNavigationEntity()
{
}

// @0x140e78af0
int PcHudNavigationEntity::vfunc_5(const TraceResult* pResult)
{
    if (!pResult || pResult->m_1c == 0)
        return 0;
    return FUN_140e7c990()->FUN_140c9af60();
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e78b40
void PcHudNavigationEntity::vfunc_4(const TraceResult* pResult)
{
    NavigationEntity::vfunc_4(pResult);
    if (pResult && !(m_20 == 0))
    {
        MS2Ptr<ASTextField> spText = m_20->FUN_1409b4620("m_distance");
        if (spText.get())
            spText->FUN_1422c4cd0(pResult->m_38);
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e78c40
Unk_StreamPoint PcHudNavigationEntity::vfunc_7()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPC)
        return DAT_143b01a60;
    NiPoint3 pt = pPC->vfunc_18();
    return Unk_StreamPoint(pt.x, pt.y, pt.z);
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e78cc0
float PcHudNavigationEntity::vfunc_8()
{
    return 40.0f - NavigationEntity::vfunc_8();
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NpcNavigationEntity

// @0x140e78d00
NpcNavigationEntity::NpcNavigationEntity(efd::SmartPointer<Unk_SSGNpc> spNpc)
{
    m_30 = spNpc.operator->()->FUN_14123c580();
    m_34 = spNpc.operator->()->FUN_141092fa0();
}

// @0x140e78d80
NpcNavigationEntity::~NpcNavigationEntity()
{
}

// @0x140e78db0
CString NpcNavigationEntity::vfunc_1()
{
    return Unk_SocketFormat<unsigned>("npc_{0}", m_30);
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e78e00
int NpcNavigationEntity::vfunc_5(const TraceResult* pResult)
{
    if (!pResult)
        return 0;
    if (pResult->m_40 == 0)
        return 0;
    TraceContext* pContext = pResult->m_40.operator->();
    if (pContext->m_18 != FUN_1403ed2d0()->FUN_141bd3060())
        return 0;
    if (pContext->m_20.find(m_34) == pContext->m_20.end())
        return 0;
    if (pResult->m_1c == 2)
        return 0;
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_30);
    if (!pNpc)
        return 0;
    return pNpc->FUN_14166ce30() == 0 ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e78f50
int NpcNavigationEntity::vfunc_6(const TraceContext* pContext)
{
    if (!pContext)
        return 0;
    if (pContext->m_20.find(m_34) == pContext->m_20.end())
        return 0;
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_30);
    if (!pNpc)
        return 0;
    return pNpc->FUN_14166ce30() == 0 ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e79010
Unk_StreamPoint NpcNavigationEntity::vfunc_7()
{
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_30);
    if (!pNpc)
        return DAT_143b01a60;
    NiAVObject* pNode = pNpc->FUN_141675150("Eff_UI");
    if (!pNode)
    {
        NiPoint3 pt = pNpc->vfunc_18();
        return Unk_StreamPoint(pt.x, pt.y, pt.z);
    }
    return FUN_140947900(pNode);
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e790f0
float NpcNavigationEntity::vfunc_8()
{
    return NavigationEntity::vfunc_8() - (FUN_1401d3200()->m_5e0.FUN_140298f40() + 30.0f);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// InteractNavigationEntity

// @0x140e79140
InteractNavigationEntity::InteractNavigationEntity(CInteractObject* pObject)
{
    m_38 = pObject->FUN_140967060();
    m_30 = pObject->FUN_140967110();
}

// @0x140e791f0
InteractNavigationEntity::~InteractNavigationEntity()
{
}

// @0x140e79230
CString InteractNavigationEntity::vfunc_1()
{
    return StringFormat<CString>("interact_{0}", m_38);
}

// @0x140e79280
int InteractNavigationEntity::vfunc_5(const TraceResult* pResult)
{
    if (!pResult)
        return 0;
    if (pResult->m_40 == 0)
        return 0;
    TraceContext* pContext = pResult->m_40.operator->();
    if (pContext->m_18 != FUN_1403ed2d0()->FUN_141bd3060())
        return 0;
    if (pContext->m_30.find(m_30) == pContext->m_30.end())
        return 0;
    if (pResult->m_1c == 2)
        return 0;
    MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(m_38);
    if (spObj.IsNull())
        return 0;
    return spObj->vfunc_7() == 0 ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e79450
int InteractNavigationEntity::vfunc_6(const TraceContext* pContext)
{
    if (!pContext)
        return 0;
    if (pContext->m_30.find(m_30) == pContext->m_30.end())
        return 0;
    MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(m_38);
    if (spObj.IsNull())
        return 0;
    return spObj->vfunc_7() == 0 ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e79590
Unk_StreamPoint InteractNavigationEntity::vfunc_7()
{
    MS2Ptr<CInteractObject> spObj = FUN_1403ed2d0()->FUN_141bc66b0(m_38);
    if (spObj.get() == 0)
        return DAT_143b01a60;
    Unk_StreamPoint pt = spObj->FUN_1409673c0();
    pt.z += 200.0f;
    return pt;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LiftableNavigationEntity

// @0x140e79670
LiftableNavigationEntity::LiftableNavigationEntity(CLiftableObject* pObject)
{
    m_38 = pObject->FUN_1414472a0();
    m_30 = pObject->FUN_141447cc0();
}

// @0x140e79720
LiftableNavigationEntity::~LiftableNavigationEntity()
{
}

// @0x140e79760
CString LiftableNavigationEntity::vfunc_1()
{
    return StringFormat<CString>("liftable_{0}", m_38);
}

// @0x140e797b0
int LiftableNavigationEntity::vfunc_5(const TraceResult* pResult)
{
    if (!pResult)
        return 0;
    if (pResult->m_40 == 0)
        return 0;
    TraceContext* pContext = pResult->m_40.operator->();
    if (pContext->m_18 != FUN_1403ed2d0()->FUN_141bd3060())
        return 0;
    if (pContext->m_40.find(m_30) == pContext->m_40.end())
        return 0;
    if (pResult->m_1c == 2)
        return 0;
    MS2Ptr<Unk_SSGNamedObj> spObj = FUN_1403ed2d0()->FUN_141bc5a20(m_38);
    if (spObj.IsNull())
        return 0;
    return spObj->FUN_141447ae0() == 0 ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e799b0
int LiftableNavigationEntity::vfunc_6(const TraceContext* pContext)
{
    if (!pContext)
        return 0;
    if (pContext->m_40.find(m_30) == pContext->m_40.end())
        return 0;
    MS2Ptr<Unk_SSGNamedObj> spObj = FUN_1403ed2d0()->FUN_141bc5a20(m_38);
    if (spObj.IsNull())
        return 0;
    return spObj->FUN_141447ae0() == 0 ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e79b20
Unk_StreamPoint LiftableNavigationEntity::vfunc_7()
{
    MS2Ptr<Unk_SSGNamedObj> spObj = FUN_1403ed2d0()->FUN_141bc5a20(m_38);
    if (spObj.get() == 0)
        return DAT_143b01a60;
    Unk_StreamPoint pt = spObj->FUN_141447c80();
    pt.z += 200.0f;
    return pt;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PortalNavigationEntity

// @0x140e79c30
PortalNavigationEntity::PortalNavigationEntity(CPortal* pPortal)
{
    m_30 = pPortal->m_nId;
}

// @0x140e79c80
PortalNavigationEntity::~PortalNavigationEntity()
{
}

// @0x140e79cb0
CString PortalNavigationEntity::vfunc_1()
{
    return Unk_SocketFormat<int>("portal_{0}", m_30);
}

// @0x140e79d00
int PortalNavigationEntity::vfunc_5(const TraceResult* pResult)
{
    if (!pResult)
        return 0;
    if (pResult->m_40 == 0)
        return 0;
    if (pResult->m_1c != 4)
        return 0;
    MS2Ptr<CPortal> spPortal = FUN_1403ed2d0()->FUN_141bc2800(m_30);
    if (spPortal.IsNull())
        return 0;
    Unk_StreamPoint pt = spPortal->FUN_14169d2f0();
    if (pt.FUN_140552700(Unk_StreamPoint(pResult->m_20.x, pResult->m_20.y, pResult->m_20.z)))
        return 0;
    return spPortal->FUN_14169d160() ? 1 : 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e79e50
Unk_StreamPoint PortalNavigationEntity::vfunc_7()
{
    MS2Ptr<CPortal> spPortal = FUN_1403ed2d0()->FUN_141bc2800(m_30);
    if (spPortal.get() == 0)
        return DAT_143b01a60;
    Unk_StreamPoint pt = spPortal->FUN_14169d2f0();
    pt.z += 200.0f;
    return pt;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UIQuestNavigation

// @0x140e79f20
UIQuestNavigation::UIQuestNavigation()
    : m_entities(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_2c = 0x1f;
    m_28 = FUN_141277f40();
    m_58 = 0;
    FUN_140939a10()->RegisterNotify(L"NotifyAddNpc", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7af90));
    FUN_140939a10()->RegisterNotify(L"NotifyRemoveNpc", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b130));
    FUN_140939a10()->RegisterNotify(L"NotifyAddInteract", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b290));
    FUN_140939a10()->RegisterNotify(L"NotifyAddLiftable", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b430));
    FUN_140939a10()->RegisterNotify(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b640));
    FUN_140939a10()->RegisterNotify(L"NotifyAddPortal", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b720));
}

// @0x140e7a530
UIQuestNavigation::~UIQuestNavigation()
{
    FUN_140939a10()->UnregisterNotify(L"NotifyAddNpc", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7af90));
    FUN_140939a10()->UnregisterNotify(L"NotifyRemoveNpc", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b130));
    FUN_140939a10()->UnregisterNotify(L"NotifyAddInteract", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b290));
    FUN_140939a10()->UnregisterNotify(L"NotifyAddLiftable", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b430));
    FUN_140939a10()->UnregisterNotify(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b640));
    FUN_140939a10()->UnregisterNotify(L"NotifyAddPortal", Delegate<void(NotifyObject*)>(this, &UIQuestNavigation::FUN_140e7b720));
}

// @0x140e7aa40
CString UIQuestNavigation::vfunc_1()
{
    return "QuestNavigation";
}

// @0x140e7aa90
void UIQuestNavigation::vfunc_2()
{
    FUN_1422dbf00(m_2c, 0, 0);
}

// @0x140e7aac0
void UIQuestNavigation::vfunc_3()
{
    if (m_30.get())
        m_30->Invoke("removeAll");
    m_entities.RemoveAll();
    UISwfEntity::FUN_1422dc080();
}

// @0x140e7ab40
void UIQuestNavigation::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    POSITION pos = m_entities.GetStartPosition();
    while (pos)
    {
        MS2Ptr<NavigationEntity> spEntity = m_entities.GetValueAt(pos);
        if (!(spEntity->m_20 == 0))
            spEntity->vfunc_3(m_30.get());
        m_entities.GetNext(pos);
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7ac40
void UIQuestNavigation::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    TraceResult* pResult = FUN_140e7c990()->FUN_140c9ac60();
    TraceContext* pContext = FUN_140e7c990()->FUN_140c9adf0();
    POSITION pos = m_entities.GetStartPosition();
    while (pos)
    {
        MS2Ptr<NavigationEntity> spEntity = m_entities.GetValueAt(pos);
        Unk_StreamPoint ptTemp;
        int nState;
        float fAlpha = 0.0f;
        if (spEntity->vfunc_5(pResult))
        {
            nState = 1;
            fAlpha = 100.0f;
        }
        else if (spEntity->vfunc_6(pContext))
        {
            nState = 1;
            fAlpha = 50.0f;
        }
        else
        {
            nState = 0;
        }
        if (spEntity->m_18 != nState)
        {
            if (nState == 0)
            {
                if (FUN_140e7ba00(spEntity))
                    spEntity->m_18 = 0;
            }
            else
            {
                if (FUN_140e7b890(spEntity))
                    spEntity->m_18 = 1;
            }
        }
        if (fAlpha != spEntity->m_1c && nState != 0)
        {
            if (spEntity->m_20.get())
            {
                spEntity->m_20->FUN_1422bfe00(fAlpha);
                spEntity->m_1c = fAlpha;
            }
        }
        spEntity->vfunc_4(pResult);
        m_entities.GetNext(pos);
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7af40
int UIQuestNavigation::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7af90
void UIQuestNavigation::FUN_140e7af90(NotifyObject* pNotify)
{
    NotifyAddNpc* pAdd = dynamic_cast<NotifyAddNpc*>(pNotify);
    if (pAdd)
    {
        MS2Ptr<NavigationEntity> spEntity(new NpcNavigationEntity(pAdd->m_spNpc));
        spEntity->vfunc_3(m_30.get());
        m_entities.SetAt(spEntity->vfunc_1(), spEntity);
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7b130
void UIQuestNavigation::FUN_140e7b130(NotifyObject* pNotify)
{
    if (m_30.IsNull())
        return;
    NotifyRemoveNpc* pRemove = dynamic_cast<NotifyRemoveNpc*>(pNotify);
    if (pRemove)
    {
        CStringA strKey = Unk_SocketFormat<unsigned>("npc_{0}", pRemove->m_spNpc->FUN_14123c580());
        MS2Ptr<NavigationEntity> spEntity(0);
        if (m_entities.Lookup(strKey, spEntity))
        {
            FUN_140e7ba00(spEntity);
            m_entities.RemoveKey(strKey);
        }
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7b290
void UIQuestNavigation::FUN_140e7b290(NotifyObject* pNotify)
{
    NotifyAddInteract* pAdd = dynamic_cast<NotifyAddInteract*>(pNotify);
    if (pAdd)
    {
        CInteractObject* pObject = static_cast<CInteractObject*>(pAdd->m_pObj);
        if (pObject->vfunc_5() == 1)
        {
            MS2Ptr<NavigationEntity> spEntity(new InteractNavigationEntity(pObject));
            spEntity->vfunc_3(m_30.get());
            m_entities.SetAt(spEntity->vfunc_1(), spEntity);
        }
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7b430
void UIQuestNavigation::FUN_140e7b430(NotifyObject* pNotify)
{
    NotifyAddLiftable* pAdd = dynamic_cast<NotifyAddLiftable*>(pNotify);
    if (pAdd)
    {
        CLiftableObject* pObject = static_cast<CLiftableObject*>(pAdd->m_pObj);
        CStringA strKey = StringFormat<CString>("liftable_{0}", pObject->FUN_1414472a0());
        if (!m_entities.Lookup(strKey))
        {
            MS2Ptr<NavigationEntity> spEntity(new LiftableNavigationEntity(pObject));
            spEntity->vfunc_3(m_30.get());
            m_entities.SetAt(spEntity->vfunc_1(), spEntity);
        }
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7b640
void UIQuestNavigation::FUN_140e7b640(NotifyObject* pNotify)
{
    MS2Ptr<NavigationEntity> spEntity(new PcHudNavigationEntity());
    spEntity->vfunc_3(m_30.get());
    m_entities.SetAt("PcHud", spEntity);
}

// @0x140e7b720
void UIQuestNavigation::FUN_140e7b720(NotifyObject* pNotify)
{
    NotifyAddPortal* pAdd = dynamic_cast<NotifyAddPortal*>(pNotify);
    if (pAdd)
    {
        CPortal* pPortal = static_cast<CPortal*>(pAdd->m_pObj);
        MS2Ptr<NavigationEntity> spEntity(new PortalNavigationEntity(pPortal));
        spEntity->vfunc_3(m_30.get());
        m_entities.SetAt(spEntity->vfunc_1(), spEntity);
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7b890
int UIQuestNavigation::FUN_140e7b890(MS2Ptr<NavigationEntity> spEntity)
{
    if (m_30.IsNull())
        return 0;
    if (spEntity->m_20 == 0)
        return 0;
    if (spEntity->m_18 == 0)
        m_30->Invoke("addChild", Scaleform::GFx::Value(spEntity->m_20->FUN_1422bb870()));
    return 1;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7ba00
int UIQuestNavigation::FUN_140e7ba00(MS2Ptr<NavigationEntity> spEntity)
{
    if (m_30.IsNull())
        return 0;
    if (spEntity->m_20 == 0)
        return 0;
    if (spEntity->m_18 != 0)
        m_30->Invoke("removeChild", Scaleform::GFx::Value(spEntity->m_20->FUN_1422bb870()));
    return 1;
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMDAT glue

// @0x140e7bcb0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, const AScript& a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1.GetString());
    FUN_1422bce40(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}   // MS2-FUNCTIONAL: not byte-matched (call order / stack and EH state layout)

// @0x140e7daf0
MS2_EMIT_CRT_MEMMOVE_S_COPY(16);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca7670-0x142ca7700 .text$yd
