// specialability.h - the special ability ("SA") tables of commonfiles\specialability.cpp (assert strings name the
// source file and its row table `m_specialTo`). Header name assumed; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/blackmarketitemoption.h"

#include "ms2/commonfiles/additionalactionadditional.h"   // SAType, the special ability type (defined there once)
enum eSpecialAbility { };                   // an ability id (the keys of the group table)

// One row of the 0xcf entry table (specialAbilityStringTable.xml <key id= option= valueType= commonStringID= valueStringID=>).
struct SpecialAbilityInfo
{
    SpecialAbilityInfo();                                                                                // 0x14081c780
    SpecialAbilityInfo(const CStringA& strKey, CStringW strFormat, CStringW strName, int nValueType);    // 0x14081c7e0

    CStringA m_strKey;          // +0x00 "option"
    int m_nValueType;           // +0x08 eOptionValue (0 none, 1 number, 2 percent)
    CStringW m_strFormat;       // +0x10 the value string
    CStringW m_strName;         // +0x18 the common (name) string
};
MS2_CHECK_SIZE(SpecialAbilityInfo, 0x20);

typedef Unk_BmBoxPtr<ATL::CAtlList<eSpecialAbility> > Unk_SAListPtr;    // TPtr<CAtlList<eSpecialAbility>>

int FUN_14081c880();                                        // loads everything and fills the lookup tables
int LoadSpecialAbilityStringTable();                                        // the row table
int LoadStringSpecialAbilityName(std::map<int, CStringW>& mapNames);       // stringSpecialAbilityName.xml
Unk_SAListPtr GetSpecialAbilityList(eSpecialAbility nType);                // the ability list of a group
