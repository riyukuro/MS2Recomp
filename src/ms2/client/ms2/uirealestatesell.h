// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uirealestatesell.h (name assumed).
//
// UIRealEstateSell is the "sell your house" confirmation dialog (UI type 0x4e82, swf "RealEstateSell"): it shows the
// house name, address, remaining days and the sale price / extension refund of the player's own house, asks for the
// character name as a confirmation (message box tagged "confirmName,<name>") and then sends the sell request
// (packet 0x37 / 6). RTTI .?AVUIRealEstateSell@@, UIDialog + one int (0x180 bytes), vftables 0x142... (84 slots) and the
// IMessageListener one at +0x18 (slot 0 is its OnMessage).
// Member and method names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class UIMsg;

class UIRealEstateSell : public UIDialog
{
public:
    UIRealEstateSell();                                             // 0x141ab5d50
    virtual ~UIRealEstateSell();                                    //  0 0x141ab5db0 (??_G 0x141ab6e30)
    virtual CString vfunc_1();                                      //  1 0x141ab5df0 "RealEstateSell"
    virtual void OnLoadInit();                                      // 20 0x141ab5f70
    virtual void OnLoadComplete();                                  // 22 0x141ab5ee0 fill the dialog
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ab5fb0
    virtual int vfunc_48() { return 0x4e82; }                       // 48 0x141ab6e70
    virtual int vfunc_65();                                         // 65 0x141ab5e40 open: nothing is pending
    virtual void vfunc_67();                                        // 67 0x141ab5e80 close
    virtual void vfunc_79(void* p);                                 // 79 0x141ab5f10
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141ab6c50 the name confirmation answer

    void FUN_141ab6230();                                           // push "initData" (house name, address, expiry, prices)
    int FUN_141ab6ad0(CStringW strName);                            // the entered name must be the player's own; sends the request

    int m_178;                                                      // +0x178 the sell request was sent
};
MS2_CHECK_OFFSET(UIRealEstateSell, m_178, 0x178);
