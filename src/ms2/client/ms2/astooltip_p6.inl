// astooltip.cpp part 6: functions 0x1409e7dc0-0x1409eb4c0 (exe order). Included by astooltip.cpp; merged into it when the unit is done.

// The value-from-XML getters of CXmlData (templated lookups over m_values, first instantiated here).
CString FUN_1407186a0(const CStringW& value);
std::vector<int> FUN_140719090(const CStringW& value);
__int64 FUN_140718320(const CStringW& value);
bool FUN_1407183f0(const CStringW& value);

// @0x1409e8500
const int& FUN_1409e8500(const CAtlArray<int>& arr, int nIndex, const int& nDefault)
{
    int nCount = (int)arr.GetCount();
    if (nIndex < 0 || nIndex > nCount - 1)
        return nDefault;
    return arr[nIndex];
}

// @0x1409e8560
CString CXmlData::FUN_1409e8560(const CStringW& strKey, const CString& strDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return strDefault;
    return FUN_1407186a0(strValue);
}

// @0x1409e8620
std::vector<int> CXmlData::FUN_1409e8620(const CStringW& strKey, const std::vector<int>& vDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return vDefault;
    return FUN_140719090(strValue);
}

// @0x1409e86e0
__int64 CXmlData::FUN_1409e86e0(const CStringW& strKey, const __int64& nDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return nDefault;
    return FUN_140718320(strValue);
}

// @0x1409e8780
bool CXmlData::FUN_1409e8780(const CStringW& strKey, const bool& bDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return bDefault;
    return FUN_1407183f0(strValue);
}

// @0x1409eb1d0
void ASObj::FUN_1409eb1d0(const char* szName, const ASArray& arr)
{
    ASData data;
    data.FUN_1422b8270(arr);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409eb270
void ASObj::FUN_1409eb270(const char* szName, const ASObj& obj)
{
    ASData data;
    data.FUN_1422b8270(obj);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409eb3b0
void ASObj::FUN_1409eb3b0(const char* szName, long n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409e7dc0
MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<AScript> sp(new ASObj(v, nMovieId));
    return sp;
}

CStringW FUN_1407196b0(int n);                  // a number with thousands separators
CStringW FUN_14083cb20(const CStringW& str);

// @0x1409eb450
CStringW FUN_1409eb450(int n)
{
    return FUN_14083cb20(FUN_1407196b0(n));
}
