// cgameeventvaluemanager.h - PLACEHOLDER for CGameEventValueManager (RTTI .?AVCGameEventValueManager@@, 0x1480 bytes). NOT an original header.
// Bases: TSingleton<CGameEventValueManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Member offsets and sizes come from the ctor (one
// member ctor call per field); most members are an event value guarded by its own CLockCriticalSection.
//
// Two views of the same layout (both checked with MS2_CHECK_OFFSET):
// - the default, opaque view: the getters are the inline COMDATs the gameevent.cpp code calls (unit_1403e9650; their
//   names are invented from the calling GameEvent* class and fit the COMDAT name order), and the values are
//   Unk_GameEventLockedValue<N> blobs those units pass to the FUN_ externs of gameeventvalue.cpp;
// - with MS2_GAMEEVENTVALUE_TYPES defined before the include (?\gameeventvaluemanager.cpp), the real member types of
//   commonfiles/gameeventvalue.h and cshutdownevent.h, so the ctor / dtor construct and destroy them. That view can't
//   be the only one yet: gameevent.cpp defines its own partial copies of some of those types.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cshutdownevent.h"

#ifdef MS2_GAMEEVENTVALUE_TYPES
#include "ms2/commonfiles/gameeventvalue.h"

// The shut down id sets of the manager (+0x1240..+0x1400; commonfiles\shutdowneventvalue.cpp, ctors 0x1407d1650..
// 0x1407d21b0, one per class; the implicit dtors are COMDATs of the manager TU). No vftable, so no RTTI name: the
// names are invented. Billboard / UGCBanner / UGCUpload are the GameEventShutdown* events that write them, the
// others are named to fit the exe's dtor COMDAT order (mangled-name sorted: ...ItemTransfer < KeySetA < KeySetB <
// KeySetC < Quest < Set1300 < UGCBanner < UGCUpload < UnkDualSet). All set<unsigned int> (ctor 0x140182e30, dtor
// 0x140183b40) except UGCUpload and the dual set.
#define MS2_SHUTDOWN_ID_SET(name, ctor)                                                                       \
    class name {                                                                                              \
    public:                                                                                                   \
        name();                                                                                               \
        CLockCriticalSection m_lock;                                                                          \
        std::set<unsigned> m_ids;                                                                             \
    };                                                                                                        \
    MS2_CHECK_SIZE(name, 0x40);
MS2_SHUTDOWN_ID_SET(CShutdownEventKeySetA, 0x1407d1650)     // +0x1240
MS2_SHUTDOWN_ID_SET(CShutdownEventKeySetB, 0x1407d17b0)     // +0x12c0
MS2_SHUTDOWN_ID_SET(CShutdownEventKeySetC, 0x1407d1910)     // +0x1280
MS2_SHUTDOWN_ID_SET(CShutdownEventSet1300, 0x1407d1a70)     // +0x1300
MS2_SHUTDOWN_ID_SET(CShutdownEventBillboard, 0x1407d1be0)   // +0x1340 (GameEventShutdownBillboard)
MS2_SHUTDOWN_ID_SET(CShutdownEventUGCBanner, 0x1407d1d40)   // +0x1380 (GameEventShutdownUGCBanner)
#undef MS2_SHUTDOWN_ID_SET

// The UGC upload kind and the shut down kinds per event (same names and layout as in gameevent.cpp, which builds one
// for 0x1407d1ef0; ~Unk_ShutdownUGCUploadInfo is 0x1403e5b20).
enum Unk_UGCUploadType
{
};
struct Unk_ShutdownUGCUploadInfo
{
    Unk_ShutdownUGCUploadInfo() : m_bFlag(0) {}
    std::set<Unk_UGCUploadType> m_ids;          // +0x00
    BOOL m_bFlag;                               // +0x10
};
// +0x13c0: the shut down UGC upload kinds by event id (GameEventShutdownUGCUpload).
class CShutdownEventUGCUpload {
public:
    CShutdownEventUGCUpload();                  // 0x1407d1ea0
    CLockCriticalSection m_lock;
    std::map<unsigned, Unk_ShutdownUGCUploadInfo> m_events;   // the key is unsigned (less<unsigned> in 0x1407d1f70)
};
MS2_CHECK_SIZE(CShutdownEventUGCUpload, 0x40);

// +0x1400: two id sets over two enum key kinds (their set ctors 0x1407d9450 / 0x1407d9420 are not the int / unsigned
// ones; 0x1407d22e0 also matches key 0 = all).
enum Unk_ShutdownDualKeyA
{
};
enum Unk_ShutdownDualKeyB
{
};
class CShutdownEventUnkDualSet {
public:
    CShutdownEventUnkDualSet();                 // 0x1407d21b0
    CLockCriticalSection m_lock;
    std::set<Unk_ShutdownDualKeyA> m_first;     // +0x30
    std::set<Unk_ShutdownDualKeyB> m_second;    // +0x40
};
MS2_CHECK_SIZE(CShutdownEventUnkDualSet, 0x50);
#endif

// An event value behind its own lock; N is the total size. Value layout not recovered.
template <int N>
struct Unk_GameEventLockedValue
{
    CLockCriticalSection m_lock;
    char m_pad_30[N - 0x30];
};
// A plain int setting (its ctor zeroes it: 0x1404240b0, 0x1404287f0).
struct Unk_GameEventIntValue
{
    int m_value;
};

class CGameEventValueManager : public TSingleton<CGameEventValueManager>
{
public:
    CGameEventValueManager();                               // 0x14046c710
    virtual ~CGameEventValueManager();                      // 0x14046cc20
#ifdef MS2_GAMEEVENTVALUE_TYPES
    CShutdownEventValue* GetShutdownValue(int nKind);       // 0x14046d0d0 (name invented)
private:
    MS2_LAYOUT_FRIEND;
    Unk_GameEventValue8 m_8;                                // +0x8
    Unk_GameEventValueSum m_40;                             // +0x40
    Unk_GameEventValue88 m_88;                              // +0x88
    Unk_GameEventValueDungeonGroup m_dungeonGroup;          // +0xc0
    CGameEventValueGuildSkillSale m_guildSkillSale;         // +0x100
    CGameEventValueGuildPersonalSkillSale m_guildPersonalSkillSale; // +0x138
    CGameEventValueGuildExp m_guildExp;                     // +0x170
    CGameEventValueGuildFund m_guildFund;                   // +0x1a8
    CGameEventValueGuildCoin m_guildCoin;                   // +0x1e0
    CGameEventValueMasteryReward m_masteryReward;           // +0x218
    Unk_GameEventValue258 m_258;                            // +0x258
    CGameEventValueMeratMarketOpenTab m_meratMarketOpenTab; // +0x290
    CGameEventValueMasteryReduce m_masteryReduce;           // +0x2c8
    Unk_GameEventValueIdLists m_2d0;                        // +0x2d0
    CGameEventValueItemBox m_itemBox;                       // +0x348
    CGameEventValueSaleItemsRestricted m_saleItemsRestricted; // +0x388
    Unk_GameEventValue408 m_408;                            // +0x408
    CGameEventValueDungeonHelperBonus m_dungeonHelperBonus; // +0x410
    CGameEventValueMentoring m_mentoring;                   // +0x448
    CGameEventValueDungeonBuff m_dungeonBuff;               // +0x458
    CGameEventValueBattlePetSpawn m_battlePetSpawn;         // +0x4a8
    CGameEventValueIDIPEvent m_idipEvent;                   // +0x5e8
    CGameEventValueStarShop m_starShop;                     // +0x660
    CGameEventValueNpcShopTalk m_npcShopTalk;               // +0x698
    CGameEventValueNpcShopGivePoint m_npcShopGivePoint;     // +0x710
    CGameEventValueNpcShopResetPriceSale m_npcShopResetPriceSale; // +0x788
    CGameEventValueDungeonOpenPeriod m_dungeonOpenPeriod;   // +0x800
    Unk_GameEventValueIdSet m_878;                          // +0x878
    Unk_GameEventValueDayItem m_8b8;                        // +0x8b8
    Unk_GameEventValueFieldObjectDrop m_930;                // +0x930
    Unk_GameEventValueFieldObjectDropList m_9a8;            // +0x9a8
    Unk_GameEventValueFieldObjectDropList2 m_a20;           // +0xa20
    CGameEventValueBurningLevelup m_burningLevelup;         // +0xa98
    CGameEventValuePublicTest m_publicTest;                 // +0xad8
    CGameEventValueCoupleDance m_coupleDance;               // +0xae0
    CGameEventValueFestival m_festival;                     // +0xb20
    CGameEventValueFieldEffect m_fieldEffect;               // +0xb98
    CGameEventValueExchangeScrollSale m_exchangeScrollSale; // +0xbd8
    Unk_GameEventValueC50 m_c50;                            // +0xc50
    CGameEventValueItemTradeRestriction m_itemTradeRestriction; // +0xc98
    CGameEventValueCollectItemGroup m_collectItemGroup;     // +0xcf8
    CGameEventValueArcadeOpen m_arcadeOpen;                 // +0xd38
    CGameEventValueBingo m_bingoEvent;                      // +0xd78
    CGameEventValueLimitedQuantity m_limitedQuantity;       // +0xdb8
    CGameEventValueEventShopNpc m_eventShopNpc;             // +0xe08
    CShutdownEventDropBox m_shutdownDropBox;                // +0xe58
    CShutdownEventInteractObject m_shutdownInteractObjectId; // +0xeb0
    CShutdownEventQuest m_shutdownQuest;                    // +0xf08
    CShutdownEventItemTransfer m_shutdownItemTransfer;      // +0xfe0
    CShutdownEventFunctionItem m_shutdownFunctionItem;      // +0x1070
    CShutdownEventKeyCountMapUInt m_shutdownSkillItem;      // +0x10c8
    CShutdownEventCoupleEmotion m_shutdownCoupleEmotion;    // +0x1120
    CShutdownEventItemRemakeOption m_shutdownItemRemakeOption; // +0x11b0
    CShutdownEventKeySetA m_1240;                           // +0x1240
    CShutdownEventKeySetC m_1280;                           // +0x1280
    CShutdownEventKeySetB m_12c0;                           // +0x12c0
    CShutdownEventSet1300 m_1300;                           // +0x1300
    CShutdownEventBillboard m_shutdownBillboard;            // +0x1340
    CShutdownEventUGCBanner m_shutdownUGCBanner;            // +0x1380
    CShutdownEventUGCUpload m_shutdownUGCUpload;            // +0x13c0
    CShutdownEventUnkDualSet m_1400;                        // +0x1400
    CShutdownEventGroup m_shutdownGroup;                    // +0x1450
#else
    // @0x1403eead0
    Unk_GameEventLockedValue<0x38>* GuildSkillSale() { return &m_guildSkillSale; }
    // @0x1403eeab0
    Unk_GameEventLockedValue<0x38>* GuildPersonalSkillSale() { return &m_guildPersonalSkillSale; }
    // @0x1403eea70
    Unk_GameEventLockedValue<0x38>* GuildExp() { return &m_guildExp; }
    // @0x1403eea90
    Unk_GameEventLockedValue<0x38>* GuildFund() { return &m_guildFund; }
    // @0x1403eea50
    Unk_GameEventLockedValue<0x38>* GuildCoin() { return &m_guildCoin; }
    // @0x1403ef680
    Unk_GameEventLockedValue<0x40>* MasteryReward() { return &m_masteryReward; }
    // @0x1403ef710
    Unk_GameEventLockedValue<0x38>* MeratMarketOpenTab() { return &m_meratMarketOpenTab; }
    // @0x1403ef660
    Unk_GameEventIntValue* MasteryReduce() { return &m_masteryReduce; }
    // @0x1403ef3b0
    Unk_GameEventLockedValue<0x40>* ItemBox() { return &m_itemBox; }
    // @0x1403f27f0
    Unk_GameEventLockedValue<0x80>* SaleItemsRestricted() { return &m_saleItemsRestricted; }
    // @0x1403ec920
    Unk_GameEventLockedValue<0x38>* FindDungeonHelperBonus() { return &m_dungeonHelperBonus; }
    // @0x1403ed040
    Unk_GameEventLockedValue<0x140>* GetBattlePetSpawn() { return &m_battlePetSpawn; }
    // @0x1403ed9f0
    Unk_GameEventLockedValue<0x38>* GetStarShop() { return &m_starShop; }
    // @0x1403ed9a0
    Unk_GameEventLockedValue<0x78>* GetNpcShopTalk() { return &m_npcShopTalk; }
    // @0x1403ed960
    Unk_GameEventLockedValue<0x78>* GetNpcShopGivePoint() { return &m_npcShopGivePoint; }
    // @0x1403ed980
    Unk_GameEventLockedValue<0x78>* GetNpcShopResetPriceSale() { return &m_npcShopResetPriceSale; }
    // @0x1403ed170
    Unk_GameEventLockedValue<0x78>* GetDungeonOpenPeriod() { return &m_dungeonOpenPeriod; }
    // @0x1403ed080
    Unk_GameEventLockedValue<0x40>* GetBurningLevelup() { return &m_burningLevelup; }
    // @0x1403ed9c0
    Unk_GameEventIntValue* GetPublicTest() { return &m_publicTest; }
    // @0x1403ed140
    Unk_GameEventLockedValue<0x40>* GetCoupleDance() { return &m_coupleDance; }
    // @0x1403ed1b0
    Unk_GameEventLockedValue<0x78>* GetFestival() { return &m_festival; }
    // @0x1403ed1d0
    Unk_GameEventLockedValue<0x40>* GetFieldEffect() { return &m_fieldEffect; }
    // @0x1403ed190
    Unk_GameEventLockedValue<0x78>* GetExchangeScrollSale() { return &m_exchangeScrollSale; }
    // @0x1403ed2e0
    Unk_GameEventLockedValue<0x60>* GetItemTradeRestriction() { return &m_itemTradeRestriction; }
    // @0x1403ed0a0
    Unk_GameEventLockedValue<0x40>* GetCollectItemGroup() { return &m_collectItemGroup; }
    // @0x1403ecfe0
    Unk_GameEventLockedValue<0x40>* GetArcadeOpen() { return &m_arcadeOpen; }
    // @0x1403ed060
    Unk_GameEventLockedValue<0x40>* GetBingoEvent() { return &m_bingoEvent; }
    // @0x140303530
    CShutdownEventDropBox* ShutdownDropBox() { return &m_shutdownDropBox; }
    // @0x1403f3230
    CShutdownEventInteractObject* ShutdownInteractObjectId() { return &m_shutdownInteractObjectId; }
    // @0x1403f3210
    CShutdownEventFunctionItem* ShutdownFunctionItem() { return &m_shutdownFunctionItem; }
    // @0x1403f3250
    CShutdownEventKeyCountMapUInt* ShutdownSkillItem() { return &m_shutdownSkillItem; }
    // @0x1403f31f0
    Unk_GameEventLockedValue<0x40>* ShutdownBillboard() { return &m_shutdownBillboard; }
    // @0x1403f3270
    Unk_GameEventLockedValue<0x40>* ShutdownUGCBanner() { return &m_shutdownUGCBanner; }
    // @0x1403f3290
    Unk_GameEventLockedValue<0x40>* ShutdownUGCUpload() { return &m_shutdownUGCUpload; }
private:
    MS2_LAYOUT_FRIEND;
    Unk_GameEventLockedValue<0x38> m_8;                // +0x8
    Unk_GameEventLockedValue<0x48> m_40;               // +0x40
    Unk_GameEventLockedValue<0x38> m_88;               // +0x88
    Unk_GameEventLockedValue<0x40> m_c0;               // +0xc0
    Unk_GameEventLockedValue<0x38> m_guildSkillSale;   // +0x100
    Unk_GameEventLockedValue<0x38> m_guildPersonalSkillSale; // +0x138
    Unk_GameEventLockedValue<0x38> m_guildExp;         // +0x170
    Unk_GameEventLockedValue<0x38> m_guildFund;        // +0x1a8
    Unk_GameEventLockedValue<0x38> m_guildCoin;        // +0x1e0
    Unk_GameEventLockedValue<0x40> m_masteryReward;    // +0x218
    Unk_GameEventLockedValue<0x38> m_258;              // +0x258
    Unk_GameEventLockedValue<0x38> m_meratMarketOpenTab; // +0x290
    Unk_GameEventIntValue m_masteryReduce;             // +0x2c8
    Unk_GameEventLockedValue<0x78> m_2d0;              // +0x2d0
    Unk_GameEventLockedValue<0x40> m_itemBox;          // +0x348
    Unk_GameEventLockedValue<0x80> m_saleItemsRestricted; // +0x388
    char m_pad_408[0x8];                               // +0x408
    Unk_GameEventLockedValue<0x38> m_dungeonHelperBonus; // +0x410
    char m_pad_448[0x10];                              // +0x448
    Unk_GameEventLockedValue<0x50> m_458;              // +0x458
    Unk_GameEventLockedValue<0x140> m_battlePetSpawn;  // +0x4a8
    Unk_GameEventLockedValue<0x78> m_5e8;              // +0x5e8
    Unk_GameEventLockedValue<0x38> m_starShop;         // +0x660
    Unk_GameEventLockedValue<0x78> m_npcShopTalk;      // +0x698
    Unk_GameEventLockedValue<0x78> m_npcShopGivePoint; // +0x710
    Unk_GameEventLockedValue<0x78> m_npcShopResetPriceSale; // +0x788
    Unk_GameEventLockedValue<0x78> m_dungeonOpenPeriod; // +0x800
    Unk_GameEventLockedValue<0x40> m_878;              // +0x878
    Unk_GameEventLockedValue<0x78> m_8b8;              // +0x8b8
    Unk_GameEventLockedValue<0x78> m_930;              // +0x930
    Unk_GameEventLockedValue<0x78> m_9a8;              // +0x9a8
    char m_pad_a20[0x78];                              // +0xa20
    Unk_GameEventLockedValue<0x40> m_burningLevelup;   // +0xa98
    Unk_GameEventIntValue m_publicTest;                // +0xad8
    Unk_GameEventLockedValue<0x40> m_coupleDance;      // +0xae0
    Unk_GameEventLockedValue<0x78> m_festival;         // +0xb20
    Unk_GameEventLockedValue<0x40> m_fieldEffect;      // +0xb98
    Unk_GameEventLockedValue<0x78> m_exchangeScrollSale; // +0xbd8
    Unk_GameEventLockedValue<0x48> m_c50;              // +0xc50
    Unk_GameEventLockedValue<0x60> m_itemTradeRestriction; // +0xc98
    Unk_GameEventLockedValue<0x40> m_collectItemGroup; // +0xcf8
    Unk_GameEventLockedValue<0x40> m_arcadeOpen;       // +0xd38
    Unk_GameEventLockedValue<0x40> m_bingoEvent;       // +0xd78
    Unk_GameEventLockedValue<0x50> m_db8;              // +0xdb8
    Unk_GameEventLockedValue<0x50> m_e08;              // +0xe08
    CShutdownEventDropBox m_shutdownDropBox;           // +0xe58
    CShutdownEventInteractObject m_shutdownInteractObjectId; // +0xeb0
    char m_pad_f08[0xd8];                              // +0xf08
    char m_pad_fe0[0x90];                              // +0xfe0
    CShutdownEventFunctionItem m_shutdownFunctionItem; // +0x1070
    CShutdownEventKeyCountMapUInt m_shutdownSkillItem; // +0x10c8
    char m_pad_1120[0x90];                             // +0x1120
    char m_pad_11b0[0x90];                             // +0x11b0
    Unk_GameEventLockedValue<0x40> m_1240;             // +0x1240
    Unk_GameEventLockedValue<0x40> m_1280;             // +0x1280
    Unk_GameEventLockedValue<0x40> m_12c0;             // +0x12c0
    Unk_GameEventLockedValue<0x40> m_1300;             // +0x1300
    Unk_GameEventLockedValue<0x40> m_shutdownBillboard; // +0x1340
    Unk_GameEventLockedValue<0x40> m_shutdownUGCBanner; // +0x1380
    Unk_GameEventLockedValue<0x40> m_shutdownUGCUpload; // +0x13c0
    Unk_GameEventLockedValue<0x50> m_1400;             // +0x1400
    char m_pad_1450[0x30];                             // +0x1450
#endif
};
MS2_CHECK_SIZE(CGameEventValueManager, 0x1480);
MS2_CHECK_OFFSET(CGameEventValueManager, m_dungeonHelperBonus, 0x410);
MS2_CHECK_OFFSET(CGameEventValueManager, m_arcadeOpen, 0xd38);
MS2_CHECK_OFFSET(CGameEventValueManager, m_shutdownSkillItem, 0x10c8);
MS2_CHECK_OFFSET(CGameEventValueManager, m_shutdownUGCUpload, 0x13c0);
#ifdef MS2_GAMEEVENTVALUE_TYPES
MS2_CHECK_OFFSET(CGameEventValueManager, m_dungeonBuff, 0x458);
MS2_CHECK_OFFSET(CGameEventValueManager, m_eventShopNpc, 0xe08);
MS2_CHECK_OFFSET(CGameEventValueManager, m_1400, 0x1400);
MS2_CHECK_OFFSET(CGameEventValueManager, m_shutdownGroup, 0x1450);
#endif
