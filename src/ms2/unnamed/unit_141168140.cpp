// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's debug console log (CDebugConsole, see
// client/ms2/debugconsole.h): console window, optional log file, named QueryPerformanceCounter timers, the CSoundDlg
// tool-dialog toggle, and the std::map<std::string, LARGE_INTEGER> glue of the timers.
// MS2-UNIT: unit_141168140
// MS2-RANGE: 0x141168140-0x14116bdc0 .text$mn
// MS2-PIN: memcpy_s 0x14116bc70
#define NOMINMAX
#define MS2_THIS_FILE ""
// The TU-local UCRT memcpy_s calls memcpy / memset out of line; the pragma must precede its inline definition.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <stdarg.h>
#include "ms2/client/ms2/debugconsole.h"
#include "ms2/client/ms2/sounddlg.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#pragma intrinsic(memset, memcpy)

// ---- unit-local views of exe objects ----

class Unk_DcApp;                                                    // the client application object
Unk_DcApp* FUN_140aadf80();
HWND FUN_14209c720(Unk_DcApp* pApp);                                // its main window

// ---- CDebugConsole ----

CDebugConsole* CDebugConsole::ms_pInstance = 0;
char CDebugConsole::ms_szLine[0x400];

// @0x141168140
CDebugConsole::CDebugConsole()
    : m_hConsole(INVALID_HANDLE_VALUE)
{
    QueryPerformanceFrequency(&m_kFrequency);
    m_pFile = NULL;
    m_bFileLog = 0;
}

// @0x1411681b0
CDebugConsole::~CDebugConsole()
{
    if (m_pFile != NULL) {
        fclose(m_pFile);
        m_pFile = NULL;
    }
}

// @0x141168200
CDebugConsole* CDebugConsole::FUN_141168200()
{
    if (ms_pInstance == 0)
        ms_pInstance = new CDebugConsole;
    return ms_pInstance;
}
MS2_REPLACE(0x141168200, CDebugConsole::FUN_141168200, 106, 0x9A07A980);

// @0x141168270
bool CDebugConsole::FUN_141168270()
{
    if (m_hConsole != INVALID_HANDLE_VALUE)
        return true;
    if (AllocConsole() == 0)
        return false;
    m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (m_hConsole == INVALID_HANDLE_VALUE) {
        FreeConsole();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141168270, CDebugConsole, FUN_141168270, 85, 0xE80C87F1);

// @0x1411682d0
void CDebugConsole::FUN_1411682d0()
{
    if (m_hConsole == INVALID_HANDLE_VALUE)
        return;
    if (FreeConsole() != 0)
        m_hConsole = INVALID_HANDLE_VALUE;
}
MS2_REPLACE_METHOD(0x1411682d0, CDebugConsole, FUN_1411682d0, 49, 0x9EE64F43);

// @0x141168310
bool CDebugConsole::FUN_141168310()
{
    return m_hConsole != INVALID_HANDLE_VALUE;
}
MS2_REPLACE_METHOD(0x141168310, CDebugConsole, FUN_141168310, 45, 0xA729B5DF);

// @0x141168350
bool CDebugConsole::FUN_141168350()
{
    if (TSingleton<CSoundDlg>::GetInstance() != 0 && TSingleton<CSoundDlg>::GetInstance()->IsNotCreated() == 0) {
        TSingleton<CSoundDlg>::DestroyInstance();
        return false;
    } else {
        TSingleton<CSoundDlg>::DestroyInstance();
        TSingleton<CSoundDlg>::CreateInstance();
        TSingleton<CSoundDlg>::GetInstance()->Create(0x92, CWnd::FromHandle(FUN_14209c720(FUN_140aadf80())));
    }
    return true;
}
MS2_REPLACE_METHOD(0x141168350, CDebugConsole, FUN_141168350, 130, 0x64B89D35);

// @0x1411683e0
void CDebugConsole::FUN_1411683e0(const char* szFormat, ...)
{
    DWORD dwWritten = 0;
    vsprintf(ms_szLine, szFormat, (va_list)(&szFormat + 1));
    if (m_hConsole != INVALID_HANDLE_VALUE) {
        WriteFile(m_hConsole, ms_szLine, (DWORD)strlen(ms_szLine), &dwWritten, NULL);
        WriteFile(m_hConsole, "\n", 1, &dwWritten, NULL);
    }
    if (m_bFileLog != 0 && m_pFile != NULL) {
        fwrite(ms_szLine, strlen(ms_szLine), 1, m_pFile);
        fwrite("\n", 1, 1, m_pFile);
    }
}

// @0x141168540
void CDebugConsole::FUN_141168540()
{
}

// @0x141168550
void CDebugConsole::FUN_141168550(WORD wAttributes)
{
    SetConsoleTextAttribute(m_hConsole, wAttributes);
}
MS2_REPLACE_METHOD(0x141168550, CDebugConsole, FUN_141168550, 38, 0x36E7D499);

// @0x141168580
void CDebugConsole::FUN_141168580(int bFileLog)
{
    if (bFileLog != 0 && m_pFile == NULL)
        m_pFile = fopen("_DebugConsoleLog.txt", "w");
    m_bFileLog = bFileLog;
}
MS2_REPLACE_METHOD(0x141168580, CDebugConsole, FUN_141168580, 78, 0xDD08726C);

// @0x1411685e0
void CDebugConsole::FUN_1411685e0(std::string strName)
{
    QueryPerformanceCounter(&m_kTimers[strName]);
}
MS2_REPLACE_METHOD(0x1411685e0, CDebugConsole, FUN_1411685e0, 70, 0x1A6C482A);

// @0x141168630
void CDebugConsole::FUN_141168630(std::string strName, float fLimit)
{
    LARGE_INTEGER kNow;
    QueryPerformanceCounter(&kNow);
    float fElapsed = ((float)kNow.QuadPart - (float)m_kTimers[strName].QuadPart) / (float)m_kFrequency.QuadPart;
    if (fElapsed > fLimit) {
        FUN_141168550(FOREGROUND_RED);
        FUN_1411683e0("%s [%f]", strName.c_str(), (double)fElapsed);
    }
}
MS2_REPLACE_METHOD(0x141168630, CDebugConsole, FUN_141168630, 213, 0x937C86E9);

// @0x141168710
void CDebugConsole::FUN_141168710()
{
    if (ms_pInstance != 0) {
        delete ms_pInstance;
        ms_pInstance = 0;
    }
}
MS2_REPLACE(0x141168710, CDebugConsole::FUN_141168710, 91, 0x88EAD335);

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// The std::map<std::string, LARGE_INTEGER> glue (0x141168770-0x14116bdc0) comes from m_kTimers.
