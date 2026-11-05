// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The quest and chapter UI texts: CQuestUIData rows from
// the locale's QuestDescription_final.xml and CChapterUIData rows from its *chapterdescription*.xml files, kept in
// the unit's static maps, plus the quest name / title / condition text helpers the quest UI calls (see questuidata.h).
// File name assumed. The condition texts go through a table of formatters by condition type (s_condTexts).
// MS2-UNIT: ?\questuidata.cpp
// MS2-RANGE: 0x1400feaa0-0x1400fed80 .text$di
// MS2-RANGE: 0x1416e4010-0x1416ec120 .text$mn
// MS2-RANGE: 0x142cb5aa0-0x142cb5bd0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400fecd0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400fed00 ; probe
// MS2-PIN: ??0CNode@?$CAtlMap@HV?$MS2Ptr@VCChapterUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCChapterUIData@@@@@3@@ATL@@QEAA@HI@Z 0x1416e8930 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VCChapterUIData@@@@QEBAPEAVCChapterUIData@@XZ 0x1416e8cb0 ; unique
// MS2-PIN: ??_ECChapterUIData@@WBI@EAAPEAXI@Z 0x1416e8ce0 ; unique
// MS2-PIN: ??_ECQuestUIData@@WBI@EAAPEAXI@Z 0x1416e8cec ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@HV?$MS2Ptr@VCChapterUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCChapterUIData@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1416ea270 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HV?$MS2Ptr@VCQuestUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestUIData@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1416eb500 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$MS2Ptr@VCQuestUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestUIData@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x1416eb770 ; prop
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cb5b70 ; probe
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cb5b90 ; probe
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CQuestUIData@@6B?$CValidData@VCQuestUIData@@@@@ 0x142f58528
// MS2-PIN: ??_7CChapterUIData@@6B?$CValidData@VCChapterUIData@@@@@ 0x142f58558
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\questuidata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "questuidata.h"
#include <stdlib.h>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/filesystem.h"

// ---- callees of other units -----------------------------------------------------------------------------------------

class Unk_QuiLoader : public CFileSystem { };
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_14015eb90
CString FUN_14071ae20(const CString& strFile);                          // the locale's string data path of <file>
CString FUN_140651350();                                                // the locale code
CString FUN_14028d3c0(CString strPath);                                 // the file name of a path
void FUN_1401d3700(CString& str);                                       // lower case
void FUN_140399100(CString strExt, CString strDir, ATL::CAtlArray<CString>& arrFiles, CString strPrefix, bool bRecursive);
bool FUN_14028f650(struct Unk_XmlElement*);   // C3: was FUN_14028f650
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);   // int attribute with default
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault);   // wide string attribute
void FUN_14025a680(CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* pszDelim);
void FUN_1401d9a30(CStringW& str, ATL::CAtlArray<int>& out, const wchar_t* pszDelim);
CStringW GetStringCommon(int nStringId);                                  // a common string by id
CStringW GetStringCommonByKey(const CStringW& strKey);                         // a common string by key
template <class A> CStringW FormatStringId(int nId, const A& a);
CStringW FUN_1413fac10(CStringW strText, CStringW strWord);             // strText with the josa of strWord
CStringW FUN_1401aa6a0(int nNpcId);                                     // the npc name
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);                         // the quest table row (null when none)
int FUN_14074bc90(int nQuestId);                                        // the quest type
int FUN_14074b050(CQuestData* pData);
int FUN_14074b070(CQuestData* pData);                                   // the repeat kind (1 daily, 2 weekly, 3 week repeat)
void* FUN_140764020();   // C3: was FUN_140764020
                  // the local player (NULL outside the field)
                  // the npc id of the open talk
extern int DAT_143ae0fc0;                                               // debug switch: show ids

// ---- the unit's statics ---------------------------------------------------------------------------------------------

// A condition text formatter: the text of the condition's "code" (and "target") parameter.
typedef CStringW (*FnCondText)(CQuestUIData* pData, CConditionCommonData* pCond);

// @0x1400feaa0
static ATL::CAtlMap<int, FnCondText> s_condTexts(17, 0.75f, 0.25f, 2.25f, 10);         // condition type -> formatter
// @0x1400feaf0
static ATL::CAtlMap<int, MS2Ptr<CChapterUIData> > s_chapters(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400feb40
static ATL::CAtlMap<int, MS2Ptr<CQuestUIData> > s_quests(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400feb90
static CLockCriticalSection s_lock;
// @0x1400febc0
static ATL::CAtlMap<int, MS2Ptr<CCacheData> > s_caches(17, 0.75f, 0.25f, 2.25f, 10);   // quest id -> the file it came from

// @0x1400fec10 (s_strSortTypeNames), @0x1400fecd0 / @0x1400fed00 (skill / stun), @0x1400fed30 (the condition table)
#include "ms2/placeholder/header_statics_a.h"
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flags (symbols-manual.tsv); local copies stay false
bool CQuestUIData::s_bInit;
bool CChapterUIData::s_bInit;
#endif

static CStringW FUN_1416e6f10(CQuestUIData* pData, CConditionCommonData* pCond);
static CStringW FUN_1416e7000(CQuestUIData* pData, CConditionCommonData* pCond);
static CStringW FUN_1416e71a0(CQuestUIData* pData, CConditionCommonData* pCond);
static CStringW FUN_1416e7270(CQuestUIData* pData, CConditionCommonData* pCond);
static CStringW FUN_1416e7470(CQuestUIData* pData, CConditionCommonData* pCond);
static CStringW FUN_1416e7570(CQuestUIData* pData, CConditionCommonData* pCond);
void FUN_1416e4590(CString strPath);
void FUN_1416e43d0();
void LoadChapterDescriptions();
void FUN_1416e7c00(CString strPath);
CStringW FUN_1416e4df0(int nQuestId);

// ---- CQuestUIData ---------------------------------------------------------------------------------------------------

// @0x1416e4010
CQuestUIData::CQuestUIData()
{
    if (s_condTexts.GetCount() == 0)
    {
        s_condTexts.SetAt(12, FUN_1416e6f10);
        s_condTexts.SetAt(26, FUN_1416e7000);
        s_condTexts.SetAt(29, FUN_1416e71a0);
        s_condTexts.SetAt(30, FUN_1416e71a0);
        s_condTexts.SetAt(37, FUN_1416e7270);
        s_condTexts.SetAt(2, FUN_1416e7470);
        s_condTexts.SetAt(3, FUN_1416e7470);
        s_condTexts.SetAt(4, FUN_1416e7470);
        s_condTexts.SetAt(156, FUN_1416e7570);
    }
    m_nQuestId = 0;
}

// @0x1416e4270
CQuestUIData::~CQuestUIData()
{
}

// Loads the quest texts, then the chapter texts, and expands their reserved words.
// @0x1416e4340
void LoadQuestDescription()
{
    CString strPath = FUN_14071ae20("QuestDescription_final.xml");
    FUN_1416e4590(strPath);
    CQuestUIData::SetInit(true);
    LoadChapterDescriptions();
    FUN_1416e43d0();
}

// Expands the reserved words ($item:..$, ...) of every quest text.
// @0x1416e43d0
void FUN_1416e43d0()
{
    for (POSITION pos = s_quests.GetStartPosition(); pos != NULL; s_quests.GetNext(pos))
    {
        MS2Ptr<CQuestUIData> spData = s_quests.GetValueAt(pos);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(spData->m_strName);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(spData->m_strComplete);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceBoldWords(spData->m_strDesc);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceBoldWords(spData->m_strSummary);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(spData->m_strDescFameUI);
        for (size_t i = 0; i < spData->m_manual.GetCount(); i++)
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(spData->m_manual[i]);
    }
}

// Reads one quest description file: <ms2><quest questID name name desc complete descFameUI manual count/>.
// @0x1416e4590
void FUN_1416e4590(CString strPath)
{
    TiXmlDocument doc;
    if (((class Unk_QuiLoader*)GetFileSystem())->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = ((class Unk_140165cf0*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    MS2Ptr<CCacheData> spCache(new CCacheData);
    spCache->FUN_1401d1160(strPath);
    for (Unk_140165cf0* pQuest = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("quest")); pQuest != 0; pQuest = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pQuest))->NextSibling("quest")))
    {
        if (!FUN_14028f650((struct Unk_XmlElement*)(pQuest)))
            continue;
        MS2Ptr<CQuestUIData> spData(new CQuestUIData);
        spData->m_nQuestId = atoi(Unk_ReadString((class Unk_XmlNode*)(pQuest), "questID", CString("")));
        spData->m_strName = FUN_1401bf530(pQuest, "name", CStringW(L""));
        spData->m_strSummary = FUN_1401bf530(pQuest, "name", CStringW(L""));
        spData->m_strDesc = FUN_1401bf530(pQuest, "desc", CStringW(L""));
        spData->m_strComplete = FUN_1401bf530(pQuest, "complete", CStringW(L""));
        spData->m_strDescFameUI = FUN_1401bf530(pQuest, "descFameUI", CStringW(L""));
        spData->m_strDesc.Replace(L"\\n", L"\n");
        spData->m_strComplete.Replace(L"\\n", L"\n");
        spData->m_strDescFameUI.Replace(L"\\n", L"\n");
        CStringW strManual = FUN_1401bf530(pQuest, "manual", CStringW(L""));
        CStringW strCount = FUN_1401bf530(pQuest, "count", CStringW(L""));
        FUN_14025a680(strManual, spData->m_manual, L"|");
        FUN_1401d9a30(strCount, spData->m_counts, L"|");
        for (size_t i = 0; i < spData->m_manual.GetCount(); i++)
            spData->m_manual[i].TrimRight();
        if (Unk_LockGuard guard = s_lock)
        {
        }
        else
        {
            s_quests.SetAt(spData->m_nQuestId, spData);
            s_caches.SetAt(spData->m_nQuestId, spCache);
        }
    }
}

// The quest's localized name: the description name, prefixed by the daily / weekly kind of a repeat quest.
// @0x1416e4df0
CStringW FUN_1416e4df0(int nQuestId)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return L"";
    MS2Ptr<CQuestData> spData = TSingleton<QuestDataTable>::GetInstance()->GetQuestById(nQuestId);
    if (spData == 0)
        return L"";
    CStringW strName;
    if (FUN_14074b070(spData.operator->()) == 1)
    {
        strName = StringFormat(L"{0} {1}", GetStringCommon(0x5e0), spUI->m_strName);
    }
    else if (FUN_14074b070(spData.operator->()) == 2)
    {
        strName = StringFormat(L"{0} {1}", GetStringCommon(0x5e1), spUI->m_strName);
    }
    else if (FUN_14074b070(spData.operator->()) == 3)
    {
        strName = StringFormat(L"{0} {1}", GetStringCommonByKey(L"s_quest_repeat_week"), spUI->m_strName);
    }
    else
    {
        strName = spUI->m_strName;
    }
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strName);
    if (DAT_143ae0fc0 != 0)
        strName.AppendFormat(L" [%d]", spUI->m_nQuestId);
    return strName;
}

// The quest name formatted by a string-table key with the quest level ("s_quest_name_with_level").
// @0x1416e5210
CStringW FUN_1416e5210(int nQuestId, CStringW strKey)
{
    CStringW strName = FUN_1416e4df0(nQuestId);
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() != 0)
        return FUN_14028dfa0<CStringW, int>(strKey, strName, spData->m_level);
    return strName;
}

// The mission summary of a quest, with the progress count of condition nIndex.
// @0x1416e5350
CStringW FUN_1416e5350(int nQuestId, int nIndex)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return L"";
    CStringW strText = spUI->m_strSummary;
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
    return spUI->FUN_1416e6900(nIndex, strText);
}

// @0x1416e5450
CStringW FUN_1416e5450(int nQuestId)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return L"";
    return spUI->m_strDesc;
}

// @0x1416e5500
CStringW FUN_1416e5500(int nQuestId)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return L"";
    return spUI->m_strDescFameUI;
}

// @0x1416e55b0
CStringW FUN_1416e55b0(int nQuestId)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return L"";
    return spUI->GetCompleteText();
}

CStringW FUN_1416e57d0(int nQuestId, int nIndex);

// Every condition text of a quest, one per line.
// @0x1416e5660
CStringW FUN_1416e5660(int nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return L"";
    CStringW strText;
    for (size_t i = 0; i < spData->m_conditions.GetCount(); i++)
    {
        if (strText.GetLength() != 0)
            strText += L"\n";
        strText += FUN_1416e57d0(nQuestId, (int)i);
    }
    return strText;
}

// @0x1416e57d0
CStringW FUN_1416e57d0(int nQuestId, int nIndex)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return L"";
    return spUI->GetConditionText(nIndex);
}

// @0x1416e5890
void FUN_1416e5890(int nQuestId, ATL::CAtlArray<CStringW>& out)
{
    MS2Ptr<CQuestUIData> spUI = FUN_1416e5f60(nQuestId);
    if (!spUI)
        return;
    spUI->GetConditionTexts(out);
}

// The quest title "[type] name" (bLevel: the name with the quest level).
// @0x1416e5900
CStringW FUN_1416e5900(int nQuestId, bool bLevel)
{
    CStringW strType = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x50, nQuestId);
    if (strType.GetLength() == 0)
    {
        switch (FUN_14074bc90(nQuestId))
        {
        case 0:
            strType = GetStringCommon(0x5dd);
            break;
        case 1:
            strType = GetStringCommon(0x5de);
            break;
        case 2:
            strType = GetStringCommon(0x5df);
            break;
        case 6:
            strType = GetStringCommonByKey(L"s_quest_guild_quest");
            break;
        case 3:
            strType = GetStringCommonByKey(L"s_quest_daily_mission");
            break;
        case 4:
            strType = GetStringCommonByKey(L"s_quest_field_mission");
            break;
        case 5:
            strType = GetStringCommonByKey(L"s_quest_event_mission");
            break;
        case 8:
            strType = GetStringCommonByKey(L"s_quest_field_quest");
            break;
        case 9:
            strType = GetStringCommonByKey(L"s_quest_alliance_quest");
            break;
        }
    }
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if ((spData.get() ? true : false))
    {
        if (FUN_14074b050(spData.operator->()) == 0 && spData->m_30 != 0)
            strType = L"\xad6c\xc5d0\xd53d";
    }
    CStringW strTitle;
    if (bLevel)
        strTitle.Format(L"[%s] %s", (const wchar_t*)strType, (const wchar_t*)FUN_1416e5210(nQuestId, CStringW(L"s_quest_name_with_level")));
    else
        strTitle.Format(L"[%s] %s", (const wchar_t*)strType, (const wchar_t*)FUN_1416e4df0(nQuestId));
    return strTitle;
}

// The row of a quest; reloads its file when it changed on disk.
// @0x1416e5f60
MS2Ptr<CQuestUIData> FUN_1416e5f60(int nQuestId)
{
    CQuestUIData::CheckInit();
    MS2Ptr<CQuestUIData> spData(0);
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else if (s_quests.Lookup(nQuestId, spData))
    {
        MS2Ptr<CCacheData> spCache(0);
        if (s_caches.Lookup(nQuestId, spCache))
        {
            if (FUN_1401d1320(spCache.operator->()))
            {
                FUN_1416e4590(*spCache->FUN_1401d1140());
                FUN_1416e43d0();
                s_quests.Lookup(nQuestId, spData);
            }
        }
        return spData;
    }
    return MS2Ptr<CQuestUIData>(0);
}

// Whether the local player may accept / complete the quest: 0 = ok, else the common string id of the reason.
// @0x1416e6100
int FUN_1416e6100(int nQuestId, int bIgnoreNpc)
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
        if (!spData)
            return 0;
        int nNpcId = TSingleton<UITalkManager>::GetInstance()->FUN_141b212f0();
        if (((class CQuestManager*)FUN_140764020())->FUN_140745590(nQuestId))
        {
            return 0x5dc;
        }
        else
        {
            int nStartNpc;
            if (bIgnoreNpc)
                nStartNpc = nNpcId;
            else
                nStartNpc = spData->m_2ec;
            if (((class CQuestManager*)FUN_140764020())->FUN_140746ba0(nQuestId, nStartNpc, 0) == 0)
            {
                return 0x5db;
            }
            else
            {
                if (((class CQuestManager*)FUN_140764020())->IsQuestActive(nQuestId))
                {
                    return 0x5da;
                }
                else
                {
                    int nEndNpc;
                    if (bIgnoreNpc)
                        nEndNpc = nNpcId;
                    else
                        nEndNpc = spData->m_2e8;
                    if (((class CQuestManager*)FUN_140764020())->vfunc_1(nQuestId, nEndNpc))
                        return 0x5d9;
                    else
                        return 0x5d8;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE(0x1416E6100, FUN_1416e6100, 480, 0x5BCD3556);

// ---- CQuestUIData members -------------------------------------------------------------------------------------------

// @0x1416e6310
CStringW CQuestUIData::GetConditionText(int nIndex)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(m_nQuestId);
    if (!spData)
        return L"";
    if (nIndex >= (int)spData->m_conditions.GetCount())
        return L"";
    MS2Ptr<CConditionCommonData> spCond = spData->m_conditions[nIndex];
    CStringW strManual = GetManualText(nIndex);
    if (strManual.GetLength() != 0)
    {
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strManual);
        return FUN_1416e6900(nIndex, strManual);
    }
    FnCondText pfn = 0;
    if (!s_condTexts.Lookup(spCond->m_nType, pfn))
        return L"";
    CStringW strText = (*pfn)(this, spCond);
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
    return FUN_1416e6900(nIndex, strText);
}

// @0x1416e6610
void CQuestUIData::GetConditionTexts(ATL::CAtlArray<CStringW>& out)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(m_nQuestId);
    if (!spData)
        return;
    for (size_t i = 0; i < spData->m_conditions.GetCount(); i++)
        out.Add(GetConditionText((int)i));
}

// @0x1416e66f0
CStringW CQuestUIData::GetCompleteText()
{
    CQuestData* pData = FUN_14074bc40(m_nQuestId).get();
    if (pData == 0)
        return L"";
    if (m_strComplete.GetLength() != 0)
        return m_strComplete;
    int nNpcId = pData->m_2ec;
    CStringW strText = FormatStringId<CStringW>(0x5e7, FUN_1401aa6a0(nNpcId));
    return strText;
}
MS2_REPLACE_METHOD(0x1416E66F0, CQuestUIData, GetCompleteText, 356, 0x7159BD0D);

// @0x1416e6860
CStringW CQuestUIData::GetManualText(int nIndex)
{
    if (nIndex >= (int)m_manual.GetCount())
        return L"";
    return m_manual[nIndex];
}
MS2_REPLACE_METHOD(0x1416E6860, CQuestUIData, GetManualText, 143, 0x8292B47D);

// @0x1416e6900
CStringW CQuestUIData::FUN_1416e6900(int nIndex, const CStringW& strText)
{
    CStringW str = strText;
    int nCount = 0;
    if (nIndex < (int)m_counts.GetCount())
        nCount = m_counts[nIndex];
    CStringW strManual = GetManualText(nIndex);
    if (strManual.GetLength() != 0 && nCount == 0)
        return str;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(m_nQuestId);
    if (!spData)
        return str;
    if (nIndex >= (int)spData->m_conditions.GetCount())
        return str;
    MS2Ptr<CConditionCommonData> spCond = spData->m_conditions[nIndex];
    if (spCond->m_nType == 37 && strManual.GetLength() == 0)
        return str;
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<CQuest> spQuest = ((class CQuestManager*)FUN_140764020())->vfunc_o10_3(m_nQuestId);
        if (spQuest.get() != 0)
        {
            __int64 nGoal = spData->m_conditions[nIndex]->m_nGoal;
            __int64 nCurrent = spQuest->IsRewarded() ? nGoal : spQuest->GetProgress(nIndex);
            if (nCurrent < 0)
                nCurrent = 0;
            if (nCurrent > nGoal)
                nCurrent = nGoal;
            return FUN_14028dfa0(CStringW(L"s_quest_desc_with_count"), str, nCurrent, nGoal);
        }
        else
        {
            __int64 nGoal = spData->m_conditions[nIndex]->m_nGoal;
            __int64 nCurrent = 0;
            return FUN_14028dfa0(CStringW(L"s_quest_desc_with_count"), str, nCurrent, nGoal);
        }
    }
    return str;
}
MS2_REPLACE_METHOD(0x1416E6900, CQuestUIData, FUN_1416e6900, 1518, 0xA9B45814);

// ---- the condition text formatters (s_condTexts) --------------------------------------------------------------------

// type 12: the npc to talk to
// @0x1416e6f10
static CStringW FUN_1416e6f10(CQuestUIData* pData, CConditionCommonData* pCond)
{
    if (pCond->m_code.GetIdCount() < 1)
        return L"";
    int nNpcId = (int)pCond->m_code.GetFirstValue();
    CStringW strText = FormatStringId<CStringW>(0x5e2, FUN_1401aa6a0(nNpcId));
    return strText;
}

// type 26: the npc to meet (with the josa of the name)
// @0x1416e7000
static CStringW FUN_1416e7000(CQuestUIData* pData, CConditionCommonData* pCond)
{
    if (pCond->m_code.GetIdCount() < 1)
        return L"";
    int nNpcId = (int)pCond->m_code.GetFirstValue();
    CStringW strFormat = GetStringCommon(0x5e3);
    CStringW strJosa = FUN_1413fac10(strFormat, FUN_1401aa6a0(nNpcId));
    CStringW strText = StringFormat<CStringW>(strJosa, FUN_1401aa6a0(nNpcId));
    return strText;
}

// types 29 / 30: the string of table 11
// @0x1416e71a0
static CStringW FUN_1416e71a0(CQuestUIData* pData, CConditionCommonData* pCond)
{
    if (pCond->m_code.GetIdCount() < 1)
        return L"";
    int nId = (int)pCond->m_code.GetFirstValue();
    if (nId == 0)
        return L"";
    return TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xb, nId);
}

// type 37: the map to reach (with the josa of the name)
// @0x1416e7270
static CStringW FUN_1416e7270(CQuestUIData* pData, CConditionCommonData* pCond)
{
    if (pCond->m_code.GetIdCount() < 1)
        return L"";
    int nMapId = (int)pCond->m_code.GetFirstValue();
    CStringW strText;
    CStringW strFormat = GetStringCommon(0x5e5);
    CStringW strJosa = FUN_1413fac10(strFormat, TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, nMapId));
    strText = StringFormat<CStringW>(strJosa, TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, nMapId));
    return strText;
}

// types 2 / 3 / 4: the item to get
// @0x1416e7470
static CStringW FUN_1416e7470(CQuestUIData* pData, CConditionCommonData* pCond)
{
    if (pCond->m_code.GetIdCount() < 1)
        return L"";
    int nItemId = (int)pCond->m_code.GetFirstValue();
    CStringW strText = FormatStringId<CStringW>(0x5e6, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
    return strText;
}

// type 156: the item to give to the npc (both with their josa)
// @0x1416e7570
static CStringW FUN_1416e7570(CQuestUIData* pData, CConditionCommonData* pCond)
{
    if (pCond->m_code.GetIdCount() < 1)
        return L"";
    if (pCond->m_target.GetIdCount() < 1)
        return L"";
    int nNpcId = (int)pCond->m_target.GetFirstValue();
    int nItemId = (int)pCond->m_code.GetFirstValue();
    CStringW strFormat;
    CStringW strBase = GetStringCommon(0x5e9);
    strFormat = FUN_1413fac10(strBase, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
    strFormat = FUN_1413fac10(strFormat, TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xc, nNpcId));
    CStringW strText = StringFormat(strFormat, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId), TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xc, nNpcId));
    return strText;
}

// ---- CChapterUIData -------------------------------------------------------------------------------------------------

// @0x1416e78f0
CChapterUIData::CChapterUIData()
    : m_nId(0), m_bTutorial(0)
{
}

// @0x1416e7980
CChapterUIData::~CChapterUIData()
{
}

// Loads the chapter texts of every *chapterdescription*.xml of the locale.
// @0x1416e79e0
void LoadChapterDescriptions()
{
    ATL::CAtlArray<CString> files;
    FUN_140399100(CString("*.xml"), FUN_14071ae20(FUN_140651350()), files, CString(""), false);
    for (size_t i = 0; i < files.GetCount(); i++)
    {
        CString strName = FUN_14028d3c0(files[i]);
        FUN_1401d3700(strName);
        if (strName.Find("chapterdescription", 0) != -1)
            FUN_1416e7c00(files[i]);
    }
    CChapterUIData::SetInit(true);
}

// Reads one chapter description file: <ms2><chapter id name desc isTutorial/>.
// @0x1416e7c00
void FUN_1416e7c00(CString strPath)
{
    TiXmlDocument doc;
    if (((class Unk_QuiLoader*)GetFileSystem())->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = ((class Unk_140165cf0*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pChapter = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("chapter")); pChapter != 0; pChapter = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pChapter))->NextSibling("chapter")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pChapter)))
            continue;
        MS2Ptr<CChapterUIData> spChapter(new CChapterUIData);
        spChapter->m_nId = FUN_140197350(pChapter, "id", 0);
        CStringW strName = FUN_1401bf530(pChapter, "name", CStringW(L""));
        CStringW strDesc = FUN_1401bf530(pChapter, "desc", CStringW(L""));
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(strName);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(strDesc);
        spChapter->m_strName = strName;
        XmlGetAttr((class TiXmlElement*)(pChapter), "isTutorial", reinterpret_cast<int&>(spChapter->m_bTutorial));
        s_chapters.SetAt(spChapter->m_nId, spChapter);
    }
}

// @0x1416e7f30
MS2Ptr<CChapterUIData> FUN_1416e7f30(int nChapterId)
{
    CChapterUIData::CheckInit();
    MS2Ptr<CChapterUIData> spChapter(0);
    s_chapters.Lookup(nChapterId, spChapter);
    return spChapter;
}

// The chapter name.
// @0x1416e7fb0
CStringW FUN_1416e7fb0(int nChapterId)
{
    MS2Ptr<CChapterUIData> spChapter = FUN_1416e7f30(nChapterId);
    if (spChapter.get() != 0)
        return spChapter->m_strName;
    return L"";
}

// The chapter is a tutorial chapter.
// @0x1416e8060
int FUN_1416e8060(int nChapterId)
{
    MS2Ptr<CChapterUIData> spChapter = FUN_1416e7f30(nChapterId);
    if (spChapter.get() != 0)
        return spChapter->m_bTutorial;
    return 0;
}
