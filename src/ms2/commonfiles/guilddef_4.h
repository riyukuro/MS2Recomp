// Guild definition COMDAT tail, part 4 (ctors/dtors/operator= of the guilddef.cpp containers and smart pointers).
// Container element types are recovered from the callers in guilddef.cpp#1..#3; record type names are invented.
#pragma once
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/commonfiles/guilddef_2.h"   // CGuildNpcShop, CGuildNpcShopMgr, CNpcShopProductProxy (rx2)
#include <atlcoll.h>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <vector>

class CSeasonData;   // only TPtr<CSeasonData>::~TPtr lives in this range (RTTI TPtredDummy<CRBMap<int,TPtr<CSeasonData>>>)

// {__int64, __int64, CStringW} record of CGuildStorage::CGuildStroageHistory (+0x18, +0x30): ctor 0x1404ee5f0, dtor 0x1404ef6a0.
struct Unk_GuildHistText {
    __int64 a=0;
    __int64 b=0;
    CStringW text=L"";
};
MS2_CHECK_SIZE(Unk_GuildHistText,0x18);

// Unk_GuildStrEntry (the CGuildInfo+0x170 map value) lives in guilddef_1.h.

namespace guilddef4 {
using GX = CGuildXmlData;
template<class T> using TP = Unk_PayloadPtr<T>;
using Hist = CGuildStorage::CGuildStroageHistory;

using MapEvent    = std::map<int,TP<GX::GuildEvent>>;
using MapProperty = std::map<int,TP<GX::GuildProperty>>;
using MapReward   = std::map<int,TP<GX::GuildRaidReward>>;
using MapSkill    = std::map<int,std::vector<TP<GX::GuildSkill>>>;
using MapRaid     = std::map<unsigned,TP<GX::GuildRaid>>;
using MapShop     = std::map<unsigned,TP<CGuildNpcShop>>;              // CGuildNpcShopMgr+0x18
using MapHouse    = std::map<std::pair<int,int>,TP<GX::GuildHouse>>;
using MapStorage  = std::map<std::pair<unsigned,int>,ItemEntity>;        // CGuildStorage+0x18
using MapNpc      = std::map<std::pair<Unk_GuildNpcKind,int>,TP<GX::GuildNpc>>;
using MapStorage2 = std::map<std::pair<__int64,int>,ItemEntity>;         // CGuildStorage+0x28 (key type inferred from size/sort order)
using SetNpcKind  = std::set<Unk_GuildNpcKind>;                          // CGuildXmlData::FUN_1404d7c20 out-parameter
using HistDeque   = std::deque<TP<Hist>>;                                // CGuildStorage+0x38
using SkillVec    = std::vector<TP<GX::GuildSkill>>;
using ProductVec  = std::vector<TP<CNpcShopProductProxy>>;               // CGuildNpcShop+0x30

using AtlStrMap     = ATL::CAtlMap<int,Unk_GuildStrEntry>;               // CGuildInfo+0x170
using AtlEventMap   = ATL::CAtlMap<int,TP<CGuildCustomEvent>>;           // CGuildInfo+0x280
using AtlSkillMap   = ATL::CAtlMap<int,TP<CGuildSkill>>;                 // CGuildInfo+0x238
using AtlNpcMap     = ATL::CAtlMap<Unk_GuildNpcKind,TP<CGuildNpc>>;      // CGuildInfo+0x2c8
using AtlLocalMap   = ATL::CAtlMap<__int64,__int64>;                     // local of CGuildInfo::FUN_1404d3400
using MemberRBMap   = ATL::CRBMap<CStringW,TP<CGuildMember>,ATL::CStringElementTraitsI<CStringW>>;   // CGuildInfo+0x320 (case-insensitive: _wcsicmp)
using GradeArray    = ATL::CAtlArray<TP<CGuildGrade>>;                   // CGuildInfo+0xa0
using HistArray     = ATL::CAtlArray<TP<Hist>>;                          // CGuildStorage+0x60
}
