// roomstagedungeoncli.h - RoomStageDungeonCli (RTTI .?AVRoomStageDungeonCli@@): the client's state of the dungeon room it
// stands in: the DungeonRoom data, the progress of the room's missions (DungeonMissionCli per mission, read from packet
// 0x100) and two result fields. Created by CMyCharacter (?\notifydebugstate.cpp) on entering a dungeon room. Owning
// unit: client\ms2\roomstagedungeoncli.cpp (0x140c9cc60-0x140c9f7a0). Member names are invented; NOT an original header.
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/dungeonmissioncli.h"

class CInPacket;

class RoomStageDungeonCli : public CPtred
{
public:
    RoomStageDungeonCli(unsigned nRoomId, int nStage);                          // 0x140c9cc60 registers packet handler 0x100
    virtual ~RoomStageDungeonCli();                                             // 0x140c9cda0 unregisters it
    void SetFlag(bool bFlag);                                             // 0x140c9ce60
    void GetMissions(std::vector<MS2Ptr<DungeonMissionCli> >& out);             // 0x140c9ce80 appends the missions
    int GetScore();                                                             // 0x140c9ceb0 sum over the missions
    int GetMaxScore();                                                          // 0x140c9cf50
    int GetRank();                                                              // 0x140c9cff0 0 without room data
    int GetStage();                                                             // 0x140c9d050
    MS2Ptr<DungeonRoom> GetRoom();                                              // 0x140c9d070
    bool IsStageFlagSet();                                                      // 0x140c9d6f0 stage 0 and the flag
    MS2Ptr<DungeonMissionCli> FindMission(int nId);                             // 0x140c9d720

private:
    void OnPacket(CInPacket& packet);                                           // 0x140c9d0c0 dispatch on the mode byte
    void OnInitMissions(CInPacket& packet);                                     // 0x140c9d1b0 mode 0
    void OnUpdateMissions(CInPacket& packet);                                   // 0x140c9d320 mode 1
    void OnSyncMissions(CInPacket& packet);                                 // 0x140c9d460 mode 2
    void OnStage(CInPacket& packet);                                            // 0x140c9d5d0 mode 3
    void OnFlag(CInPacket& packet);                                             // 0x140c9d620 mode 4
    void OnGiveUp(CInPacket& packet);                                           // 0x140c9d670 mode 5

    MS2_LAYOUT_FRIEND;
    MS2Ptr<DungeonRoom> m_spRoom;                                               // +0x18
    int m_nStage;                                                               // +0x28
    bool m_bFlag;                                                               // +0x2c
    std::vector<MS2Ptr<DungeonMissionCli> > m_missions;                         // +0x30
};
MS2_CHECK_SIZE(RoomStageDungeonCli, 0x48);
MS2_CHECK_OFFSET(RoomStageDungeonCli, m_spRoom, 0x18);
MS2_CHECK_OFFSET(RoomStageDungeonCli, m_nStage, 0x28);
MS2_CHECK_OFFSET(RoomStageDungeonCli, m_bFlag, 0x2c);
MS2_CHECK_OFFSET(RoomStageDungeonCli, m_missions, 0x30);
