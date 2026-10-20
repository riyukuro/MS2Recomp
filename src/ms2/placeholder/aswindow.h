// aswindow.h - PLACEHOLDER for ASWindow (RTTI .?AVASWindow@@, an ASGameEntity, vftable 0x143115d48) and ASDialog (RTTI
// .?AVASDialog@@, an ASWindow, vftable 0x143115e20). NOT an original header. Both reuse ASGameEntity's 26 slots and add
// no virtuals or members (the ctors 0x1422e6170 / 0x1422e63e0 only call the base ctor and store the vftable). Several
// older units carry unit-local ASDialog views (uinoticedialog.cpp, uitradedialogex.cpp, ...); new units include this
// header. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asgameentity.h"

class ASWindow : public ASGameEntity
{
public:
    ASWindow(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422e6170
    virtual ~ASWindow();                                            // 0x1422e61c0
    void FUN_1422e61f0(int bEnable);                                // "setTopMostEnable"
    void FUN_1422e6230(int bCanDrag);                               // "setCanDrag"
    int FUN_1422e6270();                                            // ceil("getWindowHeight"()), 0 if undefined / null
    int FUN_1422e6310();                                            // ceil("getWindowWidth"()), 0 if undefined / null
};
MS2_CHECK_SIZE(ASWindow, 0x88);

class ASDialog : public ASWindow
{
public:
    ASDialog(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422e63e0
    virtual ~ASDialog();                                            // 0x1422e6430
};
MS2_CHECK_SIZE(ASDialog, 0x88);
