// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). FittingDollSlotBag, the bag of the fitting doll window's slots
// (third of the three objects of the fittingdollslot.cpp range).
// MS2-UNIT: client\ms2\fittingdollslot.cpp#3
// MS2-RANGE: 0x14121e670-0x14121f110 .text$mn
// MS2-RANGE: 0x1400e9600-0x1400e9740 .text$di
// MS2-RANGE: 0x142cad9a0-0x142cada10 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?TypeCast@FittingDollSlotBag@@UEBA_NIPEAPEAX@Z 0x14121f070 ; unique
// MS2-PIN: ?TypeCast@FittingDollSlotBag@@UEBA_NIPEAPEBX@Z 0x14121f0c0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fittingdollslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fittingdollslot.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

FittingDollSlotBag* FUN_14121ef50(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(FittingDollSlotBag);

// Header-defined statics (the third copy of the shared item header's statics).
#include "ms2/placeholder/header_statics_a.h"

// @0x14121e670
void FUN_14121e670(const CString& strName, int nPcId, unsigned __int64 nDollId, bool bCodi)
{
    FittingDollSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) FittingDollSlotBag(strName, nPcId, nDollId, bCodi);
    if (pBag)
    {
        int nCount = pBag->FUN_14121eee0();
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14121e760
void FUN_14121e760(const CString& strName)
{
    FittingDollSlotBag* pBag = FUN_14121ef50(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x14121e7b0
FittingDollSlotBag::FittingDollSlotBag(const CString& strName, int nPcId, unsigned __int64 nDollId, bool bCodi)
    : DragSlotBag(strName), m_nPcId(nPcId), m_nDollId(nDollId)
{
    if (!bCodi)
    {
        m_mapSlot.SetAt(0, (Unk_InventoryEquipSlot)6);
        m_mapSlot.SetAt(1, (Unk_InventoryEquipSlot)0xe);
        m_mapSlot.SetAt(2, (Unk_InventoryEquipSlot)0xf);
        m_mapSlot.SetAt(3, (Unk_InventoryEquipSlot)0x11);
        m_mapSlot.SetAt(4, (Unk_InventoryEquipSlot)8);
        m_mapSlot.SetAt(5, (Unk_InventoryEquipSlot)10);
        m_mapSlot.SetAt(6, (Unk_InventoryEquipSlot)9);
        m_mapSlot.SetAt(7, (Unk_InventoryEquipSlot)0x10);
        m_mapSlot.SetAt(8, (Unk_InventoryEquipSlot)7);
        m_mapSlot.SetAt(9, (Unk_InventoryEquipSlot)0xb);
        m_mapSlot.SetAt(10, (Unk_InventoryEquipSlot)5);
        m_mapSlot.SetAt(11, (Unk_InventoryEquipSlot)4);
    }
    else
    {
        m_mapSlot.SetAt(0, (Unk_InventoryEquipSlot)6);
        m_mapSlot.SetAt(1, (Unk_InventoryEquipSlot)0xe);
        m_mapSlot.SetAt(2, (Unk_InventoryEquipSlot)0xd);
        m_mapSlot.SetAt(3, (Unk_InventoryEquipSlot)0xc);
        m_mapSlot.SetAt(4, (Unk_InventoryEquipSlot)8);
        m_mapSlot.SetAt(5, (Unk_InventoryEquipSlot)10);
        m_mapSlot.SetAt(6, (Unk_InventoryEquipSlot)9);
        m_mapSlot.SetAt(7, (Unk_InventoryEquipSlot)0x10);
        m_mapSlot.SetAt(8, (Unk_InventoryEquipSlot)7);
        m_mapSlot.SetAt(9, (Unk_InventoryEquipSlot)0xb);
        m_mapSlot.SetAt(10, (Unk_InventoryEquipSlot)5);
        m_mapSlot.SetAt(11, (Unk_InventoryEquipSlot)4);
    }
}

// @0x14121ec70
FittingDollSlotBag::~FittingDollSlotBag()
{
}

// @0x14121ecb0
CString FittingDollSlotBag::vfunc_15(int nIndex)
{
    Unk_InventoryEquipSlot nSlot = FUN_14121ef10(nIndex);
    CString str = StringFormat("{0}.{1}", FUN_1422c89f0(), nSlot);
    return str;
}
MS2_REPLACE_METHOD(0x14121ecb0, FittingDollSlotBag, vfunc_15, 171, 0xE8D6C8AA);

// @0x14121ed70
DragSlot* FittingDollSlotBag::vfunc_16(int nIndex)
{
    return new (efd::MemHint(efd::MemHint::NONE)) FittingDollSlot(vfunc_15(nIndex), nIndex, m_nPcId, m_nDollId, FUN_14121ef10(nIndex));
}

// @0x14121eee0
int FittingDollSlotBag::FUN_14121eee0()
{
    return (int)m_mapSlot.GetCount();
}
MS2_REPLACE_METHOD(0x14121eee0, FittingDollSlotBag, FUN_14121eee0, 33, 0x1FC27DB9);

// @0x14121ef10
Unk_InventoryEquipSlot FittingDollSlotBag::FUN_14121ef10(int nIndex)
{
    Unk_InventoryEquipSlot nSlot;
    if (m_mapSlot.Lookup(nIndex, nSlot))
        return nSlot;
    return (Unk_InventoryEquipSlot)0;
}
MS2_REPLACE_METHOD(0x14121ef10, FittingDollSlotBag, FUN_14121ef10, 61, 0x92C2A361);

// @0x14121ef50
FittingDollSlotBag* FUN_14121ef50(NotifyContext::BindData* p)
{
    FittingDollSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200056, (void**)&pBag))
        return pBag;
    else
        return 0;
}
