// unit_140ad5280.h - StateTreeWatering (actor state type 0x3e: watering a housing tree, m_n10 0xa0 / 0xa1 pick the
// kind of watering) and its payload StateTreeWateringData. NOT an original header (name assumed from the unit).
// The state shows the casting bar (UI 0x4e72) with ICastingEventListener at +0x40, plays the watering animation
// named in the payload and tells the server (packet 0xaa) when the casting finished.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

// 0x20. The watering animation name.
#ifndef MS2_STATETREEWATERINGDATA_DEFINED   // also defined by another header (w539: both may be included)
#define MS2_STATETREEWATERINGDATA_DEFINED
class StateTreeWateringData : public StateData
{
public:
    StateTreeWateringData(CString strAnim);                 // 0x140ad5280
    virtual ~StateTreeWateringData();                       // 0  0x140ad52f0 (??_G 0x140ad5d00)
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1  0x140ad5330
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2  0x140ad5380

    CString m_strAnim;                                      // +0x18
};
MS2_CHECK_SIZE(StateTreeWateringData, 0x20);
MS2_CHECK_OFFSET(StateTreeWateringData, m_strAnim, 0x18);
#endif

// 0x60.
class StateTreeWatering : public State, public ICastingEventListener
{
public:
    StateTreeWatering(PCBase* pOwner);                      // 0x140ad53d0
    virtual ~StateTreeWatering();                           // 0  0x140ad54c0 (??_G 0x140ad5cc0)
    virtual int vfunc_1();                                  // 1  0x140ad5de0: 0x3e
    virtual void vfunc_3(double fTime);                     // 3  0x140ad57b0
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ad5510
    virtual void vfunc_5(int n);                            // 5  0x140ad5830
    virtual void vfunc_6();                                 // 6  0x140ad5be0
    virtual void vfunc_7(int n);                            // 7  0x140ad5730
    virtual void vfunc_8(double fTime);                     // 8  0x140ad58a0
    virtual void vfunc_9(double fTime);                     // 9  0x140ad5a80
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140ad5d40: a new StateTreeWateringData
    virtual void OnCastingFinished();                       // listener 0  0x140ad5c30: m_n48 = 1

    int m_n48;                                              // +0x48 casting finished
    MS2Ptr<StateTreeWateringData> m_spWatering;             // +0x50
};
MS2_CHECK_SIZE(StateTreeWatering, 0x60);
MS2_CHECK_OFFSET(StateTreeWatering, m_n48, 0x48);
MS2_CHECK_OFFSET(StateTreeWatering, m_spWatering, 0x50);
