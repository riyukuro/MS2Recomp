// loginbgbgmtable.h - PLACEHOLDER for LoginBgBgmTable (RTTI .?AVLoginBgBgmTable@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<LoginBgBgmTable> at +0x0, CValidData<LoginBgBgmTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class LoginBgBgmTable : public TSingleton<LoginBgBgmTable>, public CValidData<LoginBgBgmTable>
{
public:
    LoginBgBgmTable();                                      // 0x140a71f90
    virtual ~LoginBgBgmTable();
    bool Load();                                            // 0x140a72170
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x30 - 0x10];
};
MS2_CHECK_SIZE(LoginBgBgmTable, 0x30);
