// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBuiltInDialog, the base of the always-present HUD dialogs,
// and the HUD layout metrics (exp bar height etc.) next to it.
// MS2-UNIT: ?\uibuiltindialog.cpp
// MS2-RANGE: 0x1418dcf70-0x1418dd2e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibuiltindialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/uibuiltindialog.h"
#include "ms2/placeholder/cfeaturemanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern int DAT_1439f8cc8;
extern int DAT_1439f8ccc;
extern int DAT_1439f8cd0;
extern int DAT_1439f8cd4;
CFeatureManager* FUN_140166410();

// @0x1418dcf70
UIBuiltInDialog::UIBuiltInDialog()
{
    m_2c = 14;
    m_80 = 0;
    m_88 = 1;
    FUN_141925e70(0, 1);
}

// @0x1418dd000
UIBuiltInDialog::~UIBuiltInDialog()
{
}

// @0x1418dd040
CString UIBuiltInDialog::GetTypeName()
{
    return "BuiltInDialog";
}

// @0x1418dd090
void UIBuiltInDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x1418dd0c0
int FUN_1418dd0c0()
{
    return DAT_1439f8ccc - 2;
}

int FUN_1418dd110();

// @0x1418dd0d0
int FUN_1418dd0d0()
{
    return FUN_1418dd0c0() + FUN_1418dd110() + DAT_1439f8cc8;
}

// @0x1418dd100
int FUN_1418dd100()
{
    return DAT_1439f8cd4;
}

// @0x1418dd110
int FUN_1418dd110()
{
    return FUN_140166410()->FUN_14036d570(0xbd) ? DAT_1439f8cd0 - 2 : 0;
}

// @0x1418dd150
void UIBuiltInDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141923680(0);
}

// @0x1418dd1c0
MS2_EMIT_CRT_MEMMOVE_S();
