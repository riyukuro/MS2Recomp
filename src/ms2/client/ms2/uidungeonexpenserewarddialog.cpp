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

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> DxClickDelegate;

class Unk_DxButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(const DxClickDelegate& onClick, int nFlags);     // click callback
};

class ASDialog : public ASDisplayObject
{
};

// The room record handle (released through FUN_14031c0f0) and the room table.
void FUN_14031c0f0(struct Unk_DxRoomRef* pRoom);
struct Unk_DxRoomRef { void* m_0; void* m_8; ~Unk_DxRoomRef() { FUN_14031c0f0(this); } };
class Unk_DxRoomTable { public: Unk_DxRoomRef FUN_1403206b0(int nRoomId); };
Unk_DxRoomTable* FUN_14031c2a0();
bool FUN_140334010(Unk_DxRoomRef* pRoom, int n);

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
Unk_DxHost* FUN_140d86260();

// @0x140f3a810
UIDungeonExpenseRewardDialog::UIDungeonExpenseRewardDialog()
{
    FUN_141924170(1);
    FUN_141925e70(0, 1);
}

// @0x140f3a8c0
UIDungeonExpenseRewardDialog::~UIDungeonExpenseRewardDialog()
{
}

// @0x140f3a940
CString UIDungeonExpenseRewardDialog::vfunc_1()
{
    return "DungeonExpenseRewardDialog";
}
MS2_REPLACE_METHOD(0x140F3A940, UIDungeonExpenseRewardDialog, vfunc_1, 61, 0xF8A33BFF);

// MS2-FUNCTIONAL: OnLoadComplete: the exe keeps the MS2Ptr temps and delegate copies of each button hook (larger frame)
// @0x140f3a990
void UIDungeonExpenseRewardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_140bc6d10("m_acceptButton", m_acceptButton).get() != 0)
        m_acceptButton->FUN_1422ce240(DxClickDelegate(this, &UIDungeonExpenseRewardDialog::FUN_140f3aee0), 0);
    if (FUN_140bc6d10("m_cancelButton", m_cancelButton).get() != 0)
        m_cancelButton->FUN_1422ce240(DxClickDelegate(this, &UIDungeonExpenseRewardDialog::FUN_140f3af10), 0);
    FUN_140f3ad50();
    FUN_140d86260()->vfunc_43(2, 0, 1000);
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
void UIDungeonExpenseRewardDialog::FUN_140f3ad50()
{
    if (FUN_1422dc2d0() == 0)
        return;
    FUN_140cff310(FUN_1422dbc00(), "m_text", "textField", m_178);
}

// @0x140f3ae40
void UIDungeonExpenseRewardDialog::FUN_140f3ae40(int nRoomId, int nUnused)
{
    Unk_DxRoomRef room = FUN_14031c2a0()->FUN_1403206b0(nRoomId);
    if (FUN_140334010(&room, 0))
        return;
    if (FUN_141924630() != 0)
        vfunc_68();
    FUN_141924680();
}

// @0x140f3aee0
void UIDungeonExpenseRewardDialog::FUN_140f3aee0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_68();
}

// @0x140f3af10
void UIDungeonExpenseRewardDialog::FUN_140f3af10(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_67();
}
