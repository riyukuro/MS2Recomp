// filebuffer_2.h - CFileLogger (RTTI name): the process-wide registry of crash-report log files. Files are opened by id,
// written to through the id, and flushed to disk (and their paths remembered) on close; the remembered paths can be
// deleted again later. Singleton (TSingleton<CFileLogger>). Member and helper names are invented from their use.
// Owning unit: commonfiles\filebuffer.cpp#2 (0x1403920a0-0x140395ff0 .text$mn, 0x1400b6260 .text$di).
#pragma once

#include <afx.h>
#include <map>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ctextlogfile.h"

class CFileLogger : public TSingleton<CFileLogger>
{
public:
    CFileLogger();                                          // 0x1403920a0
    virtual ~CFileLogger();                                 // 0x1403920e0

    int OpenLog(const wchar_t* pszName);              // open a log file, returns its id
    void SetLogFileLimit(int nId, unsigned int nLimit);                // set the file's byte limit
    void FUN_140392270(int nId);                            // clear the file's second list
    void FlushLog(int nId);                            // remember the file's name and write it out
    void FlushAndClearAll();                                   // write every file out and forget them
    void FUN_140392430();                                   // delete the remembered files
    void FUN_140392600(int nId, const char* pszLine);       // add a line to the first list
    void FUN_140392670(int nId, const char* pszLine);       // add a line to the second list
    void FUN_1403926e0(int nId, const CString& strLine);    // add a line to the first list
    void FUN_140392750(int nId, const CString& strLine);    // add a line to the second list

    // @0x140394b50
    static CTextLogFile* FUN_140394b50(int nId)
    {
        std::map<int, MS2Ptr<CTextLogFile> >::iterator it = ms_files.find(nId);
        if (it != ms_files.end())
            return it->second.get();
        return 0;
    }

private:
    static std::map<int, MS2Ptr<CTextLogFile> > ms_files;   // 0x143aaec60
    static std::set<CStringW> ms_paths;                     // 0x143aaec70
    static CRITICAL_SECTION ms_cs;                          // 0x143aaec80
    static int ms_nLastId;                                  // 0x143aaeca8
    static int ms_bInit;                                    // 0x143aaecac
};
MS2_CHECK_SIZE(CFileLogger, 0x8);
