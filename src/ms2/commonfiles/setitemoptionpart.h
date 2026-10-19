// setitemoptionpart.h - SetItemOptionPart (RTTI name), one part of a set item: the pieces needed for the set bonus
// (count, additional effects, two strings) and the stat / special-stat options (0xf8 bytes, base CPtred, vftable
// 0x142d8dc08, ctor 0x1407bc4b0). Layout after the v2525 snapshot; the two option maps are std::unordered_map.
#pragma once
#include <unordered_map>
#include <functional>
#include <atlcoll.h>
#include <afxstr.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/unlimitedenchantinfo.h"   // UnlimitedEnchantInfo::OptionKey, Unk_SocketSpecialStat, BaseOption

class SetItemOptionPart : public CPtred
{
public:
    typedef UnlimitedEnchantInfo::OptionKey StatKey;                // the stat type (16 stats)
    typedef Unk_SocketSpecialStat SpecialKey;                       // the special ability (4 abilities)
    typedef std::unordered_map<StatKey, Unk_EnchantPtr<BaseOption> > StatMap;
    typedef std::unordered_map<SpecialKey, Unk_EnchantPtr<BaseOption> > SpecialMap;

    SetItemOptionPart();                                            // 0x1407bc4b0
    bool FUN_1407bc580(Unk_140165cf0* pElem);                       // 0x1407bc580 load the part from its xml element
    unsigned FUN_1407bc9b0();                                       // 0x1407bc9b0 the part count
    ATL::CAtlArray<int>& FUN_1407bc9d0();                           // 0x1407bc9d0 the additional effect ids
    ATL::CAtlArray<unsigned short>& FUN_1407bc9f0();                // 0x1407bc9f0 the additional effect levels
    void FUN_1407bca10(StatKey nStat, Unk_EnchantPtr<BaseOption> spOption);         // 0x1407bca10
    void FUN_1407bcac0(SpecialKey nStat, Unk_EnchantPtr<BaseOption> spOption);      // 0x1407bcac0
    Unk_EnchantPtr<BaseOption> FUN_1407bcb70(StatKey nStat) const;                  // 0x1407bcb70
    Unk_EnchantPtr<BaseOption> FUN_1407bcc30(SpecialKey nStat) const;               // 0x1407bcc30
    void FUN_1407bccf0(std::function<void(const std::pair<StatKey, Unk_EnchantPtr<BaseOption> >&)> fn);       // 0x1407bccf0
    void FUN_1407bcdb0(std::function<void(const std::pair<SpecialKey, Unk_EnchantPtr<BaseOption> >&)> fn);    // 0x1407bcdb0
    CStringA& FUN_1407bce70();                                      // 0x1407bce70 animationPrefix
    CStringA& FUN_1407bce90();                                      // 0x1407bce90 setEffect
    CStringA& FUN_1407bceb0();                                      // 0x1407bceb0 groundAttribute
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_nCount;                                              // +0x18
    ATL::CAtlArray<int> m_effectIds;                                // +0x20
    ATL::CAtlArray<unsigned short> m_effectLevels;                  // +0x40
    CStringA m_animationPrefix;                                     // +0x60
    CStringA m_setEffect;                                           // +0x68
    CStringA m_groundAttribute;                                     // +0x70
    StatMap m_stats;                                                // +0x78
    SpecialMap m_specials;                                          // +0xb8
};
MS2_CHECK_SIZE(SetItemOptionPart, 0xf8);
MS2_CHECK_OFFSET(SetItemOptionPart, m_stats, 0x78);
MS2_CHECK_OFFSET(SetItemOptionPart, m_specials, 0xb8);
