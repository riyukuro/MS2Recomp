#pragma once
// PC +0xf78: the player's four item handles (unit_140c86000_pcitemcooldowns defines the methods; implicit dtor 0x141666a60).
// The class name is the one scenestategame.cpp used for its local view; method names are invented.
// Needs MS2Ptr in scope (ms2stdafx.h / pcbase.h).
class CItem;
class CInputStream;
class Unk_PCItemCooldowns
{
public:
    Unk_PCItemCooldowns();                                  // 0x140c86000
    void Clear();                                   // clear all four slots
    void ReadFromStream(CInputStream& stream, int nObjId);   // read the slots from a stream
    MS2Ptr<CItem> FindItemByUid(__int64 nItemUid);          // find by uid
    MS2Ptr<CItem> GetItemBySlot(int nSlot);                 // get a slot
    bool SetItem(MS2Ptr<CItem> spItem);               // put at the item's own slot
    bool RemoveItemByUid(__int64 nItemUid);                   // clear the slot holding the uid
private:
    MS2Ptr<CItem> m_items[4];
};
