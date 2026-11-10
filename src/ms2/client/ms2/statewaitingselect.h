// statewaitingselect.h - StateWaitingSelect (type 0xe): the actor state of a player in the character / equipment
// select screen (plays the "Equip_Change_<slot>_A" animation of the part being changed). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statewaitingselect.cpp` (0x1417fea70-0x1417ff730 .text$mn,
// dir client\ms2). Header name assumed. State::m_n10 is the sub state: 0x4c cap, 0x4d idle, 0x4e body, 0x4f head,
// 0x50 hair, 0x51 glove, 0x52 mantle, 0x53 shoes, 0x54 skill, 0x55 end.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

class NiActorManager;
class NiControllerSequence;

// 0x40 (no members of its own).
class StateWaitingSelect : public State
{
public:
    StateWaitingSelect(PCBase* pOwner);                     // 0x1417fea70
    virtual ~StateWaitingSelect();                          // 0x1417feab0 (??_G 0x1417ff6e0)
    virtual int vfunc_1();                                  // 1  0x1417ff720: 0xe
    virtual void vfunc_2(int n);                            // 2  0x1417feae0 (pick the sub state and play its animation)
    virtual void vfunc_3(double fTime);                     // 3  0x1417ff3f0
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417ff2e0 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417ff370 (leave)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417ff470 (an animation ended: back to idle)
    virtual int vfunc_15();                                 // 15 0x1417ff6c0: m_n10 == 0x55

    void PlayPartChangeAnimation(int* pnSub, const CString& strAnim); // switch to a part-change animation of the model's own name
};
MS2_CHECK_SIZE(StateWaitingSelect, 0x40);
