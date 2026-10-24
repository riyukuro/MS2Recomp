// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the guilddef.cpp COMDAT list (after
// commonfiles\guilddef.cpp#4): the std::map copy assignments of CGuildMemberRaid::raids (+0x18) and of
// CGuildStorage's item map (+0x18), each the map::operator= wrapper over _Tree::operator=.
// MS2-UNIT: unit_1404efc20
// MS2-RANGE: 0x1404efc20-0x1404efd80 .text$mn

#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\guilddef.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/commonfiles/guilddef_4.h"

using namespace guilddef4;

typedef std::map<unsigned long, int> Unk_GuildRaidMap;      // CGuildMemberRaid+0x18

template Unk_GuildRaidMap& Unk_GuildRaidMap::operator=(const Unk_GuildRaidMap&);
template MapStorage& MapStorage::operator=(const MapStorage&);
