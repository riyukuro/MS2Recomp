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
    void FUN_140c86060();                                   // clear all four slots
    void FUN_140c860b0(CInputStream& stream, int nObjId);   // read the slots from a stream
    MS2Ptr<CItem> FUN_140c862c0(__int64 nItemUid);          // find by uid
    MS2Ptr<CItem> FUN_140c863c0(int nSlot);                 // get a slot
    bool SetItem(MS2Ptr<CItem> spItem);               // put at the item's own slot
    bool FUN_140c86510(__int64 nItemUid);                   // clear the slot holding the uid
private:
    MS2Ptr<CItem> m_items[4];
};
