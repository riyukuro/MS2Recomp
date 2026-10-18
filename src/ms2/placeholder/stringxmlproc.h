// stringxmlproc.h - PLACEHOLDER for StringXmlProcBase / StringXmlProc<T> (RTTI .?AVStringXmlProcBase@@,
// .?AV?$StringXmlProc@W4PVPStringId@@@@). NOT an original header. Sizes: base 0x18 (CPtred), StringXmlProc<T> 0x40
// (scalar deleting dtors 0x1408503f0 / 0x140850270 / 0x140850230). Layout from LoadData 0x1410255f0, GetData 0x141025c50
// and GetText 0x141025b80; the ctors/dtors live in ?\stringidinterfacebase.cpp (not recovered yet).
// A string table loaded from an xml file: <ms2><key name="..." value="..."/>: the name column is translated to the id
// by m_factory30's table (a case-insensitive name -> id map), the result is an id -> text map.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#ifndef _HAS_AUTO_PTR_ETC
#define _HAS_AUTO_PTR_ETC 1        // clang builds are C++17: keep the STL's std::auto_ptr the exe's table loader uses
#endif
#include <memory>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

enum PVPStringId { PVPStringIdNone = 0 };
enum IndividualArenaStringId { IndividualArenaStringIdNone = 0 };

class StringXmlProcBase : public CPtred
{
public:
    StringXmlProcBase();                                    // 0x14084fd80
    virtual ~StringXmlProcBase();                           // 0x140850140
};
MS2_CHECK_SIZE(StringXmlProcBase, 0x18);

template <class T>
class StringXmlProc : public StringXmlProcBase
{
public:
    typedef ATL::CRBMap<CStringW, T, ATL::CStringElementTraits<CStringW> > KeyMap;   // case-sensitive: the exe compares keys with wcscmp (0x14051b270)
    typedef ATL::CRBMap<T, CStringW> ValueMap;

    // 0x14084faa0 (IndividualArenaStringId); callee destroys the three by-value strings. Defined by stringidinterfacebase.cpp.
    StringXmlProc(CStringA path, std::auto_ptr<KeyMap> (*factory)(), CStringA keyAttribute, CStringA valueAttribute);
    virtual ~StringXmlProc();                               // 0x14084ff80 (PVPStringId)
    CStringW GetText(T id);                                 // 0x141025b80 (PVPStringId)
    ValueMap* GetData();                                    // 0x141025c50
    ValueMap* LoadData();                                   // 0x1410255f0

    CStringA m_path18;                                      // +0x18 xml file (below the table dir)
    CStringA m_keyAttribute20;                              // +0x20 attribute holding the name
    CStringA m_valueAttribute28;                            // +0x28 attribute holding the text
    std::auto_ptr<KeyMap> (*m_factory30)();                 // +0x30 builds the name -> id map
    ValueMap* m_cached38;                                   // +0x38 loaded on first use
};
MS2_CHECK_SIZE(StringXmlProc<PVPStringId>, 0x40);
