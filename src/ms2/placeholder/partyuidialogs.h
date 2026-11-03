// Party UI types used only for RTTI lookup. Constructors establish the bases and sizes.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/client/ms2/uichaosdpsdialog.h"
class UIPartyDPSDialog : public UIDialog {
    unsigned char unrecovered[0x28];
};
class UIPartySearchRegisterDialog : public UIModalDialog {
    unsigned char unrecovered[0xa8];
};
MS2_CHECK_SIZE(UIPartyDPSDialog, 0x1a0);
MS2_CHECK_SIZE(UIPartySearchRegisterDialog, 0x228);
class UIPartyDialog : public UIDialog {
public:
    void SetDeadline(unsigned int nDeadline);   // 0x141a75a00
    void ArrangeBottomButton();                 // 0x141a75a20
    void FUN_141a759b0();                       // 0x141a759b0 refresh the vote panel
private:
    unsigned char unrecovered[0x70];
};
MS2_CHECK_SIZE(UIPartyDialog, 0x1e8);
