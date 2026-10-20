// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASStage, the ActionScript stage wrapper of the GFx UI library.
// MS2-UNIT: ?\asstage.cpp
// MS2-RANGE: 0x1422cfcb0-0x1422cfff0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asdisplayobject.h.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

using Scaleform::GFx::Value;

// @0x1422cfcb0
ASStage::ASStage(const Value& v, int nMovieId)
    : ASDisplayObjectContainer(v, nMovieId)
{
}

// @0x1422cfd00
ASStage::~ASStage()
{
}

// @0x1422cfd30
void ASStage::FUN_1422cfd30(MS2Ptr<ASInteractiveObject> spFocus)
{
    if (spFocus.get() != NULL)
        FUN_1409adbe0("focus", spFocus->FUN_1422bb870());
    else
    {
        Value vNull;
        vNull.SetNull();
        FUN_1409adbe0("focus", vNull);
    }
}
MS2_REPLACE_METHOD(0x1422CFD30, ASStage, FUN_1422cfd30, 232, 0x478C3201);

// @0x1422cfe20
MS2Ptr<ASInteractiveObject> ASStage::FUN_1422cfe20()
{
    return MS2Ptr<ASInteractiveObject>(0);
}
MS2_REPLACE_METHOD(0x1422CFE20, ASStage, FUN_1422cfe20, 55, 0x0FDCBAB2);

// @0x1422cfe60
void ASStage::FUN_1422cfe60(int nWidth)
{
    FUN_1407cb9c0("stageWidth", nWidth);
}
MS2_REPLACE_METHOD(0x1422CFE60, ASStage, FUN_1422cfe60, 40, 0x62C4E4F5);

// @0x1422cfe90
void ASStage::FUN_1422cfe90(int nHeight)
{
    FUN_1407cb9c0("stageHeight", nHeight);
}
MS2_REPLACE_METHOD(0x1422CFE90, ASStage, FUN_1422cfe90, 40, 0x6226BB45);

// @0x1422cfec0
int ASStage::FUN_1422cfec0()
{
    return FUN_1422baa20("stageWidth").GetInt();
}
MS2_REPLACE_METHOD(0x1422CFEC0, ASStage, FUN_1422cfec0, 88, 0x6AB19A62);

// @0x1422cff20
int ASStage::FUN_1422cff20()
{
    return FUN_1422baa20("stageHeight").GetInt();
}
MS2_REPLACE_METHOD(0x1422CFF20, ASStage, FUN_1422cff20, 88, 0xB85A16CE);

// @0x1422cff80
ASStage* ASStage::vfunc_5()
{
    return this;
}
MS2_REPLACE_METHOD(0x1422CFF80, ASStage, vfunc_5, 11, 0x3BE09B6E);

// MS2-PIN: ??_GASStage@@UEAAPEAXI@Z 0x1422cffb0
