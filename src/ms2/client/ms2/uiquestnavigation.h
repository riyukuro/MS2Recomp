// uiquestnavigation.h - UIQuestNavigation (RTTI .?AVUIQuestNavigation@@, 0xb0 bytes, UIObject, ui id 0x4f3c) and the
// QuestNavigation::NavigationEntity family it keeps in a name -> entity map. Owning unit: ?\uiquestnavigation.cpp
// (0x140e785c0-0x140e7dc10; header name assumed from the unit path).
//
// The dialog shows one marker per traced target (npcs, interact objects, liftables, portals and the "PcHud" arrow)
// on the HUD. Notify handlers add / remove the entities; every frame the entity set is compared with the navigator's
// current trace (Unk_QgNavi, the quest navigator singleton) and the markers are shown / hidden / faded.
// NavigationEntity: RTTI .?AVNavigationEntity@NavigationEntity@QuestNavigation@@ family, a CPtred with an
// MS2Ptr<ASGameEntity> (the marker clip) at +0x20. vftables: NavigationEntity 0x142ff7ee0 ... (9 slots each).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cquestnavigationmap.h"
#include "ms2/client/ms2/uiobject.h"

class NotifyObject;
class Unk_SSGNpc;
class CInteractObject;
class CPortal;
class CLiftableObject;

namespace QuestNavigation {

// One navigation marker. Slots (all virtual, overridden per target kind):
//   1 name (the map key, e.g. "npc_12")   2 clip type for the swf's "create"   3 create the marker clip under `pParent`
//   4 update the marker position / distance   5 is the target on the traced path?  6 ... of a trace context
//   7 world position of the target   8 screen y offset of the marker
class NavigationEntity : public CPtred
{
public:
    NavigationEntity();                                             // 0x140e785c0
    virtual ~NavigationEntity();                                    //  0 0x140e78640 (??_G 0x140e7c370)
    // @0x140e7c910
    virtual CString vfunc_1() { return ""; }                        //  1
    // @0x140e7c810
    virtual CString vfunc_2() { return ""; }                        //  2
    virtual int vfunc_3(AScript* pParent);                          //  3 0x140e786a0
    virtual void vfunc_4(const TraceResult* pResult);               //  4 0x140e78870
    virtual int vfunc_5(const TraceResult* pResult);                //  5 0x140e789d0 0
    virtual int vfunc_6(const TraceContext* pContext);              //  6 0x140e789f0 0
    virtual Unk_StreamPoint vfunc_7();                              //  7 0x140e78a10 the zero point
    virtual float vfunc_8();                                        //  8 0x140e78a40

    int m_18;                                                       // +0x18 shown
    float m_1c;                                                     // +0x1c alpha
    MS2Ptr<ASGameEntity> m_20;                                      // +0x20 the marker clip
};
MS2_CHECK_SIZE(NavigationEntity, 0x30);

// The player's own arrow in the HUD ("PcHud"): shows the distance to the traced target.
class PcHudNavigationEntity : public NavigationEntity
{
public:
    PcHudNavigationEntity();                                        // 0x140e78a80
    virtual ~PcHudNavigationEntity();                               //  0 0x140e78ac0 (??_G 0x140e7c3f0)
    // @0x140e7c950
    virtual CString vfunc_1() { return "PcHud"; }                   //  1
    // @0x140e7c890
    virtual CString vfunc_2() { return "pc"; }                      //  2
    virtual void vfunc_4(const TraceResult* pResult);               //  4 0x140e78b40 distance text
    virtual int vfunc_5(const TraceResult* pResult);                //  5 0x140e78af0
    virtual Unk_StreamPoint vfunc_7();                              //  7 0x140e78c40
    virtual float vfunc_8();                                        //  8 0x140e78cc0
};
MS2_CHECK_SIZE(PcHudNavigationEntity, 0x30);

class NpcNavigationEntity : public NavigationEntity
{
public:
    NpcNavigationEntity(efd::SmartPointer<Unk_SSGNpc> spNpc);       // 0x140e78d00 (by value: the ctor destroys it)
    virtual ~NpcNavigationEntity();                                 //  0 0x140e78d80 (??_G 0x140e7c3b0)
    virtual CString vfunc_1();                                      //  1 0x140e78db0 "npc_{0}"
    // @0x140e7c850
    virtual CString vfunc_2() { return "target"; }                  //  2
    virtual int vfunc_5(const TraceResult* pResult);                //  5 0x140e78e00
    virtual int vfunc_6(const TraceContext* pContext);              //  6 0x140e78f50
    virtual Unk_StreamPoint vfunc_7();                              //  7 0x140e79010
    virtual float vfunc_8();                                        //  8 0x140e790f0

    int m_30;                                                       // +0x30 npc object id
    unsigned m_34;                                                  // +0x34 npc id
};
MS2_CHECK_SIZE(NpcNavigationEntity, 0x38);

class InteractNavigationEntity : public NavigationEntity
{
public:
    InteractNavigationEntity(CInteractObject* pObject);             // 0x140e79140
    virtual ~InteractNavigationEntity();                            //  0 0x140e791f0 (??_G 0x140e7c2f0)
    virtual CString vfunc_1();                                      //  1 0x140e79230 "interact_{0}"
    // @0x140e7c790
    virtual CString vfunc_2() { return "target"; }                  //  2
    virtual int vfunc_5(const TraceResult* pResult);                //  5 0x140e79280
    virtual int vfunc_6(const TraceContext* pContext);              //  6 0x140e79450
    virtual Unk_StreamPoint vfunc_7();                              //  7 0x140e79590

    int m_30;                                                       // +0x30 interact object id
    CStringA m_38;                                                  // +0x38 interact object name
};
MS2_CHECK_SIZE(InteractNavigationEntity, 0x40);

class LiftableNavigationEntity : public NavigationEntity
{
public:
    LiftableNavigationEntity(CLiftableObject* pObject);             // 0x140e79670
    virtual ~LiftableNavigationEntity();                            //  0 0x140e79720 (??_G 0x140e7c330)
    virtual CString vfunc_1();                                      //  1 0x140e79760 "liftable_{0}"
    // @0x140e7c7d0
    virtual CString vfunc_2() { return "target"; }                  //  2
    virtual int vfunc_5(const TraceResult* pResult);                //  5 0x140e797b0
    virtual int vfunc_6(const TraceContext* pContext);              //  6 0x140e799b0
    virtual Unk_StreamPoint vfunc_7();                              //  7 0x140e79b20

    int m_30;                                                       // +0x30 liftable id
    CStringA m_38;                                                  // +0x38 liftable name
};
MS2_CHECK_SIZE(LiftableNavigationEntity, 0x40);

class PortalNavigationEntity : public NavigationEntity
{
public:
    PortalNavigationEntity(CPortal* pPortal);                       // 0x140e79c30
    virtual ~PortalNavigationEntity();                              //  0 0x140e79c80 (??_G 0x140e7c430)
    virtual CString vfunc_1();                                      //  1 0x140e79cb0 "portal_{0}"
    // @0x140e7c8d0
    virtual CString vfunc_2() { return "portal"; }                  //  2
    virtual int vfunc_5(const TraceResult* pResult);                //  5 0x140e79d00
    virtual Unk_StreamPoint vfunc_7();                              //  7 0x140e79e50

    int m_30;                                                       // +0x30 portal id
};
MS2_CHECK_SIZE(PortalNavigationEntity, 0x38);

} // namespace QuestNavigation

typedef ATL::CAtlMap<CStringA, MS2Ptr<QuestNavigation::NavigationEntity>, ATL::CStringElementTraits<CStringA> > QuestNavigationMap;

class UIQuestNavigation : public UIObject
{
public:
    UIQuestNavigation();                                            // 0x140e79f20
    virtual ~UIQuestNavigation();                                   //  0 0x140e7a530 (??_G 0x140e7c470)
    virtual CString GetTypeName();                                      //  1 0x140e7aa40 "QuestNavigation"
    virtual void vfunc_2();                                         //  2 0x140e7aa90 load the swf
    virtual void vfunc_3();                                         //  3 0x140e7aac0 clear the markers, unload
    virtual void vfunc_15();                                        // 15 0x140e7ac40 per-frame update
    virtual void OnLoadComplete();                                  // 22 0x140e7ab40 create the clips of the queued entities
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e7af40
    // @0x140e7cb60
    virtual int vfunc_48() { return 0x4f3c; }                       // 48

    void FUN_140e7af90(NotifyObject* pNotify);                      // NotifyAddNpc
    void FUN_140e7b130(NotifyObject* pNotify);                      // NotifyRemoveNpc
    void FUN_140e7b290(NotifyObject* pNotify);                      // NotifyAddInteract
    void FUN_140e7b430(NotifyObject* pNotify);                      // NotifyAddLiftable
    void FUN_140e7b640(NotifyObject* pNotify);                      // NotifyCompleteMyPC: the "PcHud" arrow
    void FUN_140e7b720(NotifyObject* pNotify);                      // NotifyAddPortal
    int FUN_140e7b890(MS2Ptr<QuestNavigation::NavigationEntity> spEntity);   // addChild (by value: callee destroys)
    int FUN_140e7ba00(MS2Ptr<QuestNavigation::NavigationEntity> spEntity);   // removeChild

private:
    MS2_LAYOUT_FRIEND;
    QuestNavigationMap m_entities;                                  // +0x68 name -> entity
};
MS2_CHECK_SIZE(UIQuestNavigation, 0xb0);
MS2_CHECK_OFFSET(UIQuestNavigation, m_entities, 0x68);
