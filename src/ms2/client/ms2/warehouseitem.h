// warehouseitem.h - CWarehouseItem (RTTI .?AVCWarehouseItem@@, 0x28 bytes, CPtred): one item stored in the warehouse,
// and CWarehouseItemTable, the uid -> CWarehouseItem map (ATL::CRBMap, 0x30 bytes) of the warehouse with its queries.
// Owning unit: ?\warehouseitem.cpp (0x1408fb8c0-0x1408fdf10). Header name assumed from the unit path; the table's real
// name is not in the exe (it has no virtual functions): the name is invented, member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CItem;

// vftable (1 slot: ??_G 0x1408fc7b0 sized delete 0x28)
class CWarehouseItem : public CPtred
{
public:
    CWarehouseItem(MS2Ptr<CItem> spItem);           // 0x1408fb8c0
    virtual ~CWarehouseItem();                      // 0x1408fb930

    int FUN_1408fb990();                            // the item id (0 when empty)
    __int64 FUN_1408fb9f0();                        // the item uid (0 when empty)

    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                         // +0x18
};
MS2_CHECK_SIZE(CWarehouseItem, 0x28);
MS2_CHECK_OFFSET(CWarehouseItem, m_spItem, 0x18);

class CWarehouseItemTable
{
public:
    CWarehouseItemTable();                          // 0x1408fba50
    ~CWarehouseItemTable();                         // 0x1408fba80
    void FUN_1408fbab0();                           // (empty)
    void RemoveAll();                               // 0x1408fbac0
    int Add(CItem* pItem);                          // 0x1408fbaf0 0 ok, 0x11 the uid is already stored
    void Remove(__int64 nItemUid);                  // 0x1408fbc00
    void FUN_1408fbc70(ATL::CAtlArray<MS2Ptr<CItem> >& out);                  // every item
    void FUN_1408fbd30(void* pArg, ATL::CAtlArray<MS2Ptr<CItem> >& out);      // the matching, tradable items
    MS2Ptr<CItem> FUN_1408fbe90(int nItemId);       // the first item with this item id
    MS2Ptr<CItem> FUN_1408fbf90(__int64 nItemUid);  // the item with this uid (Lookup, null test of the result)
    MS2Ptr<CItem> FUN_1408fc050(__int64 nItemUid);  // the item with this uid (Lookup's return value)
    int FUN_1408fc110();                            // number of stored items
    int FUN_1408fc1b0(int nItemId);                 // total count of the items with this item id
    int FUN_1408fc2f0(int nItemId, unsigned __int64 nUgcUid);   // same, restricted to one UGC uid

    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<unsigned __int64, MS2Ptr<CWarehouseItem> > m_items;     // +0x0
};
MS2_CHECK_SIZE(CWarehouseItemTable, 0x30);
extern CWarehouseItemTable DAT_143ab2e20;           // the housing cube inventory (unit_1400be790 defines it)
