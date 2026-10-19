// customize.h - Customize (RTTI .?AVCustomize@@, 0x88 bytes, ctor 0x140cd1570, dtor 0x140cd16e0): the controller of the
// beauty shop / dye / hair dialogs. It previews items on a player (the object id) and keeps a clone of the worn items so
// the preview can be undone, committed (packet 0x23) or restored. Nested RTTI classes Customize::BeautyShopContext,
// Customize::EditItems (the item being edited and its customize controller), Customize::CloneItems (the snapshot of the
// worn items) and Customize::Equipment (holds both, sends the changes). Owning unit ?\customize.cpp (w476); header name
// assumed. Customize's method names stay FUN_<va> (the dialog units call them so); the nested classes' names are
// invented from use (third-party v2525 Customize.h as a hint). Layouts from the ctors and the operator new sizes.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiSmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/inventory.h"          // Unk_InventoryEquipSlot

class CItem;
class CItemData;
class PC;
class CEquipItem;
class CItemCustomizeController;
class IItemCustomizeEventListener;
class Unk_BSPartHandle;     // the NiPointer<CItemCustomizeController> FUN_140cd1a30 returns (each caller views it locally)

class Customize : public CPtred, public UIItemEventListener
{
public:
    typedef ATL::CAtlMap<unsigned __int64, MS2Ptr<CItem> > ItemMap;     // items by uid

    // The shop context handed to the controller (0x28 bytes, ctor 0x140ccad60, ??_G 0x140cd52a0).
    class BeautyShopContext : public CPtred
    {
    public:
        BeautyShopContext(int nEventId, __int64 n);
        MS2_LAYOUT_FRIEND;
        int m_18;                               // +0x18 the sale event id
        __int64 m_20;                           // +0x20 sent with the beauty packet
    };

    // The item being edited (0x58 bytes): its copy, its data and the customize controller of the part.
    class EditItems : public CPtred
    {
    public:
        EditItems(int nObjectId, Customize* pOwner);            // 0x140ccadc0
        virtual ~EditItems();                                   // 0x140ccaea0 (??_G 0x140cd53e0)
        unsigned GetItemId();                                   // 0x140ccafa0
        unsigned __int64 GetItemUid();                          // 0x140ccb020
        MS2Ptr<CItem> GetItem();                                // 0x140ccb070
        unsigned GetFlags();                                    // 0x140ccb0c0 bit 1/2 size (2: morph), 4 rotation, 8 position
        NiPointer<CItemCustomizeController> GetController();    // 0x140ccb1e0
        void Update();                                          // 0x140ccb230 per frame
        void Select(MS2Ptr<CEquipItem> spEquip);                // 0x140ccb340
        void SelectSlot(Unk_InventoryEquipSlot eSlot);          // 0x140ccb5f0
        void SelectId(int nItemId);                             // 0x140ccb680
        void SelectUid(__int64 nUid);                           // 0x140ccb7d0
        int GetDragging();                                      // 0x140ccb860
        int ApplyColor(int nIndex, int n);                      // 0x140ccb8d0
        int ApplyPalette(int nPalette, int nIndex, int n);      // 0x140ccba60
        int SetColors(const int& nColor, int nSlot, int n);     // 0x140ccbc00
        int GetColors(int* pnColor, int nSlot);                 // 0x140ccbcc0
        PC* GetPC();                                            // 0x140ccbd90

        MS2_LAYOUT_FRIEND;
        int m_nObjectId;                                        // +0x18
        MS2Ptr<CItem> m_spItem;                                 // +0x20 the copy being edited
        MS2Ptr<CItemData> m_spData;                             // +0x30
        NiPointer<CItemCustomizeController> m_spController;     // +0x40
        IItemCustomizeEventListener* m_pListener;               // +0x48
        Customize* m_pOwner;                                    // +0x50
    };

    // The snapshot of the worn items (0xd0 bytes) the preview restores to.
    class CloneItems : public CPtred
    {
    public:
        CloneItems(int nObjectId, Customize* pOwner);           // 0x140ccbdd0
        virtual ~CloneItems();                                  // 0x140ccbf00 (??_G 0x140cd5360)
        void Collect(ItemMap& added, ItemMap& modified, ItemMap& removed);  // 0x140ccbf80
        void Restore(ATL::CAtlList<Unk_InventoryEquipSlot>& slots);         // 0x140ccbfd0
        void CollectUid(__int64 nUid, ItemMap& added, ItemMap& modified, ItemMap& removed);     // 0x140ccc1f0
        void RestoreUid(__int64 nUid);                          // 0x140ccc250
        void CollectSlot(Unk_InventoryEquipSlot eSlot, ItemMap& added, ItemMap& modified, ItemMap& removed);   // 0x140ccc470
        void RestoreSlot(Unk_InventoryEquipSlot eSlot);         // 0x140ccc4c0
        void Apply(MS2Ptr<CItem> spItem, Unk_InventoryEquipSlot eSlot);     // 0x140ccc860
        int IsColorChanged();                                   // 0x140ccd210
        int IsAddedUid(__int64 nUid);                           // 0x140ccd300
        int IsModifiedUid(__int64 nUid);                        // 0x140ccd440
        int IsRemovedUid(__int64 nUid);                         // 0x140ccd580
        bool IsSameUid(__int64 nUid, unsigned* pnFlags);        // 0x140ccd6c0
        int IsAddedSlot(Unk_InventoryEquipSlot eSlot);          // 0x140ccda10
        int IsModifiedSlot(Unk_InventoryEquipSlot eSlot);       // 0x140ccdb50
        int GetAdded(ItemMap& out);                             // 0x140ccdc90
        int GetModified(ItemMap& out);                          // 0x140ccded0
        int GetRemoved(ItemMap& out);                           // 0x140cce0c0
        int GetAddedUid(ItemMap& out, __int64 nUid);            // 0x140cce210
        int GetModifiedUid(ItemMap& out, __int64 nUid);         // 0x140cce2f0
        int GetRemovedUid(ItemMap& out, __int64 nUid);          // 0x140cce3d0
        int GetAddedSlot(ItemMap& out, Unk_InventoryEquipSlot eSlot);       // 0x140cce490
        int GetModifiedSlot(ItemMap& out, Unk_InventoryEquipSlot eSlot);    // 0x140cce630
        MS2Ptr<CItem> CreateItem(int nItemId);                  // 0x140cce7d0
        unsigned GetChangeFlags(__int64 nUid);                  // 0x140ccebc0 bit 1 colour, 2 appearance
        void UpdateItem(MS2Ptr<CItem> spItem);                  // 0x140ccede0
        void SaveColors();                                      // 0x140ccef20
        PC* GetPC();                                            // 0x140ccef90
        void ClearSlots();                                      // 0x140ccefd0
        int Init();                                             // 0x140ccf010

        MS2_LAYOUT_FRIEND;
        int m_nObjectId;                                                    // +0x18
        ItemMap m_mapItems;                                                 // +0x20 copies of the worn items by uid
        ATL::CAtlMap<Unk_InventoryEquipSlot, MS2Ptr<CItem> > m_mapSlots;    // +0x68 the same by slot
        int m_anColor[3];                                                   // +0xb0 the body colours
        IItemCustomizeEventListener* m_pListener;                           // +0xc0
        Customize* m_pOwner;                                                // +0xc8
    };

    // Holds the edit and the clone (0x50 bytes) and sends the changes to the server.
    class Equipment : public CPtred
    {
    public:
        Equipment(int nObjectId, Customize* pOwner);            // 0x140ccf2d0
        virtual ~Equipment();                                   // 0x140ccf450 (??_G 0x140cd5420)
        MS2Ptr<EditItems> GetEditItems();                       // 0x140ccf500
        MS2Ptr<CloneItems> GetCloneItems();                     // 0x140ccf550
        void CommitAll();                                       // 0x140ccf5a0
        void RestoreAll(ATL::CAtlList<Unk_InventoryEquipSlot>& slots);      // 0x140ccf7e0
        void CommitUid(__int64 nUid);                           // 0x140ccf940
        void RestoreUid(__int64 nUid);                          // 0x140ccfba0
        void CommitSlot(Unk_InventoryEquipSlot eSlot);          // 0x140ccfc90
        void RestoreSlot(Unk_InventoryEquipSlot eSlot);         // 0x140ccfee0
        void GetModified(__int64 nUid, MS2Ptr<CItem>& spOut);   // 0x140ccffd0
        void Apply(MS2Ptr<CItem> spItem, Unk_InventoryEquipSlot eSlot);     // 0x140cd0270
        void Equip(CItem* pItem);                               // 0x140cd03d0
        void EquipId(int nItemId);                              // 0x140cd04f0
        void ClearPreview();                                    // 0x140cd05a0
        void Unequip(CItem* pItem);                             // 0x140cd05f0
        void UnequipId(int nItemId);                            // 0x140cd0640
        void UnequipUid(__int64 nUid);                          // 0x140cd07c0
        void ShowSlot(Unk_InventoryEquipSlot eSlot);            // 0x140cd08c0 removes the "Customize" tag
        void HideSlot(Unk_InventoryEquipSlot eSlot);            // 0x140cd0980 adds the "Customize" tag
        void ResetEdit();                                       // 0x140cd0a40
        PC* GetPC();                                            // 0x140cd0af0
        void SendColors();                                      // 0x140cd0b30 packet 0x23 mode 6
        void SendAdded(MS2Ptr<CItem> spItem);                   // 0x140cd0ca0 packet 0x23 mode 3
        void SendModified(MS2Ptr<CItem> spItem);                // 0x140cd0ea0 packet 0x23 mode 5
        void SendRemoved(MS2Ptr<CItem> spItem);                 // 0x140cd0fd0 packet 0x23 mode 4
        void SendAddedMap(ItemMap& items);                      // 0x140cd10b0
        void SendModifiedMap(ItemMap& items);                   // 0x140cd1160
        void SendRemovedMap(ItemMap& items);                    // 0x140cd1210
        void ResetCapPosition(MS2Ptr<CItem> spItem);            // 0x140cd12c0

        MS2_LAYOUT_FRIEND;
        int m_nObjectId;                                        // +0x18
        MS2Ptr<EditItems> m_spEdit;                             // +0x20
        MS2Ptr<CloneItems> m_spClone;                           // +0x30
        IItemCustomizeEventListener* m_pListener;               // +0x40
        Customize* m_pOwner;                                    // +0x48
    };

    Customize(int nObjectId, IItemCustomizeEventListener* pListener, int bPreview);     // 0x140cd1570
    virtual ~Customize();                                       // 0x140cd16e0 (??_G 0x140cd53a0)
    int FUN_140cd17e0();                        // the previewed item id
    MS2Ptr<CItem> FUN_140cd1890();              // the previewed item (uiitemcoloringdialog.cpp)
    __int64 FUN_140cd1980();                    // the uid of the item being dyed
    Unk_BSPartHandle FUN_140cd1a30();           // the part being edited
    unsigned FUN_140cd1b20();                   // what the item can customize (EditItems::GetFlags)
    IItemCustomizeEventListener* FUN_140cd1bd0();   // the listener
    void FUN_140cd1bf0();                       // per frame
    bool FUN_140cd1c90(CItem* pItem);           // preview an item (false: not wearable)
    bool FUN_140cd1d50(int nItemId);            // preview an item id (false: not wearable)
    void FUN_140cd1e80();                       // take the preview items off
    void FUN_140cd1ed0(CItem* pItem);           // take an item off
    void FUN_140cd1f30(int nItemId);            // take an item id off
    void FUN_140cd1f90(__int64 nUid);           // take an item uid off
    void FUN_140cd1ff0();                       // commit all
    void FUN_140cd20c0();                       // restore all
    void FUN_140cd21a0(__int64 nUid);           // commit the item
    void FUN_140cd2210(__int64 nUid);           // restore the item
    void FUN_140cd2280(int nSlot);              // commit the slot
    void FUN_140cd22f0(int nSlot);              // restore the slot
    void FUN_140cd2360(__int64 nUid, MS2Ptr<CItem>& spOut);    // the dyed copy of the item
    void FUN_140cd23e0(MS2Ptr<CItem> spItem, int nSlot);        // apply an item to the slot
    void FUN_140cd24a0(int nSlot);              // show the cap
    void FUN_140cd2530(int nSlot);              // hide the cap
    void FUN_140cd25c0(int nSlot);              // begin on the slot
    void FUN_140cd2660(int nItemId);            // preview an item id
    void FUN_140cd2700(__int64 nUid);           // preview the item (0: none)
    void FUN_140cd27a0();                       // keep the preview
    int FUN_140cd27f0();                        // the controller is dragging
    int FUN_140cd28a0();                        // a style is previewed
    int FUN_140cd2a00();                        // changed (billable)
    int FUN_140cd2c20();                        // changed
    int FUN_140cd2ea0();                        // a colour is previewed
    int FUN_140cd3000();                        // a crop is previewed
    int FUN_140cd3160(int nIndex, int n);       // apply a palette colour
    int FUN_140cd3220(int nPalette, int nColor, int n);
    int FUN_140cd32f0(const int& nPalette, int nColor, int n);
    int FUN_140cd33c0(int* pnColor, int nSlot);
    void FUN_140cd3480(int bApply, int nPalette);               // dye every added item with the palette
    void FUN_140cd3750(ItemMap& out);           // the added items
    bool FUN_140cd3800();                       // m_bPreview
    void FUN_140cd3820();                       // forget the kept previews
    int FUN_140cd38b0();                        // m_nPalette
    void FUN_140cd38d0(int nPalette);
    void FUN_140cd38f0(MS2Ptr<BeautyShopContext> spContext);
    MS2Ptr<BeautyShopContext> FUN_140cd3940();
    void FUN_140cd3990();                       // rebuild the equipment, keep the selection
    void FUN_140cd3a70();                       // re-hide the hidden slots
    PC* FUN_140cd3df0();                        // the player

    // UIItemEventListener
    virtual void vfunc_21(void* p);             // 21 0x140cd3ae0
    virtual void vfunc_22(void* p);             // 22 0x140cd3ba0
    virtual void vfunc_24(void* p);             // 24 0x140cd3c60 an item changed (CItem*)
    virtual void vfunc_25(void* p);             // 25 0x140cd3d40

    MS2_LAYOUT_FRIEND;
    int m_nObjectId;                                            // +0x20
    MS2Ptr<Equipment> m_spEquipment;                            // +0x28
    IItemCustomizeEventListener* m_pListener;                   // +0x38
    ATL::CAtlList<Unk_InventoryEquipSlot> m_lstHiddenSlots;     // +0x40 slots with the "Customize" tag
    bool m_bPreview;                                            // +0x70
    int m_nPalette;                                             // +0x74
    MS2Ptr<BeautyShopContext> m_spContext;                      // +0x78
};
MS2_CHECK_SIZE(Customize, 0x88);
MS2_CHECK_OFFSET(Customize, m_nObjectId, 0x20);
MS2_CHECK_OFFSET(Customize, m_lstHiddenSlots, 0x40);
MS2_CHECK_OFFSET(Customize, m_bPreview, 0x70);
MS2_CHECK_OFFSET(Customize, m_spContext, 0x78);
MS2_CHECK_SIZE(Customize::BeautyShopContext, 0x28);
MS2_CHECK_SIZE(Customize::EditItems, 0x58);
MS2_CHECK_OFFSET(Customize::EditItems, m_spController, 0x40);
MS2_CHECK_SIZE(Customize::CloneItems, 0xd0);
MS2_CHECK_OFFSET(Customize::CloneItems, m_mapSlots, 0x68);
MS2_CHECK_OFFSET(Customize::CloneItems, m_anColor, 0xb0);
MS2_CHECK_OFFSET(Customize::CloneItems, m_pListener, 0xc0);
MS2_CHECK_SIZE(Customize::Equipment, 0x50);
MS2_CHECK_OFFSET(Customize::Equipment, m_pListener, 0x40);
