// stateglide.h - StateGlide (type 0x1e): the actor state of a player gliding (a move skill that falls with a
// glide animation, drifts forward along the skill row's curves and plays a looping effect). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\stateglide.cpp` (0x1417c8900-0x1417ca270 .text$mn,
// dir client\ms2). Header name assumed; member names invented from their use.
// Derives StateMoveSkill (statemanager.h): the ctor sets its fallback state to 5 and its m_n44 to 0x1e.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/placeholder/ascript.h"

class StateGlideData;

class SkillGlideData;   // the glide skill row (commonfiles/skilloverlapcompare.h)

// 0xa0.
class StateGlide : public StateMoveSkill
{
public:
    StateGlide(PCBase* pOwner);                             // 0x1417c8900
    virtual ~StateGlide();                                  // 0x1417c89e0 (??_G 0x1417ca1a0)
    virtual int vfunc_1();                                  // 1  0x1417ca260: 0x1e
    virtual void vfunc_3(double fTime);                     // 3  0x1417c8f60
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c8a60 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417c9110 (leave)
    virtual void vfunc_7(int n);                            // 7  0x1417c9250
    virtual void vfunc_8(double fTime);                     // 8  0x1417c92a0
    virtual void vfunc_9(double fTime);                     // 9  0x1417c9360 (switch between the two animations)
    virtual int vfunc_22(MS2Ptr<StateSyncObject> p);         // 22 0x1417c9710
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417ca1e0
    virtual bool vfunc_28(MS2Ptr<StateSyncObject> p);        // 28 0x1417c9660
    virtual bool vfunc_38(StateData* pData);                // 38 0x1417c9790

    void FUN_1417c9880(float fTime);                        // advance the glide and move the actor
    float FUN_1417c99f0();                                  // sway
    float FUN_1417c9ad0();
    float FUN_1417c9b70();                                  // row +0x28
    efd::Point3 FUN_1417c9ba0();                            // owner facing as world direction
    efd::Point3 FUN_1417c9c00();                            // the move of this frame (height)
    efd::Point3 FUN_1417c9ee0();                            // the move of this frame (forward)
    int FUN_1417c9740();                                    // 0x1417c9740
    int FUN_1417ca000();                                    // the actor is low enough to land

    int m_nAnim;                                            // +0x78 the animation set playing (99 or 100)
    int m_nEffect;                                          // +0x7c effect id (0 = none)
    MS2Ptr<SkillGlideData> m_spRow;                         // +0x80
    float m_fTime;                                          // +0x90
    float m_fStartZ;                                        // +0x94
    bool m_bHeightErr;                                      // +0x98
    bool m_bTooHigh;                                        // +0x99
    char m_pad_9a[6];
};
MS2_CHECK_SIZE(StateGlide, 0xa0);
MS2_CHECK_OFFSET(StateGlide, m_spRow, 0x80);
MS2_CHECK_OFFSET(StateGlide, m_fTime, 0x90);
