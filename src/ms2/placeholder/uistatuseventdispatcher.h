// uistatuseventdispatcher.h - UIStatusEventDispatcher (RTTI .?AVUIStatusEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIStatusEventDispatcher> at +0x0. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the
// hub that forwards player status changes (hp / sp / ep, level, job, name, ...) to the registered UIStatusEventListener
// dialogs. Members and methods recovered with ?\uistatuseventlistener.cpp (0x141b0cc60-0x141b0e380).
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIStatusEventListener;

class UIStatusEventDispatcher : public TSingleton<UIStatusEventDispatcher>
{
public:
    UIStatusEventDispatcher();                              // 0x141b0cc60
    virtual ~UIStatusEventDispatcher();                     //  0 0x141b0ccb0 (??_G 0x141b0e520)

    void FUN_141b0cd00(void* pListener);   // register (once)
    void FUN_141b0cd90(void* pListener);   // unregister
    void FUN_141b0ce20(int nEvent, int nValue);             // push one status to every active listener
    void FUN_141b0e000();                                   // push all 19 statuses (nValue 0)
    void FUN_141b0e050();                                   // listener slot 2
    void FUN_141b0e0d0();                                   // listener slot 22
    void FUN_141b0e150();                                   // listener slot 23
    void FUN_141b0e1d0(int a1);                             // listener slot 24
    void FUN_141b0e260(void* a1);                           // listener slot 25
    void FUN_141b0e2f0(void* a1);                           // listener slot 26
    void FUN_141b0e380(int a1, int a2);                     // listener slot 27

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<void*> m_listeners;                      // +0x08 UIStatusEventListener*
};
MS2_CHECK_SIZE(UIStatusEventDispatcher, 0x28);
