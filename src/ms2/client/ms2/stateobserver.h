// stateobserver.h - StateObserver (state type 0x3f), the spectator state that follows another player, and its
// StateObserverData payload. NOT an original header (name assumed from the unit client\ms2\stateobserver.cpp).
// Derives State / StateData (ms2/placeholder/state.h). Member names invented from their use.
#pragma once
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"

class NotifyObject;
class CProxyGameObject;
class StateSyncObject;

// 0x20. +0x18 id of the observed player (written into the sync record's string at +0x70). vftable: dtor 0x140ac5a00,
// ??_G 0x140ac5c40, vfunc_1 0x140ac3b90, vfunc_2 0x140ac3c10.
class StateObserverData : public StateData
{
public:
    StateObserverData(__int64 nTarget);                     // 0x140ac3b40
    ~StateObserverData() = default;                         // 0x140ac5a00
    virtual void vfunc_1(Unk_StateDataArg* p);              // 0x140ac3b90
    virtual void vfunc_2(Unk_StateDataArg* p);              // 0x140ac3c10

    __int64 m_nTarget;                                      // +0x18
};
MS2_CHECK_SIZE(StateObserverData, 0x20);

// 0x60. vftable: ??_G 0x140ac5c00, dtor 0x140ac3d20.
class StateObserver : public State
{
public:
    StateObserver(PCBase* pOwner);                          // 0x140ac3c60
    ~StateObserver();                                       // 0x140ac3d20
    int vfunc_1();                                          // 0x140ac5e90: 0x3f
    void vfunc_3(double fTime);                             // 0x140ac3f50
    void vfunc_4(StateData* pData);                         // 0x140ac3d60
    void vfunc_5(int n);                                    // 0x140ac3ed0
    void vfunc_8(double fTime);                             // 0x140ac3ff0
    int vfunc_22(MS2Ptr<StateSyncObject> p);                 // 0x140ac4040
    MS2Ptr<StateData> vfunc_27();                           // 0x140ac5c80
    bool vfunc_28(MS2Ptr<StateSyncObject> p);                // 0x140ac40f0

    CStringW GetTargetName();                               // the observed player's name
    void ObservePrevious();                                   // observe the previous candidate
    void ObserveNext();                                   // observe the next candidate
    void ObserveOther();                                   // observe the nearest candidate other than the current one
    void FUN_140ac45e0();                                   // enter: hide the HUD, register the kill notice
    void FUN_140ac4760();                                   // leave: restore the HUD, unregister the kill notice
    void FUN_140ac48e0();                                   // follow the observed player's position
    void FUN_140ac4c00();                                   // flush the pending target
    void FUN_140ac4c90(__int64 nTarget);                 // ask the server to observe nTarget (throttled)
    void FUN_140ac4dc0(NotifyObject* pNotice);              // NotifyKillPlayer
    __int64 GetObservedTargetId();                                // the observed player's id

    MS2Ptr<StateObserverData> m_spObserve;                  // +0x40
    int m_nSwitchTick;                                      // +0x50
    int m_pad_54;
    __int64 m_nPending;                                     // +0x58
};
MS2_CHECK_SIZE(StateObserver, 0x60);
MS2_CHECK_OFFSET(StateObserver, m_spObserve, 0x40);
MS2_CHECK_OFFSET(StateObserver, m_nPending, 0x58);
