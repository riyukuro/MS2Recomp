// unlimitedenchantinfo.h - UnlimitedEnchantInfo (RTTI name), the third record of CItemStatus (+0x38): the unlimited
// (plus) enchantment of an item. 0x48 bytes, base CPtred, ctor 0x1408bb9d0 (its unit is not recovered); only the
// members the CItemStatus unit calls are declared. Member names are by address.
#pragma once
#include <map>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/itemoption.h"      // Unk_SocketSpecialStat
class COutputStream;
class CInputStream;
class UnlimitedEnchantInfo : public CPtred
{
public:
    // The stat options (key: the stat type) and the special-stat options (key: the special stat; std::less at 0x1401850d0).
    enum OptionKey { };                                             // its std::less is the unit's own COMDAT (0x1408c07c0)
    typedef std::map<OptionKey, Unk_EnchantPtr<BaseOption> > OptionMap;
    typedef std::map<Unk_SocketSpecialStat, Unk_EnchantPtr<BaseOption> > SecondaryMap;

    UnlimitedEnchantInfo(int nItemId, int nRarity);                 // 0x1408bb9d0
    ~UnlimitedEnchantInfo() = default;                              // 0x1408c0020 (implicit; defined where the vftable is)
    MS2Ptr<UnlimitedEnchantInfo> FUN_1408bba60();                   // 0x1408bba60 copy
    void FUN_1408bbc00();                                           // 0x1408bbc00 reset
    int FUN_1408bbc50();                                            // 0x1408bbc50 the level
    int FUN_1408bbc70();                                            // 0x1408bbc70 level up
    void FUN_1408bbcb0(int nLevel, bool bChanged);                  // 0x1408bbcb0 set the level
    void FUN_1408bbd30(COutputStream& out);                         // 0x1408bbd30 write
    void FUN_1408bbef0(CInputStream& in);                           // 0x1408bbef0 read
    void FUN_1408bc1d0(bool bChanged);                              // 0x1408bc1d0
    bool FUN_1408bc1f0();                                           // 0x1408bc1f0
    Unk_EnchantPtr<BaseOption> FUN_1408bc210(unsigned nType);       // 0x1408bc210 the option of a stat type
    OptionMap& FUN_1408bc2d0();                                     // 0x1408bc2d0
    Unk_EnchantPtr<BaseOption> FUN_1408bc2f0(unsigned nType);       // 0x1408bc2f0
    SecondaryMap& FUN_1408bc3b0();                                  // 0x1408bc3b0
    void FUN_1408bc3d0();                                           // 0x1408bc3d0 (empty)
private:
    MS2_LAYOUT_FRIEND;
    bool m_bChanged;                                                // +0x18
    int m_nItemId;                                                  // +0x1c
    int m_nRarity;                                                  // +0x20
    int m_nLevel;                                                   // +0x24
    OptionMap m_options;                                            // +0x28
    SecondaryMap m_secondary;                                       // +0x38
};
MS2_CHECK_SIZE(UnlimitedEnchantInfo, 0x48);
MS2_CHECK_OFFSET(UnlimitedEnchantInfo, m_options, 0x28);
MS2_CHECK_OFFSET(UnlimitedEnchantInfo, m_secondary, 0x38);
