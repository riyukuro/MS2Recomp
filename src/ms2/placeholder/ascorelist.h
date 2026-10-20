// ascorelist.h - PLACEHOLDER for the GFx list / dropdown component wrappers. NOT an original header. Classes (RTTI names
// read from the vftables their ctors store; every one is 0x88 bytes, the size the exe child factories allocate):
//   ASCoreList : ASUIComponent             ctor 0x1422dcc20, vftable 0x143113210
//   ASScrollingList : ASCoreList           ctor 0x1422e1720, vftable 0x143114518 (factory 0x140bc61d0)
//   ASListItemRenderer : ASButton          ctor 0x1422e1c50, dtor 0x1422e1ca0, vftable 0x143114740
//   ASItemRendererBase : ASListItemRenderer ctor 0x1422e1f00, vftable 0x143114810 (factory 0x140bc6120)
//   ASDropdownMenu : ASButton              ctor 0x1422df570, vftable 0x143113d70 (factory 0x140bbe120)
// ASTileList (astilelist.h) is another ASCoreList; it predates this header and folds ASCoreList into itself. Older units
// carry unit-local views of the same objects (Unk_SdRow / Unk_CadGiftClip = ASItemRendererBase, Unk_SdList /
// Unk_CadGiftList = ASScrollingList, Unk_PsCombo / Unk_DpCombo = ASDropdownMenu); new code should use these classes.
// Only what recovered code calls is declared.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/delegate.h"

class ASCoreList : public ASUIComponent
{
public:
    ASCoreList(int nMovieId);                                           // 0x1422dcbe0 (a fresh component; ASTileList(int), astilelist.cpp)
    ASCoreList(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422dcc20
    virtual ~ASCoreList();                                              // 0x1422dcc70 (scalar deleting 0x1422de550)
    // ---- recovered with ?\ascorelist.cpp (src/ms2/gfxui/ascorelist.cpp, 0x1422dcbe0-0x1422de590); names are Ghidra's,
    // the comments name the CLIK CoreList member each one uses ----
    void FUN_1422dcca0(int nIndex);                                     // set "selectedIndex" (-1: none)
    int FUN_1422dccd0();                                                // "selectedIndex"
    MS2Ptr<class ASDataProvider> FUN_1422dcd80();                       // "dataProvider" (null if it is not an object)
    void FUN_1422dcdf0(Scaleform::GFx::Value list);                     // set "itemRendererList" (by value: the callee destroys it)
    void FUN_1422dce60(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);   // add a "listIndexChange" listener
    void FUN_1422dcee0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);                // remove the "listIndexChange" listener
    void FUN_1422dcf40(int nCount);                                     // a data provider of nCount undefined entries (slot 25)
    void FUN_1422dd000(unsigned nRows);                                 // set "rowCount"
    unsigned FUN_1422dd030();                                           // "rowCount"
    void FUN_1422dd0d0(int nIndex);                                     // scrollToIndex(index)
    void FUN_1422dd110();                                               // scrollToSelected()
    unsigned FUN_1422dd150();                                           // the entry count (0 without a data provider; asscrollinglist.cpp: `< 0` is an unsigned test)
    void FUN_1422dd1d0();                                               // remove every entry
    void FUN_1422dd230(const class ASObj& item);                        // append an entry
    void FUN_1422dd2a0(const CString& strLabel);                        // append a { label } entry (narrow text)
    void FUN_1422dd310(const CStringW& strLabel);                       // append a { label } entry
    void FUN_1422dd3d0(const CString& strLabel);                        // select the entry with this label (narrow text)
    void FUN_1422dd440(const CStringW& strLabel);                       // select the entry with this label
    CString FUN_1422dd4a0();                                            // the selected entry's label (narrow text)
    CStringW FUN_1422dd520();                                           // the selected entry's label ("" if none)
    bool FUN_1422dd760(AScript& item);                                  // the selected entry (false if none)
    void FUN_1422dd880(const CString& strMember, int nValue);           // select the first entry whose member is a string with GetInt() == nValue
    void FUN_1422dd9e0(const CString& strMember, int nValue);           // the same with GetUInt()
    void FUN_1422ddb40(const CString& strMember, const CStringW& strValue);   // select the first entry whose member equals strValue
    void FUN_1422ddd50(int nIndex);                                     // remove the entry at an index
    void FUN_1422dddc0(const CString& strLabel);                        // remove the first entry with this label
    // "itemPress" / "itemClick" / "itemRollOver" / "itemRollOut" / "itemDoubleClick" listeners: add (pUser: the AS
    // function object's user data), remove
    void FUN_1422de000(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422de080(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422de0e0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422de160(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422de1c0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422de240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422de2a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422de320(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422de380(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422de400(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    // Slot 23 override and the new slot 25 (vftable 0x143113210; ASTileCacheList overrides 25). Opt-in with the
    // ASUIComponent slots (MS2_ASUICOMPONENT_SLOTS): without them slot 25 would land on index 16.
#ifdef MS2_ASUICOMPONENT_SLOTS
    virtual void vfunc_23();                                            // 23 0x1422dd090 invalidateSelectedIndex()
    virtual void vfunc_25(const Scaleform::GFx::Value& data);           // 25 0x1422dcd30 set "dataProvider"
#endif
};
MS2_CHECK_SIZE(ASCoreList, 0x88);

class ASScrollingList : public ASCoreList
{
public:
    ASScrollingList(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422e1720
    virtual ~ASScrollingList();                                         // 0x1422e1770
    void FUN_1422e17a0();                                               // show every entry (row count = entry count)
    void FUN_1422e17f0(int nPosition);                                  // set "scrollPosition"
    int FUN_1422e1820();                                                // "scrollPosition" (the first visible row)
    void FUN_1422e1890(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange);   // add a "listIndexChange" listener
    void FUN_1422e1910(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange);   // remove the "listIndexChange" listener
    void FUN_1422e1970(int nIndex, class ASObj& row);                   // replace a data provider entry
    void FUN_1422e1a00(int nIndex, class ASObj& row);                   // "setData" on the visible renderer of an entry
};
MS2_CHECK_SIZE(ASScrollingList, 0x88);

class ASListItemRenderer : public ASButton
{
public:
    ASListItemRenderer(CString strLinkage, int nMovieId);              // 0x1422e1ba0 (a new clip of the linkage class)
    ASListItemRenderer(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422e1c50
    virtual ~ASListItemRenderer();                                      // 0x1422e1ca0 (scalar deleting 0x1422e2040)
    // recovered with ?\aslistitemrenderer.cpp (src/ms2/gfxui/aslistitemrenderer.cpp)
    bool FUN_1422e1cd0();                                               // "focusable" (the exe tests IsBool(), not the value)
    void FUN_1422e1d30(bool bFocusable);                                // set "focusable"
    unsigned int FUN_1422e1d60();                                       // "index"
    void FUN_1422e1dc0(unsigned int nIndex);                            // set "index"
    bool FUN_1422e1df0();                                               // "selectable" (IsBool(), as above)
    void FUN_1422e1e50(bool bSelectable);                               // set "selectable"
};
MS2_CHECK_SIZE(ASListItemRenderer, 0x88);

class ASItemRendererBase : public ASListItemRenderer
{
public:
    ASItemRendererBase(CString strLinkage, int nMovieId);              // 0x1422e1e80
    ASItemRendererBase(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422e1f00
    // implicit virtual dtor 0x1422e1fe0 (no vptr store: it only calls ~ASListItemRenderer; scalar deleting 0x1422e2000)
    // Registers the row's "set data" callback (the AS "fnSetData" member); pUser comes back in Params::pUserData.
    // onData by value: the callee destroys it.
    void FUN_1422e1f50(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> onData, void* pUser);
};
MS2_CHECK_SIZE(ASItemRendererBase, 0x88);

class ASDropdownMenu : public ASButton
{
public:
    ASDropdownMenu(const Scaleform::GFx::Value& v, int nMovieId);      // 0x1422df570
    virtual ~ASDropdownMenu();
    void FUN_1422df5f0(int nRowCount);                                  // the number of visible rows
    void FUN_1422df690(int nIndex);                                     // select an entry
    int FUN_1422df6c0();                                                // the selected entry
    // Registers the selection-change callback; pUser comes back in Params::pUserData.
    void FUN_1422df9a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);
    void FUN_1422dfce0(const CStringW& strLabel);                       // append an entry
    void FUN_1422dfc10();                                               // remove every entry
    void FUN_1422df720(const Scaleform::GFx::Value& v);                 // set "dataProvider" (asdropdownmenu.cpp)
    MS2Ptr<class ASDataProvider> FUN_1422df770();                       // "dataProvider" (asdropdownmenu.cpp)
    void FUN_140f1fe00(const CString& strMember, __int64* pOut);        // 0x140f1fe00 the selected entry's member (inline COMDAT, defined in uiblackmarketpagemeso.cpp)
};
MS2_CHECK_SIZE(ASDropdownMenu, 0x88);
