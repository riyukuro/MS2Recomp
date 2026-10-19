// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CChangeJobTable: Table/changeJob.xml, plus the template glue of
// its CAtlMap (subjob code -> boxed row pointer).
// MS2-UNIT: ?\changejobtable.cpp
// MS2-RANGE: 0x1401d64a0-0x1401d8bc0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\changejobtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "changejobtable.h"
#include "jobtable.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit callees.
class Unk_140166410 { public: bool FUN_14036d570(int nFeature); bool FUN_14036d4b0(const CStringW& strFeature); };   // the content switches
Unk_140166410* FUN_140166410();
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
CStringTable* FUN_1401a9d70();                          // the string table singleton
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& rOut);

// Common::Constants::Value<T>::Get, header-inline in the original (the Value<unsigned> instance 0x1401d7c10 is in this unit's
// COMDAT tail).
template<class T> T* Common::Constants::Value<T>::Get()
{
    if (!m_defined)
        Error("constants is not set");
    return &m_value;
}

// @0x1401d64a0
CChangeJobTable::CChangeJobTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1401d6510
CChangeJobTable::~CChangeJobTable()
{
}

// @0x1401d72f0
ChangeJobData::ChangeJobData()
    : m_nSubJobCode(Unk_SubJobCode_None), m_nChangeSubJobCode(0), m_bValid(true)
{
    m_nEndQuestId = 0;
    m_nStartQuestId = 0;
}

// @0x1401d74b0
ChangeJobData::~ChangeJobData()
{
}

// @0x1401d6550
// MS2-FUNCTIONAL: the skill id Add() calls pass the by-value argument through ecx (mov ecx,[n]; mov edx,ecx); no source form found
void CChangeJobTable::Load()
{
    if (!FUN_140166410()->FUN_14036d570(0xca))
        return;
    CString strPath = FUN_14071a5b0("Table", "changeJob.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("subjob"); pNode != 0; pNode = pNode->FUN_140168650("subjob"))
    {
        CStringW strFeature;
        FUN_140873420(pNode, "feature", strFeature);
        if (!FUN_140166410()->FUN_14036d4b0(strFeature))
            continue;
        DataPtr spData(Unk_SocketNew(0));
        int nValue = 0;
        FUN_1408731e0(pNode, "subJobCode", nValue);
        spData->m_nSubJobCode = static_cast<Unk_SubJobCode>(nValue);
        FUN_1408731e0(pNode, "changeSubJobCode", nValue);
        spData->m_nChangeSubJobCode = nValue;
        FUN_1408731e0(pNode, "startquestid", nValue);
        spData->m_nStartQuestId = nValue;
        FUN_1408731e0(pNode, "endquestid", nValue);
        spData->m_nEndQuestId = nValue;
        spData->m_strJobName = FUN_1401a9d70()->FUN_141811980(6, spData->m_nChangeSubJobCode);
        FUN_140873ad0(pNode, "movie", spData->m_strMovie);
        int nStringId = 0;
        FUN_1408731e0(pNode, "desc", nStringId);
        spData->m_strDesc = FUN_1401a9d70()->FUN_141811980(0x4f, nStringId);
        FUN_1408731e0(pNode, "skilldesc1", nStringId);
        spData->m_strSkillDesc1 = FUN_1401a9d70()->FUN_141811980(0x4f, nStringId);
        FUN_1408731e0(pNode, "skilldesc2", nStringId);
        spData->m_strSkillDesc2 = FUN_1401a9d70()->FUN_141811980(0x4f, nStringId);
        ATL::CAtlArray<CString> tokens1;
        CString strSkills1;
        FUN_1408733e0(pNode, "skillID1", strSkills1);
        FUN_14015f050(strSkills1, tokens1, ",");
        for (size_t i = 0; i < tokens1.GetCount(); i++)
        {
            int nSkillId = atoi(tokens1[i]);
            spData->m_skills1.Add(nSkillId);
        }
        ATL::CAtlArray<CString> tokens2;
        CString strSkills2;
        FUN_1408733e0(pNode, "skillID2", strSkills2);
        FUN_14015f050(strSkills2, tokens2, ",");
        for (size_t i = 0; i < tokens2.GetCount(); i++)
        {
            int nSkillId = atoi(tokens2[i]);
            spData->m_skills2.Add(nSkillId);
        }
        m_map.SetAt(spData->m_nSubJobCode, spData);
    }
}

// @0x1401d6c30
CChangeJobTable::DataPtr CChangeJobTable::Get(Unk_SubJobCode nSubJobCode)
{
    DataPtr spData(0);
    if (m_map.Lookup(nSubJobCode, spData))
        return spData;
    return DataPtr(0);
}

// @0x1401d6ce0
int CChangeJobTable::CanChange(int nJobGroup, Unk_SubJobCode nJobCode, unsigned short nLevel)
{
    if (nLevel < *FUN_1401d3200()->ChangeJobLevel.Get())
        return 0;
    if (JobTable::GetInstance()->GetSubJob1(nJobGroup) != nJobCode)
        return 0;
    if (m_map.Lookup(nJobCode) != 0)
        return 1;
    return 0;
}

// @0x1401d6d70
int CChangeJobTable::GetStartQuestId(Unk_SubJobCode nSubJobCode)
{
    DataPtr spData = Get(nSubJobCode);
    if (spData.get() != 0)
        return spData->m_nStartQuestId;
    return 0;
}

// @0x1401d6df0
int CChangeJobTable::GetEndQuestId(Unk_SubJobCode nSubJobCode)
{
    DataPtr spData = Get(nSubJobCode);
    if (spData.get() != 0)
        return spData->m_nEndQuestId;
    return 0;
}

// @0x1401d6e70
int CChangeJobTable::GetChangeSubJobCode(Unk_SubJobCode nSubJobCode)
{
    DataPtr spData = Get(nSubJobCode);
    if (spData.get() != 0)
        return spData->m_nChangeSubJobCode;
    return 0;
}

// @0x1401d6ef0
int CChangeJobTable::IsChangeTarget(int nJobCode)
{
    for (POSITION pos = m_map.GetStartPosition(); pos != 0; m_map.GetNext(pos))
    {
        DataPtr spData(m_map.GetValueAt(pos));
        if (spData.get() != 0 && spData->m_nChangeSubJobCode == nJobCode)
            return 1;
    }
    return 0;
}

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h) closes the CAtlMap instantiations.
#pragma function(memmove)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x1401d8aa0
errno_t FUN_1401d8aa0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
