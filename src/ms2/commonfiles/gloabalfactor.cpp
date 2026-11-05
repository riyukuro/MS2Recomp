// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGloabalFactor: the global exp / meso rate tables and Table/multicontrol.xml.
// MS2-UNIT: ?\gloabalfactor.cpp
// MS2-RANGE: 0x1404c11a0-0x1404c5c80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAM$0A@@?$pair@HM@std@@QEAA@AEAHAEAM@Z 0x1404c1b80 ; unique
// MS2-PIN: ??$make_pair@AEAHAEAM@std@@YA?AU?$pair@HM@0@AEAHAEAM@Z 0x1404c35a0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CGloabalFactor@@6B?$TSingleton@VCGloabalFactor@@@@@ 0x142d4e4d8
// MS2-PIN: ??_7CGloabalFactor@@6B?$CValidData@VCGloabalFactor@@@@@ 0x142d4e4e8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gloabalfactor.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cgloabalfactor.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/featuremanager.h"
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers (the same xml loader helpers the other table units use).
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
enum Unk_DungeonGroupType : int; template <class E> int XmlValueByName(TiXmlElement* pElem, const char* pszName, E& eOut); template <> int XmlValueByName(TiXmlElement*, const char*, Unk_DungeonGroupType&);   // 0x140179060, the enum attribute (specialization in additionalactionadditional.cpp)
class Unk_140166410;   // the game settings (CFeatureManager)
Unk_140166410* FUN_140166410();

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
CGloabalFactor* TSingleton<CGloabalFactor>::s_instance;     // DAT_143aaef08
bool CGloabalFactor::s_bInit;
#endif

// @0x1404c11a0
CGloabalFactor::CGloabalFactor()
{
}

// @0x1404c1220
CGloabalFactor::~CGloabalFactor()
{
}

// @0x1404c1290
bool CGloabalFactor::Load()
{
    if (!FUN_1404c12f0())
        return false;
    if (!FUN_1404c1370())
        return false;
    if (!LoadMultiControl())
        return false;
    return true;
}

// @0x1404c12f0
bool CGloabalFactor::FUN_1404c12f0()
{
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j <= 99; ++j)
            m_fExpRate[i][j] = 1.0f;
    }
    SetInit(true);
    return true;
}

// @0x1404c1370
bool CGloabalFactor::FUN_1404c1370()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j <= 99; ++j)
            m_fMesoRate[i][j] = 1.0f;
    }
    SetInit(true);
    return true;
}

// @0x1404c1a50
static int ReadMultiType(CString& str)
{
    if (str.IsEmpty())
        return 0;
    if (str.CompareNoCase("enchantScrollReceipe") == 0)
        return CGloabalFactor::MULTI_ENCHANT_SCROLL_RECIPE;
    else if (str.CompareNoCase("globalDropItemCount") == 0)
        return CGloabalFactor::MULTI_GLOBAL_DROP_ITEM_COUNT;
    else if (str.CompareNoCase("equipmentSellPrice") == 0)
        return CGloabalFactor::MULTI_EQUIPMENT_SELL_PRICE;
    else if (str.CompareNoCase("dungeonClearMeso") == 0)
        return CGloabalFactor::MULTI_DUNGEON_CLEAR_MESO;
    else if (str.CompareNoCase("questRewardMeso") == 0)
        return CGloabalFactor::MULTI_QUEST_REWARD_MESO;
    return 0;
}

// @0x1404c1e80 (tinyxmlhelper.h line 250)
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
static int FUN_1404c1e80(TiXmlElement* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRead != 0)
        return nRead;
    *pnOut = ReadMultiType(str);
    return nRead;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gloabalfactor.cpp"

// @0x1404c1400
bool CGloabalFactor::LoadMultiControl()
{
    m_multi.clear();
    m_multi.resize(6);
    CString strDir;
    strDir.Format("%s", "Table");
    CString strPath = FUN_14071a5b0(strDir, "multicontrol.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("multi")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("multi")))
    {
        int nType = 0;
        int nKey = 0;
        float fValue = 1.0f;
        FUN_1404c1e80(pNode, "type", &nType);
        if (nType == 4)
        {
            Unk_DungeonGroupType nEnum;
            XmlValueByName(pNode, "key", nEnum);
            nKey = nEnum;
        }
        else
        {
            XmlGetAttr((class TiXmlElement*)(pNode), "key", reinterpret_cast<int&>(nKey));
        }
        XmlGetAttr((class TiXmlElement*)(pNode), "value", reinterpret_cast<float&>(fValue));
        if (nType == 0 || nType >= 6)
            continue;
        m_multi[nType].insert(std::make_pair(nKey, fValue));
    }
    SetInit(true);
    return true;
}

// @0x1404c1730
float CGloabalFactor::FUN_1404c1730(unsigned int nLevel, int nKind)
{
    CheckInit();
    if (nLevel < 1 || nLevel > (unsigned short)reinterpret_cast<CFeatureManager*>(FUN_140166410())->GetLevelCap())
        return 1.0f;
    return m_fMesoRate[nKind][nLevel];
}

// @0x1404c17a0
float CGloabalFactor::FUN_1404c17a0(unsigned int nLevel, int nKind)
{
    CheckInit();
    if (nLevel < 1 || nLevel > (unsigned short)reinterpret_cast<CFeatureManager*>(FUN_140166410())->GetLevelCap())
        return 1.0f;
    return m_fExpRate[nKind][nLevel];
}

// @0x1404c1810
float CGloabalFactor::FUN_1404c1810(int nType, int nGroupId)
{
    CheckInit();
    if (nType == 0 || nType >= 6)
        return 1.0f;
    MultiMap& rMap = m_multi[nType];
    MultiMap::iterator it = rMap.find(nGroupId);
    if (it == rMap.end())
        return 1.0f;
    return it->second;
}

// @0x1404c18c0
void CGloabalFactor::FUN_1404c18c0(CInPacket& packet)
{
    CheckInit();
    for (size_t i = 0; i < 3; ++i)
    {
        int nKind = packet.ReadUInt8();
        for (int j = 1; j <= 99; ++j)
            m_fExpRate[nKind][j] = packet.ReadFloat();
    }
    for (size_t i = 0; i < 3; ++i)
    {
        int nKind = packet.ReadUInt8();
        for (int j = 1; j <= 99; ++j)
            m_fMesoRate[nKind][j] = packet.ReadFloat();
    }
}

// A stream record of two 64-bit values and a wide string; its owner is outside this unit (the pair of (de)serialisers
// were placed here by the linker).
class Unk_GFRecord
{
public:
    void FUN_1404c5b70(COutputStream* pOut);    // writes the record
    void FUN_1404c5be0(CInputStream* pIn);      // reads the record
    __int64 m_n0;                               // +0x0
    __int64 m_n1;                               // +0x8
    CStringW m_str;                             // +0x10
};
MS2_CHECK_SIZE(Unk_GFRecord, 0x18);

// @0x1404c5b70
void Unk_GFRecord::FUN_1404c5b70(COutputStream* pOut)
{
    pOut->WriteInt64(m_n0);
    pOut->WriteInt64(m_n1);
    pOut->WriteUnicodeString(m_str);
}

// @0x1404c5be0
void Unk_GFRecord::FUN_1404c5be0(CInputStream* pIn)
{
    m_n0 = pIn->ReadInt64();
    m_n1 = pIn->ReadInt64();
    m_str = pIn->ReadUnicodeString();
}

MS2_EMIT_CRT_MEMMOVE_S();
