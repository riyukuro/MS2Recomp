// GameEvent subclasses and *Context types of commonfiles\gameeventcontext.cpp (names from the exe's RTTI / registration
// strings; member names inferred from the XML loaders and the stream readers). w141 partial recovery.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/itemgift.h"
#include <vector>
#include <map>
#include <set>
#include "ms2/placeholder/mstime.h"

// clang-cl devirtualizes a call on an embedded member object into a direct call to an undefined function; go through
// an opaque pointer there (the byte-matched cl build keeps the member call).
#ifdef __clang__
#define MS2_GE_READ_BYTE(r) (reinterpret_cast<Unk_GEReader*>(r)->ReadByte())
#else
#define MS2_GE_READ_BYTE(r) ((r)->ReadByte())
#endif

// The attend reward entry of the cash attend table (looked up by id through the table group singleton; the table lives
// in attendgiftdatagroup.cpp). Name unknown.
class Unk_CashAttendEntry : public CPtred {
};
class Unk_AttendGiftDataGroup {
public:
    MS2Ptr<Unk_CashAttendEntry> FUN_1401ae630(int id);      // 0x1401ae630
};

class GameEventAttendGift : public GameEvent {
public:
    GameEventAttendGift();
    virtual CStringW vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_10();
protected:   // gameeventcli.cpp (GameEvent*Cli) reads the members
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<ItemGift> > m_gifts;  // +0xd0
    CStringW m_strName;                         // +0xf0
    CStringA m_strDesc;                         // +0xf8
    int m_i100;
    int m_i104;
    __int64 m_i108;
    int m_i110;
    int m_i114;
    int m_i118;
    int m_i11c;
    int m_i120;
    bool m_b124;
    bool m_b125;
};
MS2_CHECK_SIZE(GameEventAttendGift, 0x128);
MS2_CHECK_OFFSET(GameEventAttendGift, m_gifts, 0xd0);
MS2_CHECK_OFFSET(GameEventAttendGift, m_strName, 0xf0);
MS2_CHECK_OFFSET(GameEventAttendGift, m_i108, 0x108);
MS2_CHECK_OFFSET(GameEventAttendGift, m_i120, 0x120);
MS2_CHECK_OFFSET(GameEventAttendGift, m_b125, 0x125);

class GameEventCashAttend : public GameEvent {
public:
    GameEventCashAttend();
    virtual CStringW vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_10();
    int FUN_1403fbdc0() { return m_i4; }        // 0x1403fbdc0
protected:   // gameeventcli.cpp (GameEvent*Cli) reads the members
    MS2_LAYOUT_FRIEND;
    int m_i0;                                   // +0xd0 table id
    int m_i4;                                   // +0xd4
    CStringW m_strDesc;                         // +0xd8
    MS2Ptr<Unk_CashAttendEntry> m_entry;        // +0xe0
};
MS2_CHECK_SIZE(GameEventCashAttend, 0xf0);
MS2_CHECK_OFFSET(GameEventCashAttend, m_i4, 0xd4);
MS2_CHECK_OFFSET(GameEventCashAttend, m_entry, 0xe0);

// ---- *Context types of gameeventcontext.cpp (w149) ---------------------------------------------------------------------
// CPtred-derived value objects that the GameEvent subclasses of gameevent.cpp fill from their XML (Load*) and stream to
// the client (Write / Read). Their vftables hold only the scalar deleting dtor; the dtors are implicit.

class BlueMarbleEventContext : public CPtred {
public:
    BlueMarbleEventContext(int eventId, const CMsTime& endTime);   // 0x1403fc710
    void LoadRewards(Unk_140165cf0* pElem);                 // 0x1403fc7c0
    void LoadSlots(Unk_140165cf0* pElem);                   // 0x1403fc990
    void AddReward(int round, MS2Ptr<ItemEntity> spItem);   // 0x1403fcac0
    int m_eventId;                                          // +0x18
    CMsTime m_endTime;                                      // +0x20
    unsigned m_consumeItemID;                               // +0x30 "consumeItemID"
    int m_consumeItemCount;                                 // +0x34 "consumeItemCount"
    ATL::CRBMap<int, MS2Ptr<ItemEntity> > m_rewards;        // +0x38 by "round"
    std::vector<MS2Ptr<BonusGameBlueMarbleSlot> > m_slots;  // +0x68
};  // vftable 0x142d44140
MS2_CHECK_SIZE(BlueMarbleEventContext, 0x80);
MS2_CHECK_OFFSET(BlueMarbleEventContext, m_rewards, 0x38);

// DungeonExtraRewardCountCtx: gameevent.h (GameEventDungeonExtraReward holds a map of them).

enum Unk_DungeonGroupType;                                  // MSVC forward declaration (int-sized); defined in commonfiles/additionalactionadditional.h
class DungeonBonusRewardCtx : public CPtred {
public:
    DungeonBonusRewardCtx();                                // 0x1403fd8a0
    void Load(Unk_140165cf0* pElem);                        // 0x1403fd930
    void Write(COutputStream& out) const;                   // 0x1403fda00
    void Read(CInputStream& in);                            // 0x1403fda90
    void Merge(const MS2Ptr<DungeonBonusRewardCtx>& other); // 0x1403fdb40
    __int64 ApplyMesoRate(__int64 value);                   // 0x1403fdc50
    __int64 ApplyExpRate(__int64 value);                    // 0x1403fdca0
    unsigned m_dungeonID;                                   // +0x18 "dungeonID"
    Unk_DungeonGroupType m_groupType;                       // +0x1c "groupType" (a byte on the wire)
    long m_itemRolls;                                       // +0x20 "itemRolls"
    std::vector<unsigned> m_customDropBoxIds;               // +0x28 "customDropBoxIds"
    float m_mesoRate;                                       // +0x40 "mesoRate"
    float m_expRate;                                        // +0x44 "expRate"
};  // vftable 0x142d44170
MS2_CHECK_SIZE(DungeonBonusRewardCtx, 0x48);
CInputStream& operator>>(CInputStream& in, DungeonBonusRewardCtx& ctx);              // 0x1403fdcf0
COutputStream& operator<<(COutputStream& out, const DungeonBonusRewardCtx& ctx);     // 0x1403fdd20

class ItemBoxEventContext : public CPtred {
public:
    ItemBoxEventContext();                                  // 0x1403fdd50
    void Load(Unk_140165cf0* pElem);                        // 0x1403fdde0
    void Write(COutputStream& out);                         // 0x1403fde90
    void Read(CInPacket& packet);                           // 0x1403fdf70
    unsigned m_fieldID;                                     // +0x18 "fieldID"
    CStringW m_title;                                       // +0x20 "title"
    CStringW m_desc;                                        // +0x28 "desc"
    CStringW m_bannerPath;                                  // +0x30 "bannerPath"
    unsigned m_boxItemID;                                   // +0x38 "boxItemID"
    int m_3c;
};  // vftable 0x142d44180
MS2_CHECK_SIZE(ItemBoxEventContext, 0x40);

// The quest reward rates of GameEventQuestAdditionalReward: the event value is either one rate for every kind or an
// xml document with one attribute per kind plus <item id rate> rows.
class QuestAdditionalRewardContext : public CPtred {
public:
    QuestAdditionalRewardContext();                         // 0x1403fe980
    void Load(CStringW* pValue);                            // 0x1403fea10
    void Write(COutputStream& out);                         // 0x1403fecc0
    void Read(CInPacket& packet);                           // 0x1403fedf0
    unsigned m_rates[8];        // +0x18 exp, meso, guild_fund, guild_exp, guild_coin, lu, karma, menteeCoin
    ATL::CAtlMap<unsigned, unsigned> m_itemRates;           // +0x38 item id -> rate
};  // vftable 0x142d441a0
MS2_CHECK_SIZE(QuestAdditionalRewardContext, 0x80);

// GameEventReturnUser's context (the event holds it as an MS2Ptr; the ctor 0x14041cf20 is in the next unit).
class MentoringContext : public CPtred {
public:
    MentoringContext();
    void Write(COutputStream& out);                         // 0x1403ff4a0
    void Read(CInPacket& packet);                           // 0x1403ff5a0
    int m_18;
    int m_pad_1c;
    __int64 m_20;
    __int64 m_28;
    ATL::CAtlArray<unsigned> m_ids;                         // +0x30
};  // vftable 0x142d44a70
MS2_CHECK_SIZE(MentoringContext, 0x50);

class DungeonBuffEventCtx : public CPtred {
public:
    DungeonBuffEventCtx();                                  // 0x1403ff6c0
    bool Load(Unk_140165cf0* pElem);                        // 0x1403ff720: false without effect GUIDs
    unsigned m_dungeonID;                                   // +0x18 "dungeonID"
    int m_pad_1c;
    std::vector<unsigned __int64> m_addEffectGUIDs;         // +0x20 "addifectGUIDs"
    bool m_isBeginner;                                      // +0x38 "isBeginner"
};  // vftable 0x142d441b0
MS2_CHECK_SIZE(DungeonBuffEventCtx, 0x40);

// The NPC shop give-point event settings (GameEventNpcShopGivePoint::vfunc_5 loads them with Create).
class CNpcShopProductBase;
class CNpcShopGivePointContextBase : public CPtred {
public:
    CNpcShopGivePointContextBase() : m_type(0), m_giveItemId(0) {}      // 0x14040fcf0
    int GetType() { return m_type; }                                    // 0x140413360
    static MS2Ptr<CNpcShopGivePointContextBase> Create(int type, const CStringW& strPath);    // 0x140402150
    static __int64 GetGivePoint(MS2Ptr<CNpcShopGivePointContextBase> spContext,
                                MS2Ptr<CNpcShopProductBase> spProduct);                     // 0x140402390
    int m_type;                     // +0x18 1: CNpcShopGivePointContextCNSpring
    unsigned m_giveItemId;          // +0x1c "giveItemID"
};  // vftable 0x142d441c0
MS2_CHECK_SIZE(CNpcShopGivePointContextBase, 0x20);
class CNpcShopGivePointContextCNSpring : public CNpcShopGivePointContextBase {
public:
    CNpcShopGivePointContextCNSpring() : m_normalPercent(0), m_specialPercent(0) {}   // 0x14040fd40
    __int64 GetGivePoint(__int64 price, int currencyType, int label);  // 0x1404020b0
    unsigned m_normalPercent;       // +0x20 "normalPercent", in 1/10000
    unsigned m_specialPercent;      // +0x24 "specialPercent"
};  // vftable 0x142d441d0
MS2_CHECK_SIZE(CNpcShopGivePointContextCNSpring, 0x28);

// Three event setting types the client never constructs (no vftable, RTTI or caller of the methods; the period array
// one is only read by the dead 0x140427c30 in gameeventvalue). Names invented from the ToString formats.
class Unk_FieldObjectDropContext : public CPtred {
public:
    void Write(COutputStream& out);                 // 0x140403980
    void Read(CInPacket& packet);                   // 0x1404039f0
    CStringW ToString();                            // 0x140403a80
    bool IsValid();                                 // 0x140403b50
    ATL::CAtlArray<unsigned> m_fieldIds;            // +0x18
    ATL::CAtlArray<unsigned> m_objectIds;           // +0x38
    ATL::CAtlArray<unsigned> m_itemIds;             // +0x58
    unsigned m_percent;                             // +0x78
};
class Unk_FieldObjectDropListContext : public CPtred {
public:
    void Write(COutputStream& out);                 // 0x140403bd0
    void Read(CInPacket& packet);                   // 0x140403c50
    CStringW ToString();                            // 0x140403ce0
    bool IsValid();                                 // 0x140403dd0: one percent per item
    ATL::CAtlArray<unsigned> m_fieldIds;            // +0x18
    ATL::CAtlArray<unsigned> m_objectIds;           // +0x38
    ATL::CAtlArray<unsigned> m_itemIds;             // +0x58
    ATL::CAtlArray<unsigned> m_percents;            // +0x78
};
class Unk_DayItemContext : public CPtred {
public:
    class Period : public CPtred {
    public:
        void Write(COutputStream& out);             // 0x140403ed0 (empty)
        void Read(CInPacket& packet);               // 0x140403ef0 (empty)
        void Update();                              // 0x140404270: running (2) -> over (4) after the end time
        bool IsActive();                            // 0x1404042d0
        void Clear();                               // 0x140404370 (empty)
        int m_id;                                   // +0x18
        int m_pad_1c;
        CMsTime m_beginTime;                        // +0x20
        CMsTime m_endTime;                          // +0x30
        int m_state;                                // +0x40
    };
    void Write(COutputStream& out);                 // 0x140403e90 (empty)
    void Read(CInPacket& packet);                   // 0x140403eb0 (empty)
    CStringW ToString();                            // 0x140403f10
    void GetItemIds(ATL::CAtlArray<unsigned>& rOut);            // 0x140403fc0 (empty)
    void GetActivePeriodIds(ATL::CAtlArray<unsigned>& rOut);    // 0x140403fe0
    bool IsValid();                                 // 0x140404080
    bool IsActive();                                // 0x1404040e0
    bool IsTodayEnabled();                          // 0x140404190
    void Update();                                  // 0x140404260 (empty)
    void GetPeriods(ATL::CAtlArray<MS2Ptr<Period>>& rOut);      // 0x140404380
    Period* FindPeriod(int id);                     // 0x1404043b0
    ATL::CAtlArray<unsigned> m_itemIds;             // +0x18
    int m_38;
    int m_weekends;                                 // +0x3c
    int m_weekdays;                                 // +0x40
    int m_customized;                               // +0x44
    ATL::CAtlArray<int> m_customizedDays;           // +0x48 CTime days of the week
    ATL::CAtlArray<MS2Ptr<Period>> m_periods;       // +0x68
};
MS2_CHECK_SIZE(Unk_FieldObjectDropContext, 0x80);
MS2_CHECK_SIZE(Unk_FieldObjectDropListContext, 0x98);
MS2_CHECK_SIZE(Unk_DayItemContext::Period, 0x48);
MS2_CHECK_SIZE(Unk_DayItemContext, 0x88);

// The *Context types of the remaining GameEvent subclasses (vftables 0x142d441e0..0x142d44240; ??_G and dtors are
// COMDATs of this unit). Member names from the GameEvent::vfunc_2 XML loaders in gameevent.cpp.
class FestivalContext : public CPtred {
public:
    FestivalContext();                              // 0x1404052c0
    void Write(COutputStream& out);                 // 0x140405350
    void Read(CInPacket& packet);                   // 0x1404053a0
    int m_18;                                       // the event's m_68 number (a byte on the wire)
    int m_1c;                                       // the event's m_70 number (a byte on the wire)
    CMsTime m_beginTime;                            // +0x20
    CMsTime m_endTime;                              // +0x30
};
class FieldEffectContext : public CPtred {
public:
    FieldEffectContext();                           // 0x140405420
    void Clear();                                   // 0x140405490
    BOOL HasField(int id);                          // 0x1404054d0
    void Write(COutputStream& out);                 // 0x140405550
    void Read(CInPacket& packet);                   // 0x140405610
    ATL::CAtlArray<unsigned> m_fieldIds;            // +0x18
    CStringW m_effect;                              // +0x38
};
class CollectItemGroupContext : public CPtred {
public:
    CollectItemGroupContext();                      // 0x140405720
    void Write(COutputStream& out);                 // 0x1404057d0
    void Read(CInPacket& packet);                   // 0x1404058e0
    void AddCondition(ItemEntity& item);            // 0x140405ae0
    unsigned m_eventId;                             // +0x18 (unsigned: CGameEventValueCollectItemGroup::Add's make_pair forwards an unsigned&)
    int m_pad_1c;
    __int64 m_beginTime;                            // +0x20
    __int64 m_endTime;                              // +0x28
    CStringW m_name;                                // +0x30 info "name"
    std::vector<ItemEntity> m_conditions;           // +0x38 "condition"
    std::map<std::pair<unsigned, int>, unsigned> m_conditionKeys;   // +0x50 (item id, rarity) -> amount
    ItemEntity m_result;                            // +0x60 "result"
};
class ArcadeOpenContext : public CPtred {
public:
    ArcadeOpenContext();                            // 0x140405be0
    void Write(COutputStream& out);                 // 0x140405c50
    void Read(CInPacket& packet);                   // 0x140405c90
    int m_eventId;                                  // +0x18
    int m_arcadeId;                                 // +0x1c "arcadeId"
    int m_rewardCountPerDay;                        // +0x20 "rewardCountPerDay"
    int m_pad_24;
    std::vector<ItemEntity> m_rewards;              // +0x28
};

// The creating-constructor tag and the 16-byte smart pointer of a boxed value (TPtr<T> over TPtredDummy<T>; same
// template as Unk_FieldPtr in fieldmetatable.h). Members are defined out of the class so that they stay out-of-line
// COMDATs like the exe's (0x14040f040..0x140418e80).
#include "ms2/placeholder/tptreddummy.h"
struct Unk_BingoNewTag { explicit Unk_BingoNewTag(int); };     // 0x1401b7b90 (returns its this, no code)
CPtred* FUN_1401ba820(CPtred* p);                               // marks a freshly allocated box (sets the count to 1)
template <class T>
class Unk_GEBoxPtr
{
public:
    Unk_GEBoxPtr();
    Unk_GEBoxPtr(int);
    Unk_GEBoxPtr(const Unk_BingoNewTag&);
    Unk_GEBoxPtr(const Unk_GEBoxPtr& o);
    ~Unk_GEBoxPtr();
    Unk_GEBoxPtr& operator=(const Unk_GEBoxPtr& o);
    Unk_GEBoxPtr& operator=(const Unk_BingoNewTag&);           // `box = Unk_BingoNewTag(0)`: a fresh box
    bool operator==(T* p) const;                               // `box == 0`
    T* get() const;
    T* operator->() const;
    T& operator*() const;

private:
    void AddRef() const;
    void Make();
    void Release();
    static TPtredDummy<T>* Allocate(void*);
    static T* Value(TPtredDummy<T>* p);
    static TPtredDummy<T>* Owner(T* p);
    static void Ref(CPtred* p);
    static T* Create(void*);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    void* m_00;
    T* m_p;
};
template <class T> Unk_GEBoxPtr<T>::Unk_GEBoxPtr() { m_p = 0; }
template <class T> Unk_GEBoxPtr<T>::Unk_GEBoxPtr(int) { m_p = 0; }
template <class T> Unk_GEBoxPtr<T>::Unk_GEBoxPtr(const Unk_BingoNewTag&) { m_p = 0; Make(); }
template <class T> Unk_GEBoxPtr<T>::Unk_GEBoxPtr(const Unk_GEBoxPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_GEBoxPtr<T>::~Unk_GEBoxPtr() { Release(); }
template <class T> Unk_GEBoxPtr<T>& Unk_GEBoxPtr<T>::operator=(const Unk_GEBoxPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_GEBoxPtr<T>& Unk_GEBoxPtr<T>::operator=(const Unk_BingoNewTag&) { Make(); return *this; }
template <class T> bool Unk_GEBoxPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> T* Unk_GEBoxPtr<T>::get() const { return m_p; }
template <class T> T* Unk_GEBoxPtr<T>::operator->() const { return m_p; }
template <class T> T& Unk_GEBoxPtr<T>::operator*() const { return *m_p; }
template <class T> void Unk_GEBoxPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_GEBoxPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_GEBoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* Unk_GEBoxPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* Unk_GEBoxPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* Unk_GEBoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void Unk_GEBoxPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> T* Unk_GEBoxPtr<T>::Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
template <class T> void Unk_GEBoxPtr<T>::AddRefImpl(void*) const { Ref(Owner(m_p)); }
template <class T> void Unk_GEBoxPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

class BingoContext : public CPtred {
public:
    typedef Unk_GEBoxPtr<ATL::CAtlArray<ItemEntity> > RewardPtr;
    typedef Unk_GEBoxPtr<ATL::CAtlArray<int> > NumbersPtr;
    static const size_t kBoardSize = 5;            // 5x5 board
    BingoContext();                                 // 0x140405ce0
    bool LoadNumbers(CStringW strPath);             // 0x140405d70
    bool LoadRewards(CStringW strPath);             // 0x140406120
    bool LoadFreeItem(CStringW str);                // 0x140406320
    bool LoadCashItem(CStringW str);                // 0x140406370
    NumbersPtr GetTodayNumbers();                   // 0x1404063c0: the number board of the day since the begin date
    int CountLines(__int64 seed, ATL::CAtlArray<int>& checked);     // 0x140406550: completed rows/columns/diagonals
    void Write(COutputStream& out);                 // 0x140406880
    void Read(CInPacket& packet);                   // 0x1404069d0
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    CMsTime m_beginTime;                            // +0x20
    CMsTime m_endTime;                              // +0x30
    int m_freeItemId;                               // +0x40
    int m_cashItemId;                               // +0x44
    ATL::CAtlArray<RewardPtr> m_rewards;            // +0x48 one item list per line count
    ATL::CAtlArray<NumbersPtr> m_numbers;           // +0x68 one board per day
};
class LimitedQuantityContext : public CPtred {
public:
    LimitedQuantityContext();                       // 0x140406bb0
    void Write(COutputStream& out);                 // 0x140406c30
    void Read(CInPacket& packet);                   // 0x140406d70
    bool ParseRange(CStringW str);                  // 0x140406ea0
    bool LoadItems(CStringW strPath);               // 0x140406f70
    unsigned m_eventId;                             // +0x18 (unsigned: CGameEventValueLimitedQuantity::Add indexes its map<unsigned> with it)
    unsigned m_1c;                                  // key of CGameEventValueLimitedQuantity::m_keys
    int m_20;
    int m_pad_24;
    std::map<unsigned long, int> m_items;           // +0x28 item id -> quantity
};
class EventShopNpcContext : public CPtred {
public:
    EventShopNpcContext(int a, int b, int c, int d);    // 0x140407120
    int Get18();                                    // 0x140407190
    int Get1c();                                    // 0x1404071b0
    int Get20();                                    // 0x1404071d0
    int Get24();                                    // 0x1404071f0
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
};
MS2_CHECK_SIZE(FestivalContext, 0x40);
MS2_CHECK_SIZE(FieldEffectContext, 0x40);
MS2_CHECK_SIZE(CollectItemGroupContext, 0x90);
MS2_CHECK_SIZE(ArcadeOpenContext, 0x40);
MS2_CHECK_SIZE(BingoContext, 0x88);
MS2_CHECK_SIZE(LimitedQuantityContext, 0x38);
MS2_CHECK_SIZE(EventShopNpcContext, 0x28);
