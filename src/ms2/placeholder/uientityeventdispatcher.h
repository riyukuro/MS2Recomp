// uientityeventdispatcher.h - PLACEHOLDER for UIEntityEventDispatcher (RTTI .?AVUIEntityEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIEntityEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered beyond the listener list (CAtlArray<void*> at +8); the fan-out virtuals are in ?\uientityeventlistener.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <afx.h>
#include <atlcoll.h>

class Unk_UpperEvt;
class UIEntityEventListener;
class CProxyGameObject;
template <class T> class MS2Ptr;

class UIEntityEventDispatcher : public TSingleton<UIEntityEventDispatcher>
{
public:
    UIEntityEventDispatcher();                              // 0x141930820
    virtual ~UIEntityEventDispatcher();
    virtual void vfunc_1(const Unk_UpperEvt& evt);
    virtual void vfunc_2(const Unk_UpperEvt& evt);
    virtual void vfunc_3(MS2Ptr<CProxyGameObject> p);
    virtual void vfunc_4(MS2Ptr<CProxyGameObject> p);
    virtual void vfunc_5(MS2Ptr<CProxyGameObject> p, int n);
protected:
    MS2_LAYOUT_FRIEND;
    // A typed element (not void*): ATL passes non-primitive elements to Add by const& (lea rdx), as the exe does.
    ATL::CAtlArray<UIEntityEventListener*> m_listeners;     // +0x08 the registered listeners
};
MS2_CHECK_SIZE(UIEntityEventDispatcher, 0x28);
