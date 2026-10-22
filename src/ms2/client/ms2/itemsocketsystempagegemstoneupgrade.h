// ItemSocketSystemPageGemStoneUpgrade (RTTI): the gemstone upgrade page of the item socket dialog, and
// TGemStoneInEquip, the record of a gemstone socketed in an equipped item. Layouts from the ctors 0x140f74600 /
// 0x140f744f0 and the dtors 0x140f74820 / 0x140f7b4e0. Member names are invented from use.
#pragma once
#include "itemsocketsystempagebase.h"
#include "itemsocketsystempagecontrols.h"
#include "itemsocketsystempagegemstonemanage.h"
#include "ms2/placeholder/uiitemeventlistener.h"
class ASSlot;
class ASTooltip;
class CMsgBoxData;
class NotifyObject;
class ItemInfoSlot;

// A gemstone socketed in an equipment item (heap-only, held by MS2Ptr).
class TGemStoneInEquip : public CPtred {
public:
    TGemStoneInEquip(MS2Ptr<CItem> gem, MS2Ptr<CItem> equipment, int slot);   // 0x140f744f0
    virtual ~TGemStoneInEquip() {}                                              // 0x140f7b4e0
    bool FUN_140f74590();               // 0x140f74590 incomplete: no gemstone, no equipment or no slot
    MS2Ptr<CItem> m_gem;                // +0x18
    MS2Ptr<CItem> m_equipment;          // +0x28
    int m_slot;                         // +0x38
};
MS2_CHECK_SIZE(TGemStoneInEquip, 0x40);
MS2_CHECK_OFFSET(TGemStoneInEquip, m_gem, 0x18);
MS2_CHECK_OFFSET(TGemStoneInEquip, m_equipment, 0x28);
MS2_CHECK_OFFSET(TGemStoneInEquip, m_slot, 0x38);

namespace CCItemSocketSystemPacket {
class SelectItemResult;
class GemStoneUpgradeResult;
}

class ItemSocketSystemPageGemStoneUpgrade : public ItemSocketSystemPageBase, public UIItemEventListener {
public:
    using ItemSocketSystemPageBase::vfunc_8;
    ItemSocketSystemPageGemStoneUpgrade();
    virtual ~ItemSocketSystemPageGemStoneUpgrade();
    void vfunc_1() override;
    void vfunc_2() override;
    int vfunc_3(const char*, const Scaleform::GFx::Value*, int) override;
    void vfunc_5(CInPacket*) override;
    void vfunc_7(MS2Ptr<AScript>) override;
    void vfunc_2(void*) override;
    void vfunc_3(void*, bool) override;
    void vfunc_4(void*, int) override;
    void FUN_140f75c50();
    void FUN_140f76420(int);
    void FUN_140f764b0(MS2Ptr<CItem>);
    void FUN_140f76970();
    void FUN_140f770b0();
    void FUN_140f77360(MS2Ptr<CItem>);
    void FUN_140f77560(CCItemSocketSystemPacket::SelectItemResult*);
    void FUN_140f77950(ASObj&);
    void FUN_140f78110(MS2Ptr<CItem>);
    void FUN_140f78720(CInPacket*);
    void FUN_140f787a0(CInPacket*);
    void FUN_140f78f30(CInPacket*);
    void FUN_140f79210();
    void FUN_140f79430();
    void FUN_140f79490();
    void FUN_140f79540();
    void FUN_140f79680(__int64);
    void SendItemSocketSystemMode15(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140f798e0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140f799d0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140f79ad0(ItemInfoSlot&, ASSlot&);
    void FUN_140f79c50(ItemInfoSlot&, ASTooltip&);
    bool FUN_140f79e10(MS2Ptr<TGemStoneInEquip>, MS2Ptr<CItem>, int*);
    MS2Ptr<CItem> FUN_140f7a0c0(int);
    MS2Ptr<CItem> FUN_140f7a190(__int64, int*);
    bool FUN_140f7a200(int, MS2Ptr<CItem>);
    MS2Ptr<TGemStoneInEquip> FUN_140f7a380(__int64);
    void FUN_140f7a440(NotifyObject*);

    CString m_gemsName;                                         // +0x38
    CString m_selectedName;                                     // +0x40
    CString m_nextName;                                         // +0x48
    CString m_ingredientsName;                                  // +0x50
    MS2Ptr<CItem> m_selected;                                   // +0x58
    MS2Ptr<CItem> m_next;                                       // +0x68 the upgraded gemstone preview
    CAtlArray<MS2Ptr<CItem>> m_gems;                            // +0x78
    CAtlMap<__int64, MS2Ptr<TGemStoneInEquip>> m_equipped;      // +0x98 socketed gemstones by gemstone uid
    CAtlArray<MS2Ptr<CItem>> m_ingredients;                     // +0xe0
    int m_state;                                                // +0x100 1 = selected, 2 = upgraded
    __int64 m_selectedUid;                                      // +0x108
    __int64 m_highlightUid;                                     // +0x110
    MS2Ptr<Unk_SocketPageBag> m_bag;                            // +0x118
    MS2Ptr<Unk_SocketPageButton> m_debugAction;                 // +0x128
    MS2Ptr<Unk_SocketPageButton> m_debugFill;                   // +0x138
    MS2Ptr<Unk_SocketPageButton> m_debugFillUnit;               // +0x148
};
MS2_CHECK_SIZE(ItemSocketSystemPageGemStoneUpgrade, 0x158);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneUpgrade, m_gemsName, 0x38);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneUpgrade, m_equipped, 0x98);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneUpgrade, m_state, 0x100);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneUpgrade, m_bag, 0x118);
MS2_CHECK_OFFSET(ItemSocketSystemPageGemStoneUpgrade, m_debugFillUnit, 0x148);
