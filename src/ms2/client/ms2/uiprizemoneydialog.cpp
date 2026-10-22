// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPrizeMoneyDialog: see uiprizemoneydialog.h.
// MS2-UNIT: ?\uiprizemoneydialog.cpp
// MS2-RANGE: 0x140e78150-0x140e785c0 .text$mn
// MS2-PIN: ??_GUIPrizeMoneyDialog@@UEAAPEAXI@Z 0x140e78570
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiprizemoneydialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiprizemoneydialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
CStringW FUN_1409404f0(__int64 n);                              // the number as text

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_140e78470(const char* szMethod, CStringW a1, CStringW a2);
};

// FUN_140e78380 is a free function, so it reaches the dialog's protected AS pointer (UISwfEntity::m_30 at +0x30)
// through this layout view.
struct Unk_PrizeDialogAS { char m_pad_00[0x30]; MS2Ptr<AScript> m_30; };

// @0x140e78150
UIPrizeMoneyDialog::UIPrizeMoneyDialog()
{
    m_nPrize1 = 0;
    m_nPrize2 = 0;
    FUN_141925e70(1, 1);
}

// @0x140e781e0
UIPrizeMoneyDialog::~UIPrizeMoneyDialog()
{
}

// @0x140e78220
CString UIPrizeMoneyDialog::GetTypeName()
{
    return "PrizeMoneyDialog";
}
MS2_REPLACE_METHOD(0x140E78220, UIPrizeMoneyDialog, GetTypeName, 61, 0xFDED4435);

// @0x140e78270
void UIPrizeMoneyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e78380(this);
}
MS2_REPLACE_METHOD(0x140E78270, UIPrizeMoneyDialog, OnLoadComplete, 34, 0x3E014E21);

// @0x140e782a0
void UIPrizeMoneyDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(1, 0, 0x44);
}

// @0x140e78320
void UIPrizeMoneyDialog::vfunc_72()
{
}

// @0x140e78330
void FUN_140e78330(UIPrizeMoneyDialog* pDialog, __int64 nPrize1, __int64 nPrize2)
{
    pDialog->m_nPrize1 = nPrize1;
    pDialog->m_nPrize2 = nPrize2;
    FUN_140e78380(pDialog);
}
MS2_REPLACE(0x140e78330, FUN_140e78330, 68, 0x24D0EEB5);

// @0x140e78380
void FUN_140e78380(UIPrizeMoneyDialog* pDialog)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)((Unk_PrizeDialogAS*)pDialog)->m_30);
    if (pDlg != 0)
        pDlg->FUN_140e78470("setPrizeMoney", FUN_1409404f0(pDialog->m_nPrize1), FUN_1409404f0(pDialog->m_nPrize2));
}
MS2_REPLACE(0x140e78380, FUN_140e78380, 235, 0xB1158841);

// @0x140e78470
Scaleform::GFx::Value ASDialog::FUN_140e78470(const char* szMethod, CStringW a1, CStringW a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e785b0
int UIPrizeMoneyDialog::vfunc_48()
{
    return 0x4f46;
}
