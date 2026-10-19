// asmultiselecttilecachelist.h - PLACEHOLDER for ASMultiSelectTileCacheList (RTTI .?AVASMultiSelectTileCacheList@@ ->
// ASItemBag -> ASTileCacheList -> ASTileList), the C++ wrapper of a GFx tile list whose entries can be multi-selected
// (the item bags of the select dialogs). NOT an original header. ctor 0x1422cf8a0 (Value, movie id), 0x88 bytes
// (operator new(0x88) in the GetChild<ASMultiSelectTileCacheList> COMDATs, e.g. 0x140e8ce30), vftable 0x1431118d8
// (26 slots; ASItemBag 0x143111800 and ASTileCacheList 0x143111728 have the same slots except the dtor). ASItemBag
// and ASTileCacheList add no members and are folded into this class. Slots 16..25 belong to the bases (ASUIComponent
// 16..22 and 24, ASCoreList 23, ASTileList 25), which do not declare them; they are declared here so calls resolve to
// the exe slots. Units with older local stand-ins: unit_140f7d060.cpp, uiselectitemboxdialog.h (Unk_SibList).
// Only what recovered code calls is declared.
#pragma once

#include <atlcoll.h>
#include "ms2/placeholder/astilelist.h"

class ASMultiSelectTileCacheList : public ASTileList
{
public:
    ASMultiSelectTileCacheList(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422cf8a0
    virtual ~ASMultiSelectTileCacheList();                             //  0 0x1422cfbf0 (deleting)
    virtual void vfunc_16();                                           // 16 0x1422c7ec0
    virtual void vfunc_17();                                           // 17 0x1422c7f00
    virtual void vfunc_18();                                           // 18 0x1422c7f40
    virtual void vfunc_19();                                           // 19 0x1422c7f80
    virtual void vfunc_20();                                           // 20 0x1422c7fc0
    virtual void vfunc_21();                                           // 21 0x1422c8000
    virtual void vfunc_22();                                           // 22 0x1422c8040
    virtual void vfunc_23();                                           // 23 0x1422dd090
    virtual void vfunc_24(bool bValidate);                             // 24 0x1422c80c0 validateNow
    virtual void vfunc_25(const Scaleform::GFx::Value& data);          // 25 0x1422cf610 set the data provider
    unsigned FUN_1422cf920();                                          // the selected entry count
    void FUN_1422cfa30(ATL::CAtlArray<unsigned>& aSelected);           // the selected entry indices
};
MS2_CHECK_SIZE(ASMultiSelectTileCacheList, 0x88);
