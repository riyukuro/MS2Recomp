// ugchomeoptiondata.h - PLACEHOLDER for UgcHomeOptionData (RTTI .?AVUgcHomeOptionData@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<UgcHomeOptionData> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UgcHomeOptionData : public TSingleton<UgcHomeOptionData>
{
public:
    UgcHomeOptionData();                                    // 0x140b67f20
    virtual ~UgcHomeOptionData();
    void Load();                                            // 0x140b67fa0
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x98 - 0x8];
};
MS2_CHECK_SIZE(UgcHomeOptionData, 0x98);
