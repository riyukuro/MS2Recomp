// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITutorialSkipDialog: see uitutorialskipdialog.h.
// MS2-UNIT: ?\uitutorialskipdialog.cpp
// MS2-RANGE: 0x141b33740-0x141b34100 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uitutorialskipdialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types (unrecovered helpers) ----

class Unk_TsWorld;
class Unk_TsActor;                                              // the local player
class Unk_TsAS { public: Scaleform::GFx::Value FUN_1422bb330(const char* szMethod); };   // Invoke(name)

Unk_TsWorld* FUN_1403ed2d0();
Unk_TsActor* FUN_141bd0cc0(Unk_TsWorld* pWorld);
int FUN_141654700(Unk_TsActor* pActor);                         // job
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& nArg);
CStringW FUN_141615b70(const wchar_t* szFormat, const int& nArg);
CStringW FUN_14028b8e0(const CStringW& strKey);                        // localized
void FUN_140cfefe0(const Scaleform::GFx::Value& root, CString strName, CString strField, CStringW strText);
void FUN_140cff4e0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);

// @0x141b33740
UITutorialSkipDialog::UITutorialSkipDialog()
{
    m_80 = 0;
    m_88 = 1;
    FUN_141925e70(0, 1);
}

// @0x141b337c0
UITutorialSkipDialog::~UITutorialSkipDialog()
{
}

// @0x141b33800
CString UITutorialSkipDialog::GetTypeName()
{
    return CString("TutorialSkipDialog");
}

// @0x141b33850
void UITutorialSkipDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_TsActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return;
    FUN_141923680(1);
    reinterpret_cast<Unk_TsAS*>(m_30.operator->())->FUN_1422bb330("showOnDelay");
    int nJob = FUN_141654700(pActor);
    FUN_140cfefe0(FUN_1422dbb40(), "m_contents", "textField", FUN_14028b8e0(FUN_1401ceea0(L"s_tutorial_skip_message_job{0}", nJob)));
    FUN_140cff4e0(FUN_1422dbb40(), "m_tutorialSkipButton", FUN_14028b8e0(FUN_1401ceea0(L"s_tutorial_skip_button_job{0}", nJob)));
}

// @0x141b33ad0
int UITutorialSkipDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    Unk_TsActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 1;
    if (_stricmp("onTutorialSkipButton", szMethod) == 0)
    {
        int nJob = FUN_141654700(pActor);
        CStringW strMsg = FUN_14028b8e0(FUN_141615b70(L"s_tutorial_skip_job{0}", nJob));
        FUN_140d74390(strMsg, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UITutorialSkipDialog::FUN_141b33ca0));
    }
    return 0;
}

// @0x141b33ca0
bool UITutorialSkipDialog::FUN_141b33ca0(int nResult, const CMsgBoxData&)
{
    return true;
}
