// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MailItemSlot (the item slot of the mail window).
// MS2-UNIT: ?\mailitemslot.cpp
// MS2-RANGE: 0x1414723a0-0x141472ba0 .text$mn
// MS2-RANGE: 0x1400f77f0-0x1400f7980 .text$di
// MS2-PIN: ??_7MailItemSlot@@6BBindData@NotifyContext@@@ 0x142f17300
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mailitemslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "mailitemslot.h"
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
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);               // item link / popup for the item
CStringW GetStringCommon(int id);                         // string table lookup

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);

MailItemSlot* FUN_1414729b0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(MailItemSlot);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x1414723a0
MailItemSlot::MailItemSlot(const CString& strName, MS2Ptr<CItem> spItem, int nValue, int nIndex)
    : MS2DragSlot(strName, nIndex), m_spItem(spItem), m_nValue(nValue)
{
}

// @0x141472440
int MailItemSlot::GetItemId()
{
    if (m_spItem == 0)
        return 0;
    return m_spItem->FUN_1405276c0();
}

// @0x141472490
int MailItemSlot::HasItem()
{
    if (m_spItem.get() != 0)
        return 1;
    return 0;
}

// @0x1414724d0
int MailItemSlot::vfunc_11()
{
    m_spItem = 0;
    return DragSlot::vfunc_11();
}

// @0x141472510
int MailItemSlot::vfunc_14()
{
    return 0;
}

// @0x141472520
int MailItemSlot::vfunc_15()
{
    if (m_spItem == 0)
        return DragSlot::vfunc_15();
    FUN_140d2cfc0(m_spItem);
    return DragSlot::vfunc_15();
}

// @0x1414725a0
int MailItemSlot::vfunc_18(void* pv)
{
    return static_cast<DragSlot*>(pv)->vfunc_10();
}

// @0x1414725d0 (ITooltip::vfunc_0)
// MS2-FUNCTIONAL: ASTooltip::FUN_1409e25e0 returns bool in astooltip.h but int in the exe (no movzx before the test)
int MailItemSlot::vfunc_0(void* p)
{
    if (m_spItem == 0)
        return 0;
    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x80, 2);
    if (tip.FUN_1409e25e0(m_spItem.get(), m_nValue))
    {
        {
            CStringW strEmpty(L"");
            tip.FUN_1409c69b0(strEmpty);
        }
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x1414726f0
int MailItemSlot::vfunc_8(void* p)
{
    if (m_spItem == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), FUN_1403ed2d0()->FUN_141bd0cc0(), 0x15))
    {
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x1414727e0
void FUN_1414727e0(const CString& strName, MS2Ptr<CItem> spItem, int nValue, int nIndex)
{
    MailItemSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) MailItemSlot(strName, spItem, nValue, nIndex);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x1414728e0
void FUN_1414728e0(const CString& strName)
{
    MailItemSlot* pSlot = FUN_1414729b0(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x141472920
CStringW MailItemSlot::vfunc_22()
{
    return GetStringCommon(0x757);
}

// @0x141472960
MS2Ptr<CItem> MailItemSlot::vfunc_25()
{
    return m_spItem;
}

// @0x1414729b0
MailItemSlot* FUN_1414729b0(NotifyContext::BindData* p)
{
    MailItemSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x620003a, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2660-0x142cb26f0 .text$yd
