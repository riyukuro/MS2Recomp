// csmartpushmanager.h - PLACEHOLDER for CSmartPushManager (RTTI .?AVCSmartPushManager@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CSmartPushManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CSmartPushManager : public TSingleton<CSmartPushManager>
{
public:
    CSmartPushManager();                                    // 0x140dd81d0
    virtual ~CSmartPushManager();
    void FUN_140dd82b0();                                   // 0x140dd82b0
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x58 - 0x8];
};
MS2_CHECK_SIZE(CSmartPushManager, 0x58);
