// datatable_impl.h - the body of DataTable<T>::Load (0x141b82a10 for T = WebGuide). NOT an original header.
// Include it in the unit that instantiates the loader. The row type T provides LoadXml(TiXmlElement*).
#pragma once

#include "ms2/placeholder/datatable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/filesystem.h"

class CLogString;
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_14015eb90
CString GetXmlPath(const CString& strDir, const CString& strFile);   // Table/<file>
bool IsElementAvailable(struct Unk_XmlElement* pElem);   // the element is enabled (0x14028f710, commonutil.cpp, the definer's signature)
class Unk_CriticalSectionLock;
class Unk_XmlNode   // C3: member view for the former element stand-ins (shared by the includers)
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

template <class T>
int DataTable<T>::Load(CString strDir, CString strFile, CString strElement)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    CString strPath = GetXmlPath(strDir, strFile);
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild(strElement)); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling(strElement)))
    {
        if (!IsElementAvailable(reinterpret_cast<struct Unk_XmlElement*>(pNode)))
            continue;
        MS2Ptr<T> spRow = Create(pNode);
        if (spRow == 0)
        {
            (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\datatable.h", 0x3b), 0));
            continue;
        }
        spRow->LoadXml(pNode);
        Add(spRow);
    }
    Loaded();
    return 1;
}
