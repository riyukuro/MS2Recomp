// statesyncobject.h - the StateSyncObject subclasses (the per-state extra payload of a queued state request) and the
// factory that picks one by state id. The base StateSyncObject is Unk_StateArg22 (client/ms2/statemanager.h).
// Header name assumed from the unit ?\statesyncobject.cpp (0x140835210-0x140837660); class names from RTTI, member
// names inferred from the packet coders.
#pragma once
#include <afx.h>
#include <efd/Point3.h>
#include <egf/Entity.h>   // statemanager.h uses egf::Entity

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/statemanager.h"

// state 0x3c: rock-paper-scissors micro game.
class StateSyncObjectMicroGameRps : public Unk_StateArg22
{
public:
    explicit StateSyncObjectMicroGameRps(int nState);  // 0x1408366e0
    void vfunc_1(COutputStream& kOut) override;          // 0x140836760
    void vfunc_2(CInPacket& kIn) override;               // 0x140836810

    int m_nB8;              // +0xb8
    int m_nBC;              // +0xbc sent as a signed byte (-1 = none)
    int m_nC0;              // +0xc0 sent as a signed byte (-1 = none)
    CStringW m_strC8;       // +0xc8
};
MS2_CHECK_SIZE(StateSyncObjectMicroGameRps, 0xd0);

// state 0x3a: couple emotion (partner id and the two actors' positions).
class StateSyncObjectCoupleEmotion : public Unk_StateArg22
{
public:
    explicit StateSyncObjectCoupleEmotion(int nState);  // 0x140836930
    void vfunc_1(COutputStream& kOut) override;          // 0x1408369e0
    void vfunc_2(CInPacket& kIn) override;               // 0x140836ab0

    int m_nB8;              // +0xb8
    int m_nBC;              // +0xbc
    unsigned char m_nC0;    // +0xc0
    efd::Point3 m_posC4;    // +0xc4
    efd::Point3 m_posD0;    // +0xd0
};
MS2_CHECK_SIZE(StateSyncObjectCoupleEmotion, 0xe0);

// state 0x45: couple dance micro game.
class StateSyncObjectMicroGameCoupleDance : public Unk_StateArg22
{
public:
    explicit StateSyncObjectMicroGameCoupleDance(int nState);  // 0x140836be0
    void vfunc_1(COutputStream& kOut) override;                 // 0x140836c50
    void vfunc_2(CInPacket& kIn) override;                      // 0x140836ce0

    int m_nB8;              // +0xb8
    bool m_bBC;             // +0xbc
    CStringA m_strC0;       // +0xc0
};
MS2_CHECK_SIZE(StateSyncObjectMicroGameCoupleDance, 0xc8);

// state 0x47: wedding emotion.
class StateSyncObjectWeddingEmotion : public Unk_StateArg22
{
public:
    explicit StateSyncObjectWeddingEmotion(int nState);  // 0x140836dd0
    void vfunc_1(COutputStream& kOut) override;           // 0x140836e50
    void vfunc_2(CInPacket& kIn) override;                // 0x140836f20

    bool m_bB8;             // +0xb8 m_nC0 and m_bC4 follow
    bool m_bB9;             // +0xb9 m_nBC follows
    int m_nBC;              // +0xbc
    int m_nC0;              // +0xc0
    bool m_bC4;             // +0xc4
};
MS2_CHECK_SIZE(StateSyncObjectWeddingEmotion, 0xc8);

// New state request for nState (the subclass above for 0x3a/0x3c/0x45/0x47, else the base record).
MS2Ptr<Unk_StateArg22> FUN_140835450(int nState);
