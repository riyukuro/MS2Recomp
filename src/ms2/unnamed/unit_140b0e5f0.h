// CoupleEffectSystem (RTTI name): per-player helper of the couple-gem feature. It watches the distance between its owner
// (a PCBase) and the partner player, starts/stops the shared couple effect between them and tells the server about
// it (packet 0xa4: 0 start/1 stop/2 result/3 request). Created by pcbase.cpp (FUN_1416636e0, operator new(0xa0)).
// Owning unit: unit_140b0e5f0 (0x140b0e5f0-0x140b0f4c0). Member names are invented from their use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/timer.h"

class PCBase;

// 8-byte millisecond poll timer (the "elapsed since last hit" helper: ctor 0x140517b00, test 0x140268870).
struct Unk_CoupleTick
{
    Unk_CoupleTick();                       // 0x140517b00
    unsigned m_nInterval;                   // +0
    unsigned m_nLastTick;                   // +4
};
MS2_CHECK_SIZE(Unk_CoupleTick, 8);

// NiPoint3 built from an efd::Point3 (0x14027dcf0).
struct Unk_StreamPoint;
struct Unk_CoupleVec
{
    Unk_CoupleVec(const Unk_StreamPoint& pt);               // 0x14027dcf0
    Unk_CoupleVec& FUN_14097faa0(const Unk_CoupleVec& v);   // NiPoint3::operator=
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_CoupleVec, 12);

class CoupleEffectSystem : public CPtred
{
public:
    CoupleEffectSystem(PCBase* pOwner, __int64 nPartnerId, int nCoupleType, int bLinked, CStringW strName, int nGemId);  // 0x140b0e5f0
    virtual ~CoupleEffectSystem();                          // 0x140b0e730 (??_G 0x140b0f440)

    void FUN_140b0e7a0();                                   // per-tick update
    void FUN_140b0ead0(__int64 nValue);                     // report a result to the server
    void FUN_140b0eba0(int nObjectId);
    int GetCoupleType() const;                              // couple type
    CStringW GetName() const;                         // name
    __int64 FUN_140b0ec80();                                // id of the character this effect is keyed by
    void FUN_140b0ecd0();                                   // arm: activate when the partner exists
    void FUN_140b0ed30();                                   // spawn the effect
    void FUN_140b0eed0();                                   // remove the effect
    bool FUN_140b0ef20();                                   // current map allows the effect
    CString FUN_140b0efb0();                                // effect name from the gem table
    Unk_CoupleVec FUN_140b0f160();                          // midpoint of owner and partner
    void FUN_140b0f260();                                   // send the start request
    void FUN_140b0f3a0(int nMode);                          // 0 start, 1 stop

    int m_bInRange;                                         // +0x18 (effect running within range)
    int m_bActive;                                          // +0x1c
    int m_bRequested;                                       // +0x20
    int m_pad_24;
    Timer m_timer;                                          // +0x28
    unsigned m_nEffectId;                                      // +0x60 handle of the spawned effect
    Unk_CoupleTick m_tick;                                  // +0x64
    Unk_CoupleVec m_posEffect;                              // +0x6c
    PCBase* m_pOwner;                                       // +0x78
    int m_bLinked;                                          // +0x80
    int m_nCoupleType;                                      // +0x84
    __int64 m_nPartnerId;                                   // +0x88
    CStringW m_strName;                                     // +0x90
    int m_nGemId;                                           // +0x98
    int m_pad_9c;
};
MS2_CHECK_SIZE(CoupleEffectSystem, 0xa0);
MS2_CHECK_OFFSET(CoupleEffectSystem, m_timer, 0x28);
MS2_CHECK_OFFSET(CoupleEffectSystem, m_posEffect, 0x6c);
MS2_CHECK_OFFSET(CoupleEffectSystem, m_strName, 0x90);
