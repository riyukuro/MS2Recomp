// dungeonroomshutdowncontext.h - PLACEHOLDER for DungeonRoomShutdownContext (RTTI .?AVDungeonRoomShutdownContext@@,
// 0x38 bytes). NOT an original header.
// Bases: CPtred at +0x0.
// The context GameEventDungeonRoomShutdown (gameevent.cpp) builds from its two XML values; its unit
// ?\dungeonroomshutdowncontext.cpp (0x140343e50..) is not recovered, so only the members gameevent.cpp calls are
// declared and the two id sets stay opaque.
#pragma once

#include <afx.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

enum Unk_DungeonGroupType;                                  // MSVC forward declaration; defined by the including unit

class DungeonRoomShutdownContext : public CPtred
{
public:
    DungeonRoomShutdownContext();                           // 0x140343e50
    void FUN_140343eb0(const CStringW& strXml);             // <dungeonRoom id=..> elements into the room id set (+0x18)
    void FUN_140343fc0(const CStringW& strXml);             // <dungeonGroup type=..> elements into the group set (+0x28)
    bool FUN_1403441a0();                                   // true if either set is non-empty
    bool FUN_1403440d0(unsigned nRoomId);                   // the room id is in the set
    bool FUN_140344140(Unk_DungeonGroupType eGroup);        // the group is in the set

    std::set<unsigned> m_roomIds;                           // +0x18
    std::set<Unk_DungeonGroupType> m_groups;                // +0x28
};
MS2_CHECK_SIZE(DungeonRoomShutdownContext, 0x38);
