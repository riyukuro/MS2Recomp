// cluaclient.h - CLuaClient (RTTI .?AVCLuaClient@@, 0x78 bytes). NOT an original header.
// Bases: CLua at +0x0, TSingleton<CLuaClient> at +0x70. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
// The client build of CLua: IsClient() is false in the sense of "has no server console" (print() output goes to the log).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/luautil.h"

class CLuaClient : public CLua, public TSingleton<CLuaClient>
{
public:
    CLuaClient();                                           // 0x14067a440
    virtual ~CLuaClient();
    virtual bool IsClient();                                // 0x14067bc80
    virtual void Validate();                                // 0x14067a3f0
};
MS2_CHECK_SIZE(CLuaClient, 0x78);
