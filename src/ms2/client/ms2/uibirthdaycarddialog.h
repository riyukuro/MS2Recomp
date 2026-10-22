// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uibirthdaycarddialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIBirthdayCardDialog ("BirthdayCardDialog", UI type 0x4f55) is the birthday greeting card: on load it asks the
// server for the card data (packet 0xa6) and, when the local player has a birthday set, pushes the birthday month to
// the movie ("setBirthDay", two digits) and plays the greeting sound. RTTI .?AVUIBirthdayCardDialog@@, 0x178 bytes
// (no members), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIBirthdayCardDialog : public UIDialog
{
public:
    UIBirthdayCardDialog();                                     // 0x140bb9770
    virtual ~UIBirthdayCardDialog();                            //  0 0x140bb97d0 (??_G 0x140bb9b60)
    virtual CString GetTypeName();                                  //  1 0x140bb9810
    virtual int vfunc_65();                                    // 65 0x140bb9860
    virtual void vfunc_67();                                    // 67 0x140bb9890
    virtual void OnLoadComplete();                              // 22 0x140bb98c0
    virtual int vfunc_48();                                    // 48 0x140bb9bc0

    void SendBirthdayCard();                                       // request the card data from the server (packet 0xa6)
    void FUN_140bb9960();                                       // push the birthday month and play the greeting sound
};
MS2_CHECK_SIZE(UIBirthdayCardDialog, 0x178);

