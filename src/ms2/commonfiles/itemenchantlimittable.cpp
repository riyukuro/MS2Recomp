// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemEnchantLimitTable: the enchant limits per item slot
// (Table/enchantLimitTable.xml) held in an ATL::CAtlMap<int, MS2Ptr<EnchantLimit>>, and the joiners of the option stats.
// MS2-UNIT: ?\itemenchantlimittable.cpp
// MS2-RANGE: 0x14058d770-0x140591330 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x14058f3e0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VEnchantLimit@CItemEnchantLimitTable@@@@UKeyTraits@CItemEnchantLimitTable@@V?$CElementTraits@V?$MS2Ptr@VEnchantLimit@CItemEnchantLimitTable@@@@@ATL@@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x14058f650 ; unique
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x14058f740 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z 0x14058eb30
// MS2-PIN: ?set_string@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@QEAAXV?$BasicStringRef@D@3@@Z 0x140590ee0
// MS2-PIN: ??1EnchantLimit@CItemEnchantLimitTable@@UEAA@XZ 0x14058f060
// MS2-PIN: ??_7CItemEnchantLimitTable@@6B?$TSingleton@VCItemEnchantLimitTable@@@@@ 0x142d603d0
// MS2-PIN: ??_7CItemEnchantLimitTable@@6B?$CValidData@VCItemEnchantLimitTable@@@@@ 0x142d603e0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemenchantlimittable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemenchantlimittable.h"
#include "itemoption.h"
#include "itemenchantinfo.h"
#include "item.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <vector>
#include <sstream>
#include "hook/ms2hook.h"

// @0x140591210
MS2_EMIT_CRT_MEMMOVE_S();

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);          // the item data of an id

// The unit's init flag and singleton are exe globals (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
CItemEnchantLimitTable* TSingleton<CItemEnchantLimitTable>::s_instance;
bool CItemEnchantLimitTable::s_bInit;
#endif

// ---- the option stat joiners ----

// fmt's ostream formatting of a custom argument with the MS2 enum shortcut in front (see additionalactionadditional.cpp):
// enums are formatted as int, so the stream path is dead code that still instantiates basic_ostringstream<char>.
// @0x14058e8a0
template <> inline void fmt::format_arg(BasicFormatter<char>& f, const char*& format_str, const Unk_StatType& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_StatType>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<char> os;
        os << value;
        std::basic_string<char> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<char> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

// An option record with its stat map at +0x20 (the joiners are not called from the client; the owner class is unknown).
class Unk_EnchantStatSet : public CPtred
{
public:
    CString FUN_14058d770();                // the stat ids, comma separated
    CString FUN_14058d890();                // the stat values, comma separated
    CString FUN_14058d9f0();                // the stat rates, comma separated
    unsigned m_nUnk18;
    Unk_EnchantMap m_stats;
};
MS2_CHECK_OFFSET(Unk_EnchantStatSet, m_stats, 0x20);

// @0x14058d770
CString Unk_EnchantStatSet::FUN_14058d770()
{
    CString str;
    for (POSITION pos = m_stats.GetStartPosition(); pos != 0; m_stats.GetNext(pos))
    {
        if (str.GetLength() != 0)
            str += ",";
        str += Unk_SocketFormat("{0}", reinterpret_cast<const Unk_StatType&>(m_stats.GetKeyAt(pos)));
    }
    return str;
}

// @0x14058d890
CString Unk_EnchantStatSet::FUN_14058d890()
{
    CString str;
    for (POSITION pos = m_stats.GetStartPosition(); pos != 0; m_stats.GetNext(pos))
    {
        Unk_EnchantPtr<BaseOption> spOption = m_stats.GetValueAt(pos);
        if (str.GetLength() != 0)
            str += ",";
        str += Unk_SocketFormat("{0}", spOption->GetValue());
    }
    return str;
}

// @0x14058d9f0
CString Unk_EnchantStatSet::FUN_14058d9f0()
{
    CString str;
    for (POSITION pos = m_stats.GetStartPosition(); pos != 0; m_stats.GetNext(pos))
    {
        Unk_EnchantPtr<BaseOption> spOption = m_stats.GetValueAt(pos);
        if (str.GetLength() != 0)
            str += ",";
        str += Unk_SocketFormat("{0}", spOption->FUN_140266e10());
    }
    return str;
}

// ---- CItemEnchantLimitTable ----

// @0x14058db50
CItemEnchantLimitTable::CItemEnchantLimitTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14058dbf0
CItemEnchantLimitTable::~CItemEnchantLimitTable()
{
}

// @0x14058dc50
int CItemEnchantLimitTable::Load()
{
    CString strFile("enchantLimitTable.xml");
    CString strDir("Table");
    CString strPath = FUN_14071a5b0(strDir, strFile);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "limit", "slot", &nodes);
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        Unk_140165cf0* pNode = nodes[i];
        MS2Ptr<EnchantLimit> spLimit(new EnchantLimit);
        FUN_1408731a0(pNode, "minLv", spLimit->m_nMinLv);
        FUN_1408731a0(pNode, "maxLv", spLimit->m_nMaxLv);
        FUN_1408731e0(pNode, "maxGrade", spLimit->m_nMaxGrade);
        int nSlot = 0;
        FUN_1408731e0(pNode, "slot", nSlot);
        m_map.SetAt(nSlot, spLimit);
    }
    SetInit(true);
    return 1;
}

// The item may start an enchant: the item level inside the band of its slot and the grade below the limit.
#define ITEM_DATA(p) reinterpret_cast<CItemData*>((p)->FUN_140527840())
#define ITEM_DATA_BYTE(p, off) (*(reinterpret_cast<const unsigned char*>((p)->FUN_140527840()) + (off)))

// @0x14058df90
int CItemEnchantLimitTable::FUN_14058df90(CItem* pItem)
{
    CheckInit();
    if (pItem == 0)
        return 0;
    if (pItem->FUN_140527840() == 0)
        return 0;
    if (ITEM_DATA(pItem)->FUN_14053c5c0() != 1)
        return 0;
    if (pItem->FUN_140525c60() == 1)
        return 0;
    if (pItem->FUN_140527270() > 0)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(ITEM_DATA(pItem)->FUN_14053c620(), spLimit))
        return 0;
    if (pItem->FUN_140527710() < spLimit->m_nMinLv)
        return 0;

    if (pItem->FUN_140527710() > spLimit->m_nMaxLv)
        return 0;

    Unk_EnchantPtr<CItemEnchantInfo> spInfo(reinterpret_cast<CItemStatus*>(pItem->FUN_1405278a0())->GetEnchant());
    if (!spInfo)
        return 0;
    if (spInfo->GetLevel() >= spLimit->m_nMaxGrade)
        return 0;
    if (ITEM_DATA_BYTE(pItem, 0x1a1) != 0)
        return 0;
    return 1;
}

// @0x14058e230
int CItemEnchantLimitTable::FUN_14058e230(CItem* pItem)
{
    CheckInit();
    if (pItem == 0)
        return 0;
    if (pItem->FUN_140527840() == 0)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(ITEM_DATA(pItem)->FUN_14053c620(), spLimit))
        return 0;
    unsigned nLevel = pItem->FUN_140527710();
    if (nLevel < spLimit->m_nMinLv)
        return 0;
    unsigned nLevelMax = pItem->FUN_140527710();
    if (spLimit->m_nMaxLv < nLevelMax)
        return 0;
    return ITEM_DATA_BYTE(pItem, 0x1a1) == 0;
}

// @0x14058e3a0
unsigned CItemEnchantLimitTable::FUN_14058e3a0(CItem* pItem)
{
    CheckInit();
    if (pItem == 0)
        return 0;
    if (pItem->FUN_140527840() == 0)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(ITEM_DATA(pItem)->FUN_14053c620(), spLimit))
        return 0;
    return pItem->FUN_140526fc0() == spLimit->m_nMaxGrade;
}

// @0x14058e4a0
bool CItemEnchantLimitTable::FUN_14058e4a0(CItemData* pData)
{
    return m_map.Lookup(pData->FUN_14053c620()) != 0;
}

// @0x14058e500
int CItemEnchantLimitTable::FUN_14058e500(unsigned nItemId, int nGrade)
{
    CheckInit();
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(spData->FUN_14053c620(), spLimit))
        return 0;
    CItemData* pLow = spData.operator->();
    if (pLow->limit.levelLimit < spLimit->m_nMinLv)
        return 0;
    CItemData* pHigh = spData.operator->();
    if (spLimit->m_nMaxLv < pHigh->limit.levelLimit)
        return 0;
    return nGrade < spLimit->m_nMaxGrade;
}

// ---- EnchantLimit ----

// @0x14058ee60
CItemEnchantLimitTable::EnchantLimit::EnchantLimit()
    : m_nMinLv(0), m_nMaxLv(0), m_nMaxGrade(0)
{
}

// @0x14058f330
void CItemEnchantLimitTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemEnchantLimitTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1405902a0
void CItemEnchantLimitTable::SetInit(bool b)
{
    s_bInit = b;
}
