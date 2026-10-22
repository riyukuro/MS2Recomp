// uioxquizdialog.h - UIOxQuizDialog (RTTI .?AVUIOxQuizDialog@@, 0x180 bytes, base UIDialog, UI id 0x4f7d, swf
// "OxQuizDialog"): the OX quiz window with the "promote" and "create" buttons and the promote cool time. Vftables
// 0x142e52c70 (84 slots) / 0x142e52f18 (IMessageListener). Ctor 0x140e6e400, dtor 0x140e6e490 (??_G 0x140e6eae0).
// The OX quiz manager (unit_140dfef30.cpp) enables the dialog (FUN_140e6e8b0) and feeds the cool time (FUN_140e6e6c0).
// The TU (0x140e6e400-0x140e6ec40) is part of the queue unit ?\uiotherpetsystemdialog.cpp; header name assumed.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIOxQuizDialog : public UIDialog
{
public:
    UIOxQuizDialog();                                           // 0x140e6e400
    virtual ~UIOxQuizDialog();                                  //  0 0x140e6e490 (??_G 0x140e6eae0)
    virtual CString vfunc_1();                                  //  1 0x140e6e4d0 "OxQuizDialog"
    virtual void OnLoadComplete();                              // 22 0x140e6e550
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e6e580
    virtual int vfunc_48() { return 0x4f7d; }                   // 48 0x140e6eb20
    virtual int vfunc_65();                                     // 65 0x140e6e520 open only while enabled

    void FUN_140e6e610(bool bUnused);                           // refresh the cool time (when in the quiz field); a callback
    void FUN_140e6e640();                                       // show the remaining cool time
    void FUN_140e6e6c0(float fRemain, float fTotal);            // set the cool time ("setQuizPromoteCooltime")
    static void FUN_140e6e8b0(bool bEnable);                    // s_bEnable = bEnable
    void OnQuizPromote();                                       // "OnQuizPromote"
    void OnQuizCreate();                                       // "OnQuizCreate"

    static bool s_bEnable;                                      // 0x143ac6ee0 set by the OX quiz manager

private:
    MS2_LAYOUT_FRIEND;
    unsigned m_178;                                             // +0x178 tick the cool time started at
    float m_17c;                                                // +0x17c the cool time (seconds), 10
};
MS2_CHECK_SIZE(UIOxQuizDialog, 0x180);
MS2_CHECK_OFFSET(UIOxQuizDialog, m_178, 0x178);
