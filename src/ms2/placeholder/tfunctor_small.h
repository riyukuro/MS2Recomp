// One-argument functors from CFilePreload, sharing the established functor bases.
#pragma once
#include "ms2/placeholder/tfunctor.h"
template<class R,class A>
class FunctorImpl<R,ParamList<A,EmptyParam>> : public FunctorImplBase<R> {
public:
    FunctorImpl() {}
    FunctorImpl(const FunctorImpl& o) noexcept : FunctorImplBase<R>(o) {}
    virtual ~FunctorImpl() = default;
    virtual R Invoke(A) = 0;
};
template<class R,class A,class Object,class Method>
class ClassFunHandler<TFunctor<R,ParamList<A,EmptyParam>>,Object,Method>
    : public FunctorImpl<R,ParamList<A,EmptyParam>> {
public:
    typedef FunctorImpl<R,ParamList<A,EmptyParam>> Impl;
    ClassFunHandler(const Object& o,Method m) : object(o),method(m) {}
    ClassFunHandler(const ClassFunHandler& o) noexcept : Impl(o),object(o.object),method(o.method) {}
    virtual ~ClassFunHandler() = default;
    virtual ClassFunHandler* Clone() const { return new ClassFunHandler(*this); }
    virtual R Invoke(A a) { return (object->*method)(a); }
private:
    Object object;
    Method method;
};
template<class R,class A>
class TFunctor<R,ParamList<A,EmptyParam>> {
public:
    typedef FunctorImpl<R,ParamList<A,EmptyParam>> Impl;
    TFunctor() : implementation(0) {}
    template<class Object,class Method> TFunctor(const Object& o,Method m)
        : implementation(new ClassFunHandler<TFunctor,Object,Method>(o,m)) {}
    TFunctor(const TFunctor& o) : implementation(Clone(o.implementation)) {}
    ~TFunctor() { Clear(); }
    TFunctor& operator=(const TFunctor& o) { Clear(); implementation=Clone(o.implementation); return *this; }
    R operator()(A a) { return implementation->Invoke(a); }
    bool IsNull() const { return implementation==0; }
    void Clear() { if(implementation) { delete implementation; implementation=0; } }
private:
    static Impl* Clone(Impl* p) { if(p==0) return 0; Impl* copy=static_cast<Impl*>(p->Clone()); return copy; }
    Impl* implementation;
};
// One-argument handler bound to a free function (appended by gap3: ms2memfile.cpp, the XML loaders
// FunctorHandler<TFunctor<bool, ParamList<TiXmlDocument&>>, bool (*)(TiXmlDocument&)>, vftable 0x142f46850, 0x10 bytes).
template<class Functor,class Fn> class FunctorHandler;
template<class R,class A,class Fn>
class FunctorHandler<TFunctor<R,ParamList<A,EmptyParam>>,Fn>
    : public FunctorImpl<R,ParamList<A,EmptyParam>> {
public:
    typedef FunctorImpl<R,ParamList<A,EmptyParam>> Impl;
    FunctorHandler(const Fn& f) : fn(f) {}
    FunctorHandler(const FunctorHandler& o) noexcept : Impl(o),fn(o.fn) {}
    virtual ~FunctorHandler() = default;
    virtual FunctorHandler* Clone() const { return new FunctorHandler(*this); }
    virtual R Invoke(A a) { return fn(a); }
private:
    Fn fn;
};
