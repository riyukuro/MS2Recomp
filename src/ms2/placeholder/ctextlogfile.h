// ctextlogfile.h - PLACEHOLDER for CTextLogFile (RTTI .?AVCTextLogFile@@, vftable 0x142d9b308, deleting dtor 0x140867dc0): the
// crash-report log file object. NOT an original header; only what filebuffer.cpp#2 (CFileLogger) touches is named. The
// unit that owns the code is ?\textlogfile.cpp (0x140866b00-0x1408686b0, unrecovered). CPtred-derived, 0x58 bytes.
// Layout from ctor 0x140866b40: m_name (CStringW) at +0x18, two 16-byte line lists at +0x20 and +0x30 (ctor
// 0x140867b00), the byte limit pair at +0x40/+0x48 (-1 = unlimited) and a dword (0x18) at +0x50.
#pragma once

#include <afx.h>
#include <list>
#include <utility>
#include <time.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CTextLogFile : public CPtred
{
public:
    explicit CTextLogFile(const wchar_t* pszName);          // 0x140866b40
    virtual ~CTextLogFile();                                // 0x140866c00

    void FUN_140866c70();                                   // write the file next to the exe and drop the lines
    void FUN_140866f60(const char* pszLine);                // add a line to the first list
    void FUN_140867020(const char* pszLine);                // add a line to the second list
    void FUN_1408670e0(const CString& strLine);             // as 0x140866f60 for a CString
    void FUN_140867180(const CString& strLine);             // as 0x140867020 for a CString
    void FUN_140867220();                                   // clear the second list
    void FUN_140867260(unsigned long long nLimit);                // set the byte limit
    void FUN_140867330(__int64 nLen);                       // account a line against the budget
    const CStringW& GetName() const;                  // the file name

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_name;                                        // +0x18
    std::list<std::pair<__time64_t, CString> > m_lines;     // +0x20 the head lines (time, text)
    std::list<std::pair<__time64_t, CString> > m_tail;      // +0x30 the body lines
    unsigned __int64 m_nLimit;                                       // +0x40 the byte limit (-1 = unlimited)
    unsigned __int64 m_nRemain;                                      // +0x48 bytes left
    int m_nLineExtra;                                       // +0x50 bytes added to every line (0x18)
    int m_nPad54;
};
MS2_CHECK_SIZE(CTextLogFile, 0x58);
