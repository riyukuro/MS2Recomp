// uipaybackdialog.h - UIPaybackDialog (RTTI .?AVUIPaybackDialog@@, 0x180 bytes, bases UIDialog and UIStatusEventListener
// at +0x178; UI id 0x4f93, swf "PaybackDialog"): the merat payback window - the payback share per adventure level
// ("setEntity" rows), the merat earned so far, the period, and the "OnBuy" button that opens the merat market bill for
// the first payback product. Vftables 0x142e53350 (84 slots) / 0x142e53608 (UIStatusEventListener, no overrides).
// Ctor 0x140e6ec50, dtor 0x140e6ed70 (??_G 0x140e70450). Recovered with the queue unit ?\uiotherpetsystemdialog.cpp
// (TU 0x140e6ec50-0x140e70a90); header name assumed. PaybackManagerClient (paybackmanagerclient.cpp) calls
// FUN_140e6f820 when the level / merat changes; the game menu binds FUN_140e6f890.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class CInPacket;

class UIPaybackDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIPaybackDialog();                                          // 0x140e6ec50 registers the 0x10b packet handler
    virtual ~UIPaybackDialog();                                 //  0 0x140e6ed70
    virtual CString GetTypeName();                                  //  1 0x140e6ee70 "PaybackDialog"
    virtual void OnLoadComplete();                              // 22 0x140e6ef20
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e6efe0 "OnBuy"
    virtual int vfunc_48() { return 0x4f93; }                   // 48 0x140e70550
    virtual void vfunc_67();                                    // 67 0x140e6eec0 Close: stop listening

    void FUN_140e6f7c0(CInPacket& packet);                      // the 0x10b packet: close in the monthly reset window
    void FUN_140e6f820(int nOldLevel, unsigned nOldMerat);      // the level / merat changed: refresh the rows and the text
    int FUN_140e6f890();                                        // the payback is open
    void FUN_140e6f8c0();                                       // "setEntity" per level
    void FUN_140e6fba0();                                       // "setPaybackMerat"
    void FUN_140e6fdf0();                                       // "setPeriod"
};
MS2_CHECK_SIZE(UIPaybackDialog, 0x180);
