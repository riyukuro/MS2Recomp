// mentoringdatatable.h - MentoringDataTable (RTTI .?AVMentoringDataTable@@, 0x38 bytes): the mentoring rewards read from
// Table/MentoringConfig.xml (attendance reward coins, the daily coin caps, the icon flag). Header name assumed (the unit is
// commonfiles\mentoringdatatable.cpp); member and method names are invented from use.
// Bases: TSingleton<MentoringDataTable> at +0x0. Created by CGameApp::InitInstance (?\ms2.cpp).
#pragma once

#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;                                        // the tinyxml element wrapper

class MentoringDataTable : public TSingleton<MentoringDataTable>
{
public:
    MentoringDataTable();                                   // 0x14069bcb0
    virtual ~MentoringDataTable();

    bool Init();                                            // 0x14069bd60
    bool Load();                                            // 0x14069bd90
    void LoadConfig(Unk_140165cf0* pConfig);                // 0x14069bf00
    unsigned int GetAttendRewardCoin(short nDay);           // 0x14069bff0
    void GetAttendRewardCoins(std::vector<unsigned int>& rOut);      // 0x14069c070 (appends)
    unsigned int GetRewardableCoin(unsigned int nCoin, unsigned int nTodayCoin, bool bMentee);   // 0x14069c0a0
    unsigned int GetMaxMenteeDailyRewardCoin();             // 0x14069c120
    unsigned int GetMaxMentorDailyRewardCoin();             // 0x14069c140

private:
    MS2_LAYOUT_FRIEND;
    int m_nMentorRewardCoin;                                // +0x8
    int m_pad_c;
    std::vector<unsigned int> m_attendRewardCoins;          // +0x10
    unsigned int m_nMaxMentorDailyRewardCoin;               // +0x28
    unsigned int m_nMaxMenteeDailyRewardCoin;               // +0x2c
    bool m_bShowIcon;                                       // +0x30
};
MS2_CHECK_SIZE(MentoringDataTable, 0x38);
