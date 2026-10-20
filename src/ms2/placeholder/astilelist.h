// astilelist.h - PLACEHOLDER for ASTileList (RTTI .?AVASTileList@@ -> ASCoreList -> ASUIComponent), the C++ wrapper of
// a GFx tile list component. NOT an original header. ctor 0x1422cf330 (Value, movie id), dtor 0x1422cf380, sized delete
// 0x88 (0x1422cfc70): no members beyond ASUIComponent. Its base is ASCoreList (ascorelist.h; the ctors call 0x1422dcbe0 /
// 0x1422dcc20); the ASCoreList members it redeclares predate that and stay for their callers. Several units still use unit-local stand-ins (Unk_TmBag, Unk_LdItemBag, Unk_PetItemBag, ...);
// new code should use this class. Only what recovered code calls is declared.
#pragma once

#include "ms2/placeholder/ascorelist.h"

class ASTileList : public ASCoreList
{
public:
    ASTileList(int nMovieId);                                          // 0x1422cf290 (a new "scaleform.clik.controls.TileList")
    ASTileList(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422cf330
    virtual ~ASTileList();                                             // 0 0x1422cf380
    void FUN_1422dcca0(int nIndex);                                     // ASCoreList: select an entry (-1: none)
    int FUN_1422dccd0();                                                // ASCoreList: the selected entry
    void FUN_1422dcf40(int nCount);                                     // ASCoreList: the number of entries (uidungeonroomdialog)
    void FUN_1422dce60(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);   // ASCoreList: the selection-change callback (uidungeonroomdialog)
    void FUN_1422dd1d0();                                               // ASCoreList: clear
    void FUN_1422dd230(const class ASObj& item);                        // ASCoreList: append an entry (uitriggereditordialog.cpp)
    MS2Ptr<class ASDataProvider> FUN_1422dcd80();                       // ASCoreList: the data provider (uibeautyshopdevdialog.cpp)
    // ---- recovered with ?\astilelist.cpp (src/ms2/gfxui/astilelist.cpp, 0x1422cf290-0x1422cfcb0) ----
    void FUN_1422cf3b0(Scaleform::GFx::Value scrollBar);               // set "scrollBar" (by value: the callee destroys it)
    Scaleform::GFx::Value FUN_1422cf420();                              // "scrollBar"
    void FUN_1422cf470(unsigned nWidth);                                // set "columnWidth"
    void FUN_1422cf4b0(unsigned nHeight);                               // set "rowHeight"
    void FUN_1422cf4f0(int nRow);                                       // set "scrollPosition" (the first visible row)
    int FUN_1422cf520();                                                // "scrollPosition"
};
MS2_CHECK_SIZE(ASTileList, 0x88);
