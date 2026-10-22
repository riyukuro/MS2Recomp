// itemoptiondata.h - the item option tables' value classes (ItemOptionValue/Ref/Random, ItemOptionConstant,
// ItemOptionVariationData, ItemOptionRandom, ItemOptionRandomContext). Recovered from the second TU of the
// commonfiles\itemoptiondata.cpp range (0x1405ce250-0x1405f4140). Class names are RTTI; member names are by address
// unless a comment names the xml attribute they hold.
#pragma once
#include <vector>
#include <utility>
#include <functional>
#include <map>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // SAType

class CItemData;
class CItemOption;
class Unk_140165cf0;                // game TinyXML element
class Unk_Random;                   // randomeffectparam.h
class ItemOptionRandom;
class ItemOptionValueRandom;
class Unk_ItemOptionPreset;
class Unk_1405e74c0;                // the reroll request a random context works on (below)
namespace Probability { class LogContext; }     // probability.cpp: one logged roll
typedef std::vector<MS2Ptr<Probability::LogContext> > Unk_ProbabilityLog;

// A fixed or lua-computed stat value of an option row (<option name value> in itemoptionconstant.xml).
class ItemOptionValue : public CPtred
{
public:
    ItemOptionValue();                          // 0x1405ce250
    ItemOptionValue(int nStat);                 // 0x1405ce2b0
    ItemOptionValue(unsigned nSpecial);         // 0x1405ce310
    int FUN_1405ce370();                        // the stat (-1 for a special stat)
    unsigned FUN_1405ce390();                   // the special stat
    bool FUN_1405ce3b0();                       // the value is set
    bool FUN_1405ce3f0();
    BOOL FUN_1405ce470();                       // a special stat
    CString FUN_1405ce4a0();                    // the xml name of the stat
    int FUN_1405ce530();                        // the value
    void FUN_1405ce550(int nValue);             // sets the value
    virtual int vfunc_1(unsigned nItemId, int nRank);   // slot 1: the value for an item
protected:
    int m_nValue;                               // +0x18 "value"
    int m_nStat;                                // +0x1c
    unsigned m_nSpecial;                        // +0x20
};
MS2_CHECK_SIZE(ItemOptionValue, 0x28);

// A value computed from the item (createType 3 rows; the formulas of the server's lua scripts).
class ItemOptionValueRef : public ItemOptionValue
{
public:
    ItemOptionValueRef();                       // 0x1405ce590
    ItemOptionValueRef(int nStat);              // 0x1405ce5d0
    ItemOptionValueRef(unsigned nSpecial);      // 0x1405ce620
    int FUN_1405ce670(unsigned nItemId, int nRank);
    virtual int vfunc_1(unsigned nItemId, int nRank);
    int FUN_1405cf260(int nStat, int nLevel, int nRank);
    int FUN_1405cf350(int nStat, int nLevel, int nRank);
    int FUN_1405cf430(int nStat, int nLevel, int nRank);
    int FUN_1405cf510(int nLevel, int nRank);
    int FUN_1405cf650(int nStat, int nLevel);
    int FUN_1405cf6e0(int nStat, int nLevel, int nRank, int nOptionLevel);
    int FUN_1405cfb10(int nStat, int nLevel);
    int FUN_1405cfd10(int nLevel);
    int FUN_1405cfd50(int nStat, int nJob, int nOptionLevel);
    int FUN_1405cfec0(int nStat, int nJob, int nOptionLevel);
    int FUN_1405d0030(int nStat, int nJob, int nOptionLevel, bool bMultiJob);
    int FUN_1405d01e0(int nStat, int nJob, int nOptionLevel);
    int FUN_1405d0340(int nStat, int nRank);
    int FUN_1405d04a0(int nStat, int nJob, int nLevel, int nRank, int nOptionLevel);
    int FUN_1405d0780(int nStat, int nJob, int nLevel, int nRank, int nOptionLevel);
    int FUN_1405d0c10(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel, bool bNegate);
    int FUN_1405d0dd0(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel);
    int FUN_1405d0f90(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel);
    int FUN_1405d1440(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel);
    int FUN_1405d17c0(int nLevel, double dScale);
    double FUN_1405d1850(int nLevel, double dBase, double dStep, double dScale);
    double FUN_1405d18a0(int nLevel, double dBase, double dStep, double dScale);
    double FUN_1405d18f0(int nLevel, double dA, double dB, double dC);
    int FUN_1405d1960(int nRank);
    double FUN_1405d19f0(int nRank);
    double FUN_1405d1aa0(int nRank);
    double FUN_1405d1b70(int nRank);
    double FUN_1405d1c40(int nRank, int nOptionLevel);
    double FUN_1405d1d70(int nStat);
    double FUN_1405d1e70(int nJob);
    double FUN_1405d2020(int nRank);
    double FUN_1405d20f0(int nStat);
    double FUN_1405d2250(int nStat);
    double FUN_1405d23b0(double dValue);
    int FUN_1405d2410(MS2Ptr<CItemData> spItem);
    friend class ItemOptionConstant;           // its createType 3 loader reads "luaIndex" in place
private:
    unsigned m_nLuaIndex;                       // +0x28 "luaIndex"
};
MS2_CHECK_SIZE(ItemOptionValueRef, 0x30);

enum ItemOptionStatGroup { };                   // "statGroup" (stored as a number; values not recovered)

// The state of one random option roll (itemoptionrandom.xml applied to an item option).
class ItemOptionRandomContext : public CPtred
{
public:
    ItemOptionRandomContext(MS2Ptr<CItemOption> spOption, int n, MS2Ptr<ItemOptionRandom> spRandom);  // 0x1405d9a50
    int FUN_1405d9b10(int nStatId);             // the table's value of a stat id (CItemOptionTable)
    int FUN_1405d9b40(int nStatId, Unk_Random* pRandom);
    int FUN_1405d9b80(int nStatId);
    int FUN_1405d9bb0(int nStatId);
    ItemOptionStatGroup FUN_1405d9e00();        // the random row's statGroup
    int FUN_1405d9e30();                        // m_n50
    void FUN_1405d9be0(MS2Ptr<Unk_1405e74c0> spTarget);    // sets the reroll request
    BOOL FUN_1405d9c30(CString strName);        // the option already holds a stat of the name's exclusive group
    BOOL FUN_1405d9d10(CString strName);        // the same for the reroll result
    MS2Ptr<CItemOption> FUN_1405d9e50();        // the option
    int FUN_1405d9ea0(MS2Ptr<ItemOptionValueRandom> spValue, Unk_Random* pRandom, unsigned* pCount, Unk_ProbabilityLog* pLogs);
    int FUN_1405da4b0(MS2Ptr<ItemOptionValueRandom> spValue, unsigned* pCount, int nIndex, Unk_ProbabilityLog* pLogs);
    int FUN_1405daad0(MS2Ptr<ItemOptionValueRandom> spValue, unsigned* pCount, Unk_ProbabilityLog* pLogs);
    BOOL FUN_1405db0b0(MS2Ptr<CItemOption> spOption, CString strName);
    int m_nType;                                // +0x18 which table value FUN_1405d2800 reads (1, 2 or other)
    MS2Ptr<CItemOption> m_spOption;             // +0x20
    MS2Ptr<Unk_1405e74c0> m_spTarget;           // +0x30
    MS2Ptr<ItemOptionRandom> m_spRandom;        // +0x40
    int m_n50;                                  // +0x50
};
MS2_CHECK_SIZE(ItemOptionRandomContext, 0x58);

// A weighted candidate of a random option row (<option name weight statID> in itemoptionrandom.xml).
class ItemOptionValueRandom : public CPtred
{
public:
    ItemOptionValueRandom();                    // 0x1405d2520
    bool FUN_1405d2590(Unk_140165cf0* pElem);   // xml read
    CString FUN_1405d26c0();                    // the xml name of the stat
    int FUN_1405d2750();                        // the stat (-1 for a special stat)
    unsigned FUN_1405d2770();                   // the special stat
    BOOL FUN_1405d2790();                       // a special stat
    int FUN_1405d27c0();                        // "statID"
    int FUN_1405d27e0();                        // "weight"
    int FUN_1405d2800(MS2Ptr<ItemOptionRandomContext> spContext);
    int FUN_1405d28d0(MS2Ptr<ItemOptionRandomContext> spContext, Unk_Random* pRandom);
    bool FUN_1405d29b0();                       // the special stat is a special ability
private:
    int m_nStat;                                // +0x18
    unsigned m_nSpecial;                        // +0x1c
    int m_nStatId;                              // +0x20 "statID"
    int m_nWeight;                              // +0x24 "weight"
};
MS2_CHECK_SIZE(ItemOptionValueRandom, 0x28);

// The fixed option rows of an item (itemoptionconstant.xml).
class ItemOptionConstant : public CPtred
{
public:
    ItemOptionConstant();                       // 0x1405d29f0
    void FUN_1405d2a50(int nValue);
    int FUN_1405d2a70();                        // "grade"
    bool FUN_1405d2a90(Unk_140165cf0* pElem);   // xml read
    void FUN_1405d2e70(MS2Ptr<CItemOption> spOption, int nRank);   // adds the rows to an option
    size_t FUN_1405d31f0();                     // the row count
    MS2Ptr<ItemOptionValue> FUN_1405d3220(int nStat);
    MS2Ptr<ItemOptionValue> FUN_1405d3300(unsigned nSpecial);
    void FUN_1405d33e0(std::function<void(ItemOptionValue*)> fnVisit);
    void FUN_1405d3490(Unk_140165cf0* pElem);   // xml read of createType 3 (lua computed) rows
private:
    int m_n18;                                  // +0x18
    int m_nGrade;                               // +0x1c "grade"
    std::vector<MS2Ptr<ItemOptionValue> > m_vValues;    // +0x20
};
MS2_CHECK_SIZE(ItemOptionConstant, 0x38);

unsigned FUN_140767ff0();                       // random number

// Weighted choice: every entry is keyed by the running weight total, so a roll in 1..total finds the entry it falls
// on with lower_bound. The same shape as ItemDropPicker (itemdroptable.h) plus picks with a given generator; names
// invented. T = int for the stat variation rows, ItemOptionValueRandom* for the random option rows.
template <class T>
class Unk_ItemOptionPicker
{
public:
    struct Entry
    {
        Entry() : weight(0), index(0) {}
        T value;
        unsigned weight;
        int index;                                  // insertion order
    };

    Unk_ItemOptionPicker() : m_total(0) {}
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
    bool Pick(Unk_Random* pRandom, T& out) const;       // itemoptiondata_2.cpp
    bool IsValid() const
    {
        if (m_total == 0)
            return false;
        return true;
    }
    // n distinct entries: each pick removes its entry and rebuilds the running totals of the rest.
    bool PickN(std::vector<T>& out, unsigned n, Unk_Random* pRandom) const;    // itemoptiondata_2.cpp
    // probability.cpp (the log of the picks): the running total, and removing the first entry holding a value
    // (0x1407432f0 / 0x140743300 for ItemOptionValueRandom*).
    unsigned GetTotal();
    bool PopFirstItemData(T value, Entry& out);

    std::map<unsigned, Entry> m_entries;
    unsigned m_total;
};
typedef Unk_ItemOptionPicker<int> Unk_ItemOptionStatPicker;
MS2_CHECK_SIZE(Unk_ItemOptionStatPicker, 0x18);
typedef Unk_ItemOptionPicker<ItemOptionValueRandom*> Unk_ItemOptionValuePicker;

// The stat variation rows (itemoptionvariation.xml): a weighted stat choice.
class ItemOptionVariationData : public CPtred
{
public:
    ItemOptionVariationData();                  // 0x1405d37e0
    void FUN_1405d3870(Unk_140165cf0* pElem);   // xml read
    int FUN_1405d3a20();                        // "id"
    int FUN_1405d3a40();                        // a random stat (0 when none)
    int FUN_1405d3a90(Unk_Random* pRandom);
    int FUN_1405d3ae0();                        // the first stat
    int FUN_1405d3b30() const;                   // the last stat
    int FUN_1405d3b80();                        // "highStat"
    bool FUN_1405d3ba0(int nStat);              // nStat reaches highStat
private:
    int m_nId;                                  // +0x18 "id"
    int m_nProbVer;                             // +0x1c "probVer"
    SAType m_eName;                             // +0x20 "name"
    int m_nHighStat;                            // +0x24 "highStat"
    std::vector<std::pair<int, unsigned> > m_vStats;    // +0x28 <v stat weight>
    Unk_ItemOptionStatPicker m_picker;          // +0x40
};
MS2_CHECK_SIZE(ItemOptionVariationData, 0x58);

// A random option row (itemoptionrandom.xml).
class ItemOptionRandom : public CPtred
{
public:
    ItemOptionRandom();                         // 0x1405d3bf0
    int FUN_1405d3c80();                        // "code"
    ItemOptionStatGroup FUN_1405d3ca0();        // "statGroup"
    int FUN_1405d3cc0();                        // "probVer"
    int FUN_1405d3ce0();                        // "levelGroupID"
    bool Load(Unk_140165cf0* pElem);   // xml read
    // Rolls the random options onto an option.
    void FUN_1405d3f70(MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom);
    bool FUN_1405d4270(MS2Ptr<Unk_ItemOptionPreset> spPreset, MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom);
    void FUN_1405d48d0(MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom,
                       const std::vector<std::pair<int, int> >& vLocked, unsigned nCount, Unk_ProbabilityLog* pLogs);
    bool FUN_1405d4bb0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom);    // rerolls until the result differs
    bool FUN_1405d55e0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom);
    int FUN_1405d5fe0(int nRank);               // the pick count of a rank
    bool FUN_1405d6020(MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom);   // adds one random option
    void FUN_1405d6560(MS2Ptr<CItemOption> spOption, int nRank, unsigned nTrials,
                       const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut);
    void FUN_1405d68f0(unsigned nItemId, int nRank, unsigned& nPick, std::vector<CStringW>* pOut);
    bool FUN_1405d74d0(int nStat);              // a row of the stat
    bool FUN_1405d7550(unsigned nSpecial);
    void FUN_1405d75d0(std::function<void(ItemOptionValueRandom*)> fnVisit);
    int FUN_1405d7680(int nStat);               // the statID of a stat's row (0 when none)
    int FUN_1405d7710(unsigned nSpecial);
    MS2Ptr<ItemOptionValueRandom> FUN_1405d77a0(int nStat);
    MS2Ptr<ItemOptionValueRandom> FUN_1405d7870(unsigned nSpecial);
    int FUN_1405d7940(std::vector<ItemOptionValueRandom*>& vOut, CItemOption* pSource);   // the rows the source holds
    bool FUN_1405d7bf0(std::vector<ItemOptionValueRandom*>& vOut, unsigned& nCount, Unk_Random* pRandom, BOOL bFixedCount,
                       MS2Ptr<ItemOptionRandomContext> spContext, const std::vector<std::pair<int, int> >& vLocked,
                       Unk_ProbabilityLog* pLogs);
    void FUN_1405d8880(MS2Ptr<Unk_ItemOptionPreset> spPreset, std::vector<ItemOptionValueRandom*>& vOut,
                       MS2Ptr<ItemOptionRandomContext> spContext);
    MS2Ptr<ItemOptionValueRandom> FUN_1405d8f30(MS2Ptr<ItemOptionRandomContext> spContext, Unk_Random* pRandom);
    double FUN_1405d9660(std::vector<unsigned>& vWeights, size_t nPick, size_t nIndex);  // P(entry nIndex in nPick picks)
private:
    int m_nCode;                                // +0x18 "code"
    int m_nProbVer;                             // +0x1c "probVer"
    ItemOptionStatGroup m_eStatGroup;           // +0x20 "statGroup"
    int m_nLevelGroupId;                        // +0x24 "levelGroupID"
    bool m_bRarePickOne;                        // +0x28 "isRarePickOne"
    int m_nPickCount;                           // +0x2c "pickCount"
    std::vector<MS2Ptr<ItemOptionValueRandom> > m_vValues;  // +0x30
};
MS2_CHECK_SIZE(ItemOptionRandom, 0x48);

// A reroll request (server side; a CPtred box): the option to reroll, the stats kept and the probability log.
class Unk_1405e74c0 : public CPtred
{
public:
    unsigned m_nItemId;                         // +0x18
    int m_nRank;                                // +0x1c
    int m_n20;
    int m_n24;
    MS2Ptr<CItemOption> m_spSource;             // +0x28
    MS2Ptr<CItemOption> m_spResult;             // +0x38
    int m_nMode;                                // +0x48 0: keep the source's stats, 1: roll
    int m_nRoll;                                // +0x4c 0: the result is a copy of the source
    std::vector<std::pair<int, int> > m_vLocked;    // +0x50 (special, stat) pairs kept from the source
    Unk_ProbabilityLog m_vLogs;                 // +0x68
};
MS2_CHECK_OFFSET(Unk_1405e74c0, m_spSource, 0x28);
MS2_CHECK_OFFSET(Unk_1405e74c0, m_nMode, 0x48);
MS2_CHECK_OFFSET(Unk_1405e74c0, m_vLogs, 0x68);

// An option preset (server side): the stats a generated option should prefer, by xml name.
class Unk_ItemOptionPreset : public CPtred
{
public:
    unsigned m_nItemId;                         // +0x18
    int m_nRank;                                // +0x1c
    int m_nType;                                // +0x20 the random context's type
    ATL::CAtlArray<CString> m_names;            // +0x28
};
MS2_CHECK_OFFSET(Unk_ItemOptionPreset, m_names, 0x28);
