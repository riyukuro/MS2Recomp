// maplesurvivaldialog.cpp - Mushking Royale restore: UIMapleSurvivalDialog (the lobby). NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: maplesurvivaldialog
// MS2-NO-EXE: 0x140db5392 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/client/ms2/maplesurvivaldialog.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

CStringW GetStringCommonByKey(const CStringW& strKey);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> LobbyClickDelegate;

namespace
{
CStringW Key(const wchar_t* key)
{
    return GetStringCommonByKey(CStringW(key));
}

CStringW Arg(CStringW text, int idx, const CStringW& v)
{
    CStringW tag;
    tag.Format(L"{%d}", idx);
    text.Replace(tag, v);
    return text;
}

// The GMS {n:fmt} formatter (0x86f2f0 style) for int args: "{3:02d}" -> swprintf "%02d"; a plain "{n}" too.
CStringW FormatInts(const CStringW& text, const int* v, int nArgs)
{
    CStringW out;
    int i = 0;
    int len = text.GetLength();
    while (i < len)
    {
        wchar_t c = text[i];
        int close = c == L'{' ? text.Find(L'}', i) : -1;
        if (close > i + 1)
        {
            CStringW tag = text.Mid(i + 1, close - i - 1);
            int colon = tag.Find(L':');
            CStringW idx = colon < 0 ? tag : tag.Left(colon);
            int n = _wtoi(idx);
            if (idx.SpanIncluding(L"0123456789") == idx && n >= 0 && n < nArgs)
            {
                CStringW fmt = L"%" + (colon < 0 ? CStringW(L"d") : tag.Mid(colon + 1));
                CStringW one;
                one.Format(fmt, v[n]);
                out += one;
                i = close + 1;
                continue;
            }
        }
        out += c;
        ++i;
    }
    return out;
}

// "2018-08-22-15-00" (table startTime / endTime) -> year, month, day, hour, minute.
void SplitTime(const CStringW& text, int* v)
{
    v[0] = v[1] = v[2] = v[3] = v[4] = 0;
    swscanf_s(text, L"%d-%d-%d-%d-%d", &v[0], &v[1], &v[2], &v[3], &v[4]);
}

CStringW Num(__int64 n)
{
    CStringW s;
    s.Format(L"%I64d", n);
    return s;
}

MS2Ptr<ASItemSlot> BindItemSlot(AScript* pMovie, const char* name)
{
    Scaleform::GFx::Value v = pMovie->GetMember(name);
    if (!v.IsObject())
        return MS2Ptr<ASItemSlot>(0);
    return MS2Ptr<ASItemSlot>(new ASItemSlot(v, pMovie->FUN_14198f250()));
}

void SetText(MS2Ptr<ASTextField>& sp, const CStringW& text)
{
    if (sp.get() != 0)
        sp.operator->()->SetTextW(text);
}
void Show(MS2Ptr<ASMovieClip>& sp, bool b)
{
    if (sp.get() != 0)
        sp.operator->()->vfunc_4(b);
}
}

UIMapleSurvivalDialog::UIMapleSurvivalDialog() : m_gaugeWidth(0)
{
}

UIMapleSurvivalDialog::~UIMapleSurvivalDialog()
{
}

// GMS 0x79e9c0
CString UIMapleSurvivalDialog::GetTypeName()
{
    return "MapleSurvivalDialog";
}

// GMS 0x79dc50: bind the children, wire the clicks, fill every field from the manager.
void UIMapleSurvivalDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == 0)
    {
        vfunc_67();
        return;
    }
    // The KMS movie nests the fields (uimaplesurvivaldialog.gfx: root -> m_mainPage -> the texts, buttons and clips;
    // m_slot1-3, m_eff1-3 and m_levelRewardButton one level deeper in m_mainPage.m_rewardMovie), so they are bound
    // through those clips, as GMS does from m_mainPage. Without the page GMS closes the window.
    m_mainPage = m_30->FUN_1409b4560("m_mainPage");
    if (m_mainPage.get() == 0)
    {
        vfunc_67();
        return;
    }
    ASMovieClip* pPage = m_mainPage.operator->();
    m_registerButton = pPage->FUN_140acce30<ASButton>("m_registerButton");
    m_unregisterButton = pPage->FUN_140acce30<ASButton>("m_unregisterButton");
    m_seasonRewardInfoButton = pPage->FUN_140acce30<ASButton>("m_seasonRewardInfoButton");
    m_levelText = pPage->FUN_1409b4620("m_survivalLevelText");
    m_levelExpText = pPage->FUN_1409b4620("m_survivalLevelExpText");
    m_gauge = pPage->FUN_1409b4560("m_survivalLevelGauge");
    m_rewardMovie = pPage->FUN_1409b4560("m_rewardMovie");
    m_rewardMaxMovie = pPage->FUN_1409b4560("m_rewardMaxMovie");
    m_rankingText = pPage->FUN_1409b4620("m_rankingText");   // not in the KMS movie (stays null)
    m_showGradeButton = pPage->FUN_140acce30<ASButton>("m_showGradeButton");
    m_rankMark = pPage->FUN_1409b4560("m_rankMarkMovie");
    m_ratingText = pPage->FUN_1409b4620("m_ratingText");
    if (m_rewardMovie.get() != 0)
    {
        ASMovieClip* pReward = m_rewardMovie.operator->();
        m_levelRewardButton = pReward->FUN_140acce30<ASButton>("m_levelRewardButton");
        m_slot[0] = BindItemSlot(pReward, "m_slot1");
        m_slot[1] = BindItemSlot(pReward, "m_slot2");
        m_slot[2] = BindItemSlot(pReward, "m_slot3");
        m_eff[0] = pReward->FUN_1409b4560("m_eff1");
        m_eff[1] = pReward->FUN_1409b4560("m_eff2");
        m_eff[2] = pReward->FUN_1409b4560("m_eff3");
    }

    if (m_registerButton.get() != 0)
        m_registerButton.operator->()->AddClickHandler(LobbyClickDelegate(this, &UIMapleSurvivalDialog::OnRegister), 0);
    if (m_unregisterButton.get() != 0)
        m_unregisterButton.operator->()->AddClickHandler(LobbyClickDelegate(this, &UIMapleSurvivalDialog::OnUnregister), 0);
    // GMS 0x79c5a0 (season reward info) opens a web page from the constants table; not restored (no such constant).
    // GMS wires the level reward button to 0x79c640 (the refresh request) and the grade button to 0x79d750, which
    // opens the grade window 0x4f28 (a KMS dialog with another meaning); that one is left unwired.
    if (m_levelRewardButton.get() != 0)
        m_levelRewardButton.operator->()->AddClickHandler(LobbyClickDelegate(this, &UIMapleSurvivalDialog::OnRefresh), 0);

    if (m_gauge.get() != 0)
        m_gaugeWidth = m_gauge.operator->()->GetWidthCeil();
    RefreshSeason();
    RefreshState();
}

// GMS 0x79cb70
void UIMapleSurvivalDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_mainPage = 0;
    m_registerButton = 0;
    m_unregisterButton = 0;
    m_seasonRewardInfoButton = 0;
    m_levelRewardButton = 0;
    m_showGradeButton = 0;
    m_levelText = 0;
    m_levelExpText = 0;
    m_ratingText = 0;
    m_rankingText = 0;
    m_gauge = 0;
    m_rewardMovie = 0;
    m_rewardMaxMovie = 0;
    m_rankMark = 0;
    for (int i = 0; i < 3; ++i)
    {
        m_slot[i] = 0;
        m_eff[i] = 0;
    }
}

// GMS 0x79c4f0: queue. The manager rejects a rejoin; GMS shows "cant now" when the call is refused (already queued).
void UIMapleSurvivalDialog::OnRegister(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    if (pMgr->GetState() == 1)
    {
        ShowSystemNotice(Key(L"s_maple_survival_ui_cant_now"), 2, 1);
        return;
    }
    pMgr->RequestMatch();
}

// GMS 0x79c590
void UIMapleSurvivalDialog::OnUnregister(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager::GetInstance()->CancelMatch();
}

// GMS 0x79c640 (mode 0x12, throttled)
void UIMapleSurvivalDialog::OnRefresh(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager::GetInstance()->RequestRefresh();
}

// GMS 0x79dac0: while queued the cancel button shows, else the queue button.
void UIMapleSurvivalDialog::RefreshState()
{
    if (m_30 == 0)
        return;
    bool bQueued = CMapleSurvivalManager::GetInstance()->GetState() == 1;
    if (m_registerButton.get() != 0)
        m_registerButton.operator->()->vfunc_3(bQueued ? 0 : 1);
    if (m_unregisterButton.get() != 0)
        m_unregisterButton.operator->()->vfunc_3(bQueued ? 1 : 0);
    // m_mainPage.m_progressIcon (the lobby search indicator): GMS 0x7ec5d0 sets the child's visibility (slot +0xc, as
    // the buttons above), shown only while queued.
    if (m_mainPage.get() != 0)
    {
        MS2Ptr<ASMovieClip> spIcon = m_mainPage.operator->()->FUN_1409b4560("m_progressIcon");
        if (spIcon.get() != 0)
            spIcon.operator->()->vfunc_3(bQueued ? 1 : 0);
    }
}

// GMS 0x79dc30 (+ 0x79d790, 0x79d320)
void UIMapleSurvivalDialog::RefreshSeason()
{
    if (m_30 == 0)
        return;
    UpdateSeason();
    UpdateRating();
    UpdateLevel();
    UpdateReward();
}

// GMS 0x79d120: "level N", "exp / required" (MAX at the last level) and the gauge.
void UIMapleSurvivalDialog::UpdateLevel()
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    SetText(m_levelText, Arg(Key(L"s_maple_survival_ui_survival_level"), 0, Num(pMgr->m_level)));
    __int64 nReq = 0;
    // GMS reads the next level's row (0x79d1b7: level clamped to >= 1, then +1): reqExp of level L is the exp from
    // L - 1 to L. A missing row (past the last level) means MAX.
    int nNext = (pMgr->m_level < 1 ? 1 : pMgr->m_level) + 1;
    std::map<int, SurvivalLevelData>::const_iterator it = pTab->m_levels.find(nNext);
    if (it != pTab->m_levels.end())
        nReq = it->second.reqExp;
    float fRate = 1.0f;
    if (nReq == 0 || nReq == 0x7fffffffffffffffLL)
        SetText(m_levelExpText, CStringW(L"MAX"));
    else
    {
        SetText(m_levelExpText, Arg(Arg(CStringW(L"{0} / {1}"), 0, Num(pMgr->m_exp)), 1, Num(nReq)));
        fRate = (float)pMgr->m_exp / (float)nReq;
    }
    if (fRate > 1.0f)
        fRate = 1.0f;
    if (fRate < 0.0f)
        fRate = 0.0f;
    if (m_gauge.get() != 0)
        m_gauge.operator->()->SetWidthInt((int)(m_gaugeWidth * fRate));
}

// GMS 0x79d320: the season rating; without a season the "not season" text.
void UIMapleSurvivalDialog::UpdateRating()
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    bool bSeason = pMgr->m_seasonId != 0 && pTab->m_periods.find(pMgr->m_seasonId) != pTab->m_periods.end();
    if (bSeason)
        SetText(m_ratingText, Arg(Key(L"s_maple_survival_ui_rating"), 0, Num(pMgr->m_seasonValue)));
    else
        SetText(m_ratingText, Key(L"s_maple_survival_ui_not_season_rating"));
}

// GMS 0x79d4b0: the reward of the next level (the three item slots), or the "max" movie when there is none.
void UIMapleSurvivalDialog::UpdateReward()
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    int nNext = pMgr->m_1a + 1;
    std::map<int, SurvivalLevelReward>::const_iterator it = pTab->m_levelRewards.find(nNext);
    if (it == pTab->m_levelRewards.end())
    {
        Show(m_rewardMovie, false);
        Show(m_rewardMaxMovie, true);
        return;
    }
    Show(m_rewardMovie, true);
    // GMS 0x79d4b0: the reward caption (s_maple_survival_ui_reward_gain_level) for the next level. The field is
    // looked up under the reward clip (where the KMS movie nests the slots), then under the page.
    {
        CStringW strGain = Arg(Key(L"s_maple_survival_ui_reward_gain_level"), 0, Num(nNext));
        MS2Ptr<ASTextField> spGain;
        if (m_rewardMovie.get() != 0)
            spGain = m_rewardMovie.operator->()->FUN_1409b4620("m_survivalLevelRewardText");
        if (spGain.get() == 0 && m_mainPage.get() != 0)
            spGain = m_mainPage.operator->()->FUN_1409b4620("m_survivalLevelRewardText");
        SetText(spGain, strGain);
    }
    Show(m_rewardMaxMovie, false);
    bool bGained = nNext <= pMgr->m_level;      // the level is reached: the effect shows
    for (int i = 0; i < 3; ++i)
    {
        if (m_slot[i].get() != 0)
        {
            if (it->second.itemId[i] != 0)
                m_slot[i].operator->()->SetItem(it->second.itemId[i], it->second.itemRank[i], it->second.itemCount[i]);
            m_slot[i].operator->()->vfunc_4(it->second.itemId[i] != 0);
        }
        Show(m_eff[i], bGained && it->second.itemId[i] != 0);
    }
}

// GMS 0x79d790: season title and period (the free season strings when there is no season).
void UIMapleSurvivalDialog::UpdateSeason()
{
    if (m_mainPage.get() == 0)
        return;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    CStringW strTitle, strPeriod;
    std::map<int, SurvivalOpenPeriod>::const_iterator it = pTab->m_periods.find(pMgr->m_seasonId);
    if (pMgr->m_seasonId == 0 || it == pTab->m_periods.end())
    {
        strTitle = Key(L"s_maple_survival_ui_free_season_title");
        strPeriod = Key(L"s_maple_survival_ui_free_season_period");
    }
    else
    {
        strTitle = pMgr->m_season.name;
        // GMS 0x79d790: the localtime parts (year, month, day, hour, minute) of start and end, then the
        // {n:fmt} format of s_maple_survival_ui_season_period.
        int v[10];
        SplitTime(it->second.startTime, v);
        SplitTime(it->second.endTime, v + 5);
        strPeriod = FormatInts(Key(L"s_maple_survival_ui_season_period"), v, 10);
    }
    MS2Ptr<ASTextField> spTitle = m_mainPage.operator->()->FUN_1409b4620("m_seasonTitle");
    MS2Ptr<ASTextField> spPeriod = m_mainPage.operator->()->FUN_1409b4620("m_seasonPeriod");
    SetText(spTitle, strTitle);
    SetText(spPeriod, strPeriod);
}

// Manager -> window events (safe when the window is not registered or not loaded: every refresh tests m_30).
void MushkingUI::Lobby_OnState()
{
    MS2Ptr<UIDialog> sp = CUIService::GetInstance()->FindDialog((eUIClassID)MS2_UI_MAPLESURVIVAL);
    if (sp.get() == 0)
        return;
    static_cast<UIMapleSurvivalDialog*>(sp.operator->())->RefreshState();
}

void MushkingUI::Lobby_OnSeason()
{
    MS2Ptr<UIDialog> sp = CUIService::GetInstance()->FindDialog((eUIClassID)MS2_UI_MAPLESURVIVAL);
    if (sp.get() == 0)
        return;
    static_cast<UIMapleSurvivalDialog*>(sp.operator->())->RefreshSeason();
}

#endif   // MS2_HOOK_DLL
