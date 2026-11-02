// xmldata.cpp - CXmlData (src/ms2/placeholder/cxmldata.h): the "<v key="value" .../>" text block an event/config
// object carries, read back through the ATL::CAtlMap<CStringW, CStringW> CXmlData instantiates (the map's inline
// members that the link took from this object file are the 0x14092c5f0-0x14092ca40 block).
// MS2-UNIT: ?\xmldata.cpp
// MS2-RANGE: 0x14092c230-0x14092cb30 .text$mn
// MS2-PIN: ??_7CXmlData@@6B@ 0x142daa300
#include "ms2/placeholder/ms2stdafx.h"

#include <stdio.h>
#include <new>

#include "ms2/placeholder/cxmldata.h"
#include "ms2/ms2format.h"   // C3: StringFormat<CStringW, CStringW> (was FUN_140656190)

// TinyXML. This file only walks an element's attribute list; the same unit-local view itemdatastruct.cpp uses.
class Unk_TiXmlAttribute
{
public:
    void* unknown00[7];                         // TiXmlBase, document, name, value, prev
    Unk_TiXmlAttribute* next;                   // +0x38
};
MS2_CHECK_SIZE(Unk_TiXmlAttribute, 0x40);

class Unk_TiXmlAttributeSet
{
public:
    // @0x140552d70
    Unk_TiXmlAttribute* First() { return (sentinel.next == &sentinel) ? 0 : sentinel.next; }
    Unk_TiXmlAttribute sentinel;
};

class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
    // @0x14092c880
    Unk_TiXmlAttribute* FirstAttribute() { return attributeSet.First(); }
private:
    void* unknown00[5];                         // TiXmlBase, parent, type
    void* firstChild;                           // +0x28
    void* unknown30[4];                         // lastChild, value, prev, next
    Unk_TiXmlAttributeSet attributeSet;         // +0x50
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);

// The TinyXML members and the string converters this file calls but does not own.
class TiXmlAttribute   // C3: member view for the former free stand-ins
{
public:
    char const* Name() const;
    class TiXmlAttribute const* Next() const;
    char const* Value() const;
};
enum TiXmlEncoding { TIXML_ENCODING_UNKNOWN, TIXML_ENCODING_UTF8, TIXML_ENCODING_LEGACY };
class TiXmlParsingData;
class TiXmlElement   // C3: member view (Parse is virtual slot 2, called directly)
{
public:
    virtual const char* Parse(const char* p, TiXmlParsingData* data, TiXmlEncoding encoding);   // 0x1408782b0
};

CStringA FUN_14016a600(const wchar_t* psz, int nLength);                // narrows a wide string
CStringW FUN_14016a730(const char* psz, int nLength);                   // widens a narrow string

// The module loader at the tail of the file (its two helpers are in the next unit).
bool FUN_14092edf0(HMODULE* ppModule);
bool FUN_14092d8f0(HMODULE* ppModule);

// The exe calls its own, statically linked fprintf (0x140868660) instead of the DLL import the crt header declares.
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-dllimport"
#else
#pragma warning(push)
#pragma warning(disable : 4273)  // inconsistent dll linkage: intended
#endif
extern "C" int __cdecl fprintf(FILE* pFile, const char* pszFormat, ...);
#if defined(__clang__)
#pragma clang diagnostic pop
#else
#pragma warning(pop)
#endif

// @0x14092c230
CXmlData::CXmlData() : m_values()
{
}

// @0x14092c2a0
CXmlData::~CXmlData()
{
    // The destructor has to be spelled through the class name: through the `Values` alias cl 19.16 emits a call to
    // the scalar deleting destructor (??_G) instead, which is wrong for a member. (Same layout, proven by probe.)
    m_values.ATL::CAtlMap<CStringW, CStringW, ATL::CStringElementTraits<CStringW> >::~CAtlMap();
}

// @0x14092c2e0
CXmlData::CXmlData(const CStringW& strValues) : m_values()
{
    FUN_14092c400(strValues);
}

// @0x14092c370
bool CXmlData::FUN_14092c370(CXmlData* pOther)
{
    if (FUN_14092c630() != pOther->FUN_14092c630())
        return true;
    return false;
}

// @0x14092c400
void CXmlData::FUN_14092c400(const CStringW& strValues)
{
    if (strValues.IsEmpty())
        return;

    CStringA strXml = FUN_14016a600(strValues, 0);
    Unk_TiXmlElement xmlElement("xmlData");
    void* pParsed = (void*)reinterpret_cast<TiXmlElement*>(&xmlElement)->TiXmlElement::Parse(strXml.GetBuffer(), 0, TIXML_ENCODING_UNKNOWN);
    if (pParsed == 0)
        return;

    Unk_TiXmlAttribute* pAttribute = xmlElement.FirstAttribute();
    while (pAttribute != 0)
    {
        reinterpret_cast<Values*>(m_unknown18)->SetAt(FUN_14016a730(((class TiXmlAttribute*)(class Unk_TiXmlAttribute const*)(pAttribute))->Name(), 0),
                                                      FUN_14016a730(((class TiXmlAttribute*)(class Unk_TiXmlAttribute const*)(pAttribute))->Value(), 0));
        pAttribute = ((class Unk_TiXmlAttribute*)((class TiXmlAttribute*)(class Unk_TiXmlAttribute*)(pAttribute))->Next());
    }
}

// @0x14092c590
void CXmlData::FUN_14092c590()
{
    reinterpret_cast<Values*>(m_unknown18)->RemoveAll();
}

// @0x14092c5c0
bool CXmlData::FUN_14092c5c0()
{
    return reinterpret_cast<Values*>(m_unknown18)->IsEmpty();
}

// @0x14092c5f0
bool CXmlData::FUN_14092c5f0(const CStringW& strKey) const
{
    if (reinterpret_cast<const Values*>(m_unknown18)->Lookup(strKey) != 0)
        return true;
    return false;
}

// @0x14092c630
CStringW CXmlData::FUN_14092c630() const
{
    CStringW strValues(L"<v");
    for (POSITION pos = reinterpret_cast<const Values*>(m_unknown18)->GetStartPosition(); pos != 0;
         reinterpret_cast<const Values*>(m_unknown18)->GetNext(pos))
    {
        const CStringW& strKey = reinterpret_cast<const Values*>(m_unknown18)->GetKeyAt(pos);
        const CStringW& strValue = reinterpret_cast<const Values*>(m_unknown18)->GetValueAt(pos);
        strValues += StringFormat<CStringW, CStringW>(L" {0}=\"{1}\"", strKey, strValue);
    }
    strValues += L"/>";
    return strValues;
}

// @0x14092ca70
bool FUN_14092ca70(HMODULE* ppModule, LPCSTR pszDll)
{
    if (FUN_14092edf0(ppModule))
        return true;

    *ppModule = LoadLibraryA(pszDll);
    if (*ppModule == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
        fprintf(stdout, "DLL \xc6\xc4\xc0\xcf\xc0\xbb \xb7\xce\xb5\xe5\xc7\xcf\xc1\xf6 \xb8\xf8\xc7\xdf\xbd\xc0"
                        "\xb4\xcf\xb4\xd9. - module-path=\"%s\", error-code=%lu",
                pszDll, GetLastError());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return false;
    }

    return FUN_14092d8f0(ppModule);
}
