// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASCheckBox, the ActionScript check box wrapper of the GFx UI
// library.
// MS2-UNIT: ?\ascheckbox.cpp
// MS2-RANGE: 0x1422ceac0-0x1422ceb80 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asbutton.h; it only adds a vftable to ASButton.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asbutton.h"

// @0x1422ceac0
ASCheckBox::ASCheckBox(const Scaleform::GFx::Value& v, int nMovieId)
    : ASButton(v, nMovieId)
{
}

// @0x1422ceb10
ASCheckBox::~ASCheckBox()
{
}

// MS2-PIN: ??_GASCheckBox@@UEAAPEAXI@Z 0x1422ceb40
