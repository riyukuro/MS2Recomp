// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWarehouseItem / CWarehouseItemTable: see warehouseitem.h.
// MS2-UNIT: ?\warehouseitem.cpp
// MS2-RANGE: 0x1408fb8c0-0x1408fdf10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VCWarehouseItem@@@@QEBAPEAVCWarehouseItem@@XZ 0x1408fc750 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\warehouseitem.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "warehouseitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool FUN_140633d50(MS2Ptr<CItem> spItem);                                   // the item can be traded

// @0x1408fb8c0
CWarehouseItem::CWarehouseItem(MS2Ptr<CItem> spItem)
    : m_spItem(spItem)
{
}

// @0x1408fb930
CWarehouseItem::~CWarehouseItem()
{
    m_spItem = 0;
}

// @0x1408fb990
int CWarehouseItem::FUN_1408fb990()
{
    if ((CItem*)m_spItem == 0)
        return 0;
    return m_spItem->FUN_1405276c0();
}

// @0x1408fb9f0
__int64 CWarehouseItem::FUN_1408fb9f0()
{
    if ((CItem*)m_spItem == 0)
        return 0;
    return m_spItem->FUN_140526a50();
}

// @0x1408fba50
CWarehouseItemTable::CWarehouseItemTable()
    : m_items(10)
{
}

// @0x1408fba80
CWarehouseItemTable::~CWarehouseItemTable()
{
}

// @0x1408fbab0
void CWarehouseItemTable::FUN_1408fbab0()
{
}

// @0x1408fbac0
void CWarehouseItemTable::RemoveAll()
{
    m_items.RemoveAll();
}

// @0x1408fbaf0
int CWarehouseItemTable::Add(CItem* pItem)
{
    if (m_items.Lookup(pItem->FUN_140526a50()) == 0)
    {
        MS2Ptr<CWarehouseItem> spEntry(new CWarehouseItem(MS2Ptr<CItem>(pItem)));
        m_items.SetAt(spEntry->FUN_1408fb9f0(), spEntry);
        return 0;
    }
    return 0x11;
}

// @0x1408fbc00
void CWarehouseItemTable::Remove(__int64 nItemUid)
{
    MS2Ptr<CWarehouseItem> spEntry;
    if (m_items.Lookup(nItemUid, spEntry))
        m_items.RemoveKey(nItemUid);
}

// @0x1408fbc70
void CWarehouseItemTable::FUN_1408fbc70(ATL::CAtlArray<MS2Ptr<CItem> >& out)
{
    POSITION pos = m_items.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CWarehouseItem> spEntry = m_items.GetValueAt(pos);
        if (spEntry == 0)
        {
        }
        else
            out.Add(spEntry->m_spItem);
        m_items.GetNext(pos);
    }
}

// @0x1408fbd30
void CWarehouseItemTable::FUN_1408fbd30(void* pArg, ATL::CAtlArray<MS2Ptr<CItem> >& out)
{
    for (POSITION pos = m_items.GetHeadPosition(); pos != 0; m_items.GetNext(pos))
    {
        MS2Ptr<CWarehouseItem> spEntry = m_items.GetValueAt(pos);
        if (spEntry == 0 || spEntry->m_spItem == 0)
            continue;
        MS2Ptr<CItem> spItem = spEntry->m_spItem;
        if (spItem->FUN_140526060(pArg) != 0)
        {
            if (FUN_140633d50(spItem))
                out.Add(spItem);
        }
    }
}

// @0x1408fbe90
MS2Ptr<CItem> CWarehouseItemTable::FUN_1408fbe90(int nItemId)
{
    POSITION pos = m_items.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CWarehouseItem> spEntry = m_items.GetValueAt(pos);
        if (spEntry->FUN_1408fb990() == nItemId)
            return spEntry->m_spItem;
        m_items.GetNext(pos);
    }
    return MS2Ptr<CItem>(0);
}

// @0x1408fbf90
MS2Ptr<CItem> CWarehouseItemTable::FUN_1408fbf90(__int64 nItemUid)
{
    MS2Ptr<CWarehouseItem> spEntry;
    m_items.Lookup(nItemUid, spEntry);
    if (spEntry.get() == 0)
        return MS2Ptr<CItem>(0);
    return spEntry->m_spItem;
}

// @0x1408fc050
MS2Ptr<CItem> CWarehouseItemTable::FUN_1408fc050(__int64 nItemUid)
{
    MS2Ptr<CWarehouseItem> spEntry;
    if (!m_items.Lookup(nItemUid, spEntry))
        return MS2Ptr<CItem>(0);
    return spEntry->m_spItem;
}

// @0x1408fc110
int CWarehouseItemTable::FUN_1408fc110()
{
    int nCount = 0;
    POSITION pos = m_items.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CWarehouseItem> spEntry = m_items.GetValueAt(pos);
        if (spEntry.get() != 0)
            nCount++;
        m_items.GetNext(pos);
    }
    return nCount;
}

// @0x1408fc1b0
int CWarehouseItemTable::FUN_1408fc1b0(int nItemId)
{
    int nTotal = 0;
    POSITION pos = m_items.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CWarehouseItem> spEntry = m_items.GetValueAt(pos);
        if (!(spEntry == 0))
        {
            MS2Ptr<CItem> spItem = spEntry->m_spItem;
            if (spItem.IsNull() == false)
            {
                if (spItem->FUN_1405276c0() == nItemId)
                    nTotal += spItem->FUN_140526c50();
            }
        }
        m_items.GetNext(pos);
    }
    return nTotal;
}

// @0x1408fc2f0
int CWarehouseItemTable::FUN_1408fc2f0(int nItemId, unsigned __int64 nUgcUid)
{
    int nTotal = 0;
    POSITION pos = m_items.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<CWarehouseItem> spEntry = m_items.GetValueAt(pos);
        if (!(spEntry == 0))
        {
            MS2Ptr<CItem> spItem = spEntry->m_spItem;
            if (spItem.IsNull() == false)
            {
                if (spItem->FUN_1405276c0() == nItemId)
                {
                    if (spItem->FUN_1405283d0() == nUgcUid)
                        nTotal += spItem->FUN_140526c50();
                }
            }
        }
        m_items.GetNext(pos);
    }
    return nTotal;
}

MS2_EMIT_CRT_MEMMOVE_S();
