// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMyHouseAuthDialog: see uimyhouseauthdialog.h.
// MS2-UNIT: ?\uimyhouseauthdialog.cpp
// MS2-RANGE: 0x141a57b00-0x141a58040 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimyhouseauthdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uimyhouseauthdialog.h"

#include "uimessagebox.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

bool FUN_140a467d0(const MS2Ptr<AScript>* p);                                 // has the AS object been released
int FUN_1418fc760(const char* szMethod, const void* pArgs, unsigned int nArgs, int n);   // the shared vfunc_28 back end
void FUN_14151f200();                                                         // show the next queued message box

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141a57b00
UIMyHouseAuthDialog::UIMyHouseAuthDialog()
{
    FUN_141924170(1);
}

// @0x141a57b60
UIMyHouseAuthDialog::~UIMyHouseAuthDialog()
{
}

// @0x141a57ba0
CString UIMyHouseAuthDialog::GetTypeName()
{
    return "MyHouseAuthDialog";
}

// @0x141a57bf0
int UIMyHouseAuthDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141a57c20
void UIMyHouseAuthDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141a57c40
void UIMyHouseAuthDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}

// MS2-FUNCTIONAL: the exe returns (vfunc_55() ? that value : m_30 == 0) as a bool; the shared slot 79 is declared void
// @0x141a57c60
void UIMyHouseAuthDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
        FUN_140a467d0(&m_30);
}

// @0x141a57cc0
int UIMyHouseAuthDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0))
        return 1;
    if (_stricmp("onCancel", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnConfirm", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nValue = data.FUN_1422b8b10();
            bool bFirst = data.FUN_1422b8a90();
            bool bSecond = data.FUN_1422b8a90();
        }
    }
    return 0;
}

// @0x141a57e10
int UIMyHouseAuthDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nButton = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x141a57f20
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
