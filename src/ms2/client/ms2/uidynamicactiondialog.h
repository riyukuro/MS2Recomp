// uidynamicactiondialog.h - UIDynamicActionDialog (RTTI .?AVUIDynamicActionDialog@@, 0x1c0 bytes, UI id 0x4e7a, swf
// "DynamicAction"): the sibling of UICoupleActionDialog for the learned dynamic actions (skills of main type 0xe).
// Same search / favorites / sort / paging, plus a key-bind step (a pressed key is bound to the focused action; the
// confirm box can swap a key that is already used) and a shift-right-click skill preview. NOT an original header
// (the unit is client\ms2\uidynamicactiondialog.cpp; header name assumed). Member names are invented from use.
// Reuses CSkillSystem::stEmotion (Unk_Emotion) from uicoupleactiondialog.h for the learned list.
#pragma once
#include <afx.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uicoupleactiondialog.h"

class ASData;
class NotifyObject;
class Unk_DaInput;
class Unk_DaList;

// A pending key bind (12 bytes, reset by 0x14192e620): m_0 = the swap box is open, m_4 = the action, m_8 = the key.
class Unk_DaSlot
{
public:
    Unk_DaSlot() { Clear(); }                               // 0x14192e4a0
    void Clear() { m_4 = 0; m_8 = 0; m_0 = 0; }             // 0x14192e620
    bool IsSet() const;                                     // 0x14192e660

    int m_0;
    int m_4;
    int m_8;
};
MS2_CHECK_SIZE(Unk_DaSlot, 0xc);

class UIDynamicActionDialog : public UIDialog
{
public:
    UIDynamicActionDialog();                                // 0x14192ac30
    // virtual dtor 0x14192e500: implicit (pinned)
    virtual CString vfunc_1();                              //  1 0x14192ad20 "DynamicAction"
    virtual int vfunc_13();                                 // 13 0x14192b520 enter key: take the search text / bind the pressed key
    virtual void OnLoadInit();                              // 20 0x14192aff0 refresh, listen to NotifyLearnEmotion / NotifyClearAchieve
    virtual void OnLoadComplete();                          // 22 0x14192b1c0 bind the search input
    virtual void vfunc_26();                                // 26 0x14192b340 unbind
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14192bed0
    virtual int vfunc_48() { return 0x4e7a; }               // 48 0x14192e650 (COMDAT)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x14192bb30 getTooltip
    virtual int vfunc_65();                                 // 65 0x14192ad70 open: reset
    virtual void vfunc_67();                                // 67 0x14192ade0 close
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x14192ae40 key swap confirmation

    void FUN_14192c630(NotifyObject* pNotify);              // NotifyLearnEmotion: refresh
    void FUN_14192c660(NotifyObject* pNotify);              // NotifyClearAchieve: refresh
    void FUN_14192c690(const Scaleform::GFx::FunctionHandler::Params& params);   // empty (the search input callback)
    void FUN_14192c6b0();                                   // rebuild the learned actions of the player and the pages
    void FUN_14192c930(int nAction);                        // "setFocusByEmotion"
    void FUN_14192c9b0(int nAction);                        // use the action on the player
    void FUN_14192ca10(int nAction);                        // open the skill preview of the action
    void FUN_14192ca70();                                   // "buildActions" in id order
    void FUN_14192d100();                                   // "buildActions" in reverse id order
    void FUN_14192d790(CStringW strSearch);                 // set the search text; refresh when it changed
    CStringW FUN_14192d820(unsigned int nAction);           // the search keywords of an action, space separated
    void FUN_14192d960(ASArray& arr);                       // pad the page list with empty slots
    void FUN_14192da70(int nKey);                           // keys: move the selection in "m_list"
    int FUN_14192deb0(int nKey);                            // the key has no action bound
    int FUN_14192df00(int nKey, unsigned __int64 nAction);  // bind an action to a key
    MS2Ptr<Unk_DaList> FUN_140ba4b70(const CString& strName);   // list child lookup (UIDialog member, shared COMDAT)

private:
    MS2_LAYOUT_FRIEND;
    Unk_DaSlot m_178;                                       // +0x178 the action being bound (m_4) and its key (m_8)
    Unk_DaSlot m_184;                                       // +0x184 the same for a focused action with a key already used
    std::map<unsigned int, MS2Ptr<Unk_Emotion> > m_190;     // +0x190 the learned actions by id
    MS2Ptr<Unk_DaInput> m_1a0;                              // +0x1a0 "m_inputSearch"
    bool m_1b0;                                             // +0x1b0 reverse order
    bool m_1b1;                                             // +0x1b1 favorites only
    CStringW m_1b8;                                         // +0x1b8 the search text
};
MS2_CHECK_SIZE(UIDynamicActionDialog, 0x1c0);
MS2_CHECK_OFFSET(UIDynamicActionDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIDynamicActionDialog, m_184, 0x184);
MS2_CHECK_OFFSET(UIDynamicActionDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UIDynamicActionDialog, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(UIDynamicActionDialog, m_1b0, 0x1b0);
MS2_CHECK_OFFSET(UIDynamicActionDialog, m_1b8, 0x1b8);
