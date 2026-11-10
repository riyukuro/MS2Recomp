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
    void OnRequestLogin(CInPacket& packet);                  // 0x9
    void OnServerEnter(CInPacket& packet);                  // 0x15
    void OnLoadUgcMap(CInPacket& packet);                  // 0x7d
    void OnRequestFieldEnter(CInPacket& packet);                  // 0x16
    void OnFieldEntrance(CInPacket& packet);                  // 0x19
    void OnAddUser(CInPacket& packet);                  // 0x17
    void OnFieldRemoveUser(CInPacket& packet);                  // 0x18
    void OnFieldAddItem(CInPacket& packet);                  // 0x2b
    void OnFieldRemoveItem(CInPacket& packet);                  // 0x2c
    void OnFieldPickupItem(CInPacket& packet);                  // 0x2d
    void OnUserSync(CInPacket& packet);                  // 0x1c
    void OnRideSync(CInPacket& packet);                  // 0x7a
    void OnEmote(CInPacket& packet);                  // 0x1f
    void OnItemPutOnOrOff(CInPacket& packet);                  // 0x20
    void OnPetInventory(CInPacket& packet);                  // 0xce
    void OnItemInventory(CInPacket& packet);                  // 0x21
    void OnFurnishingStorage(CInPacket& packet);                  // 0x23
    void OnFurnishingInventory(CInPacket& packet);                  // 0x24
    void OnItemPutOn(CInPacket& packet);                  // 0x25
    void OnItemPutOff(CInPacket& packet);                  // 0x26
    void OnItemSkinPutOn(CInPacket& packet);                  // 0x27
    void OnItemSkinPutOff(CInPacket& packet);                  // 0x28
    void OnItemUpdate(CInPacket& packet);                  // 0x2a
    void OnUserSkinColor(CInPacket& packet);                  // 0x30
    void FUN_141717560(CInPacket& packet);                  // 0x29
    void OnUserBattle(CInPacket& packet);                  // 0x2f
    void OnStat(CInPacket& packet);                  // 0x2e
    void OnSkillUse(CInPacket& packet);                  // 0x3c
    void OnSkillSync(CInPacket& packet);                  // 0x3e
    void OnSkillCancel(CInPacket& packet);                  // 0x3f
    void OnSkillUseFailed(CInPacket& packet);                  // 0x40
    void OnStateSkill(CInPacket& packet);                  // 0x41
    void OnFieldAddNpc(CInPacket& packet);                  // 0x55
    void OnFieldRemoveNpc(CInPacket& packet);                  // 0x56
    void OnFieldDeadNpc(CInPacket& packet);                  // 0x57
    void OnNpcControl(CInPacket& packet);                  // 0x58
    void OnInteractNpc(CInPacket& packet);                  // 0x59
    void OnNpcTalk(CInPacket& packet);                  // 0x4b
    void OnFieldAddPet(CInPacket& packet);                  // 0x5a
    void OnFieldRemovePet(CInPacket& packet);                  // 0x5b
    void OnSyncPetTamingPoint(CInPacket& packet);                  // 0x5c
    void OnAdventurerBar(CInPacket& packet);                  // 0x32
    void OnRevivalConfirm(CInPacket& packet);                  // 0x33
    void OnRevival(CInPacket& packet);                  // 0x34
    void OnRevivalCount(CInPacket& packet);                  // 0x35
    void OnExpUp(CInPacket& packet);                  // 0x37
    void OnLevelUp(CInPacket& packet);                  // 0x38
    void OnMyInfo(CInPacket& packet);                  // 0xae
    void OnMeso(CInPacket& packet);                  // 0x39
    void OnMeret(CInPacket& packet);                  // 0x3a
    void OnMeretUse(CInPacket& packet);                  // 0x117
    void OnCurrencyToken(CInPacket& packet);                  // 0x3b
    void OnSkillDamage(CInPacket& packet);                  // 0x3d
    void FUN_14171c1d0(CInPacket& packet);                  // 0x3d mode 0
    void FUN_14171cdf0(CInPacket& packet);                  // 0x3d mode 1
    void OnDotDamage(CInPacket& packet);                  // 0x3d mode 3
    void FUN_14171d820(CInPacket& packet);                  // 0x3d mode 4
    void OnRegionSkillDamage(CInPacket& packet);                  // 0x3d mode 5
    void OnSplashDamage(CInPacket& packet);                  // 0x3d mode 6
    void FUN_14171e860(CInPacket& packet);                  // 0x3d mode 7
    void FUN_14171e9a0(CInPacket& packet);                  // 0x3d mode 8
    void OnFieldPortal(CInPacket& packet);                  // 0x48
    void OnJob(CInPacket& packet);                  // 0x49
    void OnBuff(CInPacket& packet);                  // 0x47
    void FUN_141720c60(CInPacket& packet);                  // 0x130
    void OnRegionSkill(CInPacket& packet);                  // 0x4c
    void OnTrigger(CInPacket& packet);                  // 0x4e
    void OnFunctionCube(CInPacket& packet);                  // 0x4d
    void OnBreakable(CInPacket& packet);                  // 0x4f
    void OnTombstone(CInPacket& packet);                  // 0x5d
    void OnUserState(CInPacket& packet);                  // 0x36
    void OnUserMoveByPortal(CInPacket& packet);                  // 0x5f
    void OnBuddy(CInPacket& packet);                  // 0x61
    void OnAdminBlock(CInPacket& packet);                  // 0x62
    void OnMail(CInPacket& packet);                  // 0x54
    void OnMassiveEvent(CInPacket& packet);                  // 0x60
    void OnStateConsumeEp(CInPacket& packet);                  // 0x64
    void OnStateFallDamage(CInPacket& packet);                  // 0x65
    void OnCinematic(CInPacket& packet);                  // 0x66
    void OnAdmin(CInPacket& packet);                  // 0x67
    void OnFollowNpc(CInPacket& packet);                  // 0x70
    void OnCubeCraftInfo(CInPacket& packet);                  // (cube item placed by an actor)
    void OnSetCraftMode(CInPacket& packet);                  // 0x68
    void OnResponseCube(CInPacket& packet);                  // 0x69
    void OnLoadCubes(CInPacket& packet);                  // 0x6a
    void OnNotice(CInPacket& packet);                  // 0x71
    void OnLiftable(CInPacket& packet);                  // 0x73
    void OnItemFusion(CInPacket& packet);                  // 0x74
    void OnVibrate(CInPacket& packet);                  // 0x75
    void OnHideVibrate(CInPacket& packet);                  // 0x76
    void OnShowVibrate(CInPacket& packet);                  // 0x77
    void OnResponseRide(CInPacket& packet);                  // 0x79
    void OnFittingDoll(CInPacket& packet);                  // 0x7b
    void OnGuideObject(CInPacket& packet);                  // 0x6e
    void OnInteractObject(CInPacket& packet);                  // 0x63
    void OnSkillCooldown(CInPacket& packet);                  // 0x42
    void OnSkillResetCooldown(CInPacket& packet);                  // 0x43
    void OnSkillPoint(CInPacket& packet);                  // 0x44
    void OnAttributePoint(CInPacket& packet);                  // 0x45
    void FUN_14172f500(CInPacket& packet);                  // 0x7e
    void OnBadgeEquip(CInPacket& packet);                  // 0x7f
    void OnGuideRecord(CInPacket& packet);                  // 0x89
    void FUN_141731190(CInPacket& packet);                  // 0x94
    void OnPlayNpcSound(CInPacket& packet);                  // 0x95
    void OnTaxi(CInPacket& packet);                  // 0x80
    void OnFindFields(CInPacket& packet);                  // 0x81
    void OnInvincibleEffect(CInPacket& packet);                  // 0x83
    void OnDpsStat(CInPacket& packet);                  // 0x86
    void OnItemDismantle(CInPacket& packet);                  // 0x96
    void OnItemLock(CInPacket& packet);                  // 0xdb
    void OnCharacterList(CInPacket& packet);                  // 0xc
    void OnRecallUser(CInPacket& packet);                  // 0x8c
    void OnPvp(CInPacket& packet);                  // 0xb6
    void OnFieldMaid(CInPacket& packet);                  // 0x9d
    void OnUserMaid(CInPacket& packet);                  // 0x9e
    void OnItemEnchant(CInPacket& packet);                  // 0x97
    void OnWebOpen(CInPacket& packet);                  // 0x9b
    void OnNewsNotification(CInPacket& packet);                  // 0x9f
    void OnSystemShop(CInPacket& packet);                  // 0xa1
    void OnAutoRevive(CInPacket& packet);                  // 0xa2
    void OnPlayerKillNotice(CInPacket& packet);                  // 0xa3
    void OnWorldShareInfo(CInPacket& packet);                  // 0xb0
    void OnNametag(CInPacket& packet);                  // 0xb1
    void OnSetPcbang(CInPacket& packet);                  // 0xb5
    void OnHomeCommand(CInPacket& packet);                  // 0xb7
    void OnWorld(CInPacket& packet);                  // 0xb9
    void OnItemDropNotice(CInPacket& packet);                  // 0xba
    void OnRecallScroll(CInPacket& packet);                  // 0xbc
    void FUN_141734930(CInPacket& packet);                  // 0xbe
    void OnEnchantScroll(CInPacket& packet);                  // 0xbf
    void OnGlobalPortal(CInPacket& packet);                  // 0xc1
    void OnQuizEvent(CInPacket& packet);                  // 0xc2
    void OnPlaySystemSound(CInPacket& packet);                  // 0xc3
    void OnFishing(CInPacket& packet);                  // 0xc4
    void OnDarkStream(CInPacket& packet);                  // 0xc5
    void OnPlayArcade(CInPacket& packet);                  // 0xd8
    void OnPlayInstrument(CInPacket& packet);                  // 0xc7
    void OnFieldProperty(CInPacket& packet);                  // 0xca
    void OnGameEventUserValue(CInPacket& packet);                  // 0xcb
    void OnMastery(CInPacket& packet);                  // 0xcd
    void OnEventReward(CInPacket& packet);                  // 0xf7
    void FUN_141736240(CInPacket& packet);                  // 0xf9
    void OnDeadUser(CInPacket& packet);                  // 0xa6
    void OnUserEnv(CInPacket& packet);                  // 0xa8
    void OnRoomDungeon(CInPacket& packet);                  // 0x1a
    void OnEnterUgcMap(CInPacket& packet);                  // 0xaa
    void OnSkillMacro(CInPacket& packet);                  // 0xd1
    void OnCheckCharNameResult(CInputStream& in);                   // 0xd3
    void OnGlobalFactor(CInPacket& packet);                  // 0xd6
    void OnSmartPush(CInPacket& packet);                  // 0xd7
    void OnHomeBank(CInPacket& packet);                  // 0xdc
    void OnHomeDoctor(CInPacket& packet);                  // 0xdd
    void OnNpcNotice(CInPacket& packet);                  // 0xe8
    void OnNpcRide(CInPacket& packet);                  // 0xe7
    void OnHomeAction(CInPacket& packet);                  // 0xea
    void OnItemUse(CInPacket& packet);                  // 0xab
    void OnItemBox(CInPacket& packet);                  // 0xac
    void OnPremiumClub(CInPacket& packet);                  // 0xeb
    void FUN_14173a0d0(CInPacket& packet);                  // 0xec
    void OnItemOptionSimulator(CInPacket& packet);                  // 0x101
    void OnLocalCamera(CInPacket& packet);                  // 0xe9
    void OnOneTimeEffect(CInPacket& packet);                  // 0xf1
    void OnCameraInterpolation(CInPacket& packet);                  // 0xf2
    void OnTimeScale(CInPacket& packet);                  // 0xf3
    void OnLegionBattle(CInPacket& packet);                  // 0xf4
    void OnHomeInvite(CInPacket& packet);                  // 0xf8
    void OnHomeInviteRequest(CInPacket& packet);                  // mode 2
    void OnHomeInviteResult(CInPacket& packet);                  // mode 0
    void OnStateFishingData(CInPacket& packet);                  // 0xfa
    void OnDungeonReviveCount(CInPacket& packet);                  // 0xfb
    void OnUgcItemTitle(CInPacket& packet);                  // 0xfd
    void OnChangeBackground(CInPacket& packet);                  // 0xfe
    void OnBindItem(CInPacket& packet);                  // 0x103
    void FUN_14173b5a0(CInPacket& packet);                  // 0x105
    void OnGmCommand(CInPacket& packet);                  // 0x106
    void FUN_14173c0f0(CInPacket& packet);                  // 0x106 mode 1
    void OnActiveCodiTab(CInPacket& packet);                  // 0x141739910 sub-handler (codi tab activated)
    void FUN_141715860(CInPacket& packet);  // 0x141713fb0 sub-handler (mode 8, item list)
    void SendBeauty(CInPacket& packet);                  // 0x141739910 sub-handler (beauty shop open)
    void OnBirthdayCard(CInPacket& packet);                  // 0x111
    void OnReactor(CInPacket& packet);                  // 0x115
    void OnTreeWatering(CInPacket& packet);                  // 0x118
    void OnSpectateMushtopia(CInPacket& packet);                  // 0x11a
    void OnLapenshard(CInPacket& packet);                  // 0x11b
    void OnPrestige(CInPacket& packet);                  // 0x11c
    void FUN_14173ddf0(CInPacket& packet);                  // 0x120
    void OnMinimapPing(CInPacket& packet);                  // 0x121
    void OnAppendClientLog(CInPacket& packet);                  // 0x91
    void OnFieldWar(CInPacket& packet);                  // 0x11f
    void OnChatStamp(CInPacket& packet);                  // 0x126
    void OnDungeonMatch(CInPacket& packet);                  // 0xef
    void OnItemScript(CInPacket& packet);                  // 0xf5
    void OnHideAndSeek(CInPacket& packet);                  // 0x12b
    void OnMessengerBrowserStamp(CInPacket& packet);                  // 0x12c
    void OnLimitBreak(CInPacket& packet);                  // 0x12e
    void OnWaterGunSkill(CInPacket& packet);                  // 0x12f
    void OnItemSocketSystem(CInPacket& packet);                  // 0xde
    void FUN_14173f7c0(CInPacket& packet);                  // 0x131
    void FUN_14173f810(CInPacket& packet);                  // 0x135
    void FUN_14173f860(CInPacket& packet);                  // 0x136
    void OnHomeBlock(CInPacket& packet);                  // 0x138
    void FUN_14173fc40(CInPacket& packet);                  // 0x139

    // helpers
    void FUN_1417127b0(CInPacket& packet, PCBase* pActor);    // read an actor's skill/buff list
    void FUN_141739450(bool bFlag);                         // spawn the taxi-station markers
    void FUN_141738240(CInPacket& packet);                  // (no dispatch case: reads the mode byte only)
    void FUN_141739220(CInPacket& packet);                  // 0xea sub-handler: formatted notice
    void RefreshIndividualPvPDialog();                                   // refresh the individual pvp dialog
    void StopTaxiEffect();                                   // drop the taxi effect (m_nTaxiEffect)
    int CheckDebugKeyCombo();                                    // Ctrl+Alt+... debug key combination
    void FUN_14173feb0();                                   // the debug key action
    void SendRequestHome(const CStringW& strName, int nType); // send packet 0x51 (mode 0, name, type)
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
