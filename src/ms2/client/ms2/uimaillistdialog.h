// uimaillistdialog.h - UIMailListDialog (RTTI .?AVUIMailListDialog@@, base UIDialog; 0x1d8 bytes): the mailbox. Recovered
// from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented. Ctor 0x1419e3510 (operator
// new 0x1d8 in CUIService::RegisterDialogs), dtor 0x1419e35e0 (deleting dtor 0x1419ea750), vftable 0x142fbec78, UI type
// 0x4e49. The definitions belong to unit `?\uimaillistdialog.cpp`.
//
// The movie shows 14 mails per page of the selected tab ("m_tab": 1 = the user mails of kinds 1..3, otherwise the system
// mails of kinds 100..112 and the ad mails). The ids of the checked rows are kept in m_mapChecked. The mails themselves
// live in the CUserMail singleton (commonfiles/usermail.h, g_143ab2ee0). The unit also holds UIMailSendDialog
// (0x190, vftable 0x142fbf2e8, ctor 0x1419ec180) and the ad bill row ASMailAdBillData / TMailAdBillDataParam.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/mctimer.h"

class ASTextField;
class CMsgBoxData;
class CMailInfo;
class Unk_MlButton;
class Unk_MlCheckBox;
class Unk_MlList;
class Unk_MlTab;
template <class T> class Unk_MailPtr;

class UIMailListDialog : public UIDialog
{
public:
    UIMailListDialog();                                             // 0x1419e3510
    virtual ~UIMailListDialog();                                    //  0 0x1419e35e0 (??_G 0x1419ea750)
    virtual CString vfunc_1();                                      //  1 0x1419e3630 "MailListDialog"
    virtual void vfunc_15();                                        // 15 0x1419e4de0 per-frame: apply the pending refreshes
    virtual void OnLoadComplete();                                  // 22 0x1419e36f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419e37d0
    virtual int vfunc_48() { return 0x4e49; }                       // 48 0x1419eabf0 UI type id
    virtual int vfunc_65();                                         // 65 0x1419e3680
    virtual void vfunc_67();                                        // 67 0x1419e36b0 close: drop the attachment tooltips
    virtual void vfunc_79(void* p);                                 // 79 0x1419e3750
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x1419e3780

    bool FUN_1419e8080(unsigned __int64 nMailId);                   // "onBuyAd": the ad bill dialog
    void FUN_1419e4f10();                                           // a mail was removed: clamp the page, refresh
    void FUN_1419e5000(__int64 nMailId);                            // "readMail"
    void FUN_1419e50b0(__int64 nMailId);                            // "receiveMail"
    void FUN_1419e5150();                                           // ask for a delayed refresh
    void FUN_1419e5190();                                           // fill the list with the current page
    void FUN_1419e5900();                                           // "onMailCount" (unread user / system mails)
    void FUN_1419e5a10(__int64 nMailId);                            // "setMailInfo" (the opened mail)
    void FUN_1419e61c0(__int64 nMailId);                            // mark read (packet 0x2d / 2)
    void FUN_1419e6290(__int64 nMailId);                            // receive the attachments (packet 0x2d / 0xb)
    void FUN_1419e6360(__int64 nMailId);                            // reply: open the send dialog
    void FUN_1419e6410(__int64 nMailId);                            // remove: confirm box
    unsigned FUN_1419e67a0(CMailInfo* pMail);                       // bind the attachment tooltips, returns their count
    void FUN_1419e6b70();                                           // drop the five attachment tooltips
    __int64 FUN_1419e6c30();                                        // "getMailID" (the opened mail)
    int FUN_1419e6ec0(Unk_MailPtr<CMailInfo> spMail);               // the mail belongs to the current tab
    int FUN_1419e6fe0(int nPage);                                   // the page exists
    int FUN_1419e70c0(CStringW strIds);                             // one of the ids has attachments
    CStringA FUN_1419e7260(Unk_MailPtr<CMailInfo> spMail);          // the row state name
    void FUN_1419e73f0();                                           // "m_page"
    int FUN_1419e74e0(__int64 nMailId);                             // an attachment is a locked item
    bool FUN_1419e7640(int nButton, const CMsgBoxData& data);       // read all: packet 0x2d / 0x12
    bool FUN_1419e77c0(int nButton, const CMsgBoxData& data);       // receive all: packet 0x2d / 0x13
    bool FUN_1419e7940(int nButton, const CMsgBoxData& data);       // remove the listed mails: packet 0x2d / 0xd
    bool FUN_1419e7c80(int nButton, const CMsgBoxData& data);       // remove one mail
    void FUN_1419e7ea0(CStringW strIds, ATL::CAtlArray<__int64>& aIds, int bSkipAttached);   // parse the id list
    int FUN_1419e7fd0();                                            // the selected tab ("m_tab")
    void FUN_1419e6d20(ATL::CAtlList<Unk_MailPtr<CMailInfo> >& out);   // the mails of the tab, newest first, ads last
    void FUN_1419e90d0();                                           // ask the server for the list (packet 0x2d / 0)

    // child lookups (UIDialog COMDATs shared by many dialogs)
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // 0x140bb4cf0 text field
    MS2Ptr<Unk_MlButton> FUN_140bb4b10(const CString& strName);     // 0x140bb4b10 button
    MS2Ptr<Unk_MlList> FUN_140c02900(const CString& strName);       // 0x140c02900 list
    MS2Ptr<Unk_MlTab> FUN_140c02870(const CString& strName);        // 0x140c02870 tab strip
    MS2Ptr<Unk_MlCheckBox> FUN_140e52670(const CString& strName);   // 0x140e52670 check box

private:
    MS2_LAYOUT_FRIEND;
    int m_nPage;                                                    // +0x178
    int m_pad_17c;
    ATL::CAtlMap<unsigned __int64, int> m_mapChecked;               // +0x180 mail id -> checked
    bool m_bRefresh;                                                // +0x1c8 a delayed refresh is pending
    Unk_McTimer m_timer;                                            // +0x1cc
    int m_pad_1d4;
};
MS2_CHECK_SIZE(UIMailListDialog, 0x1d8);
MS2_CHECK_OFFSET(UIMailListDialog, m_nPage, 0x178);
MS2_CHECK_OFFSET(UIMailListDialog, m_mapChecked, 0x180);
MS2_CHECK_OFFSET(UIMailListDialog, m_bRefresh, 0x1c8);
MS2_CHECK_OFFSET(UIMailListDialog, m_timer, 0x1cc);
