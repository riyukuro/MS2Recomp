// Alpha animation helpers of the entity layer (names of the classes are the exe's RTTI names; members are invented).
//   AlphaTourController  NiAlphaController copy whose Update drives ApplyAlpha() instead of NiMaterialProperty::SetAlpha.
//   CAlphaAnimation      timed alpha animation of one scene-graph node (ends = the node's properties are restored).
//   CEntityShower/Hider  fade of an entity's scene graph (in/out) through a TLinearInterpolator<float>.
// Owning unit: ?\alphaanimation.cpp (0x14098a990-0x14098eb30, dir client\ms2).
#pragma once
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/delegate.h"
#include <NiAlphaController.h>
#include <NiAVObject.h>
#include <NiRefObject.h>
#include <egf/EntityID.h>

// Zero-argument form of the game's Delegate (8 bytes: pointer to a heap DelegateImpl; slot 2 = Invoke).
template <class R>
class Delegate<R()>
{
public:
    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                            // 0
        virtual DelegateImplBase* vfunc_1() const = 0;          // 1 clone
        virtual R vfunc_2() = 0;                                // 2 Invoke
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;     // 3 equals
    };

    // Bound-member implementation, as for the one-argument form (appended by the uipartydialog.cpp agent: UIPopUpMenu's
    // menu handlers, 0x141a87400 / 0x141a87fd0 / 0x141a89cf0 / 0x141a89de0 / 0x141a89f50).
    template <class F>
    class DelegateImpl : public DelegateImplBase
    {
    public:
        DelegateImpl(const DelegateImpl& o) : m_f(o.m_f) {}
        DelegateImpl(const F& f) : m_f(f) {}
        virtual DelegateImplBase* vfunc_1() const { return new DelegateImpl(*this); }
        virtual R vfunc_2() { return (m_f.first->*m_f.second)(); }
        virtual bool vfunc_3(const DelegateImplBase* p) const
        {
            const DelegateImpl* o = dynamic_cast<const DelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        F m_f;
    };

    Delegate() : m_pImpl(0) {}
    template <class C>
    Delegate(C* const& obj, R (C::*const& f)())
        : m_pImpl(new DelegateImpl<std::pair<C*, R (C::*)()> >(std::make_pair(obj, f)))
    {
    }
    Delegate(const Delegate& o);
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    R operator()() const { return m_pImpl->vfunc_2(); }

private:
    DelegateImplBase* m_pImpl;
};

// A timed interpolation between two values. Reset (1) and Get (2) are provided by the concrete interpolator; Finish (3)
// fires the completion callback.
template <> Delegate<float(float)>::~Delegate();
template <> float Delegate<float(float)>::operator()(float fValue) const;
template <> void Delegate<float(float)>::Reset();

template <class T>
class TInterpolator
{
public:
    TInterpolator(float fDuration, const T& from, const T& to)
        : m_fDuration(fDuration), m_from(from), m_to(to), m_onFinish(), m_filter()
    {
    }
    virtual ~TInterpolator() {}
    void SetFrom(const T& from) { m_from = from; }
    virtual void Reset() = 0;
    virtual T Get(float fDelta) = 0;
    virtual void Finish()
    {
        if (!m_onFinish.IsNull())
            m_onFinish();
    }

    float m_fDuration;                  // +0x08
    T m_from;                           // +0x0c
    T m_to;                             // +0x10
    Delegate<void()> m_onFinish;        // +0x18
    Delegate<T(T)> m_filter;            // +0x20 (optionally post-processes the target value)
};

template <class T>
class TLinearInterpolator : public TInterpolator<T>
{
public:
    TLinearInterpolator(float fDuration, const T& from, const T& to) : TInterpolator<T>(fDuration, from, to), m_fElapsed(0) {}
    virtual ~TLinearInterpolator() {}
    virtual void Reset() { m_fElapsed = 0; }
    virtual T Get(float fDelta)
    {
        m_fElapsed = m_fElapsed + fDelta;
        float fRatio = m_fElapsed / this->m_fDuration;
        if (fRatio > 1.0f)
        {
            this->Finish();
            return this->m_to;
        }
        if (!this->m_filter.IsNull())
            this->m_to = this->m_filter(this->m_to);
        return this->m_from * (1.0f - fRatio) + this->m_to * fRatio;
    }

    float m_fElapsed;                   // +0x28
};

class AlphaTourController : public NiAlphaController
{
public:
    AlphaTourController();
    virtual ~AlphaTourController() = default;
    virtual void Update(float fTime);                                                   // 20
    virtual bool UpdateValue(float fTime, float fFloat, unsigned short usIndex = 0);    // 39
protected:
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;                // 47
    virtual void GetTargetFloatValue(float& fValue);                                    // 48
};
MS2_CHECK_SIZE(AlphaTourController, 0x50);
typedef efd::SmartPointer<AlphaTourController> AlphaTourControllerPtr;

class CAlphaAnimation : public NiRefObject
{
public:
    CAlphaAnimation(NiAVObject* pkTarget, float fEndTime);
    virtual ~CAlphaAnimation();
    virtual bool vfunc_2();                         // false = finished

    float m_fEndTime;                               // +0x10
    NiAVObjectPtr m_spTarget;                       // +0x18
    AlphaTourControllerPtr m_spController;          // +0x20
    egf::EntityID m_idOwner;                        // +0x28
};
MS2_CHECK_SIZE(CAlphaAnimation, 0x30);

class CEntityShower : public NiRefObject
{
public:
    CEntityShower(egf::EntityID idEntity, NiAVObject* pkNode, float fFrom, float fTo, float fDuration);
    virtual ~CEntityShower();
    virtual bool vfunc_2();                         // false = finished
    void SetAlpha(float fAlpha);                    // 0x14098beb0
    // @0x141bfe630
    float GetAlpha() { return m_fAlpha; }           // (COMDAT in worldservice.cpp)
    // @0x141bffde0
    egf::EntityID GetEntityID() { return m_idEntity; }   // (COMDAT in worldservice.cpp)

    bool m_bWasShown;                               // +0x10
    float m_fAlpha;                                 // +0x14
    TLinearInterpolator<float>* m_pInterpolator;    // +0x18
    float m_fEndTime;                               // +0x20
    NiAVObjectPtr m_spNode;                         // +0x28
    egf::EntityID m_idEntity;                       // +0x30
};
MS2_CHECK_SIZE(CEntityShower, 0x38);

class CEntityHider : public CEntityShower
{
public:
    CEntityHider(egf::EntityID idEntity, NiAVObject* pkNode, float fFrom, float fTo, float fDuration);
    virtual ~CEntityHider() = default;
    virtual bool vfunc_2();
};
MS2_CHECK_SIZE(CEntityHider, 0x38);
