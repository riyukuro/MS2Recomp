// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuizOXWelcomeDialog: see uiquizoxwelcomedialog.h.
// MS2-UNIT: ?\uiquizoxwelcomedialog.cpp
// MS2-RANGE: 0x140e7ef40-0x140e7f2e0 .text$mn
// MS2-PIN: ??_GUIQuizOXWelcomeDialog@@UEAAPEAXI@Z 0x140e7f290
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquizoxwelcomedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiquizoxwelcomedialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int nValue);     // invoke an AS method
};

void FUN_140710590(COutPacket& packet);                         // 0x140710590 send the packet

// FUN_140e7f110 is a free function, so it reaches the dialog's protected AS pointer (UISwfEntity::m_30 at +0x30)
// through this layout view.
struct Unk_QuizDialogAS { char m_pad_00[0x30]; MS2Ptr<AScript> m_30; };

// @0x140e7ef40
UIQuizOXWelcomeDialog::UIQuizOXWelcomeDialog()
{
    m_bHost = 0;
    FUN_141925e70(1, 1);
}

// @0x140e7efb0
UIQuizOXWelcomeDialog::~UIQuizOXWelcomeDialog()
{
}

// @0x140e7eff0
CString UIQuizOXWelcomeDialog::GetTypeName()
{
    return "QuizOXWelcomeDialog";
}
MS2_REPLACE_METHOD(0x140E7EFF0, UIQuizOXWelcomeDialog, GetTypeName, 61, 0x747A9478);

// @0x140e7f040
void UIQuizOXWelcomeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e7f110(this, m_bHost);
}
MS2_REPLACE_METHOD(0x140E7F040, UIQuizOXWelcomeDialog, OnLoadComplete, 46, 0x4379CDD0);

// @0x140e7f080
void UIQuizOXWelcomeDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(0, 0, 0);
}

// @0x140e7f100
void UIQuizOXWelcomeDialog::vfunc_72()
{
}

// @0x140e7f110
void FUN_140e7f110(UIQuizOXWelcomeDialog* pDialog, bool bHost)
{
    pDialog->m_bHost = bHost;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)((Unk_QuizDialogAS*)pDialog)->m_30);
    if (pDlg != 0)
        pDlg->FUN_1409ba030("SetHost", pDialog->m_bHost ? 1 : 0);
}

// @0x140e7f1c0
int UIQuizOXWelcomeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickStart", szMethod) == 0) {
        FUN_140e7f230(this);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E7F1C0, UIQuizOXWelcomeDialog, vfunc_28, 105, 0xAC452B05);

// @0x140e7f230
void FUN_140e7f230(UIQuizOXWelcomeDialog* pDialog)
{
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(7);
    FUN_140710590(packet);
}
MS2_REPLACE(0x140e7f230, FUN_140e7f230, 87, 0xE6DE65FD);

// @0x140e7f2d0
int UIQuizOXWelcomeDialog::vfunc_48()
{
    return 0x4f48;
}
