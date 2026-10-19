// uiitemeventlistener.h - UIItemEventListener: the 8-byte (vftable only) interface that UI classes derive from to receive
// item events (TradeSlotBag, inventory slot bags, ...). Ctor 0x1419cad20, dtor 0x1419cad40 (virtual, sets the base
// vftable 0x142fba630), 35 slots. Registered with a game-system singleton (FUN_140a6a840) in the derived ctors.
// Slot 1 is out of line (0x1419cad60, return 1); slots 2-34 are the empty inline stubs at 0x140be53b0-0x140be95e0
// (void return; signatures from the /Od parameter homing: pointer / int / bool).
// Derived classes bind the base ctor/dtor/vfunc_1 through progress/symbols-manual.tsv.
#pragma once

class UIItemEventListener
{
public:
    UIItemEventListener();                          // 0x1419cad20
    virtual ~UIItemEventListener();                 // 0x1419cad40 (scalar deleting 0x1419cc570)

    virtual int vfunc_il1();                         // 1  0x1419cad60 return 1
    virtual void vfunc_2(void*) {}                  // 2  0x140be5490
    virtual void vfunc_3(void*, bool) {}            // 3  0x140c255d0
    virtual void vfunc_4(void*, int) {}             // 4  0x140be54a0
    virtual void vfunc_5(void*, int) {}             // 5  0x140be54b0
    virtual void vfunc_il6(void*) {}                // 6  0x140be54c0
    virtual void vfunc_il7(void*) {}                // 7  0x140be54e0
    virtual void vfunc_il8(void*) {}                // 8  0x140be54d0
    virtual void vfunc_9(void*) {}                  // 9  0x140be54f0
    virtual void vfunc_10(void*) {}                 // 10 0x140be5520
    virtual void vfunc_il11(void*) {}               // 11 0x140be5510
    virtual void vfunc_12() {}                      // 12 0x140be5530
    virtual void vfunc_il13() {}                     // 13 0x140be5500
    virtual void vfunc_14(void*) {}                 // 14 0x140be5570
    virtual void vfunc_15(void*) {}                 // 15 0x140be55a0
    virtual void vfunc_16(void*) {}                 // 16 0x140be5580
    virtual void vfunc_17(void*, int) {}            // 17 0x140be5590
    virtual void vfunc_18(void*) {}                 // 18 0x140be5540
    virtual void vfunc_19(void*) {}                 // 19 0x140be5560
    virtual void vfunc_20(void*) {}                 // 20 0x140be5550
    virtual void vfunc_21(void*) {}                 // 21 0x140be95e0
    virtual void vfunc_22(void*) {}                 // 22 0x140be5420
    virtual void vfunc_23(void*) {}                 // 23 0x140be5440
    virtual void vfunc_24(void*) {}                 // 24 0x140be5410
    virtual void vfunc_25(void*) {}                 // 25 0x140be5430
    virtual void vfunc_26(int) {}                   // 26 0x140be53e0
    virtual void vfunc_27(int) {}                   // 27 0x140be53f0
    virtual void vfunc_28(void*) {}                 // 28 0x140be53d0
    virtual void vfunc_29(void*) {}                 // 29 0x140be53c0
    virtual void vfunc_30(void*) {}                 // 30 0x140be5480
    virtual void vfunc_31(void*) {}                 // 31 0x140be5470
    virtual void vfunc_32(void*, int, int) {}       // 32 0x140be5450
    virtual void vfunc_33(int, int) {}              // 33 0x140be53b0
    virtual void vfunc_34() {}                      // 34 0x140be5400
};
