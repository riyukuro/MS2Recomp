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

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_CommonLog
{
public:
    void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg);
};
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax

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
int FUN_14037cb70(Unk_140165cf0* pElem, const char* pszName, int* pnType)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
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
// MS2-FUNCTIONAL: the exe builds the file/dir CString temps and the path in place with early destruction (as in chapterbooktable); no source form found
int CFieldMissionTable::Load()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("fieldMission.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (GetFileSystem()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
    {
        return 0;
    }
    else
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return 0;
        }
        else
        {
            for (Unk_140165cf0* pRound = pRoot->FUN_140165cf0("round"); pRound != 0; pRound = pRound->FUN_140168650("round"))
            {
                RewardPtr spReward(new CFieldMissionReward);
                int nRound = 0;
                FUN_1408731e0(pRound, "mission", nRound);
                FUN_14037cb70(pRound, "type", &spReward->m_nType);
                if (spReward->m_nType == 1)
                {
                    CStringW strValue;
                    FUN_140873420(pRound, "value", strValue);
                    spReward->m_item.vfunc_1(CStringW(strValue));
                }
                else
                {
                    FUN_1408731e0(pRound, "value", spReward->m_nValue);
                    int nSubJob = 0;
                    FUN_1408731e0(pRound, "subJobLevel", nSubJob);
                    if (nSubJob == 0)
                        spReward->m_nSubJob = Unk_SubJobLevel_1;
                    else if (nSubJob == 1)
                        spReward->m_nSubJob = Unk_SubJobLevel_2;
                }
                m_rewards.SetAt(nRound, spReward);
            }
            return 1;
        }
    }
}

// @0x14037c3d0
CFieldMissionTable::RewardPtr CFieldMissionTable::GetReward(int nRound)
{
    RewardPtr spReward(0);
    m_rewards.Lookup(nRound, spReward);
    return spReward;
}

// @0x14037c450
// MS2-FUNCTIONAL: CRBMap iteration/lookup compiles to different inlined glue/reg allocation than the exe; permuter lane
int CFieldMissionTable::GetPrevRound(int nRound)
{
    POSITION pos = m_rewards.GetHeadPosition();
    while (true)
    {
        if (pos == 0)
            return 0;
        if (m_rewards.GetKeyAt(pos) == nRound)
            break;
        m_rewards.GetNext(pos);
    }
    m_rewards.GetPrev(pos);
    if (pos == 0)
        return 0;
    return m_rewards.GetKeyAt(pos);
}

// @0x14037c510
// MS2-FUNCTIONAL: CRBMap iteration/lookup compiles to different inlined glue/reg allocation than the exe; permuter lane
int CFieldMissionTable::GetNextRound(int nRound)
{
    POSITION pos = m_rewards.GetHeadPosition();
    if (nRound == 0 && pos != 0)
        return m_rewards.GetKeyAt(pos);
    pos = m_rewards.GetHeadPosition();
    while (true)
    {
        if (pos == 0)
            return 0;
        if (m_rewards.GetKeyAt(pos) == nRound)
            break;
        m_rewards.GetNext(pos);
    }
    m_rewards.GetNext(pos);
    if (pos == 0)
        return 0;
    return m_rewards.GetKeyAt(pos);
}

// @0x14037c610
// MS2-FUNCTIONAL: CRBMap iteration/lookup compiles to different inlined glue/reg allocation than the exe; permuter lane
int CFieldMissionTable::GetMaxRound()
{
    int nMax = 0;
    POSITION pos = m_rewards.GetHeadPosition();
    while (pos != 0)
    {
        if (nMax < m_rewards.GetKeyAt(pos))
            nMax = m_rewards.GetKeyAt(pos);
        m_rewards.GetNext(pos);
    }
    return nMax;
}

// @0x14037c6a0
// MS2-FUNCTIONAL: CRBMap iteration/lookup compiles to different inlined glue/reg allocation than the exe; permuter lane
void CFieldMissionTable::GetSkillPoints(int nRound, std::map<Unk_SubJobLevel, int>& rOut)
{
    if (nRound != 0)
    {
        POSITION pos = m_rewards.GetHeadPosition();
        while (pos != 0)
        {
            if (m_rewards.GetKeyAt(pos) <= nRound)
            {
                RewardPtr spReward = m_rewards.GetValueAt(pos);
                if (spReward->m_nType == 3)
                {
                    int& rnPoints = rOut[spReward->m_nSubJob];
                    rnPoints += spReward->m_nValue;
                }
            }
            m_rewards.GetNext(pos);
        }
    }
}

// @0x14037c7c0
// MS2-FUNCTIONAL: CRBMap iteration/lookup compiles to different inlined glue/reg allocation than the exe; permuter lane
int CFieldMissionTable::GetStatPoints(int nRound)
{
    int nSum;
    if (nRound == 0)
    {
        nSum = 0;
    }
    else
    {
        nSum = 0;
        POSITION pos = m_rewards.GetHeadPosition();
        while (pos != 0)
        {
            if (m_rewards.GetKeyAt(pos) <= nRound)
            {
                RewardPtr spReward = m_rewards.GetValueAt(pos);
                if (spReward->m_nType == 2)
                    nSum = nSum + spReward->m_nValue;
            }
            m_rewards.GetNext(pos);
        }
    }
    return nSum;
}
