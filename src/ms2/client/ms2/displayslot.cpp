// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DisplaySlot (a one-item display slot).
// MS2-UNIT: ?\displayslot.cpp
// MS2-RANGE: 0x140a50440-0x140a50d40 .text$mn
// MS2-RANGE: 0x1400c3bb0-0x1400c3eb0 .text$di
// MS2-PIN: ??_7DisplaySlot@@6BBindData@NotifyContext@@@ 0x142dc8128
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\displayslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "displayslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
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
CStringW GetStringCommonByKey(const CStringW& str);            // string table lookup by key
void FUN_1412751f0(const CStringW& str, int a, int b);  // show a notice

// The inventory singleton: the item of a uid.
class Unk_DsInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nUid); };
extern Unk_DsInventory DAT_143ab2a90;

void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);

DisplaySlot* FUN_140a50b00(NotifyContext::BindData* p);
MS2DragSlot* FUN_140a50b50(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(DisplaySlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"
// The exe's .text$di holds a second full copy of the header statics after the first.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// @0x140a50440
DisplaySlot::DisplaySlot(const CString& strName, MS2Ptr<CItem> spItem, int nSlotType)
    : MS2DragSlot(strName, 0), m_spItem(spItem), m_nSlotType(nSlotType)
{
}

// @0x140a504e0
int DisplaySlot::vfunc_18(void* p)
{
    MS2DragSlot* pFrom = FUN_140a50b50((NotifyContext::BindData*)p);
    if (pFrom != 0)
    {
        MS2Ptr<CItem> spItem = pFrom->vfunc_25();
        if (spItem.get() != 0 && m_nSlotType != 0)
        {
            if (!spItem->FUN_1405277e0(m_nSlotType))
            {
                FUN_1412751f0(GetStringCommonByKey(L"s_item_err_not_match_slot_item"), 1, 1);
                return static_cast<DragSlot*>((DragSlot*)p)->vfunc_10();
            }
        }
        m_spItem = spItem;
        vfunc_10();
    }
    return static_cast<DragSlot*>((DragSlot*)p)->vfunc_10();
}

// @0x140a50670
int DisplaySlot::vfunc_14()
{
    m_spItem = 0;
    vfunc_10();
    return 1;
}

// @0x140a506b0
void FUN_140a506b0(DisplaySlot* pSlot, MS2Ptr<CItem> spItem)
{
    pSlot->m_spItem = spItem;
    pSlot->vfunc_10();
}

// @0x140a50710 (ITooltip::vfunc_0)
int DisplaySlot::vfunc_0(void* p)
{
    if (m_spItem == 0)
        return 0;
    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x20, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()))
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140a507f0
int DisplaySlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spItem == 0)
        return 0;
    if (DAT_143ab2a90.FUN_140a5d680(m_spItem->FUN_140526a50()) == 0)
        m_spItem = 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), pPlayer, 0x415))
    {
        slot.FUN_1409c3750(true);
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140a50980
__int64 FUN_140a50980(DisplaySlot* pSlot)
{
    if (pSlot->m_spItem == 0)
        return 0;
    return pSlot->m_spItem->FUN_140526a50();
}

// @0x140a509d0
void FUN_140a509d0(const CString& strName, MS2Ptr<CItem> spItem, int nSlotType)
{
    DisplaySlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) DisplaySlot(strName, spItem, nSlotType);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x140a50ac0
void FUN_140a50ac0(const CString& strName)
{
    DisplaySlot* pSlot = FUN_140a50b00(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x140a50b00
DisplaySlot* FUN_140a50b00(NotifyContext::BindData* p)
{
    DisplaySlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200087, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140a50b50
MS2DragSlot* FUN_140a50b50(NotifyContext::BindData* p)
{
    MS2DragSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200023, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f340-0x142c9f460 .text$yd
