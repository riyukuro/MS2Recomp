// astilelist.h - PLACEHOLDER for ASTileList (RTTI .?AVASTileList@@ -> ASCoreList -> ASUIComponent), the C++ wrapper of
// a GFx tile list component. NOT an original header. ctor 0x1422cf330 (Value, movie id), dtor 0x1422cf380, sized delete
// 0x88 (0x1422cfc70): no members beyond ASUIComponent. ASCoreList (no RTTI of its own in the hierarchy walk here) is
// folded into this class. Several units still use unit-local stand-ins (Unk_TmBag, Unk_LdItemBag, Unk_PetItemBag, ...);
// new code should use this class. Only what recovered code calls is declared.
#pragma once

#include "ms2/placeholder/asuicomponent.h"

class ASTileList : public ASUIComponent
{
public:
    ASTileList(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422cf330
    virtual ~ASTileList();                                             // 0 0x1422cf380
    void FUN_1422dcca0(int nIndex);                                     // ASCoreList: select an entry (-1: none)
    int FUN_1422dccd0();                                                // ASCoreList: the selected entry
    void FUN_1422dcf40(int nCount);                                     // ASCoreList: the number of entries (uidungeonroomdialog)
    void FUN_1422dce60(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);   // ASCoreList: the selection-change callback (uidungeonroomdialog)
    void FUN_1422dd1d0();                                               // ASCoreList: clear
    void FUN_1422dd230(const class ASObj& item);                        // ASCoreList: append an entry (uitriggereditordialog.cpp)
};
MS2_CHECK_SIZE(ASTileList, 0x88);
