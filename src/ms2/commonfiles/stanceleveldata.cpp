// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StanceTable: Table/stance.xml (combo stance skill rows).
// MS2-UNIT: ?\stanceleveldata.cpp
// MS2-RANGE: 0x1408290b0-0x14082e170 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0HV?$MS2Ptr@VStanceData@@@@$0A@@?$pair@$$CBIV?$MS2Ptr@VStanceData@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VStanceData@@@@@1@@Z 0x14082a1a0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VStanceData@@@@$0A@@?$pair@HV?$MS2Ptr@VStanceData@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VStanceData@@@@@Z 0x14082a150
// MS2-PIN: ??$?0AEBHAEAV?$MS2Ptr@VStanceData@@@@$0A@@?$pair@HV?$MS2Ptr@VStanceData@@@@@std@@QEAA@AEBHAEAV?$MS2Ptr@VStanceData@@@@@Z 0x14082a060
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VStanceData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VStanceData@@@@@0@AEAHAEAV?$MS2Ptr@VStanceData@@@@@Z 0x14082b820
// MS2-PIN: ??$make_pair@AEBHAEAV?$MS2Ptr@VStanceData@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VStanceData@@@@@0@AEBHAEAV?$MS2Ptr@VStanceData@@@@@Z 0x14082b7c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stanceleveldata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "stanceleveldata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax

// @0x1408290b0
StanceLevelData::StanceLevelData()
    : m_nLevel(0), m_nHitCount(0), m_nMultiplyDamageRate(0), m_nMaxAccDamageRate(0)
{
}

// @0x140829120
StanceLevelData::~StanceLevelData()
{
}

// @0x140829150
bool StanceLevelData::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "level", m_nLevel);
    FUN_140873220(pNode, "hitCount", m_nHitCount);
    FUN_140873220(pNode, "multiplyDamageRate", m_nMultiplyDamageRate);
    FUN_140873220(pNode, "maxAccDamageRate", m_nMaxAccDamageRate);
    return true;
}
MS2_REPLACE_METHOD(0x140829150, StanceLevelData, Load, 137, 0x1D384741);

// @0x1408291e0
unsigned StanceLevelData::DamageRate(int nBase)
{
    unsigned nRate = (unsigned)(m_nMultiplyDamageRate * nBase) / 1000;
    nRate = (std::min)(nRate, m_nMaxAccDamageRate);
    return nRate;
}
MS2_REPLACE_METHOD(0x1408291E0, StanceLevelData, DamageRate, 76, 0x15FC89A3);

// @0x140829240
StanceData::StanceData()
    : m_nStanceAdditionalID(0), m_nHitCountAdditionalID(0)
{
}

// @0x1408292d0
StanceData::~StanceData()
{
}

// @0x140829330
bool StanceData::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "stanceAdditionalID", m_nStanceAdditionalID);
    FUN_140873220(pNode, "hitCountAdditinoalID", m_nHitCountAdditionalID);
    XmlTokenList(pNode, "damageSkillIDs", m_damageSkillIDs);
    XmlTokenList(pNode, "finishStanceSkillIDs", m_finishStanceSkillIDs);
    for (Unk_140165cf0* pLevel = pNode->FUN_140165cf0("level"); pLevel != 0; pLevel = pLevel->FUN_140168650("level"))
    {
        MS2Ptr<StanceLevelData> spLevel(new StanceLevelData);
        if (spLevel->Load(pLevel) == 0)
            continue;
        m_levels.push_back(spLevel);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140829330, StanceData, Load, 362, 0x011A2E84);

// @0x1408294a0
bool StanceData::HasDamageSkill(unsigned nSkillId)
{
    if (m_damageSkillIDs.find(nSkillId) == m_damageSkillIDs.end())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1408294A0, StanceData, HasDamageSkill, 98, 0x709CF5DB);

// @0x140829510
int StanceData::StanceAdditionalID()
{
    return m_nStanceAdditionalID;
}
MS2_REPLACE_METHOD(0x140829510, StanceData, StanceAdditionalID, 14, 0x72E52537);

// @0x140829530
int StanceData::HitCountAdditionalID()
{
    return m_nHitCountAdditionalID;
}
MS2_REPLACE_METHOD(0x140829530, StanceData, HitCountAdditionalID, 14, 0x8AEE455B);

// @0x140829550
MS2Ptr<StanceLevelData> StanceData::LevelData(unsigned nHitCount)
{
    size_t nCount = m_levels.size();
    if (nCount == 0)
        return MS2Ptr<StanceLevelData>(nullptr);
    size_t nFound = 0;
    for (size_t i = 0; i < nCount; i++)
    {
        if (nHitCount < m_levels[i]->m_nHitCount)
            break;
        nFound = i;
    }
    return m_levels[nFound];
}
MS2_REPLACE_METHOD(0x140829550, StanceData, LevelData, 244, 0xD83FD928);

// @0x140829650
StanceTable::StanceTable()
{
}

// @0x1408296d0
StanceTable::~StanceTable()
{
}

// @0x140829730
// MS2-FUNCTIONAL: exe builds the two literal CString temps and the path before the TiXmlDocument with a different EH state layout (precedent continentregiontable); not reproduced
bool StanceTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "stance.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode != 0; pNode = pNode->FUN_140168650("v"))
    {
        DataPtr spData(new StanceData);
        if (spData->Load(pNode) == 0)
            continue;
        int nStance = spData->StanceAdditionalID();
        m_stances.insert(std::make_pair(nStance, spData));
        int nHitCount = spData->HitCountAdditionalID();
        m_hitCountStances.insert(std::make_pair(nHitCount, spData));
    }
    for (std::pair<const unsigned, DataPtr> entry : m_stances)
    {
        DataPtr spData = entry.second;
        for (const int nSkill : spData->m_finishStanceSkillIDs)
        {
            if (m_finishSkills.find(nSkill) != m_finishSkills.end())
                continue;
            m_finishSkills.insert(std::make_pair(nSkill, spData));
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140829730, StanceTable, Load, 1354, 0xB841DBC2);

// @0x140829c80
bool StanceTable::HasStance(unsigned nId)
{
    if (m_stances.find(nId) == m_stances.end())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140829C80, StanceTable, HasStance, 98, 0x9B3BA73F);

// @0x140829cf0
bool StanceTable::HasHitCountStance(unsigned nId)
{
    if (m_hitCountStances.find(nId) == m_hitCountStances.end())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140829CF0, StanceTable, HasHitCountStance, 98, 0xED58AD58);

// @0x140829d60
StanceTable::DataPtr StanceTable::Stance(unsigned nId)
{
    std::map<unsigned, DataPtr>::iterator it = m_stances.find(nId);
    if (it == m_stances.end())
        return DataPtr(nullptr);
    return it->second;
}
MS2_REPLACE_METHOD(0x140829D60, StanceTable, Stance, 174, 0xC4693A34);

// @0x140829e20
StanceTable::DataPtr StanceTable::HitCountStance(unsigned nId)
{
    std::map<unsigned, DataPtr>::iterator it = m_hitCountStances.find(nId);
    if (it == m_hitCountStances.end())
        return DataPtr(nullptr);
    return it->second;
}
MS2_REPLACE_METHOD(0x140829E20, StanceTable, HitCountStance, 174, 0x53ED1018);

// @0x140829ee0
bool StanceTable::HasFinishSkill(unsigned nSkillId)
{
    std::map<unsigned, DataPtr>::iterator it = m_finishSkills.find(nSkillId);
    if (it == m_finishSkills.end())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140829EE0, StanceTable, HasFinishSkill, 93, 0x75FA0CCA);

// @0x140829f50
StanceTable::DataPtr StanceTable::FinishSkillStance(unsigned nSkillId)
{
    std::map<unsigned, DataPtr>::iterator it = m_finishSkills.find(nSkillId);
    if (it == m_finishSkills.end())
        return DataPtr(nullptr);
    return it->second;
}
MS2_REPLACE_METHOD(0x140829F50, StanceTable, FinishSkillStance, 174, 0xA691E233);
