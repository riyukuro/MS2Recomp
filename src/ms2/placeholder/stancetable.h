// stancetable.h - PLACEHOLDER for StanceTable (RTTI .?AVStanceTable@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<StanceTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// A stance level row (only the member read by ?\additionalcli.cpp is recovered; size unknown).
class StanceLevelData : public CPtred
{
public:
    int m_nStep;                                            // +0x18 the stance bar step
};
MS2_CHECK_OFFSET(StanceLevelData, m_nStep, 0x18);

// A stance row (size unknown).
class StanceData : public CPtred
{
public:
    MS2Ptr<StanceLevelData> FUN_140829550(unsigned nLevel);  // 0x140829550 the row of a level (overlap count)
};

class StanceTable : public TSingleton<StanceTable>
{
public:
    StanceTable();                                          // 0x140829650
    virtual ~StanceTable();
    MS2Ptr<StanceData> FUN_140829e20(unsigned nId);         // 0x140829e20 the row of an additional effect id
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(StanceTable, 0x38);
