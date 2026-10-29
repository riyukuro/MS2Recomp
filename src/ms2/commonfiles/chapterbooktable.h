// chapterbooktable.h - CChapterBookTable / CChapterBookData (RTTI names): the chapter book table read from
// Table/chapterBook.xml (<chapterbook id prologue epilogue rewardType1 rewardValue1 rewardType2 rewardValue2/>).
// Header name assumed from the unit path; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// One reward of a chapter (0x40 bytes). m_nType: 1 item, 2 stat point, 3 skill point.
struct Unk_ChapterReward
{
    Unk_ChapterReward();                                // 0x1401dbd70
    Unk_ChapterReward(const Unk_ChapterReward& rOther); // 0x1401dbd10
    int m_nType;                        // +0x00
    int m_nValue;                       // +0x04 point count (types 2, 3)
    ItemEntity m_item;                  // +0x08 the item (type 1)
    int m_nKind;                        // +0x38 skill point kind (1 / 2)
};
MS2_CHECK_SIZE(Unk_ChapterReward, 0x40);
MS2_CHECK_OFFSET(Unk_ChapterReward, m_item, 0x08);
MS2_CHECK_OFFSET(Unk_ChapterReward, m_nKind, 0x38);

// One <chapterbook> row, 0x50 bytes (CPtred base, deleting dtor only).
class CChapterBookData : public CPtred
{
public:
    CChapterBookData();                 // 0x1401dbc90
    // ~CChapterBookData (0x1401dc0d0) is implicit: the exe stores no vftable in it.

    int Read(Unk_140165cf0* pElem);     // 0x1401d8bc0 attributes of one <chapterbook>

    int m_nId;                          // +0x18 "id"
    unsigned m_nPrologue;               // +0x1c "prologue"
    unsigned m_nEpilogue;               // +0x20 "epilogue"
    CStringA m_strUnused;               // +0x28
    ATL::CAtlArray<Unk_ChapterReward> m_rewards;     // +0x30
};
MS2_CHECK_SIZE(CChapterBookData, 0x50);
MS2_CHECK_OFFSET(CChapterBookData, m_strUnused, 0x28);
MS2_CHECK_OFFSET(CChapterBookData, m_rewards, 0x30);

// RTTI CChapterBookTable, 0xa8 bytes (+ TSingleton).
class CChapterBookTable : public TSingleton<CChapterBookTable>
{
public:
    typedef MS2Ptr<CChapterBookData> DataPtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;
    typedef std::map<unsigned, std::pair<int, int> > SkillMap;
    typedef ATL::CAtlMap<int, int> StatMap;

    CChapterBookTable();                // 0x1401d8ec0
    virtual ~CChapterBookTable();       // 0x1401d8f90

    int Load();                                                 // 0x1401d8ff0
    DataPtr Get(int nId);                                       // 0x1401d9410
    void GetByEpilogue(int nEpilogue, ATL::CAtlArray<DataPtr>& rOut);   // 0x1401d9490
    int FindIdByPrologue(int nPrologue);                        // 0x1401d9540
    SkillMap& GetSkillMap();                                    // 0x1401d9600
    StatMap& GetStatMap();                                      // 0x1401d9620

private:
    MS2_LAYOUT_FRIEND;
    DataMap m_books;                    // +0x08 id -> row
    SkillMap m_skill;                   // +0x50 epilogue -> (kind, points)
    StatMap m_stat;                     // +0x60 epilogue -> points
};
MS2_CHECK_SIZE(CChapterBookTable, 0xa8);
MS2_CHECK_OFFSET(CChapterBookTable, m_books, 0x08);
MS2_CHECK_OFFSET(CChapterBookTable, m_skill, 0x50);
MS2_CHECK_OFFSET(CChapterBookTable, m_stat, 0x60);
