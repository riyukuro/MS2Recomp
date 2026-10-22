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
class Unk_140acd6e0;                                    // a button child

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

    void FUN_141b13880(const Scaleform::GFx::FunctionHandler::Params& params);   // the leave click of a normal field
    void FUN_141b13b00(const Scaleform::GFx::FunctionHandler::Params& params);   // the leave click of a home (forwards)
    void FUN_141b13b30();                               // leave the home: ask first when the build is not saved
    void FUN_141b144f0(char b);                         // set the red circle flag
    bool FUN_141b14510(int nResult, const CMsgBoxData& data);   // answer of the leave box
    void FUN_141b14560(int nPage);                      // open the option dialog at a page
    void FUN_141b145c0();
    void OnSelectCharacter();                               // back to the character select
    void FUN_141b14630();                               // select the current channel in the list
    CStringW FUN_141b146a0(int nMapType);               // the leave button text
    CStringW FUN_141b149d0(int nMapType);               // the leave box text
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);    // bind a button child (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    int m_180;                                          // +0x180 the selected channel
    MS2Ptr<Unk_140acd6e0> m_188;                        // +0x188 "m_exitRoom"
    char m_198;                                         // +0x198 the system option notify red circle
};
MS2_CHECK_SIZE(UISystemMenuDialog, 0x1a0);
MS2_CHECK_OFFSET(UISystemMenuDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UISystemMenuDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UISystemMenuDialog, m_198, 0x198);
