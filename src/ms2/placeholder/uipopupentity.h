// uipopupentity.h - PLACEHOLDER for UIPopupEntity (RTTI .?AVUIPopupEntity@@, 0xd8 bytes), the base of the popup
// entities (UIEpProgress, ...). NOT an original header. Base UIObject (0x68). Primary vftable 0x142fd3268 (62 slots; the
// own virtuals are 1, 15, 20, 22, 41, 48 and the new slots 52-61), IMessageListener-in-UIObject table 0x142fd3460
// (inherited). Ctor 0x141a7caf0, dtor 0x141a7cc10 (??_G 0x141a7d410). Its unit is client\ms2\uipartydialog.cpp, which
// is not recovered yet: its members are declared here only (symbols-manual rows bind them to the exe).
//
// Ownership: created by w305 (2026-10-17); other agents may only append members and slots below the marked lines.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"

namespace efd { class Point3; }

// the popup's anchor position (3 floats, passed by pointer to a copy)
struct Unk_PopupPos
{
    Unk_PopupPos() {}                   // a user ctor keeps a local copy free of a /GS cookie
    Unk_PopupPos(const efd::Point3& kPt);   // 0x14027dcf0 (the shared NiPoint3-from-Point3 copy)
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_PopupPos, 0xc);

class Unk_PopupTarget;

// The object a popup entity is attached to (the pointer UIPopupEntity keeps at +0x68): a game object with at least 90
// virtual slots. Only slots 82 (the target's ui anchor, returned as a smart pointer) and 89 are known; the others are
// placeholders that keep the slot numbers.
class Unk_PopupOwner
{
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual MS2Ptr<Unk_PopupTarget> vfunc_82();                     // 82
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual float vfunc_89();                                       // 89
};

class UIPopupEntity : public UIObject
{
public:
    UIPopupEntity(Unk_PopupOwner* pOwner);                          // 0x141a7caf0
    virtual ~UIPopupEntity();                                       //  0 0x141a7cc10 (??_G 0x141a7d410)
    virtual CString vfunc_1();                                      //  1 0x141a7cca0
    virtual void vfunc_15();                                        // 15 0x141a7cdf0
    virtual void OnLoadInit();                                      // 20 0x141a7cd90 m_d0 = vfunc_48()
    virtual void OnLoadComplete();                                  // 22 0x141a7cdd0
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x141a7d3a0 m_30 = new ASGameEntity
    virtual int vfunc_48();                                         // 48 0x141a7d450
    virtual void vfunc_52();                                        // 52 0x141a7ccf0
    virtual void vfunc_53(Unk_PopupPos pos);                        // 53 0x141a7cf60 (empty)
    virtual void vfunc_54(int nMode);                               // 54 0x141a7cf80 start (timer)
    virtual void vfunc_55();                                        // 55 0x141a7cff0 stop
    virtual int vfunc_56();                                         // 56 0x141a7d080 m_84 (active)
    virtual int vfunc_57(int nForce);                               // 57 0x141a7d0c0
    virtual int vfunc_58();                                         // 58 0x141a7d1f0
    virtual float vfunc_59();                                       // 59 0x141a7d250 returns 0
    virtual Unk_PopupPos vfunc_60();                                // 60 0x141a7d260
    virtual float vfunc_61();                                       // 61 0x141a7d360
    // ---- agents: append non-virtual UIPopupEntity members below this line (sorted by address) ----
    void FUN_141a7d0a0();                                           // m_8c = 1 (ignore the range limit)
    void FUN_141a7d300();                                           // drop the owner's ui slot m_d0

protected:
    MS2_LAYOUT_FRIEND;
    Unk_PopupOwner* m_68;               // +0x68 owner (the object the popup hangs on)
    void* m_70;                         // +0x70 cached effect record of the owner (looked up by m_78)
    CString m_78;                       // +0x78 "Eff_UI"
    int m_80;
    int m_84;                           // active flag (vfunc_56)
    int m_88;
    int m_8c;
    int m_90;                           // timer period
    float m_94;                         // range limit (vfunc_58)
    Timer m_98;                         // +0x98
    int m_d0;                           // UI type id (set in OnLoadInit)
};
MS2_CHECK_SIZE(UIPopupEntity, 0xd8);
MS2_CHECK_OFFSET(UIPopupEntity, m_68, 0x68);
MS2_CHECK_OFFSET(UIPopupEntity, m_78, 0x78);
MS2_CHECK_OFFSET(UIPopupEntity, m_94, 0x94);
MS2_CHECK_OFFSET(UIPopupEntity, m_98, 0x98);
MS2_CHECK_OFFSET(UIPopupEntity, m_d0, 0xd0);
