// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ItemLockSlot and ItemLockSlotBag (the item lock window's slots).
// MS2-UNIT: unit_140d418e0
// MS2-RANGE: 0x140d418e0-0x140d42540 .text$mn
// MS2-RANGE: 0x1400d2900-0x1400d2c20 .text$di
// MS2-PIN: ??_7ItemLockSlot@@6BBindData@NotifyContext@@@ 0x142e2b370 ; hand: primary vftable
// MS2-PIN: ?GetClassDesc@ItemLockSlot@@UEBAPEBVClassInfo@efd@@XZ 0x140d41f40 ; hand
// MS2-PIN: ?GetClassDesc@ItemLockSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x140d42430 ; hand
// MS2-PIN: ?TypeCast@ItemLockSlot@@UEBA_NIPEAPEAX@Z 0x140d41fb0 ; hand
// MS2-PIN: ?TypeCast@ItemLockSlotBag@@UEBA_NIPEAPEAX@Z 0x140d424a0 ; hand
// MS2-PIN: ?TypeCast@ItemLockSlotBag@@UEBA_NIPEAPEBX@Z 0x140d424f0 ; hand
// MS2-PIN: ?TypeCast@ItemLockSlot@@UEBA_NIPEAPEBX@Z 0x140d42000 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemlockslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemlockslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_GameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_GameCtx* FUN_1403ed2d0();

// The item lock manager (CItemLockManager, unit_1406125d0.h; not included: its ATL trace statics would join this unit's
// .text$di).
class CItemLockManager
{
public:
    MS2Ptr<CItem> FUN_1406127a0(int nSlot);
    int FUN_140612e90(MS2Ptr<CItem> item);
    int FUN_1406130e0(__int64 nItemUid);
};
class Unk_LockInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);
};
extern Unk_LockInventory DAT_143ab2a90;

CItemLockManager* FUN_140535310();                      // the item lock manager singleton
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);               // item link / popup for the item
void* FUN_140a50b50(DragSlot* pSlot);                   // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                 // its item uid

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

ItemLockSlotBag* FUN_140d42380(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemLockSlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemLockSlotBag);

static CString s_sortNames2[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// @0x140d418e0
ItemLockSlot::ItemLockSlot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, nIndex)
{
    m_spItem = spItem;
    SetEnabled(true);
}

// @0x140d41990
int ItemLockSlot::vfunc_18(void* p)
{
    void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem.get() != 0)
            FUN_140535310()->FUN_140612e90(spItem);
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140d41a60
int ItemLockSlot::vfunc_14()
{
    if (m_spItem.IsNull())
        return 0;
    FUN_140535310()->FUN_1406130e0(((CItem*)m_spItem)->FUN_140526a50());
    return 1;
}

// @0x140d41ad0
int ItemLockSlot::vfunc_15()
{
    if (m_spItem.get() != 0)
        FUN_140d2cfc0(m_spItem);
    return DragSlot::vfunc_15();
}

// @0x140d41b40
MS2Ptr<CItem> ItemLockSlot::vfunc_25()
{
    return m_spItem;
}

// MS2-FUNCTIONAL: the exe puts the ASTooltip below the by-value MS2Ptr copy in the frame (slots swapped)
// @0x140d41b90 (ITooltip::vfunc_0)
int ItemLockSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASTooltip tip(pPlayer, 0x20, 2);
    MS2Ptr<CItem> spItem = vfunc_25();
    if (tip.FUN_1409e0d40(spItem.get()) != 0)
    {
        if (IsEnabled())
            tip.FUN_1409db7b0(spItem);
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140d41cf0
int ItemLockSlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASSlot slot(2);
    int nOk = slot.FUN_1409c3860(vfunc_25().get(), pPlayer, 0x1401f);
    if (nOk != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140d41e00
int ItemLockSlot::FUN_140d41e00(__int64 nItemUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (!spItem)
        return 0;
    if (((CItem*)spItem)->FUN_140528cc0() == false)
        return 0;
    return 1;
}

// @0x140d42050
void FUN_140d42050(const CString& strName)
{
    ItemLockSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) ItemLockSlotBag(strName, 0);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(0x12);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140d42100
void FUN_140d42100(const CString& strName)
{
    ItemLockSlotBag* pBag = FUN_140d42380(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140d42150
ItemLockSlotBag::ItemLockSlotBag(const CString& strName, int nUnused)
    : DragSlotBag(strName)
{
}

// @0x140d421a0
ItemLockSlotBag::~ItemLockSlotBag()
{
}

// @0x140d421d0
CString ItemLockSlotBag::vfunc_15(int nIndex)
{
    return DragSlotBag::vfunc_15(nIndex);
}

// @0x140d42220
DragSlot* ItemLockSlotBag::vfunc_16(int nIndex)
{
    MS2Ptr<CItem> spItem = FUN_140535310()->FUN_1406127a0(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) ItemLockSlot(vfunc_15(nIndex), nIndex, spItem);
}

// @0x140d42380
ItemLockSlotBag* FUN_140d42380(NotifyContext::BindData* p)
{
    ItemLockSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200070, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x140D41990, ItemLockSlot, vfunc_18, 192, 0x2920B142);
MS2_REPLACE_METHOD(0x140D41A60, ItemLockSlot, vfunc_14, 102, 0xC7EE1CAB);
MS2_REPLACE_METHOD(0x140D41AD0, ItemLockSlot, vfunc_15, 97, 0xC098DB9B);
MS2_REPLACE_METHOD(0x140D41B40, ItemLockSlot, vfunc_25, 67, 0x047509C0);
MS2_REPLACE_METHOD(0x140D41CF0, ItemLockSlot, vfunc_8, 255, 0xBDFF241E);
MS2_REPLACE_METHOD(0x140D41E00, ItemLockSlot, FUN_140d41e00, 163, 0x6D64D169);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4df0-0x142ca4f10 .text$yd
