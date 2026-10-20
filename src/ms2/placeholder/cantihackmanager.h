// cantihackmanager.h - PLACEHOLDER for CAntiHackManager (RTTI .?AVCAntiHackManager@@, base TSingleton<CAntiHackManager>
// at +0). NOT an original header. Created/destroyed by CClientPlatformBase (CreateInstance 0x140c77400 / DestroyInstance
// 0x140c77480, GetInstance 0x140c77550 in client\ms2\ms2clientplatformbase.cpp). Method names are invented.
#pragma once

#include "ms2/commonfiles/os.h"     // TSingleton

class CAntiHackManager : public TSingleton<CAntiHackManager>
{
public:
    CAntiHackManager();
    virtual ~CAntiHackManager();
    void FUN_1409a3410(void* pParam);                   // CClientPlatformNexonKorea::vfunc_32 forwards its argument
};
