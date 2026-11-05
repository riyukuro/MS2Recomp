// datatable.h - DataTable<T> (RTTI .?AV?$DataTable@VWebGuide@@@@, .?AV?$DataTable@VPCActionGroup@@@@), the generic xml
// table loader the client tables derive from. NOT an original header (names invented; the exe asserts in
// e:\build\kr\22_04\ms2code\commonfiles\datatable.h line 0x3b). Layout 0x38: vftable, then the lock the loader holds.
//   slot 0  Add(MS2Ptr<T>)        pure; DataTableMap<T,K,KT> overrides it (inserts under the row's key)
//   slot 1  Loaded()              called once after all rows were added; empty here
//   slot 2  Create(TiXmlElement*) pure; DataTableBase<T> overrides it (a new T)
// The loader, Load(dir, file, element), is a template member: include datatable_impl.h in the unit that instantiates it.
// DataTable<WebGuide>::DataTable 0x141b81dd0; DataTableBase<WebGuide>::DataTableBase 0x141b81e10.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

class TiXmlElement;    // xml element

template <class T>
class DataTable
{
public:
    DataTable() {}                                          // vftable + lock
    // implicit destructor: only the lock is destroyed, no vftable reset
    virtual void Add(MS2Ptr<T> spRow) = 0;                  // slot 0
    virtual void Loaded() {}                                // slot 1 (0x141b82910 for T = WebGuide)
    virtual MS2Ptr<T> Create(TiXmlElement* pNode) = 0;     // slot 2
    int Load(CString strDir, CString strFile, CString strElement);   // 0x141b82a10 for T = WebGuide
    CLockCriticalSection m_lock;                            // +0x08
};
MS2_CHECK_SIZE(DataTable<CPtred>, 0x38);

// The row factory layer: Create returns a default-constructed T (0x141b82290 for T = WebGuide).
template <class T>
class DataTableBase : public DataTable<T>
{
public:
    DataTableBase() {}
    MS2Ptr<T> Create(TiXmlElement*) { return MS2Ptr<T>(new T); }
};
