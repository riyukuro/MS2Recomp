// equipmodel.h - CEquipModel: abstract base of the client's loaded models (CNifModel 0x128, CKfmModel 0x140 which
// adds NiActorManager::CallbackObject at +0x118). CPtred-based (intrusive refcount, held by MS2Ptr<T>).
// Owning unit: ?\equipmodel.cpp (0x1411ffa10-0x141209610, 247 funcs; dir client\ms2). Header name assumed.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class CNifModel : public CEquipModel` and override by copying the exact declaration. Slots 4, 6-16, 18, 19 are
//   pure (_purecall) - implement all of them in a concrete model. vfunc_N = slot N of vftable 0x142ec0ef8 (33).
// - Slots 1-3 are efd RTTI (EE_BEGIN_DECLARE_CLASS: GetClassDesc + TypeCast(const void**) + TypeCast(void**),
//   ms_ClassInfo.TypeCast = 0x1409f31d0). Derived models declare EE_DECLARE_CLASS1(X, <id>, CEquipModel)
//   (CNifModel 0x06200049, ms_ClassInfo 0x143ae2440) and bind ?ms_ClassInfo@X@@2VClassInfo@efd@@B in
//   progress/symbols-manual.tsv.
// - Signatures were taken from CEquipModel, CNifModel and CKfmModel bodies; void* params are unproven pointer types.
// - CEquipModel is heap-only (array stand-ins are fine).
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <afx.h>
#include <efd/ClassInfo.h>
#include <NiPoint3.h>
#include <NiNode.h>
#include <NiSmartPointer.h>
#include <atlcoll.h>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"

// Key of CEquipModel::m_effects (passed by const& through CElementTraits, so not a primitive int; 4 bytes).
enum Unk_EquipEffectSlot { };
class Unk_EquipModelOwner;     // MS2Ptr<T> at +0x28 (copy ctor 0x140884f30, dtor 0x1405a85f0, get 0x1405a8ed0)

// 0x118 bytes. vftable 0x142ec0ef8 (33 slots), ??_G 0x1412058b0.
class CEquipModel : public CPtred
{
public:
    CEquipModel(MS2Ptr<Unk_EquipModelOwner> spOwner, void* p18, void* p20);   // 0x1411ffa10
    virtual ~CEquipModel();                                                    // 0x1411ffcb0

    // slots 1-3: GetClassDesc 0x141205e10, TypeCast 0x141208280 / 0x1412082d0; ms_ClassInfo 0x143ad2360,
    // SetupClassInfo 0x141208010 (no parents).
    EE_DECLARE_CLASS(CEquipModel, 0x06200048);
public:
    virtual int vfunc_4(CString strPath) = 0;               // 4  pure, strPath BY VALUE (callee destroys it; CNifModel 0x141565700: load)
    virtual void vfunc_5();                                 // 5  0x1411ffdd0 (unload: detach + reset +0x28/+0xf0)
    virtual int vfunc_6() = 0;                              // 6  pure (CNifModel: m_nState = 1, calls 10, 11; returns 1)
    virtual int vfunc_7() = 0;                              // 7  pure (CNifModel: returns 1)
    virtual int vfunc_8() = 0;                              // 8  pure (CNifModel: 0)
    virtual int vfunc_9() = 0;                              // 9  pure (CNifModel: return m_nState)
    virtual void vfunc_10() = 0;                            // 10 pure
    virtual void vfunc_11() = 0;                            // 11 pure
    virtual void vfunc_12() = 0;                            // 12 pure
    virtual void vfunc_13() = 0;                            // 13 pure
    virtual void* vfunc_14() = 0;                           // 14 pure (CNifModel: returns &m_unk_f0's pointee, FUN_1409849b0(&m_unk_f0))
    virtual int vfunc_15() = 0;                             // 15 pure
    virtual void vfunc_16() = 0;                            // 16 pure
    virtual void vfunc_17();                                // 17 0x1411ffe70
    virtual void vfunc_18() = 0;                            // 18 pure
    virtual void vfunc_19(double fTime) = 0;                // 19 pure (update)
    virtual int vfunc_20();                                 // 20 0x1411fff90 (+0xc0 list test; bool result zero-extended)
    virtual float vfunc_21();                               // 21 0x1411fffc0 return m_fScale44
    virtual void vfunc_22(float f);                         // 22 0x1411fffe0 m_fScale44 = f
    virtual NiPoint3 vfunc_23();                            // 23 0x141200010 return m_pos48
    virtual void vfunc_24(const NiPoint3& p);               // 24 0x141200040 m_pos48 = p
    virtual NiPoint3 vfunc_25();                            // 25 0x141200070 return m_pos54
    virtual void vfunc_26(const NiPoint3& p);               // 26 0x1412000a0 m_pos54 = p
    virtual void vfunc_27(const char* psz);                 // 27 0x141200190 (ICF-folded, symbolised OnStatusTextChange)
    virtual void vfunc_28(void* a, void* b, float f);       // 28 0x1412001f0 (empty)
    virtual void vfunc_29(void* a, void* b, float f);       // 29 0x1412001d0 (empty)
    virtual void vfunc_30(void* a, void* b, float f);       // 30 0x141200210 (empty)
    virtual void vfunc_31();                                // 31 0x141200b20 (empty)
    virtual void vfunc_32(int n);                           // 32 0x141201750 (calls 0x141202bd0)

    NiPoint3 GetPos6c();                               // 0x1412000d0 return m_pos6c
    NiPoint3 FUN_141200130();                               // 0x141200130 return m_pos60
    CString FUN_1412028f0();                                // 0x1412028f0 return m_str38

public:
    MS2_LAYOUT_FRIEND;
    void* m_unk_18;                                 // +0x18 ctor arg 2
    void* m_unk_20;                                 // +0x20 ctor arg 3
    MS2Ptr<Unk_EquipModelOwner> m_spOwner;          // +0x28
    CString m_str38;                                // +0x38 = ""
    int m_nState;                                   // +0x40 (CNifModel vfunc_6 sets 1, vfunc_9 returns it)
    float m_fScale44;                               // +0x44 = 1.0
    NiPoint3 m_pos48;                               // +0x48 = ZERO
    NiPoint3 m_pos54;                               // +0x54 = ZERO
    NiPoint3 m_pos60;                               // +0x60 = ZERO
    NiPoint3 m_pos6c;                               // +0x6c = ZERO
    // +0x78 effect slot -> effect-manager handle (Unk_1403ed280: 0x1411a49c0 creates, 0x1411a6060 releases).
    // CAtlMap(17, .75f, .25f, 2.25f, 10) ctor 0x141205050, dtor 0x141205440, Lookup 0x141206610 (node: key +0,
    // value +4), operator[]-style SetAt 0x141207d30, RemoveKey 0x141207a40.
    ATL::CAtlMap<Unk_EquipEffectSlot, int> m_map78;
    // +0xc0 name -> flag. CRBMap(10) ctor 0x141205140, dtor 0x141205470; Find 0x141205a80 compares with
    // CDefaultCompareTraits<CString> 0x1401c0630; Lookup 0x1412066a0 (value +8), SetAt 0x141207dc0.
    ATL::CRBMap<CString, int> m_listC0;
    NiAVObjectPtr m_unk_f0;                         // +0xf0 loaded scene root (SmartPointer<NiAVObject> ctor 0x14097eba0, dtor 0x1405a85c0)
    // +0xf8 std::set<NiAVObjectPtr> (_Tree, 0x28-byte nodes, value +0x20): ctor 0x141205320, dtor 0x141205530,
    // clear 0x141209260, begin 0x141209190, insert 0x141205000 (filled by 0x141422110).
    std::set<NiAVObjectPtr> m_unk_f8;
    NiNodePtr m_spNode;                             // +0x108 (NiPointer ctor 0x1409f7170, dtor 0x1409f74b0)
    bool m_b110;                                    // +0x110
    bool m_b111;                                    // +0x111
};
MS2_CHECK_SIZE(CEquipModel, 0x118);
MS2_CHECK_OFFSET(CEquipModel, m_unk_18, 0x18);
MS2_CHECK_OFFSET(CEquipModel, m_spOwner, 0x28);
MS2_CHECK_OFFSET(CEquipModel, m_str38, 0x38);
MS2_CHECK_OFFSET(CEquipModel, m_nState, 0x40);
MS2_CHECK_OFFSET(CEquipModel, m_fScale44, 0x44);
MS2_CHECK_OFFSET(CEquipModel, m_pos6c, 0x6c);
MS2_CHECK_OFFSET(CEquipModel, m_map78, 0x78);
MS2_CHECK_OFFSET(CEquipModel, m_listC0, 0xc0);
MS2_CHECK_OFFSET(CEquipModel, m_unk_f0, 0xf0);
MS2_CHECK_OFFSET(CEquipModel, m_unk_f8, 0xf8);
MS2_CHECK_OFFSET(CEquipModel, m_spNode, 0x108);
MS2_CHECK_OFFSET(CEquipModel, m_b111, 0x111);
