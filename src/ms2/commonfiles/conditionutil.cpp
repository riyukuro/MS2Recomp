// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The condition helpers shared by the achievement, quest and
// guild code: CConditionParam (the "code" / "target" attribute of a condition: id list, "a-b" ranges, "a:b" pair or a
// "dict:" dictionary), CConditionCommonData (one parsed <condition> element) and CConditionCommon (its progress
// counter), the condition-type name table (321 entries, built at runtime into two maps), the user-find checker with its
// delegate map, and the ATL / DelegateLib / smart-pointer instances they first used.
// MS2-UNIT: commonfiles\conditionutil.cpp
// MS2-RANGE: 0x14029dff0-0x1402ab440 .text$mn
// MS2-RANGE: 0x1400b57e0-0x1400b59f0 .text$di
// MS2-RANGE: 0x142c9a4c0-0x142c9a590 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Eg_strSkill@@YAXXZ 0x1400b5940 ; prop
// MS2-PIN: ??__Eg_strStun@@YAXXZ 0x1400b5970 ; prop
// MS2-PIN: ??$StringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@@Z 0x1402a5170 ; unique
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@V?$CStringElementTraitsI@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CDefaultCharTraits@D@2@@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@@@UEAAPEAXI@Z 0x1402a5cc0 ; unique
// MS2-PIN: ??_GCConditionCommon@@UEAAPEAXI@Z 0x1402a5d00 ; unique
// MS2-PIN: ??_GCConditionCommonData@@UEAAPEAXI@Z 0x1402a5d40 ; unique
// MS2-PIN: ??_GCConditionDef@CConditionCommon@@UEAAPEAXI@Z 0x1402a5d80 ; unique
// MS2-PIN: ??_GCConditionParam@@UEAAPEAXI@Z 0x1402a5dc0 ; unique
// MS2-PIN: ??_GDelegateBase@DelegateLib@@UEAAPEAXI@Z 0x1402a5ec0 ; unique
// MS2-PIN: ??__Fg_strSkill@@YAXXZ 0x142c9a530 ; unique
// MS2-PIN: ??__Fg_strStun@@YAXXZ 0x142c9a550 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$CAtlMap@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAA@XZ 0x1402aa1d0
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAXXZ 0x1402aafd0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCConditionDef@CConditionCommon@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCConditionDef@CConditionCommon@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1402a66f0
// MS2-PIN: memmove_s 0x1402a8fc0
// MS2-PIN: ??A?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@QEAAAEA_J_K@Z 0x1402a5c10
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\conditionutil.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/questcondition.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <vector>
#include "hook/ms2hook.h"

// ---------------------------------------------------------------------------------------------------------------
// Unrecovered helpers (externs bound by VA).
// ---------------------------------------------------------------------------------------------------------------
class Unk_ConditionXml;
int FUN_1408732e0(Unk_ConditionXml* pNode, const char* pszName, __int64& rValue);          // int64 attribute
int FUN_1408731e0(Unk_ConditionXml* pNode, const char* pszName, int& rValue);              // int attribute
int FUN_1408733e0(Unk_ConditionXml* pNode, const char* pszName, CString& rValue);          // string attribute
CString FUN_14015f710(Unk_ConditionXml* pNode, const char* pszName, CString strDefault);   // string with default
CLogString* GetLogString();                                                                // the log singleton
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);       // split into strings
void FUN_140177de0(const CString& str, ATL::CAtlArray<int>& rOut, const char* pszSep);           // split into ints
void FUN_1401782a0(const CString& str, std::vector<unsigned int>& rOut, const char* pszSep);
void FUN_14015f2b0(CString strBody, CConditionDict* pDict);                                 // "k=v,k=v" into a dictionary
int FUN_140718170(const CString& str);
int FUN_1407181d0(const CString& str);
bool FUN_140718390(const CString& str);

// ---------------------------------------------------------------------------------------------------------------
// Statics (.text$di)
// ---------------------------------------------------------------------------------------------------------------
typedef MS2Ptr<CConditionCommon::CConditionDef> CConditionDefPtr;
typedef ATL::CAtlMap<CString, CConditionDefPtr, ATL::CStringElementTraitsI<CString> > CConditionDefByName;
typedef ATL::CAtlMap<int, CConditionDefPtr> CConditionDefById;

CConditionDefByName g_mapConditionByName;               // 0x143aad000
CConditionDefById g_mapConditionById;                   // 0x143aacfb0
CString g_strStun("stun");                              // 0x143aad050
CString g_strSkill("skill");                            // 0x143aad058
CString g_aStrNames[7] = {CString("None"), CString("Buy"), CString("Like"), CString("PriceLow"),
                          CString("PriceHigh"), CString("Create"), CString("EnumEnd")};   // 0x143aad060
ATL::CAtlMap<unsigned int, CString> g_mapUnknown;       // 0x143aad0a0

__int64 ParseInt64(const CString& str);                                                         // 0x1402a4fe0
void ParseInt64List(CString& str, ATL::CAtlArray<__int64>& rOut, const char* pszSep);        // 0x1402a5010
int FindElement(ATL::CAtlArray<__int64>& rArray, const __int64& rValue);                      // 0x1402a5100

CStringW StringFormat(const wchar_t* format);       // 0x1402a61e0

// ---------------------------------------------------------------------------------------------------------------
// Unk_FieldTimeSpan (declared in fieldmetatable.h)
// ---------------------------------------------------------------------------------------------------------------
// @0x1402a54a0
Unk_FieldTimeSpan::Unk_FieldTimeSpan()
{
    m_nStart = 0;
    m_nEnd = 0;
}

// @0x1402a6bd0
void Unk_FieldTimeSpan::Set(__int64 nStart, __int64 nEnd)
{
    m_nStart = nStart;
    m_nEnd = nEnd;
}

// @0x1402a6f60
bool Unk_FieldTimeSpan::Contains(__int64 nTime) const
{
    if (m_nStart > nTime)
        return false;
    if (m_nEnd < nTime)
        return false;
    return true;
}

// ---------------------------------------------------------------------------------------------------------------
// CConditionParam
// ---------------------------------------------------------------------------------------------------------------
// @0x14029dff0
CConditionParam::CConditionParam()
{
    m_nMin = 0;
    m_nMax = 0;
}

// @0x14029e0a0
CConditionParam::~CConditionParam()
{
}

// @0x14029e120
bool CConditionParam::IsTextDifferent(const CConditionParam& other) const
{
    if (m_strText != other.m_strText)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14029e120, CConditionParam, IsTextDifferent, 58, 0xF4AFF3DD);

// @0x14029e160
int CConditionParam::Parse(CString strText)
{
    m_strText = strText;
    CString strDict("dict:");
    if (m_strText.Left(strDict.GetLength()) == strDict)
    {
        CString strBody = m_strText.Mid(strDict.GetLength());
        m_dict = Unk_FieldNewTag(0);
        FUN_14015f2b0(CString(strBody), m_dict.get());
        m_flags.set(3, true);
        return 1;
    }
    ATL::CAtlArray<CString> items;
    FUN_14015f050(strText, items, ", ");
    for (size_t i = 0; i < items.GetCount(); i++)
    {
        CString strItem(items[i]);
        if (strItem.Find("-", 0) != -1)
        {
            ATL::CAtlArray<int> pair;
            FUN_140177de0(strItem, pair, "-");
            if (pair.GetCount() != 2)
                continue;
            Unk_FieldTimeSpan span;
            span.Set(pair[0], pair[1]);
            m_ranges.Add(span);
            m_flags.set(0);
        }
        else if (strItem.Find(":", 0) != -1)
        {
            ATL::CAtlArray<int> pair;
            FUN_140177de0(strItem, pair, ":");
            if (pair.GetCount() != 2)
                continue;
            m_nMin = pair[0];
            m_nMax = pair[1];
            m_flags.set(2);
        }
        else
        {
            ParseInt64List(strItem, m_ids, ",");
            if (m_ids.GetCount() > 0)
                m_flags.set(1);
        }
    }
    return 1;
}

// @0x14029e600
int CConditionParam::Matches(__int64 nValue)
{
    if (m_flags.test(0))
    {
        for (size_t i = 0; i < m_ranges.GetCount(); i++)
        {
            if (m_ranges.GetAt(i).Contains(nValue))
                return 1;
        }
    }
    if (m_flags.test(1))
        return FindElement(m_ids, nValue) != -1 ? 1 : 0;
    return 0;
}
MS2_REPLACE_METHOD(0x14029e600, CConditionParam, Matches, 226, 0x1AA1E9FB);

// @0x14029e6f0
int CConditionParam::IsSet()
{
    return m_flags.any();
}
MS2_REPLACE_METHOD(0x14029e6f0, CConditionParam, IsSet, 34, 0x3A50CE2A);

// @0x14029e720
size_t CConditionParam::GetIdCount()
{
    if (m_flags.test(1))
        return m_ids.GetCount();
    return 0;
}
MS2_REPLACE_METHOD(0x14029e720, CConditionParam, GetIdCount, 64, 0xAD1ABFBA);

// @0x14029e770
__int64 CConditionParam::GetFirstValue()
{
    if (m_flags.test(0) && m_ranges.GetCount() > 0)
        return m_ranges.GetAt(0).m_nStart;
    if (m_flags.test(1) && m_ids.GetCount() > 0)
        return m_ids[0];
    return 0;
}

// @0x14029e820
CString* CConditionParam::GetText()
{
    return &m_strText;
}
MS2_REPLACE_METHOD(0x14029e820, CConditionParam, GetText, 15, 0x874435E1);

// @0x1402a4fe0
__int64 ParseInt64(const CString& str)
{
    return _atoi64(str);
}

size_t FUN_140280400(ATL::CAtlArray<__int64>* pArray, __int64 nValue);

// @0x1402a5040
static void ParseInt64ListImpl(CString& str, ATL::CAtlArray<__int64>& rOut, const char* pszSep)
{
    int iStart = 0;
    CString strToken = str.Tokenize(pszSep, iStart);
    while (!strToken.IsEmpty())
    {
        // MS2-FUNCTIONAL: CAtlArray<__int64>::Add is called through its exe address (symbols.tsv binds the name to the 16-byte-element Add)
        FUN_140280400(&rOut, ParseInt64(strToken));
        strToken = str.Tokenize(pszSep, iStart);
    }
}

// @0x1402a5010
void ParseInt64List(CString& str, ATL::CAtlArray<__int64>& rOut, const char* pszSep)
{
    ParseInt64ListImpl(str, rOut, pszSep);
}

// @0x1402a5100
int FindElement(ATL::CAtlArray<__int64>& rArray, const __int64& rValue)
{
    for (int i = 0; i < (int)rArray.GetCount(); i++)
    {
        if (rArray[i] == rValue)
            return i;
    }
    return -1;
}

// ---------------------------------------------------------------------------------------------------------------
// Log / format wrappers
// ---------------------------------------------------------------------------------------------------------------
// @0x1402a4c70
template <class T, class U, class V>
inline void Unk_ConditionLog(CLogString* log, unsigned __int64 a, unsigned __int64 b, int category,
                             const wchar_t* format, const T& first, const U& second, const V& third)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(third)};
    log->FUN_1406536f0(a, b, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// @0x1402a61e0
CStringW StringFormat(const wchar_t* format)
{
    return StringFormat(format, fmt::ArgList());
}

// ---------------------------------------------------------------------------------------------------------------
// CConditionCommonData
// ---------------------------------------------------------------------------------------------------------------
// @0x14029e840
CConditionCommonData::CConditionCommonData() : m_nType(0), m_nGoal(1)
{
    m_nPartyCount = 0;
    m_nGuildPartyCount = 0;
}

// @0x14029e8e0
CConditionCommonData::~CConditionCommonData()
{
}

// @0x14029e940
bool CConditionCommonData::IsDifferent(CConditionCommonData* pOther)
{
    if (m_nType != pOther->m_nType)
        return true;
    if (m_nGoal != pOther->m_nGoal)
        return true;
    if (m_code.IsTextDifferent(pOther->m_code))
        return true;
    if (m_target.IsTextDifferent(pOther->m_target))
        return true;
    if (m_nPartyCount != pOther->m_nPartyCount)
        return true;
    if (m_nGuildPartyCount != pOther->m_nGuildPartyCount)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14029e940, CConditionCommonData, IsDifferent, 208, 0x866E65E5);

int ConditionTypeFromName(CString strName);                 // 0x14029f210
int ConditionKindOfType(int nType);                         // 0x14029f2b0
int ConditionHasTarget(int nType);                          // 0x14029f330

// @0x14029ea20
int CConditionCommonData::Load(Unk_ConditionXml* pNode, CStringW strTag, unsigned nId)
{
    CString strType = FUN_14015f710(pNode, "type", CString(""));
    m_nType = ConditionTypeFromName(strType);
    if (m_nType == 0)
        return 0;
    CString strCode;
    CString strTarget;
    FUN_1408732e0(pNode, "value", m_nGoal);
    FUN_1408733e0(pNode, "code", strCode);
    FUN_1408733e0(pNode, "target", strTarget);
    FUN_1408731e0(pNode, "partyCount", m_nPartyCount);
    FUN_1408731e0(pNode, "guildPartyCount", m_nGuildPartyCount);
    if (!strCode.IsEmpty() && strCode != "0")
        m_code.Parse(CString(strCode));
    if (!strTarget.IsEmpty() && strTarget != "0")
        m_target.Parse(CString(strTarget));
    CStringW strError(L"");
    if (!Validate(&strError))
    {
        Unk_ConditionLog(GetLogString(), 0, 0, 0x31, L"{0} {1}. ID:{2} ", strError, strTag, nId);
        return 0;
    }
    return 1;
}

// @0x14029edc0
// MS2-FUNCTIONAL: stack frame/temp layout of the checker + dict pointer differs (26 bytes shorter in the exe); behaviour identical
int CConditionCommonData::Validate(CStringW* pError)
{
    switch (m_nType)
    {
    case 0x11f:
    {
        CQuestConditionCheckerUserFind checker;
        CConditionDictPtr dict(static_cast<const CConditionDictPtr&>(m_target.m_dict));
        if (!dict)
        {
            *pError = StringFormat(L"condition target error. it must be dictionary.");
            return 0;
        }
        for (POSITION pos = dict->GetStartPosition(); pos != NULL; dict->GetNext(pos))
        {
            const CString& strKey = dict->GetKeyAt(pos);
            if (!checker.HasHandler(strKey))
            {
                *pError = StringFormat(L"condition target error. \"{0}\" is invalid.", strKey);
                return 0;
            }
        }
        break;
    }
    }
    return 1;
}

// ---------------------------------------------------------------------------------------------------------------
// CConditionCommon
// ---------------------------------------------------------------------------------------------------------------
// @0x14029efb0
CConditionCommon::CConditionCommon()
{
    m_nCount = 0;
    m_pData = NULL;
}

// @0x14029f000
CConditionCommon::~CConditionCommon()
{
    m_pData = NULL;
}

// @0x14029f040
int CConditionCommon::vfunc_1()
{
    if (m_pData == NULL)
        return 0;
    return m_pData->m_nType;
}
MS2_REPLACE_METHOD(0x14029f040, CConditionCommon, vfunc_1, 34, 0xE3394713);

// @0x14029f070
__int64 CConditionCommon::vfunc_2()
{
    return m_nCount;
}
MS2_REPLACE_METHOD(0x14029f070, CConditionCommon, vfunc_2, 15, 0xBBB219C9);

// @0x14029f090
int CConditionCommon::vfunc_3(CConditionCommonData* pData)
{
    if (pData == NULL)
        return 0;
    if (pData->m_nType == 0)
        return 0;
    m_pData = pData;
    return 1;
}
MS2_REPLACE_METHOD(0x14029f090, CConditionCommon, vfunc_3, 57, 0xB5508924);

// @0x14029f0d0
int CConditionCommon::vfunc_4()
{
    return m_nCount >= m_pData->m_nGoal ? 1 : 0;
}
MS2_REPLACE_METHOD(0x14029f0d0, CConditionCommon, vfunc_4, 57, 0x3D72FF1C);

// @0x14029f110
int CConditionCommon::vfunc_5(__int64 nValue)
{
    if (m_pData == NULL)
        return 0;
    if (!m_pData->m_code.IsSet())
        return 1;
    return m_pData->m_code.Matches(nValue);
}
MS2_REPLACE_METHOD(0x14029f110, CConditionCommon, vfunc_5, 93, 0xB631FC07);

// @0x14029f180
int CConditionCommon::vfunc_6(__int64 nValue)
{
    if (m_pData == NULL)
        return 0;
    if (!m_pData->m_target.IsSet())
        return 1;
    return m_pData->m_target.Matches(nValue);
}
MS2_REPLACE_METHOD(0x14029f180, CConditionCommon, vfunc_6, 97, 0xE2F20767);

// @0x14029f1f0
int CConditionCommon::vfunc_7(__int64 nValue)
{
    return 1;
}
MS2_REPLACE_METHOD(0x14029f1f0, CConditionCommon, vfunc_7, 16, 0x32804D89);

// ---------------------------------------------------------------------------------------------------------------
// Condition type table
// ---------------------------------------------------------------------------------------------------------------
// @0x14029f210
int ConditionTypeFromName(CString strName)
{
    CConditionDefPtr ptr(0);
    if (g_mapConditionByName.Lookup((const char*)strName, ptr))
        return ptr->m_nId;
    return 0;
}

// @0x14029f2b0
int ConditionKindOfType(int nType)
{
    CConditionDefPtr ptr(0);
    if (g_mapConditionById.Lookup(nType, ptr))
        return ptr->m_nKind;
    return -1;
}

// @0x14029f330
int ConditionHasTarget(int nType)
{
    CConditionDefPtr ptr(0);
    if (g_mapConditionById.Lookup(nType, ptr))
        return ptr->m_nTarget;
    return 0;
}

// @0x14029f3b0
int IsConditionTypeCounted(int nType)
{
    switch (nType)
    {
    case 3:
    case 4:
    case 0x49:
    case 0xad:
        return 0;
    default:
        return 1;
    }
}

static void AddCondition(CString strName, int nId, int nKind);          // 0x1402a4a50
static void AddTargetCondition(CString strName, int nId, int nKind);    // 0x1402a4b60

// @0x14029f3f0
void RegisterConditionTypes()
{
    AddTargetCondition(CString("level"), 0x29, 7);
    AddTargetCondition(CString("playtime"), 0x41, 0x11);
    AddTargetCondition(CString("job"), 0x46, 0xc);
    AddTargetCondition(CString("interior_level"), 0xa4, 0x22);
    AddTargetCondition(CString("item_gear_score"), 9, 8);
    AddTargetCondition(CString("mastery_grade"), 0xf8, 0x3b);
    AddTargetCondition(CString("set_mastery_grade"), 0xf9, 0x3b);
    AddTargetCondition(CString("exp"), 0x2b, 7);
    AddTargetCondition(CString("exp_rate"), 0x2c, 7);
    AddTargetCondition(CString("quest"), 0x30, 0xb);
    AddTargetCondition(CString("trophy_point"), 0x5f, 0x16);
    AddTargetCondition(CString("guild_join_req"), 0x86, 0x1e);
    AddCondition(CString("guild_join"), 0x85, 0x1e);
    AddCondition(CString("club_join"), 0x105, 0x3c);
    AddCondition(CString("quest_revise_achieve"), 0x31, 0xb);
    AddCondition(CString("empty"), 1, 0);
    AddCondition(CString("npc"), 0xc, 1);
    AddCondition(CString("npc_lasthit"), 0xf, 2);
    AddCondition(CString("npc_lasthit_buff"), 0x10, 2);
    AddCondition(CString("npc_lasthit_time"), 0x11, 2);
    AddCondition(CString("npc_no_damage"), 0xd, 1);
    AddCondition(CString("npc_timeattack"), 0xe, 1);
    AddCondition(CString("npc_race"), 0x13, 1);
    AddCondition(CString("spawner"), 0x12, 1);
    AddCondition(CString("npc_field_boss"), 0x15, 1);
    AddCondition(CString("npc_field_elite"), 0x16, 1);
    AddCondition(CString("npc_dungeon_boss"), 0x17, 1);
    AddCondition(CString("npc_event_tag"), 0x19, 1);
    AddCondition(CString("dialogue"), 0x1a, 0x27);
    AddCondition(CString("talk_in"), 0x1b, 0x27);
    AddCondition(CString("interact_npc"), 0x1c, 0x27);
    AddCondition(CString("interact_object"), 0x1d, 0x26);
    AddCondition(CString("interact_object_rep"), 0x1e, 0x26);
    AddCondition(CString("breakable_object"), 0x1f, 0x26);
    AddCondition(CString("map"), 0x25, 9);
    AddCondition(CString("explore"), 0x26, 9);
    AddCondition(CString("continent"), 0x27, 9);
    AddCondition(CString("explore_continent"), 0x28, 9);
    AddCondition(CString("item_pickup"), 2, 8);
    AddCondition(CString("item_exist"), 3, 8);
    AddCondition(CString("item_inven"), 4, 8);
    AddCondition(CString("item_break"), 5, 8);
    AddCondition(CString("item_add"), 6, 8);
    AddCondition(CString("item_destroy"), 7, 8);
    AddCondition(CString("item_collect"), 8, 8);
    AddCondition(CString("item_collect_revise"), 10, 8);
    AddCondition(CString("item_collect_script_function"), 0xb, 8);
    AddCondition(CString("donation_item"), 0x119, 0x42);
    AddCondition(CString("donation_type"), 0x11a, 0x42);
    AddCondition(CString("run"), 0x8c, 0xf);
    AddCondition(CString("swim"), 0x8d, 0xf);
    AddCondition(CString("climb"), 0x8e, 0xf);
    AddCondition(CString("glide"), 0x8f, 0xf);
    AddCondition(CString("riding"), 0x90, 0xf);
    AddCondition(CString("crawl"), 0x91, 0xf);
    AddCondition(CString("fall"), 0x92, 0xf);
    AddCondition(CString("holdtime"), 0x93, 0xe);
    AddCondition(CString("ropetime"), 0x94, 0xe);
    AddCondition(CString("laddertime"), 0x95, 0xe);
    AddCondition(CString("emotiontime"), 0x96, 0xe);
    AddCondition(CString("swimtime"), 0x97, 0xe);
    AddCondition(CString("playinstrument_time"), 0x98, 0xe);
    AddCondition(CString("play_ensenble_time"), 0x99, 0xe);
    AddCondition(CString("level_up"), 0x2a, 7);
    AddCondition(CString("quest_clear"), 0x2f, 0xb);
    AddCondition(CString("repeat_quest_clear"), 0x40, 0xb);
    AddCondition(CString("quest_clear_by_chapter"), 0x32, 0xb);
    AddCondition(CString("quest_daily"), 0x33, 0xb);
    AddCondition(CString("quest_guide"), 0x34, 0xb);
    AddCondition(CString("quest_field"), 0x3a, 0xb);
    AddCondition(CString("quest_field_first_clear"), 0x3b, 0xb);
    AddCondition(CString("quest_alliance"), 0x3c, 0xb);
    AddCondition(CString("quest_alliance_by_grade"), 0x3d, 0xb);
    AddCondition(CString("mission_attack_system"), 0x3e, 0xb);
    AddCondition(CString("skyfortress_system"), 0x3f, 0xb);
    AddCondition(CString("field_mission"), 0x36, 0xb);
    AddCondition(CString("stay_map"), 0x42, 0x11);
    AddCondition(CString("survive_map"), 0x43, 0x11);
    AddCondition(CString("job_change"), 0x47, 0xc);
    AddCondition(CString("subjob_change"), 0x48, 0xc);
    AddCondition(CString("meso"), 0x4a, 10);
    AddCondition(CString("meso_donation"), 0x49, 10);
    AddCondition(CString("skill"), 0x55, 0x12);
    AddCondition(CString("taxifind"), 0x59, 0x15);
    AddCondition(CString("taxiuse"), 0x5a, 0x15);
    AddCondition(CString("taxifee"), 0x5b, 0x15);
    AddCondition(CString("best_taxi_use"), 0x5c, 0x15);
    AddCondition(CString("best_taxi_fee"), 0x5d, 0x15);
    AddCondition(CString("hero_achieve_grade"), 0x60, 0x16);
    AddCondition(CString("hero_achieve"), 0x5e, 0x16);
    AddCondition(CString("revise_achieve_single_grade"), 0x61, 0x16);
    AddCondition(CString("revise_achieve_multi_grade"), 0x62, 0x16);
    AddCondition(CString("revival"), 99, 0x18);
    AddCondition(CString("hit_tombstone"), 100, 0x18);
    AddCondition(CString("limited_bundle_buy"), 0x6f, 0x17);
    AddCondition(CString("shop_buy"), 0x65, 0x17);
    AddCondition(CString("shop_sell"), 0x68, 0x17);
    AddCondition(CString("pvp_win"), 0x70, 0x19);
    AddCondition(CString("pvp_kill"), 0x71, 0x19);
    AddCondition(CString("pvp_die"), 0x72, 0x19);
    AddCondition(CString("guildpvp_win"), 0x73, 0x19);
    AddCondition(CString("guildpvp_die"), 0x75, 0x19);
    AddCondition(CString("guildpvp_kill"), 0x74, 0x19);
    AddCondition(CString("shadow_world_kill"), 0x79, 0x1a);
    AddCondition(CString("shadow_world_die"), 0x7a, 0x1a);
    AddCondition(CString("enchant_result"), 0x7b, 0x1b);
    AddCondition(CString("beauty_add"), 0x7c, 0x1c);
    AddCondition(CString("beauty_change"), 0x7d, 0x1c);
    AddCondition(CString("beauty_change_color"), 0x7e, 0x1c);
    AddCondition(CString("beauty_random"), 0x7f, 0x1c);
    AddCondition(CString("beauty_style_add"), 0x80, 0x1c);
    AddCondition(CString("beauty_style_apply"), 0x81, 0x1c);
    AddCondition(CString("trigger"), 0x82, 0x1d);
    AddCondition(CString("minigame_clear"), 0x83, 0x1d);
    AddCondition(CString("useropen_minigame_clear"), 0x84, 0x1d);
    AddCondition(CString("emotion"), 0x9a, 0x1f);
    AddCondition(CString("couple_dance_event"), 0x9b, 0x1f);
    AddCondition(CString("item_move"), 0x9c, 0x28);
    AddCondition(CString("buy_house"), 0x9d, 0x28);
    AddCondition(CString("buy_cube"), 0xa7, 0x28);
    AddCondition(CString("create_blueprint"), 0xa8, 0x28);
    AddCondition(CString("send_mail"), 0xa9, 0x20);
    AddCondition(CString("resolve_panelty"), 0xaa, 0x21);
    AddCondition(CString("equip_exist"), 0xad, 0xd);
    AddCondition(CString("change_equip"), 0xab, 0xd);
    AddCondition(CString("change_ugc_equip"), 0xac, 0xd);
    AddCondition(CString("change_profile"), 0xae, 0x22);
    AddCondition(CString("fall_survive"), 0xb5, 0x23);
    AddCondition(CString("fall_die"), 0xb6, 0x23);
    AddCondition(CString("fall_damage"), 0xb7, 0x23);
    AddCondition(CString("attendance"), 0xb8, 0x29);
    AddCondition(CString("dungeon_key_use"), 0xb9, 0x2a);
    AddCondition(CString("dungeon_reward"), 0xba, 0x2a);
    AddCondition(CString("dungeon_reward_group"), 0xbb, 0x2a);
    AddCondition(CString("dungeon_random_bonus"), 0xbc, 0x2a);
    AddCondition(CString("dungeon_help_beginner"), 0xbd, 0x2a);
    AddCondition(CString("dungeon_help_beginner_helper"), 0xbe, 0x2a);
    AddCondition(CString("dungeon_help_beginner_helpee"), 0xbf, 0x2a);
    AddCondition(CString("dungeon_rank"), 0xc2, 0x2a);
    AddCondition(CString("dungeon_rank_clear"), 0xc1, 0x2a);
    AddCondition(CString("dungeon_rank_clear_group"), 0xc0, 0x2a);
    AddCondition(CString("dungeon_clear"), 0xc3, 0x2a);
    AddCondition(CString("dungeon_clear_group"), 0xc4, 0x2a);
    AddCondition(CString("dungeon_first_clear"), 0xc5, 0x2a);
    AddCondition(CString("dungeon_round_clear"), 0xc6, 0x2a);
    AddCondition(CString("extend_house"), 0x9e, 0x28);
    AddCondition(CString("install_item"), 0x9f, 0x28);
    AddCondition(CString("uninstall_item"), 0xa0, 0x28);
    AddCondition(CString("vibrate_object"), 0x20, 0x26);
    AddCondition(CString("buff"), 0x58, 0x13);
    AddCondition(CString("skill_die"), 0x56, 0x12);
    AddCondition(CString("skill_damage_npc"), 0x57, 0x12);
    AddCondition(CString("banner"), 0xaf, 0x22);
    AddCondition(CString("controller"), 0x21, 0x26);
    AddCondition(CString("controller_mine"), 0x22, 0x26);
    AddCondition(CString("controller_other"), 0x23, 0x26);
    AddCondition(CString("splash_plant"), 0x24, 0x26);
    AddCondition(CString("killcount"), 0x14, 3);
    AddCondition(CString("maid_get_item"), 199, 0x2b);
    AddCondition(CString("maid_salary"), 200, 0x2b);
    AddCondition(CString("maid_jackpot"), 0xc9, 0x2b);
    AddCondition(CString("maid_affinity"), 0xca, 0x2b);
    AddCondition(CString("maid_profile"), 0xcb, 0x2b);
    AddCondition(CString("jump"), 0xcc, 0x10);
    AddCondition(CString("stay_cube"), 0x44, 0x11);
    AddCondition(CString("survive_cube"), 0x45, 0x11);
    AddCondition(CString("npc_assist_bonus"), 0x18, 4);
    AddCondition(CString("get_karma_token"), 0x4b, 10);
    AddCondition(CString("get_honor_token"), 0x4c, 10);
    AddCondition(CString("get_lu_token"), 0x4d, 10);
    AddCondition(CString("get_habi_token"), 0x4e, 10);
    AddCondition(CString("get_reverse_coin"), 0x50, 10);
    AddCondition(CString("get_mentor_token"), 0x51, 10);
    AddCondition(CString("get_mentee_token"), 0x52, 10);
    AddCondition(CString("get_star_point"), 0x53, 10);
    AddCondition(CString("use_merat"), 0x54, 10);
    AddCondition(CString("shop_buy_karma_token"), 0x66, 0x17);
    AddCondition(CString("shop_buy_honor_token"), 0x67, 0x17);
    AddCondition(CString("shop_buy_lu_token"), 0x69, 0x17);
    AddCondition(CString("shop_buy_habi_token"), 0x6a, 0x17);
    AddCondition(CString("shop_buy_reverse_coin"), 0x6b, 0x17);
    AddCondition(CString("shop_buy_mentro_token"), 0x6c, 0x17);
    AddCondition(CString("shop_buy_mentee_token"), 0x6d, 0x17);
    AddCondition(CString("shop_buy_star_point"), 0x6e, 0x17);
    AddCondition(CString("guild_championship"), 0x87, 0x1e);
    AddCondition(CString("pvp_win_score"), 0x76, 0x19);
    AddCondition(CString("pvp_win_time"), 0x77, 0x19);
    AddCondition(CString("commend_home"), 0xb0, 0x22);
    AddCondition(CString("pvp_participation"), 0x78, 0x19);
    AddCondition(CString("fish"), 0xcd, 0x2d);
    AddCondition(CString("fish_success_bait"), 0xce, 0x2d);
    AddCondition(CString("fish_fail"), 0xcf, 0x2d);
    AddCondition(CString("fish_big"), 0xd0, 0x2d);
    AddCondition(CString("fish_goldmedal"), 0xd2, 0x2d);
    AddCondition(CString("fish_collect"), 0xd1, 0x2d);
    AddCondition(CString("music_play_score"), 0xd4, 0x2e);
    AddCondition(CString("music_play_score_by_name"), 0xd5, 0x2e);
    AddCondition(CString("music_play_score_time"), 0xd6, 0x2e);
    AddCondition(CString("music_play_ensemble"), 0xd9, 0x2e);
    AddCondition(CString("music_play_ensemble_in"), 0xda, 0x2e);
    AddCondition(CString("openStoryBook"), 0xdd, 0x2f);
    AddCondition(CString("openItemBox"), 0xdc, 0x2f);
    AddCondition(CString("festival_event"), 0xde, 0x2f);
    AddCondition(CString("install_billboard"), 0xdf, 0x2f);
    AddCondition(CString("auto_fishing"), 0xd3, 0x2d);
    AddCondition(CString("smart_push"), 0xe0, 0x35);
    AddCondition(CString("item_remake_option"), 0xe1, 0x37);
    AddCondition(CString("pet_remake_option"), 0xe3, 0x37);
    AddCondition(CString("pet_remake_option_record"), 0xe4, 0x37);
    AddCondition(CString("pvp_win_with_buff"), 0xe5, 0x19);
    AddCondition(CString("pvp_win_with_grade"), 0xe6, 0x19);
    AddCondition(CString("pvp_win_perfect"), 0xe7, 0x19);
    AddCondition(CString("guild_exp"), 0x88, 0x1e);
    AddCondition(CString("guild_attendance"), 0x8a, 0x1e);
    AddCondition(CString("guild_donate"), 0x8b, 0x1e);
    AddCondition(CString("gemstone_upgrade"), 0xe8, 0x38);
    AddCondition(CString("gemstone_upgrade_try"), 0xeb, 0x38);
    AddCondition(CString("gemstone_puton"), 0xec, 0x38);
    AddCondition(CString("gemstone_putoff"), 0xed, 0x38);
    AddCondition(CString("socket_unlock"), 0xf2, 0x38);
    AddCondition(CString("socket_unlock_fail"), 0xf4, 0x38);
    AddCondition(CString("socket_unlock_try"), 0xf5, 0x38);
    AddCondition(CString("home_doctor"), 0xb1, 0x22);
    AddCondition(CString("home_bank"), 0xb2, 0x22);
    AddCondition(CString("home_goto"), 0xb3, 0x22);
    AddCondition(CString("item_design"), 0xb4, 0x22);
    AddCondition(CString("fisher_grade"), 0xfb, 0x3b);
    AddCondition(CString("music_play_grade"), 0xfa, 0x3b);
    AddCondition(CString("mastery_harvest"), 0xfc, 0x3b);
    AddCondition(CString("mastery_harvest_try"), 0xfd, 0x3b);
    AddCondition(CString("mastery_manufacturing"), 0x100, 0x3b);
    AddCondition(CString("mastery_farming"), 0x101, 0x3b);
    AddCondition(CString("mastery_farming_try"), 0x102, 0x3b);
    AddCondition(CString("mastery_gathering"), 0x103, 0x3b);
    AddCondition(CString("mastery_gathering_try"), 0x104, 0x3b);
    AddCondition(CString("mastery_harvest_otherhouse"), 0xfe, 0x3b);
    AddCondition(CString("mastery_harvest_guildhouse"), 0xff, 0x3b);
    AddCondition(CString("rotate_cube"), 0xa1, 0x28);
    AddCondition(CString("quest_accept"), 0x35, 0xb);
    AddCondition(CString("interior_exp"), 0xa2, 0x22);
    AddCondition(CString("interior_exp_offset"), 0xa3, 0x22);
    AddCondition(CString("interior_point"), 0xa5, 0x22);
    AddCondition(CString("enter_otherhouse"), 0xa6, 0x22);
    AddCondition(CString("guild_trophy"), 0x89, 0x1e);
    AddCondition(CString("skin_gemstone_puton"), 0xee, 0x38);
    AddCondition(CString("skin_gemstone_putoff"), 0xef, 0x38);
    AddCondition(CString("equip_gemstone_puton"), 0xf0, 0x38);
    AddCondition(CString("equip_gemstone_putoff"), 0xf1, 0x38);
    AddCondition(CString("guild_trigger"), 0x108, 0x1d);
    AddCondition(CString("pet_collect"), 0x109, 0x3e);
    AddCondition(CString("pet_first_collect"), 0x10a, 0x3e);
    AddCondition(CString("pet_enchant"), 0x10b, 0x3e);
    AddCondition(CString("pet_enchant_exp"), 0x10c, 0x3e);
    AddCondition(CString("pet_taming"), 0x10d, 0x3e);
    AddCondition(CString("pet_catch_id"), 0x110, 0x3e);
    AddCondition(CString("pet_catch_grade"), 0x10f, 0x3e);
    AddCondition(CString("pet_catch_category"), 0x10e, 0x3e);
    AddCondition(CString("pet_evolution_point_by_rank"), 0x111, 0x3e);
    AddCondition(CString("pet_evolution_by_rank"), 0x112, 0x3e);
    AddCondition(CString("buddy_request"), 0x106, 0x3c);
    AddCondition(CString("chat"), 0x107, 0x3c);
    AddCondition(CString("socket_unlock_success"), 0xf3, 0x38);
    AddCondition(CString("music_play_instrument_time"), 0xd7, 0x2e);
    AddCondition(CString("music_play_instrument_mastery"), 0xd8, 0x2e);
    AddCondition(CString("music_concert_cheer_up"), 0xdb, 0x2e);
    AddCondition(CString("item_remake_option_record"), 0xe2, 0x37);
    AddCondition(CString("gemstone_upgrade_success"), 0xe9, 0x38);
    AddCondition(CString("gemstone_upgrade_fail"), 0xea, 0x38);
    AddCondition(CString("character_ability_learn"), 0xf6, 0x39);
    AddCondition(CString("character_ability_reset"), 0xf7, 0x39);
    AddCondition(CString("game_helper_service"), 0x113, 0x34);
    AddCondition(CString("item_merge_success"), 0x118, 0x3f);
    AddCondition(CString("mission_point"), 0x37, 0xb);
    AddCondition(CString("fame_point"), 0x38, 0xb);
    AddCondition(CString("fame_grade"), 0x39, 0xb);
    AddCondition(CString("idip_app_attendance"), 0x114, 0x40);
    AddCondition(CString("idip_live_broadcast"), 0x115, 0x40);
    AddCondition(CString("idip_adventure_bar"), 0x116, 0x40);
    AddCondition(CString("vipgm"), 0x117, 0x41);
    AddCondition(CString("play_rps"), 0x11b, 0x43);
    AddCondition(CString("play_rps_win"), 0x11c, 0x43);
    AddCondition(CString("play_rps_lose"), 0x11d, 0x43);
    AddCondition(CString("play_rps_draw"), 0x11e, 0x43);
    AddCondition(CString("user_find"), 0x11f, 0x44);
    AddCondition(CString("survival_enter"), 0x120, 0x45);
    AddCondition(CString("survival_kill"), 0x121, 0x45);
    AddCondition(CString("survival_kill_outside"), 0x122, 0x45);
    AddCondition(CString("survival_kill_use_skill"), 0x123, 0x45);
    AddCondition(CString("survival_double_kill"), 0x126, 0x45);
    AddCondition(CString("survival_win_without_interact"), 0x127, 0x45);
    AddCondition(CString("survival_win_without_npckill"), 0x128, 0x45);
    AddCondition(CString("survival_win_use_one_skill"), 0x129, 0x45);
    AddCondition(CString("survival_total_kill_use_skill"), 0x124, 0x45);
    AddCondition(CString("survival_total_kill_use_single_skill"), 0x125, 0x45);
    AddCondition(CString("survival_rank_with_kill"), 0x12a, 0x45);
    AddCondition(CString("survival_breakable_object"), 299, 0x45);
    AddCondition(CString("survival_npc_kill"), 300, 0x45);
    AddCondition(CString("survival_item_get"), 0x12d, 0x45);
    AddCondition(CString("survival_buy_gold_pass"), 0x12e, 0x45);
    AddCondition(CString("adventure_level"), 0x2d, 7);
    AddCondition(CString("adventure_level_up"), 0x2e, 7);
    AddCondition(CString("worldchampion_hit"), 0x12f, 0x46);
    AddCondition(CString("worldchampion_damage"), 0x130, 0x46);
    AddCondition(CString("worldchampion_reward"), 0x131, 0x46);
    AddCondition(CString("nurturing_play"), 0x132, 0x26);
    AddCondition(CString("nurturing_eat"), 0x133, 0x26);
    AddCondition(CString("nurturing_growth"), 0x134, 0x26);
    AddCondition(CString("lapenshard_upgrade_try"), 0x135, 0x47);
    AddCondition(CString("lapenshard_upgrade_fail"), 0x136, 0x47);
    AddCondition(CString("lapenshard_upgrade_success"), 0x137, 0x47);
    AddCondition(CString("lapenshard_upgrade_result"), 0x138, 0x47);
    AddCondition(CString("wedding_propose"), 0x139, 0x48);
    AddCondition(CString("wedding_propose_decline"), 0x13a, 0x48);
    AddCondition(CString("wedding_propose_declined"), 0x13b, 0x48);
    AddCondition(CString("wedding_hall_reserve"), 0x13c, 0x48);
    AddCondition(CString("wedding_hall_change"), 0x13d, 0x48);
    AddCondition(CString("wedding_hall_cancel"), 0x13e, 0x48);
    AddCondition(CString("wedding_guest"), 0x13f, 0x48);
    AddCondition(CString("wedding_divorce"), 0x140, 0x48);
    AddCondition(CString("wedding_complete"), 0x141, 0x48);
    AddCondition(CString("unlimited_enchant"), 0x142, 0x1b);
}

// @0x1402a4a50
static void AddCondition(CString strName, int nId, int nKind)
{
    CConditionDefPtr ptr(new CConditionCommon::CConditionDef);
    ptr->m_strName = strName;
    ptr->m_nId = nId;
    ptr->m_nKind = nKind;
    ptr->m_nTarget = 0;
    g_mapConditionByName.SetAt((const char*)strName, ptr);
    g_mapConditionById.SetAt(nId, ptr);
}

// @0x1402a4b60
static void AddTargetCondition(CString strName, int nId, int nKind)
{
    CConditionDefPtr ptr(new CConditionCommon::CConditionDef);
    ptr->m_strName = strName;
    ptr->m_nId = nId;
    ptr->m_nKind = nKind;
    ptr->m_nTarget = 1;
    g_mapConditionByName.SetAt((const char*)strName, ptr);
    g_mapConditionById.SetAt(nId, ptr);
}

// @0x1402a5630
CConditionCommon::CConditionDef::CConditionDef() : m_nId(0), m_nKind(0), m_nTarget(0)
{
}

// ---------------------------------------------------------------------------------------------------------------
// Condition checkers
// ---------------------------------------------------------------------------------------------------------------
// @0x1402a90e0
int ConditionUserFindContext::FUN_1402a90e0()
{
    return 0x11f;
}

// @0x1402aa160
CQuestConditionChecker::CQuestConditionChecker()
{
}

// @0x1402a6b80
int CQuestConditionCheckerUserFind::HasHandler(const CString& strKey)
{
    return m_handlers.Lookup((const char*)strKey) != NULL ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1402a6b80, CQuestConditionCheckerUserFind, HasHandler, 74, 0xD35CC63A);

// @0x1402a9100
// MS2-FUNCTIONAL: the exe inlines the delegate temps differently (19 bytes longer); behaviour identical
CQuestConditionCheckerUserFind::CQuestConditionCheckerUserFind()
{
    m_handlers["jobId"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckJobId);
    m_handlers["level"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckLevel);
    m_handlers["gender"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckGender);
    m_handlers["equipItemIds"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckEquipItemsAnd);
    m_handlers["equipItemIdsAnd"] =
        DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckEquipItemsAnd);
    m_handlers["equipItemIdsOr"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckEquipItemsOr);
    m_handlers["titleId"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckTitleId);
    m_handlers["rideeId"] = DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckRideeId);
    m_handlers["oppositeGender"] =
        DelegateLib::MakeDelegate(this, &CQuestConditionCheckerUserFind::CheckOppositeGender);
}

// @0x1402a9ca0
static bool ContainsId(ATL::CAtlArray<unsigned>& rIds, unsigned nId)
{
    if (rIds.GetCount() == 0)
        return false;
    for (unsigned i = 0; i < rIds.GetCount(); i++)
    {
        if (rIds[i] == nId)
            return true;
    }
    return false;
}

// @0x1402a9540
bool CQuestConditionCheckerUserFind::CheckJobId(const CString& strValue, ConditionUserFindContext* pContext)
{
    int nJob = FUN_140718170(strValue);
    return nJob == pContext->m_job;
}
MS2_REPLACE_METHOD(0x1402a9540, CQuestConditionCheckerUserFind, CheckJobId, 75, 0xE789F5D7);

// @0x1402a95a0
bool CQuestConditionCheckerUserFind::CheckLevel(const CString& strValue, ConditionUserFindContext* pContext)
{
    ATL::CAtlArray<int> range;
    FUN_140177de0(strValue, range, " ");
    if (range.GetCount() != 2)
    {
        MS2_ASSERT_AT(0x5c, 0);
        return false;
    }
    return pContext->m_level >= range[0] && pContext->m_level <= range[1];
}
MS2_REPLACE_METHOD(0x1402a95a0, CQuestConditionCheckerUserFind, CheckLevel, 255, 0x0118F4D2);

// @0x1402a96b0
bool CQuestConditionCheckerUserFind::CheckGender(const CString& strValue, ConditionUserFindContext* pContext)
{
    int nGender = FUN_140718170(strValue);
    if (nGender == 2)
        return true;
    return nGender == pContext->m_targetKind;
}
MS2_REPLACE_METHOD(0x1402a96b0, CQuestConditionCheckerUserFind, CheckGender, 86, 0x4189B854);

// @0x1402a9710
// MS2-FUNCTIONAL: exe iterates the std::vector with class iterators and a different frame; behaviour identical
bool CQuestConditionCheckerUserFind::CheckEquipItemsAnd(const CString& strValue, ConditionUserFindContext* pContext)
{
    std::vector<unsigned int> ids;
    FUN_1401782a0(strValue, ids, " ");
    for (unsigned int nId : ids)
    {
        if (!ContainsId(pContext->m_skills, nId))
            return false;
    }
    return true;
}

// @0x1402a9810
// MS2-FUNCTIONAL: exe iterates the std::vector with class iterators and a different frame; behaviour identical
bool CQuestConditionCheckerUserFind::CheckEquipItemsOr(const CString& strValue, ConditionUserFindContext* pContext)
{
    std::vector<unsigned int> ids;
    FUN_1401782a0(strValue, ids, " ");
    for (unsigned int nId : ids)
    {
        if (ContainsId(pContext->m_skills, nId))
            return true;
    }
    return false;
}

// @0x1402a9910
bool CQuestConditionCheckerUserFind::CheckTitleId(const CString& strValue, ConditionUserFindContext* pContext)
{
    int nTitle = FUN_1407181d0(strValue);
    return nTitle == pContext->m_gender;
}
MS2_REPLACE_METHOD(0x1402a9910, CQuestConditionCheckerUserFind, CheckTitleId, 75, 0x132DA8BF);

// @0x1402a9970
bool CQuestConditionCheckerUserFind::CheckRideeId(const CString& strValue, ConditionUserFindContext* pContext)
{
    int nRidee = FUN_1407181d0(strValue);
    return nRidee == pContext->m_24;
}
MS2_REPLACE_METHOD(0x1402a9970, CQuestConditionCheckerUserFind, CheckRideeId, 75, 0x64964A63);

// @0x1402a99d0
bool CQuestConditionCheckerUserFind::CheckOppositeGender(const CString& strValue, ConditionUserFindContext* pContext)
{
    bool bValue = FUN_140718390(strValue);
    if (bValue && pContext->m_myKind != pContext->m_targetKind)
        return true;
    if (!bValue && pContext->m_myKind == pContext->m_targetKind)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1402a99d0, CQuestConditionCheckerUserFind, CheckOppositeGender, 102, 0xFA5C281D);

// @0x1402a9a40
bool CQuestConditionCheckerUserFind::Check(CConditionCommonData* pData, ConditionContext* pContext)
{
    if (pData == NULL)
    {
        MS2_ASSERT_AT(0x24, 0);
        return false;
    }
    if (pContext == NULL)
    {
        MS2_ASSERT_AT(0x2a, 0);
        return false;
    }
    if (pContext->FUN_1402a90e0() != 0x11f)
    {
        MS2_ASSERT_AT(0x30, 0);
        return false;
    }
    CConditionDictPtr dict(static_cast<const CConditionDictPtr&>(pData->m_target.m_dict));
    if (!dict)
    {
        MS2_ASSERT_AT(0x37, 0);
        return false;
    }
    for (POSITION pos = dict->GetStartPosition(); pos != NULL; dict->GetNext(pos))
    {
        const CString& strKey = dict->GetKeyAt(pos);
        const CString& strValue = dict->GetValueAt(pos);
        Handler handler;
        if (!m_handlers.Lookup((const char*)strKey, handler))
            continue;
        if (!handler(strValue, static_cast<ConditionUserFindContext*>(pContext)))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1402a9a40, CQuestConditionCheckerUserFind, Check, 596, 0x3428C26B);

// The exe carries a second, byte-identical copy of the delegate assignment/clone chain (0x1402aa240 / 0x1402aa2a0 /
// 0x1402aa600) next to the one the handler map uses; a second instantiation of the same templates reproduces it.
typedef DelegateLib::DelegateMember2<CQuestConditionCheckerUserFind, const CString&, ConditionUserFindContext*, int> UnkDelegateTwin;
template UnkDelegateTwin& UnkDelegateTwin::operator=(const UnkDelegateTwin&);

// The exe keeps two copies of the CRT's inline memmove_s in this unit (0x1402a8fc0 = the header's, via a pin; the second is
// written out here so the unit emits it too).
// @0x1402ab320
static errno_t UnkMemmoveS2(void* pDst, rsize_t nDstSize, const void* pSrc, rsize_t nSrcSize)
{
    if (nSrcSize == 0)
        return 0;
    {
        int nExprVal = !!(pDst != NULL);
        if (!nExprVal)
        {
            errno = EINVAL;
            _invalid_parameter_noinfo();
            return EINVAL;
        }
    }
    {
        int nExprVal = !!(pSrc != NULL);
        if (!nExprVal)
        {
            errno = EINVAL;
            _invalid_parameter_noinfo();
            return EINVAL;
        }
    }
    {
        int nExprVal = !!(nDstSize >= nSrcSize);
        if (!nExprVal)
        {
            errno = ERANGE;
            _invalid_parameter_noinfo();
            return ERANGE;
        }
    }
    memmove(pDst, pSrc, nSrcSize);
    return 0;
}

void UnkUseMemmoveS(void* pDst, size_t nDst, const void* pSrc, size_t nCount)
{
    memmove_s(pDst, nDst, pSrc, nCount);
    UnkMemmoveS2(pDst, nDst, pSrc, nCount);
}
