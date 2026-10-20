// clientlogmanager.h - PLACEHOLDER for ClientLogManager (RTTI .?AVClientLogManager@@, 0x68 bytes). NOT an original header.
// Bases: TSingleton<ClientLogManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It registers a CLogString callback, keeps the last
// 1001 lines and feeds the CLogDialog tool dialog (?\logdialog.cpp). Member and method names are invented from use.
#pragma once

#include <list>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

class CLogDialog;
class LogDialogCtx;
class CLogStringCtx;
enum class Unk_LogCategory : int;

class ClientLogManager : public TSingleton<ClientLogManager>
{
public:
    ClientLogManager();                                     // 0x141451410
    virtual ~ClientLogManager();                            // 0x141451500

    void SetQuiet();                                        // 0x1414515c0 stop echoing errors to the HUD
    void ToggleDialog();                                    // 0x1414515e0 open or close the log dialog
    void OnLogString(CLogStringCtx* pCtx);                  // 0x1414517c0 the CLogString callback
    void Flush();                                           // 0x141451a60 hand pending lines to the dialog/HUD
    static CStringA GetCategoryName(Unk_LogCategory nCategory);     // 0x141451c40
    CStringA GetLevelName(int nLevel);                      // 0x141451d90
    void AppendLogContext(MS2Ptr<LogDialogCtx> spCtx);      // 0x141451ea0

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CLogDialog> m_spDialog;                          // +0x08
    bool m_bQuiet;                                          // +0x18
    CLockCriticalSection m_lock;                            // +0x20
    std::list<MS2Ptr<LogDialogCtx> > m_logs;                // +0x50
    std::list<MS2Ptr<LogDialogCtx> >::iterator m_itPending; // +0x60 the first line not flushed yet (end: none)
};
MS2_CHECK_SIZE(ClientLogManager, 0x68);
