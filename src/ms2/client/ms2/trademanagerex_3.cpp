// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TradeSlotBag: the trade window's slot container (third obj of
// the three consecutive trademanagerex.cpp objs; the exe unit ?\trademanagerex.cpp was split in the queue).
// MS2-UNIT: ?\trademanagerex.cpp#3
// MS2-RANGE: 0x14185e970-0x14185f0b0 .text$mn
// MS2-RANGE: 0x14010e800-0x14010e8e0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\trademanagerex.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "trademanagerex.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "hook/ms2hook.h"

// Game-system singleton (FUN_140a6a840 returns the global at 0x143ab7f08) that keeps the UIItemEventListener list.
class Unk_ItemEventSystem
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);     // register (no duplicates)
    void FUN_1419caeb0(UIItemEventListener* pListener);     // unregister
};
Unk_ItemEventSystem* FUN_140a6a840();

// Registry of named bags/slots (GFx bind data): lookup by name, add, remove.
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);


EE_IMPLEMENT_CONCRETE_CLASS_INFO(TradeSlotBag);

// Header-defined sort-name table (same 7 strings in every obj that includes the item-sort header).
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

// @0x14185e970
TradeSlotBag::TradeSlotBag(const CString& strName)
    : DragSlotBag(strName)
{
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
}

// @0x14185ea20
TradeSlotBag::~TradeSlotBag()
{
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
}

// @0x14185eac0
void TradeSlotBag::vfunc_18(void*)
{
}

// @0x14185eae0
void TradeSlotBag::vfunc_19(void*)
{
}

// @0x14185eb00
void TradeSlotBag::vfunc_20(void*)
{
}

// @0x14185eb20
DragSlot* TradeSlotBag::vfunc_16(int nIndex)
{
    CString strName = static_cast<DragSlotBag*>(this)->vfunc_15(nIndex);
    return new (efd::MemHint(efd::MemHint::PLATFORM_NONE)) TradeSlot(strName, MS2Ptr<CItem>(0), nIndex, IsMine());
}

// @0x14185ec30
void TradeSlotBag::SetMine(bool b)
{
    m_bMine = b;
}

// @0x14185ec50
bool TradeSlotBag::IsMine()
{
    return m_bMine;
}

// @0x14185ec70
int TradeSlotBag::FUN_14185ec70(void*)
{
    return 1;
}

// uid of the item on the table in slot nSlot (0 when none)
// @0x14185ec90
__int64 FUN_14185ec90(int nSlot)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2e80.FUN_14185b520(items);
    for (unsigned i = 0; i < items.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = items.GetAt(i);
        if (spItem.get() ? true : false)
        {
            if (((CItem*)spItem)->FUN_140526b50() == nSlot)
                return ((CItem*)spItem)->FUN_140526a50();
        }
    }
    return 0;
}

// @0x14185edc0
TradeSlotBag* FUN_14185edc0(NotifyContext::BindData* p)
{
    TradeSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620005a, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc0f0-0x142cbc120 .text$yd
