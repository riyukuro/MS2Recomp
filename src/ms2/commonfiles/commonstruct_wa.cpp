// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). commonstruct slice A (temporary sub-unit).
// MS2-UNIT: commonfiles\commonstruct.cpp#1.wa
// MS2-RANGE: 0x14026ab50-0x14026ced0 .text$mn
// MS2-RANGE: 0x14026e700-0x1402709a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstruct_wa.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <list>
#include <map>
#include <vector>
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/xmlattr.h"   // C3: XmlSplit

// Scoped lock helper (ctor 0x1401b4ec0, dtor 0x1401b5120).
class Unk_1401b4ec0 {
public:
    Unk_1401b4ec0(CLockCriticalSection&, int);
    ~Unk_1401b4ec0();
    void* m_p;
};
// The STL/ATL instances behind the unit's views (C3: the calls go to their members).
typedef std::vector<MS2Ptr<CIngredientInfo>> VIng;
typedef std::vector<CString> VStr;
typedef std::vector<ItemEntity> VItem;
typedef std::map<int, int> MapII;
typedef std::list<MS2Ptr<CUserChangeableItemHistory>> LHist;
typedef ATL::CAtlArray<int> ArrI;
typedef ATL::CAtlArray<unsigned> ArrU;
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- ItemEntity -----------------------------------------------------------------------------------------------
// @0x14026ab50
ItemEntity::ItemEntity() : m_itemId(0), m_count(1), m_28(false), m_29(false), m_2a(false), m_2b(false), m_rank(1) {}
// @0x14026abf0
ItemEntity::ItemEntity(unsigned id, int rank, unsigned count, bool b28, bool b2a, bool b29, bool b2b)
    : m_itemId(id), m_count(count), m_28(b28), m_29(b29), m_2a(b2a), m_2b(b2b), m_rank(rank) {}
// @0x14026acb0
ItemEntity::ItemEntity(ItemAble& source) {
    m_itemId = source.vfunc_o18_0();
    m_count = source.vfunc_o18_2();
    m_rank = source.vfunc_o18_1();
}
// @0x14026ad60
void ItemEntity::vfunc_1(CStringW text) {
    ArrU values;
    FUN_140274fc0(text, &values, L",");
    if (values.GetCount() >= 1) m_itemId = values[0];
    if (values.GetCount() >= 2) m_rank = values[1];
    if (values.GetCount() >= 3) m_count = values[2];
}
// @0x14026ae40
void ItemEntity::vfunc_2(void* xml) {
    XmlGetAttr((class TiXmlElement*)(xml), "itemID", m_itemId);
    XmlGetAttr((class TiXmlElement*)(xml), "grade", reinterpret_cast<int&>(m_rank));
    XmlGetAttr((class TiXmlElement*)(xml), "count", m_count);
}
// @0x14026aeb0
bool FUN_14026aeb0(const ItemEntity& a, const ItemEntity& b) {
    if (a.m_itemId != b.m_itemId) return a.m_itemId < b.m_itemId;
    if (a.m_rank != b.m_rank) return a.m_rank < b.m_rank;
    return a.m_count < b.m_count;
}
// @0x14026af70
unsigned ItemEntity::vfunc_o18_0() { return m_itemId; }
// @0x14026af90
int ItemEntity::vfunc_o18_1() { return m_rank; }
// @0x14026afb0
unsigned ItemEntity::vfunc_o18_2() { return m_count; }
// @0x14026afd0
bool ItemEntity::vfunc_o18_3() { return m_28; }
// @0x14026aff0
bool ItemEntity::FUN_14026aff0() { return m_29; }
// @0x14026b010
bool ItemEntity::FUN_14026b010() { return m_2b; }
// @0x14026b030
void ItemEntity::FUN_14026b030(Unk_GiftOutput& stream) {
    reinterpret_cast<COutputStream&>(stream).WriteInt32(m_itemId);
    reinterpret_cast<COutputStream&>(stream).WriteInt16((short)m_rank);
    reinterpret_cast<COutputStream&>(stream).WriteInt32(m_count);
    reinterpret_cast<COutputStream&>(stream).WriteBool(m_28);
    reinterpret_cast<COutputStream&>(stream).WriteBool(m_2a);
    reinterpret_cast<COutputStream&>(stream).WriteBool(m_29);
    reinterpret_cast<COutputStream&>(stream).WriteBool(m_2b);
}
// @0x14026b100
void ItemEntity::FUN_14026b100(Unk_GiftInput& stream) {
    m_itemId = reinterpret_cast<CInputStream&>(stream).ReadInt32();
    m_rank = (unsigned short)reinterpret_cast<CInputStream&>(stream).ReadInt16();
    m_count = reinterpret_cast<CInputStream&>(stream).ReadInt32();
    m_28 = reinterpret_cast<CInputStream&>(stream).ReadBool();
    m_2a = reinterpret_cast<CInputStream&>(stream).ReadBool();
    m_29 = reinterpret_cast<CInputStream&>(stream).ReadBool();
    m_2b = reinterpret_cast<CInputStream&>(stream).ReadBool();
}
// @0x14026b1c0
void ItemEntity::SetRank(int rank) { m_rank = rank; }

// ---- CIngredientInfo ------------------------------------------------------------------------------------------
// @0x14026b1e0
void CIngredientInfo::FUN_14026b1e0(COutputStream& out) {
    out.WriteInt32(m_a);
    out.WriteInt32(m_b);
    out.WriteInt32(m_c);
}
// @0x14026b250
void CIngredientInfo::FUN_14026b250(CInPacket& in) {
    m_a = in.ReadInt32();
    m_b = in.ReadInt32();
    m_c = in.ReadInt32();
}
// @0x14026b2f0
bool CIngredientInfo::IsDifferent(CIngredientInfo* other) {
    if (m_a != other->m_a) return 1;
    if (m_b != other->m_b) return 1;
    if (m_c != other->m_c) return 1;
    return 0;
}
// @0x14026b350
bool CIngredientInfo::IsEmpty() {
    return m_c == 0 || (m_a == 0 && m_b == 0);
}
// @0x14026b3a0
void CIngredientInfo::FUN_14026b3a0(COutputStream& out) {
    out.WriteInt32(m_a);
    out.WriteInt32(m_b);
    out.WriteInt32(m_c);
}
// @0x14026b410
void CIngredientInfo::FUN_14026b410(CInPacket& in) {
    m_a = in.ReadInt32();
    m_b = in.ReadInt32();
    m_c = in.ReadInt32();
}
// @0x14026b4b0
unsigned CIngredientInfo::FUN_14026b4b0() {
    if (m_b != 0 && TSingleton<CItemDataTable>::GetInstance() != 0) {
        return TSingleton<CItemDataTable>::GetInstance()->GetTagItemId((ItemTagKey)m_b);
    }
    return 0;
}
// @0x14026b500
unsigned CIngredientInfo::FUN_14026b500() {
    if (m_a != 0) return m_a;
    return FUN_14026b4b0();
}
// @0x14026b540
int* FUN_14026b540(int* out, int value) { *out = value; return out; }
// @0x14026b560
bool FUN_14026b560(int* id, Unk_IngRef ref) {
    if (ref == 0) return false;
    return ref->m_a == *id;
}

// ---- CIngredientContainer -------------------------------------------------------------------------------------
// @0x14026b5f0
CIngredientContainer::CIngredientContainer() {}
// @0x14026b640
CIngredientContainer::CIngredientContainer(size_t reserve) { reinterpret_cast<VIng&>(m_items).reserve(reserve); }
// @0x14026b6b0
CIngredientContainer::CIngredientContainer(CIngredientContainer* other) {
    reinterpret_cast<VIng&>(m_items).clear();
    reinterpret_cast<VIng&>(m_items).reserve(reinterpret_cast<VIng&>(other->m_items).size());
    Unk_IngVec* source = &other->m_items;
    Unk_IngRef* it = (Unk_IngRef*)reinterpret_cast<const VIng&>(*source)._Unchecked_begin();
    Unk_IngRef* end = (Unk_IngRef*)reinterpret_cast<VIng&>(*source)._Unchecked_end();
    for (; it != end; ++it) {
        Unk_IngRef ref(*it);
        if (ref == 0) continue;
        Unk_IngRef copy(new CIngredientInfo(ref->m_a, ref->m_c, ref->m_b));
        m_items.FUN_14028b330(copy);
    }
}
// @0x14026b890
bool CIngredientContainer::IsDifferentFrom(CIngredientContainer* other) {
    if (reinterpret_cast<VIng&>(m_items).size() != reinterpret_cast<VIng&>(other->m_items).size()) return true;
    size_t count = reinterpret_cast<VIng&>(m_items).size();
    for (size_t i = 0; i < count; ++i) {
        if (m_items.FUN_14027f1f0(i)->FUN_140281f10()->IsDifferent(other->m_items.FUN_14027f220(i)->FUN_140281f10())) return true;
    }
    return false;
}
// @0x14026b980
CIngredientContainer::~CIngredientContainer() { reinterpret_cast<VIng&>(m_items).clear(); }
// @0x14026b9d0
void CIngredientContainer::FUN_14026b9d0(const CStringW& text) {
    std::vector<CString> parts;   // C3: was Unk_StrVec
    FUN_140275180(const_cast<CStringW&>(text), &parts, L",");
    if (parts.size() != 3) return;
    Unk_IngRef ref(new CIngredientInfo());
    {
        std::vector<CString> sub;   // C3: was Unk_StrVec
        FUN_140275080(parts[0], &sub, ":");
        if (sub.size() > 0) ref->m_a = FUN_1407181d0(sub[0]);
        if (sub.size() > 1) ref->m_b = TSingleton<CItemDataTable>::GetInstance()->GetTagByName(sub[1]);
    }
    ref->m_c = FUN_1407181d0(parts[2]);
    if (ref->m_a != 0) AddIngredient(Unk_IngRef(ref));
}
// @0x14026bbf0
void CIngredientContainer::FUN_14026bbf0(int a, int b) {
    if (a == 0 || b == 0) return;
    Unk_IngRef ref(new CIngredientInfo(a, b, 0));
    m_items.FUN_14028b300(ref);
}
// @0x14026bca0
void CIngredientContainer::AddIngredient(Unk_IngRef r) {
    if (r == 0) return;
    m_items.FUN_14028b330(r);
}
// @0x14026bd10
void CIngredientContainer::FUN_14026bd10(int a, int b) {
    if (a == 0 || b == 0) return;
    Unk_IngRef ref(new CIngredientInfo(0, b, a));
    m_items.FUN_14028b300(ref);
}
// @0x14026bdc0
Unk_IngRef CIngredientContainer::FUN_14026bdc0(size_t index) {
    if (index >= FUN_14026bee0()) return Unk_IngRef(0);
    return *reinterpret_cast<Unk_IngRef*>(&reinterpret_cast<VIng&>(m_items).at(index));
}
// @0x14026be50
Unk_IngRef CIngredientContainer::FUN_14026be50(size_t index) {
    if (index >= FUN_14026bf10()) return Unk_IngRef(0);
    return *(Unk_IngRef*)&reinterpret_cast<const VIng&>(m_items).at(index);
}
// @0x14026bee0
size_t CIngredientContainer::FUN_14026bee0() { return reinterpret_cast<VIng&>(m_items).size(); }
// @0x14026bf10
size_t CIngredientContainer::FUN_14026bf10() { return reinterpret_cast<VIng&>(m_items).size(); }
// @0x14026bf40
bool CIngredientContainer::FUN_14026bf40() { return reinterpret_cast<VIng&>(m_items).empty(); }
// @0x14026bf70
bool CIngredientContainer::FUN_14026bf70() { return reinterpret_cast<VIng&>(m_items).empty(); }
// @0x14026bfa0
void CIngredientContainer::FUN_14026bfa0(size_t n) { reinterpret_cast<VIng&>(m_items).reserve(n); }
// @0x14026bfd0
void CIngredientContainer::Write(COutputStream& out) {
    unsigned char count = (unsigned char)reinterpret_cast<VIng&>(m_items).size();
    out.WriteUInt8(count);
    for (size_t i = 0; i < count; ++i) {
        Unk_IngRef ref(*reinterpret_cast<Unk_IngRef*>(&reinterpret_cast<VIng&>(m_items).at(i)));
        if (ref == 0) continue;
        ref->FUN_14026b3a0(out);
    }
}
// @0x14026c0b0
void CIngredientContainer::Read(CInPacket& in) {
    reinterpret_cast<VIng&>(m_items).clear();
    size_t count = in.ReadUInt8();
    reinterpret_cast<VIng&>(m_items).reserve(count);
    for (size_t i = 0; i < count; ++i) {
        Unk_IngRef ref(new CIngredientInfo());
        if (ref == 0) continue;
        ref->FUN_14026b410(in);
        AddIngredient(ref);
    }
}
// @0x14026c230
Unk_IngVec* CIngredientContainer::FUN_14026c230() { return &m_items; }
// @0x14026c250
void CIngredientContainer::FUN_14026c250(CIngredientContainer* other) {
    if (other->FUN_14026bf40()) return;
    Unk_IngVec pending;
    size_t count = other->FUN_14026bee0();
    for (size_t i = 0; i < count; ++i) {
        Unk_IngRef cur = other->FUN_14026bdc0(i);
        if (cur == 0 || cur->IsEmpty()) continue;
        Unk_IngRef found = FUN_14026c450(cur->m_a);
        if (found.FUN_14027f250() != 0) {
            int* dst = &found->m_c;
            *dst = *dst + cur->m_c;
        } else {
            pending.FUN_14028b330(cur);
        }
    }
    if (!reinterpret_cast<VIng&>(pending).empty()) {
        Unk_It t30, t28, t20;
        Unk_It result;
        Unk_It pos = *m_items.FUN_14028aa90(&t30);
        m_items.FUN_14027c290(&result, pos, *pending.FUN_14028a260(&t20), *pending.FUN_14028aa90(&t28));
    }
}
// @0x14026c450
Unk_IngRef CIngredientContainer::FUN_14026c450(unsigned key) {
    int keyBuffer;
    Unk_It lower, t40, t48, t50;
    FUN_14027bf30(&lower, *m_items.FUN_14028a260(&t48), *m_items.FUN_14028aa90(&t40), *FUN_14026b540(&keyBuffer, key));
    if (FUN_14027f000(&lower, m_items.FUN_14028aa90(&t50))) return *reinterpret_cast<Unk_IngRef*>(&**reinterpret_cast<VIng::iterator*>(&lower));
    return Unk_IngRef(0);
}
// @0x14026c550
bool Unk_IngHolder::FUN_14026c550(Unk_IngHolder* other) {
    if (m_container.FUN_140281f00()->IsDifferentFrom(other->m_container.FUN_140281f00())) return true;
    return false;
}

// ---- DungeonRewardInfo ----------------------------------------------------------------------------------------
// @0x14026c5b0
DungeonRewardInfo::DungeonRewardInfo() {}
// @0x14026c610
DungeonRewardInfo::~DungeonRewardInfo() {}
// map<unsigned char,int> value_type.
struct Unk_RewardPair { unsigned char key; int value; };
// @0x14026c660
void DungeonRewardInfo::FUN_14026c660(COutputStream& out) {
    out.WriteInt32((int)reinterpret_cast<MapII&>(m_rewards).size());
    Unk_It t80, t88, t90, t98;
    Unk_RewardMap& rewards = m_rewards;
    Unk_It end = *rewards.FUN_14028a910(&t80);
    for (Unk_It it = *rewards.FUN_14028a130(&t88); FUN_14027ef80(&it, &end); ++*reinterpret_cast<MapII::const_iterator*>(&it)) {
        Unk_RewardPair* entry = (Unk_RewardPair*)(void*)&**reinterpret_cast<MapII::const_iterator*>(&it);
        out.WriteUInt8(entry->key);
        out.WriteInt32(entry->value);
    }
    out.WriteInt32((int)reinterpret_cast<VItem&>(m_items).size());
    Unk_ItemVec& items = m_items;
    Unk_It end2 = *items.FUN_14028aa30(&t90);
    for (Unk_It it2 = *items.FUN_14028a200(&t98); FUN_14027efc0(&it2, &end2); ++*reinterpret_cast<VItem::const_iterator*>(&it2)) {
        ItemEntity* item = (ItemEntity*)(void*)&**reinterpret_cast<VItem::const_iterator*>(&it2);
        out.WriteInt32(item->m_itemId);
        out.WriteInt32(item->m_count);
        out.WriteInt32(static_cast<ItemAble&>(*item).vfunc_o18_1());
        out.WriteBool(item->m_28);
        out.WriteBool(item->m_29);
        out.WriteBool(item->m_2b);
    }
}
// @0x14026c900
void DungeonRewardInfo::FUN_14026c900(CInPacket& in) {
    int count = in.ReadInt32();
    for (int i = 0; i < count; ++i) {
        unsigned key = in.ReadUInt8();
        int value = in.ReadInt32();
        m_rewards.FUN_14027f180(key) = value;
    }
    int itemCount = in.ReadInt32();
    for (int i = 0; i < itemCount; ++i) {
        m_items.FUN_14028b2a0(ItemEntity());
        Unk_It tmp;
        ItemEntity* item = &**reinterpret_cast<std::reverse_iterator<VItem::iterator>*>(m_items.FUN_14028b360(&tmp));
        item->m_itemId = in.ReadInt32();
        item->m_count = in.ReadInt32();
        item->SetRank(in.ReadInt32());
        item->m_28 = in.ReadBool();
        item->m_29 = in.ReadBool();
        item->m_2b = in.ReadBool();
    }
}
// @0x14026cbf0
__int64 DungeonRewardInfo::FUN_14026cbf0() {
    int key = 2;
    Unk_It found, t18;
    m_rewards.FUN_14028adf0(&found, &key);
    if (FUN_14027ee20(&found, m_rewards.FUN_14028a970(&t18))) return 0;
    return *(unsigned*)((char*)(void*)reinterpret_cast<MapII::const_iterator*>(&found)->operator->() + 4);
}
// @0x14026cc70
unsigned DungeonRewardInfo::FUN_14026cc70() {
    int key = 3;
    Unk_It found, t18;
    m_rewards.FUN_14028adf0(&found, &key);
    if (FUN_14027ee20(&found, m_rewards.FUN_14028a970(&t18))) return 0;
    return *(unsigned*)((char*)(void*)reinterpret_cast<MapII::const_iterator*>(&found)->operator->() + 4);
}
// @0x14026ccf0
__int64 DungeonRewardInfo::FUN_14026ccf0() {
    int key = 1;
    Unk_It found, t18;
    m_rewards.FUN_14028adf0(&found, &key);
    if (FUN_14027ee20(&found, m_rewards.FUN_14028a970(&t18))) return 0;
    return *(unsigned*)((char*)(void*)reinterpret_cast<MapII::const_iterator*>(&found)->operator->() + 4);
}
// @0x14026cd70
unsigned DungeonRewardInfo::FUN_14026cd70(unsigned key) {
    Unk_It t20, t18;
    Unk_It found = *m_rewards.FUN_14028ad10(&t20, (int*)&key);
    if (FUN_14027ee20(&found, m_rewards.FUN_14028a910(&t18))) return 0;
    return *(unsigned*)((char*)(void*)reinterpret_cast<MapII::const_iterator*>(&found)->operator->() + 4);
}
// @0x14026cdf0
void DungeonRewardInfo::Clear() {
    reinterpret_cast<MapII&>(m_rewards).clear();
    reinterpret_cast<VItem&>(m_items).clear();
}
// @0x14026ce30
bool DungeonRewardInfo::FUN_14026ce30() {
    if (reinterpret_cast<MapII&>(m_rewards).size() > 0) return true;
    if (reinterpret_cast<VItem&>(m_items).size() > 0) return true;
    return false;
}
// @0x14026ce80
void DungeonRewardInfo::FUN_14026ce80(unsigned key, int delta) {
    int* slot = &m_rewards.FUN_14027f180(key);
    *slot = *slot + delta;
}

// ---- WeddingHallReservationFee --------------------------------------------------------------------------------
// @0x14026e700
WeddingHallReservationFee::WeddingHallReservationFee() { Reset(); }
// @0x14026e750
WeddingHallReservationFee::~WeddingHallReservationFee() {}
// @0x14026e780
WeddingHallReservationFee& WeddingHallReservationFee::FUN_14026e780(const WeddingHallReservationFee& other) {
    Assign(other);
    return *this;
}
// @0x14026e7b0
void WeddingHallReservationFee::Reset() {
    m_total = 0;
    memset(m_values, 0, sizeof(m_values));
}
// @0x14026e7e0
void WeddingHallReservationFee::AddFee(const WeddingHallReservationFee& other) {
    m_total = m_total + other.m_total;
    for (int i = 0; i < 4; i = i + 1) m_values[i] = m_values[i] + other.m_values[i];
}
// @0x14026e860
void WeddingHallReservationFee::Assign(const WeddingHallReservationFee& other) {
    m_total = other.m_total;
    for (int i = 0; i < 4; i = i + 1) m_values[i] = other.m_values[i];
}
// @0x14026e8c0
void WeddingHallReservationFee::WriteTo(COutputStream& out) {
    for (int i = 0; i < 4; i = i + 1) out.WriteInt64(m_values[i]);
    out.WriteInt64(m_total);
}
// @0x14026e940
void WeddingHallReservationFee::ReadFrom(CInputStream& in) {
    for (int i = 0; i < 4; i = i + 1) m_values[i] = in.ReadInt64();
    m_total = in.ReadInt64();
}

// ---- NpcShopItemLife ------------------------------------------------------------------------------------------
// @0x14026e9b0
NpcShopItemLife::NpcShopItemLife() : m_type(0), m_value(0), m_time(), m_onlyVisible(false) {}
// @0x14026ea20
bool NpcShopItemLife::IsDifferentFrom(NpcShopItemLife* other) {
    if (m_type != other->m_type) return true;
    if (m_value != other->m_value) return true;
    if (m_time != other->m_time) return true;
    if (m_onlyVisible != other->m_onlyVisible) return true;
    return false;
}
// @0x14026eab0
Unk_ShopLifeRef NpcShopItemLife::Clone() {
    Unk_ShopLifeRef ref(new NpcShopItemLife());
    ref->m_type = m_type;
    ref->m_time = m_time;
    ref->m_value = m_value;
    ref->m_onlyVisible = m_onlyVisible;
    return ref;
}
// @0x14026ebc0
bool NpcShopItemLife::FUN_14026ebc0(void* xml) {
    FUN_1402767f0(xml, "itemLifeType", (unsigned*)&m_type);
    if (m_type == 0) return 0;
    switch (m_type) {
    case 1:
        XmlGetAttr((class TiXmlElement*)(xml), "itemLifeValue", (unsigned&)m_value);
        if (m_value == 0) return 0;
        break;
    case 3:
    case 4:
        XmlGetAttr((class TiXmlElement*)(xml), "itemLifeValue", (unsigned&)m_value);
        break;
    case 2: {
        ArrI parts;
        CString text;
        XmlGetAttr((class TiXmlElement*)(xml), "itemLifeDateTime", text);
        XmlSplit(text, parts, "-");
        if (parts.GetCount() == 6) {
            m_time = CMsTime(parts[0], parts[1], parts[2],
                             parts[3], parts[4], parts[5]);
        } else {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }
    XmlGetAttr((class TiXmlElement*)(xml), "onlyVisibleInLifePeriod", reinterpret_cast<bool&>(m_onlyVisible));
    return 1;
}
// @0x14026ee70
void NpcShopItemLife::Write(COutputStream& out) {
    out.WriteUInt8((unsigned char)m_type);
    switch (m_type) {
    case 1:
    case 3:
    case 4:
        out.WriteInt32(m_value);
        break;
    case 2:
        out.WriteInt64(m_time.Get());
        break;
    }
}
// @0x14026ef20
void NpcShopItemLife::Read(CInPacket& in) {
    m_type = in.ReadUInt8();
    switch (m_type) {
    case 1:
    case 3:
    case 4:
        m_value = in.ReadInt32();
        break;
    case 2:
        m_time = CMsTime(in.ReadInt64());
        break;
    }
}
// @0x14026f000
bool NpcShopItemLife::FUN_14026f000() { return m_onlyVisible == false; }
// @0x14026f040
bool NpcShopItemLife::FUN_14026f040(const CMsTime& now) {
    if (FUN_14026f000()) return true;
    return IsNotExpired(now);
}
// @0x14026f080
bool NpcShopItemLife::IsNotExpired(const CMsTime& now) {
    if (!FUN_14026f0f0()) return true;
    if (m_time.Get() > 0 && now > m_time) return false;
    return true;
}
// @0x14026f0f0
bool NpcShopItemLife::FUN_14026f0f0() {
    switch (m_type) {
    case 1:
        if (m_value == 0) return false;
        break;
    case 2:
        if (m_time.Get() == 0) return false;
        break;
    case 3:
    case 4:
        break;
    default:
        return false;
    }
    return true;
}
// @0x14026f170
__int64 NpcShopItemLife::FUN_14026f170() {
    switch (m_type) {
    case 1:
        return GetServerTime() + (unsigned)(m_value * 60);
    case 3: {
        __int64 local = GetServerTime();
        return GetNthWeekStart(&local, m_value);
    }
    case 4: {
        __int64 local = GetServerTime();
        return GetNthMonthStart(&local, m_value);
    }
    case 2:
        return m_time.Get();
    }
    return 0;
}

// ---- ItemDropItemLife -----------------------------------------------------------------------------------------
// @0x14026f220
ItemDropItemLife::ItemDropItemLife() : m_type(0), m_value(0), m_time() {}
// @0x14026f290
bool ItemDropItemLife::FUN_14026f290(void* xml) {
    FUN_1402767f0(xml, "itemLifeType", (unsigned*)&m_type);
    if (m_type == 0) return 0;
    switch (m_type) {
    case 1:
        XmlGetAttr((class TiXmlElement*)(xml), "itemLifeValue", (unsigned&)m_value);
        if (m_value == 0) return 0;
        break;
    case 3:
    case 4:
        XmlGetAttr((class TiXmlElement*)(xml), "itemLifeValue", (unsigned&)m_value);
        break;
    case 2: {
        ArrI parts;
        CString text;
        XmlGetAttr((class TiXmlElement*)(xml), "itemLifeDateTime", text);
        XmlSplit(text, parts, "-");
        if (parts.GetCount() == 6) {
            m_time = CMsTime(parts[0], parts[1], parts[2],
                             parts[3], parts[4], parts[5]);
        } else {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }
    return 1;
}
// @0x14026f520
__int64 ItemDropItemLife::FUN_14026f520() {
    switch (m_type) {
    case 1:
        return GetServerTime() + (unsigned)(m_value * 60);
    case 3: {
        __int64 local = GetServerTime();
        return GetNthWeekStart(&local, m_value);
    }
    case 4: {
        __int64 local = GetServerTime();
        return GetNthMonthStart(&local, m_value);
    }
    case 2:
        return m_time.Get();
    }
    return 0;
}
// @0x14026f5d0
bool ItemDropItemLife::FUN_14026f5d0() {
    switch (m_type) {
    case 1:
        if (m_value == 0) return false;
        break;
    case 2:
        if (m_time.Get() == 0) return false;
        break;
    case 3:
    case 4:
        break;
    default:
        return false;
    }
    return true;
}

// ---- CUserChangeableItemHistory -------------------------------------------------------------------------------
// @0x14026f650
CUserChangeableItemHistory::CUserChangeableItemHistory() {
    m_18 = 0; m_20 = 0; m_28 = 0; m_30 = 0; m_38 = 0; m_3c = 0; m_40 = 0; m_48 = 0;
}
// @0x14026f6f0
void CUserChangeableItemHistory::vfunc_1() {
    m_18 = 0; m_20 = 0; m_28 = 0; m_30 = 0; m_38 = 0; m_3c = 0; m_40 = 0; m_48 = 0;
}
// @0x14026f770
void CUserChangeableItemHistory::vfunc_2(COutputStream* out) {
    out->WriteInt64(m_18);
    out->WriteInt64(m_20);
    out->WriteInt64(m_28);
    out->WriteInt64(m_30);
    out->WriteInt32(m_38);
    out->WriteInt32(m_3c);
    out->WriteInt32(m_40);
    out->WriteInt64(m_48);
}
// @0x14026f850
void CUserChangeableItemHistory::vfunc_3(CInPacket* in) {
    m_18 = in->ReadInt64();
    m_20 = in->ReadInt64();
    m_28 = in->ReadInt64();
    m_30 = in->ReadInt64();
    m_38 = in->ReadInt32();
    m_3c = in->ReadInt32();
    m_40 = in->ReadInt32();
    m_48 = in->ReadInt64();
}

// ---- CChangeableHistoryInfo -----------------------------------------------------------------------------------
// @0x14026f9c0
CChangeableHistoryInfo::CChangeableHistoryInfo(int a, int b) : m_lock(), m_48(a), m_4c(b), m_total(0), m_list() {}
// @0x14026fa50
CChangeableHistoryInfo::~CChangeableHistoryInfo() { reinterpret_cast<LHist&>(m_list).clear(); }
// @0x14026fab0
void CChangeableHistoryInfo::FUN_14026fab0() {
    Unk_1401b4ec0 lock(m_lock, 1);
    int total = 0;
    Unk_It it, saved, t30, t28;
    m_list.FUN_14028a1a0(&it);
    while (FUN_14027ef00(&it, m_list.FUN_14028a9d0(&t30))) {
        Unk_HistRef ref(*reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::iterator*>(&it)));
        if (ref == 0) {
            saved = it;
            it = *m_list.FUN_14028aca0(&t28, saved);
            continue;
        }
        total = total + ref->m_40;
        ++*reinterpret_cast<LHist::iterator*>(&it);
    }
    m_total = total;
}
// @0x14026fc00
int CChangeableHistoryInfo::FUN_14026fc00(int mode, __int64 id) {
    int total = 0;
    Unk_1401b4ec0 lock(m_lock, 1);
    if (mode == 1) {
        Unk_HistList* list = &m_list;
        Unk_It cur, end;
        list->FUN_140289d20(&cur);
        list->FUN_140289d80(&end);
        for (; FUN_14027ef40(&cur, &end); ++*reinterpret_cast<LHist::_Unchecked_iterator*>(&cur)) {
            Unk_HistRef* ref = reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::_Unchecked_iterator*>(&cur));
            total = total + (*ref)->m_40;
        }
    } else if (mode == 2) {
        Unk_HistList* list = &m_list;
        Unk_It cur, end;
        list->FUN_140289d20(&cur);
        list->FUN_140289d80(&end);
        for (; FUN_14027ef40(&cur, &end); ++*reinterpret_cast<LHist::_Unchecked_iterator*>(&cur)) {
            Unk_HistRef* ref = reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::_Unchecked_iterator*>(&cur));
            if ((*ref)->m_28 != id) continue;
            total = total + (*ref)->m_40;
        }
    }
    return total;
}
// @0x14026fda0
void CChangeableHistoryInfo::FUN_14026fda0(Unk_HistRef entry) {
    if (entry == 0) return;
    if ((__int64)m_48 != entry->m_30) return;
    if (!(m_4c == entry->m_3c)) return;
    Unk_1401b4ec0 lock(m_lock, 1);
    m_list.FUN_14028b260(entry);
    m_total = m_total + entry->m_40;
}
// @0x14026fea0
bool CChangeableHistoryInfo::FUN_14026fea0(__int64 id) {
    Unk_1401b4ec0 lock(m_lock, 1);
    Unk_It it, saved, t20, t18;
    m_list.FUN_14028a1a0(&it);
    for (; FUN_14027ef00(&it, m_list.FUN_14028a9d0(&t20)); ++*reinterpret_cast<LHist::iterator*>(&it)) {
        if ((*reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::iterator*>(&it)))->m_18 == id) {
            m_total = m_total - (*reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::iterator*>(&it)))->m_40;
            saved = it;
            m_list.FUN_14028aca0(&t18, saved);
            return true;
        }
    }
    return false;
}
// @0x14026ffd0
Unk_HistRef CChangeableHistoryInfo::FUN_14026ffd0() {
    Unk_1401b4ec0 lock(m_lock, 1);
    if (reinterpret_cast<LHist&>(m_list).size() == 0) return Unk_HistRef(0);
    Unk_HistRef best(*m_list.FUN_14028aef0());
    Unk_It t30, it;
    FUN_14027c480(&it, *m_list.FUN_14028a1a0(&t30), 1);
    Unk_It t28;
    for (; FUN_14027ef00(&it, m_list.FUN_14028a9d0(&t28)); ++*reinterpret_cast<LHist::iterator*>(&it)) {
        if ((*reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::iterator*>(&it)))->m_38 < best->m_38) best.FUN_14027eab0(*reinterpret_cast<Unk_HistRef*>(&**reinterpret_cast<LHist::iterator*>(&it)));
    }
    return best;
}

// ---- ChangeableProductInfo ------------------------------------------------------------------------------------
// @0x140270170
ChangeableProductInfo::ChangeableProductInfo()
    : m_18(4), m_1c(1), m_20(0), m_24(0), m_28((__time64_t)0), m_38((__time64_t)0), m_48((__time64_t)0), m_58(false), m_5c(0x3c) {}
// @0x140270230
void ChangeableProductInfo::FUN_140270230(Unk_ProdRef other) {
    m_18 = other->m_18;
    m_1c = other->m_1c;
    m_20 = other->m_20;
    m_24 = other->m_24;
    m_28 = other->m_28;
    m_38 = other->m_38;
    m_48 = other->m_48;
    m_58 = other->m_58;
}
// @0x140270330
bool ChangeableProductInfo::FUN_140270330(const CMsTime& now) {
    if (m_18 != 2) return false;
    if (m_58 == false) return false;
    if (m_38.Get() < now.Get()) return true;
    return false;
}
// @0x1402703a0
bool ChangeableProductInfo::FUN_1402703a0(const CMsTime& now) {
    if (m_58 != false) {
        if (m_18 != 3) return false;
        if (m_38.Get() + m_5c < now.Get()) return true;
    } else {
        if (m_18 != 2) return false;
        if (m_38.Get() < now.Get()) return true;
    }
    return false;
}

// @0x140270450
bool ChangeableProductInfo::FUN_140270450(const CMsTime& now) {
    if (m_18 == 1) {
        CMsTime tmp(now.Get());
        if (m_28 < tmp) return true;
    }
    return false;
}

// ---- HomeBlockInfo --------------------------------------------------------------------------------------------
// @0x1402704b0
HomeBlockInfo::HomeBlockInfo() { FUN_140270530(); }
// @0x140270530
void HomeBlockInfo::FUN_140270530() {
    m_18 = 0; m_20 = 0; m_28 = 0;
    m_30.Empty();
    m_38 = 0; m_3c = 0; m_40 = 0;
    m_48.Empty();
    m_50.Empty();
}
// @0x1402705d0
void HomeBlockInfo::FUN_1402705d0(COutputStream& out) {
    out.WriteInt64(m_18);
    out.WriteInt64(m_20);
    out.WriteInt64(m_28);
    out.WriteUnicodeStringA(m_30);
    out.WriteInt16(m_38);
    out.WriteInt32(m_3c);
    out.WriteInt32(m_40);
    out.WriteUnicodeStringA(m_48);
    out.WriteUnicodeStringA(m_50);
}
// @0x1402706f0
void HomeBlockInfo::FUN_1402706f0(CInPacket& in) {
    m_18 = in.ReadInt64();
    m_20 = in.ReadInt64();
    m_28 = in.ReadInt64();
    m_30 = in.ReadUnicodeStringA();
    m_38 = in.ReadInt16();
    m_3c = in.ReadInt32();
    m_40 = in.ReadInt32();
    m_48 = in.ReadUnicodeStringA();
    m_50 = in.ReadUnicodeStringA();
}
