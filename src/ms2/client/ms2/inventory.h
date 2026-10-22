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
    void FUN_140a5c970();
    void FUN_140a5ca60(int category);
    void FUN_140a5cb80(int category, int extra);
    bool FUN_140a5cdc0(unsigned category);
    bool FUN_140a5ce30(CStringW& names);
    int FUN_140a5cf30(int category);
    int FUN_140a5d050(int category);
    int FUN_140a5d120(CItem* item);
    void FUN_140a5d390(__int64 id);
    void FUN_140a5d530(CItem* item);
    ItemPtr FUN_140a5d680(__int64 id);
    ItemPtr FUN_140a5d760(int skill, int ignoreUsability);
    ItemPtr FUN_140a5d9a0(CStringW function, int ignoreUsability);
    ItemPtr FUN_140a5dca0(CStringW function, CStringW parameter);
    ItemPtr FUN_140a5e040(int tag);
    ItemPtr FUN_140a5e2e0(int itemId);
    ItemPtr FUN_140a5e5c0(int itemId, int rarity);
    int FUN_140a5e8d0(int itemId, ATL::CAtlList<ItemPtr>& result, int order);
    bool FUN_140a5ece0(int itemId, int count);
    bool FUN_140a5ed40(int itemId, int rarity, int count);
    int FUN_140a5f060(__int64 id);
    int FUN_140a5f180(int itemId, int rarity);
    int FUN_140a5f410(ItemPtr reference);
    void FUN_140a5f780(int tag, int rarity);
    int FUN_140a5f7b0(int tag, int rarity);
    int FUN_140a5f990(CStringW function);
    int FUN_140a5fbd0(int skill, int includeEquipment);
    int FUN_140a5eda0(const int* filter);
    int FUN_140a5fe70(int category, ItemPtr reference);
    ItemPtr FUN_140a60280(int category, int slot);
    int FUN_140a603e0(int category, int from, int to);
    int FUN_140a60560(int category, int slot, ItemPtr item);
    void FUN_140a60790(ItemArray& result);
    void FUN_140a60880(int category, ItemArray& result);
    void FUN_140a609a0(int category, ATL::CAtlArray<unsigned __int64>& result);
    int FUN_140a60ad0(int type);
    int FUN_140a60c20(int type);
    int FUN_140a60d70(int type);
    int FUN_140a60ec0(int tag);
    void FUN_140a61010(int category, const __int64* filter, ItemArray& result);
    int FUN_140a61190(int category);
    int FUN_140a612b0(int category, ItemPtr item, int quantity);
    int FUN_140a61430(int category);
    int FUN_140a615d0(int category);
    int FUN_140a616e0();
    int FUN_140a617f0(ItemPtr item);
    int FUN_140a61870(MS2Ptr<CItemData> data);
    int FUN_140a618e0(int category);
    int FUN_140a61b40(int category);
    int FUN_140a61db0(__int64 id, const CStringW& argument);
    int FUN_140a621c0(__int64 id, int slot, int mode);
    int FUN_140a62920(__int64 id);
    void SendRequestItemInventory(unsigned char category);
    unsigned FUN_140a62d30(int skill);
    unsigned FUN_140a63000(int itemId);
    unsigned FUN_140a63360(int skill);
    unsigned FUN_140a635f0(CItem*);
    int FUN_140a63880(CItem* item, const CStringW& argument);
    int FUN_140a63900(CItem* item, int mode);
    int FUN_140a63950(CItem* item, int slot, int mode);
    int FUN_140a655b0(CItem* item);
    int FUN_140a65860(MS2Ptr<CItemData> data, int rarity);
    int SendEmotion(CItem* item);
    int FUN_140a65e30(CItem* item);
    int FUN_140a661e0(CItem* item);
    int FUN_140a66200(CItem* item, int* reason, CStringW& name);
    void FUN_140a66990(unsigned short level);
    void FUN_140a66ae0(ItemPtr item);
    void FUN_140a66c00();
    void FUN_140a66ca0(ATL::CAtlMap<Unk_InventoryEquipSlot, ItemPtr>& result, unsigned short level);
    __int64 FUN_140a66f20();
    void FUN_140a66f40(__int64 id);
    void FUN_140a66fa0(int enabled);
    int FUN_140a67000();
    int FUN_140a67020(ItemPtr item);
    bool FUN_140a67390(__int64 id);
    void FUN_140a673e0(ItemPtr item);
    void FUN_140a674c0(ItemPtr item);
    void FUN_140a675c0();
    int FUN_140a62270(CItem* item, int slot, int mode, int skipBinding);
    int FUN_140a65770(CItem* item);

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
