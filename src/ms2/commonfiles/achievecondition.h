// achievecondition.h - CAchieveCondition and CAchieve (RTTI names): one player achievement and its progress counter.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed; member names are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/placeholder/cptred.h"

// Progress counter of one achievement grade. RTTI .?AVCAchieveCondition@@ (0x30 bytes, vftable 0x142ce54b0: the
// deleting dtor, then CConditionCommon's slots 1-7).
class CAchieveCondition : public CObjectCount<CAchieveCondition>, public CConditionCommon
{
public:
    CAchieveCondition();                // 0x1401580a0
    virtual ~CAchieveCondition();       // 0x1401580f0

    int Init(CConditionCommonData* pData, __int64 nGoal);   // 0x140158130

    __int64 m_nGoal;                    // +0x28
};
MS2_CHECK_SIZE(CAchieveCondition, 0x30);
MS2_CHECK_OFFSET(CAchieveCondition, m_nGoal, 0x28);

// One achievement of the player. RTTI .?AVCAchieve@@ (0xe0 bytes, vftable 0x142ce54f8, 1 slot).
class CAchieve : public CObjectCount<CAchieve>, public CPtred
{
public:
    CAchieve();                         // 0x140158180
    virtual ~CAchieve();                // 0x1401582b0

    int Init(int nId, int nGrade, int nState, int nUnused);  // 0x140158350
    BOOL IsStarted();                   // 0x140158630
    int GetData30();                    // 0x140158670
    BOOL HasNextGrade();                // 0x1401586c0
    BOOL IsGradeReached();              // 0x140158730
    BOOL IsCompleted();                 // 0x1401587c0
    int GetData68();                    // 0x140158870
    BOOL IsValid();                     // 0x1401588c0
    void Encode(COutputStream& s);      // 0x140158900
    void Decode(CByteBuffer& b);        // 0x140158a90
    int GetTab();                       // 0x140158cf0
    Unk_AchieveReward* GetReward();     // 0x140158d90
    __int64 GetGradeGoal(int nGrade);   // 0x140158e30
    __int64 GetGoal();                  // 0x140158ef0
    int GetRewardCount();               // 0x140158f20
    __int64 GetValue(int nKey);         // 0x140159040
    __int64 GetPrevGradeGoal(int nGrade);   // 0x140159090
    BOOL CheckRequire();                // 0x140159160
    BOOL CanRewardRequire();            // 0x140159350
    BOOL CanRewardData68();             // 0x1401593c0
    CString GetName(int nUnused);       // 0x140159430

    // Inline accessors (COMDATs in this obj).
    // @0x14015a020
    int GetCurGrade() { return m_nCurGrade; }
    // @0x14015a280
    int GetState() { return m_nState; }
    // @0x14015a290
    int GetType() { return m_pData->m_nType; }

    // More inline accessors; their COMDATs sit in client\ms2\achievemanager.cpp's range (bodies there).
    MS2Ptr<CAchieveData> GetDataRef();  // 0x1409398d0
    unsigned GetId();                   // 0x1409399f0
    int GetStartGrade();                // 0x140939ae0
    int GetCondType();                  // 0x140941760
    __int64 GetProgress();              // 0x140941790
    void SetBookmark(int bBookmark);    // 0x1418b0bc0 (COMDAT of uiachievedialog.cpp: m_d8)
    int GetBookmark();                  // 0x1418aff70 (m_d8)
    int GetValue80();                   // 0x1418aff90 (m_80)

    float m_18;                         // +0x18
    MS2Ptr<CAchieveData> m_pData;       // +0x20
    __int64 m_30;                       // +0x30
    __int64 m_38;                       // +0x38
    __int64 m_40;                       // +0x40
    int m_nId;                          // +0x48
    int m_nState;                       // +0x4c (3 = completed)
    CAchieveCondition m_cond;           // +0x50
    int m_80;                           // +0x80
    int m_nStartGrade;                  // +0x84
    int m_nCurGrade;                    // +0x88
    ATL::CAtlMap<DWORD, __int64> m_mapValue;    // +0x90 (key type: see the note in achievecondition.cpp)
    int m_d8;                           // +0xd8
};
MS2_CHECK_SIZE(CAchieve, 0xe0);
MS2_CHECK_OFFSET(CAchieve, m_18, 0x18);
MS2_CHECK_OFFSET(CAchieve, m_pData, 0x20);
MS2_CHECK_OFFSET(CAchieve, m_cond, 0x50);
MS2_CHECK_OFFSET(CAchieve, m_mapValue, 0x90);
MS2_CHECK_OFFSET(CAchieve, m_d8, 0xd8);
