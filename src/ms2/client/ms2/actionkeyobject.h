// actionkeyobject.h - ActionKeyObject (RTTI .?AVActionKeyObject@@, vftable 0x142db0250, 13 slots) and its 26 subclasses:
// the context actions bound to the action key (portal, talk, interact, gathering, cubes, ...). MyPC owns one
// Unk_ActionKeyManager at +0x1338 (ctor 0x140951c70) that maps an action type to its action object and polls
// them every 100 ms. NOT an original header; the class names are the exe's (RTTI), the members are inferred.
// Owning unit: ?\actionkeyobject.cpp.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

#include <efd/SmartPointer.h>
#include <egf/EntityID.h>

class Cube;
class CInteractObject;
class CInteractGatheringObject;
class CHomemadeCubeObject;
class CReactor;
class PCBase;
namespace egf { class Entity; }
class Unk_AkoPortal;
class Unk_WsC_GameObj;
class CMsgBoxData;

// The point an action wants the camera / player to face; returned by ActionKeyObject::vfunc_12.
struct Unk_AkoTarget
{
    // @0x140963d20
    Unk_AkoTarget() { m_bValid = false; }
    // @0x140963cd0
    Unk_AkoTarget(const Vector3& pt) { m_pos = pt; m_bValid = true; }

    bool m_bValid;                      // +0x00
    Vector3 m_pos;              // +0x04
};
MS2_CHECK_SIZE(Unk_AkoTarget, 0x10);

class ActionKeyObject : public CPtred
{
public:
    ActionKeyObject();
    virtual ~ActionKeyObject();                         // 0
    virtual int vfunc_1();                              // 1: is the action available now
    virtual void vfunc_2();                             // 2: run the action
    virtual void vfunc_3();                             // 3: the action stops being the current one
    virtual int vfunc_4();                              // 4: the action may become the current one
    virtual int vfunc_5();                              // 5: the action type (0x1e: none)
    virtual CStringW vfunc_6();                         // 6: tooltip text
    virtual CStringW vfunc_7();                         // 7: tooltip title
    virtual CStringW vfunc_8();                         // 8: key icon name
    virtual void vfunc_9();                             // 9
    virtual int vfunc_10();                             // 10: the tooltip must be refreshed
    virtual bool vfunc_11();                            // 11: may be run by the key
    virtual Unk_AkoTarget vfunc_12();                   // 12: the action's target point
};
MS2_CHECK_SIZE(ActionKeyObject, 0x18);

typedef ATL::CRBMap<int, MS2Ptr<ActionKeyObject>, ATL::CDefaultElementTraits<int> > Unk_ActionKeyMap;   // key passed by const int&

// MyPC +0x1338. Real name unknown.
class Unk_ActionKeyManager
{
public:
    Unk_ActionKeyManager();                             // 0x140951c70
    ~Unk_ActionKeyManager();                            // 0x140952e70
    void FUN_140952ef0();                               // per-frame update: pick the current action
    void FUN_140953310();                               // run the current action
    bool FUN_140953410();                               // run the current action if it may be run by the key
    int GetCur();                                // the current action type
    ActionKeyObject* FUN_140953550();                   // the current action
    void FUN_1409535c0();                               // drop the current action (re-poll in 2 s)
    int IsEnabled();                                // polling enabled
    void SetEnabled(int bEnable);
    void FUN_1409536d0();                               // vfunc_9 of the current action
    Unk_ActionKeyMap* FUN_140953770();                  // the action set for the player's state

private:
    MS2_LAYOUT_FRIEND;
    int m_nCur;                                         // +0x00 current action type (0x1e: none)
    Unk_ActionKeyMap m_actions;                         // +0x08
    Unk_ActionKeyMap m_actionsCubeMode;                 // +0x38 (cube craft mode: MyPC::FUN_1416595d0)
    Unk_ActionKeyMap m_actionsFishing;                  // +0x68 (CFishingManager active)
    unsigned m_nNextTick;                               // +0x98
    int m_bEnabled;                                     // +0x9c
};
MS2_CHECK_SIZE(Unk_ActionKeyManager, 0xa0);

// ---- the actions (in the vftable order of the exe) -------------------------------------------------------------------
class TaxiStationAction : public ActionKeyObject
{
public:
    TaxiStationAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
};
MS2_CHECK_SIZE(TaxiStationAction, 0x18);

class FishingAction : public ActionKeyObject
{
public:
    FishingAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
};
MS2_CHECK_SIZE(FishingAction, 0x18);

struct PortalAction : public ActionKeyObject           // a struct in the exe (RTTI .?AUPortalAction@@)
{
public:
    PortalAction();
    ~PortalAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_4() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    Unk_AkoTarget vfunc_12() override;
    int FUN_140956110();                                // the portal moves to another field
    void FUN_140956160(int nTarget, int nPortalId);     // move through the portal by its type
    void FUN_140956290(int nPortalId);                  // the dungeon room dialog (type 8)
    void SendRoomDungeon();                               // request the home move (type 9)
    void FUN_140956370(unsigned nTarget, unsigned nPortalId);     // move to another field (confirmation box when asked)
    void FUN_1409569a0(int nPortalId, int nMode);       // the dungeon room dialog in a mode (types 0xc, 0xe)
    void FUN_140956a20(int nPortalId, int nArg);        // the dungeon room dialog (type 0x11)
    void FUN_140956aa0(Cube* pCell, int nTarget, int nPortalId);   // move inside a house
    bool FUN_140956be0(int nButton, const CMsgBoxData& data);   // the move confirmation box answer
    CStringW FUN_140956e40();                           // the portal's name

private:
    MS2_LAYOUT_FRIEND;
    efd::SmartPointer<egf::Entity> m_spEntity;          // +0x18 the portal's entity
    void* m_unk_20;                                     // +0x20 unused
    MS2Ptr<Unk_AkoPortal> m_spPortal;                   // +0x28 the portal's field object
};
MS2_CHECK_SIZE(PortalAction, 0x38);

class BuyCubeAction : public ActionKeyObject
{
public:
    BuyCubeAction();
    ~BuyCubeAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    void FUN_1409571a0(egf::EntityID id, int bSelect);  // highlight the cube entity

private:
    MS2_LAYOUT_FRIEND;
    int m_n18;                                          // +0x18
    egf::EntityID m_id;                                 // +0x20
};
MS2_CHECK_SIZE(BuyCubeAction, 0x28);

class LiftCubeAction : public ActionKeyObject
{
public:
    LiftCubeAction();
    ~LiftCubeAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    class Unk_WsB_Lift* FUN_140957890();                // the liftable object in reach

private:
    MS2_LAYOUT_FRIEND;
    CString m_str18;                                    // +0x18
};
MS2_CHECK_SIZE(LiftCubeAction, 0x20);

class TalkAction : public ActionKeyObject
{
public:
    TalkAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;

    int m_n18;                                          // +0x18
    int m_nNpcId;                                       // +0x1c
    CStringW m_strName;                                 // +0x20
};
MS2_CHECK_SIZE(TalkAction, 0x28);

class InteractAction : public ActionKeyObject
{
public:
    InteractAction();
    ~InteractAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    CStringW vfunc_7() override;
    Unk_AkoTarget vfunc_12() override;
    virtual int vfunc_13(CInteractObject* pObject);     // 13: the object kind is handled by this action
    CInteractObject* FUN_140958e70();                   // the usable interact object in front of the player

    CString m_strObjectId;                              // +0x18
    int m_n20;                                          // +0x20
};
MS2_CHECK_SIZE(InteractAction, 0x28);

class InteractNpcAction : public ActionKeyObject
{
public:
    InteractNpcAction();
    ~InteractNpcAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    void vfunc_9() override;
    bool vfunc_11() override;
    Unk_AkoTarget vfunc_12() override;
    Unk_WsC_GameObj* FUN_140959330();                   // the npc to talk to in front of the player

private:
    MS2_LAYOUT_FRIEND;
    Unk_WsC_GameObj* m_pNpc;                            // +0x18
    int m_n20;                                          // +0x20
};
MS2_CHECK_SIZE(InteractNpcAction, 0x28);

class ViewCubeMapProfileAction : public ActionKeyObject
{
public:
    ViewCubeMapProfileAction();
    ~ViewCubeMapProfileAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;

    int m_nMapId;                                       // +0x18 never initialised (new is 0x20)
};
MS2_CHECK_SIZE(ViewCubeMapProfileAction, 0x20);

class RegistUgcAction : public ActionKeyObject
{
public:
    RegistUgcAction();
    ~RegistUgcAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    void FUN_140959d70(egf::Entity* pEntity, int bSelect);  // highlight the ugc entity

private:
    MS2_LAYOUT_FRIEND;
    efd::SmartPointer<egf::Entity> m_spEntity;          // +0x18
};
MS2_CHECK_SIZE(RegistUgcAction, 0x20);

class PullObjectWeaponAction : public ActionKeyObject
{
public:
    PullObjectWeaponAction();
    ~PullObjectWeaponAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    Unk_AkoTarget vfunc_12() override;
    int FUN_140959eb0();                                // find the object weapon cube ahead

    MS2Ptr<Cube> m_spCube;                              // +0x18
    MS2Ptr<Cube> m_spCube28;                            // +0x28
};
MS2_CHECK_SIZE(PullObjectWeaponAction, 0x38);

class PutDownLiftableAction : public ActionKeyObject
{
public:
    PutDownLiftableAction();
    ~PutDownLiftableAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
};
MS2_CHECK_SIZE(PutDownLiftableAction, 0x18);

class FunctionCubeAction : public ActionKeyObject
{
public:
    FunctionCubeAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    CStringW vfunc_8() override;
    int vfunc_10() override;

protected:
    MS2_LAYOUT_FRIEND;
    CString m_str18;                                    // +0x18
    int m_n20;                                          // +0x20
    egf::EntityID m_id;                                 // +0x28
};
MS2_CHECK_SIZE(FunctionCubeAction, 0x30);

class FittingDollAction : public ActionKeyObject
{
public:
    FittingDollAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    int vfunc_10() override;

private:
    MS2_LAYOUT_FRIEND;
    int m_n18;                                          // +0x18
    egf::EntityID m_id;                                 // +0x20
};
MS2_CHECK_SIZE(FittingDollAction, 0x28);

class HoldAction : public ActionKeyObject
{
public:
    HoldAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    int vfunc_10() override;

    int m_n18;                                          // +0x18
    int m_n1c;                                          // +0x1c
    int m_nNpcId;                                       // +0x20
    float m_f24;                                        // +0x24
};
MS2_CHECK_SIZE(HoldAction, 0x28);

class HoldPCAction : public ActionKeyObject
{
public:
    HoldPCAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    int vfunc_10() override;

private:
    MS2_LAYOUT_FRIEND;
    int m_n18;                                          // +0x18
    float m_f1c;                                        // +0x1c
};
MS2_CHECK_SIZE(HoldPCAction, 0x20);

class ReleasePCAction : public ActionKeyObject
{
public:
    ReleasePCAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    int vfunc_10() override;

private:
    MS2_LAYOUT_FRIEND;
    int m_n18;                                          // +0x18
    float m_f1c;                                        // +0x1c
};
MS2_CHECK_SIZE(ReleasePCAction, 0x20);

class GatheringAction : public InteractAction
{
public:
    GatheringAction();
    ~GatheringAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    int vfunc_13(CInteractObject* pObject) override;
    CInteractGatheringObject* FUN_14095d840();          // the selected gathering object

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<CInteractGatheringObject> > m_objects;   // +0x28
};
MS2_CHECK_SIZE(GatheringAction, 0x48);

class BillBoardInteractAction : public InteractAction
{
public:
    BillBoardInteractAction();
    ~BillBoardInteractAction();
    int vfunc_5() override;
    CStringW vfunc_6() override;
    int vfunc_13(CInteractObject* pObject) override;
};
MS2_CHECK_SIZE(BillBoardInteractAction, 0x28);

class HomemadeCubeAction : public FunctionCubeAction
{
public:
    HomemadeCubeAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    CStringW vfunc_8() override;
    int vfunc_10() override;
    int FUN_14095e440(MS2Ptr<CHomemadeCubeObject> spCube);   // the cube may be used

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<CHomemadeCubeObject> > m_cubes;  // +0x30 nearby own homemade cubes
};
MS2_CHECK_SIZE(HomemadeCubeAction, 0x50);

class NurturingCubeAction : public FunctionCubeAction
{
public:
    NurturingCubeAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    CStringW vfunc_8() override;
    int vfunc_10() override;

private:
    MS2_LAYOUT_FRIEND;
    int m_n30;                                          // +0x30
};
MS2_CHECK_SIZE(NurturingCubeAction, 0x38);

class BannerAction : public ActionKeyObject
{
public:
    BannerAction();
    ~BannerAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    PCBase* FUN_14095edf0();                            // the nearest dancer in micro-game range

private:
    MS2_LAYOUT_FRIEND;
    int m_n18;                                          // +0x18
    int m_n1c;                                          // +0x1c
};
MS2_CHECK_SIZE(BannerAction, 0x20);

class ReactorAction : public ActionKeyObject
{
public:
    ReactorAction();
    ~ReactorAction();
    int vfunc_1() override;
    void vfunc_2() override;
    void vfunc_3() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;
    CStringW vfunc_7() override;
    Unk_AkoTarget vfunc_12() override;
    virtual int vfunc_13(efd::SmartPointer<CReactor> spReactor);  // 13: the local player may use the reactor
    CReactor* FUN_14095fcb0();                          // the reactor at the player's position

private:
    MS2_LAYOUT_FRIEND;
    int m_nReactorId;                                   // +0x18
    int m_n1c;                                          // +0x1c
};
MS2_CHECK_SIZE(ReactorAction, 0x20);

class QuestUserFindAction : public ActionKeyObject
{
public:
    QuestUserFindAction();
    ~QuestUserFindAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;

private:
    MS2_LAYOUT_FRIEND;
    __int64 m_n18;                                      // +0x18
    int m_n20;                                          // +0x20
};
MS2_CHECK_SIZE(QuestUserFindAction, 0x28);

class TreeWateringAction : public ActionKeyObject
{
public:
    TreeWateringAction();
    ~TreeWateringAction();
    int vfunc_1() override;
    void vfunc_2() override;
    int vfunc_5() override;
    CStringW vfunc_6() override;

private:
    MS2_LAYOUT_FRIEND;
    int m_n18;                                          // +0x18
    int m_n1c;                                          // +0x1c
};
MS2_CHECK_SIZE(TreeWateringAction, 0x20);
