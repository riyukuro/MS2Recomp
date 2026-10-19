// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSmartPushTable: Table/smartPush.xml and
// Table/AutoActionPricePackage.xml.
// MS2-UNIT: ?\smartpushtable.cpp
// MS2-RANGE: 0x1408105e0-0x140815690 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2SvrPtr@VCAutoActionPricePackage@@@@QEAA@H@Z 0x140811e40 ; unique
// MS2-PIN: ??0?$MS2SvrPtr@VCAutoActionPricePackage@@@@QEAA@PEAVCAutoActionPricePackage@@@Z 0x140811e60 ; unique
// MS2-PIN: ??4?$TPtrValue@V?$CAtlArray@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@V?$CElementTraits@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@@ATL@@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x140812980 ; unique
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@V?$CElementTraits@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@@ATL@@@ATL@@QEAAAEAV?$MS2SvrPtr@VCAutoActionPricePackage@@@@_K@Z 0x140813060 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CSmartPushTable@@6B?$TSingleton@VCSmartPushTable@@@@@ 0x142d951f0
// MS2-PIN: ??_7CSmartPushTable@@6B?$CValidData@VCSmartPushTable@@@@@ 0x142d95200
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@V?$CElementTraits@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@@ATL@@@ATL@@@@6B@ 0x142d95220
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@V?$CElementTraits@V?$MS2SvrPtr@VCAutoActionPricePackage@@@@@ATL@@@ATL@@@@6B@ 0x142d95220
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "smartpushtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <typeinfo>

// Unrecovered helpers (same ones the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& rOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& rOut);
int FUN_1408732e0(Unk_140165cf0* pElem, const char* pszName, __int64& rOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& rOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CString& rOut);
bool FUN_14028f710(Unk_140165cf0* pElem);                               // element is enabled
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14016a5c0(const char* psz, int n);
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
int FUN_1407181d0(CString* pStr);                                       // string to int
class Unk_Features { public: bool FUN_14036d710(int nFeature); };
Unk_Features* FUN_140166410();
void FUN_140275080(CString& str, Unk_StrVec* pOut, const char* pszDelim);   // split into a std::vector<CString>
int Parse_140219650(const CStringA& value);

CStringW FormatStringId(int id, const fmt::ArgList& args);              // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols.tsv)
bool CSmartPushTable::s_bInit;
#endif

// @0x140812000
CAutoActionPricePackage::CAutoActionPricePackage()
{
    m_nId = 0;
    m_nDuration = 0;
    m_nMerat = 0;
    m_nMeso = 0;
}

// @0x140812180
CSmartPushData::CSmartPushData()
    : m_nId(0), m_strContent(), m_nActionType(0), m_nActionValue(0), m_nRequireMerat(0), m_requireItem(), m_strImgPath()
{
}

// @0x1408105e0
CSmartPushTable::CSmartPushTable() : m_data(17, 0.75f, 0.25f, 2.25f, 10), m_packages(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1408106c0
CSmartPushTable::~CSmartPushTable()
{
}

// tinyxmlhelper.h: an enum attribute converted from its string form.
// @0x140811a50
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
inline int FUN_140811a50(Unk_140165cf0* pNode, const char* pszName, int* pOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = FUN_1408733e0(pNode, pszName, str);
    if (nRead != 0)
        return nRead;
    *pOut = Parse_140219650(str);
    return nRead;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE ""

// @0x140810730
void CSmartPushTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "smartPush.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("push"); pNode != 0;
         pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("push")))
    {
        if (!FUN_14028f710(pNode))
            continue;
        DataPtr spData(new CSmartPushData);
        FUN_1408731e0(pNode, "id", spData->m_nId);
        FUN_140873420(pNode, "content", spData->m_strContent);
        FUN_140811a50(pNode, "actionType", &spData->m_nActionType);
        FUN_140873220(pNode, "actionValue", spData->m_nActionValue);
        FUN_1408732e0(pNode, "requireMerat", spData->m_nRequireMerat);
        FUN_140873420(pNode, "imgPath", spData->m_strImgPath);
        CString strItem;
        FUN_1408733e0(pNode, "requireItem", strItem);
        if (strItem.GetLength() != 0)
        {
            Unk_StrVec parts;
            FUN_140275080(strItem, &parts, ",");
            if (parts.FUN_14028b4c0() != 3)
                continue;
            Unk_StrVec idTag;
            FUN_140275080(*parts.FUN_14027f1c0(0), &idTag, ":");
            if (idTag.FUN_14028b4c0() != 0)
                spData->m_requireItem.m_a = FUN_1407181d0(idTag.FUN_14027f1c0(0));
            if (idTag.FUN_14028b4c0() > 1)
                spData->m_requireItem.m_b = FUN_140557640(FUN_140281980(), idTag.FUN_14027f1c0(1));
            spData->m_requireItem.m_c = FUN_1407181d0(parts.FUN_14027f1c0(2));
        }
        m_data.SetAt(spData->m_nId, spData);
    }
    LoadPackages();
    SetInit(true);
}

// @0x140810d30
void CSmartPushTable::LoadPackages()
{
    CString strPath = FUN_14071a5b0("Table", "AutoActionPricePackage.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("package"); pNode != 0;
         pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("package")))
    {
        PackagePtr spPkg(new CAutoActionPricePackage);
        FUN_140873420(pNode, "content", spPkg->m_strContent);
        FUN_140873220(pNode, "id", spPkg->m_nId);
        FUN_140873220(pNode, "duration", spPkg->m_nDuration);
        FUN_1408732e0(pNode, "merat", spPkg->m_nMerat);
        FUN_1408732e0(pNode, "meso", spPkg->m_nMeso);
        PackageArrayPtr spList(0);
        if (!m_packages.Lookup(spPkg->m_strContent, spList))
        {
            spList = Unk_GrNewTag(0);
            spList->InsertAt(spPkg->m_nId, spPkg, 1);
            m_packages.SetAt(spPkg->m_strContent, spList);
        }
        else
        {
            spList->InsertAt(spPkg->m_nId, spPkg, 1);
        }
    }
}

// @0x140810c20
void CSmartPushTable::GetAll(ATL::CAtlArray<DataPtr>& rOut)
{
    CheckInit();
    for (POSITION pos = m_data.GetStartPosition(); pos != 0; m_data.GetNext(pos))
        rOut.Add(m_data.GetValueAt(pos));
}

// @0x140810ca0
CSmartPushTable::DataPtr CSmartPushTable::GetData(int nId)
{
    CheckInit();
    DataPtr p(0);
    m_data.Lookup(nId, p);
    return p;
}

// @0x140811110
CSmartPushTable::PackagePtr CSmartPushTable::GetPackage(const CStringW& strName, unsigned n)
{
    PackageArrayPtr spList(0);
    m_packages.Lookup(strName, spList);
    if (spList == 0)
        return PackagePtr(0);
    if (spList->GetCount() <= n)
        return PackagePtr(0);
    return spList->GetAt(n);
}

// @0x140811240
__int64 CSmartPushTable::GetPackageMerat(const CStringW& strName, unsigned n)
{
    PackagePtr sp = GetPackage(strName, n);
    if (sp == 0)
        return 0;
    return sp->m_nMerat;
}

// @0x1408112d0
int CSmartPushTable::GetPackageDuration(const CStringW& strName, unsigned n)
{
    PackagePtr sp = GetPackage(strName, n);
    if (sp == 0)
        return 0;
    return sp->m_nDuration * 60 * 1000;
}

// @0x140811370
CStringW CSmartPushTable::GetPackageDurationText(const CStringW& strName, unsigned n)
{
    CStringW strText;
    PackagePtr sp = GetPackage(strName, n);
    if (sp == 0)
        return strText;
    int nMinutes = sp->m_nDuration;
    int nHours = nMinutes / 60;
    int nMin = nMinutes % 60;
    if (nHours == 0 || nMin == 0)
    {
        if (nHours == 0)
        {
            if (nMin != 0)
                strText = FormatStringId(0x97c, nMin);
        }
        else
        {
            strText = FormatStringId(0x97d, nHours);
        }
    }
    else
    {
        strText = FormatStringId(0x97f, nHours, nMin);
    }
    return strText;
}

// @0x1408115a0
unsigned CSmartPushTable::GetPackageCount(const CStringW& strName)
{
    PackageArrayPtr spList(0);
    m_packages.Lookup(strName, spList);
    if (spList == 0)
        return 0;
    return (unsigned)spList->GetCount();
}

// @0x140811640
bool FUN_140811640(int n)
{
    if (!FUN_140166410()->FUN_14036d710(0x10c))
        return false;
    switch (n)
    {
    case 1: case 2: case 3: case 4:
        return true;
    case 5: case 6: case 7: case 8:
        return false;
    default:
        return false;
    }
}

// @0x140812a90
void CSmartPushTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CSmartPushTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140815130
void CSmartPushTable::SetInit(bool b)
{
    s_bInit = b;
}
