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
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2format.h"              // C3: StringFormat<T> (was FUN_1401ceea0 / FUN_141615b70)
#include "ms2/commonfiles/jobtable.h"     // C3: Unk_JobCode

// ---- unit-local views of exe types (unrecovered helpers) ----

class Unk_TsWorld;
class Unk_TsActor;                                              // the local player
   // Invoke(name)

class PC { public: int GetJobGroupId(); };   // C3: member view (0x141654700, the job)
CStringW GetStringCommonByKey(const CStringW& strKey);                        // localized
void SetNestedChildText(const Scaleform::GFx::Value& root, CString strName, CString strField, CStringW strText);
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
    Unk_TsActor* pActor = ((Unk_TsActor*)((WorldService*)(reinterpret_cast<Unk_TsWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pActor == 0)
        return;
    FUN_141923680(1);
    reinterpret_cast<AScript*>(m_30.operator->())->Invoke("showOnDelay");
    int nJob = ((PC*)pActor)->GetJobGroupId();
    SetNestedChildText(FUN_1422dbb40(), "m_contents", "textField", GetStringCommonByKey(StringFormat(L"s_tutorial_skip_message_job{0}", nJob)));
    FUN_140cff4e0(FUN_1422dbb40(), "m_tutorialSkipButton", GetStringCommonByKey(StringFormat(L"s_tutorial_skip_button_job{0}", nJob)));
}

// @0x141b33ad0
int UITutorialSkipDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    Unk_TsActor* pActor = ((Unk_TsActor*)((WorldService*)(reinterpret_cast<Unk_TsWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pActor == 0)
        return 1;
    if (_stricmp("onTutorialSkipButton", szMethod) == 0)
    {
        int nJob = ((PC*)pActor)->GetJobGroupId();
        CStringW strMsg = GetStringCommonByKey(StringFormat(L"s_tutorial_skip_job{0}", reinterpret_cast<const Unk_JobCode&>(nJob)));
        FUN_140d74390(strMsg, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UITutorialSkipDialog::FUN_141b33ca0));
    }
    return 0;
}

// @0x141b33ca0
bool UITutorialSkipDialog::FUN_141b33ca0(int nResult, const CMsgBoxData&)
{
    return true;
}
