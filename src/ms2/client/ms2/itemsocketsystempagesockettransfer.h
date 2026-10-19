// ItemSocketSystemPageSocketTransfer (RTTI): the socket transfer page of the item socket dialog (move the socketed
// gemstones of one equipment item to another). Layout from the ctor 0x140c4ffa0 / dtor 0x140c501a0; member names are
// invented from use. Not an original header.
#pragma once
#include "itemsocketsystempagebase.h"
#include "itemsocketsystempagecontrols.h"
#include "itemsocketsystempagegemstonemanage.h"
#include "ms2/placeholder/gfxvalue.h"
class CMsgBoxData;
class ASObj;
class CIngredientContainer;
struct Unk_SockUidPair;

class ItemSocketSystemPageSocketTransfer : public ItemSocketSystemPageBase {
public:
    ItemSocketSystemPageSocketTransfer();               // 0x140c4ffa0
    virtual ~ItemSocketSystemPageSocketTransfer();      // 0x140c501a0
    void vfunc_1() override;                            // 0x140c50300
    void vfunc_2() override;                            // 0x140c50d20
    int vfunc_3(const char*, const Scaleform::GFx::Value*, int) override;   // 0x140c50e00
    void vfunc_5(CInPacket*) override;                  // 0x140c50d50
    void vfunc_7(MS2Ptr<AScript>) override;             // 0x140c50330
    void FUN_140c51050();                               // the inventory and equipped items that can be a source
    void FUN_140c51410();                               // the items the source can be transferred to
    void FUN_140c51680(MS2Ptr<CItem>);                  // a source slot was picked
    void FUN_140c51a60(MS2Ptr<CItem>);                  // a target slot was picked
    void FUN_140c51fa0();                               // the action button: ask the server to transfer
    void FUN_140c527d0();                               // back to the start
    void FUN_140c52930();                               // clear everything
    void FUN_140c52a80();
    void FUN_140c52ac0();
    void FUN_140c52b20(ASObj&);                         // ingredient part of the select data
    void FUN_140c52f10(MS2Ptr<CItem>, ASObj&, int);     // the socket rows of an item
    void FUN_140c533f0(CInPacket*);                     // transfer result
    void FUN_140c53920();
    void FUN_140c53a70(const Scaleform::GFx::FunctionHandler::Params&);   // debug button: transfer
    void FUN_140c53e40(const Scaleform::GFx::FunctionHandler::Params&);   // debug button: fill ingredients
    void FUN_140c53f90(CAtlArray<MS2Ptr<CItem>>&);
    void FUN_140c53fc0(Unk_SockUidPair&);               // send the transfer request
    void FUN_140c54030();
    void FUN_140c54100(__int64);
    bool FUN_140c54210(int, const CMsgBoxData&);        // transfer the skin first? answer

    int m_state;                                        // +0x30 0 none, 1 source picked, 2 done
    CString m_sourceName, m_targetName, m_ingredientName, m_slots0Name, m_slots1Name;   // +0x38..+0x58
    MS2Ptr<CItem> m_source;                             // +0x60
    MS2Ptr<CItem> m_target;                             // +0x70
    CAtlArray<MS2Ptr<CItem>> m_ingredients;             // +0x80
    CAtlArray<MS2Ptr<CItem>> m_sourceItems;             // +0xa0
    CAtlArray<MS2Ptr<CItem>> m_targetItems;             // +0xc0
    __int64 m_sourceUid;                                // +0xe0
    __int64 m_highlightUid;                             // +0xe8
    MS2Ptr<Unk_SocketPageBag> m_sourceControl, m_targetControl;   // +0xf0, +0x100
    MS2Ptr<Unk_SocketPageButton> m_debugButton, m_debugFillButton;   // +0x110, +0x120
};
MS2_CHECK_SIZE(ItemSocketSystemPageSocketTransfer, 0x130);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketTransfer, m_state, 0x30);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketTransfer, m_source, 0x60);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketTransfer, m_ingredients, 0x80);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketTransfer, m_sourceUid, 0xe0);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketTransfer, m_sourceControl, 0xf0);
MS2_CHECK_OFFSET(ItemSocketSystemPageSocketTransfer, m_debugFillButton, 0x120);
