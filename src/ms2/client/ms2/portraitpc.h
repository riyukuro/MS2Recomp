// portraitpc.h - PortraitPC (efd RTTI "PortraitPC", class id 0x06200016, size 0x1348): the PC of the character portrait
// preview. Owning unit: ?\portraitpc.cpp (0x1416999b0-0x14169afb0 .text$mn, plus 0x1400fbf80-0x1400fc110 .text$di).
// Header name assumed.
//
// PortraitPC : ClonePC (0x1340), UIItemEventListener (+0x1340, 35 slots). ClassInfo 0x143ae4050 (setup COMDAT
// 0x14169ac60), vftables 0x142f4e9d8 (primary) / 0x142f4eea8 (CallbackObject) / 0x142f4eee0 (listener). It mirrors
// the equipment of a source PC (the account's own character when the "my codi" tab changes) into a model view.
// Heap-only.
#pragma once
#include "ms2/client/ms2/clonepc.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class NotifyObject;

class PortraitPC : public ClonePC, public UIItemEventListener
{
    EE_DECLARE_CLASS1(PortraitPC, 0x06200016, ClonePC);

public:
    PortraitPC(PC* pSource);                                // 0x14169a160
    virtual ~PortraitPC();                                  // 0x1416999b0

    virtual int vfunc_10();                                 // 10  0x14169a200
    virtual void vfunc_14();                                // 14  0x14169a040
    virtual void vfunc_53(float f);                         // 53  0x14169a4f0
    virtual void vfunc_143();                               // 143 0x14169a3d0
    virtual void vfunc_147(UIModelView* pView);             // 147 0x141699fc0
    virtual void vfunc_149();                               // 149 0x141699d60 copies the source PC's equipment

    // UIItemEventListener (+0x1340): every item event makes the portrait rebuild its equip list
    virtual void vfunc_21(void*);                           // 0x14169a740
    virtual void vfunc_22(void*);                           // 0x14169a770
    virtual void vfunc_24(void*);                           // 0x14169a7a0
    virtual void vfunc_25(void*);                           // 0x14169a7d0
    virtual void vfunc_30(void*);                           // 0x14169a800
    virtual void vfunc_31(void*);                           // 0x14169a830
    virtual void vfunc_33(int nClass, int n);               // 0x14169a000 class 0x6200004 only

    void FUN_14169a5e0();                                   // 0x14169a5e0 hands the equip models to the view
    void FUN_14169a710(NotifyObject* pNotify);              // 0x14169a710 "my codi" tab changed: rebuild
};
MS2_CHECK_SIZE(PortraitPC, 0x1348);
