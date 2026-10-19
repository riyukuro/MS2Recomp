// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SetItemOptionPart: one part of a set item. See setitemoptionpart.h.
// MS2-UNIT: ?\setitemoptionpart.cpp
// MS2-RANGE: 0x1407bc4b0-0x1407c4980 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??0?$Unk_EnchantPtr@VBaseOption@@@@QEAA@_J@Z 0x1407bf260
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\setitemoptionpart.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/setitemoptionpart.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_140178670(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<int>& arr);
void FUN_140645110(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<unsigned short>& arr);
const CStringA& FUN_14082efb0(UnlimitedEnchantInfo::OptionKey nStat);       // the xml name of a stat
const CStringA& FUN_14081d380(Unk_SocketSpecialStat nStat);                 // the xml name of a special ability
void* FUN_140166440();
unsigned __int64 FUN_1401859c0(void* pLogger, int nLevel, int nCategory, const wchar_t* pszText);
extern const UnlimitedEnchantInfo::OptionKey DAT_1439f48d0[16];
extern const Unk_SocketSpecialStat DAT_1439f4910[4];

// @0x1407bc4b0
SetItemOptionPart::SetItemOptionPart() : m_nCount(0)
{
}

// @0x1407bc580
bool SetItemOptionPart::FUN_1407bc580(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "count", m_nCount);
    if (m_nCount == 0)
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13, L"\uac12\uc774 0 \uc785\ub2c8\ub2e4.PartCount is NULL");
        return false;
    }
    FUN_140178670(pElem, "additionalEffectID", m_effectIds);
    FUN_140645110(pElem, "additionalEffectLevel", m_effectLevels);
    if (m_effectIds.GetCount() != m_effectLevels.GetCount())
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13, L"\uac12\uc774 0 \uc785\ub2c8\ub2e4.additionalEffect Count Error!");
        return false;
    }
    FUN_1408733e0(pElem, "animationPrefix", m_animationPrefix);
    FUN_1408733e0(pElem, "setEffect", m_setEffect);
    FUN_1408733e0(pElem, "groundAttribute", m_groundAttribute);

    for (StatKey nStat : DAT_1439f48d0)
    {
        Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
        int nValue = 0;
        FUN_1408731e0(pElem, (const char*)FUN_14082efb0(nStat), nValue);
        spOption->FUN_140266e90(nValue);
        if (spOption->FUN_140266ce0())
            FUN_1407bca10(nStat, spOption);
    }
    const SpecialKey* pSpecials = DAT_1439f4910;
    for (unsigned i = 0; i < 4; i++)
    {
        SpecialKey nStat = pSpecials[(int)i];
        Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
        int nValue = 0;
        FUN_1408731e0(pElem, (const char*)FUN_14081d380(nStat), nValue);
        spOption->FUN_140266e90(nValue);
        if (spOption->FUN_140266ce0())
            FUN_1407bcac0(nStat, spOption);
    }
    return true;
}

// @0x1407bc9b0
unsigned SetItemOptionPart::FUN_1407bc9b0()
{
    return m_nCount;
}

// @0x1407bc9d0
ATL::CAtlArray<int>& SetItemOptionPart::FUN_1407bc9d0()
{
    return m_effectIds;
}

// @0x1407bc9f0
ATL::CAtlArray<unsigned short>& SetItemOptionPart::FUN_1407bc9f0()
{
    return m_effectLevels;
}

// @0x1407bca10
void SetItemOptionPart::FUN_1407bca10(StatKey nStat, Unk_EnchantPtr<BaseOption> spOption)
{
    if (!spOption->FUN_140266ce0())
        return;
    m_stats.insert(std::make_pair(nStat, spOption));
}

// @0x1407bcac0
void SetItemOptionPart::FUN_1407bcac0(SpecialKey nStat, Unk_EnchantPtr<BaseOption> spOption)
{
    if (!spOption->FUN_140266ce0())
        return;
    m_specials.insert(std::make_pair(nStat, spOption));
}

// @0x1407bcb70
Unk_EnchantPtr<BaseOption> SetItemOptionPart::FUN_1407bcb70(StatKey nStat) const
{
    StatMap::const_iterator it = m_stats.find(nStat);
    if (it == m_stats.end())
        return Unk_EnchantPtr<BaseOption>(0LL);
    return it->second;
}

// @0x1407bcc30
Unk_EnchantPtr<BaseOption> SetItemOptionPart::FUN_1407bcc30(SpecialKey nStat) const
{
    SpecialMap::const_iterator it = m_specials.find(nStat);
    if (it == m_specials.end())
        return Unk_EnchantPtr<BaseOption>(0LL);
    return it->second;
}

// @0x1407bccf0
void SetItemOptionPart::FUN_1407bccf0(std::function<void(const std::pair<StatKey, Unk_EnchantPtr<BaseOption> >&)> fn)
{
    for (std::pair<const StatKey, Unk_EnchantPtr<BaseOption> >& rValue : m_stats)
    {
        std::pair<StatKey, Unk_EnchantPtr<BaseOption> > entry(rValue);
        fn(entry);
    }
}

// @0x1407bcdb0
void SetItemOptionPart::FUN_1407bcdb0(std::function<void(const std::pair<SpecialKey, Unk_EnchantPtr<BaseOption> >&)> fn)
{
    for (std::pair<const SpecialKey, Unk_EnchantPtr<BaseOption> >& rValue : m_specials)
    {
        std::pair<SpecialKey, Unk_EnchantPtr<BaseOption> > entry(rValue);
        fn(entry);
    }
}

// @0x1407bce70
CStringA& SetItemOptionPart::FUN_1407bce70()
{
    return m_animationPrefix;
}

// @0x1407bce90
CStringA& SetItemOptionPart::FUN_1407bce90()
{
    return m_setEffect;
}

// @0x1407bceb0
CStringA& SetItemOptionPart::FUN_1407bceb0()
{
    return m_groundAttribute;
}
