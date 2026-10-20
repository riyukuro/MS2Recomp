// uiworldmap.h - PLACEHOLDER for the UIWorldMap namespace (the world map's data records): MapTile, DisplaySetting,
// IconInfo, AddtionalInfo (sic, RTTI spelling), DungeonInfo, FieldSearchInfo and TooltipEntry. All CPtred-derived records
// are owned by ?\worldmapmanager.cpp (0x141b94cb0-0x141bb1490: ctors, ??_G, vftables 0x142ffa038..0x142ffa088) and read
// by UIWorldMapDialog (?\uiworldmapdialog.cpp). Layouts from RTTI sizes, the ctors and the v2525 snapshot
// (work/ext/v2525 include/ms2/UIWorldMap/*.h, same layouts); member names are invented unless noted. NOT an original
// header. The dtors are implicit (each user TU emits its own COMDAT copy, e.g. ~DisplaySetting 0x141b688d0).
#pragma once

#include <utility>
#include <vector>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

template <class T> class MS2Ptr;
class CQuestData;
class DungeonRoom;

namespace UIWorldMap {

// A tooltip line of an icon or an additional info (0x18 bytes; the inline ctor 0x141b684b0 and the implicit dtor
// 0x141b688f0 are COMDATs of ?\uiworldmapdialog.cpp, which fills them in FUN_141b58670 / FUN_141b58830).
struct TooltipEntry
{
    TooltipEntry() : m_0(0), m_4(0), m_10(0) {}     // 0x141b684b0
    int m_0;                                // +0x00 the id (quest / npc), the duplicate key
    int m_4;                                // +0x04 kind (format strings 0x720..0x723; 1..5 quest states)
    CStringW m_8;                           // +0x08 the line
    short m_10;                             // +0x10
};
MS2_CHECK_SIZE(TooltipEntry, 0x18);

// A field (map) tile of the world map. RTTI .?AVMapTile@UIWorldMap@@, 0x80 bytes, vftable 0x142ffa038, ctor 0x141badd30
// (scalars zeroed, four CString), ??_G 0x141bb0300. MS2Ptr<MapTile> COMDATs are shared with other units (dtor
// 0x140cb1490 is tabcontentspetcollect's Unk_PcFieldInfo view).
class MapTile : public CPtred
{
public:
    MapTile();                              // 0x141badd30
    int FUN_141b94b90();                    // 0x141b94b90 the tile is shown (UIWorldMapDialog "createMap")

    int m_18;                               // +0x18 tile type
    int m_1c;                               // +0x1c
    bool m_20;                              // +0x20
    bool m_21;                              // +0x21
    int m_24;                               // +0x24
    int m_28;                               // +0x28
    int m_2c;                               // +0x2c
    int m_30;                               // +0x30
    unsigned m_34;                          // +0x34 the tile key (unsigned map key in WorldMapManager)
    int m_38;                               // +0x38
    CString m_40;                           // +0x40
    CString m_48;                           // +0x48
    unsigned m_50;                          // +0x50 distance to the current tile (unsigned compares)
    int m_54;                               // +0x54
    int m_58;                               // +0x58
    int m_5c;                               // +0x5c
    CString m_60;                           // +0x60
    int m_68;                               // +0x68
    int m_6c;                               // +0x6c
    int m_70;                               // +0x70 dungeon room id (UIWorldMapDialog "OnMouseClickTile")
    int m_74;                               // +0x74
    CString m_78;                           // +0x78
};
MS2_CHECK_SIZE(MapTile, 0x80);

// The display filter of the world map (embedded in UIWorldMapDialog at +0x1d8). RTTI .?AVDisplaySetting@UIWorldMap@@,
// 0x30 bytes, vftable 0x142ffa088, ctor 0x141b94fb0 (calls Reset), ??_G 0x141bb0200.
class DisplaySetting : public CPtred
{
public:
    DisplaySetting();                       // 0x141b94fb0
    void FUN_141b95000();                   // 0x141b95000 reset: 1, 1, 1, 0, 0
    int FUN_141b95080(MS2Ptr<CQuestData> spQuest);      // 0x141b95080 the quest passes the filter (UIWorldMapDialog)
    int FUN_141b95270(MS2Ptr<DungeonRoom> spRoom);      // 0x141b95270 the dungeon passes the filter (UIWorldMapDialog)
    int m_18[5];                            // +0x18 indexed (/Od imul) flags: [0..2] from the game option bytes
                                            //       +0x20..+0x22, [3] "displayProperQuest", [4] "displayProperDungeon"
};
MS2_CHECK_SIZE(DisplaySetting, 0x30);

// RTTI .?AVDungeonInfo@UIWorldMap@@, 0x20 bytes, vftable 0x142ffa058, ctor 0x141badca0. Embedded in IconInfo at +0x48.
class DungeonInfo : public CPtred
{
public:
    DungeonInfo();                          // 0x141badca0
    int m_18;                               // +0x18
    bool m_1c;                              // +0x1c
    bool m_1d;                              // +0x1d
};
MS2_CHECK_SIZE(DungeonInfo, 0x20);

// The icons of a field (boss, portals, party, buddies, quests). RTTI .?AVIconInfo@UIWorldMap@@, 0xc8 bytes, vftable
// 0x142ffa068, ctor 0x141b94ef0, ??_G 0x141bb02c0.
class IconInfo : public CPtred
{
public:
    struct Rect                             // ctor 0x141badbe0 (name invented)
    {
        Rect();                             // 0x141badbe0
        int m_0;                            // +0x00
        std::vector<int> m_8;               // +0x08
        int m_20;                           // +0x20
    };
    IconInfo();                             // 0x141b94ef0
    int m_18;                               // +0x18 the field id
    Rect m_20;                              // +0x20 the boss: +0x20 npc id, +0x28 channels, +0x40 kind (1 field boss, 2)
    DungeonInfo m_48;                       // +0x48
    std::vector<std::pair<CStringW, CStringW> > m_68;   // +0x68 portals (line, times line)
    std::vector<TooltipEntry> m_80;         // +0x80 the npc lines (FUN_141b58830)
    std::vector<std::pair<CStringW, CStringW> > m_98;   // +0x98 party members (name line, channel line)
    std::vector<std::pair<CStringW, CStringW> > m_b0;   // +0xb0 buddies (name line, channel line)
};
MS2_CHECK_SIZE(IconInfo, 0xc8);

// RTTI .?AVAddtionalInfo@UIWorldMap@@ (sic), 0x40 bytes, vftable 0x142ffa048, ctor 0x141badb80, ??_G 0x141bb0180.
class AddtionalInfo : public CPtred
{
public:
    struct IntPair                          // ctor 0x141bade80 (name invented)
    {
        IntPair();                          // 0x141bade80
        int m_0;
        int m_4;
    };
    // implicit ctor 0x141badb80 (`new AddtionalInfo()` zero-fills first: factory 0x141b9d8e0)
    int m_18;                               // +0x18
    IntPair m_1c;                           // +0x1c
    std::vector<TooltipEntry> m_28;         // +0x28 the quest lines (FUN_141b58670)
};
MS2_CHECK_SIZE(AddtionalInfo, 0x40);

// RTTI .?AVFieldSearchInfo@UIWorldMap@@, 0x30 bytes, vftable 0x142ffa078, ctor 0x141badcf0, ??_G 0x141bb0280.
class FieldSearchInfo : public CPtred
{
public:
    // implicit ctor 0x141badcf0 (`new FieldSearchInfo()` zero-fills first: factory 0x141b9d950)
    int m_18;                               // +0x18 the field id
    CStringW m_20;                          // +0x20 the display name (string table 3)
    int m_28;                               // +0x28 the mapped id
    int m_2c;                               // +0x2c
};
MS2_CHECK_SIZE(FieldSearchInfo, 0x30);

bool FUN_141b94e70(const TooltipEntry& a, const TooltipEntry& b);   // 0x141b94e70 the tooltip line order (UIWorldMapDialog sorts IconInfo::m_80)

}  // namespace UIWorldMap
// member offset checks specialise a global template, so they sit outside the namespace
MS2_CHECK_OFFSET(UIWorldMap::MapTile, m_40, 0x40);
MS2_CHECK_OFFSET(UIWorldMap::MapTile, m_50, 0x50);
MS2_CHECK_OFFSET(UIWorldMap::MapTile, m_70, 0x70);
MS2_CHECK_OFFSET(UIWorldMap::IconInfo, m_48, 0x48);
MS2_CHECK_OFFSET(UIWorldMap::IconInfo, m_98, 0x98);
