// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiprizemoneydialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIPrizeMoneyDialog ("PrizeMoneyDialog", UI type 0x4f46) shows two prize amounts; they are pushed to the movie as
// text through "setPrizeMoney". RTTI .?AVUIPrizeMoneyDialog@@, 0x188 bytes (UIDialog 0x178 + two 64-bit amounts),
// vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIPrizeMoneyDialog : public UIDialog
{
public:
    UIPrizeMoneyDialog();                                       // 0x140e78150
    virtual ~UIPrizeMoneyDialog();                              //  0 0x140e781e0 (??_G 0x140e78570)
    virtual CString GetTypeName();                                  //  1 0x140e78220
    virtual void OnLoadComplete();                              // 22 0x140e78270
    virtual void vfunc_43();                                    // 43 0x140e782a0
    virtual void vfunc_72();                                    // 72 0x140e78320 (empty)
    virtual int vfunc_48();                                     // 48 0x140e785b0

public:
    __int64 m_nPrize1;                                          // +0x178 second argument of "setPrizeMoney"
    __int64 m_nPrize2;                                          // +0x180 first argument of "setPrizeMoney"
};
MS2_CHECK_SIZE(UIPrizeMoneyDialog, 0x188);
MS2_CHECK_OFFSET(UIPrizeMoneyDialog, m_nPrize1, 0x178);

// Remember both amounts and push them to the movie (0x140e78330).
void FUN_140e78330(UIPrizeMoneyDialog* pDialog, __int64 nPrize1, __int64 nPrize2);

// Push the amounts to the movie (0x140e78380).
void FUN_140e78380(UIPrizeMoneyDialog* pDialog);
