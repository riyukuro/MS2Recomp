// datatablemap.h - DataTableMap<T, K, KTraits> (RTTI .?AV?$DataTableMap@VWebGuide@@V?$CStringT@D...@ATL@@V?$CStringElementTraits@...@3@@@):
// a DataTable<T> that keeps its rows in an ATL::CAtlMap<K, MS2Ptr<T>, KTraits> under T::GetKey(). NOT an original header.
// Layout 0x80 for T = WebGuide: DataTable (0x38) + the map at +0x38 (ctor 0x141b81e40 builds it with 17, .75, .25, 2.25, 10).
// WebGuideTable keeps its TSingleton at +0x80. The row type provides CString GetKey() const and LoadXml(TiXmlElement*).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/datatable.h"

template <class T, class K, class KTraits>
class DataTableMap : public DataTableBase<T>
{
public:
    typedef ATL::CAtlMap<K, MS2Ptr<T>, KTraits> RowMap;

    DataTableMap() {}                                       // 0x141b81e40
    void Add(MS2Ptr<T> spRow) { m_map.SetAt(spRow->GetKey(), spRow); }  // slot 0 (0x141b82890)

    RowMap m_map;                                           // +0x38
};
