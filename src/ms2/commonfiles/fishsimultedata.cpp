// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The fishing tables: see fishsimultedata.h.
// MS2-UNIT: ?\fishsimultedata.cpp
// MS2-RANGE: 0x1403b0e30-0x1403b72d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$MS2Ptr@VCFishData@@@@QEBAPEAVCFishData@@XZ 0x1403b3c80 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCFishingRodData@@@@QEBAPEAVCFishingRodData@@XZ 0x1403b3c90 ; order
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@QEAAAEAV0@AEBUUnk_BmNewTag@@@Z 0x1403b3f40 ; unique
// MS2-PIN: ?GetTextFilter@CFishingTable@@SAPEAVUnk_FishTextFilter@@XZ 0x1403b4750 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCFishData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFishData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1403b47b0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCFishingRodData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFishingRodData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1403b48a0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCFishingSpotData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFishingSpotData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1403b4990
// MS2-PIN: ??_7CFishingTable@@6B?$TSingleton@VCFishingTable@@@@@ 0x142d34710
// MS2-PIN: ??_7CFishingTable@@6B?$CValidData@VCFishingTable@@@@@ 0x142d34720
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\fishsimultedata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "fishsimultedata.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----
bool FUN_14028f710(Unk_140165cf0* pElem);                   // the node is a usable element
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_CommonLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_CommonLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
CStringTable* FUN_1401a9d70();                              // the string table singleton
CStringW FUN_14028b8e0(const CStringW& strKey);             // string table text
CStringW FUN_14028de60(int nStringId);                      // string table text by id
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, int* pnOut);             // rank
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);        // string attribute
int FUN_14015f480(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<CStringW>& rOut);   // list of strings
void FUN_140177e10(const CString& str, ATL::CAtlArray<int>& rOut, const wchar_t* pszSep);    // split into numbers
void FUN_140274fc0(const CStringW& str, ATL::CAtlArray<unsigned int>* pOut, const wchar_t* pszSep);   // split a list of ids
void FUN_1416fbf20(Unk_FishTextFilter* pFilter, CStringW& str);   // post-process a UI text

// The unit's exe globals are in symbols-manual.tsv; the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CFishingTable::s_bInit;
Unk_FishTextFilter* CFishingTable::s_pTextFilter;
#endif

// ---- CFishSimulteData ----

// @0x1403b39f0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CFishSimulteData::~CFishSimulteData()
{
}

// @0x1403b0e30
CFishSimulteData::CFishSimulteData()
    : m_n18(0), m_n1c(0), m_n20(0)
{
    memset(m_aN24, 0, sizeof(m_aN24));
}

// @0x1403b0ea0
void CFishSimulteData::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_n18);
    out.vfunc_o10_3(m_n1c);
    out.vfunc_o10_3(m_n20);
    for (size_t i = 0; i < 4; i++)
        out.vfunc_o10_3(m_aN24[i]);
}

// @0x1403b0f50
void CFishSimulteData::Read(CByteBuffer& in)
{
    m_n18 = in.vfunc_o8_3();
    m_n1c = in.vfunc_o8_3();
    m_n20 = in.vfunc_o8_3();
    for (size_t i = 0; i < 4; i++)
        m_aN24[i] = in.vfunc_o8_3();
}

// ---- CFishData ----

// @0x1403b39d0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CFishData::~CFishData()
{
}

// @0x1403b1040
CFishData::CFishData()
    : m_nId(0), m_nMastery(0), m_nHabitat(8), m_nRank(0), m_nIgnoreSpotMastery(0), m_nFishingBook(1), m_nCompanion(0)
{
}

// @0x1403b1100
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishData::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "id", m_nId);
    FUN_140873220(pNode, "fishMastery", m_nMastery);
    FUN_14015f500(pNode, "rank", &m_nRank);
    FUN_1408731e0(pNode, "ignoreSpotMastery", m_nIgnoreSpotMastery);
    FUN_1408731e0(pNode, "fishingBook", m_nFishingBook);
    FUN_140873220(pNode, "companion", m_nCompanion);
    CStringW strHabitat;
    FUN_140873420(pNode, "habitat", strHabitat);
    m_nHabitat = CFishingTable::GetInstance()->FUN_1403b1f70(strHabitat);
    ATL::CAtlArray<int> arr;
    CString strSmall;
    FUN_140873ad0(pNode, "smallSize", strSmall);
    FUN_140177e10(strSmall, arr, L"-");
    if (arr.GetCount() != 2)
        return 0;
    int nSmallMax = arr[1];
    m_aSize[0].FUN_140303060(arr[0], arr[1] - 1);
    arr.RemoveAll();
    CString strBig;
    FUN_140873ad0(pNode, "bigSize", strBig);
    FUN_140177e10(strBig, arr, L"-");
    if (arr.GetCount() != 2)
        return 0;
    int nBigMin = arr[0];
    int nBigMax = arr[1];
    m_aSize[2].FUN_140303060(arr[0], arr[1] - 1);
    m_aSize[1].FUN_140303060(nSmallMax, nBigMin - 1);
    m_aSize[3].FUN_140303060(nBigMax, nBigMax * 10);
    return 1;
}

// @0x1403b14d0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
bool CFishData::FUN_1403b14d0(unsigned nSize) const
{
    return m_aSize[3].m_nMin <= nSize;
}

// @0x1403b1520
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
unsigned __int64 CFishData::FUN_1403b1520(unsigned nSize) const
{
    for (unsigned __int64 i = 0; i <= 3; i++)
    {
        if (m_aSize[i].FUN_1403b4ef0(nSize))
            return i;
    }
    return 4;
}

// @0x1403b1590
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishData::FUN_1403b1590(unsigned nSize) const
{
    int nClass = (int)FUN_1403b1520(nSize);
    if (nClass == 0)
        return 1;
    if (nClass == 1)
        return 2;
    if (nClass == 2 || nClass == 3)
        return 3;
    return 0;
}

// @0x1403b1600
CStringW CFishData::FUN_1403b1600() const
{
    return StringFormat(L"./Data/Resource/Image/Fishing/{0}.png", m_nId);
}

// @0x1403b1650
CStringW CFishData::FUN_1403b1650() const
{
    return FUN_1401a9d70()->FUN_141811980(0x1d, m_nId);
}

// @0x1403b16b0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CStringW CFishData::FUN_1403b16b0(int bDetail) const
{
    CStringW str;
    if (m_nHabitat != 7)
    {
        str = FUN_14028b8e0(CStringW(L"s_fishing_fish_habitat"));
        CStringW strMaps = CFishingTable::GetInstance()->FUN_1403b2ee0(m_nId);
        if (strMaps.GetLength() == 0)
            str += FUN_14028b8e0(CStringW(L"s_fishing_fish_habitat_unknown"));
        else
        {
            str += strMaps;
            str += FUN_14028b8e0(CStringW(L"s_fishing_fish_habitat_more"));
        }
    }
    if (bDetail == 0)
        str += FUN_1401a9d70()->FUN_141811980(0x1e, m_nId);
    else
        str += FUN_1401a9d70()->FUN_141811980(0x1f, m_nId);
    FUN_1416fbf20(CFishingTable::GetTextFilter(), str);
    return str;
}

// ---- CFishingRodData ----

// @0x1403b3a10
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CFishingRodData::~CFishingRodData()
{
}

// @0x1403b1980
CFishingRodData::CFishingRodData()
    : m_nRodCode(0), m_nMasteryLimit(0), m_nAddMastery(0), m_nReduceTime(0)
{
}

// @0x1403b1a20
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
bool CFishingRodData::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "rodCode", m_nRodCode);
    FUN_140873220(pNode, "fishMasteryLimit", m_nMasteryLimit);
    FUN_140873220(pNode, "addFishMastery", m_nAddMastery);
    FUN_140873220(pNode, "reduceFishingTime", m_nReduceTime);
    FUN_140873ad0(pNode, "chair", m_strChair);
    FUN_140873ad0(pNode, "fishLureEffect", m_strLureEffect);
    FUN_140873ad0(pNode, "fishingChairEffect", m_strChairEffect);
    return m_nRodCode != 0;
}

// ---- CFishingSpotData ----

// @0x1403b3a60
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CFishingSpotData::~CFishingSpotData()
{
}

// @0x1403b1b20
CFishingSpotData::CFishingSpotData()
    : m_nId(0), m_nMinMastery(0), m_nMaxMastery(0)
{
}

// @0x1403b1b90
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
bool CFishingSpotData::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "id", m_nId);
    FUN_140873220(pNode, "minMastery", m_nMinMastery);
    FUN_140873220(pNode, "maxMastery", m_nMaxMastery);
    ATL::CAtlArray<CStringW> arr;
    FUN_14015f480(pNode, "liquidType", arr);
    m_arrLiquid.RemoveAll();
    for (size_t i = 0; i < arr.GetCount(); i++)
    {
        int nHabitat = CFishingTable::GetInstance()->FUN_1403b1f70(arr[i]);
        if (nHabitat != 8)
            m_arrLiquid.Add(nHabitat);
    }
    return m_nId != 0;
}

// ---- CFishingTable ----

// @0x1403b1d00
CFishingTable::CFishingTable()
    : m_mapFish(17, 0.75f, 0.25f, 2.25f, 10)
    , m_mapRod(17, 0.75f, 0.25f, 2.25f, 10)
    , m_mapSpot(17, 0.75f, 0.25f, 2.25f, 10)
    , m_mapMaps(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1403b1e60
CFishingTable::~CFishingTable()
{
}

// @0x1403b1f00
int CFishingTable::Load()
{
    if (!LoadFish())
        return 0;
    if (!LoadRods())
        return 0;
    if (!LoadSpots())
        return 0;
    if (!LoadHabitats())
        return 0;
    SetInit(true);
    return 1;
}

// @0x1403b1f70
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishingTable::FUN_1403b1f70(const CStringW& strHabitat)
{
    if (strHabitat == L"water")
        return 0;
    if (strHabitat == L"seawater")
        return 1;
    if (strHabitat == L"poison")
        return 3;
    if (strHabitat == L"lava")
        return 2;
    if (strHabitat == L"oil")
        return 4;
    if (strHabitat == L"devilwater")
        return 5;
    if (strHabitat == L"emeraldwater")
        return 6;
    if (strHabitat == L"all")
        return 7;
    return 8;
}

// @0x1403b20b0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CStringW CFishingTable::FUN_1403b20b0(int nHabitat)
{
    switch (nHabitat)
    {
    case 0:
        return FUN_14028de60(0xbd0);
    case 1:
        return FUN_14028de60(0xbd1);
    case 2:
        return FUN_14028de60(0xbd3);
    case 3:
        return FUN_14028de60(0xbd2);
    case 4:
        return FUN_14028de60(0xbd4);
    case 5:
        return FUN_14028de60(0xbd5);
    case 6:
        return FUN_14028de60(0xbd6);
    default:
        return L"";
    }
}

// @0x1403b2240
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CStringW CFishingTable::FUN_1403b2240(int n)
{
    return FUN_14028de60(n + 0xbba);
}

// @0x1403b22a0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishingTable::LoadSpots()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("fishingSpot.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("spot"); pNode != 0; pNode = pNode->FUN_140168650("spot"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        CFishingSpotDataPtr spData(new CFishingSpotData);
        if (spData->Load(pNode))
            m_mapSpot.SetAt(spData->m_nId, spData);
    }
    return 1;
}

// @0x1403b2540
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishingTable::LoadFish()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("fish.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("fish"); pNode != 0; pNode = pNode->FUN_140168650("fish"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        CFishDataPtr spData(new CFishData);
        if (spData->Load(pNode))
            m_mapFish.SetAt(spData->m_nId, spData);
    }
    return 1;
}

// @0x1403b27e0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishingTable::LoadRods()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("fishingRod.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("rod"); pNode != 0; pNode = pNode->FUN_140168650("rod"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nId = 0;
        FUN_140873220(pNode, "rodCode", nId);
        CFishingRodDataPtr spData(new CFishingRodData);
        if (spData->Load(pNode))
            m_mapRod.SetAt(nId, spData);
    }
    return 1;
}

// @0x1403b2a80
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CFishingTable::LoadHabitats()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("fishHabitat.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("fish"); pNode != 0; pNode = pNode->FUN_140168650("fish"))
    {
        unsigned nId = 0;
        CStringW strHabitat;
        FUN_140873220(pNode, "id", nId);
        FUN_140873420(pNode, "habitat", strHabitat);
        CFishMapIdsPtr spMaps(0);
        if (!m_mapMaps.Lookup(nId, spMaps))
        {
            spMaps = Unk_BmNewTag(0);
            m_mapMaps.SetAt(nId, spMaps);
        }
        FUN_140274fc0(strHabitat, spMaps.get(), L", ");
    }
    return 1;
}

// @0x1403b2d30
CFishDataPtr CFishingTable::GetFish(int nId)
{
    CheckInit();
    CFishDataPtr spData(0);
    m_mapFish.Lookup(nId, spData);
    return spData;
}

// @0x1403b2dc0
CFishingRodDataPtr CFishingTable::GetRod(int nId)
{
    CheckInit();
    CFishingRodDataPtr spData(0);
    m_mapRod.Lookup(nId, spData);
    return spData;
}

// @0x1403b2e50
CFishingSpotDataPtr CFishingTable::GetSpot(int nId)
{
    CheckInit();
    CFishingSpotDataPtr spData(0);
    m_mapSpot.Lookup(nId, spData);
    return spData;
}

// @0x1403b2ee0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
CStringW CFishingTable::FUN_1403b2ee0(unsigned nFishId)
{
    CheckInit();
    int nCount = 0;
    CStringW str;
    CFishMapIdsPtr spMaps(0);
    if (m_mapMaps.Lookup(nFishId, spMaps))
    {
        for (size_t i = 0; i < spMaps->GetCount(); i++)
        {
            unsigned nMapId = (*spMaps)[i];
            MS2Ptr<CFieldData> spMap = CFieldData::FUN_140374140(nMapId);
            if (!!spMap)
            {
                if (str.GetLength() != 0)
                    str += L", ";
                str += StringFormat(L"$map:{0}$", nMapId);
                nCount++;
                if (nCount > 2)
                    break;
            }
        }
    }
    return str;
}

// @0x1403b30b0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
void CFishingTable::FUN_1403b30b0(ATL::CAtlArray<unsigned int>* pOut, int nHabitat, int bBookOnly)
{
    CheckInit();
    for (POSITION pos = m_mapFish.GetStartPosition(); pos != 0; m_mapFish.GetNext(pos))
    {
        CFishDataPtr spData = m_mapFish.GetValueAt(pos);
        if (spData->m_nHabitat == nHabitat)
        {
            if (bBookOnly != 0 && spData->m_nFishingBook == 0)
                continue;
            pOut->Add(spData->m_nId);
        }
    }
}

// @0x1403b3f70
void CFishingTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CFishingTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1403b4ef0
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
bool Unk_FishRange::FUN_1403b4ef0(unsigned n) const
{
    if (n < m_nMin)
        return false;
    if (m_nMax < n)
        return false;
    return true;
}

// @0x1403b6cf0
void CFishingTable::SetInit(bool b)
{
    s_bInit = b;
}

MS2_EMIT_CRT_MEMMOVE_S();
