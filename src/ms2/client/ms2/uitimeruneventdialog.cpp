// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITimeRunEventDialog: see uitimeruneventdialog.h.
// MS2-UNIT: ?\uitimeruneventdialog.cpp
// MS2-RANGE: 0x140ee2190-0x140ee52f0 .text$mn
// MS2-RANGE: 0x1400dccc0-0x1400dce30 .text$di
// MS2-RANGE: 0x142ca8690-0x142ca8720 .text$yd
// MS2-GUESS-LOOKALIKES
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitimeruneventdialog.cpp"    // assumed
#define MS2_ASUICOMPONENT_SLOTS   // ASUIComponent slot 24 (validateNow) for the "m_list" refresh

#include "ms2/placeholder/ms2stdafx.h"

#include "uitimeruneventdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include <algorithm>
#include <map>
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/client/ms2/uidailymissiondialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The root script object of the dialog, as the Invoke back end sees it. Only the overloads this unit calls.
class Unk_TrScript
{
public:
    // C3: FUN_140eba060 is AScript::FUN_140eba060(const char*, const AScript&, unsigned) (ascript.h)
};
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* szText);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

// The counter tables (0x143ab3010): lookup by (kind, id) with a default.
class Unk_AttendTable { public: int GetValue(int nKind, unsigned nId, const int& nDefault); };
extern GameEventUserValue DAT_143ab3010;

class Unk_SSGDlg4e28 { public: void MarkDirty(); };   // the game menu dialog (UI type 0x4e28); def in uileveluppackagedialog
class UIGameMenuDialog* FindGameMenuDialog(int nType);

void* GetGameRule();
void* FUN_140764020();
MS2Ptr<CQuestData> GetQuestData(int nQuestId);
UIQuestEventDispatcher* FUN_140bfc4b0();
int FUN_140718170(const CString& str);
__int64 GetServerTime();                                // the server time
__int64 FUN_140761ba0(int nA, int nB);
CStringW FUN_1409404f0(__int64 n);
CStringW GetQuestSummary(int nQuest, int n);
void FUN_140710590(COutPacket& packet);
#define TR_CAT(a, b) ((a) + (b))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140ee2190
UITimeRunEventDialog::UITimeRunEventDialog() : m_missionBinder(TR_CAT(GetTypeName(), "_mission")), m_mapBinder(TR_CAT(GetTypeName(), "_map"))
{
    SetTweenEnabled(1);
}

// @0x140ee2330
UITimeRunEventDialog::~UITimeRunEventDialog() {}

// @0x140ee23c0
CString UITimeRunEventDialog::GetTypeName() { return "TimeRunEventDialog"; }

// @0x140ee2410
int UITimeRunEventDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65()) return 0;
    FUN_140bfc4b0()->AddListener(this);
    return 1;
}

// @0x140ee2470
void UITimeRunEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->RemoveListener(this);
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee24d0
void UITimeRunEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull()) {
        vfunc_67();
        return;
    }
    reinterpret_cast<AScript*>(m_30.operator->())->Invoke("setDay", GetElapsedDays(spContext));
    if (MS2Ptr<ASTextField> spText = GetChild<ASTextField>("m_remainTime"))
        spText->SetTextW(FUN_140ee4380(spContext));
    UpdateRewardData();
    UpdateTabCounts();
}

// @0x140ee26d0
int UITimeRunEventDialog::vfunc_13() { return UIDialog::vfunc_13(); }

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee26f0
void UITimeRunEventDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if ((strMethod == "getTabTooltip")) {
        int nTab = FUN_140718170(pArgs->FUN_1422b8d30());
        MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
        if (spContext.get() != 0) {
            CMsTime now(GetServerTime());
            CMsTime start(GetStartTime(spContext));
            AddDays(start, nTab);
            if (start.Get() > now.Get()) {
                ATL::CTimeSpan span = start - now;
                CStringW strRemain = FormatTimeSpan(span, true, true, true, true);
                ASTooltip tip(2);
                if (tip.ApplyTextTooltip(FUN_14028dfa0<CStringW>(CStringW(L"s_timerun_remain_time_from_day"), strRemain)))
                    *pRetVal = tip.GetValue();
            }
        }
    } else if ((strMethod == "getTooltip")) {
        CStringW strKind = pArgs->FUN_1422b8f40();
        if (operator==(strKind, "guide")) {
            int nQuest = pArgs->PopUInt();
            MS2Ptr<CQuestData> data = GetQuestData(nQuest);
            if (data.get() != 0) {
                void* pMyPC = WorldService::GetInstance()->FUN_141bd0cc0();
                if (pMyPC == 0) return;
                ASTooltip tip(2);
                if (tip.ApplyTextTooltip(FUN_1409404f0(FUN_140761ba0(nQuest, 1)))) {
                    tip.SetTooltipAlign(1);
                    *pRetVal = tip.GetValue();
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee2b30
int UITimeRunEventDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    if (!_stricmp(szMethod, "onTabChange")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nTab = data.PopInt();
            FUN_140ee3c00(nTab + 1);
        }
        return 1;
    } else if (!_stricmp(szMethod, "onReceiveItem")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nItem = data.PopUInt();
            COutPacket packet(static_cast<int>(SendOp::Quest), 0);
            packet.Encode1(0x1b);
            packet.Encode4(nItem);
            FUN_140710590(packet);
        }
        return 1;
    } else if (!_stricmp(szMethod, "onClickFinalReward")) {
        MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
        if (spContext.get() != 0) {
            int nDefault = 0;
            int nReceived = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dc, spContext->m_eventId, nDefault);
            if (nReceived == 0) {
                COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
                packet.Encode1(3);
                FUN_140710590(packet);
            }
        }
        return 1;
    } else if (!_stricmp(szMethod, "onClickReward")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nKey = data.PopUInt();
            MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
            if (spContext.get() != 0) {
                int nDefault = 0;
                int nTaken = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dd, spContext->m_eventId, nDefault);
                if (nKey == spContext->GetNextRewardKey(nTaken)) {
                    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
                    packet.Encode1(4);
                    packet.Encode4(nKey);
                    FUN_140710590(packet);
                }
            }
            return 1;
        }
    }
    return 0;
}

// @0x140ee2f20
void UITimeRunEventDialog::vfunc_o178_10(void* pQuest)
{
    if (m_30.IsNull()) return;
    bool bSkip = static_cast<CQuest*>(pQuest)->GetData()->m_350.m_value != 3;
    if (bSkip) return;
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull()) return;
    MS2Ptr<TimeRunEventContext::QuestContext> spQuest(0);
    if (spContext->m_quests.Lookup(static_cast<CQuest*>(pQuest)->GetQuestId(), spQuest)) {
        if (spQuest->m_20 == GetSelectedDay())
            FUN_140ee3c00(spQuest->m_20);
    }
    UpdateRewardData();
    UpdateTabCounts();
}

// @0x140ee3100
void UITimeRunEventDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_tick.Check(1000)) {
        MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
        if (spContext.IsNull()) {
            vfunc_67();
            return;
        }
        if (MS2Ptr<ASTextField> spText = GetChild<ASTextField>("m_remainTime"))
            spText->SetTextW(FUN_140ee4380(spContext));
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee3290
int UITimeRunEventDialog::FUN_140ee3290()
{
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull()) return 0;
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        MS2Ptr<CQuest> quest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(spQuest->m_questId);
        if (quest.IsNull()) return 0;
        if (quest->GetState() == 3) return 0;
    }
    int nDefault = 0;
    int nReceived = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dc, spContext->m_eventId, nDefault);
    if (nReceived == 0) return 1;
    int nDefault2 = 0;
    unsigned nTaken = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dd, spContext->m_eventId, nDefault2);
    for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != NULL; spContext->m_rewards.GetNext(pos)) {
        unsigned nKey = spContext->m_rewards.GetKeyAt(pos);
        if (nTaken < nKey) return 1;
    }
    return 0;
}

// @0x140ee3580
void UITimeRunEventDialog::UpdateRewardData()
{
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull())
        return;
    unsigned nDistance = GetEarnedDistance(spContext);
    int nDefault = 0;
    unsigned nTaken = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dd, spContext->m_eventId, nDefault);
    int nDefault2 = 0;
    int nReceived = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dc, spContext->m_eventId, nDefault2);
    unsigned nNext = spContext->GetNextRewardKey(nTaken);
    reinterpret_cast<AScript*>(m_30.operator->())->Invoke("setMapData", (int)spContext->m_1c, (int)nDistance);
    m_mapBinder.FUN_140d43990();
    ASArray rewards(2);
    for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != NULL; spContext->m_rewards.GetNext(pos)) {
        unsigned nKey = spContext->m_rewards.GetKeyAt(pos);
        MS2Ptr<ItemEntity> spItem = spContext->m_rewards.GetValueAt(pos);
        BOOL bReached = nKey <= nDistance;
        BOOL bNext = nKey == nNext;
        BOOL bTaken = nKey < nTaken;
        ASObj row(2);
        row.SetMemberUInt("distance", nKey);
        row.SetStringMember("binding", m_mapBinder.FUN_140d43510(static_cast<ItemAble*>((ItemEntity*)spItem)));
        row.SetBoolMember("enabled", bReached && bNext && !bTaken ? true : false);
        row.SetIntMember("visible", bReached);
        rewards.PushObj(row);
    }
    reinterpret_cast<AScript*>(m_30.operator->())->FUN_140eba060("setRewardData", rewards, spContext->m_1c);
    reinterpret_cast<AScript*>(m_30.operator->())->FUN_140ee5060("setFinalReward", m_mapBinder.FUN_140d43510(static_cast<ItemAble*>(&spContext->m_item)), nDistance >= (unsigned)spContext->m_1c && nReceived == 0 ? true : false);
    if (MS2Ptr<ASTextField> spText = GetChild<ASTextField>("m_totalDistance"))
    {
        CStringW strDistance = FUN_14028dfa0(CStringW(L"s_timerun_total_distance"), nDistance);
        spText->SetTextW(strDistance);
    }
}

// @0x140ee3c00
void UITimeRunEventDialog::FUN_140ee3c00(int nDay)
{
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull()) {
        vfunc_67();
        return;
    }
    m_missionBinder.FUN_140d43990();
    if (MS2Ptr<ASScrollingList> spList = reinterpret_cast<UIDailyMissionDialog*>(this)->GetScrollingList("m_list")) {   // the list getter of UIDailyMissionDialog
        spList->FUN_1422dd1d0();
        for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
            MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
            if (spQuest->m_20 != nDay)
                continue;
            MS2Ptr<CQuest> quest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(spQuest->m_questId);
            if (quest.IsNull())
                continue;
            if (quest->GetData()->m_complete.m_choiceRewards.GetCount() == 0)
                continue;
            const CQuestData::QuestRewardItem& reward = quest->GetData()->m_complete.m_choiceRewards[0];
            CStringW strDesc = GetQuestSummary((int)quest->GetQuestId(), 0);
            strDesc.Replace(L"#5c2b00", L"#ffffff");
            ASObj row(2);
            row.SetMemberUInt("id", spQuest->m_questId);
            row.SetIntMember("completed", quest->IsRewarded());
            row.SetIntMember("satisfied", quest->IsComplete());
            row.SetWStringMember("label", FUN_14028dfa0(CStringW(L"s_timerun_event_distance"), spQuest->m_1c));
            row.SetWStringMember("desc", CStringW(strDesc));
            row.SetStringMember("binding", m_missionBinder.BindNewItem(reward.m_itemId, reward.m_count, reward.m_job));
            row.FUN_1409c1180("exp", FUN_140761ba0((int)spQuest->m_questId, 1));
            spList->AddItem(row);
        }
        spList->vfunc_24(true);
    }
}

// @0x140ee4280
int UITimeRunEventDialog::GetEarnedDistance(MS2Ptr<TimeRunEventContext> spContext)
{
    int nSum = 0;
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        TimeRunEventContext::QuestContext* pQuest = spQuest.operator->();
        if (static_cast<CQuestManager*>(FUN_140764020())->IsQuestRewarded(pQuest->m_questId) != 0)
            nSum += spQuest->m_1c;
    }
    return nSum;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee4380
CStringW UITimeRunEventDialog::FUN_140ee4380(MS2Ptr<TimeRunEventContext> spContext)
{
    __int64 nEnd = 0;
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        MS2Ptr<CQuest> quest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0) {
            nEnd = quest->GetEndTime();
            break;
        }
    }
    ATL::CTimeSpan span = CMsTime(nEnd) - CMsTime(GetServerTime());
    return FormatTimeSpan(span, true, true, true, true);
}

// @0x140ee4570
void UITimeRunEventDialog::OpenRewardDialog(int)
{
    UpdateRewardData();
    Unk_SSGDlg4e28* pDlg = reinterpret_cast<Unk_SSGDlg4e28*>(FindGameMenuDialog(0x4e28));
    if (pDlg != 0)
        pDlg->MarkDirty();
}

// @0x140ee45c0
int UITimeRunEventDialog::GetClaimableCount()
{
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull()) return 0;
    int nCount = 0;
    int bAll = 1;
    unsigned nTotal = 0;
    CMsTime now(GetServerTime());
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        MS2Ptr<CQuest> quest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0) {
            CMsTime start(quest->GetStartTime());
            AddDays(start, spQuest->m_20 - 1);
            if (now.Get() < start.Get()) {
                bAll = 0;
                continue;
            }
            if (quest->IsComplete() != 0) nCount = nCount + 1;
            if (quest->IsRewarded() == 0) bAll = 0; else nTotal += spQuest->m_1c;
        }
    }
    if (bAll) {
        int nDefault = 0;
        if (reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dc, spContext->m_eventId, nDefault) == 0) nCount = nCount + 1;
    }
    int nDefault2 = 0;
    unsigned nTaken = reinterpret_cast<Unk_AttendTable&>(DAT_143ab3010).GetValue(0x5dd, spContext->m_eventId, nDefault2);
    for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != NULL; spContext->m_rewards.GetNext(pos)) {
        unsigned nKey = spContext->m_rewards.GetKeyAt(pos);
        if (nTotal < nKey)
            continue;
        if (nKey > nTaken) {
            nCount = nCount + 1;
            break;
        }
    }
    return nCount;
}

// @0x140ee4990
__int64 UITimeRunEventDialog::GetStartTime(MS2Ptr<TimeRunEventContext> spContext)
{
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        MS2Ptr<CQuest> quest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0)
            return quest->GetStartTime();
    }
    return 0;
}

// @0x140ee4b00
int UITimeRunEventDialog::GetSelectedDay()
{
    if (MS2Ptr<ASButtonBar> spTab = reinterpret_cast<UIDailyMissionDialog*>(this)->GetButtonBar("m_tab"))
        return spTab.operator->()->GetSelectedIndex() + 1;
    return -1;
}

// @0x140ee4bb0
int UITimeRunEventDialog::GetElapsedDays(MS2Ptr<TimeRunEventContext> spContext)
{
    __int64 tStart = GetStartTime(spContext);
    ATL::CTimeSpan span = CMsTime(GetServerTime()) - CMsTime(tStart);
    int nDays = (int)span.GetDays();
    int nMax = 6;
    int nResult = (std::min)(nMax, nDays);
    return nResult;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee4ca0
void UITimeRunEventDialog::UpdateTabCounts()
{
    if (m_30.IsNull()) return;
    MS2Ptr<TimeRunEventContext> spContext = static_cast<CGameRule*>(GetGameRule())->GetTimeRunEvent();
    if (spContext.IsNull()) return;
    std::map<int, int> counts;
    for (unsigned __int64 i = 1; i <= 7; ++i)
        counts[(int)i] = 0;
    CMsTime now(GetServerTime());
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        MS2Ptr<CQuest> quest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0) {
            CMsTime start(quest->GetStartTime());
            AddDays(start, spQuest->m_20 - 1);
            if (now.Get() < start.Get()) continue;
            if (quest->IsComplete() == 0) continue;
            ++counts[spQuest->m_20];
        }
    }
    for (std::map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
        std::pair<const int, int>* pEntry = it.operator->();
        reinterpret_cast<AScript*>(m_30.operator->())->FUN_1409ba0d0("setTabCount", it->first - 1, pEntry->second);
    }
}

// @0x140ee5060
Scaleform::GFx::Value AScript::FUN_140ee5060(const char* szMethod, CString a1, bool a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bce70(&args[0], (const char*)a1);
    FUN_1422bcce0(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
