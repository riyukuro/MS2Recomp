// uientityeventlistener.cpp - UIEntityEventListener (the 8-byte interface the HUD widgets implement) and the
// UIEntityEventDispatcher singleton that fans entity events out to the registered listeners (CAtlArray<UIEntityEventListener*> at +8).
// The tail of the range is the CAtlArray<UIEntityEventListener*> block the link took from this file.
// MS2-UNIT: ?\uientityeventlistener.cpp
// MS2-RANGE: 0x141930710-0x141931550 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAA@XZ 0x141930d90 ; unique
// MS2-PIN: ??1?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAA@XZ 0x141930e00 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@CAXPEAPEAVUIEntityEventListener@@_K@Z 0x141931040 ; unique
// MS2-PIN: ??A?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAAAEAPEAVUIEntityEventListener@@_K@Z 0x141931080 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@AEAA_N_K@Z 0x1419310d0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAVUIEntityEventListener@@@ATL@@SAXPEAPEAVUIEntityEventListener@@0_K@Z 0x141931270 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAAX_K0@Z 0x1419312d0 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1419313c0 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@CAXPEAPEAVUIEntityEventListener@@_K@Z 0x141930fd0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAAXXZ 0x1419312b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetCount@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEBA_KXZ 0x1419310c0
// MS2-PIN: ?Add@?$CAtlArray@PEAVUIEntityEventListener@@V?$CElementTraits@PEAVUIEntityEventListener@@@ATL@@@ATL@@QEAA_KAEBQEAVUIEntityEventListener@@@Z 0x141930f20
// MS2-PIN: ??_7UIEntityEventListener@@6B@ 0x142fa36a0
// MS2-PIN: ??_7UIEntityEventDispatcher@@6B@ 0x142fa36e8
// MS2-PIN: ??_7?$TSingleton@VUIEntityEventDispatcher@@@@6B@ 0x142fa36d8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uientityeventlistener.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiupperhpbar.h"
#include "ms2/placeholder/uientityeventdispatcher.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/ms2recover.h"


class Unk_UpperEvt { public: Unk_UpperEvt(const Unk_UpperEvt&);    /* 0x1408b6b20 */ private: void* m_0; };
void FUN_1406c70a0(void*);
extern template class MS2Ptr<CProxyGameObject>;

// The listener as the dispatcher sees its slots 1..5.
class Unk_EvtListenerView
{
public:
    virtual ~Unk_EvtListenerView();
    virtual void s1(Unk_UpperEvt);
    virtual void s2(Unk_UpperEvt);
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
void UIEntityEventListener::vfunc_3(MS2Ptr<CProxyGameObject>)
{
}

// @0x1419307c0
void UIEntityEventListener::vfunc_4(MS2Ptr<CProxyGameObject>)
{
}

// @0x1419307f0
void UIEntityEventListener::vfunc_5(MS2Ptr<CProxyGameObject>, int)
{
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

// @0x1419308c0
void Unk_UpperEvents::FUN_1419308c0(UIEntityEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (pListener == m_listeners[i])
            return;
    }
    m_listeners.Add(pListener);
}

// @0x141930950
void Unk_UpperEvents::FUN_141930950(UIEntityEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (pListener == m_listeners[i])
        {
            m_listeners.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x1419309e0
void UIEntityEventDispatcher::vfunc_1(const Unk_UpperEvt& evt)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* p = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (p != 0)
            p->s1(evt);
    }
}

// @0x141930a90
void UIEntityEventDispatcher::vfunc_2(const Unk_UpperEvt& evt)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        Unk_EvtListenerView* p = reinterpret_cast<Unk_EvtListenerView*>(m_listeners[i]);
        if (p != 0)
            p->s2(evt);
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
