// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimyhouseauthdialog.h (name assumed:
// the .cpp's __FILE__ string is not in the exe for this unit).
//
// UIMyHouseAuthDialog ("MyHouseAuthDialog", UI type 0x4e8b, RTTI .?AVUIMyHouseAuthDialog@@, 0x178 bytes = UIDialog):
// the confirm dialog the my-home editor pops when it needs the owner's authorisation. It has no fields of its own (the
// ctor only turns on the open tween, FUN_141924170(1)); "onCancel" closes it and "OnConfirm" consumes the box's
// arguments. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class UIMyHouseAuthDialog : public UIDialog
{
public:
    UIMyHouseAuthDialog();                                          // 0x141a57b00 (open tween 1)
    virtual ~UIMyHouseAuthDialog();                                 //  0 0x141a57b60 (??_G 0x141a57ed0)
    virtual CString GetTypeName();                                      //  1 0x141a57ba0 "MyHouseAuthDialog"
    virtual void OnLoadComplete();                                  // 22 0x141a57c40 the base's
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a57cc0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141a57e10 the confirm box's answer
    virtual int vfunc_48() { return 0x4e8b; }                       // 48 0x141a57f10 UI type id
    virtual int vfunc_65();                                         // 65 0x141a57bf0 open (the base's)
    virtual void vfunc_67();                                        // 67 0x141a57c20 close (the base's)
    virtual void vfunc_79(void* p);                                 // 79 0x141a57c60 the base's
};
MS2_CHECK_SIZE(UIMyHouseAuthDialog, 0x178);
