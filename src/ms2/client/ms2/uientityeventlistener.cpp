// uientityeventlistener.cpp - UIEntityEventListener (the 8-byte interface the HUD widgets implement) and the
// UIEntityEventDispatcher singleton that fans entity events out to the registered listeners (CAtlArray<void*> at +8).
// The tail of the range is the CAtlArray<void*> block the link took from this file.
// MS2-UNIT: ?\uientityeventlistener.cpp
// MS2-RANGE: 0x141930710-0x141931550 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x141930d90 ; unique
// MS2-PIN: ??1?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x141930e00 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141931040 ; unique
// MS2-PIN: ??A?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAAEAPEAX_K@Z 0x141931080 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@AEAA_N_K@Z 0x1419310d0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAX@ATL@@SAXPEAPEAX0_K@Z 0x141931270 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAX_K0@Z 0x1419312d0 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_N_KH@Z 0x1419313c0 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141930fd0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAXXZ 0x1419312b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEBA_KXZ 0x1419310c0
// MS2-PIN: ?Add@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_KPEAX@Z 0x141930f20
// MS2-PIN: ??_7UIEntityEventListener@@6B@ 0x142fa36a0
// MS2-PIN: ??_7UIEntityEventDispatcher@@6B@ 0x142fa36e8
// MS2-PIN: ??_7?$TSingleton@VUIEntityEventDispatcher@@@@6B@ 0x142fa36d8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uientityeventlistener.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiupperhpbar.h"
#include "ms2/placeholder/uientityeventdispatcher.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/ms2recover.h"


class Unk_UpperEvt { public: Unk_UpperEvt(const Unk_UpperEvt&); private: void* m_0; };
void FUN_1406c70a0(void*);
Unk_UpperEvt* FUN_1408b6b20(void* dst, const Unk_UpperEvt& src);   // copy ctor
extern template class MS2Ptr<CProxyGameObject>;

struct Unk_EvtBuf { void* a; void* b; void* c; };   // the event copy lives in a 24-byte local

// The listener as the dispatcher sees its slots 1..5.
class Unk_EvtListenerView
{
public:
    virtual ~Unk_EvtListenerView();
    virtual void s1(const Unk_UpperEvt&);
    virtual void s2(const Unk_UpperEvt&);
    virtual void s3(MS2Ptr<CProxyGameObject>);
    virtual void s4(MS2Ptr<CProxyGameObject>);
    virtual void s5(MS2Ptr<CProxyGameObject>, int);
};

// The dispatcher with its fan-out virtuals and the add / remove the HUD widgets call (named by VA there).
class Unk_UpperEvents : public UIEntityEventDispatcher
{
public:
    void FUN_1419308c0(UIEntityEventListener* pListener);
    void FUN_141930950(UIEntityEventListener* pListener);
};

// @0x141930710
UIEntityEventListener::UIEntityEventListener()
{
}

// @0x141930730
UIEntityEventListener::~UIEntityEventListener()
{
}

// @0x141930750
void UIEntityEventListener::vfunc_1(void*)
{
}

// @0x141930770
void UIEntityEventListener::vfunc_o70_2(const Unk_UpperEvt&)
{
}

// @0x141930790
void UIEntityEventListener::vfunc_3(void* p)
{
    FUN_1406c70a0(p);
}

// @0x1419307c0
void UIEntityEventListener::vfunc_4(void* p)
{
    FUN_1406c70a0(p);
}

// @0x1419307f0
void UIEntityEventListener::vfunc_5(void* p, int)
{
    FUN_1406c70a0(p);
}

// @0x141930820
UIEntityEventDispatcher::UIEntityEventDispatcher() : m_listeners()
{
}

// @0x141930870
UIEntityEventDispatcher::~UIEntityEventDispatcher()
{
    m_listeners.RemoveAll();
}

// MS2-FUNCTIONAL: the exe's CAtlArray<void*>::Add takes the element by reference (older ATL); ours takes it by value
// @0x1419308c0
void Unk_UpperEvents::FUN_1419308c0(UIEntityEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (m_listeners[i] == pListener)
            return;
    }
    m_listeners.Add(pListener);
}

// MS2-FUNCTIONAL: loop shape / GetCount-GetAt pairing differs after the by-value Add (older ATL)
// @0x141930950
void Unk_UpperEvents::FUN_141930950(UIEntityEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (m_listeners[i] == pListener)
        {
            m_listeners.RemoveAt(i, 1);
            return;
        }
    }
}

// MS2-FUNCTIONAL: the event copy local / copy-ctor call does not pair (FUN_1408b6b20 shape)
// @0x1419309e0
void UIEntityEventDispatcher::vfunc_1(const Unk_UpperEvt& evt)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* p = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (p != 0)
            {
            Unk_EvtBuf buf;
            p->s1(*FUN_1408b6b20(&buf, evt));
        };
    }
}

// MS2-FUNCTIONAL: as vfunc_1 (event copy local)
// @0x141930a90
void UIEntityEventDispatcher::vfunc_2(const Unk_UpperEvt& evt)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* p = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (p != 0)
            {
            Unk_EvtBuf buf;
            p->s2(*FUN_1408b6b20(&buf, evt));
        };
    }
}

// @0x141930b40
void UIEntityEventDispatcher::vfunc_3(MS2Ptr<CProxyGameObject> p)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* l = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (l != 0)
            l->s3(p);
    }
}

// @0x141930c00
void UIEntityEventDispatcher::vfunc_4(MS2Ptr<CProxyGameObject> p)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* l = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (l != 0)
            l->s4(p);
    }
}

// @0x141930cc0
void UIEntityEventDispatcher::vfunc_5(MS2Ptr<CProxyGameObject> p, int n)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* l = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (l != 0)
            l->s5(p, n);
    }
}
