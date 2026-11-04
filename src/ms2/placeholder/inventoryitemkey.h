// inventoryitemkey.h - PLACEHOLDER for the 12-byte item key of the inventory count query
// Unk_Inventory::FUN_140a5eda0(const int*) (client\ms2\inventory.h): item id, rarity, one unused int. NOT an original
// header; name invented. The ctor (0x140bb5a30, zeroes the three ints) is an inline COMDAT first instantiated by
// uibingoeventdialog.cpp.
#pragma once

#include "ms2/ms2layout.h"

struct Unk_InventoryItemKey
{
    // @0x140bb5a30
    Unk_InventoryItemKey() : m_id(0), m_rarity(0), m_extra(0) {}
    int m_id;
    int m_rarity;
    int m_extra;
};
MS2_CHECK_SIZE(Unk_InventoryItemKey, 0xc);
