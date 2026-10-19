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
#include "ms2/placeholder/asbilldata.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/commonfiles/usermail.h"

class ASTextField;
class CMsgBoxData;
class CMailInfo;
class Unk_MlButton;
class Unk_MlCheckBox;
class Unk_MlList;
class Unk_MlTab;
class Unk_MsInput;
class Unk_MsCombo;
template <class T> class Unk_MailPtr;

// One ad of an ad mail as a bill row (RTTI .?AVASMailAdBillData@@, 0x58 bytes; ctor 0x1419ea130, dtor 0x1419ea3c0).
class ASMailAdBillData : public ASBillData
{
public:
    ASMailAdBillData() : ASBillData(2), m_nSlot(-1) {}              // 0x1419ea130
    virtual ~ASMailAdBillData() {}                                  //  0 0x1419ea3c0 (??_G 0x1419ea650)
    virtual int vfunc_5() { return m_nSlot; }                       //  5 0x1419eaab0 the ad slot of the mail
    void FUN_1419eb8f0(int nSlot) { m_nSlot = nSlot; }              // 0x1419eb8f0
    int m_nSlot;                                                    // +0x50
};
MS2_CHECK_SIZE(ASMailAdBillData, 0x58);

// The bill dialog argument block of an ad mail (RTTI .?AVTMailAdBillDataParam@@, 0xe8 bytes; ctor 0x1419ea230).
class TMailAdBillDataParam : public TMarketBillDataParam
{
public:
    TMailAdBillDataParam() { m_nMailId = 0; m_b2c = false; }        // 0x1419ea230
    virtual ~TMailAdBillDataParam() = default;                      //  0 0x1419ea450 (??_G 0x1419ea710; no vptr store)
    __int64 m_nMailId;                                              // +0xe0
};
MS2_CHECK_SIZE(TMailAdBillDataParam, 0xe8);

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
    MS2Ptr<TMailAdBillDataParam> FUN_1419e8620(const CStringA& strMovie);   // the ad bill dialog's argument block
    bool FUN_1419e88b0(MS2Ptr<TMarketBillDataParam> spParam, const TMarketBillDataParam::PaymentMap& mapPay);   // buy
    bool FUN_1419e8b70(Scaleform::GFx::Value* pRetVal, ASData& data, MS2Ptr<TMarketBillDataParam> spParam);     // tooltip
    void FUN_1419e4ef0(void* p);                                    // empty, unreferenced
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

// The mail compose dialog (RTTI .?AVUIMailSendDialog@@, bases UIDialog and UIStatusEventListener at +0x178; 0x190 bytes).
// Ctor 0x1419ec180, dtor 0x1419ec230 (deleting dtor 0x1419eded0), vftables 0x142fbf2e8 / 0x142fbf590 (IMessageListener) /
// 0x142fbf5a0 (UIStatusEventListener, no overrides), UI type 0x4e4a. m_spReply is the mail being answered.
class UIMailSendDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIMailSendDialog();                                             // 0x1419ec180
    virtual ~UIMailSendDialog();                                    //  0 0x1419ec230 (??_G 0x1419eded0)
    virtual CString vfunc_1();                                      //  1 0x1419ec2b0 "MailSendDialog"
    virtual int vfunc_13();                                         // 13 0x1419ec440 enter / tab keys
    virtual void vfunc_15();                                        // 15 0x1419ecb70 empty
    virtual void OnLoadComplete();                                  // 22 0x1419ec570
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419ec700
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x1419ec7a0 empty
    virtual int vfunc_48() { return 0x4e4a; }                       // 48 0x1419ee090 UI type id
    virtual int vfunc_65();                                         // 65 0x1419ec300 open (or raise)
    virtual void vfunc_67();                                        // 67 0x1419ec3d0 close
    virtual int vfunc_74(int nMsg, void* p2, void* p3);             // 74 0x1419ec7c0 receiver name candidates while typing
    virtual void vfunc_79(void* p);                                 // 79 0x1419ec5c0 packet 0x54 (send result)

    void FUN_1419ecb80();                                           // close (vfunc_67)
    void FUN_1419ecbb0(CMailInfo* pReplyTo);                        // answer this mail
    void FUN_1419ecbf0();                                           // "setData": the reply prefill
    void FUN_1419ed010();                                           // fill "m_buddys" with the buddy names
    void FUN_1419ed1c0();                                           // "OnSend": check and send (packet 0x2d / 1)
    void FUN_1419ed410(CStringW& strReceiver);                      // the receiver text
    void FUN_1419ed4e0(CStringW& strTitle);                         // the title text (reserved words filtered)
    void FUN_1419ed6b0(CStringW& strContent);                       // the content text (reserved words filtered)
    void FUN_1419ed7f0(ATL::CAtlMap<unsigned __int64, CStringW>& names);   // buddies and guild members by character id

    // child lookups (UIDialog COMDATs shared by many dialogs)
    MS2Ptr<Unk_MsInput> FUN_140e35bd0(const CString& strName);      // 0x140e35bd0 text input
    MS2Ptr<Unk_MsCombo> FUN_140c28560(const CString& strName);      // 0x140c28560 dropdown

private:
    MS2_LAYOUT_FRIEND;
    CUserMail::MailPtr m_spReply;                                   // +0x180
};
MS2_CHECK_SIZE(UIMailSendDialog, 0x190);
MS2_CHECK_OFFSET(UIMailSendDialog, m_spReply, 0x180);
