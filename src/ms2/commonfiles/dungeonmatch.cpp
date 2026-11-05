// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dungeon match roles (Support/Tank: parse, from the job,
// as a string) and the item <dummy> attach node.
// MS2-UNIT: commonfiles\dungeonmatch.cpp
// MS2-RANGE: 0x1403142a0-0x140314830 .text$mn
// MS2-RANGE: 0x1400b5b10-0x1400b5c30 .text$di
// MS2-RANGE: 0x142c9a5e0-0x142c9a650 .text$yd
// The queue row's .text$mn range 0x1402e6c50-0x14031b800 is four TUs: the item drop tables (0x1402e6c50-0x1403142a0),
// this file, the DungeonMissionData classes (0x140314830-0x140318c80) and DungeonMissionDataTable (0x140318c80-
// 0x14031b800); each has its own source.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonmatch.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonmatch.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0

int XmlGetAttr(class TiXmlElement*, const char*, efd::Point3&);   // C3: was FUN_140874670 (0x140874670, xmlattr's Point3 reader)

// ---- statics of a shared header (sort names, skill, stun) ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// @0x1403142a0
ItemDummyInfo::ItemDummyInfo()
    : gender(2), rotation(0.0f, 0.0f, 0.0f), translation(0.0f, 0.0f, 0.0f), step(0.0003f), worldmode(false),
      worldlerp(false)
{
}

// @0x140314350
void ItemDummyInfo::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "gender", reinterpret_cast<int&>(gender));
    XmlGetAttr((class TiXmlElement*)(pElem), "sequence", sequence);
    XmlGetAttr((class TiXmlElement*)(pElem), "targetnode", targetnode);
    XmlGetAttr((class TiXmlElement*)(pElem), "worldmode", reinterpret_cast<bool&>(worldmode));
    XmlGetAttr((class TiXmlElement*)(pElem), "worldlerp", reinterpret_cast<bool&>(worldlerp));
    XmlGetAttr((class TiXmlElement*)(pElem), "step", reinterpret_cast<float&>(step));
    XmlGetAttr((class TiXmlElement*)(pElem), "rotation", reinterpret_cast<efd::Point3&>(rotation));
    XmlGetAttr((class TiXmlElement*)(pElem), "translation", reinterpret_cast<efd::Point3&>(translation));
}
MS2_REPLACE_METHOD(0x140314350, ItemDummyInfo, Load, 247, 0xAF1AC415);

// @0x140314450
void FUN_140314450(void* p1, void* p2, CString str)
{
}

// @0x140314480
void SetDungeonMatchRolesByJob(DungeonMatchRoles& roles, int nJob)
{
    switch (nJob)
    {
    case 10:
        roles.Set(DungeonMatchRole_Tank, true);
        break;
    case 40:
        roles.Set(DungeonMatchRole_Support, true);
        break;
    case 110:
        roles.Set(DungeonMatchRole_Support, true);
        break;
    }
}
MS2_REPLACE_OVERLOAD(0x140314480, void(DungeonMatchRoles&, int), SetDungeonMatchRolesByJob, 107, 0x809845EF);

// @0x140314500
CString GetDungeonMatchRolesString(const DungeonMatchRoles& roles)
{
    CString str;
    if (roles[DungeonMatchRole_Support])
        str += "S";
    if (roles[DungeonMatchRole_Tank])
        str += "T";
    return str;
}
MS2_REPLACE_OVERLOAD(0x140314500, CString(const DungeonMatchRoles&), GetDungeonMatchRolesString, 171, 0x58A07AF6);

// @0x1403145c0
DungeonMatchRole ParseDungeonMatchRole(const CString& str)
{
    if (str.IsEmpty())
        return DungeonMatchRole_None;
    if (str.CompareNoCase("Support") == 0)
        return DungeonMatchRole_Support;
    else if (str.CompareNoCase("Tank") == 0)
        return DungeonMatchRole_Tank;
    MS2_ASSERT_AT(15, 0);
    return DungeonMatchRole_None;
}
MS2_REPLACE_OVERLOAD(0x1403145C0, DungeonMatchRole(const CString&), ParseDungeonMatchRole, 130, 0xDA2139A6);
