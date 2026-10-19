// effectparam.h - CEffectParam: CPtred-based base of the ~28 effect parameter classes parsed from the effect XML
// (CPostEffectParam, CNifEffectParam, CSoundEventEffectParam, TransitionEffectParam ...). Owning unit:
// client\ms2\effectservice.cpp (0x14119e920-0x1411b8510, 873 funcs). Header name assumed.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class XEffectParam : public CEffectParam` (or CPostEffectParam, posteffectparam.h); copy the exact virtual
//   declarations to override. vfunc_N = slot N of vftable 0x142eba118 (8 slots, ??_G 0x1411a1db0).
// - The dtor is inline: its only COMDAT (0x140987960) was emitted by the first unit that destroyed a param
//   (unit_140987430, CAfterImageEffectParam), not by effectservice.
// - vfunc_6 creates the runtime effect object; it returns NiPointer<CEffect> (8 bytes, hidden return pointer;
//   NiPointer(T*) COMDAT 0x1409878c0). CEffect (the runtime effect, NiRefObject-based, 13 slots) is declared below.
// - The XML node type is the game's TinyXML element (Unk_140165cf0, see commonfiles/fielddata.h).
#pragma once
#include <afx.h>
#include <NiRefObject.h>
#include <NiRTTI.h>
#include <NiSmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"

class Unk_140165cf0;     // game TinyXML element
class NiAVObject;
class NiTransform;
// Effect owner/target context passed to CEffectParam::vfunc_7 and CEffect::vfunc_3 (getters 0x140a53110/53010/53050/
// 53420). 0x70 bytes; only the fields read directly by recovered code are named (CEffectService::OnTick builds one).
class Unk_EffectTarget
{
public:
    Unk_EffectTarget();             // 0x140a52ef0 (0x70 bytes)
    ~Unk_EffectTarget();            // 0x1405a89e0
    CString m_strName;              // +0x00 the effect file name
    int m_nKind;                    // +0x08 (CPostEffectParam::vfunc_7: 3 passes; copied to CEffect +0x18)
    int m_unk_0c;
    NiPointer<NiAVObject> m_spObject;   // +0x10 the node the effect is attached to (effectservice: skip position)
    NiTransform* m_pXform;          // +0x18 world transform when there is no node (caller owned)
    void* m_unk_20;
    void* m_unk_28;
    bool m_b30;                     // +0x30 effectservice: Unk_SkipCheck::m_n14
    bool m_b31;                     // +0x31
    bool m_b32;
    bool m_b33;
    bool m_b34;                     // +0x34 copied to CEffect::m_b2f
    bool m_b35;
    bool m_b36;
    bool m_b37;
    int m_unk_38;
    int m_unk_3c;
    Delegate<void(unsigned int, CString, bool)> m_dgInserted;  // +0x40 called with the effect id once the effects exist
    int m_unk_48;
    unsigned int m_nRandomIndex;    // +0x4c CRandomEffect: forced child index (mod count); 0 = weighted random
    void* m_unk_50;
    void* m_unk_58;
    void* m_unk_60;
    void* m_unk_68;

    void FUN_140a53190(int nObjectId);  // 0x140a53190 set the owner object id
    class GameObject* FUN_140a533b0();  // 0x140a533b0 return the GameObject* at +0x58 (the effect's owner actor)
    // ?\unit_140a52ef0.cpp getters (owner = the GameObject at +0x58; 2 = "any" for gender/job).
    int FUN_140a53010();            // 0x140a53010 owner gender
    int FUN_140a53050();            // 0x140a53050 owner job code
    int FUN_140a53090();            // 0x140a53090 owner object id
    bool FUN_140a530d0();           // 0x140a530d0 the target is the local player
    bool FUN_140a53110();           // 0x140a53110 the owner is optimized out (hidden)
    double FUN_140a53420();         // 0x140a53420 start time (+0x68), 0 = now
    void FUN_140a534a0();           // 0x140a534a0 resolve the owner by id and its scene node
    void FUN_140a53550();           // 0x140a53550 start time (+0x68) = now
    void FUN_140a53170(int nId);    // 0x140a53170 +0x50 = nId
    void FUN_140a531b0(int nId);    // 0x140a531b0 the lookup id (NoticeMessage::SetLookupId, placeholder/effectquery.h)
    Delegate<void(unsigned int, CString, bool)>& FUN_140a53460();  // 0x140a53460 the inserted callback (+0x40)
};
MS2_CHECK_OFFSET(Unk_EffectTarget, m_nKind, 0x08);
MS2_CHECK_OFFSET(Unk_EffectTarget, m_spObject, 0x10);
MS2_CHECK_OFFSET(Unk_EffectTarget, m_b30, 0x30);
MS2_CHECK_OFFSET(Unk_EffectTarget, m_b34, 0x34);
MS2_CHECK_OFFSET(Unk_EffectTarget, m_dgInserted, 0x40);
MS2_CHECK_OFFSET(Unk_EffectTarget, m_nRandomIndex, 0x4c);
MS2_CHECK_SIZE(Unk_EffectTarget, 0x70);

class CEffectParam;

// 0x30 bytes. Runtime effect base (CPostEffect 0x38 etc.). vftable 0x142eb9a50 (13 slots): slot 0 is _purecall
// (pure virtual destructor; dtor body 0x14119eaa0), slot 1 NiRefObject::DeleteThis, 12 pure.
class CEffect : public NiRefObject
{
public:
    CEffect();                                      // 0x14119ea10
    virtual ~CEffect() = 0;                         // 0x14119eaa0

    // slot 2: GetRTTI 0x14119f4a0. Root NiRTTI "CEffect" at 0x143ad1568 (built by the effectservice static init;
    // every concrete effect does NiImplementRTTI(X, CEffect) -> NiDeclareRTTI in the derived class).
    NiDeclareRTTI;
public:
    // 3 0x14119f0b0 init from the param: m_unk_18 = pTarget->m_nKind, m_b2f = pTarget->m_b34,
    // m_dStartTime = time + startDelay, m_fDuration, m_bLoop (param +0x30), m_str10 = param m_str20; returns true.
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);
    virtual void vfunc_4();                         // 4  0x14119f190
    virtual void vfunc_5();                         // 5  0x14119f1b0
    virtual void vfunc_6(float f);                  // 6  0x14119f1d0 calls vfunc_5
    virtual void vfunc_7();                         // 7  0x14119f200
    virtual int vfunc_8(void* p);                   // 8  0x14119f220 return 0
    virtual bool vfunc_9();                         // 9  0x14119f240
    virtual void vfunc_10(bool b);                  // 10 0x14119f2f0 {}
    virtual int vfunc_11();                         // 11 0x14119f300 return !m_b2c
    virtual int vfunc_12() = 0;                     // 12 pure (CPostEffect 0x140dbdc80: return +0x30)
    // @0x140985010
    int GetKind() const { return m_unk_18; }
    CString GetName() const;                        // 0x14119f330
    float GetDuration() const;                      // 0x14119f380
    double GetStartTime() const;                    // 0x14119f3a0
    bool FUN_14119f3c0() const;                     // 0x14119f3c0 started (vfunc_4 ran)
    bool IsLoop() const;                            // 0x14119f3e0
    bool FUN_14119f400() const;                     // 0x14119f400

public:
    MS2_LAYOUT_FRIEND;
    CString m_str10;                // +0x10
    int m_unk_18;                   // +0x18 pTarget->m_nKind
    double m_dStartTime;            // +0x20
    float m_fDuration;              // +0x28 param m_fDuration
    bool m_b2c;                     // +0x2c param m_b30 (loop?)
    bool m_b2d;                     // +0x2d
    bool m_b2e;                     // +0x2e
    bool m_b2f;                     // +0x2f = 1
};
MS2_CHECK_SIZE(CEffect, 0x30);
MS2_CHECK_OFFSET(CEffect, m_str10, 0x10);
MS2_CHECK_OFFSET(CEffect, m_dStartTime, 0x20);
MS2_CHECK_OFFSET(CEffect, m_fDuration, 0x28);
MS2_CHECK_OFFSET(CEffect, m_b2f, 0x2f);
typedef NiPointer<CEffect> CEffectPtr;

// 0x48 bytes.
class CEffectParam : public CPtred
{
public:
    explicit CEffectParam(int nType);                       // 0x1411a01d0
    virtual ~CEffectParam() = default;                      // 0x140987960 (inline, no vptr store), ??_G 0x1411a1db0

    virtual void vfunc_1(Unk_140165cf0* pNode);             // 1 0x1411a0290 load startDelay/duration/lodSkipLevel/.../ignoreOptimize
    virtual bool vfunc_2();                                 // 2 0x1411a03d0 validate (warns for types 4,7-10,12,15 with no duration)
    virtual bool vfunc_3();                                 // 3 0x14119e920 return true
    virtual void vfunc_4();                                 // 4 0x14119e930 {}
    virtual bool vfunc_5(int n);                            // 5 0x1411a0480 return true
    virtual CEffectPtr vfunc_6();                           // 6 0x1411a04a0 base: null
    virtual bool vfunc_7(Unk_EffectTarget* p);              // 7 0x14119e940 filter: skip for this target?

public:
    MS2_LAYOUT_FRIEND;
    int m_nType;                    // +0x18 ctor arg
    CString m_str20;                // +0x20 (used in the vfunc_2 warning)
    float m_fStartDelay;            // +0x28 "startDelay"
    float m_fDuration;              // +0x2c "duration"
    bool m_b30;                     // +0x30 attribute name at 0x142eb9ee0
    bool m_bOffSkip;                // +0x31 "offSkip"
    bool m_bOnlyCasterMyPC;         // +0x32 "onlyCasterMyPC"
    bool m_bOnlyTargetMyPC;         // +0x33 "onlyTargetMyPC"
    int m_nLodSkipLevel;            // +0x34 "lodSkipLevel"
    int m_nGender;                  // +0x38 "gender" (= 2: any)
    int m_nJobCode;                 // +0x3c "jobCode"
    bool m_bIgnoreOptimize;         // +0x40 "ignoreOptimize"
};
MS2_CHECK_SIZE(CEffectParam, 0x48);
MS2_CHECK_OFFSET(CEffectParam, m_nType, 0x18);
MS2_CHECK_OFFSET(CEffectParam, m_str20, 0x20);
MS2_CHECK_OFFSET(CEffectParam, m_fDuration, 0x2c);
MS2_CHECK_OFFSET(CEffectParam, m_bOnlyTargetMyPC, 0x33);
MS2_CHECK_OFFSET(CEffectParam, m_nGender, 0x38);
MS2_CHECK_OFFSET(CEffectParam, m_bIgnoreOptimize, 0x40);
