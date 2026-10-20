// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SetItemTable: the equipment set table (Table/SetItemInfo.xml)
// with the SetItemInfo rows it holds in an ATL::CAtlMap<int, MS2Ptr<SetItemInfo>> and the multimap from a piece item id
// to its sets.
// MS2-UNIT: ?\setitemtable.cpp
// MS2-RANGE: 0x1400bc830-0x1400bc9c0 .text$di
// MS2-RANGE: 0x1407c4980-0x1407c9f40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAV?$MS2Ptr@VSetItemInfo@@@@$0A@@?$pair@HV?$MS2Ptr@VSetItemInfo@@@@@std@@QEAA@AEAHAEAV?$MS2Ptr@VSetItemInfo@@@@@Z 0x1407c5310 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VSetItemInfo@@@@$0A@@?$pair@$$CBIV?$MS2Ptr@VSetItemInfo@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VSetItemInfo@@@@@1@@Z 0x1407c5450 ; unique
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VSetItemInfo@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VSetItemInfo@@@@@0@AEAHAEAV?$MS2Ptr@VSetItemInfo@@@@@Z 0x1407c6c30 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VSetItemInfo@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VSetItemInfo@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1407c79e0 ; unique
// MS2-PIN: ?push_back@?$vector@V?$MS2Ptr@VSetItemInfo@@@@V?$allocator@V?$MS2Ptr@VSetItemInfo@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VSetItemInfo@@@@@Z 0x1407c9df0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7SetItemTable@@6B?$TSingleton@VSetItemTable@@@@@ 0x142d8e138
// MS2-PIN: ??_7SetItemTable@@6B?$CValidData@VSetItemTable@@@@@ 0x142d8e148
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\setitemtable.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>
#include "ms2/placeholder/setitemtable.h"
#include "logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
// The two-argument log call (an FMT_VARIADIC instantiation, ?\characterability.cpp).
void FUN_1401e0850(CLogString* log, int level, int category, const wchar_t* format, const CString& first,
                   const unsigned& second);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);     // undecorated class name
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
void* FUN_1406aeee0();
bool FUN_1406af060(void* p);

// The unit's init flag is an exe global (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool SetItemTable::s_bInit;
#endif

// The name tables of the market sort enums this TU gets from its shared header.
// @0x1400bc830
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400bc8f0
static CString s_premiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// The UCRT's `static __inline memcpy_s` copy of this TU (kept alive by the pointer below).
// @0x1407c9e20
// MS2-FUNCTIONAL: CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_sit_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnSitMemcpyS)(void*, size_t, const void*, size_t) = &ms2_sit_memcpy_s;

// @0x1407c4980
SetItemTable::SetItemTable()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1407c4a50
SetItemTable::~SetItemTable()
{
}

// @0x1407c4ae0
int SetItemTable::Load()
{
    if (LoadSets() == 0)
        return 0;
    if (FUN_1407c52d0() == 0)
        return 0;
    SetInit(true);
    return 1;
}

// @0x1407c4b30
// MS2-FUNCTIONAL: temporaries/EH state layout differs (46 bytes larger)
int SetItemTable::LoadSets()
{
    m_map.RemoveAll();
    CString strPath = FUN_14071a5b0(CString("Table"), CString("SetItemInfo.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "set", "id", &nodes);
    for (unsigned i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        SetItemInfoPtr spInfo(new SetItemInfo);
        if (!spInfo->FUN_1407ad2f0(pNode))
            return 0;
        if (m_map.Lookup(spInfo->FUN_1407ad550()) != 0)
        {
            unsigned nSetId = spInfo->FUN_1407ad550();
            FUN_1401e0850(FUN_140166440(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[<ms2> {0}] SetID is Duplicated, setID = {1}", strPath, nSetId);
            return 0;
        }
        std::vector<unsigned>& items = spInfo->FUN_1407ad710();
        std::vector<unsigned>::iterator itEnd = items.end();
        for (std::vector<unsigned>::iterator it = items.begin(); it != itEnd; ++it)
        {
            int nItemId = *it;
            m_byItem.insert(std::make_pair(nItemId, spInfo));
        }
        m_map.SetAt(spInfo->FUN_1407ad550(), spInfo);
    }
    return 1;
}

// @0x1407c5020
// MS2-FUNCTIONAL: prologue/temporary layout differs by a byte
bool FUN_1407c5020()
{
    void* p = FUN_1406aeee0();
    return FUN_1406af060(p);
}

// @0x1407c5050
SetItemInfoPtr SetItemTable::GetSetItemInfo(int nSetId)
{
    CheckInit();
    SetItemInfoPtr spInfo;
    m_map.Lookup(nSetId, spInfo);
    return spInfo;
}

// @0x1407c50e0
void SetItemTable::FUN_1407c50e0(int nSetId, void* pOut)
{
    CheckInit();
    SetItemInfoPtr spInfo = GetSetItemInfo(nSetId);
    if (spInfo.get() != 0)
        spInfo->FUN_1407ad670((ATL::CAtlArray<unsigned>*)pOut);
}

// @0x1407c5160
// MS2-FUNCTIONAL: temporary/EH layout differs
bool SetItemTable::FUN_1407c5160(int nSetId)
{
    SetItemInfoPtr spInfo;
    if (m_map.Lookup(nSetId, spInfo) == 0)
        return false;
    return spInfo->FUN_1407ad600();
}

// @0x1407c51f0
// MS2-FUNCTIONAL: iterator temporaries differ (84 vs 90 bytes)
bool SetItemTable::HasSetItem(unsigned nItemId) const
{
    std::multimap<unsigned, SetItemInfoPtr>::const_iterator itEnd = m_byItem.end();
    return m_byItem.find(nItemId) != itEnd;
}

// @0x1407c5250
// MS2-FUNCTIONAL: iterator temporaries differ (118 vs 120 bytes)
void SetItemTable::GetSetItemInfos(unsigned nItemId, std::vector<SetItemInfoPtr>& sets)
{
    CheckInit();
    std::pair<std::multimap<unsigned, SetItemInfoPtr>::iterator, std::multimap<unsigned, SetItemInfoPtr>::iterator> range = m_byItem.equal_range(nItemId);
    while (range.first != range.second)
    {
        sets.push_back(range.first->second);
        ++range.first;
    }
}

// @0x1407c52d0
int SetItemTable::FUN_1407c52d0()
{
    return 1;
}

// @0x1407c7710
void SetItemTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(SetItemTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1407c8620
void SetItemTable::SetInit(bool b)
{
    s_bInit = b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9bf00-0x142c9bf60 .text$yd
