// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTileList and its cached-renderer subclasses
// ASTileCacheList, ASItemBag and ASMultiSelectTileCacheList: the C++ wrappers of the CLIK TileList components.
// MS2-UNIT: ?\astilelist.cpp
// MS2-RANGE: 0x1422cf290-0x1422cfcb0 .text$mn
// MS2-PIN: ??_GASItemBag@@UEAAPEAXI@Z 0x1422cfbb0
// MS2-PIN: ??_GASMultiSelectTileCacheList@@UEAAPEAXI@Z 0x1422cfbf0
// MS2-PIN: ??_GASTileCacheList@@UEAAPEAXI@Z 0x1422cfc30
// MS2-PIN: ??_GASTileList@@UEAAPEAXI@Z 0x1422cfc70
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: ASCommonDepth-era tail of the previous obj ends at 0x1422cf290; ASStage's ctor starts the next obj at
// 0x1422cfcb0. The classes are declared in src/ms2/placeholder/astilelist.h and asmultiselecttilecachelist.h (method
// names are Ghidra's, the comments name the AS member each one uses). The COMDAT tail holds the two "every element as a
// UInt" helpers of the selected-list getters (CAtlArray / std::vector) and the four scalar deleting dtors (all
// grouped after the helpers, in mangled-name order).
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include <atlcoll.h>
#include <vector>

#include "ms2/placeholder/asmultiselecttilecachelist.h"
#include "ms2/placeholder/asobj.h"

#include "hook/ms2hook.h"

// The GFx movie of a movie id (AScript's static helper, ascript.cpp range; null if the movie is not loaded).
Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);

// Every element of an AS array as a UInt appended to a container (inline COMDATs; names invented).
template <class T> void GetAll(ASArray& arr, ATL::CAtlArray<T>& aOut);
template <class T> void GetAll(ASArray& arr, std::vector<T>& aOut);

// @0x1422cf290
ASTileList::ASTileList(int nMovieId)
    : ASCoreList(nMovieId)
{
    m_nMovieId = nMovieId;
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie == NULL)
        return;
    pMovie->CreateObject(&m_value, "scaleform.clik.controls.TileList", NULL, 0);
}

// @0x1422cf330
ASTileList::ASTileList(const Scaleform::GFx::Value& v, int nMovieId)
    : ASCoreList(v, nMovieId)
{
}

// @0x1422cf380
ASTileList::~ASTileList()
{
}

// @0x1422cf3b0
void ASTileList::FUN_1422cf3b0(Scaleform::GFx::Value scrollBar)
{
    FUN_1409adbe0("scrollBar", scrollBar);
}

// @0x1422cf420
Scaleform::GFx::Value ASTileList::FUN_1422cf420()
{
    return FUN_1422baa20("scrollBar");
}
MS2_REPLACE_METHOD(0x1422CF420, ASTileList, FUN_1422cf420, 65, 0xCB76CB8D);

// @0x1422cf470
void ASTileList::FUN_1422cf470(unsigned nWidth)
{
    FUN_140e06d60("columnWidth", nWidth);
}
MS2_REPLACE_METHOD(0x1422CF470, ASTileList, FUN_1422cf470, 47, 0xD59311EF);

// @0x1422cf4b0
void ASTileList::FUN_1422cf4b0(unsigned nHeight)
{
    FUN_140e06d60("rowHeight", nHeight);
}
MS2_REPLACE_METHOD(0x1422CF4B0, ASTileList, FUN_1422cf4b0, 47, 0x35ABF3B4);

// @0x1422cf4f0
void ASTileList::FUN_1422cf4f0(int nRow)
{
    FUN_1407cb9c0("scrollPosition", nRow);
}
MS2_REPLACE_METHOD(0x1422CF4F0, ASTileList, FUN_1422cf4f0, 40, 0x4C605C86);

// @0x1422cf520
int ASTileList::FUN_1422cf520()
{
    return (int)FUN_1422baa20("scrollPosition").GetNumber();
}
MS2_REPLACE_METHOD(0x1422CF520, ASTileList, FUN_1422cf520, 92, 0x3064F1C5);

// @0x1422cf590
ASTileCacheList::ASTileCacheList(const Scaleform::GFx::Value& v, int nMovieId)
    : ASTileList(v, nMovieId)
{
}

// @0x1422cf5e0
ASTileCacheList::~ASTileCacheList()
{
}

// @0x1422cf610
void ASTileCacheList::vfunc_25(const Scaleform::GFx::Value& data)
{
    FUN_1422cf720();
    ASCoreList::vfunc_25(data);
}
MS2_REPLACE_METHOD(0x1422CF610, ASTileCacheList, vfunc_25, 44, 0x5C059142);

// @0x1422cf650
void ASTileCacheList::FUN_1422cf650(int nIndex, AScript& item)
{
    Invoke("addItemData", nIndex, item.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1422CF650, ASTileCacheList, FUN_1422cf650, 123, 0xB4855FE1);

// @0x1422cf6e0
void ASTileCacheList::FUN_1422cf6e0(int nIndex)
{
    Invoke("removeItemData", nIndex);
}
MS2_REPLACE_METHOD(0x1422CF6E0, ASTileCacheList, FUN_1422cf6e0, 55, 0x0768FB48);

// @0x1422cf720
void ASTileCacheList::FUN_1422cf720()
{
    Invoke("resetRenderer");
}
MS2_REPLACE_METHOD(0x1422CF720, ASTileCacheList, FUN_1422cf720, 46, 0x8833EEE5);

// @0x1422cf760
ASItemBag::ASItemBag(const Scaleform::GFx::Value& v, int nMovieId)
    : ASTileCacheList(v, nMovieId)
{
}

// @0x1422cf7b0
ASItemBag::~ASItemBag()
{
}

// @0x1422cf7e0
void ASItemBag::FUN_1422cf7e0(int nIndex)
{
    Invoke("add", nIndex);
}
MS2_REPLACE_METHOD(0x1422CF7E0, ASItemBag, FUN_1422cf7e0, 55, 0x7C2FB1E0);

// @0x1422cf820
void ASItemBag::FUN_1422cf820(int nIndex)
{
    Invoke("remove", nIndex);
}
MS2_REPLACE_METHOD(0x1422CF820, ASItemBag, FUN_1422cf820, 55, 0xDDD4538B);

// @0x1422cf860
void ASItemBag::FUN_1422cf860()
{
    Invoke("update");
}
MS2_REPLACE_METHOD(0x1422CF860, ASItemBag, FUN_1422cf860, 46, 0x86BA5BD0);

// @0x1422cf8a0
ASMultiSelectTileCacheList::ASMultiSelectTileCacheList(const Scaleform::GFx::Value& v, int nMovieId)
    : ASItemBag(v, nMovieId)
{
}

// @0x1422cf8f0
ASMultiSelectTileCacheList::~ASMultiSelectTileCacheList()
{
}

// @0x1422cf920
unsigned ASMultiSelectTileCacheList::FUN_1422cf920()
{
    return Invoke("getSelectedCount").GetUInt();
}
MS2_REPLACE_METHOD(0x1422CF920, ASMultiSelectTileCacheList, FUN_1422cf920, 88, 0x5E98B9ED);

// @0x1422cf980
void ASMultiSelectTileCacheList::FUN_1422cf980(std::vector<unsigned>& aSelected)
{
    ASArray arr(m_nMovieId);
    FUN_140caf140("getSelectedList", arr);
    GetAll(arr, aSelected);
}
MS2_REPLACE_METHOD(0x1422CF980, ASMultiSelectTileCacheList, FUN_1422cf980, 158, 0x13EE0D5E);

// @0x1422cfa30
void ASMultiSelectTileCacheList::FUN_1422cfa30(ATL::CAtlArray<unsigned>& aSelected)
{
    ASArray arr(m_nMovieId);
    FUN_140caf140("getSelectedList", arr);
    GetAll(arr, aSelected);
}
MS2_REPLACE_METHOD(0x1422CFA30, ASMultiSelectTileCacheList, FUN_1422cfa30, 158, 0xAAD87653);

// @0x1422cfad0
template <class T> void GetAll(ASArray& arr, ATL::CAtlArray<T>& aOut)
{
    unsigned nCount = arr.FUN_1422bc5d0();
    for (unsigned i = 0; i < nCount; i++) {
        T value;
        arr.FUN_1422bc860(i, value);
        aOut.Add(value);
    }
}

// @0x1422cfb40
template <class T> void GetAll(ASArray& arr, std::vector<T>& aOut)
{
    unsigned nCount = arr.FUN_1422bc5d0();
    for (unsigned i = 0; i < nCount; i++) {
        T value;
        arr.FUN_1422bc860(i, value);
        aOut.push_back(value);
    }
}
