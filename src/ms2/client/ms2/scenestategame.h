// scenestategame.h - CSceneStateGame (efd RTTI name "CSceneStateGame", class id 0x0620000c): the
// in-field scene state. It dispatches every field packet (OnPacket, opcode switch 0x9..0x139) to its handlers and
// keeps the reconnect loop. Header name assumed from the unit path; handler names are FUN_<va> (opcode in the comment).
//
// Bases: CSceneStateBase (0x10), IWorldServiceCallback at +0x10 (vftable 0x142f5faa0; overrides slots 1 and 4).
// Primary vftable 0x142f5fa18 (16 slots), ??_G 0x1417476f0 (0x78 bytes), ClassInfo 0x143ae7560.
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/timer.h"

class CInPacket;
class CInputStream;
class CMsgBoxData;
class NotifyObject;
class PCBase;

class CSceneStateGame : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateGame, 0x0620000c, efd::IBase);

public:
    CSceneStateGame();                                      // 0x14170bda0
    virtual ~CSceneStateGame();                             // 0x14170be40

    int vfunc_15() override;                                // 0x14170be90
    void OnEnter(int nPrevState) override;                  // 0x14170beb0
    void OnLeave(int nNextState) override;                  // 0x14170bfd0
    void OnUpdate(double fTime) override;                   // 0x14170c0c0
    void OnPacket(CInPacket& packet) override;              // 0x14170c5b0
    void vfunc_1(int) override;                             // 0x14170d9f0 (IWorldServiceCallback slot 1: field entered)
    void vfunc_4(int) override;                             // 0x14170daf0 (IWorldServiceCallback slot 4: disconnected)
    int vfunc_14() override;                                // 0x14170dbc0
    void OnWndMessage(unsigned int nMsg, int wParam, int lParam) override;  // 0x14170dbe0

    // packet handlers (opcode)
    void FUN_14170dc90(CInPacket& packet);                  // 0x9
    void OnServerEnter(CInPacket& packet);                  // 0x15
    void OnLoadUgcMap(CInPacket& packet);                  // 0x7d
    void FUN_14170f930(CInPacket& packet);                  // 0x16
    void FUN_14170fc70(CInPacket& packet);                  // 0x19
    void OnAddUser(CInPacket& packet);                  // 0x17
    void FUN_141711dc0(CInPacket& packet);                  // 0x18
    void OnFieldAddItem(CInPacket& packet);                  // 0x2b
    void FUN_141712340(CInPacket& packet);                  // 0x2c
    void OnFieldPickupItem(CInPacket& packet);                  // 0x2d
    void OnUserSync(CInPacket& packet);                  // 0x1c
    void OnRideSync(CInPacket& packet);                  // 0x7a
    void FUN_141712a90(CInPacket& packet);                  // 0x1f
    void OnItemPutOnOrOff(CInPacket& packet);                  // 0x20
    void FUN_1417132b0(CInPacket& packet);                  // 0xce
    void OnItemInventory(CInPacket& packet);                  // 0x21
    void FUN_141715bd0(CInPacket& packet);                  // 0x23
    void OnFurnishingInventory(CInPacket& packet);                  // 0x24
    void OnItemPutOn(CInPacket& packet);                  // 0x25
    void OnItemPutOff(CInPacket& packet);                  // 0x26
    void FUN_141716d10(CInPacket& packet);                  // 0x27
    void OnItemSkinPutOff(CInPacket& packet);                  // 0x28
    void OnItemUpdate(CInPacket& packet);                  // 0x2a
    void OnUserSkinColor(CInPacket& packet);                  // 0x30
    void FUN_141717560(CInPacket& packet);                  // 0x29
    void OnUserBattle(CInPacket& packet);                  // 0x2f
    void OnStat(CInPacket& packet);                  // 0x2e
    void OnSkillUse(CInPacket& packet);                  // 0x3c
    void FUN_141718150(CInPacket& packet);                  // 0x3e
    void OnSkillCancel(CInPacket& packet);                  // 0x3f
    void OnSkillUseFailed(CInPacket& packet);                  // 0x40
    void FUN_141718b80(CInPacket& packet);                  // 0x41
    void OnFieldAddNpc(CInPacket& packet);                  // 0x55
    void FUN_1417195f0(CInPacket& packet);                  // 0x56
    void FUN_1417197c0(CInPacket& packet);                  // 0x57
    void FUN_141719840(CInPacket& packet);                  // 0x58
    void OnInteractNpc(CInPacket& packet);                  // 0x59
    void FUN_141719a30(CInPacket& packet);                  // 0x4b
    void OnFieldAddPet(CInPacket& packet);                  // 0x5a
    void FUN_14171a2e0(CInPacket& packet);                  // 0x5b
    void OnSyncPetTamingPoint(CInPacket& packet);                  // 0x5c
    void FUN_14171a6c0(CInPacket& packet);                  // 0x32
    void OnRevivalConfirm(CInPacket& packet);                  // 0x33
    void OnRevival(CInPacket& packet);                  // 0x34
    void FUN_14171aa90(CInPacket& packet);                  // 0x35
    void FUN_14171ab00(CInPacket& packet);                  // 0x37
    void OnLevelUp(CInPacket& packet);                  // 0x38
    void OnMyInfo(CInPacket& packet);                  // 0xae
    void OnMeso(CInPacket& packet);                  // 0x39
    void OnMeret(CInPacket& packet);                  // 0x3a
    void FUN_14171bad0(CInPacket& packet);                  // 0x117
    void OnCurrencyToken(CInPacket& packet);                  // 0x3b
    void OnSkillDamage(CInPacket& packet);                  // 0x3d
    void FUN_14171c1d0(CInPacket& packet);                  // 0x3d mode 0
    void FUN_14171cdf0(CInPacket& packet);                  // 0x3d mode 1
    void FUN_14171d610(CInPacket& packet);                  // 0x3d mode 3
    void FUN_14171d820(CInPacket& packet);                  // 0x3d mode 4
    void FUN_14171dc40(CInPacket& packet);                  // 0x3d mode 5
    void FUN_14171e440(CInPacket& packet);                  // 0x3d mode 6
    void FUN_14171e860(CInPacket& packet);                  // 0x3d mode 7
    void FUN_14171e9a0(CInPacket& packet);                  // 0x3d mode 8
    void OnFieldPortal(CInPacket& packet);                  // 0x48
    void OnJob(CInPacket& packet);                  // 0x49
    void OnBuff(CInPacket& packet);                  // 0x47
    void FUN_141720c60(CInPacket& packet);                  // 0x130
    void OnRegionSkill(CInPacket& packet);                  // 0x4c
    void FUN_141721270(CInPacket& packet);                  // 0x4e
    void FUN_1417212a0(CInPacket& packet);                  // 0x4d
    void FUN_1417212d0(CInPacket& packet);                  // 0x4f
    void OnTombstone(CInPacket& packet);                  // 0x5d
    void OnUserState(CInPacket& packet);                  // 0x36
    void OnUserMoveByPortal(CInPacket& packet);                  // 0x5f
    void FUN_141721c50(CInPacket& packet);                  // 0x61
    void FUN_141721c90(CInPacket& packet);                  // 0x62
    void FUN_141721cd0(CInPacket& packet);                  // 0x54
    void OnMassiveEvent(CInPacket& packet);                  // 0x60
    void FUN_141722fb0(CInPacket& packet);                  // 0x64
    void OnStateFallDamage(CInPacket& packet);                  // 0x65
    void OnCinematic(CInPacket& packet);                  // 0x66
    void FUN_1417232a0(CInPacket& packet);                  // 0x67
    void FUN_141723330(CInPacket& packet);                  // 0x70
    void FUN_1417235a0(CInPacket& packet);                  // (cube item placed by an actor)
    void OnSetCraftMode(CInPacket& packet);                  // 0x68
    void OnResponseCube(CInPacket& packet);                  // 0x69
    void OnLoadCubes(CInPacket& packet);                  // 0x6a
    void FUN_141728c20(CInPacket& packet);                  // 0x71
    void OnLiftable(CInPacket& packet);                  // 0x73
    void OnItemFusion(CInPacket& packet);                  // 0x74
    void FUN_14172a1c0(CInPacket& packet);                  // 0x75
    void FUN_14172a7b0(CInPacket& packet);                  // 0x76
    void FUN_14172a850(CInPacket& packet);                  // 0x77
    void OnResponseRide(CInPacket& packet);                  // 0x79
    void FUN_14172b350(CInPacket& packet);                  // 0x7b
    void FUN_14172c170(CInPacket& packet);                  // 0x6e
    void OnInteractObject(CInPacket& packet);                  // 0x63
    void FUN_14172f030(CInPacket& packet);                  // 0x42
    void FUN_14172f1c0(CInPacket& packet);                  // 0x43
    void FUN_14172f210(CInPacket& packet);                  // 0x44
    void FUN_14172f480(CInPacket& packet);                  // 0x45
    void FUN_14172f500(CInPacket& packet);                  // 0x7e
    void FUN_141730920(CInPacket& packet);                  // 0x7f
    void FUN_141731160(CInPacket& packet);                  // 0x89
    void FUN_141731190(CInPacket& packet);                  // 0x94
    void FUN_141731350(CInPacket& packet);                  // 0x95
    void FUN_141731470(CInPacket& packet);                  // 0x80
    void FUN_141731610(CInPacket& packet);                  // 0x81
    void FUN_1417316d0(CInPacket& packet);                  // 0x83
    void FUN_141731730(CInPacket& packet);                  // 0x86
    void FUN_141731ac0(CInPacket& packet);                  // 0x96
    void FUN_141731af0(CInPacket& packet);                  // 0xdb
    void FUN_141731b20(CInPacket& packet);                  // 0xc
    void FUN_141731c10(CInPacket& packet);                  // 0x8c
    void OnPvp(CInPacket& packet);                  // 0xb6
    void FUN_141732ac0(CInPacket& packet);                  // 0x9d
    void FUN_141732af0(CInPacket& packet);                  // 0x9e
    void OnItemEnchant(CInPacket& packet);                  // 0x97
    void OnWebOpen(CInPacket& packet);                  // 0x9b
    void FUN_141733440(CInPacket& packet);                  // 0x9f
    void OnSystemShop(CInPacket& packet);                  // 0xa1
    void OnAutoRevive(CInPacket& packet);                  // 0xa2
    void OnPlayerKillNotice(CInPacket& packet);                  // 0xa3
    void FUN_141733b30(CInPacket& packet);                  // 0xb0
    void OnNametag(CInPacket& packet);                  // 0xb1
    void OnSetPcbang(CInPacket& packet);                  // 0xb5
    void FUN_1417340f0(CInPacket& packet);                  // 0xb7
    void FUN_1417343c0(CInPacket& packet);                  // 0xb9
    void OnItemDropNotice(CInPacket& packet);                  // 0xba
    void OnRecallScroll(CInPacket& packet);                  // 0xbc
    void FUN_141734930(CInPacket& packet);                  // 0xbe
    void OnEnchantScroll(CInPacket& packet);                  // 0xbf
    void OnGlobalPortal(CInPacket& packet);                  // 0xc1
    void OnQuizEvent(CInPacket& packet);                  // 0xc2
    void FUN_141734bc0(CInPacket& packet);                  // 0xc3
    void FUN_141734c70(CInPacket& packet);                  // 0xc4
    void OnDarkStream(CInPacket& packet);                  // 0xc5
    void OnPlayArcade(CInPacket& packet);                  // 0xd8
    void FUN_1417353b0(CInPacket& packet);                  // 0xc7
    void FUN_1417353e0(CInPacket& packet);                  // 0xca
    void FUN_141735410(CInPacket& packet);                  // 0xcb
    void OnMastery(CInPacket& packet);                  // 0xcd
    void OnEventReward(CInPacket& packet);                  // 0xf7
    void FUN_141736240(CInPacket& packet);                  // 0xf9
    void FUN_141736880(CInPacket& packet);                  // 0xa6
    void FUN_141736940(CInPacket& packet);                  // 0xa8
    void FUN_141737360(CInPacket& packet);                  // 0x1a
    void FUN_1417373d0(CInPacket& packet);                  // 0xaa
    void FUN_141737d60(CInPacket& packet);                  // 0xd1
    void FUN_141737db0(CInputStream& in);                   // 0xd3
    void FUN_1417380c0(CInPacket& packet);                  // 0xd6
    void FUN_141738120(CInPacket& packet);                  // 0xd7
    void FUN_141738290(CInPacket& packet);                  // 0xdc
    void FUN_141738380(CInPacket& packet);                  // 0xdd
    void FUN_141738430(CInPacket& packet);                  // 0xe8
    void FUN_141738ad0(CInPacket& packet);                  // 0xe7
    void FUN_141738b40(CInPacket& packet);                  // 0xea
    void FUN_141739910(CInPacket& packet);                  // 0xab
    void FUN_141739e40(CInPacket& packet);                  // 0xac
    void OnPremiumClub(CInPacket& packet);                  // 0xeb
    void FUN_14173a0d0(CInPacket& packet);                  // 0xec
    void FUN_14173a0f0(CInPacket& packet);                  // 0x101
    void OnLocalCamera(CInPacket& packet);                  // 0xe9
    void OnOneTimeEffect(CInPacket& packet);                  // 0xf1
    void FUN_14173a5b0(CInPacket& packet);                  // 0xf2
    void OnTimeScale(CInPacket& packet);                  // 0xf3
    void FUN_14173a720(CInPacket& packet);                  // 0xf4
    void OnHomeInvite(CInPacket& packet);                  // 0xf8
    void FUN_14173aa10(CInPacket& packet);                  // mode 2
    void FUN_14173ad60(CInPacket& packet);                  // mode 0
    void FUN_14173b080(CInPacket& packet);                  // 0xfa
    void FUN_14173b1d0(CInPacket& packet);                  // 0xfb
    void FUN_14173b220(CInPacket& packet);                  // 0xfd
    void FUN_14173b380(CInPacket& packet);                  // 0xfe
    void FUN_14173b420(CInPacket& packet);                  // 0x103
    void FUN_14173b5a0(CInPacket& packet);                  // 0x105
    void FUN_14173c090(CInPacket& packet);                  // 0x106
    void FUN_14173c0f0(CInPacket& packet);                  // 0x106 mode 1
    void FUN_14173c2d0(CInPacket& packet);                  // 0x141739910 sub-handler (codi tab activated)
    void FUN_141715860(CInPacket& packet);  // 0x141713fb0 sub-handler (mode 8, item list)
    void SendBeauty(CInPacket& packet);                  // 0x141739910 sub-handler (beauty shop open)
    void FUN_14173c7a0(CInPacket& packet);                  // 0x111
    void OnReactor(CInPacket& packet);                  // 0x115
    void FUN_14173ce30(CInPacket& packet);                  // 0x118
    void FUN_14173d180(CInPacket& packet);                  // 0x11a
    void OnLapenshard(CInPacket& packet);                  // 0x11b
    void OnPrestige(CInPacket& packet);                  // 0x11c
    void FUN_14173ddf0(CInPacket& packet);                  // 0x120
    void FUN_14173de10(CInPacket& packet);                  // 0x121
    void FUN_14173def0(CInPacket& packet);                  // 0x91
    void FUN_14173dfd0(CInPacket& packet);                  // 0x11f
    void FUN_14173e440(CInPacket& packet);                  // 0x126
    void FUN_14173e4b0(CInPacket& packet);                  // 0xef
    void FUN_14173e510(CInPacket& packet);                  // 0xf5
    void OnHideAndSeek(CInPacket& packet);                  // 0x12b
    void FUN_14173f0c0(CInPacket& packet);                  // 0x12c
    void OnLimitBreak(CInPacket& packet);                  // 0x12e
    void FUN_14173f280(CInPacket& packet);                  // 0x12f
    void OnItemSocketSystem(CInPacket& packet);                  // 0xde
    void FUN_14173f7c0(CInPacket& packet);                  // 0x131
    void FUN_14173f810(CInPacket& packet);                  // 0x135
    void FUN_14173f860(CInPacket& packet);                  // 0x136
    void FUN_14173fc00(CInPacket& packet);                  // 0x138
    void FUN_14173fc40(CInPacket& packet);                  // 0x139

    // helpers
    void FUN_1417127b0(CInPacket& packet, PCBase* pActor);    // read an actor's skill/buff list
    void FUN_141739450(bool bFlag);                         // spawn the taxi-station markers
    void FUN_141738240(CInPacket& packet);                  // (no dispatch case: reads the mode byte only)
    void FUN_141739220(CInPacket& packet);                  // 0xea sub-handler: formatted notice
    void FUN_1417398d0();                                   // refresh the individual pvp dialog
    void FUN_141739880();                                   // drop the taxi effect (m_nTaxiEffect)
    int FUN_14173fe20();                                    // Ctrl+Alt+... debug key combination
    void FUN_14173feb0();                                   // the debug key action
    void FUN_141740200(const CStringW& strName, int nType); // send packet 0x51 (mode 0, name, type)
    bool FUN_141740280(int nButton, const CMsgBoxData& data); // message box callback: answers packet 0x51

public:   // members (names inferred)
    bool m_b18;                                             // +0x18 (true)
    double m_f20;                                           // +0x20 (OnEnter: FUN_141473280)
    int m_nOpcode;                                          // +0x28 opcode of the packet being handled
    int m_nTaxiEffect;                                      // +0x2c effect handle (FUN_1411a49c0)
    bool m_bReconnecting;                                   // +0x30
    Timer m_reconnectTimer;                                 // +0x38
    int m_nRetry;                                           // +0x70
};
MS2_CHECK_SIZE(CSceneStateGame, 0x78);
MS2_CHECK_OFFSET(CSceneStateGame, m_nOpcode, 0x28);
MS2_CHECK_OFFSET(CSceneStateGame, m_reconnectTimer, 0x38);
MS2_CHECK_OFFSET(CSceneStateGame, m_nRetry, 0x70);
