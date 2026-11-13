// survivalgameresultdialog.cpp - Mushking Royale restore: UISurvivalGameResultDialog. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: survivalgameresultdialog
// MS2-NO-EXE: 0x140db5396 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/client/ms2/survivalgameresultdialog.h"
#include "ms2/client/ms2/survivalkilllogdialog.h"
#include "ms2/client/ms2/survivalobserverdialog.h"
#include "ms2/client/ms2/stormbar.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/opcodes.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- KMS helpers (declarations as their other callers have them) ----
CStringW GetStringCommonByKey(const CStringW& strKey);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);   // GMS 0xa1fd00
void FUN_140710590(COutPacket& packet);                                  // send
int FUN_1418fc760(const char* szMethod, void* pArgs, int nArgs, void* pDlg);   // common AS callbacks (UIDialog users)

namespace
{
// CMapleSurvivalManager::m_result.r[] index of each GMS dialog field. The mode 0x11 handler (GMS 0x6e3110) reads
// 16 ints and passes them to the setter 0x89b290 as r0, r2, r3, r4, r5, r6..r11, r14, r15, r13, 0, 0, r12, 0, 0
// (stored from +0x110 on); r1 is dropped.
enum
{
    kResult0 = 0,           // +0x110 ("setResult" fifth arg)
    kRatingBefore = 2,      // +0x114
    kRatingAfter = 3,       // +0x118
    kKills = 4,             // +0x11c ("setGameRecord" first arg)
    kRank = 5,              // +0x120 ("setGameRecord" second arg)
    kLevel0 = 6,            // +0x124..+0x134: "setSurvivalLevelResult" first five args
    kLevelNow = 10,         // +0x134 (compared with the table's max level)
    kResult11 = 11,         // +0x138 ("setResult" fourth arg)
    kCharLevel = 12,        // +0x150 ("setCharLevelResult" first arg)
    kHeroLevel = 13,        // +0x144 ("setHeroLevelResult" first arg)
    kSeconds = 14,          // +0x13c survival time
    kRecord15 = 15,         // +0x140 ("setGameRecord" fourth arg)
};

const int kTopN = 10;       // GMS: constants +0x7ca4 (value not known)

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

UISurvivalGameResultDialog* FindResult()
{
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_SURVIVAL_GAMERESULT);
    if (sp.get() == 0)
        return 0;
    return static_cast<UISurvivalGameResultDialog*>(sp.operator->());   // the service keeps the dialog alive
}

MS2Ptr<ASItemSlot> BindSlot(const Scaleform::GFx::Value& parent, int nIndex, int nMovieId)
{
    // GMS 0x89af40 formats the child name of m_RewardItems with the index 1..5 (format string not recovered); the
    // usual KMS names are tried in turn.
    static const char* const s_formats[] = { "m_item%d", "item%d", "m_slot%d", "slot%d", "m_itemSlot%d" };
    for (int f = 0; f < (int)(sizeof(s_formats) / sizeof(s_formats[0])); ++f)
    {
        CStringA name;
        name.Format(s_formats[f], nIndex);
        Scaleform::GFx::Value v;
        if (parent.GetMember(name, &v) && v.IsObject())
            return MS2Ptr<ASItemSlot>(new ASItemSlot(v, nMovieId));
    }
    return MS2Ptr<ASItemSlot>(0);
}
}

// GMS 0x899aa0
UISurvivalGameResultDialog::UISurvivalGameResultDialog() : m_bPending(false), m_bWatching(false), m_nFieldId(0)
{
}

UISurvivalGameResultDialog::~UISurvivalGameResultDialog()
{
}

// GMS 0x8999e0
CString UISurvivalGameResultDialog::GetTypeName()
{
    return "SurvivalGameResultDialog";
}

// GMS 0x89af40: close button, the 5 reward slots, the kept result, then "initData" with an object of one member,
// visibleWatchButton: feature 0xb2 on (0x4a9870) and not (a flag at +0x38 of the object at +0xc20 of 0x1ad1848 and a
// value below 50, 0x6019b0). The observer feature check here is the one OnWatch uses; the second test is left out.
void UISurvivalGameResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    BindCloseButton("m_closeButton");
    if (m_30.IsNull())
        return;
    // uisurvivalgameresultdialog.gfx: m_RewardItems sits in m_bottom, and the movie's root placement is named
    // m_mainClip, so the path is tried from the bound object and from m_mainClip (and the old root name last).
    Scaleform::GFx::Value items;
    {
        Scaleform::GFx::Value top = m_30->GetMember("m_mainClip");
        Scaleform::GFx::Value bottom = m_30->GetMember("m_bottom");
        if (!bottom.IsObject() && top.IsObject())
            top.GetMember("m_bottom", &bottom);
        if (bottom.IsObject())
            bottom.GetMember("m_RewardItems", &items);
        if (!items.IsObject())
            items = m_30->GetMember("m_RewardItems");
    }
    for (int i = 0; i < 5; ++i)
        m_slot[i] = items.IsObject() ? BindSlot(items, i + 1, m_30->FUN_14198f250()) : MS2Ptr<ASItemSlot>(0);
    ASObj obj(2);
    obj.SetBoolMember("visibleWatchButton", !IsMapleSurvivalShutdown(3));
    m_30->Invoke("initData", obj.GetValue());
    if (m_bPending)
    {
        m_bPending = false;
        Populate();
    }
}

// GMS 0x899e50
void UISurvivalGameResultDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (int i = 0; i < 5; ++i)
        m_slot[i] = 0;
}

// GMS 0x89a090: "OnExit" closes (and leaves the field), "OnWatch" spectates the local player's killer.
int UISurvivalGameResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, (int)nArgs, (void*)this) != 0)
        return 1;
    if (_stricmp("OnExit", szMethod) == 0)
    {
        m_bWatching = false;
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnWatch", szMethod) != 0)
        return 0;
    // GMS 0x899b30 == 0 -> notice string 0x309 (the observer feature is off); the KMS string id is unknown.
    if (IsMapleSurvivalShutdown(3))
        return 0;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    WorldService* pWs = WorldService::GetInstance();
    if (pMgr != 0 && !pMgr->m_finishList.empty())
    {
        ShowSystemNotice(Key(L"s_maple_survival_ui_observer_game_finish"), 1, 1);
        return 0;
    }
    if (pWs == 0 || pWs->GetLocalPlayer() == 0)
        return 0;
    // (GMS 0x4ab450 / 0xb79e70: in a squad, only while a party member is alive -- left out.)
    CUIService* pUI = CUIService::GetInstance();
    if (pUI != 0)
    {
        MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_SURVIVAL_KILLLOG);
        if (sp.get() != 0)
            static_cast<UISurvivalKillLogDialog*>(sp.operator->())->SetVisiblePlayInfo(false);
    }
    COutPacket packet(static_cast<int>(SendOp::SpectateMushtopia), 0);
    packet.WriteUInt8(0);
    packet.WriteInt64(UISurvivalKillLogDialog::s_killerId);
    FUN_140710590(packet);
    m_bWatching = true;
    vfunc_67();
    return 1;
}

// GMS 0x899f60: closing the result leaves the field (RequestMoveField u8 1) unless OnWatch was sent. (GMS also
// re-shows three KMS HUD windows hidden by slot 8, 0x899ef0: left out.) Here the leave is skipped once the player
// is no longer in the game field.
void UISurvivalGameResultDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    if (m_bWatching)
        return;
    WorldService* pWs = WorldService::GetInstance();
    if (pWs == 0 || pWs->GetLocalPlayer() == 0 || pWs->GetFieldId() != m_nFieldId)
        return;
    COutPacket packet(static_cast<int>(SendOp::RequestMoveField), 0);
    packet.WriteUInt8(1);
    FUN_140710590(packet);
}

// GMS 0x89a4d0
void UISurvivalGameResultDialog::Populate()
{
    if (m_30.IsNull())
    {
        m_bPending = true;
        return;
    }
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    if (pMgr == 0)
        return;
    const SurvivalGameResult& res = pMgr->m_result;
    const int* r = res.r;

    // Headline (GMS +0x1ec is a squad override text that nothing sets here).
    CStringW strMessage;
    if (r[kRank] == 1)
        strMessage = Key(L"s_maple_survival_ui_result_message_victory");
    else if (r[kRank] > 1 && r[kRank] <= kTopN)
        strMessage = Key(L"s_maple_survival_ui_result_message_top_n");
    else
        strMessage = Key(L"s_maple_survival_ui_result_message_etc");

    int nSec = r[kSeconds];
    CStringW strTime;
    strTime.Format(L"%02d:%02d:%02d", nSec / 3600, nSec % 3600 / 60, nSec % 60);

    CStringW strDelta;
    CStringW strNum;
    if (r[kRatingBefore] < r[kRatingAfter])
    {
        strNum.Format(L"%d", r[kRatingAfter] - r[kRatingBefore]);
        strDelta = Arg(Key(L"s_maple_survival_ui_result_rating_delta_up"), 0, strNum);
    }
    if (r[kRatingAfter] < r[kRatingBefore])
    {
        strNum.Format(L"%d", r[kRatingBefore] - r[kRatingAfter]);
        strDelta = Arg(Key(L"s_maple_survival_ui_result_rating_delta_down"), 0, strNum);
    }

    int nMaxLevel = 0;
    const std::map<int, SurvivalLevelData>& levels = CMapleSurvivalTable::Get().m_levels;
    if (!levels.empty())
        nMaxLevel = levels.rbegin()->second.level;   // GMS 0x89b510
    bool bMaxLevel = nMaxLevel <= r[kLevelNow];
    bool bBuff = res.f[0] > 0.0f || res.f[1] > 0.0f || res.f[2] > 0.0f || res.f[3] > 0.0f;
    // GMS 0x626320(level + 1): reqExp of the next level's row, low 32 bits; no row gives INT64_MAX -> -1.
    int nNextReq = -1;
    {
        std::map<int, SurvivalLevelData>::const_iterator it = levels.find(r[kLevelNow] + 1);
        if (it != levels.end())
            nNextReq = (int)it->second.reqExp;
    }

    // Method names and arg lists as the result gfx declares them; the binds as GMS 0x89a7b9..0x89a95f pushes them.
    {
        ASArgList args;   // GMS 0x6fe360
        args.push_back(Scaleform::GFx::Value((const wchar_t*)strMessage));
        m_30->FUN_1422bb8f0("setGameMessage", args);
    }
    {
        ASArgList args;   // setGameRecord(int, int, String, int)
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kKills]));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kRank]));
        args.push_back(Scaleform::GFx::Value((const wchar_t*)strTime));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kRecord15]));
        m_30->FUN_1422bb8f0("setGameRecord", args);
    }
    {
        ASArgList args;   // setResult(int, int, String, int, int)
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kRatingBefore]));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kRatingAfter]));
        args.push_back(Scaleform::GFx::Value((const wchar_t*)strDelta));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kResult11]));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kResult0]));
        m_30->FUN_1422bb8f0("setResult", args);
    }
    {
        ASArgList args;   // setHeroLevelResult(int, int, int): GMS +0x144, +0x148, +0x14c (the last two are 0)
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kHeroLevel]));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)0));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)0));
        m_30->FUN_1422bb8f0("setHeroLevelResult", args);
    }
    {
        ASArgList args;   // setSurvivalLevelResult(int x6, Boolean, Boolean)
        for (int i = kLevel0; i <= kLevelNow; ++i)
            args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[i]));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)nNextReq));
        args.push_back(Scaleform::GFx::Value(bMaxLevel));
        args.push_back(Scaleform::GFx::Value(bBuff));
        m_30->FUN_1422bb8f0("setSurvivalLevelResult", args);
    }
    {
        ASArgList args;   // setCharLevelResult(int, int, int): GMS +0x150, +0x154, +0x158 (the last two are 0)
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)r[kCharLevel]));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)0));
        args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)0));
        m_30->FUN_1422bb8f0("setCharLevelResult", args);
    }

    for (int i = 0; i < 5; ++i)
    {
        if (m_slot[i].get() == 0)
            continue;
        if (i < (int)res.items.size())
        {
            const SurvivalResultItem& it = res.items[i];
            m_slot[i].operator->()->SetItem(it.id, it.rarity, it.count);
            m_slot[i].operator->()->vfunc_4(true);
        }
        else
        {
            m_slot[i].operator->()->vfunc_4(false);
        }
    }
}

// GMS 0x89b290 (setter, then populate) with the open done by its caller 0x6e3110.
void UISurvivalGameResultDialog::OnShow()
{
    CUIService* pUI = CUIService::GetInstance();
    if (pUI != 0 && !pUI->IsDialogOpen((eUIClassID)MS2_UI_SURVIVAL_GAMERESULT))
        pUI->OpenDialog((eUIClassID)MS2_UI_SURVIVAL_GAMERESULT);
    WorldService* pWs = WorldService::GetInstance();
    m_nFieldId = pWs != 0 ? pWs->GetFieldId() : 0;
    m_bWatching = false;
    Populate();
}

namespace MushkingUI
{
// Mode 0x11
void Result_Show()
{
    UISurvivalGameResultDialog* pDlg = FindResult();
    if (pDlg != 0)
        pDlg->OnShow();
}

void RegisterGameDialogs()
{
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UISurvivalGameResultDialog));
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UISurvivalKillLogDialog));
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UISurvivalObserverDialog));
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UIStormBar));
}
}

#endif   // MS2_HOOK_DLL
