// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ItemScrollSlot (a single item slot of the item scroll windows),
// with the .text$di initializer of ItemScrollSlot::ms_ClassInfo. See itemscrollslot.h.
// MS2-UNIT: ?\itemscrollslot.cpp
// MS2-RANGE: 0x140d42540-0x140d431c0 .text$mn
// MS2-RANGE: 0x1400d2c20-0x1400d2c40 .text$di
// MS2-PIN: ??_7ItemScrollSlot@@6BBindData@NotifyContext@@@ 0x142e2b770 ; hand: primary vftable
// MS2-PIN: ?TypeCast@ItemScrollSlot@@UEBA_NIPEAPEAX@Z 0x140d430c0 ; hand
// MS2-PIN: ?TypeCast@ItemScrollSlot@@UEBA_NIPEAPEBX@Z 0x140d43110 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemscrollslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemscrollslot.h"
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

void FUN_140657820();                                   // invalid call of an empty Delegate (shared)

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);

ItemScrollSlot* FUN_140d42c30(NotifyContext::BindData* p);

// The Delegate member bodies used here (shared layout: one heap implementation; vftable 1 clone, 2 invoke).
template<> inline Delegate<void(ItemScrollSlot*, DragSlot*)>::~Delegate()
{
    if (m_pImpl)
        delete m_pImpl;
}
template<> inline Delegate<void(ItemScrollSlot*, DragSlot*)>& Delegate<void(ItemScrollSlot*, DragSlot*)>::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}
template<> inline Delegate<void(ItemScrollSlot*)>::~Delegate()
{
    if (m_pImpl)
        delete m_pImpl;
}
template<> inline Delegate<void(ItemScrollSlot*)>& Delegate<void(ItemScrollSlot*)>::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}
template<> inline void Delegate<void(ItemScrollSlot*)>::operator()(ItemScrollSlot* a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}
template<> inline void Delegate<void(ItemScrollSlot*, DragSlot*)>::operator()(ItemScrollSlot* a1, DragSlot* a2) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->Invoke(a1, a2);
}

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemScrollSlot);

// @0x140d42540
void FUN_140d42540(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem)
{
    ItemScrollSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) ItemScrollSlot(strName, nOwner, spItem);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x140d42630
void FUN_140d42630(const CString& strName)
{
    ItemScrollSlot* pSlot = FUN_140d42c30(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x140d42670
ItemScrollSlot::ItemScrollSlot(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, 0), m_nOwner(nOwner), m_spItem(spItem), m_nFlags(1)
{
}

// @0x140d42740
int ItemScrollSlot::vfunc_17()
{
    SetItem(MS2Ptr<CItem>(0));
    if (!m_fnRemove.IsNull())
        m_fnRemove(this);
    return vfunc_10();
}

// @0x140d427c0
int ItemScrollSlot::vfunc_18(void* p)
{
    if (!m_fnDrop.IsNull())
        m_fnDrop(this, static_cast<DragSlot*>(p));
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140d42820
int ItemScrollSlot::vfunc_14()
{
    vfunc_17();
    return 1;
}

// @0x140d42850
MS2Ptr<CItem> ItemScrollSlot::vfunc_25()
{
    return m_spItem;
}

// @0x140d428a0
void ItemScrollSlot::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}

// @0x140d428f0
__int64 ItemScrollSlot::FUN_140d428f0()
{
    if (m_spItem.get() != 0)
        return ((CItem*)m_spItem)->FUN_140526a50();
    return 0;
}

// @0x140d42940 (ITooltip::vfunc_0)
int ItemScrollSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASTooltip tip(pPlayer, 0x20, 2);
    int nOk = tip.FUN_1409e0d40(vfunc_25().get());
    if (nOk != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140d42a60
int ItemScrollSlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASSlot slot(2);
    int nOk = slot.FUN_1409c3860(vfunc_25().get(), pPlayer, m_nFlags);
    if (nOk != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140d42b70
void ItemScrollSlot::SetDropFn(ItemScrollSlotDropFn fn)
{
    m_fnDrop = fn;
}

// @0x140d42bc0
void ItemScrollSlot::SetRemoveFn(ItemScrollSlotRemoveFn fn)
{
    m_fnRemove = fn;
}

// @0x140d42c10
void ItemScrollSlot::SetFlags(int nFlags)
{
    m_nFlags = nFlags;
}

// @0x140d42c30
ItemScrollSlot* FUN_140d42c30(NotifyContext::BindData* p)
{
    ItemScrollSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200034, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE(0x140D42630, FUN_140d42630, 55, 0x7697323A);
MS2_REPLACE_METHOD(0x140D42740, ItemScrollSlot, vfunc_17, 122, 0x579E1D56);
MS2_REPLACE_METHOD(0x140D427C0, ItemScrollSlot, vfunc_18, 90, 0xF3417CA2);
MS2_REPLACE_METHOD(0x140D42820, ItemScrollSlot, vfunc_14, 38, 0xF4633F56);
MS2_REPLACE_METHOD(0x140D42850, ItemScrollSlot, vfunc_25, 67, 0x32060F89);
MS2_REPLACE_METHOD(0x140D428F0, ItemScrollSlot, FUN_140d428f0, 69, 0x5759F841);
MS2_REPLACE_METHOD(0x140D42A60, ItemScrollSlot, vfunc_8, 264, 0x6E642538);
MS2_REPLACE_METHOD(0x140D42C10, ItemScrollSlot, SetFlags, 25, 0xD3EC7A67);
MS2_REPLACE(0x140D42C30, FUN_140d42c30, 73, 0x7E105824);
