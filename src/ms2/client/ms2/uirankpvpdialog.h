// uirankpvpdialog.h - UIRankPvPDialog (RTTI .?AVUIRankPvPDialog@@, 0x280 bytes, UIDialog (IMessageListener at +0x18),
// UI id 0x4f04, swf "RankPvPDialog"): the rank duel (ranked PvP arena) lobby. Two tabs: the register page (register /
// unregister, the observer check box, the weekly reward gauge, the season record and the grade mark) and the statistics
// page (one history row per job). Owning unit: ?\uirankpvpdialog.cpp. Header name assumed from the unit path; the member
// names are the swf child names.
#pragma once
#include <afx.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASButton;
class ASCheckBox;

class UIRankPvPDialog : public UIDialog
{
public:
    UIRankPvPDialog();                                          // 0x140f91d90
    virtual ~UIRankPvPDialog();                                 //  0 0x140f91f40 (??_G 0x140f97eb0)
    virtual CString GetTypeName();                                  //  1 0x140f920b0 "RankPvPDialog"
    virtual void OnLoadInit();                                  // 20 0x140f92100
    virtual void OnLoadComplete();                              // 22 0x140f92120
    virtual void vfunc_26();                                    // 26 0x140f93d50 drop the children
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x140f94120 "getTooltip"
    virtual int vfunc_48() { return 0x4f04; }                   // 48 0x140f97f20
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140f93ec0

    void FUN_140f94390();                                       // the match state changed: register / unregister button
    void FUN_140f94490();                                       // the own record changed: gauge, rating, grade mark
    void FUN_140f94840();                                       // the records changed: the history rows
    void FUN_140f95090(const Scaleform::GFx::FunctionHandler::Params& params);   // a tab was clicked (user data = tab)
    void FUN_140f95220(const Scaleform::GFx::FunctionHandler::Params& params);   // the shop button was clicked
    void FUN_140f95260(const Scaleform::GFx::FunctionHandler::Params& params);   // the register button was clicked
    void SendPVPMode15(const Scaleform::GFx::FunctionHandler::Params& params);   // the unregister button was clicked
    void FUN_140f95550(const Scaleform::GFx::FunctionHandler::Params& params);   // the show grade button was clicked
    void FUN_140f95630(const Scaleform::GFx::FunctionHandler::Params& params);   // the observer check box was clicked
    bool FUN_140f95750();                                       // request the match; false (with a notice) when not allowed

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASButton> m_registMenu;                              // +0x178
    MS2Ptr<ASButton> m_statisticsMenu;                          // +0x188
    MS2Ptr<ASButton> m_shopButton;                              // +0x198
    MS2Ptr<ASMovieClip> m_registerPage;                         // +0x1a8
    MS2Ptr<ASMovieClip> m_statisticsPage;                       // +0x1b8
    MS2Ptr<ASButton> m_register;                                // +0x1c8
    MS2Ptr<ASButton> m_unregister;                              // +0x1d8
    MS2Ptr<ASButton> m_showGrade;                               // +0x1e8
    MS2Ptr<ASCheckBox> m_observeCheck;                          // +0x1f8
    MS2Ptr<ASMovieClip> m_gauge;                                // +0x208
    MS2Ptr<ASTextField> m_rewardText;                           // +0x218
    MS2Ptr<ASTextField> m_seasonWinCount;                       // +0x228
    MS2Ptr<ASTextField> m_seasonBestRating;                     // +0x238
    MS2Ptr<ASTextField> m_rating;                               // +0x248
    MS2Ptr<ASMovieClip> m_rankMark;                             // +0x258
    std::map<int, MS2Ptr<ASMovieClip> > m_history;              // +0x268 job group -> "m_historyN" row
    int m_gaugeWidth;                                           // +0x278 the full width of m_gauge
};
MS2_CHECK_SIZE(UIRankPvPDialog, 0x280);
MS2_CHECK_OFFSET(UIRankPvPDialog, m_registMenu, 0x178);
MS2_CHECK_OFFSET(UIRankPvPDialog, m_observeCheck, 0x1f8);
MS2_CHECK_OFFSET(UIRankPvPDialog, m_rankMark, 0x258);
MS2_CHECK_OFFSET(UIRankPvPDialog, m_history, 0x268);
MS2_CHECK_OFFSET(UIRankPvPDialog, m_gaugeWidth, 0x278);
