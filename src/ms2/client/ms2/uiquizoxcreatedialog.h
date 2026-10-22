// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiquizoxcreatedialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIQuizOXCreateDialog is the room creation screen of the OX quiz ("QuizOXCreateDialog", UI type 0x4f47): the
// "m_dropdownEntryFee" drop down lists the allowed entry fees (m_fees, set by SetFees), "OnCreate" sends the
// create request (packet 0x90, sub-op 0) and "OnCancel" closes the dialog. RTTI .?AVUIQuizOXCreateDialog@@,
// 0x190 bytes (UIDialog 0x178 + the fee vector), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASData;

class UIQuizOXCreateDialog : public UIDialog
{
public:
    UIQuizOXCreateDialog();                                     // 0x140e7e2f0
    virtual ~UIQuizOXCreateDialog();                            //  0 0x140e7e350 (??_G 0x140e7e960)
    virtual CString GetTypeName();                                  //  1 0x140e7e460
    virtual void OnLoadComplete();                              // 22 0x140e7e4b0
    virtual void vfunc_43();                                    // 43 0x140e7e760
    virtual void vfunc_72();                                    // 72 0x140e7e7e0 (empty)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e7e7f0
    virtual int vfunc_48();                                     // 48 0x140e7e9a0

    void SetFees(std::vector<int>& fees);                 // 0x140e7e3a0 (named from its use: replaces m_fees)

public:
    std::vector<int> m_fees;                                    // +0x178 allowed entry fees
};
MS2_CHECK_SIZE(UIQuizOXCreateDialog, 0x190);
MS2_CHECK_OFFSET(UIQuizOXCreateDialog, m_fees, 0x178);

// "OnCreate" handler (0x140e7e900): the first three arguments (as ints) go to the create request packet.
int FUN_140e7e900(UIQuizOXCreateDialog* pDialog, ASData* pArgs);
