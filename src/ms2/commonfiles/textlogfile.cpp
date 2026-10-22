// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTextLogFile: the crash-report text log. It collects time-stamped
// lines in two lists (head and body), keeps a byte budget and writes both to a file next to the exe when asked.
// MS2-UNIT: ?\textlogfile.cpp
// MS2-RANGE: 0x140866b00-0x1408686b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEA_JAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$0A@@?$pair@_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@QEAA@AEA_JAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x140867520 ; unique
// MS2-PIN: ??$?0_JPEBD$0A@@?$pair@_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@QEAA@$$QEAU?$pair@_JPEBD@1@@Z 0x140867570 ; unique
// MS2-PIN: ??$make_pair@AEA_JAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@YA?AU?$pair@_JV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@0@AEA_JAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1408678e0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\textlogfile.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ctextlogfile.h"
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The two section headings of the file (the exe keeps them as pointer variables in .data).
static const char* s_pszHeadSection = "=================[CRASH REPORTER LOGGER HEAD]=================\r\n";
static const char* s_pszBodySection = "=================[CRASH REPORTER LOGGER BODY]=================\r\n";

// @0x140866b00
tm* FUN_140866b00(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// @0x140866b20
__time64_t FUN_140866b20(__time64_t* pTime)
{
    return _time64(pTime);
}

// @0x140866b40
CTextLogFile::CTextLogFile(const wchar_t* pszName)
{
    m_nLimit = -1;
    m_nRemain = 0;
    m_name = pszName;
    m_nLineExtra = 0x18;
}

// @0x140866c00
CTextLogFile::~CTextLogFile()
{
}

// The time stamp text of a log line.
CString FUN_1408673d0(const __time64_t* pTime);

// MS2-FUNCTIONAL: fprintf/loop block layout (2 bytes longer)
// @0x140866c70
void CTextLogFile::FUN_140866c70()
{
    if (!m_lines.empty() || !m_tail.empty()) {
        WCHAR szModule[MAX_PATH];
        WCHAR szPath[MAX_PATH];
        LPWSTR pszFile;
        GetModuleFileNameW(0, szModule, MAX_PATH);
        GetFullPathNameW(szModule, MAX_PATH, szPath, &pszFile);
        if (pszFile != 0)
            *pszFile = L'\0';
        wcscat_s(szPath, MAX_PATH, m_name);
        FILE* pFile = _wfopen(szPath, L"w");
        fprintf(pFile, s_pszHeadSection);
        for (std::list<std::pair<__time64_t, CString> >::iterator it = m_lines.begin(); it != m_lines.end(); ++it) {
            const char* pszText = it->second.GetBuffer();
            fprintf(pFile, "[%s] %s\r\n", FUN_1408673d0(&it->first).GetBuffer(), pszText);
        }
        fprintf(pFile, s_pszBodySection);
        for (std::list<std::pair<__time64_t, CString> >::iterator it = m_tail.begin(); it != m_tail.end(); ++it) {
            const char* pszText = it->second.GetBuffer();
            fprintf(pFile, "[%s] %s\r\n", FUN_1408673d0(&it->first).GetBuffer(), pszText);
        }
        fclose(pFile);
        FUN_140867220();
    }
}

// MS2-FUNCTIONAL: inline strlen loop shape (exe increments in place, compares the byte directly)
// MS2-FUNCTIONAL: inline strlen loop shape
// @0x140866f60
void CTextLogFile::FUN_140866f60(const char* pszLine)
{
    if (m_nLimit != -1) {
        __int64 nLen = -1;
        do {
            ++nLen;
        } while (pszLine[nLen]);
        FUN_140867330(nLen);
    }
    __time64_t tNow;
    FUN_140866b20(&tNow);
    m_lines.push_back(std::make_pair(tNow, pszLine));
}

// MS2-FUNCTIONAL: inline strlen loop shape (exe increments in place, compares the byte directly)
// MS2-FUNCTIONAL: inline strlen loop shape
// @0x140867020
void CTextLogFile::FUN_140867020(const char* pszLine)
{
    if (m_nLimit != -1) {
        __int64 nLen = -1;
        do {
            ++nLen;
        } while (pszLine[nLen]);
        FUN_140867330(nLen);
    }
    __time64_t tNow;
    FUN_140866b20(&tNow);
    m_tail.push_back(std::make_pair(tNow, pszLine));
}

// @0x1408670e0
void CTextLogFile::FUN_1408670e0(const CString& strLine)
{
    if (m_nLimit != -1)
        FUN_140867330(strLine.GetLength());
    __time64_t tNow;
    FUN_140866b20(&tNow);
    m_lines.push_back(std::make_pair(tNow, strLine));
}

// @0x140867180
void CTextLogFile::FUN_140867180(const CString& strLine)
{
    if (m_nLimit != -1)
        FUN_140867330(strLine.GetLength());
    __time64_t tNow;
    FUN_140866b20(&tNow);
    m_tail.push_back(std::make_pair(tNow, strLine));
}

// @0x140867220
void CTextLogFile::FUN_140867220()
{
    m_tail.clear();
    m_nRemain = m_nLimit;
}

// MS2-FUNCTIONAL: inline strlen loop shape (exe increments in place, compares the byte directly)
// MS2-FUNCTIONAL: inline strlen loop shape
// @0x140867260
void CTextLogFile::FUN_140867260(unsigned long long nLimit)
{
    const char* pszHead = s_pszHeadSection;
    __int64 nHead = -1;
    do {
        ++nHead;
    } while (pszHead[nHead]);
    const char* pszBody = s_pszBodySection;
    __int64 nBody = -1;
    do {
        ++nBody;
    } while (pszBody[nBody]);
    nLimit = nLimit - (nHead + nBody);
    m_nLimit = nLimit;
    m_nRemain = nLimit;
}

// @0x140867310
const CStringW& CTextLogFile::GetName() const
{
    return m_name;
}

// @0x140867330
void CTextLogFile::FUN_140867330(__int64 nLen)
{
    m_nRemain = m_nRemain - (nLen + m_nLineExtra);
    while (m_nRemain < 0) {
        m_nRemain = m_nRemain + (m_tail.front().second.GetLength() + m_nLineExtra);
        m_tail.pop_front();
    }
}

// @0x1408673d0
CString FUN_1408673d0(const __time64_t* pTime)
{
    CString strTime;
    char szText[1024];
    tm* pTm = FUN_140866b00(pTime);
    strftime(szText, 1024, "%Y-%m-%d %H:%M:%S", pTm);
    strTime = szText;
    return strTime;
}

MS2_EMIT_CRT_MEMMOVE_S();
