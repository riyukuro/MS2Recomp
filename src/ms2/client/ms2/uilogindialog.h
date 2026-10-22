// uilogindialog.h - UILoginDialog (RTTI .?AVUILoginDialog@@, 0x188 bytes, UIDialog, UI id 0x4e22, swf "LoginDialog"): the
// account / password dialog of the login scene (UISceneLogin). "OnConnect" sends the login request (packet 3), the
// two packet handlers it registers react to the answer. Owning unit: ?\uilogindialog.cpp. Header name assumed from the
// unit path; member names are inferred, FUN_<va> are non-virtual members.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"

class ASMovieClip;
class CInPacket;
class CMsgBoxData;
class Unk_LoginInput;
struct Unk_LoginRequest;

class UILoginDialog : public UIDialog
{
public:
    UILoginDialog();                                            // 0x1419e0cb0
    virtual ~UILoginDialog();                                   //  0 0x1419e0e80 (??_G 0x1419e3130)
    virtual CString vfunc_1();                                  //  1 0x1419e0ff0 "LoginDialog"
    virtual int vfunc_13();                                     // 13 0x1419e19e0 enter / tab key
    virtual void OnLoadComplete();                              // 22 0x1419e1690 initData
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419e1ad0
    virtual void vfunc_43();                                    // 43 0x1419e2100
    virtual int vfunc_48() { return 0x4e22; }                   // 48 0x1419e3170
    virtual void vfunc_67();                                    // 67 0x1419e1670
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1419e1860

    void OnEndPopdown(char bFromPopdown);                      // 0x1419e1040 open the web page (not while the login scene shows a region list)
    void FUN_1419e1160(CInPacket& iPacket);                     // 0x1419e1160 packet 9: send the login request
    void FUN_1419e1570(CInPacket& iPacket);                     // 0x1419e1570 packet 0x134: the answer to "delete account"
    CString FUN_1419e2370();                                    // 0x1419e2370 the typed account id
    CString FUN_1419e2450();                                    // 0x1419e2450 the typed password
    MS2Ptr<Unk_LoginInput> FUN_1419e2530();                     // 0x1419e2530 "m_inputID"
    template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out);   // 0x140bc6d10 bind a child
    MS2Ptr<Unk_LoginInput> FUN_1419e25e0();                     // 0x1419e25e0 "m_inputPW"
    bool FUN_1419e2690(int nResult, const CMsgBoxData& box);    // 0x1419e2690 message box answer: check "m_chkLocaledName"
    bool FUN_1419e2730(int nResult, const CMsgBoxData& box);    // 0x1419e2730 message box answer: check "m_chkLocaledName" on yes
    void FUN_1419e27d0();                                       // 0x1419e27d0 enter the failure state
    void FUN_1419e28a0();                                       // 0x1419e28a0 leave it
    int FUN_1419e2900();                                        // 0x1419e2900 the input has the focus
    void OnConnect();                                       // 0x1419e2920 connect: hide the dialog through the scene
    bool FUN_1419e21e0(CStringW strMessage);                    // 0x1419e21e0 show the message box (callback FUN_1419e22e0)
    bool FUN_1419e22e0(int nResult, const CMsgBoxData& box);    // 0x1419e22e0 its answer
    bool FUN_1419e2310(int nResult);                            // 0x1419e2310

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_178;                                  // +0x178 constructed and released, never used
};
MS2_CHECK_SIZE(UILoginDialog, 0x188);
MS2_CHECK_OFFSET(UILoginDialog, m_178, 0x178);
