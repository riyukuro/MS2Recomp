// asdragslot.h - ASDragSlot (RTTI .?AVASDragSlot@@, base ASUIComponent, vftable 0x14311a5a0, 25 slots, no overrides
// besides the dtor): the AS side of a drag slot. Header name and directory assumed (the GFx UI library has no
// __FILE__ strings).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASDragSlot : public ASUIComponent
{
public:
    ASDragSlot(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422f7190
    virtual ~ASDragSlot();                                      // 0x1422f71e0 (scalar deleting 0x1422f7210)
    // Slots 3 and 16-24 are ASUIComponent's (opt-in in asuicomponent.h; same convention as asgameentity.h): redeclared
    // here so the vftable is complete. symbols-manual binds the names to the base VAs.
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260
    virtual void vfunc_16();                                    // 16 0x1422c7ec0
    virtual void vfunc_17();                                    // 17 0x1422c7f00
    virtual void vfunc_18();                                    // 18 0x1422c7f40
    virtual void vfunc_19();                                    // 19 0x1422c7f80
    virtual void vfunc_20();                                    // 20 0x1422c7fc0
    virtual void vfunc_21();                                    // 21 0x1422c8000
    virtual void vfunc_22();                                    // 22 0x1422c8040
    virtual void vfunc_23();                                    // 23 0x1422c8080
    virtual void vfunc_24(bool bInvalidate);                    // 24 0x1422c80c0
};
MS2_CHECK_SIZE(ASDragSlot, 0x88);
