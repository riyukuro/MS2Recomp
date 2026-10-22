// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ItemExchangeSlot (the item slot of the exchange-scroll dialog).
// MS2-UNIT: ?\itemexchangeslot.cpp
// MS2-RANGE: 0x140b6c7a0-0x140b6d070 .text$mn
// MS2-RANGE: 0x1400c8430-0x1400c85c0 .text$di
// MS2-PIN: ??_7ItemExchangeSlot@@6BBindData@NotifyContext@@@ 0x142de00f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemexchangeslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemexchangeslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uidialog.h"
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

// The inventory slot (invenslot.cpp) a slot can be dropped on: id 0x6200023.
class Unk_InvenSlot : public DragSlot
{
public:
    __int64 FUN_141405a10();                            // the uid of the item in the slot
};
Unk_InvenSlot* FUN_140a50b50(DragSlot* pSlot);          // pSlot->TypeCast(0x6200023), 0 on failure

// The inventory's bag of items by uid.
class Unk_IesInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nUid); };
extern Unk_IesInventory DAT_143ab2a90;

// The dialog this slot lives on (uiitemexchangescrolldialog.cpp).
class UIItemExchangeScrollDialog : public UIDialog
{
public:
    void FUN_140f52c80();                               // refresh after the item changed
};

// UI registry: a handle to a registered UI object.
class Unk_IesUIRef
{
public:
    ~Unk_IesUIRef();                                    // FUN_1403e5630
    UIObject* FUN_1403e8a70() const;
    UIObject* FUN_1403ed9e0();
private:
    void* unknown;
    UIObject* object;
};
class Unk_IesUIMgr { public: Unk_IesUIRef FUN_141adcea0(int nId); };
Unk_IesUIMgr* FUN_1403ed2b0();

void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);

ItemExchangeSlot* FUN_140b6cde0(NotifyContext::BindData* p);
UIItemExchangeScrollDialog* FUN_140b6ce30(int nId);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemExchangeSlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x140b6c7a0
void FUN_140b6c7a0(const CString& strName, __int64 nTarget, MS2Ptr<CItem> spItem)
{
    ItemExchangeSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) ItemExchangeSlot(strName, nTarget, spItem);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x140b6c890
void FUN_140b6c890(const CString& strName)
{
    ItemExchangeSlot* pSlot = FUN_140b6cde0(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x140b6c8d0
ItemExchangeSlot::ItemExchangeSlot(const CString& strName, __int64 nTarget, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, 0), m_nTarget(nTarget), m_spItem(spItem)
{
}

// @0x140b6c970
// MS2-FUNCTIONAL: the exe's override returns void (no eax=1); DragSlot::vfunc_17 is int here
int ItemExchangeSlot::vfunc_17()
{
    SetItem(MS2Ptr<CItem>(0));
    UIItemExchangeScrollDialog* pDlg = FUN_140b6ce30(0x4f14);
    if (pDlg)
        pDlg->FUN_140f52c80();
    vfunc_10();
    return 1;
}

// @0x140b6c9e0
int ItemExchangeSlot::vfunc_18(void* p)
{
    Unk_InvenSlot* pInven = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pInven != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(pInven->FUN_141405a10());
        if (spItem.get() != 0)
        {
            COutPacket packet(static_cast<int>(SendOp::ItemExchangeScroll), 0);
            packet.WriteUInt8(0);
            packet.WriteInt64(m_nTarget);
            packet.WriteInt64(spItem->FUN_140526a50());
            FUN_140710590(packet);
        }
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140b6caf0
int ItemExchangeSlot::vfunc_14()
{
    vfunc_17();
    return 1;
}

// @0x140b6cb20
MS2Ptr<CItem> ItemExchangeSlot::vfunc_25()
{
    return m_spItem;
}

// @0x140b6cb70
void ItemExchangeSlot::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}

// @0x140b6cbc0 (ITooltip::vfunc_0)
int ItemExchangeSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASTooltip tip(pPlayer, 0x20, 2);
    int nResult = tip.FUN_1409e0d40(vfunc_25().get());
    if (nResult != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b6cce0
int ItemExchangeSlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASSlot slot(2);
    int nResult = slot.FUN_1409c3860(vfunc_25().get(), pPlayer, 1);
    if (nResult != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b6cde0
ItemExchangeSlot* FUN_140b6cde0(NotifyContext::BindData* p)
{
    ItemExchangeSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200077, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140b6ce30
UIItemExchangeScrollDialog* FUN_140b6ce30(int nId)
{
    if (FUN_1403ed2b0())
    {
        Unk_IesUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIItemExchangeScrollDialog*>(ref.FUN_1403ed9e0());
    }
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0cc0-0x142ca0d50 .text$yd
