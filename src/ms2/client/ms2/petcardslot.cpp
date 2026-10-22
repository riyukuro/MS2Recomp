// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PetCardSlot, PetConsumeSlot and their bags (the pet windows' slots).
// MS2-UNIT: ?\petcardslot.cpp
// MS2-RANGE: 0x140b77000-0x140b788d0 .text$mn
// MS2-RANGE: 0x1400c8b90-0x1400c8d80 .text$di
// MS2-PIN: ??_7PetCardSlot@@6BBindData@NotifyContext@@@ 0x142de2240 ; hand: primary vftable
// MS2-PIN: ??_7PetConsumeSlot@@6BBindData@NotifyContext@@@ 0x142de23d8 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\petcardslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "petcardslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
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

extern Unk_Inventory DAT_143ab2a90;                     // the player's inventory

// The pet system singleton (0x140535320): the uid of the item the pet currently uses.
class Unk_PetSystem
{
public:
    __int64 FUN_140c8b2e0();
};
Unk_PetSystem* FUN_140535320();

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

PetCardSlotBag* FUN_140b78150(NotifyContext::BindData* p);
PetConsumeSlotBag* FUN_140b781a0(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(PetCardSlot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(PetCardSlotBag);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(PetConsumeSlot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(PetConsumeSlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x140b77000
PetCardSlot::PetCardSlot(const CString& strName, int nIndex, unsigned __int64 nItemUid)
    : MS2DragSlot(strName, nIndex)
{
    m_nItemUid = nItemUid;
}

// @0x140b77070
PetCardSlot::~PetCardSlot()
{
}

// @0x140b770b0 (ITooltip::vfunc_0)
int PetCardSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return 0;
    int nFlags = 0x100;
    ASTooltip tip(pPlayer, nFlags, 2);
    if (tip.FUN_1409e0d40(spItem.get()) != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b771f0
int PetCardSlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(spItem.get(), pPlayer, 0x10401) != 0)
    {
        slot.FUN_1409c2650();
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b77330
MS2Ptr<CItem> PetCardSlot::vfunc_25()
{
    return DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
}

// @0x140b77380
unsigned __int64 PetCardSlot::GetItemUid()
{
    return m_nItemUid;
}

#define PET_MAX(a, b) ((a) > (b) ? (a) : (b))
#define PET_MIN(a, b) ((a) < (b) ? (a) : (b))

// @0x140b773a0
void FUN_140b773a0(const CString& strName, const ATL::CAtlArray<unsigned __int64>& uids)
{
    PetCardSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) PetCardSlotBag(strName, uids);
    if (pBag)
    {
        int nMax = 15;
        int nCap = DAT_143ab2a90.FUN_140a5d050(9);
        int nSlots = PET_MIN(PET_MAX((int)uids.GetCount(), 15), nCap);
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nSlots);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140b77500
void FUN_140b77500(const CString& strName)
{
    PetCardSlotBag* pBag = FUN_140b78150(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140b77550
PetCardSlotBag::PetCardSlotBag(const CString& strName, const ATL::CAtlArray<unsigned __int64>& uids)
    : DragSlotBag(strName)
{
    m_uids.Copy(uids);
}

// @0x140b775d0
PetCardSlotBag::~PetCardSlotBag()
{
}

// @0x140b77610
CString PetCardSlotBag::vfunc_15(int nIndex)
{
    CString str;
    str.Format("%s.PETCARD%d", (const char*)FUN_1422c89f0(), (unsigned)nIndex);
    return str;
}

// @0x140b776d0
DragSlot* PetCardSlotBag::vfunc_16(int nIndex)
{
    if (m_uids.GetCount() <= (size_t)nIndex)
        return 0;
    CString strName = vfunc_15(nIndex);
    unsigned __int64 nUid = m_uids.GetAt(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) PetCardSlot(strName, nIndex, nUid);
}

// @0x140b777f0
PetConsumeSlot::PetConsumeSlot(const CString& strName, int nIndex, unsigned __int64 nItemUid, int nCount)
    : MS2DragSlot(strName, nIndex)
{
    m_nCount = nCount;
    m_nItemUid = nItemUid;
}

// @0x140b77870
PetConsumeSlot::~PetConsumeSlot()
{
}

// @0x140b778b0 (ITooltip::vfunc_0)
int PetConsumeSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return 0;
    int nFlags = 0x100;
    ASTooltip tip(pPlayer, nFlags, 2);
    if (tip.FUN_1409e0d40(spItem.get()) != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b779f0
int PetConsumeSlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(spItem.get(), pPlayer, 0x10401) != 0)
    {
        slot.FUN_1409c2650();
        slot.FUN_1409c1f00(FUN_140b77be0());
        if (1 < (unsigned)m_nCount)
            slot.FUN_1409c2190(m_nCount);
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b77b70
MS2Ptr<CItem> PetConsumeSlot::vfunc_25()
{
    return DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
}

// @0x140b77bc0
unsigned __int64 PetConsumeSlot::GetItemUid()
{
    return m_nItemUid;
}

// @0x140b77be0
int PetConsumeSlot::FUN_140b77be0()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spItem == 0)
        return 1;
    if (((CItem*)spItem)->FUN_140528c60() != 0)
        return 1;
    if (((CItem*)spItem)->FUN_140528ca0() == 1)
        return 1;
    if (FUN_140535320()->FUN_140c8b2e0() == (__int64)m_nItemUid)
        return 1;
    return 0;
}

// @0x140b77cf0
void FUN_140b77cf0(const CString& strName, const ATL::CAtlArray<PetConsumeSlotBag::Entry>& entries)
{
    PetConsumeSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) PetConsumeSlotBag(strName, entries);
    if (pBag)
    {
        int nMax = 15;
        int nCap = DAT_143ab2a90.FUN_140a5d050(9);
        int nSlots = PET_MIN(PET_MAX((int)entries.GetCount(), 15), nCap);
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nSlots);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140b77e50
void FUN_140b77e50(const CString& strName)
{
    PetConsumeSlotBag* pBag = FUN_140b781a0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140b77ea0
PetConsumeSlotBag::PetConsumeSlotBag(const CString& strName, const ATL::CAtlArray<Entry>& entries)
    : DragSlotBag(strName)
{
    m_entries.Copy(entries);
}

// @0x140b77f20
PetConsumeSlotBag::~PetConsumeSlotBag()
{
}

// @0x140b77f60
CString PetConsumeSlotBag::vfunc_15(int nIndex)
{
    CString str;
    str.Format("%s.PETCARD%d", (const char*)FUN_1422c89f0(), (unsigned)nIndex);
    return str;
}

// @0x140b78020
DragSlot* PetConsumeSlotBag::vfunc_16(int nIndex)
{
    if (m_entries.GetCount() <= (size_t)nIndex)
        return 0;
    CString strName = vfunc_15(nIndex);
    Entry entry = m_entries.GetAt(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) PetConsumeSlot(strName, nIndex, entry.first, entry.second);
}

// @0x140b78150
PetCardSlotBag* FUN_140b78150(NotifyContext::BindData* p)
{
    PetCardSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200079, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// @0x140b781a0
PetConsumeSlotBag* FUN_140b781a0(NotifyContext::BindData* p)
{
    PetConsumeSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620007d, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x140B771F0, PetCardSlot, vfunc_8, 304, 0x5907B6EF);
MS2_REPLACE_METHOD(0x140B77330, PetCardSlot, vfunc_25, 72, 0x64D77ADE);
MS2_REPLACE_METHOD(0x140B77380, PetCardSlot, GetItemUid, 18, 0xEE8FE4C1);
MS2_REPLACE(0x140B773A0, FUN_140b773a0, 342, 0xC592DD3A);
MS2_REPLACE(0x140B77500, FUN_140b77500, 65, 0x7D3CD8AC);
MS2_REPLACE_METHOD(0x140B77610, PetCardSlotBag, vfunc_15, 175, 0x35FA3E2F);
MS2_REPLACE_METHOD(0x140B776D0, PetCardSlotBag, vfunc_16, 271, 0x037E7E8A);
MS2_REPLACE_METHOD(0x140B779F0, PetConsumeSlot, vfunc_8, 374, 0x570CE11F);
MS2_REPLACE_METHOD(0x140B77B70, PetConsumeSlot, vfunc_25, 72, 0x787A76A4);
MS2_REPLACE_METHOD(0x140B77BC0, PetConsumeSlot, GetItemUid, 18, 0xB95413A9);
MS2_REPLACE_METHOD(0x140B77BE0, PetConsumeSlot, FUN_140b77be0, 265, 0xF8714119);
MS2_REPLACE(0x140B77CF0, FUN_140b77cf0, 342, 0x02E66DF3);
MS2_REPLACE(0x140B77E50, FUN_140b77e50, 65, 0xA753BCAF);
MS2_REPLACE_METHOD(0x140B77F60, PetConsumeSlotBag, vfunc_15, 175, 0xC812C402);
MS2_REPLACE_METHOD(0x140B78020, PetConsumeSlotBag, vfunc_16, 299, 0x8D4F8608);
MS2_REPLACE(0x140B78150, FUN_140b78150, 73, 0xA6BDF7CB);
MS2_REPLACE(0x140B781A0, FUN_140b781a0, 73, 0x88EBD2AF);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0fb0-0x142ca1040 .text$yd
