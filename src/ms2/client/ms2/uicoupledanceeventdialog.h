// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicoupledanceeventdialog.h (name
// assumed: the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UICoupleDanceEventDialog is the couple-dance event banner dialog ("CoupleDanceEventDialog", UI type 0x4f71): it
// lists the event's reward steps (an "ItemSlotBinder" fills the reward slots), starts a couple dance request when the
// banner is opened and asks before it is closed. RTTI .?AVUICoupleDanceEventDialog@@, 0x1c8 bytes, vftables
// 0x142df8f08 (84 slots) and 0x142df91b0 (IMessageListener at +0x18).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset>.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/uidialog.h"

class UICoupleDanceEventDialog : public UIDialog
{
public:
    UICoupleDanceEventDialog();                                                                     // 0x140bfcb00
    virtual ~UICoupleDanceEventDialog();                                                            //  0 0x140bfcbb0
    virtual CString GetTypeName();                                                                      //  1 0x140bfcc00
    virtual void OnLoadComplete();                                                                  // 22 0x140bfccf0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140bfcd30
    virtual int vfunc_48() { return 0x4f71; }                                                       // 48 (COMDAT 0x140bfe4a0)
    virtual void vfunc_67();                                                                        // 67 0x140bfcc80
    virtual int vfunc_71();                                                                         // 71 0x140bfd300
    virtual void vfunc_72();                                                                        // 72 0x140bfcc50
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);                                       // IMessageListener 0 0x140bfd4d0

    void FUN_140bfd5e0();                   // refresh the whole dialog: fills the reward steps and sends "setData"
    void FUN_140bfdc00();                   // recount the completed reward steps (m_1c0); notifies the server UI
    void FUN_140bfde00();                   // refresh the banner button when the open/close state changed
    void FUN_140bfdf60(int nStep);          // request the reward of step nStep (packet 0xa8/0x19)
    int FUN_140bfe180();                    // m_1c0
    void FUN_140bfe1a0(void* a1);                   // FUN_140bfd5e0() when the dialog is closed, else FUN_140bfdc00()

private:
    MS2_LAYOUT_FRIEND;
    bool m_178;                             // +0x178 banner is open ("isOpenBanner")
    ItemSlotBinder m_180;                   // +0x180 binds the reward items to slots (named after GetTypeName())
    int m_1c0;                              // +0x1c0 number of completed reward steps
};
MS2_CHECK_SIZE(UICoupleDanceEventDialog, 0x1c8);
MS2_CHECK_OFFSET(UICoupleDanceEventDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UICoupleDanceEventDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UICoupleDanceEventDialog, m_1c0, 0x1c0);
