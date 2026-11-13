// maplesurvivalpassdialog.h - Mushking Royale restore: UIMapleSurvivalPassDialog (GMS 0x4f7b, here
// MS2_UI_MAPLESURVIVAL_PASS). NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included only by maplesurvivalpassdialog.cpp.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASButton;
class ASMovieClip;
class ASItemSlot;
class ASAdditionalEffectSlot;
class CMsgBoxData;
struct SurvivalPassRewardEntry;

class UIMapleSurvivalPassDialog : public UIDialog
{
public:
    UIMapleSurvivalPassDialog();
    virtual ~UIMapleSurvivalPassDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x79f730) "MapleSurvivalPassDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x7a33a0)
    virtual void vfunc_26();                        // 26 (GMS 0x7a2070 releases the children)
    virtual int vfunc_48() { return 0x4fc1; }       // 48 MS2_UI_MAPLESURVIVAL_PASS

    // Manager events (MushkingUI::Pass_*); each one tests m_30.
    void RefreshState();                            // GMS 0x79f8e0
    void RefreshSeason();                           // GMS 0x7a0990
    void RefreshRecord();                           // GMS 0x7a0da0 + 0x7a1120 + 0x7a3310(true)
    void RefreshSkins();                            // GMS 0x7a27e0

    // Clicks (GMS handler VAs).
    void OnRegister(const Scaleform::GFx::FunctionHandler::Params& params);      // GMS 0x79fa60
    void OnUnregister(const Scaleform::GFx::FunctionHandler::Params& params);    // GMS 0x79fb20
    void OnSetting(const Scaleform::GFx::FunctionHandler::Params& params);       // GMS 0x79fd80
    void OnSelectMode(const Scaleform::GFx::FunctionHandler::Params& params);    // GMS 0x7a0070 (user 0 close, 1 solo, 2 squad)
    void OnSkinPlus(const Scaleform::GFx::FunctionHandler::Params& params);      // GMS 0x7a1420 (user = skin slot)
    void OnBuyPaidPass(const Scaleform::GFx::FunctionHandler::Params& params);   // GMS 0x7a1460
    void OnReceive(const Scaleform::GFx::FunctionHandler::Params& params);       // GMS 0x7a0150
    void OnPrevPage(const Scaleform::GFx::FunctionHandler::Params& params);      // GMS 0x7a32a0
    void OnNextPage(const Scaleform::GFx::FunctionHandler::Params& params);      // GMS 0x7a32d0
    bool OnBuyBox(int nResult, const CMsgBoxData& box);                          // GMS 0x7a03d0

private:
    bool CanChangeMode(CStringW& strError);         // GMS 0x79fbe0
    void RefreshMode();                             // GMS 0x79fe90
    void RefreshPaidInfo();                         // GMS 0x7a1120
    void RefreshComplete();                         // GMS 0x7a1240
    void RefreshRewardPage();                       // GMS 0x7a2ea0
    void ResetPage(bool bReset);                    // GMS 0x7a3310
    int MaxRewardLevel();
    void RefreshCell(int nRow, int nCol, MS2Ptr<ASMovieClip>& spCell, const SurvivalPassRewardEntry* pEntry, int nLevel, bool bPaid, bool bSpecial);   // GMS 0x7a28d0

    MS2Ptr<ASMovieClip> m_mainInfo;                     // GMS +0x114
    MS2Ptr<ASMovieClip> m_skinInfo;                     // GMS +0x11c
    MS2Ptr<ASMovieClip> m_itemInfo;                     // GMS +0x124
    MS2Ptr<ASMovieClip> m_levelInfo;                    // GMS +0x12c
    MS2Ptr<ASMovieClip> m_rewardInfo;                   // GMS +0x134
    MS2Ptr<ASMovieClip> m_modeSelector;                 // GMS +0x13c
    MS2Ptr<ASButton> m_registerButton;
    MS2Ptr<ASButton> m_unregisterButton;
    MS2Ptr<ASButton> m_seasonRewardInfoButton;
    MS2Ptr<ASButton> m_rankButton;
    MS2Ptr<ASButton> m_settingButton;
    MS2Ptr<ASButton> m_soloSelectButton;
    MS2Ptr<ASButton> m_squadSelectButton;
    MS2Ptr<ASButton> m_selectorCloseButton;
    MS2Ptr<ASButton> m_plus[3];                     // m_tailSkin / m_ridingSkin / m_glidingSkin .m_plus
    MS2Ptr<ASButton> m_activePaidPassButton;
    MS2Ptr<ASButton> m_prevPage;
    MS2Ptr<ASButton> m_nextPage;
    MS2Ptr<ASButton> m_receiveButton;
    MS2Ptr<ASMovieClip> m_row[8];                   // m_rewardInfo row clips (name probed at load, see the .cpp)
    MS2Ptr<ASMovieClip> m_cell[8][3];               // row .m_free / .m_paid1 / .m_paid2
    int m_cellKind[8][3];                           // 0 none, 1 item slot, 2 additional-effect slot
    MS2Ptr<ASItemSlot> m_cellItem[8][3];            // reward page cells m_free / m_paid1 / m_paid2 .m_slot (kept: the
    MS2Ptr<ASAdditionalEffectSlot> m_cellEffect[8][3];   // slot objects own the AS tooltip callbacks)
    int m_gaugeWidth;                               // m_levelInfo.m_expGauge.m_survivalLevelGauge full width
    int m_nPage;                                    // GMS +0x1b8 first level of the reward page
    bool m_bSquad;                                  // GMS +0x1d4
};
