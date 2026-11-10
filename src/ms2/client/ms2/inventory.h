// Inventory storage. Class/member names are inferred; offsets come from
// 0x140a5c7a0 and the slot/identifier accessors in inventory.cpp.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
enum Unk_InventoryEquipSlot : int { Unk_InventoryEquipSlotNone = 0 };

class Unk_Inventory {
public:
    typedef MS2Ptr<CItem> ItemPtr;
    typedef ATL::CAtlArray<ItemPtr> ItemArray;
    typedef ATL::CRBMap<unsigned __int64, ItemPtr> ItemMap;
    Unk_Inventory();
    ~Unk_Inventory();
    void FUN_140a5c8e0();
    void Clear();
    void RemoveItemsInCategory(int category);
    void SetExtraSlots(int category, int extra);
    bool IsExtraSlotsMaxed(unsigned category);
    int FUN_140a5ce30(CStringW& names);
    int GetItemCount(int category);
    int GetSlotCount(int category);
    unsigned __int64 FUN_140a5d0f0();
    int AddItem(CItem* item);
    void RemoveItem(__int64 id);
    void ReplaceItem(CItem* item);
    ItemPtr FindItemByUid(__int64 id);
    ItemPtr FindItemBySkillId(int skill, int ignoreUsability);
    ItemPtr FindItemByFunction(CStringW function, int ignoreUsability);
    ItemPtr FindItemByFunctionAndParameter(CStringW function, CStringW parameter);
    ItemPtr FindItemByTag(int tag);
    ItemPtr FUN_140a5e2e0(int itemId);
    ItemPtr FUN_140a5e5c0(int itemId, int rarity);
    int FUN_140a5e8d0(int itemId, ATL::CAtlList<ItemPtr>& result, int order);
    int HasItemCount(int itemId, int count);
    int FUN_140a5ed40(int itemId, int rarity, int count);
    int FUN_140a5f060(__int64 id);
    int FUN_140a5f180(int itemId, int rarity);
    int FUN_140a5f410(ItemPtr reference);
    int GetItemCountByTag(int tag, int rarity);
    int FUN_140a5f7b0(int tag, int rarity);
    int GetItemCountByFunction(CStringW function);
    int GetItemCountBySkillId(int skill, int includeEquipment);
    int GetItemCountByFilter(const int* filter);
    int FUN_140a5fe70(int category, ItemPtr reference);
    ItemPtr GetItemAt(int category, int slot);
    int SwapSlots(int category, int from, int to);
    int FUN_140a60560(int category, int slot, ItemPtr item);
    void GetAllItems(ItemArray& result);
    void GetItemsInCategory(int category, ItemArray& result);
    void GetItemUidsInCategory(int category, ATL::CAtlArray<unsigned __int64>& result);
    int HasItemOfType(int type);
    int FUN_140a60c20(int type);
    int HasItemWithIconCode(int type);
    int HasItemWithTag(int tag);
    void FUN_140a61010(int category, const __int64* filter, ItemArray& result);
    int FindEmptySlot(int category);
    int FUN_140a612b0(int category, ItemPtr item, int quantity);
    int FUN_140a61430(int category);
    int GetEmptySlotCount(int category);
    int FUN_140a616e0();
    int FUN_140a617f0(ItemPtr item);
    int FUN_140a61870(MS2Ptr<CItemData> data);
    int NeedsSort(int category);
    int HasMergeableStacks(int category);
    int RequestUseItem(__int64 id, const CStringW& argument);
    int FUN_140a621c0(__int64 id, int slot, int mode);
    int RequestUnequipItem(__int64 id);
    void SendRequestItemInventory(int category);
    unsigned FUN_140a62d30(int skill);
    unsigned FUN_140a63000(int itemId);
    unsigned FUN_140a63360(int skill);
    unsigned FUN_140a635f0(CItem*);
    int FUN_140a63880(CItem* item, const CStringW& argument);
    int FUN_140a63900(CItem* item, int mode);
    int CanEquipItem(CItem* item, int slot, int mode);
    int FUN_140a655b0(CItem* item);
    int GetItemRequirementError(MS2Ptr<CItemData> data, int rarity);
    int FUN_140a65b70();
    int SendEmotion(CItem* item);
    int FUN_140a65e30(CItem* item);
    int FUN_140a661e0(CItem* item);
    int FUN_140a66200(CItem* item, int* reason, CStringW& name);
    void FUN_140a66990(unsigned short level);
    void FUN_140a66ae0(ItemPtr item);
    void ResetAutoEquip();
    void CollectAutoEquipCandidates(ATL::CAtlMap<Unk_InventoryEquipSlot, ItemPtr>& result, unsigned short level);
    __int64 FUN_140a66f20();
    void FUN_140a66f40(__int64 id);
    void SetAutoEquipEnabled(int enabled);
    int IsAutoEquipEnabled();
    int FUN_140a67020(ItemPtr item);
    int FUN_140a67390(__int64 id);
    void FUN_140a673e0(ItemPtr item);
    void ExcludeFromAutoEquip(ItemPtr item);
    void ProcessAutoEquipQueue();
    int RequestEquipItem(CItem* item, int slot, int mode, int skipBinding);
    int GetItemUseError(CItem* item);

    CLockCriticalSection lock;
    ItemMap items;
    ItemArray slots[15];
    int extraSlots[15];
    int autoEquipEnabled;
    __int64 pendingItem;
    ATL::CAtlList<ItemPtr> autoEquipQueue;
    ATL::CAtlList<__int64> excludedItems;
};
MS2_CHECK_SIZE(Unk_Inventory, 0x2e8);
MS2_CHECK_OFFSET(Unk_Inventory, items, 0x30);
MS2_CHECK_OFFSET(Unk_Inventory, slots, 0x60);
MS2_CHECK_OFFSET(Unk_Inventory, extraSlots, 0x240);
MS2_CHECK_OFFSET(Unk_Inventory, autoEquipEnabled, 0x27c);
MS2_CHECK_OFFSET(Unk_Inventory, pendingItem, 0x280);
MS2_CHECK_OFFSET(Unk_Inventory, autoEquipQueue, 0x288);
MS2_CHECK_OFFSET(Unk_Inventory, excludedItems, 0x2b8);
