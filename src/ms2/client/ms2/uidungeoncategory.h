// uidungeoncategory.h - the dungeon control center window (RTTI UIDungeonControlCenter) and the category table behind its
// tabs (RTTI UIDungeonCategoryTable, Table/dungeonCategory.xml; rows RTTI UIDungeonCategory).
// NOT an original header (the unit is ?\uidungeoncategory.cpp). Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/commonfiles/os.h"

class CInPacket;
class ASArray;
class Unk_DcRoom;

#include "ms2/placeholder/dclevelrange.h"

// A dungeon group type (attribute "groupType"; read through the enum attribute reader).
enum Unk_DcGroupType
{
};

// One <dungeonSubTab> of dungeonCategory.xml: its level range and the dungeon group types listed under it. 0x40 bytes.
class UIDungeonCategory : public CPtred
{
public:
    UIDungeonCategory();                                        // 0x140c08990
    virtual ~UIDungeonCategory();                               // 0x140c089f0

    Unk_DcLevelRange m_range;                                   // +0x18 attribute "level"
    ATL::CAtlArray<Unk_DcGroupType> m_groupTypes;               // +0x20 <dungeonCategory groupType=...>
};
MS2_CHECK_SIZE(UIDungeonCategory, 0x40);
MS2_CHECK_OFFSET(UIDungeonCategory, m_range, 0x18);
MS2_CHECK_OFFSET(UIDungeonCategory, m_groupTypes, 0x20);

// The category table: per main tab (0, 1) the sub tabs keyed by their lowest level. 0x70 bytes.
class UIDungeonCategoryTable : public TSingleton<UIDungeonCategoryTable>, public CValidData<UIDungeonCategoryTable>
{
public:
    typedef ATL::CRBMap<unsigned short, MS2Ptr<UIDungeonCategory> > Map;

    UIDungeonCategoryTable();                                   // 0x140c08a30
    virtual ~UIDungeonCategoryTable();                          // 0x140c08ad0

    void Load();                                                // 0x140c08b50
    void FUN_140c08ec0(int nTab, ATL::CAtlArray<MS2Ptr<UIDungeonCategory> >& out);   // the sub tabs of a main tab
    unsigned short FUN_140c08f50(int nTab);                     // the highest sub tab level
    int FUN_140c09030(int nTab, unsigned short nLevel);         // the sub tab of a level (else the last one)

    static void CheckInit();                                    // 0x140c09910
    static void SetInit(bool b);                                // 0x140c0ab90
    static bool s_bInit;                                        // 0x143abdff0

private:
    MS2_LAYOUT_FRIEND;
    Map m_maps[2];                                              // +0x10
};
MS2_CHECK_SIZE(UIDungeonCategoryTable, 0x70);
MS2_CHECK_OFFSET(UIDungeonCategoryTable, m_maps, 0x10);


// The dungeon control center window (UI id 0x4f84). 0x1d0 bytes.
class UIDungeonControlCenter : public UIDialog
{
public:
    typedef std::vector<MS2Ptr<Unk_DcRoom> > RoomVec;

    UIDungeonControlCenter();                                   // 0x140c0aea0
    virtual ~UIDungeonControlCenter();                          // 0x140c0af60
    virtual CString GetTypeName();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual int vfunc_53(void* pCfg);
    virtual int vfunc_54(void* pCfg);
    virtual int vfunc_48() { return 0x4f84; }

    void FUN_140c0ba70(std::set<unsigned int>& ids);            // take the bookmarked dungeons (swap)
    void FUN_140c0bab0();                                       // the weekly reward component
    void FUN_140c0c430();                                       // the find component (match state)
    void FUN_140c0c600(int nTab);                               // show a main tab
    void FUN_140c0c660(int bUpdate);                            // main tab 0: build or update the sub tab
    void FUN_140c0c8e0();                                       // main tab 1
    void OnSetting();                                       // open the search setting dialog
    void OnPartySearch();                                       // toggle the party search dialog
    void SendPartyMode32();                                       // request a party match
    void SendPartyMode34();                                       // cancel the party match
    void OnBookmark();                                       // bookmark list
    void OnPopupDetail();                                       // toggle the detail popup
    void FUN_140c0cdb0(int nId);                                // bookmark a dungeon
    void SendRoomDungeon(int nGroupType);                         // enter a lobby
    void FUN_140c0cea0(CInPacket& packet);                      // packet 0x53 (party match)
    void FUN_140c0cf20(CInPacket& packet);                      // packet 0x1a (dungeon reward)
    int FUN_140c0cf80(int nGroupType, const Unk_DcLevelRange& range, ASArray& out);
    void FUN_140c0d260(ASArray& out);                           // the recommended category
    void FUN_140c0d620(MS2Ptr<UIDungeonCategory> pCategory, ASArray& out);
    void FUN_140c0d800(RoomVec& out);                           // up to four recommended rooms
    void FUN_140c0dab0(RoomVec& out);                           // the enterable rooms
    int FUN_140c0dc60(int nGroupType);                          // the lobby of a group type (-1: none)

private:
    MS2_LAYOUT_FRIEND;
    ItemSlotBinder m_binder;                                    // +0x178
    int m_nSubTab;                                              // +0x1b8
    std::set<unsigned int> m_bookmarks;                         // +0x1c0
};
MS2_CHECK_SIZE(UIDungeonControlCenter, 0x1d0);
MS2_CHECK_OFFSET(UIDungeonControlCenter, m_binder, 0x178);
MS2_CHECK_OFFSET(UIDungeonControlCenter, m_nSubTab, 0x1b8);
MS2_CHECK_OFFSET(UIDungeonControlCenter, m_bookmarks, 0x1c0);
