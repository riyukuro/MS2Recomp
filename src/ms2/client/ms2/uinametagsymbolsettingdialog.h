// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uinametagsymbolsettingdialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UINameTagSymbolSettingDialog ("NameTagSymbolSettingDialog", UI type 0x4ed5): the picker for the symbol shown on the
// player's name tag. OnLoadComplete fills the "m_list" of the movie with one row per symbol the name tag symbol manager
// (global at 0x143ab05b8) knows - skipping unknown ids and symbols the manager reports as hidden - and selects the
// symbol the player currently wears. "onOk" sends packet 0x6b with the picked symbol id (when the manager allows it),
// "onCancel" and "onOk" both close the dialog. RTTI .?AVUINameTagSymbolSettingDialog@@, 0x178 bytes (no members of its
// own), vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_NtList;

class UINameTagSymbolSettingDialog : public UIDialog
{
public:
    UINameTagSymbolSettingDialog();                             // 0x14131d910
    virtual ~UINameTagSymbolSettingDialog();                    //  0 0x14131d980 (??_G 0x14131e0e0)
    virtual CString GetTypeName();                                  //  1 0x14131d9c0 "NameTagSymbolSettingDialog"
    virtual void OnLoadComplete();                              // 22 0x14131da30 fill the symbol list
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x14131df40 "onOk" / "onCancel"
    virtual int vfunc_48();                                     // 48 0x14131e140
    virtual void vfunc_67();                                    // 67 0x14131da10 close
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x14131def0

    MS2Ptr<Unk_NtList> FUN_140c02900(const CString& strName);   // bind a list child
};
MS2_CHECK_SIZE(UINameTagSymbolSettingDialog, 0x178);
