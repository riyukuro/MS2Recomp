// xmlattr.h - PLACEHOLDER for the game's TinyXML attribute helpers (not an original header; names invented).
// The element type is the game TinyXML element (Unk_140165cf0, as the table units call it). The attribute readers
// return 0 when the attribute exists (TIXML_SUCCESS) and leave the output untouched otherwise.
// The list/enum helper templates and the child element iterator were instantiated first by
// ?\additionalactionadditional.cpp (0x140177cf0-0x140179460 and the iterator COMDATs at 0x140183390...).
#pragma once
#include <afx.h>
#include <assert.h>
#include <atlcoll.h>
#include <stdlib.h>
#include <set>
#include <string>
#include <type_traits>
#include <vector>
#include "ms2/ms2layout.h"

// TinyXML's own TiXmlString (reference to a rep {size, capacity, str[]}); the exe's c_str is this 18-byte accessor, not
// std::string::c_str (0x1401d4890).
struct Unk_TiXmlString
{
    struct Rep { size_t size; size_t capacity; char str[1]; };
    Rep* m_rep;
    const char* c_str() const { return m_rep->str; }
};

// Game TinyXML element. Only the members the helpers touch are modelled: TiXmlNode::value (TIXML_USE_STL) at +0x38.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);     // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);     // NextSiblingElement
    Unk_140165cf0* FUN_14086e8d0(const char* pszName);     // FirstChildElement (the tinyxmlhelper.h list readers' copy)
    Unk_140165cf0* FUN_14086e7e0(const char* pszName);     // NextSiblingElement (same)
    const Unk_140165cf0* NextSiblingElement() const;       // 0x14086e770 (TiXmlNode, any name)
    // @0x1403f0510 (TinyXML's non-const wrapper)
    Unk_140165cf0* NextSiblingElement() { return const_cast<Unk_140165cf0*>((const_cast<const Unk_140165cf0*>(this))->NextSiblingElement()); }
    // @0x140189180
    const char* Value() const { return m_value.c_str(); }
private:
    void* m_unk_00[7];
    Unk_TiXmlString m_value;            // +0x38
};

int FUN_1408730a0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
int FUN_1408731a0(Unk_140165cf0* pElem, const char* pszName, unsigned short& nOut);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);
int FUN_1408732a0(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);            // tick (duration) value
int FUN_1408732e0(Unk_140165cf0* pElem, const char* pszName, __int64& nOut);
int FUN_140873360(Unk_140165cf0* pElem, const char* pszName, float& fOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CStringA& strOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);
int FUN_140873890(Unk_140165cf0* pElem, const char* pszName, int& nOut);              // int or enum value
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);  // string attribute with default
void FUN_14015f050(const CString& str, ATL::CAtlArray<CString>& arr, const char* pszDelim);  // split into strings

// Iterates an element and its same-named siblings: `for (Unk_140165cf0* p : pParent->FUN_140165cf0("x"))`.
class Unk_XmlElementIterator
{
public:
    // @0x140183390
    Unk_XmlElementIterator(Unk_140165cf0* p) : m_p(p) {}
    // @0x1401833b0
    Unk_XmlElementIterator() : m_p(0) {}
    // @0x140184920
    Unk_140165cf0* operator*() const { return m_p; }
    // @0x140184c50
    Unk_XmlElementIterator& operator++() { m_p = m_p->FUN_140168650(m_p->Value()); return *this; }
    // @0x140184450
    bool operator!=(const Unk_XmlElementIterator& o) const { return m_p != o.m_p; }
private:
    Unk_140165cf0* m_p;
};
MS2_CHECK_SIZE(Unk_XmlElementIterator, 8);
// @0x14018ef30
inline Unk_XmlElementIterator begin(Unk_140165cf0* p) { return Unk_XmlElementIterator(p); }
// @0x14018f960
inline Unk_XmlElementIterator end(Unk_140165cf0*) { return Unk_XmlElementIterator(); }

// The templates below are untagged (their instantiations pair through symbols.tsv); keep them more than
// TAG_WINDOW lines below the end() tag, or a TU that never emits end() binds that tag to XmlConvert.

// Token conversion (0x140177cf0 unsigned short, 0x140177d20 int, 0x140177d50 unsigned, 0x140177d80 float).
template <class T> T XmlConvert(const CString& str) { return (T)atoi(str); }
template <> inline float XmlConvert<float>(const CString& str) { return (float)atof(str); }

// Splits a delimited list (0x140177e70 / 0x140177f30 / 0x140177ff0 / 0x1401780b0 for the arrays, 0x1401781a0 set,
// 0x140178300 / 0x1401783d0 / 0x1401784a0 vectors) and the forwarding wrappers in front of them.
template <class T> void XmlSplitImpl(const CString& str, ATL::CAtlArray<T>& arr, const char* pszDelim)
{
    int nPos = 0;
    CString strToken = str.Tokenize(pszDelim, nPos);
    while (!strToken.IsEmpty())
    {
        arr.Add(XmlConvert<T>(strToken));
        strToken = str.Tokenize(pszDelim, nPos);
    }
}
template <class T> void XmlSplitImpl(const CString& str, std::set<T>& set, const char* pszDelim)
{
    int nPos = 0;
    CString strToken = str.Tokenize(pszDelim, nPos);
    while (!strToken.IsEmpty())
    {
        set.insert(XmlConvert<T>(strToken));
        strToken = str.Tokenize(pszDelim, nPos);
    }
}
template <class T> void XmlSplitImpl(const CString& str, std::vector<T>& vec, const char* pszDelim)
{
    int nPos = 0;
    CString strToken = str.Tokenize(pszDelim, nPos);
    while (!strToken.IsEmpty())
    {
        vec.push_back(XmlConvert<T>(strToken));
        strToken = str.Tokenize(pszDelim, nPos);
    }
}
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim) { XmlSplitImpl(str, out, pszDelim); }

// Comma separated list attribute (0x140178570 CAtlArray<int>, 0x1401785f0 vector<int>, 0x140178670
// CAtlArray<unsigned>, 0x1401786f0 set<unsigned>, 0x140178770 vector<unsigned>, 0x1401787f0 CAtlArray<float>,
// 0x140178870 vector<float>).
template <class C> int XmlTokenList(Unk_140165cf0* pElem, const char* pszName, C& out)
{
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet == 0)
        XmlSplit(str, out, ",");
    return nRet;
}
// 0x1401788f0
template <> inline int XmlTokenList(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<CString>& out)
{
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet == 0)
        FUN_14015f050(str, out, ",");
    return nRet;
}

// The enum readers come from commonfiles\tinyxmlhelper.h: they start with a compile-time type guard whose failure
// branch asserts FALSE (with that header's __FILE__) and returns TIXML_WRONG_TYPE (2).
#define MS2_TINYXMLHELPER_FILE L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
#define MS2_TINYXMLHELPER_ASSERT(line, expression)                                                                \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), MS2_TINYXMLHELPER_FILE, (unsigned)(line)), 0))

// Enum attribute stored as a number (0x140178970-0x140178f10, one per enum type).
template <class E> int XmlValue(Unk_140165cf0* pElem, const char* pszName, E& eOut)
{
    if (!std::is_enum<E>::value)
    {
        MS2_TINYXMLHELPER_ASSERT(231, FALSE);
        return 2;
    }
    int nValue = 0;
    int nRet = FUN_140873890(pElem, pszName, nValue);
    if (nRet != 0)
        return nRet;
    eOut = (E)nValue;
    return nRet;
}

// tinyxmlhelper.h: enum attribute given by name (the parser is the enum's string converter).
template <class E, E (*Parse)(const CStringA&)>
int XmlEnumName(Unk_140165cf0* pElem, const char* pszName, E& eOut)
{
    if (0) {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CStringA str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    eOut = Parse(str);
    return nResult;
}
