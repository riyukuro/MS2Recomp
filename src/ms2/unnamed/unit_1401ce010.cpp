// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCrashManager (crash-report setup: CrashReporter_64.dll strings,
// dump file names, shutdown callbacks) and the template instances it brings along: the wide StringFormat/fmt writer
// COMDATs, ATL CTime accessors, the std::list<TFunctor<void,EmptyParam> > glue.
// MS2-UNIT: unit_1401ce010
// MS2-RANGE: 0x1401ce010-0x1401d1020 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$StringFormat@H@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x1401ceea0 ; unique
// MS2-PIN: ?GetDay@CTime@ATL@@QEBAHXZ 0x1401d0400 ; unique
// MS2-PIN: ?GetHour@CTime@ATL@@QEBAHXZ 0x1401d0460 ; unique
// MS2-PIN: ?GetLocalTm@CTime@ATL@@QEBAPEAUtm@@PEAU3@@Z 0x1401d04e0 ; unique
// MS2-PIN: ?GetMinute@CTime@ATL@@QEBAHXZ 0x1401d05b0 ; unique
// MS2-PIN: ?GetMonth@CTime@ATL@@QEBAHXZ 0x1401d0610 ; unique
// MS2-PIN: ?GetSecond@CTime@ATL@@QEBAHXZ 0x1401d0680 ; unique
// MS2-PIN: ?GetYear@CTime@ATL@@QEBAHXZ 0x1401d06e0 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@V?$TFunctor@XVEmptyParam@@@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@V?$TFunctor@XVEmptyParam@@@@PEAX@2@_K@Z 0x1401d0c10 ; unique
// MS2-PIN: ?type@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_KAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x1401d0e90 ; unique
// MS2-PIN: ??$?0V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@ArgType@internal@fmt@@QEAA@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x1401cee30 ; manual
// MS2-PIN: ??$make_type@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@internal@fmt@@YA_KAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x1401cfc00 ; manual
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/fmt/writer.h"
#include "ms2/commonfiles/crashmanager.h"
#include "ms2/commonfiles/filebuffer_2.h"
#include "ms2/commonfiles/timeutil.h"
#include "hook/ms2hook.h"

// @0x1401d02a0
CStringW StringFormat(const wchar_t* format, const fmt::ArgList& args)
{
    try
    {
        CStringW str = fmt::format(format, args).c_str();
        return str;
    }
    catch (std::exception& e)
    {
        // ASSERT(FALSE) of commonfiles\stringutil.h (the function body lives in that header)
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stringutil.h", 556), 0));
    }
    return format;
}

// @0x1401d0c40
std::wstring fmt::format(WStringRef format, ArgList args)
{
    WWriter w;
    w.write(format, args);
    return w.str();
}

// The crash reporter DLL (CrashReporter_64.dll) imports; the exe calls through the IAT slots.
extern "C" void (__cdecl* __imp_CrashReporter_SetDumpFileName)(const wchar_t*);
extern "C" void (__cdecl* __imp_CrashReporter_SetFullDumpPath)(const wchar_t*);
extern "C" void (__cdecl* __imp_CrashReporter_SetStrInfoA)(const wchar_t*, const char*);
extern "C" void (__cdecl* __imp_CrashReporter_SetClientExit)(int);

// The feature-flag holder; FUN_14036e510 tells whether the full-dump mode is switched on.
class Unk_FeatureHolder { public: bool FUN_14036e510(); };
Unk_FeatureHolder* FUN_140166410();

// The CrashManagerCli singleton (client\ms2\ms2.cpp), seen from its CCrashManager base.
class Unk_CrashSingleton
{
public:
    // @0x1401d04d0
    static CCrashManager* GetInstance() { return s_instance; }
    static CCrashManager* s_instance;                                   // 0x143aac538
};

// @0x1401ce010
CCrashManager::CCrashManager()
{
    m_nLogId = -1;
    m_pad_50 = 0;
    m_pad_58 = 0;
    m_bFilterHooked = false;
    m_strBuild.Format("%s %s", (LPCSTR)FormatCompileDate(CString("Apr 13 2022")), "17:36:51");
    __imp_CrashReporter_SetStrInfoA(L"Build", m_strBuild.GetBuffer());
    m_strProduct = "MapleStory2";
    m_strName = m_strProduct;
}

// @0x1401ce1d0
CCrashManager::~CCrashManager()
{
}

// @0x1401ce270
void CCrashManager::FUN_1401ce270(const CString& strLine)
{
    if (m_nLogId != -1)
        TSingleton<CFileLogger>::GetInstance()->FUN_140392750(m_nLogId, strLine);
}

// @0x1401ce2b0
void CCrashManager::FUN_1401ce2b0(const char* pszLine)
{
    if (m_nLogId != -1)
        TSingleton<CFileLogger>::GetInstance()->FUN_140392670(m_nLogId, pszLine);
}

// @0x1401ce2f0
void CCrashManager::FUN_1401ce2f0(const char* pszFormat, ...)
{
    if (m_nLogId != -1)
    {
        CString strLine;
        va_list args;
        va_start(args, pszFormat);
        strLine.FormatV(pszFormat, args);
        va_end(args);
        TSingleton<CFileLogger>::GetInstance()->FUN_140392670(m_nLogId, strLine.GetBuffer());
    }
}

// @0x1401ce3a0
void CCrashManager::FUN_1401ce3a0()
{
    TSingleton<CFileLogger>::GetInstance()->FUN_1403922d0(m_nLogId);
}

// @0x1401ce3d0
void CCrashManager::FUN_1401ce3d0(TFunctor<void, EmptyParam> callback)
{
    m_callbacks.push_back(callback);
}

// @0x1401ce420
void CCrashManager::FUN_1401ce420()
{
    m_callbacks.clear();
    __imp_CrashReporter_SetClientExit(0);
}

// @0x1401ce450
void CCrashManager::FUN_1401ce450()
{
}

// @0x1401ce460
CStringW CCrashManager::FUN_1401ce460()
{
    if (!m_strDumpPath.IsEmpty())
        return m_strDumpPath;
    CStringW strPath;
    __time64_t now;
    _time64(&now);
    CTime time(now);
    CStringW strDir;
    if (!strDir.IsEmpty() && GetFileAttributesW(strDir) != INVALID_FILE_ATTRIBUTES)
    {
        CString strBuild = m_strBuild;
        strBuild.Format("%s %s", (LPCSTR)FormatCompileDate(CString("Apr 13 2022")), "17:36:51");
        strBuild.Remove(':');
        strBuild.Replace(' ', '_');
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nHour = time.GetHour();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        int nYear = time.GetYear();
        strPath = StringFormat(L"{0}/{1}_{2}/{3}_{1}_{4:04d}{5:02d}{6:02d}_{7:02d}{8:02d}{9:02d}.dmp",
                               strDir, m_strName, strBuild, m_strServer, nYear, nMonth, nDay, nHour, nMinute, nSecond);
    }
    else
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nHour = time.GetHour();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        int nYear = time.GetYear();
        strPath = StringFormat(L"Dump_{0}_{1:04d}{2:02d}{3:02d}_{4:02d}{5:02d}{6:02d}.dmp",
                               m_strName, nYear, nMonth, nDay, nHour, nMinute, nSecond);
    }
    m_strDumpPath = strPath;
    return strPath;
}
MS2_REPLACE_METHOD(0x1401ce460, CCrashManager, FUN_1401ce460, 1128, 0x562C8DC6);

// @0x1401ce8d0
CString CCrashManager::FUN_1401ce8d0()
{
    CString strResult;
    strResult.Format("%s %s", (LPCSTR)m_strName, (LPCSTR)CString(m_strBuild));
    strResult.Remove(':');
    return strResult;
}

// @0x1401ce9b0
void CCrashManager::FUN_1401ce9b0()
{
}

// @0x1401ce9c0
void CCrashManager::FUN_1401ce9c0()
{
    HMODULE hKernel32 = LoadLibraryA("kernel32.dll");
    FARPROC pOrgEntry = GetProcAddress(hKernel32, "SetUnhandledExceptionFilter");
    if (pOrgEntry != 0)
    {
        m_bFilterHooked = true;
        BYTE expected[5] = {0x8B, 0xFF, 0x55, 0x8B, 0xEC};
        if (memcmp(expected, pOrgEntry, 5) == 0)
        {
            BYTE patch[5] = {0x33, 0xC0, 0xC2, 0x04, 0x00};
            DWORD dwOldProtect;
            if (!VirtualProtect(pOrgEntry, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect))
            {
                m_bFilterHooked = false;
            }
            else
            {
                memcpy(pOrgEntry, patch, 5);
                DWORD dwTemp;
                if (!VirtualProtect(pOrgEntry, 5, dwOldProtect, &dwTemp))
                    m_bFilterHooked = false;
                else if (!FlushInstructionCache(GetCurrentProcess(), pOrgEntry, 5))
                    m_bFilterHooked = false;
            }
        }
        else
        {
            m_bFilterHooked = false;
        }
    }
    FreeLibrary(hKernel32);
}
MS2_REPLACE_METHOD(0x1401ce9c0, CCrashManager, FUN_1401ce9c0, 366, 0xCDACFBF2);

// @0x1401ceb40
void CCrashManager::FUN_1401ceb40()
{
}

// @0x1401ceb50
void CCrashManager::FUN_1401ceb50()
{
}

// @0x1401ceb60
void FUN_1401ceb60()
{
    if (!FUN_140166410()->FUN_14036e510())
    {
        CStringW strPath = Unk_CrashSingleton::GetInstance()->FUN_1401ce460();
        __imp_CrashReporter_SetFullDumpPath(strPath.GetBuffer());
    }
    else
    {
        int nStart = 0;
        CStringW strPath = Unk_CrashSingleton::GetInstance()->FUN_1401ce460();
        CStringW strName = strPath.Tokenize(L".", nStart);
        CStringW strExt = strPath.Tokenize(L".", nStart);
        int nIndex = 0;
#ifdef __clang__
        // clang emits an unavailable MFC CopyChars import for operator+; build the same string by appending
        CStringW strFull(L"./FullDump/Full");
        strFull.Append(strName);
        strFull.Append(StringFormat(L"_{0}.", nIndex));
        strFull.Append(strExt);
        __imp_CrashReporter_SetFullDumpPath(strFull.GetString());
#else
        __imp_CrashReporter_SetFullDumpPath(L"./FullDump/Full" + strName + StringFormat(L"_{0}.", nIndex) + strExt);
#endif
        __imp_CrashReporter_SetDumpFileName(StringFormat(L"dump{0}", nIndex));
    }
}

// @0x1401ced80
void FUN_1401ced80()
{
    TSingleton<CFileLogger>::GetInstance()->FUN_140392430();
}

// @0x1401d0f00
MS2_EMIT_CRT_MEMMOVE_S();
