// UIHomeSummonDialog (RTTI .?AVUIHomeSummonDialog@@, 0x1a0 bytes, UI id 0x4ede: the house owner types a visitor's name and
// confirms to summon them (packet 0x37 sub 0x1e)). Unit name assumed (the exe has no path for it). Names invented from the
// callers: FUN_<va> are non-virtual members. w276.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/imessagelistener.h"

class Unk_SumButton;
class Unk_SumText;

class UIHomeSummonDialog : public UIDialog
{
public:
    UIHomeSummonDialog();                                       // 0x141299650
    virtual ~UIHomeSummonDialog();                              //  0 0x141299700 (??_G 0x14129a240)
    virtual CString GetTypeName();                                  //  1 0x141299780 "HomeSummonDialog"
    virtual int vfunc_13();                                     // 13 0x141299af0 enter key: send, escape key: close
    virtual void OnLoadComplete();                              // 22 0x141299880 bind the buttons and the text input
    virtual void vfunc_26();                                    // 26 0x141299ab0
    virtual void vfunc_43();                                    // 43 0x1412997d0
    virtual int vfunc_48() { return 0x4ede; }                   // 48 (COMDAT 0x14129a280)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141299dd0

    void OnConfirmClick(const Scaleform::GFx::FunctionHandler::Params&);   // 0x141299bb0
    void Summon();                                              // 0x141299be0 send the typed name
    void SetName(CString strName);                              // 0x141299eb0 m_178 = strName
    MS2Ptr<Unk_SumText> FUN_14129a040(const CString& strName, MS2Ptr<Unk_SumText>& out);    // 0x14129a040 bind a text input
    MS2Ptr<Unk_SumText> FUN_140e35bd0(const CString& strName);  // text input child lookup (UIDialog member)
    MS2Ptr<Unk_SumButton> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_SumButton>& out);   // bind a button

private:
    MS2_LAYOUT_FRIEND;
    CString m_178;                                              // +0x178 the name shown / preset
    MS2Ptr<Unk_SumButton> m_180;                                // +0x180 "m_confirmButton"
    MS2Ptr<Unk_SumText> m_190;                                  // +0x190 "m_textInput"
};
MS2_CHECK_SIZE(UIHomeSummonDialog, 0x1a0);
MS2_CHECK_OFFSET(UIHomeSummonDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIHomeSummonDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIHomeSummonDialog, m_190, 0x190);
