// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The publisher platform factory: FUN_140d86270 creates the
// Nexon (country 0) or Tencent (country 3) IClientPlatform singleton, FUN_140d86330 destroys both.
// MS2-UNIT: client\ms2\ms2clientplatform.cpp
// MS2-RANGE: 0x140d86270-0x140d86560 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2clientplatform.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and globals ----
class CClientPlatformNexonKorea : public IClientPlatform { public: CClientPlatformNexonKorea(); virtual ~CClientPlatformNexonKorea(); char m_pad_08[0x30]; };     // ctor 0x140c77ab0
class CClientPlatformTencent : public IClientPlatform { public: CClientPlatformTencent(); virtual ~CClientPlatformTencent(); char m_pad_08[0x30]; };           // ctor 0x140c7cd70
extern int DAT_143ab0248;                       // client country (0 Nexon Korea, 3 Tencent)
extern IClientPlatform* DAT_143ac2fd8;          // the live platform (read by FUN_140d86260)
extern void* DAT_143abf518;                     // the Nexon platform singleton
extern void* DAT_143abf628;                     // the Tencent platform singleton
int FUN_1406c34c0();                            // the Nexon platform enabled predicate
CClientPlatformNexonKorea* FUN_140c7a240();               // the Nexon platform singleton
IClientPlatform* FUN_140d86370();
IClientPlatform* FUN_140d863f0();
CClientPlatformTencent* FUN_140d86550();               // the Tencent platform singleton
void FUN_140d86470();
void FUN_140d864e0();

// @0x140d86270
bool FUN_140d86270()
{
    bool bResult = true;
    switch (DAT_143ab0248) {
    case 0:
        DAT_143ac2fd8 = FUN_140d86370();
        break;
    case 3:
        DAT_143ac2fd8 = FUN_140d863f0();
        break;
    default:
        MS2_ASSERT_AT(30, FALSE);
        return false;
    }
    if (DAT_143ac2fd8 == 0 || !bResult)
        return false;
    if (FUN_1406c34c0() != 0 && DAT_143ac2fd8->vfunc_17() == 0)
        return false;
    return true;
}
MS2_REPLACE(0x140D86270, FUN_140d86270, 171, 0x003E167D);

// @0x140d86330
void FUN_140d86330()
{
    if (FUN_140c7a240() != 0)
        FUN_140d86470();
    if (FUN_140d86550() != 0)
        FUN_140d864e0();
    DAT_143ac2fd8 = 0;
}
MS2_REPLACE(0x140D86330, FUN_140d86330, 50, 0x6C8FF6F9);

// @0x140d86370
IClientPlatform* FUN_140d86370()
{
    IClientPlatform* pPlatform;
    if (DAT_143abf518 != 0)
        pPlatform = FUN_140c7a240();
    else
        pPlatform = new CClientPlatformNexonKorea;
    return pPlatform;
}
MS2_REPLACE(0x140D86370, FUN_140d86370, 114, 0xD42FA7CE);

// @0x140d863f0
IClientPlatform* FUN_140d863f0()
{
    IClientPlatform* pPlatform;
    if (DAT_143abf628 != 0)
        pPlatform = FUN_140d86550();
    else
        pPlatform = new CClientPlatformTencent;
    return pPlatform;
}
MS2_REPLACE(0x140D863F0, FUN_140d863f0, 114, 0xB9B68421);

// @0x140d86470
void FUN_140d86470()
{
    if (DAT_143abf518 != 0) {
        delete FUN_140c7a240();
        DAT_143abf518 = 0;
    }
}
MS2_REPLACE(0x140D86470, FUN_140d86470, 98, 0x0EF39B86);

// @0x140d864e0
void FUN_140d864e0()
{
    if (DAT_143abf628 != 0) {
        delete FUN_140d86550();
        DAT_143abf628 = 0;
    }
}
MS2_REPLACE(0x140D864E0, FUN_140d864e0, 98, 0x1B90A320);

// @0x140d86550
CClientPlatformTencent* FUN_140d86550()
{
    return (CClientPlatformTencent*)DAT_143abf628;
}
MS2_REPLACE(0x140D86550, FUN_140d86550, 8, 0xA6EA81C0);
