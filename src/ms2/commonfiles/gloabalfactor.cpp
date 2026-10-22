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

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
int FUN_140179060(Unk_140165cf0* pElem, const char* pszName, int& nOut);   // int or enum value by name
class Unk_140166410 { public: unsigned short FUN_14036db20(); };           // the game settings (max level)
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
// MS2-FUNCTIONAL: the exe emits an extra jmp after each else-if arm (194 vs 204 bytes); no source form found
static int ReadMultiType(CString& str)
{
    if (str.IsEmpty())
        return 0;
    else
    {
        if (str.CompareNoCase("enchantScrollReceipe") == 0)
            return CGloabalFactor::MULTI_ENCHANT_SCROLL_RECIPE;
        else
        {
            if (str.CompareNoCase("globalDropItemCount") == 0)
                return CGloabalFactor::MULTI_GLOBAL_DROP_ITEM_COUNT;
            else
            {
                if (str.CompareNoCase("equipmentSellPrice") == 0)
                    return CGloabalFactor::MULTI_EQUIPMENT_SELL_PRICE;
                else
                {
                    if (str.CompareNoCase("dungeonClearMeso") == 0)
                        return CGloabalFactor::MULTI_DUNGEON_CLEAR_MESO;
                    else
                    {
                        if (str.CompareNoCase("questRewardMeso") == 0)
                            return CGloabalFactor::MULTI_QUEST_REWARD_MESO;
                        else
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

// @0x1404c1e80 (tinyxmlhelper.h line 250)
// MS2-FUNCTIONAL: the exe frame holds the assert-macro temporaries (188 vs 163 bytes)
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
static int FUN_1404c1e80(Unk_140165cf0* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = FUN_1408733e0(pElem, pszName, str);
    if (nRead == 0)
        *pnOut = ReadMultiType(str);
    return nRead;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gloabalfactor.cpp"

// @0x1404c1400
// MS2-FUNCTIONAL: the exe keeps the narrowed path pointer and the 0x10-byte xml/path temporaries in a different frame layout (814 vs 796 bytes)
bool CGloabalFactor::LoadMultiControl()
{
    m_multi.clear();
    m_multi.resize(6);
    CString strDir;
    strDir.Format("%s", "Table");
    CString strPath = FUN_14071a5b0(strDir, CString("multicontrol.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("multi"); pNode != 0; pNode = pNode->FUN_140168650("multi"))
    {
        int nType = 0;
        int nKey = 0;
        float fValue = 1.0f;
        FUN_1404c1e80(pNode, "type", &nType);
        if (nType == 4)
        {
            int nEnum;
            FUN_140179060(pNode, "key", nEnum);
            nKey = nEnum;
        }
        else
        {
            FUN_1408731e0(pNode, "key", nKey);
        }
        FUN_140873360(pNode, "value", fValue);
        if (nType != 0 && nType < 6)
            m_multi[nType].insert(std::make_pair(nKey, fValue));
    }
    SetInit(true);
    return true;
}

// @0x1404c1730
float CGloabalFactor::FUN_1404c1730(unsigned int nLevel, int nKind)
{
    CheckInit();
    if (nLevel < 1 || nLevel > FUN_140166410()->FUN_14036db20())
        return 1.0f;
    return m_fMesoRate[nKind][nLevel];
}

// @0x1404c17a0
float CGloabalFactor::FUN_1404c17a0(unsigned int nLevel, int nKind)
{
    CheckInit();
    if (nLevel < 1 || nLevel > FUN_140166410()->FUN_14036db20())
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
