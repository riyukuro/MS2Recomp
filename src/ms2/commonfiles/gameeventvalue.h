// gameeventvalue.h - the event value types of CGameEventValueManager (commonfiles\gameeventvalue.cpp). NOT an
// original header. Each value is a CLockCriticalSection (+0) and the state the GameEvent* handlers write (start / end)
// and the game reads. Sizes and order are the members of the manager (ctor 0x14046c710: one member ctor per value, in
// this order); CGameEventValueBattlePetSpawn, CGameEventValueIDIPEvent and CGameEventValueItemTradeRestriction (and
// their nested types) are RTTI names, the other class names are invented from the manager getters and the callers.
// The values without a dtor in the unit's main code have an implicit one (a COMDAT of the unit's tail).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/commonfiles/fieldmetatable.h"

// +0x8: a locked int (Get / Set).
class Unk_GameEventValue8 {
public:
    Unk_GameEventValue8();                          // 0x140422c10
    ~Unk_GameEventValue8();                         // 0x140422c50
    int GetValue();                                 // 0x140422c80
    void SetValue(int value);                       // 0x140422cd0
    CLockCriticalSection m_lock;
    int m_value;                                    // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValue8, 0x38);

// +0x40: the sum of the per-event values.
class Unk_GameEventValueSum {
public:
    Unk_GameEventValueSum();                        // 0x140422d20
    ~Unk_GameEventValueSum();                       // 0x140422d70
    int GetSum();                                   // 0x140422db0
    void SetValue(unsigned eventId, int value);     // 0x140422e00: 0 removes the event
    CLockCriticalSection m_lock;
    int m_sum;                                      // +0x30
    std::map<unsigned, unsigned> m_values; // +0x38 event id -> value
};
MS2_CHECK_SIZE(Unk_GameEventValueSum, 0x48);

// +0x88: a locked int.
class Unk_GameEventValue88 {
public:
    Unk_GameEventValue88();                         // 0x1404232d0
    ~Unk_GameEventValue88();                        // 0x140423310
    int GetValue();                                 // 0x140423340
    void SetValue(int value);                       // 0x140423390
    CLockCriticalSection m_lock;
    int m_value;                                    // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValue88, 0x38);

// +0xc0: two ints per dungeon group (1..14).
class Unk_GameEventValueDungeonGroup {
public:
    Unk_GameEventValueDungeonGroup();               // 0x140422f10
    ~Unk_GameEventValueDungeonGroup();              // 0x140422f60
    int GetFirst(Unk_DungeonGroupType type);        // 0x140422fa0: 0 without an entry
    int GetSecond(Unk_DungeonGroupType type, int nDefault); // 0x140423090: INT_MAX without an entry, nDefault for 0
    void Set(Unk_DungeonGroupType type, unsigned first, unsigned second);// 0x1404231b0: first 0 removes the entry
    CLockCriticalSection m_lock;
    std::map<Unk_DungeonGroupType, std::pair<int, int> > m_groups;     // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValueDungeonGroup, 0x40);

// +0x100..+0x1e0: the guild event rates (GameEventGuild* set them).
#define MS2_GE_GUILD_RATE(name, ctor, dtor, get, set)                                                         \
    class name {                                                                                              \
    public:                                                                                                   \
        name();                                                                                               \
        ~name();                                                                                              \
        int GetRate();                                                                                        \
        void SetRate(int rate);                                                                               \
        CLockCriticalSection m_lock;                                                                          \
        int m_rate;                                                                                           \
    };                                                                                                        \
    MS2_CHECK_SIZE(name, 0x38);
MS2_GE_GUILD_RATE(CGameEventValueGuildSkillSale, 0x1404233e0, 0x140423420, 0x140423450, 0x1404234a0)
MS2_GE_GUILD_RATE(CGameEventValueGuildPersonalSkillSale, 0x1404234f0, 0x140423530, 0x140423560, 0x1404235b0)
MS2_GE_GUILD_RATE(CGameEventValueGuildExp, 0x140423600, 0x140423640, 0x140423670, 0x1404236c0)
MS2_GE_GUILD_RATE(CGameEventValueGuildFund, 0x140423710, 0x140423750, 0x140423780, 0x1404237d0)
MS2_GE_GUILD_RATE(CGameEventValueGuildCoin, 0x140423820, 0x140423860, 0x140423890, 0x1404238e0)
#undef MS2_GE_GUILD_RATE

// +0x218: per event, the mastery reward rate of a (mastery type, field id).
class CGameEventValueMasteryReward {
public:
    typedef std::map<std::pair<int, unsigned long>, int> Rates;
    CGameEventValueMasteryReward();                 // 0x140423930
    ~CGameEventValueMasteryReward();                // 0x140423980
    int GetRate(int type, unsigned long fieldId);   // 0x1404239c0: the sum over the events
    void Load(unsigned long eventId, int type, const CStringW& strPath);   // 0x140423b10: <v fieldID= rate=/>
    void Remove(unsigned long eventId);             // 0x140423da0
    CLockCriticalSection m_lock;
    std::map<unsigned long, Rates> m_events;        // +0x30
};
MS2_CHECK_SIZE(CGameEventValueMasteryReward, 0x40);

// +0x258: a locked int.
class Unk_GameEventValue258 {
public:
    Unk_GameEventValue258();                        // 0x140423e60
    ~Unk_GameEventValue258();                       // 0x140423ea0
    int GetValue();                                 // 0x140423ed0
    void SetValue(int value);                       // 0x140423f40
    CLockCriticalSection m_lock;
    int m_value;                                    // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValue258, 0x38);

// +0x290: the merat market tab the event opens.
class CGameEventValueMeratMarketOpenTab {
public:
    CGameEventValueMeratMarketOpenTab();            // 0x140423fa0
    ~CGameEventValueMeratMarketOpenTab();           // 0x140423fe0
    const CStringW& GetTab();                       // 0x140424020 (no lock)
    void SetTab(const CStringW& strTab);            // 0x140424040
    CLockCriticalSection m_lock;
    CStringW m_tab;                                 // +0x30
};
MS2_CHECK_SIZE(CGameEventValueMeratMarketOpenTab, 0x38);

// +0x2c8: the mastery reduce rate (in 1/10000), no lock.
class CGameEventValueMasteryReduce {
public:
    CGameEventValueMasteryReduce();                 // 0x1404240b0
    ~CGameEventValueMasteryReduce();                // 0x1404240d0
    unsigned Apply(unsigned value);                 // 0x1404240e0
    void SetRate(int rate);                         // 0x140424130
    CStringW GetText();                             // 0x140424150 "s_mastery_reduce_event"
    int m_rate;
};
MS2_CHECK_SIZE(CGameEventValueMasteryReduce, 4);

// +0x2d0: id lists per key.
class Unk_GameEventValueIdLists {
public:
    Unk_GameEventValueIdLists();                    // 0x140424200
    ~Unk_GameEventValueIdLists();                   // 0x140424270
    void Add(unsigned key, unsigned id);            // 0x1404242b0
    bool Remove(unsigned key, unsigned id);         // 0x1404243c0: drops the key with its last id
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, Unk_FieldIdListPtr> m_lists;     // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValueIdLists, 0x78);

// +0x348: the item box events by field.
class CGameEventValueItemBox {
public:
    CGameEventValueItemBox();                       // 0x1404244f0
    ~CGameEventValueItemBox();                      // 0x140424540
    MS2Ptr<ItemBoxEventContext> Get(unsigned fieldId);          // 0x140424580
    bool Add(MS2Ptr<ItemBoxEventContext> spContext);            // 0x1404246b0: false for a known field
    void Remove(MS2Ptr<ItemBoxEventContext> spContext);         // 0x1404247e0
    CLockCriticalSection m_lock;
    std::map<unsigned, MS2Ptr<ItemBoxEventContext> > m_contexts;       // +0x30
};
MS2_CHECK_SIZE(CGameEventValueItemBox, 0x40);

// +0x388: the items the sale event restricts.
class CGameEventValueSaleItemsRestricted {
public:
    CGameEventValueSaleItemsRestricted();           // 0x140424870
    ~CGameEventValueSaleItemsRestricted();          // 0x1404248e0
    bool IsActive();                                // 0x140424920 (no lock)
    bool IsRestricted(unsigned itemId);             // 0x140424940
    void SetItems(ATL::CAtlArray<unsigned>& items); // 0x1404249f0
    void Clear();                                   // 0x140424ae0
    CLockCriticalSection m_lock;
    bool m_active;                                  // +0x30
    ATL::CAtlMap<unsigned, bool> m_items;           // +0x38
};
MS2_CHECK_SIZE(CGameEventValueSaleItemsRestricted, 0x80);

// +0x408: a flag and an int, no lock.
class Unk_GameEventValue408 {
public:
    Unk_GameEventValue408();                        // 0x140424b40
    ~Unk_GameEventValue408();                       // 0x140424b70
    bool IsSet();                                   // 0x140424b80
    unsigned GetValue();                            // 0x140424ba0
    void SetValue(unsigned value);                  // 0x140424bc0: a nonzero value sets the flag
    void Reset();                                   // 0x140424bf0
    bool m_set;
    unsigned m_value;                               // +0x4
};
MS2_CHECK_SIZE(Unk_GameEventValue408, 8);

// +0x410: the dungeon helper bonus (added / removed per event).
class CGameEventValueDungeonHelperBonus {
public:
    CGameEventValueDungeonHelperBonus();            // 0x140424c10
    ~CGameEventValueDungeonHelperBonus();           // 0x140424c50
    void Add(int bonus);                            // 0x140424c80
    void Sub(int bonus);                            // 0x140424cd0
    int GetBonus();                                 // 0x140424d20
    CLockCriticalSection m_lock;
    int m_bonus;                                    // +0x30
};
MS2_CHECK_SIZE(CGameEventValueDungeonHelperBonus, 0x38);

// +0x448: the mentoring event (GameEventReturnUser's context), no lock.
class CGameEventValueMentoring {
public:
    CGameEventValueMentoring();                     // 0x140424d70
    void Set(MS2Ptr<MentoringContext> spContext);   // 0x140424da0
    int GetId();                                    // 0x140424de0
    __int64 GetEndTime();                           // 0x140424e20
    __int64 GetBeginTime();                         // 0x140424e60
    void Reset();                                   // 0x140424ea0
    void GetIds(ATL::CAtlArray<unsigned>& ids);     // 0x140424ed0
    BOOL HasId(unsigned id);                        // 0x140424f20
    MS2Ptr<MentoringContext> m_spContext;
};
MS2_CHECK_SIZE(CGameEventValueMentoring, 0x10);

// +0x458: per dungeon, the reference counts of the buff GUIDs (normal / beginner).
class CGameEventValueDungeonBuff {
public:
    typedef std::map<unsigned __int64, unsigned> Counts;
    CGameEventValueDungeonBuff();                   // 0x140424f90
    void Add(unsigned long dungeonId, MS2Ptr<DungeonBuffEventCtx> spContext);     // 0x140424ff0
    void Remove(unsigned long dungeonId, MS2Ptr<DungeonBuffEventCtx> spContext);  // 0x140425150
    void GetBuffs(unsigned long dungeonId, std::set<unsigned __int64>& buffs);     // 0x1404252f0
    void GetBeginnerBuffs(unsigned long dungeonId, std::vector<unsigned __int64>& buffs); // 0x1404253c0
    CLockCriticalSection m_lock;
    std::map<unsigned long, Counts> m_buffs;            // +0x30
    std::map<unsigned long, Counts> m_beginnerBuffs;    // +0x40
};
MS2_CHECK_SIZE(CGameEventValueDungeonBuff, 0x50);

// +0x4a8: the battle pet spawn events by field.
class CGameEventValueBattlePetSpawn {
public:
    class SpawnContext : public CPtred {
    public:
        SpawnContext() : m_eventId(0), m_probability(0), m_count(0) {}    // 0x1404462b0
        int m_eventId;                              // +0x18
        unsigned m_probability;                     // +0x1c
        unsigned m_count;                           // +0x20
        int m_pad_24;
        ATL::CAtlArray<unsigned> m_petIds;          // +0x28
    };
    CGameEventValueBattlePetSpawn();                // 0x1404254a0
    void AddSpawn(int eventId, const CStringW& strValues);     // 0x1404255b0
    void RemoveSpawn(int eventId, const CStringW& strValues);  // 0x140425f40
    void AddImprove(unsigned eventId, const CStringW& strValues);   // 0x140426380
    void RemoveImprove(int eventId, const CStringW& strValues);     // 0x1404266f0
    __int64 GetTime(unsigned fieldId);              // 0x140426960: the spawn start or the last end time
    unsigned GetImproveProbability(unsigned fieldId);   // 0x140426a50: field 0 is the default
    MS2Ptr<SpawnContext> GetSpawn(unsigned fieldId);    // 0x140426b10
    void GetFields(unsigned petId, ATL::CAtlArray<unsigned>& fields);   // 0x140426bc0
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<SpawnContext> > m_spawns;                 // +0x30 field id ->
    ATL::CAtlMap<unsigned, std::pair<unsigned, unsigned> > m_improves;      // +0x78 field id -> (event id, probability)
    ATL::CRBMultiMap<unsigned, unsigned> m_petFields;                       // +0xc0 pet id -> field ids
    __int64 m_time;                                                         // +0xf0
    ATL::CAtlMap<unsigned, __int64> m_endTimes;                             // +0xf8
};
MS2_CHECK_SIZE(CGameEventValueBattlePetSpawn::SpawnContext, 0x48);
MS2_CHECK_SIZE(CGameEventValueBattlePetSpawn, 0x140);

// +0x5e8: the IDIP events.
class CGameEventValueIDIPEvent {
public:
    class IDIPEventContext : public CPtred {
    public:
        IDIPEventContext(int type, CMsTime time) : m_type(type), m_time(time) {}   // 0x140446240
        int m_type;                                 // +0x18
        int m_pad_1c;
        CMsTime m_time;                             // +0x20
    };
    CGameEventValueIDIPEvent();                     // 0x140426c90
    void Add(unsigned id, int type, const CMsTime& time);   // 0x140426d00
    void Remove(unsigned id);                       // 0x140426e00
    MS2Ptr<IDIPEventContext> Find(int type);        // 0x140426e70
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<IDIPEventContext> > m_events;     // +0x30
};
MS2_CHECK_SIZE(CGameEventValueIDIPEvent::IDIPEventContext, 0x30);
MS2_CHECK_SIZE(CGameEventValueIDIPEvent, 0x78);

// +0x660: the star shop event.
class CGameEventValueStarShop {
public:
    CGameEventValueStarShop();                      // 0x140426fb0
    void SetValue(int value);                       // 0x140426ff0
    int GetValue();                                 // 0x140427050 (no lock)
    CLockCriticalSection m_lock;
    int m_value;                                    // +0x30
};
MS2_CHECK_SIZE(CGameEventValueStarShop, 0x38);

// +0x698: the NPC shop talk events by NPC.
class CGameEventValueNpcShopTalk {
public:
    CGameEventValueNpcShopTalk();                   // 0x140427070
    void Set(unsigned npcId, unsigned value);       // 0x1404270e0
    void Remove(unsigned npcId);                    // 0x140427150
    unsigned Get(unsigned npcId);                   // 0x1404271c0
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, unsigned> m_values;      // +0x30
};
MS2_CHECK_SIZE(CGameEventValueNpcShopTalk, 0x78);

// +0x710: the NPC shop give point events.
class CGameEventValueNpcShopGivePoint {
public:
    CGameEventValueNpcShopGivePoint();              // 0x140427240
    void Set(unsigned id, MS2Ptr<CNpcShopGivePointContextBase> spContext);    // 0x1404272b0
    void Remove(unsigned id);                       // 0x140427330
    MS2Ptr<CNpcShopGivePointContextBase> Get(unsigned id);                    // 0x1404273a0
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<CNpcShopGivePointContextBase> > m_contexts; // +0x30
};
MS2_CHECK_SIZE(CGameEventValueNpcShopGivePoint, 0x78);

// +0x788: the NPC shop reset price sale events by NPC.
class CGameEventValueNpcShopResetPriceSale {
public:
    CGameEventValueNpcShopResetPriceSale();         // 0x140427450
    void Set(unsigned npcId, unsigned value);       // 0x1404274c0
    void Remove(unsigned npcId);                    // 0x140427530
    unsigned Get(unsigned npcId);                   // 0x1404275a0
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, unsigned> m_values;      // +0x30
};
MS2_CHECK_SIZE(CGameEventValueNpcShopResetPriceSale, 0x78);

// +0x800: the open periods by dungeon tag.
class CGameEventValueDungeonOpenPeriod {
public:
    typedef ATL::CAtlMap<CStringW, Unk_FieldTimeSpan, ATL::CStringElementTraits<CStringW> > Periods;
    CGameEventValueDungeonOpenPeriod();             // 0x140427620
    bool Add(CStringW strTag, __int64 beginTime, __int64 endTime);     // 0x140427690: false for a known tag
    void Remove(CStringW strTag);                   // 0x140427780
    bool IsOpen(CStringW strTag, __int64 time);     // 0x1404277f0
    bool GetPeriod(CStringW strTag, Unk_FieldTimeSpan& period);        // 0x1404278c0
    CLockCriticalSection m_lock;
    Periods m_periods;                              // +0x30
};
MS2_CHECK_SIZE(CGameEventValueDungeonOpenPeriod, 0x78);

// +0x878: a set of ids.
class Unk_GameEventValueIdSet {
public:
    Unk_GameEventValueIdSet();                      // 0x140427970
    void Add(unsigned id);                          // 0x1404279c0
    void Remove(unsigned id);                       // 0x140427a20
    bool IsActive();                                // 0x140427a80: not empty
    CLockCriticalSection m_lock;
    std::set<unsigned> m_ids;                       // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValueIdSet, 0x40);

// +0x8b8 / +0x930 / +0x9a8 (+0xa20): the setting maps of the three context types the client never builds.
class Unk_GameEventValueDayItem {
public:
    Unk_GameEventValueDayItem();                    // 0x140427af0
    void Add(unsigned id, Unk_DayItemContext* pContext);    // 0x140427b60
    void Remove(unsigned id);                       // 0x140427be0
    void GetContexts(ATL::CAtlList<MS2Ptr<Unk_DayItemContext> >& contexts, bool bAll);   // 0x140427c30: active ones
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<Unk_DayItemContext> > m_contexts;     // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValueDayItem, 0x78);
class Unk_GameEventValueFieldObjectDrop {
public:
    Unk_GameEventValueFieldObjectDrop();            // 0x140427d20
    void Add(unsigned id, Unk_FieldObjectDropContext* pContext);    // 0x140427d90
    void Remove(unsigned id);                       // 0x140427e10
    void GetContexts(ATL::CAtlList<MS2Ptr<Unk_FieldObjectDropContext> >& contexts);  // 0x140427e60
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<Unk_FieldObjectDropContext> > m_contexts;     // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValueFieldObjectDrop, 0x78);
class Unk_GameEventValueFieldObjectDropList {
public:
    Unk_GameEventValueFieldObjectDropList();        // 0x140427f30
    void Add(unsigned id, Unk_FieldObjectDropListContext* pContext);    // 0x140427fa0
    void Remove(unsigned id);                       // 0x140428020
    void GetContexts(ATL::CAtlList<MS2Ptr<Unk_FieldObjectDropListContext> >& contexts);  // 0x140428070
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<Unk_FieldObjectDropListContext> > m_contexts; // +0x30
};
MS2_CHECK_SIZE(Unk_GameEventValueFieldObjectDropList, 0x78);
class Unk_GameEventValueFieldObjectDropList2 : public Unk_GameEventValueFieldObjectDropList {
public:
    Unk_GameEventValueFieldObjectDropList2();       // 0x140428140
};
MS2_CHECK_SIZE(Unk_GameEventValueFieldObjectDropList2, 0x78);

// +0xa98: the burning level-up events.
class CGameEventValueBurningLevelup {
public:
    CGameEventValueBurningLevelup();                // 0x140428170
    ~CGameEventValueBurningLevelup();               // 0x1404281c0
    MS2Ptr<BurningLevelupContext> Get(unsigned eventId);       // 0x140428200
    void GetAll(std::list<MS2Ptr<BurningLevelupContext> >& contexts);     // 0x140428300
    void Add(MS2Ptr<BurningLevelupContext> spContext);         // 0x1404283e0
    void Remove(MS2Ptr<BurningLevelupContext> spContext);      // 0x1404284a0
    MS2Ptr<BurningLevelupContext> FindByTarget(int id);        // 0x140428510
    CLockCriticalSection m_lock;
    std::map<unsigned, MS2Ptr<BurningLevelupContext> > m_contexts;        // +0x30
};
MS2_CHECK_SIZE(CGameEventValueBurningLevelup, 0x40);

// +0xae0: the couple dance event.
class CGameEventValueCoupleDance {
public:
    CGameEventValueCoupleDance();                   // 0x140428670
    ~CGameEventValueCoupleDance();                  // 0x1404286c0
    MS2Ptr<CoupleDanceContext> Get();               // 0x140428700
    void Set(MS2Ptr<CoupleDanceContext> spContext); // 0x140428780
    CLockCriticalSection m_lock;
    MS2Ptr<CoupleDanceContext> m_spContext;         // +0x30
};
MS2_CHECK_SIZE(CGameEventValueCoupleDance, 0x40);

// +0xad8: the public test flag, no lock.
class CGameEventValuePublicTest {
public:
    CGameEventValuePublicTest();                    // 0x1404287f0
    void SetValue(int value);                       // 0x140428810
    int GetValue();                                 // 0x140428830
    int m_value;
};
MS2_CHECK_SIZE(CGameEventValuePublicTest, 4);

// +0xb20: the festival events.
class CGameEventValueFestival {
public:
    CGameEventValueFestival();                      // 0x140428850
    void GetAll(ATL::CAtlArray<MS2Ptr<FestivalContext> >& contexts);  // 0x1404288d0
    void Add(unsigned id, MS2Ptr<FestivalContext> spContext);         // 0x140428980
    void Remove(unsigned id);                       // 0x1404289f0
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned, MS2Ptr<FestivalContext> > m_contexts;      // +0x30
};
MS2_CHECK_SIZE(CGameEventValueFestival, 0x78);

// +0xb98: the field effect event.
class CGameEventValueFieldEffect {
public:
    CGameEventValueFieldEffect();                   // 0x140428a40
    MS2Ptr<FieldEffectContext> Get();               // 0x140428a90
    void Set(MS2Ptr<FieldEffectContext> spContext); // 0x140428b10
    CLockCriticalSection m_lock;
    MS2Ptr<FieldEffectContext> m_spContext;         // +0x30
};
MS2_CHECK_SIZE(CGameEventValueFieldEffect, 0x40);

// +0xbd8: the exchange scroll sale rates by item.
class CGameEventValueExchangeScrollSale {
public:
    CGameEventValueExchangeScrollSale();            // 0x140428b80
    void Set(unsigned long itemId, int rate);       // 0x140428bf0
    void Remove(unsigned long itemId);              // 0x140428c60
    int Get(unsigned long itemId);                  // 0x140428cb0
    CLockCriticalSection m_lock;
    ATL::CAtlMap<unsigned long, int> m_rates;       // +0x30
};
MS2_CHECK_SIZE(CGameEventValueExchangeScrollSale, 0x78);

// +0xc50: a time window and an int.
class Unk_GameEventValueC50 {
public:
    Unk_GameEventValueC50();                        // 0x140428d30
    void Set(__int64 beginTime, __int64 endTime, int value);   // 0x140428d80
    void Clear();                                   // 0x140428df0
    bool Get(__int64& beginTime, __int64& endTime, int& value);    // 0x140428e50: false when unset
    CLockCriticalSection m_lock;
    __int64 m_beginTime;                            // +0x30
    __int64 m_endTime;                              // +0x38
    int m_value;                                    // +0x40
};
MS2_CHECK_SIZE(Unk_GameEventValueC50, 0x48);

// +0xc98: the item trade restriction events.
class CGameEventValueItemTradeRestriction {
public:
    class RestrictionData : public CPtred {
    public:
        RestrictionData();                          // 0x140428f00
        explicit RestrictionData(Unk_VftableEmitTag) {}   // not exe code: emits the vftable in unit_14044a880
        void SetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId, unsigned short limit);  // 0x1404290b0
        unsigned short GetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId);           // 0x1404291d0
        typedef ATL::CAtlMap<unsigned, unsigned short> Limits;   // item id -> limit
        Limits m_blackMarketSell;                   // +0x18 one per Unk_ItemTradeRestrictionType
        Limits m_blackMarketBuy;                    // +0x60
        Limits m_tradeSend;                         // +0xa8
        Limits m_tradeRecv;                         // +0xf0
        Limits m_dropItem;                          // +0x138
        Limits m_pickupItem;                        // +0x180
    };
    CGameEventValueItemTradeRestriction();          // 0x1404292f0
    void Add(unsigned eventId, const MS2Ptr<RestrictionData>& spData);     // 0x140429330
    void Remove(unsigned eventId);                  // 0x1404293a0
    unsigned short GetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId);   // 0x140429410: first event's
    CLockCriticalSection m_lock;
    ATL::CRBMap<unsigned, MS2Ptr<RestrictionData> > m_events;  // +0x30
};
MS2_CHECK_SIZE(CGameEventValueItemTradeRestriction::RestrictionData, 0x1c8);
MS2_CHECK_SIZE(CGameEventValueItemTradeRestriction, 0x60);

// +0xcf8: the collect item group events.
class CGameEventValueCollectItemGroup {
public:
    CGameEventValueCollectItemGroup();              // 0x140429500
    ~CGameEventValueCollectItemGroup();             // 0x140429550
    MS2Ptr<CollectItemGroupContext> Get(unsigned eventId);            // 0x140429590
    void GetAll(std::vector<MS2Ptr<CollectItemGroupContext> >& contexts);     // 0x140429690
    void Add(MS2Ptr<CollectItemGroupContext> spContext);           // 0x140429770
    void Remove(MS2Ptr<CollectItemGroupContext> spContext);        // 0x140429830
    CLockCriticalSection m_lock;
    std::map<unsigned, MS2Ptr<CollectItemGroupContext> > m_contexts;               // +0x30
};
MS2_CHECK_SIZE(CGameEventValueCollectItemGroup, 0x40);

// +0xd38: the arcade open events by arcade.
class CGameEventValueArcadeOpen {
public:
    CGameEventValueArcadeOpen();                    // 0x1404298a0
    ~CGameEventValueArcadeOpen();                   // 0x1404298f0
    MS2Ptr<ArcadeOpenContext> Get(int arcadeId);    // 0x140429930
    bool Add(MS2Ptr<ArcadeOpenContext> spContext);  // 0x140429a30: false for a known arcade
    void Remove(MS2Ptr<ArcadeOpenContext> spContext);   // 0x140429b80
    CLockCriticalSection m_lock;
    std::map<int, MS2Ptr<ArcadeOpenContext> > m_contexts;  // +0x30
};
MS2_CHECK_SIZE(CGameEventValueArcadeOpen, 0x40);

// +0xd78: the bingo event.
class CGameEventValueBingo {
public:
    CGameEventValueBingo();                         // 0x140429bf0
    ~CGameEventValueBingo();                        // 0x140429c40
    MS2Ptr<BingoContext> Get();                     // 0x140429c80
    void Set(MS2Ptr<BingoContext> spContext);       // 0x140429d00: ignores NULL
    void Clear(MS2Ptr<BingoContext> spContext);     // 0x140429d90: only the current one
    CLockCriticalSection m_lock;
    MS2Ptr<BingoContext> m_spContext;               // +0x30
};
MS2_CHECK_SIZE(CGameEventValueBingo, 0x40);

// +0xdb8: the limited quantity events (by event id and by the +0x1c key).
class CGameEventValueLimitedQuantity {
public:
    CGameEventValueLimitedQuantity();               // 0x140429e20
    ~CGameEventValueLimitedQuantity();              // 0x140429e80
    MS2Ptr<LimitedQuantityContext> Get(unsigned eventId);          // 0x140429ed0
    MS2Ptr<LimitedQuantityContext> GetByKey(unsigned key);         // 0x140429fd0
    void Add(MS2Ptr<LimitedQuantityContext> spContext);            // 0x14042a0e0
    void Remove(MS2Ptr<LimitedQuantityContext> spContext);         // 0x14042a260
    CLockCriticalSection m_lock;
    std::map<unsigned, MS2Ptr<LimitedQuantityContext> > m_contexts;            // +0x30
    std::map<unsigned, unsigned> m_keys;                        // +0x40 key -> event id
};
MS2_CHECK_SIZE(CGameEventValueLimitedQuantity, 0x50);

// +0xe08: the event shop NPCs (by id and by group).
class CGameEventValueEventShopNpc {
public:
    typedef std::list<MS2Ptr<EventShopNpcContext> > Contexts;
    CGameEventValueEventShopNpc();                  // 0x14042a360
    void Add(MS2Ptr<EventShopNpcContext> pContext); // 0x14042a3c0
    void Remove(int id);                            // 0x14042a5b0
    MS2Ptr<EventShopNpcContext> Find(unsigned long group, int npcId);  // 0x14042a7d0
    CLockCriticalSection m_lock;
    std::map<unsigned, MS2Ptr<EventShopNpcContext> > m_contexts;                     // +0x30 Get18 ->
    std::map<unsigned long, Contexts> m_groups;                         // +0x40 Get20 ->
};
MS2_CHECK_SIZE(CGameEventValueEventShopNpc, 0x50);
