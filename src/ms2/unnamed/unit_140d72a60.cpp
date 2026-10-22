// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuest mission kinds: CDailyMission, CFieldMission, CEventMission,
// CMentoringMission, CWeddingMission, plus the trivial CQuest base virtuals.
// MS2-UNIT: unit_140d72a60
// MS2-FUNCTIONAL: CDailyMission::ShowProgress / CFieldMission::Complete / CWeddingMission::ShowRewards are behaviour-equivalent; the exe range-check branch layout and temp slot order are not reproduced
// MS2-RANGE: 0x1400d3940-0x1400d39c0 .text$di
// MS2-RANGE: 0x140d72a60-0x140d73aa0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1CDailyMission@@UEAA@XZ 0x140d72ab0
// MS2-PIN: ??1CFieldMission@@UEAA@XZ 0x140d72db0
// MS2-PIN: ??1CEventMission@@UEAA@XZ 0x140d730d0
// MS2-PIN: ??1CMentoringMission@@UEAA@XZ 0x140d73490
// MS2-PIN: ??1CWeddingMission@@UEAA@XZ 0x140d735c0
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400d3940
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questkinds.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// A group reward row (only the fields the field mission reads).
class Unk_QmGroupReward {
public:
    char m_pad_00[0x18];
    int m_kind;                                 // +0x18 2 = stat point, 3 = skill point
    int m_point;                                // +0x1c
    char m_pad_20[0x50 - 0x20];
    int m_skillKind;                            // +0x50
};
class Unk_QmGroupRewardPtr {
public:
    ~Unk_QmGroupRewardPtr();                    // 0x14037ea60
    Unk_QmGroupReward* get() const;             // 0x140d73770
    Unk_QmGroupReward* operator->() const;      // 0x14037ebf0
private:
    void* m_0;
    Unk_QmGroupReward* m_p;
};
class Unk_QmGroupTable { public: Unk_QmGroupRewardPtr FUN_14037c3d0(int group); };
Unk_QmGroupTable* FUN_140d738f0();
class CQuestManager;
class Unk_QmGroupSource { public: int FUN_1416d0150(); };
Unk_QmGroupSource* FUN_140764020();

class Unk_QmGameEvent {
public:
    int FUN_1403fd5a0(int questId);
    char m_pad_00[0xa0];
    CStringW m_tag;                             // +0xa0
};
class Unk_QmGameEventRef {
public:
    ~Unk_QmGameEventRef();                      // 0x1403e5510
    bool IsNull() const;                        // 0x1403e84c0
    Unk_QmGameEvent* Get() const;               // 0x1403e8cd0
private:
    void* m_0;
    void* m_p;
};
class Unk_GmEvtKey;
extern Unk_GmEvtKey DAT_143ab2fc0;
class Unk_QmGameEventMgr {
public:
    Unk_QmGameEventRef FUN_14047ca40(const Unk_GmEvtKey& key);
};
Unk_QmGameEventMgr* FUN_1401c0d90();

class Unk_MentorSchedule { public: int FUN_140424f20(int id); };
class Unk_MentorScheduleHolder { public: Unk_MentorSchedule* FUN_14041d160(); };
Unk_MentorScheduleHolder* FUN_140302b00();

UIRewardNotify* FUN_140938cd0(int uiType);
CStringW FUN_14062b4f0(CStringW, const int*);
CStringW GetStringCommonByKey(const CStringW&);
CStringW FUN_1416e4df0(int);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CStringW FUN_140c160b0(CStringW, const __int64*);
void FUN_1412751b0(const CStringW&, int);
void FUN_1412751f0(const CStringW&, int, int);
void* FUN_140c70240();
int FUN_140b71580(void*);

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

// @0x140d72af0
void CDailyMission::ShowProgress(int index)
{
    CQuest::ShowProgress(index);
    if (IsComplete()) {
        CStringW key;
        int grade = m_data->m_338.m_value;
        if (grade > 0 && grade <= 2) key = L"s_recommend_contents_reward_notify_levelup";
        else if (grade > 2 && grade <= 5) key = L"s_recommend_contents_reward_notify_dailymission";
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
        FUN_1412751b0(FUN_14062b4f0(CStringW(L"s_daily_mission_reward_mission_point"), &m_data->m_complete.m_missionPoint), 7);
}

// ---- CFieldMission ----

// @0x140d72d60
CFieldMission::CFieldMission() {}

// @0x140d72df0
void CFieldMission::Complete(CInPacket& packet)
{
    CQuest::Complete(packet);
    int nGroup = FUN_140764020()->FUN_1416d0150();
    Unk_QmGroupRewardPtr row = FUN_140d738f0()->FUN_14037c3d0(nGroup);
    UIRewardNotify* notify;
    if (row.get() != 0 && (notify = FUN_140938cd0(0x4e5d)) != 0 && row.get() != 0) {
        switch (row->m_kind) {
        case 3: {
            notify->FUN_141ac1950(row->m_point, row->m_skillKind);
            CStringW key = L"s_reward_notify_skill_point";
            if (row->m_skillKind == 2) key = L"s_reward_notify_skill_point_sub_1";
            FUN_1412751b0(FUN_14062b4f0(key, &row->m_point), 0x14);
        }
            break;
        case 2:
            notify->FUN_141ac1b50(row->m_point);
            FUN_1412751b0(FUN_14062b4f0(CStringW(L"s_reward_notify_stat_point"), &row->m_point), 0x14);
            break;
        }
    }
}

// ---- CEventMission ----

// @0x140d73080
CEventMission::CEventMission() : m_78(0) {}

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
        Unk_QmGameEventRef ref = FUN_1401c0d90()->FUN_14047ca40(DAT_143ab2fc0);
        if (ref.IsNull()) return;
        int n = ref.Get()->FUN_1403fd5a0(FUN_140bfc580());
        if (n == -1) return;
        UIRewardNotify* notify = FUN_140938cd0(0x4e5d);
        if (notify != 0) {
            CStringW text = FUN_1405c2690(L"s_stampevent_quest_complete", FUN_1416e4df0(FUN_140bfc580()));
            notify->FUN_141ac1730(text, n != 0, ref.Get()->m_tag);
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

// @0x140d734d0
void CMentoringMission::ShowExpired() {}

// @0x140d734e0
int CMentoringMission::FUN_1407447c0()
{
    if (CQuestCommon::FUN_1407447c0()) return 1;
    if (FUN_140302b00()->FUN_14041d160()->FUN_140424f20(FUN_140bfc580()) == 0) return 1;
    if (FUN_140b71580(FUN_140c70240()) != 2) return 1;
    return 0;
}

// ---- CWeddingMission ----

// @0x140d73570
CWeddingMission::CWeddingMission() {}

// @0x140d73600
void CWeddingMission::ShowRewards(int reward)
{
    CQuest::ShowRewards(reward);
    if (reward == 0) return;
    MS2Ptr<CQuestData> data = GetData();
    if (data == 0) return;
    if (data->m_complete.m_weddingExp == 0) return;
    UIRewardNotify* notify = FUN_140938cd0(0x4e5d);
    if (notify != 0) {
        CStringW msg = FUN_140c160b0(CStringW(L"s_system_quest_reward_wedding_exp"), &data->m_complete.m_weddingExp);
        notify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/wedding.png"), msg, 0);
    }
}

// @0x140d73770
Unk_QmGroupReward* Unk_QmGroupRewardPtr::get() const { return m_p; }

// @0x140d738f0
extern void* DAT_143aaec48;
Unk_QmGroupTable* FUN_140d738f0() { return static_cast<Unk_QmGroupTable*>(DAT_143aaec48); }

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
