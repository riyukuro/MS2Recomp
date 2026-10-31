// cindividualarenadatatable.h - PLACEHOLDER for CIndividualArenaDataTable (RTTI .?AVCIndividualArenaDataTable@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CIndividualArenaDataTable> at +0x0, CValidData<CIndividualArenaDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CIndividualArenaDataTable : public TSingleton<CIndividualArenaDataTable>,
                                  public CValidData<CIndividualArenaDataTable>
{
public:
    CIndividualArenaDataTable();                            // 0x14051a260
    virtual ~CIndividualArenaDataTable();
    bool Load();                                            // 0x14051a360
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x58 - 0x10];
};
MS2_CHECK_SIZE(CIndividualArenaDataTable, 0x58);
