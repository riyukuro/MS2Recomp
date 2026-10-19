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

// The glide skill row (a CPtred; fields used by StateGlide only). Name invented.
class Unk_GlideRow : public CPtred
{
public:
    int FUN_140802ab0();                    // 0x140802ab0 (a value of the row; returned by FUN_1417c9740)

    char m_pad_18[4];
    int m_nSkill;                           // +0x18
    float m_f1c;                            // +0x1c subtracted from the end height
    float m_f20;                            // +0x20 maximum fall height (0 = unlimited)
    float m_f24;                            // +0x24 forward speed per second
    float m_f28;                            // +0x28 base speed
    float m_f2c;                            // +0x2c fall speed per second
    float m_f30;                            // +0x30
    float m_f34;                            // +0x34 sway amplitude
    float m_f38;                            // +0x38 sway period
    float m_f3c;                            // +0x3c fall limit
    float m_f40;                            // +0x40 forward limit
    char m_pad_44[4];
    CStringA m_strEffectA;                  // +0x48
    CStringA m_strEffectB;                  // +0x50
    CStringA m_strAnimB;                    // +0x58
    char m_pad_60[8];
    CStringA m_strAnimA;                    // +0x68
    bool m_bCheckGround;                    // +0x70
    char m_pad_71[3];
    int m_nSpeedMul;                        // +0x74
};

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
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x1417c9710
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x1417ca1e0
    virtual bool vfunc_28(MS2Ptr<Unk_StateArg22> p);        // 28 0x1417c9660
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
    MS2Ptr<Unk_GlideRow> m_spRow;                           // +0x80
    float m_fTime;                                          // +0x90
    float m_fStartZ;                                        // +0x94
    bool m_bHeightErr;                                      // +0x98
    bool m_bTooHigh;                                        // +0x99
    char m_pad_9a[6];
};
MS2_CHECK_SIZE(StateGlide, 0xa0);
MS2_CHECK_OFFSET(StateGlide, m_spRow, 0x80);
MS2_CHECK_OFFSET(StateGlide, m_fTime, 0x90);
