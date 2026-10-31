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

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> KsClickDelegate;

class Unk_KsButton : public ASMovieClip
{
public:
    void FUN_1422ce240(const KsClickDelegate& onClick, int nFlags);     // click callback
};

// The click event: the pressed button's index is read from the second pointer (+0x30).
struct Unk_KsParams { char m_pad[0x30]; void* m_pButton; };
int FUN_140bd09c0(void* pButton);                                       // which button (2 = the mouse layout)

class Unk_KsKeyBinds;                                                   // the key binding table
class Unk_SoundSink* FUN_1409331f0();   // C3: was FUN_1409331f0
class CKeyTable   // C3: member view for the former free stand-ins
{
public:
    int GetLocked();
};
void FUN_1414297e0(Unk_KsKeyBinds* p, const CString& strXml, int n);    // load the key xml

class Unk_KsInputState                                                  // singleton at FUN_1409a8b10
{
public:
    char m_pad[0x30];
    char m_mouse[1];                                                    // +0x30
};
Unk_KsInputState* FUN_1409a8b10();
void* FUN_140c58ac0(Unk_KsInputState* p);
void FUN_14125bd20(struct Unk_InterfaceFlag*, bool);   // C3: was FUN_14125bd20
class CGameOption   // C3: member view for the former free stand-ins
{
public:
    void FUN_141243540();
};
class UIGameOptionDialog* FUN_140a02e60(int);   // C3: was FUN_140a02e60
class UIGameOptionDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419438b0();
};
class UIMainPlayerInfo* FUN_140931900(int);   // C3: was FUN_140931900
class UIMainPlayerInfo   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419f19c0();
};
class CGameOptionInputDefault   // C3: member view for the former free stand-ins
{
public:
    static void FUN_1412533f0();
};

// @0x140c581a0
UIKeySettingSelectDialog::UIKeySettingSelectDialog()
{
    m_80 = 0;
    FUN_141924170(1);
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
    int bOn = ((class CKeyTable*)(class Unk_KsKeyBinds*)(((class Unk_KsKeyBinds*)FUN_1409331f0())))->GetLocked() == 0;
    if (FUN_140bc6d10("m_button1", m_button1))
    {
        m_button1->FUN_1422ce240(KsClickDelegate(this, &UIKeySettingSelectDialog::FUN_140c58690), 1);
        m_button1->FUN_1422c1fe0(bOn);
    }
    if (FUN_140bc6d10("m_button2", m_button2))
    {
        m_button2->FUN_1422ce240(KsClickDelegate(this, &UIKeySettingSelectDialog::FUN_140c58690), 2);
        m_button2->FUN_1422c1fe0(bOn);
    }
}

// @0x140c58690
void UIKeySettingSelectDialog::FUN_140c58690(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nButton = FUN_140bd09c0(((Unk_KsParams*)&params)->m_pButton);
    if (nButton == 2)
    {
        FUN_1414297e0(((class Unk_KsKeyBinds*)FUN_1409331f0()), "./Data/Xml/Table/default/DefaultMouseControlKey.xml", 0);
        FUN_14125bd20((struct Unk_InterfaceFlag*)(FUN_140c58ac0(FUN_1409a8b10())), true);
    }
    else
    {
        FUN_1414297e0(((class Unk_KsKeyBinds*)FUN_1409331f0()), "./Data/Xml/Table/default/DefaultKey.xml", 0);
        FUN_14125bd20((struct Unk_InterfaceFlag*)(FUN_140c58ac0(FUN_1409a8b10())), false);
    }
    ((class CGameOption*)(class Unk_KsInputState*)(FUN_1409a8b10()))->FUN_141243540();
    void* pDlg = ((void*)FUN_140a02e60(0x4ef3));
    if (pDlg != 0)
        ((class UIGameOptionDialog*)(void*)(pDlg))->FUN_1419438b0();
    void* pInfo = ((void*)FUN_140931900(0x4e5f));
    if (pInfo != 0)
        ((class UIMainPlayerInfo*)(void*)(pInfo))->FUN_1419f19c0();
    CGameOptionInputDefault::FUN_1412533f0();
    vfunc_67();
}

// @0x140c58ac0
void* FUN_140c58ac0(Unk_KsInputState* p)
{
    return p->m_mouse;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3000-0x142ca3090 .text$yd
