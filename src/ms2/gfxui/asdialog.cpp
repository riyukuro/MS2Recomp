// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASDialog, the ActionScript dialog root wrapper of the GFx UI
// library.
// MS2-UNIT: ?\asdialog.cpp
// MS2-RANGE: 0x1422e63e0-0x1422e64a0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/aswindow.h; it only adds a vftable to ASWindow.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/aswindow.h"

// @0x1422e63e0
ASDialog::ASDialog(const Scaleform::GFx::Value& v, int nMovieId)
    : ASWindow(v, nMovieId)
{
}

// @0x1422e6430
ASDialog::~ASDialog()
{
}

// MS2-PIN: ??_GASDialog@@UEAAPEAXI@Z 0x1422e6460
