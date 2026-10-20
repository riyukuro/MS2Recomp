// asmultiselecttilecachelist.h - PLACEHOLDER for ASTileCacheList (RTTI .?AVASTileCacheList@@ -> ASTileList), ASItemBag
// (-> ASTileCacheList) and ASMultiSelectTileCacheList (-> ASItemBag), the C++ wrappers of GFx tile lists that cache their
// item renderers; the multi-select one lets several entries be selected (the item bags of the select dialogs). NOT an
// original header. Recovered with ?\astilelist.cpp (src/ms2/gfxui/astilelist.cpp, 0x1422cf290-0x1422cfcb0). All are 0x88
// bytes (operator new(0x88) in the GetChild<ASMultiSelectTileCacheList> COMDATs, e.g. 0x140e8ce30) and add no members.
// vftables (26 slots, equal except the dtor): ASTileCacheList 0x143111728, ASItemBag 0x143111800,
// ASMultiSelectTileCacheList 0x1431118d8. Slots 16..25 belong to the bases (ASUIComponent 16..22 and 24, ASCoreList 23
// and 25, ASTileCacheList 25). With MS2_ASUICOMPONENT_SLOTS the bases declare them; without it ASMultiSelectTileCacheList
// declares 16..25 itself (as before) so that calls resolve to the exe slots. Units with older local stand-ins:
// unit_140f7d060.cpp, uiselectitemboxdialog.h (Unk_SibList). Only what recovered code calls is declared.
#pragma once

#include <atlcoll.h>
#include <vector>
#include "ms2/placeholder/astilelist.h"

class ASTileCacheList : public ASTileList
{
public:
    ASTileCacheList(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422cf590
    virtual ~ASTileCacheList();                                         // 0 0x1422cf5e0 (scalar deleting 0x1422cfc30)
#ifdef MS2_ASUICOMPONENT_SLOTS
    virtual void vfunc_25(const Scaleform::GFx::Value& data);           // 25 0x1422cf610 resetRenderer, then ASCoreList's
#endif
    void FUN_1422cf650(int nIndex, AScript& item);                      // addItemData(index, item)
    void FUN_1422cf6e0(int nIndex);                                     // removeItemData(index)
    void FUN_1422cf720();                                               // resetRenderer()
};
MS2_CHECK_SIZE(ASTileCacheList, 0x88);

class ASItemBag : public ASTileCacheList
{
public:
    ASItemBag(const Scaleform::GFx::Value& v, int nMovieId);           // 0x1422cf760
    virtual ~ASItemBag();                                               // 0 0x1422cf7b0 (scalar deleting 0x1422cfbb0)
    void FUN_1422cf7e0(int nIndex);                                     // add(index)
    void FUN_1422cf820(int nIndex);                                     // remove(index)
    void FUN_1422cf860();                                               // update()
};
MS2_CHECK_SIZE(ASItemBag, 0x88);

class ASMultiSelectTileCacheList : public ASItemBag
{
public:
    ASMultiSelectTileCacheList(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422cf8a0
    virtual ~ASMultiSelectTileCacheList();                             //  0 0x1422cf8f0 (scalar deleting 0x1422cfbf0)
#ifndef MS2_ASUICOMPONENT_SLOTS
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
#endif
    unsigned FUN_1422cf920();                                          // getSelectedCount()
    void FUN_1422cf980(std::vector<unsigned>& aSelected);              // getSelectedList() into a vector
    void FUN_1422cfa30(ATL::CAtlArray<unsigned>& aSelected);           // getSelectedList() into an array
};
MS2_CHECK_SIZE(ASMultiSelectTileCacheList, 0x88);
