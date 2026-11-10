// statedatagrabtarget.h - StateDataGrabTarget (the grab state's payload, 0x28: the grabbed actor's id at +0x18 and the
// attach node's name at +0x20) and StateGrabTarget (actor state type 0x2b, 0x68): while grabbed the owner is pinned to
// a named node of the grabbing actor.
// MS2-UNIT: ?\statedatagrabtarget.cpp
// MS2-RANGE: 0x141024250-0x141024dc0 .text$mn
#pragma once

#include <afx.h>
#include <efd/Point3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/state.h"

class PCBase;

// The exe's dtor body is CString + StateData::~StateData with no vptr store, so it stays implicit:
// MS2-PIN: ??1StateDataGrabTarget@@UEAA@XZ 0x141024b10
class StateDataGrabTarget : public StateData
{
public:
    StateDataGrabTarget();                             // @0x141024250
    virtual void vfunc_1(Unk_StateDataArg* p);         // 1 @0x1410242a0
    virtual void vfunc_2(Unk_StateDataArg* p);         // 2 @0x141024300
    int m_nTarget;                                     // +0x18
    CString m_strNode;                                 // +0x20
};
MS2_CHECK_SIZE(StateDataGrabTarget, 0x28);
MS2_CHECK_OFFSET(StateDataGrabTarget, m_nTarget, 0x18);
MS2_CHECK_OFFSET(StateDataGrabTarget, m_strNode, 0x20);

class StateGrabTarget : public State
{
public:
    StateGrabTarget(PCBase* pOwner);                   // @0x141024360
    virtual ~StateGrabTarget();                        // @0x1410243f0
    virtual int vfunc_1();                             // 1  @0x141024c80: 0x2b
    virtual void vfunc_3(double fTime);                // 3  @0x141024680
    virtual void vfunc_4(StateData* pData);            // 4  @0x141024430
    virtual void vfunc_5(int n);                       // 5  @0x1410245e0
    virtual void vfunc_8(double fTime);                // 8  @0x141024940 (empty)
    virtual int vfunc_17();                            // 17 @0x141024a20: 0
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);    // 22 @0x1410249f0: 1
    virtual MS2Ptr<StateData> vfunc_27();              // 27 @0x141024960: a new StateDataGrabTarget
    int FUN_141024a30(int nTarget);                    // @0x141024a30: the payload names this grabbed actor
    efd::Point3 m_kPos;                                // +0x40 (the owner's position before the grab)
    efd::Point3 m_kDir;                                // +0x4c (the owner's direction before the grab)
    MS2Ptr<StateDataGrabTarget> m_spGrab;              // +0x58
};
MS2_CHECK_SIZE(StateGrabTarget, 0x68);
MS2_CHECK_OFFSET(StateGrabTarget, m_kPos, 0x40);
MS2_CHECK_OFFSET(StateGrabTarget, m_kDir, 0x4c);
MS2_CHECK_OFFSET(StateGrabTarget, m_spGrab, 0x58);
