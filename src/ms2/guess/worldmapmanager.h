// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldMapManager (RTTI .?AVWorldMapManager@@, 0xf8 bytes,
// base TSingleton<WorldMapManager>): the world map's data. It loads the tile layout (Table/worldmap.xml and the files it
// lists, worldMapFieldNameInfo.xml), builds the field search index, keeps the per-field icon records the server sends
// (special npcs, additional info, dungeons, event icons) and fills the AS objects of the world map's search panel.
// ctor 0x141b95380 (created by CGameApp::InitInstance), dtor 0x141b954d0, ??_G 0x141bb0340. Layout from the ctor/dtor
// and the v2525 snapshot (work/ext/v2525 include/ms2/WorldMapManager.h, same layout); method names are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiworldmap.h"
#include "ms2/placeholder/specialnpcinfo.h"

class ASObj;
class CCacheData;
class CInPacket;
class EventIconInfo;
template <class T> class Unk_BmBoxPtr;                 // blackmarketitemoption.h (included by the unit)

class WorldMapManager : public TSingleton<WorldMapManager>
{
public:
    typedef std::vector<MS2Ptr<UIWorldMap::MapTile> > TileVector;
    typedef std::map<int, TileVector> TileGroups;

    WorldMapManager();                                                          // 0x141b95380
    virtual ~WorldMapManager();                                                 // 0x141b954d0

    int LoadWorldMapFiles();                                                    // 0x141b95640
    int LoadFieldTiles();                                                       // 0x141b96690 the field search index
    int LoadFieldNameInfo();                                                    // 0x141b96930
    void PollChangedFiles();                                                    // 0x141b96d90 reload changed tables
    void LoadWorldMapNames(ATL::CAtlArray<CString>& names);                     // 0x141b96f10
    void LoadIconPacket(CInPacket* packet);                                     // 0x141b970f0
    void LoadSpecialNpcs(CInPacket* packet);                                    // 0x141b971a0
    void LoadAddtionalInfos(CInPacket* packet);                                 // 0x141b97680
    TileVector& GetWorldTiles(int world);                                       // 0x141b977e0
    TileGroups& GetTileGroups();                                                // 0x141b978c0
    MS2Ptr<UIWorldMap::MapTile> FindMapTileByKey(unsigned key);                 // 0x141b978e0
    std::set<int>& GetPortalFields();                                           // 0x141b979b0
    std::map<unsigned, MS2Ptr<UIWorldMap::FieldSearchInfo> >& FieldSearchInfos();   // 0x141b979d0
    MS2Ptr<UIWorldMap::FieldSearchInfo> FindFieldSearchInfo(CStringW name);     // 0x141b979f0
    void ClearIconInfos();                                                      // 0x141b97b50
    void SetIconInfo(unsigned id, MS2Ptr<UIWorldMap::IconInfo> info);           // 0x141b97b90
    MS2Ptr<UIWorldMap::IconInfo> GetOrAddIconInfo(unsigned id);                 // 0x141b97bf0
    void ClearAddtionalInfos();                                                 // 0x141b97d30
    void SetAddtionalInfo(unsigned id, MS2Ptr<UIWorldMap::AddtionalInfo> info); // 0x141b97d60
    MS2Ptr<UIWorldMap::AddtionalInfo> GetOrAddAddtionalInfo(unsigned id);       // 0x141b97dc0
    void SelectFieldTile(unsigned key);                                         // 0x141b97f00
    int SelectedField();                                                        // 0x141b97fe0
    MS2Ptr<UIWorldMap::MapTile> FindMapTile(int id);                            // 0x141b98000 the default tile of a map
    void ClearIconInfoTooltips();                                               // 0x141b980d0
    void ClearDungeonInfos();                                                   // 0x141b98180
    void ClearAddtionalInfoTooltips();                                          // 0x141b98250
    int WorldOfField(int field);                                                // 0x141b98300
    bool HasFieldSearchInfo(unsigned id);                                       // 0x141b98380
    void AddSpecialNpc(Unk_BmBoxPtr<SpecialNPCInfo> info);                      // 0x141b983f0
    int BuildFieldSearch(unsigned field, ASObj* script, bool mission);         // 0x141b98440
    int BuildNameSearch(CStringW search, ASObj* script);                        // 0x141b984a0
    void BuildNpcRewardPreview(int npc, ASObj* script);                         // 0x141b99dc0
    void SetDungeonScript(MS2Ptr<UIWorldMap::IconInfo> info, ASObj* script, int variant);   // 0x141b9a1e0
    void SetEventIconInfo(unsigned id, MS2Ptr<EventIconInfo> info);             // 0x141b9a300
    void RemoveEventIconInfo(unsigned id);                                      // 0x141b9a360
    void SetEventScript(unsigned id, ASObj* script);                            // 0x141b9a390
    CStringW NpcSearchName(int npc, int field);                                 // 0x141b9a560
    int BuildFieldDetails(unsigned field, ASObj* script);                       // 0x141b9a9f0
    int BuildMissionSearch(unsigned field, ASObj* script);                      // 0x141b9bf10

private:
    MS2_LAYOUT_FRIEND;
    std::set<int> m_8;                                                          // +0x08 the portal fields
    TileGroups m_18;                                                            // +0x18 the tiles of each world
    std::map<int, MS2Ptr<UIWorldMap::IconInfo> > m_28;                          // +0x28 field -> icons
    std::map<int, MS2Ptr<UIWorldMap::AddtionalInfo> > m_38;                     // +0x38 field -> additional info
    std::map<unsigned, MS2Ptr<UIWorldMap::MapTile> > m_48;                      // +0x48 tile key -> tile
    std::map<int, MS2Ptr<UIWorldMap::MapTile> > m_58;                           // +0x58 map -> default tile
    std::map<unsigned, MS2Ptr<UIWorldMap::FieldSearchInfo> > m_68;              // +0x68 field -> search info
    int m_78;                                                                   // +0x78 the selected tile key
    ATL::CAtlMap<int, Unk_BmBoxPtr<SpecialNPCInfo> > m_80;                      // +0x80 npc -> special npc
    std::map<unsigned, MS2Ptr<EventIconInfo> > m_c8;                            // +0xc8 field -> event icon
    ATL::CAtlArray<MS2Ptr<CCacheData> > m_d8;                                   // +0xd8 the loaded tables
};
MS2_CHECK_SIZE(WorldMapManager, 0xf8);
MS2_CHECK_OFFSET(WorldMapManager, m_18, 0x18);
MS2_CHECK_OFFSET(WorldMapManager, m_78, 0x78);
MS2_CHECK_OFFSET(WorldMapManager, m_80, 0x80);
MS2_CHECK_OFFSET(WorldMapManager, m_c8, 0xc8);
MS2_CHECK_OFFSET(WorldMapManager, m_d8, 0xd8);
