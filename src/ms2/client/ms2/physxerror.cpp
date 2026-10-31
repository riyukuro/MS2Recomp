// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2/placeholder/physxerror.h.
// MS2-UNIT: ?\physxerror.cpp
// MS2-RANGE: 0x1416889f0-0x14168917b .text$mn
// MS2-PIN: ??_GCPhysXError@@UEAAPEAXI@Z 0x141689100
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\physxerror.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <string>

#include "ms2/placeholder/physxerror.h"
#include "ms2/commonfiles/crashmanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/placeholder/crashmanagercli.h"

// ---- unit-local placeholders ----

void* FUN_140166440();                                              // the logger
void FUN_1403a1310(void* pLogger, int nLevel, int nId, const wchar_t* pszFormat, const char* const& a, const char* const& b);
void FUN_1401859c0(void* pLogger, int nLevel, int nId, const wchar_t* pszText);
CStringW FUN_14016a730(const char* psz, int n);                     // narrow -> wide
int FUN_140392040(char* pBuffer, size_t nSize, const char* pszFormat, ...);
void FUN_141b6fc50(const CString& strText, const CString& strCaption, int n);   // message box

// The event sink (TSingleton<CBigDataLogSystem>::GetInstance).

extern char DAT_143ae37d0[0x100];                                   // message buffer

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1416889f0
CPhysXError::CPhysXError()
{
}

// @0x141688a30
CPhysXError::~CPhysXError()
{
}

// Not hooked (throws/terminates).
// @0x141688a60
void CPhysXError::reportError(NxErrorCode code, const char* message, const char* file, int line)
{
    std::string strType;
    bool bLogOnly = false;
    switch (code)
    {
    case NXE_NO_ERROR:
        strType.assign("No Error");
        bLogOnly = true;
        break;
    case NXE_INVALID_PARAMETER:
        strType.assign("Invalid Parameter");
        break;
    case NXE_INVALID_OPERATION:
        strType.assign("Invalid Operation");
        break;
    case NXE_OUT_OF_MEMORY:
        strType.assign("Out of Memory");
        break;
    case NXE_INTERNAL_ERROR:
        strType.assign("Internal Error");
        break;
    case NXE_ASSERTION:
        strType.assign("Assertion");
        break;
    case NXE_DB_INFO:
        strType.assign("Debug Info");
        bLogOnly = true;
        break;
    case NXE_DB_WARNING:
        strType.assign("Debug Warning");
        bLogOnly = true;
        break;
    case NXE_DB_PRINT:
        strType.assign("Debug Print");
        bLogOnly = true;
    }
    if (bLogOnly)
    {
        const char* pszType = strType.c_str();
        FUN_1403a1310(FUN_140166440(), 2, 0x13, L"{0} {1}", pszType, message);
    }
    else
    {
        if (TSingleton<CBigDataLogSystem>::GetInstance() != 0)
        {
            CString strLog;
            strLog.Format("%s %s", strType.c_str(), message);
            TSingleton<CBigDataLogSystem>::GetInstance()->SendLog("physx", strLog);
        }
        switch (code)
        {
        case NXE_INTERNAL_ERROR:
            FUN_140392040(DAT_143ae37d0, 0x100, "%s \nCheck your graphic driver.", message);
            FUN_141b6fc50(DAT_143ae37d0, "PhysX", 0);
            TerminateProcess(GetCurrentProcess(), 2);
            break;
        case NXE_OUT_OF_MEMORY:
            FUN_141b6fc50(message, "PhysX", 0);
            TerminateProcess(GetCurrentProcess(), 2);
            break;
        }
        reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2b0("\n--- CPhysXError Log---");
        reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2f0("reportError : %s, %s, %s, %d", strType.c_str(), message, file, line);
        throw 13;
    }
}

// @0x141688f50
NxAssertResponse CPhysXError::reportAssertViolation(const char* message, const char* file, int line)
{
    reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2b0("\n--- CPhysXError Log---");
    reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2f0("reportAssertViolation : %s, %s, Line:%d", message, file, line);
    if (TSingleton<CBigDataLogSystem>::GetInstance() != 0)
    {
        CString strLog;
        strLog.Format("assert %s %s %d", message, file, line);
        TSingleton<CBigDataLogSystem>::GetInstance()->SendLog("physx", strLog);
    }
    return NX_AR_CONTINUE;
}
MS2_REPLACE_METHOD(0x141688f50, CPhysXError, reportAssertViolation, 222, 0xE2694B8D);

// @0x141689040
void CPhysXError::print(const char* message)
{
    FUN_1401859c0(FUN_140166440(), 1, 0x13, FUN_14016a730(message, 0));
}
MS2_REPLACE_METHOD(0x141689040, CPhysXError, print, 121, 0x39255ECB);
