// stateusefurnituredata.h - StateUseFurniture (type 0x29): the actor state of a player sitting / lying on a housing
// furniture cube (a CFunctionCubeObject with an interaction animation), and its payload StateUseFurnitureData (the
// cube's key). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\stateusefurnituredata.cpp`
// (0x141282a50-0x141284ac0 .text$mn, dir client\ms2). Header name assumed; member names invented from their use.
// Derives State / StateData (ms2/placeholder/state.h).
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"

class CFunctionCubeObject;

// 0x20. The exe's dtor body is ~CString then ~StateData with no vptr store, so it stays implicit:
// MS2-PIN: ??1StateUseFurnitureData@@UEAA@XZ 0x141284730
// The key of the furniture cube; slots 1 / 2 mirror it into / out of the state-sync record (+0x70).
class StateUseFurnitureData : public StateData
{
public:
    StateUseFurnitureData();                                // 0x141282a50
    StateUseFurnitureData(CString strKey);                  // 0x141282aa0
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1 0x141282b10
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2 0x141282b60

    CString m_strKey;                                       // +0x18
};
MS2_CHECK_SIZE(StateUseFurnitureData, 0x20);
MS2_CHECK_OFFSET(StateUseFurnitureData, m_strKey, 0x18);

// 0x78. m_spCube is the furniture cube object being used; m_n64 is set once its sit animation started; m_nEffect is the
// effect id of the cube's effect; m_vPos is the position the player stood at before sitting (restored on leaving).
class StateUseFurniture : public State
{
public:
    StateUseFurniture(PCBase* pOwner);                      // 0x141282bb0
    virtual ~StateUseFurniture();                           // 0x141282c50 (??_G 0x1412848a0)
    virtual int vfunc_1();                                  // 1  0x1412849a0: 0x29
    virtual void vfunc_3(double fTime);                     // 3  0x141283340 (move onto the cube's seat node)
    virtual void vfunc_4(StateData* pData);                 // 4  0x141282ca0 (enter)
    virtual void vfunc_5(int n);                            // 5  0x141284050 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x141283d80 (stand up on buffs)
    virtual void AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 11 0x141284470
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x141284920: an empty StateUseFurnitureData

    CString FUN_141284620();                                // the key of the furniture (empty without data)

    MS2Ptr<CFunctionCubeObject> m_spCube;                   // +0x40
    MS2Ptr<StateUseFurnitureData> m_spFurniture;            // +0x50
    int m_nEffect;                                          // +0x60
    int m_n64;                                              // +0x64
    Vector3 m_vPos;                                 // +0x68
};
MS2_CHECK_SIZE(StateUseFurniture, 0x78);
MS2_CHECK_OFFSET(StateUseFurniture, m_spCube, 0x40);
MS2_CHECK_OFFSET(StateUseFurniture, m_spFurniture, 0x50);
MS2_CHECK_OFFSET(StateUseFurniture, m_nEffect, 0x60);
MS2_CHECK_OFFSET(StateUseFurniture, m_vPos, 0x68);
