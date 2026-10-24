// cmachineidmanager.h - PLACEHOLDER for CMachineIDManager (RTTI .?AVCMachineIDManager@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<CMachineIDManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

// The owner's TU (guess/machineidmanager.cpp) specializes TSingleton<CMachineIDManager> and defines its s_instance (0x143ab8aa8) outright; the same
// specialization here keeps this header's users from instantiating a second, COMDAT s_instance of the primary template.
class CMachineIDManager;
template <> class TSingleton<CMachineIDManager>
{
public:
    TSingleton();                                       // 0x140d4fe20
    virtual ~TSingleton();                              // 0x140d4fe50
    static CMachineIDManager* s_instance;               // 0x143ab8aa8
    static CMachineIDManager* GetInstance() { return s_instance; }
};

class CMachineIDManager : public TSingleton<CMachineIDManager>
{
public:
    CMachineIDManager();                                    // 0x140d4fcd0
    virtual ~CMachineIDManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x20 - 0x8];
};
MS2_CHECK_SIZE(CMachineIDManager, 0x20);
