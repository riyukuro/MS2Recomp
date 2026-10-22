// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uihighlightgamemenu.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UIHighlightGameMenu ("HighlightGameMenu", RTTI .?AVUIHighlightGameMenu@@, 0x1f0 bytes): the row of highlight icons
// beside the game menu (character info, skill book, inventory, ...). m_actions maps the icon names to the member
// predicates that decide whether the icon has something new to show; the tick (every second) asks all of them and sends
// the names that say yes to the movie ("setMenu"). The second base (+0x178) is the item event listener: picking up or
// equipping an item marks the gem stone predicate dirty. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are
// non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class NotifyObject;

// The timer the tick uses (one 8-byte time stamp; ctor 0x140517b00, FUN_140268870 asks whether the period elapsed).
struct Unk_HlTimer
{
    void FUN_140517b00();
    int FUN_140268870(int nMs);
    __int64 m_tick;
};
MS2_CHECK_SIZE(Unk_HlTimer, 8);

// A one-byte bit set (commonfiles\bitset.inl: this unit holds its own copies of the members, all with a single bit).
struct Unk_HlBits;
struct Unk_HlBitRef
{
    Unk_HlBits* m_pBits;
    int m_nPos;
    bool FUN_140c24ac0();                               // 0x140c24ac0 the bit
    Unk_HlBitRef(Unk_HlBits* pBits, int nPos);          // 0x140c249d0
};
struct Unk_HlBits
{
    unsigned char m_a[1];
    Unk_HlBits& FUN_140c24770();                        // 0x140c24770 ctor (all clear)
    Unk_HlBits& FUN_140c261c0();                        // 0x140c261c0 set all
    Unk_HlBits& FUN_140c26080();                        // 0x140c26080 clear all
    Unk_HlBits& FUN_140c260a0(int nPos, bool bSet);     // 0x140c260a0 Set
    bool FUN_140c261e0(int nPos) const;                 // 0x140c261e0 Test
    void FUN_140c26280(unsigned char nFill);            // 0x140c26280 Fill
    void FUN_140c262e0();                               // 0x140c262e0 clear the unused bits
    Unk_HlBitRef FUN_140c25f10(int nPos);               // 0x140c25f10 operator[]
};
MS2_CHECK_SIZE(Unk_HlBits, 1);

class UIHighlightGameMenu : public UIDialog, public UIItemEventListener
{
public:
    typedef bool (UIHighlightGameMenu::*Action)();

    UIHighlightGameMenu();                              // 0x140c220d0
    virtual ~UIHighlightGameMenu();                     //  0 0x140c22550 (??_G 0x140c24b90)
    virtual CString vfunc_1();                          //  1 0x140c22690 "HighlightGameMenu"
    virtual void vfunc_67();                            // 67 0x140c226e0
    virtual void OnLoadComplete();                      // 22 0x140c22700 register the item listener, then refresh
    virtual void vfunc_43();                            // 43 0x140c22760 move the movie below the inventory
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x140c22800 icon click
    virtual void vfunc_72();                            // 72 0x140c22ae0 tick
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140c22b30 "getTooltip"
    virtual void vfunc_26();                            // 26 0x140c22c60
    virtual int vfunc_48() { return 0x4f75; }           // 48 0x140c25180 UI type id
    virtual void vfunc_2(void* pItem);                  // UIItemEventListener 2 0x140c22d80
    virtual void vfunc_5(void* pItem, int nCount);      // UIItemEventListener 5 0x140c22d00
    virtual void vfunc_21(void* pItem);                 // UIItemEventListener 21 0x140c22df0
    virtual void vfunc_22(void* pItem);                 // UIItemEventListener 22 0x140c22ea0

    bool IsActive();                               // 0x140c22ce0 the icon count is non-zero
    void FUN_140c244b0(int* pPos, bool bSet);           // 0x140c244b0 set a socket bit
    void FUN_140c22f50();                               // ask every action, send the "setMenu" list
    bool FUN_140c231b0();                               // "inven": a better piece of equipment is in the bag
    bool FUN_140c234d0();                               // "skillbook": a skill point can be spent
    bool FUN_140c235d0();                               // class 6: a gem stone page is open
    bool FUN_140c236f0();                               // "characterinfo": the stat window has a point to spend
    bool FUN_140c237a0();                               // "enchantscroll": a scroll and an item that can use it
    bool FUN_140c23f10();                               // "gemstone": a socket and a gem stone for it
    void FUN_140c24470(NotifyObject* pObj);             // "NotifyGameStart": reset the gem stone bits

private:
    MS2_LAYOUT_FRIEND;
    Unk_HlTimer m_timer;                                // +0x180
    ATL::CAtlMap<CString, Action, ATL::CStringElementTraits<CString> > m_actions;   // +0x188 icon name -> predicate
    __int64 m_nScrollItem;                              // +0x1d0 the enchant scroll found
    __int64 m_nTargetItem;                              // +0x1d8 the item it can be used on
    int m_nCount;                                       // +0x1e0 icons shown
    int m_nMargin;                                      // +0x1e4
    bool m_bActive;                                     // +0x1e8
    Unk_HlBits m_bitsGem;                            // +0x1e9
    Unk_HlBits m_bitsSocket;                         // +0x1ea
    char m_pad_1eb[5];
};
MS2_CHECK_SIZE(UIHighlightGameMenu, 0x1f0);
