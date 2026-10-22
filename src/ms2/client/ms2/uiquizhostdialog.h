// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiquizhostdialog.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UIQuizHostDialog is the host's question screen of the OX quiz ("QuizHostDialog", UI type 0x4f44): the host types
// the question, "OnQuestionSubmit" sends it (packet 0x90, sub-op 10) and "OnFinishEvent" ends the event (a message box
// asks for confirmation; ending before round 2 is refused). RTTI .?AVUIQuizHostDialog@@, 0x180 bytes (UIDialog 0x178
// + the round number), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIQuizHostDialog : public UIDialog
{
public:
    UIQuizHostDialog();                                         // 0x140e7dc10
    // The destructor is implicit (0x140e7dc90: just ~UIDialog), ??_G 0x140e7e2a0.
    virtual CString GetTypeName();                                  //  1 0x140e7dcd0
    virtual void OnLoadComplete();                              // 22 0x140e7dd20
    virtual void vfunc_43();                                    // 43 0x140e7dd60
    virtual void vfunc_72();                                    // 72 0x140e7dde0 (empty)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e7ddf0
    virtual int vfunc_48();                                     // 48 0x140e7e2e0

public:
    int m_nRound;                                               // +0x178 current round (starts at 1)
};
MS2_CHECK_SIZE(UIQuizHostDialog, 0x180);
MS2_CHECK_OFFSET(UIQuizHostDialog, m_nRound, 0x178);

// Remember the round and push it to the movie ("SetRound") (0x140e7df20).
void FUN_140e7df20(UIQuizHostDialog* pDialog, int nRound);

// Movie calls: "ClearInput" (0x140e7dfb0), "EnableSubmit" (0x140e7e030).
void FUN_140e7dfb0(UIQuizHostDialog* pDialog);
void FUN_140e7e030(UIQuizHostDialog* pDialog, bool bEnable);

// Enable / disable the "m_btnEventFinish" button (0x140e7e0b0).
void FUN_140e7e0b0(UIQuizHostDialog* pDialog, bool bEnable);

// Send the (trimmed, non-empty) question (0x140e7e160): packet 0x90 with (10, 10, text).
void FUN_140e7e160(UIQuizHostDialog* pDialog, const CStringW& strQuestion);

// "OnFinishEvent" handler (0x140e7e220): before round 2 only a notice, otherwise the finish confirmation box.
void FUN_140e7e220(UIQuizHostDialog* pDialog);
