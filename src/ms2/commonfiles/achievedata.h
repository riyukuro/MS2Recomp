// achievedata.h - CAchieveData / CAchieveGradeData (RTTI names; achievement table rows). Header name assumed. The
// code is the second obj of the old `?\achievecondition.cpp` range (0x14015b490-0x14016da90, here ?\achievedata.cpp).
// Member names are invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// The reward block of a grade (0x60 bytes, ctor 0x140164110, dtor 0x140164650; m_nType 0 = no reward).
// Loaded from the <reward type= code= value= rank= subJobLevel= extra=> element.
struct Unk_AchieveReward
{
    Unk_AchieveReward();                // 0x140164110
    ~Unk_AchieveReward();               // 0x140164650
    bool operator!=(const Unk_AchieveReward& o) const;  // 0x140164880
    int m_nType;                        // +0x00 (1 item, 2 title, 3 statpoint, 4 skillpoint, ...)
    unsigned m_nCode;                   // +0x04
    unsigned m_nValue;                  // +0x08
    int m_nRank;                        // +0x0c (1 by default)
    long m_nSubJob;                     // +0x10 (1 by default)
    int m_pad_14;
    ATL::CAtlMap<CStringA, CStringA, ATL::CStringElementTraitsI<CStringA> > m_mapExtra;   // +0x18
};
MS2_CHECK_SIZE(Unk_AchieveReward, 0x60);

// One grade (step) of an achievement. RTTI .?AVCAchieveGradeData@@, 0x90 bytes, vftable 0x142ce68a0.
class CAchieveGradeData : public CPtred
{
public:
    CAchieveGradeData();                // 0x14015b490
    virtual ~CAchieveGradeData();       // 0x14015b540
    bool operator!=(const CAchieveGradeData& o) const;  // 0x14015b5a0 (true when the grades differ)

    int m_nGrade;                       // +0x18
    int m_pad_1c;
    Unk_AchieveReward m_reward;         // +0x20
    MS2Ptr<CConditionCommonData> m_pCondition;  // +0x80
};
MS2_CHECK_SIZE(CAchieveGradeData, 0x90);
MS2_CHECK_OFFSET(CAchieveGradeData, m_reward, 0x20);
MS2_CHECK_OFFSET(CAchieveGradeData, m_pCondition, 0x80);


// One achievement. RTTI .?AVCAchieveData@@, 0xf8 bytes; bases CObjectCount<CAchieveData> (empty, +0x30),
// CCacheData (+0), CValidData<CAchieveData> (+0x28).
class CAchieveData : public CObjectCount<CAchieveData>, public CCacheData, public CValidData<CAchieveData>
{
public:
    CAchieveData();                     // 0x14015b640
    virtual ~CAchieveData();            // 0x14015b7d0

    bool operator!=(const CAchieveData& o) const;       // 0x14015b8d0 (true when the tables differ)
    MS2Ptr<CAchieveGradeData> GetGrade(int nGrade);     // 0x14015bc40
    CString GetName();                  // 0x14015bcd0 (icon path)
    int IsAvailable();                  // 0x14015bd60 (feature and locale of this build)
    void OnLoaded();                    // 0x14015dcb0 (empty)

    // The table (loaded from Achieve\*.xml, see LoadAll/Load in achievedata.cpp).
    static bool s_bInit;                // 0x143aab3a0
    static void CheckInit();            // 0x140165670
    static void SetInit(bool bInit);    // 0x14016a500
    static int GetSurvivalFlag(int nId);                // 0x14015be50
    static int HasRewardSkill(unsigned nId, int nGrade);   // 0x14015bed0
    static int HasRewardStat(unsigned nId, int nGrade);    // 0x14015bf90
    static void LoadAll();              // 0x14015c050
    static void Load(CString strPath);  // 0x14015c270
    static void LoadClient(CString strPath, MS2Ptr<CAchieveData>& rOut);   // 0x14015cff0
    static MS2Ptr<CAchieveGradeData> Find(int nId, int nGrade);   // 0x14015dab0
    static void GetAll(ATL::CAtlArray<MS2Ptr<CAchieveData> >& rOut);   // 0x14015db60
    static int MarkSeen(int nId);       // 0x14015dc10
    static int ParseRequireType(CStringA& str);         // 0x14015dcc0
    static int ParseRewardType(CStringA& str);          // 0x14015dd20
    static int ParseRewardType(CStringW& str);          // 0x14015df00
    static CStringW GetRewardTypeName(int nType);       // 0x14015df70

    int m_nAccount;                     // +0x30 ("account")
    unsigned m_nId;                     // +0x34 ("id")
    int m_nType;                        // +0x38 (id / 10000000)
    int m_nMaxGrade;                    // +0x3c
    int m_nFirstGrade;                  // +0x40 (ctor: 0x7fffffff)
    int m_pad_44;
    CString m_strIcon;                  // +0x48 ("icon")
    int m_nNoticePercent;               // +0x50 ("noticePercent", ctor: 1)
    int m_pad_54;
    CStringW m_strFeature;              // +0x58 ("feature")
    CString m_strLocale;                // +0x60 ("locale")
    int m_nLocking;                     // +0x68 ("locking")
    int m_nSurvival;                    // +0x6c (1 when contentsTag contains "Survival")
    int m_nCategory;                    // +0x70 ((id / 1000000) % 10)
    int m_pad_74;
    CString m_strCategoryTag;           // +0x78 ("categoryTag")
    CString m_strContentsTag;           // +0x80 ("contentsTag")
    int m_nRequireType;                 // +0x88 ("uiFilterType": 1 event name, 2 event id)
    int m_pad_8c;
    ATL::CAtlArray<CStringW> m_aRequire;                        // +0x90 ("uiFilterValue")
    ATL::CAtlMap<int, MS2Ptr<CAchieveGradeData> > m_mapGrade;   // +0xb0
};
MS2_CHECK_SIZE(CAchieveData, 0xf8);
MS2_CHECK_OFFSET(CAchieveData, m_nFirstGrade, 0x40);
MS2_CHECK_OFFSET(CAchieveData, m_strIcon, 0x48);
MS2_CHECK_OFFSET(CAchieveData, m_nRequireType, 0x88);
MS2_CHECK_OFFSET(CAchieveData, m_aRequire, 0x90);

// Looks the achievement up in the table cache (0x14015d9e0; name invented).
MS2Ptr<CAchieveData> GetAchieveData(int nId);
