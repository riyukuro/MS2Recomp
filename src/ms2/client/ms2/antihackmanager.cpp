// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAntiHackManager (the anti-hack singleton the network
// service ticks) and the two file-local helpers that build the anti-hack module's path and its version string.
// Original source file name unknown (assumed from the class name).
// MS2-UNIT: ?\antihackmanager.cpp
// MS2-RANGE: 0x1409a3360-0x1409a36c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\antihackmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/networkservice.h"
#include "hook/ms2hook.h"

// @0x1409a3460 — the full path of a file that sits next to the running executable: "<drive><dir><strName>".
CString FUN_1409a3460(CString strName)
{
    char szModule[0x104];
    memset(szModule, 0, sizeof(szModule));
    GetModuleFileNameA(0, szModule, 0x104);
    char szDrive[_MAX_DRIVE];
    char szDir[_MAX_DIR];
    _splitpath(szModule, szDrive, szDir, 0, 0);
    CString strPath;
    strPath.Format("%s%s%s", szDrive, szDir, (LPCSTR)strName);
    return strPath;
}
MS2_REPLACE(0x1409A3460, FUN_1409a3460, 276, 0x0C3E2E02);

// @0x1409a3580 — the build number (0x9dd) as a hex string; the anti-hack module's expected version.
CString FUN_1409a3580()
{
    CString strVersion;
    strVersion.Format("%x", 0x9dd);
    return strVersion;
}
MS2_REPLACE(0x1409A3580, FUN_1409a3580, 110, 0xCB992C13);

// A value whose second word is an object with a virtual Table() (slot 1) — the record the anti-hack manager's
// query is handed by its caller. Layout only: the query reaches the object through the caller's record.
class Unk_AntiHackArg
{
public:
    virtual void vfunc_0() {}
    virtual bool vfunc_1() { return false; }
};
struct Unk_AntiHackRecord
{
    void* m_pUnk0;          // +0x0
    Unk_AntiHackArg m_kArg; // +0x8
};

// The anti-hack manager: a stateless singleton (the exe object is its vftable alone).
class CAntiHackManager : public TSingleton<CAntiHackManager>
{
public:
    CAntiHackManager();
    virtual ~CAntiHackManager();
    void FUN_1409a33d0();                           // @0x1409a33d0 tell the network service about the current state
    void FUN_1409a3410(Unk_AntiHackRecord* pRecord);  // @0x1409a3410 ask the object the record carries
};
MS2_CHECK_SIZE(CAntiHackManager, 8);

// @0x1409a3360
CAntiHackManager::CAntiHackManager()
{
}

// @0x1409a33a0
CAntiHackManager::~CAntiHackManager()
{
}

// @0x1409a33d0
void CAntiHackManager::FUN_1409a33d0()
{
    Unk_NetworkCallbacks* pCallbacks = FUN_140d86260();
    pCallbacks->vfunc_30();
}
MS2_REPLACE_METHOD(0x1409A33D0, CAntiHackManager, FUN_1409a33d0, 43, 0x2965EA44);

// @0x1409a3410
void CAntiHackManager::FUN_1409a3410(Unk_AntiHackRecord* pRecord)
{
    int nResult = pRecord->m_kArg.vfunc_1();
}
MS2_REPLACE_METHOD(0x1409A3410, CAntiHackManager, FUN_1409a3410, 60, 0xBCDE2DFF);
