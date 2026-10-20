// gameeventmanagercli.h - GameEventManagerCli (RTTI .?AVGameEventManagerCli@@, 0x60 bytes). Recovered with
// client\ms2\gameeventmanagercli.cpp (0x140ceaa70..): the client's list of running game events, kept in sync by the
// game-event packet (0 = full list, 1 = add, 2 = remove, 3 = update) and announced through NotifyGameEventChanged.
// Method names follow the asserts (gameEvent->GetID()) and the v2525 snapshot; the rest are invented.
// Bases: TSingleton<GameEventManagerCli> at +0x0.
#pragma once

#include <map>
#include <atlcoll.h>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CInPacket;
class GameEvent;
template <class T> class MS2Ptr;

class GameEventManagerCli : public TSingleton<GameEventManagerCli>
{
public:
    GameEventManagerCli();                                  // 0x140ceaa70
    virtual ~GameEventManagerCli();                         // 0x140ceab00
    void Dispatch(CInPacket& packet);                       // 0x140ceab50
    void Clear();                                           // 0x140ceac00
    MS2Ptr<GameEvent> Find(int nId);                        // 0x140ceacd0
    bool IsEnabled(CStringW strName);                       // 0x140cead80 an event of that name is running
    void Packet0(CInPacket& packet);                        // 0x140ceae40 the full list
    void Packet1(CInPacket& packet);                        // 0x140ceaff0 added events
    void Packet2(CInPacket& packet);                        // 0x140ceb2a0 removed event ids
    void Packet3(CInPacket& packet);                        // 0x140ceb480 updated events
    bool Add(MS2Ptr<GameEvent> gameEvent);                  // 0x140ceb730
    void Remove(MS2Ptr<GameEvent> gameEvent);               // 0x140ceb880
    void Update(MS2Ptr<GameEvent> gameEvent);               // 0x140ceba50
    GameEvent* Create(CStringW strName);                    // 0x140cebb30 "GameEvent{0}Cli", else "GameEvent{0}"
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<int, MS2Ptr<GameEvent> > m_events;          // +0x08 id -> event
    std::map<CStringW, unsigned int> m_states;                 // +0x50 event name -> number of running events
};
MS2_CHECK_SIZE(GameEventManagerCli, 0x60);
