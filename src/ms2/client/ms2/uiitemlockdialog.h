// uiitemlockdialog.h - UIItemLockDialog (RTTI .?AVUIItemLockDialog@@, 0x1b8 bytes, UIDialog + UIStatusEventListener +
// UIItemEventListener, UI id 0x4f08, swf "ItemLockDialog"): the window where items are locked / unlocked. It binds the
// "m_itemBag" control to its own bag id, follows the inventory dialog, tells the CItemLockManager the selected tab and
// asks for confirmation (message boxes) before an item is locked or unlocked. FUN_140f57c60 creates a display item slot
// (kept in m_188 so that it can be released). Owning unit: ?\uiitemlockdialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class UIItemLockDialog : public UIDialog, public UIStatusEventListener, public UIItemEventListener
{
public:
    UIItemLockDialog();                                         // 0x140f56ab0
    virtual ~UIItemLockDialog();                                //  0 0x140f56b90 (??_G 0x140f57ef0)
    virtual CString GetTypeName();                                  //  1 0x140f56c30 "ItemLockDialog"
    virtual void OnLoadInit();                                  // 20 0x140f57030 play the dialog_open sound
    virtual void OnLoadComplete();                              // 22 0x140f570b0
    virtual void vfunc_26();                                    // 26 0x140f57160
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f572e0
    virtual void vfunc_43();                                    // 43 0x140f57ab0
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x140f572c0 empty
    virtual int vfunc_48() { return 0x4f08; }                   // 48 0x140f57f30
    virtual void vfunc_15();                                    // 15 0x140f57c20
    virtual void vfunc_66();                                    // 66 0x140f578f0
    virtual void vfunc_67();                                    // 67 0x140f571f0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140f57a20

    void FUN_140f56c80();                                       // bind the bag, then refresh the lock buttons
    void FUN_140f56e00();                                       // enable / disable the lock buttons
    int FUN_140f56f50();                                        // the bag control is visible
    CString FUN_140f57c60(unsigned nItemId, int nRarity);       // create a display slot for an item
    void FUN_140f57e30();                                       // release the display slots

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<CString> m_lstSlots;                          // +0x188 names of the display slots created
};
MS2_CHECK_SIZE(UIItemLockDialog, 0x1b8);
MS2_CHECK_OFFSET(UIItemLockDialog, m_lstSlots, 0x188);
