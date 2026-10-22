// petcardslot.h - PetCardSlot / PetCardSlotBag and PetConsumeSlot / PetConsumeSlotBag: the item slots of the pet windows
// (a pet card item, and a consumed item with a count). The slots hold an item uid (looked up in the inventory on use);
// the bags hold the uids and create one slot per entry. Owning unit: ?\petcardslot.cpp (0x140b77000-0x140b788d0).
// Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0x98 bytes. vftable 0x142de2240 (26 slots, ??_G 0x140b781f0 sized delete 0x98), ITooltip @+0x78.
class PetCardSlot : public MS2DragSlot
{
public:
    PetCardSlot(const CString& strName, int nIndex, unsigned __int64 nItemUid);     // 0x140b77000
    virtual ~PetCardSlot();                             // 0x140b77070

    // slots 2-4: GetClassDesc 0x140b78370, TypeCast 0x140b78530 / 0x140b78580; ms_ClassInfo 0x143abb8e0,
    // SetupClassInfo 0x140b783b0 (parent MS2DragSlot, id 0x6200078).
    EE_DECLARE_CLASS1(PetCardSlot, 0x06200078, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140b771f0 build the item slot into p
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140b77330 the item in the slot (by uid)
    virtual int vfunc_0(void* p);                       // ITooltip 0x140b770b0 build the tooltip into p

    unsigned __int64 GetItemUid();                   // the item uid

public:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nItemUid;                        // +0x90
};
MS2_CHECK_SIZE(PetCardSlot, 0x98);
MS2_CHECK_OFFSET(PetCardSlot, m_nItemUid, 0x90);

// 0xa8 bytes. vftable (16 slots, ??_G 0x140b78250 sized delete 0xa8).
class PetCardSlotBag : public DragSlotBag
{
public:
    PetCardSlotBag(const CString& strName, const ATL::CAtlArray<unsigned __int64>& uids);   // 0x140b77550
    virtual ~PetCardSlotBag();                          // 0x140b775d0

    // slots 2-4: GetClassDesc 0x140b78380, TypeCast 0x140b785d0 / 0x140b78620; ms_ClassInfo 0x143abbcf0,
    // SetupClassInfo 0x140b78410 (parent DragSlotBag, id 0x6200079).
    EE_DECLARE_CLASS1(PetCardSlotBag, 0x06200079, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x140b77610 "<bag>.PETCARD<n>"
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x140b776d0 new PetCardSlot for the uid at nIndex (0 past the end)

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<unsigned __int64> m_uids;            // +0x88 item uids
};
MS2_CHECK_SIZE(PetCardSlotBag, 0xa8);
MS2_CHECK_OFFSET(PetCardSlotBag, m_uids, 0x88);

// 0xa0 bytes. vftable 0x142de23d8 (26 slots, ??_G 0x140b782b0 sized delete 0xa0), ITooltip @+0x78.
class PetConsumeSlot : public MS2DragSlot
{
public:
    PetConsumeSlot(const CString& strName, int nIndex, unsigned __int64 nItemUid, int nCount);     // 0x140b777f0
    virtual ~PetConsumeSlot();                          // 0x140b77870

    // slots 2-4: GetClassDesc 0x140b78390, TypeCast 0x140b78670 / 0x140b786c0; ms_ClassInfo 0x143abc100,
    // SetupClassInfo 0x140b78470 (parent MS2DragSlot, id 0x620007c). Its SetupClassInfo registers the name "PetCardSlot"
    // (a copy-paste in the original source), so the declaration below names PetCardSlot.
    EE_DECLARE_CLASS1(PetCardSlot, 0x0620007C, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140b779f0 build the item slot into p (count, seal marks)
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140b77b70 the item in the slot (by uid)
    virtual int vfunc_0(void* p);                       // ITooltip 0x140b778b0 build the tooltip into p

    unsigned __int64 GetItemUid();                   // the item uid
    int FUN_140b77be0();                                // the item is sealed (or missing)

public:
    MS2_LAYOUT_FRIEND;
    int m_nCount;                                       // +0x90
    int m_pad_94;
    unsigned __int64 m_nItemUid;                        // +0x98
};
MS2_CHECK_SIZE(PetConsumeSlot, 0xa0);
MS2_CHECK_OFFSET(PetConsumeSlot, m_nCount, 0x90);
MS2_CHECK_OFFSET(PetConsumeSlot, m_nItemUid, 0x98);

// 0xa8 bytes. vftable (16 slots, ??_G 0x140b78310 sized delete 0xa8).
class PetConsumeSlotBag : public DragSlotBag
{
public:
    // (uid, count) per slot.
    typedef std::pair<unsigned __int64, int> Entry;

    PetConsumeSlotBag(const CString& strName, const ATL::CAtlArray<Entry>& entries);   // 0x140b77ea0
    virtual ~PetConsumeSlotBag();                       // 0x140b77f20

    // slots 2-4: GetClassDesc 0x140b783a0, TypeCast 0x140b78710 / 0x140b78760; ms_ClassInfo 0x143abc510,
    // SetupClassInfo 0x140b784d0 (parent DragSlotBag, id 0x620007d).
    EE_DECLARE_CLASS1(PetConsumeSlotBag, 0x0620007D, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x140b77f60 "<bag>.PETCARD<n>"
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x140b78020 new PetConsumeSlot for the entry at nIndex (0 past the end)

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<Entry> m_entries;                    // +0x88
};
MS2_CHECK_SIZE(PetConsumeSlotBag, 0xa8);
MS2_CHECK_OFFSET(PetConsumeSlotBag, m_entries, 0x88);
