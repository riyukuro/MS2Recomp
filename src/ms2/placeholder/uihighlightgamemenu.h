// uihighlightgamemenu.h - PLACEHOLDER for UIHighlightGameMenu (RTTI .?AVUIHighlightGameMenu@@, 0x1f0 bytes), the
// game-menu highlight dialog. NOT an original header. Ctor 0x140c220d0 (uiservice.cpp creates it); the members are
// not recovered, only what ?\uibottomcenteralignmanager.cpp reads.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class UIHighlightGameMenu : public UIDialog
{
public:
    bool IsActive();                                   // 0x140c22ce0 returns the byte at +0x1e8
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_178[0x1f0 - 0x178];
};
MS2_CHECK_SIZE(UIHighlightGameMenu, 0x1f0);
