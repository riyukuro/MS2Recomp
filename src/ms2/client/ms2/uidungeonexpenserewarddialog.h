// uidungeonexpenserewarddialog.h - UIDungeonExpenseRewardDialog (RTTI .?AUIDungeonExpenseRewardDialog@@, 0x1a0 bytes,
// UIDialog, UI id 0x4ef8, swf "DungeonExpenseRewardDialog"): the confirm box shown for a dungeon reward that costs
// something; the text ("m_text" / "textField") is set from m_178 and the two buttons accept / cancel (open / close).
// Owning unit: ?\uidungeonexpenserewarddialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_DxButton;

class UIDungeonExpenseRewardDialog : public UIDialog
{
public:
    UIDungeonExpenseRewardDialog();                             // 0x140f3a810
    virtual ~UIDungeonExpenseRewardDialog();                    //  0 0x140f3a8c0 (??_G 0x140f3b1f0)
    virtual CString vfunc_1();                                  //  1 0x140f3a940 "DungeonExpenseRewardDialog"
    virtual void OnLoadComplete();                              // 22 0x140f3a990 hook the buttons, set the text
    virtual void vfunc_43();                                    // 43 0x140f3ac60 anchor the swf window
    virtual int vfunc_48() { return 0x4ef8; }                   // 48 0x140f3b230
    virtual void vfunc_67();                                    // 67 0x140f3ad00

    void FUN_140f3ad50();                                       // set the text
    void FUN_140f3ae40(int nRoomId, int nUnused);                            // close unless the room still qualifies
    void FUN_140f3aee0(const Scaleform::GFx::FunctionHandler::Params& params);   // accept clicked
    void FUN_140f3af10(const Scaleform::GFx::FunctionHandler::Params& params);   // cancel clicked

private:
    MS2Ptr<Unk_DxButton> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_DxButton>& out);   // 0x140bc6d10 returns by value (hidden return pointer)
    CStringW m_178;                                             // +0x178 the message
    MS2Ptr<Unk_DxButton> m_acceptButton;                        // +0x180 "m_acceptButton"
    MS2Ptr<Unk_DxButton> m_cancelButton;                        // +0x190 "m_cancelButton"
};
MS2_CHECK_SIZE(UIDungeonExpenseRewardDialog, 0x1a0);
