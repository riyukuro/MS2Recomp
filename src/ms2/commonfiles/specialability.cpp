// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Special abilities (socket "SA" stats): the 0xcf-row table
// (specialAbilityStringTable.xml + stringSpecialAbilityName.xml), name -> type lookup and the ability groups.
// MS2-UNIT: commonfiles\specialability.cpp
// MS2-RANGE: 0x1400bd070-0x1400bd140 .text$di
// MS2-RANGE: 0x14081c780-0x1408273f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@QEAA@XZ 0x140821a50 ; unique
// MS2-PIN: ??1?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@QEAA@XZ 0x140821a70 ; unique
// MS2-PIN: ??_G?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@QEAAPEAXI@Z 0x140822350 ; unique
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CAtlList@W4eSpecialAbility@@V?$CElementTraits@W4eSpecialAbility@@@ATL@@@ATL@@@@QEAAAEAV0@AEBUUnk_BmNewTag@@@Z 0x140822510 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x140825c10 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140825c20 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@USpecialAbilityInfo@@@std@@V?$_Vector_val@U?$_Simple_types@USpecialAbilityInfo@@@std@@@2@$00@std@@QEAAAEAV?$allocator@USpecialAbilityInfo@@@2@XZ 0x140825c90 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@USpecialAbilityInfo@@@std@@V?$_Vector_val@U?$_Simple_types@USpecialAbilityInfo@@@std@@@2@$00@std@@QEBAAEBV?$allocator@USpecialAbilityInfo@@@2@XZ 0x140825ca0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@XZ 0x140825cb0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x140825cf0 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@2@@Z 0x140825f80 ; unique
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@PEAX@2@@Z 0x140826060 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@2@@Z 0x140826400 ; unique
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@PEAX@2@@Z 0x1408264e0 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@2@_K@Z 0x140826c20 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4SAType@@@std@@PEAX@2@_K@Z 0x140826c50 ; order
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\specialability.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "specialability.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <map>
#include <vector>
#include <new>

#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

class Unk_140165cf0;     // game TinyXML element

// Unrecovered helpers (the xml loader helpers the other table units use).
Unk_140165cf0* FUN_140165cf0(Unk_140165cf0* pParent, const char* pszName);      // the first child element
Unk_140165cf0* FUN_140168650(Unk_140165cf0* pElem, const char* pszName);        // the next sibling with the name
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CStringA FUN_14071a5b0(const CStringA& strDir, const CStringA& strFile);         // Table/<file>
CStringA FUN_14071ae20(const CStringA& strFile);                                 // the localised string table path
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CStringA& strOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);

// The row table (DAT_143ab1a40, constructed by skilltieroptionmanager.cpp's static init range); m_specialTo in the source.
extern std::vector<SpecialAbilityInfo> DAT_143ab1a40;

// The name table key order: case insensitive (FUN_1408222c0).
struct Unk_SANameLess
{
    bool operator()(const CStringA& strA, const CStringA& strB) const;
};

// @0x1408222c0
bool Unk_SANameLess::operator()(const CStringA& strA, const CStringA& strB) const
{
    return strA.CompareNoCase(strB) < 0;
}

// The row vector is constructed and destroyed by other units' static init ranges; its ctor/dtor COMDATs
// (0x140821660 ... 0x140821a90) live in this range, so instantiate them here.
void Unk_SpecialToAnchor(void* pMem)
{
    std::vector<SpecialAbilityInfo>* p = new (pMem) std::vector<SpecialAbilityInfo>();
    p->std::vector<SpecialAbilityInfo>::~vector();
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's globals (symbols-manual.tsv)
// @0x1400bd070
std::map<CStringA, SAType, Unk_SANameLess> g_mapSANameToType;
// @0x1400bd0a0
Unk_SpecialAbilityMap g_kSpecialAbilityMap;
// @0x1400bd0f0
ATL::CAtlMap<eSpecialAbility, Unk_SAListPtr> g_mapSAAbilityList;
#else
extern std::map<CStringA, SAType, Unk_SANameLess> g_mapSANameToType;
extern Unk_SpecialAbilityMap g_kSpecialAbilityMap;
extern ATL::CAtlMap<eSpecialAbility, Unk_SAListPtr> g_mapSAAbilityList;
#endif

// @0x14081c780
SpecialAbilityInfo::SpecialAbilityInfo()
    : m_nValueType(0)
{
}

// @0x14081c7e0
SpecialAbilityInfo::SpecialAbilityInfo(const CStringA& strKey, CStringW strFormat, CStringW strName, int nValueType)
    : m_strKey(strKey), m_nValueType(nValueType), m_strFormat(strFormat), m_strName(strName)
{
}

// @0x14081c880
int FUN_14081c880()
{
    if (FUN_14081ccd0() == 0)
        return 0;
    // The two fixed special stats (g_kSpecialAbilityMap: stat -> string id).
    g_kSpecialAbilityMap.SetAt((Unk_SocketSpecialStat)0x75, 0x5a995cc);
    g_kSpecialAbilityMap.SetAt((Unk_SocketSpecialStat)0x76, 0x5a995ce);
    for (int i = 1; i < 0xcf; i++)
    {
        SAType nType = (SAType)i;
        g_mapSANameToType.insert(std::make_pair(DAT_143ab1a40[i].m_strKey, nType));
    }
    Unk_SAListPtr spList;
    spList = Unk_BmNewTag(0);
    eSpecialAbility e1 = (eSpecialAbility)0x18;
    spList->AddTail(e1);
    eSpecialAbility e2 = (eSpecialAbility)0x19;
    spList->AddTail(e2);
    eSpecialAbility e3 = (eSpecialAbility)0x12;
    spList->AddTail(e3);
    eSpecialAbility e4 = (eSpecialAbility)0x13;
    spList->AddTail(e4);
    eSpecialAbility e5 = (eSpecialAbility)0x14;
    spList->AddTail(e5);
    eSpecialAbility e6 = (eSpecialAbility)0x15;
    spList->AddTail(e6);
    eSpecialAbility e7 = (eSpecialAbility)0x16;
    spList->AddTail(e7);
    eSpecialAbility e8 = (eSpecialAbility)0x17;
    spList->AddTail(e8);
    eSpecialAbility e9 = (eSpecialAbility)7;
    spList->AddTail(e9);
    eSpecialAbility e10 = (eSpecialAbility)9;
    spList->AddTail(e10);
    eSpecialAbility e11 = (eSpecialAbility)0xb;
    spList->AddTail(e11);
    eSpecialAbility e12 = (eSpecialAbility)0xc;
    spList->AddTail(e12);
    eSpecialAbility k1 = (eSpecialAbility)0x18;
    g_mapSAAbilityList.SetAt(k1, spList);
    eSpecialAbility k2 = (eSpecialAbility)0x19;
    g_mapSAAbilityList.SetAt(k2, spList);
    eSpecialAbility k3 = (eSpecialAbility)0x12;
    g_mapSAAbilityList.SetAt(k3, spList);
    eSpecialAbility k4 = (eSpecialAbility)0x13;
    g_mapSAAbilityList.SetAt(k4, spList);
    eSpecialAbility k5 = (eSpecialAbility)0x14;
    g_mapSAAbilityList.SetAt(k5, spList);
    eSpecialAbility k6 = (eSpecialAbility)0x15;
    g_mapSAAbilityList.SetAt(k6, spList);
    eSpecialAbility k7 = (eSpecialAbility)0x16;
    g_mapSAAbilityList.SetAt(k7, spList);
    eSpecialAbility k8 = (eSpecialAbility)0x17;
    g_mapSAAbilityList.SetAt(k8, spList);
    eSpecialAbility k9 = (eSpecialAbility)7;
    g_mapSAAbilityList.SetAt(k9, spList);
    eSpecialAbility k10 = (eSpecialAbility)9;
    g_mapSAAbilityList.SetAt(k10, spList);
    eSpecialAbility k11 = (eSpecialAbility)0xb;
    g_mapSAAbilityList.SetAt(k11, spList);
    eSpecialAbility k12 = (eSpecialAbility)0xc;
    g_mapSAAbilityList.SetAt(k12, spList);
    return 1;
}

// @0x14081ccd0
int FUN_14081ccd0()
{
    DAT_143ab1a40.clear();
    DAT_143ab1a40.resize(0xcf);
    std::map<int, CStringW> mapNames;
    FUN_14081d060(mapNames);
    CStringA strPath = FUN_14071a5b0(CStringA("Table"), CStringA("specialAbilityStringTable.xml"));
    TiXmlDocument doc;
    int nResult;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        nResult = 0;
    }
    else
    {
        Unk_140165cf0* pRoot = FUN_140165cf0(reinterpret_cast<Unk_140165cf0*>(&doc), "ms2");
        if (pRoot == 0)
        {
            nResult = 0;
        }
        else
        {
            for (Unk_140165cf0* pElem = FUN_140165cf0(pRoot, "key"); pElem != 0; pElem = FUN_140168650(pElem, "key"))
            {
                CStringA strOption;
                int nId;
                int nValueType;
                int nCommonId;
                int nValueId;
                FUN_1408731e0(pElem, "id", nId);
                FUN_1408733e0(pElem, "option", strOption);
                FUN_1408731e0(pElem, "valueType", nValueType);
                FUN_1408731e0(pElem, "commonStringID", nCommonId);
                FUN_1408731e0(pElem, "valueStringID", nValueId);
                DAT_143ab1a40[nId] = SpecialAbilityInfo(strOption, mapNames[nValueId], mapNames[nCommonId], nValueType);
            }
            mapNames.clear();
            nResult = 1;
        }
    }
    return nResult;
}

// @0x14081d060
int FUN_14081d060(std::map<int, CStringW>& mapNames)
{
    CStringA strPath = FUN_14071ae20(CStringA("stringSpecialAbilityName.xml"));
    TiXmlDocument doc;
    int nResult;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        nResult = 0;
    }
    else
    {
        Unk_140165cf0* pRoot = FUN_140165cf0(reinterpret_cast<Unk_140165cf0*>(&doc), "ms2");
        if (pRoot == 0)
        {
            nResult = 0;
        }
        else
        {
            for (Unk_140165cf0* pElem = FUN_140165cf0(pRoot, "key"); pElem != 0; pElem = FUN_140168650(pElem, "key"))
            {
                CStringW strName;
                CStringW strUnused;
                int nId;
                FUN_1408731e0(pElem, "id", nId);
                FUN_140873420(pElem, "name", strName);
                mapNames[nId] = strName;
            }
            nResult = 1;
        }
    }
    return nResult;
}

// @0x14081d260 the row index of a name (case insensitive), 0 if there is none
unsigned FUN_14081d260(const CStringA& strName)
{
    for (unsigned i = 0; i < DAT_143ab1a40.size(); i++)
    {
        if (DAT_143ab1a40[i].m_strKey.CompareNoCase(strName) == 0)
            return i;
    }
    return 0;
}

// @0x14081d2f0
SAType FUN_14081d2f0(const CStringA& strName)
{
    std::map<CStringA, SAType, Unk_SANameLess>::iterator it = g_mapSANameToType.find(strName);
    if (it != g_mapSANameToType.end())
        return it->second;
    MS2_ASSERT_AT(0xa6, 0);
    return SAType_None;
}

// @0x14081d380 the option key of a row
const CStringA& FUN_14081d380(int nIndex)
{
    static CStringA s_strEmpty;
    unsigned saIdx = nIndex;
    if (nIndex >= 0xcf)
        return s_strEmpty;
    return DAT_143ab1a40[saIdx].m_strKey;
}

// @0x14081d420
bool FUN_14081d420(int nIndex)
{
    if (nIndex >= 0xcf)
        return false;
    return !DAT_143ab1a40[nIndex].m_strKey.IsEmpty();
}

// @0x14081d480
int FUN_14081d480(int nType)
{
    switch (nType)
    {
    case 0: return 0x98;
    case 1: return 0x99;
    case 2: return 0x9a;
    case 3: return 0x9b;
    case 4: return 0xb4;
    case 5: return 0xb5;
    default:
        MS2_ASSERT_AT(0xdd, 0);
        return 0;
    case 7: return 0xb6;
    case 8: return 0xb7;
    case 10: return 0xb8;
    case 0xc: return 0xb9;
    case 0xd: return 0xba;
    case 0xe: return 0xbb;
    case 0xf: return 0xbc;
    case 0x10: return 0xbd;
    case 0x11: return 0xbe;
    case 0x12: return 0xbf;
    case 0x13: return 0xc0;
    case 0x14: return 0xc1;
    case 0x15: return 0xc2;
    case 0x17: return 0xc3;
    case 0x18: return 0xc4;
    case 0x19: return 0xc5;
    case 0x1a: return 0xc6;
    case 0x1c: return 0x82;
    case 0x1d: return 0xc9;
    case 0x1f: return 199;
    case 0x20: return 200;
    }
}

// @0x14081d650 the option has one of the abilities of the group
int FUN_14081d650(MS2Ptr<CItemOption> spOption, int nGroup, unsigned nType)
{
    int nResult;
    Unk_SAListPtr spList = FUN_14081d7b0((eSpecialAbility)nType);
    if (spList.get() == 0)
    {
        nResult = 0;
    }
    else
    {
        POSITION pos = spList->GetHeadPosition();
        BaseOption* pFound;
        do
        {
            if (pos == 0)
                return 0;
            eSpecialAbility nStat = spList->GetNext(pos);
            pFound = spOption->FUN_1405cb800(nGroup, nStat).get();
        } while (pFound == 0);
        nResult = 1;
    }
    return nResult;
}

// @0x14081d7b0 the ability list of a group
Unk_SAListPtr FUN_14081d7b0(eSpecialAbility nType)
{
    Unk_SAListPtr spList(0);
    g_mapSAAbilityList.Lookup(nType, spList);
    return spList;
}

// @0x14081d830
int FUN_14081d830(int nType)
{
    return FUN_14081d7b0((eSpecialAbility)nType).get() != 0;
}

// @0x14081d8a0
int FUN_14081d8a0(int nType)
{
    switch (nType)
    {
    case 0x3e9:
    case 0x3ea:
    case 0x3eb:
    case 0x3ec:
        return 1;
    default:
        return 0;
    }
}

// @0x14081d8e0
int FUN_14081d8e0(int nType)
{
    switch (nType)
    {
    case 3:
    case 4:
    case 5:
    case 0x17:
    case 0x1a:
    case 0x26:
    case 0x28:
    case 0x3a:
        return 1;
    default:
        return 0;
    }
}

// @0x14081d980
int FUN_14081d980(int nValue)
{
    switch (nValue)
    {
    case 0xb1:
        return 0x26;
    case 0xb2:
        return 0x28;
    case 0xbd:
        return 0x17;
    case 0xbe:
        return 0x1a;
    default:
        return 0;
    }
}

// @0x14081d9e0 the ability is a skill level up tier (0x4d - 0x5a)
int FUN_14081d9e0(int nType)
{
    switch (nType)
    {
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
        return 1;
    default:
        return 0;
    }
}

// @0x14081da20 the tier of it
int FUN_14081da20(int nType)
{
    switch (nType)
    {
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
        return nType - 0x4c;
    default:
        return 0;
    }
}

// @0x14081da60
bool FUN_14081da60(int nType, int nItemId)
{
    bool bResult;
    switch (nType)
    {
    case 0x62:
        bResult = nItemId == 0x3a2c943;
        break;
    case 99:
        bResult = nItemId == 0x3a2c941;
        break;
    case 100:
        bResult = nItemId == 0x3a2c942;
        break;
    case 0x65:
        bResult = nItemId == 0x3a2c946;
        break;
    case 0x66:
        bResult = nItemId == 0x3a2c944;
        break;
    case 0x67:
        bResult = nItemId == 0x3a2c947;
        break;
    case 0x68:
        if (nItemId == 0x3a2c948 || nItemId == 0x3f221c1)
            bResult = true;
        else
            bResult = false;
        break;
    default:
        bResult = true;
        break;
    case 0xa2:
        bResult = nItemId == 0x3a2c94a;
    }
    return bResult;
}

// @0x14081dc50 the value is a plain number
bool FUN_14081dc50(int nIndex)
{
        MS2_ASSERT_MSG_AT(0x175, L"m_specialTo[saIdx].m_valueType != eOptionValue::kNone", DAT_143ab1a40[nIndex].m_nValueType != 0);
    return DAT_143ab1a40[nIndex].m_nValueType == 1;
}

// @0x14081dcd0 the value is a percent
bool FUN_14081dcd0(int nIndex)
{
        MS2_ASSERT_MSG_AT(0x17b, L"m_specialTo[saIdx].m_valueType != eOptionValue::kNone", DAT_143ab1a40[nIndex].m_nValueType != 0);
    return DAT_143ab1a40[nIndex].m_nValueType == 2;
}

// @0x14081dd50
int FUN_14081dd50(int nIndex)
{
    return DAT_143ab1a40[nIndex].m_nValueType;
}

// @0x14081dd80
SAType FUN_14081dd80(const CStringA& strName)
{
    return FUN_14081d2f0(strName);
}
