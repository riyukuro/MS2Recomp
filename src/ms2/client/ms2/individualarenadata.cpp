// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). IndividualArenaData / CIndividualArenaDataTable:
// Table/IndividualArena.xml.
// MS2-UNIT: ?\individualarenadata.cpp
// MS2-RANGE: 0x14051a170-0x14051c920 .text$mn
// MS2-PIN: ??_7CIndividualArenaDataTable@@6B?$TSingleton@VCIndividualArenaDataTable@@@@@ 0x142d55bc8
// MS2-PIN: ??_7CIndividualArenaDataTable@@6B?$CValidData@VCIndividualArenaDataTable@@@@@ 0x142d55bd8
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "individualarenadata.h"
#include "ms2/placeholder/stringxmlproc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
#include <typeinfo>

// Unrecovered helpers (same ones continentregiontable.cpp uses).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& rOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CString& rOut);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);

void* FUN_140164930(void*, unsigned __int64);                               // element address
int FUN_140768010(int nRange, int nBase);                                   // random number in [nBase, nBase + nRange)

// An array of strings that can hand out a random element (the weakest-typed caller of the tail function below).
class Unk_IaNames { public: CString FUN_14051c870(); void* m_names; };

typedef ATL::CRBMap<CStringW, IndividualArenaStringId, ATL::CStringElementTraits<CStringW> > IndividualArenaStringMap;
std::auto_ptr<IndividualArenaStringMap> MakeIndividualArenaStringMap();     // 0x14084d0c0

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv)
bool CIndividualArenaDataTable::s_bInit;
#endif

// @0x14051a170
IndividualArenaData::IndividualArenaData() : m_nArenaType(0)
{
    m_nFieldID = 0;
    m_nPlayerCount = 0;
    m_nRewardItemId1 = 0;
    m_nReward1Winner = 0;
    m_nReward1Loser = 0;
    m_nRewardItemId2 = 0;
    m_nReward2Winner = 0;
    m_nReward2Loser = 0;
}

// @0x14051a220
IndividualArenaData::~IndividualArenaData()
{
}

// @0x14051a260
CIndividualArenaDataTable::CIndividualArenaDataTable() : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14051a300
CIndividualArenaDataTable::~CIndividualArenaDataTable()
{
}

// @0x14051a360
bool CIndividualArenaDataTable::Load()
{
    m_map.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "IndividualArena.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return false;
    std::auto_ptr<IndividualArenaStringMap> strings = MakeIndividualArenaStringMap();
    if (strings.get() == 0)
        return false;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("individualArena"); pNode != 0;
         pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("individualArena")))
    {
        int nType = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "arenaType", nType);
        if (nType == 0)
            continue;
        DataPtr data(MS2SvrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "arenaType", data->m_nArenaType);
        CStringW strName;
        FUN_140873420(pNode, "arenaName", strName);
        const IndividualArenaStringMap::CPair* pName = strings->Lookup(strName);
        if (pName == 0)
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return false;
        }
        data->m_nNameId = pName->m_value;
        CStringW strDetail;
        FUN_140873420(pNode, "arenaDetail", strDetail);
        const IndividualArenaStringMap::CPair* pDetail = strings->Lookup(strDetail);
        if (pDetail == 0)
        {
            Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return false;
        }
        data->m_nDetailId = pDetail->m_value;
        FUN_1408733e0(pNode, "bannerPath", data->m_strBannerPath);
        XmlGetAttr((class TiXmlElement*)(pNode), "fieldID", data->m_nFieldID);
        XmlGetAttr((class TiXmlElement*)(pNode), "playerCount", data->m_nPlayerCount);
        XmlGetAttr((class TiXmlElement*)(pNode), "rewardItemId1", data->m_nRewardItemId1);
        XmlGetAttr((class TiXmlElement*)(pNode), "reward1Winner", data->m_nReward1Winner);
        XmlGetAttr((class TiXmlElement*)(pNode), "reward1Loser", data->m_nReward1Loser);
        XmlGetAttr((class TiXmlElement*)(pNode), "rewardItemId2", data->m_nRewardItemId2);
        XmlGetAttr((class TiXmlElement*)(pNode), "reward2Winner", data->m_nReward2Winner);
        XmlGetAttr((class TiXmlElement*)(pNode), "reward2Loser", data->m_nReward2Loser);
        m_map.SetAt(nType, data);
    }
    SetInit(true);
    return true;
}

// @0x14051a980
CIndividualArenaDataTable::DataPtr CIndividualArenaDataTable::GetData(int nArenaType)
{
    CheckInit();
    DataPtr p;
    if (!m_map.Lookup(nArenaType, p))
        return DataPtr(0);
    return p;
}

// @0x14051b1c0
void CIndividualArenaDataTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CIndividualArenaDataTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14051c4f0
void CIndividualArenaDataTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x14051c750
MS2_EMIT_CRT_MEMMOVE_S();

// @0x14051c870
CString Unk_IaNames::FUN_14051c870()
{
    if (((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(&m_names))->GetCount() == 0)
        return "";
    int nIndex = FUN_140768010((int)((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(&m_names))->GetCount(), 0);
    return *(CString*)FUN_140164930(&m_names, nIndex);
}
