// debugconsole.h - the client's debug console log (no RTTI; 0x30 bytes, lazily created singleton 0x141168200,
// destroyed by 0x141168710): a Win32 console (AllocConsole / STD_OUTPUT_HANDLE) plus an optional
// "_DebugConsoleLog.txt" copy of every line, and named QueryPerformanceCounter timers that print the names that ran
// longer than a limit. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is unit_141168140
// (0x141168140-0x14116bdc0). NOT an original header: the class and member names are invented from use. Callers that
// predate this header view it as Unk_ExportLog (tableexporter.cpp), Unk_GsDbgLog, Unk_WsG_Sys168200.
#pragma once
#include <windows.h>
#include <stdio.h>
#include <map>
#include <string>
#include "ms2/ms2layout.h"

class CDebugConsole
{
public:
    CDebugConsole();                                                // 0x141168140
    ~CDebugConsole();                                               // 0x1411681b0 (deleting dtor 0x14116a8e0)

    static CDebugConsole* FUN_141168200();                          // the instance (created on first use)
    static void FUN_141168710();                                    // delete the instance

    bool FUN_141168270();                                           // open the console window; true when open
    void FUN_1411682d0();                                           // close the console window
    bool FUN_141168310();                                           // the console window is open
    bool FUN_141168350();                                           // toggle the CSoundDlg tool dialog; true when shown
    void FUN_1411683e0(const char* szFormat, ...);                  // print one line (console and log file)
    void FUN_141168540();                                           // (empty)
    void FUN_141168550(WORD wAttributes);                           // console text colour
    void FUN_141168580(int bFileLog);                               // copy the lines into _DebugConsoleLog.txt
    void FUN_1411685e0(std::string strName);                        // start the named timer
    void FUN_141168630(std::string strName, float fLimit);          // stop it; print it when it took over fLimit s

private:
    MS2_LAYOUT_FRIEND;
    static CDebugConsole* ms_pInstance;                             // 0x143acffb8
    static char ms_szLine[0x400];                                   // 0x143acffd0 the formatted line

    HANDLE m_hConsole;                                              // +0x00 INVALID_HANDLE_VALUE while closed
    LARGE_INTEGER m_kFrequency;                                     // +0x08
    std::map<std::string, LARGE_INTEGER> m_kTimers;                 // +0x10 timer start counts
    int m_bFileLog;                                                 // +0x20
    FILE* m_pFile;                                                  // +0x28
};
MS2_CHECK_SIZE(CDebugConsole, 0x30);
MS2_CHECK_OFFSET(CDebugConsole, m_kTimers, 0x10);
MS2_CHECK_OFFSET(CDebugConsole, m_pFile, 0x28);
