// uientityeventlistener.h - PLACEHOLDER for UIEntityEventListener (RTTI .?AVUIEntityEventListener@@): the 8-byte (vftable
// only) interface that HUD classes derive from to receive entity events (UIUpperHpBar, UILapenshardShieldBar, ...).
// Registered with UIEntityEventDispatcher (placeholder/uientityeventdispatcher.h) in OnLoadInit / vfunc_26.
// Ctor 0x141930750-area, 6 slots: 0 deleting dtor, 1..5 the event callbacks (0x141930750 .. 0x1419307f0 in
// ?\uientityeventlistener.cpp); derived classes bind the base ctor/dtor/slots through progress/symbols-manual.tsv.
// NOT an original header (name assumed); the signatures are the by-pointer forms (units that need the event type
// keep their own typed view, see uiupperhpbar.h).
#pragma once

#include "ms2/ms2layout.h"

class CProxyGameObject;
template <class T> class MS2Ptr;

class UIEntityEventListener
{
public:
    UIEntityEventListener();
    virtual ~UIEntityEventListener();
    virtual void vfunc_1(void*);
    virtual void vfunc_o70_2(const void*);
    // 3..5 get the actor as a by-value MS2Ptr (the callee destroys it; the overrides keep it in an EH state).
    virtual void vfunc_3(MS2Ptr<CProxyGameObject> spActor);
    virtual void vfunc_4(MS2Ptr<CProxyGameObject> spActor);
    virtual void vfunc_5(MS2Ptr<CProxyGameObject> spActor, int);
};
MS2_CHECK_SIZE(UIEntityEventListener, 8);
