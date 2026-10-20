// uniqueswfidcreator.h - PLACEHOLDER for UniqueSwfIDCreator (RTTI .?AVUniqueSwfIDCreator@@, vftable 0x14311a568, 0x118
// bytes): hands out the unique ids ("<name>_<n>_") of the GFx movies the UI loads. NOT an original header. An efd class
// (EE_DECLARE_CLASS, id 0x06202715; ms_ClassInfo 0x143b0d820 is defined in unit_14013acc0.cpp) with the empty bases
// efd::MemObject @8 and SingletonClass<UniqueSwfIDCreator> @9; no virtual dtor (3 slots: GetClassDesc, TypeCast x2).
//
// The two CRBMap value types are int-sized and byte-indistinguishable: +0xb8 shares its COMDATs with reactor.cpp's map
// (ctor 0x140b7c550, Lookup(k, v&) 0x140b7d240, SetAt 0x140b7e170), +0xe8 with equipmodel.cpp's (ctor 0x141205140, Lookup(k)
// 0x141206670, SetAt 0x141207dc0). Those units both call their map CRBMap<CString, int>; since the exe keeps two copies
// they are two different types. Distinct stand-ins (unsigned / long) keep the names apart until one side is proven.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/ClassInfo.h>
#include <efd/MemObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/singletonclass.h"

class UniqueSwfIDCreator : public efd::MemObject, public SingletonClass<UniqueSwfIDCreator>
{
    EE_DECLARE_CLASS(UniqueSwfIDCreator, 0x06202715);
public:
    UniqueSwfIDCreator();                                                   // 0x1422f69e0
    // The id of a movie file: "" (returns 0) for an empty name; the name without ".swf" for a fixed id (bFixed, also
    // recorded) or a name already recorded as fixed; else "<name>_<n>_" with a per-name counter.
    int FUN_1422f6ac0(CString& strId, const CString& strFile, int bFixed);
    int FUN_1422f6c90(CString strId);                                       // drop an id from m_list10 (0 if the list has others but not it)
    // "<name>.<ext>_<n>_" with a per-key counter; the id is also queued (m_listIds). "" (returns 0) for an empty ext.
    int FUN_1422f6d50(CString& strId, CString strName, const CString& strExt);
    int FUN_1422f6ec0(CString strId);                                       // drop a queued id (1 if found)
    int FUN_1422f6fc0(CString strName);                                     // the name was recorded as fixed

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<CString> m_list10;                                        // +0x10 ids FUN_1422f6c90 removes
    ATL::CAtlMap<CString, unsigned int, ATL::CStringElementTraits<CString> > m_mapCount;   // +0x40 name -> last counter
    ATL::CAtlList<CString> m_listIds;                                       // +0x88 ids from FUN_1422f6d50
    ATL::CRBMap<CString, unsigned int> m_mapExtCount;                       // +0xb8 "<name>.<ext>" -> last counter
    ATL::CRBMap<CString, long> m_mapFixed;                                  // +0xe8 fixed names (value 1)
};
MS2_CHECK_SIZE(UniqueSwfIDCreator, 0x118);
