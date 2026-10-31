// cchangejobtable.h - PLACEHOLDER for CChangeJobTable (RTTI .?AVCChangeJobTable@@, 0x50 bytes). NOT an original header.
// Bases: TSingleton<CChangeJobTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CChangeJobTable : public TSingleton<CChangeJobTable>
{
public:
    CChangeJobTable();                                      // 0x1401d64a0
    virtual ~CChangeJobTable();
    void Load();                                            // 0x1401d6550
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x50 - 0x8];
};
MS2_CHECK_SIZE(CChangeJobTable, 0x50);
