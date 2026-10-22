// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CExpTable: the level / experience tables
// (nextExp.xml, ExpBaseTable.xml, RewardContentExpStaticTable.xml, commonExpTable.xml, petExp.xml, petEvolution.xml).
// MS2-UNIT: ?\exptable.cpp
// MS2-RANGE: 0x140352350-0x1403588d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Emplace_back@AEB_J@?$_Uninitialized_backout_al@PEA_JV?$allocator@_J@std@@@std@@QEAAXAEB_J@Z 0x140354360 ; unique
// MS2-PIN: ??$_Resize@V<lambda_aaf1f722a389aa487a4258a299f87243>@@@?$vector@_JV?$allocator@_J@std@@@std@@AEAAX_KV<lambda_aaf1f722a389aa487a4258a299f87243>@@@Z 0x140355950 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEA_JPEA_JV?$allocator@_J@std@@@std@@YAPEA_JQEA_J0PEA_JAEAV?$allocator@_J@0@@Z 0x140355e40 ; unique
// MS2-PIN: ??$construct@_JAEB_J@?$_Default_allocator_traits@V?$allocator@_J@std@@@std@@SAXAEAV?$allocator@_J@1@QEA_JAEB_J@Z 0x140356060 ; unique
// MS2-PIN: ??$forward@AEB_J@std@@YAAEB_JAEB_J@Z 0x1403561b0 ; prop
// MS2-PIN: ??0?$vector@_JV?$allocator@_J@std@@@std@@QEAA@XZ 0x140356530 ; unique
// MS2-PIN: ??A?$vector@_JV?$allocator@_J@std@@@std@@QEBAAEB_J_K@Z 0x140356840 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@_JV?$allocator@_J@std@@@std@@AEBA_K_K@Z 0x140356f40 ; unique
// MS2-PIN: ?_Change_array@?$vector@_JV?$allocator@_J@std@@@std@@AEAAXQEA_J_K1@Z 0x140356fd0 ; unique
// MS2-PIN: ?_Destroy@?$vector@_JV?$allocator@_J@std@@@std@@AEAAXPEA_J0@Z 0x140357150 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@_J@std@@@2@XZ 0x140357910 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ExpCurve@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ExpCurve@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x140357930 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ExpCurve@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ExpCurve@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140357940 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@_J@std@@V?$_Vector_val@U?$_Simple_types@_J@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@_J@std@@@2@XZ 0x1403579d0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBQEA_JXZ 0x140357c90 ; unique
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEBAAEBQEA_JXZ 0x140357d10 ; unique
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@_JV?$allocator@_J@std@@@std@@@std@@QEAAXXZ 0x140357d30 ; unique
// MS2-PIN: ?_Tidy@?$vector@_JV?$allocator@_J@std@@@std@@AEAAXXZ 0x140357f00 ; unique
// MS2-PIN: ?capacity@?$vector@_JV?$allocator@_J@std@@@std@@QEBA_KXZ 0x1403581a0 ; prop
// MS2-PIN: ?clear@?$vector@_JV?$allocator@_J@std@@@std@@QEAAXXZ 0x140358280 ; unique
// MS2-PIN: ?deallocate@?$allocator@_J@std@@QEAAXQEA_J_K@Z 0x140358360 ; unique
// MS2-PIN: ?empty@?$vector@_JV?$allocator@_J@std@@@std@@QEBA_NXZ 0x140358390 ; unique
// MS2-PIN: ?size@?$vector@_JV?$allocator@_J@std@@@std@@QEBA_KXZ 0x140358770 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7CExpTable@@6B?$TSingleton@VCExpTable@@@@@ 0x142d2a570
// MS2-PIN: ??_7CExpTable@@6B?$CValidData@VCExpTable@@@@@ 0x142d2a580
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\exptable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "exptable.h"
#include "filesystem.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>

class Unk_140165cf0                         // game TinyXML element
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);          // the first child with the name
    Unk_140165cf0* FUN_140168650(const char* pszName);          // the next sibling with the name
};

// Unrecovered helpers.
CString FUN_14016a5c0(const char* psz, int nCodePage);          // narrows a string (the RTTI name in CheckInit)
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
void FUN_140177a80(CLogString* log, int level, int category, const wchar_t* format, const int& arg);
bool FUN_14028f710(Unk_140165cf0* pElem);                                   // the node is an element
int FUN_14086f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1408732e0(Unk_140165cf0* pElem, const char* pszName, __int64* pOut);
int FUN_1408733a0(Unk_140165cf0* pElem, const char* pszName, double* pOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CStringA* pOut);
int FUN_14021af40(CStringA* pStr);                                          // the string as a number
void FUN_14015f710(CStringA* pOut, Unk_140165cf0* pElem, const char* pszName, CStringA strDefault);
unsigned short FUN_140197350(Unk_140165cf0* pElem, const char* pszName, unsigned short nDefault);
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault);
class Unk_1401c0db0 { public: __int64 FUN_140678cd0(__int64 nValue, unsigned short nArg); };
Unk_1401c0db0* FUN_1401c0db0();

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CExpTable::s_bInit;
#endif

// The unit's one-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
// @0x140353fc0
template <class T>
inline void Unk_ExpLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// @0x140354050
int Unk_ExpGetInt(Unk_140165cf0* pElem, const char* pszName, int* pOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CStringA str;
    int nRet = FUN_1408733e0(pElem, pszName, &str);
    if (nRet != 0)
        return nRet;
    *pOut = FUN_14021af40(&str);
    return nRet;
}

// @0x140354110
double Unk_ExpGetDouble(Unk_140165cf0* pElem, const char* pszName, double fDefault)
{
    double fValue;
    if (FUN_1408733a0(pElem, pszName, &fValue) != 0)
        return fDefault;
    return fValue;
}

// @0x140354150
__int64 Unk_ExpGetInt64(Unk_140165cf0* pElem, const char* pszName, __int64 nDefault)
{
    __int64 nValue;
    if (FUN_1408732e0(pElem, pszName, &nValue) != 0)
        return nDefault;
    return nValue;
}

// @0x140352350
Unk_ExpCurve::Unk_ExpCurve()
    : m_nBase(0)
{
}

// @0x140352390
void Unk_ExpCurve::SetValue(unsigned short nLevel, __int64 nValue)
{
    if (nLevel > 99)
        return;
    if (nLevel == 0)
        m_nBase = nValue;
    else
    {
        if (m_values.empty())
            m_values.resize(99, 0);
        m_values[nLevel - 1] = nValue;
    }
}

// @0x140352430
__int64 Unk_ExpCurve::GetValue(unsigned short nLevel) const
{
    if (m_values.empty())
        return m_nBase;
    if (nLevel <= 0 || nLevel > m_values.size())
        return 0;
    return const_cast<std::vector<__int64>&>(m_values)[nLevel - 1];
}

// @0x1403524b0
void Unk_ExpCurve::Scale(const Unk_ExpCurve& src, double fFactor)
{
    m_values.clear();
    m_values.resize(src.m_values.size(), 0);
    for (size_t i = 0; i < m_values.size(); ++i)
    {
        __int64 nMin = 1;
        __int64 nValue = (__int64)((double)src.m_values[i] * fFactor + 0.5);
        m_values[i] = (std::max)(nValue, nMin);
    }
}

// @0x1403525a0
bool Unk_ExpCurve::IsValid() const
{
    if (m_nBase != 0)
        return true;
    if (m_values.size() > 0)
        return true;
    return false;
}

// @0x1403525e0
CExpTable::CExpTable()
    : m_petEvolution(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1403526f0
CExpTable::~CExpTable()
{
}

// @0x140356ca0
void CExpTable::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CExpTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1403527a0
bool CExpTable::Load()
{
    if (!LoadNextExp())
        return false;
    if (!Reserved())
        return false;
    if (!LoadReward())
        return false;
    if (!LoadCommonExp())
        return false;
    if (!LoadPetExp())
        return false;
    if (!LoadPetEvolution())
        return false;
    SetInit(true);
    return true;
}

// @0x140352ab0
bool CExpTable::Reserved()
{
    return true;
}

#define MS2_EXP_XML_ERR L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]"

// @0x140352840
bool CExpTable::LoadNextExp()
{
    for (int i = 0; i < 99; ++i)
        m_nextExp[i] = 0x7fffffffffffffffLL;
    CString strPath = FUN_14071a5b0("Table", "nextExp.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, MS2_EXP_XML_ERR, strPath);
        return false;
    }
    for (Unk_140165cf0* pExp = pRoot->FUN_140165cf0("exp"); pExp != 0; pExp = pExp->FUN_140168650("exp"))
    {
        if (!FUN_14028f710(pExp))
            continue;
        int nLevel = 0;
        FUN_14086f500(pExp, "level", &nLevel);
        if (nLevel < 1 || nLevel > 99)
            continue;
        __int64 nValue = Unk_ExpGetInt64(pExp, "value", 0);
        m_nextExp[nLevel] = nValue;
    }
    return true;
}

// @0x140352ac0
bool CExpTable::LoadReward()
{
    if (!ReadExpTable("ExpBaseTable.xml"))
        return false;
    if (!ReadExpTable("RewardContentExpStaticTable.xml"))
        return false;
    return true;
}

// @0x140352ba0
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CExpTable::LoadCommonExp()
{
    CString strPath = FUN_14071a5b0("Table", "commonExpTable.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, MS2_EXP_XML_ERR, strPath);
        return false;
    }
    for (Unk_140165cf0* pExp = pRoot->FUN_140165cf0("exp"); pExp != 0; pExp = pExp->FUN_140168650("exp"))
    {
        if (!FUN_14028f710(pExp))
            continue;
        int nTableId = 0;
        int nType = -1;
        Unk_ExpGetInt(pExp, "expType", &nType);
        double fFactor = Unk_ExpGetDouble(pExp, "factor", 0);
        FUN_140873220(pExp, "expTableID", &nTableId);
        CStringA strTableType;
        FUN_14015f710(&strTableType, pExp, "tableType", "");
        if (nType != -1 && nTableId != 0)
            m_typeCurves[nType].Scale(m_curves[nTableId], fFactor);
    }
    return true;
}

// @0x140352e90
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CExpTable::LoadPetExp()
{
    CString strPath = FUN_14071a5b0("Table", "petExp.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, MS2_EXP_XML_ERR, strPath);
        return false;
    }
    static const char* const s_pszGrades[6] = {"normal", "rare", "elite", "excellent", "legendary", "artifact"};
    for (Unk_140165cf0* pExp = pRoot->FUN_140165cf0("exp"); pExp != 0; pExp = pExp->FUN_140168650("exp"))
    {
        if (!FUN_14028f710(pExp))
            continue;
        int nLevel = 0;
        FUN_14086f500(pExp, "level", &nLevel);
        if (nLevel < 1 || nLevel > 99)
            continue;
        for (int i = 0; i < 6; ++i)
        {
            if (FUN_1408732e0(pExp, s_pszGrades[i], &m_petExp[1 + i][nLevel]) != 0)
                Unk_ExpLog(CLogString::GetInstance(), 1, 0x13, L"[Isn't normal EXP level : {0}]", nLevel);
        }
    }
    return true;
}

// @0x1403532d0
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CExpTable::LoadPetEvolution()
{
    m_petEvolution.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "petEvolution.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, MS2_EXP_XML_ERR, strPath);
        return false;
    }
    for (Unk_140165cf0* pEvo = pRoot->FUN_140165cf0("petEvolution"); pEvo != 0; pEvo = pEvo->FUN_140168650("petEvolution"))
    {
        if (FUN_14028f710(pEvo))
        {
            unsigned short nItemLevel = FUN_140197350(pEvo, "requireItemLevel", 0);
            Unk_BmBoxPtr<Unk_PetGradeArray> spGrades((Unk_BmNewTag(0)));
            spGrades->Add(0);
            unsigned nGrade1 = FUN_140197390(pEvo, "Grade1", 0);
            spGrades->Add(nGrade1);
            unsigned nGrade2 = FUN_140197390(pEvo, "Grade2", 0);
            spGrades->Add(nGrade2);
            unsigned nGrade3 = FUN_140197390(pEvo, "Grade3", 0);
            spGrades->Add(nGrade3);
            unsigned nGrade4 = FUN_140197390(pEvo, "Grade4", 0);
            spGrades->Add(nGrade4);
            spGrades->Add(0);
            m_petEvolution.SetAt(nItemLevel, spGrades);
        }
    }
    return true;
}

// @0x140353ae0
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CExpTable::ReadExpTable(const CString& strFile)
{
    CString strPath = FUN_14071a5b0("Table", strFile);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[file: {0}]", strPath);
        return false;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, MS2_EXP_XML_ERR, strPath);
        return false;
    }
    for (Unk_140165cf0* pTable = pRoot->FUN_140165cf0("table"); pTable != 0; pTable = pTable->FUN_140168650("table"))
    {
        int nTableId = 0;
        FUN_140873220(pTable, "expTableID", &nTableId);
        if (nTableId != 0)
        {
            Unk_ExpCurve& curve = m_curves[nTableId];
            if (!curve.IsValid())
            {
                for (Unk_140165cf0* pBase = pTable->FUN_140165cf0("base"); pBase != 0; pBase = pBase->FUN_140168650("base"))
                {
                    if (FUN_14028f710(pBase))
                    {
                        int nLevel = FUN_140197350(pBase, "level", 0);
                        __int64 nExp = Unk_ExpGetInt64(pBase, "exp", 0);
                        curve.SetValue((unsigned short)nLevel, nExp);
                    }
                }
            }
            else
                FUN_140177a80(CLogString::GetInstance(), 1, 0x13, L"CExpTable::ReadExpTable DuplicateID:{0}", nTableId);
        }
    }
    return true;
}

// @0x140353610
__int64 CExpTable::GetNextExp(unsigned short nLevel)
{
    CheckInit();
    if (nLevel < 1 || nLevel > 99)
        return 0x7fffffffffffffffLL;
    return m_nextExp[nLevel];
}

// @0x140353660
__int64 CExpTable::GetBaseValue(unsigned short nLevel, int nType)
{
    CheckInit();
    if (nLevel < 1 || nLevel > 99)
        return 0;
    const Unk_ExpBase& base = m_base[nLevel];
    if (nType == 1)
        return base.m_n1;
    else if (nType == 3)
        return base.m_n3;
    else if (nType == 7)
        return base.m_n7;
    else if (nType == 4)
        return base.m_n4;
    else if (nType == 6)
        return base.m_n6;
    return 0;
}

// @0x140353720
__int64 CExpTable::GetTypeValue(unsigned short nLevel, int nType)
{
    CheckInit();
    if (nType < 0 || nType >= 0x30)
        return 0;
    if (nType == 8)
        return GetBaseValue(nLevel, 6);
    return m_typeCurves[nType].GetValue(nLevel);
}

// @0x1403537a0
__int64 CExpTable::GetScaledValue(unsigned short nLevel, int nId, double fFactor)
{
    if (nId == 0)
        return 0;
    Unk_ExpCurve& curve = m_curves[reinterpret_cast<const unsigned&>(nId)];
    __int64 nValue = (__int64)((double)curve.GetValue(nLevel) * fFactor + 0.5);
    __int64 nMin = 1;
    return (std::max)(nValue, nMin);
}

// @0x140353840
__int64 CExpTable::GetPetValue(unsigned short nLevel, int nGrade)
{
    CheckInit();
    if (nGrade == 1)
        return m_typeCurves[9].GetValue(nLevel);
    else if (nGrade == 2)
        return m_typeCurves[10].GetValue(nLevel);
    else if (nGrade == 3)
        return m_typeCurves[11].GetValue(nLevel);
    else if (nGrade == 4)
        return m_typeCurves[12].GetValue(nLevel);
    return 0;
}

// @0x140353930
__int64 CExpTable::GetPetExp(unsigned short nLevel, int nRow, unsigned short nArg)
{
    if (nRow >= 7)
        return 0x7fffffffffffffffLL;
    if (nLevel > 0x32)
        return 0x7fffffffffffffffLL;
    return FUN_1401c0db0()->FUN_140678cd0(m_petExp[nRow][nLevel], nArg);
}

// @0x1403539d0
int CExpTable::GetPetEvolution(unsigned short nId, int nGrade)
{
    if (m_petEvolution.Lookup(nId) == 0)
        return 0;
    Unk_BmBoxPtr<Unk_PetGradeArray> spGrades(0);
    m_petEvolution.Lookup(nId, spGrades);
    if (!spGrades)
        return 0;
    if (spGrades->GetCount() <= (size_t)nGrade)
        return 0;
    return spGrades->GetAt(nGrade);
}
