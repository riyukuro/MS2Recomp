// uiwatchagamedialog.h - UIWatchAGameDialog (RTTI .?AVUIWatchAGameDialog@@, 0x238 bytes, UIDialog, UI id 0x4f91, swf
// "WatchAGameDialog"): the spectator box of the hide and seek / arcade games. A fold button, and up to four action buttons
// (change camera, reset camera, light stick, clap) that each have an icon and a tooltip. Owning unit:
// ?\uiwatchagamedialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASMovieClip;
class Unk_140acd6e0;

class UIWatchAGameDialog : public UIDialog
{
public:
    UIWatchAGameDialog();                                       // 0x140fc07a0
    virtual ~UIWatchAGameDialog();                              //  0 0x140fc0930 (??_G 0x140fc1ca0)
    virtual CString GetTypeName();                                  //  1 0x140fc09f0 "WatchAGameDialog"
    virtual void OnLoadComplete();                              // 22 0x140fc0bf0 bind the buttons
    virtual void vfunc_43();                                    // 43 0x140fc1300
    virtual int vfunc_48() { return 0x4f91; }                   // 48 0x140fc1ce0
    virtual void vfunc_67();                                    // 67 0x140fc0a40

    void SetValue(int nValue);                             // 0x140fc0b20
    void SetCharId(int nCharId);                            // 0x140fc0b40
    void FUN_140fc0b60(bool bFlag);                             // 0x140fc0b60 remember the flag, push "foldDialog"
    void FUN_140fc1380(const Scaleform::GFx::FunctionHandler::Params& params);   // an action button was clicked
    void FUN_140fc1440(const Scaleform::GFx::FunctionHandler::Params& params);   // the fold button was clicked
    void FUN_140fc1560(int nIndex, const CString& strIcon, const CStringW& strTooltip);   // icon + tooltip of one action button
    void FUN_140fc1710();                                       // next camera
    void FUN_140fc17d0();                                       // reset the camera
    void FUN_140fc1850(int nEmotion);                           // play an emotion on the own player

    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);          // 0x140ba7930 bind a movie clip child
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);        // 0x140bb4b10 bind a button child

private:
    MS2_LAYOUT_FRIEND;
    bool m_bFolded;                                             // +0x178
    int m_nValue;                                               // +0x17c
    int m_nCharId;                                              // +0x180
    bool m_bFlag;                                               // +0x184
    int m_nCamera;                                              // +0x188 index into m_cameras, -1 = none
    std::vector<int> m_cameras;                                 // +0x190 the camera triggers
    MS2Ptr<Unk_140acd6e0> m_foldButton;                         // +0x1a8 "m_foldButton"
    MS2Ptr<Unk_140acd6e0> m_buttons[4];                         // +0x1b8 "m_button" of each action clip
    MS2Ptr<ASMovieClip> m_clips[4];                             // +0x1f8 "m_actionButton1..4"
};
MS2_CHECK_SIZE(UIWatchAGameDialog, 0x238);
MS2_CHECK_OFFSET(UIWatchAGameDialog, m_cameras, 0x190);
MS2_CHECK_OFFSET(UIWatchAGameDialog, m_foldButton, 0x1a8);
MS2_CHECK_OFFSET(UIWatchAGameDialog, m_buttons, 0x1b8);
MS2_CHECK_OFFSET(UIWatchAGameDialog, m_clips, 0x1f8);
