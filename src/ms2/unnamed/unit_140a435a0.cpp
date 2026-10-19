// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CrashManagerCli (the client's crash handler setup: the
// CrashReporter_64.dll callbacks, the process-wide error handlers and the crash-log entry map) with its
// ATL::CRBMap<int, CString> and std::list<TFunctor> glue.
// MS2-UNIT: unit_140a435a0
// MS2-RANGE: 0x140a435a0-0x140a45d40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@K@ATL@@SA_NAEBK0@Z 0x140a445e0 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@K@ATL@@SAHAEBK0@Z 0x140a44630 ; unique
// MS2-PIN: ?Find@?$CRBTree@KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@K@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@IEBAPEAVCNode@12@K@Z 0x140a44670 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include <csignal>
#include <new.h>
#include <eh.h>
#include "ms2/commonfiles/filebuffer_2.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "ms2/placeholder/iclientplatform.h"
#include "hook/ms2hook.h"

// The CrashReporter_64.dll imports; the exe calls through the IAT slots.
extern "C" void (__cdecl* __imp_CrashReporter_Init)(const wchar_t*, int);
extern "C" void (__cdecl* __imp_CrashReporter_RegisterCallback_BeforeDump)(void (__cdecl*)());
extern "C" void (__cdecl* __imp_CrashReporter_RegisterCallback_AfterDump)(void (__cdecl*)());
extern "C" void (__cdecl* __imp_CrashReporter_SetDumpFileName)(const wchar_t*);
extern "C" void (__cdecl* __imp_CrashReporter_SetFullDumpPath)(const wchar_t*);

// The modal "the game crashed" dialog (a global instance); the message text sits behind the CDialog base.
class Unk_CrashDialog : public CDialog
{
public:
    void FUN_140a45970(CString strMessage);                 // 0x140a45970
    void* m_unknown130[8];                                  // +0x130 unrecovered dialog members
    CString m_strMessage;                                   // +0x170
};
MS2_CHECK_OFFSET(Unk_CrashDialog, m_strMessage, 0x170);
extern Unk_CrashDialog g_dlgCrash;                          // 0x143af7f80
extern DWORD g_dwCrashMainThreadId;                         // 0x143aac530
extern LPTOP_LEVEL_EXCEPTION_FILTER g_pfnPrevExceptionFilter;   // 0x143ab6728

class Unk_ImgTagSource;
Unk_ImgTagSource* FUN_14025e7a0();
unsigned FUN_1422af8a0(Unk_ImgTagSource* pSource, int nKind);
CStringW FUN_14028de60(int nStringId);
CString FUN_14016a600(const wchar_t* pwsz, int n);          // wide -> narrow
IClientPlatform* FUN_140d86260();
void FUN_141b6db40(int nCode);
class Unk_FeatureHolder { public: bool FUN_14036e510(); };
Unk_FeatureHolder* FUN_140166410();
void FUN_140a43b20();
void FUN_140a43d40();
void FUN_140a43f00();
LONG WINAPI FUN_140a43fa0(EXCEPTION_POINTERS* pException);
#define SIGABRT_COMPAT 22

// @0x140a435a0
// MS2-FUNCTIONAL: frame 0x50 vs 0x48: the exe keeps the CString temporaries in named locals
void CrashManagerCli::FUN_140a435a0()
{
    g_dwCrashMainThreadId = GetCurrentThreadId();
    int nPlatform = 0;
    int nReportMode = 3;
    const wchar_t* apszProduct[9] = {L"ms2_kr",  L"ms2_krcenter", L"ms2_krlogin",   L"ms2_krgame",   L"ms2_dev",
                                     L"ms2_dev_64", L"ms2_devserver", L"ms2_devserver", L"ms2_devserver"};
    (void)nPlatform;
    (void)apszProduct;
    __imp_CrashReporter_Init(L"ms2_kr", nReportMode);
    __imp_CrashReporter_RegisterCallback_BeforeDump(FUN_140a43b20);
    m_nLogId = TSingleton<CFileLogger>::GetInstance()->FUN_140392110(L"MS2Log.txt");
    __imp_CrashReporter_RegisterCallback_AfterDump(FUN_140a43d40);
    g_pfnPrevExceptionFilter = SetUnhandledExceptionFilter(FUN_140a43fa0);
    CStringW strMessage = FUN_14028de60(0xc3d);
    g_dlgCrash.FUN_140a45970(FUN_14016a600(strMessage, 0));
    FUN_140a43f00();
}

// @0x140a43750
void CrashManagerCli::FUN_140a43750(DWORD nId, CString strText)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_map.SetAt(nId, strText);
}

// @0x140a437d0
void CrashManagerCli::FUN_140a437d0(DWORD nId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_map.RemoveKey(nId);
}

// @0x140a43830
// MS2-FUNCTIONAL: iterator locals / ATL accessors order differs
void CrashManagerCli::FUN_140a43830()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    POSITION pos = m_map.GetHeadPosition();
    while (pos != NULL)
    {
        const CString& strValue = m_map.GetValueAt(pos);
        const DWORD& nKey = m_map.GetKeyAt(pos);
        FUN_1401ce270(Unk_SocketFormat("{0} {1}", nKey, strValue));
        m_map.GetNext(pos);
    }
}

// @0x140a43920
// MS2-FUNCTIONAL: exe copies the Lookup result through a char local; no source form found
bool CrashManagerCli::FUN_140a43920(DWORD nId, CString& strText)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_map.Lookup(nId, strText) != 0;
}

// @0x140a439b0
void FUN_140a439b0(void*)
{
    FUN_140a43f00();
}

// @0x140a439d0
void FUN_140a439d0()
{
    FUN_140d86260()->vfunc_23(10, "Crash");
    DWORD dwThread = GetCurrentThreadId();
    if (g_dwCrashMainThreadId == dwThread)
    {
        if (TSingleton<CrashManagerCli>::GetInstance() != 0)
        {
            unsigned nImgTag = FUN_1422af8a0(FUN_14025e7a0(), 2);
            TSingleton<CrashManagerCli>::GetInstance()->FUN_1401ce2f0("MyPreErrHandler ImgTag:%x", nImgTag);
            std::list<TFunctor<void, EmptyParam> >& callbacks = TSingleton<CrashManagerCli>::GetInstance()->FUN_140a44800();
            for (std::list<TFunctor<void, EmptyParam> >::iterator it = callbacks.begin(); it != callbacks.end(); ++it)
            {
                if (!it->IsNull())
                    (*it)();
            }
            TSingleton<CrashManagerCli>::GetInstance()->FUN_1401ce3a0();
        }
    }
    else
    {
        if (TSingleton<CrashManagerCli>::GetInstance() != 0)
        {
            TSingleton<CrashManagerCli>::GetInstance()->FUN_140a43830();
            TSingleton<CrashManagerCli>::GetInstance()->FUN_1401ce3a0();
        }
    }
}

// @0x140a43b10
void FUN_140a43b10(void*)
{
}

// @0x140a43b20
// MS2-FUNCTIONAL: wide CString temporaries (operator+ chain) order
void FUN_140a43b20()
{
    FUN_140a439d0();
    if (!FUN_140166410()->FUN_14036e510())
    {
        CStringW strPath = TSingleton<CrashManagerCli>::GetInstance()->FUN_1401ce460();
        __imp_CrashReporter_SetFullDumpPath(strPath.GetBuffer());
    }
    else
    {
        int nStart = 0;
        CStringW strPath = TSingleton<CrashManagerCli>::GetInstance()->FUN_1401ce460();
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

// @0x140a43d40
void FUN_140a43d40()
{
    TSingleton<CFileLogger>::GetInstance()->FUN_140392430();
    g_dlgCrash.DoModal();
}

// @0x140a43d70
void FUN_140a43d70(const wchar_t*, const wchar_t*, const wchar_t*, unsigned, uintptr_t)
{
    RaiseException(0xc000000d, 1, 0, 0);
}

// @0x140a43db0
void FUN_140a43db0()
{
    RaiseException(0xc0000005, 1, 0, 0);
}

// @0x140a43de0
int FUN_140a43de0(size_t)
{
    RaiseException(0xc0000017, 1, 0, 0);
    return 0;
}

// @0x140a43e10
void FUN_140a43e10()
{
    RaiseException(0xc0000017, 1, 0, 0);
}

// @0x140a43e40
void FUN_140a43e40(int)
{
    RaiseException(0xc0000005, 1, 0, 0);
}

// @0x140a43e70
void FUN_140a43e70(int)
{
    RaiseException(0xc0000005, 1, 0, 0);
}

// @0x140a43ea0
void FUN_140a43ea0(int)
{
    RaiseException(0xc0000005, 1, 0, 0);
}

// @0x140a43ed0
void FUN_140a43ed0()
{
    RaiseException(0xc0000005, 1, 0, 0);
}

// @0x140a43f00
void FUN_140a43f00()
{
    set_unexpected(FUN_140a43ed0);
    set_terminate(FUN_140a43ed0);
    _set_invalid_parameter_handler(FUN_140a43d70);
    _set_purecall_handler(FUN_140a43db0);
    _set_new_mode(1);
    _set_abort_behavior(2, 2);
    signal(SIGABRT_COMPAT, FUN_140a43e40);
    signal(SIGINT, FUN_140a43e70);
    signal(SIGTERM, FUN_140a43ea0);
}

// @0x140a43fa0
LONG WINAPI FUN_140a43fa0(EXCEPTION_POINTERS* pException)
{
    DWORD dwCode = pException->ExceptionRecord->ExceptionCode;
    if (dwCode == 0x80000003)
    {
        FUN_141b6db40(2);
        if (g_pfnPrevExceptionFilter != 0)
            return g_pfnPrevExceptionFilter(pException);
    }
    else if (g_pfnPrevExceptionFilter != 0)
        return g_pfnPrevExceptionFilter(pException);
    return 1;
}

// @0x140a44800
std::list<TFunctor<void, EmptyParam> >& CrashManagerCli::FUN_140a44800()
{
    return m_callbacks;
}

// @0x140a45970
void Unk_CrashDialog::FUN_140a45970(CString strMessage)
{
    m_strMessage = strMessage;
}
