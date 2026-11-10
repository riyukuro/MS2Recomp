// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIKeySettingSelectDialog: choose the default key layout.
// MS2-UNIT: ?\uikeysettingselectdialog.cpp
// MS2-RANGE: 0x1400cdba0-0x1400cdd10 .text$di
// MS2-RANGE: 0x140c581a0-0x140c58d30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uikeysettingselectdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uikeysettingselectdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cgameoption.h"  // C3: was a local member view
#include "ms2/client/ms2/uigameoptiondialog.h"  // C3: was a local member view
#include "ms2/client/ms2/uimainplayerinfo.h"  // C3: was a local member view
#include "ms2/client/ms2/gameoptioninputdefault.h"  // C3: was a local member view
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce240
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> KsClickDelegate;

// The click event: the pressed button's index is read from the second pointer (+0x30).
struct Unk_KsParams { char m_pad[0x30]; void* m_pButton; };
int FUN_140bd09c0(void* pButton);                                       // which button (2 = the mouse layout)

class Unk_KsKeyBinds;                                                   // the key binding table
class Unk_SoundSink* GetKeyTable();   // C3: was GetKeyTable
class CKeyTable   // C3: member view for the former free stand-ins
{
public:
    int GetLocked(); int FUN_1414297e0(const CString& strPath, int n);
};


// C3: the former input-state stand-in is CGameOption (singleton at FUN_1409a8b10); its +0x30 member is
//     CGameOption::m_interfaceChar, and 0x140c58ac0 is CGameOption::GetInterfaceChar (cgameoption.h)
//
//
//
//
//
void FUN_14125bd20(struct Unk_InterfaceFlag*, bool);   // C3: was FUN_14125bd20
class UIGameOptionDialog* FindGameOptionDialog(int);   // C3: was FindGameOptionDialog
class UIMainPlayerInfo* FindMainPlayerInfo(int);   // C3: was FindMainPlayerInfo

// @0x140c581a0
UIKeySettingSelectDialog::UIKeySettingSelectDialog()
{
    m_80 = 0;
    SetTweenEnabled(1);
}

// @0x140c58240
UIKeySettingSelectDialog::~UIKeySettingSelectDialog()
{
    m_button1 = 0;
    m_button2 = 0;
}

// @0x140c582e0
CString UIKeySettingSelectDialog::GetTypeName()
{
    return "KeySettingSelectDialog";
}
MS2_REPLACE_METHOD(0x140C582E0, UIKeySettingSelectDialog, GetTypeName, 61, 0x1E8AD39C);

// @0x140c58330
void UIKeySettingSelectDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_button1 = 0;
    m_button2 = 0;
}

// @0x140c58380
void UIKeySettingSelectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    int bOn = ((class CKeyTable*)(class Unk_KsKeyBinds*)(((class Unk_KsKeyBinds*)GetKeyTable())))->GetLocked() == 0;
    if (reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_button1", reinterpret_cast<MS2Ptr<ASButton>&>(m_button1)))
    {
        m_button1->AddClickHandler(KsClickDelegate(this, &UIKeySettingSelectDialog::FUN_140c58690), (void*)1);
        m_button1->SetEnabled(bOn);
    }
    if (reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_button2", reinterpret_cast<MS2Ptr<ASButton>&>(m_button2)))
    {
        m_button2->AddClickHandler(KsClickDelegate(this, &UIKeySettingSelectDialog::FUN_140c58690), (void*)2);
        m_button2->SetEnabled(bOn);
    }
}

// @0x140c58690
void UIKeySettingSelectDialog::FUN_140c58690(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nButton = FUN_140bd09c0(((Unk_KsParams*)&params)->m_pButton);
    if (nButton == 2)
    {
        ((class CKeyTable*)GetKeyTable())->FUN_1414297e0("./Data/Xml/Table/default/DefaultMouseControlKey.xml", 0);
        FUN_14125bd20((struct Unk_InterfaceFlag*)(TSingleton<CGameOption>::GetInstance()->GetInterfaceChar()), true);
    }
    else
    {
        ((class CKeyTable*)GetKeyTable())->FUN_1414297e0("./Data/Xml/Table/default/DefaultKey.xml", 0);
        FUN_14125bd20((struct Unk_InterfaceFlag*)(TSingleton<CGameOption>::GetInstance()->GetInterfaceChar()), false);
    }
    TSingleton<CGameOption>::GetInstance()->SaveCharacterSettings();
    void* pDlg = ((void*)FindGameOptionDialog(0x4ef3));
    if (pDlg != 0)
        ((class UIGameOptionDialog*)(void*)(pDlg))->ReopenCurrentTab();
    void* pInfo = ((void*)FindMainPlayerInfo(0x4e5f));
    if (pInfo != 0)
        ((class UIMainPlayerInfo*)(void*)(pInfo))->RefreshQuickSlots();
    CGameOptionInputDefault::FUN_1412533f0();
    vfunc_67();
}

// @0x140c58ac0
Unk_InterfaceFlag* CGameOption::GetInterfaceChar()
{
    return &m_interfaceChar;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3000-0x142ca3090 .text$yd
