// uiservereventdispatcher.h - UIServerEventDispatcher (RTTI .?AVUIServerEventDispatcher@@, 0x28 bytes,
// base TSingleton<UIServerEventDispatcher>, vftables 0x142ef0cc0 / 0x142eedcb0). The singleton that keeps the
// registered server-event listeners in a CAtlArray<UIServerEventListener*> and fans an event out to all of them.
// Code owner: ?\uiservereventdispatcher.cpp (ctor 0x141347260, dtor 0x1413472b0, vfunc_1 0x141347410).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

// The listener the dispatcher notifies: vfunc_1 calls its vtable slot 1 with the object itself. Slot 0 is the
// (virtual) destructor, so this is the one declared virtual.
class UIServerEventListener
{
public:
    virtual ~UIServerEventListener() {}     // slot 0
    virtual void Notify() {}                // slot 1 (0x141a4d920: empty)
};

class UIServerEventDispatcher : public TSingleton<UIServerEventDispatcher>
{
public:
    UIServerEventDispatcher();              // 0x141347260
    virtual ~UIServerEventDispatcher();     // 0x1413472b0
    virtual void vfunc_1();                 // 0x141347410 notifies every registered listener
    void AddListener(UIServerEventListener* pListener);     // 0x1413472f0 (ignores a duplicate)
    void RemoveListener(UIServerEventListener* pListener);  // 0x141347380
private:
    ATL::CAtlArray<UIServerEventListener*> m_listeners;     // +0x08 the registered listeners
};
MS2_CHECK_SIZE(UIServerEventDispatcher, 0x28);
