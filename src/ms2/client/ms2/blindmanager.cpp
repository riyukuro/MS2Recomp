// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). BlindManager: the per-type block lists of the merat market /
// chat, persisted in <user dir>\BlindList.xml. See blindmanager.h.
// MS2-UNIT: ?\blindmanager.cpp
// MS2-RANGE: 0x140a24e90-0x140a2a0a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\blindmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/blindmanager.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include <string.h>
#include <time.h>
#include <string>
#include <limits>
#include "hook/ms2hook.h"
// The game's TinyXML node classes. Its TiXmlDocument is renamed here: filesystem.h brings the placeholder
// document (tixmldocument.h), which this unit uses for the file itself.
#define TiXmlDocument TiXmlDocument_TinyXml
#include "ms2/commonfiles/tinyxml.h"
#include "ms2/ms2format.h"
#undef TiXmlDocument
#include "ms2/placeholder/xmlattr.h"   // C3 #12: after tinyxml.h, so its reduced TiXml view steps aside
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers.
CString FUN_141275640();                                                // the user data directory
CString FUN_140cc2a00(const CString& strDir, const CString& strFile);   // dir + "\\" + file
CString FUN_1409a2360(const char* psz, int n);                          // text conversion
CString FUN_14016a5c0(const char* psz, int n);                          // path conversion
int FUN_140197350(TiXmlElement* pElem, const char* pszName, int nDefault);
CStringW FUN_1401bf530(TiXmlElement* pElem, const char* pszName, CStringW strDefault);
__int64 Unk_ExpGetInt64(TiXmlElement* pElem, const char* pszName, __int64 nDefault); // _time64 attribute
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, CStringW const&);   // C3: was FUN_1408740a0
void XmlSetAttr(class TiXmlElement*, char const*, __int64 const&);   // C3: was FUN_140873eb0
__int64 GetServerTime();                                                // the server time
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410


// @0x140a24e90
BlindManager::BlindManager()
{
    CreateLists();
}

// @0x140a24ef0
BlindManager::~BlindManager()
{
    ClearLists();
}

// @0x140a24f50
void BlindManager::ClearLists()
{
    for (int nIndex = 0; nIndex < 6; nIndex++)
    {
        delete m_lists[nIndex];
    }
    m_lists.clear();
}

// @0x140a24ff0
void BlindManager::CreateLists()
{
    m_lists.resize(6);
    for (int nIndex = 0; nIndex < 6; nIndex++)
    {
        m_lists[nIndex] = new BlindList;
    }
}

// @0x140a250a0
void BlindManager::Load()
{
    ClearLists();
    CreateLists();
    CString strPath = FUN_140cc2a00(FUN_141275640(), "BlindList.xml");
    if (GetFileSystem()->FUN_1403987d0(std::string((const char*)strPath)) == 0)
        return;
    TiXmlDocument document;
    if (GetFileSystem()->FUN_1403974b0(&document, strPath, 0, true, false) == 0)
        return;
    Unk_XmlNode* pRoot = reinterpret_cast<Unk_XmlNode*>(&document)->FirstChild("ms2");
    for (TiXmlElement* pNode = ((class TiXmlElement*)(pRoot->FirstChild("blind"))); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("blind")))
    {
        int nType = FUN_140197350(pNode, "type", 0);
        CStringW strTarget = FUN_1401bf530(pNode, "target", CStringW(L""));
        __int64 nExpire = Unk_ExpGetInt64(pNode, "time", 0);
        if (nType < 0 || nType >= 6)
            continue;
        __time64_t nNow;
        _time64(&nNow);
        if (nNow > nExpire)
            continue;
        BlindList* pList = m_lists[nType];
        if (pList == 0)
            continue;
        BlindEntry entry;
        entry.m_name = strTarget;
        entry.m_expire = nExpire;
        (*pList)[strTarget] = entry;
    }
}

// @0x140a25400
void BlindManager::Save()
{
    TiXmlDocument document;
    TiXmlDeclaration declaration("1.0", "utf-8", "");
    ((void*)((class TiXmlNode*)(void*)(&document))->InsertEndChild(declaration));
    ((void*)((class TiXmlNode*)(void*)(&document))->InsertEndChild(*(class TiXmlNode const*)(&static_cast<const TiXmlComment&>(TiXmlComment(FUN_1409a2360(" \xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad \xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2 "
            "\xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf \xc1\xf7\xc1\xa2 \xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6 \xb8\xb6\xbc\xbc\xbf\xe4 ", 0))))));
    TiXmlElement root("ms2");
    for (int nType = 0; nType < 6; nType++)
    {
        BlindList* pList = m_lists[nType];
        for (BlindList::iterator it = pList->begin(); it != pList->end(); ++it)
        {
            TiXmlElement element("blind");
            XmlSetAttr(&element, "type", nType);
            XmlSetAttr(&element, "target", it->second.m_name);
            XmlSetAttr(&element, "time", *(__int64 const*)(&it->second.m_expire));
            ((void*)((class TiXmlNode*)(void*)(&root))->InsertEndChild(element));
        }
    }
    ((void*)((class TiXmlNode*)(void*)(&document))->InsertEndChild(root));
    CString strPath = FUN_140cc2a00(FUN_141275640(), "BlindList.xml");
    document.SaveFile(FUN_14016a5c0(strPath, 0));
}

// @0x140a25730
bool BlindManager::Block(int nType, CStringW strKey)
{
    if (nType > 6 || nType < 0)
        return false;
    BlindList* pList = m_lists[nType];
    BlindEntry entry;
    entry.m_name = strKey;
    __time64_t nNow;
    _time64(&nNow);
    entry.m_expire = (std::numeric_limits<__int64>::max)();
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036e4c0())
        entry.m_expire = nNow + 0x15180;
    (*pList)[strKey] = entry;
    Save();
    return true;
}

// @0x140a25840
bool BlindManager::IsBlocked(int nType, CStringW strKey)
{
    if (nType > 6 || nType < 0)
        return false;
    BlindList* pList = m_lists[nType];
    BlindList::iterator it = pList->find(strKey);
    if (it == pList->end())
        return false;
    BlindEntry& entry = it->second;
    if (entry.m_expire > GetServerTime())
        return true;
    return false;
}

// @0x140a25950
bool BlindManager::BlockId(int nType, unsigned __int64 nId)
{
    return Block(nType, StringFormat<unsigned __int64>(L"{0}", nId));
}

// @0x140a259b0
bool BlindManager::IsBlockedId(int nType, unsigned __int64 nId)
{
    return IsBlocked(nType, StringFormat<unsigned __int64>(L"{0}", nId));
}

// 0x140a27ec0: TiXmlComment(const char*), tinyxml.h's inline ctor, emitted here by Save.

// Anchor for the UCRT header-inline memmove_s COMDAT of this range (0x140a29f80), which the exe's other users reach.
void Unk_BlindAnchor(void* pDst, const void* pSrc)
{
    memmove_s(pDst, 8, pSrc, 8);
}
