// xmlattr.h - PLACEHOLDER for the game's TinyXML attribute helpers (not an original header; names invented).
// The element type is the game TinyXML element (TiXmlElement, as the table units call it). The attribute readers
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

#include "ms2/placeholder/tixmlelement.h"   // TiXmlNode / TiXmlElement (the element type), Unk_TiXmlString
// C3 #12: the element stand-in Unk_140165cf0 was TiXmlElement (work/ua11/tixml-proof.md): its
// FUN_140165cf0 / FUN_140168650 members are TiXmlNode::FirstChildElement / NextSiblingElement(const char*),
// and its NextSiblingElement() / Value() inline COMDATs (0x1403f0510 / 0x140189180) are in tixmlelement.h.





















int FUN_1408730a0(TiXmlElement* pElem, const char* pszName, bool& bOut);
int FUN_1408731a0(TiXmlElement* pElem, const char* pszName, unsigned short& nOut);
int FUN_1408731e0(TiXmlElement* pElem, const char* pszName, int& nOut);
int FUN_140873220(TiXmlElement* pElem, const char* pszName, unsigned& nOut);
int FUN_1408732a0(TiXmlElement* pElem, const char* pszName, unsigned& nOut);            // tick (duration) value
int FUN_1408732e0(TiXmlElement* pElem, const char* pszName, __int64& nOut);
int FUN_140873360(TiXmlElement* pElem, const char* pszName, float& fOut);
int FUN_1408733e0(TiXmlElement* pElem, const char* pszName, CStringA& strOut);
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0 (0x1408733e0)
int FUN_140873420(TiXmlElement* pElem, const char* pszName, CStringW& strOut);
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890 (int or enum value)
CString FUN_14015f710(TiXmlElement* pElem, const char* pszName, CString strDefault);  // string attribute with default
void Unk_SplitA(CString& str, ATL::CAtlArray<CString>* pOut, const char* pszSep);   // split into strings (C3: was FUN_14015f050, the achievedata def)

// Iterates an element and its same-named siblings: `for (TiXmlElement* p : pParent->FirstChildElement("x"))`.
class Unk_XmlElementIterator
{
public:
    // @0x140183390
    Unk_XmlElementIterator(TiXmlElement* p) : m_p(p) {}
    // @0x1401833b0
    Unk_XmlElementIterator() : m_p(0) {}
    // @0x140184920
    TiXmlElement* operator*() const { return m_p; }
    // @0x140184c50
    Unk_XmlElementIterator& operator++() { m_p = m_p->NextSiblingElement(m_p->Value()); return *this; }
    // @0x140184450
    bool operator!=(const Unk_XmlElementIterator& o) const { return m_p != o.m_p; }
private:
    TiXmlElement* m_p;
};
MS2_CHECK_SIZE(Unk_XmlElementIterator, 8);
// @0x14018ef30
inline Unk_XmlElementIterator begin(TiXmlElement* p) { return Unk_XmlElementIterator(p); }
// @0x14018f960
inline Unk_XmlElementIterator end(TiXmlElement*) { return Unk_XmlElementIterator(); }

// The templates below are untagged (their instantiations pair through symbols.tsv); keep them more than
// TAG_WINDOW lines below the end() tag, or a TU that never emits end() binds that tag to XmlConvert.

// Token conversion (0x140177cf0 unsigned short, 0x140177d20 int, 0x140177d50 unsigned, 0x140177d80 float).
template <class T> T XmlConvert(const CString& str) { return (T)atoi(str); }
template <> inline float XmlConvert<float>(const CString& str) { return (float)atof(str); }
// 0x1404082e0: unsigned 64-bit lists (GUIDs, UGC market SNs) are parsed with _strtoui64, not atoi. It lives here
// so every TU instantiates the same body (the linker keeps one COMDAT copy for all callers).
template <> inline unsigned __int64 XmlConvert<unsigned __int64>(const CString& str) { return _strtoui64(str, NULL, 10); }

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
template <class C> int XmlTokenList(TiXmlElement* pElem, const char* pszName, C& out)
{
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet == 0)
        XmlSplit(str, out, ",");
    return nRet;
}
// 0x1401788f0
template <> inline int XmlTokenList(TiXmlElement* pElem, const char* pszName, ATL::CAtlArray<CString>& out)
{
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet == 0)
        Unk_SplitA(str, &out, ",");
    return nRet;
}

// The enum readers come from commonfiles\tinyxmlhelper.h: they start with a compile-time type guard whose failure
// branch asserts FALSE (with that header's __FILE__) and returns TIXML_WRONG_TYPE (2).
#define MS2_TINYXMLHELPER_FILE L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
#define MS2_TINYXMLHELPER_ASSERT(line, expression)                                                                \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), MS2_TINYXMLHELPER_FILE, (unsigned)(line)), 0))

// Enum attribute stored as a number (0x140178970-0x140178f10, one per enum type).
template <class E> int XmlValue(TiXmlElement* pElem, const char* pszName, E& eOut)
{
    if (!std::is_enum<E>::value)
    {
        MS2_TINYXMLHELPER_ASSERT(231, FALSE);
        return 2;
    }
    int nValue = 0;
    int nRet = XmlQuery((class TiXmlElement*)(pElem), pszName, nValue);
    if (nRet != 0)
        return nRet;
    eOut = (E)nValue;
    return nRet;
}

// tinyxmlhelper.h: enum attribute given by name (the parser is the enum's string converter).
template <class E, E (*Parse)(const CStringA&)>
int XmlEnumName(TiXmlElement* pElem, const char* pszName, E& eOut)
{
    if (0) {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CStringA str;
    int nResult = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nResult != 0)
        return nResult;
    eOut = Parse(str);
    return nResult;
}
