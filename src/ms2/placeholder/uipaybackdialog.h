// uipaybackdialog.h - PLACEHOLDER for UIPaybackDialog (RTTI .?AVUIPaybackDialog@@, UI id 0x4f93; ctor 0x140e6ec50).
// NOT an original header and not a layout: only what the game menu table binds is declared (the RTTI of its
// ClassFunHandler proves `int (UIPaybackDialog::*)()`, and UIDialog's multiple inheritance gives the 16-byte pointer).
#pragma once

#include "ms2/client/ms2/uidialog.h"

class UIPaybackDialog : public UIDialog
{
public:
    int FUN_140e6f890();                                    // 0x140e6f890 a payback reward can be claimed
};
