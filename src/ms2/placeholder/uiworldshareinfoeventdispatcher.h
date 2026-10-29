// uiworldshareinfoeventdispatcher.h - PLACEHOLDER for UIWorldShareInfoEventDispatcher (RTTI .?AVUIWorldShareInfoEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIWorldShareInfoEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered beyond the listener list (CAtlArray<void*> at +8); the fan-out and add / remove are in
// ?\uiworldshareinfoeventlistener.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <afx.h>
#include <atlcoll.h>

// The 8-byte interface the world-share widgets implement (RTTI .?AVUIWorldShareInfoEventListener@@).
class UIWorldShareInfoEventListener
{
public:
    UIWorldShareInfoEventListener();                        // 0x14135fc40
    virtual ~UIWorldShareInfoEventListener();               // 0 0x14135fc60
    virtual void vfunc_1(__int64 n, int a, int b);          // 1 0x1413603c0 (empty)
};
MS2_CHECK_SIZE(UIWorldShareInfoEventListener, 8);

class UIWorldShareInfoEventDispatcher : public TSingleton<UIWorldShareInfoEventDispatcher>
{
public:
    UIWorldShareInfoEventDispatcher();                      // 0x14135fc80
    virtual ~UIWorldShareInfoEventDispatcher();
    virtual void vfunc_1(__int64 n, int a, int b);          // 1 0x14135fe40 fan out to every listener
    void FUN_14135fd20(UIWorldShareInfoEventListener* pListener);   // add (once)
    void FUN_14135fdb0(UIWorldShareInfoEventListener* pListener);   // remove
private:
    MS2_LAYOUT_FRIEND;
    // A typed element (not void*): ATL passes non-primitive elements to Add by const& (lea rdx), as the exe does.
    ATL::CAtlArray<UIWorldShareInfoEventListener*> m_listeners; // +0x08 the registered listeners
};
MS2_CHECK_SIZE(UIWorldShareInfoEventDispatcher, 0x28);
