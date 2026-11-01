// datatable_impl.h - the body of DataTable<T>::Load (0x141b82a10 for T = WebGuide). NOT an original header.
// Include it in the unit that instantiates the loader. The row type T provides LoadXml(Unk_140165cf0*).
#pragma once

#include "ms2/placeholder/datatable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_14015eb90
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
class Unk_CriticalSectionLock;
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins (shared by the includers)
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

template <class T>
int DataTable<T>::Load(CString strDir, CString strFile, CString strElement)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    CString strPath = FUN_14071a5b0(strDir, strFile);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = ((class Unk_140165cf0*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild(strElement)); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling(strElement)))
    {
        if (!FUN_14028f710(pNode))
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
