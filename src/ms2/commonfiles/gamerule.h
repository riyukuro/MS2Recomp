// gamerule.h - CGameRule (commonfiles\gamerule.cpp; RTTI .?AVCGameRule@@, 0xf58 bytes). NOT an original header.
// The client side store of the running game events: each GameEvent* start / end handler (commonfiles\gameevent.cpp
// vfunc_5 / vfunc_6) puts its context or rate here and the UI / item code asks for it. Layout recovered from the ctor
// (0x140474af0) and the accessors; member names follow the offsets (the handler names are in the comments).
#pragma once

#include "ms2/ms2layout.h"
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/placeholder/termtagcontext.h"

class CItemData;
class COutputStream;
class CInPacket;
class Unk_AttendTable;

// The hash of the term tag map (std::hash has no CStringT specialization; the exe hashes the UTF-16 bytes).
// The FNV-1a byte hash is the older STL's _Hash_seq (14.16 has no such function; the exe has its own copy).
namespace std {
inline size_t _Hash_seq(const unsigned char* _First, size_t _Count)
{
    const size_t _FNV_offset_basis = 14695981039346656037ULL;
    const size_t _FNV_prime = 1099511628211ULL;
    size_t _Val = _FNV_offset_basis;
    for (size_t _Next = 0; _Next < _Count; ++_Next) {
        _Val ^= (size_t)_First[_Next];
        _Val *= _FNV_prime;
    }
    return _Val;
}
template <> struct hash<ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t> > >
{
    size_t operator()(const ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t> >& str) const
    {
        return _Hash_seq((const unsigned char*)static_cast<const wchar_t*>(str), str.GetLength() * sizeof(wchar_t));
    }
};
}

// The rates of the overlapping events of one kind: per key the rate of every running event (m_10[key][eventId]) and
// the largest of them (m_0[key]). Callers of the plain rates use key 0. Name invented.
template <class K>
class Unk_GameRuleRateMap
{
public:
    void Set(unsigned long eventId, K key, unsigned long rate);         // 0x14049f860 (K = unsigned long)
    void Remove(unsigned long eventId, K key);                          // 0x1404acbd0
    unsigned long Get(K key, unsigned long nDefault);                   // 0x1404a2be0
    void Recompute(K key);                                              // 0x1404a6e40

    std::map<K, unsigned long> m_0;                                     // key -> the largest rate
    std::map<K, std::map<unsigned long, unsigned long> > m_10;          // key -> event id -> rate
};

template <class K> void Unk_GameRuleRateMap<K>::Set(unsigned long eventId, K key, unsigned long rate)
{
    std::map<unsigned long, unsigned long>& rates = m_10[key];
    rates[eventId] = rate;
    Recompute(key);
}
template <class K> void Unk_GameRuleRateMap<K>::Remove(unsigned long eventId, K key)
{
    std::map<unsigned long, unsigned long>& rates = m_10[key];
    rates.erase(eventId);
    Recompute(key);
}
template <class K> unsigned long Unk_GameRuleRateMap<K>::Get(K key, unsigned long nDefault)
{
    if (m_0.find(key) == m_0.end())
        return nDefault;
    return m_0[key];
}
template <class K> void Unk_GameRuleRateMap<K>::Recompute(K key)
{
    if (m_10.find(key) == m_10.end()) {
        m_0.erase(key);
        return;
    }
    std::map<unsigned long, unsigned long>& rates = m_10[key];
    if (rates.empty()) {
        m_10.erase(key);
        m_0.erase(key);
        return;
    }
    unsigned long nMax = rates.begin()->second;
    for (std::map<unsigned long, unsigned long>::const_iterator it = rates.begin(), itEnd = rates.end(); it != itEnd; ++it)
        nMax = (std::max)(nMax, it->second);
    m_0[key] = nMax;
}

// The item kind of the remake (option change) sale, 0 = every item (CGameRule::FUN_140478cd0 picks 1..3 from three
// CItemData kind tests). An enum, not int: the exe's map<K, ...> instances of m_568 compare through their own
// less<K> copy (0x14049ef20), not less<int> (0x1401f1b70). Name invented.
enum Unk_RemakeSaleItemType { Unk_RemakeSaleItemType_All = 0 };
// The key of the stamp event map m_b68 (StampEventContext::m_98; 10001/10002 are tested first). An enum, not int:
// the exe's CAtlMap passes it by reference (CDefaultElementTraits) and its NewNode sorts after the CStringT-keyed one.
enum Unk_StampKey { Unk_StampKey_Default = 0 };

// One (lo, hi) range of GameEventEpicRestart (operator new 0x80 in 0x14047c020). Name invented.
struct Unk_EpicRestartRange {
    bool IsIn(unsigned value) const;                // 0x1403b4ef0: lo <= value <= hi
    unsigned m_lo;
    unsigned m_hi;
};
class EpicRestartContext : public CPtred {
public:
    EpicRestartContext() : m_18(0), m_20(0), m_78(0), m_7c(0) {}   // 0x14049a5c0
    int m_18;                                       // +0x18 event id
    __int64 m_20;                                   // +0x20 end time
    std::set<unsigned> m_28;                        // +0x28
    ATL::CAtlArray<Unk_EpicRestartRange> m_38;      // +0x38
    ATL::CAtlArray<unsigned> m_58;                  // +0x58
    int m_78;                                       // +0x78
    int m_7c;                                       // +0x7c
};
MS2_CHECK_SIZE(EpicRestartContext, 0x80);

class UgcMapCommendationGMEvent : public CPtred {
public:
    UgcMapCommendationGMEvent(int id, __int64 time, CStringW str) { m_18 = id; m_20 = time; m_28 = str; }  // 0x14049a690
    int m_18;
    __int64 m_20;
    CStringW m_28;
};
MS2_CHECK_SIZE(UgcMapCommendationGMEvent, 0x30);

// The context of 0xc00 (set / get only; no reader in the exe). Name invented.
class Unk_GameRuleC00Context : public CPtred {};
// The item tag rewards of 0xd48: the reward items of the events whose tag list contains a tag. Name invented.
class Unk_ItemTagRewardContext : public CPtred {
public:
    std::set<CStringW> m_tags;                      // +0x18
    std::vector<ItemEntity> m_items;                // +0x28
};
MS2_CHECK_SIZE(Unk_ItemTagRewardContext, 0x40);

// The key of the massive construction set (0xca0). Name invented.
struct Unk_ConstructionKey {
    Unk_ConstructionKey(unsigned id, int value) : m_id(id), m_value(value) {}   // 0x14049a660
    bool operator<(const Unk_ConstructionKey& o) const                         // 0x14049ecd0
    {
        if (m_id != o.m_id)
            return m_id < o.m_id;
        else
            return m_value < o.m_value;
    }
    unsigned m_id;
    int m_value;
};

// The GameReason helpers of this TU (free functions; names not recovered).
int FUN_140475e40(int reason);
BOOL FUN_140475e80(int reason);
BOOL FUN_140475f20(int reason);
BOOL FUN_140475fa0(int reason);
void FUN_140475ff0(unsigned short value);
CString FUN_140476020(int reason);                          // GameReason_* name

class CGameRule : public TSingleton<CGameRule>
{
public:
    typedef Unk_GEBoxPtr<ATL::CRBMap<int, int> > IntMapBox;
    typedef Unk_GEBoxPtr<ATL::CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> > > SaleCubeBox;

    CGameRule();                                            // 0x140474af0
    virtual ~CGameRule();                                   // 0x140475640
    // @0x1403f31d0 (GameEventTransferItemBound; name invented)
    void SetTransferItemBound(bool bBound) { m_transferItemBound = bBound; }

    void FUN_1404766e0();                                   // clears the events
    void FUN_140476930(int nEventId, int nRate);            // adventure level bonus exp rate
    void FUN_1404769a0(int nEventId);                       // ... removed
    __int64 FUN_140476a10(__int64 value);
    unsigned FUN_140476ad0();
    void FUN_140476b40(int a, int b, BOOL c);               // GameEventSaleBeautyShop
    void FUN_140476be0(int a, BOOL c);
    unsigned FUN_140476c70(int nEvent, unsigned nPrice, int nLevel);
    int FUN_140476cf0(int nEvent, int nLevel);
    void FUN_140476d50(int nEvent, int nLevel, unsigned* pRate, int* pIndex);
    void FUN_140476ef0(ATL::CAtlArray<int>& out, int nLevel, unsigned nMin);
    void FUN_140477020(int eventId, int a, int b, int c);   // GameEventSaleChat start
    void FUN_1404770e0(int eventId);
    __int64 FUN_140477180();
    __int64 FUN_140477210();
    __int64 FUN_1404772a0();
    __int64 FUN_140477330();
    void FUN_140477360(int eventId, MS2Ptr<SAHotTimeEventContext> spContext);
    void FUN_140477420(int eventId);
    int FUN_1404774a0(unsigned key, int bAll);
    void FUN_140477590(ATL::CAtlList<MS2Ptr<SAHotTimeEventContext> >& list);
    int FUN_140477640(int bPcBang);
    int FUN_1404776f0(int key);
    void FUN_1404777a0(int key, int value);
    void FUN_140477820(COutputStream& out, int key);
    void FUN_1404779b0(CInPacket& packet);
    void FUN_140477ab0(ATL::CAtlArray<std::pair<int, int> >& out);
    BOOL FUN_140477bb0();
    void FUN_140477bd0(int eventId, MS2Ptr<MesoRevivalEventContext> spContext);
    void FUN_140477c90(int eventId);
    int FUN_140477d10(int bAll);
    void FUN_140477dc0(unsigned eventId);                   // GameEventFreeAirTaxi
    void FUN_140477e30(unsigned eventId);
    BOOL FUN_140477ea0();
    void FUN_140477f20(int value, CStringW text);           // GameEventUserCondition
    void FUN_140477fb0(int value);
    CStringW FUN_140478020(int value);
    BOOL FUN_1404780e0(int value);
    void FUN_140478170(int eventId, MS2Ptr<OntimeEventContext> spContext);   // GameEventOntime
    void FUN_1404781f0(int eventId);
    MS2Ptr<const OntimeEventContext> FUN_140478280();
    MS2Ptr<const OntimeEventContext> FUN_1404783e0(int eventId);
    void FUN_1404784b0(int a, __int64 b, CStringW str);     // GameEventUgcMapCommendationGM
    void FUN_140478640(int a);
    MS2Ptr<UgcMapCommendationGMEvent> FUN_1404786b0(int a);
    void FUN_140478770(int value, int key, int sub);
    void FUN_1404788a0(int key, int sub);
    void FUN_140478960(int key, ATL::CRBMap<int, int>& out);
    void FUN_140478a40(int value);                          // GameEventDeleteUrlCache
    int FUN_140478a60();
    void FUN_140478a80(int eventId, int rate);              // GameEventSaleEnchant
    void FUN_140478af0(int eventId);
    unsigned FUN_140478b60();
    void FUN_140478bd0(int eventId, int type, int rate);    // GameEventSaleRemake
    void FUN_140478c50(int eventId, int type);
    unsigned FUN_140478cd0(MS2Ptr<CItemData> spItem);
    unsigned FUN_140478db0(int type);
    void FUN_140478e80(int eventId, int rate);              // GameEventSaleGemStoneUpgrade
    void FUN_140478ef0(int eventId);
    unsigned FUN_140478f60();
    void FUN_140478fd0(CStringW tag, MS2Ptr<EventQuestContext> spContext);  // GameEventQuestTag
    void FUN_140479070(CStringW tag);
    BOOL FUN_140479100(CStringW tag);
    MS2Ptr<EventQuestContext> FUN_1404791b0(CStringW tag);
    void FUN_140479280(MS2Ptr<TermTagContext> spContext);
    void FUN_140479330(const CStringW& name);
    bool FUN_1404793a0(const CStringW& name);
    MS2Ptr<TermTagContext> FUN_140479410(const CStringW& name);
    void FUN_140479510(int rate, __int64 beginTime, __int64 endTime);       // GameEventBlackMarketFeeDiscount
    int FUN_140479560();
    __int64 FUN_140479580();
    __int64 FUN_1404795a0();
    void FUN_1404795c0(int value);                          // GameEventEventFieldPopup
    int FUN_1404795e0();
    void FUN_140479600(int value);                          // GameEventUGCMapSaleCoupon
    int FUN_140479620();
    void FUN_140479640(int eventId, int rate);              // GameEventUGCMapContractSale
    void FUN_1404796b0(int eventId);
    unsigned FUN_140479720();
    void FUN_140479790(int eventId, int rate);              // GameEventUGCMapExtensionSale
    void FUN_140479800(int eventId);
    unsigned FUN_140479870();
    void FUN_1404798e0(int value);                          // GameEventSaleAutoFishing
    int FUN_140479900();
    void FUN_140479920(CStringW str);
    CStringW FUN_140479970();
    void FUN_140479a00(int value);                          // GameEventSaleAutoPlayInstrument
    int FUN_140479a20();
    void FUN_140479a40(CStringW str);
    CStringW FUN_140479a90();
    bool FUN_140479b20(unsigned roomId);
    bool FUN_140479bd0(Unk_DungeonGroupType group);
    void FUN_140479c80(MS2Ptr<DungeonRoomShutdownContext> spContext);       // GameEventDungeonRoomShutdown
    bool FUN_140479cf0(unsigned roomId);
    void FUN_140479da0(MS2Ptr<DungeonRoomShutdownContext> spContext);
    bool FUN_140479e10(unsigned dungeonId);
    void FUN_140479f30(std::vector<MS2Ptr<EventTimeLimitDungeonContext> >& contexts); // GameEventDungeonEnterTimeLimit
    void FUN_14047a0a0(int eventId);
    void FUN_14047a1b0(unsigned dungeonId, std::vector<Unk_DayTimeRange>& out);
    bool FUN_14047a270(unsigned id);
    void FUN_14047a360(std::set<unsigned> ids);             // GameEventFieldShutdown on
    void FUN_14047a3d0();                                   // ... off
    bool FUN_14047a420(unsigned dungeonId, MS2Ptr<DungeonExtraRewardCountCtx> spCount); // GameEventDungeonExtraReward
    void FUN_14047a4e0(unsigned dungeonId, int eventId);
    MS2Ptr<DungeonExtraRewardCountCtx> FUN_14047a5b0(unsigned dungeonId);
    void FUN_14047a6a0(int eventId, MS2Ptr<NpcEventDropEventContext> spContext);   // GameEventNpcEventDrop
    void FUN_14047a730(int eventId);
    void FUN_14047a7a0(std::vector<MS2Ptr<NpcEventDropEventContext> >& out);
    void FUN_14047a8c0(int type);                           // GameEventItemBuff
    int FUN_14047a8e0();
    void FUN_14047a900(MS2Ptr<DungeonBonusRewardCtx> spContext);
    void FUN_14047aa00(MS2Ptr<DungeonBonusRewardCtx> spContext);
    MS2Ptr<DungeonBonusRewardCtx> FUN_14047ab70(Unk_DungeonGroupType group);
    MS2Ptr<DungeonBonusRewardCtx> FUN_14047ad00(unsigned dungeonId);
    MS2Ptr<DungeonBonusRewardCtx> FUN_14047ae90(const std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts);
    void FUN_14047afb0(MS2Ptr<DungeonBonusRewardCtx> spContext);
    void FUN_14047b070(MS2Ptr<DungeonBonusRewardCtx> spContext);
    MS2Ptr<DungeonBonusRewardCtx> FUN_14047b170(unsigned dungeonId);
    void FUN_14047b300(unsigned dungeonId, Unk_DungeonGroupType group, std::vector<unsigned>& out);
    void FUN_14047b540(MS2Ptr<SkillUpgradeSaleEventContext> spContext);     // GameEventSaleSkillUpgrade
    void FUN_14047b5c0(unsigned skillId);
    MS2Ptr<SkillUpgradeSaleEventContext> FUN_14047b620(unsigned skillId);
    void FUN_14047b6d0(const CStringW& str);
    CStringW FUN_14047b740();
    unsigned FUN_14047b7c0(float rate, int value);
    unsigned FUN_14047b860(float rate, unsigned value);
    void FUN_14047b8f0(MS2Ptr<BlueMarbleEventContext> spContext);                  // GameEventBlueMarble
    MS2Ptr<BlueMarbleEventContext> FUN_14047b940();
    void FUN_14047b990(int value);
    int FUN_14047b9b0();
    void FUN_14047b9d0(int eventId, int rate);                                     // GameEventSaleUGCDesign
    void FUN_14047ba40(int eventId);
    unsigned FUN_14047bab0();
    void FUN_14047bb20(bool bOn, const CMsTime& time);                             // GameEventLoginNotice
    bool FUN_14047bb90();
    CMsTime FUN_14047bbe0();
    __int64 FUN_14047bc50(Unk_SaleHousingKey key, int type, __int64 price);
    void FUN_14047be80(int eventId, ATL::CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> >& cubes);   // GameEventSaleHousing
    void FUN_14047bfc0(int eventId);
    void FUN_14047c020(int eventId, __int64 endTime, const CStringA& a, const CStringA& b, const CStringA& c); // GameEventEpicRestart
    void FUN_14047c1e0();
    int FUN_14047c240();
    __int64 FUN_14047c2e0();
    BOOL FUN_14047c380(unsigned value);
    BOOL FUN_14047c530(unsigned value);
    int FUN_14047c600();
    int FUN_14047c6a0();
    void FUN_14047c740(int level, const CStringW& str);                            // GameEventLevelUpPackage
    void FUN_14047c7c0();
    int FUN_14047c820();
    void FUN_14047c870(ATL::CAtlArray<unsigned>& out);
    void FUN_14047c8e0(MS2Ptr<StampEventContext> spContext);                      // GameEventStampEvent
    void FUN_14047c990(MS2Ptr<StampEventContext> spContext);
    MS2Ptr<StampEventContext> FUN_14047ca40(Unk_AttendTable& table);
    void FUN_14047cd30(MS2Ptr<LongTermAttendGiftContext> spContext);             // GameEventLongTermAttendGift start
    void FUN_14047cdd0(MS2Ptr<LongTermAttendGiftContext> spContext);             // ... end
    MS2Ptr<LongTermAttendGiftContext> FUN_14047ce70();
    void FUN_14047cef0(MS2Ptr<GalleryContext> spContext);                        // GameEventGallery
    MS2Ptr<GalleryContext> FUN_14047cf60();
    void FUN_14047cfe0(MS2Ptr<SnowmanContext> spContext);                        // GameEventSnowman
    MS2Ptr<SnowmanContext> FUN_14047d050();
    void FUN_14047d0d0(MS2Ptr<RpsContext> spContext);                            // GameEventRps
    MS2Ptr<RpsContext> FUN_14047d140();
    void FUN_14047d1c0(MS2Ptr<ReactorContext> spContext);                        // GameEventReactor
    MS2Ptr<ReactorContext> FUN_14047d230();
    void FUN_14047d2b0(MS2Ptr<TreeWateringContext> spContext);                   // GameEventTreeWatering
    MS2Ptr<TreeWateringContext> FUN_14047d320();
    void FUN_14047d3a0(MS2Ptr<Unk_GameRuleC00Context> spContext);
    MS2Ptr<Unk_GameRuleC00Context> FUN_14047d410();
    void FUN_14047d490(unsigned value);
    float FUN_14047d4e0();
    void FUN_14047d570(unsigned value);
    float FUN_14047d5c0();
    void FUN_14047d650(MS2Ptr<TimeRunEventContext> spContext);              // GameEventTimeRunEvent start / end (null)
    MS2Ptr<TimeRunEventContext> FUN_14047d6c0();
    int FUN_14047d740(unsigned questId);
    void FUN_14047d820(int eventId, const CStringW& text);
    void FUN_14047d900(int eventId);
    bool FUN_14047d970(CStringW& strNotice);
    void FUN_14047dae0(CStringW str);
    CStringW FUN_14047db50();
    void FUN_14047dba0(unsigned id, int value);                                   // GameEventMassiveConstructionEvent
    void FUN_14047dc80(unsigned id, int value);
    void FUN_14047dd60();
    bool FUN_14047ddd0(unsigned id, int value, unsigned __int64 objectId);
    void FUN_14047df50(unsigned __int64 id);
    void FUN_14047e020(unsigned __int64 id);
    void FUN_14047e0e0();
    bool FUN_14047e150(unsigned __int64 nId);
    void FUN_14047e230(unsigned __int64 nId);                                            // ignore the construction lock of one id
    void FUN_14047e300();                                                        // ... clear them
    unsigned FUN_14047e370(unsigned key);
    void FUN_14047e530(MS2Ptr<EnchantRateEventContext> spContext);                // GameEventEnchantRate
    void FUN_14047e630(int eventId);
    void FUN_14047e740(bool bOpen);                                               // GameEventRankDuel
    bool FUN_14047e790();
    void FUN_14047e830(bool bOpen);                                               // GameEventGuildChampionship
    bool FUN_14047e880();
    void FUN_14047e8e0(unsigned a, unsigned b, MS2Ptr<QuestAdditionalRewardContext> spContext);   // GameEventQuestAdditionalReward
    void FUN_14047e980(unsigned a, unsigned b);
    unsigned FUN_14047ea00(unsigned a, unsigned b, int index);
    unsigned FUN_14047eb30(unsigned a, unsigned b, unsigned itemId);
    void FUN_14047ec80(bool bOpen);                         // guild vs game open
    bool FUN_14047eca0();
    void FUN_14047ecc0(CStringW tag, std::vector<ItemEntity>& out);
    void FUN_14047ee40(int key, MS2Ptr<Unk_ItemTagRewardContext> spContext);
    void FUN_14047ef00(int key);
    void FUN_14047ef70(int eventId, int value);                                   // GameEventPetMastery
    void FUN_14047efe0(int eventId);
    int FUN_14047f050(int value);
    bool FUN_14047f0f0();
    void FUN_14047f180(int eventId, int value);
    void FUN_14047f1f0(int eventId);
    int FUN_14047f260(int value);
    bool FUN_14047f300();
    void FUN_14047f390(int eventId, int rate);                                    // GameEventPetBattleExp
    void FUN_14047f400(int eventId);
    __int64 FUN_14047f470(__int64 value);
    unsigned FUN_14047f520();
    void FUN_14047f590(int eventId, int rate);                                    // GameEventPetComposeSale
    void FUN_14047f600(int eventId);
    __int64 FUN_14047f670(__int64 value);
    unsigned FUN_14047f720(unsigned value);
    void FUN_14047f7a0(int nEventId, int nRate);                                 // pet crystal sale rate
    void FUN_14047f810(int nEventId);                                            // ... removed
    unsigned FUN_14047f880();
    void FUN_14047f8f0(int nEventId, int nRate);                                 // lapenshard upgrade (RGB) sale rate
    void FUN_14047f960(int nEventId);                                            // ... removed
    void FUN_14047f9d0();                                   // recomputes the SA hot time sums
    void FUN_14047fc60();                                   // recomputes the meso revival flags

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_8;
    ATL::CAtlMap<int, MS2Ptr<SAHotTimeEventContext> > m_38;
    CLockCriticalSection m_80;
    std::map<int, int> m_b0;                                // SA hot time sums
    std::map<int, int> m_c0;                                // ... of the PC bang events
    int m_d0;
    int m_d4;
    CLockCriticalSection m_d8;
    Unk_GameRuleRateMap<unsigned long> m_108;
    CLockCriticalSection m_128;
    ATL::CAtlMap<unsigned long, int> m_158[2];              // beauty shop sales
    CLockCriticalSection m_1e8;
    ATL::CAtlMap<int, int> m_218;
    CLockCriticalSection m_260;
    Unk_GameRuleRateMap<unsigned long> m_290;               // chat sales
    Unk_GameRuleRateMap<unsigned long> m_2b0;
    Unk_GameRuleRateMap<unsigned long> m_2d0;
    ATL::CAtlMap<int, MS2Ptr<MesoRevivalEventContext> > m_2f0;
    CLockCriticalSection m_338;
    int m_368;
    int m_36c;
    CLockCriticalSection m_370;
    std::set<unsigned> m_3a0;                               // free air taxi
    int m_3b0;
    std::map<Unk_DungeonGroupType, std::set<MS2Ptr<DungeonBonusRewardCtx> > > m_3b8;
    std::map<unsigned, std::set<MS2Ptr<DungeonBonusRewardCtx> > > m_3c8;
    CLockCriticalSection m_3d8;
    std::map<unsigned, std::set<MS2Ptr<DungeonBonusRewardCtx> > > m_408;
    CLockCriticalSection m_418;
    std::map<int, MS2Ptr<NpcEventDropEventContext> > m_448;
    CLockCriticalSection m_458;
    ATL::CAtlMap<int, CStringW> m_488;                      // user conditions
    CLockCriticalSection m_4d0;
    ATL::CAtlMap<int, MS2Ptr<OntimeEventContext> > m_500;
    Unk_GameRuleRateMap<unsigned long> m_548;               // enchant sale
    Unk_GameRuleRateMap<Unk_RemakeSaleItemType> m_568;      // remake sale per item type
    Unk_GameRuleRateMap<unsigned long> m_588;               // gem stone upgrade sale
    CLockCriticalSection m_5a8;
    ATL::CAtlMap<CStringW, MS2Ptr<EventQuestContext>, ATL::CStringElementTraits<CStringW> > m_5d8;
    CLockCriticalSection m_620;
    std::unordered_map<CStringW, MS2Ptr<TermTagContext> > m_650;
    int m_690;                                              // black market fee discount
    __int64 m_698;
    __int64 m_6a0;
    int m_6a8;
    Unk_GameRuleRateMap<unsigned long> m_6b0;               // UGC map contract sale
    Unk_GameRuleRateMap<unsigned long> m_6d0;               // UGC map extension sale
    int m_6f0;
    int m_6f4;
    CStringW m_6f8;
    int m_700;
    CStringW m_708;
    CLockCriticalSection m_710;
    MS2Ptr<DungeonRoomShutdownContext> m_740;
    CLockCriticalSection m_750;
    MS2Ptr<DungeonRoomShutdownContext> m_780;
    CLockCriticalSection m_790;
    std::multimap<unsigned, MS2Ptr<EventTimeLimitDungeonContext> > m_7c0;
    CLockCriticalSection m_7d0;
    std::set<unsigned> m_800;                               // field shutdown
    CLockCriticalSection m_810;
    ATL::CAtlMap<unsigned, MS2Ptr<DungeonExtraRewardCountCtx> > m_840;
    CStringW m_888;
    ATL::CAtlMap<unsigned, MS2Ptr<SkillUpgradeSaleEventContext> > m_890;
    MS2Ptr<BlueMarbleEventContext> m_8d8;
    int m_8e8;
    Unk_GameRuleRateMap<unsigned long> m_8f0;               // UGC design sale
    bool m_910;
    CMsTime m_918;
    CLockCriticalSection m_928;
    std::multimap<unsigned, MS2Ptr<EnchantRateEventContext> > m_958;
    CLockCriticalSection m_968;
    bool m_998;
    CLockCriticalSection m_9a0;
    bool m_9d0;
    CLockCriticalSection m_9d8;
    ATL::CRBMap<int, MS2Ptr<UgcMapCommendationGMEvent> > m_a08;
    CLockCriticalSection m_a38;
    ATL::CRBMap<int, IntMapBox> m_a68;
    int m_a98;
    bool m_transferItemBound;                               // +0xa9c
    CLockCriticalSection m_aa0;
    ATL::CRBMap<unsigned, SaleCubeBox> m_ad0;
    CLockCriticalSection m_b00;
    MS2Ptr<EpicRestartContext> m_b30;
    int m_b40;
    ATL::CAtlArray<unsigned> m_b48;
    ATL::CAtlMap<Unk_StampKey, MS2Ptr<StampEventContext> > m_b68;
    MS2Ptr<GalleryContext> m_bb0;
    MS2Ptr<SnowmanContext> m_bc0;
    MS2Ptr<RpsContext> m_bd0;
    MS2Ptr<ReactorContext> m_be0;
    MS2Ptr<TreeWateringContext> m_bf0;
    MS2Ptr<Unk_GameRuleC00Context> m_c00;
    unsigned m_c10;
    unsigned m_c14;
    ATL::CAtlMap<unsigned, CStringW> m_c18;                 // game event notices
    bool m_c60;
    CStringW m_c68;
    CLockCriticalSection m_c70;
    std::set<Unk_ConstructionKey> m_ca0;
    std::set<unsigned __int64> m_cb0;
    CLockCriticalSection m_cc0;
    std::set<unsigned __int64> m_cf0;
    std::map<std::pair<int, int>, MS2Ptr<QuestAdditionalRewardContext> > m_d00;
    bool m_d10;
    CLockCriticalSection m_d18;
    std::multimap<unsigned, MS2Ptr<Unk_ItemTagRewardContext> > m_d48;
    CLockCriticalSection m_d58;
    Unk_GameRuleRateMap<unsigned long> m_d88;
    CLockCriticalSection m_da8;
    Unk_GameRuleRateMap<unsigned long> m_dd8;
    CLockCriticalSection m_df8;
    Unk_GameRuleRateMap<unsigned long> m_e28;
    CLockCriticalSection m_e48;
    Unk_GameRuleRateMap<unsigned long> m_e78;
    MS2Ptr<TimeRunEventContext> m_e98;
    CLockCriticalSection m_ea8;
    Unk_GameRuleRateMap<unsigned long> m_ed8;
    MS2Ptr<LongTermAttendGiftContext> m_ef8;
    CLockCriticalSection m_f08;
    Unk_GameRuleRateMap<unsigned long> m_f38;
};
MS2_CHECK_SIZE(CGameRule, 0xf58);
MS2_CHECK_OFFSET(CGameRule, m_38, 0x38);
MS2_CHECK_OFFSET(CGameRule, m_158, 0x158);
MS2_CHECK_OFFSET(CGameRule, m_2f0, 0x2f0);
MS2_CHECK_OFFSET(CGameRule, m_3b8, 0x3b8);
MS2_CHECK_OFFSET(CGameRule, m_448, 0x448);
MS2_CHECK_OFFSET(CGameRule, m_500, 0x500);
MS2_CHECK_OFFSET(CGameRule, m_5d8, 0x5d8);
MS2_CHECK_OFFSET(CGameRule, m_650, 0x650);
MS2_CHECK_OFFSET(CGameRule, m_690, 0x690);
MS2_CHECK_OFFSET(CGameRule, m_740, 0x740);
MS2_CHECK_OFFSET(CGameRule, m_7c0, 0x7c0);
MS2_CHECK_OFFSET(CGameRule, m_840, 0x840);
MS2_CHECK_OFFSET(CGameRule, m_890, 0x890);
MS2_CHECK_OFFSET(CGameRule, m_918, 0x918);
MS2_CHECK_OFFSET(CGameRule, m_958, 0x958);
MS2_CHECK_OFFSET(CGameRule, m_a08, 0xa08);
MS2_CHECK_OFFSET(CGameRule, m_a68, 0xa68);
MS2_CHECK_OFFSET(CGameRule, m_transferItemBound, 0xa9c);
MS2_CHECK_OFFSET(CGameRule, m_ad0, 0xad0);
MS2_CHECK_OFFSET(CGameRule, m_b30, 0xb30);
MS2_CHECK_OFFSET(CGameRule, m_b68, 0xb68);
MS2_CHECK_OFFSET(CGameRule, m_c00, 0xc00);
MS2_CHECK_OFFSET(CGameRule, m_c18, 0xc18);
MS2_CHECK_OFFSET(CGameRule, m_ca0, 0xca0);
MS2_CHECK_OFFSET(CGameRule, m_d00, 0xd00);
MS2_CHECK_OFFSET(CGameRule, m_d48, 0xd48);
MS2_CHECK_OFFSET(CGameRule, m_e98, 0xe98);
MS2_CHECK_OFFSET(CGameRule, m_ef8, 0xef8);
MS2_CHECK_OFFSET(CGameRule, m_f38, 0xf38);
