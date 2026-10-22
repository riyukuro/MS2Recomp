// lapenshardslot.h - LapenshardSlot: the lapenshard (lapen) slots of the lapenshard system window and the quick bar.
// The slot either shows a free item (m_nSlot == 0, the item of the window's inventory list) or the item equipped in the
// player's lapenshard slot m_nSlot; dropping a lapenshard on it equips it (packet 0xad). Owning unit: ?\lapenshardslot.cpp
// (0x140a6e830-0x140a702f0, .text$di 0x1400c45a0-0x1400c4760). Header name assumed from the unit path; member names are
// invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0xa8 bytes. vftable (26 slots, ??_G 0x140a70040 sized delete 0xa8), ITooltip @+0x78.
class LapenshardSlot : public MS2DragSlot
{
public:
    LapenshardSlot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem, int nSlot, int nKind);   // 0x140a6e830
    virtual ~LapenshardSlot() = default;             // 0x140a70010 (the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x140a700a0, TypeCast 0x140a70130 / 0x140a70180; ms_ClassInfo 0x143ab7a50,
    // SetupClassInfo 0x140a700d0 (parent MS2DragSlot, id 0x6200083).
    EE_DECLARE_CLASS1(LapenshardSlot, 0x06200083, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140a6fc00 build the item slot into p
    virtual int vfunc_14();                             // 14 0x140a6ee30 equip the item of the slot
    virtual int vfunc_17();                             // 17 0x140a6ea20
    virtual int vfunc_18(void* p);                      // 18 0x140a6ea50 another slot was dropped on it
    virtual int vfunc_20();                             // 20 0x140a6f1b0 button down
    virtual int vfunc_21();                             // 21 0x140a6f390 button up
    virtual CStringW vfunc_22();                        // 22 0x140a6f570 tooltip title
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140a6f610 the item of the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x140a6f9e0 build the tooltip into p

    int FUN_140a6f860();                                // the lapenshard slot of the player (0: a free slot)
    int FUN_140a6f880();                                // the kind (the slot the item is equipped into)

private:
    void SendLapenshard(int nSlot, __int64 nItemUid);    // request the equip (packet 0xad)

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                             // +0x90
    int m_nSlot;                                        // +0xa0
    int m_nKind;                                        // +0xa4
};
MS2_CHECK_SIZE(LapenshardSlot, 0xa8);
MS2_CHECK_OFFSET(LapenshardSlot, m_spItem, 0x90);
MS2_CHECK_OFFSET(LapenshardSlot, m_nKind, 0xa4);
