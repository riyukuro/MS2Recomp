// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITimeRunEventDialog: see uitimeruneventdialog.h.
// MS2-UNIT: ?\uitimeruneventdialog.cpp
// MS2-RANGE: 0x140ee2190-0x140ee52f0 .text$mn
// MS2-RANGE: 0x1400dccc0-0x1400dce30 .text$di
// MS2-RANGE: 0x142ca8690-0x142ca8720 .text$yd
// MS2-GUESS-LOOKALIKES
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitimeruneventdialog.cpp"    // assumed

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

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The list control of the movie (the AS list with clear / append).
class Unk_TrList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dd230(const ASObj& row);               // append a row
};

// The day tab strip of the movie.
class Unk_TrTab : public AScript
{
public:
    int FUN_1422e3210();                                // selected tab
};

// The root script object of the dialog, as the Invoke back end sees it. Only the overloads this unit calls.
class Unk_TrScript
{
public:
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int a1);                          // 1 int
    Scaleform::GFx::Value FUN_1409ba0d0(const char* szMethod, int a1, int a2);                  // 2 ints
    Scaleform::GFx::Value FUN_140acd070(const char* szMethod, unsigned int a1, unsigned int a2);   // 2 unsigned
    Scaleform::GFx::Value FUN_140eba060(const char* szMethod, const AScript& a1, unsigned int a2);  // array, unsigned
    Scaleform::GFx::Value FUN_140ee5060(const char* szMethod, CString a1, bool a2);             // string, bool
};
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* szText);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

// The counter tables (0x143ab3010): lookup by (kind, id) with a default.
class Unk_TrCounters { public: int FUN_1409617d0(int nKind, unsigned nId, int* pnDefault); };
extern Unk_TrCounters g_trCounters;

class Unk_TrPlayer { public: void* FUN_141bd0cc0(); };
Unk_TrPlayer* FUN_1403ed2d0();
class Unk_TrDlg { public: void FUN_140ea5f80(); };
Unk_TrDlg* FUN_140938b90(int nType);

CGameRule* FUN_1401c0d90();
CQuestManager* FUN_140764020();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
UIQuestEventDispatcher* FUN_140bfc4b0();
bool FUN_140184310(const CString& str, const char* sz);
bool FUN_140841300(const CStringW& str, const char* sz);
int FUN_140718170(const CString& str);
__int64 FUN_140869440();                                // the server time
__int64 FUN_140282020(const CMsTime& kTime);            // time_t of a CMsTime
__int64 FUN_140761ba0(int nA, int nB);
__int64 FUN_140761ba0(unsigned nA, int nB);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_140938ae0(CStringW strKey, const int& n);
CStringW FUN_140938ae0(CStringW strKey, const unsigned& n);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1416e5350(unsigned nQuest, int n);
void FUN_140710590(COutPacket& packet);
#ifdef __clang__
// clang otherwise emits an unavailable CopyChars DLL import for CString + const char*; bind the exe's operator+.
CString FUN_14038f6d0(const CString& strLeft, const char* szRight);
#define TR_CAT(a, b) FUN_14038f6d0(a, b)
#else
#define TR_CAT(a, b) ((a) + (b))
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140ee2190
UITimeRunEventDialog::UITimeRunEventDialog() : m_missionBinder(TR_CAT(GetTypeName(), "_mission")), m_mapBinder(TR_CAT(GetTypeName(), "_map"))
{
    FUN_141924170(1);
}

// @0x140ee2330
UITimeRunEventDialog::~UITimeRunEventDialog() {}

// @0x140ee23c0
CString UITimeRunEventDialog::GetTypeName() { return "TimeRunEventDialog"; }

// @0x140ee2410
int UITimeRunEventDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65()) return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    return 1;
}

// @0x140ee2470
void UITimeRunEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee24d0
void UITimeRunEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
    if (spContext.IsNull()) {
        vfunc_67();
    } else {
        int nDay = FUN_140ee4bb0(spContext);
        reinterpret_cast<Unk_TrScript*>(m_30.operator->())->FUN_1409ba030("setDay", nDay);
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_remainTime"))
            spText->FUN_1422c4cd0(FUN_140ee4380(spContext));
        FUN_140ee3580();
        FUN_140ee4ca0();
    }
}

// @0x140ee26d0
int UITimeRunEventDialog::vfunc_13() { return UIDialog::vfunc_13(); }

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee26f0
void UITimeRunEventDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (FUN_140184310(strMethod, "getTabTooltip")) {
        int nTab = FUN_140718170(pArgs->FUN_1422b8d30());
        MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
        if (spContext.get() != 0) {
            CMsTime now(FUN_140869440());
            CMsTime start(FUN_140ee4990(spContext));
            AddDays(start, nTab);
            if (now.Get() < start.Get()) {
                CStringW strRemain = FormatTimeSpan(start - now, true, true, true, true);
                ASTooltip tip(2);
                if (tip.FUN_1409e26b0(FUN_1405c2690(CStringW(L"s_timerun_remain_time_from_day"), strRemain)))
                    *pRetVal = tip.FUN_1422bb870();
            }
        }
    } else if (FUN_140184310(strMethod, "getTooltip")) {
        CStringW strKind = pArgs->FUN_1422b8f40();
        if (FUN_140841300(strKind, "guide")) {
            int nQuest = pArgs->FUN_1422b8b10();
            MS2Ptr<CQuestData> data = FUN_14074bc40(nQuest);
            if (data.get() != 0) {
                if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0) return;
                ASTooltip tip(2);
                if (tip.FUN_1409e26b0(FUN_1409404f0(FUN_140761ba0(nQuest, 1)))) {
                    tip.FUN_1409c6dc0(1);
                    *pRetVal = tip.FUN_1422bb870();
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
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nTab = data.FUN_1422b8a10();
            FUN_140ee3c00(nTab + 1);
        }
        return 1;
    } else if (!_stricmp(szMethod, "onReceiveItem")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nItem = data.FUN_1422b8b10();
            COutPacket packet(0x29, 0);
            packet.Encode1(0x1b);
            packet.Encode4(nItem);
            FUN_140710590(packet);
        }
        return 1;
    } else if (!_stricmp(szMethod, "onClickFinalReward")) {
        MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
        if (spContext.get() != 0) {
            int nDefault = 0;
            int nReceived = g_trCounters.FUN_1409617d0(0x5dc, spContext->m_eventId, &nDefault);
            if (nReceived == 0) {
                COutPacket packet(0x97, 0);
                packet.Encode1(3);
                FUN_140710590(packet);
            }
        }
        return 1;
    } else if (!_stricmp(szMethod, "onClickReward")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nKey = data.FUN_1422b8b10();
            MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
            if (spContext.get() != 0) {
                int nDefault = 0;
                int nTaken = g_trCounters.FUN_1409617d0(0x5dd, spContext->m_eventId, &nDefault);
                int nNext = spContext->GetNextRewardKey(nTaken);
                if (nKey == nNext) {
                    COutPacket packet(0x97, 0);
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

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee2f20
void UITimeRunEventDialog::vfunc_o178_10(void* pQuest)
{
    if (m_30.IsNull()) return;
    if (static_cast<CQuest*>(pQuest)->GetData()->m_350.m_value == 3) {
        MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
        if (!spContext.IsNull()) {
            MS2Ptr<TimeRunEventContext::QuestContext> spQuest(0);
            unsigned nQuest = static_cast<CQuest*>(pQuest)->FUN_140bfc580();
            if (spContext->m_quests.Lookup(nQuest, spQuest)) {
                if (spQuest->m_20 == FUN_140ee4b00())
                    FUN_140ee3c00(spQuest->m_20);
            }
            FUN_140ee3580();
            FUN_140ee4ca0();
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee3100
void UITimeRunEventDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_tick.FUN_140268870(1000)) {
        MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
        if (spContext.IsNull()) {
            vfunc_67();
        } else {
            if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_remainTime"))
                spText->FUN_1422c4cd0(FUN_140ee4380(spContext));
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee3290
int FUN_140ee3290()
{
    MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
    if (spContext.IsNull()) return 0;
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(spQuest->m_questId);
        if (quest.IsNull()) return 0;
        if (quest->GetState() == 3) return 0;
    }
    int nDefault = 0;
    int nReceived = g_trCounters.FUN_1409617d0(0x5dc, spContext->m_eventId, &nDefault);
    if (nReceived == 0) return 1;
    int nDefault2 = 0;
    unsigned nTaken = g_trCounters.FUN_1409617d0(0x5dd, spContext->m_eventId, &nDefault2);
    for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != NULL; spContext->m_rewards.GetNext(pos)) {
        unsigned nKey = spContext->m_rewards.GetKeyAt(pos);
        if (nTaken < nKey) return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee3580
void UITimeRunEventDialog::FUN_140ee3580()
{
    MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
    if (!spContext.IsNull()) {
        unsigned nDistance = FUN_140ee4280(spContext);
        int nDefault = 0;
        unsigned nTaken = g_trCounters.FUN_1409617d0(0x5dd, spContext->m_eventId, &nDefault);
        int nDefault2 = 0;
        int nReceived = g_trCounters.FUN_1409617d0(0x5dc, spContext->m_eventId, &nDefault2);
        unsigned nNext = spContext->GetNextRewardKey(nTaken);
        TimeRunEventContext* pContext = spContext.operator->();
        reinterpret_cast<Unk_TrScript*>(m_30.operator->())->FUN_140acd070("setMapData", pContext->m_1c, nDistance);
        m_mapBinder.FUN_140d43990();
        ASArray rewards(2);
        for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != NULL; spContext->m_rewards.GetNext(pos)) {
            unsigned nKey = spContext->m_rewards.GetKeyAt(pos);
            MS2Ptr<ItemEntity> spItem = spContext->m_rewards.GetValueAt(pos);
            bool bReached = nKey <= nDistance;
            bool bNext = nKey == nNext;
            bool bTaken = nKey < nTaken;
            ASObj row(2);
            row.FUN_1409c0d20("distance", nKey);
            ItemEntity* pItem = spItem.get();
            row.FUN_1407cba60("binding", m_mapBinder.FUN_140d43510(pItem ? static_cast<ItemAble*>(pItem) : 0));
            bool bEnabled;
            if (!bReached || !bNext || bTaken) bEnabled = false; else bEnabled = true;
            row.FUN_1407cbbe0("enabled", bEnabled);
            row.FUN_1407cb9c0("visible", bReached);
            rewards.FUN_1422bbf00(row);
        }
        reinterpret_cast<Unk_TrScript*>(m_30.operator->())->FUN_140eba060("setRewardData", rewards, spContext->m_1c);
        bool bFinal;
        if (nDistance < (unsigned)spContext->m_1c || nReceived != 0) bFinal = false; else bFinal = true;
        TimeRunEventContext* pFinal = spContext.operator->();
        ItemEntity* pFinalItem = &pFinal->m_item;
        CString strBind = m_mapBinder.FUN_140d43510(pFinalItem ? static_cast<ItemAble*>(pFinalItem) : 0);
        reinterpret_cast<Unk_TrScript*>(m_30.operator->())->FUN_140ee5060("setFinalReward", strBind, bFinal);
        if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_totalDistance"))
            spText->FUN_1422c4cd0(FUN_140938ae0(CStringW(L"s_timerun_total_distance"), nDistance));
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee3c00
void UITimeRunEventDialog::FUN_140ee3c00(int nDay)
{
    MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
    if (!spContext.IsNull()) {
        m_missionBinder.FUN_140d43990();
        if (MS2Ptr<Unk_TrList> spList = FUN_140c02900("m_list")) {
            spList->FUN_1422dd1d0();
            for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
                MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
                if (spQuest->m_20 == nDay) {
                    Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(spQuest->m_questId);
                    if (!quest.IsNull()) {
                        if (quest->GetData()->m_complete.m_choiceRewards.GetCount() != 0) {
                            const CQuestData::QuestRewardItem& reward = quest->GetData()->m_complete.m_choiceRewards[0];
                            CStringW strDesc = FUN_1416e5350(quest->FUN_140bfc580(), 0);
                            strDesc.Replace(L"#5c2b00", L"#ffffff");
                            ASObj row(2);
                            row.FUN_1409c0d20("id", spQuest->m_questId);
                            row.FUN_1407cb9c0("completed", quest->IsRewarded());
                            row.FUN_1407cb9c0("satisfied", quest->IsComplete());
                            row.FUN_1407cbb20("label", FUN_140938ae0(CStringW(L"s_timerun_event_distance"), spQuest->m_1c));
                            row.FUN_1407cbb20("desc", CStringW(strDesc));
                            row.FUN_1407cba60("binding", m_missionBinder.FUN_140d43310(reward.m_itemId, reward.m_count, reward.m_job));
                            row.FUN_1409c1180("exp", FUN_140761ba0(spQuest->m_questId, 1));
                            spList->FUN_1422dd230(row);
                        }
                    }
                }
            }
            spList->vfunc_24(true);
        }
    } else {
        vfunc_67();
    }
}

// @0x140ee4280
int UITimeRunEventDialog::FUN_140ee4280(MS2Ptr<TimeRunEventContext> spContext)
{
    int nSum = 0;
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        TimeRunEventContext::QuestContext* pQuest = spQuest.operator->();
        if (FUN_140764020()->FUN_140745590(pQuest->m_questId) != 0)
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
        Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0) {
            nEnd = quest->FUN_1407448a0();
            break;
        }
    }
    CMsTime now(FUN_140869440());
    CMsTime end(nEnd);
    return FormatTimeSpan(end - now, true, true, true, true);
}

// @0x140ee4570
void UITimeRunEventDialog::FUN_140ee4570(int)
{
    FUN_140ee3580();
    Unk_TrDlg* pDlg = FUN_140938b90(0x4e28);
    if (pDlg != 0)
        pDlg->FUN_140ea5f80();
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee45c0
int FUN_140ee45c0()
{
    MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
    if (spContext.IsNull()) return 0;
    int nCount = 0;
    bool bAll = true;
    unsigned nTotal = 0;
    CMsTime now(FUN_140869440());
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0) {
            CMsTime start(quest->GetStartTime());
            AddDays(start, spQuest->m_20 - 1);
            if (FUN_140282020(start) <= FUN_140282020(now)) {
                if (quest->IsComplete() != 0) nCount = nCount + 1;
                if (quest->IsRewarded() == 0) bAll = false; else nTotal += spQuest->m_1c;
            } else {
                bAll = false;
            }
        }
    }
    if (bAll) {
        int nDefault = 0;
        if (g_trCounters.FUN_1409617d0(0x5dc, spContext->m_eventId, &nDefault) == 0) nCount = nCount + 1;
    }
    int nDefault2 = 0;
    unsigned nTaken = g_trCounters.FUN_1409617d0(0x5dd, spContext->m_eventId, &nDefault2);
    for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != NULL; spContext->m_rewards.GetNext(pos)) {
        unsigned nKey = spContext->m_rewards.GetKeyAt(pos);
        if (nKey <= nTotal && nTaken < nKey) {
            nCount = nCount + 1;
            break;
        }
    }
    return nCount;
}

// @0x140ee4990
__int64 UITimeRunEventDialog::FUN_140ee4990(MS2Ptr<TimeRunEventContext> spContext)
{
    for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
        Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(spQuest->m_questId);
        if (quest.get() != 0)
            return quest->GetStartTime();
    }
    return 0;
}

// @0x140ee4b00
int UITimeRunEventDialog::FUN_140ee4b00()
{
    if (MS2Ptr<Unk_TrTab> spTab = FUN_140c02870("m_tab"))
        return spTab->FUN_1422e3210() + 1;
    return -1;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee4bb0
int UITimeRunEventDialog::FUN_140ee4bb0(MS2Ptr<TimeRunEventContext> spContext)
{
    ATL::CTimeSpan span = CMsTime(FUN_140869440()) - CMsTime(FUN_140ee4990(spContext));
    int nDays = (int)span.GetDays();
    int nMax = 6;
    int nResult = (std::min)(nMax, nDays);
    return nResult;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temp/frame layout differs from the exe (not byte-exact)
// @0x140ee4ca0
void UITimeRunEventDialog::FUN_140ee4ca0()
{
    if (!m_30.IsNull()) {
        MS2Ptr<TimeRunEventContext> spContext = FUN_1401c0d90()->FUN_14047d6c0();
        if (!spContext.IsNull()) {
            std::map<int, int> counts;
            for (unsigned __int64 i = 1; i < 8; ++i)
                counts[(int)i] = 0;
            CMsTime now(FUN_140869440());
            for (POSITION pos = spContext->m_quests.GetStartPosition(); pos != NULL; spContext->m_quests.GetNext(pos)) {
                MS2Ptr<TimeRunEventContext::QuestContext> spQuest = spContext->m_quests.GetValueAt(pos);
                Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(spQuest->m_questId);
                if (quest.get() != 0) {
                    CMsTime start(quest->GetStartTime());
                    AddDays(start, spQuest->m_20 - 1);
                    if (FUN_140282020(now) >= FUN_140282020(start)) {
                        if (quest->IsComplete() != 0)
                            counts[spQuest->m_20] = counts[spQuest->m_20] + 1;
                    }
                }
            }
            for (std::map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
                std::pair<const int, int>* pEntry = it.operator->();
                int nTab = it->first - 1;
                reinterpret_cast<Unk_TrScript*>(m_30.operator->())->FUN_1409ba0d0("setTabCount", nTab, pEntry->second);
            }
        }
    }
}

// @0x140ee5060
Scaleform::GFx::Value Unk_TrScript::FUN_140ee5060(const char* szMethod, CString a1, bool a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
