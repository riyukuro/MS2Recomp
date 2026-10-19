// cashinventorybag.h - CashInventoryBag / CashInventorySlot: the bag of the 30 cash inventory slots (items bought in
// the cash shop and waiting to be moved into the character's inventory); a click on a slot asks to pick the item up.
// Owning unit: ?\cashinventorybag.cpp (0x140b055c0-0x140b0dc70, .text$di 0x1400c6cf0). The unit also carries the whole
// CCashMarketMan (placeholder/ccashmarketman.h) since both sat in one translation unit of the exe. Header name assumed
// from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0x90 bytes. vftable (17 slots, ??_G 0x140b05b70 sized delete 0x90).
class CashInventoryBag : public DragSlotBag
{
public:
    CashInventoryBag(const CString& strName, int nType);    // 0x140b056d0
    virtual ~CashInventoryBag();                        // 0x140b05720

    // slots 2-4: GetClassDesc 0x140b05bd0, TypeCast 0x140b05c80 / 0x140b05cd0; ms_ClassInfo 0x143ab9e60,
    // SetupClassInfo 0x140b05c20 (parent DragSlotBag, id 0x6200061).
    EE_DECLARE_CLASS1(CashInventoryBag, 0x06200061, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x140b05750 (calls the base)
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x140b057a0 new CashInventorySlot for the product at nIndex

public:
    MS2_LAYOUT_FRIEND;
    int m_nType;                                        // +0x88
    int m_pad_8c;
};
MS2_CHECK_SIZE(CashInventoryBag, 0x90);
MS2_CHECK_OFFSET(CashInventoryBag, m_nType, 0x88);

// 0xa8 bytes. vftable (26 slots, ??_G 0x140b0dad0 sized delete 0xa8), ITooltip @+0x78.
class CashInventorySlot : public MS2DragSlot
{
public:
    CashInventorySlot(const CString& strName, int nProductId, int nType, int nIndex);   // 0x140b0ceb0
    virtual ~CashInventorySlot();                       // 0x140b0cf90

    // slots 2-4: GetClassDesc 0x140b0db30, TypeCast 0x140b0dba0 / 0x140b0dbf0; ms_ClassInfo 0x143aba3f0,
    // SetupClassInfo 0x140b0db40 (parent MS2DragSlot, id 0x6200062).
    EE_DECLARE_CLASS1(CashInventorySlot, 0x06200062, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140b0d1a0 build the slot (item icon, count) into p
    virtual int vfunc_13();                             // 13 0x140b0d040 ask to pick the item up
    virtual int vfunc_14();                             // 14 0x140b0d070 ask to pick the item up
    virtual int vfunc_18(void* p);                      // 18 0x140b0d010 return vfunc_10() of the other slot
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140b0d290 the item of the product behind the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x140b0d0a0 build the tooltip into p

    void FUN_140b0d440();                               // the pick up question (message box with the item)

public:
    MS2_LAYOUT_FRIEND;
    int m_nProductId;                                   // +0x90 CCashInventoryProduct::m_n1c
    int m_nType;                                        // +0x94
    MS2Ptr<CItem> m_spItem;                             // +0x98
};
MS2_CHECK_SIZE(CashInventorySlot, 0xa8);
MS2_CHECK_OFFSET(CashInventorySlot, m_nProductId, 0x90);
MS2_CHECK_OFFSET(CashInventorySlot, m_spItem, 0x98);
