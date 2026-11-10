// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFieldMissionTable: Table/fieldMission.xml.
// MS2-UNIT: ?\fieldmissiontable.cpp
// MS2-RANGE: 0x14037bf80-0x140380840 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNext@?$CRBTree@HV?$MS2Ptr@VCFieldMissionReward@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFieldMissionReward@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14037f170 ; prop
// MS2-PIN: ?GetPrev@?$CRBTree@HV?$MS2Ptr@VCFieldMissionReward@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFieldMissionReward@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14037f1b0 ; prop
// MS2-PIN: ?SetAt@?$CRBMap@HV?$MS2Ptr@VCFieldMissionReward@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFieldMissionReward@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VCFieldMissionReward@@@@@Z 0x14037fd70 ; unique
// MS2-PIN: ?Successor@?$CRBTree@HV?$MS2Ptr@VCFieldMissionReward@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFieldMissionReward@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14037fe50 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_SubJobLevel@@HU?$less@W4Unk_SubJobLevel@@@std@@V?$allocator@U?$pair@$$CBW4Unk_SubJobLevel@@H@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_SubJobLevel@@H@std@@PEAX@2@@Z 0x140380110 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\fieldmissiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fieldmissiontable.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <map>
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers (the same xml loader helpers the other table units use).
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was V::FUN_14015eb90
class Unk_CommonLog
{
public:
};
class CLogString* GetLogString();
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax

// @0x14037c8c0
int FUN_14037c8c0(CString& str)
{
    if (str.IsEmpty())
        return 0;
    if (str.CompareNoCase("item") == 0)
        return 1;
    else if (str.CompareNoCase("statpoint") == 0)
        return 2;
    else if (str.CompareNoCase("skillpoint") == 0)
        return 3;
    return 0;
}

// @0x14037cb70
int FUN_14037cb70(TiXmlElement* pElem, const char* pszName, int* pnType)
{
    if (FALSE)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet != 0)
        return nRet;
    *pnType = FUN_14037c8c0(str);
    return nRet;
}

// @0x14037e900
CFieldMissionReward::CFieldMissionReward() : m_nType(0), m_nValue(0), m_item(), m_nSubJob(Unk_SubJobLevel_1)
{
}

// @0x14037eab0
CFieldMissionReward::~CFieldMissionReward()
{
}

// @0x14037bf80
CFieldMissionTable::CFieldMissionTable() : m_rewards(10)
{
}

// @0x14037bfd0
CFieldMissionTable::~CFieldMissionTable()
{
}

// @0x14037c010
int CFieldMissionTable::Load()
{
    CString strPath = GetXmlPath("Table", "fieldMission.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pRound = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("round")); pRound != 0; pRound = ((class TiXmlElement*)((class Unk_XmlNode*)(pRound))->NextSibling("round")))
    {
        RewardPtr spReward(new CFieldMissionReward);
        int nRound = 0;
        XmlGetAttr((class TiXmlElement*)(pRound), "mission", reinterpret_cast<int&>(nRound));
        FUN_14037cb70(pRound, "type", &spReward->m_nType);
        if (spReward->m_nType == 1)
        {
            CStringW strValue;
            XmlGetAttr((class TiXmlElement*)(pRound), "value", strValue);
            spReward->m_item.vfunc_1(CStringW(strValue));
        }
        else
        {
            XmlGetAttr((class TiXmlElement*)(pRound), "value", reinterpret_cast<int&>(spReward->m_nValue));
            int nSubJob = 0;
            XmlGetAttr((class TiXmlElement*)(pRound), "subJobLevel", reinterpret_cast<int&>(nSubJob));
            if (nSubJob == 0)
                spReward->m_nSubJob = Unk_SubJobLevel_1;
            else if (nSubJob == 1)
                spReward->m_nSubJob = Unk_SubJobLevel_2;
        }
        m_rewards.SetAt(nRound, spReward);
    }
    return 1;
}

// @0x14037c3d0
CFieldMissionTable::RewardPtr CFieldMissionTable::GetReward(int nRound)
{
    RewardPtr spReward(0);
    m_rewards.Lookup(nRound, spReward);
    return spReward;
}

// @0x14037c450
int CFieldMissionTable::GetPrevRound(int nRound)
{
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != 0; m_rewards.GetNext(pos))
    {
        int nKey = m_rewards.GetKeyAt(pos);
        if (nKey == nRound)
        {
            m_rewards.GetPrev(pos);
            if (pos == 0)
                return 0;
            return m_rewards.GetKeyAt(pos);
        }
    }
    return 0;
}

// @0x14037c510
int CFieldMissionTable::GetNextRound(int nRound)
{
    if (nRound == 0)
    {
        POSITION pos = m_rewards.GetHeadPosition();
        if (pos != 0)
            return m_rewards.GetKeyAt(pos);
    }
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != 0; m_rewards.GetNext(pos))
    {
        int nKey = m_rewards.GetKeyAt(pos);
        if (nKey == nRound)
        {
            m_rewards.GetNext(pos);
            if (pos == 0)
                return 0;
            return m_rewards.GetKeyAt(pos);
        }
    }
    return 0;
}

// @0x14037c610
int CFieldMissionTable::GetMaxRound()
{
    int nMax = 0;
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != 0; m_rewards.GetNext(pos))
    {
        int nKey = m_rewards.GetKeyAt(pos);
        if (nKey > nMax)
            nMax = nKey;
    }
    return nMax;
}

// @0x14037c6a0
void CFieldMissionTable::GetSkillPoints(int nRound, std::map<Unk_SubJobLevel, int>& rOut)
{
    if (nRound == 0)
        return;
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != 0; m_rewards.GetNext(pos))
    {
        int nKey = m_rewards.GetKeyAt(pos);
        if (nKey <= nRound)
        {
            RewardPtr spReward = m_rewards.GetValueAt(pos);
            if (spReward->m_nType == 3)
                rOut[spReward->m_nSubJob] += spReward->m_nValue;
        }
    }
}

// @0x14037c7c0
int CFieldMissionTable::GetStatPoints(int nRound)
{
    if (nRound == 0)
        return 0;
    int nSum = 0;
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != 0; m_rewards.GetNext(pos))
    {
        int nKey = m_rewards.GetKeyAt(pos);
        if (nKey <= nRound)
        {
            RewardPtr spReward = m_rewards.GetValueAt(pos);
            if (spReward->m_nType == 2)
                nSum = nSum + spReward->m_nValue;
        }
    }
    return nSum;
}

// Full-executable aliases for existing field-mission table methods.
// MS2-PIN: ?Load@CFieldMissionTable@@QEAAHXZ 0x14037c010
// MS2-PIN: ?GetPrevRound@CFieldMissionTable@@QEAAHH@Z 0x14037c450
// MS2-PIN: ?GetNextRound@CFieldMissionTable@@QEAAHH@Z 0x14037c510
// MS2-PIN: ?FUN_14037c010@@YAXPEAVCFieldMissionTable@@@Z 0x14037c010
// MS2-PIN: ?FUN_14037c450@@YAHPEAVCFieldMissionTable@@H@Z 0x14037c450
// MS2-PIN: ?FUN_14037c510@@YAHPEAVCFieldMissionTable@@H@Z 0x14037c510
// MS2-PIN: ?FUN_14037c510@@YAHPEAXH@Z 0x14037c510

// MS2-FUNCTIONAL: full-exe void ABI entry; the source Load result is intentionally discarded.
void FUN_14037c010(CFieldMissionTable* pTable) { pTable->Load(); }
// MS2-FUNCTIONAL: full-exe compatibility entry forwarding to the recovered round traversal.
int FUN_14037c450(CFieldMissionTable* pTable, int nRound) { return pTable->GetPrevRound(nRound); }
// MS2-FUNCTIONAL: full-exe compatibility entry forwarding to the recovered round traversal.
int FUN_14037c510(CFieldMissionTable* pTable, int nRound) { return pTable->GetNextRound(nRound); }
// MS2-FUNCTIONAL: same pointer ABI under a generic caller-side type used by one unresolved reference.
int FUN_14037c510(void* pTable, int nRound) { return static_cast<CFieldMissionTable*>(pTable)->GetNextRound(nRound); }

// MS2-PIN: ?FUN_14037c010@@YAXPEAVCFieldMissionTable@@@Z 0x14037c010
// MS2-PIN: ?FUN_14037c450@@YAHPEAVCFieldMissionTable@@H@Z 0x14037c450
// MS2-PIN: ?FUN_14037c510@@YAHPEAVCFieldMissionTable@@H@Z 0x14037c510
// MS2-PIN: ?FUN_14037c510@@YAHPEAXH@Z 0x14037c510
