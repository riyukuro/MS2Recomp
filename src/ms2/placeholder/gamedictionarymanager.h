// gamedictionarymanager.h - PLACEHOLDER for GameDictionaryManager (RTTI .?AVGameDictionaryManager@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<GameDictionaryManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It loads the three web-finder tables
// (Table/monsterWebfinder_Npc.xml, monsterWebfinder_Mob.xml, itemWebfinder.xml) into CRBMaps of id -> entry
// (?\gamedictionarymanager.cpp, 0x1403b72d0-0x1403ba180). Method and member names are invented.
#pragma once

#include <atlcoll.h>
#include <list>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/tptrvalue.h"

class Unk_140165cf0;    // game TinyXML element (ms2/placeholder/xmlattr.h)

// One <key> row of a web-finder table (RTTI TPtredDummy<struct GameDictionaryData>; ctor 0x1403b86f0 zeroes all five).
struct GameDictionaryData
{
    GameDictionaryData() : m_id(0), m_level(0), m_grade(0), m_invisibleLevel(0), m_fieldId(0) {}
    unsigned m_id;              // +0x00 "id"
    int m_level;                // +0x04 set by SetMobLevel (not in the xml)
    int m_grade;                // +0x08 "grade"
    int m_invisibleLevel;       // +0x0c "invisibleLevel"
    unsigned m_fieldId;         // +0x10 "FieldID"
};
MS2_CHECK_SIZE(GameDictionaryData, 0x14);

class GameDictionaryManager : public TSingleton<GameDictionaryManager>
{
public:
    typedef TPtrValue<GameDictionaryData> DataPtr;
    typedef ATL::CRBMap<int, DataPtr> DataMap;
    enum { kNpc = 1, kMob = 2, kItem = 3 };     // the table selector of GetAll / Get

    GameDictionaryManager();                                // 0x1403b72d0
    virtual ~GameDictionaryManager();                       // 0x1403b7360
    void LoadAll();                                         // 0x1403b73c0
    void LoadNpc();                                         // 0x1403b7400
    void LoadMob();                                         // 0x1403b75f0
    void LoadItem();                                        // 0x1403b77e0
    void LoadEntry(DataMap& map, Unk_140165cf0* pElem);     // 0x1403b79d0: rows with value="0" are skipped
    std::list<DataPtr> GetAll(int nType);                   // 0x1403b7af0: the non-null entries of one table
    DataPtr Get(int nType, int nId);                        // 0x1403b7c40
    void SetMobLevel(int nId, int nLevel);                  // 0x1403b7d30

    DataMap m_npcs;             // +0x08 kNpc
    DataMap m_mobs;             // +0x38 kMob
    DataMap m_items;            // +0x68 kItem
};
MS2_CHECK_OFFSET(GameDictionaryManager, m_npcs, 0x8);
MS2_CHECK_OFFSET(GameDictionaryManager, m_mobs, 0x38);
MS2_CHECK_OFFSET(GameDictionaryManager, m_items, 0x68);
MS2_CHECK_SIZE(GameDictionaryManager, 0x98);
