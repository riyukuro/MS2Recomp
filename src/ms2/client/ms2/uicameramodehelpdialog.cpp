// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICameraModeHelpDialog: see uicameramodehelpdialog.h.
// MS2-UNIT: ?\uicameramodehelpdialog.cpp
// MS2-RANGE: 0x140e05260-0x140e05460 .text$mn
// MS2-PIN: ??_GUICameraModeHelpDialog@@UEAAPEAXI@Z 0x140e05410
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicameramodehelpdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uicameramodehelpdialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

// @0x140e05260
UICameraModeHelpDialog::UICameraModeHelpDialog()
{
    FUN_141924170(1);
    FUN_141925e70(0, 1);
}

// @0x140e052d0
UICameraModeHelpDialog::~UICameraModeHelpDialog()
{
}

// @0x140e05310
CString UICameraModeHelpDialog::vfunc_1()
{
    return "CameraModeHelpDialog";
}
MS2_REPLACE_METHOD(0x140E05310, UICameraModeHelpDialog, vfunc_1, 61, 0xDCBE5949);

// @0x140e05360
void UICameraModeHelpDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(6, -300, 0);
}

// @0x140e05450
int UICameraModeHelpDialog::vfunc_48()
{
    return 0x4f3e;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140e05360, UICameraModeHelpDialog, vfunc_43, 167, 0xAC5A83F4);
MS2_REPLACE_METHOD(0x140e05450, UICameraModeHelpDialog, vfunc_48, 11, 0x95668B3E);

