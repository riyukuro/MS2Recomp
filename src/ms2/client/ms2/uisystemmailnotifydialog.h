// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uisystemmailnotifydialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UISystemMailNotifyDialog ("SystemMailNotifyDialog", UI type 0x4edc, RTTI .?AVUISystemMailNotifyDialog@@, 0x210 bytes =
// UIDialog + members from +0x178): the corner popup that announces a system mail (a mail table record with a title, a
// description and reward items) or, in "on time event" mode, a timed event with a countdown. Packet 0xbd of the game scene
// (scenestategame.cpp) feeds FUN_1412a53e0: type 0 = the mail id of the pending popup, type 1 = a mail to show.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members, member names invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"

class ASMovieClip;
class CInPacket;
class NotifyObject;
class Unk_140acd6e0;
struct Unk_SmReward;

// 8-byte millisecond poll timer (ctor 0x140517b00, "interval elapsed" test 0x140268870 re-arms).
struct Unk_SmTick
{
    Unk_SmTick();                           // 0x140517b00
    int FUN_140268870(int nInterval);       // true once the interval elapsed
    unsigned m_nInterval;                   // +0
    unsigned m_nLastTick;                   // +4
};
MS2_CHECK_SIZE(Unk_SmTick, 8);

class UISystemMailNotifyDialog : public UIDialog
{
public:
    UISystemMailNotifyDialog();                                 // 0x1412a4590
    virtual ~UISystemMailNotifyDialog();                        //  0 0x1412a47f0 (??_G 0x1412a7010)
    virtual CString vfunc_1();                                  //  1 0x1412a49b0 "SystemMailNotifyDialog"
    virtual void OnLoadComplete();                              // 22 0x1412a4a00 bind the two panels, buttons and slot
    virtual void vfunc_26();                                    // 26 0x1412a52b0 reset
    virtual int vfunc_48() { return 0x4edc; }                   // 48 0x1412a7110 UI type id
    virtual void vfunc_72();                                    // 72 0x1412a5340 per frame: countdown / hide timer

    void FUN_1412a53e0(CInPacket& packet);                      // 0x1412a53e0 packet 0xbd: pending mail id / show a mail
    void FUN_1412a5570(int nMailId);                            // 0x1412a5570 show the mail
    void SetOnTime(bool bOnTime);                           // 0x1412a5c50 on-time event mode
    void FUN_1412a5c70(int nMs);                                // 0x1412a5c70 hide after nMs
    int FUN_1412a5ca0();                                       // 0x1412a5ca0 a mail is pending
    void FUN_1412a5ce0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1412a5ce0 "m_btnDetail": open the page
    void FUN_1412a5d10(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1412a5d10 "m_btnShow": hide / show
    void FUN_1412a5db0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1412a5db0 "m_btnClose"
    void FUN_1412a5de0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1412a5de0 "m_btnOnTime"
    void FUN_1412a5e60(NotifyObject* pNotify);                  // 0x1412a5e60 "NotifyCompleteMyPC"
    void FUN_1412a5eb0(const Unk_SmReward* pReward);                    // 0x1412a5eb0 bind the reward item to the slot
    void FUN_1412a6080();                                       // 0x1412a6080 drop the bound item
    void FUN_1412a60d0();                                       // 0x1412a60d0 play the "open" tween
    void FUN_1412a61a0();                                       // 0x1412a61a0 play the "close" tween
    void FUN_1412a62a0();                                       // 0x1412a62a0 the hide timer ran out
    void FUN_1412a6390();                                       // 0x1412a6390 refresh the countdown text

    MS2Ptr<Unk_140acd6e0> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_140acd6e0>& out);   // 0x140bc6d10 bind a button child
    MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out);       // 0x140c57ce0 bind a clip child

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                          // +0x178 the mail id shown
    int m_17c;                          // +0x17c the mail id pending
    int m_180;                          // +0x180 a mail was announced
    int m_184;                          // +0x184 1 until the first show
    bool m_bOnTime;                     // +0x188 on-time event mode
    CString m_strUrl;                   // +0x190 the page of the "detail" button
    CString m_strSlot;                  // +0x198 the name the reward item is bound under
    MS2Ptr<ASMovieClip> m_event;        // +0x1a0 "m_event"
    MS2Ptr<ASMovieClip> m_onTimeEvent;  // +0x1b0 "m_onTimeEvent"
    MS2Ptr<Unk_140acd6e0> m_btnShow;    // +0x1c0 "m_btnShow"
    MS2Ptr<Unk_140acd6e0> m_btnDetail;  // +0x1d0 "m_detail"
    MS2Ptr<Unk_140acd6e0> m_btnClose;   // +0x1e0 "m_close"
    MS2Ptr<Unk_140acd6e0> m_btnOnTime;  // +0x1f0 "m_onTimeEventButton"
    Unk_SmTick m_tick;                  // +0x200
    unsigned m_nHideAt;                 // +0x208 server time the popup hides at
};
MS2_CHECK_SIZE(UISystemMailNotifyDialog, 0x210);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_bOnTime, 0x188);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_strUrl, 0x190);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_event, 0x1a0);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_btnShow, 0x1c0);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_btnOnTime, 0x1f0);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_tick, 0x200);
MS2_CHECK_OFFSET(UISystemMailNotifyDialog, m_nHideAt, 0x208);
