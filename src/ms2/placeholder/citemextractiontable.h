// citemextractiontable.h - PLACEHOLDER for CItemExtractionTable (RTTI .?AVCItemExtractionTable@@, 0x80 bytes). NOT an original header.
// Bases: CCacheData at +0x0, TSingleton<CItemExtractionTable> at +0x28, CValidData<CItemExtractionTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemExtractionTable : public CCacheData,
                             public TSingleton<CItemExtractionTable>,
                             public CValidData<CItemExtractionTable>
{
public:
    CItemExtractionTable();                                 // 0x140597010
    virtual ~CItemExtractionTable();
    void Load();                                            // 0x140597150
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0x80 - 0x38];
};
MS2_CHECK_SIZE(CItemExtractionTable, 0x80);
