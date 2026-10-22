// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). RoomStageDungeonCli: the client's state of the dungeon room
// it stands in (room data, the missions' progress read from packet 0x100), plus the std::vector / Delegate glue over its
// members.
// MS2-UNIT: client\ms2\roomstagedungeoncli.cpp
// MS2-RANGE: 0x140c9cc60-0x140c9f7a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140c9e750 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c9f4c0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140c9f610 ; unique
// MS2-PIN: ??$Call@VRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x140c9f640 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVRoomStageDungeonCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c9f670 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\roomstagedungeoncli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <iterator>
#include "roomstagedungeoncli.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/ms2recover.h"

// Out-of-unit helpers.
class Unk_McPackets
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> handler);
};
Unk_McPackets* FUN_140bccd50();
CStringW FUN_140298ea0(CStringW);
void FUN_1412751b0(const CStringW&, int);

// @0x140c9d950
template <class T>
static void AppendAll(const std::vector<T>& src, std::vector<T>& dst)
{
    std::copy(src.begin(), src.end(), std::back_inserter(dst));
}

// @0x140c9cc60
RoomStageDungeonCli::RoomStageDungeonCli(unsigned nRoomId, int nStage)
    : m_nStage(nStage)
{
    m_spRoom = DungeonRoomTable::GetInstance()->GetRoom(nRoomId);
    FUN_140bccd50()->FUN_140da5180(0x100, Delegate<void(CInPacket&)>(this, &RoomStageDungeonCli::OnPacket));
}

// @0x140c9cda0
RoomStageDungeonCli::~RoomStageDungeonCli()
{
    FUN_140bccd50()->FUN_140da51e0(0x100, Delegate<void(CInPacket&)>(this, &RoomStageDungeonCli::OnPacket));
}

// @0x140c9ce60
void RoomStageDungeonCli::SetFlag(bool bFlag)
{
    m_bFlag = bFlag;
}

// @0x140c9ce80
void RoomStageDungeonCli::GetMissions(std::vector<MS2Ptr<DungeonMissionCli> >& out)
{
    AppendAll(m_missions, out);
}

// @0x140c9ceb0
int RoomStageDungeonCli::GetScore()
{
    int nScore = 0;
    for (std::vector<MS2Ptr<DungeonMissionCli> >::iterator it = m_missions.begin(); it != m_missions.end(); it++)
        nScore += (*it)->GetScore();
    return nScore;
}

// @0x140c9cf50
int RoomStageDungeonCli::GetMaxScore()
{
    int nScore = 0;
    for (std::vector<MS2Ptr<DungeonMissionCli> >::iterator it = m_missions.begin(); it != m_missions.end(); it++)
        nScore += (*it)->GetMaxScore();
    return nScore;
}

// @0x140c9cff0
int RoomStageDungeonCli::GetRank()
{
    if (m_spRoom == 0)
        return 0;
    return m_spRoom->GetRank(GetScore());
}

// @0x140c9d050
int RoomStageDungeonCli::GetStage()
{
    return m_nStage;
}

// @0x140c9d070
MS2Ptr<DungeonRoom> RoomStageDungeonCli::GetRoom()
{
    return m_spRoom;
}

// @0x140c9d0c0
void RoomStageDungeonCli::OnPacket(CInPacket& packet)
{
    int nMode = packet.ReadUInt8();
    switch (nMode)
    {
    case 0:
        OnInitMissions(packet);
        break;
    case 1:
        OnUpdateMissions(packet);
        break;
    case 2:
        OnSyncMissions(packet);
        break;
    case 3:
        OnStage(packet);
        break;
    case 4:
        OnFlag(packet);
        break;
    case 5:
        OnGiveUp(packet);
        break;
    }
}

// @0x140c9d1b0
void RoomStageDungeonCli::OnInitMissions(CInPacket& packet)
{
    m_missions.clear();
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        int nId = packet.ReadInt32();
        MS2Ptr<DungeonMissionCli> miCli = DungeonMissionCli::Create(nId);
        MS2_ASSERT_AT(0x68, miCli);
        if (miCli == 0)
            break;
        miCli->vfunc_2(packet);
        m_missions.push_back(miCli);
    }
}

// @0x140c9d320
void RoomStageDungeonCli::OnUpdateMissions(CInPacket& packet)
{
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        int nId = packet.ReadInt32();
        MS2Ptr<DungeonMissionCli> miCli = FindMission(nId);
        if (miCli == 0)
        {
            MS2_ASSERT_AT(0x7b, 0);
            return;
        }
        miCli->vfunc_2(packet);
    }
}

// @0x140c9d460
void RoomStageDungeonCli::OnSyncMissions(CInPacket& packet)
{
    unsigned nCount = packet.ReadInt32();
    if (m_missions.size() != nCount)
    {
        MS2_ASSERT_AT(0x88, 0);
        return;
    }
    for (unsigned i = 0; i < nCount; i++)
    {
        int nId = packet.ReadInt32();
        if (m_missions[i]->GetId() != nId)
        {
            MS2_ASSERT_AT(0x91, 0);
            return;
        }
        m_missions[i]->vfunc_2(packet);
    }
}

// @0x140c9d5d0
void RoomStageDungeonCli::OnStage(CInPacket& packet)
{
    m_nStage = packet.ReadUInt8();
}

// @0x140c9d620
void RoomStageDungeonCli::OnFlag(CInPacket& packet)
{
    m_bFlag = packet.ReadBool();
}

// @0x140c9d670
void RoomStageDungeonCli::OnGiveUp(CInPacket&)
{
    FUN_1412751b0(FUN_140298ea0(CStringW(L"s_party_notify_dungeon_giveup")), 0x14);
}

// @0x140c9d6f0
bool RoomStageDungeonCli::IsStageFlagSet()
{
    if (m_nStage != 0)
        return false;
    if (m_bFlag == 0)
        return false;
    return true;
}

// @0x140c9d720
MS2Ptr<DungeonMissionCli> RoomStageDungeonCli::FindMission(int nId)
{
    for (unsigned i = 0; i < m_missions.size(); i++)
    {
        if (m_missions[i]->GetId() == nId)
            return m_missions[i];
    }
    return MS2Ptr<DungeonMissionCli>(0);
}
