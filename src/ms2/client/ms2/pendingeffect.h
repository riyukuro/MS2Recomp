// pendingeffect.h - PendingEffect (RTTI name): an effect request that is waiting for its resources. It owns the effect
// set it was created for (a list of CEffectParam, +0x20), a copy of the request/target (+0x30) with its own copies of the
// two transforms and the point array the target points at, and a 50 ms poll timer; Poll() says when every param is
// ready, FUN_140a8f4a0 then instantiates them. Header name assumed from the unit path. Member names are invented.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiSmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"      // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"     // Vector3 (NiPoint3 with out-of-line special members)
#include "ms2/client/ms2/effectparam.h"

typedef MS2Ptr<CEffectParam> Unk_PeParamPtr;

// The effect group an effect id resolves to (effectservice). Only the param list at +0x28 and three accessors are known.
class Unk_PeEffectSet : public CPtred
{
public:
    ATL::CAtlList<Unk_PeParamPtr>& FUN_14119f540();         // the param list (+0x28)
    bool FUN_14119f680();                                   // every param reports vfunc_3 (ready)
    void FUN_14119f710();                                   // vfunc_4 on each param that is not ready
};

// NiTransform (0x34 bytes: 3x3 rotation, translate, scale). Special members are out of line.
struct Unk_PeXform
{
    Unk_PeXform();                                          // 0x140a332d0
    Unk_PeXform& operator=(const Unk_PeXform& o);           // 0x140a35c30
    char m_pad_00[0x34];
};
MS2_CHECK_SIZE(Unk_PeXform, 0x34);

typedef ATL::CAtlArray<Vector3> Unk_PePointArray;

// 8-byte millisecond poll timer (ctor 0x140517b00; "elapsed since last hit" test 0x140268870).
struct Unk_PeTick
{
    Unk_PeTick();                                           // 0x140517b00
    int FUN_140268870(unsigned nInterval);
    unsigned m_nInterval;
    unsigned m_nLastTick;
};
MS2_CHECK_SIZE(Unk_PeTick, 8);

// The effect request/target the effects are created for: the full 0x70-byte object behind Unk_EffectTarget
// (effectparam.h declares only a partial view; a PendingEffect stores one by value). +0x18/+0x20/+0x28 point at
// transforms / a point array owned by the caller, which Init re-points at the PendingEffect's own copies.
struct Unk_PeTarget
{
    Unk_PeTarget();                                         // 0x140a52ef0
    ~Unk_PeTarget();                                        // 0x1405a89e0
    Unk_PeTarget& operator=(const Unk_PeTarget& o);         // 0x140a53260
    char m_pad_00[0x18];
    Unk_PeXform* m_pXformA;                                 // +0x18
    Unk_PeXform* m_pXformB;                                 // +0x20
    Unk_PePointArray* m_pPoints;                            // +0x28
    char m_pad_30[0x40];
};
MS2_CHECK_SIZE(Unk_PeTarget, 0x70);
MS2_CHECK_OFFSET(Unk_PeTarget, m_pXformA, 0x18);
MS2_CHECK_OFFSET(Unk_PeTarget, m_pPoints, 0x28);

class PendingEffect : public CPtred
{
public:
    explicit PendingEffect(int nId);                                    // 0x140a8f1d0
    virtual ~PendingEffect();                                           // 0x140a8f290, sdd 0x140a90270

    bool Init(MS2Ptr<Unk_PeEffectSet> spSet, const Unk_PeTarget& kTarget);   // 0x140a8f300
    bool Poll();                                                        // 0x140a8f440 timer elapsed and every param ready
    void CreateEffects(std::vector<CEffectPtr>& vOut);                  // 0x140a8f4a0 instantiate each param
    int GetId() const;                                                  // 0x140a8f5a0
    Unk_PeTarget& GetTarget();                                          // 0x140a8f5c0

    int m_nId;                                                          // +0x18
    MS2Ptr<Unk_PeEffectSet> m_spSet;                                    // +0x20
    Unk_PeTarget m_target;                                              // +0x30
    Unk_PeTick m_tick;                                                  // +0xa0
    Unk_PeXform m_xformA;                                               // +0xa8
    Unk_PeXform m_xformB;                                               // +0xdc
    Unk_PePointArray m_points;                                          // +0x110
};
MS2_CHECK_SIZE(PendingEffect, 0x130);
MS2_CHECK_OFFSET(PendingEffect, m_target, 0x30);
MS2_CHECK_OFFSET(PendingEffect, m_xformB, 0xdc);
MS2_CHECK_OFFSET(PendingEffect, m_points, 0x110);
