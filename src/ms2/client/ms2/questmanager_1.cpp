// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuest object.
// MS2-UNIT: client\ms2\questmanager.cpp#1
// MS2-RANGE: 0x1416c6210-0x1416c7fd0 .text$mn
// MS2-RANGE: 0x1400fe730-0x1400fe8a0 .text$di
// MS2-RANGE: 0x142cb58b0-0x142cb5990 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VCConditionCommonData@@@@QEAA@H@Z 0x1416c7cf0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\quest.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "questmanager_1.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/questcondition.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// This object's header statics omit the sort-name array in header_statics_a.h.
class Unk_QuestHeaderMap
{
public:
    Unk_QuestHeaderMap(int, float, float, float, int);
    ~Unk_QuestHeaderMap();
    void* m_storage[10];
};
MS2_CHECK_SIZE(Unk_QuestHeaderMap, 0x50);
static CString s_skill = "skill";
static CString s_stun = "stun";
static Unk_QuestHeaderMap s_headerMap(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_accept = "quest_accept";
static CString s_complete = "quest_complete";
static CString s_progress = "quest_progress";
static CString s_reward = "quest_reward";

MS2Ptr<CQuestData> FUN_14074bc40(int);
bool FUN_14064d4e0(const MS2Ptr<CQuestData>&);
int FUN_14074b790(int);
int FUN_14029f3b0(int);
__int64 FUN_140869440();
bool FUN_140930b70();
bool FUN_1409312f0();
extern int DAT_143ab2880;
void FUN_141276180(const CString&, const CString&);
CStringW FUN_1416e4df0(int);
CStringW FUN_1405c2690(CStringW, const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);

void* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(void*);
int FUN_141654700(PCBase*);
int FUN_141658e60(PCBase*);
int FUN_141661c50(PCBase*);
int FUN_141676410(PCBase*);
class Unk_QuestSkill : public CPtred {};
bool FUN_140b02900(const MS2Ptr<Unk_QuestSkill>&);
unsigned FUN_1411dc820(Unk_QuestSkill*);
void* FUN_1416561a0(PCBase*);
void FUN_1411e1ce0(void*, ATL::CAtlList<MS2Ptr<Unk_QuestSkill>>&, int);

// A read-only prefix of the dungeon-room row; no instance is constructed here.
struct Unk_QuestRoom : CPtred {
    unsigned char m_unrecovered[0xe0];
    unsigned m_maxUsers;
};
MS2_CHECK_OFFSET(Unk_QuestRoom, m_maxUsers, 0xf8);
bool FUN_140e36ca0(const MS2Ptr<Unk_QuestRoom>&);
class Unk_QuestRoomTable { public: MS2Ptr<Unk_QuestRoom> FUN_1403206b0(int); };
Unk_QuestRoomTable* FUN_14031c2a0();
void* FUN_140166410();
bool FUN_14036d570(void*, int);

CStringW FUN_1416e5350(int, int);
CStringW FUN_1416e57d0(int, int);
void FUN_14083d2b0(CStringW&);
void FUN_14025a680(const CStringW&, ATL::CAtlArray<CStringW>&, const wchar_t*);
extern const wchar_t DAT_142f5515c[];
class Unk_QuestProgressDialog { public: void FUN_1419f0ef0(const CStringW&, const CString&); };
Unk_QuestProgressDialog* FUN_140931900(int);

class Unk_QuestRewardDialog
{
public:
    void FUN_141abf230(__int64 experience, __int64 bonus);
    void FUN_141abf450(__int64 money, __int64 bonus);
    void FUN_141abf6e0(int item, int count);
};
Unk_QuestRewardDialog* FUN_140938cd0(int);
void* FUN_1401c0d90();
unsigned FUN_14047ea00(void*, int, int, int);
int FUN_14047eb30(void*, int, int, int);
int FUN_1404774a0(void*, int, int);
int FUN_141658f30(PCBase*);
int FUN_14074b070(CQuestData*);
int FUN_14074b050(CQuestData*);
int FUN_140748050(CQuestData::QuestRewardItem*, int);
__int64 FUN_140761ba0(int, int);
__int64 FUN_140761cc0(int, int);
CStringW FUN_14028b8e0(const CStringW&);
void FUN_1412751b0(const CStringW&, int);

// Read-only prefix of the constants singleton. The embedded checked constant's
// accessor (0x1402056b0) validates its initialized flag before returning its value.
class Unk_QuestIntConstant { public: const int& FUN_1402056b0() const; };
struct Unk_QuestConstants {
    unsigned char m_unrecovered[0x59c0];
    Unk_QuestIntConstant m_bonusLevel;
};
MS2_CHECK_OFFSET(Unk_QuestConstants, m_bonusLevel, 0x59c0);
Unk_QuestConstants* FUN_1401d3200();

// @0x1416c6210
CQuest::CQuest() : m_state(3), m_data(0), m_startTime(0), m_completeTime(0),
    m_68(0), m_trackingState(1), m_trackedValue(0) {}

// @0x1416c62e0
CQuest::~CQuest() { m_data = 0; }

// @0x1416c6360
MS2Ptr<CQuestData> CQuest::GetData() { return m_data; }

// @0x1416c63b0
int CQuest::IsComplete() const
{
    if (GetState() != 1) return 0;
    for (size_t i = 0; i < m_progress.FUN_1401b8910(); ++i) {
        if (m_progress.FUN_1401b88c0(i) < m_data->m_conditions.GetAt(i)->m_nGoal) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x1416C6360, CQuest, CQuestCommon, GetData, 65, 0x751C8574);
MS2_REPLACE_METHOD_VIA(0x1416C63B0, CQuest, CQuestCommon, IsComplete, 184, 0xB165BA86);

// @0x1416c6470
int CQuest::IsActive() { return GetState() == 1; }
// @0x1416c64b0
int CQuest::IsRewarded() { return GetState() == 2; }
MS2_REPLACE_METHOD_VIA(0x1416C6470, CQuest, CQuestCommon, IsActive, 58, 0x37339AA1);
// @0x1416c64f0
__int64 CQuest::GetStartTime() { return m_startTime; }
MS2_REPLACE_METHOD_VIA(0x1416C64B0, CQuest, CQuestCommon, IsRewarded, 58, 0x34FA2306);

// MS2-FUNCTIONAL: equivalent initialization with a differently ordered return block.
// @0x1416c6510
int CQuest::Init(int id, int state)
{
    m_data = FUN_14074bc40(id);
    if (!FUN_14064d4e0(m_data)) {
        m_68 = 0;
        m_completeTime = 0;
        m_state = state;
        size_t i = 0;
        while (i < m_data->m_conditions.GetCount()) {
            m_progress.FUN_140280400(0);
            ++i;
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x1416C64F0, CQuest, CQuestCommon, GetStartTime, 15, 0x8B0075C1);
MS2_REPLACE_METHOD(0x1416C6510, CQuest, Init, 247, 0xE7D98F49);

// @0x1416c6610
unsigned char CQuest::GetFlag() { return m_data->m_flag; }
// @0x1416c6640
__int64 CQuest::GetProgress(int index) const
{
    if (index >= (int)m_progress.FUN_1401b8910()) return 0;
    return m_progress.FUN_1401b88c0(index);
}
MS2_REPLACE_METHOD(0x1416C6610, CQuest, GetFlag, 35, 0x7487077B);
MS2_REPLACE_METHOD(0x1416C6640, CQuest, GetProgress, 70, 0xF8DB8031);
// @0x1416c6690
void CQuest::SetProgress(int index, __int64 count)
{
    if (index >= (int)m_progress.FUN_1401b8910()) return;
    m_progress.FUN_1401b7ff0(index) = count;
}
MS2_REPLACE_METHOD(0x1416C6690, CQuest, SetProgress, 78, 0xA488EC14);
// @0x1416c66f0
int CQuest::IsConditionComplete(int index)
{
    if (GetState() != 1) return 0;
    if (index >= (int)m_progress.FUN_1401b8910()) return 0;
    if (index >= (int)m_data->m_conditions.GetCount()) return 0;
    return m_progress.FUN_1401b7ff0(index) >= m_data->m_conditions[index]->m_nGoal;
}
MS2_REPLACE_METHOD(0x1416C66F0, CQuest, IsConditionComplete, 231, 0xDACD67C9);

// No hook: constructs a ConditionUserFindContext with DLL-local RTTI.
// MS2-FUNCTIONAL: typed list traversal and RAII retain all cleanup paths.
// @0x1416c67e0
int CQuest::CheckUserFind(PCBase* actor)
{
    if (actor) {
        PCBase* mine = FUN_141bd0cc0(FUN_1403ed2d0());
        if (mine) {
            ConditionUserFindContext context;
            context.m_job = FUN_141654700(actor);
            context.m_level = (unsigned short)actor->vfunc_78();
            context.m_myKind = FUN_141658e60(mine);
            context.m_targetKind = FUN_141658e60(actor);
            context.m_gender = FUN_141661c50(actor);
            context.m_24 = FUN_141676410(actor);
            ATL::CAtlList<MS2Ptr<Unk_QuestSkill>> skills(10);
            FUN_1411e1ce0(FUN_1416561a0(actor), skills, 0);
            FUN_1411e1ce0(FUN_1416561a0(actor), skills, 1);
            FUN_1411e1ce0(FUN_1416561a0(actor), skills, 2);
            POSITION pos = skills.GetHeadPosition();
            while (pos) {
                MS2Ptr<Unk_QuestSkill> skill(skills.GetAt(pos));
                if (!FUN_140b02900(skill)) context.m_skills.Add(FUN_1411dc820(skill));
                skills.GetNext(pos);
            }
            CQuestConditionCheckerUserFind checker;
            MS2Ptr<CConditionCommonData> unused(0);
            size_t count = m_data->m_conditions.GetCount();
            for (size_t i = 0; i < count; ++i) {
                MS2Ptr<CConditionCommonData> condition(m_data->m_conditions[i]);
                if (!condition.IsNull() && condition->m_nType == 0x11f) {
                    if (checker.Check(condition, &context) == 1) return 1;
                }
            }
        }
    }
    return 0;
}

// @0x1416c6b70
int CQuest::GetTrackingState()
{
    if (FUN_14074b790(FUN_140bfc580()) != 0) return 1;
    return m_trackingState;
}
MS2_REPLACE_METHOD(0x1416C6B70, CQuest, GetTrackingState, 50, 0x24E2DF98);
// @0x1416c6bb0
int CQuest::GetTrackedValue() { return m_trackedValue; }
// @0x1416c6bd0
void CQuest::SetTrackingState(int state) { m_trackingState = state; }
MS2_REPLACE_METHOD(0x1416C6BB0, CQuest, GetTrackedValue, 14, 0x81E2A10F);
// MS2-FUNCTIONAL: byte cast uses a separate local; packet opcode and writes are exact.
// @0x1416c6bf0
void CQuest::RequestTrackingState(int state)
{
    if (FUN_14074b790(FUN_140bfc580()) == 0 && GetTrackingState() != state) {
        COutPacket packet(0x29, 0);
        packet.COutPacket::vfunc_o10_1(9);
        packet.COutPacket::vfunc_o10_3(FUN_140bfc580());
        unsigned char value = (unsigned char)state;
        packet.COutPacket::vfunc_o10_1(value);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1416C6BD0, CQuest, SetTrackingState, 22, 0x0E4CDE77);
MS2_REPLACE_METHOD(0x1416C6BF0, CQuest, RequestTrackingState, 163, 0x6404A25E);
// @0x1416c6ca0
void CQuest::SetTrackedValue(int value) { m_trackedValue = value; }

// MS2-FUNCTIONAL: early returns replace decompiler's shared result temporary.
// @0x1416c6cc0
int CQuest::HasMultiUserRoom(int field)
{
    if (!FUN_14036d570(FUN_140166410(), 0xdc)) return 0;
    if (FUN_1407443e0(field) == 0) return 0;
    int roomId = m_data->m_30c.m_roomId;
    if (roomId == 0) return 0;
    MS2Ptr<Unk_QuestRoom> room = FUN_14031c2a0()->FUN_1403206b0(roomId);
    if (FUN_140e36ca0(room)) return 0;
    return room->m_maxUsers < 2 ? 0 : 1;
}
MS2_REPLACE_METHOD(0x1416C6CA0, CQuest, SetTrackedValue, 22, 0x161CE143);
MS2_REPLACE_METHOD(0x1416C6CC0, CQuest, HasMultiUserRoom, 279, 0xA5783223);

// MS2-FUNCTIONAL: early returns replace the final result temporary.
// @0x1416c6de0
int CQuest::FUN_1407443e0(int field)
{
    if (CQuestCommon::FUN_1407443e0(field) == 0) return 0;
    int id = m_data->m_30c.m_fieldId;
    if (m_data->m_30c.m_roomId != 0 && !FUN_140930b70()) return 0;
    if (id == 0 || id != DAT_143ab2880) return 1;
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x1416C6DE0, CQuest, CQuestCommon, FUN_1407443e0, 148, 0x98F2F50E);
// @0x1416c6e80
int CQuest::FUN_140744670(int field)
{
    if (CQuestCommon::FUN_140744670(field) == 0) return 0;
    return FUN_1409312f0();
}
MS2_REPLACE_METHOD_VIA(0x1416C6E80, CQuest, CQuestCommon, FUN_140744670, 51, 0x2E71EEB5);

// MS2-FUNCTIONAL: named CString assignment temporaries omitted.
// @0x1416c6ec0
void CQuest::ShowProgress(int index)
{
    if (index < (int)m_data->m_conditions.GetCount()) {
        CString category;
        CStringW text;
        int type = GetQuestType();
        if (type == 3) {
            category = "guide";
            text = FUN_1416e5350(FUN_140bfc580(), index);
        } else if (type == 10) {
            category = "wedding";
            text = FUN_1416e5350(FUN_140bfc580(), index);
        } else {
            category = "quest";
            text = FUN_1416e57d0(FUN_140bfc580(), index);
        }
        FUN_14083d2b0(text);
        Unk_QuestProgressDialog* dialog = FUN_140931900(0x4e5f);
        if (dialog) {
            ATL::CAtlArray<CStringW> lines;
            FUN_14025a680(text, lines, DAT_142f5515c);
            if (lines.GetCount() != 0) dialog->FUN_1419f0ef0(lines[0], category);
        }
    }
}
MS2_REPLACE_METHOD(0x1416C6EC0, CQuest, ShowProgress, 609, 0x0BFA9F42);

// @0x1416c7130
void CQuest::PlayAcceptSound()
{
    CString name(m_data->m_2d0.m_accept);
    if (name.GetLength() == 0) name = s_accept;
    FUN_141276180(name, "");
}
MS2_REPLACE_METHOD(0x1416C7130, CQuest, PlayAcceptSound, 152, 0x076016A7);
// MS2-FUNCTIONAL: reference selection and secondary-vtable temporaries differ.
// @0x1416c71d0
void CQuest::PlayProgressSound()
{
    CString empty("");
    const CString& name = IsComplete() ? s_complete : s_progress;
    FUN_141276180(name, empty);
}
MS2_REPLACE_METHOD(0x1416C71D0, CQuest, PlayProgressSound, 143, 0x9CA37571);
// @0x1416c7270
void CQuest::PlayRewardSound()
{
    CString name(m_data->m_2d0.m_reward);
    if (name.GetLength() == 0) name = s_reward;
    FUN_141276180(name, "");
}
MS2_REPLACE_METHOD(0x1416C7270, CQuest, PlayRewardSound, 152, 0x1390298C);

// MS2-FUNCTIONAL: typed reward containers; equivalent float conversions and
// repeated singleton/actor lookups follow the original control flow.
// @0x1416c7310
void CQuest::ShowRewards(int reward)
{
    PCBase* mine = FUN_141bd0cc0(FUN_1403ed2d0());
    if (mine && !FUN_14064d4e0(m_data)) {
        int id = FUN_140bfc580();
        int type = FUN_14074b050(m_data.operator->());
        int subtype = FUN_14074b070(m_data.operator->());
        bool eventBonus = false;
        for (size_t i = 0; i < 8; ++i) {
            if (FUN_14047ea00(FUN_1401c0d90(), type, subtype, (int)i) != 0) {
                eventBonus = true;
                break;
            }
        }
        Unk_QuestRewardDialog* dialog = FUN_140938cd0(0x4e5d);
        if (dialog) {
            CQuestData* data = m_data.operator->();
            int bonusLevel = FUN_1401d3200()->m_bonusLevel.FUN_1402056b0();
            int level = data->m_level;
            __int64 experience = FUN_140761ba0(id, reward);
            if (experience != 0) {
                float multiplier = 0.0f;
                unsigned bonus = FUN_14047ea00(FUN_1401c0d90(), type, subtype, 0);
                if (bonus != 0) multiplier = (float)bonus / 10000.0f;
                __int64 extra = 0;
                if (bonusLevel <= level) {
                    int myLevel = FUN_141658f30(mine);
                    int rate = FUN_1404774a0(FUN_1401c0d90(), 0x31, myLevel);
                    extra = (__int64)((float)experience * ((float)rate / 1000.0f + 1.0f) - (float)experience);
                }
                dialog->FUN_141abf230((__int64)((float)experience * (multiplier + 1.0f)), extra);
            }
            __int64 money = FUN_140761cc0(id, reward);
            if (money != 0) {
                float multiplier = 0.0f;
                unsigned bonus = FUN_14047ea00(FUN_1401c0d90(), type, subtype, 1);
                if (bonus != 0) multiplier = (float)bonus / 10000.0f;
                __int64 extra = 0;
                dialog->FUN_141abf450((__int64)((float)money * (multiplier + 1.0f)), extra);
            }
            if (reward == 0) {
                for (size_t i = 0; i < m_data->m_rewards.size(); ++i) {
                    int item = m_data->m_rewards[i].m_itemId;
                    dialog->FUN_141abf6e0(item, m_data->m_rewards[i].m_count);
                    if (FUN_14047eb30(FUN_1401c0d90(), type, subtype, item) != 0) eventBonus = true;
                }
            } else {
                PCBase* actor = FUN_141bd0cc0(FUN_1403ed2d0());
                if (actor) {
                    for (size_t i = 0; i < m_data->m_complete.m_choiceRewards.GetCount(); ++i) {
                        CQuestData::QuestRewardItem& item = m_data->m_complete.m_choiceRewards[i];
                        if (item.m_itemId != 0) {
                            int job = FUN_141654700(actor);
                            if (FUN_140748050(&item, job) != 0) {
                                int itemId = m_data->m_complete.m_choiceRewards[i].m_itemId;
                                dialog->FUN_141abf6e0(itemId, m_data->m_complete.m_choiceRewards[i].m_count);
                                if (FUN_14047eb30(FUN_1401c0d90(), type, subtype, itemId) != 0) eventBonus = true;
                            }
                        }
                    }
                }
            }
        }
        if (eventBonus && reward != 0)
            FUN_1412751b0(FUN_14028b8e0(L"s_quest_additional_reward_event"), 0x14);
    }
}
MS2_REPLACE_METHOD(0x1416C7310, CQuest, ShowRewards, 1598, 0x3053843A);

// MS2-FUNCTIONAL: secondary stream call temporaries differ; signed read widening preserved.
// @0x1416c7960
void CQuest::DecodeStart(CInPacket& packet)
{
    if (!(m_data == (CQuestData*)0)) {
        unsigned count = packet.vfunc_o8_3();
        for (size_t i = 0; i < count; ++i) {
            int value = packet.vfunc_o8_3();
            SetProgress((int)i, value);
        }
        m_startTime = FUN_140869440();
        ShowRewards(0);
        PlayAcceptSound();
    }
}
MS2_REPLACE_METHOD(0x1416C7960, CQuest, DecodeStart, 237, 0xABC6DCF6);
// MS2-FUNCTIONAL: secondary stream and condition temporaries differ.
// @0x1416c7a60
void CQuest::DecodeProgress(CInPacket& packet)
{
    unsigned count = packet.vfunc_o8_3();
    for (size_t i = 0; i < count; ++i) {
        int value = packet.vfunc_o8_3();
        bool changed = false;
        if (i < m_data->m_conditions.GetCount()) {
            if (FUN_14029f3b0(m_data->m_conditions[i]->m_nType) != 0) {
                changed = value != GetProgress((int)i);
                SetProgress((int)i, value);
            }
            if (changed) ShowProgress((int)i);
        }
    }
    PlayProgressSound();
}
MS2_REPLACE_METHOD(0x1416C7A60, CQuest, DecodeProgress, 354, 0xAA353D3D);
// @0x1416c7bd0
void CQuest::Complete(CInPacket& packet)
{
    if (m_data == (CQuestData*)0) return;
    m_completeTime = FUN_140869440();
    ShowRewards(1);
    PlayRewardSound();
}
MS2_REPLACE_METHOD(0x1416C7BD0, CQuest, Complete, 98, 0x87AAF937);
// @0x1416c7c40
void CQuest::ShowExpired()
{
    FUN_1412751f0(FUN_1405c2690(L"s_quest_expired_auto_giveup", FUN_1416e4df0(FUN_140bfc580())), 1, 1);
}
MS2_REPLACE_METHOD(0x1416C7C40, CQuest, ShowExpired, 176, 0xBA04D5B7);

// @0x1416c7d10
CQuestCommon::CQuestCommon() {}

// @0x1416c7d30
ConditionContext::ConditionContext() {}
// @0x1416c7d50
ConditionUserFindContext::ConditionUserFindContext() : m_user(0), m_level(0),
    m_targetKind(3), m_myKind(3), m_job(0), m_gender(0), m_24(0) {}
// MS2-FUNCTIONAL: defaulted destructor also restores the context vptr before cleanup.
// @0x1416c7df0
ConditionUserFindContext::~ConditionUserFindContext() = default;

MS2_EMIT_CRT_MEMMOVE_S();
