// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2/placeholder/itemslotbinder.h.
// MS2-UNIT: ?\itemslotbinder.cpp
// MS2-RANGE: 0x140d431c0-0x140d43fe0 .text$mn
// MS2-PIN: ??C?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x1401c0180
// MS2-PIN: ??1?$MS2Ptr@VCItem@@@@QEAA@XZ 0x1401bfde0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemslotbinder.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/citem.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// An item description the binder can read through its virtual interface (the dungeon control center reward slot).
class Unk_SlotBindInfo
{
public:
    virtual int vfunc_0();                  // item id
    virtual int vfunc_1();                  // rarity
    virtual int vfunc_2();                  // amount
    virtual bool vfunc_3();                 // not tradable
};

// Binds the item under the slot name in the flash binding table (items are looked up by name from the swf).
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nA, int nB, int nC);
void FUN_141415600(const CString& strName);

// @0x140d431c0
ItemSlotBinder::ItemSlotBinder(CString strOwner) : m_18(strOwner), m_20(0), m_24(0x11), m_28(0x800)
{
}

// @0x140d43260
ItemSlotBinder::~ItemSlotBinder()
{
    FUN_140d43990();
}

// @0x140d432d0
void FUN_140d432d0(ItemSlotBinder* pBinder, int n)
{
    pBinder->m_24 = n;
}

// @0x140d432f0
void FUN_140d432f0(ItemSlotBinder* pBinder, int n)
{
    pBinder->m_28 = n;
}

// @0x140d43310
CString ItemSlotBinder::FUN_140d43310(int nItemId, int nRarity, int nAmount)
{
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_14052b130(nItemId, nRarity, 0) != 0)
    {
        item->FUN_140526c70(nAmount);
        m_20++;
        CString strName = StringFormat("{0}_{1}", m_18, m_20);
        FUN_141415450(strName, MS2Ptr<CItem>(item), 0, m_24, m_28);
        m_slots.insert(strName);
        return strName;
    }
    return "";
}

// @0x140d43510
CString ItemSlotBinder::FUN_140d43510(const void* pItem)
{
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_14052b130(((Unk_SlotBindInfo*)pItem)->vfunc_0(), ((Unk_SlotBindInfo*)pItem)->vfunc_1(), 0) != 0)
    {
        item->FUN_140526c70(((Unk_SlotBindInfo*)pItem)->vfunc_2());
        if (((Unk_SlotBindInfo*)pItem)->vfunc_3() != 0)
            item->FUN_1405273f0(0);
        m_20++;
        CString strName = StringFormat("{0}_{1}", m_18, m_20);
        FUN_141415450(strName, MS2Ptr<CItem>(item), 0, m_24, m_28);
        m_slots.insert(strName);
        return strName;
    }
    return "";
}

// @0x140d43790
CString ItemSlotBinder::FUN_140d43790(void* pItem)
{
    if (pItem == 0)
        return "";
    m_20++;
    CString strName = StringFormat("{0}_{1}", m_18, m_20);
    FUN_141415450(strName, MS2Ptr<CItem>((CItem*)pItem), 0, m_24, m_28);
    m_slots.insert(strName);
    return strName;
}

// @0x140d438f0
void ItemSlotBinder::FUN_140d438f0(CString strSlot)
{
    if (m_slots.find(strSlot) != m_slots.end())
    {
        FUN_141415600(strSlot);
        m_slots.erase(strSlot);
    }
}

// @0x140d43990
void ItemSlotBinder::FUN_140d43990()
{
    for (std::set<CString>::iterator it = m_slots.begin(); it != m_slots.end(); it++)
        FUN_141415600(*it);
    m_slots.clear();
}

// The CRT's memmove_s (static inline in corecrt_memcpy_s.h) sits in this unit's range; referencing it instantiates it.
void Unk_ItemSlotBinderMoveAnchor(void* pDst, size_t nDst, void* pSrc, size_t nSrc)
{
    memmove_s(pDst, nDst, pSrc, nSrc);
}
