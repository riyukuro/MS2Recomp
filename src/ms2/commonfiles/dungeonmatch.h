// dungeonmatch.h - the dungeon match roles (Support/Tank) and the item "dummy" attach node. Owning unit:
// commonfiles\dungeonmatch.cpp (0x1403142a0-0x140314830). NOT an original header; the names are invented unless noted
// (the field names are the xml attribute names).
#pragma once
#include <afx.h>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/bitset.h"

class TiXmlElement;     // game TinyXML element

// An item's <dummy> attach node (read by the item data loader, 0x140543ca0). 0x38 bytes.
struct ItemDummyInfo
{
    ItemDummyInfo();                        // 0x1403142a0
    void Load(TiXmlElement* pElem);        // 0x140314350

    int gender;                             // +0x00
    CString sequence;                       // +0x08
    CString targetnode;                     // +0x10
    efd::Point3 rotation;                   // +0x18
    efd::Point3 translation;                // +0x24
    float step;                             // +0x30
    bool worldmode;                         // +0x34
    bool worldlerp;                         // +0x35
};
MS2_CHECK_SIZE(ItemDummyInfo, 0x38);

// The dungeon match roles (bit positions in DungeonMatchRoles).
enum DungeonMatchRole
{
    DungeonMatchRole_None = 0,
    DungeonMatchRole_Support = 1,
    DungeonMatchRole_Tank = 2,
};
typedef Unk_Bitset<3> DungeonMatchRoles;

void FUN_140314450(void* p1, void* p2, CString str);                    // 0x140314450 (empty)
void SetDungeonMatchRolesByJob(DungeonMatchRoles& roles, int nJob);     // 0x140314480
CString GetDungeonMatchRolesString(const DungeonMatchRoles& roles);     // 0x140314500 "S" / "T"
DungeonMatchRole ParseDungeonMatchRole(const CString& str);             // 0x1403145c0
