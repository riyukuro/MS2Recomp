// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uirangepreviewdialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIRangePreviewDialog is a debug dialog ("RangePreviewDialog", UI type 0x4eb5) for previewing collision and skill
// ranges: its four check boxes toggle the global debug flags (pc/npc collision, pc/npc skill range), and "reload npc
// extent" re-applies every npc's extent from its data record. RTTI .?AVUIRangePreviewDialog@@, 0x178 bytes (no
// members), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASData;

class UIRangePreviewDialog : public UIDialog
{
public:
    UIRangePreviewDialog();                                     // 0x141346a40
    // The destructor is implicit (0x141346a90: just ~UIDialog), ??_G 0x141347050.
    virtual CString GetTypeName();                                  //  1 0x141346ad0
    virtual void OnLoadComplete();                              // 22 0x141346b20
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x141346c40
    virtual int vfunc_48();                                     // 48 0x1413470d0

    void OnClickNpcExtentReload();                                       // re-apply every npc's extent from its data record
};
MS2_CHECK_SIZE(UIRangePreviewDialog, 0x178);

// The check box handlers: the first two arguments are the pc / npc flags.
void FUN_141346dc0(UIRangePreviewDialog* pDialog, ASData* pArgs);   // 0x141346dc0 collision
void FUN_141346e00(UIRangePreviewDialog* pDialog, ASData* pArgs);   // 0x141346e00 skill range
