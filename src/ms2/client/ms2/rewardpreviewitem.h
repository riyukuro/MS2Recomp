// rewardpreviewitem.h - RewardPreviewItem / RewardPreviewInfo / CRewardPreviewTable (RTTI names): the reward preview
// lists of bosses (Table/RewardPreview_boss.xml, by npc id) and dungeons (Table/RewardPreview_dungeon.xml, by dungeon
// room id) shown by the boss reward preview and dungeon room dialogs. Header name assumed (unit ?\rewardpreviewitem.cpp).
// Layouts from the ctors / dtors (0x140dc2ef0, 0x140dc3760, 0x140dc3b70); member names invented from the xml attributes.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/dclevelrange.h"

class Unk_140165cf0;     // game TinyXML element
class ItemDropResult;
class PC;

// The "itemTag" attribute: the badge of the preview slot.
enum RewardPreviewItemTag
{
    RewardPreviewItemTag_None = 0,
    RewardPreviewItemTag_New = 1,       // "new"
    RewardPreviewItemTag_Event = 2,     // "event"
};
RewardPreviewItemTag ParseRewardPreviewItemTag(const CString& str);    // 0x140dc4ee0

// One <item> of a preview. RTTI RewardPreviewItem, 0x78 bytes, base CPtred, vftable 0x142e386c8.
class RewardPreviewItem : public CPtred
{
public:
    RewardPreviewItem();                                            // 0x140dc2ef0
    void Load(Unk_140165cf0* pElem);                                // 0x140dc2f80
    void Set(ItemDropResult& result);                               // 0x140dc3020 (dungeon room dialog: the drop results)
    bool IsValid(PC* pPC);                                          // 0x140dc3090 job and level requirements
    RewardPreviewItemTag GetItemTag();                              // 0x140dc30e0
    void SetItemTag(RewardPreviewItemTag eTag);                     // 0x140dc3100
    bool GetTradable();                                             // 0x140dc3120
    // The display order (std::sort predicate): tag, rank (descending), item type, ..., item id.
    static bool Compare(MS2Ptr<RewardPreviewItem> spA, MS2Ptr<RewardPreviewItem> spB);    // 0x140dc3140
    bool IsJobValid(PC* pPC);                                       // 0x140dc3630
    bool IsLevelValid(PC* pPC);                                     // 0x140dc36e0

    ItemEntity m_item;                                              // +0x18
    RewardPreviewItemTag m_itemTag;                                 // +0x48 "itemTag"
    ATL::CAtlArray<unsigned> m_reqJobs;                             // +0x50 "reqJobs"
    Unk_DcLevelRange m_reqLevel;                                    // +0x70 "reqLevel"
    bool m_bTradable;                                               // +0x74 (ItemAble slot 3 of the drop result)
};
MS2_CHECK_SIZE(RewardPreviewItem, 0x78);
MS2_CHECK_OFFSET(RewardPreviewItem, m_item, 0x18);
MS2_CHECK_OFFSET(RewardPreviewItem, m_itemTag, 0x48);
MS2_CHECK_OFFSET(RewardPreviewItem, m_reqJobs, 0x50);
MS2_CHECK_OFFSET(RewardPreviewItem, m_reqLevel, 0x70);
MS2_CHECK_OFFSET(RewardPreviewItem, m_bTradable, 0x74);

// One <preview>. RTTI RewardPreviewInfo, 0x40 bytes, base CPtred, vftable 0x142e386d8.
class RewardPreviewInfo : public CPtred
{
public:
    RewardPreviewInfo();                                            // 0x140dc3760
    void Load(Unk_140165cf0* pElem);                                // 0x140dc37b0
    void GetAll(ATL::CAtlList<ItemEntity>& items);                  // 0x140dc38d0
    void GetValid(PC* pPC, ATL::CAtlList<ItemEntity>& items);       // 0x140dc3950 the items valid for the player
    void GetValidArray(PC* pPC, ATL::CAtlArray<MS2Ptr<RewardPreviewItem> >& items);   // 0x140dc3a10
    void GetValidVector(PC* pPC, std::vector<MS2Ptr<RewardPreviewItem> >& items);      // 0x140dc3ac0

    unsigned m_id;                                                  // +0x18 "id"
    ATL::CAtlArray<MS2Ptr<RewardPreviewItem> > m_items;             // +0x20 <item>
};
MS2_CHECK_SIZE(RewardPreviewInfo, 0x40);
MS2_CHECK_OFFSET(RewardPreviewInfo, m_items, 0x20);

// The table. RTTI CRewardPreviewTable, 0x88 bytes: TSingleton +0, CValidData +8 (vftables 0x142e38708 / 0x142e38718).
// Created and loaded by CGameApp::InitInstance (?\ms2.cpp). The dtor (0x140dc6200) is implicit.
class CRewardPreviewTable : public TSingleton<CRewardPreviewTable>, public CValidData<CRewardPreviewTable>
{
public:
    CRewardPreviewTable();                                          // 0x140dc3b70
    bool Load();                                                    // 0x140dc3c20
    MS2Ptr<RewardPreviewInfo> GetBoss(unsigned nNpcId);             // 0x140dc3c70
    MS2Ptr<RewardPreviewInfo> GetDungeon(unsigned nDungeonRoomId);  // 0x140dc3d30
    // Developer checks: log the preview items no drop box of the npc / dungeon room can drop.
    bool ValidateBoss();                                            // 0x140dc3df0
    bool ValidateDungeon();                                         // 0x140dc43e0
    bool LoadBoss();                                                // 0x140dc49e0
    bool LoadDungeon();                                             // 0x140dc4c60

    static void CheckInit();                                        // 0x140dc6780
    static void SetInit(bool b);                                    // 0x140dc8f90
    static bool s_bInit;                                            // DAT_143ac4900

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<unsigned, MS2Ptr<RewardPreviewInfo> > m_boss;      // +0x10 npc id -> preview
    ATL::CRBMap<unsigned, MS2Ptr<RewardPreviewInfo> > m_dungeon;    // +0x58 dungeon room id -> preview
};
MS2_CHECK_SIZE(CRewardPreviewTable, 0x88);
MS2_CHECK_OFFSET(CRewardPreviewTable, m_boss, 0x10);
MS2_CHECK_OFFSET(CRewardPreviewTable, m_dungeon, 0x58);
