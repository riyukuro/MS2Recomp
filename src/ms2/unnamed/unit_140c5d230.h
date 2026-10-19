// unit_140c5d230.h - the Lapenshard (lapenshard = "skill shard" item) system window and its HUD shield bar: classes of
// unit_140c5d230 (0x140c5d230-0x140c6b300). NOT an original header (the exe has no __FILE__ strings for these classes;
// the unit name is a guess from the RTTI names, the member names are invented from use). Sibling of the pet system
// dialog's pages (client\ms2\tabcontentspetcompose.h): the same page / section structure.
//
//   UILapenshardSystemDialog (0x1c0, UIModalDialog + UIItemEventListener, UI id 0x4f6d, swf "LapenshardSystemDialog"):
//       a tab strip over two pages, UILapenshardEquipTab ("equip") and UILapenshardUpgradeTab ("upgrade").
//   LapenshardSystemTabContents: the page interface (12 slots); LapenshardSystemTabPanelBase: one section of a page
//       (9 slots), which binds a child control of the page's movie ("m_itemBag", "m_body", ...).
//   UILapenshardShieldBar (0xa8, UIHeadUpDisplay + UIEntityEventListener, UI id 0x4f73): the shield buff HUD.
#pragma once

#include "ms2/placeholder/chomeprivilege.h"
#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uientityeventlistener.h"
#include "ms2/client/ms2/uimodaldialog.h"

class ItemInfoSlot;
class ASSlot;
class ASTooltip;
class CMsgBoxData;
class MyPC;
class Unk_UISwfEntity_25;

class LapenshardSystemTabPanelBase;
class LapenshardSystemTabContents;
class UILapenshardEquipTab;
class UILapenshardUpgradeTab;
class UILapenshardSystemDialog;
class Unk_LsTabBar;

typedef MS2Ptr<LapenshardSystemTabPanelBase> LapenshardPanelPtr;
typedef ATL::CAtlList<LapenshardPanelPtr> LapenshardPanelList;

// ---- the sections -------------------------------------------------------------------------------------------------

// 0x28 bytes, vftable 0x142e0b760 (9 slots). One section of a page: binds a child control of the page's movie and
// reacts to the page's slot-5 notifications. Slots 6/7/8 are shared by every section (0x140c5ed00 / 0x140c5ec20 / 0x140c5ec70).
class LapenshardSystemTabPanelBase : public CPtred
{
public:
    LapenshardSystemTabPanelBase();                                 // 0x140c5e4d0
    virtual ~LapenshardSystemTabPanelBase();                        //  0 0x140c5e620 (??_G 0x140c5e7f0)
    virtual void vfunc_1();                                         //  1 0x140c5ec40
    virtual void vfunc_2();                                         //  2 0x140c5eca0
    virtual void vfunc_3();                                         //  3 0x140c5e900 (build the section)
    virtual void vfunc_4();                                         //  4 0x140c5e8f0 (clear the section)
    virtual void vfunc_5(int nEvent);                               //  5 0x140c5ed60 (page notification)
    virtual void vfunc_6(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB);     //  6 0x140c5ed00 (both by value: the callee destroys them)
    virtual void vfunc_7();                                         //  7 0x140c5ec20
    virtual int vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 8 0x140c5ec70 returns 0

    void FUN_140c5ee50(MS2Ptr<ASUIComponent> ui);                   // 0x140c5ee50 attach the page's movie (by value: the callee destroys it)

    MS2Ptr<ASUIComponent> m_ui;                                     // +0x18 the page's movie
};
MS2_CHECK_SIZE(LapenshardSystemTabPanelBase, 0x28);
MS2_CHECK_OFFSET(LapenshardSystemTabPanelBase, m_ui, 0x18);

// 0x38 bytes, vftable 0x142e0b7b0: the player's bag of lapenshards ("m_itemBag").
class LapenshardItemSlotBagPanel : public LapenshardSystemTabPanelBase
{
public:
    LapenshardItemSlotBagPanel(UILapenshardEquipTab* pTab);         // 0x140c5d230
    virtual ~LapenshardItemSlotBagPanel();                          //  0 0x140c5e5c0 (??_G 0x140c5e770)
    virtual void vfunc_1();                                         //  1 0x140c5d290 -> vfunc_4
    virtual void vfunc_2();                                         //  2 0x140c5d2c0 -> vfunc_4
    virtual void vfunc_3();                                         //  3 0x140c5d2f0
    virtual void vfunc_4();                                         //  4 0x140c5d530
    virtual void vfunc_5(int nEvent);                               //  5 0x140c5d580

    CString m_strBag;                                               // +0x28 the item bag's registry name
    UILapenshardEquipTab* m_pTab;                                   // +0x30
};
MS2_CHECK_SIZE(LapenshardItemSlotBagPanel, 0x38);

// 0x38 bytes, vftable 0x142e0b800: the six equip slots ("m_equipSlot1..6").
class LapenshardEquipSlotPanel : public LapenshardSystemTabPanelBase
{
public:
    LapenshardEquipSlotPanel(UILapenshardEquipTab* pTab);           // 0x140c5d5c0
    virtual ~LapenshardEquipSlotPanel();                            //  0 0x140c5e590 (??_G 0x140c5e730)
    virtual void vfunc_1();                                         //  1 0x140c5d620 -> vfunc_4
    virtual void vfunc_2();                                         //  2 0x140c5d650 -> vfunc_4
    virtual void vfunc_3();                                         //  3 0x140c5d680
    virtual void vfunc_4();                                         //  4 0x140c5d900
    virtual void vfunc_5(int nEvent);                               //  5 0x140c5d950

    void FUN_140c5d9c0(int bOn);                                    // 0x140c5d9c0 play / stop the equip effect of the matching slot

    CString m_strBag;                                               // +0x28 the slot bag's registry name
    UILapenshardEquipTab* m_pTab;                                   // +0x30
};
MS2_CHECK_SIZE(LapenshardEquipSlotPanel, 0x38);

// ---- the pages ----------------------------------------------------------------------------------------------------

// 0x18 bytes, vftable 0x142e0b6f8 (12 slots; 3 and 8 are pure). One page of the system window.
class LapenshardSystemTabContents : public CPtred
{
public:
    LapenshardSystemTabContents();                                  // 0x140c5e4a0
    virtual ~LapenshardSystemTabContents();                         //  0 0x140c5e5f0 (??_G 0x140c5e7b0)
    virtual void vfunc_1();                                         //  1 0x140c5ec30 (close)
    virtual void vfunc_2(int nEvent);                               //  2 0x140c5ed50 (notify the sections)
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui) = 0;             //  3 pure (attach the page's movie)
    virtual void vfunc_4();                                         //  4 0x140c5ec90
    virtual void vfunc_5(void* a1, void* a2, void* a3);             //  5 0x140c5ed30 (empty)
    virtual int vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 6 0x140c5ec50 returns 0
    virtual void vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4);   // 7 0x140c5ecb0 (a2 by value: the callee destroys it)
    virtual int vfunc_8() = 0;                                      //  8 pure
    virtual void vfunc_9(CInPacket& packet);                        //  9 0x140c5ece0 (packet 0x11b)
    virtual void vfunc_10(void* a1, bool b);                        // 10 0x140c5ecf0 (empty)
    virtual class MyPC* vfunc_11();                                 // 11 0x140c608f0 (looks the local player up)
};
MS2_CHECK_SIZE(LapenshardSystemTabContents, 0x18);

// 0x58 bytes, vftable 0x142e0b850: the "equip" page (the bag and the six equip slots).
class UILapenshardEquipTab : public LapenshardSystemTabContents
{
public:
    UILapenshardEquipTab();                                         // 0x140c5dba0
    virtual ~UILapenshardEquipTab();                                //  0 0x140c5e660 (??_G 0x140c5e830)
    virtual void vfunc_1();                                         //  1 0x140c5dd20 close the sections
    virtual void vfunc_2(int nEvent);                               //  2 0x140c5dee0
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);                 //  3 0x140c5dfd0
    virtual void vfunc_4();                                         //  4 0x140c5de10
    virtual int vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 6 0x140c5e140 "OnUnmountEquipSlot"
    virtual int vfunc_8();                                          //  8 0x140c5e290 (1)
    virtual void vfunc_9(CInPacket& packet);                        //  9 0x140c5e2b0
    virtual void vfunc_10(void* a1, bool b);                        // 10 0x140c5e370 (empty)

    LapenshardPanelList m_panels;                                   // +0x18
    MS2Ptr<ASUIComponent> m_ui;                                     // +0x48
};
MS2_CHECK_SIZE(UILapenshardEquipTab, 0x58);
MS2_CHECK_OFFSET(UILapenshardEquipTab, m_ui, 0x48);

// ---- the upgrade page ---------------------------------------------------------------------------------------------

typedef ATL::CAtlArray<MS2Ptr<CItem> > LapenshardItemArray;

// 0x58 bytes, vftable 0x142e0b8?: the source bag ("m_sourceItemBag"): the lapenshards that can be upgraded.
class LapenshardSourceItemSlotBagPanel : public LapenshardSystemTabPanelBase
{
public:
    LapenshardSourceItemSlotBagPanel(UILapenshardUpgradeTab* pTab); // 0x140c63710
    virtual ~LapenshardSourceItemSlotBagPanel();                    //  0 0x140c6a1c0 (??_G 0x140c6a4c0)
    virtual void vfunc_1();                                         //  1 0x140c63780 -> vfunc_4
    virtual void vfunc_2();                                         //  2 0x140c637b0 -> vfunc_4
    virtual void vfunc_3();                                         //  3 0x140c637e0
    virtual void vfunc_4();                                         //  4 0x140c63a00
    virtual void vfunc_5(int nEvent);                               //  5 0x140c63a70
    virtual int vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 8 0x140c63ad0 "OnSelectSourceItem"

    void FUN_140c63bb0(int nIndex);                                 // pick the item of the bag as the source

    CString m_strBag;                                               // +0x28 the bag's registry name
    UILapenshardUpgradeTab* m_pTab;                                 // +0x30
    LapenshardItemArray m_items;                                    // +0x38
};
MS2_CHECK_SIZE(LapenshardSourceItemSlotBagPanel, 0x58);

// 0x58 bytes: the ingredient bag ("m_ingredientItemBag").
class LapenshardIngredientItemSlotBagPanel : public LapenshardSystemTabPanelBase
{
public:
    LapenshardIngredientItemSlotBagPanel(UILapenshardUpgradeTab* pTab);   // 0x140c63c70
    virtual ~LapenshardIngredientItemSlotBagPanel();                //  0 0x140c6a180 (??_G 0x140c6a480)
    virtual void vfunc_1();                                         //  1 0x140c63ce0 -> vfunc_4
    virtual void vfunc_2();                                         //  2 0x140c63d10 -> vfunc_4
    virtual void vfunc_3();                                         //  3 0x140c63d40
    virtual void vfunc_4();                                         //  4 0x140c64160
    virtual void vfunc_5(int nEvent);                               //  5 0x140c64200
    virtual int vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 8 0x140c642b0 "OnSelectIngredientItem"

    void FUN_140c64390(int nIndex);                                 // pick (some of) the item of the bag as an ingredient
    void FUN_140c64960(int nIndex, int nCount);                     // move nCount of the item into / out of the ingredients
    bool FUN_140c64b10(int nResult, const CMsgBoxData& box);       // the count input box's answer (message-box delegate)
    bool FUN_140c64bc0(int nResult, const CMsgBoxData& box);       // the count box's answer (message-box delegate)

    CString m_strBag;                                               // +0x28
    UILapenshardUpgradeTab* m_pTab;                                 // +0x30
    LapenshardItemArray m_items;                                    // +0x38
};
MS2_CHECK_SIZE(LapenshardIngredientItemSlotBagPanel, 0x58);

// 0xc8 bytes: the source / result slot and the upgrade animation ("m_body").
class LapenshardUpgradeSlotPanel : public LapenshardSystemTabPanelBase
{
public:
    LapenshardUpgradeSlotPanel(UILapenshardUpgradeTab* pTab);       // 0x140c64d50
    virtual ~LapenshardUpgradeSlotPanel();                          //  0 0x140c6a200 (??_G 0x140c6a500)
    virtual void vfunc_1();                                         //  1 0x140c64e50 -> vfunc_4
    virtual void vfunc_2();                                         //  2 0x140c64e80 -> vfunc_4
    virtual void vfunc_3();                                         //  3 0x140c64eb0
    virtual void vfunc_4();                                         //  4 0x140c650d0
    virtual void vfunc_5(int nEvent);                               //  5 0x140c651a0

    void FUN_140c652d0(ItemInfoSlot& slot, ASSlot& asSlot);        // slot callback: mark an empty slot
    void FUN_140c65360(ItemInfoSlot& slot, ASTooltip& tooltip);    // tooltip callback
    void FUN_140c654a0(CString& strSlot, MS2Ptr<CItem> spItem);     // 0x140c654a0 bind a slot name to an item
    void FUN_140c65e00();
    void FUN_140c65ef0();
    void FUN_140c660f0();
    void FUN_140c671d0();
    void FUN_140c67440(int bSuccess);
    void FUN_140c67ce0();

    CString m_strSource;                                            // +0x28 "lapenshardUpgradeSourceSlot"
    CString m_strResult;                                            // +0x30 "lapenshardUpgradeResultSlot"
    CString m_strBind;                                              // +0x38
    ATL::CAtlArray<CString> m_slotNames;                            // +0x40
    UILapenshardUpgradeTab* m_pTab;                                 // +0x60
    MS2Ptr<CItem> m_spSource;                                       // +0x68
    ATL::CAtlArray<int> m_aRows;                                    // +0x78
    ATL::CAtlArray<int> m_aCols;                                    // +0x98
    MS2Ptr<ASUIComponent> m_body;                                   // +0xb8 "m_body"
};
MS2_CHECK_SIZE(LapenshardUpgradeSlotPanel, 0xc8);

// 0xc8 bytes, vftable 0x142e0b9?: the "upgrade" page (source slot, ingredients, upgrade request).
class UILapenshardUpgradeTab : public LapenshardSystemTabContents
{
public:
    UILapenshardUpgradeTab();                                       // 0x140c67de0
    virtual ~UILapenshardUpgradeTab();                              //  0 0x140c6a2d0 (??_G 0x140c6a540)
    virtual void vfunc_1();                                         //  1 0x140c68090 close the sections
    virtual void vfunc_2(int nEvent);                               //  2 0x140c68260
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui);                 //  3 0x140c68390
    virtual void vfunc_4();                                         //  4 0x140c68190
    virtual int vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 6 0x140c68500
    virtual int vfunc_8();                                          //  8 0x140c68860 (0)
    virtual void vfunc_9(CInPacket& packet);                        //  9 0x140c68870
    virtual void vfunc_10(void* a1, bool b);                        // 10 0x140c68a30 (empty)

    void FUN_140c68a50();                                           // reset the page state
    void FUN_140c68aa0();                                           // tell the server the ingredients changed
    void FUN_140c68bd0(MS2Ptr<CItem> spItem);                       // pick the source item
    MS2Ptr<CItem> FUN_140c68da0();                                  // the source item
    void FUN_140c68df0();                                           // clear the source item
    int FUN_140c68e20() { return m_nState; }                        // 0 idle, 1 source set, 2 requested, 3 answered, 4 processed
    int FUN_140c68e40() { return m_n_bc; }
    void FUN_140c68e60(unsigned __int64 nUid, int nDelta);          // add / remove ingredients of an item
    void FUN_140c68f90();                                           // clear the ingredients
    int FUN_140c68fd0() { return m_nTotal; }                        // the number of ingredients
    int FUN_140c68ff0(unsigned __int64 nUid);                       // the number of one ingredient
    void FUN_140c69030();                                           // request the upgrade
    int FUN_140c691f0();                                            // the upgrade can be requested
    void FUN_140c69620();
    int FUN_140c69650() { return m_n_c0; }

    LapenshardPanelList m_panels;                                   // +0x18
    int m_nState;                                                   // +0x48
    MS2Ptr<ASUIComponent> m_ui;                                     // +0x50
    MS2Ptr<CItem> m_spSource;                                       // +0x60
    ATL::CAtlMap<unsigned __int64, int> m_ingredients;              // +0x70 item uid -> count
    int m_nTotal;                                                   // +0xb8
    int m_n_bc;                                                     // +0xbc
    int m_n_c0;                                                     // +0xc0
};
MS2_CHECK_SIZE(UILapenshardUpgradeTab, 0xc8);
MS2_CHECK_OFFSET(UILapenshardUpgradeTab, m_ui, 0x50);
MS2_CHECK_OFFSET(UILapenshardUpgradeTab, m_ingredients, 0x70);

// ---- the window -----------------------------------------------------------------------------------------------------

typedef MS2Ptr<LapenshardSystemTabContents> LapenshardTabPtr;

// 0x1c0 bytes: the Lapenshard window (a modal dialog), a tab strip over the pages.
class UILapenshardSystemDialog : public UIModalDialog, public UIItemEventListener
{
public:
    // 0x38 bytes, vftable 0x142e0b8f8 (CPtred): one tab, its name ("equip" / "upgrade"), its label and its page.
    class TabInfo : public CPtred
    {
    public:
        TabInfo(CString strName, CStringW strLabel, LapenshardTabPtr spPage);   // 0x140c61110 (all by value: the callee destroys them)
        virtual ~TabInfo();                                         //  0 0x140c62b50 (??_G 0x140c62dd0)

        CString m_strName;                                          // +0x18
        CStringW m_strLabel;                                        // +0x20
        LapenshardTabPtr m_spPage;                                  // +0x28
    };
    typedef MS2Ptr<TabInfo> TabInfoPtr;

    UILapenshardSystemDialog();                                     // 0x140c611d0
    virtual ~UILapenshardSystemDialog();                            //  0 0x140c62ba0 (??_G 0x140c62e10)
    virtual CString vfunc_1();                                      //  1 0x140c612a0 "LapenshardSystemDialog"
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x140c61de0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c61be0
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x140c61b50
    virtual int vfunc_48() { return 0x4f6d; }                       // 48 0x140c63030
    virtual int vfunc_65();                                         // 65 0x140c612f0 Open: build the two tabs
    virtual void vfunc_67();                                        // 67 0x140c616f0 Close
    virtual int vfunc_73();                                         // 73 0x140c62000 can open
    virtual bool vfunc_75();                                        // 75 0x140c62390
    virtual void vfunc_79(void* p);                                 // 79 0x140c61f00
    virtual int vfunc_82();                                         // 82 0x140c61ea0
    virtual void OnLoadComplete();                                  // 22 0x140c61870

    // UIItemEventListener slot 3 (this+0x180 thunk 0x140c61f60)
    virtual void vfunc_3(void* pItem, bool b);

    void FUN_140c623c0(int nEvent);                                 // notify the shown page
    void FUN_140c62490(int nSlot);                                  // select a slot, notify 10
    void FUN_140c624d0();                                           // notify 11
    int FUN_140c62500() const { return m_nSlot; }                   // the selected equip slot
    void FUN_140c62740();                                           // the shown page: close
    void FUN_140c627a0(unsigned nTab, const Scaleform::GFx::Value& root);   // show the page of tab nTab

    MS2Ptr<Unk_LsTabBar> FUN_140c02870(const CString& strName);     // bind the tab strip

    LapenshardTabPtr m_spPage;                                      // +0x188 the shown page
    ATL::CAtlArray<TabInfoPtr> m_tabs;                              // +0x198
    int m_nSlot;                                                    // +0x1b8
};

// ---- the shield bar HUD -------------------------------------------------------------------------------------------------

// The buff the shield bar shows (layout seen through the HUD's reads only; the object is owned elsewhere).
class Unk_LsBuffInfo
{
public:
    unsigned char m_pad_00[0x2a0];
    __int64 m_nValue;                                               // +0x2a0 the shield value
    unsigned char m_pad_2a8[8];
    unsigned m_nSkillId;                                            // +0x2b0
};
class Unk_LsBuff : public CPtred
{
public:
    unsigned FUN_14096d2e0();                                       // the time left in ms (0 when none or elapsed)

    unsigned char m_pad_18[8];
    unsigned m_nEnd;                                                // +0x20 end tick
    unsigned char m_pad_24[0xc];
    __int64 m_nId;                                                  // +0x30
};
Unk_LsBuffInfo* FUN_14096d810(Unk_LsBuff* pBuff);                   // the buff's info (the object at +0x68)

// The poll timer (ctor 0x140517b00; FUN_140268870: true once nMs have passed since the last true).
class Unk_LsTick
{
public:
    Unk_LsTick();                                                   // 0x140517b00
    void FUN_140268840();                                           // restart
    int FUN_140268870(unsigned nMs);
private:
    unsigned __int64 m_nTick;
};

class Unk_LsEntityEvents;

// 0xa8 bytes, (UIHeadUpDisplay + UIEntityEventListener at +0x70, UI id 0x4f73): shows the shield buff.
class UILapenshardShieldBar : public UIHeadUpDisplay, public UIEntityEventListener
{
public:
    UILapenshardShieldBar();                                        // 0x140c5efa0
    virtual ~UILapenshardShieldBar();                               //  0 0x140c5f090 (??_G 0x140c60770)
    virtual CString vfunc_1();                                      //  1 0x140c5f120 "LapenshardShieldBar"
    virtual void vfunc_3();                                         //  3 0x140c5f5b0
    virtual void vfunc_15();                                        // 15 0x140c5f610
    virtual void OnLoadInit();                                      // 20 0x140c5f170
    virtual void OnLoadComplete();                                  // 22 0x140c5f1d0
    virtual void vfunc_26();                                        // 26 0x140c5f200
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c5f870
    virtual void vfunc_43();                                        // 43 0x140c5f2a0
    virtual int vfunc_48() { return 0x4f73; }                       // 48 0x140c607c0

    void FUN_140c5f8f0(MS2Ptr<Unk_LsBuff> spBuff);                  // show a buff (by value: the callee destroys it)
    MS2Ptr<Unk_LsBuff> FUN_140c5f990();                             // the shown buff
    CStringW FUN_140c5f9e0();                                       // "mm:ss" left
    void FUN_140c5faf0();                                           // play "end"
    int FUN_140c5fbb0() { return m_bEnded; }                        // the buff ended
    void FUN_140c5fbd0();                                           // bind the skill slot and play "open"

    MS2Ptr<Unk_LsBuff> m_spBuff;                                    // +0x78
    int m_nPending;                                                 // +0x88 the buff changed, "open" is due
    CString m_strBind;                                              // +0x90 the skill slot's bind id
    Unk_LsTick m_tick;                                              // +0x98
    int m_bImpending;                                               // +0xa0
    int m_bEnded;                                                   // +0xa4
};
MS2_CHECK_SIZE(UILapenshardShieldBar, 0xa8);
MS2_CHECK_OFFSET(UILapenshardShieldBar, m_spBuff, 0x78);
MS2_CHECK_OFFSET(UILapenshardShieldBar, m_bEnded, 0xa4);
