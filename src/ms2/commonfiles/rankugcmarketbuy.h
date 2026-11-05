// rankugcmarketbuy.h - the ranking client data: CRankUgcMarketBuy (one entry of the UGC market buy ranking, read from
// the ranking packet), RankingArenaData / CRankingArenaDataTable (the arena grade table, Table/pvpRankingDuelMode.xml)
// and CRankViewer (the singleton that holds the two ranking lists). Owning unit: ?\rankugcmarketbuy.cpp
// (0x140768690-0x14076a1e0). Class names from RTTI; field names invented.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"

class COutputStream;
class CInPacket;
class TiXmlElement;     // game TinyXML element

// RTTI CRankUgcMarketBuy, 0x48 bytes. The wire format is the field order of Write / Read.
class CRankUgcMarketBuy : public CPtred
{
public:
    CRankUgcMarketBuy();                            // 0x140768690
    virtual ~CRankUgcMarketBuy();                   // 0x140768700 (??_G 0x140768a80)

    void Reset();                                   // 0x140768770
    void Write(COutputStream& out);                 // 0x1407687f0
    void Read(CInPacket& packet);                   // 0x1407688c0

    __int64 m_nId;                                  // +0x18
    CStringW m_strName;                             // +0x20
    CString m_strText;                              // +0x28
    int m_nFlag;                                    // +0x30 (one byte on the wire)
    int m_pad_34;
    __int64 m_nValue;                               // +0x38
    int m_nCount;                                   // +0x40
    int m_pad_44;
};
MS2_CHECK_SIZE(CRankUgcMarketBuy, 0x48);
MS2_CHECK_OFFSET(CRankUgcMarketBuy, m_strName, 0x20);
MS2_CHECK_OFFSET(CRankUgcMarketBuy, m_nValue, 0x38);

// RTTI RankingArenaData, 0x38 bytes: one gradeInfo row of pvpRankingDuelMode.xml.
class RankingArenaData : public CPtred
{
public:
    RankingArenaData();                             // 0x140768ac0
    virtual ~RankingArenaData();                    // 0x140768b50 (??_G 0x1407692a0)
    RankingArenaData& operator=(const RankingArenaData& o);     // 0x140769130

    int m_nGrade;                                   // +0x18 grade
    int m_nGradeRating;                             // +0x1c gradeRating (the lowest rating of the grade)
    int m_nWinnerReward;                            // +0x20 winnerReward
    int m_nLoserReward;                             // +0x24 loserReward
    int m_nWeeklyRewardMax;                         // +0x28 weeklyRewardMax
    int m_nWinnerRating;                            // +0x2c winnerRating
    int m_nLoserRating;                             // +0x30 loserRating
    int m_pad_34;
};
MS2_CHECK_SIZE(RankingArenaData, 0x38);

// RTTI CRankingArenaDataTable, 0x1d0 bytes: TSingleton at +0, CValidData at +8; the grades 1..7 (0 is unused).
class CRankingArenaDataTable : public TSingleton<CRankingArenaDataTable>, public CValidData<CRankingArenaDataTable>
{
public:
    CRankingArenaDataTable();                       // 0x140768b80
    virtual ~CRankingArenaDataTable();              // 0x140768c10

    bool Load();                                    // 0x140768c90
    RankingArenaData* GetGrade(int nGrade);         // 0x140768fb0 (>= 8: grade 1)
    RankingArenaData* GetGradeOfRating(int nRating);    // 0x140769000
    static void CheckInit();                        // 0x1407692e0
    // @0x140769390
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;                            // DAT_143ab0e58

    RankingArenaData m_aGrades[8];                  // +0x10
};
MS2_CHECK_SIZE(CRankingArenaDataTable, 0x1d0);
MS2_CHECK_OFFSET(CRankingArenaDataTable, m_aGrades, 0x10);

// RTTI CRankViewer, 0x78 bytes: the two ranking lists (kind 0 and 1 of the ranking packet) behind a lock.
class CRankViewer : public TSingleton<CRankViewer>
{
public:
    CRankViewer();                                  // 0x1407694c0
    virtual ~CRankViewer();

    void ReadList(CInPacket& packet);               // 0x1407695c0
    void OnPacket(CInPacket& packet);               // 0x140769780
    ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> >* GetKind0List();
    ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> >* GetKind1List();

    CLockCriticalSection m_lock;                    // +0x08
    ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> > m_aKind0;    // +0x38
    ATL::CAtlArray<MS2Ptr<CRankUgcMarketBuy> > m_aKind1;    // +0x58
};
MS2_CHECK_SIZE(CRankViewer, 0x78);
MS2_CHECK_OFFSET(CRankViewer, m_lock, 0x8);
MS2_CHECK_OFFSET(CRankViewer, m_aKind0, 0x38);
MS2_CHECK_OFFSET(CRankViewer, m_aKind1, 0x58);
