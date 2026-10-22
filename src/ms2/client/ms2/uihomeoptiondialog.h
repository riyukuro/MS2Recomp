// uihomeoptiondialog.h - UIHomeOptionDialog (RTTI .?AVUIHomeOptionDialog@@, UIDialog, UI id from vfunc_48, swf
// "HomeOptionDialog"): the home option dialog (opentype, the nine permission rows, the password, kick all users).
// Owning unit: unit_140fa8cc0 (0x140fa8cc0-0x140fa9eb0 .text$mn; its header statics are the .text$di run at 0x1400e1a10).
// Header name assumed from the class name; the exe has no __FILE__ string for it. No members of its own. vftable
// 0x142... (IMessageListener part at +0x18, slot 0 is its OnMessage).
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/imessagelistener.h"

class UIHomeOptionDialog : public UIDialog
{
public:
    UIHomeOptionDialog();                                       // 0x140fa8cc0
    virtual ~UIHomeOptionDialog();                              //  0 0x140fa8d20 (??_G 0x140fa9d40)
    virtual CString vfunc_1();                                  //  1 0x140fa8d60 "HomeOptionDialog"
    virtual void OnLoadComplete();                              // 22 0x140fa8db0 fill the dialog
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fa8de0
    virtual int vfunc_48() { return 0x4f26; }                   // 48 0x140fa9d80
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140fa9570 message box answers

    void FUN_140fa97a0();                                       // push "setData" (opentype and the nine rows)
    void FUN_140fa99b0(bool bOpen, CStringW strPassword);   // send the open type and password to the player
    void FUN_140fa9a50(int nRow, int nValue);                   // send the permission row (flag and level)
    void SendRequestCubeMode42(int nRow, bool bOn);  // packet 0x37/0x2a
    void SendRequestCubeMode43(int nRow, int nLevel);   // packet 0x37/0x2b
    void SendRequestCubeMode49();                                       // packet 0x37/0x31 kick every visitor
};
