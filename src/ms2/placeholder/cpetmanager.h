// cpetmanager.h - PLACEHOLDER for CPetManager (RTTI .?AVCPetManager@@, 0x198 bytes) and CPetInventory (0x88 bytes, the
// member at +0x18; the name is invented, the exe has no RTTI for it but the message box delegates name it:
// Delegate<bool(int,const CMsgBoxData&)>::DelegateImpl<std::pair<CPetInventory*, bool (CPetInventory::*)(int,const CMsgBoxData&)>>).
// NOT an original header. Both live in ?\petmanager.cpp.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; ctor 0x140c894b0, dtor 0x140c89570, deleting dtor 0x140c8da70.
// CPetManager::OnResponsePet handles the pet packet (opcode 0x79 family; sub-mode = first byte).
// CPetInventory (ctor 0x140c86860, dtor 0x140c8d680) is Unk_Inventory's shape (client\ms2\inventory.h) with one bag:
//   +0x00 lock, +0x30 uid -> item map, +0x60 slot array, +0x80 int (reset to 0).
#pragma once

#include <atlcoll.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ccpetinfopacket.h"

class CMsgBoxData;
class CInPacket;
class Unk_PetRow;

class CPetInventory
{
public:
    typedef MS2Ptr<CItem> ItemPtr;
    typedef ATL::CAtlArray<ItemPtr> ItemArray;
    typedef ATL::CRBMap<unsigned __int64, ItemPtr> ItemMap;

    CPetInventory();                                        // 0x140c86860
    ~CPetInventory();                                       // 0x140c8d680

    void ResetSlots();                                   // reset: drop all items, size the slot array to the summoned pet's row
    int AddItem(CItem* pItem);                        // add (0 ok, 0x11 occupied, 0xd full, 0x1d bad slot)
    void RemoveItem(unsigned __int64 nUid);              // remove by uid
    ItemPtr GetItemBySlot(int nSlot);                       // the item of a slot
    ItemPtr FindUsableItemById(int nItemId);                     // a usable item of an item id
    size_t CollectItemsById(int nItemId, ATL::CAtlList<ItemPtr>& result, int nMode);   // stacks of an item id, sorted by count
    ItemPtr GetItemByUid(unsigned __int64 nUid);           // by uid
    ItemPtr FUN_140c87300(int nItemId, int bAnyUsability);  // by item data id
    int GetUsedSlotCount();                                    // occupied slots
    int GetSlotCount();                                    // slot count
    int HasEmptySlot();                                    // any free slot (scanned from both ends)
    int HasEnoughItems(int nItemId, int nCount);           // BOOL
    int FUN_140c877e0(int nItemId, int nRarity, int nCount); // BOOL
    int GetItemCount(int nItemId, int nRarity);            // owned count of an item id (usable ones)
    int GetStackRoom(int nItemId);                         // room left in the stacks of an item id
    unsigned FindEmptySlot();                               // first free slot (-1: none)
    int FindSlotForItem(ItemPtr spItem, int nNeed);           // slot a stack of the item can go to
    void GetAllItems(ATL::CAtlArray<ItemPtr>& result);    // all items
    bool UseItemById(int nItemId);                        // use the usable item of that id
    bool FUN_140c88050(int nItemId);                        // use the item of that data id
    void SendRequestPetInventoryMode7();                                   // packet 0x79 mode 7
    void SendRequestPetInventoryMode3(__int64 nUid, int nSlot);            // packet 0x79 mode 3 (move)
    void SendRequestPetInventoryMode0(__int64 nUid, int nSlot, int nCount);   // packet 0x79 mode 0 (take out)
    void SendRequestPetInventoryMode1(__int64 nUid, int nSlot, int nCount); // packet 0x79 mode 1 (put in)
    bool OnMoveToPetCountResult(int nButton, const CMsgBoxData& box);   // count box result of SendRequestPetInventoryMode0
    bool OnMoveFromPetCountResult(int nButton, const CMsgBoxData& box);   // count box result of SendRequestPetInventoryMode1
    static void MoveItemToPetInventory(ItemPtr spItem, int nSlot);   // no `this` in the exe (spItem in rcx); take an item out of the pet inventory (count box when stacked)
    static void MoveItemFromPetInventory(ItemPtr spItem, int nSlot);   // no `this` in the exe (spItem in rcx); put an item into the pet inventory
    bool UseItemSkill(ItemPtr spItem);                     // use the item's skill

    CLockCriticalSection m_lock;                            // +0x00
    ItemMap m_items;                                        // +0x30
    ItemArray m_slots;                                      // +0x60
    int m_n80;                                              // +0x80
};
MS2_CHECK_SIZE(CPetInventory, 0x88);
MS2_CHECK_OFFSET(CPetInventory, m_items, 0x30);
MS2_CHECK_OFFSET(CPetInventory, m_slots, 0x60);
MS2_CHECK_OFFSET(CPetInventory, m_n80, 0x80);

// The pet table dispatches nothing itself; the empty class at +0xa0 only has a constructor (0x140c89200).
class Unk_PetManagerEmpty
{
public:
    Unk_PetManagerEmpty();                                  // 0x140c89200
    MS2Ptr<CItem> FUN_140c892c0(int nItemId);               // item lookup by id
    int FUN_140c89440(int nItemId, int nRarity);
};

class CPetManager : public TSingleton<CPetManager>
{
public:
    CPetManager();                                          // 0x140c894b0
    virtual ~CPetManager();                                 // 0x140c89570

    // dispatch and handlers of the pet packet (sub-mode = the first byte)
    void OnResponsePet(CInPacket& in);
    void OnPetCountList(CInPacket& in);                      // mode 7: counts of all pets
    void OnPetCountUpdate(CInPacket& in);                      // mode 8: count of one pet
    void OnPetInfo(CInPacket& in);                      // mode 9: info
    void OnPetSummoned(CInPacket& in);                      // mode 0: summon
    void OnPetUnsummoned(CInPacket& in);                      // mode 1: recall
    void OnPetSummonSound(CInPacket& in);                      // mode 2: summon effect
    void OnPetRenamed(CInPacket& in);                      // mode 4: name
    void OnPetFlagsUpdate(CInPacket& in);                      // mode 6: flags
    void OnPetOptionsUpdate(CInPacket& in);                      // mode 5: options
    void FUN_140c8a4b0(CInPacket& in);                      // mode 10: pet item value
    void FUN_140c8a640(CInPacket& in);                      // mode 0x12: pet item level
    void FUN_140c8a7a0(CInPacket& in);                      // mode 0x11: pet item data
    void OnPetLevelUp(CInPacket& in);                      // mode 0xb: level up
    void FUN_140c8ab80(CInPacket& in);                      // mode 0xc: pet exp
    void FUN_140c8ac50(CInPacket& in);                      // mode 0x10: new pet item
    void OnPetError(CInPacket& in);                      // mode 0x13: error
    void FUN_140c8afa0(CInPacket& in);                      // mode 0x15: apply the pet to a player
    void OnPetAutoChanged(CInPacket& in);                      // mode 0xf: auto flag
    void OnPetTrapSkillConsumed(CInPacket& in);                      // mode 0x14: trap skill consume notice

    void ClearCounts();                                   // clear the counts
    int GetCountByKey(int nKey);                            // count of a key
    int HasSummonedPet();                                    // has a summoned pet item
    __int64 GetSummonUid();                                // the summoned pet item uid
    void SetSummonUid(__int64 nUid);
    int GetAuto();                                    // auto flag
    int SendRequestPet();                                    // toggle the auto flag (sends it)
    CPetInventory* GetInventory();                         // &m_inv
    Unk_PetManagerEmpty* FUN_140c8b430();                   // &m_a0
    CCPetInfoPacket::Info* GetInfo();                 // &m_info
    MS2Ptr<Unk_PetRow> GetSummonedPetRow();                     // the table row of the summoned pet item
    void* GetPlayerPet(int nObjectId);                     // the pet (CPet) of a player object, or null

    // item use entry points (the callers pass an item data id)
    int UseItemById(int nItemId);
    int FUN_140c89270(int nItemId);
    MS2Ptr<CItem> FindItemById(int nItemId);
    MS2Ptr<CItem> FindItemByUid(unsigned __int64 nUid);
    int CountItems(int nItemId, int nRarity);

private:
    MS2_LAYOUT_FRIEND;
public:
    __int64 m_8;                                            // +0x08
    __int64 m_nSummonUid;                                   // +0x10 the summoned pet's item uid
    CPetInventory m_inv;                                    // +0x18
    Unk_PetManagerEmpty m_a0;                               // +0xa0
    CCPetInfoPacket::Info m_info;                           // +0xa8
    std::map<unsigned long, long> m_counts;                       // +0x180
    int m_nAuto;                                            // +0x190 (1)
};
MS2_CHECK_SIZE(CPetManager, 0x198);
MS2_CHECK_OFFSET(CPetManager, m_inv, 0x18);
MS2_CHECK_OFFSET(CPetManager, m_info, 0xa8);
MS2_CHECK_OFFSET(CPetManager, m_counts, 0x180);
MS2_CHECK_OFFSET(CPetManager, m_nAuto, 0x190);
