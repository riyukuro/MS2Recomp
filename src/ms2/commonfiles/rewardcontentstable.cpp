// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). RewardContentsTable: the reward contents tables
// (Table/RewardContent.xml, RewardContentItemTable.xml, RewardContentMesoTable.xml, RewardContentMesoStaticTable.xml),
// see rewardcontentstable.h.
// MS2-UNIT: commonfiles\rewardcontentstable.cpp
// MS2-RANGE: 0x1407703a0-0x14077dd10 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??1RewardContents@@UEAA@XZ 0x140778240
// MS2-PIN: ??1RewardContentsItem@@UEAA@XZ 0x140778260
// MS2-PIN: ??1RewardContentsItemGroup@@UEAA@XZ 0x140778280
// MS2-PIN: ??1RewardContentsItemTable@@UEAA@XZ 0x1407782b0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@_JV?$allocator@_J@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$vector@_JV?$allocator@_J@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x14077b400 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\rewardcontentstable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "rewardcontentstable.h"
#include "exptable.h"
#include "adventureleveltablehelper.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_RwLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_RwLoader* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const CString& strArg);
void FUN_1406a6d70(void* pLog, int a, int b, int c, const wchar_t* pszFormat, const int& nArg);
class Unk_RwLog { public: void FUN_1402804e0(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message); };
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pNode);                               // the row is for this client's region
int FUN_1408733a0(Unk_140165cf0* pElem, const char* pszName, double* pOut);
bool FUN_140768040(unsigned nChance);                                   // the percent roll
CExpTable* FUN_1404a1bb0();
CAdventureLevelTable* FUN_1401958a0();

// @0x1407790a0
bool Unk_DcLevelRange::FUN_1407790a0() const
{
    return (m_nLow == 0 && m_nHigh == 0) ? 1 : 0;
}

// @0x1407790e0
bool Unk_DcLevelRange::FUN_1407790e0(unsigned short nLevel) const
{
    if (m_nLow > nLevel)
        return false;
    if (m_nHigh < nLevel)
        return false;
    return true;
}

// @0x1407703a0
RewardContentsItem::RewardContentsItem()
    : m_nProb(0)
{
}

// @0x1407703f0
void RewardContentsItem::vfunc_2(void* pNode)
{
    ItemEntity::vfunc_2(pNode);
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "prob", reinterpret_cast<unsigned&>(m_nProb));
}

// @0x140770440
RewardContentsItemGroup::RewardContentsItemGroup()
{
}

// @0x1407704a0
bool RewardContentsItemGroup::Load(void* pNode)
{
    FUN_1408731a0(static_cast<Unk_140165cf0*>(pNode), "minLevel", m_levelRange.m_nLow);
    FUN_1408731a0(static_cast<Unk_140165cf0*>(pNode), "maxLevel", m_levelRange.m_nHigh);
    (void)((!!(m_levelRange.m_nLow <= m_levelRange.m_nHigh)) || (_wassert(L"m_levelRange.m_minValue <= m_levelRange.m_maxValue", _CRT_WIDE(MS2_THIS_FILE), 35), 0));
    for (Unk_140165cf0* pChild = static_cast<Unk_140165cf0*>(pNode)->FUN_140165cf0("item"); pChild != 0; pChild = pChild->FUN_140168650("item"))
    {
        MS2Ptr<RewardContentsItem> spItem(new RewardContentsItem);
        spItem->vfunc_2(pChild);
        if (spItem->m_itemId == 0 || spItem->m_count == 0)
            return false;
        m_items.push_back(spItem);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1407704A0, RewardContentsItemGroup, Load, 423, 0xED5D9CB7);

// @0x140770650
bool RewardContentsItemGroup::GetItems(unsigned short nLevel, std::vector<ItemEntity>& rItems)
{
    if (!m_levelRange.FUN_1407790a0() && !m_levelRange.FUN_1407790e0(nLevel))
        return false;
    for (unsigned i = 0; i < m_items.size(); i++)
    {
        if (m_items[i]->m_nProb != 0 && !FUN_140768040(m_items[i]->m_nProb))
            continue;
        rItems.push_back(ItemEntity(*m_items[i]));
    }
    return true;
}
MS2_REPLACE_METHOD(0x140770650, RewardContentsItemGroup, GetItems, 351, 0x18A68F55);

// @0x1407707c0
RewardContentsItemTable::RewardContentsItemTable()
    : m_nItemTableId(0)
{
}

// @0x140770810
// MS2-FUNCTIONAL: the loop latch/temporary order differs from the exe (frame 8 bytes larger)
bool RewardContentsItemTable::Load(void* pNode)
{
    if (!FUN_14028f710(static_cast<Unk_140165cf0*>(pNode)))
        return false;
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "itemTableID", m_nItemTableId);
    if (m_nItemTableId == 0)
        return false;
    for (Unk_140165cf0* pChild = static_cast<Unk_140165cf0*>(pNode)->FUN_140165cf0("v"); pChild != 0; pChild = pChild->FUN_140168650("v"))
    {
        MS2Ptr<RewardContentsItemGroup> spGroup(new RewardContentsItemGroup);
        if (!spGroup->Load(pChild))
            continue;
        m_groups.push_back(spGroup);
    }
    return !m_groups.empty();
}
MS2_REPLACE_METHOD(0x140770810, RewardContentsItemTable, Load, 345, 0x70BC9629);

// @0x140770970
void RewardContentsItemTable::GetItems(unsigned short nLevel, std::vector<ItemEntity>& rItems)
{
    for (unsigned i = 0; i < m_groups.size(); i++)
    {
        MS2Ptr<RewardContentsItemGroup> spGroup(m_groups[i]);
        if (spGroup == static_cast<RewardContentsItemGroup*>(0))
            continue;
        if (spGroup->GetItems(nLevel, rItems))
            return;
    }
}
MS2_REPLACE_METHOD(0x140770970, RewardContentsItemTable, GetItems, 213, 0x699DE83E);

// @0x140770a50
RewardContents::RewardContents()
    : m_nRewardId(0), m_nMesoTableId(0), m_dMesoFactor(1.0), m_nExpTableId(0), m_dExpFactor(1.0), m_nItemTableId(0),
      m_nAdventureExpTableId(0)
{
}

// @0x140770af0
bool RewardContents::Load(void* pNode)
{
    if (!FUN_14028f710(static_cast<Unk_140165cf0*>(pNode)))
        return false;
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "rewardID", m_nRewardId);
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "mesoTableID", m_nMesoTableId);
    FUN_1408733a0(static_cast<Unk_140165cf0*>(pNode), "mesoFactor", &m_dMesoFactor);
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "expTableID", m_nExpTableId);
    FUN_1408733a0(static_cast<Unk_140165cf0*>(pNode), "expFactor", &m_dExpFactor);
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "itemTableID", m_nItemTableId);
    FUN_140873220(static_cast<Unk_140165cf0*>(pNode), "adventureExpTableID", m_nAdventureExpTableId);
    if (m_nRewardId == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140770AF0, RewardContents, Load, 263, 0xFC7E7EB1);

// @0x140770c00
RewardContentsTable::Result::Result()
    : m_nMeso(0), m_nExp(0), m_nAdventureExp(0)
{
}

// @0x140770c50
RewardContentsTable::RewardContentsTable()
{
}

// @0x140770cd0
RewardContentsTable::~RewardContentsTable()
{
}

// @0x140770d30
bool RewardContentsTable::Load()
{
    if (!ReadMesoTable("RewardContentMesoTable.xml"))
        return false;
    if (!ReadMesoTable("RewardContentMesoStaticTable.xml"))
        return false;
    if (!ReadItemTable())
        return false;
    if (!ReadContents())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140770D30, RewardContentsTable, Load, 254, 0x2BC4FC6E);

// @0x140770e40
bool RewardContentsTable::GetReward(unsigned nRewardId, unsigned short nLevel, Result& rResult)
{
    std::map<unsigned, MS2Ptr<RewardContents> >::iterator it = m_rewards.find(nRewardId);
    if (it == m_rewards.end())
        return false;
    MS2Ptr<RewardContents> spReward(it->second);
    if (spReward == static_cast<RewardContents*>(0))
        return false;
    rResult.m_nExp = FUN_1404a1bb0()->GetScaledValue(nLevel, spReward->m_nExpTableId, spReward->m_dExpFactor);
    rResult.m_nAdventureExp = (__int64)FUN_1401958a0()->FindUnused2(spReward->m_nAdventureExpTableId);
    rResult.m_nMeso = GetMeso(spReward->m_nMesoTableId, spReward->m_dMesoFactor, nLevel);
    GetItems(spReward->m_nItemTableId, nLevel, rResult.m_items);
    return true;
}
MS2_REPLACE_METHOD(0x140770E40, RewardContentsTable, GetReward, 482, 0x1CFC9067);

// @0x140771030
// MS2-FUNCTIONAL: one extra 8-byte frame slot before the path string; the rest matches
bool RewardContentsTable::ReadMesoTable(const CStringA& strFile)
{
    CString strPath = FUN_14071a5b0("Table", strFile);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("table"); pNode != 0; pNode = pNode->FUN_140168650("table"))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "mesoTableID", nId);
        if (nId == 0)
            continue;
        std::vector<__int64>& values = m_mesoTables[nId];
        if (!values.empty())
        {
            FUN_1406a6d70(FUN_140166440(), 0, 0, 0x13, L"RewardContentsTable::ReadMesoTable DuplicateID:{0}", nId);
            continue;
        }
        for (Unk_140165cf0* pChild = pNode->FUN_140165cf0("v"); pChild != 0; pChild = pChild->FUN_140168650("v"))
        {
            if (!FUN_14028f710(pChild))
                continue;
            unsigned short nLevel = 0;
            __int64 nMeso = 0;
            FUN_1408731a0(pChild, "level", nLevel);
            FUN_1408732e0(pChild, "meso", nMeso);
            if (values.empty())
            {
                if (nLevel > 0)
                {
                    __int64 nZero = 0;
                    values.resize(100, nZero);
                }
                else
                {
                    __int64 nZero = 0;
                    values.resize(1, nZero);
                }
            }
            if (nLevel > 99 || nMeso == 0)
            {
                static_cast<Unk_RwLog*>(FUN_140166440())->FUN_1402804e0(0, 0, 0x13, L"Invalid RewardContentsTable::ReadMesoTable");
                return false;
            }
            values[nLevel] = nMeso;
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140771030, RewardContentsTable, ReadMesoTable, 912, 0x4A48AC18);

// @0x1407713d0
bool RewardContentsTable::ReadItemTable()
{
    CString strPath = FUN_14071a5b0("Table", "RewardContentItemTable.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("table"); pNode != 0; pNode = pNode->FUN_140168650("table"))
    {
        MS2Ptr<RewardContentsItemTable> spValue(new RewardContentsItemTable);
        if (!spValue->Load(pNode))
            continue;
        if (m_itemTables.find(spValue->m_nItemTableId) != m_itemTables.end())
            return false;
        m_itemTables.insert(std::make_pair(spValue->m_nItemTableId, spValue));
    }
    return true;
}
MS2_REPLACE_METHOD(0x1407713D0, RewardContentsTable, ReadItemTable, 849, 0x6DE84DCE);

// @0x140771730
bool RewardContentsTable::ReadContents()
{
    CString strPath = FUN_14071a5b0("Table", "RewardContent.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode != 0; pNode = pNode->FUN_140168650("v"))
    {
        MS2Ptr<RewardContents> spValue(new RewardContents);
        if (!spValue->Load(pNode))
            continue;
        m_rewards[spValue->m_nRewardId] = spValue;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140771730, RewardContentsTable, ReadContents, 632, 0xF3A8F4A9);

// @0x1407719b0
// MS2-FUNCTIONAL: locals/size compares differ slightly from the exe (the unused epsilon local's slot, size() inlining)
__int64 RewardContentsTable::GetMeso(unsigned nTableId, double dFactor, unsigned short nLevel)
{
    std::map<unsigned, std::vector<__int64> >::iterator it = m_mesoTables.find(nTableId);
    if (it == m_mesoTables.end())
        return 0;
    double dEpsilon = 0.00001;
    std::vector<__int64>& values = it->second;
    if (values.size() == 1)
        return static_cast<__int64>(static_cast<double>(values[0]) * dFactor + 0.00001);
    if (nLevel != 0)
    {
        size_t nIndex = nLevel;
        if (nIndex < values.size())
            return static_cast<__int64>(static_cast<double>(values[nLevel]) * dFactor + 0.00001);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1407719B0, RewardContentsTable, GetMeso, 277, 0x4A6C85FD);

// @0x140771ad0
void RewardContentsTable::GetItems(unsigned nTableId, unsigned short nLevel, std::vector<ItemEntity>& rItems)
{
    std::map<unsigned, MS2Ptr<RewardContentsItemTable> >::iterator it = m_itemTables.find(nTableId);
    if (it == m_itemTables.end())
        return;
    MS2Ptr<RewardContentsItemTable> spTable(it->second);
    if (spTable == static_cast<RewardContentsItemTable*>(0))
        return;
    spTable->GetItems(nLevel, rItems);
}
MS2_REPLACE_METHOD(0x140771AD0, RewardContentsTable, GetItems, 207, 0xB7EBF7D4);
