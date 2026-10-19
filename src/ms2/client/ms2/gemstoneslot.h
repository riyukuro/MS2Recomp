// gemstoneslot.h - GemStoneSlot: the ItemInfoSlot of one socket of the gemstone manage page (shows the gemstone put into the
// socket, or the "empty" / "locked" socket frame), and GemStoneSlotBag: the bag of such slots (one per socket record of the
// equipment). Owning unit: ?\gemstoneslot.cpp (0x140cfd6f0-0x140cff310). Header name assumed from the unit path; member names
// are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cgemstoneitem.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/iteminfoslot.h"

class ASSlot;
class CMsgBoxData;

// 0xf8 bytes. vftable (26 slots, ??_G 0x140cfe970 sized delete 0xf8), ITooltip @+0x78.
class GemStoneSlot : public ItemInfoSlot
{
public:
    GemStoneSlot(const CString& strName, MS2Ptr<CGemStoneItem> spGem, int nIndex, int nIconType, int nFlags);   // 0x140cfd840
    virtual ~GemStoneSlot();                            // 0x140cfe8b0

    // slots 2-4: GetClassDesc 0x140cfea70, TypeCast 0x140cfec00 / 0x140cfec50; ms_ClassInfo 0x143ac1010,
    // SetupClassInfo 0x140cfeae0 (parent ItemInfoSlot, id 0x6200030).
    EE_DECLARE_CLASS1(GemStoneSlot, 0x06200030, ItemInfoSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140cfda30 build the slot (socket frame + gemstone item)
    virtual int vfunc_18(void* p);                      // 18 0x140cfdbe0 drop of another slot: take over its item

    void SetGem(MS2Ptr<CGemStoneItem> spGem);           // 0x140cfd950 keep the socket record and show its gemstone
    void FUN_140cfdc70(ASSlot* pSlot, bool bLocked);    // the "lock" flag of the slot movie
    void FUN_140cfdcb0(ASSlot* pSlot, MS2Ptr<CItem> spItem, bool bLocked);   // the "text" of the slot movie
    void FUN_140cfddf0(MS2Ptr<CItem> spGemItem);        // ask to socket the dropped gemstone into this socket
    bool FUN_140cfdfe0(int nButton, const CMsgBoxData& box);   // result of that confirm box

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CGemStoneItem> m_spGem;                      // +0xe8 socket record (equipment, gemstone, locked)
};
MS2_CHECK_SIZE(GemStoneSlot, 0xf8);
MS2_CHECK_OFFSET(GemStoneSlot, m_spGem, 0xe8);

// 0xa0 bytes. vftable (17 slots, ??_G 0x140cfe9d0 sized delete 0xa0).
class GemStoneSlotBag : public DragSlotBag
{
public:
    // Reads the socket record at nIndex from the array handed to the bag (returned by value: hidden slot).
    typedef MS2Ptr<CGemStoneItem> (*GetGemFn)(void* pSockets, int nIndex);

    GemStoneSlotBag(const CString& strName, void* pSockets, GetGemFn pfnGetGem, int nIconType, int nFlags);   // 0x140cfe200
    virtual ~GemStoneSlotBag();                         // 0x140cfe290

    // slots 2-4: GetClassDesc 0x140cfea80, TypeCast 0x140cfeca0 / 0x140cfecf0; ms_ClassInfo 0x143ac1420,
    // SetupClassInfo 0x140cfeb40 (parent DragSlotBag, id 0x6200030).
    EE_DECLARE_CLASS1(GemStoneSlotBag, 0x06200030, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x140cfe2c0 new GemStoneSlot for the socket record at nIndex

public:
    MS2_LAYOUT_FRIEND;
    GetGemFn m_pfnGetGem;                               // +0x88
    void* m_pSockets;                                   // +0x90 the socket record array handed to the callback
    int m_nIconType;                                    // +0x98
    int m_nFlags;                                       // +0x9c
};
MS2_CHECK_SIZE(GemStoneSlotBag, 0xa0);
MS2_CHECK_OFFSET(GemStoneSlotBag, m_pfnGetGem, 0x88);
MS2_CHECK_OFFSET(GemStoneSlotBag, m_nFlags, 0x9c);
