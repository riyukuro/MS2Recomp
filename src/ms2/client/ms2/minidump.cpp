// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). client\ms2\minidump.cpp: the fatal-error minidump
// writer. FUN_141484920/FUN_141484990 install/uninstall the unhandled-exception filter together with the CRT
// invalid-parameter and purecall handlers; FUN_141484a30 and the filter FUN_1414854b0 both build a file name
// ("<module> <address> @ <computer> (<date>).dmp") and hand it to FUN_141484ac0, which fills the shared detail
// text buffer (FUN_141484c70) and writes minidump.dmp with MiniDumpWriteDump.
//
// The TU carries its own copies of the three MINIDUMP structures MiniDumpWriteDump takes, packed to 4 - the exe
// frame proves the layout (MINIDUMP_EXCEPTION_INFORMATION is {DWORD, PVOID, BOOL} at +0/+4/+12, the user-stream
// information is {DWORD, PVOID} at +0/+4 and the stream entries are {DWORD, DWORD, PVOID}, 0x10 each).
// MS2-UNIT: client\ms2\minidump.cpp
// MS2-RANGE: 0x141484920-0x1414856d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\minidump.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <string>

#include "ms2/ms2recover.h"

#define PSAPI_VERSION 1  // the exe imports PSAPI.DLL!GetProcessMemoryInfo, not kernel32 K32GetProcessMemoryInfo
#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#pragma comment(lib, "dbghelp.lib")     // MiniDumpWriteDump

// ---- unit-local helpers ----

int FUN_14092c040(wchar_t* pBuffer, size_t cchBuffer, const wchar_t* pszFormat, ...);   // wide "sprintf_s" helper
int FUN_140392040(char* pBuffer, size_t nSize, const char* pszFormat, ...);              // narrow "sprintf_s" helper

// The two CRT callback stubs at 0x141485570 (spills its arguments and breaks) and 0x141485590 (nop/int3/ret),
// defined after the exception filter.
extern "C" void __cdecl FUN_141485570(const wchar_t*, const wchar_t*, const wchar_t*, unsigned, uintptr_t);
extern "C" void __cdecl FUN_141485590();

// ---- this TU's own functions ----
void FUN_141484c70(const char* pszGraphicInfo, const char* pszAdditionalInfo, wchar_t* pwszDetail, size_t nDetailSize);
bool FUN_141484ac0(LPCSTR pszPath, LPEXCEPTION_POINTERS pExceptionPointers);
LONG WINAPI FUN_1414854b0(LPEXCEPTION_POINTERS pExceptionInfo);
void FUN_1414855a0(char* pszPath, const void* pExceptionAddress);
char* FUN_1414856b0(char* pszText, int ch);                                              // strrchr (out of line in the exe)

// ---- unit-local state ----

// The three report buffers FUN_141484ac0 hands to FUN_141484c70 (they sit next to each other in the exe's .bss:
// 0x143addac0, 0x143addcc0, 0x143addec0). Note the caller passes the *byte* size of the wide buffer as the
// character count - it is 0x1000, exactly what sizeof() yields, so FUN_141484c70 is told twice the capacity it has.
char    g_szAdditionalInfo[0x200];      // 0x143addac0
char    g_szGraphicInfo[0x200];         // 0x143addcc0
wchar_t g_wszDetailInfo[0x800];         // 0x143addec0 (0x1000 bytes, the user-stream buffer below)

// MINIDUMP_TYPE the game asks for; the exe keeps it in .data with the value 2 (MiniDumpWithFullMemory).
DWORD g_dwMinidumpType = 2;             // 0x1439f7cc0

// ---- unit-local copy of the MINIDUMP structures ----

#pragma pack(push, 4)
struct MS2DumpExceptionInfo
{
    DWORD nThreadId;                    // +0x00
    void* pExceptionPointers;           // +0x04  PEXCEPTION_POINTERS
    BOOL  bClientPointers;              // +0x0c
};
struct MS2DumpUserStream
{
    DWORD nType;                        // +0x00  MiniDumpSystemInfoStream (7) / MiniDumpWriteFullMemoryStream (0xb)
    DWORD nBufferSize;                  // +0x04
    void* pBuffer;                      // +0x08
};
struct MS2DumpUserStreamInfo
{
    DWORD nNumberOfStreams;             // +0x00
    MS2DumpUserStream* pStreams;        // +0x04
};
#pragma pack(pop)

// Not declared __declspec(dllimport): the exe reaches the import through a linker-generated thunk
// (call 0x14274d664), which is what a plain declaration plus dbghelp.lib produces.
extern "C" BOOL WINAPI MiniDumpWriteDump(HANDLE hProcess, DWORD nProcessId, HANDLE hFile,
                                         DWORD nDumpType, const MS2DumpExceptionInfo* pExceptionInfo,
                                         const MS2DumpUserStreamInfo* pUserStreamInfo,
                                         void* pCallbackParam);

// ---- the installed handlers ----

static LPTOP_LEVEL_EXCEPTION_FILTER prevFilter = NULL;                  // 0x143adfec0
static _invalid_parameter_handler prevInvalidParameterHandler = NULL;   // 0x143adfec8
static _purecall_handler          prevPurecallHandler = NULL;           // 0x143adfed0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141484920
void FUN_141484920()
{
    MS2_ASSERT_AT(0x5b, prevFilter == NULL);
    prevFilter = SetUnhandledExceptionFilter(FUN_1414854b0);
    prevInvalidParameterHandler = _set_invalid_parameter_handler(FUN_141485570);
    prevPurecallHandler = _set_purecall_handler(FUN_141485590);
}

// @0x141484990
void FUN_141484990()
{
    MS2_ASSERT_AT(99, prevFilter != NULL);
    SetUnhandledExceptionFilter(prevFilter);
    _set_invalid_parameter_handler(prevInvalidParameterHandler);
    _set_purecall_handler(prevPurecallHandler);
    prevFilter = NULL;
    prevInvalidParameterHandler = NULL;
    prevPurecallHandler = NULL;
}

// @0x141484a30
void FUN_141484a30()
{
    char szPath[MAX_PATH] = "minidump.dmp";
    FUN_1414855a0(szPath, reinterpret_cast<void*>(0x7fffffff));
    FUN_141484ac0(szPath, NULL);
}

// @0x141484ac0
bool FUN_141484ac0(LPCSTR pszPath, LPEXCEPTION_POINTERS pExceptionPointers)
{
    FUN_141484c70(g_szGraphicInfo, g_szAdditionalInfo, g_wszDetailInfo, sizeof(g_wszDetailInfo));

    const MS2DumpExceptionInfo* pExceptionInfo = NULL;
    MS2DumpExceptionInfo exceptionInfo;
    if (pExceptionPointers != NULL)
    {
        exceptionInfo.bClientPointers = FALSE;
        exceptionInfo.pExceptionPointers = pExceptionPointers;
        exceptionInfo.nThreadId = GetCurrentThreadId();
        pExceptionInfo = &exceptionInfo;
    }

    SYSTEM_INFO sysInfo;
    MS2DumpUserStream astreams[2];
    astreams[0].nType = 7;
    astreams[0].nBufferSize = sizeof(sysInfo);
    GetSystemInfo(&sysInfo);
    astreams[0].pBuffer = &sysInfo;
    astreams[1].nType = 0xb;
    astreams[1].nBufferSize = sizeof(g_wszDetailInfo);
    astreams[1].pBuffer = g_wszDetailInfo;

    MS2DumpUserStreamInfo userStreamInfo;
    userStreamInfo.nNumberOfStreams = 2;
    userStreamInfo.pStreams = astreams;

    HANDLE hFile = CreateFileA(pszPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, g_dwMinidumpType, pExceptionInfo, &userStreamInfo, NULL);
    CloseHandle(hFile);
    return true;
}

// @0x141484c70
// MS2-FUNCTIONAL: the report text and the printf argument lists are reproduced from the exe, but the frame does not
// come out byte-identical (MSVC picks a different local layout for the 0x4e0-byte frame).
void FUN_141484c70(const char* pszGraphicInfo, const char* pszAdditionalInfo, wchar_t* pwszDetail, size_t nDetailSize)
{
    std::string strDetail;   // constructed and destroyed by the exe, never touched in between

    wchar_t* pwszWrite = pwszDetail;
    wchar_t* pwszEnd = pwszDetail + nDetailSize;

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    int cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"OEM ID: %d, Number of processors: %d\n", sysInfo.dwOemId, sysInfo.dwNumberOfProcessors);
    pwszWrite += cchWritten;
    cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"Processor type: %d, Processor level: %d, Processor revision: %d\n", sysInfo.dwProcessorType, sysInfo.wProcessorLevel, sysInfo.wProcessorRevision);
    pwszWrite += cchWritten;

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Hardware/Description/System/CentralProcessor/0", 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
    {
        DWORD dwType = 4;
        DWORD adwSize[3] = { 4, 1, 0 };
        DWORD dwSpeed = 0;
        if (RegQueryValueExW(hKey, L"~MHz", NULL, &dwType, (LPBYTE)&dwSpeed, adwSize) == ERROR_SUCCESS)
        {
            cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"CPU speed: %d MHz\n", dwSpeed);
            pwszWrite += cchWritten;
        }

        char szProcessor[512];
        adwSize[0] = 0x1fe;
        if (RegQueryValueExW(hKey, L"ProcessorNameString", NULL, &adwSize[1], (LPBYTE)szProcessor, adwSize) == ERROR_SUCCESS)
        {
            cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"Processor name: %s\n", szProcessor);
            pwszWrite += cchWritten;
        }
        adwSize[0] = 0x1fe;
        if (RegQueryValueExW(hKey, L"Identifier", NULL, &adwSize[1], (LPBYTE)szProcessor, adwSize) == ERROR_SUCCESS)
        {
            cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"Processor identifier: %s\n", szProcessor);
            pwszWrite += cchWritten;
        }
        RegCloseKey(hKey);
    }

    OSVERSIONINFOEXW osvi;
    memset(&osvi, 0, sizeof(osvi));
    osvi.dwOSVersionInfoSize = sizeof(osvi);
    if (GetVersionExW((LPOSVERSIONINFOW)&osvi))
    {
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite,
                                   L"dwMajorVersion: %ld; dwMinorVersion: %ld; dwBuildNumber: %ld; wServicePackMajor: %d; wServicePackMinor: %d\n",
                                   osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber, osvi.wServicePackMajor, osvi.wServicePackMinor);
        pwszWrite += cchWritten;
    }

    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    size_t nAvailVirtual = (size_t)ms.dwAvailVirtual / 0x400;
    size_t nTotalVirtual = (size_t)ms.dwTotalVirtual / 0x400;
    size_t nAvailPageFile = (size_t)ms.dwAvailPageFile / 0x400;
    size_t nTotalPageFile = (size_t)ms.dwTotalPageFile / 0x400;
    size_t nAvailPhys = (size_t)ms.dwAvailPhys / 0x400;
    cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite,
                               L"TotalPhys     : %8zuk, AvailPhys     : %8zuk, TotalPagefile : %8zuk, AvailPageFile : %8zuk, TotalVirtual  : %8zuk, AvailVirtual  : %8zuk\n",
                               (size_t)ms.dwTotalPhys / 0x400, nAvailPhys, nTotalPageFile, nAvailPageFile, nTotalVirtual, nAvailVirtual);
    pwszWrite += cchWritten;

    PROCESS_MEMORY_COUNTERS_EX pmc;
    pmc.cb = sizeof(pmc);
    if (!GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc)))
    {
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"Process memory information unavailable.\n");
        pwszWrite += cchWritten;
    }
    else
    {
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L" Process memory information ===\n");
        pwszWrite += cchWritten;
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"Page fault count           : %12ld, \n", pmc.PageFaultCount);
        pwszWrite += cchWritten;
        size_t nWorkingSet = (size_t)pmc.WorkingSetSize / 0x400;
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"PeakWorkingSetSize         : %12zdk, WorkingSetSize         : %12zdk\n",
                                   (size_t)pmc.PeakWorkingSetSize / 0x400, nWorkingSet);
        pwszWrite += cchWritten;
        size_t nQuotaPagedPool = (size_t)pmc.QuotaPagedPoolUsage / 0x400;
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"QuotaPeakPagedPoolUsage    : %12zdk, QuotaPagedPoolUsage    : %12zdk\n",
                                   (size_t)pmc.QuotaPeakPagedPoolUsage / 0x400, nQuotaPagedPool);
        pwszWrite += cchWritten;
        size_t nQuotaNonPagedPool = (size_t)pmc.QuotaNonPagedPoolUsage / 0x400;
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"QuotaPeakNonPagedPoolUsage : %12zdk, QuotaNonPagedPoolUsage : %12zdk\n",
                                   (size_t)pmc.QuotaPeakNonPagedPoolUsage / 0x400, nQuotaNonPagedPool);
        pwszWrite += cchWritten;
        size_t nPagefileUsage = (size_t)pmc.PagefileUsage / 0x400;
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"PeakPagefileUsage          : %12zdk, PagefileUsage          : %12zdk\n",
                                   (size_t)pmc.PeakPagefileUsage / 0x400, nPagefileUsage);
        pwszWrite += cchWritten;
        cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"PrivateUsage               : %12zdk\n", (size_t)pmc.PrivateUsage / 0x400);
        pwszWrite += cchWritten;
    }

    cchWritten = FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"\n Graphic Information ===\n%s\n", pszGraphicInfo);
    pwszWrite += cchWritten;
    FUN_14092c040(pwszWrite, pwszEnd - pwszWrite, L"\n Additional Information ===\n%s\n", pszAdditionalInfo);
}

// @0x1414854b0
LONG WINAPI FUN_1414854b0(LPEXCEPTION_POINTERS pExceptionInfo)
{
    char szPath[MAX_PATH];
    strcpy(szPath, "minidump.dmp");   // the exe copies the 13 bytes with no zero-fill of the rest of the buffer
    FUN_1414855a0(szPath, pExceptionInfo->ExceptionRecord->ExceptionAddress);
    FUN_141484ac0(szPath, pExceptionInfo);
    // "프로그램이 죽었습니다.\n\n개발팀에 문의해주세요." in the exe's MBCS (CP949) encoding
    MessageBoxA(NULL, "\xc7\xc1\xb7\xce\xb1\xd7\xb7\xa5\xc0\xcc \xc1\xd7\xbe\xfa\xbd\xc0\xb4\xcf\xb4\xd9.\n\n\xb0\xeb\xb9\xdf\xc6\xf7\xbf\xa1 \xb9\xae\xc0\xc7\xc7\xd8\xc1\xd6\xbc\xbc\xbf\xe4.", "MapleStory2", 0);
    TerminateProcess(GetCurrentProcess(), 2);
    return 1;
}

// The invalid-parameter handler FUN_141484920 installs: breaks into the debugger.
// MS2-FUNCTIONAL: the exe spills the four register arguments to their home slots before the int3.
// @0x141485570
extern "C" void __cdecl FUN_141485570(const wchar_t*, const wchar_t*, const wchar_t*, unsigned, uintptr_t)
{
    __debugbreak();
}

// The purecall handler FUN_141484920 installs: breaks into the debugger.
// MS2-FUNCTIONAL: the exe pads the int3 with a 2-byte nop.
// @0x141485590
extern "C" void __cdecl FUN_141485590()
{
    __debugbreak();
}

// @0x1414855a0
void FUN_1414855a0(char* pszPath, const void* pExceptionAddress)
{
    char szModulePath[MAX_PATH];
    GetModuleFileNameA(NULL, szModulePath, MAX_PATH);
    const char* pszFileName = FUN_1414856b0(szModulePath, '\\');
    DWORD cchComputer = MAX_PATH;
    char szComputer[MAX_PATH];
    GetComputerNameA(szComputer, &cchComputer);
    SYSTEMTIME st;
    GetLocalTime(&st);
    FUN_140392040(pszPath, MAX_PATH, "%s %p @ %s (%d-%02d-%02d %02d;%02d;%02d).dmp", pszFileName + 1, pExceptionAddress, szComputer,
                  st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
}

// @0x1414856b0
char* FUN_1414856b0(char* pszText, int ch)
{
    return strrchr(pszText, ch);
}
