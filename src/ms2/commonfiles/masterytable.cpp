// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMasteryTable: Table/masteryReceipe.xml, Table/mastery.xml
// and Table/masteryDifferentialFactor.xml (job skill recipes, grades and reward factors).
// MS2-UNIT: commonfiles\masterytable.cpp
// MS2-RANGE: 0x1406694a0-0x140672770 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@QEAA@H@Z 0x14066cd40 ; unique
// MS2-PIN: ??0?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@QEAA@XZ 0x14066cd90 ; prop
// MS2-PIN: ??0?$MS2Ptr@VMastery@CMasteryTable@@@@QEAA@H@Z 0x14066cdf0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VMastery@CMasteryTable@@@@QEAA@PEAVMastery@CMasteryTable@@@Z 0x14066ce10 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCMasteryReceipe@@@@QEAA@PEAVCMasteryReceipe@@@Z 0x14066cf40 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCMasteryReceipe@@@@QEAA@XZ 0x14066cf70 ; prop
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@@@QEAA@XZ 0x14066cf90 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@@3@@ATL@@IEAA@H@Z 0x14066d220 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$MS2Ptr@VCMasteryReceipe@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMasteryReceipe@@@@@3@@ATL@@IEAA@H@Z 0x14066d260 ; unique
// MS2-PIN: ??1?$TPtredDummy@V?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@@@UEAA@XZ 0x14066d5e0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@QEBAPEAVDifferentialFactor@CMasteryTable@@XZ 0x14066d970 ; unique
// MS2-PIN: ??C?$MS2Ptr@VMastery@CMasteryTable@@@@QEBAPEAVMastery@CMasteryTable@@XZ 0x14066d980 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCMasteryReceipe@@@@QEBAPEAVCMasteryReceipe@@XZ 0x14066d9a0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAA_KAEBU?$pair@HH@std@@@Z 0x14066dca0 ; unique
// MS2-PIN: ?GetData@?$CAtlArray@V?$MS2Ptr@VCMasteryReceipe@@@@V?$CElementTraits@V?$MS2Ptr@VCMasteryReceipe@@@@@ATL@@@ATL@@QEAAPEAV?$MS2Ptr@VCMasteryReceipe@@@@XZ 0x14066e7f0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14066eac0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@AEAA_N_K@Z 0x14066ed10 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@@3@@ATL@@QEBA_NHAEAV?$MS2Ptr@VDifferentialFactor@CMasteryTable@@@@@Z 0x14066f6c0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@U?$pair@HH@std@@@ATL@@SAXPEAU?$pair@HH@std@@0_K@Z 0x140670e80 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?AddRef@?$TPtrValue@V?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@@@AEBAXXZ 0x140672210
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCMasteryReceipe@@@@@ATL@@SAXPEAV?$MS2Ptr@VCMasteryReceipe@@@@0_K@Z 0x140670ec0
// MS2-PIN: ??_7CMasteryTable@@6B?$TSingleton@VCMasteryTable@@@@@ 0x142d71768
// MS2-PIN: ??_7CMasteryTable@@6B?$CValidData@VCMasteryTable@@@@@ 0x142d71778
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@CAXPEAU?$pair@HH@std@@_K@Z 0x14066de30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\masterytable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "masterytable.h"
#include "luautil.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include <stdlib.h>
#include "hook/ms2hook.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// Unrecovered helpers (the xml loader helpers the other table units use).
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
enum Unk_InteractMasteryType { Unk_InteractMasteryType_None = 0 }; template <class E> int XmlValue(TiXmlElement*, const char*, E&);     // enum value (mastery type)
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
CStringA FUN_140cc2ad0(const CString& strCategory, const CString& strFile);   // icon file path in a category
CStringW GetStringCommonByKey(const CStringW& strKey);                              // string table lookup
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
bool FUN_14028d470(float fValue, float fTolerance);                          // commonutil: nearly equal

// Item counts the player holds back by the production limit (id -> count; the exe global named by the zone unit).
extern ATL::CAtlMap<int, int> g_143ab3150;

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CMasteryTable::s_bInit;
#endif

// @0x14066d000
CMasteryReceipe::CMasteryReceipe() : m_nId(0), m_nType(0), m_nLevel(0), m_nRequireMastery(0), m_nRequireMeso(0),
    m_nRewardMastery(0), m_nGatheringTime(0), m_nHighPropLimit(0), m_nNormalPropLimit(0), m_nExceptRewardExp(0)
{
}

// @0x14066d320
CMasteryTable::DifferentialFactor::DifferentialFactor() : m_nFactor(0)
{
}

// @0x14066d370
CMasteryTable::Mastery::Mastery() : m_nGrade(0), m_nValue(0)
{
}

// @0x1406694a0
int CMasteryReceipe::Load(TiXmlElement* pNode)
{
    XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<int&>(m_nId));
    XmlValue(pNode, "masteryType", *(Unk_InteractMasteryType*)&m_nType);
    XmlGetAttr((class TiXmlElement*)(pNode), "requireMastery", m_nRequireMastery);
    XmlGetAttr((class TiXmlElement*)(pNode), "requireMeso", reinterpret_cast<__int64&>(m_nRequireMeso));
    XmlTokenList(pNode, "requireQuest", m_requireQuest);
    XmlGetAttr((class TiXmlElement*)(pNode), "requireLevel", reinterpret_cast<unsigned short&>(m_nLevel));
    XmlGetAttr((class TiXmlElement*)(pNode), "rewardMastery", m_nRewardMastery);
    XmlGetAttr((class TiXmlElement*)(pNode), "gatheringTime", m_nGatheringTime);
    XmlGetAttr((class TiXmlElement*)(pNode), "highPropLimitCount", m_nHighPropLimit);
    XmlGetAttr((class TiXmlElement*)(pNode), "normalPropLimitCount", m_nNormalPropLimit);
    XmlGetAttr((class TiXmlElement*)(pNode), "exceptRewardExp", reinterpret_cast<int&>(m_nExceptRewardExp));
    if (m_nType == 11)
        m_nLevel = 50;
    ATL::CAtlArray<unsigned> habitats;
    XmlTokenList(pNode, "habitatMapId", habitats);
    for (size_t i = 0; i < habitats.GetCount(); i++)
    {
        if (m_strHabitat.GetLength() != 0)
            m_strHabitat += L", ";
        m_strHabitat += TSingleton<CReservedWordTable>::GetInstance()/*C3:TSingleton<CReservedWordTable>::GetInstance*/->FUN_1416fbfe0(habitats[i], CStringW(L"#909090"));
    }
    for (size_t i = 1; i <= 5; i++)
    {
        CString strKey = StringFormat("requireItem{0}", i);
        CStringW strValue;
        XmlGetAttr((class TiXmlElement*)(pNode), strKey, strValue);
        m_ingredients.FUN_14026b9d0(strValue);
    }
    for (size_t i = 1; i <= 5; i++)
    {
        CString strKey = StringFormat("rewardItem{0}", i);
        CStringW strValue;
        XmlGetAttr((class TiXmlElement*)(pNode), strKey, strValue);
        ItemEntity item;
        item.vfunc_1(CStringW(strValue));
        if (item.m_itemId != 0)
            m_rewards.Add(item);
    }
    return 1;
}

// @0x140669980
CStringA CMasteryReceipe::IconPath()
{
    CString strFile = StringFormat("{0}.png", m_nId);
    return FUN_140cc2ad0("MasteryReceipe", strFile);
}

// @0x140669a20
CMasteryTable::CMasteryTable() : m_differentials(17, 0.75f, 0.25f, 2.25f, 10), m_receipes(17, 0.75f, 0.25f, 2.25f, 10),
    m_ingredientReceipes(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140669b70
CMasteryTable::~CMasteryTable()
{
}

// @0x140669c30
int CMasteryTable::Load()
{
    SetInit(true);
    if (!LoadReceipes())
        return 0;
    if (!LoadMastery())
        return 0;
    if (!LoadDifferentials())
        return 0;
    return 1;
}

// @0x140669c90
// MS2-FUNCTIONAL: exe builds the two literal CString temps and the path before the TiXmlDocument with a different EH state layout (precedent continentregiontable); not reproduced
int CMasteryTable::LoadMastery()
{
    CString strPath = FUN_14071a5b0("Table", "mastery.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>((class TiXmlElement *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pType = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("mastery")); pType != 0; pType = ((class TiXmlElement*)((class Unk_XmlNode*)(pType))->NextSibling("mastery")))
    {
        int nType = 0;
        XmlGetAttr((class TiXmlElement*)(pType), "type", reinterpret_cast<int&>(nType));
        if (nType < 0 || nType >= 12)
            continue;
        for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pType))->FirstChild("v")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
        {
            if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
                continue;
            MasteryPtr spMastery(new Mastery);
            XmlGetAttr((class TiXmlElement*)(pNode), "value", spMastery->m_nValue);
            XmlGetAttr((class TiXmlElement*)(pNode), "grade", reinterpret_cast<int&>(spMastery->m_nGrade));
            ATL::CAtlArray<unsigned> ids;
            ATL::CAtlArray<int> ranks;
            ATL::CAtlArray<int> counts;
            XmlTokenList(pNode, "rewardJobItemID", ids);
            XmlTokenList(pNode, "rewardJobItemRank", ranks);
            XmlTokenList(pNode, "rewardJobItemCount", counts);
            if (ids.GetCount() != ranks.GetCount())
                return 0;
            if (ranks.GetCount() != counts.GetCount())
                return 0;
            for (size_t i = 0; i < ids.GetCount(); i++)
            {
                MS2Ptr<ItemEntity> spItem(new ItemEntity);
                spItem->m_itemId = ids[i];
                spItem->SetRank(ranks[i]);
                spItem->m_count = counts[i];
                spMastery->m_rewards.Add(spItem);
            }
            m_mastery[nType].SetAt(spMastery->m_nGrade, spMastery);
        }
    }
    return 1;
}

// @0x14066a300
// MS2-FUNCTIONAL: exe builds the two literal CString temps and the path before the TiXmlDocument with a different EH state layout (precedent continentregiontable); not reproduced
int CMasteryTable::LoadReceipes()
{
    CString strPath = FUN_14071a5b0("Table", "masteryReceipe.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>((class TiXmlElement *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("receipe")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("receipe")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        int nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<unsigned&>(nId));
        ReceipePtr spReceipe(new CMasteryReceipe);
        if (spReceipe->Load(pNode) != 0)
        {
            m_receipes.SetAt(nId, spReceipe);
            for (size_t i = 0; i < spReceipe->m_ingredients.FUN_14026bee0(); i++)
            {
                Unk_IngRef ref = spReceipe->m_ingredients.FUN_14026bdc0(i);
                IngredientListPtr spList(0);
                if (!m_ingredientReceipes.Lookup(ref->FUN_14026b500(), spList))
                {
                    spList = Unk_GrNewTag(0);
                    m_ingredientReceipes.SetAt(ref->FUN_14026b500(), spList);
                }
                spList->Add(std::make_pair(spReceipe->m_nId, reinterpret_cast<unsigned&>(ref->m_c)));
            }
        }
    }
    return 1;
}

// @0x14066a740
int CMasteryTable::LoadDifferentials()
{
    CString strPath = FUN_14071a5b0("Table", "masteryDifferentialFactor.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>((class TiXmlElement *)((class Unk_XmlNode*)((&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        int nDifference = 0;
        DifferentialPtr spFactor(new DifferentialFactor);
        XmlGetAttr((class TiXmlElement*)(pNode), "differential", reinterpret_cast<int&>(nDifference));
        XmlGetAttr((class TiXmlElement*)(pNode), "factor", spFactor->m_nFactor);
        XmlGetAttr((class TiXmlElement*)(pNode), "icon", spFactor->m_strIcon);
        m_differentials.SetAt(nDifference, spFactor);
    }
    return 1;
}

// @0x14066aa00
CMasteryTable::ReceipePtr CMasteryTable::Find(int nReceipeId)
{
    CheckInit();
    ReceipePtr sp(0);
    m_receipes.Lookup(nReceipeId, sp);
    return sp;
}

// qsort comparator of Receipes: by required mastery (descending order of the compare result), then by id.
// @0x14066c7a0
static int __cdecl CompareReceipes(const void* pA, const void* pB)
{
    CMasteryTable::ReceipePtr spA(*static_cast<const CMasteryTable::ReceipePtr*>(pA));
    CMasteryTable::ReceipePtr spB(*static_cast<const CMasteryTable::ReceipePtr*>(pB));
    if (spA->m_nRequireMastery == spB->m_nRequireMastery)
        return spA->m_nId > spB->m_nId ? 1 : -1;
    return spA->m_nRequireMastery > spB->m_nRequireMastery ? 1 : -1;
}

// @0x14066aa90
void CMasteryTable::Receipes(int nType, ATL::CAtlArray<ReceipePtr>& rOut)
{
    for (POSITION pos = m_receipes.GetStartPosition(); pos != 0; m_receipes.GetNext(pos))
    {
        ReceipePtr sp(m_receipes.GetValueAt(pos));
        if (sp->m_nType != nType)
            continue;
        rOut.Add(sp);
    }
    qsort(rOut.GetData(), rOut.GetCount(), sizeof(ReceipePtr), CompareReceipes);
}

// @0x14066ab90
int CMasteryTable::Factor(int nReceipeId, unsigned nValue)
{
    CheckInit();
    ReceipePtr spReceipe = Find(nReceipeId);
    if (!spReceipe)
        return 0;
    if (IsOther(ReceipePtr(spReceipe)))
        return spReceipe->m_nRewardMastery;
    int nBase = Grade(spReceipe->m_nType, spReceipe->m_nRequireMastery);
    int nNow = Grade(spReceipe->m_nType, nValue);
    int nDifference = nNow - nBase;
    if (nDifference >= 0)
    {
        DifferentialPtr spFactor(0);
        if (m_differentials.Lookup(nDifference, spFactor))
        {
            float fReward = (float)(unsigned)(spReceipe->m_nRewardMastery * spFactor->m_nFactor) / 10000.0f;
            return (unsigned)(fReward + 0.5f);
        }
    }
    return 0;
}

// @0x14066adb0
CStringA CMasteryTable::DifferentialName(int nReceipeId, unsigned nValue)
{
    CheckInit();
    ReceipePtr spReceipe = Find(nReceipeId);
    if (!spReceipe)
        return CStringA("");
    int nBase = Grade(spReceipe->m_nType, spReceipe->m_nRequireMastery);
    int nNow = Grade(spReceipe->m_nType, nValue);
    int nDifference = nNow - nBase;
    if (nDifference >= 0)
    {
        DifferentialPtr spFactor(0);
        if (m_differentials.Lookup(nDifference, spFactor))
            return spFactor->m_strIcon;
    }
    return CStringA("");
}

// @0x14066af60
int CMasteryTable::Grade(int nType, unsigned nValue)
{
    CheckInit();
    if (nType < 0 || nType >= 12)
        return 0;
    ATL::CRBMap<int, MasteryPtr>& rMap = m_mastery[nType];
    for (POSITION pos = rMap.GetHeadPosition(); pos != 0; rMap.GetNext(pos))
    {
        MasteryPtr sp(rMap.GetValueAt(pos));
        if (sp->m_nValue > nValue)
            return sp->m_nGrade - 1;
    }
    return MaxGrade(nType);
}

// @0x14066b050
int CMasteryTable::MaxGrade(int nType)
{
    if (nType < 0 || nType >= 12)
        return 0;
    ATL::CRBMap<int, MasteryPtr>& rMap = m_mastery[nType];
    POSITION pos = rMap.GetTailPosition();
    if (pos != 0)
    {
        MasteryPtr sp(rMap.GetValueAt(pos));
        return sp->m_nGrade;
    }
    return 0;
}

// @0x14066b100
// MS2-FUNCTIONAL: not byte-identical (local/temporary layout and member order differ from the exe build)
void CMasteryTable::Rewards(int nId, int nJob, ATL::CAtlArray<MS2Ptr<ItemEntity> >& rOut)
{
    CheckInit();
    int nGrade = GradeFromID(nId);
    int nType = TypeFromID(nId);
    if (nType < 0 || nType > 12)
        return;
    if (nGrade < 1)
        return;
    if (nGrade > MaxGrade(nType))
        return;
    MasteryPtr spMastery(0);
    if (m_mastery[nType].Lookup(nGrade, spMastery))
    {
        for (size_t i = 0; i < spMastery->m_rewards.GetCount(); i++)
        {
            MS2Ptr<ItemEntity> spItem(spMastery->m_rewards[i]);
            if (spItem->m_itemId != 0)
            {
                MS2Ptr<CItemData> spData = FUN_14053f870(spItem->m_itemId);
                if (!spData)
                    continue;
                if (!spData->limit.IsJobRecommended(nJob))
                    continue;
                rOut.Add(spItem);
            }
        }
    }
}

// @0x14066b310
unsigned CMasteryTable::Value(int nType, int nGrade)
{
    CheckInit();
    if (nGrade < 1)
        return (unsigned)-1;
    if (nGrade > MaxGrade(nType))
        return (unsigned)-1;
    MasteryPtr spMastery(0);
    if (m_mastery[nType].Lookup(nGrade, spMastery))
        return spMastery->m_nValue;
    return (unsigned)-1;
}

// @0x14066b3e0
unsigned CMasteryTable::MaxValue(int nType)
{
    if (nType < 0 || nType >= 12)
        return (unsigned)-1;
    int nMax = MaxGrade(nType);
    if (nMax == 0)
        return (unsigned)-1;
    return Value(nType, nMax);
}

// @0x14066b440
// MS2-FUNCTIONAL: not byte-identical (local/temporary layout and member order differ from the exe build)
int CMasteryTable::Type(int nReceipeId)
{
    ReceipePtr sp = Find(nReceipeId);
    if (!sp)
        return 12;
    return sp->m_nType;
}

// @0x14066b4c0
int CMasteryTable::TypeFromID(unsigned nId)
{
    return nId / 1000;
}

// @0x14066b4e0
int CMasteryTable::GradeFromID(unsigned nId)
{
    return nId % 1000;
}

// @0x14066b500
int CMasteryTable::MakeID(int nType, int nGrade)
{
    return nType * 1000 + nGrade;
}

// @0x14066b530
int CMasteryTable::StringID(int nType)
{
    switch (nType)
    {
    case 1:
        MS2_ASSERT_AT(0x1f1, 0);
        return 0x423;
    case 2:
        MS2_ASSERT_AT(500, 0);
        return 0x427;
    case 3:
        return 0xc1f;
    case 4:
        return 0xc20;
    case 5:
        return 0xc21;
    case 6:
        return 0xc22;
    case 7:
        return 0xc23;
    case 8:
        return 0xc24;
    case 9:
        return 0xc25;
    case 10:
        return 0xc26;
    case 11:
        return 0xc28;
    default:
        return 0;
    }
}

// @0x14066b640
// MS2-FUNCTIONAL: not byte-identical (local/temporary layout and member order differ from the exe build)
ItemEntity* CMasteryTable::FirstItem(int nReceipeId)
{
    ReceipePtr sp = Find(nReceipeId);
    if (!sp)
        return 0;
    if (sp->m_rewards.GetCount() == 0)
        return 0;
    return &sp->m_rewards[0];
}

// @0x14066b710
// MS2-FUNCTIONAL: not byte-identical (local/temporary layout and member order differ from the exe build)
int CMasteryTable::HasIngredient(int nReceipeId, int nItemId)
{
    ReceipePtr spReceipe = Find(nReceipeId);
    if (!spReceipe)
        return 0;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    for (size_t i = 0; i < spReceipe->m_ingredients.FUN_14026bee0(); i++)
    {
        Unk_IngRef ref = spReceipe->m_ingredients.FUN_14026bdc0(i);
        if (ref->m_b != 0 && spItem->HasStringTag(ref->m_b))
            return 1;
        if (ref->FUN_14026b500() == nItemId)
            return 1;
    }
    return 0;
}

// @0x14066b910
int CMasteryTable::HasTypeIngredient(int nType, int nItemId)
{
    for (POSITION pos = m_receipes.GetStartPosition(); pos != 0; m_receipes.GetNext(pos))
    {
        ReceipePtr sp(m_receipes.GetValueAt(pos));
        if (sp->m_nType != nType)
            continue;
        if (HasIngredient(sp->m_nId, nItemId))
            return 1;
    }
    return 0;
}

// @0x14066ba00
int CMasteryTable::IsProductionType(int nType)
{
    switch (nType)
    {
    case 1:
    case 2:
        MS2_ASSERT_AT(0x253, 0);
        return 0;
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return 0;
    default:
        return 0;
    }
}

// @0x14066bab0
int CMasteryTable::IsProduction(int nReceipeId)
{
    return IsProduction(Find(nReceipeId));
}

// @0x14066bb00
// MS2-FUNCTIONAL: not byte-identical (local/temporary layout and member order differ from the exe build)
int CMasteryTable::IsProduction(ReceipePtr spReceipe)
{
    if (!spReceipe)
        return 0;
    return IsProductionType(spReceipe->m_nType);
}

// @0x14066bb80
int CMasteryTable::IsOther(int nReceipeId)
{
    return IsProduction(nReceipeId) == 0;
}

// @0x14066bbc0
int CMasteryTable::IsOther(ReceipePtr spReceipe)
{
    return IsProduction(ReceipePtr(spReceipe)) == 0;
}

// @0x14066bc40
int CMasteryTable::LimitState(int nReceipeId)
{
    ReceipePtr sp = Find(nReceipeId);
    if (!sp)
        return 3;
    int nHeld = 0;
    g_143ab3150.Lookup(nReceipeId, nHeld);
    double dLimit = ((class CLua*)FUN_1401c0db0())->CalcGatheringObjectgSuccessProp(nHeld, sp->m_nHighPropLimit, sp->m_nNormalPropLimit);
    if (FUN_14028d470((float)dLimit, 0.0f))
        return 3;
    if ((unsigned)nHeld < sp->m_nHighPropLimit)
        return 0;
    else if ((unsigned)nHeld < sp->m_nNormalPropLimit)
        return 1;
    else
        return 2;
}

// @0x14066bdd0
CStringW CMasteryTable::TypeName(int nType)
{
    switch (nType)
    {
    case 3:
        return GetStringCommonByKey(L"s_mastery_mining");
    case 4:
        return GetStringCommonByKey(L"s_mastery_gathering");
    case 5:
        return GetStringCommonByKey(L"s_mastery_breeding");
    case 6:
        return GetStringCommonByKey(L"s_mastery_farming");
    case 7:
        return GetStringCommonByKey(L"s_mastery_blacksmithing");
    case 8:
        return GetStringCommonByKey(L"s_mastery_engraving");
    case 9:
        return GetStringCommonByKey(L"s_mastery_alchemist");
    case 10:
        return GetStringCommonByKey(L"s_mastery_cooking");
    case 11:
        return GetStringCommonByKey(L"s_mastery_pettaming");
    default:
        return L"";
    }
}

// @0x14066c110
CStringW CMasteryTable::SuccessDescription(int nType, int nReceipeId, int nColored)
{
    CStringW strText;
    switch (LimitState(nReceipeId))
    {
    case 0:
        strText = FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_high"), TypeName(nType));
        break;
    case 1:
        strText = FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_normal"), TypeName(nType));
        break;
    case 2:
        strText = FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_low"), TypeName(nType));
        break;
    case 3:
        strText = FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_zero"), TypeName(nType));
        break;
    }
    if (nColored == 0)
        return strText;
    switch (LimitState(nReceipeId))
    {
    case 0:
        return FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_green"), strText);
    case 1:
        return FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_yellow"), strText);
    case 2:
    case 3:
        return FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_success_prop_red"), strText);
    }
    return CStringW(L"");
}

// @0x14066c690
CStringW CMasteryTable::GradeName(int nType, int nGrade)
{
    CStringW strKey = StringFormat(L"s_mastery_grade_{0}", nGrade);
    return GetStringCommonByKey(strKey);
}

// @0x14066c710
CMasteryTable::IngredientListPtr CMasteryTable::IngredientReceipes(unsigned nItemId)
{
    IngredientListPtr sp(0);
    m_ingredientReceipes.Lookup(nItemId, sp);
    return sp;
}

// @0x14066de70
void CMasteryTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMasteryTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140671e30
void CMasteryTable::SetInit(bool b)
{
    s_bInit = b;
}
// fx25: the 1-load GetCount look-alike; FUN_14066aa90 (and uimasterydialog's 0x140eb0da0) call 0x14066e7e0
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCMasteryReceipe@@@@V?$CElementTraits@V?$MS2Ptr@VCMasteryReceipe@@@@@ATL@@@ATL@@QEBA_KXZ 0x14066e7e0
// Full-executable aliases to the corresponding CMasteryTable routines already emitted in this unit.
// MS2-PIN: ?IconPath@CMasteryReceipe@@QEAA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140669980
// MS2-PIN: ?Receipes@CMasteryTable@@QEAAXHAEAV?$CAtlArray@V?$MS2Ptr@VCMasteryReceipe@@@@V?$CElementTraits@V?$MS2Ptr@VCMasteryReceipe@@@@@ATL@@@ATL@@@Z 0x14066aa90
// MS2-PIN: ?Rewards@CMasteryTable@@QEAAXHHAEAV?$CAtlArray@V?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@ATL@@@ATL@@@Z 0x14066b100
// MS2-PIN: ?HasTypeIngredient@CMasteryTable@@QEAAHHH@Z 0x14066b910
// MS2-PIN: ?SuccessDescription@CMasteryTable@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HHH@Z 0x14066c110
// MS2-PIN: ?GradeName@CMasteryTable@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HH@Z 0x14066c690
// MS2-PIN: ?FUN_140669980@Unk_MRec@@QEAA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140669980
// MS2-PIN: ?FUN_14066aa90@Unk_MData@@QEAAXHAEAV?$CAtlArray@V?$MS2Ptr@VUnk_MRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_MRec@@@@@ATL@@@ATL@@@Z 0x14066aa90
// MS2-PIN: ?FUN_14066b100@Unk_MData@@QEAAXHHAEAV?$CAtlArray@V?$MS2Ptr@UItemEntity@@@@V?$CElementTraits@V?$MS2Ptr@UItemEntity@@@@@ATL@@@ATL@@@Z 0x14066b100
// MS2-PIN: ?FUN_14066b100@Unk_MmTable@@QEAAXHHAEAV?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@@Z 0x14066b100
// MS2-PIN: ?FUN_14066b910@Unk_MData@@QEAAHHH@Z 0x14066b910
// MS2-PIN: ?FUN_14066c110@Unk_MData@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HHH@Z 0x14066c110
// MS2-PIN: ?FUN_14066c690@Unk_MData@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HH@Z 0x14066c690
// MS2-PIN: ?FUN_14066c690@Unk_SSGMastery@@QEAA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HH@Z 0x14066c690
