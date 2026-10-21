// ItemSocketSystemPageSocketUnlock (RTTI): the socket unlock page of the item socket dialog (open more sockets of an
// equipment item with ingredients). Layout from the ctor 0x140f7d060 / dtor 0x140f7d280; member names are invented from
// use. Not an original header.
#pragma once
#include <vector>
#include "itemsocketsystempagebase.h"
#include "itemsocketsystempagecontrols.h"
#include "itemsocketsystempagegemstonemanage.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/gfxvalue.h"
class CMsgBoxData;
class ASObj;
struct Unk_SockUidList;

class ItemSocketSystemPageSocketUnlock : public ItemSocketSystemPageBase, public UIItemEventListener {
public:
    using ItemSocketSystemPageBase::vfunc_8;
    ItemSocketSystemPageSocketUnlock();                 // 0x140f7d060
    virtual ~ItemSocketSystemPageSocketUnlock();        // 0x140f7d280
    void vfunc_1() override;                            // 0x140f7d400
    void vfunc_2() override;                            // 0x140f7e340
    int vfunc_3(const char*, const Scaleform::GFx::Value*, int) override;   // 0x140f7e440
    void vfunc_5(CInPacket*) override;                  // 0x140f7e370
    void vfunc_7(MS2Ptr<AScript>) override;             // 0x140f7d430
    void vfunc_3(void*, bool) override;                 // 0x140f7e690 (the item listener's item removed)
    void FUN_140f7e8d0();                               // the items that can be unlocked
    void FUN_140f7ec20();                               // the items that can be ingredient equipment
    void FUN_140f7ef70(MS2Ptr<CItem>);                  // a source slot was picked
    void FUN_140f7f210(MS2Ptr<CItem>);                  // all sockets are open: just show the item
    void FUN_140f7f420(MS2Ptr<CItem>);                  // an ingredient equipment slot was picked
    void FUN_140f7fa20(MS2Ptr<CItem>);                  // the ingredient equipment was confirmed
    void FUN_140f7ff50(const CStringW&, __int64*, std::vector<MS2Ptr<CItem> >&);   // ask before unlocking
    void FUN_140f80160();                               // the action button: unlock
    void FUN_140f80d70();                               // back to the start
    void FUN_140f80f30();                               // clear everything
    void FUN_140f810b0();
    void FUN_140f81100(ASObj&);                         // ingredient part of the select data
    void FUN_140f81a40(ASObj&, int);                    // the socket rows of the item
    void FUN_140f81f00(CInPacket*);                     // select item result
    void FUN_140f82340(CInPacket*);                     // unlock result
    void FUN_140f826b0(CInPacket* packet);              // refresh the ingredient prices (packet unused)
    void FUN_140f82940(const Scaleform::GFx::FunctionHandler::Params&);   // debug button: unlock
    void FUN_140f82a50(const Scaleform::GFx::FunctionHandler::Params&);   // debug button: fill ingredients
    void FUN_140f82ba0(const Scaleform::GFx::FunctionHandler::Params&);   // multi select list change
    void FUN_140f82d00(const Scaleform::GFx::FunctionHandler::Params&);   // action button
    void FUN_140f82d50(const Scaleform::GFx::FunctionHandler::Params&);   // source list change
    void FUN_140f82e10(const Scaleform::GFx::FunctionHandler::Params&);   // ingredient list change
    void FUN_140f82ed0(CAtlArray<MS2Ptr<CItem>>&);
    void FUN_140f82f20(Unk_SockUidList&);               // send the unlock request
    void FUN_140f82f90();
    void FUN_140f83060(__int64);
    void FUN_140f83170();
    void FUN_140f832f0();
    bool FUN_140f83440(int, const CMsgBoxData&);        // unlock ingredient in gemstone? answer
    bool FUN_140f83560(int, const CMsgBoxData&);        // high SA option? answer

    int m_state;                                        // +0x38 0 none, 1 item picked, 2 done
    CString m_selectedName, m_ingredientSlotName, m_ingredientName, m_slots0Name, m_slots1Name;   // +0x40..+0x60
    MS2Ptr<CItem> m_selected;                           // +0x68
    CAtlArray<MS2Ptr<CItem>> m_ingredients;             // +0x78
    CAtlArray<MS2Ptr<CItem>> m_sourceItems;             // +0x98
    CAtlArray<MS2Ptr<CItem>> m_ingredientEquips;        // +0xb8
    __int64 m_selectedUid;                              // +0xd8
    __int64 m_highlightUid;                             // +0xe0
    MS2Ptr<Unk_SocketPageBag> m_sourceControl, m_ingredientControl;   // +0xe8, +0xf8
    MS2Ptr<Unk_SocketPageButton> m_actionButton, m_debugButton, m_debugFillButton;   // +0x108, +0x118, +0x128
};
MS2_CHECK_SIZE(ItemSocketSystemPageSocketUnlock, 0x138);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketUnlock, m_state, 0x38);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketUnlock, m_selected, 0x68);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketUnlock, m_ingredients, 0x78);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketUnlock, m_selectedUid, 0xd8);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketUnlock, m_sourceControl, 0xe8);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketUnlock, m_debugFillButton, 0x128);
