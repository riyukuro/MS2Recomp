// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 6 of unit_1413a9df0: the template glue of the guide-condition
// TU. The enum formatter machinery (fmt::internal::MakeValue / make_type / format_arg of five unit-local enums), the
// StringFormat instances the conditions describe themselves with, the UI dialog finders and the XML attribute readers.
// MS2-UNIT: unit_1413a9df0#6
// MS2-RANGE: 0x1413afcb0-0x1413b28e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0W4Unk_GcEnum1@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_GcEnum1@@@Z 0x1413afcb0 ; prop
// MS2-PIN: ??$?0W4Unk_GcModeId@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_GcModeId@@@Z 0x1413afce0 ; prop
// MS2-PIN: ??$?0W4Unk_GcAchieveType@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_GcAchieveType@@@Z 0x1413afd10 ; prop
// MS2-PIN: ??$StringFormat@W4Unk_GcEnum1@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBW4Unk_GcEnum1@@@Z 0x1413b13d0 ; prop
// MS2-PIN: ??$StringFormat@W4Unk_GcModeId@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBW4Unk_GcModeId@@@Z 0x1413b1470 ; prop
// MS2-PIN: ??$StringFormat@W4Unk_GcAchieveType@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBW4Unk_GcAchieveType@@@Z 0x1413b1510 ; prop
// MS2-PIN: ??$StringFormat@W4Unk_GcItemType@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBW4Unk_GcItemType@@@Z 0x1413b15b0 ; prop
// MS2-PIN: ??$FormatCustomArg@W4Unk_GcEnum1@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x1413b2620 ; prop
// MS2-PIN: ??$FormatCustomArg@W4Unk_GcModeId@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x1413b2650 ; prop
// MS2-PIN: ??$FormatCustomArg@W4Unk_GcAchieveType@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x1413b2680 ; prop
// MS2-PIN: ??$make_type@W4Unk_GcEnum1@@@internal@fmt@@YA_KAEBW4Unk_GcEnum1@@@Z 0x1413b2710 ; prop
// MS2-PIN: ??$make_type@W4Unk_GcAchieveType@@@internal@fmt@@YA_KAEBW4Unk_GcAchieveType@@@Z 0x1413b2750 ; prop
// MS2-PIN: ??$make_type@W4Unk_GcIconType@@@internal@fmt@@YA_KAEBW4Unk_GcIconType@@@Z 0x1413b2770 ; unique
// MS2-PIN: ??$make_type@W4Unk_GcItemType@@@internal@fmt@@YA_KAEBW4Unk_GcItemType@@@Z 0x1413b2790 ; unique
// MS2-PIN: ??$type@W4Unk_GcEnum1@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_GcEnum1@@@Z 0x1413b27b0 ; prop
// MS2-PIN: ??$type@W4Unk_GcModeId@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_GcModeId@@@Z 0x1413b27c0 ; prop
// MS2-PIN: ??$type@W4Unk_GcAchieveType@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_GcAchieveType@@@Z 0x1413b27d0 ; prop
// MS2-PIN: ??$type@W4Unk_GcIconType@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_GcIconType@@@Z 0x1413b27e0 ; prop
// MS2-PIN: ??$type@W4Unk_GcItemType@@$0A@@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBW4Unk_GcItemType@@@Z 0x1413b27f0 ; prop
// MS2-PIN: ??0?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x1413b2800 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <sstream>

// The dialog headers declare the server time getter 0x140869440 with a signed result; the unit header's view is unsigned.
#define FUN_140869440 Unk_FUN_140869440_signed
#include "ms2/client/ms2/uichatemoticondialog.h"
#include "ms2/client/ms2/uiitemenchantdialog.h"
#include "ms2/placeholder/partyuidialogs.h"
#undef FUN_140869440
#include "ms2/unnamed/unit_1413a9df0.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

// ---- enum formatter customization ---------------------------------------------------------------------------------------------
// fmt's ostream formatting of a custom argument with the MS2 enum shortcut in front (see itembreakmanager.cpp, 0x140534820):
// the stream branch is dead code for enums but keeps the stack cookie and scratch locals.
#define GC_FORMAT_ARG(E) \
    template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const E& value) \
    { \
        internal::Arg arg; \
        internal::Value& arg_value = arg; \
        if (std::is_enum<E>::value) \
        { \
            arg.int_value = value; \
            arg.type = internal::Arg::INT; \
        } \
        else \
        { \
            std::basic_ostringstream<wchar_t> os; \
            os << value; \
            std::basic_string<wchar_t> str = os.str(); \
            arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str); \
            arg.type = internal::Arg::STRING; \
        } \
        format_str = f.format(format_str, arg); \
    }
// @0x1413b2080
GC_FORMAT_ARG(Unk_GcEnum1)
// @0x1413b21a0
GC_FORMAT_ARG(Unk_GcModeId)
// @0x1413b22c0
GC_FORMAT_ARG(Unk_GcAchieveType)
// @0x1413b23e0
GC_FORMAT_ARG(Unk_GcIconType)
// @0x1413b2500
GC_FORMAT_ARG(Unk_GcItemType)

// ---- StringFormat instances ---------------------------------------------------------------------------------------------------
// The exe has one out-of-line copy per argument-type list; the conditions call them through the extern templates.
template CStringW StringFormat<int, unsigned, unsigned>(const wchar_t*, const int&, const unsigned&, const unsigned&);     // @0x1413afe00
template CStringW StringFormat<int, float, int>(const wchar_t*, const int&, const float&, const int&);                   // @0x1413b0180
template CStringW StringFormat<int, bool, bool>(const wchar_t*, const int&, const bool&, const bool&);                   // @0x1413b0500
template CStringW StringFormat<unsigned, CStringA, unsigned, unsigned, unsigned>(const wchar_t*, const unsigned&, const CStringA&, const unsigned&, const unsigned&, const unsigned&);   // @0x1413b0880
template CStringW StringFormat<unsigned, Unk_GcItemType, Unk_GcIconType>(const wchar_t*, const unsigned&, const Unk_GcItemType&, const Unk_GcIconType&);   // @0x1413b0c80
template CStringW StringFormat<float, float, float, float>(const wchar_t*, const float&, const float&, const float&, const float&);   // @0x1413b1000
template CStringW StringFormat<Unk_GcEnum1>(const wchar_t*, const Unk_GcEnum1&);                                          // @0x1413b13d0
template CStringW StringFormat<Unk_GcModeId>(const wchar_t*, const Unk_GcModeId&);                                        // @0x1413b1470
template CStringW StringFormat<Unk_GcAchieveType>(const wchar_t*, const Unk_GcAchieveType&);                              // @0x1413b1510
template CStringW StringFormat<Unk_GcItemType>(const wchar_t*, const Unk_GcItemType&);                                    // @0x1413b15b0
template CStringW StringFormat<Unk_GcItemType, int, int>(const wchar_t*, const Unk_GcItemType&, const int&, const int&);   // @0x1413b1650

// ---- the dialog finders and the dialog value lookup ---------------------------------------------------------------------------
// The UI manager hands out a reference object (refcount block + object); the finders downcast the held object.
class Unk_GcUIRef
{
public:
    ~Unk_GcUIRef();                                         // 0x1403e5630
    UIObject* FUN_1403e8a70() const;                        // the held object, 0 = none
    void* m_pRc; UIObject* m_pObj;
};
MS2_CHECK_SIZE(Unk_GcUIRef, 0x10);
void* FUN_1403ed2b0();                                      // the UI manager
struct Unk_GcUiMgrId { Unk_GcUIRef FUN_141adcea0(int nUIId); };
struct Unk_GcUiMgrName { Unk_GcUIRef FUN_141adcf50(const CString& strName); };
UIObject* FUN_1403ed9e0(Unk_GcUIRef& ref);

// A parsed dialog tree node (40 bytes; the destructor is 0x140614800).
class Unk_GcNode
{
public:
    ~Unk_GcNode();
    char m_buf[40];
};
MS2_CHECK_SIZE(Unk_GcNode, 0x28);
void FUN_1422baa20(void* pInner, Unk_GcNode* pOut, const char* pszName);
char FUN_1409b4d40(Unk_GcNode* pNode);
void FUN_140d02f80(Unk_G9Val* pOut, int nNull);
void FUN_140d01be0(Unk_G9Val* pOut, int nIdx, Unk_GcNode* pNode);
char FUN_140ba28d0(void* pList, void* pNull);
void* FUN_1409ee290(void* pList);

// @0x1413b19d0
Unk_G9Val* FUN_1413b19d0(void* pInner, Unk_G9Val* pOut, const CString* pName)
{
    Unk_GcNode node;
    FUN_1422baa20(pInner, &node, *pName);
    if (!FUN_1409b4d40(&node))
        FUN_140d02f80(pOut, 0);
    else
        FUN_140d01be0(pOut, *(int*)((char*)pInner + 0x18), &node);
    return pOut;
}

// @0x1413b1a90
void FUN_1413b1a90(void* pDialog, Unk_G9Val* pOut, const CString* pChild)
{
    void* pList = (char*)pDialog + 0x30;
    if (!FUN_140ba28d0(pList, 0))
        FUN_1413b19d0(FUN_1409ee290(pList), pOut, pChild);
    else
        FUN_140d02f80(pOut, 0);
}

// @0x1413b1b20
void* FUN_1413b1b20(unsigned nUIId)
{
    if (FUN_1403ed2b0())
    {
        Unk_GcUIRef ref = reinterpret_cast<Unk_GcUiMgrId*>(FUN_1403ed2b0())->FUN_141adcea0(nUIId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIChatEmoticonDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x1413b1bc0
void* FUN_1413b1bc0(unsigned nUIId)
{
    if (FUN_1403ed2b0())
    {
        Unk_GcUIRef ref = reinterpret_cast<Unk_GcUiMgrId*>(FUN_1403ed2b0())->FUN_141adcea0(nUIId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIItemEnchantDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x1413b1c60
void* FUN_1413b1c60(const CStringA& strName)
{
    if (FUN_1403ed2b0())
    {
        Unk_GcUIRef ref = reinterpret_cast<Unk_GcUiMgrName*>(FUN_1403ed2b0())->FUN_141adcf50(strName);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIPartyDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// ---- the XML attribute readers --------------------------------------------------------------------------------------------------
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_140873890(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CStringA& strOut);
int FUN_1408730a0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
int FUN_140874670(Unk_140165cf0* pElem, const char* pszName, Unk_StreamPoint& ptOut);
void FUN_1413747d0(Unk_GcOptInt* pOpt);                     // reset to unset
void FUN_1413b5850(Unk_GcOptVec3* pOpt);
void FUN_1413b5860(Unk_GcOptBool* pOpt);
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);
size_t FUN_140186260(ATL::CAtlArray<int>& arr);
int* FUN_1401844d0(ATL::CAtlArray<int>& arr, size_t i);
void FUN_1405c6380(void* pOut, int a, int b);
int FUN_14138a170(const CStringA& str);
extern char DAT_142f01338;                                  // the separator string

// @0x1413b1d00
int FUN_1413b1d00(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptInt& oOut)
{
    FUN_1413747d0(&oOut);
    int n;
    int nResult = FUN_1408731e0(pElem, pszName, n);
    if (nResult == 0)
        new (&oOut) Unk_GcOptInt(n);
    return nResult;
}

// @0x1413b1d60
int FUN_1413b1d60(Unk_140165cf0* pElem, const char* pszName, void* pOut)
{
    CStringA str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult == 0)
    {
        ATL::CAtlArray<int> arr;
        FUN_140177de0(str, arr, &DAT_142f01338);
        if (FUN_140186260(arr) != 2)
            return 2;
        int* pSecond = FUN_1401844d0(arr, 1);
        int* pFirst = FUN_1401844d0(arr, 0);
        FUN_1405c6380(pOut, *pFirst, *pSecond);
    }
    return nResult;
}

// @0x1413b1e70
int FUN_1413b1e70(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptVec3& oOut)
{
    FUN_1413b5850(&oOut);
    Unk_StreamPoint pt;
    int nResult = FUN_140874670(pElem, pszName, pt);
    if (nResult == 0)
        new (&oOut) Unk_GcOptVec3(pt);
    return nResult;
}

// @0x1413b1ed0
int FUN_1413b1ed0(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptBool& oOut)
{
    FUN_1413b5860(&oOut);
    bool b;
    int nResult = FUN_1408730a0(pElem, pszName, b);
    if (nResult == 0)
        new (&oOut) Unk_GcOptBool(b);
    return nResult;
}

// @0x1413b1f30
int FUN_1413b1f30(Unk_140165cf0* pElem, const char* pszName, int& nOut)
{
    int n = 0;
    int nResult = FUN_140873890(pElem, pszName, n);
    if (nResult == 0)
        nOut = n;
    return nResult;
}

// @0x1413b1fc0
int FUN_1413b1fc0(Unk_140165cf0* pElem, const char* pszName, int& nOut)
{
    CStringA str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult == 0)
        nOut = FUN_14138a170(str);
    return nResult;
}

// ---- small helpers ----------------------------------------------------------------------------------------------------------------
// The out-of-line default constructors of the optional members (called by the condition constructors of part 3).
// (no source of their own: the instances are emitted where a member is default-constructed, so this scratch function uses them)
void Unk_GcOptScratch()
{
    Unk_GcOptInt oInt;
    Unk_GcOptBool oBool;
    FUN_1413747d0(&oInt);
    FUN_1413b5860(&oBool);
}

// @0x1413b2880
Unk_GcCondRef* Unk_GcCondRef::FUN_1413b2880(Unk_GcCondRef& rhs)
{
    m_p = rhs.m_p;
    rhs.m_p = 0;
    return this;
}

// @0x1413b28b0
Unk_GcCondRef* Unk_GcCondRef::FUN_1413b28b0(CGuideCondition* pCond)
{
    m_p = pCond;
    FUN_141388ed0();
    return this;
}
