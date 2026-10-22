// uimusicconcertdialog.h - UIMusicConcertDialog (RTTI .?AVUIMusicConcertDialog@@, 0x260 bytes, UIDialog, UI id 0x4f36, swf
// "MusicConcertDialog"): the audience box of the music concert. A fold button, a top text with the concert state and six
// action buttons (register / unregister, change stage, change camera, firework, light stick, clap). Owning unit:
// ?\uimusicconcertdialog.cpp. Header name assumed from the unit path; member names are invented from use. The sibling
// UIWatchAGameDialog (uiwatchagamedialog.h) has the same button idiom.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASMovieClip;
class ASTextField;
class Unk_MusicButton;

class UIMusicConcertDialog : public UIDialog
{
public:
    UIMusicConcertDialog();                                     // 0x140e694a0
    virtual ~UIMusicConcertDialog();                            //  0 0x140e695a0 (??_G 0x140e6b4f0)
    virtual CString vfunc_1();                                  //  1 0x140e6a000 "MusicConcertDialog"
    virtual void OnLoadComplete();                              // 22 0x140e69760 bind the six action buttons, the fold button, the top text
    virtual void vfunc_26();                                    // 26 0x140e69660
    virtual void vfunc_43();                                    // 43 0x140e6a050
    virtual int vfunc_48() { return 0x4f36; }                   // 48 0x140e6b530
    virtual void vfunc_67();                                    // 67 0x140e69680 close: drop the controls
    virtual void vfunc_72();                                    // 72 0x140e69730 refresh the top text

    void FUN_140e6a0d0(const Scaleform::GFx::FunctionHandler::Params& params);   // an action button was clicked
    void FUN_140e6a1b0(const Scaleform::GFx::FunctionHandler::Params& params);   // the fold button was clicked
    void FUN_140e6a290();                                       // the top text and the first button's label
    void FUN_140e6a5d0(int nIndex, const CString& strIcon, const CStringW& strTooltip);   // icon + tooltip of one button
    void FUN_140e6a780();                                       // register button
    void FUN_140e6a9d0();                                       // unregister (after the confirm box)
    void SendPlayInstrumentMode13();                                       // stage button (packet 0x74 / 0xd)
    void FUN_140e6ab90();                                       // camera button
    void SendPlayInstrumentMode14();                                       // firework button (packet 0x74 / 0xe)
    void SendPlayInstrumentMode15(int nEmotion);                           // emotion button (packet 0x74 / 0xf)
    bool SendPlayInstrumentMode11(int nResult, const class CMsgBoxData& box);   // confirm register: packet 0x74 / 0xb
    bool SendPlayInstrumentMode12(int nResult, const class CMsgBoxData& box);   // confirm unregister: packet 0x74 / 0xc

    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);          // 0x140ba7930 bind a movie clip child
    MS2Ptr<Unk_MusicButton> FUN_140bb4b10(const CString& strName);      // 0x140bb4b10 bind a button child
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);          // 0x140bb4cf0 bind a text field child

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_clips[6];                             // +0x178 "m_actionButton1..6"
    MS2Ptr<Unk_MusicButton> m_buttons[6];                       // +0x1d8 "m_button" of each clip
    MS2Ptr<Unk_MusicButton> m_foldButton;                       // +0x238 "m_foldButton"
    MS2Ptr<ASTextField> m_topText;                              // +0x248 "m_topText"
    bool m_bFolded;                                             // +0x258
};
MS2_CHECK_SIZE(UIMusicConcertDialog, 0x260);
MS2_CHECK_OFFSET(UIMusicConcertDialog, m_clips, 0x178);
MS2_CHECK_OFFSET(UIMusicConcertDialog, m_buttons, 0x1d8);
MS2_CHECK_OFFSET(UIMusicConcertDialog, m_foldButton, 0x238);
MS2_CHECK_OFFSET(UIMusicConcertDialog, m_topText, 0x248);
MS2_CHECK_OFFSET(UIMusicConcertDialog, m_bFolded, 0x258);
