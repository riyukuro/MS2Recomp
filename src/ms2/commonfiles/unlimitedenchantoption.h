// unlimitedenchantoption.h - UnlimitedEnchantOption / UnlimitedEnchantTable (RTTI names): the stat options granted by
// the unlimited (plus) enchantment per item slot and grade, read from Table/Server/UnlimitedEnchantOption.xml.
// Header name assumed. Layout after the v2525 snapshot; member names invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/unlimitedenchantinfo.h"   // OptionKey, Unk_SocketSpecialStat, BaseOption

class CItem;

// The stat options of one slot / grade. RTTI UnlimitedEnchantOption, 0x38 bytes, base CPtred, vftable 0x142da3010.
class UnlimitedEnchantOption : public CPtred
{
public:
    typedef UnlimitedEnchantInfo::OptionKey StatKey;
    typedef Unk_SocketSpecialStat SpecialKey;
    typedef std::map<StatKey, Unk_EnchantPtr<BaseOption> > StatMap;
    typedef std::map<SpecialKey, Unk_EnchantPtr<BaseOption> > SpecialMap;

    UnlimitedEnchantOption();                                       // 0x1408c3140
    void Merge(MS2Ptr<UnlimitedEnchantOption> spOther);             // 0x1408c31e0
    void MergePrimary(MS2Ptr<UnlimitedEnchantOption> spOther);      // 0x1408c3280
    void MergeSecondary(MS2Ptr<UnlimitedEnchantOption> spOther);    // 0x1408c3490

    StatMap m_stats;                                                // +0x18
    SpecialMap m_specials;                                          // +0x28
};
MS2_CHECK_SIZE(UnlimitedEnchantOption, 0x38);
MS2_CHECK_OFFSET(UnlimitedEnchantOption, m_stats, 0x18);
MS2_CHECK_OFFSET(UnlimitedEnchantOption, m_specials, 0x28);

class CItemData;

// The table. RTTI UnlimitedEnchantTable, 0x68 bytes: TSingleton +0, CValidData +8, slot -> grade -> option map +0x10 and the
// three cost tables. Created by CGameApp::InitInstance side (not recovered).
class UnlimitedEnchantTable : public TSingleton<UnlimitedEnchantTable>,
                              public CValidData<UnlimitedEnchantTable>
{
public:
    typedef std::map<int, MS2Ptr<UnlimitedEnchantOption> > GradeMap;

    UnlimitedEnchantTable();                                        // 0x1408c36a0
    virtual ~UnlimitedEnchantTable();                               // 0x1408c3750

    bool Load();                                                    // 0x1408c37f0
    MS2Ptr<UnlimitedEnchantOption> FindForItem(MS2Ptr<CItem> spItem);   // 0x1408c4530
    MS2Ptr<UnlimitedEnchantOption> Find(unsigned nItemId, int nGrade);  // 0x1408c4600
    void GetCosts(int nGrade, int nSlot, int& a, int& b, int& c, int& d, int& e);   // 0x1408c4810
    void InitializeCosts();                                         // 0x1408c4980

    static void SetValid(bool b);                                   // 0x1408ccbd0
    static bool s_bValid;                                           // DAT_143ab24e8

private:
    MS2_LAYOUT_FRIEND;
    std::map<int, GradeMap> m_options;                              // +0x10 slot -> grade
    std::vector<unsigned> m_cost1;                                  // +0x20
    std::vector<unsigned> m_cost2;                                  // +0x38
    std::vector<unsigned> m_cost3;                                  // +0x50
};
MS2_CHECK_SIZE(UnlimitedEnchantTable, 0x68);
MS2_CHECK_OFFSET(UnlimitedEnchantTable, m_options, 0x10);
MS2_CHECK_OFFSET(UnlimitedEnchantTable, m_cost3, 0x50);
