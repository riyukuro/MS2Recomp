// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client side of the dungeon missions: DungeonMissionCli (the
// score earned so far plus a pointer to its DungeonMissionData), DungeonMissionPlayTime / DungeonMissionLimitUserCount /
// DungeonMissionEvent and the 13 counted subclasses of the Event mission. Per class a factory registered by name in the
// dynamic initializers (the registry is the one of commonfiles\dungeonmissiondata.cpp), the name (vfunc_1) and the ctor;
// the implicit dtors and ??_G are COMDATs. The unit name is a guess (queue row ?\dungeonmissioncli.cpp).
// MS2-UNIT: ?\dungeonmissioncli.cpp
// MS2-RANGE: 0x1400c7840-0x1400c7d40 .text$di
// MS2-RANGE: 0x140b1dcf0-0x140b206b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1DungeonMissionCli@@UEAA@XZ 0x140b1fed0 ; unique
// MS2-PIN: ??1DungeonMissionEvent@@UEAA@XZ 0x140b1ff70 ; prop
// MS2-PIN: ??1DungeonMissionLimitUserCount@@UEAA@XZ 0x140b20010 ; prop
// MS2-PIN: ??_GDungeonMissionCli@@UEAAPEAXI@Z 0x140b20150 ; prop
// MS2-PIN: ??_GDungeonMissionEvent@@UEAAPEAXI@Z 0x140b20290 ; prop
// MS2-PIN: ??_GDungeonMissionLimitUserCount@@UEAAPEAXI@Z 0x140b203d0 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_regDamageBySkill@@YAXXZ 0x1400c7840
// MS2-PIN: ??__Es_regDamageCount@@YAXXZ 0x1400c7890
// MS2-PIN: ??__Es_regDamageToNpc@@YAXXZ 0x1400c78e0
// MS2-PIN: ??__Es_regDeathCount@@YAXXZ 0x1400c7930
// MS2-PIN: ??__Es_regEvent@@YAXXZ 0x1400c7980
// MS2-PIN: ??__Es_regGainBuff@@YAXXZ 0x1400c79d0
// MS2-PIN: ??__Es_regHealingPotion@@YAXXZ 0x1400c7a20
// MS2-PIN: ??__Es_regKillNpc@@YAXXZ 0x1400c7a70
// MS2-PIN: ??__Es_regLastHitNpc@@YAXXZ 0x1400c7ac0
// MS2-PIN: ??__Es_regLimitUserCount@@YAXXZ 0x1400c7b10
// MS2-PIN: ??__Es_regPlayTime@@YAXXZ 0x1400c7b60
// MS2-PIN: ??__Es_regTrigger@@YAXXZ 0x1400c7bb0
// MS2-PIN: ??__Es_regUseEp@@YAXXZ 0x1400c7c00
// MS2-PIN: ??__Es_regUseInteractObject@@YAXXZ 0x1400c7c50
// MS2-PIN: ??__Es_regUseSkill@@YAXXZ 0x1400c7ca0
// MS2-PIN: ??__Es_regUseSp@@YAXXZ 0x1400c7cf0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dungeonmissioncli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonmissioncli.h"
#include "ms2/commonfiles/dungeonmissiondatatable.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

// The common log (FUN_140166440()).
class Unk_CommonLog
{
public:
    void FUN_1402804e0(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
Unk_CommonLog* FUN_140166440();

// The packet stream readers (commonfiles\packet.cpp).
CInputStream& FUN_14070f3c0(CInputStream& in, short& value);
CInputStream& FUN_14070f500(CInputStream& in, __int64& value);

// The string table text with two arguments (a key like "s_dungeonMission_ingame_misison_normal").
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registry at DllMain time, before the exe's CRT/locks exist
// Registration of the mission classes by name (dynamic initializers, 0x1400c7840-0x1400c7cf0).
static ClassObjectRegistrar s_regDamageBySkill(L"DungeonMissionDamageBySkill", DungeonMissionDamageBySkill::CreateObject);
static ClassObjectRegistrar s_regDamageCount(L"DungeonMissionDamageCount", DungeonMissionDamageCount::CreateObject);
static ClassObjectRegistrar s_regDamageToNpc(L"DungeonMissionDamageToNpc", DungeonMissionDamageToNpc::CreateObject);
static ClassObjectRegistrar s_regDeathCount(L"DungeonMissionDeathCount", DungeonMissionDeathCount::CreateObject);
static ClassObjectRegistrar s_regEvent(L"DungeonMissionEvent", DungeonMissionEvent::CreateObject);
static ClassObjectRegistrar s_regGainBuff(L"DungeonMissionGainBuff", DungeonMissionGainBuff::CreateObject);
static ClassObjectRegistrar s_regHealingPotion(L"DungeonMissionHealingPotion", DungeonMissionHealingPotion::CreateObject);
static ClassObjectRegistrar s_regKillNpc(L"DungeonMissionKillNpc", DungeonMissionKillNpc::CreateObject);
static ClassObjectRegistrar s_regLastHitNpc(L"DungeonMissionLastHitNpc", DungeonMissionLastHitNpc::CreateObject);
static ClassObjectRegistrar s_regLimitUserCount(L"DungeonMissionLimitUserCount", DungeonMissionLimitUserCount::CreateObject);
static ClassObjectRegistrar s_regPlayTime(L"DungeonMissionPlayTime", DungeonMissionPlayTime::CreateObject);
static ClassObjectRegistrar s_regTrigger(L"DungeonMissionTrigger", DungeonMissionTrigger::CreateObject);
static ClassObjectRegistrar s_regUseEp(L"DungeonMissionUseEp", DungeonMissionUseEp::CreateObject);
static ClassObjectRegistrar s_regUseInteractObject(L"DungeonMissionUseInteractObject", DungeonMissionUseInteractObject::CreateObject);
static ClassObjectRegistrar s_regUseSkill(L"DungeonMissionUseSkill", DungeonMissionUseSkill::CreateObject);
static ClassObjectRegistrar s_regUseSp(L"DungeonMissionUseSp", DungeonMissionUseSp::CreateObject);
#endif

// @0x140b1dcf0
DungeonMissionCli::DungeonMissionCli()
{
    m_score = 0;
}

// @0x140b1dd30
MS2Ptr<DungeonMissionCli> DungeonMissionCli::Create(unsigned nId)
{
    MS2Ptr<DungeonMissionData> pData = DungeonMissionDataTable::GetInstance()->GetMission(nId);
    if (pData == 0)
    {
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, L"DungeonMissionGroup Data Error");
        return MS2Ptr<DungeonMissionCli>(0);
    }
    CStringW strClass = StringFormat(L"DungeonMission{0}", pData->m_type);
    MS2Ptr<DungeonMissionCli> pCli(static_cast<DungeonMissionCli*>(FUN_1401f7f50(strClass)));
    if (pCli == 0)
    {
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, L"DungeonMissionCli NotFound Class");
        return MS2Ptr<DungeonMissionCli>(0);
    }
    pCli->m_data = pData.get();
    return pCli;
}

// @0x140b1df30
void DungeonMissionCli::vfunc_2(CInputStream& in)
{
    FUN_14070f3c0(in, m_score);
}

// @0x140b1df60
void DungeonMissionCli::vfunc_3()
{
}

// @0x140b1df70
CStringW DungeonMissionCli::vfunc_4()
{
    return FUN_14028dfa0(CStringW(L"s_dungeonMission_ingame_misison_normal"), GetName(), L"");
}

// @0x140b1e010
short DungeonMissionCli::GetScore()
{
    return m_score;
}

// @0x140b1e030
short DungeonMissionCli::GetMaxScore()
{
    if (m_data == 0)
        return 0;
    return m_data->m_maxScore;
}

// @0x140b1e060
CStringW DungeonMissionCli::GetName()
{
    if (m_data == 0)
        return L"";
    return m_data->GetName();
}

// @0x140b1e0e0
unsigned DungeonMissionCli::GetId()
{
    if (m_data == 0)
        return 0;
    return m_data->m_id;
}

// @0x140b1e110
bool DungeonMissionCli::IsMaxScore()
{
    if (m_data == 0)
        return false;
    if (m_data->m_applyCount == 0)
        return false;
    if (!m_data->m_isPenaltyType && m_score == m_data->m_maxScore)
        return true;
    return false;
}

// @0x140b1e180
bool DungeonMissionCli::IsPenaltyCleared()
{
    if (m_data == 0)
        return false;
    if (m_data->m_applyCount == 0)
        return false;
    if (m_data->m_applyCount < 0 && m_score == 0)
        return true;
    return false;
}

// @0x140b1e1e0
ClassObject* DungeonMissionPlayTime::CreateObject()
{
    return new DungeonMissionPlayTime;
}

// @0x140b1e240
CStringW DungeonMissionPlayTime::vfunc_1()
{
    return L"DungeonMissionPlayTime";
}

// @0x140b1e290
DungeonMissionPlayTime::DungeonMissionPlayTime()
{
    m_time1 = 0;
    m_time2 = 0;
}

// @0x140b1e2e0
void DungeonMissionPlayTime::vfunc_2(CInputStream& in)
{
    DungeonMissionCli::vfunc_2(in);
    FUN_14070f500(in, m_time1);
    FUN_14070f500(in, m_time2);
}

// @0x140b1e340
ClassObject* DungeonMissionLimitUserCount::CreateObject()
{
    return new DungeonMissionLimitUserCount;
}

// @0x140b1e3a0
CStringW DungeonMissionLimitUserCount::vfunc_1()
{
    return L"DungeonMissionLimitUserCount";
}

// @0x140b1e3f0
DungeonMissionLimitUserCount::DungeonMissionLimitUserCount()
{
}

// @0x140b1e430
ClassObject* DungeonMissionEvent::CreateObject()
{
    return new DungeonMissionEvent;
}

// @0x140b1e490
CStringW DungeonMissionEvent::vfunc_1()
{
    return L"DungeonMissionEvent";
}

// @0x140b1e4e0
DungeonMissionEvent::DungeonMissionEvent()
{
    m_count = 0;
}

// @0x140b1e520
void DungeonMissionEvent::vfunc_2(CInputStream& in)
{
    DungeonMissionCli::vfunc_2(in);
    FUN_14070f3c0(in, m_count);
}

// @0x140b1e560
CStringW DungeonMissionEvent::vfunc_4()
{
    if (m_data->m_isPenaltyType)
    {
        short nTotal = m_data->m_applyCount;
        int nLeft = nTotal - m_count;
        CStringW strCount = StringFormat(L"({0}/{1})", nLeft, nTotal);
        if (m_count >= nTotal)
            return FUN_1408f71a0(L"s_dungeonMission_ingame_misison_fail", GetName(), strCount);
        return FUN_1408f71a0(L"s_dungeonMission_ingame_misison_normal", GetName(), strCount);
    }
    else
    {
        short nTotal = m_data->m_applyCount;
        CStringW strCount = StringFormat(L"({0}/{1})", m_count, nTotal);
        if (m_count >= nTotal)
            return FUN_1408f71a0(L"s_dungeonMission_ingame_misison_success", GetName(), strCount);
        return FUN_1408f71a0(L"s_dungeonMission_ingame_misison_normal", GetName(), strCount);
    }
}

// @0x140b1e8f0
ClassObject* DungeonMissionDeathCount::CreateObject()
{
    return new DungeonMissionDeathCount;
}

// @0x140b1e950
CStringW DungeonMissionDeathCount::vfunc_1()
{
    return L"DungeonMissionDeathCount";
}

// @0x140b1e9a0
ClassObject* DungeonMissionKillNpc::CreateObject()
{
    return new DungeonMissionKillNpc;
}

// @0x140b1ea00
CStringW DungeonMissionKillNpc::vfunc_1()
{
    return L"DungeonMissionKillNpc";
}

// @0x140b1ea50
ClassObject* DungeonMissionHealingPotion::CreateObject()
{
    return new DungeonMissionHealingPotion;
}

// @0x140b1eab0
CStringW DungeonMissionHealingPotion::vfunc_1()
{
    return L"DungeonMissionHealingPotion";
}

// @0x140b1eb00
ClassObject* DungeonMissionDamageBySkill::CreateObject()
{
    return new DungeonMissionDamageBySkill;
}

// @0x140b1eb60
CStringW DungeonMissionDamageBySkill::vfunc_1()
{
    return L"DungeonMissionDamageBySkill";
}

// @0x140b1ebb0
ClassObject* DungeonMissionUseEp::CreateObject()
{
    return new DungeonMissionUseEp;
}

// @0x140b1ec10
CStringW DungeonMissionUseEp::vfunc_1()
{
    return L"DungeonMissionUseEp";
}

// @0x140b1ec60
ClassObject* DungeonMissionUseSp::CreateObject()
{
    return new DungeonMissionUseSp;
}

// @0x140b1ecc0
CStringW DungeonMissionUseSp::vfunc_1()
{
    return L"DungeonMissionUseSp";
}

// @0x140b1ed10
ClassObject* DungeonMissionUseSkill::CreateObject()
{
    return new DungeonMissionUseSkill;
}

// @0x140b1ed70
CStringW DungeonMissionUseSkill::vfunc_1()
{
    return L"DungeonMissionUseSkill";
}

// @0x140b1edc0
ClassObject* DungeonMissionGainBuff::CreateObject()
{
    return new DungeonMissionGainBuff;
}

// @0x140b1ee20
CStringW DungeonMissionGainBuff::vfunc_1()
{
    return L"DungeonMissionGainBuff";
}

// @0x140b1ee70
ClassObject* DungeonMissionLastHitNpc::CreateObject()
{
    return new DungeonMissionLastHitNpc;
}

// @0x140b1eed0
CStringW DungeonMissionLastHitNpc::vfunc_1()
{
    return L"DungeonMissionLastHitNpc";
}

// @0x140b1ef20
ClassObject* DungeonMissionUseInteractObject::CreateObject()
{
    return new DungeonMissionUseInteractObject;
}

// @0x140b1ef80
CStringW DungeonMissionUseInteractObject::vfunc_1()
{
    return L"DungeonMissionUseInteractObject";
}

// @0x140b1efd0
ClassObject* DungeonMissionDamageCount::CreateObject()
{
    return new DungeonMissionDamageCount;
}

// @0x140b1f030
CStringW DungeonMissionDamageCount::vfunc_1()
{
    return L"DungeonMissionDamageCount";
}

// @0x140b1f080
ClassObject* DungeonMissionDamageToNpc::CreateObject()
{
    return new DungeonMissionDamageToNpc;
}

// @0x140b1f0e0
CStringW DungeonMissionDamageToNpc::vfunc_1()
{
    return L"DungeonMissionDamageToNpc";
}

// @0x140b1f130
ClassObject* DungeonMissionTrigger::CreateObject()
{
    return new DungeonMissionTrigger;
}

// @0x140b1f190
CStringW DungeonMissionTrigger::vfunc_1()
{
    return L"DungeonMissionTrigger";
}

// @0x140b1fc30
DungeonMissionDamageBySkill::DungeonMissionDamageBySkill()
{
}

// @0x140b1fc60
DungeonMissionDamageCount::DungeonMissionDamageCount()
{
}

// @0x140b1fc90
DungeonMissionDamageToNpc::DungeonMissionDamageToNpc()
{
}

// @0x140b1fcc0
DungeonMissionDeathCount::DungeonMissionDeathCount()
{
}

// @0x140b1fcf0
DungeonMissionGainBuff::DungeonMissionGainBuff()
{
}

// @0x140b1fd20
DungeonMissionHealingPotion::DungeonMissionHealingPotion()
{
}

// @0x140b1fd50
DungeonMissionKillNpc::DungeonMissionKillNpc()
{
}

// @0x140b1fd80
DungeonMissionLastHitNpc::DungeonMissionLastHitNpc()
{
}

// @0x140b1fdb0
DungeonMissionTrigger::DungeonMissionTrigger()
{
}

// @0x140b1fde0
DungeonMissionUseEp::DungeonMissionUseEp()
{
}

// @0x140b1fe10
DungeonMissionUseInteractObject::DungeonMissionUseInteractObject()
{
}

// @0x140b1fe40
DungeonMissionUseSkill::DungeonMissionUseSkill()
{
}

// @0x140b1fe70
DungeonMissionUseSp::DungeonMissionUseSp()
{
}
