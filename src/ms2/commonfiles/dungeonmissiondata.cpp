// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dungeon missions of DungeonMission.xml: the
// DungeonMissionData base (score split into applyCount steps) and its per-type subclasses, registered by name in the
// ClassObject factory registry.
// MS2-UNIT: commonfiles\dungeonmissiondata.cpp
// MS2-RANGE: 0x140314830-0x140318c80 .text$mn
// MS2-RANGE: 0x1400b5c30-0x1400b5fa0 .text$di
// The unit name is a guess: the queue row commonfiles\dungeonmatch.cpp (0x1402e6c50-0x14031b800) is four TUs, see
// commonfiles\dungeonmatch.cpp.
// MS2-PIN: ??__Es_regDungeonMissionData@@YAXXZ 0x1400b5c30
// MS2-PIN: ??__Es_regDamageBySkill@@YAXXZ 0x1400b5c80
// MS2-PIN: ??__Es_regDamageToNpc@@YAXXZ 0x1400b5cd0
// MS2-PIN: ??__Es_regGainBuff@@YAXXZ 0x1400b5d20
// MS2-PIN: ??__Es_regKillNpc@@YAXXZ 0x1400b5d70
// MS2-PIN: ??__Es_regLastHitNpc@@YAXXZ 0x1400b5dc0
// MS2-PIN: ??__Es_regLimitUserCount@@YAXXZ 0x1400b5e10
// MS2-PIN: ??__Es_regPlayTime@@YAXXZ 0x1400b5e60
// MS2-PIN: ??__Es_regTrigger@@YAXXZ 0x1400b5eb0
// MS2-PIN: ??__Es_regUseInteractObject@@YAXXZ 0x1400b5f00
// MS2-PIN: ??__Es_regUseSkill@@YAXXZ 0x1400b5f50
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonmissiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonmissiondata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The common log (FUN_140166440()).
class Unk_CommonLog
{
public:
    void FUN_1402804e0(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
Unk_CommonLog* FUN_140166440();

class Unk_StringTable { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_StringTable* FUN_1401a9d70();

int FUN_140873160(Unk_140165cf0* pElem, const char* pszName, short& nOut);

// Clamps v into [lo, hi].
template <class T> T Clamp(const T& v, T lo, T hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registry at DllMain time, before the exe's CRT/locks exist
// Registration of the mission classes by name (dynamic initializers, 0x143aad1e1-0x143aad1eb).
static ClassObjectRegistrar s_regDungeonMissionData(L"DungeonMissionData", DungeonMissionData::CreateObject);
static ClassObjectRegistrar s_regDamageBySkill(L"DungeonMissionDataDamageBySkill", DungeonMissionDataDamageBySkill::CreateObject);
static ClassObjectRegistrar s_regDamageToNpc(L"DungeonMissionDataDamageToNpc", DungeonMissionDataDamageToNpc::CreateObject);
static ClassObjectRegistrar s_regGainBuff(L"DungeonMissionDataGainBuff", DungeonMissionDataGainBuff::CreateObject);
static ClassObjectRegistrar s_regKillNpc(L"DungeonMissionDataKillNpc", DungeonMissionDataKillNpc::CreateObject);
static ClassObjectRegistrar s_regLastHitNpc(L"DungeonMissionDataLastHitNpc", DungeonMissionDataLastHitNpc::CreateObject);
static ClassObjectRegistrar s_regLimitUserCount(L"DungeonMissionDataLimitUserCount", DungeonMissionDataLimitUserCount::CreateObject);
static ClassObjectRegistrar s_regPlayTime(L"DungeonMissionDataPlayTime", DungeonMissionDataPlayTime::CreateObject);
static ClassObjectRegistrar s_regTrigger(L"DungeonMissionDataTrigger", DungeonMissionDataTrigger::CreateObject);
static ClassObjectRegistrar s_regUseInteractObject(L"DungeonMissionDataUseInteractObject", DungeonMissionDataUseInteractObject::CreateObject);
static ClassObjectRegistrar s_regUseSkill(L"DungeonMissionDataUseSkill", DungeonMissionDataUseSkill::CreateObject);
#endif

// ---- DungeonMissionData ----

// @0x140314830
ClassObject* DungeonMissionData::CreateObject()
{
    return new DungeonMissionData;
}
MS2_REPLACE(0x140314830, DungeonMissionData::CreateObject, 82, 0xE38F2F6A);

// @0x140314890
CStringW DungeonMissionData::GetTypeName()
{
    return L"DungeonMissionData";
}
MS2_REPLACE_METHOD(0x140314890, DungeonMissionData, GetTypeName, 61, 0x21FE0D43);

// @0x1403148e0
DungeonMissionData::DungeonMissionData()
    : m_id(0), m_maxScore(0), m_applyCount(1), m_isPenaltyType(false)
{
}

// @0x140314960
bool DungeonMissionData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_id);
    FUN_140873420(pElem, "type", m_type);
    FUN_140873160(pElem, "maxScore", m_maxScore);
    FUN_140873160(pElem, "applyCount", m_applyCount);
    FUN_1408730a0(pElem, "isPenaltyType", m_isPenaltyType);
    if (m_id == 0)
    {
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, StringFormat(L"DungeonMissionData ID Error"));
        return false;
    }
    if (m_applyCount <= 0)
    {
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, StringFormat(L"applyCount must be more 0", m_id));
        return false;
    }
    if (m_applyCount != 0 && m_maxScore % m_applyCount != 0)
    {
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, StringFormat(L"DungeonMissionData Score Division Error ID={0}", m_id));
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140314960, DungeonMissionData, Load, 639, 0x8C65B85D);

// @0x140314bf0
bool DungeonMissionData::vfunc_3()
{
    return false;
}
MS2_REPLACE_METHOD(0x140314BF0, DungeonMissionData, vfunc_3, 8, 0x41132FCD);

// @0x140314c00
unsigned DungeonMissionData::GetId()
{
    return m_id;
}
MS2_REPLACE_METHOD(0x140314C00, DungeonMissionData, GetId, 14, 0x72E52537);

// @0x140314c20
short DungeonMissionData::GetScore(short nCount)
{
    short nUnit = m_maxScore;
    if (m_applyCount > 1)
        nUnit = m_maxScore / m_applyCount;
    short nApplied = Clamp(nCount, (short)0, m_applyCount);
    if (!m_isPenaltyType)
        return Clamp((short)(nUnit * nApplied), (short)0, m_maxScore);
    else
        return Clamp((short)(m_maxScore - nUnit * nApplied), (short)0, m_maxScore);
}
MS2_REPLACE_METHOD(0x140314C20, DungeonMissionData, GetScore, 206, 0x57DDEE0F);

// @0x140314d00
CStringW DungeonMissionData::GetName()
{
    return FUN_1401a9d70()->FUN_141811980(0x3c, m_id);
}
MS2_REPLACE_METHOD(0x140314D00, DungeonMissionData, GetName, 76, 0x106F6DFC);

// @0x140314d60
MS2Ptr<DungeonMissionData> DungeonMissionData::Create(Unk_140165cf0* pElem)
{
    CStringW strType;
    FUN_140873420(pElem, "type", strType);
    if (strType.GetLength() == 0)
        return MS2Ptr<DungeonMissionData>(0);
    CStringW strClass = StringFormat(L"DungeonMissionData{0}", strType);
    MS2Ptr<DungeonMissionData> pData(static_cast<DungeonMissionData*>(FUN_1401f7f50(strClass)));
    if (pData == 0)
        pData.AssignRaw(new DungeonMissionData);
    pData->Load(pElem);
    return pData;
}
MS2_REPLACE(0x140314D60, DungeonMissionData::Create, 428, 0x9E70BA00);

// ---- DungeonMissionDataPlayTime ----

// @0x140314f20
ClassObject* DungeonMissionDataPlayTime::CreateObject()
{
    return new DungeonMissionDataPlayTime;
}
MS2_REPLACE(0x140314F20, DungeonMissionDataPlayTime::CreateObject, 82, 0xA4C5B0CC);

// @0x140314f80
CStringW DungeonMissionDataPlayTime::GetTypeName()
{
    return L"DungeonMissionDataPlayTime";
}
MS2_REPLACE_METHOD(0x140314F80, DungeonMissionDataPlayTime, GetTypeName, 61, 0xFDA50BA5);

// @0x140314fd0
bool DungeonMissionDataPlayTime::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    m_value1 = 0;
    m_value2 = 0;
    FUN_1408731e0(pElem, "value1", m_value1);
    FUN_1408731e0(pElem, "value2", m_value2);
    return true;
}
MS2_REPLACE_METHOD(0x140314FD0, DungeonMissionDataPlayTime, Load, 118, 0x8E0B5B21);

// @0x140315050
bool DungeonMissionDataPlayTime::vfunc_3()
{
    return true;
}
MS2_REPLACE_METHOD(0x140315050, DungeonMissionDataPlayTime, vfunc_3, 8, 0x71679366);

// ---- DungeonMissionDataLimitUserCount ----

// @0x140315060
ClassObject* DungeonMissionDataLimitUserCount::CreateObject()
{
    return new DungeonMissionDataLimitUserCount;
}
MS2_REPLACE(0x140315060, DungeonMissionDataLimitUserCount::CreateObject, 82, 0x856FB269);

// @0x1403150c0
CStringW DungeonMissionDataLimitUserCount::GetTypeName()
{
    return L"DungeonMissionDataLimitUserCount";
}
MS2_REPLACE_METHOD(0x1403150C0, DungeonMissionDataLimitUserCount, GetTypeName, 61, 0x66DC0398);

// @0x140315110
bool DungeonMissionDataLimitUserCount::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    m_value1 = 1;
    FUN_140873220(pElem, "value1", m_value1);
    return true;
}
MS2_REPLACE_METHOD(0x140315110, DungeonMissionDataLimitUserCount, Load, 77, 0xA9BBDACF);

// ---- DungeonMissionDataKillNpc ----

// @0x140315170
ClassObject* DungeonMissionDataKillNpc::CreateObject()
{
    return new DungeonMissionDataKillNpc;
}
MS2_REPLACE(0x140315170, DungeonMissionDataKillNpc::CreateObject, 82, 0x4F7AFDD2);

// @0x1403151d0
CStringW DungeonMissionDataKillNpc::GetTypeName()
{
    return L"DungeonMissionDataKillNpc";
}
MS2_REPLACE_METHOD(0x1403151D0, DungeonMissionDataKillNpc, GetTypeName, 61, 0xA964FE77);

// @0x140315220
bool DungeonMissionDataKillNpc::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    m_value2 = 1;
    XmlTokenList(pElem, "value1", m_value1);
    FUN_140873220(pElem, "value2", m_value2);
    if (m_value2 <= 0)
    {
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, StringFormat(L"DataKillNpc mission value2 is 0"));
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140315220, DungeonMissionDataKillNpc, Load, 224, 0xC2243731);

// ---- DungeonMissionDataDamageBySkill ----

// @0x140315310
ClassObject* DungeonMissionDataDamageBySkill::CreateObject()
{
    return new DungeonMissionDataDamageBySkill;
}
MS2_REPLACE(0x140315310, DungeonMissionDataDamageBySkill::CreateObject, 82, 0x2560158E);

// @0x140315370
CStringW DungeonMissionDataDamageBySkill::GetTypeName()
{
    return L"DungeonMissionDataDamageBySkill";
}
MS2_REPLACE_METHOD(0x140315370, DungeonMissionDataDamageBySkill, GetTypeName, 61, 0x103E837A);

// @0x1403153c0
bool DungeonMissionDataDamageBySkill::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    XmlTokenList(pElem, "value1", m_value1);
    XmlTokenList(pElem, "value2", m_value2);
    return true;
}
MS2_REPLACE_METHOD(0x1403153C0, DungeonMissionDataDamageBySkill, Load, 94, 0xEA7A26CD);

// ---- DungeonMissionDataUseSkill ----

// @0x140315430
ClassObject* DungeonMissionDataUseSkill::CreateObject()
{
    return new DungeonMissionDataUseSkill;
}
MS2_REPLACE(0x140315430, DungeonMissionDataUseSkill::CreateObject, 82, 0x8D444821);

// @0x140315490
CStringW DungeonMissionDataUseSkill::GetTypeName()
{
    return L"DungeonMissionDataUseSkill";
}
MS2_REPLACE_METHOD(0x140315490, DungeonMissionDataUseSkill, GetTypeName, 61, 0x7C1546C6);

// @0x1403154e0
bool DungeonMissionDataUseSkill::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    m_value1 = 0;
    FUN_140873220(pElem, "value1", m_value1);
    return true;
}
MS2_REPLACE_METHOD(0x1403154E0, DungeonMissionDataUseSkill, Load, 77, 0x8847D090);

// ---- DungeonMissionDataGainBuff ----

// @0x140315540
ClassObject* DungeonMissionDataGainBuff::CreateObject()
{
    return new DungeonMissionDataGainBuff;
}
MS2_REPLACE(0x140315540, DungeonMissionDataGainBuff::CreateObject, 82, 0x598AD50F);

// @0x1403155a0
CStringW DungeonMissionDataGainBuff::GetTypeName()
{
    return L"DungeonMissionDataGainBuff";
}
MS2_REPLACE_METHOD(0x1403155A0, DungeonMissionDataGainBuff, GetTypeName, 61, 0xD0D4E531);

// @0x1403155f0
bool DungeonMissionDataGainBuff::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    XmlTokenList(pElem, "value1", m_value1);
    return true;
}
MS2_REPLACE_METHOD(0x1403155F0, DungeonMissionDataGainBuff, Load, 65, 0xC722CD03);

// ---- DungeonMissionDataLastHitNpc ----

// @0x140315640
ClassObject* DungeonMissionDataLastHitNpc::CreateObject()
{
    return new DungeonMissionDataLastHitNpc;
}
MS2_REPLACE(0x140315640, DungeonMissionDataLastHitNpc::CreateObject, 82, 0xE875F467);

// @0x1403156a0
CStringW DungeonMissionDataLastHitNpc::GetTypeName()
{
    return L"DungeonMissionDataLastHitNpc";
}
MS2_REPLACE_METHOD(0x1403156A0, DungeonMissionDataLastHitNpc, GetTypeName, 61, 0xED4B6883);

// @0x1403156f0
bool DungeonMissionDataLastHitNpc::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    XmlTokenList(pElem, "value1", m_value1);
    return true;
}
MS2_REPLACE_METHOD(0x1403156F0, DungeonMissionDataLastHitNpc, Load, 65, 0xD3EBC22A);

// ---- DungeonMissionDataUseInteractObject ----

// @0x140315740
ClassObject* DungeonMissionDataUseInteractObject::CreateObject()
{
    return new DungeonMissionDataUseInteractObject;
}
MS2_REPLACE(0x140315740, DungeonMissionDataUseInteractObject::CreateObject, 82, 0x306434CC);

// @0x1403157a0
CStringW DungeonMissionDataUseInteractObject::GetTypeName()
{
    return L"DungeonMissionDataUseInteractObject";
}
MS2_REPLACE_METHOD(0x1403157A0, DungeonMissionDataUseInteractObject, GetTypeName, 61, 0x4FA969F8);

// @0x1403157f0
bool DungeonMissionDataUseInteractObject::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    m_value1 = 0;
    FUN_1408731e0(pElem, "value1", m_value1);
    return true;
}
MS2_REPLACE_METHOD(0x1403157F0, DungeonMissionDataUseInteractObject, Load, 77, 0x13D665CC);

// ---- DungeonMissionDataDamageToNpc ----

// @0x140315850
ClassObject* DungeonMissionDataDamageToNpc::CreateObject()
{
    return new DungeonMissionDataDamageToNpc;
}
MS2_REPLACE(0x140315850, DungeonMissionDataDamageToNpc::CreateObject, 82, 0x48B9CFF4);

// @0x1403158b0
CStringW DungeonMissionDataDamageToNpc::GetTypeName()
{
    return L"DungeonMissionDataDamageToNpc";
}
MS2_REPLACE_METHOD(0x1403158B0, DungeonMissionDataDamageToNpc, GetTypeName, 61, 0x97C62EB4);

// @0x140315900
bool DungeonMissionDataDamageToNpc::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    FUN_1408732e0(pElem, "value1", m_value1);
    XmlTokenList(pElem, "value2", m_value2);
    m_damagePerApply = m_value1 / m_applyCount;
    return true;
}
MS2_REPLACE_METHOD(0x140315900, DungeonMissionDataDamageToNpc, Load, 137, 0x07D8D8D3);

// @0x140315990
bool DungeonMissionDataDamageToNpc::IsTargetNpc(unsigned nNpcId)
{
    if (m_value2.empty())
        return true;
    return m_value2.find(nNpcId) != m_value2.end();
}
MS2_REPLACE_METHOD(0x140315990, DungeonMissionDataDamageToNpc, IsTargetNpc, 113, 0x792731CA);

// ---- DungeonMissionDataTrigger ----

// @0x140315a10
ClassObject* DungeonMissionDataTrigger::CreateObject()
{
    return new DungeonMissionDataTrigger;
}
MS2_REPLACE(0x140315A10, DungeonMissionDataTrigger::CreateObject, 82, 0xE21F081A);

// @0x140315a70
CStringW DungeonMissionDataTrigger::GetTypeName()
{
    return L"DungeonMissionDataTrigger";
}
MS2_REPLACE_METHOD(0x140315A70, DungeonMissionDataTrigger, GetTypeName, 61, 0xAA071FE5);

// @0x140315ac0
bool DungeonMissionDataTrigger::Load(Unk_140165cf0* pElem)
{
    DungeonMissionData::Load(pElem);
    return true;
}
MS2_REPLACE_METHOD(0x140315AC0, DungeonMissionDataTrigger, Load, 36, 0x6F002DBE);
