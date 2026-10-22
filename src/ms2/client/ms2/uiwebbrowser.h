// uiwebbrowser.h - UIWebBrowser (RTTI .?AVUIWebBrowser@@, 0x220 bytes, UIWebBrowserBase, UI id 0x4e6a, swf "WebBrowser"): the
// in-game browser window (home / back / forward / refresh buttons, min / max size toggle). The browser pages live in the exe's
// browser manager; it also registers for the "NotifyGameStart" notice to forget the stored page. Owning unit:
// ?\uiwebbrowser.cpp. Header name assumed from the unit path; member names are inferred, FUN_<va> are non-virtual members.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiupperhuddialog.h"
#include "ms2/placeholder/delegate.h"

class NotifyObject;
class Unk_140acd6e0;

class UIWebBrowser : public UIWebBrowserBase
{
public:
    UIWebBrowser();                                             // 0x141b4f220
    virtual ~UIWebBrowser();                                    //  0 0x141b4f470 (??_G 0x141b513a0, ??_E thunk 0x141b51290)
    virtual CString GetTypeName();                                  //  1 0x141b4f620 "WebBrowser"
    virtual void OnLoadInit();                                  // 20 0x141b4f690 read the sizes from the constants
    virtual void OnLoadComplete();                              // 22 0x141b4f820 bind the buttons
    virtual void vfunc_26();                                    // 26 0x141b50250
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b50530
    virtual void vfunc_43();                                    // 43 0x141b50380
    virtual int vfunc_48() { return 0x4e6a; }                   // 48 (COMDAT 0x141b513e0)
    virtual int vfunc_65();                                     // 65 0x141b4f670
    virtual void vfunc_84(bool bVisible);                       // 84 0x141b50610
    virtual int vfunc_88();                                     // 88 0x141b503c0 2 when the window has its small size
    virtual void vfunc_89(const CString& strUrl);               // 89 0x141b50680 navigate
    virtual bool vfunc_91();                                    // 91 0x141b50990 resizable

    void FUN_141b50420(NotifyObject* pNotify);                  // 0x141b50420 "NotifyGameStart": forget the stored page
    void SetStored(const CString& strUrl);                  // 0x141b50450 browser callback: remember the page
    void FUN_141b50490(const CString& strKey);                  // 0x141b50490 navigate to the page stored under a key
    void FUN_141b507b0(int nWidth, int nHeight);                // 0x141b507b0 "setBrowserSize"
    void FUN_141b50830(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b50830 navigation button
    void FUN_141b50890(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b50890 "min size" button
    void FUN_141b50910(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b50910 "max size" button
    void FUN_141b509b0();                                       // 0x141b509b0 show the min / max size button that applies
    template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out);   // 0x140bc6d10 bind a child

protected:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_140acd6e0> m_btnHome;            // +0x198 "m_btnHome"
    MS2Ptr<Unk_140acd6e0> m_btnPrev;            // +0x1a8 "m_btnPrev"
    MS2Ptr<Unk_140acd6e0> m_btnNext;            // +0x1b8 "m_btnNext"
    MS2Ptr<Unk_140acd6e0> m_btnRefresh;         // +0x1c8 "m_btnRefresh"
    MS2Ptr<Unk_140acd6e0> m_btnMinSize;         // +0x1d8 "m_btnMinSize"
    MS2Ptr<Unk_140acd6e0> m_btnMaxSize;         // +0x1e8 "m_btnMaxSize"
    CString m_strStored;                        // +0x1f8 the page reported by the browser
    int m_nWidth;                               // +0x200 current browser size
    int m_nHeight;                              // +0x204
    int m_nSmallSize;                           // +0x208 "m_textureSize"
    int m_nMinWidth;                            // +0x20c the constants: small size
    int m_nMinHeight;                           // +0x210
    int m_nMaxWidth;                            // +0x214 large size
    int m_nMaxHeight;                           // +0x218
    bool m_bResizable;                          // +0x21c
};
MS2_CHECK_SIZE(UIWebBrowser, 0x220);
MS2_CHECK_OFFSET(UIWebBrowser, m_btnHome, 0x198);
MS2_CHECK_OFFSET(UIWebBrowser, m_btnMaxSize, 0x1e8);
MS2_CHECK_OFFSET(UIWebBrowser, m_strStored, 0x1f8);
MS2_CHECK_OFFSET(UIWebBrowser, m_nWidth, 0x200);
MS2_CHECK_OFFSET(UIWebBrowser, m_bResizable, 0x21c);
