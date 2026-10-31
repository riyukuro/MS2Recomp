// csmartpushtable.h - PLACEHOLDER for CSmartPushTable (RTTI .?AVCSmartPushTable@@, 0xa0 bytes). NOT an original header.
// Bases: TSingleton<CSmartPushTable> at +0x0, CValidData<CSmartPushTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CSmartPushTable : public TSingleton<CSmartPushTable>, public CValidData<CSmartPushTable>
{
public:
    CSmartPushTable();                                      // 0x1408105e0
    virtual ~CSmartPushTable();
    void Load();                                            // 0x140810730
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xa0 - 0x10];
};
MS2_CHECK_SIZE(CSmartPushTable, 0xa0);
