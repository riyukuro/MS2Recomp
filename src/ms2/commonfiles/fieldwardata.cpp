// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The field war table: FieldWarData.xml (FieldWarData, the
// FieldWarGroup that picks one of a group's entries by weight, the FieldWarDataTable singleton) and the std::map /
// std::vector glue over its members.
// MS2-UNIT: commonfiles\fieldwardata.cpp
// MS2-RANGE: 0x1403820e0-0x14038b670 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?back@?$vector@IV?$allocator@I@std@@@std@@QEAAAEAIXZ 0x14038aa70 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldWarData@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldWarData@@@@@std@@PEAX@2@_K@Z 0x14038ad60 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldWarGroup@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VFieldWarGroup@@@@@std@@PEAX@2@_K@Z 0x14038ad90 ; order
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7FieldWarDataTable@@6B?$TSingleton@VFieldWarDataTable@@@@@ 0x142d2fdc0
// MS2-PIN: ??_7FieldWarDataTable@@6B?$CValidData@VFieldWarDataTable@@@@@ 0x142d2fdd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\fieldwardata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fieldwardata.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"

// The table file loader helpers.
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool FieldWarDataTable::s_bInit;
#endif

// @0x1403820e0
FieldWarData::FieldWarData()
    : m_fieldWarID(0), m_fieldWarGroupID(0), m_pickWeight(1), m_fieldID(0), m_rewardID(0), m_uiFieldID(0),
      m_isChangeMaxUser(0), m_playerCountFactorID(0)
{
}

// @0x140382170
FieldWarData::~FieldWarData()
{
}

// @0x1403821a0
void FieldWarData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "fieldWarID", m_fieldWarID);
    FUN_140873220(pElem, "fieldWarGroupID", m_fieldWarGroupID);
    FUN_140873220(pElem, "pickWeight", m_pickWeight);
    FUN_140873220(pElem, "fieldID", m_fieldID);
    FUN_140873220(pElem, "rewardID", m_rewardID);
    FUN_140873220(pElem, "uiFieldID", m_uiFieldID);
    FUN_1408730a0(pElem, "isChangeMaxUser", m_isChangeMaxUser);
    FUN_140873220(pElem, "playerCountFactorID", m_playerCountFactorID);
}

// @0x1403822b0
unsigned FieldWarData::GetFieldWarID() const
{
    return m_fieldWarID;
}

// @0x1403822d0
unsigned FieldWarData::GetFieldWarGroupID() const
{
    return m_fieldWarGroupID;
}

// @0x1403822f0
bool FieldWarData::IsValid() const
{
    return true;
}

// @0x140382300
FieldWarGroup::FieldWarGroup(unsigned nGroupID)
    : m_groupID(nGroupID)
{
}

// @0x140387c80
// MS2-FUNCTIONAL: member vector teardown order/shape differs slightly from the exe
FieldWarGroup::~FieldWarGroup()
{
}

// @0x140382370
void FieldWarGroup::AddData(MS2Ptr<FieldWarData> spData)
{
    unsigned nTotal = GetTotalWeight();
    nTotal += spData->m_pickWeight;
    m_weights.push_back(nTotal);
    m_datas.push_back(spData);
}

// @0x1403823f0
unsigned FieldWarGroup::GetTotalWeight()
{
    if (m_weights.empty())
        return 0;
    return m_weights.back();
}

// @0x140382440
MS2Ptr<FieldWarData> FieldWarGroup::PickData(Unk_Random& kRandom)
{
    if (m_datas.empty())
        return MS2Ptr<FieldWarData>(0);
    unsigned nTotal = GetTotalWeight();
    if (nTotal == 0)
        return MS2Ptr<FieldWarData>(0);
    unsigned nPick = kRandom.FUN_1407684c0() % nTotal;
    for (size_t i = 0; i < m_weights.size(); i++)
    {
        if (nPick < m_weights[i])
            return m_datas[i];
    }
    MS2_ASSERT_AT(0x5c, 0);
    return MS2Ptr<FieldWarData>(0);
}

// @0x1403825b0
FieldWarDataTable::FieldWarDataTable()
{
}

// @0x140382650
FieldWarDataTable::~FieldWarDataTable()
{
}

// @0x1403826e0
bool FieldWarDataTable::Load()
{
    Clear();
    CString strPath = FUN_14071a5b0("Table", "FieldWarData.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return false;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "fieldWar", "fieldWarID", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        MS2Ptr<FieldWarData> spData(new FieldWarData);
        spData->Load(pNode);
        if (!spData->IsValid())
            continue;
        AddData(spData);
    }
    SetInit(true);
    return true;
}

// @0x1403829c0
MS2Ptr<FieldWarGroup> FieldWarDataTable::GetOrAddGroup(unsigned nGroupID)
{
    std::map<unsigned, MS2Ptr<FieldWarGroup> >::iterator it = m_groups.find(nGroupID);
    if (it == m_groups.end())
    {
        MS2Ptr<FieldWarGroup> spGroup(new FieldWarGroup(nGroupID));
        m_groups[nGroupID] = spGroup;
        return spGroup;
    }
    return it->second;
}

// @0x140382b20
MS2Ptr<FieldWarData> FieldWarDataTable::GetDataByFieldID(unsigned nFieldID)
{
    std::map<unsigned, MS2Ptr<FieldWarData> >::iterator it = m_byFieldID.find(nFieldID);
    if (it == m_byFieldID.end())
        return MS2Ptr<FieldWarData>(0);
    return it->second;
}

// @0x140382be0
MS2Ptr<FieldWarData> FieldWarDataTable::GetData(unsigned nFieldWarID)
{
    std::map<unsigned, MS2Ptr<FieldWarData> >::iterator it = m_byID.find(nFieldWarID);
    if (it == m_byID.end())
        return MS2Ptr<FieldWarData>(0);
    return it->second;
}

// @0x140382ca0
void FieldWarDataTable::Clear()
{
    m_byID.clear();
}

// @0x140382cd0
void FieldWarDataTable::AddData(MS2Ptr<FieldWarData> spData)
{
    MS2Ptr<FieldWarGroup> spGroup = GetOrAddGroup(spData->GetFieldWarGroupID());
    if (spGroup == 0)
        return;
    spGroup->AddData(spData);
    m_byID[spData->GetFieldWarID()] = spData;
    m_byFieldID[spData->m_fieldID] = spData;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE_METHOD(0x1403821a0, FieldWarData, Load, 251, 0xE8EC07A8);
MS2_REPLACE_METHOD(0x1403822b0, FieldWarData, GetFieldWarID, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x1403822d0, FieldWarData, GetFieldWarGroupID, 14, 0x8AEE455B);
MS2_REPLACE_METHOD(0x1403822f0, FieldWarData, IsValid, 8, 0x71679366);
MS2_REPLACE_METHOD(0x1403823f0, FieldWarGroup, GetTotalWeight, 61, 0x48CE2ABA);
MS2_REPLACE_METHOD(0x140382ca0, FieldWarDataTable, Clear, 31, 0x0CD65179);

