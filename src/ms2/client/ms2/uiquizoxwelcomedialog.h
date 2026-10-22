// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiquizoxwelcomedialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIQuizOXWelcomeDialog is the host screen of the OX quiz ("QuizOXWelcomeDialog", UI type 0x4f48): the single
// m_bHost flag is pushed to the movie as "SetHost" so the SWF shows the Start button only to the host, and
// "OnClickStart" sends the start request (packet 0x90). RTTI .?AVUIQuizOXWelcomeDialog@@, 0x180 bytes (UIDialog
// 0x178 + the host flag), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIQuizOXWelcomeDialog : public UIDialog
{
public:
    UIQuizOXWelcomeDialog();                                    // 0x140e7ef40
    virtual ~UIQuizOXWelcomeDialog();                           //  0 0x140e7efb0 (??_G 0x140e7f290)
    virtual CString GetTypeName();                                  //  1 0x140e7eff0
    virtual void OnLoadComplete();                              // 22 0x140e7f040
    virtual void vfunc_43();                                    // 43 0x140e7f080
    virtual void vfunc_72();                                    // 72 0x140e7f100 (empty)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e7f1c0
    virtual int vfunc_48();                                     // 48 0x140e7f2d0

public:
    bool m_bHost;                                               // +0x178 1 while this client hosts the quiz
};
MS2_CHECK_SIZE(UIQuizOXWelcomeDialog, 0x180);
MS2_CHECK_OFFSET(UIQuizOXWelcomeDialog, m_bHost, 0x178);

// Push the host flag to the movie (0x140e7f110): remembers it, then calls "SetHost" with it.
void FUN_140e7f110(UIQuizOXWelcomeDialog* pDialog, bool bHost);

// Ask the server to start the quiz (0x140e7f230): packet 0x90 with (10, 7) (the OX quiz mode and round count).
void FUN_140e7f230(UIQuizOXWelcomeDialog* pDialog);
