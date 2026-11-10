// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSmartPushTable: Table/smartPush.xml and
// Table/AutoActionPricePackage.xml.
// MS2-UNIT: ?\smartpushtable.cpp
// MS2-RANGE: 0x1408105e0-0x140815690 .text$mn
// MS2-PINS-BEGIN tplpin
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
#include "ms2/placeholder/formatstringid.h"   // C3: FUN_14028dee0 by its real name (was FormatStringId(int, const ArgList&))
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/filesystem.h"
#include <typeinfo>
#include "ms2/commonfiles/itemdatatable.h"   // C3: CItemDataTable::GetTagByName was FUN_140557640
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420

// Unrecovered helpers (same ones the other table units use).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
// C3 #8: the cast-only Unk_140168650 view removed
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int FUN_140873420(TiXmlElement* pElem, const char* pszName, CStringW& rOut);

bool IsElementAvailable(struct Unk_XmlElement*);   // C3: was IsElementAvailable
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class Unk_140166420 : public CFileSystem { };
CString ToCString(const char* psz, int n);
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_14015eb90
unsigned int ParseUInt(const CString& str);                                       // string to int
class Unk_140166410* FUN_140166410();   // the CFeatureManager instance (0x140166410, the definer's signature)
void FUN_140275080(CString& str, void* pOut, const char* pszDelim);   // C3: the exe's void* signature (was Unk_StrVec*)   // split into a std::vector<CString>
int Parse_140219650(const CStringA& value);


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
inline int FUN_140811a50(TiXmlElement* pNode, const char* pszName, int* pOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = XmlGetAttr((class TiXmlElement*)(pNode), pszName, str);
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
    CString strPath = GetXmlPath("Table", "smartPush.xml");
    TiXmlDocument doc;
    if (((class Unk_140166420*)GetFileSystem())->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("push")); pNode != 0;
         pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("push")))
    {
        if (!IsElementAvailable((struct Unk_XmlElement*)(pNode)))
            continue;
        DataPtr spData(new CSmartPushData);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", spData->m_nId);
        XmlGetAttr((class TiXmlElement*)(pNode), "content", spData->m_strContent);
        FUN_140811a50(pNode, "actionType", &spData->m_nActionType);
        XmlGetAttr((class TiXmlElement*)(pNode), "actionValue", spData->m_nActionValue);
        XmlGetAttr((class TiXmlElement*)(pNode), "requireMerat", spData->m_nRequireMerat);
        XmlGetAttr((class TiXmlElement*)(pNode), "imgPath", spData->m_strImgPath);
        CString strItem;
        XmlGetAttr((class TiXmlElement*)(pNode), "requireItem", strItem);
        if (strItem.GetLength() != 0)
        {
            std::vector<CString> parts;   // C3: was Unk_StrVec
            FUN_140275080(strItem, &parts, ",");
            if (parts.size() != 3)
                continue;
            std::vector<CString> idTag;   // C3: was Unk_StrVec
            FUN_140275080(parts[0], &idTag, ":");
            if (idTag.size() > 0)
                spData->m_requireItem.m_a = ParseUInt(idTag[0]);
            if (idTag.size() > 1)
                spData->m_requireItem.m_b = TSingleton<CItemDataTable>::GetInstance()->GetTagByName(idTag[1]);
            spData->m_requireItem.m_c = ParseUInt(parts[2]);
        }
        m_data.SetAt(spData->m_nId, spData);
    }
    LoadPackages();
    SetInit(true);
}

// @0x140810d30
void CSmartPushTable::LoadPackages()
{
    CString strPath = GetXmlPath("Table", "AutoActionPricePackage.xml");
    TiXmlDocument doc;
    if (((class Unk_140166420*)GetFileSystem())->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("package")); pNode != 0;
         pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("package")))
    {
        PackagePtr spPkg(new CAutoActionPricePackage);
        XmlGetAttr((class TiXmlElement*)(pNode), "content", spPkg->m_strContent);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", spPkg->m_nId);
        XmlGetAttr((class TiXmlElement*)(pNode), "duration", spPkg->m_nDuration);
        XmlGetAttr((class TiXmlElement*)(pNode), "merat", spPkg->m_nMerat);
        XmlGetAttr((class TiXmlElement*)(pNode), "meso", spPkg->m_nMeso);
        PackageArrayPtr spList(0);
        if (m_packages.Lookup(spPkg->m_strContent, spList))
        {
            spList->InsertAt(spPkg->m_nId, spPkg, 1);
        }
        else
        {
            spList = Unk_GrNewTag(0);
            spList->InsertAt(spPkg->m_nId, spPkg, 1);
            m_packages.SetAt(spPkg->m_strContent, spList);
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
    return const_cast<const PackageArray&>(*spList.get()).GetAt(n);
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
    int nMin;
    int nHours = nMinutes / 60;
    nMin = nMinutes % 60;
    if (nHours != 0 && nMin != 0)
        strText = FormatStringId(0x97f, nHours, nMin);
    else if (nHours != 0)
        strText = FormatStringId(0x97d, nHours);
    else if (nMin != 0)
        strText = FormatStringId(0x97c, nMin);
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
bool IsFirstUseRedMerat(int n)
{
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d710(0x10c))
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
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(CSmartPushTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140815130
void CSmartPushTable::SetInit(bool b)
{
    s_bInit = b;
}
