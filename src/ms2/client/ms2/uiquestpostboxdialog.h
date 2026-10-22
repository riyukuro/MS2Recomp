// Recovered UIQuestPostBoxDialog (UI type 0x4f56 "QuestPostBoxDialog"): the quest post box list. RTTI vftables: dialog
// at +0, IMessageListener at +0x18, UIQuestEventListener at +0x178. File name assumed (the class name).
// Unnamed helpers and members use invented names.
#pragma once
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"        // UIQuestEventListener (13 slots)

class Unk_PostBoxList;
class UIQuestPostBoxDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIQuestPostBoxDialog();                             // 0x140e7f2e0
    virtual ~UIQuestPostBoxDialog();                    //  0 0x140e7f390 (??_G 0x140e7fd00)
    virtual CString GetTypeName();                          //  1 0x140e7f400
    virtual int vfunc_65();                             // 65 0x140e7f450
    virtual void vfunc_67();                            // 67 0x140e7f480
    virtual void OnLoadComplete();                      // 22 0x140e7f4e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e7f540
    virtual void vfunc_o178_1(void* pQuest);            // quest accepted: close when the quest flag +0x33 is set
    virtual int vfunc_48() { return 0x4f56; }           // 48 (COMDAT 0x140e7fd40)

    void FUN_140e7f660();                               // fill "m_list" with the quests, sorted by kind
    void FUN_140e7f920(int nQuest);                     // onSelectPost: talk to the quest's npc
    CString FUN_140e7fb90(int nQuest);                  // list icon name of a quest kind
    MS2Ptr<Unk_PostBoxList> FUN_140c02900(const CString& strName);     // bind a list child
};
MS2_CHECK_SIZE(UIQuestPostBoxDialog, 0x180);
