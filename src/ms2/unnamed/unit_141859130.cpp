// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The xblock entity-name table (entity GUID -> name), loaded
// from ./Data/Resource/Exported/XBlock/<xblock>.xblock, with its ATL CRBMap<GUID, CString> instantiation. Names invented.
// MS2-UNIT: unit_141859130
// MS2-RANGE: 0x141859130-0x14185aa10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <string.h>
#include <efd/utf8string.h>
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"

class Unk_XmlNode { public: public:
    class Unk_XmlNode* FirstChild(char const*);   // C3: was free FUN_140165cf0
public:
    class Unk_XmlNode* NextSibling(char const*);   // C3: was free FUN_140168650
};

CString FUN_14016a5c0(const char* psz, int n);
const char* FUN_14086f4b0(Unk_XmlNode* pNode, const char* pszName); // attribute text

#pragma function(memcmp, memset)
// A GUID kept as 16 raw bytes, compared with memcmp.
struct Unk_XBlockGuid
{
    unsigned char m_b[16];
    Unk_XBlockGuid() { memset(m_b, 0, 16); }
    bool operator==(const Unk_XBlockGuid& rhs) const { return memcmp(m_b, rhs.m_b, 16) == 0; }
    bool operator<(const Unk_XBlockGuid& rhs) const { return memcmp(m_b, rhs.m_b, 16) < 0; }
};
#pragma intrinsic(memcmp, memset)

bool FUN_141859a60(const efd::utf8string& strGuid, Unk_XBlockGuid* pGuid);

class Unk_XBlockNameMap
{
public:
    Unk_XBlockNameMap();                                                 // 0x141859130
    ~Unk_XBlockNameMap();                                                // 0x141859160
    int LoadXBlock(CString strXBlock);                                   // 0x141859190
    CString FindName(const Unk_XBlockGuid& key);                         // 0x1418594d0

    ATL::CRBMap<Unk_XBlockGuid, CString> m_names;
};

// @0x141859130
Unk_XBlockNameMap::Unk_XBlockNameMap()
    : m_names(10)
{
}

// @0x141859160
Unk_XBlockNameMap::~Unk_XBlockNameMap()
{
}

// @0x141859190
int Unk_XBlockNameMap::LoadXBlock(CString strXBlock)
{
    m_names.RemoveAll();
    CString strPath;
    strPath.Format("./Data/Resource/Exported/XBlock/%s.xblock", (const char*)strXBlock);
    TiXmlDocument doc;
    if (!doc.FUN_140870fc0(FUN_14016a5c0((const char*)strPath, 0), 0))
        return 0;
    Unk_XmlNode* pGame = ((class Unk_XmlNode*)(void*)(&doc))->FirstChild("game");
    if (pGame == 0)
        return 0;
    Unk_XmlNode* pEntity = ((class Unk_XmlNode*)(void*)(pGame))->FirstChild("entitySet");
    if (pEntity == 0)
        return 0;
    for (pEntity = ((class Unk_XmlNode*)(void*)(pEntity))->FirstChild("entity"); pEntity != 0; pEntity = ((class Unk_XmlNode*)(class Unk_XmlNode*)(pEntity))->NextSibling("entity")) {
        const char* pszId = FUN_14086f4b0(pEntity, "id");
        if (pszId == 0)
            continue;
        const char* pszName = FUN_14086f4b0(pEntity, "name");
        if (pszName == 0)
            continue;
        CString strName(pszName);
        Unk_XBlockGuid guid;
        {
            efd::utf8string strId(pszId);
            FUN_141859a60(strId, &guid);
        }
        m_names.SetAt(guid, strName);
    }
    return 1;
}

// @0x1418594d0
CString Unk_XBlockNameMap::FindName(const Unk_XBlockGuid& key)
{
    CString strName;
    m_names.Lookup(key, strName);
    return strName;
}

// @0x141859a60   parses a 32-hex-digit GUID string ("{}" and "-" ignored) into its in-memory byte layout
bool FUN_141859a60(const efd::utf8string& strGuid, Unk_XBlockGuid* pGuid)
{
    efd::utf8string str(strGuid);
    str.trim(efd::TrimAll, " \t{}");
    str.replace_substr("-", "");
    if (str.length() != 0x20)
        return false;
    const char* pszHex = str.c_str();
    unsigned char b[16];
    unsigned char* pOut = b;
    for (int i = 0; i < 0x20; i++) {
        int n = 0;
        char c = pszHex[i];
        if (c == '0')
            n = 0;
        else if (c >= '1' && c <= '9')
            n = c - 0x30;
        else if (c >= 'a' && c <= 'f')
            n = c - 0x57;
        else if (c >= 'A' && c <= 'F')
            n = c - 0x37;
        else
            return false;
        if (i % 2 == 0)
            *pOut = (unsigned char)(n << 4);
        else {
            *pOut = *pOut + (unsigned char)n;
            pOut++;
        }
    }
    pGuid->m_b[0] = b[3];
    pGuid->m_b[1] = b[2];
    pGuid->m_b[2] = b[1];
    pGuid->m_b[3] = b[0];
    pGuid->m_b[4] = b[5];
    pGuid->m_b[5] = b[4];
    pGuid->m_b[6] = b[7];
    pGuid->m_b[7] = b[6];
    pGuid->m_b[8] = b[8];
    pGuid->m_b[9] = b[9];
    pGuid->m_b[10] = b[10];
    pGuid->m_b[11] = b[11];
    pGuid->m_b[12] = b[12];
    pGuid->m_b[13] = b[13];
    pGuid->m_b[14] = b[14];
    pGuid->m_b[15] = b[15];
    return true;
}
