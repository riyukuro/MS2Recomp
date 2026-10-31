// cjobconditiontable.h - PLACEHOLDER for CJobConditionTable (RTTI .?AVCJobConditionTable@@, 0x88 bytes). NOT an original header.
// Bases: TSingleton<CJobConditionTable> at +0x0, CValidData<CJobConditionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CJobConditionTable : public TSingleton<CJobConditionTable>, public CValidData<CJobConditionTable>
{
public:
    CJobConditionTable();                                   // 0x140635ec0
    virtual ~CJobConditionTable();
    int Load();                                             // 0x140636000
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x88 - 0x10];
};
MS2_CHECK_SIZE(CJobConditionTable, 0x88);
