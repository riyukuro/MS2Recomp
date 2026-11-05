// itemdroptable.h - the item drop tables (RTTI .?AVItemDropTable@@ and the ItemDrop* data classes). The class names
// come from RTTI; the member names are the xml attribute names where the loaders read them, invented otherwise.
// Recovered from the first TU of the queue row commonfiles\dungeonmatch.cpp (0x1402e6c50-0x1403142a0); the original
// file name is unknown.
#pragma once

#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/itemgift.h"

unsigned FUN_140767ff0();                                   // random number

// Weighted random choice. Every entry is keyed by the running weight total, so a roll in 1..total finds the entry it
// falls on with lower_bound. Names invented (they keep the exe's COMDAT order).
template <class T>
class ItemDropPicker
{
public:
    struct Entry
    {
        Entry() : weight(0), index(0) {}
        T value;
        unsigned weight;
        int index;                                          // insertion order
    };

    ItemDropPicker() : m_total(0) {}
    // Adds value with the given weight (ignored when 0).
    void Register(unsigned weight, T value)
    {
        if (weight < 1)
            return;
        m_total += weight;
        Entry entry;
        entry.value = value;
        entry.weight = weight;
        entry.index = (int)m_entries.size();
        m_entries.insert(std::make_pair(m_total, entry));
    }
    bool Pick(Entry& out) const
    {
        if (m_total == 0)
            return false;
        unsigned roll = FUN_140767ff0() % m_total + 1;
        typename std::map<unsigned, Entry>::const_iterator it = m_entries.lower_bound(roll);
        if (it == m_entries.end())
            return false;
        out = it->second;
        return true;
    }
    bool Pick(T& out) const
    {
        Entry entry;
        if (Pick(entry) == true)
        {
            out = entry.value;
            return true;
        }
        return false;
    }
    bool Query(T value)
    {
        for (typename std::map<unsigned, Entry>::const_iterator it = m_entries.begin(); it != m_entries.end(); ++it)
        {
            if (it->second.value == value)
                return true;
        }
        return false;
    }
    unsigned GetTotal() { return m_total; }
    bool Remains() const
    {
        if (m_total == 0)
            return false;
        return true;
    }
    // Scales every weight but the one of except by rate; except gets what the others lost (or gave up).
    void Rescale(float rate, T except)
    {
        std::map<unsigned, Entry> entries(m_entries.begin(), m_entries.end());
        typename std::map<unsigned, Entry>::iterator it = entries.begin();
        typename std::map<unsigned, Entry>::iterator itEnd = entries.end();
        m_total = 0;
        m_entries.clear();
        int remainder = 0;
        int previous = 0;
        for (; it != itEnd; ++it)
        {
            int weight = it->first - previous;
            previous = it->first;
            if (it->second.value == except)
            {
                remainder += weight;
                continue;
            }
            unsigned scaled = weight * rate;
            Register(scaled, it->second.value);
            remainder -= scaled - weight;
        }
        if (remainder > 0)
            Register(remainder, except);
    }

private:
    MS2_LAYOUT_FRIEND;
    std::map<unsigned, Entry> m_entries;
    unsigned m_total;
};

// A count range: min..max picked uniformly.
struct ItemDropCount
{
    ItemDropCount() : m_min(0), m_max(0) {}
    void Range(unsigned nMin, unsigned nMax)
    {
        m_min = nMin;
        m_max = nMax;
    }
    unsigned GetValue()
    {
        if (m_max > m_min)
            return rand() % (m_max - m_min + 1) + m_min;
        return m_min;
    }
    unsigned GetValueScaled(float fMinRate, float fMaxRate)
    {
        unsigned nMin = m_min * fMinRate;
        unsigned nMax = m_max * fMaxRate;
        if (nMax > nMin)
            return nMin + rand() % (nMax - nMin + 1);
        return nMin;
    }
    unsigned m_min;
    unsigned m_max;
};
MS2_CHECK_SIZE(ItemDropCount, 8);

enum ItemDropGrade {};                                      // item rank (1..)
enum ItemDropMapType {};                                    // CFieldData mapType
enum ItemDropTooltip {};                                    // "showTooltip" (2: hidden from the box tooltip)

class ItemDropData;
// A drop filter: the virtual decides whether a data entry may drop.
class ItemDropFilter
{
public:
    virtual bool Accept(ItemDropData* pData) = 0;
};

class ItemDropData : public CPtred
{
public:
    ItemDropData();
    virtual bool Load(TiXmlElement* pElem);
    virtual CString GetTypeName();
    // The rank to drop: a random option rank when no grade list is given.
    virtual int GetDropRank(int nArg, int nLevel, bool bAssist);
    virtual int PickGrade();

    void OnLoad();
    bool Check(unsigned nMapId, bool bAssist, ItemDropFilter* pFilter);
    bool CheckMap(unsigned nMapId) const;
    bool CheckAssist(bool bAssist);
    bool CheckFilter(ItemDropFilter* pFilter);
    unsigned GetCount();
    unsigned GetCountScaled(float fRate);
    unsigned GetMaxCount();
    unsigned GetMinCount();
    unsigned GetItemId();
    unsigned GetItemId2();
    unsigned GetWeight();
    int GetRank();
    int GetEnchantLevel();
    bool IsTradableCountDeduction();
    unsigned GetSocketDataId();
    bool IsShowIconOnGachaUI();
    bool IsConstraintsQuest();
    bool IsBindCharacter();
    bool IsRePackingLimitCountDeduction();
    bool IsDisableBreak();
    bool HasGrade(ItemDropGrade grade);
    void Reset(void* p);
    bool IsValid();

    MS2_LAYOUT_FRIEND;
    unsigned m_itemID;                                         // +0x18
    unsigned m_itemID2;                                         // +0x1c
    unsigned m_weight = 1;                                  // +0x20
    bool m_assistBonus = false;                             // +0x24
    int m_uiItemRank = 0;                                   // +0x28
    bool m_constraintsQuest = false;                        // +0x2c
    int m_enchantLevel = 0;                                 // +0x30
    unsigned m_socketDataID = 0;                            // +0x34
    bool m_tradableCountDeduction = false;                  // +0x38
    bool m_isBindCharacter = false;                         // +0x39
    bool m_rePackingLimitCountDeduction = false;            // +0x3a
    bool m_disableBreak = false;                            // +0x3b
    bool m_showIconOnGachaUI = true;                        // +0x3c
    std::set<unsigned> m_mapDependency;                     // +0x40
    ItemDropCount m_count;                                  // +0x50 minCount/maxCount
    ItemDropPicker<ItemDropGrade> m_grade;                  // +0x58 grade/gradeProbability
    MS2Ptr<ItemDropItemLife> m_itemLife;                    // +0x70
};
MS2_CHECK_SIZE(ItemDropData, 0x80);
MS2_CHECK_OFFSET(ItemDropData, m_mapDependency, 0x40);
MS2_CHECK_OFFSET(ItemDropData, m_itemLife, 0x70);

class ItemDropDataGlobal : public ItemDropData
{
public:
    ItemDropDataGlobal();
    virtual bool Load(TiXmlElement* pElem);
    virtual CString GetTypeName();
    bool CheckLevel(unsigned nLevel);
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_minLevel;                                    // +0x80
    unsigned m_maxLevel;                                    // +0x84
};
MS2_CHECK_SIZE(ItemDropDataGlobal, 0x88);

class ItemDropDataIndividual : public ItemDropData
{
public:
    ItemDropDataIndividual();
    virtual bool Load(TiXmlElement* pElem);
    virtual CString GetTypeName();
    unsigned GetProperJobWeight();
    unsigned GetImProperJobWeight();
    bool IsAnnounce();
    ItemDropTooltip GetShowTooltip();
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_properJobWeight;                             // +0x80
    unsigned m_imProperJobWeight;                           // +0x84
    bool m_isAnnounce;                                      // +0x88
    ItemDropTooltip m_showTooltip;                          // +0x8c
};
MS2_CHECK_SIZE(ItemDropDataIndividual, 0x90);

class ItemDropGlobalGroup : public CPtred
{
public:
    ItemDropGlobalGroup();
    bool Load(TiXmlElement* pElem);
    unsigned GetId();
    std::vector<MS2Ptr<ItemDropDataGlobal>>& GetItems();
    void Add(MS2Ptr<ItemDropDataGlobal> pData);
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_dropGroupID;                                 // +0x18
    std::vector<MS2Ptr<ItemDropDataGlobal>> m_items;        // +0x20
};
MS2_CHECK_SIZE(ItemDropGlobalGroup, 0x38);

class ItemDropGlobalBox : public CPtred
{
public:
    ItemDropGlobalBox();
    bool Load(TiXmlElement* pElem);
    unsigned GetUnk18();
    unsigned GetDropCount(float fRate) const;
    unsigned GetDropGroupId();
    bool IsOwnerDrop();
    bool CheckMap(int nMapId);
    bool CheckLevel(unsigned nLevel);
    bool CheckContinent(int nMapId);
    bool CheckMapType(int nMapId);
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_unk_18;                                      // +0x18
    std::map<int, ItemDropPicker<int>> m_dropCount;         // +0x20 keyed by the drop rate in percent
    unsigned m_dropGroupIDs;                                 // +0x30
    bool m_isOwnerDrop;                                     // +0x34
    unsigned m_minLevel;                                    // +0x38
    unsigned m_maxLevel;                                    // +0x3c
    int m_continentCondition;                               // +0x40
    ItemDropMapType m_mapTypeCondition;                     // +0x44
};
MS2_CHECK_SIZE(ItemDropGlobalBox, 0x48);

class ItemDropGlobalBoxGroup : public CPtred
{
public:
    ItemDropGlobalBoxGroup();
    unsigned GetId();
    bool Load(TiXmlElement* pElem);
    std::vector<MS2Ptr<ItemDropGlobalBox>>& GetBoxes();
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_dropBoxID;                                   // +0x18
    std::vector<MS2Ptr<ItemDropGlobalBox>> m_boxes;         // +0x20
};
MS2_CHECK_SIZE(ItemDropGlobalBoxGroup, 0x38);

class ItemDropIndividualGroup : public CPtred
{
public:
    ItemDropIndividualGroup();
    virtual ~ItemDropIndividualGroup();
    unsigned GetId();
    int PickDropCount();
    unsigned GetSmartDropRate();
    bool Load(TiXmlElement* pElem);
    bool CheckLevel(unsigned nLevel);
    bool IsApplySmartGenderDrop();
    bool IsServerDrop();
    std::vector<MS2Ptr<ItemDropDataIndividual>>& GetItems();
    ItemDropPicker<ItemDropDataIndividual*>* GetDataPicker() { return &m_dataPicker; }

    MS2_LAYOUT_FRIEND;
    unsigned m_dropGroupID;                                 // +0x18
    ItemDropPicker<int> m_dropCount;                        // +0x20 dropCount/dropCountProbability
    ItemDropPicker<ItemDropDataIndividual*> m_dataPicker;   // +0x38
    std::vector<MS2Ptr<ItemDropDataIndividual>> m_items;    // +0x50
    unsigned m_dropGroupMinLevel;                           // +0x68
    unsigned m_smartDropRate;                               // +0x6c
    bool m_isApplySmartGenderDrop;                          // +0x70
    bool m_serverDrop;                                      // +0x71
};
MS2_CHECK_SIZE(ItemDropIndividualGroup, 0x78);

class ItemDropIndividualBox : public CPtred
{
public:
    ItemDropIndividualBox();
    bool Load(TiXmlElement* pElem);
    unsigned GetId();
    unsigned GetProbVer();

    MS2_LAYOUT_FRIEND;
    std::vector<MS2Ptr<ItemDropIndividualGroup>> m_groups;  // +0x18
    unsigned m_dropBoxID;                                   // +0x30
    unsigned m_probVer;                                     // +0x34
};
MS2_CHECK_SIZE(ItemDropIndividualBox, 0x38);

// The drop request (the dropper and the looter).
struct ItemDropContext
{
    ItemDropContext();
    // The level the global drop tables are checked against.
    int GetLevel();

    int m_unk_00;                                           // +0x00
    int m_job;                                              // +0x04
    int m_gender;                                           // +0x08 (2: any)
    int m_mapId;                                            // +0x0c
    bool m_isOwner;                                         // +0x10
    int m_level;                                            // +0x14
    int m_userLevel;                                        // +0x18
    int m_rankArg;                                          // +0x1c
    bool m_isAssist;                                        // +0x20
    float m_dropRate;                                       // +0x24
    bool m_serverDrop;                                      // +0x28
    ItemDropFilter* m_pFilter;                              // +0x30
};
MS2_CHECK_SIZE(ItemDropContext, 0x38);

class ItemDropResult : public ItemAble, public CPtred
{
public:
    ItemDropResult();
    ItemDropResult(unsigned nItemId, unsigned nCount, int nRank, int nEnchant, unsigned nWeight, unsigned nTotalWeight,
                   unsigned nGroupId, bool bSmartGender, bool bAnnounce, int nTooltip, bool bTradable,
                   bool bIsBind, bool bRePacking, bool bDisableBreak);
    bool operator<(ItemDropResult& o);
    virtual unsigned int vfunc_o18_0();                     // item id
    virtual int vfunc_o18_1();                              // rank
    virtual unsigned int vfunc_o18_2();                     // count
    virtual bool vfunc_o18_3();                             // tradable count deduction
    bool IsRePackingLimitCountDeduction();
    bool IsDisableBreak();
    bool Set(MS2Ptr<ItemDropDataIndividual> pData);
    double GetProbability();
    bool HasItemLife();
    void SetRank(int nRank);

    unsigned m_itemId;                                         // +0x20
    unsigned m_count;                                       // +0x24
    unsigned m_maxCount;                                    // +0x28
    bool m_bAnnounce;                                       // +0x2c
    int m_enchant;                                          // +0x30
    unsigned m_socketDataId;                                // +0x34
    int m_tooltip;                                          // +0x38
    bool m_tradableCountDeduction;                          // +0x3c
    bool m_rePackingLimitCountDeduction;                    // +0x3d
    bool m_isBindCharacter;                                 // +0x3e
    bool m_disableBreak;                                    // +0x3f
    bool m_bServerDrop;                                     // +0x40
    bool m_showIconOnGachaUI;                               // +0x41
    unsigned m_weight;                                      // +0x44
    unsigned m_totalWeight;                                 // +0x48
    unsigned m_groupId;                                       // +0x4c
    bool m_smartGender;                                     // +0x50
    MS2Ptr<ItemDropItemLife> m_itemLife;                    // +0x58
    int m_rank;                                             // +0x68
};
MS2_CHECK_SIZE(ItemDropResult, 0x70);
// ItemDropResult reaches CPtred through its second base (+0x8): the pointer and the reference-count tag go through
// a CPtred* conversion (null-checked adjust) instead of the zero-offset no-op of the generic bodies.
template <> inline void MS2Ptr<ItemDropResult>::AddRef() const
{
    if (m_p)
        AddRefImpl(static_cast<CPtred*>((ItemDropResult*)0));
}
template <> inline void MS2Ptr<ItemDropResult>::Release()
{
    if (m_p)
    {
        ReleaseImpl(static_cast<CPtred*>((ItemDropResult*)0));
        m_p = 0;
    }
}
template <> inline MS2Ptr<ItemDropResult>::MS2Ptr(ItemDropResult* p)
{
    m_p = static_cast<ItemDropResult*>(static_cast<CPtred*>(p));
    AddRef();
}
MS2_CHECK_OFFSET(ItemDropResult, m_itemId, 0x20);
MS2_CHECK_OFFSET(ItemDropResult, m_itemLife, 0x58);

class ItemDropTable : public TSingleton<ItemDropTable>, public CValidData<ItemDropTable>
{
public:
    ItemDropTable();                                        // 0x1402e9940
    virtual ~ItemDropTable();
    bool Initialize();
    void Drop(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out);
    void DropGlobal(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out);
    bool GetBoxItems(unsigned nBoxId, std::vector<ItemDropResult>& out);
    bool GetBoxItems(unsigned nBoxId, std::vector<MS2Ptr<ItemDropResult>>& out);
    bool GetBoxItems(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out, bool bSkipHidden);
    bool GetUniqueBoxItems(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out);
    static bool IsGlobalBox(unsigned nBoxId);
    bool HasGlobalBox(unsigned nBoxId);
    bool HasIndividualBox(unsigned nBoxId);
    void Clear();
    bool HasItem(unsigned nBoxId, int nItemId, int nRank);
    void DropGroup(unsigned nBoxId, unsigned nGroupId, ItemDropContext& ctx, std::vector<ItemDropResult>& out);
    bool HasServerDrop(unsigned nBoxId);
    MS2Ptr<ItemDropIndividualBox> GetIndividualBox(unsigned nBoxId);
    bool LoadGlobalBoxes();
    bool LoadGlobalGroups();
    bool LoadIndividualBoxes();
    void DropIndividualGroup(ItemDropIndividualGroup* pGroup, ItemDropContext& ctx, std::vector<ItemDropResult>& out);
    void DropIndividual(unsigned nBoxId, ItemDropContext& ctx, std::vector<ItemDropResult>& out);

    static void CheckInit();                                // message box when the table is not loaded
    static void SetInit(bool b);
    static bool s_bInit;                                    // 0x143aad178
private:
    MS2_LAYOUT_FRIEND;
    std::unordered_map<unsigned, MS2Ptr<ItemDropGlobalGroup>> m_globalGroups;        // +0x10
    std::unordered_map<unsigned, MS2Ptr<ItemDropGlobalBoxGroup>> m_globalBoxes;      // +0x50
    std::unordered_map<unsigned, MS2Ptr<ItemDropIndividualBox>> m_individualBoxes;   // +0x90
    CLockCriticalSection m_lock;                                                // +0xd0
    // +0x100, never used here. 0x28-byte nodes (4-byte key, bool), but its tree COMDATs are distinct from the
    // map<int, bool> / map<unsigned, bool> copies elsewhere: an unsigned long (DWORD) key keeps them apart.
    std::map<unsigned long, bool> m_unk_100;
};
MS2_CHECK_SIZE(ItemDropTable, 0x110);
MS2_CHECK_OFFSET(ItemDropTable, m_lock, 0xd0);
