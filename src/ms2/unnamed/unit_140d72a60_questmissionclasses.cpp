// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuest mission kinds: CDailyMission, CFieldMission, CEventMission,
// CMentoringMission, CWeddingMission, plus the trivial CQuest base virtuals.
// MS2-UNIT: unit_140d72a60
// MS2-FUNCTIONAL: the five mission dtors are implicit here; the exe declares them (vftable stores), which needs a questkinds.h change
// MS2-RANGE: 0x1400d3940-0x1400d39c0 .text$di
// MS2-RANGE: 0x140d72a60-0x140d73aa0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400d3940
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questkinds.h"
#include "ms2/commonfiles/fieldmissiontable.h"   // C3: CFieldMissionTable::GetReward (0x14037c3d0), MS2Ptr<CFieldMissionReward>::get (0x140d73770), GetInstance (0x140d738f0)
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers


// return types of the getters this unit calls
class CMentoringManager;

// ---- unit-local views of exe objects ----

class CQuestManager;
void* FUN_140764020();   // C3: was FUN_140764020

class StampEventContext { public: int GetStampFlag(int); }; class Unk_QmGameEvent : public StampEventContext {
public:

    char m_pad_00[0xa0];
    CStringW m_tag;                             // +0xa0
};
template <> MS2Ptr<StampEventContext>::~MS2Ptr();                 // 0x1403e5510
class Unk_AttendTable;
class GameEventUserValue;
extern GameEventUserValue DAT_143ab2fc0;
class CGameRule {   // C3: member view of gamerule.h's CGameRule
public:
    MS2Ptr<StampEventContext> FUN_14047ca40(Unk_AttendTable& table);
};
void* FUN_1401c0d90();

class Unk_MentorSchedule;
class CGameEventValueMentoring   // C3: member view (the mentoring schedule)
{
public:
    BOOL HasId(unsigned id);   // 0x140424f20
};
class Unk_RuManager { public: class Unk_RuMentoring* GetMentoring(); };   // C3: was Unk_MentorScheduleHolder::FUN_14041d160 (gameeventreturnuser.cpp)

UIRewardNotify* FindRewardNotify(int uiType);
CStringW GetStringCommonByKey(const CStringW&);
CStringW FUN_1416e4df0(int);
void FUN_1412751b0(const CStringW&, int);
void FUN_1412751f0(const CStringW&, int, int);
class CMentoringManager   // C3: member view for the former free stand-ins
{
public:
    unsigned int FUN_140b71580();
};

// ---- CQuest base virtuals ----

// @0x140d738c0
int CQuest::FUN_140d738c0() { return 0; }
// @0x140d738d0
int CQuest::FUN_140d738d0() { return 0; }
// @0x140d738e0
void CQuest::FUN_140d738e0() {}
// @0x140d73950
void CQuest::FUN_140d73950() {}
// @0x140d73960
void CQuest::FUN_140d73960() {}
// @0x140d73970
int CQuest::FUN_140d73970() { return 0; }

// @0x140d73980
MS2_EMIT_CRT_MEMMOVE_S();

// ---- CDailyMission ----

// @0x140d72a60
CDailyMission::CDailyMission() {}

// @0x140d72ab0
CDailyMission::~CDailyMission() {}

// @0x140d72af0
void CDailyMission::ShowProgress(int index)
{
    CQuest::ShowProgress(index);
    if (IsComplete()) {
        CStringW key;
        switch (m_data->m_338.m_value) {
        case 1:
        case 2:
            key = L"s_recommend_contents_reward_notify_levelup";
            break;
        case 3:
        case 4:
        case 5:
            key = L"s_recommend_contents_reward_notify_dailymission";
            break;
        }
        FUN_1412751b0(GetStringCommonByKey(key), 0x14);
    }
}

// @0x140d72c00
void CDailyMission::PlayProgressSound() {}
// @0x140d72c10
void CDailyMission::PlayRewardSound() {}
// @0x140d72c20
void CDailyMission::PlayAcceptSound() {}

// @0x140d72c30
void CDailyMission::ShowExpired()
{
    if (m_data->m_338.m_value == 2) {
    } else CQuest::ShowExpired();
}

// @0x140d72c70
void CDailyMission::Complete(CInPacket& packet)
{
    CQuest::Complete(packet);
    if (m_data->m_338.m_value == 4 || m_data->m_338.m_value == 3)
        FUN_1412751b0(FUN_14028dfa0<int>(CStringW(L"s_daily_mission_reward_mission_point"), m_data->m_complete.m_missionPoint), 7);
}

// ---- CFieldMission ----

// @0x140d72d60
CFieldMission::CFieldMission() {}

// @0x140d72db0
CFieldMission::~CFieldMission() {}

// @0x140d72df0
void CFieldMission::Complete(CInPacket& packet)
{
    CQuest::Complete(packet);
    int nGroup = ((class CQuestManager*)FUN_140764020())->CountCompletedQuests80();
    CFieldMissionTable::RewardPtr row = TSingleton<CFieldMissionTable>::GetInstance()->GetReward(nGroup);
    UIRewardNotify* notify;
    if (row.get() != 0 && (notify = FindRewardNotify(0x4e5d)) != 0 && row.get() != 0) {
        switch (row->m_nType) {
        case 3: {
            notify->FUN_141ac1950(row->m_nValue, row->m_nSubJob);
            CStringW key = L"s_reward_notify_skill_point";
            if (row->m_nSubJob == 2) key = L"s_reward_notify_skill_point_sub_1";
            FUN_1412751b0(FUN_14028dfa0<int>(key, row->m_nValue), 0x14);
        }
            break;
        case 2:
            notify->FUN_141ac1b50(row->m_nValue);
            FUN_1412751b0(FUN_14028dfa0<int>(CStringW(L"s_reward_notify_stat_point"), row->m_nValue), 0x14);
            break;
        }
    }
}

// ---- CEventMission ----

// @0x140d73080
CEventMission::CEventMission() : m_78(0) {}

// @0x140d730d0
CEventMission::~CEventMission() {}

// @0x140d73110
int CEventMission::Init(int id, int state)
{
    if (!CQuest::Init(id, state)) return 0;
    if (m_data.get()) m_78 = m_data->m_350.m_value;
    return 1;
}

// @0x140d73190
void CEventMission::Complete(CInPacket& packet)
{
    CQuest::Complete(packet);
    if (m_78 == 2) {
        MS2Ptr<StampEventContext> ref = reinterpret_cast<CGameRule*>(FUN_1401c0d90())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
        if (ref.IsNull()) return;
        int n = ref->GetStampFlag(FUN_140bfc580());
        if (n == -1) return;
        UIRewardNotify* notify = FindRewardNotify(0x4e5d);
        if (notify != 0) {
            CStringW text = FUN_14028dfa0<CStringW>(L"s_stampevent_quest_complete", FUN_1416e4df0(FUN_140bfc580()));
            notify->FUN_141ac1730(text, n != 0, static_cast<Unk_QmGameEvent*>(ref.operator->())->m_tag);
        }
    }
}

// @0x140d73340
void CEventMission::ShowProgress(int index)
{
    if (m_78 == 1 && IsComplete()) FUN_1412751f0(GetStringCommonByKey(L"s_event_mission_levelpackage_complete"), 3, 1);
}

// @0x140d73400
void CEventMission::PlayProgressSound() {}
// @0x140d73410
void CEventMission::PlayRewardSound() {}
// @0x140d73420
void CEventMission::PlayAcceptSound() {}
// @0x140d73430
void CEventMission::ShowExpired() {}

// ---- CMentoringMission ----

// @0x140d73440
CMentoringMission::CMentoringMission() {}

// @0x140d73490
CMentoringMission::~CMentoringMission() {}

// @0x140d734d0
void CMentoringMission::ShowExpired() {}

// @0x140d734e0
int CMentoringMission::FUN_1407447c0()
{
    if (CQuestCommon::FUN_1407447c0()) return 1;
    if (reinterpret_cast<CGameEventValueMentoring*>(reinterpret_cast<Unk_RuManager*>(TSingleton<CGameEventValueManager>::GetInstance())->GetMentoring())->HasId(FUN_140bfc580()) == 0) return 1;
    if (((class CMentoringManager*)(void*)(TSingleton<CMentoringManager>::GetInstance()))->FUN_140b71580() != 2) return 1;
    return 0;
}

// ---- CWeddingMission ----

// @0x140d73570
CWeddingMission::CWeddingMission() {}

// @0x140d735c0
CWeddingMission::~CWeddingMission() {}

// @0x140d73600
void CWeddingMission::ShowRewards(int reward)
{
    CQuest::ShowRewards(reward);
    if (reward == 0) return;
    MS2Ptr<CQuestData> data = GetData();
    if (data == 0) return;
    if (data->m_complete.m_weddingExp == 0) return;
    UIRewardNotify* notify = FindRewardNotify(0x4e5d);
    if (notify != 0) {
        CStringW msg = FUN_14028dfa0<__int64>(CStringW(L"s_system_quest_reward_wedding_exp"), data->m_complete.m_weddingExp);
        CStringW image = L"./Data/Resource/Image/ETC/wedding.png";
        notify->FUN_141ac1580(image, msg, 0);
    }
}

// ---- quest types ----

// @0x140d73900
int CDailyMission::GetQuestType() { return 3; }
// @0x140d73910
int CEventMission::GetQuestType() { return 5; }
// @0x140d73920
int CFieldMission::GetQuestType() { return 4; }
// @0x140d73930
int CMentoringMission::GetQuestType() { return 7; }
// @0x140d73940
int CWeddingMission::GetQuestType() { return 10; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca54a0-0x142ca54e0 .text$yd
