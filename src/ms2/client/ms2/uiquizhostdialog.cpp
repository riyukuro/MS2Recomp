// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuizHostDialog: see uiquizhostdialog.h.
// MS2-UNIT: ?\uiquizhostdialog.cpp
// MS2-RANGE: 0x140e7dc10-0x140e7e2f0 .text$mn
// MS2-PIN: ??1UIQuizHostDialog@@UEAA@XZ 0x140e7dc90
// MS2-PIN: ??_GUIQuizHostDialog@@UEAAPEAXI@Z 0x140e7e2a0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquizhostdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiquizhostdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int nValue);      // invoke an AS method with an int
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);                  // invoke an AS method
    Scaleform::GFx::Value FUN_140bfe360(const char* szMethod, bool bValue);     // invoke an AS method with a bool
};

// The free functions below reach the dialog's protected AS pointer (UISwfEntity::m_30 at +0x30) through this view.
struct Unk_QhDialogAS { char m_pad_00[0x30]; MS2Ptr<AScript> m_30; };

// A child of the movie (a button): handle at +8, the dtor sits at 0x140acd6e0.
class Unk_QhButton : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(int bEnabled);
};
class Unk_QhHandle
{
public:
    Unk_QhButton* FUN_140acd9c0();
    Unk_QhButton* FUN_140acd9e0();
    void FUN_140acd6e0();
};
class Unk_QhMovieEntity : public UIDialog
{
public:
    Unk_QhHandle FUN_140bb4b10(const CString& strName);         // child lookup
};

void FUN_140710590(COutPacket& packet);                         // 0x140710590 send the packet
CStringW FUN_140298ea0(CStringW strKey);                        // localized string
void FUN_1412751b0(const CStringW& strText, int nType);         // system notice
void FUN_140dff970();                                           // finish confirmation message box

// @0x140e7dc10
UIQuizHostDialog::UIQuizHostDialog()
{
    m_nRound = 1;
    FUN_141925e70(1, 1);
}

// @0x140e7dcd0
CString UIQuizHostDialog::GetTypeName()
{
    return "QuizHostDialog";
}
MS2_REPLACE_METHOD(0x140E7DCD0, UIQuizHostDialog, GetTypeName, 61, 0x3BE68A74);

// @0x140e7dd20
void UIQuizHostDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e7df20(this, m_nRound);
}
MS2_REPLACE_METHOD(0x140E7DD20, UIQuizHostDialog, OnLoadComplete, 45, 0x0CAE16DD);

// @0x140e7dd60
void UIQuizHostDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(2, 0, 0xffffff06);
}
MS2_REPLACE_METHOD(0x140E7DD60, UIQuizHostDialog, vfunc_43, 116, 0x9636135A);

// @0x140e7dde0
void UIQuizHostDialog::vfunc_72()
{
}

// @0x140e7ddf0
int UIQuizHostDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnQuestionSubmit", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140e7e160(this, data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("OnFinishEvent", szMethod) == 0)
        FUN_140e7e220(this);
    return 0;
}
MS2_REPLACE_METHOD(0x140E7DDF0, UIQuizHostDialog, vfunc_28, 283, 0xA48E651D);

// @0x140e7df20
void FUN_140e7df20(UIQuizHostDialog* pDialog, int nRound)
{
    pDialog->m_nRound = nRound;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)((Unk_QhDialogAS*)pDialog)->m_30);
    if (pDlg != 0)
        pDlg->FUN_1409ba030("SetRound", nRound);
}

// @0x140e7dfb0
void FUN_140e7dfb0(UIQuizHostDialog* pDialog)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)((Unk_QhDialogAS*)pDialog)->m_30);
    if (pDlg != 0)
        pDlg->FUN_1422bb330("ClearInput");
}

// @0x140e7e030
void FUN_140e7e030(UIQuizHostDialog* pDialog, bool bEnable)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)((Unk_QhDialogAS*)pDialog)->m_30);
    if (pDlg != 0)
        pDlg->FUN_140bfe360("EnableSubmit", bEnable);
}

// @0x140e7e0b0
void FUN_140e7e0b0(UIQuizHostDialog* pDialog, bool bEnable)
{
    Unk_QhHandle hButton = static_cast<Unk_QhMovieEntity*>(static_cast<UIDialog*>(pDialog))->FUN_140bb4b10("m_btnEventFinish");
    if (hButton.FUN_140acd9c0() != 0)
        hButton.FUN_140acd9e0()->FUN_1422c1fe0(bEnable);
    hButton.FUN_140acd6e0();
}

// @0x140e7e160
void FUN_140e7e160(UIQuizHostDialog* pDialog, const CStringW& strQuestion)
{
    CStringW strText(strQuestion);
    strText.Trim();
    if (strText.GetLength() == 0)
        return;
    COutPacket packet(0x90, 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_8(strText);
    FUN_140710590(packet);
}

// @0x140e7e220
void FUN_140e7e220(UIQuizHostDialog* pDialog)
{
    if (pDialog->m_nRound < 2) {
        CStringW strText = FUN_140298ea0(CStringW(L"s_ugcox_finish_fail_by_round"));
        FUN_1412751b0(strText, 20);
    } else {
        FUN_140dff970();
    }
}

// @0x140e7e2e0
int UIQuizHostDialog::vfunc_48()
{
    return 0x4f44;
}
