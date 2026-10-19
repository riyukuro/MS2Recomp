// uinoticedialog.h - UINoticeDialog (RTTI .?AVUINoticeDialog@@ 0x143a80f70, 0x200 bytes, UI type 0x4ee9, swf "NoticeDialog"):
// the notice page shown from the game's web browser manager (a UIWebBrowserBase, uiupperhuddialog.h). The page url comes
// from the client constant NoticeDialogUrl; the page is drawn into an image that is added to the m_renderTarget child of the
// swf, a "show" button toggles the page and a "maview" button opens the in-game WebBrowser (0x4e6a). The dialog hides itself
// NoticeDialogOpenSeconds after it was shown. Header name assumed from the unit path (?\uinoticedialog.cpp,
// 0x1410084b0-0x14100a030). Names invented from the callers: FUN_<va> are non-virtual members. w408.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiupperhuddialog.h"
#include "ms2/client/ms2/uitencentaas2dialog.h"

class ASMovieClip;
class ASUIComponent;
class Unk_140acd6e0;
class NotifyObject;

class UINoticeDialog : public UIWebBrowserBase
{
public:
    UINoticeDialog();                                               // 0x1410084b0
    virtual ~UINoticeDialog();                                      //  0 0x1410085c0 (??_G 0x141009eb0, ??_E thunk 0x141009e58)

    virtual CString vfunc_1();                                      //  1 0x141008690 "NoticeDialog"
    virtual void OnLoadComplete();                                  // 22 0x141008700 bind the children
    virtual void vfunc_26();                                        // 26 0x141008e10 release the children
    virtual void vfunc_43();                                        // 43 0x141008ec0
    virtual int vfunc_48() { return 0x4ee9; }                       // 48 (COMDAT 0x141009ef0)
    virtual void vfunc_72();                                        // 72 0x141008f30 hide when the open time is over
    virtual int vfunc_73();                                         // 73 0x1410086e0
    virtual void vfunc_77();                                        // 77 0x1410093a0 focus the hit area
    virtual void vfunc_85();                                        // 85 0x141008fa0 load the render target image
    virtual void vfunc_86();                                        // 86 0x1410092a0 unload it
    virtual void vfunc_87(SIZE* pSize);                             // 87 0x1410093f0
    virtual bool vfunc_90(POINT* pPos);                             // 90 0x141009470

    void FUN_141009680(NotifyObject* pNotify);                      // 0x141009680 notice handler: restart the open time and show
    void FUN_141009710(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141009710 mouse over the hit area: vfunc_84(1)
    void FUN_141009740(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141009740 mouse out of the hit area: vfunc_84(0)
    void FUN_141009770(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141009770 "show" button
    void FUN_1410097a0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1410097a0 "maview" button: open the WebBrowser
    void FUN_1410097d0();                                           // 0x1410097d0 toggle between show and hide
    void FUN_141009870();                                           // 0x141009870 navigate the browser page to the notice url
    void FUN_141009950(int nSeconds);                               // 0x141009950 m_nHideAt = now + nSeconds
    void FUN_141009980();                                           // 0x141009980 show
    void FUN_141009a60();                                           // 0x141009a60 hide

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_mainWindow;                               // +0x198 "m_mainWindow"
    MS2Ptr<Unk_140acd6e0> m_showButton;                             // +0x1a8 "m_showButton"
    MS2Ptr<Unk_140acd6e0> m_maviewButton;                           // +0x1b8 "m_maviewButton"
    MS2Ptr<ASUIComponent> m_hitArea;                                // +0x1c8 "m_hitArea"
    MS2Ptr<ASUIComponent> m_renderTarget;                           // +0x1d8 "m_renderTarget"
    Unk_AasImagePtr m_spImage;                                      // +0x1e8 the page image
    unsigned int m_nHideAt;                                         // +0x1f8 tick (ms) after which the notice hides; 0 = none
};
MS2_CHECK_SIZE(UINoticeDialog, 0x200);
MS2_CHECK_OFFSET(UINoticeDialog, m_mainWindow, 0x198);
MS2_CHECK_OFFSET(UINoticeDialog, m_hitArea, 0x1c8);
MS2_CHECK_OFFSET(UINoticeDialog, m_spImage, 0x1e8);
MS2_CHECK_OFFSET(UINoticeDialog, m_nHideAt, 0x1f8);
