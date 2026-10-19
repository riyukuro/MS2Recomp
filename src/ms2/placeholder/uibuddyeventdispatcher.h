// uibuddyeventdispatcher.h - PLACEHOLDER for UIBuddyEventDispatcher (RTTI .?AVUIBuddyEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIBuddyEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Owning unit ?\uibuddyeventlistener.cpp. It broadcasts the
// buddy events to the registered UIBuddyEventListener objects (slots 1-14 of the listener).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <afx.h>
#include <atlcoll.h>

class UIBuddyEventListener;

class UIBuddyEventDispatcher : public TSingleton<UIBuddyEventDispatcher>
{
public:
    UIBuddyEventDispatcher();                               // 0x1418d93b0
    virtual ~UIBuddyEventDispatcher();                      // 0x1418d9400 (??_G 0x1418d9e50)
    virtual void vfunc_1(__int64 nId);                      //  1 0x1418d9570 broadcast to the listeners
    virtual void vfunc_2(__int64 nId);                      //  2 0x1418d9600
    virtual void vfunc_3(__int64 nId);                      //  3 0x1418d9690
    virtual void vfunc_4(__int64 nId, int n);               //  4 0x1418d9720
    virtual void vfunc_5(__int64 nId);                      //  5 0x1418d97b0
    virtual void vfunc_6(__int64 nId);                      //  6 0x1418d9840
    virtual void vfunc_7(__int64 nId);                      //  7 0x1418d98d0
    virtual void vfunc_8(__int64 nId);                      //  8 0x1418d9960
    virtual void vfunc_9(__int64 nId);                      //  9 0x1418d99f0
    virtual void vfunc_10(__int64 nId, int n);              // 10 0x1418d9a80
    virtual void vfunc_11(__int64 nId);                     // 11 0x1418d9b10
    virtual void vfunc_12(__int64 nId);                     // 12 0x1418d9ba0
    virtual void vfunc_13(__int64 nId);                     // 13 0x1418d9c30
    virtual void vfunc_14();                                // 14 0x1418d9cc0
    void FUN_1418d9450(UIBuddyEventListener* pListener);    // add a listener unless it is registered
    void FUN_1418d94e0(UIBuddyEventListener* pListener);    // remove a listener
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<void*> m_8;                              // +0x8 the registered UIBuddyEventListener*
};
MS2_CHECK_SIZE(UIBuddyEventDispatcher, 0x28);
