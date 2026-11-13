// maplesurvivaldialog.h - Mushking Royale restore: the lobby UIMapleSurvivalDialog (GMS 0x4f6d, here MS2_UI_MAPLESURVIVAL).
// NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included by maplesurvivaldialog.cpp and maplesurvivalbuybundledialog.cpp (registration).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASButton;
class ASMovieClip;
class ASTextField;
class ASItemSlot;

class UIMapleSurvivalDialog : public UIDialog
{
public:
    UIMapleSurvivalDialog();
    virtual ~UIMapleSurvivalDialog();
    virtual CString GetTypeName();                  // 1 (GMS 0x79e9c0) "MapleSurvivalDialog"
    virtual void OnLoadComplete();                  // 22 (GMS 0x79dc50)
    virtual void vfunc_26();                        // 26 (GMS 0x79cb70 releases the children)
    virtual int vfunc_48() { return 0x4fc0; }       // 48 (GMS 0x79e9e0) MS2_UI_MAPLESURVIVAL

    void RefreshState();                            // GMS 0x79dac0: register / unregister buttons, progress icon
    void RefreshSeason();                           // GMS 0x79dc30 (0x79d120, 0x79d4b0) plus 0x79d790 and 0x79d320

    void OnRegister(const Scaleform::GFx::FunctionHandler::Params& params);      // GMS 0x79c4f0
    void OnUnregister(const Scaleform::GFx::FunctionHandler::Params& params);    // GMS 0x79c590
    void OnRefresh(const Scaleform::GFx::FunctionHandler::Params& params);       // GMS 0x79c640

private:
    void UpdateLevel();         // GMS 0x79d120: level text, exp text, exp gauge
    void UpdateRating();        // GMS 0x79d320: rating text
    void UpdateReward();        // GMS 0x79d4b0: next level reward
    void UpdateSeason();        // GMS 0x79d790: season title / period

    MS2Ptr<ASMovieClip> m_mainPage;
    MS2Ptr<ASButton> m_registerButton;
    MS2Ptr<ASButton> m_unregisterButton;
    MS2Ptr<ASButton> m_seasonRewardInfoButton;
    MS2Ptr<ASButton> m_levelRewardButton;
    MS2Ptr<ASButton> m_showGradeButton;
    MS2Ptr<ASTextField> m_levelText;
    MS2Ptr<ASTextField> m_levelExpText;
    MS2Ptr<ASTextField> m_ratingText;
    MS2Ptr<ASTextField> m_rankingText;
    MS2Ptr<ASMovieClip> m_gauge;
    MS2Ptr<ASMovieClip> m_rewardMovie;
    MS2Ptr<ASMovieClip> m_rewardMaxMovie;
    MS2Ptr<ASMovieClip> m_rankMark;
    MS2Ptr<ASItemSlot> m_slot[3];
    MS2Ptr<ASMovieClip> m_eff[3];
    int m_gaugeWidth;
};
