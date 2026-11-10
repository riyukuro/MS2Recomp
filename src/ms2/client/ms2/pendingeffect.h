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
#include <NiTransform.h>                  // C3: NiTransform (ctor 0x140a332d0, operator= 0x140a35c30)
#include "ms2/client/ms2/effectparam.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/placeholder/effectquery.h"   // C3: NoticeMessage, the real request/target

typedef MS2Ptr<CEffectParam> Unk_PeParamPtr;

// The effect group an effect id resolves to (effectservice). Only the param list at +0x28 and three accessors are known.
class Unk_PeEffectSet : public CPtred
{
public:
    ATL::CAtlList<Unk_PeParamPtr>& GetParams();         // the param list (+0x28)
    bool AreAllParamsReady();                                   // every param reports vfunc_3 (ready)
    void FUN_14119f710();                                   // vfunc_4 on each param that is not ready
};

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

class PendingEffect : public CPtred
{
public:
    explicit PendingEffect(int nId);                                    // 0x140a8f1d0
    virtual ~PendingEffect();                                           // 0x140a8f290, sdd 0x140a90270

    bool Init(MS2Ptr<Unk_PeEffectSet> spSet, const NoticeMessage& kTarget);   // 0x140a8f300
    bool Poll();                                                        // 0x140a8f440 timer elapsed and every param ready
    void CreateEffects(std::vector<CEffectPtr>& vOut);                  // 0x140a8f4a0 instantiate each param
    int GetId() const;                                                  // 0x140a8f5a0
    NoticeMessage& GetTarget();                                         // 0x140a8f5c0

    int m_nId;                                                          // +0x18
    MS2Ptr<Unk_PeEffectSet> m_spSet;                                    // +0x20
    NoticeMessage m_target;                                             // +0x30
    Unk_IntervalTimer m_tick;                                           // +0xa0 (C3: the real 50 ms timer)
    NiTransform m_xformA;                                               // +0xa8
    NiTransform m_xformB;                                               // +0xdc
    Unk_PePointArray m_points;                                          // +0x110
};
MS2_CHECK_SIZE(PendingEffect, 0x130);
MS2_CHECK_OFFSET(PendingEffect, m_target, 0x30);
MS2_CHECK_OFFSET(PendingEffect, m_xformB, 0xdc);
MS2_CHECK_OFFSET(PendingEffect, m_points, 0x110);
