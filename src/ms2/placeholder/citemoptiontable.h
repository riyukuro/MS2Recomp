// citemoptiontable.h - PLACEHOLDER for CItemOptionTable (RTTI .?AVCItemOptionTable@@, 0x118 bytes). NOT an original header.
// Bases: TSingleton<CItemOptionTable> at +0x0, CValidData<CItemOptionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include <atlcoll.h>
#include "ms2/placeholder/unk_optionnamelist.h"

class Unk_Random;

class CItemOptionTable : public TSingleton<CItemOptionTable>, public CValidData<CItemOptionTable>
{
public:
    CItemOptionTable();                                     // 0x1405f4140
    virtual ~CItemOptionTable();
    // commonfiles\itemoptiondata.cpp#3 (declared for the random option rolls of #2)
    int FUN_1405f6100(unsigned nStatId);
    int RollVariation(unsigned nStatId, Unk_Random* pRandom);
    int FUN_1405f6230(unsigned nStatId);
    int FUN_1405f62c0(unsigned nStatId);
    Unk_OptionNameListPtr FindOptionNameList(const CString& strName);     // the exclusive group of a stat name (null: none)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x118 - 0x10];
};
MS2_CHECK_SIZE(CItemOptionTable, 0x118);
