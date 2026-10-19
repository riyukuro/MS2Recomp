// astriggerstate.h - PLACEHOLDER for ASTriggerState (RTTI .?AVASTriggerState@@, vftable 0x142dbf4c0, 25 slots), the AS
// UI component of one state box of the trigger editor movie. NOT an original header. An ASUIComponent that adds no
// members and no virtuals: the slot list is ASUIComponent's (3 / 4 override ASDisplayObject, 16-24 are ASUIComponent's),
// declared here because placeholder/asuicomponent.h declares none of them. Same declaration as astriggerstate.cpp
// (the unit that owns the ctor / dtor), shared for uitriggereditordialog.cpp. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASTriggerState : public ASUIComponent
{
public:
    ASTriggerState(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1409f00e0
    virtual ~ASTriggerState();                                      // 0x1409f0130
    virtual void vfunc_3(int nVisible);                             // 3  0x1422c7260
    virtual void vfunc_4(bool b);                                   // 4  0x1422c7230
    virtual void vfunc_16();                                        // 16 0x1422c7ec0
    virtual void vfunc_17();                                        // 17 0x1422c7f00
    virtual void vfunc_18();                                        // 18 0x1422c7f40
    virtual void vfunc_19();                                        // 19 0x1422c7f80
    virtual void vfunc_20();                                        // 20 0x1422c7fc0
    virtual void vfunc_21();                                        // 21 0x1422c8000
    virtual void vfunc_22();                                        // 22 0x1422c8040
    virtual void vfunc_23();                                        // 23 0x1422c8080
    virtual void vfunc_24(bool bRefresh);                           // 24 0x1422c80c0 validateNow
};
MS2_CHECK_SIZE(ASTriggerState, 0x88);
