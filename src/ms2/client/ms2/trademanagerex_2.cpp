// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TradeSlot: one slot of the trade window (second of the three
// consecutive trademanagerex.cpp objs; the exe unit ?\trademanagerex.cpp was split in the queue).
// MS2-UNIT: ?\trademanagerex.cpp#2
// MS2-RANGE: 0x14185dca0-0x14185e970 .text$mn
// MS2-RANGE: 0x14010e670-0x14010e800 .text$di
// MS2-PIN: ??_7TradeSlot@@6BBindData@NotifyContext@@@ 0x142f87cc0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\trademanagerex.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "trademanagerex.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "hook/ms2hook.h"

// Item template data (itemdata.cpp): the pickup/drop sound name.
class Unk_TradeItemData
{
public:
    CString FUN_14053eca0();
};
Unk_TradeItemData* FUN_140527840(CItem* pItem);         // CItem::GetItemData

// Sound player (effectservice.cpp): FUN_1403ed280 is its singleton getter.
class Unk_SoundPlayer
{
public:
    int FUN_1411a5110(CString strDir, CString strName, CString strSub, int a4, __int64 a5, float fVolume, int a7);
};
Unk_SoundPlayer* FUN_1403ed280();

// Game context: FUN_141bd0cc0 returns the local player (the tooltip owner).
class Unk_GameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_GameCtx* FUN_1403ed2d0();

// The inventory slot (invenslot.cpp) a trade slot can be dropped on: id 0x6200023.
class Unk_InvenSlot : public DragSlot
{
public:
    __int64 FUN_141405a10();                            // the uid of the item in the slot
    int FUN_14140b6d0(MS2Ptr<CItem> spItem);            // put the item into the slot
};
Unk_InvenSlot* FUN_140a50b50(DragSlot* pSlot);          // pSlot->TypeCast(0x6200023), 0 on failure

// The bag of the player's inventory items by uid.
class Unk_InventoryItems
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 uid);
};
extern Unk_InventoryItems DAT_143ab2a90;

// Item context-menu actions.
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);               // show the item's popup (id, rarity, template)

CStringW FUN_14028de60(int id);                         // string table lookup

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);                  // clear the bag's slots
class TradeSlotBag;
TradeSlotBag* FUN_14185edc0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(TradeSlot);

// Header-defined statics (same in every obj that includes the shared item header).
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
class Unk_1402a9d70
{
public:
    Unk_1402a9d70(int, float, float, float, int);
    ~Unk_1402a9d70();
private:
    void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48;
};
MS2_CHECK_SIZE(Unk_1402a9d70, 0x50);
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// @0x14185dca0
TradeSlot::TradeSlot(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, bool bMine)
    : MS2DragSlot(strName, nIndex), m_spItem(spItem), m_bMine(bMine)
{
    FUN_140a7bd80(true);
}

// @0x14185dd50
int TradeSlot::vfunc_14()
{
    if (FUN_14185e630())
    {
        FUN_14185e370(m_spItem);
        FUN_14140ea30()->SendTradeMode9(FUN_14185e580(), FUN_1422cc410());
    }
    return 1;
}

// @0x14185ddf0
int TradeSlot::vfunc_15()
{
    if (m_spItem.get())
        FUN_140d2cfc0(m_spItem);
    return DragSlot::vfunc_15();
}

// @0x14185de60
int TradeSlot::vfunc_18(void* p)
{
    Unk_InvenSlot* pInven = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pInven != 0)
    {
        if (FUN_14185e630())
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(pInven->FUN_141405a10());
            if (spItem.get())
                pInven->FUN_14140b6d0(spItem);
        }
        pInven->vfunc_10();
    }
    else
    {
        static_cast<DragSlot*>(p)->vfunc_10();
    }
    return 1;   // MS2-FUNCTIONAL: the exe's override returns void (eax is whatever vfunc_10 left)
}

// @0x14185df40 (ITooltip::vfunc_0)
int TradeSlot::vfunc_0(void* p)
{
    bool bMine = FUN_14185e630();
    int nFlags = bMine ? 0x80 : 0x1000;
    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), nFlags, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()))
    {
        if (FUN_14185e630())
        {
            tip.FUN_1409c69b0(FUN_14028de60(0x750));
            {
                CStringW strText(L"");
                tip.FUN_1409c65f0(strText);
            }
        }
        else
        {
            {
                CStringW strTitle(L"");
                tip.FUN_1409c69b0(strTitle);
            }
            {
                CStringW strText(L"");
                tip.FUN_1409c65f0(strText);
            }
        }
        if (FUN_140a7bd60() == 1)
            tip.FUN_1409db7b0(vfunc_25());
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x14185e1b0
int TradeSlot::vfunc_8(void* p)
{
    if (m_spItem == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), FUN_1403ed2d0()->FUN_141bd0cc0(), 0x1c81f))
    {
        if (!FUN_14185e630())
            slot.FUN_1409c2650();
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x14185e2c0
int TradeSlot::vfunc_20()
{
    DragSlot::vfunc_20();
    FUN_14185e370(m_spItem);
    return 1;
}

// @0x14185e320
MS2Ptr<CItem> TradeSlot::vfunc_25()
{
    return m_spItem;
}

// @0x14185e370
void TradeSlot::FUN_14185e370(MS2Ptr<CItem> spItem)
{
    if (spItem.get() ? true : false)
    {
        if (FUN_140527840(spItem.operator->()))
        {
            FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), FUN_140527840(spItem.operator->())->FUN_14053eca0(), CString(""), 0, 0, 1.0f, 0);
        }
    }
}

// @0x14185e4e0
void TradeSlot::FUN_14185e4e0(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}

// @0x14185e530
int TradeSlot::FUN_14185e530()
{
    if (m_spItem.get())
        return m_spItem->FUN_1405276c0();
    return 0;
}

// @0x14185e580
__int64 TradeSlot::FUN_14185e580()
{
    if (m_spItem.get())
        return m_spItem->FUN_140526a50();
    return 0;
}

// @0x14185e5d0
void TradeSlot::FUN_14185e5d0()
{
    if (FUN_14185e630())
        FUN_14140ea30()->SendTradeMode9(FUN_14185e580(), FUN_1422cc410());
}

// @0x14185e630
bool TradeSlot::FUN_14185e630()
{
    return m_bMine;
}

// @0x14185e670
CStringW TradeSlot::vfunc_22()
{
    return FUN_14028de60(0x750);
}

// @0x14185e850
void FUN_14185e850(const CString& strName, int nCount, bool bMine)
{
    TradeSlotBag* pBag = new (efd::MemHint(efd::MemHint::PLATFORM_NONE)) TradeSlotBag(strName);
    if (pBag)
    {
        pBag->FUN_14185ec30(bMine);
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14185e920
void FUN_14185e920(const CString& strName)
{
    TradeSlotBag* pBag = FUN_14185edc0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc060-0x142cbc0f0 .text$yd
