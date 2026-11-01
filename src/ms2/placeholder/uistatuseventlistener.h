// uistatuseventlistener.h - PLACEHOLDER for UIStatusEventListener (RTTI .?AVUIStatusEventListener@@), the 8-byte
// listener base that UI dialogs and HUD entities list as a secondary base (vptr only). NOT an original header.
// Owning unit ?\uistatuseventlistener.cpp (0x141b0cc00-0x141b127f0, unrecovered); every out-of-line member is a
// symbols-manual row. vftable 0x142fe5a08 (32 slots). Slot names are vfunc_oa0_<slot> (the Ghidra names for the
// +0xa0 subobject of UIEmoticon::Entity); the base implementations are the exe's no-op stubs at 0x140aa6xxx.
// Recovered by w20 with ?\uiemoticon.cpp; parameter types from the prologues of the base stubs (work/uibase/slotsig.py); 7, 8 and 10 take a CStringW
// by value that the callee destroys.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"

class UIStatusEventListener
{
public:
    UIStatusEventListener();                                // 0x141b0cc00
    virtual ~UIStatusEventListener();                       //  0 0x141b0cc20 (??_G 0x141b0e560)
    virtual int vfunc_oa0_1();                              //  1 0x141b0cc40 returns 1
    virtual void vfunc_oa0_2();                             //  2 0x140aa6d70
    virtual void vfunc_oa0_3(int a1, int a2) {}                          //  3 COMDAT 0x140ba4fc0 (first emitted in ?\uiadventureleveldialog.cpp)
    virtual void vfunc_oa0_4(int a1, int a2) {}                          //  4 COMDAT 0x140ba4fe0 (first emitted in ?\uiadventureleveldialog.cpp)
    virtual void vfunc_oa0_5(int a1, int a2);                             //  5 0x140aa6d80
    virtual void vfunc_oa0_6(void* a1, void* a2);                             //  6 0x140aa6d90
    virtual void vfunc_oa0_7(int a1, CStringW s);         //  7 0x140aa6de0
    virtual void vfunc_oa0_8(CStringW s);                   //  8 0x140aa6e60
    virtual void vfunc_oa0_9(unsigned short a1) {}                          //  9 COMDAT 0x140ba4fd0 (first emitted in ?\uiadventureleveldialog.cpp)
    virtual void vfunc_oa0_10(CStringW s);                  // 10 0x140aa6da0
    virtual void vfunc_oa0_11(void* a1);                            // 11 0x140aa6e50
    virtual void vfunc_oa0_12(int a1);                            // 12 0x140aa6ed0
    virtual void vfunc_oa0_13(void* a1);                            // 13 0x140aa6ee0
    virtual void vfunc_oa0_14(void* a1, int a2);                            // 14 0x140aa6e30
    virtual void vfunc_oa0_15(void* a1, int a2);                            // 15 0x140aa6e40
    virtual void vfunc_oa0_16(void* a1, int a2);                            // 16 0x140aa6dd0
    virtual void vfunc_oa0_17(void* a1, int a2);                            // 17 0x140aa6e10
    virtual void vfunc_oa0_18(void* a1, int a2);                            // 18 0x140aa6e20
    virtual void vfunc_oa0_19(void* a1, int a2);                            // 19 0x140aa6dc0
    virtual void vfunc_oa0_20(int a1);                            // 20 0x140aa6e80
    virtual void vfunc_oa0_21();                            // 21 0x140aa6eb0
    virtual void vfunc_oa0_22();                            // 22 0x140aa6f20
    virtual void vfunc_oa0_23();                            // 23 0x140aa6f10
    virtual void vfunc_oa0_24(int a1);                            // 24 0x140aa6f30
    virtual void vfunc_oa0_25(void* a1);                            // 25 0x140aa6f00
    virtual void vfunc_oa0_26(void* a1);                            // 26 0x140aa6ef0
    virtual void vfunc_oa0_27(int a1, int a2);                            // 27 0x140aa6e90
    virtual void vfunc_oa0_28();                            // 28 0x140aa6ea0
    virtual void vfunc_oa0_29();                            // 29 0x140aa6ec0
    virtual void vfunc_oa0_30(int a1);                            // 30 0x140aa6d50
    virtual void vfunc_oa0_31(void* a1);                            // 31 0x140aa6d60
};
MS2_CHECK_SIZE(UIStatusEventListener, 8);
