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
#include "ms2/commonfiles/filesystem.h"
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0

// @0x140591210
MS2_EMIT_CRT_MEMMOVE_S();

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString GetXmlPath(const CString& strDir, const CString& strFile);        // Table/<file>
CString ToCString(const char* pszName, int nFlags);     // undecorated class name
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def
MS2Ptr<CItemData> FUN_14053f870(int nItemId);               // the item data of an id
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

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
        MS2Ptr<BaseOption> spOption = m_stats.GetValueAt(pos);
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
        MS2Ptr<BaseOption> spOption = m_stats.GetValueAt(pos);
        if (str.GetLength() != 0)
            str += ",";
        str += Unk_SocketFormat("{0}", spOption->GetRate());
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
    CString strPath = GetXmlPath("Table", "enchantLimitTable.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<TiXmlElement*> nodes;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "limit", "slot", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&nodes));
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        TiXmlElement* pNode = nodes[i];
        MS2Ptr<EnchantLimit> spLimit(new EnchantLimit);
        XmlGetAttr((class TiXmlElement*)(pNode), "minLv", reinterpret_cast<unsigned short&>(spLimit->m_nMinLv));
        XmlGetAttr((class TiXmlElement*)(pNode), "maxLv", reinterpret_cast<unsigned short&>(spLimit->m_nMaxLv));
        XmlGetAttr((class TiXmlElement*)(pNode), "maxGrade", reinterpret_cast<int&>(spLimit->m_nMaxGrade));
        int nSlot = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "slot", reinterpret_cast<int&>(nSlot));
        int nKey = nSlot;
        m_map.SetAt(nKey, spLimit);
    }
    SetInit(true);
    return 1;
}

// The item may start an enchant: the item level inside the band of its slot and the grade below the limit.
#define ITEM_DATA(p) reinterpret_cast<CItemData*>((p)->GetData())
#define ITEM_DATA_BYTE(p, off) (*(reinterpret_cast<const unsigned char*>((p)->GetData()) + (off)))

// @0x14058df90
int CItemEnchantLimitTable::CanEnchant(CItem* pItem)
{
    CheckInit();
    if (pItem == 0)
        return 0;
    if (pItem->GetData() == 0)
        return 0;
    if (ITEM_DATA(pItem)->GetType() != 1)
        return 0;
    if (pItem->FUN_140525c60() == 1)
        return 0;
    if (pItem->GetPlusLevel() > 0)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(ITEM_DATA(pItem)->GetEquipSubtype(), spLimit))
        return 0;
    if (pItem->GetRequiredLevel() < spLimit->m_nMinLv)
        return 0;

    if (pItem->GetRequiredLevel() > spLimit->m_nMaxLv)
        return 0;

    MS2Ptr<CItemEnchantInfo> spInfo(reinterpret_cast<CItemStatus*>(pItem->GetStatus())->GetEnchant());
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
    if (pItem->GetData() == 0)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(ITEM_DATA(pItem)->GetEquipSubtype(), spLimit))
        return 0;
    if (pItem->GetRequiredLevel() < spLimit->m_nMinLv)
        return 0;
    if (pItem->GetRequiredLevel() > spLimit->m_nMaxLv)
        return 0;
    if (ITEM_DATA_BYTE(pItem, 0x1a1) != 0)
        return 0;
    return 1;
}

// @0x14058e3a0
unsigned CItemEnchantLimitTable::IsMaxGrade(CItem* pItem)
{
    CheckInit();
    if (pItem == 0)
        return 0;
    if (pItem->GetData() == 0)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(ITEM_DATA(pItem)->GetEquipSubtype(), spLimit))
        return 0;
    return pItem->GetEnchantLevel() == spLimit->m_nMaxGrade;
}

// @0x14058e4a0
bool CItemEnchantLimitTable::HasLimit(CItemData* pData)
{
    return m_map.Lookup(pData->GetEquipSubtype()) != 0;
}

// @0x14058e500
int CItemEnchantLimitTable::CanEnchantToGrade(unsigned nItemId, int nGrade)
{
    CheckInit();
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return 0;
    MS2Ptr<EnchantLimit> spLimit(0);
    if (!m_map.Lookup(spData->GetEquipSubtype(), spLimit))
        return 0;
    CItemData* pLow = spData.operator->();
    if (pLow->limit.levelLimit < spLimit->m_nMinLv)
        return 0;
    CItemData* pHigh = spData.operator->();
    if (pHigh->limit.levelLimit > spLimit->m_nMaxLv)
        return 0;
    if (nGrade >= spLimit->m_nMaxGrade)
        return 0;
    return 1;
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
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(CItemEnchantLimitTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1405902a0
void CItemEnchantLimitTable::SetInit(bool b)
{
    s_bInit = b;
}
