// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ItemEnchantSlotBag and ItemInfoSlot (2nd TU of the fused guess unit).
// MS2-UNIT: ?\itemcustomizecontroller.cpp#2
// MS2-RANGE: 0x141414d60-0x141416dd0 .text$mn
// MS2-RANGE: 0x1400f5fd0-0x1400f6320 .text$di
// MS2-RANGE: 0x142cb1d50-0x142cb1e90 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GItemEnchantSlotBag@@UEAAPEAXI@Z 0x141415220 ; unique
// MS2-PIN: ?GetClassDesc@ItemEnchantSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x141415280 ; unique
// MS2-PIN: ?SetupClassInfo@ItemEnchantSlotBag@@SAXPEAVClassInfo@efd@@_K@Z 0x141415290 ; unique
// MS2-PIN: ?TypeCast@ItemEnchantSlotBag@@UEBA_NIPEAPEAX@Z 0x1414152f0 ; unique
// MS2-PIN: ?TypeCast@ItemEnchantSlotBag@@UEBA_NIPEAPEBX@Z 0x141415340 ; unique
// MS2-PIN: ?GetClassDesc@ItemInfoSlot@@UEBAPEBVClassInfo@efd@@XZ 0x141416b80 ; prop
// MS2-PIN: ?TypeCast@ItemInfoSlot@@UEBA_NIPEAPEAX@Z 0x141416b90 ; order
// MS2-PIN: ?TypeCast@ItemInfoSlot@@UEBA_NIPEAPEBX@Z 0x141416be0 ; order
// MS2-PINS-END tplpin
// MS2-PIN: ??_7ItemInfoSlot@@6BBindData@NotifyContext@@@ 0x142f0fea8 ; hand: primary vftable
// MS2-PIN: ??__E?ms_ClassInfo@ItemInfoSlot@@2VClassInfo@efd@@B@@YAXXZ 0x1400f6160 ; hand: second ClassInfo init
// MS2-PIN: ??__Fs_condition@@YAXXZ 0x142cb1dc0 ; hand: atexit after s_stun
// MS2-PIN: ??__Fs_condition2@@YAXXZ 0x142cb1e70 ; hand: atexit after s_stun2
// MS2-PIN: ?IsNull@?$Delegate@$$A6AHPEAVItemInfoSlot@@@Z@@QEBA_NXZ 0x141416c30 ; hand: CanFn IsNull
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemcustomizecontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "iteminfoslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#include <exception>

// ---- out-of-unit callees ----
// Item template data (itemdata.cpp): the class name string is at +0x290.
class Unk_ItemDataX
{
public:
    char m_pad[0x290];
    CStringW m_strClass;
};
Unk_ItemDataX* FUN_140527840(CItem* pItem);             // CItem::GetItemData

// Game context: FUN_141bd0cc0 returns the local player (the tooltip owner).
class Unk_GameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_GameCtx* FUN_1403ed2d0();

// Exchange-scroll records: the singleton hands out a ref-counted record by item id.
class Unk_ExchangeData : public CPtred
{
public:
    char m_pad[0x24];                                   // +0x18
    int m_nRarity;                                      // +0x3c
    int m_nFlag;                                        // +0x40
};
class Unk_ExchangeMgr
{
public:
    MS2Ptr<Unk_ExchangeData> FUN_140595750(int nItemId);
};
Unk_ExchangeMgr* FUN_140f56960();

MS2Ptr<CItem> FUN_1419be700(unsigned __int64 uid);               // find an item by uid
CStringW FUN_1419021b0(int a, int b);                   // format "a/b"
CStringW FUN_14028de60(int id);                         // string table lookup
CStringW FUN_14028b8e0(const CStringW& str);            // string table lookup by key
void FUN_140d2d150(int nItemId, int nAmount);           // show the item's popup menu
void FUN_140cff1b0(const Scaleform::GFx::Value&, CString, CStringW);   // set a member of the movie to a string
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);
float FUN_140bf4fd0(float f);                           // ceilf
void FUN_140657820();                                   // 'invalid call' of an empty Delegate (shared)

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);                  // clear the bag's slots
ItemInfoSlot* FUN_140c69ab0(NotifyContext::BindData* p);   // BindData -> ItemInfoSlot (TypeCast), 0 on failure

// The empty-delegate error of ItemInfoSlotCanFn.
class InvalidCallException : public std::exception
{
public:
    InvalidCallException();                             // 0x14056be40
};

// Delegate bodies of the three callbacks (the exe checks for an empty delegate before the call).
template<> inline void ItemInfoSlotSlotFn::operator()(ItemInfoSlot* a1, ASSlot* a2) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->Invoke(a1, a2);
}
template<> inline void ItemInfoSlotTipFn::operator()(ItemInfoSlot* a1, ASTooltip* a2) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->Invoke(a1, a2);
}

// @0x141416840
// MS2-FUNCTIONAL: throw helper; exception object construction/unwind differs
void FUN_141416840()
{
    InvalidCallException ex;
    throw ex;
}
template<> inline int ItemInfoSlotCanFn::operator()(ItemInfoSlot* a1) const
{
    if (m_pImpl == 0)
        FUN_141416840();
    return m_pImpl->vfunc_2(a1);
}
template<> inline ItemInfoSlotCanFn::~Delegate() { if (m_pImpl) delete m_pImpl; }
template<> inline ItemInfoSlotCanFn& ItemInfoSlotCanFn::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl) delete m_pImpl;
    if (o.m_pImpl == 0) m_pImpl = 0;
    else m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

ItemEnchantSlotBag* FUN_1414151d0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemEnchantSlotBag);

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

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemInfoSlot);
static CString s_itemCount("itemCount");

static CString s_sortNames2[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// @0x141414d60
void FUN_141414d60(const CString& strName, const ATL::CAtlArray<unsigned __int64>& items)
{
    ItemEnchantSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) ItemEnchantSlotBag(strName, items);
    if (pBag)
    {
        int nCount = (int)(FUN_140bf4fd0((float)items.GetCount() / 4.0f) * 4.0f);
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x141414e50
void FUN_141414e50(const CString& strName)
{
    ItemEnchantSlotBag* pBag = FUN_1414151d0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x141414ea0
ItemEnchantSlotBag::ItemEnchantSlotBag(const CString& strName, const ATL::CAtlArray<unsigned __int64>& items)
    : DragSlotBag(strName)
{
    m_uids.Copy(items);
}

// @0x141414f20
ItemEnchantSlotBag::~ItemEnchantSlotBag()
{
    m_uids.RemoveAll();
}

// @0x141414f80
CString ItemEnchantSlotBag::vfunc_15(int nIndex)
{
    return DragSlotBag::vfunc_15(nIndex);
}

// @0x141414fd0
DragSlot* ItemEnchantSlotBag::vfunc_16(int nIndex)
{
    MS2Ptr<CItem> spItem(0);
    if (nIndex < (int)m_uids.GetCount())
        spItem = FUN_1419be700(m_uids.GetAt(nIndex));
    return new (efd::MemHint(efd::MemHint::NONE)) ItemInfoSlot(vfunc_15(nIndex), spItem, nIndex, 0x535, 0);
}

// @0x1414151d0
ItemEnchantSlotBag* FUN_1414151d0(NotifyContext::BindData* p)
{
    ItemEnchantSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620005d, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// @0x141415450
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags)
{
    ItemInfoSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) ItemInfoSlot(strName, spItem, nIndex, nIconType, nFlags);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x141415560
void FUN_141415560(const CString& strName, ItemInfoSlot::CreateParam* pParam)
{
    ItemInfoSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) ItemInfoSlot(strName, pParam);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x141415600
void FUN_141415600(const CString& strName)
{
    ItemInfoSlot* pSlot = FUN_140c69ab0(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x141415390
ItemInfoSlot::CreateParam::CreateParam()
    : m_spItem(0), m_nIndex(0), m_nIconType(0), m_nFlags(0), m_nTipArg(-1), m_bEnabled(false)
{
}

// @0x141415640
ItemInfoSlot::ItemInfoSlot(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags)
    : MS2DragSlot(strName, nIndex), m_nItemId(0), m_spItem(spItem), m_nTipArg(-1)
{
    int n1;
    if (nIconType != 0)
        n1 = nIconType;
    else
        n1 = 0x415;
    m_nIconType = n1;
    int n2;
    if (nFlags != 0)
        n2 = nFlags;
    else
        n2 = 0x20;
    m_nFlags = n2;
    UpdateItemId();
    SetEnabled(false);
}

// @0x1414157d0
ItemInfoSlot::ItemInfoSlot(const CString& strName, CreateParam* pParam)
    : MS2DragSlot(strName, pParam->m_nIndex), m_nItemId(0), m_spItem(pParam->m_spItem),
      m_strSlotText(pParam->m_strSlotText), m_strTip(pParam->m_strTip), m_nTipArg(pParam->m_nTipArg)
{
    int n1;
    if (pParam->m_nIconType != 0)
        n1 = pParam->m_nIconType;
    else
        n1 = 0x415;
    m_nIconType = n1;
    int n2;
    if (pParam->m_nFlags != 0)
        n2 = pParam->m_nFlags;
    else
        n2 = 0x20;
    m_nFlags = n2;
    m_strCount = pParam->m_strCount;
    UpdateItemId();
    SetEnabled(pParam->m_bEnabled);
}

// @0x1414159a0
ItemInfoSlot::~ItemInfoSlot()
{
}

// @0x141415a70
int ItemInfoSlot::vfunc_15()
{
    if (m_spItem.get())
        FUN_140d2d150(m_spItem->FUN_1405276c0(), m_spItem->FUN_140526bd0());
    return DragSlot::vfunc_15();
}

// @0x141415af0
void ItemInfoSlot::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
    UpdateItemId();
}

// @0x141415b40
int ItemInfoSlot::GetItemId()
{
    return m_nItemId;
}

// @0x141415bb0
void ItemInfoSlot::UpdateItemId()
{
    int nId;
    if (m_spItem.get() != 0)
        nId = m_spItem->FUN_1405276c0();
    else
        nId = 0;
    m_nItemId = nId;
}

// @0x141415b60
MS2Ptr<CItem> ItemInfoSlot::vfunc_25()
{
    return m_spItem;
}

// @0x141415c20
int ItemInfoSlot::vfunc_11()
{
    m_nItemId = 0;
    return DragSlot::vfunc_11();
}

// @0x141415c50
int ItemInfoSlot::vfunc_18(void* pv)
{
    DragSlot* p = static_cast<DragSlot*>(pv);
    if (p == 0)
        return 1;
    return p->vfunc_10();
}

// @0x141415c90 (ITooltip::vfunc_0)
// MS2-FUNCTIONAL: tooltip builder; EH state layout/temp ordering differs from exe
int ItemInfoSlot::vfunc_0(void* p)
{
    if (!m_fnCan.IsNull() && m_fnCan(this) == 0)
        return 0;
    if (m_spItem == 0 && m_strTip.GetLength() != 0)
    {
        ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), m_nFlags, 2);
        if (tip.FUN_1409e26b0(m_strTip))
        {
            if (m_nTipArg != -1)
                tip.FUN_1409c6dc0(m_nTipArg);
            *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
            return 1;
        }
    }
    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), m_nFlags, 2);
    int nResult = 0;
    if (!m_fnTip.IsNull())
    {
        m_fnTip(this, &tip);
        nResult = 1;
    }
    else
    {
        if (m_spItem.get())
        {
            if (FUN_1403b3c40(FUN_140527840(m_spItem.operator->())->m_strClass, L"ItemExchangeScroll"))
            {
                void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPlayer == 0)
                    return 0;
                MS2Ptr<Unk_ExchangeData> spData = FUN_140f56960()->FUN_140595750(m_spItem->FUN_1405276c0());
                if (spData.get())
                {
                    MS2Ptr<CItem> spCmp(new CItem);
                    if (spCmp.get())
                    {
                        if (!spCmp->FUN_14052b130(spData->m_nRarity, spData->m_nFlag, 0))
                            return 0;
                        ASTooltip tip2(pPlayer, 0x800, 2);
                        if (tip2.FUN_1409e13f0(spCmp.get(), m_spItem.get(), 0x800, 0x80))
                        {
                            {
                                CStringW strEmpty(L"");
                                tip2.FUN_1409c6a20(strEmpty, FUN_14028de60(0x75a));
                            }
                            {
                                CStringW strEmpty(L"");
                                CStringW strKey(L"s_word_compose_result");
                                tip2.FUN_1409c7060(FUN_14028b8e0(strKey), strEmpty);
                            }
                            *static_cast<Scaleform::GFx::Value*>(p) = tip2.FUN_1422bb870();
                            return 1;
                        }
                    }
                }
                goto done;
            }
        }
        nResult = tip.FUN_1409e0d40(m_spItem.get());
        if (IsEnabled())
            tip.FUN_1409db7b0(m_spItem);
    }
done:
    if (nResult == 1)
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
    return nResult == 1;
}

// @0x141416380
int ItemInfoSlot::vfunc_8(void* p)
{
    ASSlot slot(2);
    MS2Ptr<CItem> spItem = m_spItem;
    if (!spItem)
    {
        if (m_strSlotText.GetLength() != 0 && slot.FUN_1409c48b0(m_strSlotText))
        {
            if (m_strCount.GetLength() > 0)
                slot.FUN_1407cba60((const char*)s_itemCount, m_strCount);
            *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
            return 1;
        }
        return 0;
    }
    if (slot.FUN_1409c3860(spItem.get(), FUN_1403ed2d0()->FUN_141bd0cc0(), m_nIconType))
    {
        if (!m_fnSlot.IsNull())
            m_fnSlot(this, &slot);
        if (m_strCount.GetLength() > 0)
            slot.FUN_1407cba60((const char*)s_itemCount, m_strCount);
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x141416650
void ItemInfoSlot::SetSlotFn(ItemInfoSlotSlotFn fn)
{
    m_fnSlot = fn;
}

// @0x1414166a0
void ItemInfoSlot::SetTipFn(ItemInfoSlotTipFn fn)
{
    m_fnTip = fn;
}

// @0x1414166f0
void ItemInfoSlot::SetCanFn(ItemInfoSlotCanFn fn)
{
    m_fnCan = fn;
}

// @0x141416740
// MS2-FUNCTIONAL: exe builds two extra CString temps via IAT conversions around FUN_1419021b0; frame/EH states differ
void ItemInfoSlot::SetCountText(int a, int b)
{
    AScript root(m_value18, 2);
    if (root.FUN_1422ba9a0())
        return;
    FUN_140cff1b0(m_value18, "m_count", FUN_1419021b0(a, b));
}

MS2_EMIT_CRT_MEMMOVE_S();
