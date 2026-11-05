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
#include "ms2/commonfiles/filesystem.h"
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_1401b4ec0 { public: Unk_1401b4ec0(CLockCriticalSection&, int); ~Unk_1401b4ec0(); private: void* m_p; };  // C3: the scoped lock (0x1401b4ec0 / 0x1401b5120, matched in commonfiles/banktable.cpp)

// return types of the getters this unit calls
class CFileSystem;

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 : public CFileSystem { };
CFileSystem* GetFileSystem();
CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_14015eb90
template <class T1, class T2> void FUN_1401e0850(CLogString* log, int level, int category, const wchar_t* format, const T1& first,
                   const T2& second);
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int FUN_140873420(TiXmlElement* pElem, const char* pszName, CStringW& rOut);
CString FUN_14015f710(TiXmlElement* pElem, const char* pszName, CString strDefault);
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
void FUN_1402929a0(const CStringW& str, std::vector<int>& rOut, const wchar_t* pszSep);          // split into ints (the definer's signature, commonutil.cpp)
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
unsigned char FUN_1401d1320(CCacheData* pCache);    // file changed since load

// @0x140729360
unsigned short FUN_140729360(const CStringW& str) { return (unsigned short)_wtoi(str); }

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
static int FUN_140729460(TiXmlElement* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xe7, FALSE);
        return 2;
    }
    int nValue = 0;
    int nResult = XmlQuery((class TiXmlElement*)(pElem), pszName, *(int*)(&nValue));
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
bool CPetData::Load(TiXmlElement* pNode)
{
    if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
        return false;
    XmlGetAttr((class TiXmlElement*)(pNode), "code", m_nId);
    FUN_140729460(pNode, "type", &m_nType);
    XmlGetAttr((class TiXmlElement*)(pNode), "slotNum", m_nSlotNum);
    XmlGetAttr((class TiXmlElement*)(pNode), "collectGroupId", m_nCollectGroupId);
    XmlGetAttr((class TiXmlElement*)(pNode), "isCollectPreview", m_bCollectPreview);
    XmlGetAttr((class TiXmlElement*)(pNode), "tamingGroupID", m_nTamingGroupId);
    XmlGetAttr((class TiXmlElement*)(pNode), "enablePetExtraction", m_bEnablePetExtraction);
    XmlGetAttr((class TiXmlElement*)(pNode), "itemIDs", m_nItemIds);
    Unk_SplitA(const_cast<CStringA&>(static_cast<const CStringA&>(Unk_ReadString((class Unk_XmlNode*)(pNode), "tamingAiPresets", CString("")))), (ATL::CAtlArray<CStringA>*)(&m_tamingAiPresets), ",");
    unsigned int nSkillId = 0;
    unsigned short nSkillLevel = 0;
    XmlGetAttr((class TiXmlElement*)(pNode), "passiveSkillId", nSkillId);
    XmlGetAttr((class TiXmlElement*)(pNode), "passiveSkillLevel", *(unsigned short*)(&nSkillLevel));
    m_passiveSkills.SetAt(nSkillId, nSkillLevel);
    XmlGetAttr((class TiXmlElement*)(pNode), "warpDistance", *(float*)(&m_fWarpDistance));
    XmlGetAttr((class TiXmlElement*)(pNode), "traceDistance", *(float*)(&m_fTraceDistance));
    XmlGetAttr((class TiXmlElement*)(pNode), "battleTraceDistance", *(float*)(&m_fBattleTraceDistance));
    XmlGetAttr((class TiXmlElement*)(pNode), "nameTagOffsetY", *(float*)(&m_fNameTagOffsetY));
    XmlGetAttr((class TiXmlElement*)(pNode), "optionLevel", *(unsigned short*)(&m_nOptionLevel));
    XmlGetAttr((class TiXmlElement*)(pNode), "constantOptionFactor", *(float*)(&m_fConstantOptionFactor));
    {
        CStringW strIds;
        CStringW strLevels;
        XmlGetAttr((class TiXmlElement*)(pNode), "additionalEffectID", strIds);
        XmlGetAttr((class TiXmlElement*)(pNode), "additionalEffectLevel", strLevels);
        std::vector<unsigned int> ids;
        std::vector<unsigned short> levels;
        FUN_1402929a0(strIds, reinterpret_cast<std::vector<int>&>(ids), L",");
        FUN_140729390(strLevels, levels, L",");
        int nCount = (int)(std::min)(ids.size(), levels.size());
        for (int i = 0; i < nCount; ++i)
        {
            std::pair<unsigned int, unsigned short> kEffect(ids[i], levels[i]);
            m_additionalEffects.push_back(kEffect);
        }
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
    if (reinterpret_cast<Unk_140166420*>(GetFileSystem())->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    Unk_1401b4ec0 lock(m_lock, 1);
    FUN_1401d1160(CString(strPath));
    m_pets.RemoveAll();
    m_petsByKfm.RemoveAll();
    std::vector<TiXmlElement*> nodes;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "pets", "code", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&nodes));
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        TiXmlElement* pNode = nodes[i];
        if (pNode == 0)
            continue;
        PetPtr spPet(new CPetData);
        if (!spPet->Load(pNode))
        {
            unsigned int nId = spPet->GetId();
            FUN_1401e0850<CString, unsigned>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}][petID={1}] loading Failed!",
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
                    Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다IsPetKFM failed. {0}]",
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
    Unk_1401b4ec0 lock(m_lock, 1);
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        LoadProperties();
    PetPtr spPet;
    m_pets.Lookup(nPetId, spPet);
    return spPet;
}

// @0x1407291c0
CPetDataTable::PetPtr CPetDataTable::Find(CString strKfm)
{
    Unk_1401b4ec0 lock(m_lock, 1);
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        LoadProperties();
    PetPtr spPet;
    m_petsByKfm.Lookup(strKfm, spPet);
    return spPet;
}

// @0x1407292a0
int CPetDataTable::Contains(CString strKfm)
{
    Unk_1401b4ec0 lock(m_lock, 1);
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)) != 0)
        LoadProperties();
    return m_petsByKfm.Lookup(strKfm) != 0;
}
