// cguideaction.h - PLACEHOLDER for the guide-quest action classes (RTTI .?AVCGuideAction@@ and its subclasses): the
// ClassObject-derived steps a guide entity runs (an XML loader in vfunc_2, start in vfunc_3, stop in vfunc_4, "done" in
// vfunc_5), each registered by name in the ClassObject factory ("CGuideAction" + the XML "type" attribute). Owning unit
// client\ms2\guideaction.cpp (.text$di 0x1400f1f60-0x1400f27b0, .text$mn 0x141382b90-0x1413892f0): base ctor
// 0x141382d20, dtor 0x141382d60, slots 2..5 at 0x141382d90..0x141382dd0; the subclass ctors / dtors are implicit
// (0x141386f70.. / 0x1413876c0..). Layouts proven from the operator new sizes and the loaders. NOT an original header;
// member names come from the XML attribute names. Append new members / helpers here.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"

class Unk_140165cf0;
class NotifyObject;

// 0x18.
class CGuideAction : public ClassObject
{
public:
    CGuideAction();                                         // 0x141382d20
    virtual ~CGuideAction();                                // 0 0x141382d60
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141382d90: XML loader
    virtual void vfunc_3();                                 // 3 0x141382db0: start
    virtual void vfunc_4();                                 // 4 0x141382dc0: stop
    virtual int vfunc_5();                                  // 5 0x141382dd0: done (1)
};
MS2_CHECK_SIZE(CGuideAction, 0x18);

// The action of an <action> element: the class "CGuideAction" + its "type" attribute, loaded from the element.
MS2Ptr<CGuideAction> FUN_141382b90(Unk_140165cf0* pElem);  // 0x141382b90

// 0x20. Maximizes or restores the minimap.
class CGuideActionMinimapMaximize : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141382df0
    virtual CStringW vfunc_1();                             // 1 0x141382e50
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141382ea0
    virtual void vfunc_3();                                 // 3 0x141382ef0

    int m_isOn;                                             // +0x18
};
MS2_CHECK_SIZE(CGuideActionMinimapMaximize, 0x20);

// 0x28. Opens a dialog by ui class id, or by name when the id is 0.
class CGuideActionOpenDialog : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141382f50
    virtual CStringW vfunc_1();                             // 1 0x141382fb0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141383000
    virtual void vfunc_3();                                 // 3 0x141383070

    unsigned m_dialogID;                                    // +0x18
    CStringA m_dialogName;                                  // +0x20
};
MS2_CHECK_SIZE(CGuideActionOpenDialog, 0x28);

// 0x40. Spawns an effect file at every <cube> (position, rotation in degrees, scale) and removes them on stop.
class CGuideActionEffect : public CGuideAction
{
public:
    // 0x20. The ctor 0x1413874d0 is implicit.
    struct Cube
    {
        Unk_StreamPoint m_pos;                              // +0x00
        Unk_StreamPoint m_rotate;                           // +0x0c degrees
        float m_scale;                                      // +0x18
        int m_handle;                                       // +0x1c the spawned effect (0: none)
    };

    static ClassObject* CreateObject();                     // 0x141383100
    virtual CStringW vfunc_1();                             // 1 0x141383160
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413831b0
    virtual void vfunc_3();                                 // 3 0x1413832d0
    virtual void vfunc_4();                                 // 4 0x141383490

    CStringA m_path;                                        // +0x18
    ATL::CAtlArray<Cube> m_cubes;                           // +0x20
};
MS2_CHECK_SIZE(CGuideActionEffect::Cube, 0x20);
MS2_CHECK_SIZE(CGuideActionEffect, 0x40);

// 0x20. Holds one of the client's numbered limits (a use count per limit kind) while running.
class CGuideActionLimit : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141383550
    virtual CStringW vfunc_1();                             // 1 0x1413835b0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141383600
    virtual void vfunc_3();                                 // 3 0x141383700
    virtual void vfunc_4();                                 // 4 0x141383730

    int m_limit;                                            // +0x18
};
MS2_CHECK_SIZE(CGuideActionLimit, 0x20);

int FUN_141383760(int nLimit);                              // 0x141383760 the limit is held
void FUN_1413837a0(int nLimit);                             // 0x1413837a0 hold
void FUN_1413837e0(int nLimit);                             // 0x1413837e0 release

// 0x20. Holds a dialog-name limit while running.
class CGuideActionLimitDialog : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141383860
    virtual CStringW vfunc_1();                             // 1 0x1413838c0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141383910
    virtual void vfunc_3();                                 // 3 0x1413839d0
    virtual void vfunc_4();                                 // 4 0x141383a20

    CStringA m_dialogName;                                  // +0x18
};
MS2_CHECK_SIZE(CGuideActionLimitDialog, 0x20);

int FUN_141383a70(CStringA strName);                        // 0x141383a70 the dialog is limited
void FUN_141383b00(CStringA strName);                       // 0x141383b00 hold
void FUN_141383b90(CStringA strName);                       // 0x141383b90 release

// 0x48. Shows the <text> tutorial balloons of a guide entity one after the other.
class CGuideActionUITutorial : public CGuideAction
{
public:
    struct Step
    {
        unsigned m_textId;                                  // +0x00
        unsigned m_waitTick;                                // +0x04 the minimum display time
    };

    static ClassObject* CreateObject();                     // 0x141383c00
    virtual CStringW vfunc_1();                             // 1 0x141383c60
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141383cb0
    virtual void vfunc_3();                                 // 3 0x141383d90
    virtual void vfunc_4();                                 // 4 0x141383e40
    virtual int vfunc_5();                                  // 5 0x141383ea0
    void FUN_141383f50();                                   // 0x141383f50 next step once the current one has waited

    int m_entityId;                                         // +0x18
    unsigned m_tick;                                        // +0x1c the start of the current step (0: not started)
    unsigned m_index;                                       // +0x20
    ATL::CAtlArray<Step> m_steps;                           // +0x28
};
MS2_CHECK_SIZE(CGuideActionUITutorial::Step, 8);
MS2_CHECK_SIZE(CGuideActionUITutorial, 0x48);

// The input device a text action is restricted to (commonfiles enum parser 0x14021ade0: "Keyboard" / "GamePad").
enum CGuideControllerType
{
    GuideController_Any = 0,
    GuideController_Keyboard = 1,
    GuideController_GamePad = 2,
};

// 0x28. Base of the guide text actions.
class CGuideActionUITextBase : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141384080
    virtual CStringW vfunc_1();                             // 1 0x1413840e0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141384130
    bool FUN_141384200();                                   // 0x141384200 the controller type matches the gamepad option

    int m_entityId;                                         // +0x18
    unsigned m_textId;                                      // +0x1c
    int m_isNotClose;                                       // +0x20
    CGuideControllerType m_controllerType;                  // +0x24
};
MS2_CHECK_SIZE(CGuideActionUITextBase, 0x28);

// 0x28. The summary text of the guide panel.
class CGuideActionUISummary : public CGuideActionUITextBase
{
public:
    static ClassObject* CreateObject();                     // 0x1413842a0
    virtual CStringW vfunc_1();                             // 1 0x141384300
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141384350
    virtual void vfunc_3();                                 // 3 0x141384390
    virtual void vfunc_4();                                 // 4 0x1413843f0
    virtual int vfunc_5();                                  // 5 0x141384450
};
MS2_CHECK_SIZE(CGuideActionUISummary, 0x28);

// 0x40. A guide arrow at a world offset.
class CGuideActionUIArrow : public CGuideActionUITextBase
{
public:
    static ClassObject* CreateObject();                     // 0x1413844b0
    virtual CStringW vfunc_1();                             // 1 0x141384510
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141384560
    virtual void vfunc_3();                                 // 3 0x141384680
    virtual void vfunc_4();                                 // 4 0x1413847f0

    Unk_StreamPoint m_offset;                               // +0x28
    unsigned m_direction;                                   // +0x34
    unsigned m_align;                                       // +0x38
};
MS2_CHECK_SIZE(CGuideActionUIArrow, 0x40);

// 0x28. A text tip.
class CGuideActionUITextTip : public CGuideActionUITextBase
{
public:
    static ClassObject* CreateObject();                     // 0x141384850
    virtual CStringW vfunc_1();                             // 1 0x1413848b0
    virtual void vfunc_3();                                 // 3 0x141384900
    virtual void vfunc_4();                                 // 4 0x141384960
};
MS2_CHECK_SIZE(CGuideActionUITextTip, 0x28);

// 0xa8. A guide arrow pointing at a dialog (or a child element of it, or a custom position kind).
class CGuideActionUIArrowDialog : public CGuideActionUIArrow
{
public:
    static ClassObject* CreateObject();                     // 0x1413849c0
    virtual CStringW vfunc_1();                             // 1 0x141384a20
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141384a70
    virtual void vfunc_3();                                 // 3 0x141384bd0

    unsigned m_dialogID;                                    // +0x40
    CStringA m_dialogName;                                  // +0x48
    int m_childIndex;                                       // +0x50
    ATL::CAtlArray<CStringA> m_childName;                   // +0x58 the "."-separated element path
    ATL::CAtlArray<CStringA> m_focusDialogName;             // +0x78
    CStringA m_customPosType;                               // +0x98
    int m_customPosValue;                                   // +0xa0
};
MS2_CHECK_SIZE(CGuideActionUIArrowDialog, 0xa8);

// 0x20. Removes a guide arrow on start (isAtOpen) or on stop.
class CGuideActionUIArrowClose : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141384dd0
    virtual CStringW vfunc_1();                             // 1 0x141384e30
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141384e80
    virtual void vfunc_3();                                 // 3 0x141384f00
    virtual void vfunc_4();                                 // 4 0x141384f50

    unsigned m_entityId;                                    // +0x18
    int m_isAtOpen;                                         // +0x1c
};
MS2_CHECK_SIZE(CGuideActionUIArrowClose, 0x20);

class CGuideCondition;

// 0x60. Runs the nested <actions> once all nested <conditions> pass.
class CGuideActionConditionAction : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141384fa0
    virtual CStringW vfunc_1();                             // 1 0x141385000
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141385050
    virtual void vfunc_3();                                 // 3 0x1413851b0
    virtual int vfunc_5();                                  // 5 0x1413852b0

    int m_started;                                          // +0x18
    ATL::CAtlArray<MS2Ptr<CGuideCondition> > m_conditions;  // +0x20
    ATL::CAtlArray<MS2Ptr<CGuideAction> > m_actions;        // +0x40
};
MS2_CHECK_SIZE(CGuideActionConditionAction, 0x60);

// 0x20. Equips (shows) the tutorial weapon while running.
class CGuideActionEquipWeaponTutorial : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141385350
    virtual CStringW vfunc_1();                             // 1 0x1413853b0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141385400
    virtual void vfunc_3();                                 // 3 0x141385460
    virtual void vfunc_4();                                 // 4 0x141385490

    int m_isUse;                                            // +0x18
};
MS2_CHECK_SIZE(CGuideActionEquipWeaponTutorial, 0x20);

// 0x20. Finishes another guide entity by id.
class CGuideActionForceClear : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x1413854c0
    virtual CStringW vfunc_1();                             // 1 0x141385520
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141385570
    virtual void vfunc_3();                                 // 3 0x1413855f0

    int m_id;                                               // +0x18
};
MS2_CHECK_SIZE(CGuideActionForceClear, 0x20);

// 0x48. Plays trigger cameras (optionally with the cinematic cut-scene bars and a skip button).
class CGuideActionSequenceCamera : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141385620
    virtual CStringW vfunc_1();                             // 1 0x141385680
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413856d0
    virtual void vfunc_3();                                 // 3 0x141385770
    virtual void vfunc_4();                                 // 4 0x141385a40
    virtual int vfunc_5();                                  // 5 0x141385b50
    void FUN_141385ba0(NotifyObject* pNotify);              // 0x141385ba0 "NotifyCutSceneCinematicSkip"

    int m_isUseCinematicCutScene;                           // +0x18
    ATL::CAtlArray<int> m_triggerCameraId;                  // +0x20
    float m_endInterpolationTime;                           // +0x40
    int m_skipped;                                          // +0x44
};
MS2_CHECK_SIZE(CGuideActionSequenceCamera, 0x48);

// 0x20. Opens the smart-recommend notice with an offer.
class CGuideActionSmartRecommend : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141385bc0
    virtual CStringW vfunc_1();                             // 1 0x141385c20
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141385c70
    virtual void vfunc_3();                                 // 3 0x141385cd0

    unsigned m_recommendCode;                               // +0x18
};
MS2_CHECK_SIZE(CGuideActionSmartRecommend, 0x20);

// 0x20. Raises a server trigger event.
class CGuideActionServerTriggerEvent : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141385d50
    virtual CStringW vfunc_1();                             // 1 0x141385db0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141385e00
    virtual void vfunc_3();                                 // 3 0x141385e60

    unsigned m_eventID;                                     // +0x18
};
MS2_CHECK_SIZE(CGuideActionServerTriggerEvent, 0x20);

// 0x20. Enables or disables a game menu entry.
class CGuideActionGameMenuLimit : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141385ed0
    virtual CStringW vfunc_1();                             // 1 0x141385f30
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141385f80
    virtual void vfunc_3();                                 // 3 0x141385ff0

    unsigned m_menuID;                                      // +0x18
    int m_enabled;                                          // +0x1c
};
MS2_CHECK_SIZE(CGuideActionGameMenuLimit, 0x20);

// 0x18. Asks the server for the tutorial item.
class CGuideActionRequestTutorialItem : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141386070
    virtual CStringW vfunc_1();                             // 1 0x1413860d0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141386120
    virtual void vfunc_3();                                 // 3 0x141386150
};
MS2_CHECK_SIZE(CGuideActionRequestTutorialItem, 0x18);

// 0x50. Shows a side popup talk (an NPC balloon in the corner).
class CGuideActionSideNpcTalk : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x1413861a0
    virtual CStringW vfunc_1();                             // 1 0x141386200
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x141386250
    virtual void vfunc_3();                                 // 3 0x141386360

    int m_uiType;                                           // +0x18
    CStringA m_usm;                                         // +0x20
    unsigned m_scriptID;                                    // +0x28
    CStringA m_illust;                                      // +0x30
    unsigned m_duration;                                    // +0x38 ms (3000)
    CStringA m_voice;                                       // +0x40
    CStringA m_sound;                                       // +0x48
};
MS2_CHECK_SIZE(CGuideActionSideNpcTalk, 0x50);

// 0x18. Tells the server the tutorial is cleared.
class CGuideActionClearTutorial : public CGuideAction
{
public:
    static ClassObject* CreateObject();                     // 0x141386550
    virtual CStringW vfunc_1();                             // 1 0x1413865b0
    virtual void vfunc_3();                                 // 3 0x141386600
};
MS2_CHECK_SIZE(CGuideActionClearTutorial, 0x18);
