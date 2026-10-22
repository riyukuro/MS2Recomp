// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptionaccount.cpp: the account row of the
// game options.
// MS2-UNIT: ?\gameoptionaccount.cpp
// MS2-RANGE: 0x140cfb200-0x140cfb450 .text$mn
// MS2-PIN: ??_GCGameOptionAccount@@UEAAPEAXI@Z 0x140cfb2f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptionaccount.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "gameoptionaccount.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140cfb200
CGameOptionAccount::CGameOptionAccount(int nId, int nType)
    : CBaseOption(nId, nType)
{
}

// @0x140cfb250
CGameOptionAccount::~CGameOptionAccount()
{
}

// @0x140cfb280
CString CGameOptionAccount::GetTypeName()
{
    return "GameOptionAccount";
}
MS2_REPLACE_METHOD(0x140CFB280, CGameOptionAccount, GetTypeName, 61, 0x7B28F3AC);

// @0x140cfb2d0
int CGameOptionAccount::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}
MS2_REPLACE_METHOD(0x140CFB2D0, CGameOptionAccount, vfunc_5, 23, 0x192A1B0B);

MS2_EMIT_CRT_MEMMOVE_S();
