// ms2dragslot.h - MS2DragSlot: the game's DragSlot (gfxui/dragslot.h) with an item getter; base of ~30 UI slot
// classes (TradeSlot, InvenSlot, EquipSlot, SkillSlot, StoreSlot, ...). Owning unit: ?\ms2dragslot.cpp
// (0x140a7bb20-0x140a7beb0, 11 funcs; dir client\ms2). Header name assumed from the unit path.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class TradeSlot : public MS2DragSlot` and copy the exact virtual declarations to override (slots from
//   gfxui/dragslot.h plus slot 25 here). Secondary vftable (ITooltip) is at +0x78; derived members start at +0x90.
// - Slots 2-4 are efd RTTI (GetClassDesc + 2x TypeCast): every derived class declares
//   EE_DECLARE_CLASS1(X, <id>, MS2DragSlot) (id from its SetupClassInfo: `FUN_1409f2e10(p,"X",id,...)`) and binds
//   ?ms_ClassInfo@X@@2VClassInfo@efd@@B in progress/symbols-manual.tsv.
// - NiRefObject-based: allocate with NiNew / EE_NEW (efd::MemObject operator new takes a MemHint).
// - vfunc_25 returns the item shown in the slot as MS2Ptr<CItem> (hidden return; null ctor 0x140203510).
#pragma once
#include "ms2/gfxui/dragslot.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>

class CItem;

// 0x90 bytes. vftable 0x142dcc930 (26 slots, ??_G 0x140a7bda0 sized delete 0x90), ITooltip @+0x78 0x142dcca08.
class MS2DragSlot : public DragSlot
{
public:
    MS2DragSlot(const CString& strName, int nIndex);    // 0x140a7bb20
    virtual ~MS2DragSlot();                             // 0x140a7bb90

    // slots 2-4: GetClassDesc 0x140a7be00, TypeCast 0x140a7be10 / 0x140a7be60; ms_ClassInfo 0x143ab8400,
    // SetupClassInfo 0x140a36a10.
    EE_DECLARE_CLASS1(MS2DragSlot, 0x0620002D, DragSlot);
public:
    virtual int vfunc_16();                             // 16 0x140a7bbd0 if enabled and item: item preview
    virtual int vfunc_19();                             // 19 0x140a7bcc0 if enabled: key/state check 0x49406
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140a7bd20 base: null

    bool IsEnabled();                               // return m_bEnabled
    void SetEnabled(bool b);                         // m_bEnabled = b

public:
    MS2_LAYOUT_FRIEND;
    bool m_bEnabled;                                    // +0x88
};
MS2_CHECK_SIZE(MS2DragSlot, 0x90);
MS2_CHECK_OFFSET(MS2DragSlot, m_bEnabled, 0x88);
