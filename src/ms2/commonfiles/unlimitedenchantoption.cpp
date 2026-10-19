// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UnlimitedEnchantOption / UnlimitedEnchantTable: the stat
// options of the unlimited enchantment per item slot and grade (Table/Server/UnlimitedEnchantOption.xml), and the
// template glue of their std::maps. The header-included static sort-name table is emitted here as well.
// MS2-UNIT: ?\unlimitedenchantoption.cpp
// MS2-RANGE: 0x1400be020-0x1400be110 .text$di
// MS2-RANGE: 0x1408c3140-0x1408d1c50 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: memcpy_s 0x1408d1ab0
// MS2-PIN: ??_7UnlimitedEnchantTable@@6B?$TSingleton@VUnlimitedEnchantTable@@@@@ 0x142da3040
// MS2-PIN: ??_7UnlimitedEnchantTable@@6B?$CValidData@VUnlimitedEnchantTable@@@@@ 0x142da3050
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\unlimitedenchantoption.cpp"
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>
#include <algorithm>
#include "ms2/commonfiles/unlimitedenchantoption.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);   // split into ints
CString FUN_1402bb1c0(const char* szFormat, const int& n);                  // StringFormat<int>
bool FUN_14028d470(float a, float b);                                       // approximately equal
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);
extern const int DAT_1439f4a10;                                             // the option slots per row (4)

// ---- dynamic initializers (.text$di) ----

// @0x1400be020
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400be0e0
static CLockCriticalSection s_lock;

// ---- .text$mn ----

#ifndef MS2_HOOK_DLL
bool UnlimitedEnchantTable::s_bValid;
#endif

// @0x1408c3140
UnlimitedEnchantOption::UnlimitedEnchantOption()
{
}

// @0x1408c31e0
void UnlimitedEnchantOption::Merge(MS2Ptr<UnlimitedEnchantOption> spOther)
{
    MergePrimary(spOther);
    MergeSecondary(spOther);
}

// @0x1408c3280
void UnlimitedEnchantOption::MergePrimary(MS2Ptr<UnlimitedEnchantOption> spOther)
{
    StatMap::iterator it = spOther->m_stats.begin();
    StatMap::iterator itEnd = spOther->m_stats.end();
    for (; it != itEnd; ++it)
    {
        StatKey nKey = it->first;
        if (m_stats.find(nKey) != m_stats.end())
        {
            m_stats[nKey]->FUN_140266dd0(it->second.get());
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
            spOption->FUN_140266da0(it->second.get());
            m_stats[nKey] = spOption;
        }
    }
}

// @0x1408c3490
void UnlimitedEnchantOption::MergeSecondary(MS2Ptr<UnlimitedEnchantOption> spOther)
{
    SpecialMap::iterator it = spOther->m_specials.begin();
    SpecialMap::iterator itEnd = spOther->m_specials.end();
    for (; it != itEnd; ++it)
    {
        SpecialKey nKey = it->first;
        if (m_specials.find(nKey) != m_specials.end())
        {
            m_specials[nKey]->FUN_140266dd0(it->second.get());
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
            spOption->FUN_140266da0(it->second.get());
            m_specials[nKey] = spOption;
        }
    }
}

// @0x1408c36a0
UnlimitedEnchantTable::UnlimitedEnchantTable()
{
}

// @0x1408c3750
UnlimitedEnchantTable::~UnlimitedEnchantTable()
{
}

// @0x1408c37f0
bool UnlimitedEnchantTable::Load()
{
    InitializeCosts();
    CString strPath = FUN_14071a5b0(CString("Table/Server"), CString("UnlimitedEnchantOption.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    typedef std::map<std::pair<int, int>, MS2Ptr<UnlimitedEnchantOption> > RangeMap;
    std::map<int, RangeMap> ranges;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("option"); pNode != 0; pNode = pNode->FUN_140168650("option"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nSlot = 0;
        CString strGrade;
        FUN_1408731e0(pNode, "slot", nSlot);
        FUN_1408733e0(pNode, "grade", strGrade);
        ATL::CAtlArray<int> grades;
        FUN_140177de0(strGrade, grades, "-");
        int nFirst = 0;
        int nLast = 0;
        if (grades.GetCount() == 1)
        {
            nFirst = grades[0];
            nLast = grades[0];
        }
        else if (grades.GetCount() == 2)
        {
            nFirst = grades[0];
            nLast = grades[1];
        }
        else
        {
            FUN_140166440()->FUN_14015eb90(1, 0x13, L"[<ms2> invalid unlimited enchanat grade {0}]", strGrade);
            continue;
        }
        std::pair<int, int> key(nFirst, nLast);
        if (ranges[nSlot].find(key) != ranges[nSlot].end())
        {
            FUN_140166440()->FUN_14015eb90(1, 0x13, L"\uC911\uBCF5\uB41C \uD0A4 \uAC12\uC774 \uC874\uC7AC \uD569\uB2C8\uB2E4.[<ms2> {0}]", strPath);
            continue;
        }
        MS2Ptr<UnlimitedEnchantOption> spInfo(new UnlimitedEnchantOption);
        for (int i = 1; i <= DAT_1439f4a10; i++)
        {
            UnlimitedEnchantInfo::OptionKey nOption = (UnlimitedEnchantInfo::OptionKey)-1;
            __int64 nValue = 0;
            float fRate = 0;
            XmlValue(pNode, FUN_1402bb1c0("option{0}", i), nOption);
            FUN_1408732e0(pNode, FUN_1402bb1c0("value{0}", i), nValue);
            FUN_140873360(pNode, FUN_1402bb1c0("rate{0}", i), fRate);
            if (nOption != -1 && (!FUN_14028d470(fRate, 0) || nValue != 0))
            {
                Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
                if (nValue != 0)
                    spOption->FUN_140266e90((int)nValue);
                else
                    spOption->FUN_140266e50(fRate);
                std::pair<UnlimitedEnchantInfo::OptionKey, Unk_EnchantPtr<BaseOption> > entry(nOption, spOption);
                spInfo->m_stats.insert(entry);
            }
            Unk_SocketSpecialStat nSpecial = (Unk_SocketSpecialStat)0;
            float fSpecialRate = 0;
            XmlValue(pNode, FUN_1402bb1c0("sa_option{0}", i), nSpecial);
            FUN_140873360(pNode, FUN_1402bb1c0("sa_rate{0}", i), fSpecialRate);
            if (nSpecial != 0 && !FUN_14028d470(fSpecialRate, 0))
            {
                Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
                spOption->FUN_140266e50(fSpecialRate);
                std::pair<Unk_SocketSpecialStat, Unk_EnchantPtr<BaseOption> > entry(nSpecial, spOption);
                spInfo->m_specials.insert(entry);
            }
        }
        ranges[nSlot].insert(std::make_pair(key, spInfo));
    }
    std::map<int, RangeMap>::iterator it = ranges.begin();
    for (; it != ranges.end(); ++it)
    {
        int nSlot = it->first;
        RangeMap::iterator itRange = it->second.begin();
        RangeMap::iterator itEnd = it->second.end();
        MS2Ptr<UnlimitedEnchantOption> spCumulative(new UnlimitedEnchantOption);
        for (; itRange != itEnd; ++itRange)
        {
            int nFirst = itRange->first.first;
            int nLast = itRange->first.second;
            MS2Ptr<UnlimitedEnchantOption> spInfo = itRange->second;
            for (int nGrade = nFirst; nGrade < nLast + 1; nGrade++)
            {
                spCumulative->Merge(spInfo);
                MS2Ptr<UnlimitedEnchantOption> spCopy(new UnlimitedEnchantOption);
                spCopy->Merge(spCumulative);
                m_options[nSlot].insert(std::make_pair(nGrade, spCopy));
            }
        }
    }
    ranges.clear();
    SetValid(true);
    return true;
}

// @0x1408c4530
MS2Ptr<UnlimitedEnchantOption> UnlimitedEnchantTable::FindForItem(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return MS2Ptr<UnlimitedEnchantOption>(0);
    return Find(spItem->FUN_1405276c0(), spItem->FUN_140527270());
}

// @0x1408c4600
MS2Ptr<UnlimitedEnchantOption> UnlimitedEnchantTable::Find(unsigned nItemId, int nGrade)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return MS2Ptr<UnlimitedEnchantOption>(0);
    int nSlot = spData->FUN_14053c620();
    if (m_options.find(nSlot) == m_options.end())
        return MS2Ptr<UnlimitedEnchantOption>(0);
    GradeMap::iterator it = m_options[nSlot].find(nGrade);
    if (it == m_options[nSlot].end())
        return MS2Ptr<UnlimitedEnchantOption>(0);
    return it->second;
}

// @0x1408c4810
void UnlimitedEnchantTable::GetCosts(int nGrade, int nSlot, int& a, int& b, int& c, int& d, int& e)
{
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 1;
    size_t nIndex = (std::min)(nGrade / 10, 9);
    a = m_cost1[nIndex];
    b = a * 65;
    d = m_cost2[nIndex];
    c = d * 16;
    e = m_cost3[nIndex];
    if (nSlot == 31 || nSlot == 34)
    {
        a /= 2;
        b /= 2;
        c /= 2;
        d /= 2;
        e /= 2;
    }
}

// @0x1408c4980
void UnlimitedEnchantTable::InitializeCosts()
{
    m_cost1.clear();
    m_cost2.clear();
    m_cost3.clear();
    m_cost1 = {0x36, 0x4a, 0x5e, 0x9e, 0x102, 0x166, 0x259, 0x3c1, 0x529, 0x5cb};
    m_cost2 = {4, 8, 12, 16, 20, 24, 28, 32, 36, 40};
    m_cost3 = {0x493, 0x79f, 0xaab, 0x1066, 0x1854, 0x2042, 0x3ec5, 0x6fc1, 0xa0c5, 0xb71e};
}

// @0x1408ccbd0
void UnlimitedEnchantTable::SetValid(bool b)
{
    s_bValid = b;
}

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// @0x1408d1bd0
ItemFunctionArgs::ItemFunctionArgs()
    : values(17, 0.75f, 0.25f, 2.25f, 10)
{
}
