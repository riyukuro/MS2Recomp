// dragslot.h - GFx UI library slot classes: NotifyContext::BindData (NiRefObject + name + two GFx values + array),
// ITooltip (1-slot interface) and DragSlot (BindData + ITooltip; drag & drop item slot). Base of MS2DragSlot
// (client/ms2/ms2dragslot.h) and its ~30 game slot classes. The code lives in the GFx UI library range
// (0x1422c88e0-0x1422cc830, inside unit_1422b0000 / decomp-gfxui); header name and directory assumed.
//
// HOW TO USE THIS HEADER (for unit workers):
// - Game slots derive from MS2DragSlot, not directly from DragSlot. vfunc_N = slot N of the primary vftable.
// - Slots 2-4 are efd RTTI: EE_BEGIN_DECLARE_CLASS emits GetClassDesc (return &ms_ClassInfo) and the two
//   TypeCast overloads (ms_ClassInfo.TypeCast = 0x1409f31d0). Every derived class declares its own
//   EE_DECLARE_CLASS1(X, <id>, <parent>) - find the id in its SetupClassInfo (`FUN_1409f2e10(p,"<Name>",id,...)`).
//   ms_ClassInfo objects are bound as data symbols in progress/symbols-manual.tsv.
// - Slot bodies that just forward (`return vfunc_10();`) are written int: void vs int is byte-identical there.
// - None of these have recovered .cpp files; ctors/dtors are bound by VA (progress/symbols-manual.tsv).
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <efd/ClassInfo.h>
#include <NiRefObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"

namespace NotifyContext {

// 0x78 bytes. vftable 0x14310c898 (10 slots, ??_G 0x1422c9a80).
class BindData : public NiRefObject
{
public:
    explicit BindData(const CString& strName);      // 0x1422c88e0
    virtual ~BindData();                            // 0x1422c8970

    // slots 2-4: GetClassDesc 0x1422c9f20, TypeCast 0x1422cc220 / 0x1422cc270; ms_ClassInfo 0x143b0ae50,
    // SetupClassInfo 0x140a36910 (no parents).
    EE_DECLARE_CLASS(BindData, 0x06202734);
public:
    virtual void vfunc_5();                         // 5 0x1422c8d60 {}
    virtual void vfunc_6(void* p);                  // 6 0x1422c8d70 {}
    virtual int vfunc_7(void* p);                   // 7 0x1422c8d90 return 1
    virtual int vfunc_8(void* p);                   // 8 0x1422c8db0 return 0
    virtual void vfunc_9();                         // 9 0x1422c8dd0 {}
    CString FUN_1422c89f0();                        // 0x1422c89f0 a copy of m_strName
    Scaleform::GFx::Value& FUN_1422c8d40();         // 0x1422c8d40 &m_value18 (the slot's AS data)

public:
    MS2_LAYOUT_FRIEND;
    CString m_strName;                              // +0x10
    Scaleform::GFx::Value m_value18;                // +0x18
    Scaleform::GFx::Value m_value38;                // +0x38
    CAtlArray<void*> m_arr58;                       // +0x58
};

} // namespace NotifyContext
MS2_CHECK_SIZE(NotifyContext::BindData, 0x78);
MS2_CHECK_OFFSET(NotifyContext::BindData, m_strName, 0x10);
MS2_CHECK_OFFSET(NotifyContext::BindData, m_value38, 0x38);
MS2_CHECK_OFFSET(NotifyContext::BindData, m_arr58, 0x58);

// 8 bytes, vftable 0x14310c8f8 (1 pure slot). No virtual dtor.
class ITooltip
{
public:
    virtual int vfunc_0(void* p) = 0;               // DragSlot: 0x1422cc690 return 0
};

// 0x88 bytes. vftable 0x14310c908 (25 slots, ??_G 0x1422cc750); ITooltip vftable @+0x78 0x14310c9d8.
class DragSlot : public NotifyContext::BindData, public ITooltip
{
public:
    DragSlot(const CString& strName, int nIndex);   // 0x1422cc350
    virtual ~DragSlot();                            // 0x1422cc3d0

    // slots 2-4: GetClassDesc 0x1422cc7b0, TypeCast 0x1422cc7c0 / 0x1422cc810; ms_ClassInfo 0x143b0b2b0,
    // SetupClassInfo 0x140a369b0 (includes BindData only; ITooltip has no RTTI).
    EE_DECLARE_CLASS1(DragSlot, 0x06202735, NotifyContext::BindData);
public:
    virtual void vfunc_5();                         // 5  0x1422cc4c0 if (m_bDragging) vfunc_21()
    virtual int vfunc_7(void* p);                   // 7  0x1422cc660 return vfunc_10()
    virtual int vfunc_10();                         // 10 0x1422cc430 FUN_1422c8be0(this); return 1
    virtual int vfunc_11();                         // 11 0x1422cc460 FUN_1422c8b50(this); return 1
    virtual int vfunc_12();                         // 12 0x1422cc490 return vfunc_10()
    virtual int vfunc_13();                         // 13 0x1422cc500 return vfunc_10()
    virtual int vfunc_14();                         // 14 0x1422cc530 return vfunc_10()
    virtual int vfunc_15();                         // 15 0x1422cc560 return vfunc_10()
    virtual int vfunc_16();                         // 16 0x1422cc590 return vfunc_10()
    virtual int vfunc_17();                         // 17 0x1422cc5c0 return vfunc_12()
    virtual int vfunc_18(void* p);                  // 18 0x1422cc5f0 return 1
    virtual int vfunc_19();                         // 19 0x1422cc610 return 0
    virtual int vfunc_20();                         // 20 0x1422cc620 m_bDragging = 1; return 1
    virtual int vfunc_21();                         // 21 0x1422cc640 m_bDragging = 0; return 1
    virtual CStringW vfunc_22();                    // 22 0x1422cc6b0 return literal 0x14310c8e8
    virtual void vfunc_23(void* p);                 // 23 0x1422cc700 {}
    virtual void vfunc_24(void* p);                 // 24 0x1422cc720 {}

    // ITooltip
    virtual int vfunc_0(void* p);                   // 0x1422cc690 return 0

    int FUN_1422cc410();                            // return m_nIndex

public:
    int m_nIndex;                                   // +0x80 ctor arg
    int m_bDragging;                                // +0x84
};
MS2_CHECK_SIZE(DragSlot, 0x88);
MS2_CHECK_OFFSET(DragSlot, m_nIndex, 0x80);
MS2_CHECK_OFFSET(DragSlot, m_bDragging, 0x84);

// 0x88 bytes. Container of named DragSlots ("<bag name>.<index>"). vftable 0x14310cbd0 (17 slots, ??_G 0x1422cda80).
// Derived bags (TradeSlotBag, InventorySlotBag, ...) start their members / UIItemEventListener base at +0x88.
class DragSlotBag : public NotifyContext::BindData
{
public:
    explicit DragSlotBag(const CString& strName);   // 0x1422cc8f0
    virtual ~DragSlotBag();                         // 0x1422cc950

    // slots 2-4: GetClassDesc 0x1422cdae0, TypeCast 0x1422cdaf0 / 0x1422cdb40; ms_ClassInfo 0x143b0b6c0,
    // SetupClassInfo 0x140a375e0.
    EE_DECLARE_CLASS1(DragSlotBag, 0x06202736, NotifyContext::BindData);
public:
    virtual void vfunc_10(int nCount);              // 10 0x1422cc990 for i < n: FUN_1422ccb50(this, i) (create slots)
    virtual void vfunc_11(void* p);                 // 11 0x1422ccd50 for each slot: slot->vfunc_23(p)
    virtual void vfunc_12(void* p);                 // 12 0x1422cce30 for each slot: slot->vfunc_24(p)
    virtual void vfunc_13(int i);                   // 13 0x1422ccf10 slot(i)->vfunc_11()
    virtual void vfunc_14(int i);                   // 14 0x1422ccf60 slot(i)->vfunc_10()
    virtual CString vfunc_15(int i);                // 15 0x1422cd120 Format("%s.%d", m_strName, i)
    virtual DragSlot* vfunc_16(int n);              // 16 0x1422cd1a0 return 0 (creates the slot for index n; TradeSlotBag: new TradeSlot)

public:
    std::map<int, CString> m_slots;                 // +0x78 slot index -> slot name ("<bag name>.<index>"); FUN_1422ccb50 inserts,
                                                    // vfunc_11/12 walk it (init 0x141000090, dtor 0x1410004f0, clear 0x1410083f0)
};
MS2_CHECK_SIZE(DragSlotBag, 0x88);
MS2_CHECK_OFFSET(DragSlotBag, m_slots, 0x78);
