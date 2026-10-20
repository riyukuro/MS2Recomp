// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASScrollingList, the ActionScript scrolling list wrapper of
// the GFx UI library.
// MS2-UNIT: ?\asscrollinglist.cpp
// MS2-RANGE: 0x1422e1720-0x1422e1ba0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/ascorelist.h (with its base ASCoreList).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

// @0x1422e1720
ASScrollingList::ASScrollingList(const Scaleform::GFx::Value& v, int nMovieId)
    : ASCoreList(v, nMovieId)
{
}

// @0x1422e1770
ASScrollingList::~ASScrollingList()
{
}

// @0x1422e17a0
void ASScrollingList::FUN_1422e17a0()
{
    FUN_1422dd0d0(FUN_1422dd150() < 0 ? 0 : FUN_1422dd150());
}
MS2_REPLACE_METHOD(0x1422E17A0, ASScrollingList, FUN_1422e17a0, 66, 0x49B7C3FB);

// @0x1422e17f0
void ASScrollingList::FUN_1422e17f0(int nPosition)
{
    FUN_1407cb9c0("scrollPosition", nPosition);
}
MS2_REPLACE_METHOD(0x1422E17F0, ASScrollingList, FUN_1422e17f0, 40, 0x5680D819);

// @0x1422e1820
int ASScrollingList::FUN_1422e1820()
{
    return (int)FUN_1422baa20("scrollPosition").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E1820, ASScrollingList, FUN_1422e1820, 92, 0x79FE17F6);

// @0x1422e1890
void ASScrollingList::FUN_1422e1890(const ASCallback& onChange)
{
    FUN_1422c3600("listIndexChange", onChange, false, 0, 0, (void*)NULL);
}
MS2_REPLACE_METHOD(0x1422E1890, ASScrollingList, FUN_1422e1890, 107, 0xE25DFB5F);

// @0x1422e1910
void ASScrollingList::FUN_1422e1910(const ASCallback& onChange)
{
    FUN_1422c3820("listIndexChange", onChange, false);
}
MS2_REPLACE_METHOD(0x1422E1910, ASScrollingList, FUN_1422e1910, 82, 0xDAF972B7);

// @0x1422e1970
void ASScrollingList::FUN_1422e1970(int nIndex, ASObj& row)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider == 0)
        return;
    spProvider->FUN_1422bc730(nIndex, row.FUN_1422bb890());
}
MS2_REPLACE_METHOD(0x1422E1970, ASScrollingList, FUN_1422e1970, 135, 0x4455B56B);

// @0x1422e1a00
void ASScrollingList::FUN_1422e1a00(int nIndex, ASObj& row)
{
    int nRow = nIndex - FUN_1422e1820();
    Scaleform::GFx::Value renderer = Invoke("getRendererAt", nRow);
    if (renderer.IsDisplayObject()) {
        MS2Ptr<ASDisplayObject> spRenderer(new ASDisplayObject(renderer, m_nMovieId));
        if (spRenderer.get())
            spRenderer->FUN_140acd1f0("setData", row);
    }
}
MS2_REPLACE_METHOD(0x1422E1A00, ASScrollingList, FUN_1422e1a00, 345, 0x9E718522);

// MS2-PIN: ??_GASScrollingList@@UEAAPEAXI@Z 0x1422e1b60
