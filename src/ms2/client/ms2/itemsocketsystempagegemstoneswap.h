// ItemSocketSystemPageGemstoneSwap (RTTI): the gemstone swap page of the item socket dialog (move the gemstones of one
// equipment item to another of the same kind; "GemStoneSwapPage_*" bags, packet 0x88 operations 8 / 0xa). Layout from
// the ctor 0x140c47c80 / dtor 0x140c47dd0 (new 0xf8 in the dialog's page factory); member names are invented from use.
// Not an original header.
#pragma once
#include "itemsocketsystempagebase.h"
#include "itemsocketsystempagecontrols.h"
#include "ms2/placeholder/itemslotbinder.h"
class CMsgBoxData;
class ASArray;
class ASSlot;

class ItemSocketSystemPageGemstoneSwap : public ItemSocketSystemPageBase {
public:
    ItemSocketSystemPageGemstoneSwap();                 // 0x140c47c80
    virtual ~ItemSocketSystemPageGemstoneSwap();        // 0x140c47dd0
    void vfunc_1() override;                            // 0x140c47e80
    void vfunc_2() override;                            // 0x140c48380
    int vfunc_3(const char*, const Scaleform::GFx::Value*, int) override;   // 0x140c48430
    void vfunc_5(CInPacket*) override;                  // 0x140c483b0
    void vfunc_6() override;                            // 0x140c48820 redraw both items after a swap
    void vfunc_7(MS2Ptr<AScript>) override;             // 0x140c47eb0
    void FUN_140c48c70(CInPacket*);                     // operation 9: a gemstone was put into the target
    void SendItemSocketSystemMode8(CInPacket*);                     // operation 0xb: a gemstone was taken off the source
    bool FUN_140c48df0(int, const CMsgBoxData&);        // the swap confirm box answer: take the source gemstones off
    void FUN_140c49000(ItemInfoSlot&, ASSlot&);         // bag slot callback
    void FUN_140c49110();                               // clear everything
    void FUN_140c49250(int);                            // a source slot was picked
    void FUN_140c49580(int);                            // a target slot was picked
    void OnRetry();                               // back to the start
    void FUN_140c49990(MS2Ptr<CItem>, CString, ASArray*);   // the gemstone slots of an item
    void FUN_140c49fc0();                               // fill the source bag
    void FUN_140c4a2b0(MS2Ptr<CItem>);                  // fill the target bag for a source
    bool FUN_140c4a620(MS2Ptr<CItem>);                  // can be a source
    bool FUN_140c4a760(MS2Ptr<CItem>, MS2Ptr<CItem>);   // the second item can take the first one's gemstones
    void FUN_140c4a9a0(CAtlArray<MS2Ptr<CItem>>&);      // the inventory and equipped items
    bool FUN_140c4ab30(MS2Ptr<CItem>, CStringW&);       // the swap price text; false when it cannot be paid

    CAtlArray<MS2Ptr<CItem>> m_sourceItems;             // +0x30
    CAtlArray<MS2Ptr<CItem>> m_targetItems;             // +0x50
    MS2Ptr<Unk_SocketPageBag> m_sourceControl;          // +0x70
    MS2Ptr<Unk_SocketPageBag> m_targetControl;          // +0x80
    CString m_slots0Name, m_slots1Name;                 // +0x90, +0x98
    ItemSlotBinder m_binder;                            // +0xa0
    __int64 m_sourceUid;                                // +0xe0
    __int64 m_targetUid;                                // +0xe8
    int m_refresh;                                      // +0xf0 set by operation 9, consumed by vfunc_6
};
MS2_CHECK_SIZE(ItemSocketSystemPageGemstoneSwap, 0xf8);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemstoneSwap, m_sourceItems, 0x30);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemstoneSwap, m_sourceControl, 0x70);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemstoneSwap, m_slots0Name, 0x90);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemstoneSwap, m_binder, 0xa0);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemstoneSwap, m_sourceUid, 0xe0);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemstoneSwap, m_refresh, 0xf0);
