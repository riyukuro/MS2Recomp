// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDungeonExpenseRewardDialog: the paid dungeon reward box.
// MS2-UNIT: ?\uidungeonexpenserewarddialog.cpp
// MS2-RANGE: 0x140f3a810-0x140f3b490 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonexpenserewarddialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uidungeonexpenserewarddialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce240
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> DxClickDelegate;

class ASDialog : public ASDisplayObject
{
};


void FUN_140cff310(const Scaleform::GFx::Value&, CString, CString, CStringW);     // set a text clip's text
int FUN_1418dd0d0();                                                    // the screen margin

// The network / host singleton: only the slot 43 (set a mode) is used here.
class Unk_DxHost
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42();
    virtual void vfunc_43(int a, int b, int c);
};
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()

// @0x140f3a810
UIDungeonExpenseRewardDialog::UIDungeonExpenseRewardDialog()
{
    SetTweenEnabled(1);
    SetFlag(0, 1);
}

// @0x140f3a8c0
UIDungeonExpenseRewardDialog::~UIDungeonExpenseRewardDialog()
{
}

// @0x140f3a940
CString UIDungeonExpenseRewardDialog::GetTypeName()
{
    return "DungeonExpenseRewardDialog";
}
MS2_REPLACE_METHOD(0x140F3A940, UIDungeonExpenseRewardDialog, GetTypeName, 61, 0xF8A33BFF);

// MS2-FUNCTIONAL: OnLoadComplete: the exe keeps the MS2Ptr temps and delegate copies of each button hook (larger frame)
// @0x140f3a990
void UIDungeonExpenseRewardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_acceptButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_acceptButton)))
        m_acceptButton->FUN_1422ce240(DxClickDelegate(this, &UIDungeonExpenseRewardDialog::OnAccept), 0);
    if (reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_cancelButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_cancelButton)))
        m_cancelButton->FUN_1422ce240(DxClickDelegate(this, &UIDungeonExpenseRewardDialog::OnCancel), 0);
    SetText();
    ((class Unk_DxHost*)((void*)GetClientPlatform()))->vfunc_43(2, 0, 1000);
}

// @0x140f3ac60
void UIDungeonExpenseRewardDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        int nMargin = FUN_1418dd0d0() + 0x3c;
        pDialog->vfunc_2(8, 0x14, nMargin * -1);
    }
}

// @0x140f3ad00
void UIDungeonExpenseRewardDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_acceptButton = 0;
    m_cancelButton = 0;
}

// @0x140f3ad50
void UIDungeonExpenseRewardDialog::SetText()
{
    if (FUN_1422dc2d0() == 0)
        return;
    FUN_140cff310(FUN_1422dbc00(), "m_text", "textField", m_178);
}

// @0x140f3ae40
void UIDungeonExpenseRewardDialog::FUN_140f3ae40(int nRoomId, int nUnused)
{
    DungeonRoomPtr room = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(nRoomId);
    if (room == 0)
        return;
    if (FUN_141924630() != 0)
        vfunc_68();
    FUN_141924680();
}

// @0x140f3aee0
void UIDungeonExpenseRewardDialog::OnAccept(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_68();
}

// @0x140f3af10
void UIDungeonExpenseRewardDialog::OnCancel(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_67();
}
