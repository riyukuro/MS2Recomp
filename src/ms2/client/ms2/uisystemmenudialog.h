// uisystemmenudialog.h - the in-game system menu (RTTI UISystemMenuDialog, UI id 0x4e21; "m_exitRoom" button, channel list):
// opens the game option / character select / channel change entries and the leave-the-room box. NOT an original header
// (the unit is ?\uisystemmenudialog.cpp). Member and helper names are invented from use.
// Bases: UIDialog (with its IMessageListener at +0x18) and the server event listener at +0x178.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiservereventdispatcher.h"
#include "ms2/placeholder/ascript.h"

class CMsgBoxData;
class ASButton;                                    // a button child

class UISystemMenuDialog : public UIDialog, public UIServerEventListener
{
public:
    UISystemMenuDialog();                               // 0x141b12ad0
    virtual ~UISystemMenuDialog() {}                     // 0x141b12ba0 (??_G 0x141b15620)
    virtual CString GetTypeName();
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void OnLoadInit();
    virtual void vfunc_26();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual int vfunc_48() { return 0x4e21; }           // 0x141b15660
    virtual void vfunc_79(void* p);
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    // UIServerEventListener
    virtual void Notify();                              // 0x141b13640 fill the channel list

    void OnLeaveFieldClick(const Scaleform::GFx::FunctionHandler::Params& params);   // the leave click of a normal field
    void OnLeaveHomeClick(const Scaleform::GFx::FunctionHandler::Params& params);   // the leave click of a home (forwards)
    void LeaveHome();                               // leave the home: ask first when the build is not saved
    void SetRedCircle(bool b);                         // set the red circle flag
    bool FUN_141b14510(int nResult, const CMsgBoxData& data);   // answer of the leave box
    void OpenGameOptionDialog(int nPage);                      // open the option dialog at a page
    void RequestQuit();
    void OnSelectCharacter();                               // back to the character select
    void SelectCurrentChannel();                               // select the current channel in the list
    CStringW GetLeaveButtonText(int nMapType);               // the leave button text
    CStringW GetLeaveBoxText(int nMapType);               // the leave box text

private:
    MS2_LAYOUT_FRIEND;
    int m_180;                                          // +0x180 the selected channel
    MS2Ptr<ASButton> m_188;                        // +0x188 "m_exitRoom"
    bool m_198;                                         // +0x198 the system option notify red circle
};
MS2_CHECK_SIZE(UISystemMenuDialog, 0x1a0);
MS2_CHECK_OFFSET(UISystemMenuDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UISystemMenuDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UISystemMenuDialog, m_198, 0x198);
