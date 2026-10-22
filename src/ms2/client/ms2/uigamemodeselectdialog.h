// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uigamemodeselectdialog.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UIGameModeSelectDialog (RTTI .?AVUIGameModeSelectDialog@@, UI type 0x4f6e, swf "GameModeSelectDialog") is the popup
// that lets the player pick between the rpg and the royale game mode. Its only control is the "m_start" button; the movie
// gets the two movie paths ("rpgMoviePath", "royaleMoviePath") from the constants table.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_GmStartButton;

class UIGameModeSelectDialog : public UIDialog
{
public:
    UIGameModeSelectDialog();                                   // 0x140c19f20 (m_80 = 0, FUN_141925e70(0, 1))
    virtual ~UIGameModeSelectDialog();                          //  0 0x140c19fb0 (??_G 0x140c1a850)
    virtual CString GetTypeName();                                  //  1 0x140c1a000 "GameModeSelectDialog"
    virtual int vfunc_13();                                     // 13 0x140c1a3e0 (UIDialog::vfunc_13() != 0)
    virtual void OnLoadComplete();                              // 22 0x140c1a070 bind "m_start", push "initData"
    virtual void vfunc_26();                                    // 26 0x140c1a4b0 release the button
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c1a410 "OnEndPopdown"
    virtual void vfunc_43();                                    // 43 0x140c1a4f0
    virtual int vfunc_48() { return 0x4f6e; }                   // 48 0x140c1a890
    virtual void vfunc_67();                                    // 67 0x140c1a050
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140c1a390 (UIDialog::OnMessage != 0)

    void FUN_140c1a510(const Scaleform::GFx::FunctionHandler::Params& params);   // "m_start" clicked: popdown

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_GmStartButton> m_178;                            // +0x178 "m_start"
};
MS2_CHECK_SIZE(UIGameModeSelectDialog, 0x188);
