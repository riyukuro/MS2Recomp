// cquestnavigator.h - PLACEHOLDER for CQuestNavigator (RTTI .?AVCQuestNavigator@@, 0xc0 bytes). NOT an original header.
// Bases: TSingleton<CQuestNavigator> at +0x0, UIQuestEventListener at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; it draws the quest guide beam: the effect node of the
// navigation beam (m_10), the traced destination of the selected quest (m_18) and the maps / npcs / objects the selected
// quest leads to (m_70). Bodies in unnamed/unit_140c99700-like unit ?\questnavigator.cpp.
#pragma once

#include <NiSmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"
#include "ms2/placeholder/cquestnavigationmap.h"
#include "ms2/placeholder/nipoint3.h"

class NiNode;
class NotifyObject;

class CQuestNavigator : public TSingleton<CQuestNavigator>, public UIQuestEventListener
{
public:
    CQuestNavigator();                                      // 0x140c99700
    virtual ~CQuestNavigator();                             // 0x140c99990

    // UIQuestEventListener slots (the listener base names them vfunc_o178_<n>); the quest is a CQuest*.
    virtual void vfunc_o178_1(void* pQuest);                // 0x140c99c40 accepted / progress
    virtual void vfunc_o178_2(void* pQuest);                // 0x140c99d20
    virtual void vfunc_o178_3(void* pQuest);                // 0x140c99d80
    virtual void vfunc_o178_5(void* pQuest);                // 0x140c99da0
    virtual void vfunc_o178_6(void* pQuest);                // 0x140c99be0
    virtual void vfunc_o178_7(int nQuestId, int a2);        // 0x140c99e00

    void FUN_140c99e30();                                   // drop the beam effect from its parent
    void FUN_140c99ee0();                                   // per frame: re-trace the selected quest and move the beam
    void OnCreateMyPC(NotifyObject* pNotify);               // 0x140c9a0e0 "NotifyCreateMyPC"
    void OnCompleteMyPC(NotifyObject* pNotify);             // 0x140c9a1c0 "NotifyCompleteMyPC"
    void SelectQuest(int nQuestId);                         // 0x140c9a420
    int IsSelected(int nQuestId);                           // 0x140c9a490
    int FUN_140c9a4c0(QuestNavigation::TraceResult* pResult);   // trace the quest to its nearest target (0 = found)
    QuestNavigation::TraceResult* Result();                 // 0x140c9ac60
    void FUN_140c9ac80();                                   // rebuild m_70 from the tracked quests
    QuestNavigation::TraceContext* Context();               // 0x140c9adf0
    int HasMap(int nMapId);                                // 0x140c9ae10
    int HasNpc(int nNpcId);                                // 0x140c9ae80
    int HasInteractObject(int nObjectId);                  // 0x140c9aef0
    bool FUN_140c9af60();                                   // the beam may be shown
    Vector3 FUN_140c9b0a0(const Vector3& pos);   // the beam's end point towards pos
    CStringW FUN_140c9b150(const Vector3& pos);     // the distance text to pos

private:
    MS2_LAYOUT_FRIEND;
    NiPointer<NiNode> m_10;                                 // +0x10 the beam effect
    QuestNavigation::TraceResult m_18;                      // +0x18
    int m_68;                                               // +0x68 the context needs a rebuild
    int m_6c;
    QuestNavigation::TraceContext m_70;                     // +0x70
};
MS2_CHECK_SIZE(CQuestNavigator, 0xc0);
