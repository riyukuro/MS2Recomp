// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UnlimitedEnchantInfo: the unlimited (plus) enchantment of an
// item, the third record of CItemStatus. Two option maps (32-byte BaseOption rows) keyed by 4-byte stat types.
// MS2-UNIT: commonfiles\unlimitedenchantinfo.cpp
// MS2-RANGE: 0x1408bb9d0-0x1408c3140 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@1@XZ 0x1408c0260 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@1@XZ 0x1408c0280 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@1@XZ 0x1408c02a0 ; probe
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@1@XZ 0x1408c02c0 ; probe
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@PEAX@2@_K@Z 0x1408c27e0 ; probe
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@PEAX@2@_K@Z 0x1408c2810 ; probe
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@W4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@U?$less@W4Unk_SocketSpecialStat@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_SocketSpecialStat@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@std@@@std@@@2@AEBW4Unk_SocketSpecialStat@@@Z 0x1408c2d00 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@W4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@U?$less@W4OptionKey@UnlimitedEnchantInfo@@@std@@V?$allocator@U?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@5@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4OptionKey@UnlimitedEnchantInfo@@V?$Unk_EnchantPtr@VBaseOption@@@@@std@@@std@@@std@@@2@AEBW4OptionKey@UnlimitedEnchantInfo@@@Z 0x1408c2de0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\unlimitedenchantinfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/unlimitedenchantinfo.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1408bb9d0
UnlimitedEnchantInfo::UnlimitedEnchantInfo(int nItemId, int nRarity) : m_nItemId(nItemId), m_nRarity(nRarity)
{
    FUN_1408bbc00();
}

// @0x1408bba60
MS2Ptr<UnlimitedEnchantInfo> UnlimitedEnchantInfo::FUN_1408bba60()
{
    MS2Ptr<UnlimitedEnchantInfo> spCopy(new UnlimitedEnchantInfo(m_nItemId, m_nRarity));
    spCopy->m_nLevel = m_nLevel;
    spCopy->m_options.insert(m_options.begin(), m_options.end());
    spCopy->m_secondary.insert(m_secondary.begin(), m_secondary.end());
    return spCopy;
}

// @0x1408bbc00
void UnlimitedEnchantInfo::FUN_1408bbc00()
{
    m_nLevel = 0;
    m_options.clear();
    m_secondary.clear();
    m_bChanged = false;
}

// @0x1408bbc50
int UnlimitedEnchantInfo::GetLevel()
{
    return m_nLevel;
}

// @0x1408bbc70
int UnlimitedEnchantInfo::FUN_1408bbc70()
{
    FUN_1408bbcb0(m_nLevel + 1, true);
    return GetLevel();
}

// @0x1408bbcb0
void UnlimitedEnchantInfo::FUN_1408bbcb0(int nLevel, bool bChanged)
{
    if (nLevel < 0)
    {
        MS2_ASSERT_AT(45, FALSE);
        nLevel = 0;
    }
    m_nLevel = nLevel;
    FUN_1408bc3d0();
    SetChanged(bChanged);
}

// @0x1408bbd30
void UnlimitedEnchantInfo::FUN_1408bbd30(COutputStream& out)
{
    out.WriteInt32(m_nLevel);
    // (the exe walks the maps through const_iterators: FUN_1408bbd30 is a const method in the original)
    unsigned nOptions = static_cast<const OptionMap&>(m_options).size();
    out.WriteInt32(nOptions);
    OptionMap::const_iterator it = static_cast<const OptionMap&>(m_options).begin();
    OptionMap::const_iterator itEnd = static_cast<const OptionMap&>(m_options).end();
    for (; it != itEnd; ++it)
    {
        out.WriteInt16(static_cast<short>(it->first));
        it->second->FUN_140266d20(reinterpret_cast<Unk_EnchantWrite&>(out));
    }
    unsigned nSecondary = static_cast<const SecondaryMap&>(m_secondary).size();
    out.WriteInt32(nSecondary);
    SecondaryMap::const_iterator it2 = static_cast<const SecondaryMap&>(m_secondary).begin();
    SecondaryMap::const_iterator it2End = static_cast<const SecondaryMap&>(m_secondary).end();
    for (; it2 != it2End; ++it2)
    {
        out.WriteInt16(static_cast<short>(it2->first));
        it2->second->FUN_140266d20(reinterpret_cast<Unk_EnchantWrite&>(out));
    }
}

// @0x1408bbef0
void UnlimitedEnchantInfo::FUN_1408bbef0(CInputStream& in)
{
    m_nLevel = in.ReadInt32();
    m_options.clear();
    unsigned nCount = in.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        OptionKey key = static_cast<OptionKey>(static_cast<unsigned short>(in.ReadInt16()));
        Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
        spOption->FUN_140266d60(reinterpret_cast<Unk_EnchantRead&>(in));
        m_options.insert(std::pair<OptionKey, Unk_EnchantPtr<BaseOption> >(key, spOption));
    }
    m_secondary.clear();
    unsigned nCount2 = in.ReadInt32();
    for (unsigned i = 0; i < nCount2; i++)
    {
        Unk_SocketSpecialStat key = static_cast<Unk_SocketSpecialStat>(static_cast<unsigned short>(in.ReadInt16()));
        Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
        spOption->FUN_140266d60(reinterpret_cast<Unk_EnchantRead&>(in));
        m_secondary.insert(std::pair<Unk_SocketSpecialStat, Unk_EnchantPtr<BaseOption> >(key, spOption));
    }
}

// @0x1408bc1d0
void UnlimitedEnchantInfo::SetChanged(bool bChanged)
{
    m_bChanged = bChanged;
}

// @0x1408bc1f0
bool UnlimitedEnchantInfo::IsChanged()
{
    return m_bChanged;
}

// @0x1408bc210
Unk_EnchantPtr<BaseOption> UnlimitedEnchantInfo::FUN_1408bc210(unsigned nType)
{
    OptionMap::iterator it = m_options.find(reinterpret_cast<const OptionKey&>(nType));
    if (it == m_options.end())
        return Unk_EnchantPtr<BaseOption>(0);
    return it->second;
}

// @0x1408bc2d0
UnlimitedEnchantInfo::OptionMap& UnlimitedEnchantInfo::FUN_1408bc2d0()
{
    return m_options;
}

// @0x1408bc2f0
Unk_EnchantPtr<BaseOption> UnlimitedEnchantInfo::FUN_1408bc2f0(unsigned nType)
{
    SecondaryMap::iterator it = m_secondary.find(reinterpret_cast<const Unk_SocketSpecialStat&>(nType)); // the exe's parameter is the key itself
    if (it == m_secondary.end())
        return Unk_EnchantPtr<BaseOption>(0);
    return it->second;
}

// @0x1408bc3b0
UnlimitedEnchantInfo::SecondaryMap& UnlimitedEnchantInfo::FUN_1408bc3b0()
{
    return m_secondary;
}

// @0x1408bc3d0
void UnlimitedEnchantInfo::FUN_1408bc3d0()
{
}

// @0x1408c3020 (the obj's unreferenced copy of the CRT's static-inline memmove_s)
MS2_EMIT_CRT_MEMMOVE_S();
