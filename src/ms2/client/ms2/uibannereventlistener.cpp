// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uibanner.h (UIBannerEventListener).
//
// The two banner-click listeners: the event's Entity is the target, the local player is the challenger. Each
// listener validates the target (same player, blocked user, game state, distance, position, state) and then asks
// the server (COutPacket type 0xa8) to start the microgame. The matching "are you sure?" message box result
// callbacks (the two Delegate<bool(int, const CMsgBoxData&)> bodies) live in the same TU.
//
// MS2-UNIT: client\ms2\uibannereventlistener.cpp
// MS2-RANGE: 0x1400c9d30-0x1400c9ed0 .text$di
// MS2-RANGE: 0x140bac2f0-0x140bad0a0 .text$mn
//
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VUnk_CoupleDanceEvent@@@@QEBAPEAVUnk_CoupleDanceEvent@@XZ 0x140bacf70 ; unique
// MS2-PINS-END
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibannereventlistener.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uibanner.h"

// ---- the unit's header statics: this one comes first (an unidentified header included before the common one) ----
static CStringW s_strBannerClose(L"bannerClose");

#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

class State;

// The local player (0x1403ed2d0's singleton -> 0x141bd0cc0): a large virtual class; only a few slots are used here.
struct Unk_Pos { Unk_Pos(); float m_0; float m_4; float m_8; };
class Unk_141bd0cc0
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_Pos vfunc_18();                                     // 18: position
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59(int a1, int a2, int a3, int a4);          // 59: switch to a microgame state
    int FUN_14123c580();                                            // the actor kind / team
    int FUN_14166c930();                                            // current state id
    State* FUN_14166ccb0();                                         // current state
    __int64 FUN_141656a80();                                        // the character id
};
class Unk_1403ed2d0 { public: Unk_141bd0cc0* FUN_141bd0cc0(); };
Unk_1403ed2d0* FUN_1403ed2d0();
bool FUN_140b883c0();
bool FUN_140b88470(Unk_Pos& posA, Unk_Pos& posB);
bool FUN_140b884e0(Unk_Pos& pos);
bool FUN_140b887b0(Unk_141bd0cc0* pPlayer);
Unk_141bd0cc0* FUN_140b879d0(State* pState);                        // the opponent of the rps state
Unk_141bd0cc0* FUN_140b89dd0(State* pState);                        // the partner of the couple dance state

// Message boxes (CMsgBoxData): the button index lives at +0x18 of the timer struct.
struct Unk_MsgBoxTimer { int m_nSec; int m_nMs; int m_nShowFormat; void* m_strFormat; int m_nButton; int m_nArmed; };
class Unk_CMsgBoxData
{
public:
    void FUN_141a01660(const CStringW& strTag);
    void FUN_141a024a0(int n);
    const Unk_MsgBoxTimer& FUN_141a04a80() const;
};
MS2Ptr<Unk_CMsgBoxData> FUN_140d73f20(CStringW strMessage, int nType);
void FUN_140d73c60(MS2Ptr<Unk_CMsgBoxData> box);
CStringW FUN_1409eec40(int nStringId);
CStringW FUN_140298ea0(CStringW strKey);
void FUN_141275260(int nStringId, int a, int b);
void FUN_1412752d0(const CStringW& str, int n);

// The current microgame event (0x140302b00 -> +0xae0 -> a copy under a lock): its id is at +0x18.
class Unk_CoupleDanceEvent
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    int m_id;                                                       // +0x18
};
MS2_CHECK_OFFSET(Unk_CoupleDanceEvent, m_id, 0x18);
// @0x140bacf70
template <> Unk_CoupleDanceEvent* MS2Ptr<Unk_CoupleDanceEvent>::get() const { return m_p; }
class Unk_CoupleEventHolder { public: MS2Ptr<Unk_CoupleDanceEvent> FUN_140428700(); };
class Unk_140302b00 { public: Unk_CoupleEventHolder* FUN_1403ed140(); };
Unk_140302b00* FUN_140302b00();

// The buddy manager (blocked users).
class Unk_SSG97a780 { public: unsigned FUN_140ae51b0(__int64 nCharacterId); };
Unk_SSG97a780* FUN_14097a780();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140bac2f0
void UIBannerEventListenerRpsGame::vfunc_1(MS2Ptr<UIBanner::Entity> pEntity)
{
    if (pEntity == NULL)
    {
        MS2_ASSERT_AT(0x10, 0);
        return;
    }
    Unk_141bd0cc0* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
    {
        MS2_ASSERT_AT(0x17, 0);
        return;
    }
    Unk_141bd0cc0* pTarget = reinterpret_cast<Unk_141bd0cc0*>(pEntity->FUN_140ba86d0());
    if (!pTarget)
    {
        MS2_ASSERT_AT(0x1e, 0);
        return;
    }
    int bSelfTarget = (pPlayer->FUN_14123c580() == pTarget->FUN_14123c580()) ? 1 : 0;
    if (bSelfTarget)
    {
        // We cannot challenge ourselves.
        CStringW strMessage = FUN_1409eec40(0xd0c);
        MS2Ptr<Unk_CMsgBoxData> box = FUN_140d73f20(strMessage, 1);
        box->FUN_141a01660(s_strBannerClose);
        box->FUN_141a024a0(0);
        FUN_140d73c60(box);
        return;
    }
    if (FUN_14097a780()->FUN_140ae51b0(pTarget->FUN_141656a80()))
    {
        FUN_141275260(0xd08, 1, 1);
        return;
    }
    if (!FUN_140b883c0())
    {
        FUN_141275260(0xd00, 1, 1);
        return;
    }
    Unk_Pos posPlayer = pPlayer->vfunc_18();
    Unk_Pos posTarget = pTarget->vfunc_18();
    if (!FUN_140b88470(posPlayer, posTarget))
    {
        FUN_141275260(0xd01, 1, 1);
        return;
    }
    if (!FUN_140b884e0(posPlayer))
    {
        FUN_141275260(0xd02, 1, 1);
        return;
    }
    if (!FUN_140b887b0(pPlayer))
    {
        FUN_141275260(0xd03, 1, 1);
        return;
    }
    COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
    packet.Encode2(1);
    packet.Encode8(pTarget->FUN_141656a80());
    FUN_140710590(packet);
}

// @0x140bac700
bool FUN_140bac700(int nResult, const Unk_CMsgBoxData& box)
{
    if (box.FUN_141a04a80().m_nButton != 0)
        return true;
    Unk_141bd0cc0* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
    {
        MS2_ASSERT_AT(0x5f, 0);
        return true;
    }
    if (pPlayer->FUN_14166c930() != 0x3c)
        return true;
    State* pState = pPlayer->FUN_14166ccb0();
    if (!pState)
    {
        MS2_ASSERT_AT(0x69, 0);
        return true;
    }
    Unk_141bd0cc0* pTarget = FUN_140b879d0(pState);
    if (!pTarget)
        return true;
    COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
    packet.Encode2(5);
    packet.Encode8(pTarget->FUN_141656a80());
    FUN_140710590(packet);
    pPlayer->vfunc_59(1, 0, 0, 0);
    return true;
}

// @0x140bac880
void UIBannerEventListenerCoupleDance::vfunc_1(MS2Ptr<UIBanner::Entity> pEntity)
{
    if (pEntity == NULL)
    {
        MS2_ASSERT_AT(0x81, 0);
        return;
    }
    Unk_141bd0cc0* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
    {
        MS2_ASSERT_AT(0x88, 0);
        return;
    }
    Unk_141bd0cc0* pTarget = reinterpret_cast<Unk_141bd0cc0*>(pEntity->FUN_140ba86d0());
    if (!pTarget)
    {
        MS2_ASSERT_AT(0x8f, 0);
        return;
    }
    if (pPlayer->FUN_14123c580() == pTarget->FUN_14123c580())
    {
        // We cannot dance with ourselves.
        MS2Ptr<Unk_CMsgBoxData> box = FUN_140d73f20(FUN_140298ea0(L"s_microgame_couple_dance_close"), 1);
        box->FUN_141a01660(s_strBannerClose);
        box->FUN_141a024a0(0);
        FUN_140d73c60(box);
        return;
    }
    MS2Ptr<Unk_CoupleDanceEvent> pEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (pEvent == NULL)
    {
        FUN_1412752d0(CStringW(L"s_microgame_couple_dance_end_event"), 1);
        return;
    }
    if (FUN_14097a780()->FUN_140ae51b0(pTarget->FUN_141656a80()))
    {
        FUN_1412752d0(CStringW(L"s_microgame_couple_dance_request_failed_blocked_user"), 1);
        return;
    }
    Unk_Pos posPlayer = pPlayer->vfunc_18();
    Unk_Pos posTarget = pTarget->vfunc_18();
    if (!FUN_140b88470(posPlayer, posTarget))
    {
        FUN_1412752d0(CStringW(L"s_microgame_couple_dance_request_failed_wrong_distance"), 1);
        return;
    }
    if (!FUN_140b884e0(posPlayer))
    {
        FUN_1412752d0(CStringW(L"s_microgame_couple_dance_request_failed_wrong_position"), 1);
        return;
    }
    if (!FUN_140b887b0(pPlayer))
    {
        FUN_1412752d0(CStringW(L"s_microgame_couple_dance_request_failed_wrong_state"), 1);
        return;
    }
    COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
    packet.Encode2(0xe);
    packet.Encode4(pEvent->m_id);
    packet.Encode8(pTarget->FUN_141656a80());
    FUN_140710590(packet);
}

// @0x140bacda0
bool FUN_140bacda0(int nResult, const Unk_CMsgBoxData& box)
{
    if (box.FUN_141a04a80().m_nButton != 0)
        return true;
    Unk_141bd0cc0* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
    {
        MS2_ASSERT_AT(0xd0, 0);
        return true;
    }
    if (pPlayer->FUN_14166c930() != 0x45)
        return true;
    State* pState = pPlayer->FUN_14166ccb0();
    if (!pState)
    {
        MS2_ASSERT_AT(0xda, 0);
        return true;
    }
    Unk_141bd0cc0* pTarget = FUN_140b89dd0(pState);
    if (!pTarget)
        return true;
    int nEventId = 0;
    MS2Ptr<Unk_CoupleDanceEvent> pEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (pEvent.get())
        nEventId = pEvent->m_id;
    COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
    packet.Encode2(0x13);
    packet.Encode4(nEventId);
    packet.Encode8(pTarget->FUN_141656a80());
    FUN_140710590(packet);
    pPlayer->vfunc_59(1, 0, 0, 0);
    return true;
}

// @0x140bacf80
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1680-0x142ca1730 .text$yd
