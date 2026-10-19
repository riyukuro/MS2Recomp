// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). BlindManager: the per-type block lists of the merat market /
// chat, persisted in <user dir>\BlindList.xml. See blindmanager.h.
// MS2-UNIT: ?\blindmanager.cpp
// MS2-RANGE: 0x140a24e90-0x140a2a0a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\blindmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/blindmanager.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include <string.h>
#include <time.h>
#include <string>
#include "hook/ms2hook.h"

// Unrecovered helpers.
CString FUN_141275640();                                                // the user data directory
CString FUN_140cc2a00(const CString& strDir, const CString& strFile);   // dir + "\\" + file
CString FUN_1409a2360(const char* psz, int n);                          // text conversion
CString FUN_14016a5c0(const char* psz, int n);                          // path conversion
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault);
__int64 FUN_140354150(Unk_140165cf0* pElem, const char* pszName);       // _time64 attribute
void* FUN_14086e000(void* pParent, const void* pChild);                 // InsertEndChild
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);       // SetAttribute(name, int)
void FUN_1408740a0(void* pElem, const char* pszName, const CStringW* pstrValue);   // SetAttribute(name, string)
void FUN_140873eb0(void* pElem, const char* pszName, const __int64* pnValue);      // SetAttribute(name, time)
bool FUN_1408710c0(void* pDoc, const char* pszPath);                    // SaveFile
__int64 FUN_140190260();                                                // the default block duration end
__int64 FUN_140869440();                                                // the server time
CFeatureManager* FUN_140166410();
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const unsigned __int64& nArg);   // "{0}" formatter
void* FUN_14086e9c0(void* pNode, int nType);                            // TiXmlNode::TiXmlNode
void FUN_140872b60(void* pNode, const char* pszValue);                  // TiXmlNode::SetValue
extern char DAT_142dfc138;                                              // the TiXmlComment vftable

// The game's TinyXML (bare global names, not efd::), as far as this unit builds it.
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);                      // 0x14086f2f0
    ~Unk_TiXmlElement();                                        // 0x14086f450
private:
    void* m_data[0x12];
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);
class Unk_TiXmlDeclaration
{
public:
    Unk_TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);   // 0x1408704d0
    ~Unk_TiXmlDeclaration();                                    // 0x14081ad20
private:
    void* m_data[0xd];
};
MS2_CHECK_SIZE(Unk_TiXmlDeclaration, 0x68);
class Unk_TiXmlComment
{
public:
    explicit Unk_TiXmlComment(const char* pszValue);            // 0x140a27ec0
    ~Unk_TiXmlComment();                                        // 0x1408724d0
private:
    void* m_data[0xa];
};
MS2_CHECK_SIZE(Unk_TiXmlComment, 0x50);

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
// MS2-FUNCTIONAL: the exe keeps the path temporaries in a different order around the std::string argument (frame 0x10 smaller)
void BlindManager::Load()
{
    ClearLists();
    CreateLists();
    CString strFile("BlindList.xml");
    CString strPath = FUN_140cc2a00(FUN_141275640(), strFile);
    if (FUN_140166420()->FUN_1403987d0(std::string((const char*)strPath)) == 0)
        return;
    TiXmlDocument document;
    if (FUN_140166420()->FUN_1403974b0(&document, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&document)->FUN_140165cf0("ms2");
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("blind"); pNode != 0; pNode = pNode->FUN_140168650("blind"))
    {
        int nType = FUN_140197350(pNode, "type", 0);
        CStringW strTarget = FUN_1401bf530(pNode, "target", CStringW(L""));
        __int64 nExpire = FUN_140354150(pNode, "time");
        if (nType < 0 || nType > 5)
            continue;
        __time64_t nNow;
        _time64(&nNow);
        if (nExpire < nNow)
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
// MS2-FUNCTIONAL: the comment node temporaries are laid out differently (frame 0x10 larger in the exe)
void BlindManager::Save()
{
    TiXmlDocument document;
    Unk_TiXmlDeclaration declaration("1.0", "utf-8", "");
    FUN_14086e000(&document, &declaration);
    {
        Unk_TiXmlComment comment(FUN_1409a2360(" \xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad \xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2 "
            "\xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf \xc1\xf7\xc1\xa2 \xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6 \xb8\xb6\xbc\xbc\xbf\xe4 ", 0));
        FUN_14086e000(&document, &comment);
    }
    Unk_TiXmlElement root("ms2");
    for (int nType = 0; nType < 6; nType++)
    {
        BlindList* pList = m_lists[nType];
        for (BlindList::iterator it = pList->begin(); it != pList->end(); ++it)
        {
            Unk_TiXmlElement element("blind");
            FUN_140873ca0(&element, "type", nType);
            FUN_1408740a0(&element, "target", &it->second.m_name);
            FUN_140873eb0(&element, "time", &it->second.m_expire);
            FUN_14086e000(&root, &element);
        }
    }
    FUN_14086e000(&document, &root);
    CString strFile("BlindList.xml");
    CString strPath = FUN_140cc2a00(FUN_141275640(), strFile);
    FUN_1408710c0(&document, FUN_14016a5c0(strPath, 0));
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
    entry.m_expire = FUN_140190260();
    if (FUN_140166410()->FUN_14036e4c0())
        entry.m_expire = nNow + 0x15180;
    (*pList)[strKey] = entry;
    Save();
    return true;
}

// @0x140a25840
// MS2-FUNCTIONAL: the exe splits the key destruction over the return paths (2 more ip2state entries)
bool BlindManager::IsBlocked(int nType, CStringW strKey)
{
    if (nType > 6 || nType < 0)
        return false;
    BlindList* pList = m_lists[nType];
    BlindList::iterator it = pList->find(strKey);
    if (it == pList->end())
        return false;
    BlindEntry& entry = it->second;
    if (FUN_140869440() < entry.m_expire)
        return true;
    return false;
}

// @0x140a25950
bool BlindManager::BlockId(int nType, unsigned __int64 nId)
{
    return Block(nType, FUN_1406c6bd0(L"{0}", nId));
}

// @0x140a259b0
bool BlindManager::IsBlockedId(int nType, unsigned __int64 nId)
{
    return IsBlocked(nType, FUN_1406c6bd0(L"{0}", nId));
}

// @0x140a27ec0
// MS2-FUNCTIONAL: the exe's ctor has unwind info (the TiXmlNode base is destroyed on exceptions); the vftable is bound as a data symbol (the comment node class is not recovered)
Unk_TiXmlComment::Unk_TiXmlComment(const char* pszValue)
{
    FUN_14086e9c0(this, 2);
    *reinterpret_cast<void**>(this) = &DAT_142dfc138;
    FUN_140872b60(this, pszValue);
}

// Anchor for the UCRT header-inline memmove_s COMDAT of this range (0x140a29f80), which the exe's other users reach.
void Unk_BlindAnchor(void* pDst, const void* pSrc)
{
    memmove_s(pDst, 8, pSrc, 8);
}
