// uipopupnpctalkdialog.h - UIPopupNpcTalkDialog (RTTI .?AVUIPopupNpcTalkDialog@@, 0x1e0 bytes, UIDialog + UIQuestEventListener
// at +0x178, UI id 0x4f4d, swf "PopupNpcTalkDialog"): the small npc talk popup of a field quest. It shows one line of the
// quest's talk script at a time ("setNpc", "setPortrait", "m_script", "m_next", "m_end") and, past the last line, completes
// or accepts the quest. Owning unit: ?\uipopupnpctalkdialog.cpp. Header name assumed from the unit path; member names are
// inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/scriptptr.h"     // Unk_ScriptPtr<CTalkScript> (m_188)
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class NotifyObject;
class CTalkScript;
class ASTextField;
class ASButton;

class UIPopupNpcTalkDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIPopupNpcTalkDialog();                                     // 0x140e76460
    virtual ~UIPopupNpcTalkDialog();                            //  0 0x140e76770 (??_G 0x140e77fc0)
    virtual CString GetTypeName();                                  //  1 0x140e769d0 "PopupNpcTalkDialog"
    virtual int vfunc_13();                                     // 13 0x140e76e70 click: next line
    virtual void OnLoadComplete();                              // 22 0x140e76ab0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e76af0 "onClickNext" / "onClickEnd"
    virtual void vfunc_43();                                    // 43 0x140e76db0
    virtual int vfunc_48() { return 0x4f4d; }                   // 48 0x140e78010
    virtual int vfunc_65();                                     // 65 0x140e76a20
    virtual void vfunc_67();                                    // 67 0x140e76a50 Close
    virtual void vfunc_o178_1(void*);                           // UIQuestEventListener 1 0x140e76cd0
    virtual void vfunc_o178_3(void*);                           // UIQuestEventListener 3 0x140e76d50

    void FUN_140e770a0(NotifyObject* pNotify);                  // 0x140e770a0 "NotifyFadeInComplete": open the first field quest of the map
    void FUN_140e771b0(NotifyObject* pNotify);                  // 0x140e771b0 "NotifyChangeMyPC": forget the opened quests
    void FUN_140e771e0(int nQuest);                             // 0x140e771e0 start the talk of a quest
    void FUN_140e77300();                                       // 0x140e77300
    int FUN_140e77330();                                        // 0x140e77330 show the current line; 0 no quest, 1 shown, 2 past the end
    int FUN_140e77b80(int nQuest);                              // 0x140e77b80 quest is startable on this map

private:
    MS2_LAYOUT_FRIEND;
    int m_180;                          // +0x180 current line
    int m_184;                          // +0x184 quest id
    Unk_ScriptPtr<CTalkScript> m_188;   // +0x188 its talk script
    ATL::CAtlMap<unsigned, int> m_198;  // +0x198 quests already opened
};
MS2_CHECK_SIZE(UIPopupNpcTalkDialog, 0x1e0);
MS2_CHECK_OFFSET(UIPopupNpcTalkDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIPopupNpcTalkDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIPopupNpcTalkDialog, m_198, 0x198);
