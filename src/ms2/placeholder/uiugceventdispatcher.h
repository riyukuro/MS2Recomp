// uiugceventdispatcher.h - PLACEHOLDER for UIUGCEventDispatcher (RTTI .?AVUIUGCEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIUGCEventDispatcher> at +0x0.
// Owning unit ?\uiugcbannerdialog.cpp. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It broadcasts the UGC events
// to the registered UIUGCEventListener objects (slots 1-7 of the listener).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <atlcoll.h>

class UIUGCEventListener;

class UIUGCEventDispatcher : public TSingleton<UIUGCEventDispatcher>
{
public:
    UIUGCEventDispatcher();                                 // 0x141b38b40
    virtual ~UIUGCEventDispatcher();                        // 0x141b38b90
    virtual void vfunc_1(void* p, CString str);             // 1 0x141b38d00 broadcast to the listeners
    virtual void vfunc_2(void* p, CString str);             // 2 0x141b38dd0
    virtual void vfunc_3(void* p, void* q);                 // 3 0x141b38ea0
    virtual void vfunc_4(int n);                            // 4 0x141b38f30
    virtual void vfunc_5();                                 // 5 0x141b38fc0
    virtual void vfunc_6();                                 // 6 0x141b39040
    virtual void vfunc_7(int n);                            // 7 0x141b390c0
    void FUN_141b38be0(UIUGCEventListener* pListener);                    // add a listener unless it is registered
    void FUN_141b38c70(UIUGCEventListener* pListener);                    // remove a listener
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<void*> m_8;                              // +0x8 the registered UIUGCEventListener*
};
MS2_CHECK_SIZE(UIUGCEventDispatcher, 0x28);
