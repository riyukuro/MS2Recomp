// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 6 of unit_1413a9df0: the template glue of the guide-condition
// TU. The enum formatter machinery (fmt::internal::MakeValue / make_type / format_arg of five unit-local enums), the
// StringFormat instances the conditions describe themselves with, the UI dialog finders and the XML attribute readers.
// MS2-UNIT: unit_1413a9df0#6
// MS2-RANGE: 0x1413afcb0-0x1413b2880 .text$mn
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
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/uiservice.h"
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0

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

// @0x1413b19d0
template <> MS2Ptr<ASDisplayObject> AScript::FUN_140e159f0<ASDisplayObject>(const CString& strName)
{
    Scaleform::GFx::Value node = GetMember(strName);
    if (node.IsObject())
        return FUN_140d01be0(m_nMovieId, node);
    return MS2Ptr<ASDisplayObject>(0);
}

// @0x1413b1a90
template <> MS2Ptr<ASDisplayObject> UISwfEntity::GetChild<ASDisplayObject>(const CString& strChild)
{
    if (m_30 == 0)
        return MS2Ptr<ASDisplayObject>(0);
    return m_30->FUN_140e159f0<ASDisplayObject>(strChild);
}

// @0x1413b1b20
void* FUN_1413b1b20(unsigned nUIId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUIId);
        if (ref.get())
            return dynamic_cast<UIChatEmoticonDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x1413b1bc0
void* FUN_1413b1bc0(unsigned nUIId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUIId);
        if (ref.get())
            return dynamic_cast<UIItemEnchantDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x1413b1c60
void* FUN_1413b1c60(const CStringA& strName)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObjectByName(strName);
        if (ref.get())
            return dynamic_cast<UIPartyDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// ---- the XML attribute readers --------------------------------------------------------------------------------------------------
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, efd::Point3&);   // C3: was FUN_140874670
void FUN_1413747d0(unsigned char*);   // C3: was FUN_1413747d0
void Unk_GcClear0(char*);   // C3: was FUN_1413b5850
void Unk_GcClear1(char*);   // C3: was FUN_1413b5860
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177de0
class Unk_MergeRange   // C3: member view for the former free stand-ins
{
public:
    void Set(int, int);
};
int FUN_14138a170(const CStringA& str);

// @0x1413b1d00
int FUN_1413b1d00(TiXmlElement* pElem, const char* pszName, Unk_GcOptInt& oOut)
{
    FUN_1413747d0((unsigned char*)(&oOut));
    int n;
    int nResult = XmlGetAttr((class TiXmlElement*)(pElem), pszName, n);
    if (nResult == 0)
        oOut = n;
    return nResult;
}

// @0x1413b1d60
int FUN_1413b1d60(TiXmlElement* pElem, const char* pszName, void* pOut)
{
    CStringA str;
    int nResult = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nResult == 0)
    {
        ATL::CAtlArray<int> arr;
        XmlSplit(str, arr, "-");
        if (((ATL::CAtlArray<int, ATL::CElementTraits<int>>*)&static_cast<class ATL::CAtlArray<int, class ATL::CElementTraits<int>>&>(arr))->GetCount() != 2)
            return 2;
        ((class Unk_MergeRange*)(void*)(pOut))->Set(arr[0], arr[1]);
    }
    return nResult;
}

// @0x1413b1e70
int FUN_1413b1e70(TiXmlElement* pElem, const char* pszName, Unk_GcOptVec3& oOut)
{
    Unk_GcClear0((char*)(&oOut));
    Vector3 pt;
    int nResult = XmlGetAttr((class TiXmlElement*)(pElem), pszName, reinterpret_cast<efd::Point3&>(pt));
    if (nResult == 0)
        oOut = pt;
    return nResult;
}

// @0x1413b1ed0
int FUN_1413b1ed0(TiXmlElement* pElem, const char* pszName, Unk_GcOptBool& oOut)
{
    Unk_GcClear1((char*)(&oOut));
    bool b;
    int nResult = XmlGetAttr((class TiXmlElement*)(pElem), pszName, b);
    if (nResult == 0)
        oOut = b;
    return nResult;
}

// @0x1413b1f30
int FUN_1413b1f30(TiXmlElement* pElem, const char* pszName, int& nOut)
{
    // the tinyxmlhelper.h template's compile-time-false guard (ASSERT(FALSE) of its line 231)
    if (false)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int n = 0;
    int nResult = XmlQuery((class TiXmlElement*)(pElem), pszName, n);
    if (nResult != 0)
        return nResult;
    nOut = n;
    return nResult;
}

// @0x1413b1fc0
int FUN_1413b1fc0(TiXmlElement* pElem, const char* pszName, int& nOut)
{
    // the tinyxmlhelper.h template's compile-time-false guard (ASSERT(FALSE) of its line 250)
    if (false)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CStringA str;
    int nResult = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nResult != 0)
        return nResult;
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
    FUN_1413747d0((unsigned char*)(&oInt));
    Unk_GcClear1((char*)(&oBool));
}
