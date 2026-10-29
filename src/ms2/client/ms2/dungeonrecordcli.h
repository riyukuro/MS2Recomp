// dungeonrecordcli.h - the client's dungeon records (DungeonRecordCli, a DungeonRecord with client-side counters) and the
// manager that owns them (DungeonRecordManagerCli, RTTI): the room-id -> record table, the rank reward table, the
// reward-boost state and the packet handlers that feed them. Owning unit: client\ms2\dungeonrecordcli.cpp
// (0x140b206b0-0x140b26ff0). Method names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/dungeonrecord.h"
#include "ms2/commonfiles/dungeonroom.h"

class CInPacket;
class CInputStream;

// RTTI DungeonRecordCli, 0x88 bytes (no members of its own).
class DungeonRecordCli : public DungeonRecord
{
public:
    DungeonRecordCli();                                     // 0x140b206b0
    DungeonRecordCli(unsigned nRoomID);                     // 0x140b206f0 also resolves the room
    // dtor 0x140b244e0 implicit

    unsigned GetBonusRewardCountNow();                        // 0x140b20750
    int GetMaxCount();                                      // 0x140b20780 the room's reward count (+ the bonus count while not expired)
    unsigned GetExtraCountNow();                            // 0x140b207f0
    long Get5c();                                           // 0x140b20820
    int GetBonusCountNow();                                 // 0x140b20840 0 once expired
    __int64 GetExpire();                                    // 0x140b20880
    short Get60();                                          // 0x140b208a0
    short Get68(__int64 tNow);                              // 0x140b208c0
    bool HasCountLeft();                                    // 0x140b208f0
    bool IsExtraExhausted();                                // 0x140b20990 the extra count reached the event's reward count
    unsigned short GetRaw68();                              // 0x140b20a40
    bool IsExpired();                                       // 0x140b20a60
};
MS2_CHECK_SIZE(DungeonRecordCli, 0x88);

typedef MS2Ptr<DungeonRecordCli> DungeonRecordCliPtr;
typedef MS2Ptr<DungeonRankReward> DungeonRankRewardPtr;

// RTTI DungeonRecordManagerCli, 0xa8 bytes.
class DungeonRecordManagerCli : public CPtred
{
public:
    DungeonRecordManagerCli();                              // 0x140b20aa0
    // dtor 0x140b24500 implicit

    size_t GetRecordCount();                                // 0x140b20b70
    void Clear();                                           // 0x140b20ba0
    void OnPacket(CInPacket& packet);                       // 0x140b20be0 by the sub-command byte
    void OnRecords(CInPacket& packet);                      // 0x140b20d40 cmd 5: all records
    void OnAddRecord(CInPacket& packet);                    // 0x140b20d90 cmd 6
    void OnRewardNotice(CInPacket& packet);                 // 0x140b20e80 cmd 7
    void OnClosingPhoto(CInPacket& packet);                 // 0x140b21150 cmd 10
    void OnOpenDialog(CInPacket& packet);                   // 0x140b21190 cmd 11
    void OnAddRecordExtra(CInPacket& packet);               // 0x140b211c0
    void OnError(CInPacket& packet);                        // 0x140b21310 cmd 0x12
    void OnRewards(CInPacket& packet);                      // 0x140b21f90 cmd 0x13: all rank rewards
    void OnAddReward(CInPacket& packet);                    // 0x140b21fe0 cmd 0x14
    void OnBoostState(CInPacket& packet);                   // 0x140b220a0 cmd 0x16
    void OnRates(CInPacket& packet);                        // 0x140b22100
    DungeonRecordCliPtr GetRecord(unsigned nRoomID);        // 0x140b22160 creates a missing record
    bool CanEnter(unsigned nRoomID);                        // 0x140b22290
    bool HasProgress(unsigned nRoomID);                     // 0x140b22320
    bool CanClaimHelperReward(unsigned nRoomID);            // 0x140b223d0
    bool IsBoostActive();                                   // 0x140b22530
    bool IsSeasonRoom(unsigned nRoomID);                    // 0x140b225a0
    float GetRateA();                                       // 0x140b22620
    float GetRateB();                                       // 0x140b22640
    short GetRoomScore60(unsigned nRoomID);                 // 0x140b22660
    unsigned short GetRoomScore68(unsigned nRoomID);        // 0x140b226f0
    int GetTotalScore();                                    // 0x140b22780
    long GetRoomValue5c(unsigned nRoomID);                  // 0x140b22890
    int GetRankRewardCount(unsigned nRank);                 // 0x140b22910
    void GetScoredRecords(std::vector<DungeonRecordCliPtr>& out);   // 0x140b229c0
    unsigned GetExtraTicketCost(DungeonRoomPtr pRoom);      // 0x140b22aa0
    int GetRoomBonusCount(unsigned nRoomID);                // 0x140b22b40
    void GetSeasonRooms(std::vector<DungeonRoomPtr>& out);  // 0x140b22bc0
    void ShowLackExtraTicket(unsigned nRoomID);             // 0x140b22cb0

    ATL::CRBMap<unsigned, DungeonRecordCliPtr> m_records;   // +0x18 room id -> record
    ATL::CAtlMap<unsigned, DungeonRankRewardPtr> m_rewards; // +0x48 rank -> reward
    unsigned __int64 m_90;                                  // +0x90 boost expiry
    __int64 m_98;                                           // +0x98 boost owner
    float m_a0;                                             // +0xa0
    float m_a4;                                             // +0xa4
};
MS2_CHECK_SIZE(DungeonRecordManagerCli, 0xa8);
MS2_CHECK_OFFSET(DungeonRecordManagerCli, m_rewards, 0x48);
MS2_CHECK_OFFSET(DungeonRecordManagerCli, m_a0, 0xa0);
