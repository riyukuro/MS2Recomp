// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRankPvPDialog: see uirankpvpdialog.h.
// MS2-UNIT: ?\uirankpvpdialog.cpp
// MS2-RANGE: 0x1400e10b0-0x1400e13b0 .text$di
// MS2-RANGE: 0x140f91d90-0x140f99280 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it). The rest of the range is the
// std::map<int, MS2Ptr<ASMovieClip>> glue of the history rows and the click delegates.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirankpvpdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uirankpvpdialog.h"
#include "uimessageboxdata.h"
#include "pvpmanager.h"
#include "pcbase.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/rankugcmarketbuy.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cpvprankduelcomponent.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ----

static CString s_strTooltipAlign = "tooltipAlign";
static CStringW s_strRankArenaJoin = L"rankArenaJoin";              // message box tags
static CStringW s_strRankArenaObserve = L"rankArenaObserve";
static CStringW s_strRankArenaRegister = L"rankArenaRegister";
static CString s_strBuyTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> RankClickDelegate;

class Unk_PCBaseBuffs { public: int FUN_140970020(int nBuffId, unsigned short nLevel, int a, int b); };
class Unk_RankWorld { public: PCBase* FUN_141bd0cc0(); };          // the local player
Unk_RankWorld* FUN_1403ed2d0();
class Unk_RankUIService { public: void FUN_141adc530(int nUiId); }; // close
Unk_RankUIService* FUN_1403ed2b0();
class Unk_RankGradeDialog { public: void FUN_140e2dfc0(int a, int b); };
Unk_RankGradeDialog* FUN_140b2d030(int nUiId);                      // GetDialog
class Unk_RankBrowser { public: void FUN_14135ec00(const CString& strUrl, bool b); };
Unk_RankBrowser* FUN_140c43790(int nUiId);                          // GetDialog
class Unk_RankClientState { public: };
Unk_RankClientState* FUN_1409a8b10();
struct Unk_RankClientFlags { unsigned char m_0; unsigned char m_observer; };
Unk_RankClientFlags* FUN_140c9b8b0(Unk_RankClientState* p);
void FUN_141243540(Unk_RankClientState* p);                         // save the client flags

CFeatureManager* FUN_140166410();
CStringTable* FUN_1401a9d70();
JobTable* FUN_1401d7a50();
CRankingArenaDataTable* FUN_140dc19b0();
CStringW FUN_14028b8e0(const CStringW& str);                        // string table text by key
CStringW FUN_14028de60(int nId);                                    // string table text by id
CStringW FUN_14062b4f0(CStringW strKey, const int& n);             // the key's text formatted with n
CStringW FUN_140b90340(CStringW strKey, const int& a, const int& b, const int& c);
CStringW FUN_1408116a0(int nId, const int& n);                      // the id's text formatted with n
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a, const int& b);
CString FUN_1402bb1c0(const char* szFormat, const int& n);
CString FUN_140e10af0(const char* szFormat, const Unk_JobCode& job);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strFrame);
void FUN_140d73aa0(CStringW text, int nA, int nB, CStringW tag);     // toast
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                        // show the message box
void FUN_1412751f0(const CStringW& text, int nA, int nB);           // notice
void FUN_14151f200();                                               // close the open modal box
void FUN_1413499b0(int nTab);                                       // open the arena shop
bool FUN_1407105c0(COutPacket* packet, int key, int delay);         // rate limited send
bool FUN_14028d780(bool b);
int FUN_140bb9640(void* p);                                         // the click's user data

// @0x140f91d90
UIRankPvPDialog::UIRankPvPDialog()
    : m_gaugeWidth(0)
{
    FUN_141924170(1);
}

// @0x140f91f40
UIRankPvPDialog::~UIRankPvPDialog()
{
}

// @0x140f920b0
CString UIRankPvPDialog::vfunc_1()
{
    return "RankPvPDialog";
}
MS2_REPLACE_METHOD(0x140F920B0, UIRankPvPDialog, vfunc_1, 61, 0x29FDC615);

// @0x140f92100
void UIRankPvPDialog::OnLoadInit()
{
    UIDialog::OnLoadInit();
}
MS2_REPLACE_METHOD(0x140F92100, UIRankPvPDialog, OnLoadInit, 24, 0x13CA9F3E);

// @0x140f92120
void UIRankPvPDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    FUN_1419260d0("m_webGuideButton", 0);
    m_registMenu = GetChild<ASButton>("m_registMenu");
    m_statisticsMenu = GetChild<ASButton>("m_statisticsMenu");
    m_shopButton = GetChild<ASButton>("m_shopButton");
    m_registerPage = GetChild<ASMovieClip>("m_registerPage");
    m_statisticsPage = GetChild<ASMovieClip>("m_statisticsPage");
    m_registMenu->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::FUN_140f95090), 0);
    m_statisticsMenu->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::FUN_140f95090), 1);
    m_shopButton->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::FUN_140f95220), 0);
    if (m_registerPage)
    {
        m_register = m_registerPage->FUN_140acce30<ASButton>("m_register");
        m_unregister = m_registerPage->FUN_140acce30<ASButton>("m_unregister");
        m_observeCheck = m_registerPage->FUN_140c11f50<ASCheckBox>("m_observeCheck");
        m_gauge = m_registerPage->FUN_1409b4560("m_gauge");
        m_showGrade = m_registerPage->FUN_140acce30<ASButton>("m_showGrade");
        m_rewardText = m_registerPage->FUN_1409b4620("m_rewardText");
        m_seasonWinCount = m_registerPage->FUN_1409b4620("m_seasonWinCount");
        m_seasonBestRating = m_registerPage->FUN_1409b4620("m_seasonBestRating");
        m_rating = m_registerPage->FUN_1409b4620("m_rating");
        m_rankMark = m_registerPage->FUN_1409b4560("m_rankMark");
        m_observeCheck->FUN_1422ce090(FUN_140c9b8b0(FUN_1409a8b10())->m_observer);
        m_register->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::FUN_140f95260), 0);
        m_unregister->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::SendPVPMode15), 0);
        m_showGrade->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::FUN_140f95550), 0);
        m_observeCheck->FUN_1422ce240(RankClickDelegate(this, &UIRankPvPDialog::FUN_140f95630), 0);
        m_gaugeWidth = m_gauge->FUN_1422c1340();
    }
    if (m_statisticsPage)
    {
        m_history[1] = m_statisticsPage->FUN_1409b4560("m_history1");
        m_history[10] = m_statisticsPage->FUN_1409b4560("m_history2");
        m_history[20] = m_statisticsPage->FUN_1409b4560("m_history3");
        m_history[30] = m_statisticsPage->FUN_1409b4560("m_history4");
        m_history[40] = m_statisticsPage->FUN_1409b4560("m_history5");
        m_history[50] = m_statisticsPage->FUN_1409b4560("m_history6");
        m_history[60] = m_statisticsPage->FUN_1409b4560("m_history7");
        m_history[70] = m_statisticsPage->FUN_1409b4560("m_history8");
        m_history[80] = m_statisticsPage->FUN_1409b4560("m_history9");
        m_history[90] = m_statisticsPage->FUN_1409b4560("m_history10");
        m_history[100] = m_statisticsPage->FUN_1409b4560("m_history11");
        m_history[110] = m_statisticsPage->FUN_1409b4560("m_history12");
        // Outside Korea the first job row is hidden.
        bool bHideFirst = FUN_140166410()->FUN_14036d8e0() != "KR" && m_history[1] != 0;
        if (bHideFirst)
            m_history[1]->vfunc_4(false);
        if (!FUN_140166410()->FUN_14036d570(8))
        {
            if (m_history[90])
                m_history[90]->vfunc_4(false);
        }
        if (!FUN_140166410()->FUN_14036d570(0x12))
        {
            if (m_history[100])
                m_history[100]->vfunc_4(false);
        }
        if (!FUN_140166410()->FUN_14036d570(0x25))
        {
            if (m_history[110])
                m_history[110]->vfunc_4(false);
        }
        // Stack the visible rows.
        int y = (int)m_history[1]->FUN_1422c1110();
        int nStep = (int)(m_history[10]->FUN_1422c1110() - (float)y);
        std::map<int, MS2Ptr<ASMovieClip> >::iterator it = m_history.begin();
        std::map<int, MS2Ptr<ASMovieClip> >::iterator itEnd = m_history.end();
        for (; it != itEnd; ++it)
        {
            if (it->second == 0)
                continue;
            if (!it->second->FUN_1422bfca0())
                continue;
            it->second->FUN_1422c04a0(y);
            y += nStep;
        }
    }
    CPVPManager::GetInstance()->GetRankDuel()->RefreshLeague();
    FUN_140f94390();
    FUN_140f94490();
    FUN_140f94840();
    m_registerPage->vfunc_3(1);
    m_statisticsPage->vfunc_3(0);
    m_registMenu->FUN_1422ce090(1);
    m_statisticsMenu->FUN_1422ce090(0);
}
MS2_REPLACE_METHOD(0x140F92120, UIRankPvPDialog, OnLoadComplete, 7204, 0xB09A3B85);

// @0x140f93d50
void UIRankPvPDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_registMenu = 0;
    m_statisticsMenu = 0;
    m_shopButton = 0;
    m_registerPage = 0;
    m_statisticsPage = 0;
    m_register = 0;
    m_unregister = 0;
    m_observeCheck = 0;
    m_gauge = 0;
    m_rewardText = 0;
    m_showGrade = 0;
    m_seasonWinCount = 0;
    m_seasonBestRating = 0;
    m_rating = 0;
    m_rankMark = 0;
    m_history.clear();
}
MS2_REPLACE_METHOD(0x140F93D50, UIRankPvPDialog, vfunc_26, 358, 0xB7AF0D70);

// @0x140f93ec0
int UIRankPvPDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            if (strTag == s_strRankArenaJoin || strTag == s_strRankArenaObserve)
            {
                if (!CPVPManager::GetInstance()->GetRankDuel()->RequestCancelMatch())
                {
                    FUN_1412751f0(FUN_14028b8e0(L"s_rank_duel_ui_error_cant_move"), 1, 1);
                    return 0;
                }
                return 1;
            }
            else if (strTag == s_strRankArenaRegister)
            {
                if (FUN_140f95750() == 1)
                    FUN_14151f200();
                return 1;
            }
        }
    }
    else if (pMsg->FUN_1422e4520() == 0x7d2)
    {
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (strTag == s_strRankArenaJoin)
            CPVPManager::GetInstance()->GetRankDuel()->RequestCancelMatch();
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x140f94120
void UIRankPvPDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (strMethod == "getTooltip")
    {
        CString strRequest = pArgs->FUN_1422b8d30();
        if (strRequest == "gradeTooltip")
        {
            ASObj tooltip(2);
            tooltip.FUN_1409c0dc0("tooltip", "guild_champion_ship_tooltip");
            tooltip.FUN_1409eb310(s_strTooltipAlign, 7);
            for (int i = 1; i < 8; i++)
            {
                RankingArenaData* pGrade = FUN_140dc19b0()->GetGrade(i);
                CString strNameKey = FUN_1402bb1c0("rankName{0}", i);
                CString strScoreKey = FUN_1402bb1c0("score{0}", i);
                CStringW strName = FUN_1401a9d70()->FUN_141811980(0x22, pGrade->m_nGrade);
                CStringW strScore = FUN_1408116a0(0x3f7, pGrade->m_nGradeRating);
                tooltip.FUN_1407cbb20(strNameKey, strName);
                tooltip.FUN_1407cbb20(strScoreKey, strScore);
            }
            *pRetVal = tooltip.FUN_1422bb870();
        }
    }
}

// @0x140f94390
void UIRankPvPDialog::FUN_140f94390()
{
    if (m_30 == 0)
        return;
    int nState = CPVPManager::GetInstance()->GetRankDuel()->m_state;
    if (nState == 1)
    {
        m_register->vfunc_3(0);
        m_unregister->vfunc_3(1);
    }
    else
    {
        m_register->vfunc_3(1);
        m_unregister->vfunc_3(0);
    }
}
MS2_REPLACE_METHOD(0x140F94390, UIRankPvPDialog, FUN_140f94390, 248, 0xD338B38A);

// @0x140f94490
void UIRankPvPDialog::FUN_140f94490()
{
    if (m_30 == 0)
        return;
    CPvpRankDuelComponent* pDuel = CPVPManager::GetInstance()->GetRankDuel();
    pDuel->RefreshLeague();
    int nMax = pDuel->CurrentRating();
    int nValue = pDuel->m_value28;
    float fRate = (float)nValue / (float)nMax;
    int nWidth = (int)((float)m_gaugeWidth * fRate);
    if (nWidth > m_gaugeWidth)
        nWidth = m_gaugeWidth;
    m_gauge->FUN_1422c0e20(nWidth);
    m_rewardText->FUN_1422c4cd0(FUN_14083dc40(L"{0} / {1}", nValue, nMax));
    if (nValue > nMax)
        m_rewardText->FUN_1422c50e0(0xc00000);
    else
        m_rewardText->FUN_1422c50e0(0);
    int nWin = CPVPManager::GetInstance()->GetRankDuel()->m_total2c;
    int nRating = pDuel->m_value20;
    int nBest = pDuel->m_value24;
    CStringW strRating = FUN_14062b4f0(CStringW(L"s_rank_duel_ui_rating"), nRating);
    CStringW strBest = FUN_14062b4f0(CStringW(L"s_rank_duel_ui_rating"), nBest);
    CStringW strWin = FUN_14062b4f0(CStringW(L"s_rank_duel_ui_win_count"), nWin);
    m_rating->FUN_1422c4cd0(strRating);
    m_seasonWinCount->FUN_1422c4cd0(strWin);
    m_seasonBestRating->FUN_1422c4cd0(strBest);
    RankingArenaData* pGrade = FUN_140dc19b0()->GetGradeOfRating(nRating);
    int nGrade = pGrade->m_nGrade;
    CString strLabel = FUN_1402bb1c0("_{0}", nGrade);
    m_rankMark->vfunc_15(strLabel);
}
MS2_REPLACE_METHOD(0x140F94490, UIRankPvPDialog, FUN_140f94490, 933, 0x64540A9E);

// @0x140f94840
void UIRankPvPDialog::FUN_140f94840()
{
    if (m_30 == 0)
        return;
    int nWin = CPVPManager::GetInstance()->GetRankDuel()->m_total2c;
    int nLose = CPVPManager::GetInstance()->GetRankDuel()->m_total30;
    int nTotal = nWin + nLose;
    CStringW strTotal = FUN_140b90340(CStringW(L"s_rank_duel_ui_total_history"), nTotal, nWin, nLose);
    FUN_140cfee80((*m_statisticsPage).FUN_1422bb890(), "m_totalHistory", strTotal);
    std::map<int, MS2Ptr<ASMovieClip> >::iterator it = m_history.begin();
    std::map<int, MS2Ptr<ASMovieClip> >::iterator itEnd = m_history.end();
    for (; it != itEnd; ++it)
    {
        MS2Ptr<ASMovieClip> spRow(it->second);
        if (spRow == 0)
            continue;
        if (!spRow->FUN_1422bfca0())
            continue;
        int nJobGroup = it->first;
        MS2Ptr<RankDuelStatisticalData> spRecord = CPVPManager::GetInstance()->GetRankDuel()->FindRecord(nJobGroup);
        if (spRecord == 0)
            spRecord.AssignRaw(new RankDuelStatisticalData);
        FUN_140cffca0((*spRow).FUN_1422bb890(), "jobIcon", FUN_140e10af0("_{0}", FUN_1401d7a50()->GetSubJob1(nJobGroup)));
        FUN_140cfee80((*spRow).FUN_1422bb890(), "jobName", FUN_1401a9d70()->FUN_141811980(0x4d, nJobGroup));
        MS2Ptr<ASTextField> spWinRate = spRow->FUN_1409b4620("winRate");
        CStringW strNone(L"-");
        if (spRecord->m_value1c == 0 && spRecord->m_value20 == 0)
        {
            FUN_140cfee80((*spRow).FUN_1422bb890(), "winCount", strNone);
            if (spWinRate)
            {
                spWinRate->FUN_1422c4cd0(strNone);
                spWinRate->FUN_1422c50e0(0);
            }
        }
        else
        {
            FUN_140cfee80((*spRow).FUN_1422bb890(), "winCount", FUN_14062b4f0(CStringW(L"s_rank_duel_ui_win_count"), spRecord->m_value1c));
            int nRate = spRecord->m_value1c * 100 / (spRecord->m_value1c + spRecord->m_value20);
            if (spWinRate)
            {
                spWinRate->FUN_1422c4cd0(FUN_14062b4f0(CStringW(L"s_rank_duel_ui_win_rate"), nRate));
                if (nRate >= 60)
                    spWinRate->FUN_1422c50e0(0xa2ed);
                else if (nRate <= 40)
                    spWinRate->FUN_1422c50e0(0xc00000);
                else
                    spWinRate->FUN_1422c50e0(0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140F94840, UIRankPvPDialog, FUN_140f94840, 2121, 0xC35C2BBC);

// @0x140f95090
void UIRankPvPDialog::FUN_140f95090(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    int nTab = FUN_140bb9640(params.pUserData);
    if (nTab == 0)
    {
        m_registerPage->vfunc_3(1);
        m_statisticsPage->vfunc_3(0);
        m_registMenu->FUN_1422ce090(1);
        m_statisticsMenu->FUN_1422ce090(0);
    }
    else if (nTab == 1)
    {
        m_registerPage->vfunc_3(0);
        m_statisticsPage->vfunc_3(1);
        m_registMenu->FUN_1422ce090(0);
        m_statisticsMenu->FUN_1422ce090(1);
    }
}
MS2_REPLACE_METHOD(0x140F95090, UIRankPvPDialog, FUN_140f95090, 391, 0x9CD5BE55);

// @0x140f95220
void UIRankPvPDialog::FUN_140f95220(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    FUN_1413499b0(3);
}
MS2_REPLACE_METHOD(0x140F95220, UIRankPvPDialog, FUN_140f95220, 57, 0x6E32C22F);

// @0x140f95260
void UIRankPvPDialog::FUN_140f95260(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    unsigned char nObserver = FUN_140c9b8b0(FUN_1409a8b10())->m_observer;
    if (nObserver == 1)
    {
        // Registering while observing: ask first (OnMessage "rankArenaRegister").
        if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028b8e0(L"s_rank_duel_ui_regist_on_observe"), this,
                                                      s_strRankArenaRegister))
        {
            spBox->FUN_141a02460(1);
            spBox->FUN_141a02480(1);
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        FUN_140f95750();
    }
}

// @0x140f95460
void UIRankPvPDialog::SendPVPMode15(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nState = CPVPManager::GetInstance()->GetRankDuel()->m_state;
    if (nState != 1)
    {
        FUN_140d73aa0(FUN_14028de60(0x428), 0, 0, CStringW(L""));
    }
    else
    {
        COutPacket packet(0x61, 0);
        packet.vfunc_o10_1(0xf);
        FUN_1407105c0(&packet, 0xf, 1000);
    }
}
MS2_REPLACE_METHOD(0x140F95460, UIRankPvPDialog, SendPVPMode15, 219, 0x5F2723A2);

// @0x140f95550
void UIRankPvPDialog::FUN_140f95550(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_140166410()->FUN_14036d570(0x3f) == 1)
    {
        Unk_RankGradeDialog* pDialog = FUN_140b2d030(0x4f24);
        if (pDialog)
        {
            pDialog->FUN_140e2dfc0(4, 0);
            FUN_1403ed2b0()->FUN_141adc530(0x4f24);
        }
    }
    else if (FUN_140166410()->FUN_14036d570(0x3b) == 1)
    {
        Unk_RankBrowser* pBrowser = FUN_140c43790(0x4e6a);
        if (pBrowser == 0)
            return;
        pBrowser->FUN_14135ec00("maview:/Rank/PVP", true);
    }
}
MS2_REPLACE_METHOD(0x140F95550, UIRankPvPDialog, FUN_140f95550, 215, 0x466CFA9B);

// @0x140f95630
void UIRankPvPDialog::FUN_140f95630(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    bool bObserve = FUN_14028d780(m_observeCheck->FUN_1422ce0e0());
    FUN_140c9b8b0(FUN_1409a8b10())->m_observer = bObserve;
    FUN_141243540(FUN_1409a8b10());
    if (bObserve)
        FUN_140d73aa0(FUN_14028b8e0(L"s_rank_duel_ui_observe_notify"), 0, 0, CStringW(L""));
}
MS2_REPLACE_METHOD(0x140F95630, UIRankPvPDialog, FUN_140f95630, 271, 0x177668F5);

// @0x140f95750
bool UIRankPvPDialog::FUN_140f95750()
{
    int nState = CPVPManager::GetInstance()->GetRankDuel()->m_state;
    if (nState != 0)
    {
        FUN_140d73aa0(FUN_14028de60(0x428), 0, 0, CStringW(L""));
        return false;
    }
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (pPlayer->FUN_1416749a0()->FUN_140970020(0x5f5e107, 0, 0, 1) != 0)
    {
        FUN_140d73aa0(FUN_14028de60(0x429), 0, 0, CStringW(L""));
        return false;
    }
    if ((unsigned short)pPlayer->vfunc_78() < (unsigned short)FUN_140166410()->FUN_14036dc20())
    {
        FUN_140d73aa0(FUN_14028de60(0x42a), 0, 0, CStringW(L""));
        return false;
    }
    COutPacket packet(0x61, 0);
    packet.vfunc_o10_1(0xe);
    FUN_1407105c0(&packet, 0xe, 1000);
    return true;
}
MS2_REPLACE_METHOD(0x140F95750, UIRankPvPDialog, FUN_140f95750, 634, 0x2753D075);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa1e0-0x142caa320 .text$yd
