// ItemSocketSystemPageBase: RTTI 9-slot CPtred-derived interface.
// Member names are inferred. Constructor 0x140f6c680; deleting destructor proves 0x30 bytes.
#pragma once
#include "ms2/placeholder/asdisplayobject.h"
#include <atlcoll.h>
#include "ms2/client/ms2/iteminfoslot.h"
class CItem;
class ItemInfoSlot;
class CInPacket;
class TSocketGemStoneInfo;
class CIngredientContainer;
class AScript; typedef AScript ASObj;
class Unk_SocketPageBag;

class ItemSocketSystemPageBase : public CPtred
{
public:
    class SaleParam : public CPtred {
    public:
        SaleParam();
        ~SaleParam() = default;
        int enabled;
        int value1c;
        int rate;
        int value24;
    };
    ItemSocketSystemPageBase();
    virtual ~ItemSocketSystemPageBase();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count) { return 0; }
    virtual void vfunc_4(MS2Ptr<AScript> root);
    virtual void vfunc_5(CInPacket* packet) {}
    virtual void vfunc_6();
    virtual void vfunc_7(MS2Ptr<AScript> root);
    virtual void vfunc_8(CInPacket* packet);

    void FUN_140f6d620(int enabled);
    int FUN_140f6d670();
    MS2Ptr<CItem> CreateItem(int itemId, int grade);
    MS2Ptr<CItem> CreateItemFromSource(int itemId, int grade, bool bindOwner, MS2Ptr<CItem> source);
    MS2Ptr<CItem> CreateGemStoneItem(MS2Ptr<TSocketGemStoneInfo> info, int grade, bool bindOwner);
    ItemInfoSlot* GetItemSlot(const CString& name);
    ItemInfoSlot* SetInfoSlotItem(const CString& name, MS2Ptr<CItem> item);
    ItemInfoSlot* RefreshInfoSlot(const CString& name);
    MS2Ptr<CItem> FindItemByUid(__int64 uid, CAtlArray<MS2Ptr<CItem>>& items, int* index);
    MS2Ptr<CItem> GetItemAt(CAtlArray<MS2Ptr<CItem>>& items, unsigned index);
    void SwapItems(CAtlArray<MS2Ptr<CItem>>& items, int first, int second);
    void FUN_140f6d450(const CString& name, CAtlArray<MS2Ptr<CItem>>& items, int icon, int flags);
    void FUN_140f6d4c0(const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<ItemSlotBag::CreateParam> param);
    void FUN_140f6d590(const CString& name, MS2Ptr<CItem> item, int icon, int flags);
    bool RemoveItemAt(int index, const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<Unk_SocketPageBag> control);
    bool AddItemToBag(MS2Ptr<CItem> item, const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<Unk_SocketPageBag> control);
    void ClearListSelection(MS2Ptr<Unk_SocketPageBag> control);
    void BuildIngredientRows(const CString& name, CIngredientContainer& ingredients, ASObj& data, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<CItem> excluded, __int64* price, MS2Ptr<SaleParam> sale);
    void SetSlotNew(int index, bool isNew);
    void UpdateIngredientCounts(const CString& name, const CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<CItem> excluded, __int64* price, MS2Ptr<SaleParam> sale);
    int GetOwnedItemCount(MS2Ptr<CItem> item, MS2Ptr<CItem> excluded);
    int FUN_140f6e6e0();
    void FUN_140f6e700(__int64 uid);
    void SetRestoreInventory();
protected:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_root;
    bool m_restoreInventory;
};
MS2_CHECK_SIZE(ItemSocketSystemPageBase, 0x30);
MS2_CHECK_OFFSET(ItemSocketSystemPageBase, m_root, 0x18);
MS2_CHECK_OFFSET(ItemSocketSystemPageBase, m_restoreInventory, 0x28);
MS2_CHECK_SIZE(ItemSocketSystemPageBase::SaleParam, 0x28);
