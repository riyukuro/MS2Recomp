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
    virtual void vfunc_11();                                        // 11 0x140c608f0 (looks the local player up)
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
