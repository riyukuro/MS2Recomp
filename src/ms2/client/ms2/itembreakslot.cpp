// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ItemBreakSlot and ItemBreakSlotBag (the item break window's slots).
// MS2-UNIT: ?\itembreakslot.cpp
// MS2-RANGE: 0x14140ff10-0x141410cd0 .text$mn
// MS2-RANGE: 0x1400f5950-0x1400f5c70 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetClassDesc@ItemBreakSlot@@UEBAPEBVClassInfo@efd@@XZ 0x1414105c0 ; prop
// MS2-PIN: ?GetClassDesc@ItemBreakSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x141410aa0 ; unique
// MS2-PIN: ?TypeCast@ItemBreakSlotBag@@UEBA_NIPEAPEAX@Z 0x141410b10 ; unique
// MS2-PIN: ?TypeCast@ItemBreakSlotBag@@UEBA_NIPEAPEBX@Z 0x141410b60 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7ItemBreakSlot@@6BBindData@NotifyContext@@@ 0x142f0f280 ; hand: primary vftable
// MS2-PIN: ?TypeCast@ItemBreakSlot@@UEBA_NIPEAPEAX@Z 0x141410630 ; hand
// MS2-PIN: ?TypeCast@ItemBreakSlot@@UEBA_NIPEAPEBX@Z 0x141410680 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itembreakslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itembreakslot.h"
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

// The item break manager (TSingleton, 0x1409c4b20 is its GetInstance).
class Unk_BrkMgr
{
public:
    MS2Ptr<CItem> FUN_140531ce0(int nIndex);            // the nIndex-th item of the list
    int FUN_140532de0(MS2Ptr<CItem> spItem, int nIndex);    // put the item at nIndex
    int FUN_140533340(MS2Ptr<CItem> spItem);            // add the item
};
Unk_BrkMgr* FUN_1409c4b20();

// Player inventory (global at 0x143ab2a90): item lookup by uid.
class Unk_LockInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);
};
extern Unk_LockInventory DAT_143ab2a90;

void FUN_140d2cfc0(MS2Ptr<CItem> spItem);               // item link / popup for the item
bool FUN_140633bf0(MS2Ptr<CItem> spItem);               // the item can be broken
void* FUN_140a50b50(DragSlot* pSlot);                   // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                 // its item uid
DragSlot* FUN_14140e5e0(NotifyContext::BindData* p);
NotifyContext::BindData* FUN_1422cd070(DragSlotBag* pBag, int nIndex);

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

ItemBreakSlotBag* FUN_1414109f0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemBreakSlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemBreakSlotBag);

static CString s_sortNames2[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// @0x14140ff10
ItemBreakSlot::ItemBreakSlot(const CString& strName, int nIndex)
    : MS2DragSlot(strName, nIndex)
{
    SetEnabled(true);
}

// @0x14140ff80
int ItemBreakSlot::vfunc_18(void* p)
{
    void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem.get() != 0)
            FUN_1409c4b20()->FUN_140532de0(spItem, FUN_1422cc410());
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x141410070
int ItemBreakSlot::vfunc_14()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (!spItem)
        return 0;
    FUN_1409c4b20()->FUN_140533340(spItem);
    return 1;
}

// @0x141410130
int ItemBreakSlot::vfunc_15()
{
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem.get() != 0)
        FUN_140d2cfc0(spItem);
    return DragSlot::vfunc_15();
}

// @0x1414101c0
MS2Ptr<CItem> ItemBreakSlot::vfunc_25()
{
    return FUN_1409c4b20()->FUN_140531ce0(m_nIndex);
}

// MS2-FUNCTIONAL: the exe puts the ASTooltip below the by-value MS2Ptr copy in the frame (slots swapped)
// @0x141410210 (ITooltip::vfunc_0)
int ItemBreakSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASTooltip tip(pPlayer, 0x20, 2);
    MS2Ptr<CItem> spItem = vfunc_25();
    if (tip.FUN_1409e0d40(spItem.get()) != 0)
    {
        if (IsEnabled() == true)
            tip.FUN_1409db7b0(spItem);
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x141410370
int ItemBreakSlot::vfunc_8(void* p)
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

// @0x141410480
int ItemBreakSlot::FUN_141410480(__int64 nItemUid)
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
    if (!spItem)
        return 0;
    if (FUN_140633bf0(spItem) == false)
        return 0;
    return 1;
}

// @0x1414106d0
void FUN_1414106d0(const CString& strName)
{
    ItemBreakSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) ItemBreakSlotBag(strName, 0);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(100);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x141410780
void FUN_141410780(const CString& strName)
{
    ItemBreakSlotBag* pBag = FUN_1414109f0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x1414107d0
ItemBreakSlotBag::ItemBreakSlotBag(const CString& strName, int nUnused)
    : DragSlotBag(strName)
{
}

// @0x141410820
ItemBreakSlotBag::~ItemBreakSlotBag()
{
}

// @0x141410850
CString ItemBreakSlotBag::vfunc_15(int nIndex)
{
    return DragSlotBag::vfunc_15(nIndex);
}

// @0x1414108a0
DragSlot* ItemBreakSlotBag::vfunc_16(int nIndex)
{
    return new (efd::MemHint(efd::MemHint::NONE)) ItemBreakSlot(vfunc_15(nIndex), nIndex);
}

// @0x1414109a0
void FUN_1414109a0(DragSlotBag* pBag, int nIndex)
{
    DragSlot* pSlot = FUN_14140e5e0(FUN_1422cd070(pBag, nIndex));
    if (pSlot)
        pSlot->vfunc_10();
}

// @0x1414109f0
ItemBreakSlotBag* FUN_1414109f0(NotifyContext::BindData* p)
{
    ItemBreakSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620005c, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x14140FF80, ItemBreakSlot, vfunc_18, 220, 0xE6C7307A);
MS2_REPLACE_METHOD(0x141410070, ItemBreakSlot, vfunc_14, 176, 0x231C58CC);
MS2_REPLACE_METHOD(0x141410130, ItemBreakSlot, vfunc_15, 131, 0xAC2C2180);
MS2_REPLACE_METHOD(0x141410370, ItemBreakSlot, vfunc_8, 255, 0x9BF96D29);
MS2_REPLACE_METHOD(0x141410480, ItemBreakSlot, FUN_141410480, 188, 0xAFD9AFF5);
MS2_REPLACE_METHOD(0x1414101C0, ItemBreakSlot, vfunc_25, 73, 0x60C39FD2);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb1ab0-0x142cb1bd0 .text$yd
