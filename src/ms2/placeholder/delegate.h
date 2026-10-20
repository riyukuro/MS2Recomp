// delegate.h - PLACEHOLDER for the game's Delegate<R(Args...)> (RTTI e.g. .?AV?$Delegate@$$A6A_NH...@@ with nested
// DelegateImplBase / DelegateImpl<F> / DelegateImpl<std::pair<C*, R (C::*)(Args...)>>). NOT an original header.
//
// 8 bytes: a pointer to a heap DelegateImplBase (vftable: 0 = deleting dtor, 2 = Invoke; 1 and 3 unknown, pure in
// the base). The ctor/IsNull/operator() bodies are inline because their COMDATs are in recovered units (for
// R(Args) = CString(CString, bool): 0x1422dcac0 / 0x1422dcbb0 / 0x1422dcae0, uiswfentity.cpp); the rest is declared
// only (~Delegate 0x1416291c0, operator= 0x1416292e0 for the same R(Args)). Only the arities recovered code uses
// are spelled out; the original is probably variadic.
#pragma once

#include "ms2/ms2layout.h"
#include <utility>

template <class F> class Delegate;

template <class R, class A1, class A2>
class Delegate<R(A1, A2)>
{
public:
    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                    // 0
        virtual DelegateImplBase* vfunc_1() const = 0;  // 1 (clone?)
        virtual R Invoke(A1 a1, A2 a2) = 0;             // 2
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;     // 3 equals (parameter recovered from uiworldchampionrewarddialog.cpp)
    };

    // Bound-member implementation, as for the one-argument form below (appended by the uiworldchampionrewarddialog.cpp agent).
    template <class F>
    class DelegateImpl : public DelegateImplBase
    {
    public:
        DelegateImpl(const DelegateImpl& o) : m_f(o.m_f) {}
        DelegateImpl(const F& f) : m_f(f) {}
        virtual DelegateImplBase* vfunc_1() const { return new DelegateImpl(*this); }
        virtual R Invoke(A1 a1, A2 a2) { return Call(m_f, a1, a2); }
        virtual bool vfunc_3(const DelegateImplBase* p) const
        {
            const DelegateImpl* o = dynamic_cast<const DelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        template <class C, class M> static R Call(std::pair<C*, M>& p, A1 a1, A2 a2) { return (p.first->*p.second)(a1, a2); }
        static R Call(R (*&pfn)(A1, A2), A1 a1, A2 a2) { return pfn(a1, a2); }   // a free function (microgamemanagercli.cpp)

        F m_f;
    };

    Delegate() : m_pImpl(0) {}
    template <class C>
    Delegate(C* const& obj, R (C::*const& f)(A1, A2))
        : m_pImpl(new DelegateImpl<std::pair<C*, R (C::*)(A1, A2)> >(std::make_pair(obj, f)))
    {
    }
    // A free function (microgamemanagercli.cpp: Delegate<bool(int, const CMsgBoxData&)>, 0x140b76b10).
    explicit Delegate(R (*f)(A1, A2))
        : m_pImpl(new DelegateImpl<R (*)(A1, A2)>(f))
    {
    }
    // A captureless lambda by value (uisystemmenudialog.cpp 0x141b15070): converts to the function pointer, then as above.
    template <class L>
    explicit Delegate(L l)
        : m_pImpl(new DelegateImpl<R (*)(A1, A2)>(static_cast<R (*)(A1, A2)>(l)))
    {
    }
    Delegate(const Delegate& o);        // declared: makes a by-value Delegate argument go by reference to a caller temp (see the one-argument form)
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    R operator()(A1 a1, A2 a2) const { return m_pImpl->Invoke(a1, a2); }
    bool operator==(const Delegate& o) const;   // specialized by the units with the COMDAT (uimessagebox.cpp)

private:
    DelegateImplBase* m_pImpl;          // +0x00
};

// ---- one-argument form (appended by the uidungeonlobby.cpp agent) ----
// Delegate<void(CInPacket&)> as used by the packet handlers: 8 bytes, a pointer to a heap DelegateImpl. The
// pair-of-(object, member function) form is built by the template constructor; DelegateImpl<std::pair<C*, M>>
// is the bound-member implementation (0x20 bytes: vftable + the 24-byte pair). DelegateImplBase's ctor/dtor are
// out of line (declared only). Seen in client\ms2\uidungeonlobby.cpp (0x140e18340..0x140e18560).
#include <utility>

template <class R, class A1>
class Delegate<R(A1)>
{
public:
    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                            // 0
        virtual DelegateImplBase* vfunc_1() const = 0;          // 1 clone
        virtual R vfunc_2(A1 a1) = 0;                           // 2 Invoke
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;     // 3 equals
    };

    template <class F>
    class DelegateImpl : public DelegateImplBase
    {
    public:
        DelegateImpl(const DelegateImpl& o) : m_f(o.m_f) {}
        DelegateImpl(const F& f) : m_f(f) {}
        virtual DelegateImplBase* vfunc_1() const { return new DelegateImpl(*this); }
        virtual R vfunc_2(A1 a1) { return Call(m_f, a1); }
        virtual bool vfunc_3(const DelegateImplBase* p) const
        {
            const DelegateImpl* o = dynamic_cast<const DelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        template <class C, class M> static R Call(std::pair<C*, M>& p, A1 a1) { return (p.first->*p.second)(a1); }
        static R Call(R (*&pfn)(A1), A1 a1) { return pfn(a1); }   // a free function (ugcmanager_5.cpp)

        F m_f;
    };

    Delegate() : m_pImpl(0) {}
    template <class C>
    Delegate(C* const& obj, R (C::*const& f)(A1))     // f by const&: the caller copies the PMF before it stores `this` (uiobject.cpp agent)
        : m_pImpl(new DelegateImpl<std::pair<C*, R (C::*)(A1)> >(std::make_pair(obj, f)))
    {
    }
    // A free function (appended by the ugcmanager.cpp#4 agent: Delegate<CString(const CString&)>, 0x141892540). The
    // generic DelegateImpl::vfunc_2 only calls bound members; the unit that uses this specializes it.
    explicit Delegate(R (*f)(A1))
        : m_pImpl(new DelegateImpl<R (*)(A1)>(f))
    {
    }
    Delegate(const Delegate& o);        // declared (appended by the uiobject.cpp agent): a user copy ctor makes a by-value
                                        // Delegate argument go by reference to a caller temp that the callee destroys
                                        // (UIObject::OnLoadComplete 0x14131ec00); without it the ABI passes it in a register
    ~Delegate();

    // Logging callback containers (logstring.cpp): bodies specialized in that unit.
    Delegate& operator=(const Delegate& o);
    bool operator==(const Delegate& o) const;
    bool IsNull() const { return m_pImpl == 0; }
    R operator()(A1 a1) const;
    void Reset();                       // deletes the implementation (alphaanimation.cpp: Delegate<float(float)>, 0x14098e760)

private:
    DelegateImplBase* m_pImpl;          // +0x00
};

// ---- three-argument form (appended by the effectservice.cpp agent) ----
// Delegate<void(unsigned, CString, bool)>: the "effect inserted" callback of Unk_EffectTarget (+0x40), called by
// CEffectService::FUN_1411a4a00 (IsNull 0x1411b80a0, operator() 0x1411b0e30: null check FUN_140657820, then slot 2).
template <class R, class A1, class A2, class A3>
class Delegate<R(A1, A2, A3)>
{
public:
    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                            // 0
        virtual DelegateImplBase* vfunc_1() const = 0;          // 1 clone
        virtual R vfunc_2(A1 a1, A2 a2, A3 a3) = 0;             // 2 Invoke
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;     // 3 equals
    };

    // Bound-member implementation as in the other forms (appended by the equipment.cpp agent: CEquipment's set effect
    // callback, DelegateImpl<pair<CEquipment*, ...>> vftable 0x142ec0458, ctor 0x1411f0240).
    template <class F>
    class DelegateImpl : public DelegateImplBase
    {
    public:
        DelegateImpl(const DelegateImpl& o) : m_f(o.m_f) {}
        DelegateImpl(const F& f) : m_f(f) {}
        virtual DelegateImplBase* vfunc_1() const { return new DelegateImpl(*this); }
        virtual R vfunc_2(A1 a1, A2 a2, A3 a3) { return Call(m_f, a1, a2, a3); }
        virtual bool vfunc_3(const DelegateImplBase* p) const
        {
            const DelegateImpl* o = dynamic_cast<const DelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        template <class C, class M> static R Call(std::pair<C*, M>& p, A1 a1, A2 a2, A3 a3)
        {
            return (p.first->*p.second)(a1, a2, a3);
        }

        F m_f;
    };

    Delegate() : m_pImpl(0) {}
    template <class C>
    Delegate(C* const& obj, R (C::*const& f)(A1, A2, A3))
        : m_pImpl(new DelegateImpl<std::pair<C*, R (C::*)(A1, A2, A3)> >(std::make_pair(obj, f)))
    {
    }
    Delegate(const Delegate& o);
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    R operator()(A1 a1, A2 a2, A3 a3) const;            // body specialized by the unit that owns the COMDAT

private:
    DelegateImplBase* m_pImpl;          // +0x00
};

// ---- four-argument form (appended by the uimeratmarketdialog.cpp agent) ----
// Delegate<bool(TPtr<TMarketBillDataParam>, const CAtlMap<ePayType, __int64>&, const CStringW&, const CStringW&)>: the
// gift callback of the market bill (exe RTTI of UIMeratMarketDialog's DelegateImpl, 0x141313e40). Bound-member form
// as in the one- and two-argument forms.
template <class R, class A1, class A2, class A3, class A4>
class Delegate<R(A1, A2, A3, A4)>
{
public:
    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                            // 0
        virtual DelegateImplBase* vfunc_1() const = 0;          // 1 clone
        virtual R vfunc_2(A1 a1, A2 a2, A3 a3, A4 a4) = 0;      // 2 Invoke
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;     // 3 equals
    };

    template <class F>
    class DelegateImpl : public DelegateImplBase
    {
    public:
        DelegateImpl(const DelegateImpl& o) : m_f(o.m_f) {}
        DelegateImpl(const F& f) : m_f(f) {}
        virtual DelegateImplBase* vfunc_1() const { return new DelegateImpl(*this); }
        virtual R vfunc_2(A1 a1, A2 a2, A3 a3, A4 a4) { return Call(m_f, a1, a2, a3, a4); }
        virtual bool vfunc_3(const DelegateImplBase* p) const
        {
            const DelegateImpl* o = dynamic_cast<const DelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        template <class C, class M> static R Call(std::pair<C*, M>& p, A1 a1, A2 a2, A3 a3, A4 a4)
        {
            return (p.first->*p.second)(a1, a2, a3, a4);
        }

        F m_f;
    };

    Delegate() : m_pImpl(0) {}
    template <class C>
    Delegate(C* const& obj, R (C::*const& f)(A1, A2, A3, A4))
        : m_pImpl(new DelegateImpl<std::pair<C*, R (C::*)(A1, A2, A3, A4)> >(std::make_pair(obj, f)))
    {
    }
    Delegate(const Delegate& o);
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    R operator()(A1 a1, A2 a2, A3 a3, A4 a4) const;     // body specialized by the unit that owns the COMDAT

private:
    DelegateImplBase* m_pImpl;          // +0x00
};
