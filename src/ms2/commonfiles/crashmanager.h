// crashmanager.h - CCrashManager (RTTI name): the client's crash-report setup. It owns the crash-report log id (a
// CFileLogger file), the product/build strings handed to CrashReporter_64.dll and the list of callbacks run on shutdown.
// CrashManagerCli (client\ms2\ms2.cpp) derives from it. Member names are invented from their use.
// Owning unit: unit_1401ce010 (0x1401ce010-0x1401d1020 .text$mn).
#pragma once

#include <afx.h>
#include <atlstr.h>
#include <list>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/tfunctor.h"

class CCrashManager
{
public:
    CCrashManager();                                                    // 0x1401ce010
    virtual ~CCrashManager();                                           // 0x1401ce1d0 (??_G 0x1401d0260)

    void AddLogLine(const CString& strLine);                         // add a line to the log's second list
    void FUN_1401ce2b0(const char* pszLine);                            // add a line to the log's second list
    void FUN_1401ce2f0(const char* pszFormat, ...);                     // printf-style line, second list
    void FlushLog();                                               // flush the log file
    void AddCallback(TFunctor<void, EmptyParam> callback);            // register a shutdown callback
    void FUN_1401ce420();                                               // drop the callbacks and mark a clean exit
    void FUN_1401ce450();                                               // no-op
    CStringW GetDumpPath();                                           // the dump file path (built once)
    CString GetBuildString();                                            // the build string without ':'
    void FUN_1401ce9b0();                                               // no-op
    void DisableUnhandledExceptionFilter();                                               // disable the CRT's SetUnhandledExceptionFilter
    void FUN_1401ceb40();                                               // no-op
    void FUN_1401ceb50();                                               // no-op

protected:
    MS2_LAYOUT_FRIEND;
    int m_nLogId;                                                       // +0x08 CFileLogger id, -1 = none
    CString m_strProduct;                                               // +0x10 "MapleStory2"
    CString m_str18;                                                    // +0x18
    CString m_strServer;                                                // +0x20
    CString m_strName;                                                  // +0x28 copy of the product name
    CString m_strBuild;                                                 // +0x30 "<compile date> <time>"
    CStringW m_strDumpPath;                                             // +0x38
    std::list<TFunctor<void, EmptyParam> > m_callbacks;                 // +0x40
    void* m_pad_50;                                                     // +0x50
    void* m_pad_58;                                                     // +0x58
    bool m_bFilterHooked;                                               // +0x60
};
MS2_CHECK_SIZE(CCrashManager, 0x68);
MS2_CHECK_OFFSET(CCrashManager, m_nLogId, 0x8);
MS2_CHECK_OFFSET(CCrashManager, m_strBuild, 0x30);
MS2_CHECK_OFFSET(CCrashManager, m_strDumpPath, 0x38);
MS2_CHECK_OFFSET(CCrashManager, m_callbacks, 0x40);
MS2_CHECK_OFFSET(CCrashManager, m_bFilterHooked, 0x60);
