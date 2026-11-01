// itemoption.h - CItemOption, the option record of an item (CItemStatus +0x18; alloc 0x2f8). Recovered from the first
// TU of the commonfiles\itemoptiondata.cpp range (0x1405caed0-0x1405ce250). Names are by address.
#pragma once
#include <atlcoll.h>
#include <utility>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemenchantinfo.h"

class COutputStream;
class CInputStream;

// The special-stat options of a socket (the key is the special stat; ctor 0x1405cccb0 in itemoptiondata.cpp).
enum Unk_SocketSpecialStat { };
typedef ATL::CAtlMap<Unk_SocketSpecialStat, Unk_EnchantPtr<BaseOption> > Unk_SocketSpecialMap;
// The basic stat of an option group entry, as the first of the pair CItemOption::GetFirstStat returns.
enum Unk_StatType { };
// The display order of an option line (CItemOptionTable::FUN_1405f6ed0) -> its text.
typedef ATL::CRBMap<unsigned, CString> Unk_OptionTextMap;
// The special stat -> ability table iterated by HasSpecialAbility/CollectSpecialAbilityValues (the global is owned by specialability.cpp).
typedef ATL::CAtlMap<Unk_SocketSpecialStat, unsigned> Unk_SpecialAbilityMap;

class CItemOption : public CPtred
{
public:
    CItemOption(unsigned nItemId);              // 0x1405caed0
    MS2Ptr<CItemOption> Clone();        // 0x1405caf90 copy
    void ClearAll();                       // 0x1405cb110 clear
    void ClearGroup(int nGroup);             // 0x1405cb190 clear a group
    bool TrySetStatOption(int nGroup, int nStat, Unk_EnchantPtr<BaseOption> spOption);        // 0x1405cb200
    bool TrySetSpecialOption(int nGroup, unsigned nStat, Unk_EnchantPtr<BaseOption> spOption);   // 0x1405cb2a0
    unsigned GetItemId();                   // 0x1405cb340 the item id
    void FUN_1405cb360(int nValue);             // 0x1405cb360
    int FUN_1405cb380();                        // 0x1405cb380
    int SumStatValue(unsigned nType);          // 0x1405cb3a0 the summed value of a stat type
    int SumSpecialValue(unsigned nType);          // 0x1405cb440 the summed value of a special stat
    std::pair<Unk_StatType, int> GetFirstStat(int nGroup) const;      // 0x1405cb4e0 the first stat of a group
    std::pair<Unk_SocketSpecialStat, int> GetFirstSpecialStat(int nGroup) const;  // 0x1405cb620 the first special stat
    Unk_EnchantPtr<BaseOption> GetStatOption(int nGroup, int nStat);        // 0x1405cb760
    Unk_EnchantPtr<BaseOption> GetSpecialOption(int nGroup, unsigned nType);   // 0x1405cb800
    Unk_EnchantMap& GetStatMap(int nGroup);  // 0x1405cb8a0 the stat map of a group
    Unk_SocketSpecialMap& GetSpecialMap(int nGroup);    // 0x1405cb8d0 the special-stat map of a group
    void FUN_1405cb900(int nGroup, Unk_OptionTextMap& kOut);    // 0x1405cb900 the option texts of a group
    int GetGroupOptionCount(int nGroup);              // 0x1405cbbb0 the option count of a group
    BOOL HasAbilitySpecial(int nGroup) const;       // 0x1405cbc10
    int HasSpecialAbility();                        // 0x1405cbc90 has a special ability
    void CollectSpecialAbilityValues(ATL::CAtlMap<unsigned, unsigned short>& kOut);  // 0x1405cbd70 sums the special abilities
    void Serialize(COutputStream& kOut);    // 0x1405cbeb0 write
    void Deserialize(CInputStream& kIn);      // 0x1405cc190 read
    bool HasGroup4Options();                       // 0x1405cc410 group 4 is not empty
    bool CopyGroup2From(MS2Ptr<CItemOption> spSource);   // 0x1405cc480 copy group 2
    BOOL SetGroup(int nGroup, const Unk_EnchantMap& kStat, const Unk_SocketSpecialMap& kSpecial);   // 0x1405cc590
    bool FUN_1405cc640(int nGroup, CItemOption* pOther) const;  // 0x1405cc640 same group options
private:
    unsigned m_nItemId;                         // +0x18
    Unk_EnchantMap m_aStat[5];                  // +0x20
    Unk_SocketSpecialMap m_aSpecial[5];         // +0x188
    int m_n2f0;                                 // +0x2f0
};
MS2_CHECK_SIZE(CItemOption, 0x2f8);
