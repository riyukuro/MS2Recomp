// cnpsman.h - PLACEHOLDER for CNPSMan (RTTI .?AVCNPSMan@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CNPSMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

// The owner's TU (client/ms2/npsman.cpp) specializes TSingleton<CNPSMan> and defines its s_instance (0x143abf520) outright; the same
// specialization here keeps this header's users from instantiating a second, COMDAT s_instance of the primary template.
class CNPSMan;
template <> class TSingleton<CNPSMan>
{
public:
    TSingleton();                                       // 0x140db91a0
    virtual ~TSingleton();                              // 0x140db91d0
    static CNPSMan* s_instance;                         // 0x143abf520
    static CNPSMan* GetInstance() { return s_instance; }
};

class CNPSMan : public TSingleton<CNPSMan>
{
public:
    CNPSMan();                                              // 0x140db8d80
    virtual ~CNPSMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(CNPSMan, 0x38);
