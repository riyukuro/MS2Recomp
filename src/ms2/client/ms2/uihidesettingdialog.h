// uihidesettingdialog.h - UIHideSettingDialog (RTTI .?AVUIHideSettingDialog@@, 0x1c0 bytes): the "hide UI" settings
// dialog listing the HUDs and dialogs that can be hidden (one check box each, grouped by kind). Recovered with
// ?\uihidesettingdialog.cpp; header name and directory assumed. Base UIDialog (uidialog.h).
// Primary vftable 0x142fb0578 (84 slots), IMessageListener-in-UIHideSettingDialog 0x142fb0820. Ctor 0x141986ea0,
// dtor 0x141986f30 (??_G 0x141989300).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class ASObj;

namespace UIHideSettingDialogDef
{
// One entry of the list: a UI (by type id) with its label and kind (0 HUD, 1 dialog, 2 other). RTTI
// .?AUSwfInfo@UIHideSettingDialogDef@@, vftable 0x142fb0568, 0x28 bytes.
struct SwfInfo : public CPtred
{
    SwfInfo();                                                              // 0x141986d90
    void FUN_141986df0(ASObj& obj, bool bSelected);                         // fills a list row: name, label, selected

    CStringW m_strName;                 // +0x18 label (the UI's GetTypeName() unless given)
    int m_nId;                          // +0x20 UI type id (vfunc_48)
    int m_nType;                        // +0x24 0 HUD, 1 dialog, 2 other (the index of the list group)
};
MS2_CHECK_SIZE(SwfInfo, 0x28);
}

class UIHideSettingDialog : public UIDialog
{
public:
    UIHideSettingDialog();                                                  // 0x141986ea0
    virtual ~UIHideSettingDialog();                                         //  0 0x141986f30 (??_G 0x141989300)
    virtual CString GetTypeName();                                              //  1 0x141986fa0 "HideSettingDialog"
    virtual void vfunc_10();                                                // 10 0x141986ff0 clears the list
    virtual int vfunc_13();                                                 // 13 0x141987450 Enter: onEnterKey
    virtual void OnLoadComplete();                                          // 22 0x141987020 registers the UIs, builds the list
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);    // 28 0x1419874f0
    virtual int vfunc_48() { return 0x4e50; }                               // 48 0x1419897e0 (inline: emitted after ??_G)

    void FUN_141987990();                                                   // sends the grouped list to AS ("buildList")
    void FUN_141987f50(int nId, const CStringW& strLabel);                 // adds the UI nId to the list

protected:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<CString, MS2Ptr<UIHideSettingDialogDef::SwfInfo>, ATL::CStringElementTraits<CString> > m_178;    // +0x178 by class name
};
MS2_CHECK_SIZE(UIHideSettingDialog, 0x1c0);
MS2_CHECK_OFFSET(UIHideSettingDialog, m_178, 0x178);
