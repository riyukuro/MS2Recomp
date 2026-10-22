// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uichatemoticondialog.h (name
// assumed: the class name; the exe has no assert path for it other than uichatemoticondialog.cpp).
//
// UIChatEmoticonDialog is the chat emoticon picker ("ChatEmoticonDialog", UI type 0x4f80): a row of category tabs
// (the swf "buildTab" call) and a grid of emoticons of the selected tab (the swf "buildItem" call). The tabs are the
// categories of the emoticon table (Table/chatEmoticon.xml) of the packs the player owns, plus the favourite tab -1.
// A pack the player just received is flagged "new" until its tab is opened. Clicking an emoticon posts a
// NotifyChatEmoticonSelected that the chat input picks up; the shop button opens the Merat market on the emoticon page.
// RTTI .?AVUIChatEmoticonDialog@@, 0x1c8 bytes, vftables at +0 and +0x18 (IMessageListener).
// Also defined here: UIChatEmoticonInfo (RTTI, 0x20) and NotifyChatEmoticonSelected (RTTI, 0x28).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>
#include <list>
#include <map>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/uidialog.h"

class ASData;

// One emoticon cell of a tab: the emoticon id and whether it is flagged "new" (its pack was just received).
// The constructor is the exe's COMDAT at 0x140bd5220; the destructor is the implicit one (only ~CPtred).
class UIChatEmoticonInfo : public CPtred
{
public:
    UIChatEmoticonInfo() : m_bNew(false), m_nEmoticonId(0) {}       // 0x140bd5220 (COMDAT)
    virtual ~UIChatEmoticonInfo();                                  //  0 0x140bd5510 (??_G 0x140bd5b60)

    bool m_bNew;                        // +0x18
    int m_nEmoticonId;                  // +0x1c
};
MS2_CHECK_SIZE(UIChatEmoticonInfo, 0x20);

// The "an emoticon was picked" notice: the chat window that was active and the emoticon id. Posted through the notify
// manager (FUN_140939a10) and consumed by the chat input.
class NotifyChatEmoticonSelected : public NotifyObject
{
public:
    NotifyChatEmoticonSelected(const CStringW& strTarget, int nEmoticonId);     // 0x140bd51b0
    virtual ~NotifyChatEmoticonSelected();                          //  0 0x140bd5470 (??_G 0x140bd5ae0)
    virtual CStringW vfunc_1();                                     //  1 0x140db5520 (notify name; another unit)

    CStringW m_strTarget;               // +0x18
    int m_nEmoticonId;                  // +0x20
};
MS2_CHECK_SIZE(NotifyChatEmoticonSelected, 0x28);

// One tab of the dialog: a category id. (A distinct element type: the exe has its own copy of every list member for this
// list, which the shared std::list<int> symbols cannot name.)
struct UIChatEmoticonTab
{
    int m_nCategoryId;
};

class UIChatEmoticonDialog : public UIDialog
{
public:
    UIChatEmoticonDialog();                                         // 0x140bd0e90
    virtual ~UIChatEmoticonDialog();                                //  0 0x140bd54a0 (??_G 0x140bd5b20)
    virtual CString vfunc_1();                                      //  1 0x140bd0f60 "ChatEmoticonDialog"
    virtual int vfunc_13();                                         // 13 0x140bd11a0 closed ? UIDialog::vfunc_13() : 0
    virtual void OnLoadComplete();                                  // 22 0x140bd1080
    virtual void vfunc_26();                                        // 26 0x140bd1160
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x140bd1540 onSelectTab / onSelectEmoticon / onClickShopButton
    virtual int vfunc_48() { return 0x4f80; }                       // 48 (COMDAT 0x140bd5bc0)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140bd11e0 "getTooltip": the pack's expiry
    virtual int vfunc_65();                                         // 65 0x140bd0fb0
    virtual void vfunc_67();                                        // 67 0x140bd0fe0
    virtual void vfunc_72();                                        // 72 0x140bd1000 per-frame: rebuild when a pack expires

    void FUN_140bd1720();                                           // send the tab list ("buildTab")
    void FUN_140bd1a60();                                           // send the emoticons of the selected tab ("buildItem")
    void FUN_140bd1fc0();                                           // rebuild the tab model from the owned packs
    void FUN_140bd2620();                                           // reload: model, tabs, items
    void FUN_140bd2660();                                           // forget the model and the new flags
    void FUN_140bd26c0(unsigned nGroupId);                          // flag a pack "new"
    CStringW FUN_140bd2720(int nEmoticonId);                        // the chat command of an emoticon (":name:")
    void FUN_140bd27e0(int nTab);                                   // swf onSelectTab
    void FUN_140bd28b0(int nEmoticonId);                            // swf onSelectEmoticon: post the notice
    void OnClickShopButton();                                           // open the Merat market on the emoticon page

    std::set<unsigned> m_setNewGroups;                              // +0x178 packs received since the dialog was last opened
    std::list<UIChatEmoticonTab> m_tabs;                                          // +0x188 the category ids of the tabs, in order
    std::set<int> m_setNewTabs;                                     // +0x198 the tabs with a new pack
    std::map<int, std::list<MS2Ptr<UIChatEmoticonInfo> > > m_emoticons;     // +0x1a8 category id (-1 favourites) -> cells
    int m_nSelTab;                                                  // +0x1b8 the selected category id, -1 at start
    __int64 m_nNextExpire;                                          // +0x1c0 the earliest expiry among the shown packs
};
MS2_CHECK_SIZE(UIChatEmoticonDialog, 0x1c8);
