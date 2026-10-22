// cmycharacter.h - PLACEHOLDER for CMyCharacter (the name comes from the packet Delegate template instance
// Delegate<void(CInPacket&)>::DelegateImpl<pair<CMyCharacter*, void (CMyCharacter::*)(CInPacket&)>>). The client's own
// character state singleton: the static at 0x143ab3350 (guard 0x143ab33e8, accessor FUN_140931510 in unit_14092f420),
// constructed by 0x140d9ee70, 0x98 bytes, no vftable. Its methods live in ?\notifydebugstate.cpp (0x140d9ee70..0x140da4da0);
// that unit also holds CChatEmoticonCli's ctor / dtor and the NotifyDebugState / NotifyDungeonEnterState notices.
// Member names are invented from use; NOT an original header.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/userproxy.h"

class CInPacket;
class DungeonRecordManagerCli;
class RoomStageDungeonCli;
class CChatEmoticonCli;

class CMyCharacter
{
public:
    CMyCharacter();                                                 // 0x140d9ee70
    ~CMyCharacter();                                                // 0x140d9efd0

    void FUN_140d9f040();                                           // register the packet 0xd9 handler
    void FUN_140d9f0c0();                                           // unregister it
    void FUN_140d9f140();                                           // reset the state
    void FUN_140d9f1c0(CInPacket& packet);                          // read the id -> time table
    void FUN_140d9f200(CInPacket& packet);                          // packet 0xd9: titles bit set, then a NotifyDebugState
    MS2Ptr<DungeonRecordManagerCli> GetRecord();                // the dungeon record manager
    void FUN_140d9f310(__int64 nExpire);                            // set the expire time, (re)start the main info UI timer
    void FUN_140d9f400(int nA, int nB, bool bFlag);                 // new room stage state
    void FUN_140d9f4b0();                                           // drop the room stage state
    MS2Ptr<RoomStageDungeonCli> GetStage();                    // the room stage state
    bool FUN_140d9f530(int nId);                                    // the id is in the table
    __int64 FUN_140d9f580(int nId);                                 // the time of the id, or 0
    bool FUN_140d9f5d0(int nIndex);                                 // title bit
    CStringW FUN_140d9f600(int nIndex);                             // title bit name suffix
    void FUN_140d9f710(CInPacket& packet);                          // read the id -> state map, then a NotifyDungeonEnterState
    unsigned FUN_140d9f880(int nId);                                // the state of the id, or 0
    MS2Ptr<CChatEmoticonCli> GetChatEmoticon();                       // the chat emoticon state

    MS2Ptr<DungeonRecordManagerCli> m_spRecord;                     // +0x00
    MS2Ptr<RoomStageDungeonCli> m_spStage;                          // +0x10
    __int64 m_nExpire;                                              // +0x20
    ATL::CAtlMap<int, __int64> m_times;                             // +0x28
    std::map<unsigned long, unsigned> m_states;                               // +0x70
    MS2Ptr<CChatEmoticonCli> m_spChatEmoticon;                      // +0x80
    Unk_UserProxyBits m_titles;                                     // +0x90
};
MS2_CHECK_SIZE(CMyCharacter, 0x98);
