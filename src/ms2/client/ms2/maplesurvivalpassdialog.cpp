// maplesurvivalpassdialog.cpp - Mushking Royale restore: UIMapleSurvivalPassDialog. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: maplesurvivalpassdialog
// MS2-NO-EXE: 0x140db5394 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/client/ms2/maplesurvivalpassdialog.h"
#include "ms2/client/ms2/maplesurvivalskindialog.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

CStringW GetStringCommonByKey(const CStringW& strKey);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int type);             // a new message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show it
__int64 GetServerTime();                                                // now

// The additional-effect slot is a class of asitemslot.cpp (no shared header): this view declares only what is used
// here (ctor, virtual dtor, SetEffect; no inline virtual, so this unit emits no vftable for it).
class ASAdditionalEffectSlot : public ASUIComponent
{
public:
    ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASAdditionalEffectSlot();
    void SetEffect(int nId, unsigned short nLevel);
private:
    int m_nId;                                                  // +0x88
    unsigned short m_nLevel;                                    // +0x8c
};

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> PassClickDelegate;

namespace
{
const int kRows = 8;            // GMS 0x7a2ea0: eight levels per page

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

CStringW Num(__int64 n)
{
    CStringW s;
    s.Format(L"%I64d", n);
    return s;
}

int UserInt(const Scaleform::GFx::FunctionHandler::Params& params)
{
    return (int)(INT_PTR)params.pUserData;
}

bool HasChild(AScript* p, const char* name)
{
    if (p == 0)
        return false;
    Scaleform::GFx::Value v = p->GetMember(name);
    return v.IsObject();
}

MS2Ptr<ASMovieClip> Clip(MS2Ptr<ASMovieClip>& sp, const char* name)
{
    if (sp.get() == 0)
        return MS2Ptr<ASMovieClip>(0);
    return sp.operator->()->FUN_1409b4560(name);
}

MS2Ptr<ASTextField> Text(MS2Ptr<ASMovieClip>& sp, const char* name)
{
    if (sp.get() == 0)
        return MS2Ptr<ASTextField>(0);
    return sp.operator->()->FUN_1409b4620(name);
}

MS2Ptr<ASButton> Button(MS2Ptr<ASMovieClip>& sp, const char* name)
{
    if (sp.get() == 0)
        return MS2Ptr<ASButton>(0);
    return sp.operator->()->FUN_140acce30<ASButton>(name);
}

template<class T> MS2Ptr<T> Bind(AScript* p, const char* name)
{
    if (p == 0)
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value v = p->GetMember(name);
    if (!v.IsObject())
        return MS2Ptr<T>(0);
    return MS2Ptr<T>(new T(v, p->FUN_14198f250()));
}

void SetText(MS2Ptr<ASTextField> sp, const CStringW& text)
{
    if (sp.get() != 0)
        sp.operator->()->SetTextW(text);
}
void Show(MS2Ptr<ASMovieClip> sp, bool b)
{
    if (sp.get() != 0)
        sp.operator->()->vfunc_4(b);
}
void ShowButton(MS2Ptr<ASButton>& sp, bool b)
{
    if (sp.get() != 0)
        sp.operator->()->vfunc_3(b ? 1 : 0);
}
void Goto(MS2Ptr<ASMovieClip> sp, const char* label)
{
    if (sp.get() != 0)
        sp.operator->()->vfunc_15(CString(label));
}
void Click(MS2Ptr<ASButton>& sp, const PassClickDelegate& d, int nUser)
{
    if (sp.get() != 0)
        sp.operator->()->AddClickHandler(d, (void*)(INT_PTR)nUser);
}

// The reward page rows: the GMS row name comes from a Format whose pattern is not in the decompile (0x7a2ea0 calls a
// CStringA Format with i + 1). The first pattern the movie answers to is used.
const char* const kRowPatterns[] = { "m_reward%d", "m_row%d", "m_list%d", "m_item%d", "m_level%d", "m_slot%d", "m_rewardItem%d", "m_rewardSlot%d" };

const SurvivalPassReward* FindReward(const std::map<int, SurvivalPassReward>& m, int nLevel)
{
    std::map<int, SurvivalPassReward>::const_iterator it = m.find(nLevel);
    return it == m.end() ? 0 : &it->second;
}
}

UIMapleSurvivalPassDialog::UIMapleSurvivalPassDialog() : m_gaugeWidth(0), m_nPage(1), m_bSquad(false)
{
    for (int i = 0; i < kRows; ++i)
        for (int j = 0; j < 3; ++j)
            m_cellKind[i][j] = 0;
}

UIMapleSurvivalPassDialog::~UIMapleSurvivalPassDialog()
{
}

// GMS 0x79f730
CString UIMapleSurvivalPassDialog::GetTypeName()
{
    return "MapleSurvivalPassDialog";
}

// GMS 0x7a33a0: bind the panels and buttons, wire the clicks, fill everything from the manager.
void UIMapleSurvivalPassDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == 0)
    {
        vfunc_67();
        return;
    }
    m_mainInfo = m_30->FUN_1409b4560("m_mainInfo");
    m_skinInfo = m_30->FUN_1409b4560("m_skinInfo");
    m_itemInfo = m_30->FUN_1409b4560("m_itemInfo");
    m_levelInfo = m_30->FUN_1409b4560("m_levelInfo");
    m_rewardInfo = m_30->FUN_1409b4560("m_rewardInfo");
    m_modeSelector = m_30->FUN_1409b4560("m_modeSelector");
    // uimaplesurvivalpassdialog.gfx keeps these five buttons inside m_mainInfo (only m_receiveButton, the panels, the
    // title, drag bar and close button are on the root).
    m_registerButton = Button(m_mainInfo, "m_registerButton");
    m_unregisterButton = Button(m_mainInfo, "m_unregisterButton");
    m_seasonRewardInfoButton = Button(m_mainInfo, "m_seasonRewardInfoButton");
    m_rankButton = Button(m_mainInfo, "m_rankButton");
    m_settingButton = Button(m_mainInfo, "m_settingButton");
    m_soloSelectButton = Button(m_modeSelector, "m_soloSelectButton");
    m_squadSelectButton = Button(m_modeSelector, "m_squadSelectButton");
    m_selectorCloseButton = Button(m_modeSelector, "m_closeButton");
    {
        static const char* const kSkin[3] = { "m_tailSkin", "m_ridingSkin", "m_glidingSkin" };
        for (int i = 0; i < 3; ++i)
        {
            MS2Ptr<ASMovieClip> spSkin = Clip(m_skinInfo, kSkin[i]);
            m_plus[i] = Button(spSkin, "m_plus");
        }
    }
    {
        MS2Ptr<ASMovieClip> spPaid = Clip(m_rewardInfo, "m_paidPassInfo");
        m_activePaidPassButton = Button(spPaid, "m_activePaidPassButton");
    }
    m_prevPage = Button(m_rewardInfo, "m_prevPage");
    m_nextPage = Button(m_rewardInfo, "m_nextPage");
    m_receiveButton = m_30->FUN_140acce30<ASButton>("m_receiveButton");   // on the root, not in m_rewardInfo

    // the reward rows and their three cells
    if (m_rewardInfo.get() != 0)
    {
        const char* szPattern = 0;
        for (size_t k = 0; k < sizeof(kRowPatterns) / sizeof(kRowPatterns[0]) && szPattern == 0; ++k)
        {
            CStringA strName;
            strName.Format(kRowPatterns[k], 1);
            if (HasChild(m_rewardInfo.operator->(), strName))
                szPattern = kRowPatterns[k];
        }
        if (szPattern != 0)
        {
            static const char* const kCell[3] = { "m_free", "m_paid1", "m_paid2" };
            for (int i = 0; i < kRows; ++i)
            {
                CStringA strName;
                strName.Format(szPattern, i + 1);
                m_row[i] = m_rewardInfo.operator->()->FUN_1409b4560(strName);
                for (int j = 0; j < 3; ++j)
                    m_cell[i][j] = Clip(m_row[i], kCell[j]);
            }
        }
    }

    Click(m_registerButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnRegister), 0);
    Click(m_unregisterButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnUnregister), 0);
    Click(m_settingButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnSetting), 0);
    Click(m_selectorCloseButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnSelectMode), 0);
    Click(m_soloSelectButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnSelectMode), 1);
    Click(m_squadSelectButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnSelectMode), 2);
    for (int i = 0; i < 3; ++i)
        Click(m_plus[i], PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnSkinPlus), i);
    Click(m_activePaidPassButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnBuyPaidPass), 0);
    Click(m_prevPage, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnPrevPage), 0);
    Click(m_nextPage, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnNextPage), 0);
    Click(m_receiveButton, PassClickDelegate(this, &UIMapleSurvivalPassDialog::OnReceive), 0);
    // Not restored: the season reward info button (GMS opens a web page from the constants table), the rank button
    // and the static-text centering (0x7a0510).

    Show(m_modeSelector, false);
    {
        MS2Ptr<ASMovieClip> spGauge = Clip(m_levelInfo, "m_expGauge");
        MS2Ptr<ASMovieClip> spBar = Clip(spGauge, "m_survivalLevelGauge");
        if (spBar.get() != 0)
            m_gaugeWidth = spBar.operator->()->GetWidthCeil();
    }
    RefreshMode();
    RefreshSeason();
    RefreshRecord();
    RefreshSkins();
    RefreshState();
}

// GMS 0x7a2070
void UIMapleSurvivalPassDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_mainInfo = 0;
    m_skinInfo = 0;
    m_itemInfo = 0;
    m_levelInfo = 0;
    m_rewardInfo = 0;
    m_modeSelector = 0;
    m_registerButton = 0;
    m_unregisterButton = 0;
    m_seasonRewardInfoButton = 0;
    m_rankButton = 0;
    m_settingButton = 0;
    m_soloSelectButton = 0;
    m_squadSelectButton = 0;
    m_selectorCloseButton = 0;
    for (int i = 0; i < 3; ++i)
        m_plus[i] = 0;
    m_activePaidPassButton = 0;
    m_prevPage = 0;
    m_nextPage = 0;
    m_receiveButton = 0;
    for (int i = 0; i < kRows; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m_cellItem[i][j] = 0;
            m_cellEffect[i][j] = 0;
            m_cell[i][j] = 0;
            m_cellKind[i][j] = 0;
        }
        m_row[i] = 0;
    }
}

// GMS 0x79f8e0: solo mode follows the manager state, squad mode the party's squad registration; a party member who
// is not the leader cannot queue the squad.
void UIMapleSurvivalPassDialog::RefreshState()
{
    if (m_30 == 0 || m_mainInfo.get() == 0)
        return;
    bool bQueued;
    if (m_bSquad)
        bQueued = TSingleton<CPartyManager>::GetInstance()->IsSurvivalSquadRegistered();
    else
        bQueued = CMapleSurvivalManager::GetInstance()->GetState() == 1;
    ShowButton(m_registerButton, !bQueued);
    ShowButton(m_unregisterButton, bQueued);
    Show(Clip(m_mainInfo, "m_progressIcon"), bQueued);
}

// GMS 0x79fa60: squad mode goes straight to the squad checks and send (they show their own notices).
void UIMapleSurvivalPassDialog::OnRegister(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    if (m_bSquad)
    {
        pMgr->RequestSquadMatch();
        return;
    }
    if (pMgr->GetState() == 1)
    {
        ShowSystemNotice(Key(L"s_maple_survival_ui_cant_now"), 2, 1);
        return;
    }
    pMgr->RequestMatch();
}

// GMS 0x79fb20
void UIMapleSurvivalPassDialog::OnUnregister(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager::GetInstance()->CancelMatch();
}

// GMS 0x79fbe0: the mode cannot change in a party or while queued.
bool UIMapleSurvivalPassDialog::CanChangeMode(CStringW& strError)
{
    CPartyManager* pParty = TSingleton<CPartyManager>::GetInstance();
    if (pParty->IsInParty())
    {
        strError = Key(L"s_maple_survival_ui_info_mode_cant_in_party");
        return false;
    }
    if (CMapleSurvivalManager::GetInstance()->GetState() == 1 || pParty->IsSurvivalSquadRegistered())
    {
        strError = Key(L"s_maple_survival_ui_info_mode_cant_registed");
        return false;
    }
    return true;
}

// GMS 0x79fd80: opens the mode selector.
void UIMapleSurvivalPassDialog::OnSetting(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_modeSelector.get() == 0)
        return;
    CStringW strError;
    if (!CanChangeMode(strError))
    {
        ShowSystemNotice(strError, 1, 1);
        return;
    }
    Show(m_modeSelector, true);
}

// GMS 0x7a0070: 0 closes the selector, 1 solo, 2 squad.
void UIMapleSurvivalPassDialog::OnSelectMode(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_modeSelector.get() == 0)
        return;
    int nMode = UserInt(params);
    if (nMode != 0)
    {
        CStringW strError;
        if (!CanChangeMode(strError))
            ShowSystemNotice(strError, 1, 1);
        else if (nMode == 1 || nMode == 2)
        {
            m_bSquad = nMode == 2;
            RefreshMode();
            RefreshState();
        }
    }
    Show(m_modeSelector, false);
}

// GMS 0x79fe90: the background frame and the mode text (squad: {0} = party size).
void UIMapleSurvivalPassDialog::RefreshMode()
{
    if (m_mainInfo.get() == 0)
        return;
    Goto(Clip(m_mainInfo, "m_mainInfoBG"), m_bSquad ? "squad" : "solo");
    CStringW strText;
    if (m_bSquad)
    {
        int nCount = TSingleton<CPartyManager>::GetInstance()->GetMemberCount();
        if (nCount < 1)
            nCount = 1;
        strText = Arg(Key(L"s_maple_survival_ui_info_mode_squad"), 0, Num(nCount));
    }
    else
        strText = Key(L"s_maple_survival_ui_info_mode_solo");
    SetText(Text(m_mainInfo, "m_modeText"), strText);
}

// GMS 0x7a0990: season name and period (the free-season strings without a season).
void UIMapleSurvivalPassDialog::RefreshSeason()
{
    if (m_30 == 0 || m_mainInfo.get() == 0)
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
        strPeriod = Arg(Arg(Key(L"s_maple_survival_ui_season_period"), 0, it->second.startTime), 1, it->second.endTime);
    }
    SetText(Text(m_mainInfo, "m_seasonNameText"), strTitle);
    SetText(Text(m_mainInfo, "m_periodText"), strPeriod);
}

// GMS 0x7a0da0 (level, exp, gauge, grade icon) + 0x7a1120 (pass ticket) + 0x7a3310(true) (reward page).
void UIMapleSurvivalPassDialog::RefreshRecord()
{
    if (m_30 == 0)
        return;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    if (m_levelInfo.get() != 0)
    {
        SetText(Text(m_levelInfo, "m_levelText"), Arg(Key(L"s_maple_survival_ui_survival_level"), 0, Num(pMgr->m_level)));
        __int64 nReq = 0;
        int nGrade = 0;
        std::map<int, SurvivalLevelData>::const_iterator it = pTab->m_levels.find(pMgr->m_level);
        if (it != pTab->m_levels.end())
            nGrade = it->second.grade;
        // GMS 0x7a0e9c: the required exp is the next level's row (level + 1); a missing row means MAX.
        it = pTab->m_levels.find(pMgr->m_level + 1);
        if (it != pTab->m_levels.end())
            nReq = it->second.reqExp;
        MS2Ptr<ASMovieClip> spGauge = Clip(m_levelInfo, "m_expGauge");
        float fRate = 1.0f;
        if (nReq == 0 || nReq == 0x7fffffffffffffffLL)
            SetText(Text(spGauge, "m_survivalLevelExpText"), CStringW(L"MAX"));
        else
        {
            SetText(Text(spGauge, "m_survivalLevelExpText"), Arg(Arg(CStringW(L"{0} / {1}"), 0, Num(pMgr->m_exp)), 1, Num(nReq)));
            fRate = (float)pMgr->m_exp / (float)nReq;
        }
        if (fRate > 1.0f)
            fRate = 1.0f;
        if (fRate < 0.0f)
            fRate = 0.0f;
        MS2Ptr<ASMovieClip> spBar = Clip(spGauge, "m_survivalLevelGauge");
        if (spBar.get() != 0)
            spBar.operator->()->SetWidthInt((int)(m_gaugeWidth * fRate));
        CString strGrade;
        strGrade.Format("%d", nGrade);
        MS2Ptr<ASMovieClip> spIcon = Clip(m_levelInfo, "m_levelIcon");
        if (spIcon.get() != 0)
            spIcon.operator->()->vfunc_15(strGrade);
    }
    RefreshPaidInfo();
    ResetPage(true);
}

// GMS 0x7a1120
void UIMapleSurvivalPassDialog::RefreshPaidInfo()
{
    Goto(Clip(m_rewardInfo, "m_paidPassInfo"), CMapleSurvivalManager::GetInstance()->m_1c != 0 ? "ticket_on" : "ticket_off");
}

int UIMapleSurvivalPassDialog::MaxRewardLevel()
{
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    int nMax = 0;
    if (!pTab->m_passRewards.empty())
        nMax = pTab->m_passRewards.rbegin()->first;
    if (!pTab->m_passRewardsPaid.empty() && pTab->m_passRewardsPaid.rbegin()->first > nMax)
        nMax = pTab->m_passRewardsPaid.rbegin()->first;
    return nMax;
}

// GMS 0x7a1240: the "all received" marks of the free and the paid track.
void UIMapleSurvivalPassDialog::RefreshComplete()
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    int nMax = MaxRewardLevel();
    Show(Clip(m_rewardInfo, "m_freeRewardComplete"), nMax <= pMgr->m_1e);
    Show(Clip(m_rewardInfo, "m_paidRewardComplete"), nMax <= pMgr->m_20);
}

// GMS 0x7a3310: bReset puts the page at the first unclaimed level (free and, with the pass, paid).
void UIMapleSurvivalPassDialog::ResetPage(bool bReset)
{
    if (bReset)
    {
        CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
        int nPage = pMgr->m_1e;
        if (pMgr->m_1c != 0 && pMgr->m_20 < nPage)
            nPage = pMgr->m_20;
        m_nPage = nPage;
    }
    int nLast = MaxRewardLevel() - kRows + 1;
    if (m_nPage > nLast)
        m_nPage = nLast;
    if (m_nPage < 1)
        m_nPage = 1;
    RefreshComplete();
    RefreshRewardPage();
}

// GMS 0x7a32a0 / 0x7a32d0 (bodies not in the decompile): one page back / forward, clamped by ResetPage.
void UIMapleSurvivalPassDialog::OnPrevPage(const Scaleform::GFx::FunctionHandler::Params&)
{
    m_nPage -= kRows;
    ResetPage(false);
}

void UIMapleSurvivalPassDialog::OnNextPage(const Scaleform::GFx::FunctionHandler::Params&)
{
    m_nPage += kRows;
    ResetPage(false);
}

// GMS 0x7a2ea0: one row per level from m_nPage; a level without free and paid rewards hides its row.
void UIMapleSurvivalPassDialog::RefreshRewardPage()
{
    if (m_rewardInfo.get() == 0)
        return;
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    for (int i = 0; i < kRows; ++i)
    {
        if (m_row[i].get() == 0)
            continue;
        int nLevel = m_nPage + i;
        const SurvivalPassReward* pFree = FindReward(pTab->m_passRewards, nLevel);
        const SurvivalPassReward* pPaid = FindReward(pTab->m_passRewardsPaid, nLevel);
        if (pFree == 0 && pPaid == 0)
        {
            m_row[i].operator->()->vfunc_4(false);
            continue;
        }
        m_row[i].operator->()->vfunc_4(true);
        SetText(Text(m_row[i], "m_levelText"), Num(nLevel));
        RefreshCell(i, 0, m_cell[i][0], pFree ? &pFree->entry[0] : 0, nLevel, false, pFree && pFree->bSpecial);
        RefreshCell(i, 1, m_cell[i][1], pPaid ? &pPaid->entry[0] : 0, nLevel, true, pPaid && pPaid->bSpecial);
        RefreshCell(i, 2, m_cell[i][2], pPaid ? &pPaid->entry[1] : 0, nLevel, true, pPaid && pPaid->bSpecial);
    }
}

// GMS 0x7a28d0: one reward cell (item, gender item or additional effect) and its claim state overlay.
void UIMapleSurvivalPassDialog::RefreshCell(int nRow, int nCol, MS2Ptr<ASMovieClip>& spCell, const SurvivalPassRewardEntry* pEntry, int nLevel, bool bPaid, bool bSpecial)
{
    if (spCell.get() == 0)
        return;
    ASMovieClip* pCell = spCell.operator->();
    if (pEntry != 0 && pEntry->type.IsEmpty())
        pEntry = 0;
    MS2Ptr<ASMovieClip> spSlotClip = Clip(spCell, "m_slot");
    if (pEntry == 0)
    {
        pCell->vfunc_15(CString("hide"));
        Show(spSlotClip, false);
        return;
    }
    pCell->vfunc_15(CString("show"));
    Show(spSlotClip, true);

    int nKind = pEntry->type == L"additionalEffect" ? 2 : 1;
    if (m_cellKind[nRow][nCol] != nKind)
    {
        // drop the old wrapper before the new one registers its tooltip callback on the same AS object
        m_cellItem[nRow][nCol] = 0;
        m_cellEffect[nRow][nCol] = 0;
        if (nKind == 2)
            m_cellEffect[nRow][nCol] = Bind<ASAdditionalEffectSlot>(pCell, "m_slot");
        else
            m_cellItem[nRow][nCol] = Bind<ASItemSlot>(pCell, "m_slot");
        m_cellKind[nRow][nCol] = nKind;
    }
    if (nKind == 2)
    {
        if (m_cellEffect[nRow][nCol].get() != 0)
            m_cellEffect[nRow][nCol].operator->()->SetEffect(_wtoi(pEntry->id), (unsigned short)_wtoi(pEntry->value));
    }
    else if (m_cellItem[nRow][nCol].get() != 0)
    {
        // "item": id / rarity / count. "genderItem" lists "male,female" ids; GMS picks by the player's gender, the
        // restore takes the first one.
        CStringW strId = pEntry->id;
        int nComma = strId.Find(L',');
        if (nComma >= 0)
            strId = strId.Left(nComma);
        int nCount = _wtoi(pEntry->count);
        m_cellItem[nRow][nCol].operator->()->SetItem(_wtoi(strId), _wtoi(pEntry->value), nCount > 0 ? nCount : 1);
    }

    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    int nClaimed = bPaid ? pMgr->m_20 : pMgr->m_1e;
    MS2Ptr<ASMovieClip> spOver = Clip(spCell, "m_slotOverLap");
    if (nLevel <= nClaimed)
        Goto(spOver, "received");
    else if (bPaid && pMgr->m_1c == 0)
        Goto(spOver, "needPaidPass");
    else if (pMgr->m_level < nLevel)
        Goto(spOver, "needLevel");
    else
    {
        Goto(spOver, "normal");
        MS2Ptr<ASMovieClip> spEffect = Clip(spOver, "m_effect");
        if (spEffect.get() != 0)
            spEffect.operator->()->vfunc_6();
    }
    Show(Clip(spCell, "m_isSpecialItem"), bSpecial);
}

// GMS 0x7a0150: claim up to one page of free and paid levels; with the pass both tracks stop at the same level.
void UIMapleSurvivalPassDialog::OnReceive(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    int nLevel = pMgr->m_level;
    int a = pMgr->m_1e;
    int b = pMgr->m_20;
    int iFree = nLevel - a;
    if (iFree < 0)
        iFree = 0;
    if (iFree > kRows)
        iFree = kRows;
    int iPaid = nLevel - b;
    if (iPaid < 0)
        iPaid = 0;
    if (iPaid > kRows)
        iPaid = kRows;
    if (pMgr->m_1c != 0)
    {
        int t = a + iFree < b + iPaid ? a + iFree : b + iPaid;
        iPaid = t - b > 0 ? t - b : 0;
        iFree = t - a > 0 ? t - a : 0;
    }
    else
        iPaid = 0;
    if (iFree == 0 && iPaid == 0)
    {
        ShowSystemNotice(Key(L"s_maple_survival_pass_gain_nothing"), 1, 1);
        return;
    }
    pMgr->ClaimRewards(iFree, iPaid);
}

// GMS 0x7a1460: buy the paid pass. While the pass-bundle event runs the bundle window opens instead.
void UIMapleSurvivalPassDialog::OnBuyPaidPass(const Scaleform::GFx::FunctionHandler::Params&)
{
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    if (pMgr->m_1c != 0)
        return;
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    std::map<int, SurvivalOpenPeriod>::const_iterator it = pTab->m_periods.find(pMgr->m_seasonId);
    if (it == pTab->m_periods.end())
        return;
    __int64 a = 0, b = 0;
    int c = 0;
    if (GetMapleSurvivalPassBundle(a, b, c))
    {
        CUIService::GetInstance()->OpenDialog((eUIClassID)MS2_UI_MAPLESURVIVAL_BUYBUNDLE);
        return;
    }
    CStringW strText = Arg(Key(L"s_maple_survival_ui_buy_paid_pass"), 0, Num(it->second.passPrice));
    if (MS2Ptr<CMsgBoxData> box = FUN_140d73f20(strText, 1))
    {
        box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMapleSurvivalPassDialog::OnBuyBox));
        FUN_140d73c60(box);
    }
}

// GMS 0x7a03d0: OK buys the pass at the season's price (looked up again: the season may have changed).
bool UIMapleSurvivalPassDialog::OnBuyBox(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0 && box.GetTimer().m_nButton == 0)
    {
        CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
        CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
        std::map<int, SurvivalOpenPeriod>::const_iterator it = pTab->m_periods.find(pMgr->m_seasonId);
        if (it != pTab->m_periods.end() && pMgr->m_1c == 0)
            pMgr->BuyPass(true, it->second.passPrice);
    }
    return true;
}

// GMS 0x7a1420: the skin window on the clicked slot (open it, or refresh it when it is open).
void UIMapleSurvivalPassDialog::OnSkinPlus(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nSlot = UserInt(params);
    if (nSlot < 0 || nSlot > 2)
        return;
    CUIService* pUI = CUIService::GetInstance();
    MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_MAPLESURVIVAL_SKIN);
    if (sp.get() == 0)
        return;
    UIMapleSurvivalSkinDialog* pSkin = static_cast<UIMapleSurvivalSkinDialog*>(sp.operator->());
    pSkin->SetSlot(nSlot);
    if (!pUI->IsDialogOpen((eUIClassID)MS2_UI_MAPLESURVIVAL_SKIN))
        pUI->OpenDialog((eUIClassID)MS2_UI_MAPLESURVIVAL_SKIN);
    else
        pSkin->RefreshSkins();
}

// GMS 0x7a27e0 (+ 0x7a2600 per slot): the equipped skin icon of each slot (none when expired or unknown).
void UIMapleSurvivalPassDialog::RefreshSkins()
{
    if (m_30 == 0 || m_skinInfo.get() == 0)
        return;
    static const char* const kSkin[3] = { "m_tailSkin", "m_ridingSkin", "m_glidingSkin" };
    static const char* const kFrame[3] = { "tail", "riding", "gliding" };
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    __int64 nNow = GetServerTime();
    for (int i = 0; i < 3; ++i)
    {
        MS2Ptr<ASMovieClip> spSkin = Clip(m_skinInfo, kSkin[i]);
        if (spSkin.get() == 0)
            continue;
        const SurvivalSkinSlot& slot = pMgr->m_skinSlots[i];
        const SurvivalSkinInfo* pInfo = 0;
        if (slot.equipped != 0)
        {
            for (size_t k = 0; k < slot.skins.size(); ++k)
            {
                if (slot.skins[k].first != slot.equipped)
                    continue;
                if (slot.skins[k].second >= nNow)
                {
                    std::map<int, SurvivalSkinInfo>::const_iterator it = pTab->m_skins.find(slot.equipped);
                    if (it != pTab->m_skins.end())
                        pInfo = &it->second;
                }
                break;
            }
        }
        MS2Ptr<ASMovieClip> spSlot = Clip(spSkin, "m_slot");
        if (spSlot.get() != 0)
        {
            ASSlot data(2);
            if (pInfo != 0)
                data.SetIconPathString(pInfo->imagePath);
            spSlot.operator->()->Invoke("setSlotData", data);
        }
        spSkin.operator->()->vfunc_15(CString(kFrame[i]));
    }
}

// Manager -> window events (safe when the window is not registered or not loaded: every refresh tests m_30).
namespace
{
UIMapleSurvivalPassDialog* FindPass()
{
    MS2Ptr<UIDialog> sp = CUIService::GetInstance()->FindDialog((eUIClassID)MS2_UI_MAPLESURVIVAL_PASS);
    return static_cast<UIMapleSurvivalPassDialog*>(sp.get());   // the service keeps the registered dialog alive
}
}

void MushkingUI::Pass_OnState()
{
    if (UIMapleSurvivalPassDialog* p = FindPass())
        p->RefreshState();
}

void MushkingUI::Pass_OnSeason()
{
    if (UIMapleSurvivalPassDialog* p = FindPass())
        p->RefreshSeason();
}

void MushkingUI::Pass_OnRecord()
{
    if (UIMapleSurvivalPassDialog* p = FindPass())
        p->RefreshRecord();
}

void MushkingUI::Pass_OnSkins()
{
    if (UIMapleSurvivalPassDialog* p = FindPass())
        p->RefreshSkins();
}

#endif   // MS2_HOOK_DLL
