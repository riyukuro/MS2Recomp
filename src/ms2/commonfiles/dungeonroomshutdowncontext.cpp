// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DungeonRoomShutdownContext (RTTI name), the context
// GameEventDungeonRoomShutdown builds from its two XML value strings: the dungeon room ids (<dungeonRoom id=..>) and the
// dungeon group types (<dungeonGroup type=..>). The unit is the class plus the std::set<Unk_DungeonGroupType> glue
// (std::set<unsigned> glue is shared with commonfiles\dungeonmatch.cpp).
// MS2-UNIT: ?\dungeonroomshutdowncontext.cpp
// MS2-RANGE: 0x140343e50-0x140346f60 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_GDungeonRoomShutdownContext@@UEAAPEAXI@Z 0x140345b00
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonroomshutdowncontext.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/dungeonroomshutdowncontext.h"

#include "ms2/placeholder/dungeongrouptype.h"

// Out-of-unit helpers.
int FUN_140179060(Unk_140165cf0* pElem, const char* pszName, Unk_DungeonGroupType& eOut);   // enum attribute by name
Unk_140165cf0* FUN_14086e860(TiXmlDocument* pDoc);                                         // first child element

// @0x140345b40
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc)
{
    return FUN_14086e860(pDoc);
}

// @0x140343e50
DungeonRoomShutdownContext::DungeonRoomShutdownContext()
{
}

// @0x140343eb0
void DungeonRoomShutdownContext::FUN_140343eb0(const CStringW& strXml)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strXml) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("dungeonRoom"); pNode != 0;
         pNode = pNode->FUN_140168650("dungeonRoom"))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        if (nId != 0)
            m_roomIds.insert(nId);
    }
}

// @0x140343fc0
void DungeonRoomShutdownContext::FUN_140343fc0(const CStringW& strXml)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strXml) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("dungeonGroup"); pNode != 0;
         pNode = pNode->FUN_140168650("dungeonGroup"))
    {
        Unk_DungeonGroupType eType = Unk_DungeonGroupType_None;
        FUN_140179060(pNode, "type", eType);
        if (eType != 0)
            m_groups.insert(eType);
    }
}

// @0x1403440d0
bool DungeonRoomShutdownContext::FUN_1403440d0(unsigned nRoomId)
{
    if (m_roomIds.find(nRoomId) != m_roomIds.end())
        return 1;
    return 0;
}

// @0x140344140
bool DungeonRoomShutdownContext::FUN_140344140(Unk_DungeonGroupType eGroup)
{
    return m_groups.find(eGroup) != m_groups.end();
}

// @0x1403441a0
bool DungeonRoomShutdownContext::FUN_1403441a0()
{
    if (!m_roomIds.empty())
        return 1;
    if (!m_groups.empty())
        return 1;
    return 0;
}

// @0x140346e40
MS2_EMIT_CRT_MEMMOVE_S();
