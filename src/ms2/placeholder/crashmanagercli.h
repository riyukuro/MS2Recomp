// crashmanagercli.h - PLACEHOLDER for CrashManagerCli (RTTI .?AVCrashManagerCli@@, 0xd0 bytes). NOT an original header.
// Bases: CCrashManager at +0x0, TSingleton<CrashManagerCli> at +0x68.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/crashmanager.h"
#include <atlcoll.h>
#include "ms2/placeholder/clockcriticalsection.h"

class CrashManagerCli;
class CrashManagerCli : public CCrashManager, public TSingleton<CrashManagerCli>
{
public:
    // @0x1414961b0
    CrashManagerCli() {}
    // @0x141497620
    virtual ~CrashManagerCli() {}
    void FUN_140a435a0();                                   // installs the crash handler (InitInstance)
    void FUN_140a43750(DWORD nId, CString strText);           // set the text of a crash-log entry
    void FUN_140a437d0(DWORD nId);                            // remove a crash-log entry
    void FUN_140a43830();                                   // write every entry to the crash log
    bool FUN_140a43920(DWORD nId, CString& strText);          // read a crash-log entry
    std::list<TFunctor<void, EmptyParam> >& FUN_140a44800();    // the shutdown callbacks
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x70
    ATL::CRBMap<DWORD, CString> m_map;                      // +0xa0 log entries by id
};
MS2_CHECK_SIZE(CrashManagerCli, 0xd0);

