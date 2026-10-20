// questuidata.h - CQuestUIData (RTTI, 0x90 bytes) and CChapterUIData (RTTI, 0x38 bytes): the quest / chapter texts
// of the client string data (QuestDescription_final.xml, the locale's *chapterdescription*.xml). Header name assumed
// (the unit is ?\questuidata.cpp); member names are invented from the xml tags and from use.
// Both are CPtred rows with CValidData<T> as the second base (+0x18); the rows live in the unit's static maps
// (quest id / chapter id -> row) and are reached through the FUN_1416e5f60 / FUN_1416e7f30 lookups.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"

CString FUN_14016a5c0(const char* pszName, int nFlags);    // undecorated class name

class CQuestUIData : public CPtred, public CValidData<CQuestUIData>
{
public:
    CQuestUIData();                                     // 0x1416e4010
    virtual ~CQuestUIData();                            // 0x1416e4270

    CStringW FUN_1416e6310(int nIndex);                 // the text of condition nIndex (manual text or the type formatter)
    void FUN_1416e6610(ATL::CAtlArray<CStringW>& out);  // the texts of every condition
    CStringW FUN_1416e66f0();                           // the complete text (default: the complete npc line)
    CStringW FUN_1416e6860(int nIndex);                 // the manual text of condition nIndex ("" when none)
    CStringW FUN_1416e6900(int nIndex, const CStringW& strText);   // strText with the condition's progress count

    // @0x1416e8f30
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CString msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CQuestUIData).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1416ebc50
    static void SetInit(bool b) { s_bInit = b; }

    static bool s_bInit;                                // 0x143ae65dd

    int m_nQuestId;                                     // +0x20 "questID"
    CStringW m_strName;                                 // +0x28 "name"
    CStringW m_strSummary;                              // +0x30 "name" (second copy, the mission summary)
    CStringW m_strDesc;                                 // +0x38 "desc"
    CStringW m_strComplete;                             // +0x40 "complete"
    ATL::CAtlArray<CStringW> m_manual;                  // +0x48 "manual" (per condition, '|' separated)
    ATL::CAtlArray<int> m_counts;                       // +0x68 "count" (per condition, '|' separated)
    CStringW m_strDescFameUI;                           // +0x88 "descFameUI"
};
MS2_CHECK_SIZE(CQuestUIData, 0x90);
MS2_CHECK_OFFSET(CQuestUIData, m_nQuestId, 0x20);
MS2_CHECK_OFFSET(CQuestUIData, m_manual, 0x48);
MS2_CHECK_OFFSET(CQuestUIData, m_counts, 0x68);
MS2_CHECK_OFFSET(CQuestUIData, m_strDescFameUI, 0x88);

class CChapterUIData : public CPtred, public CValidData<CChapterUIData>
{
public:
    CChapterUIData();                                   // 0x1416e78f0
    virtual ~CChapterUIData();                          // 0x1416e7980

    // @0x1416e8e80
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CString msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CChapterUIData).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1416ebc40
    static void SetInit(bool b) { s_bInit = b; }

    static bool s_bInit;                                // 0x143ae67e8

    int m_nId;                                          // +0x20 "id"
    CStringW m_strName;                                 // +0x28 "name"
    int m_bTutorial;                                    // +0x30 "isTutorial"
};
MS2_CHECK_SIZE(CChapterUIData, 0x38);
MS2_CHECK_OFFSET(CChapterUIData, m_strName, 0x28);
MS2_CHECK_OFFSET(CChapterUIData, m_bTutorial, 0x30);

// The unit's lookups (free functions; other units declare them by these names).
MS2Ptr<CQuestUIData> FUN_1416e5f60(int nQuestId);          // the row of a quest (null when none)
MS2Ptr<CChapterUIData> FUN_1416e7f30(int nChapterId);      // the row of a chapter (null when none)
