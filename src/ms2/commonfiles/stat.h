// stat.h - the stat table (commonfiles\stat.cpp): the 35 stat definitions read from Table/statStringTable.xml and
// string/stringStatName.xml, and the per-job stat values per level read from Table/Server/userStat<job>.xml.
// Header name assumed from the unit path; type and member names are invented from use.
#pragma once
#include <afx.h>
#include <string.h>
#include "ms2/ms2layout.h"

// One stat of the stat table (0x28 bytes).
struct StatDefinition
{
    StatDefinition();                                                           // 0x14082e170
    StatDefinition(int nId, CStringA strName, int nValueType, CStringW strValueText, CStringW strCommonText);   // 0x14082e1f0
    int GetId() const { return m_nId; }                                         // 0x140831f20
    const CStringA& GetName() const { return m_strName; }                       // 0x140831f30
    CStringW GetValueText() const { return m_strValueText; }                    // 0x140831b90
    CStringW GetCommonText() const { return m_strCommonText; }                  // 0x140831b40
    int m_nId;                      // +0x00 "id" (-1 when unset)
    CStringA m_strName;             // +0x08 "option"
    int m_nValueType;               // +0x10 "valueType" (0 none, 1 and 2 are the two value kinds)
    CStringW m_strValueText;        // +0x18 string of "valueStringID"
    CStringW m_strCommonText;       // +0x20 string of "commonStringID"
};
MS2_CHECK_SIZE(StatDefinition, 0x28);

// The values of every stat per level (200 levels x 35 stats) of one job (zeroed on construction).
struct StatLevelValues
{
    StatLevelValues() { memset(this, 0, sizeof(*this)); }
    __int64 m_values[200][35];
};
