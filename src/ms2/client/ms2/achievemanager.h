// achievemanager.h - CAchieveManager (RTTI): the client's achievement list (id -> CAchieve) with the packet handler and the
// reward / notification texts, plus the achievement UI description rows (CAchieveUIData, achieveDescription.xml,
// SpecialRewardDesc, achieveSpecialRewardDescription.xml) and the achievement category tree (CAchieveCategory,
// achieveCategory.xml). Member names are invented from use; header name assumed.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/commonfiles/achievecondition.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/notifyobject.h"

// A nullable<int> (commonfiles\nullable.h): the flag byte at +0, the value at +4.
struct Unk_NullableInt
{
    unsigned char HasValue();           // 0x14093aca0 (returns the flag byte as is)
    int* GetValue();                    // 0x1409393d0 (asserts m_isValueSet)

    unsigned char m_bSet;               // +0x00
    int m_nValue;                       // +0x04
};
MS2_CHECK_SIZE(Unk_NullableInt, 8);

// The three counters kept next to the list (index 0..2 = achievement category 1..3); the ctor, the clear and the
// add are out-of-unit helpers (0x140267ba0 / 0x140267bd0 / 0x140267c70).
struct Unk_AchieveTab
{
    void FUN_140267ba0();               // ctor
    void FUN_140267bd0();               // clear
    void FUN_140267c70(int nIndex, int nAdd);   // add to a counter
    int m_n[3];
};
MS2_CHECK_SIZE(Unk_AchieveTab, 0xc);

typedef ATL::CAtlArray<MS2Ptr<CAchieve> > CAchieveList;

class CAchieveManager : public TSingleton<CAchieveManager>
{
public:
    typedef ATL::CRBMap<unsigned, MS2Ptr<CAchieve> > Map;

    CAchieveManager();                                              // 0x140935c20
    virtual ~CAchieveManager();                                     // 0x140935c90 (scalar deleting 0x1409394d0)

    void Reload();                                                  // 0x140935cd0 (every table achievement at its first grade)
    MS2Ptr<CAchieve> Find(unsigned nId);                            // 0x140935e60
    void GetFirstList(CAchieveList& rOut);                          // 0x140935ee0 (type 2, no other filter)
    void GetFirstListByCategory(CAchieveList& rOut, unsigned char nCategory);   // 0x140935f30
    void GetList(CAchieveList& rOut, int nType, unsigned char nCategory, int bStarted, int bGradeReached);   // 0x140935f80
    void GetListFromTable(CAchieveList& rOut, int nType, unsigned char nCategory, int bStarted, int bGradeReached);   // 0x1409361f0
    int GetRewardTotal(int nType);                                  // 0x1409364d0
    int IsCompleted(unsigned nId);                                 // 0x1409365a0
    bool IsGradeCleared(unsigned nId, int nGrade);                  // 0x140936640
    bool HasCompletedOfType(Unk_NullableInt nType);                 // 0x140936740
    int IsBeforeStartGrade(unsigned nId, int nGrade);              // 0x140936900
    int IsBeforeStartGradeOf(MS2Ptr<CAchieve> pAchieve, int nGrade);   // 0x1409369b0
    void OnPacket(CByteBuffer& rBuf);                               // 0x140936a50
    void NotifyClear(CAchieve* pAchieve);                           // 0x140936ec0
    void NotifyReward(int nId, int nGrade);                         // 0x1409372b0
    void Tally(CAchieve* pAchieve);                                 // 0x1409388a0
    void RebuildTally();                                            // 0x1409389f0
    Unk_AchieveTab* GetTally();                                     // 0x140938ad0

    Map m_map;                                                      // +0x08 id -> achievement (ATL red-black tree)
    Unk_AchieveTab m_tally;                                         // +0x38
};
MS2_CHECK_SIZE(CAchieveManager, 0x48);
MS2_CHECK_OFFSET(CAchieveManager, m_map, 0x08);
MS2_CHECK_OFFSET(CAchieveManager, m_tally, 0x38);

// The "achievement cleared" notice queued for the HUD (vftable 0x142dac118, NotifyObject slots).
class NotifyClearAchieve : public NotifyObject
{
public:
    NotifyClearAchieve(int nId);                                    // 0x140939030
    virtual ~NotifyClearAchieve();                                  // 0x140939240
    virtual CStringW vfunc_1();                                     // 0x140db50b0 (notifychangebuff.cpp)

    int m_nId;                                                      // +0x18
};
MS2_CHECK_SIZE(NotifyClearAchieve, 0x20);

// One row of achieveDescription.xml (RTTI CAchieveUIData, 0x48 bytes; CValidData<CAchieveUIData> at +0x18).
class CAchieveUIData : public CPtred, public CValidData<CAchieveUIData>
{
public:
    // One row of achieveSpecialRewardDescription.xml (RTTI CAchieveUIData::SpecialRewardDesc, 0x30 bytes).
    class SpecialRewardDesc : public CPtred
    {
    public:
        SpecialRewardDesc();                                        // 0x140940ac0
        virtual ~SpecialRewardDesc();                               // 0x140940d20

        CStringW m_strSpecialDesc;                                  // +0x18 "specialDesc"
        CStringW m_strNotifyIcon;                                   // +0x20 "specialNotifyIcon"
        CStringW m_strNotifyString;                                 // +0x28 "specialNotifyString"
    };

    CAchieveUIData();                                               // 0x14093add0
    virtual ~CAchieveUIData();                                      // 0x14093ae90

    static bool s_bInit;                                            // 0x143ab34e0
    static void SetInit(bool bInit);                                // 0x1409431b0
    static void CheckInit();                                        // 0x140941290 (message box when the table is not loaded)
    static void LoadAll();                                          // 0x14093af30
    static void LoadDesc();                                         // 0x14093af50 (achieveDescription.xml)
    static void LoadSpecialReward();                                // 0x14093b440 (achieveSpecialRewardDescription.xml)
    static MS2Ptr<CAchieveUIData> Find(int nId);                    // 0x14093b8c0
    static MS2Ptr<SpecialRewardDesc> FindSpecialReward(int nId, int nGrade);   // 0x14093e3e0

    int m_nId;                                                      // +0x20 "id"
    CStringW m_strDesc;                                             // +0x28 "desc"
    CStringW m_strComplete;                                         // +0x30 "complete"
    CStringW m_strManualDesc;                                       // +0x38 "manualDesc"
    CStringW m_strManualComplete;                                   // +0x40 "manualComplete"
};
MS2_CHECK_SIZE(CAchieveUIData, 0x48);
MS2_CHECK_SIZE(CAchieveUIData::SpecialRewardDesc, 0x30);
MS2_CHECK_OFFSET(CAchieveUIData, m_strDesc, 0x28);

// One node of achieveCategory.xml (RTTI CAchieveCategory, 0x68 bytes; CValidData<CAchieveCategory> at +0x18).
class CAchieveCategory : public CPtred, public CValidData<CAchieveCategory>
{
public:
    CAchieveCategory();                                             // 0x14093e4a0
    virtual ~CAchieveCategory();                                    // 0x14093e570

    typedef ATL::CAtlArray<MS2Ptr<CAchieveCategory> > List;

    static bool s_bInit;                                            // 0x143ab3678
    static void SetInit(bool bInit);                                // 0x1409431a0
    static void CheckInit();                                        // 0x1409411e0
    static bool Load();                                             // 0x14093e610 (achieveCategory.xml)
    static void GetTabs(List& rOut);                                // 0x14093eae0 (the open top-level nodes)
    static void GetRows(List& rOut);                                // 0x14093eb90 (the open nodes with their open children)
    static MS2Ptr<CAchieveCategory> GetRow(int nIndex);             // 0x14093ece0
    static MS2Ptr<CAchieveCategory> FindById(int nId);              // 0x14093ef10
    static int FindIdByTab(int nTab);                               // 0x14093f0d0
    static int ParseTab(CStringA& strTab);                          // 0x14093f8a0
    static int ParseTree(CStringA& strTree);                        // 0x14093f910
    int IsOpen();                                                   // 0x14093f240 (no event filter, or the event is running)
    bool Matches(unsigned nAchieveId);                              // 0x14093f2d0

    int m_nId;                                                      // +0x20 "id"
    int m_nTab;                                                     // +0x24 "tab" (summary / emblem / trophy)
    int m_nTree;                                                    // +0x28 "tree" (expand / collapse / fixed)
    CStringA m_strCategoryTag;                                      // +0x30 "categoryTag"
    CStringA m_strContentsTag;                                      // +0x38 "contentsTag"
    CStringW m_strEventFilter;                                      // +0x40 "eventFilter"
    ATL::CAtlArray<MS2Ptr<CAchieveCategory> > m_aChildren;          // +0x48 "child" rows
};
MS2_CHECK_SIZE(CAchieveCategory, 0x68);
MS2_CHECK_OFFSET(CAchieveCategory, m_aChildren, 0x48);
