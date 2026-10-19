// cxmldata.h - PLACEHOLDER for CXmlData (RTTI .?AVCXmlData@@, 0x60 bytes, base CPtred, vftable 0x142daa300).
// NOT an original header. Code owner: ?\xmldata.cpp (dtor 0x14092c2a0, deleting dtor 0x14092c780). Only its
// destructor is called by recovered code so far (CItemData's <function> block holds one at +0x90).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

int FUN_1407181a0(const CStringW& str);    // a wide string as an int
unsigned long FUN_1407182c0(const CStringW& str);   // a wide string as an unsigned long

class CXmlData : public CPtred
{
public:
    CXmlData();                         // 0x14092c230
    CXmlData(const CStringW& strValues);    // 0x14092c2e0 parses "key=value" text (gameeventvalue.cpp)
    virtual ~CXmlData();                // 0x14092c2a0
    bool FUN_14092c370(CXmlData* pOther);           // differs from pOther (additionalactionadditional.cpp)
    void FUN_14092c590();                           // clears the parsed values
    void FUN_14092c400(const CStringW& strValues);  // parses "key=value" text
    CString FUN_1409e8560(const CStringW& strKey, const CString& strDefault);     // value as an ansi string (scenestategame.cpp)
    CStringW FUN_14042cad0(const CStringW& strKey, const CStringW& strDefault);   // value as a wide string
    bool FUN_14092c5c0();                           // no values parsed
    typedef ATL::CAtlMap<CStringW, CStringW, ATL::CStringElementTraits<CStringW> > Values;
    CStringW FUN_14092c630() const;                 // serializes to "<v key="value".../>"
    bool FUN_14092c5f0(const CStringW& strKey) const;   // the key is present
    std::vector<int> FUN_1409e8620(const CStringW& strKey, const std::vector<int>& vDefault);   // value as a comma separated int list (unit_140d1ae30)
    __int64 FUN_1409e86e0(const CStringW& strKey, const __int64& nDefault);   // value as an __int64 (unit_140d1ae30)
    // The value as an int, nDefault when the key is missing. An inline (COMDAT copies 0x1403d8110 in gameevent.cpp
    // and 0x14054c530 in itemdatastruct.cpp).
    int GetInt(const CStringW& strKey, const int& nDefault)
    {
        CStringW strValue;
        if (!reinterpret_cast<Values*>(m_unknown18)->Lookup(strKey, strValue))
            return nDefault;
        return FUN_1407181a0(strValue);
    }
    // The value as an unsigned long, nDefault when the key is missing (COMDAT 0x140d26970 in unit_140d1ae30).
    unsigned long GetULong(const CStringW& strKey, const unsigned long& nDefault)
    {
        CStringW strValue;
        if (!reinterpret_cast<Values*>(m_unknown18)->Lookup(strKey, strValue))
            return nDefault;
        return FUN_1407182c0(strValue);
    }
    bool FUN_1409e8780(const CStringW& strKey, const bool& bDefault);   // value as a bool (unit_140d1ae30)
private:
    // The parsed key/values. A union so that the units that only need the map can still reach the same storage
    // through the raw array (xmldata.cpp's ctor/dtor construct/destroy m_values explicitly).
    union
    {
        Values m_values;                // +0x18 the parsed key/values
        unsigned char m_unknown18[0x48];
    };
};
MS2_CHECK_SIZE(CXmlData, 0x60);
