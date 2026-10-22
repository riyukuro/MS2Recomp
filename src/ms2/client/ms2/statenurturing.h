// statenurturing.h - the housing-cube pet/plant actor states: StateNurturing (feeding / playing / gifting a nurturing cube,
// type 0x40), StateIdleSpawnObject (type 1) and StateInterActionSpawnObject (type 0x19) of a CubeSpawnObject. NOT an original
// header (name assumed from the unit client\ms2\statenurturing.cpp). All derive State (ms2/placeholder/state.h).
#pragma once
#include <vector>

#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/unnamed/unit_140ad1860.h"    // Unk_McTimer

class CNurturingCubeObject;
class CubeSpawnObject;
struct Unk_CastInfo;     // casting bar request (0x38)

// 0x78. The player's nurturing-cube interaction (gift 0xa7, feed 0xa5, play 0xa6): picks the nearest usable cube, shows the
// casting bar and tells the server which cubes were used. The ICastingEventListener at +0x40 is the casting bar's callback.
class StateNurturing : public State, public ICastingEventListener
{
public:
    StateNurturing(PCBase* pOwner);                         // 0x140ac08e0
    virtual ~StateNurturing();                              // 0x140ac0980 (??_G 0x140ac31d0)
    virtual int vfunc_1();                                  // 1  0x140ac3230: 0x40
    virtual void vfunc_3(double fTime);                     // 3  0x140ac10c0
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ac09e0
    virtual void vfunc_5(int n);                            // 5  0x140ac0f80
    virtual void vfunc_7(int n);                            // 7  0x140ac0f10
    virtual void vfunc_8(double fTime);                     // 8  0x140ac11c0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140ac12c0
    virtual void OnCastingFinished();                       // listener 0  0x140ac12a0: m_n48 = 1

    unsigned FUN_140ac1370();                               // NurturingDuration
    efd::utf8string FUN_140ac13a0();                        // the action animation of m_n10
    void FUN_140ac1480(Unk_CastInfo* pInfo);                // fill the casting bar request
    MS2Ptr<CNurturingCubeObject> FUN_140ac1650();           // nearest usable cube in reach (null when none)
    void SendFunctionCubeMode4();                                   // send the used cubes (kind 4)
    void SendFunctionCubeMode5();                                   // send the cubes the player may use (kind 5)

    int m_n48;                                              // +0x48 casting finished
    MS2Ptr<CNurturingCubeObject> m_spTarget;                // +0x50 nearest usable cube
    std::vector<MS2Ptr<CNurturingCubeObject> > m_aCubes;    // +0x60 usable cubes in reach
};
MS2_CHECK_SIZE(StateNurturing, 0x78);
MS2_CHECK_OFFSET(StateNurturing, m_n48, 0x48);
MS2_CHECK_OFFSET(StateNurturing, m_spTarget, 0x50);
MS2_CHECK_OFFSET(StateNurturing, m_aCubes, 0x60);

// 0x40. The interaction animation of a cube pet (type 0x19).
class StateInterActionSpawnObject : public State
{
public:
    StateInterActionSpawnObject(CubeSpawnObject* pOwner);   // 0x140ac1c30
    virtual ~StateInterActionSpawnObject();                 // 0x140ac1c70 (??_G 0x140ac3190)
    virtual int vfunc_1();                                  // 1  0x140ac3220: 0x19
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ac1ca0
    virtual void vfunc_5(int n);                            // 5  0x140ac1d40

    CubeSpawnObject* FUN_140ac1de0();                       // the owner as a CubeSpawnObject
};
MS2_CHECK_SIZE(StateInterActionSpawnObject, 0x40);

// 0x48. The idle behaviour of a cube pet (type 1): idle -> sleeping -> ... by the 60 s timer.
class StateIdleSpawnObject : public State
{
public:
    StateIdleSpawnObject(CubeSpawnObject* pOwner);          // 0x140ac1e20
    virtual ~StateIdleSpawnObject();                        // 0x140ac1e90 (??_G 0x140ac3150)
    virtual int vfunc_1();                                  // 1  0x140ac3210: 1
    virtual void vfunc_2(int n);                            // 2  0x140ac1ec0
    virtual void vfunc_3(double fTime);                     // 3  0x140ac2050
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ac1f30
    virtual void vfunc_5(int n);                            // 5  0x140ac2020
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140ac21a0

    CubeSpawnObject* FUN_140ac21e0();                       // the owner as a CubeSpawnObject

    Unk_McTimer m_timer;                                    // +0x40
};
MS2_CHECK_SIZE(StateIdleSpawnObject, 0x48);
MS2_CHECK_OFFSET(StateIdleSpawnObject, m_timer, 0x40);
