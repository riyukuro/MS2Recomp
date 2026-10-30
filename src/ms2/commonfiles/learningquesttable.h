// learningquesttable.h - CLearningQuestTable / CLearningQuestData (RTTI names): the learning quest table read from
// Table/learningQuest.xml (<learning id category movie reqLevel reqQuest reqField gotoField gotoPortal/>).
// Header name assumed; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// One <learning> row, 0x48 bytes; vftable 0x142d6e0b8-ish (deleting dtor only).
class CLearningQuestData : public CPtred
{
public:
    CLearningQuestData();               // 0x14064d220
    // ~CLearningQuestData (0x14064d430) is implicit: the exe stores no vftable in it.

    int Read(Unk_140165cf0* pElem);     // 0x14064ca50 attributes of one <learning>; 0 when the row is unusable

    int m_nId;                          // +0x18 "id"
    int m_nCategory;                    // +0x1c "category"
    int m_nQuestKind;                   // +0x20 filled from the required quest's kind byte (reqQuest != 0)
    CStringA m_strMovie;                // +0x28 "movie"
    unsigned short m_nReqLevel;         // +0x30 "reqLevel"
    int m_nReqQuest;                    // +0x34 "reqQuest" (quest id)
    int m_nReqField;                    // +0x38 "reqField"
    int m_nGotoField;                   // +0x3c "gotoField"
    int m_nGotoPortal;                  // +0x40 "gotoPortal"
};
MS2_CHECK_SIZE(CLearningQuestData, 0x48);
MS2_CHECK_OFFSET(CLearningQuestData, m_strMovie, 0x28);
MS2_CHECK_OFFSET(CLearningQuestData, m_nGotoPortal, 0x40);

// RTTI CLearningQuestTable, 0x38 bytes; vftable 0x142d6e0d8-ish (+ TSingleton).
class CLearningQuestTable : public TSingleton<CLearningQuestTable>
{
public:
    typedef MS2Ptr<CLearningQuestData> DataPtr;
    typedef ATL::CRBMap<int, DataPtr> DataMap;

    CLearningQuestTable();              // 0x14064cbf0
    virtual ~CLearningQuestTable();     // 0x14064cc40

    int Load();                                             // 0x14064cc80
    void GetAll(ATL::CAtlArray<DataPtr>& rOut);             // 0x14064cf80 every row in id order
    DataPtr Get(int nId);                                   // 0x14064d020

private:
    MS2_LAYOUT_FRIEND;
    DataMap m_map;                      // +0x08
};
MS2_CHECK_SIZE(CLearningQuestTable, 0x38);
MS2_CHECK_OFFSET(CLearningQuestTable, m_map, 0x08);
