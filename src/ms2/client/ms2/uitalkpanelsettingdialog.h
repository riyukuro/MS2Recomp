// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uitalkpanelsettingdialog.h (name assumed
// from the unit path: the .cpp's __FILE__ string is not in the exe for this unit).
//
// UITalkPanelSettingDialog ("TalkPanelSettingDialog", UI type id 0x4e62, RTTI .?AVUITalkPanelSettingDialog@@, 0x190 bytes):
// the chat tab settings window of the messenger. It edits one MessengerData::TalkTab (name + its PanelSetting): the
// "m_tab" name input, the screen look sliders / damage radios and the Subject / Require / Notice / System check groups.
// FUN_141b24ee0 pushes a PanelSetting into the movie, FUN_141b23ab0 reads the movie back into one. Applying / closing
// goes through the chat tab manager (Unk_MdState +0x40) and the chat window (+0x48), see the .cpp.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASUIComponent;
class Unk_TpsButton;
namespace MessengerData { class PanelSetting; }

class UITalkPanelSettingDialog : public UIDialog
{
public:
    UITalkPanelSettingDialog();                                         // 0x141b224f0
    virtual ~UITalkPanelSettingDialog();                                //  0 0x141b22580 (??_G 0x141b265a0)
    virtual CString GetTypeName();                                          //  1 0x141b225d0 "TalkPanelSettingDialog"
    virtual int vfunc_13();                                             // 13 0x141b22970 the key handler (Enter applies)
    virtual void OnLoadComplete();                                      // 22 0x141b22730 bind the movie, show the current tab
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x141b22c60 OnOk / eventInitialize / eventApply / OnCloseDialog
    virtual int vfunc_48() { return 0x4e62; }                           // 48 0x141b265e0 UI type id
    virtual void vfunc_67();                                            // 67 0x141b226d0 Close
    virtual void vfunc_69();                                            // 69 0x141b22620 revert unless applied, then Close
    virtual void vfunc_80(void* pRequest);                              // 80 0x141b230f0 the platform request answers (OnKeyHandler / OnOk / eventApply)

    CStringW FUN_141b23550();                                           // the "m_tab" input's text
    int EventInitialize();                                                // reset the PanelSetting to the defaults and show it
    int FUN_141b236c0(const CStringW& strName);                         // validate the new tab name, apply the movie's settings; 1 = done
    int FUN_141b23a40(const CStringW& strName);                         // the chat window accepts the tab name
    void FUN_141b23ab0(MessengerData::PanelSetting* pSetting);          // movie -> PanelSetting
    void FUN_141b24ee0(MessengerData::PanelSetting* pSetting);          // PanelSetting -> movie
    MS2Ptr<Unk_TpsButton> FUN_140bb4b10(const CString& strName);         // 0x140bb4b10 bind a button child

private:
    MS2Ptr<ASUIComponent> m_spRoot;                                     // +0x178 the "m_settingMenu" clip (0x10 bytes)
    int m_bApplied;                                                     // +0x188 "eventApply" ran (do not revert on close)
    int m_pad_18c;
};
MS2_CHECK_SIZE(UITalkPanelSettingDialog, 0x190);
