// asgameentity.h - PLACEHOLDER for ASGameEntity (RTTI .?AVASGameEntity@@, base ASUIComponent (its ctor calls
// 0x1422c7100), vftable 0x1431132f8 (26 slots), ctor 0x1422de590, dtor 0x1422de5e0, ??_G 0x1422de640). NOT an
// original header; the code is in src/ms2/gfxui/asgameentity.cpp (?\asgameentity.cpp).
// 0x88 bytes (operator new(0x88) in FUN_140ba77e0, the `new ASGameEntity(v, n)` wrapper). Units must include this
// header instead of redefining the class.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASGameEntity : public ASUIComponent
{
public:
    ASGameEntity(const Scaleform::GFx::Value& root, int nMovieId);     // 0x1422de590
    virtual ~ASGameEntity();                                // 0 0x1422de5e0
    // Slots 3 and 16-24 are ASUIComponent's (asuicomponent.h does not declare them yet; same convention as
    // asitemslot.h): redeclared here so slot 25 lands right. symbols-manual binds the names to the base VAs.
    virtual void vfunc_3(int nVisible);                     // 3 0x1422c7260
    virtual void vfunc_16();                                // 16 0x1422c7ec0
    virtual void vfunc_17();                                // 17 0x1422c7f00
    virtual void vfunc_18();                                // 18 0x1422c7f40
    virtual void vfunc_19();                                // 19 0x1422c7f80
    virtual void vfunc_20();                                // 20 0x1422c7fc0
    virtual void vfunc_21();                                // 21 0x1422c8000
    virtual void vfunc_22();                                // 22 0x1422c8040
    virtual void vfunc_23();                                // 23 0x1422c8080
    virtual void vfunc_24(bool bRefresh);                   // 24 0x1422c80c0
    virtual void vfunc_25();                                // 25 0x1422de610 invoke AS "alignment" (UpdateAlignment)
    int FUN_1422c1500();                                    // width
    int FUN_1422c1530();                                    // height
    void FUN_1422bffe0(int x, int y);                       // set the position
    void FUN_1422c00f0(float x, float y);                   // set the position (float)
    void FUN_1422c0f60(float* pX, float* pY);               // get the position
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int nActorId, CString strCache, int n);   // "createEntity" (UIHudEntity family)
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value clip, bool b);     // "updateEntity"
};
MS2_CHECK_SIZE(ASGameEntity, 0x88);
