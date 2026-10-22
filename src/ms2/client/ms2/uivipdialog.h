// uivipdialog.h - UIVIPDialog (RTTI .?AVUIVIPDialog@@, base UIDialog; 0x1d8 bytes): the VIP membership window ("VIPDialog",
// UI id 0x4f1b). It lists the benefit items of the CVIPTable (m_benefitItemList), shows the remaining VIP time (m_remainTime,
// m_timerIcon) and lets the player claim a benefit item (packet 0x8e: 1 = ask the claimed ids, 2 = claim one id; the reply
// reaches FUN_140fb87d0). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names
// invented. Ctor 0x140fb7dc0, dtor 0x140fb7e70 (deleting 0x140fb98d0).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/vipgoods.h"

class CInPacket;
class ASData;
class ASTextField;
class ASMovieClip;

class UIVIPDialog : public UIDialog
{
public:
    UIVIPDialog();                                                  // 0x140fb7dc0
    virtual ~UIVIPDialog();                                         //  0 0x140fb7e70 (??_G 0x140fb98d0)
    virtual CString GetTypeName();                                      //  1 0x140fb7ee0 "VIPDialog"
    virtual void OnLoadComplete();                                  // 22 0x140fb8040 asks the claimed benefit ids
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fb80f0 OnClickGetItem / onClickBuyGoods
    virtual int vfunc_48();                                         // 48 0x140fb9990 0x4f1b
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140fb8240 tooltips: benefitItem / effectIcon
    virtual int vfunc_65();                                         // 65 0x140fb7f30
    virtual void vfunc_67();                                        // 67 0x140fb7f60
    virtual void vfunc_72();                                        // 72 0x140fb7f80 re-lists when the VIP end time changed

    void SendPremiumClubMode1();                                           // 0x140fb8620 packet 0x8e / 1: ask the claimed benefit ids
    int FUN_140fb8680();                                            // 0x140fb8680 the number of benefit items that can be claimed
    void FUN_140fb87d0(CInPacket& packet, int nMode);               // 0x140fb87d0 packet reply: 1 = claimed ids, 2 = one claimed
    void FUN_140fb8d10();                                           // 0x140fb8d10 the remaining time text and the timer icon
    void FUN_140fb9150();                                           // 0x140fb9150 fill the benefit list of the movie
    int FUN_140fb9720(unsigned nBenefitId);                         // 0x140fb9720 the benefit is still claimable (VIP and not claimed)

    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // text field child lookup (a UIDialog member)
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // movie clip child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_bindIds;                              // +0x178 (only constructed and destroyed here)
    ATL::CAtlList<unsigned> m_claimedIds;                           // +0x198 benefit ids already claimed
    __int64 m_nVipEnd;                                              // +0x1c8 the VIP end time of the last listing
    int m_nVip;                                                     // +0x1d0 the VIP flag of the last listing
};
MS2_CHECK_SIZE(UIVIPDialog, 0x1d8);
MS2_CHECK_OFFSET(UIVIPDialog, m_bindIds, 0x178);
MS2_CHECK_OFFSET(UIVIPDialog, m_claimedIds, 0x198);
MS2_CHECK_OFFSET(UIVIPDialog, m_nVipEnd, 0x1c8);
MS2_CHECK_OFFSET(UIVIPDialog, m_nVip, 0x1d0);
