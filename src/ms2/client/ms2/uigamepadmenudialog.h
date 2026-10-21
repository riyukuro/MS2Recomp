// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uigamepadmenudialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UIGamePadMenuDialog ("GamePadMenuDialog", UI type 0x4f63, RTTI .?AVUIGamePadMenuDialog@@, 0x270 bytes): the gamepad
// radial menu. The menu entries come from the menu table (singleton at 0x143abe318): m_menus holds the top level
// nodes, m_pages remembers the sub-menu count of every page and m_enable the enable state of the entries that are
// not in the movie yet. The d-pad / stick keys (0x92..0x95) move the cursor ("moveMenu"), the movie reports a click
// as "<menu>[_event]" and the dialog runs the entry (key bind or the dialog of its ui id). Names: virtuals are
// Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uigamemenudialog.h"   // EMenuKey (m_enable shares UIGameMenuDialog::m_enabled's CAtlMap instance)
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"

class Unk_GpNode;
class Unk_GpButton;
class NotifyObject;
class ASObj;

class UIGamePadMenuDialog : public UIDialog
{
public:
    UIGamePadMenuDialog();                              // 0x140c1aaf0
    virtual ~UIGamePadMenuDialog();                     //  0 0x140c1ad10 (??_G 0x140c1ce70)
    virtual CString vfunc_1();                          //  1 0x140c1ae70 "GamePadMenuDialog"
    virtual void vfunc_67();                            // 67 0x140c1aec0 close: reset the cursor and the menus
    virtual void OnLoadInit();                          // 20 0x140c1af20
    virtual void OnLoadComplete();                      // 22 0x140c1af40 build the menus
    virtual void vfunc_26();                            // 26 0x140c1afa0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x140c1afc0 "OnMove" / menu click
    virtual int vfunc_13();                             // 13 0x140c1b230 d-pad keys
    virtual void vfunc_72();                            // 72 0x140c1b400 tick: hand out the queued menus
    virtual int vfunc_48() { return 0x4f63; }           // 48 0x140c1d3f0 UI type id

    void FUN_140c1b550();                               // fill m_menus and send "updateAlignment"
    void FUN_140c1b620();                               // send the first queued menu ("addMenuEntity")
    void FUN_140c1ba90(int nMenu, int nEnable);         // "setMenuEnable" / remember it
    int FUN_140c1c770() { return 1; }                   // the menu page kind
    CString FUN_140c1bc10(int nMenu, __int64 nUnused);  // menu name
    CString FUN_140c1bcd0(int nMenu);                   // menu name (the other record flavour)
    MS2Ptr<Unk_GpButton> FUN_140c1bd90(int nMenu, __int64 nUnused);    // button of a menu
    MS2Ptr<Unk_GpButton> FUN_140c1be20(const CString& strMenu);     // "m_menus.<name>.m_button"
    int FUN_140c1bf90(int nMenu);                       // enable state (1 when unknown)
    void FUN_140c1bfe0(NotifyObject* pObj);             // "NotifyCompleteMyPC": forget the enable states
    void FUN_140c1c010(ATL::CAtlArray<MS2Ptr<Unk_GpNode> >& dst);   // collect the menus that can be shown
    int FUN_140c1c160(int nMenu, ASObj* pObj);          // fill the "addMenuEntity" arguments
    void FUN_140c1c530(int nKey);                       // move the cursor
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);  // bind a movie clip child (this+0x30)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<Unk_GpNode> > m_menus;        // +0x178
    ATL::CAtlMap<EMenuKey, int> m_enable;               // +0x198 menu id -> enable state (the CAtlMap<EMenuKey, int> code at 0x140c1xxxx)
    ATL::CAtlMap<int, unsigned int> m_pages;            // +0x1e0 page -> sub-menu count (the CAtlMap<int, UINT> code at 0x1405xxxxx)
    int m_nPage;                                        // +0x228
    int m_nItem;                                        // +0x22c
    Timer m_timer;                                      // +0x230
    int m_nMoveMs;                                      // +0x268 0x32
};
MS2_CHECK_SIZE(UIGamePadMenuDialog, 0x270);
