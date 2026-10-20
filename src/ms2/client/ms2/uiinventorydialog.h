// uiinventorydialog.h - UIInventoryDialog (RTTI .?AVUIInventoryDialog@@, 0x228 bytes, UIDialog + UIStatusEventListener +
// UIItemEventListener, UI id 0x4e2d, swf "InventoryDialog"): the inventory window. A button bar of tabs ("m_tab") picks
// the item category, "m_itemBagEx" lists the slots of the tab (an InventorySlotBag registered under the dialog name),
// "m_inputSearch" searches the items by name, and the side buttons open the item break / lock / enchant / merge / bank
// windows. The unit also holds UIInviteGroupDialog and the item break dialogs (separate headers).
// Owning unit: client\ms2\uiinventorydialog.cpp.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/delegate.h"

class ASButtonBar;
class ASTextInput;
class CMsgBoxData;
class Unk_InvItemBag;

class UIInventoryDialog : public UIDialog, public UIStatusEventListener, public UIItemEventListener
{
public:
    typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

    UIInventoryDialog();                                        // 0x141996ec0
    virtual ~UIInventoryDialog();                               //  0 0x141997080 (??_G 0x14199f390)
    virtual CString vfunc_1();                                  //  1 0x141997190 "InventoryDialog"
    virtual int vfunc_13();                                     // 13 0x141999a80 Enter key: apply the search text
    virtual void vfunc_15();                                    // 15 0x141997580 per-frame: the pending refreshes
    virtual void vfunc_18();                                    // 18 0x141999c70 follow the dialog it is placed next to
    virtual void OnLoadComplete();                              // 22 0x141997dd0
    virtual void vfunc_26();                                    // 26 0x141998250 drop the controls
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141998680
    virtual void vfunc_43();                                    // 43 0x1419974e0
    virtual int vfunc_46();                                     // 46 0x1419994e0 movie ready: the feature buttons
    virtual int vfunc_48() { return 0x4e2d; }                   // 48 0x14199f450
    virtual void vfunc_62(int nWidth, int nHeight);             // 62 0x141997620
    virtual int vfunc_65();                                     // 65 0x141997280 open: register the listeners
    virtual void vfunc_66();                                    // 66 0x14199c020
    virtual void vfunc_67();                                    // 67 0x141997330 close
    virtual void vfunc_80(void* pRequest);                      // 80 0x141997ba0 platform reply: the search text
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1419982b0

    // UIStatusEventListener (+0x178)
    virtual int vfunc_oa0_1();                                  // o178 1 0x141997230
    virtual void vfunc_oa0_7(int a1, CStringW s);               // o178 7 0x141997880
    virtual void vfunc_oa0_9(unsigned short a1);                // o178 9 0x141997800
    virtual void vfunc_oa0_11(void* a1);                        // o178 11 0x1419976e0 the mesos changed
    virtual void vfunc_oa0_25(void* a1);                        // o178 25 0x141997920
    virtual void vfunc_oa0_26(void* a1);                        // o178 26 0x141997980

    // UIItemEventListener (+0x180)
    virtual int vfunc_il1();                                    // o180 1 0x1419971e0
    virtual void vfunc_26(int nItemId);                         // o180 26 0x1419979e0 an item was used: play its pose

    // ---- non-virtual members, sorted by address ----
    static void FUN_141999d20(int nMode);                       // the alignment mode (s_nAlignMode)
    void FUN_141999d40(int nTab);                               // select a tab
    int FUN_141999de0();                                        // the tab
    void FUN_141999e00();                                       // refresh everything
    void FUN_141999e20();                                       // reset the tab
    void FUN_141999e50();                                       // the slots were expanded: play "m_expandEff"
    int FUN_141999f10();                                        // the bag's scroll position
    void FUN_141999f60();                                       // the side buttons' state
    void FUN_14199a3f0(__int64 nItemUid);                       // refresh the slot of an item
    void FUN_14199a4b0(const Scaleform::GFx::FunctionHandler::Params& params);   // tab changed
    void FUN_14199a620(const Scaleform::GFx::FunctionHandler::Params& params);   // search text changed: the candidates
    void FUN_14199a910();                                       // open the bank
    void FUN_14199aaa0();                                       // toggle the enchant dialog
    MS2Ptr<ASButtonBar> FUN_14199aad0();                        // the tab bar
    int FUN_14199ab20(CString strName);                         // the index of a tab name (-1: none)
    CStringW FUN_14199abe0();                                   // the search text
    bool FUN_14199ac30(int nResult, const CMsgBoxData& box);    // couple effect: the receiver name was entered
    bool FUN_14199b100(int nResult, const CMsgBoxData& box);    // couple effect: send or ask for the name
    bool FUN_14199b480(int nResult, const CMsgBoxData& box);    // sort confirmation
    bool FUN_14199b4e0(int nResult, const CMsgBoxData& box);    // rename an item
    void FUN_14199b800(CStringW strText);                       // ask the platform to accept the text, then search
    void FUN_14199ba10();                                       // rebuild the bag
    void FUN_14199bbb0(int nTab);                               // switch the tab and rebuild the bag
    void FUN_14199bc00();                                       // the tabs' "new item" marks
    void FUN_14199be00(int nTab);                               // clear the "new" flags of a tab
    void FUN_14199bed0(const __int64& nMesos);                  // the meso amount of the box
    static int FUN_14199bfc0();                                 // a trade is running (and the player is alive)
    void FUN_14199c0d0();                                       // refresh the "m_expand" text
    static void FUN_14199c230(int nTab, bool bStack);           // send the sort request
    void FUN_14199c2b0(CStringW strText);                       // scroll to the item matching the text
    void FUN_14199c610(CStringW strSearch, ATL::CAtlList<CStringW>& names);   // the item names of the tab containing the text
    bool FUN_14199c7b0(int nResult, const CMsgBoxData& box);    // "not found" box closed: focus the input
    void FUN_14199c8a0(int* pWidth, int* pHeight);              // the panel size
    void FUN_14199ca90();                                       // bind and fill the tab bar
    void FUN_14199d1c0();                                       // the tab list
    int FUN_14199d840();                                        // the stackable items of the tab
    int FUN_14199d920(int nTab);                                // the button of a tab
    bool FUN_14199d980();                                       // the tab can be expanded
    CStringW FUN_14199d9c0();                                   // the item break button tooltip
    CStringW FUN_14199ddd0();                                   // the slot expand tooltip
    CStringW FUN_14199deb0(int bBank);                          // the open bank tooltip
    void FUN_14199e2a0();                                       // expand the slots (or tell why not)

    static int s_nAlignMode;                                    // 0x143af2f60

private:
    MS2_LAYOUT_FRIEND;
    CString m_188;                                              // +0x188 the bag name (vfunc_1())
    int m_190;                                                  // +0x190 the dialog placed next to ("openWindowPos")
    int m_194;                                                  // +0x194 the tab
    int m_198;                                                  // +0x198
    int m_19c;                                                  // +0x19c pending refreshes: 1 new marks, 2 expand text, 4 bag
    int m_1a0;                                                  // +0x1a0 the previous tab
    int m_1a4;                                                  // +0x1a4 the open item dialog (1 break, 2 donation, 3 lock, 4/5)
    ATL::CAtlArray<int> m_1a8;                                  // +0x1a8 tab -> button index
    MS2Ptr<ASButtonBar> m_1c8;                                  // +0x1c8 "m_tab"
    CStringW m_1d8;                                             // +0x1d8 the search text
    MS2Ptr<ASTextInput> m_1e0;                                  // +0x1e0 "m_inputSearch"
    ATL::CAtlArray<std::pair<CString, int> > m_1f0;             // +0x1f0 the tabs (name, tab)
    MS2Ptr<Unk_InvItemBag> m_210;                               // +0x210 "m_itemBagEx"
    void* m_220;                                                // +0x220
};
MS2_CHECK_SIZE(UIInventoryDialog, 0x228);
MS2_CHECK_OFFSET(UIInventoryDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIInventoryDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UIInventoryDialog, m_1f0, 0x1f0);
MS2_CHECK_OFFSET(UIInventoryDialog, m_210, 0x210);
