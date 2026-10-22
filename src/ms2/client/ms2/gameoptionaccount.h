// gameoptionaccount.h - CGameOptionAccount (RTTI .?AVCGameOptionAccount@@, base CBaseOption, 0x30 bytes): the "account"
// game option row (GameOptionAccount). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed.
// vftable 0x142e23e68 (15 slots; only 0 (deleting dtor), 1 and 5 are its own).
#pragma once
#include "ms2/client/ms2/baseoption.h"

class CGameOptionAccount : public CBaseOption
{
public:
    CGameOptionAccount(int nId, int nType);                         // 0x140cfb200
    virtual ~CGameOptionAccount();                                  // 0x140cfb250 (deleting dtor 0x140cfb2f0)

    virtual CString GetTypeName();                                      // 0x140cfb280
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x140cfb2d0 (not handled)
};
MS2_CHECK_SIZE(CGameOptionAccount, 0x30);
