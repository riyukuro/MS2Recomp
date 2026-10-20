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
    virtual ~ASCoreList();                                              // 0x1422dcc70 (astilelist.cpp)
    void FUN_1422dcf40(int nCount);                                     // the number of rows ("dataProvider" length)
    MS2Ptr<class ASDataProvider> FUN_1422dcd80();                       // the data provider
    void FUN_1422dd0d0(int nRows);                                      // the visible row count
    unsigned FUN_1422dd150();                                           // the entry count (asscrollinglist.cpp: `< 0` is an unsigned test)
    // Slot 23 override and the new slot 25 (vftable 0x143113210; ASTileCacheList overrides 25). Opt-in with the
    // ASUIComponent slots (MS2_ASUICOMPONENT_SLOTS): without them slot 25 would land on index 16.
#ifdef MS2_ASUICOMPONENT_SLOTS
    virtual void vfunc_23();                                            // 23 0x1422dd090
    virtual void vfunc_25(const Scaleform::GFx::Value& data);           // 25 0x1422dcd30 set the data provider
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
};
MS2_CHECK_SIZE(ASDropdownMenu, 0x88);
