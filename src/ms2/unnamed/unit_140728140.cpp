// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPetData / CPetDataTable: the pet table of
// Table/petProperty.xml (<pets code=... type=... slotNum=.../>), with the CAtlMap / std::vector glue of its members.
// MS2-UNIT: unit_140728140
// MS2-RANGE: 0x140728140-0x14072bdc0 .text$mn
// MS2-PIN: ??_7CPetData@@6B@ 0x142d82d60
// MS2-PIN: ??_7CPetDataTable@@6B?$TSingleton@VCPetDataTable@@@@@ 0x142d82d90
// MS2-PIN: ??_7CPetDataTable@@6B?$CValidData@VCPetDataTable@@@@@ 0x142d82da0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\petdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include <typeinfo>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
void FUN_1401e0850(CLogString* log, int level, int category, const wchar_t* format, const CString& first,
                   const unsigned& second);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& rOut);
int FUN_140873890(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1408730a0(Unk_140165cf0* pElem, const char* pszName, bool& rOut);
int FUN_1408731a0(Unk_140165cf0* pElem, const char* pszName, unsigned short* pOut);
int FUN_140873360(Unk_140165cf0* pElem, const char* pszName, float* pOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& rOut);
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);
void FUN_14015f050(const CStringA& str, ATL::CAtlArray<CStringA>* pOut, const char* pszSep);   // split
void FUN_1402929a0(const CStringW& str, std::vector<int>& rOut, const wchar_t* pszSep);          // split into ints
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
unsigned char FUN_1401d1320(CCacheData* pCache);    // file changed since load

// @0x140729360
static unsigned short FUN_140729360(const CStringW& str) { return (unsigned short)_wtoi(str); }

// @0x140729390
static void FUN_140729390(CStringW& str, std::vector<unsigned short>& rOut, const wchar_t* pszSep)
{
    int nPos = 0;
    CStringW strToken = str.Tokenize(pszSep, nPos);
    while (!strToken.IsEmpty())
    {
        rOut.push_back(FUN_140729360(strToken));
        strToken = str.Tokenize(pszSep, nPos);
    }
}

// @0x140729460
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
static int FUN_140729460(Unk_140165cf0* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xe7, FALSE);
        return 2;
    }
    int nValue = 0;
    int nResult = FUN_140873890(pElem, pszName, &nValue);
    if (nResult != 0)
        return nResult;
    *pnOut = nValue;
    return nResult;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\petdata.cpp"

// ---- CPetData ----

// @0x140728140
CPetData::CPetData()
    : m_nType(0), m_bEnablePetExtraction(false), m_bCollectPreview(true), m_nCollectGroupId(0), m_nTamingGroupId(0),
      m_passiveSkills(17, 0.75f, 0.25f, 2.25f, 10), m_fWarpDistance(1500.0f), m_fTraceDistance(300.0f),
      m_fBattleTraceDistance(600.0f), m_fNameTagOffsetY(0.0f), m_nSlotNum(0), m_nOptionLevel(0),
      m_fConstantOptionFactor(0.0f), m_nItemIds(0), m_nId(0)
{
}

// @0x1407282b0
CPetData::~CPetData() {}

// @0x140728320
// MS2-FUNCTIONAL: stack temporaries (tamingAiPresets default-string chain) laid out 8 bytes differently
bool CPetData::Load(Unk_140165cf0* pNode)
{
    if (!FUN_14028f710(pNode))
        return false;
    FUN_140873220(pNode, "code", m_nId);
    FUN_140729460(pNode, "type", &m_nType);
    FUN_140873220(pNode, "slotNum", m_nSlotNum);
    FUN_140873220(pNode, "collectGroupId", m_nCollectGroupId);
    FUN_1408730a0(pNode, "isCollectPreview", m_bCollectPreview);
    FUN_140873220(pNode, "tamingGroupID", m_nTamingGroupId);
    FUN_1408730a0(pNode, "enablePetExtraction", m_bEnablePetExtraction);
    FUN_140873220(pNode, "itemIDs", m_nItemIds);
    FUN_14015f050(FUN_14015f710(pNode, "tamingAiPresets", CString("")), &m_tamingAiPresets, ",");
    unsigned int nSkillId = 0;
    unsigned short nSkillLevel = 0;
    FUN_140873220(pNode, "passiveSkillId", nSkillId);
    FUN_1408731a0(pNode, "passiveSkillLevel", &nSkillLevel);
    m_passiveSkills.SetAt(nSkillId, nSkillLevel);
    FUN_140873360(pNode, "warpDistance", &m_fWarpDistance);
    FUN_140873360(pNode, "traceDistance", &m_fTraceDistance);
    FUN_140873360(pNode, "battleTraceDistance", &m_fBattleTraceDistance);
    FUN_140873360(pNode, "nameTagOffsetY", &m_fNameTagOffsetY);
    FUN_1408731a0(pNode, "optionLevel", &m_nOptionLevel);
    FUN_140873360(pNode, "constantOptionFactor", &m_fConstantOptionFactor);
    {
        CStringW strIds;
        CStringW strLevels;
        FUN_140873420(pNode, "additionalEffectID", strIds);
        FUN_140873420(pNode, "additionalEffectLevel", strLevels);
        std::vector<int> ids;
        std::vector<unsigned short> levels;
        FUN_1402929a0(strIds, ids, L",");
        FUN_140729390(strLevels, levels, L",");
        int nCount = (int)(std::min)(ids.size(), levels.size());
        for (int i = 0; i < nCount; ++i)
            m_additionalEffects.push_back(std::make_pair((unsigned int)ids[i], levels[i]));
    }
    return true;
}

// @0x1407287e0
int CPetData::GetItemId(int nKind)
{
    if (m_nItemIds == 0)
        return m_nId;
    return m_nItemIds;
}

// @0x140728820
unsigned int CPetData::GetId() { return m_nId; }

// ---- CPetDataTable ----

// @0x140728840
CPetDataTable::CPetDataTable() : m_pets(17, 0.75f, 0.25f, 2.25f, 10), m_petsByKfm(17, 0.75f, 0.25f, 2.25f, 10) {}

// @0x140728970
CPetDataTable::~CPetDataTable() {}

// @0x140728a30
bool CPetDataTable::Load()
{
    if (!LoadProperties())
        return false;
    if (!LoadCollectGroups())
        return false;
    return true;
}

// @0x140728a70
bool CPetDataTable::LoadProperties()
{
    CString strPath = FUN_14071a5b0("Table", "petProperty.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    Unk_CriticalSectionLock lock(m_lock, 1);
    FUN_1401d1160(CString(strPath));
    m_pets.RemoveAll();
    m_petsByKfm.RemoveAll();
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "pets", "code", &nodes);
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        PetPtr spPet(new CPetData);
        if (!spPet->Load(pNode))
        {
            unsigned int nId = spPet->GetId();
            FUN_1401e0850(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}][petID={1}] loading Failed!",
                          strPath, nId);
            continue;
        }
        m_pets.SetAt(spPet->GetId(), spPet);
        if (spPet->m_nType == 1 && spPet->m_nTamingGroupId != 0)
        {
            MS2Ptr<CNpcData> spNpc = FUN_1406cd330(spPet->GetId());
            if (spNpc.get() != 0)
            {
                if (Contains(spNpc->m_model.m_strKfm))
                {
                    FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다IsPetKFM failed. {0}]",
                                  spNpc->m_model.m_strKfm);
                    return false;
                }
                m_petsByKfm.SetAt(spNpc->m_model.m_strKfm, spPet);
            }
        }
    }
    return true;
}

// @0x140728fe0
bool CPetDataTable::LoadCollectGroups()
{
    if (!m_collect.Load())
        return false;
    for (POSITION pos = m_pets.GetStartPosition(); pos != NULL; m_pets.GetNext(pos))
    {
        unsigned int nPetId = m_pets.GetKeyAt(pos);
        PetPtr spPet = m_pets.GetValueAt(pos);
        if (spPet == 0)
            continue;
        m_collect.Add(nPetId, spPet->m_nCollectGroupId);
    }
    return true;
}

// @0x1407290f0
CPetDataTable::PetPtr CPetDataTable::Find(unsigned int nPetId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        LoadProperties();
    PetPtr spPet;
    m_pets.Lookup(nPetId, spPet);
    return spPet;
}

// @0x1407291c0
CPetDataTable::PetPtr CPetDataTable::Find(CString strKfm)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        LoadProperties();
    PetPtr spPet;
    m_petsByKfm.Lookup(strKfm, spPet);
    return spPet;
}

// @0x1407292a0
int CPetDataTable::Contains(CString strKfm)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        LoadProperties();
    return m_petsByKfm.Lookup(strKfm) != 0;
}
