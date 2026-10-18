// cpvprankduelcomponent.h - PLACEHOLDER for CPvpRankDuelComponent (RTTI .?AVCPvpRankDuelComponent@@, 0x38 bytes, vftable
// 0x142e... with the destructor only) and RankDuelStatisticalData (RTTI .?AVRankDuelStatisticalData@@, 0x28 bytes,
// CPtred). NOT original headers; the member names are invented. Owning unit: ?\pvprankduelcomponent.cpp.
//
// The component is the rank-duel (ranked PvP arena) packet handler: OnMessage dispatches the server's rank-duel
// packets by opcode (matching state, own record, per-league records, the round banner of the arena).
#pragma once

#include <afx.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cinpacket.h"

// One record of the rank-duel statistics (per season/league key); read from the 0x17 packet.
class RankDuelStatisticalData : public CPtred
{
public:
    RankDuelStatisticalData();                                      // 0x140dc1390
    virtual ~RankDuelStatisticalData();                             // 0x140dc1500 (??_G 0x140dc1970)
    void FUN_14026b250(CInPacket& packet);                          // read the record

    MS2_LAYOUT_FRIEND;
    int m_key;                                                      // +0x18 map key
    int m_value1c;                                                  // +0x1c (summed into the component's +0x2c)
    int m_value20;                                                  // +0x20 (summed into the component's +0x30)
    bool m_flag24;                                                  // +0x24
};
MS2_CHECK_SIZE(RankDuelStatisticalData, 0x28);
MS2_CHECK_OFFSET(RankDuelStatisticalData, m_key, 0x18);
MS2_CHECK_OFFSET(RankDuelStatisticalData, m_flag24, 0x24);

class CPvpRankDuelComponent
{
public:
    CPvpRankDuelComponent();                                        // 0x140dbddc0
    virtual ~CPvpRankDuelComponent();                               // 0x140dbde10 (??_G 0x140dc1930)

    void SetState(int nState);                                      // 0x140dbde50
    void OnMessage(int nMessage, CInPacket& packet);                // 0x140dbde70
    void Reset();                                                   // 0x140dbf090
    void RefreshLeague();                                           // 0x140dbf110
    bool RequestCancelMatch();                                      // 0x140dbf160
    int CurrentRating();                                            // 0x140dbf260
    MS2Ptr<RankDuelStatisticalData> FindRecord(int nKey);           // 0x140dbf2a0

    MS2_LAYOUT_FRIEND;
    std::map<int, MS2Ptr<RankDuelStatisticalData> > m_records;      // +0x08 (the key is the record's m_key)
    int m_state;                                                    // +0x18 0 idle, 1 queued, 2 matched
    int m_league;                                                   // +0x1c
    int m_value20;                                                  // +0x20 rating (1000 by default)
    int m_value24;                                                  // +0x24 1000 by default
    int m_value28;                                                  // +0x28
    int m_total2c;                                                  // +0x2c sum of the records' +0x1c
    int m_total30;                                                  // +0x30 sum of the records' +0x20
};
MS2_CHECK_SIZE(CPvpRankDuelComponent, 0x38);
MS2_CHECK_OFFSET(CPvpRankDuelComponent, m_records, 0x08);
MS2_CHECK_OFFSET(CPvpRankDuelComponent, m_state, 0x18);
MS2_CHECK_OFFSET(CPvpRankDuelComponent, m_total30, 0x30);
